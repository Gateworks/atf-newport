/** @file

    Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _CAVM_DT_H_
#define _CAVM_DT_H_

#include <platform_dt.h>
#include <cavm_phy_mgmt.h>

/* Define different QLM-MODE variants. These definitions based on the BDK code. */
typedef enum {
	CAVM_QLM_MODE_DISABLED,		/* QLM is disabled (all chips) */
	/* PCIe modes  */
	CAVM_QLM_MODE_PCIE_1X1,		/* 1 PCIe, 1 lane. Other lanes unused */
	CAVM_QLM_MODE_PCIE_1X2,		/* 1 PCIe, 2 lanes */
	CAVM_QLM_MODE_PCIE_1X4,		/* 1 PCIe, 4 lanes */
	CAVM_QLM_MODE_PCIE_1X8,		/* 1 PCIe, 8 lanes */
	CAVM_QLM_MODE_PCIE_1X16,	/* 1 PCIe, 16 lanes (CN93XX) */
	/* SATA modes  */
	CAVM_QLM_MODE_SATA_4X1,		/* SATA, each lane independent (cn88xx) */
	CAVM_QLM_MODE_SATA_2X1,		/* SATA, each lane independent (cn83xx) */
	/* CCPI / OCI modes */
	CAVM_QLM_MODE_OCI,		/* OCI Multichip interconnect (cn88xx) */
	/* BGX / CGX modes */
	CAVM_QLM_MODE_SGMII_4X1,	/* SGMII, each lane independent (cn88xx) */
	CAVM_QLM_MODE_SGMII_2X1,	/* SGMII, each lane independent (cn83xx) */
	CAVM_QLM_MODE_SGMII_1X1,	/* SGMII, single lane (cn80xx) */
	CAVM_QLM_MODE_XAUI_1X4,		/* 1 XAUI or DXAUI, 4 lanes (cn88xx), use gbaud to tell difference */
	CAVM_QLM_MODE_RXAUI_2X2,	/* 2 RXAUI, 2 lanes each (cn88xx) */
	CAVM_QLM_MODE_RXAUI_1X2,	/* 1 RXAUI, 2 lanes each (cn83xx) */
	CAVM_QLM_MODE_XFI_4X1,		/* 4 XFI, 1 lane each (cn88xx) */
	CAVM_QLM_MODE_XFI_2X1,		/* 2 XFI, 1 lane each (cn83xx) */
	CAVM_QLM_MODE_XFI_1X1,		/* 1 XFI, single lane (cn80xx) */
	CAVM_QLM_MODE_XLAUI_1X4,	/* 1 XLAUI, 4 lanes each (cn88xx) */
	CAVM_QLM_MODE_10G_KR_4X1,	/* 4 10GBASE-KR, 1 lane each (cn88xx) */
	CAVM_QLM_MODE_10G_KR_2X1,	/* 2 10GBASE-KR, 1 lane each (cn83xx) */
	CAVM_QLM_MODE_10G_KR_1X1,	/* 1 10GBASE-KR, single lane (cn80xx) */
	CAVM_QLM_MODE_40G_KR4_1X4,	/* 1 40GBASE-KR4, 4 lanes each (cn88xx) */
	CAVM_QLM_MODE_QSGMII_4X1,	/* QSGMII is 4 SGMII on one lane (cn81xx, cn83xx) */
	CAVM_QLM_MODE_25G_4X1,		/* 25G, 1 lane each (CN93XX QLMs) */
	CAVM_QLM_MODE_25G_2X1,		/* 25G, 1 lane each (CN93XX DLMs) */
	CAVM_QLM_MODE_50G_2X2,		/* 50G, 2 lanes each (CN93XX QLMs) */
	CAVM_QLM_MODE_50G_1X2,		/* 50G, 2 lanes each (CN93XX DLMs) */
	CAVM_QLM_MODE_100G_1X4,		/* 100G, 4 lanes each (CN93XX) */
	CAVM_QLM_MODE_25G_KR_4X1,	/* 25G-KR, 1 lane each (CN93XX QLMs) */
	CAVM_QLM_MODE_25G_KR_2X1,	/* 25G-KR, 1 lane each (CN93XX DLMs) */
	CAVM_QLM_MODE_50G_KR_2X2,	/* 50G-KR, 2 lanes each (CN93XX QLMs) */
	CAVM_QLM_MODE_50G_KR_1X2,	/* 50G-KR, 2 lanes each (CN93XX DLMs) */
	CAVM_QLM_MODE_100G_KR4_1X4,	/* 100G-KR4, 4 lanes each (CN93XX) */
	CAVM_QLM_MODE_USXGMII_4X1,	/* USXGMII, 4 over 1 lane, 10M, 100M, 1G, 2.5G, 5G (CN93XX QLMs) */
	CAVM_QLM_MODE_USXGMII_2X1,	/* USXGMII, 2 over 1 lane, 10M, 100M, 1G, 2.5G, 5G, 10G (CN93XX QLMs) */
	CAVM_QLM_MODE_LAST,
} cavm_qlm_modes_t;

/* This structure is stored in GSERNX_LANEX_SCRATCHX to remember the mode of a
 * single lane. Based on the BDK structure;
 */
typedef union
{
	uint64_t u;
	struct {
		uint16_t baud_mhz;		/* Baudrate of the lane in MHz */
		cavm_qlm_modes_t mode: 8;	/* Mode of the lane */
		uint32_t flags: 8;		/* Mode flags */
		uint32_t pcie: 1;		/* Mode is PCIE RC or endpoint, see flags */
		uint32_t sata: 1;		/* Mode is SATA */
		uint32_t cgx: 1;		/* Mode is supported by CGX, see mode for details */
		uint32_t reserved: 29;		/* Reserved for future use */
	} s;
} cavm_qlm_state_lane_t;

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

typedef struct phy_config {
	int phy_addr;
	int mdio_bus;
	char phy_compatible[64];
	octeontx_sfp_info_t sfp_info;
} phy_config_t;

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
	/* NOTE: when this bit is set, it doesn't necessarily
	 * mean the link is up until the user sends LINK UP command
	 */
	int lmac_enable;
	int phy_mode;		/* MAC or PHY mode for SGMII */
	int sgmii_1000x_mode;	/* SGMII or 1000x mode for SGMII */
	int phy_present;
	int autoneg_dis;
	uint8_t local_mac_address[6];
	phy_config_t phy_config;
} cgx_lmac_config_t;

typedef struct cgx_config {
	uint32_t node:4;
	uint32_t lmac_count:4;
	uint32_t lmacs_used:4;
	/* for RVU */
	uint32_t enable:1;
	cgx_lmac_config_t lmac_cfg[MAX_LMAC_PER_CGX];
} cgx_config_t;

typedef struct boot_device_conf {
	int node;
	int boot_type;
	int controller;
	int cs;
} boot_device_conf_t;

typedef union mcu_twsi {
	uint32_t u;
	struct mcu_twsi_s {
		uint32_t node		: 8; /* Node ID */
		uint32_t int_addr	: 8; /* TWSI Internal Address */
		uint32_t bus		: 8; /* TWSI bus */
		uint32_t addr		: 8; /* TWSI slave address */
	} s;
} mcu_twsi_t;

typedef struct board_fdt {
	char board_model[64];
	int bmc_boot_twsi_node;
	int bmc_boot_twsi_bus;
	int bmc_boot_twsi_addr;
	int bmc_ipmi_twsi_node;
	int bmc_ipmi_twsi_bus;
	int bmc_ipmi_twsi_addr;
	int gpio_shutdown_ctl_in;
	int gpio_shutdown_ctl_out;
#if TRUSTED_BOARD_BOOT
	uint64_t trust_rot_addr;
	uint64_t trust_key_addr;
#endif
	rvu_config_t rvu_config;
	cgx_config_t cgx_cfg[MAX_CGX];
	boot_device_conf_t boot_dev;
	mcu_twsi_t mcu_twsi;
} board_fdt_t;

int cavm_fill_board_details(int info);
int plat_fill_board_details(int info);
int octeontx2_get_lane_num(int qlm);

extern board_fdt_t *bfdt;

#endif
