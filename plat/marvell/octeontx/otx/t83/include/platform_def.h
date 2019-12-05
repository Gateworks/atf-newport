/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLATFORM_DEF_H__
#define __PLATFORM_DEF_H__

#include <arch.h>
#include <common_def.h>
#include <tbbr_img_def.h>
#include <xlat_tables_v2.h>

/*******************************************************************************
 * Generic platform constants
 ******************************************************************************/

#define ARM_BL31_PLAT_PARAM_VAL		0x0f1e2d3c4b5a6978ULL

/* Size of cacheable stacks */
#define PLATFORM_STACK_SIZE		0x1000

#define OCTEONTX_PRIMARY_CPU		0x0

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
#define OCTEONTX_STATE_ON		0
#define OCTEONTX_STATE_RET		1
#define OCTEONTX_STATE_OFF		2
#define PLAT_MAX_RET_STATE		OCTEONTX_STATE_RET
#define PLAT_MAX_OFF_STATE		OCTEONTX_STATE_OFF

#define PLATFORM_NODE_COUNT		(PLATFORM_MAX_NODES)
#define PLATFORM_CLUSTER_COUNT		(PLATFORM_MAX_NODES * \
						PLATFORM_MAX_CLUSTERS_PER_NODE)
#define PLATFORM_MAX_CPUS_PER_CLUSTER	PLATFORM_CORE_PER_CLUSTER
#define PLATFORM_CORE_COUNT		(PLATFORM_CLUSTER_COUNT * \
						PLATFORM_CORE_PER_CLUSTER)

/* Marvell's OCTEONTX doesn't support AArch32 in EL1/2 */

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


#define PLATFORM_MAX_NODES		2
#define PLATFORM_MAX_CLUSTERS_PER_NODE	3
#define PLATFORM_CORE_PER_CLUSTER	16

#define MAX_XLAT_TABLES			48

/* Location of trusted dram on the base OcteonTX */
#define TZDRAM_BASE			0x00000000
#define TZDRAM_SIZE			0x00400000

#define FDT_MAX_SIZE			0x20000
#define FDT_BASE			(TZDRAM_BASE + TZDRAM_SIZE - FDT_MAX_SIZE)

#define BOARD_CFG_LIMIT			FDT_BASE
#define BOARD_CFG_MAX_SIZE		0x1000
#define BOARD_CFG_BASE			(BOARD_CFG_LIMIT - BOARD_CFG_MAX_SIZE)

#define BL1_RW_LIMIT			BOARD_CFG_BASE
#if defined(TRUSTED_BOARD_BOOT)
#define BL1_RW_MAX_SIZE			(0x00024000 + MAX_XLAT_TABLES * PAGE_SIZE)
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

/* Load address of BL33 in the OcteonTX port. */
#define NS_IMAGE_BASE			0x02800000
#define NS_IMAGE_MAX_SIZE		(0x40000000 - NS_IMAGE_BASE)

/* Number of TWSI interfaces */
#define TWSI_NUM			2

/* Signals used to communicate with MCU */
#define OCTEONTX_MCU_SHUTDOWN_SIGNAL	0x96

#define OCTEONTX_GPIO_DT_PATH		"/soc@0/pci@848000000000/gpio0@6,0"

#define MAX_GPIO_INTERRUPTS		80

#define GIC_PF_BAR4				CAVM_GIC_BAR_E_GIC_PF_BAR4_CN8
#define GIC_PF_BAR4_SIZE	CAVM_GIC_BAR_E_GIC_PF_BAR4_CN8_SIZE

#define PEM_INT_VEC_E_INTA			CAVM_PEM_INT_VEC_E_INTA_CN8
#define PEM_INT_VEC_E_INT_SUM		CAVM_PEM_INT_VEC_E_INT_SUM_CN8

#define UAAX_PF_BAR0(x)		CAVM_UAA_BAR_E_UAAX_PF_BAR0_CN8(x)

#define ECAM_PF_BAR2(x)		CAVM_ECAM_BAR_E_ECAMX_PF_BAR2_CN8(x)

#endif
