#/** @file
#
#  Copyright (c) 2016-2017, Marvell International Ltd. All rights reserved.<BR>
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#**/

BL32_SOURCES		+=	plat/marvell/common/tsp/cavm_tsp_setup.c		\
				plat/marvell/common/aarch64/cavm_helpers.S	\
				plat/marvell/common/cavm_gicv3.c		\
				plat/common/aarch64/platform_mp_stack.S		\
				plat/common/plat_gicv3.c