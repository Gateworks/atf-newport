/*
 * Copyright (C) 2017-2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#ifndef __RVU_H_
#define __RVU_H_

/*
 * Total 40MB of memory is reserved for mailbox, msix table
 * and firwmare data
 *   - 34MB is for mailbox(32 PFs + 512 VFs * 64KB mailbox size)
 *   - 128KB for PFs msix table(32 PFs * 256(MSIX entries) * entry * size).
 *   - 1MB for VFs msix table(512 VFs * 128 * MSIX entry size).
 *   - fwdata @ offset 38M
 * 96xx has 16 PFs and 256 VFs whereas 98xx has 32 PFs and 512 VFs.
 */
#define PF_MBOX_BASE		RVU_MEM_BASE
#define PF_MBOX_SIZE		0x000200000
#define VF_MBOX_BASE		(PF_MBOX_BASE + PF_MBOX_SIZE)
#define VF_MBOX_SIZE		0x002000000
#define PF_MSIX_BASE		(VF_MBOX_BASE + VF_MBOX_SIZE)
#define VF_MSIX_BASE_IDX_NUMBER	0x2000
/* The last 2M reserved for shared firmware data */
#define SH_FWDATA_OFFSET	0x2600000
#define SH_FWDATA_BASE		(RVU_MEM_BASE + SH_FWDATA_OFFSET)
#define SH_FWDATA_SIZE		0x200000
#define RVU_MEM_END		(RVU_MEM_SIZE + RVU_MEM_BASE)

/*
 * According to errata RVU-36163 in RVU_PRIV_PF()_MSIX_CFG fields
 * PF_MSIXT_OFFSET and VF_MSIXT_OFFSET has to be aligned to multiple of 64.
 */
#define RVU_36163_OFFSET_ALIGNMENT	(1 << 6)
#define RVU_36163_ALIGNMENT_MASK    (RVU_36163_OFFSET_ALIGNMENT - 1)

#define DEVID_MASK	0xff
#define CLASS_CODE_MASK	0xffffff
#define RVU_CLASS_CODE	0x020000
#define CPT_CLASS_CODE	0x108000
/* It is Generic System Peripheral with subclass System peripheral */
#define GSP_CLASS_CODE	0x088000

#define MAX_RVU_PFS			16
#define MAX_RVU_VFS_PER_PF		128
#define SSO_TIM_TO_NPA_PFS_FACTOR	3/4
#define RVU_MSIX_VEC_SIZE 		16

/* Number of AF interrupts consumed by PF0 */
#define RVU_AF_INT_VEC_E_MSIX_SIZE	5

/* Number of MSI-X per VF */
#define RVU_VF_INT_VEC_COUNT			1

/* Bit 0 is MBOX in RVU_PF_INT register */
#define RVU_PF_INT_SET_MBOX		1

/* Bit 0 is MBOX in RVU_VF_INT register */
#define RVU_VF_INT_SET_MBOX		1

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
	int vf_num_msix_vec;
	int pf_res_ena; /* Enable npa/nix to PF */
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
	RVU_PF15,	/* It is not fixed, can be changed via fuses */
} rvu_device;


int octeontx2_clear_lf_to_pf_mapping();
void octeontx_rvu_init();

#endif
