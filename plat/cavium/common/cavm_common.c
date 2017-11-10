/** @file

  Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <platform_def.h>
#include <xlat_tables.h>
#include <stdio.h>
#include <stdlib.h>
#include <libfdt.h>
#include <cavm_private.h>
#include <cavm_common.h>


extern void plat_add_mmio_node(unsigned long node);
extern unsigned thunder_get_node_count(void);
extern int plat_get_boot_type(int boot_mode);

void *fdt_ptr = (void *)~0;

unsigned long plat_get_ns_image_entrypoint(void)
{
	return NS_IMAGE_BASE;
}

uint64_t plat_get_syscnt_freq2(void)
{
	return THUNDER_SYSCNT_FREQ * 1000 * 1000;
}

#define ROUND_DOWN(val, align)	((val) / (align) * (align))
#define ROUND_UP(val, align)	(((val) + (align) - 1) / (align) * (align))

void add_map_record(unsigned long addr, unsigned long size, mmap_attr_t attr)
{
	/* Round up to sensible boundry */
	mmap_add_region(ROUND_DOWN(addr, 2*1024*1024),
			ROUND_DOWN(addr, 2*1024*1024),
			ROUND_UP(size, 2*1024*1024),
			attr);
}

static void plat_add_mmio_common(void)
{
	unsigned long attr;

	/* Shared Memory */
	/* Do not use add_map_record here, it will round size up */
	attr = MT_MEMORY | MT_RO | MT_SECURE;

	if (fdt_ptr != (void *)~0)
		mmap_add_region((unsigned long)fdt_ptr, (unsigned long)fdt_ptr,
			TZDRAM_SIZE - (unsigned long)fdt_ptr,
			attr);

	attr = MT_MEMORY | MT_RW | MT_NS;
	mmap_add_region(NS_IMAGE_BASE, NS_IMAGE_BASE, NS_IMAGE_MAX_SIZE, attr);
}

void plat_add_mmio_map()
{
	unsigned long node, node_count;

	plat_add_mmio_common();

	node_count = thunder_get_node_count();
	for (node = 0; node < node_count; node++)
		plat_add_mmio_node(node);
}

#define set_bit(reg, bit) reg |= (1ULL<<(bit))
#define unset_bit(reg, bit) reg &= ~(1ULL<<(bit))

void thunder_cpu_setup(void)
{
	uint64_t cvmctl_el1, cvmmemctl0_el1, cvmmemctl1_el1, midr;

	cvmctl_el1 = read_cvmctl_el1();
	cvmmemctl0_el1 = read_cvmmemctl0_el1();
	cvmmemctl1_el1 = read_cvmmemctl1_el1();
	midr = read_midr();

	/* Enable CAS/CASP and v8.1 support for T93, disable for previous models. */
	if (MIDR_PARTNUM(midr) == T93PARTNUM) {
		unset_bit(cvmctl_el1, 36);  /* Enable CAS */
		unset_bit(cvmctl_el1, 37);  /* Enable CASP */
	} else {
		set_bit(cvmctl_el1, 36);  /* Disable CAS */
		set_bit(cvmctl_el1, 37);  /* Disable CASP */
		unset_bit(cvmctl_el1, 33);    /* Disable v8.1 */
	}

	/* Enable prefetcher */
	set_bit(cvmctl_el1, 43);   /* Ignore the bp for next line prefetcher. */
	set_bit(cvmctl_el1, 42);   /* Use stride of 2. */
	set_bit(cvmctl_el1, 41);   /* Enable next line prefetcher. */
	set_bit(cvmctl_el1, 40);   /* Enable delta prefetcher. */

	if (MIDR_PARTNUM(midr) == T83PARTNUM) {
		set_bit(cvmmemctl1_el1, 3); /* Enable LMTST */
		set_bit(cvmmemctl1_el1, 4); /* Enable SSO/PKO addr region */
		if (IS_THUNDER_PASS(midr, T83PARTNUM, 1, 0)) {
			unset_bit(cvmmemctl1_el1, 6); /* Disable SSO switch tag */
		} else {
			set_bit(cvmmemctl1_el1, 6); /* Enable SSO switch tag */
		}
	} else if (MIDR_PARTNUM(midr) == T93PARTNUM) {
		set_bit(cvmmemctl1_el1, 3); /* Enable LMTST */
		set_bit(cvmmemctl1_el1, 4); /* Enable SSO/PKO addr region */
	}

	/* Fix up defaults from the BDK which is broken and violates the ARM ARM. */
	unset_bit(cvmmemctl0_el1, 17); /* Don't reset timer on merge as that violates the ARM ARM. */
	unset_bit(cvmmemctl0_el1, 18); /* Set Write-buffer timeout for NSH entries to 218 cycles. */

	write_cvmctl_el1(cvmctl_el1);
	write_cvmmemctl0_el1(cvmmemctl0_el1);
	write_cvmmemctl1_el1(cvmmemctl1_el1);

	/* Allow CVM CACHE instructions from EL1/EL2 */
	write_cvm_access_el1(read_cvm_access_el1() & ~(1 << 8));
	write_cvm_access_el2(read_cvm_access_el2() & ~(1 << 8));
	write_cvm_access_el3(read_cvm_access_el3() & ~(1 << 8));
}

/* Flush the L2 Cache */
void l2c_flush(void)
{
	/* Select the L2 cache */
	union cavm_ap_csselr_el1 csselr_el1;
	union cavm_ap_ccsidr_el1 ccsidr_el1;
	unsigned int sets, ways;
	int l2_way, l2_set;
	uint64_t val;

	csselr_el1.s.level = 1;

	__asm__ volatile ("msr csselr_el1, %0" : : "r"((uint64_t)csselr_el1.u));

	__asm__ volatile ("mrs %0, ccsidr_el1" : "=&r"(val));

	ccsidr_el1.u = val;

	sets = ccsidr_el1.s.numsets + 1;
	ways = ccsidr_el1.s.associativity + 1;

	int is_rtg = 1; /* Clear remote tags */

	for (l2_way = 0; l2_way < ways; l2_way++) {
		for (l2_set = 0; l2_set < sets; l2_set++) {
			val = 128 * (l2_set + sets * (l2_way + (is_rtg * 16)));
			__asm__ volatile("sys #0,c11,C0,#5, %0\n" : : "r"(val));
		}
	}

	is_rtg = 0; /* Clear local tags */
	for (l2_way = 0; l2_way < ways; l2_way++) {
		for (l2_set = 0; l2_set < sets; l2_set++) {
			val = 128 * (l2_set + sets * (l2_way + (is_rtg * 16)));
			__asm__ volatile("sys #0,c11,C0,#5, %0\n" : : "r"(val));
		}
	}
}
