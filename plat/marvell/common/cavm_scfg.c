/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#include <cavm_common.h>
#include <debug.h>
#include <cavm_octeontx_scfg.h>
#include <cavm_scfg_bl1.h>

static void fill_sata_cfg() {
	int sata;

	plat_octeontx_scfg->scfg.sata_cfg.sata_count = plat_octeontx_get_sata_count();
	for (sata = 0; sata < plat_octeontx_scfg->scfg.sata_cfg.sata_count; sata++) {
		plat_octeontx_scfg->scfg.sata_cfg.to_gser[sata] = plat_octeontx_sata_to_gser(sata);
		plat_octeontx_scfg->scfg.sata_cfg.to_lane[sata] = plat_octeontx_sata_to_lane(sata);
	}
}


WEAK int plat_octeontx_fill_soc_details(void) {
	return 0;
}

int octeontx_fill_soc_details()
{
	int rc, lmc;

	for (lmc = 0; lmc < MAX_LMC; lmc++) {
		plat_octeontx_scfg->scfg.is_lmc_enabled[lmc] = plat_octeontx_is_lmc_enabled(lmc);
	}

	fill_sata_cfg();

	rc = plat_octeontx_fill_soc_details();
	if(rc) {
		WARN("Collecting family SoC details failed\n");
		return rc;
	}

	return 0;
}
