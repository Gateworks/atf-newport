/** @file

  Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#include <stdio.h>
#include <arch.h>
#include <platform_def.h>
#include <thunder_private.h>
#include <thunder_common.h>
#include <platform.h>
#include <assert.h>
#include <thunder_dt.h>

/*
 * Total 40MB of memory is reserved for mailbox and msix table.
 * First 34 MB is for mailbox(32 PFs + 512 VFs * 64KB mailbox
 * size). 64KB for PFs msix table(32 PFs * 128(MSIX entries)*entry
 * size). 1MB for VFs msix table(512 VFs * 128 * MSIX entry size).
 * 93xx has 16 PFs and 256 VFs whereas 99xx has 32 PFs and 512 VFs.
 */

#define PF_MBOX_BASE	0x000000000
#define PF_MBOX_SIZE	0x000200000
#define VF_MBOX_BASE	(PF_MBOX_SIZE + PF_MBOX_SIZE)
#define VF_MBOX_SIZE	0x002000000
#define PF_MSIX_BASE	(VF_MBOX_BASE + VF_MBOX_SIZE)
#define VF_MSIX_OFFSET	0x10000

#define DEVID_MASK	0xff
#define CLASS_CODE_MASK	0xffffff
#define RVU_CLASS_CODE	0x20000

#define MAX_RVU_PFS	16

#define SSO_TIM_TO_NPA_PFS_FACTOR	3/4

#define FALSE	0
#define TRUE	1

typedef struct pci_config {
	int pf_devid;
	int vf_devid;
	int class_code;
} pci_config_t;

struct rvu_device {
	int enable;
	int num_vfs;
	int first_hwvf;
	int pf_num_msix_vec;
	int pf_res_ena; /* Enable npa/nix to PF */
	int vf_res_ena; /* Enable npa/nix to VFs */
	pci_config_t pci; /* PCI configuration */
};

typedef enum {
	RVU_AF,
	RVU_CGX0_LMAC0,
	RVU_CGX0_LMAC1,
	RVU_CGX0_LMAC2,
	RVU_CGX0_LMAC3,
	RVU_CGX1_LMAC0,
	RVU_CGX1_LMAC1,
	RVU_CGX1_LMAC2,
	RVU_CGX1_LMAC3,
	RVU_CGX2_LMAC0,
	RVU_CGX2_LMAC1,
	RVU_CGX2_LMAC2,
	RVU_CGX2_LMAC3,
	RVU_SSO_TIM,
	RVU_NPA,
	RVU_CPT
} rvu_device;

static struct rvu_device rvu_dev[MAX_RVU_PFS];

static void octeontx_init_rvu_af(int *hwvf)
{
	rvu_dev[RVU_AF].enable = TRUE;
	rvu_dev[RVU_AF].num_vfs = bfdt.rvu_config.admin_pf.num_rvu_vfs;
	rvu_dev[RVU_AF].first_hwvf = *hwvf; /* Start with 0 */
	rvu_dev[RVU_AF].pf_num_msix_vec = bfdt.rvu_config.admin_pf.num_msix_vec;
	rvu_dev[RVU_AF].pf_res_ena = FALSE;
	rvu_dev[RVU_AF].vf_res_ena = FALSE;
	rvu_dev[RVU_AF].pci.pf_devid = CAVM_PCC_DEV_IDL_E_RVU_AF & DEVID_MASK;
	rvu_dev[RVU_AF].pci.vf_devid = CAVM_PCC_DEV_IDL_E_RVU_VF & DEVID_MASK;
	rvu_dev[RVU_AF].pci.class_code = RVU_CLASS_CODE & CLASS_CODE_MASK;
	/* Increment already allocated HWVFs */
	*hwvf += rvu_dev[RVU_AF].num_vfs;
}

static void octeontx_init_rvu_fixed(int *hwvf, int rvu, int bfdt_index, int has_vfs)
{
	rvu_sw_rvu_pf_t *sw_pf;

	assert(bfdt_index < SW_RVU_MAX_PF);
	sw_pf = &bfdt.rvu_config.sw_pf[bfdt_index];

	rvu_dev[rvu].enable = TRUE;
	rvu_dev[rvu].num_vfs = has_vfs ? sw_pf->num_rvu_vfs : 0;
	rvu_dev[rvu].first_hwvf = has_vfs ? *hwvf : 0;
	rvu_dev[rvu].pf_num_msix_vec = sw_pf->num_msix_vec;
	rvu_dev[rvu].pf_res_ena = FALSE;
	rvu_dev[rvu].vf_res_ena = FALSE;
	switch (bfdt_index) {
	case SW_RVU_SSO_TIM_PF:
		rvu_dev[rvu].pci.pf_devid =
			CAVM_PCC_DEV_IDL_E_SW_RVU_SSO_TIM_PF & DEVID_MASK;
		rvu_dev[rvu].pci.vf_devid =
			CAVM_PCC_DEV_IDL_E_SW_RVU_SSO_TIM_VF & DEVID_MASK;
		rvu_dev[rvu].pci.class_code = RVU_CLASS_CODE & CLASS_CODE_MASK;
		break;
	case SW_RVU_NPA_PF:
		rvu_dev[rvu].pci.pf_devid =
			CAVM_PCC_DEV_IDL_E_SW_RVU_NPA_PF & DEVID_MASK;
		rvu_dev[rvu].pci.vf_devid =
			CAVM_PCC_DEV_IDL_E_SW_RVU_NPA_VF & DEVID_MASK;
		rvu_dev[rvu].pci.class_code = RVU_CLASS_CODE & CLASS_CODE_MASK;
		break;
	case SW_RVU_CPT_PF:
		rvu_dev[rvu].pci.pf_devid =
			CAVM_PCC_DEV_IDL_E_SW_RVU_CPT_PF & DEVID_MASK;
		rvu_dev[rvu].pci.vf_devid =
			CAVM_PCC_DEV_IDL_E_SW_RVU_CPT_VF & DEVID_MASK;
		rvu_dev[rvu].pci.class_code = RVU_CLASS_CODE & CLASS_CODE_MASK;
		break;
	}
	/* Increment already allocated HWVFs */
	*hwvf += rvu_dev[rvu].num_vfs;
}

static void octeontx_init_rvu_lmac(int *hwvf, int rvu, cgx_info_t *cgx,
				   int lmac_id)
{
	rvu_dev[rvu].enable = TRUE;
	rvu_dev[rvu].num_vfs = cgx->lmac_cfg[lmac_id].num_rvu_vfs;
	rvu_dev[rvu].first_hwvf = *hwvf;
	rvu_dev[rvu].pf_num_msix_vec = cgx->lmac_cfg[lmac_id].num_msix_vec;
	rvu_dev[rvu].pf_res_ena = TRUE;
	rvu_dev[rvu].vf_res_ena = FALSE;
	rvu_dev[rvu].pci.pf_devid = CAVM_PCC_DEV_IDL_E_RVU & DEVID_MASK;
	rvu_dev[rvu].pci.vf_devid = CAVM_PCC_DEV_IDL_E_RVU_VF & DEVID_MASK;
	rvu_dev[rvu].pci.class_code = RVU_CLASS_CODE & CLASS_CODE_MASK;
	/* Increment already allocated HWVFs */
	*hwvf += rvu_dev[rvu].num_vfs;
}

static void octeontx_init_rvu_from_fdt(void)
{
	int cgx_id, lmac_id, pf, uninit_pfs, sso_tim_pfs, npa_pfs, current_hwvf = 0;
	cgx_info_t *cgx;

	/* Firstly, initialize fixed setup (PF0, PF13, PF14, PF15) */
	/* Init RVU0 - AF (PF0) */
	octeontx_init_rvu_af(&current_hwvf);

	/* Init RVU13 - SSO_TIM (PF13) */
	octeontx_init_rvu_fixed(&current_hwvf, RVU_SSO_TIM,
				SW_RVU_SSO_TIM_PF, TRUE);

	/* Init RVU14 - NPA (PF14) */
	octeontx_init_rvu_fixed(&current_hwvf, RVU_NPA,
				SW_RVU_NPA_PF, TRUE);

	/* Init RVU15 - CPT (PF15) */
	octeontx_init_rvu_fixed(&current_hwvf, RVU_CPT,
				SW_RVU_CPT_PF, TRUE);

	/* Initialize CGX PF */
	pf = RVU_CGX0_LMAC0;
	uninit_pfs = 0;
	for (cgx_id = 0; cgx_id < MAX_CGX; cgx_id++) {
		cgx = &bfdt.rvu_config.cgx_pf[cgx_id];
		if (cgx->enable) {
			for (lmac_id = 0; lmac_id < MAX_LMAC_PER_CGX; lmac_id++) {
				if (cgx->lmac_cfg[lmac_id].enable) {
					octeontx_init_rvu_lmac(&current_hwvf,
							       pf, cgx,
							       lmac_id);
					assert(current_hwvf < RVU_HWVFS);
					pf++;
				} else {
					/* Increment number of not
					 * configured PFs yet */
					uninit_pfs++;
				}
			}
		} else {
			/* all four LMACs are not initialized */
			uninit_pfs += MAX_LMAC_PER_CGX;
		}
	}

	/*
	 * For all unitialized PFs, divide them by factor and configure:
	 * FACTOR*uninit_pf's as SSO_TIM PF
	 * All left PFs (uninit_pfs - FACTOR*uninit_pfs) as NPA PF
	 * FACTOR, as discussed with ODP developers, is set to 3/4.
	 */
	if (!uninit_pfs)
		return;

	sso_tim_pfs = uninit_pfs * SSO_TIM_TO_NPA_PFS_FACTOR;
	npa_pfs = uninit_pfs - sso_tim_pfs;
	while (sso_tim_pfs > 0) {
		octeontx_init_rvu_fixed(&current_hwvf, pf++,
					SW_RVU_SSO_TIM_PF, FALSE);
		sso_tim_pfs--;
	}

	while (npa_pfs > 0) {
		octeontx_init_rvu_fixed(&current_hwvf, pf++,
					SW_RVU_NPA_PF, FALSE);
		npa_pfs--;
	}
}

/* returns max PFs supported by RVU */
static int octeontx_get_max_rvu_pfs(void)
{
	union cavm_rvu_priv_const priv_const;

	priv_const.u = CSR_READ_PA(0, CAVM_RVU_PRIV_CONST);

	return priv_const.s.pfs;
}

/* set mailbox memory*/
static void mailbox_enable(void)
{
	int pf;
	static uint64_t vf_base = VF_MBOX_BASE;
	union cavm_rvu_af_pf_bar4_addr pf_bar4_addr;

	pf_bar4_addr.u = 0;
	pf_bar4_addr.s.addr = PF_MBOX_BASE;
	CSR_WRITE_PA(0, CAVM_RVU_AF_PF_BAR4_ADDR, pf_bar4_addr.u);

	for (pf = 0; pf < octeontx_get_max_rvu_pfs(); pf++) {
		if (rvu_dev[pf].enable && rvu_dev[pf].num_vfs) {
			uint64_t bar4_addr = CSR_PA(0, CAVM_RVU_PFX_VFX_BAR2(pf, 0)) + 0x10;
			cavm_write64(bar4_addr, vf_base);
			vf_base = vf_base + (0x10000 * (rvu_dev[pf].num_vfs & 0x7f));
		}
	}
}

/* Initialize PCI PF_DEVID and VF_DEVID */
static void config_rvu_pci(void)
{
	cavm_rvu_priv_pfx_id_cfg_t pf_id_cfg;
	int pf;

	for (pf = 0; pf < octeontx_get_max_rvu_pfs(); pf++) {
		pf_id_cfg.u = 0;
		pf_id_cfg.s.class_code = rvu_dev[pf].pci.class_code;
		pf_id_cfg.s.pf_devid = rvu_dev[pf].pci.pf_devid;
		pf_id_cfg.s.vf_devid = rvu_dev[pf].pci.vf_devid;

		CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_ID_CFG(pf), pf_id_cfg.u);
	}
}

static void msix_enable(void)
{
	uint32_t vf_msix_offset = VF_MSIX_OFFSET;
	int pf;

	/* set AF MSIX table base*/
	union cavm_rvu_af_msixtr_base af_msix_cfg;

	af_msix_cfg.u = 0;
	af_msix_cfg.s.addr = PF_MSIX_BASE;
	CSR_WRITE_PA(0, CAVM_RVU_AF_MSIXTR_BASE, af_msix_cfg.u);

	/* set PF/VF msix table size and offset */
	for (pf = 0; pf < octeontx_get_max_rvu_pfs(); pf++) {
		if (rvu_dev[pf].enable) {
			union cavm_rvu_priv_pfx_msix_cfg pfx_msix_cfg;
			//TODO: Get info from rvu_dev structure instead of hardcoded values.
			//Validation is needed here.

			pfx_msix_cfg.u = 0;
			pfx_msix_cfg.s.pf_msixt_offset = (0x800 * (pf & 0xf));
			pfx_msix_cfg.s.pf_msixt_sizem1 = 0x7f;
			if (rvu_dev[pf].num_vfs) {
				pfx_msix_cfg.s.vf_msixt_offset = vf_msix_offset;
				pfx_msix_cfg.s.vf_msixt_sizem1 = 0x7f;
				vf_msix_offset = (vf_msix_offset + (rvu_dev[pf].num_vfs & 0x7f) * 0x800);
			}
			CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_MSIX_CFG(pf), pfx_msix_cfg.u);
		}
	}
}

/* Map NPA/NIX LF to rvu VFs */
static inline void map_lf_to_vf(int pf, int vf, int npalf_id, int nixlf_id)
{
	union cavm_nixx_priv_lfx_cfg nix_lf_cfg;
	union cavm_npa_priv_lfx_cfg npa_lf_cfg;

	nix_lf_cfg.u = npa_lf_cfg.u = 0;
	nix_lf_cfg.s.ena = npa_lf_cfg.s.ena = 1;
	nix_lf_cfg.s.pf_func = npa_lf_cfg.s.pf_func = (((pf & 0x3f) << 10)
					| ((vf + 1) & 0x3ff));
	nix_lf_cfg.s.slot = npa_lf_cfg.s.slot = 0;
	CSR_WRITE_PA(0, CAVM_NPA_PRIV_LFX_CFG(npalf_id), npa_lf_cfg.u);
	CSR_WRITE_PA(0, CAVM_NIXX_PRIV_LFX_CFG(0, nixlf_id), nix_lf_cfg.u);
}

/* set total VFs and HWVFs for PFs */
static void enable_rvu_pf(int pf)
{
	union cavm_rvu_priv_pfx_cfg pf_cfg;

	pf_cfg.u = 0;
	pf_cfg.s.af_ena = (pf == RVU_AF || pf == RVU_CPT) ? TRUE : FALSE;
	pf_cfg.s.ena = TRUE;
	pf_cfg.s.nvf = rvu_dev[pf].num_vfs;
	pf_cfg.s.first_hwvf = rvu_dev[pf].first_hwvf;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_CFG(pf), pf_cfg.u);
}

static void disable_rvu_pf(int pf)
{
	union cavm_rvu_priv_pfx_cfg pf_cfg;

	pf_cfg.u = 0;
	pf_cfg.s.af_ena = 0;
	pf_cfg.s.ena = 0;
	pf_cfg.s.nvf = 0;
	pf_cfg.s.first_hwvf = 0;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_CFG(pf), pf_cfg.u);

}
/* Enable NPA for PF*/
static void pf_enable_npa(int pf, int lf_id)
{
	union cavm_rvu_priv_pfx_npa_cfg pf_npa_cfg;
	union cavm_npa_priv_lfx_cfg npa_lf_cfg;

	pf_npa_cfg.u = 0;
	pf_npa_cfg.s.has_lf = 1;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_NPA_CFG(pf), pf_npa_cfg.u);

	npa_lf_cfg.u = 0;
	npa_lf_cfg.s.ena = 1;
	npa_lf_cfg.s.pf_func = (((pf & 0x3f) << 10) | 0x0);
	npa_lf_cfg.s.slot = 0;
	CSR_WRITE_PA(0, CAVM_NPA_PRIV_LFX_CFG(lf_id), npa_lf_cfg.u);
}

/* Enable NIX for PF*/
static void pf_enable_nix(int pf, int lf_id)
{
	union cavm_rvu_priv_pfx_nixx_cfg pf_nix_cfg;
	union cavm_nixx_priv_lfx_cfg nix_lf_cfg;

	pf_nix_cfg.u = 0;
	pf_nix_cfg.s.has_lf = 1;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_NIXX_CFG(pf, 0), pf_nix_cfg.u);

	nix_lf_cfg.u = 0;
	nix_lf_cfg.s.ena = 1;
	nix_lf_cfg.s.pf_func = (((pf & 0x3f) << 10) | 0x0);
	nix_lf_cfg.s.slot = 0;
	CSR_WRITE_PA(0, CAVM_NIXX_PRIV_LFX_CFG(0, lf_id), nix_lf_cfg.u);
}

/* Enable NIX and NPA for hwvf/VFs */
static void hwvf_enable_npa_nix(int hwvf)
{
	union cavm_rvu_priv_hwvfx_npa_cfg  hwvf_npa_cfg;
	union cavm_rvu_priv_hwvfx_nixx_cfg hwvf_nix_cfg;

	hwvf_npa_cfg.u = 0;
	hwvf_npa_cfg.s.has_lf = 1;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_HWVFX_NPA_CFG(hwvf), hwvf_npa_cfg.u);

	hwvf_nix_cfg.u = 0;
	hwvf_nix_cfg.s.has_lf = 1;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_HWVFX_NIXX_CFG(hwvf, 0), hwvf_nix_cfg.u);
}

/* Reset all the resources before enabling PF */
static void reset_rvu_pf(int pf)
{
	union cavm_rvu_priv_pfx_cptx_cfg cpt_cfg;
	union cavm_rvu_priv_pfx_int_cfg int_cfg;
	union cavm_rvu_priv_pfx_msix_cfg msix_cfg;
	union cavm_rvu_priv_pfx_nixx_cfg nix_cfg;
	union cavm_rvu_priv_pfx_npa_cfg npa_cfg;
	union cavm_rvu_priv_pfx_sso_cfg sso_cfg;
	union cavm_rvu_priv_pfx_ssow_cfg ssow_cfg;
	union cavm_rvu_priv_pfx_tim_cfg tim_cfg;

	cpt_cfg.u = 0;
	cpt_cfg.s.num_lfs = 0;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_CPTX_CFG(pf, 0), cpt_cfg.u);

	int_cfg.u = 0;
	int_cfg.s.msix_offset = 0;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_INT_CFG(pf), int_cfg.u);

	msix_cfg.u = 0;
	msix_cfg.s.pf_msixt_offset = 0;
	msix_cfg.s.pf_msixt_sizem1 = 0;
	msix_cfg.s.vf_msixt_offset = 0;
	msix_cfg.s.vf_msixt_sizem1 = 0;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_MSIX_CFG(pf), msix_cfg.u);

	nix_cfg.u = 0;
	nix_cfg.s.has_lf = 0;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_NIXX_CFG(pf, 0), nix_cfg.u);

	npa_cfg.u = 0;
	npa_cfg.s.has_lf = 0;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_NPA_CFG(pf), npa_cfg.u);

	sso_cfg.u = 0;
	sso_cfg.s.num_lfs = 0;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_SSO_CFG(pf), sso_cfg.u);

	ssow_cfg.u = 0;
	ssow_cfg.s.num_lfs = 0;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_SSOW_CFG(pf), ssow_cfg.u);

	tim_cfg.u = 0;
	tim_cfg.s.num_lfs = 0;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_TIM_CFG(pf), tim_cfg.u);
}

void octeontx_rvu_init(void)
{
	int pf, hwvf, vf;
	int npalf_id = 0, nixlf_id = 0;

	octeontx_init_rvu_from_fdt();

	for (pf = 0 ; pf < octeontx_get_max_rvu_pfs(); pf++) {
		if (rvu_dev[pf].enable) {
			reset_rvu_pf(pf);
			enable_rvu_pf(pf);
			if (rvu_dev[pf].pf_res_ena) {
				pf_enable_nix(pf, nixlf_id);
				nixlf_id++;
				pf_enable_npa(pf, npalf_id);
				npalf_id++;
			}

			if (rvu_dev[pf].vf_res_ena) {
				hwvf = rvu_dev[pf].first_hwvf;
				for (vf = 0; vf < rvu_dev[pf].num_vfs; vf++) {
					hwvf_enable_npa_nix(hwvf);
					map_lf_to_vf(pf, vf, npalf_id, nixlf_id);
					nixlf_id++;
					npalf_id++;
					hwvf++;
				}
			}
		}
		else 	/* Disable unused PFs */
			disable_rvu_pf(pf);
	}

	msix_enable();
	mailbox_enable();
	config_rvu_pci();
}
