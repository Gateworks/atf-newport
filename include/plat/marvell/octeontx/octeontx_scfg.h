/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_SCFG_H__
#define __OCTEONTX_SCFG_H__

#include <platform_scfg.h>

typedef struct sata_cfg {
	int to_gser[MAX_SATA];
	int to_lane[MAX_SATA];
} sata_cfg_t;

typedef struct scfg {
	uint8_t is_lmc_enabled[MAX_LMC];
	sata_cfg_t sata_cfg;
} scfg_t;

#endif /* __OCTEONTX_SCFG_H__ */
