/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_SCFG_BL1_H__
#define __CAVM_SCFG_BL1_H__

// function used to fill scfg with common data
int octeontx_fill_soc_details();

// function called by common code to fill scfg with family specific infromation
int plat_octeontx_fill_soc_details(void);

#endif /* __CAVM_SCFG_BL1_H__ */
