/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PHY_MARVELL_H__
#define __PHY_MARVELL_H__

#include <phy_mgmt.h>

/* define DEBUG_ATF_MARVELL_PHY_DRIVER to enable debug logs */
#ifdef DEBUG_ATF_MARVELL_PHY_DRIVER
#define debug_phy_driver printf
#else
#define debug_phy_driver(...) ((void) (0))
#endif

phy_drv_t *marvell_1514_check_type(int type);
#ifdef MARVELL_PHY_1548
phy_drv_t *marvell_1548_check_type(int type);
#endif /* MARVELL_PHY_1548 */
#ifdef MARVELL_PHY_5123
phy_drv_t *marvell_5123_check_type(int type);
#endif /* MARVELL_PHY_5123 */
phy_drv_t *marvell_5113_check_type(int type);
#ifdef MARVELL_PHY_6141
phy_drv_t *marvell_6141_check_type(int type);
#endif /* MARVELL_PHY_6141 */

#endif /* __PHY_MARVELL_H__ */
