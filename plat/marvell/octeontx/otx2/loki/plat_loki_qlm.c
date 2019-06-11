/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/*
 * QLM driver for OcteonTX2.
 * Contains ATF specific functions, not implemented in qlm.c
 */

#include <octeontx_common.h>
#include <qlm.h>

/* QLMx => GSERx mapping for loki A0 */
#define GSERR_MIN_A0		1	/* QLM1 => GSERR */
#define GSERR_MAX_A0		1	/* QLM1 => GSERR */
#define GSERC_MIN_A0		2	/* DLM2 => GSERC */
#define GSERC_MAX_A0		6	/* DLM6 => GSERC */

qlm_state_lane_t plat_otx2_get_qlm_state_lane(int qlm, int lane)
{
	qlm_state_lane_t state;
	int gserr_min, gserr_max;
	int gserc_min, gserc_max;

	gserr_min = GSERR_MIN_A0;
	gserr_max = GSERR_MAX_A0;
	gserc_min = GSERC_MIN_A0;
	gserc_max = GSERC_MAX_A0;

	if (qlm >= gserr_min && qlm <= gserr_max) {
		state.u = CSR_READ(CAVM_GSERRX_SCRATCHX(qlm - gserr_min, lane));
	} else if (qlm >= gserc_min && qlm <= gserc_max) {
		state.u = CSR_READ(CAVM_GSERCX_SCRATCHX(qlm - gserc_min, lane));
	} else {
		state.u = 0;
		state.s.mode = QLM_MODE_DISABLED;
	}

	return state;
}
