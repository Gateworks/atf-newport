/** @file

  Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <thunder_common.h>
#include <thunder_private.h>

int thunder_get_lmc_per_node(void)
{
	return 3;
}

int thunder_get_num_ecams_per_node(void)
{
	return 1;
}

int thunder_get_sata_count(void)
{
	return 4;
}

/* Return the highest GSER number, which can be configured as SATA */
int thunder_get_max_sata_gser(void)
{
	return 5;
}

/*
 * SATA to GSER mapping
 * SATA(0-1) --- GSER3
 */
int thunder_sata_to_gser(int ctrlr)
{
	if (ctrlr > 1)
		return -1;

	return 3;
}

int thunder_sata_to_lane(int ctrlr)
{
	if (ctrlr > 1)
		return -1;

	return ctrlr % 2;
}

int thunder_dram_is_lmc_enabled(unsigned node, unsigned lmc)
{
	union cavm_lmcx_ddr_pll_ctl lmcx_ddr_pll_ctl;

	lmcx_ddr_pll_ctl.u = CSR_READ_PA(node, CAVM_LMCX_DDR_PLL_CTL(lmc));

	return lmcx_ddr_pll_ctl.cn83xx.reset_n;
}

unsigned thunder_get_node_count(void)
{
	unsigned long node = cavm_numa_local();
	union cavm_ccs_ccpi_ctl ccs_ccpi_ctl;

	ccs_ccpi_ctl.u = CSR_READ_PA(node, CAVM_CCS_CCPI_CTL);

	return (ccs_ccpi_ctl.s.enaoci > 1) ? 2 : 1;
}

/*******************************************************************************
 * Setup secondary CPU JUMP address from RESET
 ******************************************************************************/
void set_secondary_cpu_jump_addr(unsigned int bl1_base)
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
	CSR_WRITE_PA(0, CAVM_ROM_MEMX(0), 0xd503201fd508711f);
	CSR_WRITE_PA(0, CAVM_ROM_MEMX(1), 0xd61f000058000040);
	CSR_WRITE_PA(0, CAVM_ROM_MEMX(2), (uint64_t)bl1_base);
}

int thunder_get_ccu_count(void)
{
	return 4;
}

int thunder_get_mpi_count(void)
{
	return 2;
}

int thunder_get_smmu_count(void)
{
	return 1;
}

int thunder_get_twsi_count(void)
{
	return 6;
}

int thunder_get_cpt_count(void)
{
	return 2;
}

int thunder_get_cgx_count(void)
{
	return 3;
}

int thunder_get_pem_count(void)
{
	return 3;
}

int thunder_get_gser_count(void)
{
	return 8;
}

int thunder_get_uaa_count(void)
{
	return 8;
}

void plat_add_mmio_node(unsigned long node)
{
	unsigned long attr;
	int i, device_type_count;

	attr = MT_DEVICE | MT_RW | MT_SECURE;
	add_map_record(CSR_PA(node, CAVM_RST_PF_BAR0), CAVM_RST_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_RST_PF_BAR2), CAVM_RST_PF_BAR2_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_RST_PF_BAR4), CAVM_RST_PF_BAR4_SIZE, attr);

	device_type_count = thunder_get_ccu_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_CCU_PF_BAR0(i)), CAVM_RST_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_CCU_PF_BAR4(i)), CAVM_RST_PF_BAR4_SIZE, attr);
	}
	add_map_record(CSR_PA(node, CAVM_CCS_PF_BAR0), CAVM_CCS_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_BOOT_PF_BAR0), CAVM_MIO_BOOT_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_EMM_PF_BAR0), CAVM_MIO_EMM_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_EMM_PF_BAR4), CAVM_MIO_EMM_PF_BAR4_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_FUS_BAR_E_MIO_FUS_PF_BAR0),
		       CAVM_MIO_FUS_BAR_E_MIO_FUS_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_FUSF_BAR_E_FUSF_PF_BAR0),
		       CAVM_FUSF_BAR_E_FUSF_PF_BAR0_SIZE, attr);

	device_type_count = thunder_get_mpi_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_MPI_PF_BAR0(i)), CAVM_MPI_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_MPI_PF_BAR4(i)), CAVM_MPI_PF_BAR0_SIZE, attr);
	}
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR2), CAVM_GIC_PF_BAR2_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR4), CAVM_GIC_PF_BAR4_SIZE, attr);

	device_type_count = thunder_get_smmu_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_SMMUX_PF_BAR0(i)), CAVM_SMMUX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_SMMUX_PF_BAR4(i)), CAVM_SMMUX_PF_BAR4_SIZE, attr);
	}
	add_map_record(CSR_PA(node, CAVM_GTI_PF_BAR0), CAVM_GTI_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GTI_PF_BAR4), CAVM_GTI_PF_BAR4_SIZE, attr);

	device_type_count = thunder_get_lmc_per_node();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_LMCX_PF_BAR0(i)), CAVM_LMCX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_LMCX_PF_BAR4(i)), CAVM_LMCX_PF_BAR4_SIZE, attr);
	}

	device_type_count = thunder_get_twsi_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_MIO_TWSX_PF_BAR0(i)), CAVM_MIO_TWSX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_MIO_TWSX_PF_BAR4(i)), CAVM_MIO_TWSX_PF_BAR4_SIZE, attr);
	}

	device_type_count = thunder_get_cpt_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_CPT_PF_BAR0(i)), CAVM_CPT_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_CPT_PF_BAR4(i)), CAVM_CPT_PF_BAR4_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_CPT_VFX_BAR0(i, 0)), 64*CAVM_CPT_VFX_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_CPT_VFX_BAR4(i, 0)), 64*CAVM_CPT_VFX_BAR4_SIZE, attr);
	}

	device_type_count = thunder_get_cgx_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_CGX_PF_BAR0(i)), CAVM_CGX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_CGX_PF_BAR4(i)), CAVM_CGX_PF_BAR4_SIZE, attr);
	}

	device_type_count = thunder_get_pem_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_PEMX_PF_BAR0(i)), CAVM_PEMX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_PEMX_PF_BAR4(i)), CAVM_PEMX_PF_BAR4_SIZE, attr);
	}

	device_type_count = thunder_get_gser_count();
	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_GSERX_PF_BAR0(i)), CAVM_GSERX_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_DAP_PF_BAR0), CAVM_DAP_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_DAP_PF_BAR2), CAVM_DAP_PF_BAR2_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GPIO_PF_BAR0), CAVM_GPIO_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GPIO_PF_BAR4), CAVM_GPIO_PF_BAR4_SIZE, attr);

	device_type_count = thunder_get_uaa_count();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_UAAX_PF_BAR0(i)), CAVM_UAAX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_UAAX_PF_BAR4(i)), CAVM_UAAX_PF_BAR4_SIZE, attr);
	}

	device_type_count = thunder_get_num_ecams_per_node();
	for (i = 0; i < device_type_count; i++) {
		add_map_record(CSR_PA(node, CAVM_ECAM_PF_BAR0(i)), CAVM_ECAM_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_ECAM_PF_BAR2(i)), CAVM_ECAM_PF_BAR2_SIZE, attr);
	}

	device_type_count = thunder_get_sata_count();
	for (i = 0; i < device_type_count; ++i)
	{
		add_map_record(CSR_PA(node, CAVM_SATAX_PF_BAR0(i)), CAVM_SATAX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_SATAX_PF_BAR2(i)), CAVM_SATAX_PF_BAR2_SIZE, attr);
	}

	add_map_record(CSR_PA(node, CAVM_ROM_PF_BAR0), CAVM_ROM_PF_BAR0_SIZE, attr);
}

int plat_get_boot_type(int boot_type)
{
	int ret;

	if (boot_type == 0x05) { /* Remote boot */
		ret = THUNDER_BOOT_REMOTE;
	} else if (boot_type == 0x02 || boot_type == 0x03) { /* SPI */
		ret = THUNDER_BOOT_SPI;
	} else if (boot_type == 0x00 || boot_type == 0x01) { /* (e)MMC */
		ret = THUNDER_BOOT_EMMC;
	} else {
		ret = -THUNDER_BOOT_UNSUPPORTED;
	}

	return ret;
}
