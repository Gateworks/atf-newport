/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <arch.h>
#include <platform_def.h>
#include <asm_macros.S>
#include <assert_macros.S>
#include <cpu_macros.S>
#include <pl011.h>
#include <console.h>

	/* Global functions */
	.globl	plat_is_my_cpu_primary
	.globl	plat_get_my_entrypoint
	.globl	plat_secondary_cold_boot_setup
	.globl	plat_crash_console_init
	.globl	plat_crash_console_putc
	.globl	platform_mem_init
	.globl	octeontx_sec_entry_point

	.weak octeontx_io_trap_handler

	/* -----------------------------------------------------
	 * unsigned int plat_is_my_cpu_primary(void);
	 *
	 * This function checks if this is the Primary CPU
	 * -----------------------------------------------------
	 */
func plat_is_my_cpu_primary
	mrs	x0, mpidr_el1
	and	x0, x0, #(MPIDR_CLUSTER_MASK | MPIDR_CPU_MASK | MPIDR_NODE_MASK)
	cmp	x0, #OCTEONTX_PRIMARY_CPU
	cset	x0, eq
	ret
endfunc plat_is_my_cpu_primary

	/* -----------------------------------------------------
	 * unsigned long plat_get_my_entrypoint (void);
	 *
	 * Main job of this routine is to distinguish between
	 * a cold and warm boot. If the octeontx_sec_entry_point for
	 * this CPU is present, then it's a warm boot.
	 *
	 * -----------------------------------------------------
	 */
func plat_get_my_entrypoint
	adr	x1, octeontx_sec_entry_point
	ldr	x0, [x1]
	ret
endfunc plat_get_my_entrypoint

	/* -----------------------------------------------------
	 * void plat_secondary_cold_boot_setup (void);
	 *
	 * This function performs any platform specific actions
	 * needed for a secondary cpu after a cold reset. Right
	 * now this is a stub function.
	 * -----------------------------------------------------
	 */
func plat_secondary_cold_boot_setup

	mov_imm	x0, MAILBOX_BASE
	/* Wait until the entrypoint gets populated.
	 * In current implementation it will be always bl31_warm_entrypoint.
	 * Secondary CPU will be trapped until all initializations will be done.
	 */
poll_mailbox:
	ldr	x1, [x0]
	cbz	x1, 1f
	br	x1
1:
	wfe
	b	poll_mailbox
endfunc plat_secondary_cold_boot_setup

	/* ---------------------------------------------
	 * int plat_crash_console_init(void)
	 * Function to initialize the crash console
	 * without a C Runtime to print crash report.
	 * Clobber list : x0, x1, x2, x3, x4, x6, x7, x14
	 * ---------------------------------------------
	 */
func plat_crash_console_init
	/* Save link register */
	mov	x4, x30
	/* Switch to crash console */
	mov	w0, #CONSOLE_FLAG_CRASH
	bl	console_switch_state
	/* Register UAA0 as pl011 console */
	mov_imm	x0, 0x87E028000000
	mov_imm	x1, 7273800
	mov_imm	x2, 115200
	adr	x3, console_struct
	bl	console_pl011_register
	/* Switch registered console to crash console */
	adr	x0, console_struct
	mov	w1, #CONSOLE_FLAG_CRASH
	bl	console_set_scope
	mov	x30, x4
	ret
endfunc plat_crash_console_init

	/* ---------------------------------------------
	 * int plat_crash_console_putc(int c)
	 * Function to print a character on the crash
	 * console without a C Runtime.
	 * Clobber list : x1, x2
	 * ---------------------------------------------
	 */
func plat_crash_console_putc
	mov_imm	x1, 0x87E028000000
	/* ---------------------------------------------
	 * Link register (x30) is not altered, ret from
	 * console_putc will return from this function
	 * ---------------------------------------------
	 */
	b	console_putc
endfunc plat_crash_console_putc

	/* --------------------------------------------------------
	 * void platform_mem_init (void);
	 *
	 * Any memory init, relocation to be done before the
	 * platform boots. Called very early in the boot process.
	 * --------------------------------------------------------
	 */
func platform_mem_init
	ret
endfunc platform_mem_init

	.data
	.align 3

	/* --------------------------------------------------
	 * CPU Secure entry point - resume from suspend
	 * --------------------------------------------------
	 */
octeontx_sec_entry_point:
	.quad	0

	/* --------------------------------------------------
	 * Reserve space for console_pl011_t structure
	 * --------------------------------------------------
	 */
console_struct:
	.space	CONSOLE_T_PL011_BASE + REGSZ

func octeontx_io_trap_handler
	ret
endfunc octeontx_io_trap_handler
