/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_TWSI_H__
#define __CAVM_TWSI_H__

int octeontx_twsi_send(unsigned int twsi_num,
			uint16_t addr, const uint8_t *buffer, size_t size);
int octeontx_twsi_recv(unsigned int twsi_num,
			uint16_t addr, uint8_t *buffer, size_t size);

#endif /* __CAVM_TWSI_H__ */
