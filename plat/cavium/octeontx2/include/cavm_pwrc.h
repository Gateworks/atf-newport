/** @file

    Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
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

#endif /* __CAVM_PWRC_H__ */
