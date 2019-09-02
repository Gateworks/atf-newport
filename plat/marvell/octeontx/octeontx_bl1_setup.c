/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#include <arch.h>
#include <bl_common.h>
#include <console.h>
#include <pl011.h>
#include <platform.h>
#include <platform_def.h>
#include <tbbr_img_def.h>
#include <xlat_tables_v2.h>
#include "../../../bl1/bl1_private.h"
#include <octeontx_common.h>
#include <octeontx_board_cfg.h>
#include <octeontx_board_cfg_setup.h>
#include <libfdt.h>
#include <debug.h>
#include <assert.h>
#include <bl1.h>
#include <octeontx_scfg_setup.h>
#include <plat_octeontx.h>
#include <octeontx_io_storage.h>
#include <octeontx_helpers.h>
#include <timers_octeontx.h>

#if ENABLE_ATTESTATION_SERVICE
#include <octeontx_attestation.h>
#include <auth/auth_mod.h>
#include <plat_octeontx.h>
#include <tbbr_oid.h>
#endif

/* Data structure which holds the extents of the trusted DRAM for BL1*/
static meminfo_t bl1_tzram_layout;

/* Data structure for console initialization */
static console_pl011_t console;

#if ENABLE_ATTESTATION_SERVICE
/*
 * This holds the BL1 platform data (which includes s/w attestation info).
 * Upon exit, the contents of this structure are passed to BL2.
 *
 * See also BL2 variable 'octeontx_bl2_plat_args'.
 */
static octeontx_bl_platform_args_t octeontx_bl1_plat_args;

/*
 * This populates the platform argument pointer that is passed to BL2
 * as 'arg0' - see also 'bl2_early_platform_setup2()'.
 */
static octeontx_bl_platform_args_t *populate_platform_args_for_bl2(void)
{
	const auth_img_desc_t *img_desc_ptr;
	const auth_param_desc_t *auth_param;
	int img_id;

	octeontx_bl1_plat_args.fdt = fdt_ptr;

	img_id = BL2_IMAGE_ID;
	if (!(auth_img_flags[img_id] & IMG_FLAG_AUTHENTICATED)) {
		ERROR("Image ID %u is not authenticated\n", img_id);
	} else {
		img_desc_ptr = &cot_desc_ptr[img_id];
		assert(img_desc_ptr->parent);

		/* parent image has authentication signature stored within */
		img_desc_ptr = &cot_desc_ptr[img_desc_ptr->parent->img_id];

		auth_param = &img_desc_ptr->authenticated_data[0];
		assert(!strcmp(auth_param->type_desc->cookie,
			       TRUSTED_BOOT_FW_HASH_OID));
		assert(auth_param->data.len ==
		       sizeof(octeontx_bl1_plat_args.atf_bl2_enc_sig));

		/*
		 * Implementation note: BL1 doesn't contain TLS support for
		 * decoding the [BL2 image] hash; so, we store the encoded
		 * hash and let BL2 decode it later (BL2 DOES contain TLS
		 * support for decoding hashes).
		 * This removes the requirement of adding [more] TLS support
		 * to BL1.
		 */
		memcpy(octeontx_bl1_plat_args.atf_bl2_enc_sig,
		       auth_param->data.ptr,
		       sizeof(octeontx_bl1_plat_args.atf_bl2_enc_sig));
	}

	return &octeontx_bl1_plat_args;
}
#endif

meminfo_t *bl1_plat_sec_mem_layout(void)
{
	return &bl1_tzram_layout;
}

void bl1_plat_arch_setup(void)
{
	mmap_add_region(bl1_tzram_layout.total_base, bl1_tzram_layout.total_base,
			BL_CODE_BASE - bl1_tzram_layout.total_base,
			MT_MEMORY | MT_RW | MT_SECURE);
	mmap_add_region(BL_CODE_BASE, BL_CODE_BASE,
			BL_CODE_END - BL_CODE_BASE,
			MT_MEMORY | MT_RO | MT_SECURE);
	mmap_add_region(BL_CODE_END, BL_CODE_END,
			bl1_tzram_layout.total_size - BL_CODE_END,
			MT_MEMORY | MT_RW | MT_SECURE);
#if USE_COHERENT_MEM
	mmap_add_region(BL_COHERENT_RAM_BASE, BL_COHERENT_RAM_BASE,
			BL_COHERENT_RAM_END - BL_COHERENT_RAM_BASE,
			MT_MEMORY | MT_RW | MT_SECURE);
#endif

	plat_add_mmio_map();

	init_xlat_tables();

	enable_mmu_el3(0);

	plat_octeontx_set_secondary_cpu_jump_addr(
				(uint64_t)plat_secondary_cold_boot_setup);
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
	snprintf(uid_prop, sizeof(uid_prop), "CHIP-UNIQUE-ID.NODE0");
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
	octeontx_fill_soc_details();
	octeontx_fill_board_details(1);

	timers_octeontx_init_delay();

        /* Initialise the IO layer and register platform IO devices */
        octeontx_io_setup();
}

void bl1_early_platform_setup(void)
{
	plat_octeontx_cpu_setup();

	/* Do it here. Later this region will be mapped as RO. */
	fdt_pack(fdt_ptr);

	/* Initialize the console to provide early debug support */
	console_pl011_register(UAAX_PF_BAR0(0), 0, 0, &console);
	console_set_scope((console_t *)&console, CONSOLE_FLAG_RUNTIME);
	console_switch_state(CONSOLE_FLAG_RUNTIME);

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
#if ENABLE_ATTESTATION_SERVICE
	ep_info->args.arg0 = (u_register_t)populate_platform_args_for_bl2();
#else
	ep_info->args.arg0 = (u_register_t)fdt_ptr;
#endif

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
