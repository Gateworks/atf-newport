/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __PLAT_FUSE_H__
#define __PLAT_FUSE_H__

/* Utils macro for fuses usage */
#define FUSE_BIT_TO_BYTE_ADDR_SHIFT	0x3
#define FUSE_BIT_TO_BYTE_ADDR(addr)	((addr) >> FUSE_BIT_TO_BYTE_ADDR_SHIFT)
#define FUSE_HI_ADDR_SHIFT		0x8
#define FUSE_HI_ADDR(addr)		((addr) >> FUSE_HI_ADDR_SHIFT)
#define FUSE_BYTE_ADDR_MASK		0x7
#define FUSE_BIT_SET			0x1
#define FUSE_GET_VAL(dat, fuse)		(((uint8_t)dat) >> ((fuse) & FUSE_BYTE_ADDR_MASK) & FUSE_BIT_SET)

int plat_fuse_read(int fuse);

#endif /* __PLAT_FUSE_H__ */