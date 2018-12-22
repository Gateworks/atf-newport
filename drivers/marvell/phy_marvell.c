/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <plat_board_cfg.h>
#include <cgx.h>
#include <cgx_intf.h>
#include <phy_mgmt.h>
#include <smi.h>

/* 5123 includes */
#include "mcdApiTypes.h"
#include "mcdApiRegs.h"
#include "mcdUtils.h"
#include "mcdAPI.h"
#include "mcdInitialization.h"
#include "mcdDiagnostics.h"
#include "mcdServiceCpuCm3BvFw.h"
#include "mcd_sbus_master.0x101A_0001.h"
#include "mcd_serdes.0x2464_0245swap.h"
#include "mcd_serdes.0x2464_0245.h"


/* 5113 includes */
#include "mxdApiTypes.h"
#include "mxdHwCntl.h"
#include "mxdUtils.h"
#include "mxdApiRegs.h"
#include "mxdFwDownload.h"
#include "mxdInitialization.h"
#include "mxdHwSerdesCntl.h"

/* define DEBUG_ATF_MARVELL_PHY_DRIVER to enable debug logs */
#undef DEBUG_ATF_MARVELL_PHY_DRIVER	/* Marvell PHY Driver logs */

#ifdef DEBUG_ATF_MARVELL_PHY_DRIVER
#define debug_phy_driver printf
#else
#define debug_phy_driver(...) ((void) (0))
#endif

MCD_DEV marvell_5123_priv;
MXD_DEV marvell_5113_priv;

static MCD_STATUS mcd_read_mdio(MCD_DEV_PTR pDev, MCD_U16 mdioPort, MCD_U16 mmd, MCD_U16 reg, MCD_U16 *value)
{
	phy_config_t *phy = pDev->hostContext;
	*value = phy_mdio_read(phy, CLAUSE45, mmd, reg);
	return MCD_OK;
}

static MCD_STATUS mcd_write_mdio(MCD_DEV_PTR pDev, MCD_U16 mdioPort, MCD_U16 mmd, MCD_U16 reg, MCD_U16 value)
{
	phy_config_t *phy = pDev->hostContext;
	phy_mdio_write(phy, mmd, CLAUSE45, reg, value);
	return MCD_OK;
}

static MXD_STATUS mxd_read_mdio(MXD_DEV_PTR pDev, MXD_U16 mdioPort, MXD_U16 mmd, MXD_U16 reg, MXD_U16 *value)
{
	phy_config_t *phy = pDev->hostContext;
	*value = phy_mdio_read(phy, CLAUSE45, mmd, reg);
	return MXD_OK;
}

static MXD_STATUS mxd_write_mdio(MXD_DEV_PTR pDev, MXD_U16 mdioPort, MXD_U16 mmd, MXD_U16 reg, MXD_U16 value)
{
	phy_config_t *phy = pDev->hostContext;
	phy_mdio_write(phy, mmd, CLAUSE45, reg, value);
	return MXD_OK;
}

/* To obtain link status for 88e1514 */
void phy_marvell_1514_get_link_status(int cgx_id, int lmac_id,
					link_state_t *link)
{
	int addr;
	int mdio;
	int status;		/* vendor specific reg 17 */
	phy_config_t *phy;

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	addr = phy->addr;
	mdio = phy->mdio_bus;

	if ((mdio == -1) || (addr == -1)) {
		ERROR("%s: mdio bus/addr not valid\n", __func__);
		return;
	}
	debug_phy_driver("%s: mdio_bus %d phy_addr 0x%x\n", __func__, mdio, addr);

	link->u64 = 0;

	/* As per 88E1514 Data sheet, either
	 * status register 0 should be read back-to-back or
	 * reg 17 should be read once for the current link status
	 */
	status = smi_read(mdio, CLAUSE22, addr, -1, MII_88E1514_STATUS_REG);
	debug_phy_driver("%s: status 0x%x\n", __func__, status);
	if (!(status & (1 << 10)))	/* Check bit 10 for real time status */
		return;			/* Link is down, return link down */

	/* Before reading the link speed, resolve bit needs to be checked
	 * As per datasheet, link speed bits are valid only when bit 11 of REG
	 * 17 is set (resolve bit). This bit indicates AN complete if
	 * AN is enabled or AN is disabled
	 */
	if (status & (1 << 11)) {
		/* Bit 14:15 for speed
		 * 11 = Reserved
		 * 10 = 1000 Mbps
		 * 01 = 100 Mbps
		 * 00 = 10 Mbps
		 */
		switch ((status >> 14) & 0x3) {
		case 0:
			link->s.speed = CGX_LINK_10M;
			break;
		case 1:
			link->s.speed = CGX_LINK_100M;
			break;
		case 2:
			link->s.speed = CGX_LINK_1G;
			break;
		default:
			link->s.speed = CGX_LINK_NONE;
			return;
		}
		link->s.link_up = 1;
		/* Bit 13 for duplex */
		link->s.full_duplex = ((status >> 13) & 1);
	}

}

/* One time initialization for the PHY if required */
void phy_marvell_5123_probe(int cgx_id, int lmac_id)
{
	MCD_STATUS status;
	phy_config_t *phy;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	phy->priv = (void *)&marvell_5123_priv;
	return;
	status = mcdInitDriver(mcd_read_mdio, mcd_write_mdio, phy->addr,
				(const MCD_U8 *)mcdServiceCpuCm3BvFw,
				sizeof(mcdServiceCpuCm3BvFw),
				(const MCD_U16 *)mcd_sbusMaster01x101A_0001Data,
				sizeof(mcd_sbusMaster01x101A_0001Data),
				(const MCD_U16 *)mcd_serdes0x2464_0245Swap,
				sizeof(mcd_serdes0x2464_0245Swap),
				(const MCD_U16 *)mcd_serdes0x2464_0245Data,
				sizeof(mcd_serdes0x2464_0245Data),
				phy, phy->priv);
	if (status != MCD_OK) {
		ERROR("%s: %d:%d MARVELL 5123 PHY driver Initialization failed\n",
			 __func__, cgx_id, lmac_id);
	}
}

/* To set the operating mode of the PHY if required */
void phy_marvell_5123_config(int cgx_id, int lmac_id)
{
	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);
}

/* To enable/disable AN */
void phy_marvell_5123_set_an(int cgx_id, int lmac_id)
{
	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);
}

/* To obtain the link status */
void phy_marvell_5123_get_link_status(int cgx_id, int lmac_id,
					link_state_t *link)
{

}

/* One time initialization for the PHY if required */
void phy_marvell_5113_probe(int cgx_id, int lmac_id)
{
	MXD_STATUS status;
	phy_config_t *phy;
	
	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	return;
	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	phy->priv = (void *)&marvell_5113_priv;

	status = mxdInitDriver(mxd_read_mdio, mxd_write_mdio, phy->addr,
				NULL, 0,
				NULL, 0,
				NULL, 0,
				phy, phy->priv);
	if (status != MXD_OK) {
		ERROR("%s: %d:%d MARVELL 5113 PHY driver Initialization failed\n",
			 __func__, cgx_id, lmac_id);
	}
}

/* To set the operating mode of the PHY if required */
void phy_marvell_5113_config(int cgx_id, int lmac_id)
{
	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);
}

/* To enable/disable AN */
void phy_marvell_5113_set_an(int cgx_id, int lmac_id)
{
	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);
}

/* To obtain the link status */
void phy_marvell_5113_get_link_status(int cgx_id, int lmac_id,
					link_state_t *link)
{
	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);
}

/* Table of Marvell PHY driver list */
phy_drv_t marvell_drv[] = {
	{
		.drv_name			= "MARVELL-88E1514",
		.drv_type			= PHY_MARVELL_88E1514,
		.flags				= 0,
		.probe				= phy_generic_probe,
		.config				= phy_generic_config,
		.set_an				= phy_generic_set_an,
		.reset				= phy_generic_reset,
		.get_link_status		= phy_marvell_1514_get_link_status,
		.shutdown			= phy_generic_shutdown,
	},
	{
		.drv_name 			= "MARVELL-88X5123",
		.drv_type 			= PHY_MARVELL_5123,
		.flags 				= 0,
		.probe 				= phy_marvell_5123_probe,
		.config 			= phy_marvell_5123_config,
		.set_an				= phy_marvell_5123_set_an,
		.reset 				= phy_generic_reset,
		.get_link_status		= phy_marvell_5123_get_link_status,
		.shutdown			= phy_generic_shutdown,
	},
	{
		.drv_name 			= "MARVELL-88X5113",
		.drv_type 			= PHY_MARVELL_5113,
		.flags	 			= 0,
		.probe 				= phy_marvell_5113_probe,
		.config	 			= phy_marvell_5113_config,
		.set_an				= phy_marvell_5113_set_an,
		.reset 				= phy_generic_reset,
		.get_link_status 		= phy_marvell_5113_get_link_status,
		.shutdown			= phy_generic_shutdown,
	},
};

phy_drv_t *phy_marvell_drv_lookup(int type)
{
	for (int i = 0; i < ARRAY_SIZE(marvell_drv); i++) {
		if (type == marvell_drv[i].drv_type) {
			debug_phy_driver("%s: found matching MARVELL PHY driver for type %d\n",
				__func__, type);
			return &marvell_drv[i];
		}
	}
	return NULL;
}
