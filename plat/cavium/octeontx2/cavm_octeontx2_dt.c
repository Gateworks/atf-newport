/** @file

  Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <platform_def.h>
#include <debug.h>
#include <libfdt.h>
#include <stdlib.h>
#include <cavm_dt.h>
#include <cavm_common.h>

static void octeontx2_boot_device_from_strapx(const int node)
{
	cavm_gpio_strap_t gpio_strap;
	int boot_medium;

	bfdt.boot_dev.node = node;

	gpio_strap.u = CSR_READ(0, CAVM_GPIO_STRAP);
	boot_medium = (gpio_strap.u) & 0x7;

	switch (boot_medium) {
		case CAVM_RST_BOOT_METHOD_E_REMOTE_CN9:
			bfdt.boot_dev.boot_type = THUNDER_BOOT_REMOTE;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI0_CS0:
			bfdt.boot_dev.boot_type = THUNDER_BOOT_SPI;
			bfdt.boot_dev.controller = 0;
			bfdt.boot_dev.cs = 0;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI0_CS1:
			bfdt.boot_dev.boot_type = THUNDER_BOOT_SPI;
			bfdt.boot_dev.controller = 0;
			bfdt.boot_dev.cs = 1;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI1_CS0:
			bfdt.boot_dev.boot_type = THUNDER_BOOT_SPI;
			bfdt.boot_dev.controller = 1;
			bfdt.boot_dev.cs = 0;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI1_CS1:
			bfdt.boot_dev.boot_type = THUNDER_BOOT_SPI;
			bfdt.boot_dev.controller = 1;
			bfdt.boot_dev.cs = 1;
			break;
		case CAVM_RST_BOOT_METHOD_E_EMMC_CS0:
			bfdt.boot_dev.boot_type = THUNDER_BOOT_EMMC;
			bfdt.boot_dev.controller = 0;
			bfdt.boot_dev.cs = 0;
			break;
		case CAVM_RST_BOOT_METHOD_E_EMMC_CS1:
			bfdt.boot_dev.boot_type = THUNDER_BOOT_EMMC;
			bfdt.boot_dev.controller = 0;
			bfdt.boot_dev.cs = 1;
			break;
		default:
			bfdt.boot_dev.boot_type = -THUNDER_BOOT_UNSUPPORTED;
			break;
	}
}

static int octeontx2_parse_boot_device(const void *fdt, const int offset,
				       const int node)
{
	char boot_device[16], *cs;
	const char *name;
	int len, val;

	bfdt.boot_dev.node = node;

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

	bfdt.boot_dev.boot_type = val;

	/* Get boot controller (only for SPI) */
	if (bfdt.boot_dev.boot_type == THUNDER_BOOT_SPI) {
		if (!strncmp("SPI0", boot_device, 4))
			val = 0;
		else if (!strncmp("SPI1", boot_device, 4))
			val = 1;
		else
			val = -1;
	} else {
		val = -1;
	}

	bfdt.boot_dev.controller = val;

	/* Get chip select used to boot (EMMC and SPI) */
	if (bfdt.boot_dev.boot_type == THUNDER_BOOT_SPI ||
	    bfdt.boot_dev.boot_type == THUNDER_BOOT_EMMC) {
		cs = strchr(boot_device, '_');
		if (!cs) {
			val = -1;
		} else {
			cs += 3; //Move pointer over "CS" string to point to boot CS
			val = (*cs - '0');
			if ((val != 0) &&
			    (val != 1)) {
				val = -1;
			}
		}
	} else {
		val = -1;
	}

	bfdt.boot_dev.cs = val;

	return 0;
}

int plat_fill_board_details(int info)
{
	const void *fdt = fdt_ptr;
	int offset, rc, node;

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
	rc = octeontx2_parse_boot_device(fdt, offset, node);
	if (rc) {
		INFO("Using GPIO_STRAPX register for boot device\n");
		octeontx2_boot_device_from_strapx(node);
	}

	return 0;
}
