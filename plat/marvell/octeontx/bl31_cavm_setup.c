/*
 * Copyright (c) 2013-2014, ARM Limited and Contributors. All rights reserved.
 * Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <arch.h>
#include <arch_helpers.h>
#include <assert.h>
#include <bl_common.h>
#include <bl31.h>
#include <console.h>
#include <mmio.h>
#include <pl011.h>
#include <platform.h>
#include <interrupt_mgmt.h>
#include <stddef.h>
#include <xlat_tables_v2.h>
#include <cavm_common.h>
#include <cavm_board_cfg.h>
#include <debug.h>
#include <timers.h>
#include <platform_def.h>
#include <plat_cavm.h>
#include <cavm_gicv3.h>
#include <cavm_security.h>
#include <cavm_dram.h>


static entry_point_info_t bl33_image_ep_info, bl32_image_ep_info;

/* Data structure for console initialization */
static console_pl011_t console;

/*******************************************************************************
 * Return a pointer to the 'entry_point_info' structure of the next image for the
 * security state specified. BL33 corresponds to the non-secure image type
 * while BL32 corresponds to the secure image type. A NULL pointer is returned
 * if the image does not exist.
 ******************************************************************************/
entry_point_info_t *bl31_plat_get_next_image_ep_info(uint32_t type)
{
	assert(sec_state_is_valid(type));

	if (type == NON_SECURE)
		return &bl33_image_ep_info;

	/* Currently Cavium platforms does not support BL32 image,
	 * for SECURE type image return NULL */
	return NULL;
}

/*******************************************************************************
 * Perform any BL31 specific platform actions. Here is an opportunity to copy
 * parameters passed by the calling EL (S-EL1 in BL2 & S-EL3 in BL1) before they
 * are lost (potentially). This needs to be done before the MMU is initialized
 * so that the memory layout can be used while creating page tables. On the FVP
 * we know that BL2 has populated the parameters in secure DRAM. So we just use
 * the reference passed in 'from_bl2' instead of copying. The 'data' parameter
 * is not used since all the information is contained in 'from_bl2'. Also, BL2
 * has flushed this information to memory, so we are guaranteed to pick up good
 * data
 ******************************************************************************/
#if LOAD_IMAGE_V2
void bl31_early_platform_setup(void *from_bl2,
				void *plat_params_from_bl2)
#else
void bl31_early_platform_setup(bl31_params_t *from_bl2,
				void *plat_params_from_bl2)
#endif
{
	console_pl011_register(UAAX_PF_BAR0(0), 0, 0, &console);

#if LOAD_IMAGE_V2
	/*
	 * Check params passed from BL2 should not be NULL,
	 */
	bl_params_t *params_from_bl2 = (bl_params_t *)from_bl2;
	assert(params_from_bl2 != NULL);
	assert(params_from_bl2->h.type == PARAM_BL_PARAMS);
	assert(params_from_bl2->h.version >= VERSION_2);

	fdt_ptr = plat_params_from_bl2;
	bl_params_node_t *bl_params = params_from_bl2->head;

	/*
	 * Copy BL33 and BL32 (if present), entry point information.
	 * They are stored in Secure RAM, in BL2's address space.
	 */
	while (bl_params) {
		if (bl_params->image_id == BL32_IMAGE_ID)
			bl32_image_ep_info = *bl_params->ep_info;

		if (bl_params->image_id == BL33_IMAGE_ID)
			bl33_image_ep_info = *bl_params->ep_info;

		bl_params = bl_params->next_params_info;
	}

	if (bl33_image_ep_info.pc == 0)
		panic();

#else /* LOAD_IMAGE_V2 */

	/* Check params passed from BL2 should not be NULL,
	 * We are not checking plat_params_from_bl2 as NULL as we are not
	 * using it on FVP
	 */
	assert(from_bl2 != NULL);
	assert(from_bl2->h.type == PARAM_BL31);
	assert(from_bl2->h.version >= VERSION_1);

	fdt_ptr = plat_params_from_bl2;

	/*
	 * Copy BL3-3, BL3-2 entry point information.
	 * They are stored in Secure RAM, in BL2's address space.
	 */
	if (from_bl2->bl32_ep_info)
		bl32_image_ep_info = *from_bl2->bl32_ep_info;
	bl33_image_ep_info = *from_bl2->bl33_ep_info;
#endif /* LOAD_IMAGE_V2 */

}


void bl31_early_platform_setup2(u_register_t arg0, u_register_t arg1,
				u_register_t arg2, u_register_t arg3)
{
	bl31_early_platform_setup((void *)arg0, (void *)arg1);
}

static void octeontx_el3_irq_init(void)
{
	uint32_t flags;
	int32_t rc;

	flags = 0;
	set_interrupt_rm_flag(flags, SECURE);
	set_interrupt_rm_flag(flags, NON_SECURE);

	rc = register_interrupt_type_handler(INTR_TYPE_EL3, handle_irq_el3, flags);
	if (rc)
		printf("err %d on registering secure handler;\n", rc);
}

/*******************************************************************************
 * Initialize the gic, configure the CLCD and zero out variables needed by the
 * secondaries to boot up correctly.
 ******************************************************************************/
void bl31_platform_setup()
{
	/*
	 * In order to keep MMC functional in non-secure world, we must
	 * make the device have access to non-secure memory. It is safe to
	 * do it here, because every firmware image is loaded at this time.
	 */
	octeontx_configure_mmc_security(0); /* non-secure */
	octeontx_el3_irq_init();
	octeontx_gic_driver_init();
	octeontx_gic_init();
	timers_init();
	/* This API is platform dependent. It can be any boot time
	 * initialization that needs to be performed related to
	 * firmware services provided in BL31
	 */
	plat_octeontx_setup();

	/*
	 * Apply SATA quirk only for CN8XXX family
	 */
	if (cavm_is_model(OCTEONTX_CN8XXX)) {
		sata_ipm_quirk();
	}

	/* Intialize the power controller */
	plat_pwrc_setup();
}

/*******************************************************************************
 * Perform the very early platform specific architectural setup here. At the
 * moment this is only intializes the mmu in a quick and dirty way.
 ******************************************************************************/
void bl31_plat_arch_setup()
{
	uintptr_t ns_dma_memory_base = octeontx_dram_size() - NS_DMA_MEMORY_SIZE;
	mmap_add_region(BL_CODE_BASE, BL_CODE_BASE,
			BL31_END - BL_CODE_BASE,
			MT_MEMORY | MT_RW | MT_SECURE);
	mmap_add_region(BL_CODE_BASE, BL_CODE_BASE,
			BL_CODE_END - BL_CODE_BASE,
			MT_MEMORY | MT_RO | MT_SECURE);

	mmap_add_region(MAILBOX_BASE, MAILBOX_BASE,
			MAILBOX_MAX_SIZE,
			MT_MEMORY | MT_RW | MT_SECURE);

#if USE_COHERENT_MEM
	mmap_add_region(BL_COHERENT_RAM_BASE, BL_COHERENT_RAM_BASE,
			BL_COHERENT_RAM_END - BL_COHERENT_RAM_BASE,
			MT_MEMORY | MT_RW | MT_SECURE);
#endif

	mmap_add_region(ns_dma_memory_base, ns_dma_memory_base,
			NS_DMA_MEMORY_SIZE,
			MT_DEVICE | MT_RW | MT_NS);

	plat_add_mmio_map();

	init_xlat_tables();

	enable_mmu_el3(0);
}

void bl31_plat_runtime_setup(void)
{
#ifndef DEBUG
	console_uninit();
#endif
}
