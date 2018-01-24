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

/* Define different QLM-MODE variants. These definitions based on the BDK code. */
typedef enum {
	CAVM_QLM_MODE_DISABLED,		/* QLM is disabled (all chips) */
	CAVM_QLM_MODE_PCIE_1X1,		/* 1 PCIe, 1 lane. Other lanes unused */
	CAVM_QLM_MODE_PCIE_1X2,		/* 1 PCIe, 2 lanes */
	CAVM_QLM_MODE_PCIE_1X4,		/* 1 PCIe, 4 lanes */
	CAVM_QLM_MODE_PCIE_1X8,		/* 1 PCIe, 8 lanes */
	CAVM_QLM_MODE_PCIE_1X16,	/* 1 PCIe, 16 lanes (CN93XX) */
	CAVM_QLM_MODE_SATA_4X1,		/* SATA, each lane independent (cn88xx) */
	CAVM_QLM_MODE_SATA_2X1,		/* SATA, each lane independent (cn83xx) */
	CAVM_QLM_MODE_SGMII_4X1,	/* SGMII, each lane independent (cn88xx) */
	CAVM_QLM_MODE_SGMII_2X1,	/* SGMII, each lane independent (cn83xx) */
	CAVM_QLM_MODE_SGMII_1X1,	/* SGMII, single lane (cn80xx) */
	CAVM_QLM_MODE_XAUI_1X4,		/* 1 XAUI or DXAUI, 4 lanes (cn88xx), use gbaud to tell difference */
	CAVM_QLM_MODE_RXAUI_2X2,	/* 2 RXAUI, 2 lanes each (cn88xx) */
	CAVM_QLM_MODE_RXAUI_1X2,	/* 1 RXAUI, 2 lanes each (cn83xx) */
	CAVM_QLM_MODE_OCI,		/* OCI Multichip interconnect (cn88xx) */
	CAVM_QLM_MODE_XFI_4X1,		/* 4 XFI, 1 lane each (cn88xx) */
	CAVM_QLM_MODE_XFI_2X1,		/* 2 XFI, 1 lane each (cn83xx) */
	CAVM_QLM_MODE_XFI_1X1,		/* 1 XFI, single lane (cn80xx) */
	CAVM_QLM_MODE_XLAUI_1X4,	/* 1 XLAUI, 4 lanes each (cn88xx) */
	CAVM_QLM_MODE_10G_KR_4X1,	/* 4 10GBASE-KR, 1 lane each (cn88xx) */
	CAVM_QLM_MODE_10G_KR_2X1,	/* 2 10GBASE-KR, 1 lane each (cn83xx) */
	CAVM_QLM_MODE_10G_KR_1X1,	/* 1 10GBASE-KR, single lane (cn80xx) */
	CAVM_QLM_MODE_40G_KR4_1X4,	/* 1 40GBASE-KR4, 4 lanes each (cn88xx) */
	CAVM_QLM_MODE_QSGMII_4X1,	/* QSGMII is 4 SGMII on one lane (cn81xx, cn83xx) */
	CAVM_QLM_MODE_25G_4X1,		/* 25G, 1 lane each (CN93XX QLMs) */
	CAVM_QLM_MODE_25G_2X1,		/* 25G, 1 lane each (CN93XX DLMs) */
	CAVM_QLM_MODE_50G_2X2,		/* 50G, 2 lanes each (CN93XX QLMs) */
	CAVM_QLM_MODE_50G_1X2,		/* 50G, 2 lanes each (CN93XX DLMs) */
	CAVM_QLM_MODE_100G_1X4,		/* 100G, 4 lanes each (CN93XX) */
	CAVM_QLM_MODE_25G_KR_4X1,	/* 25G-KR, 1 lane each (CN93XX QLMs) */
	CAVM_QLM_MODE_25G_KR_2X1,	/* 25G-KR, 1 lane each (CN93XX DLMs) */
	CAVM_QLM_MODE_50G_KR_2X2,	/* 50G-KR, 2 lanes each (CN93XX QLMs) */
	CAVM_QLM_MODE_50G_KR_1X2,	/* 50G-KR, 2 lanes each (CN93XX DLMs) */
	CAVM_QLM_MODE_100G_KR4_1X4,	/* 100G-KR4, 4 lanes each (CN93XX) */
	CAVM_QLM_MODE_USXGMII_4X1,	/* USXGMII, 4 over 1 lane, 10M, 100M, 1G, 2.5G, 5G (CN93XX QLMs) */
	CAVM_QLM_MODE_USXGMII_2X1,	/* USXGMII, 2 over 1 lane, 10M, 100M, 1G, 2.5G, 5G, 10G (CN93XX QLMs) */
	CAVM_QLM_MODE_LAST,
} cavm_qlm_modes_t;

/* This structure is stored in GSERNX_LANEX_SCRATCHX to remember the mode of a
 * single lane. Based on the BDK structure;
 */
typedef union
{
	uint64_t u;
	struct {
		uint16_t baud_mhz;		/* Baudrate of the lane in MHz */
		cavm_qlm_modes_t mode: 8;	/* Mode of the lane, enumerated by cavm_qlm_modes_t */
		uint32_t flags: 8;		/* Mode flags */
		uint32_t reserved;		/* Reserved for future use */
	} s;
} cavm_qlm_state_lane_t;

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

/* Return number of lanes available for different QLMs. */
static int octeontx2_get_lane_num(int qlm)
{
	if ((qlm == 4) || (qlm == 5)) {
		return 2;
	}
	return 4;
}

/* Return the CGX index in the cgx_cfg array based on the QLM value. If
 * there is no such QLM, then -1 will be returned.
 */
static int octeontx2_get_cgx_idx(int qlm)
{
	int idx;

	switch (qlm) {
	case 3:
	case 7:
		idx = 0;
		break;
	case 4:
	case 5:
		idx = 1;
		break;
	case 6:
		idx = 2;
		break;
	default:
		idx = -1;
		break;
	}

	return idx;
}

/* Fill CGX structure, if possible.
 * Return the number of lanes used for initialization.
 */
static int octeontx2_fill_cgx_struct(int node, int qlm, int lane, int mode_idx)
{
	cgx_config_t *cgx;
	int cgx_idx;

	if ((mode_idx < CAVM_QLM_MODE_SGMII_4X1) || (mode_idx > CAVM_QLM_MODE_USXGMII_2X1)) {
		INFO("N%d.QLM%d.LANE%d: not configured for CGX, skip.\n",
				node, qlm, lane);
		return 0;
	}

	cgx_idx = octeontx2_get_cgx_idx(qlm);
	if ((cgx_idx < 0) || (cgx_idx >= MAX_CGX)) {
		WARN("N%d.CGX: QLM%d cannot be configured for CGX.\n",
				node, qlm);
		return 0;
	}
	INFO("N%d.CGX%d: Configure QLM%d Lane%d\n", node, cgx_idx, qlm, lane);

	cgx = &bfdt.cgx_cfg[cgx_idx];
	if (cgx->lmac_count >= MAX_LMAC_PER_CGX) {
		WARN("N%d.CGX%d: already configured, not configuring QLM%d, Lane%d\n",
				node, cgx_idx, qlm, lane);
		return 0;
	}

	return 0;
}

/* BDK fills the CAVM_GSERNX_LANEX_SCRATCH0 register with mode used by LANE.
 * The routine goes through all the NODE/QLM/LANE sets and initializes
 * CGX/LMAC, if any.
 */
static void octeontx2_fill_cgx_details(const void *fdt)
{
	int node_idx;
	int qlm_idx;
	int lane_idx;
	int nnum;
	int lnum;
	int linit;
	cavm_qlm_state_lane_t qlm_state;
	uint64_t gser_base;

	nnum = thunder_get_node_count();
	for (node_idx = 0; node_idx < nnum; node_idx++) {
		for (qlm_idx = 3; qlm_idx <= 7; qlm_idx++) {
			lnum = octeontx2_get_lane_num(qlm_idx);
			gser_base = CSR_PA(node_idx, CAVM_GSERX_PF_BAR0(qlm_idx));
			for (lane_idx = 0; lane_idx < lnum; lane_idx++) {
				qlm_state.u = CSR_READ(gser_base, CAVM_GSERNX_LANEX_SCRATCHX(qlm_idx, lane_idx, 0));
				INFO("N%d.QLM%d.LANE%d: mode=%d\n",
						node_idx, qlm_idx, lane_idx,
						qlm_state.s.mode);
				linit = octeontx2_fill_cgx_struct(node_idx,
						qlm_idx, lane_idx,
						qlm_state.s.mode);
				/* If number of initialized lanes is more
				 * than 1, then we should skip these
				 * initializations.
				 */
				if (linit > 1)
					lane_idx += linit - 1;
			}
		}
	}
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

	octeontx2_fill_cgx_details(fdt);

	return 0;
}
