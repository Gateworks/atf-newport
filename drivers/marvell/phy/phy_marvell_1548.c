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

/* Some of the routines in 88E1548 driver are the same as in 88E1514 */
extern phy_drv_t marvell_1514_drv;

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

void phy_marvell_1548_probe(int cgx_id, int lmac_id)
{
	phy_config_t *phy;
	int mdio, addr;
	int val;

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	mdio = phy->mdio_bus;
	addr = phy->addr;

	debug_phy_driver("%s: %d:%d\n", __func__, mdio, addr);

	/* Make sure we're on page 0 (though 1 works too) */
	marvell_set_22_page(phy, 0);
	val = smi_read(mdio, CLAUSE22, addr, -1, MII_PHY_ID1_REG);
	NOTICE("%s: bus %d addr 0x%x PHY ID1 0x%x\n",
	       __func__, mdio, addr, val);

	val = smi_read(mdio, CLAUSE22, addr, -1, MII_PHY_ID2_REG);
	NOTICE("%s: bus %d addr 0x%x PHY ID2 0x%x\n",
	       __func__, mdio, addr, val);

	/* Find out what our mode and preferences are */
	marvell_set_22_page(phy, 18);
	val = smi_read(mdio, CLAUSE22, addr, -1, MII_88E1548_GENERAL_CONTROL_1);

	phy->marvell_88e1548_mode = val & 0x0007;
	phy->marvell_88e1548_media_pref = (val >> 4) & 0x0003;

	/* Set last copper based on the mode. */
	switch (phy->marvell_88e1548_mode) {
	case PHY_MEDIA_QSGMII_TO_1000BASE_X:
	case PHY_MEDIA_QSGMII_TO_100BASE_FX:
		/* These modes are only fiber */
		phy->last_copper = 0;
		break;
	case PHY_MEDIA_QSGMII_TO_AUTO_COPPER_SGMII:
	case PHY_MEDIA_QSGMII_TO_AUTO_COPPER_1000BASE_X:
		/* These modes support both copper and fiber */
		switch (phy->marvell_88e1548_media_pref) {
		case PHY_PREFERENCE_FIRST_MEDIA:
		case PHY_PREFERENCE_COPPER:
			phy->last_copper = 1;
			break;
		default:
			phy->last_copper = 0;
			break;
		}
	default:
		/* All other modes are copper only */
		phy->last_copper = 1;
		break;
	}
	marvell_set_22_page(phy, phy->last_copper ? 0 : 1);
}

/*
 * Get the phy link status for the Marvell 1548 phy
 */
void phy_marvell_1548_get_fiber_link_status(phy_config_t *phy,
					    link_state_t *link)
{
	int addr = phy->addr;
	int mdio = phy->mdio_bus;
	int status;

	if ((mdio == -1) || (addr == -1)) {
		ERROR("%s: mdio bus/addr not valid\n", __func__);
		return;
	}
	debug_phy_driver("%s: mdio_bus %d phy_addr %#x\n",
			__func__, mdio, addr);

	link->u64 = 0;

	/* The fiber link status is a little different than the copper link
	 * status since there is no need to check for autonegotiation
	 * completing, unlike the 88E1514.
	 */
	/* Use 1.17 for current current status */
	marvell_set_22_page(phy, 1);
	status = smi_read(mdio, CLAUSE22, addr, -1, MII_88E1514_STATUS_REG);
	if (!(status & (1 << 10)))	/* Check link */
		return;

	link->s.speed = mv_1g_link_speed[(status >> 14) & 0x3];
	if (link->s.speed == CGX_LINK_NONE)
		return;

	link->s.full_duplex = 1;
	link->s.link_up = 1;
}

/* To obtain link status for 88e1548 */
void phy_marvell_1548_get_link_status(int cgx_id, int lmac_id,
				      link_state_t *link)
{
	phy_config_t *phy;
	int is_auto = 0;
	int mdio, addr;

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	addr = phy->addr;
	mdio = phy->mdio_bus;

	if ((mdio == -1) || (addr == -1)) {
		ERROR("%s: mdio bus/addr not valid\n", __func__);
		return;
	}
	debug_phy_driver("%s: mdio_bus %d, phy_addr 0x%x\n", __func__,
			 mdio, addr);

	switch (phy->marvell_88e1548_mode) {
	/* Some modes force the link type */
	case PHY_MEDIA_QSGMII_TO_COPPER:
	case PHY_MEDIA_SGMII_TO_COPPER:
	case PHY_MEDIA_QSGMII_TO_SGMII:
	case PHY_MEDIA_SGMII_TO_QSGMII:
		/* Must be copper */
		phy->last_copper = 1;
		break;
	case PHY_MEDIA_QSGMII_TO_1000BASE_X:
	case PHY_MEDIA_QSGMII_TO_100BASE_FX:
		/* Must be fiber */
		phy->last_copper = 0;
		break;
	case PHY_MEDIA_QSGMII_TO_AUTO_COPPER_SGMII:
	case PHY_MEDIA_QSGMII_TO_AUTO_COPPER_1000BASE_X:
		/* Can be copper or fiber */
		is_auto = 1;
		break;
	default:
		ERROR("%s: Unknown 88e1548 media mode %#x\n",
		      __func__, phy->marvell_88e1548_mode);
		return;
	}

	/* The 88E1548 copper link status is the same as the 88E1514 however
	 * fiber links can ignore speed and duplex resolved bit as long as
	 * the link is up.  We keep track of the last link up port and
	 * continue to poll that port (as an optimization) rather than
	 * both ports. If the link is still up, we're good.
	 */
	if (phy->last_copper) {
		marvell_set_22_page(phy, 0);
		marvell_1514_drv.get_link_status(cgx_id, lmac_id, link);
	} else {
		phy_marvell_1548_get_fiber_link_status(phy, link);
	}

	if (link->s.link_up)
		return;

	/* The 88E1548 can automatically switch between copper and fiber
	 * so if it is in one of these ports and the link is down, check
	 * the link on the other port.  The last_copper field indicates
	 * if we expect to see link up with copper or fiber.  If the link
	 * is down and the interface is in auto mode, then check the other
	 * interface type.
	 */
	if (is_auto) {
		if (phy->last_copper) {
			/* Check fiber if copper is down */
			phy_marvell_1548_get_fiber_link_status(phy, link);
		} else {
			/* Check copper if fiber is down */
			marvell_set_22_page(phy, 0);
			marvell_1514_drv.get_link_status(cgx_id, lmac_id, link);
		}
		if (link->s.link_up) {
			/* Link is up, so we switch the last interface type */
			phy->last_copper = !phy->last_copper;
		} else {
			/* Both links are down.  Set to start with the
			 * preferred type.
			 */
			switch (phy->marvell_88e1548_media_pref) {
			case PHY_PREFERENCE_COPPER:
				phy->last_copper = 1;
				break;
			case PHY_PREFERENCE_FIBER:
				phy->last_copper = 0;
				break;
			default:
				/* No preference, leave as-is */
				break;
			}
		}
	}
}

void phy_marvell_1548_supported_modes(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	phy->supported_link_modes = ((1 << CGX_MODE_SGMII_BIT) |
			(1 << CGX_MODE_1000_BASEX_BIT) |
			(1 << CGX_MODE_QSGMII_BIT));
}

void phy_marvell_1548_set_an(int cgx_id, int lmac_id)
{
	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);
}

void phy_marvell_1548_reset(int cgx_id, int lmac_id)
{
	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);
}

void phy_marvell_1548_shutdown(int cgx_id, int lmac_id)
{
	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);
}

phy_drv_t marvell_1548_drv = {
	.drv_name		= "MARVELL-88E1548",
	.drv_type		= PHY_MARVELL_88E1548,
	.flags			= 0,
	.probe			= phy_marvell_1548_probe,
	.config			= phy_generic_config,
	.reset			= phy_marvell_1548_reset,
	.get_link_status	= phy_marvell_1548_get_link_status,
	.set_supported_modes	= phy_marvell_1548_supported_modes,
	.shutdown		= phy_marvell_1548_shutdown,
};

phy_drv_t *marvell_1548_check_type(int type)
{
	if (marvell_1548_drv.drv_type == type)
		return &marvell_1548_drv;
	return NULL;
}
