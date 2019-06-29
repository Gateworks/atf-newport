/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <octeontx_common.h>
#include <platform_setup.h>
#include <platform_dt.h>
#include <plat_scfg.h>
#include <octeontx_scfg_bl1.h>
#include <plat_otx2_configuration.h>
#include <assert.h>

static void fill_qlm_max_lane_num(void)
{
	int qlm;

	for (qlm = 0; qlm < plat_octeontx_scfg->gser_count; qlm++) {
		plat_octeontx_scfg->qlm_max_lane_num[qlm] = plat_get_max_lane_num(qlm);
	}
}

int plat_octeontx_fill_soc_details(void)
{
	plat_octeontx_scfg->iobn_count = plat_octeontx_get_iobn_count();
	plat_octeontx_scfg->cgx_count = plat_octeontx_get_cgx_count();
	assert(plat_octeontx_scfg->cgx_count <= MAX_CGX);
	plat_octeontx_scfg->gser_count = plat_octeontx_get_gser_count();
	plat_octeontx_scfg->mcc_count = plat_octeontx_get_mcc_count();
	fill_qlm_max_lane_num();

	return 0;
}
