/** @file
#
#  Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
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
#include <cavm_private.h>
#include <cavm_common.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <cavm_dt.h>
#include <cavm_ecam.h>

#ifdef DEBUG_ATF_PLAT_ECAM
#define debug_plat_ecam printf
#else
#define debug_plat_ecam(...) ((void) (0))
#endif

/* Probe for disabling TWSI busses from PCI scan */
static int ecam_probe_twsi(int node, unsigned long arg)
{
	return (bfdt.bmc_boot_twsi_bus != arg);
}

/* Probe RST_CTLX for PEM usability. */
static int ecam_probe_pem(int node, unsigned long arg)
{
	union cavm_rst_soft_prstx soft_prst;

	soft_prst.u = CSR_READ_PA(node, CAVM_RST_SOFT_PRSTX(arg));

	return soft_prst.s.soft_prst == 0;
}

/* Probe GSERX_CFG[SATA] for SATA usability. arg is the GSER number. */
static int ecam_probe_sata(int node, unsigned long arg)
{
	union cavm_gserx_cfg cfg;

	cfg.u = CSR_READ_PA(node, CAVM_GSERX_CFG(3));

	return cfg.s.sata != 0;
}

/* Probe GSERX_CFG[BGX] for BGX usability. arg is the GSER number. */
static int ecam_probe_bgx(int node, unsigned long arg)
{
	union cavm_gserx_cfg cfg_dlm0;
	union cavm_gserx_cfg cfg_dlm1;

	/*
	 * On 81xx BGX is split across 2 DLMs, check both DLMs
	 * for marking BGX PCi device secure 
	 */
	arg = arg ? 2 : 0;
	cfg_dlm0.u = CSR_READ_PA(node, CAVM_GSERX_CFG(arg));
	cfg_dlm1.u = CSR_READ_PA(node, CAVM_GSERX_CFG(arg + 1));

	return (cfg_dlm0.s.bgx || cfg_dlm1.s.bgx);
}

/*
 * Map probe methods to appropriate DEVID.
 */
struct ecam_probe_callback probe_callbacks[] = {
	{0xa012, 0x177d, ecam_probe_twsi, 0},
	{0xa020, 0x177d, ecam_probe_pem, 0},
	{0xa01c, 0x177d, ecam_probe_sata, 0},
	{0xa026, 0x177d, ecam_probe_bgx, 0},
	{ECAM_INVALID_DEV_ID, 0, 0, 0}
};

/*
 * Following device's BAR0 will be hidden
 * from non-secure world.
 */
struct secure_devices secure_devs[] = {
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_SMMU},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GIC},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GTI},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_L2C},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_SGP},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_DAP},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_MIO_FUS},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_FUSF},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_KEY},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_MIO_BOOT},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_UAA},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_PEM},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_IOBN},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_VRM},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_LBK},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GSER},
	{CAVM_PCC_PROD_E_CN81XX, CAVM_PCC_DEV_IDL_E_PCIERC},
	{ECAM_INVALID_PROD_ID, ECAM_INVALID_PCC_IDL_ID}
};

static inline uint64_t cn81xx_get_dev_config(struct ecam_device *dev)
{
	uint64_t pconfig;
	cavm_pccpf_xxx_id_t pccpf_id;

	pconfig = (dev->base_addr |
		  ((dev->bus << ECAM_BUS_SHIFT) & ECAM_BUS_MASK) |
		  ((dev->dev << ECAM_DEV_SHIFT) & ECAM_DEV_MASK) |
		  ((dev->func << ECAM_FUNC_SHIFT) & ECAM_FUNC_MASK));

	pccpf_id.u = cavm_read32(pconfig + CAVM_PCCPF_XXX_ID);
	if (pccpf_id.s.vendid == 0xffff || pccpf_id.s.devid == 0xffff)
		return 0;

	return pconfig;
}

/*
 * This method is a quirk for CN80xx to disable CPT block
 */
static int cn81xx_quirk_cn80xx(struct ecam_device *dev)
{
	int i;
	uint32_t fuse_cnt = 0;

	/* Check if CPT block is available by reading the fuse */
	if ((dev->ecam == 0) && (dev->domain == 0) && (dev->bus == 4)) {
		for (i = 1665; i <= 1680; i++) {
			fuse_cnt += thunder_fuse_read(dev->node, i);
		}

		if (fuse_cnt == 16)
			return 1;
	}

	return 0;
}

static int cn81xx_is_bus_disabled(struct ecam_device *dev)
{
	int rc = 0;

	rc = cn81xx_quirk_cn80xx(dev);
	if ((dev->ecam == 0) && (dev->bus > 5))
		rc = 1;

	return rc;
}

static inline int cn81xx_skip_bus(struct ecam_device *dev)
{
	return (dev->bus > 1);
}

static inline void cn81xx_disable_bus(struct ecam_device *dev)
{
	cavm_ecamx_busx_sdis_t bus_sdis;

	/* disable bus */
	bus_sdis.u = CSR_READ_PA(dev->node,
				 CAVM_ECAMX_BUSX_SDIS(dev->ecam, dev->bus));
	bus_sdis.s.sec = 1;
	CSR_WRITE_PA(dev->node,
		     CAVM_ECAMX_BUSX_SDIS(dev->ecam, dev->bus),
		     bus_sdis.u);
	debug_plat_ecam("disable_bus %d:%d:%d\n", dev->node, dev->ecam,
			dev->bus);
}

static inline void cn81xx_enable_bus(struct ecam_device *dev)
{
	cavm_ecamx_busx_sdis_t bus_sdis;
	cavm_ecamx_busx_nsdis_t bus_nsdis;

	/* enable bus */
	bus_sdis.u = CSR_READ_PA(dev->node,
				 CAVM_ECAMX_BUSX_SDIS(dev->ecam, dev->bus));
	bus_sdis.s.sec = 0;
	bus_sdis.s.dis = 0;
	CSR_WRITE_PA(dev->node,
		     CAVM_ECAMX_BUSX_SDIS(dev->ecam, dev->bus),
		     bus_sdis.u);

	bus_nsdis.u = CSR_READ_PA(dev->node,
				  CAVM_ECAMX_BUSX_NSDIS(dev->ecam, dev->bus));
	bus_nsdis.s.dis = 0;
	CSR_WRITE_PA(dev->node,
		     CAVM_ECAMX_BUSX_NSDIS(dev->ecam, dev->bus),
		     bus_nsdis.u);

	debug_plat_ecam("enable_bus %d:%d:%d\n", dev->node, dev->ecam,
			dev->bus);
}

static inline void cn81xx_disable_dev(struct ecam_device *dev)
{
	cavm_ecamx_devx_sdis_t dev_sdis;

	/* disable device */
	dev_sdis.u = CSR_READ_PA(dev->node,
				 CAVM_ECAMX_DEVX_SDIS(dev->ecam, dev->dev));
	dev_sdis.s.sec = 1;
	CSR_WRITE_PA(dev->node,
		     CAVM_ECAMX_DEVX_SDIS(dev->ecam, dev->dev),
		     dev_sdis.u);
	debug_plat_ecam("disable_dev %d:%d:%02x\n", dev->node, dev->ecam,
			dev->dev);
}

static inline void cn81xx_enable_dev(struct ecam_device *dev)
{
	cavm_ecamx_devx_sdis_t dev_sdis;
	cavm_ecamx_devx_nsdis_t dev_nsdis;

	/* enable device */
	dev_sdis.u = CSR_READ_PA(dev->node,
				 CAVM_ECAMX_DEVX_SDIS(dev->ecam, dev->dev));
	dev_sdis.s.sec = 0;
	dev_sdis.s.dis = 0;
	CSR_WRITE_PA(dev->node,
		     CAVM_ECAMX_DEVX_SDIS(dev->ecam, dev->dev),
		     dev_sdis.u);

	dev_nsdis.u = CSR_READ_PA(dev->node,
				  CAVM_ECAMX_DEVX_NSDIS(dev->ecam, dev->dev));
	dev_nsdis.s.dis = 0;
	CSR_WRITE_PA(dev->node,
		     CAVM_ECAMX_DEVX_NSDIS(dev->ecam, dev->dev),
		     dev_nsdis.u);

	debug_plat_ecam("enable_dev %d:%d:%02x\n", dev->node, dev->ecam,
			dev->dev);
}

static inline void cn81xx_disable_func(struct ecam_device *dev)
{
	cavm_ecamx_rslx_sdis_t rsl_sdis;

	/* disable function */
	rsl_sdis.u = CSR_READ_PA(dev->node,
				 CAVM_ECAMX_RSLX_SDIS(dev->ecam, dev->func));
	rsl_sdis.s.sec = 1;
	CSR_WRITE_PA(dev->node,
		     CAVM_ECAMX_RSLX_SDIS(dev->ecam, dev->func),
		     rsl_sdis.u);
	debug_plat_ecam("disable_func %d:%d:%02x\n", dev->node, dev->ecam,
			dev->func);
}

static inline void cn81xx_enable_func(struct ecam_device *dev)
{
	cavm_ecamx_rslx_sdis_t rsl_sdis;
	cavm_ecamx_rslx_nsdis_t rsl_nsdis;

	/* enable function */
	rsl_sdis.u = CSR_READ_PA(dev->node,
				 CAVM_ECAMX_RSLX_SDIS(dev->ecam, dev->func));
	rsl_sdis.s.sec = 0;
	rsl_sdis.s.dis = 0;
	CSR_WRITE_PA(dev->node,
		     CAVM_ECAMX_RSLX_SDIS(dev->ecam, dev->func),
		     rsl_sdis.u);

	rsl_nsdis.u = CSR_READ_PA(dev->node,
				  CAVM_ECAMX_RSLX_NSDIS(dev->ecam, dev->func));
	rsl_nsdis.s.dis = 0;
	CSR_WRITE_PA(dev->node,
		     CAVM_ECAMX_RSLX_NSDIS(dev->ecam, dev->func),
		     rsl_nsdis.u);

	debug_plat_ecam("enable_func %d:%d:%02x\n", dev->node, dev->ecam,
			dev->func);
}

static inline int cn81xx_get_ecam_count(int node)
{
	cavm_ecamx_const_t ecam_const;

	ecam_const.u = CSR_READ_PA(node, CAVM_ECAMX_CONST(0));

	return ecam_const.s.ecams;
}

static int cn81xx_get_domain_count(struct ecam_device *dev)
{
	/*
	 * In CN81xx ECAM topology, there're no domains.
	 * To satisfy PCI scan, at least 1 domain needs to be present
	 */
	return 1;
}

static inline int cn81xx_is_domain_present(struct ecam_device *dev)
{
	/*
	 * To satisfy proper PCI scan,
	 * at least 1 domain needs to be present
	 */
	return (dev->domain == 0);
}

static int cn81xx_get_secure_settings(struct ecam_device *dev, uint64_t pconfig)
{
	cavm_pccpf_xxx_id_t pccpf_id;
	int i = 0;

	/* Get secure/non-secure setting */
	pccpf_id.u = cavm_read32(pconfig + CAVM_PCCPF_XXX_ID);
	debug_plat_ecam("%s: DeviceID=0x%04x\n", __func__, pccpf_id.s.devid);

	dev->config.s.is_secure = 0;
	while (secure_devs[i].devid != ECAM_INVALID_PCC_IDL_ID) {
		if (((secure_devs[i].prodid << ECAM_PROD_SHIFT) |
			secure_devs[i].devid) == pccpf_id.s.devid)
			dev->config.s.is_secure = 1;
		i++;
	}

	/* Set SCP/MCP to 0, as they don't exist on T81 */
	dev->config.s.is_mcp_secure = 0;
	dev->config.s.is_scp_secure = 0;

	return 1;
}

struct ecam_probe_callback *cn81xx_get_probe_callbacks(void)
{
	return &probe_callbacks[0];
}

struct ecam_init_callback *cn81xx_get_init_callbacks(void)
{
	return NULL;
}

const struct ecam_platform_defs plat_ops = {
	.soc_type = T81PARTNUM,
	.get_ecam_count = cn81xx_get_ecam_count,
	.get_domain_count = cn81xx_get_domain_count,
	.is_domain_present = cn81xx_is_domain_present,
	.get_secure_settings = cn81xx_get_secure_settings,
	.get_dev_config = cn81xx_get_dev_config,
	.get_probes = cn81xx_get_probe_callbacks,
	.get_plat_inits = cn81xx_get_init_callbacks,
	.is_bus_disabled = cn81xx_is_bus_disabled,
	.skip_bus = cn81xx_skip_bus,
	.enable_bus = cn81xx_enable_bus,
	.disable_bus = cn81xx_disable_bus,
	.enable_dev = cn81xx_enable_dev,
	.disable_dev = cn81xx_disable_dev,
	.enable_func = cn81xx_enable_func,
	.disable_func = cn81xx_disable_func
};
