/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLAT_SCFG_H__
#define __PLAT_SCFG_H__

#include <octeontx_scfg.h>
#include <platform_scfg.h>

typedef struct plat_octeontx_scfg {
	scfg_t scfg;

	uint8_t qlm_max_lane_num[MAX_QLM];
	uint8_t iobn_count;
	uint8_t cgx_count;
	uint8_t gser_count;
	uint8_t mcc_count;
} plat_octeontx_scfg_t;

extern plat_octeontx_scfg_t * const plat_octeontx_scfg;

#endif /* __PLAT_SCFG_H__ */
