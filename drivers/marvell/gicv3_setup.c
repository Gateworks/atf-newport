/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/* GIC driver for OcteonTX (CN8xxx and CN9xxx) */

#include <arch.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <gicv3_setup.h>
#include <octeontx_utils.h>
#include <octeontx_irqs_def.h>

#undef GICD_SETSPI_NSR
#undef GICD_CLRSPI_NSR
#undef GICD_SETSPI_SR
#undef GICD_CLRSPI_SR
#undef GICD_TYPER
#undef GICD_IIDR

#include <gic_common.h>
#include <gicv3.h>
#include <platform.h>
#include <interrupt_mgmt.h>

/*
 * It is number of all interrupts configured in GIC.
 * Every GIC interrupt has to be defined in interrupt_array.
 * There is one interrupt for secure timer, interrupts for GPIO and
 * interrupts for BPHY.
 */
#define NUMBER_OF_GIC_INTERRUPTS	(1 + GPIO_SPI_IRQS + BPHY_PSM_IRQS_NUMBER)

#if IMAGE_BL31
/* The GICv3 driver only needs to be initialized in EL3 */
uintptr_t rdistif_base_addrs[PLATFORM_CORE_COUNT];

/*
 * Array of interrupts to be configured by GIC driver
 */
static interrupt_prop_t interrupt_array[NUMBER_OF_GIC_INTERRUPTS];

#define ADD_BPHY_PSM_INTERUPTS_TO_ARRAY()

/*
 * Method to initialize all GIC interrupts.
 * Define G0/G1S interrupts via Interrupt type,
 * one of INTR_TYPE_EL3, INTR_TYPE_S_EL1
 */
static void initialize_interrupt_array(interrupt_prop_t *intr_array)
{
	int i, idx = 0;

	/* Configure Secure Timer Interrupt */
	intr_array[idx].intr_num = SEC_TIMER_PPI_IRQ;
	intr_array[idx].intr_pri = 0;
	intr_array[idx].intr_grp = INTR_TYPE_EL3;
	intr_array[idx].intr_cfg = GIC_INTR_CFG_LEVEL;
	idx++;

	/* Configure GPIO IRQs */
	for (i = 0; i < GPIO_SPI_IRQS; i++) {
		intr_array[idx].intr_num = GPIO_SPI_IRQ(i);
		intr_array[idx].intr_pri = 0;
		intr_array[idx].intr_grp = INTR_TYPE_EL3;
		intr_array[idx].intr_cfg = GIC_INTR_CFG_LEVEL;
		idx++;
	}

	/* Configure BPHY PSM IRQs */
	for (i = 0; i < BPHY_PSM_IRQS_NUMBER; i++) {
		intr_array[idx].intr_num = BPHY_PSM_IRQ(i);
		intr_array[idx].intr_pri = 0;
		intr_array[idx].intr_grp = INTR_TYPE_EL3;
		intr_array[idx].intr_cfg = GIC_INTR_CFG_LEVEL;
		idx++;
	}
}

static gicv3_driver_data_t octeontx_gic_data = {
	.interrupt_props_num = ARRAY_SIZE(interrupt_array),
	.rdistif_num = PLATFORM_CORE_COUNT,
	.rdistif_base_addrs = rdistif_base_addrs,
#if defined(PLAT_t83) || defined(PLAT_t81)
	/*
	 * T9X can use the generic driver implementation
	 * to obtain the core pos and hence define it only
	 * for T8X platforms
	 */
	.mpidr_to_core_pos = octeontx_calc_core_pos,
#endif
};
#endif

void octeontx_gic_driver_init(void)
{
	/*
	 * The GICv3 driver is initialized in EL3 and does not need
	 * to be initialized again in SEL1. This is because the S-EL1
	 * can use GIC system registers to manage interrupts and does
	 * not need GIC interface base addresses to be configured.
	 */
#if IMAGE_BL31
	/* ERRATUM GIC-28835 */
	if (IS_OCTEONTX_PASS(read_midr(), T83PARTNUM, 1, 0)) {
	        union cavm_gic_cfg_ctlr cfg_ctlr;
	        cfg_ctlr.u = CSR_READ(CAVM_GIC_CFG_CTLR);
	        cfg_ctlr.s.dis_cpu_if_load_balancer = 1;
	        CSR_WRITE(CAVM_GIC_CFG_CTLR, cfg_ctlr.u);
	}

	/* Initialize array of interrupts to be configured by GIC driver */
	initialize_interrupt_array(interrupt_array);
	octeontx_gic_data.interrupt_props = interrupt_array;

	octeontx_gic_data.gicd_base = CAVM_GIC_BAR_E_GIC_PF_BAR0;
	octeontx_gic_data.gicr_base = GIC_PF_BAR4;
	gicv3_driver_init(&octeontx_gic_data);
#endif
}

/******************************************************************************
 * ARM common helper to initialize the GIC. Only invoked by BL31
 *****************************************************************************/
void octeontx_gic_init(void)
{
	gicv3_distif_init();
	gicv3_rdistif_init(plat_my_core_pos());
	gicv3_cpuif_enable(plat_my_core_pos());
}

/******************************************************************************
 * Cavium common helper to initialize the per-cpu redistributor interface in GICv3
 *****************************************************************************/
void octeontx_gic_pcpu_init(void)
{
	gicv3_rdistif_init(plat_my_core_pos());
}

/******************************************************************************
 * Cavium common helper to enable the GIC CPU interface
 *****************************************************************************/
void octeontx_gic_cpuif_enable(void)
{
	gicv3_cpuif_enable(plat_my_core_pos());
}

/******************************************************************************
 * Cavium common helper to disable the GIC CPU interface
 *****************************************************************************/
void octeontx_gic_cpuif_disable(void)
{
	gicv3_cpuif_disable(plat_my_core_pos());
}
