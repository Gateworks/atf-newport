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

#include "mydApiRegs.h"
#include "mydApiTypes.h"
#include "mydAPI.h"
#include "mydDiagnostics.h"
#include "mydUtils.h"
#include "mydInitialization.h"
#include "mydFwImages.h"
#include "mydHwSerdesCntl.h"

MYD_DEV marvell_6141_priv[MAX_CGX];

static MYD_STATUS myd_read_mdio(MYD_DEV_PTR pDev, MYD_U16 mdioPort,
				MYD_U16 mmd, MYD_U16 reg, MYD_U16 *value)
{
	int read;
	phy_config_t *phy = pDev->hostContext;

	read = smi_read(phy->mdio_bus, CLAUSE45, phy->addr, mmd, reg);
	*value = read;
	return MYD_OK;
}

static MYD_STATUS myd_write_mdio(MYD_DEV_PTR pDev, MYD_U16 mdioPort,
				 MYD_U16 mmd, MYD_U16 reg, MYD_U16 value)
{
	phy_config_t *phy = pDev->hostContext;

	smi_write(phy->mdio_bus, phy->addr, mmd, CLAUSE45, reg, value);
	return MYD_OK;
}

void phy_marvell_6141_probe(int cgx_id, int lmac_id)
{
	MYD_U16 x6141_sbus_master_image_size;
	MYD_U16 x6141_serdes_image_size;
	MYD_STATUS status;
	phy_config_t *phy;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	phy->priv = &marvell_6141_priv[cgx_id];

	if (((MYD_DEV_PTR)phy->priv)->devEnabled)
		return;

	x6141_sbus_master_image_size = x6141_sbus_master_image_end -
						x6141_sbus_master_image_start;
	x6141_serdes_image_size = x6141_serdes_image_end -
						x6141_serdes_image_start;

	status = mydInitDriver(myd_read_mdio, myd_write_mdio, phy->addr, NULL,
			       0,
			       x6141_sbus_master_image_start,
			       x6141_sbus_master_image_size,
			       x6141_serdes_image_start,
			       x6141_serdes_image_size,
			       phy,
			       phy->priv);
	if (status != MYD_OK) {
		ERROR("%s: %d:%d mydInitDriver() failed\n", __func__, cgx_id,
		      lmac_id);
		return;
	}

#ifdef DEBUG_ATF_MARVELL_PHY_DRIVER
	MYD_U16 serdesRevision = 0;
	MYD_U16 sbmRevision = 0;

	status = mydSerdesGetRevision(phy->priv, phy->addr, &serdesRevision,
				      &sbmRevision);
	if (status != MYD_OK) {
		ERROR("%s: %d:%d mydSerdesGetRevision() failed\n", __func__,
		      cgx_id, lmac_id);
	}
	printf("%s: %d:%d SERDES FW rev 0x%x SBUS MASTER FW rev 0x%x\n",
			 __func__, cgx_id, lmac_id, serdesRevision,
			 sbmRevision);
#endif
}

void phy_marvell_6141_config(int cgx_id, int lmac_id)
{
	phy_config_t *phy;
	cgx_lmac_config_t *lmac_cfg;
	MYD_STATUS status;
	MYD_U16 result;
	MYD_OP_MODE host_mode, line_mode;
	MYD_U16 lane;
	MYD_U32 mode_option;
	MYD_DEV_PTR myd_dev;
	PMYD_MODE_CONFIG myd_host_config;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;

	switch (lmac_cfg->mode_idx) {
	case QLM_MODE_XFI:
	case QLM_MODE_SFI:
	case QLM_MODE_10G_KR:
		switch (lmac_cfg->fec) {
		case CGX_FEC_BASE_R:
			if (lmac_cfg->mode_idx == QLM_MODE_10G_KR)
				host_mode = MYD_P10KF;
			else
				host_mode = MYD_P10LF;
			line_mode = MYD_P10KF;
			break;
		case CGX_FEC_NONE:
		default:
			if (lmac_cfg->mode_idx == QLM_MODE_10G_KR)
				host_mode = MYD_P10KN;
			else
				host_mode = MYD_P10LN;
			line_mode = MYD_P10LN;
			break;
		}
		break;

	case QLM_MODE_25GAUI_C2C:
		host_mode = MYD_P25LR; /* 25GBASE-R, RS-FEC, no AN */

		switch (lmac_cfg->fec) {
		case CGX_FEC_RS:
			line_mode = MYD_P25LR;
			break;
		case CGX_FEC_BASE_R:
			line_mode = MYD_P25LF;
			break;
		case CGX_FEC_NONE:
		default:
			line_mode = MYD_P25LN;
			break;
		}
		break;

	case QLM_MODE_25GAUI_2_C2C:
		host_mode = MYD_P25YN; /* 25GBASE-R2, no FEC, no AN */

		switch (lmac_cfg->fec) {
		case CGX_FEC_RS:
			line_mode = MYD_P25LR;
			break;
		case CGX_FEC_BASE_R:
			line_mode = MYD_P25LF;
			break;
		case CGX_FEC_NONE:
		default:
			line_mode = MYD_P25LN;
			break;
		}
		break;

	case QLM_MODE_50GAUI_2_C2C:
	case QLM_MODE_50GAUI_4_C2C:
		if (phy->mod_type == PHY_MOD_TYPE_PAM4) {
			line_mode = MYD_P50UP; /* 50GBASE-R, RS-FEC, no AN */
		} else {
			switch (lmac_cfg->fec) {
			case CGX_FEC_RS:
				line_mode = MYD_P50MR;
				break;
			case CGX_FEC_BASE_R:
				line_mode = MYD_P50MF;
				break;
			case CGX_FEC_NONE:
			default:
				line_mode = MYD_P50MN;
				break;
			}
		}

		if (lmac_cfg->mode_idx == QLM_MODE_50GAUI_2_C2C)
			host_mode = MYD_P50MR; /* 50GBASE-R2, RS-FEC, no AN */
		else
			host_mode = MYD_P50LN; /* 50GBASE-R4, no FEC, no AN */
		break;

	default:
		ERROR("%s: %d:%d QLM_MODE %d is not supported\n", __func__,
		      cgx_id, lmac_id, lmac_cfg->mode_idx);
		return;
	}

	lane = lmac_cfg->lane_to_sds & 3;
	myd_dev = phy->priv;
	myd_host_config = &myd_dev->hostConfig[0][lane];
	if (myd_host_config->opMode == MYD_P25YN && host_mode != MYD_P25YN) {
		/* undo the 25GBASE-R2 hack */
		myd_write_mdio(phy->priv, phy->addr, 4, 0xF06C, 0);
	}

	mode_option = MYD_MODE_FORCE_RECONFIG;
	status = mydSetModeSelection(phy->priv, phy->addr, lane, host_mode,
				     line_mode, mode_option,
				     &result);
	if (status == MYD_OK) {
		if (host_mode == MYD_P25YN) {
			/* Hack the 6141's P25YN mode to make its 25GBASE-R2 PCS
			 * conform to the T9x's "implementation" of 25GBASE-R2
			 * (which looks like a scaled down 50GBASE-R2 with CGX
			 * LMAC type set to FIFTYG_R and GSER speed at
			 * 12.89 Gbd).
			 * The settings below came from the 6141 design team.
			 */

			/* fix alignment markers */
			myd_write_mdio(phy->priv, phy->addr, 4, 0xF06C, 0xF000);

			/* host-side sw reset */
			myd_write_mdio(phy->priv, phy->addr,
					31, 0xF003, 0x0080);
		}
		return;
	}

	ERROR("%s: %d:%d mydSetModeSelection() failed, lane=%hu, result=%hu\n",
	      __func__, cgx_id, lmac_id, lane, result);
}

void phy_marvell_6141_get_link_status(int cgx_id, int lmac_id,
				      link_state_t *link)
{
	MYD_U16 latchedStatus, currentStatus;
	MYD_PCS_LINK_STATUS statusDetail;
	MYD_STATUS status;
	MYD_U16 lane;
	phy_config_t *phy;
	cgx_lmac_config_t *lmac_cfg;
	MYD_DEV_PTR myd_dev;
	PMYD_MODE_CONFIG myd_mode_config;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	lane = lmac_cfg->lane_to_sds & 3;
	phy = &lmac_cfg->phy_config;

	mydMemSet(&statusDetail, 0, sizeof(MYD_PCS_LINK_STATUS));
	link->u64 = 0;

	status = mydCheckPCSLinkStatus(phy->priv, phy->addr, lane,
				       &currentStatus, &latchedStatus,
				       &statusDetail);
	if (status != MYD_OK) {
		ERROR("%s: %d:%d mydCheckPCSLinkStatus failed for lane %hu.\n",
		      __func__, cgx_id, lmac_id, lane);
		return;
	}

	if (currentStatus != MYD_LINK_UP)
		return;

	link->s.link_up = 1;
	link->s.full_duplex = 1;

	myd_dev = phy->priv;
	myd_mode_config = &myd_dev->lineConfig[0][lane];
	switch (myd_mode_config->opMode) {
	case MYD_P10LN:
		link->s.speed = CGX_LINK_10G;
		link->s.fec = CGX_FEC_NONE;
		break;
	case MYD_P10KF:
		link->s.speed = CGX_LINK_10G;
		link->s.fec = CGX_FEC_BASE_R;
		break;
	case MYD_P25LN:
		link->s.speed = CGX_LINK_25G;
		link->s.fec = CGX_FEC_NONE;
		break;
	case MYD_P25LR:
		link->s.speed = CGX_LINK_25G;
		link->s.fec = CGX_FEC_RS;
		break;
	case MYD_P25LF:
		link->s.speed = CGX_LINK_25G;
		link->s.fec = CGX_FEC_BASE_R;
		break;
	case MYD_P50MN:
		link->s.speed = CGX_LINK_50G;
		link->s.fec = CGX_FEC_NONE;
		break;
	case MYD_P50MF:
		link->s.speed = CGX_LINK_50G;
		link->s.fec = CGX_FEC_BASE_R;
		break;
	case MYD_P50MR:
	case MYD_P50UP:
		link->s.speed = CGX_LINK_50G;
		link->s.fec = CGX_FEC_RS;
		break;
	default:
		ERROR("%s: %d:%d Unexpected line mode %d\n",
		      __func__, cgx_id, lmac_id,
		      myd_mode_config->speed);
		break;
	}
}

void phy_marvell_6141_supported_modes(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	phy->supported_link_modes = ((1 << CGX_MODE_10G_KR_BIT) |
			(1 << CGX_MODE_10G_C2C_BIT) |
			(1 << CGX_MODE_10G_C2M_BIT) |
			(1 << CGX_MODE_25G_C2C_BIT) |
			(1 << CGX_MODE_25G_2_C2C_BIT) |
			(1 << CGX_MODE_50G_C2C_BIT) |
			(1 << CGX_MODE_50G_4_C2C_BIT));
}

#ifdef DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS
static MYD_PRBS_SELECTOR_TYPE phy_marvell_6141_get_prbs_selector(int prbs)
{
	MYD_PRBS_SELECTOR_TYPE prbs_sel;

	switch (prbs) {
	case 7:
		prbs_sel = MYD_PRBS7;
		break;
	case 9:
		prbs_sel = MYD_PRBS9;
		break;
	case 13:
		prbs_sel = MYD_PRBS13;
		break;
	case 15:
		prbs_sel = MYD_PRBS15;
		break;
	case 23:
		prbs_sel = MYD_PRBS23;
		break;
	case 31:
		prbs_sel = MYD_PRBS31;
		break;
	default:
		WARN("Unsupported PRBS mode %d, using 7\n", prbs);
		prbs_sel = MYD_PRBS7;
		break;
	}

	return prbs_sel;
}

static int phy_marvell_6141_enable_prbs(int cgx_id, int lmac_id, int host_side,
	int prbs, int dir)
{
	MYD_STATUS status;
	phy_config_t *phy;
	MYD_U16 lane;
	cgx_lmac_config_t *lmac_cfg;
	MYD_PRBS_SELECTOR_TYPE prbs_sel;
	int enable_tx;
	int enable_rx;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	lane = lmac_cfg->lane_to_sds & 3;
	prbs_sel = phy_marvell_6141_get_prbs_selector(prbs);

	status = mydSetPRBSClearOnRead(
		phy->priv,
		phy->addr,
		MYD_HOST_SIDE,
		lane,
		1);
	if (status != MYD_OK) {
		WARN(
			"CGX%d(%d): mydSetPRBSClearOnRead() for host side failed\n",
			cgx_id, lane);
		return -1;
	}

	status = mydSetPRBSClearOnRead(
		phy->priv,
		phy->addr,
		MYD_LINE_SIDE,
		lane,
		1);
	if (status != MYD_OK) {
		WARN(
			"CGX%d(%d): mydSetPRBSClearOnRead() for line side failed\n",
			cgx_id, lane);
		return -1;
	}

	status = mydSetPRBSPattern(
		phy->priv,
		phy->addr,
		MYD_LINE_SIDE,
		lane,
		prbs_sel,
		MYD_PRBS_NONE);
	if (status != MYD_OK) {
		WARN("CGX%d(%d): mydSetPRBSPattern() for line side failed\n",
			cgx_id, lane);
		return -1;
	}

	status = mydSetPRBSPattern(
		phy->priv,
		phy->addr,
		MYD_HOST_SIDE,
		lane,
		prbs_sel,
		MYD_PRBS_NONE);
	if (status != MYD_OK) {
		WARN("CGX%d(%d): mydSetPRBSPattern() for host side failed\n",
			cgx_id, lane);
		return -1;
	}

	enable_tx = (dir == QLM_DIRECTION_TX);
	enable_rx = (dir == QLM_DIRECTION_RX);

	status = mydSetPRBSEnableTxRx(
		phy->priv,
		phy->addr,
		host_side ? MYD_HOST_SIDE : MYD_LINE_SIDE,
		lane,
		(enable_tx | enable_rx) ? MYD_ENABLE : MYD_DISABLE, /* TX */
		(enable_rx) ? MYD_ENABLE : MYD_DISABLE, /* RX */
		prbs_sel);
	if (status != MYD_OK) {
		WARN("CGX%d(%d): mydSetPRBSEnableTxRx() failed\n",
			cgx_id, lane);
		return -1;
	}

	return 0;
}

static int phy_marvell_6141_disable_prbs(int cgx_id, int lmac_id, int host_side,
	int prbs)
{
	MYD_STATUS status;
	phy_config_t *phy;
	cgx_lmac_config_t *lmac_cfg;
	MYD_U16 lane;
	MYD_PRBS_SELECTOR_TYPE prbs_sel;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	lane = lmac_cfg->lane_to_sds & 3;
	prbs_sel = phy_marvell_6141_get_prbs_selector(prbs);

	status = mydSetPRBSEnableTxRx(
		phy->priv,
		phy->addr,
		host_side ? MYD_HOST_SIDE : MYD_LINE_SIDE,
		lane,
		MYD_DISABLE, /* TX */
		MYD_DISABLE, /* RX */
		prbs_sel);
	if (status != MYD_OK) {
		WARN("CGX%d(%d): mydSetPRBSEnableTxRx() failed\n",
			cgx_id, lane);
		return -1;
	}

	mydLaneSoftReset(
		phy->priv,
		phy->addr,
		host_side ? MYD_HOST_SIDE : MYD_LINE_SIDE,
		lane,
		10);

	return 0;
}

static uint64_t phy_marvell_6141_get_prbs_errors(int cgx_id, int lmac_id,
	int host_side, int clear, int prbs)
{
	MYD_STATUS status;
	phy_config_t *phy;
	cgx_lmac_config_t *lmac_cfg;
	MYD_U16 lane;
	MYD_PRBS_SELECTOR_TYPE prbs_sel;
	MYD_BOOL prbsLocked;
	MYD_U64 txBitCount, rxBitCount, rxBitErrorCount;
	uint64_t errors;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	lane = lmac_cfg->lane_to_sds & 3;
	prbs_sel = phy_marvell_6141_get_prbs_selector(prbs);

	status = mydGetPRBSLocked(
		phy->priv,
		phy->addr,
		host_side ? MYD_HOST_SIDE : MYD_LINE_SIDE,
		lane,
		&prbsLocked);
	if (status != MYD_OK) {
		WARN("CGX%d(%d): mydGetPRBSLocked() failed\n", cgx_id, lane);
		return -1;
	}
	if (!prbsLocked) {
		WARN("CGX%d(%d): did not get PRBS lock\n", cgx_id, lane);
		return -1;
	}

	status = mydGetPRBSCounts(
		phy->priv,
		phy->addr,
		host_side ? MYD_HOST_SIDE : MYD_LINE_SIDE,
		lane,
		prbs_sel,
		&txBitCount, &rxBitCount, &rxBitErrorCount);
	if (status != MYD_OK) {
		WARN("CGX%d(%d): mydGetPRBSCounts() failed\n", cgx_id, lane);
		return -1;
	}

	if (host_side) {
		errors = lmac_cfg->prbs_errors_host + rxBitErrorCount;
		lmac_cfg->prbs_errors_host = (clear) ? 0 : errors;
		return errors;
	}

	errors = lmac_cfg->prbs_errors_line + rxBitErrorCount;
	lmac_cfg->prbs_errors_line = (clear) ? 0 : errors;
	return errors;
}
#endif /* DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS */

phy_drv_t marvell_6141_drv = {
		.drv_name		= "MARVELL-88X6141",
		.drv_type		= PHY_MARVELL_6141,
		.flags			= PHY_FLAG_SUPPORTS_CHANGING_MOD_TYPE,
		.probe			= phy_marvell_6141_probe,
		.config			= phy_marvell_6141_config,
		.reset			= phy_generic_reset,
		.get_link_status	= phy_marvell_6141_get_link_status,
		.set_supported_modes	= phy_marvell_6141_supported_modes,
		.shutdown		= phy_generic_shutdown,
#ifdef DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS
		.enable_prbs		= phy_marvell_6141_enable_prbs,
		.disable_prbs		= phy_marvell_6141_disable_prbs,
		.get_prbs_errors	= phy_marvell_6141_get_prbs_errors,
#endif /* DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS */
	};

phy_drv_t *marvell_6141_check_type(int type)
{
	if (marvell_6141_drv.drv_type == type)
		return &marvell_6141_drv;
	return NULL;
}
