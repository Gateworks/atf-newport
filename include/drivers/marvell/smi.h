/*
 * Copyright (C) 2017-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __SMI_H__
#define __SMI_H__

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

int smi_phy_read(int bus_id, int mode,
			int addr, int devad, int regnum);

int smi_phy_write(int bus_id, int addr, int devad,
			 int mode, int regnum, uint16_t value);

int smi_phy_reset(int bus_id);

#endif /* __SMI_H__ */
