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
#if defined(PLAT_t96)	/* FIXME: add support for T83 platform */
static void gti_access_secure_memory_setup(int do_secure);
#endif
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
		uint64_t vector_ptr;
		int intr_pinx;
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

		for (i = 0; i < PLATFORM_CORE_COUNT; i++) {

			if (!(cores & (1 << i)))
				continue;

			/* Get the offset of interrupt vector for this core */
			intr_pinx = CAVM_GTI_INT_VEC_E_CORE_WDOGX_INT_CN9(i);

			/* INTR_PINX vector address */
			vector_ptr = CAVM_GTI_BAR_E_GTI_PF_BAR4_CN9 +
					 (intr_pinx << 4);
			debug_gti_watchdog("Watchdog: vector_ptr = %llx, ",
					vector_ptr);
			debug_gti_watchdog("Watchdog: intr_pinx = %d\n",
					intr_pinx);

			/* Enable SECVEC to make the vector secure */
			octeontx_write64(vector_ptr, CAVM_GICD_SETSPI_SR | 1);
			vector_ptr += 0x8;
			debug_gti_watchdog("Watchdog: setvector ptr to 0x%x\n",
					 GTI_CWD_SPI_IRQ(i));
			octeontx_write64(vector_ptr, GTI_CWD_SPI_IRQ(i));
		}

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

		/* FIXME: add support for T83 platform */
#if defined(PLAT_t96)
		gti_access_secure_memory_setup(1);
#endif

		debug_gti_watchdog("Watchdog: Set to expire %llu SCLK cycles\n",
					timeout_wdog << 18);

		wdog.s.len = timeout_wdog;
		/*
		 * setup watchdog to interrupt + del3t + reset mode.
		 * DEL3T is not enabled currently.
		 */
		wdog.s.mode = 3;

		for (i = 0; i < PLATFORM_CORE_COUNT; i++) {
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
	for (int i = 0; i < PLATFORM_CORE_COUNT; i++) {
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

/*
 * This function configures IOBN to grant access for GTI to secure memory
 */
#if defined(PLAT_t96)	/* FIXME: add support for T83 platform */
static void gti_access_secure_memory_setup(int do_secure)
{
	/*
	 * dev_idx - Stream's dev number (stream_id<7:0>)
	 * bus_idx - Stream's bus number (stream_id<15:8>).
	 */
	uint64_t bus_idx = (CAVM_PCC_DEV_CON_E_GTI_CN9 >> 8) & 0xFF;
	uint64_t domain_idx = (CAVM_PCC_DEV_CON_E_GTI_CN9 >> 16) & 0xFF;
	uint64_t dev_idx = (CAVM_PCC_DEV_CON_E_GTI_CN9 >> 3) & 0xFF;

	cavm_iobnx_domx_busx_streams_t iobn_domx_busx_stream;
	cavm_iobnx_domx_devx_streams_t iobn_domx_devx_stream;

	debug_gti_watchdog("iobn count = %d\n", plat_octeontx_scfg->iobn_count);
	for (int iobn_idx = 0; iobn_idx < plat_octeontx_scfg->iobn_count;
				iobn_idx++) {

		iobn_domx_busx_stream.u = CSR_READ(
			CAVM_IOBNX_DOMX_BUSX_STREAMS(iobn_idx,
			domain_idx, bus_idx));
		debug_gti_watchdog("busx strm_nsec = %d, phys_nsec = %d\n",
			iobn_domx_busx_stream.s.strm_nsec,
			iobn_domx_busx_stream.s.phys_nsec);

		if (do_secure) {
			iobn_domx_busx_stream.s.strm_nsec = 0;
			iobn_domx_busx_stream.s.phys_nsec = 0;
			CSR_WRITE(CAVM_IOBNX_DOMX_BUSX_STREAMS(
				iobn_idx, domain_idx, bus_idx),
				iobn_domx_busx_stream.u);
		}

		iobn_domx_devx_stream.u = CSR_READ(
			CAVM_IOBNX_DOMX_DEVX_STREAMS(iobn_idx,
			domain_idx, dev_idx));
		debug_gti_watchdog("devx strm_nsec = %d, phys_nsec = %d\n",
			iobn_domx_devx_stream.s.strm_nsec,
			iobn_domx_devx_stream.s.phys_nsec);

		if (do_secure) {
			iobn_domx_devx_stream.s.strm_nsec = 0;
			iobn_domx_devx_stream.s.phys_nsec = 0;
			CSR_WRITE(CAVM_IOBNX_DOMX_DEVX_STREAMS(
				iobn_idx, domain_idx, dev_idx),
				iobn_domx_devx_stream.u);
		}
	}
}
#endif

int gti_wdog_remove_handler(void)
{
	int retval = 1;

	gti_watchdog_disable();

	return retval;
}

int gti_wdog_install_handler(uint64_t kernel_wdog_callback, uint64_t core,
			 uint64_t watchdog_timeout_ms, uint64_t cores)
{
	int retval = 1;

	g_kernel_cback = kernel_wdog_callback;

	debug_gti_watchdog("Watchdog: core = %lld, mpidr = 0x%llx\n",
			 core, read_mpidr());

	if (core == PLATFORM_CORE_COUNT) {
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
