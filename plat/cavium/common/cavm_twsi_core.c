/** @file

  Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#include <stddef.h>
#include <assert.h>
#include <platform_def.h>
#include <delay_timer.h>
#include <stdio.h>
#include <cavm_common.h>
#include <cavm_twsi_core.h>

#undef DEBUG_ATF_TWSI

#ifdef DEBUG_ATF_TWSI
#define debug_twsi printf
#else
#define debug_twsi(...) ((void) (0))
#endif

uint64_t tz_count(uint64_t x)
{
	uint64_t ret = 0;

	if (!x) {
		ret = 64;
	} else {
		ret += (x & 0x00000000ffffffff) ? 0 : 32;
		ret += (x & 0x0000ffff0000ffff) ? 0 : 16;
		ret += (x & 0x00ff00ff00ff00ff) ? 0 : 8;
		ret += (x & 0x0f0f0f0f0f0f0f0f) ? 0 : 4;
		ret += (x & 0x3333333333333333) ? 0 : 2;
		ret += (x & 0x5555555555555555) ? 0 : 1;
	}

	return ret;
}

uint64_t twsi_write_sw(unsigned int node, unsigned int twsi_num,
			      cavm_mio_twsx_sw_twsi_t sw_twsi)
{
	int timeout = 10000;
	sw_twsi.s.r = 0;
	sw_twsi.s.v = 1;

	assert(twsi_num < TWSI_NUM);

	CSR_WRITE(node, CAVM_MIO_TWSX_SW_TWSI(twsi_num), sw_twsi.u);

	do {
		sw_twsi.u = CSR_READ(node, CAVM_MIO_TWSX_SW_TWSI(twsi_num));
	} while (timeout-- && (sw_twsi.s.v != 0));

	if (sw_twsi.s.v)
		debug_twsi("%s: Timed out\n", __func__);

	return sw_twsi.u;
}

uint64_t twsi_read_sw(unsigned int node, unsigned int twsi_num,
			     cavm_mio_twsx_sw_twsi_t sw_twsi)
{
	int timeout = 10000;
	sw_twsi.s.r = 1;
	sw_twsi.s.v = 1;

	assert(twsi_num < TWSI_NUM);

	CSR_WRITE(node, CAVM_MIO_TWSX_SW_TWSI(twsi_num), sw_twsi.u);

	do {
		sw_twsi.u = CSR_READ(node, CAVM_MIO_TWSX_SW_TWSI(twsi_num));
	} while (timeout-- && (sw_twsi.s.v != 0));

	if (sw_twsi.s.v)
		debug_twsi("%s: Timed out\n", __func__);

	return sw_twsi.u;
}

uint8_t twsi_read_status(unsigned int node, unsigned int twsi_num)
{
	cavm_mio_twsx_sw_twsi_t sw_twsi;

	sw_twsi.u = 0;
	sw_twsi.s.op = 0x6;
	sw_twsi.s.eop_ia = TWSI_STAT;

	return twsi_read_sw(node, twsi_num, sw_twsi);
}

void twsi_write_ctl(unsigned int node, unsigned int twsi_num, uint8_t data)
{
	cavm_mio_twsx_sw_twsi_t sw_twsi;

	sw_twsi.u = 0;
	sw_twsi.s.op = 0x6;
	sw_twsi.s.eop_ia = TWSI_CTL;
	sw_twsi.s.data = data;

	twsi_write_sw(node, twsi_num, sw_twsi);
}

uint8_t twsi_read_ctl(unsigned int node, unsigned int twsi_num)
{
	cavm_mio_twsx_sw_twsi_t sw_twsi;

	sw_twsi.u = 0;
	sw_twsi.s.op = 0x6;
	sw_twsi.s.eop_ia = TWSI_CTL;

	return twsi_read_sw(node, twsi_num, sw_twsi);
}

int twsi_wait(unsigned int node, unsigned int twsi_num)
{
	unsigned int timeout = 500000;
	uint8_t twsi_ctl;

	do {
		twsi_ctl = twsi_read_ctl(node, twsi_num);
		twsi_ctl &= TWSI_CTL_IFLG;
	} while (timeout-- && !twsi_ctl);

	return !twsi_ctl;
}

void twsi_enable(unsigned int node, unsigned int twsi_num)
{
	uint8_t twsi_ctl = TWSI_CTL_ENAB;

	twsi_write_ctl(node, twsi_num, twsi_ctl);
}

void twsi_recover_bus(unsigned int node, unsigned int twsi_num)
{
	cavm_mio_twsx_int_t twsi_int;
	int i;

	twsi_int.u = CSR_READ(node, CAVM_MIO_TWSX_INT(twsi_num));

	for (i = 0; i < TWSI_RECOVERY_UDELAY; i++) {
		if (!twsi_int.s.scl_ovr) {
			/* SCL shouldn't be low here */
			if (!twsi_int.s.scl) {
				debug_twsi("N%d.TWSI%d: SCL is stuck low\n",
				      node, twsi_num);
				return;
			}

			/* Break if SDA is high */
			if (twsi_int.s.sda)
				break;
		}

		twsi_int.s.scl_ovr = !twsi_int.s.scl_ovr;
		CSR_WRITE(node, CAVM_MIO_TWSX_INT(twsi_num), twsi_int.u);
		udelay(TWSI_RECOVERY_UDELAY);
	}

	twsi_int.s.scl_ovr = 1;
	twsi_int.s.sda_ovr = 1;
	CSR_WRITE(node, CAVM_MIO_TWSX_INT(twsi_num), twsi_int.u);
	udelay(TWSI_RECOVERY_UDELAY);
	twsi_int.s.scl_ovr = 0;
	CSR_WRITE(node, CAVM_MIO_TWSX_INT(twsi_num), twsi_int.u);
	udelay(TWSI_RECOVERY_UDELAY);
	twsi_int.s.sda_ovr = 0;
	CSR_WRITE(node, CAVM_MIO_TWSX_INT(twsi_num), twsi_int.u);
	udelay(TWSI_RECOVERY_UDELAY);
}

int twsi_stop(unsigned int node, unsigned int twsi_num)
{
	uint8_t stat, twsi_ctl;

	twsi_ctl = TWSI_CTL_STP | TWSI_CTL_ENAB;
	twsi_write_ctl(node, twsi_num, twsi_ctl);

	stat = twsi_read_status(node, twsi_num);
	if (stat != TWSI_STAT_IDLE) {
		debug_twsi("N%d.TWSI%d: Bad status: 0x%x\n",
			   node, twsi_num, stat);
		return -1;
	}

	return 0;
}

int twsi_start(unsigned int node, unsigned int twsi_num)
{
	uint8_t twsi_ctl = TWSI_CTL_STA | TWSI_CTL_ENAB;
	int rc;
	uint8_t stat;

	twsi_write_ctl(node, twsi_num, twsi_ctl);

	rc = twsi_wait(node, twsi_num);
	if (rc) {
		stat = twsi_read_status(node, twsi_num);
		switch (stat) {
			case TWSI_STAT_START:
			case TWSI_STAT_RSTART:
				return 0;
			default:
				twsi_stop(node, twsi_num);
				twsi_recover_bus(node, twsi_num);
				return -1;
		}
	}

	return 0;
}

void twsi_send_ack(unsigned int node, unsigned int twsi_num)
{
	uint8_t twsi_ctl = TWSI_CTL_AAK | TWSI_CTL_ENAB;

	twsi_write_ctl(node, twsi_num, twsi_ctl);
}

void twsi_set_speed(unsigned int node, unsigned int twsi_num, unsigned int speed)
{
	cavm_mio_twsx_sw_twsi_t sw_twsi;
	cavm_rst_boot_t rst_boot;
	uint8_t twsi_clkctl;
	unsigned int div_n, div_m, div_d;
	unsigned long pnr_clk, tclk;
	unsigned long thp;

	rst_boot.u = CSR_READ(node, CAVM_RST_BOOT);

	pnr_clk = rst_boot.s.pnr_mul * PLL_REF_CLK;

	sw_twsi.u = 0;
	sw_twsi.s.eop_ia = 0x4;

	thp = twsi_read_sw(node, twsi_num, sw_twsi);

	tclk = pnr_clk / (2 * (thp + 1));

	div_d = (speed > 400000) ? 15 : 10;

	div_n = tz_count(tclk / (speed * div_d));
	div_m = (tclk / (speed * div_d)) >> div_n;

	twsi_clkctl = ((div_m - 1) << TWSI_CLKCTL_MS) | (div_n << TWSI_CLKCTL_NS);

	sw_twsi.u = 0;
	sw_twsi.s.op = 0x6;
	sw_twsi.s.eop_ia = TWSI_CLKCTL;
	sw_twsi.s.data = twsi_clkctl;

	twsi_write_sw(node, twsi_num, sw_twsi);
}


