/** @file

  Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <asm_macros.S>
#include <bl_common.h>
#include <cpu_macros.S>
#include <plat_macros.S>
#include <context.h>

	.global cavm_io_trap_handler

/* Main entry point for Cavium-specific trapping mechanism */
func cavm_io_trap_handler
	/*
	 * Mainline save_x18_to_x29_sp_el0 macro is defined
	 * at runtime_exceptions.S, so platform code has to duplicate
	 * code to store GP regs on stack.
	 *
	 * Save GP registers on entrypoint.
	 */
	stp	x0, x1, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X0]
	stp	x2, x3, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X2]
	stp	x4, x5, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X4]
	stp	x6, x7, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X6]
	stp	x8, x9, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X8]
	stp	x10, x11, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X10]
	stp	x12, x13, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X12]
	stp	x14, x15, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X14]
	stp	x16, x17, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X16]
	stp	x18, x19, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X18]
	stp	x20, x21, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X20]
	stp	x22, x23, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X22]
	stp	x24, x25, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X24]
	stp	x26, x27, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X26]
	stp	x28, x29, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_X28]
	mrs	x18, sp_el0
	str	x18, [sp, #CTX_GPREGS_OFFSET + CTX_GPREG_SP_EL0]

	mov	x0, sp

	/*
	 * Restore the saved C runtime stack value which will become the new
	 * SP_EL0 i.e. EL3 runtime stack. It was saved in the 'cpu_context'
	 * structure prior to the last ERET from EL3.
	 */
	ldr	x12, [x0, #CTX_EL3STATE_OFFSET + CTX_RUNTIME_SP]
	msr	spsel, #0

	/*
	 * Save the SPSR_EL3, ELR_EL3, & SCR_EL3 for more scalability
	 * to use by el3_exit method.
	 *
	 * Since it's custom trap mechanism, we're forced to increment
	 * ELR_EL3 by 4 (for the next instruction) when we get back
	 * to previous ELx.
	 */
	mrs	x16, spsr_el3
	mrs	x17, elr_el3
	add	x17, x17, 4
	mrs	x18, scr_el3
	stp	x16, x17, [x0, #CTX_EL3STATE_OFFSET + CTX_SPSR_EL3]
	str	x18, [x0, #CTX_EL3STATE_OFFSET + CTX_SCR_EL3]

	mov	sp, x12

	/* Go to C trap handler and then immediately drop into el3_exit() */
	bl	cavm_trap_handler

	b	el3_exit
endfunc cavm_io_trap_handler

