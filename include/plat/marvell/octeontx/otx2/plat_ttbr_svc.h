/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef PLAT_TTBR_SVC_H
#define PLAT_TTBR_SVC_H

/* First argument of the smc call */
#define VTTBR_EL2	0x0
#define TTBR0_EL2	0x1
#define TTBR1_EL2	0x2
#define TTBR0_EL1	0x3
#define TTBR1_EL1	0x4
#define TTBR_LAST	0x4

#define TTBR_OK		0x0
#define TTBR_INV_ARG	0x1

int set_ttbr(uint64_t ttbr, uint64_t value);

#endif /* PLAT_TTBR_SVC_H */
