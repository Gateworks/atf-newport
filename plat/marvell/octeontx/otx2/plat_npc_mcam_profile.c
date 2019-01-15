/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <platform_def.h>
#include <plat_npc_mcam_profile.h>

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
