/** @file

  Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <cavm_common.h>
#include <cavm_twsi_core.h>

#undef DEBUG_ATF_TWSI

#ifdef DEBUG_ATF_TWSI
#define debug_twsi printf
#else
#define debug_twsi(...) ((void) (0))
#endif

int thunder_twsi_send(unsigned int node, unsigned int twsi_num,
		      uint16_t addr, const uint8_t *buffer, size_t size)
{
	cavm_mio_twsx_sw_twsi_t sw_twsi;
	int rc;
	size_t curr = 0;

	rc = twsi_start(node, twsi_num);
	if (rc) {
		debug_twsi("N%d.TWSI%d: Could not start bus transaction\n",
			   node, twsi_num);
		return rc;
	}

	sw_twsi.u = 0;
	sw_twsi.s.op = 6;
	sw_twsi.s.eop_ia = TWSI_DATA;
	sw_twsi.s.data = (uint32_t) addr << 1;

	twsi_write_sw(node, twsi_num, sw_twsi);
	twsi_enable(node, twsi_num);

	rc = twsi_wait(node, twsi_num);
	if (rc) {
		debug_twsi("N%d.TWSI%d: Timed out writing slave addr 0x%x\n",
			   node, twsi_num, addr);
		return rc;
	}

	rc = twsi_read_status(node, twsi_num);
	if (rc != TWSI_STAT_TXADDR_ACK) {
		debug_twsi("N%d.TWSI%d: Status 0x%x\n", node, twsi_num, rc);
		return rc;
	}

	while (curr < size) {
		sw_twsi.u = 0;
		sw_twsi.s.op = 6;
		sw_twsi.s.eop_ia = TWSI_DATA;
		sw_twsi.s.data = buffer[curr++];

		twsi_write_sw(node, twsi_num, sw_twsi);
		twsi_enable(node, twsi_num);

		rc = twsi_wait(node, twsi_num);
		if (rc) {
			debug_twsi("N%d.TWSI%d: Timeout writing data to 0x%x\n",
				   node, twsi_num, addr);
			return rc;
		}

		rc = twsi_read_status(node, twsi_num);
		debug_twsi("N%d.TWSI%d: Status 0x%x\n",
			   node, twsi_num, addr);
	}

	twsi_stop(node, twsi_num);
	return 0;
}

int thunder_twsi_recv(unsigned int node, unsigned int twsi_num,
		      uint16_t addr, uint8_t *buffer, size_t size)
{
	cavm_mio_twsx_sw_twsi_t sw_twsi;
	int rc;
	size_t curr = 0;

	rc = twsi_start(node, twsi_num);
	if (rc) {
		debug_twsi("N%d.TWSI%d: Could not start bus transaction\n",
			   node, twsi_num);
		return rc;
	}

	sw_twsi.u = 0;
	sw_twsi.s.op = 6;
	sw_twsi.s.eop_ia = TWSI_DATA;
	sw_twsi.s.data = (uint32_t) (addr << 1) | 1;

	twsi_write_sw(node, twsi_num, sw_twsi);
	twsi_enable(node, twsi_num);

	rc = twsi_wait(node, twsi_num);
	if (rc) {
		debug_twsi("N%d.TWSI%d: Waiting for slave 0x%x failed\n",
			   node, twsi_num, addr);
		return rc;
	}

	rc = twsi_read_status(node, twsi_num);
	if (rc != TWSI_STAT_RXADDR_ACK) {
		debug_twsi("N%d.TWSI%d: Status 0x%x\n", node, twsi_num, rc);
		return rc;
	}

	while (curr < size) {
		if (curr < (size - 1))
			twsi_send_ack(node, twsi_num);
		else
			twsi_enable(node, twsi_num);

		rc = twsi_wait(node, twsi_num);
		if (rc) {
			debug_twsi("N%d.TWSI%d: Waiting for data failed 0x%x\n",
				   node, twsi_num, addr);
			return rc;
		}

		sw_twsi.u = twsi_read_sw(node, twsi_num, sw_twsi);
		buffer[curr++] = sw_twsi.s.data;
	}

	twsi_stop(node, twsi_num);
	return 0;
}
