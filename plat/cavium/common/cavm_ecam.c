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
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <cavm_private.h>
#include <cavm_common.h>
#include <cavm_dt.h>
#include <cavm_ecam.h>

#undef DEBUG_ATF_ECAM

#ifdef DEBUG_ATF_ECAM
#define debug_io printf
#else
#define debug_io(x,...);
#endif

/*
 * Platform methods defined in thunder_ecam_cnXXxx.c file
 */
extern const struct ecam_platform_defs plat_ops;

static struct ecam_device ecam_bridges[OCTEONTX_ECAM_MAX_DEV];

/*
 * Global ecam_device instance
 */
static struct ecam_device ecam_dev;

static uint64_t get_bar_val(struct pcie_config *pconfig, int bar)
{
	uint32_t cap;
	int cap_offset = pconfig->cap_pointer & 0xfc;
	uint64_t h, l, ret = 0;

	do {
		cap = cavm_read32((uint8_t *) pconfig + cap_offset);
		if ((cap & 0xff) == 0x14)
			break;
		cap_offset = (cap >> 8) & 0xfc;
	} while (cap_offset);
	if (cap_offset) {
		/* Found EA */
		int es, bei;
		int ne = (cap >> 16) & 0x3f;

		cap_offset += 4;
		while (ne) {
			uint32_t dw0 = cavm_read32((uint8_t *) pconfig + cap_offset + 0);

			es = dw0 & 7;
			bei = (dw0 >> 4) & 0xf;
			if (bei == bar) {
				h = 0;
				l = cavm_read32((uint8_t *) pconfig + cap_offset + 4);
				if (l & 2)
					h = cavm_read32((uint8_t *) pconfig + cap_offset + 12);
				ret = (h << 32) | (l & ~0xfull);
				break;
			}
			cap_offset += (es + 1) * 4;
			ne--;
		}

	} else {
		h = 0;
		l = pconfig->baseaddress_reg[bar];
		if (l & 4)
			h = pconfig->baseaddress_reg[bar + 1];
		ret = (h << 32) | (l & ~0xfull);
	}
	return ret;
}

#ifdef DEBUG_ATF_IO
static void print_config_space(struct pcie_config *pconfig)
{
	int i;
	debug_io("************pcie config(%x:%x)***************\n",
		 pconfig->devid, pconfig->vendor_id);

	debug_io(" class_code\t\t::%6x\n", pconfig->class_code);
	debug_io(" header_type\t\t::%2x\n", (uint8_t) pconfig->header_type);
	for (i = 0; i < 6; i++)
		debug_io(" baseaddress_reg[%d]\t::%x\n", i,
			 pconfig->baseaddress_reg[i]);
	debug_io(" sub_system_vendor_id\t::%4x\n",
		 pconfig->sub_system_vendor_id);
	debug_io(" sub_system_id\t\t::%4x\n", pconfig->sub_system_id);
	debug_io(" cap_pointer\t\t::%2x\n", pconfig->cap_pointer);
	debug_io(" intterrupt_line\t::%2x\n", pconfig->intterrupt_line);
	debug_io(" intterrupt_pin\t\t::%2x\n", pconfig->intterrupt_pin);

	debug_io("**********************************************\n");
}
#else
static inline void print_config_space(struct pcie_config *pconfig)
{
}
#endif

static int enable_msix(uint64_t config_base, uint8_t cap_pointer, uint16_t * table_size,
		       uint8_t * bir)
{
	struct msix_cap *msicap;
	/* enable MSI-X */
	while (1 && cap_pointer) {
		msicap = (struct msix_cap *)(config_base + cap_pointer);
		if (msicap->cap_ID == PCI_MSIX_CAP_ID) {
			msicap->messagecontrol |= (1 << 15);
			*table_size = (msicap->messagecontrol & 0x3ff) + 1;
			*bir = (msicap->table_offset_and_bir & 0x7);
			break;
		}
		cap_pointer = msicap->next_pointer;
	}
	return 0;

}

static inline int smmu_get_irq(int node, int smmunr, int vectornr)
{
	int irq =
	    (node * 8) + smmunr +
	    ((vectornr < (OCTEONTX_SMMU_NUM_CONTEXTS * 2)) ? 0 : 4);
	switch (irq) {
	case 0:
		return OCTEONTX_SMMU0_CONTEXT_IRQ;
	case 1:
		return OCTEONTX_SMMU1_CONTEXT_IRQ;
	case 2:
		return OCTEONTX_SMMU2_CONTEXT_IRQ;
	case 3:
		return OCTEONTX_SMMU3_CONTEXT_IRQ;
	case 4:
		return OCTEONTX_SMMU0_GLOBAL_IRQ;
	case 5:
		return OCTEONTX_SMMU1_GLOBAL_IRQ;
	case 6:
		return OCTEONTX_SMMU2_GLOBAL_IRQ;
	case 7:
		return OCTEONTX_SMMU3_GLOBAL_IRQ;
	case 8:
		return OCTEONTX_SMMU4_CONTEXT_IRQ;
	case 9:
		return OCTEONTX_SMMU5_CONTEXT_IRQ;
	case 10:
		return OCTEONTX_SMMU6_CONTEXT_IRQ;
	case 11:
		return OCTEONTX_SMMU7_CONTEXT_IRQ;
	case 12:
		return OCTEONTX_SMMU4_GLOBAL_IRQ;
	case 13:
		return OCTEONTX_SMMU5_GLOBAL_IRQ;
	case 14:
		return OCTEONTX_SMMU6_GLOBAL_IRQ;
	case 15:
		return OCTEONTX_SMMU7_GLOBAL_IRQ;

	}
	return -1;
}

static void init_smmu(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	int i;
	int smmunr = ((config_base >> 36) & 0xff) - 0x48;

	debug_io("SMMU(%d) NODE(%d) init called config_base:%lx size:%lx\n",
		 smmunr, node, config_base, config_size);
	print_config_space(pconfig);

	/* Allow all IO units to access only non secure memory 
	 * We can program secure devices later when they discovered.
	 *
	 */
	/* FIXME: Making devices non-secure from SMMU should be done differently */
	for (int i = 0; i < 2048; i++) {
		/* Only eMMC in SMMU0 is secure */
		/*if (i == 8 && smmunr == 0) {
			CSR_WRITE_PA((unsigned long)node,
				     CAVM_SMMUX_SSDRX(smmunr, i), 0xffffcfff);
			continue;
		}*/

		CSR_WRITE_PA((unsigned long)node, CAVM_SMMUX_SSDRX(smmunr, i),
			     0xffffffff);
	}

	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* evn though size and bir got from generic code
	 * this is hilghy specific to cn88xx pass 1.0
	 * */
	if (1 && table_size) {
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			cavm_write64(vector_base, (i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR);
			vector_base += 8;
			cavm_write64(vector_base, smmu_get_irq(node, smmunr, i));
			vector_base += 8;
			//debug_io("SMMU(%d) : Vector:%d address :%lx irq:%d\n",smmunr, i, 
			//       ((i%2)? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR),smmu_get_irq(smmunr, i));
		}
	}
}

static void init_gpio(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	int i;
	uint32_t *sctl = (uint32_t *) (config_base + CAVM_PCCPF_XXX_VSEC_SCTL);
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);
	//int gpio_pin = GPIO_PWR_PIN;
	int gpio_pin = bfdt.gpio_shutdown_ctl_in;

	if (gpio_pin < 0)
		return;

	/* not intialising node1 gpio */
	if (node)
		return;

	debug_io("setting secure/phys @%p\n", (void *)sctl);
	*sctl |= 3;

	printf("GPIO(%d) Node(%d) init called config_base:%lx size:%lx\n",
	       vsec_ctl.s.inst_num, node, config_base, config_size);
	print_config_space(pconfig);
	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* evn though size and bir got from generic code
	 * this is highly specific to cn88xx pass 1.0
	 * */
	if (1 && table_size) {
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			if (i == (48 + (gpio_pin * 2))
			    || i == (49 + (gpio_pin * 2))) {
				cavm_write64(vector_base, ((i % 2) ? CAVM_GICD_CLRSPI_SR : CAVM_GICD_SETSPI_SR));	//enable SECVEC (bit 0)
				//*(uint64_t *)vector_base = ((i%2)? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR) ; 
				vector_base += 8;
				cavm_write64(vector_base, OCTEONTX_GPIO_PWR_S_IRQ);
				vector_base += 8;
				debug_io("GPIO(%d)-NODE(%d): Vector:%d address :%lx irq:%d\n",
				       vsec_ctl.s.inst_num, node, i,
				       (i % 2) ? CAVM_GICD_CLRSPI_SR : CAVM_GICD_SETSPI_SR,
				       OCTEONTX_GPIO_PWR_S_IRQ);
			} else {
				vector_base += 0x10;
			}
		}
	}

}

static inline int uaa_get_irq(int uaanr)
{
	switch (uaanr) {
	case 0:
		return OCTEONTX_UAA0_IRQ;
	case 1:
		return OCTEONTX_UAA1_IRQ;
	case 2:
		return OCTEONTX_UAA2_IRQ;
	case 3:
		return OCTEONTX_UAA3_IRQ;
	default:
		return -1;
	}
}

static void init_uaa(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	int i, uaa_irq;
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	union cavm_pccpf_xxx_cmd cmd;

	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);

	/* not intialising node1 uaa */
	if (node)
		return;

	uaa_irq = uaa_get_irq(vsec_ctl.s.inst_num);

	if (uaa_irq < 0)
		return;

	if ((cavm_read32(config_base + CAVM_PCCPF_XXX_SUBID)>>24) == 0xb2) {
		/* enable bus master for uaa, not like 8xxx always en */
		cmd.u = cavm_read32(config_base + CAVM_PCCPF_XXX_CMD);
		cmd.s.me = 1;
		cavm_write32(config_base + CAVM_PCCPF_XXX_CMD, cmd.u);
	}

	debug_io("UAA(%d) Node(%d) init called config_base:%lx size:%lx\n",
		 vsec_ctl.s.inst_num, node, config_base, config_size);
	print_config_space(pconfig);
	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* evn though size and bir got from generic code
	 * this is highly specific to cn88xx pass 1.0
	 * */
	if (1 && table_size) {
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			cavm_write64(vector_base, (i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR);
			vector_base += 8;
			printf("\r"); /* Need to revisit and remove this workaround */
			cavm_write64(vector_base, uaa_irq);
			vector_base += 8;
			debug_io("UAA(%d)-NODE(%d): Vector:%d address :%lx irq:%d\n",
				 vsec_ctl.s.inst_num, node, i,
				 ((i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR),
				 uaa_irq);
		}
	}
}

static void init_twsi(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	uint32_t devfn = (config_base >> 12) & 0xffUL;
	int i;
	uint32_t *sctl = (uint32_t *) (config_base + CAVM_PCCPF_XXX_VSEC_SCTL);
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;

	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);

	/* not intialising node1 twsi */
	if (node)
		return;

	debug_io("Using TWSI func = 0x%x\n", devfn);

	if ((devfn & 0x7) != bfdt.bmc_boot_twsi_bus)
		return;

	debug_io("setting secure/phys @%p\n", (void *)sctl);
	*sctl |= 3;
	printf("TWSI1(%d) Node(%d) init called config_base:%lx size:%lx\n",
	       vsec_ctl.s.inst_num, node, config_base, config_size);
	print_config_space(pconfig);
	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* even though size and bir got from generic code
	 * this is highly specific to cn88xx pass 1.0
	 */
	if (1 && table_size) {
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			cavm_write64(vector_base, (i % 2) ? CAVM_GICD_CLRSPI_SR : CAVM_GICD_SETSPI_SR);
			vector_base += 8;
			cavm_write64(vector_base, OCTEONTX_TWSI_1_S_IRQ);
			vector_base += 8;
			debug_io("TWSI1(%d)-NODE(%d): Vector:%d address :%lx irq:%d\n",
				 vsec_ctl.s.inst_num, node, i,
				 ((i % 2) ? CAVM_GICD_CLRSPI_SR : CAVM_GICD_SETSPI_SR),
				 OCTEONTX_TWSI_1_S_IRQ);

		}

	}
}

static void init_pem(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	int i;
	uint64_t msg;
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);

	debug_io("PEM(%d) Node(%d) init called config_base:%lx size:%lx\n",
		 vsec_ctl.s.inst_num, node, config_base, config_size);
	print_config_space(pconfig);
	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* evn though size and bir got from generic code
	 * this is highly specific to cn88xx pass 1.0
	 * */
	if (table_size) {
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			cavm_write64(vector_base, (i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR);
			vector_base += 8;
			if (i >= CAVM_PEM_INT_VEC_E_INTA && i < CAVM_PEM_INT_VEC_E_INT_SUM)
				msg = ((i - CAVM_PEM_INT_VEC_E_INTA) / 2) + OCTEONTX_PEM_INTBASE_IRQ +
					(24 * node) + (4 * vsec_ctl.s.inst_num);
			else
				msg = 0x100000000ull;	/* Masked */
			cavm_write64(vector_base, msg);
			vector_base += 8;
			debug_io
			    ("PEM(%d)-NODE(%d): Vector:%d address :%lx irq:%lu\n",
			     vsec_ctl.s.inst_num, node, i,
			     ((i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR),
			     msg);
		}
	}
}

static void init_gti(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	int i;
	uint8_t cap_pointer, bir = 0;
	uint16_t table_size = 0;
	uint64_t vector_base = 0, msg = 0;

	debug_io("GTI NODE(%d) init called config_base:%lx size:%lx\n", node,
		 config_base, config_size);
	cap_pointer = pconfig->cap_pointer;
	print_config_space(pconfig);

	enable_msix(config_base, cap_pointer, &table_size, &bir);

	/* initialise MSI-X Vector table */
	if (table_size) {
		vector_base = get_bar_val(pconfig, bir);
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);
	}

	/* configure interrupt vectors */
	for (i = 0; i < table_size; i++) {
		if (i < CAVM_GTI_INT_VEC_E_TX_TIMESTAMP)
			cavm_write64(vector_base, (i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR);
		else
			cavm_write64(vector_base, CAVM_GICD_SETSPI_NSR);
		vector_base += 8;
		if (i == CAVM_GTI_INT_VEC_E_WATCHDOG ||
		    i == CAVM_GTI_INT_VEC_E_WATCHDOG_CLEAR) {
			msg = OCTEONTX_GTI_WDOG_IRQ;
		} else {
			msg = 0x100000000ULL; /* Masked */
		}
		cavm_write64(vector_base, msg);
		vector_base += 8;
		debug_io
		    ("GTI NODE(%d): Vector:%d address :%lx irq:%lu\n",
		     node, i,
		     (i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR,
		     msg);
	}
}

static void init_iobn(int node, uint64_t config_base, uint64_t config_size)
{
	int iobn_nr;
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	union cavm_iobnx_dis_ncbi_io iobn_dis_ncbi;

	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);
	iobn_nr = vsec_ctl.s.inst_num;

	debug_io("IOBN(%d) NODE(%d) init called config_base:%lx size:%lx\n",
		vsec_ctl.s.inst_num, node, config_base, config_size);
	/*
	 * When booting in Trusted Mode the Boot ROM disables accesses originating
	 * from SLI by setting IOBN0_DIS_NCBI_IO.SLI_OFF=1. We unset the bit here.
	 * Ideally signed software has to clear this  bit if it wants to allow
	 * external PCIe devices to do DMA.
	 */
	if(iobn_nr == 0) {
		iobn_dis_ncbi.u = CSR_READ_PA(node, CAVM_IOBNX_DIS_NCBI_IO(iobn_nr));

		iobn_dis_ncbi.s.sli_off = 0;
		CSR_WRITE_PA(node, CAVM_IOBNX_DIS_NCBI_IO(iobn_nr), iobn_dis_ncbi.u);
	}
}

static void init_iobn5(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	int i, iobn_nr;
	int domain, bus, dev;
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	union cavm_ecamx_const ecamx_const;
	union cavm_ecamx_domx_const domx_const;

	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);
	iobn_nr = vsec_ctl.s.inst_num;

	debug_io("IOBN(%d) NODE(%d) init called config_base:%lx size:%lx\n",
		vsec_ctl.s.inst_num, node, config_base, config_size);

	print_config_space(pconfig);

	/*
	 * Allow all IO units to access non-secure memory.
	 * We can program secure devices later when they discovered.
	 */
	for (i = 0; i < 256; i++) {
		CSR_WRITE_PA(node, CAVM_IOBNX_RSLX_STREAMS(iobn_nr,i), 0x3);
	}

	ecamx_const.u = CSR_READ_PA(node, CAVM_ECAMX_CONST(0));

	for (domain = 0; domain < ecamx_const.s.domains; domain++) {
		/* Domains may not be contiguous */
		domx_const.u = CSR_READ_PA(node, CAVM_ECAMX_DOMX_CONST(0,domain));
		if (domx_const.s.pres) {
			for (bus = 0; bus < 256; bus++)
				CSR_WRITE_PA(node, CAVM_IOBNX_DOMX_BUSX_STREAMS(iobn_nr, domain, bus), 0x3);
			for (dev = 0; dev < 32; dev++)
				CSR_WRITE_PA(node, CAVM_IOBNX_DOMX_DEVX_STREAMS(iobn_nr, domain, dev), 0x3);
		}
	}
}

/*
 * This is the callback structure that holds callback for
 * different devices.
 */
struct ecam_init_callback init_callbacks[] = {
	{0xa008, 0x177d, init_smmu},
	{0xa00a, 0x177d, init_gpio},
	{0xa00f, 0x177d, init_uaa},
	{0xa012, 0x177d, init_twsi},
	{0xa017, 0x177d, init_gti},
	{0xa020, 0x177d, init_pem},
	{0xa027, 0x177d, init_iobn},
	{0xa06b, 0x177d, init_iobn5},
	{ECAM_INVALID_DEV_ID, 0, 0},	//no more callbacks
};

static inline int octeontx_bus_is_rsl(struct ecam_device *device)
{
	return (device->ecam == 0 && device->domain == 0 && device->bus == 1);
}

/*
 * Initialize ECAM device structure
 */
static void octeontx_ecam_dev_init(struct ecam_device *device, unsigned node,
				 unsigned ecam)
{
	device->base_addr = CSR_PA(node, CAVM_ECAM_PF_BAR2(ecam));
	device->node = node;
	device->ecam = ecam;
}

/*
 * Method to use probe_callbacks structure defined in
 * SoC-specific ECAM files to determine if given device should
 * be hidden from non-secure world.
 */
static int octeontx_call_probe(int node, uint64_t pconfig)
{
	cavm_pccpf_xxx_id_t pccpf_id;
	struct ecam_probe_callback *probe_callbacks;
	int rc, i = 0;

	probe_callbacks = plat_ops.get_probes();
	if (!probe_callbacks)
		return 1;

	pccpf_id.u = cavm_read32(pconfig + CAVM_PCCPF_XXX_ID);

	while (probe_callbacks[i].devid != ECAM_INVALID_DEV_ID) {
		if (probe_callbacks[i].devid == pccpf_id.s.devid
		    && probe_callbacks[i].vendor_id == pccpf_id.s.vendid) {
			debug_io("'calling io_probe ... %lx\n",
				 (uint64_t) probe_callbacks[i].io_probe);
			rc = probe_callbacks[i].io_probe(node,
					probe_callbacks[i].call_count);
			probe_callbacks[i].call_count++;
			return rc;
		}
		i++;
	}

	return 1;
}

/*
 * Method to initialize given device if matched in init_callbacks definition. 
 */
static void octeontx_call_init(int node, uint64_t pconfig)
{
	struct ecam_init_callback *plat_init_callbacks;
	cavm_pccpf_xxx_id_t pccpf_id;
	int i = 0;

	pccpf_id.u = cavm_read32(pconfig + CAVM_PCCPF_XXX_ID);

	while (init_callbacks[i].devid != ECAM_INVALID_DEV_ID) {
		if (init_callbacks[i].devid == pccpf_id.s.devid
		    && init_callbacks[i].vendor_id == pccpf_id.s.vendid) {
			debug_io("'calling io_init ... %lx\n",
				 (uint64_t) init_callbacks[i].io_init);
			init_callbacks[i].io_init(node, pconfig,
						  sizeof(struct pcie_config));
		}
		i++;
	}

	/* Look for plat_init_callbacks */
	plat_init_callbacks = plat_ops.get_plat_inits();
	if (!plat_init_callbacks)
		return;

	i = 0;
	while (plat_init_callbacks[i].devid != ECAM_INVALID_DEV_ID) {
		if (plat_init_callbacks[i].devid == pccpf_id.s.devid
		    && plat_init_callbacks[i].vendor_id == pccpf_id.s.vendid) {
			debug_io("'calling plat_io_init ... %lx\n",
				 (uint64_t) plat_init_callbacks[i].io_init);
			plat_init_callbacks[i].io_init(node, pconfig,
						sizeof(struct pcie_config));
		}
		i++;
	}
}

static unsigned prev_ns_func = 0;
static void octeontx_ari_capability(struct ecam_device *device)
{
	cavm_pccpf_xxx_vsec_ctl_t vsec_ctl;
	unsigned act_func;
	uint64_t pconfig;

	if (device->func == 0)
		prev_ns_func = 0;

	/* Store the actual function number */
	act_func = device->func;

	/* Read pconfig for previous, valid function */
	device->func = prev_ns_func;
	pconfig = plat_ops.get_dev_config(device);

	/* Program ARI capability properly */
	vsec_ctl.u = cavm_read32(pconfig + CAVM_PCCPF_XXX_VSEC_CTL);
	vsec_ctl.s.nxtfn_ns = act_func;
	cavm_write32(pconfig + CAVM_PCCPF_XXX_VSEC_CTL, vsec_ctl.u);

	/* Update prev_ns_func value */
	device->func = act_func;
	prev_ns_func = device->func;
}

static inline int octeontx_dev_is_bridge(uint64_t pconfig)
{
	cavm_pccpf_xxx_id_t pccpf_id;

	pccpf_id.u = cavm_read32(pconfig + CAVM_PCCPF_XXX_ID);
	if ((pccpf_id.s.devid & 0xff) == 0x02)
		return 1;

	return 0;
}

static void octeontx_ecam_dev_enumerate(struct ecam_device *device)
{
	uint64_t pconfig;
	int rc;

	/* Get address of the device */
	pconfig = plat_ops.get_dev_config(device);
	if (!pconfig) {
		debug_io("%s: Unable to get config\n", __func__);
		return;
	}

	/* Call platform-specific method for secure settings */
	rc = plat_ops.get_secure_settings(device, pconfig);
	if (!rc) {
		debug_io("%s: Unable to get secure settings\n", __func__);
		return;
	}

	/* Call probe function on device (if probe method exist) */
	rc = octeontx_call_probe(device->node, pconfig);
	if (!rc) {
		debug_io("%s: Probe returned with rc=%d\n", __func__, rc);
		if (octeontx_bus_is_rsl(device))
			plat_ops.disable_func(device);
		else
			plat_ops.disable_dev(device);
		return;
	}

	/* Call init function on device */
	octeontx_call_init(device->node, pconfig);

	debug_io("%s: N%u:E%u:DOM%u:B%u:D%u:FUN%u\n"
		 "pconfig: 0x%lx, secure:%u, scp:%u, mcp:%u\n",
		 __func__, device->node, device->ecam, device->domain,
		 device->bus, device->dev, device->func, pconfig,
		 device->config.s.is_secure, device->config.s.is_scp_secure,
		 device->config.s.is_mcp_secure);

	/* For RSL bus, configure secure settings for function,
	 * otherwise configure device */
	if (octeontx_bus_is_rsl(device)) {
		if (device->config.s.is_secure) {
			plat_ops.disable_func(device);
		} else {
			octeontx_ari_capability(device);
			plat_ops.enable_func(device);
		}
	} else {
		if (device->config.s.is_secure) {
			plat_ops.disable_dev(device);
		} else {
			plat_ops.enable_dev(device);
		}
	}

	debug_io("%s: pconfig: 0x%lx, value: 0x%x\n", __func__, pconfig,
		cavm_read32(pconfig));

	if (octeontx_dev_is_bridge(pconfig)) {
		cavm_pccbr_xxx_bus_t sbus;

		sbus.u = cavm_read32(pconfig + CAVM_PCCBR_XXX_BUS);
		if (sbus.s.sbnum != 0 &&
		    sbus.s.sbnum < OCTEONTX_ECAM_MAX_BUS) {
			/* Add to brigdes list */
			ecam_bridges[device->dev].bus = sbus.s.sbnum;
			debug_io("Adding bridge=%d to list...\n",
				  sbus.s.sbnum);
		}
	}
}

static void octeontx_rsl_enumerate(struct ecam_device *device)
{
	for (device->func = 0;
	     device->func < OCTEONTX_ECAM_MAX_FUNC;
	     device->func++) {
		device->dev = 0;
		octeontx_ecam_dev_enumerate(device);
	}
}

static void octeontx_dev_on_bus_enumerate(struct ecam_device *device)
{
	for (device->dev = 0;
	     device->dev < OCTEONTX_ECAM_MAX_DEV;
	     device->dev++) {
		device->func = 0;
		octeontx_ecam_dev_enumerate(device);
	}
}

static void octeontx_bus_enumerate(struct ecam_device *device)
{
	debug_io("%s: N%u:E%u:DOM%u:B%u\n",
		 __func__, device->node, device->ecam, device->domain,
		 device->bus);

	plat_ops.enable_bus(device);

	octeontx_dev_on_bus_enumerate(device);
}

static void octeontx_scan_bridge(struct ecam_device *device)
{
	int bridge;

	for (bridge = 0; bridge < OCTEONTX_ECAM_MAX_DEV; bridge++) {
		/* Disable buses that does not exist */
		if (plat_ops.is_bus_disabled(device)) {
			plat_ops.disable_bus(device);
			return;
		}
		/* We've got bus bridge */
		if (device->bus == ecam_bridges[bridge].bus) {
			plat_ops.enable_bus(device);
			if (plat_ops.skip_bus(device))
				return;

			if (octeontx_bus_is_rsl(device)) {
				octeontx_rsl_enumerate(device);
			} else {
				octeontx_dev_on_bus_enumerate(device);
			}

			ecam_bridges[bridge].bus = 0;
			continue;
		}
	}
}

static void octeontx_domain_setup(struct ecam_device *device)
{
	/* Scan bus 0 for all bridges */
	device->bus = 0;
	octeontx_bus_enumerate(device);

	/* Now go through all found bridges */
	for (device->bus = 1;
	     device->bus < OCTEONTX_ECAM_MAX_BUS;
	     device->bus++) {
		octeontx_scan_bridge(device);
	}
}

static void octeontx_ecam_setup(unsigned node, unsigned ecam)
{
	struct ecam_device *device = &ecam_dev;
	unsigned domain_count;

	octeontx_ecam_dev_init(device, node, ecam);
	domain_count = plat_ops.get_domain_count(device);

	for (device->domain = 0;
	     device->domain < domain_count;
	     device->domain++) {
		if (!plat_ops.is_domain_present(device))
			continue;
		octeontx_domain_setup(device);
	}
}

void octeontx_pci_init(void)
{
	unsigned node_count, ecam_count, node, ecam;

	node_count = thunder_get_node_count();
	for (node = 0; node < node_count; node++) {
		ecam_count = plat_ops.get_ecam_count(node);
		for (ecam = 0; ecam < ecam_count; ecam++)
			octeontx_ecam_setup(node, ecam);
	}
}
