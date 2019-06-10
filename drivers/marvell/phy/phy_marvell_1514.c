/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <delay_timer.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <plat_board_cfg.h>
#include <cgx.h>
#include <cgx_intf.h>
#include <phy_marvell.h>
#include <phy_mgmt.h>
#include <pubsub.h>
#include <smi.h>

/* Set the register page number to use for Marvell clause 22 phys */
static void marvell_set_22_page(phy_config_t *phy, int page)
{
	/* Do nothing if we're not switching pages */
	if (page == phy->last_page)
		return;

	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22,
		  MII_MARVELL_22_PAGE_REG, page);
	phy->last_page = page;
}

/* Maps link speed bits to QLM link speed */
static const enum cgx_link_speed mv_1g_link_speed[4] = {
	CGX_LINK_10M, CGX_LINK_100M, CGX_LINK_1G, CGX_LINK_NONE,
};

/* One time initialization for the PHY if required */
void phy_marvell_1514_probe(int cgx_id, int lmac_id)
{
	int val;
	phy_config_t *phy;

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	debug_phy_driver("%s: %d:%d\n", __func__, phy->mdio_bus, phy->addr);

	/* Read the PHY ID and print it to user */
	val = smi_read(phy->mdio_bus, CLAUSE22, phy->addr, -1, MII_PHY_ID1_REG);
	NOTICE("%s: bus %d addr 0x%x PHY ID1 0x%x\n", __func__, phy->mdio_bus,
					phy->addr, val);

	val = smi_read(phy->mdio_bus, CLAUSE22, phy->addr, -1, MII_PHY_ID2_REG);
	NOTICE("%s: bus %d addr 0x%x PHY ID2 0x%x\n", __func__, phy->mdio_bus,
					phy->addr, val);

	/* EEE initialization */
	marvell_set_22_page(phy, 0xff);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 17, 0x214B);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 16, 0x2144);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 17, 0x0C28);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 16, 0x2146);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 17, 0xB233);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 16, 0x214D);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 17, 0xCC0C);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 16, 0x2159);
	marvell_set_22_page(phy, 0x00);

	/* SGMII-to-Copper mode initialization */
	/* Select page 18 */
	marvell_set_22_page(phy, 18);

	/* In reg 20, write MODE[2:0] = 0x1 (SGMII to Copper) */
	val = smi_read(phy->mdio_bus, CLAUSE22, phy->addr, -1, 20);
	val &= ~0x7; /* Clear Mode[2:0] */
	val |= 0x1; /* Mode[2:0} = SGMII */
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 20, val);

	/* PHY reset is necessary after changing MODE[2:0] */
	val |= 0x8000;
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 20, val);

	udelay(100);

	/* Reset page selection */
	marvell_set_22_page(phy, 0);
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
	debug_phy_driver("%s: mdio_bus %d phy_addr 0x%x\n",
			__func__, mdio, addr);

	link->u64 = 0;

	/* As per 88E1514 Data sheet, either
	 * status register 0 should be read back-to-back or
	 * reg 17 should be read once for the current link status
	 */
	status = smi_read(mdio, CLAUSE22, addr, -1, MII_88E1514_STATUS_REG);
	debug_phy_driver("%s: 88E1514 status 0x%x\n", __func__, status);
	if (!(status & (1 << 10)))	/* Check bit 10 for real time status */
		return;			/* Link is down, return link down */

	/* Before reading the link speed, resolve bit needs to be checked
	 * As per datasheet, link speed bits are valid only when bit 11 of REG
	 * 17 is set (resolve bit). This bit indicates AN complete if
	 * AN is enabled or AN is disabled
	 */
	if (status & (1 << 11)) {
		link->s.speed = mv_1g_link_speed[(status >> 14) & 0x3];
		if (link->s.speed == CGX_LINK_NONE)
			return;

		link->s.link_up = 1;
		/* Bit 13 for duplex */
		link->s.full_duplex = ((status >> 13) & 1);
	}
}

void phy_marvell_1514_supported_modes(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	phy->supported_link_modes = ((1 << CGX_MODE_SGMII_BIT) |
			(1 << CGX_MODE_1000_BASEX_BIT));
}

phy_drv_t marvell_1514_drv = {
		.drv_name		= "MARVELL-88E1514",
		.drv_type		= PHY_MARVELL_88E1514,
		.flags			= 0,
		.probe			= phy_marvell_1514_probe,
		.config			= phy_generic_config,
		.set_an			= phy_generic_set_an,
		.reset			= phy_generic_reset,
		.get_link_status	= phy_marvell_1514_get_link_status,
		.set_supported_modes	= phy_marvell_1514_supported_modes,
		.shutdown		= phy_generic_shutdown,
	};

phy_drv_t *marvell_1514_check_type(int type)
{
	if (marvell_1514_drv.drv_type == type)
		return &marvell_1514_drv;
	return NULL;
}
