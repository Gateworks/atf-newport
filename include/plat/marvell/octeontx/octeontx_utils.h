/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_UTILS_H__
#define __OCTEONTX_UTILS_H__

#include <arch_helpers.h>

#define IS_OCTEONTX_PASS(midr, partnum, hi, low)			\
	((((midr) >> MIDR_PN_SHIFT & MIDR_PN_MASK) == (partnum)) &&	\
	 (((midr) >> MIDR_VAR_SHIFT & MIDR_VAR_MASK) == (hi) - 1) &&	\
	 (((midr) >> MIDR_REV_SHIFT & MIDR_REV_MASK) == (low)))

#define octeontx_read8(addr)       (*(volatile uint8_t *)(addr))
#define octeontx_read16(addr)      cavm_le16_to_cpu(*(volatile uint16_t *)(addr))
#define octeontx_read32(addr)      cavm_le32_to_cpu(*(volatile uint32_t *)(addr))
#define octeontx_read64(addr)      cavm_le64_to_cpu(*(volatile uint64_t *)(addr))

#define octeontx_write8(addr, val) (*(volatile uint8_t *)(addr) = (val))
#define octeontx_write16(addr, val)        (*(volatile uint16_t *)(addr) = cavm_cpu_to_le16((val)))
#define octeontx_write32(addr, val)        (*(volatile uint32_t *)(addr) = cavm_cpu_to_le32((val)))
#define octeontx_write64(addr, val)        (*(volatile uint64_t *)(addr) = cavm_cpu_to_le64((val)))

/**
 * Builds a bit mask given the required size in bits.
 *
 * @param bits   Number of bits in the mask
 * @return The mask
 */
static inline uint64_t octeontx_build_mask(uint64_t bits)
{
	if (bits == 64)
		return -1;

	return ~((~0x0ull) << bits);
}

/**
 * Extract bits out of a number
 *
 * @param input  Number to extract from
 * @param lsb    Starting bit, least significant (0-63)
 * @param width  Width in bits (1-64)
 *
 * @return Extracted number
 */
static inline uint64_t octeontx_bit_extract(uint64_t input, int lsb, int width)
{
	uint64_t result = input >> lsb;
	result &= octeontx_build_mask(width);
	return result;
}

/**
 * Insert bits into a number
 *
 * @param original Original data, before insert
 * @param input    Data to insert
 * @param lsb    Starting bit, least significant (0-63)
 * @param width  Width in bits (1-64)
 *
 * @return Number with inserted bits
 */
static inline uint64_t octeontx_bit_insert(uint64_t original, uint64_t input, int lsb, int width)
{
	uint64_t mask = octeontx_build_mask(width);
	uint64_t result = original & ~(mask << lsb);
	result |= (input & mask) << lsb;
	return result;
}

#endif /* __OCTEONTX_UTILS_H__ */
