/** @file

  Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
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
#include <cavm_common.h>
#include <cavm_cgx_intf.h>
#include <cavm_cgx.h>
#include <cavm_setup.h>
#include <cavm_pwrc.h>
#include <cavm_legacy_pwrc.h>
#include <cavm_gpio.h>
#include <cavm_dt.h>

/* Any SoC family specific setup
 * to be done in BL31 can be initialized
 * in this API. If there are any platform
 * specific init to be done but not common
 * to family, each platform can define
 * its own API and can be called from here
 */
void plat_cavm_setup(void)
{
	/* Initialize CGX framework */
	cgx_fw_intf_init();

	/* setup gpio interrupt handling */
	plat_gpio_irq_setup();
}

const uintptr_t plat_get_scmi_mbox_addr(int node)
{
	return CSR_PA(node, CAVM_CPC_RAM_MEMX(AP_SECURE0_TO_XCP_MBOX_OFFSET));
}

const uintptr_t plat_get_scmi_db_addr(int node)
{
	return CSR_PA(node, CAVM_XCPX_DEVX_XCP_MBOX(
			    CAVM_CPC_XCP_MAP_E_SCP,
			    CAVM_XCP_MBOX_DEV_E_AP_SECURE0));
}

extern void *scmi_handle;

void plat_pwrc_setup(void)
{
	int rc;

	/*
	 * Try to initialize SCMI, in case of error,
	 * fallback to legacy PM driver
	 */
	rc = cavm_pwrc_setup();
	if (rc) {
		cavm_legacy_pwrc_setup();
	}
}

void plat_setup_psci_ops(uintptr_t sec_entrypoint,
			 const plat_psci_ops_t **psci_ops)
{
	if (scmi_handle == NULL) {
		cavm_legacy_setup_psci_ops(sec_entrypoint, psci_ops);
	} else {
		cavm_setup_psci_ops(sec_entrypoint, psci_ops);
	}
}

/*
 * fuse parameter should be one of the fuse enum - FUS_FUSE_NUM_E
 * for which the value to be read
 */
int plat_fuse_read(int node, int fuse)
{
	uint64_t fus_val;
	int byte_addr = FUSE_BIT_TO_BYTE_ADDR(fuse);

	/* read the cache register to obtain the fuse state
	 * FUS_CACHEX() operates on 64-bit and indexed by
	 * FUS_FUSE_NUM_E
	 */
	fus_val = CSR_READ(node, CAVM_FUS_CACHEX(byte_addr >> 3));
	fus_val >>= (byte_addr & 7) << 3;
	return FUSE_GET_VAL(fus_val, fuse);
}

/*
 * Get ROM_T_CNT value from the FUSF_RCMD
 *
 * Return: Value in 0-32 range
 */
unsigned int plat_get_rom_t_cnt(int node)
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
	CSR_WRITE(node, CAVM_FUSF_RCMD, read_cmd.u);
	do {
		read_cmd.u = CSR_READ(node, CAVM_FUSF_RCMD);
	} while (read_cmd.s.pend);

	/* ASIM returns 0 on FUSF_RCMD accesses */
	if (!strncmp(bfdt->board_model, "asim-", 5))
		dat = CSR_READ(node, CAVM_FUSF_CTL);
	else
		dat = CSR_READ(node, CAVM_FUSF_BNK_DATX(0));

	/*
	 * FUSF_BNK_DATX contains all 128 fuses
	 * in the bank associated with FUSF_RCMD[ADDR].
	 * ROM_T_CNT is stored on FUSF_BNK_DATX(0)[63:32]
	 */
	nv_count_val = cavm_bit_extract(dat, CAVM_FUSF_FUSE_NUM_E_ROM_T_CNTX(0), 32);

	/* Convert value from rom_t_cnt to unsigned int */
	if (nv_count_val)
		ret = 32 - __builtin_clz(nv_count_val);

	return ret;
}
