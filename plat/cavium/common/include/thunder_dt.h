/** @file

    Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _THUNDER_DT_H_
#define _THUNDER_DT_H_

#define MAX_CGX			3
#define MAX_LMAC_PER_CGX	4

/* Total number of Hardware VFs */
#define RVU_HWVFS		256

/* Global, default number of VFs */
#define DEFAULT_VFS		8

/* Default number of VFs for PF0 (admin PF) */
#define DEFAULT_AF_PF0_VFS	0

/* Default number of VFs for PF15 (CPT PF) */
#define DEFAULT_CPT_PF15_VFS	64

/* Default number of MSIX vectors per PF (non-admin) */
#define DEFAULT_MSIX		128

/* Default number of MSIX vectors for AF PF */
#define DEFAULT_MSIX_AF		133

typedef struct cgx_lmac_cfg {
	int enable;
	int num_rvu_vfs;
	int num_msix_vec;
	/* More to be added in future */
} cgx_lmac_cfg_t;

typedef struct cgx_info {
	int enable;
	cgx_lmac_cfg_t lmac_cfg[MAX_LMAC_PER_CGX];
	/* More to be added in future */
} cgx_info_t;

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
	cgx_info_t cgx_pf[MAX_CGX];
	rvu_sw_rvu_pf_t sw_pf[SW_RVU_MAX_PF];
} rvu_config_t;

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
} board_fdt_t;

int thunder_fill_board_details(int info);

extern board_fdt_t bfdt;
#endif
