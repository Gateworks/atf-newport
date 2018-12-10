/*
 * Copyright (C) 2017-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <stdint.h>
#include <stdio.h>
#include <timers.h>
#include <platform_def.h>
#include <debug.h>
#include <assert.h>
#include <octeontx_common.h>
#include <hw_timers.h>
#include <delay_timer.h>
#include <string.h>
#include <smi.h>

/* SMI driver for OcteonTX (CN8xxx and CN9xxx) */

#undef DEBUG_ATF_SMI

#ifdef DEBUG_ATF_SMI
#define debug_smi(...) printf(__VA_ARGS__)
#else
#define debug_smi(...) ((void) (0))
#endif

static void smi_setmode(int bus_id, int mode)
{
	union cavm_smi_x_clk smix_clk;

	smix_clk.u = CSR_READ(CAVM_SMI_X_CLK(bus_id));
	smix_clk.s.mode = mode;
	smix_clk.s.preamble = mode == CLAUSE45;
	CSR_WRITE(CAVM_SMI_X_CLK(bus_id), smix_clk.u);
}

static int smi_c45_addr(int bus_id, int addr, int devad, int regnum)
{
	union cavm_smi_x_cmd smix_cmd;
	union cavm_smi_x_wr_dat smix_wr_dat;
	unsigned long timeout = MDIO_TIMEOUT;

	smix_wr_dat.u = 0;
	smix_wr_dat.s.dat = regnum;

	CSR_WRITE(CAVM_SMI_X_WR_DAT(bus_id), smix_wr_dat.u);

	smix_cmd.u = 0;
	smix_cmd.s.phy_op = SMI_OP_C45_ADDR;
	smix_cmd.s.phy_adr = addr;
	smix_cmd.s.reg_adr = devad;

	CSR_WRITE(CAVM_SMI_X_CMD(bus_id), smix_cmd.u);

	do {
		smix_wr_dat.u = CSR_READ(CAVM_SMI_X_WR_DAT(bus_id));
		udelay(100);
		timeout--;
	} while (smix_wr_dat.s.pending && timeout);

	return timeout == 0;
}

int smi_read(int bus_id, int mode, int addr, int devad, int regnum)
{
	union cavm_smi_x_cmd smix_cmd;
	union cavm_smi_x_rd_dat smix_rd_dat;
	unsigned long timeout = MDIO_TIMEOUT;
	int ret;

	debug_smi("RD: Mode: %u, addr: %d, devad: %d, reg: %d\n",
	      mode, addr, devad, regnum);

	smi_setmode(bus_id, mode);

	if (mode == CLAUSE45) {
		ret = smi_c45_addr(bus_id, addr, devad, regnum);

		debug_smi("RD: ret: %u\n", ret);

		if (ret)
			return 0;
	}

	smix_cmd.u = 0;
	smix_cmd.s.phy_adr = addr;


	if (mode == CLAUSE45) {
		smix_cmd.s.reg_adr = devad;
		smix_cmd.s.phy_op = SMI_OP_C45_READ;
	} else {
		smix_cmd.s.reg_adr = regnum;
		smix_cmd.s.phy_op = SMI_OP_C22_READ;
	}

	CSR_WRITE(CAVM_SMI_X_CMD(bus_id), smix_cmd.u);

	do {
		smix_rd_dat.u = CSR_READ(CAVM_SMI_X_RD_DAT(bus_id));
		udelay(10);
		timeout--;
	} while (smix_rd_dat.s.pending && timeout);

	debug_smi("SMIX_RD_DAT: %lx\n", (unsigned long)smix_rd_dat.u);

	return smix_rd_dat.s.dat;
}

int smi_write(int bus_id, int addr, int devad,
			 int mode, int regnum, uint16_t value)
{
	union cavm_smi_x_cmd smix_cmd;
	union cavm_smi_x_wr_dat smix_wr_dat;
	unsigned long timeout = MDIO_TIMEOUT;
	int ret;

	debug_smi("WR: Mode: %u, addr: %d, devad: %d, reg: %d\n",
	      mode, addr, devad, regnum);

	if (mode == CLAUSE45) {
		ret = smi_c45_addr(bus_id, addr, devad, regnum);

		debug_smi("WR: ret: %u\n", ret);

		if (ret)
			return ret;
	}

	smix_wr_dat.u = 0;
	smix_wr_dat.s.dat = value;

	CSR_WRITE(CAVM_SMI_X_WR_DAT(bus_id), smix_wr_dat.u);

	smix_cmd.u = 0;
	smix_cmd.s.phy_adr = addr;

	if (mode == CLAUSE45) {
		smix_cmd.s.reg_adr = devad;
		smix_cmd.s.phy_op = SMI_OP_C45_WRITE;
	} else {
		smix_cmd.s.reg_adr = regnum;
		smix_cmd.s.phy_op = SMI_OP_C22_WRITE;
	}

	CSR_WRITE(CAVM_SMI_X_CMD(bus_id), smix_cmd.u);

	do {
		smix_wr_dat.u = CSR_READ(CAVM_SMI_X_WR_DAT(bus_id));
		udelay(10);
		timeout--;
	} while (smix_wr_dat.s.pending && timeout);

	debug_smi("SMIX_WR_DAT: %lx\n", (unsigned long)smix_wr_dat.u);

	return timeout == 0;
}

int smi_reset(int bus_id)
{
	union cavm_smi_x_en smi_en;

	smi_en.s.en = 0;
	CSR_WRITE(CAVM_SMI_X_EN(bus_id), smi_en.u);

	smi_en.s.en = 1;
	CSR_WRITE(CAVM_SMI_X_EN(bus_id), smi_en.u);

	return 0;
}
