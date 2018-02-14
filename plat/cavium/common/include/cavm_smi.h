/** @file

  Copyright (c) 2017-2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#define MDIO_TIMEOUT 10000

enum {
	CLAUSE22 = 0,
	CLAUSE45 = 1,
};

enum {
	SMI_OP_C22_WRITE = 0,
	SMI_OP_C22_READ = 1,

	SMI_OP_C45_ADDR = 0,
	SMI_OP_C45_WRITE = 1,
	SMI_OP_C45_PRIA = 2,
	SMI_OP_C45_READ = 3,
};

int smi_phy_read(int node, int bus_id, int mode,
			int addr, int devad, int regnum);

int smi_phy_write(int node, int bus_id, int addr, int devad,
			 int mode, int regnum, uint16_t value);

int smi_phy_reset(int node, int bus_id);
