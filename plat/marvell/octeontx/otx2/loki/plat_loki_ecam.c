/*
 * Copyright (C) 2019 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#include <platform_def.h>
#include <platform_setup.h>
#include <octeontx_common.h>

#include <debug.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <octeontx_ecam.h>
#include <plat_board_cfg.h>
#include <plat_scfg.h>
#include <cgx.h>
#include <octeontx_utils.h>
#include <rvu.h>
#include <plat_otx2_configuration.h>
#include <qlm.h>

#ifdef DEBUG_ATF_PLAT_ECAM
#define debug_plat_ecam printf
#else
#define debug_plat_ecam(...) ((void) (0))
#endif

/*
 * Platform methods defined in plat_cavm_ecam.c file
 */
extern const struct ecam_platform_defs plat_ops;


static int is_qlm_configured_as_cgx(int qlm)
{
	qlm_state_lane_t qlm_state;
	int lnum;

	lnum = plat_octeontx_scfg->qlm_max_lane_num[qlm];
	for (int lane = 0; lane < lnum; lane++) {
		qlm_state = plat_otx2_get_qlm_state_lane(qlm, lane);
		if (qlm_state.s.cgx) {
			debug_plat_ecam("%s: CGX detected on qlm %d lane %d\n",
				__func__, qlm, lane);
			return 1;
		}
	}

	return 0;
}

static int ecam_probe_cgx(unsigned long long arg)
{
	debug_plat_ecam("%s arg %lld\n", __func__, arg);

	/* cgx to qlm mapping.
	 * CGX0 - QLM1
	 * CGX1 - DLM2, DLM3
	 * CGX2 - DLM4, DLM5
	 * CGX3 - DLM6
	 */
	switch (arg) {
	case 0:
		return is_qlm_configured_as_cgx(1);
	case 1:
		return is_qlm_configured_as_cgx(2) ||
			is_qlm_configured_as_cgx(3);
	case 2:
		return is_qlm_configured_as_cgx(4) ||
			is_qlm_configured_as_cgx(5);
	case 3:
		return is_qlm_configured_as_cgx(6);
	}

	return 0;
}

struct ecam_probe_callback probe_callbacks[] = {
	{0xa059, 0x177d, ecam_probe_cgx, 0},
	{ECAM_INVALID_DEV_ID, 0, 0, 0}
};

static void init_gpio(uint64_t config_base, uint64_t config_size)
{
	union cavm_pccpf_xxx_vsec_sctl vsec_sctl;

	debug_plat_ecam("GPIO init called config_base:%llx size:%llx\n",
			config_base, config_size);

	/* Block can have mix of secure and non-secure MSI-X interrupts */
	vsec_sctl.u = octeontx_read32(config_base + CAVM_PCCPF_XXX_VSEC_SCTL);
	vsec_sctl.cn9.msix_sec_en = 1;
	vsec_sctl.cn9.msix_sec_phys = 1;
	octeontx_write32(config_base + CAVM_PCCPF_XXX_VSEC_SCTL, vsec_sctl.u);
}

static void init_rvu_rid(uint64_t config_base, uint64_t config_size)
{
	union cavm_pccpf_xxx_vsec_sctl vsec_sctl;

	vsec_sctl.u = octeontx_read32(config_base + CAVM_PCCPF_XXX_VSEC_SCTL);
	vsec_sctl.cn9.rid = plat_configure_rid();
	octeontx_write32(config_base + CAVM_PCCPF_XXX_VSEC_SCTL, vsec_sctl.u);
}

static void init_rvu(uint64_t config_base, uint64_t config_size)
{
	init_rvu_rid(config_base, config_size);
	octeontx_rvu_init();
}

static void init_cgx(uint64_t config_base, uint64_t config_size)
{
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	int cgx_id;
	cgx_config_t *cgx;

	vsec_ctl.u = octeontx_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);
	cgx_id = vsec_ctl.s.inst_num;

	debug_plat_ecam("CGX(%d): init config_base:%llx size:%llx\n",
		vsec_ctl.s.inst_num, config_base, config_size);

	cgx = &(plat_octeontx_bcfg->cgx_cfg[cgx_id]);

	/* CGX1, CGX2 and CGX3 are routed to RFOE for loki */
	if ((cgx_id == 1) || (cgx_id == 2) || (cgx_id == 3))
		cgx->is_rfoe = 1;

	cgx_hw_init(cgx_id);
}

static void init_bphy(uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	union cavm_pccpf_xxx_vsec_sctl vsec_sctl;
	uint8_t bir = 0;
	uint16_t tbl_sz = 0;

	debug_plat_ecam("BPHY init called config_base:%llx size:%llx\n",
			config_base, config_size);

	vsec_sctl.u = octeontx_read32(config_base + CAVM_PCCPF_XXX_VSEC_SCTL);
	vsec_sctl.cn9.msix_sec_en = 1;
	vsec_sctl.cn9.msix_sec_phys = 1;
	octeontx_write32(config_base + CAVM_PCCPF_XXX_VSEC_SCTL, vsec_sctl.u);

	enable_msix(config_base, pconfig->cap_pointer, &tbl_sz, &bir);
	if (tbl_sz) {
		debug_plat_ecam("tbl sz: %x, bir:%x\n", tbl_sz, bir);
		debug_plat_ecam("MSI-X vector base: %llx\n",
				get_bar_val(pconfig, bir));
	}
}

struct ecam_init_callback plat_init_callbacks[] = {
	{0xa00a, 0x177d, init_gpio},
	{0xa059, 0x177d, init_cgx}, /* 0x59 - PCC_DEV_IDL_E::CGX */
	{0xa065, 0x177d, init_rvu}, /* 0x65 - PCC_DEV_IDL_E::RVU_AF */
	{0xa063, 0x177d, init_rvu_rid}, /* 0x63 - PCC_DEV_IDL_E::RVU */
	{0xa0f8, 0x177d, init_rvu_rid}, /* 0xf8 - PCC_DEV_IDL_E::RVU_AF_VF */
	{0xa0f9, 0x177d, init_rvu_rid}, /* 0xf9 - PCC_DEV_IDL_E::RVU_SSO_PF */
	{0xa0fa, 0x177d, init_rvu_rid}, /* 0xfa - PCC_DEV_IDL_E::RVU_SSO_VF */
	{0xa0fb, 0x177d, init_rvu_rid}, /* 0xfb - PCC_DEV_IDL_E::RVU_NPA_PF */
	{0xa0fc, 0x177d, init_rvu_rid}, /* 0xfc - PCC_DEV_IDL_E::RVU_NPA_VF */
	{0xa089, 0x177d, init_bphy},
	{ECAM_INVALID_DEV_ID, 0, 0}
};

/*
 * Following device's BAR0 will be hidden
 * from non-secure world.
 */
struct secure_devices secure_devs[] = {
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GIC5},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GTI},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_UAA},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_LMC},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_OCLA},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GSERN},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_DAP},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_FUSF},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_AVS},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_TSN},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_CCS},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_CCU},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_FUS5},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_BTS},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_NDF},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_SMI},
	{ECAM_INVALID_PROD_ID, ECAM_INVALID_PCC_IDL_ID}
};

struct secure_devices secure_mcp_devs[] = {
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GIC5},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GTI},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_UAA},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_LMC},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_OCLA},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_GSERN},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_DAP},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_FUSF},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_AVS},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_TSN},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_CCS},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_CCU},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_FUS5},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_RST5},
	{CAVM_PCC_PROD_E_GEN, CAVM_PCC_DEV_IDL_E_BTS},
	{ECAM_INVALID_PROD_ID, ECAM_INVALID_PCC_IDL_ID}
};

/*
 * Currently we're not hidding anything from SCP,
 * since it's operating in secure domain
 */
struct secure_devices secure_scp_devs[] = {
	{ECAM_INVALID_PROD_ID, ECAM_INVALID_PCC_IDL_ID}
};

static inline uint64_t loki_get_dev_config(struct ecam_device *dev)
{
	uint64_t pconfig;
	cavm_pccpf_xxx_id_t pccpf_id;

	pconfig = (dev->base_addr |
		  ((dev->domain << ECAM_DOM_SHIFT) & ECAM_DOM_MASK) |
		  ((dev->bus << ECAM_BUS_SHIFT) & ECAM_BUS_MASK) |
		  ((dev->dev << ECAM_DEV_SHIFT) & ECAM_DEV_MASK) |
		  ((dev->func << ECAM_FUNC_SHIFT) & ECAM_FUNC_MASK));

	pccpf_id.u = octeontx_read32(pconfig + CAVM_PCCPF_XXX_ID);
	if (pccpf_id.s.vendid == 0xffff || pccpf_id.s.devid == 0xffff)
		return 0;

	return pconfig;
}

static int loki_is_bus_disabled(struct ecam_device *dev)
{
	int rc = 0;

	/***********************************************************************
	 * TODO: CHECK IF THIS IS TRUE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 **********************************************************************/
	/* Below buses does not exist in internal loki topology */
	if (((dev->domain == 0) && (dev->bus > 12)) ||
	    ((dev->domain == 1) && ((dev->bus > 1) && (dev->bus != 4)))  ||
	    ((dev->domain == 2) && (dev->bus > 16)))
		rc = 1;

	return rc;
}

static int loki_skip_bus(struct ecam_device *dev)
{
	return 0;
}

static inline void loki_enable_bus(struct ecam_device *dev)
{
	cavm_ecamx_domx_busx_permit_t bus_permit;

	/* enable bus */
	bus_permit.u = CSR_READ(CAVM_ECAMX_DOMX_BUSX_PERMIT(dev->ecam,
				   dev->domain, dev->bus));
	bus_permit.s.sec_dis = 0;
	bus_permit.s.nsec_dis = 0;
	bus_permit.s.xcp0_dis = 0;
	bus_permit.s.xcp1_dis = 0;
	CSR_WRITE(CAVM_ECAMX_DOMX_BUSX_PERMIT(dev->ecam, dev->domain,
		     dev->bus), bus_permit.u);
	debug_plat_ecam("enable_bus E%d:DOM%d:B%d\n",
			dev->ecam, dev->domain, dev->bus);
}

static inline void loki_disable_bus(struct ecam_device *dev)
{
	cavm_ecamx_domx_busx_permit_t bus_permit;

	/* disable bus */
	bus_permit.u = CSR_READ(CAVM_ECAMX_DOMX_BUSX_PERMIT(dev->ecam,
				   dev->domain, dev->bus));
	bus_permit.s.sec_dis = 0;
	bus_permit.s.nsec_dis = 1;
	bus_permit.s.xcp0_dis = 0;
	bus_permit.s.xcp1_dis = 0;
	CSR_WRITE(CAVM_ECAMX_DOMX_BUSX_PERMIT(dev->ecam, dev->domain,
		     dev->bus), bus_permit.u);
	debug_plat_ecam("disable_bus E%d:DOM%d:B%d\n",
			dev->ecam, dev->domain, dev->bus);
}

static inline void loki_enable_dev(struct ecam_device *dev)
{
	cavm_ecamx_domx_devx_permit_t dev_permit;

	/* enable dev */
	dev_permit.u = CSR_READ(CAVM_ECAMX_DOMX_DEVX_PERMIT(dev->ecam,
				   dev->domain, dev->dev));
	dev_permit.s.sec_dis = 0;
	dev_permit.s.nsec_dis = 0;
	dev_permit.s.xcp0_dis = dev->config.s.is_scp_secure;
	dev_permit.s.xcp1_dis = dev->config.s.is_mcp_secure;
	CSR_WRITE(CAVM_ECAMX_DOMX_DEVX_PERMIT(dev->ecam, dev->domain,
		     dev->dev), dev_permit.u);
	debug_plat_ecam("enable_dev E%d:DOM%d:D%d\n",
			dev->ecam, dev->domain, dev->dev);
}

static inline void loki_disable_dev(struct ecam_device *dev)
{
	cavm_ecamx_domx_devx_permit_t dev_permit;

	/* enable dev */
	dev_permit.u = CSR_READ(CAVM_ECAMX_DOMX_DEVX_PERMIT(dev->ecam,
				   dev->domain, dev->dev));
	dev_permit.s.sec_dis = 0;
	dev_permit.s.nsec_dis = 1;
	dev_permit.s.xcp0_dis = dev->config.s.is_scp_secure;
	dev_permit.s.xcp1_dis = dev->config.s.is_mcp_secure;
	CSR_WRITE(CAVM_ECAMX_DOMX_DEVX_PERMIT(dev->ecam, dev->domain,
		     dev->dev), dev_permit.u);
	debug_plat_ecam("disable_dev E%d:DOM%d:D%d\n",
			dev->ecam, dev->domain, dev->dev);
}

static inline void loki_enable_func(struct ecam_device *dev)
{
	cavm_ecamx_domx_rslx_permit_t rsl_permit;

	/* enable func */
	rsl_permit.u = CSR_READ(CAVM_ECAMX_DOMX_RSLX_PERMIT(dev->ecam,
				   dev->domain, dev->func));
	rsl_permit.s.sec_dis = 0;
	rsl_permit.s.nsec_dis = 0;
	rsl_permit.s.xcp0_dis = dev->config.s.is_scp_secure;
	rsl_permit.s.xcp1_dis = dev->config.s.is_mcp_secure;
	CSR_WRITE(CAVM_ECAMX_DOMX_RSLX_PERMIT(dev->ecam, dev->domain,
		     dev->func), rsl_permit.u);
	debug_plat_ecam("enable_func E%d:DOM%d:F%d\n",
			dev->ecam, dev->domain, dev->func);
}

static inline void loki_disable_func(struct ecam_device *dev)
{
	cavm_ecamx_domx_rslx_permit_t rsl_permit;

	/* disable func */
	rsl_permit.u = CSR_READ(CAVM_ECAMX_DOMX_RSLX_PERMIT(dev->ecam,
				   dev->domain, dev->func));
	rsl_permit.s.sec_dis = 0;
	rsl_permit.s.nsec_dis = 1;
	rsl_permit.s.xcp0_dis = dev->config.s.is_scp_secure;
	rsl_permit.s.xcp1_dis = dev->config.s.is_mcp_secure;
	CSR_WRITE(CAVM_ECAMX_DOMX_RSLX_PERMIT(dev->ecam, dev->domain,
		     dev->func), rsl_permit.u);
	debug_plat_ecam("disable_func E%d:DOM%d:F%d\n",
			dev->ecam, dev->domain, dev->func);
}

static int loki_get_ecam_count(void)
{
	cavm_ecamx_const_t ecam_const;

	ecam_const.u = CSR_READ(CAVM_ECAMX_CONST(0));

	return ecam_const.s.ecams;
}

static int loki_get_domain_count(struct ecam_device *dev)
{
	cavm_ecamx_const_t ecam_const;

	ecam_const.u = CSR_READ(CAVM_ECAMX_CONST(dev->ecam));

	return ecam_const.s.domains;
}

static inline int loki_is_domain_present(struct ecam_device *dev)
{
	cavm_ecamx_domx_const_t dom_const;

	dom_const.u = CSR_READ(CAVM_ECAMX_DOMX_CONST(dev->ecam,
				  dev->domain));

	return (dom_const.s.pres && dom_const.s.permit);
}

static int loki_get_secure_settings(struct ecam_device *dev, uint64_t pconfig)
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

struct ecam_probe_callback *loki_get_probe_callbacks(void)
{
	return &probe_callbacks[0];
}

struct ecam_init_callback *loki_get_init_callbacks(void)
{
	return &plat_init_callbacks[0];
}

const struct ecam_platform_defs plat_ops = {
	.soc_type = LOKIPARTNUM,
	.get_ecam_count = loki_get_ecam_count,
	.get_domain_count = loki_get_domain_count,
	.is_domain_present = loki_is_domain_present,
	.get_secure_settings = loki_get_secure_settings,
	.get_dev_config = loki_get_dev_config,
	.get_probes = loki_get_probe_callbacks,
	.get_plat_inits = loki_get_init_callbacks,
	.is_bus_disabled = loki_is_bus_disabled,
	.skip_bus = loki_skip_bus,
	.enable_bus = loki_enable_bus,
	.disable_bus = loki_disable_bus,
	.enable_dev = loki_enable_dev,
	.disable_dev = loki_disable_dev,
	.enable_func = loki_enable_func,
	.disable_func = loki_disable_func,
};
