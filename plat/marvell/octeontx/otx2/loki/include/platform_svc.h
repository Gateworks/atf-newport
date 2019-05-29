/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLATFORM_SVC_H__
#define __PLATFORM_SVC_H__

/* OcteonTX Service Calls version numbers */
#define PLAT_OCTEONTX_VERSION_MAJOR	0x2
#define PLAT_OCTEONTX_VERSION_MINOR	0x0

/* x1 - node number */
#define PLAT_OCTEONTX_DISABLE_RVU_LFS		0xc2000b01

/*
 * x1 - ooo
 * Return:
 *	0x0 -- Success
 *	0x2 -- Fail
 */
#define PLAT_OCTEONTX_OOO_CONFIG		0xc2000b07

#define PLAT_OCTEONTX_INSTALL_BPHY_PSM_ERRINT	0xc2000803
#define PLAT_OCTEONTX_REMOVE_BPHY_PSM_ERRINT	0xc2000804

/* Number of platform specific SMCs */
#define PLAT_OCTEONTX_NUM_SMC_CALLS	6
int octeontx2_configure_ooo(int);

#endif /* __PLATFORM_SVC_H__ */
