/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <octeontx_common.h>
#include <octeontx_utils.h>
#include <platform_def.h>
#include <octeontx_plat_configuration.h>
#include <plat_octeontx.h>

/*
 * SATA to GSER mapping
 * SATA(0-1) --- GSER3
 */
int plat_octeontx_sata_to_gser(int ctrlr)
{
	if (ctrlr > 1)
		return -1;

	return 3;
}

int plat_octeontx_sata_to_lane(int ctrlr)
{
	if (ctrlr > 1)
		return -1;

	return ctrlr % 2;
}

int plat_octeontx_is_lmc_enabled(unsigned lmc)
{
	union cavm_lmcx_dll_ctl2 lmcx_dll_ctl2;

	lmcx_dll_ctl2.u = CSR_READ(CAVM_LMCX_DLL_CTL2(lmc));

	return (lmcx_dll_ctl2.s.dreset ? 0 : 1);
}

/*******************************************************************************
 * Setup secondary CPU JUMP address from RESET
 ******************************************************************************/
void set_secondary_cpu_jump_addr(unsigned int bl1_base)
{
       CSR_WRITE(CAVM_MIO_BOOT_AP_JUMP, bl1_base);
}

void plat_add_mmio()
{
	unsigned long attr;
	int i;

	attr = MT_DEVICE | MT_RW | MT_SECURE;
	add_map_record(CAVM_RST_BAR_E_RST_PF_BAR0_CN8, CAVM_RST_BAR_E_RST_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CAVM_L2C_BAR_E_L2C_PF_BAR0, CAVM_L2C_BAR_E_L2C_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_MIO_BOOT_BAR_E_MIO_BOOT_PF_BAR0, CAVM_MIO_BOOT_BAR_E_MIO_BOOT_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR0_CN8, CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CAVM_MIO_FUS_BAR_E_MIO_FUS_PF_BAR0,
		       CAVM_MIO_FUS_BAR_E_MIO_FUS_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_MPI_BAR_E_MPI_PF_BAR0, CAVM_MPI_BAR_E_MPI_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_GIC_BAR_E_GIC_PF_BAR2, CAVM_GIC_BAR_E_GIC_PF_BAR2_SIZE, attr);
	add_map_record(GIC_PF_BAR4, GIC_PF_BAR4_SIZE, attr);
#if TRUSTED_BOARD_BOOT
	add_map_record(CAVM_KEY_BAR_E_KEY_PF_BAR2,
		       CAVM_KEY_BAR_E_KEY_PF_BAR2_SIZE, (MT_DEVICE | MT_RO | MT_SECURE));
	add_map_record(CAVM_FUSF_BAR_E_FUSF_PF_BAR0,
		       CAVM_FUSF_BAR_E_FUSF_PF_BAR0_SIZE, (MT_DEVICE | MT_RW | MT_SECURE));
#endif


	add_map_record(CAVM_SMMU_BAR_E_SMMUX_PF_BAR0_CN8(0), CAVM_SMMU_BAR_E_SMMUX_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CAVM_SMMU_BAR_E_SMMUX_PF_BAR4(0), CAVM_SMMU_BAR_E_SMMUX_PF_BAR4_SIZE, attr);

	add_map_record(CAVM_GTI_BAR_E_GTI_PF_BAR0_CN8, CAVM_GTI_BAR_E_GTI_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CAVM_GTI_BAR_E_GTI_PF_BAR4_CN8, CAVM_GTI_BAR_E_GTI_PF_BAR4_CN8_SIZE, attr);


	add_map_record(CAVM_LMC_BAR_E_LMCX_PF_BAR0(0), CAVM_LMC_BAR_E_LMCX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 2; i++) {
		add_map_record(CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR0_CN8(i), CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR0_CN8_SIZE, attr);
		add_map_record(CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4(i), CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4_SIZE, attr);
	}

	add_map_record(CAVM_L2C_CBC_BAR_E_L2C_CBCX_PF_BAR0(0), CAVM_L2C_CBC_BAR_E_L2C_CBCX_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_L2C_MCI_BAR_E_L2C_MCIX_PF_BAR0(0), CAVM_L2C_MCI_BAR_E_L2C_MCIX_PF_BAR0_SIZE, attr);
	add_map_record(CAVM_L2C_TAD_BAR_E_L2C_TADX_PF_BAR0(0), CAVM_L2C_TAD_BAR_E_L2C_TADX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 3; i++) {
		add_map_record(CAVM_PEM_BAR_E_PEMX_PF_BAR0_CN8(i), CAVM_PEM_BAR_E_PEMX_PF_BAR0_CN8_SIZE, attr);

		add_map_record(CAVM_PEM_BAR_E_PEMX_PF_BAR4_CN8(i),
			       CAVM_PEM_BAR_E_PEMX_PF_BAR4_CN8_SIZE, attr);
	}

	for (i = 0; i < 4; i++)
		add_map_record(CAVM_GSER_BAR_E_GSERX_PF_BAR0(i), CAVM_GSER_BAR_E_GSERX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 2; i++)
		add_map_record(CAVM_BGX_BAR_E_BGXX_PF_BAR0(i), CAVM_BGX_BAR_E_BGXX_PF_BAR0_SIZE, attr);

	add_map_record(CAVM_DAP_BAR_E_DAP_PF_BAR0, CAVM_DAP_BAR_E_DAP_PF_BAR0_SIZE, attr);

	add_map_record(CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN8, CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN8_SIZE, attr);
	add_map_record(CAVM_GPIO_BAR_E_GPIO_PF_BAR4, CAVM_GPIO_BAR_E_GPIO_PF_BAR4_SIZE, attr);

	for (i = 0; i < 4; i++) {
		add_map_record(UAAX_PF_BAR0(i), CAVM_UAA_BAR_E_UAAX_PF_BAR0_CN8_SIZE, attr);
		add_map_record(CAVM_UAA_BAR_E_UAAX_PF_BAR4(i), CAVM_UAA_BAR_E_UAAX_PF_BAR4_SIZE, attr);
	}

	add_map_record(CAVM_ECAM_BAR_E_ECAMX_PF_BAR0_CN8(0), CAVM_ECAM_BAR_E_ECAMX_PF_BAR0_CN8_SIZE, attr);
	add_map_record(ECAM_PF_BAR2(0), CAVM_ECAM_BAR_E_ECAMX_PF_BAR2_CN8_SIZE, attr);

	add_map_record(CAVM_SLI_BAR_E_SLIX_PF_BAR0_CN81XX(0), CAVM_SLI_BAR_E_SLIX_PF_BAR0_CN81XX_SIZE, attr);

	for (i = 0; i < 2; ++i)
	{
		add_map_record(CAVM_SATA_BAR_E_SATAX_PF_BAR0(i),
			       CAVM_SATA_BAR_E_SATAX_PF_BAR0_SIZE, attr);
	}

	for (i = 0; i < 2; ++i) {
		add_map_record(CAVM_IOBN_BAR_E_IOBNX_PF_BAR0_CN8(i), CAVM_IOBN_BAR_E_IOBNX_PF_BAR0_CN8_SIZE , attr);
	}
}

/* dummy functions to satisfy other platforms in this family */
void plat_set_gpio_msix_vectors(int gpio_num, int irq_num, int enable)
{

}

void plat_gpio_irq_setup(void)
{

}
