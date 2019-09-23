/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <string.h>
#include <debug.h>
#include <plat_scfg.h>
#include <octeontx_trace.h>
#include <runtime_svc.h>
#include <octeontx_svc.h>


/* Secure trace buffer partitioned among all cpus */
char arm_tracebuf[ARM_TRACEBUF_SIZE] __aligned(CACHE_WRITEBACK_GRANULE);

uint64_t arm_trace_alloc_sbuf(uint64_t size, uint64_t cpu, int llc_lock_req,
			      uint64_t *addr)
{
	static uint64_t cpu_size_init;
	int err = 0;

	if (!cpu_size_init)
		cpu_size_init = size;

	/* We assume buffer size is same for all cpus */
	if (cpu_size_init != size)
		return SMC_UNK;

	/* Ensure end offset doesn't overflow the tracebuffer */
	if (cpu * size + size > ARM_TRACEBUF_SIZE)
		return SMC_UNK;

	*addr = (uint64_t)arm_tracebuf + cpu * size;

	if (llc_lock_req)
		err = octeontx_llc_lock(*addr, size);

	if (err)
		return SMC_UNK;

	return SMC_OK;
}

/* API to map non secure buffer for copying trace data */
int arm_trace_register_drvbuf(uint64_t address, uint64_t size)
{
	mmap_add_dynamic_region(address, address, size, MT_MEMORY
			| MT_RW | MT_NS);
	return 0;
}

int arm_trace_unregister_drvbuf(uint64_t address, uint64_t size)
{
	mmap_remove_dynamic_region(address, size);
	return 0;
}

int arm_trace_copy_to_drvbuf(uint64_t dst,  uint64_t src, uint64_t size)
{

	/* Ensure src is within the tracebuffer area */
	if (((char *)src < arm_tracebuf) &&
	    ((char *)src > arm_tracebuf + ARM_TRACEBUF_SIZE - 1))
		return SMC_UNK;

	/* Ensure dst is a non secure region */
	if (dst < TZDRAM_BASE + TZDRAM_SIZE)
		return SMC_UNK;

	memcpy((void *)(dst), (void *)(src), size);
	return 0;
}

