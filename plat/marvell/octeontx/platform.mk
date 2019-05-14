# Copyright (C) 2016-2018 Marvell International Ltd.
#
# SPDX-License-Identifier:     BSD-3-Clause
# https://spdx.org/licenses


LIBFDT_DIR		:=	lib/libfdt

PLAT_INCLUDES		:=	-Iinclude/common/tbbr				\
				-Iinclude/lib/libfdt 				\
				-Iinclude/lib/stdlib				\
				-Iinclude/plat/marvell/octeontx 			\
				-Iinclude/plat/marvell/octeontx/csr 			\
				-Iinclude/plat/marvell/octeontx/aarch64 			\
				-Iinclude/drivers/marvell				\
				-Iinclude/lib				\

include lib/xlat_tables_v2/xlat_tables.mk

PLAT_BL_COMMON_SOURCES	:=	drivers/arm/pl011/aarch64/pl011_console.S	\
				drivers/marvell/mmc.c		\
				drivers/marvell/twsi_core.c		\
				drivers/marvell/twsi.c		\
				${LIBFDT_DIR}/fdt.c				\
				${LIBFDT_DIR}/fdt_ro.c				\
				${LIBFDT_DIR}/fdt_rw.c				\
				${LIBFDT_DIR}/fdt_wip.c				\
				plat/marvell/octeontx/octeontx_common.c		\
				plat/marvell/octeontx/octeontx_dram.c			\
				drivers/marvell/smi.c		\
				plat/marvell/octeontx/octeontx_io_storage.c		\
				plat/marvell/octeontx/aarch64/octeontx_report_exception.S	\
				plat/marvell/octeontx/aarch64/octeontx_helpers.S 	\
				${XLAT_TABLES_LIB_SRCS}				\

BL1_SOURCES		+=	drivers/marvell/spi.c		\
				drivers/io/io_fip.c				\
				drivers/io/io_memmap.c				\
				drivers/io/io_storage.c				\
				plat/marvell/octeontx/octeontx_bl1_setup.c			\
				plat/marvell/octeontx/octeontx_board_cfg_bl1.c		\
				plat/marvell/octeontx/octeontx_scfg_bl1.c			\
				plat/marvell/octeontx/aarch64/octeontx_bl1_entrypoint.S	\

BL2_SOURCES		+=	drivers/marvell/spi.c		\
				drivers/io/io_fip.c				\
				drivers/io/io_memmap.c				\
				drivers/io/io_storage.c				\
				plat/marvell/octeontx/octeontx_bl2_setup.c		\
				plat/marvell/octeontx/octeontx_ecam.c			\

BL31_SOURCES		+=	drivers/arm/gic/common/gic_common.c		\
				drivers/arm/gic/v3/gicv3_main.c			\
				drivers/arm/gic/v3/gicv3_helpers.c		\
				drivers/marvell/spi.c		\
				drivers/delay_timer/delay_timer.c		\
				drivers/marvell/gicv3_setup.c			\
				drivers/marvell/timers_octeontx.c		\
				lib/timers/timers.c				\
				drivers/marvell/gpio_octeontx.c		\
				drivers/marvell/gti_watchdog.c                  \
				plat/marvell/octeontx/octeontx_bl31_setup.c			\
				plat/marvell/octeontx/octeontx_legacy_pm.c			\
				plat/marvell/octeontx/octeontx_legacy_pwrc.c		\
				plat/marvell/octeontx/octeontx_sata.c				\
				plat/marvell/octeontx/octeontx_svc.c				\
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

PROGRAMMABLE_RESET_ADDRESS	:=	1

ifeq (${LOAD_IMAGE_V2},1)
    BL2_SOURCES		+=	common/desc_image_load.c				\
				plat/marvell/octeontx/aarch64/octeontx_bl2_mem_params_desc.c	\
				plat/marvell/octeontx/octeontx_image_load.c
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
                              plat/marvell/octeontx/octeontx_tbbr_cot.c            \
                              plat/marvell/octeontx/octeontx_trusted_boot.c

    CRYPTO_LIB_MK := drivers/auth/mbedtls/mbedtls_crypto.mk
    IMG_PARSER_LIB_MK := drivers/auth/mbedtls/mbedtls_x509.mk

    $(info Including ${CRYPTO_LIB_MK})
    include ${CRYPTO_LIB_MK}

    $(info Including ${IMG_PARSER_LIB_MK})
    include ${IMG_PARSER_LIB_MK}
endif
