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

#define OCTEONTX_CN81XX_MIDR            0x430F0A20
#define OCTEONTX_CN83XX_MIDR            0x430F0A30

func octeontx_reset_func
	ret
endfunc octeontx_reset_func

func octeontx_core_pwr_dwn
	ret
endfunc octeontx_core_pwr_dwn

func octeontx_cluster_pwr_dwn
	ret
endfunc octeontx_cluster_pwr_dwn

func octeontx_cpu_reg_dump
	ret
endfunc octeontx_cpu_reg_dump

declare_cpu_ops octeontx, OCTEONTX_CN81XX_MIDR, \
	octeontx_reset_func, \
	octeontx_core_pwr_dwn, \
	octeontx_cluster_pwr_dwn

declare_cpu_ops octeontx, OCTEONTX_CN83XX_MIDR, \
	octeontx_reset_func, \
	octeontx_core_pwr_dwn, \
	octeontx_cluster_pwr_dwn
