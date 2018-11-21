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
	.globl	octeontx_calc_core_pos

	/* -----------------------------------------------------
	 * unsigned int plat_my_core_pos(void);
	 *
	 * result: CorePos = CoreId + (ClusterId << 4) + (NodeId << 6)
	 * -----------------------------------------------------
	 */
func plat_my_core_pos
	mrs	x0, mpidr_el1
	b	octeontx_calc_core_pos
endfunc plat_my_core_pos

func octeontx_calc_core_pos
	and	x1, x0, #MPIDR_CPU_MASK
	orr	x1, x1, x0, LSR #4
	and	x1, x1, #0x3f /* Cluster and Core ID */
	ubfx	x0, x0, 16, 2 /* Node ID */
	ldr	w2, =(PLATFORM_MAX_CLUSTERS_PER_NODE * PLATFORM_MAX_CPUS_PER_CLUSTER)
	umaddl	x0, w0, w2, x1
	ret
endfunc octeontx_calc_core_pos
