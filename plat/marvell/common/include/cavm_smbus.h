/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_SMBUS_H__
#define __CAVM_SMBUS_H__

#define SMBUS_HOST_ADDR		0x08
#define SMBUS_MAX_BLOCK_BYTES	255

typedef enum {
	SMBUS_QUICK_READ,
	SMBUS_QUICK_WRITE,
	SMBUS_RECEIVE_BYTE,
	SMBUS_SEND_BYTE,
	SMBUS_READ_BYTE,
	SMBUS_WRITE_BYTE,
	SMBUS_READ_WORD,
	SMBUS_WRITE_WORD,
	SMBUS_PROCESS_CALL,
	SMBUS_BLOCK_READ,
	SMBUS_BLOCK_WRITE,
	SMBUS_HOST_NOTIFY
} smbus_op_t;

typedef struct smbus_hdr {
	unsigned int	node;
	unsigned int	twsi_num;
	uint8_t		pec_check;
} smbus_hdr_t;

int smbus_execute(unsigned int node, unsigned int twsi_num, uint8_t pec_check,
		  uint16_t slave_addr, uint8_t command, smbus_op_t operation,
		  uint8_t *data, uint8_t bytes);
#endif
