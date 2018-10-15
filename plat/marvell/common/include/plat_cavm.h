/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __PLAT_CAVM_H__
#define __PLAT_CAVM_H__

void set_secondary_cpu_jump_addr(unsigned int bl1_base);

void plat_octeontx_setup(void);
void plat_pwrc_setup(void);

unsigned int plat_get_rom_t_cnt();

#endif /* __PLAT_CAVM_H__ */