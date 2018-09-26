/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <platform_def.h>
#include <cavm_npc_mcam_profile.h>

#ifdef NT_FW_CONFIG

static uint64_t mkex_blob_size;

uint64_t otx2_get_npc_profile_addr(uint64_t profile_id)
{
	/*
	 * Return base address of all profiles, ignoring the profile id,
	 * not the size of particular profile.
	 */

	return (uint64_t)(NT_FW_CONFIG_BASE);
}

uint64_t otx2_get_npc_profile_size(uint64_t profile_id)
{
	/*
	 * Return size of all loaded binary blob, ignoring the profile id,
	 * not the size of particular profile.
	 */

	return mkex_blob_size;
}

void plat_octeontx_set_nt_fw_config_size(uint64_t nt_fw_config_size)
{
	mkex_blob_size = nt_fw_config_size;
}
#endif
