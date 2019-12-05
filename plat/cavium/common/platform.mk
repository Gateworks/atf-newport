#/** @file
#
#  Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#**/

LIBFDT_DIR		:=	lib/libfdt

PLAT_INCLUDES		:=	-Icsr/include					\
				-Iinclude/common/tbbr				\
				-Iinclude/lib/libfdt 				\
				-Iplat/cavium/common/include 			\

PLAT_BL_COMMON_SOURCES	:=	drivers/arm/pl011/pl011_console.S		\
				drivers/cavium/thunder_mmc.c			\
				drivers/cavium/thunder_twsi.c			\
				lib/aarch64/xlat_tables.c			\
				${LIBFDT_DIR}/fdt.c				\
				${LIBFDT_DIR}/fdt_ro.c				\
				${LIBFDT_DIR}/fdt_rw.c				\
				plat/common/aarch64/plat_common.c		\
				plat/cavium/common/thunder_common.c		\
				plat/cavium/common/thunder_dram.c		\
				plat/cavium/common/thunder_dt.c			\
				plat/cavium/common/thunder_io_storage.c		\

BL1_SOURCES		+=	bl31/aarch64/crash_reporting.S			\
				drivers/cavium/thunder_spi.c			\
				drivers/io/io_fip.c				\
				drivers/io/io_memmap.c				\
				drivers/io/io_storage.c				\
				lib/cpus/aarch64/thunder.S			\
				plat/cavium/common/aarch64/thunder_helpers.S	\
				plat/cavium/common/bl1_thunder_setup.c		\
				plat/common/aarch64/platform_up_stack.S		\

BL2_SOURCES		+=	drivers/cavium/thunder_spi.c			\
				drivers/io/io_fip.c				\
				drivers/io/io_memmap.c				\
				drivers/io/io_storage.c				\
				plat/cavium/common/bl2_thunder_setup.c		\
				plat/cavium/common/thunder_ecam.c		\
				plat/cavium/common/thunder_gti.c		\
				plat/cavium/common/thunder_security.c		\
				plat/common/aarch64/platform_up_stack.S		\

BL31_SOURCES		+=	drivers/arm/gic/common/gic_common.c		\
				drivers/arm/gic/v3/gicv3_main.c			\
				drivers/arm/gic/v3/gicv3_helpers.c		\
				drivers/cavium/thunder_spi.c			\
				lib/cpus/aarch64/thunder.S			\
				lib/timers/timers.c				\
				plat/cavium/common/aarch64/thunder_helpers.S	\
				plat/cavium/common/bl31_thunder_setup.c		\
				plat/cavium/common/thunder_gicv3.c		\
				plat/cavium/common/thunder_pm.c			\
				plat/cavium/common/thunder_pwrc.c		\
				plat/cavium/common/thunder_sata.c		\
				plat/cavium/common/thunder_svc.c		\
				plat/cavium/common/thunder_timers.c		\
				plat/cavium/common/thunder_topology.c		\
				plat/common/aarch64/plat_psci_common.c		\
				plat/common/aarch64/platform_mp_stack.S		\
				plat/common/plat_gicv3.c			\

ENABLE_PLAT_COMPAT	:=	0

CRASH_REPORTING		:=	1

ASM_ASSERTION		:=	1

PL011_GENERIC_UART	:=	1

ERROR_DEPRECATED	:=	1

MAX_XLAT_LEVEL		:=	4
$(eval $(call add_define,MAX_XLAT_LEVEL))
