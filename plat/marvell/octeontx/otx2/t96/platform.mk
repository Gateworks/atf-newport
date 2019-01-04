# Copyright (C) 2016-2018 Marvell International Ltd.
#
# SPDX-License-Identifier:     BSD-3-Clause
# https://spdx.org/licenses

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
				drivers/marvell/phy_gen.c		\
				drivers/marvell/phy_vitesse.c		\
				drivers/marvell/phy_mgmt.c		\
				drivers/marvell/sfp_mgmt.c		\
				drivers/marvell/cgx_intf.c		\
				plat/marvell/octeontx/otx2/plat_pm.c			\
				plat/marvell/octeontx/otx2/plat_pwrc.c		\
				plat/marvell/octeontx/otx2/plat_scmi.c		\
				plat/marvell/octeontx/otx2/plat_flr.c		\
				plat/marvell/octeontx/otx2/cavm_npc_mcam_profile.c	\
				plat/marvell/octeontx/otx2/t96/plat_t96_legacy_pm_ops.c  \

ifdef NT_FW_CONFIG
    $(eval $(call add_define,NT_FW_CONFIG))
endif
