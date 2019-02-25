/*
 * Copyright (C) 2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <octeontx_legacy_pwrc.h>
#include <gpio_octeontx.h>
#include <plat_octeontx.h>
#include <plat_fuse.h>
#include <octeontx_utils.h>

/* Any SoC family specific setup
 * to be done in BL31 can be initialized
 * in this API. If there are any platform
 * specific init to be done but not common
 * to family, each platform can define
 * its own API and can be called from here
 */
void plat_octeontx_setup(void)
{
	/* setup gpio interrupt handling */
	plat_gpio_irq_setup();
}

void plat_pwrc_setup(void)
{
	octeontx_legacy_pwrc_setup();
}

void plat_setup_psci_ops(uintptr_t sec_entrypoint,
			 const plat_psci_ops_t **psci_ops)
{
	octeontx_legacy_setup_psci_ops(sec_entrypoint, psci_ops);
}

/*
 * Read a single fuse bit from MIO_FUS
 */
int plat_fuse_read(int fuse)
{
	cavm_mio_fus_rcmd_t read_cmd;
	int byte_addr = FUSE_BIT_TO_BYTE_ADDR(fuse);

	read_cmd.u = 0;
	read_cmd.s.addr = byte_addr;
	read_cmd.s.addr_hi = FUSE_HI_ADDR(byte_addr);
	read_cmd.s.pend = 1;
	CSR_WRITE(CAVM_MIO_FUS_RCMD, read_cmd.u);
	while ((read_cmd.u = CSR_READ(CAVM_MIO_FUS_RCMD)) &&
		read_cmd.s.pend);

	return FUSE_GET_VAL(read_cmd.s.dat, fuse);
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
	cavm_fusf_ctl_t fusf_ctl;

	read_cmd.u = 0;
	/* In CN8XXX fuses take a byte address, not a 128 bit bank */
	read_cmd.cn8.addr = CAVM_FUSF_FUSE_NUM_E_ROM_T_CNTX(0) >> 3;
	read_cmd.cn8.addr_hi = CAVM_FUSF_FUSE_NUM_E_ROM_T_CNTX(0) >> 9;
	read_cmd.s.pend = 1;
	CSR_WRITE(CAVM_FUSF_RCMD, read_cmd.u);
	do {
		read_cmd.u = CSR_READ(CAVM_FUSF_RCMD);
	} while (read_cmd.s.pend);

	/*
	 * FUSF_BNK_DATX contains all 128 fuses
	 * in the bank associated with FUSF_RCMD[ADDR].
	 * ROM_T_CNT is stored on FUSF_BNK_DATX(0)[63:32].
	 */
	dat = CSR_READ(CAVM_FUSF_BNK_DATX(0));
	nv_count_val = octeontx_bit_extract(dat, CAVM_FUSF_FUSE_NUM_E_ROM_T_CNTX(0), 32);

	/*
	 * When there's no runtime update on BDK side,
	 * FUSF_BNK_DATX returns 0x1 with no respect to
	 * the actually soft blown value.
	 * Read NV_CNT from FUSF_CTL and use bigger value.
	 */
	fusf_ctl.u = CSR_READ(CAVM_FUSF_CTL);
	if (nv_count_val < fusf_ctl.s.rom_t_cnt)
		nv_count_val = fusf_ctl.s.rom_t_cnt;

	/* Convert value from rom_t_cnt to unsigned int */
	if (nv_count_val)
		ret = 32 - __builtin_clz(nv_count_val);

	return ret;
}

#ifdef NT_FW_CONFIG
void plat_octeontx_set_nt_fw_config_size(uint64_t nt_fw_config_size)
{
	/* Not used on CN8xxx */
	return;
}
#endif

void plat_octeontx_cpu_setup(void)
{
	uint64_t cvmctl_el1, cvmmemctl0_el1, cvmmemctl1_el1, midr;

	cvmctl_el1 = read_cvmctl_el1();
	cvmmemctl0_el1 = read_cvmmemctl0_el1();
	cvmmemctl1_el1 = read_cvmmemctl1_el1();

	midr = read_midr();

	/*
	 * Enable CAS/CASP and v8.1 support for T83 pass >1.0,
	 * disable for previous models.
	 */
	if ((MIDR_PARTNUM(midr) == T83PARTNUM)
	    && !(IS_OCTEONTX_PASS(midr, T83PARTNUM, 1, 0))) {
		unset_bit(cvmctl_el1, 36);  /* Enable CAS */
		unset_bit(cvmctl_el1, 37);  /* Enable CASP */
		set_bit(cvmctl_el1, 33);    /* Enable v8.1 */
	} else {
		set_bit(cvmctl_el1, 36);  /* Disable CAS */
		set_bit(cvmctl_el1, 37);  /* Disable CASP */
		unset_bit(cvmctl_el1, 33);    /* Disable v8.1 */
	}

	/* Enable prefetcher */
	set_bit(cvmctl_el1, 43);   /* Ignore the bp for next line prefetcher. */
	set_bit(cvmctl_el1, 42);   /* Use stride of 2. */
	set_bit(cvmctl_el1, 41);   /* Enable next line prefetcher. */
	set_bit(cvmctl_el1, 40);   /* Enable delta prefetcher. */

	if (MIDR_PARTNUM(midr) == T83PARTNUM) {
		set_bit(cvmmemctl1_el1, 3); /* Enable LMTST */
		set_bit(cvmmemctl1_el1, 4); /* Enable SSO/PKO addr region */
		/* Trap any accesses to nonzero node id */
		set_bit(cvmmemctl1_el1, 5);

		if (IS_OCTEONTX_PASS(midr, T83PARTNUM, 1, 0)) {
			/* Disable SSO switch tag */
			unset_bit(cvmmemctl1_el1, 6);
		} else {
			/* Enable SSO switch tag */
			set_bit(cvmmemctl1_el1, 6);
		}
	}

	/*
	 * Fix up defaults from the BDK which is broken and
	 * violates the ARM ARM.
	 */

	/* Don't reset timer on merge as that violates the ARM ARM. */
	unset_bit(cvmmemctl0_el1, 17);
	/* Set Write-buffer timeout for NSH entries to 218 cycles. */
	unset_bit(cvmmemctl0_el1, 18);

	write_cvmctl_el1(cvmctl_el1);
	write_cvmmemctl0_el1(cvmmemctl0_el1);
	write_cvmmemctl1_el1(cvmmemctl1_el1);

	/* Allow CVM CACHE instructions from EL1/EL2 */
	write_cvm_access_el1(read_cvm_access_el1() & ~(1 << 8));
	write_cvm_access_el2(read_cvm_access_el2() & ~(1 << 8));
	write_cvm_access_el3(read_cvm_access_el3() & ~(1 << 8));
}
