# Copyright (C) 2018 Marvell International Ltd.
#
# SPDX-License-Identifier:     BSD-3-Clause
# https://spdx.org/licenses

MARVELL_PLAT_BASE		:= plat/marvell/armada
MARVELL_PLAT_INCLUDE_BASE	:= include/plat/marvell/armada

include plat/marvell/version.mk
include plat/marvell/marvell.mk

VERSION_STRING			+=(Marvell-${SUBVERSION})

SEPARATE_CODE_AND_RODATA	:= 1

# Convert LLC to secure SRAM
LLC_SRAM			:= 0
$(eval $(call add_define,LLC_SRAM))

# Enable/Disable LLC
ifeq (${LLC_SRAM}, 0)
LLC_ENABLE			:= 1
else
# When LLC_SRAM=1, all or part of LLC converted to SRAM and enabled by OP-TEE.
# All existing cases activating LLC at BL31 stage should be disabled.
# The below assignment does not allow changing the LLC_ENABLE
# value in the command line.
LLC_ENABLE			= 0
endif
$(eval $(call add_define,LLC_ENABLE))

PLAT_INCLUDES		+=	-I. -Iinclude/common/tbbr		\
				-I$(MARVELL_PLAT_INCLUDE_BASE)/common	\
				-I$(MARVELL_PLAT_INCLUDE_BASE)/common/aarch64


PLAT_BL_COMMON_SOURCES  +=      lib/xlat_tables/xlat_tables_common.c			\
				lib/xlat_tables/aarch64/xlat_tables.c			\
				$(MARVELL_PLAT_BASE)/common/aarch64/marvell_common.c	\
				$(MARVELL_PLAT_BASE)/common/aarch64/marvell_helpers.S

BL1_SOURCES		+=	drivers/delay_timer/delay_timer.c			\
				drivers/io/io_fip.c					\
				drivers/io/io_memmap.c					\
				drivers/io/io_storage.c					\
				$(MARVELL_PLAT_BASE)/common/marvell_bl1_setup.c		\
				$(MARVELL_PLAT_BASE)/common/marvell_io_storage.c	\
				$(MARVELL_PLAT_BASE)/common/plat_delay_timer.c

ifdef EL3_PAYLOAD_BASE
# Need the arm_program_trusted_mailbox() function to release secondary CPUs from
# their holding pen
endif

BL2_SOURCES		+=	drivers/io/io_fip.c					\
				drivers/io/io_memmap.c					\
				drivers/io/io_storage.c					\
				$(MARVELL_PLAT_BASE)/common/marvell_bl2_setup.c		\
				$(MARVELL_PLAT_BASE)/common/marvell_io_storage.c

ifeq (${LOAD_IMAGE_V2},1)
BL2_SOURCES		+=	$(MARVELL_PLAT_BASE)/common/aarch64/marvell_bl2_mem_params_desc.c	\
				$(MARVELL_PLAT_BASE)/common/marvell_image_load.c			\
				common/desc_image_load.c
ifeq (${SPD},opteed)
BL2_SOURCES		+=	lib/optee/optee_utils.c
endif
endif

BL31_SOURCES		+=	$(MARVELL_PLAT_BASE)/common/marvell_bl31_setup.c	\
				$(MARVELL_PLAT_BASE)/common/marvell_pm.c		\
				$(MARVELL_PLAT_BASE)/common/marvell_topology.c		\
				plat/common/plat_psci_common.c				\
				$(MARVELL_PLAT_BASE)/common/plat_delay_timer.c		\
				drivers/delay_timer/delay_timer.c

# PSCI functionality
$(eval $(call add_define,CONFIG_ARM64))

# Add the build options to pack Trusted OS Extra1 and Trusted OS Extra2 images
# in the FIP if the platform requires.
ifneq ($(BL32_EXTRA1),)
$(eval $(call TOOL_ADD_IMG,bl32_extra1,--tos-fw-extra1))
endif
ifneq ($(BL32_EXTRA2),)
$(eval $(call TOOL_ADD_IMG,bl32_extra2,--tos-fw-extra2))
endif

# MSS (SCP) build
ifeq (${MSS_SUPPORT}, 1)
include $(MARVELL_PLAT_BASE)/common/mss/mss_common.mk
endif

fip: mrvl_flash
