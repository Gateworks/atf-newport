/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <arch.h>
#include <platform_def.h>
#include <asm_macros.S>
#include <assert_macros.S>
#include <cpu_macros.S>
#include <bl_common.h>
#include <pl011.h>
#include <console.h>

	.globl	plat_report_exception

	/* -----------------------------------------------------
	 * void plat_report_exception(unsigned int);
	 *
	 * This function print reported exception.
	 * Possible values of x0 are defined in bl_common.h
	 * Clobber list : x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x14
	 * -----------------------------------------------------
	 */
func plat_report_exception
	/* Save link register */
	mov	x8, x30
	mov	x10, x0
	bl	plat_crash_console_init

	adr	x4, plat_err_str
	bl	asm_print_str

	adr	x4, error_code_str
	bl	asm_print_str
	mov	x4, x10
	bl	asm_print_hex

	mrs	x2, currentel
	and	x2, x2, #0x0c
	/* Check EL1 */
	cmp	x2, #0x04
	beq	plat_report_el1

	adr	x4, el3_str
	bl	asm_print_str

	adr	x4, esr_str
	bl	asm_print_str
	mrs	x4, esr_el3
	bl	asm_print_hex

	adr	x4, elr_str
	bl	asm_print_str
	mrs	x4, elr_el3
	bl	asm_print_hex

	adr	x4, spsr_str
	bl	asm_print_str
	mrs	x4, spsr_el3
	bl	asm_print_hex

	adr	x4, far_str
	bl	asm_print_str
	mrs	x4, far_el3
	bl	asm_print_hex

	b	plat_report_end

plat_report_el1:
	adr	x4, el1_str
	bl	asm_print_str

	adr	x4, esr_str
	bl	asm_print_str
	mrs	x4, esr_el1
	bl	asm_print_hex

	adr	x4, elr_str
	bl	asm_print_str
	mrs	x4, elr_el1
	bl	asm_print_hex

	adr	x4, spsr_str
	bl	asm_print_str
	mrs	x4, spsr_el1
	bl	asm_print_hex

	adr	x4, far_str
	bl	asm_print_str
	mrs	x4, far_el1
	bl	asm_print_hex
plat_report_end:
	adr	x4, newline_str
	bl	asm_print_str
	mov	x30, x8
	ret
endfunc plat_report_exception


.section .rodata.octeontx_crash_prints, "aS"
plat_err_str:
	.asciz "\nPlatform exception reporting:"
error_code_str:
	.asciz "\nError code: 0x"
el3_str:
	.asciz "\nEL3"
el1_str:
	.asciz "\nEL1s"
esr_str:
	.asciz "\nESR:  0x"
elr_str:
	.asciz "\nELR:  0x"
spsr_str:
	.asciz "\nSPSR: 0x"
far_str:
	.asciz "\nFAR:  0x"
newline_str:
	.asciz "\n"
