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
