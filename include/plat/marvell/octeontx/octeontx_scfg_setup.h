/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_SCFG_SETUP_H__
#define __OCTEONTX_SCFG_SETUP_H__

// function used to fill scfg with common data
int octeontx_fill_soc_details();

// function called by common code to fill scfg with family specific infromation
int plat_octeontx_fill_soc_details(void);

#endif /* __OCTEONTX_SCFG_SETUP_H__ */
