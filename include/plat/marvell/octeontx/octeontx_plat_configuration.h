/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __OCTEONTX_PLAT_CONFIGURATION_H__
#define __OCTEONTX_PLAT_CONFIGURATION_H__

int plat_octeontx_get_lmc_count(void);
int plat_octeontx_get_sata_count(void);
int plat_octeontx_sata_to_gser(int ctrlr);
int plat_octeontx_sata_to_lane(int ctrlr);
int plat_octeontx_is_lmc_enabled(unsigned lmc);

#endif /* __OCTEONTX_PLAT_CONFIGURATION_H__ */