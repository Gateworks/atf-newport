/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <string.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <cgx_intf.h>
#include <cgx.h>
#include <cavm_pwrc.h>
#include <octeontx_legacy_pwrc.h>
#include <gpio_octeontx.h>
#include <cavm_dt.h>
#include <cavm_flr.h>
#include <plat_octeontx.h>
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
	/* Initialize CGX framework */
	cgx_fw_intf_init();

	/* setup gpio interrupt handling */
	plat_gpio_irq_setup();

	/* Workaround for FLR handling on CN9xxx */
	plat_flr_init();
}

extern void *scmi_handle;

void plat_pwrc_setup(void)
{
	int rc;

	/*
	 * Try to initialize SCMI, in case of error,
	 * fallback to legacy PM driver
	 */
	rc = octeontx_pwrc_setup();
	if (rc) {
		octeontx_legacy_pwrc_setup();
	}
}

void plat_setup_psci_ops(uintptr_t sec_entrypoint,
			 const plat_psci_ops_t **psci_ops)
{
	if (scmi_handle == NULL) {
		octeontx_legacy_setup_psci_ops(sec_entrypoint, psci_ops);
	} else {
		octeontx_setup_psci_ops(sec_entrypoint, psci_ops);
	}
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
