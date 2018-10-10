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

LIBFDT_DIR		:=	lib/libfdt

PLAT_INCLUDES		:=	-Icsr/include					\
				-Iinclude/common/tbbr				\
				-Iinclude/lib/libfdt 				\
				-Iinclude/lib/stdlib				\
				-Iinclude/plat/marvell/octeontx 			\
				-Iinclude/plat/marvell/octeontx/aarch64 			\
				-Iinclude/drivers/marvell				\

include lib/xlat_tables_v2/xlat_tables.mk

PLAT_BL_COMMON_SOURCES	:=	drivers/arm/pl011/aarch64/pl011_console.S	\
				drivers/marvell/cavm_mmc.c		\
				plat/marvell/octeontx/cavm_twsi_core.c		\
				drivers/marvell/cavm_twsi.c		\
				${LIBFDT_DIR}/fdt.c				\
				${LIBFDT_DIR}/fdt_ro.c				\
				${LIBFDT_DIR}/fdt_rw.c				\
				${LIBFDT_DIR}/fdt_wip.c				\
				plat/marvell/octeontx/cavm_common.c		\
				plat/marvell/octeontx/cavm_dram.c			\
				drivers/marvell/cavm_smi.c		\
				plat/marvell/octeontx/cavm_io_storage.c		\
				${XLAT_TABLES_LIB_SRCS}				\

BL1_SOURCES		+=	drivers/marvell/cavm_spi.c		\
				drivers/io/io_fip.c				\
				drivers/io/io_memmap.c				\
				drivers/io/io_storage.c				\
				plat/marvell/octeontx/aarch64/cavm_helpers.S 	\
				plat/marvell/octeontx/bl1_cavm_setup.c		\
				plat/marvell/octeontx/cavm_dt.c			\
				plat/marvell/octeontx/cavm_scfg.c	\

BL2_SOURCES		+=	drivers/marvell/cavm_spi.c		\
				drivers/io/io_fip.c				\
				drivers/io/io_memmap.c				\
				drivers/io/io_storage.c				\
				plat/marvell/octeontx/bl2_cavm_setup.c		\
				plat/marvell/octeontx/cavm_ecam.c			\

BL31_SOURCES		+=	drivers/arm/gic/common/gic_common.c		\
				drivers/arm/gic/v3/gicv3_main.c			\
				drivers/arm/gic/v3/gicv3_helpers.c		\
				drivers/marvell/cavm_spi.c		\
				drivers/delay_timer/delay_timer.c		\
				lib/timers/timers.c				\
				drivers/marvell/cavm_gpio.c		\
				plat/marvell/octeontx/aarch64/cavm_helpers.S 	\
				plat/marvell/octeontx/bl31_cavm_setup.c		\
				plat/marvell/octeontx/cavm_gicv3.c			\
				plat/marvell/octeontx/cavm_legacy_pm.c		\
				plat/marvell/octeontx/cavm_legacy_pwrc.c		\
				plat/marvell/octeontx/cavm_sata.c			\
				plat/marvell/octeontx/cavm_svc.c			\
				plat/marvell/octeontx/cavm_timers.c		\
				plat/common/plat_psci_common.c			\
				plat/common/plat_gicv3.c			\

ENABLE_PLAT_COMPAT	:=	0

CRASH_REPORTING		:=	1

ASM_ASSERTION		:=	1

PL011_GENERIC_UART	:=	1

ERROR_DEPRECATED	:=	1

USE_TBBR_DEFS		:=	1

MULTI_CONSOLE_API	:=	1

CTX_INCLUDE_AARCH32_REGS	:=	0

ifeq (${LOAD_IMAGE_V2},1)
    BL2_SOURCES		+=	common/desc_image_load.c				\
				plat/marvell/octeontx/aarch64/cavm_bl2_mem_params_desc.c	\
				plat/marvell/octeontx/cavm_image_load.c
endif

ifeq (${SECURE_BOOT},1)
    include drivers/auth/mbedtls/mbedtls_common.mk

    ifeq (${ARM_ROTPK_LOCATION}, regs)
        ARM_ROTPK_LOCATION_ID = ARM_ROTPK_REGS_ID
    else
        $(error "Unsupported ARM_ROTPK_LOCATION value '${ARM_ROTPK_LOCATION}'")
    endif

    # KEY_ALG and TF_MBEDTLS_KEY_ALG are used for authentication purposes
    KEY_ALG                := ecdsa
    TF_MBEDTLS_KEY_ALG     := ${KEY_ALG}

    # CIPHER_TYPE that will be used to encrypt/decrypt images
    # If not defied at build time, do not use encryption
    ifneq (${CIPHER_TYPE},)
        MBEDTLS_CIPHER_TYPE	   := ${CIPHER_TYPE}
        CRYPTO_BOARD_BOOT	   := 1
    else
        CRYPTO_BOARD_BOOT	   := 0
    endif

    $(eval $(call add_define,ARM_ROTPK_LOCATION_ID))
    PLAT_BL_COMMON_SOURCES += drivers/auth/auth_mod.c                              \
                              drivers/auth/crypto_mod.c                            \
                              drivers/auth/img_parser_mod.c                        \
                              plat/marvell/octeontx/cavm_tbbr_cot.c                   \
                              plat/marvell/octeontx/cavm_trusted_boot.c

    CRYPTO_LIB_MK := drivers/auth/mbedtls/mbedtls_crypto.mk
    IMG_PARSER_LIB_MK := drivers/auth/mbedtls/mbedtls_x509.mk

    $(info Including ${CRYPTO_LIB_MK})
    include ${CRYPTO_LIB_MK}

    $(info Including ${IMG_PARSER_LIB_MK})
    include ${IMG_PARSER_LIB_MK}
endif
