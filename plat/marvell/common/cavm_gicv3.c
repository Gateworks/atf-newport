/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <platform_def.h>
#include <cavm_common.h>
#include <cavm_utils.h>

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

#if IMAGE_BL31
/* The GICv3 driver only needs to be initialized in EL3 */
uintptr_t rdistif_base_addrs[PLATFORM_CORE_COUNT];

/*
 * Array of interrupts to be configured by GIC driver
 * Define G0/G1S interrupts via Interrupt type,
 * one of INTR_TYPE_EL3, INTR_TYPE_S_EL1, INTR_TYPE_NS
 */
static const interrupt_prop_t interrupt_array[] = {
	INTR_PROP_DESC(OCTEONTX_IRQ_SEC_PHY_TIMER, 0, INTR_TYPE_EL3, GIC_INTR_CFG_LEVEL),
	INTR_PROP_DESC(OCTEONTX_GPIO_PWR_S_IRQ, 0, INTR_TYPE_EL3, GIC_INTR_CFG_LEVEL),
	INTR_PROP_DESC(OCTEONTX_IRQ_GPIO_BASE, 0, INTR_TYPE_EL3, GIC_INTR_CFG_EDGE),
	INTR_PROP_DESC(OCTEONTX_IRQ_GPIO_BASE + 1, 0, INTR_TYPE_EL3, GIC_INTR_CFG_EDGE),
	INTR_PROP_DESC(OCTEONTX_IRQ_GPIO_BASE + 2, 0, INTR_TYPE_EL3, GIC_INTR_CFG_EDGE),
	INTR_PROP_DESC(OCTEONTX_IRQ_GPIO_BASE + 3, 0, INTR_TYPE_EL3, GIC_INTR_CFG_EDGE)
};

static gicv3_driver_data_t thunder_gic_data = {
	.interrupt_props = interrupt_array,
	.interrupt_props_num = ARRAY_SIZE(interrupt_array),
	.rdistif_num = PLATFORM_CORE_COUNT,
	.rdistif_base_addrs = rdistif_base_addrs,
#if defined(PLAT_t83) || defined(PLAT_t81)
	/*
	 * T9X can use the generic driver implementation
	 * to obtain the core pos and hence define it only
	 * for T8X platforms
	 */
	.mpidr_to_core_pos = thunder_calc_core_pos,
#endif
};
#endif

void thunder_gic_driver_init(void)
{
	/*
	 * The GICv3 driver is initialized in EL3 and does not need
	 * to be initialized again in SEL1. This is because the S-EL1
	 * can use GIC system registers to manage interrupts and does
	 * not need GIC interface base addresses to be configured.
	 */
#if IMAGE_BL31
	/* ERRATUM GIC-28835 */
	if (IS_THUNDER_PASS(read_midr(), T83PARTNUM, 1, 0)) {
	        union cavm_gic_cfg_ctlr cfg_ctlr;
	        cfg_ctlr.u = CSR_READ(0, CAVM_GIC_CFG_CTLR);
	        cfg_ctlr.s.dis_cpu_if_load_balancer = 1;
	        CSR_WRITE(0, CAVM_GIC_CFG_CTLR, cfg_ctlr.u);
	}

	thunder_gic_data.gicd_base = CSR_PA(0, CAVM_GIC_BAR_E_GIC_PF_BAR0);
	thunder_gic_data.gicr_base = CSR_PA(0, GIC_PF_BAR4);
	gicv3_driver_init(&thunder_gic_data);

#endif
}

/******************************************************************************
 * ARM common helper to initialize the GIC. Only invoked by BL31
 *****************************************************************************/
void thunder_gic_init(void)
{
	gicv3_distif_init();
	gicv3_rdistif_init(plat_my_core_pos());
	gicv3_cpuif_enable(plat_my_core_pos());
}

/******************************************************************************
 * Cavium common helper to initialize the per-cpu redistributor interface in GICv3
 *****************************************************************************/
void cavm_gic_pcpu_init(void)
{
	gicv3_rdistif_init(plat_my_core_pos());
}

/******************************************************************************
 * Cavium common helper to enable the GIC CPU interface
 *****************************************************************************/
void cavm_gic_cpuif_enable(void)
{
	gicv3_cpuif_enable(plat_my_core_pos());
}

/******************************************************************************
 * Cavium common helper to disable the GIC CPU interface
 *****************************************************************************/
void cavm_gic_cpuif_disable(void)
{
	gicv3_cpuif_disable(plat_my_core_pos());
}
