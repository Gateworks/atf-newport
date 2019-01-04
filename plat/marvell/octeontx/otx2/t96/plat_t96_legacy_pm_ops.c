/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <psci.h>
#include <debug.h>
#include <octeontx_common.h>
#include <octeontx_legacy_pm.h>

/*******************************************************************************
 * FVP handler to reboot the system
 ******************************************************************************/

static void __dead2 plat_octeontx_legacy_system_reset(void)
{
	union cavm_rst_boot rst_boot;
	union cavm_rst_chip_domain_w1s rst_chip;
	union cavm_rst_ocx rst_ocx;

	rst_ocx.u = 0;
	CSR_WRITE(CAVM_RST_OCX, rst_ocx.u);

	rst_ocx.u = CSR_READ(CAVM_RST_OCX);

	// SCP should auto restart after reset
	rst_boot.s.rboot = 0;
	CSR_WRITE(CAVM_RST_BOOT, rst_boot.u);

	// entire system reset
	rst_chip.s.soft_rst = 1;
	CSR_WRITE(CAVM_RST_CHIP_DOMAIN_W1S, rst_chip.u);
	while (rst_chip.s.soft_rst)
		rst_chip.u = CSR_READ(CAVM_RST_CHIP_DOMAIN_W1S);

	ERROR("OcteonTX System Reset: operation not handled.\n");
	panic();
}

void plat_octeontx_legacy_psci_override_pm_ops(plat_psci_ops_t *pm_ops) {
	pm_ops->system_reset = plat_octeontx_legacy_system_reset;
}
