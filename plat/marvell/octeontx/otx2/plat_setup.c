/*
 * Copyright (C) 2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <string.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <cgx_intf.h>
#include <cgx.h>
#include <plat_pwrc.h>
#include <octeontx_legacy_pwrc.h>
#include <gpio_octeontx.h>
#include <plat_board_cfg.h>
#include <plat_flr.h>
#include <lmc_ras.h>
#include <plat_octeontx.h>
#include <octeontx_utils.h>
#include <sh_fwdata.h>

static int disable_ooo;

/* Any SoC family specific setup
 * to be done in BL31 can be initialized
 * in this API. If there are any platform
 * specific init to be done but not common
 * to family, each platform can define
 * its own API and can be called from here
 */
void plat_octeontx_setup(void)
{
	sh_fwdata_init();
	/* Initialize CGX framework */
	cgx_fw_intf_init();

	/* setup gpio interrupt handling */
	plat_gpio_irq_setup();


	/* Workaround for FLR handling on CN9xxx */
	plat_flr_init();

	plat_dram_ras_init();
}

/*
 * Program REVID for PCIe devices.
 * Bits 0..1: minor pass
 * Bits 3..2: major pass
 * Bits 7..4: midr id, 0:96, 1:95, 2:loki, 3:98, f:unknown
 */
unsigned int plat_configure_rid(void)
{
	unsigned int val;
	uint8_t midr_id;
	uint64_t midr;

	val = 0;
	midr = read_midr();

	switch (MIDR_PARTNUM(midr)) {
	case T96PARTNUM:
		midr_id = 0;
		break;

	case F95PARTNUM:
		midr_id = 1;
		break;

	case LOKIPARTNUM:
		midr_id = 2;
		break;

	case T98PARTNUM:
		midr_id = 3;
		break;

	default:
		midr_id = 0xf;
		WARN("Unknown partnum 0x%llx, set midr id in REVID to 0xf\n",
			MIDR_PARTNUM(midr));
	}

	val = midr_id << 4;
	/* program minor pass */
	val |= MIDR_REVISION(midr) & 0x3;

	/* program major pass */
	val |= MIDR_VARIANT(midr) & 0x3;

	return val;
}

extern void *scmi_handle;

void plat_pwrc_setup(void)
{
	int rc;

#ifdef SCMI_WITH_LEGACY_PM
	/*
	 * Initialize SCMI for custom Cavium configuration protocol.
	 * Initialize legacy pwrc for PSCI
	 */
	rc = octeontx_pwrc_setup();
	if (rc)
		WARN("SCMI initialize falied with %d\n", rc);
	octeontx_legacy_pwrc_setup();
#else
	/*
	 * Try to initialize SCMI, in case of error,
	 * fallback to legacy PM driver
	 */
	rc = octeontx_pwrc_setup();
	if (rc) {
		octeontx_legacy_pwrc_setup();
	}
#endif
}

void plat_setup_psci_ops(uintptr_t sec_entrypoint,
			 const plat_psci_ops_t **psci_ops)
{
#ifdef SCMI_WITH_LEGACY_PM
	/*
	 * Always use legacy PSCI ops
	 */
	octeontx_legacy_setup_psci_ops(sec_entrypoint, psci_ops);
#else
	if (scmi_handle == NULL) {
		octeontx_legacy_setup_psci_ops(sec_entrypoint, psci_ops);
	} else {
		octeontx_setup_psci_ops(sec_entrypoint, psci_ops);
	}
#endif
}

/*
 * Get ROM_T_CNT value from the FUSF_RCMD
 *
 * Return: Value in 0-32 range
 */
unsigned int plat_get_rom_t_cnt()
{
	cavm_fusf_rcmd_t read_cmd;
	uint64_t dat;
	uint32_t nv_count_val = 0;
	unsigned int ret = 0;

	read_cmd.u = 0;
	/* In CN9XXX fuses take a 128 bit bank, not a byte address.
	 * ROM_T_CNT is at bank 0 */
	read_cmd.cn9.addr = CAVM_FUSF_FUSE_NUM_E_ROM_T_CNTX(0) >> 7;
	read_cmd.s.pend = 1;
	CSR_WRITE(CAVM_FUSF_RCMD, read_cmd.u);
	do {
		read_cmd.u = CSR_READ(CAVM_FUSF_RCMD);
	} while (read_cmd.s.pend);

	/* ASIM returns 0 on FUSF_RCMD accesses */
	if (!strncmp(plat_octeontx_bcfg->bcfg.board_model, "asim-", 5))
		dat = CSR_READ(CAVM_FUSF_CTL);
	else
		dat = CSR_READ(CAVM_FUSF_BNK_DATX(0));

	/*
	 * FUSF_BNK_DATX contains all 128 fuses
	 * in the bank associated with FUSF_RCMD[ADDR].
	 * ROM_T_CNT is stored on FUSF_BNK_DATX(0)[63:32]
	 */
	nv_count_val = octeontx_bit_extract(dat, CAVM_FUSF_FUSE_NUM_E_ROM_T_CNTX(0), 32);

	/* Convert value from rom_t_cnt to unsigned int */
	if (nv_count_val)
		ret = 32 - __builtin_clz(nv_count_val);

	return ret;
}

/*
 * Return alternative pkg information
 *
 * @return non-zero if an alternative package
 *     0 = Normal package
 *     1 = Alternative package 1 (CN93XX)
 *     3 = Alternative package 3 (CN95XXE)
 */
int plat_get_altpkg(void)
{
	union cavm_gpio_pkg_ver pkg_ver;

	pkg_ver.u = CSR_READ(CAVM_GPIO_PKG_VER);
	return pkg_ver.s.pkg_ver;
}

/*
 * Return to enable/disable OOO
 *
 * @return non-zero to diable OOO
 */
int plat_get_ooo_status(void)
{
	if (disable_ooo)
		return 1;
	else
		return 0;
}

void plat_octeontx_cpu_setup(void)
{
	uint64_t cvmctl_el1, cvmmemctl0_el1, cvmmemctl1_el1, cvmmemctl2_el1;
	uint64_t cvmctl2_el1, midr;

	cvmctl_el1 = read_cvmctl_el1();
	cvmctl2_el1 = read_cvmctl2_el1();
	cvmmemctl0_el1 = read_cvmmemctl0_el1();
	cvmmemctl1_el1 = read_cvmmemctl1_el1();
	cvmmemctl2_el1 = read_cvmmemctl2_el1();
	midr = read_midr();

	/* Enable CAS/CASP and v8.1 support */
	unset_bit(cvmctl_el1, 36);  /* Enable CAS */
	unset_bit(cvmctl_el1, 37);  /* Enable CASP */

	/* Enable prefetcher */
	set_bit(cvmctl_el1, 43);   /* Ignore the bp for next line prefetcher. */
	set_bit(cvmctl_el1, 42);   /* Use stride of 2. */
	set_bit(cvmctl_el1, 41);   /* Enable next line prefetcher. */
	set_bit(cvmctl_el1, 40);   /* Enable delta prefetcher. */

	/* Errata AP-36579 */
	if (IS_OCTEONTX_PASS(midr, T96PARTNUM, 1, 0)
	    || IS_OCTEONTX_VAR(midr, F95PARTNUM, 1)) {
		/* cvmctl2_el1[3:2] = REDUCE_MAP_BANDWIDTH */
		set_bit(cvmctl2_el1, 2);
		set_bit(cvmctl2_el1, 3);
	}

	/* Errata AP-36933 */
	if (IS_OCTEONTX_PN(midr, T96PARTNUM)
	    || IS_OCTEONTX_VAR(midr, F95PARTNUM, 1)
	    || IS_OCTEONTX_PASS(midr, LOKIPARTNUM, 1, 0)
	    || IS_OCTEONTX_PASS(midr, T98PARTNUM, 1, 0))
		/* cvmctl_el1[54] = DISABLE_LDP_STP_FISS */
		set_bit(cvmctl_el1, 54);

	/*
	 * Disable v8.5 store barrier for better performance on all models.
	 * cvmctl_el1[61] = DISABLE_STORE_BARRIER_FUNC
	 */
	set_bit(cvmctl_el1, 61);

	/*
	 * Set cvm_ctl_el1[5] to workaround debug state execution in
	 * incorrect EL
	 */
	if (IS_OCTEONTX_PASS(midr, T96PARTNUM, 1, 0))
		set_bit(cvmctl_el1, 5);

	set_bit(cvmmemctl1_el1, 3); /* Enable LMTST */
	set_bit(cvmmemctl1_el1, 4); /* Enable SSO/PKO addr region */
	set_bit(cvmmemctl1_el1, 5); /* Trap any accesses to nonzero node id */
	set_bit(cvmmemctl1_el1, 6); /* Enable SSO switch tag */

	if (IS_OCTEONTX_PN(midr, F95PARTNUM)
	    || IS_OCTEONTX_PN(midr, LOKIPARTNUM))
		set_bit(cvmmemctl1_el1, 58); /* Enable 128-bit access to BPHY */

	/*
	 * To improve performance memory-unit for EL1 should be configured in
	 * different way than default.
	 */
	cvmmemctl2_el1 = octeontx_bit_insert(
			cvmmemctl2_el1, MTLB0_BLOCK_VALUE,
			MTLB0_BLOCK_SHIFT, MTLB0_BLOCK_WIDTH);
	cvmmemctl2_el1 = octeontx_bit_insert(
			cvmmemctl2_el1, TLBI_BLOCK_VALUE,
			TLBI_BLOCK_SHIFT, TLBI_BLOCK_WIDTH);

	/*
	 * Fix up defaults from the BDK which is broken and
	 * violates the ARM ARM.
	 */

	/* Don't reset timer on merge as that violates the ARM ARM. */
	unset_bit(cvmmemctl0_el1, 17);
	/* Set Write-buffer timeout for NSH entries to 218 cycles. */
	unset_bit(cvmmemctl0_el1, 18);

	/* Disable/enable OOO */
	if (plat_get_ooo_status())
		set_bit(cvmctl_el1, 44);
	else
		unset_bit(cvmctl_el1, 44);

	write_cvmctl_el1(cvmctl_el1);
	write_cvmctl2_el1(cvmctl2_el1);
	write_cvmmemctl0_el1(cvmmemctl0_el1);
	write_cvmmemctl1_el1(cvmmemctl1_el1);
	write_cvmmemctl2_el1(cvmmemctl2_el1);

	/* Allow CVM CACHE instructions from EL1/EL2 */
	write_cvm_access_el1(read_cvm_access_el1() & ~(1 << 8));
	write_cvm_access_el2(read_cvm_access_el2() & ~(1 << 8));
	write_cvm_access_el3(read_cvm_access_el3() & ~(1 << 8));
}

int octeontx2_configure_ooo(int x1)
{
	uint64_t cvmctl_el1;

	disable_ooo = x1 ? 1 : 0;

	cvmctl_el1 = read_cvmctl_el1();
	if (disable_ooo)
		set_bit(cvmctl_el1, 44);
	else
		unset_bit(cvmctl_el1, 44);

	write_cvmctl_el1(cvmctl_el1);

	return 0;
}
