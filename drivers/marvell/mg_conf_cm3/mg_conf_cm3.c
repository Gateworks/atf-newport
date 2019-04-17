/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <a8k_plat_def.h>
#include <debug.h>
#include <mmio.h>
#include <mss_scp_bl2_format.h>
#include <string.h>

/* CONFI REGISTERS */
#define MG_CM3_CONFI_BASE(CP)		(MVEBU_CP_REGS_BASE(CP) + 0x100000)
#define MG_CM3_SRAM_BASE(CP)		MG_CM3_CONFI_BASE(CP)
#define MG_CM3_CONFI_GLOB_CFG_REG(CP)	(MG_CM3_CONFI_BASE(CP) + 0x2B500)
#define CM3_CPU_EN_BIT			BIT(28)
#define MG_CM3_MG_INT_MFX_REG(CP)	(MG_CM3_CONFI_BASE(CP) + 0x2B054)
#define CM3_SYS_RESET_BIT		BIT(0)

#define MG_SRAM_SIZE	0x20000 /* 128KB */

int mg_image_load(uintptr_t src_addr, uint32_t size, int cp_index)
{
	uintptr_t mg_regs = MG_CM3_SRAM_BASE(cp_index);

	if (size > MG_SRAM_SIZE) {
		ERROR("image is too big to fit into MG CM3 memory\n");
		return 1;
	}

	NOTICE("Loading MG image from address 0x%lx Size 0x%x to MG at 0x%lx\n",
	       src_addr, size, mg_regs);

	/* Copy image to MG CM3 SRAM */
	memcpy((void *)mg_regs, (void *)src_addr, size);

	/* Don't release MG CM3 from reset - it will be done by next step
	 * bootloader (e.g. U-Boot), when appriopriate device-tree setup (which
	 * has enabeld 802.3. auto-neg) will be choosen.
	 */

	return 0;
}

void mg_start_ap_fw(int cp_nr)
{
	if (mmio_read_32(MG_CM3_CONFI_GLOB_CFG_REG(cp_nr)) & CM3_CPU_EN_BIT) {
		VERBOSE("cm3 already running\n");
		return;  /* cm3 already running */
	}

	mmio_setbits_32(MG_CM3_CONFI_GLOB_CFG_REG(cp_nr), CM3_CPU_EN_BIT);
	mmio_setbits_32(MG_CM3_MG_INT_MFX_REG(cp_nr), CM3_SYS_RESET_BIT);

	/* TODO: add some routine for checking if ap process is running, if not
	 * disable cm3.
	 */
}
