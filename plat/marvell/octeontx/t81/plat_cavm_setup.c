/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <cavm_common.h>
#include <cavm_utils.h>
#include <platform_def.h>

int thunder_get_lmc_per_node(void)
{
	return 1;
}

int thunder_get_num_ecams_per_node(void)
{
	return 1;
}

int thunder_get_sata_count(void)
{
	return 2;
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
	union cavm_lmcx_dll_ctl2 lmcx_dll_ctl2;

	lmcx_dll_ctl2.u = CSR_READ(node, CAVM_LMCX_DLL_CTL2(lmc));

	return (lmcx_dll_ctl2.s.dreset ? 0 : 1);
}

unsigned thunder_get_node_count(void)
{
	unsigned long node = cavm_numa_local();
	union cavm_l2c_oci_ctl l2c_oci_ctl;

	l2c_oci_ctl.u = CSR_READ(node, CAVM_L2C_OCI_CTL);

	return (l2c_oci_ctl.s.enaoci > 1) ? 2 : 1;
}

/*******************************************************************************
 * Setup secondary CPU JUMP address from RESET
 ******************************************************************************/
void set_secondary_cpu_jump_addr(unsigned int bl1_base)
{
       CSR_WRITE(0, CAVM_MIO_BOOT_AP_JUMP, bl1_base);
}

void plat_add_mmio_node(unsigned long node)
{
	unsigned long attr;
	int i;

	attr = MT_DEVICE | MT_RW | MT_SECURE;
	add_map_record(CSR_PA(node, CAVM_RST_BAR_E_RST_PF_BAR0_CN8), CAVM_RST_BAR_E_RST_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_L2C_BAR_E_L2C_PF_BAR0), CAVM_L2C_BAR_E_L2C_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_BOOT_BAR_E_MIO_BOOT_PF_BAR0), CAVM_MIO_BOOT_BAR_E_MIO_BOOT_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR0_CN8), CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_FUS_BAR_E_MIO_FUS_PF_BAR0),
		       CAVM_MIO_FUS_BAR_E_MIO_FUS_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MPI_BAR_E_MPI_PF_BAR0), CAVM_MPI_BAR_E_MPI_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_BAR_E_GIC_PF_BAR2), CAVM_GIC_BAR_E_GIC_PF_BAR2_SIZE, attr);
	add_map_record(CSR_PA(node, GIC_PF_BAR4), GIC_PF_BAR4_SIZE, attr);
#if TRUSTED_BOARD_BOOT
	add_map_record(CSR_PA(node, CAVM_KEY_BAR_E_KEY_PF_BAR2),
		       CAVM_KEY_BAR_E_KEY_PF_BAR2_SIZE, (MT_DEVICE | MT_RO | MT_SECURE));
	add_map_record(CSR_PA(node, CAVM_FUSF_BAR_E_FUSF_PF_BAR0),
		       CAVM_FUSF_BAR_E_FUSF_PF_BAR0_SIZE, (MT_DEVICE | MT_RW | MT_SECURE));
#endif


	add_map_record(CSR_PA(node, CAVM_SMMU_BAR_E_SMMUX_PF_BAR0_CN8(0)), CAVM_SMMU_BAR_E_SMMUX_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_SMMU_BAR_E_SMMUX_PF_BAR4(0)), CAVM_SMMU_BAR_E_SMMUX_PF_BAR4_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_GTI_BAR_E_GTI_PF_BAR0_CN8), CAVM_GTI_BAR_E_GTI_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GTI_BAR_E_GTI_PF_BAR4_CN8), CAVM_GTI_BAR_E_GTI_PF_BAR4_CN8_SIZE, attr);


	add_map_record(CSR_PA(node, CAVM_LMC_BAR_E_LMCX_PF_BAR0(0)), CAVM_LMC_BAR_E_LMCX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 2; i++) {
		add_map_record(CSR_PA(node, CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR0_CN8(i)), CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR0_CN8_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4(i)), CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4_SIZE, attr);
	}

	add_map_record(CSR_PA(node, CAVM_L2C_CBC_BAR_E_L2C_CBCX_PF_BAR0(0)), CAVM_L2C_CBC_BAR_E_L2C_CBCX_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_L2C_MCI_BAR_E_L2C_MCIX_PF_BAR0(0)), CAVM_L2C_MCI_BAR_E_L2C_MCIX_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_L2C_TAD_BAR_E_L2C_TADX_PF_BAR0(0)), CAVM_L2C_TAD_BAR_E_L2C_TADX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 3; i++) {
		add_map_record(CSR_PA(node, CAVM_PEM_BAR_E_PEMX_PF_BAR0_CN8(i)), CAVM_PEM_BAR_E_PEMX_PF_BAR0_CN8_SIZE, attr);

		add_map_record(CSR_PA(node, CAVM_PEM_BAR_E_PEMX_PF_BAR4_CN8(i)),
			       CAVM_PEM_BAR_E_PEMX_PF_BAR4_CN8_SIZE, attr);
	}

	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_GSER_BAR_E_GSERX_PF_BAR0(i)), CAVM_GSER_BAR_E_GSERX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 2; i++)
		add_map_record(CSR_PA(node, CAVM_BGX_BAR_E_BGXX_PF_BAR0(i)), CAVM_BGX_BAR_E_BGXX_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_DAP_BAR_E_DAP_PF_BAR0), CAVM_DAP_BAR_E_DAP_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN8), CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GPIO_BAR_E_GPIO_PF_BAR4), CAVM_GPIO_BAR_E_GPIO_PF_BAR4_SIZE, attr);

	for (i = 0; i < 4; i++) {
		add_map_record(CSR_PA(node, UAAX_PF_BAR0(i)), CAVM_UAA_BAR_E_UAAX_PF_BAR0_CN8_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_UAA_BAR_E_UAAX_PF_BAR4(i)), CAVM_UAA_BAR_E_UAAX_PF_BAR4_SIZE, attr);
	}

	add_map_record(CSR_PA(node, CAVM_ECAM_BAR_E_ECAMX_PF_BAR0_CN8(0)), CAVM_ECAM_BAR_E_ECAMX_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CSR_PA(node, ECAM_PF_BAR2(0)), CAVM_ECAM_BAR_E_ECAMX_PF_BAR2_CN8_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_SLI_BAR_E_SLIX_PF_BAR0_CN81XX(0)), CAVM_SLI_BAR_E_SLIX_PF_BAR0_CN81XX_SIZE, attr);

	for (i = 0; i < 2; ++i)
	{
		add_map_record(CSR_PA(node, CAVM_SATA_BAR_E_SATAX_PF_BAR0(i)),
			       CAVM_SATA_BAR_E_SATAX_PF_BAR0_SIZE, attr);
	}

	for (i = 0; i < 2; ++i) {
		add_map_record(CSR_PA(node, CAVM_IOBN_BAR_E_IOBNX_PF_BAR0_CN8(i)), CAVM_IOBN_BAR_E_IOBNX_PF_BAR0_CN8_SIZE , attr);
	}
}

/* dummy functions to satisfy other platforms in this family */
void plat_set_gpio_msix_vectors(int gpio_num, int irq_num, int enable)
{

}

void plat_gpio_irq_setup(void)
{

}
