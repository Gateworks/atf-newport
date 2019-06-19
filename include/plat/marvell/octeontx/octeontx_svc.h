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

/* x1 - node number */
#define OCTEONTX_DRAM_SIZE		0xc2000301

/* no args */
#define OCTEONTX_NODE_COUNT		0xc2000601

/* X1 - gpio_num, X2 - sp, X3 - cpu, X4 - ttbr0 */
#define OCTEONTX_INSTALL_GPIO_INT	0xc2000801
/* X1 - gpio_num */
#define OCTEONTX_REMOVE_GPIO_INT	0xc2000802

/* x1 - character to print */
#define OCTEONTX_PUTC			0xc2000a01

/*
 * X1 - kernel_wdog_callback, X2 - cpu,
 * X3 - watchdog_timeout_ms, X4 - coremask
 */
#define OCTEONTX_INSTALL_WDOG           0xc2000c01

#define OCTEONTX_REMOVE_WDOG            0xc2000c02

#define OCTEONTX_START_WDOG		0xc2000c03

#define OCTEONTX_RESTORE_WDOG_CTXT	0xc2000c04

#define OCTEONTX_NUM_CALLS		12

/* API that allows to define family specific SMC CALLS */
uintptr_t plat_octeontx_svc_smc_handler(uint32_t smc_fid,
					u_register_t x1,
					u_register_t x2,
					u_register_t x3,
					u_register_t x4,
					void *cookie,
					void *handle,
					u_register_t flags);


#endif /* __OCTEONTX_SVC_H__ */
