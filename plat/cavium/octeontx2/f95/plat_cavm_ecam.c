/** @file
#
#  Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
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
#include <platform_setup.h>
#include <cavm_common.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <cavm_ecam.h>
#include <cavm_dt.h>
#include <cavm_cgx.h>

#ifdef DEBUG_ATF_PLAT_ECAM
#define debug_plat_ecam printf
#else
#define debug_plat_ecam(...) ((void) (0))
#endif

/* Probe GSERNX_LANE_SCRATCHX[] for CGX config */
static int ecam_probe_cgx(int node, unsigned long arg)
{
	cavm_qlm_state_lane_t qlm_state;
	int qlm = -1, lnum = 0;

	debug_plat_ecam("%s arg %ld\n", __func__, arg);

	/* FIXME: cgx to qlm mapping.
	 * CGX0 - QLM0
	 * CGX1 - QLM2
	 * CGX2 - DLM3
	 */
	switch (arg) {
	case 0:
		qlm = 0;
		break;
	case 1:
		qlm = 2;
		break;
	case 2:
		qlm = 3;
		break;
	}

	lnum = plat_get_max_lane_num(qlm);
	while (qlm != -1) {
		for (int lane = 0; lane < lnum; lane++) {
			qlm_state.u = CSR_READ(node,
				CAVM_GSERNX_LANEX_SCRATCHX(qlm, lane, 0));
			if ((qlm_state.s.mode >= CAVM_QLM_MODE_SGMII_4X1) &&
				(qlm_state.s.mode <=
					CAVM_QLM_MODE_USXGMII_2X1)) {
				debug_plat_ecam("%s: CGX detected on qlm %d lane %d\n",
					__func__, qlm, lane);
				return 1;
			}
		}
		qlm = -1;
	};
	return 0;
}

struct ecam_probe_callback probe_callbacks[] = {
	{0xa059, 0x177d, ecam_probe_cgx, 0},
	{ECAM_INVALID_DEV_ID, 0, 0, 0}
};

static void init_rvu(int node, uint64_t config_base, uint64_t config_size)
{
	octeontx_rvu_init(node);
}

static void init_cgx(int node, uint64_t config_base, uint64_t config_size)
{
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	int cgx_id;

	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);
	cgx_id = vsec_ctl.s.inst_num;

	debug_plat_ecam("CGX(%d):NODE(%d) init config_base:%lx size:%lx\n",
		vsec_ctl.s.inst_num, node, config_base, config_size);

	cgx_hw_init(node, cgx_id);
}

struct ecam_init_callback plat_init_callbacks[] = {
	{0xa059, 0x177d, init_cgx}, /* 0x59 - PCC_DEV_IDL_E::CGX */
	{0xa065, 0x177d, init_rvu}, /* 0x65 - PCC_DEV_IDL_E::RVU_AF */
	{ECAM_INVALID_DEV_ID, 0, 0}
};

/*
 * Following device's BAR0 will be hidden
 * from non-secure world.
 */
struct secure_devices secure_devs[] = {
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GIC},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GTI},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_UAA},
	{ECAM_INVALID_PROD_ID, ECAM_INVALID_PCC_IDL_ID}
};

/*
 * Currently we're not hidding anything from SCP/MCP
 */
struct secure_devices secure_mcp_devs[] = {
	{ECAM_INVALID_PROD_ID, ECAM_INVALID_PCC_IDL_ID}
};

struct secure_devices secure_scp_devs[] = {
	{ECAM_INVALID_PROD_ID, ECAM_INVALID_PCC_IDL_ID}
};

static inline uint64_t cn95xx_get_dev_config(struct ecam_device *dev)
{
	uint64_t pconfig;
	cavm_pccpf_xxx_id_t pccpf_id;

	pconfig = (dev->base_addr |
		  ((dev->domain << ECAM_DOM_SHIFT) & ECAM_DOM_MASK) |
		  ((dev->bus << ECAM_BUS_SHIFT) & ECAM_BUS_MASK) |
		  ((dev->dev << ECAM_DEV_SHIFT) & ECAM_DEV_MASK) |
		  ((dev->func << ECAM_FUNC_SHIFT) & ECAM_FUNC_MASK));

	pccpf_id.u = cavm_read32(pconfig + CAVM_PCCPF_XXX_ID);
	if (pccpf_id.s.vendid == 0xffff || pccpf_id.s.devid == 0xffff)
		return 0;

	return pconfig;
}

static int cn95xx_is_bus_disabled(struct ecam_device *dev)
{
	int rc = 0;

	/* Below buses does not exist in internal F95 topology */
	if (((dev->domain == 0) && (dev->bus > 12)) ||
	    ((dev->domain == 1) && (dev->bus > 1))  ||
	    ((dev->domain == 2) && (dev->bus > 16)))
		rc = 1;

	return rc;
}

static int cn95xx_skip_bus(struct ecam_device *dev)
{
	return 0;
}

static inline void cn95xx_enable_bus(struct ecam_device *dev)
{
	cavm_ecamx_domx_busx_permit_t bus_permit;

	/* enable bus */
	bus_permit.u = CSR_READ(dev->node,
				   CAVM_ECAMX_DOMX_BUSX_PERMIT(dev->ecam,
				   dev->domain, dev->bus));
	bus_permit.s.sec_dis = 0;
	bus_permit.s.nsec_dis = 0;
	bus_permit.s.xcp0_dis = 0;
	bus_permit.s.xcp1_dis = 0;
	CSR_WRITE(dev->node,
		     CAVM_ECAMX_DOMX_BUSX_PERMIT(dev->ecam, dev->domain,
		     dev->bus), bus_permit.u);
	debug_plat_ecam("enable_bus N%d:E%d:DOM%d:B%d\n", dev->node, dev->ecam,
			dev->domain, dev->bus);
}

static inline void cn95xx_disable_bus(struct ecam_device *dev)
{
	cavm_ecamx_domx_busx_permit_t bus_permit;

	/* disable bus */
	bus_permit.u = CSR_READ(dev->node,
				   CAVM_ECAMX_DOMX_BUSX_PERMIT(dev->ecam,
				   dev->domain, dev->bus));
	bus_permit.s.sec_dis = 0;
	bus_permit.s.nsec_dis = 1;
	bus_permit.s.xcp0_dis = 0;
	bus_permit.s.xcp1_dis = 0;
	CSR_WRITE(dev->node,
		     CAVM_ECAMX_DOMX_BUSX_PERMIT(dev->ecam, dev->domain,
		     dev->bus), bus_permit.u);
	debug_plat_ecam("disable_bus N%d:E%d:DOM%d:B%d\n", dev->node, dev->ecam,
			dev->domain, dev->bus);
}

static inline void cn95xx_enable_dev(struct ecam_device *dev)
{
	cavm_ecamx_domx_devx_permit_t dev_permit;

	/* enable dev */
	dev_permit.u = CSR_READ(dev->node,
				   CAVM_ECAMX_DOMX_DEVX_PERMIT(dev->ecam,
				   dev->domain, dev->dev));
	dev_permit.s.sec_dis = 0;
	dev_permit.s.nsec_dis = 0;
	dev_permit.s.xcp0_dis = dev->config.s.is_scp_secure;
	dev_permit.s.xcp1_dis = dev->config.s.is_mcp_secure;
	CSR_WRITE(dev->node,
		     CAVM_ECAMX_DOMX_DEVX_PERMIT(dev->ecam, dev->domain,
		     dev->dev), dev_permit.u);
	debug_plat_ecam("enable_dev N%d:E%d:DOM%d:D%d\n", dev->node, dev->ecam,
			dev->domain, dev->dev);
}

static inline void cn95xx_disable_dev(struct ecam_device *dev)
{
	cavm_ecamx_domx_devx_permit_t dev_permit;

	/* enable dev */
	dev_permit.u = CSR_READ(dev->node,
				   CAVM_ECAMX_DOMX_DEVX_PERMIT(dev->ecam,
				   dev->domain, dev->dev));
	dev_permit.s.sec_dis = 0;
	dev_permit.s.nsec_dis = 1;
	dev_permit.s.xcp0_dis = dev->config.s.is_scp_secure;
	dev_permit.s.xcp1_dis = dev->config.s.is_mcp_secure;
	CSR_WRITE(dev->node,
		     CAVM_ECAMX_DOMX_DEVX_PERMIT(dev->ecam, dev->domain,
		     dev->dev), dev_permit.u);
	debug_plat_ecam("disable_dev N%d:E%d:DOM%d:D%d\n", dev->node, dev->ecam,
			dev->domain, dev->dev);
}

static inline void cn95xx_enable_func(struct ecam_device *dev)
{
	cavm_ecamx_domx_rslx_permit_t rsl_permit;

	/* enable func */
	rsl_permit.u = CSR_READ(dev->node,
				   CAVM_ECAMX_DOMX_RSLX_PERMIT(dev->ecam,
				   dev->domain, dev->func));
	rsl_permit.s.sec_dis = 0;
	rsl_permit.s.nsec_dis = 0;
	rsl_permit.s.xcp0_dis = dev->config.s.is_scp_secure;
	rsl_permit.s.xcp1_dis = dev->config.s.is_mcp_secure;
	CSR_WRITE(dev->node,
		     CAVM_ECAMX_DOMX_RSLX_PERMIT(dev->ecam, dev->domain,
		     dev->func), rsl_permit.u);
	debug_plat_ecam("enable_func N%d:E%d:DOM%d:F%d\n", dev->node,
			dev->ecam, dev->domain, dev->func);
}

static inline void cn95xx_disable_func(struct ecam_device *dev)
{
	cavm_ecamx_domx_rslx_permit_t rsl_permit;

	/* disable func */
	rsl_permit.u = CSR_READ(dev->node,
				   CAVM_ECAMX_DOMX_RSLX_PERMIT(dev->ecam,
				   dev->domain, dev->func));
	rsl_permit.s.sec_dis = 0;
	rsl_permit.s.nsec_dis = 1;
	rsl_permit.s.xcp0_dis = dev->config.s.is_scp_secure;
	rsl_permit.s.xcp1_dis = dev->config.s.is_mcp_secure;
	CSR_WRITE(dev->node,
		     CAVM_ECAMX_DOMX_RSLX_PERMIT(dev->ecam, dev->domain,
		     dev->func), rsl_permit.u);
	debug_plat_ecam("disable_func N%d:E%d:DOM%d:F%d\n", dev->node,
			dev->ecam, dev->domain, dev->func);
}

static int cn95xx_get_ecam_count(int node)
{
	cavm_ecamx_const_t ecam_const;

	ecam_const.u = CSR_READ(node, CAVM_ECAMX_CONST(0));

	return ecam_const.s.ecams;
}

static int cn95xx_get_domain_count(struct ecam_device *dev)
{
	cavm_ecamx_const_t ecam_const;

	ecam_const.u = CSR_READ(dev->node, CAVM_ECAMX_CONST(dev->ecam));

	return ecam_const.s.domains;
}

static inline int cn95xx_is_domain_present(struct ecam_device *dev)
{
	cavm_ecamx_domx_const_t dom_const;

	dom_const.u = CSR_READ(dev->node,
				  CAVM_ECAMX_DOMX_CONST(dev->ecam,
				  dev->domain));

	return (dom_const.s.pres && dom_const.s.permit);
}

static int cn95xx_get_secure_settings(struct ecam_device *dev, uint64_t pconfig)
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

	i = 0;
	dev->config.s.is_mcp_secure = 0;
	while (secure_mcp_devs[i].devid != ECAM_INVALID_PCC_IDL_ID) {
		if (((secure_mcp_devs[i].prodid << ECAM_PROD_SHIFT) |
			secure_mcp_devs[i].devid) == pccpf_id.s.devid)
			dev->config.s.is_mcp_secure = 1;
		i++;
	}

	i = 0;
	dev->config.s.is_scp_secure = 0;
	while (secure_scp_devs[i].devid != ECAM_INVALID_PCC_IDL_ID) {
		if (((secure_scp_devs[i].prodid << ECAM_PROD_SHIFT) |
			secure_scp_devs[i].devid) == pccpf_id.s.devid)
			dev->config.s.is_scp_secure = 1;
		i++;
	}

	return 1;
}

struct ecam_probe_callback *cn95xx_get_probe_callbacks(void)
{
	return &probe_callbacks[0];
}

struct ecam_init_callback *cn95xx_get_init_callbacks(void)
{
	return &plat_init_callbacks[0];
}

const struct ecam_platform_defs plat_ops = {
	.soc_type = F95PARTNUM,
	.get_ecam_count = cn95xx_get_ecam_count,
	.get_domain_count = cn95xx_get_domain_count,
	.is_domain_present = cn95xx_is_domain_present,
	.get_secure_settings = cn95xx_get_secure_settings,
	.get_dev_config = cn95xx_get_dev_config,
	.get_probes = cn95xx_get_probe_callbacks,
	.get_plat_inits = cn95xx_get_init_callbacks,
	.is_bus_disabled = cn95xx_is_bus_disabled,
	.skip_bus = cn95xx_skip_bus,
	.enable_bus = cn95xx_enable_bus,
	.disable_bus = cn95xx_disable_bus,
	.enable_dev = cn95xx_enable_dev,
	.disable_dev = cn95xx_disable_dev,
	.enable_func = cn95xx_enable_func,
	.disable_func = cn95xx_disable_func,
};
