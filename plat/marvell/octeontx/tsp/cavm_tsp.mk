# Copyright (C) 2016-2017 Marvell International Ltd.
#
# SPDX-License-Identifier:     BSD-3-Clause
# https://spdx.org/licenses

BL32_SOURCES		+=	plat/marvell/common/tsp/cavm_tsp_setup.c		\
				plat/marvell/common/aarch64/cavm_helpers.S	\
				plat/marvell/common/cavm_gicv3.c		\
				plat/common/aarch64/platform_mp_stack.S		\
				plat/common/plat_gicv3.c
