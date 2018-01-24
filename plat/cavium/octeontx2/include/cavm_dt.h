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
	/* below info to be filled during run time
	 * by CGX driver
	 */
	octeontx_phy_link_state_t link_status;
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

extern board_fdt_t bfdt;
#endif
