/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_COMMON_H__
#define __CAVM_COMMON_H__

#include <stdint.h>
#include <xlat_tables_v2.h>
#include <arch_helpers.h>
#include <stddef.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "cavm-arch.h"
#pragma GCC diagnostic pop

#define MIDR_REVISION_MASK      0xf
#define MIDR_REVISION(midr)     ((midr) & MIDR_REVISION_MASK)
#define MIDR_PARTNUM_SHIFT      4
#define MIDR_PARTNUM_MASK       (0xfff << MIDR_PARTNUM_SHIFT)
#define MIDR_PARTNUM(midr)      \
        (((midr) & MIDR_PARTNUM_MASK) >> MIDR_PARTNUM_SHIFT)

#define T81PARTNUM 0xA2
#define T83PARTNUM 0xA3
#define T98PARTNUM 0xB1
#define T96PARTNUM 0xB2
#define F95PARTNUM 0xB3

/* Boot type definitions */
#define THUNDER_BOOT_UNSUPPORTED	1
#define THUNDER_BOOT_REMOTE		10
#define THUNDER_BOOT_SPI		11
#define THUNDER_BOOT_EMMC		12

#undef AP_CVMCTL_EL1
#undef AP_CVM_ACCESS_EL1
#undef AP_CVMMEMCTL0_EL1
#undef AP_CVMMEMCTL1_EL1
#undef AP_CVM_ACCESS_EL2
#undef AP_CVM_ACCESS_EL3

#define AP_CVMCTL_EL1		S3_0_C11_C0_0
#define AP_CVM_ACCESS_EL1	S3_0_C11_C0_3
#define AP_CVMMEMCTL0_EL1	S3_0_C11_C0_4
#define AP_CVMMEMCTL1_EL1	S3_0_C11_C0_5
#define AP_CVM_ACCESS_EL2	S3_4_C11_C0_3
#define AP_CVM_ACCESS_EL3	S3_6_C11_C0_3

DEFINE_RENAME_SYSREG_RW_FUNCS(cvmctl_el1, AP_CVMCTL_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmmemctl0_el1, AP_CVMMEMCTL0_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmmemctl1_el1, AP_CVMMEMCTL1_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvm_access_el1, AP_CVM_ACCESS_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvm_access_el2, AP_CVM_ACCESS_EL2)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvm_access_el3, AP_CVM_ACCESS_EL3)

#define IS_THUNDER_PASS(midr, partnum, hi, low)				\
	((((midr) >> MIDR_PN_SHIFT & MIDR_PN_MASK) == (partnum)) &&	\
	 (((midr) >> MIDR_VAR_SHIFT & MIDR_VAR_MASK) == (hi) - 1) &&	\
	 (((midr) >> MIDR_REV_SHIFT & MIDR_REV_MASK) == (low)))

/* Utils macro for fuses usage */
#define FUSE_BIT_TO_BYTE_ADDR_SHIFT	0x3
#define FUSE_BIT_TO_BYTE_ADDR(addr)	((addr) >> FUSE_BIT_TO_BYTE_ADDR_SHIFT)
#define FUSE_HI_ADDR_SHIFT		0x8
#define FUSE_HI_ADDR(addr)		((addr) >> FUSE_HI_ADDR_SHIFT)
#define FUSE_BYTE_ADDR_MASK		0x7
#define FUSE_BIT_SET			0x1
#define FUSE_GET_VAL(dat, fuse)		(((uint8_t)dat) >> ((fuse) & FUSE_BYTE_ADDR_MASK) & FUSE_BIT_SET)


/* In Mhz */
#define THUNDER_SYSCNT_FREQ	100ull

#define PCI_MSIX_CAP_ID		0x11

/* Definitions of IRQ PPI (Per-Processor Interrupt) IDs (range 0x10 - 0x1f) */

/* Secure physical generic timer IRQ */
#define OCTEONTX_IRQ_SEC_PHY_TIMER	0x1d


/* Definitions of IRQ SPI (Shared Peripheral Interrupt) IDs (range 0x20-0x9f) */

/*
 * OCTEONTX GPIO POWER IRQ for graceful shutdown.
 * OCTEONTX_GPIO_PWR_S_IRQ: Secure IRQ that comes first as soon as GPIO
 *                          is triggered
 * OCTEONTX_GPIO_PWR_NS_IRQ: Non-Secure IRQ to kernel to initiate
 *                           graceful shutdown
 * OCTEONTX_KEY_POWER_IRQ: Firmware generated IRQ to signal KEY_POWER
 *                         to non-secure software
 */
#define OCTEONTX_GPIO_PWR_NS_IRQ	0x20
#define OCTEONTX_GPIO_PWR_S_IRQ		0x21
#define OCTEONTX_KEY_POWER_IRQ		OCTEONTX_GPIO_PWR_NS_IRQ

/* TWSI Secure interrupt for BMC events */
#define OCTEONTX_TWSI_1_S_IRQ		0x22

/* UAA interrupts */
#define OCTEONTX_UAA0_IRQ		0x25
#define OCTEONTX_UAA1_IRQ		0x26
#define OCTEONTX_UAA2_IRQ		0x27
#define OCTEONTX_UAA3_IRQ		0x28

/* Watchdog interrupt */
#define OCTEONTX_GTI_WDOG_IRQ		0x29

/*
 * 4 IRQs per PEM (INTA, INTB, INTC, INTD)
 * 12 PEMs (6 per node)
 * 0x30 (48) IRQs needed
 */
#define OCTEONTX_PEM_INTBASE_IRQ	0x30

/* First available irq after PEM is 0x60 */

/*
 * SMMU 0..3 NODE0
 * SMMU 4..7 NODE1
 * Modify the below to change ths SMMU SPI's 
 */
#define OCTEONTX_SMMU0_GLOBAL_IRQ	0x64
#define OCTEONTX_SMMU0_CONTEXT_IRQ	0x65
#define OCTEONTX_SMMU1_GLOBAL_IRQ	0x66
#define OCTEONTX_SMMU1_CONTEXT_IRQ	0x67
#define OCTEONTX_SMMU2_GLOBAL_IRQ	0x68
#define OCTEONTX_SMMU2_CONTEXT_IRQ	0x69
#define OCTEONTX_SMMU3_GLOBAL_IRQ	0x6a
#define OCTEONTX_SMMU3_CONTEXT_IRQ	0x6b
#define OCTEONTX_SMMU4_GLOBAL_IRQ	0x6c
#define OCTEONTX_SMMU4_CONTEXT_IRQ	0x6d
#define OCTEONTX_SMMU5_GLOBAL_IRQ	0x6e
#define OCTEONTX_SMMU5_CONTEXT_IRQ	0x6f
#define OCTEONTX_SMMU6_GLOBAL_IRQ	0x70
#define OCTEONTX_SMMU6_CONTEXT_IRQ	0x71
#define OCTEONTX_SMMU7_GLOBAL_IRQ	0x72
#define OCTEONTX_SMMU7_CONTEXT_IRQ	0x73

#define OCTEONTX_SMMU_GLOBAL_VECTOR_OFFSET	0x1000
#define OCTEONTX_SMMU_NUM_CONTEXTS		0x80

/* Base SPI for GPIO interrupt to be handled in ATF */
#define OCTEONTX_IRQ_GPIO_BASE		0x74
#define OCTEONTX_IRQ_GPIO_COUNT		0x4
/* Default SPI to be used by kernel GPIO driver when intercepting interrupts */
#define OCTEONTX_IRQ_GPIO_NSEC		0x79

#define set_bit(reg, bit) reg |= (1ULL<<(bit))
#define unset_bit(reg, bit) reg &= ~(1ULL<<(bit))

int thunder_get_lmc_per_node(void);

int thunder_get_num_ecams_per_node(void);

int thunder_get_sata_count(void);
int thunder_sata_to_gser(int ctrlr);
int thunder_sata_to_lane(int ctrlr);
int thunder_get_max_sata_gser(void);
int thunder_get_iobn_count(void);
int thunder_get_cpt_count(void);
int thunder_get_gser_count(void);

void add_map_record(unsigned long addr, unsigned long size, mmap_attr_t attr);

int plat_fuse_read(int node, int fuse);

void octeontx_pci_init(void);
void octeontx_rvu_init(int node);
int octeontx2_clear_lf_to_pf_mapping(int node);
void plat_add_mmio_map(void);
void thunder_io_setup(void);
void octeontx_security_setup(void);
unsigned thunder_get_node_count(void);
int thunder_dram_is_lmc_enabled(unsigned node, unsigned lmc);
uint64_t thunder_dram_size_node(unsigned node);
void thunder_cpu_setup(void);
extern void *fdt_ptr;
void thunder_gic_driver_init(void);
void thunder_gic_init(void);
void cavm_gic_pcpu_init(void);
void cavm_gic_cpuif_enable(void);
void cavm_gic_cpuif_disable(void);
unsigned int thunder_calc_core_pos(unsigned long mpidr);
void thunder_signal_shutdown(void);
void plat_pwrc_setup(void);
int thunder_twsi_send(unsigned int node, unsigned int twsi_num,
			uint16_t addr, const uint8_t *buffer, size_t size);
int thunder_twsi_recv(unsigned int node, unsigned int twsi_num,
			uint16_t addr, uint8_t *buffer, size_t size);
void sata_ipm_quirk(void);

void cavm_configure_mmc_security(int secure);
void set_secondary_cpu_jump_addr(unsigned int bl1_base);
void l2c_flush(void);
void plat_cavm_setup(void);
unsigned int plat_get_rom_t_cnt(int node);
void plat_flr_init(void);

/**
 * Builds a bit mask given the required size in bits.
 *
 * @param bits   Number of bits in the mask
 * @return The mask
 */
static inline uint64_t cavm_build_mask(uint64_t bits)
{
	if (bits == 64)
		return -1;

	return ~((~0x0ull) << bits);
}

/**
 * Extract bits out of a number
 *
 * @param input  Number to extract from
 * @param lsb    Starting bit, least significant (0-63)
 * @param width  Width in bits (1-64)
 *
 * @return Extracted number
 */
static inline uint64_t cavm_bit_extract(uint64_t input, int lsb, int width)
{
    uint64_t result = input >> lsb;
    result &= cavm_build_mask(width);
    return result;
}

/**
 * Insert bits into a number
 *
 * @param original Original data, before insert
 * @param input    Data to insert
 * @param lsb    Starting bit, least significant (0-63)
 * @param width  Width in bits (1-64)
 *
 * @return Number with inserted bits
 */
static inline uint64_t cavm_bit_insert(uint64_t original, uint64_t input, int lsb, int width)
{
    uint64_t mask = cavm_build_mask(width);
    uint64_t result = original & ~(mask << lsb);
    result |= (input & mask) << lsb;
    return result;
}



#endif /* __CAVM_COMMON_H__ */
