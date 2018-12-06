/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PHY_MGMT_H__
#define __PHY_MGMT_H__

/* IEEE 802.3 spec CLAUSE 45 MDIO access
 * PMA/PMD control reg bits 6 & 13 determine
 * speed sel
 * 6 13
 * 1 1 = bits 5:2 select speed
 * 1 0 = 1000 Mb/s
 * 0 1 = 100 Mb/s
 * 0 0 = 10 Mb/s
 */
#define PHY_CLAUSE45_SPEED_10M		0x0000
#define PHY_CLAUSE45_SPEED_100M		0x0040
#define PHY_CLAUSE45_SPEED_1G		0x2000
#define PHY_CLAUSE45_SPEED_BITS_2_5_SEL	0x2040
#define PHY_CLAUSE45_SPEED_SEL_MASK	PHY_CLAUSE45_SPEED_BITS_2_5_SEL
#define PHY_CLAUSE45_MAX_SPEED_SEL	0xF

/* IEE 802.3 spec : CLAUSE 45 registers */
#define PMA_PMD_DEVICE_ADDR		1
#define PMA_PMD_CONTROL_REG		0
#define PMA_PMD_STATUS_REG		1

/* generic 802.3 clause types */
typedef enum {
	PHY_GENERIC_8023_NONE,
	PHY_GENERIC_8023_C22,
	PHY_GENERIC_8023_C45
} phy_clause_t;

/* APIs */
void octeontx_phy_reset(int cgx_id, int lmac_id);

int octeontx_get_phy_link_status(int cgx_id, int lmac_id,
				link_state_t *link);

#endif /* __PHY_MGMT_H__ */
