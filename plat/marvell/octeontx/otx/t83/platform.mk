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
				-Iplat/marvell/octeontx/otx/t83/include		\

PLAT_BL_COMMON_SOURCES	+=	plat/marvell/octeontx/otx/t83/plat_t83_setup.c	\
				plat/marvell/octeontx/otx/plat_security.c		\
				plat/marvell/octeontx/otx/plat_bcfg_init.c		\
				plat/marvell/octeontx/otx/plat_setup.c		\

BL1_SOURCES		+=	plat/marvell/octeontx/otx/aarch64/plat_octeontx_common.S	\
				plat/marvell/octeontx/otx/aarch64/plat_helpers.S	\
				plat/marvell/octeontx/otx/plat_board_cfg.c		\

BL2_SOURCES		+=	plat/marvell/octeontx/otx/t83/plat_t83_ecam.c	\

BL31_SOURCES		+=	plat/marvell/octeontx/otx/aarch64/plat_octeontx_common.S	\
				plat/marvell/octeontx/otx/aarch64/plat_helpers.S	\
				plat/marvell/octeontx/otx/plat_topology.c		\
