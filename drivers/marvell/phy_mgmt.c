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

/* Table to map the PHY speed to CGX speed enum for clause 45
 * From IEEE 803.2 cd (amendment) clause 45
 * Bits 1.0.5.2 (for this bits to be effective bit 6
 * (MSB speed selection) & 13 (LSB speed selection)
 * should be set
 * Speed selection
 * 5 4 3 2
 * 1 1 x x = Reserved
 * 1 0 1 x = Reserved
 * 1 0 0 1 = 400 Gb/s
 * 1 0 0 0 = 200 Gb/s
 * 0 1 1 1 = 5 Gb/s
 * 0 1 1 0 = 2.5 Gb/s
 * 0 1 0 1 = 50 Gb/s
 * 0 1 0 0 = 25 Gb/s
 * 0 0 1 1 = 100 Gb/s
 * 0 0 1 0 = 40 Gb/s
 * 0 0 0 1 = 10PASS-TS/2BASE-TL
 * 0 0 0 0 = 10 Gb/s
 */
static int cgx_speed[PHY_CLAUSE45_MAX_SPEED_SEL] = {CGX_LINK_10G,
				CGX_LINK_NONE,
				CGX_LINK_40G,
				CGX_LINK_100G,
				CGX_LINK_25G,
				CGX_LINK_50G,
				CGX_LINK_2HG,
				CGX_LINK_5G};

static void octeontx_get_generic_8023_c22_phy_link_state(phy_config_t *phy,
							link_state_t *link)
{
	int addr = phy->phy_addr;
	int mdio = phy->mdio_bus;
	int control;		/* reg 0 */
	int status;		/* reg 1 */
	int an_adv;		/* reg 4 */
	int link_partner_abil;	/* reg 5 */
	int ms_control;		/* reg 9 */
	int ms_status;		/* reg 10 */

	if ((mdio == -1) || (addr == -1)) {
		ERROR("%s: mdio bus/addr not valid\n", __func__);
		return;
	}
	debug_nw_mgmt("%s: mdio_bus %d phy_addr 0x%x\n", __func__, mdio, addr);

	link->u64 = 0;

	status = smi_read(mdio, CLAUSE22, addr, -1, 1);
	if (!(status & 0x4))	/* check bit 2 for Link Status */
		return;		/* Link is down, return link down */

	link->s.link_up = 1;
	control = smi_read(mdio, CLAUSE22, addr, -1, 0);
	/* Check if AN is enabled & complete */
	if ((control & (1 << 12)) && (status & (1 << 5))) {
		debug_nw_mgmt("AN is enabled & complete\n");
		ms_control = smi_read(mdio, CLAUSE22, addr, -1, 0x9);
		ms_status = smi_read(mdio, CLAUSE22, addr, -1, 0xA);

		ms_status &= ms_control << 2;
		link_partner_abil = smi_read(mdio, CLAUSE22, addr, -1, 0x5);
		an_adv = smi_read(mdio, CLAUSE22, addr, -1, 0x4);
		link_partner_abil &= an_adv;

		if (ms_status & 0xC00) {
			link->s.speed = CGX_LINK_1G;
			link->s.full_duplex = !!(ms_status & 0x800);
		} else if (link_partner_abil & 0x0180) {
			link->s.speed = CGX_LINK_100M;
			link->s.full_duplex = !!(link_partner_abil & 0x100);
		} else if (link_partner_abil & 0x0060) {
			link->s.speed = CGX_LINK_10M;
			link->s.full_duplex = !!(link_partner_abil & 0x0040);
		}
	} else {
		/* AN not enabled */
		debug_nw_mgmt("AN is not complete\n");
		link->s.full_duplex = !!(control & (1 << 8));

		if (control & (1 << 6))
			link->s.speed = CGX_LINK_1G;
		else if (control & (1 << 13))
			link->s.speed = CGX_LINK_100M;
		else
			link->s.speed = CGX_LINK_10M;
	}
}

static void octeontx_get_generic_8023_c45_phy_link_state(phy_config_t *phy,
							link_state_t *link)
{
	int addr = phy->phy_addr;
	int mdio = phy->mdio_bus;
	int speed_sel;
	int pma_ctrl1;	/* PMA/PMD control reg 0 */
	int phy_status;	/* PMA/PMD status reg 1 */

	if ((mdio == -1) || (addr == -1)) {
		ERROR("%s: mdio bus/addr not valid\n", __func__);
		return;
	}

	debug_nw_mgmt("%s: mdio_bus %d phy_addr 0x%x\n", __func__, mdio, addr);

	link->u64 = 0;
	pma_ctrl1 = smi_read(mdio, CLAUSE45, addr, PMA_PMD_DEVICE_ADDR,
					PMA_PMD_CONTROL_REG);
	/* From IEEE 803.2 spec
	 * section 45.2.1.1 PMA/PMD control 1 register (Register 1.0)
	 * Read bits 6 & 13
	 * 6 13
	 * 1 1 = bits 5:2 select speed
	 * 1 0 = 1000 Mb/s
	 * 0 1 = 100 Mb/s
	 * 0 0 = 10 Mb/s
	 */
	switch (pma_ctrl1 & PHY_CLAUSE45_SPEED_SEL_MASK) {
	case PHY_CLAUSE45_SPEED_10M:
		link->s.speed = CGX_LINK_10M;
		break;
	case PHY_CLAUSE45_SPEED_100M:
		link->s.speed = CGX_LINK_100M;
		break;
	case PHY_CLAUSE45_SPEED_1G:
		link->s.speed = CGX_LINK_1G;
		break;
	case PHY_CLAUSE45_SPEED_BITS_2_5_SEL:
		/* if bits 6 & 13 are set to 1, then bits 5:2 selects speed */
		speed_sel = octeontx_bit_extract(pma_ctrl1, 2, 4) & 0xF;
		if ((speed_sel >= 0x0) && (speed_sel < PHY_CLAUSE45_MAX_SPEED_SEL))
			link->s.speed = cgx_speed[speed_sel];
		else
			link->s.speed = CGX_LINK_NONE;
		break;
	default:
		link->s.speed = CGX_LINK_NONE;
		break;
	}
	/* PMA/PMD status reg
	 * 1.1.2 Receive link status
	 * 1 = PMA/PMD receive link up
	 * 0 = PMA/PMD receive link down
	 */
	phy_status = smi_read(mdio, CLAUSE45, addr, PMA_PMD_DEVICE_ADDR,
						PMA_PMD_STATUS_REG);
	link->s.link_up = octeontx_bit_extract(phy_status, 2, 1) & 0x1;
	if (link->s.link_up)
		link->s.full_duplex = 1;
}

int octeontx_get_phy_link_status(int cgx_id, int lmac_id,
						link_state_t *link)
{
	cgx_lmac_config_t *lmac = NULL;
	int ret = 0;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	/* Get the LMAC type for each LMAC */
	lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	debug_nw_mgmt("%s: mode %d\n", __func__, lmac->mode);

	/* FIXME: certain PHYs might need to handled differently.
	 * based on the special DT attribute, even for below modes
	 * link status should be read from PHY. use clause45
	 */
	if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_XAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_RXAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_TENG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_FIFTYG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R)) {
		/* obtain the status from CGX CSRs */
		cgx_xaui_get_link(cgx_id, lmac_id, link);
		debug_nw_mgmt("link %d speed %d duplex %d\n", link->s.link_up,
			link->s.speed, link->s.full_duplex);
		return ret;
	}

	/* in case of USXGMII, need to obtain link status from PHY */
	if (lmac->mode == CAVM_CGX_LMAC_TYPES_E_USXGMII) {
		octeontx_get_generic_8023_c45_phy_link_state(
						&lmac->phy_config, link);
		debug_nw_mgmt("link %d speed %d duplex %d\n", link->s.link_up,
			link->s.speed, link->s.full_duplex);
		return ret;
	}

	/* handle generic clause first */
	if (lmac->phy_config.clause == PHY_GENERIC_8023_C22) {
		octeontx_get_generic_8023_c22_phy_link_state(&lmac->phy_config, link);
	} else if (lmac->phy_config.clause == PHY_GENERIC_8023_C45) {
		octeontx_get_generic_8023_c45_phy_link_state(
					&lmac->phy_config, link);
	} else {
		/* FIXME: handle other specific PHY cases */
		ERROR("%s no compatible string for PHY found\n", __func__);
		ret = -1;
	}
	debug_nw_mgmt("link %d speed %d duplex %d\n", link->s.link_up,
			link->s.speed, link->s.full_duplex);
	return ret;
}

void octeontx_phy_reset(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_nw_mgmt("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	/* Enable the SMI/MDIO bus */
	if (phy->mdio_bus != -1)
		smi_reset(phy->mdio_bus);

}
