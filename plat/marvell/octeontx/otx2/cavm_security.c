/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <stdio.h>
#include <debug.h>
#include <arch.h>
#include <platform_def.h>
#include <platform_setup.h>
#include <cavm_common.h>
#include <cavm_dt.h>
#include <cavm_octeontx_scfg.h>
#include <cavm_security.h>

struct ccs_region {
	unsigned int  number;
	unsigned long start;
	unsigned long end;
	unsigned int  secure;
};

#define LAST_CCS_REGION (~0U)

struct ccs_region ccs_map [] = {
	{
		.number  = 0,
		.start   = TZDRAM_BASE,
		.end     = TZDRAM_BASE + TZDRAM_SIZE - 1,
		.secure  = 1,
	},
	{
		.number  = 1,
		.start   = TZDRAM_BASE + TZDRAM_SIZE,
		.end     = ~0UL,
		.secure  = 0,
	},
	{
		.number  = LAST_CCS_REGION,
	},
};

void octeontx_security_setup(void)
{
	union cavm_ccs_asc_regionx_attr ccs_asc_attr;
	struct ccs_region *region = ccs_map;
	uint64_t dram_end;

	while (region->number != LAST_CCS_REGION) {
		dram_end = octeontx_dram_size() - 1;
		if (region->end > dram_end)
			region->end = dram_end;

		CSR_WRITE(CAVM_CCS_ASC_REGIONX_START(region->number), region->start);
		CSR_WRITE(CAVM_CCS_ASC_REGIONX_END(region->number), region->end);

		ccs_asc_attr.u = CSR_READ(CAVM_CCS_ASC_REGIONX_ATTR(region->number));
		/*
		 * For given memory region, grant access
		 * to this region to all LMCs
		 */
		ccs_asc_attr.s.lmc_mode = CAVM_CCS_LMC_MODE;
		ccs_asc_attr.s.lmc_mask = CAVM_CCS_LMC_MASK;
		ccs_asc_attr.s.s_en  = region->secure;
		ccs_asc_attr.s.ns_en = !region->secure;
		CSR_WRITE(CAVM_CCS_ASC_REGIONX_ATTR(region->number), ccs_asc_attr.u);

		VERBOSE("Mark memory region %d:: %llx to %llx as %ssecure (%llx)\n",
			region->number,
			CSR_READ(CAVM_CCS_ASC_REGIONX_START(region->number)),
			CSR_READ(CAVM_CCS_ASC_REGIONX_END(region->number)) | 0xffffff,
			region->secure ? "" : "non-",
			CSR_READ(CAVM_CCS_ASC_REGIONX_ATTR(region->number)));

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
/*
 * This function configures IOBN to grant access for eMMC controller
 * to secure/non-secure memory based on input parameter passed
 */
void octeontx_configure_mmc_security(int secure)
{
	/*
	 * rsl_idx - PCC function number for the RSL device
	 * (stream ID<7:0>)
	 * bus_idx - Stream's bus number (stream_id<15:8>).
	 */
	uint64_t rsl_idx = CAVM_PCC_DEV_CON_E_MIO_EMM & 0xFF;
	uint64_t bus_idx = (CAVM_PCC_DEV_CON_E_MIO_EMM >> 8) & 0xFF;
	uint64_t domain_idx = (CAVM_PCC_DEV_CON_E_MIO_EMM >> 16) & 0xFF;
	cavm_iobnx_rslx_streams_t iobn_rslx_stream;
	cavm_iobnx_domx_busx_streams_t iobn_domx_busx_stream;

	/* Check for MMC boot, if not return here */
	if (plat_octeontx_bcfg->bcfg.boot_dev.boot_type != OCTEONTX_BOOT_EMMC)
		return;

	for (int iobn_idx = 0; iobn_idx < plat_octeontx_scfg->iobn_count;
				iobn_idx++) {
		if (secure) {
			/*
			 * While booting from MMC device, it is
			 * necessary to configure IOBN as to grant
			 * access for eMMC controller to secure memory,
			 * where images are loaded
			 */
			iobn_rslx_stream.u = CSR_READ(
				CAVM_IOBNX_RSLX_STREAMS(iobn_idx,
							rsl_idx));
			iobn_rslx_stream.s.strm_nsec = 0;
			iobn_rslx_stream.s.phys_nsec = 0;
			CSR_WRITE(CAVM_IOBNX_RSLX_STREAMS(
						iobn_idx, rsl_idx),
						iobn_rslx_stream.u);

			iobn_domx_busx_stream.u = CSR_READ(
				CAVM_IOBNX_DOMX_BUSX_STREAMS(iobn_idx,
				domain_idx, bus_idx));
			iobn_domx_busx_stream.s.strm_nsec = 0;
			iobn_domx_busx_stream.s.phys_nsec = 0;
			CSR_WRITE(CAVM_IOBNX_DOMX_BUSX_STREAMS(
				iobn_idx, domain_idx, bus_idx),
				iobn_domx_busx_stream.u);
		} else {
			/*
			 * Configure IOBN and mark MMC controller in
			 * NODE0 as acting for non-secure domain.
			 */
			iobn_rslx_stream.u = CSR_READ(
				CAVM_IOBNX_RSLX_STREAMS(
					iobn_idx, rsl_idx));
			iobn_rslx_stream.s.strm_nsec = 1;
			iobn_rslx_stream.s.phys_nsec = 1;
			CSR_WRITE(CAVM_IOBNX_RSLX_STREAMS(
					iobn_idx, rsl_idx), iobn_rslx_stream.u);

			iobn_domx_busx_stream.u = CSR_READ(
				CAVM_IOBNX_DOMX_BUSX_STREAMS(iobn_idx,
				domain_idx, bus_idx));
			iobn_domx_busx_stream.s.strm_nsec = 1;
			iobn_domx_busx_stream.s.phys_nsec = 1;
			CSR_WRITE(CAVM_IOBNX_DOMX_BUSX_STREAMS(
					iobn_idx, domain_idx, bus_idx),
					iobn_domx_busx_stream.u);
		}
	}
}
