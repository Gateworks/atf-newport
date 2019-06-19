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
void plat_gti_access_secure_memory_setup(int do_secure) WEAK;
void plat_gti_irq_setup(int core) WEAK;
uint64_t del3t_trap_handler;

/* Driver API */

int gti_wdog_remove_handler(void);

int gti_wdog_install_handler(uint64_t core);

int gti_wdog_start(uint64_t kernel_wdog_callback, uint64_t watchdog_timeout_ms,
			 uint64_t cores);

int gti_wdog_restore_wdog_ctxt(void);

#endif /* __GTI_WATCHDOG_H__ */
