#include <thunder_common.h>
#include <thunder_private.h>


void plat_add_mmio_node(unsigned long node)
{
	unsigned long attr;
	int i;

	attr = MT_DEVICE | MT_RW | MT_SECURE;
	add_map_record(CSR_PA(node, CAVM_RST_PF_BAR0), CAVM_RST_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_L2C_PF_BAR0), CAVM_L2C_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_BOOT_PF_BAR0), CAVM_MIO_BOOT_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_EMM_PF_BAR0), CAVM_MIO_EMM_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MPI_PF_BAR0), CAVM_MPI_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR0), CAVM_GIC_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR2), CAVM_GIC_PF_BAR2_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR4), CAVM_GIC_PF_BAR4_SIZE, attr);

	for (i = 0; i < 4; i++) {
		add_map_record(CSR_PA(node, CAVM_SMMUX_PF_BAR0(i)), CAVM_SMMUX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_SMMU_BAR_E_SMMUX_PF_BAR4(i)),
			       CAVM_SMMU_BAR_E_SMMUX_PF_BAR4_SIZE, attr);
	}

	add_map_record(CSR_PA(node, CAVM_GTI_PF_BAR0), CAVM_GTI_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GTI_PF_BAR4), CAVM_GTI_PF_BAR4_SIZE, attr);

	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_LMCX_PF_BAR0(i)), CAVM_LMCX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 6; i++) {
		add_map_record(CSR_PA(node, CAVM_MIO_TWSX_PF_BAR0(i)), CAVM_MIO_TWSX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4(i)),
			       CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4_SIZE, attr);
	}

	for (i = 0; i < 4; i++) {
		add_map_record(CSR_PA(node, CAVM_L2C_CBCX_PF_BAR0(i)), CAVM_L2C_CBCX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_L2C_MCIX_PF_BAR0(i)), CAVM_L2C_MCIX_PF_BAR0_SIZE, attr);
	}
	for (i = 0; i < 8; i++)
		add_map_record(CSR_PA(node, CAVM_L2C_TADX_PF_BAR0(i)), CAVM_L2C_TADX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 6; i++) {
		add_map_record(CSR_PA(node, CAVM_PEMX_PF_BAR0(i)), CAVM_PEMX_PF_BAR0_SIZE, attr);

		add_map_record(CSR_PA(node, CAVM_PEM_BAR_E_PEMX_PF_BAR4(i)),
			       CAVM_PEM_BAR_E_PEMX_PF_BAR4_SIZE, attr);
	}

	for (i = 0; i < 13; i++)
		add_map_record(CSR_PA(node, CAVM_GSERX_PF_BAR0(i)), CAVM_GSERX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 2; i++)
		add_map_record(CSR_PA(node, CAVM_BGXX_PF_BAR0(i)), CAVM_BGXX_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_DAP_PF_BAR0), CAVM_DAP_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_OCX_PF_BAR0), CAVM_OCX_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_GPIO_PF_BAR0), CAVM_GPIO_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GPIO_PF_BAR4), CAVM_GPIO_PF_BAR4_SIZE, attr);

	for (i = 0; i < 4; i++) {
		add_map_record(CSR_PA(node, CAVM_UAAX_PF_BAR0(i)), CAVM_UAAX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_UAA_BAR_E_UAAX_PF_BAR4_CN83XX(i)),
			       CAVM_UAA_BAR_E_UAAX_PF_BAR4_CN83XX_SIZE, attr);
	}

	for (i = 0; i < 4; i++) {
		add_map_record(CSR_PA(node, CAVM_ECAM_BAR_E_ECAMX_PF_BAR0(i)),
			       CAVM_ECAM_BAR_E_ECAMX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_ECAMX_PF_BAR2(i)), CAVM_ECAMX_PF_BAR2_SIZE, attr);
	}

	add_map_record(CSR_PA(node, CAVM_SLIX_PF_BAR0(0)), CAVM_SLIX_PF_BAR0_SIZE, attr);
}
