/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_OTX2_CONFIGURATION_H__
#define __CAVM_OTX2_CONFIGURATION_H__

#define CN93XX_PKG   1
#define CN95XXE_PKG  3

int plat_octeontx_get_iobn_count(void);
int plat_octeontx_get_cpt_count(void);
int plat_octeontx_get_cgx_count(void);
int plat_octeontx_get_gser_count(void);
int plat_get_altpkg(void);

#endif /* __CAVM_OTX2_CONFIGURATION_H__ */
