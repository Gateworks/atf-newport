/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <octeontx_common.h>
#include <debug.h>
#include <plat_scfg.h>
#include <octeontx_scfg_bl1.h>
#include <octeontx_plat_configuration.h>

WEAK int plat_octeontx_fill_soc_details(void) {
	return 0;
}

int octeontx_fill_soc_details()
{
	int rc, lmc, sata;

	for (lmc = 0; lmc < MAX_LMC; lmc++) {
		plat_octeontx_scfg->scfg.is_lmc_enabled[lmc] = plat_octeontx_is_lmc_enabled(lmc);
	}

	for (sata = 0; sata < MAX_SATA; sata++) {
		plat_octeontx_scfg->scfg.sata_cfg.to_gser[sata] = plat_octeontx_sata_to_gser(sata);
		plat_octeontx_scfg->scfg.sata_cfg.to_lane[sata] = plat_octeontx_sata_to_lane(sata);
	}

	rc = plat_octeontx_fill_soc_details();
	if(rc) {
		WARN("Collecting family SoC details failed\n");
		return rc;
	}

	return 0;
}
