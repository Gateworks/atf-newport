/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <string.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <plat_board_cfg.h>
#include <smi.h>
#include <cgx_intf.h>
#include <cgx.h>
#include <phy_marvell.h>
#include <phy_mgmt.h>

typedef phy_drv_t *(*phy_drv_check_type_t)(int);

phy_drv_check_type_t marvell_drv[] = {
	marvell_1514_check_type,
#ifdef MARVELL_PHY_5123
	marvell_5123_check_type,
#endif /* MARVELL_PHY_5123 */
	marvell_5113_check_type,
#ifdef MARVELL_PHY_6141
	marvell_6141_check_type,
#endif /* MARVELL_PHY_6141 */
#ifdef MARVELL_PHY_1548
	marvell_1548_check_type,
#endif /* MARVELL_PHY_1548 */
};

phy_drv_t *phy_marvell_drv_lookup(int type)
{
	phy_drv_t *drv;

	for (int i = 0; i < ARRAY_SIZE(marvell_drv); i++) {
		drv = marvell_drv[i](type);
		if (drv != NULL) {
			debug_phy_driver(
				"%s: found matching MARVELL PHY driver for type %d\n",
				__func__, type);
			return drv;
		}
	}
	return NULL;
}
