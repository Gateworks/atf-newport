/** @file

  Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
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
