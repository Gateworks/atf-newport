/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_SCFG_H__
#define __OCTEONTX_SCFG_H__

#include <platform_scfg.h>

#if defined(PLAT_t83) || defined(PLAT_t81)
typedef struct sata_cfg {
	int to_gser[MAX_SATA];
	int to_lane[MAX_SATA];
} sata_cfg_t;
#endif

typedef struct scfg {
	uint8_t is_lmc_enabled[MAX_LMC];
#if defined(PLAT_t83) || defined(PLAT_t81)
	sata_cfg_t sata_cfg;
#endif
} scfg_t;

#endif /* __OCTEONTX_SCFG_H__ */
