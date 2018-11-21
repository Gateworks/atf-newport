/*
 * Copyright (C) 2016-2017 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef PLAT_MACROS_S
#define PLAT_MACROS_S
#include <arch.h>
#include <platform_def.h>

.section .rodata.gic_reg_name, "aS"
gic_regs: .asciz "icc_ctlr", "icc_hppir0", "icc_hppir1", ""

	/* ---------------------------------------------
	 * The below macro prints out relevant GIC
	 * registers whenever an unhandled exception is
	 * taken in BL31.
	 * ---------------------------------------------
	 */
	.macro plat_crash_print_regs
	mrs	x8, ICC_CTLR_EL3
	mrs	x9, ICC_HPPIR0_EL1
	mrs	x10, ICC_HPPIR1_EL1
	adr	x6, gic_regs
	bl	str_in_crash_buf_print
	.endm

/* ------------------------------------------------
 * The below required platform porting macro prints
 * out relevant interconnect registers whenever an
 * unhandled exception is taken in BL3-1.
  * ------------------------------------------------
 */
.macro plat_print_interconnect_regs
	nop
.endm
#endif /* PLAT_MACROS_S */
