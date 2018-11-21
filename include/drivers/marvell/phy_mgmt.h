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

/* This structure contains the tap values to use for various cable lengths */
typedef struct phy_vsc7224_tap {
	uint16_t len;		/* Starting cable length for tap values */
	uint16_t main_tap;	/* Main tap value to use */
	uint16_t pre_tap;	/* Pre-tap value to use */
	uint16_t post_tap;	/* Post-tap value to use */
} phy_vsc7224_tap_t;

typedef struct phy_vsc7224_chan {
	int lane;
	uint8_t is_tx;			/* True if is transmit channel */
	uint8_t maintap_disable;	/* True to disable the main tap */
	uint8_t pretap_disable;		/* True to disable pre-tap */
	uint8_t posttap_disable;	/* True to disable post-tap */
	int num_taps;			/* Number of tap values */
	phy_vsc7224_tap_t taps[6];	/* For now, consider 6 TAPS as max */
} phy_vsc7224_chan_t;

/* Data structure for Microsemi VSC7224 reclocking chip */
typedef struct phy_vsc7224 {
	const char *name;
	phy_vsc7224_chan_t channel[4];
	sfp_i2c_info_t i2c_bus;
	int i2c_addr;
} phy_vsc7224_t;

/* APIs */
void octeontx_phy_reset(int cgx_id, int lmac_id);

int octeontx_get_phy_link_status(int cgx_id, int lmac_id,
				link_state_t *link);

#endif /* __PHY_MGMT_H__ */
