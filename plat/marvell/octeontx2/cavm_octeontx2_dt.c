/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <platform_def.h>
#include <platform_setup.h>
#include <debug.h>
#include <libfdt.h>
#include <stdlib.h>
#include <assert.h>
#include <cavm_dt.h>
#include <cavm_common.h>
#include <cavm_utils.h>

/* define DEBUG_ATF_DTS to enable debug logs */
#undef DEBUG_ATF_DTS

#ifdef DEBUG_ATF_DTS
#define debug_dts printf
#else
#define debug_dts(...) ((void) (0))
#endif

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
	{-1, "PCIE_X1", NULL},
	{-1, "PCIE_X2", NULL},
	{-1, "PCIE_X4", NULL},
	{-1, "PCIE_X8", NULL},
	{-1, "PCIE_X16", NULL},
	{-1, "SATA", NULL},
	/* CGX/LMAC types. */
	{CAVM_CGX_LMAC_TYPES_E_SGMII, "SGMII", "sgmii"},
	{CAVM_CGX_LMAC_TYPES_E_QSGMII, "QSGMII", "qsgmii"},
	{CAVM_CGX_LMAC_TYPES_E_XAUI, "XAUI", "xaui"},
	{CAVM_CGX_LMAC_TYPES_E_RXAUI, "RXAUI", "rxaui"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "XFI", "xfi"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "SFI", "sfi"},
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "XLAUI", "xlaui"},
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "XLAUI_C2M", "xlaui"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "10G_KR", "10g_kr"},
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "40G_KR4", "40g_kr"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25GAUI_C2C", "25g"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25GAUI_C2M", "25g"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50GAUI_2_C2C", "50g"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50GAUI_2_C2M", "50g"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "CAUI_4_C2C", "100g"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "CAUI_4_C2M", "100g"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25G_AN", "25g"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50G_AN", "50g"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "100G_AN", "100g"},
	{CAVM_CGX_LMAC_TYPES_E_USXGMII, "USXGMII_4X1", "usxgmii"},
	{CAVM_CGX_LMAC_TYPES_E_USXGMII, "USXGMII_2X1", "usxgmii"},
	{CAVM_CGX_LMAC_TYPES_E_USXGMII, "USXGMII_1X1", "usxgmii"},
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
		cgx = &(bfdt->cgx_cfg[i]);
		debug_dts("N%d.CGX%d: lmac_count = %d\n", cgx->node, i,
				cgx->lmac_count);
		for (j = 0; j < cgx->lmac_count; j++) {
			lmac = &cgx->lmac_cfg[j];
			debug_dts("N%d.CGX%d.LMAC%d: mode = %s:%d, qlm = %d, lane = %d, lane_to_sds=0x%x\n",
					cgx->node,
					i,
					j,
					qlmmode_strmap[lmac->mode_idx].bdk_str,
					lmac->mode,
					lmac->qlm,
					lmac->lane,
					lmac->lane_to_sds);
			debug_dts("\tnum_rvu_vfs=%d, num_msix_vec=%d, use_training=%d\n",
					lmac->num_rvu_vfs,
					lmac->num_msix_vec,
					lmac->use_training);
			debug_dts("\tMAC=%x:%x:%x:%x:%x:%x\n",
					lmac->local_mac_address[0],
					lmac->local_mac_address[1],
					lmac->local_mac_address[2],
					lmac->local_mac_address[3],
					lmac->local_mac_address[4],
					lmac->local_mac_address[5]);
			if (lmac->phy_present) {
				phy = &lmac->phy_config;
				if (strlen(phy->phy_compatible)) {
					debug_dts("\tPHY: mdio_bus=%d, phy_addr=0x%x, compatible=%s\n",
							phy->mdio_bus,
							phy->phy_addr,
							phy->phy_compatible);
				} else {
					debug_dts("\tPHY: mdio_bus=%d, phy_addr=0x%x, compatible=NULL\n",
							phy->mdio_bus,
							phy->phy_addr);
				}
			} else {
				debug_dts("\tPHY: NONE\n");
			}
			if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) ||
				(lmac->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
				debug_dts("\tphy_mode=%d, sgmii_1000x_mode=%d, autoneg_dis=%d\n",
						lmac->phy_mode,
						lmac->sgmii_1000x_mode,
						lmac->autoneg_dis);
			}
			debug_dts("\tLMAC enable=%d\n", lmac->lmac_enable);
		}
	}
}

static int octeontx2_fdt_get_int32(const void *fdt, const char *prop,
					int offset)
{
	const uint32_t *reg;
	int val = 0;

	reg = fdt_getprop(fdt, offset, prop, NULL);
	if (!reg) {
		WARN("%s: cannot find reg property for prop %s\n",
				 __func__, prop);
		return -1;
	}
	val = fdt32_to_cpu(*reg);

	return val;
}

static uint64_t octeontx2_fdt_get_uint64(const void *fdt, const char *prop,
					int offset)
{
	const uint32_t *reg;
	uint64_t val = 0;

	reg = fdt_getprop(fdt, offset, prop, NULL);
	if (!reg) {
		WARN("%s: cannot find reg property for prop %s\n",
				 __func__, prop);
		return -1;
	}
	/* To read the 64-bit property from DT, 8-byte aligned
	 * address is required as SCTLR_EL1/EL3(aa) - alignment
	 * check enable bit is set. Ex:MDIO address is 64-bit and
	 * fdt_getprop() might not return 8 byte aligned addr.
	 * to avoid alignment fault, the below code does 2 32-bit
	 * reads to obtain 64-bit addr.
	 */
	val = (uint64_t)fdt32_to_cpu(reg[0]) << 32;
	val |= fdt32_to_cpu(reg[1]);

	return val;
}

static int octeontx2_fdt_lookup_phandle(const void *fdt_addr, int offset,
		const char *prop_name)
{
	const uint32_t *phandle;

	phandle = fdt_getprop(fdt_addr, offset, prop_name, NULL);
	if (phandle)
		return fdt_node_offset_by_phandle(fdt_addr,
					fdt32_to_cpu(*phandle));
	else
		return -FDT_ERR_NOTFOUND;
}

/* Return numeric representation of the BDK field required. Return -1, if such
 * field isn't defined. Note that -1 can be value for the field.
 */
static long octeontx2_fdtbdk_get_num(const void *fdt_addr, const char *prop,
		int base)
{
	long ret;
	int offset;
	const char *buf;
	int len;

	offset = fdt_path_offset(fdt_addr, "/cavium,bdk");
	buf = fdt_getprop(fdt_addr, offset, prop, &len);
	if (!buf) {
		debug_dts("No %s option is set in BDK.\n", prop);
		return -1;
	}
	ret = strtol(buf, NULL, base);

	return ret;
}

/**
 * octeontx2_handle_num_rvu_vfs - handle errors and report user about
 * @req_vfs: requested (via FDT) number of VFs
 * @default_vfs: default number of VFs
 * @sum_vfs: already allocated HWVFs
 * @name: node name
 *
 * returns:
 * 	Valid number (req_vfs/default_vfs/0) of VFs that can be configured
 */
static int octeontx2_handle_num_rvu_vfs(int req_vfs, int default_vfs,
					int *sum_vfs, const char *name)
{
	int hwvfs_left, ret = 0;

	hwvfs_left = MAX_RVU_HWVFS - *sum_vfs;
	/* Check if requested num_rvu_vfs does not exceed
	 * maximum number of VFs per PF and number of left HWVFs */
	if ((req_vfs <= MAX_VFS_PER_PF) && (hwvfs_left >= req_vfs)) {
		/* Valid config */
		ret = req_vfs;
	} else {
		/* Print error, try fallback to default value */
		WARN("RVU: Request to allocate more VFs (%d) than allowed\n"
		     "              for node %s, trying fallback\n"
		     "              to default (%d)\n",
		     req_vfs, name, default_vfs);
		/* Repeat check for default value */
		if ((default_vfs <= MAX_VFS_PER_PF) && (hwvfs_left >= default_vfs)) {
			WARN("RVU: Successful fallback to default VFs (%d)\n"
			     "              for node %s\n",
			     default_vfs, name);
			ret = default_vfs;
		} else {
			/* Can't do more here, zeroing
			 * number of VFs for this PF */
			ERROR("RVU: Zeroing number of VFs for node %s\n", name);
			ret = 0;
		}
	}

	return ret;
}

/**
 * octeontx2_parse_rvu_admin - fill rvu_admin_pf_t structure of rvu_config
 * @fdt: pointer to the device tree blob
 * @parentoffset: offset to parent node (ecam2)
 * @node: node name
 * @sum_vfs: already allocated HWVFs
 *
 * returns:
 * 	0 on success, -1 otherwise
 */
static int octeontx2_parse_rvu_admin(const void *fdt, int parentoffset,
				    const char *name, int *sum_vfs)
{
	int offset, len, req_vfs;
	rvu_sw_rvu_pf_t *sw_pf;
	const int *val;

	/* Find offset of *name node */
	offset = fdt_subnode_offset(fdt, parentoffset, name);
	if (offset < 0) {
		WARN("RVU: No %s node in FDT\n", name);
		return -1;
	}

	sw_pf = &(bfdt->rvu_config.admin_pf);
	/* Get number of MSIX */
	val = fdt_getprop(fdt, offset, "num-msix-vec", &len);
	if (!val) {
		WARN("RVU: No num-msix-vec, using %d number of MSIX\n"
		     "              for node %s\n", DEFAULT_MSIX_AF, name);
		sw_pf->num_msix_vec = DEFAULT_MSIX_AF;
	} else {
		sw_pf->num_msix_vec = fdt32_to_cpu(*val);
	}

	/* Get number of VFs from FDT */
	val = fdt_getprop(fdt, offset, "num-rvu-vfs", &len);
	if (!val) {
		/* If there's no such property in FDT
		 * try to assign default VFS */
		WARN("RVU: No num-rvu-vfs property for node %s\n", name);
		sw_pf->num_rvu_vfs = octeontx2_handle_num_rvu_vfs(DEFAULT_AF_PF0_VFS,
					DEFAULT_AF_PF0_VFS, sum_vfs, name);
	} else {
		/* We've got that property, handle any errors with config */
		req_vfs = fdt32_to_cpu(*val);
		sw_pf->num_rvu_vfs = octeontx2_handle_num_rvu_vfs(req_vfs,
					DEFAULT_AF_PF0_VFS, sum_vfs, name);
	}

	/* Increment number of allocated HWVFs */
	*sum_vfs += sw_pf->num_rvu_vfs;

	return 0;
}

/**
 * octeontx2_parse_sw_rvu - fill rvu_sw_pf_t structure of rvu_config
 * @fdt: pointer to the device tree blob
 * @parentoffset: offset to parent node (ecam2)
 * @node: node name
 * @sw_rvu_pf: index enumerated by sw_rvu_pfs
 * @sum_vfs: already allocated HWVFs
 *
 * returns:
 * 	0 on success, -1 otherwise
 */
static int octeontx2_parse_sw_rvu(const void *fdt, int parentoffset,
				 const char *name, int sw_rvu_pf, int *sum_vfs)
{
	int offset, len, req_vfs;
	const int *val;
	rvu_sw_rvu_pf_t *sw_pf;

	assert(sw_rvu_pf >= 0 && sw_rvu_pf < SW_RVU_MAX_PF);

	sw_pf = &(bfdt->rvu_config.sw_pf[sw_rvu_pf]);
	/* Find offset of *name node */
	offset = fdt_subnode_offset(fdt, parentoffset, name);
	if (offset < 0) {
		WARN("RVU: No %s node in FDT\n", name);
		return -1;
	}

	/* Get number of MSIX */
	val = fdt_getprop(fdt, offset, "num-msix-vec", &len);
	if (!val) {
		WARN("RVU: No num-msix-vec, using %d number of MSIX\n"
		     "              for node %s\n", DEFAULT_MSIX_SW, name);
		sw_pf->num_msix_vec = DEFAULT_MSIX_SW;
	} else {
		sw_pf->num_msix_vec = fdt32_to_cpu(*val);
	}

	/* Get number of VFs from FDT */
	val = fdt_getprop(fdt, offset, "num-rvu-vfs", &len);
	if (!val) {
		/* If there's no such property in FDT
		 * try to assign default VFS */
		WARN("RVU: No num-rvu-vfs property for node %s\n", name);
		sw_pf->num_rvu_vfs = octeontx2_handle_num_rvu_vfs(DEFAULT_VFS,
					DEFAULT_VFS, sum_vfs, name);
	} else {
		/* We've got that property, handle any errors with config */
		req_vfs = fdt32_to_cpu(*val);
		sw_pf->num_rvu_vfs = octeontx2_handle_num_rvu_vfs(req_vfs,
					DEFAULT_VFS, sum_vfs, name);
	}

	/* Increment number of allocated HWVFs */
	*sum_vfs += sw_pf->num_rvu_vfs;

	return 0;
}

static void octeontx2_parse_rvu_config(const void *fdt, int *fdt_vfs)
{
	int offset, rc, soc_offset, cpt;
	char node_name[32];
	int node = 0; /* FIXME:node to be sent as a parameter */

	/* CGX configuration is already done on this step,
	 * perform initial setup for other RVU-related nodes */
	bfdt->rvu_config.valid = 0;
	soc_offset = offset = fdt_path_offset(fdt, "/soc@0");
	if (soc_offset < 0) {
		ERROR("RVU: Unable to find soc@0 node\n");
		return;
	}

	/* Parse all subnodes of ECAM0, Domain2 */
	snprintf(node_name, sizeof(node_name), "pci@%llx",
		(CSR_PA(node, CAVM_ECAM_PF_BAR2(0)) | (2 << 28)));
	offset = fdt_subnode_offset(fdt, soc_offset, node_name);
	if (offset < 0) {
		ERROR("RVU: Unable to find ecam2 node: %s\n", node_name);
		return;
	}

	/* Fill rvu_admin_pf_t structure */
	rc = octeontx2_parse_rvu_admin(fdt, offset, RVU_ADMIN_FDT_NODE, fdt_vfs);
	if (rc < 0) {
		WARN("RVU: Unable to fill PF0-ADMIN structure\n");
		return;
	}

	/* Fill rvu_sw_rvu_pf_t structure, start with SSO_TIM (PF13) */
	rc = octeontx2_parse_sw_rvu(fdt, offset, RVU_SSO_TIM_FDT_NODE,
				    SW_RVU_SSO_TIM_PF, fdt_vfs);
	if (rc < 0) {
		WARN("RVU: Unable to fill PF13-SSO_TIM structure\n");
		return;
	}

	/* Now parse NPA (PF14) */
	rc = octeontx2_parse_sw_rvu(fdt, offset, RVU_NPA_FDT_NODE,
				    SW_RVU_NPA_PF, fdt_vfs);
	if (rc < 0) {
		WARN("RVU: Unable to fill PF14-NPA structure\n");
		return;
	}

	/* Find if CPT node is available */
	if (thunder_get_cpt_count()) {
		/* if CPT block is available, check if node is
		 * present before configuring RVU for CPT
		 */
		cpt = fdt_subnode_offset(fdt, offset, RVU_CPT_FDT_NODE);
		if (cpt < 0) {
			/* If node is not present, return error */
			WARN("RVU: CPT node is not available\n");
			return;
		}
		rc = octeontx2_parse_sw_rvu(fdt, offset, RVU_CPT_FDT_NODE,
					    SW_RVU_CPT_PF, fdt_vfs);
		if (rc < 0) {
			WARN("RVU: Unable to fill PF15 structure\n");
			return;
		}
	} else { /* CPT not available */
		debug_dts("RVU: CPT is disabled\n");
		bfdt->rvu_config.cpt_dis = 1;
	}

	/* Here we can mark FDT RVU config as valid */
	bfdt->rvu_config.valid = 1;
}


static void octeontx2_boot_device_from_strapx(const int node)
{
	cavm_gpio_strap_t gpio_strap;
	int boot_medium;

	bfdt->boot_dev.node = node;

	gpio_strap.u = CSR_READ(0, CAVM_GPIO_STRAP);
	boot_medium = (gpio_strap.u) & 0x7;

	switch (boot_medium) {
		case CAVM_RST_BOOT_METHOD_E_REMOTE_CN9:
			bfdt->boot_dev.boot_type = THUNDER_BOOT_REMOTE;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI0_CS0:
			bfdt->boot_dev.boot_type = THUNDER_BOOT_SPI;
			bfdt->boot_dev.controller = 0;
			bfdt->boot_dev.cs = 0;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI0_CS1:
			bfdt->boot_dev.boot_type = THUNDER_BOOT_SPI;
			bfdt->boot_dev.controller = 0;
			bfdt->boot_dev.cs = 1;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI1_CS0:
			bfdt->boot_dev.boot_type = THUNDER_BOOT_SPI;
			bfdt->boot_dev.controller = 1;
			bfdt->boot_dev.cs = 0;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI1_CS1:
			bfdt->boot_dev.boot_type = THUNDER_BOOT_SPI;
			bfdt->boot_dev.controller = 1;
			bfdt->boot_dev.cs = 1;
			break;
		case CAVM_RST_BOOT_METHOD_E_EMMC_CS0:
			bfdt->boot_dev.boot_type = THUNDER_BOOT_EMMC;
			bfdt->boot_dev.controller = 0;
			bfdt->boot_dev.cs = 0;
			break;
		case CAVM_RST_BOOT_METHOD_E_EMMC_CS1:
			bfdt->boot_dev.boot_type = THUNDER_BOOT_EMMC;
			bfdt->boot_dev.controller = 0;
			bfdt->boot_dev.cs = 1;
			break;
		default:
			bfdt->boot_dev.boot_type = -THUNDER_BOOT_UNSUPPORTED;
			break;
	}
}

static int octeontx2_parse_boot_device(const void *fdt, const int offset,
				       const int node)
{
	char boot_device[16], *cs;
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

	/* Get boot controller (only for SPI) */
	if (bfdt->boot_dev.boot_type == THUNDER_BOOT_SPI) {
		if (!strncmp("SPI0", boot_device, 4))
			val = 0;
		else if (!strncmp("SPI1", boot_device, 4))
			val = 1;
		else
			val = -1;
	} else {
		val = -1;
	}

	bfdt->boot_dev.controller = val;

	/* Get chip select used to boot (EMMC and SPI) */
	if (bfdt->boot_dev.boot_type == THUNDER_BOOT_SPI ||
	    bfdt->boot_dev.boot_type == THUNDER_BOOT_EMMC) {
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

	bfdt->boot_dev.cs = val;

	return 0;
}

static int octeontx2_fdt_get_bus(const void *fdt, int offset,
		int cgx_idx, int lmac_idx)
{
	int node, bus = -1;
	uint64_t mdio;
	const char *nodename;
	uint32_t i2c;

	if (offset < 0)
		return -1;

	/* obtain parent node and get the name */
	node = fdt_parent_offset(fdt, offset);
	if (node < 0)
		return -1;

	nodename = fdt_get_name(fdt, node, NULL);

	if (!strncmp(nodename, "mdio", 4)) {
		debug_dts("CGX%d.LMAC%d: PHY is on MDIO bus\n", cgx_idx, lmac_idx);
		mdio = octeontx2_fdt_get_uint64(fdt, "reg", node);
		bus = (mdio & (1 << 7)) ? 1 : 0;
		debug_dts("CGX%d.LMAC%d: mdio 0x%lx bus %d\n",
				cgx_idx, lmac_idx, mdio, bus);
	} else if (!strncmp(nodename, "i2c", 3)) {
		debug_dts("CGX%d.LMAC%d: PHY is on I2C bus\n", cgx_idx, lmac_idx);
		i2c = octeontx2_fdt_get_int32(fdt, "reg", node);
		/* based on DEVFN for TWSI 0/1 */
		bus = (i2c & (1 << 8)) ? 1 : 0;
		debug_dts("CGX%d.LMAC%d: i2c 0x%x bus %d\n",
				cgx_idx, lmac_idx, i2c, bus);
	} else
		WARN("CGX%d.LMAC%d: no compatible bus type for PHY\n",
				cgx_idx, lmac_idx);

	return bus;
}

static void octeontx2_fdt_get_i2c_bus_info(const void *fdt, int offset,
		sfp_i2c_info_t *i2c_info, int cgx_idx, int lmac_idx)
{
	int parent;

	parent = fdt_parent_offset(fdt, offset);
	if (parent < 0) {
		ERROR("CGX%d.LMAC%d: couldn't find i2c type\n",
				cgx_idx, lmac_idx);
		return;
	}

	if (!fdt_node_check_compatible(fdt, parent,
		"cavium,thunder-8890-twsi")) {
		i2c_info->type = I2C_BUS_DEFAULT;
		/* twsi bus */
		i2c_info->bus  = octeontx2_fdt_get_bus(fdt, offset,
				cgx_idx, lmac_idx);
	} else if (!fdt_node_check_compatible(fdt, parent,
				"nxp,pca9546")) {
		debug_dts("CGX%d.LMAC%d: 9546 MUX\n", cgx_idx, lmac_idx);

		i2c_info->is_mux = 0; /* PCA9546 is a switch */
		i2c_info->type = I2C_MUX_PCA9546;
		i2c_info->channel = octeontx2_fdt_get_int32(fdt, "reg",
				offset);
		i2c_info->addr = octeontx2_fdt_get_int32(fdt, "reg",
				parent);
		/* TWSI bus */
		i2c_info->bus = octeontx2_fdt_get_bus(fdt,
				parent, cgx_idx, lmac_idx);
		debug_dts("CGX%d.LMAC%d: channel %d addr 0x%x bus %d\n",
				cgx_idx, lmac_idx,
				i2c_info->channel,
				i2c_info->addr, i2c_info->bus);
	} else
		WARN("CGX%d.LMAC%d: couldn't find any valid MUX\n",
				cgx_idx, lmac_idx);
}

static void octeontx2_fdt_gpio_get_info_by_phandle(const void *fdt, int offset,
		const char *propname, sfp_gpio_info_t *gpio_info,
		int cgx_idx, int lmac_idx)
{
	int len;
	const struct fdt_property *prop;
	const uint32_t *data;
	int phandle;

	prop = fdt_get_property(fdt, offset, propname, &len);
	if (!prop) {
		WARN("CGX%d.LMAC%d: couldn't find %s property\n",
				cgx_idx, lmac_idx, propname);
		return;
	}

	if (len != 3 * sizeof(unsigned int)) {
		ERROR("CGX%d.LMAC%d: %s property is of wrong format : must contain phandle, pin & flags\n",
				cgx_idx, lmac_idx, propname);
		return;
	}

	data = (const uint32_t *)prop->data;
	phandle = fdt32_to_cpu(data[0]);
	gpio_info->pin = fdt32_to_cpu(data[1]);
	gpio_info->flags = fdt32_to_cpu(data[2]);

	int node = fdt_node_offset_by_phandle(fdt, phandle);

	if (!fdt_node_check_compatible(fdt, node,
		"cavium,thunder-8890-gpio")) {
		gpio_info->type = GPIO_PIN_DEFAULT;
		/* handle this case later */
	} else if (!fdt_node_check_compatible(fdt, node,
			"nxp,pca9535")) {
		debug_dts("CGX%d.LMAC%d: 9535 GPIO I2C Expander %d\n",
				cgx_idx, lmac_idx,
				gpio_info->pin);
		gpio_info->type = GPIO_PIN_PCA9535;
		gpio_info->num_pins = octeontx2_fdt_get_int32(fdt,
				"ngpios", node);

		gpio_info->i2c_addr = octeontx2_fdt_get_int32(fdt, "reg",
				node);
		octeontx2_fdt_get_i2c_bus_info(fdt, node, &gpio_info->i2c_info,
				cgx_idx, lmac_idx);
		debug_dts("CGX%d.LMAC%d: addr 0x%x bus %d num pins %d\n",
				cgx_idx, lmac_idx,
				gpio_info->i2c_addr, gpio_info->i2c_info.bus,
				gpio_info->num_pins);
	}
}

static void octeontx2_fdt_parse_vsc7224_reginit(const void *fdt, int offset,
			phy_vsc7224_t *vsc7224, int cgx_idx, int lmac_idx)
{
	int i;
	int len;
	const uint32_t *reginit;

	reginit = fdt_getprop(fdt, offset, "vitesse,reg-init", &len);
	if (!reginit) {
		WARN("CGX%d.LMAC%d: Cannot find \"vitesse,reg-init\" parameter.\n",
				cgx_idx, lmac_idx);
		return;
	}
	debug_dts("CGX%d.LMAC%d: \"vitesse,reg-init\" length_bytes = %d, length_words32 = %ld.\n",
			cgx_idx, lmac_idx, len, len / sizeof(*reginit));
	debug_dts("CGX%d.LMAC%d: output \"vitesse,reg-init\":\n",
			cgx_idx, lmac_idx);
	len = len / sizeof(*reginit) - 1;
	for (i = 0; i < len; i += 2) {
		debug_dts("CGX%d.LMAC%d: \t0x%x 0x%x\n", cgx_idx, lmac_idx,
				fdt32_to_cpu(*(reginit + i)),
				fdt32_to_cpu(*(reginit + i + 1)));
	}
}

static void octeontx2_fdt_parse_vsc7224_channels(const void *fdt, int offset,
			phy_vsc7224_t *vsc7224, int cgx_idx, int lmac_idx)
{
	int num_chan = 0, reg = 0, len = 0, i;
	phy_vsc7224_chan_t *chan;
	const uint32_t *tap_values;

	/* walk through all channels */
	do {
		offset = fdt_node_offset_by_compatible(fdt, offset,
					"vitesse,vsc7224-channel");
		if (offset < 0) {
			WARN("CGX%d.LMAC%d: no valid 7224 channels found\n",
					cgx_idx, lmac_idx);
			break;
		}
		reg = octeontx2_fdt_get_int32(fdt, "reg", offset);
		if (reg < 0 || reg > 3) {
			ERROR("CGX%d.LMAC%d: invalid channel, only 4 channels are valid\n",
					cgx_idx, lmac_idx);
			break;
		}
		chan = &vsc7224->channel[num_chan];

		if (fdt_getprop(fdt, offset, "direction-tx", NULL) != NULL)
			chan->is_tx = 1;
		else
			chan->is_tx = 0;

		if (fdt_getprop(fdt, offset, "pretap-disable", NULL) != NULL)
			chan->pretap_disable = 1;
		else
			chan->pretap_disable = 0;

		if (fdt_getprop(fdt, offset, "posttap-disable", NULL) != NULL)
			chan->posttap_disable = 1;
		else
			chan->posttap_disable = 0;

		if (fdt_getprop(fdt, offset, "maintap-disable", NULL) != NULL)
			chan->maintap_disable = 1;
		else
			chan->maintap_disable = 0;

		tap_values = fdt_getprop(fdt, offset, "taps", &len);
		if (!tap_values) {
			WARN("CGX%d.LMAC%d: no taps defined for vsc7224 channel %d\n",
					cgx_idx, lmac_idx, num_chan);
			break;
		}
		if (len % 16) {
			WARN("CGX%d.LMAC%d: tap values not defined in 16-bit format\n",
					cgx_idx, lmac_idx);
			break;
		}
		chan->num_taps = len/16;
		debug_dts("CGX%d.LMAC%d: taps %d chan %d\n", cgx_idx, lmac_idx,
				chan->num_taps, num_chan);

		/* Read all the tap values */
		for (i = 0; i < chan->num_taps; i++) {
			chan->taps[i].len =
					fdt32_to_cpu(tap_values[i * 4 + 0]);
			chan->taps[i].main_tap =
					fdt32_to_cpu(tap_values[i * 4 + 1]);
			chan->taps[i].pre_tap =
					fdt32_to_cpu(tap_values[i * 4 + 2]);
			chan->taps[i].post_tap =
					fdt32_to_cpu(tap_values[i * 4 + 3]);
			debug_dts("CGX%d.LMAC%d: tap %d: len: %d, main_tap: 0x%x, pre_tap:0x%x, post_tap: 0x%x\n",
				cgx_idx, lmac_idx,
				i, chan->taps[i].len,
				chan->taps[i].main_tap,
				chan->taps[i].pre_tap,
				chan->taps[i].post_tap);
		}

		num_chan++;
	} while (num_chan < 4);
}

static void octeontx2_fdt_parse_sfp_info(const void *fdt, int offset,
		int cgx_idx, int lmac_idx)
{
	sfp_i2c_info_t *i2c_info;
	sfp_gpio_info_t *mod_abs;
	sfp_slot_info_t *sfp_info;
	cgx_lmac_config_t *lmac;
	int eeprom, parent;

	lmac = &(bfdt->cgx_cfg[cgx_idx].lmac_cfg[lmac_idx]);
	sfp_info = &lmac->sfp_info;
	i2c_info = &sfp_info->i2c_eeprom_info;
	mod_abs = &sfp_info->mod_abs; /* for now, parse only mod abs */

	if (fdt_node_check_compatible(fdt, offset, "sfp-slot"))
		return;

	sfp_info->name = fdt_get_name(fdt, offset, NULL);
	debug_dts("CGX%d.LMAC%d: sfp_info->name %s\n",
			cgx_idx, lmac_idx, sfp_info->name);

	/* Parse EEPROM related I2C info */
	eeprom = octeontx2_fdt_lookup_phandle(fdt, offset, "eeprom");
	if (eeprom < 0) {
		ERROR("CGX%d.LMAC%d: Couldn't find EEPROM info for SFP\n",
				cgx_idx, lmac_idx);
		return;
	}

	i2c_info->eeprom_addr = octeontx2_fdt_get_int32(fdt, "reg", eeprom);
	parent = fdt_parent_offset(fdt, eeprom);

	octeontx2_fdt_get_i2c_bus_info(fdt, parent, i2c_info, cgx_idx, lmac_idx);

	/* Parse GPIO info for XFI-SFP interface */
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "detect", mod_abs,
			cgx_idx, lmac_idx);
}

static void octeontx2_fdt_parse_vsc7224_info(const void *fdt,
		phy_vsc7224_t *vsc7224, int cgx_idx, int lmac_idx)
{
	int offset = -1;
	int parent = -1;
	const uint32_t *reg;

	offset = fdt_node_offset_by_compatible(fdt, offset,
					"vitesse,vsc7224");

	if (offset < 0) {
		ERROR("CGX%d.LMAC%d: Cannot parse FDT info for VSC7224 phy.\n",
				cgx_idx, lmac_idx);
		return;
	}

	reg = fdt_getprop(fdt, offset, "reg", NULL);
	if (!reg) {
		ERROR("CGX%d.LMAC%d: \"vitesse,vsc7224\" section doesn't contain the reg property.\n",
				cgx_idx, lmac_idx);
		return;
	}
	vsc7224->i2c_addr = fdt32_to_cpu(*reg);
	parent = fdt_parent_offset(fdt, offset);
	octeontx2_fdt_get_i2c_bus_info(fdt, parent, &vsc7224->i2c_bus,
			cgx_idx, lmac_idx);
	vsc7224->name = fdt_get_name(fdt, offset, NULL);
	debug_dts("CGX%d.LMAC%d: PHY name %s i2c_addr 0x%x\n",
			cgx_idx, lmac_idx,
			vsc7224->name, vsc7224->i2c_addr);

	octeontx2_fdt_parse_vsc7224_reginit(fdt, offset, vsc7224,
			cgx_idx, lmac_idx);

	octeontx2_fdt_parse_vsc7224_channels(fdt, offset, vsc7224,
			cgx_idx, lmac_idx);
}

/* This routine sets a number of LMACs to initialize and the size to use.
 * For instance:
 *  - SGMII_2X1: will initialize 2 LMACs and each LMAC will take only one
 *  lane
 *  - XAUI_1X4: will initialize 1 LMAC and it will take all 4 lanes
 */
static void octeontx2_lmac_num_touse(int mode_idx, int *cnt, int *touse)
{
	*cnt = 0;
	*touse = 0;
	switch (mode_idx) {
	case CAVM_QLM_MODE_SGMII:
	case CAVM_QLM_MODE_XFI:
	case CAVM_QLM_MODE_SFI:
	case CAVM_QLM_MODE_10G_KR:
	case CAVM_QLM_MODE_25GAUI_C2C:
	case CAVM_QLM_MODE_25GAUI_C2M:
	case CAVM_QLM_MODE_25G_AN:
		*cnt = 1;
		*touse = 1;
		break;
	case CAVM_QLM_MODE_XAUI:
	case CAVM_QLM_MODE_XLAUI:
	case CAVM_QLM_MODE_XLAUI_C2M:
	case CAVM_QLM_MODE_40G_KR4:
	case CAVM_QLM_MODE_CAUI_4_C2C:
	case CAVM_QLM_MODE_CAUI_4_C2M:
	case CAVM_QLM_MODE_100G_AN:
		*cnt = 1;
		*touse = 4;
		break;
	case CAVM_QLM_MODE_RXAUI:
	case CAVM_QLM_MODE_50GAUI_2_C2C:
	case CAVM_QLM_MODE_50GAUI_2_C2M:
	case CAVM_QLM_MODE_50G_AN:
		*cnt = 1;
		*touse = 2;
		break;
	case CAVM_QLM_MODE_USXGMII_4X1:
	case CAVM_QLM_MODE_QSGMII:
		*cnt = 4;
		*touse = 1;
		break;
	case CAVM_QLM_MODE_USXGMII_2X1:
		*cnt = 2;
		*touse = 1;
		break;
	case CAVM_QLM_MODE_USXGMII_1X1:
		*cnt = 1;
		*touse = 1;
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

	debug_dts("N%d:CGX%d: qlm = %d, mode_idx = %d, lmac_need = %d\n",
			 node, cgx_idx, qlm, mode_idx, lmac_need);
	cgx = &(bfdt->cgx_cfg[cgx_idx]);
	lmac_avail = MAX_LMAC_PER_CGX - cgx->lmacs_used;

	/* This code is based on QLM<->CGX mapping and fixed per SoC.
	 * hence add model specific condition
	 */
	if ((mode_idx == CAVM_QLM_MODE_QSGMII)
	    || (mode_idx == CAVM_QLM_MODE_USXGMII_4X1)) {
		if (cgx->lmacs_used)
			lmac_avail = cgx->lmacs_used;
	} else if (cavm_is_model(OCTEONTX_CN96XX)) {
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
	} else if (cavm_is_model(OCTEONTX_CNF95XX)) {
		/* Only 2 lanes are available for QLM3 in F95 */
		if (qlm == 3) {
			lmac_avail = 2;
			for (i = 0; i < cgx->lmac_count; i++) {
				lmac = &cgx->lmac_cfg[i];
				if (lmac->qlm == qlm)
					lmac_avail--;
			}
		}
	}

	if (lmac_need > lmac_avail) {
		WARN("N%d.CGX%d: Can't configure mode:%s. Requires %d LMACs, but %d LMACs available on QLM%d.\n",
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
	cgx_lmac_config_t *lmac, *temp_lmac;
	int mode;
	int cgx_idx;
	int i, j;
	int lcnt, lused;

	if ((mode_idx < CAVM_QLM_MODE_SGMII) || (mode_idx >= CAVM_QLM_MODE_LAST)) {
		debug_dts("N%d.QLM%d.LANE%d: not configured for CGX, skip.\n",
				node, qlm, lane);
		return 0;
	}

	cgx_idx = plat_get_cgx_idx(qlm);
	if ((cgx_idx < 0) || (cgx_idx >= MAX_CGX)) {
		WARN("N%d.CGX: QLM%d cannot be configured for CGX.\n",
				node, qlm);
		return 0;
	}
	debug_dts("N%d.CGX%d: Configure QLM%d Lane%d\n", node, cgx_idx, qlm, lane);

	cgx = &(bfdt->cgx_cfg[cgx_idx]);
	if (cgx->lmac_count >= MAX_LMAC_PER_CGX) {
		WARN("N%d.CGX%d: already configured, not configuring QLM%d, Lane%d\n",
				node, cgx_idx, qlm, lane);
		return 0;
	}

	/* if CGX is configured in USXGMII mode, don't configure other modes
	 * in the same CGX
	 */
	if (cgx->usxgmii_mode) {
		WARN("N%d.CGX%d: is configured in USXGMII mode, cannot configure other modes\n",
				node, cgx_idx);
		return 0;
	}

	if (((mode_idx == CAVM_QLM_MODE_USXGMII_1X1) ||
			(mode_idx == CAVM_QLM_MODE_USXGMII_2X1) ||
			(mode_idx == CAVM_QLM_MODE_USXGMII_4X1)) &&
			(cgx->lmac_count)) {
		/* if LMACs in the same CGX for which USXGMII is configured,
		 * are configured with different modes already, UXSGMII cannot be
		 * configured
		 */
		WARN("N%d.CGX%d: cannot configure USXGMII for this CGX\n",
				node, cgx_idx);
		return 0;
	}

	octeontx2_lmac_num_touse(mode_idx, &lcnt, &lused);
	if (!lcnt || !lused) {
		debug_dts("N%d.CGX%d: the %s mode doesn't require any LMAC initialization.\n",
				node, cgx_idx,
				qlmmode_strmap[mode_idx].bdk_str);
		return 0;
	}
	debug_dts("N%d.CGX%d: mode_idx %d needs %d lanes, %d lmacs\n", node, cgx_idx, mode_idx, lused, lcnt); 
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
		/* FIXME: Parser needs to fixed to pass the correct lane
		 * as sent by BDK and to support mode configuration
		 * based on any possible lane.
		 */
		if (mode == CAVM_CGX_LMAC_TYPES_E_USXGMII) {
			if (!cgx->usxgmii_mode) {
				/* this is the first lane with USXGMII mode.
				 * update one time all LMACs lane with the same
				 * physical lane. physical SerDes lane to be
				 * programmed in case of USXGMII mode instead
				 * of lane_to_sds
				 */
				for (j = 0; j < MAX_LMAC_PER_CGX; j++) {
					temp_lmac = &cgx->lmac_cfg[j];
					temp_lmac->lane = lane;
				}
			}
		} else
			lmac->lane = lane + i;
		switch (mode) {
		case CAVM_CGX_LMAC_TYPES_E_XAUI:
		case CAVM_CGX_LMAC_TYPES_E_FORTYG_R:
		case CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R:
			lmac->lane_to_sds = 0xe4;
			break;
		case CAVM_CGX_LMAC_TYPES_E_RXAUI:
		case CAVM_CGX_LMAC_TYPES_E_FIFTYG_R:
			/* The RXAUI mode is always using a double lane. So
			 * the lane value can be 0 or 2.
			 */
			if (lane == 2)
				lmac->lane_to_sds = 0xe;
			else
				lmac->lane_to_sds = 0x4;
			break;
		default:
			lmac->lane_to_sds = lmac->lane;
			if (cavm_is_model(OCTEONTX_CN96XX) && (qlm == 5))
				lmac->lane_to_sds += 2;
			break;
		}

		switch (mode_idx) {
		case CAVM_QLM_MODE_10G_KR:
		case CAVM_QLM_MODE_40G_KR4:
			lmac->use_training = 1; /* FIXME: should be coming from SFP/QSFP */
			break;
		case CAVM_QLM_MODE_USXGMII_1X1:
		case CAVM_QLM_MODE_USXGMII_2X1:
		case CAVM_QLM_MODE_USXGMII_4X1:
			cgx->usxgmii_mode = 1;	/* set USXGMII for this CGX */
		case CAVM_QLM_MODE_XFI:
		case CAVM_QLM_MODE_SFI:
		case CAVM_QLM_MODE_XLAUI:
		case CAVM_QLM_MODE_XLAUI_C2M:
		case CAVM_QLM_MODE_RXAUI:
		case CAVM_QLM_MODE_XAUI:
		/* fixed speed option. consider as AN disabled cases */
		case CAVM_QLM_MODE_25GAUI_C2C:
		case CAVM_QLM_MODE_25GAUI_C2M:
		case CAVM_QLM_MODE_50GAUI_2_C2C:
		case CAVM_QLM_MODE_50GAUI_2_C2M:
		case CAVM_QLM_MODE_CAUI_4_C2C:
		case CAVM_QLM_MODE_CAUI_4_C2M:
			/* FIXME : always disable AN for USXGMII for now */
			lmac->autoneg_dis = 1;
			break;
		}

		cgx->lmac_count++;
		cgx->lmacs_used += lused;
	}

	cgx->enable = 1;

	/* if a QLM/DLM is configured as USXGMII (even if it uses 1 LMAC),
	 * CGX may not be used by other lanes. Hence always return 4
	 */
	if (cgx->usxgmii_mode)
		return 4;

	return (lcnt * lused);
}

/* Get the LMAC information from the Linux DT file. The following properties
 * are checked:
 *  - phy-handle
 *  - num-rvu-vfs
 *  - num-msix-vec
 * SGMII/QSGMII only:
 *  - cavium,sgmii-mac-phy-mode
 *  - cavium,sgmii-mac-1000x-mode
 *  - cavium,disable-autonegotiation
 */
static void octeontx2_cgx_lmacs_check_linux(const void *fdt,
		cgx_config_t *cgx, int cgx_idx, int cgx_offset, int *fdt_vfs)
{
	int lmac_idx;
	cgx_lmac_config_t *lmac;
	char name[16], node_name[64];
	const int *val;
	int len;
	int lmac_offset, phy_offset, sfp_offset;
	int req_vfs;
	phy_config_t *phy;
	const char *str;

	for (lmac_idx = 0; lmac_idx < cgx->lmac_count; lmac_idx++) {
		lmac = &cgx->lmac_cfg[lmac_idx];
		snprintf(name, sizeof(name), "%s@%d%d",
				qlmmode_strmap[lmac->mode_idx].linux_str,
				cgx_idx, lmac_idx);
		lmac_offset = fdt_subnode_offset(fdt, cgx_offset, name);
		if (lmac_offset < 0) {
			ERROR("CGX%d.LMAC%d: DT:%s not found in device tree\n",
					cgx_idx, lmac_idx, name);
			continue;
		}

		phy_offset = octeontx2_fdt_lookup_phandle(fdt,
				lmac_offset, "phy-handle");
		if (phy_offset > 0) {
			lmac->phy_present = 1;
			phy = &lmac->phy_config;
			str = NULL;
			str = (const char *)fdt_getprop(fdt, phy_offset,
					"compatible", &len);
			if (!str) {
				ERROR("ERROR: no compatible property in phy\n");
			} else {
				if (fdt_stringlist_contains(str, len,
						"ethernet-phy-ieee802.3-c22")) {
					phy->clause = PHY_GENERIC_8023_C22;
					debug_dts("%s: %d:%d C22 compatible PHY str\n",
						__func__, cgx_idx, lmac_idx);
				} else if (fdt_stringlist_contains(str, len,
						"ethernet-phy-ieee802.3-c45")) {
					phy->clause = PHY_GENERIC_8023_C45;
					debug_dts("%s: %d:%d C45 compatible PHY\n",
						__func__, cgx_idx, lmac_idx);
				} else
					phy->clause = PHY_GENERIC_8023_NONE;

				strncpy(phy->phy_compatible, str, 64);

				if (!strcmp(str, "vitesse,vsc7224")) {
					phy_vsc7224_t *vsc;

					vsc = &lmac->phy_config.vsc7224;
					octeontx2_fdt_parse_vsc7224_info(fdt, vsc,
						cgx_idx, lmac_idx);
				} else {
					phy->phy_addr =	octeontx2_fdt_get_int32(fdt,
							"reg", phy_offset);
					phy->mdio_bus = octeontx2_fdt_get_bus(fdt,
							phy_offset, cgx_idx,
							lmac_idx);
				}
			}
		}

		/* Check for sfp-slot info */
		sfp_offset = octeontx2_fdt_lookup_phandle(fdt,
				lmac_offset, "sfp-slot");
		if (sfp_offset > 0) {
			octeontx2_fdt_parse_sfp_info(fdt, sfp_offset,
					cgx_idx, lmac_idx);
		}

		/* Construct the proper node name for error handling */
		snprintf(node_name, sizeof(node_name), "%s/%s",
			 fdt_get_name(fdt, cgx_offset, NULL),
			 fdt_get_name(fdt, lmac_offset, NULL));
		val = fdt_getprop(fdt, lmac_offset, "num-rvu-vfs", &len);
		if (val) {
			/* We've got that property, handle any errors with config */
			req_vfs = fdt32_to_cpu(*val);
			lmac->num_rvu_vfs = octeontx2_handle_num_rvu_vfs(req_vfs,
						DEFAULT_VFS, fdt_vfs, node_name);
		} else {
			/* If there's no such property in FDT
			 * try to assign default VFS */
			WARN("RVU: No num-rvu-vfs property for node %s\n", name);
			lmac->num_rvu_vfs = octeontx2_handle_num_rvu_vfs(DEFAULT_VFS,
						DEFAULT_VFS, fdt_vfs, node_name);
		}

		/* Increment number of allocated HWVFs */
		*fdt_vfs += lmac->num_rvu_vfs;

		val = fdt_getprop(fdt, lmac_offset, "num-msix-vec", &len);
		if (val)
			lmac->num_msix_vec = fdt32_to_cpu(*val);
		else {
			WARN("N%d.CGX%d.LMAC%d: num-msix-vec not set, configuring %d number of MSIX.\n",
					cgx->node, cgx_idx, lmac_idx, DEFAULT_MSIX_LMAC);
			lmac->num_msix_vec = DEFAULT_MSIX_LMAC;
		}

		/* Fields only for the SGMII/QSGMII LMAC types. */
		if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) ||
				(lmac->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
			val = fdt_getprop(fdt, lmac_offset,
					"cavium,sgmii-mac-phy-mode", &len);
			if (val)
				lmac->phy_mode = 1;
			val = fdt_getprop(fdt, lmac_offset,
					"cavium,sgmii-mac-1000x-mode", &len);
			if (val)
				lmac->sgmii_1000x_mode = 1;
			val = fdt_getprop(fdt, lmac_offset,
					"cavium,disable-autonegotiation",
					&len);
			if (val)
				lmac->autoneg_dis = 1;
		}

		/* Enable LMAC */
		lmac->lmac_enable = 1;
	}
}

/* Main routine to parse the CGX information from the Linux DT file. */
static void octeontx2_cgx_check_linux(const void *fdt)
{
	int i;
	cgx_config_t *cgx;
	int offset, cgx_offset;
	int fdt_vfs = 0;
	char name[16];

	offset = fdt_path_offset(fdt, "/soc@0");
	if (offset < 0) {
		ERROR("DT: Can't find CGX information in the Linux DT.\n");
		return;
	}
	offset = fdt_node_offset_by_compatible(fdt, offset, "pci-bridge");
	if (offset < 0) {
		ERROR("DT: Unable to find mrml_bridge node.\n");
		return;
	}

	for (i = 0; i < MAX_CGX; i++) {
		cgx = &(bfdt->cgx_cfg[i]);
		snprintf(name, sizeof(name), "cgx@%d", i);
		if (!cgx->lmac_count)
			continue;
		cgx_offset = fdt_subnode_offset(fdt, offset, name);
		if (cgx_offset < 0) {
			ERROR("DT: %s node present in the device tree\n", name);
			continue;
		}
		octeontx2_cgx_lmacs_check_linux(fdt, cgx, i, cgx_offset, &fdt_vfs);
	}

	/* Parse RVU configuration */
	octeontx2_parse_rvu_config(fdt, &fdt_vfs);
}

/* Assign all the possible MAC addresses to the LMAC initialized.
 * This is made according to the values from the BDK DT file:
 *   BOARD-MAC-ADDRESS-NUM
 *   BOARD-MAC-ADDRESS
 * First "N" LMACs will be configured. Remaining interfaces will be
 * initialized with zeros.
 */
static void octeontx2_cgx_assign_mac(const void *fdt)
{
	int cgx_idx, lmac_idx;
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac;
	int mac_num;
	int override;
	long mac;

	/* Parse BDK DT file, to find variables to set MAC address:
	 *   BOARD-MAC-ADDRESS-NUM
	 *   BOARD-MAC-ADDRESS-NUM-OVERRIDE
	 *   BOARD-MAC-ADDRESS
	 */
	mac_num = octeontx2_fdtbdk_get_num(fdt, "BOARD-MAC-ADDRESS-NUM", 10);
	if (!mac_num)
		mac_num = octeontx2_fdtbdk_get_num(fdt, "BOARD-MAC-ADDRESS-NUM", 16);
	debug_dts("BOARD-MAC-ADDRESS-NUM=%d\n", mac_num);
	override = octeontx2_fdtbdk_get_num(fdt, "BOARD-MAC-ADDRESS-NUM-OVERRIDE", 10);
	if (override >= 0) {
		debug_dts("Override number of MAC to set=%d.\n", override);
		mac_num = override;
	}
	if (mac_num <= 0) {
		debug_dts("No MAC addresses should be set.\n");
		return;
	}
	mac = octeontx2_fdtbdk_get_num(fdt, "BOARD-MAC-ADDRESS", 16);
	debug_dts("BOARD-MAC-ADDRESS=%lx\n", mac);
	if (mac == -1) {
		debug_dts("Base MAC address is not defined.\n");
		return;
	}

	/* Initialize N first LMACs with the MAC address. */
	for (cgx_idx = 0; cgx_idx < MAX_CGX; cgx_idx++) {
		cgx = &(bfdt->cgx_cfg[cgx_idx]);
		for (lmac_idx = 0; lmac_idx < cgx->lmac_count; lmac_idx++) {
			lmac = &cgx->lmac_cfg[lmac_idx];
			if (!lmac->lmac_enable)
				continue;
			lmac->local_mac_address[0] = (mac >> 40) & 0xff;
			lmac->local_mac_address[1] = (mac >> 32) & 0xff;
			lmac->local_mac_address[2] = (mac >> 24) & 0xff;
			lmac->local_mac_address[3] = (mac >> 16) & 0xff;
			lmac->local_mac_address[4] = (mac >> 8) & 0xff;
			lmac->local_mac_address[5] = mac & 0xff;
			mac++;
			mac_num--;
			/* If there are no free LMACs, then just return
			 * from the routine.
			 */
			if (!mac_num) {
				debug_dts("All free MAC addresses are assigned.\n");
				return;
			}
		}
	}
}

/* BDK fills the CAVM_GSERNX_LANEX_SCRATCH0 register with mode used by LANE.
 * The routine goes through all the NODE/QLM/LANE sets and initializes
 * CGX/LMAC, if any.
 * After it the Linux DT file is used to get other information for CGX.
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

	nnum = thunder_get_node_count();
	for (node_idx = 0; node_idx < nnum; node_idx++) {
		for (qlm_idx = thunder_get_gser_count() - 1; qlm_idx >= 0; qlm_idx--) {
			lnum = plat_get_max_lane_num(qlm_idx);
			for (lane_idx = 0; lane_idx < lnum; lane_idx++) {
				qlm_state.u = CSR_READ(node_idx, CAVM_GSERNX_LANEX_SCRATCHX(qlm_idx, lane_idx, 0));
				debug_dts("N%d.QLM%d.LANE%d: mode=%d:%s\n",
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
	octeontx2_cgx_check_linux(fdt);
	octeontx2_cgx_assign_mac(fdt);
}

int plat_fill_board_details(int info)
{
	const void *fdt = fdt_ptr;
	int offset, rc, node;

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
	rc = octeontx2_parse_boot_device(fdt, offset, node);
	if (rc) {
		debug_dts("Using GPIO_STRAPX register for boot device\n");
		octeontx2_boot_device_from_strapx(node);
	}

	octeontx2_fill_cgx_details(fdt);

	if (info)
		octeontx2_print_board_variables();

	return 0;
}
