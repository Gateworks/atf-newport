/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLAT_OTX2_CONFIGURATION_H__
#define __PLAT_OTX2_CONFIGURATION_H__

#define CN93XX_PKG   1
#define CN95XXE_PKG  3

int plat_octeontx_get_iobn_count(void);
int plat_octeontx_get_cpt_count(void);
int plat_octeontx_get_cgx_count(void);
int plat_octeontx_get_gser_count(void);
int plat_octeontx_get_mcc_count(void);
int plat_get_altpkg(void);
int plat_get_ooo_status(void);

#endif /* __PLAT_OTX2_CONFIGURATION_H__ */
