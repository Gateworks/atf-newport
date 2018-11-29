/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __OCTEONTX_BOARD_CFG_BL1_H__
#define __OCTEONTX_BOARD_CFG_BL1_H__

// function used to fill bcfg with common data
int octeontx_fill_board_details(int info);

// function called by common code to fill bcfg with family specific infromation
int plat_octeontx_fill_board_details(void);

// function to print family specific information
void plat_octeontx_print_board_variables(void);

#endif /* __OCTEONTX_BOARD_CFG_BL1_H__ */