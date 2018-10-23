/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_SCFG_H__
#define __CAVM_SCFG_H__

#include <platform_scfg.h>

typedef struct sata_cfg {
	uint8_t sata_count;
	uint8_t to_gser[MAX_SATA];
	uint8_t to_lane[MAX_SATA];
} sata_cfg_t;

typedef struct lmc_cfg {
	uint8_t lmc_count;
	uint8_t is_enabled[MAX_LMC];
} lmc_cfg_t;

typedef struct scfg {
	lmc_cfg_t lmc_cfg;
	sata_cfg_t sata_cfg;
} scfg_t;

#endif /* __CAVM_SCFG_H__ */
