#ifndef __CAVM_CSRS_MDAB_CBP_MEM_H__
#define __CAVM_CSRS_MDAB_CBP_MEM_H__
/* This file is auto-generated. Do not edit */

/***********************license start***********************************
* Copyright (C) 2019 Marvell International Ltd.
* SPDX-License-Identifier: BSD-3-Clause
* https://spdx.org/licenses
***********************license end**************************************/


/**
 * @file
 *
 * Configuration and status register (CSR) address and type definitions for
 * OcteonTX MDAB_CBP_MEM.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) mdab_cbp#_dmem_array#
 *
 * MDAB CBP Data Memory Array Registers
 * This address range provides OCTEON FUSION cores access to any MDAB CBP data memory
 * array. Intended for
 * debug purposes only because RSL accesses are slow.
 *
 * Internal:
 * "SW RESTRICTIONS: When generating RSL addresses please use the following equation:
 *   rsl_byte_address = 0x87E044800000 + (MDAB-ID[5:0] \<\< 17) + (8B_OFFSET[13:0] \<\< 3)
 *   where:
 *     MEMTYP = {0:IMEM/1:DMEM}
 *     MDAB-IDs:
 *       CBP[0:15]:  {0..15}
 *
 *     SW must also be sure to restrict the 8B_OFFSET (based on DSPTYPE/RAMTYPE) as follows:
 *
 *       DSPTYPE    RAMTYPE   8B_OFFSET (range)
 *     ------------------------------------------
 *       cnCBP       DMEM     [0..(16K-1)]
 *
 *     "
 */
union cavm_mdab_cbpx_dmem_arrayx
{
    uint64_t u;
    struct cavm_mdab_cbpx_dmem_arrayx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t qword                 : 64; /**< [ 63:  0](R/W) Quad-word (8-byte) data from DSP data memory. */
#else /* Word 0 - Little Endian */
        uint64_t qword                 : 64; /**< [ 63:  0](R/W) Quad-word (8-byte) data from DSP data memory. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdab_cbpx_dmem_arrayx_s cn; */
};
typedef union cavm_mdab_cbpx_dmem_arrayx cavm_mdab_cbpx_dmem_arrayx_t;

static inline uint64_t CAVM_MDAB_CBPX_DMEM_ARRAYX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDAB_CBPX_DMEM_ARRAYX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=32767)))
        return 0x87e044c00000ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x7fff);
    __cavm_csr_fatal("MDAB_CBPX_DMEM_ARRAYX", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDAB_CBPX_DMEM_ARRAYX(a,b) cavm_mdab_cbpx_dmem_arrayx_t
#define bustype_CAVM_MDAB_CBPX_DMEM_ARRAYX(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDAB_CBPX_DMEM_ARRAYX(a,b) "MDAB_CBPX_DMEM_ARRAYX"
#define busnum_CAVM_MDAB_CBPX_DMEM_ARRAYX(a,b) (a)
#define arguments_CAVM_MDAB_CBPX_DMEM_ARRAYX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdab_cbp#_imem_array#
 *
 * MDAB Instruction Memory Array Registers
 * This address range provides OCTEON TX2 cores access to any MDAB instruction memory array. Intended
 * for debug purposes only because RSL accesses are slow.
 *
 * Internal:
 * "SW RESTRICTIONS: When generating RSL addresses please use the following equation:
 *   rsl_byte_address = 0x87E044400000 + (MDAB-ID[5:0] \<\< 16) + (8B_OFFSET[12:0] \<\< 3)
 *    where:
 *     MDAB-IDs:
 *       CBP[0:15]:  {0..15}
 *
 *     SW must also be sure to restrict the 8B_OFFSET (based on DSPTYPE/RAMTYPE) as follows:
 *
 *       DSPTYPE    RAMTYPE   8B_OFFSET (range)
 *     ------------------------------------------
 *       cnCBP       IMEM     [0..(8K-1)]
 *
 *     "
 */
union cavm_mdab_cbpx_imem_arrayx
{
    uint64_t u;
    struct cavm_mdab_cbpx_imem_arrayx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t qword                 : 64; /**< [ 63:  0](WO) Quad-word (8-byte) data from DSP program memory. */
#else /* Word 0 - Little Endian */
        uint64_t qword                 : 64; /**< [ 63:  0](WO) Quad-word (8-byte) data from DSP program memory. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdab_cbpx_imem_arrayx_s cn; */
};
typedef union cavm_mdab_cbpx_imem_arrayx cavm_mdab_cbpx_imem_arrayx_t;

static inline uint64_t CAVM_MDAB_CBPX_IMEM_ARRAYX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDAB_CBPX_IMEM_ARRAYX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=16383)))
        return 0x87e044800000ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x3fff);
    __cavm_csr_fatal("MDAB_CBPX_IMEM_ARRAYX", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDAB_CBPX_IMEM_ARRAYX(a,b) cavm_mdab_cbpx_imem_arrayx_t
#define bustype_CAVM_MDAB_CBPX_IMEM_ARRAYX(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDAB_CBPX_IMEM_ARRAYX(a,b) "MDAB_CBPX_IMEM_ARRAYX"
#define busnum_CAVM_MDAB_CBPX_IMEM_ARRAYX(a,b) (a)
#define arguments_CAVM_MDAB_CBPX_IMEM_ARRAYX(a,b) (a),(b),-1,-1

#endif /* __CAVM_CSRS_MDAB_CBP_MEM_H__ */
