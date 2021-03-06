/*
 * Copyright (c) 2013-2017, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch.h>
#include <el3_common_macros.S>
#include <platform_def.h>

#if BL2_AT_EL3
#define ENTRYPOINT_FUNC_NAME	bl2_entrypoint
#else
#define ENTRYPOINT_FUNC_NAME	bl1_entrypoint
#endif

	.globl	plat_reset_handler
#if !BL2_AT_EL3
	.globl	bl1_entrypoint

	/* -----------------------------------------------------
	 * bl1_entrypoint() is the entry point into the trusted
	 * firmware code when a cpu is released from warm or
	 * cold reset.
	 * -----------------------------------------------------
	 */

func bl1_entrypoint
	/* ---------------------------------------------------------------------
	 * If the reset address is programmable then bl1_entrypoint() is
	 * executed only on the cold boot path. Therefore, we can skip the warm
	 * boot mailbox mechanism.
	 * ---------------------------------------------------------------------
	 */
	el3_entrypoint_common					\
		_init_sctlr=1					\
		_warm_boot_mailbox=!PROGRAMMABLE_RESET_ADDRESS	\
		_secondary_cold_boot=!COLD_BOOT_SINGLE_CPU	\
		_init_memory=1					\
		_init_c_runtime=1				\
		_exception_vectors=bl1_exceptions

	/* ---------------------------------------------
	 * Architectural init. can be generic e.g.
	 * enabling stack alignment and platform spec-
	 * ific e.g. MMU & page table setup as per the
	 * platform memory map. Perform the latter here
	 * and the former in bl1_main.
	 * ---------------------------------------------
	 */
	bl	bl1_early_platform_setup
	bl	bl1_plat_arch_setup

	/* --------------------------------------------------
	 * Initialize platform and jump to our c-entry point
	 * for this type of reset.
	 * --------------------------------------------------
	 */
	bl	bl1_main

	/*
	 * Apply errata #30471 - AP_HCR_EL2[BSU].
	 * No need to keep the previous state of AP_HCR_EL2[BSU]
	 * since not yet configured by KVM/Xen.
	 * In future when we'll support runtime switching to S-BL1,
	 * (not only for the BL2 image, as done now),
	 * it will be required to save context of HCR_EL2[BSU].
	 */
	bl	errata_30471

	/* --------------------------------------------------
	 * Do the transition to next boot image.
	 * --------------------------------------------------
	 */
	b	el3_exit
endfunc bl1_entrypoint
#endif /* !BL2_AT_EL3 */

	/*
	 * octeontx_relocation function set this variable to 1 when
	 * it relocate code.
	 */
is_reloc_done:
	.quad 0

	/* --------------------------------------------------------
	 * void plat_reset_handler (void);
	 *
	 * Platform specific configuration right after cpu is
	 * is our of reset.
	 *
	 * The plat_reset_handler can clobber x0 - x18, x30.
	 * --------------------------------------------------------
	 */
func plat_reset_handler
	mov	x18, x30
	adr	x0, is_reloc_done
	ldr	x0, [x0]
	cmp	x0, 0
	b.ne	reloc_done
	bl	octeontx_relocation
reloc_done:
	mov	x30, x18
	ret
endfunc plat_reset_handler

	/* --------------------------------------------------------
	 * void octeontx_relocation (int);
	 *
	 * x1 - points to FDT generated by BDK
	 *
	 * This function copy FDT and relocate code to the linker
	 * address. After relocation (if needed) it jumps to
	 * relocated bl1_entrypoint.
	 *
	 * The octeontx_relocation can clobber x0 - x17, x30.
	 * --------------------------------------------------------
	 */
func octeontx_relocation
	mov	x17, x30
	/*
	 * x1 - points to FDT generated by BDK. Instructions from entrypoint
	 * to this place shouldn't change x1. Copy FDT to desired location.
	 */
	adr	x2, fdt_ptr
	ldr	x0, =FDT_BASE
	str	x0, [x2]
	mov	x2, #FDT_MAX_SIZE
	bl	copy_data

	/*
	 * Relocate to the linker address.
	 * Code to this place is position independent so it can be done there.
	 */
	ldr     x0, =ENTRYPOINT_FUNC_NAME        /* linker address */
	adr     x1, ENTRYPOINT_FUNC_NAME /* get the loaded address */
	cmp     x0, x1
	b.eq    reloc_end

	ldr	x2, =__RO_START__
	ldr	x3, =__DATA_RAM_END__
	sub	x2, x3, x2 /* size of relocatable part */
reloc_loop:
	ldp     q0, q1, [x1], 32
	subs    w2, w2, 32
	stp     q0, q1, [x0], 32
	b.gt    reloc_loop
	dmb     sy
	ic      ialluis
	dsb     sy
	/* Relocation done, update is_reloc_done variable in relocated code */
	ldr	x0, =is_reloc_done
	mov_imm	x1, 1
	str	x1, [x0]
	/* Jump to relocated entrypoint */
	ldr     x0, =ENTRYPOINT_FUNC_NAME
	br      x0
reloc_end:
	mov	x30, x17
	ret
endfunc octeontx_relocation

func copy_data
copy_loop:
	ldr     x23, [x1]
	str     x23, [x0]
	sub     x2, x2, #8
	add     x1, x1, #8
	add     x0, x0, #8
	cbnz    x2, copy_loop
	ret
endfunc copy_data

func errata_30471
	mrs	x23, S3_0_C0_C0_0
	ldr	x24, =0x00F00F00 //Mask for pass 1.x, T81/T83
	and	x23, x23, x24
	cmp	x23, #0x00000A00 //If pass 1.x, T81/T83
	b.ne	invalid_pass
	mrs	x23, HCR_EL2
	bic	x23, x23, #HCR_BSU0_BIT
	bic	x23, x23, #HCR_BSU1_BIT
	msr	HCR_EL2, x23
invalid_pass:
	ret
endfunc errata_30471
