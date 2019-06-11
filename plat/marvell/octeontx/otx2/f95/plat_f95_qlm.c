/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <octeontx_common.h>
#include <platform_scfg.h>
#include <qlm.h>

/* QLMx => GSERx mapping for f95 A0 */
#define GSERN_MIN_A0		0		/* QLM0 => GSERN */
#define GSERN_MAX_A0		(MAX_QLM - 1)	/* QLM3 => GSERN */

qlm_state_lane_t plat_otx2_get_qlm_state_lane(int qlm, int lane)
{
	qlm_state_lane_t state;
	int gsern_min, gsern_max;

	gsern_min = GSERN_MIN_A0;
	gsern_max = GSERN_MAX_A0;

	if (qlm >= gsern_min && qlm <= gsern_max) {
		state.u = CSR_READ(CAVM_GSERNX_LANEX_SCRATCHX(
						qlm - gsern_min, lane, 0));
	} else {
		state.u = 0;
		state.s.mode = QLM_MODE_DISABLED;
	}

	return state;
}

