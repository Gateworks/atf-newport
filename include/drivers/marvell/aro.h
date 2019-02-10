/*
 * Copyright (C) 2017 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */
#ifndef _ARO_H_
#define _ARO_H_

#include <mvebu_def.h>

enum cpu_clock_freq_mode {
	CPU_2000_DDR_1200_RCLK_1200 = 0x0,
	CPU_2000_DDR_1050_RCLK_1050 = 0x1,
	CPU_1600_DDR_800_RCLK_800   = 0x4,
	CPU_2200_DDR_1200_RCLK_1200 = 0x6, /* custom freq for 91xx */
	CPU_1800_DDR_1050_RCLK_1050 = 0x7,
	CPU_1600_DDR_900_RCLK_900   = 0x0B,
	CPU_1600_DDR_1050_RCLK_1050 = 0x0D,
	CPU_1600_DDR_1200_RCLK_1200 = 0x0D,
	CPU_1600_DDR_900_RCLK_900_2 = 0x0E,
	CPU_1000_DDR_650_RCLK_650   = 0x13,
	CPU_1300_DDR_800_RCLK_800   = 0x14,
	CPU_1300_DDR_650_RCLK_650   = 0x17,
	CPU_1200_DDR_800_RCLK_800   = 0x19,
	CPU_1400_DDR_800_RCLK_800   = 0x1a,
	CPU_600_DDR_800_RCLK_800    = 0x1B,
	CPU_800_DDR_800_RCLK_800    = 0x1C,
	CPU_1000_DDR_800_RCLK_800   = 0x1D,
	CPU_DDR_RCLK_INVALID
};

#endif /* _ARO_H_ */
