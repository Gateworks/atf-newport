/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <arch.h>
#include <asm_macros.S>
#include <bl_common.h>
#include <cpu_macros.S>
#include <plat_macros.S>

func octeontx2_reset_func
	ret
endfunc octeontx2_reset_func

func octeontx2_core_pwr_dwn
	ret
endfunc octeontx2_core_pwr_dwn

func octeontx2_cluster_pwr_dwn
	ret
endfunc octeontx2_cluster_pwr_dwn

func octeontx2_cpu_reg_dump
	ret
endfunc octeontx2_cpu_reg_dump

declare_cpu_ops octeontx2, OCTEONTX2_CN96XX_MIDR, \
	octeontx2_reset_func, \
	octeontx2_core_pwr_dwn, \
	octeontx2_cluster_pwr_dwn
