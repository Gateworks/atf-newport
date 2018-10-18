/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <platform_def.h>
#include <cavm_common.h>
#include <string.h>
#include <debug.h>

static inline uint32_t popcnt(uint64_t val)
{
	uint64_t x, x2 = val;

	x2 = x2 - ((x2 >> 1) & 0x5555555555555555ull);
	/* Every 2 bits holds the sum of every pair of bits (32) */
	x2 = ((x2 >> 2) & 0x3333333333333333ull) + (x2 & 0x3333333333333333ull);
	/* Every 4 bits holds the sum of every 4-set of bits (3 significant bits) (16) */
	x2 = (x2 + (x2 >> 4)) & 0x0F0F0F0F0F0F0F0Full;
	/* Every 8 bits holds the sum of every 8-set of bits (4 significant bits) (8) */

	x = x2 * 0x0101010101010101ull >> 56;

	/* The lower 8 bits hold the popcnt */
	return x;  /* (7 significant bits) */
}

uint64_t octeontx_dram_size()
{
	uint64_t rank_size, memsize = 0;
	int num_ranks, lmc;
	int lmc_count;
	union cavm_lmcx_config lmcx_config;

	lmc_count = plat_octeontx_get_lmc_count();
	if (lmc_count < 0) {
		printf("Cannot obtain lmc_count\n");
		return 0;
	}

	for (lmc = 0; lmc < lmc_count; lmc++) {
		if (!plat_octeontx_is_lmc_enabled(lmc))
			continue;

		lmcx_config.u = CSR_READ(CAVM_LMCX_CONFIG(lmc));
		num_ranks = popcnt(lmcx_config.s.init_status);
		rank_size = 1ull << (28 + lmcx_config.s.pbank_lsb - lmcx_config.s.rank_ena);
		memsize += rank_size * num_ranks;
	}

	/* Safenet for ASIM without configured DRAM size */
	if (memsize == 0) {
		ERROR("DRAM size for ASIM/EMUL-platform not configured\n");
		memsize = 2ull << 30; //2GB to align with BDK
	}

	return memsize;
}
