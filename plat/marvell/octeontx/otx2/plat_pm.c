/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch_helpers.h>
#include <assert.h>
#include <cassert.h>
#include <plat_pwrc.h>
#include <debug.h>
#include <errno.h>
#include <platform_def.h>
#include <platform_setup.h>
#include <platform.h>
#include <octeontx_common.h>
#include <timers.h>
#include <gicv3_setup.h>
#include <octeontx_security.h>
#include <octeontx_dram.h>

extern void *scmi_handle;

/*
 * All the power management helpers in this file assume at least cluster power
 * level is supported.
 */
CASSERT(PLAT_MAX_PWR_LVL >= CAVM_PWR_LVL1,
		assert_max_pwr_lvl_supported_mismatch);

/*
 * Ensure that the PLAT_MAX_PWR_LVL is not greater than CAVM_SYSTEM_PWR_DMN_LVL
 * assumed by the Cavium SCP layer.
 */
CASSERT(PLAT_MAX_PWR_LVL <= CAVM_SYSTEM_PWR_DMN_LVL,
		assert_max_pwr_lvl_higher_than_cavm_sys_lvl);

/*******************************************************************************
 * Handler called when a power domain is about to be turned on. The
 * level and mpidr determine the affinity instance.
 ******************************************************************************/
static int octeontx_pwr_domain_on(u_register_t mpidr)
{
	octeontx_scp_on(mpidr);

	return PSCI_E_SUCCESS;
}

static void octeontx_pwr_domain_on_finisher_common(
		const psci_power_state_t *target_state)
{
	assert(CAVM_CORE_PWR_STATE(target_state) == CAVM_LOCAL_STATE_OFF);

	/*
	 * Perform the common cluster specific operations i.e enable coherency
	 * if this cluster was off.
	 *
	 * TODO: For optimization, Cavium ATF platform port should implement
	 * the CMI driver (since we're not using CCI/CCN common drivers) 
	 * and wrap in under plat_arm_interconnect_ API.
	 * As we can keep the interconnect always on, right now just
	 * comment out this part.
	 */
/*	if (CAVM_CLUSTER_PWR_STATE(target_state) == CAVM_LOCAL_STATE_OFF)
		plat_arm_interconnect_enter_coherency();
*/
}

/*******************************************************************************
 * Handler called when a power level has just been powered on after
 * being turned off earlier. The target_state encodes the low power state that
 * each level has woken up from. This handler would never be invoked with
 * the system power domain uninitialized as either the primary would have taken
 * care of it as part of cold boot or the first core awakened from system
 * suspend would have already initialized it.
 ******************************************************************************/
static void octeontx_pwr_domain_on_finish(const psci_power_state_t *target_state)
{
	/* Assert that the system power domain need not be initialized */
	assert(CAVM_SYSTEM_PWR_STATE(target_state) == CAVM_LOCAL_STATE_RUN);

	octeontx_pwr_domain_on_finisher_common(target_state);

	/* Program the gic per-cpu distributor or re-distributor interface */
	octeontx_gic_pcpu_init();

	/* Enable the gic cpu interface */
	octeontx_gic_cpuif_enable();

	/* Apply erratas on secondary cores */
	octeontx_cpu_setup();

	/* Init FLR for secondary cores */
	plat_flr_init();
}

/*******************************************************************************
 * Common function called while turning a cpu off or suspending it. It is called
 * from octeontx_off() or octeontx_suspend() when these functions in turn are 
 * called for power domain at the highest power level which will be powered
 * down. It performs the actions common to the OFF and SUSPEND calls.
 ******************************************************************************/
static void octeontx_power_down_common(const psci_power_state_t *target_state)
{
	/* Prevent interrupts from spuriously waking up this cpu */
	octeontx_gic_cpuif_disable();

	/* Cluster is to be turned off, so disable coherency
	 *
	 * TODO: For optimization, Cavium ATF platform port should implement
	 * the CMI driver (since we're not using CCI/CCN common drivers) 
	 * and wrap in under plat_arm_interconnect_ API.
	 * As we can keep the interconnect always on, right now just
	 * comment out this part.
	 */
/*	if (CAVM_CLUSTER_PWR_STATE(target_state) == CAVM_LOCAL_STATE_OFF)
		plat_arm_interconnect_exit_coherency();
*/
}

/*******************************************************************************
 * Handler called when a power domain is about to be turned off. The
 * target_state encodes the power state that each level should transition to.
 ******************************************************************************/
static void octeontx_pwr_domain_off(const psci_power_state_t *target_state)
{
	assert(CAVM_CORE_PWR_STATE(target_state) == CAVM_LOCAL_STATE_OFF);
	octeontx_power_down_common(target_state);
	octeontx_scp_off(target_state);
}

/*******************************************************************************
 * Handler called when a power domain is about to be suspended. The
 * target_state encodes the power state that each level should transition to.
 ******************************************************************************/
static void octeontx_pwr_domain_suspend(const psci_power_state_t *target_state)
{
	/*
	 * Cavium SCP currently supports retention only at cpu level. Just return
	 * as nothing is to be done for retention.
	 */
	if (CAVM_CORE_PWR_STATE(target_state) == CAVM_LOCAL_STATE_RET)
		return;

	assert(CAVM_CORE_PWR_STATE(target_state) == CAVM_LOCAL_STATE_OFF);
	octeontx_power_down_common(target_state);
	octeontx_scp_suspend(target_state);
}

/******************************************************************************
 * Helper function to resume the platform from system suspend. Reinitialize
 * the system components which are not in the Always ON power domain.
 * TODO: Unify the platform setup when waking up from cold boot and system
 * resume in arm_bl31_platform_setup().
 *****************************************************************************/
static void octeontx_system_pwr_domain_resume(void)
{
	/* Assert system power domain is available on the platform */
	assert(PLAT_MAX_PWR_LVL >= CAVM_PWR_LVL2);

	/* Ported from bl31_platform_setup, may require alignment */
	octeontx_configure_mmc_security(0); /* non-secure */

	/*TODO: Check if required here on HW, should not be
	 *since it's persistent through the suspend */
	//octeontx_el3_irq_init();

	octeontx_gic_driver_init();
	octeontx_gic_init();
	timers_init();
}

/*******************************************************************************
 * Handler called when a power domain has just been powered on after
 * having been suspended earlier. The target_state encodes the low power state
 * that each level has woken up from.
 * TODO: At the moment we reuse the on finisher and reinitialize the secure
 * context. Need to implement a separate suspend finisher.
 ******************************************************************************/
static void octeontx_pwr_domain_suspend_finish(
				const psci_power_state_t *target_state)
{
	/* Return as nothing is to be done on waking up from retention. */
	if (CAVM_CORE_PWR_STATE(target_state) == CAVM_LOCAL_STATE_RET)
		return;

	/* Perform system domain restore if woken up from system suspend */
	if (CAVM_SYSTEM_PWR_STATE(target_state) == CAVM_LOCAL_STATE_OFF)
		octeontx_system_pwr_domain_resume();
	else
		/* Enable the gic cpu interface */
		octeontx_gic_cpuif_enable();

	octeontx_pwr_domain_on_finisher_common(target_state);
}

/*******************************************************************************
 * Handlers to shutdown/reboot the system
 ******************************************************************************/
static void __dead2 octeontx_system_off(void)
{
	octeontx_scp_sys_shutdown();
}

static void __dead2 octeontx_system_reset(void)
{
	octeontx_scp_sys_reboot();
}

/*******************************************************************************
 * Handler called when the CPU power domain is about to enter standby.
 ******************************************************************************/
static void octeontx_cpu_standby(plat_local_state_t cpu_state)
{
	unsigned int scr;

	assert(cpu_state == CAVM_LOCAL_STATE_RET);

	scr = read_scr_el3();
	/*
	 * Enable the Non secure interrupt to wake the CPU.
	 * In GICv3 affinity routing mode, the non secure group1 interrupts use
	 * the PhysicalFIQ at EL3 whereas in GICv2, it uses the PhysicalIRQ.
	 * Enabling both the bits works for both GICv2 mode and GICv3 affinity
	 * routing mode.
	 */
	write_scr_el3(scr | SCR_IRQ_BIT | SCR_FIQ_BIT);
	isb();
	dsb();
	wfi();

	/*
	 * Restore SCR to the original value, synchronisation of scr_el3 is
	 * done by eret while el3_exit to save some execution cycles.
	 */
	write_scr_el3(scr);
}

/*******************************************************************************
 * Handler called to return the 'req_state' for system suspend.
 ******************************************************************************/
static void octeontx_get_sys_suspend_power_state(psci_power_state_t *req_state)
{
	unsigned int i;

	/*
	 * System Suspend is supported only if the system power domain node
	 * is implemented.
	 */
	assert(PLAT_MAX_PWR_LVL == CAVM_SYSTEM_PWR_DMN_LVL);

	for (i = CAVM_PWR_LVL0; i <= PLAT_MAX_PWR_LVL; i++)
		req_state->pwr_domain_state[i] = CAVM_LOCAL_STATE_OFF;
}

/*******************************************************************************
 * Handler to query CPU/cluster power states from SCP
 ******************************************************************************/
static int octeontx_node_hw_state(u_register_t mpidr, unsigned int power_level)
{
	return octeontx_scp_get_power_state(mpidr, power_level);
}

/*******************************************************************************
 * Internal helper to validate power state
 ******************************************************************************/
static int octeontx_helper_validate_power_state(unsigned int power_state,
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
		if (pwr_lvl != CAVM_PWR_LVL0)
			return PSCI_E_INVALID_PARAMS;

		req_state->pwr_domain_state[CAVM_PWR_LVL0] =
					CAVM_LOCAL_STATE_RET;
	} else {
		for (i = CAVM_PWR_LVL0; i <= pwr_lvl; i++)
			req_state->pwr_domain_state[i] =
					CAVM_LOCAL_STATE_OFF;
	}

	/*
	 * We expect the 'state id' to be zero.
	 */
	if (psci_get_pstate_id(power_state))
		return PSCI_E_INVALID_PARAMS;

	return PSCI_E_SUCCESS;
}

/*
 * The system power domain suspend is only supported only via
 * PSCI SYSTEM_SUSPEND API. PSCI CPU_SUSPEND request to system power domain
 * will be downgraded to the lower level.
 */
static int octeontx_validate_power_state(unsigned int power_state,
			    psci_power_state_t *req_state)
{
	int rc;
	rc = octeontx_helper_validate_power_state(power_state, req_state);

	/*
	 * Ensure that the system power domain level is never suspended
	 * via PSCI CPU SUSPEND API. Currently system suspend is only
	 * supported via PSCI SYSTEM SUSPEND API.
	 */
	req_state->pwr_domain_state[CAVM_SYSTEM_PWR_DMN_LVL] = CAVM_LOCAL_STATE_RUN;
	return rc;
}

/*
 * Custom `translate_power_state_by_mpidr` handler for Cavium. Unlike in the
 * `octeontx_validate_power_state`, we do not downgrade the system power
 * domain level request in `power_state` as it will be used to query the
 * PSCI_STAT_COUNT/RESIDENCY at the system power domain level.
 */
static int octeontx_translate_power_state_by_mpidr(u_register_t mpidr,
		unsigned int power_state,
		psci_power_state_t *output_state)
{
	return octeontx_helper_validate_power_state(power_state, output_state);
}


/*******************************************************************************
 * Cavium standard platform handler called to check the validity of the non secure
 * entrypoint.
 ******************************************************************************/
static int octeontx_validate_ns_entrypoint(uintptr_t entrypoint)
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
 * Export the platform handlers via plat_arm_psci_pm_ops. The Cavium
 * platform will take care of registering the handlers with PSCI.
 ******************************************************************************/
plat_psci_ops_t plat_octeontx_psci_pm_ops = {
	.pwr_domain_on		= octeontx_pwr_domain_on,
	.pwr_domain_on_finish	= octeontx_pwr_domain_on_finish,
	.pwr_domain_off		= octeontx_pwr_domain_off,
	.cpu_standby		= octeontx_cpu_standby,
	.pwr_domain_suspend	= octeontx_pwr_domain_suspend,
	.pwr_domain_suspend_finish	= octeontx_pwr_domain_suspend_finish,
	.system_off		= octeontx_system_off,
	.system_reset		= octeontx_system_reset,
	.validate_power_state	= octeontx_validate_power_state,
	.validate_ns_entrypoint = octeontx_validate_ns_entrypoint,
	.translate_power_state_by_mpidr = octeontx_translate_power_state_by_mpidr,
	.get_node_hw_state	= octeontx_node_hw_state,
	.get_sys_suspend_power_state = octeontx_get_sys_suspend_power_state
};


/*******************************************************************************
 * Private function to program the mailbox for a cpu before it is released
 * from reset. This function assumes that the Trusted mail box base is within
 * the TZDRAM shared region
 ******************************************************************************/
static void octeontx_program_trusted_mailbox(uintptr_t address)
{
       uintptr_t *mailbox = (void *) MAILBOX_BASE;

       *mailbox = address;
}

int octeontx_setup_psci_ops(uintptr_t sec_entrypoint,
				const plat_psci_ops_t **psci_ops)
{
	/* SCMI driver was already initalized here */
	assert(scmi_handle);

	/*
	 * Probe the SCP for capabilities, override existing entries if
	 * SCP does not support given ones
	 */
	*psci_ops = plat_octeontx_psci_override_pm_ops(&plat_octeontx_psci_pm_ops);

	/* Setup mailbox with entry point. */
	octeontx_program_trusted_mailbox(sec_entrypoint);

	return 0;
}
