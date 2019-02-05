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
#define PLAT_OCTEONTX_DISABLE_RVU_LFS		0xc2000b01

#define PLAT_OCTEONTX_INSTALL_BPHY_PSM_ERRINT	0xc2000803
#define PLAT_OCTEONTX_REMOVE_BPHY_PSM_ERRINT	0xc2000804

/* Number of platform specific SMCs */
#define PLAT_OCTEONTX_NUM_SMC_CALLS	3

#endif /* __PLATFORM_SVC_H__ */
