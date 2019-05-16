#ifndef __CAVM_CSRS_MDBW_H__
#define __CAVM_CSRS_MDBW_H__
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
 * OcteonTX MDBW.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration mdbw_ab_port_width_e
 *
 * MDBW AB Port Width Enumeration
 * Enumerates the AB port width.
 */
#define CAVM_MDBW_AB_PORT_WIDTH_E_DW_128 (1)
#define CAVM_MDBW_AB_PORT_WIDTH_E_DW_256 (0)
#define CAVM_MDBW_AB_PORT_WIDTH_E_DW_32 (3)
#define CAVM_MDBW_AB_PORT_WIDTH_E_DW_64 (2)

/**
 * Enumeration mdbw_dac_pnb_rd_cmd_e
 *
 * MDBW DAC Read DMA Command Enumeration
 * Enumerates the read requests to LLC/DRAM command types.
 */
#define CAVM_MDBW_DAC_PNB_RD_CMD_E_LDD (0)
#define CAVM_MDBW_DAC_PNB_RD_CMD_E_LDT (1)

/**
 * Enumeration mdbw_dma_mode_e
 *
 * MDBW DMA Mode Enumeration
 */
#define CAVM_MDBW_DMA_MODE_E_BLK_DMA (0)
#define CAVM_MDBW_DMA_MODE_E_THREE_D_BLK_DMA (4)
#define CAVM_MDBW_DMA_MODE_E_TWO_D_BLK_DMA_BLKCNT (3)
#define CAVM_MDBW_DMA_MODE_E_TWO_D_BLK_DMA_BLKMSK (2)

/**
 * Enumeration mdbw_dsp_job_sel_e
 *
 * MDBW Memory destination Enumeration
 * Enumerates the memory destination for read/write DMA for the DSP core.
 */
#define CAVM_MDBW_DSP_JOB_SEL_E_LOAD_LOCAL (1)
#define CAVM_MDBW_DSP_JOB_SEL_E_LOAD_LOCAL_RST (2)
#define CAVM_MDBW_DSP_JOB_SEL_E_NORMAL (0)
#define CAVM_MDBW_DSP_JOB_SEL_E_STORE_LOCAL (3)

/**
 * Enumeration mdbw_ghb_priority_e
 *
 * MDBW GHAB Priority Enumeration
 * Enumerates the GHAB priority levels.
 */
#define CAVM_MDBW_GHB_PRIORITY_E_HIGH (1)
#define CAVM_MDBW_GHB_PRIORITY_E_NORMAL (0)

/**
 * Enumeration mdbw_pnb_dswap_e
 *
 * MDBW PNB Data Swap Enumeration
 * Enumerates the data swap that is to be performed in PNB.
 */
#define CAVM_MDBW_PNB_DSWAP_E_FOUR_BYTE (3)
#define CAVM_MDBW_PNB_DSWAP_E_NONE (0)
#define CAVM_MDBW_PNB_DSWAP_E_ONE_BYTE (1)
#define CAVM_MDBW_PNB_DSWAP_E_RSVD0 (4)
#define CAVM_MDBW_PNB_DSWAP_E_RSVD1 (5)
#define CAVM_MDBW_PNB_DSWAP_E_RSVD2 (6)
#define CAVM_MDBW_PNB_DSWAP_E_RSVD3 (7)
#define CAVM_MDBW_PNB_DSWAP_E_TWO_BYTE (2)

/**
 * Enumeration mdbw_pnb_rd_cmd_e
 *
 * MDBW Read DMA Command Enumeration
 * Enumerates the read requests to LLC/DRAM command types.
 */
#define CAVM_MDBW_PNB_RD_CMD_E_LDD (0)
#define CAVM_MDBW_PNB_RD_CMD_E_LDT (1)
#define CAVM_MDBW_PNB_RD_CMD_E_LDWB (2)
#define CAVM_MDBW_PNB_RD_CMD_E_RSVD0 (3)

/**
 * Enumeration mdbw_pnb_wr_cmd_e
 *
 * MDBW Write DMA Command Enumeration
 * Enumerates the write DMA LLC/DRAM command types.
 */
#define CAVM_MDBW_PNB_WR_CMD_E_RSVD0 (3)
#define CAVM_MDBW_PNB_WR_CMD_E_STF (1)
#define CAVM_MDBW_PNB_WR_CMD_E_STP (0)
#define CAVM_MDBW_PNB_WR_CMD_E_STT (2)

/**
 * Enumeration mdbw_tmem_sel_e
 *
 * MDBW Target Memory Enumeration
 * Enumerates the target memory for GAA data fetch.
 */
#define CAVM_MDBW_TMEM_SEL_E_L2C_DDR (1)
#define CAVM_MDBW_TMEM_SEL_E_SMEM (0)

/**
 * Structure mdbw_jd_cfg_data_s
 *
 * MDBW Config Data Structure
 * The MDBW config data subdescriptor is written to the hardware driven config space if
 * SLOT_EN=1,
 * else it writes the data from a starting address of zero.
 */
union cavm_mdbw_jd_cfg_data_s
{
    uint64_t u;
    struct cavm_mdbw_jd_cfg_data_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cfg_wr_data           : 64; /**< [ 63:  0] Specifies the config write data to be written. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_wr_data           : 64; /**< [ 63:  0] Specifies the config write data to be written. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbw_jd_cfg_data_s_s cn; */
};

/**
 * Structure mdbw_jd_cfg_ptr_s
 *
 * MDBW Config Pointer Structure
 * The MDBW config pointer subdescriptor specifies an indirection pointer location for the
 * config
 * subdescriptors. This subdescriptor is required for all jobs.
 */
union cavm_mdbw_jd_cfg_ptr_s
{
    uint64_t u;
    struct cavm_mdbw_jd_cfg_ptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t target_mem            : 1;  /**< [ 63: 63] Defines the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
        uint64_t reserved_53_62        : 10;
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the config subdescriptor start address pointer as a byte location. The address
                                                                 has to
                                                                 be 64-bit aligned, i.e., bits [2:0] = 0. */
#else /* Word 0 - Little Endian */
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the config subdescriptor start address pointer as a byte location. The address
                                                                 has to
                                                                 be 64-bit aligned, i.e., bits [2:0] = 0. */
        uint64_t reserved_53_62        : 10;
        uint64_t target_mem            : 1;  /**< [ 63: 63] Defines the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbw_jd_cfg_ptr_s_s cn; */
};

/**
 * Structure mdbw_jd_dma_cfg_word_0_s
 *
 * MDBW DMA Configuration Word 0 Structure
 * The MDBW DMA config word 0 subdescriptor is the first word of the read/write DMA config sequence.
 */
union cavm_mdbw_jd_dma_cfg_word_0_s
{
    uint64_t u;
    struct cavm_mdbw_jd_dma_cfg_word_0_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t block_size            : 16; /**< [ 47: 32] Defines the DMA block size in 32-bit words for all transfers.
                                                                 A multiple of 4 must be used for the 128-bit MDBW interfaces. */
        uint64_t reserved_9_31         : 23;
        uint64_t cmd_type              : 2;  /**< [  8:  7] DMA command type for LLC/DRAM access. The read and write operations are
                                                                 enumerated with MDBW_PNB_RD_CMD_E and MDBW_PNB_WR_CMD_E respectively. */
        uint64_t dswap                 : 3;  /**< [  6:  4] The byte swapper enables PNB to swap bytes on a 64-bit boundary. The swap operations are
                                                                 enumerated in MDBW_PNB_DSWAP_E. Swaps are only applied on DMA to/from
                                                                 LLC/DRAM. */
        uint64_t target_mem            : 1;  /**< [  3:  3] Defines the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
        uint64_t dma_mode              : 3;  /**< [  2:  0] Selects the DMA mode, enumerated by MDBW_DMA_MODE_E. */
#else /* Word 0 - Little Endian */
        uint64_t dma_mode              : 3;  /**< [  2:  0] Selects the DMA mode, enumerated by MDBW_DMA_MODE_E. */
        uint64_t target_mem            : 1;  /**< [  3:  3] Defines the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
        uint64_t dswap                 : 3;  /**< [  6:  4] The byte swapper enables PNB to swap bytes on a 64-bit boundary. The swap operations are
                                                                 enumerated in MDBW_PNB_DSWAP_E. Swaps are only applied on DMA to/from
                                                                 LLC/DRAM. */
        uint64_t cmd_type              : 2;  /**< [  8:  7] DMA command type for LLC/DRAM access. The read and write operations are
                                                                 enumerated with MDBW_PNB_RD_CMD_E and MDBW_PNB_WR_CMD_E respectively. */
        uint64_t reserved_9_31         : 23;
        uint64_t block_size            : 16; /**< [ 47: 32] Defines the DMA block size in 32-bit words for all transfers.
                                                                 A multiple of 4 must be used for the 128-bit MDBW interfaces. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct cavm_mdbw_jd_dma_cfg_word_0_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t reserved_56_59        : 4;
        uint64_t reserved_54_55        : 2;
        uint64_t reserved_48_53        : 6;
        uint64_t block_size            : 16; /**< [ 47: 32] Defines the DMA block size in 32-bit words for all transfers.
                                                                 A multiple of 4 must be used for the 128-bit MDBW interfaces. */
        uint64_t reserved_16_31        : 16;
        uint64_t reserved_9_15         : 7;
        uint64_t cmd_type              : 2;  /**< [  8:  7] DMA command type for LLC/DRAM access. The read and write operations are
                                                                 enumerated with MDBW_PNB_RD_CMD_E and MDBW_PNB_WR_CMD_E respectively. */
        uint64_t dswap                 : 3;  /**< [  6:  4] The byte swapper enables PNB to swap bytes on a 64-bit boundary. The swap operations are
                                                                 enumerated in MDBW_PNB_DSWAP_E. Swaps are only applied on DMA to/from
                                                                 LLC/DRAM. */
        uint64_t target_mem            : 1;  /**< [  3:  3] Defines the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
        uint64_t dma_mode              : 3;  /**< [  2:  0] Selects the DMA mode, enumerated by MDBW_DMA_MODE_E. */
#else /* Word 0 - Little Endian */
        uint64_t dma_mode              : 3;  /**< [  2:  0] Selects the DMA mode, enumerated by MDBW_DMA_MODE_E. */
        uint64_t target_mem            : 1;  /**< [  3:  3] Defines the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
        uint64_t dswap                 : 3;  /**< [  6:  4] The byte swapper enables PNB to swap bytes on a 64-bit boundary. The swap operations are
                                                                 enumerated in MDBW_PNB_DSWAP_E. Swaps are only applied on DMA to/from
                                                                 LLC/DRAM. */
        uint64_t cmd_type              : 2;  /**< [  8:  7] DMA command type for LLC/DRAM access. The read and write operations are
                                                                 enumerated with MDBW_PNB_RD_CMD_E and MDBW_PNB_WR_CMD_E respectively. */
        uint64_t reserved_9_15         : 7;
        uint64_t reserved_16_31        : 16;
        uint64_t block_size            : 16; /**< [ 47: 32] Defines the DMA block size in 32-bit words for all transfers.
                                                                 A multiple of 4 must be used for the 128-bit MDBW interfaces. */
        uint64_t reserved_48_53        : 6;
        uint64_t reserved_54_55        : 2;
        uint64_t reserved_56_59        : 4;
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } cn;
};

/**
 * Structure mdbw_jd_dma_cfg_word_1_s
 *
 * MDBW DMA Configuration Word 1 Structure
 * The MDBW DMA config word 1 subdescriptor is the second word of the read/write DMA config sequence.
 */
union cavm_mdbw_jd_dma_cfg_word_1_s
{
    uint64_t u;
    struct cavm_mdbw_jd_dma_cfg_word_1_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the DMA start address pointer as a byte location.
                                                                 The address must be naturally aligned to the maximum size of the DMA port, i.e., the
                                                                 address is 128-bit aligned. For a 128-bit port, bits [3:0] = 0. */
#else /* Word 0 - Little Endian */
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the DMA start address pointer as a byte location.
                                                                 The address must be naturally aligned to the maximum size of the DMA port, i.e., the
                                                                 address is 128-bit aligned. For a 128-bit port, bits [3:0] = 0. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbw_jd_dma_cfg_word_1_s_s cn; */
};

/**
 * Structure mdbw_jd_dma_cfg_word_2_s
 *
 * MDBW DMA Configuration Word 2 Structure
 * This structure specifies the format for the third word of read/write
 * block DMA commands. This word should be present for all 2D and 3D DMA
 * modes, i.e., for all modes except when
 * MDBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MDBW_DMA_MODE_E::BLK_DMA.
 */
union cavm_mdbw_jd_dma_cfg_word_2_s
{
    uint64_t u;
    struct cavm_mdbw_jd_dma_cfg_word_2_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t stride                : 32; /**< [ 63: 32] Signed distance in bytes between the start of consecutive blocks of 2D
                                                                 DMA. Must be two's complement value in the range ABS([STRIDE]) \< 128
                                                                 MB.  The stride distance must be aligned to the DMA port width. */
        uint64_t block_param           : 32; /**< [ 31:  0] When MDBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MDBW_DMA_MODE_E::TWO_D_BLK_DMA_BLKMSK,
                                                                 [BLOCK_PARAM] is a block-skip mask. Each bit 31..0 corresponds to one
                                                                 of 32 blocks. Setting a bit in the mask will cause the DMA command to
                                                                 skip that block. Note that a value of 0xFFFFFFFF is illegal, a command
                                                                 must have at least one block that is NOT skipped.

                                                                 When MDBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MDBW_DMA_MODE_E::TWO_D_BLK_DMA_BLKCNT,
                                                                 [BLOCK_PARAM] is the number of blocks of DMA, and no blocks are
                                                                 skipped. Must be in the range [0x1, 0x400].

                                                                 When MDBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] =
                                                                 MDBW_DMA_MODE_E::THREE_D_BLK_DMA, [BLOCK_PARAM] is the number of
                                                                 blocks in each 3D block. No blocks are skipped. Must be in the range
                                                                 [0x1, 0x400]. */
#else /* Word 0 - Little Endian */
        uint64_t block_param           : 32; /**< [ 31:  0] When MDBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MDBW_DMA_MODE_E::TWO_D_BLK_DMA_BLKMSK,
                                                                 [BLOCK_PARAM] is a block-skip mask. Each bit 31..0 corresponds to one
                                                                 of 32 blocks. Setting a bit in the mask will cause the DMA command to
                                                                 skip that block. Note that a value of 0xFFFFFFFF is illegal, a command
                                                                 must have at least one block that is NOT skipped.

                                                                 When MDBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MDBW_DMA_MODE_E::TWO_D_BLK_DMA_BLKCNT,
                                                                 [BLOCK_PARAM] is the number of blocks of DMA, and no blocks are
                                                                 skipped. Must be in the range [0x1, 0x400].

                                                                 When MDBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] =
                                                                 MDBW_DMA_MODE_E::THREE_D_BLK_DMA, [BLOCK_PARAM] is the number of
                                                                 blocks in each 3D block. No blocks are skipped. Must be in the range
                                                                 [0x1, 0x400]. */
        uint64_t stride                : 32; /**< [ 63: 32] Signed distance in bytes between the start of consecutive blocks of 2D
                                                                 DMA. Must be two's complement value in the range ABS([STRIDE]) \< 128
                                                                 MB.  The stride distance must be aligned to the DMA port width. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbw_jd_dma_cfg_word_2_s_s cn; */
};

/**
 * Structure mdbw_jd_dma_cfg_word_3_s
 *
 * MDBW DMA Configuration Word 3 Structure
 * The MDBW DMA config word 3 subdescriptor is the fourth word of the read/write DMA config
 * sequence. This is required only if the operation is a LOAD_LOCAL or STORE_LOCAL.
 */
union cavm_mdbw_jd_dma_cfg_word_3_s
{
    uint64_t u;
    struct cavm_mdbw_jd_dma_cfg_word_3_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t mem_addr              : 32; /**< [ 31:  0] Specifies the DMEM/IMEM address and is used by the DAC to WR/RD. */
#else /* Word 0 - Little Endian */
        uint64_t mem_addr              : 32; /**< [ 31:  0] Specifies the DMEM/IMEM address and is used by the DAC to WR/RD. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbw_jd_dma_cfg_word_3_s_s cnf95xx; */
    struct cavm_mdbw_jd_dma_cfg_word_3_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_63        : 41;
        uint64_t mem_addr              : 23; /**< [ 22:  0] Specifies the DMEM/IMEM address and is used by the DAC to WR/RD. */
#else /* Word 0 - Little Endian */
        uint64_t mem_addr              : 23; /**< [ 22:  0] Specifies the DMEM/IMEM address and is used by the DAC to WR/RD. */
        uint64_t reserved_23_63        : 41;
#endif /* Word 0 - End */
    } loki;
};

/**
 * Structure mdbw_jd_dma_ptr_s
 *
 * MDBW DMA Pointer Structure
 * The MDBW DMA pointer subdescriptor specifies an indirection pointer location to the DMA
 * subdescriptors. Each read and/or write port must have a pointer location in every job
 * descriptor.
 */
union cavm_mdbw_jd_dma_ptr_s
{
    uint64_t u;
    struct cavm_mdbw_jd_dma_ptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t target_mem            : 1;  /**< [ 63: 63] Defines the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
        uint64_t reserved_53_62        : 10;
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the CFG descriptor start address pointer as a byte location. The address has to
                                                                 be 64-bit aligned, i.e., bits [2:0] = 0. */
#else /* Word 0 - Little Endian */
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the CFG descriptor start address pointer as a byte location. The address has to
                                                                 be 64-bit aligned, i.e., bits [2:0] = 0. */
        uint64_t reserved_53_62        : 10;
        uint64_t target_mem            : 1;  /**< [ 63: 63] Defines the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbw_jd_dma_ptr_s_s cn; */
};

/**
 * Structure mdbw_jd_hdr_word_0_s
 *
 * MDBW Header Word 0 Structure
 * The MDBW header word 0 is the first word of the job header subdescriptor. This subdescriptor
 * is required for all jobs.
 */
union cavm_mdbw_jd_hdr_word_0_s
{
    uint64_t u;
    struct cavm_mdbw_jd_hdr_word_0_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t dsp_job_type          : 2;  /**< [ 62: 61] Indicates whether DMA is performed under software control or automatic
                                                                 hardware control. Job types are enumerated with MDBW_DSP_JOB_SEL_E. */
        uint64_t toth                  : 4;  /**< [ 60: 57] Job timeout threshold. The timeout timer starts counting when the job
                                                                 gets started on a DAC. The timer increments by one each SCLK cycle,
                                                                 and a timeout occurs when the timer reaches the threshold specified
                                                                 as:

                                                                 _ ((MDBW()_JD_CFG[TIMEOUT_MULT]\<\<4)+[TOTH])*2^([TOTH_TICK]+4)

                                                                 Setting [TOTH]=0 disables the timeout timer.

                                                                 For example, to get 10.24 us timeout value when BPHY runs at 1GHz,
                                                                 set [TOTH_TICK]=0x6, [TOTH]=0xA, and MDBW()_JD_CFG[TIMEOUT_MULT]=0x1. */
        uint64_t toth_tick             : 4;  /**< [ 56: 53] Timeout threshold tick count. See MDBW_JD_HDR_WORD_0_S[TOTH] for
                                                                 details. */
        uint64_t jce_cnt               : 6;  /**< [ 52: 47] Specifies the number of 64-bit job completion event words to fetch starting from
                                                                 MDBW_JD_JCE_PTR_S[START_ADDR].
                                                                 Supports up to 62 x 64-bit words, i.e., 31 JCE commands. */
        uint64_t reserved_42_46        : 5;
        uint64_t dma_p0_wrcnt          : 10; /**< [ 41: 32] Specifies the number of 64-bit write DMA command words to fetch starting from
                                                                 MDBW_JD_DMA_PTR_S[START_ADDR].  Supports up to 1023 64-bit words. */
        uint64_t reserved_26_31        : 6;
        uint64_t dma_p0_rdcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit read DMA command words to fetch starting from
                                                                 MDBW_JD_DMA_PTR_S[START_ADDR].  Supports up to 1023 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t cfg_cnt               : 10; /**< [  9:  0] Specifies the number of 64-bit job configuration words to fetch starting from
                                                                 MDBW_JD_CFG_PTR_S[START_ADDR].  Supports up to 1022 64-bit words. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_cnt               : 10; /**< [  9:  0] Specifies the number of 64-bit job configuration words to fetch starting from
                                                                 MDBW_JD_CFG_PTR_S[START_ADDR].  Supports up to 1022 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t dma_p0_rdcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit read DMA command words to fetch starting from
                                                                 MDBW_JD_DMA_PTR_S[START_ADDR].  Supports up to 1023 64-bit words. */
        uint64_t reserved_26_31        : 6;
        uint64_t dma_p0_wrcnt          : 10; /**< [ 41: 32] Specifies the number of 64-bit write DMA command words to fetch starting from
                                                                 MDBW_JD_DMA_PTR_S[START_ADDR].  Supports up to 1023 64-bit words. */
        uint64_t reserved_42_46        : 5;
        uint64_t jce_cnt               : 6;  /**< [ 52: 47] Specifies the number of 64-bit job completion event words to fetch starting from
                                                                 MDBW_JD_JCE_PTR_S[START_ADDR].
                                                                 Supports up to 62 x 64-bit words, i.e., 31 JCE commands. */
        uint64_t toth_tick             : 4;  /**< [ 56: 53] Timeout threshold tick count. See MDBW_JD_HDR_WORD_0_S[TOTH] for
                                                                 details. */
        uint64_t toth                  : 4;  /**< [ 60: 57] Job timeout threshold. The timeout timer starts counting when the job
                                                                 gets started on a DAC. The timer increments by one each SCLK cycle,
                                                                 and a timeout occurs when the timer reaches the threshold specified
                                                                 as:

                                                                 _ ((MDBW()_JD_CFG[TIMEOUT_MULT]\<\<4)+[TOTH])*2^([TOTH_TICK]+4)

                                                                 Setting [TOTH]=0 disables the timeout timer.

                                                                 For example, to get 10.24 us timeout value when BPHY runs at 1GHz,
                                                                 set [TOTH_TICK]=0x6, [TOTH]=0xA, and MDBW()_JD_CFG[TIMEOUT_MULT]=0x1. */
        uint64_t dsp_job_type          : 2;  /**< [ 62: 61] Indicates whether DMA is performed under software control or automatic
                                                                 hardware control. Job types are enumerated with MDBW_DSP_JOB_SEL_E. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbw_jd_hdr_word_0_s_s cnf95xx; */
    struct cavm_mdbw_jd_hdr_word_0_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t dsp_job_type          : 2;  /**< [ 62: 61] Indicates whether DMA is performed under software control or automatic
                                                                 hardware control. Job types are enumerated with MDBW_DSP_JOB_SEL_E. */
        uint64_t toth                  : 4;  /**< [ 60: 57] Job timeout threshold. The timeout timer starts counting when the job
                                                                 gets started on a DAC. The timer increments by one each SCLK cycle,
                                                                 and a timeout occurs when the timer reaches the threshold specified
                                                                 as:

                                                                 _ ((MDBW()_JD_CFG[TIMEOUT_MULT]\<\<4)+[TOTH])*2^([TOTH_TICK]+4)

                                                                 Setting [TOTH]=0 disables the timeout timer.

                                                                 For example, to get 10.24 us timeout value when BPHY runs at 1GHz,
                                                                 set [TOTH_TICK]=0x6, [TOTH]=0xA, and MDBW()_JD_CFG[TIMEOUT_MULT]=0x1. */
        uint64_t toth_tick             : 4;  /**< [ 56: 53] Timeout threshold tick count. See MDBW_JD_HDR_WORD_0_S[TOTH] for
                                                                 details. */
        uint64_t jce_cnt               : 6;  /**< [ 52: 47] Specifies the number of 64-bit job completion event words to fetch starting from
                                                                 MDBW_JD_JCE_PTR_S[START_ADDR].
                                                                 Supports up to 62 64-bit words, i.e., 31 JCE commands. */
        uint64_t reserved_42_46        : 5;
        uint64_t dma_p0_wrcnt          : 10; /**< [ 41: 32] Specifies the number of 64-bit write DMA command words to fetch starting from
                                                                 MDBW_JD_DMA_PTR_S[START_ADDR].  Supports up to 1023 64-bit words. */
        uint64_t reserved_26_31        : 6;
        uint64_t dma_p0_rdcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit read DMA command words to fetch starting from
                                                                 MDBW_JD_DMA_PTR_S[START_ADDR].  Supports up to 1023 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t cfg_cnt               : 10; /**< [  9:  0] Specifies the number of 64-bit job configuration words to fetch starting from
                                                                 MDBW_JD_CFG_PTR_S[START_ADDR].  Supports up to 1022 64-bit words. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_cnt               : 10; /**< [  9:  0] Specifies the number of 64-bit job configuration words to fetch starting from
                                                                 MDBW_JD_CFG_PTR_S[START_ADDR].  Supports up to 1022 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t dma_p0_rdcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit read DMA command words to fetch starting from
                                                                 MDBW_JD_DMA_PTR_S[START_ADDR].  Supports up to 1023 64-bit words. */
        uint64_t reserved_26_31        : 6;
        uint64_t dma_p0_wrcnt          : 10; /**< [ 41: 32] Specifies the number of 64-bit write DMA command words to fetch starting from
                                                                 MDBW_JD_DMA_PTR_S[START_ADDR].  Supports up to 1023 64-bit words. */
        uint64_t reserved_42_46        : 5;
        uint64_t jce_cnt               : 6;  /**< [ 52: 47] Specifies the number of 64-bit job completion event words to fetch starting from
                                                                 MDBW_JD_JCE_PTR_S[START_ADDR].
                                                                 Supports up to 62 64-bit words, i.e., 31 JCE commands. */
        uint64_t toth_tick             : 4;  /**< [ 56: 53] Timeout threshold tick count. See MDBW_JD_HDR_WORD_0_S[TOTH] for
                                                                 details. */
        uint64_t toth                  : 4;  /**< [ 60: 57] Job timeout threshold. The timeout timer starts counting when the job
                                                                 gets started on a DAC. The timer increments by one each SCLK cycle,
                                                                 and a timeout occurs when the timer reaches the threshold specified
                                                                 as:

                                                                 _ ((MDBW()_JD_CFG[TIMEOUT_MULT]\<\<4)+[TOTH])*2^([TOTH_TICK]+4)

                                                                 Setting [TOTH]=0 disables the timeout timer.

                                                                 For example, to get 10.24 us timeout value when BPHY runs at 1GHz,
                                                                 set [TOTH_TICK]=0x6, [TOTH]=0xA, and MDBW()_JD_CFG[TIMEOUT_MULT]=0x1. */
        uint64_t dsp_job_type          : 2;  /**< [ 62: 61] Indicates whether DMA is performed under software control or automatic
                                                                 hardware control. Job types are enumerated with MDBW_DSP_JOB_SEL_E. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } loki;
};

/**
 * Structure mdbw_jd_jce_ptr_s
 *
 * MDBW Job Completion Event Pointer Structure
 * The MDBW job completion event (JCE) pointer subdescriptor specifies an indirection pointer
 * location for the JCE descriptors. This subdescriptor is required for all jobs.
 */
union cavm_mdbw_jd_jce_ptr_s
{
    uint64_t u;
    struct cavm_mdbw_jd_jce_ptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t target_mem            : 1;  /**< [ 63: 63] Specifies the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
        uint64_t reserved_53_62        : 10;
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the JCE subdescriptor start address pointer as a byte location. The address has
                                                                 to be naturally aligned to a 64-bit the descriptor size, i.e., bits [2:0] = 0. */
#else /* Word 0 - Little Endian */
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the JCE subdescriptor start address pointer as a byte location. The address has
                                                                 to be naturally aligned to a 64-bit the descriptor size, i.e., bits [2:0] = 0. */
        uint64_t reserved_53_62        : 10;
        uint64_t target_mem            : 1;  /**< [ 63: 63] Specifies the target memory for the operation as enumerated in MDBW_TMEM_SEL_E. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbw_jd_jce_ptr_s_s cn; */
};

/**
 * Register (RSL) mdbw#_ab_port_hp
 *
 * MDBW AB Port High Priority Register
 * This register set, specifies the port priority per MDBW, per AB, per read and write port.
 */
union cavm_mdbwx_ab_port_hp
{
    uint64_t u;
    struct cavm_mdbwx_ab_port_hp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t wr_hp                 : 1;  /**< [  1:  1](R/W) Write port is high priority when set. */
        uint64_t rd_hp                 : 1;  /**< [  0:  0](R/W) Read port is high priority when set. */
#else /* Word 0 - Little Endian */
        uint64_t rd_hp                 : 1;  /**< [  0:  0](R/W) Read port is high priority when set. */
        uint64_t wr_hp                 : 1;  /**< [  1:  1](R/W) Write port is high priority when set. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_port_hp_s cn; */
};
typedef union cavm_mdbwx_ab_port_hp cavm_mdbwx_ab_port_hp_t;

static inline uint64_t CAVM_MDBWX_AB_PORT_HP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_PORT_HP(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002350ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002350ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_AB_PORT_HP", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_PORT_HP(a) cavm_mdbwx_ab_port_hp_t
#define bustype_CAVM_MDBWX_AB_PORT_HP(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_PORT_HP(a) "MDBWX_AB_PORT_HP"
#define busnum_CAVM_MDBWX_AB_PORT_HP(a) (a)
#define arguments_CAVM_MDBWX_AB_PORT_HP(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_cderr_oflow_jtag
 *
 * MDBW CFG DMA Overflow Error Job Tag Registers
 * This register set, specifies the config DMA overflow error logging of job tag
 * corresponding to the interrupt message per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_cderr_oflow_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_cderr_oflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_cderr_oflow_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_cderr_oflow_jtag cavm_mdbwx_ab_sltx_cderr_oflow_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_CDERR_OFLOW_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_CDERR_OFLOW_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044000f40ll + 0x4000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044000f40ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_CDERR_OFLOW_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_CDERR_OFLOW_JTAG(a,b) cavm_mdbwx_ab_sltx_cderr_oflow_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_CDERR_OFLOW_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_CDERR_OFLOW_JTAG(a,b) "MDBWX_AB_SLTX_CDERR_OFLOW_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_CDERR_OFLOW_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_CDERR_OFLOW_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_cderr_uflow_jtag
 *
 * MDBW CFG DMA Underflow Error Job Tag Registers
 * This register set, specifies the config DMA underflow error logging of job tag
 * corresponding to the interrupt message per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_cderr_uflow_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_cderr_uflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_cderr_uflow_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_cderr_uflow_jtag cavm_mdbwx_ab_sltx_cderr_uflow_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_CDERR_UFLOW_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_CDERR_UFLOW_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044000f50ll + 0x4000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044000f50ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_CDERR_UFLOW_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_CDERR_UFLOW_JTAG(a,b) cavm_mdbwx_ab_sltx_cderr_uflow_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_CDERR_UFLOW_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_CDERR_UFLOW_JTAG(a,b) "MDBWX_AB_SLTX_CDERR_UFLOW_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_CDERR_UFLOW_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_CDERR_UFLOW_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_cfg_fat_jtag
 *
 * MDBW CFG DMA Fatal Error Job Tag Register
 * This register set, specifies the Config DMA fatal error logging of the job tag,
 * corresponding to the interrupt message register per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_cfg_fat_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_cfg_fat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_cfg_fat_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_cfg_fat_jtag cavm_mdbwx_ab_sltx_cfg_fat_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_CFG_FAT_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_CFG_FAT_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001900ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001900ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_CFG_FAT_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_CFG_FAT_JTAG(a,b) cavm_mdbwx_ab_sltx_cfg_fat_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_CFG_FAT_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_CFG_FAT_JTAG(a,b) "MDBWX_AB_SLTX_CFG_FAT_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_CFG_FAT_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_CFG_FAT_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_cfg_nfat_jtag
 *
 * MDBW CFG DMA Non-Fatal Error Job Tag Register
 * This register set, specifies the Config DMA non-fatal error logging of the job tag,
 * corresponding to the interrupt message register per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_cfg_nfat_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_cfg_nfat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_cfg_nfat_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_cfg_nfat_jtag cavm_mdbwx_ab_sltx_cfg_nfat_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_CFG_NFAT_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_CFG_NFAT_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044002100ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044002100ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_CFG_NFAT_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_CFG_NFAT_JTAG(a,b) cavm_mdbwx_ab_sltx_cfg_nfat_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_CFG_NFAT_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_CFG_NFAT_JTAG(a,b) "MDBWX_AB_SLTX_CFG_NFAT_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_CFG_NFAT_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_CFG_NFAT_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_cp_fat_jtag
 *
 * MDBW Control Path Fatal Error Job Tag Register
 * This register set, specifies the control path (JMGR, AB) fatal error event logging of the job
 * tag, corresponding to the interrupt message per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_cp_fat_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_cp_fat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t ab                    : 16; /**< [ 47: 32](RO/H) This set of bits, specifies the AB (DAC) error job tag.
                                                                 Internal:
                                                                 The tag might not be
                                                                 latest tag or accurate. As the error
                                                                 signal can be asserted by the AB (DAC) in the absence of a job as well. */
        uint64_t jd_fetch              : 16; /**< [ 31: 16](RO/H) This set of bits, specifies the job descriptor fetch, had a GHAB response with a fatal
                                                                 error.

                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t job_sd_fetch          : 16; /**< [ 15:  0](RO/H) This set of bits, the job subdescriptor fetch, had a GHAB response with a fatal error. */
#else /* Word 0 - Little Endian */
        uint64_t job_sd_fetch          : 16; /**< [ 15:  0](RO/H) This set of bits, the job subdescriptor fetch, had a GHAB response with a fatal error. */
        uint64_t jd_fetch              : 16; /**< [ 31: 16](RO/H) This set of bits, specifies the job descriptor fetch, had a GHAB response with a fatal
                                                                 error.

                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t ab                    : 16; /**< [ 47: 32](RO/H) This set of bits, specifies the AB (DAC) error job tag.
                                                                 Internal:
                                                                 The tag might not be
                                                                 latest tag or accurate. As the error
                                                                 signal can be asserted by the AB (DAC) in the absence of a job as well. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_cp_fat_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_cp_fat_jtag cavm_mdbwx_ab_sltx_cp_fat_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_CP_FAT_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_CP_FAT_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001a00ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001a00ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_CP_FAT_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_CP_FAT_JTAG(a,b) cavm_mdbwx_ab_sltx_cp_fat_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_CP_FAT_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_CP_FAT_JTAG(a,b) "MDBWX_AB_SLTX_CP_FAT_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_CP_FAT_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_CP_FAT_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_cp_nfat_jtag
 *
 * MDBW Control Path Non-Fatal Error Job Tag Register
 * This register set, specifies the control Path (JMGR, AB) non-fatal error event logging of the
 * job tag, corresponding to the interrupt message register per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_cp_nfat_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_cp_nfat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t ab                    : 16; /**< [ 47: 32](RO/H) This set of bits, specifies the AB (DAC) error job tag.
                                                                 Internal:
                                                                 The tag might not be
                                                                 latest tag or accurate. As the error
                                                                 signal can be asserted by the AB (DAC) in the absence of a job as well. */
        uint64_t jd_fetch              : 16; /**< [ 31: 16](RO/H) This set of bits, specifies the job descriptor fetch, had a GHAB response with a fatal
                                                                 error.

                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t job_sd_fetch          : 16; /**< [ 15:  0](RO/H) This set of bits, the job subdescriptor fetch, had a GHAB response with a fatal error. */
#else /* Word 0 - Little Endian */
        uint64_t job_sd_fetch          : 16; /**< [ 15:  0](RO/H) This set of bits, the job subdescriptor fetch, had a GHAB response with a fatal error. */
        uint64_t jd_fetch              : 16; /**< [ 31: 16](RO/H) This set of bits, specifies the job descriptor fetch, had a GHAB response with a fatal
                                                                 error.

                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t ab                    : 16; /**< [ 47: 32](RO/H) This set of bits, specifies the AB (DAC) error job tag.
                                                                 Internal:
                                                                 The tag might not be
                                                                 latest tag or accurate. As the error
                                                                 signal can be asserted by the AB (DAC) in the absence of a job as well. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_cp_nfat_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_cp_nfat_jtag cavm_mdbwx_ab_sltx_cp_nfat_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_CP_NFAT_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_CP_NFAT_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044002200ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044002200ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_CP_NFAT_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_CP_NFAT_JTAG(a,b) cavm_mdbwx_ab_sltx_cp_nfat_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_CP_NFAT_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_CP_NFAT_JTAG(a,b) "MDBWX_AB_SLTX_CP_NFAT_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_CP_NFAT_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_CP_NFAT_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_debug0
 *
 * INTERNAL: MDBW AB Slot Debug Register
 *
 * Internal:
 * This register set specifies debug information per MDBW,  per job slot. This
 * register set contains bits, which specify the write-resend mask. This masks subsequent
 * interrupt transactions for this register. If set indicates an interrupt has been issued for
 * this vector. The bit is reset by hardware if software performs a W1C to any of the
 * corresponding interrupt bits in the interrupt register.
 */
union cavm_mdbwx_ab_sltx_debug0
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_debug0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ferr                  : 1;  /**< [ 63: 63](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for fatal errors. */
        uint64_t nferr                 : 1;  /**< [ 62: 62](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for non-fatal errors. */
        uint64_t derr                  : 1;  /**< [ 61: 61](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for DMA errors. */
        uint64_t adrerr                : 1;  /**< [ 60: 60](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask for address errors. */
        uint64_t reserved_16_59        : 44;
        uint64_t job_id                : 16; /**< [ 15:  0](RO/H) Internal:
                                                                 This set of bits, specifies the job tag, corresponding to the job that is active
                                                                 in the MDBW, per AB, per job slot. */
#else /* Word 0 - Little Endian */
        uint64_t job_id                : 16; /**< [ 15:  0](RO/H) Internal:
                                                                 This set of bits, specifies the job tag, corresponding to the job that is active
                                                                 in the MDBW, per AB, per job slot. */
        uint64_t reserved_16_59        : 44;
        uint64_t adrerr                : 1;  /**< [ 60: 60](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask for address errors. */
        uint64_t derr                  : 1;  /**< [ 61: 61](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for DMA errors. */
        uint64_t nferr                 : 1;  /**< [ 62: 62](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for non-fatal errors. */
        uint64_t ferr                  : 1;  /**< [ 63: 63](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for fatal errors. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_debug0_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_debug0 cavm_mdbwx_ab_sltx_debug0_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_DEBUG0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_DEBUG0(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044002330ll + 0x4000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044002330ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_DEBUG0", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_DEBUG0(a,b) cavm_mdbwx_ab_sltx_debug0_t
#define bustype_CAVM_MDBWX_AB_SLTX_DEBUG0(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_DEBUG0(a,b) "MDBWX_AB_SLTX_DEBUG0"
#define busnum_CAVM_MDBWX_AB_SLTX_DEBUG0(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_DEBUG0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_derr_ena_w1c
 *
 * MDBW DMA Error Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_mdbwx_ab_sltx_derr_ena_w1c
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_derr_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t reserved_13_24        : 12;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_13_24        : 12;
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_derr_ena_w1c_s cnf95xx; */
    struct cavm_mdbwx_ab_sltx_derr_ena_w1c_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t reserved_13_24        : 12;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_13_24        : 12;
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_ab_sltx_derr_ena_w1c cavm_mdbwx_ab_sltx_derr_ena_w1c_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_DERR_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_DERR_ENA_W1C(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001100ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001100ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_DERR_ENA_W1C", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1C(a,b) cavm_mdbwx_ab_sltx_derr_ena_w1c_t
#define bustype_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1C(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1C(a,b) "MDBWX_AB_SLTX_DERR_ENA_W1C"
#define busnum_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1C(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_derr_ena_w1s
 *
 * MDBW DMA Error Message Enable Set Registers
 * This register sets interrupt enable bits.
 */
union cavm_mdbwx_ab_sltx_derr_ena_w1s
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_derr_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t reserved_13_24        : 12;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_13_24        : 12;
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_derr_ena_w1s_s cnf95xx; */
    struct cavm_mdbwx_ab_sltx_derr_ena_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t reserved_13_24        : 12;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_13_24        : 12;
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_ab_sltx_derr_ena_w1s cavm_mdbwx_ab_sltx_derr_ena_w1s_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_DERR_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_DERR_ENA_W1S(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001000ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001000ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_DERR_ENA_W1S", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1S(a,b) cavm_mdbwx_ab_sltx_derr_ena_w1s_t
#define bustype_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1S(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1S(a,b) "MDBWX_AB_SLTX_DERR_ENA_W1S"
#define busnum_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1S(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_DERR_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_derr_int
 *
 * MDBW DMA Error Message Interrupt Register
 * This register set specifies the DMA overflow/underflow error interrupt vector per MDBW per
 * job slot. These generate DMA error interrupts to the PSM, which drives this signal to the CIU.
 */
union cavm_mdbwx_ab_sltx_derr_int
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_derr_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1C/H) This bit specifies the config DMA underflow error. */
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1C/H) This bit specifies the config DMA overflow error. */
        uint64_t reserved_13_24        : 12;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) This bit specifies the write DMA port underflow error. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) This bit specifies the write DMA port overflow error. */
        uint64_t reserved_5_7          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) This bit specifies the read DMA port 0 underflow error. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) This bit specifies the read DMA port overflow error. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) This bit specifies the read DMA port overflow error. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) This bit specifies the read DMA port 0 underflow error. */
        uint64_t reserved_5_7          : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) This bit specifies the write DMA port overflow error. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) This bit specifies the write DMA port underflow error. */
        uint64_t reserved_13_24        : 12;
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1C/H) This bit specifies the config DMA overflow error. */
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1C/H) This bit specifies the config DMA underflow error. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_derr_int_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_derr_int cavm_mdbwx_ab_sltx_derr_int_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_DERR_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_DERR_INT(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044000e00ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044000e00ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_DERR_INT", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_DERR_INT(a,b) cavm_mdbwx_ab_sltx_derr_int_t
#define bustype_CAVM_MDBWX_AB_SLTX_DERR_INT(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_DERR_INT(a,b) "MDBWX_AB_SLTX_DERR_INT"
#define busnum_CAVM_MDBWX_AB_SLTX_DERR_INT(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_DERR_INT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_derr_int_w1s
 *
 * MDBW DMA Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_mdbwx_ab_sltx_derr_int_w1s
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_derr_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t reserved_13_24        : 12;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_13_24        : 12;
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_derr_int_w1s_s cnf95xx; */
    struct cavm_mdbwx_ab_sltx_derr_int_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t reserved_13_24        : 12;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t reserved_13_24        : 12;
        uint64_t cfg_dma_oflow         : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_OFLOW]. */
        uint64_t cfg_dma_uflow         : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_DERR_INT[CFG_DMA_UFLOW]. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_ab_sltx_derr_int_w1s cavm_mdbwx_ab_sltx_derr_int_w1s_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_DERR_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_DERR_INT_W1S(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001200ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001200ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_DERR_INT_W1S", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_DERR_INT_W1S(a,b) cavm_mdbwx_ab_sltx_derr_int_w1s_t
#define bustype_CAVM_MDBWX_AB_SLTX_DERR_INT_W1S(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_DERR_INT_W1S(a,b) "MDBWX_AB_SLTX_DERR_INT_W1S"
#define busnum_CAVM_MDBWX_AB_SLTX_DERR_INT_W1S(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_DERR_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_fat_err_ena_w1c
 *
 * MDBW Fatal Error Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_mdbwx_ab_sltx_fat_err_ena_w1c
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_fat_err_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_fat_err_ena_w1c_s cnf95xx; */
    struct cavm_mdbwx_ab_sltx_fat_err_ena_w1c_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_ab_sltx_fat_err_ena_w1c cavm_mdbwx_ab_sltx_fat_err_ena_w1c_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1C(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001500ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001500ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_FAT_ERR_ENA_W1C", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1C(a,b) cavm_mdbwx_ab_sltx_fat_err_ena_w1c_t
#define bustype_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1C(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1C(a,b) "MDBWX_AB_SLTX_FAT_ERR_ENA_W1C"
#define busnum_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1C(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_fat_err_ena_w1s
 *
 * MDBW Fatal Error Message Enable Set Registers
 * This register sets interrupt enable bits.
 */
union cavm_mdbwx_ab_sltx_fat_err_ena_w1s
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_fat_err_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_fat_err_ena_w1s_s cnf95xx; */
    struct cavm_mdbwx_ab_sltx_fat_err_ena_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_ab_sltx_fat_err_ena_w1s cavm_mdbwx_ab_sltx_fat_err_ena_w1s_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1S(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001400ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001400ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_FAT_ERR_ENA_W1S", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1S(a,b) cavm_mdbwx_ab_sltx_fat_err_ena_w1s_t
#define bustype_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1S(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1S(a,b) "MDBWX_AB_SLTX_FAT_ERR_ENA_W1S"
#define busnum_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1S(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_FAT_ERR_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_fat_err_int
 *
 * MDBW Fatal Error Message Interrupt Register
 * This register set specifies the fatal error interrupt vector per MDBW per job slot. These
 * generate fatal error interrupts to the PSM, which drives this signal to the CIU.
 */
union cavm_mdbwx_ab_sltx_fat_err_int
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_fat_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) This bit specifies that the AB (DAC) had a fatal error. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) This bit specifies the job descriptor fetch, had a GHAB response with a fatal error.
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) This bit specifies the job subdescriptor fetch, had a GHAB response with a fatal error. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) This bit specifies that the DAC Configuration DMA has a fatal Error . */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) This bit specifies the write DMA port 0 has a fatal error. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) This bit specifies the read DMA port 0 has a fatal error. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) This bit specifies the read DMA port 0 has a fatal error. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) This bit specifies the write DMA port 0 has a fatal error. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) This bit specifies that the DAC Configuration DMA has a fatal Error . */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) This bit specifies the job subdescriptor fetch, had a GHAB response with a fatal error. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) This bit specifies the job descriptor fetch, had a GHAB response with a fatal error.
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) This bit specifies that the AB (DAC) had a fatal error. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_fat_err_int_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_fat_err_int cavm_mdbwx_ab_sltx_fat_err_int_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_FAT_ERR_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_FAT_ERR_INT(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001300ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001300ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_FAT_ERR_INT", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT(a,b) cavm_mdbwx_ab_sltx_fat_err_int_t
#define bustype_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT(a,b) "MDBWX_AB_SLTX_FAT_ERR_INT"
#define busnum_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_fat_err_int_w1s
 *
 * MDBW Fatal Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_mdbwx_ab_sltx_fat_err_int_w1s
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_fat_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_fat_err_int_w1s_s cnf95xx; */
    struct cavm_mdbwx_ab_sltx_fat_err_int_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 Since this
                                                                 happens before AB or job slot
                                                                 assignment, the error is a single bit and always reported in AB(0), Slot(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_ab_sltx_fat_err_int_w1s cavm_mdbwx_ab_sltx_fat_err_int_w1s_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_FAT_ERR_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_FAT_ERR_INT_W1S(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001600ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001600ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_FAT_ERR_INT_W1S", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT_W1S(a,b) cavm_mdbwx_ab_sltx_fat_err_int_w1s_t
#define bustype_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT_W1S(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT_W1S(a,b) "MDBWX_AB_SLTX_FAT_ERR_INT_W1S"
#define busnum_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT_W1S(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_FAT_ERR_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_nfat_err_ena_w1c
 *
 * MDBW Non-Fatal Error Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_mdbwx_ab_sltx_nfat_err_ena_w1c
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_nfat_err_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_nfat_err_ena_w1c_s cnf95xx; */
    struct cavm_mdbwx_ab_sltx_nfat_err_ena_w1c_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_ab_sltx_nfat_err_ena_w1c cavm_mdbwx_ab_sltx_nfat_err_ena_w1c_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1C(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001d00ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001d00ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_NFAT_ERR_ENA_W1C", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1C(a,b) cavm_mdbwx_ab_sltx_nfat_err_ena_w1c_t
#define bustype_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1C(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1C(a,b) "MDBWX_AB_SLTX_NFAT_ERR_ENA_W1C"
#define busnum_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1C(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_nfat_err_ena_w1s
 *
 * MDBW Non-Fatal Error Message Enable Set Registers
 * This register sets interrupt enable bits.
 */
union cavm_mdbwx_ab_sltx_nfat_err_ena_w1s
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_nfat_err_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_nfat_err_ena_w1s_s cnf95xx; */
    struct cavm_mdbwx_ab_sltx_nfat_err_ena_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_ab_sltx_nfat_err_ena_w1s cavm_mdbwx_ab_sltx_nfat_err_ena_w1s_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1S(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001c00ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001c00ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_NFAT_ERR_ENA_W1S", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1S(a,b) cavm_mdbwx_ab_sltx_nfat_err_ena_w1s_t
#define bustype_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1S(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1S(a,b) "MDBWX_AB_SLTX_NFAT_ERR_ENA_W1S"
#define busnum_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1S(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_NFAT_ERR_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_nfat_err_int
 *
 * MDBW Non-Fatal Error Message Interrupt Register
 * This register set, specifies the non-fatal error interrupt vector per MDBW per job slot. These
 * generate non-fatal error interrupts to the PSM, which drives this signal to the GIC.
 */
union cavm_mdbwx_ab_sltx_nfat_err_int
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_nfat_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) This bit specifies the AB (DAC) had a non-fatal error. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) This bit specifies the job descriptor fetch, had a GHAB response with a fatal error.
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) This bit specifies the job subdescriptor fetch, had a GHAB response with a fatal error. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) This bit specifies that the DAC Configuration DMA has a non-fatal error. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) This bit specifies that the write DMA port 0 has a non-fatal error. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) This bit specifies that the read DMA port 0 has a non-fatal error. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) This bit specifies that the read DMA port 0 has a non-fatal error. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) This bit specifies that the write DMA port 0 has a non-fatal error. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1C/H) This bit specifies that the DAC Configuration DMA has a non-fatal error. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) This bit specifies the job subdescriptor fetch, had a GHAB response with a fatal error. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) This bit specifies the job descriptor fetch, had a GHAB response with a fatal error.
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) This bit specifies the AB (DAC) had a non-fatal error. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_nfat_err_int_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_nfat_err_int cavm_mdbwx_ab_sltx_nfat_err_int_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001b00ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001b00ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_NFAT_ERR_INT", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT(a,b) cavm_mdbwx_ab_sltx_nfat_err_int_t
#define bustype_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT(a,b) "MDBWX_AB_SLTX_NFAT_ERR_INT"
#define busnum_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_nfat_err_int_w1s
 *
 * MDBW Non-Fatal Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_mdbwx_ab_sltx_nfat_err_int_w1s
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_nfat_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MDBW(0..41)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_nfat_err_int_w1s_s cnf95xx; */
    struct cavm_mdbwx_ab_sltx_nfat_err_int_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_9_11         : 3;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t reserved_1_7          : 7;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_9_11         : 3;
        uint64_t cfg_dma               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[CFG_DMA]. */
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[JD_FETCH].
                                                                 Internal:
                                                                 This error, job tag is only valid for SLT(0). */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MDBW(0..15)_AB_SLT(0..1)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_ab_sltx_nfat_err_int_w1s cavm_mdbwx_ab_sltx_nfat_err_int_w1s_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT_W1S(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001e00ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001e00ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_NFAT_ERR_INT_W1S", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT_W1S(a,b) cavm_mdbwx_ab_sltx_nfat_err_int_w1s_t
#define bustype_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT_W1S(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT_W1S(a,b) "MDBWX_AB_SLTX_NFAT_ERR_INT_W1S"
#define busnum_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT_W1S(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_NFAT_ERR_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_rd_fat_jtag
 *
 * MDBW RD DMA Fatal Error Job Tag Register
 * This register set, specfies the read DMA fatal error event logging of the job tag,
 * corresponding to the interrupt message register per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_rd_fat_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_rd_fat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_rd_fat_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_rd_fat_jtag cavm_mdbwx_ab_sltx_rd_fat_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_RD_FAT_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_RD_FAT_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001700ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001700ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_RD_FAT_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_RD_FAT_JTAG(a,b) cavm_mdbwx_ab_sltx_rd_fat_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_RD_FAT_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_RD_FAT_JTAG(a,b) "MDBWX_AB_SLTX_RD_FAT_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_RD_FAT_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_RD_FAT_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_rd_nfat_jtag
 *
 * MDBW RD DMA Non-Fatal Error Job Tag Register
 * This register set, specifies the read DMA non-fatal error event logging of the job tag,
 * corresponding to the interrupt register per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_rd_nfat_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_rd_nfat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_rd_nfat_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_rd_nfat_jtag cavm_mdbwx_ab_sltx_rd_nfat_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_RD_NFAT_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_RD_NFAT_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001f00ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001f00ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_RD_NFAT_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_RD_NFAT_JTAG(a,b) cavm_mdbwx_ab_sltx_rd_nfat_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_RD_NFAT_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_RD_NFAT_JTAG(a,b) "MDBWX_AB_SLTX_RD_NFAT_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_RD_NFAT_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_RD_NFAT_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_rderr_oflow_jtag
 *
 * MDBW Read DMA Error Overflow Job Tag Registers
 * This register set, specifies the read DMA overflow error logging of job tag
 * corresponding to the interrupt message per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_rderr_oflow_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_rderr_oflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_rderr_oflow_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_rderr_oflow_jtag cavm_mdbwx_ab_sltx_rderr_oflow_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_RDERR_OFLOW_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_RDERR_OFLOW_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044000f00ll + 0x4000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044000f00ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_RDERR_OFLOW_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_RDERR_OFLOW_JTAG(a,b) cavm_mdbwx_ab_sltx_rderr_oflow_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_RDERR_OFLOW_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_RDERR_OFLOW_JTAG(a,b) "MDBWX_AB_SLTX_RDERR_OFLOW_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_RDERR_OFLOW_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_RDERR_OFLOW_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_rderr_uflow_jtag
 *
 * MDBW Read DMA Error Underflow Job Tag Registers
 * This register set, specifies the read DMA underflow error logging of job tag
 * corresponding to the interrupt message per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_rderr_uflow_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_rderr_uflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_rderr_uflow_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_rderr_uflow_jtag cavm_mdbwx_ab_sltx_rderr_uflow_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_RDERR_UFLOW_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_RDERR_UFLOW_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044000f10ll + 0x4000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044000f10ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_RDERR_UFLOW_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_RDERR_UFLOW_JTAG(a,b) cavm_mdbwx_ab_sltx_rderr_uflow_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_RDERR_UFLOW_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_RDERR_UFLOW_JTAG(a,b) "MDBWX_AB_SLTX_RDERR_UFLOW_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_RDERR_UFLOW_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_RDERR_UFLOW_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_wderr_oflow_jtag
 *
 * MDBW WR DMA Error Overflow Job Tag Register
 * This register set, specfies the write DMA overflow error event logging of the job
 * tag, corresponding to the interrupt per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_wderr_oflow_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_wderr_oflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_wderr_oflow_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_wderr_oflow_jtag cavm_mdbwx_ab_sltx_wderr_oflow_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_WDERR_OFLOW_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_WDERR_OFLOW_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044000f20ll + 0x4000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044000f20ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_WDERR_OFLOW_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_WDERR_OFLOW_JTAG(a,b) cavm_mdbwx_ab_sltx_wderr_oflow_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_WDERR_OFLOW_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_WDERR_OFLOW_JTAG(a,b) "MDBWX_AB_SLTX_WDERR_OFLOW_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_WDERR_OFLOW_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_WDERR_OFLOW_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_wderr_uflow_jtag
 *
 * MDBW WR DMA Error Underflow Job Tag Register
 * This register set, specfies the write DMA underflow error event logging of the job
 * tag, corresponding to the interrupt per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_wderr_uflow_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_wderr_uflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_wderr_uflow_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_wderr_uflow_jtag cavm_mdbwx_ab_sltx_wderr_uflow_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_WDERR_UFLOW_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_WDERR_UFLOW_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044000f30ll + 0x4000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044000f30ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_WDERR_UFLOW_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_WDERR_UFLOW_JTAG(a,b) cavm_mdbwx_ab_sltx_wderr_uflow_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_WDERR_UFLOW_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_WDERR_UFLOW_JTAG(a,b) "MDBWX_AB_SLTX_WDERR_UFLOW_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_WDERR_UFLOW_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_WDERR_UFLOW_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_wr_fat_jtag
 *
 * MDBW WR DMA Fatal Error Job Tag Register
 * This register set, specifies the write DMA fatal error event logging of the job tag,
 * corresponding to the interrupt message per MDBW per job slot.
 * register.
 */
union cavm_mdbwx_ab_sltx_wr_fat_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_wr_fat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_wr_fat_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_wr_fat_jtag cavm_mdbwx_ab_sltx_wr_fat_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_WR_FAT_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_WR_FAT_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044001800ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044001800ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_WR_FAT_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_WR_FAT_JTAG(a,b) cavm_mdbwx_ab_sltx_wr_fat_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_WR_FAT_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_WR_FAT_JTAG(a,b) "MDBWX_AB_SLTX_WR_FAT_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_WR_FAT_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_WR_FAT_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_ab_slt#_wr_nfat_jtag
 *
 * MDBW WR DMA Non-Fatal Error Job Tag Register
 * This register set, specifies the write DMA non-fatal error logging of the job tag,
 * corresponding to the interrupt message register per MDBW per job slot.
 */
union cavm_mdbwx_ab_sltx_wr_nfat_jtag
{
    uint64_t u;
    struct cavm_mdbwx_ab_sltx_wr_nfat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) This set of bits, specifies the DMA port 0 job tag. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_ab_sltx_wr_nfat_jtag_s cn; */
};
typedef union cavm_mdbwx_ab_sltx_wr_nfat_jtag cavm_mdbwx_ab_sltx_wr_nfat_jtag_t;

static inline uint64_t CAVM_MDBWX_AB_SLTX_WR_NFAT_JTAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_AB_SLTX_WR_NFAT_JTAG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044002000ll + 0x4000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044002000ll + 0x40000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_AB_SLTX_WR_NFAT_JTAG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_AB_SLTX_WR_NFAT_JTAG(a,b) cavm_mdbwx_ab_sltx_wr_nfat_jtag_t
#define bustype_CAVM_MDBWX_AB_SLTX_WR_NFAT_JTAG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_AB_SLTX_WR_NFAT_JTAG(a,b) "MDBWX_AB_SLTX_WR_NFAT_JTAG"
#define busnum_CAVM_MDBWX_AB_SLTX_WR_NFAT_JTAG(a,b) (a)
#define arguments_CAVM_MDBWX_AB_SLTX_WR_NFAT_JTAG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_adr_err_ena_w1c
 *
 * MDBW Address Range Error Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_mdbwx_adr_err_ena_w1c
{
    uint64_t u;
    struct cavm_mdbwx_adr_err_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MDBW(0..41)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MDBW(0..41)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MDBW(0..41)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..41)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..41)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MDBW(0..41)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MDBW(0..41)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MDBW(0..41)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_adr_err_ena_w1c_s cnf95xx; */
    struct cavm_mdbwx_adr_err_ena_w1c_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MDBW(0..15)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MDBW(0..15)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MDBW(0..15)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..15)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MDBW(0..15)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MDBW(0..15)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MDBW(0..15)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MDBW(0..15)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_adr_err_ena_w1c cavm_mdbwx_adr_err_ena_w1c_t;

static inline uint64_t CAVM_MDBWX_ADR_ERR_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ADR_ERR_ENA_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000d10ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000d10ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ADR_ERR_ENA_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ADR_ERR_ENA_W1C(a) cavm_mdbwx_adr_err_ena_w1c_t
#define bustype_CAVM_MDBWX_ADR_ERR_ENA_W1C(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ADR_ERR_ENA_W1C(a) "MDBWX_ADR_ERR_ENA_W1C"
#define busnum_CAVM_MDBWX_ADR_ERR_ENA_W1C(a) (a)
#define arguments_CAVM_MDBWX_ADR_ERR_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_adr_err_ena_w1s
 *
 * MDBW Address Range Error Message Enable Set Registers
 * This register sets interrupt enable bits.
 */
union cavm_mdbwx_adr_err_ena_w1s
{
    uint64_t u;
    struct cavm_mdbwx_adr_err_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MDBW(0..41)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MDBW(0..41)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MDBW(0..41)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..41)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..41)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MDBW(0..41)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MDBW(0..41)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MDBW(0..41)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_adr_err_ena_w1s_s cnf95xx; */
    struct cavm_mdbwx_adr_err_ena_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MDBW(0..15)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MDBW(0..15)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MDBW(0..15)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..15)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MDBW(0..15)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MDBW(0..15)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MDBW(0..15)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MDBW(0..15)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_adr_err_ena_w1s cavm_mdbwx_adr_err_ena_w1s_t;

static inline uint64_t CAVM_MDBWX_ADR_ERR_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ADR_ERR_ENA_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000d08ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000d08ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ADR_ERR_ENA_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ADR_ERR_ENA_W1S(a) cavm_mdbwx_adr_err_ena_w1s_t
#define bustype_CAVM_MDBWX_ADR_ERR_ENA_W1S(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ADR_ERR_ENA_W1S(a) "MDBWX_ADR_ERR_ENA_W1S"
#define busnum_CAVM_MDBWX_ADR_ERR_ENA_W1S(a) (a)
#define arguments_CAVM_MDBWX_ADR_ERR_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_adr_err_int
 *
 * MDBW Address Range Error Interrupt Register
 * These registers record DMA address range check errors.
 * When an error occurs, the job tag is recorded in the following register.
 * MDBW()_ADR_ERR_JTAG
 *
 * In some cases, read overflow/underflow errors are recorded for the wrong
 * slot, and the wrong job tag is recorded.  In these cases, the correct job
 * tag should be available in the HAB_ERROR_SOURCE0 register for the given
 * HAB.
 *
 * When an error occurs, the MHAB sends an error message to PSM which then
 * triggers an interrupt, if enabled. In addition, the MDBW sends the command
 * specified by \<MDBW()_ADR_ERROR_JCE_W1, MDBW()_ADR_ERROR_JCE_W0\>
 * to the PSM.
 */
union cavm_mdbwx_adr_err_int
{
    uint64_t u;
    struct cavm_mdbwx_adr_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) Non-existant access detected for writes. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) Non-existant access detected for reads. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) LLC/DRAM access range error. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) SMEM access range error. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) SMEM access range error. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) LLC/DRAM access range error. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) Non-existant access detected for reads. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) Non-existant access detected for writes. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_adr_err_int_s cn; */
};
typedef union cavm_mdbwx_adr_err_int cavm_mdbwx_adr_err_int_t;

static inline uint64_t CAVM_MDBWX_ADR_ERR_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ADR_ERR_INT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000d00ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000d00ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ADR_ERR_INT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ADR_ERR_INT(a) cavm_mdbwx_adr_err_int_t
#define bustype_CAVM_MDBWX_ADR_ERR_INT(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ADR_ERR_INT(a) "MDBWX_ADR_ERR_INT"
#define busnum_CAVM_MDBWX_ADR_ERR_INT(a) (a)
#define arguments_CAVM_MDBWX_ADR_ERR_INT(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_adr_err_int_w1s
 *
 * MDBW Address Range Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_mdbwx_adr_err_int_w1s
{
    uint64_t u;
    struct cavm_mdbwx_adr_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MDBW(0..41)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MDBW(0..41)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MDBW(0..41)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..41)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..41)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MDBW(0..41)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MDBW(0..41)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MDBW(0..41)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_adr_err_int_w1s_s cnf95xx; */
    struct cavm_mdbwx_adr_err_int_w1s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MDBW(0..15)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MDBW(0..15)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MDBW(0..15)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..15)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MDBW(0..15)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MDBW(0..15)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MDBW(0..15)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MDBW(0..15)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_mdbwx_adr_err_int_w1s cavm_mdbwx_adr_err_int_w1s_t;

static inline uint64_t CAVM_MDBWX_ADR_ERR_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ADR_ERR_INT_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000d18ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000d18ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ADR_ERR_INT_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ADR_ERR_INT_W1S(a) cavm_mdbwx_adr_err_int_w1s_t
#define bustype_CAVM_MDBWX_ADR_ERR_INT_W1S(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ADR_ERR_INT_W1S(a) "MDBWX_ADR_ERR_INT_W1S"
#define busnum_CAVM_MDBWX_ADR_ERR_INT_W1S(a) (a)
#define arguments_CAVM_MDBWX_ADR_ERR_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_adr_err_jtag
 *
 * MDBW Address Range Error Job Tag Registers
 * This register records the job tag of an address range error interrupt.
 * In some cases, the wrong job tag will be recorded.
 * In these cases, the HAB_ERROR_SOURCE0 register for the given HAB
 * should report the correct job tag.
 */
union cavm_mdbwx_adr_err_jtag
{
    uint64_t u;
    struct cavm_mdbwx_adr_err_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t gaa_wr_nxm            : 16; /**< [ 63: 48](RO/H) The job tag for a GAA write NXM error. */
        uint64_t gaa_rd_nxm            : 16; /**< [ 47: 32](RO/H) The job tag for a GAA read NXM error. */
        uint64_t ddr_range             : 16; /**< [ 31: 16](RO/H) The job tag for a DDR out of range error. */
        uint64_t smem_range            : 16; /**< [ 15:  0](RO/H) The job tag for a SMEM out of range error. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range            : 16; /**< [ 15:  0](RO/H) The job tag for a SMEM out of range error. */
        uint64_t ddr_range             : 16; /**< [ 31: 16](RO/H) The job tag for a DDR out of range error. */
        uint64_t gaa_rd_nxm            : 16; /**< [ 47: 32](RO/H) The job tag for a GAA read NXM error. */
        uint64_t gaa_wr_nxm            : 16; /**< [ 63: 48](RO/H) The job tag for a GAA write NXM error. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_adr_err_jtag_s cn; */
};
typedef union cavm_mdbwx_adr_err_jtag cavm_mdbwx_adr_err_jtag_t;

static inline uint64_t CAVM_MDBWX_ADR_ERR_JTAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ADR_ERR_JTAG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000d20ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000d20ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ADR_ERR_JTAG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ADR_ERR_JTAG(a) cavm_mdbwx_adr_err_jtag_t
#define bustype_CAVM_MDBWX_ADR_ERR_JTAG(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ADR_ERR_JTAG(a) "MDBWX_ADR_ERR_JTAG"
#define busnum_CAVM_MDBWX_ADR_ERR_JTAG(a) (a)
#define arguments_CAVM_MDBWX_ADR_ERR_JTAG(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_adr_error_jce_w0
 *
 * MDBW Address Error JCE Word 0 Register
 * This register specifies the low 64 bits of a PSM command issued when an
 * address error occurs.
 */
union cavm_mdbwx_adr_error_jce_w0
{
    uint64_t u;
    struct cavm_mdbwx_adr_error_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a job timeout. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a job timeout. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_adr_error_jce_w0_s cn; */
};
typedef union cavm_mdbwx_adr_error_jce_w0 cavm_mdbwx_adr_error_jce_w0_t;

static inline uint64_t CAVM_MDBWX_ADR_ERROR_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ADR_ERROR_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000060ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000060ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ADR_ERROR_JCE_W0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ADR_ERROR_JCE_W0(a) cavm_mdbwx_adr_error_jce_w0_t
#define bustype_CAVM_MDBWX_ADR_ERROR_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ADR_ERROR_JCE_W0(a) "MDBWX_ADR_ERROR_JCE_W0"
#define busnum_CAVM_MDBWX_ADR_ERROR_JCE_W0(a) (a)
#define arguments_CAVM_MDBWX_ADR_ERROR_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_adr_error_jce_w1
 *
 * MDBW Address Error JCE Word 1 Register
 * This register specifies the high 64 bits of a PSM command issued when an
 * address error occurs.
 */
union cavm_mdbwx_adr_error_jce_w1
{
    uint64_t u;
    struct cavm_mdbwx_adr_error_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a job timeout. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a job timeout. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_adr_error_jce_w1_s cn; */
};
typedef union cavm_mdbwx_adr_error_jce_w1 cavm_mdbwx_adr_error_jce_w1_t;

static inline uint64_t CAVM_MDBWX_ADR_ERROR_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ADR_ERROR_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000068ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000068ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ADR_ERROR_JCE_W1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ADR_ERROR_JCE_W1(a) cavm_mdbwx_adr_error_jce_w1_t
#define bustype_CAVM_MDBWX_ADR_ERROR_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ADR_ERROR_JCE_W1(a) "MDBWX_ADR_ERROR_JCE_W1"
#define busnum_CAVM_MDBWX_ADR_ERROR_JCE_W1(a) (a)
#define arguments_CAVM_MDBWX_ADR_ERROR_JCE_W1(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_cfg
 *
 * MDBW Configuration Register
 * This register set, specifies the configuration for each MDBW globally in terms of reset, clock
 * and priority levels.
 */
union cavm_mdbwx_cfg
{
    uint64_t u;
    struct cavm_mdbwx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_51_63        : 13;
        uint64_t mdbw_done             : 1;  /**< [ 50: 50](RO/H) This bit is set, after this register's [ENA] bit = 0, and indicates the MDBW has completed
                                                                 clearing internal states corresponding to PSM Jobs. This bit must be set, before software
                                                                 reenables the MDBW by setting [ENA] = 1.

                                                                 Internal:
                                                                 Used to indicate SW MDBW reset is complete. */
        uint64_t ab_done               : 1;  /**< [ 49: 49](RO/H) This bit is used to indicate the MDBW has completed clearing internal states corresponding
                                                                 to
                                                                 an AB. This bit is reset by hardware after a MDBW is reenabled.

                                                                 Internal:
                                                                 Used to indicate SW reset sequence is complete. */
        uint64_t reserved_29_48        : 20;
        uint64_t mdbw_stopped          : 1;  /**< [ 28: 28](RO/H) This bit is set, after this register's [ENA] bit = 0, and indicates the MDBW is busy
                                                                 clearing internal states corresponding to PSM Jobs. This bit must be equal to 0, before
                                                                 software reenables the MDBW by setting [ENA] = 1.

                                                                 Internal:
                                                                 Used to indicate SW reset sequence is in progress. */
        uint64_t reserved_25_27        : 3;
        uint64_t ab_stopped            : 1;  /**< [ 24: 24](RO/H) This bit is set indicates the MDBW is busy clearing internal states corresponding to an
                                                                 AB. This bit must be equal to 0, before software reenables the AB by setting [AB_ENA] =
                                                                 1.

                                                                 Internal:
                                                                 Used to indicate SW reset sequence is in progress. */
        uint64_t reserved_21_23        : 3;
        uint64_t ab_busy               : 1;  /**< [ 20: 20](RO/H) This bit is set indicates the AB is busy processing a job. */
        uint64_t reserved_17_19        : 3;
        uint64_t ab_ena                : 1;  /**< [ 16: 16](R/W) This bit defines the enable corresponding to the AB within the MDBW.
                                                                 Internal:
                                                                 Used as a conditional reset for the AB's. */
        uint64_t reserved_7_15         : 9;
        uint64_t ab_cclk_pwait_dis     : 1;  /**< [  6:  6](R/W) Set one to disable the DSP conditional clock gating when DSP is in PWAIT sleep mode.
                                                                 During DSP sleep mode, the DSP conditional clock is turned off if this bit is set to 0. */
        uint64_t reserved_5            : 1;
        uint64_t ab_cclk_force_on      : 1;  /**< [  4:  4](R/W) Set one to force the DSP conditional clock to be always on. For diagnostic use only. */
        uint64_t nojob_runstall_ena    : 1;  /**< [  3:  3](R/W) When set, force DAC RUNSTALL=1 when MDBW has no MDAB jobs to process.
                                                                 DSP RUNSTALL=1 will force the internal DSP pipeline to STALL (to save DSP core power).
                                                                 When this bit is ENABLED, the DSP pipeline is forced to STALL (to save power),
                                                                 and the STALL will only be released when a new Job arrives [DSP Slave mode]. */
        uint64_t job_slot_ena          : 1;  /**< [  2:  2](R/W) This bit enables MDBW job slot scheduling. Setting this bit = 0, all AB's will use slot 0
                                                                 for all subsequent
                                                                 jobs. Software must ensure the MDBW is in an idle state, i.e., without any active or
                                                                 pending jobs enqueued, before setting this bit.

                                                                 Internal:
                                                                 Used as a backup measure only. */
        uint64_t ena                   : 1;  /**< [  1:  1](R/W) This bit enables the MDBW. Setting this bit = 0, does not reset any MDBW CSR
                                                                 setting or stats; it only resets the JMGR, AMM logic.

                                                                 Internal:
                                                                 Used as a conditional
                                                                 reset for the MDBW. */
        uint64_t mdbw_cclk_force_on    : 1;  /**< [  0:  0](R/W) Set one to force the MDBW conditional clock to be always on. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t mdbw_cclk_force_on    : 1;  /**< [  0:  0](R/W) Set one to force the MDBW conditional clock to be always on. For diagnostic use only. */
        uint64_t ena                   : 1;  /**< [  1:  1](R/W) This bit enables the MDBW. Setting this bit = 0, does not reset any MDBW CSR
                                                                 setting or stats; it only resets the JMGR, AMM logic.

                                                                 Internal:
                                                                 Used as a conditional
                                                                 reset for the MDBW. */
        uint64_t job_slot_ena          : 1;  /**< [  2:  2](R/W) This bit enables MDBW job slot scheduling. Setting this bit = 0, all AB's will use slot 0
                                                                 for all subsequent
                                                                 jobs. Software must ensure the MDBW is in an idle state, i.e., without any active or
                                                                 pending jobs enqueued, before setting this bit.

                                                                 Internal:
                                                                 Used as a backup measure only. */
        uint64_t nojob_runstall_ena    : 1;  /**< [  3:  3](R/W) When set, force DAC RUNSTALL=1 when MDBW has no MDAB jobs to process.
                                                                 DSP RUNSTALL=1 will force the internal DSP pipeline to STALL (to save DSP core power).
                                                                 When this bit is ENABLED, the DSP pipeline is forced to STALL (to save power),
                                                                 and the STALL will only be released when a new Job arrives [DSP Slave mode]. */
        uint64_t ab_cclk_force_on      : 1;  /**< [  4:  4](R/W) Set one to force the DSP conditional clock to be always on. For diagnostic use only. */
        uint64_t reserved_5            : 1;
        uint64_t ab_cclk_pwait_dis     : 1;  /**< [  6:  6](R/W) Set one to disable the DSP conditional clock gating when DSP is in PWAIT sleep mode.
                                                                 During DSP sleep mode, the DSP conditional clock is turned off if this bit is set to 0. */
        uint64_t reserved_7_15         : 9;
        uint64_t ab_ena                : 1;  /**< [ 16: 16](R/W) This bit defines the enable corresponding to the AB within the MDBW.
                                                                 Internal:
                                                                 Used as a conditional reset for the AB's. */
        uint64_t reserved_17_19        : 3;
        uint64_t ab_busy               : 1;  /**< [ 20: 20](RO/H) This bit is set indicates the AB is busy processing a job. */
        uint64_t reserved_21_23        : 3;
        uint64_t ab_stopped            : 1;  /**< [ 24: 24](RO/H) This bit is set indicates the MDBW is busy clearing internal states corresponding to an
                                                                 AB. This bit must be equal to 0, before software reenables the AB by setting [AB_ENA] =
                                                                 1.

                                                                 Internal:
                                                                 Used to indicate SW reset sequence is in progress. */
        uint64_t reserved_25_27        : 3;
        uint64_t mdbw_stopped          : 1;  /**< [ 28: 28](RO/H) This bit is set, after this register's [ENA] bit = 0, and indicates the MDBW is busy
                                                                 clearing internal states corresponding to PSM Jobs. This bit must be equal to 0, before
                                                                 software reenables the MDBW by setting [ENA] = 1.

                                                                 Internal:
                                                                 Used to indicate SW reset sequence is in progress. */
        uint64_t reserved_29_48        : 20;
        uint64_t ab_done               : 1;  /**< [ 49: 49](RO/H) This bit is used to indicate the MDBW has completed clearing internal states corresponding
                                                                 to
                                                                 an AB. This bit is reset by hardware after a MDBW is reenabled.

                                                                 Internal:
                                                                 Used to indicate SW reset sequence is complete. */
        uint64_t mdbw_done             : 1;  /**< [ 50: 50](RO/H) This bit is set, after this register's [ENA] bit = 0, and indicates the MDBW has completed
                                                                 clearing internal states corresponding to PSM Jobs. This bit must be set, before software
                                                                 reenables the MDBW by setting [ENA] = 1.

                                                                 Internal:
                                                                 Used to indicate SW MDBW reset is complete. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_cfg_s cn; */
};
typedef union cavm_mdbwx_cfg cavm_mdbwx_cfg_t;

static inline uint64_t CAVM_MDBWX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_CFG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000000ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000000ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_CFG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_CFG(a) cavm_mdbwx_cfg_t
#define bustype_CAVM_MDBWX_CFG(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_CFG(a) "MDBWX_CFG"
#define busnum_CAVM_MDBWX_CFG(a) (a)
#define arguments_CAVM_MDBWX_CFG(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_debug1
 *
 * INTERNAL: MDBW Debug 1 Register
 *
 * Internal:
 * This register set, specifies special debug CSR's for internal used per MDBW.
 * Specifically, This
 * register set contains bits, which specify the a master reset to the MDBW.
 */
union cavm_mdbwx_debug1
{
    uint64_t u;
    struct cavm_mdbwx_debug1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t master_reset_n        : 1;  /**< [ 63: 63](R/W) Internal:
                                                                 This debug reset bit is used to reset (active low) the MAB irrespective of
                                                                 quiescience state.
                                                                 This must not be used unless it is assured there are no PSM credit returns required.
                                                                 Alternatively, the PSM queue and credits for this MAB needs to be restored after this
                                                                 operation. Further, all system access for this MHB needs to be flushed from the system
                                                                 before re-enabling this block. This is primarily for debug puposes only. Writing a 0
                                                                 resets the MDB and writing a 1 brings the MDB out of reset. */
        uint64_t cfg_arb_sel           : 1;  /**< [ 62: 62](R/W) Internal:
                                                                 If this bit is set to 1, indicates a higher (fixed) priority for CFG DMA
                                                                 requests over RD-DMA CFG requests. When this bit is set to 0 both the CFG DMA and RD DMA
                                                                 CFG requests are arbitrated on a round-robin basis. */
        uint64_t reserved_2_61         : 60;
        uint64_t dac_dbg_en            : 1;  /**< [  1:  1](R/W) Set one to enable DAC debug signals to be driven on dbg3 data bus. */
        uint64_t amm_dbg_en            : 1;  /**< [  0:  0](R/W) Set one to enable DMA debug signals to be driven on dbg3 data bus. */
#else /* Word 0 - Little Endian */
        uint64_t amm_dbg_en            : 1;  /**< [  0:  0](R/W) Set one to enable DMA debug signals to be driven on dbg3 data bus. */
        uint64_t dac_dbg_en            : 1;  /**< [  1:  1](R/W) Set one to enable DAC debug signals to be driven on dbg3 data bus. */
        uint64_t reserved_2_61         : 60;
        uint64_t cfg_arb_sel           : 1;  /**< [ 62: 62](R/W) Internal:
                                                                 If this bit is set to 1, indicates a higher (fixed) priority for CFG DMA
                                                                 requests over RD-DMA CFG requests. When this bit is set to 0 both the CFG DMA and RD DMA
                                                                 CFG requests are arbitrated on a round-robin basis. */
        uint64_t master_reset_n        : 1;  /**< [ 63: 63](R/W) Internal:
                                                                 This debug reset bit is used to reset (active low) the MAB irrespective of
                                                                 quiescience state.
                                                                 This must not be used unless it is assured there are no PSM credit returns required.
                                                                 Alternatively, the PSM queue and credits for this MAB needs to be restored after this
                                                                 operation. Further, all system access for this MHB needs to be flushed from the system
                                                                 before re-enabling this block. This is primarily for debug puposes only. Writing a 0
                                                                 resets the MDB and writing a 1 brings the MDB out of reset. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_debug1_s cn; */
};
typedef union cavm_mdbwx_debug1 cavm_mdbwx_debug1_t;

static inline uint64_t CAVM_MDBWX_DEBUG1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_DEBUG1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002340ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002340ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_DEBUG1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_DEBUG1(a) cavm_mdbwx_debug1_t
#define bustype_CAVM_MDBWX_DEBUG1(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_DEBUG1(a) "MDBWX_DEBUG1"
#define busnum_CAVM_MDBWX_DEBUG1(a) (a)
#define arguments_CAVM_MDBWX_DEBUG1(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_dma_error_jce_w0
 *
 * MDBW JCE DMA Error Word 0 Register
 * This register set, specifies the DMA error job completion message word 0 per MDBW.
 */
union cavm_mdbwx_dma_error_jce_w0
{
    uint64_t u;
    struct cavm_mdbwx_dma_error_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 0 for a DMA error job completion status to send to
                                                                 PSM \<w1,w0\>. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 0 for a DMA error job completion status to send to
                                                                 PSM \<w1,w0\>. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_dma_error_jce_w0_s cn; */
};
typedef union cavm_mdbwx_dma_error_jce_w0 cavm_mdbwx_dma_error_jce_w0_t;

static inline uint64_t CAVM_MDBWX_DMA_ERROR_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_DMA_ERROR_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000020ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000020ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_DMA_ERROR_JCE_W0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_DMA_ERROR_JCE_W0(a) cavm_mdbwx_dma_error_jce_w0_t
#define bustype_CAVM_MDBWX_DMA_ERROR_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_DMA_ERROR_JCE_W0(a) "MDBWX_DMA_ERROR_JCE_W0"
#define busnum_CAVM_MDBWX_DMA_ERROR_JCE_W0(a) (a)
#define arguments_CAVM_MDBWX_DMA_ERROR_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_dma_error_jce_w1
 *
 * MDBW JCE DMA Error Word 1 Register
 * This register set, specifies the DMA error job completion message word 1 per MDBW.
 */
union cavm_mdbwx_dma_error_jce_w1
{
    uint64_t u;
    struct cavm_mdbwx_dma_error_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) This set of bits defines the word 1 for a DMA error job completion status to send to PSM \<w1,w0\>. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) This set of bits defines the word 1 for a DMA error job completion status to send to PSM \<w1,w0\>. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_dma_error_jce_w1_s cn; */
};
typedef union cavm_mdbwx_dma_error_jce_w1 cavm_mdbwx_dma_error_jce_w1_t;

static inline uint64_t CAVM_MDBWX_DMA_ERROR_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_DMA_ERROR_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000028ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000028ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_DMA_ERROR_JCE_W1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_DMA_ERROR_JCE_W1(a) cavm_mdbwx_dma_error_jce_w1_t
#define bustype_CAVM_MDBWX_DMA_ERROR_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_DMA_ERROR_JCE_W1(a) "MDBWX_DMA_ERROR_JCE_W1"
#define busnum_CAVM_MDBWX_DMA_ERROR_JCE_W1(a) (a)
#define arguments_CAVM_MDBWX_DMA_ERROR_JCE_W1(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_dv_scratch
 *
 * INTERNAL: MDBW Verification Scratch Register
 *
 * Internal:
 * This register set, defines a scratch register for verification purposes only per
 * MDBW.
 */
union cavm_mdbwx_dv_scratch
{
    uint64_t u;
    struct cavm_mdbwx_dv_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t it                    : 64; /**< [ 63:  0](R/W) Internal:
                                                                 This set of bits are specified for DV only. */
#else /* Word 0 - Little Endian */
        uint64_t it                    : 64; /**< [ 63:  0](R/W) Internal:
                                                                 This set of bits are specified for DV only. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_dv_scratch_s cn; */
};
typedef union cavm_mdbwx_dv_scratch cavm_mdbwx_dv_scratch_t;

static inline uint64_t CAVM_MDBWX_DV_SCRATCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_DV_SCRATCH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002f10ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002f10ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_DV_SCRATCH", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_DV_SCRATCH(a) cavm_mdbwx_dv_scratch_t
#define bustype_CAVM_MDBWX_DV_SCRATCH(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_DV_SCRATCH(a) "MDBWX_DV_SCRATCH"
#define busnum_CAVM_MDBWX_DV_SCRATCH(a) (a)
#define arguments_CAVM_MDBWX_DV_SCRATCH(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_eco
 *
 * INTERNAL: MDBW ECO Register
 */
union cavm_mdbwx_eco
{
    uint64_t u;
    struct cavm_mdbwx_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage.(Has AB CTRL signals tied to it) */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage.(Has AB CTRL signals tied to it) */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_eco_s cn; */
};
typedef union cavm_mdbwx_eco cavm_mdbwx_eco_t;

static inline uint64_t CAVM_MDBWX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ECO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002f00ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002f00ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ECO", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ECO(a) cavm_mdbwx_eco_t
#define bustype_CAVM_MDBWX_ECO(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ECO(a) "MDBWX_ECO"
#define busnum_CAVM_MDBWX_ECO(a) (a)
#define arguments_CAVM_MDBWX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_err_stat0
 *
 * MDBW Errors Statistic 0 Register
 * This register set specifies the statistic for the number of errors (except SBE's and
 * DBE's) per MDBW.
 *
 * Internal:
 * If the stat counter indicates per clock increment, this implies one
 * of error singalling was a level signal and did not conform to specification. It also indicates
 * a potential deadlock condition, if the counter rolls on for an extended period of time.
 */
union cavm_mdbwx_err_stat0
{
    uint64_t u;
    struct cavm_mdbwx_err_stat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nfat_err_stat         : 32; /**< [ 63: 32](R/W/H) This set of bits specifies the statistic counter value of non-fatal errors. */
        uint64_t fat_err_stat          : 32; /**< [ 31:  0](R/W/H) This set of bits specifies the statistic counter value of fatal errors. */
#else /* Word 0 - Little Endian */
        uint64_t fat_err_stat          : 32; /**< [ 31:  0](R/W/H) This set of bits specifies the statistic counter value of fatal errors. */
        uint64_t nfat_err_stat         : 32; /**< [ 63: 32](R/W/H) This set of bits specifies the statistic counter value of non-fatal errors. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_err_stat0_s cn; */
};
typedef union cavm_mdbwx_err_stat0 cavm_mdbwx_err_stat0_t;

static inline uint64_t CAVM_MDBWX_ERR_STAT0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ERR_STAT0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002318ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002318ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ERR_STAT0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ERR_STAT0(a) cavm_mdbwx_err_stat0_t
#define bustype_CAVM_MDBWX_ERR_STAT0(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ERR_STAT0(a) "MDBWX_ERR_STAT0"
#define busnum_CAVM_MDBWX_ERR_STAT0(a) (a)
#define arguments_CAVM_MDBWX_ERR_STAT0(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_err_stat1
 *
 * MDBW Errors Statistic 1 Register
 * This register set specifies the statistic for the number of DMA errors per MDBW.
 * Internal:
 * If
 * the stat counter indicates per clock increment, this implies one
 * of error singalling was a level signal and did not conform to specification. It also indicates
 * a potential deadlock condition, if the counter rolls on for an extended period of time.
 */
union cavm_mdbwx_err_stat1
{
    uint64_t u;
    struct cavm_mdbwx_err_stat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t adr_err_stat          : 32; /**< [ 63: 32](R/W/H) Count of address range errors.
                                                                 Internal:
                                                                 This does not account for multiple
                                                                 DMA errors that might occur across different jobs, AB's in the same clock cycle. */
        uint64_t dma_err_stat          : 32; /**< [ 31:  0](R/W/H) This set of bits, specifies the number of DMA errors.
                                                                 Internal:
                                                                 This does not account for
                                                                 multiple
                                                                 DMA errors that might occur across different jobs, AB's in the same clock cycle. */
#else /* Word 0 - Little Endian */
        uint64_t dma_err_stat          : 32; /**< [ 31:  0](R/W/H) This set of bits, specifies the number of DMA errors.
                                                                 Internal:
                                                                 This does not account for
                                                                 multiple
                                                                 DMA errors that might occur across different jobs, AB's in the same clock cycle. */
        uint64_t adr_err_stat          : 32; /**< [ 63: 32](R/W/H) Count of address range errors.
                                                                 Internal:
                                                                 This does not account for multiple
                                                                 DMA errors that might occur across different jobs, AB's in the same clock cycle. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_err_stat1_s cn; */
};
typedef union cavm_mdbwx_err_stat1 cavm_mdbwx_err_stat1_t;

static inline uint64_t CAVM_MDBWX_ERR_STAT1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_ERR_STAT1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002320ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002320ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_ERR_STAT1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_ERR_STAT1(a) cavm_mdbwx_err_stat1_t
#define bustype_CAVM_MDBWX_ERR_STAT1(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_ERR_STAT1(a) "MDBWX_ERR_STAT1"
#define busnum_CAVM_MDBWX_ERR_STAT1(a) (a)
#define arguments_CAVM_MDBWX_ERR_STAT1(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_fatal_error_jce_w0
 *
 * MDBW JCE Fatal Error Word 0 Register
 * This register set, specifies fatal error job completion message word 0 per MDBW.
 */
union cavm_mdbwx_fatal_error_jce_w0
{
    uint64_t u;
    struct cavm_mdbwx_fatal_error_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 0 for a fatal error job completion status to send to
                                                                 PSM \<w1,w0\>. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 0 for a fatal error job completion status to send to
                                                                 PSM \<w1,w0\>. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_fatal_error_jce_w0_s cn; */
};
typedef union cavm_mdbwx_fatal_error_jce_w0 cavm_mdbwx_fatal_error_jce_w0_t;

static inline uint64_t CAVM_MDBWX_FATAL_ERROR_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_FATAL_ERROR_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000030ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000030ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_FATAL_ERROR_JCE_W0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_FATAL_ERROR_JCE_W0(a) cavm_mdbwx_fatal_error_jce_w0_t
#define bustype_CAVM_MDBWX_FATAL_ERROR_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_FATAL_ERROR_JCE_W0(a) "MDBWX_FATAL_ERROR_JCE_W0"
#define busnum_CAVM_MDBWX_FATAL_ERROR_JCE_W0(a) (a)
#define arguments_CAVM_MDBWX_FATAL_ERROR_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_fatal_error_jce_w1
 *
 * MDBW JCE Fatal Error Word 1 Register
 * This register set, specifies the fatal error job completion message word 1 per MDBW.
 */
union cavm_mdbwx_fatal_error_jce_w1
{
    uint64_t u;
    struct cavm_mdbwx_fatal_error_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 1 for a fatal error job completion status to send to
                                                                 PSM \<w1,w0\>. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 1 for a fatal error job completion status to send to
                                                                 PSM \<w1,w0\>. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_fatal_error_jce_w1_s cn; */
};
typedef union cavm_mdbwx_fatal_error_jce_w1 cavm_mdbwx_fatal_error_jce_w1_t;

static inline uint64_t CAVM_MDBWX_FATAL_ERROR_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_FATAL_ERROR_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000038ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000038ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_FATAL_ERROR_JCE_W1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_FATAL_ERROR_JCE_W1(a) cavm_mdbwx_fatal_error_jce_w1_t
#define bustype_CAVM_MDBWX_FATAL_ERROR_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_FATAL_ERROR_JCE_W1(a) "MDBWX_FATAL_ERROR_JCE_W1"
#define busnum_CAVM_MDBWX_FATAL_ERROR_JCE_W1(a) (a)
#define arguments_CAVM_MDBWX_FATAL_ERROR_JCE_W1(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_fyi
 *
 * MDBW For your information Register
 * This register set, specifies the hardware specifications per MDBW.
 */
union cavm_mdbwx_fyi
{
    uint64_t u;
    struct cavm_mdbwx_fyi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t psm_did               : 6;  /**< [ 63: 58](RO) This set of bits, specifies the PSM bus device ID for the MDBW. */
        uint64_t reserved_57           : 1;
        uint64_t pnb                   : 1;  /**< [ 56: 56](RO) The PNB channel number for LLC/DRAM access. */
        uint64_t ghb                   : 4;  /**< [ 55: 52](RO) The GHAB number the MHAB attached to. */
        uint64_t reserved_51           : 1;
        uint64_t ghb_port              : 3;  /**< [ 50: 48](RO) The GHAB port number the MHAB attached to. */
        uint64_t reserved_40_47        : 8;
        uint64_t ab_cores              : 2;  /**< [ 39: 38](RO) This set of bits, specifies the number of AB cores present in the MDBW;
                                                                 where the number of cores =  MDBW()_FYI[AB_CORES] + 1. */
        uint64_t ab_cfg_credit_ena     : 1;  /**< [ 37: 37](RO) This bit specifies, if the AB config interface uses credit based access. */
        uint64_t num_ab_rd_ports       : 2;  /**< [ 36: 35](RO) This set of bits, specifies the number of AB read ports; where the number of RD ports =
                                                                 MDBW()_FYI[NUM_AB_RD_PORTS] + 1. */
        uint64_t num_ab_wr_ports       : 2;  /**< [ 34: 33](RO) This set of bits, specifies the number of AB write ports; where the number of WR ports =
                                                                 MDBW()_FYI[NUM_AB_WR_PORTS] + 1. */
        uint64_t num_ab_job_slots      : 2;  /**< [ 32: 31](RO) This set of bits, specifies the number of AB job slots; where the number of job slots =
                                                                 MDBW()_FYI[NUM_AB_JOB_SLOTS] + 1. */
        uint64_t ab_rd_port_0          : 2;  /**< [ 30: 29](RO) This set of bits, specifies the read port 0 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_rd_port_1          : 2;  /**< [ 28: 27](RO) This set of bits, specifies the read port 1 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_rd_port_2          : 2;  /**< [ 26: 25](RO) This set of bits, specifies the read port 2 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_rd_port_3          : 2;  /**< [ 24: 23](RO) This set of bits, specifies the read port 3 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_wr_port_0          : 2;  /**< [ 22: 21](RO) This set of bits, specifies the write port 0 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_wr_port_1          : 2;  /**< [ 20: 19](RO) This set of bits, specifies the write port 1 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_wr_port_2          : 2;  /**< [ 18: 17](RO) This set of bits, specifies the write port 2 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_wr_port_3          : 2;  /**< [ 16: 15](RO) This set of bits, specifies the write port 3 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t reserved_0_14         : 15;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_14         : 15;
        uint64_t ab_wr_port_3          : 2;  /**< [ 16: 15](RO) This set of bits, specifies the write port 3 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_wr_port_2          : 2;  /**< [ 18: 17](RO) This set of bits, specifies the write port 2 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_wr_port_1          : 2;  /**< [ 20: 19](RO) This set of bits, specifies the write port 1 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_wr_port_0          : 2;  /**< [ 22: 21](RO) This set of bits, specifies the write port 0 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_rd_port_3          : 2;  /**< [ 24: 23](RO) This set of bits, specifies the read port 3 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_rd_port_2          : 2;  /**< [ 26: 25](RO) This set of bits, specifies the read port 2 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_rd_port_1          : 2;  /**< [ 28: 27](RO) This set of bits, specifies the read port 1 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t ab_rd_port_0          : 2;  /**< [ 30: 29](RO) This set of bits, specifies the read port 0 width if defined for the AB, enumerated with
                                                                 MDBW_AB_PORT_WIDTH_E. */
        uint64_t num_ab_job_slots      : 2;  /**< [ 32: 31](RO) This set of bits, specifies the number of AB job slots; where the number of job slots =
                                                                 MDBW()_FYI[NUM_AB_JOB_SLOTS] + 1. */
        uint64_t num_ab_wr_ports       : 2;  /**< [ 34: 33](RO) This set of bits, specifies the number of AB write ports; where the number of WR ports =
                                                                 MDBW()_FYI[NUM_AB_WR_PORTS] + 1. */
        uint64_t num_ab_rd_ports       : 2;  /**< [ 36: 35](RO) This set of bits, specifies the number of AB read ports; where the number of RD ports =
                                                                 MDBW()_FYI[NUM_AB_RD_PORTS] + 1. */
        uint64_t ab_cfg_credit_ena     : 1;  /**< [ 37: 37](RO) This bit specifies, if the AB config interface uses credit based access. */
        uint64_t ab_cores              : 2;  /**< [ 39: 38](RO) This set of bits, specifies the number of AB cores present in the MDBW;
                                                                 where the number of cores =  MDBW()_FYI[AB_CORES] + 1. */
        uint64_t reserved_40_47        : 8;
        uint64_t ghb_port              : 3;  /**< [ 50: 48](RO) The GHAB port number the MHAB attached to. */
        uint64_t reserved_51           : 1;
        uint64_t ghb                   : 4;  /**< [ 55: 52](RO) The GHAB number the MHAB attached to. */
        uint64_t pnb                   : 1;  /**< [ 56: 56](RO) The PNB channel number for LLC/DRAM access. */
        uint64_t reserved_57           : 1;
        uint64_t psm_did               : 6;  /**< [ 63: 58](RO) This set of bits, specifies the PSM bus device ID for the MDBW. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_fyi_s cn; */
};
typedef union cavm_mdbwx_fyi cavm_mdbwx_fyi_t;

static inline uint64_t CAVM_MDBWX_FYI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_FYI(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000100ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000100ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_FYI", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_FYI(a) cavm_mdbwx_fyi_t
#define bustype_CAVM_MDBWX_FYI(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_FYI(a) "MDBWX_FYI"
#define busnum_CAVM_MDBWX_FYI(a) (a)
#define arguments_CAVM_MDBWX_FYI(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_jd_cfg
 *
 * MDBW Configuration Register
 * This register set, specifies per job configuration parameters per MDBW.
 */
union cavm_mdbwx_jd_cfg
{
    uint64_t u;
    struct cavm_mdbwx_jd_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr_range_chk_ena    : 1;  /**< [ 63: 63](R/W) LLC/DRAM and SMEM address range check enable. */
        uint64_t ghb_throttle_dis      : 1;  /**< [ 62: 62](R/W) GHAB interface throttle disable. */
        uint64_t reserved_58_61        : 4;
        uint64_t ghb_rd_weight         : 6;  /**< [ 57: 52](R/W) The weighted round-robin arbitration weight used in the GHAB when
                                                                 arbitrating for read requests from this MHAB. A value of zero will
                                                                 only allow requests when there are no competing requests from other
                                                                 MHABs in the same GHAB, or when all competing MHABs have an effective
                                                                 weight of zero. A higher weight guarantees a greater share of the GHAB
                                                                 bandwidth. */
        uint64_t reserved_50_51        : 2;
        uint64_t ghb_wr_weight         : 6;  /**< [ 49: 44](R/W) The weighted round-robin arbitration weight used in the GHAB when
                                                                 arbitrating for read requests from this MHAB. A value of zero will
                                                                 only allow requests when there are no competing requests from other
                                                                 MHABs in the same GHAB, or when all competing MHABs have an effective
                                                                 weight of zero. A higher weight guarantees a greater share of the GHAB
                                                                 bandwidth. */
        uint64_t ghb_rd_off_rate       : 8;  /**< [ 43: 36](R/W) This field specifies the number of cycles a GHAB idle gap can be.
                                                                 An idle gap is a gap inserted during a bursty transfer.
                                                                 A value of 0 means no gaps. */
        uint64_t ghb_rd_on_rate        : 8;  /**< [ 35: 28](R/W) This field specifies the number of contiguous cycles a bursty GHAB transfer can be.
                                                                 A value of 0 stops all GHAB transactions. This field should never be set to 0. */
        uint64_t ghb_wr_off_rate       : 8;  /**< [ 27: 20](R/W) This field specifies the number of cycles a GHAB idle gap can be.
                                                                 An idle gap is a gap inserted during a bursty transfer.
                                                                 A value of 0 means no gaps. */
        uint64_t ghb_wr_on_rate        : 8;  /**< [ 19: 12](R/W) This field specifies the number of contiguous cycles a bursty GHAB transfer can be.
                                                                 A value of 0 stops all GHAB transactions. This field should never be set to 0.
                                                                 For writes to LLC/DRAM, HW allows up to seven cycles over the ON rate limit if the
                                                                 terminal count doesn't align to the cacheline boundary. */
        uint64_t dac_fetch_cmd_type    : 1;  /**< [ 11: 11](R/W) This set of bits, specifies the command type to use for all DAC originating read requests
                                                                 to LLC/DRAM; as enumerated in MDBW_DAC_PNB_RD_CMD_E. */
        uint64_t reserved_8_10         : 3;
        uint64_t timeout_mult          : 4;  /**< [  7:  4](R/W) This set of bits, specifies the timeout multiplier value to be used along with the
                                                                 MDBW_HDR_WORD_0_S[TOTH_TICK]
                                                                 and MDBW_HDR_WORD_0_S[TOTH] field; to determine the the job timeout value. */
        uint64_t dsp_tto               : 1;  /**< [  3:  3](R/W) This bit specifies when the MDBW starts counting for a job timeout specified in
                                                                 MDBW_JD_HDR_WORD_0_S[TOTH]. This bit is = 0; indicates that the specified timeout
                                                                 commences based on when the DSP is busy. This bit is = 1; indicates that the specified
                                                                 timeout commences based on when the job commences internally within the MDBW. Thereby, the
                                                                 timeout is an aggregate sum of all the internal system latencies. */
        uint64_t reserved_2            : 1;
        uint64_t jd_fetch_cmd_type     : 2;  /**< [  1:  0](R/W) This set of bits, specifies the command type to use for all the job descriptor,
                                                                 subdescriptor fetches made by the MDBW as enumerated in MDBW_PNB_RD_CMD_E.
                                                                  * If the MDBW_PNB_RD_CMD_E=LDWB, then the MDBW will issue an LDT for all non full
                                                                 cacheline requests. */
#else /* Word 0 - Little Endian */
        uint64_t jd_fetch_cmd_type     : 2;  /**< [  1:  0](R/W) This set of bits, specifies the command type to use for all the job descriptor,
                                                                 subdescriptor fetches made by the MDBW as enumerated in MDBW_PNB_RD_CMD_E.
                                                                  * If the MDBW_PNB_RD_CMD_E=LDWB, then the MDBW will issue an LDT for all non full
                                                                 cacheline requests. */
        uint64_t reserved_2            : 1;
        uint64_t dsp_tto               : 1;  /**< [  3:  3](R/W) This bit specifies when the MDBW starts counting for a job timeout specified in
                                                                 MDBW_JD_HDR_WORD_0_S[TOTH]. This bit is = 0; indicates that the specified timeout
                                                                 commences based on when the DSP is busy. This bit is = 1; indicates that the specified
                                                                 timeout commences based on when the job commences internally within the MDBW. Thereby, the
                                                                 timeout is an aggregate sum of all the internal system latencies. */
        uint64_t timeout_mult          : 4;  /**< [  7:  4](R/W) This set of bits, specifies the timeout multiplier value to be used along with the
                                                                 MDBW_HDR_WORD_0_S[TOTH_TICK]
                                                                 and MDBW_HDR_WORD_0_S[TOTH] field; to determine the the job timeout value. */
        uint64_t reserved_8_10         : 3;
        uint64_t dac_fetch_cmd_type    : 1;  /**< [ 11: 11](R/W) This set of bits, specifies the command type to use for all DAC originating read requests
                                                                 to LLC/DRAM; as enumerated in MDBW_DAC_PNB_RD_CMD_E. */
        uint64_t ghb_wr_on_rate        : 8;  /**< [ 19: 12](R/W) This field specifies the number of contiguous cycles a bursty GHAB transfer can be.
                                                                 A value of 0 stops all GHAB transactions. This field should never be set to 0.
                                                                 For writes to LLC/DRAM, HW allows up to seven cycles over the ON rate limit if the
                                                                 terminal count doesn't align to the cacheline boundary. */
        uint64_t ghb_wr_off_rate       : 8;  /**< [ 27: 20](R/W) This field specifies the number of cycles a GHAB idle gap can be.
                                                                 An idle gap is a gap inserted during a bursty transfer.
                                                                 A value of 0 means no gaps. */
        uint64_t ghb_rd_on_rate        : 8;  /**< [ 35: 28](R/W) This field specifies the number of contiguous cycles a bursty GHAB transfer can be.
                                                                 A value of 0 stops all GHAB transactions. This field should never be set to 0. */
        uint64_t ghb_rd_off_rate       : 8;  /**< [ 43: 36](R/W) This field specifies the number of cycles a GHAB idle gap can be.
                                                                 An idle gap is a gap inserted during a bursty transfer.
                                                                 A value of 0 means no gaps. */
        uint64_t ghb_wr_weight         : 6;  /**< [ 49: 44](R/W) The weighted round-robin arbitration weight used in the GHAB when
                                                                 arbitrating for read requests from this MHAB. A value of zero will
                                                                 only allow requests when there are no competing requests from other
                                                                 MHABs in the same GHAB, or when all competing MHABs have an effective
                                                                 weight of zero. A higher weight guarantees a greater share of the GHAB
                                                                 bandwidth. */
        uint64_t reserved_50_51        : 2;
        uint64_t ghb_rd_weight         : 6;  /**< [ 57: 52](R/W) The weighted round-robin arbitration weight used in the GHAB when
                                                                 arbitrating for read requests from this MHAB. A value of zero will
                                                                 only allow requests when there are no competing requests from other
                                                                 MHABs in the same GHAB, or when all competing MHABs have an effective
                                                                 weight of zero. A higher weight guarantees a greater share of the GHAB
                                                                 bandwidth. */
        uint64_t reserved_58_61        : 4;
        uint64_t ghb_throttle_dis      : 1;  /**< [ 62: 62](R/W) GHAB interface throttle disable. */
        uint64_t addr_range_chk_ena    : 1;  /**< [ 63: 63](R/W) LLC/DRAM and SMEM address range check enable. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_jd_cfg_s cn; */
};
typedef union cavm_mdbwx_jd_cfg cavm_mdbwx_jd_cfg_t;

static inline uint64_t CAVM_MDBWX_JD_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_JD_CFG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000008ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000008ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_JD_CFG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_JD_CFG(a) cavm_mdbwx_jd_cfg_t
#define bustype_CAVM_MDBWX_JD_CFG(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_JD_CFG(a) "MDBWX_JD_CFG"
#define busnum_CAVM_MDBWX_JD_CFG(a) (a)
#define arguments_CAVM_MDBWX_JD_CFG(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_job_compl_stat
 *
 * MDBW Job Completion Statistic Register
 * This register set specifies the statistic for the number of jobs that have been completed per
 * MDBW.
 */
union cavm_mdbwx_job_compl_stat
{
    uint64_t u;
    struct cavm_mdbwx_job_compl_stat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t stat                  : 48; /**< [ 47:  0](R/W/H) This set of bits specifies the statistic counter value. */
#else /* Word 0 - Little Endian */
        uint64_t stat                  : 48; /**< [ 47:  0](R/W/H) This set of bits specifies the statistic counter value. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_job_compl_stat_s cn; */
};
typedef union cavm_mdbwx_job_compl_stat cavm_mdbwx_job_compl_stat_t;

static inline uint64_t CAVM_MDBWX_JOB_COMPL_STAT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_JOB_COMPL_STAT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002308ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002308ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_JOB_COMPL_STAT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_JOB_COMPL_STAT(a) cavm_mdbwx_job_compl_stat_t
#define bustype_CAVM_MDBWX_JOB_COMPL_STAT(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_JOB_COMPL_STAT(a) "MDBWX_JOB_COMPL_STAT"
#define busnum_CAVM_MDBWX_JOB_COMPL_STAT(a) (a)
#define arguments_CAVM_MDBWX_JOB_COMPL_STAT(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_job_drop_stat
 *
 * MDBW Job Drop Statistic Register
 * This register set specifies the statistic for the number of jobs that have been
 * dropped per MDBW. This
 * indicates jobs that are dropped after the MDBW is disabled.
 */
union cavm_mdbwx_job_drop_stat
{
    uint64_t u;
    struct cavm_mdbwx_job_drop_stat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t stat                  : 32; /**< [ 31:  0](R/W/H) This set of bits specifies the statistic counter value. */
#else /* Word 0 - Little Endian */
        uint64_t stat                  : 32; /**< [ 31:  0](R/W/H) This set of bits specifies the statistic counter value. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_job_drop_stat_s cn; */
};
typedef union cavm_mdbwx_job_drop_stat cavm_mdbwx_job_drop_stat_t;

static inline uint64_t CAVM_MDBWX_JOB_DROP_STAT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_JOB_DROP_STAT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002310ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002310ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_JOB_DROP_STAT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_JOB_DROP_STAT(a) cavm_mdbwx_job_drop_stat_t
#define bustype_CAVM_MDBWX_JOB_DROP_STAT(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_JOB_DROP_STAT(a) "MDBWX_JOB_DROP_STAT"
#define busnum_CAVM_MDBWX_JOB_DROP_STAT(a) (a)
#define arguments_CAVM_MDBWX_JOB_DROP_STAT(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_job_enqueue_stat
 *
 * MDBW Job Enqueue Statistic Register
 * This register set specifies the statistic for the number of jobs that have been enqueued per MDBW.
 */
union cavm_mdbwx_job_enqueue_stat
{
    uint64_t u;
    struct cavm_mdbwx_job_enqueue_stat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t stat                  : 48; /**< [ 47:  0](R/W/H) This set of bits specifies the statistic counter value. */
#else /* Word 0 - Little Endian */
        uint64_t stat                  : 48; /**< [ 47:  0](R/W/H) This set of bits specifies the statistic counter value. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_job_enqueue_stat_s cn; */
};
typedef union cavm_mdbwx_job_enqueue_stat cavm_mdbwx_job_enqueue_stat_t;

static inline uint64_t CAVM_MDBWX_JOB_ENQUEUE_STAT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_JOB_ENQUEUE_STAT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002300ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002300ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_JOB_ENQUEUE_STAT", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_JOB_ENQUEUE_STAT(a) cavm_mdbwx_job_enqueue_stat_t
#define bustype_CAVM_MDBWX_JOB_ENQUEUE_STAT(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_JOB_ENQUEUE_STAT(a) "MDBWX_JOB_ENQUEUE_STAT"
#define busnum_CAVM_MDBWX_JOB_ENQUEUE_STAT(a) (a)
#define arguments_CAVM_MDBWX_JOB_ENQUEUE_STAT(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_jobq#_cfg
 *
 * MDBW Job Queue Configuration Register
 * This register specifies the job queue attributes to each AB core.
 */
union cavm_mdbwx_jobqx_cfg
{
    uint64_t u;
    struct cavm_mdbwx_jobqx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t weight                : 6;  /**< [  9:  4](R/W) The weighted round-robin arbitration weight used in the job queue
                                                                 arbitration. A value of zero will only allow requests when there are no
                                                                 competing requests from the other queue, or when all competing queues
                                                                 have an effective weight of zero. */
        uint64_t ab_sel                : 4;  /**< [  3:  0](R/W) Bit mask to select ABs. A value of one allows the AB to accept jobs. */
#else /* Word 0 - Little Endian */
        uint64_t ab_sel                : 4;  /**< [  3:  0](R/W) Bit mask to select ABs. A value of one allows the AB to accept jobs. */
        uint64_t weight                : 6;  /**< [  9:  4](R/W) The weighted round-robin arbitration weight used in the job queue
                                                                 arbitration. A value of zero will only allow requests when there are no
                                                                 competing requests from the other queue, or when all competing queues
                                                                 have an effective weight of zero. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_jobqx_cfg_s cn; */
};
typedef union cavm_mdbwx_jobqx_cfg cavm_mdbwx_jobqx_cfg_t;

static inline uint64_t CAVM_MDBWX_JOBQX_CFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_JOBQX_CFG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=41) && (b<=1)))
        return 0x87e044000010ll + 0x4000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=15) && (b<=1)))
        return 0x87e044000010ll + 0x40000ll * ((a) & 0xf) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("MDBWX_JOBQX_CFG", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_JOBQX_CFG(a,b) cavm_mdbwx_jobqx_cfg_t
#define bustype_CAVM_MDBWX_JOBQX_CFG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_JOBQX_CFG(a,b) "MDBWX_JOBQX_CFG"
#define busnum_CAVM_MDBWX_JOBQX_CFG(a,b) (a)
#define arguments_CAVM_MDBWX_JOBQX_CFG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mdbw#_non_fatal_error_jce_w0
 *
 * MDBW JCE Non Fatal Error Word 0 Register
 * This register set, specifies the non-fatal error job completion message word 0 per MDBW.
 */
union cavm_mdbwx_non_fatal_error_jce_w0
{
    uint64_t u;
    struct cavm_mdbwx_non_fatal_error_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 0 for a non-fatal error job completion status to send
                                                                 to
                                                                 PSM \<w1,w0\>. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 0 for a non-fatal error job completion status to send
                                                                 to
                                                                 PSM \<w1,w0\>. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_non_fatal_error_jce_w0_s cn; */
};
typedef union cavm_mdbwx_non_fatal_error_jce_w0 cavm_mdbwx_non_fatal_error_jce_w0_t;

static inline uint64_t CAVM_MDBWX_NON_FATAL_ERROR_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_NON_FATAL_ERROR_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000040ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000040ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_NON_FATAL_ERROR_JCE_W0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W0(a) cavm_mdbwx_non_fatal_error_jce_w0_t
#define bustype_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W0(a) "MDBWX_NON_FATAL_ERROR_JCE_W0"
#define busnum_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W0(a) (a)
#define arguments_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_non_fatal_error_jce_w1
 *
 * MDBW JCE Non Fatal Error Word 1 Register
 * This register set, specifies the non-fatal error job completion message word 1 per MDBW.
 */
union cavm_mdbwx_non_fatal_error_jce_w1
{
    uint64_t u;
    struct cavm_mdbwx_non_fatal_error_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 1 for a non-fatal error job completion status to send
                                                                 to
                                                                 PSM \<w1,w0\>. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 1 for a non-fatal error job completion status to send
                                                                 to
                                                                 PSM \<w1,w0\>. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_non_fatal_error_jce_w1_s cn; */
};
typedef union cavm_mdbwx_non_fatal_error_jce_w1 cavm_mdbwx_non_fatal_error_jce_w1_t;

static inline uint64_t CAVM_MDBWX_NON_FATAL_ERROR_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_NON_FATAL_ERROR_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000048ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000048ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_NON_FATAL_ERROR_JCE_W1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W1(a) cavm_mdbwx_non_fatal_error_jce_w1_t
#define bustype_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W1(a) "MDBWX_NON_FATAL_ERROR_JCE_W1"
#define busnum_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W1(a) (a)
#define arguments_CAVM_MDBWX_NON_FATAL_ERROR_JCE_W1(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_phymem_range
 *
 * MDBW BPHY SMEM Address Range Register
 * This register specifies the legal address range for BPHY shared memory access.
 */
union cavm_mdbwx_phymem_range
{
    uint64_t u;
    struct cavm_mdbwx_phymem_range_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t smem_max_addr         : 25; /**< [ 56: 32](R/W) SMEM maximum address. Must be 128-bit aligned. */
        uint64_t reserved_25_31        : 7;
        uint64_t smem_min_addr         : 25; /**< [ 24:  0](R/W) SMEM minimum address. Must be 128-bit aligned. */
#else /* Word 0 - Little Endian */
        uint64_t smem_min_addr         : 25; /**< [ 24:  0](R/W) SMEM minimum address. Must be 128-bit aligned. */
        uint64_t reserved_25_31        : 7;
        uint64_t smem_max_addr         : 25; /**< [ 56: 32](R/W) SMEM maximum address. Must be 128-bit aligned. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_phymem_range_s cn; */
};
typedef union cavm_mdbwx_phymem_range cavm_mdbwx_phymem_range_t;

static inline uint64_t CAVM_MDBWX_PHYMEM_RANGE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_PHYMEM_RANGE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002410ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002410ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_PHYMEM_RANGE", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_PHYMEM_RANGE(a) cavm_mdbwx_phymem_range_t
#define bustype_CAVM_MDBWX_PHYMEM_RANGE(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_PHYMEM_RANGE(a) "MDBWX_PHYMEM_RANGE"
#define busnum_CAVM_MDBWX_PHYMEM_RANGE(a) (a)
#define arguments_CAVM_MDBWX_PHYMEM_RANGE(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_sysmem_range_max
 *
 * MDBW LLC/DRAM Address Range Max Register
 * This register specifies the legal maximum address for system memory access.
 */
union cavm_mdbwx_sysmem_range_max
{
    uint64_t u;
    struct cavm_mdbwx_sysmem_range_max_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ddr_max_addr          : 53; /**< [ 52:  0](R/W) Maximum IOVA for accesses to LLC/DRAM memory. */
#else /* Word 0 - Little Endian */
        uint64_t ddr_max_addr          : 53; /**< [ 52:  0](R/W) Maximum IOVA for accesses to LLC/DRAM memory. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_sysmem_range_max_s cn; */
};
typedef union cavm_mdbwx_sysmem_range_max cavm_mdbwx_sysmem_range_max_t;

static inline uint64_t CAVM_MDBWX_SYSMEM_RANGE_MAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_SYSMEM_RANGE_MAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002408ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002408ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_SYSMEM_RANGE_MAX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_SYSMEM_RANGE_MAX(a) cavm_mdbwx_sysmem_range_max_t
#define bustype_CAVM_MDBWX_SYSMEM_RANGE_MAX(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_SYSMEM_RANGE_MAX(a) "MDBWX_SYSMEM_RANGE_MAX"
#define busnum_CAVM_MDBWX_SYSMEM_RANGE_MAX(a) (a)
#define arguments_CAVM_MDBWX_SYSMEM_RANGE_MAX(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_sysmem_range_min
 *
 * MDBW LLC/DRAM Address Range Min Register
 * This register specifies the legal minimum address for system memory access.
 */
union cavm_mdbwx_sysmem_range_min
{
    uint64_t u;
    struct cavm_mdbwx_sysmem_range_min_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ddr_min_addr          : 53; /**< [ 52:  0](R/W) Minimum IOVA for accesses to LLC/DRAM memory. */
#else /* Word 0 - Little Endian */
        uint64_t ddr_min_addr          : 53; /**< [ 52:  0](R/W) Minimum IOVA for accesses to LLC/DRAM memory. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_sysmem_range_min_s cn; */
};
typedef union cavm_mdbwx_sysmem_range_min cavm_mdbwx_sysmem_range_min_t;

static inline uint64_t CAVM_MDBWX_SYSMEM_RANGE_MIN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_SYSMEM_RANGE_MIN(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044002400ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044002400ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_SYSMEM_RANGE_MIN", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_SYSMEM_RANGE_MIN(a) cavm_mdbwx_sysmem_range_min_t
#define bustype_CAVM_MDBWX_SYSMEM_RANGE_MIN(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_SYSMEM_RANGE_MIN(a) "MDBWX_SYSMEM_RANGE_MIN"
#define busnum_CAVM_MDBWX_SYSMEM_RANGE_MIN(a) (a)
#define arguments_CAVM_MDBWX_SYSMEM_RANGE_MIN(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_timeout_jce_w0
 *
 * MDBW JCE Timeout Word 0 Register
 * This register set, specifies the timeout job completion message word 0 per MDBW.
 */
union cavm_mdbwx_timeout_jce_w0
{
    uint64_t u;
    struct cavm_mdbwx_timeout_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 0 for a timeout job completion status to send to PSM\<w1,w0\>. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 0 for a timeout job completion status to send to PSM\<w1,w0\>. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_timeout_jce_w0_s cn; */
};
typedef union cavm_mdbwx_timeout_jce_w0 cavm_mdbwx_timeout_jce_w0_t;

static inline uint64_t CAVM_MDBWX_TIMEOUT_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_TIMEOUT_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000050ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000050ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_TIMEOUT_JCE_W0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_TIMEOUT_JCE_W0(a) cavm_mdbwx_timeout_jce_w0_t
#define bustype_CAVM_MDBWX_TIMEOUT_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_TIMEOUT_JCE_W0(a) "MDBWX_TIMEOUT_JCE_W0"
#define busnum_CAVM_MDBWX_TIMEOUT_JCE_W0(a) (a)
#define arguments_CAVM_MDBWX_TIMEOUT_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mdbw#_timeout_jce_w1
 *
 * MDBW JCE Timeout Word 1 Register
 * This register set, specifies the timeout job completion message word 1 per MDBW.
 */
union cavm_mdbwx_timeout_jce_w1
{
    uint64_t u;
    struct cavm_mdbwx_timeout_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 1 for a timeout job completion status to send to PSM\<w1,w0\>. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) This set of bits, specifies the word 1 for a timeout job completion status to send to PSM\<w1,w0\>. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mdbwx_timeout_jce_w1_s cn; */
};
typedef union cavm_mdbwx_timeout_jce_w1 cavm_mdbwx_timeout_jce_w1_t;

static inline uint64_t CAVM_MDBWX_TIMEOUT_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MDBWX_TIMEOUT_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=41))
        return 0x87e044000058ll + 0x4000ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=15))
        return 0x87e044000058ll + 0x40000ll * ((a) & 0xf);
    __cavm_csr_fatal("MDBWX_TIMEOUT_JCE_W1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_MDBWX_TIMEOUT_JCE_W1(a) cavm_mdbwx_timeout_jce_w1_t
#define bustype_CAVM_MDBWX_TIMEOUT_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MDBWX_TIMEOUT_JCE_W1(a) "MDBWX_TIMEOUT_JCE_W1"
#define busnum_CAVM_MDBWX_TIMEOUT_JCE_W1(a) (a)
#define arguments_CAVM_MDBWX_TIMEOUT_JCE_W1(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_MDBW_H__ */
