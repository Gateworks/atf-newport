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
				-Iinclude/lib/stdlib				\
				-Iplat/cavium/common/include 			\

PLAT_BL_COMMON_SOURCES	:=	drivers/arm/pl011/aarch64/pl011_console.S	\
				drivers/cavium/thunder_mmc.c			\
				drivers/cavium/thunder_twsi.c			\
				lib/xlat_tables/xlat_tables_common.c		\
				lib/xlat_tables/aarch64/xlat_tables.c		\
				${LIBFDT_DIR}/fdt.c				\
				${LIBFDT_DIR}/fdt_ro.c				\
				${LIBFDT_DIR}/fdt_rw.c				\
				plat/cavium/common/thunder_common.c		\
				plat/cavium/common/thunder_dram.c		\
				plat/cavium/common/thunder_dt.c			\
				plat/cavium/common/thunder_io_storage.c		\

BL1_SOURCES		+=	drivers/cavium/thunder_spi.c			\
				drivers/io/io_fip.c				\
				drivers/io/io_memmap.c				\
				drivers/io/io_storage.c				\
				lib/cpus/aarch64/thunder.S			\
				plat/cavium/common/aarch64/thunder_helpers.S	\
				plat/cavium/common/bl1_thunder_setup.c		\

BL2_SOURCES		+=	drivers/cavium/thunder_spi.c			\
				drivers/io/io_fip.c				\
				drivers/io/io_memmap.c				\
				drivers/io/io_storage.c				\
				plat/cavium/common/bl2_thunder_setup.c		\
				plat/cavium/common/thunder_ecam.c		\
				plat/cavium/common/thunder_gti.c		\
				plat/cavium/common/thunder_security.c		\

BL31_SOURCES		+=	drivers/arm/gic/common/gic_common.c		\
				drivers/arm/gic/v3/gicv3_main.c			\
				drivers/arm/gic/v3/gicv3_helpers.c		\
				drivers/cavium/thunder_spi.c			\
				drivers/delay_timer/delay_timer.c		\
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
				plat/common/plat_psci_common.c			\
				plat/common/plat_gicv3.c			\

ENABLE_PLAT_COMPAT	:=	0

CRASH_REPORTING		:=	1

ASM_ASSERTION		:=	1

PL011_GENERIC_UART	:=	1

ERROR_DEPRECATED	:=	1

CTX_INCLUDE_AARCH32_REGS	:=	0

ifeq (${LOAD_IMAGE_V2},1)
    BL2_SOURCES		+=	common/desc_image_load.c				\
				plat/cavium/common/aarch64/thunder_bl2_mem_params_desc.c\
				plat/cavium/common/thunder_image_load.c
endif
