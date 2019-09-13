/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/* PHY driver for OcteonTX2 */

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <string.h>
#include <platform_def.h>
#include <timers.h>
#include <octeontx_common.h>
#include <delay_timer.h>
#include <plat_board_cfg.h>
#include <smi.h>
#include <cgx_intf.h>
#include <cgx.h>
#include <phy_mgmt.h>
#include <octeontx_utils.h>
#include <sh_fwdata.h>

/* define DEBUG_ATF_NW_MGMT to enable debug logs */
#undef DEBUG_ATF_NW_MGMT	/* PHY, SFP/QSFP management */

#ifdef DEBUG_ATF_NW_MGMT
#define debug_nw_mgmt printf
#else
#define debug_nw_mgmt(...) ((void) (0))
#endif

int phy_get_link_status(int cgx_id, int lmac_id,
				link_state_t *link)
{
	cgx_lmac_config_t *lmac = NULL;
	phy_config_t *phy = NULL;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	/* Get the LMAC type for each LMAC */
	lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac->phy_config;

	debug_nw_mgmt("%s: mode %d\n", __func__, lmac->mode);

	if (!lmac->phy_present)
		return -1;

	if (phy->mux_switch)
		smi_set_switch(phy, 1); /* Enable the switch */

	/* Call PHY specific probe callback here */
	if (phy->valid)
		lmac->phy_config.drv->get_link_status(cgx_id,
				lmac_id, link);

	if (phy->mux_switch)
		smi_set_switch(phy, 0); /* Disable the switch */

	return 0;
}

void phy_probe(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	/* Enable the SMI/MDIO bus */
	smi_reset(phy->mdio_bus);

	if (phy->mux_switch)
		smi_set_switch(phy, 1); /* enable the switch */

	/* Call PHY specific probe callback here */
	if (phy->valid)
		phy->drv->probe(cgx_id, lmac_id);

	if (phy->mux_switch)
		smi_set_switch(phy, 0); /* Disable the switch */

	sh_fwdata_update_phy_mod_type(cgx_id, lmac_id);
	sh_fwdata_update_phy_can_change_mod_type(cgx_id, lmac_id);
}

void phy_config(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	if (phy->mux_switch)
		smi_set_switch(phy, 1); /* Enable the switch */

	/* Call PHY specific config callback here */
	if (phy->valid)
		phy->drv->config(cgx_id, lmac_id);

	if (phy->mux_switch)
		smi_set_switch(phy, 0); /* Disable the switch */
}

int phy_set_mod_type(int cgx_id, int lmac_id, phy_mod_type mod_type)
{
	cgx_lmac_config_t *lmac;
	phy_config_t *phy;
	int qlm_mode;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac->phy_config;

	if (phy->mod_type == mod_type)
		return 0; /* no change in mod_type */

	if (!(phy->drv->flags & PHY_FLAG_SUPPORTS_CHANGING_MOD_TYPE)) {
		ERROR("%s: %d:%d Changing PHY modulation type not supported\n",
		      __func__, cgx_id, lmac_id);
		return -1;
	}

	if (mod_type != PHY_MOD_TYPE_PAM4 && mod_type != PHY_MOD_TYPE_NRZ) {
		ERROR("%s: %d:%d invalid mod_type %d\n", __func__, cgx_id,
		      lmac_id, mod_type);
		return -1;
	}

	if (mod_type == PHY_MOD_TYPE_PAM4) {
		qlm_mode = lmac->mode_idx;
		switch (qlm_mode) {
		/* For now, only these two QLM modes are permitted to have
		 * PAM4 modulation on the PHY line side.
		 */
		case QLM_MODE_50GAUI_2_C2C:
		case QLM_MODE_50GAUI_4_C2C:
			phy->mod_type = PHY_MOD_TYPE_PAM4;
			if (lmac->fec != CGX_FEC_RS) {
				WARN("%s: %d:%d Setting FEC to RS because PAM4 requires it.\n",
				     __func__, cgx_id, lmac_id);
				cgx_set_fec_type(cgx_id, lmac_id, CGX_FEC_RS);
				cgx_update_flash_fec_param(cgx_id, lmac_id,
							   CGX_FEC_RS);
				/* No need to call phy_config() here because it
				 * already got called from cgx_set_fec_type().
				 */
			} else {
				phy_config(cgx_id, lmac_id);
			}
			break;

		default:
			ERROR("%s: %d:%d PAM4 is not supported at current link speed.\n",
			      __func__, cgx_id, lmac_id);
			return -1;
		}
	} else {
		phy->mod_type = PHY_MOD_TYPE_NRZ;
		phy_config(cgx_id, lmac_id);
	}

	sh_fwdata_update_phy_mod_type(cgx_id, lmac_id);

	return 0;
}

void phy_set_supported_link_modes(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	/* Call PHY specific callback here */
	if (phy->valid)
		phy->drv->set_supported_modes(cgx_id, lmac_id);
}

void phy_reset(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	if (phy->mux_switch)
		smi_set_switch(phy, 1); /* Enable the switch */

	/* Call PHY specific config callback here */
	if (phy->valid)
		phy->drv->reset(cgx_id, lmac_id);

	if (phy->mux_switch)
		smi_set_switch(phy, 0); /* Disable the switch */
}

void phy_lookup(int cgx_id, int lmac_id, int type)
{
	cgx_lmac_config_t *lmac;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	/* First look for PHY driver in Marvell PHY table */
	lmac->phy_config.drv = phy_marvell_drv_lookup(type);
	if (lmac->phy_config.drv != NULL) {
		lmac->phy_config.valid = 1;
		return;
	}
	/* Next look for PHY driver in Vitesse PHY table */
	lmac->phy_config.drv = phy_vitesse_drv_lookup(type);
	if (lmac->phy_config.drv != NULL) {
		lmac->phy_config.valid = 1;
		return;
	}

	/* FIXME: Add new PHY table lookup here */

	/* Last, look for PHY type in Generic PHY table */
	lmac->phy_config.drv = phy_generic_drv_lookup(type);
	if (lmac->phy_config.drv != NULL) {
		lmac->phy_config.valid = 1;
		return;
	}

	/* If reached here, no valid PHY driver found */
	lmac->phy_config.valid = 0;
	ERROR("%s: %d:%d, no valid PHY driver found for type %d\n", __func__,
			cgx_id, lmac_id, type);
}

#ifdef DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS
int phy_enable_prbs(int cgx_id, int lmac_id, int host_side, int prbs, int dir)
{
	phy_config_t *phy;
	uint64_t ret = -1;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	if (phy->mux_switch)
		smi_set_switch(phy, 1); /* Enable the switch */

	/* Call PHY specific enable_prbs callback here */
	if (phy->valid && phy->drv->enable_prbs)
		ret = phy->drv->enable_prbs(cgx_id, lmac_id, host_side, prbs,
					dir);

	if (phy->mux_switch)
		smi_set_switch(phy, 0); /* Disable the switch */

	return ret;
}

int phy_disable_prbs(int cgx_id, int lmac_id, int host_side, int prbs)
{
	phy_config_t *phy;
	uint64_t ret = -1;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	if (phy->mux_switch)
		smi_set_switch(phy, 1); /* Enable the switch */

	/* Call PHY specific disable_prbs callback here */
	if (phy->valid && phy->drv->disable_prbs)
		ret = phy->drv->disable_prbs(cgx_id, lmac_id, host_side, prbs);

	if (phy->mux_switch)
		smi_set_switch(phy, 0); /* Disable the switch */

	return ret;
}

uint64_t phy_get_prbs_errors(int cgx_id, int lmac_id, int host_side,
	int clear, int prbs)
{
	phy_config_t *phy;
	uint64_t ret = -1;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	if (phy->mux_switch)
		smi_set_switch(phy, 1); /* Enable the switch */

	/* Call PHY specific get_prbs_errors callback here */
	if (phy->valid && phy->drv->get_prbs_errors)
		ret = phy->drv->get_prbs_errors(cgx_id, lmac_id, host_side,
					clear, prbs);

	if (phy->mux_switch)
		smi_set_switch(phy, 0); /* Disable the switch */

	return ret;
}
#endif /* DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS */

/* Wrapper APIs for SMI driver for now */
void phy_set_switch(phy_config_t *phy, int enable)
{
	smi_set_switch(phy, enable);
}

int phy_mdio_read(phy_config_t *phy, int mode, int devad, int reg)
{
	int val = 0;

	val = smi_read(phy->mdio_bus, mode, phy->addr, devad, reg);

	return val;
}

void phy_mdio_write(phy_config_t *phy, int mode, int devad, int reg, int val)
{
	smi_write(phy->mdio_bus, phy->addr, devad, mode, reg, val);
}
