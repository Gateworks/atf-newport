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
#include <platform_setup.h>
#include <cavm_octeontx_scfg.h>
#include <cavm_scfg_bl1.h>
#include <cavm_otx2_configuration.h>

static void fill_qlm_max_lane_num(void)
{
	int qlm;

	for (qlm = 0; qlm < MAX_QLM; qlm++) {
		plat_octeontx_scfg->qlm_max_lane_num[qlm] = plat_get_max_lane_num(qlm);
	}
}

int plat_octeontx_fill_soc_details(void)
{
	plat_octeontx_scfg->iobn_count = plat_octeontx_get_iobn_count();
	fill_qlm_max_lane_num();

	return 0;
}
