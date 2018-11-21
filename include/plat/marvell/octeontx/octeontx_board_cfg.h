/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_BOARD_CFG_H__
#define __OCTEONTX_BOARD_CFG_H__

typedef struct boot_device_conf {
	int node;
	int boot_type;
	int controller;
	int cs;
} boot_device_conf_t;

typedef union mcu_twsi {
	uint32_t u;
	struct mcu_twsi_s {
		uint32_t int_addr	: 8; /* TWSI Internal Address */
		uint32_t bus		: 8; /* TWSI bus */
		uint32_t addr		: 8; /* TWSI slave address */
	} s;
} mcu_twsi_t;

typedef struct board_cfg {
	char board_model[64];
	int bmc_boot_twsi_bus;
	int bmc_boot_twsi_addr;
	int bmc_ipmi_twsi_bus;
	int bmc_ipmi_twsi_addr;
	int gpio_shutdown_ctl_in;
	int gpio_shutdown_ctl_out;
#if TRUSTED_BOARD_BOOT
	uint64_t trust_rot_addr;
	uint64_t trust_key_addr;
#endif
	boot_device_conf_t boot_dev;
	mcu_twsi_t mcu_twsi;
  
} board_cfg_t;

#endif /* __OCTEONTX_BOARD_CFG_H__ */