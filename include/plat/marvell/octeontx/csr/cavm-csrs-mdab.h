#ifndef __CAVM_CSRS_MDAB_H__
#define __CAVM_CSRS_MDAB_H__
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
 * OcteonTX MDAB.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL32b) mdab#_cfg_addr
 *
 * MDAB Configuration DMA Address Register
 * The starting address used by the CFG DMA engine when writing the job configuration to local
 * DSP memory.
 */
union cavm_mdabx_cfg_addr
{
    uint64_t u;
    struct cavm_mdabx_cfg_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31_63        : 33;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W) The 128b-aligned starting address used by the CFG-DMA engine when writing the job
                                                                 configuration to local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4).
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4).
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4).
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4).
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines which DSP Memory space
                                                                 (0:DMEM/1:IMEM). */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W) The 128b-aligned starting address used by the CFG-DMA engine when writing the job
                                                                 configuration to local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4).
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4).
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4).
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4).
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines which DSP Memory space
                                                                 (0:DMEM/1:IMEM). */
        uint64_t reserved_31_63        : 33;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_cfg_addr_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31           : 1;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W) The 128b-aligned starting address used by the CFG-DMA engine when writing the job
                                                                 configuration to local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4).
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4).
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4).
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4).
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines which DSP Memory space
                                                                 (0:DMEM/1:IMEM). */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W) The 128b-aligned starting address used by the CFG-DMA engine when writing the job
                                                                 configuration to local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4).
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4).
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4).
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4).
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines which DSP Memory space
                                                                 (0:DMEM/1:IMEM). */
        uint64_t reserved_31           : 1;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_cfg_addr_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_31        : 9;
        uint64_t addr                  : 19; /**< [ 22:  4](R/W) The 128 bit-aligned starting address used by the CFG DMA engine when writing the job
                                                                 configuration to local DSP memory.

                                                                 _ When ADDR[22:21] is 0x0 (dTCM/DMEM), valid 128-bit-aligned address range = 0x0
                                                                 - (0x03_FFFF \>\> 4).
                                                                 _ When ADDR[22:21] is 0x1 (pTCM/IMEM), valid 128-bit-aligned address range =
                                                                 (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4).
                                                                 _ When ADDR[22:21] is 0x2 (CPM registers), valid 128-bit-aligned address range =
                                                                 (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4). */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 19; /**< [ 22:  4](R/W) The 128 bit-aligned starting address used by the CFG DMA engine when writing the job
                                                                 configuration to local DSP memory.

                                                                 _ When ADDR[22:21] is 0x0 (dTCM/DMEM), valid 128-bit-aligned address range = 0x0
                                                                 - (0x03_FFFF \>\> 4).
                                                                 _ When ADDR[22:21] is 0x1 (pTCM/IMEM), valid 128-bit-aligned address range =
                                                                 (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4).
                                                                 _ When ADDR[22:21] is 0x2 (CPM registers), valid 128-bit-aligned address range =
                                                                 (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4). */
        uint64_t reserved_23_31        : 9;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_cfg_addr cavm_mdabx_cfg_addr_t;

static inline uint64_t CAVM_MDABX_CFG_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_CFG_ADDR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100030ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400030ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_CFG_ADDR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_CFG_ADDR(a) cavm_mdabx_cfg_addr_t
#define bustype_CAVM_MDABX_CFG_ADDR(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_CFG_ADDR(a) "MDABX_CFG_ADDR"
#define busnum_CAVM_MDABX_CFG_ADDR(a) (a)
#define arguments_CAVM_MDABX_CFG_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_cfg_length
 *
 * MDAB Configuration DMA Length Register
 * The actual 128-bit length of the most recent CFG DMA engine job configuration transfer.
 */
union cavm_mdabx_cfg_length
{
    uint64_t u;
    struct cavm_mdabx_cfg_length_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent CFG-DMA engine job configuration transfer.
                                                                 NOTE: This field will be updated when the CFG-DMA has been actually write committed to
                                                                 local DSP memory,
                                                                 which allows software to read (poll) the length field during the CFG-DMA transfer to know how
                                                                 many 128-bit chunks are
                                                                 now currently available to be read and used. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent CFG-DMA engine job configuration transfer.
                                                                 NOTE: This field will be updated when the CFG-DMA has been actually write committed to
                                                                 local DSP memory,
                                                                 which allows software to read (poll) the length field during the CFG-DMA transfer to know how
                                                                 many 128-bit chunks are
                                                                 now currently available to be read and used. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_cfg_length_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_31        : 13;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent CFG-DMA engine job configuration transfer.
                                                                 NOTE: This field will be updated when the CFG-DMA has been actually write committed to
                                                                 local DSP memory,
                                                                 which allows software to read (poll) the length field during the CFG-DMA transfer to know how
                                                                 many 128-bit chunks are
                                                                 now currently available to be read and used. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent CFG-DMA engine job configuration transfer.
                                                                 NOTE: This field will be updated when the CFG-DMA has been actually write committed to
                                                                 local DSP memory,
                                                                 which allows software to read (poll) the length field during the CFG-DMA transfer to know how
                                                                 many 128-bit chunks are
                                                                 now currently available to be read and used. */
        uint64_t reserved_19_31        : 13;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_cfg_length_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_31        : 14;
        uint64_t length                : 14; /**< [ 17:  4](RO/H) The actual 128-bit length of the most recent CFG-DMA engine job configuration transfer.

                                                                 Note: This field will be updated when the CFG DMA has been actually write committed to
                                                                 local DSP memory,
                                                                 which allows software to read (poll) the length field during the CFG DMA transfer to know how
                                                                 many 128-bit chunks are
                                                                 now currently available to be read and used. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t length                : 14; /**< [ 17:  4](RO/H) The actual 128-bit length of the most recent CFG-DMA engine job configuration transfer.

                                                                 Note: This field will be updated when the CFG DMA has been actually write committed to
                                                                 local DSP memory,
                                                                 which allows software to read (poll) the length field during the CFG DMA transfer to know how
                                                                 many 128-bit chunks are
                                                                 now currently available to be read and used. */
        uint64_t reserved_18_31        : 14;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_cfg_length cavm_mdabx_cfg_length_t;

static inline uint64_t CAVM_MDABX_CFG_LENGTH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_CFG_LENGTH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100050ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400050ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_CFG_LENGTH", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_CFG_LENGTH(a) cavm_mdabx_cfg_length_t
#define bustype_CAVM_MDABX_CFG_LENGTH(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_CFG_LENGTH(a) "MDABX_CFG_LENGTH"
#define busnum_CAVM_MDABX_CFG_LENGTH(a) (a)
#define arguments_CAVM_MDABX_CFG_LENGTH(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_cfg_limit
 *
 * MDAB Configuration DMA Limit Register
 * The maximum number of 128-bit sized chunks that the CFG DMA engine may write starting from the
 * 128-bit-aligned MDAB()_CFG_ADDR.
 */
union cavm_mdabx_cfg_limit
{
    uint64_t u;
    struct cavm_mdabx_cfg_limit_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last CFG-DMA slice which may be written to address MDAB()_CFG_ADDR.
                                                                 DSP software may choose to segment the JD.CFG-DMA data into multiple non-contiguous CFG-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final CFG-DMA sub-blk transfer.
                                                                 Each CFG-DMA operation's LAST will indicate when the last segment (or slice) CFG-DMA
                                                                 operation has been set up, to complete the JD.CFG-DMA data transfer.
                                                                 SW_NOTE: For every new CFG-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.CFG-DMA data slice transfer. */
        uint64_t reserved_19_30        : 12;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W) "The maximum number of 128-bit chunks that the CFG-DMA engine may write at address
                                                                 MDAB()_CFG_ADDR.
                                                                 Typically, DSP software will allocate LIMIT buffer space (max) to be larger than the JD.JCFG
                                                                 data. DSP software is at liberty to break the total CFG-DMA transfer into multiples segments (or
                                                                 DMA slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.JCFG data is detected), the CFG-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W) "The maximum number of 128-bit chunks that the CFG-DMA engine may write at address
                                                                 MDAB()_CFG_ADDR.
                                                                 Typically, DSP software will allocate LIMIT buffer space (max) to be larger than the JD.JCFG
                                                                 data. DSP software is at liberty to break the total CFG-DMA transfer into multiples segments (or
                                                                 DMA slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.JCFG data is detected), the CFG-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_19_30        : 12;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last CFG-DMA slice which may be written to address MDAB()_CFG_ADDR.
                                                                 DSP software may choose to segment the JD.CFG-DMA data into multiple non-contiguous CFG-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final CFG-DMA sub-blk transfer.
                                                                 Each CFG-DMA operation's LAST will indicate when the last segment (or slice) CFG-DMA
                                                                 operation has been set up, to complete the JD.CFG-DMA data transfer.
                                                                 SW_NOTE: For every new CFG-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.CFG-DMA data slice transfer. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_cfg_limit_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last CFG-DMA slice which may be written to address MDAB()_CFG_ADDR.
                                                                 DSP software may choose to segment the JD.CFG-DMA data into multiple non-contiguous CFG-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final CFG-DMA sub-blk transfer.
                                                                 Each CFG-DMA operation's LAST will indicate when the last segment (or slice) CFG-DMA
                                                                 operation has been set up, to complete the JD.CFG-DMA data transfer.
                                                                 SW_NOTE: For every new CFG-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.CFG-DMA data slice transfer. */
        uint64_t reserved_19_30        : 12;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W) "The maximum number of 128-bit chunks that the CFG-DMA engine may write at address
                                                                 MDAB()_CFG_ADDR.
                                                                 Typically, DSP software will allocate LIMIT buffer space (max) to be larger than the JD.JCFG
                                                                 data. DSP software is at liberty to break the total CFG-DMA transfer into multiples segments (or
                                                                 DMA slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.JCFG data is detected), the CFG-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W) "The maximum number of 128-bit chunks that the CFG-DMA engine may write at address
                                                                 MDAB()_CFG_ADDR.
                                                                 Typically, DSP software will allocate LIMIT buffer space (max) to be larger than the JD.JCFG
                                                                 data. DSP software is at liberty to break the total CFG-DMA transfer into multiples segments (or
                                                                 DMA slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.JCFG data is detected), the CFG-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_19_30        : 12;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last CFG-DMA slice which may be written to address MDAB()_CFG_ADDR.
                                                                 DSP software may choose to segment the JD.CFG-DMA data into multiple non-contiguous CFG-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final CFG-DMA sub-blk transfer.
                                                                 Each CFG-DMA operation's LAST will indicate when the last segment (or slice) CFG-DMA
                                                                 operation has been set up, to complete the JD.CFG-DMA data transfer.
                                                                 SW_NOTE: For every new CFG-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.CFG-DMA data slice transfer. */
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_cfg_limit_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last CFG-DMA slice which may be written to address MDAB()_CFG_ADDR.
                                                                 DSP software may choose to segment the JD.CFG DMA data into multiple noncontiguous CFG DMA
                                                                 transfers to DSP local memory.

                                                                 Eventually, DSP software will indicate the [LAST] segment (or slice), to indicate this is
                                                                 the final CFG DMA sub-block transfer.
                                                                 Each CFG DMA operation's [LAST] will indicate when the last segment (or slice) CFG DMA
                                                                 operation has been set up, to complete the JD.CFG DMA data transfer.

                                                                 Software note: For every new CFG DMA slice operation, DSP software must signal [LAST] to indicate
                                                                 the final JD.CFG DMA data slice transfer. */
        uint64_t reserved_18_30        : 13;
        uint64_t limit                 : 14; /**< [ 17:  4](R/W) "The maximum number of 128-bit chunks that the CFG DMA engine may write at address
                                                                 MDAB()_CFG_ADDR.

                                                                 Typically, DSP software will allocate [LIMIT] buffer space (max) to be larger than the JD.JCFG
                                                                 data. DSP software is at liberty to break the total CFG DMA transfer into multiples segments (or
                                                                 DMA slices) using the LIMIT register. When either [LIMIT] has been reached (or if the last
                                                                 JD.JCFG data is detected), the CFG DMA is done.

                                                                 _ dTCM/DMEM: 0x0 - (0x03_FFFF \>\> 4).
                                                                 _ pTCM/IMEM: (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4).
                                                                 _ CPM registers: (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4).

                                                                 Software restriction #1: Software should never program [LIMIT] = 0x0.
                                                                 Indeterminate results can/will occur.

                                                                 Software restriction #2: Software should ensure that ADDR+LIMIT sizes fall
                                                                 within the instruction and data memory
                                                                 space; otherwise [DMA_ERROR] and indeterminate results can/will occur." */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t limit                 : 14; /**< [ 17:  4](R/W) "The maximum number of 128-bit chunks that the CFG DMA engine may write at address
                                                                 MDAB()_CFG_ADDR.

                                                                 Typically, DSP software will allocate [LIMIT] buffer space (max) to be larger than the JD.JCFG
                                                                 data. DSP software is at liberty to break the total CFG DMA transfer into multiples segments (or
                                                                 DMA slices) using the LIMIT register. When either [LIMIT] has been reached (or if the last
                                                                 JD.JCFG data is detected), the CFG DMA is done.

                                                                 _ dTCM/DMEM: 0x0 - (0x03_FFFF \>\> 4).
                                                                 _ pTCM/IMEM: (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4).
                                                                 _ CPM registers: (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4).

                                                                 Software restriction #1: Software should never program [LIMIT] = 0x0.
                                                                 Indeterminate results can/will occur.

                                                                 Software restriction #2: Software should ensure that ADDR+LIMIT sizes fall
                                                                 within the instruction and data memory
                                                                 space; otherwise [DMA_ERROR] and indeterminate results can/will occur." */
        uint64_t reserved_18_30        : 13;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last CFG-DMA slice which may be written to address MDAB()_CFG_ADDR.
                                                                 DSP software may choose to segment the JD.CFG DMA data into multiple noncontiguous CFG DMA
                                                                 transfers to DSP local memory.

                                                                 Eventually, DSP software will indicate the [LAST] segment (or slice), to indicate this is
                                                                 the final CFG DMA sub-block transfer.
                                                                 Each CFG DMA operation's [LAST] will indicate when the last segment (or slice) CFG DMA
                                                                 operation has been set up, to complete the JD.CFG DMA data transfer.

                                                                 Software note: For every new CFG DMA slice operation, DSP software must signal [LAST] to indicate
                                                                 the final JD.CFG DMA data slice transfer. */
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_cfg_limit cavm_mdabx_cfg_limit_t;

static inline uint64_t CAVM_MDABX_CFG_LIMIT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_CFG_LIMIT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100040ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400040ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_CFG_LIMIT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_CFG_LIMIT(a) cavm_mdabx_cfg_limit_t
#define bustype_CAVM_MDABX_CFG_LIMIT(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_CFG_LIMIT(a) "MDABX_CFG_LIMIT"
#define busnum_CAVM_MDABX_CFG_LIMIT(a) (a)
#define arguments_CAVM_MDABX_CFG_LIMIT(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_cfg_status
 *
 * MDAB Configuration DMA Status Register
 * Reports the status for the CFG DMA engine.
 */
union cavm_mdabx_cfg_status
{
    uint64_t u;
    struct cavm_mdabx_cfg_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed CFG-DMA operation.
                                                                  When DSP software writes START_BUSY=0-\>1, the CFG-DMA engine will wait until the next
                                                                  available Job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_10_15        : 6;
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending CFG-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent CFG-DMA operation. */
        uint64_t reserved_7            : 1;
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last CFG-DMA operation encountered an underflow. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last CFG-DMA operation encountered an overflow. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last CFG-DMA operation encountered an error. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last CFG-DMA operation transferred the last word of the job configuration
                                                                 section from the job descriptor. */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a CFG-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the CFG-DMA engine starts its first
                                                                 CFG-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used by software to know
                                                                 when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1. */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job configuration
                                                                 section(JD.JCFG) for the next available job into the local memory starting at
                                                                 MDAB()_CFG_ADDR, up to
                                                                 MDAB()_CFG_ADDR+MDAB()_CFG_LIMIT or until the last JD.JCFG data has been transferred.
                                                                 If the CFG-DMA engine has already transferred part but not all of the JD.JCFG section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.JCFG
                                                                 section, or until it writes
                                                                 MDAB()_CFG_LIMIT for the LAST CFG-DMA slice, whichever comes first. This bit is reset to
                                                                 zero when the
                                                                 CFG-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
#else /* Word 0 - Little Endian */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job configuration
                                                                 section(JD.JCFG) for the next available job into the local memory starting at
                                                                 MDAB()_CFG_ADDR, up to
                                                                 MDAB()_CFG_ADDR+MDAB()_CFG_LIMIT or until the last JD.JCFG data has been transferred.
                                                                 If the CFG-DMA engine has already transferred part but not all of the JD.JCFG section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.JCFG
                                                                 section, or until it writes
                                                                 MDAB()_CFG_LIMIT for the LAST CFG-DMA slice, whichever comes first. This bit is reset to
                                                                 zero when the
                                                                 CFG-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the CFG-DMA engine starts its first
                                                                 CFG-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used by software to know
                                                                 when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1. */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a CFG-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last CFG-DMA operation transferred the last word of the job configuration
                                                                 section from the job descriptor. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last CFG-DMA operation encountered an error. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last CFG-DMA operation encountered an overflow. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last CFG-DMA operation encountered an underflow. */
        uint64_t reserved_7            : 1;
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent CFG-DMA operation. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending CFG-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t reserved_10_15        : 6;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed CFG-DMA operation.
                                                                  When DSP software writes START_BUSY=0-\>1, the CFG-DMA engine will wait until the next
                                                                  available Job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_cfg_status_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed CFG-DMA operation.
                                                                  When DSP software writes START_BUSY=0-\>1, the CFG-DMA engine will wait until the next
                                                                  available Job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_10_15        : 6;
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending CFG-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent CFG-DMA operation. */
        uint64_t reserved_7            : 1;
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last CFG-DMA operation encountered an underflow. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last CFG-DMA operation encountered an overflow. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last CFG-DMA operation encountered an error. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last CFG-DMA operation transferred the last word of the job configuration
                                                                 section from the job descriptor. */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a CFG-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the CFG-DMA engine starts its first
                                                                 CFG-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used by software to know
                                                                 when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1. */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job configuration
                                                                 section(JD.JCFG) for the next available job into the local memory starting at
                                                                 MDAB()_CFG_ADDR, up to
                                                                 MDAB()_CFG_ADDR+MDAB()_CFG_LIMIT or until the last JD.JCFG data has been transferred.
                                                                 If the CFG-DMA engine has already transferred part but not all of the JD.JCFG section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.JCFG
                                                                 section, or until it writes
                                                                 MDAB()_CFG_LIMIT for the LAST CFG-DMA slice, whichever comes first. This bit is reset to
                                                                 zero when the
                                                                 CFG-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
#else /* Word 0 - Little Endian */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job configuration
                                                                 section(JD.JCFG) for the next available job into the local memory starting at
                                                                 MDAB()_CFG_ADDR, up to
                                                                 MDAB()_CFG_ADDR+MDAB()_CFG_LIMIT or until the last JD.JCFG data has been transferred.
                                                                 If the CFG-DMA engine has already transferred part but not all of the JD.JCFG section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.JCFG
                                                                 section, or until it writes
                                                                 MDAB()_CFG_LIMIT for the LAST CFG-DMA slice, whichever comes first. This bit is reset to
                                                                 zero when the
                                                                 CFG-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the CFG-DMA engine starts its first
                                                                 CFG-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used by software to know
                                                                 when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1. */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a CFG-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last CFG-DMA operation transferred the last word of the job configuration
                                                                 section from the job descriptor. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last CFG-DMA operation encountered an error. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last CFG-DMA operation encountered an overflow. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last CFG-DMA operation encountered an underflow. */
        uint64_t reserved_7            : 1;
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent CFG-DMA operation. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending CFG-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t reserved_10_15        : 6;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed CFG-DMA operation.
                                                                  When DSP software writes START_BUSY=0-\>1, the CFG-DMA engine will wait until the next
                                                                  available Job has been enqueued, at which point the JOB_TAG will be latched in. */
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_cfg_status_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed CFG DMA operation.
                                                                  When DSP software writes [START_BUSY] = 0 -\> 1, the CFG DMA engine will wait until the next
                                                                  available job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_10_15        : 6;
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending CFG DMA operation. Valid only when [START_BUSY] is 0 and
                                                                 [DMA_PENDING] is 1. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent CFG DMA operation. */
        uint64_t reserved_7            : 1;
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last CFG DMA operation encountered an underflow. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last CFG DMA operation encountered an overflow. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last CFG DMA operation encountered an error. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last CFG DMA operation transferred the last word of the job configuration
                                                                 section from the job descriptor. */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a CFG DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the CFG DMA engine starts its first
                                                                 CFG DMA transfer.

                                                                 Software note: DSP software can use this bit to qualify the [JOB_TAG],
                                                                 [JOB_SLOT], [DMA_ERROR], and [LAST_DMA_DONE]
                                                                 bits in this CSR. These status bits remain set and POST_RESET is used by software to know
                                                                 when they are truly valid.

                                                                 Set (hardware) = MDAB reset.

                                                                 Clear (software) = DSP writes [START_BUSY] = 0 -\> 1. */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job configuration
                                                                 section (JD.JCFG) for the next available job into the local memory starting at
                                                                 MDAB()_CFG_ADDR, up to
                                                                 MDAB()_CFG_ADDR+MDAB()_CFG_LIMIT or until the last JD.JCFG data has been transferred.
                                                                 If the CFG DMA engine has already transferred part but not all of the JD.JCFG section for
                                                                 a job, it will continue transferring data until it reaches the end of the JD.JCFG
                                                                 section, or until it writes
                                                                 MDAB()_CFG_LIMIT for the last CFG DMA slice, whichever comes first.

                                                                 This bit is reset to zero when the
                                                                 CFG DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
#else /* Word 0 - Little Endian */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job configuration
                                                                 section (JD.JCFG) for the next available job into the local memory starting at
                                                                 MDAB()_CFG_ADDR, up to
                                                                 MDAB()_CFG_ADDR+MDAB()_CFG_LIMIT or until the last JD.JCFG data has been transferred.
                                                                 If the CFG DMA engine has already transferred part but not all of the JD.JCFG section for
                                                                 a job, it will continue transferring data until it reaches the end of the JD.JCFG
                                                                 section, or until it writes
                                                                 MDAB()_CFG_LIMIT for the last CFG DMA slice, whichever comes first.

                                                                 This bit is reset to zero when the
                                                                 CFG DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the CFG DMA engine starts its first
                                                                 CFG DMA transfer.

                                                                 Software note: DSP software can use this bit to qualify the [JOB_TAG],
                                                                 [JOB_SLOT], [DMA_ERROR], and [LAST_DMA_DONE]
                                                                 bits in this CSR. These status bits remain set and POST_RESET is used by software to know
                                                                 when they are truly valid.

                                                                 Set (hardware) = MDAB reset.

                                                                 Clear (software) = DSP writes [START_BUSY] = 0 -\> 1. */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a CFG DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last CFG DMA operation transferred the last word of the job configuration
                                                                 section from the job descriptor. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last CFG DMA operation encountered an error. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last CFG DMA operation encountered an overflow. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last CFG DMA operation encountered an underflow. */
        uint64_t reserved_7            : 1;
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent CFG DMA operation. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending CFG DMA operation. Valid only when [START_BUSY] is 0 and
                                                                 [DMA_PENDING] is 1. */
        uint64_t reserved_10_15        : 6;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed CFG DMA operation.
                                                                  When DSP software writes [START_BUSY] = 0 -\> 1, the CFG DMA engine will wait until the next
                                                                  available job has been enqueued, at which point the JOB_TAG will be latched in. */
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_cfg_status cavm_mdabx_cfg_status_t;

static inline uint64_t CAVM_MDABX_CFG_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_CFG_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100020ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400020ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_CFG_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_CFG_STATUS(a) cavm_mdabx_cfg_status_t
#define bustype_CAVM_MDABX_CFG_STATUS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_CFG_STATUS(a) "MDABX_CFG_STATUS"
#define busnum_CAVM_MDABX_CFG_STATUS(a) (a)
#define arguments_CAVM_MDABX_CFG_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_dac_eco
 *
 * INTERNAL: DAC ECO Register
 *
 * Internal:
 * Reserved for ECO usage
 */
union cavm_mdabx_dac_eco
{
    uint64_t u;
    struct cavm_mdabx_dac_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_dac_eco_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_dac_eco cavm_mdabx_dac_eco_t;

static inline uint64_t CAVM_MDABX_DAC_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_DAC_ECO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100300ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400300ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_DAC_ECO", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_DAC_ECO(a) cavm_mdabx_dac_eco_t
#define bustype_CAVM_MDABX_DAC_ECO(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_DAC_ECO(a) "MDABX_DAC_ECO"
#define busnum_CAVM_MDABX_DAC_ECO(a) (a)
#define arguments_CAVM_MDABX_DAC_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_dac_membase_hi
 *
 * DAC Address Offset Upper Bits Register
 * This register provides the upper bits of a 1MB aligned base address that is added to
 * dac-gaa requests before
 * the address in system memory space is issued on the dac-\>gaa r/w request bus.
 * This register and the corresponding DAC_MEMBASE_LO register should only be programmed
 * when the DAC is idle.
 */
union cavm_mdabx_dac_membase_hi
{
    uint32_t u;
    struct cavm_mdabx_dac_membase_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_21_31        : 11;
        uint32_t dac_membase_hi        : 21; /**< [ 20:  0](R/W) When the DSP issues a read or write request to system memory space on the dac-\>gaa i/f, this
                                                                 1MB-aligned offset addr[52:20] is added to the DSP address to provide access to any
                                                                 physical address in the system memory space. This field provides bits [52:32]. */
#else /* Word 0 - Little Endian */
        uint32_t dac_membase_hi        : 21; /**< [ 20:  0](R/W) When the DSP issues a read or write request to system memory space on the dac-\>gaa i/f, this
                                                                 1MB-aligned offset addr[52:20] is added to the DSP address to provide access to any
                                                                 physical address in the system memory space. This field provides bits [52:32]. */
        uint32_t reserved_21_31        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_dac_membase_hi_s cn; */
};
typedef union cavm_mdabx_dac_membase_hi cavm_mdabx_dac_membase_hi_t;

static inline uint64_t CAVM_MDABX_DAC_MEMBASE_HI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_DAC_MEMBASE_HI(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100450ll + 0x4000ll * ((a) & 0x3f);
    __cavm_csr_fatal("MDABX_DAC_MEMBASE_HI", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_DAC_MEMBASE_HI(a) cavm_mdabx_dac_membase_hi_t
#define bustype_CAVM_MDABX_DAC_MEMBASE_HI(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_DAC_MEMBASE_HI(a) "MDABX_DAC_MEMBASE_HI"
#define busnum_CAVM_MDABX_DAC_MEMBASE_HI(a) (a)
#define arguments_CAVM_MDABX_DAC_MEMBASE_HI(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_dac_membase_lo
 *
 * DAC Address Offset Lower Bits Register
 * This register provides the lower bits of a 1MB aligned base address that is added to
 * dac-gaa requests before
 * the address in system memory space is issued on the dac-\>gaa r/w request bus.
 * This register and the corresponding DAC_MEMBASE_HI register should only be programmed
 * when the DAC is idle.
 */
union cavm_mdabx_dac_membase_lo
{
    uint32_t u;
    struct cavm_mdabx_dac_membase_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dac_membase_lo        : 12; /**< [ 31: 20](R/W) When the DSP issues a read or write request to system memory space on the dac-\>gaa i/f, this
                                                                 1MB-aligned offset addr[52:20] is added to the DSP address to provide access to any
                                                                 physical address in the system memory space. This field provides the lower bits [31:20]. */
        uint32_t reserved_0_19         : 20;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_19         : 20;
        uint32_t dac_membase_lo        : 12; /**< [ 31: 20](R/W) When the DSP issues a read or write request to system memory space on the dac-\>gaa i/f, this
                                                                 1MB-aligned offset addr[52:20] is added to the DSP address to provide access to any
                                                                 physical address in the system memory space. This field provides the lower bits [31:20]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_dac_membase_lo_s cn; */
};
typedef union cavm_mdabx_dac_membase_lo cavm_mdabx_dac_membase_lo_t;

static inline uint64_t CAVM_MDABX_DAC_MEMBASE_LO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_DAC_MEMBASE_LO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100440ll + 0x4000ll * ((a) & 0x3f);
    __cavm_csr_fatal("MDABX_DAC_MEMBASE_LO", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_DAC_MEMBASE_LO(a) cavm_mdabx_dac_membase_lo_t
#define bustype_CAVM_MDABX_DAC_MEMBASE_LO(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_DAC_MEMBASE_LO(a) "MDABX_DAC_MEMBASE_LO"
#define busnum_CAVM_MDABX_DAC_MEMBASE_LO(a) (a)
#define arguments_CAVM_MDABX_DAC_MEMBASE_LO(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_dac_timer
 *
 * MDAB DAC Timer Register
 * This register contains a local timer that is incremented every [TICK_DIV] DSPCLK cycles.
 */
union cavm_mdabx_dac_timer
{
    uint64_t u;
    struct cavm_mdabx_dac_timer_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t tick_div              : 8;  /**< [ 31: 24](R/W) Timer divider value. When [TICK_DIV] is 0, [TICK] increments every 256 DSPCLK cycles. */
        uint64_t reserved_16_23        : 8;
        uint64_t tick                  : 16; /**< [ 15:  0](RO/H) Local timer. Increments every [TICK_DIV] DSPCLK cycles. */
#else /* Word 0 - Little Endian */
        uint64_t tick                  : 16; /**< [ 15:  0](RO/H) Local timer. Increments every [TICK_DIV] DSPCLK cycles. */
        uint64_t reserved_16_23        : 8;
        uint64_t tick_div              : 8;  /**< [ 31: 24](R/W) Timer divider value. When [TICK_DIV] is 0, [TICK] increments every 256 DSPCLK cycles. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_dac_timer_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tick_div              : 8;  /**< [ 31: 24](R/W) Timer divider value. When [TICK_DIV] is 0, [TICK] increments every 256 DSPCLK cycles. */
        uint64_t reserved_16_23        : 8;
        uint64_t tick                  : 16; /**< [ 15:  0](RO/H) Local timer. Increments every [TICK_DIV] DSPCLK cycles. */
#else /* Word 0 - Little Endian */
        uint64_t tick                  : 16; /**< [ 15:  0](RO/H) Local timer. Increments every [TICK_DIV] DSPCLK cycles. */
        uint64_t reserved_16_23        : 8;
        uint64_t tick_div              : 8;  /**< [ 31: 24](R/W) Timer divider value. When [TICK_DIV] is 0, [TICK] increments every 256 DSPCLK cycles. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_dac_timer cavm_mdabx_dac_timer_t;

static inline uint64_t CAVM_MDABX_DAC_TIMER(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_DAC_TIMER(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100210ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400210ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_DAC_TIMER", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_DAC_TIMER(a) cavm_mdabx_dac_timer_t
#define bustype_CAVM_MDABX_DAC_TIMER(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_DAC_TIMER(a) "MDABX_DAC_TIMER"
#define busnum_CAVM_MDABX_DAC_TIMER(a) (a)
#define arguments_CAVM_MDABX_DAC_TIMER(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_dsp_cnf
 *
 * MDAB DSP Configuration Register
 * Set Configuration Values Driven on the DSP I/f, which changes the DSP WH behaviour.
 */
union cavm_mdabx_dsp_cnf
{
    uint32_t u;
    struct cavm_mdabx_dsp_cnf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t axi_b                 : 1;  /**< [  0:  0](R/W) Limits the DSP burst size to BL4. 0x1 - limit, 0x0-no limit. */
#else /* Word 0 - Little Endian */
        uint32_t axi_b                 : 1;  /**< [  0:  0](R/W) Limits the DSP burst size to BL4. 0x1 - limit, 0x0-no limit. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_dsp_cnf_s cn; */
};
typedef union cavm_mdabx_dsp_cnf cavm_mdabx_dsp_cnf_t;

static inline uint64_t CAVM_MDABX_DSP_CNF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_DSP_CNF(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400b10ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_DSP_CNF", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_DSP_CNF(a) cavm_mdabx_dsp_cnf_t
#define bustype_CAVM_MDABX_DSP_CNF(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_DSP_CNF(a) "MDABX_DSP_CNF"
#define busnum_CAVM_MDABX_DSP_CNF(a) (a)
#define arguments_CAVM_MDABX_DSP_CNF(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_dsp_dma_ctrl
 *
 * MDAB DSP DMAs Control Register
 * Control The DMA external I/F .
 */
union cavm_mdabx_dsp_dma_ctrl
{
    uint32_t u;
    struct cavm_mdabx_dsp_dma_ctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_2_31         : 30;
        uint32_t ext_ddma_dbg_match_ack : 1; /**< [  1:  1](R/W) TBD */
        uint32_t ddma_next             : 1;  /**< [  0:  0](R/W) TBD */
#else /* Word 0 - Little Endian */
        uint32_t ddma_next             : 1;  /**< [  0:  0](R/W) TBD */
        uint32_t ext_ddma_dbg_match_ack : 1; /**< [  1:  1](R/W) TBD */
        uint32_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_dsp_dma_ctrl_s cn; */
};
typedef union cavm_mdabx_dsp_dma_ctrl cavm_mdabx_dsp_dma_ctrl_t;

static inline uint64_t CAVM_MDABX_DSP_DMA_CTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_DSP_DMA_CTRL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400b30ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_DSP_DMA_CTRL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_DSP_DMA_CTRL(a) cavm_mdabx_dsp_dma_ctrl_t
#define bustype_CAVM_MDABX_DSP_DMA_CTRL(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_DSP_DMA_CTRL(a) "MDABX_DSP_DMA_CTRL"
#define busnum_CAVM_MDABX_DSP_DMA_CTRL(a) (a)
#define arguments_CAVM_MDABX_DSP_DMA_CTRL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_dsp_dma_sts
 *
 * MDAB DSP DMAs Status Register
 * DSP DMA external Status I/F .
 */
union cavm_mdabx_dsp_dma_sts
{
    uint32_t u;
    struct cavm_mdabx_dsp_dma_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t ddma_dbg_match_r      : 1;  /**< [  0:  0](RO/H) TBD */
#else /* Word 0 - Little Endian */
        uint32_t ddma_dbg_match_r      : 1;  /**< [  0:  0](RO/H) TBD */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_dsp_dma_sts_s cn; */
};
typedef union cavm_mdabx_dsp_dma_sts cavm_mdabx_dsp_dma_sts_t;

static inline uint64_t CAVM_MDABX_DSP_DMA_STS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_DSP_DMA_STS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400b40ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_DSP_DMA_STS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_DSP_DMA_STS(a) cavm_mdabx_dsp_dma_sts_t
#define bustype_CAVM_MDABX_DSP_DMA_STS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_DSP_DMA_STS(a) "MDABX_DSP_DMA_STS"
#define busnum_CAVM_MDABX_DSP_DMA_STS(a) (a)
#define arguments_CAVM_MDABX_DSP_DMA_STS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_edp_brdg_ctrl
 *
 * INTERNAL: MDAB EDP Bridge Control Register
 *
 * Control The Bridge hook to the EDP AXI I/F.
 */
union cavm_mdabx_edp_brdg_ctrl
{
    uint32_t u;
    struct cavm_mdabx_edp_brdg_ctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_2_31         : 30;
        uint32_t wburst                : 1;  /**< [  1:  1](R/W) Supporting Write Bursts to System Memory. 0x1 - Enable 0x0 - Disable */
        uint32_t rburst                : 1;  /**< [  0:  0](R/W) Supporting READ Bursts to System Memory. 0x1 - Enable 0x0 - Disable */
#else /* Word 0 - Little Endian */
        uint32_t rburst                : 1;  /**< [  0:  0](R/W) Supporting READ Bursts to System Memory. 0x1 - Enable 0x0 - Disable */
        uint32_t wburst                : 1;  /**< [  1:  1](R/W) Supporting Write Bursts to System Memory. 0x1 - Enable 0x0 - Disable */
        uint32_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_edp_brdg_ctrl_s cn; */
};
typedef union cavm_mdabx_edp_brdg_ctrl cavm_mdabx_edp_brdg_ctrl_t;

static inline uint64_t CAVM_MDABX_EDP_BRDG_CTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_EDP_BRDG_CTRL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400ba0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_EDP_BRDG_CTRL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_EDP_BRDG_CTRL(a) cavm_mdabx_edp_brdg_ctrl_t
#define bustype_CAVM_MDABX_EDP_BRDG_CTRL(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_EDP_BRDG_CTRL(a) "MDABX_EDP_BRDG_CTRL"
#define busnum_CAVM_MDABX_EDP_BRDG_CTRL(a) (a)
#define arguments_CAVM_MDABX_EDP_BRDG_CTRL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_edp_brdg_sts
 *
 * MDAB EDP Bridge Status Register
 * Status The Bridge hook to the EDP AXI I/F.
 */
union cavm_mdabx_edp_brdg_sts
{
    uint32_t u;
    struct cavm_mdabx_edp_brdg_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t monitor_addr          : 24; /**< [ 31:  8](RO/H) Monitor address, valid when Lock indication is set. */
        uint32_t reserved_4_7          : 4;
        uint32_t monitor_sts           : 1;  /**< [  3:  3](RO/H) 0x0 Free, 0x1 Locked */
        uint32_t reserved_2            : 1;
        uint32_t edp_w_freetag         : 1;  /**< [  1:  1](RO/H) EDP Bridge has free tag for Write. */
        uint32_t edp_r_freetag         : 1;  /**< [  0:  0](RO/H) EDP Bridge has free tag for read. */
#else /* Word 0 - Little Endian */
        uint32_t edp_r_freetag         : 1;  /**< [  0:  0](RO/H) EDP Bridge has free tag for read. */
        uint32_t edp_w_freetag         : 1;  /**< [  1:  1](RO/H) EDP Bridge has free tag for Write. */
        uint32_t reserved_2            : 1;
        uint32_t monitor_sts           : 1;  /**< [  3:  3](RO/H) 0x0 Free, 0x1 Locked */
        uint32_t reserved_4_7          : 4;
        uint32_t monitor_addr          : 24; /**< [ 31:  8](RO/H) Monitor address, valid when Lock indication is set. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_edp_brdg_sts_s cn; */
};
typedef union cavm_mdabx_edp_brdg_sts cavm_mdabx_edp_brdg_sts_t;

static inline uint64_t CAVM_MDABX_EDP_BRDG_STS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_EDP_BRDG_STS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400bb0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_EDP_BRDG_STS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_EDP_BRDG_STS(a) cavm_mdabx_edp_brdg_sts_t
#define bustype_CAVM_MDABX_EDP_BRDG_STS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_EDP_BRDG_STS(a) "MDABX_EDP_BRDG_STS"
#define busnum_CAVM_MDABX_EDP_BRDG_STS(a) (a)
#define arguments_CAVM_MDABX_EDP_BRDG_STS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_edp_err_sts
 *
 * MDAB Address Error Status Register
 * Lock bits[31:4] of the address in case of an error on the AXI request.
 */
union cavm_mdabx_edp_err_sts
{
    uint32_t u;
    struct cavm_mdabx_edp_err_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t addr                  : 28; /**< [ 31:  4](RO/H) This Register Value defined the override value of address bits[31:20] of the
                                                                 address targeting system memory. */
        uint32_t reserved_2_3          : 2;
        uint32_t typ                   : 1;  /**< [  1:  1](RO/H) Transaction type.
                                                                 0 = Read.
                                                                 1 = Write. */
        uint32_t lock                  : 1;  /**< [  0:  0](R/W1C/H) Lock indication. When set address value can not be overriden. */
#else /* Word 0 - Little Endian */
        uint32_t lock                  : 1;  /**< [  0:  0](R/W1C/H) Lock indication. When set address value can not be overriden. */
        uint32_t typ                   : 1;  /**< [  1:  1](RO/H) Transaction type.
                                                                 0 = Read.
                                                                 1 = Write. */
        uint32_t reserved_2_3          : 2;
        uint32_t addr                  : 28; /**< [ 31:  4](RO/H) This Register Value defined the override value of address bits[31:20] of the
                                                                 address targeting system memory. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_edp_err_sts_s cn; */
};
typedef union cavm_mdabx_edp_err_sts cavm_mdabx_edp_err_sts_t;

static inline uint64_t CAVM_MDABX_EDP_ERR_STS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_EDP_ERR_STS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444008e0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_EDP_ERR_STS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_EDP_ERR_STS(a) cavm_mdabx_edp_err_sts_t
#define bustype_CAVM_MDABX_EDP_ERR_STS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_EDP_ERR_STS(a) "MDABX_EDP_ERR_STS"
#define busnum_CAVM_MDABX_EDP_ERR_STS(a) (a)
#define arguments_CAVM_MDABX_EDP_ERR_STS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_epp_brdg_ctrl
 *
 * MDAB EPP Bridge Control Register
 * Control The Bridge hook to the EPP AXI I/F.
 */
union cavm_mdabx_epp_brdg_ctrl
{
    uint32_t u;
    struct cavm_mdabx_epp_brdg_ctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t rburst                : 1;  /**< [  0:  0](R/W) Supporting READ Bursts to System Memory. 0x1 - Enable 0x0 - Disable */
#else /* Word 0 - Little Endian */
        uint32_t rburst                : 1;  /**< [  0:  0](R/W) Supporting READ Bursts to System Memory. 0x1 - Enable 0x0 - Disable */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_epp_brdg_ctrl_s cn; */
};
typedef union cavm_mdabx_epp_brdg_ctrl cavm_mdabx_epp_brdg_ctrl_t;

static inline uint64_t CAVM_MDABX_EPP_BRDG_CTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_EPP_BRDG_CTRL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400b80ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_EPP_BRDG_CTRL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_EPP_BRDG_CTRL(a) cavm_mdabx_epp_brdg_ctrl_t
#define bustype_CAVM_MDABX_EPP_BRDG_CTRL(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_EPP_BRDG_CTRL(a) "MDABX_EPP_BRDG_CTRL"
#define busnum_CAVM_MDABX_EPP_BRDG_CTRL(a) (a)
#define arguments_CAVM_MDABX_EPP_BRDG_CTRL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_epp_brdg_sts
 *
 * INTERNAL: MDAB EPP Bridge Status Register
 *
 * Status The Bridge hook to the EPP AXI I/F.
 */
union cavm_mdabx_epp_brdg_sts
{
    uint32_t u;
    struct cavm_mdabx_epp_brdg_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t epp_r_freetag         : 1;  /**< [  0:  0](RO/H) EPP Bridge has free tag for read. */
#else /* Word 0 - Little Endian */
        uint32_t epp_r_freetag         : 1;  /**< [  0:  0](RO/H) EPP Bridge has free tag for read. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_epp_brdg_sts_s cn; */
};
typedef union cavm_mdabx_epp_brdg_sts cavm_mdabx_epp_brdg_sts_t;

static inline uint64_t CAVM_MDABX_EPP_BRDG_STS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_EPP_BRDG_STS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400b90ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_EPP_BRDG_STS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_EPP_BRDG_STS(a) cavm_mdabx_epp_brdg_sts_t
#define bustype_CAVM_MDABX_EPP_BRDG_STS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_EPP_BRDG_STS(a) "MDABX_EPP_BRDG_STS"
#define busnum_CAVM_MDABX_EPP_BRDG_STS(a) (a)
#define arguments_CAVM_MDABX_EPP_BRDG_STS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_epp_err_sts
 *
 * MDAB EPP Address Error Status Register
 * Lock bits[31:4] of the address in case of an error on the AXI request.
 */
union cavm_mdabx_epp_err_sts
{
    uint32_t u;
    struct cavm_mdabx_epp_err_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t addr                  : 28; /**< [ 31:  4](RO/H) This Register Value defined the override value of address bits[31:20] of the
                                                                 address targeting system memory. */
        uint32_t reserved_2_3          : 2;
        uint32_t typ                   : 1;  /**< [  1:  1](RO/H) Transaction type.
                                                                 0 = Read.
                                                                 1 = Write. */
        uint32_t lock                  : 1;  /**< [  0:  0](R/W1C/H) Lock indication. When set the address value can not be overriden. */
#else /* Word 0 - Little Endian */
        uint32_t lock                  : 1;  /**< [  0:  0](R/W1C/H) Lock indication. When set the address value can not be overriden. */
        uint32_t typ                   : 1;  /**< [  1:  1](RO/H) Transaction type.
                                                                 0 = Read.
                                                                 1 = Write. */
        uint32_t reserved_2_3          : 2;
        uint32_t addr                  : 28; /**< [ 31:  4](RO/H) This Register Value defined the override value of address bits[31:20] of the
                                                                 address targeting system memory. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_epp_err_sts_s cn; */
};
typedef union cavm_mdabx_epp_err_sts cavm_mdabx_epp_err_sts_t;

static inline uint64_t CAVM_MDABX_EPP_ERR_STS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_EPP_ERR_STS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444008f0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_EPP_ERR_STS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_EPP_ERR_STS(a) cavm_mdabx_epp_err_sts_t
#define bustype_CAVM_MDABX_EPP_ERR_STS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_EPP_ERR_STS(a) "MDABX_EPP_ERR_STS"
#define busnum_CAVM_MDABX_EPP_ERR_STS(a) (a)
#define arguments_CAVM_MDABX_EPP_ERR_STS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_err_int_ena_w1c
 *
 * MDAB Error Cause Interrupt Enable Clear Register
 * This register is used to Clear MDAB Erorr interrupt enable for the MDAB_ERR_INT_SUM bits.
 */
union cavm_mdabx_err_int_ena_w1c
{
    uint32_t u;
    struct cavm_mdabx_err_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W1S/H) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W1S/H) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W1S/H) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W1S/H) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W1C/H) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t reserved_14_15        : 2;
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W1C/H) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W1C/H) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W1C/H) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W1C/H) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W1C/H) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W1C/H) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W1C/H) DSP BMAN violation error */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W1C/H) DSP QMAN violation error */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W1C/H) DSP Access protection violation */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W1C/H) DSP Permission Violation */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W1C/H) DSP General Violation indication */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W1C/H) DSP Undefined Op-Code */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W1C/H) DSP iCache ECC Error on TAG RAM. */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W1C/H) DSP iCache ECC Error on Data RAM. */
#else /* Word 0 - Little Endian */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W1C/H) DSP iCache ECC Error on Data RAM. */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W1C/H) DSP iCache ECC Error on TAG RAM. */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W1C/H) DSP Undefined Op-Code */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W1C/H) DSP General Violation indication */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W1C/H) DSP Permission Violation */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W1C/H) DSP Access protection violation */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W1C/H) DSP QMAN violation error */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W1C/H) DSP BMAN violation error */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W1C/H) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W1C/H) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W1C/H) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W1C/H) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W1C/H) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W1C/H) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t reserved_14_15        : 2;
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W1C/H) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W1S/H) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W1S/H) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W1S/H) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W1S/H) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_err_int_ena_w1c_s cn; */
};
typedef union cavm_mdabx_err_int_ena_w1c cavm_mdabx_err_int_ena_w1c_t;

static inline uint64_t CAVM_MDABX_ERR_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ERR_INT_ENA_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400aa0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_ERR_INT_ENA_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ERR_INT_ENA_W1C(a) cavm_mdabx_err_int_ena_w1c_t
#define bustype_CAVM_MDABX_ERR_INT_ENA_W1C(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ERR_INT_ENA_W1C(a) "MDABX_ERR_INT_ENA_W1C"
#define busnum_CAVM_MDABX_ERR_INT_ENA_W1C(a) (a)
#define arguments_CAVM_MDABX_ERR_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_err_int_ena_w1s
 *
 * MDAB Error Cause Interrupt Enable Set Register
 * This register is used to set MDAB Erorr interrupt enable for the MDAB_ERR_INT_SUM bits.
 */
union cavm_mdabx_err_int_ena_w1s
{
    uint32_t u;
    struct cavm_mdabx_err_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W1S/H) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W1S/H) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W1S/H) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W1S/H) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W1S/H) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t reserved_14_15        : 2;
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W1S/H) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W1S/H) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W1S/H) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W1S/H) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W1S/H) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W1S/H) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W1S/H) DSP BMAN violation error */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W1S/H) DSP QMAN violation error */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W1S/H) DSP Access protection violation */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W1S/H) DSP Permission Violation */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W1S/H) DSP General Violation indication */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W1S/H) DSP Undefined Op-Code */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W1S/H) DSP iCache ECC Error on TAG RAM. */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W1S/H) DSP iCache ECC Error on Data RAM. */
#else /* Word 0 - Little Endian */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W1S/H) DSP iCache ECC Error on Data RAM. */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W1S/H) DSP iCache ECC Error on TAG RAM. */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W1S/H) DSP Undefined Op-Code */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W1S/H) DSP General Violation indication */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W1S/H) DSP Permission Violation */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W1S/H) DSP Access protection violation */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W1S/H) DSP QMAN violation error */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W1S/H) DSP BMAN violation error */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W1S/H) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W1S/H) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W1S/H) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W1S/H) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W1S/H) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W1S/H) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t reserved_14_15        : 2;
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W1S/H) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W1S/H) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W1S/H) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W1S/H) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W1S/H) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_err_int_ena_w1s_s cn; */
};
typedef union cavm_mdabx_err_int_ena_w1s cavm_mdabx_err_int_ena_w1s_t;

static inline uint64_t CAVM_MDABX_ERR_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ERR_INT_ENA_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a90ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_ERR_INT_ENA_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ERR_INT_ENA_W1S(a) cavm_mdabx_err_int_ena_w1s_t
#define bustype_CAVM_MDABX_ERR_INT_ENA_W1S(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ERR_INT_ENA_W1S(a) "MDABX_ERR_INT_ENA_W1S"
#define busnum_CAVM_MDABX_ERR_INT_ENA_W1S(a) (a)
#define arguments_CAVM_MDABX_ERR_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_err_int_int0_ena
 *
 * MDAB Error Cause Interrupt INT0 Enable Register
 * This register is used to Enable Reporting MDAB Secondary interrupts  To DSP INT0.
 */
union cavm_mdabx_err_int_int0_ena
{
    uint32_t u;
    struct cavm_mdabx_err_int_int0_ena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t reserved_14_15        : 2;
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W) DSP BMAN violation error */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W) DSP QMAN violation error */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W) DSP Access protection violation */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W) DSP Permission Violation */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W) DSP General Violation indication */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W) DSP Undefined Op-Code */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W) DSP iCache ECC Error on TAG RAM. */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W) DSP iCache ECC Error on Data RAM. */
#else /* Word 0 - Little Endian */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W) DSP iCache ECC Error on Data RAM. */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W) DSP iCache ECC Error on TAG RAM. */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W) DSP Undefined Op-Code */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W) DSP General Violation indication */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W) DSP Permission Violation */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W) DSP Access protection violation */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W) DSP QMAN violation error */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W) DSP BMAN violation error */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t reserved_14_15        : 2;
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_err_int_int0_ena_s cn; */
};
typedef union cavm_mdabx_err_int_int0_ena cavm_mdabx_err_int_int0_ena_t;

static inline uint64_t CAVM_MDABX_ERR_INT_INT0_ENA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ERR_INT_INT0_ENA(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400ab0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_ERR_INT_INT0_ENA", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ERR_INT_INT0_ENA(a) cavm_mdabx_err_int_int0_ena_t
#define bustype_CAVM_MDABX_ERR_INT_INT0_ENA(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ERR_INT_INT0_ENA(a) "MDABX_ERR_INT_INT0_ENA"
#define busnum_CAVM_MDABX_ERR_INT_INT0_ENA(a) (a)
#define arguments_CAVM_MDABX_ERR_INT_INT0_ENA(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_err_int_intvec_ena
 *
 * MDAB Error Cause Interrupt INTVEC Enable Register
 * This register is used to Enable Reporting MDAB Secondary interrupts  To DSP Interrupt Vector.
 */
union cavm_mdabx_err_int_intvec_ena
{
    uint32_t u;
    struct cavm_mdabx_err_int_intvec_ena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t reserved_14_15        : 2;
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W) DSP BMAN violation error */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W) DSP QMAN violation error */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W) DSP Access protection violation */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W) DSP Permission Violation */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W) DSP General Violation indication */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W) DSP Undefined Op-Code */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W) DSP iCache ECC Error on TAG RAM. */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W) DSP iCache ECC Error on Data RAM. */
#else /* Word 0 - Little Endian */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W) DSP iCache ECC Error on Data RAM. */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W) DSP iCache ECC Error on TAG RAM. */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W) DSP Undefined Op-Code */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W) DSP General Violation indication */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W) DSP Permission Violation */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W) DSP Access protection violation */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W) DSP QMAN violation error */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W) DSP BMAN violation error */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t reserved_14_15        : 2;
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_err_int_intvec_ena_s cn; */
};
typedef union cavm_mdabx_err_int_intvec_ena cavm_mdabx_err_int_intvec_ena_t;

static inline uint64_t CAVM_MDABX_ERR_INT_INTVEC_ENA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ERR_INT_INTVEC_ENA(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400ac0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_ERR_INT_INTVEC_ENA", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ERR_INT_INTVEC_ENA(a) cavm_mdabx_err_int_intvec_ena_t
#define bustype_CAVM_MDABX_ERR_INT_INTVEC_ENA(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ERR_INT_INTVEC_ENA(a) "MDABX_ERR_INT_INTVEC_ENA"
#define busnum_CAVM_MDABX_ERR_INT_INTVEC_ENA(a) (a)
#define arguments_CAVM_MDABX_ERR_INT_INTVEC_ENA(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_err_int_nmi_ena
 *
 * MDAB Error Cause Interrupt NMI Enable Register
 * This register is used to Enable Reporting MDAB Secondary interrupts  To DSP NMI.
 */
union cavm_mdabx_err_int_nmi_ena
{
    uint32_t u;
    struct cavm_mdabx_err_int_nmi_ena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t reserved_14_15        : 2;
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W) DSP BMAN violation error */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W) DSP QMAN violation error */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W) DSP Access protection violation */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W) DSP Permission Violation */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W) DSP General Violation indication */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W) DSP Undefined Op-Code */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W) DSP iCache ECC Error on TAG RAM. */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W) DSP iCache ECC Error on Data RAM. */
#else /* Word 0 - Little Endian */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W) DSP iCache ECC Error on Data RAM. */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W) DSP iCache ECC Error on TAG RAM. */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W) DSP Undefined Op-Code */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W) DSP General Violation indication */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W) DSP Permission Violation */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W) DSP Access protection violation */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W) DSP QMAN violation error */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W) DSP BMAN violation error */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t reserved_14_15        : 2;
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_err_int_nmi_ena_s cn; */
};
typedef union cavm_mdabx_err_int_nmi_ena cavm_mdabx_err_int_nmi_ena_t;

static inline uint64_t CAVM_MDABX_ERR_INT_NMI_ENA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ERR_INT_NMI_ENA(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400ad0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_ERR_INT_NMI_ENA", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ERR_INT_NMI_ENA(a) cavm_mdabx_err_int_nmi_ena_t
#define bustype_CAVM_MDABX_ERR_INT_NMI_ENA(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ERR_INT_NMI_ENA(a) "MDABX_ERR_INT_NMI_ENA"
#define busnum_CAVM_MDABX_ERR_INT_NMI_ENA(a) (a)
#define arguments_CAVM_MDABX_ERR_INT_NMI_ENA(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_err_int_sum_w1c
 *
 * MDAB Error Cause Interrupt Summary Register
 * This register reports the Error interrupt sources status for the MDAB.
 * Software clears individual interrupts by writing one to the corresponding bit.
 */
union cavm_mdabx_err_int_sum_w1c
{
    uint32_t u;
    struct cavm_mdabx_err_int_sum_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W1C/H) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W1C/H) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W1C/H) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W1C/H) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W1C/H) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W1C/H) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W1C/H) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W1C/H) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W1C/H) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W1C/H) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W1C/H) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W1C/H) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t reserved_14_15        : 2;
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W1C/H) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W1C/H) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W1C/H) Instruction Fetch Decode Error. Instruction fetch does not hit SMEM. */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W1C/H) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W1C/H) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W1C/H) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W1C/H) DSP BMAN violation error */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W1C/H) DSP QMAN violation error */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W1C/H) DSP Access protection violation */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W1C/H) DSP Permission Violation */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W1C/H) DSP General Violation indication */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W1C/H) DSP Undefined Op-Code */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W1C/H) DSP iCache ECC Error on TAG RAM. */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W1C/H) DSP iCache ECC Error on Data RAM. */
#else /* Word 0 - Little Endian */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W1C/H) DSP iCache ECC Error on Data RAM. */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W1C/H) DSP iCache ECC Error on TAG RAM. */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W1C/H) DSP Undefined Op-Code */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W1C/H) DSP General Violation indication */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W1C/H) DSP Permission Violation */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W1C/H) DSP Access protection violation */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W1C/H) DSP QMAN violation error */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W1C/H) DSP BMAN violation error */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W1C/H) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W1C/H) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W1C/H) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W1C/H) Instruction Fetch Decode Error. Instruction fetch does not hit SMEM. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W1C/H) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W1C/H) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t reserved_14_15        : 2;
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W1C/H) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W1C/H) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W1C/H) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W1C/H) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W1C/H) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W1C/H) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W1C/H) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W1C/H) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W1C/H) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W1C/H) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W1C/H) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W1C/H) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_err_int_sum_w1c_s cn; */
};
typedef union cavm_mdabx_err_int_sum_w1c cavm_mdabx_err_int_sum_w1c_t;

static inline uint64_t CAVM_MDABX_ERR_INT_SUM_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ERR_INT_SUM_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a70ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_ERR_INT_SUM_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ERR_INT_SUM_W1C(a) cavm_mdabx_err_int_sum_w1c_t
#define bustype_CAVM_MDABX_ERR_INT_SUM_W1C(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ERR_INT_SUM_W1C(a) "MDABX_ERR_INT_SUM_W1C"
#define busnum_CAVM_MDABX_ERR_INT_SUM_W1C(a) (a)
#define arguments_CAVM_MDABX_ERR_INT_SUM_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_err_int_sum_w1s
 *
 * MDAB Error Cause Interrupt Summary Set Register
 * This register is used to artificially set MDAB interrupts described in
 * MDAB_ERR_INT_SUM (for software Debug/Test)
 */
union cavm_mdabx_err_int_sum_w1s
{
    uint32_t u;
    struct cavm_mdabx_err_int_sum_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W1S/H) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W1S/H) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W1S/H) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W1S/H) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W1S/H) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t reserved_14_15        : 2;
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W1S/H) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W1S/H) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W1S/H) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W1S/H) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W1S/H) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W1S/H) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W1S/H) DSP BMAN violation error */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W1S/H) DSP QMAN violation error */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W1S/H) DSP Access protection violation */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W1S/H) DSP Permission Violation */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W1S/H) DSP General Violation indication */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W1S/H) DSP Undefined Op-Code */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W1S/H) DSP iCache ECC Error on TAG RAM. */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W1S/H) DSP iCache ECC Error on Data RAM. */
#else /* Word 0 - Little Endian */
        uint32_t ideccerr              : 1;  /**< [  0:  0](R/W1S/H) DSP iCache ECC Error on Data RAM. */
        uint32_t iteccerr              : 1;  /**< [  1:  1](R/W1S/H) DSP iCache ECC Error on TAG RAM. */
        uint32_t uoc                   : 1;  /**< [  2:  2](R/W1S/H) DSP Undefined Op-Code */
        uint32_t gvi                   : 1;  /**< [  3:  3](R/W1S/H) DSP General Violation indication */
        uint32_t pi                    : 1;  /**< [  4:  4](R/W1S/H) DSP Permission Violation */
        uint32_t apv                   : 1;  /**< [  5:  5](R/W1S/H) DSP Access protection violation */
        uint32_t qmv                   : 1;  /**< [  6:  6](R/W1S/H) DSP QMAN violation error */
        uint32_t bmv                   : 1;  /**< [  7:  7](R/W1S/H) DSP BMAN violation error */
        uint32_t epprdecerr            : 1;  /**< [  8:  8](R/W1S/H) EDP (AXI Program master port) Read access did not hit any BAR */
        uint32_t edpwdecerr            : 1;  /**< [  9:  9](R/W1S/H) EDP (AXI Program master port) Write access did not hit any BAR */
        uint32_t edprdecerr            : 1;  /**< [ 10: 10](R/W1S/H) EDP (AXI Data master port) Read access did not hit any BAR */
        uint32_t ifdecerr              : 1;  /**< [ 11: 11](R/W1S/H) Indicate Instruction Fetch from Non-SMEM memory space. Reported by the IPB. read
                                                                 Decode Error is returned to the DSP as well. */
        uint32_t rcsr_err              : 1;  /**< [ 12: 12](R/W1S/H) A read transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t wcsr_err              : 1;  /**< [ 13: 13](R/W1S/H) A write transaction to CSR was violating the CSR access restrictions. A slave
                                                                 error is returned to the intiator. */
        uint32_t reserved_14_15        : 2;
        uint32_t axisslverr            : 1;  /**< [ 16: 16](R/W1S/H) EDAP (DSP AXI Slave Port) return Slave Error for Read or Write access to the DSP memory space. */
        uint32_t edprdblerr            : 1;  /**< [ 17: 17](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpwrblerr            : 1;  /**< [ 18: 18](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported burst length. */
        uint32_t epprdblerr            : 1;  /**< [ 19: 19](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported burst length. */
        uint32_t edpiderr              : 1;  /**< [ 20: 20](R/W1S/H) EDP (DSP AXI Master Port) read or write channel unsupported AXI ID. */
        uint32_t eppiderr              : 1;  /**< [ 21: 21](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported AXI ID. */
        uint32_t edprdatterr           : 1;  /**< [ 22: 22](R/W1S/H) EDP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edpwratterr           : 1;  /**< [ 23: 23](R/W1S/H) EDP (DSP AXI Master Port) write channel unsupported attribute (burst type, unsupported size). */
        uint32_t epprdatterr           : 1;  /**< [ 24: 24](R/W1S/H) EPP (DSP AXI Master Port) read channel unsupported attribute (burst type). */
        uint32_t edprdtrgterr          : 1;  /**< [ 25: 25](R/W1S/H) EDP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t edpwrtrgterr          : 1;  /**< [ 26: 26](R/W1S/H) EDP (DSP AXI Master Port) write channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t epprdtrgterr          : 1;  /**< [ 27: 27](R/W1S/H) EPP (DSP AXI Master Port) read channel target error indicates GAA Error response of FAT_ERR. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_err_int_sum_w1s_s cn; */
};
typedef union cavm_mdabx_err_int_sum_w1s cavm_mdabx_err_int_sum_w1s_t;

static inline uint64_t CAVM_MDABX_ERR_INT_SUM_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ERR_INT_SUM_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a80ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_ERR_INT_SUM_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ERR_INT_SUM_W1S(a) cavm_mdabx_err_int_sum_w1s_t
#define bustype_CAVM_MDABX_ERR_INT_SUM_W1S(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ERR_INT_SUM_W1S(a) "MDABX_ERR_INT_SUM_W1S"
#define busnum_CAVM_MDABX_ERR_INT_SUM_W1S(a) (a)
#define arguments_CAVM_MDABX_ERR_INT_SUM_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_error_address
 *
 * INTERNAL: MDAB Error Address Register
 *
 * This register contains the address of the transaction that caused an error signal to be
 * asserted
 *
 * Internal:
 * This register is broken in o75p1
 */
union cavm_mdabx_error_address
{
    uint64_t u;
    struct cavm_mdabx_error_address_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t addr                  : 32; /**< [ 31:  0](RO/H) When an RSL access causes the ID_MEM_NXM error bit to be set, this field captures the
                                                                 failing address. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 32; /**< [ 31:  0](RO/H) When an RSL access causes the ID_MEM_NXM error bit to be set, this field captures the
                                                                 failing address. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_error_address_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 32; /**< [ 31:  0](RO/H) When an RSL access causes the ID_MEM_NXM error bit to be set, this field captures the
                                                                 failing address. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 32; /**< [ 31:  0](RO/H) When an RSL access causes the ID_MEM_NXM error bit to be set, this field captures the
                                                                 failing address. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_error_address cavm_mdabx_error_address_t;

static inline uint64_t CAVM_MDABX_ERROR_ADDRESS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ERROR_ADDRESS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100270ll + 0x4000ll * ((a) & 0x3f);
    __cavm_csr_fatal("MDABX_ERROR_ADDRESS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ERROR_ADDRESS(a) cavm_mdabx_error_address_t
#define bustype_CAVM_MDABX_ERROR_ADDRESS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ERROR_ADDRESS(a) "MDABX_ERROR_ADDRESS"
#define busnum_CAVM_MDABX_ERROR_ADDRESS(a) (a)
#define arguments_CAVM_MDABX_ERROR_ADDRESS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_error_status
 *
 * INTERNAL: MDAB Error Status Register
 *
 * This register contains error status signals.
 * Internal:
 * This register is broken in o75p1
 */
union cavm_mdabx_error_status
{
    uint64_t u;
    struct cavm_mdabx_error_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t error_hilo            : 1;  /**< [  8:  8](RO/H) This field indicates the state of addr[3] of a CSR transaction that caused the error whose
                                                                 state is recorded in
                                                                 this register.  (CSR-WR: WBEs/CSR-RD:8B-aligned) */
        uint64_t error_flitsize        : 1;  /**< [  7:  7](RO/H) This field indicates the type of transaction that caused the recorded error. 0=16B, 1=32B */
        uint64_t error_type            : 1;  /**< [  6:  6](RO/H) This field indicates the type of transaction that caused the recorded error. 0=non-csr, 1=csr. */
        uint64_t error_cmd             : 1;  /**< [  5:  5](RO/H) This field indicates the command type of the transaction that caused the recorded error.
                                                                 0=RD, 1=WR. */
        uint64_t error_src             : 3;  /**< [  4:  2](RO/H) This field indicates the source of the transaction that caused the recorded error.
                                                                 000: WDM
                                                                 001: RDM
                                                                 010: CDM
                                                                 011: CSR
                                                                 100: PFO Write Request Error */
        uint64_t mem_dataerr           : 1;  /**< [  1:  1](R/W1C/H) This bit will be set when a data error has occurred during a csr or DMA engine operation.. */
        uint64_t mem_addrerr           : 1;  /**< [  0:  0](R/W1C/H) This bit will be set when a csr or DMA engine access is performed to a non existent
                                                                 instruction
                                                                 or data memory address. */
#else /* Word 0 - Little Endian */
        uint64_t mem_addrerr           : 1;  /**< [  0:  0](R/W1C/H) This bit will be set when a csr or DMA engine access is performed to a non existent
                                                                 instruction
                                                                 or data memory address. */
        uint64_t mem_dataerr           : 1;  /**< [  1:  1](R/W1C/H) This bit will be set when a data error has occurred during a csr or DMA engine operation.. */
        uint64_t error_src             : 3;  /**< [  4:  2](RO/H) This field indicates the source of the transaction that caused the recorded error.
                                                                 000: WDM
                                                                 001: RDM
                                                                 010: CDM
                                                                 011: CSR
                                                                 100: PFO Write Request Error */
        uint64_t error_cmd             : 1;  /**< [  5:  5](RO/H) This field indicates the command type of the transaction that caused the recorded error.
                                                                 0=RD, 1=WR. */
        uint64_t error_type            : 1;  /**< [  6:  6](RO/H) This field indicates the type of transaction that caused the recorded error. 0=non-csr, 1=csr. */
        uint64_t error_flitsize        : 1;  /**< [  7:  7](RO/H) This field indicates the type of transaction that caused the recorded error. 0=16B, 1=32B */
        uint64_t error_hilo            : 1;  /**< [  8:  8](RO/H) This field indicates the state of addr[3] of a CSR transaction that caused the error whose
                                                                 state is recorded in
                                                                 this register.  (CSR-WR: WBEs/CSR-RD:8B-aligned) */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_error_status_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_31         : 23;
        uint64_t error_hilo            : 1;  /**< [  8:  8](RO/H) This field indicates the state of addr[3] of a CSR transaction that caused the error whose
                                                                 state is recorded in
                                                                 this register.  (CSR-WR: WBEs/CSR-RD:8B-aligned) */
        uint64_t error_flitsize        : 1;  /**< [  7:  7](RO/H) This field indicates the type of transaction that caused the recorded error. 0=16B, 1=32B */
        uint64_t error_type            : 1;  /**< [  6:  6](RO/H) This field indicates the type of transaction that caused the recorded error. 0=non-csr, 1=csr. */
        uint64_t error_cmd             : 1;  /**< [  5:  5](RO/H) This field indicates the command type of the transaction that caused the recorded error.
                                                                 0=RD, 1=WR. */
        uint64_t error_src             : 3;  /**< [  4:  2](RO/H) This field indicates the source of the transaction that caused the recorded error.
                                                                 000: WDM
                                                                 001: RDM
                                                                 010: CDM
                                                                 011: CSR
                                                                 100: PFO Write Request Error */
        uint64_t mem_dataerr           : 1;  /**< [  1:  1](R/W1C/H) This bit will be set when a data error has occurred during a csr or DMA engine operation.. */
        uint64_t mem_addrerr           : 1;  /**< [  0:  0](R/W1C/H) This bit will be set when a csr or DMA engine access is performed to a non existent
                                                                 instruction
                                                                 or data memory address. */
#else /* Word 0 - Little Endian */
        uint64_t mem_addrerr           : 1;  /**< [  0:  0](R/W1C/H) This bit will be set when a csr or DMA engine access is performed to a non existent
                                                                 instruction
                                                                 or data memory address. */
        uint64_t mem_dataerr           : 1;  /**< [  1:  1](R/W1C/H) This bit will be set when a data error has occurred during a csr or DMA engine operation.. */
        uint64_t error_src             : 3;  /**< [  4:  2](RO/H) This field indicates the source of the transaction that caused the recorded error.
                                                                 000: WDM
                                                                 001: RDM
                                                                 010: CDM
                                                                 011: CSR
                                                                 100: PFO Write Request Error */
        uint64_t error_cmd             : 1;  /**< [  5:  5](RO/H) This field indicates the command type of the transaction that caused the recorded error.
                                                                 0=RD, 1=WR. */
        uint64_t error_type            : 1;  /**< [  6:  6](RO/H) This field indicates the type of transaction that caused the recorded error. 0=non-csr, 1=csr. */
        uint64_t error_flitsize        : 1;  /**< [  7:  7](RO/H) This field indicates the type of transaction that caused the recorded error. 0=16B, 1=32B */
        uint64_t error_hilo            : 1;  /**< [  8:  8](RO/H) This field indicates the state of addr[3] of a CSR transaction that caused the error whose
                                                                 state is recorded in
                                                                 this register.  (CSR-WR: WBEs/CSR-RD:8B-aligned) */
        uint64_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_error_status cavm_mdabx_error_status_t;

static inline uint64_t CAVM_MDABX_ERROR_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ERROR_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100260ll + 0x4000ll * ((a) & 0x3f);
    __cavm_csr_fatal("MDABX_ERROR_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ERROR_STATUS(a) cavm_mdabx_error_status_t
#define bustype_CAVM_MDABX_ERROR_STATUS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ERROR_STATUS(a) "MDABX_ERROR_STATUS"
#define busnum_CAVM_MDABX_ERROR_STATUS(a) (a)
#define arguments_CAVM_MDABX_ERROR_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gp0
 *
 * MDAB General Purpose Register 0
 * General purpose scratch register.
 */
union cavm_mdabx_gp0
{
    uint64_t u;
    struct cavm_mdabx_gp0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gp0                   : 32; /**< [ 31:  0](R/W) Scratch register 0. */
#else /* Word 0 - Little Endian */
        uint64_t gp0                   : 32; /**< [ 31:  0](R/W) Scratch register 0. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gp0_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gp0                   : 32; /**< [ 31:  0](R/W) Scratch register 0. */
#else /* Word 0 - Little Endian */
        uint64_t gp0                   : 32; /**< [ 31:  0](R/W) Scratch register 0. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gp0 cavm_mdabx_gp0_t;

static inline uint64_t CAVM_MDABX_GP0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GP0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100350ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400350ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GP0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GP0(a) cavm_mdabx_gp0_t
#define bustype_CAVM_MDABX_GP0(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GP0(a) "MDABX_GP0"
#define busnum_CAVM_MDABX_GP0(a) (a)
#define arguments_CAVM_MDABX_GP0(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gp1
 *
 * MDAB General Purpose Register 1
 * General purpose scratch register.
 */
union cavm_mdabx_gp1
{
    uint64_t u;
    struct cavm_mdabx_gp1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gp1                   : 32; /**< [ 31:  0](R/W) Scratch register 1. */
#else /* Word 0 - Little Endian */
        uint64_t gp1                   : 32; /**< [ 31:  0](R/W) Scratch register 1. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gp1_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gp1                   : 32; /**< [ 31:  0](R/W) Scratch register 1. */
#else /* Word 0 - Little Endian */
        uint64_t gp1                   : 32; /**< [ 31:  0](R/W) Scratch register 1. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gp1 cavm_mdabx_gp1_t;

static inline uint64_t CAVM_MDABX_GP1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GP1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100360ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400360ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GP1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GP1(a) cavm_mdabx_gp1_t
#define bustype_CAVM_MDABX_GP1(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GP1(a) "MDABX_GP1"
#define busnum_CAVM_MDABX_GP1(a) (a)
#define arguments_CAVM_MDABX_GP1(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gp2
 *
 * MDAB General Purpose Register 2
 * General purpose scratch register.
 */
union cavm_mdabx_gp2
{
    uint64_t u;
    struct cavm_mdabx_gp2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gp2                   : 32; /**< [ 31:  0](R/W) Scratch register 2. */
#else /* Word 0 - Little Endian */
        uint64_t gp2                   : 32; /**< [ 31:  0](R/W) Scratch register 2. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gp2_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gp2                   : 32; /**< [ 31:  0](R/W) Scratch register 2. */
#else /* Word 0 - Little Endian */
        uint64_t gp2                   : 32; /**< [ 31:  0](R/W) Scratch register 2. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gp2 cavm_mdabx_gp2_t;

static inline uint64_t CAVM_MDABX_GP2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GP2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100370ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400370ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GP2", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GP2(a) cavm_mdabx_gp2_t
#define bustype_CAVM_MDABX_GP2(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GP2(a) "MDABX_GP2"
#define busnum_CAVM_MDABX_GP2(a) (a)
#define arguments_CAVM_MDABX_GP2(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gp3
 *
 * MDAB General Purpose Register 3
 * General purpose scratch register.
 */
union cavm_mdabx_gp3
{
    uint64_t u;
    struct cavm_mdabx_gp3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gp3                   : 32; /**< [ 31:  0](R/W) Scratch register 3. */
#else /* Word 0 - Little Endian */
        uint64_t gp3                   : 32; /**< [ 31:  0](R/W) Scratch register 3. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gp3_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gp3                   : 32; /**< [ 31:  0](R/W) Scratch register 3. */
#else /* Word 0 - Little Endian */
        uint64_t gp3                   : 32; /**< [ 31:  0](R/W) Scratch register 3. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gp3 cavm_mdabx_gp3_t;

static inline uint64_t CAVM_MDABX_GP3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GP3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100380ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400380ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GP3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GP3(a) cavm_mdabx_gp3_t
#define bustype_CAVM_MDABX_GP3(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GP3(a) "MDABX_GP3"
#define busnum_CAVM_MDABX_GP3(a) (a)
#define arguments_CAVM_MDABX_GP3(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gp4
 *
 * MDAB General Purpose Register 4
 * General purpose scratch register.
 */
union cavm_mdabx_gp4
{
    uint64_t u;
    struct cavm_mdabx_gp4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gp4                   : 32; /**< [ 31:  0](R/W) Scratch register 4. */
#else /* Word 0 - Little Endian */
        uint64_t gp4                   : 32; /**< [ 31:  0](R/W) Scratch register 4. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gp4_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gp4                   : 32; /**< [ 31:  0](R/W) Scratch register 4. */
#else /* Word 0 - Little Endian */
        uint64_t gp4                   : 32; /**< [ 31:  0](R/W) Scratch register 4. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gp4 cavm_mdabx_gp4_t;

static inline uint64_t CAVM_MDABX_GP4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GP4(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100390ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400390ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GP4", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GP4(a) cavm_mdabx_gp4_t
#define bustype_CAVM_MDABX_GP4(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GP4(a) "MDABX_GP4"
#define busnum_CAVM_MDABX_GP4(a) (a)
#define arguments_CAVM_MDABX_GP4(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gp5
 *
 * MDAB General Purpose Register 5
 * General purpose scratch register.
 */
union cavm_mdabx_gp5
{
    uint64_t u;
    struct cavm_mdabx_gp5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gp5                   : 32; /**< [ 31:  0](R/W) Scratch register 5. */
#else /* Word 0 - Little Endian */
        uint64_t gp5                   : 32; /**< [ 31:  0](R/W) Scratch register 5. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gp5_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gp5                   : 32; /**< [ 31:  0](R/W) Scratch register 5. */
#else /* Word 0 - Little Endian */
        uint64_t gp5                   : 32; /**< [ 31:  0](R/W) Scratch register 5. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gp5 cavm_mdabx_gp5_t;

static inline uint64_t CAVM_MDABX_GP5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GP5(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441003a0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444003a0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GP5", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GP5(a) cavm_mdabx_gp5_t
#define bustype_CAVM_MDABX_GP5(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GP5(a) "MDABX_GP5"
#define busnum_CAVM_MDABX_GP5(a) (a)
#define arguments_CAVM_MDABX_GP5(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gp6
 *
 * MDAB General Purpose Register 6
 * General purpose scratch register.
 */
union cavm_mdabx_gp6
{
    uint64_t u;
    struct cavm_mdabx_gp6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gp6                   : 32; /**< [ 31:  0](R/W) Scratch register 6. */
#else /* Word 0 - Little Endian */
        uint64_t gp6                   : 32; /**< [ 31:  0](R/W) Scratch register 6. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gp6_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gp6                   : 32; /**< [ 31:  0](R/W) Scratch register 6. */
#else /* Word 0 - Little Endian */
        uint64_t gp6                   : 32; /**< [ 31:  0](R/W) Scratch register 6. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gp6 cavm_mdabx_gp6_t;

static inline uint64_t CAVM_MDABX_GP6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GP6(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441003b0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444003b0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GP6", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GP6(a) cavm_mdabx_gp6_t
#define bustype_CAVM_MDABX_GP6(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GP6(a) "MDABX_GP6"
#define busnum_CAVM_MDABX_GP6(a) (a)
#define arguments_CAVM_MDABX_GP6(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gp7
 *
 * MDAB General Purpose Register 7
 * General purpose scratch register.
 */
union cavm_mdabx_gp7
{
    uint64_t u;
    struct cavm_mdabx_gp7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gp7                   : 32; /**< [ 31:  0](R/W) Scratch register 7. */
#else /* Word 0 - Little Endian */
        uint64_t gp7                   : 32; /**< [ 31:  0](R/W) Scratch register 7. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gp7_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gp7                   : 32; /**< [ 31:  0](R/W) Scratch register 7. */
#else /* Word 0 - Little Endian */
        uint64_t gp7                   : 32; /**< [ 31:  0](R/W) Scratch register 7. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gp7 cavm_mdabx_gp7_t;

static inline uint64_t CAVM_MDABX_GP7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GP7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441003c0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444003c0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GP7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GP7(a) cavm_mdabx_gp7_t
#define bustype_CAVM_MDABX_GP7(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GP7(a) "MDABX_GP7"
#define busnum_CAVM_MDABX_GP7(a) (a)
#define arguments_CAVM_MDABX_GP7(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gpio_in
 *
 * MDAB GPIO Input Register
 * DSP GPIO input register, allows DSP to read data from other hosts.
 */
union cavm_mdabx_gpio_in
{
    uint64_t u;
    struct cavm_mdabx_gpio_in_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gpio_in               : 32; /**< [ 31:  0](R/W) DSP GPIO input register, allows DSP to read data from other hosts. */
#else /* Word 0 - Little Endian */
        uint64_t gpio_in               : 32; /**< [ 31:  0](R/W) DSP GPIO input register, allows DSP to read data from other hosts. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gpio_in_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gpio_in               : 32; /**< [ 31:  0](R/W) DSP GPIO input register, allows DSP to read data from other hosts. */
#else /* Word 0 - Little Endian */
        uint64_t gpio_in               : 32; /**< [ 31:  0](R/W) DSP GPIO input register, allows DSP to read data from other hosts. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gpio_in cavm_mdabx_gpio_in_t;

static inline uint64_t CAVM_MDABX_GPIO_IN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GPIO_IN(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100320ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400320ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GPIO_IN", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GPIO_IN(a) cavm_mdabx_gpio_in_t
#define bustype_CAVM_MDABX_GPIO_IN(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GPIO_IN(a) "MDABX_GPIO_IN"
#define busnum_CAVM_MDABX_GPIO_IN(a) (a)
#define arguments_CAVM_MDABX_GPIO_IN(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_gpio_out
 *
 * MDAB GPIO Output Register
 * DSP GPIO output register, allows DSP to output data for other hosts
 */
union cavm_mdabx_gpio_out
{
    uint64_t u;
    struct cavm_mdabx_gpio_out_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t gpio_out              : 32; /**< [ 31:  0](RO/H) DSP GPIO output register, allows DSP to output data for other hosts */
#else /* Word 0 - Little Endian */
        uint64_t gpio_out              : 32; /**< [ 31:  0](RO/H) DSP GPIO output register, allows DSP to output data for other hosts */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_gpio_out_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gpio_out              : 32; /**< [ 31:  0](RO/H) DSP GPIO output register, allows DSP to output data for other hosts */
#else /* Word 0 - Little Endian */
        uint64_t gpio_out              : 32; /**< [ 31:  0](RO/H) DSP GPIO output register, allows DSP to output data for other hosts */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_gpio_out cavm_mdabx_gpio_out_t;

static inline uint64_t CAVM_MDABX_GPIO_OUT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_GPIO_OUT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100310ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400310ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_GPIO_OUT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_GPIO_OUT(a) cavm_mdabx_gpio_out_t
#define bustype_CAVM_MDABX_GPIO_OUT(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_GPIO_OUT(a) "MDABX_GPIO_OUT"
#define busnum_CAVM_MDABX_GPIO_OUT(a) (a)
#define arguments_CAVM_MDABX_GPIO_OUT(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_id
 *
 * MDAB ID Register
 * MDAB ID Register.
 */
union cavm_mdabx_id
{
    uint64_t u;
    struct cavm_mdabx_id_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t mdb_id                : 32; /**< [ 31:  0](RO/H) MDAB ID register. */
#else /* Word 0 - Little Endian */
        uint64_t mdb_id                : 32; /**< [ 31:  0](RO/H) MDAB ID register. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_id_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_31         : 26;
        uint64_t mdb_id                : 6;  /**< [  5:  0](RO/H) MDAB ID register. */
#else /* Word 0 - Little Endian */
        uint64_t mdb_id                : 6;  /**< [  5:  0](RO/H) MDAB ID register. */
        uint64_t reserved_6_31         : 26;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_id_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mdb_id                : 32; /**< [ 31:  0](RO/H) MDAB ID register. */
#else /* Word 0 - Little Endian */
        uint64_t mdb_id                : 32; /**< [ 31:  0](RO/H) MDAB ID register. */
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_id cavm_mdabx_id_t;

static inline uint64_t CAVM_MDABX_ID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_ID(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100340ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400340ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_ID", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_ID(a) cavm_mdabx_id_t
#define bustype_CAVM_MDABX_ID(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_ID(a) "MDABX_ID"
#define busnum_CAVM_MDABX_ID(a) (a)
#define arguments_CAVM_MDABX_ID(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_int1_ena
 *
 * MDAB Secondary Interrupt INT1 Enable Register
 * This register is used to Enable Reporting MDAB Secondary interrupts  To DSP INT1.
 */
union cavm_mdabx_int1_ena
{
    uint32_t u;
    struct cavm_mdabx_int1_ena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W) If Enable, CTI_INT event is reported to DSP INT1. 0x1 - Enable, 0x0 - Disable */
        uint32_t reserved_2_7          : 6;
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W) If Enable, QMAN_IRQ event is reported to DSP INT1. 0x1 - Enable, 0x0 - Disable */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W) If Enable, SGO event is reported to DSP INT1. 0x1 - Enable, 0x0 - Disable */
#else /* Word 0 - Little Endian */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W) If Enable, SGO event is reported to DSP INT1. 0x1 - Enable, 0x0 - Disable */
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W) If Enable, QMAN_IRQ event is reported to DSP INT1. 0x1 - Enable, 0x0 - Disable */
        uint32_t reserved_2_7          : 6;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W) If Enable, CTI_INT event is reported to DSP INT1. 0x1 - Enable, 0x0 - Disable */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_int1_ena_s cn; */
};
typedef union cavm_mdabx_int1_ena cavm_mdabx_int1_ena_t;

static inline uint64_t CAVM_MDABX_INT1_ENA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_INT1_ENA(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a40ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_INT1_ENA", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_INT1_ENA(a) cavm_mdabx_int1_ena_t
#define bustype_CAVM_MDABX_INT1_ENA(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_INT1_ENA(a) "MDABX_INT1_ENA"
#define busnum_CAVM_MDABX_INT1_ENA(a) (a)
#define arguments_CAVM_MDABX_INT1_ENA(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_int_ena_w1c
 *
 * MDAB Interrupt Enable CLEAR Register
 * This register is used to clear MDAB progammable interrupt enables for the MDAB_INT_SUM bits.
 */
union cavm_mdabx_int_ena_w1c
{
    uint64_t u;
    struct cavm_mdabx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears the enable for the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears the enable for the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_PENDING]. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_PENDING]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears the enable for the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears the enable for the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_int_ena_w1c_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_31        : 19;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears the enable for the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears the enable for the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_PENDING]. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_PENDING]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enables for the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears the enable for the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears the enable for the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_int_ena_w1c_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_31        : 19;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears the enable for the MBAD()_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears the enable for the MBAD()_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_PENDING]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[RD_DMA_PENDING]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[CFG_DMA_PENDING]. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[CFG_DMA_PENDING]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[RD_DMA_PENDING]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_PENDING]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enables for the MBAD()_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears the enable for the MBAD()_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears the enable for the MBAD()_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_int_ena_w1c cavm_mdabx_int_ena_w1c_t;

static inline uint64_t CAVM_MDABX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_INT_ENA_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100170ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400170ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_INT_ENA_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_INT_ENA_W1C(a) cavm_mdabx_int_ena_w1c_t
#define bustype_CAVM_MDABX_INT_ENA_W1C(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_INT_ENA_W1C(a) "MDABX_INT_ENA_W1C"
#define busnum_CAVM_MDABX_INT_ENA_W1C(a) (a)
#define arguments_CAVM_MDABX_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_int_ena_w1s
 *
 * MDAB Interrupt Enable SET Register
 * This register is used to set MDAB progammable interrupt enables for the MDAB_INT_SUM bits.
 */
union cavm_mdabx_int_ena_w1s
{
    uint64_t u;
    struct cavm_mdabx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the enable for the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the enable for the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_LAST_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_LAST_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_SLICE_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_PENDING]. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_PENDING]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_SLICE_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_LAST_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_LAST_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the enable for the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the enable for the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_int_ena_w1s_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_31        : 19;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the enable for the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the enable for the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_LAST_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_LAST_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_SLICE_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_PENDING]. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_PENDING]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_SLICE_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[RD_DMA_LAST_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_LAST_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enables for the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the enable for the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the enable for the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_int_ena_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_31        : 19;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the enable for the MBAD()_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the enable for the MBAD()_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_LAST_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_SLICE_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_PENDING]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[RD_DMA_LAST_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[RD_DMA_SLICE_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[RD_DMA_PENDING]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[CFG_DMA_PENDING]. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[CFG_DMA_PENDING]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[RD_DMA_PENDING]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[RD_DMA_SLICE_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[RD_DMA_LAST_DONE].  Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a load local operation. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_PENDING]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_SLICE_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_LAST_DONE]. Note that this interrupt
                                                                 bit will NOT get
                                                                 set at the end of a store local operation. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enables for the MBAD()_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the enable for the MBAD()_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the enable for the MBAD()_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_int_ena_w1s cavm_mdabx_int_ena_w1s_t;

static inline uint64_t CAVM_MDABX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_INT_ENA_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100180ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400180ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_INT_ENA_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_INT_ENA_W1S(a) cavm_mdabx_int_ena_w1s_t
#define bustype_CAVM_MDABX_INT_ENA_W1S(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_INT_ENA_W1S(a) "MDABX_INT_ENA_W1S"
#define busnum_CAVM_MDABX_INT_ENA_W1S(a) (a)
#define arguments_CAVM_MDABX_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_int_sel
 *
 * MDAB Interrupt Level Select Register
 * This register is used to configure the MDAB interrupts to the DSP cores.
 */
union cavm_mdabx_int_sel
{
    uint64_t u;
    struct cavm_mdabx_int_sel_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t ld_lcl_trig_style     : 1;  /**< [  2:  2](R/W) Determines whether load local start/finish interrupts are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
        uint64_t dma_int_trig_style    : 1;  /**< [  1:  1](R/W) Determines whether interrupts reported via MDAB_INT_SUM are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t dma_int_trig_style    : 1;  /**< [  1:  1](R/W) Determines whether interrupts reported via MDAB_INT_SUM are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
        uint64_t ld_lcl_trig_style     : 1;  /**< [  2:  2](R/W) Determines whether load local start/finish interrupts are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_int_sel_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_31         : 29;
        uint64_t ld_lcl_trig_style     : 1;  /**< [  2:  2](R/W) Determines whether load local start/finish interrupts are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
        uint64_t dma_int_trig_style    : 1;  /**< [  1:  1](R/W) Determines whether interrupts reported via MDAB_INT_SUM are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
        uint64_t int_level_sel         : 1;  /**< [  0:  0](R/W) Selects interrupt priority for MDAB_INT_SUM interrupts.
                                                                 0 = Level 1 interrupts.
                                                                 1 = Level 2 interrupts.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
#else /* Word 0 - Little Endian */
        uint64_t int_level_sel         : 1;  /**< [  0:  0](R/W) Selects interrupt priority for MDAB_INT_SUM interrupts.
                                                                 0 = Level 1 interrupts.
                                                                 1 = Level 2 interrupts.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
        uint64_t dma_int_trig_style    : 1;  /**< [  1:  1](R/W) Determines whether interrupts reported via MDAB_INT_SUM are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
        uint64_t ld_lcl_trig_style     : 1;  /**< [  2:  2](R/W) Determines whether load local start/finish interrupts are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior
                                                                 to initial configuration of the interrupt enable register. */
        uint64_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_int_sel_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_31         : 29;
        uint64_t ld_lcl_trig_style     : 1;  /**< [  2:  2](R/W) Reserved. must be 0.
                                                                 Internal:
                                                                 Determines whether load local start/finish interrupts are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior to initial configuration of the interrupt enable register. */
        uint64_t dma_int_trig_style    : 1;  /**< [  1:  1](R/W) Reserved. Must be 0.
                                                                 Internal:
                                                                 Determines whether interrupts reported via MDAB_INT_SUM are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior to initial configuration of the interrupt enable register. */
        uint64_t int_rout_sel          : 1;  /**< [  0:  0](R/W) Selects interrupt routing for MDAB_INT_SUM interrupts.
                                                                 0 = INT 0 Enable.
                                                                 1 = VINT enable .
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior to initial configuration of the interrupt enable register.

                                                                 Internal:
                                                                 This bit in F95 control the level of interrupt reported - level 1 or level 2. */
#else /* Word 0 - Little Endian */
        uint64_t int_rout_sel          : 1;  /**< [  0:  0](R/W) Selects interrupt routing for MDAB_INT_SUM interrupts.
                                                                 0 = INT 0 Enable.
                                                                 1 = VINT enable .
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior to initial configuration of the interrupt enable register.

                                                                 Internal:
                                                                 This bit in F95 control the level of interrupt reported - level 1 or level 2. */
        uint64_t dma_int_trig_style    : 1;  /**< [  1:  1](R/W) Reserved. Must be 0.
                                                                 Internal:
                                                                 Determines whether interrupts reported via MDAB_INT_SUM are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior to initial configuration of the interrupt enable register. */
        uint64_t ld_lcl_trig_style     : 1;  /**< [  2:  2](R/W) Reserved. must be 0.
                                                                 Internal:
                                                                 Determines whether load local start/finish interrupts are level or
                                                                 edge triggered:
                                                                 0 = Level-sensitive.
                                                                 1 = Edge-triggered.
                                                                 NOTE: To ensure correct generation of outstanding interrupts, this bit MUST be programmed
                                                                 prior to initial configuration of the interrupt enable register. */
        uint64_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_int_sel cavm_mdabx_int_sel_t;

static inline uint64_t CAVM_MDABX_INT_SEL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_INT_SEL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100190ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400190ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_INT_SEL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_INT_SEL(a) cavm_mdabx_int_sel_t
#define bustype_CAVM_MDABX_INT_SEL(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_INT_SEL(a) "MDABX_INT_SEL"
#define busnum_CAVM_MDABX_INT_SEL(a) (a)
#define arguments_CAVM_MDABX_INT_SEL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_int_src
 *
 * MDAB Secondary Interrupt Source Register
 * This register allows OCTEON TX2 software or DSP software to trigger a software
 * generated interrupt.
 */
union cavm_mdabx_int_src
{
    uint64_t u;
    struct cavm_mdabx_int_src_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t sw_intr               : 1;  /**< [  0:  0](R/W) Generates a software interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t sw_intr               : 1;  /**< [  0:  0](R/W) Generates a software interrupt. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_int_src_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_31         : 31;
        uint64_t sw_intr               : 1;  /**< [  0:  0](R/W) Generates a software interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t sw_intr               : 1;  /**< [  0:  0](R/W) Generates a software interrupt. */
        uint64_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_int_src cavm_mdabx_int_src_t;

static inline uint64_t CAVM_MDABX_INT_SRC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_INT_SRC(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441001a0ll + 0x4000ll * ((a) & 0x3f);
    __cavm_csr_fatal("MDABX_INT_SRC", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_INT_SRC(a) cavm_mdabx_int_src_t
#define bustype_CAVM_MDABX_INT_SRC(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_INT_SRC(a) "MDABX_INT_SRC"
#define busnum_CAVM_MDABX_INT_SRC(a) (a)
#define arguments_CAVM_MDABX_INT_SRC(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_int_sum_w1c
 *
 * MDAB Interrupt Summary Register
 * This register reports the interrupt status for the MDAB DMA engines.
 * Software clears individual interrupts by writing one to the corresponding bit.
 */
union cavm_mdabx_int_sum_w1c
{
    uint64_t u;
    struct cavm_mdabx_int_sum_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Indicates a job is ready in slot 1. Writing a 1 to this bit clears the interrupt. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Indicates a job is ready in slot 0. Writing a 1 to this bit clears the interrupt. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Output data DMA underflow. When set, indicates that the MDAB()_WR_LIMIT
                                                                 specified a DMA transfer that was smaller than the amount of output
                                                                 data described by the job descriptor and the DSP had data remaining
                                                                 in the buffer when the transaction completed. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Output data DMA overflow. When set, indicates that the MDAB()_WR_LIMIT
                                                                 specified a DMA transfer that exceeded the amount of output data
                                                                 described by the job descriptor and the DMA engine was unable to
                                                                 transfer all of the data between MDAB()_WR_ADDR and
                                                                 MDAB()_WR_ADDR+MDAB()_WR_LIMIT. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) When set indicates that the WR-DMA engine completed transferring all
                                                                 output data described by the job descriptor (JD.WR-DMA). */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Output data WR-DMA slice done. When set, indicates that the WR-DMA
                                                                 engine completed an output data transfer but reached MDAB()_WR_LIMIT
                                                                 before transferring all of the output data described by the job descriptor. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Output data WR-DMA pending. When set, software needs to program the
                                                                 output data WR-DMA engine to transfer the output data for a new job. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) When set indicates that the input data RD-DMA engine completed
                                                                 transferring all input data for a job. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) RD-DMA slice done. When set, indicates that the RD-DMA engine
                                                                 completed an input data transfer but reached MDAB()_RD_LIMIT before
                                                                 transferring all of the input data for the job. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) RD-DMA pending. When set, software needs to program the RD-DMA engine
                                                                 to transfer the input data for a new job. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) CFG-DMA LAST Done detected: When set indicates that the CFG-DMA
                                                                 engine detected the last data transfer for the entire job
                                                                 configuration data (JD.JCFG) for a job. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) CFG-DMA slice done. When set, indicates that the CFG-DMA engine
                                                                 completed a job configuration data slice transfer and reached the
                                                                 MDAB()_CFG_LIMIT before transferring the LAST data from job configuration
                                                                 data for the job (JD.JCFG). */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) CFG-DMA pending. When set, software needs to program the CFG-DMA
                                                                 engine to transfer the job configuration data for a new job. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) CFG-DMA pending. When set, software needs to program the CFG-DMA
                                                                 engine to transfer the job configuration data for a new job. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) CFG-DMA slice done. When set, indicates that the CFG-DMA engine
                                                                 completed a job configuration data slice transfer and reached the
                                                                 MDAB()_CFG_LIMIT before transferring the LAST data from job configuration
                                                                 data for the job (JD.JCFG). */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) CFG-DMA LAST Done detected: When set indicates that the CFG-DMA
                                                                 engine detected the last data transfer for the entire job
                                                                 configuration data (JD.JCFG) for a job. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) RD-DMA pending. When set, software needs to program the RD-DMA engine
                                                                 to transfer the input data for a new job. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) RD-DMA slice done. When set, indicates that the RD-DMA engine
                                                                 completed an input data transfer but reached MDAB()_RD_LIMIT before
                                                                 transferring all of the input data for the job. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) When set indicates that the input data RD-DMA engine completed
                                                                 transferring all input data for a job. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Output data WR-DMA pending. When set, software needs to program the
                                                                 output data WR-DMA engine to transfer the output data for a new job. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Output data WR-DMA slice done. When set, indicates that the WR-DMA
                                                                 engine completed an output data transfer but reached MDAB()_WR_LIMIT
                                                                 before transferring all of the output data described by the job descriptor. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) When set indicates that the WR-DMA engine completed transferring all
                                                                 output data described by the job descriptor (JD.WR-DMA). */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Output data DMA overflow. When set, indicates that the MDAB()_WR_LIMIT
                                                                 specified a DMA transfer that exceeded the amount of output data
                                                                 described by the job descriptor and the DMA engine was unable to
                                                                 transfer all of the data between MDAB()_WR_ADDR and
                                                                 MDAB()_WR_ADDR+MDAB()_WR_LIMIT. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Output data DMA underflow. When set, indicates that the MDAB()_WR_LIMIT
                                                                 specified a DMA transfer that was smaller than the amount of output
                                                                 data described by the job descriptor and the DSP had data remaining
                                                                 in the buffer when the transaction completed. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Indicates a job is ready in slot 0. Writing a 1 to this bit clears the interrupt. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Indicates a job is ready in slot 1. Writing a 1 to this bit clears the interrupt. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_int_sum_w1c_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_31        : 19;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Indicates a job is ready in slot 1. Writing a 1 to this bit clears the interrupt. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Indicates a job is ready in slot 0. Writing a 1 to this bit clears the interrupt. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Output data DMA underflow. When set, indicates that the MDAB()_WR_LIMIT
                                                                 specified a DMA transfer that was smaller than the amount of output
                                                                 data described by the job descriptor and the DSP had data remaining
                                                                 in the buffer when the transaction completed. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Output data DMA overflow. When set, indicates that the MDAB()_WR_LIMIT
                                                                 specified a DMA transfer that exceeded the amount of output data
                                                                 described by the job descriptor and the DMA engine was unable to
                                                                 transfer all of the data between MDAB()_WR_ADDR and
                                                                 MDAB()_WR_ADDR+MDAB()_WR_LIMIT. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) When set indicates that the WR-DMA engine completed transferring all
                                                                 output data described by the job descriptor (JD.WR-DMA). */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Output data WR-DMA slice done. When set, indicates that the WR-DMA
                                                                 engine completed an output data transfer but reached MDAB()_WR_LIMIT
                                                                 before transferring all of the output data described by the job descriptor. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Output data WR-DMA pending. When set, software needs to program the
                                                                 output data WR-DMA engine to transfer the output data for a new job. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) When set indicates that the input data RD-DMA engine completed
                                                                 transferring all input data for a job. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) RD-DMA slice done. When set, indicates that the RD-DMA engine
                                                                 completed an input data transfer but reached MDAB()_RD_LIMIT before
                                                                 transferring all of the input data for the job. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) RD-DMA pending. When set, software needs to program the RD-DMA engine
                                                                 to transfer the input data for a new job. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) CFG-DMA LAST Done detected: When set indicates that the CFG-DMA
                                                                 engine detected the last data transfer for the entire job
                                                                 configuration data (JD.JCFG) for a job. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) CFG-DMA slice done. When set, indicates that the CFG-DMA engine
                                                                 completed a job configuration data slice transfer and reached the
                                                                 MDAB()_CFG_LIMIT before transferring the LAST data from job configuration
                                                                 data for the job (JD.JCFG). */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) CFG-DMA pending. When set, software needs to program the CFG-DMA
                                                                 engine to transfer the job configuration data for a new job. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1C/H) CFG-DMA pending. When set, software needs to program the CFG-DMA
                                                                 engine to transfer the job configuration data for a new job. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1C/H) CFG-DMA slice done. When set, indicates that the CFG-DMA engine
                                                                 completed a job configuration data slice transfer and reached the
                                                                 MDAB()_CFG_LIMIT before transferring the LAST data from job configuration
                                                                 data for the job (JD.JCFG). */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1C/H) CFG-DMA LAST Done detected: When set indicates that the CFG-DMA
                                                                 engine detected the last data transfer for the entire job
                                                                 configuration data (JD.JCFG) for a job. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1C/H) RD-DMA pending. When set, software needs to program the RD-DMA engine
                                                                 to transfer the input data for a new job. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1C/H) RD-DMA slice done. When set, indicates that the RD-DMA engine
                                                                 completed an input data transfer but reached MDAB()_RD_LIMIT before
                                                                 transferring all of the input data for the job. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1C/H) When set indicates that the input data RD-DMA engine completed
                                                                 transferring all input data for a job. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1C/H) Output data WR-DMA pending. When set, software needs to program the
                                                                 output data WR-DMA engine to transfer the output data for a new job. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1C/H) Output data WR-DMA slice done. When set, indicates that the WR-DMA
                                                                 engine completed an output data transfer but reached MDAB()_WR_LIMIT
                                                                 before transferring all of the output data described by the job descriptor. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1C/H) When set indicates that the WR-DMA engine completed transferring all
                                                                 output data described by the job descriptor (JD.WR-DMA). */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1C/H) Output data DMA overflow. When set, indicates that the MDAB()_WR_LIMIT
                                                                 specified a DMA transfer that exceeded the amount of output data
                                                                 described by the job descriptor and the DMA engine was unable to
                                                                 transfer all of the data between MDAB()_WR_ADDR and
                                                                 MDAB()_WR_ADDR+MDAB()_WR_LIMIT. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1C/H) Output data DMA underflow. When set, indicates that the MDAB()_WR_LIMIT
                                                                 specified a DMA transfer that was smaller than the amount of output
                                                                 data described by the job descriptor and the DSP had data remaining
                                                                 in the buffer when the transaction completed. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1C/H) Indicates a job is ready in slot 0. Writing a 1 to this bit clears the interrupt. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1C/H) Indicates a job is ready in slot 1. Writing a 1 to this bit clears the interrupt. */
        uint64_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_int_sum_w1c cavm_mdabx_int_sum_w1c_t;

static inline uint64_t CAVM_MDABX_INT_SUM_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_INT_SUM_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100150ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400150ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_INT_SUM_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_INT_SUM_W1C(a) cavm_mdabx_int_sum_w1c_t
#define bustype_CAVM_MDABX_INT_SUM_W1C(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_INT_SUM_W1C(a) "MDABX_INT_SUM_W1C"
#define busnum_CAVM_MDABX_INT_SUM_W1C(a) (a)
#define arguments_CAVM_MDABX_INT_SUM_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_int_sum_w1s
 *
 * MDAB Interrupt Summary SET Register
 * This register is used to artificially set MDAB interrupts described in
 * MDAB_INT_SUM (for software Debug/Test), and also provides the hardware input to allow
 * the DMA controllers to set the appropriate interrupt bit.
 */
union cavm_mdabx_int_sum_w1s
{
    uint64_t u;
    struct cavm_mdabx_int_sum_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_PENDING]. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_PENDING]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_int_sum_w1s_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_31        : 19;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_PENDING]. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_PENDING]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets the MDABx_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_PENDING]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets the MDABx_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_PENDING]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets the MDABx_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the MDABx_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the MDABx_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_int_sum_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_31        : 19;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the MDAB()_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the MDAB()_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets the MDAB()_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets the MDAB()_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the MBAD()_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets the MBAD()_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets the MBAD()_INT_SUM[WR_DMA_PENDING]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets the MBAD()_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets the MBAD()_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets the MBAD()_INT_SUM[RD_DMA_PENDING]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets the MBAD()_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the MBAD()_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets the MBAD()_INT_SUM[CFG_DMA_PENDING]. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](R/W1S/H) Reads or sets the MBAD()_INT_SUM[CFG_DMA_PENDING]. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the MBAD()_INT_SUM[CFG_DMA_SLICE_DONE]. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](R/W1S/H) Reads or sets the MBAD()_INT_SUM[CFG_DMA_LAST_DONE]. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets the MBAD()_INT_SUM[RD_DMA_PENDING]. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](R/W1S/H) Reads or sets the MBAD()_INT_SUM[RD_DMA_SLICE_DONE]. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets the MBAD()_INT_SUM[RD_DMA_LAST_DONE]. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](R/W1S/H) Reads or sets the MBAD()_INT_SUM[WR_DMA_PENDING]. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](R/W1S/H) Reads or sets the MBAD()_INT_SUM[WR_DMA_SLICE_DONE]. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the MBAD()_INT_SUM[WR_DMA_LAST_DONE]. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets the MDAB()_INT_SUM[WR_DMA_OFLOW]. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets the MDAB()_INT_SUM[WR_DMA_UFLOW]. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets the MDAB()_INT_SUM[JOB_RDY0] interrupt bit. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets the MDAB()_INT_SUM[JOB_RDY1] interrupt bit. */
        uint64_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_int_sum_w1s cavm_mdabx_int_sum_w1s_t;

static inline uint64_t CAVM_MDABX_INT_SUM_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_INT_SUM_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100160ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400160ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_INT_SUM_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_INT_SUM_W1S(a) cavm_mdabx_int_sum_w1s_t
#define bustype_CAVM_MDABX_INT_SUM_W1S(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_INT_SUM_W1S(a) "MDABX_INT_SUM_W1S"
#define busnum_CAVM_MDABX_INT_SUM_W1S(a) (a)
#define arguments_CAVM_MDABX_INT_SUM_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_int_vec_addr
 *
 * MDAB Interrupt Vector Address Register
 * This register sets the address for usage in case of INT Vec assertion. It is also
 * being used upon reset exit for boot address when Boot register is set.
 */
union cavm_mdabx_int_vec_addr
{
    uint32_t u;
    struct cavm_mdabx_int_vec_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vecaddr               : 28; /**< [ 31:  4](R/W) Handler Vector address. */
        uint32_t reserved_1_3          : 3;
        uint32_t vintc                 : 1;  /**< [  0:  0](R/W) Context switch control. */
#else /* Word 0 - Little Endian */
        uint32_t vintc                 : 1;  /**< [  0:  0](R/W) Context switch control. */
        uint32_t reserved_1_3          : 3;
        uint32_t vecaddr               : 28; /**< [ 31:  4](R/W) Handler Vector address. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_int_vec_addr_s cn; */
};
typedef union cavm_mdabx_int_vec_addr cavm_mdabx_int_vec_addr_t;

static inline uint64_t CAVM_MDABX_INT_VEC_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_INT_VEC_ADDR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400ae0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_INT_VEC_ADDR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_INT_VEC_ADDR(a) cavm_mdabx_int_vec_addr_t
#define bustype_CAVM_MDABX_INT_VEC_ADDR(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_INT_VEC_ADDR(a) "MDABX_INT_VEC_ADDR"
#define busnum_CAVM_MDABX_INT_VEC_ADDR(a) (a)
#define arguments_CAVM_MDABX_INT_VEC_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_interrupt_active
 *
 * MDAB Interrupt Active Status Register
 * This register indicates what interrupts are enabled and active.
 */
union cavm_mdabx_interrupt_active
{
    uint64_t u;
    struct cavm_mdabx_interrupt_active_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](RO/H) Indicates the JOB_RDY1 interrupt is active. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](RO/H) Indicates the JOB_RDY0 interrupt is active. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](RO/H) Indicates the WR_DMA_UFLOW interrupt is active. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](RO/H) Indicates the WR_DMA_OFLOW interrupt is active. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](RO/H) Indicates the WR_DMA_LAST_DONE interrupt is active. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](RO/H) Indicates the WR_DMA_SLICE_DONE interrupt is active. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](RO/H) Indicates the WR_DMA_PENDING interrupt is active. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](RO/H) Indicates the RD_DMA_LAST_DONE interrupt is active. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](RO/H) Indicates the RD_DMA_SLICE_DONE interrupt is active. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](RO/H) Indicates the RD_DMA_PENDING interrupt is active. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](RO/H) Indicates the CFG_DMA_LAST_DONE interrupt is active. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](RO/H) Indicates the CFG_DMA_SLICE_DONE interrupt is active. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](RO/H) Indicates the CFG_DMA_PENDING interrupt is active. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](RO/H) Indicates the CFG_DMA_PENDING interrupt is active. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](RO/H) Indicates the CFG_DMA_SLICE_DONE interrupt is active. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](RO/H) Indicates the CFG_DMA_LAST_DONE interrupt is active. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](RO/H) Indicates the RD_DMA_PENDING interrupt is active. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](RO/H) Indicates the RD_DMA_SLICE_DONE interrupt is active. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](RO/H) Indicates the RD_DMA_LAST_DONE interrupt is active. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](RO/H) Indicates the WR_DMA_PENDING interrupt is active. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](RO/H) Indicates the WR_DMA_SLICE_DONE interrupt is active. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](RO/H) Indicates the WR_DMA_LAST_DONE interrupt is active. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](RO/H) Indicates the WR_DMA_OFLOW interrupt is active. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](RO/H) Indicates the WR_DMA_UFLOW interrupt is active. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](RO/H) Indicates the JOB_RDY0 interrupt is active. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](RO/H) Indicates the JOB_RDY1 interrupt is active. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_interrupt_active_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_31        : 19;
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](RO/H) Indicates the JOB_RDY1 interrupt is active. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](RO/H) Indicates the JOB_RDY0 interrupt is active. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](RO/H) Indicates the WR_DMA_UFLOW interrupt is active. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](RO/H) Indicates the WR_DMA_OFLOW interrupt is active. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](RO/H) Indicates the WR_DMA_LAST_DONE interrupt is active. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](RO/H) Indicates the WR_DMA_SLICE_DONE interrupt is active. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](RO/H) Indicates the WR_DMA_PENDING interrupt is active. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](RO/H) Indicates the RD_DMA_LAST_DONE interrupt is active. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](RO/H) Indicates the RD_DMA_SLICE_DONE interrupt is active. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](RO/H) Indicates the RD_DMA_PENDING interrupt is active. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](RO/H) Indicates the CFG_DMA_LAST_DONE interrupt is active. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](RO/H) Indicates the CFG_DMA_SLICE_DONE interrupt is active. */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](RO/H) Indicates the CFG_DMA_PENDING interrupt is active. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_dma_pending       : 1;  /**< [  0:  0](RO/H) Indicates the CFG_DMA_PENDING interrupt is active. */
        uint64_t cfg_dma_slice_done    : 1;  /**< [  1:  1](RO/H) Indicates the CFG_DMA_SLICE_DONE interrupt is active. */
        uint64_t cfg_dma_last_done     : 1;  /**< [  2:  2](RO/H) Indicates the CFG_DMA_LAST_DONE interrupt is active. */
        uint64_t rd_dma_pending        : 1;  /**< [  3:  3](RO/H) Indicates the RD_DMA_PENDING interrupt is active. */
        uint64_t rd_dma_slice_done     : 1;  /**< [  4:  4](RO/H) Indicates the RD_DMA_SLICE_DONE interrupt is active. */
        uint64_t rd_dma_last_done      : 1;  /**< [  5:  5](RO/H) Indicates the RD_DMA_LAST_DONE interrupt is active. */
        uint64_t wr_dma_pending        : 1;  /**< [  6:  6](RO/H) Indicates the WR_DMA_PENDING interrupt is active. */
        uint64_t wr_dma_slice_done     : 1;  /**< [  7:  7](RO/H) Indicates the WR_DMA_SLICE_DONE interrupt is active. */
        uint64_t wr_dma_last_done      : 1;  /**< [  8:  8](RO/H) Indicates the WR_DMA_LAST_DONE interrupt is active. */
        uint64_t wr_dma_oflow          : 1;  /**< [  9:  9](RO/H) Indicates the WR_DMA_OFLOW interrupt is active. */
        uint64_t wr_dma_uflow          : 1;  /**< [ 10: 10](RO/H) Indicates the WR_DMA_UFLOW interrupt is active. */
        uint64_t job_rdy0              : 1;  /**< [ 11: 11](RO/H) Indicates the JOB_RDY0 interrupt is active. */
        uint64_t job_rdy1              : 1;  /**< [ 12: 12](RO/H) Indicates the JOB_RDY1 interrupt is active. */
        uint64_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_interrupt_active cavm_mdabx_interrupt_active_t;

static inline uint64_t CAVM_MDABX_INTERRUPT_ACTIVE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_INTERRUPT_ACTIVE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100280ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400280ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_INTERRUPT_ACTIVE", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_INTERRUPT_ACTIVE(a) cavm_mdabx_interrupt_active_t
#define bustype_CAVM_MDABX_INTERRUPT_ACTIVE(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_INTERRUPT_ACTIVE(a) "MDABX_INTERRUPT_ACTIVE"
#define busnum_CAVM_MDABX_INTERRUPT_ACTIVE(a) (a)
#define arguments_CAVM_MDABX_INTERRUPT_ACTIVE(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ipb_ctl
 *
 * MDAB IPB Control Register
 * IPB Control Register.
 */
union cavm_mdabx_ipb_ctl
{
    uint32_t u;
    struct cavm_mdabx_ipb_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t prefetch_size         : 3;  /**< [  7:  5](R/W) This register defines the prefetch size in clines on a miss (values 1 to 7).
                                                                 When programmed to value 0, IPB data prefetch is disabled. */
        uint32_t priority_mode         : 2;  /**< [  4:  3](R/W) This register defines the priority of IPB data fetch and data prefetch requests.
                                                                 HP_DISABLED   = 0 - no high priority requests.
                                                                 HP_DFETCH_CWF = 1 - high priority only for CWF data fetch request.
                                                                 HP_DFETCH     = 2 - high priority for all data fetch requests.
                                                                 HP_FETCH_ALL  = 3 - high priority for all IPB requests. */
        uint32_t arbiter_mode          : 3;  /**< [  2:  0](R/W) The IPB arbiter mode field can be set to the following values.
                                                                 RR_REQ     = 0 - interleaved request. Round robin between IPB and GXF at 16B
                                                                 single FLIT level.
                                                                 RR_TRN     = 1 - interleaved transaction. Round robin at the transaction level.
                                                                 GXF transaction - RD32 (2x16B requests), WR (1x16B request).
                                                                 IPB transaction - between 1 and 7x 16B requests (programmable).
                                                                 FP_REQ_GXF = 2 - fixed priority requests, GXF has highest priority.
                                                                 FP_REQ_IPB = 3 - fixed priority requests, IPB has highest priority.
                                                                 FP_REQ_DAT = 4 - fixed priority requests (DFETCH, GXF, PFETCH).
                                                                 FP_TRN_GXF = 5 - fixed priority transaction, GXF has highest priority.
                                                                 FP_TRN_IPB = 6 - fixed priority transaction, IPB has highest priority.
                                                                 FP_TRN_DAT = 7 - fixed priority transaction (DFETCH, GXF, PFETCH).
                                                                 This field is static and should be programmed once at power on. */
#else /* Word 0 - Little Endian */
        uint32_t arbiter_mode          : 3;  /**< [  2:  0](R/W) The IPB arbiter mode field can be set to the following values.
                                                                 RR_REQ     = 0 - interleaved request. Round robin between IPB and GXF at 16B
                                                                 single FLIT level.
                                                                 RR_TRN     = 1 - interleaved transaction. Round robin at the transaction level.
                                                                 GXF transaction - RD32 (2x16B requests), WR (1x16B request).
                                                                 IPB transaction - between 1 and 7x 16B requests (programmable).
                                                                 FP_REQ_GXF = 2 - fixed priority requests, GXF has highest priority.
                                                                 FP_REQ_IPB = 3 - fixed priority requests, IPB has highest priority.
                                                                 FP_REQ_DAT = 4 - fixed priority requests (DFETCH, GXF, PFETCH).
                                                                 FP_TRN_GXF = 5 - fixed priority transaction, GXF has highest priority.
                                                                 FP_TRN_IPB = 6 - fixed priority transaction, IPB has highest priority.
                                                                 FP_TRN_DAT = 7 - fixed priority transaction (DFETCH, GXF, PFETCH).
                                                                 This field is static and should be programmed once at power on. */
        uint32_t priority_mode         : 2;  /**< [  4:  3](R/W) This register defines the priority of IPB data fetch and data prefetch requests.
                                                                 HP_DISABLED   = 0 - no high priority requests.
                                                                 HP_DFETCH_CWF = 1 - high priority only for CWF data fetch request.
                                                                 HP_DFETCH     = 2 - high priority for all data fetch requests.
                                                                 HP_FETCH_ALL  = 3 - high priority for all IPB requests. */
        uint32_t prefetch_size         : 3;  /**< [  7:  5](R/W) This register defines the prefetch size in clines on a miss (values 1 to 7).
                                                                 When programmed to value 0, IPB data prefetch is disabled. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_ipb_ctl_s cn; */
};
typedef union cavm_mdabx_ipb_ctl cavm_mdabx_ipb_ctl_t;

static inline uint64_t CAVM_MDABX_IPB_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_IPB_CTL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441002c0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444002c0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_IPB_CTL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_IPB_CTL(a) cavm_mdabx_ipb_ctl_t
#define bustype_CAVM_MDABX_IPB_CTL(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_IPB_CTL(a) "MDABX_IPB_CTL"
#define busnum_CAVM_MDABX_IPB_CTL(a) (a)
#define arguments_CAVM_MDABX_IPB_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ipb_flush
 *
 * MDAB IPB Flush Register
 * IPB flush control register
 */
union cavm_mdabx_ipb_flush
{
    uint32_t u;
    struct cavm_mdabx_ipb_flush_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_2_31         : 30;
        uint32_t flush                 : 1;  /**< [  1:  1](R/W1C) Write to 1 to flush the IPB. This can be done only if field IPB IDLE is 1. */
        uint32_t idle                  : 1;  /**< [  0:  0](RO/H) Set by the IPB whenever it is not servicing a cache miss request. */
#else /* Word 0 - Little Endian */
        uint32_t idle                  : 1;  /**< [  0:  0](RO/H) Set by the IPB whenever it is not servicing a cache miss request. */
        uint32_t flush                 : 1;  /**< [  1:  1](R/W1C) Write to 1 to flush the IPB. This can be done only if field IPB IDLE is 1. */
        uint32_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_ipb_flush_s cn; */
};
typedef union cavm_mdabx_ipb_flush cavm_mdabx_ipb_flush_t;

static inline uint64_t CAVM_MDABX_IPB_FLUSH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_IPB_FLUSH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441002f0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444002f0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_IPB_FLUSH", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_IPB_FLUSH(a) cavm_mdabx_ipb_flush_t
#define bustype_CAVM_MDABX_IPB_FLUSH(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_IPB_FLUSH(a) "MDABX_IPB_FLUSH"
#define busnum_CAVM_MDABX_IPB_FLUSH(a) (a)
#define arguments_CAVM_MDABX_IPB_FLUSH(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ipb_perf_ctl
 *
 * IPB Performance Measurement Control Register
 * IPB Performance Measurement Control.
 */
union cavm_mdabx_ipb_perf_ctl
{
    uint32_t u;
    struct cavm_mdabx_ipb_perf_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t enable                : 1;  /**< [  0:  0](R/W) Enable/disable IPB performance measurement. Write 1 to enable and 0 to disable. */
#else /* Word 0 - Little Endian */
        uint32_t enable                : 1;  /**< [  0:  0](R/W) Enable/disable IPB performance measurement. Write 1 to enable and 0 to disable. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_ipb_perf_ctl_s cn; */
};
typedef union cavm_mdabx_ipb_perf_ctl cavm_mdabx_ipb_perf_ctl_t;

static inline uint64_t CAVM_MDABX_IPB_PERF_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_IPB_PERF_CTL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441004a0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444004a0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_IPB_PERF_CTL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_IPB_PERF_CTL(a) cavm_mdabx_ipb_perf_ctl_t
#define bustype_CAVM_MDABX_IPB_PERF_CTL(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_IPB_PERF_CTL(a) "MDABX_IPB_PERF_CTL"
#define busnum_CAVM_MDABX_IPB_PERF_CTL(a) (a)
#define arguments_CAVM_MDABX_IPB_PERF_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ipb_perf_hitcnt
 *
 * IPB Hit Register
 * Count number of IPB hits.
 */
union cavm_mdabx_ipb_perf_hitcnt
{
    uint32_t u;
    struct cavm_mdabx_ipb_perf_hitcnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t hit_count             : 32; /**< [ 31:  0](RO/H) This counter is incremented each time the cache line requested is present in the IPB.
                                                                 Counter is cleared and enabled by writing 1 to field ENABLE of register IPB_PERF_CTL.
                                                                 Counter is disabled by writing 0 to field ENABLE of register IPB_PERF_CTL. */
#else /* Word 0 - Little Endian */
        uint32_t hit_count             : 32; /**< [ 31:  0](RO/H) This counter is incremented each time the cache line requested is present in the IPB.
                                                                 Counter is cleared and enabled by writing 1 to field ENABLE of register IPB_PERF_CTL.
                                                                 Counter is disabled by writing 0 to field ENABLE of register IPB_PERF_CTL. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_ipb_perf_hitcnt_s cn; */
};
typedef union cavm_mdabx_ipb_perf_hitcnt cavm_mdabx_ipb_perf_hitcnt_t;

static inline uint64_t CAVM_MDABX_IPB_PERF_HITCNT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_IPB_PERF_HITCNT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441004c0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444004c0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_IPB_PERF_HITCNT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_IPB_PERF_HITCNT(a) cavm_mdabx_ipb_perf_hitcnt_t
#define bustype_CAVM_MDABX_IPB_PERF_HITCNT(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_IPB_PERF_HITCNT(a) "MDABX_IPB_PERF_HITCNT"
#define busnum_CAVM_MDABX_IPB_PERF_HITCNT(a) (a)
#define arguments_CAVM_MDABX_IPB_PERF_HITCNT(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ipb_perf_latency
 *
 * IPB Minimum and Maximum Latency Register
 * Store maximum and minimum IPB response latency.
 */
union cavm_mdabx_ipb_perf_latency
{
    uint32_t u;
    struct cavm_mdabx_ipb_perf_latency_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t misslat_max           : 16; /**< [ 31: 16](RO/H) Maximum number of clock cycles counted from the moment the cache miss request is received
                                                                 until the first response FLIT is sent back. This field is permanently forced to 0 when the clock
                                                                 cycle counter overflows. */
        uint32_t misslat_min           : 16; /**< [ 15:  0](RO/H) Minimum number of clock cycles counted from the moment the cache miss request is received
                                                                 until the first response FLIT is sent back. This field is permanently forced to 0 when the clock
                                                                 cycle counter overflows. */
#else /* Word 0 - Little Endian */
        uint32_t misslat_min           : 16; /**< [ 15:  0](RO/H) Minimum number of clock cycles counted from the moment the cache miss request is received
                                                                 until the first response FLIT is sent back. This field is permanently forced to 0 when the clock
                                                                 cycle counter overflows. */
        uint32_t misslat_max           : 16; /**< [ 31: 16](RO/H) Maximum number of clock cycles counted from the moment the cache miss request is received
                                                                 until the first response FLIT is sent back. This field is permanently forced to 0 when the clock
                                                                 cycle counter overflows. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_ipb_perf_latency_s cn; */
};
typedef union cavm_mdabx_ipb_perf_latency cavm_mdabx_ipb_perf_latency_t;

static inline uint64_t CAVM_MDABX_IPB_PERF_LATENCY(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_IPB_PERF_LATENCY(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441004d0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444004d0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_IPB_PERF_LATENCY", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_IPB_PERF_LATENCY(a) cavm_mdabx_ipb_perf_latency_t
#define bustype_CAVM_MDABX_IPB_PERF_LATENCY(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_IPB_PERF_LATENCY(a) "MDABX_IPB_PERF_LATENCY"
#define busnum_CAVM_MDABX_IPB_PERF_LATENCY(a) (a)
#define arguments_CAVM_MDABX_IPB_PERF_LATENCY(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ipb_perf_misscnt
 *
 * IPB Cache Miss Request Register
 * Count number of cache miss requests received by the IPB.
 */
union cavm_mdabx_ipb_perf_misscnt
{
    uint32_t u;
    struct cavm_mdabx_ipb_perf_misscnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t miss_count            : 32; /**< [ 31:  0](RO/H) This counter is incremented each time a cache miss request is received by the IPB.
                                                                 Counter is cleared and enabled by writing 1 to field ENABLE of register IPB_PERF_CTL.
                                                                 Counter is disabled by writing 0 to field ENABLE of register IPB_PERF_CTL. */
#else /* Word 0 - Little Endian */
        uint32_t miss_count            : 32; /**< [ 31:  0](RO/H) This counter is incremented each time a cache miss request is received by the IPB.
                                                                 Counter is cleared and enabled by writing 1 to field ENABLE of register IPB_PERF_CTL.
                                                                 Counter is disabled by writing 0 to field ENABLE of register IPB_PERF_CTL. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_ipb_perf_misscnt_s cn; */
};
typedef union cavm_mdabx_ipb_perf_misscnt cavm_mdabx_ipb_perf_misscnt_t;

static inline uint64_t CAVM_MDABX_IPB_PERF_MISSCNT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_IPB_PERF_MISSCNT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441004b0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444004b0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_IPB_PERF_MISSCNT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_IPB_PERF_MISSCNT(a) cavm_mdabx_ipb_perf_misscnt_t
#define bustype_CAVM_MDABX_IPB_PERF_MISSCNT(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_IPB_PERF_MISSCNT(a) "MDABX_IPB_PERF_MISSCNT"
#define busnum_CAVM_MDABX_IPB_PERF_MISSCNT(a) (a)
#define arguments_CAVM_MDABX_IPB_PERF_MISSCNT(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ipb_pfrange_max
 *
 * MDAB IPB Maximum Prefetch Range Register
 * IPB maximum prefetch range control register.
 */
union cavm_mdabx_ipb_pfrange_max
{
    uint32_t u;
    struct cavm_mdabx_ipb_pfrange_max_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t prefetch_max          : 28; /**< [ 31:  4](R/W) The upper (max) address bounds for the prefetch address check.
                                                                 This value is specified as a 16B address aligned to a cache line boundary.
                                                                 Set this value in conjunction with IPB PREFETCH_SIZE such that IPB prefetch
                                                                 address stays inside valid memory range.
                                                                 Legal SYSMEM address range is [0xFFFF_FFFF:0x8000_0000].
                                                                 Legal SMEM DSP address range is [0x617F_FFFF:0x6000_0000]. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t prefetch_max          : 28; /**< [ 31:  4](R/W) The upper (max) address bounds for the prefetch address check.
                                                                 This value is specified as a 16B address aligned to a cache line boundary.
                                                                 Set this value in conjunction with IPB PREFETCH_SIZE such that IPB prefetch
                                                                 address stays inside valid memory range.
                                                                 Legal SYSMEM address range is [0xFFFF_FFFF:0x8000_0000].
                                                                 Legal SMEM DSP address range is [0x617F_FFFF:0x6000_0000]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_ipb_pfrange_max_s cn; */
};
typedef union cavm_mdabx_ipb_pfrange_max cavm_mdabx_ipb_pfrange_max_t;

static inline uint64_t CAVM_MDABX_IPB_PFRANGE_MAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_IPB_PFRANGE_MAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441002e0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444002e0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_IPB_PFRANGE_MAX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_IPB_PFRANGE_MAX(a) cavm_mdabx_ipb_pfrange_max_t
#define bustype_CAVM_MDABX_IPB_PFRANGE_MAX(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_IPB_PFRANGE_MAX(a) "MDABX_IPB_PFRANGE_MAX"
#define busnum_CAVM_MDABX_IPB_PFRANGE_MAX(a) (a)
#define arguments_CAVM_MDABX_IPB_PFRANGE_MAX(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ipb_pfrange_min
 *
 * MDAB IPB Minimum Prefetch Range Register
 * IPB minimum prefetch range control register.
 */
union cavm_mdabx_ipb_pfrange_min
{
    uint32_t u;
    struct cavm_mdabx_ipb_pfrange_min_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t prefetch_min          : 28; /**< [ 31:  4](R/W) The lower (min) address bounds for the prefetch address check.
                                                                 This value is specified as a 16B address aligned to a cache line boundary.
                                                                 Set this value in conjunction with IPB PREFETCH_SIZE such that IPB prefetch
                                                                 address stays inside valid memory range.
                                                                 Legal SYSMEM address range is [0xFFFF_FFFF:0x8000_0000].
                                                                 Legal SMEM DSP address range is [0x617F_FFFF:0x6000_0000]. */
        uint32_t reserved_1_3          : 3;
        uint32_t prefetch_range        : 1;  /**< [  0:  0](R/W) When RANGE=0(IN) - All I$ Miss addresses \>= MIN AND \<= MAX
                                                                 will generate the 'n' programmable PFETCHes.
                                                                 When RANGE=1(OUT) - All I$ Miss addresses \< MIN OR \> MAX
                                                                 will generate the 'n' programmable PFETCHes. */
#else /* Word 0 - Little Endian */
        uint32_t prefetch_range        : 1;  /**< [  0:  0](R/W) When RANGE=0(IN) - All I$ Miss addresses \>= MIN AND \<= MAX
                                                                 will generate the 'n' programmable PFETCHes.
                                                                 When RANGE=1(OUT) - All I$ Miss addresses \< MIN OR \> MAX
                                                                 will generate the 'n' programmable PFETCHes. */
        uint32_t reserved_1_3          : 3;
        uint32_t prefetch_min          : 28; /**< [ 31:  4](R/W) The lower (min) address bounds for the prefetch address check.
                                                                 This value is specified as a 16B address aligned to a cache line boundary.
                                                                 Set this value in conjunction with IPB PREFETCH_SIZE such that IPB prefetch
                                                                 address stays inside valid memory range.
                                                                 Legal SYSMEM address range is [0xFFFF_FFFF:0x8000_0000].
                                                                 Legal SMEM DSP address range is [0x617F_FFFF:0x6000_0000]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_ipb_pfrange_min_s cn; */
};
typedef union cavm_mdabx_ipb_pfrange_min cavm_mdabx_ipb_pfrange_min_t;

static inline uint64_t CAVM_MDABX_IPB_PFRANGE_MIN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_IPB_PFRANGE_MIN(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441002d0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444002d0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_IPB_PFRANGE_MIN", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_IPB_PFRANGE_MIN(a) cavm_mdabx_ipb_pfrange_min_t
#define bustype_CAVM_MDABX_IPB_PFRANGE_MIN(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_IPB_PFRANGE_MIN(a) "MDABX_IPB_PFRANGE_MIN"
#define busnum_CAVM_MDABX_IPB_PFRANGE_MIN(a) (a)
#define arguments_CAVM_MDABX_IPB_PFRANGE_MIN(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_job_ptr_hi#
 *
 * MDAB Job Pointer Upper Bits Register
 * Reports the upper pointer bits of the job in each slot. When a job is received from
 * the PSM, its pointer
 * will always be reflected in one of these two registers until the job completes. The job
 * will not complete until MDAB(0..15)_JOB_STATUS(0..1)
 * bits 0..5 have all been set.
 */
union cavm_mdabx_job_ptr_hix
{
    uint32_t u;
    struct cavm_mdabx_job_ptr_hix_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_21_31        : 11;
        uint32_t job_ptr_hi            : 21; /**< [ 20:  0](RO/H) The JOB_PTR field bits [52:32] from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
#else /* Word 0 - Little Endian */
        uint32_t job_ptr_hi            : 21; /**< [ 20:  0](RO/H) The JOB_PTR field bits [52:32] from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint32_t reserved_21_31        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_job_ptr_hix_s cn; */
};
typedef union cavm_mdabx_job_ptr_hix cavm_mdabx_job_ptr_hix_t;

static inline uint64_t CAVM_MDABX_JOB_PTR_HIX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_JOB_PTR_HIX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044100410ll + 0x4000ll * ((a) & 0x3f) + 0x20ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044400410ll + 0x40000ll * ((a) & 0xf) + 0x20ll * ((b) & 0x1);
    __cavm_csr_fatal("MDABX_JOB_PTR_HIX", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_JOB_PTR_HIX(a,b) cavm_mdabx_job_ptr_hix_t
#define bustype_CAVM_MDABX_JOB_PTR_HIX(a,b) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_JOB_PTR_HIX(a,b) "MDABX_JOB_PTR_HIX"
#define busnum_CAVM_MDABX_JOB_PTR_HIX(a,b) (a)
#define arguments_CAVM_MDABX_JOB_PTR_HIX(a,b) (a),(b),-1,-1

/**
 * Register (RSL32b) mdab#_job_ptr_lo#
 *
 * MDAB Job Pointer Lower Bits Register
 * Reports the lower pointer bits of the job in each slot. When a job is received from
 * the PSM, its pointer
 * will always be reflected in one of these two registers until the job completes. The job
 * will not complete until MDAB(0..15)_JOB_STATUS(0..1)
 * bits 0..5 have all been set.
 */
union cavm_mdabx_job_ptr_lox
{
    uint32_t u;
    struct cavm_mdabx_job_ptr_lox_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t job_ptr_lo            : 32; /**< [ 31:  0](RO/H) The JOB_PTR field bits [31:0] from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
#else /* Word 0 - Little Endian */
        uint32_t job_ptr_lo            : 32; /**< [ 31:  0](RO/H) The JOB_PTR field bits [31:0] from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_job_ptr_lox_s cn; */
};
typedef union cavm_mdabx_job_ptr_lox cavm_mdabx_job_ptr_lox_t;

static inline uint64_t CAVM_MDABX_JOB_PTR_LOX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_JOB_PTR_LOX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044100400ll + 0x4000ll * ((a) & 0x3f) + 0x20ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044400400ll + 0x40000ll * ((a) & 0xf) + 0x20ll * ((b) & 0x1);
    __cavm_csr_fatal("MDABX_JOB_PTR_LOX", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_JOB_PTR_LOX(a,b) cavm_mdabx_job_ptr_lox_t
#define bustype_CAVM_MDABX_JOB_PTR_LOX(a,b) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_JOB_PTR_LOX(a,b) "MDABX_JOB_PTR_LOX"
#define busnum_CAVM_MDABX_JOB_PTR_LOX(a,b) (a)
#define arguments_CAVM_MDABX_JOB_PTR_LOX(a,b) (a),(b),-1,-1

/**
 * Register (RSL32b) mdab#_job_status#
 *
 * MDAB Job Status Register
 * Reports the status for the job in each slot. When a job is received from the PSM, its status
 * will always be reflected in one of these two status registers until the job completes. The job
 * will not complete until
 * bits 0..5 have all been set.
 */
union cavm_mdabx_job_statusx
{
    uint64_t u;
    struct cavm_mdabx_job_statusx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t job_type              : 2;  /**< [ 15: 14](RO/H) The JOB_TYPE field from the PSM command that created the job.
                                                                 The MDBW_JD_HDR_WORD_0_S[DSP_JOB_TYPE] value from the job descriptor, enumerated
                                                                 by MDBW_DSP_JOB_SEL_E.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t reserved_6_13         : 8;
        uint64_t wr_dma_done           : 1;  /**< [  5:  5](RO/H) Set when hardware completes all WR-DMA transfers and all writes have been committed to
                                                                 SMEM or L2C/DDR Memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t rd_dma_done           : 1;  /**< [  4:  4](RO/H) Set when hardware completes all RD-DMA transfers and the data has been committed to local
                                                                 DSP I/D Memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t cfg_dma_done          : 1;  /**< [  3:  3](RO/H) Set when hardware completes all CFG-DMA transfers for the job configuration and the
                                                                 configuration has been committed to local DSP I/D Memory. */
        uint64_t sw_done               : 1;  /**< [  2:  2](R/W1S/H) Software must set this bit to signal when it has finished all processing for a job. */
        uint64_t sw_started            : 1;  /**< [  1:  1](R/W1S/H) Software can set this bit to record when it began processing the job. The time when this
                                                                 bit is set will be used by the job watchdog timer and will be used to determine the job
                                                                 runtime
                                                                 recorded in the job log. */
        uint64_t valid                 : 1;  /**< [  0:  0](RO/H) Set to one when the status reflects a valid job has been received from the PSM. Set to
                                                                 zero
                                                                 when there is no job in the given slot. */
#else /* Word 0 - Little Endian */
        uint64_t valid                 : 1;  /**< [  0:  0](RO/H) Set to one when the status reflects a valid job has been received from the PSM. Set to
                                                                 zero
                                                                 when there is no job in the given slot. */
        uint64_t sw_started            : 1;  /**< [  1:  1](R/W1S/H) Software can set this bit to record when it began processing the job. The time when this
                                                                 bit is set will be used by the job watchdog timer and will be used to determine the job
                                                                 runtime
                                                                 recorded in the job log. */
        uint64_t sw_done               : 1;  /**< [  2:  2](R/W1S/H) Software must set this bit to signal when it has finished all processing for a job. */
        uint64_t cfg_dma_done          : 1;  /**< [  3:  3](RO/H) Set when hardware completes all CFG-DMA transfers for the job configuration and the
                                                                 configuration has been committed to local DSP I/D Memory. */
        uint64_t rd_dma_done           : 1;  /**< [  4:  4](RO/H) Set when hardware completes all RD-DMA transfers and the data has been committed to local
                                                                 DSP I/D Memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t wr_dma_done           : 1;  /**< [  5:  5](RO/H) Set when hardware completes all WR-DMA transfers and all writes have been committed to
                                                                 SMEM or L2C/DDR Memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t reserved_6_13         : 8;
        uint64_t job_type              : 2;  /**< [ 15: 14](RO/H) The JOB_TYPE field from the PSM command that created the job.
                                                                 The MDBW_JD_HDR_WORD_0_S[DSP_JOB_TYPE] value from the job descriptor, enumerated
                                                                 by MDBW_DSP_JOB_SEL_E.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_job_statusx_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t job_type              : 2;  /**< [ 15: 14](RO/H) The JOB_TYPE field from the PSM command that created the job.
                                                                 The MDBW_JD_HDR_WORD_0_S[DSP_JOB_TYPE] value from the job descriptor, enumerated
                                                                 by MDBW_DSP_JOB_SEL_E.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t reserved_6_13         : 8;
        uint64_t wr_dma_done           : 1;  /**< [  5:  5](RO/H) Set when hardware completes all WR-DMA transfers and all writes have been committed to
                                                                 SMEM or L2C/DDR Memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t rd_dma_done           : 1;  /**< [  4:  4](RO/H) Set when hardware completes all RD-DMA transfers and the data has been committed to local
                                                                 DSP I/D Memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t cfg_dma_done          : 1;  /**< [  3:  3](RO/H) Set when hardware completes all CFG-DMA transfers for the job configuration and the
                                                                 configuration has been committed to local DSP I/D Memory. */
        uint64_t sw_done               : 1;  /**< [  2:  2](R/W1S/H) Software must set this bit to signal when it has finished all processing for a job. */
        uint64_t sw_started            : 1;  /**< [  1:  1](R/W1S/H) Software can set this bit to record when it began processing the job. The time when this
                                                                 bit is set will be used by the job watchdog timer and will be used to determine the job
                                                                 runtime
                                                                 recorded in the job log. */
        uint64_t valid                 : 1;  /**< [  0:  0](RO/H) Set to one when the status reflects a valid job has been received from the PSM. Set to
                                                                 zero
                                                                 when there is no job in the given slot. */
#else /* Word 0 - Little Endian */
        uint64_t valid                 : 1;  /**< [  0:  0](RO/H) Set to one when the status reflects a valid job has been received from the PSM. Set to
                                                                 zero
                                                                 when there is no job in the given slot. */
        uint64_t sw_started            : 1;  /**< [  1:  1](R/W1S/H) Software can set this bit to record when it began processing the job. The time when this
                                                                 bit is set will be used by the job watchdog timer and will be used to determine the job
                                                                 runtime
                                                                 recorded in the job log. */
        uint64_t sw_done               : 1;  /**< [  2:  2](R/W1S/H) Software must set this bit to signal when it has finished all processing for a job. */
        uint64_t cfg_dma_done          : 1;  /**< [  3:  3](RO/H) Set when hardware completes all CFG-DMA transfers for the job configuration and the
                                                                 configuration has been committed to local DSP I/D Memory. */
        uint64_t rd_dma_done           : 1;  /**< [  4:  4](RO/H) Set when hardware completes all RD-DMA transfers and the data has been committed to local
                                                                 DSP I/D Memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t wr_dma_done           : 1;  /**< [  5:  5](RO/H) Set when hardware completes all WR-DMA transfers and all writes have been committed to
                                                                 SMEM or L2C/DDR Memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t reserved_6_13         : 8;
        uint64_t job_type              : 2;  /**< [ 15: 14](RO/H) The JOB_TYPE field from the PSM command that created the job.
                                                                 The MDBW_JD_HDR_WORD_0_S[DSP_JOB_TYPE] value from the job descriptor, enumerated
                                                                 by MDBW_DSP_JOB_SEL_E.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_job_statusx_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t job_type              : 2;  /**< [ 15: 14](RO/H) The JOB_TYPE field from the PSM command that created the job.
                                                                 The MDBW_JD_HDR_WORD_0_S[DSP_JOB_TYPE] value from the job descriptor, enumerated
                                                                 by MDBW_DSP_JOB_SEL_E.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t reserved_6_13         : 8;
        uint64_t wr_dma_done           : 1;  /**< [  5:  5](RO/H) Set when hardware completes all write DMA transfers and all writes have been committed to
                                                                 SMEM or LLC/DRAM memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t rd_dma_done           : 1;  /**< [  4:  4](RO/H) Set when hardware completes all read DMA transfers and the data has been committed to
                                                                 DSP local instruction memory and local data memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t cfg_dma_done          : 1;  /**< [  3:  3](RO/H) Set when hardware completes all CFG DMA transfers for the job configuration and the
                                                                 configuration has been committed to DSP local instruction memory and local data memory. */
        uint64_t sw_done               : 1;  /**< [  2:  2](R/W1S/H) Software must set this bit to signal when it has finished all processing for a job. */
        uint64_t sw_started            : 1;  /**< [  1:  1](R/W1S/H) Software can set this bit to record when it began processing the job. The time when this
                                                                 bit is set will be used by the job watchdog timer and will be used to determine the job
                                                                 runtime
                                                                 recorded in the job log. */
        uint64_t valid                 : 1;  /**< [  0:  0](RO/H) Set to one when the status reflects a valid job has been received from the PSM. Set to
                                                                 zero
                                                                 when there is no job in the given slot. */
#else /* Word 0 - Little Endian */
        uint64_t valid                 : 1;  /**< [  0:  0](RO/H) Set to one when the status reflects a valid job has been received from the PSM. Set to
                                                                 zero
                                                                 when there is no job in the given slot. */
        uint64_t sw_started            : 1;  /**< [  1:  1](R/W1S/H) Software can set this bit to record when it began processing the job. The time when this
                                                                 bit is set will be used by the job watchdog timer and will be used to determine the job
                                                                 runtime
                                                                 recorded in the job log. */
        uint64_t sw_done               : 1;  /**< [  2:  2](R/W1S/H) Software must set this bit to signal when it has finished all processing for a job. */
        uint64_t cfg_dma_done          : 1;  /**< [  3:  3](RO/H) Set when hardware completes all CFG DMA transfers for the job configuration and the
                                                                 configuration has been committed to DSP local instruction memory and local data memory. */
        uint64_t rd_dma_done           : 1;  /**< [  4:  4](RO/H) Set when hardware completes all read DMA transfers and the data has been committed to
                                                                 DSP local instruction memory and local data memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t wr_dma_done           : 1;  /**< [  5:  5](RO/H) Set when hardware completes all write DMA transfers and all writes have been committed to
                                                                 SMEM or LLC/DRAM memory.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t reserved_6_13         : 8;
        uint64_t job_type              : 2;  /**< [ 15: 14](RO/H) The JOB_TYPE field from the PSM command that created the job.
                                                                 The MDBW_JD_HDR_WORD_0_S[DSP_JOB_TYPE] value from the job descriptor, enumerated
                                                                 by MDBW_DSP_JOB_SEL_E.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command that created the job.
                                                                 Since MDAB hardware updates this register, its contents are unpredictable in software. */
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_job_statusx cavm_mdabx_job_statusx_t;

static inline uint64_t CAVM_MDABX_JOB_STATUSX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_JOB_STATUSX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044100000ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044400000ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDABX_JOB_STATUSX", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_JOB_STATUSX(a,b) cavm_mdabx_job_statusx_t
#define bustype_CAVM_MDABX_JOB_STATUSX(a,b) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_JOB_STATUSX(a,b) "MDABX_JOB_STATUSX"
#define busnum_CAVM_MDABX_JOB_STATUSX(a,b) (a)
#define arguments_CAVM_MDABX_JOB_STATUSX(a,b) (a),(b),-1,-1

/**
 * Register (RSL32b) mdab#_job_status1#
 *
 * MDAB Job Status1 Register
 * Additional job status information for software.
 */
union cavm_mdabx_job_status1x
{
    uint64_t u;
    struct cavm_mdabx_job_status1x_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t cfg_cnt               : 9;  /**< [  8:  0](RO/H) Contains the total CFG-DMA transfer count in 128B chunks. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_cnt               : 9;  /**< [  8:  0](RO/H) Contains the total CFG-DMA transfer count in 128B chunks. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_job_status1x_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_31         : 23;
        uint64_t cfg_cnt               : 9;  /**< [  8:  0](RO/H) Contains the total CFG-DMA transfer count in 128B chunks. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_cnt               : 9;  /**< [  8:  0](RO/H) Contains the total CFG-DMA transfer count in 128B chunks. */
        uint64_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_job_status1x cavm_mdabx_job_status1x_t;

static inline uint64_t CAVM_MDABX_JOB_STATUS1X(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_JOB_STATUS1X(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e0441000e0ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e0444000e0ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDABX_JOB_STATUS1X", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_JOB_STATUS1X(a,b) cavm_mdabx_job_status1x_t
#define bustype_CAVM_MDABX_JOB_STATUS1X(a,b) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_JOB_STATUS1X(a,b) "MDABX_JOB_STATUS1X"
#define busnum_CAVM_MDABX_JOB_STATUS1X(a,b) (a)
#define arguments_CAVM_MDABX_JOB_STATUS1X(a,b) (a),(b),-1,-1

/**
 * Register (RSL32b) mdab#_ld_int_ena_w1c
 *
 * MDAB Load Local Interrupt Enable Clear Register
 * This is the INT_ENA clear register for the load local start and done interrupts.
 */
union cavm_mdabx_ld_int_ena_w1c
{
    uint64_t u;
    struct cavm_mdabx_ld_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1C/H) Writing a 1 to this bit disables the load local done interrupt. */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1C/H) Writing a 1 to this bit disables the load local start interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1C/H) Writing a 1 to this bit disables the load local start interrupt. */
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1C/H) Writing a 1 to this bit disables the load local done interrupt. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_ld_int_ena_w1c_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_31         : 30;
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1C/H) Writing a 1 to this bit disables the load local done interrupt. */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1C/H) Writing a 1 to this bit disables the load local start interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1C/H) Writing a 1 to this bit disables the load local start interrupt. */
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1C/H) Writing a 1 to this bit disables the load local done interrupt. */
        uint64_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_ld_int_ena_w1c cavm_mdabx_ld_int_ena_w1c_t;

static inline uint64_t CAVM_MDABX_LD_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_LD_INT_ENA_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100240ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400240ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_LD_INT_ENA_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_LD_INT_ENA_W1C(a) cavm_mdabx_ld_int_ena_w1c_t
#define bustype_CAVM_MDABX_LD_INT_ENA_W1C(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_LD_INT_ENA_W1C(a) "MDABX_LD_INT_ENA_W1C"
#define busnum_CAVM_MDABX_LD_INT_ENA_W1C(a) (a)
#define arguments_CAVM_MDABX_LD_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ld_int_ena_w1s
 *
 * MDAB Load Local Interrupt Enable Set Register
 * This is the INT_ENA set register for the load local start and done interrupts.
 */
union cavm_mdabx_ld_int_ena_w1s
{
    uint64_t u;
    struct cavm_mdabx_ld_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1S/H) Writing a 1 to this bit enables the load local done interrupt. */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1S/H) Writing a 1 to this bit enables the load local start interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1S/H) Writing a 1 to this bit enables the load local start interrupt. */
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1S/H) Writing a 1 to this bit enables the load local done interrupt. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_ld_int_ena_w1s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_31         : 30;
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1S/H) Writing a 1 to this bit enables the load local done interrupt. */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1S/H) Writing a 1 to this bit enables the load local start interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1S/H) Writing a 1 to this bit enables the load local start interrupt. */
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1S/H) Writing a 1 to this bit enables the load local done interrupt. */
        uint64_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_ld_int_ena_w1s cavm_mdabx_ld_int_ena_w1s_t;

static inline uint64_t CAVM_MDABX_LD_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_LD_INT_ENA_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100250ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400250ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_LD_INT_ENA_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_LD_INT_ENA_W1S(a) cavm_mdabx_ld_int_ena_w1s_t
#define bustype_CAVM_MDABX_LD_INT_ENA_W1S(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_LD_INT_ENA_W1S(a) "MDABX_LD_INT_ENA_W1S"
#define busnum_CAVM_MDABX_LD_INT_ENA_W1S(a) (a)
#define arguments_CAVM_MDABX_LD_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ld_int_sum_w1c
 *
 * MDAB Load Local Interrrupt Summary Clear Register
 * This is the INT_SUM clear register for the load local start and done interrupts.
 */
union cavm_mdabx_ld_int_sum_w1c
{
    uint64_t u;
    struct cavm_mdabx_ld_int_sum_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1C/H) Writing a 1 to this bit clears the INT_SUM bit for the load local done interrupt. */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1C/H) Writing a 1 to this bit clears the INT_SUM bit for the load local start interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1C/H) Writing a 1 to this bit clears the INT_SUM bit for the load local start interrupt. */
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1C/H) Writing a 1 to this bit clears the INT_SUM bit for the load local done interrupt. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_ld_int_sum_w1c_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_31         : 30;
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1C/H) Writing a 1 to this bit clears the INT_SUM bit for the load local done interrupt. */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1C/H) Writing a 1 to this bit clears the INT_SUM bit for the load local start interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1C/H) Writing a 1 to this bit clears the INT_SUM bit for the load local start interrupt. */
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1C/H) Writing a 1 to this bit clears the INT_SUM bit for the load local done interrupt. */
        uint64_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_ld_int_sum_w1c cavm_mdabx_ld_int_sum_w1c_t;

static inline uint64_t CAVM_MDABX_LD_INT_SUM_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_LD_INT_SUM_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100220ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400220ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_LD_INT_SUM_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_LD_INT_SUM_W1C(a) cavm_mdabx_ld_int_sum_w1c_t
#define bustype_CAVM_MDABX_LD_INT_SUM_W1C(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_LD_INT_SUM_W1C(a) "MDABX_LD_INT_SUM_W1C"
#define busnum_CAVM_MDABX_LD_INT_SUM_W1C(a) (a)
#define arguments_CAVM_MDABX_LD_INT_SUM_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_ld_int_sum_w1s
 *
 * MDAB Load Local Interrupt Summary Set Register
 * This is the INT_SUM set register for the load local start and done interrupts.
 */
union cavm_mdabx_ld_int_sum_w1s
{
    uint64_t u;
    struct cavm_mdabx_ld_int_sum_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1S/H) This bit is set by the read DMA load local logic when a load_local_without_reset slice
                                                                 completes.  Writing a 1 to this bit sets the INT_SUM bit for the load local done
                                                                 interrupt.
                                                                 This allows software to generate the interrupt if the corresponding enable bit is set. */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1S/H) This bit is set by the read DMA load local logic when a load_local_without_reset slice
                                                                 operation
                                                                 starts.  Writing a 1 to this bit sets the INT_SUM bit for the load local start interrupt.
                                                                 This allows software to generate the interrupt if the corresponding enable bit is set. */
#else /* Word 0 - Little Endian */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1S/H) This bit is set by the read DMA load local logic when a load_local_without_reset slice
                                                                 operation
                                                                 starts.  Writing a 1 to this bit sets the INT_SUM bit for the load local start interrupt.
                                                                 This allows software to generate the interrupt if the corresponding enable bit is set. */
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1S/H) This bit is set by the read DMA load local logic when a load_local_without_reset slice
                                                                 completes.  Writing a 1 to this bit sets the INT_SUM bit for the load local done
                                                                 interrupt.
                                                                 This allows software to generate the interrupt if the corresponding enable bit is set. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_ld_int_sum_w1s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_31         : 30;
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1S/H) This bit is set by the read DMA load local logic when a load_local_without_reset slice
                                                                 completes.  Writing a 1 to this bit sets the INT_SUM bit for the load local done
                                                                 interrupt.
                                                                 This allows software to generate the interrupt if the corresponding enable bit is set. */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1S/H) This bit is set by the read DMA load local logic when a load_local_without_reset slice
                                                                 operation
                                                                 starts.  Writing a 1 to this bit sets the INT_SUM bit for the load local start interrupt.
                                                                 This allows software to generate the interrupt if the corresponding enable bit is set. */
#else /* Word 0 - Little Endian */
        uint64_t ld_lcl_start_int      : 1;  /**< [  0:  0](R/W1S/H) This bit is set by the read DMA load local logic when a load_local_without_reset slice
                                                                 operation
                                                                 starts.  Writing a 1 to this bit sets the INT_SUM bit for the load local start interrupt.
                                                                 This allows software to generate the interrupt if the corresponding enable bit is set. */
        uint64_t ld_lcl_done_int       : 1;  /**< [  1:  1](R/W1S/H) This bit is set by the read DMA load local logic when a load_local_without_reset slice
                                                                 completes.  Writing a 1 to this bit sets the INT_SUM bit for the load local done
                                                                 interrupt.
                                                                 This allows software to generate the interrupt if the corresponding enable bit is set. */
        uint64_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_ld_int_sum_w1s cavm_mdabx_ld_int_sum_w1s_t;

static inline uint64_t CAVM_MDABX_LD_INT_SUM_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_LD_INT_SUM_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100230ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400230ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_LD_INT_SUM_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_LD_INT_SUM_W1S(a) cavm_mdabx_ld_int_sum_w1s_t
#define bustype_CAVM_MDABX_LD_INT_SUM_W1S(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_LD_INT_SUM_W1S(a) "MDABX_LD_INT_SUM_W1S"
#define busnum_CAVM_MDABX_LD_INT_SUM_W1S(a) (a)
#define arguments_CAVM_MDABX_LD_INT_SUM_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_pfault_info
 *
 * MDAB Processor Debug Register
 * This register contains the status of the PFaultInfo bus.
 */
union cavm_mdabx_pfault_info
{
    uint32_t u;
    struct cavm_mdabx_pfault_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t pfaultinfo            : 32; /**< [ 31:  0](RO/H) Fault Informational Signal (mirrors the internal Fault Information Register).
                                                                 Every time the DSP indicates a PFaultInfoValid strobe, the PFaultInfo[31:0] bus is
                                                                 captured to this register. */
#else /* Word 0 - Little Endian */
        uint32_t pfaultinfo            : 32; /**< [ 31:  0](RO/H) Fault Informational Signal (mirrors the internal Fault Information Register).
                                                                 Every time the DSP indicates a PFaultInfoValid strobe, the PFaultInfo[31:0] bus is
                                                                 captured to this register. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_pfault_info_s cn; */
};
typedef union cavm_mdabx_pfault_info cavm_mdabx_pfault_info_t;

static inline uint64_t CAVM_MDABX_PFAULT_INFO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PFAULT_INFO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441001d0ll + 0x4000ll * ((a) & 0x3f);
    __cavm_csr_fatal("MDABX_PFAULT_INFO", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PFAULT_INFO(a) cavm_mdabx_pfault_info_t
#define bustype_CAVM_MDABX_PFAULT_INFO(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PFAULT_INFO(a) "MDABX_PFAULT_INFO"
#define busnum_CAVM_MDABX_PFAULT_INFO(a) (a)
#define arguments_CAVM_MDABX_PFAULT_INFO(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_pfio_ctl
 *
 * MDAB PFIO Control Register
 * PFI and PFO control register
 */
union cavm_mdabx_pfio_ctl
{
    uint64_t u;
    struct cavm_mdabx_pfio_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t pfo_rd_dswap          : 3;  /**< [  9:  7](R/W) Determines the swap data field on PFO read requests to system memory (not SMEM).
                                                                 0: no swapping.
                                                                 1: byte swapping (0x0123456789abcdef -\> 0xefcdab8967452301).
                                                                 2: 16-bit swapping (0x0123456789abcdef -\> 0xcdef89ab45670123).
                                                                 3: 32-bit swapping (0x0123456789abcdef -\> 0x89abcdef01234567).
                                                                 4-7: Reserved. */
        uint64_t pfo_wr_dswap          : 3;  /**< [  6:  4](R/W) Determines the swap data field on PFO write requests to system memory (not SMEM).
                                                                 0: no swapping.
                                                                 1: byte swapping (0x0123456789abcdef -\> 0xefcdab8967452301).
                                                                 2: 16-bit swapping (0x0123456789abcdef -\> 0xcdef89ab45670123).
                                                                 3: 32-bit swapping (0x0123456789abcdef -\> 0x89abcdef01234567).
                                                                 4-7: Reserved. */
        uint64_t pfo_rsp_arbmode       : 1;  /**< [  3:  3](R/W) Determines the PFO-RSP arbitration policy for the several
                                                                 different RSP types which can be serviced/returned to the DSP core ?out of order?.
                                                                 When set to one, the PFO-RSP arbitration will be round robin amongst the several
                                                                 pending PFO-RSP types = {WR-RSP, RD-RSP, ILL-RSP}.  When set to zero, the PFO-RSP
                                                                 arbitration uses a two stage arbitration where The first stage uses round robin
                                                                 amongst the pending WR-RSPs and RD-RSPs.  The 2nd stage uses fixed priority, with
                                                                 ILL-RSPs(illegal responses) having higher Priority over the RD|WR-RSPs.
                                                                 NOTE: ILL-RSP = ?Illegal responses? and include:
                                                                 1)      For non-existent memory (NXM): DSP will receive RSP=AErrL
                                                                 2)      For Illegal Command (ILL-CMD): DSP will receive RSP=ADErrL */
        uint64_t req_priority          : 2;  /**< [  2:  1](R/W) Programmable control of the PFI-REQ Priority field for incoming requests. */
        uint64_t pfi_req_arbmode       : 1;  /**< [  0:  0](R/W) Determines the PFI-REQ arbitration policy for the several different inbound PIF request
                                                                 types which are serviced/returned by the DSP in strict order.
                                                                 When set to one, the PFO-REQ arbitration will be round robin amongst the several
                                                                 pending PFI-REQ types = {CSR(I/D MEM), CFG-DMA, RD-DMA, WR-DMA}.
                                                                 When set to zero, the PFI-REQ arbitration uses a fixed priority arbitration scheme:
                                                                 {CSR(I/D MEM)=LP, CFG-DMA, RD-DMA, WR-DMA=HP}. */
#else /* Word 0 - Little Endian */
        uint64_t pfi_req_arbmode       : 1;  /**< [  0:  0](R/W) Determines the PFI-REQ arbitration policy for the several different inbound PIF request
                                                                 types which are serviced/returned by the DSP in strict order.
                                                                 When set to one, the PFO-REQ arbitration will be round robin amongst the several
                                                                 pending PFI-REQ types = {CSR(I/D MEM), CFG-DMA, RD-DMA, WR-DMA}.
                                                                 When set to zero, the PFI-REQ arbitration uses a fixed priority arbitration scheme:
                                                                 {CSR(I/D MEM)=LP, CFG-DMA, RD-DMA, WR-DMA=HP}. */
        uint64_t req_priority          : 2;  /**< [  2:  1](R/W) Programmable control of the PFI-REQ Priority field for incoming requests. */
        uint64_t pfo_rsp_arbmode       : 1;  /**< [  3:  3](R/W) Determines the PFO-RSP arbitration policy for the several
                                                                 different RSP types which can be serviced/returned to the DSP core ?out of order?.
                                                                 When set to one, the PFO-RSP arbitration will be round robin amongst the several
                                                                 pending PFO-RSP types = {WR-RSP, RD-RSP, ILL-RSP}.  When set to zero, the PFO-RSP
                                                                 arbitration uses a two stage arbitration where The first stage uses round robin
                                                                 amongst the pending WR-RSPs and RD-RSPs.  The 2nd stage uses fixed priority, with
                                                                 ILL-RSPs(illegal responses) having higher Priority over the RD|WR-RSPs.
                                                                 NOTE: ILL-RSP = ?Illegal responses? and include:
                                                                 1)      For non-existent memory (NXM): DSP will receive RSP=AErrL
                                                                 2)      For Illegal Command (ILL-CMD): DSP will receive RSP=ADErrL */
        uint64_t pfo_wr_dswap          : 3;  /**< [  6:  4](R/W) Determines the swap data field on PFO write requests to system memory (not SMEM).
                                                                 0: no swapping.
                                                                 1: byte swapping (0x0123456789abcdef -\> 0xefcdab8967452301).
                                                                 2: 16-bit swapping (0x0123456789abcdef -\> 0xcdef89ab45670123).
                                                                 3: 32-bit swapping (0x0123456789abcdef -\> 0x89abcdef01234567).
                                                                 4-7: Reserved. */
        uint64_t pfo_rd_dswap          : 3;  /**< [  9:  7](R/W) Determines the swap data field on PFO read requests to system memory (not SMEM).
                                                                 0: no swapping.
                                                                 1: byte swapping (0x0123456789abcdef -\> 0xefcdab8967452301).
                                                                 2: 16-bit swapping (0x0123456789abcdef -\> 0xcdef89ab45670123).
                                                                 3: 32-bit swapping (0x0123456789abcdef -\> 0x89abcdef01234567).
                                                                 4-7: Reserved. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_pfio_ctl_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_31        : 22;
        uint64_t pfo_rd_dswap          : 3;  /**< [  9:  7](R/W) Determines the swap data field on PFO read requests to system memory (not SMEM).
                                                                 0: no swapping.
                                                                 1: byte swapping (0x0123456789abcdef -\> 0xefcdab8967452301).
                                                                 2: 16-bit swapping (0x0123456789abcdef -\> 0xcdef89ab45670123).
                                                                 3: 32-bit swapping (0x0123456789abcdef -\> 0x89abcdef01234567).
                                                                 4-7: Reserved. */
        uint64_t pfo_wr_dswap          : 3;  /**< [  6:  4](R/W) Determines the swap data field on PFO write requests to system memory (not SMEM).
                                                                 0: no swapping.
                                                                 1: byte swapping (0x0123456789abcdef -\> 0xefcdab8967452301).
                                                                 2: 16-bit swapping (0x0123456789abcdef -\> 0xcdef89ab45670123).
                                                                 3: 32-bit swapping (0x0123456789abcdef -\> 0x89abcdef01234567).
                                                                 4-7: Reserved. */
        uint64_t pfo_rsp_arbmode       : 1;  /**< [  3:  3](R/W) Determines the PFO-RSP arbitration policy for the several
                                                                 different RSP types which can be serviced/returned to the DSP core ?out of order?.
                                                                 When set to one, the PFO-RSP arbitration will be round robin amongst the several
                                                                 pending PFO-RSP types = {WR-RSP, RD-RSP, ILL-RSP}.  When set to zero, the PFO-RSP
                                                                 arbitration uses a two stage arbitration where The first stage uses round robin
                                                                 amongst the pending WR-RSPs and RD-RSPs.  The 2nd stage uses fixed priority, with
                                                                 ILL-RSPs(illegal responses) having higher Priority over the RD|WR-RSPs.
                                                                 NOTE: ILL-RSP = ?Illegal responses? and include:
                                                                 1)      For non-existent memory (NXM): DSP will receive RSP=AErrL
                                                                 2)      For Illegal Command (ILL-CMD): DSP will receive RSP=ADErrL */
        uint64_t req_priority          : 2;  /**< [  2:  1](R/W) Programmable control of the PFI-REQ Priority field for incoming requests. */
        uint64_t pfi_req_arbmode       : 1;  /**< [  0:  0](R/W) Determines the PFI-REQ arbitration policy for the several different inbound PIF request
                                                                 types which are serviced/returned by the DSP in strict order.
                                                                 When set to one, the PFO-REQ arbitration will be round robin amongst the several
                                                                 pending PFI-REQ types = {CSR(I/D MEM), CFG-DMA, RD-DMA, WR-DMA}.
                                                                 When set to zero, the PFI-REQ arbitration uses a fixed priority arbitration scheme:
                                                                 {CSR(I/D MEM)=LP, CFG-DMA, RD-DMA, WR-DMA=HP}. */
#else /* Word 0 - Little Endian */
        uint64_t pfi_req_arbmode       : 1;  /**< [  0:  0](R/W) Determines the PFI-REQ arbitration policy for the several different inbound PIF request
                                                                 types which are serviced/returned by the DSP in strict order.
                                                                 When set to one, the PFO-REQ arbitration will be round robin amongst the several
                                                                 pending PFI-REQ types = {CSR(I/D MEM), CFG-DMA, RD-DMA, WR-DMA}.
                                                                 When set to zero, the PFI-REQ arbitration uses a fixed priority arbitration scheme:
                                                                 {CSR(I/D MEM)=LP, CFG-DMA, RD-DMA, WR-DMA=HP}. */
        uint64_t req_priority          : 2;  /**< [  2:  1](R/W) Programmable control of the PFI-REQ Priority field for incoming requests. */
        uint64_t pfo_rsp_arbmode       : 1;  /**< [  3:  3](R/W) Determines the PFO-RSP arbitration policy for the several
                                                                 different RSP types which can be serviced/returned to the DSP core ?out of order?.
                                                                 When set to one, the PFO-RSP arbitration will be round robin amongst the several
                                                                 pending PFO-RSP types = {WR-RSP, RD-RSP, ILL-RSP}.  When set to zero, the PFO-RSP
                                                                 arbitration uses a two stage arbitration where The first stage uses round robin
                                                                 amongst the pending WR-RSPs and RD-RSPs.  The 2nd stage uses fixed priority, with
                                                                 ILL-RSPs(illegal responses) having higher Priority over the RD|WR-RSPs.
                                                                 NOTE: ILL-RSP = ?Illegal responses? and include:
                                                                 1)      For non-existent memory (NXM): DSP will receive RSP=AErrL
                                                                 2)      For Illegal Command (ILL-CMD): DSP will receive RSP=ADErrL */
        uint64_t pfo_wr_dswap          : 3;  /**< [  6:  4](R/W) Determines the swap data field on PFO write requests to system memory (not SMEM).
                                                                 0: no swapping.
                                                                 1: byte swapping (0x0123456789abcdef -\> 0xefcdab8967452301).
                                                                 2: 16-bit swapping (0x0123456789abcdef -\> 0xcdef89ab45670123).
                                                                 3: 32-bit swapping (0x0123456789abcdef -\> 0x89abcdef01234567).
                                                                 4-7: Reserved. */
        uint64_t pfo_rd_dswap          : 3;  /**< [  9:  7](R/W) Determines the swap data field on PFO read requests to system memory (not SMEM).
                                                                 0: no swapping.
                                                                 1: byte swapping (0x0123456789abcdef -\> 0xefcdab8967452301).
                                                                 2: 16-bit swapping (0x0123456789abcdef -\> 0xcdef89ab45670123).
                                                                 3: 32-bit swapping (0x0123456789abcdef -\> 0x89abcdef01234567).
                                                                 4-7: Reserved. */
        uint64_t reserved_10_31        : 22;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_pfio_ctl cavm_mdabx_pfio_ctl_t;

static inline uint64_t CAVM_MDABX_PFIO_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PFIO_CTL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100330ll + 0x4000ll * ((a) & 0x3f);
    __cavm_csr_fatal("MDABX_PFIO_CTL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PFIO_CTL(a) cavm_mdabx_pfio_ctl_t
#define bustype_CAVM_MDABX_PFIO_CTL(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PFIO_CTL(a) "MDABX_PFIO_CTL"
#define busnum_CAVM_MDABX_PFIO_CTL(a) (a)
#define arguments_CAVM_MDABX_PFIO_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_proc_ctl
 *
 * MDAB Processor Mode Control Register
 * This register contains controls for certain DSP operating modes.
 */
union cavm_mdabx_proc_ctl
{
    uint64_t u;
    struct cavm_mdabx_proc_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t rcv_core              : 1;  /**< [ 31: 31](R/W) When this bit is set, a DSP core which is low power state (deep sleep or Light
                                                                 Sleep) would wake up and move to run state. */
        uint64_t deep_slp_req          : 1;  /**< [ 30: 30](R/W) An assertion of this bit, in a case where a DSP core is in light sleep would
                                                                 cause transition to Stand By (deep sleep). */
        uint64_t boot                  : 1;  /**< [ 29: 29](R/W) When this bit is set, upon DSP exit Global Reset, the DSP would start booting
                                                                 from an address which is set by MDAB(0..15)_INT_VEC_ADDR. */
        uint64_t powersave_stall_en    : 1;  /**< [ 28: 28](R/W) This bit enables the RUNSTALL powersaving mode. If set, the RUNSTALL signal is toggled
                                                                 according to the POWERSAVE_ON_CNT and POWERSAVE_OFF_CNT registers. The RUNSTALL
                                                                 signal is toggled high for the number of clocks provided by POWERSAVE_ON_CNT+1. Likewise
                                                                 the RUNSTALL is toggled low for the number of clocks provided by POWERSAVE_OFF_CNT+1.
                                                                 Minimum valid count values are 15. */
        uint64_t powersave_off_cnt     : 10; /**< [ 27: 18](R/W) This register provides the off (low) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven low for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t powersave_on_cnt      : 10; /**< [ 17:  8](R/W) This register provides the on (high) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven high for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t cya_ld_lcl_rst_rs_clr : 1;  /**< [  7:  7](R/W) This register contains backdoor cleanup state.
                                                                 Internal:
                                                                 When performing a load local with reset operation, If this bit is set
                                                                 it will override the logic that holds reset and run_stall active until the slice with
                                                                 last == 1 is completed.  This will result in reset and run_stall being deasserted after
                                                                 each slice of a multislice ld_lcl_wrst operation. */
        uint64_t stlcl_stall           : 1;  /**< [  6:  6](R/W) Local stall bit.  During a ST_LCL transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input. */
        uint64_t ldlcl_stall           : 1;  /**< [  5:  5](R/W) Local stall bit.  During a LD_LCL (without reset) transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input.
                                                                 NOTE: */
        uint64_t breset                : 1;  /**< [  4:  4](R/W/H) When software sets this bit the entire DSP will be forced in the reset state. When the
                                                                 software clears this bit, the DSP will come out of reset and start execution at the reset
                                                                 interrupt vector (if run_stall is not asserted).  This bit is cleared at the start of
                                                                 a load local with reset operation so that the DSP reset input can be correctly controlled
                                                                 by the load local with reset logic. */
        uint64_t reserved_3            : 1;
        uint64_t dreset                : 1;  /**< [  2:  2](R/W) Setting this bit asserts reset to the DSP debug logic. */
        uint64_t stat_vector_sel       : 1;  /**< [  1:  1](R/W) Setting this bit selects the alternative stationary vector base address. */
        uint64_t run_stall             : 1;  /**< [  0:  0](R/W/H) When this bit is SET the DSP's RUN_STALL input will be asserted, forcing the DSP to
                                                                 "stall" until the bit is cleared.  This bit is cleared at the start of a load local
                                                                 with reset operation to enable the load local logic to control the DSP RunStall input.
                                                                 At the end of the load local with reset operation when the last block of instruction/
                                                                 data has been loaded into the DSP memory, the DSP RunStall input will be deasserted
                                                                 so the DSP can start running. */
#else /* Word 0 - Little Endian */
        uint64_t run_stall             : 1;  /**< [  0:  0](R/W/H) When this bit is SET the DSP's RUN_STALL input will be asserted, forcing the DSP to
                                                                 "stall" until the bit is cleared.  This bit is cleared at the start of a load local
                                                                 with reset operation to enable the load local logic to control the DSP RunStall input.
                                                                 At the end of the load local with reset operation when the last block of instruction/
                                                                 data has been loaded into the DSP memory, the DSP RunStall input will be deasserted
                                                                 so the DSP can start running. */
        uint64_t stat_vector_sel       : 1;  /**< [  1:  1](R/W) Setting this bit selects the alternative stationary vector base address. */
        uint64_t dreset                : 1;  /**< [  2:  2](R/W) Setting this bit asserts reset to the DSP debug logic. */
        uint64_t reserved_3            : 1;
        uint64_t breset                : 1;  /**< [  4:  4](R/W/H) When software sets this bit the entire DSP will be forced in the reset state. When the
                                                                 software clears this bit, the DSP will come out of reset and start execution at the reset
                                                                 interrupt vector (if run_stall is not asserted).  This bit is cleared at the start of
                                                                 a load local with reset operation so that the DSP reset input can be correctly controlled
                                                                 by the load local with reset logic. */
        uint64_t ldlcl_stall           : 1;  /**< [  5:  5](R/W) Local stall bit.  During a LD_LCL (without reset) transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input.
                                                                 NOTE: */
        uint64_t stlcl_stall           : 1;  /**< [  6:  6](R/W) Local stall bit.  During a ST_LCL transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input. */
        uint64_t cya_ld_lcl_rst_rs_clr : 1;  /**< [  7:  7](R/W) This register contains backdoor cleanup state.
                                                                 Internal:
                                                                 When performing a load local with reset operation, If this bit is set
                                                                 it will override the logic that holds reset and run_stall active until the slice with
                                                                 last == 1 is completed.  This will result in reset and run_stall being deasserted after
                                                                 each slice of a multislice ld_lcl_wrst operation. */
        uint64_t powersave_on_cnt      : 10; /**< [ 17:  8](R/W) This register provides the on (high) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven high for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t powersave_off_cnt     : 10; /**< [ 27: 18](R/W) This register provides the off (low) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven low for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t powersave_stall_en    : 1;  /**< [ 28: 28](R/W) This bit enables the RUNSTALL powersaving mode. If set, the RUNSTALL signal is toggled
                                                                 according to the POWERSAVE_ON_CNT and POWERSAVE_OFF_CNT registers. The RUNSTALL
                                                                 signal is toggled high for the number of clocks provided by POWERSAVE_ON_CNT+1. Likewise
                                                                 the RUNSTALL is toggled low for the number of clocks provided by POWERSAVE_OFF_CNT+1.
                                                                 Minimum valid count values are 15. */
        uint64_t boot                  : 1;  /**< [ 29: 29](R/W) When this bit is set, upon DSP exit Global Reset, the DSP would start booting
                                                                 from an address which is set by MDAB(0..15)_INT_VEC_ADDR. */
        uint64_t deep_slp_req          : 1;  /**< [ 30: 30](R/W) An assertion of this bit, in a case where a DSP core is in light sleep would
                                                                 cause transition to Stand By (deep sleep). */
        uint64_t rcv_core              : 1;  /**< [ 31: 31](R/W) When this bit is set, a DSP core which is low power state (deep sleep or Light
                                                                 Sleep) would wake up and move to run state. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_proc_ctl_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_31        : 3;
        uint64_t powersave_stall_en    : 1;  /**< [ 28: 28](R/W) This bit enables the RUNSTALL powersaving mode. If set, the RUNSTALL signal is toggled
                                                                 according to the POWERSAVE_ON_CNT and POWERSAVE_OFF_CNT registers. The RUNSTALL
                                                                 signal is toggled high for the number of clocks provided by POWERSAVE_ON_CNT+1. Likewise
                                                                 the RUNSTALL is toggled low for the number of clocks provided by POWERSAVE_OFF_CNT+1.
                                                                 Minimum valid count values are 15. */
        uint64_t powersave_off_cnt     : 10; /**< [ 27: 18](R/W) This register provides the off (low) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven low for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t powersave_on_cnt      : 10; /**< [ 17:  8](R/W) This register provides the on (high) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven high for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t cya_ld_lcl_rst_rs_clr : 1;  /**< [  7:  7](R/W) This register contains backdoor cleanup state.
                                                                 Internal:
                                                                 When performing a load local with reset operation, If this bit is set
                                                                 it will override the logic that holds reset and run_stall active until the slice with
                                                                 last == 1 is completed.  This will result in reset and run_stall being deasserted after
                                                                 each slice of a multislice ld_lcl_wrst operation. */
        uint64_t stlcl_stall           : 1;  /**< [  6:  6](R/W) Local stall bit.  During a ST_LCL transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input. */
        uint64_t ldlcl_stall           : 1;  /**< [  5:  5](R/W) Local stall bit.  During a LD_LCL (without reset) transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input.
                                                                 NOTE: */
        uint64_t breset                : 1;  /**< [  4:  4](R/W/H) When software sets this bit the entire DSP will be forced in the reset state. When the
                                                                 software clears this bit, the DSP will come out of reset and start execution at the reset
                                                                 interrupt vector (if run_stall is not asserted).  This bit is cleared at the start of
                                                                 a load local with reset operation so that the DSP reset input can be correctly controlled
                                                                 by the load local with reset logic. */
        uint64_t ocd_halt_on_reset     : 1;  /**< [  3:  3](R/W) Force the DSP to enter OCDHaltMode after reset. */
        uint64_t dreset                : 1;  /**< [  2:  2](R/W) Setting this bit asserts reset to the DSP debug logic. */
        uint64_t stat_vector_sel       : 1;  /**< [  1:  1](R/W) Setting this bit selects the alternative stationary vector base address. */
        uint64_t run_stall             : 1;  /**< [  0:  0](R/W/H) When this bit is SET the DSP's RUN_STALL input will be asserted, forcing the DSP to
                                                                 "stall" until the bit is cleared.  This bit is cleared at the start of a load local
                                                                 with reset operation to enable the load local logic to control the DSP RunStall input.
                                                                 At the end of the load local with reset operation when the last block of instruction/
                                                                 data has been loaded into the DSP memory, the DSP RunStall input will be deasserted
                                                                 so the DSP can start running. */
#else /* Word 0 - Little Endian */
        uint64_t run_stall             : 1;  /**< [  0:  0](R/W/H) When this bit is SET the DSP's RUN_STALL input will be asserted, forcing the DSP to
                                                                 "stall" until the bit is cleared.  This bit is cleared at the start of a load local
                                                                 with reset operation to enable the load local logic to control the DSP RunStall input.
                                                                 At the end of the load local with reset operation when the last block of instruction/
                                                                 data has been loaded into the DSP memory, the DSP RunStall input will be deasserted
                                                                 so the DSP can start running. */
        uint64_t stat_vector_sel       : 1;  /**< [  1:  1](R/W) Setting this bit selects the alternative stationary vector base address. */
        uint64_t dreset                : 1;  /**< [  2:  2](R/W) Setting this bit asserts reset to the DSP debug logic. */
        uint64_t ocd_halt_on_reset     : 1;  /**< [  3:  3](R/W) Force the DSP to enter OCDHaltMode after reset. */
        uint64_t breset                : 1;  /**< [  4:  4](R/W/H) When software sets this bit the entire DSP will be forced in the reset state. When the
                                                                 software clears this bit, the DSP will come out of reset and start execution at the reset
                                                                 interrupt vector (if run_stall is not asserted).  This bit is cleared at the start of
                                                                 a load local with reset operation so that the DSP reset input can be correctly controlled
                                                                 by the load local with reset logic. */
        uint64_t ldlcl_stall           : 1;  /**< [  5:  5](R/W) Local stall bit.  During a LD_LCL (without reset) transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input.
                                                                 NOTE: */
        uint64_t stlcl_stall           : 1;  /**< [  6:  6](R/W) Local stall bit.  During a ST_LCL transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input. */
        uint64_t cya_ld_lcl_rst_rs_clr : 1;  /**< [  7:  7](R/W) This register contains backdoor cleanup state.
                                                                 Internal:
                                                                 When performing a load local with reset operation, If this bit is set
                                                                 it will override the logic that holds reset and run_stall active until the slice with
                                                                 last == 1 is completed.  This will result in reset and run_stall being deasserted after
                                                                 each slice of a multislice ld_lcl_wrst operation. */
        uint64_t powersave_on_cnt      : 10; /**< [ 17:  8](R/W) This register provides the on (high) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven high for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t powersave_off_cnt     : 10; /**< [ 27: 18](R/W) This register provides the off (low) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven low for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t powersave_stall_en    : 1;  /**< [ 28: 28](R/W) This bit enables the RUNSTALL powersaving mode. If set, the RUNSTALL signal is toggled
                                                                 according to the POWERSAVE_ON_CNT and POWERSAVE_OFF_CNT registers. The RUNSTALL
                                                                 signal is toggled high for the number of clocks provided by POWERSAVE_ON_CNT+1. Likewise
                                                                 the RUNSTALL is toggled low for the number of clocks provided by POWERSAVE_OFF_CNT+1.
                                                                 Minimum valid count values are 15. */
        uint64_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_proc_ctl_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rcv_core              : 1;  /**< [ 31: 31](R/W) When this bit is set, a DSP core which is low power state (deep sleep or Light
                                                                 Sleep) would wake up and move to run state. */
        uint64_t deep_slp_req          : 1;  /**< [ 30: 30](R/W) An assertion of this bit, in a case where a DSP core is in light sleep would
                                                                 cause transition to Stand By (deep sleep). */
        uint64_t boot                  : 1;  /**< [ 29: 29](R/W) When this bit is set, upon DSP exit Global Reset, the DSP would start booting
                                                                 from an address which is set by MDAB(0..15)_INT_VEC_ADDR. */
        uint64_t powersave_stall_en    : 1;  /**< [ 28: 28](R/W) This bit enables the RUNSTALL powersaving mode. If set, the RUNSTALL signal is toggled
                                                                 according to the POWERSAVE_ON_CNT and POWERSAVE_OFF_CNT registers. The RUNSTALL
                                                                 signal is toggled high for the number of clocks provided by POWERSAVE_ON_CNT+1. Likewise
                                                                 the RUNSTALL is toggled low for the number of clocks provided by POWERSAVE_OFF_CNT+1.
                                                                 Minimum valid count values are 15. */
        uint64_t powersave_off_cnt     : 10; /**< [ 27: 18](R/W) This register provides the off (low) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven low for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t powersave_on_cnt      : 10; /**< [ 17:  8](R/W) This register provides the on (high) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven high for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t cya_ld_lcl_rst_rs_clr : 1;  /**< [  7:  7](R/W) This register contains backdoor cleanup state.
                                                                 Internal:
                                                                 When performing a load local with reset operation, If this bit is set
                                                                 it will override the logic that holds reset and run_stall active until the slice with
                                                                 last == 1 is completed.  This will result in reset and run_stall being deasserted after
                                                                 each slice of a multislice ld_lcl_wrst operation. */
        uint64_t stlcl_stall           : 1;  /**< [  6:  6](R/W) Local stall bit.  During a ST_LCL transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input. */
        uint64_t ldlcl_stall           : 1;  /**< [  5:  5](R/W) Local stall bit.  During a LD_LCL (without reset) transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input.
                                                                 NOTE: */
        uint64_t breset                : 1;  /**< [  4:  4](R/W/H) When software sets this bit the entire DSP Core will be forced in the reset state. When the
                                                                 software clears this bit, the DSP will come out of reset and start execution at the reset
                                                                 interrupt vector (if run_stall is not asserted).  This bit is cleared at the start of
                                                                 a load local with reset operation so that the DSP reset input can be correctly controlled
                                                                 by the load local with reset logic. DSP Memory system and DSP Debug lgic are not
                                                                 held at reset while this bit is set. */
        uint64_t dspsysrest            : 1;  /**< [  3:  3](R/W) Force the DSP core and the DSP Memory system to reset state. DSP Debug logic is
                                                                 not held at reset state while this bit is set. */
        uint64_t dreset                : 1;  /**< [  2:  2](R/W) Setting this bit asserts reset to the DSP debug logic. */
        uint64_t reserved_1            : 1;
        uint64_t run_stall             : 1;  /**< [  0:  0](R/W/H) When this bit is SET the DSP's RUN_STALL input will be asserted, forcing the DSP to
                                                                 "stall" until the bit is cleared.  This bit is cleared at the start of a load local
                                                                 with reset operation to enable the load local logic to control the DSP RunStall input.
                                                                 At the end of the load local with reset operation when the last block of instruction/
                                                                 data has been loaded into the DSP memory, the DSP RunStall input will be deasserted
                                                                 so the DSP can start running. */
#else /* Word 0 - Little Endian */
        uint64_t run_stall             : 1;  /**< [  0:  0](R/W/H) When this bit is SET the DSP's RUN_STALL input will be asserted, forcing the DSP to
                                                                 "stall" until the bit is cleared.  This bit is cleared at the start of a load local
                                                                 with reset operation to enable the load local logic to control the DSP RunStall input.
                                                                 At the end of the load local with reset operation when the last block of instruction/
                                                                 data has been loaded into the DSP memory, the DSP RunStall input will be deasserted
                                                                 so the DSP can start running. */
        uint64_t reserved_1            : 1;
        uint64_t dreset                : 1;  /**< [  2:  2](R/W) Setting this bit asserts reset to the DSP debug logic. */
        uint64_t dspsysrest            : 1;  /**< [  3:  3](R/W) Force the DSP core and the DSP Memory system to reset state. DSP Debug logic is
                                                                 not held at reset state while this bit is set. */
        uint64_t breset                : 1;  /**< [  4:  4](R/W/H) When software sets this bit the entire DSP Core will be forced in the reset state. When the
                                                                 software clears this bit, the DSP will come out of reset and start execution at the reset
                                                                 interrupt vector (if run_stall is not asserted).  This bit is cleared at the start of
                                                                 a load local with reset operation so that the DSP reset input can be correctly controlled
                                                                 by the load local with reset logic. DSP Memory system and DSP Debug lgic are not
                                                                 held at reset while this bit is set. */
        uint64_t ldlcl_stall           : 1;  /**< [  5:  5](R/W) Local stall bit.  During a LD_LCL (without reset) transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input.
                                                                 NOTE: */
        uint64_t stlcl_stall           : 1;  /**< [  6:  6](R/W) Local stall bit.  During a ST_LCL transaction, if this
                                                                 bit is SET, the DAC hardware will assert the DSP RunStall input. If the bit
                                                                 is CLEAR, the DAC hardware will NOT assert the DSP RunStall input. */
        uint64_t cya_ld_lcl_rst_rs_clr : 1;  /**< [  7:  7](R/W) This register contains backdoor cleanup state.
                                                                 Internal:
                                                                 When performing a load local with reset operation, If this bit is set
                                                                 it will override the logic that holds reset and run_stall active until the slice with
                                                                 last == 1 is completed.  This will result in reset and run_stall being deasserted after
                                                                 each slice of a multislice ld_lcl_wrst operation. */
        uint64_t powersave_on_cnt      : 10; /**< [ 17:  8](R/W) This register provides the on (high) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven high for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t powersave_off_cnt     : 10; /**< [ 27: 18](R/W) This register provides the off (low) count for RUNSTALL powersaving mode. The
                                                                 RUNSTALL signal will be driven low for
                                                                 this value +1 clocks. The minimum valid value is 15, which provides a count of
                                                                 16 clocks. This register provides
                                                                 a maximum count of 1024. */
        uint64_t powersave_stall_en    : 1;  /**< [ 28: 28](R/W) This bit enables the RUNSTALL powersaving mode. If set, the RUNSTALL signal is toggled
                                                                 according to the POWERSAVE_ON_CNT and POWERSAVE_OFF_CNT registers. The RUNSTALL
                                                                 signal is toggled high for the number of clocks provided by POWERSAVE_ON_CNT+1. Likewise
                                                                 the RUNSTALL is toggled low for the number of clocks provided by POWERSAVE_OFF_CNT+1.
                                                                 Minimum valid count values are 15. */
        uint64_t boot                  : 1;  /**< [ 29: 29](R/W) When this bit is set, upon DSP exit Global Reset, the DSP would start booting
                                                                 from an address which is set by MDAB(0..15)_INT_VEC_ADDR. */
        uint64_t deep_slp_req          : 1;  /**< [ 30: 30](R/W) An assertion of this bit, in a case where a DSP core is in light sleep would
                                                                 cause transition to Stand By (deep sleep). */
        uint64_t rcv_core              : 1;  /**< [ 31: 31](R/W) When this bit is set, a DSP core which is low power state (deep sleep or Light
                                                                 Sleep) would wake up and move to run state. */
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_proc_ctl cavm_mdabx_proc_ctl_t;

static inline uint64_t CAVM_MDABX_PROC_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PROC_CTL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441001c0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444001c0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_PROC_CTL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PROC_CTL(a) cavm_mdabx_proc_ctl_t
#define bustype_CAVM_MDABX_PROC_CTL(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PROC_CTL(a) "MDABX_PROC_CTL"
#define busnum_CAVM_MDABX_PROC_CTL(a) (a)
#define arguments_CAVM_MDABX_PROC_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_proc_debug
 *
 * MDAB Processor Debug Register
 * This register contains iram data store and dram conditional store status bits (need
 * to update this register) .
 */
union cavm_mdabx_proc_debug
{
    uint64_t u;
    struct cavm_mdabx_proc_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t dblexccnt             : 8;  /**< [ 15:  8](R/W/H) DSP Double Exception Fault Counter. Counts the number double exceptions which
                                                                 have occurred. write zeroes to clear. */
        uint64_t pfatalerr             : 1;  /**< [  7:  7](RO/H) Sticky Fatal Error notification signal that is asserted when a fatal error condition occurs. */
        uint64_t debugmode             : 1;  /**< [  6:  6](RO/H) non-maskable version of XOCDMode (DSP status output). */
        uint64_t iram1loadstore        : 1;  /**< [  5:  5](RO/H) Data load/store to iram 1. */
        uint64_t iram0loadstore        : 1;  /**< [  4:  4](RO/H) Data load/store to iram 0. */
        uint64_t dram1lockb1           : 1;  /**< [  3:  3](RO/H) Conditional store has caused dram1 bank1 to be locked. */
        uint64_t dram1lockb0           : 1;  /**< [  2:  2](RO/H) Conditional store has caused dram1 bank0 to be locked. */
        uint64_t dram0lockb1           : 1;  /**< [  1:  1](RO/H) Conditional store has caused dram0 bank1 to be locked. */
        uint64_t dram0lockb0           : 1;  /**< [  0:  0](RO/H) Conditional store has caused dram0 bank0 to be locked. */
#else /* Word 0 - Little Endian */
        uint64_t dram0lockb0           : 1;  /**< [  0:  0](RO/H) Conditional store has caused dram0 bank0 to be locked. */
        uint64_t dram0lockb1           : 1;  /**< [  1:  1](RO/H) Conditional store has caused dram0 bank1 to be locked. */
        uint64_t dram1lockb0           : 1;  /**< [  2:  2](RO/H) Conditional store has caused dram1 bank0 to be locked. */
        uint64_t dram1lockb1           : 1;  /**< [  3:  3](RO/H) Conditional store has caused dram1 bank1 to be locked. */
        uint64_t iram0loadstore        : 1;  /**< [  4:  4](RO/H) Data load/store to iram 0. */
        uint64_t iram1loadstore        : 1;  /**< [  5:  5](RO/H) Data load/store to iram 1. */
        uint64_t debugmode             : 1;  /**< [  6:  6](RO/H) non-maskable version of XOCDMode (DSP status output). */
        uint64_t pfatalerr             : 1;  /**< [  7:  7](RO/H) Sticky Fatal Error notification signal that is asserted when a fatal error condition occurs. */
        uint64_t dblexccnt             : 8;  /**< [ 15:  8](R/W/H) DSP Double Exception Fault Counter. Counts the number double exceptions which
                                                                 have occurred. write zeroes to clear. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_proc_debug_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_31        : 16;
        uint64_t dblexccnt             : 8;  /**< [ 15:  8](R/W/H) DSP Double Exception Fault Counter. Counts the number double exceptions which
                                                                 have occurred. write zeroes to clear. */
        uint64_t pfatalerr             : 1;  /**< [  7:  7](RO/H) Sticky Fatal Error notification signal that is asserted when a fatal error condition occurs. */
        uint64_t debugmode             : 1;  /**< [  6:  6](RO/H) non-maskable version of XOCDMode (DSP status output). */
        uint64_t iram1loadstore        : 1;  /**< [  5:  5](RO/H) Data load/store to iram 1. */
        uint64_t iram0loadstore        : 1;  /**< [  4:  4](RO/H) Data load/store to iram 0. */
        uint64_t dram1lockb1           : 1;  /**< [  3:  3](RO/H) Conditional store has caused dram1 bank1 to be locked. */
        uint64_t dram1lockb0           : 1;  /**< [  2:  2](RO/H) Conditional store has caused dram1 bank0 to be locked. */
        uint64_t dram0lockb1           : 1;  /**< [  1:  1](RO/H) Conditional store has caused dram0 bank1 to be locked. */
        uint64_t dram0lockb0           : 1;  /**< [  0:  0](RO/H) Conditional store has caused dram0 bank0 to be locked. */
#else /* Word 0 - Little Endian */
        uint64_t dram0lockb0           : 1;  /**< [  0:  0](RO/H) Conditional store has caused dram0 bank0 to be locked. */
        uint64_t dram0lockb1           : 1;  /**< [  1:  1](RO/H) Conditional store has caused dram0 bank1 to be locked. */
        uint64_t dram1lockb0           : 1;  /**< [  2:  2](RO/H) Conditional store has caused dram1 bank0 to be locked. */
        uint64_t dram1lockb1           : 1;  /**< [  3:  3](RO/H) Conditional store has caused dram1 bank1 to be locked. */
        uint64_t iram0loadstore        : 1;  /**< [  4:  4](RO/H) Data load/store to iram 0. */
        uint64_t iram1loadstore        : 1;  /**< [  5:  5](RO/H) Data load/store to iram 1. */
        uint64_t debugmode             : 1;  /**< [  6:  6](RO/H) non-maskable version of XOCDMode (DSP status output). */
        uint64_t pfatalerr             : 1;  /**< [  7:  7](RO/H) Sticky Fatal Error notification signal that is asserted when a fatal error condition occurs. */
        uint64_t dblexccnt             : 8;  /**< [ 15:  8](R/W/H) DSP Double Exception Fault Counter. Counts the number double exceptions which
                                                                 have occurred. write zeroes to clear. */
        uint64_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_proc_debug cavm_mdabx_proc_debug_t;

static inline uint64_t CAVM_MDABX_PROC_DEBUG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PROC_DEBUG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441001e0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444001e0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_PROC_DEBUG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PROC_DEBUG(a) cavm_mdabx_proc_debug_t
#define bustype_CAVM_MDABX_PROC_DEBUG(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PROC_DEBUG(a) "MDABX_PROC_DEBUG"
#define busnum_CAVM_MDABX_PROC_DEBUG(a) (a)
#define arguments_CAVM_MDABX_PROC_DEBUG(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_proc_status
 *
 * MDAB Processor Status Register
 * This register indicates status value regarding the DSP state.
 */
union cavm_mdabx_proc_status
{
    uint64_t u;
    struct cavm_mdabx_proc_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t ocem_dbg_mod          : 1;  /**< [ 16: 16](RO/H) DSP OECM debugmode indication. */
        uint64_t dsp_trap              : 1;  /**< [ 15: 15](RO/H) DSP Core in a TRAP indication */
        uint64_t etm_en                : 1;  /**< [ 14: 14](RO/H) DSP Core ETM is Enabled. */
        uint64_t etm_fifo_empty        : 1;  /**< [ 13: 13](RO/H) reflect the status for the ETM FIFO, 0x0 - empty, 0x1 - accupeid . */
        uint64_t ocem_gp               : 4;  /**< [ 12:  9](RO/H) reflect the status at OCEM Control Register bits[15:12]. */
        uint64_t ack_ds                : 1;  /**< [  8:  8](RO/H) Acknowledge transition request from Light Sleep to Deep Sleep. */
        uint64_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_7          : 8;
        uint64_t ack_ds                : 1;  /**< [  8:  8](RO/H) Acknowledge transition request from Light Sleep to Deep Sleep. */
        uint64_t ocem_gp               : 4;  /**< [ 12:  9](RO/H) reflect the status at OCEM Control Register bits[15:12]. */
        uint64_t etm_fifo_empty        : 1;  /**< [ 13: 13](RO/H) reflect the status for the ETM FIFO, 0x0 - empty, 0x1 - accupeid . */
        uint64_t etm_en                : 1;  /**< [ 14: 14](RO/H) DSP Core ETM is Enabled. */
        uint64_t dsp_trap              : 1;  /**< [ 15: 15](RO/H) DSP Core in a TRAP indication */
        uint64_t ocem_dbg_mod          : 1;  /**< [ 16: 16](RO/H) DSP OECM debugmode indication. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_proc_status_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_31         : 30;
        uint64_t xocd_state            : 1;  /**< [  1:  1](RO/H) Indicates the DSP has entered the post reset OCD halt mode. */
        uint64_t pwait_state           : 1;  /**< [  0:  0](RO/H) Indicates that the DSP is in the sleep mode as a result of executing the
                                                                 WAITI instruction.  Any enabled interrupt will wake the DSP up. */
#else /* Word 0 - Little Endian */
        uint64_t pwait_state           : 1;  /**< [  0:  0](RO/H) Indicates that the DSP is in the sleep mode as a result of executing the
                                                                 WAITI instruction.  Any enabled interrupt will wake the DSP up. */
        uint64_t xocd_state            : 1;  /**< [  1:  1](RO/H) Indicates the DSP has entered the post reset OCD halt mode. */
        uint64_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_proc_status_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_31        : 15;
        uint64_t ocem_dbg_mod          : 1;  /**< [ 16: 16](RO/H) DSP OECM debugmode indication. */
        uint64_t dsp_trap              : 1;  /**< [ 15: 15](RO/H) DSP Core in a TRAP indication */
        uint64_t etm_en                : 1;  /**< [ 14: 14](RO/H) DSP Core ETM is Enabled. */
        uint64_t etm_fifo_empty        : 1;  /**< [ 13: 13](RO/H) reflect the status for the ETM FIFO, 0x0 - empty, 0x1 - accupeid . */
        uint64_t ocem_gp               : 4;  /**< [ 12:  9](RO/H) reflect the status at OCEM Control Register bits[15:12]. */
        uint64_t ack_ds                : 1;  /**< [  8:  8](RO/H) Acknowledge transition request from Light Sleep to Deep Sleep. */
        uint64_t reserved_2_7          : 6;
        uint64_t core_deep_sleep       : 1;  /**< [  1:  1](RO/H) Indicates the DSP core and its memory system are in sleep mode. Any enabled
                                                                 interrupt will wake the DSP up or setting RCV_CORE in MDAB(0..15)_PROC_CTL. */
        uint64_t core_light_sleep      : 1;  /**< [  0:  0](RO/H) Indicates that the DSP core is in the sleep mode. Any enabled interrupt will
                                                                 wake the DSP up or setting RCV_CORE in MDAB(0..15)_PROC_CTL. */
#else /* Word 0 - Little Endian */
        uint64_t core_light_sleep      : 1;  /**< [  0:  0](RO/H) Indicates that the DSP core is in the sleep mode. Any enabled interrupt will
                                                                 wake the DSP up or setting RCV_CORE in MDAB(0..15)_PROC_CTL. */
        uint64_t core_deep_sleep       : 1;  /**< [  1:  1](RO/H) Indicates the DSP core and its memory system are in sleep mode. Any enabled
                                                                 interrupt will wake the DSP up or setting RCV_CORE in MDAB(0..15)_PROC_CTL. */
        uint64_t reserved_2_7          : 6;
        uint64_t ack_ds                : 1;  /**< [  8:  8](RO/H) Acknowledge transition request from Light Sleep to Deep Sleep. */
        uint64_t ocem_gp               : 4;  /**< [ 12:  9](RO/H) reflect the status at OCEM Control Register bits[15:12]. */
        uint64_t etm_fifo_empty        : 1;  /**< [ 13: 13](RO/H) reflect the status for the ETM FIFO, 0x0 - empty, 0x1 - accupeid . */
        uint64_t etm_en                : 1;  /**< [ 14: 14](RO/H) DSP Core ETM is Enabled. */
        uint64_t dsp_trap              : 1;  /**< [ 15: 15](RO/H) DSP Core in a TRAP indication */
        uint64_t ocem_dbg_mod          : 1;  /**< [ 16: 16](RO/H) DSP OECM debugmode indication. */
        uint64_t reserved_17_31        : 15;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_proc_status cavm_mdabx_proc_status_t;

static inline uint64_t CAVM_MDABX_PROC_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PROC_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441001b0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444001b0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_PROC_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PROC_STATUS(a) cavm_mdabx_proc_status_t
#define bustype_CAVM_MDABX_PROC_STATUS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PROC_STATUS(a) "MDABX_PROC_STATUS"
#define busnum_CAVM_MDABX_PROC_STATUS(a) (a)
#define arguments_CAVM_MDABX_PROC_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_psm_cmd#
 *
 * MDAB PSM Command Register
 * "These four 32b registers comprise a full 128b job command which allows DSP software to send  new
 * 128-bit job command to the PHY Scheduler Module(PSM) by:
 *    1) Writes to the 4x PSM_CMD(0..3) registers: (where the 128-bit Job Command =
 *       MDABx_PSM_CMD[3:0]).
 *    2) Write to the MDAB()_PSM_CMD_PUSH[PUSH_BUSY]=1 which will send a 128b job command to the
 *       PSM.
 *    3) Wait (poll) until hardware clears the MDAB()_PSM_CMD_PUSH[PUSH_BUSY]=0 to
 *       ensure the job command has been
 *       fully transferred to the PSM before the DSP software can re-use the PSM_CMD[3:0] registers."
 */
union cavm_mdabx_psm_cmdx
{
    uint64_t u;
    struct cavm_mdabx_psm_cmdx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t word                  : 32; /**< [ 31:  0](R/W) The full 128-bit job command is comprised of the WORD[3:0] from EACH 1(of 4) 32b CSRs =
                                                                 {MDABx_PSM_CMD[3:0]} */
#else /* Word 0 - Little Endian */
        uint64_t word                  : 32; /**< [ 31:  0](R/W) The full 128-bit job command is comprised of the WORD[3:0] from EACH 1(of 4) 32b CSRs =
                                                                 {MDABx_PSM_CMD[3:0]} */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_psm_cmdx_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t word                  : 32; /**< [ 31:  0](R/W) The full 128-bit job command is comprised of the WORD[3:0] from EACH 1(of 4) 32b CSRs =
                                                                 {MDABx_PSM_CMD[3:0]} */
#else /* Word 0 - Little Endian */
        uint64_t word                  : 32; /**< [ 31:  0](R/W) The full 128-bit job command is comprised of the WORD[3:0] from EACH 1(of 4) 32b CSRs =
                                                                 {MDABx_PSM_CMD[3:0]} */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_psm_cmdx cavm_mdabx_psm_cmdx_t;

static inline uint64_t CAVM_MDABX_PSM_CMDX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PSM_CMDX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=3)))
        return 0x87e044100100ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=3)))
        return 0x87e044400100ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x3);
    __cavm_csr_fatal("MDABX_PSM_CMDX", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PSM_CMDX(a,b) cavm_mdabx_psm_cmdx_t
#define bustype_CAVM_MDABX_PSM_CMDX(a,b) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PSM_CMDX(a,b) "MDABX_PSM_CMDX"
#define busnum_CAVM_MDABX_PSM_CMDX(a,b) (a)
#define arguments_CAVM_MDABX_PSM_CMDX(a,b) (a),(b),-1,-1

/**
 * Register (RSL32b) mdab#_psm_cmd_push
 *
 * MDAB PSM Command Register
 * This register causes the hardware to push a new job command currently in MDAB()_PSM_CMD_(0..3)
 * to the PSM.
 */
union cavm_mdabx_psm_cmd_push
{
    uint64_t u;
    struct cavm_mdabx_psm_cmd_push_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t psm_idle              : 1;  /**< [  1:  1](RO/H) When high, indicates that there are no outstanding psm commands in the jcmd logic. */
        uint64_t push_busy             : 1;  /**< [  0:  0](R/W1S/H) When software writes a one, hardware will start sending the PSM command stored in
                                                                 MDABx_PSM_CMD(0..3) to the PSM.  Hardware will clear this bit when the 128b job command has
                                                                 been sent to the PSM, thus allowing software to re-use the MDABx_PSM_CMD(0..3) for the next
                                                                 job command (if required). */
#else /* Word 0 - Little Endian */
        uint64_t push_busy             : 1;  /**< [  0:  0](R/W1S/H) When software writes a one, hardware will start sending the PSM command stored in
                                                                 MDABx_PSM_CMD(0..3) to the PSM.  Hardware will clear this bit when the 128b job command has
                                                                 been sent to the PSM, thus allowing software to re-use the MDABx_PSM_CMD(0..3) for the next
                                                                 job command (if required). */
        uint64_t psm_idle              : 1;  /**< [  1:  1](RO/H) When high, indicates that there are no outstanding psm commands in the jcmd logic. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_psm_cmd_push_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_31         : 30;
        uint64_t psm_idle              : 1;  /**< [  1:  1](RO/H) When high, indicates that there are no outstanding psm commands in the jcmd logic. */
        uint64_t push_busy             : 1;  /**< [  0:  0](R/W1S/H) When software writes a one, hardware will start sending the PSM command stored in
                                                                 MDABx_PSM_CMD(0..3) to the PSM.  Hardware will clear this bit when the 128b job command has
                                                                 been sent to the PSM, thus allowing software to re-use the MDABx_PSM_CMD(0..3) for the next
                                                                 job command (if required). */
#else /* Word 0 - Little Endian */
        uint64_t push_busy             : 1;  /**< [  0:  0](R/W1S/H) When software writes a one, hardware will start sending the PSM command stored in
                                                                 MDABx_PSM_CMD(0..3) to the PSM.  Hardware will clear this bit when the 128b job command has
                                                                 been sent to the PSM, thus allowing software to re-use the MDABx_PSM_CMD(0..3) for the next
                                                                 job command (if required). */
        uint64_t psm_idle              : 1;  /**< [  1:  1](RO/H) When high, indicates that there are no outstanding psm commands in the jcmd logic. */
        uint64_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_psm_cmd_push cavm_mdabx_psm_cmd_push_t;

static inline uint64_t CAVM_MDABX_PSM_CMD_PUSH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PSM_CMD_PUSH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100140ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400140ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_PSM_CMD_PUSH", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PSM_CMD_PUSH(a) cavm_mdabx_psm_cmd_push_t
#define bustype_CAVM_MDABX_PSM_CMD_PUSH(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PSM_CMD_PUSH(a) "MDABX_PSM_CMD_PUSH"
#define busnum_CAVM_MDABX_PSM_CMD_PUSH(a) (a)
#define arguments_CAVM_MDABX_PSM_CMD_PUSH(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_psm_timer
 *
 * MDAB PSM Timer Broadcast Register
 * This register contains the latest value captured from the PSM timer.
 */
union cavm_mdabx_psm_timer
{
    uint64_t u;
    struct cavm_mdabx_psm_timer_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t frame                 : 12; /**< [ 15:  4](RO/H) PSM timer frame field. */
        uint64_t sub_frame             : 4;  /**< [  3:  0](RO/H) PSM timer sub_frame field. */
#else /* Word 0 - Little Endian */
        uint64_t sub_frame             : 4;  /**< [  3:  0](RO/H) PSM timer sub_frame field. */
        uint64_t frame                 : 12; /**< [ 15:  4](RO/H) PSM timer frame field. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_psm_timer_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_31        : 16;
        uint64_t frame                 : 12; /**< [ 15:  4](RO/H) PSM timer frame field. */
        uint64_t sub_frame             : 4;  /**< [  3:  0](RO/H) PSM timer sub_frame field. */
#else /* Word 0 - Little Endian */
        uint64_t sub_frame             : 4;  /**< [  3:  0](RO/H) PSM timer sub_frame field. */
        uint64_t frame                 : 12; /**< [ 15:  4](RO/H) PSM timer frame field. */
        uint64_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_psm_timer cavm_mdabx_psm_timer_t;

static inline uint64_t CAVM_MDABX_PSM_TIMER(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PSM_TIMER(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441001f0ll + 0x4000ll * ((a) & 0x3f);
    __cavm_csr_fatal("MDABX_PSM_TIMER", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PSM_TIMER(a) cavm_mdabx_psm_timer_t
#define bustype_CAVM_MDABX_PSM_TIMER(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PSM_TIMER(a) "MDABX_PSM_TIMER"
#define busnum_CAVM_MDABX_PSM_TIMER(a) (a)
#define arguments_CAVM_MDABX_PSM_TIMER(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_psm_timer_hi
 *
 * MDAB PSM Timer Broadcast Register
 * This register contains the latest value captured from the PSM timer bits[63:32].
 */
union cavm_mdabx_psm_timer_hi
{
    uint32_t u;
    struct cavm_mdabx_psm_timer_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bcn_hi                : 32; /**< [ 31:  0](RO/H) BCN Time bits[63:32] broadcast from the PSM timer. */
#else /* Word 0 - Little Endian */
        uint32_t bcn_hi                : 32; /**< [ 31:  0](RO/H) BCN Time bits[63:32] broadcast from the PSM timer. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_psm_timer_hi_s cn; */
};
typedef union cavm_mdabx_psm_timer_hi cavm_mdabx_psm_timer_hi_t;

static inline uint64_t CAVM_MDABX_PSM_TIMER_HI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PSM_TIMER_HI(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444001f0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_PSM_TIMER_HI", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PSM_TIMER_HI(a) cavm_mdabx_psm_timer_hi_t
#define bustype_CAVM_MDABX_PSM_TIMER_HI(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PSM_TIMER_HI(a) "MDABX_PSM_TIMER_HI"
#define busnum_CAVM_MDABX_PSM_TIMER_HI(a) (a)
#define arguments_CAVM_MDABX_PSM_TIMER_HI(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_psm_timer_lo
 *
 * MDAB PSM Timer Broadcast Register
 * This register contains the latest value captured from the PSM timer[31:0].
 *
 * Internal:
 * This register complete the lower bits of the BCN time. part of it is captured from
 * the PSM time broadcast and the other parts is being generated locally.
 * The 64bit formed from those two registers (PSM_TIMER_LO,PSM_TIMER_HI) are being
 * passed to the Trace Timespamp .
 */
union cavm_mdabx_psm_timer_lo
{
    uint32_t u;
    struct cavm_mdabx_psm_timer_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bcn_lo                : 8;  /**< [ 31: 24](RO/H) BCN Time bits[31:24] broadcast from the PSM timer. */
        uint32_t bcn_lsb               : 24; /**< [ 23:  0](RO/H) BCN Time bits[23:0].

                                                                 Internal:
                                                                 Those bits are generated by a local counter running int he DSP Freq to alow high
                                                                 granularity of the BNC timer. */
#else /* Word 0 - Little Endian */
        uint32_t bcn_lsb               : 24; /**< [ 23:  0](RO/H) BCN Time bits[23:0].

                                                                 Internal:
                                                                 Those bits are generated by a local counter running int he DSP Freq to alow high
                                                                 granularity of the BNC timer. */
        uint32_t bcn_lo                : 8;  /**< [ 31: 24](RO/H) BCN Time bits[31:24] broadcast from the PSM timer. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_psm_timer_lo_s cn; */
};
typedef union cavm_mdabx_psm_timer_lo cavm_mdabx_psm_timer_lo_t;

static inline uint64_t CAVM_MDABX_PSM_TIMER_LO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_PSM_TIMER_LO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400200ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_PSM_TIMER_LO", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_PSM_TIMER_LO(a) cavm_mdabx_psm_timer_lo_t
#define bustype_CAVM_MDABX_PSM_TIMER_LO(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_PSM_TIMER_LO(a) "MDABX_PSM_TIMER_LO"
#define busnum_CAVM_MDABX_PSM_TIMER_LO(a) (a)
#define arguments_CAVM_MDABX_PSM_TIMER_LO(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rd_addr
 *
 * MDAB Read DMA Address Register
 * The starting address used by the RD-DMA engine when writing RD-DMA data to local DSP memory.
 * During Job_Type = LD_LCL commands, hardware loads the RD_ADDR/RD_LIMIT registers directly.
 */
union cavm_mdabx_rd_addr
{
    uint64_t u;
    struct cavm_mdabx_rd_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31_63        : 33;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W/H) The 128b-aligned starting address used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4)
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4)
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines WHICH DSP Memory space
                                                                 (0:DMEM/1:IMEM) */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W/H) The 128b-aligned starting address used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4)
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4)
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines WHICH DSP Memory space
                                                                 (0:DMEM/1:IMEM) */
        uint64_t reserved_31_63        : 33;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_rd_addr_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31           : 1;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W/H) The 128b-aligned starting address used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4)
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4)
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines WHICH DSP Memory space
                                                                 (0:DMEM/1:IMEM) */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W/H) The 128b-aligned starting address used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4)
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4)
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines WHICH DSP Memory space
                                                                 (0:DMEM/1:IMEM) */
        uint64_t reserved_31           : 1;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_rd_addr_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_31        : 9;
        uint64_t addr                  : 19; /**< [ 22:  4](R/W/H) The 128b-aligned starting address used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory.
                                                                 When ADDR[22:21] == 2'b00 (D-TCM/DMEM):
                                                                   Valid 128b-aligned address range = 0x0 - (0x03_FFFF \>\> 4)
                                                                 When ADDR[22:21] == 2'b01 (P-TCM/IMEM):
                                                                   Valid 128b-aligned address range = (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4)
                                                                 When ADDR[22:21] == 2'b10 (CMP registers):
                                                                   Valid 128b-aligned address range = (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4) */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 19; /**< [ 22:  4](R/W/H) The 128b-aligned starting address used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory.
                                                                 When ADDR[22:21] == 2'b00 (D-TCM/DMEM):
                                                                   Valid 128b-aligned address range = 0x0 - (0x03_FFFF \>\> 4)
                                                                 When ADDR[22:21] == 2'b01 (P-TCM/IMEM):
                                                                   Valid 128b-aligned address range = (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4)
                                                                 When ADDR[22:21] == 2'b10 (CMP registers):
                                                                   Valid 128b-aligned address range = (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4) */
        uint64_t reserved_23_31        : 9;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_rd_addr cavm_mdabx_rd_addr_t;

static inline uint64_t CAVM_MDABX_RD_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RD_ADDR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100070ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400070ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RD_ADDR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RD_ADDR(a) cavm_mdabx_rd_addr_t
#define bustype_CAVM_MDABX_RD_ADDR(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RD_ADDR(a) "MDABX_RD_ADDR"
#define busnum_CAVM_MDABX_RD_ADDR(a) (a)
#define arguments_CAVM_MDABX_RD_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rd_error_sts
 *
 * MDAB RD Error Status Register
 * This register contains DSP slave read error status signals.
 */
union cavm_mdabx_rd_error_sts
{
    uint32_t u;
    struct cavm_mdabx_rd_error_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_25_31        : 7;
        uint32_t addr                  : 21; /**< [ 24:  4](RO/H) When a DSP slave write access causes the SLVERR error bit to be set, this field captures the
                                                                 failing address. */
        uint32_t error_src             : 3;  /**< [  3:  1](RO/H) This field indicates the source of the transaction that caused the recorded error.
                                                                 000: WDM
                                                                 001: RDM
                                                                 010: CDM
                                                                 011: CSR
                                                                 100: PFO Write Request Error */
        uint32_t mem_slverr            : 1;  /**< [  0:  0](R/W1C/H) This bit will be set when a write channel csr or DMA engine access is performed to a non existent
                                                                 instruction or data memory address, or when any other illegal access is performed */
#else /* Word 0 - Little Endian */
        uint32_t mem_slverr            : 1;  /**< [  0:  0](R/W1C/H) This bit will be set when a write channel csr or DMA engine access is performed to a non existent
                                                                 instruction or data memory address, or when any other illegal access is performed */
        uint32_t error_src             : 3;  /**< [  3:  1](RO/H) This field indicates the source of the transaction that caused the recorded error.
                                                                 000: WDM
                                                                 001: RDM
                                                                 010: CDM
                                                                 011: CSR
                                                                 100: PFO Write Request Error */
        uint32_t addr                  : 21; /**< [ 24:  4](RO/H) When a DSP slave write access causes the SLVERR error bit to be set, this field captures the
                                                                 failing address. */
        uint32_t reserved_25_31        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_rd_error_sts_s cn; */
};
typedef union cavm_mdabx_rd_error_sts cavm_mdabx_rd_error_sts_t;

static inline uint64_t CAVM_MDABX_RD_ERROR_STS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RD_ERROR_STS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400270ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RD_ERROR_STS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RD_ERROR_STS(a) cavm_mdabx_rd_error_sts_t
#define bustype_CAVM_MDABX_RD_ERROR_STS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RD_ERROR_STS(a) "MDABX_RD_ERROR_STS"
#define busnum_CAVM_MDABX_RD_ERROR_STS(a) (a)
#define arguments_CAVM_MDABX_RD_ERROR_STS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rd_fifo_status
 *
 * MDAB Read DMA Slice FIFO Status Register
 * The entry status of the read DMA slice FIFO.
 */
union cavm_mdabx_rd_fifo_status
{
    uint32_t u;
    struct cavm_mdabx_rd_fifo_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_6_31         : 26;
        uint32_t slice_fifo_rem_cnt    : 3;  /**< [  5:  3](RO/H) This field is the count of the remaining FIFO entries. It is updated after every FIFO
                                                                 pop (or START_BUSY set), and retains it's last value after a FIFO flush. */
        uint32_t slice_fifo_psh_cnt    : 3;  /**< [  2:  0](RO/H) This count field provides the number of slice FIFO pushes since the last
                                                                 DMA transfer finished, or since the last FIFO flush. */
#else /* Word 0 - Little Endian */
        uint32_t slice_fifo_psh_cnt    : 3;  /**< [  2:  0](RO/H) This count field provides the number of slice FIFO pushes since the last
                                                                 DMA transfer finished, or since the last FIFO flush. */
        uint32_t slice_fifo_rem_cnt    : 3;  /**< [  5:  3](RO/H) This field is the count of the remaining FIFO entries. It is updated after every FIFO
                                                                 pop (or START_BUSY set), and retains it's last value after a FIFO flush. */
        uint32_t reserved_6_31         : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_rd_fifo_status_s cn; */
};
typedef union cavm_mdabx_rd_fifo_status cavm_mdabx_rd_fifo_status_t;

static inline uint64_t CAVM_MDABX_RD_FIFO_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RD_FIFO_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100480ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400480ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RD_FIFO_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RD_FIFO_STATUS(a) cavm_mdabx_rd_fifo_status_t
#define bustype_CAVM_MDABX_RD_FIFO_STATUS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RD_FIFO_STATUS(a) "MDABX_RD_FIFO_STATUS"
#define busnum_CAVM_MDABX_RD_FIFO_STATUS(a) (a)
#define arguments_CAVM_MDABX_RD_FIFO_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rd_length
 *
 * MDAB Read DMA Length Register
 * The actual 128-bit length of the most recent RD-DMA engine job configuration transfer.
 */
union cavm_mdabx_rd_length
{
    uint64_t u;
    struct cavm_mdabx_rd_length_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent RD-DMA engine read DMA transfer.
                                                                 This field will be updated when RD-DMA requests have been actually write committed to local DSP
                                                                 memory,
                                                                 which allows software to read (poll) the length field during the RD-DMA transfer to know how many
                                                                 128-bit chunks are now currently available to be read and used. This field is reset to 0 when at
                                                                 the start of a transfer or when a new slice starts for a multi-slice transfer. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent RD-DMA engine read DMA transfer.
                                                                 This field will be updated when RD-DMA requests have been actually write committed to local DSP
                                                                 memory,
                                                                 which allows software to read (poll) the length field during the RD-DMA transfer to know how many
                                                                 128-bit chunks are now currently available to be read and used. This field is reset to 0 when at
                                                                 the start of a transfer or when a new slice starts for a multi-slice transfer. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_rd_length_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_31        : 13;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent RD-DMA engine read DMA transfer.
                                                                 This field will be updated when RD-DMA requests have been actually write committed to local DSP
                                                                 memory,
                                                                 which allows software to read (poll) the length field during the RD-DMA transfer to know how many
                                                                 128-bit chunks are now currently available to be read and used. This field is reset to 0 when at
                                                                 the start of a transfer or when a new slice starts for a multi-slice transfer. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent RD-DMA engine read DMA transfer.
                                                                 This field will be updated when RD-DMA requests have been actually write committed to local DSP
                                                                 memory,
                                                                 which allows software to read (poll) the length field during the RD-DMA transfer to know how many
                                                                 128-bit chunks are now currently available to be read and used. This field is reset to 0 when at
                                                                 the start of a transfer or when a new slice starts for a multi-slice transfer. */
        uint64_t reserved_19_31        : 13;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_rd_length_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_31        : 14;
        uint64_t length                : 14; /**< [ 17:  4](RO/H) The actual 128-bit length of the most recent RD-DMA engine read DMA transfer.
                                                                 This field will be updated when the RD-DMA has been actually write committed to local DSP
                                                                 memory,
                                                                 which allows software to read (poll) the length field during the RD-DMA transfer to know how many
                                                                 128-bit chunks are now currently available to be read and used. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t length                : 14; /**< [ 17:  4](RO/H) The actual 128-bit length of the most recent RD-DMA engine read DMA transfer.
                                                                 This field will be updated when the RD-DMA has been actually write committed to local DSP
                                                                 memory,
                                                                 which allows software to read (poll) the length field during the RD-DMA transfer to know how many
                                                                 128-bit chunks are now currently available to be read and used. */
        uint64_t reserved_18_31        : 14;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_rd_length cavm_mdabx_rd_length_t;

static inline uint64_t CAVM_MDABX_RD_LENGTH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RD_LENGTH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100090ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400090ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RD_LENGTH", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RD_LENGTH(a) cavm_mdabx_rd_length_t
#define bustype_CAVM_MDABX_RD_LENGTH(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RD_LENGTH(a) "MDABX_RD_LENGTH"
#define busnum_CAVM_MDABX_RD_LENGTH(a) (a)
#define arguments_CAVM_MDABX_RD_LENGTH(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rd_limit
 *
 * MDAB Read DMA Limit Register
 * The maximum number of 128-bit sized chunks that the RD-DMA engine may write starting from the
 * 128-bit-aligned MDAB()_RD_ADDR. During Job_Type = LD_LCL* commands, hardware loads
 * the RD_ADDR/RD_LIMIT
 * registers directly from the Job Descriptor's DMA section(s).
 */
union cavm_mdabx_rd_limit
{
    uint64_t u;
    struct cavm_mdabx_rd_limit_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last RD-DMA slice which may be written to address MDAB()_RD_ADDR.
                                                                 DSP software may choose to segment the JD.RD-DMA data into multiple non-contiguous RD-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final RD-DMA sub-blk transfer.
                                                                 Each RD-DMA operation's LAST will indicate when the last segment (or slice) RD-DMA
                                                                 operation has been set up, to complete the JD.RD-DMA data transfer.
                                                                 SW_NOTE: For every new RD-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.RD-DMA data slice transfer. */
        uint64_t reserved_19_30        : 12;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W/H) "The maximum number of 128-bit chunks that the RD-DMA engine may write at address
                                                                 MDAB()_RD_ADDR.
                                                                 The JD.JCFG data typically will contain the total RD-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total RD-DMA transfer into multiples RD-DMA segments (or
                                                                 slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.RD-DMA data is detected), the RD-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W/H) "The maximum number of 128-bit chunks that the RD-DMA engine may write at address
                                                                 MDAB()_RD_ADDR.
                                                                 The JD.JCFG data typically will contain the total RD-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total RD-DMA transfer into multiples RD-DMA segments (or
                                                                 slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.RD-DMA data is detected), the RD-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_19_30        : 12;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last RD-DMA slice which may be written to address MDAB()_RD_ADDR.
                                                                 DSP software may choose to segment the JD.RD-DMA data into multiple non-contiguous RD-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final RD-DMA sub-blk transfer.
                                                                 Each RD-DMA operation's LAST will indicate when the last segment (or slice) RD-DMA
                                                                 operation has been set up, to complete the JD.RD-DMA data transfer.
                                                                 SW_NOTE: For every new RD-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.RD-DMA data slice transfer. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_rd_limit_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last RD-DMA slice which may be written to address MDAB()_RD_ADDR.
                                                                 DSP software may choose to segment the JD.RD-DMA data into multiple non-contiguous RD-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final RD-DMA sub-blk transfer.
                                                                 Each RD-DMA operation's LAST will indicate when the last segment (or slice) RD-DMA
                                                                 operation has been set up, to complete the JD.RD-DMA data transfer.
                                                                 SW_NOTE: For every new RD-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.RD-DMA data slice transfer. */
        uint64_t reserved_19_30        : 12;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W/H) "The maximum number of 128-bit chunks that the RD-DMA engine may write at address
                                                                 MDAB()_RD_ADDR.
                                                                 The JD.JCFG data typically will contain the total RD-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total RD-DMA transfer into multiples RD-DMA segments (or
                                                                 slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.RD-DMA data is detected), the RD-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W/H) "The maximum number of 128-bit chunks that the RD-DMA engine may write at address
                                                                 MDAB()_RD_ADDR.
                                                                 The JD.JCFG data typically will contain the total RD-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total RD-DMA transfer into multiples RD-DMA segments (or
                                                                 slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.RD-DMA data is detected), the RD-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_19_30        : 12;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last RD-DMA slice which may be written to address MDAB()_RD_ADDR.
                                                                 DSP software may choose to segment the JD.RD-DMA data into multiple non-contiguous RD-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final RD-DMA sub-blk transfer.
                                                                 Each RD-DMA operation's LAST will indicate when the last segment (or slice) RD-DMA
                                                                 operation has been set up, to complete the JD.RD-DMA data transfer.
                                                                 SW_NOTE: For every new RD-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.RD-DMA data slice transfer. */
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_rd_limit_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last RD-DMA slice which may be written to address MDAB()_RD_ADDR.
                                                                 DSP software may choose to segment the JD.RD-DMA data into multiple non-contiguous RD-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final RD-DMA sub-blk transfer.
                                                                 Each RD-DMA operation's LAST will indicate when the last segment (or slice) RD-DMA
                                                                 operation has been set up, to complete the JD.RD-DMA data transfer.
                                                                 SW_NOTE: For every new RD-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.RD-DMA data slice transfer. */
        uint64_t reserved_18_30        : 13;
        uint64_t limit                 : 14; /**< [ 17:  4](R/W/H) "The maximum number of 128-bit chunks that the RD-DMA engine may write at address
                                                                 MDAB()_RD_ADDR.
                                                                 The JD.JCFG data typically will contain the total RD-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total RD-DMA transfer into multiples RD-DMA segments (or
                                                                 slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.RD-DMA data is detected), the RD-DMA is done.

                                                                 D-TCM/DMEM: 0x0 - (0x03_FFFF \>\> 4)
                                                                 P-TCM/IMEM: (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4)
                                                                 CMP registers: (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4)

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t limit                 : 14; /**< [ 17:  4](R/W/H) "The maximum number of 128-bit chunks that the RD-DMA engine may write at address
                                                                 MDAB()_RD_ADDR.
                                                                 The JD.JCFG data typically will contain the total RD-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total RD-DMA transfer into multiples RD-DMA segments (or
                                                                 slices) using the LIMIT register. When either LIMIT has been reached (or if the last
                                                                 JD.RD-DMA data is detected), the RD-DMA is done.

                                                                 D-TCM/DMEM: 0x0 - (0x03_FFFF \>\> 4)
                                                                 P-TCM/IMEM: (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4)
                                                                 CMP registers: (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4)

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_18_30        : 13;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last RD-DMA slice which may be written to address MDAB()_RD_ADDR.
                                                                 DSP software may choose to segment the JD.RD-DMA data into multiple non-contiguous RD-DMA
                                                                 transfers to DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final RD-DMA sub-blk transfer.
                                                                 Each RD-DMA operation's LAST will indicate when the last segment (or slice) RD-DMA
                                                                 operation has been set up, to complete the JD.RD-DMA data transfer.
                                                                 SW_NOTE: For every new RD-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.RD-DMA data slice transfer. */
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_rd_limit cavm_mdabx_rd_limit_t;

static inline uint64_t CAVM_MDABX_RD_LIMIT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RD_LIMIT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100080ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400080ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RD_LIMIT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RD_LIMIT(a) cavm_mdabx_rd_limit_t
#define bustype_CAVM_MDABX_RD_LIMIT(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RD_LIMIT(a) "MDABX_RD_LIMIT"
#define busnum_CAVM_MDABX_RD_LIMIT(a) (a)
#define arguments_CAVM_MDABX_RD_LIMIT(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rd_next_addr
 *
 * MDAB Read DMA Next Address Register
 * The next address for multi slice DMA transfers. Indicates the first unused slice starting address.
 */
union cavm_mdabx_rd_next_addr
{
    uint32_t u;
    struct cavm_mdabx_rd_next_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t next_addr             : 27; /**< [ 30:  4](RO/H) The next 128b-aligned starting address to be used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory. This register is used to determine the address for unused slices. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t next_addr             : 27; /**< [ 30:  4](RO/H) The next 128b-aligned starting address to be used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory. This register is used to determine the address for unused slices. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_rd_next_addr_s cnf95xx; */
    struct cavm_mdabx_rd_next_addr_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_23_31        : 9;
        uint32_t next_addr             : 19; /**< [ 22:  4](RO/H) The next 128b-aligned starting address to be used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory. This register is used to determine the address for unused slices. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t next_addr             : 19; /**< [ 22:  4](RO/H) The next 128b-aligned starting address to be used by the RD-DMA engine when writing RD-DMA data to
                                                                 local DSP memory. This register is used to determine the address for unused slices. */
        uint32_t reserved_23_31        : 9;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_rd_next_addr cavm_mdabx_rd_next_addr_t;

static inline uint64_t CAVM_MDABX_RD_NEXT_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RD_NEXT_ADDR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100460ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400460ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RD_NEXT_ADDR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RD_NEXT_ADDR(a) cavm_mdabx_rd_next_addr_t
#define bustype_CAVM_MDABX_RD_NEXT_ADDR(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RD_NEXT_ADDR(a) "MDABX_RD_NEXT_ADDR"
#define busnum_CAVM_MDABX_RD_NEXT_ADDR(a) (a)
#define arguments_CAVM_MDABX_RD_NEXT_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rd_status
 *
 * MDAB Read DMA Status Register
 * Reports the status for the RD DMA engine.
 */
union cavm_mdabx_rd_status
{
    uint64_t u;
    struct cavm_mdabx_rd_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed RD-DMA operation.
                                                                 When DSP software writes START_BUSY=0-\>1, the RD-DMA engine will wait until the next
                                                                 available Job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_13_15        : 3;
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t post_ld_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a Load-Local job has completed (last LD-LCL micro-op completes).
                                                                 Cleared when a Normal job has completed. */
        uint64_t ld_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a Load-Local operation is active. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending RD-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent RD-DMA operation. */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last RD-DMA operation encountered an underflow. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last RD-DMA operation encountered an overflow. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last RD-DMA operation encountered an error. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last RD-DMA operation transferred the last word of the RD-DMA data from the
                                                                 job descriptor (JD.RD-DMA). */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a RD-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the RD-DMA engine starts its first
                                                                 RD-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job descriptor's read
                                                                 DMA section (JD.RD-DMA) for the next available job into the local memory starting at
                                                                 MDAB()_RD_ADDR, up to MDAB()_RD_ADDR+MDAB()_RD_LIMIT or when the last 128-bit word of the JD.RD-
                                                                 DMA section is
                                                                 transferred (whichever comes first).
                                                                 If the RD-DMA engine has already transferred part but not all of the JD.RD-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.RD-DMA
                                                                 section, or until it
                                                                 writes MDAB()_CFG_LIMIT for the LAST RD-DMA slice, whichever comes first. This bit is reset
                                                                 to zero when the
                                                                 RD-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
#else /* Word 0 - Little Endian */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job descriptor's read
                                                                 DMA section (JD.RD-DMA) for the next available job into the local memory starting at
                                                                 MDAB()_RD_ADDR, up to MDAB()_RD_ADDR+MDAB()_RD_LIMIT or when the last 128-bit word of the JD.RD-
                                                                 DMA section is
                                                                 transferred (whichever comes first).
                                                                 If the RD-DMA engine has already transferred part but not all of the JD.RD-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.RD-DMA
                                                                 section, or until it
                                                                 writes MDAB()_CFG_LIMIT for the LAST RD-DMA slice, whichever comes first. This bit is reset
                                                                 to zero when the
                                                                 RD-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the RD-DMA engine starts its first
                                                                 RD-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a RD-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last RD-DMA operation transferred the last word of the RD-DMA data from the
                                                                 job descriptor (JD.RD-DMA). */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last RD-DMA operation encountered an error. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last RD-DMA operation encountered an overflow. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last RD-DMA operation encountered an underflow. */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent RD-DMA operation. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending RD-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t ld_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a Load-Local operation is active. */
        uint64_t post_ld_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a Load-Local job has completed (last LD-LCL micro-op completes).
                                                                 Cleared when a Normal job has completed. */
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed RD-DMA operation.
                                                                 When DSP software writes START_BUSY=0-\>1, the RD-DMA engine will wait until the next
                                                                 available Job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_rd_status_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed RD-DMA operation.
                                                                 When DSP software writes START_BUSY=0-\>1, the RD-DMA engine will wait until the next
                                                                 available Job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_13_15        : 3;
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t post_ld_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a Load-Local job has completed (last LD-LCL micro-op completes).
                                                                 Cleared when a Normal job has completed. */
        uint64_t ld_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a Load-Local operation is active. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending RD-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent RD-DMA operation. */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last RD-DMA operation encountered an underflow. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last RD-DMA operation encountered an overflow. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last RD-DMA operation encountered an error. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last RD-DMA operation transferred the last word of the RD-DMA data from the
                                                                 job descriptor (JD.RD-DMA). */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a RD-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the RD-DMA engine starts its first
                                                                 RD-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job descriptor's read
                                                                 DMA section (JD.RD-DMA) for the next available job into the local memory starting at
                                                                 MDAB()_RD_ADDR, up to MDAB()_RD_ADDR+MDAB()_RD_LIMIT or when the last 128-bit word of the JD.RD-
                                                                 DMA section is
                                                                 transferred (whichever comes first).
                                                                 If the RD-DMA engine has already transferred part but not all of the JD.RD-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.RD-DMA
                                                                 section, or until it
                                                                 writes MDAB()_CFG_LIMIT for the LAST RD-DMA slice, whichever comes first. This bit is reset
                                                                 to zero when the
                                                                 RD-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
#else /* Word 0 - Little Endian */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job descriptor's read
                                                                 DMA section (JD.RD-DMA) for the next available job into the local memory starting at
                                                                 MDAB()_RD_ADDR, up to MDAB()_RD_ADDR+MDAB()_RD_LIMIT or when the last 128-bit word of the JD.RD-
                                                                 DMA section is
                                                                 transferred (whichever comes first).
                                                                 If the RD-DMA engine has already transferred part but not all of the JD.RD-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.RD-DMA
                                                                 section, or until it
                                                                 writes MDAB()_CFG_LIMIT for the LAST RD-DMA slice, whichever comes first. This bit is reset
                                                                 to zero when the
                                                                 RD-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the RD-DMA engine starts its first
                                                                 RD-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a RD-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last RD-DMA operation transferred the last word of the RD-DMA data from the
                                                                 job descriptor (JD.RD-DMA). */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last RD-DMA operation encountered an error. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last RD-DMA operation encountered an overflow. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last RD-DMA operation encountered an underflow. */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent RD-DMA operation. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending RD-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t ld_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a Load-Local operation is active. */
        uint64_t post_ld_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a Load-Local job has completed (last LD-LCL micro-op completes).
                                                                 Cleared when a Normal job has completed. */
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed RD-DMA operation.
                                                                 When DSP software writes START_BUSY=0-\>1, the RD-DMA engine will wait until the next
                                                                 available Job has been enqueued, at which point the JOB_TAG will be latched in. */
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_rd_status_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed RD DMA operation.
                                                                 When DSP software writes [START_BUSY] = 0 -\> 1, the RD DMA engine will wait until the next
                                                                 available job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_13_15        : 3;
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t post_ld_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a load local job has completed (last LOAD-LCL micro-op completes).
                                                                 Cleared when a normal job has completed. */
        uint64_t ld_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a load local operation is active. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending RD DMA operation. Valid only when [START_BUSY] == 0 and
                                                                 [DMA_PENDING] == 1. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent RD DMA operation. */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last RD DMA operation encountered an underflow. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last RD DMA operation encountered an overflow. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last RD DMA operation encountered an error. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last RD DMA operation transferred the last word of the RD DMA data from the
                                                                 job descriptor (JD.RD-DMA). */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a RD DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the RD-DMA engine starts its first
                                                                 RD-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job descriptor's read
                                                                 DMA section (JD.RD-DMA) for the next available job into the local memory starting at
                                                                 MDAB()_RD_ADDR, up to MDAB()_RD_ADDR+MDAB()_RD_LIMIT or when the last 128-bit word of the JD.RD-
                                                                 DMA section is
                                                                 transferred (whichever comes first).
                                                                 If the RD-DMA engine has already transferred part but not all of the JD.RD-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.RD-DMA
                                                                 section, or until it
                                                                 writes MDAB()_CFG_LIMIT for the LAST RD-DMA slice, whichever comes first. This bit is reset
                                                                 to zero when the
                                                                 RD-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
#else /* Word 0 - Little Endian */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will write the job descriptor's read
                                                                 DMA section (JD.RD-DMA) for the next available job into the local memory starting at
                                                                 MDAB()_RD_ADDR, up to MDAB()_RD_ADDR+MDAB()_RD_LIMIT or when the last 128-bit word of the JD.RD-
                                                                 DMA section is
                                                                 transferred (whichever comes first).
                                                                 If the RD-DMA engine has already transferred part but not all of the JD.RD-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.RD-DMA
                                                                 section, or until it
                                                                 writes MDAB()_CFG_LIMIT for the LAST RD-DMA slice, whichever comes first. This bit is reset
                                                                 to zero when the
                                                                 RD-DMA engine has completed the transfer and is ready to be re-initialized for another
                                                                 transfer. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the RD-DMA engine starts its first
                                                                 RD-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a RD DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last RD DMA operation transferred the last word of the RD DMA data from the
                                                                 job descriptor (JD.RD-DMA). */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last RD DMA operation encountered an error. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last RD DMA operation encountered an overflow. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last RD DMA operation encountered an underflow. */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent RD DMA operation. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending RD DMA operation. Valid only when [START_BUSY] == 0 and
                                                                 [DMA_PENDING] == 1. */
        uint64_t ld_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a load local operation is active. */
        uint64_t post_ld_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a load local job has completed (last LOAD-LCL micro-op completes).
                                                                 Cleared when a normal job has completed. */
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed RD DMA operation.
                                                                 When DSP software writes [START_BUSY] = 0 -\> 1, the RD DMA engine will wait until the next
                                                                 available job has been enqueued, at which point the JOB_TAG will be latched in. */
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_rd_status cavm_mdabx_rd_status_t;

static inline uint64_t CAVM_MDABX_RD_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RD_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100060ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400060ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RD_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RD_STATUS(a) cavm_mdabx_rd_status_t
#define bustype_CAVM_MDABX_RD_STATUS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RD_STATUS(a) "MDABX_RD_STATUS"
#define busnum_CAVM_MDABX_RD_STATUS(a) (a)
#define arguments_CAVM_MDABX_RD_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rmp_dflt_win_addr_hi
 *
 * MDAB System Memory Default Remap Address High Register
 * Define the default remap address bits [52:32].
 */
union cavm_mdabx_rmp_dflt_win_addr_hi
{
    uint32_t u;
    struct cavm_mdabx_rmp_dflt_win_addr_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_21_31        : 11;
        uint32_t haddr                 : 21; /**< [ 20:  0](R/W) This Register Value defined the override value of address bits[52:32] of the
                                                                 address trgeting the System memory. */
#else /* Word 0 - Little Endian */
        uint32_t haddr                 : 21; /**< [ 20:  0](R/W) This Register Value defined the override value of address bits[52:32] of the
                                                                 address trgeting the System memory. */
        uint32_t reserved_21_31        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_rmp_dflt_win_addr_hi_s cn; */
};
typedef union cavm_mdabx_rmp_dflt_win_addr_hi cavm_mdabx_rmp_dflt_win_addr_hi_t;

static inline uint64_t CAVM_MDABX_RMP_DFLT_WIN_ADDR_HI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RMP_DFLT_WIN_ADDR_HI(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444008c0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RMP_DFLT_WIN_ADDR_HI", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RMP_DFLT_WIN_ADDR_HI(a) cavm_mdabx_rmp_dflt_win_addr_hi_t
#define bustype_CAVM_MDABX_RMP_DFLT_WIN_ADDR_HI(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RMP_DFLT_WIN_ADDR_HI(a) "MDABX_RMP_DFLT_WIN_ADDR_HI"
#define busnum_CAVM_MDABX_RMP_DFLT_WIN_ADDR_HI(a) (a)
#define arguments_CAVM_MDABX_RMP_DFLT_WIN_ADDR_HI(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rmp_dflt_win_addr_low
 *
 * MDAB System Memory Default Remap Address Low Register
 * Define the DefaultRemap address bits [31:0].
 */
union cavm_mdabx_rmp_dflt_win_addr_low
{
    uint32_t u;
    struct cavm_mdabx_rmp_dflt_win_addr_low_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t laddr                 : 20; /**< [ 31: 12](R/W) This Register Value defined the override value of address bits[31:20] of the
                                                                 address trgeting the System memory. */
        uint32_t reserved_0_11         : 12;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_11         : 12;
        uint32_t laddr                 : 20; /**< [ 31: 12](R/W) This Register Value defined the override value of address bits[31:20] of the
                                                                 address trgeting the System memory. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_rmp_dflt_win_addr_low_s cn; */
};
typedef union cavm_mdabx_rmp_dflt_win_addr_low cavm_mdabx_rmp_dflt_win_addr_low_t;

static inline uint64_t CAVM_MDABX_RMP_DFLT_WIN_ADDR_LOW(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RMP_DFLT_WIN_ADDR_LOW(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444008d0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RMP_DFLT_WIN_ADDR_LOW", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RMP_DFLT_WIN_ADDR_LOW(a) cavm_mdabx_rmp_dflt_win_addr_low_t
#define bustype_CAVM_MDABX_RMP_DFLT_WIN_ADDR_LOW(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RMP_DFLT_WIN_ADDR_LOW(a) "MDABX_RMP_DFLT_WIN_ADDR_LOW"
#define busnum_CAVM_MDABX_RMP_DFLT_WIN_ADDR_LOW(a) (a)
#define arguments_CAVM_MDABX_RMP_DFLT_WIN_ADDR_LOW(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rmp_win_addr_hi
 *
 * MDAB System Memory Remap Address High Register
 * Define the remap address bits [52:32].
 */
union cavm_mdabx_rmp_win_addr_hi
{
    uint32_t u;
    struct cavm_mdabx_rmp_win_addr_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_21_31        : 11;
        uint32_t haddr                 : 21; /**< [ 20:  0](R/W) This Register Value defined the override value of address bits[52:32] of the
                                                                 address trgeting the System memory. */
#else /* Word 0 - Little Endian */
        uint32_t haddr                 : 21; /**< [ 20:  0](R/W) This Register Value defined the override value of address bits[52:32] of the
                                                                 address trgeting the System memory. */
        uint32_t reserved_21_31        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_rmp_win_addr_hi_s cn; */
};
typedef union cavm_mdabx_rmp_win_addr_hi cavm_mdabx_rmp_win_addr_hi_t;

static inline uint64_t CAVM_MDABX_RMP_WIN_ADDR_HI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RMP_WIN_ADDR_HI(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400880ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RMP_WIN_ADDR_HI", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RMP_WIN_ADDR_HI(a) cavm_mdabx_rmp_win_addr_hi_t
#define bustype_CAVM_MDABX_RMP_WIN_ADDR_HI(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RMP_WIN_ADDR_HI(a) "MDABX_RMP_WIN_ADDR_HI"
#define busnum_CAVM_MDABX_RMP_WIN_ADDR_HI(a) (a)
#define arguments_CAVM_MDABX_RMP_WIN_ADDR_HI(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rmp_win_addr_low
 *
 * MDAB System Memory Remap Address Low Register
 * Define the remap address bits [31:0].
 */
union cavm_mdabx_rmp_win_addr_low
{
    uint32_t u;
    struct cavm_mdabx_rmp_win_addr_low_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t laddr                 : 20; /**< [ 31: 12](R/W) This Register Value defined the override value of address bits[31:20] of the
                                                                 address trgeting the System memory. */
        uint32_t reserved_0_11         : 12;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_11         : 12;
        uint32_t laddr                 : 20; /**< [ 31: 12](R/W) This Register Value defined the override value of address bits[31:20] of the
                                                                 address trgeting the System memory. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_rmp_win_addr_low_s cn; */
};
typedef union cavm_mdabx_rmp_win_addr_low cavm_mdabx_rmp_win_addr_low_t;

static inline uint64_t CAVM_MDABX_RMP_WIN_ADDR_LOW(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RMP_WIN_ADDR_LOW(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400890ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RMP_WIN_ADDR_LOW", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RMP_WIN_ADDR_LOW(a) cavm_mdabx_rmp_win_addr_low_t
#define bustype_CAVM_MDABX_RMP_WIN_ADDR_LOW(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RMP_WIN_ADDR_LOW(a) "MDABX_RMP_WIN_ADDR_LOW"
#define busnum_CAVM_MDABX_RMP_WIN_ADDR_LOW(a) (a)
#define arguments_CAVM_MDABX_RMP_WIN_ADDR_LOW(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rmp_win_base
 *
 * MDAB System Memory Remap Window Base Addr Register
 * Sets the Base Address of the System Memory Remap window.
 */
union cavm_mdabx_rmp_win_base
{
    uint32_t u;
    struct cavm_mdabx_rmp_win_base_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t baddr                 : 28; /**< [ 31:  4](R/W) Base Address of the Remap Window. */
        uint32_t reserved_1_3          : 3;
        uint32_t rmp_win_en            : 1;  /**< [  0:  0](R/W) Enable the SYSMEM Remap window.
                                                                 0 = Disable.
                                                                 1 = Enable. */
#else /* Word 0 - Little Endian */
        uint32_t rmp_win_en            : 1;  /**< [  0:  0](R/W) Enable the SYSMEM Remap window.
                                                                 0 = Disable.
                                                                 1 = Enable. */
        uint32_t reserved_1_3          : 3;
        uint32_t baddr                 : 28; /**< [ 31:  4](R/W) Base Address of the Remap Window. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_rmp_win_base_s cn; */
};
typedef union cavm_mdabx_rmp_win_base cavm_mdabx_rmp_win_base_t;

static inline uint64_t CAVM_MDABX_RMP_WIN_BASE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RMP_WIN_BASE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444008a0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RMP_WIN_BASE", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RMP_WIN_BASE(a) cavm_mdabx_rmp_win_base_t
#define bustype_CAVM_MDABX_RMP_WIN_BASE(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RMP_WIN_BASE(a) "MDABX_RMP_WIN_BASE"
#define busnum_CAVM_MDABX_RMP_WIN_BASE(a) (a)
#define arguments_CAVM_MDABX_RMP_WIN_BASE(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_rmp_win_size
 *
 * MDAB System Memory Remap Window Size Register
 * Sets the Base Address of the System Memory Remap window.
 */
union cavm_mdabx_rmp_win_size
{
    uint32_t u;
    struct cavm_mdabx_rmp_win_size_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t wsize                 : 32; /**< [ 31:  0](R/W) Remap window Size. */
#else /* Word 0 - Little Endian */
        uint32_t wsize                 : 32; /**< [ 31:  0](R/W) Remap window Size. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_rmp_win_size_s cn; */
};
typedef union cavm_mdabx_rmp_win_size cavm_mdabx_rmp_win_size_t;

static inline uint64_t CAVM_MDABX_RMP_WIN_SIZE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_RMP_WIN_SIZE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444008b0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_RMP_WIN_SIZE", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_RMP_WIN_SIZE(a) cavm_mdabx_rmp_win_size_t
#define bustype_CAVM_MDABX_RMP_WIN_SIZE(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_RMP_WIN_SIZE(a) "MDABX_RMP_WIN_SIZE"
#define busnum_CAVM_MDABX_RMP_WIN_SIZE(a) (a)
#define arguments_CAVM_MDABX_RMP_WIN_SIZE(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_sec_int_ena_w1c
 *
 * MDAB Secondary Interrupt Enable CLEAR Register
 * This register is used to clear MDAB Secondary interrupt enables for the MDAB_SEC_INT_SUM bits.
 */
union cavm_mdabx_sec_int_ena_w1c
{
    uint32_t u;
    struct cavm_mdabx_sec_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W1C/H) Reads or clears the enable for the MBAD()_SEC_INT_SUM[CTI_INT] interrupt bit. */
        uint32_t reserved_2_7          : 6;
        uint32_t qman_int              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears the enable for the MBAD()_SEC_INT_SUM[QMAN_INT] interrupt bit. */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enables for the MBAD()_SEC_INT_SUM[SGI]. */
#else /* Word 0 - Little Endian */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enables for the MBAD()_SEC_INT_SUM[SGI]. */
        uint32_t qman_int              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears the enable for the MBAD()_SEC_INT_SUM[QMAN_INT] interrupt bit. */
        uint32_t reserved_2_7          : 6;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W1C/H) Reads or clears the enable for the MBAD()_SEC_INT_SUM[CTI_INT] interrupt bit. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_sec_int_ena_w1c_s cn; */
};
typedef union cavm_mdabx_sec_int_ena_w1c cavm_mdabx_sec_int_ena_w1c_t;

static inline uint64_t CAVM_MDABX_SEC_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SEC_INT_ENA_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a20ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SEC_INT_ENA_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SEC_INT_ENA_W1C(a) cavm_mdabx_sec_int_ena_w1c_t
#define bustype_CAVM_MDABX_SEC_INT_ENA_W1C(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SEC_INT_ENA_W1C(a) "MDABX_SEC_INT_ENA_W1C"
#define busnum_CAVM_MDABX_SEC_INT_ENA_W1C(a) (a)
#define arguments_CAVM_MDABX_SEC_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_sec_int_ena_w1s
 *
 * MDAB Secondary Interrupt Enable SET Register
 * This register is used to set MDAB Secondary interrupt enables for the MDAB_SEC_INT_SUM bits.
 */
union cavm_mdabx_sec_int_ena_w1s
{
    uint32_t u;
    struct cavm_mdabx_sec_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the enable for the MBAD()_SEC_INT_SUM[CTI_INT] interrupt bit. */
        uint32_t reserved_2_7          : 6;
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the enable for the MBAD()_SEC_INT_SUM[QMAN_IRQ] interrupt bit. */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enables for the MBAD()_SEC_INT_SUM[SGI]. */
#else /* Word 0 - Little Endian */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enables for the MBAD()_SEC_INT_SUM[SGI]. */
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the enable for the MBAD()_SEC_INT_SUM[QMAN_IRQ] interrupt bit. */
        uint32_t reserved_2_7          : 6;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the enable for the MBAD()_SEC_INT_SUM[CTI_INT] interrupt bit. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_sec_int_ena_w1s_s cn; */
};
typedef union cavm_mdabx_sec_int_ena_w1s cavm_mdabx_sec_int_ena_w1s_t;

static inline uint64_t CAVM_MDABX_SEC_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SEC_INT_ENA_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a30ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SEC_INT_ENA_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SEC_INT_ENA_W1S(a) cavm_mdabx_sec_int_ena_w1s_t
#define bustype_CAVM_MDABX_SEC_INT_ENA_W1S(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SEC_INT_ENA_W1S(a) "MDABX_SEC_INT_ENA_W1S"
#define busnum_CAVM_MDABX_SEC_INT_ENA_W1S(a) (a)
#define arguments_CAVM_MDABX_SEC_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_sec_int_intvec_ena
 *
 * MDAB Secondary Interrupt INTVEC Enable Register
 * This register is used to Enable Reporting MDAB Secondary interrupts  To DSP INT Vector.
 */
union cavm_mdabx_sec_int_intvec_ena
{
    uint32_t u;
    struct cavm_mdabx_sec_int_intvec_ena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W) If Enable, CTI_INT event is reported to DSP INTVEC. 0x1 - Enable, 0x0 - Disable */
        uint32_t reserved_2_7          : 6;
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W) If Enable, QMAN_IRQ event is reported to DSP INTVEC. 0x1 - Enable, 0x0 - Disable */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W) If Enable, SGO event is reported to DSP INTVEC. 0x1 - Enable, 0x0 - Disable */
#else /* Word 0 - Little Endian */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W) If Enable, SGO event is reported to DSP INTVEC. 0x1 - Enable, 0x0 - Disable */
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W) If Enable, QMAN_IRQ event is reported to DSP INTVEC. 0x1 - Enable, 0x0 - Disable */
        uint32_t reserved_2_7          : 6;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W) If Enable, CTI_INT event is reported to DSP INTVEC. 0x1 - Enable, 0x0 - Disable */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_sec_int_intvec_ena_s cn; */
};
typedef union cavm_mdabx_sec_int_intvec_ena cavm_mdabx_sec_int_intvec_ena_t;

static inline uint64_t CAVM_MDABX_SEC_INT_INTVEC_ENA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SEC_INT_INTVEC_ENA(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a50ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SEC_INT_INTVEC_ENA", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SEC_INT_INTVEC_ENA(a) cavm_mdabx_sec_int_intvec_ena_t
#define bustype_CAVM_MDABX_SEC_INT_INTVEC_ENA(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SEC_INT_INTVEC_ENA(a) "MDABX_SEC_INT_INTVEC_ENA"
#define busnum_CAVM_MDABX_SEC_INT_INTVEC_ENA(a) (a)
#define arguments_CAVM_MDABX_SEC_INT_INTVEC_ENA(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_sec_int_nmi_ena
 *
 * MDAB Secondary Interrupt NMI Enable Register
 * This register is used to Enable Reporting MDAB Secondary interrupts  To DSP NMI.
 */
union cavm_mdabx_sec_int_nmi_ena
{
    uint32_t u;
    struct cavm_mdabx_sec_int_nmi_ena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W) If Enable, CTI_INT event is reported to DSP NMI. 0x1 - Enable, 0x0 - Disable */
        uint32_t reserved_2_7          : 6;
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W) If Enable, QMAN_IRQ event is reported to DSP NMI. 0x1 - Enable, 0x0 - Disable */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W) If Enable, SGO event is reported to DSP NMI. 0x1 - Enable, 0x0 - Disable */
#else /* Word 0 - Little Endian */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W) If Enable, SGO event is reported to DSP NMI. 0x1 - Enable, 0x0 - Disable */
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W) If Enable, QMAN_IRQ event is reported to DSP NMI. 0x1 - Enable, 0x0 - Disable */
        uint32_t reserved_2_7          : 6;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W) If Enable, CTI_INT event is reported to DSP NMI. 0x1 - Enable, 0x0 - Disable */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_sec_int_nmi_ena_s cn; */
};
typedef union cavm_mdabx_sec_int_nmi_ena cavm_mdabx_sec_int_nmi_ena_t;

static inline uint64_t CAVM_MDABX_SEC_INT_NMI_ENA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SEC_INT_NMI_ENA(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a60ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SEC_INT_NMI_ENA", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SEC_INT_NMI_ENA(a) cavm_mdabx_sec_int_nmi_ena_t
#define bustype_CAVM_MDABX_SEC_INT_NMI_ENA(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SEC_INT_NMI_ENA(a) "MDABX_SEC_INT_NMI_ENA"
#define busnum_CAVM_MDABX_SEC_INT_NMI_ENA(a) (a)
#define arguments_CAVM_MDABX_SEC_INT_NMI_ENA(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_sec_int_sum_w1c
 *
 * MDAB Secondary Interrupt Summary Register
 * This register reports the Seconday interrupt sources status for the MDAB.
 * Software clears individual interrupts by writing one to the corresponding bit.
 */
union cavm_mdabx_sec_int_sum_w1c
{
    uint32_t u;
    struct cavm_mdabx_sec_int_sum_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cti_trigger           : 1;  /**< [  8:  8](R/W1C/H) Indicates CTI Event has occured. */
        uint32_t reserved_2_7          : 6;
        uint32_t qmap_irq              : 1;  /**< [  1:  1](R/W1C/H) Indicates QMAN IRQ event has occured. */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W1C/H) SW Generated Interrupt. */
#else /* Word 0 - Little Endian */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W1C/H) SW Generated Interrupt. */
        uint32_t qmap_irq              : 1;  /**< [  1:  1](R/W1C/H) Indicates QMAN IRQ event has occured. */
        uint32_t reserved_2_7          : 6;
        uint32_t cti_trigger           : 1;  /**< [  8:  8](R/W1C/H) Indicates CTI Event has occured. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_sec_int_sum_w1c_s cn; */
};
typedef union cavm_mdabx_sec_int_sum_w1c cavm_mdabx_sec_int_sum_w1c_t;

static inline uint64_t CAVM_MDABX_SEC_INT_SUM_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SEC_INT_SUM_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a00ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SEC_INT_SUM_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SEC_INT_SUM_W1C(a) cavm_mdabx_sec_int_sum_w1c_t
#define bustype_CAVM_MDABX_SEC_INT_SUM_W1C(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SEC_INT_SUM_W1C(a) "MDABX_SEC_INT_SUM_W1C"
#define busnum_CAVM_MDABX_SEC_INT_SUM_W1C(a) (a)
#define arguments_CAVM_MDABX_SEC_INT_SUM_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_sec_int_sum_w1s
 *
 * MDAB Secondary Interrupt Summary SET Register
 * This register is used to artificially set MDAB interrupts described in
 * MDAB_SEC_INT_SUM (for software Debug/Test)
 */
union cavm_mdabx_sec_int_sum_w1s
{
    uint32_t u;
    struct cavm_mdabx_sec_int_sum_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the MBAD()_SEC_INT_SUM[CTI_INT] interrupt bit. */
        uint32_t reserved_2_7          : 6;
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the MBAD()_SEC_INT_SUM[QMAN_INT] interrupt bit. */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets the MBAD()_SEC_INT_SUM[SGI]. */
#else /* Word 0 - Little Endian */
        uint32_t sgi                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets the MBAD()_SEC_INT_SUM[SGI]. */
        uint32_t qman_irq              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets the MBAD()_SEC_INT_SUM[QMAN_INT] interrupt bit. */
        uint32_t reserved_2_7          : 6;
        uint32_t cti_int               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets the MBAD()_SEC_INT_SUM[CTI_INT] interrupt bit. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_sec_int_sum_w1s_s cn; */
};
typedef union cavm_mdabx_sec_int_sum_w1s cavm_mdabx_sec_int_sum_w1s_t;

static inline uint64_t CAVM_MDABX_SEC_INT_SUM_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SEC_INT_SUM_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400a10ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SEC_INT_SUM_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SEC_INT_SUM_W1S(a) cavm_mdabx_sec_int_sum_w1s_t
#define bustype_CAVM_MDABX_SEC_INT_SUM_W1S(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SEC_INT_SUM_W1S(a) "MDABX_SEC_INT_SUM_W1S"
#define busnum_CAVM_MDABX_SEC_INT_SUM_W1S(a) (a)
#define arguments_CAVM_MDABX_SEC_INT_SUM_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_smem_bar
 *
 * MDAB Shared Memory Base Address Register
 * Sets the Base address of the shared Memory address space.
 */
union cavm_mdabx_smem_bar
{
    uint32_t u;
    struct cavm_mdabx_smem_bar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t baddr                 : 32; /**< [ 31:  0](R/W) Base address */
#else /* Word 0 - Little Endian */
        uint32_t baddr                 : 32; /**< [ 31:  0](R/W) Base address */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_smem_bar_s cn; */
};
typedef union cavm_mdabx_smem_bar cavm_mdabx_smem_bar_t;

static inline uint64_t CAVM_MDABX_SMEM_BAR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SMEM_BAR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400800ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SMEM_BAR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SMEM_BAR(a) cavm_mdabx_smem_bar_t
#define bustype_CAVM_MDABX_SMEM_BAR(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SMEM_BAR(a) "MDABX_SMEM_BAR"
#define busnum_CAVM_MDABX_SMEM_BAR(a) (a)
#define arguments_CAVM_MDABX_SMEM_BAR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_smem_bar_size
 *
 * MDAB Shared Memory Address Space size Register
 * Sets the Window Size, in bytes, minus 1. Example, for 1MByte window set this resiger
 * to 0x000F_FFFF.
 */
union cavm_mdabx_smem_bar_size
{
    uint32_t u;
    struct cavm_mdabx_smem_bar_size_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bsize                 : 32; /**< [ 31:  0](R/W) BAR Size. */
#else /* Word 0 - Little Endian */
        uint32_t bsize                 : 32; /**< [ 31:  0](R/W) BAR Size. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_smem_bar_size_s cn; */
};
typedef union cavm_mdabx_smem_bar_size cavm_mdabx_smem_bar_size_t;

static inline uint64_t CAVM_MDABX_SMEM_BAR_SIZE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SMEM_BAR_SIZE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400810ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SMEM_BAR_SIZE", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SMEM_BAR_SIZE(a) cavm_mdabx_smem_bar_size_t
#define bustype_CAVM_MDABX_SMEM_BAR_SIZE(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SMEM_BAR_SIZE(a) "MDABX_SMEM_BAR_SIZE"
#define busnum_CAVM_MDABX_SMEM_BAR_SIZE(a) (a)
#define arguments_CAVM_MDABX_SMEM_BAR_SIZE(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_sysmem_bar
 *
 * MDAB System Memory Base Address Register
 * Sets the Base address of the System Memory address space.
 */
union cavm_mdabx_sysmem_bar
{
    uint32_t u;
    struct cavm_mdabx_sysmem_bar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t baddr                 : 32; /**< [ 31:  0](R/W) Base address */
#else /* Word 0 - Little Endian */
        uint32_t baddr                 : 32; /**< [ 31:  0](R/W) Base address */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_sysmem_bar_s cn; */
};
typedef union cavm_mdabx_sysmem_bar cavm_mdabx_sysmem_bar_t;

static inline uint64_t CAVM_MDABX_SYSMEM_BAR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SYSMEM_BAR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400820ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SYSMEM_BAR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SYSMEM_BAR(a) cavm_mdabx_sysmem_bar_t
#define bustype_CAVM_MDABX_SYSMEM_BAR(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SYSMEM_BAR(a) "MDABX_SYSMEM_BAR"
#define busnum_CAVM_MDABX_SYSMEM_BAR(a) (a)
#define arguments_CAVM_MDABX_SYSMEM_BAR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_sysmem_bar_size
 *
 * MDAB System Memory Address Space size Register
 * Sets the Size of the System Memory BAR.
 */
union cavm_mdabx_sysmem_bar_size
{
    uint32_t u;
    struct cavm_mdabx_sysmem_bar_size_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bsize                 : 32; /**< [ 31:  0](R/W) BAR Size. */
#else /* Word 0 - Little Endian */
        uint32_t bsize                 : 32; /**< [ 31:  0](R/W) BAR Size. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_sysmem_bar_size_s cn; */
};
typedef union cavm_mdabx_sysmem_bar_size cavm_mdabx_sysmem_bar_size_t;

static inline uint64_t CAVM_MDABX_SYSMEM_BAR_SIZE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_SYSMEM_BAR_SIZE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400830ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_SYSMEM_BAR_SIZE", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_SYSMEM_BAR_SIZE(a) cavm_mdabx_sysmem_bar_size_t
#define bustype_CAVM_MDABX_SYSMEM_BAR_SIZE(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_SYSMEM_BAR_SIZE(a) "MDABX_SYSMEM_BAR_SIZE"
#define busnum_CAVM_MDABX_SYSMEM_BAR_SIZE(a) (a)
#define arguments_CAVM_MDABX_SYSMEM_BAR_SIZE(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_wr_addr
 *
 * MDAB Write DMA Address Register
 * The starting address used by the WR-DMA engine when reading WR-DMA data from local DSP memory.
 * During Job_Type = ST_LCL* commands, hardware loads the WR_ADDR/WR_LIMIT registers directly.
 */
union cavm_mdabx_wr_addr
{
    uint64_t u;
    struct cavm_mdabx_wr_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31_63        : 33;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W/H) The 128b-aligned starting address used by the WR-DMA engine when reading WR-DMA data from
                                                                 local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4)
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4)
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines WHICH DSP Memory space
                                                                 (0:DMEM/1:IMEM) */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W/H) The 128b-aligned starting address used by the WR-DMA engine when reading WR-DMA data from
                                                                 local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4)
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4)
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines WHICH DSP Memory space
                                                                 (0:DMEM/1:IMEM) */
        uint64_t reserved_31_63        : 33;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_wr_addr_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31           : 1;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W/H) The 128b-aligned starting address used by the WR-DMA engine when reading WR-DMA data from
                                                                 local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4)
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4)
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines WHICH DSP Memory space
                                                                 (0:DMEM/1:IMEM) */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 27; /**< [ 30:  4](R/W/H) The 128b-aligned starting address used by the WR-DMA engine when reading WR-DMA data from
                                                                 local DSP memory.
                                                                 When ADDR[30]=1(IMEM):
                                                                    For MBP32 (256KB IMEM): Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4003.FFFF \>\> 4)
                                                                    For SBP (64KB IMEM):  Valid 128b-aligned address range = (0x4000.0000 \>\> 4) -
                                                                 (0x4000.FFFF \>\> 4)
                                                                 When ADDR[30]=0(DMEM):
                                                                    For MBP32 (128KB DMEM): Valid 128b-aligned address range = (0x3FFE.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                    For SBP (256KB DMEM): Valid 128b-aligned address range = (0x3FFC.0000 \>\> 4) -
                                                                 (0x3FFF.FFFF \>\> 4)
                                                                 NOTE: In the I/D MEM address decoding scheme, ADDR[30] determines WHICH DSP Memory space
                                                                 (0:DMEM/1:IMEM) */
        uint64_t reserved_31           : 1;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_wr_addr_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_31        : 9;
        uint64_t addr                  : 19; /**< [ 22:  4](R/W/H) The 128b-aligned starting address used by the WR-DMA engine when reading WR-DMA data from
                                                                 local DSP memory.
                                                                 When ADDR[22:21] == 2'b00 (D-TCM/DMEM):
                                                                   Valid 128b-aligned address range = 0x0 - (0x03_FFFF \>\> 4)
                                                                 When ADDR[22:21] == 2'b01 (P-TCM/IMEM):
                                                                   Valid 128b-aligned address range = (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4)
                                                                 When ADDR[22:21] == 2'b10 (CMP registers):
                                                                   Valid 128b-aligned address range = (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4) */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 19; /**< [ 22:  4](R/W/H) The 128b-aligned starting address used by the WR-DMA engine when reading WR-DMA data from
                                                                 local DSP memory.
                                                                 When ADDR[22:21] == 2'b00 (D-TCM/DMEM):
                                                                   Valid 128b-aligned address range = 0x0 - (0x03_FFFF \>\> 4)
                                                                 When ADDR[22:21] == 2'b01 (P-TCM/IMEM):
                                                                   Valid 128b-aligned address range = (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4)
                                                                 When ADDR[22:21] == 2'b10 (CMP registers):
                                                                   Valid 128b-aligned address range = (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4) */
        uint64_t reserved_23_31        : 9;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_wr_addr cavm_mdabx_wr_addr_t;

static inline uint64_t CAVM_MDABX_WR_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_WR_ADDR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441000b0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444000b0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_WR_ADDR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_WR_ADDR(a) cavm_mdabx_wr_addr_t
#define bustype_CAVM_MDABX_WR_ADDR(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_WR_ADDR(a) "MDABX_WR_ADDR"
#define busnum_CAVM_MDABX_WR_ADDR(a) (a)
#define arguments_CAVM_MDABX_WR_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_wr_error_sts
 *
 * INTERNAL: MDAB Write Error Status Register
 *
 * This register contains DSP slave write error status signals.
 */
union cavm_mdabx_wr_error_sts
{
    uint32_t u;
    struct cavm_mdabx_wr_error_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_25_31        : 7;
        uint32_t addr                  : 21; /**< [ 24:  4](RO/H) When a DSP slave write access causes the SLVERR error bit to be set, this field captures the
                                                                 failing address. */
        uint32_t error_src             : 3;  /**< [  3:  1](RO/H) This field indicates the source of the transaction that caused the recorded error.
                                                                 000: WDM
                                                                 001: RDM
                                                                 010: CDM
                                                                 011: CSR
                                                                 100: PFO Write Request Error */
        uint32_t mem_slverr            : 1;  /**< [  0:  0](R/W1C/H) This bit will be set when a write channel csr or DMA engine access is performed to a non existent
                                                                 instruction or data memory address, or when any other illegal access is performed */
#else /* Word 0 - Little Endian */
        uint32_t mem_slverr            : 1;  /**< [  0:  0](R/W1C/H) This bit will be set when a write channel csr or DMA engine access is performed to a non existent
                                                                 instruction or data memory address, or when any other illegal access is performed */
        uint32_t error_src             : 3;  /**< [  3:  1](RO/H) This field indicates the source of the transaction that caused the recorded error.
                                                                 000: WDM
                                                                 001: RDM
                                                                 010: CDM
                                                                 011: CSR
                                                                 100: PFO Write Request Error */
        uint32_t addr                  : 21; /**< [ 24:  4](RO/H) When a DSP slave write access causes the SLVERR error bit to be set, this field captures the
                                                                 failing address. */
        uint32_t reserved_25_31        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_wr_error_sts_s cn; */
};
typedef union cavm_mdabx_wr_error_sts cavm_mdabx_wr_error_sts_t;

static inline uint64_t CAVM_MDABX_WR_ERROR_STS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_WR_ERROR_STS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400260ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_WR_ERROR_STS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_WR_ERROR_STS(a) cavm_mdabx_wr_error_sts_t
#define bustype_CAVM_MDABX_WR_ERROR_STS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_WR_ERROR_STS(a) "MDABX_WR_ERROR_STS"
#define busnum_CAVM_MDABX_WR_ERROR_STS(a) (a)
#define arguments_CAVM_MDABX_WR_ERROR_STS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_wr_fifo_status
 *
 * MDAB Write DMA Slice FIFO Status Register
 * The entry status of the write DMA slice FIFO.
 */
union cavm_mdabx_wr_fifo_status
{
    uint32_t u;
    struct cavm_mdabx_wr_fifo_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_6_31         : 26;
        uint32_t slice_fifo_rem_cnt    : 3;  /**< [  5:  3](RO/H) This field is the count of the remaining FIFO entries. */
        uint32_t slice_fifo_psh_cnt    : 3;  /**< [  2:  0](RO/H) This count field provides the number of slice FIFO pushes since the last
                                                                 DMA transfer finished, or since the last FIFO flush. */
#else /* Word 0 - Little Endian */
        uint32_t slice_fifo_psh_cnt    : 3;  /**< [  2:  0](RO/H) This count field provides the number of slice FIFO pushes since the last
                                                                 DMA transfer finished, or since the last FIFO flush. */
        uint32_t slice_fifo_rem_cnt    : 3;  /**< [  5:  3](RO/H) This field is the count of the remaining FIFO entries. */
        uint32_t reserved_6_31         : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_wr_fifo_status_s cn; */
};
typedef union cavm_mdabx_wr_fifo_status cavm_mdabx_wr_fifo_status_t;

static inline uint64_t CAVM_MDABX_WR_FIFO_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_WR_FIFO_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100490ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400490ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_WR_FIFO_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_WR_FIFO_STATUS(a) cavm_mdabx_wr_fifo_status_t
#define bustype_CAVM_MDABX_WR_FIFO_STATUS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_WR_FIFO_STATUS(a) "MDABX_WR_FIFO_STATUS"
#define busnum_CAVM_MDABX_WR_FIFO_STATUS(a) (a)
#define arguments_CAVM_MDABX_WR_FIFO_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_wr_length
 *
 * MDAB Write DMA Length Register
 * The actual 128-bit length of the most recent WR-DMA engine job configuration transfer.
 */
union cavm_mdabx_wr_length
{
    uint64_t u;
    struct cavm_mdabx_wr_length_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent WR-DMA engine write DMA
                                                                 transfer.

                                                                 NOTE: This field will be updated when the WR-DMA has been actually
                                                                 committed to SMEM or L2C/DDR Memory, which allows software to poll the
                                                                 length field during the WR-DMA transfer to know how many 128-bit
                                                                 chunks are currently available at their intended memory destinations
                                                                 before use by software or other hardware blocks. This field is reset to zero
                                                                 when a new transfer is started or when a new slice starts in and multi-slice transfer. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent WR-DMA engine write DMA
                                                                 transfer.

                                                                 NOTE: This field will be updated when the WR-DMA has been actually
                                                                 committed to SMEM or L2C/DDR Memory, which allows software to poll the
                                                                 length field during the WR-DMA transfer to know how many 128-bit
                                                                 chunks are currently available at their intended memory destinations
                                                                 before use by software or other hardware blocks. This field is reset to zero
                                                                 when a new transfer is started or when a new slice starts in and multi-slice transfer. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_wr_length_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_31        : 13;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent WR-DMA engine write DMA
                                                                 transfer.

                                                                 NOTE: This field will be updated when the WR-DMA has been actually
                                                                 committed to SMEM or L2C/DDR Memory, which allows software to poll the
                                                                 length field during the WR-DMA transfer to know how many 128-bit
                                                                 chunks are currently available at their intended memory destinations
                                                                 before use by software or other hardware blocks. This field is reset to zero
                                                                 when a new transfer is started or when a new slice starts in and multi-slice transfer. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t length                : 15; /**< [ 18:  4](RO/H) The actual 128-bit length of the most recent WR-DMA engine write DMA
                                                                 transfer.

                                                                 NOTE: This field will be updated when the WR-DMA has been actually
                                                                 committed to SMEM or L2C/DDR Memory, which allows software to poll the
                                                                 length field during the WR-DMA transfer to know how many 128-bit
                                                                 chunks are currently available at their intended memory destinations
                                                                 before use by software or other hardware blocks. This field is reset to zero
                                                                 when a new transfer is started or when a new slice starts in and multi-slice transfer. */
        uint64_t reserved_19_31        : 13;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_wr_length_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_31        : 14;
        uint64_t length                : 14; /**< [ 17:  4](RO/H) The actual 128-bit length of the most recent WR-DMA engine write DMA
                                                                 transfer.

                                                                 NOTE: This field will be updated when the WR-DMA has been actually
                                                                 committed to SMEM or L2C/DDR Memory, which allows software to poll the
                                                                 length field during the WR-DMA transfer to know how many 128-bit
                                                                 chunks are currently available at their intended memory destinations
                                                                 before use by software or other hardware blocks. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t length                : 14; /**< [ 17:  4](RO/H) The actual 128-bit length of the most recent WR-DMA engine write DMA
                                                                 transfer.

                                                                 NOTE: This field will be updated when the WR-DMA has been actually
                                                                 committed to SMEM or L2C/DDR Memory, which allows software to poll the
                                                                 length field during the WR-DMA transfer to know how many 128-bit
                                                                 chunks are currently available at their intended memory destinations
                                                                 before use by software or other hardware blocks. */
        uint64_t reserved_18_31        : 14;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_wr_length cavm_mdabx_wr_length_t;

static inline uint64_t CAVM_MDABX_WR_LENGTH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_WR_LENGTH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441000d0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444000d0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_WR_LENGTH", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_WR_LENGTH(a) cavm_mdabx_wr_length_t
#define bustype_CAVM_MDABX_WR_LENGTH(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_WR_LENGTH(a) "MDABX_WR_LENGTH"
#define busnum_CAVM_MDABX_WR_LENGTH(a) (a)
#define arguments_CAVM_MDABX_WR_LENGTH(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_wr_limit
 *
 * MDAB Write DMA Limit Register
 * The maximum number of 128-bit sized chunks that the WR-DMA engine may read starting from the
 * 128-bit-aligned MDAB()_WR_ADDR. NOTE: During Job_Type = ST_LCL* commands, hardware loads the
 * WR_ADDR/WR_LIMIT registers
 * directly.
 */
union cavm_mdabx_wr_limit
{
    uint64_t u;
    struct cavm_mdabx_wr_limit_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last WR-DMA slice which may be read from address MDAB()_WR_ADDR.
                                                                 DSP software may choose to segment the JD.WR-DMA data into multiple non-contiguous WR-DMA
                                                                 transfers from DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final WR-DMA sub-blk transfer.
                                                                 Each WR-DMA operation's LAST will indicate when the last segment (or slice) WR-DMA
                                                                 operation has been set up, to complete the JD.WR-DMA data transfer.
                                                                 SW_NOTE: For every new WR-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.WR-DMA data slice transfer. */
        uint64_t reserved_19_30        : 12;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W/H) "The maximum number of 128-bit chunks that the WR-DMA engine may read from address
                                                                 MDAB()_WR_ADDR.
                                                                 The JD.JCFG data typically will contain the total WR-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total WR-DMA transfer into multiple WR-DMA segments (or
                                                                 slices) using the LIMIT register.
                                                                 DSP software will set the LAST flag and a LIMIT for the final WR-DMA slice.
                                                                 When LIMIT has been reached during the LAST WR-DMA slice (or if the last JD.WR-DMA's write
                                                                 commit is detected), the WR-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W/H) "The maximum number of 128-bit chunks that the WR-DMA engine may read from address
                                                                 MDAB()_WR_ADDR.
                                                                 The JD.JCFG data typically will contain the total WR-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total WR-DMA transfer into multiple WR-DMA segments (or
                                                                 slices) using the LIMIT register.
                                                                 DSP software will set the LAST flag and a LIMIT for the final WR-DMA slice.
                                                                 When LIMIT has been reached during the LAST WR-DMA slice (or if the last JD.WR-DMA's write
                                                                 commit is detected), the WR-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_19_30        : 12;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last WR-DMA slice which may be read from address MDAB()_WR_ADDR.
                                                                 DSP software may choose to segment the JD.WR-DMA data into multiple non-contiguous WR-DMA
                                                                 transfers from DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final WR-DMA sub-blk transfer.
                                                                 Each WR-DMA operation's LAST will indicate when the last segment (or slice) WR-DMA
                                                                 operation has been set up, to complete the JD.WR-DMA data transfer.
                                                                 SW_NOTE: For every new WR-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.WR-DMA data slice transfer. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_wr_limit_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last WR-DMA slice which may be read from address MDAB()_WR_ADDR.
                                                                 DSP software may choose to segment the JD.WR-DMA data into multiple non-contiguous WR-DMA
                                                                 transfers from DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final WR-DMA sub-blk transfer.
                                                                 Each WR-DMA operation's LAST will indicate when the last segment (or slice) WR-DMA
                                                                 operation has been set up, to complete the JD.WR-DMA data transfer.
                                                                 SW_NOTE: For every new WR-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.WR-DMA data slice transfer. */
        uint64_t reserved_19_30        : 12;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W/H) "The maximum number of 128-bit chunks that the WR-DMA engine may read from address
                                                                 MDAB()_WR_ADDR.
                                                                 The JD.JCFG data typically will contain the total WR-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total WR-DMA transfer into multiple WR-DMA segments (or
                                                                 slices) using the LIMIT register.
                                                                 DSP software will set the LAST flag and a LIMIT for the final WR-DMA slice.
                                                                 When LIMIT has been reached during the LAST WR-DMA slice (or if the last JD.WR-DMA's write
                                                                 commit is detected), the WR-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t limit                 : 15; /**< [ 18:  4](R/W/H) "The maximum number of 128-bit chunks that the WR-DMA engine may read from address
                                                                 MDAB()_WR_ADDR.
                                                                 The JD.JCFG data typically will contain the total WR-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total WR-DMA transfer into multiple WR-DMA segments (or
                                                                 slices) using the LIMIT register.
                                                                 DSP software will set the LAST flag and a LIMIT for the final WR-DMA slice.
                                                                 When LIMIT has been reached during the LAST WR-DMA slice (or if the last JD.WR-DMA's write
                                                                 commit is detected), the WR-DMA is done.

                                                                 For MBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4003.FFFF
                                                                    DMEM: 0x3FFE.0000 - 0x3FFF.FFFF
                                                                 For SBP DSP:
                                                                    IMEM: 0x4000.0000 - 0x4000.FFFF
                                                                    DMEM: 0x3FFC.0000 - 0x3FFF.FFFF

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_19_30        : 12;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last WR-DMA slice which may be read from address MDAB()_WR_ADDR.
                                                                 DSP software may choose to segment the JD.WR-DMA data into multiple non-contiguous WR-DMA
                                                                 transfers from DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final WR-DMA sub-blk transfer.
                                                                 Each WR-DMA operation's LAST will indicate when the last segment (or slice) WR-DMA
                                                                 operation has been set up, to complete the JD.WR-DMA data transfer.
                                                                 SW_NOTE: For every new WR-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.WR-DMA data slice transfer. */
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_mdabx_wr_limit_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last WR-DMA slice which may be read from address MDAB()_WR_ADDR.
                                                                 DSP software may choose to segment the JD.WR-DMA data into multiple non-contiguous WR-DMA
                                                                 transfers from DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final WR-DMA sub-blk transfer.
                                                                 Each WR-DMA operation's LAST will indicate when the last segment (or slice) WR-DMA
                                                                 operation has been set up, to complete the JD.WR-DMA data transfer.
                                                                 SW_NOTE: For every new WR-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.WR-DMA data slice transfer. */
        uint64_t reserved_18_30        : 13;
        uint64_t limit                 : 14; /**< [ 17:  4](R/W/H) "The maximum number of 128-bit chunks that the WR-DMA engine may read from address
                                                                 MDAB()_WR_ADDR.
                                                                 The JD.JCFG data typically will contain the total WR-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total WR-DMA transfer into multiple WR-DMA segments (or
                                                                 slices) using the LIMIT register.
                                                                 DSP software will set the LAST flag and a LIMIT for the final WR-DMA slice.
                                                                 When LIMIT has been reached during the LAST WR-DMA slice (or if the last JD.WR-DMA's write
                                                                 commit is detected), the WR-DMA is done.

                                                                 D-TCM/DMEM: 0x0 - (0x03_FFFF \>\> 4)
                                                                 P-TCM/IMEM: (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4)
                                                                 CMP registers: (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4)

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t limit                 : 14; /**< [ 17:  4](R/W/H) "The maximum number of 128-bit chunks that the WR-DMA engine may read from address
                                                                 MDAB()_WR_ADDR.
                                                                 The JD.JCFG data typically will contain the total WR-DMA Length for each new job. The
                                                                 DSP software is at liberty to break the total WR-DMA transfer into multiple WR-DMA segments (or
                                                                 slices) using the LIMIT register.
                                                                 DSP software will set the LAST flag and a LIMIT for the final WR-DMA slice.
                                                                 When LIMIT has been reached during the LAST WR-DMA slice (or if the last JD.WR-DMA's write
                                                                 commit is detected), the WR-DMA is done.

                                                                 D-TCM/DMEM: 0x0 - (0x03_FFFF \>\> 4)
                                                                 P-TCM/IMEM: (0x20_0000 \>\> 4) - (0x21_FFFF \>\> 4)
                                                                 CMP registers: (0x40_0000 \>\> 4) - (0x40_3FFF \>\> 4)

                                                                 SW RESTRICTION #1: Software should never program LIMIT=0. INDETERMINATE results can/will occur.
                                                                 SW RESTRICTION #2: Software should ensure that ADDR+LIMIT SIZES fall within the I+D MEM space,
                                                                 otherwise DMA_ERROR and INDETERMINATE results can/will occur." */
        uint64_t reserved_18_30        : 13;
        uint64_t last                  : 1;  /**< [ 31: 31](R/W) Indicates the last WR-DMA slice which may be read from address MDAB()_WR_ADDR.
                                                                 DSP software may choose to segment the JD.WR-DMA data into multiple non-contiguous WR-DMA
                                                                 transfers from DSP local memory.
                                                                 Eventually, DSP software will indicate the LAST segment (or slice), to indicate this is
                                                                 the final WR-DMA sub-blk transfer.
                                                                 Each WR-DMA operation's LAST will indicate when the last segment (or slice) WR-DMA
                                                                 operation has been set up, to complete the JD.WR-DMA data transfer.
                                                                 SW_NOTE: For every new WR-DMA slice operation, DSP software *MUST* signal LAST to indicate
                                                                 the final JD.WR-DMA data slice transfer. */
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_wr_limit cavm_mdabx_wr_limit_t;

static inline uint64_t CAVM_MDABX_WR_LIMIT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_WR_LIMIT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441000c0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444000c0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_WR_LIMIT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_WR_LIMIT(a) cavm_mdabx_wr_limit_t
#define bustype_CAVM_MDABX_WR_LIMIT(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_WR_LIMIT(a) "MDABX_WR_LIMIT"
#define busnum_CAVM_MDABX_WR_LIMIT(a) (a)
#define arguments_CAVM_MDABX_WR_LIMIT(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_wr_next_addr
 *
 * MDAB Write DMA Next Address Register
 * The next address for multi slice DMA transfers. Indicates the first unused slice starting address.
 */
union cavm_mdabx_wr_next_addr
{
    uint32_t u;
    struct cavm_mdabx_wr_next_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t next_addr             : 27; /**< [ 30:  4](RO/H) The next 128b-aligned starting address to be used by the WR-DMA engine when writing WR-DMA data to
                                                                 local DSP memory. This register is used to determine the address for unused slices. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t next_addr             : 27; /**< [ 30:  4](RO/H) The next 128b-aligned starting address to be used by the WR-DMA engine when writing WR-DMA data to
                                                                 local DSP memory. This register is used to determine the address for unused slices. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdabx_wr_next_addr_s cnf95xx; */
    struct cavm_mdabx_wr_next_addr_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_23_31        : 9;
        uint32_t next_addr             : 19; /**< [ 22:  4](RO/H) The next 128b-aligned starting address to be used by the WR-DMA engine when writing WR-DMA data to
                                                                 local DSP memory. This register is used to determine the address for unused slices. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t next_addr             : 19; /**< [ 22:  4](RO/H) The next 128b-aligned starting address to be used by the WR-DMA engine when writing WR-DMA data to
                                                                 local DSP memory. This register is used to determine the address for unused slices. */
        uint32_t reserved_23_31        : 9;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdabx_wr_next_addr cavm_mdabx_wr_next_addr_t;

static inline uint64_t CAVM_MDABX_WR_NEXT_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_WR_NEXT_ADDR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044100470ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044400470ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_WR_NEXT_ADDR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_WR_NEXT_ADDR(a) cavm_mdabx_wr_next_addr_t
#define bustype_CAVM_MDABX_WR_NEXT_ADDR(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_WR_NEXT_ADDR(a) "MDABX_WR_NEXT_ADDR"
#define busnum_CAVM_MDABX_WR_NEXT_ADDR(a) (a)
#define arguments_CAVM_MDABX_WR_NEXT_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) mdab#_wr_status
 *
 * MDAB Write DMA Status Register
 * Reports the status for the WR-DMA engine.
 */
union cavm_mdabx_wr_status
{
    uint64_t u;
    struct cavm_mdabx_wr_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed WR-DMA operation.
                                                                 When DSP software writes START_BUSY=0-\>1, the WR-DMA engine will wait until the next
                                                                 available Job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_13_15        : 3;
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t post_st_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a Store-Local job has completed (last ST-LCL micro-op completes).
                                                                 Cleared when a Normal job has completed. */
        uint64_t st_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a Store-Local operation is active. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending WR-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent WR-DMA operation. */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last WR-DMA operation encountered an underflow */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last WR-DMA operation encountered an overflow */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last WR-DMA operation encountered an error. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last WR-DMA operation received the last write-commit for the WR-DMA data from
                                                                 the job descriptor (JD.WR-DMA). WR-DMAs are issued to either SMEM or L2C/DDR, and the WR-
                                                                 DMA engine will receive
                                                                 ordered write responses from the MHBW-AMM to indicate which writes have been committed. */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a WR-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the WR-DMA engine starts its first
                                                                 WR-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will copy the data for the completed
                                                                 job from the local memory starting at MDAB()_WD_ADDR to the mdbw, up to
                                                                 MDAB()_WR_ADDR+MDAB()_WR_LIMIT
                                                                 or when the last 128-bit word of the JD.WR-DMA section is transferred (whichever comes
                                                                 first).
                                                                 If the WR-DMA engine has already transferred part but not all of the JD.WR-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.WR-DMA
                                                                 section,
                                                                 or until it writes MDAB()_CFG_LIMIT for the LAST WR-DMA slice, whichever comes first.
                                                                 This bit is reset to zero when the WR-DMA engine has completed the transfer and is ready
                                                                 to be re-initialized for another transfer. */
#else /* Word 0 - Little Endian */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will copy the data for the completed
                                                                 job from the local memory starting at MDAB()_WD_ADDR to the mdbw, up to
                                                                 MDAB()_WR_ADDR+MDAB()_WR_LIMIT
                                                                 or when the last 128-bit word of the JD.WR-DMA section is transferred (whichever comes
                                                                 first).
                                                                 If the WR-DMA engine has already transferred part but not all of the JD.WR-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.WR-DMA
                                                                 section,
                                                                 or until it writes MDAB()_CFG_LIMIT for the LAST WR-DMA slice, whichever comes first.
                                                                 This bit is reset to zero when the WR-DMA engine has completed the transfer and is ready
                                                                 to be re-initialized for another transfer. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the WR-DMA engine starts its first
                                                                 WR-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a WR-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last WR-DMA operation received the last write-commit for the WR-DMA data from
                                                                 the job descriptor (JD.WR-DMA). WR-DMAs are issued to either SMEM or L2C/DDR, and the WR-
                                                                 DMA engine will receive
                                                                 ordered write responses from the MHBW-AMM to indicate which writes have been committed. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last WR-DMA operation encountered an error. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last WR-DMA operation encountered an overflow */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last WR-DMA operation encountered an underflow */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent WR-DMA operation. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending WR-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t st_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a Store-Local operation is active. */
        uint64_t post_st_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a Store-Local job has completed (last ST-LCL micro-op completes).
                                                                 Cleared when a Normal job has completed. */
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed WR-DMA operation.
                                                                 When DSP software writes START_BUSY=0-\>1, the WR-DMA engine will wait until the next
                                                                 available Job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdabx_wr_status_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed WR-DMA operation.
                                                                 When DSP software writes START_BUSY=0-\>1, the WR-DMA engine will wait until the next
                                                                 available Job has been enqueued, at which point the JOB_TAG will be latched in. */
        uint64_t reserved_13_15        : 3;
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t post_st_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a Store-Local job has completed (last ST-LCL micro-op completes).
                                                                 Cleared when a Normal job has completed. */
        uint64_t st_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a Store-Local operation is active. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending WR-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent WR-DMA operation. */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last WR-DMA operation encountered an underflow */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last WR-DMA operation encountered an overflow */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last WR-DMA operation encountered an error. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last WR-DMA operation received the last write-commit for the WR-DMA data from
                                                                 the job descriptor (JD.WR-DMA). WR-DMAs are issued to either SMEM or L2C/DDR, and the WR-
                                                                 DMA engine will receive
                                                                 ordered write responses from the MHBW-AMM to indicate which writes have been committed. */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a WR-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the WR-DMA engine starts its first
                                                                 WR-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will copy the data for the completed
                                                                 job from the local memory starting at MDAB()_WD_ADDR to the mdbw, up to
                                                                 MDAB()_WR_ADDR+MDAB()_WR_LIMIT
                                                                 or when the last 128-bit word of the JD.WR-DMA section is transferred (whichever comes
                                                                 first).
                                                                 If the WR-DMA engine has already transferred part but not all of the JD.WR-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.WR-DMA
                                                                 section,
                                                                 or until it writes MDAB()_CFG_LIMIT for the LAST WR-DMA slice, whichever comes first.
                                                                 This bit is reset to zero when the WR-DMA engine has completed the transfer and is ready
                                                                 to be re-initialized for another transfer. */
#else /* Word 0 - Little Endian */
        uint64_t start_busy            : 1;  /**< [  0:  0](R/W1S/H) When software writes a one to this register, hardware will copy the data for the completed
                                                                 job from the local memory starting at MDAB()_WD_ADDR to the mdbw, up to
                                                                 MDAB()_WR_ADDR+MDAB()_WR_LIMIT
                                                                 or when the last 128-bit word of the JD.WR-DMA section is transferred (whichever comes
                                                                 first).
                                                                 If the WR-DMA engine has already transferred part but not all of the JD.WR-DMA section for
                                                                 a job, then it will continue transferring data until it reaches the end of the JD.WR-DMA
                                                                 section,
                                                                 or until it writes MDAB()_CFG_LIMIT for the LAST WR-DMA slice, whichever comes first.
                                                                 This bit is reset to zero when the WR-DMA engine has completed the transfer and is ready
                                                                 to be re-initialized for another transfer. */
        uint64_t post_reset            : 1;  /**< [  1:  1](RO/H) Set to one on MDAB reset and remains one until the WR-DMA engine starts its first
                                                                 WR-DMA transfer.
                                                                 SWNOTE: DSP software can use this bit to qualify the JOB_TAG, JOB_SLOT, DMA_ERROR, LAST_DMA_DONE
                                                                 bits in this CSR. [see: these status bits remain SET and POST_RESET is used
                                                                 by software to know when they are truly valid].
                                                                 SET(HW): MDAB reset
                                                                 CLR(SW): DSP writes START_BUSY=0-\>1 */
        uint64_t dma_pending           : 1;  /**< [  2:  2](RO/H) Set when a WR-DMA operation is pending for the engine and the internal interface needs to
                                                                 be programmed. */
        uint64_t last_dma_done         : 1;  /**< [  3:  3](RO/H) Set when the last WR-DMA operation received the last write-commit for the WR-DMA data from
                                                                 the job descriptor (JD.WR-DMA). WR-DMAs are issued to either SMEM or L2C/DDR, and the WR-
                                                                 DMA engine will receive
                                                                 ordered write responses from the MHBW-AMM to indicate which writes have been committed. */
        uint64_t dma_error             : 1;  /**< [  4:  4](RO/H) Set when the last WR-DMA operation encountered an error. */
        uint64_t dma_oflow             : 1;  /**< [  5:  5](RO/H) Set when the last WR-DMA operation encountered an overflow */
        uint64_t dma_uflow             : 1;  /**< [  6:  6](RO/H) Set when the last WR-DMA operation encountered an underflow */
        uint64_t slice_fifo_oflow      : 1;  /**< [  7:  7](RO/H) Set when the slice FIFO overflows. */
        uint64_t job_slot              : 1;  /**< [  8:  8](RO/H) The job slot for the most recent WR-DMA operation. */
        uint64_t pending_slot          : 1;  /**< [  9:  9](RO/H) The job slot for the pending WR-DMA operation. Valid only when START_BUSY == 0 and
                                                                 DMA_PENDING == 1. */
        uint64_t st_lcl_busy           : 1;  /**< [ 10: 10](RO/H) Set when a Store-Local operation is active. */
        uint64_t post_st_lcl           : 1;  /**< [ 11: 11](RO/H) Set when a Store-Local job has completed (last ST-LCL micro-op completes).
                                                                 Cleared when a Normal job has completed. */
        uint64_t slice_fifo_flush      : 1;  /**< [ 12: 12](R/W1S/H) Write one to flush the slice FIFO. This field will be automatically cleared. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_tag               : 16; /**< [ 31: 16](RO/H) The JOB_TAG field from the PSM command for the last completed WR-DMA operation.
                                                                 When DSP software writes START_BUSY=0-\>1, the WR-DMA engine will wait until the next
                                                                 available Job has been enqueued, at which point the JOB_TAG will be latched in. */
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mdabx_wr_status cavm_mdabx_wr_status_t;

static inline uint64_t CAVM_MDABX_WR_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDABX_WR_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e0441000a0ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e0444000a0ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDABX_WR_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDABX_WR_STATUS(a) cavm_mdabx_wr_status_t
#define bustype_CAVM_MDABX_WR_STATUS(a) CSR_TYPE_RSL32b
#define basename_CAVM_MDABX_WR_STATUS(a) "MDABX_WR_STATUS"
#define busnum_CAVM_MDABX_WR_STATUS(a) (a)
#define arguments_CAVM_MDABX_WR_STATUS(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_MDAB_H__ */
