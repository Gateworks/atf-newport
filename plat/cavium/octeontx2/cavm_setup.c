/** @file

  Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <cavm_common.h>
#include <cavm_cgx_intf.h>
#include <cavm_cgx.h>
#include <cavm_setup.h>
#include <cavm_pwrc.h>
#include <cavm_legacy_pwrc.h>

/* Any SoC family specific setup
 * to be done in BL31 can be initialized
 * in this API. If there are any platform
 * specific init to be done but not common
 * to family, each platform can define
 * its own API and can be called from here
 */
void plat_cavm_setup(void)
{
	/* Initialize CGX framework */
	cgx_fw_intf_init();
}

const uintptr_t plat_get_scmi_mbox_addr(int node)
{
	return CSR_PA(node, CAVM_CPC_RAM_MEMX(AP_SECURE0_TO_XCP_MBOX_OFFSET));
}

const uintptr_t plat_get_scmi_db_addr(int node)
{
	return CSR_PA(node, CAVM_XCPX_DEVX_XCP_MBOX(
			    CAVM_CPC_XCP_MAP_E_SCP,
			    CAVM_XCP_MBOX_DEV_E_AP_SECURE0));
}

extern void *scmi_handle;

void plat_pwrc_setup(void)
{
	int rc;

	/*
	 * Try to initialize SCMI, in case of error,
	 * fallback to legacy PM driver
	 */
	rc = cavm_pwrc_setup();
	if (rc) {
		cavm_legacy_pwrc_setup();
	}
}

void plat_setup_psci_ops(uintptr_t sec_entrypoint,
			 const plat_psci_ops_t **psci_ops)
{
	if (scmi_handle == NULL) {
		cavm_legacy_setup_psci_ops(sec_entrypoint, psci_ops);
	} else {
		cavm_setup_psci_ops(sec_entrypoint, psci_ops);
	}
}

