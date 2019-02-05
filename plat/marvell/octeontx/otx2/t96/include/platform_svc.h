/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLATFORM_SVC_H__
#define __PLATFORM_SVC_H__

/* OcteonTX Service Calls version numbers */
#define PLAT_OCTEONTX_VERSION_MAJOR	0x1
#define PLAT_OCTEONTX_VERSION_MINOR	0x1

/* x1 - node number */
#define PLAT_OCTEONTX_DISABLE_RVU_LFS	0xc2000b01

/*
 * x1 - lf index, x2 - block type
 * Return:
 *	0x0 -- Success
 *	0x2 -- Fail
 */
#define PLAT_OCTEONTX_NDC_RESET		0xc2000b02
/*
 * x1 - lf index, x2 - lf block address, x3 - ndc block address
 * Return:
 *	0x0 -- Success
 *	0x2 -- Fail
 */
#define PLAT_OCTEONTX_NDC_SYNC		0xc2000b03
/*
 * No input
 * Return:
 *	0x0 -- Success
 *	0x1 -- Ongoing operation
 *	0x2 -- Fail
 */
#define PLAT_OCTEONTX_NDC_STATUS	0xc2000b04

/* Number of platform specific SMCs */
#define PLAT_OCTEONTX_NUM_SMC_CALLS	4

#endif /* __PLATFORM_SVC_H__ */
