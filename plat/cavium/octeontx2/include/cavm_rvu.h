/** @file

  Copyright (c) 2017-2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _CAVM_RVU_H_
#define _CAVM_RVU_H_

/*
 * Total 40MB of memory is reserved for mailbox and msix table.
 * First 34 MB is for mailbox(32 PFs + 512 VFs * 64KB mailbox
 * size). 128KB for PFs msix table(32 PFs * 256(MSIX entries)*entry
 * size). 1MB for VFs msix table(512 VFs * 128 * MSIX entry size).
 * 93xx has 16 PFs and 256 VFs whereas 99xx has 32 PFs and 512 VFs.
 */
#define PF_MBOX_BASE	RVU_MEM_BASE
#define PF_MBOX_SIZE	0x000200000
#define VF_MBOX_BASE	(PF_MBOX_BASE + PF_MBOX_SIZE)
#define VF_MBOX_SIZE	0x002000000
#define PF_MSIX_BASE	(VF_MBOX_BASE + VF_MBOX_SIZE)
#define VF_MSIX_OFFSET	0x20000

#define DEVID_MASK	0xff
#define CLASS_CODE_MASK	0xffffff
#define RVU_CLASS_CODE	0x020000
#define CPT_CLASS_CODE	0x108000

#define MAX_RVU_PFS			16
#define MAX_RVU_VFS_PER_PF		128
#define SSO_TIM_TO_NPA_PFS_FACTOR	3/4
#define RVU_MSIX_VEC_SIZE 		16
#define RVU_DEFAULT_MSIX_VEC_PER_VF	128

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

#endif
