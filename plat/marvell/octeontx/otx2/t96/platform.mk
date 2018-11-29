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

PLAT_BL_COMMON_SOURCES	+=	plat/marvell/octeontx/otx2/t96/plat_t96_setup.c		\
				plat/marvell/octeontx/otx2/plat_security.c		\
				plat/marvell/octeontx/otx2/plat_bcfg_init.c		\
				drivers/marvell/phy_mgmt.c		\
				drivers/marvell/sfp_mgmt.c		\
				drivers/marvell/cgx_intf.c		\
				drivers/marvell/cgx.c		\
				plat/marvell/octeontx/otx2/plat_setup.c		\

BL1_SOURCES		+=	plat/marvell/octeontx/otx2/aarch64/plat_octeontx_common.S	\
				plat/marvell/octeontx/otx2/aarch64/plat_helpers.S	\
				plat/marvell/octeontx/otx2/plat_board_cfg.c	\
				plat/marvell/octeontx/otx2/plat_scfg.c	\

BL2_SOURCES		+=	plat/marvell/octeontx/otx2/t96/plat_t96_ecam.c		\
				drivers/marvell/rvu.c		\

BL31_SOURCES		+=	plat/marvell/octeontx/otx2/aarch64/plat_octeontx_common.S	\
				plat/marvell/octeontx/otx2/t96/plat_t96_flr.S			\
				plat/marvell/octeontx/otx2/aarch64/plat_helpers.S	\
				plat/marvell/octeontx/otx2/plat_topology.c		\
				drivers/marvell/rvu.c		\
				plat/marvell/octeontx/otx2/plat_pm.c			\
				plat/marvell/octeontx/otx2/plat_pwrc.c		\
				plat/marvell/octeontx/otx2/plat_scmi.c		\
				plat/marvell/octeontx/otx2/plat_flr.c		\
