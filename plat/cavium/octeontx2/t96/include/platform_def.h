/** @file

  Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __PLATFORM_DEF_H__
#define __PLATFORM_DEF_H__

#include <arch.h>
#include <common_def.h>
#include <tbbr_img_def.h>
#include <xlat_tables.h>

/*******************************************************************************
 * Generic platform constants
 ******************************************************************************/

#define ARM_BL31_PLAT_PARAM_VAL		0x0f1e2d3c4b5a6978ULL

/* Size of cacheable stacks */
#define PLATFORM_STACK_SIZE		0x1000

#define THUNDER_PRIMARY_CPU		0x0

/* Required platform porting definitions */
#define PLAT_NUM_PWR_DOMAINS		(PLATFORM_CLUSTER_COUNT + \
					PLATFORM_CORE_COUNT + \
					PLATFORM_NODE_COUNT)
#define PLAT_MAX_PWR_LVL		MPIDR_AFFLVL2

/* SATA-related definitions */
#define MAX_SATA_CONTROLLERS		16
#define MAX_SATA_GSER			8

/*******************************************************************************
 * Platform power states
 ******************************************************************************/
#define THUNDER_STATE_ON		0
#define THUNDER_STATE_RET		1
#define THUNDER_STATE_OFF		2
#define PLAT_MAX_RET_STATE		THUNDER_STATE_RET
#define PLAT_MAX_OFF_STATE		THUNDER_STATE_OFF

#define PLATFORM_NODE_COUNT		(PLATFORM_MAX_NODES)
#define PLATFORM_CLUSTER_COUNT		(PLATFORM_MAX_NODES * \
						PLATFORM_MAX_CLUSTERS_PER_NODE)
#define PLATFORM_MAX_CPUS_PER_CLUSTER	PLATFORM_CORE_PER_CLUSTER
#define PLATFORM_CORE_COUNT		(PLATFORM_CLUSTER_COUNT * \
						PLATFORM_CORE_PER_CLUSTER)

/* Cavium ThunderX doesn't support AArch32 in EL1/2 */

#define NO_AARCH32_EL2	1

/*******************************************************************************
 * Declarations and constants to access the mailboxes safely. Each mailbox is
 * aligned on the biggest cache line size in the platform. This is known only
 * to the platform as it might have a combination of integrated and external
 * caches. Such alignment ensures that two maiboxes do not sit on the same cache
 * line at any cache level. They could belong to different cpus/clusters &
 * get written while being protected by different locks causing corruption of
 * a valid mailbox address.
 ******************************************************************************/
#define CACHE_WRITEBACK_SHIFT   7
#define CACHE_WRITEBACK_GRANULE (1 << CACHE_WRITEBACK_SHIFT)

#define MAX_IO_DEVICES			5
#define MAX_IO_HANDLES			4

/*******************************************************************************
 * Platform specific page table and MMU setup constants
 ******************************************************************************/
#define ADDR_SPACE_SIZE_SHIFT		48
#define PLAT_VIRT_ADDR_SPACE_SIZE	(1ull << ADDR_SPACE_SIZE_SHIFT)
#define PLAT_PHY_ADDR_SPACE_SIZE	(1ull << ADDR_SPACE_SIZE_SHIFT)

#define MAX_MMAP_REGIONS		256

#define NS_DMA_MEMORY_SIZE		0x100000

#define OCTEONTX2_CN96XX_MIDR		0x430F0B20

#define CVM_PN_EL1			S3_0_C11_C4_2

#define PLATFORM_MAX_NODES		1
#define PLATFORM_MAX_CLUSTERS_PER_NODE	4
#define PLATFORM_CORE_PER_CLUSTER	6

#define MAX_XLAT_TABLES			58

/* Location of trusted dram on the base OcteonTX2 */
#define TZDRAM_BASE			0x00000000
#define TZDRAM_SIZE			0x01000000

/*
 * Memory used for mailbox and RVU MSI-X
 * Required size is 40M, but due to CCS_REGION memory
 * granulation - minimum size of region is 16M need to
 * reserve 48M of size for this purpose.
 */
#define RVU_MEM_BASE			(TZDRAM_BASE + TZDRAM_SIZE)
#define RVU_MEM_SIZE			0x03000000

#define FDT_MAX_SIZE			0x20000
#define FDT_BASE			(TZDRAM_BASE + TZDRAM_SIZE - FDT_MAX_SIZE)

#define BOARD_CFG_LIMIT			FDT_BASE
#define BOARD_CFG_MAX_SIZE		0x4000
#define BOARD_CFG_BASE			(BOARD_CFG_LIMIT - BOARD_CFG_MAX_SIZE)

#define BL1_RW_LIMIT			BOARD_CFG_BASE
#if defined(TRUSTED_BOARD_BOOT)
#define BL1_RW_MAX_SIZE			(0x00028000 + MAX_XLAT_TABLES * PAGE_SIZE)
#else /* TRUSTED_BOARD_BOOT */
#define BL1_RW_MAX_SIZE			(0x00010000 + MAX_XLAT_TABLES * PAGE_SIZE)
#endif /* TRUSTED_BOARD_BOOT */
#define BL1_RW_BASE			(BL1_RW_LIMIT - BL1_RW_MAX_SIZE)

#define BL2_LIMIT			BL1_RW_BASE
#if defined(TRUSTED_BOARD_BOOT)
#define BL2_MAX_SIZE			(0x00028000 + MAX_XLAT_TABLES * PAGE_SIZE)
#else /* TRUSTED_BOARD_BOOT */
#define BL2_MAX_SIZE			(0x00020000 + MAX_XLAT_TABLES * PAGE_SIZE)
#endif /* TRUSTED_BOARD_BOOT */
#define BL2_BASE			(BL2_LIMIT - BL2_MAX_SIZE)

#define MAILBOX_LIMIT			BL2_BASE
#define MAILBOX_MAX_SIZE		0x1000      /* 4 KB */
#define MAILBOX_BASE			(MAILBOX_LIMIT - MAILBOX_MAX_SIZE)

#define BL31_LIMIT			MAILBOX_BASE
#define BL31_MAX_SIZE			(0x00091000 + MAX_XLAT_TABLES * PAGE_SIZE)
#define BL31_BASE			(BL31_LIMIT - BL31_MAX_SIZE)

#define BL2U_BASE			BL2_BASE
#define BL2U_LIMIT			BL2_LIMIT

#define TSP_IRQ_SEC_PHY_TIMER		29
#define TSP_SEC_MEM_BASE		TZDRAM_BASE
#define TSP_SEC_MEM_SIZE		TZDRAM_SIZE

/* Load address of BL33 in the OcteonTX2 port. */
#define NS_IMAGE_BASE			0x04000000
#define NS_IMAGE_MAX_SIZE		(0x40000000 - NS_IMAGE_BASE)

/* Number of TWSI interfaces */
#define TWSI_NUM			6

/* Signals used to communicate with MCU */
#define OCTEONTX_MCU_SHUTDOWN_SIGNAL	0x96

#define MAX_GPIO_INTERRUPTS		64
#endif
