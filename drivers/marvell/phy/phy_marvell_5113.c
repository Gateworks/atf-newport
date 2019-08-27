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
#include <string.h>

#include "mxdApiRegs.h"
#include "mxdApiTypes.h"
#include "mxdAPI.h"
#include "mxdHwCntl.h"
#include "mxdUtils.h"
#include "mxdFwDownload.h"
#include "mxdInitialization.h"
#include "mxdHwSerdesCntl.h"
#include "mxdAPIInternal.h"

typedef struct {
	MXD_DEV mxddev;
	struct {
		int use_an;
		int completed_an;
		int cmain_host;
		int cpre_host;
		int cpost_host;
		int cmain_line;
		int cpre_line;
		int cpost_line;
		int use_20G;
	} port[4];
} phy_mxd_priv_t;

/* Allow multiple instances of PHY driver to run on different QLMs */
phy_mxd_priv_t marvell_5113_priv[MAX_CGX];

static MXD_STATUS mxd_read_mdio(MXD_DEV_PTR pDev, MXD_U16 mdioPort,
	MXD_U16 mmd, MXD_U16 reg, MXD_U16 *value)
{
	int read;
	phy_config_t *phy = pDev->hostContext;

	read = smi_read(phy->mdio_bus, CLAUSE45, phy->addr, mmd, reg);
	*value = read;
	return MXD_OK;
}

static MXD_STATUS mxd_write_mdio(MXD_DEV_PTR pDev, MXD_U16 mdioPort,
	MXD_U16 mmd, MXD_U16 reg, MXD_U16 value)
{
	phy_config_t *phy = pDev->hostContext;

	smi_write(phy->mdio_bus, phy->addr, mmd, CLAUSE45, reg, value);
	return MXD_OK;
}

/* One time initialization for the PHY if required */
void phy_marvell_5113_probe(int cgx_id, int lmac_id)
{
	MXD_STATUS status;
	phy_config_t *phy;
	cgx_lmac_config_t *lmac;

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	debug_phy_driver("%s: %d:%d addr 0x%x\n", __func__, cgx_id,
						lmac_id, phy->addr);
	phy->priv = (void *)&marvell_5113_priv[cgx_id];

	status = mxdInitDriver(mxd_read_mdio, mxd_write_mdio, phy->addr,
				NULL, 0,
				NULL, 0,
				NULL, 0,
				phy, &marvell_5113_priv[cgx_id].mxddev);
	if (status != MXD_OK) {
		ERROR("%s PHY driver init failed 0x%lx\n", __func__, status);
		return;
	}

	/* If PHY programming is successful, make the PHY initialized
	 * on other LMACs as well
	 */
	for (int i = 0; i < MAX_LMAC_PER_CGX; i++) {
		lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[i];
		lmac->phy_config.init = 1;
	}
	printf("%s: cgx%d 5113 PHY init successfully\n", __func__,
						cgx_id);
}

/* To set the operating mode of the PHY if required */
void phy_marvell_5113_config(int cgx_id, int lmac_id)
{
	int port;
	cgx_lmac_config_t *lmac_cfg;
	phy_config_t *phy;
	int host_mode = MXD_P10LN;
	int line_mode = MXD_P10LN;
	const char *mode_str = "10G-BASE-R";
	MXD_U16 result = 0;
	MXD_BOOL forceReConfig = MXD_FALSE;
	MXD_STATUS status;
	MXD_U16 swReset = 1;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port = phy->port;

	debug_phy_driver("%s: port %d AN %d QLM mode %d\n", __func__, port,
			!lmac_cfg->autoneg_dis, lmac_cfg->mode_idx);

	/* If previously 20G clock was configured and current mode
	 * is not 20G, Overwrite the clock modified to support 20G
	 * with default value
	 */
	if ((lmac_cfg->mode_idx != QLM_MODE_20GAUI_C2C) &&
			marvell_5113_priv[cgx_id].port[port].use_20G) {
		debug_phy_driver("%s: Prev mode was 20G, change the clock to default\n",
						__func__);
		mxdResetLaneBaudRate(&marvell_5113_priv[cgx_id].mxddev,
				phy->addr, MXD_HOST_SIDE, port);
		mxdResetLaneBaudRate(&marvell_5113_priv[cgx_id].mxddev,
				phy->addr, MXD_LINE_SIDE, port);
		status = mxdLaneSoftReset(&marvell_5113_priv[cgx_id].mxddev,
				phy->addr, MXD_HOST_SIDE, port, 1000);
		status = mxdLaneSoftReset(&marvell_5113_priv[cgx_id].mxddev,
				phy->addr, MXD_LINE_SIDE, port, 1000);
	}
	/* Disable AN/20G flags for all and enable it only
	 * for appropriate modes
	 */
	marvell_5113_priv[cgx_id].port[port].use_an = 0;
	marvell_5113_priv[cgx_id].port[port].use_20G = 0;
	marvell_5113_priv[cgx_id].mxddev.use20G = 0;
	marvell_5113_priv[cgx_id].port[port].completed_an = 0;

	switch (lmac_cfg->mode_idx) {
	case QLM_MODE_SGMII:
		host_mode = MXD_P1S;
		line_mode = MXD_P1P;
		mode_str = "SGMII";
		marvell_5113_priv[cgx_id].port[port].use_an = 1;
	break;
	case QLM_MODE_1G_X:
		host_mode = line_mode = MXD_P1X;
		mode_str = "1G_X";
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
	break;
	case QLM_MODE_XLAUI:
	case QLM_MODE_XLAUI_C2M:
		if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "40G-BASE-R4-FEC";
			host_mode = line_mode = MXD_P40LF;
		} else {
			mode_str = "40G-BASE-R4";
			host_mode = line_mode = MXD_P40LN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
	break;
	case QLM_MODE_40G_KR4:
		if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "40G-BASE-KR4-FEC";
			host_mode = line_mode = MXD_P40KF;
		} else {
			mode_str = "40G-BASE-KR4";
			host_mode = line_mode = MXD_P40KN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 1;
	break;
	case QLM_MODE_XFI:
	case QLM_MODE_SFI:
		if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "10G-BASE-R-FEC";
			host_mode = line_mode = MXD_P10LF;
		} else {
			mode_str = "10G-BASE-R";
			host_mode = line_mode = MXD_P10LN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
	break;
	case QLM_MODE_10G_KR:
		if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "10G-BASE-KR-FEC";
			host_mode = line_mode = MXD_P10KF;
		} else {
			mode_str = "10G-BASE-KR";
			host_mode = line_mode = MXD_P10KN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 1;
	break;
	case QLM_MODE_20GAUI_C2C:
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "20G-BASE-R-RSFEC";
			host_mode = line_mode = MXD_P25LR;
		} else if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "20G-BASE-R-FEC";
			host_mode = line_mode = MXD_P25LF;
		} else {
			mode_str = "20G-BASE-R";
			host_mode = line_mode = MXD_P25LN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
		marvell_5113_priv[cgx_id].mxddev.use20G = 1;
		marvell_5113_priv[cgx_id].port[port].use_20G = 1;
	break;
	case QLM_MODE_25GAUI_C2C:
	case QLM_MODE_25GAUI_C2M:
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "25G-BASE-R-RSFEC";
			host_mode = line_mode = MXD_P25LR;
		} else if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "25G-BASE-R-FEC";
			host_mode = line_mode = MXD_P25LF;
		} else {
			mode_str = "25G-BASE-R";
			host_mode = line_mode = MXD_P25LN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
	break;
	case QLM_MODE_25G_KR:
	/* FIXME for case QLM_MODE_25G_CR */
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "25G-BASE-KR-RSFEC";
			host_mode = line_mode = MXD_P25KR;
		} else if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "25G-BASE-KR-FEC";
			host_mode = line_mode = MXD_P25KF;
		} else {
			mode_str = "25G-BASE-KR";
			host_mode = line_mode = MXD_P25KN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 1;
	break;
	case QLM_MODE_40GAUI_2_C2C:
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "40G-BASE-R-RSFEC";
			host_mode = line_mode = MXD_P50MR;
		} else if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "40G-BASE-R-FEC";
			host_mode = line_mode = MXD_P50LF;
		} else {
			mode_str = "40G-BASE-R";
			host_mode = line_mode = MXD_P50LN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
		marvell_5113_priv[cgx_id].mxddev.use20G = 1;
		marvell_5113_priv[cgx_id].port[port].use_20G = 1;
	break;
	case QLM_MODE_50GAUI_2_C2C:
	case QLM_MODE_50GAUI_2_C2M:
		/* FIXME : to select the OP MODE for consortium/
		 * non-standard
		 */
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "50-BASE-R2-RSFEC";
			host_mode = line_mode = MXD_P50MR;
		} else if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "50G-BASE-R2-FEC";
			host_mode = line_mode = MXD_P50LF;
		} else {
			mode_str = "50G-BASE-R2";
			host_mode = line_mode = MXD_P50LN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
	break;
	case QLM_MODE_50G_KR2:
	/* FIXME for case QLM_MODE_50G_CR2: */
		/* FIXME : to select the OP MODE for consortium/
		 * non-standard
		 */
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "50-BASE-KR2-RSFEC";
			host_mode = line_mode = MXD_P50JR;
		} else if (lmac_cfg->fec == CGX_FEC_BASE_R) {
			mode_str = "50G-BASE-KR2-FEC";
			host_mode = line_mode = MXD_P50KF;
		} else {
			mode_str = "50G-BASE-KR2";
			host_mode = line_mode = MXD_P50KN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 1;
	break;
	case QLM_MODE_80GAUI_4_C2C:
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "80G-BASE-R4-RSFEC";
			host_mode = line_mode = MXD_P100LR;
		} else {
			mode_str = "80G-BASE-R4";
			host_mode = line_mode = MXD_P100LN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
		marvell_5113_priv[cgx_id].mxddev.use20G = 1;
		marvell_5113_priv[cgx_id].port[port].use_20G = 1;
	break;
	case QLM_MODE_CAUI_4_C2C:
	case QLM_MODE_CAUI_4_C2M:
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "100G-BASE-R4-RSFEC";
			host_mode = line_mode = MXD_P100LR;
		} else {
			mode_str = "100G-BASE-R4";
			host_mode = line_mode = MXD_P100LN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
	break;
	case QLM_MODE_100G_KR4:
	/* FIXME for case QLM_MODE_100G_CR4 */
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "100G-BASE-KR4-RSFEC";
			host_mode = line_mode = MXD_P100KR;
		} else {
			mode_str = "100G-BASE-KR4";
			host_mode = line_mode = MXD_P100KN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 1;
	break;
	default:
	break;
	}
	if (mode_str != NULL)
		printf("%s: port %d mode_str %s host_mode %d\t"
				"line_mode %d\n", __func__, port, mode_str,
				host_mode, line_mode);

	status = mxdSetUserFixedModeSelection(&marvell_5113_priv[cgx_id].mxddev,
					phy->addr, port,
					host_mode, line_mode,
					forceReConfig, &result);

	if (status != MXD_OK) {
		ERROR("%s: SetMode failed, error_result. status 0x%lx\t"
			"result 0x%x\n", __func__, status, result);
		return;
	}

	/* EBB9604 88x5113 module has host/line swapped
	 * 88X5113 "host" side points to network
	 * 88x5113 "line" side points to CN96
	 * Patch : Received from Bruce(BDK)
	 */
	if (!strncmp(plat_octeontx_bcfg->bcfg.board_model, "ebb9", 4)) {
		MXD_U16 HostRxPolarities[4] = {0, 1, 0, 1};
		MXD_U16 HostTxPolarities[4] = {0, 0, 1, 0};
		MXD_U16 LineRxPolarities[4] = {1, 1, 0, 0};
		MXD_U16 LineTxPolarities[4] = {0, 0, 1, 1};

		/* Invert host-side input lanes 3 and 1
		 * Invert line-side input lanes 1 and 0 and
		 * line-side output lanes 3 and 2
		 * Invert host-side output lane 2
		 */
		status = mxdSetRxPolarity(
				&marvell_5113_priv[cgx_id].mxddev,
				phy->addr,
				MXD_HOST_SIDE, port,
				HostRxPolarities[port],
				swReset);
		if (status != MXD_OK) {
			ERROR("%s: mxdSetRxPolarity() host lane %d\t"
				" failed\n", __func__, port);
			return;
		}
		status = mxdSetTxPolarity(
				&marvell_5113_priv[cgx_id].mxddev,
				phy->addr,
				MXD_HOST_SIDE, port,
				HostTxPolarities[port],
				swReset);

		if (status != MXD_OK) {
			ERROR("%s: mxdSetTxPolarity() host lane %d\t"
				"failed\n", __func__, port);
			return;
		}
		status = mxdSetRxPolarity(
				&marvell_5113_priv[cgx_id].mxddev,
				phy->addr,
				MXD_LINE_SIDE, port,
				LineRxPolarities[port],
				swReset);
		if (status != MXD_OK) {
			ERROR("%s: mxdSetRxPolarity() line lane %d\t"
				"failed\n", __func__, port);
			return;
		}
		status = mxdSetTxPolarity(
				&marvell_5113_priv[cgx_id].mxddev,
				phy->addr,
				MXD_LINE_SIDE, port,
				LineTxPolarities[port],
				swReset);
		if (status != MXD_OK) {
			ERROR("%s: mxdSetTxPolarity() host lane %d\t"
				"failed\n", __func__, port);
			return;
		}
	}
}

/* To SW reset PHY */
void phy_marvell_5113_reset(int cgx_id, int lmac_id)
{
	MXD_STATUS status;
	int port;
	cgx_lmac_config_t *lmac_cfg;
	phy_config_t *phy;

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port = phy->port;

	printf("%s: %d:%d port %d\n", __func__, cgx_id, lmac_id, port);

	status = mxdLaneSoftReset(&marvell_5113_priv[cgx_id].mxddev,
			phy->addr, MXD_HOST_SIDE, port, 1000);
	status = mxdLaneSoftReset(&marvell_5113_priv[cgx_id].mxddev,
			phy->addr, MXD_LINE_SIDE, port, 1000);

	if (status != MXD_OK) {
		printf("%s: %d:%d Reset of PHY 88x5113 failed\n", __func__,
			cgx_id, lmac_id);
	}
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
	MXD_U16 currentStatus = 0;
	MXD_U16 latchedStatus = 0;
	MXD_DETAILED_STATUS_TYPE detailedStatus;
	MXD_STATUS status;
	MXD_SPEED speed = 0;
	MXD_PCS_TYPE pcsType = 0;
	MXD_U16 reg;
	MXD_U16 value;
	int port;
	cgx_lmac_config_t *lmac_cfg;
	phy_config_t *phy;
	int phy_side, host_side;
	MXD_U8 autoNegComplete = -1;
	static MXD_U16 speed_bits;

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port = phy->port;

	link->u64 = 0;

	if (!strncmp(plat_octeontx_bcfg->bcfg.board_model, "ebb9", 4)) {
		phy_side = MXD_HOST_SIDE;
		host_side = MXD_LINE_SIDE;
	} else {
		phy_side = MXD_LINE_SIDE;
		host_side = MXD_HOST_SIDE;
	}

	debug_phy_driver("%s: %d:%d phy side %d\n", __func__, cgx_id, lmac_id,
					phy_side);
	if (marvell_5113_priv[cgx_id].port[port].use_an) {
		/* Do nothing if AN already completed */
		if (!marvell_5113_priv[cgx_id].port[port].completed_an) {
			status = mxdAutoNegCheckComplete(
					&marvell_5113_priv[cgx_id].mxddev,
					phy->addr,
					host_side, port,
					&autoNegComplete);
			if (status != MXD_OK) {
				ERROR("%s(%d): mxdAutoNegCheckComplete() failed\n",
						__func__, port);
				return;
			}
			if (!autoNegComplete)	{
				debug_phy_driver("%s(%d): 88X5113 PHY AN not complete\n",
							__func__, port);
				return;
			}

			status = mxdGetAutoNegResolution(
					&marvell_5113_priv[cgx_id].mxddev,
						phy->addr, host_side, port,
						&speed_bits);
			if (status != MXD_OK) {
				ERROR("%s(%d): mxdGetAutoNegResolution() failed",
							__func__, port);
				return;
			}
		} else
			debug_phy_driver("%s: port %d completed_an\n",
						__func__, port);

		status =  mxdCheckLinkStatus(&marvell_5113_priv[cgx_id].mxddev,
						phy->addr, port, MXD_TRUE,
						&currentStatus, &latchedStatus,
						&detailedStatus);
		if (status != MXD_OK)
			ERROR("%s: mxdCheckLinkStatus failed %ld\n",
				__func__, status);

		debug_phy_driver("%s(%d): 88X5113 PHY link is %d, speed 0x%x\n",
				__func__, port, currentStatus, speed);

		if (currentStatus == MXD_LINK_UP)
			link->s.link_up = 1;
		else
			link->s.link_up = 0;

		debug_phy_driver("%s(%d): 88X5113 PHY returned speed_bits 0x%x\n",
						__func__, port, speed_bits);

		/* No macros defined by PHY SDK */
		if (speed_bits & 0x0008) {
			/* 10GB-KR = 0x0008 */
			link->s.full_duplex = 1;
			link->s.speed = CGX_LINK_10G;
		} else if (speed_bits & 0x0060) {
			/* 40GB-KR4 = 0x0020 */
			/* 40GB-CR4 = 0x0040 */
			link->s.full_duplex = 1;
			link->s.speed = CGX_LINK_40G;
		} else if (speed_bits & 0x0c00) {
			/* 100GB-KR4 = 0x0400 */
			/* 100GB-CR4 = 0x0800 */
			link->s.full_duplex = 1;
			link->s.speed = CGX_LINK_100G;
		} else if (speed_bits & 0x3000) {
			/* 25GB-KR-S/CR-S = 0x1000 */
			/* 25GB-KR/CR     = 0x2000 */
			link->s.full_duplex = 1;
			link->s.speed = CGX_LINK_25G;
		} else
			link->s.link_up = 0;
	} else {
		status =  mxdCheckLinkStatus(&marvell_5113_priv[cgx_id].mxddev,
						phy->addr, port, MXD_TRUE,
						&currentStatus, &latchedStatus,
						&detailedStatus);
		if (status != MXD_OK)
			ERROR("%s: mxdCheckLinkStatus failed %ld\n",
				__func__, status);

		status = mxdGetModeSpeed(&marvell_5113_priv[cgx_id].mxddev,
					phy->addr,
					phy_side, port, &speed,
					&pcsType);
		if (status != MXD_OK) {
			ERROR("%s: mxdGetModeSpeed failed %ld\n",
				__func__, status);
			return;
		}
		debug_phy_driver("%s(%d): 88X5113 PHY link is %d, speed 0x%x\n",
				__func__,
				port, currentStatus, speed);
		debug_phy_driver("%s(%d): 88X5113 PHY link hostCurrent.%ld\t"
				"lineCurrent.%ld\n", __func__, port,
			  detailedStatus.Per_lane_status.hostCurrent[port],
			  detailedStatus.Per_lane_status.lineCurrent[port]);

		link->s.link_up = (currentStatus == MXD_LINK_UP);
		link->s.full_duplex = 1;

		switch (speed) {
		case MXD_1GB:
			link->s.speed = CGX_LINK_1G;
		break;
		case MXD_10GB:
			link->s.speed = CGX_LINK_10G;
		break;
		case MXD_40GB:
			link->s.speed = CGX_LINK_40G;
		break;
		case MXD_25GB:
			link->s.speed = CGX_LINK_25G;
			/* FIXME to get speed for 20G */
			reg = 0xf005 + port;
			mxd_read_mdio(&marvell_5113_priv[cgx_id].mxddev,
							phy->addr,
							4, reg, &value);
			if (value == 0x8084) {
				debug_phy_driver("%s(%d): Report 20G speed\n",
						__func__, port);
				link->s.speed = CGX_LINK_20G;
			}
		break;
		/* FIXME for other modes : 50/100G - 40/80G */
		case MXD_50GB:
			link->s.speed = CGX_LINK_50G;
		break;
		case MXD_100GB:
			link->s.speed = CGX_LINK_100G;
		break;
		default:
			link->s.speed = CGX_LINK_NONE;
		break;
		}
	}
}

void phy_marvell_5113_supported_modes(int cgx_id, int lmac_id)
{
	phy_config_t *phy;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

	/* FIXME : 25/50/100 + CR/KR not tested with 5113 PHY.
	 * Don't add to the supported modes yet
	 * will be added with C0
	 */
	phy->supported_link_modes = ((1 << CGX_MODE_SGMII_BIT) |
			(1 << CGX_MODE_1000_BASEX_BIT) |
			(1 << CGX_MODE_10G_C2C_BIT) |
			(1 << CGX_MODE_10G_C2M_BIT) |
			(1 << CGX_MODE_10G_KR_BIT) |
			(1 << CGX_MODE_20G_C2C_BIT) |
			(1 << CGX_MODE_40G_C2C_BIT) |
			(1 << CGX_MODE_40G_C2M_BIT) |
			(1 << CGX_MODE_40GAUI_C2C_BIT) |
			(1 << CGX_MODE_80GAUI_C2C_BIT));
}

#ifdef DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS
static MXD_PRBS_SELECTOR_TYPE phy_marvell_5113_get_prbs_selector(int prbs)
{
	MXD_PRBS_SELECTOR_TYPE prbs_sel;

	switch (prbs) {
	case 7:
		prbs_sel = MXD_PRBS7;
		break;
	case 9:
		prbs_sel = MXD_PRBS9;
		break;
	case 13:
		prbs_sel = MXD_PRBS13;
		break;
	case 15:
		prbs_sel = MXD_PRBS15;
		break;
	case 23:
		prbs_sel = MXD_PRBS23;
		break;
	case 31:
		prbs_sel = MXD_PRBS31;
		break;
	default:
		WARN("Unsupported PRBS mode %d, using 7\n", prbs);
		prbs_sel = MXD_PRBS7;
		break;
	}

	return prbs_sel;
}


static int phy_marvell_5113_enable_prbs(int cgx_id, int lmac_id, int host_side,
	int prbs, int dir)
{
	MXD_STATUS status;
	phy_config_t *phy;
	int port_num;
	cgx_lmac_config_t *lmac_cfg;
	MXD_PRBS_SELECTOR_TYPE prbs_sel;
	int host_line_swapped;
	int enable_tx;
	int enable_rx;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port_num = phy->port;
	prbs_sel = phy_marvell_5113_get_prbs_selector(prbs);
	host_line_swapped =
		!strncmp(plat_octeontx_bcfg->bcfg.board_model, "ebb9", 4);

	status = mxdSetPRBSClearOnRead(
		&marvell_5113_priv[cgx_id].mxddev,
		phy->addr,
		MXD_HOST_SIDE,
		port_num,
		1);
	if (status != MXD_OK) {
		WARN("CGX%d(%d): mxdSetPRBSClearOnRead() failed\n",
			cgx_id, port_num);
		return -1;
	}

	status = mxdSetPRBSClearOnRead(
		&marvell_5113_priv[cgx_id].mxddev,
		phy->addr,
		MXD_LINE_SIDE,
		port_num,
		1);
	if (status != MXD_OK) {
		WARN("CGX%d(%d): mxdSetPRBSClearOnRead() failed\n",
			cgx_id, port_num);
		return -1;
	}

	status = mxdSetLineSidePRBSPattern(
		&marvell_5113_priv[cgx_id].mxddev,
		phy->addr,
		port_num,
		prbs_sel,
		MXD_PRBS_NONE,
		MXD_ALL_ZERO);
	if (status != MXD_OK) {
		WARN("CGX%d(%d): mxdSetLineSidePRBSPattern() failed\n",
			cgx_id, port_num);
		return -1;
	}

	status = mxdSetHostSidePRBSPattern(
		&marvell_5113_priv[cgx_id].mxddev,
		phy->addr,
		port_num,
		prbs_sel,
		MXD_PRBS_NONE,
		MXD_ALL_ZERO);
	if (status != MXD_OK) {
		WARN("CGX%d(%d): mxdSetHostSidePRBSPattern() failed\n",
			cgx_id, port_num);
		return -1;
	}

	enable_tx = (dir == QLM_DIRECTION_TX);
	enable_rx = (dir == QLM_DIRECTION_RX);

	status = mxdSetPRBSEnableTxRx(
		&marvell_5113_priv[cgx_id].mxddev,
		phy->addr,
		(host_side ^ host_line_swapped) ? MXD_HOST_SIDE : MXD_LINE_SIDE,
		port_num,
		(enable_tx | enable_rx) ? MXD_ENABLE : MXD_DISABLE, /* TX */
		(enable_rx) ? MXD_ENABLE : MXD_DISABLE); /* RX */
	if (status != MXD_OK) {
		WARN("CGX%d(%d): mxdSetPRBSEnableTxRx() failed\n",
			cgx_id, port_num);
		return -1;
	}
	return 0;
}

static int phy_marvell_5113_disable_prbs(int cgx_id, int lmac_id, int host_side,
	int prbs)
{
	MXD_STATUS status;
	phy_config_t *phy;
	int port_num;
	cgx_lmac_config_t *lmac_cfg;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port_num = phy->port;

	status = mxdSetPRBSEnableTxRx(
		&marvell_5113_priv[cgx_id].mxddev,
		phy->addr,
		(host_side) ? MXD_HOST_SIDE : MXD_LINE_SIDE,
		0, /* lane */
		MXD_DISABLE, /* TX */
		MXD_DISABLE); /* RX */
	if (status != MXD_OK) {
		WARN("CGX%d(%d): mxdSetPRBSEnableTxRx() failed\n",
			cgx_id, port_num);
		return -1;
	}
	return 0;
}

static uint64_t phy_marvell_5113_get_prbs_errors(int cgx_id, int lmac_id,
	int host_side, int clear, int prbs)
{
	MXD_STATUS status;
	phy_config_t *phy;
	int port_num;
	cgx_lmac_config_t *lmac_cfg;
	MXD_U16 phy_side;
	MXD_BOOL locked = 0;
	MXD_U64 txBitCount;
	MXD_U64 rxBitCount;
	MXD_U64 rxBitErrorCount;
	uint64_t errors;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port_num = phy->port;
	if (!strncmp(plat_octeontx_bcfg->bcfg.board_model, "ebb9", 4))
		phy_side = host_side ? MXD_LINE_SIDE : MXD_HOST_SIDE;
	else
		phy_side = host_side ? MXD_HOST_SIDE : MXD_LINE_SIDE;

	status = mxdGetPRBSLocked(
		&marvell_5113_priv[cgx_id].mxddev,
		phy->addr,
		phy_side,
		port_num,
		&locked);
	if (status != MXD_OK) {
		WARN("CGX%d(%d): mxdGetPRBSLocked() failed\n",
			cgx_id, port_num);
		return -1;
	}

	if (!locked)
		return -1;

	status = mxdGetPRBSCounts(
		&marvell_5113_priv[cgx_id].mxddev,
		phy->addr,
		phy_side,
		port_num,
		&txBitCount,
		&rxBitCount,
		&rxBitErrorCount);
	if (status != MXD_OK) {
		WARN("CGX%d(%d): mxdGetPRBSCounts() failed\n",
			cgx_id, port_num);
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

phy_drv_t marvell_5113_drv = {
		.drv_name		= "MARVELL-88X5113",
		.drv_type		= PHY_MARVELL_5113,
		.flags			= 0,
		.probe			= phy_marvell_5113_probe,
		.config			= phy_marvell_5113_config,
		.set_an			= phy_marvell_5113_set_an,
		.reset			= phy_marvell_5113_reset,
		.get_link_status	= phy_marvell_5113_get_link_status,
		.set_supported_modes	= phy_marvell_5113_supported_modes,
		.shutdown		= phy_generic_shutdown,
#ifdef DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS
		.enable_prbs		= phy_marvell_5113_enable_prbs,
		.disable_prbs		= phy_marvell_5113_disable_prbs,
		.get_prbs_errors	= phy_marvell_5113_get_prbs_errors,
#endif /* DEBUG_ATF_ENABLE_SERDES_DIAGNOSTIC_CMDS */
	};

phy_drv_t *marvell_5113_check_type(int type)
{
	if (marvell_5113_drv.drv_type == type)
		return &marvell_5113_drv;
	return NULL;
}
