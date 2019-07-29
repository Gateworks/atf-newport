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
#include <qlm.h>
#include <sfp_mgmt.h>
#include <phy_mgmt.h>
#include <platform_scfg.h>
#include <octeontx_board_cfg.h>

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
	volatile int mdio_bus_dbg;
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
	uint32_t is_rfoe:1;
	uint16_t network_lane_order;
	cgx_lmac_config_t lmac_cfg[MAX_LMAC_PER_CGX];
} cgx_config_t;

typedef struct qlm_config {
	uint8_t lane_rx_polarity[MAX_LANES_PER_QLM];
	uint8_t lane_tx_polarity[MAX_LANES_PER_QLM];
	uint8_t lane_rx_prevga_gn_adapt[MAX_LANES_PER_QLM];
	uint8_t lane_rx_prevga_gn_ovrd[MAX_LANES_PER_QLM];
} qlm_config_t;

typedef struct mcc_ras_config {
	uint32_t lmcoe_count:8;
	uint32_t enabled:1;
} mcc_ras_config_t;

typedef struct plat_octeontx_board_cfg {
	board_cfg_t bcfg;
	rvu_config_t rvu_config;
	cgx_config_t cgx_cfg[MAX_CGX];
	qlm_config_t qlm_cfg[MAX_QLM];
	int qlm_voltage;
	mcc_ras_config_t mcc_ras_cfg[MAX_MCC];
	uint64_t pf_mac_base; /* PF MAC Address */
	int pf_mac_num;
} plat_octeontx_board_cfg_t;

extern plat_octeontx_board_cfg_t * const plat_octeontx_bcfg;

#endif /* __PLAT_BOARD_CFG_H__ */
