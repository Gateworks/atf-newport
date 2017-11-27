/** @file

  Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
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
#include <platform.h>
#include <platform_def.h>
#include <tbbr_img_def.h>
#include <xlat_tables.h>
#include "../../../bl1/bl1_private.h"
#include <cavm_common.h>
#include <cavm_dt.h>
#include <libfdt.h>
#include <debug.h>
#include <assert.h>
#include <bl1.h>

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

int bl1_plat_handle_post_image_load(unsigned int image_id)
{
	meminfo_t *bl2_tzram_layout;
	meminfo_t *bl1_tzram_layout;
	image_desc_t *image_desc;
	entry_point_info_t *ep_info;

	if (image_id != BL2_IMAGE_ID)
		return 0;

	/* Get the image descriptor */
	image_desc = bl1_plat_get_image_desc(BL2_IMAGE_ID);
	assert(image_desc != NULL);

	/* Get the entry point info */
	ep_info = &image_desc->ep_info;

	/* Find out how much free trusted ram remains after BL1 load */
	bl1_tzram_layout = bl1_plat_sec_mem_layout();

	/*
	 * Create a new layout of memory for BL2 as seen by BL1 i.e.
	 * tell it the amount of total and free memory available.
	 * This layout is created at the first free address visible
	 * to BL2. BL2 will read the memory layout before using its
	 * memory for other purposes.
	 */
#if LOAD_IMAGE_V2
	/* Original ATF tries to put BL2 tzram layout at the start of the
	 * memory, which overwrites BDK/images in case of remote loading
	 * through PCIe.  Just place tzram layout in RAM segment of memory, BL2
	 * will read it early enough, before setting MMU regions */
	/*bl2_tzram_layout = (meminfo_t *) bl1_tzram_layout->total_base; */
	static meminfo_t inram_bl2_tzram_layout;
	bl2_tzram_layout = &inram_bl2_tzram_layout;
#else
	bl2_tzram_layout = (meminfo_t *) bl1_tzram_layout->free_base;
#endif /* LOAD_IMAGE_V2 */

#if !ERROR_DEPRECATED
	bl1_init_bl2_mem_layout(bl1_tzram_layout, bl2_tzram_layout);
#else
	bl1_calc_bl2_mem_layout(bl1_tzram_layout, bl2_tzram_layout);
#endif

	ep_info->args.arg1 = (uintptr_t)bl2_tzram_layout;

	VERBOSE("BL1: BL2 memory layout address = %p\n",
		(void *) bl2_tzram_layout);
	return 0;
}
