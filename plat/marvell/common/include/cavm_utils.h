/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_UTILS_H__
#define __CAVM_UTILS_H__

#define cavm_read8(addr)       (*(volatile uint8_t *)(addr))
#define cavm_read16(addr)      cavm_le16_to_cpu(*(volatile uint16_t *)(addr))
#define cavm_read32(addr)      cavm_le32_to_cpu(*(volatile uint32_t *)(addr))
#define cavm_read64(addr)      cavm_le64_to_cpu(*(volatile uint64_t *)(addr))

#define cavm_write8(addr, val) (*(volatile uint8_t *)(addr) = (val))
#define cavm_write16(addr, val)        (*(volatile uint16_t *)(addr) = cavm_cpu_to_le16((val)))
#define cavm_write32(addr, val)        (*(volatile uint32_t *)(addr) = cavm_cpu_to_le32((val)))
#define cavm_write64(addr, val)        (*(volatile uint64_t *)(addr) = cavm_cpu_to_le64((val)))

/**
 * Macro to get the physical address of a CSR on a node
 */
#define CSR_PA(node, csr) ((csr) | ((uint64_t)(node) << 44))

#endif /* __CAVM_UTILS_H__ */