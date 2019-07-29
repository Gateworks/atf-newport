/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <debug.h>
#include <octeontx_common.h>
#include <stdint.h>
#include <uuid.h>
#include <rvu.h>
#include <plat_board_cfg.h>
#include <cgx.h>
#include <smi.h>
#include <phy_mgmt.h>

int mdio_debug_read(int cgxlmac_id, int mode, int phyaddr, int devad,
		    int regnum)
{
	int cgx, lmac, ret;
	cgx_lmac_config_t *lcfg;
	phy_config_t *phy;

	cgx = (cgxlmac_id >> 4)	& 0xF;
	lmac = cgxlmac_id & 0xF;
	lcfg = &plat_octeontx_bcfg->cgx_cfg[cgx].lmac_cfg[lmac];

	if (!lcfg->phy_present)
		return 0;

	phy = &lcfg->phy_config;
	lcfg->mdio_bus_dbg = phy->mdio_bus;

	smi_set_switch(phy, 1);
	ret = smi_read(phy->mdio_bus, mode, phyaddr, devad, regnum);
	smi_set_switch(phy, 0);

	lcfg->mdio_bus_dbg = -1;
	return ret;
}

int mdio_debug_write(int cgxlmac_id, int mode, int phyaddr, int devad,
		     int regnum, uint16_t value)
{
	int cgx, lmac, ret;
	cgx_lmac_config_t *lcfg;
	phy_config_t *phy;

	cgx = (cgxlmac_id >> 4)	& 0xF;
	lmac = cgxlmac_id & 0xF;
	lcfg = &plat_octeontx_bcfg->cgx_cfg[cgx].lmac_cfg[lmac];

	if (!lcfg->phy_present)
		return 0;

	phy = &lcfg->phy_config;
	lcfg->mdio_bus_dbg = phy->mdio_bus;

	smi_set_switch(phy, 1);
	ret = smi_write(phy->mdio_bus, phyaddr, devad, mode, regnum, value);
	smi_set_switch(phy, 0);

	lcfg->mdio_bus_dbg = -1;
	return ret;
}
