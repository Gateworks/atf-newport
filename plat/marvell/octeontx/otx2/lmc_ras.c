/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/* EDAC driver for OcteonTX2 */

#include <arch.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <platform_def.h>
#include <octeontx_irqs_def.h>
#include <octeontx_common.h>
#include <debug.h>
#include <interrupt_mgmt.h>
#include <plat_board_cfg.h>
#include <octeontx_security.h>
#include <octeontx_dram.h>
#include <octeontx_utils.h>
#include <uuid.h>
#include <platform.h>
#include <lmc_ras.h>
#include <timers.h>
#include <delay_timer.h>

#ifdef DEBUG_ATF_RAS
# define debug_ras printf
#else
# define debug_ras(...) ((void)(0))
#endif

#define CACHE_LINE_SIZE		128
#define RAS_MAX_MEM_CHAINS	32
#define NUM_MCC			2

struct ras_dram_lmc_map {
	int lmc;
	int mcc;
	int lmcoe;
};

struct ras_ccs_addr_conversion_data {
	uint64_t addr;          //uint64_t addr;
	int phys_lmc_mask;      //MASK of LMC
	int idx_alias;
	int ASC_REGION;
	int ASC_REM;
	int ASC_MD_LR_BIT;      //Left Right Bit selector
	int ASC_LMC_MASK;		//Mask of Channels enabled
	int ASC_LMC_MODE;		//Mode region is setup as
	uint64_t ASC_MD_LR_EN;	//Bit mask of Address bits used in hash
	uint64_t ASC_OFFSET;	//Address offset
	uint64_t ASC_MCS_EN[4];	//Bit Masks for Hashing
	//int show_debug;
};

// Table to translate ECC single-bit syndrome to "byte.bit" format.
//
// indexed by syndrome, data is [7:4] = byte no. + 1 and [3:0] = bit no.
// hack: make the byte no. bits be non-zero even for byte 0;
// this is so non-explicit data can be 0x00 and will be illegal.
static const unsigned char
ecc_syndrome_to_bytebit[256] = {
	// byte 0, bits 0 to 7
	[0xce] = 0x10, [0xcb] = 0x11, [0xd3] = 0x12, [0xd5] = 0x13,
	[0xd6] = 0x14, [0xd9] = 0x15, [0xda] = 0x16, [0xdc] = 0x17,
	// byte 1, bits 0 to 7
	[0x23] = 0x20, [0x25] = 0x21, [0x26] = 0x22, [0x29] = 0x23,
	[0x2a] = 0x24, [0x2c] = 0x25, [0x31] = 0x26, [0x34] = 0x27,
	// byte 2, bits 0 to 7
	[0x0e] = 0x30, [0x0b] = 0x31, [0x13] = 0x32, [0x15] = 0x33,
	[0x16] = 0x34, [0x19] = 0x35, [0x1a] = 0x36, [0x1c] = 0x37,
	// byte 3, bits 0 to 7
	[0xe3] = 0x40, [0xe5] = 0x41, [0xe6] = 0x42, [0xe9] = 0x43,
	[0xea] = 0x44, [0xec] = 0x45, [0xf1] = 0x46, [0xf4] = 0x47,
	// byte 4, bits 0 to 7
	[0x4f] = 0x50, [0x4a] = 0x51, [0x52] = 0x52, [0x54] = 0x53,
	[0x57] = 0x54, [0x58] = 0x55, [0x5b] = 0x56, [0x5d] = 0x57,
	// byte 5, bits 0 to 7
	[0xa2] = 0x60, [0xa4] = 0x61, [0xa7] = 0x62, [0xa8] = 0x63,
	[0xab] = 0x64, [0xad] = 0x65, [0xb0] = 0x66, [0xb5] = 0x67,
	// byte 6, bits 0 to 7
	[0x8f] = 0x70, [0x8a] = 0x71, [0x92] = 0x72, [0x94] = 0x73,
	[0x97] = 0x74, [0x98] = 0x75, [0x9b] = 0x76, [0x9d] = 0x77,
	// byte 7, bits 0 to 7
	[0x62] = 0x80, [0x64] = 0x81, [0x67] = 0x82, [0x68] = 0x83,
	[0x6b] = 0x84, [0x6d] = 0x85, [0x70] = 0x86, [0x75] = 0x87,
	// byte 8, bits 0 to 7
	[0x01] = 0x90, [0x02] = 0x91, [0x04] = 0x92, [0x08] = 0x93,
	[0x10] = 0x94, [0x20] = 0x95, [0x40] = 0x96, [0x80] = 0x97
};

int64_t __ras_dram_ecc_single_bit_errors[RAS_MAX_MEM_CHAINS];
int64_t __ras_dram_ecc_double_bit_errors[RAS_MAX_MEM_CHAINS];

#define EDAC_POLLED	/* do not rely on IRQs */
#ifdef EDAC_POLLED
static int edac_timer = -1; /* periodic poll */
#endif
static int edac_alive; /* protect against EDAC_POLLED early polling */

/**
 * Atomically adds a signed value to a 64 bit (aligned) memory location.
 *
 * This version does not perform 'sync' operations to enforce memory
 * operations.  This should only be used when there are no memory operation
 * ordering constraints.  (This should NOT be used for reference counting -
 * use the standard version instead.)
 *
 * @param ptr    address in memory to add incr to
 * @param incr   amount to increment memory location by (signed)
 */
static inline void ras_atomic_add64_nosync(int64_t *ptr, int64_t incr)
{
	__asm__ volatile ("ldadd %x[i], xzr, [%[b]]"
		      : [r] "+m" (*ptr)
		      : [i] "r" (incr), [b]"r" (ptr)
		      : "memory");
}

static inline int is_asim(void)
{
	return !strncmp(plat_octeontx_bcfg->bcfg.board_model, "asim-", 5);
}

/**
 * Add 2 bits into the LMC address to represent the LMC the address
 * came from. (like the CN8xxx LMC address configuration)
 *
 * @param addr  an LMC address without LMC bits
 * @param lmc   The LMC the address originated from
 *
 * @return an LMC address with LMC Bits
 */
static inline uint64_t ras_ccs_get_lmc_addr(uint64_t addr, int lmc)
{
	return (((((((1ULL << 36)-1) << 7) & addr) << 2) |
		 (0x7f & addr)) | ((lmc & 0x3) << 7));
}

/**
 * Remove the two bits from an interal LMC address that represent the
 * LMC the address is on and return just the DRAM bits
 *
 * @param addr  an LMC address with LMC bits
 *
 * @return an LMC address without LMC Bits
 */
static inline uint64_t ras_ccs_get_dram_addr(uint64_t addr)
{
	return (((((1ULL << 36)-1) << 9) & addr) >> 2) |
	       (0x7f & addr);
}

/**
 * Extract the LMC from the address provided
 *
 * @param address   A full LMC address with LMC bits indicating
 *                  which lmc it came from
 *
 * @return the LMC the address originated on
 */
static inline int ras_ccs_find_lmc(uint64_t address)
{
	return (address >> 7) & 0x3;
}

/**
 * Population count
 *
 * @param number	64-bit number to count lmc_mod6_hash_bits
 *
 * @returns		Number of 1 bits
 */
static inline int ras_dpop(uint64_t number)
{
	number -= (number >> 1) & 0x5555555555555555;
	number = (number & 0x3333333333333333) +
		 ((number >> 2) & 0x3333333333333333);
	number = (number + (number >> 4)) & 0x0f0f0f0f0f0f0f0f;
	return (number * 0x0101010101010101) >> 56;
}

/**
 * Perform a Reduction XOR operation and return result
 *
 * @param number    number to do reduction XOR on
 *
 * @return          0 if number of bits is even
 *                  1 if number of bits is odd
 */
static inline int __rxor(uint64_t number)
{
	return ras_dpop(number) % 2;	//64 bit popcount
}

/**
 * Unhash the physical address without the left right bit
 *
 * @param _pa_no_lr_hash	Hashed address without the left right bit
 * @param ccs_adr_mcs		CAVM_CCS_ADR_MCSX data
 *
 * @return on Success		Unhashed LMC address without the left right bit
 *         on Failure		-1
 */
uint64_t ras_ccs_reverse_lmc_hash(uint64_t _pa_no_lr_hash,
				   uint64_t *ccs_adr_mcs)
{
	uint64_t pa_no_lr;
	uint64_t adr_mcs[4];
	int lmc_hash, i;
	int low_addr;
	int num_good_bits = 0;
	int upper_lmc_hash_parity[4];
	int lower_lmc_hash_parity;

	pa_no_lr = _pa_no_lr_hash & ~(0xfff);
	lmc_hash = (_pa_no_lr_hash >> 8) & 0xf;

	debug_ras("%-40s: 0x%016llx\n", "pre pa_no_lr", pa_no_lr);
	debug_ras("%-40s: 0x%x\n", "lmc_hash", lmc_hash);

	for (i = 0; i < 4; i++) {
		adr_mcs[i] = ccs_adr_mcs[i];
		upper_lmc_hash_parity[i] =
			__rxor((adr_mcs[i] >> 12) & (pa_no_lr >> 12));
	}
	debug_ras("%-40s: [%d%d%d%d]\n", "upper_lmc_hash_parity",
		  upper_lmc_hash_parity[0], upper_lmc_hash_parity[1],
		  upper_lmc_hash_parity[2], upper_lmc_hash_parity[3]);

	/* Loop all possible address values in bits [3:0] and check to
	 * see if exactly one matches.
	 */
	for (low_addr = 0; low_addr < 16; low_addr++) {
		num_good_bits = 0;
		for (i = 0; i < 4; i++) {
			lower_lmc_hash_parity =
				__rxor(((adr_mcs[i] >> 8) & 0xf) & low_addr);
			if (lower_lmc_hash_parity ^
			      (upper_lmc_hash_parity[i] ==
			       ((lmc_hash >> i) & 0x1)))
				num_good_bits++;
		}
		if (num_good_bits == 4)
			break;
	}

	debug_ras("%-40s: 0x%x\n", "low_addr", low_addr);

	if (num_good_bits == 4)
		return pa_no_lr | (low_addr << 8);
	else
		return -1;
}

/**
 * Convert an LMC address into a Physical Address used coreside
 * this tries conversion within a single translation region
 *
 * @param addr_data	Data used to decode the LMC Address
 *
 * @return  on success	Physical address coressponding to the LMC address
 *          on failure	-1
 */
uint64_t ras_ccs_convert_lmc_to_pa_algorithm(
				struct ras_ccs_addr_conversion_data *addr_data)
{
	uint64_t pre_offset     = addr_data->addr;
#ifdef DEBUG_ATF_RAS
	int region		= addr_data->ASC_REGION;
#endif
	int ASC_MD_LR_BIT       = addr_data->ASC_MD_LR_BIT;
	uint64_t ASC_MD_LR_EN   = addr_data->ASC_MD_LR_EN;
	int ASC_LMC_MASK        = addr_data->ASC_LMC_MASK;
	int ASC_LMC_MODE        = addr_data->ASC_LMC_MODE;
	int phys_lmc_mask       = addr_data->phys_lmc_mask;

	uint64_t pa_no_lr;
	uint64_t pa_no_lr_hash = 0;
	uint64_t pa;
	uint64_t gen_addr;
	uint64_t left_mask;
	uint64_t right_mask;

	int lrbit;
	int MD_mirror = 0;
	int MD_right = 0;
	int MD_right_calculated;
	int lmcquarter;
	int pa_no_lr_hash_mod6;

	debug_ras("Starting LMC to PA Conversion Algorithm\n");
	debug_ras("%-40s: 0x%016llx\n", "pre_offset", pre_offset);

	/* check if lmcmask and ASC LMC MASK intersect if not this region
	 * isn't mapped to this ASC
	 */
	if ((phys_lmc_mask & ASC_LMC_MASK) == 0) {
		debug_ras("LMC mask 0x%x Does not Fit into ASC %d LMC_MASK 0x%x\n",
			  phys_lmc_mask, region, ASC_LMC_MASK);
		return -1;
	}

	switch (ASC_LMC_MODE) {

	case CAVM_CCS_LMC_MODE_E_FLAT_1:
		MD_right = pre_offset & 0x1;
		/* right shift by 1 to get bits 34:1
		 * and left shift by 8 to move bits to [41:8]
		 */
		pa_no_lr_hash = (pre_offset >> 1);
		pa_no_lr_hash <<= 8;
		/* Drop pa_no_lr_hash[42] */
		pa_no_lr_hash &= ((1ULL << 41) - 1);

		debug_ras("%-40s: %d\n", "MD_right", MD_right);
		debug_ras("%-40s: 0x%016llx\n", "pa_no_lr_hash", pa_no_lr_hash);
		break;

	case CAVM_CCS_LMC_MODE_E_STRIPE_2:
		pa_no_lr_hash = pre_offset << 8;
		/* if phys_lmc_mask is LMC0 MD_right is 1 if it is LMC1
		 * MD_right is 0
		 */
		if (ASC_LMC_MASK == 0x3)                    /* LMC01 */
			MD_right = phys_lmc_mask & 0x1 ? 1 : 0;
		/* if phys_lmc_mask is LMC0 MD_right is 1 if it is LMC2
		 * MD_right is 0
		 */
		else if (ASC_LMC_MASK == 0x5)               /* LMC02 */
			MD_right = phys_lmc_mask & 0x1 ? 1 : 0;
		/* if phys_lmc_mask is LMC2 MD_right is 1 if it is LMC1
		 * MD_right is 0
		 */
		else if (ASC_LMC_MASK == 0x6)               /* LMC12 */
			MD_right = phys_lmc_mask & 0x4 ? 1 : 0;

		debug_ras("%-40s: %d\n", "MD_right", MD_right);
		debug_ras("%-40s: 0x%016llx\n", "pa_no_lr_hash", pa_no_lr_hash);
		break;

	case CAVM_CCS_LMC_MODE_E_STRIPE_3:
		lmcquarter = pre_offset & 0x3;
		pa_no_lr_hash_mod6 = 0;

		/* Determine pa_no_lr_hash_mod6 and MD_right based upon which
		 * LMC the addr came from and the LMC quarter
		 */
		if (phys_lmc_mask == 0x1) {     /* LMC0 */
			MD_right = 1;
			if (lmcquarter == 0x0)
				pa_no_lr_hash_mod6 = 0;
			else if (lmcquarter == 0x1)
				pa_no_lr_hash_mod6 = 0x3;
			else if (lmcquarter == 0x2)
				pa_no_lr_hash_mod6 = 0x5;
			else if (lmcquarter == 0x3) {
				pa_no_lr_hash_mod6 = 0x1;
				MD_right = 0;
			} else {
				debug_ras("ERROR: Unsupported lmc, lmcquarter: %x %x\n",
					  phys_lmc_mask, lmcquarter);
				return -1;
			}
		} else if (phys_lmc_mask == 0x2) { /* LMC1 */
			MD_right = 0;
			if (lmcquarter == 0x0)
				pa_no_lr_hash_mod6 = 0;
			else if (lmcquarter == 0x1)
				pa_no_lr_hash_mod6 = 0x2;
			else if (lmcquarter == 0x2)
				pa_no_lr_hash_mod6 = 0x3;
			else if (lmcquarter == 0x3)
				pa_no_lr_hash_mod6 = 0x4;
			else {
				debug_ras("ERROR: Unsupported lmc, lmcquarter: %x %x\n",
					  phys_lmc_mask, lmcquarter);
				return -1;
			}
		} else if (phys_lmc_mask == 0x4) { /* LMC2 */
			MD_right = 1;
			if (lmcquarter == 0x0)
				pa_no_lr_hash_mod6 = 0x1;
			else if (lmcquarter == 0x1)
				pa_no_lr_hash_mod6 = 0x2;
			else if (lmcquarter == 0x2)
				pa_no_lr_hash_mod6 = 0x4;
			else if (lmcquarter == 0x3) {
				pa_no_lr_hash_mod6 = 0x5;
				MD_right = 0;
			} else {
				debug_ras("ERROR: Unsupported lmc, lmcquarter: %x %x\n",
					  phys_lmc_mask, lmcquarter);
				return -1;
			}
		}

		pa_no_lr_hash = (((pre_offset >> 2) * 6) +
						pa_no_lr_hash_mod6) << 8;

		debug_ras("%-40s: %d\n", "lmcquarter", lmcquarter);
		debug_ras("%-40s: 0x%x\n", "pa_no_lr_hash_mod6",
			  pa_no_lr_hash_mod6);
		debug_ras("%-40s: %d\n", "MD_right", MD_right);
		debug_ras("%-40s: 0x%016llx\n", "pa_no_lr_hash", pa_no_lr_hash);

		break;

	default:
		debug_ras("Unsupported lmc_mode: %x\n", ASC_LMC_MODE);
		return -1;
	}

	pa_no_lr = ras_ccs_reverse_lmc_hash(pa_no_lr_hash,
					    addr_data->ASC_MCS_EN);
	debug_ras("%-40s: 0x%016llx\n", "pa_no_lr", pa_no_lr);
	if (pa_no_lr == (uint64_t)-1) {
		debug_ras("No Valid LMC Hash Combinations Work for lmc%0d address: 0x%016llx.\n",
			  phys_lmc_mask, pre_offset);
		return -1;
	}

	/* left mask */
	left_mask = ((1ULL << (42 - (ASC_MD_LR_BIT + 7))) - 1) <<
							(ASC_MD_LR_BIT + 8);

	/* right mask */
	right_mask = (1ULL << (ASC_MD_LR_BIT + 8)) - 1;

	debug_ras("%-40s: 0x%llx\n", "left_mask", left_mask);
	debug_ras("%-40s: 0x%llx\n", "right_mask", right_mask);

	/* pa_no_lr is currently bits 42:0 but bits 7:0 are left as 0 */
	pa = (pa_no_lr & left_mask) | ((pa_no_lr & right_mask) >> 1);

	debug_ras("%-40s: 0x%016llx\n", "pre_pa", pa);

	MD_right_calculated = __rxor((ASC_MD_LR_EN << 7) & pa) ^ MD_mirror;

	if (MD_right == MD_right_calculated)
		lrbit = 0;
	else
		lrbit = 1;

	gen_addr = (pa | lrbit << (ASC_MD_LR_BIT + 7));

	debug_ras("Generated Addr: 0x%016llx\n", gen_addr);
	return gen_addr;
}

/**
 * Convert a memory address from a LMC address in CN9XXX to
 * a physical address, trying conversion in all translation regions
 *
 * @param _lmc_addr     Full LMC Address including cache line bits
 *
 * @return	on success	A physical address corresponding with
 *				the lmc address given
 *		on failure	-1
 */
static uint64_t ras_ccs_convert_lmc_to_pa(uint64_t _lmc_addr)
{
	int region;
	uint64_t internal_lmc_addr;
	int found_good_addr = 0;
	uint64_t final_phys_addr = 0;
	int lmc;
	int MAX_ASCS;
	union cavm_ccs_const ccs_const;
	struct ras_ccs_addr_conversion_data addr_data;

	debug_ras("Starting LMC to PA Conversion\n");
	memset(&addr_data, 0, sizeof(struct ras_ccs_addr_conversion_data));

	for (int mcs = 0; mcs < 4; mcs++)
		addr_data.ASC_MCS_EN[mcs] = CSR_READ(CAVM_CCS_ADR_MCSX(mcs));

	debug_ras("Original LMC ADDR: 0x%016llx\n", _lmc_addr);
	lmc = ras_ccs_find_lmc(_lmc_addr);
	internal_lmc_addr = ras_ccs_get_dram_addr(_lmc_addr);
	addr_data.phys_lmc_mask = 0x1 << lmc;
	debug_ras("ADDR: 0x%016llx LMC origin: %d\n", internal_lmc_addr, lmc);

	/* Find number of ASC regions on this chip */
	ccs_const.u = CSR_READ(CAVM_CCS_CONST);
	MAX_ASCS = ccs_const.s.asc;

	for (region = 0; region < MAX_ASCS; region++) {
		union cavm_ccs_asc_regionx_attr attr;

		attr.u = CSR_READ(CAVM_CCS_ASC_REGIONX_ATTR(region));

		/* check if region is enabled */
		if (attr.s.ns_en || attr.s.s_en) {
			union cavm_ccs_adr_ctl adr_ctl;
			union cavm_ccs_asc_regionx_offset offset;
			uint64_t phys_addr;

			debug_ras("ASC%d: Checking Conversion from LMC to PA\n",
				  region);
			adr_ctl.u = CSR_READ(CAVM_CCS_ADR_CTL);
			//addr_data.idx_alias = !adr_ctl.s.dissetalias;
			addr_data.ASC_MD_LR_BIT = adr_ctl.s.md_lr_bit;
			addr_data.ASC_MD_LR_EN = adr_ctl.s.md_lr_en;
			addr_data.ASC_LMC_MASK = attr.s.lmc_mask;
			addr_data.ASC_LMC_MODE = attr.s.lmc_mode;
			addr_data.ASC_REGION = region;
			addr_data.addr = internal_lmc_addr / CACHE_LINE_SIZE;

			phys_addr = ras_ccs_convert_lmc_to_pa_algorithm(
								&addr_data);
			if (phys_addr == (uint64_t) -1) {
				debug_ras("ASC%d: Failed to Convert LMC to Phys Addr\n",
					  region);
				continue;
			}
			offset.u = CSR_READ(
					CAVM_CCS_ASC_REGIONX_OFFSET(region));
			phys_addr += (offset.s.offset << 17);
			debug_ras("ASC%d: Found Phys Addr: 0x%016llx\n",
				  region, phys_addr);
			/* duplicate translations are OK */
			if (found_good_addr && final_phys_addr == phys_addr)
				continue;
			found_good_addr++;
			final_phys_addr = phys_addr;
		}
	}

	if (found_good_addr == 1)
		return final_phys_addr;
	else if (found_good_addr > 1)
		debug_ras("ERROR FOUND ALIASING!\n");
	else
		debug_ras("ERROR UNABLE TO FIND PHYS ADDR!\n");
	ERROR("CCS Decode - LMC to PA returned -1\n");
	return -1;
}

/**
 * Return the number of bank bits in use
 *
 * NOTE: all DDR3, and DDR4 x16 today, use only 3 bank bits; DDR4 x4 and x8
 * always have 4 bank bits
 * NOTE: this will change in the future, when DDR4 x16 devices can come with
 * 16 banks!! FIXME!!
 */
static int ras_dram_get_num_bank_bits(int lmc)
{
	union cavm_lmcx_config lmcx_config;
	int bank_width;

	lmcx_config.u = CSR_READ(CAVM_LMCX_CONFIG(lmc)); /* sample LMCn */
	bank_width = lmcx_config.s.bg2_enable ? 4 : 3;

	return bank_width;
}

/**
 * Given a physical DRAM address, extract information about the LMC, DIMM,
 * prank, lrank, bank, row, and column that was accessed.
 *
 * @param address Full LMC Address
 * @param lmc     LMC controller the address was for
 * @param dimm    DIMM the address was for
 * @param prank   Physical RANK on the DIMM
 * @param lrank   Logical RANK on the DIMM
 * @param bank    BANK on the DIMM
 * @param row     Row on the DIMM
 * @param col     Column on the DIMM
 */
void ras_dram_address_extract_info(uint64_t address, int *lmc,
				   int *dimm, int *prank, int *lrank,
				   int *bank, int *row, int *col)
{
	int xbits = 2;
	union cavm_lmcx_config lmcx_config;
	union cavm_lmcx_ext_config ext_config;
	int bank_lsb;
	int bank_width;
	int dimm_lsb;
	int dimm_width;
	int prank_lsb;
	int prank_width;
	int lrank_lsb;
	int lrank_width;
	int row_lsb;
	int row_width;
	int col_hi_lsb;
	int col_hi_width;
	int col_hi;

	/* xbits setup in address conversion to look like 8x */
	*lmc = octeontx_bit_extract(address, 7, xbits);

	bank_lsb = 7 + xbits;
	/* Figure out the bank field width */
	lmcx_config.u = CSR_READ(CAVM_LMCX_CONFIG(*lmc));
	bank_width = ras_dram_get_num_bank_bits(*lmc);

	/* Extract additional info from the LMC_CONFIG CSR */
	ext_config.u = CSR_READ(CAVM_LMCX_EXT_CONFIG(*lmc));
	dimm_lsb    = 28 + lmcx_config.s.pbank_lsb + xbits;
	dimm_width  = 40 - dimm_lsb;
	prank_lsb   = dimm_lsb - lmcx_config.s.rank_ena;
	prank_width = dimm_lsb - prank_lsb;
	lrank_lsb   = prank_lsb - ext_config.s.dimm0_cid;
	lrank_width = prank_lsb - lrank_lsb;
	row_lsb     = 14 + lmcx_config.s.row_lsb + xbits;
	row_width   = lrank_lsb - row_lsb;
	col_hi_lsb  = bank_lsb + bank_width;
	col_hi_width = row_lsb - col_hi_lsb;

	/* Extract the parts of the address */
	*dimm =  octeontx_bit_extract(address, dimm_lsb, dimm_width);
	*prank = octeontx_bit_extract(address, prank_lsb, prank_width);
	*lrank = octeontx_bit_extract(address, lrank_lsb, lrank_width);
	*row =   octeontx_bit_extract(address, row_lsb, row_width);

	/* bank calculation may be aliased... */
	/* xor_bank not present on CN9XXX */
	*bank = octeontx_bit_extract(address, bank_lsb, bank_width);
	/* LMC number already extracted */
	col_hi = octeontx_bit_extract(address, col_hi_lsb, col_hi_width);

	*col = octeontx_bit_extract(address, 3, 4) | (col_hi << 4);
	/* Bus byte is address bits [2:0]. Unused here */
}

/* NOTE: this copies the result data structure */
static void ras_dram_get_lmc_map(struct ras_dram_lmc_map *map, int lmc)
{
	map->lmc = lmc;

	if (cavm_is_model(OCTEONTX_CN96XX)) {
		map->mcc = (lmc == 1) ? 0 : 1;
		map->lmcoe = (lmc == 2) ? 1 : 0;
	} else if (cavm_is_model(OCTEONTX_CNF95XX)) {
		map->mcc = 0;
		map->lmcoe = (lmc) ? 1 : 0;
	} else {
		ERROR("%s: Error: Unsupported OcteonTX2 model!\n", __func__);
		map->mcc = 0;
		map->lmcoe = 0;
	}
}

static int ras_print_syndrome(char *str, int len, uint8_t syn,
			      union cavm_mccx_lmcoex_ras_int ras_int,
			      union cavm_mccx_lmcoex_ras_err00misc0 misc0,
			      int beat)
{
	int bytebit = ecc_syndrome_to_bytebit[syn];

	if (bytebit) {
		if (ras_int.s.err03 || ras_int.s.err02) {
			if (ras_int.s.err03)
				return snprintf(str, len, "DED=0x%02x",
						0x1 << beat);
			else
				return snprintf(str, len,
						"BYTE %d.%d/0x%02x [%x/%04x]",
						((bytebit >> 4) & 0x0f) - 1,
						bytebit & 0x0f,
						0x1 << beat, misc0.s.of,
						misc0.s.cec);
		} else {
			return snprintf(str, len, "SYN=0x%02x", syn);
		}
	}
	return 0;
}

/*
 * Sketch a fatal-error handler
 * platfoms may override
 * this should move to pm_ops
 */
#pragma weak handle_fatal_ecc_by_reboot
int handle_fatal_ecc_by_reboot = 1;

#pragma weak handle_fatal
void handle_fatal(void)
{
	extern void __dead2 octeontx_scp_sys_reboot(void);

	if (handle_fatal_ecc_by_reboot) {
		/*
		 * System integrity has been compromised,
		 * but pausing to allow UART to drain details to console.
		 * Until we can be sure the ATF secure area is undamaged
		 * this should ideally be a NoWayOut watchdog start
		 * rather than an active delay ...
		 */
		printf("Fatal ERROR: rebooting\n");
		mdelay(1000);
		octeontx_scp_sys_reboot();
	}
}

static void ras_check_double_bit02(int mcc, int lmcoe,
				union cavm_mccx_lmcoex_ras_err00status *status,
				union cavm_mccx_lmcoex_ras_err00addr *erraddr,
				uint64_t *syns_left)
{
	status->u  = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR02STATUS(mcc, lmcoe));
	erraddr->u = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR02ADDR(mcc, lmcoe));
	*syns_left = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR02MISC1(mcc, lmcoe));

	/* Clear Error Interrupts by writing
	 * CAVM_MCCX_LMCOEX_RAS_ERR02STATUS[V]
	 */
	CSR_WRITE(CAVM_MCCX_LMCOEX_RAS_ERR02STATUS(mcc, lmcoe), status->u);
}

static void ras_check_double_bit03(int mcc, int lmcoe,
				union cavm_mccx_lmcoex_ras_err00status *status,
				union cavm_mccx_lmcoex_ras_err00addr *erraddr,
				uint64_t *syns_left)
{
	status->u  = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR03STATUS(mcc, lmcoe));
	erraddr->u = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR03ADDR(mcc, lmcoe));
	*syns_left = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR03MISC1(mcc, lmcoe));

	/* Clear Error Interrupts by writing
	 * CAVM_MCCX_LMCOEX_RAS_ERR02STATUS[V]
	 */
	CSR_WRITE(CAVM_MCCX_LMCOEX_RAS_ERR03STATUS(mcc, lmcoe), status->u);
}

static int ras_check_ecc_errors(int lmc)
{
	struct ras_dram_lmc_map lmc_map;
	union cavm_mccx_lmcoex_ras_int ras_int;
	char *err_type = "";
	char synstr[256];
	int lmc_num = 0;
	int dimm = 0;
	int prank = 0;
	int lrank = 0;
	int bank = 0;
	int row = 0;
	int col = 0;
	int beat = 0;
	int fidx = 0;
	uint64_t syns_left = 0;
	uint64_t address = 0;
	uint64_t physaddr = 0;
	uint64_t lmcaddr = 0;
	union cavm_mccx_lmcoex_ras_err00status status;
	union cavm_mccx_lmcoex_ras_err00addr erraddr;
	union cavm_mccx_lmcoex_ras_err00misc0 misc0;
	union cavm_mccx_lmcoex_ras_int_ena_w1s ras_int_ena;
	int report_err;
	int fatal = 0;

	status.u = 0;
	erraddr.u = 0;
	misc0.u = 0;

	ras_dram_get_lmc_map(&lmc_map, lmc);
	ras_int.u = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERRGSR0(lmc_map.mcc,
							  lmc_map.lmcoe));

	if (!ras_int.u)
		return 0;

	/* use the RAS_INT_ENA bits to say whether we actually had
	 * enabled the interrupts; that is, the ERR0xSTATUS[V] bits are
	 * always current, but we may not desire reporting them
	 */
	ras_int_ena.u = CSR_READ(CAVM_MCCX_LMCOEX_RAS_INT_ENA_W1S(lmc_map.mcc,
							  lmc_map.lmcoe));
	report_err = ((ras_int.u & ras_int_ena.u & 0xFF) != 0);

	/* check for double bit errors only in MCC */
	if ((ras_int.s.err03) || (ras_int.s.err02)) {
		if (ras_int.s.err02)
			ras_check_double_bit02(lmc_map.mcc, lmc_map.lmcoe,
					       &status, &erraddr, &syns_left);
		else if (ras_int.s.err03)
			/* more double bit errors from MCC */
			ras_check_double_bit03(lmc_map.mcc, lmc_map.lmcoe,
					       &status, &erraddr, &syns_left);

		err_type = "double";
		ras_atomic_add64_nosync(&__ras_dram_ecc_double_bit_errors[lmc],
					1);
		fatal++;
	} else if (ras_int.s.err01 || ras_int.s.err00) {
		/* check for single bit errors
		 * else check only when no double bit errs
		 * single bit errors from MCC
		 */
		if (ras_int.s.err00) {
			status.u  = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR00STATUS
						(lmc_map.mcc, lmc_map.lmcoe));
			erraddr.u = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR00ADDR
						(lmc_map.mcc, lmc_map.lmcoe));
			misc0.u   = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR00MISC0
						(lmc_map.mcc, lmc_map.lmcoe));
			syns_left = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR00MISC1
						(lmc_map.mcc, lmc_map.lmcoe));

			/* Clear Error Interrupts by writing
			 * CAVM_MCCX_LMCOEX_RAS_ERR00STATUS[V]
			 */
			CSR_WRITE(CAVM_MCCX_LMCOEX_RAS_ERR00STATUS(lmc_map.mcc,
								lmc_map.lmcoe),
				  status.u);
			CSR_WRITE(CAVM_MCCX_LMCOEX_RAS_ERR00MISC0(lmc_map.mcc,
							lmc_map.lmcoe),
				  0UL);
			/* err_type = "single ERR00"; */
		} else if (ras_int.s.err01) {
			/* more single bit errors from MCC */
			status.u = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR01STATUS
						(lmc_map.mcc, lmc_map.lmcoe));
			erraddr.u = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR01ADDR
						(lmc_map.mcc, lmc_map.lmcoe));
			misc0.u   = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR01MISC0
						(lmc_map.mcc, lmc_map.lmcoe));
			syns_left = CSR_READ(CAVM_MCCX_LMCOEX_RAS_ERR01MISC1
						(lmc_map.mcc, lmc_map.lmcoe));

			/* Clear Error Interrupts by writing
			 * CAVM_MCCX_LMCOEX_RAS_ERR01STATUS[V]
			 */
			CSR_WRITE(CAVM_MCCX_LMCOEX_RAS_ERR01STATUS(lmc_map.mcc,
								 lmc_map.lmcoe),
				  status.u);
			CSR_WRITE(CAVM_MCCX_LMCOEX_RAS_ERR01MISC0(lmc_map.mcc,
								lmc_map.lmcoe),
				  0UL);
			/* err_type = "single ERR01"; */
		}
		err_type = "single";
		ras_atomic_add64_nosync(&__ras_dram_ecc_single_bit_errors[lmc],
					1);
	}

	address = octeontx_bit_extract(erraddr.u, 3, 35) * CACHE_LINE_SIZE;

	/* Display failing cache line index instead of phase string on
	 * CN9XXX
	 */
	fidx = octeontx_bit_extract(erraddr.u, 0, 3);

	if (!report_err) { /* FIXME? use TRACE to control output or not */
		ERROR("%s: N%d.LMC%d: EXTRA ECC: %s @ 0x%016llX (I%02llX/E%02llx)\n",
		      __func__, 0, lmc, err_type, address,
		      ras_int.u & 0x0FUL, ras_int_ena.u & 0x0FUL);

#if PRINT_EXTRA_ECC_ERRORS_CN9XXX
		/* for debugging, enable this to always print all the info
		 * for the "extra" errors
		 */
		ERROR("N%d.LMC%d: EXTRA ECC: %s @ 0x%016llX (I%02llX/E%02llx)\n",
		      0, lmc, err_type, address,
		      ras_int.u & 0x0FUL, ras_int_ena.u & 0x0FUL);
		ras_print_extra_ecc_errors_cn9xxx_lmc(lmc, erraddr, status);
#endif /* PRINT_EXTRA_ECC_ERRORS_CN9XXX */

		return 0; /* we bypass reporting on this LMC */
	}

	/* Add memory offset for previous channels */
	lmcaddr = ras_ccs_get_lmc_addr(address, lmc);
	physaddr = ras_ccs_convert_lmc_to_pa(lmcaddr);
	if (physaddr == (uint64_t)-1) {
		ERROR("N%d.LMC%d: ERROR: LMC to Phys conversion failed: ADDR: 0x%llx, LMC: 0x%llx\n",
		      0, lmc, address, lmcaddr);
		return 0;
	}

	synstr[0] = 0; /* just in case... */
	while (syns_left) {
		int stroff = 0;
		/* Check each byte of the syndrome for error data
		 * each byte represents the syndrome data for one of 8 beats
		 * in a transaction
		 *
		 * The syndrome can hold error data for multiple errors
		 * but if the byte is 0 there's no error
		 */
		if (syns_left & 0xFF)
			stroff += ras_print_syndrome(synstr,
						     sizeof(synstr) - stroff,
						     syns_left & 0xff,
						     ras_int, misc0, beat);
		syns_left >>= 8;
		beat++;
		if (syns_left)
			stroff += snprintf(synstr,
					   sizeof(synstr) - stroff, ", ");
	}

	ras_dram_address_extract_info(lmcaddr, &lmc_num, &dimm,
				      &prank, &lrank, &bank, &row, &col);
	ERROR("N%d.LMC%d: ECC %s (DIMM%d,Rank%d/%d,Bank%02d,Row 0x%05x,Col 0x%04x,FIDX=%d,%s)[0x%012llx]\n",
	      0, lmc, err_type, dimm, prank, lrank, bank, row, col, fidx,
	      synstr, physaddr);

#if PRINT_EXTRA_ECC_ERRORS_CN9XXX
	/* print extra info for "normal" errors if enabled */
	ras_print_extra_ecc_errors_cn9xxx_lmc(lmc, erraddr, status);
#endif /* PRINT_EXTRA_ECC_ERRORS_CN9XXX */
	return fatal;
}

static void ras_check_ecc_errors_cn9xxx(void)
{
	int fatal = 0;

	for (int lmc = 0; lmc < 3; lmc++)
		fatal += ras_check_ecc_errors(lmc);
	if (fatal)
		handle_fatal();
}

static void check_cn9xxx_mdc(void)
{
	union cavm_mdc_int_w1s mdc_int_w1s;
	union cavm_mdc_ecc_status mdc_ecc_status;

	mdc_int_w1s.u = CSR_READ(CAVM_MDC_INT_W1S);
	if (mdc_int_w1s.s.ecc_error) {
		mdc_ecc_status.u = CSR_READ(CAVM_MDC_ECC_STATUS);
		if (mdc_ecc_status.s.dbe)
			ERROR("ERROR: ECC double bit failure, Row 0x%x, Chain %d, Hub %d, Node %d\n",
			      mdc_ecc_status.s.row, mdc_ecc_status.s.chain_id,
			      mdc_ecc_status.s.hub_id,
			      mdc_ecc_status.s.node_id);
		if (mdc_ecc_status.s.dbe_plus)
			ERROR("ERROR: ECC other double bit failures occurred\n");

		if (mdc_ecc_status.s.sbe)
			ERROR("Warning: ECC single bit correction, Row 0x%x, Chain %d, Hub %d, Node %d\n",
			      mdc_ecc_status.s.row, mdc_ecc_status.s.chain_id,
			      mdc_ecc_status.s.hub_id,
			      mdc_ecc_status.s.node_id);
		if (mdc_ecc_status.s.sbe_plus)
			ERROR("ECC other single bit correction occurred\n");
	}
}

static uint64_t tx2_mdc_isr(uint32_t id, uint32_t flags, void *cookie)
{
	union cavm_mdc_ecc_status stat;
	uint64_t mdc_int = CSR_READ(CAVM_MDC_INT_W1C);

	if (!mdc_int)
		return 0;

	stat.u = CSR_READ(CAVM_MDC_ECC_STATUS);
	if (stat.u && edac_alive) {
		INFO("%s: ecc_status: %llx r: %x c: %x h:%x n: %x db:%d+%d sb%d+%d\n",
		      __func__, stat.u, stat.s.row, stat.s.chain_id,
		      stat.s.hub_id, stat.s.node_id,
		      stat.s.dbe_plus, stat.s.dbe,
		      stat.s.sbe_plus, stat.s.sbe);
		check_cn9xxx_mdc();
	}
	CSR_WRITE(CAVM_MDC_INT_W1C, mdc_int);
	return 0;
}

static uint64_t tx2_mcc_isr(uint32_t id, uint32_t flags, void *cookie)
{
	union cavm_mccx_lmcoex_ras_int lmcoe_ras_int;
	union cavm_mccx_const mcc_const;
	int mcc, lmcoe;

	for (mcc = 0; mcc < NUM_MCC; mcc++) {
		mcc_const.u = CSR_READ(CAVM_MCCX_CONST(mcc));
		for (lmcoe = 0; lmcoe < mcc_const.s.lmcs ; lmcoe++) {
			lmcoe_ras_int.u = CSR_READ(CAVM_MCCX_LMCOEX_RAS_INT(mcc,
									lmcoe));
			if (lmcoe_ras_int.u)
				INFO("%s(0x%x, 0x%x, %p) lmcoe_ras_int: 0x%llx\n",
				      __func__, id, flags, cookie,
				      lmcoe_ras_int.u);
		}
	}
	ras_check_ecc_errors_cn9xxx();
	return 0;
}

#ifdef EDAC_POLLED
static int edac_poll(int hd)
{
	/* one call sufficient, it doesn't inspect args ... */
	tx2_mcc_isr(0, 0, NULL);
	return 0;
}
#endif

static int ras_init_mcc(int mcc)
{
	uint64_t bar2 = CAVM_MCC_BAR_E_MCCX_PF_BAR4(mcc);
	int irq;
	union cavm_mccx_config *cfgp = (void *)CAVM_MCCX_CONFIG(mcc);
	union cavm_mccx_config cfg;
	union cavm_mccx_lmcoex_ras_int_ena_w1s int_ena;
	union cavm_mccx_const mc;
	int lmcoe;

	/* Config interrupt vectors */
	int vec;
	uint64_t vaddr;
	uint64_t vctl;
	int rc = 0;

	INFO("%s(%d)\n", __func__, mcc);
	INFO("Installing tx2_mcc_isr\n");


	mc.u = CSR_READ(CAVM_MCCX_CONST(mcc));
	for (lmcoe = 0; lmcoe < mc.s.lmcs; lmcoe++) {
		vec = lmcoe + 0x4;
		vaddr = bar2 + 0x10 * (vec);
		vctl = vaddr + 0x8;

		irq = MCC_SPI_IRQ(vec + mcc * 8);
		rc = register_interrupt_handler(INTR_TYPE_EL3, irq,
						tx2_mcc_isr);
		if (rc) {
			INFO("e?%d tx2_mcc_isr(%x), mcc: %d\n",
			     rc, irq, mcc);
			return rc;
		}

		INFO("Enabling error MSIX interrupt %d for MCC %d, LMCOE %d, vaddr: 0x%llx, vctl: 0x%llx, irq: 0x%x\n",
		     vec, mcc, lmcoe, vaddr, vctl, irq);

		octeontx_write64(vaddr, CAVM_GICD_SETSPI_SR | 1);
		octeontx_write64(vctl, irq);
		octeontx_write64(vaddr + 0x10, CAVM_GICD_CLRSPI_SR | 1);
		octeontx_write64(vctl + 0x10, irq);

		INFO("addr: 0x%llx, ctl: 0x%llx\n",
		     octeontx_read64(vaddr), octeontx_read64(vctl));

		int_ena.u = 0;
		int_ena.s.err00 = 1;
		int_ena.s.err01 = 1;
		int_ena.s.err02 = 1;
		int_ena.s.err03 = 1;
		int_ena.s.err04 = 1;
		int_ena.s.err05 = 1;
		int_ena.s.err06 = 1;
		int_ena.s.err07 = 1;
		CSR_WRITE(CAVM_MCCX_LMCOEX_RAS_INT_ENA_W1S(mcc, lmcoe),
			  int_ena.u);
	}

	INFO("%s done\n", __func__);
	cfg.u = octeontx_read64(cfgp);
	cfg.s.dis_tadpsn = 0;
	cfg.s.dis_tadecc = 0;
	octeontx_write64(cfgp, cfg.u);

	return 0;
}

static int ras_init_mccs(void)
{
	uint64_t vaddr = CAVM_MDC_PF_MSIX_VECX_ADDR(0);
	uint64_t vctl = CAVM_MDC_PF_MSIX_VECX_CTL(0);
	int rc = 0;
	int irq = MDC_SPI_IRQ();
	int mcc;
	int num_mccs = cavm_is_model(OCTEONTX_CNF95XX) ? 1 : 2;

	INFO("%s: %d MCCs\n", __func__, num_mccs);
	for (mcc = 0; mcc < num_mccs; mcc++)
		ras_init_mcc(mcc);

	uint64_t ctl = CAVM_GICD_SETSPI_SR | 1;

	INFO("Registering MCC interrupt handlers\n");
	rc = register_interrupt_handler(INTR_TYPE_EL3, irq, tx2_mdc_isr);
	if (rc) {
		INFO("e?%d tx2_mcc_isr(%x)\n", rc, irq);
		return rc;
	}
	octeontx_write64(vaddr, ctl);
	octeontx_write64(vctl, irq);

	CSR_WRITE(CAVM_MDC_INT_W1C, 1ULL);
	CSR_WRITE(CAVM_MDC_INT_ENA_W1S, 1ULL);

#ifdef EDAC_POLLED
	/* until all IRQs serviced correctly, use 1Hz poll */
	if (edac_timer < 0)
		edac_timer = timer_create(TM_PERIODIC, 1000, edac_poll);
	if (edac_timer >= 0)
		timer_start(edac_timer);
	else
		ERROR("edac_timer error %d\n", edac_timer);
#endif

	edac_alive = 1;

	return 0;
}

int plat_dram_ras_init(void)
{
	INFO("%s\n", __func__);
	switch (MIDR_PARTNUM(read_midr())) {
	case T96PARTNUM:
	case F95PARTNUM:
	case LOKIPARTNUM:
		ras_init_mccs();
		break;
	default:
		ERROR("e: %s: OcteonTX device not supported\n", __func__);
		break;
	}
	INFO("RAS handlers registered\n");
	return 0;
}
