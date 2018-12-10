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
#include <plat_board_cfg.h>
#include <cgx.h>
#include <sfp_intf.h>
#include <phy_mgmt.h>
#include <smi.h>
#include <twsi.h>

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

void smi_set_switch(phy_config_t *phy, int enable)
{
	uint8_t data[2], reg_val = 0x0;
	int ret;
	static uint8_t reg_read_mask;

	debug_smi("%s: enable %d reg_read_mask 0x%x\n",
			__func__, enable, reg_read_mask);

	if (phy->mux_switch) {
		if (phy->mux_info.pin > phy->mux_info.num_pins) {
			ERROR("%s: Invalid pin\n", __func__);
			return;
		}

		switch (phy->mux_info.type) {
		/* For now, handle only 8-bit CPLD controller for MDIO MUX */
		case GPIO_PIN_CPLD:
			data[0] = (phy->mux_info.pin >> 3); /* Internal Addr */
			reg_val = (1 << (phy->mux_info.pin & 7));
			if (enable)
				data[1] = reg_read_mask |= reg_val;
			else
				data[1] = reg_read_mask &= ~reg_val;
			/* Reading the register via TWSI and toggle the bit
			 * again via TWSI write seems expensive. Build a
			 * reg mask at the end of every input and use it
			 * for this internal ADDR. This internal ADDR is used
			 * only for MDIO switch and it is safe to do so fornow.
			 */
			reg_read_mask |= data[1];
			break;
		default:
			data[0] = 0;
			data[1] = 0;
			return; /* No other cases handled */
		};

		debug_smi("%s: Switch %d MUX type %d Int Addr 0x%x Bit %d\n",
				__func__, phy->mux_switch, phy->mux_info.type,
				phy->mux_info.pin >> 3, phy->mux_info.pin & 7);

		/* Don't perform the TWSI operation for ASIM platform */
		if (strncmp(plat_octeontx_bcfg->bcfg.board_model, "asim-", 5)) {
			ret = octeontx_twsi_send(phy->mux_info.i2c_bus,
					phy->mux_info.i2c_addr,
					data,
					sizeof(data));
			if (ret) {
				ERROR("%s TWSI write to GPIO controller reg 0x%x failed\n",
					__func__, phy->mux_info.i2c_addr);
				return;
			}
		}
	}
}
