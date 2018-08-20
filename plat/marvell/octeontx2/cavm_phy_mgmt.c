
/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <string.h>
#include <platform_def.h>
#include <timers.h>
#include <cavm_common.h>
#include <delay_timer.h>
#include <cavm_dt.h>
#include <cavm_smi.h>
#include <cavm_cgx_intf.h>
#include <cavm_cgx.h>
#include <cavm_phy_mgmt.h>


/* define DEBUG_ATF_NW_MGMT to enable debug logs */
#undef DEBUG_ATF_NW_MGMT	/* PHY, SFP/QSFP management */

#ifdef DEBUG_ATF_NW_MGMT
#define debug_nw_mgmt printf
#else
#define debug_nw_mgmt(...) ((void) (0))
#endif

static void cavm_get_generic_8023_c22_phy_link_state(phy_config_t *phy,
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

	status = smi_phy_read(0, mdio, CLAUSE22, addr, -1, 1);
	if (!(status & 0x4))	/* check bit 2 for Link Status */
		return;		/* Link is down, return link down */

	link->s.link_up = 1;
	control = smi_phy_read(0, mdio, CLAUSE22, addr, -1, 0);
	/* Check if AN is enabled & complete */
	if ((control & (1 << 12)) && (status & (1 << 5))) {
		debug_nw_mgmt("AN is enabled & complete\n");
		ms_control = smi_phy_read(0, mdio, CLAUSE22, addr, -1, 0x9);
		ms_status = smi_phy_read(0, mdio, CLAUSE22, addr, -1, 0xA);

		ms_status &= ms_control << 2;
		link_partner_abil = smi_phy_read(0, mdio, CLAUSE22, addr, -1, 0x5);
		an_adv = smi_phy_read(0, mdio, CLAUSE22, addr, -1, 0x4);
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

int cavm_get_phy_link_status(int node, int cgx_id, int lmac_id,
						link_state_t *link)
{
	cgx_lmac_config_t *lmac = NULL;
	int ret = 0;

	debug_nw_mgmt("%s: %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	/* Get the LMAC type for each LMAC */
	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	debug_nw_mgmt("%s: mode %d\n", __func__, lmac->mode);

	/* FIXME: certain PHYs might need to handled differently */
	if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_XAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_RXAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_TENG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_FIFTYG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R)) {
		/* obtain the status from CGX CSRs */
		cgx_xaui_get_link(node, cgx_id, lmac_id, link);
		debug_nw_mgmt("link %d speed %d duplex %d\n", link->s.link_up,
			link->s.speed, link->s.full_duplex);
		return ret;
	}

	if (lmac->mode == CAVM_CGX_LMAC_TYPES_E_USXGMII) {
		/* FIXME : Need to obtain PHY status for USXGMII */
	}

	/* handle generic clause first */
	if (lmac->phy_config.clause == PHY_GENERIC_8023_C22) {
		cavm_get_generic_8023_c22_phy_link_state(&lmac->phy_config, link);
	} else {
		/* FIXME: handle other specific PHY cases */
		ERROR("%s no compatible string for PHY found\n", __func__);
		ret = -1;
	}
	debug_nw_mgmt("link %d speed %d duplex %d\n", link->s.link_up,
			link->s.speed, link->s.full_duplex);
	return ret;
}

void cavm_phy_reset(int node, int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_nw_mgmt("%s: %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	phy = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	/* Enable the SMI/MDIO bus */
	if (phy->mdio_bus != -1)
		smi_phy_reset(node, phy->mdio_bus);

}
