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
#define PLAT_OCTEONTX_VERSION_MINOR	0x2

/* x1 - node number */
#define PLAT_OCTEONTX_DISABLE_RVU_LFS	0xc2000b01

#define PLAT_OCTEONTX_FLSF_FW_BOOTED	0xc2000b02
/*
 * No input
 * Return:
 *	0x0 -- Success
 */
#define PLAT_OCTEONTX_FLSF_CLEAR_FORCE_2NDRY	0xc2000b03
/*
 * x1 - ooo
 * Return:
 *	0x0 -- Success
 *	0x2 -- Fail
 */
#define PLAT_OCTEONTX_OOO_CONFIG	0xc2000b04

/*
 * X1 - CGX_LMAC_ID [0:3 LMAC, 4:7 CGX], X2 - CLAUSE MODE, X3 - phy address,
 * X4 - device address, X5 - register address
 */
#define PLAT_OCTEONTX_MDIO_DBG_READ		0xc2000d01

/*
 * X1 - CGX_LMAC_ID [0:3 LMAC, 4:7 CGX], X2 - CLAUSE MODE, X3 - phy address,
 * X4 - device address, X5 - register address, X6 - register value
 */
#define PLAT_OCTEONTX_MDIO_DBG_WRITE		0xc2000d02

/*
 * X1 - if <= 0, query for attestation buffer address.
 *      if > 0, specifies nonce len
 * Return:
 *      > 0: specifies attestation buffer address (for query call).
 *      0  : success
 *      < 0: failure
 */
#define OCTEONTX_ATTESTATION_QUERY		0xc2000d03

/* Number of platform specific SMCs */
#define PLAT_OCTEONTX_NUM_SMC_CALLS	7

int octeontx2_configure_ooo(int x1);

int mdio_debug_read(int cgxlmac_id, int mode, int phyaddr, int devad,
		    int regnum);
int mdio_debug_write(int cgxlmac_id, int mode, int phyaddr, int devad,
		     int regnum, uint16_t value);
#endif /* __PLATFORM_SVC_H__ */
