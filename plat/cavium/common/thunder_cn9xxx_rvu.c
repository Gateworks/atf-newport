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

/* Total 40MB of memory is reserved for mailbox and msix table.
 * First 34 MB is for mailbox(32 PFs + 512 VFs * 64KB mailbox
 * size). 64KB for PFs msix table(32 PFs * 128(MSIX entries)*entry
 * size). 1MB for VFs msix table(512 VFs * 128 * MSIX entry size).
 * 93xx has 13 PFs and 256 VFs whereas 99xx has 32 PFs and 512 VFs.
 */

#define PF_MBOX_BASE	0x000000000
#define PF_MBOX_SIZE	0x000200000
#define VF_MBOX_BASE	(PF_MBOX_SIZE + PF_MBOX_SIZE)
#define VF_MBOX_SIZE	0x002000000
#define PF_MSIX_BASE	(VF_MBOX_BASE + VF_MBOX_SIZE)
#define VF_MSIX_OFFSET	0x10000

#define FALSE	0
#define TRUE	1

struct rvu_device {
	int enable;
	int num_vfs;
	int first_hwvf;
	int pf_res_ena; /* Enable npa/nix to PF */
	int vf_res_ena; /* Enable npa/nix to VFs */
};

//TODO: Instead of allocating this structure, make one instance
//	and fill it based on the FDT.
static struct rvu_device rvu_dev[] = {
	{TRUE, 8, 0, FALSE, FALSE},
	{TRUE, 8, 8, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{TRUE, 0, 0, TRUE, FALSE},
	{FALSE, 0, 0, FALSE, FALSE},
	{FALSE, 0, 0, FALSE, FALSE},
	{FALSE, 0, 0, FALSE, FALSE},
};

/* returns max PFs supported by RVU */
int get_max_rvu_pfs(void)
{
	union cavm_rvu_priv_const priv_const;

	priv_const.u = CSR_READ_PA(0, CAVM_RVU_PRIV_CONST);

	return priv_const.s.pfs;
}

/* set mailbox memory*/
void mailbox_enable(void)
{
	int pf;
	static uint64_t vf_base = VF_MBOX_BASE;
	union cavm_rvu_af_pf_bar4_addr pf_bar4_addr;

	pf_bar4_addr.u = 0;
	pf_bar4_addr.s.addr = PF_MBOX_BASE;
	CSR_WRITE_PA(0, CAVM_RVU_AF_PF_BAR4_ADDR, pf_bar4_addr.u);

	for (pf = 0; pf < get_max_rvu_pfs(); pf++) {
		if (rvu_dev[pf].enable && rvu_dev[pf].num_vfs) {
			uint64_t bar4_addr = CSR_PA(0, CAVM_RVU_PFX_VFX_BAR2(pf, 0)) + 0x10;
			cavm_write64(bar4_addr, vf_base);
			vf_base = vf_base + (0x10000 * (rvu_dev[pf].num_vfs & 0x7f));
		}
	}
}

void msix_enable(void)
{
	uint32_t vf_msix_offset = VF_MSIX_OFFSET;
	int pf;

	/* set AF MSIX table base*/
	union cavm_rvu_af_msixtr_base af_msix_cfg;

	af_msix_cfg.u = 0;
	af_msix_cfg.s.addr = PF_MSIX_BASE;
	CSR_WRITE_PA(0, CAVM_RVU_AF_MSIXTR_BASE, af_msix_cfg.u);

	/* set PF/VF msix table size and offset */
	for (pf = 0; pf < get_max_rvu_pfs(); pf++) {
		if (rvu_dev[pf].enable) {
			union cavm_rvu_priv_pfx_msix_cfg pfx_msix_cfg;

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
void map_lf_to_vf(int pf, int vf, int npalf_id, int nixlf_id)
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
void enable_rvu_pf(int pf)
{
	union cavm_rvu_priv_pfx_cfg pf_cfg;

	pf_cfg.u = 0;
	pf_cfg.s.af_ena = (pf == 0) ? 1 : 0;
	pf_cfg.s.ena = 1;
	pf_cfg.s.nvf = rvu_dev[pf].num_vfs;
	pf_cfg.s.first_hwvf = rvu_dev[pf].first_hwvf;
	CSR_WRITE_PA(0, CAVM_RVU_PRIV_PFX_CFG(pf), pf_cfg.u);
}

void disable_rvu_pf(int pf)
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
void pf_enable_npa(int pf, int lf_id)
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
void pf_enable_nix(int pf, int lf_id)
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
void hwvf_enable_npa_nix(int hwvf)
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
void reset_rvu_pf(int pf)
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

	for (pf = 0 ; pf < get_max_rvu_pfs(); pf++) {
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

}
