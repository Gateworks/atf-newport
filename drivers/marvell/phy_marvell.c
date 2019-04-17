/*
 * Copyright (C) 2018 Marvell International Ltd.
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
#include "mxdApiRegs.h"
#include "mxdApiTypes.h"
#include "mxdAPI.h"
#include "mxdHwCntl.h"
#include "mxdUtils.h"
#include "mxdFwDownload.h"
#include "mxdInitialization.h"
#include "mxdHwSerdesCntl.h"
#include "mxdAPIInternal.h"

#ifdef MARVELL_PHY_6141
/* 6141 includes */
#include "mydApiTypes.h"
#include "mydAPI.h"
#include "mydUtils.h"
#include "mydInitialization.h"
#include "mydFwImages.h"
#include "mydHwSerdesCntl.h"
#endif /* MARVELL_PHY_6141 */

/* define DEBUG_ATF_MARVELL_PHY_DRIVER to enable debug logs */
#undef DEBUG_ATF_MARVELL_PHY_DRIVER	/* Marvell PHY Driver logs */

#ifdef DEBUG_ATF_MARVELL_PHY_DRIVER
#define debug_phy_driver printf
#else
#define debug_phy_driver(...) ((void) (0))
#endif

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
	} port[8];
} phy_mcd_priv_t;

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
	} port[4];
} phy_mxd_priv_t;

phy_mcd_priv_t marvell_5123_priv;

/* Allow multiple instances of PHY driver to run on different QLMs */
phy_mxd_priv_t marvell_5113_priv[MAX_CGX];

#ifdef MARVELL_PHY_6141
MYD_DEV marvell_6141_priv;
#endif /* MARVELL_PHY_6141 */

static MCD_STATUS mcd_read_mdio(MCD_DEV_PTR pDev, MCD_U16 mdioPort, MCD_U16 mmd, MCD_U16 reg, MCD_U16 *value)
{
	int read;
	phy_config_t *phy = pDev->hostContext;
	read = smi_read(phy->mdio_bus, CLAUSE45, phy->addr, mmd, reg);
	*value = read;
	return MCD_OK;
}

static MCD_STATUS mcd_write_mdio(MCD_DEV_PTR pDev, MCD_U16 mdioPort, MCD_U16 mmd, MCD_U16 reg, MCD_U16 value)
{
	phy_config_t *phy = pDev->hostContext;
	smi_write(phy->mdio_bus, phy->addr, mmd, CLAUSE45, reg, value);
	return MCD_OK;
}

static MXD_STATUS mxd_read_mdio(MXD_DEV_PTR pDev, MXD_U16 mdioPort, MXD_U16 mmd, MXD_U16 reg, MXD_U16 *value)
{
	int read;
	phy_config_t *phy = pDev->hostContext;
	read = smi_read(phy->mdio_bus, CLAUSE45, phy->addr, mmd, reg);
	*value = read;
	return MXD_OK;
}

static MXD_STATUS mxd_write_mdio(MXD_DEV_PTR pDev, MXD_U16 mdioPort, MXD_U16 mmd, MXD_U16 reg, MXD_U16 value)
{
	phy_config_t *phy = pDev->hostContext;
	smi_write(phy->mdio_bus, phy->addr, mmd, CLAUSE45, reg, value);
	return MXD_OK;
}

#ifdef MARVELL_PHY_6141
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
#endif /* MARVELL_PHY_6141 */

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
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 22, 0x00FF);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 17, 0x214B);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 16, 0x2144);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 17, 0x0C28);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 16, 0x2146);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 17, 0xB233);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 16, 0x214D);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 17, 0xCC0C);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 16, 0x2159);
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 22, 0x0000);

	/* SGMII-to-Copper mode initialization */
	/* Select page 18 */
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 22, 0x0012);

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
	smi_write(phy->mdio_bus, phy->addr, -1, CLAUSE22, 22, 0x0);
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
	static int init;
	MCD_STATUS status;
	MCD_U16 serdesRevision = 0;
	MCD_U16 sbmRevision = 0;
	phy_config_t *phy;

	if (init)
		return;

	printf("%s: Initializing Marvell 88x5123 PHY...\n", __func__);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;

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

	debug_phy_driver("%s: port %d AN %d\n", __func__, port_num,
			!lmac_cfg->autoneg_dis);

	if (!lmac_cfg->autoneg_dis)
		marvell_5123_priv.port[port_num].use_an = 1;

	switch (lmac_cfg->mode) {
	case CAVM_CGX_LMAC_TYPES_E_TENG_R:
		modesVector = MCD_AN_10GBase_KR;
		op_mode = MCD_MODE_P10L;
		fec_type = MCD_NO_FEC;
		mode_str = "10GBASE-KR";
	break;
	case CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R:
		modesVector = MCD_AN_25GBase_KR1S;
		op_mode = MCD_MODE_P25S;
		fec_type = MCD_RS_FEC_HOST;
		mode_str = "25GBASE-KR";
	break;
	case CAVM_CGX_LMAC_TYPES_E_FORTYG_R:
		modesVector = MCD_AN_40GBASE_KR4;
		op_mode = MCD_MODE_P40L;
		fec_type = MCD_NO_FEC;
		mode_str = "40GBASE-KR4";
	break;
	case CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R:
		modesVector = MCD_AN_100GBASE_KR4;
		op_mode = MCD_MODE_P100S;
		fec_type = MCD_RS_FEC_HOST;
		mode_str = "100GBASE-KR4";
	break;
	/* FIXME for other modes */
	default:
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
		case QLM_MODE_XFI:
		case QLM_MODE_SFI:
			link->s.speed = CGX_LINK_10G;
		break;
		case QLM_MODE_20GAUI_C2C:
		case QLM_MODE_20GAUI_C2M:
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
		case QLM_MODE_40GAUI_2_C2M:
			link->s.speed = CGX_LINK_40G;
		break;
		case QLM_MODE_50GAUI_2_C2C:
		case QLM_MODE_50GAUI_2_C2M:
			link->s.speed = CGX_LINK_50G;
		break;
		case QLM_MODE_80GAUI_4_C2C:
		case QLM_MODE_80GAUI_4_C2M:
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

#define MXD_LINE_SIDE  3
#define MXD_HOST_SIDE  4

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
	MXD_16 preCursor;
	MXD_16 attenuation;
	MXD_16 postCursor;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port = phy->port;

	debug_phy_driver("%s: port %d AN %d QLM mode %d\n", __func__, port,
			!lmac_cfg->autoneg_dis, lmac_cfg->mode_idx);

	/* Disable AN and enable AN only for appropriate modes */
	marvell_5113_priv[cgx_id].port[port].use_an = 0;
	switch (lmac_cfg->mode_idx) {
	case QLM_MODE_XLAUI:
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
	case QLM_MODE_20GAUI_C2M:
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
	case QLM_MODE_25G_AN:
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
	case QLM_MODE_50G_AN:
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
	case QLM_MODE_80GAUI_4_C2M:
		if (lmac_cfg->fec == CGX_FEC_RS) {
			mode_str = "80G-BASE-R4-RSFEC";
			host_mode = line_mode = MXD_P100LR;
		} else {
			mode_str = "80G-BASE-R4";
			host_mode = line_mode = MXD_P100LN;
		}
		marvell_5113_priv[cgx_id].port[port].use_an = 0;
		marvell_5113_priv[cgx_id].mxddev.use20G = 1;
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
	case QLM_MODE_100G_AN:
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
	if (!strncmp(plat_octeontx_bcfg->bcfg.board_model, "ebb96", 5)) {
		MXD_U16 HostRxPolarities[4] = {0, 1, 0, 1};
		MXD_U16 HostTxPolarities[4] = {0, 0, 1, 0};
		MXD_U16 LineRxPolarities[4] = {1, 1, 0, 0};
		MXD_U16 LineTxPolarities[4] = {0, 0, 1, 1};

		/* Invert host-side input lanes 3 and 1
		 * Invert line-side input lanes 1 and 0 and
		 * line-side output lanes 3 and 2
		 * Invert host-side output lane 2
		 */
		for (int lane = 0; lane < 4; lane++) {
			status = mxdSetRxPolarity(
					&marvell_5113_priv[cgx_id].mxddev,
					phy->addr,
					MXD_HOST_SIDE, lane,
					HostRxPolarities[lane],
					swReset);
			if (status != MXD_OK) {
				ERROR("%s: mxdSetRxPolarity() host lane %d\t"
					" failed\n", __func__, lane);
				return;
			}
			status = mxdSetTxPolarity(
					&marvell_5113_priv[cgx_id].mxddev,
					phy->addr,
					MXD_HOST_SIDE, lane,
					HostTxPolarities[lane],
					swReset);

			if (status != MXD_OK) {
				ERROR("%s: mxdSetTxPolarity() host lane %d\t"
					"failed\n", __func__, lane);
				return;
			}
			status = mxdSetRxPolarity(
					&marvell_5113_priv[cgx_id].mxddev,
					phy->addr,
					MXD_LINE_SIDE, lane,
					LineRxPolarities[lane],
					swReset);
			if (status != MXD_OK) {
				ERROR("%s: mxdSetRxPolarity() line lane %d\t"
					"failed\n", __func__, lane);
				return;
			}
			status = mxdSetTxPolarity(
					&marvell_5113_priv[cgx_id].mxddev,
					phy->addr,
					MXD_LINE_SIDE, lane,
					LineTxPolarities[lane],
					swReset);
			if (status != MXD_OK) {
				ERROR("%s: mxdSetTxPolarity() host lane %d\t"
					"failed\n", __func__, lane);
				return;
			}
		}
	}

	/* Patch : from Bruce (BDK) for 25G Serdes Tuning */
	if ((lmac_cfg->mode_idx == QLM_MODE_20GAUI_C2C) ||
		(lmac_cfg->mode_idx == QLM_MODE_20GAUI_C2M)) {
		debug_phy_driver("%s(%d): 20G serdes tuning\n", __func__, port);
		preCursor = 6;
		attenuation = 31;
		postCursor = 4;
		/* FIXME : QLM 6 needs different tuning */
		if (lmac_cfg->qlm == 6) {
			preCursor = 10;
			attenuation = 31;
			postCursor = 6;
		}
		status = mxdSetTxFFE(&marvell_5113_priv[cgx_id].mxddev,
					phy->addr,
					MXD_LINE_SIDE, port,
					preCursor, attenuation,
					postCursor, 1);
		if (status != MXD_OK) {
			ERROR("%s(%d): mxdSetTxFFE failed\n", __func__, port);
			return;
		}
		status = mxdGetTxFFE(&marvell_5113_priv[cgx_id].mxddev,
					phy->addr,
					MXD_LINE_SIDE, port,
					&preCursor, &attenuation,
					&postCursor);
		if (status != MXD_OK) {
			ERROR("%s(%d): mxdGetTxFFE failed\n", __func__, port);
			return;
		}
		debug_phy_driver("%s(%d): FFE preCursor.%d attenuation.%d\t"
				"postCursor.%d\n", __func__, port, preCursor,
				attenuation, postCursor);
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
	int phy_side;

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	phy = &lmac_cfg->phy_config;
	port = phy->port;

	link->u64 = 0;

	if (!strncmp(plat_octeontx_bcfg->bcfg.board_model, "ebb96", 5))
		phy_side = MXD_HOST_SIDE;
	else
		phy_side = MXD_LINE_SIDE;

	debug_phy_driver("%s: %d:%d phy side %d\n", __func__, cgx_id, lmac_id,
					phy_side);
	if (marvell_5113_priv[cgx_id].port[port].use_an) {
		/* FIXME */
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

#ifdef MARVELL_PHY_6141
void phy_marvell_6141_probe(int cgx_id, int lmac_id)
{
	MYD_U16 x6141_sbus_master_image_size;
	MYD_U16 x6141_serdes_image_size;
	MYD_STATUS status;
	phy_config_t *phy;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	phy->priv = &marvell_6141_priv;

	if (marvell_6141_priv.devEnabled)
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
			       &marvell_6141_priv);
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

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	switch (lmac_cfg->mode_idx) {
	case QLM_MODE_10G_KR:
		host_mode = MYD_P10KN; /* 10GBASE-KR, no FEC */
		line_mode = MYD_P10LN; /* 10GBASE-LR/SR */
		break;

	case QLM_MODE_25GAUI_C2C:
		host_mode = MYD_P25LR; /* 25GBASE-R, RS-FEC, no AN */
		line_mode = MYD_P25LN; /* 25GBASE-R, no FEC, no AN */
		break;

	case QLM_MODE_50GAUI_2_C2C:
		host_mode = MYD_P50MR; /* 50GBASE-R2, RS-FEC, no AN */
		line_mode = MYD_P50MN; /* 50GBASE-R2, no FEC, no AN */
		break;

	default:
		ERROR("%s: %d:%d QLM_MODE %d is not supported\n", __func__,
		      cgx_id, lmac_id, lmac_cfg->mode_idx);
		return;
	}

	phy = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id].phy_config;
	lane = lmac_cfg->lane_to_sds & 3;

	status = mydSetModeSelection(phy->priv, phy->addr, lane, host_mode,
				     line_mode, MYD_MODE_ICAL_EFFORT_0,
				     &result);
	if (status == MYD_OK)
		return;

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
	int lmac_type;

	debug_phy_driver("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	lmac_type = lmac_cfg->mode;
	lane = lmac_cfg->lane_to_sds & 3;
	phy = &lmac_cfg->phy_config;

	mydMemSet(&statusDetail, 0, sizeof(MYD_PCS_LINK_STATUS));
	link->u64 = 0;

	status = mydCheckPCSLinkStatus(phy->priv, phy->addr, lane,
				       &currentStatus, &latchedStatus,
				       &statusDetail);
	if (status == MYD_OK) {
		if (currentStatus == MYD_LINK_UP) {
			switch (lmac_type) {
			case CAVM_CGX_LMAC_TYPES_E_TENG_R:
				link->s.speed = CGX_LINK_10G;
				break;
			case CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R:
				link->s.speed = CGX_LINK_25G;
				break;
			case CAVM_CGX_LMAC_TYPES_E_FIFTYG_R:
				link->s.speed = CGX_LINK_50G;
				break;
			default:
				ERROR("%s: %d:%d Unexpected lmac_type %d\n",
				      __func__, cgx_id, lmac_id, lmac_type);
				return;
			}
			link->s.link_up = 1;
			link->s.full_duplex = 1;
		}
		return;
	}

	ERROR("%s: %d:%d mydCheckPCSLinkStatus() failed for lane %hu.\n",
	      __func__, cgx_id, lmac_id, lane);
}
#endif /* MARVELL_PHY_6141 */

/* Table of Marvell PHY driver list */
phy_drv_t marvell_drv[] = {
	{
		.drv_name		= "MARVELL-88E1514",
		.drv_type		= PHY_MARVELL_88E1514,
		.flags			= 0,
		.probe			= phy_marvell_1514_probe,
		.config			= phy_generic_config,
		.set_an			= phy_generic_set_an,
		.reset			= phy_generic_reset,
		.get_link_status	= phy_marvell_1514_get_link_status,
		.shutdown		= phy_generic_shutdown,
	},
	{
		.drv_name		= "MARVELL-88X5123",
		.drv_type		= PHY_MARVELL_5123,
		.flags			= 0,
		.probe			= phy_marvell_5123_probe,
		.config			= phy_marvell_5123_config,
		.set_an			= phy_marvell_5123_set_an,
		.reset			= phy_generic_reset,
		.get_link_status	= phy_marvell_5123_get_link_status,
		.shutdown		= phy_generic_shutdown,
	},
	{
		.drv_name		= "MARVELL-88X5113",
		.drv_type		= PHY_MARVELL_5113,
		.flags			= 0,
		.probe			= phy_marvell_5113_probe,
		.config			= phy_marvell_5113_config,
		.set_an			= phy_marvell_5113_set_an,
		.reset			= phy_generic_reset,
		.get_link_status	= phy_marvell_5113_get_link_status,
		.shutdown		= phy_generic_shutdown,
	},

#ifdef MARVELL_PHY_6141
	{
		.drv_name		= "MARVELL-88X6141",
		.drv_type		= PHY_MARVELL_6141,
		.flags			= 0,
		.probe			= phy_marvell_6141_probe,
		.config			= phy_marvell_6141_config,
		.reset			= phy_generic_reset,
		.get_link_status	= phy_marvell_6141_get_link_status,
		.shutdown		= phy_generic_shutdown,
	},
#endif /* MARVELL_PHY_6141 */
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
