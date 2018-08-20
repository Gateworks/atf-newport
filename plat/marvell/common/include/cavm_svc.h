/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_SVC_H__
#define __CAVM_SVC_H__

/* SMC function IDs for Standard Service queries */

#define THUNDERX_SVC_CALL_COUNT	0x4300ff00
#define THUNDERX_SVC_UID	0x4300ff01

#define THUNDERX_SVC_VERSION	0x4300ff03

/* ThunderX Service Calls version numbers */
#define THUNDERX_VERSION_MAJOR	0x0
#define THUNDERX_VERSION_MINOR	0x3

/* x1 - node number */
#define THUNDERX_DRAM_SIZE		0x43000301

/* no args */
#define THUNDERX_NODE_COUNT		0x43000601

/* X1 - gpio_num, X2 - sp, X3 - cpu, X4 - ttbr0 */
#define THUNDERX_INSTALL_GPIO_INT	0x43000801
/* X1 - gpio_num */
#define THUNDERX_REMOVE_GPIO_INT	0x43000802

/* x1 - character to print */
#define THUNDERX_PUTC			0x43000a01

/* x1 - node number */
#if (!defined(PLAT_t81) && !defined(PLAT_t83))
#define THUNDERX_DISABLE_RVU_LFS	0x43000b01
#endif

#if (!defined(PLAT_t81) && !defined(PLAT_t83))
#define THUNDERX_NUM_CALLS		9
#else
#define THUNDERX_NUM_CALLS		8
#endif

#endif /* __THUNDER_SVC_H__ */
