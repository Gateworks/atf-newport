/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_BOARD_CFG_BL1_H__
#define __OCTEONTX_BOARD_CFG_BL1_H__

// function used to fill bcfg with common data
int octeontx_fill_board_details(int info);

// function called by common code to fill bcfg with family specific infromation
int plat_octeontx_fill_board_details(void);

// function to print family specific information
void plat_octeontx_print_board_variables(void);

#endif /* __OCTEONTX_BOARD_CFG_BL1_H__ */