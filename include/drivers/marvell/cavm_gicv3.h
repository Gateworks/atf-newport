/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_GICV3_H__
#define __CAVM_GICV3_H__

void octeontx_gic_driver_init(void);
void octeontx_gic_init(void);
void octeontx_gic_pcpu_init(void);
void octeontx_gic_cpuif_enable(void);
void octeontx_gic_cpuif_disable(void);

#endif /* __CAVM_GICV3_H__ */
