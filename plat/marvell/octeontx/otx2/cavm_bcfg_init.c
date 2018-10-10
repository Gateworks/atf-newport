/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <stdint.h>
#include <platform_def.h>
#include <cassert.h>
#include <cavm_dt.h>
#include <cavm_octeontx_scfg.h>

plat_octeontx_board_cfg_t * const plat_octeontx_bcfg = (void *)BOARD_CFG_BASE;

plat_octeontx_scfg_t * const plat_octeontx_scfg = (void *)BOARD_CFG_BASE + sizeof(plat_octeontx_board_cfg_t);

/*
 * Check if board_cfg_t and scfg_t fits in the memory region reserved
 * for these structures to make sure we do not modify
 * not-preserved memory.
 */
CASSERT((sizeof(plat_octeontx_board_cfg_t) + sizeof(plat_octeontx_scfg_t)) < BOARD_CFG_MAX_SIZE,
  plat_octeontx_board_cfg_t__is_larger_then__BOARD_CFG_MAX_SIZE);
