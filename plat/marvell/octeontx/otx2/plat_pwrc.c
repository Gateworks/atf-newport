/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <arch_helpers.h>
#include <assert.h>
#include <debug.h>
#include <plat_pwrc.h>
#include <platform_def.h>
#include <platform_setup.h>
#include <platform.h>
#include <string.h>
#include <octeontx_common.h>
#include <plat_scmi.h>
#include <gicv3_setup.h>

/*
 * This file implements the SCP helper functions using SCMI protocol.
 */

/*
 * SCMI power state parameter bit field encoding for Cavium platforms.
 *
 * 31  20 19       16 15      12 11       8 7        4 3         0
 * +-------------------------------------------------------------+
 * | SBZ | Max level |  Level 3 |  Level 2 |  Level 1 |  Level 0 |
 * |     |           |   state  |   state  |   state  |   state  |
 * +-------------------------------------------------------------+
 *
 * `Max level` encodes the highest level that has a valid power state
 * encoded in the power state.
 */
#define SCMI_PWR_STATE_MAX_PWR_LVL_SHIFT	16
#define SCMI_PWR_STATE_MAX_PWR_LVL_WIDTH	4
#define SCMI_PWR_STATE_MAX_PWR_LVL_MASK		\
				((1 << SCMI_PWR_STATE_MAX_PWR_LVL_WIDTH) - 1)
#define SCMI_SET_PWR_STATE_MAX_PWR_LVL(pwr_state, max_lvl)		\
		(pwr_state) |= ((max_lvl) & SCMI_PWR_STATE_MAX_PWR_LVL_MASK)	\
				<< SCMI_PWR_STATE_MAX_PWR_LVL_SHIFT
#define SCMI_GET_PWR_STATE_MAX_PWR_LVL(pwr_state)		\
		(((pwr_state) >> SCMI_PWR_STATE_MAX_PWR_LVL_SHIFT)	\
				& SCMI_PWR_STATE_MAX_PWR_LVL_MASK)

#define SCMI_PWR_STATE_LVL_WIDTH		4
#define SCMI_PWR_STATE_LVL_MASK			\
				((1 << SCMI_PWR_STATE_LVL_WIDTH) - 1)
#define SCMI_SET_PWR_STATE_LVL(pwr_state, lvl, lvl_state)		\
		(pwr_state) |= ((lvl_state) & SCMI_PWR_STATE_LVL_MASK)	\
				<< (SCMI_PWR_STATE_LVL_WIDTH * (lvl))
#define SCMI_GET_PWR_STATE_LVL(pwr_state, lvl)		\
		(((pwr_state) >> (SCMI_PWR_STATE_LVL_WIDTH * (lvl))) &	\
				SCMI_PWR_STATE_LVL_MASK)

/*
 * The global handle for invoking the SCMI driver APIs after the driver
 * has been initialized.
 */
void *scmi_handle = NULL;

/* The SCMI channel global object */
static scmi_channel_t scmi_channel;

/* Global platform SCMI info */
scmi_channel_plat_info_t plat_octeontx_scmi_plat_info;

/* Create bakery lock instance for SCMI purposes */
DEFINE_BAKERY_LOCK(octeontx_scmi_lock);

/*
 * Helper function to suspend a CPU power domain and its parent power domains
 * if applicable.
 */
void octeontx_scp_suspend(const psci_power_state_t *target_state)
{
	int lvl, ret;
	uint32_t scmi_pwr_state = 0;

	/* At least power domain level 0 should be specified to be suspended */
	assert(target_state->pwr_domain_state[CAVM_PWR_LVL0] ==
						CAVM_LOCAL_STATE_OFF);

	/* Check if power down at system power domain level is requested */
	if (CAVM_SYSTEM_PWR_STATE(target_state) == CAVM_LOCAL_STATE_OFF) {
		/* Issue SCMI command for SYSTEM_SUSPEND */
		ret = scmi_sys_pwr_state_set(scmi_handle,
				SCMI_SYS_PWR_FORCEFUL_REQ,
				SCMI_SYS_PWR_SUSPEND);
		if (ret != SCMI_E_SUCCESS) {
			ERROR("SCMI system power domain suspend return 0x%x unexpected\n",
					ret);
			panic();
		}
		return;
	}

	/*
	 * If we reach here, then assert that power down at system power domain
	 * level is running.
	 */
	assert(target_state->pwr_domain_state[CAVM_SYSTEM_PWR_DMN_LVL] ==
							CAVM_LOCAL_STATE_RUN);

	/* For level 0, specify `scmi_power_state_sleep` as the power state */
	SCMI_SET_PWR_STATE_LVL(scmi_pwr_state, CAVM_PWR_LVL0,
						scmi_power_state_sleep);

	for (lvl = CAVM_PWR_LVL1; lvl <= PLAT_MAX_PWR_LVL; lvl++) {
		if (target_state->pwr_domain_state[lvl] == CAVM_LOCAL_STATE_RUN)
			break;

		assert(target_state->pwr_domain_state[lvl] ==
							CAVM_LOCAL_STATE_OFF);
		/*
		 * Specify `scmi_power_state_off` as power state for higher
		 * levels.
		 */
		SCMI_SET_PWR_STATE_LVL(scmi_pwr_state, lvl,
						scmi_power_state_off);
	}

	SCMI_SET_PWR_STATE_MAX_PWR_LVL(scmi_pwr_state, lvl - 1);

	ret = scmi_pwr_state_set(scmi_handle,
		plat_octeontx_core_pos_to_scmi_dmn_id_map[plat_my_core_pos()],
		scmi_pwr_state);

	if (ret != SCMI_E_SUCCESS) {
		ERROR("SCMI set power state command return 0x%x unexpected\n",
				ret);
		panic();
	}
}

/*
 * Helper function to turn off a CPU power domain and its parent power domains
 * if applicable.
 */
void octeontx_scp_off(const psci_power_state_t *target_state)
{
	int lvl = 0, ret;
	uint32_t scmi_pwr_state = 0;

	/* At-least the CPU level should be specified to be OFF */
	assert(target_state->pwr_domain_state[CAVM_PWR_LVL0] ==
							CAVM_LOCAL_STATE_OFF);

	/* PSCI CPU OFF cannot be used to turn OFF system power domain */
	assert(target_state->pwr_domain_state[CAVM_SYSTEM_PWR_DMN_LVL] ==
							CAVM_LOCAL_STATE_RUN);

	for (; lvl <= PLAT_MAX_PWR_LVL; lvl++) {
		if (target_state->pwr_domain_state[lvl] == CAVM_LOCAL_STATE_RUN)
			break;

		assert(target_state->pwr_domain_state[lvl] ==
							CAVM_LOCAL_STATE_OFF);
		SCMI_SET_PWR_STATE_LVL(scmi_pwr_state, lvl,
				scmi_power_state_off);
	}

	SCMI_SET_PWR_STATE_MAX_PWR_LVL(scmi_pwr_state, lvl - 1);

	ret = scmi_pwr_state_set(scmi_handle,
		plat_octeontx_core_pos_to_scmi_dmn_id_map[plat_my_core_pos()],
		scmi_pwr_state);

	if (ret != SCMI_E_QUEUED && ret != SCMI_E_SUCCESS) {
		ERROR("SCMI set power state command return 0x%x unexpected\n",
				ret);
		panic();
	}
}

/*
 * Helper function to turn ON a CPU power domain and its parent power domains
 * if applicable.
 */
void octeontx_scp_on(u_register_t mpidr)
{
	int lvl = 0, ret, core_pos;
	uint32_t scmi_pwr_state = 0;

	for (; lvl <= PLAT_MAX_PWR_LVL; lvl++)
		SCMI_SET_PWR_STATE_LVL(scmi_pwr_state, lvl,
				scmi_power_state_on);

	SCMI_SET_PWR_STATE_MAX_PWR_LVL(scmi_pwr_state, lvl - 1);

	core_pos = plat_core_pos_by_mpidr(mpidr);
	assert(core_pos >= 0 && core_pos < PLATFORM_CORE_COUNT);

	ret = scmi_pwr_state_set(scmi_handle,
		plat_octeontx_core_pos_to_scmi_dmn_id_map[core_pos],
		scmi_pwr_state);

	if (ret != SCMI_E_QUEUED && ret != SCMI_E_SUCCESS) {
		ERROR("SCMI set power state command return 0x%x unexpected\n",
				ret);
		panic();
	}
}

/*
 * Helper function to get the power state of a power domain node as reported
 * by the SCP.
 */
int octeontx_scp_get_power_state(u_register_t mpidr, unsigned int power_level)
{
	int ret, cpu_idx;
	uint32_t scmi_pwr_state = 0, lvl_state;

	/* We don't support get power state at the system power domain level */
	if ((power_level > PLAT_MAX_PWR_LVL) ||
			(power_level == CAVM_SYSTEM_PWR_DMN_LVL)) {
		WARN("Invalid power level %u specified for SCMI get power state\n",
				power_level);
		return PSCI_E_INVALID_PARAMS;
	}

	cpu_idx = plat_core_pos_by_mpidr(mpidr);
	assert(cpu_idx > -1);

	ret = scmi_pwr_state_get(scmi_handle,
		plat_octeontx_core_pos_to_scmi_dmn_id_map[cpu_idx],
		&scmi_pwr_state);

	if (ret != SCMI_E_SUCCESS) {
		WARN("SCMI get power state command return 0x%x unexpected\n",
				ret);
		return PSCI_E_INVALID_PARAMS;
	}

	/*
	 * Find the maximum power level described in the get power state
	 * command. If it is less than the requested power level, then assume
	 * the requested power level is ON.
	 */
	if (SCMI_GET_PWR_STATE_MAX_PWR_LVL(scmi_pwr_state) < power_level)
		return HW_ON;

	lvl_state = SCMI_GET_PWR_STATE_LVL(scmi_pwr_state, power_level);
	if (lvl_state == scmi_power_state_on)
		return HW_ON;

	assert((lvl_state == scmi_power_state_off) ||
				(lvl_state == scmi_power_state_sleep));
	return HW_OFF;
}

/*
 * Helper function to shutdown the system via SCMI.
 */
void __dead2 octeontx_scp_sys_shutdown(void)
{
	int ret;

	/*
	 * Disable GIC CPU interface to prevent pending interrupt from waking
	 * up the AP from WFI.
	 */
	octeontx_gic_cpuif_disable();

	/*
	 * Issue SCMI command for SYSTEM_SHUTDOWN. First issue a graceful
	 * request and if that fails force the request.
	 */
	ret = scmi_sys_pwr_state_set(scmi_handle,
			SCMI_SYS_PWR_FORCEFUL_REQ,
			SCMI_SYS_PWR_SHUTDOWN);
	if (ret != SCMI_E_SUCCESS) {
		ERROR("SCMI system power domain shutdown return 0x%x unexpected\n",
				ret);
		panic();
	}

	wfi();
	ERROR("Cavium SCP System Shutdown: operation not handled.\n");
	panic();
}

/*
 * Helper function to reset the system via SCMI.
 */
void __dead2 octeontx_scp_sys_reboot(void)
{
	int ret;

	/*
	 * Disable GIC CPU interface to prevent pending interrupt from waking
	 * up the AP from WFI.
	 */
	octeontx_gic_cpuif_disable();

	/*
	 * Issue SCMI command for SYSTEM_REBOOT. First issue a graceful
	 * request and if that fails force the request.
	 */
	ret = scmi_sys_pwr_state_set(scmi_handle,
			SCMI_SYS_PWR_FORCEFUL_REQ,
			SCMI_SYS_PWR_COLD_RESET);
	if (ret != SCMI_E_SUCCESS) {
		ERROR("SCMI system power domain reset return 0x%x unexpected\n",
				ret);
		panic();
	}

	wfi();
	ERROR("Cavium SCP System Reset: operation not handled.\n");
	panic();
}

static int octeontx_pwrc_init_scmi(scmi_channel_plat_info_t *plat_scmi_info)
{
	assert(plat_scmi_info);

	plat_scmi_info->scmi_mbx_mem = plat_get_scmi_mbox_addr();
	plat_scmi_info->db_reg_addr = plat_get_scmi_db_addr();
	plat_scmi_info->db_preserve_mask = PLAT_SCMI_DB_PRESERVE_MASK;
	plat_scmi_info->db_modify_mask = PLAT_SCMI_DB_MODIFY_MASK;

	return 0;
}

int octeontx_pwrc_setup(void)
{
	/* Initialize platform SCMI config structure */
	octeontx_pwrc_init_scmi(&plat_octeontx_scmi_plat_info);

	scmi_channel.info = &plat_octeontx_scmi_plat_info;
	scmi_channel.lock = &octeontx_scmi_lock;
	scmi_handle = scmi_init(&scmi_channel);
	if (scmi_handle == NULL) {
		NOTICE("SCMI Initialization failed, fallback to legacy PM\n");
		return -1;
	}

	return 0;
}

/******************************************************************************
 * This function overrides the default definition for Cavium platforms. Initialize
 * the SCMI driver, query capability via SCMI and modify the PSCI capability
 * based on that.
 *****************************************************************************/
const plat_psci_ops_t *plat_octeontx_psci_override_pm_ops(plat_psci_ops_t *ops)
{
	uint32_t msg_attr;
	int ret;

	assert(scmi_handle);

	/* Check that power domain POWER_STATE_SET message is supported */
	ret = scmi_proto_msg_attr(scmi_handle, SCMI_PWR_DMN_PROTO_ID,
				SCMI_PWR_STATE_SET_MSG, &msg_attr);
	if (ret != SCMI_E_SUCCESS) {
		ERROR("Set power state command is not supported by SCMI\n");
		panic();
	}

	/*
	 * Don't support PSCI NODE_HW_STATE call if SCMI doesn't support
	 * POWER_STATE_GET message.
	 */
	ret = scmi_proto_msg_attr(scmi_handle, SCMI_PWR_DMN_PROTO_ID,
				SCMI_PWR_STATE_GET_MSG, &msg_attr);
	if (ret != SCMI_E_SUCCESS)
		ops->get_node_hw_state = NULL;

	/* Check if the SCMI SYSTEM_POWER_STATE_SET message is supported */
	ret = scmi_proto_msg_attr(scmi_handle, SCMI_SYS_PWR_PROTO_ID,
				SCMI_SYS_PWR_STATE_SET_MSG, &msg_attr);
	if (ret != SCMI_E_SUCCESS) {
		/* System power management operations are not supported */
		ops->system_off = NULL;
		ops->system_reset = NULL;
		ops->get_sys_suspend_power_state = NULL;
	} else if (!(msg_attr & SCMI_SYS_PWR_SUSPEND_SUPPORTED)) {
		/*
		 * System power management protocol is available, but it does
		 * not support SYSTEM SUSPEND.
		 */
		ops->get_sys_suspend_power_state = NULL;
	}

	return ops;
}
