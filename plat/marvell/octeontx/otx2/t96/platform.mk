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

PLAT_XLAT_TABLES_DYNAMIC := 1
$(eval $(call add_define,PLAT_XLAT_TABLES_DYNAMIC))

ARM_ARCH_MINOR		:=	2

PLAT_INCLUDES		+=	-Iinclude/plat/marvell/octeontx/otx2			\
				-Iplat/marvell/octeontx/otx2/t96/include		\

PLAT_BL_COMMON_SOURCES	+=	plat/marvell/octeontx/otx2/t96/plat_cavm_setup.c		\
				plat/marvell/octeontx/otx2/cavm_security.c		\
				plat/marvell/octeontx/otx2/cavm_bcfg_init.c		\
				drivers/marvell/phy_mgmt.c		\
				drivers/marvell/sfp_mgmt.c		\
				drivers/marvell/cgx_intf.c		\
				drivers/marvell/cgx.c		\
				plat/marvell/octeontx/otx2/cavm_setup.c		\

BL1_SOURCES		+=	plat/marvell/octeontx/otx2/aarch64/octeontx2_common.S	\
				plat/marvell/octeontx/otx2/aarch64/plat_cavm_helpers.S	\
				plat/marvell/octeontx/otx2/cavm_octeontx2_dt.c	\
				plat/marvell/octeontx/otx2/cavm_octeontx_scfg.c	\

BL2_SOURCES		+=	plat/marvell/octeontx/otx2/t96/plat_cavm_ecam.c		\
				drivers/marvell/rvu.c		\

BL31_SOURCES		+=	plat/marvell/octeontx/otx2/aarch64/octeontx2_common.S	\
				plat/marvell/octeontx/otx2/t96/plat_flr.S			\
				plat/marvell/octeontx/otx2/aarch64/plat_cavm_helpers.S	\
				plat/marvell/octeontx/otx2/cavm_topology.c		\
				drivers/marvell/rvu.c		\
				plat/marvell/octeontx/otx2/cavm_pm.c			\
				plat/marvell/octeontx/otx2/cavm_pwrc.c		\
				plat/marvell/octeontx/otx2/cavm_scmi.c		\
				plat/marvell/octeontx/otx2/cavm_flr.c		\
