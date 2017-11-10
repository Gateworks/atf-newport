/** @file

  Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <platform_def.h>
#include <cavm_private.h>
#include <stdio.h>
#include <debug.h>

/*
 * Defines used for CN93xx to enable particular
 * LMC access to particular ASC_REGION
 */
#define CAVM_CCS_LMC_MASK_LMC0	0x1
#define CAVM_CCS_LMC_MASK_LMC1	0x2
#define CAVM_CCS_LMC_MASK_LMC2	0x4

struct ccs_region {
	unsigned int  node;
	unsigned int  number;
	unsigned long start;
	unsigned long end;
	unsigned int  secure;
};

struct ccs_region ccs_map [] = {
	{
		.node    = 0,
		.number  = 0,
		.start   = TZDRAM_BASE,
		.end     = TZDRAM_BASE + TZDRAM_SIZE,
		.secure  = 1,
	},
	{
		.node    = 0,
		.number  = 1,
		.start   = RVU_MEM_BASE,
		.end     = RVU_MEM_BASE + RVU_MEM_SIZE,
		.secure  = 0,
	},

	{
		.node    = 0,
		.number  = 2,
		.start   = RVU_MEM_BASE + RVU_MEM_SIZE,
		.end     = ~0UL,
		.secure  = 0,
	},
	{
		.node    = ~0U,
	},
};

void octeontx_security_setup(void)
{
	unsigned node_count = thunder_get_node_count();
	union cavm_ccs_asc_regionx_attr ccs_asc_attr;
	struct ccs_region *region = ccs_map;
	uint64_t dram_end;

	while (region->node < node_count) {
		dram_end = thunder_dram_size_node(region->node) - 1;
		if (region->end > dram_end)
			region->end = dram_end;

		CSR_WRITE_PA(region->node,
			     CAVM_CCS_ASC_REGIONX_START(region->number),
			     region->start);
		CSR_WRITE_PA(region->node,
			     CAVM_CCS_ASC_REGIONX_END(region->number),
			     region->end);

		ccs_asc_attr.u = CSR_READ_PA(region->node, CAVM_CCS_ASC_REGIONX_ATTR(region->number));
		/*
		 * For given memory region, grant access
		 * to this region to all LMCs
		 */
		ccs_asc_attr.s.lmc_mode = CAVM_CCS_LMC_MODE_E_STRIPE_3;
		ccs_asc_attr.s.lmc_mask = CAVM_CCS_LMC_MASK_LMC0 |
					  CAVM_CCS_LMC_MASK_LMC1 |
					  CAVM_CCS_LMC_MASK_LMC2;
		ccs_asc_attr.s.s_en  = region->secure;
		ccs_asc_attr.s.ns_en = !region->secure;
		CSR_WRITE_PA(region->node,
			     CAVM_CCS_ASC_REGIONX_ATTR(region->number),
			     ccs_asc_attr.u);

		INFO("Mark memory region %d at node %d:: %lx to %lx as %ssecure (%lx)\n",
			region->number, region->node,
			CSR_READ_PA(region->node, CAVM_CCS_ASC_REGIONX_START(region->number)),
			CSR_READ_PA(region->node, CAVM_CCS_ASC_REGIONX_END(region->number)),
			region->secure ? "" : "non-",
			CSR_READ_PA(region->node, CAVM_CCS_ASC_REGIONX_ATTR(region->number)));

		region++;
	}

	VERBOSE("Flushing L1C\n");
	dcsw_op_all(DCCISW);

	VERBOSE("Flushing L2C\n");
	l2c_flush();

	VERBOSE("Flushing IC\n");
	__asm__ volatile("ic iallu\n"
			 "isb\n");
}

