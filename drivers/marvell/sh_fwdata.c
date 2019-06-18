/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

/* SH FW DATA management driver for OcteonTX2 */

#include <stdio.h>
#include <string.h>
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
#include <sfp_mgmt.h>

#ifdef NT_FW_CONFIG
#include <plat_npc_mcam_profile.h>
#endif

#undef DEBUG_ATF_SH_MEM_MGMT

#ifdef DEBUG_ATF_SH_MEM_MGMT
#define debug_shmem_mgmt printf
#else
#define debug_shmem_mgmt(...) ((void) (0))
#endif
#define RST_REF_CLK 50

static struct cgx_lmac_fwdata_s *get_sh_cgx_fwdata_ptr(int cgx_id, int lmac_id)
{
	struct sh_fwdata *fw_data;
	struct cgx_lmac_fwdata_s *sh_cgx_fwdata;

	fw_data = (struct sh_fwdata *)get_sh_fwdata_base();
	sh_cgx_fwdata = &fw_data->cgx_fw_data[cgx_id][lmac_id];

	debug_shmem_mgmt("%s: %d:%d fw_data %p cgx_fw_data %p\n",
					__func__, cgx_id,
					lmac_id, fw_data,
					sh_cgx_fwdata);
	return sh_cgx_fwdata;
}

void sh_fwdata_init(void)
{
	union cavm_rst_boot cavm_rst_boot_t;
	struct sh_fwdata *fwdata;
	int i, pf_mac_num;
	uint64_t pf_mac;

	fwdata = (struct sh_fwdata *)get_sh_fwdata_base();
	if (get_sh_fwdata_base() + sizeof(struct sh_fwdata) > RVU_MEM_END) {
		fwdata->header_magic = 0x0;
		ERROR("SHARED FWDATA size misconfiguration\n");
		return;
	}
	 memset(fwdata, 0, sizeof(fwdata));
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
	cavm_rst_boot_t.u = CSR_READ(CAVM_RST_BOOT);
	fwdata->rclk = cavm_rst_boot_t.s.c_mul * RST_REF_CLK;
	fwdata->sclk = cavm_rst_boot_t.s.pnr_mul * RST_REF_CLK;

#ifdef NT_FW_CONFIG
	fwdata->mcam_addr = otx2_get_npc_profile_addr(0);
	fwdata->mcam_sz = otx2_get_npc_profile_size(0);
#endif
}

void sh_fwdata_update_supported_fec(int cgx_id, int lmac_id)
{
	struct cgx_lmac_fwdata_s *fwdata;

	fwdata = get_sh_cgx_fwdata_ptr(cgx_id, lmac_id);

	fwdata->rw_valid = 0;

	/* FIXME: For now, return the FEC type based on PCS. when SFP mgmt
	 * is integrated fully, then supported FEC should be based on
	 * transceiver capabilities as well
	 */
	fwdata->supported_fec = cgx_get_supported_fec_type(cgx_id, lmac_id);

	fwdata->rw_valid = 1;
	debug_shmem_mgmt("%s: %d:%d fwdata->supported_fec %llx\n", __func__,
						cgx_id,
						lmac_id, fwdata->supported_fec);
}

void sh_fwdata_update_eeprom_data(int cgx_id, int lmac_id, uint16_t sff_id)
{
	struct cgx_lmac_fwdata_s *fwdata;
	sfp_shared_data_t *sh_data = sfp_get_sh_mem_ptr(cgx_id, lmac_id);

	fwdata = get_sh_cgx_fwdata_ptr(cgx_id, lmac_id);

	fwdata->rw_valid = 0;

	memcpy(fwdata->sfp_eeprom.buf, sh_data->buf, SFP_EEPROM_SIZE);

	fwdata->sfp_eeprom.sff_id = sff_id;
	fwdata->rw_valid = 1;
}

void sh_fwdata_clear_eeprom_data(int cgx_id, int lmac_id, uint16_t sff_id)
{
	struct cgx_lmac_fwdata_s *fwdata;

	fwdata = get_sh_cgx_fwdata_ptr(cgx_id, lmac_id);

	fwdata->rw_valid = 0;
	fwdata->sfp_eeprom.sff_id = 0;
	memset(fwdata->sfp_eeprom.buf, 0, SFP_EEPROM_SIZE);
	fwdata->rw_valid = 1;
}

int sh_fwdata_get_supported_fec(int cgx_id, int lmac_id)
{
	struct cgx_lmac_fwdata_s *fwdata;

	fwdata = get_sh_cgx_fwdata_ptr(cgx_id, lmac_id);

	debug_shmem_mgmt("%s: %d:%d supported fec %d\n", __func__,
			cgx_id, lmac_id,
			fwdata->supported_fec);

	return fwdata->supported_fec;
}

void sh_fwdata_update_phy_mod_type(int cgx_id, int lmac_id)
{
	struct cgx_lmac_fwdata_s *fwdata;
	phy_config_t *phy;
	cgx_lmac_config_t *lmac_cfg;

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	fwdata = get_sh_cgx_fwdata_ptr(cgx_id, lmac_id);

	fwdata->rw_valid = 0;
	/* Make sure Linux kernel sees rw_valid is cleared before changing
	 * other fields of fwdata.
	 */
	WMB;

	fwdata->phy.mod_type = phy->mod_type;
	/* Make sure that the write to phy_mod_type is done before indicating
	 * to Linux that fwdata is valid.
	 */
	WMB;

	fwdata->rw_valid = 1;
}

void sh_fwdata_update_phy_can_change_mod_type(int cgx_id, int lmac_id)
{
	struct cgx_lmac_fwdata_s *fwdata;
	phy_config_t *phy;
	cgx_lmac_config_t *lmac_cfg;

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	fwdata = get_sh_cgx_fwdata_ptr(cgx_id, lmac_id);

	fwdata->rw_valid = 0;
	/* Make sure Linux kernel sees rw_valid is cleared before changing
	 * other fields of fwdata.
	 */
	WMB;

	if (phy->drv->flags & PHY_FLAG_SUPPORTS_CHANGING_MOD_TYPE)
		fwdata->phy.can_change_mod_type = 1;
	else
		fwdata->phy.can_change_mod_type = 0;
	/* Make sure that the write to phy.can_change_mod_type is done before
	 * indicating to Linux that fwdata is valid.
	 */
	WMB;

	fwdata->rw_valid = 1;
}
