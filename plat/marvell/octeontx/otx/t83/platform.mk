# Copyright (C) 2016-2018 Marvell International Ltd.
#
# SPDX-License-Identifier:     BSD-3-Clause
# https://spdx.org/licenses

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
				plat/marvell/octeontx/otx/plat_scfg.c		\

BL2_SOURCES		+=	plat/marvell/octeontx/otx/t83/plat_t83_ecam.c	\

BL31_SOURCES		+=	plat/marvell/octeontx/otx/aarch64/plat_octeontx_common.S	\
				plat/marvell/octeontx/otx/aarch64/plat_helpers.S	\
				plat/marvell/octeontx/otx/plat_topology.c		\
				plat/marvell/octeontx/otx/plat_sata.c		\
