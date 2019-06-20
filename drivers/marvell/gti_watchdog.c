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
			 uint64_t scr_el3);
uint64_t g_kernel_cback;
_Atomic int in_use_lock;

void prepare_elx_kernel_callback(void)
{
	if ((in_use_lock++) == 0)
		el3_invoke_elx_kernel_callback(g_kernel_cback, SPSR_ISR,
				 SCR_ISR);
}

uint64_t gti_cwd_irq_handler(uint32_t id, uint32_t flags, void *cookie)
{
	prepare_elx_kernel_callback();
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

		for (i = 0; i < GTI_CWD_SPI_IRQS; i++) {

			if (!(cores & (1 << i)))
				continue;

			rc = register_interrupt_handler(INTR_TYPE_EL3,
							GTI_CWD_SPI_IRQ(i),
							gti_cwd_irq_handler);
			if (rc) {
				ERROR("err %d register CWD secure interrupt\n",
							 rc);
				return;
			}
		}

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

int gti_wdog_install_handler(uint64_t kernel_wdog_callback, uint64_t core,
			 uint64_t watchdog_timeout_ms, uint64_t cores)
{
	int retval = 1;

	if ((!IS_OCTEONTX_PN(read_midr(), T83PARTNUM)) &&
		(!IS_OCTEONTX_PN(read_midr(), T96PARTNUM)))
		return 0;

	g_kernel_cback = kernel_wdog_callback;

	debug_gti_watchdog("Watchdog: core = %lld, mpidr = 0x%llx\n",
			 core, read_mpidr());

	if (core == GTI_CWD_SPI_IRQS) {
		debug_gti_watchdog("Watchdog: kernel callback = 0x%llx, ",
				 g_kernel_cback);
		debug_gti_watchdog("timeout_ms = %lld, ",
				 watchdog_timeout_ms);
		debug_gti_watchdog("cores = 0x%llx\n", cores);
		gti_watchdog_set(watchdog_timeout_ms, cores);
	} else {
		gicv3_set_spi_routing(GTI_CWD_SPI_IRQ(core), GICV3_IRM_PE,
			read_mpidr());
	}

	return retval;
}
