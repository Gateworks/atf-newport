/** @file

  Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <debug.h>
#include <libfdt.h>
#include <stdlib.h>
#include <assert.h>
#include <platform_def.h>
#include <cavm_dt.h>
#include <cavm_common.h>

static void octeontx_boot_device_from_strapx(const int node)
{
	cavm_gpio_strap_t gpio_strap;
	cavm_rst_boot_t rst_boot;
	int boot_medium, ret;

	rst_boot.u = CSR_READ(0, CAVM_RST_BOOT);
	if (rst_boot.s.rboot) {
		/* Fill boot_dev structure */
		bfdt->boot_dev.node = node;
		bfdt->boot_dev.boot_type = THUNDER_BOOT_REMOTE;
		bfdt->boot_dev.controller = 0;
		bfdt->boot_dev.cs = 0;
		return;
	}

	gpio_strap.u = CSR_READ(0, CAVM_GPIO_STRAP);
	boot_medium = (gpio_strap.u) & 0xf;

	switch (boot_medium) {
		case CAVM_RST_BOOT_METHOD_E_SPI24:
		case CAVM_RST_BOOT_METHOD_E_SPI32:
			ret = THUNDER_BOOT_SPI;
			break;
		case CAVM_RST_BOOT_METHOD_E_EMMC_LS:
		case CAVM_RST_BOOT_METHOD_E_EMMC_SS:
			ret = THUNDER_BOOT_EMMC;
			break;
		default:
			ret = -THUNDER_BOOT_UNSUPPORTED;
			break;
	}

	/* Fill boot_dev structure */
	bfdt->boot_dev.node = node;
	bfdt->boot_dev.boot_type = ret;
	bfdt->boot_dev.controller = 0;
	bfdt->boot_dev.cs = 0;
}

static int octeontx_parse_boot_device(const void *fdt, const int offset,
				      const int node)
{
	char boot_device[16];
	const char *name;
	int len, val;

	bfdt->boot_dev.node = node;

	snprintf(boot_device, sizeof(boot_device), "BOOT-DEVICE.N%d", node);
	name = fdt_getprop(fdt, offset, boot_device, &len);
	if (!name) {
		WARN("No %s is found\n", boot_device);
		return -1;
	}

	strncpy(boot_device, name, sizeof(boot_device));
	boot_device[sizeof(boot_device) - 1] = '\0';

	/* Get boot type */
	if (!strncmp("SPI", boot_device, 3))
		val = THUNDER_BOOT_SPI;
	else if (!strncmp("EMMC", boot_device, 4))
		val = THUNDER_BOOT_EMMC;
	else if (!strncmp("REMOTE", boot_device, 6))
		val = THUNDER_BOOT_REMOTE;
	else
		val = -THUNDER_BOOT_UNSUPPORTED;

	bfdt->boot_dev.boot_type = val;
	bfdt->boot_dev.controller = 0;
	bfdt->boot_dev.cs = 0;

	return 0;
}

int plat_fill_board_details(int info)
{
	const void *fdt = fdt_ptr;
	int offset, len, rc, node;

	/*
	 * Check if board_cfg_t fits in the memory region reserved
	 * for board_cfg_t structure to make sure we do not modify
	 * not-preserved memory.
	 */
	assert(sizeof(board_fdt_t) < (BOARD_CFG_MAX_SIZE - BOARD_CFG_BASE));

	rc = cavm_fill_board_details(info);
	if (rc) {
		WARN("Processing common FDT failed\n");
		return rc;
	}

	rc = fdt_check_header(fdt);
	if (rc) {
		WARN("Invalid device tree\n");
		return rc;
	}

	offset = fdt_path_offset(fdt, "/cavium,bdk");
	if (offset < 0) {
		WARN("FDT node not found\n");
		return offset;
	}

	node = 0;
	rc = octeontx_parse_boot_device(fdt, offset, node);
	if (rc) {
		INFO("Using GPIO_STRAPX register for boot device\n");
		octeontx_boot_device_from_strapx(node);
	}

	offset = fdt_path_offset(fdt_ptr, OCTEONTX_GPIO_DT_PATH);
	if (offset >= 0) {
		if (fdt_getprop(fdt_ptr, offset, "interrupts", &len))
			bfdt->gpio_intercept_intr = 1;
		else
			bfdt->gpio_intercept_intr = 0;
	} else {
		bfdt->gpio_intercept_intr = 0;
	}

	return 0;
}
