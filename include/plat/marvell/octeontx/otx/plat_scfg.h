/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __PLAT_SCFG_H__
#define __PLAT_SCFG_H__

#include <octeontx_scfg.h>
#include <platform_scfg.h>

typedef struct plat_octeontx_scfg {
	scfg_t scfg;
} plat_octeontx_scfg_t;

extern plat_octeontx_scfg_t * const plat_octeontx_scfg;

#endif /* __PLAT_SCFG_H__ */
