#/** @file
#
#  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#**/

# Include common Marvell platform's makefile helper
include plat/marvell/octeontx/platform.mk

PLAT_INCLUDES		+=	-Iinclude/plat/marvell/octeontx/otx			\
				-Iplat/marvell/octeontx/otx/t81/include		\

PLAT_BL_COMMON_SOURCES	+=	plat/marvell/octeontx/otx/t81/plat_cavm_setup.c	\
				plat/marvell/octeontx/otx/cavm_security.c		\
				plat/marvell/octeontx/otx/cavm_bcfg_init.c		\
				plat/marvell/octeontx/otx/cavm_setup.c		\

BL1_SOURCES		+=	plat/marvell/octeontx/otx/aarch64/octeontx_common.S	\
				plat/marvell/octeontx/otx/aarch64/plat_cavm_helpers.S	\
				plat/marvell/octeontx/otx/cavm_octeontx_dt.c		\

BL2_SOURCES		+=	plat/marvell/octeontx/otx/t81/plat_cavm_ecam.c	\

BL31_SOURCES		+=	plat/marvell/octeontx/otx/aarch64/octeontx_common.S	\
				plat/marvell/octeontx/otx/aarch64/plat_cavm_helpers.S	\
				plat/marvell/octeontx/otx/cavm_topology.c		\
