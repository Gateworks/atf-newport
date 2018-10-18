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
include plat/marvell/common/platform.mk

ARM_ARCH_MINOR		:=	2

PLAT_INCLUDES		+=	-Iplat/marvell/octeontx2/include			\
				-Iplat/marvell/octeontx2/f95/include		\

PLAT_BL_COMMON_SOURCES	+=	plat/marvell/octeontx2/f95/plat_cavm_setup.c		\
				plat/marvell/octeontx2/cavm_security.c		\
				plat/marvell/octeontx2/cavm_octeontx2_dt.c	\
				plat/marvell/octeontx2/cavm_phy_mgmt.c		\
				plat/marvell/octeontx2/cavm_cgx_intf.c		\
				plat/marvell/octeontx2/cavm_cgx.c		\
				plat/marvell/octeontx2/cavm_setup.c		\

BL1_SOURCES		+=	plat/marvell/octeontx2/aarch64/octeontx2_common.S	\
				plat/marvell/octeontx2/aarch64/plat_cavm_helpers.S	\

BL2_SOURCES		+=	plat/marvell/octeontx2/f95/plat_cavm_ecam.c		\
				plat/marvell/octeontx2/cavm_rvu.c		\

BL31_SOURCES		+=	plat/marvell/octeontx2/aarch64/octeontx2_common.S	\
				plat/marvell/octeontx2/aarch64/plat_cavm_helpers.S	\
				plat/marvell/octeontx2/cavm_topology.c		\
				plat/marvell/octeontx2/cavm_rvu.c		\
				plat/marvell/octeontx2/cavm_pm.c			\
				plat/marvell/octeontx2/cavm_pwrc.c		\
				plat/marvell/octeontx2/cavm_scmi.c		\
