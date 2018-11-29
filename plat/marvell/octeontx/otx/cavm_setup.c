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
#include <platform_def.h>
#include <cavm_common.h>
#include <cavm_legacy_pwrc.h>
#include <cavm_gpio.h>
#include <plat_cavm.h>
#include <cavm_fuse.h>
#include <cavm_utils.h>

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
