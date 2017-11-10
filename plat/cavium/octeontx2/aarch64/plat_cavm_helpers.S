/** @file

  Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <platform_def.h>
#include <asm_macros.S>
#include <assert_macros.S>
#include <cpu_macros.S>

	/* Global functions */
	.globl	plat_my_core_pos

	/* -----------------------------------------------------
	 * unsigned int plat_my_core_pos(void);
	 *
	 * result: CorePos = (CoreId  * 4) + ClusterId
	 * -----------------------------------------------------
	 */
func plat_my_core_pos
	mrs	x0, CVM_PN_EL1
	and	x0, x0, #0xFFFF
	ret
endfunc plat_my_core_pos
