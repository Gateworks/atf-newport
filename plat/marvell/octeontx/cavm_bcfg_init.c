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

plat_octeontx_board_cfg_t * const plat_octeontx_bcfg = (void *)BOARD_CFG_BASE;

/*
 * Check if board_cfg_t fits in the memory region reserved
 * for board_cfg_t structure to make sure we do not modify
 * not-preserved memory.
 */
CASSERT(sizeof(plat_octeontx_board_cfg_t) < BOARD_CFG_MAX_SIZE,
  plat_octeontx_board_cfg_t__is_larger_then__BOARD_CFG_MAX_SIZE);
