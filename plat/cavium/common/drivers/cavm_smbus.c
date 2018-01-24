/** @file

  Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <cavm_common.h>
#include <cavm_twsi_core.h>
#include <cavm_smbus.h>

#define DEBUG_ATF_SMBUS

#ifdef DEBUG_ATF_SMBUS
#define debug_smbus printf
#else
#define debug_smbus(...) ((void) (0))
#endif

/* Helper functions */
static int smbus_core_send_slave_addr(smbus_hdr_t *hdr, uint16_t slave_addr,
				      uint8_t read)
{
	int rc;
	cavm_mio_twsx_sw_twsi_t sw_twsi;

	rc = twsi_start(hdr->node, hdr->twsi_num);
	if (rc) {
		debug_smbus("SMBus: N%d.TWSI%d: Could not start transaction\n",
			    hdr->node, hdr->twsi_num);
		return rc;
	}

	sw_twsi.u = 0;
	sw_twsi.s.op = 6;
	sw_twsi.s.eop_ia = TWSI_DATA;
	sw_twsi.s.data = (uint32_t) slave_addr << 1;
	sw_twsi.s.data = ((read) ? (sw_twsi.s.data | 1) : (sw_twsi.s.data | 0));

	twsi_write_sw(hdr->node, hdr->twsi_num, sw_twsi);
	twsi_enable(hdr->node, hdr->twsi_num);

	rc = twsi_wait(hdr->node, hdr->twsi_num);
	if (rc) {
		debug_smbus("SMBus: N%d.TWSI%d: Waiting for slave 0x%x failed\n",
			    hdr->node, hdr->twsi_num, slave_addr);
		return rc;
	}

	return 0;
}

static int smbus_core_send_byte(smbus_hdr_t *hdr, uint8_t *byte)
{
	int rc;
	cavm_mio_twsx_sw_twsi_t sw_twsi;

	sw_twsi.u = 0;
	sw_twsi.s.op = 6;
	sw_twsi.s.eop_ia = TWSI_DATA;
	sw_twsi.s.data = *byte;

	twsi_write_sw(hdr->node, hdr->twsi_num, sw_twsi);
	twsi_enable(hdr->node, hdr->twsi_num);

	rc = twsi_wait(hdr->node, hdr->twsi_num);
	if (rc) {
		debug_smbus("SMBus: N%d.TWSI%d: Timeout writing data 0x%x\n",
			    hdr->node, hdr->twsi_num, *byte);
		return rc;
	}

	rc = twsi_read_status(hdr->node, hdr->twsi_num);
	debug_smbus("SMBus: N%d.TWSI%d: Status 0x%x\n",
		    hdr->node, hdr->twsi_num, rc);

	return 0;
}

static int smbus_core_receive_byte(smbus_hdr_t *hdr, uint8_t *byte)
{
	int rc;
	cavm_mio_twsx_sw_twsi_t sw_twsi;

	rc = twsi_wait(hdr->node, hdr->twsi_num);
	if (rc) {
		debug_smbus("SMBus: N%d.TWSI%d: Waiting for data failed\n",
			    hdr->node, hdr->twsi_num);
		return rc;
	}

	sw_twsi.u = twsi_read_sw(hdr->node, hdr->twsi_num, sw_twsi);
	*byte = sw_twsi.s.data;

	return 0;
}

/*
 * 	8-bit checksum algorithm: Initialize checksum to 0. For each byte,
 * 	checksum = (checksum + byte) modulo 256. Then checksum = - checksum.
 * 	When the checksum and the bytes are added together, modulo 256,
 * 	the result should be 0.
 */
static uint8_t smbus_calc_csum(uint8_t *data, size_t bytes)
{
	int i;
	uint8_t csum = 0;

	for (i = 0; i < bytes; i++) {
		csum += data[i];
	}

	return (-csum);
}

/* Functions used in smbus_execute API */
static int smbus_quick(smbus_hdr_t *hdr, uint16_t slave_addr, uint8_t read)
{
	int rc;

	assert(hdr != NULL);

	rc = smbus_core_send_slave_addr(hdr, slave_addr, read);
	if (rc) {
		debug_smbus("SMBus: Unable to execute %s", __func__);
		return -1;
	}
	/* SMBus 3.0 spec does not define the PEC check for Quick CMD */
	twsi_stop(hdr->node, hdr->twsi_num);

	return 0;
}

static int smbus_byte(smbus_hdr_t *hdr, uint16_t slave_addr, uint8_t read,
		      uint8_t pec_check, uint8_t *data, uint8_t bytes)
{
	int rc;
	uint8_t csum, buf;

	assert(hdr != NULL);
	assert(bytes == 1);

	rc = smbus_core_send_slave_addr(hdr, slave_addr, read);
	if (rc) {
		debug_smbus("SMBus: Unable to execute %s", __func__);
		return -1;
	}

	if (read) {
		if (pec_check) {
			twsi_send_ack(hdr->node, hdr->twsi_num);
			rc = smbus_core_receive_byte(hdr, data);
			if (rc) {
				debug_smbus("SMBus: Unable to receive data\n");
				return -1;
			}

			/* Do not touch received data */
			buf = *data;
			/* Calculate checksum of sent byte */
			csum = smbus_calc_csum(&buf, 1);

			twsi_enable(hdr->node, hdr->twsi_num);
			/* Receive the PEC byte */
			rc = smbus_core_receive_byte(hdr, &buf);
			if (rc) {
				debug_smbus("SMBus: Unable to receive data\n");
				return -1;
			}

			/* Compare checksums */
			if (buf != csum) {
				debug_smbus("SMBus: Checksum mismatch"
					    "received=0x%x, calculated=0x%x\n",
					    buf, csum);
				return -1;
			}
		} else {
			twsi_enable(hdr->node, hdr->twsi_num);
			rc = smbus_core_receive_byte(hdr, data);
			if (rc) {
				debug_smbus("SMBus: Unable to receive data\n");
				return -1;
			}
		}
	} else {
		rc = smbus_core_send_byte(hdr, data);
		if (rc) {
			debug_smbus("SMBus: Unable to send 0x%x\n", *data);
			return -1;
		}

		if (pec_check) {
			buf = smbus_calc_csum(data, 1);
			rc = smbus_core_send_byte(hdr, &buf);
			if (rc) {
				debug_smbus("SMBus: Unable to send PEC Byte\n");
				return -1;
			}
		}
	}

	twsi_stop(hdr->node, hdr->twsi_num);

	return 0;
}

static int smbus_write(smbus_hdr_t *hdr, uint16_t slave_addr, uint8_t command,
		       uint8_t pec_check, uint8_t *data, uint8_t bytes)
{
	int rc;
	uint8_t csum, send, *buf_ptr;

	assert(hdr != NULL);

	rc = smbus_core_send_slave_addr(hdr, slave_addr, 0);
	if (rc) {
		debug_smbus("SMBus: Unable to execute %s", __func__);
		return -1;
	}

	rc = smbus_core_send_byte(hdr, &command);
	if (rc) {
		debug_smbus("SMBus: Unable to send command %s", __func__);
		return -1;
	}

	buf_ptr = data;
	send = 0;
	while (bytes != 0) {
		rc = smbus_core_send_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to send 0x%x\n", *buf_ptr);
			return -1;
		}

		buf_ptr++;
		send++;
		bytes--;
	}

	if (pec_check) {
		csum = smbus_calc_csum(data, send);
		rc = smbus_core_send_byte(hdr, &csum);
		if (rc) {
			debug_smbus("SMBus: Unable to send PEC Byte\n");
			return -1;
		}
	}

	twsi_stop(hdr->node, hdr->twsi_num);

	return 0;
}

static int smbus_read(smbus_hdr_t *hdr, uint16_t slave_addr, uint8_t command,
		      uint8_t pec_check, uint8_t *data, uint8_t bytes)
{
	int rc;
	uint8_t buf[2], *buf_ptr, received, csum;

	assert(hdr != NULL);

	rc = smbus_core_send_slave_addr(hdr, slave_addr, 0);
	if (rc) {
		debug_smbus("SMBus: Unable to execute %s", __func__);
		return -1;
	}

	rc = smbus_core_send_byte(hdr, &command);
	if (rc) {
		debug_smbus("SMBus: Unable to send command %s", __func__);
		return -1;
	}

	/* Repeated start */
	rc = smbus_core_send_slave_addr(hdr, slave_addr, 1);
	if (rc) {
		debug_smbus("SMBus: Unable to send repeated start %s", __func__);
		return -1;
	}

	received = 0;
	buf_ptr = data;
	while (bytes > 1) {
		twsi_send_ack(hdr->node, hdr->twsi_num);
		rc = smbus_core_receive_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}

		received++;
		buf_ptr++;
		bytes--;
	}

	/* Process last byte depending on PEC value */
	if (pec_check) {
		twsi_send_ack(hdr->node, hdr->twsi_num);
		rc = smbus_core_receive_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}

		received++;
		/* Do not touch received data */
		memcpy(buf, data, received);
		/* Calculate checksum */
		csum = smbus_calc_csum(buf, received);

		twsi_enable(hdr->node, hdr->twsi_num);
		/* Receive the PEC byte */
		rc = smbus_core_receive_byte(hdr, buf);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}

		/* Compare checksums */
		if (*buf != csum) {
			debug_smbus("SMBus: Checksum mismatch"
				    "received=0x%x, calculated=0x%x\n",
				    *buf, csum);
			return -1;
		}
	} else {
		twsi_enable(hdr->node, hdr->twsi_num);
		rc = smbus_core_receive_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}
	}

	twsi_stop(hdr->node, hdr->twsi_num);

	return 0;
}

static int smbus_process_call(smbus_hdr_t *hdr, uint16_t slave_addr,
			      uint8_t command, uint8_t pec_check, uint8_t *data,
			      uint8_t bytes)
{
	int rc;
	uint8_t buf[2], csum, *buf_ptr;

	assert(hdr != NULL);
	assert(bytes == 2);

	rc = smbus_core_send_slave_addr(hdr, slave_addr, 0);
	if (rc) {
		debug_smbus("SMBus: Unable to execute %s", __func__);
		return -1;
	}

	rc = smbus_core_send_byte(hdr, &command);
	if (rc) {
		debug_smbus("SMBus: Unable to send command %s", __func__);
		return -1;
	}

	memcpy(buf, data, bytes);
	buf_ptr = buf;
	/* Send word to slave */
	while (bytes != 0) {
		rc = smbus_core_send_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to send data %s", __func__);
			return -1;
		}

		buf_ptr++;
		bytes--;
	}

	/* Repeated start */
	rc = smbus_core_send_slave_addr(hdr, slave_addr, 1);
	if (rc) {
		debug_smbus("SMBus: Unable to send repeated start %s", __func__);
		return -1;
	}

	/* Receive first 8 bits from slave */
	twsi_send_ack(hdr->node, hdr->twsi_num);
	buf_ptr = data;
	rc = smbus_core_receive_byte(hdr, buf_ptr);
	if (rc) {
		debug_smbus("SMBus: Unable to receive data\n");
		return -1;
	}
	buf_ptr++;

	if (pec_check) {
		twsi_send_ack(hdr->node, hdr->twsi_num);
		rc = smbus_core_receive_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}

		/* Do not touch received data */
		memcpy(buf, data, 2);
		/* Calculate checksum */
		csum = smbus_calc_csum(buf, 2);

		twsi_enable(hdr->node, hdr->twsi_num);
		/* Receive the PEC byte */
		rc = smbus_core_receive_byte(hdr, buf);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}

		/* Compare checksums */
		if (buf[0] != csum) {
			debug_smbus("SMBus: Checksum mismatch"
				    "received=0x%x, calculated=0x%x\n",
				    buf[0], csum);
			return -1;
		}
	} else {
		twsi_enable(hdr->node, hdr->twsi_num);
		rc = smbus_core_receive_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}
	}

	twsi_stop(hdr->node, hdr->twsi_num);

	return 0;
}

static int smbus_block_write(smbus_hdr_t *hdr, uint16_t slave_addr,
			     uint8_t command, uint8_t pec_check, uint8_t *data,
			     uint8_t bytes)
{
	int rc;
	uint8_t buf[SMBUS_MAX_BLOCK_BYTES], *buf_ptr;
	uint8_t send, csum;

	assert(hdr != NULL);
	assert(bytes <= SMBUS_MAX_BLOCK_BYTES);

	rc = smbus_core_send_slave_addr(hdr, slave_addr, 0);
	if (rc) {
		debug_smbus("SMBus: Unable to execute %s", __func__);
		return -1;
	}

	rc = smbus_core_send_byte(hdr, &command);
	if (rc) {
		debug_smbus("SMBus: Unable to send command %s", __func__);
		return -1;
	}

	rc = smbus_core_send_byte(hdr, &bytes);
	if (rc) {
		debug_smbus("SMBus: Unable to send # of bytes %s", __func__);
		return -1;
	}

	memcpy(buf, data, bytes);
	buf_ptr = buf;
	send = 0;
	while (bytes != 0) {
		rc = smbus_core_send_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to send 0x%x\n", *buf_ptr);
			return -1;
		}

		buf_ptr++;
		send++;
		bytes--;
	}

	if (pec_check) {
		csum = smbus_calc_csum(data, send);
		rc = smbus_core_send_byte(hdr, &csum);
		if (rc) {
			debug_smbus("SMBus: Unable to send PEC Byte\n");
			return -1;
		}
	}

	twsi_stop(hdr->node, hdr->twsi_num);

	return 0;
}

static int smbus_block_read(smbus_hdr_t *hdr, uint16_t slave_addr,
			     uint8_t command, uint8_t pec_check, uint8_t *data,
			     uint8_t bytes)
{
	int rc;
	uint8_t buf[SMBUS_MAX_BLOCK_BYTES], *buf_ptr;
	uint8_t csum, received, block_count;

	assert(hdr != NULL);
	assert(bytes <= SMBUS_MAX_BLOCK_BYTES);

	rc = smbus_core_send_slave_addr(hdr, slave_addr, 0);
	if (rc) {
		debug_smbus("SMBus: Unable to execute %s", __func__);
		return -1;
	}

	rc = smbus_core_send_byte(hdr, &command);
	if (rc) {
		debug_smbus("SMBus: Unable to send command %s", __func__);
		return -1;
	}

	/* Repeated start */
	rc = smbus_core_send_slave_addr(hdr, slave_addr, 1);
	if (rc) {
		debug_smbus("SMBus: Unable to send repeated start %s", __func__);
		return -1;
	}

	/* Receive the block count from slave */
	twsi_send_ack(hdr->node, hdr->twsi_num);
	rc = smbus_core_receive_byte(hdr, &block_count);
	if (rc) {
		debug_smbus("SMBus: Unable to receive data\n");
		return -1;
	}

	received = 0;
	buf_ptr = data;
	while (block_count > 1) {
		twsi_send_ack(hdr->node, hdr->twsi_num);
		rc = smbus_core_receive_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}

		received++;
		buf_ptr++;
		bytes--;
	}

	/* Process last byte depending on PEC value */
	if (pec_check) {
		twsi_send_ack(hdr->node, hdr->twsi_num);
		rc = smbus_core_receive_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}

		received++;
		/* Do not touch received data */
		memcpy(buf, data, received);
		/* Calculate checksum */
		csum = smbus_calc_csum(buf, received);

		twsi_enable(hdr->node, hdr->twsi_num);
		/* Receive the PEC byte */
		rc = smbus_core_receive_byte(hdr, buf);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}

		/* Compare checksums */
		if (buf[0] != csum) {
			debug_smbus("SMBus: Checksum mismatch"
				    "received=0x%x, calculated=0x%x\n",
				    buf[0], csum);
			return -1;
		}
	} else {
		twsi_enable(hdr->node, hdr->twsi_num);
		rc = smbus_core_receive_byte(hdr, buf_ptr);
		if (rc) {
			debug_smbus("SMBus: Unable to receive data\n");
			return -1;
		}
	}

	twsi_stop(hdr->node, hdr->twsi_num);

	return 0;
}

static int smbus_host_notify(smbus_hdr_t *hdr, uint16_t slave_addr,
			     uint8_t *data, uint8_t bytes)
{
	int rc;
	uint8_t *buf_ptr;
	cavm_mio_twsx_sw_twsi_t sw_twsi;

	assert(bytes == 2);

	rc = twsi_start(hdr->node, hdr->twsi_num);
	if (rc) {
		debug_smbus("SMBus: N%d.TWSI%d: Could not start transaction\n",
			    hdr->node, hdr->twsi_num);
		return rc;
	}

	sw_twsi.u = 0;
	sw_twsi.s.op = 6;
	sw_twsi.s.eop_ia = TWSI_DATA;
	sw_twsi.s.data = (uint32_t) SMBUS_HOST_ADDR << 1;

	twsi_write_sw(hdr->node, hdr->twsi_num, sw_twsi);
	twsi_enable(hdr->node, hdr->twsi_num);

	rc = twsi_wait(hdr->node, hdr->twsi_num);
	if (rc) {
		debug_smbus("SMBus: N%d.TWSI%d: Unable to send SMB Host Addr\n",
			    hdr->node, hdr->twsi_num);
		return rc;
	}

	sw_twsi.u = 0;
	sw_twsi.s.op = 6;
	sw_twsi.s.eop_ia = TWSI_DATA;
	sw_twsi.s.data = (uint32_t)slave_addr << 1;

	twsi_write_sw(hdr->node, hdr->twsi_num, sw_twsi);
	twsi_enable(hdr->node, hdr->twsi_num);

	rc = twsi_wait(hdr->node, hdr->twsi_num);
	if (rc) {
		debug_smbus("SMBus: N%d.TWSI%d: Timeout writing data 0x%x\n",
			    hdr->node, hdr->twsi_num, (slave_addr << 1));
		return rc;
	}

	rc = twsi_read_status(hdr->node, hdr->twsi_num);
	debug_smbus("SMBus: N%d.TWSI%d: Status 0x%x\n",
		    hdr->node, hdr->twsi_num, rc);

	buf_ptr = data;
	rc = smbus_core_send_byte(hdr, buf_ptr);
	if (rc) {
		debug_smbus("SMBus: Unable to send 0x%x\n", *buf_ptr);
		return -1;
	}

	buf_ptr++;
	rc = smbus_core_send_byte(hdr, buf_ptr);
	if (rc) {
		debug_smbus("SMBus: Unable to send 0x%x\n", *buf_ptr);
		return -1;
	}

	twsi_stop(hdr->node, hdr->twsi_num);

	return 0;
}

static void smbus_init(smbus_hdr_t *hdr, unsigned int node,
		       unsigned int twsi_num, uint8_t pec_check)
{
	hdr->node = node;
	hdr->twsi_num = twsi_num;
	hdr->pec_check = pec_check;
}

/* SMBus API */
int smbus_execute(unsigned int node, unsigned int twsi_num, uint8_t pec_check,
		  uint16_t slave_addr, uint8_t command, smbus_op_t operation,
		  uint8_t *data, uint8_t bytes)
{
	int rc;
	smbus_hdr_t hdr;
	smbus_init(&hdr, node, twsi_num, pec_check);

	switch (operation) {
		case SMBUS_QUICK_READ:
			rc = smbus_quick(&hdr, slave_addr, 1);
			break;
		case SMBUS_QUICK_WRITE:
			rc = smbus_quick(&hdr, slave_addr, 0);
			break;
		case SMBUS_RECEIVE_BYTE:
			rc = smbus_byte(&hdr, slave_addr, 1, pec_check, data,
					bytes);
			break;
		case SMBUS_SEND_BYTE:
			rc = smbus_byte(&hdr, slave_addr, 0, pec_check, data,
					bytes);
			break;
		case SMBUS_READ_BYTE:
			rc = smbus_read(&hdr, slave_addr, command,
					pec_check, data, 1);
			break;
		case SMBUS_WRITE_BYTE:
			rc = smbus_write(&hdr, slave_addr, command,
					 pec_check, data, 1);
			break;
		case SMBUS_READ_WORD:
			rc = smbus_read(&hdr, slave_addr, command,
					pec_check, data, 2);
			break;
		case SMBUS_WRITE_WORD:
			rc = smbus_write(&hdr, slave_addr, command,
					 pec_check, data, 2);
			break;
		case SMBUS_PROCESS_CALL:
			rc = smbus_process_call(&hdr, slave_addr, command,
						pec_check, data, 2);
			break;
		case SMBUS_BLOCK_READ:
			rc = smbus_block_read(&hdr, slave_addr, command,
					      pec_check, data, bytes);
			break;
		case SMBUS_BLOCK_WRITE:
			rc = smbus_block_write(&hdr, slave_addr, command,
					       pec_check, data, bytes);
			break;
		case SMBUS_HOST_NOTIFY:
			rc = smbus_host_notify(&hdr, slave_addr, data, bytes);
			break;
		default:
			rc = -1;
			break;
	}

	return rc;
}
