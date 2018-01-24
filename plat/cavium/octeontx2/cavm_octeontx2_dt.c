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

struct qlm_mode_strmap_s {
	int mode;
	char *bdk_str;
	char *linux_str;
};

static struct qlm_mode_strmap_s qlmmode_strmap[] = {
	/* These modes are defined to have a 1 to 1 reflection from the
	 * QLM/LANE mode to the array index.
	 */
	{-1, "DISABLED", NULL},
	{-1, "PCIE_1X1", NULL},
	{-1, "PCIE_1X2", NULL},
	{-1, "PCIE_1X4", NULL},
	{-1, "PCIE_1X8", NULL},
	{-1, "PCIE_1X16", NULL},
	{-1, "SATA_4X1", NULL},
	{-1, "SATA_2X1", NULL},
	/* CGX/LMAC types. */
	{CAVM_CGX_LMAC_TYPES_E_SGMII, "SGMII_4X1", "sgmii"},
	{CAVM_CGX_LMAC_TYPES_E_SGMII, "SGMII_2X1", "sgmii"},
	{CAVM_CGX_LMAC_TYPES_E_SGMII, "SGMII_1X1", "sgmii"},
	{CAVM_CGX_LMAC_TYPES_E_XAUI, "XAUI_1X4", "xaui"},
	{CAVM_CGX_LMAC_TYPES_E_RXAUI, "RXAUI_2X2", "rxaui"},
	{CAVM_CGX_LMAC_TYPES_E_RXAUI, "RXAUI_1X2", "rxaui"},
	{-1, "OCI", NULL}, /* Not supported for now. */
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "XFI_4X1", "xfi"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "XFI_2X1", "xfi"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "XFI_1X1", "xfi"},
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "XLAUI_1X4", "xlaui"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "10G_KR_4X1", "10g_kr"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "10G_KR_2X1", "10g_kr"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "10G_KR_1X1", "10g_kr"},
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "40G_KR4_1X4", "40g_kr"},
	{CAVM_CGX_LMAC_TYPES_E_QSGMII, "QSGMII_4X1", "qsgmii"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25G_4X1", "25g"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25G_2X1", "25g"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50G_2X2", "50g"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50G_1X2", "50g"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "100G_1X4", "100g"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25G_KR_4X1", "25g"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25G_KR_2X1", "25g"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50G_KR_2X2", "50g"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50G_KR_1X2", "50g"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "100G_KR4_1X4", "100g"},
	{CAVM_CGX_LMAC_TYPES_E_USXGMII, "USXGMII_4X1", "usgxgmii"},
	{CAVM_CGX_LMAC_TYPES_E_USXGMII, "USXGMII_2X1", "usgxgmii"},
	{-1, NULL, NULL}
};

/* Output information specific for OCTEONTX2, for now only CGX. */
static void octeontx2_print_board_variables(void)
{
	int i, j;
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac;
	phy_config_t *phy;

	for (i = 0; i < MAX_CGX; i++) {
		cgx = &bfdt.cgx_cfg[i];
		INFO("N%d.CGX%d: lmac_count = %d\n", cgx->node, i,
				cgx->lmac_count);
		for (j = 0; j < cgx->lmac_count; j++) {
			lmac = &cgx->lmac_cfg[j];
			INFO("N%d.CGX%d.LMAC%d: mode = %s:%d, qlm = %d, lane_to_sds=0x%x\n",
					cgx->node,
					i,
					j,
					qlmmode_strmap[lmac->mode_idx].bdk_str,
					lmac->mode,
					lmac->qlm,
					lmac->lane_to_sds);
			INFO("\tnum_rvu_vfs=%d, num_msix_vec=%d, use_training=%d\n",
					lmac->num_rvu_vfs,
					lmac->num_msix_vec,
					lmac->use_training);
			if (lmac->phy_present) {
				phy = &lmac->phy_config;
				if (strlen(phy->phy_compatible)) {
					INFO("\tPHY: mdio_bus=%d, phy_addr=0x%x, compatible=%s\n",
							phy->mdio_bus,
							phy->phy_addr,
							phy->phy_compatible);
				} else {
					INFO("\tPHY: mdio_bus=%d, phy_addr=0x%x, compatible=NULL\n",
							phy->mdio_bus,
							phy->phy_addr);
				}
			} else {
				INFO("\tPHY: NONE\n");
			}
			if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) ||
				(lmac->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
				INFO("\tphy_mode=%d, sgmii_1000x_mode=%d, autoneg_dis=%d\n",
						lmac->phy_mode,
						lmac->sgmii_1000x_mode,
						lmac->autoneg_dis);
			}
			INFO("\tLMAC enable=%d\n", lmac->lmac_enable);
		}
	}
}

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

/* This routine sets a number of LMACs to initialize and the size to use.
 * For instance:
 *  - SGMII_2X1: will initialize 2 LMACs and each LMAC will take only one
 *  size
 *  - XAUI_1X4: will initialize 1 LMAC and it will take all 4 space
 */
static void octeontx2_lmac_num_touse(int mode_idx, int *cnt, int *touse)
{
	*cnt = 0;
	*touse = 0;
	switch (mode_idx) {
	case CAVM_QLM_MODE_SGMII_4X1:
	case CAVM_QLM_MODE_XFI_4X1:
	case CAVM_QLM_MODE_10G_KR_4X1:
	case CAVM_QLM_MODE_QSGMII_4X1:
	case CAVM_QLM_MODE_25G_4X1:
	case CAVM_QLM_MODE_25G_KR_4X1:
	case CAVM_QLM_MODE_USXGMII_4X1:
		*cnt = 4;
		*touse = 1;
		break;
	case CAVM_QLM_MODE_SGMII_2X1:
	case CAVM_QLM_MODE_XFI_2X1:
	case CAVM_QLM_MODE_10G_KR_2X1:
	case CAVM_QLM_MODE_25G_2X1:
	case CAVM_QLM_MODE_25G_KR_2X1:
	case CAVM_QLM_MODE_USXGMII_2X1:
		*cnt = 2;
		*touse = 1;
		break;
	case CAVM_QLM_MODE_SGMII_1X1:
	case CAVM_QLM_MODE_XFI_1X1:
	case CAVM_QLM_MODE_10G_KR_1X1:
		*cnt = 1;
		*touse = 1;
		break;
	case CAVM_QLM_MODE_XAUI_1X4:
	case CAVM_QLM_MODE_XLAUI_1X4:
	case CAVM_QLM_MODE_40G_KR4_1X4:
	case CAVM_QLM_MODE_100G_1X4:
	case CAVM_QLM_MODE_100G_KR4_1X4:
		*cnt = 1;
		*touse = 4;
		break;
	case CAVM_QLM_MODE_RXAUI_2X2:
	case CAVM_QLM_MODE_50G_2X2:
	case CAVM_QLM_MODE_50G_KR_2X2:
		*cnt = 2;
		*touse = 2;
		break;
	case CAVM_QLM_MODE_RXAUI_1X2:
	case CAVM_QLM_MODE_50G_1X2:
	case CAVM_QLM_MODE_50G_KR_1X2:
		*cnt = 1;
		*touse = 2;
		break;
	}
}

/* Check if it is possible to configure LMAC in the current mode. Return
 * 0 in case of success, otherwise return -1.
 */
static int octeontx2_check_qlm_lmacs(int node, int cgx_idx,
		int qlm, int mode_idx, int lmac_need)
{
	int lmac_avail;
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac;
	int i;

	cgx = &bfdt.cgx_cfg[cgx_idx];
	lmac_avail = MAX_LMAC_PER_CGX - cgx->lmacs_used;
	if ((qlm == 3) || (qlm == 7)) {
		/* Only QLM3 or QLM7 may be Ethernet, not both. */
		for (i = 0; i < cgx->lmac_count; i++) {
			lmac = &cgx->lmac_cfg[i];
			if (lmac->qlm != qlm) {
				WARN("N%d.CGX%d: Can't configure mode:%s. QLM%d is requested, but QLM%d is used.",
						node, cgx_idx,
						qlmmode_strmap[mode_idx].bdk_str,
						qlm, lmac->qlm);
				lmac_avail = 0;
				break;
			}
		}
	} else if ((qlm == 4) || (qlm == 5)) {
		/* QLM4 and QLM5 does not support quad lane Ethernet
		 * protocols. Only two lanes are available for each
		 * QLM.
		 */
		lmac_avail = 2;
		for (i = 0; i < cgx->lmac_count; i++) {
			lmac = &cgx->lmac_cfg[i];
			if (lmac->qlm == qlm)
				lmac_avail--;
		}
	}

	if (lmac_need > lmac_avail) {
		WARN("N%d.CGX%d: Can't configure mode:%s. Requires %d free LMACs, but %d LMACs available on QLM%d.\n",
				node, cgx_idx,
				qlmmode_strmap[mode_idx].bdk_str,
				lmac_need, lmac_avail, qlm);
		return -1;
	}

	return 0;
}

/* Fill CGX structure, if possible.
 * Return the number of lanes used for initialization.
 */
static int octeontx2_fill_cgx_struct(int node, int qlm, int lane, int mode_idx)
{
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac;
	int mode;
	int cgx_idx;
	int i;
	int lcnt, lused;

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

	octeontx2_lmac_num_touse(mode_idx, &lcnt, &lused);
	if (!lcnt || !lused) {
		INFO("N%d.CGX%d: the %s mode doesn't require any LMAC initialization.\n",
				node, cgx_idx,
				qlmmode_strmap[mode_idx].bdk_str);
		return 0;
	}
	if (octeontx2_check_qlm_lmacs(node, cgx_idx, qlm, mode_idx, lcnt * lused))
		return 0;
	if (lane % (lcnt * lused)) {
		WARN("N%d.CGX%d.LANE%d: wrong LANE%d for the %s mode.\n",
				node, cgx_idx, lane, lane,
				qlmmode_strmap[mode_idx].bdk_str);
		return 0;
	}

	mode = qlmmode_strmap[mode_idx].mode;
	/* Fill in the CGX/LMAC structures. */
	cgx->node = node;
	for (i = 0; i < lcnt; i++) {
		lmac = &cgx->lmac_cfg[cgx->lmac_count];
		lmac->lane_to_sds = -1;
		lmac->mode = mode;
		lmac->mode_idx = mode_idx;
		lmac->qlm = qlm;
		switch (mode) {
		case CAVM_CGX_LMAC_TYPES_E_XAUI:
		case CAVM_CGX_LMAC_TYPES_E_FORTYG_R:
		case CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R:
			lmac->lane_to_sds = 0xe4;
			break;
		case CAVM_CGX_LMAC_TYPES_E_RXAUI:
			if (lane % 2)
				lmac->lane_to_sds = 0xe;
			else
				lmac->lane_to_sds = 0x4;
			break;
		default:
			lmac->lane_to_sds = lane + i;
			if (qlm == 5)
				lmac->lane_to_sds += 2;
			break;
		}
		switch (mode_idx) {
		case CAVM_QLM_MODE_10G_KR_4X1:
		case CAVM_QLM_MODE_10G_KR_2X1:
		case CAVM_QLM_MODE_10G_KR_1X1:
		case CAVM_QLM_MODE_40G_KR4_1X4:
		case CAVM_QLM_MODE_25G_KR_4X1:
		case CAVM_QLM_MODE_25G_KR_2X1:
		case CAVM_QLM_MODE_50G_KR_2X2:
		case CAVM_QLM_MODE_50G_KR_1X2:
		case CAVM_QLM_MODE_100G_KR4_1X4:
			lmac->use_training = 1;
			break;
		}

		cgx->lmac_count++;
		cgx->lmacs_used += lused;
	}

	cgx->enable = 1;

	return (lcnt * lused);
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
				INFO("N%d.QLM%d.LANE%d: mode=%d:%s\n",
						node_idx, qlm_idx, lane_idx,
						qlm_state.s.mode,
						qlmmode_strmap[qlm_state.s.mode].bdk_str);
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
	if (info)
		octeontx2_print_board_variables();

	return 0;
}
