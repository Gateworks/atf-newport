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
	int ret = 0;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	/* Get the LMAC type for each LMAC */
	lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac->phy_config;

	debug_nw_mgmt("%s: mode %d\n", __func__, lmac->mode);

	if (lmac->phy_present) {
		if (phy->mux_switch)
			smi_set_switch(phy, 1); /* Enable the switch */

		/* Call PHY specific probe callback here */
		if (phy->valid)
			lmac->phy_config.drv->get_link_status(cgx_id,
					lmac_id, link);

		if (phy->mux_switch)
			smi_set_switch(phy, 0); /* Disable the switch */

		debug_nw_mgmt("link %d speed %d duplex %d\n", link->s.link_up,
			link->s.speed, link->s.full_duplex);
		return ret;
	}

	if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_XAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_RXAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_TENG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_FIFTYG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R)) {
		/* Obtain the link status from CGX CSRs */
		cgx_xaui_get_link(cgx_id, lmac_id, link);
		debug_nw_mgmt("link %d speed %d duplex %d\n", link->s.link_up,
			link->s.speed, link->s.full_duplex);
		return ret;
	}

	/* Other cases should not reach here */
	ERROR("%s: Invalid reach\n", __func__);
	return -1;
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
