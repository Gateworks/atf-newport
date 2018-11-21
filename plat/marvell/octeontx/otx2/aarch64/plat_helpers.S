/*
 * Copyright (C) 2016-2017 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

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
