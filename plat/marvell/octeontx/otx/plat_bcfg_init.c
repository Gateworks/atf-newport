/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <stdint.h>
#include <platform_def.h>
#include <cassert.h>
#include <plat_board_cfg.h>
#include <plat_scfg.h>

plat_octeontx_board_cfg_t * const plat_octeontx_bcfg = (void *)BOARD_CFG_BASE;

plat_octeontx_scfg_t * const plat_octeontx_scfg = (void *)BOARD_CFG_BASE + sizeof(plat_octeontx_board_cfg_t);

/*
 * Check if board_cfg_t and scfg_t fits in the memory region reserved
 * for these structures to make sure we do not modify
 * not-preserved memory.
 */
CASSERT((sizeof(plat_octeontx_board_cfg_t) + sizeof(plat_octeontx_scfg_t)) < BOARD_CFG_MAX_SIZE,
  plat_octeontx_board_cfg_t__is_larger_then__BOARD_CFG_MAX_SIZE);
