/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch_helpers.h>
#include <assert.h>
#include <bl_common.h>
#include <context.h>
#include <context_mgmt.h>
#include <debug.h>
#include <mmio.h>
#include <platform.h>
#include <platform_def.h>
#include <psci.h>
#include <cavm_legacy_pwrc.h>
#include <cavm_common.h>
#include <cavm_dt.h>
#include <cavm_gpio.h>
#include <cavm_gicv3.h>
#include <cavm_twsi.h>

#undef GICD_SETSPI_NSR
#undef GICD_CLRSPI_NSR
#undef GICD_SETSPI_SR
#undef GICD_CLRSPI_SR
#undef GICD_TYPER
#undef GICD_IIDR

static void octeontx_odm_shutdown(int shutdown_gpio)
{
	volatile int loop;

	/* Assert GPIO to signal shutdown */
	gpio_set_out(shutdown_gpio);
	loop = 0xFFFF;
	while(loop--){};
	gpio_clr_out(shutdown_gpio);
	loop = 0xFFFF;
	while(loop--){};
	gpio_set_out(shutdown_gpio);
}

static int octeontx_signal_mcu(uint8_t signal)
{
	uint8_t data[2];
	int rc;

	data[0] = plat_octeontx_bcfg->bcfg.mcu_twsi.s.int_addr;
	data[1] = signal;

	rc = octeontx_twsi_send(plat_octeontx_bcfg->bcfg.mcu_twsi.s.bus,
			       plat_octeontx_bcfg->bcfg.mcu_twsi.s.addr, data, sizeof(data));
	if (rc) {
		ERROR("Unable to send signal 0x%x to MCU, error 0x%x\n",
		      signal, rc);
		return -1;
	}

	return 0;
}

static void octeontx_signal_shutdown(void)
{
	int rc;

	/* Check for MCU structure */
	if (plat_octeontx_bcfg->bcfg.mcu_twsi.u != 0) {
		/* We're on EBB, shutdown using MCU */
		rc = octeontx_signal_mcu(OCTEONTX_MCU_SHUTDOWN_SIGNAL);
		if (!rc) {
			INFO("Cavium System Off: shutting down system...\n");
			for(;;);
		} else {
			ERROR("Cavium System Off: Unable to send shutdown to MCU\n");
			panic();
		}
	/* Check for GPIO config */
	} else if (plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_out >= 0) {
		/* We're on SFF board, shutdown using GPIO */
		octeontx_odm_shutdown(plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_out);
	} else {
		ERROR("Cavium System Off: Incorrect shutdown configuration\n");
		panic();
	}
}

static void octeontx_legacy_power_domain_on_finish_common(const psci_power_state_t *target_state)
{
	assert(target_state->pwr_domain_state[MPIDR_AFFLVL0] ==
					OCTEONTX_STATE_OFF);
}


/*******************************************************************************
 * FVP handler called when a CPU is about to enter standby.
 ******************************************************************************/
static void octeontx_legacy_cpu_standby(plat_local_state_t cpu_state)
{

	assert(cpu_state == OCTEONTX_STATE_RET);

	/*
	 * Enter standby state
	 * dsb is good practice before using wfi to enter low power states
	 */
	dsb();
	wfi();
}

/*******************************************************************************
 * FVP handler called when a power domain is about to be turned on. The
 * mpidr determines the CPU to be turned on.
 ******************************************************************************/
static int octeontx_legacy_pwr_domain_on(u_register_t mpidr)
{
	int rc = PSCI_E_SUCCESS;

	octeontx_legacy_pwrc_write_pponr(mpidr);
	return rc;
}

/*******************************************************************************
 * FVP handler called when a power domain is about to be turned off. The
 * target_state encodes the power state that each level should transition to.
 ******************************************************************************/
static void octeontx_legacy_pwr_domain_off(const psci_power_state_t *target_state)
{
	assert(target_state->pwr_domain_state[MPIDR_AFFLVL0] ==
					OCTEONTX_STATE_OFF);
	/*
	 * If execution reaches this stage then this power domain will be
	 * suspended. Prevent interrupts from spuriously waking up this cpu.
	 */
	octeontx_gic_cpuif_disable();
}

/*******************************************************************************
 * FVP handler called when a power domain is about to be suspended. The
 * target_state encodes the power state that each level should transition to.
 ******************************************************************************/
static void octeontx_legacy_pwr_domain_suspend(const psci_power_state_t *target_state)
{
	/*
	 * FVP has retention only at cpu level. Just return
	 * as nothing is to be done for retention.
	 */
	if (target_state->pwr_domain_state[MPIDR_AFFLVL0] ==
					OCTEONTX_STATE_RET)
		return;

	assert(target_state->pwr_domain_state[MPIDR_AFFLVL0] ==
					OCTEONTX_STATE_OFF);

	/* Prevent interrupts from spuriously waking up this cpu */
	octeontx_gic_cpuif_disable();
}

/*******************************************************************************
 * FVP handler called when a power domain has just been powered on after
 * being turned off earlier. The target_state encodes the low power state that
 * each level has woken up from.
 ******************************************************************************/
static void octeontx_legacy_pwr_domain_on_finish(const psci_power_state_t *target_state)
{
	octeontx_legacy_power_domain_on_finish_common(target_state);

	/* Enable the gic cpu interface */
	octeontx_gic_pcpu_init();

	/* Program the gic per-cpu distributor or re-distributor interface */
	octeontx_gic_cpuif_enable();

	/* Setup platform quirks for secondary cores */
	octeontx_cpu_setup();

	/* Init FLR for secondary cores */
	plat_flr_init();
}

/*******************************************************************************
 * FVP handler called when a power domain has just been powered on after
 * having been suspended earlier. The target_state encodes the low power state
 * that each level has woken up from.
 * TODO: At the moment we reuse the on finisher and reinitialize the secure
 * context. Need to implement a separate suspend finisher.
 ******************************************************************************/
static void octeontx_legacy_pwr_domain_suspend_finish(const psci_power_state_t *target_state)
{
	/*
	 * Nothing to be done on waking up from retention from CPU level.
	 */
	if (target_state->pwr_domain_state[MPIDR_AFFLVL0] ==
					OCTEONTX_STATE_RET)
		return;

	octeontx_legacy_power_domain_on_finish_common(target_state);

	/* Enable the gic cpu interface */
	octeontx_gic_cpuif_enable();
}

/*******************************************************************************
 * FVP handlers to shutdown/reboot the system
 ******************************************************************************/
static void __dead2 octeontx_legacy_system_off(void)
{
	octeontx_signal_shutdown();
	/* Should never reach it */
	panic();
}

static void __dead2 octeontx_legacy_system_reset(void)
{
	union cavm_rst_soft_rst rst_soft_rst;
	union cavm_rst_ocx rst_ocx;

	rst_ocx.u = 0;
	CSR_WRITE(CAVM_RST_OCX, rst_ocx.u);

	rst_ocx.u = CSR_READ(CAVM_RST_OCX);
	rst_soft_rst.u = 0;
	rst_soft_rst.s.soft_rst = 1;
	CSR_WRITE(CAVM_RST_SOFT_RST, rst_soft_rst.u);

	ERROR("OcteonTX System Reset: operation not handled.\n");
	panic();
}

/*******************************************************************************
 * ARM standard platform handler called to check the validity of the power state
 * parameter.
 ******************************************************************************/
static int octeontx_legacy_validate_power_state(unsigned int power_state,
			    psci_power_state_t *req_state)
{
	int pstate = psci_get_pstate_type(power_state);
	int pwr_lvl = psci_get_pstate_pwrlvl(power_state);
	int i;

	assert(req_state);

	if (pwr_lvl > PLAT_MAX_PWR_LVL)
		return PSCI_E_INVALID_PARAMS;

	/* Sanity check the requested state */
	if (pstate == PSTATE_TYPE_STANDBY) {
		/*
		 * It's possible to enter standby only on power level 0
		 * Ignore any other power level.
		 */
		if (pwr_lvl != MPIDR_AFFLVL0)
			return PSCI_E_INVALID_PARAMS;

		req_state->pwr_domain_state[MPIDR_AFFLVL0] =
					OCTEONTX_STATE_RET;
	} else {
		for (i = MPIDR_AFFLVL0; i <= pwr_lvl; i++)
			req_state->pwr_domain_state[i] =
					OCTEONTX_STATE_OFF;
	}

	/*
	 * We expect the 'state id' to be zero.
	 */
	if (psci_get_pstate_id(power_state))
		return PSCI_E_INVALID_PARAMS;

	return PSCI_E_SUCCESS;
}

/*******************************************************************************
 * ARM standard platform handler called to check the validity of the non secure
 * entrypoint.
 ******************************************************************************/
static int octeontx_legacy_validate_ns_entrypoint(uintptr_t entrypoint)
{
	uint64_t dram_end = 0;

	dram_end = octeontx_dram_size();

	/*
	 * Check if the non secure entrypoint lies within the non
	 * secure DRAM.
	 */
	if ((entrypoint >= NS_IMAGE_BASE) && (entrypoint < (dram_end - 1)))
		return PSCI_E_SUCCESS;

	return PSCI_E_INVALID_ADDRESS;
}

/*******************************************************************************
 * Export the platform handlers via plat_octeontx_legacy_psci_pm_ops. The ARM Standard
 * platform layer will take care of registering the handlers with PSCI.
 ******************************************************************************/
const plat_psci_ops_t plat_octeontx_legacy_psci_pm_ops = {
	.cpu_standby = octeontx_legacy_cpu_standby,
	.pwr_domain_on = octeontx_legacy_pwr_domain_on,
	.pwr_domain_off = octeontx_legacy_pwr_domain_off,
	.pwr_domain_suspend = octeontx_legacy_pwr_domain_suspend,
	.pwr_domain_on_finish = octeontx_legacy_pwr_domain_on_finish,
	.pwr_domain_suspend_finish = octeontx_legacy_pwr_domain_suspend_finish,
	.system_off = octeontx_legacy_system_off,
	.system_reset = octeontx_legacy_system_reset,
	.validate_power_state = octeontx_legacy_validate_power_state,
	.validate_ns_entrypoint = octeontx_legacy_validate_ns_entrypoint
};

/*******************************************************************************
 * Private function to program the mailbox for a cpu before it is released
 * from reset. This function assumes that the Trusted mail box base is within
 * the ARM_SHARED_RAM region
 ******************************************************************************/
static void octeontx_legacy_program_trusted_mailbox(uintptr_t address)
{
       uintptr_t *mailbox = (void *) MAILBOX_BASE;

       *mailbox = address;
}

int octeontx_legacy_setup_psci_ops(uintptr_t sec_entrypoint,
				const plat_psci_ops_t **psci_ops)
{

	*psci_ops = &plat_octeontx_legacy_psci_pm_ops;

	/* Setup mailbox with entry point. */
	octeontx_legacy_program_trusted_mailbox(sec_entrypoint);

	return 0;
}
