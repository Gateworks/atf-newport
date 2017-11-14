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
#include <bl_common.h>
#include <console.h>
#include <platform_def.h>
#include <tbbr_img_def.h>
#include <xlat_tables.h>
#include "../../../bl1/bl1_private.h"
#include <thunder_private.h>
#include <thunder_dt.h>
#include <libfdt.h>
#include <debug.h>

#define BL1_RO_BASE (unsigned long)(&__RO_START__)
#define BL1_RO_LIMIT (unsigned long)(&__RO_END__)

#if USE_COHERENT_MEM
/*
 * The next 2 constants identify the extents of the coherent memory region.
 * These addresses are used by the MMU setup code and therefore they must be
 * page-aligned.  It is the responsibility of the linker script to ensure that
 * __COHERENT_RAM_START__ and __COHERENT_RAM_END__ linker symbols refer to
 * page-aligned addresses.
 */
#define BL1_COHERENT_RAM_BASE (unsigned long)(&__COHERENT_RAM_START__)
#define BL1_COHERENT_RAM_LIMIT (unsigned long)(&__COHERENT_RAM_END__)
#endif


/* Data structure which holds the extents of the trusted DRAM for BL1*/
static meminfo_t bl1_tzram_layout;

meminfo_t *bl1_plat_sec_mem_layout(void)
{
	return &bl1_tzram_layout;
}

void bl1_plat_arch_setup(void)
{
	mmap_add_region(bl1_tzram_layout.total_base, bl1_tzram_layout.total_base,
			BL1_RO_BASE - bl1_tzram_layout.total_base,
			MT_MEMORY | MT_RW | MT_SECURE);
	mmap_add_region(BL1_RO_BASE, BL1_RO_BASE,
			BL1_RO_LIMIT - BL1_RO_BASE,
			MT_MEMORY | MT_RO | MT_SECURE);
	mmap_add_region(BL1_RO_LIMIT, BL1_RO_LIMIT,
			bl1_tzram_layout.total_size - BL1_RO_LIMIT,
			MT_MEMORY | MT_RW | MT_SECURE);
#if USE_COHERENT_MEM
	mmap_add_region(BL1_COHERENT_RAM_BASE, BL1_COHERENT_RAM_BASE,
			BL1_COHERENT_RAM_LIMIT - BL1_COHERENT_RAM_BASE,
			MT_MEMORY | MT_RW | MT_SECURE);
#endif

	plat_add_mmio_map();

	init_xlat_tables();

	enable_mmu_el3(0);

	set_secondary_cpu_jump_addr(BL1_RW_BASE);
}

void bl1_platform_print_chip_id(void)
{
	const void *fdt = fdt_ptr;
	const char *uid;
	char uid_prop[21];
	int offset, len;

	offset = fdt_path_offset(fdt, "/cavium,bdk");
	if (offset < 0) {
		INFO("WARNING: FDT node not found\n");
		return;
	}
	snprintf(uid_prop, sizeof(uid_prop), "CHIP-UNIQUE-ID.NODE%d",
		 cavm_numa_local());
	uid = fdt_getprop(fdt, offset, uid_prop, &len);
	if (uid) {
		if (!strncmp(uid, "00000000000000000000", 20))
			NOTICE("CHIP UniqueID not set\n");
		else
			NOTICE("CHIP UniqueID = %s\n", uid);

	} else {
		INFO("WARNING: No CHIP-Unique-ID is found\n");
		NOTICE("CHIP UniqueID not set\n");
	}
}

void bl1_platform_setup(void)
{
	bl1_platform_print_chip_id();
	thunder_fill_board_details(1);

        /* Initialise the IO layer and register platform IO devices */
        thunder_io_setup();
}

void bl1_early_platform_setup(void)
{
	thunder_cpu_setup();

	/* Do it here. Later this region will be mapped as RO. */
	fdt_pack(fdt_ptr);

	/* Initialize the console to provide early debug support */
	console_init(CSR_PA(0, CAVM_UAAX_PF_BAR0(0)), 0, 0);

	/* Allow BL1 to see the whole Trusted RAM */
	bl1_tzram_layout.total_base = TZDRAM_BASE;
	bl1_tzram_layout.total_size = TZDRAM_SIZE;

	/* Calculate how much RAM BL1 is using and how much remains free */
#if !LOAD_IMAGE_V2
	bl1_tzram_layout.free_base = TZDRAM_BASE;
	bl1_tzram_layout.free_size = TZDRAM_SIZE;
	reserve_mem(&bl1_tzram_layout.free_base,
		    &bl1_tzram_layout.free_size,
		    BL1_RAM_BASE,
		    BL1_RAM_LIMIT - BL1_RAM_BASE);
	reserve_mem(&bl1_tzram_layout.free_base,
		    &bl1_tzram_layout.free_size,
		    0,
		    BL31_BASE);
#endif
}

void bl1_plat_set_ep_info(unsigned int image_id,
		entry_point_info_t *ep_info)
{
	ep_info->args.arg2 = (unsigned long)fdt_ptr;

}
