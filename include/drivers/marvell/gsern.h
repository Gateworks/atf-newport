/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef _GSERN_H_
#define _GSERN_H_

#include <gsern/gsern_settings.h>
#include <stdint.h>

#define GSERN_COMMON_BIAS_BCFG_PWDN_BIT			BIT(0)

#define GSERN_LANE_INIT_BSTS_EYE_READY			BIT(40)
#define GSERN_LANE_INIT_BSTS_TX_RST_SM_COMPLETE		BIT(33)
#define GSERN_LANE_INIT_BSTS_TX_READY			BIT(32)
#define GSERN_LANE_INIT_BSTS_RX_DEEP_IDLE		BIT(26)
#define GSERN_LANE_INIT_BSTS_RX_RST_SM_COMPLETE		BIT(25)
#define GSERN_LANE_INIT_BSTS_RX_READY			BIT(24)
#define GSERN_LANE_INIT_BSTS_RST_SM_COMPLETE		BIT(5)
#define GSERN_LANE_INIT_BSTS_RST_SM_READY		BIT(4)
#define GSERN_LANE_INIT_BSTS_CAL_FAIL			BIT(1)
#define GSERN_LANE_INIT_BSTS_CAL_READY			BIT(0)

#define GSERN_COMMON_INIT_BSTS_RST_SM_COMPLETE		BIT(5)
#define GSERN_COMMON_INIT_BSTS_RST_SM_READY		BIT(4)
#define GSERN_COMMON_INIT_BSTS_CAL_FAIL			BIT(1)
#define GSERN_COMMON_INIT_BSTS_CAL_READY		BIT(0)


#define GSERNX_LANEX_TRAIN_5_BCFG_EQ_EVAL_ACK		BIT(32)

#define GSERN_LANE_EYE_DAT_CYCLE_CNT_DONE		BIT(49)

enum gsern_mode {
	GSERN_MODE_DISABLED,
	GSERN_MODE_PCIE_RC,
	GSERN_MODE_PCIE_EP,
	GSERN_MODE_CGX,
};

enum gsern_flags {
	GSERN_FLAGS_NONE = 0x0,
	GSERN_FLAGS_DUAL = 0x1,
	GSERN_FLAGS_QUAD = 0x2
};

/*
 * Eye diagram captures are stored in the following structure
 */
typedef struct {
	int width;              /* Width in the x direction (time) */
	int height;             /* Height in the y direction (voltage) */
	uint32_t data[64][128]; /* Error count at location, saturates as max */
} gsern_qlm_eye_t;

/**
 * Setup the initial mode of a GSERN serdes. This is called for the initial mode
 * set, not mode change due to auto negotiation.
 *
 * @param qlm      DLM/QLM to setup
 * @param qlm_lane Lane in QLM to setup. Only used in networking modes
 * @param mode     Mode to setup
 * @param is_first Set if this is the first DLM/QLM in a sequence used for wide
 *             protocols. For example, PCIe x16 would set this on QLM0 but not
 *             on QLM1-3.
 * @param baud_mhz Baud rate in MegaHertz
 * @param flags    Mode flags for optional features
 *
 * @return Zero on success, negative on failure
 */
int gsern_set_mode(int qlm, int qlm_lane, enum gsern_mode mode, int is_first,
	int baud_mhz, enum gsern_flags flags);

/**
 * Capture an eye diagram
 *
 * @param node	 Node to access
 * @param qlm	  QLM to access
 * @param lane	 Lane to access
 * @param eye_data Location where the eye data will be stored
 *
 * @return Zero on success, negative on failure
 */
int gsern_eye_capture(int qlm, int lane, gsern_qlm_eye_t *eye_data);

#endif /* _GSERN_H_ */
