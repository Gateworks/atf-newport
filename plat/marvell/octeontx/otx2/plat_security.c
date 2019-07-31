/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#include <stdio.h>
#include <debug.h>
#include <arch.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <plat_board_cfg.h>
#include <plat_scfg.h>
#include <octeontx_security.h>
#include <octeontx_dram.h>
#include <octeontx_utils.h>

struct ccs_region {
	unsigned int  number;
	unsigned long start;
	unsigned long end;
	unsigned int  secure;
};

#define LAST_CCS_REGION (~0U)
#define MCC_CONFIG_DIS_TADPSN_BIT	BIT(1)

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

/*
 * This is workaround for errata NIX-31533
 */
static void disable_poison(void)
{
	uint64_t mcc_config;
	int i;

	for (i = 0; i < plat_octeontx_scfg->mcc_count; i++) {
		mcc_config = CSR_READ(CAVM_MCCX_CONFIG(i));
		mcc_config |= MCC_CONFIG_DIS_TADPSN_BIT;
		CSR_WRITE(CAVM_MCCX_CONFIG(i), mcc_config);
	}
}

/* Flush the L2 Cache */
void l2c_flush(void)
{
	/* Select the L2 cache */
	union cavm_ap_csselr_el1 csselr_el1;
	union cavm_ap_ccsidr_el1 ccsidr_el1;
	union cavm_ccs_const ccs_const;

	unsigned int sets, ways, clusters, tads;
	int cluster, tad, tg, way, index;

	ccs_const.u = CSR_READ(CAVM_CCS_CONST);
	clusters = ccs_const.s.clu;
	tads = ccs_const.s.tadclu;
	csselr_el1.s.level = 2;
	__asm__ volatile ("msr csselr_el1, %0" : : "r"((uint64_t)csselr_el1.u));
	__asm__ volatile ("mrs %0, ccsidr_el1" : "=&r"(ccsidr_el1.u));

	sets = ((ccsidr_el1.s.numsets + 1) / tads / clusters);
	ways = (ccsidr_el1.s.associativity + 1);
	for (cluster = 0; cluster < clusters; cluster++) {
		for (tad = 0; tad < tads; tad++) {
			for (tg = 0; tg < 2; tg++) {
				for (way = 0; way < ways; way++) {
					for (index = 0; index < sets; index++) {
						uint64_t encoded = 0;

						encoded |= cluster << 25;
						encoded |= tad << 24;
						encoded |= tg << 23;
						encoded |= way << 18;
						encoded |= index << 8;
						__asm__ volatile
				("sys #0,c11,c0,#5, %0" : : "r" (encoded));
					}
				}
			}
		}
	}
}

void octeontx_security_setup(void)
{
	union cavm_ccs_asc_regionx_attr ccs_asc_attr;
	struct ccs_region *region = ccs_map;
	uint64_t dram_end;
	uint64_t midr;
	uint8_t lmc_mask, lmc_mode;

	midr = read_midr();

	if (IS_OCTEONTX_PN(midr, T96PARTNUM)
	    || IS_OCTEONTX_VAR(midr, F95PARTNUM, 1)
	    || IS_OCTEONTX_PASS(midr, LOKIPARTNUM, 1, 0))
		disable_poison();

	/*
	 * BDK has configured CCS ASC REGION 0. We will use the same lmc_mask and
	 * lmc_mode for every configured region.
	 */
	ccs_asc_attr.u = CSR_READ(CAVM_CCS_ASC_REGIONX_ATTR(0));
	lmc_mode = ccs_asc_attr.s.lmc_mode;
	lmc_mask = ccs_asc_attr.s.lmc_mask;

	INFO("BDK LMC mode = 0x%x; mask 0x%x\n", lmc_mode, lmc_mask);

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
		ccs_asc_attr.s.lmc_mode = lmc_mode;
		ccs_asc_attr.s.lmc_mask = lmc_mask;
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
