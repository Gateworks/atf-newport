/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLAT_BOARD_CFG_H__
#define __PLAT_BOARD_CFG_H__

#include <octeontx_board_cfg.h>

typedef struct plat_octeontx_board_cfg {
	board_cfg_t bcfg;

	int gpio_intercept_intr;
} plat_octeontx_board_cfg_t;

extern plat_octeontx_board_cfg_t * const plat_octeontx_bcfg;

#endif /* __PLAT_BOARD_CFG__ */
