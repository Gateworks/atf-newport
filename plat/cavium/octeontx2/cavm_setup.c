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
