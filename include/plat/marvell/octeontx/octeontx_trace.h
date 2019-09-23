/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_TRACE_H__
#define __OCTEONTX_TRACE_H__

uint64_t arm_trace_alloc_sbuf(uint64_t size, uint64_t cpu, int llc_lock_req,
			      uint64_t *addr);
int arm_trace_register_drvbuf(uint64_t address, uint64_t size);
int arm_trace_unregister_drvbuf(uint64_t address, uint64_t size);
int arm_trace_copy_to_drvbuf(uint64_t dst,  uint64_t src, uint64_t size);

#endif /* __OCTEONTX_TRACE_H__ */
