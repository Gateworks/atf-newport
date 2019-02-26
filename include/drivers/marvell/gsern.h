/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef _GSERN_H_
#define _GSERN_H_

#include <gsern_settings.h>

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#define GSERN_COMMON_BIAS_BCFG_PWDN_BIT		BIT(0)

#define GSERN_LANE_INIT_BSTS_TX_RST_SM_COMPLETE		BIT(33)
#define GSERN_LANE_INIT_BSTS_TX_READY			BIT(32)
#define GSERN_LANE_INIT_BSTS_RST_SM_COMPLETE		BIT(5)
#define GSERN_LANE_INIT_BSTS_RST_SM_READY		BIT(4)
#define GSERN_LANE_INIT_BSTS_CAL_FAIL			BIT(1)
#define GSERN_LANE_INIT_BSTS_CAL_READY			BIT(0)

#define GSERN_COMMON_INIT_BSTS_RST_SM_COMPLETE		BIT(5)
#define GSERN_COMMON_INIT_BSTS_RST_SM_READY		BIT(4)
#define GSERN_COMMON_INIT_BSTS_CAL_FAIL			BIT(1)
#define GSERN_COMMON_INIT_BSTS_CAL_READY		BIT(0)

/* GSERN flags */
#define GSERN_FLAGS_NONE		0
#define GSERN_FLAGS_DUAL		1
#define GSERN_FLAGS_QUAD		2

int gsern_init_network(int qlm, int qlm_lane, int flags,
	enum gsern_lane_modes mode);

#endif /* _GSERN_H_ */

