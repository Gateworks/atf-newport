/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLAT_OTX_CONFIGURATION_H__
#define __PLAT_OTX_CONFIGURATION_H__

#if defined(PLAT_t83) || defined(PLAT_t81)
int plat_octeontx_sata_to_gser(int ctrlr);
int plat_octeontx_sata_to_lane(int ctrlr);
#endif

#endif /* __PLAT_OTX_CONFIGURATION_H__ */
