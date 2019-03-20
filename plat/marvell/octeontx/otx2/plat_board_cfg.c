/*
 * Copyright (C) 2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#include <platform_def.h>
#include <platform_setup.h>
#include <debug.h>
#include <libfdt.h>
#include <stdlib.h>
#include <assert.h>
#include <plat_board_cfg.h>
#include <octeontx_common.h>
#include <octeontx_board_cfg_bl1.h>
#include <plat_scfg.h>
#include <plat_otx2_configuration.h>

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
	{CAVM_CGX_LMAC_TYPES_E_SGMII, "1G_X", "sgmii"},
	{CAVM_CGX_LMAC_TYPES_E_QSGMII, "QSGMII", "qsgmii"},
	{CAVM_CGX_LMAC_TYPES_E_XAUI, "XAUI", "xaui"},
	{CAVM_CGX_LMAC_TYPES_E_RXAUI, "RXAUI", "rxaui"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "XFI", "xfi"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "SFI", "sfi"},
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "XLAUI", "xlaui"},
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "XLAUI_C2M", "xlaui"},
	{CAVM_CGX_LMAC_TYPES_E_TENG_R, "10G_KR", "xfi-10g-kr"},
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "40G_KR4", "xlaui-40g-kr"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "20GAUI_C2C", "25gaui"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "20GAUI_C2M", "25gaui"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25GAUI_C2C", "25gaui"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25GAUI_C2M", "25gaui"},
	/* FIXME: if this new mode need to be supported in SDK.
	 * For now, just add the string match
	 */
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "40GAUI_2_C2C", "40gaui"},
	{CAVM_CGX_LMAC_TYPES_E_FORTYG_R, "40GAUI_2_C2M", "40gaui"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50GAUI_2_C2C", "50gaui"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50GAUI_2_C2M", "50gaui"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "80GAUI_4_C2C", "caui"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "80GAUI_4_C2M", "caui"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "CAUI_4_C2C", "caui"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "CAUI_4_C2M", "caui"},
	{CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R, "25G_AN", "25g_kr"},
	{CAVM_CGX_LMAC_TYPES_E_FIFTYG_R, "50G_AN", "50g_kr"},
	{CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R, "100G_AN", "100g_kr"},
	{CAVM_CGX_LMAC_TYPES_E_USXGMII, "USXGMII_4X1", "usxgmii"},
	{CAVM_CGX_LMAC_TYPES_E_USXGMII, "USXGMII_2X1", "usxgmii"},
	{CAVM_CGX_LMAC_TYPES_E_USXGMII, "USXGMII_1X1", "usxgmii"},
	{-1, NULL, NULL}
};

/* List of GPIO types - used as expanders in case of SFP/QSFP/PHY */
static const gpio_compat_t gpio_compat_list[] = {
	{ "cavium,thunder-8890-gpio", GPIO_PIN_DEFAULT, 64 },	/* 64 pins for T9x */
	{ "nxp_pca9505",	GPIO_PIN_PCA953X, 40 },
	{ "nxp_pca9698",	GPIO_PIN_PCA953X, 40 },
	{ "nxp_pca9534",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9535",	GPIO_PIN_PCA953X, 16 },
	{ "nxp_pca9536",	GPIO_PIN_PCA953X, 4 },
	{ "nxp_pca9537",	GPIO_PIN_PCA953X, 4 },
	{ "nxp_pca9538",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9539",	GPIO_PIN_PCA953X, 16 },
	{ "nxp_pca9554",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9554a",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9555",	GPIO_PIN_PCA953X, 16 },
	{ "nxp_pca9555a",	GPIO_PIN_PCA953X, 16 },
	{ "nxp_pca9556",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9557",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9574",	GPIO_PIN_PCA957X, 8 },
	{ "nxp_pca9575",	GPIO_PIN_PCA957X, 16 },
	{ "maxim_max7310",	GPIO_PIN_PCA953X, 8 },
	{ "maxim_max7312",	GPIO_PIN_PCA953X, 16 },
	{ "maxim_max7313",	GPIO_PIN_PCA953X, 16 },
	{ "maxim_max7315",	GPIO_PIN_PCA953X, 8 },
	{ "ti_pca6107",		GPIO_PIN_PCA953X, 8 },
	{ "ti_tca6408",		GPIO_PIN_PCA953X, 8 },
	{ "ti_tca6416",		GPIO_PIN_PCA953X, 16 },
	{ "ti_tca9554",		GPIO_PIN_PCA953X, 8 },
	{ "nxp_pcf8574",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pcf8574a",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca8574",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca9670",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca9672",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca9674",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca8575",	GPIO_PIN_PCF857X, 16 },
	{ "nxp_pcf8575",	GPIO_PIN_PCF857X, 16 },
	{ "nxp_pca9671",	GPIO_PIN_PCF857X, 16 },
	{ "nxp_pca9673",	GPIO_PIN_PCF857X, 16 },
	{ "nxp_pca9675",	GPIO_PIN_PCF857X, 16 },
	{ "maxim_max7328",	GPIO_PIN_PCF857X, 8 },
	{ "maxim_max7329",	GPIO_PIN_PCF857X, 8 },
	{ "cavium,cpld96xx",	GPIO_PIN_CPLD,	8},
};

/* List of I2C Mux/Switch types */
static const i2c_compat_t i2c_compat_list[] = {
	{ "cavium,thunder-8890-twsi", I2C_BUS_DEFAULT, I2C_OTHER,  0, 6},
	{ "cavium,thunderx-i2c", I2C_BUS_DEFAULT, I2C_OTHER,  0, 6},
	{ "nxp_pca9540", I2C_BUS_PCA9540, I2C_MUX,    4, 2 },
	{ "nxp_pca9542", I2C_BUS_PCA9542, I2C_MUX,    4, 2 },
	{ "nxp_pca9543", I2C_BUS_PCA9543, I2C_SWITCH, 0, 2 },
	{ "nxp_pca9544", I2C_BUS_PCA9544, I2C_MUX,    4, 4 },
	{ "nxp_pca9545", I2C_BUS_PCA9545, I2C_SWITCH, 0, 4 },
	{ "nxp_pca9546", I2C_BUS_PCA9546, I2C_SWITCH, 0, 4 },
	{ "nxp_pca9547", I2C_BUS_PCA9547, I2C_MUX,    8, 8 },
	{ "nxp_pca9548", I2C_BUS_PCA9548, I2C_SWITCH, 0, 8 },
};

/* List of PHY compatible strings/types */
static const phy_compatible_type_t phy_compat_list[] = {
	{ "marvell,88x5123", PHY_MARVELL_5123},
	{ "marvell,88x5113", PHY_MARVELL_5113},
#ifdef MARVELL_PHY_6141
	{ "marvell,88x6141", PHY_MARVELL_6141},
#endif /* MARVELL_PHY_6141 */
	{ "marvell,88e1514", PHY_MARVELL_88E1514},
	{ "marvell,88e1512", PHY_MARVELL_88E1514},
	{ "vitesse,vsc8574", PHY_VITESSE_8574},
	{ "ethernet-phy-ieee802.3-c22", PHY_GENERIC_8023_C22},
	{ "ethernet-phy-ieee802.3-c45", PHY_GENERIC_8023_C45},
};

/* Output information specific for OCTEONTX2, for now only CGX. */
void plat_octeontx_print_board_variables(void)
{
	int i, j;
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac;
	phy_config_t *phy;

	for (i = 0; i < plat_octeontx_scfg->cgx_count; i++) {
		cgx = &(plat_octeontx_bcfg->cgx_cfg[i]);
		debug_dts("CGX%d: lmac_count = %d\n", i, cgx->lmac_count);
		for (j = 0; j < cgx->lmac_count; j++) {
			lmac = &cgx->lmac_cfg[j];
			debug_dts("CGX%d.LMAC%d: mode = %s:%d, qlm = %d, lane = %d, lane_to_sds=0x%x\n",
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
				if (phy->type != PHY_NONE) {
					debug_dts("\tPHY: mdio_bus=%d\t"
							"phy_addr=0x%x\t"
							"type=%d switch=%d\t"
							"port=%d\n",
							phy->mdio_bus,
							phy->addr,
							phy->type,
							phy->mux_switch,
							phy->port);
				}
			} else {
				debug_dts("\tPHY: NONE\n");
			}
			if (lmac->sfp_slot) {
				debug_dts("\tSFP: present\n");
				debug_dts("\tis_sfp=%d\n", lmac->sfp_info.is_sfp);
				debug_dts("\tis_qsfp=%d\n", lmac->sfp_info.is_qsfp);
				debug_dts("\tmax_power=%dmW\n", lmac->sfp_info.max_power);
			}
			if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) ||
				(lmac->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
				debug_dts("\tphy_mode=%d, sgmii_1000x_mode=%d, autoneg_dis=%d\n",
						lmac->phy_mode,
						lmac->sgmii_1000x_mode,
						lmac->autoneg_dis);
			}
			debug_dts("\tfec_type=%d\n", lmac->fec);
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
		debug_dts("%s: cannot find property %s\n",
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
		WARN("%s: Cannot find property for prop %s\n",
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

	sw_pf = &(plat_octeontx_bcfg->rvu_config.admin_pf);
	/* Get number of MSIX */
	val = fdt_getprop(fdt, offset, "num-msix-vec", &len);
	if (!val) {
		VERBOSE("RVU: No num-msix-vec, using %d number of MSIX\n"
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
		VERBOSE("RVU: No num-rvu-vfs property for node %s\n", name);
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

	sw_pf = &(plat_octeontx_bcfg->rvu_config.sw_pf[sw_rvu_pf]);
	/* Find offset of *name node */
	offset = fdt_subnode_offset(fdt, parentoffset, name);
	if (offset < 0) {
		WARN("RVU: No %s node in FDT\n", name);
		return -1;
	}

	/* Get number of MSIX */
	val = fdt_getprop(fdt, offset, "num-msix-vec", &len);
	if (!val) {
		VERBOSE("RVU: No num-msix-vec, using %d number of MSIX\n"
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
		VERBOSE("RVU: No num-rvu-vfs property for node %s\n", name);
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

	/* CGX configuration is already done on this step,
	 * perform initial setup for other RVU-related nodes */
	plat_octeontx_bcfg->rvu_config.valid = 0;
	soc_offset = offset = fdt_path_offset(fdt, "/soc@0");
	if (soc_offset < 0) {
		ERROR("RVU: Unable to find soc@0 node\n");
		return;
	}

	/* Parse all subnodes of ECAM0, Domain2 */
	snprintf(node_name, sizeof(node_name), "pci@%llx",
		(ECAM_PF_BAR2(0) | (2 << 28)));
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
	if (plat_octeontx_get_cpt_count()) {
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
		plat_octeontx_bcfg->rvu_config.cpt_dis = 1;
	}

	/* Here we can mark FDT RVU config as valid */
	plat_octeontx_bcfg->rvu_config.valid = 1;
}


static void octeontx2_boot_device_from_strapx()
{
	cavm_gpio_strap_t gpio_strap;
	int boot_medium;

	gpio_strap.u = CSR_READ(CAVM_GPIO_STRAP);
	boot_medium = (gpio_strap.u) & 0x7;

	switch (boot_medium) {
		case CAVM_RST_BOOT_METHOD_E_REMOTE_CN9:
			plat_octeontx_bcfg->bcfg.boot_dev.boot_type = OCTEONTX_BOOT_REMOTE;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI0_CS0:
			plat_octeontx_bcfg->bcfg.boot_dev.boot_type = OCTEONTX_BOOT_SPI;
			plat_octeontx_bcfg->bcfg.boot_dev.controller = 0;
			plat_octeontx_bcfg->bcfg.boot_dev.cs = 0;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI0_CS1:
			plat_octeontx_bcfg->bcfg.boot_dev.boot_type = OCTEONTX_BOOT_SPI;
			plat_octeontx_bcfg->bcfg.boot_dev.controller = 0;
			plat_octeontx_bcfg->bcfg.boot_dev.cs = 1;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI1_CS0:
			plat_octeontx_bcfg->bcfg.boot_dev.boot_type = OCTEONTX_BOOT_SPI;
			plat_octeontx_bcfg->bcfg.boot_dev.controller = 1;
			plat_octeontx_bcfg->bcfg.boot_dev.cs = 0;
			break;
		case CAVM_RST_BOOT_METHOD_E_SPI1_CS1:
			plat_octeontx_bcfg->bcfg.boot_dev.boot_type = OCTEONTX_BOOT_SPI;
			plat_octeontx_bcfg->bcfg.boot_dev.controller = 1;
			plat_octeontx_bcfg->bcfg.boot_dev.cs = 1;
			break;
		case CAVM_RST_BOOT_METHOD_E_EMMC_CS0:
			plat_octeontx_bcfg->bcfg.boot_dev.boot_type = OCTEONTX_BOOT_EMMC;
			plat_octeontx_bcfg->bcfg.boot_dev.controller = 0;
			plat_octeontx_bcfg->bcfg.boot_dev.cs = 0;
			break;
		case CAVM_RST_BOOT_METHOD_E_EMMC_CS1:
			plat_octeontx_bcfg->bcfg.boot_dev.boot_type = OCTEONTX_BOOT_EMMC;
			plat_octeontx_bcfg->bcfg.boot_dev.controller = 0;
			plat_octeontx_bcfg->bcfg.boot_dev.cs = 1;
			break;
		default:
			plat_octeontx_bcfg->bcfg.boot_dev.boot_type = -OCTEONTX_BOOT_UNSUPPORTED;
			break;
	}
}

static int octeontx2_parse_boot_device(const void *fdt, const int offset)
{
	char boot_device[16], *cs;
	const char *name;
	int len, val;

	snprintf(boot_device, sizeof(boot_device), "BOOT-DEVICE.N0");
	name = fdt_getprop(fdt, offset, boot_device, &len);
	if (!name) {
		WARN("No %s is found\n", boot_device);
		return -1;
	}

	strncpy(boot_device, name, sizeof(boot_device));
	boot_device[sizeof(boot_device) - 1] = '\0';

	/* Get boot type */
	if (!strncmp("SPI", boot_device, 3))
		val = OCTEONTX_BOOT_SPI;
	else if (!strncmp("EMMC", boot_device, 4))
		val = OCTEONTX_BOOT_EMMC;
	else if (!strncmp("REMOTE", boot_device, 6))
		val = OCTEONTX_BOOT_REMOTE;
	else
		val = -OCTEONTX_BOOT_UNSUPPORTED;

	plat_octeontx_bcfg->bcfg.boot_dev.boot_type = val;

	/* Get boot controller (only for SPI) */
	if (plat_octeontx_bcfg->bcfg.boot_dev.boot_type == OCTEONTX_BOOT_SPI) {
		if (!strncmp("SPI0", boot_device, 4))
			val = 0;
		else if (!strncmp("SPI1", boot_device, 4))
			val = 1;
		else
			val = -1;
	} else {
		val = -1;
	}

	plat_octeontx_bcfg->bcfg.boot_dev.controller = val;

	/* Get chip select used to boot (EMMC and SPI) */
	if (plat_octeontx_bcfg->bcfg.boot_dev.boot_type == OCTEONTX_BOOT_SPI ||
	    plat_octeontx_bcfg->bcfg.boot_dev.boot_type == OCTEONTX_BOOT_EMMC) {
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

	plat_octeontx_bcfg->bcfg.boot_dev.cs = val;

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
		debug_dts("CGX%d.LMAC%d: MDIO node\n", cgx_idx, lmac_idx);
		mdio = octeontx2_fdt_get_uint64(fdt, "reg", node);
		if (mdio != -1)
			bus = (mdio & (1 << 7)) ? 1 : 0;
		debug_dts("CGX%d.LMAC%d: mdio 0x%llx bus %d\n",
				cgx_idx, lmac_idx, mdio, bus);
	} else if (!strncmp(nodename, "i2c", 3)) {
		debug_dts("CGX%d.LMAC%d: I2C node\n", cgx_idx, lmac_idx);
		i2c = octeontx2_fdt_get_int32(fdt, "reg", node);
		/* based on DEVFN, obtain TWSI bus */
		bus = ((i2c >> 8) & 0x7);
		debug_dts("CGX%d.LMAC%d: bus %d\n",
				cgx_idx, lmac_idx, bus);
	} else
		WARN("CGX%d.LMAC%d: no compatible bus type for PHY/SFP\n",
				cgx_idx, lmac_idx);

	return bus;
}

static void octeontx2_fdt_get_i2c_bus_info(const void *fdt, int offset,
		i2c_info_t *i2c_info, int cgx_idx, int lmac_idx)
{
	int parent;

	parent = fdt_parent_offset(fdt, offset);
	if (parent < 0) {
		ERROR("CGX%d.LMAC%d: couldn't find i2c type\n",
				cgx_idx, lmac_idx);
		return;
	}

	for (int i = 0; i < ARRAY_SIZE(i2c_compat_list); i++) {
		if (!fdt_node_check_compatible(fdt, parent,
					       i2c_compat_list[i].compatible)) {
			debug_dts("CGX%d.LMAC%d: I2C type %d\n", cgx_idx,
					lmac_idx, i2c_compat_list[i].type);
			i2c_info->type = i2c_compat_list[i].type;
			if (i2c_info->type == I2C_BUS_DEFAULT) {
				/* TWSI bus */
				i2c_info->bus = octeontx2_fdt_get_bus(fdt,
					offset, cgx_idx, lmac_idx);
			} else { /* all other MUX/SWITCH cases */
				i2c_info->is_mux = i2c_compat_list[i].mux_type;
				i2c_info->channel = octeontx2_fdt_get_int32(fdt,
							"reg", offset);
				i2c_info->addr = octeontx2_fdt_get_int32(fdt,
							"reg", parent);
				/* TWSI bus */
				i2c_info->bus = octeontx2_fdt_get_bus(fdt,
					parent, cgx_idx, lmac_idx);
				debug_dts("CGX%d.LMAC%d: I2C SWITCH %d: channel %d addr 0x%x bus %d\n",
					cgx_idx, lmac_idx, !i2c_info->is_mux,
					i2c_info->channel,
					i2c_info->addr, i2c_info->bus);
			}
			break;
		}
	}
	if (i2c_info->type == I2C_BUS_NONE)
		debug_dts("CGX%d.LMAC%d: couldn't find valid I2C BUS type\n",
				cgx_idx, lmac_idx);
}

static void octeontx2_fdt_gpio_get_info_by_phandle(const void *fdt, int offset,
		const char *propname, gpio_info_t *gpio_info,
		int cgx_idx, int lmac_idx)
{
	int len;
	const struct fdt_property *prop;
	const uint32_t *data;
	int phandle, parent;

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

	debug_dts("CGX%d.LMAC%d: GPIO name %s pin %d flags %d\n",
			cgx_idx, lmac_idx, propname, gpio_info->pin, gpio_info->flags);
	for (int i = 0; i < ARRAY_SIZE(gpio_compat_list); i++) {
		if (!fdt_node_check_compatible(fdt, node,
				gpio_compat_list[i].compatible)) {
			debug_dts("CGX%d.LMAC%d: gpio type %d\n", cgx_idx,
					lmac_idx, gpio_compat_list[i].type);

			/* If the gpio is connected directly, just update
			 * the type and return
			 */
			if (gpio_compat_list[i].type == GPIO_PIN_DEFAULT) {
				gpio_info->type = gpio_compat_list[i].type;
				break;
			}

			/* For all other GPIO pins that are connected
			 * through expanders
			 */
			gpio_info->num_pins = octeontx2_fdt_get_int32(fdt,
				"ngpios", node);

			/* If the gpio is connected directly, just update
			 * the type and return
			 */
			if (gpio_compat_list[i].type == GPIO_PIN_DEFAULT) {
				gpio_info->type = gpio_compat_list[i].type;
				break;
			}

			/* For all other GPIO pins that are connected
			 * through expanders
			 */
			gpio_info->num_pins = octeontx2_fdt_get_int32(fdt,
				"ngpios", node);
			/* If max number of GPIOs are not available from
			 * DT, get it from the static table
			 */
			if (!gpio_info->num_pins)
				gpio_info->num_pins = gpio_compat_list[i].ngpios;
			gpio_info->type = gpio_compat_list[i].type;
			gpio_info->i2c_addr = octeontx2_fdt_get_int32(fdt, "reg",
				node);
			octeontx2_fdt_get_i2c_bus_info(fdt, node,
					&gpio_info->i2c_info,
					cgx_idx, lmac_idx);
			if (gpio_info->i2c_info.type == I2C_BUS_NONE) {
				/* There might be the case of where the GPIO
				 * expander is behind the I2C switch. Hence
				 * pass the parent node to obtain the
				 * i2c info again
				 */
				parent = fdt_parent_offset(fdt, node);
				octeontx2_fdt_get_i2c_bus_info(fdt, parent,
					&gpio_info->i2c_info,
					cgx_idx, lmac_idx);
			}
			gpio_info->i2c_bus = gpio_info->i2c_info.bus;
			debug_dts("CGX%d.LMAC%d: GPIO controller : addr 0x%x bus %d num pins %d\n",
				cgx_idx, lmac_idx,
				gpio_info->i2c_addr, gpio_info->i2c_bus,
				gpio_info->num_pins);
			break;
		}
	}
	if (gpio_info->type == GPIO_PIN_NONE)
		WARN("CGX%d.LMAC%d: couldn't find any valid GPIO type\n",
				cgx_idx, lmac_idx);
}

static void octeontx2_fdt_parse_qsfp_info(const void *fdt, int offset,
		int cgx_idx, int lmac_idx)
{
	const char *name;
	i2c_info_t *i2c_info;
	sfp_slot_info_t *qsfp_info;
	cgx_lmac_config_t *lmac;
	int eeprom, parent;

	lmac = &(plat_octeontx_bcfg->cgx_cfg[cgx_idx].lmac_cfg[lmac_idx]);
	qsfp_info = &lmac->sfp_info;
	i2c_info = &qsfp_info->i2c_eeprom_info;

	if (fdt_node_check_compatible(fdt, offset, "qsfp-slot"))
		return;

	lmac->sfp_slot = 1;	/* SFP slot is present */
	qsfp_info->is_qsfp = 1;	/* To indicate slot is QSFP */
	qsfp_info->is_sfp = 0;
	name = fdt_get_name(fdt, offset, NULL);
	strncpy(qsfp_info->name, name, sizeof(qsfp_info->name));
	debug_dts("CGX%d.LMAC%d: qsfp_info->name %s\n",
			cgx_idx, lmac_idx, qsfp_info->name);

	/* obtain MAX power for the slot as per the board design */
	qsfp_info->max_power = octeontx2_fdt_get_int32(fdt, "max_power", offset);

	/* Parse EEPROM related I2C info */
	eeprom = octeontx2_fdt_lookup_phandle(fdt, offset, "eeprom");
	if (eeprom < 0) {
		ERROR("CGX%d.LMAC%d: Couldn't find EEPROM info for SFP\n",
				cgx_idx, lmac_idx);
		return;
	}

	parent = fdt_parent_offset(fdt, eeprom);

	qsfp_info->eeprom_addr = octeontx2_fdt_get_int32(fdt, "reg", eeprom);

	debug_dts("CGX%d.LMAC%d: EEPROM addr 0x%x\n", cgx_idx, lmac_idx,
					qsfp_info->eeprom_addr);

	octeontx2_fdt_get_i2c_bus_info(fdt, parent, i2c_info,
					cgx_idx, lmac_idx);

	/* Parse GPIO info for QSFP interface */
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "mod_sel",
			&qsfp_info->select, cgx_idx, lmac_idx);
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "reset",
			&qsfp_info->reset, cgx_idx, lmac_idx);
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "lowpow_mode",
			&qsfp_info->lp_mode, cgx_idx, lmac_idx);
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "mod_present",
			&qsfp_info->mod_prs, cgx_idx, lmac_idx);
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "int",
			&qsfp_info->interrupt, cgx_idx, lmac_idx);
}

static void octeontx2_fdt_parse_sfp_info(const void *fdt, int offset,
		int cgx_idx, int lmac_idx)
{
	const char *name;
	i2c_info_t *i2c_info;
	sfp_slot_info_t *sfp_info;
	cgx_lmac_config_t *lmac;
	int eeprom, parent;

	lmac = &(plat_octeontx_bcfg->cgx_cfg[cgx_idx].lmac_cfg[lmac_idx]);
	sfp_info = &lmac->sfp_info;
	i2c_info = &sfp_info->i2c_eeprom_info;

	if (fdt_node_check_compatible(fdt, offset, "sfp-slot"))
		return;

	lmac->sfp_slot = 1;	/* SFP slot is present */
	sfp_info->is_sfp = 1;	/* To indicate slot is SFP */
	sfp_info->is_qsfp = 0;
	name = fdt_get_name(fdt, offset, NULL);
	strncpy(sfp_info->name, name, sizeof(sfp_info->name));
	debug_dts("CGX%d.LMAC%d: sfp_info->name %s\n",
			cgx_idx, lmac_idx, sfp_info->name);

	/* obtain MAX power for the slot as per the board design */
	sfp_info->max_power = octeontx2_fdt_get_int32(fdt, "max_power", offset);

	/* Parse EEPROM related I2C info */
	eeprom = octeontx2_fdt_lookup_phandle(fdt, offset, "eeprom");
	if (eeprom < 0) {
		ERROR("CGX%d.LMAC%d: Couldn't find EEPROM info for SFP\n",
				cgx_idx, lmac_idx);
		return;
	}

	parent = fdt_parent_offset(fdt, eeprom);

	sfp_info->eeprom_addr = octeontx2_fdt_get_int32(fdt, "reg", eeprom);

	debug_dts("CGX%d.LMAC%d: EEPROM addr 0x%x\n", cgx_idx, lmac_idx,
					sfp_info->eeprom_addr);

	octeontx2_fdt_get_i2c_bus_info(fdt, parent, i2c_info, cgx_idx, lmac_idx);

	/* Parse GPIO info for SFP interface */
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "detect",
			&sfp_info->mod_abs, cgx_idx, lmac_idx);
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "tx_disable",
			&sfp_info->tx_disable, cgx_idx, lmac_idx);
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "tx_fault",
			&sfp_info->tx_fault, cgx_idx, lmac_idx);
	octeontx2_fdt_gpio_get_info_by_phandle(fdt, offset, "rx_los",
			&sfp_info->rx_los, cgx_idx, lmac_idx);
}

fec_type_t octeontx2_handle_fec_config(int mode, int req_fec)
{
	int fec = req_fec;

	/* FEC can be disabled by user. In that case, no need
	 * to validate against any PCS supported FEC option.
	 */
	if (fec == CGX_FEC_NONE) {
		debug_dts("%s: FEC disabled\n", __func__);
		return fec;
	}

	/* Validate FEC configuration against PCS supported FEC option.
	 * If the type is not correct, set FEC to be -1 so default
	 * FEC type can be configured
	 */
	switch (mode) {
	case CAVM_CGX_LMAC_TYPES_E_TENG_R:
	case CAVM_CGX_LMAC_TYPES_E_FORTYG_R:
		if (fec != CGX_FEC_BASE_R) {
			WARN("%s: 10G/40G PCS doesn't support FEC type %d\n", __func__, req_fec);
			fec = -1;
		}
	break;
	case CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R:
	case CAVM_CGX_LMAC_TYPES_E_FIFTYG_R:
		if ((fec != CGX_FEC_BASE_R) && (fec != CGX_FEC_RS)) {
			WARN("%s: 25G/50G PCS doesn't support FEC type %d\n", __func__, req_fec);
			fec = -1;
		}
	break;
	case CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R:
		if (fec != CGX_FEC_RS) {
			WARN("%s: 100G PCS doesn't support FEC type %d\n", __func__, req_fec);
			fec = -1;
		}
	break;
	case CAVM_CGX_LMAC_TYPES_E_USXGMII:
		if (fec != CGX_FEC_RS) {
			WARN("%s: USXGMII PCS doesn't support FEC type %d\n", __func__, req_fec);
			fec = -1;
		}
	break;
	default:
		fec = 0;
	break;
	}

	return fec;
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
	case QLM_MODE_1G_X:
	case QLM_MODE_SGMII:
	case QLM_MODE_XFI:
	case QLM_MODE_SFI:
	case QLM_MODE_10G_KR:
	case QLM_MODE_20GAUI_C2C:
	case QLM_MODE_20GAUI_C2M:
	case QLM_MODE_25GAUI_C2C:
	case QLM_MODE_25GAUI_C2M:
	case QLM_MODE_25G_AN:
		*cnt = 1;
		*touse = 1;
		break;
	case QLM_MODE_XAUI:
	case QLM_MODE_XLAUI:
	case QLM_MODE_XLAUI_C2M:
	case QLM_MODE_40GAUI_2_C2C:
	case QLM_MODE_40GAUI_2_C2M:
	case QLM_MODE_40G_KR4:
	case QLM_MODE_80GAUI_4_C2C:
	case QLM_MODE_80GAUI_4_C2M:
	case QLM_MODE_CAUI_4_C2C:
	case QLM_MODE_CAUI_4_C2M:
	case QLM_MODE_100G_AN:
		*cnt = 1;
		*touse = 4;
		break;
	case QLM_MODE_RXAUI:
	case QLM_MODE_50GAUI_2_C2C:
	case QLM_MODE_50GAUI_2_C2M:
	case QLM_MODE_50G_AN:
		*cnt = 1;
		*touse = 2;
		break;
	case QLM_MODE_USXGMII_4X1:
	case QLM_MODE_QSGMII:
		*cnt = 4;
		*touse = 1;
		break;
	case QLM_MODE_USXGMII_2X1:
		*cnt = 2;
		*touse = 1;
		break;
	case QLM_MODE_USXGMII_1X1:
		*cnt = 1;
		*touse = 1;
		break;
	}
}

/* Check if it is possible to configure LMAC in the current mode. Return
 * 0 in case of success, otherwise return -1.
 */
static int octeontx2_check_qlm_lmacs(int cgx_idx,
		int qlm, int mode_idx, int lmac_need)
{
	int lmac_avail;
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac;
	int i;
	int max_lanes = plat_octeontx_scfg->qlm_max_lane_num[qlm];

	debug_dts("CGX%d: qlm = %d, mode_idx = %d, lmac_need = %d\n",
			 cgx_idx, qlm, mode_idx, lmac_need);
	cgx = &(plat_octeontx_bcfg->cgx_cfg[cgx_idx]);
	lmac_avail = MAX_LMAC_PER_CGX - cgx->lmacs_used;

	/* This code is based on QLM<->CGX mapping and fixed per SoC.
	 * hence add model specific condition
	 */
	if ((mode_idx == QLM_MODE_QSGMII)
	    || (mode_idx == QLM_MODE_USXGMII_4X1)) {
		if (cgx->lmacs_used)
			lmac_avail = cgx->lmacs_used;
	} else if (cavm_is_model(OCTEONTX_CN96XX)) {
		if ((qlm == 3) || (qlm == 7)) {
			/* Only QLM3 or QLM7 may be Ethernet, not both. */
			for (i = 0; i < cgx->lmac_count; i++) {
				lmac = &cgx->lmac_cfg[i];
				if (lmac->qlm != qlm) {
					WARN("CGX%d: Can't configure mode:%s. QLM%d is requested, but QLM%d is used.",
						cgx_idx,
						qlmmode_strmap[mode_idx].bdk_str,
						qlm, lmac->qlm);
					lmac_avail = 0;
					break;
				}
			}
		} else if (max_lanes == 2) {
			/* DLMs does not support quad lane Ethernet protocols.
			 * Only two lanes are available.
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
		WARN("CGX%d: Can't configure mode:%s. Requires %d LMACs, but %d LMACs available on QLM%d.\n",
				cgx_idx,
				qlmmode_strmap[mode_idx].bdk_str,
				lmac_need, lmac_avail, qlm);
		return -1;
	}

	return 0;
}

/* Fill CGX structure, if possible.
 * Return the number of lanes used for initialization.
 */
static int octeontx2_fill_cgx_struct(int qlm, int lane, int mode_idx)
{
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac, *temp_lmac;
	int mode;
	int cgx_idx;
	int i, j;
	int lcnt, lused, lane_to_sds;

	if ((mode_idx < QLM_MODE_SGMII) || (mode_idx >= QLM_MODE_LAST)) {
		debug_dts("QLM%d.LANE%d: not configured for CGX, skip.\n", qlm, lane);
		return 0;
	}

	cgx_idx = plat_get_cgx_idx(qlm);
	if ((cgx_idx < 0) || (cgx_idx >= plat_octeontx_scfg->cgx_count)) {
		WARN("CGX: QLM%d cannot be configured for CGX.\n", qlm);
		return 0;
	}
	debug_dts("CGX%d: Configure QLM%d Lane%d\n", cgx_idx, qlm, lane);

	cgx = &(plat_octeontx_bcfg->cgx_cfg[cgx_idx]);
	if (cgx->lmac_count >= MAX_LMAC_PER_CGX) {
		WARN("CGX%d: already configured, not configuring QLM%d, Lane%d\n",
				cgx_idx, qlm, lane);
		return 0;
	}

	/* if CGX is configured in USXGMII mode, don't configure other modes
	 * in the same CGX
	 */
	if (cgx->usxgmii_mode) {
		WARN("CGX%d: is configured in USXGMII mode, cannot configure other modes\n",
				cgx_idx);
		return 0;
	}

	if (((mode_idx == QLM_MODE_USXGMII_1X1) ||
			(mode_idx == QLM_MODE_USXGMII_2X1) ||
			(mode_idx == QLM_MODE_USXGMII_4X1)) &&
			(cgx->lmac_count)) {
		/* if LMACs in the same CGX for which USXGMII is configured,
		 * are configured with different modes already, UXSGMII cannot be
		 * configured
		 */
		WARN("CGX%d: cannot configure USXGMII for this CGX\n",
				cgx_idx);
		return 0;
	}

	octeontx2_lmac_num_touse(mode_idx, &lcnt, &lused);
	if (!lcnt || !lused) {
		debug_dts("CGX%d: the %s mode doesn't require any LMAC initialization.\n",
				cgx_idx,
				qlmmode_strmap[mode_idx].bdk_str);
		return 0;
	}
	debug_dts("CGX%d: mode_idx %d needs %d lanes, %d lmacs\n", cgx_idx, mode_idx, lused, lcnt); 
	if (octeontx2_check_qlm_lmacs(cgx_idx, qlm, mode_idx, lcnt * lused))
		return 0;
	if (lane % (lcnt * lused)) {
		WARN("CGX%d.LANE%d: wrong LANE%d for the %s mode.\n",
				cgx_idx, lane, lane,
				qlmmode_strmap[mode_idx].bdk_str);
		return 0;
	}

	mode = qlmmode_strmap[mode_idx].mode;
	/* Fill in the CGX/LMAC structures. */
	for (i = 0; i < lcnt; i++) {
		lmac = &cgx->lmac_cfg[cgx->lmac_count];
		if ((!strncmp(plat_octeontx_bcfg->bcfg.board_model, "ebb96",
				5)) ||
			(!strncmp(plat_octeontx_bcfg->bcfg.board_model,
				"ebb93", 5)))
			lane_to_sds = 0x1B; /* Lanes are reversed */
		else
			lane_to_sds = 0xE4; /* Default value */
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
					if ((!strncmp(plat_octeontx_bcfg->bcfg.board_model,
						"ebb96", 5)) ||
					(!strncmp(plat_octeontx_bcfg->bcfg.board_model,
						"ebb93", 5)))
						temp_lmac->lane = ~lane & 3;
					else
						temp_lmac->lane = lane;
				}
			}
		} else
			lmac->lane = lane + i;
		switch (mode) {
		case CAVM_CGX_LMAC_TYPES_E_XAUI:
		case CAVM_CGX_LMAC_TYPES_E_FORTYG_R:
		case CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R:
			lmac->lane_to_sds = lane_to_sds;
			break;
		case CAVM_CGX_LMAC_TYPES_E_RXAUI:
		case CAVM_CGX_LMAC_TYPES_E_FIFTYG_R:
			/* The RXAUI mode is always using a double lane. So
			 * the lane value can be 0 or 2.
			 */
			if (cavm_is_model(OCTEONTX_CN9XXX) && (qlm == 5))
				lane += 2;
			lmac->lane_to_sds = (lane_to_sds >> (lane * 2)) & 0xF;
			break;
		default:
			if (cavm_is_model(OCTEONTX_CN9XXX) && (qlm == 5))
				lane += 2;
			lmac->lane_to_sds = (lane_to_sds >> (lane * 2)) & 0x3;
			break;
		}

		switch (mode_idx) {
		case QLM_MODE_10G_KR:
		case QLM_MODE_40G_KR4:
			lmac->use_training = 1; /* FIXME: should be coming from SFP/QSFP */
			break;
		case QLM_MODE_USXGMII_1X1:
		case QLM_MODE_USXGMII_2X1:
		case QLM_MODE_USXGMII_4X1:
			cgx->usxgmii_mode = 1;	/* set USXGMII for this CGX */
		case QLM_MODE_XFI:
		case QLM_MODE_SFI:
		case QLM_MODE_XLAUI:
		case QLM_MODE_XLAUI_C2M:
		case QLM_MODE_RXAUI:
		case QLM_MODE_XAUI:
		/* fixed speed option. consider as AN disabled cases */

		case QLM_MODE_20GAUI_C2C:
		case QLM_MODE_20GAUI_C2M:
		case QLM_MODE_25GAUI_C2C:
		case QLM_MODE_25GAUI_C2M:
		case QLM_MODE_40GAUI_2_C2C:
		case QLM_MODE_40GAUI_2_C2M:
		case QLM_MODE_50GAUI_2_C2C:
		case QLM_MODE_50GAUI_2_C2M:
		case QLM_MODE_80GAUI_4_C2C:
		case QLM_MODE_80GAUI_4_C2M:
		case QLM_MODE_CAUI_4_C2C:
		case QLM_MODE_CAUI_4_C2M:
			/* FIXME : always disable AN for USXGMII for now */
			lmac->autoneg_dis = 1;
			break;
		}

		cgx->lmac_count++;
		cgx->lmacs_used += lused;

		/* In case of 1000 BASE-X, update the property of LMAC */
		if (mode_idx == QLM_MODE_1G_X)
			lmac->sgmii_1000x_mode = 1;
	}

	cgx->enable = 1;

	/* if a QLM/DLM is configured as USXGMII (even if it uses 1 LMAC),
	 * CGX may not be used by other lanes. Hence always return 4
	 */
	if (cgx->usxgmii_mode)
		return 4;

	return (lcnt * lused);
}

static int octeontx2_cgx_get_phy_info(const void *fdt, int lmac_offset, int cgx_idx, int lmac_idx)
{
	cgx_lmac_config_t *lmac;
	int phy_offset, mux_offset;
	char phyname[16];
	phy_config_t *phy;

	lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_idx].lmac_cfg[lmac_idx];

	strncpy(phyname, "phy-handle", sizeof(phyname));

	/* FIXME: Using board model is safe to use for now */
	if (!strncmp(plat_octeontx_bcfg->bcfg.board_model, "ebb96", 5)) {
		/* On EBB9604 board, PHY address can be different on
		 * QLM 3 and QLM 7 and at a time, ethernet can be configured
		 * either on QLM3 or QLM7 only and not both. CGX0 is mapped to
		 * QLM 3 or QLM 7. Hence if it is CGX0, check for the
		 * QLM number it is mapped to look for the phy-handle.
		 * QLM 3: phy-handle
		 * QLM 7: phy-handle1
		 */
		if ((cgx_idx == 0) && (lmac->qlm == 7))
			strncpy(phyname, "phy-handle1", sizeof(phyname));
	}

	phy_offset = octeontx2_fdt_lookup_phandle(fdt, lmac_offset, phyname);
	if (phy_offset > 0) {
		phy = &lmac->phy_config;

		for (int i = 0; i < ARRAY_SIZE(phy_compat_list); i++) {
			if (!fdt_node_check_compatible(fdt, phy_offset,
				phy_compat_list[i].compatible)) {
				phy->type = phy_compat_list[i].phy_type;
				debug_dts("%s: %d:%d PHY type %d\n",
					__func__, cgx_idx, lmac_idx,
					phy->type);
				break;
			}
		}
		if (phy->type == PHY_NONE) {
			ERROR("ERROR: Supported PHY compatible not found\n");
			return -1;
		}
		/* Save the PHY address and bus for all PHY types */
		phy->addr = octeontx2_fdt_get_int32(fdt,
					"reg", phy_offset);
		phy->mdio_bus = octeontx2_fdt_get_bus(fdt,
				phy_offset, cgx_idx,
				lmac_idx);
		phy->port = octeontx2_fdt_get_int32(fdt,
					"port", phy_offset);

		/* Check if the MDIO bus is behind a switch */
		mux_offset = octeontx2_fdt_lookup_phandle(fdt,
					phy_offset, "mdio-mux");
		if (mux_offset > 0) {
			if (fdt_node_check_compatible(fdt, mux_offset,
						"octeontx2,mdio-mux")) {
				WARN("%s: %d:%d MDIO switch not compatible\n",
							__func__,
							cgx_idx, lmac_idx);
				return -1;
			}

			octeontx2_fdt_gpio_get_info_by_phandle(fdt,
					mux_offset, "gpios",
					&phy->mux_info, cgx_idx, lmac_idx);
			phy->mux_switch = 1;
		}
		lmac->phy_present = 1;
	}
	return 0;
}

/* Get the LMAC information from the Linux DT file. The following properties
 * are checked:
 *  - phy-handle
 *  - num-rvu-vfs
 *  - num-msix-vec
 * SGMII/QSGMII only:
 *  - octeontx,sgmii-mac-phy-mode
 *  - octeontx,disable-autonegotiation
 */
static void octeontx2_cgx_lmacs_check_linux(const void *fdt,
		cgx_config_t *cgx, int cgx_idx, int cgx_offset, int *fdt_vfs)
{
	int lmac_idx;
	cgx_lmac_config_t *lmac;
	char name[16], node_name[64];
	const int *val;
	int len, ret;
	int lmac_offset, sfp_offset, qsfp_offset;
	int req_vfs, req_fec;
	char sfpname[16], qsfpname[16];

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

		ret = octeontx2_cgx_get_phy_info(fdt, lmac_offset, cgx_idx, lmac_idx);
		if (ret == -1) {
			/* If there are errors encountered in obtaining the valid PHY
			 * info in case of PHY present, don't enable the LMAC. just return
			 * here.
			 */
			WARN("%s: %d:%d PHY info not correct\n", __func__,
						cgx_idx, lmac_idx);
			continue;
		}

		strncpy(sfpname, "sfp-slot", sizeof(sfpname));
		strncpy(qsfpname, "qsfp-slot", sizeof(qsfpname));

		/* FIXME: Using board model is safe to use for now */
		if (!strncmp(plat_octeontx_bcfg->bcfg.board_model, "ebb9", 4)) {
			/* On EBB9604 board, PHY address can be different on
			 * QLM 3 and QLM 7 and at a time, ethernet can be configured
			 * either on QLM3 or QLM7 only and not both. CGX0 is mapped to
			 * QLM 3 or QLM 7. Hence if it is CGX0, check for the
			 * QLM number it is mapped to look for the sfp-slot.
			 * QLM 3: sfp-slot
			 * QLM 7: sfp-slot1
			 */
			if ((cgx_idx == 0) && (lmac->qlm == 7)) {
				strncpy(sfpname, "sfp-slot1", sizeof(sfpname));
				strncpy(qsfpname, "qsfp-slot1", sizeof(qsfpname));
			}
		}

		/* Check for sfp-slot info */
		sfp_offset = octeontx2_fdt_lookup_phandle(fdt,
				lmac_offset, sfpname);
		if (sfp_offset > 0) {
			octeontx2_fdt_parse_sfp_info(fdt, sfp_offset,
					cgx_idx, lmac_idx);
		}

		/* Check for qsfp-slot info */
		qsfp_offset = octeontx2_fdt_lookup_phandle(fdt,
				lmac_offset, qsfpname);
		if (qsfp_offset > 0) {
			octeontx2_fdt_parse_qsfp_info(fdt, qsfp_offset,
					cgx_idx, lmac_idx);
		}

		/* Handle FEC types */
		val = fdt_getprop(fdt, lmac_offset,
				"octeontx,fec-type", &len);
		if (val) {
			req_fec = fdt32_to_cpu(*val);
			lmac->fec = octeontx2_handle_fec_config(
				lmac->mode, req_fec);
		} else {
			/* User did not specify FEC type property
			 * in the DT. set it to -1 to configure
			 * the default type.
			 */
			lmac->fec = -1;
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
			VERBOSE("RVU: No num-rvu-vfs property for node %s\n", name);
			lmac->num_rvu_vfs = octeontx2_handle_num_rvu_vfs(DEFAULT_VFS,
						DEFAULT_VFS, fdt_vfs, node_name);
		}

		/* Increment number of allocated HWVFs */
		*fdt_vfs += lmac->num_rvu_vfs;

		val = fdt_getprop(fdt, lmac_offset, "num-msix-vec", &len);
		if (val)
			lmac->num_msix_vec = fdt32_to_cpu(*val);
		else {
			VERBOSE("CGX%d.LMAC%d: num-msix-vec not set, configuring %d number of MSIX.\n",
					cgx_idx, lmac_idx, DEFAULT_MSIX_LMAC);
			lmac->num_msix_vec = DEFAULT_MSIX_LMAC;
		}

		/* Fields only for the SGMII/QSGMII LMAC types. */
		if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) ||
				(lmac->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
			val = fdt_getprop(fdt, lmac_offset,
					"octeontx,sgmii-mac-phy-mode", &len);
			if (val)
				lmac->phy_mode = 1;
			val = fdt_getprop(fdt, lmac_offset,
					"octeontx,disable-autonegotiation",
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

	for (i = 0; i < plat_octeontx_scfg->cgx_count; i++) {
		cgx = &(plat_octeontx_bcfg->cgx_cfg[i]);
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

	/* Update the board configuration */
	plat_octeontx_bcfg->pf_mac_base = mac;
	plat_octeontx_bcfg->pf_mac_num = mac_num;

	/* Initialize N first LMACs with the MAC address. */
	for (cgx_idx = 0; cgx_idx < plat_octeontx_scfg->cgx_count; cgx_idx++) {
		cgx = &(plat_octeontx_bcfg->cgx_cfg[cgx_idx]);
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
 * The routine goes through all the QLM/LANE sets and initializes
 * CGX/LMAC, if any.
 * After it the Linux DT file is used to get other information for CGX.
 */
static void octeontx2_fill_cgx_details(const void *fdt)
{
	int qlm_idx;
	int lane_idx;
	int lnum;
	int linit;
	octeontx_qlm_state_lane_t qlm_state;

	for (qlm_idx = 0; qlm_idx < plat_octeontx_get_gser_count(); qlm_idx++) {
		lnum = plat_octeontx_scfg->qlm_max_lane_num[qlm_idx];
		for (lane_idx = 0; lane_idx < lnum; lane_idx++) {
			qlm_state.u = CSR_READ(CAVM_GSERNX_LANEX_SCRATCHX(qlm_idx, lane_idx, 0));
			debug_dts("QLM%d.LANE%d: mode=%d:%s\n",
					qlm_idx, lane_idx,
					qlm_state.s.mode,
					qlmmode_strmap[qlm_state.s.mode].bdk_str);
			linit = octeontx2_fill_cgx_struct(qlm_idx, lane_idx, qlm_state.s.mode);
			/* If number of initialized lanes is more
			 * than 1, then we should skip these
			 * initializations.
			 */
			if (linit > 1)
				lane_idx += linit - 1;
		}
	}
	octeontx2_cgx_check_linux(fdt);
	octeontx2_cgx_assign_mac(fdt);
}

int plat_octeontx_fill_board_details(void)
{
	const void *fdt = fdt_ptr;
	int offset, rc;

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

	rc = octeontx2_parse_boot_device(fdt, offset);
	if (rc) {
		debug_dts("Using GPIO_STRAPX register for boot device\n");
		octeontx2_boot_device_from_strapx();
	}

	octeontx2_fill_cgx_details(fdt);

	return 0;
}
