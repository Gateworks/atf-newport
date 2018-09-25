/** @file

    Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _CAVM_DT_H_
#define _CAVM_DT_H_

#include <cavm_board_cfg.h>

typedef struct plat_octeontx_board_cfg {
	board_cfg_t bcfg;

	int gpio_intercept_intr;
} plat_octeontx_board_cfg_t;

int plat_fill_board_details(int info);
int octeontx_fill_board_details(int info);

extern plat_octeontx_board_cfg_t *plat_octeontx_bcfg;

#endif
