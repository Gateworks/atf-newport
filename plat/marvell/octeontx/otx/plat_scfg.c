/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <octeontx_common.h>
#include <plat_scfg.h>
#include <octeontx_scfg_bl1.h>
#include <plat_otx_configuration.h>
#include <assert.h>

int plat_octeontx_fill_soc_details(void)
{
	int sata;

	for (sata = 0; sata < MAX_SATA; sata++) {
		plat_octeontx_scfg->scfg.sata_cfg.to_gser[sata] = plat_octeontx_sata_to_gser(sata);
		plat_octeontx_scfg->scfg.sata_cfg.to_lane[sata] = plat_octeontx_sata_to_lane(sata);
	}

	return 0;
}
