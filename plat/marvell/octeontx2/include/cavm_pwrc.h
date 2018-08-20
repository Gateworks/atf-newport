/** @file

    Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_PWRC_H__
#define __CAVM_PWRC_H__

#include <cdefs.h>
#include <psci.h>
#include <types.h>

/* SCMI related defines */

/*
 * Macros mapping the MPIDR Affinity levels to Cavium Platform Power levels. The
 * power levels have a 1:1 mapping with the MPIDR affinity levels.
 */
#define CAVM_PWR_LVL0		MPIDR_AFFLVL0
#define CAVM_PWR_LVL1		MPIDR_AFFLVL1
#define CAVM_PWR_LVL2		MPIDR_AFFLVL2

/*
 *  Macros for local power states in Cavium platforms encoded by State-ID field
 *  within the power-state parameter.
 */

/* Local power state for power domains in Run state. */
#define CAVM_LOCAL_STATE_RUN	0
/* Local power state for retention. Valid only for CPU power domains */
#define CAVM_LOCAL_STATE_RET	1
/* Local power state for OFF/power-down. Valid for CPU and cluster power
   domains */
#define CAVM_LOCAL_STATE_OFF	2

/* System power domain at level 2, as currently implemented by Cavium platforms */
#define CAVM_SYSTEM_PWR_DMN_LVL		CAVM_PWR_LVL2

/* Macros to read the CAVM power domain state */
#define CAVM_CORE_PWR_STATE(state)	(state)->pwr_domain_state[CAVM_PWR_LVL0]
#define CAVM_CLUSTER_PWR_STATE(state)	(state)->pwr_domain_state[CAVM_PWR_LVL1]
#define CAVM_SYSTEM_PWR_STATE(state)	\
			((PLAT_MAX_PWR_LVL == CAVM_SYSTEM_PWR_DMN_LVL) ?\
			(state)->pwr_domain_state[CAVM_SYSTEM_PWR_DMN_LVL] : 0)

/*
 * The SCMI power state enumeration for a power domain level
 */
typedef enum {
	scmi_power_state_off = 0,
	scmi_power_state_on = 1,
	scmi_power_state_sleep = 2,
} scmi_power_state_t;

/* Exported functions for SCP usage */
void cavm_scp_suspend(const psci_power_state_t *target_state);
void cavm_scp_off(const psci_power_state_t *target_state);
void cavm_scp_on(u_register_t mpidr);
int cavm_scp_get_power_state(u_register_t mpidr, unsigned int power_level);
void __dead2 cavm_scp_sys_shutdown(void);
void __dead2 cavm_scp_sys_reboot(void);

const plat_psci_ops_t *plat_cavm_psci_override_pm_ops(plat_psci_ops_t *ops);

int cavm_pwrc_setup(void);
int cavm_setup_psci_ops(uintptr_t sec_entrypoint,
			const plat_psci_ops_t **psci_ops);

#endif /* __CAVM_PWRC_H__ */
