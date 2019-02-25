/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_COMMON_H__
#define __OCTEONTX_COMMON_H__

#include <stdint.h>
#include <xlat_tables_v2.h>
#include <arch_helpers.h>
#include <stddef.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "cavm-arch.h"
#pragma GCC diagnostic pop

#define MIDR_REVISION(midr)     ((midr) & MIDR_REV_MASK)
#define MIDR_PARTNUM(midr)      \
        (((midr) >> MIDR_PN_SHIFT) & MIDR_PN_MASK)

#define T81PARTNUM 0xA2
#define T83PARTNUM 0xA3
#define T98PARTNUM 0xB1
#define T96PARTNUM 0xB2
#define F95PARTNUM 0xB3

/* Boot type definitions */
#define OCTEONTX_BOOT_UNSUPPORTED	1
#define OCTEONTX_BOOT_REMOTE		10
#define OCTEONTX_BOOT_SPI		11
#define OCTEONTX_BOOT_EMMC		12

#undef AP_CVMCTL_EL1
#undef AP_CVM_ACCESS_EL1
#undef AP_CVMMEMCTL0_EL1
#undef AP_CVMMEMCTL1_EL1
#undef AP_CVM_ACCESS_EL2
#undef AP_CVM_ACCESS_EL3

#define AP_CVMCTL_EL1		S3_0_C11_C0_0
#define AP_CVMCTL2_EL1		S3_0_C11_C0_1
#define AP_CVM_ACCESS_EL1	S3_0_C11_C0_3
#define AP_CVMMEMCTL0_EL1	S3_0_C11_C0_4
#define AP_CVMMEMCTL1_EL1	S3_0_C11_C0_5
#define AP_CVMMEMCTL2_EL1	S3_0_C11_C0_6
#define AP_CVM_ACCESS_EL2	S3_4_C11_C0_3
#define AP_CVM_ACCESS_EL3	S3_6_C11_C0_3

DEFINE_RENAME_SYSREG_RW_FUNCS(cvmctl_el1, AP_CVMCTL_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmctl2_el1, AP_CVMCTL2_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmmemctl0_el1, AP_CVMMEMCTL0_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmmemctl1_el1, AP_CVMMEMCTL1_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmmemctl2_el1, AP_CVMMEMCTL2_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvm_access_el1, AP_CVM_ACCESS_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvm_access_el2, AP_CVM_ACCESS_EL2)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvm_access_el3, AP_CVM_ACCESS_EL3)

/*
 * Defines for AP_CVMMEMCTL2_EL1 register
 */
#define MTLB0_BLOCK_WIDTH	9
#define MTLB0_BLOCK_SHIFT	0
/* Default value for better performance */
#define MTLB0_BLOCK_VALUE	ULL(0xf)

#define TLBI_BLOCK_WIDTH	9
#define TLBI_BLOCK_SHIFT	16
/* Default value for better performance */
#define TLBI_BLOCK_VALUE	ULL(0xf)

/* In Mhz */
#define OCTEONTX_SYSCNT_FREQ	100ull

#define PCI_MSIX_CAP_ID		0x11

#define SMMU_NUM_CONTEXTS	0x80

#define set_bit(reg, bit) reg |= (1ULL<<(bit))
#define unset_bit(reg, bit) reg &= ~(1ULL<<(bit))

void add_map_record(unsigned long addr, unsigned long size, mmap_attr_t attr);

void plat_add_mmio_map(void);

extern void *fdt_ptr;
unsigned int octeontx_calc_core_pos(unsigned long mpidr);
void sata_ipm_quirk(void);

void plat_flr_init(void);

#ifdef NT_FW_CONFIG
void plat_octeontx_set_nt_fw_config_size(uint64_t nt_fw_config_size);
#endif

#endif /* __OCTEONTX_COMMON_H__ */
