/** @file
#
#  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#**/

#include <platform_def.h>
#include <cavm_common.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <libfdt.h>
#include <cavm_dt.h>
#include <cavm_ecam.h>
#include <cavm_utils.h>
#include <cavm_octeontx_scfg.h>
#include <cavm_irqs_def.h>

#ifdef DEBUG_ATF_PLAT_ECAM
#define debug_plat_ecam printf
#else
#define debug_plat_ecam(...) ((void) (0))
#endif

/* Probe for disabling TWSI busses from PCI scan */
static int ecam_probe_twsi(unsigned long arg)
{
	return (plat_octeontx_bcfg->bcfg.bmc_boot_twsi_bus != arg);
}

/* Probe RST_CTLX for PEM usability. */
static int ecam_probe_pem(unsigned long arg)
{
	union cavm_rst_soft_prstx soft_prst;

	soft_prst.u = CSR_READ(CAVM_RST_SOFT_PRSTX(arg));

	return soft_prst.s.soft_prst == 0;
}

/* Probe GSERX_CFG[SATA] for SATA usability. arg is the GSER number. */
static int ecam_probe_sata(unsigned long arg)
{
	union cavm_gserx_cfg cfg;

	cfg.u = CSR_READ(CAVM_GSERX_CFG(arg / 2 + 4));

	return cfg.s.sata != 0;
}

/* Probe GSERX_CFG[BGX] for BGX usability. arg is the GSER number. */
static int ecam_probe_bgx(unsigned long arg)
{
	union cavm_gserx_cfg cfg_dlm0;
	union cavm_gserx_cfg cfg_dlm1;

	cfg_dlm1.u = 0;

	/*
	 * On 83xx BGX is split across 2 DLMs, check both DLMs
	 * for marking BGX PCi device secure 
	 */
	switch (arg) {
	case 0:
		cfg_dlm0.u = CSR_READ(CAVM_GSERX_CFG(2));
		break;
	case 1:
		cfg_dlm0.u = CSR_READ(CAVM_GSERX_CFG(3));
		break;
	case 2:
		cfg_dlm0.u = CSR_READ(CAVM_GSERX_CFG(5));
		cfg_dlm1.u = CSR_READ(CAVM_GSERX_CFG(6));
		break;
	case 3:
		cfg_dlm0.u = CSR_READ(CAVM_GSERX_CFG(4));
		break;
	default:
		cfg_dlm0.u = 0;
	}

	return (cfg_dlm0.s.bgx || cfg_dlm1.s.bgx);
}

/* arg is LMC number */
static int ecam_probe_lmc(unsigned long arg)
{
	return plat_octeontx_scfg->scfg.is_lmc_enabled[arg];
}

struct ecam_probe_callback probe_callbacks[] = {
	{0xa012, 0x177d, ecam_probe_twsi, 0},
	{0xa020, 0x177d, ecam_probe_pem, 0},
	{0xa01c, 0x177d, ecam_probe_sata, 0},
	{0xa026, 0x177d, ecam_probe_bgx, 0},
	{0xa022, 0x177d, ecam_probe_lmc, 0},
	{ECAM_INVALID_DEV_ID, 0, 0, 0}
};

static void init_gpio(uint64_t config_base, uint64_t config_size)
{
	union cavm_pccpf_xxx_vsec_sctl vsec_sctl;
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint64_t vector_base;
	int i, vector_skip;
	uint16_t table_size = 0;
	uint8_t cap_ptr = pconfig->cap_pointer;
	uint8_t bir = 0;

	/*
	 * Check if we are intercepting interrupts of GPIO in ATF.
	 * This is for a feature where ATF will intercept certain GPIO
	 * interrupts and call a user space handler. It is done for low latency
	 * interrupt handling requirement in the user space.
	 *
	 * Do not continue if not intercepting.
	 */
	if (!plat_octeontx_bcfg->gpio_intercept_intr)
		return;

	debug_plat_ecam("GPIO init called config_base:%lx size:%lx\n",
			config_base, config_size);

	/* Mark the MSI-X interrupts as physical */
	vsec_sctl.u = octeontx_read32(config_base + CAVM_PCCPF_XXX_VSEC_SCTL);
	vsec_sctl.s.msix_phys = 1;
	octeontx_write32(config_base + CAVM_PCCPF_XXX_VSEC_SCTL, vsec_sctl.u);

	enable_msix(config_base, cap_ptr, &table_size, &bir);

	if (table_size) {
		debug_plat_ecam("table_size: %x, bir:%1x\n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		debug_plat_ecam("MSI-X vector base:%lx\n", vector_base);

		/* Skip the multicast interrupt vectors */
		vector_skip = CAVM_GPIO_INT_VEC_E_INTR_PINX_CN83XX(0);
		vector_base += vector_skip * 0x10;

		for (i = vector_skip; i < table_size; i++) {
			/* enable SECVEC (bit0) for each MSI-X vectors*/
			octeontx_write64(vector_base, ((i % 2) ?
						CAVM_GICD_CLRSPI_NSR :
						CAVM_GICD_SETSPI_NSR) | 1);
			vector_base += 8;
			octeontx_write64(vector_base, GPIO_SPI_IRQ_NSEC(0));
			vector_base += 8;
		}
	}
}

/*
 * Callback for platform specific block initialization
 */
struct ecam_init_callback plat_init_callbacks[] = {
	{0xa00a, 0x177d, init_gpio},
	{ECAM_INVALID_DEV_ID, 0, 0}
};

struct secure_devices secure_devs[] = {
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_SMMU},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GIC},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GTI},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_L2C},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_SGP},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_DAP},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_MIO_FUS},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_FUSF},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_NCSI},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_KEY},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_MIO_BOOT},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_UAA},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_PEM},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_IOBN},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GSER},
/*	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_SLIRE}, */
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_VRM},
	{CAVM_PCC_PROD_E_CN83XX, CAVM_PCC_DEV_IDL_E_PCIERC},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_NDF},
	{ECAM_INVALID_PROD_ID, ECAM_INVALID_PCC_IDL_ID}
};

static inline uint64_t cn83xx_get_dev_config(struct ecam_device *dev)
{
	uint64_t pconfig;
	cavm_pccpf_xxx_id_t pccpf_id;

	pconfig = (dev->base_addr |
		  ((dev->bus << ECAM_BUS_SHIFT) & ECAM_BUS_MASK) |
		  ((dev->dev << ECAM_DEV_SHIFT) & ECAM_DEV_MASK) |
		  ((dev->func << ECAM_FUNC_SHIFT) & ECAM_FUNC_MASK));

	pccpf_id.u = octeontx_read32(pconfig + CAVM_PCCPF_XXX_ID);
	if (pccpf_id.s.vendid == 0xffff || pccpf_id.s.devid == 0xffff)
		return 0;

	return pconfig;
}

static int cn83xx_is_bus_disabled(struct ecam_device *dev)
{
	int rc = 0;

	if (((dev->ecam == 0) && (dev->bus > 11)) ||
	    ((dev->ecam == 1) && (dev->bus > 5)))
		rc = 1;

	return rc;
}

static inline int cn83xx_skip_bus(struct ecam_device *dev)
{
	return (((dev->ecam == 1) && (dev->bus > 0)) || (dev->bus > 1));
}

static inline void cn83xx_disable_bus(struct ecam_device *dev)
{
	cavm_ecamx_busx_sdis_t bus_sdis;

	/* disable bus */
	bus_sdis.u = CSR_READ(CAVM_ECAMX_BUSX_SDIS(dev->ecam, dev->bus));
	bus_sdis.s.sec = 1;
	CSR_WRITE(CAVM_ECAMX_BUSX_SDIS(dev->ecam, dev->bus), bus_sdis.u);
	debug_plat_ecam("disable_bus %d:%d\n", dev->ecam,
			dev->bus);
}

static inline void cn83xx_enable_bus(struct ecam_device *dev)
{
	cavm_ecamx_busx_sdis_t bus_sdis;
	cavm_ecamx_busx_nsdis_t bus_nsdis;

	/* enable bus */
	bus_sdis.u = CSR_READ(CAVM_ECAMX_BUSX_SDIS(dev->ecam, dev->bus));
	bus_sdis.s.sec = 0;
	bus_sdis.s.dis = 0;
	CSR_WRITE(CAVM_ECAMX_BUSX_SDIS(dev->ecam, dev->bus), bus_sdis.u);

	bus_nsdis.u = CSR_READ(CAVM_ECAMX_BUSX_NSDIS(dev->ecam, dev->bus));
	bus_nsdis.s.dis = 0;
	CSR_WRITE(CAVM_ECAMX_BUSX_NSDIS(dev->ecam, dev->bus), bus_nsdis.u);

	debug_plat_ecam("enable_bus %d:%d\n", dev->ecam, dev->bus);
}

static inline void cn83xx_disable_dev(struct ecam_device *dev)
{
	cavm_ecamx_devx_sdis_t dev_sdis;

	/* disable device */
	dev_sdis.u = CSR_READ(CAVM_ECAMX_DEVX_SDIS(dev->ecam, dev->dev));
	dev_sdis.s.sec = 1;
	CSR_WRITE(CAVM_ECAMX_DEVX_SDIS(dev->ecam, dev->dev), dev_sdis.u);
	debug_plat_ecam("disable_dev %d:%d:%02x\n", dev->ecam, dev->dev);
}

static inline void cn83xx_enable_dev(struct ecam_device *dev)
{
	cavm_ecamx_devx_sdis_t dev_sdis;
	cavm_ecamx_devx_nsdis_t dev_nsdis;

	/* enable device */
	dev_sdis.u = CSR_READ(CAVM_ECAMX_DEVX_SDIS(dev->ecam, dev->dev));
	dev_sdis.s.sec = 0;
	dev_sdis.s.dis = 0;
	CSR_WRITE(CAVM_ECAMX_DEVX_SDIS(dev->ecam, dev->dev), dev_sdis.u);

	dev_nsdis.u = CSR_READ(CAVM_ECAMX_DEVX_NSDIS(dev->ecam, dev->dev));
	dev_nsdis.s.dis = 0;
	CSR_WRITE(CAVM_ECAMX_DEVX_NSDIS(dev->ecam, dev->dev), dev_nsdis.u);

	debug_plat_ecam("enable_dev %d:%02x\n", dev->ecam, dev->dev);
}

static inline void cn83xx_disable_func(struct ecam_device *dev)
{
	cavm_ecamx_rslx_sdis_t rsl_sdis;

	/* disable function */
	rsl_sdis.u = CSR_READ(CAVM_ECAMX_RSLX_SDIS(dev->ecam, dev->func));
	rsl_sdis.s.sec = 1;
	CSR_WRITE(CAVM_ECAMX_RSLX_SDIS(dev->ecam, dev->func), rsl_sdis.u);
	debug_plat_ecam("disable_func %d:%02x\n", dev->ecam, dev->func);
}

static inline void cn83xx_enable_func(struct ecam_device *dev)
{
	cavm_ecamx_rslx_sdis_t rsl_sdis;
	cavm_ecamx_rslx_nsdis_t rsl_nsdis;

	/* enable function */
	rsl_sdis.u = CSR_READ(CAVM_ECAMX_RSLX_SDIS(dev->ecam, dev->func));
	rsl_sdis.s.sec = 0;
	rsl_sdis.s.dis = 0;
	CSR_WRITE(CAVM_ECAMX_RSLX_SDIS(dev->ecam, dev->func), rsl_sdis.u);

	rsl_nsdis.u = CSR_READ(CAVM_ECAMX_RSLX_NSDIS(dev->ecam, dev->func));
	rsl_nsdis.s.dis = 0;
	CSR_WRITE(CAVM_ECAMX_RSLX_NSDIS(dev->ecam, dev->func), rsl_nsdis.u);

	debug_plat_ecam("enable_func %d:%02x\n", dev->ecam, dev->func);
}

static inline int cn83xx_get_ecam_count()
{
	cavm_ecamx_const_t ecam_const;

	ecam_const.u = CSR_READ(CAVM_ECAMX_CONST(0));

	return ecam_const.s.ecams;
}

static int cn83xx_get_domain_count(struct ecam_device *dev)
{
	/*
	 * In CN83xx ECAM topology, there're no domains.
	 * To satisfy PCI scan, at least 1 domain needs to be present
	 */
	return 1;
}

static inline int cn83xx_is_domain_present(struct ecam_device *dev)
{
	/*
	 * To satisfy proper PCI scan,
	 * at least 1 domain needs to be present
	 */
	return (dev->domain == 0);
}

static int cn83xx_get_secure_settings(struct ecam_device *dev, uint64_t pconfig)
{
	cavm_pccpf_xxx_id_t pccpf_id;
	int i = 0;

	/* Get secure/non-secure setting */
	pccpf_id.u = octeontx_read32(pconfig + CAVM_PCCPF_XXX_ID);
	debug_plat_ecam("%s: DeviceID=0x%04x\n", __func__, pccpf_id.s.devid);

	dev->config.s.is_secure = 0;
	while (secure_devs[i].devid != ECAM_INVALID_PCC_IDL_ID) {
		if (((secure_devs[i].prodid << ECAM_PROD_SHIFT) |
			secure_devs[i].devid) == pccpf_id.s.devid)
			dev->config.s.is_secure = 1;
		i++;
	}

	/* Set SCP/MCP to 0, as they don't exist on T83 */
	dev->config.s.is_mcp_secure = 0;
	dev->config.s.is_scp_secure = 0;

	return 1;
}

struct ecam_probe_callback *cn83xx_get_probe_callbacks(void)
{
	return &probe_callbacks[0];
}

struct ecam_init_callback *cn83xx_get_init_callbacks(void)
{
	return &plat_init_callbacks[0];
}

const struct ecam_platform_defs plat_ops = {
	.soc_type = T83PARTNUM,
	.get_ecam_count = cn83xx_get_ecam_count,
	.get_domain_count = cn83xx_get_domain_count,
	.is_domain_present = cn83xx_is_domain_present,
	.get_secure_settings = cn83xx_get_secure_settings,
	.get_dev_config = cn83xx_get_dev_config,
	.get_probes = cn83xx_get_probe_callbacks,
	.get_plat_inits = cn83xx_get_init_callbacks,
	.is_bus_disabled = cn83xx_is_bus_disabled,
	.skip_bus = cn83xx_skip_bus,
	.enable_bus = cn83xx_enable_bus,
	.disable_bus = cn83xx_disable_bus,
	.enable_dev = cn83xx_enable_dev,
	.disable_dev = cn83xx_disable_dev,
	.enable_func = cn83xx_enable_func,
	.disable_func = cn83xx_disable_func
};
