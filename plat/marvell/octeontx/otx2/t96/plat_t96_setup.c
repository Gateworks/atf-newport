/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <debug.h>
#include <platform.h>
#include <platform_def.h>
#include <platform_setup.h>
#include <octeontx_common.h>
#include <gpio_octeontx.h>
#include <octeontx_utils.h>
#include <platform_scfg.h>
#include <octeontx_plat_configuration.h>
#include <plat_otx2_configuration.h>
#include <plat_octeontx.h>

static uint64_t msix_addr_save;

int plat_octeontx_get_ecams_count(void)
{
	return 1;
}

int plat_octeontx_get_iobn_count(void)
{
	if (plat_get_altpkg() == CN95XXE_PKG)
		return 1;

	return 2;
}

/*
 * SATA to GSER mapping
 * SATA(0-1) --- DLM4
 * SATA(2-3) --- DLM5
 */
int plat_octeontx_sata_to_gser(int ctrlr)
{
	if (plat_get_altpkg() == CN95XXE_PKG)
		return -1;

	if (ctrlr > 3)
		return -1;

	return ((ctrlr > 1) ? 5 : 4);
}

int plat_octeontx_sata_to_lane(int ctrlr)
{
	if (plat_get_altpkg() == CN95XXE_PKG)
		return -1;

	if (ctrlr > 3)
		return -1;

	return ((ctrlr > 1) ? ctrlr - 2 : ctrlr);
}

int plat_octeontx_is_lmc_enabled(unsigned lmc)
{
	union cavm_lmcx_dll_ctl2 lmcx_dll_ctl2;

	if ((plat_get_altpkg() == CN95XXE_PKG)
	    && (lmc == 1)) {
		return 0;
	} else if ((plat_get_altpkg() == CN93XX_PKG)
	    && (lmc == 2)) {
		return 0;
	}

	lmcx_dll_ctl2.u = CSR_READ(CAVM_LMCX_DLL_CTL2(lmc));

	return (lmcx_dll_ctl2.cn96xx.dreset ? 0 : 1);
}

/*******************************************************************************
 * Setup secondary CPU JUMP address from RESET
 ******************************************************************************/
void plat_octeontx_set_secondary_cpu_jump_addr(uint64_t entrypoint_addr)
{
	/*
	 * Assembly for ROM memory:
	 *  d508711f        ic      ialluis
	 *  d503201f        nop
	 *  58000040        ldr     x0, 328 <branch_addr>
	 *  d61f0000        br      x0
	 *              branch_addr:
	 * Memory is little endain, so 64 bit constants have the first
	 * instruction in the low word
	 */
	CSR_WRITE(CAVM_ROM_MEMX(0), 0xd503201fd508711f);
	CSR_WRITE(CAVM_ROM_MEMX(1), 0xd61f000058000040);
	CSR_WRITE(CAVM_ROM_MEMX(2), entrypoint_addr);
}

int plat_octeontx_get_ccu_count(void)
{
	return 4;
}

int plat_octeontx_get_mpi_count(void)
{
	return 2;
}

int plat_octeontx_get_smmu_count(void)
{
	return 1;
}

int plat_octeontx_get_twsi_count(void)
{
	return 6;
}

int plat_octeontx_get_cpt_count(void)
{
	if (plat_get_altpkg() == CN95XXE_PKG)
		return 0;

	return 1;
}

int plat_octeontx_get_cgx_count(void)
{
	if (plat_get_altpkg() == CN93XX_PKG)
		return 2;

	return 3;
}

int plat_octeontx_get_pem_count(void)
{
	if (plat_get_altpkg() == CN95XXE_PKG)
		return 1;

	return 3;
}

int plat_octeontx_get_gser_count(void)
{
	if (plat_get_altpkg() == CN93XX_PKG)
		return 6;

	return 8;
}

int plat_octeontx_get_uaa_count(void)
{
	return 8;
}

int plat_octeontx_get_rvu_count(void)
{
	return 16;
}

/* Return number of lanes available for different QLMs. */
int plat_get_max_lane_num(int qlm)
{
	if ((qlm == 4) || (qlm == 5))
		return 2;
	return 4;
}

/* Return the CGX<->QLM mapping */
int plat_get_cgx_idx(int qlm)
{
	int idx;

	switch (qlm) {
	case 3:
	case 7:
		idx = 0;
		break;
	case 4:
	case 5:
		idx = 1;
		break;
	case 6:
		idx = 2;
		break;
	default:
		idx = -1;
		break;
	}

	return idx;
}

/*
 * BDK uses CPC RAM memory as key memory.
 * This is indicated by storing the ROTPK at TRUST-ROT-ADDR,
 * which is in range of CPC_RAM_MEMX.
 * Moreover, ATF needs to have access to SCP-AP Secure0 mailbox.
 * Map required memory as MT_RW.
 */
void plat_map_cpc_mem()
{
	cavm_cpc_const_t cpc_const;
	unsigned long cpc_ram_size, attr;

	/* Calculate CPC RAM size based on a number of 16KB memory regions */
	cpc_const.u = CSR_READ(CAVM_CPC_CONST);
	cpc_ram_size = cpc_const.s.mem_regions * 0x4000;

	attr = MT_MEMORY | MT_RW | MT_SECURE;
	add_map_record(CAVM_CPC_RAM_MEMX(0),
		       cpc_ram_size, attr);

	/* Map required XCP memory region for doorbell registers */
	add_map_record(CAVM_XCP_BAR_E_XCPX_PF_BAR0(CAVM_CPC_XCP_MAP_E_SCP),
		       CAVM_XCP_BAR_E_XCPX_PF_BAR0_SIZE, attr);
}

void plat_add_mmio()
{
	unsigned long attr;
	int i, device_type_count;

	attr = MT_DEVICE | MT_RW | MT_SECURE;
	add_map_record(CAVM_RST_BAR_E_RST_PF_BAR0_CN9, CAVM_RST_BAR_E_RST_PF_BAR0_CN9_SIZE, attr);
	add_map_record(CAVM_RST_BAR_E_RST_PF_BAR2, CAVM_RST_BAR_E_RST_PF_BAR2_SIZE, attr);
	add_map_record(CAVM_RST_BAR_E_RST_PF_BAR4, CAVM_RST_BAR_E_RST_PF_BAR4_SIZE, attr);

	device_type_count = plat_octeontx_get_ccu_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CAVM_CCU_BAR_E_CCUX_PF_BAR0(i), CAVM_CCU_BAR_E_CCUX_PF_BAR0_SIZE, attr);
		add_map_record(CAVM_CCU_BAR_E_CCUX_PF_BAR4(i), CAVM_CCU_BAR_E_CCUX_PF_BAR4_SIZE, attr);
	}
	add_map_record(CAVM_CCS_BAR_E_CCS_PF_BAR0, CAVM_CCS_BAR_E_CCS_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_MIO_BOOT_BAR_E_MIO_BOOT_PF_BAR0, CAVM_MIO_BOOT_BAR_E_MIO_BOOT_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR0_CN9, CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR0_CN9_SIZE, attr);
	add_map_record(CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR4, CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR4_SIZE, attr);
	add_map_record(CAVM_FUS_BAR_E_FUS_PF_BAR0,
		       CAVM_FUS_BAR_E_FUS_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_FUSF_BAR_E_FUSF_PF_BAR0,
		       CAVM_FUSF_BAR_E_FUSF_PF_BAR0_SIZE, attr);

	device_type_count = plat_octeontx_get_mpi_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CAVM_MPI_BAR_E_MPIX_PF_BAR0(i), CAVM_MPI_BAR_E_MPIX_PF_BAR0_SIZE, attr);
		add_map_record(CAVM_MPI_BAR_E_MPIX_PF_BAR4(i), CAVM_MPI_BAR_E_MPIX_PF_BAR4_SIZE, attr);
	}
	add_map_record(CAVM_GIC_BAR_E_GIC_PF_BAR2, CAVM_GIC_BAR_E_GIC_PF_BAR2_SIZE, attr);
	add_map_record(GIC_PF_BAR4, GIC_PF_BAR4_SIZE, attr);

	device_type_count = plat_octeontx_get_smmu_count();
	for (i = 0; i < device_type_count; i++)
		add_map_record(CAVM_SMMU_BAR_E_SMMUX_PF_BAR0_CN8(i), CAVM_SMMU_BAR_E_SMMUX_PF_BAR0_CN8_SIZE, attr);

	add_map_record(CAVM_GTI_BAR_E_GTI_PF_BAR0_CN9, CAVM_GTI_BAR_E_GTI_PF_BAR0_CN9_SIZE, attr);
	add_map_record(CAVM_GTI_BAR_E_GTI_PF_BAR4_CN9, CAVM_GTI_BAR_E_GTI_PF_BAR4_CN9_SIZE, attr);

	for (i = 0; i < MAX_LMC; i++) {
		add_map_record(CAVM_LMC_BAR_E_LMCX_PF_BAR0(i), CAVM_LMC_BAR_E_LMCX_PF_BAR0_SIZE, attr);
		add_map_record(CAVM_LMC_BAR_E_LMCX_PF_BAR4(i), CAVM_LMC_BAR_E_LMCX_PF_BAR4_SIZE, attr);
	}

	device_type_count = plat_octeontx_get_twsi_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR0_CN9(i), CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR0_CN9_SIZE, attr);
		add_map_record(CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4(i), CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4_SIZE, attr);
	}

	device_type_count = plat_octeontx_get_cpt_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CAVM_CPT_BAR_E_CPTX_PF_BAR0(i), CAVM_CPT_BAR_E_CPTX_PF_BAR0_SIZE, attr);
		add_map_record(CAVM_CPT_BAR_E_CPTX_PF_BAR4(i), CAVM_CPT_BAR_E_CPTX_PF_BAR4_SIZE, attr);
		add_map_record(CAVM_CPT_BAR_E_CPTX_VFX_BAR0(i, 0), 64*CAVM_CPT_BAR_E_CPTX_VFX_BAR0_SIZE, attr);
		add_map_record(CAVM_CPT_BAR_E_CPTX_VFX_BAR4(i, 0), 64*CAVM_CPT_BAR_E_CPTX_VFX_BAR4_SIZE, attr);
	}

	device_type_count = plat_octeontx_get_cgx_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CAVM_CGX_BAR_E_CGXX_PF_BAR0(i), CAVM_CGX_BAR_E_CGXX_PF_BAR0_SIZE, attr);
		add_map_record(CAVM_CGX_BAR_E_CGXX_PF_BAR4(i), CAVM_CGX_BAR_E_CGXX_PF_BAR4_SIZE, attr);
	}

	device_type_count = plat_octeontx_get_pem_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CAVM_PEM_BAR_E_PEMX_PF_BAR0_CN9(i), CAVM_PEM_BAR_E_PEMX_PF_BAR0_CN9_SIZE, attr);
		add_map_record(CAVM_PEM_BAR_E_PEMX_PF_BAR4_CN9(i), CAVM_PEM_BAR_E_PEMX_PF_BAR4_CN9_SIZE, attr);
	}

	device_type_count = plat_octeontx_get_gser_count();
	for (i = 0; i < device_type_count; i++)
		add_map_record(CAVM_GSERN_BAR_E_GSERNX_PF_BAR0(i),
			       CAVM_GSERN_BAR_E_GSERNX_PF_BAR0_SIZE, attr);

	add_map_record(CAVM_DAP_BAR_E_DAP_PF_BAR0, CAVM_DAP_BAR_E_DAP_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_DAP_BAR_E_DAP_PF_BAR2_CN9, CAVM_DAP_BAR_E_DAP_PF_BAR2_CN9_SIZE, attr);
	add_map_record(CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN9, CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN9_SIZE, attr);
	add_map_record(CAVM_GPIO_BAR_E_GPIO_PF_BAR4, CAVM_GPIO_BAR_E_GPIO_PF_BAR4_SIZE, attr);

	device_type_count = plat_octeontx_get_uaa_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(UAAX_PF_BAR0(i), CAVM_UAA_BAR_E_UAAX_PF_BAR0_CN9_SIZE, attr);
		add_map_record(CAVM_UAA_BAR_E_UAAX_PF_BAR4(i), CAVM_UAA_BAR_E_UAAX_PF_BAR4_SIZE, attr);
	}

	device_type_count = plat_octeontx_get_ecams_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CAVM_ECAM_BAR_E_ECAMX_PF_BAR0_CN9(i), CAVM_ECAM_BAR_E_ECAMX_PF_BAR0_CN9_SIZE, attr);
		add_map_record(ECAM_PF_BAR2(i), CAVM_ECAM_BAR_E_ECAMX_PF_BAR2_CN9_SIZE, attr);
	}

	for (i = 0; i < MAX_SATA; ++i)
	{
		add_map_record(CAVM_SATA_BAR_E_SATAX_PF_BAR0(i), CAVM_SATA_BAR_E_SATAX_PF_BAR0_SIZE, attr);
		add_map_record(CAVM_SATA_BAR_E_SATAX_PF_BAR2(i), CAVM_SATA_BAR_E_SATAX_PF_BAR2_SIZE, attr);
	}

	add_map_record(CAVM_ROM_BAR_E_ROM_PF_BAR0, CAVM_ROM_BAR_E_ROM_PF_BAR0_SIZE, attr);

	device_type_count = plat_octeontx_get_iobn_count();
	for (i = 0; i < device_type_count; ++i) {
		add_map_record(CAVM_IOBN_BAR_E_IOBNX_PF_BAR0_CN9(i), CAVM_IOBN_BAR_E_IOBNX_PF_BAR0_CN9_SIZE , attr);
		add_map_record(CAVM_IOBN_BAR_E_IOBNX_PF_BAR4(i), CAVM_IOBN_BAR_E_IOBNX_PF_BAR4_SIZE, attr);
	}

	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0), CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);
	device_type_count = plat_octeontx_get_rvu_count();
	for (i = 0; i < device_type_count; ++i)
		add_map_record(CAVM_RVU_BAR_E_RVU_PFX_FUNCX_BAR2(i, 0), CAVM_RVU_BAR_E_RVU_PFX_FUNCX_BAR2_SIZE, attr);

	/* Add regions for required for RVU init */
	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0) +
				CAVM_RVU_BLOCK_ADDR_E_NIXX(0) * CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE,
				CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);
	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0) +
				CAVM_RVU_BLOCK_ADDR_E_NPA * CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE,
				CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);
	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0) +
				CAVM_RVU_BLOCK_ADDR_E_SSO * CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE,
				CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);
	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0) +
				CAVM_RVU_BLOCK_ADDR_E_SSOW * CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE,
				CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);
	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0) +
				CAVM_RVU_BLOCK_ADDR_E_TIM * CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE,
				CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);
	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0) +
				CAVM_RVU_BLOCK_ADDR_E_CPTX(0) * CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE,
				CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);
	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0) +
				CAVM_RVU_BLOCK_ADDR_E_NDCX(0) * CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE,
				CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);
	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0) +
				CAVM_RVU_BLOCK_ADDR_E_NDCX(1) * CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE,
				CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);
	add_map_record(CAVM_RVU_BAR_E_RVU_PFX_BAR0(0) +
				CAVM_RVU_BLOCK_ADDR_E_NDCX(2) * CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE,
				CAVM_RVU_BAR_E_RVU_PFX_BAR0_SIZE, attr);

	add_map_record(CAVM_SMI_BAR_E_SMI_PF_BAR0_CN9,
				CAVM_SMI_BAR_E_SMI_PF_BAR0_CN9_SIZE, attr);

	plat_map_cpc_mem();

	/*
	 * Shared memory configuration.
	 * Map additional memory used by RVU/SFP mgmt(shared between AP & MCP).
	 * Do not use add_map_record, it will round size up
	 */
	mmap_add_region(RVU_MEM_BASE, RVU_MEM_BASE,
			RVU_MEM_SIZE, (MT_MEMORY | MT_RW | MT_NS));

	mmap_add_region(SFP_SHMEM_BASE, SFP_SHMEM_BASE,
			SFP_SHMEM_SIZE, (MT_MEMORY | MT_RW | MT_NS));

#ifdef NT_FW_CONFIG
	mmap_add_region(NT_FW_CONFIG_BASE, NT_FW_CONFIG_BASE,
			NT_FW_CONFIG_LIMIT, (MT_MEMORY | MT_RW | MT_NS));
#endif
}

void plat_set_gpio_msix_vectors(int gpio_num, int irq_num, int enable)
{
	uint64_t vector_ptr;
	int intr_pinx;

	/* Get the offset of interrupt vector for that GPIO line */
	intr_pinx = CAVM_GPIO_INT_VEC_E_INTR_PINX_CN96XX(gpio_num);

	/* INTR_PINX vector address */
	vector_ptr =  CAVM_GPIO_BAR_E_GPIO_PF_BAR4 + intr_pinx * 0x10;

	if (enable) {
		/* Save vector address so that it can be restored.
		 * The value will be same for set and clear vectors so saving
		 * once will suffice.
		 */
		msix_addr_save = octeontx_read64(vector_ptr);
		/* Enable SECVEC to make the vector secure */
		octeontx_write64(vector_ptr, CAVM_GICD_SETSPI_SR | 1);
		vector_ptr += 0x8;
		octeontx_write64(vector_ptr, irq_num);

		/* INTR_PINX_CLEAR vector */
		vector_ptr += 0x8;
		/* Enable SECVEC to make the vector secure */
		octeontx_write64(vector_ptr, CAVM_GICD_CLRSPI_SR | 1);
		vector_ptr += 0x8;
		octeontx_write64(vector_ptr, irq_num);
	} else {
		/* Restore the vector address */
		octeontx_write64(vector_ptr, msix_addr_save);

		/* INTR_PINX_CLEAR vector */
		vector_ptr += 0x10;
		octeontx_write64(vector_ptr, msix_addr_save);
	}
}

void plat_gpio_irq_setup(void)
{
	gpio_intercept_interrupts = 1;

	if (octeontx_register_gpio_handlers() < 0)
		ERROR("Failed to register GPIO intercept handlers\n");
}
