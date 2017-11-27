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

declare_cpu_ops octeontx2, OCTEONTX2_CN93XX_MIDR, \
	octeontx2_reset_func, \
	octeontx2_core_pwr_dwn, \
	octeontx2_cluster_pwr_dwn
