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

typedef struct {
	MCD_DEV mcddev;
	struct {
		int use_an;
		int completed_an;
		int cmain_host;
		int cpre_host;
		int cpost_host;
		int cmain_line;
		int cpre_line;
		int cpost_line;
		int tx_host_lane;
		int tx_line_lane;
		int rx_host_lane;
		int rx_line_lane;
	} port[8];
} phy_mcd_priv_t;

phy_mcd_priv_t marvell_5123_priv;

static MCD_STATUS mcd_read_mdio(MCD_DEV_PTR pDev, MCD_U16 mdioPort,
	MCD_U16 mmd, MCD_U16 reg, MCD_U16 *value)
{
	int read;
	phy_config_t *phy = pDev->hostContext;

	read = smi_read(phy->mdio_bus, CLAUSE45, phy->addr, mmd, reg);
	*value = read;
	return MCD_OK;
}

static MCD_STATUS mcd_write_mdio(MCD_DEV_PTR pDev, MCD_U16 mdioPort,
	MCD_U16 mmd, MCD_U16 reg, MCD_U16 value)
{
	phy_config_t *phy = pDev->hostContext;

	smi_write(phy->mdio_bus, phy->addr, mmd, CLAUSE45, reg, value);
	return MCD_OK;
}

/* One time initialization for the PHY if required */
void phy_marvell_5123_probe(int cgx_id, int lmac_id)
{
	static int init;
	MCD_STATUS status;
	MCD_U16 serdesRevision = 0;
	MCD_U16 sbmRevision = 0;
	phy_config_t *phy, *phy1 = NULL;

	if (init)
		return;

	printf("%s: Initializing Marvell 88x5123 PHY...\n", __func__);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	for (int i = cgx_id + 1; i < MAX_CGX; i++) {
		phy1 = &plat_octeontx_bcfg->cgx_cfg[i].lmac_cfg[lmac_id].phy_config;
		if (phy1->type == PHY_MARVELL_5123)
			break;
	}

	phy->priv = &marvell_5123_priv;
	status = mcdInitDriver(mcd_read_mdio, mcd_write_mdio, phy->addr,
				(const MCD_U8 *)mcdServiceCpuCm3BvFw,
				sizeof(mcdServiceCpuCm3BvFw),
				(const MCD_U16 *)mcd_sbusMaster01x101A_0001Data,
				AVAGO_SBUS_MASTER_FW_IMAGE_SIZE,
				(const MCD_U16 *)mcd_serdes0x2464_0245Swap,
				AVAGO_SERDES_FW_SWAP_IMAGE_SIZE,
				(const MCD_U16 *)mcd_serdes0x2464_0245Data,
				AVAGO_SERDES_FW_IMAGE_SIZE,
				phy, &marvell_5123_priv.mcddev);
	if (status != MCD_OK) {
		ERROR("%s: %d:%d MARVELL 5123 PHY driver Initialization\t"
			"failed, status 0x%x\n",
			 __func__, cgx_id, lmac_id, status);
	}

	/* PHY needs to be initialized only once for both the slices */
	init = 1;

	status = mcdSerdesGetRevision(phy->priv, &serdesRevision, &sbmRevision);
	if (status != MCD_OK) {
		ERROR("%s(): failed %d\n", __func__, status);
		return;
	}
	printf("%s: SERDES FW revision 0x%x BUS MASTER FW revision 0x%x\n",
				__func__, serdesRevision, sbmRevision);

	/* Remap serdes lane if lanes are swapped. Swapped
	 * lane info is obtained from DTS for each board
	 */
	for (int i = 0; i < 4; i++) {
		marvell_5123_priv.port[i].tx_host_lane = (phy->host_order >> (4 * i)) & 0xF;

		marvell_5123_priv.port[i].rx_host_lane = marvell_5123_priv.port[i].tx_host_lane;

		marvell_5123_priv.port[i].tx_line_lane = (phy->line_order >> (4 * i)) & 0xF;

		marvell_5123_priv.port[i].rx_line_lane = marvell_5123_priv.port[i].tx_line_lane;

		if (phy1 == NULL)
			continue;

		marvell_5123_priv.port[i + 4].tx_host_lane = (phy1->host_order >> (4 * i)) & 0xF;

		marvell_5123_priv.port[i + 4].rx_host_lane = marvell_5123_priv.port[i + 4].tx_host_lane;

		marvell_5123_priv.port[i + 4].tx_line_lane = (phy1->line_order >> (4 * i)) & 0xF;

		marvell_5123_priv.port[i + 4].rx_line_lane = marvell_5123_priv.port[i + 4].tx_line_lane;
	}

	/* Program lane order */
	MCD_SERDES_TXRX_LANE_REMAP remap[8][2] = {
		/* Line side  - Slice 0, Slice 1 */
		{ {marvell_5123_priv.port[0].tx_line_lane, marvell_5123_priv.port[0].rx_line_lane},
			{marvell_5123_priv.port[4].tx_line_lane, marvell_5123_priv.port[4].rx_line_lane} },
		{ {marvell_5123_priv.port[1].tx_line_lane, marvell_5123_priv.port[1].rx_line_lane},
			{marvell_5123_priv.port[5].tx_line_lane, marvell_5123_priv.port[5].rx_line_lane} },
		{ {marvell_5123_priv.port[2].tx_line_lane, marvell_5123_priv.port[2].rx_line_lane},
			{marvell_5123_priv.port[6].tx_line_lane, marvell_5123_priv.port[6].rx_line_lane} },
		{ {marvell_5123_priv.port[3].tx_line_lane, marvell_5123_priv.port[3].rx_line_lane},
			{marvell_5123_priv.port[7].tx_line_lane, marvell_5123_priv.port[7].rx_line_lane} },
		/* Host side, unused. Swapping done in CGX */
		{ {0, 0}, {0, 0} },
		{ {1, 1}, {1, 1} },
		{ {2, 2}, {2, 2} },
		{ {3, 3}, {3, 3} }
	};

	/* Call the remapping API separately for both the slices */
	status = mcdSetLaneRemapping(&marvell_5123_priv.mcddev, MCD_LINE_SIDE, 0, remap);
	if (status != MCD_OK) {
		ERROR("%s: mcdSetLaneRemapping() failed for slice 0\n", __func__);
		return;
	}
	status = mcdSetLaneRemapping(&marvell_5123_priv.mcddev, MCD_LINE_SIDE, 1, remap);
	if (status != MCD_OK) {
		ERROR("%s: mcdSetLaneRemapping() failed for slice 1\n", __func__);
		return;
	}
}

/* To set the operating mode of the PHY if required */
void phy_marvell_5123_config(int cgx_id, int lmac_id)
{
	int port_num;
	cgx_lmac_config_t *lmac_cfg;
	phy_config_t *phy;
	MCD_U32 modesVector = MCD_AN_10GBase_KR;
	MCD_OP_MODE op_mode = MCD_MODE_P10L;
	MCD_FEC_TYPE fec_type = MCD_NO_FEC;
	const char *mode_str = "10GBASE-KR";
	MCD_MODE_CONFIG_PARAM config;
	MCD_CONFIG_SERDES_AP_PARAM ap_config;
	MCD_STATUS status;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	memset(&config, 0, sizeof(MCD_MODE_CONFIG_PARAM));
	memset(&ap_config, 0, sizeof(MCD_CONFIG_SERDES_AP_PARAM));

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port_num = phy->port;

	debug_phy_driver("%s: port %d AN %d FEC %d\n", __func__, port_num,
			!lmac_cfg->autoneg_dis, lmac_cfg->fec);

	if (!lmac_cfg->autoneg_dis)
		marvell_5123_priv.port[port_num].use_an = 1;

	if (lmac_cfg->fec == CGX_FEC_RS)
		fec_type = MCD_RS_FEC_HOST;
	else if (lmac_cfg->fec == CGX_FEC_BASE_R)
		fec_type = MCD_FC_FEC_HOST;

	switch (lmac_cfg->mode_idx) {
	case QLM_MODE_1G_X:
		op_mode = MCD_MODE_P1;
		mode_str = "1000 BASE-X";
	break;
	case QLM_MODE_XLAUI:
	case QLM_MODE_XLAUI_C2M:
		op_mode = MCD_MODE_P40L;
		mode_str = "40G-BASE-R4";
	break;
	case QLM_MODE_40G_KR4:
		op_mode = MCD_MODE_P40L;
		modesVector = MCD_AN_40GBASE_KR4;
		mode_str = "40G-BASE-KR4";
	break;
	case QLM_MODE_XFI:
	case QLM_MODE_SFI:
		op_mode = MCD_MODE_P10L;
		mode_str = "10G-BASE-R";
	break;
	case QLM_MODE_10G_KR:
		op_mode = MCD_MODE_P10L;
		modesVector = MCD_AN_10GBase_KR;
		mode_str = "10G-BASE-KR";
	break;
	case QLM_MODE_20GAUI_C2C:
		mode_str = "20G-BASE-R";
		op_mode = MCD_MODE_P20S;
	break;
	case QLM_MODE_25GAUI_C2C:
	case QLM_MODE_25GAUI_C2M:
		op_mode = MCD_MODE_P25S;
		mode_str = "25G-BASE-R";
	break;
	case QLM_MODE_25G_KR:
		op_mode = MCD_MODE_P25S;
		mode_str = "25G-BASE-KR";
		modesVector = MCD_AN_25GBase_KR1S;
	break;
	case QLM_MODE_40GAUI_2_C2C:
		op_mode = MCD_MODE_P40R2S;
		mode_str = "40G-BASE-R";
	break;
	case QLM_MODE_50GAUI_2_C2C:
	case QLM_MODE_50GAUI_2_C2M:
		/* FIXME : to select the OP MODE for consortium/
		 * non-standard
		 */
		op_mode = MCD_MODE_P50R2S;
		mode_str = "50G-BASE-R2";
	break;
	case QLM_MODE_50G_KR2:
		op_mode = MCD_MODE_P50R2S;
		mode_str = "50G-BASE-KR2";
		modesVector = MCD_AN_50GBase_KR2_CONSORTIUM;
	break;
	case QLM_MODE_CAUI_4_C2C:
	case QLM_MODE_CAUI_4_C2M:
		op_mode = MCD_MODE_P100S;
		mode_str = "100G-BASE-R4";
	break;
	case QLM_MODE_100G_KR4:
		modesVector = MCD_AN_100GBASE_KR4;
		op_mode = MCD_MODE_P100S;
		mode_str = "100G-BASE-KR4";
	break;
	default:
		printf("%s: %d:%d mode %d not supported by 5123\n",
			__func__, cgx_id, lmac_id, lmac_cfg->mode_idx);
		return;
	break;
	}
	printf("%s: port %d op_mode %d fec %d\n", __func__, port_num,
						op_mode, fec_type);

	if (marvell_5123_priv.port[port_num].use_an) {
		if (mode_str != NULL)
			debug_phy_driver("%s: port %d setting AP modestr %s\n",
					__func__, port_num, mode_str);

		status = mcdSetAPModeSelection(&marvell_5123_priv.mcddev,
						port_num,
						port_num, /* lane used for AN*/
						modesVector,
						MCD_TRUE, /* fcPause */
						MCD_TRUE, /* fcAsmDir */
						fec_type, /* Support FEC */
						fec_type, /* Request FEC */
						/* AN nonce checking disabled */
						MCD_TRUE,
						&ap_config,
						MCD_TRUE); /* Enable AN */
		if (status != MCD_OK) {
			debug_phy_driver("%s: port %d mcdSetAPModeSelection\t"
						"failed %d\n",
						__func__, port_num, status);
			return;
		}
	} else {
		debug_phy_driver("%s: port %d setting non AP\n", __func__,
						port_num);

		status = mcdSetModeSelectionExt(&marvell_5123_priv.mcddev,
				port_num,
				op_mode,
				MCD_FALSE,	/* autoNegAdvEnable */
				fec_type,	/* Request FEC */
				&config);
		if (status != MCD_OK) {
			printf("%s: port%d mcdSetModeSelectionExt() fail %d\n",
				__func__, port_num, status);
			return;
		}
	}
	if (phy->forceconfig) {
		/* SW reset the port */
		mcdPortReset(&marvell_5123_priv.mcddev,
				port_num,
				MCD_BOTH_SIDE,
				MCD_SOFT_RESET,
				100);
		if (status != MCD_OK) {
			printf("%s: port%d mcdPortReset() fail %d\n",
				__func__, port_num, status);
			return;
		}
	}
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
	int port_num;
	MCD_MODE_CONFIG_PARAM config;
	MCD_U16 speed;
	MCD_U16 currentStatus = 0;
	MCD_U16 latchedStatus = 0;
	MCD_STATUS status;
	cgx_lmac_config_t *lmac_cfg;
	phy_config_t *phy;
	DETAILED_STATUS_TYPE statusDetail;

	link->u64 = 0;

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port_num = phy->port;
	if (!lmac_cfg->autoneg_dis) {
		if (marvell_5123_priv.port[port_num].completed_an)
			return;
		memset(&config, 0, sizeof(config));
		config.ctleBiasParams.host = MCD_CTLE_BIAS_NORMAL;
		config.noPpmMode = MCD_NO_PPM_RX_SQUELCH_MODE;

		status = mcdAutoNegCheckCompleteExt(&marvell_5123_priv.mcddev,
					port_num, MCD_LINE_SIDE, TRUE,
					&config, &speed);
		if (status != MCD_OK) {
			printf("%s: port %d mcdAutoNegCheckCompleteExt()\t"
				"failed", __func__, port_num);
			return;
		}

		debug_phy_driver("%s: %d returned speed 0x%x\n", __func__,
							port_num, speed);
		if (speed)
			marvell_5123_priv.port[port_num].completed_an = 1;

		link->s.link_up = 1;
		link->s.full_duplex = 1;

		switch (speed)	{
		case MCD_NEG_1000KX:
			link->s.speed = CGX_LINK_1G;
		break;
		case MCD_NEG_100CR10:
		case MCD_NEG_100KP4:
		case MCD_NEG_100KR4:
		case MCD_NEG_100CR4:
			link->s.speed = CGX_LINK_100G;
		break;
		case MCD_NEG_10KR:
			link->s.speed = CGX_LINK_10G;
		break;
		case MCD_NEG_40KR4:
		case MCD_NEG_40CR4:
			link->s.speed = CGX_LINK_40G;
		break;
		case MCD_NEG_25KR_CONSORTIUM:
		case MCD_NEG_25CR_CONSORTIUM:
		case MCD_NEG_25KRCS:
		case MCD_NEG_25KCR:
			link->s.speed = CGX_LINK_25G;
		break;
		case MCD_NEG_50KR_CONSORTIUM:
		case MCD_NEG_50CR_CONSORTIUM:
			link->s.speed = CGX_LINK_50G;
		break;
		/* FIXME for 20G/80G modes */
		case MCD_NEG_NONE:
		default:
			link->s.speed = CGX_LINK_NONE;
			link->s.link_up = 0;
			link->s.full_duplex = 0;
		break;
		}
	} else {
		status =  mcdCheckLinkStatus(&marvell_5123_priv.mcddev,
				port_num, &currentStatus, &latchedStatus,
				&statusDetail);
		if (status != MCD_OK)
			WARN("%s: port %d mcdCheckLinkStatus() failed",
					__func__, port_num);
		debug_phy_driver("%s: port %d PHY link is %d\n", __func__,
					port_num, currentStatus);

		link->s.link_up = (currentStatus == MCD_LINK_UP);
		link->s.full_duplex = 1;

		/* In case of FIXED mode, just return the speed based on
		 * mode configured
		 */
		switch (lmac_cfg->mode_idx) {
		case QLM_MODE_1G_X:
			link->s.speed = CGX_LINK_1G;
		break;
		case QLM_MODE_XFI:
		case QLM_MODE_SFI:
			link->s.speed = CGX_LINK_10G;
		break;
		case QLM_MODE_20GAUI_C2C:
			link->s.speed = CGX_LINK_20G;
		break;
		case QLM_MODE_25GAUI_C2C:
		case QLM_MODE_25GAUI_C2M:
			link->s.speed = CGX_LINK_25G;
		break;
		case QLM_MODE_XLAUI:
		case QLM_MODE_XLAUI_C2M:
			link->s.speed = CGX_LINK_40G;
		break;
		case QLM_MODE_40GAUI_2_C2C:
			link->s.speed = CGX_LINK_40G;
		break;
		case QLM_MODE_50GAUI_2_C2C:
		case QLM_MODE_50GAUI_2_C2M:
			link->s.speed = CGX_LINK_50G;
		break;
		case QLM_MODE_80GAUI_4_C2C:
			link->s.speed = CGX_LINK_80G;
		break;
		case QLM_MODE_CAUI_4_C2C:
		case QLM_MODE_CAUI_4_C2M:
			link->s.speed = CGX_LINK_100G;
		break;
		/* FIXME for other modes */
		default:
			link->s.speed = CGX_LINK_NONE;
			link->s.link_up = 0;
			link->s.full_duplex = 0;
		break;
		}
	}
}

void phy_marvell_5123_supported_modes(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	phy->supported_link_modes = ((1 << CGX_MODE_1000_BASEX_BIT) |
			(1 << CGX_MODE_10G_C2C_BIT) |
			(1 << CGX_MODE_10G_C2M_BIT) |
			(1 << CGX_MODE_20G_C2C_BIT) |
			(1 << CGX_MODE_25G_C2C_BIT) |
			(1 << CGX_MODE_25G_C2M_BIT) |
			(1 << CGX_MODE_40G_C2C_BIT) |
			(1 << CGX_MODE_40G_C2M_BIT) |
			(1 << CGX_MODE_50G_C2C_BIT) |
			(1 << CGX_MODE_50G_C2M_BIT) |
			(1 << CGX_MODE_40GAUI_C2C_BIT) |
			(1 << CGX_MODE_80GAUI_C2C_BIT) |
			(1 << CGX_MODE_100G_C2C_BIT) |
			(1 << CGX_MODE_100G_C2M_BIT));
}

#ifdef DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS
static MCD_PRBS_LINE_SELECTOR_TYPE phy_marvell_5123_get_prbs_line_selector(
	int prbs)
{
	MCD_PRBS_LINE_SELECTOR_TYPE prbs_sel;

	switch (prbs) {
	case 7:
		prbs_sel = MCD_LINE_PRBS7;
		break;
	case 9:
		prbs_sel = MCD_LINE_PRBS9;
		break;
	case 13:
		prbs_sel = MCD_LINE_PRBS11;
		break;
	case 15:
		prbs_sel = MCD_LINE_PRBS15;
		break;
	case 23:
		prbs_sel = MCD_LINE_PRBS23;
		break;
	case 31:
		prbs_sel = MCD_LINE_PRBS31;
		break;
	default:
		WARN("Unsupported PRBS mode %d, using 7\n", prbs);
		prbs_sel = MCD_LINE_PRBS7;
		break;
	}

	return prbs_sel;
}

static MCD_PRBS_HOST_SELECTOR_TYPE phy_marvell_5123_get_prbs_host_selector(
	int prbs)
{
	MCD_PRBS_HOST_SELECTOR_TYPE prbs_sel;

	switch (prbs) {
	case 7:
		prbs_sel = MCD_HOST_PRBS7;
		break;
	case 9:
		prbs_sel = MCD_HOST_PRBS9;
		break;
	case 13:
		prbs_sel = MCD_HOST_PRBS11;
		break;
	case 15:
		prbs_sel = MCD_HOST_PRBS15;
		break;
	case 23:
		prbs_sel = MCD_HOST_PRBS23;
		break;
	case 31:
		prbs_sel = MCD_HOST_PRBS31;
		break;
	default:
		WARN("Unsupported PRBS mode %d, using 7\n", prbs);
		prbs_sel = MCD_HOST_PRBS7;
		break;
	}

	return prbs_sel;
}

static int phy_marvell_5123_enable_prbs(int cgx_id, int lmac_id, int host_side,
	int prbs, int dir)
{
	MCD_STATUS status;
	phy_config_t *phy;
	int port_num;
	cgx_lmac_config_t *lmac_cfg;
	MCD_PRBS_LINE_SELECTOR_TYPE linepat;
	MCD_PRBS_HOST_SELECTOR_TYPE hostpat;
	int enable_tx;
	int enable_rx;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port_num = phy->port;
	linepat = phy_marvell_5123_get_prbs_line_selector(prbs);
	hostpat = phy_marvell_5123_get_prbs_host_selector(prbs);

	status = mcdSetLineSidePRBSPattern(
		&marvell_5123_priv.mcddev,
		port_num,
		0, /* lane */
		linepat,
		MCD_LINE_PRBS_NONE);
	if (status != MCD_OK) {
		WARN("CGX%d(%d): mcdSetLineSidePRBSPattern() failed\n",
			cgx_id, port_num);
		return -1;
	}
	status = mcdSetHostSidePRBSPattern(
		&marvell_5123_priv.mcddev,
		port_num,
		0, /* lane */
		hostpat);
	if (status != MCD_OK) {
		WARN("CGX%d(%d): mcdSetHostSidePRBSPattern() failed\n",
			cgx_id, port_num);
		return -1;
	}

	enable_tx = (dir == QLM_DIRECTION_TX);
	enable_rx = (dir == QLM_DIRECTION_RX);

	status = mcdSetPRBSEnableTxRx(
		&marvell_5123_priv.mcddev,
		port_num,
		(host_side) ? MCD_HOST_SIDE : MCD_LINE_SIDE,
		0, /* lane */
		(enable_tx | enable_rx) ? MCD_ENABLE : MCD_DISABLE, /* TX */
		(enable_rx) ? MCD_ENABLE : MCD_DISABLE); /* RX */
	if (status != MCD_OK) {
		WARN("CGX%d(%d): mcdSetPRBSEnableTxRx() failed\n",
			cgx_id, port_num);
		return -1;
	}

	return 0;
}

static int phy_marvell_5123_disable_prbs(int cgx_id, int lmac_id, int host_side,
	int prbs)
{
	MCD_STATUS status;
	phy_config_t *phy;
	int port_num;
	cgx_lmac_config_t *lmac_cfg;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port_num = phy->port;

	status = mcdSetPRBSEnableTxRx(
		&marvell_5123_priv.mcddev,
		port_num,
		(host_side) ? MCD_HOST_SIDE : MCD_LINE_SIDE,
		0, /* lane */
		MCD_DISABLE, /* TX */
		MCD_DISABLE); /* RX */
	if (status != MCD_OK) {
		WARN("CGX%d(%d): mcdSetPRBSEnableTxRx() failed\n",
			cgx_id, port_num);
		return -1;
	}
	return 0;
}

static uint64_t phy_marvell_5123_get_prbs_errors(int cgx_id, int lmac_id,
	int host_side, int clear, int prbs)
{
	MCD_STATUS status;
	phy_config_t *phy;
	int port_num;
	cgx_lmac_config_t *lmac_cfg;
	MCD_U64 txBitCount;
	MCD_U64 rxBitCount;
	MCD_U64 rxBitErrorCount;
	uint64_t errors;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port_num = phy->port;

	status = mcdGetPRBSCounts(
		&marvell_5123_priv.mcddev,
		port_num,
		(host_side) ? MCD_HOST_SIDE : MCD_LINE_SIDE,
		0, /* lane */
		&txBitCount,
		&rxBitCount,
		&rxBitErrorCount);
	if (status != MCD_OK) {
		WARN("CGX%d(%d): mcdGetPRBSCounts() failed\n",
			cgx_id, port_num);
		return -1;
	}

	if (host_side) {
		/*
		 * 5123 API seems to return 0xffff when there isn't a lock.
		 * Documentation is useless
		 */
		if (rxBitErrorCount == 0xffff) {
			lmac_cfg->prbs_errors_host = 0;
			return -1;
		}
		errors = lmac_cfg->prbs_errors_host + rxBitErrorCount;
		lmac_cfg->prbs_errors_host = (clear) ? 0 : errors;
		return errors;
	}

	/*
	 * 5123 API seems to return 0xffff when there isn't a lock.
	 * Documentation is useless
	 */
	if (rxBitErrorCount == 0xffff) {
		lmac_cfg->prbs_errors_line = 0;
		return -1;
	}
	errors = lmac_cfg->prbs_errors_line + rxBitErrorCount;
	lmac_cfg->prbs_errors_line = (clear) ? 0 : errors;
	return errors;
}
#endif /* DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS */

phy_drv_t marvell_5123_drv = {
		.drv_name		= "MARVELL-88X5123",
		.drv_type		= PHY_MARVELL_5123,
		.flags			= 0,
		.probe			= phy_marvell_5123_probe,
		.config			= phy_marvell_5123_config,
		.set_an			= phy_marvell_5123_set_an,
		.reset			= phy_generic_reset,
		.get_link_status	= phy_marvell_5123_get_link_status,
		.set_supported_modes	= phy_marvell_5123_supported_modes,
		.shutdown		= phy_generic_shutdown,
#ifdef DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS
		.enable_prbs		= phy_marvell_5123_enable_prbs,
		.disable_prbs		= phy_marvell_5123_disable_prbs,
		.get_prbs_errors	= phy_marvell_5123_get_prbs_errors,
#endif /* DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS */
	};

phy_drv_t *marvell_5123_check_type(int type)
{
	if (marvell_5123_drv.drv_type == type)
		return &marvell_5123_drv;
	return NULL;
}
