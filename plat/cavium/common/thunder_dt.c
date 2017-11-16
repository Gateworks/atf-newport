/** @file

  Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <platform_def.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <thunder_dt.h>
#include <thunder_private.h>
#include <debug.h>
#include <assert.h>

#include <libfdt.h>

board_fdt_t bfdt;

static void print_board_variables()
{
	INFO("======================\n");
	INFO("BOARD MODEL = %s\n", bfdt.board_model);
	INFO("BMC BOOT TWSI node=%d bus=0x%x, addr=0x%x\n",
		bfdt.bmc_boot_twsi_node,
		bfdt.bmc_boot_twsi_bus,
		bfdt.bmc_boot_twsi_addr);
	INFO("BMC IPMI TWSI node=%d bus=0x%x, addr=0x%x\n",
		bfdt.bmc_ipmi_twsi_node,
		bfdt.bmc_ipmi_twsi_bus,
		bfdt.bmc_ipmi_twsi_addr);
	INFO("GPIO Shutdown pin IN = 0x%x\n",
		bfdt.gpio_shutdown_ctl_in);
	INFO("GPIO Shutdown pin OUT = 0x%x\n",
		bfdt.gpio_shutdown_ctl_out);
#if TRUSTED_BOARD_BOOT
	INFO("TRUST-ROT-ADDR = 0x%lx\n",
		bfdt.trust_rot_addr);
	INFO("TRUST-BSSK-ADDR = 0x%lx\n",
		bfdt.trust_key_addr);
#endif
	INFO("======================\n");

}

#if TRUSTED_BOARD_BOOT
static uint64_t thunder_fdt_get_uint64(const void *fdt, int offset, const char *property, int base)
{
	const char *name;
	int len;

	name = fdt_getprop(fdt, offset, property, &len);
	if (!name) {
		WARN("No %s is found\n", property);
		return 0;
	} else {
		return (uint64_t)strtol(name, NULL, base);
	}
}
#endif

static int thunder_fdt_get(const void *fdt, int offset, const char *property, int base)
{
	const char *name;
	int len;

	name = fdt_getprop(fdt, offset, property, &len);
	if (!name) {
		WARN("No %s is found\n", property);
		return -1;
	} else {
		return (int)strtol(name, NULL, base);
	}

}

#if PLAT_t93
/**
 * octeontx_parse_rvu_cgx - fill cgx_info_t structure of rvu_config
 * @fdt: pointer to the device tree blob
 * @parentoffset: offset to parent node (ecam0)
 *
 * returns:
 * 	On success, sum of number of VFs per given PHY node, -1 otherwise
 */
static int octeontx_parse_rvu_cgx(const void *fdt, int parentoffset)
{
	int cgx_id, lmac_id, cgx_offset, numvfs = 0, lmac_offset, len;
	const int *val;
	cgx_config_t *cgx;
	char cgx_name[16];

	for (cgx_id = 0; cgx_id < MAX_CGX; cgx_id++) {
		cgx = &bfdt.cgx_cfg[cgx_id];
		/* Construct cgx node name */
		snprintf(cgx_name, sizeof(cgx_name), "cgx%d", cgx_id);
		cgx_offset = fdt_subnode_offset(fdt, parentoffset, cgx_name);
		if (cgx_offset < 0) {
			/*
			 * Could not find given cgx node, disable
			 * CGX and all LMACs
			 */
			cgx->enable = 0;
			for (lmac_id = 0; lmac_id < MAX_LMAC_PER_CGX; lmac_id++)
				cgx->lmac_cfg[lmac_id].enable = 0;
			continue;
		}

		INFO("RVU: %s node found, parsing LMACs..\n", cgx_name);
		cgx->enable = 1;

		/*
		 * BDK already trimmed redundant FDT nodes and left here
		 * at most 4 subnodes.
		 */
		lmac_id = 0;
		fdt_for_each_subnode(lmac_offset, fdt, cgx_offset) {
			/* Get number of VFs from FDT for given LMAC */
			val = fdt_getprop(fdt, lmac_offset, "num-rvu-vfs", &len);
			if (!val) {
				/* If there's no such property in FDT,
				 * set it to default value DEFAULT_VFS */
				WARN("RVU: No num-rvu-vfs, using %d number of\n"
				     "              VFs for subnode %d under %s\n",
				     DEFAULT_VFS, lmac_id, cgx_name);
				cgx->lmac_cfg[lmac_id].num_rvu_vfs = DEFAULT_VFS;
			} else {
				cgx->lmac_cfg[lmac_id].num_rvu_vfs = fdt32_to_cpu(*val);
			}

			/* Get number of MSIX */
			val = fdt_getprop(fdt, lmac_offset,
					      "num-msix-vec", &len);
			if (!val) {
				/* If there's no such property in FDT,
				 * set it to default value DEFAULT_VFS */
				WARN("RVU: No num-msix-vec, using %d number of\n"
				     "              MSIX for subnode %d under %s\n",
				     DEFAULT_MSIX, lmac_id, cgx_name);
				cgx->lmac_cfg[lmac_id].num_msix_vec = DEFAULT_MSIX;
			} else {
				cgx->lmac_cfg[lmac_id].num_msix_vec = fdt32_to_cpu(*val);
			}

			/* Increment number of assigned VFs */
			numvfs += cgx->lmac_cfg[lmac_id].num_rvu_vfs;

			/* Enable LMAC */
			cgx->lmac_cfg[lmac_id].enable = 1;
			lmac_id++;
		}

		/* Now, disable all other LMACs */
		for (; lmac_id < MAX_LMAC_PER_CGX; lmac_id++) {
			cgx->lmac_cfg[lmac_id].enable = 0;
		}

	}

	return numvfs;
}

/**
 * octeontx_parse_rvu_admin - fill rvu_admin_pf_t structure of rvu_config
 * @fdt: pointer to the device tree blob
 * @parentoffset: offset to parent node (ecam2)
 * @node: node name
 *
 * returns:
 * 	On success, number of VFs from DTB on *name node, -1 otherwise
 */
static int octeontx_parse_rvu_admin(void *fdt, int parentoffset,
				    const char *name)
{
	int offset, len;
	const int *val;

	/* Find offset of *name node */
	offset = fdt_subnode_offset(fdt, parentoffset, name);
	if (offset < 0) {
		WARN("RVU: No %s node in FDT\n", name);
		return -1;
	}

	/* Get number of VFs from FDT */
	val = fdt_getprop(fdt, offset, "num-rvu-vfs", &len);
	if (!val) {
		/* If there's no such property in FDT,
		 * set it to default value DEFAULT_AF_PF0_VFS */
		WARN("RVU: No num-rvu-vfs, using %d number of VFs\n"
		     "              for node %s\n",
		     DEFAULT_AF_PF0_VFS, name);
		bfdt.rvu_config.admin_pf.num_rvu_vfs = DEFAULT_AF_PF0_VFS;
	} else {
		bfdt.rvu_config.admin_pf.num_rvu_vfs = fdt32_to_cpu(*val);
	}

	/* Get number of MSIX */
	val = fdt_getprop(fdt, offset, "num-msix-vec", &len);
	if (!val) {
		WARN("RVU: No num-msix-vec, using %d number of MSIX\n"
		     "              for node: %s\n", DEFAULT_MSIX_AF, name);
		bfdt.rvu_config.admin_pf.num_msix_vec = DEFAULT_MSIX_AF;
	} else {
		bfdt.rvu_config.admin_pf.num_msix_vec = fdt32_to_cpu(*val);
	}

	/* Trim (replace with FDT_NOP tags) proper node from FDT */
	//TODO: Uncomment it, causes hang on ASIM.
/*	*val = fdt_del_node(fdt, offset);
	if (*val < 0) {
		ERROR("RVU: Unable to remove node %s from DTB", name);
		return -1;
	}*/

	return bfdt.rvu_config.admin_pf.num_rvu_vfs;
}

/**
 * octeontx_parse_sw_rvu - fill rvu_sw_pf_t structure of rvu_config
 * @fdt: pointer to the device tree blob
 * @parentoffset: offset to parent node (ecam2)
 * @node: node name
 * @sw_rvu_pf: index enumerated by sw_rvu_pfs
 *
 * returns:
 * 	On success, number of VFs from DTB on *name node, -1 otherwise
 */
static int octeontx_parse_sw_rvu(void *fdt, int parentoffset,
				 const char *name, int sw_rvu_pf)
{
	int offset, len;
	const int *val;

	assert(sw_rvu_pf > 0 || sw_rvu_pf < SW_RVU_MAX_PF);

	/* Find offset of *name node */
	offset = fdt_subnode_offset(fdt, parentoffset, name);
	if (offset < 0) {
		WARN("RVU: No %s node in FDT\n", name);
		return -1;
	}

	/* Get number of VFs from FDT */
	val = fdt_getprop(fdt, offset, "num-rvu-vfs", &len);
	if (!val) {
		WARN("RVU: No num-rvu-vfs, using %d number of VFs\n"
		     "              for node %s\n", DEFAULT_VFS, name);
		bfdt.rvu_config.sw_pf[sw_rvu_pf].num_rvu_vfs = DEFAULT_VFS;
	} else {
		bfdt.rvu_config.sw_pf[sw_rvu_pf].num_rvu_vfs = fdt32_to_cpu(*val);
	}

	/* Get number of MSIX */
	val = fdt_getprop(fdt, offset, "num-msix-vec", &len);
	if (!val) {
		WARN("RVU: No num-msix-vec, using %d number of MSIX\n"
		     "              for node: %s\n", DEFAULT_MSIX, name);
		bfdt.rvu_config.sw_pf[sw_rvu_pf].num_msix_vec = DEFAULT_MSIX;
	} else {
		bfdt.rvu_config.sw_pf[sw_rvu_pf].num_msix_vec = fdt32_to_cpu(*val);
	}

	/* Trim (replace with FDT_NOP tags) proper node from FDT */
	//TODO: Uncomment it, causes hang on ASIM.
/*	*val = fdt_del_node(fdt, offset);
	if (val < 0) {
		ERROR("RVU: Unable to remove node %s from DTB", name);
		return -1;
	}*/

	/* On success, return number of VFs */
	return bfdt.rvu_config.sw_pf[sw_rvu_pf].num_rvu_vfs;
}

static int octeontx_parse_rvu_config(void)
{
	void *fdt = fdt_ptr;
	int offset, rc, soc_offset, fdt_vfs;
	char node_name[32];

	/* Initial setup */
	fdt_vfs = 0;
	soc_offset = offset = fdt_path_offset(fdt, "/soc@0");
	if (soc_offset < 0) {
		ERROR("RVU: Unable to find soc@0 node\n");
		return -1;
	}

	/* Parse all subnodes of ECAM0, Domain2 */
	snprintf(node_name, sizeof(node_name), "pci@%llx",
		(CSR_PA(0, CAVM_ECAM_PF_BAR2(0)) | (2 << 28)));
	offset = fdt_subnode_offset(fdt, soc_offset, node_name);
	if (offset < 0) {
		ERROR("RVU: Unable to find ecam2 node: %s\n", node_name);
		return -1;
	}

	/* Fill rvu_admin_pf_t structure */
	rc = octeontx_parse_rvu_admin(fdt, offset, "rvu-admin@0");
	if (rc < 0) {
		WARN("RVU: Unable to fill PF0-ADMIN structure\n");
		return -1;
	} else {
		/* Add number of VFs to fdt_vfs */
		fdt_vfs += rc;
	}

	/* Fill rvu_sw_rvu_pf_t structure, start with SSO_TIM (PF13) */
	rc = octeontx_parse_sw_rvu(fdt, offset, "rvu-sso-tim@0",
				   SW_RVU_SSO_TIM_PF);
	if (rc < 0) {
		WARN("RVU: Unable to fill PF13-SSO_TIM structure\n");
		return -1;
	} else {
		/* Add number of VFs to fdt_vfs */
		fdt_vfs += rc;
	}

	/* Now parse NPA (PF14) */
	rc = octeontx_parse_sw_rvu(fdt, offset, "rvu-npa@0", SW_RVU_NPA_PF);
	if (rc < 0) {
		WARN("RVU: Unable to fill PF14-NPA structure\n");
		return -1;
	} else {
		/* Add number of VFs to fdt_vfs */
		fdt_vfs += rc;
	}

	/* Finally, parse CPT (PF15) */
	rc = octeontx_parse_sw_rvu(fdt, offset, "rvu-cpt@0", SW_RVU_CPT_PF);
	if (rc < 0) {
		WARN("RVU: Unable to fill PF15-CPT structure\n");
		return -1;
	} else {
		/* Add number of VFs to fdt_vfs */
		fdt_vfs += rc;
	}

	/* Look for mrml_bridge node */
	offset = fdt_node_offset_by_compatible(fdt, soc_offset, "pci-bridge");
	if (offset < 0) {
		ERROR("RVU: Unable to find mrml_bridge node\n");
		return -1;
	}

	/* Fill cgx_info_t structure */
	rc = octeontx_parse_rvu_cgx(fdt, offset);
	if (rc < 0) {
		WARN("RVU: Unable to fill CGX config properly\n");
		return -1;
	} else {
		fdt_vfs += rc;
	}

	/* Check if number of requested VFs (via DTB) does not exceed number
	 * of Hardware VFs */
	if (fdt_vfs > RVU_HWVFS) {
		ERROR("RVU: Wrong FDT config. Tried to configure more\n"
		       "             VFs (%d) than HWVFs (%d). Please edit\n"
		       "             FDT and reflash the board\n", fdt_vfs,
		       RVU_HWVFS);
		return -1;
	}

	return 0;
}
#endif /* PLAT_t93 */

int thunder_fill_board_details(int info)
{
	const void *fdt = fdt_ptr;
	const char *name;
	int offset, len, config;

	if (fdt_check_header(fdt)) {
		printf("WARNING: Invalid device tree\n");
		return -1;
	}

	offset = fdt_path_offset(fdt, "/cavium,bdk");
	if (offset < 0) {
		printf("WARNING: FDT node not found\n");
		return offset;
	}

	name = fdt_getprop(fdt, offset, "BOARD-MODEL", &len);
	if (!name) {
		printf("WARNING: No BOARD-MODEL is found\n");
		bfdt.board_model[0] = '\0';
	} else {
		strncpy(bfdt.board_model, name, sizeof(bfdt.board_model));
		/* Terminate, in case strlen(name) > sizeof(board_model) */
		bfdt.board_model[sizeof(bfdt.board_model) - 1] = '\0';
		len = strlen(bfdt.board_model);
		for (int i = 0; i < len; i++)
			bfdt.board_model[i] = tolower(bfdt.board_model[i]);
	}

	config = thunder_fdt_get(fdt, offset, "BMC-BOOT-TWSI-CONFIG", 0);
	if (config != -1) {
		bfdt.bmc_boot_twsi_node = (config >> 16) & 0xff;
		bfdt.bmc_boot_twsi_bus = (config >> 8) & 0xff;
		bfdt.bmc_boot_twsi_addr = config & 0xff;
	} else {
		bfdt.bmc_boot_twsi_node = 0;
		bfdt.bmc_boot_twsi_bus = thunder_fdt_get(fdt, offset, "BMC-BOOT-TWSI-BUS", 10);
		bfdt.bmc_boot_twsi_addr = thunder_fdt_get(fdt, offset, "BMC-BOOT-TWSI-ADDR", 16);
	}
	config = thunder_fdt_get(fdt, offset, "BMC-IPMI-TWSI-CONFIG", 0);
	if (config != -1) {
		bfdt.bmc_ipmi_twsi_node = (config >> 16) & 0xff;
		bfdt.bmc_ipmi_twsi_bus = (config >> 8) & 0xff;
		bfdt.bmc_ipmi_twsi_addr = config & 0xff;
	} else {
		bfdt.bmc_ipmi_twsi_node = 0;
		bfdt.bmc_ipmi_twsi_bus = thunder_fdt_get(fdt, offset, "BMC-IPMI-TWSI-BUS", 10);
		bfdt.bmc_ipmi_twsi_addr = thunder_fdt_get(fdt, offset, "BMC-IPMI-TWSI-ADDR", 16);
	}

	bfdt.gpio_shutdown_ctl_in = thunder_fdt_get(fdt, offset, "GPIO-SHUTDOWN-CTL-IN", 0);
	/* The new format is hex and allows for node id and polarity
	 * packed into the value. We don't use them right now and mask
	 * them out. */
	if (bfdt.gpio_shutdown_ctl_in != -1)
		bfdt.gpio_shutdown_ctl_in &= 0xff;

	bfdt.gpio_shutdown_ctl_out = thunder_fdt_get(fdt, offset, "GPIO-SHUTDOWN-CTL-OUT", 0);
	/* The new format is hex and allows for node id and polarity
	 * packed into the value. We don't use them right now and mask
	 * them out. */
	if (bfdt.gpio_shutdown_ctl_out != -1)
		bfdt.gpio_shutdown_ctl_out &= 0xff;

#if TRUSTED_BOARD_BOOT
	/*
	 * Configuration for Trusted Board Boot received from BDK.
	 * For more information, please refer to bdk-trusted-boot.pdf file
	 * in BDK source repository.
	 */
	bfdt.trust_rot_addr = thunder_fdt_get_uint64(fdt, offset, "TRUST-ROT-ADDR", 16);

	/*
	 * If either thunder_fdt_get_uint64 returned -1 (property not found) or
	 * 0 (property found, but set to 0 indicates non-secure boot), stop secure booting
	 */
	if (bfdt.trust_rot_addr == 0 || bfdt.trust_rot_addr == -1) {
		printf("ERROR: No TRUST-ROT-ADDR in DTS, trusted boot failed\n");
		return -1;
	}

#if CRYPTO_BOARD_BOOT
	/*
	 * TRUST-BSSK-ADDR is set only when HUK parameter was passed to build system.
	 * If so, it contains the address of BSSK key. Firstly, try to get BSSK
	 */
	bfdt.trust_key_addr = thunder_fdt_get_uint64(fdt, offset, "TRUST-BSSK-ADDR", 16);

	/*
	 * If either thunder_fdt_get_uint64 returned -1 (property not found) or
	 * 0 (property found, but set to 0 indicates SSK), print info about it
	 */
	if (bfdt.trust_key_addr == 0 || bfdt.trust_rot_addr == -1) {
		printf("INFO: No TRUST-BSSK-ADDR in DTS, images will be decrypted\n"
		       "      with SSK key from FUSF_SSKX(0..1).\n");
		bfdt.trust_key_addr = 0;
	}
#endif /* CRYPTO_BOARD_BOOT */

#endif /* TRUSTED_BOARD_BOOT */

#if PLAT_t93
	config = octeontx_parse_rvu_config();
	if (config < 0) {
		printf("RVU: Invalid FDT configuration. Reflash firmware\n"
		       "     built with DEBUG=1 flag for more information\n");
		bfdt.rvu_config.valid = 0;
	} else {
		bfdt.rvu_config.valid = 1;
	}
#endif
	if (info)
		print_board_variables();

	return 0;
}
