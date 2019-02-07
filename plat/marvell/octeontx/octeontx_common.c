/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#include <arch.h>
#include <platform_def.h>
#include <xlat_tables_v2.h>
#include <stdio.h>
#include <stdlib.h>
#include <libfdt.h>
#include <octeontx_utils.h>
#include <octeontx_common.h>

#pragma weak plat_flr_init

extern void plat_add_mmio();

void *fdt_ptr = (void *)~0;

unsigned long plat_get_ns_image_entrypoint(void)
{
	return NS_IMAGE_BASE;
}

uint64_t plat_get_syscnt_freq2(void)
{
	return OCTEONTX_SYSCNT_FREQ * 1000 * 1000;
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

	/* Map BFDT structure */
	attr = MT_MEMORY | MT_RW | MT_SECURE;
	mmap_add_region(BOARD_CFG_BASE, BOARD_CFG_BASE, BOARD_CFG_MAX_SIZE, attr);

	attr = MT_MEMORY | MT_RW | MT_NS;
	mmap_add_region(NS_IMAGE_BASE, NS_IMAGE_BASE, NS_IMAGE_MAX_SIZE, attr);
}

void plat_add_mmio_map()
{
	plat_add_mmio_common();

	plat_add_mmio();
}

void octeontx_cpu_setup(void)
{
	uint64_t cvmctl_el1, cvmmemctl0_el1, cvmmemctl1_el1, midr;
#if (defined(PLAT_t96) || defined(PLAT_f95))
	uint64_t cvmmemctl2_el1;
#endif

	cvmctl_el1 = read_cvmctl_el1();
	cvmmemctl0_el1 = read_cvmmemctl0_el1();
	cvmmemctl1_el1 = read_cvmmemctl1_el1();
#if (defined(PLAT_t96) || defined(PLAT_f95))
	cvmmemctl2_el1 = read_cvmmemctl2_el1();
#endif
	midr = read_midr();

	/* Enable CAS/CASP and v8.1 support for T96, F95 and T83 pass >1.0,
	   disable for previous models. */
	if ((MIDR_PARTNUM(midr) == T96PARTNUM)
	    || (MIDR_PARTNUM(midr) == F95PARTNUM)) {
		unset_bit(cvmctl_el1, 36);  /* Enable CAS */
		unset_bit(cvmctl_el1, 37);  /* Enable CASP */
	} else if ((MIDR_PARTNUM(midr) == T83PARTNUM)
		&& !(IS_OCTEONTX_PASS(midr, T83PARTNUM, 1, 0))) {
		unset_bit(cvmctl_el1, 36);  /* Enable CAS */
		unset_bit(cvmctl_el1, 37);  /* Enable CASP */
		set_bit(cvmctl_el1, 33);    /* Enable v8.1 */
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

	/* Set cvm_ctl_el1[5] to workaround debug state execution in incorrect EL */
	if (IS_OCTEONTX_PASS(midr, T96PARTNUM, 1, 0))
		set_bit(cvmctl_el1, 5);

	if (MIDR_PARTNUM(midr) == T83PARTNUM) {
		set_bit(cvmmemctl1_el1, 3); /* Enable LMTST */
		set_bit(cvmmemctl1_el1, 4); /* Enable SSO/PKO addr region */
		set_bit(cvmmemctl1_el1, 5); /* Trap any accesses to nonzero node id */

		if (IS_OCTEONTX_PASS(midr, T83PARTNUM, 1, 0)) {
			unset_bit(cvmmemctl1_el1, 6); /* Disable SSO switch tag */
		} else {
			set_bit(cvmmemctl1_el1, 6); /* Enable SSO switch tag */
		}
	} else if ((MIDR_PARTNUM(midr) == T96PARTNUM)
		|| (MIDR_PARTNUM(midr) == F95PARTNUM)) {
		set_bit(cvmmemctl1_el1, 3); /* Enable LMTST */
		set_bit(cvmmemctl1_el1, 4); /* Enable SSO/PKO addr region */
		set_bit(cvmmemctl1_el1, 5); /* Trap any accesses to nonzero node id */
		set_bit(cvmmemctl1_el1, 6); /* Enable SSO switch tag */
	}

	if ((MIDR_PARTNUM(midr) == F95PARTNUM)) {
		set_bit(cvmmemctl1_el1, 58); /* Enable 128-bit access to BPHY */
	}

#if (defined(PLAT_t96) || defined(PLAT_f95))
	/*
	 * To improve performance memory-unit for EL1 should be configured in
	 * different way than default.
	 */
	if ((MIDR_PARTNUM(midr) == T96PARTNUM)
	    || (MIDR_PARTNUM(midr) == F95PARTNUM)) {
		cvmmemctl2_el1 = octeontx_bit_insert(
			cvmmemctl2_el1, MTLB0_BLOCK_VALUE,
			MTLB0_BLOCK_SHIFT, MTLB0_BLOCK_WIDTH);
		cvmmemctl2_el1 = octeontx_bit_insert(
			cvmmemctl2_el1, TLBI_BLOCK_VALUE,
			TLBI_BLOCK_SHIFT, TLBI_BLOCK_WIDTH);
	}
#endif

	/* Fix up defaults from the BDK which is broken and violates the ARM ARM. */
	unset_bit(cvmmemctl0_el1, 17); /* Don't reset timer on merge as that violates the ARM ARM. */
	unset_bit(cvmmemctl0_el1, 18); /* Set Write-buffer timeout for NSH entries to 218 cycles. */

	write_cvmctl_el1(cvmctl_el1);
	write_cvmmemctl0_el1(cvmmemctl0_el1);
	write_cvmmemctl1_el1(cvmmemctl1_el1);

#if (defined(PLAT_t96) || defined(PLAT_f95))
	write_cvmmemctl2_el1(cvmmemctl2_el1);
#endif

	/* Allow CVM CACHE instructions from EL1/EL2 */
	write_cvm_access_el1(read_cvm_access_el1() & ~(1 << 8));
	write_cvm_access_el2(read_cvm_access_el2() & ~(1 << 8));
	write_cvm_access_el3(read_cvm_access_el3() & ~(1 << 8));
}

void plat_error_handler(int err_code)
{
#if TRUSTED_BOARD_BOOT
	/* Handle platform-specific secure boot failure cause */
	cavm_rst_boot_t rst_boot;

	rst_boot.u = CSR_READ(CAVM_RST_BOOT);
	rst_boot.s.dis_huk = 1;
	CSR_WRITE(CAVM_RST_BOOT, rst_boot.u);
#endif
	for(;;);
}

void plat_flr_init(void) {
	return;
}
