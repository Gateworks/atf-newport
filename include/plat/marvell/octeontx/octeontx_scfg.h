/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __OCTEONTX_SCFG_H__
#define __OCTEONTX_SCFG_H__

#include <platform_scfg.h>

typedef struct sata_cfg {
	uint8_t to_gser[MAX_SATA];
	uint8_t to_lane[MAX_SATA];
} sata_cfg_t;

typedef struct scfg {
	uint8_t is_lmc_enabled[MAX_LMC];
	sata_cfg_t sata_cfg;
} scfg_t;

#endif /* __OCTEONTX_SCFG_H__ */
