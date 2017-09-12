/** @file

    Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __THUNDER_PRIVATE_H
#define __THUNDER_PRIVATE_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "cavm-arch.h"
#pragma GCC diagnostic pop

#include <arch_helpers.h>
#include <stddef.h>

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

/* In Mhz */
#define THUNDER_SYSCNT_FREQ	100ull

void octeontx_pci_init(void);
void plat_add_mmio_map(void);
void thunder_io_setup(void);
void thunder_security_setup(void);
unsigned thunder_get_node_count(void);
int thunder_dram_is_lmc_enabled(unsigned node, unsigned lmc);
uint64_t thunder_dram_size_node(unsigned node);
void thunder_cpu_setup(void);
extern void *fdt_ptr;
void thunder_gic_driver_init(void);
void thunder_gic_init(void);
unsigned int thunder_calc_core_pos(unsigned long mpidr);
void thunder_signal_shutdown(void);
int thunder_pwrc_setup(void);
void thunder_twsi_send(unsigned int node, unsigned int twsi_num,
			uint16_t addr, const uint8_t *buffer, size_t size);
void sata_ipm_quirk(void);

int spi_nor_init(void);
int spi_nor_rw_data(int write, unsigned long addr, int size, void *buf, int buf_size);
int spi_nor_erase_sect(uint32_t addr);

void set_secondary_cpu_jump_addr(unsigned int bl1_base);

static uint8_t thunder_fuse_read_byte(int node, int byte_addr)
{
	union cavm_mio_fus_rcmd read_cmd;

	read_cmd.u = 0;
	read_cmd.s.addr = byte_addr;
	read_cmd.s.pend = 1;
	CSR_WRITE_PA(node, CAVM_MIO_FUS_RCMD, read_cmd.u);
	while ((read_cmd.u = CSR_READ_PA(node, CAVM_MIO_FUS_RCMD)) &&
		read_cmd.s.pend) ;

	return read_cmd.s.dat;
}

static inline int thunder_fuse_read(int node, int fuse)
{
	return (thunder_fuse_read_byte(node, fuse >> 3) >> (fuse & 0x7)) & 1;
}

#define PCI_MSIX_CAP_ID		0x11

/* Definitions of IRQ PPI (Per-Processor Interrupt) IDs (range 0x10 - 0x1f) */

/* Secure physical generic timer IRQ */
#define IRQ_SEC_PHY_TIMER	0x1d


/* Definitions of IRQ SPI (Shared Peripheral Interrupt) IDs (range 0x20-0x9f) */

/*
 * GPIO POWER IRQ for graceful shutdown.
 * GPIO_PWR_S_IRQ: Secure IRQ that comes first as soon as GPIO is triggered
 * GPIO_PWR_NS_IRQ: Non-Secure IRQ to kernel to initiate graceful shutdown
 * KEY_POWER_IRQ: Firmware generated IRQ to signal KEY_POWER to non-secure
 *                software
 */
#define GPIO_PWR_NS_IRQ		0x20
#define GPIO_PWR_S_IRQ		0x21
#define KEY_POWER_IRQ		GPIO_PWR_NS_IRQ

/* TWSI Secure interrupt for BMC events */
#define TWSI_1_S_IRQ		0x22

/* UAA interrupts */
#define UAA0_IRQ		0x25
#define UAA1_IRQ		0x26
#define UAA2_IRQ		0x27
#define UAA3_IRQ		0x28

/* Watchdog interrupt */
#define GTI_WDOG_IRQ		0x29

/*
 * 4 IRQs per PEM (INTA, INTB, INTC, INTD)
 * 12 PEMs (6 per node)
 * 0x30 (48) IRQs needed
 */
#define PEM_INTBASE_IRQ		0x30

/* First available irq after PEM is 0x60 */

/*
 * SMMU 0..3 NODE0
 * SMMU 4..7 NODE1
 * Modify the below to change ths SMMU SPI's 
 */
#define SMMU0_GLOBAL_IRQ	0x64
#define SMMU0_CONTEXT_IRQ	0x65
#define SMMU1_GLOBAL_IRQ	0x66
#define SMMU1_CONTEXT_IRQ	0x67
#define SMMU2_GLOBAL_IRQ	0x68
#define SMMU2_CONTEXT_IRQ	0x69
#define SMMU3_GLOBAL_IRQ	0x6a
#define SMMU3_CONTEXT_IRQ	0x6b
#define SMMU4_GLOBAL_IRQ	0x6c
#define SMMU4_CONTEXT_IRQ	0x6d
#define SMMU5_GLOBAL_IRQ	0x6e
#define SMMU5_CONTEXT_IRQ	0x6f
#define SMMU6_GLOBAL_IRQ	0x70
#define SMMU6_CONTEXT_IRQ	0x71
#define SMMU7_GLOBAL_IRQ	0x72
#define SMMU7_CONTEXT_IRQ	0x73

#define SMMU_GLOBAL_VECTOR_OFFSET 0x1000
#define SMMU_NUM_CONTEXTS	0x80

#endif
