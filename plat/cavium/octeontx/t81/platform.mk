#/** @file
#
#  Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#**/

# Include common thunder platform's makefile helper
include plat/cavium/common/platform.mk

PLAT_INCLUDES		+=	-Iplat/cavium/octeontx/include			\
				-Iplat/cavium/octeontx/t81/include		\

PLAT_BL_COMMON_SOURCES	+=	plat/cavium/octeontx/t81/plat_cavm_setup.c	\
				plat/cavium/octeontx/cavm_security.c		\
				plat/cavium/octeontx/cavm_octeontx_dt.c		\
				plat/cavium/octeontx/cavm_setup.c		\

BL1_SOURCES		+=	plat/cavium/octeontx/aarch64/octeontx_common.S	\
				plat/cavium/octeontx/aarch64/plat_cavm_helpers.S	\

BL2_SOURCES		+=	plat/cavium/octeontx/t81/plat_cavm_ecam.c	\

BL31_SOURCES		+=	plat/cavium/octeontx/aarch64/octeontx_common.S	\
				plat/cavium/octeontx/aarch64/plat_cavm_helpers.S	\
				plat/cavium/octeontx/cavm_topology.c		\
