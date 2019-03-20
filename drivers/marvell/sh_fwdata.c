/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

/* SH FW DATA management driver for OcteonTX2 */

#include <stdio.h>
#include <arch.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <plat_board_cfg.h>
#include <rvu.h>
#include <sh_fwdata.h>
#include <platform.h>
#include <assert.h>
#include <debug.h>
#include <octeontx_utils.h>
#include <plat_scfg.h>

#undef DEBUG_ATF_SH_MEM_MGMT

#ifdef DEBUG_ATF_SH_MEM_MGMT
#define debug_shmem_mgmt printf
#else
#define debug_shmem_mgmt(...) ((void) (0))
#endif

void sh_fwdata_init(void)
{
	struct sh_fwdata *fwdata;
	int i, pf_mac_num;
	uint64_t pf_mac;

	fwdata = (struct sh_fwdata *)get_sh_fwdata_base();
	if (get_sh_fwdata_base() + sizeof(struct sh_fwdata) > RVU_MEM_END) {
		fwdata->header_magic = 0x0;
		ERROR("SHARED FWDATA size misconfiguration\n");
		return;
	}
	fwdata->header_magic = SH_FWDATA_HEADER_MAGIC;
	fwdata->version = SH_FWDATA_VERSION;

	/* MAC address */
	pf_mac_num = plat_octeontx_bcfg->pf_mac_num;
	pf_mac = plat_octeontx_bcfg->pf_mac_base;

	/* Clear MAC tables */
	for (i = 0; i < PF_MACNUM_MAX; i++)
		fwdata->pf_macs[i]  = 0;

	for (i = 0; i < VF_MACNUM_MAX; i++)
		fwdata->vf_macs[i] = 0;

	/* Init PF MAC address; Skip PF 0 used as AF */
	for (i = 1; i < pf_mac_num; i++) {
		if (i >= PF_MACNUM_MAX)
			break;
		fwdata->pf_macs[i] = pf_mac;
		pf_mac++;
	}
}

