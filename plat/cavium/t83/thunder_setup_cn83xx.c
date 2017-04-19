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
	return 2;
}

int thunder_get_num_ecams_per_node(void)
{
	return 2;
}

int thunder_get_sata_count(void)
{
	return 6;
}

/* Return the highest GSER number, which can be configured as SATA */
int thunder_get_max_sata_gser(void)
{
	return 3;
}

/*
 * SATA to GSER mapping
 * SATA(0-1) --- GSER4
 * SATA(2-3) --- GSER5
 * SATA(4-5) --- GSER6
 */
int thunder_sata_to_gser(int ctrlr)
{
	if (ctrlr > 5)
		return -1;

	return 4 + (ctrlr / 2);
}

int thunder_sata_to_lane(int ctrlr)
{
	if (ctrlr > 5)
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
	union cavm_l2c_oci_ctl l2c_oci_ctl;

	l2c_oci_ctl.u = CSR_READ_PA(node, CAVM_L2C_OCI_CTL);

	return (l2c_oci_ctl.s.enaoci > 1) ? 2 : 1;
}

/*******************************************************************************
 * Setup secondary CPU JUMP address from RESET
 ******************************************************************************/
void set_secondary_cpu_jump_addr(unsigned int bl1_base)
{
       CSR_WRITE_PA(0, CAVM_MIO_BOOT_AP_JUMP, bl1_base);
}

void plat_add_mmio_node(unsigned long node)
{
	unsigned long attr;
	int i;

	attr = MT_DEVICE | MT_RW | MT_SECURE;
	add_map_record(CSR_PA(node, CAVM_RST_PF_BAR0), CAVM_RST_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_L2C_PF_BAR0), CAVM_L2C_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_BOOT_PF_BAR0), CAVM_MIO_BOOT_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_EMM_PF_BAR0), CAVM_MIO_EMM_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_FUS_BAR_E_MIO_FUS_PF_BAR0),
		       CAVM_MIO_FUS_BAR_E_MIO_FUS_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MPI_PF_BAR0(0)), CAVM_MPI_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR2), CAVM_GIC_PF_BAR2_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR4), CAVM_GIC_PF_BAR4_SIZE, attr);
#if TRUSTED_BOARD_BOOT
	add_map_record(CSR_PA(node, CAVM_KEY_BAR_E_KEY_PF_BAR2),
		       CAVM_KEY_BAR_E_KEY_PF_BAR2_SIZE, (MT_DEVICE | MT_RO | MT_SECURE));
	add_map_record(CSR_PA(node, CAVM_FUSF_BAR_E_FUSF_PF_BAR0),
		       CAVM_FUSF_BAR_E_FUSF_PF_BAR0_SIZE, (MT_DEVICE | MT_RO | MT_SECURE));
#endif /* TRUSTED_BOARD_BOOT */

	for (i = 0; i < 2; i++) {
		add_map_record(CSR_PA(node, CAVM_SMMUX_PF_BAR0(i)), CAVM_SMMUX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_SMMUX_PF_BAR4(i)), CAVM_SMMUX_PF_BAR4_SIZE, attr);
	}

	add_map_record(CSR_PA(node, CAVM_GTI_PF_BAR0), CAVM_GTI_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GTI_PF_BAR4), CAVM_GTI_PF_BAR4_SIZE, attr);

	for (i = 0; i < 2; i++)
		add_map_record(CSR_PA(node, CAVM_LMCX_PF_BAR0(i)), CAVM_LMCX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 2; i++) {
		add_map_record(CSR_PA(node, CAVM_MIO_TWSX_PF_BAR0(i)), CAVM_MIO_TWSX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_MIO_TWSX_PF_BAR4(i)), CAVM_MIO_TWSX_PF_BAR4_SIZE, attr);
	}

	for (i = 0; i < 4; i++) {
		add_map_record(CSR_PA(node, CAVM_L2C_CBCX_PF_BAR0(i)), CAVM_L2C_CBCX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_L2C_MCIX_PF_BAR0(i)), CAVM_L2C_MCIX_PF_BAR0_SIZE, attr);
	}
	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_L2C_TADX_PF_BAR0(i)), CAVM_L2C_TADX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 4; i++) {
		add_map_record(CSR_PA(node, CAVM_PEMX_PF_BAR0(i)), CAVM_PEMX_PF_BAR0_SIZE, attr);

		add_map_record(CSR_PA(node, CAVM_PEMX_PF_BAR4(i)),
			       CAVM_PEMX_PF_BAR4_SIZE, attr);
	}

	for (i = 0; i < 7; i++)
		add_map_record(CSR_PA(node, CAVM_GSERX_PF_BAR0(i)), CAVM_GSERX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_BGXX_PF_BAR0(i)), CAVM_BGXX_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_DAP_PF_BAR0), CAVM_DAP_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_OCX_PF_BAR0), CAVM_OCX_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_GPIO_PF_BAR0), CAVM_GPIO_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GPIO_PF_BAR4), CAVM_GPIO_PF_BAR4_SIZE, attr);

	for (i = 0; i < 4; i++) {
		add_map_record(CSR_PA(node, CAVM_UAAX_PF_BAR0(i)), CAVM_UAAX_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_UAAX_PF_BAR4(i)), CAVM_UAAX_PF_BAR4_SIZE, attr);
	}

	for (i = 0; i < 2; i++) {
		add_map_record(CSR_PA(node, CAVM_ECAM_PF_BAR0(i)), CAVM_ECAM_PF_BAR0_SIZE, attr);
		add_map_record(CSR_PA(node, CAVM_ECAM_PF_BAR2(i)), CAVM_ECAM_PF_BAR2_SIZE, attr);
	}

	add_map_record(CSR_PA(node, CAVM_SLIX_PF_BAR0(0)), CAVM_SLIX_PF_BAR0_SIZE, attr);

	for (i = 0; i < 6; ++i)
	{
		add_map_record(CSR_PA(node, CAVM_SATAX_PF_BAR0(i)),
			       CAVM_SATAX_PF_BAR0_SIZE, attr);
	}
}
