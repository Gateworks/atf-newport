/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_SVC_H__
#define __OCTEONTX_SVC_H__

/* SMC function IDs for Standard Service queries */

#define OCTEONTX_SVC_CALL_COUNT	0xc200ff00
#define OCTEONTX_SVC_UID	0xc200ff01

#define OCTEONTX_SVC_VERSION	0xc200ff03

/* OcteonTX Service Calls version numbers */
#define OCTEONTX_VERSION_MAJOR	0x1
#define OCTEONTX_VERSION_MINOR	0x1

/* x1 - node number */
#define OCTEONTX_DRAM_SIZE		0xc2000301

/* no args */
#define OCTEONTX_NODE_COUNT		0xc2000601

/* X1 - gpio_num, X2 - sp, X3 - cpu, X4 - ttbr0 */
#define OCTEONTX_INSTALL_GPIO_INT	0xc2000801
/* X1 - gpio_num */
#define OCTEONTX_REMOVE_GPIO_INT	0xc2000802

#define OCTEONTX_INSTALL_BPHY_PSM_ERRINT	0xc2000803
#define OCTEONTX_REMOVE_BPHY_PSM_ERRINT		0xc2000804

/* x1 - character to print */
#define OCTEONTX_PUTC			0xc2000a01

/* x1 - node number */
#if (!defined(PLAT_t81) && !defined(PLAT_t83))
#define OCTEONTX_DISABLE_RVU_LFS	0xc2000b01
#endif

#if (defined(PLAT_t96))
/*
 * x1 - lf index, x2 - block type
 * Return:
 *	0x0 -- Success
 *	0x2 -- Fail
 */
#define OCTEONTX_NDC_RESET		0xc2000b02
/*
 * x1 - lf index, x2 - lf block address, x3 - ndc block address
 * Return:
 *	0x0 -- Success
 *	0x2 -- Fail
 */
#define OCTEONTX_NDC_SYNC		0xc2000b03
/*
 * No input
 * Return:
 *	0x0 -- Success
 *	0x1 -- Ongoing operation
 *	0x2 -- Fail
 */
#define OCTEONTX_NDC_STATUS		0xc2000b04
#endif

#if (!defined(PLAT_t81) && !defined(PLAT_t83))
#define OCTEONTX_NUM_CALLS		12
#else
#define OCTEONTX_NUM_CALLS		8
#endif

#endif /* __OCTEONTX_SVC_H__ */
