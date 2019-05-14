/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __GTI_WATCHDOG_H__
#define __GTI_WATCHDOG_H__

int gti_watchdog_is_running(int core);
void gti_watchdog_disable(void);
uint64_t del3t_trap_handler;

/* Driver API */

int gti_wdog_remove_handler(void);

int gti_wdog_install_handler(uint64_t kernel_wdog_callback, uint64_t sp,
				uint64_t x3, uint64_t x4);

#endif /* __GTI_WATCHDOG_H__ */