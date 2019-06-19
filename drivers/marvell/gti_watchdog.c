/*
 * Copyright (C) 2016-2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/* GTI Watchdog driver for 96xx */

#include <arch_helpers.h>
#include <assert.h>
#include <debug.h>
#include <psci.h>
#include <errno.h>
#include <gic_common.h>
#include <gicv3.h>
#include <platform.h>
#include <platform_def.h>
#include <plat_scfg.h>
#include <runtime_svc.h>
#include <interrupt_mgmt.h>
#include <context_mgmt.h>
#include <string.h>

#include <octeontx_ecam.h>
#include <octeontx_svc.h>
#include <octeontx_common.h>
#include <octeontx_utils.h>
#include <octeontx_irqs_def.h>
#include <gti_watchdog.h>

#undef DEBUG_GTI_WDOG

#ifdef DEBUG_GTI_WDOG
#define debug_gti_watchdog printf
#else
#define debug_gti_watchdog(...) ((void) (0))
#endif

#define SPSR_ISR	SPSR_64(MODE_EL2, MODE_SP_ELX, 3)
#define SCR_ISR		(SCR_NS_BIT | SCR_RW_BIT)

void el3_invoke_elx_kernel_callback(uint64_t kernel_cback, uint64_t spsr_el3,
			 uint64_t scr_el3, int el_mode);
uint64_t g_kernel_cback;
el3_state_t g_el3state_save;
gp_regs_t g_gpregs_save;
uint64_t g_el2_sp_save;
uint32_t g_intid;
_Atomic int in_use_lock;

void prepare_elx_kernel_callback(int el_mode)
{
#if 0
	/* For testing on ASIM only */
	CSR_WRITE(CAVM_GTI_CWD_WDOGX(plat_my_core_pos()), 0);
#endif

	el3_invoke_elx_kernel_callback(g_kernel_cback, SPSR_ISR, SCR_ISR,
				 el_mode);
}

int prepare_elx_restore_context(void)
{
	cpu_context_t *cm_ctxt;
	el3_state_t *el3state_ctx;
	gp_regs_t *gpregs_ctx;
	uint64_t val;
	int el_mode;

	cm_ctxt = cm_get_context(NON_SECURE);

	gpregs_ctx = get_gpregs_ctx(cm_ctxt);
	el3state_ctx = get_el3state_ctx(cm_ctxt);

	val = read_ctx_reg((el3state_ctx), (uint32_t)(CTX_SPSR_EL3));
	el_mode = GET_EL(val);

	memcpy((void *) &g_gpregs_save, (void *)gpregs_ctx, sizeof(gp_regs_t));
	memcpy((void *) &g_el3state_save, (void *)el3state_ctx,
			 sizeof(el3_state_t));

	/*
	 * NOTE: SP_EL2 will be modified during kernel nmi callback invocation,
	 * hence, save it here and restore it back when we restore and resume
	 * interrupted context.
	 */

	__asm__ __volatile__ ("mrs %0, sp_el2\n\t" : "=r"(g_el2_sp_save) : : );

	return el_mode;
}


void restore_elx_context_and_return(void)
{
	cpu_context_t *cm_ctxt;
	el3_state_t *el3state_ctx;
	gp_regs_t *gpregs_ctx;

	/*
	 * We had shortcut the top-level interrupt handler path and invoked
	 * the kernel nmi callback via a simulated exception return to EL2
	 * from EL3, so when we return back we need to do interrupt completion.
	 */

	plat_ic_end_of_interrupt(g_intid);

	cm_ctxt = cm_get_context(NON_SECURE);

	gpregs_ctx = get_gpregs_ctx(cm_ctxt);
	el3state_ctx = get_el3state_ctx(cm_ctxt);

	memcpy(gpregs_ctx, (void *) &g_gpregs_save, sizeof(gp_regs_t));
	memcpy(el3state_ctx, (void *) &g_el3state_save, sizeof(el3_state_t));

	__asm__ __volatile__ ("msr sp_el2, %0\n\t" : : "r"(g_el2_sp_save));

	/*
	 * Ensure that the global save state is restored to the expired
	 * watchdog core's context before it gets overwritten by another
	 * watchdog expiration.
	 */
	in_use_lock--;
}

uint64_t gti_cwd_irq_handler(uint32_t id, uint32_t flags, void *cookie)
{
	int el_mode;

	if ((in_use_lock++) == 0) {
		g_intid = id;
		el_mode = prepare_elx_restore_context();
		prepare_elx_kernel_callback(el_mode);
		/* Does not return here */
	}
	in_use_lock--;
	return 0;
}

#define PLL_REF_CLK 50000000	/* 50 MHz */

/**
 * Setup the watchdog to expire in timeout_ms milliseconds. We are programming
 * the watchdog in Interrupt + DEL3T trap + Soft-reset mode, out of which
 * we ignore the Interrupt.
 *
 * Since we want a DEL3T trap first, we actually program the watchdog to
 * expire at the timeout / 2.
 *
 */
static void gti_watchdog_set(uint64_t timeout_ms, uint64_t cores)
{
	if (timeout_ms > 0) {
		uint64_t sclk;
		union cavm_rst_boot rst_boot;
		union cavm_gti_cwd_wdogx wdog;
		cavm_gti_cwd_int_ena_set_t gti_cwd_ena;
		static int intr_hndlrs_registered;
		int i, rc;

		rst_boot.u = CSR_READ(CAVM_RST_BOOT);
		sclk = PLL_REF_CLK * rst_boot.s.pnr_mul;
		uint64_t timeout_sclk = sclk * timeout_ms / 1000;

		/* Watchdog counts in 1024 cycle steps */
		uint64_t timeout_wdog = timeout_sclk >> 10;
		/*
		 * We can only specify the upper 16 bits of a 24 bit value.
		 * Round up
		 */
		timeout_wdog = (timeout_wdog + 0xff) >> 8;
		/* If the timeout overflows the hardware limit, set max */
		if (timeout_wdog >= 0x10000) {
			debug_gti_watchdog("Watchdog: Timer count overflow!\n");
			timeout_wdog = 0xffff;
		}

		gti_cwd_ena.s.core = cores;
		CSR_WRITE(CAVM_GTI_CWD_INT_ENA_SET, gti_cwd_ena.u);

		debug_gti_watchdog("Watchdog: gti ena set = 0x%llx\n",
			CSR_READ(CAVM_GTI_CWD_INT_ENA_SET));

		/* configure interrupt vectors */

		for (i = 0; i < GTI_CWD_SPI_IRQS; i++) {

			if (!(cores & (1 << i)))
				continue;

			plat_gti_irq_setup(i);
		}

		if (intr_hndlrs_registered)
			goto intr_hndlrs_already_registered;
		else
			intr_hndlrs_registered = 1;

		for (i = 0; i < GTI_CWD_SPI_IRQS; i++) {

			rc = register_interrupt_handler(INTR_TYPE_EL3,
							GTI_CWD_SPI_IRQ(i),
							gti_cwd_irq_handler);
			if (rc) {
				ERROR("err %d register CWD secure interrupt\n",
							 rc);
				return;
			}
		}
intr_hndlrs_already_registered:

		plat_gti_access_secure_memory_setup(1);

		debug_gti_watchdog("Watchdog: Set to expire %llu SCLK cycles\n",
					timeout_wdog << 18);

		wdog.u = 0;
		wdog.s.len = timeout_wdog;
		wdog.s.cnt = timeout_wdog << 8;
		/*
		 * setup watchdog to interrupt + del3t + reset mode.
		 * DEL3T is not enabled currently.
		 */
		wdog.s.mode = 3;

		for (i = 0; i < GTI_CWD_SPI_IRQS; i++) {
			if (!(cores & (1 << i)))
				continue;
			CSR_WRITE(CAVM_GTI_CWD_WDOGX(i), wdog.u);
			CSR_WRITE(CAVM_GTI_CWD_POKEX(i), 0);
		}
	}
}

/**
 * Disable the hardware watchdog
 */
void gti_watchdog_disable(void)
{
	for (int i = 0; i < GTI_CWD_SPI_IRQS; i++) {
		if (gti_watchdog_is_running(i)) {
			debug_gti_watchdog("Disabling watchdog on core %d\n",
					 i);
			CSR_WRITE(CAVM_GTI_CWD_WDOGX(i), 0);
		}
	}

	debug_gti_watchdog("Watchdog: Disabled\n");
}

/**
 * Return true if the watchdog is configured and running
 *
 * @return Non-zero if watchdog is running
 */
int gti_watchdog_is_running(int core)
{
	union cavm_gti_cwd_wdogx wdog;

	wdog.u = CSR_READ(CAVM_GTI_CWD_WDOGX(core));
	return wdog.s.mode != 0;
}

int gti_wdog_remove_handler(void)
{
	int retval = 1;

	if ((!IS_OCTEONTX_PN(read_midr(), T83PARTNUM)) &&
		(!IS_OCTEONTX_PN(read_midr(), T96PARTNUM)))
		return 0;

	gti_watchdog_disable();

	return retval;
}

int gti_wdog_install_handler(uint64_t core)
{
	int retval = 1;

	if ((!IS_OCTEONTX_PN(read_midr(), T83PARTNUM)) &&
		(!IS_OCTEONTX_PN(read_midr(), T96PARTNUM)))
		return 0;

	debug_gti_watchdog("Watchdog: core = %lld, mpidr = 0x%llx\n",
			 core, read_mpidr());

	gicv3_set_spi_routing(GTI_CWD_SPI_IRQ(core), GICV3_IRM_PE,
				read_mpidr());

	return retval;
}

int gti_wdog_start(uint64_t kernel_wdog_callback, uint64_t watchdog_timeout_ms,
			 uint64_t cores)
{
	if ((!IS_OCTEONTX_PN(read_midr(), T83PARTNUM)) &&
		(!IS_OCTEONTX_PN(read_midr(), T96PARTNUM)))
		return 0;

	debug_gti_watchdog("timeout_ms = %lld, ",
			 watchdog_timeout_ms);

	debug_gti_watchdog("cores = 0x%llx\n", cores);

	g_kernel_cback = kernel_wdog_callback;

	gti_watchdog_set(watchdog_timeout_ms, cores);

	return 1;
}

int gti_wdog_restore_wdog_ctxt(void)
{
	if ((!IS_OCTEONTX_PN(read_midr(), T83PARTNUM)) &&
		(!IS_OCTEONTX_PN(read_midr(), T96PARTNUM)))
		return 0;

	restore_elx_context_and_return();

	return 1;
}
