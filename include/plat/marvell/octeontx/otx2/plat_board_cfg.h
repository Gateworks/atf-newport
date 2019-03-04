/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLAT_BOARD_CFG_H__
#define __PLAT_BOARD_CFG_H__

#include <platform_dt.h>
#include <cgx.h>
#include <sfp_mgmt.h>
#include <phy_mgmt.h>
#include <octeontx_board_cfg.h>

/* Define different QLM-MODE variants. These definitions based on the BDK code. */
typedef enum {
	/* QLM is disabled (all chips) */
	CAVM_QLM_MODE_DISABLED,
	/* PCIe modes  */
	/* 1 PCIe, 1 lane. Other lanes unused */
	CAVM_QLM_MODE_PCIE_1X1,
	/* 1 PCIe, 2 lanes */
	CAVM_QLM_MODE_PCIE_1X2,
	/* 1 PCIe, 4 lanes */
	CAVM_QLM_MODE_PCIE_1X4,
	/* 1 PCIe, 8 lanes */
	CAVM_QLM_MODE_PCIE_1X8,
	/* 1 PCIe, 16 lanes (CN93XX) */
	CAVM_QLM_MODE_PCIE_1X16,
	/* SATA modes  */
	/* SATA, each lane independent (CN81xx) */
	CAVM_QLM_MODE_SATA,
	/* BGX / CGX modes */
	/* SGMII, each lane independent (CN81xx) */
	CAVM_QLM_MODE_SGMII,
	/* 1000BASE-X, each lane independent */
	CAVM_QLM_MODE_1G_X,
	/* QSGMII is 4 SGMII on one lane (CN81xx) */
	CAVM_QLM_MODE_QSGMII,
	/* 1 XAUI or DXAUI, 4 lanes (CN81xx), use gbaud to tell difference */
	CAVM_QLM_MODE_XAUI,
	/* 2 RXAUI, 2 lanes each (CN81xx) */
	CAVM_QLM_MODE_RXAUI,
	/* 4 XFI, 1 lane each (CN81xx) */
	CAVM_QLM_MODE_XFI,
	/* 4 SFI, 1 lane each (CN93xx) */
	CAVM_QLM_MODE_SFI,
	/* 1 XLAUI chip-to-chip, 4 lanes each (CN81xx) */
	CAVM_QLM_MODE_XLAUI,
	/* 1 XLAUI chip-to-module, 4 lanes each (CN93xx) */
	CAVM_QLM_MODE_XLAUI_C2M,
	/* 4 10GBASE-KR, 1 lane each (CN81xx) */
	CAVM_QLM_MODE_10G_KR,
	/* 1 40GBASE-KR4, 4 lanes each (CN83xx) */
	CAVM_QLM_MODE_40G_KR4,
	/* 20GAUI chip to chip, 1 lane each (CN9XXX) */
	CAVM_QLM_MODE_20GAUI_C2C,
	/* 20GAUI chip to module, 1 lane each (CN9XXX) */
	CAVM_QLM_MODE_20GAUI_C2M,
	/* 25G chip-to-chip, 1 lane each (CN93XX QLMs) */
	CAVM_QLM_MODE_25GAUI_C2C,
	/* 25G chip-to-module, 1 lane each (CN93XX QLMs) */
	CAVM_QLM_MODE_25GAUI_C2M,
	/* 40GAUI-2 chip to chip, 2 lanes each (CN9XXX) */
	CAVM_QLM_MODE_40GAUI_2_C2C,
	/* 40GAUI-2 chip to module, 2 lanes each (CN9XXX) */
	CAVM_QLM_MODE_40GAUI_2_C2M,
	/* 50G chip to chip, 2 lanes each (CN93XX QLMs) */
	CAVM_QLM_MODE_50GAUI_2_C2C,
	/* 50G chip to module, 2 lanes each (CN93XX QLMs) */
	CAVM_QLM_MODE_50GAUI_2_C2M,
	/* 80GAUI-2 chip to chip, 4 lanes each (CN9XXX) */
	CAVM_QLM_MODE_80GAUI_4_C2C,
	/* 80GAUI-2 chip to module, 4 lanes each (CN9XXX) */
	CAVM_QLM_MODE_80GAUI_4_C2M,
	/* 100G chip-to-chip, 4 lanes each (CN93XX) */
	CAVM_QLM_MODE_CAUI_4_C2C,
	/* 100G chip-to-module, 4 lanes each (CN93XX) */
	CAVM_QLM_MODE_CAUI_4_C2M,
	/* 25G max using auto-neg, 1 lane each (CN93XX QLMs) */
	CAVM_QLM_MODE_25G_AN,
	/* 50G max using auto-neg, 2 lanes each (CN93XX QLMs) */
	CAVM_QLM_MODE_50G_AN,
	/* 100G max using auto-neg, 4 lanes each (CN93XX) */
	CAVM_QLM_MODE_100G_AN,
	/* USXGMII, 4 over 1 lane, 10M, 100M, 1G, 2.5G, 5G (CN93XX QLMs) */
	CAVM_QLM_MODE_USXGMII_4X1,
	/* USXGMII, 2 over 1 lane, 10M, 100M, 1G, 2.5G, 5G, 10G (CN93XX QLMs) */
	CAVM_QLM_MODE_USXGMII_2X1,
	/* USXGMII, 1 over 1 lane, 10M, 100M, 1G, 2.5G, 5G, 10G,
	 * 20G (CN93XX QLMs)
	 */
	CAVM_QLM_MODE_USXGMII_1X1,
	CAVM_QLM_MODE_LAST,
} octeontx_qlm_modes_t;

/* This structure is stored in GSERNX_LANEX_SCRATCHX to remember the mode of a
 * single lane. Based on the BDK structure;
 */
typedef union
{
	uint64_t u;
	struct {
		uint16_t baud_mhz;		/* Baudrate of the lane in MHz */
		octeontx_qlm_modes_t mode: 8;	/* Mode of the lane */
		uint32_t flags: 8;		/* Mode flags */
		uint32_t pcie: 1;		/* Mode is PCIE RC or endpoint, see flags */
		uint32_t sata: 1;		/* Mode is SATA */
		uint32_t cgx: 1;		/* Mode is supported by CGX, see mode for details */
		uint32_t reserved: 29;		/* Reserved for future use */
	} s;
} octeontx_qlm_state_lane_t;

typedef struct rvu_sw_rvu_pf {
	int num_rvu_vfs;
	int num_msix_vec;
} rvu_sw_rvu_pf_t;

typedef enum {
	SW_RVU_SSO_TIM_PF,
	SW_RVU_NPA_PF,
	SW_RVU_CPT_PF,
	SW_RVU_MAX_PF
} sw_rvu_pfs;

typedef struct rvu_config {
	int valid;
	int cpt_dis;	/* to indicate if CPT block is not present */
	rvu_sw_rvu_pf_t admin_pf;
	rvu_sw_rvu_pf_t sw_pf[SW_RVU_MAX_PF];
} rvu_config_t;

/* Define LMAC structure. */
typedef struct cgx_lmac_config {
	/* for RVU */
	int num_rvu_vfs;
	int num_msix_vec;
	/* below info to be filled by
	 * FDT parser during boot time or mode
	 * change
	 */
	int lane_to_sds;
	int use_training;
	int mode;		/* octeontx_qlm_mode enum type */
	int mode_idx;		/* helper field for the mode mapping */
	int qlm;		/* from BDK DT */
	int lane;		/* from BDK DT */
	/* NOTE: when this bit is set, it doesn't necessarily
	 * mean the link is up until the user sends LINK UP command
	 */
	int lmac_enable;
	int phy_mode;		/* MAC or PHY mode for SGMII */
	int sgmii_1000x_mode;	/* SGMII or 1000x mode for SGMII */
	int phy_present;
	int sfp_slot;
	int autoneg_dis;
	int fec;
	uint8_t local_mac_address[6];
	phy_config_t phy_config;
	sfp_slot_info_t sfp_info;
} cgx_lmac_config_t;

typedef struct cgx_config {
	uint32_t lmac_count:4;
	uint32_t lmacs_used:4;
	uint32_t usxgmii_mode:1; /* global - per CGX */
	/* for RVU */
	uint32_t enable:1;
	cgx_lmac_config_t lmac_cfg[MAX_LMAC_PER_CGX];
} cgx_config_t;

typedef struct plat_octeontx_board_cfg {
	board_cfg_t bcfg;

	rvu_config_t rvu_config;
	cgx_config_t cgx_cfg[MAX_CGX];
} plat_octeontx_board_cfg_t;

extern plat_octeontx_board_cfg_t * const plat_octeontx_bcfg;

#endif /* __PLAT_BOARD_CFG_H__ */
