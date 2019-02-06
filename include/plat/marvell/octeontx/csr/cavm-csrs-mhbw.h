#ifndef __CAVM_CSRS_MHBW_H__
#define __CAVM_CSRS_MHBW_H__
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
 * OcteonTX MHBW.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration mhbw_ab_port_width_e
 *
 * MHBW HAB Port Width Enumeration
 */
#define CAVM_MHBW_AB_PORT_WIDTH_E_DW_128 (1)
#define CAVM_MHBW_AB_PORT_WIDTH_E_DW_256 (0)
#define CAVM_MHBW_AB_PORT_WIDTH_E_DW_32 (3)
#define CAVM_MHBW_AB_PORT_WIDTH_E_DW_64 (2)

/**
 * Enumeration mhbw_dma_mode_e
 *
 * MHBW DMA Mode Enumeration
 */
#define CAVM_MHBW_DMA_MODE_E_BLK_DMA (0)
#define CAVM_MHBW_DMA_MODE_E_THREE_D_BLK_DMA (4)
#define CAVM_MHBW_DMA_MODE_E_TWO_D_BLK_DMA_BLKCNT (3)
#define CAVM_MHBW_DMA_MODE_E_TWO_D_BLK_DMA_BLKMSK (2)

/**
 * Enumeration mhbw_ghb_priority_e
 *
 * MHBW GHAB Priority Enumeration
 */
#define CAVM_MHBW_GHB_PRIORITY_E_HIGH (1)
#define CAVM_MHBW_GHB_PRIORITY_E_NORMAL (0)

/**
 * Enumeration mhbw_pnb_dswap_e
 *
 * MHBW PNB Data Swap Enumeration
 * This enumeration describes the different possible data swap operation
 * performed by the PNB.
 */
#define CAVM_MHBW_PNB_DSWAP_E_FOUR_BYTE (3)
#define CAVM_MHBW_PNB_DSWAP_E_NONE (0)
#define CAVM_MHBW_PNB_DSWAP_E_ONE_BYTE (1)
#define CAVM_MHBW_PNB_DSWAP_E_RSVD0 (4)
#define CAVM_MHBW_PNB_DSWAP_E_RSVD1 (5)
#define CAVM_MHBW_PNB_DSWAP_E_RSVD2 (6)
#define CAVM_MHBW_PNB_DSWAP_E_RSVD3 (7)
#define CAVM_MHBW_PNB_DSWAP_E_TWO_BYTE (2)

/**
 * Enumeration mhbw_pnb_rd_cmd_e
 *
 * MHBW Read DMA Command Enumeration
 * This enumeration describes the different command types for reads from
 * L2C/DRAM.
 */
#define CAVM_MHBW_PNB_RD_CMD_E_LDD (0)
#define CAVM_MHBW_PNB_RD_CMD_E_LDT (1)
#define CAVM_MHBW_PNB_RD_CMD_E_LDWB (2)
#define CAVM_MHBW_PNB_RD_CMD_E_RSVD0 (3)

/**
 * Enumeration mhbw_pnb_wr_cmd_e
 *
 * MHBW Write DMA Command Enumeration
 * This enumeration describes the different command types for writes to
 * L2C/DRAM.
 */
#define CAVM_MHBW_PNB_WR_CMD_E_RSVD0 (3)
#define CAVM_MHBW_PNB_WR_CMD_E_STF (1)
#define CAVM_MHBW_PNB_WR_CMD_E_STP (0)
#define CAVM_MHBW_PNB_WR_CMD_E_STT (2)

/**
 * Enumeration mhbw_tmem_sel_e
 *
 * MHBW Target Memory Enumeration
 * This enumeration is used to indicate whether a pointer in a job descriptor
 * describes a location in BPHY SMEM or in main memory.
 */
#define CAVM_MHBW_TMEM_SEL_E_L2C_DDR (1)
#define CAVM_MHBW_TMEM_SEL_E_SMEM (0)

/**
 * Structure mhbw_jd_cfg_data_s
 *
 * INTERNAL: MHBW Job Configuration Data Structure
 *
 * The MHBW config data subdescriptor is written to the hardware driven config space if
 * SLOT_EN=1,
 * else it writes the data from a starting address of zero.
 */
union cavm_mhbw_jd_cfg_data_s
{
    uint64_t u;
    struct cavm_mhbw_jd_cfg_data_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cfg_wr_data           : 64; /**< [ 63:  0] Specifies the config write data to be written. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_wr_data           : 64; /**< [ 63:  0] Specifies the config write data to be written. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_cfg_data_s_s cn; */
};

/**
 * Structure mhbw_jd_cfg_ptr_s
 *
 * MHBW Job Configuration Pointer Structure
 * This structure specifies a pointer to the location of the job
 * configuration data. This pointer is required for all jobs.
 */
union cavm_mhbw_jd_cfg_ptr_s
{
    uint64_t u;
    struct cavm_mhbw_jd_cfg_ptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t target_mem            : 1;  /**< [ 63: 63] Specifies the target memory for the address, as enumerate in
                                                                 MHBW_TMEM_SEL_E. */
        uint64_t reserved_53_62        : 10;
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the byte address of the start of the job configuration data.
                                                                 The address must be 64 bit aligned, i.e., bits[2:0] must be 0. */
#else /* Word 0 - Little Endian */
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the byte address of the start of the job configuration data.
                                                                 The address must be 64 bit aligned, i.e., bits[2:0] must be 0. */
        uint64_t reserved_53_62        : 10;
        uint64_t target_mem            : 1;  /**< [ 63: 63] Specifies the target memory for the address, as enumerate in
                                                                 MHBW_TMEM_SEL_E. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_cfg_ptr_s_s cn; */
};

/**
 * Structure mhbw_jd_dma_cfg_word_0_s
 *
 * MHBW DMA Command Word 0 Structure
 * This structure specifies the format for the first word of each read/write
 * DMA command. All read and write DMA commands must use this structure.
 */
union cavm_mhbw_jd_dma_cfg_word_0_s
{
    uint64_t u;
    struct cavm_mhbw_jd_dma_cfg_word_0_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t group_id              : 4;  /**< [ 59: 56] Group ID is used for multi-threaded DMA ports only. Groups must use
                                                                 sequential IDs starting with 0. If more than 16 groups are required,
                                                                 the GROUP_IDs can be repeated, e.g., 0, 1, 2,..., 15, 0, 1,... */
        uint64_t reserved_54_55        : 2;
        uint64_t thread_id             : 6;  /**< [ 53: 48] Thread ID for this command. Thread IDs can be in the range 0-63,
                                                                 regardless of the number of threads supported on a given port. */
        uint64_t block_size            : 16; /**< [ 47: 32] Defines the DMA block size in 32-bit words.
                                                                 [BLOCK_SIZE] must be a multiple of 2 or 4 for 64-bit or 128-/256-bit
                                                                 ports, . */
        uint64_t chunk_size            : 16; /**< [ 31: 16] For multi-threaded read DMA ports, this field specifies how many words
                                                                 are read from the thread before switching to the next thread.
                                                                 [CHUNK_SIZE] is specified as a number of 32-bit words, and must be
                                                                 of the same granularity as the port width. */
        uint64_t reserved_9_15         : 7;
        uint64_t cmd_type              : 2;  /**< [  8:  7] Command type for LLC/DRAM access. The read and write operations are
                                                                 enumerated with MHBW_PNB_RD_CMD_E and MHBW_PNB_WR_CMD_E respectively.

                                                                 Note that DMA to/from BPHY SMEM ignores this field. */
        uint64_t dswap                 : 3;  /**< [  6:  4] The byte swap mode for DMA to/from LLC/DRAM.  The swap operations are
                                                                 enumerated in MHBW_PNB_DSWAP_E.

                                                                 Note that DMA to/from BPHY SMEM ignores this field. */
        uint64_t target_mem            : 1;  /**< [  3:  3] Defines the target memory for the operation as enumerated in MHBW_TMEM_SEL_E. */
        uint64_t dma_mode              : 3;  /**< [  2:  0] Selects the DMA mode, enumerated by MHBW_DMA_MODE_E. */
#else /* Word 0 - Little Endian */
        uint64_t dma_mode              : 3;  /**< [  2:  0] Selects the DMA mode, enumerated by MHBW_DMA_MODE_E. */
        uint64_t target_mem            : 1;  /**< [  3:  3] Defines the target memory for the operation as enumerated in MHBW_TMEM_SEL_E. */
        uint64_t dswap                 : 3;  /**< [  6:  4] The byte swap mode for DMA to/from LLC/DRAM.  The swap operations are
                                                                 enumerated in MHBW_PNB_DSWAP_E.

                                                                 Note that DMA to/from BPHY SMEM ignores this field. */
        uint64_t cmd_type              : 2;  /**< [  8:  7] Command type for LLC/DRAM access. The read and write operations are
                                                                 enumerated with MHBW_PNB_RD_CMD_E and MHBW_PNB_WR_CMD_E respectively.

                                                                 Note that DMA to/from BPHY SMEM ignores this field. */
        uint64_t reserved_9_15         : 7;
        uint64_t chunk_size            : 16; /**< [ 31: 16] For multi-threaded read DMA ports, this field specifies how many words
                                                                 are read from the thread before switching to the next thread.
                                                                 [CHUNK_SIZE] is specified as a number of 32-bit words, and must be
                                                                 of the same granularity as the port width. */
        uint64_t block_size            : 16; /**< [ 47: 32] Defines the DMA block size in 32-bit words.
                                                                 [BLOCK_SIZE] must be a multiple of 2 or 4 for 64-bit or 128-/256-bit
                                                                 ports, . */
        uint64_t thread_id             : 6;  /**< [ 53: 48] Thread ID for this command. Thread IDs can be in the range 0-63,
                                                                 regardless of the number of threads supported on a given port. */
        uint64_t reserved_54_55        : 2;
        uint64_t group_id              : 4;  /**< [ 59: 56] Group ID is used for multi-threaded DMA ports only. Groups must use
                                                                 sequential IDs starting with 0. If more than 16 groups are required,
                                                                 the GROUP_IDs can be repeated, e.g., 0, 1, 2,..., 15, 0, 1,... */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_dma_cfg_word_0_s_s cn; */
};

/**
 * Structure mhbw_jd_dma_cfg_word_1_s
 *
 * MHBW DMA Configuration Word 1 Structure
 * This structure specifies the format for the second word of each read/write
 * DMA command. All read and write DMA commands must use this structure.
 */
union cavm_mhbw_jd_dma_cfg_word_1_s
{
    uint64_t u;
    struct cavm_mhbw_jd_dma_cfg_word_1_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the byte address of the DMA starting location.
                                                                 The address must be aligned to the width of the DMA port. As an
                                                                 exception, 256 bit ports only require that START_ADDR is 128 bit
                                                                 aligned. */
#else /* Word 0 - Little Endian */
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the byte address of the DMA starting location.
                                                                 The address must be aligned to the width of the DMA port. As an
                                                                 exception, 256 bit ports only require that START_ADDR is 128 bit
                                                                 aligned. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_dma_cfg_word_1_s_s cn; */
};

/**
 * Structure mhbw_jd_dma_cfg_word_2_s
 *
 * MHBW DMA Configuration Word 2 Structure
 * This structure specifies the format for the third word of read/write
 * block DMA commands. This word should be present for all 2D and 3D DMA
 * modes, i.e., for all modes except when
 * MDBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MDBW_DMA_MODE_E::BLK_DMA.
 */
union cavm_mhbw_jd_dma_cfg_word_2_s
{
    uint64_t u;
    struct cavm_mhbw_jd_dma_cfg_word_2_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t stride                : 32; /**< [ 63: 32] Signed distance in bytes between the start of consecutive blocks of 2D
                                                                 DMA. Must be two's complement value in the range ABS([STRIDE]) \< 128
                                                                 MB.  The stride distance must be aligned to the DMA port width. */
        uint64_t block_param           : 32; /**< [ 31:  0] When MHBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MHBW_DMA_MODE_E::TWO_D_BLK_DMA_BLKMSK,
                                                                 [BLOCK_PARAM] is a block-skip mask. Each bit 31..0 corresponds to one
                                                                 of 32 blocks. Setting a bit in the mask will cause the DMA command to
                                                                 skip that block. Note that a value of 0xFFFFFFFF is illegal, a command
                                                                 must have at least one block that is NOT skipped.

                                                                 When MHBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MHBW_DMA_MODE_E::TWO_D_BLK_DMA_BLKCNT,
                                                                 [BLOCK_PARAM] is the number of blocks of DMA, and no blocks are
                                                                 skipped. Must be in the range [0x1, 0x400].

                                                                 When MHBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] =
                                                                 MHBW_DMA_MODE_E::THREE_D_BLK_DMA, [BLOCK_PARAM] is the number of
                                                                 blocks in each 3D block. No blocks are skipped. Must be in the range
                                                                 [0x1, 0x400]. */
#else /* Word 0 - Little Endian */
        uint64_t block_param           : 32; /**< [ 31:  0] When MHBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MHBW_DMA_MODE_E::TWO_D_BLK_DMA_BLKMSK,
                                                                 [BLOCK_PARAM] is a block-skip mask. Each bit 31..0 corresponds to one
                                                                 of 32 blocks. Setting a bit in the mask will cause the DMA command to
                                                                 skip that block. Note that a value of 0xFFFFFFFF is illegal, a command
                                                                 must have at least one block that is NOT skipped.

                                                                 When MHBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MHBW_DMA_MODE_E::TWO_D_BLK_DMA_BLKCNT,
                                                                 [BLOCK_PARAM] is the number of blocks of DMA, and no blocks are
                                                                 skipped. Must be in the range [0x1, 0x400].

                                                                 When MHBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] =
                                                                 MHBW_DMA_MODE_E::THREE_D_BLK_DMA, [BLOCK_PARAM] is the number of
                                                                 blocks in each 3D block. No blocks are skipped. Must be in the range
                                                                 [0x1, 0x400]. */
        uint64_t stride                : 32; /**< [ 63: 32] Signed distance in bytes between the start of consecutive blocks of 2D
                                                                 DMA. Must be two's complement value in the range ABS([STRIDE]) \< 128
                                                                 MB.  The stride distance must be aligned to the DMA port width. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_dma_cfg_word_2_s_s cn; */
};

/**
 * Structure mhbw_jd_dma_cfg_word_3_s
 *
 * MHBW DMA Configuration Word 3 Structure
 * This structure specifies the format for the fourth word of
 * DMA commands when MHBW_JD_DMA_CFG_WORD_0_S[DMA_MODE] = MHBW_DMA_MODE_E::THREE_D_BLK_DMA.
 */
union cavm_mhbw_jd_dma_cfg_word_3_s
{
    uint64_t u;
    struct cavm_mhbw_jd_dma_cfg_word_3_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t stride_3d             : 32; /**< [ 63: 32] The signed distance in 32-bit words between consecutive 3D blocks.
                                                                 The stride distance must be aligned to the DMA port width, and
                                                                 ABS([STRIDE_3D]) must be \< 128 MB. */
        uint64_t reserved_11_31        : 21;
        uint64_t num_3d_blocks         : 11; /**< [ 10:  0] The number of 3D blocks. I.e., the 2D block DMA pattern specified by
                                                                 MHBW_JD_DMA_CFG_WORD_2_S is repeated [NUM_3D_BLOCKS] times. Must be in
                                                                 the range [0x1, 0x400]. */
#else /* Word 0 - Little Endian */
        uint64_t num_3d_blocks         : 11; /**< [ 10:  0] The number of 3D blocks. I.e., the 2D block DMA pattern specified by
                                                                 MHBW_JD_DMA_CFG_WORD_2_S is repeated [NUM_3D_BLOCKS] times. Must be in
                                                                 the range [0x1, 0x400]. */
        uint64_t reserved_11_31        : 21;
        uint64_t stride_3d             : 32; /**< [ 63: 32] The signed distance in 32-bit words between consecutive 3D blocks.
                                                                 The stride distance must be aligned to the DMA port width, and
                                                                 ABS([STRIDE_3D]) must be \< 128 MB. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_dma_cfg_word_3_s_s cn; */
};

/**
 * Structure mhbw_jd_dma_ptr_s
 *
 * MHBW DMA Sub-descriptor Pointer Structure
 * This structure specifies a pointer to the location of a DMA port
 * subdescriptor section. The job descriptor must contain a pointer for each
 * read and write port in the MHAB that will run the job.
 */
union cavm_mhbw_jd_dma_ptr_s
{
    uint64_t u;
    struct cavm_mhbw_jd_dma_ptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t target_mem            : 1;  /**< [ 63: 63] Specifies the target memory for the address, as enumerate in
                                                                 MHBW_TMEM_SEL_E. */
        uint64_t reserved_53_62        : 10;
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the byte address of the start of the DMA port
                                                                 subdescriptor.  The address must be 64 bit aligned, i.e., bits[2:0]
                                                                 must be 0. */
#else /* Word 0 - Little Endian */
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the byte address of the start of the DMA port
                                                                 subdescriptor.  The address must be 64 bit aligned, i.e., bits[2:0]
                                                                 must be 0. */
        uint64_t reserved_53_62        : 10;
        uint64_t target_mem            : 1;  /**< [ 63: 63] Specifies the target memory for the address, as enumerate in
                                                                 MHBW_TMEM_SEL_E. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_dma_ptr_s_s cn; */
};

/**
 * Structure mhbw_jd_hdr_word_0_s
 *
 * MHBW Job Descriptor Header Word 0 Structure
 * This structure specifies the format of the first word of the job
 * descriptor for all MHAB jobs.
 */
union cavm_mhbw_jd_hdr_word_0_s
{
    uint64_t u;
    struct cavm_mhbw_jd_hdr_word_0_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t toth                  : 4;  /**< [ 60: 57] Job timeout threshold. The timeout timer starts counting when the job
                                                                 gets started on a HAB. The timer increments by one each SCLK cycle,
                                                                 and a timeout occurs when the timer reaches the threshold specified
                                                                 as:

                                                                 _ ((MHBW()_JD_CFG[TIMEOUT_MULT]\<\<4)+[TOTH])*2^([TOTH_TICK]+4)

                                                                 Setting [TOTH]=0 disables the timeout timer.

                                                                 For example, to get 10.24 us timeout value when BPHY runs at 1GHz,
                                                                 set [TOTH_TICK]=0x6, [TOTH]=0xA, and MHBW()_JD_CFG[TIMEOUT_MULT]=0x1. */
        uint64_t toth_tick             : 4;  /**< [ 56: 53] Timeout threshold tick count. See MHBW_JD_HDR_WORD_0_S[TOTH] for
                                                                 details. */
        uint64_t jce_cnt               : 6;  /**< [ 52: 47] Specifies the number of 64-bit words in the job completion even
                                                                 subdescriptor, starting from MHBW_JD_JCE_PTR_S[START_ADDR].
                                                                 Supports up to 64 x 64-bit words, i.e., 32 PSM commands. */
        uint64_t reserved_42_46        : 5;
        uint64_t dma_p0_wrcnt          : 10; /**< [ 41: 32] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 write port 0. Supports up to 1023 64-bit words. */
        uint64_t reserved_26_31        : 6;
        uint64_t dma_p0_rdcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 read port 0. Supports up to 1023 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t cfg_cnt               : 10; /**< [  9:  0] Specifies the number of 64-bit words in the job configuration
                                                                 subdescriptor, starting from MHBW_JD_CFG_PTR_S[START_ADDR].  Supports
                                                                 up to 1023 64-bit words. */
#else /* Word 0 - Little Endian */
        uint64_t cfg_cnt               : 10; /**< [  9:  0] Specifies the number of 64-bit words in the job configuration
                                                                 subdescriptor, starting from MHBW_JD_CFG_PTR_S[START_ADDR].  Supports
                                                                 up to 1023 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t dma_p0_rdcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 read port 0. Supports up to 1023 64-bit words. */
        uint64_t reserved_26_31        : 6;
        uint64_t dma_p0_wrcnt          : 10; /**< [ 41: 32] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 write port 0. Supports up to 1023 64-bit words. */
        uint64_t reserved_42_46        : 5;
        uint64_t jce_cnt               : 6;  /**< [ 52: 47] Specifies the number of 64-bit words in the job completion even
                                                                 subdescriptor, starting from MHBW_JD_JCE_PTR_S[START_ADDR].
                                                                 Supports up to 64 x 64-bit words, i.e., 32 PSM commands. */
        uint64_t toth_tick             : 4;  /**< [ 56: 53] Timeout threshold tick count. See MHBW_JD_HDR_WORD_0_S[TOTH] for
                                                                 details. */
        uint64_t toth                  : 4;  /**< [ 60: 57] Job timeout threshold. The timeout timer starts counting when the job
                                                                 gets started on a HAB. The timer increments by one each SCLK cycle,
                                                                 and a timeout occurs when the timer reaches the threshold specified
                                                                 as:

                                                                 _ ((MHBW()_JD_CFG[TIMEOUT_MULT]\<\<4)+[TOTH])*2^([TOTH_TICK]+4)

                                                                 Setting [TOTH]=0 disables the timeout timer.

                                                                 For example, to get 10.24 us timeout value when BPHY runs at 1GHz,
                                                                 set [TOTH_TICK]=0x6, [TOTH]=0xA, and MHBW()_JD_CFG[TIMEOUT_MULT]=0x1. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_hdr_word_0_s_s cn; */
};

/**
 * Structure mhbw_jd_hdr_word_1_s
 *
 * MHBW Header Word 1 Structure
 * This structure specifies the format of the second word of the job
 * descriptor header. This word is only required for MHABs with more than one
 * read DMA port, or more than one write DMA port.
 */
union cavm_mhbw_jd_hdr_word_1_s
{
    uint64_t u;
    struct cavm_mhbw_jd_hdr_word_1_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t dma_p2_wrcnt          : 10; /**< [ 57: 48] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 write port 2. Supports up to 1023 64-bit words. */
        uint64_t reserved_42_47        : 6;
        uint64_t dma_p2_rdcnt          : 10; /**< [ 41: 32] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 read port 2. Supports up to 1023 64-bit words. */
        uint64_t reserved_26_31        : 6;
        uint64_t dma_p1_wrcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 write port 1. Supports up to 1023 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t dma_p1_rdcnt          : 10; /**< [  9:  0] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 read port 1. Supports up to 1023 64-bit words. */
#else /* Word 0 - Little Endian */
        uint64_t dma_p1_rdcnt          : 10; /**< [  9:  0] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 read port 1. Supports up to 1023 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t dma_p1_wrcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 write port 1. Supports up to 1023 64-bit words. */
        uint64_t reserved_26_31        : 6;
        uint64_t dma_p2_rdcnt          : 10; /**< [ 41: 32] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 read port 2. Supports up to 1023 64-bit words. */
        uint64_t reserved_42_47        : 6;
        uint64_t dma_p2_wrcnt          : 10; /**< [ 57: 48] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 write port 2. Supports up to 1023 64-bit words. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_hdr_word_1_s_s cn; */
};

/**
 * Structure mhbw_jd_hdr_word_2_s
 *
 * MHBW Header Word 2 Structure
 * This structure specifies the format of the third word of the job
 * descriptor header. This word is only required for MHABs with more than
 * three read DMA port or three write DMA ports, i.e, only for TDEC jobs.
 */
union cavm_mhbw_jd_hdr_word_2_s
{
    uint64_t u;
    struct cavm_mhbw_jd_hdr_word_2_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t dma_p3_wrcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 write port 3. Supports up to 1023 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t dma_p3_rdcnt          : 10; /**< [  9:  0] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 read port 3. Supports up to 1023 64-bit words. */
#else /* Word 0 - Little Endian */
        uint64_t dma_p3_rdcnt          : 10; /**< [  9:  0] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 read port 3. Supports up to 1023 64-bit words. */
        uint64_t reserved_10_15        : 6;
        uint64_t dma_p3_wrcnt          : 10; /**< [ 25: 16] Specifies the number of 64-bit words in the DMA subdescriptor for
                                                                 write port 3. Supports up to 1023 64-bit words. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_hdr_word_2_s_s cn; */
};

/**
 * Structure mhbw_jd_jce_ptr_s
 *
 * MHBW Job Completion Event Pointer Structure
 * This structure specifies a pointer to the location of the job completion
 * event (JCE) subdescriptor section. This pointer is required for all jobs,
 * and must follow the pointers for all write DMA ports.
 */
union cavm_mhbw_jd_jce_ptr_s
{
    uint64_t u;
    struct cavm_mhbw_jd_jce_ptr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t target_mem            : 1;  /**< [ 63: 63] Specifies the target memory for the address, as enumerate in
                                                                 MHBW_TMEM_SEL_E. */
        uint64_t reserved_53_62        : 10;
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the byte address of the start of the JCE subdescriptor.
                                                                 The address must be 64 bit aligned, i.e., bits[2:0] must be 0. */
#else /* Word 0 - Little Endian */
        uint64_t start_addr            : 53; /**< [ 52:  0] Specifies the byte address of the start of the JCE subdescriptor.
                                                                 The address must be 64 bit aligned, i.e., bits[2:0] must be 0. */
        uint64_t reserved_53_62        : 10;
        uint64_t target_mem            : 1;  /**< [ 63: 63] Specifies the target memory for the address, as enumerate in
                                                                 MHBW_TMEM_SEL_E. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbw_jd_jce_ptr_s_s cn; */
};

/**
 * Register (RSL) mhbw#_ab#_port_hp
 *
 * MHBW AB Port High Priority Register
 * This register set, specifies the port priority per MHBW, per AB, per read and write port.
 */
union cavm_mhbwx_abx_port_hp
{
    uint64_t u;
    struct cavm_mhbwx_abx_port_hp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t wr_hp                 : 4;  /**< [  7:  4](R/W) Write port is high priority when set. */
        uint64_t rd_hp                 : 4;  /**< [  3:  0](R/W) Read port is high priority when set. */
#else /* Word 0 - Little Endian */
        uint64_t rd_hp                 : 4;  /**< [  3:  0](R/W) Read port is high priority when set. */
        uint64_t wr_hp                 : 4;  /**< [  7:  4](R/W) Write port is high priority when set. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_port_hp_s cn; */
};
typedef union cavm_mhbwx_abx_port_hp cavm_mhbwx_abx_port_hp_t;

static inline uint64_t CAVM_MHBWX_ABX_PORT_HP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_PORT_HP(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2)))
        return 0x87e043023000ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_PORT_HP", 2, a, b, 0, 0);
}

#define typedef_CAVM_MHBWX_ABX_PORT_HP(a,b) cavm_mhbwx_abx_port_hp_t
#define bustype_CAVM_MHBWX_ABX_PORT_HP(a,b) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_PORT_HP(a,b) "MHBWX_ABX_PORT_HP"
#define busnum_CAVM_MHBWX_ABX_PORT_HP(a,b) (a)
#define arguments_CAVM_MHBWX_ABX_PORT_HP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mhbw#_ab#_slt#_cp_fat_jtag
 *
 * MHBW Control Path Fatal Error Job Tag Register
 * These registers record the job tag for HAB fatal errors and MHBW control
 * path fatal errors.  Errors are reported for the specific HAB and slot that
 * received the error.
 */
union cavm_mhbwx_abx_sltx_cp_fat_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_cp_fat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t ab                    : 16; /**< [ 47: 32](RO/H) The job tag for the job that caused a HAB error. Note, in some
                                                                 cases this tag might be incorrect and a HAB-specific register should
                                                                 be used to determine the correct tag. */
        uint64_t jd_fetch              : 16; /**< [ 31: 16](RO/H) The job tag for the job that had an error when fetching the job
                                                                 descriptor header and subdescriptor pointers. Note this tag is only
                                                                 valid for HAB 0 and slot 0. */
        uint64_t job_sd_fetch          : 16; /**< [ 15:  0](RO/H) Job tag for the job that had an error when fetching the job
                                                                 subdescriptors. */
#else /* Word 0 - Little Endian */
        uint64_t job_sd_fetch          : 16; /**< [ 15:  0](RO/H) Job tag for the job that had an error when fetching the job
                                                                 subdescriptors. */
        uint64_t jd_fetch              : 16; /**< [ 31: 16](RO/H) The job tag for the job that had an error when fetching the job
                                                                 descriptor header and subdescriptor pointers. Note this tag is only
                                                                 valid for HAB 0 and slot 0. */
        uint64_t ab                    : 16; /**< [ 47: 32](RO/H) The job tag for the job that caused a HAB error. Note, in some
                                                                 cases this tag might be incorrect and a HAB-specific register should
                                                                 be used to determine the correct tag. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_cp_fat_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_cp_fat_jtag cavm_mhbwx_abx_sltx_cp_fat_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_CP_FAT_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_CP_FAT_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043022000ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_CP_FAT_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_CP_FAT_JTAG(a,b,c) cavm_mhbwx_abx_sltx_cp_fat_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_CP_FAT_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_CP_FAT_JTAG(a,b,c) "MHBWX_ABX_SLTX_CP_FAT_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_CP_FAT_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_CP_FAT_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_cp_nfat_jtag
 *
 * MHBW Control Path Non-Fatal Error Job Tag Register
 * These registers record the job tag for HAB nonfatal errors and MHBW control
 * path nonfatal errors.  Errors are reported for the specific HAB and slot that
 * received the error.
 */
union cavm_mhbwx_abx_sltx_cp_nfat_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_cp_nfat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t ab                    : 16; /**< [ 47: 32](RO/H) The job tag for the job that caused a HAB error. Note, in some
                                                                 cases this tag might be incorrect and a HAB-specific register should
                                                                 be used to determine the correct tag. */
        uint64_t jd_fetch              : 16; /**< [ 31: 16](RO/H) The job tag for the job that had an error when fetching the job
                                                                 descriptor header and subdescriptor pointers. Note this tag is only
                                                                 valid for HAB 0 and slot 0. */
        uint64_t job_sd_fetch          : 16; /**< [ 15:  0](RO/H) Job tag for the job that had an error when fetching the job
                                                                 subdescriptors. */
#else /* Word 0 - Little Endian */
        uint64_t job_sd_fetch          : 16; /**< [ 15:  0](RO/H) Job tag for the job that had an error when fetching the job
                                                                 subdescriptors. */
        uint64_t jd_fetch              : 16; /**< [ 31: 16](RO/H) The job tag for the job that had an error when fetching the job
                                                                 descriptor header and subdescriptor pointers. Note this tag is only
                                                                 valid for HAB 0 and slot 0. */
        uint64_t ab                    : 16; /**< [ 47: 32](RO/H) The job tag for the job that caused a HAB error. Note, in some
                                                                 cases this tag might be incorrect and a HAB-specific register should
                                                                 be used to determine the correct tag. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_cp_nfat_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_cp_nfat_jtag cavm_mhbwx_abx_sltx_cp_nfat_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_CP_NFAT_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_CP_NFAT_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043022700ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_CP_NFAT_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_CP_NFAT_JTAG(a,b,c) cavm_mhbwx_abx_sltx_cp_nfat_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_CP_NFAT_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_CP_NFAT_JTAG(a,b,c) "MHBWX_ABX_SLTX_CP_NFAT_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_CP_NFAT_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_CP_NFAT_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_debug0
 *
 * INTERNAL: MHBW AB Slot Debug Register
 *
 * Internal:
 * This register set, specifies debug information per MHBW, per AB, per job slot. This
 * register set contains bits, which specify the write-resend mask. This masks subsequent
 * interrupt transactions for this register. If set indicates an interrupt has been issued for
 * this vector. The bit is reset by hardware if software performs a W1C to any of the
 * corresponding interrupt bits in the interrupt register. It also contains the job tag of the
 * job that is currently being processed by an AB.
 */
union cavm_mhbwx_abx_sltx_debug0
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_debug0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ferr                  : 1;  /**< [ 63: 63](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for fatal errors. */
        uint64_t nferr                 : 1;  /**< [ 62: 62](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for nonfatal errors. */
        uint64_t derr                  : 1;  /**< [ 61: 61](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for DMA errors. */
        uint64_t adrerr                : 1;  /**< [ 60: 60](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask for address errors. */
        uint64_t reserved_16_59        : 44;
        uint64_t job_id                : 16; /**< [ 15:  0](RO/H) Internal:
                                                                 This set of bits, specifies the job tag, corresponding to the job that is active
                                                                 in the MHBW, per AB, per job slot. */
#else /* Word 0 - Little Endian */
        uint64_t job_id                : 16; /**< [ 15:  0](RO/H) Internal:
                                                                 This set of bits, specifies the job tag, corresponding to the job that is active
                                                                 in the MHBW, per AB, per job slot. */
        uint64_t reserved_16_59        : 44;
        uint64_t adrerr                : 1;  /**< [ 60: 60](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask for address errors. */
        uint64_t derr                  : 1;  /**< [ 61: 61](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for DMA errors. */
        uint64_t nferr                 : 1;  /**< [ 62: 62](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for nonfatal errors. */
        uint64_t ferr                  : 1;  /**< [ 63: 63](R/W/H) Internal:
                                                                 This bit specifies the write-resend mask, for fatal errors. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_debug0_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_debug0 cavm_mhbwx_abx_sltx_debug0_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_DEBUG0(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_DEBUG0(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043022900ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_DEBUG0", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_DEBUG0(a,b,c) cavm_mhbwx_abx_sltx_debug0_t
#define bustype_CAVM_MHBWX_ABX_SLTX_DEBUG0(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_DEBUG0(a,b,c) "MHBWX_ABX_SLTX_DEBUG0"
#define busnum_CAVM_MHBWX_ABX_SLTX_DEBUG0(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_DEBUG0(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_derr_ena_w1c
 *
 * MHBW DMA Error Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_mhbwx_abx_sltx_derr_ena_w1c
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_derr_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t wr_dma_uflow_port3    : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT3]. */
        uint64_t wr_dma_uflow_port2    : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT2]. */
        uint64_t wr_dma_uflow_port1    : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT1]. */
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t wr_dma_oflow_port3    : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT3]. */
        uint64_t wr_dma_oflow_port2    : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT2]. */
        uint64_t wr_dma_oflow_port1    : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT1]. */
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t rd_dma_uflow_port3    : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT3]. */
        uint64_t rd_dma_uflow_port2    : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT2]. */
        uint64_t rd_dma_uflow_port1    : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT1]. */
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t rd_dma_oflow_port3    : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT3]. */
        uint64_t rd_dma_oflow_port2    : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT2]. */
        uint64_t rd_dma_oflow_port1    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT1]. */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
        uint64_t rd_dma_oflow_port1    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT1]. */
        uint64_t rd_dma_oflow_port2    : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT2]. */
        uint64_t rd_dma_oflow_port3    : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT3]. */
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t rd_dma_uflow_port1    : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT1]. */
        uint64_t rd_dma_uflow_port2    : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT2]. */
        uint64_t rd_dma_uflow_port3    : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT3]. */
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t wr_dma_oflow_port1    : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT1]. */
        uint64_t wr_dma_oflow_port2    : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT2]. */
        uint64_t wr_dma_oflow_port3    : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT3]. */
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t wr_dma_uflow_port1    : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT1]. */
        uint64_t wr_dma_uflow_port2    : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT2]. */
        uint64_t wr_dma_uflow_port3    : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT3]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_derr_ena_w1c_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_derr_ena_w1c cavm_mhbwx_abx_sltx_derr_ena_w1c_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1C(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1C(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021200ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_DERR_ENA_W1C", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1C(a,b,c) cavm_mhbwx_abx_sltx_derr_ena_w1c_t
#define bustype_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1C(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1C(a,b,c) "MHBWX_ABX_SLTX_DERR_ENA_W1C"
#define busnum_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1C(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1C(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_derr_ena_w1s
 *
 * MHBW DMA Error Message Enable Set Registers
 * This register sets interrupt enable bits.
 */
union cavm_mhbwx_abx_sltx_derr_ena_w1s
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_derr_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t wr_dma_uflow_port3    : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT3]. */
        uint64_t wr_dma_uflow_port2    : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT2]. */
        uint64_t wr_dma_uflow_port1    : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT1]. */
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t wr_dma_oflow_port3    : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT3]. */
        uint64_t wr_dma_oflow_port2    : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT2]. */
        uint64_t wr_dma_oflow_port1    : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT1]. */
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t rd_dma_uflow_port3    : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT3]. */
        uint64_t rd_dma_uflow_port2    : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT2]. */
        uint64_t rd_dma_uflow_port1    : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT1]. */
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t rd_dma_oflow_port3    : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT3]. */
        uint64_t rd_dma_oflow_port2    : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT2]. */
        uint64_t rd_dma_oflow_port1    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT1]. */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
        uint64_t rd_dma_oflow_port1    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT1]. */
        uint64_t rd_dma_oflow_port2    : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT2]. */
        uint64_t rd_dma_oflow_port3    : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT3]. */
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t rd_dma_uflow_port1    : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT1]. */
        uint64_t rd_dma_uflow_port2    : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT2]. */
        uint64_t rd_dma_uflow_port3    : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT3]. */
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t wr_dma_oflow_port1    : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT1]. */
        uint64_t wr_dma_oflow_port2    : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT2]. */
        uint64_t wr_dma_oflow_port3    : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT3]. */
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t wr_dma_uflow_port1    : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT1]. */
        uint64_t wr_dma_uflow_port2    : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT2]. */
        uint64_t wr_dma_uflow_port3    : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT3]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_derr_ena_w1s_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_derr_ena_w1s cavm_mhbwx_abx_sltx_derr_ena_w1s_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1S(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1S(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021100ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_DERR_ENA_W1S", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1S(a,b,c) cavm_mhbwx_abx_sltx_derr_ena_w1s_t
#define bustype_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1S(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1S(a,b,c) "MHBWX_ABX_SLTX_DERR_ENA_W1S"
#define busnum_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1S(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_DERR_ENA_W1S(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_derr_int
 *
 * MHBW DMA Error Message Interrupt Register
 * These registers record DMA overflow/underflow errors. There is one
 * register for each job slot (SLT(0..2)) in each HAB (AB(0..2)) in each MHAB
 * (MHBW(0..27)). Note that registers only exist for the number of HABs and
 * slots in each specific MHAB.
 *
 * When an error occurs, the job tag is recorded in one of the following
 * registers:
 *
 * _ Read overflow: MHBW()_AB()_SLT()_RDERR_OFLOW_JTAG
 *
 * _ Read underflow: MHBW()_AB()_SLT()_RDERR_UFLOW_JTAG
 *
 * _ Write overflow: MHBW()_AB()_SLT()_WDERR_OFLOW_JTAG
 *
 * _ Write underflow: MHBW()_AB()_SLT()_WDERR_UFLOW_JTAG
 *
 * In some cases, read overflow/underflow errors are recorded for the wrong
 * slot, and the wrong job tag is recorded.  In these cases, the correct job
 * tag should be available in the HAB_ERROR_SOURCE0 register for the given
 * HAB.
 *
 * When an error occurs, the MHAB sends a DMA error message to PSM which then
 * triggers an interrupt, if enabled. In addition, the MHBW sends the command
 * specified by \<MHBW()_DMA_ERROR_JCE_W1,MHBW()_DMA_ERROR_JCE_W0\>
 * to the PSM.
 */
union cavm_mhbwx_abx_sltx_derr_int
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_derr_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t wr_dma_uflow_port3    : 1;  /**< [ 15: 15](R/W1C/H) Write underflow error on write port 3. */
        uint64_t wr_dma_uflow_port2    : 1;  /**< [ 14: 14](R/W1C/H) Write underflow error on write port 2. */
        uint64_t wr_dma_uflow_port1    : 1;  /**< [ 13: 13](R/W1C/H) Write underflow error on write port 1. */
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) Write underflow error on write port 0. */
        uint64_t wr_dma_oflow_port3    : 1;  /**< [ 11: 11](R/W1C/H) Write overflow error on write port 3. */
        uint64_t wr_dma_oflow_port2    : 1;  /**< [ 10: 10](R/W1C/H) Write overflow error on write port 2. */
        uint64_t wr_dma_oflow_port1    : 1;  /**< [  9:  9](R/W1C/H) Write overflow error on write port 1. */
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) Write overflow error on write port 0. */
        uint64_t rd_dma_uflow_port3    : 1;  /**< [  7:  7](R/W1C/H) Read underflow on read port 3. */
        uint64_t rd_dma_uflow_port2    : 1;  /**< [  6:  6](R/W1C/H) Read underflow on read port 2. */
        uint64_t rd_dma_uflow_port1    : 1;  /**< [  5:  5](R/W1C/H) Read underflow on read port 1. */
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) Read underflow on read port 0. */
        uint64_t rd_dma_oflow_port3    : 1;  /**< [  3:  3](R/W1C/H) Read overflow on read port 3. */
        uint64_t rd_dma_oflow_port2    : 1;  /**< [  2:  2](R/W1C/H) Read overflow on read port 2. */
        uint64_t rd_dma_oflow_port1    : 1;  /**< [  1:  1](R/W1C/H) Read overflow on read port 1. */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) Read overflow on read port 0. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1C/H) Read overflow on read port 0. */
        uint64_t rd_dma_oflow_port1    : 1;  /**< [  1:  1](R/W1C/H) Read overflow on read port 1. */
        uint64_t rd_dma_oflow_port2    : 1;  /**< [  2:  2](R/W1C/H) Read overflow on read port 2. */
        uint64_t rd_dma_oflow_port3    : 1;  /**< [  3:  3](R/W1C/H) Read overflow on read port 3. */
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1C/H) Read underflow on read port 0. */
        uint64_t rd_dma_uflow_port1    : 1;  /**< [  5:  5](R/W1C/H) Read underflow on read port 1. */
        uint64_t rd_dma_uflow_port2    : 1;  /**< [  6:  6](R/W1C/H) Read underflow on read port 2. */
        uint64_t rd_dma_uflow_port3    : 1;  /**< [  7:  7](R/W1C/H) Read underflow on read port 3. */
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1C/H) Write overflow error on write port 0. */
        uint64_t wr_dma_oflow_port1    : 1;  /**< [  9:  9](R/W1C/H) Write overflow error on write port 1. */
        uint64_t wr_dma_oflow_port2    : 1;  /**< [ 10: 10](R/W1C/H) Write overflow error on write port 2. */
        uint64_t wr_dma_oflow_port3    : 1;  /**< [ 11: 11](R/W1C/H) Write overflow error on write port 3. */
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1C/H) Write underflow error on write port 0. */
        uint64_t wr_dma_uflow_port1    : 1;  /**< [ 13: 13](R/W1C/H) Write underflow error on write port 1. */
        uint64_t wr_dma_uflow_port2    : 1;  /**< [ 14: 14](R/W1C/H) Write underflow error on write port 2. */
        uint64_t wr_dma_uflow_port3    : 1;  /**< [ 15: 15](R/W1C/H) Write underflow error on write port 3. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_derr_int_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_derr_int cavm_mhbwx_abx_sltx_derr_int_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_DERR_INT(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_DERR_INT(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043020e00ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_DERR_INT", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_DERR_INT(a,b,c) cavm_mhbwx_abx_sltx_derr_int_t
#define bustype_CAVM_MHBWX_ABX_SLTX_DERR_INT(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_DERR_INT(a,b,c) "MHBWX_ABX_SLTX_DERR_INT"
#define busnum_CAVM_MHBWX_ABX_SLTX_DERR_INT(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_DERR_INT(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_derr_int_w1s
 *
 * MHBW DMA Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_mhbwx_abx_sltx_derr_int_w1s
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_derr_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t wr_dma_uflow_port3    : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT3]. */
        uint64_t wr_dma_uflow_port2    : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT2]. */
        uint64_t wr_dma_uflow_port1    : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT1]. */
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t wr_dma_oflow_port3    : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT3]. */
        uint64_t wr_dma_oflow_port2    : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT2]. */
        uint64_t wr_dma_oflow_port1    : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT1]. */
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t rd_dma_uflow_port3    : 1;  /**< [  7:  7](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT3]. */
        uint64_t rd_dma_uflow_port2    : 1;  /**< [  6:  6](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT2]. */
        uint64_t rd_dma_uflow_port1    : 1;  /**< [  5:  5](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT1]. */
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t rd_dma_oflow_port3    : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT3]. */
        uint64_t rd_dma_oflow_port2    : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT2]. */
        uint64_t rd_dma_oflow_port1    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT1]. */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_oflow_port0    : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT0]. */
        uint64_t rd_dma_oflow_port1    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT1]. */
        uint64_t rd_dma_oflow_port2    : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT2]. */
        uint64_t rd_dma_oflow_port3    : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_OFLOW_PORT3]. */
        uint64_t rd_dma_uflow_port0    : 1;  /**< [  4:  4](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT0]. */
        uint64_t rd_dma_uflow_port1    : 1;  /**< [  5:  5](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT1]. */
        uint64_t rd_dma_uflow_port2    : 1;  /**< [  6:  6](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT2]. */
        uint64_t rd_dma_uflow_port3    : 1;  /**< [  7:  7](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[RD_DMA_UFLOW_PORT3]. */
        uint64_t wr_dma_oflow_port0    : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT0]. */
        uint64_t wr_dma_oflow_port1    : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT1]. */
        uint64_t wr_dma_oflow_port2    : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT2]. */
        uint64_t wr_dma_oflow_port3    : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_OFLOW_PORT3]. */
        uint64_t wr_dma_uflow_port0    : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT0]. */
        uint64_t wr_dma_uflow_port1    : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT1]. */
        uint64_t wr_dma_uflow_port2    : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT2]. */
        uint64_t wr_dma_uflow_port3    : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_DERR_INT[WR_DMA_UFLOW_PORT3]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_derr_int_w1s_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_derr_int_w1s cavm_mhbwx_abx_sltx_derr_int_w1s_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_DERR_INT_W1S(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_DERR_INT_W1S(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021300ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_DERR_INT_W1S", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_DERR_INT_W1S(a,b,c) cavm_mhbwx_abx_sltx_derr_int_w1s_t
#define bustype_CAVM_MHBWX_ABX_SLTX_DERR_INT_W1S(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_DERR_INT_W1S(a,b,c) "MHBWX_ABX_SLTX_DERR_INT_W1S"
#define busnum_CAVM_MHBWX_ABX_SLTX_DERR_INT_W1S(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_DERR_INT_W1S(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_fat_err_ena_w1c
 *
 * MHBW Fatal Error Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_mhbwx_abx_sltx_fat_err_ena_w1c
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_fat_err_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_12_15        : 4;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12_15        : 4;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mhbwx_abx_sltx_fat_err_ena_w1c_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t reserved_12           : 1;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12           : 1;
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mhbwx_abx_sltx_fat_err_ena_w1c cavm_mhbwx_abx_sltx_fat_err_ena_w1c_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1C(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1C(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021c00ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_FAT_ERR_ENA_W1C", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1C(a,b,c) cavm_mhbwx_abx_sltx_fat_err_ena_w1c_t
#define bustype_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1C(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1C(a,b,c) "MHBWX_ABX_SLTX_FAT_ERR_ENA_W1C"
#define busnum_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1C(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1C(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_fat_err_ena_w1s
 *
 * MHBW Fatal Error Message Enable Set Registers
 * This register sets interrupt enable bits.
 */
union cavm_mhbwx_abx_sltx_fat_err_ena_w1s
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_fat_err_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_12_15        : 4;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12_15        : 4;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mhbwx_abx_sltx_fat_err_ena_w1s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t reserved_12           : 1;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12           : 1;
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mhbwx_abx_sltx_fat_err_ena_w1s cavm_mhbwx_abx_sltx_fat_err_ena_w1s_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1S(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1S(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021b00ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_FAT_ERR_ENA_W1S", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1S(a,b,c) cavm_mhbwx_abx_sltx_fat_err_ena_w1s_t
#define bustype_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1S(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1S(a,b,c) "MHBWX_ABX_SLTX_FAT_ERR_ENA_W1S"
#define busnum_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1S(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_FAT_ERR_ENA_W1S(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_fat_err_int
 *
 * MHBW Fatal Error Message Interrupt Register
 * These registers record fatal errors. There is one
 * register for each job slot (SLT(0..2)) in each HAB (AB(0..2)) in each MHAB
 * (MHBW(0..27)). Note that registers only exist for the number of HABs and
 * slots in each specific MHAB.
 *
 * Fatal errors include:
 * * ECC double-bit errors on SMEM accesses.
 * * errors when accessing memory.
 * * ECC double-bit errors in internal HAB memories.
 * * HAB-specific fatal errors.
 *
 * When an error occurs, the job tag is recorded in one of the following
 * registers:
 *
 * _ Error on read DMA: MHBW()_AB()_SLT()_RD_FAT_JTAG
 *
 * _ Error on write DMA: MHBW()_AB()_SLT()_WR_FAT_JTAG
 *
 * _ Other fatal errors: MHBW()_AB()_SLT()_CP_FAT_JTAG
 *
 * When an error occurs, the MHAB sends a fatal error message to PSM which then
 * triggers an interrupt, if enabled. In addition, the MHBW sends the command
 * specified by \<MHBW()_FATAL_ERROR_JCE_W1,MHBW()_FATAL_ERROR_JCE_W0\>
 * to the PSM.
 */
union cavm_mhbwx_abx_sltx_fat_err_int
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_fat_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Fatal error reported by the HAB. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Job descriptor header or subdescriptor pointer fetch received a
                                                                 response with a fatal error.  Note that these errors are always
                                                                 reported for HAB 0, slot 0. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Job subdescriptor fetch received a response with a fatal error. */
        uint64_t reserved_12_15        : 4;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Fatal error on write DMA response for write port 3. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Fatal error on write DMA response for write port 2. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Fatal error on write DMA response for write port 1. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Fatal error on write DMA response for write port 0. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Fatal error on read DMA response for read port 3. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Fatal error on read DMA response for read port 2. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Fatal error on read DMA response for read port 1. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Fatal error on read DMA response for read port 0. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Fatal error on read DMA response for read port 0. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Fatal error on read DMA response for read port 1. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Fatal error on read DMA response for read port 2. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Fatal error on read DMA response for read port 3. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Fatal error on write DMA response for write port 0. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Fatal error on write DMA response for write port 1. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Fatal error on write DMA response for write port 2. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Fatal error on write DMA response for write port 3. */
        uint64_t reserved_12_15        : 4;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Job subdescriptor fetch received a response with a fatal error. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Job descriptor header or subdescriptor pointer fetch received a
                                                                 response with a fatal error.  Note that these errors are always
                                                                 reported for HAB 0, slot 0. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Fatal error reported by the HAB. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mhbwx_abx_sltx_fat_err_int_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Fatal error reported by the HAB. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Job descriptor header or subdescriptor pointer fetch received a
                                                                 response with a fatal error.  Note that these errors are always
                                                                 reported for HAB 0, slot 0. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Job subdescriptor fetch received a response with a fatal error. */
        uint64_t reserved_13_15        : 3;
        uint64_t reserved_12           : 1;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Fatal error on write DMA response for write port 3. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Fatal error on write DMA response for write port 2. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Fatal error on write DMA response for write port 1. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Fatal error on write DMA response for write port 0. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Fatal error on read DMA response for read port 3. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Fatal error on read DMA response for read port 2. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Fatal error on read DMA response for read port 1. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Fatal error on read DMA response for read port 0. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Fatal error on read DMA response for read port 0. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Fatal error on read DMA response for read port 1. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Fatal error on read DMA response for read port 2. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Fatal error on read DMA response for read port 3. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Fatal error on write DMA response for write port 0. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Fatal error on write DMA response for write port 1. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Fatal error on write DMA response for write port 2. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Fatal error on write DMA response for write port 3. */
        uint64_t reserved_12           : 1;
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Job subdescriptor fetch received a response with a fatal error. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Job descriptor header or subdescriptor pointer fetch received a
                                                                 response with a fatal error.  Note that these errors are always
                                                                 reported for HAB 0, slot 0. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Fatal error reported by the HAB. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mhbwx_abx_sltx_fat_err_int cavm_mhbwx_abx_sltx_fat_err_int_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021a00ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_FAT_ERR_INT", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT(a,b,c) cavm_mhbwx_abx_sltx_fat_err_int_t
#define bustype_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT(a,b,c) "MHBWX_ABX_SLTX_FAT_ERR_INT"
#define busnum_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_fat_err_int_w1s
 *
 * MHBW Fatal Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_mhbwx_abx_sltx_fat_err_int_w1s
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_fat_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_12_15        : 4;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12_15        : 4;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mhbwx_abx_sltx_fat_err_int_w1s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t reserved_12           : 1;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12           : 1;
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_FAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mhbwx_abx_sltx_fat_err_int_w1s cavm_mhbwx_abx_sltx_fat_err_int_w1s_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT_W1S(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT_W1S(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021d00ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_FAT_ERR_INT_W1S", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT_W1S(a,b,c) cavm_mhbwx_abx_sltx_fat_err_int_w1s_t
#define bustype_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT_W1S(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT_W1S(a,b,c) "MHBWX_ABX_SLTX_FAT_ERR_INT_W1S"
#define busnum_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT_W1S(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_FAT_ERR_INT_W1S(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_nfat_err_ena_w1c
 *
 * MHBW Non-Fatal Error Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_mhbwx_abx_sltx_nfat_err_ena_w1c
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_nfat_err_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_12_15        : 4;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12_15        : 4;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mhbwx_abx_sltx_nfat_err_ena_w1c_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t reserved_12           : 1;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12           : 1;
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mhbwx_abx_sltx_nfat_err_ena_w1c cavm_mhbwx_abx_sltx_nfat_err_ena_w1c_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1C(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1C(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043022300ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1C", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1C(a,b,c) cavm_mhbwx_abx_sltx_nfat_err_ena_w1c_t
#define bustype_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1C(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1C(a,b,c) "MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1C"
#define busnum_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1C(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1C(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_nfat_err_ena_w1s
 *
 * MHBW Non-Fatal Error Message Enable Set Registers
 * This register sets interrupt enable bits.
 */
union cavm_mhbwx_abx_sltx_nfat_err_ena_w1s
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_nfat_err_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_12_15        : 4;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12_15        : 4;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mhbwx_abx_sltx_nfat_err_ena_w1s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t reserved_12           : 1;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12           : 1;
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mhbwx_abx_sltx_nfat_err_ena_w1s cavm_mhbwx_abx_sltx_nfat_err_ena_w1s_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1S(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1S(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043022200ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1S", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1S(a,b,c) cavm_mhbwx_abx_sltx_nfat_err_ena_w1s_t
#define bustype_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1S(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1S(a,b,c) "MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1S"
#define busnum_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1S(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_ENA_W1S(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_nfat_err_int
 *
 * MHBW Non-Fatal Error Message Interrupt Register
 * These registers record nonfatal errors. There is one
 * register for each job slot (SLT(0..2)) in each HAB (AB(0..2)) in each MHAB
 * (MHBW(0..27)). Note that registers only exist for the number of HABs and
 * slots in each specific MHAB.
 *
 * Fatal errors include:
 * * ECC single-bit errors on SMEM accesses.
 * * ECC single-bit errors in internal HAB memories.
 * * HAB-specific fatal errors.
 *
 * When an error occurs, the job tag is recorded in one of the following
 * registers:
 *
 * _ Error on read DMA: MHBW()_AB()_SLT()_RD_NFAT_JTAG
 *
 * _ Error on write DMA: MHBW()_AB()_SLT()_WR_NFAT_JTAG
 *
 * _ Other nonfatal errors: MHBW()_AB()_SLT()_CP_NFAT_JTAG
 *
 * When an error occurs, the MHAB sends a fatal error message to PSM which then
 * triggers an interrupt, if enabled. In addition, the MHBW sends the command
 * specified by \<MHBW()_NON_FATAL_ERROR_JCE_W1,MHBW()_NON_FATAL_ERROR_JCE_W0\>
 * to the PSM.
 */
union cavm_mhbwx_abx_sltx_nfat_err_int
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_nfat_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Non-fatal error reported by the HAB. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Job descriptor header or subdescriptor pointer fetch received a
                                                                 response with a nonfatal error.  Note that these errors are always
                                                                 reported for HAB 0, slot 0. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Job subdescriptor fetch received a response with a nonfatal error. */
        uint64_t reserved_12_15        : 4;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Non-fatal error on write DMA response for write port 3. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Non-fatal error on write DMA response for write port 2. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Non-fatal error on write DMA response for write port 1. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Non-fatal error on write DMA response for write port 0. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Non-fatal error on read DMA response for read port 3. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Non-fatal error on read DMA response for read port 2. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Non-fatal error on read DMA response for read port 1. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Non-fatal error on read DMA response for read port 0. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Non-fatal error on read DMA response for read port 0. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Non-fatal error on read DMA response for read port 1. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Non-fatal error on read DMA response for read port 2. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Non-fatal error on read DMA response for read port 3. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Non-fatal error on write DMA response for write port 0. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Non-fatal error on write DMA response for write port 1. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Non-fatal error on write DMA response for write port 2. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Non-fatal error on write DMA response for write port 3. */
        uint64_t reserved_12_15        : 4;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Job subdescriptor fetch received a response with a nonfatal error. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Job descriptor header or subdescriptor pointer fetch received a
                                                                 response with a nonfatal error.  Note that these errors are always
                                                                 reported for HAB 0, slot 0. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Non-fatal error reported by the HAB. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mhbwx_abx_sltx_nfat_err_int_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Non-fatal error reported by the HAB. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Job descriptor header or subdescriptor pointer fetch received a
                                                                 response with a nonfatal error.  Note that these errors are always
                                                                 reported for HAB 0, slot 0. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Job subdescriptor fetch received a response with a nonfatal error. */
        uint64_t reserved_13_15        : 3;
        uint64_t reserved_12           : 1;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Non-fatal error on write DMA response for write port 3. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Non-fatal error on write DMA response for write port 2. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Non-fatal error on write DMA response for write port 1. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Non-fatal error on write DMA response for write port 0. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Non-fatal error on read DMA response for read port 3. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Non-fatal error on read DMA response for read port 2. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Non-fatal error on read DMA response for read port 1. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Non-fatal error on read DMA response for read port 0. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1C/H) Non-fatal error on read DMA response for read port 0. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1C/H) Non-fatal error on read DMA response for read port 1. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1C/H) Non-fatal error on read DMA response for read port 2. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1C/H) Non-fatal error on read DMA response for read port 3. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1C/H) Non-fatal error on write DMA response for write port 0. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1C/H) Non-fatal error on write DMA response for write port 1. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1C/H) Non-fatal error on write DMA response for write port 2. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1C/H) Non-fatal error on write DMA response for write port 3. */
        uint64_t reserved_12           : 1;
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1C/H) Job subdescriptor fetch received a response with a nonfatal error. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1C/H) Job descriptor header or subdescriptor pointer fetch received a
                                                                 response with a nonfatal error.  Note that these errors are always
                                                                 reported for HAB 0, slot 0. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1C/H) Non-fatal error reported by the HAB. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mhbwx_abx_sltx_nfat_err_int cavm_mhbwx_abx_sltx_nfat_err_int_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043022100ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_NFAT_ERR_INT", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT(a,b,c) cavm_mhbwx_abx_sltx_nfat_err_int_t
#define bustype_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT(a,b,c) "MHBWX_ABX_SLTX_NFAT_ERR_INT"
#define busnum_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_nfat_err_int_w1s
 *
 * MHBW Non-Fatal Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_mhbwx_abx_sltx_nfat_err_int_w1s
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_nfat_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_12_15        : 4;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12_15        : 4;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    struct cavm_mhbwx_abx_sltx_nfat_err_int_w1s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t reserved_13_15        : 3;
        uint64_t reserved_12           : 1;
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
#else /* Word 0 - Little Endian */
        uint64_t rd_dma_port0          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT0]. */
        uint64_t rd_dma_port1          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT1]. */
        uint64_t rd_dma_port2          : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT2]. */
        uint64_t rd_dma_port3          : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[RD_DMA_PORT3]. */
        uint64_t reserved_4_7          : 4;
        uint64_t wr_dma_port0          : 1;  /**< [  8:  8](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT0]. */
        uint64_t wr_dma_port1          : 1;  /**< [  9:  9](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT1]. */
        uint64_t wr_dma_port2          : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT2]. */
        uint64_t wr_dma_port3          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[WR_DMA_PORT3]. */
        uint64_t reserved_12           : 1;
        uint64_t reserved_13_15        : 3;
        uint64_t job_sd_fetch          : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JOB_SD_FETCH]. */
        uint64_t jd_fetch              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[JD_FETCH]. */
        uint64_t ab                    : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets MHBW(0..27)_AB(0..2)_SLT(0..2)_NFAT_ERR_INT[AB]. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_mhbwx_abx_sltx_nfat_err_int_w1s cavm_mhbwx_abx_sltx_nfat_err_int_w1s_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT_W1S(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT_W1S(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043022400ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_NFAT_ERR_INT_W1S", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT_W1S(a,b,c) cavm_mhbwx_abx_sltx_nfat_err_int_w1s_t
#define bustype_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT_W1S(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT_W1S(a,b,c) "MHBWX_ABX_SLTX_NFAT_ERR_INT_W1S"
#define busnum_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT_W1S(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_NFAT_ERR_INT_W1S(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_rd_fat_jtag
 *
 * MHBW RD DMA Fatal Error Job Tag Register
 * These registers record the job tag when a read DMA receives a response
 * indicating a fatal error. Errors are reported for the specific HAB and slot
 * that received the error.
 */
union cavm_mhbwx_abx_sltx_rd_fat_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_rd_fat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_rd_fat_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_rd_fat_jtag cavm_mhbwx_abx_sltx_rd_fat_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_RD_FAT_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_RD_FAT_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021e00ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_RD_FAT_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_RD_FAT_JTAG(a,b,c) cavm_mhbwx_abx_sltx_rd_fat_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_RD_FAT_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_RD_FAT_JTAG(a,b,c) "MHBWX_ABX_SLTX_RD_FAT_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_RD_FAT_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_RD_FAT_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_rd_nfat_jtag
 *
 * MHBW RD DMA Non-Fatal Error Job Tag Register
 * These registers record the job tag when a read DMA receives a response
 * indicating a nonfatal error. Errors are reported for the specific HAB and slot
 * that received the error.
 */
union cavm_mhbwx_abx_sltx_rd_nfat_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_rd_nfat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_rd_nfat_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_rd_nfat_jtag cavm_mhbwx_abx_sltx_rd_nfat_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_RD_NFAT_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_RD_NFAT_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043022500ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_RD_NFAT_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_RD_NFAT_JTAG(a,b,c) cavm_mhbwx_abx_sltx_rd_nfat_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_RD_NFAT_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_RD_NFAT_JTAG(a,b,c) "MHBWX_ABX_SLTX_RD_NFAT_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_RD_NFAT_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_RD_NFAT_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_rderr_oflow_jtag
 *
 * MHBW Read DMA Error Overflow Job Tag Registers
 * These registers record the job tag when a read DMA overflow occurs for a
 * given slot on a given HAB. In some cases, the wrong job tag will be
 * recorded for the wrong slot. In these cases, the HAB_ERROR_SOURCE0
 * register for the given HAB should report the correct job tag.
 *
 * Internal:
 * If the AB signals an underflow or overflow after returning the last beat credit on
 * the AB-MHBW interface for a job. The job tag will potentially be incorrect; since there is no
 * previous job context stacking for error handling.
 */
union cavm_mhbwx_abx_sltx_rderr_oflow_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_rderr_oflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read overflow occurred on port 3. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read overflow occurred on port 2. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read overflow occurred on port 1. */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read overflow occurred on port 0. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read overflow occurred on port 0. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read overflow occurred on port 1. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read overflow occurred on port 2. */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read overflow occurred on port 3. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_rderr_oflow_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_rderr_oflow_jtag cavm_mhbwx_abx_sltx_rderr_oflow_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_RDERR_OFLOW_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_RDERR_OFLOW_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043020f00ll + 0x80000ll * ((a) & 0x1f) + 0x20ll * ((b) & 0x3) + 8ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_RDERR_OFLOW_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_RDERR_OFLOW_JTAG(a,b,c) cavm_mhbwx_abx_sltx_rderr_oflow_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_RDERR_OFLOW_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_RDERR_OFLOW_JTAG(a,b,c) "MHBWX_ABX_SLTX_RDERR_OFLOW_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_RDERR_OFLOW_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_RDERR_OFLOW_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_rderr_uflow_jtag
 *
 * MHBW Read DMA Error Underflow Job Tag Registers
 * These registers record the job tag when a read DMA underflow occurs for a
 * given slot on a given HAB. In some cases, the wrong job tag will be
 * recorded for the wrong slot. In these cases, the HAB_ERROR_SOURCE0
 * register for the given HAB should report the correct job tag.
 *
 * Internal:
 * If the AB signals an underflow or overflow after returning the last beat credit on
 * the AB-MHBW interface for a job. The job tag will potentially be incorrect; since there is no
 * previous job context stacking for error handling.
 */
union cavm_mhbwx_abx_sltx_rderr_uflow_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_rderr_uflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_rderr_uflow_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_rderr_uflow_jtag cavm_mhbwx_abx_sltx_rderr_uflow_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_RDERR_UFLOW_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_RDERR_UFLOW_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043020f80ll + 0x80000ll * ((a) & 0x1f) + 0x20ll * ((b) & 0x3) + 8ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_RDERR_UFLOW_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_RDERR_UFLOW_JTAG(a,b,c) cavm_mhbwx_abx_sltx_rderr_uflow_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_RDERR_UFLOW_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_RDERR_UFLOW_JTAG(a,b,c) "MHBWX_ABX_SLTX_RDERR_UFLOW_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_RDERR_UFLOW_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_RDERR_UFLOW_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_wderr_oflow_jtag
 *
 * MHBW WR DMA Error Overflow Job Tag Register
 * These registers record the job tag when a write DMA overflow occurs for a
 * given slot on a given HAB. Write errors are always recorded correctly.
 */
union cavm_mhbwx_abx_sltx_wderr_oflow_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_wderr_oflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read overflow occurred on port 3. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read overflow occurred on port 2. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read overflow occurred on port 1. */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read overflow occurred on port 0. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read overflow occurred on port 0. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read overflow occurred on port 1. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read overflow occurred on port 2. */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read overflow occurred on port 3. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_wderr_oflow_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_wderr_oflow_jtag cavm_mhbwx_abx_sltx_wderr_oflow_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_WDERR_OFLOW_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_WDERR_OFLOW_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021000ll + 0x80000ll * ((a) & 0x1f) + 0x20ll * ((b) & 0x3) + 8ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_WDERR_OFLOW_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_WDERR_OFLOW_JTAG(a,b,c) cavm_mhbwx_abx_sltx_wderr_oflow_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_WDERR_OFLOW_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_WDERR_OFLOW_JTAG(a,b,c) "MHBWX_ABX_SLTX_WDERR_OFLOW_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_WDERR_OFLOW_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_WDERR_OFLOW_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_wderr_uflow_jtag
 *
 * MHBW WR DMA Error Underflow Job Tag Register
 * These registers record the job tag when a write DMA overflow occurs for a
 * given slot on a given HAB. Write errors are always recorded correctly.
 */
union cavm_mhbwx_abx_sltx_wderr_uflow_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_wderr_uflow_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_wderr_uflow_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_wderr_uflow_jtag cavm_mhbwx_abx_sltx_wderr_uflow_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_WDERR_UFLOW_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_WDERR_UFLOW_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021080ll + 0x80000ll * ((a) & 0x1f) + 0x20ll * ((b) & 0x3) + 8ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_WDERR_UFLOW_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_WDERR_UFLOW_JTAG(a,b,c) cavm_mhbwx_abx_sltx_wderr_uflow_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_WDERR_UFLOW_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_WDERR_UFLOW_JTAG(a,b,c) "MHBWX_ABX_SLTX_WDERR_UFLOW_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_WDERR_UFLOW_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_WDERR_UFLOW_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_wr_fat_jtag
 *
 * MHBW WR DMA Fatal Error Job Tag Register
 * These registers record the job tag when a write DMA receives a response
 * indicating a fatal error. Errors are reported for the specific HAB and slot
 * that received the error.
 */
union cavm_mhbwx_abx_sltx_wr_fat_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_wr_fat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_wr_fat_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_wr_fat_jtag cavm_mhbwx_abx_sltx_wr_fat_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_WR_FAT_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_WR_FAT_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043021f00ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_WR_FAT_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_WR_FAT_JTAG(a,b,c) cavm_mhbwx_abx_sltx_wr_fat_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_WR_FAT_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_WR_FAT_JTAG(a,b,c) "MHBWX_ABX_SLTX_WR_FAT_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_WR_FAT_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_WR_FAT_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_ab#_slt#_wr_nfat_jtag
 *
 * MHBW WR DMA Non-Fatal Error Job Tag Register
 * These registers record the job tag when a write DMA receives a response
 * indicating a nonfatal error. Errors are reported for the specific HAB and slot
 * that received the error.
 */
union cavm_mhbwx_abx_sltx_wr_nfat_jtag
{
    uint64_t u;
    struct cavm_mhbwx_abx_sltx_wr_nfat_jtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
#else /* Word 0 - Little Endian */
        uint64_t port0                 : 16; /**< [ 15:  0](RO/H) The job tag when a read underflow occurred on port 0. */
        uint64_t port1                 : 16; /**< [ 31: 16](RO/H) The job tag when a read underflow occurred on port 1. */
        uint64_t port2                 : 16; /**< [ 47: 32](RO/H) The job tag when a read underflow occurred on port 2. */
        uint64_t port3                 : 16; /**< [ 63: 48](RO/H) The job tag when a read underflow occurred on port 3. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_abx_sltx_wr_nfat_jtag_s cn; */
};
typedef union cavm_mhbwx_abx_sltx_wr_nfat_jtag cavm_mhbwx_abx_sltx_wr_nfat_jtag_t;

static inline uint64_t CAVM_MHBWX_ABX_SLTX_WR_NFAT_JTAG(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ABX_SLTX_WR_NFAT_JTAG(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=2) && (c<=2)))
        return 0x87e043022600ll + 0x80000ll * ((a) & 0x1f) + 0x40ll * ((b) & 0x3) + 0x10ll * ((c) & 0x3);
    __cavm_csr_fatal("MHBWX_ABX_SLTX_WR_NFAT_JTAG", 3, a, b, c, 0);
}

#define typedef_CAVM_MHBWX_ABX_SLTX_WR_NFAT_JTAG(a,b,c) cavm_mhbwx_abx_sltx_wr_nfat_jtag_t
#define bustype_CAVM_MHBWX_ABX_SLTX_WR_NFAT_JTAG(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ABX_SLTX_WR_NFAT_JTAG(a,b,c) "MHBWX_ABX_SLTX_WR_NFAT_JTAG"
#define busnum_CAVM_MHBWX_ABX_SLTX_WR_NFAT_JTAG(a,b,c) (a)
#define arguments_CAVM_MHBWX_ABX_SLTX_WR_NFAT_JTAG(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) mhbw#_adr_err_ena_w1c
 *
 * MHBW Address Range Error Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_mhbwx_adr_err_ena_w1c
{
    uint64_t u;
    struct cavm_mhbwx_adr_err_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MHBW(0..27)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MHBW(0..27)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MHBW(0..27)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MHBW(0..27)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_adr_err_ena_w1c_s cn; */
};
typedef union cavm_mhbwx_adr_err_ena_w1c cavm_mhbwx_adr_err_ena_w1c_t;

static inline uint64_t CAVM_MHBWX_ADR_ERR_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ADR_ERR_ENA_W1C(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020d10ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ADR_ERR_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ADR_ERR_ENA_W1C(a) cavm_mhbwx_adr_err_ena_w1c_t
#define bustype_CAVM_MHBWX_ADR_ERR_ENA_W1C(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ADR_ERR_ENA_W1C(a) "MHBWX_ADR_ERR_ENA_W1C"
#define busnum_CAVM_MHBWX_ADR_ERR_ENA_W1C(a) (a)
#define arguments_CAVM_MHBWX_ADR_ERR_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_adr_err_ena_w1s
 *
 * MHBW Address Range Error Message Enable Set Registers
 * This register sets interrupt enable bits.
 */
union cavm_mhbwx_adr_err_ena_w1s
{
    uint64_t u;
    struct cavm_mhbwx_adr_err_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MHBW(0..27)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MHBW(0..27)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MHBW(0..27)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MHBW(0..27)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_adr_err_ena_w1s_s cn; */
};
typedef union cavm_mhbwx_adr_err_ena_w1s cavm_mhbwx_adr_err_ena_w1s_t;

static inline uint64_t CAVM_MHBWX_ADR_ERR_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ADR_ERR_ENA_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020d08ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ADR_ERR_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ADR_ERR_ENA_W1S(a) cavm_mhbwx_adr_err_ena_w1s_t
#define bustype_CAVM_MHBWX_ADR_ERR_ENA_W1S(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ADR_ERR_ENA_W1S(a) "MHBWX_ADR_ERR_ENA_W1S"
#define busnum_CAVM_MHBWX_ADR_ERR_ENA_W1S(a) (a)
#define arguments_CAVM_MHBWX_ADR_ERR_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_adr_err_int
 *
 * MHBW Address Range Error Interrupt Register
 * These registers record DMA address range check errors.
 * When an error occurs, the job tag is recorded in the following register.
 * MHBW()_ADR_ERR_JTAG
 *
 * In some cases, read overflow/underflow errors are recorded for the wrong
 * slot, and the wrong job tag is recorded.  In these cases, the correct job
 * tag should be available in the HAB_ERROR_SOURCE0 register for the given
 * HAB.
 *
 * When an error occurs, the MHAB sends an error message to PSM which then
 * triggers an interrupt, if enabled. In addition, the MHBW sends the command
 * specified by \<MHBW()_ADR_ERR_JCE_W1, MHBW()_ADR_ERR_JCE_W0\>
 * to the PSM.
 */
union cavm_mhbwx_adr_err_int
{
    uint64_t u;
    struct cavm_mhbwx_adr_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) NXM access detected for GAA writes. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) NXM access detected for GAA reads. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) L2C/DDR access range error. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) SMEM access range error. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1C/H) SMEM access range error. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1C/H) L2C/DDR access range error. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1C/H) NXM access detected for GAA reads. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1C/H) NXM access detected for GAA writes. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_adr_err_int_s cn; */
};
typedef union cavm_mhbwx_adr_err_int cavm_mhbwx_adr_err_int_t;

static inline uint64_t CAVM_MHBWX_ADR_ERR_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ADR_ERR_INT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020d00ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ADR_ERR_INT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ADR_ERR_INT(a) cavm_mhbwx_adr_err_int_t
#define bustype_CAVM_MHBWX_ADR_ERR_INT(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ADR_ERR_INT(a) "MHBWX_ADR_ERR_INT"
#define busnum_CAVM_MHBWX_ADR_ERR_INT(a) (a)
#define arguments_CAVM_MHBWX_ADR_ERR_INT(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_adr_err_int_w1s
 *
 * MHBW Address Range Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_mhbwx_adr_err_int_w1s
{
    uint64_t u;
    struct cavm_mhbwx_adr_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t smem_range_err        : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MHBW(0..27)_ADR_ERR_INT[SMEM_RANGE_ERR]. */
        uint64_t ddr_range_err         : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MHBW(0..27)_ADR_ERR_INT[DDR_RANGE_ERR]. */
        uint64_t gaa_rd_nxm_err        : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MHBW(0..27)_ADR_ERR_INT[GAA_RD_NXM_ERR]. */
        uint64_t gaa_wr_nxm_err        : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MHBW(0..27)_ADR_ERR_INT[GAA_WR_NXM_ERR]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_adr_err_int_w1s_s cn; */
};
typedef union cavm_mhbwx_adr_err_int_w1s cavm_mhbwx_adr_err_int_w1s_t;

static inline uint64_t CAVM_MHBWX_ADR_ERR_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ADR_ERR_INT_W1S(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020d18ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ADR_ERR_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ADR_ERR_INT_W1S(a) cavm_mhbwx_adr_err_int_w1s_t
#define bustype_CAVM_MHBWX_ADR_ERR_INT_W1S(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ADR_ERR_INT_W1S(a) "MHBWX_ADR_ERR_INT_W1S"
#define busnum_CAVM_MHBWX_ADR_ERR_INT_W1S(a) (a)
#define arguments_CAVM_MHBWX_ADR_ERR_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_adr_err_jtag
 *
 * MHBW Address Range Error Job Tag Registers
 * This register records the job tag of an address range error interrupt.
 * In some cases, the wrong job tag will be recorded.
 * In these cases, the HAB_ERROR_SOURCE0 register for the given HAB
 * should report the correct job tag.
 */
union cavm_mhbwx_adr_err_jtag
{
    uint64_t u;
    struct cavm_mhbwx_adr_err_jtag_s
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
    /* struct cavm_mhbwx_adr_err_jtag_s cn; */
};
typedef union cavm_mhbwx_adr_err_jtag cavm_mhbwx_adr_err_jtag_t;

static inline uint64_t CAVM_MHBWX_ADR_ERR_JTAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ADR_ERR_JTAG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020d20ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ADR_ERR_JTAG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ADR_ERR_JTAG(a) cavm_mhbwx_adr_err_jtag_t
#define bustype_CAVM_MHBWX_ADR_ERR_JTAG(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ADR_ERR_JTAG(a) "MHBWX_ADR_ERR_JTAG"
#define busnum_CAVM_MHBWX_ADR_ERR_JTAG(a) (a)
#define arguments_CAVM_MHBWX_ADR_ERR_JTAG(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_adr_error_jce_w0
 *
 * MHBW Address Error JCE Word 0 Register
 * This register specifies the low 64 bits of a PSM command issued when an
 * address error occurs.
 */
union cavm_mhbwx_adr_error_jce_w0
{
    uint64_t u;
    struct cavm_mhbwx_adr_error_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a job timeout. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a job timeout. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_adr_error_jce_w0_s cn; */
};
typedef union cavm_mhbwx_adr_error_jce_w0 cavm_mhbwx_adr_error_jce_w0_t;

static inline uint64_t CAVM_MHBWX_ADR_ERROR_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ADR_ERROR_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020060ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ADR_ERROR_JCE_W0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ADR_ERROR_JCE_W0(a) cavm_mhbwx_adr_error_jce_w0_t
#define bustype_CAVM_MHBWX_ADR_ERROR_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ADR_ERROR_JCE_W0(a) "MHBWX_ADR_ERROR_JCE_W0"
#define busnum_CAVM_MHBWX_ADR_ERROR_JCE_W0(a) (a)
#define arguments_CAVM_MHBWX_ADR_ERROR_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_adr_error_jce_w1
 *
 * MHBW Address Error JCE Word 1 Register
 * This register specifies the high 64 bits of a PSM command issued when an
 * address error occurs.
 */
union cavm_mhbwx_adr_error_jce_w1
{
    uint64_t u;
    struct cavm_mhbwx_adr_error_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a job timeout. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a job timeout. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_adr_error_jce_w1_s cn; */
};
typedef union cavm_mhbwx_adr_error_jce_w1 cavm_mhbwx_adr_error_jce_w1_t;

static inline uint64_t CAVM_MHBWX_ADR_ERROR_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ADR_ERROR_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020068ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ADR_ERROR_JCE_W1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ADR_ERROR_JCE_W1(a) cavm_mhbwx_adr_error_jce_w1_t
#define bustype_CAVM_MHBWX_ADR_ERROR_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ADR_ERROR_JCE_W1(a) "MHBWX_ADR_ERROR_JCE_W1"
#define busnum_CAVM_MHBWX_ADR_ERROR_JCE_W1(a) (a)
#define arguments_CAVM_MHBWX_ADR_ERROR_JCE_W1(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_cfg
 *
 * MHBW Configuration Register
 * These registers specify the clock, reset, and priority configuration of
 * each MHAB. See [AB_ENA] for the HAB reset procedure.
 */
union cavm_mhbwx_cfg
{
    uint64_t u;
    struct cavm_mhbwx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_51_63        : 13;
        uint64_t mhbw_done             : 1;  /**< [ 50: 50](RO/H) Indicates the MHBW has been disabled and has finished clearing all
                                                                 internal state. When resetting the MHBW, software must wait until this
                                                                 bit is set before re-enabling the MHBW via MHBW()_CFG[ENA]. */
        uint64_t ab_done               : 4;  /**< [ 49: 46](RO/H) For each HAB, these bits indicate when it has been disabled and
                                                                 all associated state has been cleared. When resetting a HAB, software
                                                                 must wait until the corresponding bit is set before re-enabling a HAB
                                                                 using MHBW()_CFG[AB_ENA]. */
        uint64_t reserved_29_45        : 17;
        uint64_t mhbw_stopped          : 1;  /**< [ 28: 28](RO/H) TODO
                                                                 Internal:
                                                                 Set to 1 when soft reset begins (i.e., MHBW()_CFG[ENA] written to 0),
                                                                 and remains set to 1 while reset is in progress. Automatically cleared
                                                                 to zero when reset completes (i.e., when MHBW()_CFG[MHBW_DONE] is set
                                                                 to 1). */
        uint64_t ab_stopped            : 4;  /**< [ 27: 24](RO/H) TODO
                                                                 Internal:
                                                                 One bit per HAB. Each bit is set to 1 when he corresponding HAB is
                                                                 disabled (i.e. MHBW()_CFG[AB_ENA] bit is written to 0), and remains
                                                                 set to 1 while reset is in progress. Automatically cleared to zero
                                                                 when reset completes (i.e., when corresponding bit in
                                                                 MHBW()_CFG[AB_DONE] is set to 1). */
        uint64_t ab_busy               : 4;  /**< [ 23: 20](RO/H) Each bit, when set to 1, indicates a HAB is busy processing a job. */
        uint64_t ab_ena                : 4;  /**< [ 19: 16](R/W) Enable or disable each HAB. HABs must be disabled one at a time. When
                                                                 a HAB is disabled, hardware starts the HAB reset flush sequence.
                                                                 Software must wait until the corresponding bit in [AB_DONE] is set
                                                                 before disabling the next HAB. After disabling a HAB, software cannot re-enable the HAB
                                                                 without completing the MHBW reset flush sequence as follows:

                                                                 _ 1. Disable an HAB by setting the corresponding [AB_ENA] bit to 0.

                                                                 _ 2. Poll the corresponding [AB_DONE] bit until it is set by hardware.

                                                                 _ 3. Repeat step 1 and 2 for all existing HABs.

                                                                 _ 4. After all HABs are disabled, disable the MHBW by writing [ENA] = 0.

                                                                 _ 5. Poll [MHBW_DONE] until it is set by hardware.

                                                                 _ 6. After the MHBW flush done, enable the MHBW by writing [ENA] = 1.

                                                                 _ 7. Enable the HABs, one at a time or all together, by setting the [AB_ENA] bits to 1. */
        uint64_t reserved_12_15        : 4;
        uint64_t ab_uclk_force_on      : 4;  /**< [ 11:  8](R/W) Set one to force the HAB unconditional clock to be always on. A CYA function. */
        uint64_t ab_cclk_force_on      : 4;  /**< [  7:  4](R/W) Set one to force the HAB conditional clock to be always on. A CYA function. */
        uint64_t reserved_3            : 1;
        uint64_t job_slot_ena          : 1;  /**< [  2:  2](R/W) Enable job pipelining.
                                                                 0 = Jobs are only scheduled to slot 0 for each HAB.
                                                                 1 = Jobs are scheduled to all slots supported by the HAB, allowing
                                                                 multiple jobs to be active at once.

                                                                 Note that software must ensure the MHBW is in an idle state, i.e, no
                                                                 active or pending jobs, before setting this bit. */
        uint64_t ena                   : 1;  /**< [  1:  1](R/W) When set enables the MHBW. When cleared to zero, disables the MHBW.
                                                                 Note that all HABs must be disabled using MHBW()_CFG[AB_ENA] before
                                                                 disabling the MHBW.

                                                                 While disabled, any jobs scheduled to the MHAB will be dropped.

                                                                 After disabling the MHBW, software must wait until
                                                                 MHBW()_CFG[MHBW_DONE] is set before re-enabling it. */
        uint64_t mhbw_cclk_force_on    : 1;  /**< [  0:  0](R/W) Set one to force the MHBW conditional clock to be always on. A CYA function. */
#else /* Word 0 - Little Endian */
        uint64_t mhbw_cclk_force_on    : 1;  /**< [  0:  0](R/W) Set one to force the MHBW conditional clock to be always on. A CYA function. */
        uint64_t ena                   : 1;  /**< [  1:  1](R/W) When set enables the MHBW. When cleared to zero, disables the MHBW.
                                                                 Note that all HABs must be disabled using MHBW()_CFG[AB_ENA] before
                                                                 disabling the MHBW.

                                                                 While disabled, any jobs scheduled to the MHAB will be dropped.

                                                                 After disabling the MHBW, software must wait until
                                                                 MHBW()_CFG[MHBW_DONE] is set before re-enabling it. */
        uint64_t job_slot_ena          : 1;  /**< [  2:  2](R/W) Enable job pipelining.
                                                                 0 = Jobs are only scheduled to slot 0 for each HAB.
                                                                 1 = Jobs are scheduled to all slots supported by the HAB, allowing
                                                                 multiple jobs to be active at once.

                                                                 Note that software must ensure the MHBW is in an idle state, i.e, no
                                                                 active or pending jobs, before setting this bit. */
        uint64_t reserved_3            : 1;
        uint64_t ab_cclk_force_on      : 4;  /**< [  7:  4](R/W) Set one to force the HAB conditional clock to be always on. A CYA function. */
        uint64_t ab_uclk_force_on      : 4;  /**< [ 11:  8](R/W) Set one to force the HAB unconditional clock to be always on. A CYA function. */
        uint64_t reserved_12_15        : 4;
        uint64_t ab_ena                : 4;  /**< [ 19: 16](R/W) Enable or disable each HAB. HABs must be disabled one at a time. When
                                                                 a HAB is disabled, hardware starts the HAB reset flush sequence.
                                                                 Software must wait until the corresponding bit in [AB_DONE] is set
                                                                 before disabling the next HAB. After disabling a HAB, software cannot re-enable the HAB
                                                                 without completing the MHBW reset flush sequence as follows:

                                                                 _ 1. Disable an HAB by setting the corresponding [AB_ENA] bit to 0.

                                                                 _ 2. Poll the corresponding [AB_DONE] bit until it is set by hardware.

                                                                 _ 3. Repeat step 1 and 2 for all existing HABs.

                                                                 _ 4. After all HABs are disabled, disable the MHBW by writing [ENA] = 0.

                                                                 _ 5. Poll [MHBW_DONE] until it is set by hardware.

                                                                 _ 6. After the MHBW flush done, enable the MHBW by writing [ENA] = 1.

                                                                 _ 7. Enable the HABs, one at a time or all together, by setting the [AB_ENA] bits to 1. */
        uint64_t ab_busy               : 4;  /**< [ 23: 20](RO/H) Each bit, when set to 1, indicates a HAB is busy processing a job. */
        uint64_t ab_stopped            : 4;  /**< [ 27: 24](RO/H) TODO
                                                                 Internal:
                                                                 One bit per HAB. Each bit is set to 1 when he corresponding HAB is
                                                                 disabled (i.e. MHBW()_CFG[AB_ENA] bit is written to 0), and remains
                                                                 set to 1 while reset is in progress. Automatically cleared to zero
                                                                 when reset completes (i.e., when corresponding bit in
                                                                 MHBW()_CFG[AB_DONE] is set to 1). */
        uint64_t mhbw_stopped          : 1;  /**< [ 28: 28](RO/H) TODO
                                                                 Internal:
                                                                 Set to 1 when soft reset begins (i.e., MHBW()_CFG[ENA] written to 0),
                                                                 and remains set to 1 while reset is in progress. Automatically cleared
                                                                 to zero when reset completes (i.e., when MHBW()_CFG[MHBW_DONE] is set
                                                                 to 1). */
        uint64_t reserved_29_45        : 17;
        uint64_t ab_done               : 4;  /**< [ 49: 46](RO/H) For each HAB, these bits indicate when it has been disabled and
                                                                 all associated state has been cleared. When resetting a HAB, software
                                                                 must wait until the corresponding bit is set before re-enabling a HAB
                                                                 using MHBW()_CFG[AB_ENA]. */
        uint64_t mhbw_done             : 1;  /**< [ 50: 50](RO/H) Indicates the MHBW has been disabled and has finished clearing all
                                                                 internal state. When resetting the MHBW, software must wait until this
                                                                 bit is set before re-enabling the MHBW via MHBW()_CFG[ENA]. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_cfg_s cn; */
};
typedef union cavm_mhbwx_cfg cavm_mhbwx_cfg_t;

static inline uint64_t CAVM_MHBWX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_CFG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020000ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_CFG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_CFG(a) cavm_mhbwx_cfg_t
#define bustype_CAVM_MHBWX_CFG(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_CFG(a) "MHBWX_CFG"
#define busnum_CAVM_MHBWX_CFG(a) (a)
#define arguments_CAVM_MHBWX_CFG(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_debug1
 *
 * INTERNAL: MHBW Debug 1 Register
 *
 * This register set, specifies special debug CSR's for internal used per MHBW.
 * Specifically, This
 * register set contains bits, which specify the a master reset to the MHBW.
 */
union cavm_mhbwx_debug1
{
    uint64_t u;
    struct cavm_mhbwx_debug1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t master_reset_n        : 1;  /**< [ 63: 63](R/W) Internal:
                                                                 This debug reset bit is used to reset (active low) the MAB irrespective of
                                                                 quiescience state.
                                                                 This must not be used unless it is assured there are no PSM credit returns required.
                                                                 Alternatively, the PSM queue and credits for this MAB needs to be restored after this
                                                                 operation. Further, all system access for this MHB needs to be flushed from the system
                                                                 before re-enabling this block. This is primarily for debug puposes only. Writing a 0
                                                                 resets the MHB and writing a 1 brings the MHB out of reset. */
        uint64_t reserved_2_62         : 61;
        uint64_t gaa_dbg_en            : 1;  /**< [  1:  1](R/W) Enables the GAA debug mux data on the bus. As this muxs data from SRAM and flp_fif's, this
                                                                 bit gates unqualified data. */
        uint64_t amm_dbg_en            : 1;  /**< [  0:  0](R/W) Enables the AMM debug mux data on the bus. As this muxs data from SRAM and flp_fif's, this
                                                                 bit gates unqualified data. */
#else /* Word 0 - Little Endian */
        uint64_t amm_dbg_en            : 1;  /**< [  0:  0](R/W) Enables the AMM debug mux data on the bus. As this muxs data from SRAM and flp_fif's, this
                                                                 bit gates unqualified data. */
        uint64_t gaa_dbg_en            : 1;  /**< [  1:  1](R/W) Enables the GAA debug mux data on the bus. As this muxs data from SRAM and flp_fif's, this
                                                                 bit gates unqualified data. */
        uint64_t reserved_2_62         : 61;
        uint64_t master_reset_n        : 1;  /**< [ 63: 63](R/W) Internal:
                                                                 This debug reset bit is used to reset (active low) the MAB irrespective of
                                                                 quiescience state.
                                                                 This must not be used unless it is assured there are no PSM credit returns required.
                                                                 Alternatively, the PSM queue and credits for this MAB needs to be restored after this
                                                                 operation. Further, all system access for this MHB needs to be flushed from the system
                                                                 before re-enabling this block. This is primarily for debug puposes only. Writing a 0
                                                                 resets the MHB and writing a 1 brings the MHB out of reset. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_debug1_s cn; */
};
typedef union cavm_mhbwx_debug1 cavm_mhbwx_debug1_t;

static inline uint64_t CAVM_MHBWX_DEBUG1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_DEBUG1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e04302d200ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_DEBUG1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_DEBUG1(a) cavm_mhbwx_debug1_t
#define bustype_CAVM_MHBWX_DEBUG1(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_DEBUG1(a) "MHBWX_DEBUG1"
#define busnum_CAVM_MHBWX_DEBUG1(a) (a)
#define arguments_CAVM_MHBWX_DEBUG1(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_dma_error_jce_w0
 *
 * MHBW DMA Error JCE Word 0 Register
 * This register specifies the low 64 bits of a PSM command issued when the
 * MHBW has a DMA error.
 */
union cavm_mhbwx_dma_error_jce_w0
{
    uint64_t u;
    struct cavm_mhbwx_dma_error_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a DMA error. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a DMA error. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_dma_error_jce_w0_s cn; */
};
typedef union cavm_mhbwx_dma_error_jce_w0 cavm_mhbwx_dma_error_jce_w0_t;

static inline uint64_t CAVM_MHBWX_DMA_ERROR_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_DMA_ERROR_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020020ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_DMA_ERROR_JCE_W0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_DMA_ERROR_JCE_W0(a) cavm_mhbwx_dma_error_jce_w0_t
#define bustype_CAVM_MHBWX_DMA_ERROR_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_DMA_ERROR_JCE_W0(a) "MHBWX_DMA_ERROR_JCE_W0"
#define busnum_CAVM_MHBWX_DMA_ERROR_JCE_W0(a) (a)
#define arguments_CAVM_MHBWX_DMA_ERROR_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_dma_error_jce_w1
 *
 * MHBW DMA Error JCE Word 1 Register
 * This register specifies the high 64 bits of a PSM command issued when the
 * MHBW has a DMA error.
 */
union cavm_mhbwx_dma_error_jce_w1
{
    uint64_t u;
    struct cavm_mhbwx_dma_error_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a DMA error. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a DMA error. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_dma_error_jce_w1_s cn; */
};
typedef union cavm_mhbwx_dma_error_jce_w1 cavm_mhbwx_dma_error_jce_w1_t;

static inline uint64_t CAVM_MHBWX_DMA_ERROR_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_DMA_ERROR_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020028ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_DMA_ERROR_JCE_W1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_DMA_ERROR_JCE_W1(a) cavm_mhbwx_dma_error_jce_w1_t
#define bustype_CAVM_MHBWX_DMA_ERROR_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_DMA_ERROR_JCE_W1(a) "MHBWX_DMA_ERROR_JCE_W1"
#define busnum_CAVM_MHBWX_DMA_ERROR_JCE_W1(a) (a)
#define arguments_CAVM_MHBWX_DMA_ERROR_JCE_W1(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_eco
 *
 * INTERNAL: MHBW ECO Register
 */
union cavm_mhbwx_eco
{
    uint64_t u;
    struct cavm_mhbwx_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_eco_s cn; */
};
typedef union cavm_mhbwx_eco cavm_mhbwx_eco_t;

static inline uint64_t CAVM_MHBWX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ECO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e04302f000ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ECO", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ECO(a) cavm_mhbwx_eco_t
#define bustype_CAVM_MHBWX_ECO(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ECO(a) "MHBWX_ECO"
#define busnum_CAVM_MHBWX_ECO(a) (a)
#define arguments_CAVM_MHBWX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_err_stat0
 *
 * MHBW Errors Statistic 0 Register
 * These registers count fatal and nonfatal errors (excluding ECC errors in
 * MHBW memories). Note that if multiple HABs have errors in the exact same
 * cycle, only one is counted. Both counters wrap to zero at 2^32.
 *
 * Internal:
 * If the stat counter indicates per clock increment, this implies one
 * of error signalling was a level signal and did not conform to specification. It also indicates
 * a potential deadlock condition, if the counter rolls on for an extended period of time.
 */
union cavm_mhbwx_err_stat0
{
    uint64_t u;
    struct cavm_mhbwx_err_stat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nfat_err_stat         : 32; /**< [ 63: 32](R/W/H) Count of nonfatal errors.
                                                                 Internal:
                                                                 This does not account for
                                                                 multiple nonfatal errors that might occur across different jobs, AB's in the same clock
                                                                 cycle. */
        uint64_t fat_err_stat          : 32; /**< [ 31:  0](R/W/H) Count of fatal errors.
                                                                 Internal:
                                                                 This does not account for
                                                                 multiple fatal errors that might occur across different jobs, AB's in the same clock
                                                                 cycle. */
#else /* Word 0 - Little Endian */
        uint64_t fat_err_stat          : 32; /**< [ 31:  0](R/W/H) Count of fatal errors.
                                                                 Internal:
                                                                 This does not account for
                                                                 multiple fatal errors that might occur across different jobs, AB's in the same clock
                                                                 cycle. */
        uint64_t nfat_err_stat         : 32; /**< [ 63: 32](R/W/H) Count of nonfatal errors.
                                                                 Internal:
                                                                 This does not account for
                                                                 multiple nonfatal errors that might occur across different jobs, AB's in the same clock
                                                                 cycle. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_err_stat0_s cn; */
};
typedef union cavm_mhbwx_err_stat0 cavm_mhbwx_err_stat0_t;

static inline uint64_t CAVM_MHBWX_ERR_STAT0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ERR_STAT0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043022818ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ERR_STAT0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ERR_STAT0(a) cavm_mhbwx_err_stat0_t
#define bustype_CAVM_MHBWX_ERR_STAT0(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ERR_STAT0(a) "MHBWX_ERR_STAT0"
#define busnum_CAVM_MHBWX_ERR_STAT0(a) (a)
#define arguments_CAVM_MHBWX_ERR_STAT0(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_err_stat1
 *
 * MHBW Errors Statistic 1 Register
 * These registers count DMA errors for each MHAB. Note that if errors are
 * reported on multiple ports, or for multiple HABs in the same cycle, then
 * only one error is counted. The counter wraps to zero at 2^32.
 *
 * Internal:
 * If the stat counter indicates per clock increment, this implies
 * one of error signalling was a level signal and did not conform to
 * specification. It also indicates a potential deadlock condition, if the
 * counter rolls on for an extended period of time.
 */
union cavm_mhbwx_err_stat1
{
    uint64_t u;
    struct cavm_mhbwx_err_stat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t adr_err_stat          : 32; /**< [ 63: 32](R/W/H) Count of Address range errors.
                                                                 Internal:
                                                                 This does not account for multiple
                                                                 DMA errors that might occur across different jobs, AB's in the same clock cycle. */
        uint64_t dma_err_stat          : 32; /**< [ 31:  0](R/W/H) Count of DMA errors.
                                                                 Internal:
                                                                 This does not account for multiple
                                                                 DMA errors that might occur across different jobs, AB's in the same clock cycle. */
#else /* Word 0 - Little Endian */
        uint64_t dma_err_stat          : 32; /**< [ 31:  0](R/W/H) Count of DMA errors.
                                                                 Internal:
                                                                 This does not account for multiple
                                                                 DMA errors that might occur across different jobs, AB's in the same clock cycle. */
        uint64_t adr_err_stat          : 32; /**< [ 63: 32](R/W/H) Count of Address range errors.
                                                                 Internal:
                                                                 This does not account for multiple
                                                                 DMA errors that might occur across different jobs, AB's in the same clock cycle. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_err_stat1_s cn; */
};
typedef union cavm_mhbwx_err_stat1 cavm_mhbwx_err_stat1_t;

static inline uint64_t CAVM_MHBWX_ERR_STAT1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_ERR_STAT1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043022820ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_ERR_STAT1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_ERR_STAT1(a) cavm_mhbwx_err_stat1_t
#define bustype_CAVM_MHBWX_ERR_STAT1(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_ERR_STAT1(a) "MHBWX_ERR_STAT1"
#define busnum_CAVM_MHBWX_ERR_STAT1(a) (a)
#define arguments_CAVM_MHBWX_ERR_STAT1(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_ext#_sfunc
 *
 * INTERNAL: MHBW External Special Function Register
 *
 * This register set, specifies any special MHBW direct CSR functionality that is required by a HAB.
 */
union cavm_mhbwx_extx_sfunc
{
    uint64_t u;
    struct cavm_mhbwx_extx_sfunc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ext                   : 64; /**< [ 63:  0](R/W/H) Please see corresponding HAB for special function definitions. */
#else /* Word 0 - Little Endian */
        uint64_t ext                   : 64; /**< [ 63:  0](R/W/H) Please see corresponding HAB for special function definitions. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_extx_sfunc_s cn; */
};
typedef union cavm_mhbwx_extx_sfunc cavm_mhbwx_extx_sfunc_t;

static inline uint64_t CAVM_MHBWX_EXTX_SFUNC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_EXTX_SFUNC(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=3)))
        return 0x87e04302d100ll + 0x80000ll * ((a) & 0x1f) + 0x10ll * ((b) & 0x3);
    __cavm_csr_fatal("MHBWX_EXTX_SFUNC", 2, a, b, 0, 0);
}

#define typedef_CAVM_MHBWX_EXTX_SFUNC(a,b) cavm_mhbwx_extx_sfunc_t
#define bustype_CAVM_MHBWX_EXTX_SFUNC(a,b) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_EXTX_SFUNC(a,b) "MHBWX_EXTX_SFUNC"
#define busnum_CAVM_MHBWX_EXTX_SFUNC(a,b) (a)
#define arguments_CAVM_MHBWX_EXTX_SFUNC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mhbw#_fatal_error_jce_w0
 *
 * MHBW Fatal Error JCE Word 0 Register
 * This register specifies the low 64 bits of a PSM command issued when the
 * MHBW or one of its HABs suffer a fatal error.
 */
union cavm_mhbwx_fatal_error_jce_w0
{
    uint64_t u;
    struct cavm_mhbwx_fatal_error_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a fatal error. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a fatal error. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_fatal_error_jce_w0_s cn; */
};
typedef union cavm_mhbwx_fatal_error_jce_w0 cavm_mhbwx_fatal_error_jce_w0_t;

static inline uint64_t CAVM_MHBWX_FATAL_ERROR_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_FATAL_ERROR_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020030ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_FATAL_ERROR_JCE_W0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_FATAL_ERROR_JCE_W0(a) cavm_mhbwx_fatal_error_jce_w0_t
#define bustype_CAVM_MHBWX_FATAL_ERROR_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_FATAL_ERROR_JCE_W0(a) "MHBWX_FATAL_ERROR_JCE_W0"
#define busnum_CAVM_MHBWX_FATAL_ERROR_JCE_W0(a) (a)
#define arguments_CAVM_MHBWX_FATAL_ERROR_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_fatal_error_jce_w1
 *
 * MHBW Fatal Error JCE Word 1 Register
 * This register specifies the high 64 bits of a PSM command issued when the
 * MHBW or one of its HABs suffer a fatal error.
 */
union cavm_mhbwx_fatal_error_jce_w1
{
    uint64_t u;
    struct cavm_mhbwx_fatal_error_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a fatal error. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a fatal error. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_fatal_error_jce_w1_s cn; */
};
typedef union cavm_mhbwx_fatal_error_jce_w1 cavm_mhbwx_fatal_error_jce_w1_t;

static inline uint64_t CAVM_MHBWX_FATAL_ERROR_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_FATAL_ERROR_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020038ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_FATAL_ERROR_JCE_W1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_FATAL_ERROR_JCE_W1(a) cavm_mhbwx_fatal_error_jce_w1_t
#define bustype_CAVM_MHBWX_FATAL_ERROR_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_FATAL_ERROR_JCE_W1(a) "MHBWX_FATAL_ERROR_JCE_W1"
#define busnum_CAVM_MHBWX_FATAL_ERROR_JCE_W1(a) (a)
#define arguments_CAVM_MHBWX_FATAL_ERROR_JCE_W1(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_fyi
 *
 * MHBW For Your Information Register
 * These registers detail the specification of each MHBW.
 */
union cavm_mhbwx_fyi
{
    uint64_t u;
    struct cavm_mhbwx_fyi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t psm_did               : 6;  /**< [ 63: 58](RO/H) The PSM ID used to schedule jobs on this MHAB (i.e., the bit to set in
                                                                 PSM_RSRC_TBL()[MAB_MAP] to map a job type to this MHAB). */
        uint64_t reserved_57           : 1;
        uint64_t pnb                   : 1;  /**< [ 56: 56](RO/H) The PNB channel number for L2C/DDR access. */
        uint64_t ghb                   : 4;  /**< [ 55: 52](RO/H) The GHAB number the MHAB attached to. */
        uint64_t reserved_50_51        : 2;
        uint64_t ghb_port              : 2;  /**< [ 49: 48](RO/H) The GHAB port number the MHAB attached to. */
        uint64_t reserved_40_47        : 8;
        uint64_t ab_cores              : 2;  /**< [ 39: 38](RO/H) The number of HABs in the MHAB, minus 1. */
        uint64_t ab_cfg_credit_ena     : 1;  /**< [ 37: 37](RO/H) TODO
                                                                 Internal:
                                                                 This bit specifies if the AB config interface uses credit based access. */
        uint64_t num_ab_rd_ports       : 2;  /**< [ 36: 35](RO/H) The number of read ports for each HAB, minus 1. */
        uint64_t num_ab_wr_ports       : 2;  /**< [ 34: 33](RO/H) The number of write ports for each HAB, minus 1. */
        uint64_t num_ab_job_slots      : 2;  /**< [ 32: 31](RO/H) The number of job slots available in each HAB, minus 1. */
        uint64_t ab_rd_port_0          : 2;  /**< [ 30: 29](RO/H) The width of read port 0, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. */
        uint64_t ab_rd_port_1          : 2;  /**< [ 28: 27](RO/H) The width of read port 1, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_RD_PORTS] \< 1. */
        uint64_t ab_rd_port_2          : 2;  /**< [ 26: 25](RO/H) The width of read port 2, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_RD_PORTS] \< 2. */
        uint64_t ab_rd_port_3          : 2;  /**< [ 24: 23](RO/H) The width of read port 3, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_RD_PORTS] \< 3. */
        uint64_t ab_wr_port_0          : 2;  /**< [ 22: 21](RO/H) The width of write port 0, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. */
        uint64_t ab_wr_port_1          : 2;  /**< [ 20: 19](RO/H) The width of write port 1, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_WR_PORTS] \< 1. */
        uint64_t ab_wr_port_2          : 2;  /**< [ 18: 17](RO/H) The width of write port 2, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_WR_PORTS] \< 2. */
        uint64_t ab_wr_port_3          : 2;  /**< [ 16: 15](RO/H) The width of write port 3, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_WR_PORTS] \< 3. */
        uint64_t reserved_0_14         : 15;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_14         : 15;
        uint64_t ab_wr_port_3          : 2;  /**< [ 16: 15](RO/H) The width of write port 3, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_WR_PORTS] \< 3. */
        uint64_t ab_wr_port_2          : 2;  /**< [ 18: 17](RO/H) The width of write port 2, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_WR_PORTS] \< 2. */
        uint64_t ab_wr_port_1          : 2;  /**< [ 20: 19](RO/H) The width of write port 1, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_WR_PORTS] \< 1. */
        uint64_t ab_wr_port_0          : 2;  /**< [ 22: 21](RO/H) The width of write port 0, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. */
        uint64_t ab_rd_port_3          : 2;  /**< [ 24: 23](RO/H) The width of read port 3, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_RD_PORTS] \< 3. */
        uint64_t ab_rd_port_2          : 2;  /**< [ 26: 25](RO/H) The width of read port 2, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_RD_PORTS] \< 2. */
        uint64_t ab_rd_port_1          : 2;  /**< [ 28: 27](RO/H) The width of read port 1, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. Value is undefined if
                                                                 MHBW()_FYI[NUM_AB_RD_PORTS] \< 1. */
        uint64_t ab_rd_port_0          : 2;  /**< [ 30: 29](RO/H) The width of read port 0, specified using the enumeration
                                                                 MHBW_AB_PORT_WIDTH_E. */
        uint64_t num_ab_job_slots      : 2;  /**< [ 32: 31](RO/H) The number of job slots available in each HAB, minus 1. */
        uint64_t num_ab_wr_ports       : 2;  /**< [ 34: 33](RO/H) The number of write ports for each HAB, minus 1. */
        uint64_t num_ab_rd_ports       : 2;  /**< [ 36: 35](RO/H) The number of read ports for each HAB, minus 1. */
        uint64_t ab_cfg_credit_ena     : 1;  /**< [ 37: 37](RO/H) TODO
                                                                 Internal:
                                                                 This bit specifies if the AB config interface uses credit based access. */
        uint64_t ab_cores              : 2;  /**< [ 39: 38](RO/H) The number of HABs in the MHAB, minus 1. */
        uint64_t reserved_40_47        : 8;
        uint64_t ghb_port              : 2;  /**< [ 49: 48](RO/H) The GHAB port number the MHAB attached to. */
        uint64_t reserved_50_51        : 2;
        uint64_t ghb                   : 4;  /**< [ 55: 52](RO/H) The GHAB number the MHAB attached to. */
        uint64_t pnb                   : 1;  /**< [ 56: 56](RO/H) The PNB channel number for L2C/DDR access. */
        uint64_t reserved_57           : 1;
        uint64_t psm_did               : 6;  /**< [ 63: 58](RO/H) The PSM ID used to schedule jobs on this MHAB (i.e., the bit to set in
                                                                 PSM_RSRC_TBL()[MAB_MAP] to map a job type to this MHAB). */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_fyi_s cn; */
};
typedef union cavm_mhbwx_fyi cavm_mhbwx_fyi_t;

static inline uint64_t CAVM_MHBWX_FYI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_FYI(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020100ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_FYI", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_FYI(a) cavm_mhbwx_fyi_t
#define bustype_CAVM_MHBWX_FYI(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_FYI(a) "MHBWX_FYI"
#define busnum_CAVM_MHBWX_FYI(a) (a)
#define arguments_CAVM_MHBWX_FYI(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_jd_cfg
 *
 * MHBW Additional Configuration Register
 * These registers specify additional MHBW configuration parameters.
 */
union cavm_mhbwx_jd_cfg
{
    uint64_t u;
    struct cavm_mhbwx_jd_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr_range_chk_ena    : 1;  /**< [ 63: 63](R/W) L2C/DDR and SMEM address range check enable. */
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
                                                                 For writes to L2C/DDR, HW allows up to seven cycles over the ON rate limit if the
                                                                 terminal count does not align to the cacheline boundary. */
        uint64_t reserved_8_11         : 4;
        uint64_t timeout_mult          : 4;  /**< [  7:  4](R/W) This set of bits, specifies the timeout multiplier used when
                                                                 calculating job timeout thresholds. See MHBW_JD_HDR_WORD_0_S[TOTH] for
                                                                 details. */
        uint64_t reserved_2_3          : 2;
        uint64_t jd_fetch_cmd_type     : 2;  /**< [  1:  0](R/W) Specifies the command type used when reading a job descriptor
                                                                 (including subdescriptor sections) from main memory. Command types
                                                                 are enumerated in MHBW_PNB_RD_CMD_E.  Note that if
                                                                 MHBW_PNB_RD_CMD_E::LDWB is specified, then any requests for less than
                                                                 128 bytes will be automatically converted to type LDT to avoid
                                                                 accidental loss of data. */
#else /* Word 0 - Little Endian */
        uint64_t jd_fetch_cmd_type     : 2;  /**< [  1:  0](R/W) Specifies the command type used when reading a job descriptor
                                                                 (including subdescriptor sections) from main memory. Command types
                                                                 are enumerated in MHBW_PNB_RD_CMD_E.  Note that if
                                                                 MHBW_PNB_RD_CMD_E::LDWB is specified, then any requests for less than
                                                                 128 bytes will be automatically converted to type LDT to avoid
                                                                 accidental loss of data. */
        uint64_t reserved_2_3          : 2;
        uint64_t timeout_mult          : 4;  /**< [  7:  4](R/W) This set of bits, specifies the timeout multiplier used when
                                                                 calculating job timeout thresholds. See MHBW_JD_HDR_WORD_0_S[TOTH] for
                                                                 details. */
        uint64_t reserved_8_11         : 4;
        uint64_t ghb_wr_on_rate        : 8;  /**< [ 19: 12](R/W) This field specifies the number of contiguous cycles a bursty GHAB transfer can be.
                                                                 A value of 0 stops all GHAB transactions. This field should never be set to 0.
                                                                 For writes to L2C/DDR, HW allows up to seven cycles over the ON rate limit if the
                                                                 terminal count does not align to the cacheline boundary. */
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
        uint64_t addr_range_chk_ena    : 1;  /**< [ 63: 63](R/W) L2C/DDR and SMEM address range check enable. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_jd_cfg_s cn; */
};
typedef union cavm_mhbwx_jd_cfg cavm_mhbwx_jd_cfg_t;

static inline uint64_t CAVM_MHBWX_JD_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_JD_CFG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020008ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_JD_CFG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_JD_CFG(a) cavm_mhbwx_jd_cfg_t
#define bustype_CAVM_MHBWX_JD_CFG(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_JD_CFG(a) "MHBWX_JD_CFG"
#define busnum_CAVM_MHBWX_JD_CFG(a) (a)
#define arguments_CAVM_MHBWX_JD_CFG(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_job_compl_stat
 *
 * MHBW Job Completion Statistic Register
 * These registers count the number of jobs completed by each MHAB.
 */
union cavm_mhbwx_job_compl_stat
{
    uint64_t u;
    struct cavm_mhbwx_job_compl_stat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t stat                  : 48; /**< [ 47:  0](R/W/H) The counter value. Wraps to zero at 2^48. */
#else /* Word 0 - Little Endian */
        uint64_t stat                  : 48; /**< [ 47:  0](R/W/H) The counter value. Wraps to zero at 2^48. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_job_compl_stat_s cn; */
};
typedef union cavm_mhbwx_job_compl_stat cavm_mhbwx_job_compl_stat_t;

static inline uint64_t CAVM_MHBWX_JOB_COMPL_STAT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_JOB_COMPL_STAT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043022808ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_JOB_COMPL_STAT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_JOB_COMPL_STAT(a) cavm_mhbwx_job_compl_stat_t
#define bustype_CAVM_MHBWX_JOB_COMPL_STAT(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_JOB_COMPL_STAT(a) "MHBWX_JOB_COMPL_STAT"
#define busnum_CAVM_MHBWX_JOB_COMPL_STAT(a) (a)
#define arguments_CAVM_MHBWX_JOB_COMPL_STAT(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_job_drop_stat
 *
 * MHBW Job Drop Statistic Register
 * These registers count the number of jobs dropped by each MHAB. Dropped
 * jobs include any jobs received when the MHBW is disabled or when all HABs
 * are disabled, and any jobs active on a HAB when it is disabled.
 *
 * Internal:
 * If multiple AB's are
 * disabled simultaneously the number of dropped jobs will be an underestimate of the total
 * number of jobs.
 */
union cavm_mhbwx_job_drop_stat
{
    uint64_t u;
    struct cavm_mhbwx_job_drop_stat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t stat                  : 32; /**< [ 31:  0](R/W/H) The counter value. Wraps to zero at 2^32. */
#else /* Word 0 - Little Endian */
        uint64_t stat                  : 32; /**< [ 31:  0](R/W/H) The counter value. Wraps to zero at 2^32. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_job_drop_stat_s cn; */
};
typedef union cavm_mhbwx_job_drop_stat cavm_mhbwx_job_drop_stat_t;

static inline uint64_t CAVM_MHBWX_JOB_DROP_STAT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_JOB_DROP_STAT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043022810ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_JOB_DROP_STAT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_JOB_DROP_STAT(a) cavm_mhbwx_job_drop_stat_t
#define bustype_CAVM_MHBWX_JOB_DROP_STAT(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_JOB_DROP_STAT(a) "MHBWX_JOB_DROP_STAT"
#define busnum_CAVM_MHBWX_JOB_DROP_STAT(a) (a)
#define arguments_CAVM_MHBWX_JOB_DROP_STAT(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_job_enqueue_stat
 *
 * MHBW Job Enqueue Statistic Register
 * These registers count the number of job en-queued per MHAB.
 */
union cavm_mhbwx_job_enqueue_stat
{
    uint64_t u;
    struct cavm_mhbwx_job_enqueue_stat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t stat                  : 48; /**< [ 47:  0](R/W/H) The counter value. Wraps to zero at 2^48. */
#else /* Word 0 - Little Endian */
        uint64_t stat                  : 48; /**< [ 47:  0](R/W/H) The counter value. Wraps to zero at 2^48. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_job_enqueue_stat_s cn; */
};
typedef union cavm_mhbwx_job_enqueue_stat cavm_mhbwx_job_enqueue_stat_t;

static inline uint64_t CAVM_MHBWX_JOB_ENQUEUE_STAT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_JOB_ENQUEUE_STAT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043022800ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_JOB_ENQUEUE_STAT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_JOB_ENQUEUE_STAT(a) cavm_mhbwx_job_enqueue_stat_t
#define bustype_CAVM_MHBWX_JOB_ENQUEUE_STAT(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_JOB_ENQUEUE_STAT(a) "MHBWX_JOB_ENQUEUE_STAT"
#define busnum_CAVM_MHBWX_JOB_ENQUEUE_STAT(a) (a)
#define arguments_CAVM_MHBWX_JOB_ENQUEUE_STAT(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_jobq#_cfg
 *
 * MHBW Job Queue Configuration Register
 * This register specifies the job queue attributes to each AB core.
 */
union cavm_mhbwx_jobqx_cfg
{
    uint64_t u;
    struct cavm_mhbwx_jobqx_cfg_s
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
    /* struct cavm_mhbwx_jobqx_cfg_s cn; */
};
typedef union cavm_mhbwx_jobqx_cfg cavm_mhbwx_jobqx_cfg_t;

static inline uint64_t CAVM_MHBWX_JOBQX_CFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_JOBQX_CFG(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=27) && (b<=1)))
        return 0x87e043020010ll + 0x80000ll * ((a) & 0x1f) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("MHBWX_JOBQX_CFG", 2, a, b, 0, 0);
}

#define typedef_CAVM_MHBWX_JOBQX_CFG(a,b) cavm_mhbwx_jobqx_cfg_t
#define bustype_CAVM_MHBWX_JOBQX_CFG(a,b) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_JOBQX_CFG(a,b) "MHBWX_JOBQX_CFG"
#define busnum_CAVM_MHBWX_JOBQX_CFG(a,b) (a)
#define arguments_CAVM_MHBWX_JOBQX_CFG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) mhbw#_non_fatal_error_jce_w0
 *
 * MHBW Non-Fatal Error JCE Word 0 Register
 * This register specifies the low 64 bits of a PSM command issued when the
 * MHBW or one of its HABs suffer a nonfatal error.
 */
union cavm_mhbwx_non_fatal_error_jce_w0
{
    uint64_t u;
    struct cavm_mhbwx_non_fatal_error_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a nonfatal error. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a nonfatal error. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_non_fatal_error_jce_w0_s cn; */
};
typedef union cavm_mhbwx_non_fatal_error_jce_w0 cavm_mhbwx_non_fatal_error_jce_w0_t;

static inline uint64_t CAVM_MHBWX_NON_FATAL_ERROR_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_NON_FATAL_ERROR_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020040ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_NON_FATAL_ERROR_JCE_W0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W0(a) cavm_mhbwx_non_fatal_error_jce_w0_t
#define bustype_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W0(a) "MHBWX_NON_FATAL_ERROR_JCE_W0"
#define busnum_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W0(a) (a)
#define arguments_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_non_fatal_error_jce_w1
 *
 * MHBW Non-Fatal Error JCE Word 1 Register
 * This register specifies the high 64 bits of a PSM command issued when the
 * MHBW or one of its HABs suffer a nonfatal error.
 */
union cavm_mhbwx_non_fatal_error_jce_w1
{
    uint64_t u;
    struct cavm_mhbwx_non_fatal_error_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a nonfatal error. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a nonfatal error. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_non_fatal_error_jce_w1_s cn; */
};
typedef union cavm_mhbwx_non_fatal_error_jce_w1 cavm_mhbwx_non_fatal_error_jce_w1_t;

static inline uint64_t CAVM_MHBWX_NON_FATAL_ERROR_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_NON_FATAL_ERROR_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020048ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_NON_FATAL_ERROR_JCE_W1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W1(a) cavm_mhbwx_non_fatal_error_jce_w1_t
#define bustype_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W1(a) "MHBWX_NON_FATAL_ERROR_JCE_W1"
#define busnum_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W1(a) (a)
#define arguments_CAVM_MHBWX_NON_FATAL_ERROR_JCE_W1(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_phymem_range
 *
 * MHBW BPHY SMEM Address Range Register
 * This register specifies the legal address range for BPHY memory access.
 */
union cavm_mhbwx_phymem_range
{
    uint64_t u;
    struct cavm_mhbwx_phymem_range_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t smem_max_addr         : 25; /**< [ 56: 32](R/W) SMEM max address. 128-bit aligned. */
        uint64_t reserved_25_31        : 7;
        uint64_t smem_min_addr         : 25; /**< [ 24:  0](R/W) SMEM min address. 128-bit aligned. */
#else /* Word 0 - Little Endian */
        uint64_t smem_min_addr         : 25; /**< [ 24:  0](R/W) SMEM min address. 128-bit aligned. */
        uint64_t reserved_25_31        : 7;
        uint64_t smem_max_addr         : 25; /**< [ 56: 32](R/W) SMEM max address. 128-bit aligned. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_phymem_range_s cn; */
};
typedef union cavm_mhbwx_phymem_range cavm_mhbwx_phymem_range_t;

static inline uint64_t CAVM_MHBWX_PHYMEM_RANGE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_PHYMEM_RANGE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043023210ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_PHYMEM_RANGE", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_PHYMEM_RANGE(a) cavm_mhbwx_phymem_range_t
#define bustype_CAVM_MHBWX_PHYMEM_RANGE(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_PHYMEM_RANGE(a) "MHBWX_PHYMEM_RANGE"
#define busnum_CAVM_MHBWX_PHYMEM_RANGE(a) (a)
#define arguments_CAVM_MHBWX_PHYMEM_RANGE(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_sysmem_range_max
 *
 * MHBW L2C/DDR Address Range Max Register
 * This register specifies the legal max address for system memory access.
 */
union cavm_mhbwx_sysmem_range_max
{
    uint64_t u;
    struct cavm_mhbwx_sysmem_range_max_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ddr_max_addr          : 53; /**< [ 52:  0](R/W) L2C/DDR max byte address. */
#else /* Word 0 - Little Endian */
        uint64_t ddr_max_addr          : 53; /**< [ 52:  0](R/W) L2C/DDR max byte address. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_sysmem_range_max_s cn; */
};
typedef union cavm_mhbwx_sysmem_range_max cavm_mhbwx_sysmem_range_max_t;

static inline uint64_t CAVM_MHBWX_SYSMEM_RANGE_MAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_SYSMEM_RANGE_MAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043023208ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_SYSMEM_RANGE_MAX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_SYSMEM_RANGE_MAX(a) cavm_mhbwx_sysmem_range_max_t
#define bustype_CAVM_MHBWX_SYSMEM_RANGE_MAX(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_SYSMEM_RANGE_MAX(a) "MHBWX_SYSMEM_RANGE_MAX"
#define busnum_CAVM_MHBWX_SYSMEM_RANGE_MAX(a) (a)
#define arguments_CAVM_MHBWX_SYSMEM_RANGE_MAX(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_sysmem_range_min
 *
 * MHBW L2C/DDR Address Range Min Register
 * This register specifies the legal min address for system memory access.
 */
union cavm_mhbwx_sysmem_range_min
{
    uint64_t u;
    struct cavm_mhbwx_sysmem_range_min_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ddr_min_addr          : 53; /**< [ 52:  0](R/W) L2C/DDR min byte address. */
#else /* Word 0 - Little Endian */
        uint64_t ddr_min_addr          : 53; /**< [ 52:  0](R/W) L2C/DDR min byte address. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_sysmem_range_min_s cn; */
};
typedef union cavm_mhbwx_sysmem_range_min cavm_mhbwx_sysmem_range_min_t;

static inline uint64_t CAVM_MHBWX_SYSMEM_RANGE_MIN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_SYSMEM_RANGE_MIN(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043023200ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_SYSMEM_RANGE_MIN", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_SYSMEM_RANGE_MIN(a) cavm_mhbwx_sysmem_range_min_t
#define bustype_CAVM_MHBWX_SYSMEM_RANGE_MIN(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_SYSMEM_RANGE_MIN(a) "MHBWX_SYSMEM_RANGE_MIN"
#define busnum_CAVM_MHBWX_SYSMEM_RANGE_MIN(a) (a)
#define arguments_CAVM_MHBWX_SYSMEM_RANGE_MIN(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_timeout_jce_w0
 *
 * MHBW Timeout JCE Word 0 Register
 * This register specifies the low 64 bits of a PSM command issued when a
 * job timeout occurs.
 */
union cavm_mhbwx_timeout_jce_w0
{
    uint64_t u;
    struct cavm_mhbwx_timeout_jce_w0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a job timeout. */
#else /* Word 0 - Little Endian */
        uint64_t ls_word               : 64; /**< [ 63:  0](R/W) The first word of the PSM command to send on a job timeout. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_timeout_jce_w0_s cn; */
};
typedef union cavm_mhbwx_timeout_jce_w0 cavm_mhbwx_timeout_jce_w0_t;

static inline uint64_t CAVM_MHBWX_TIMEOUT_JCE_W0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_TIMEOUT_JCE_W0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020050ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_TIMEOUT_JCE_W0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_TIMEOUT_JCE_W0(a) cavm_mhbwx_timeout_jce_w0_t
#define bustype_CAVM_MHBWX_TIMEOUT_JCE_W0(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_TIMEOUT_JCE_W0(a) "MHBWX_TIMEOUT_JCE_W0"
#define busnum_CAVM_MHBWX_TIMEOUT_JCE_W0(a) (a)
#define arguments_CAVM_MHBWX_TIMEOUT_JCE_W0(a) (a),-1,-1,-1

/**
 * Register (RSL) mhbw#_timeout_jce_w1
 *
 * MHBW Timeout JCE Word 1 Register
 * This register specifies the high 64 bits of a PSM command issued when a
 * job timeout occurs.
 */
union cavm_mhbwx_timeout_jce_w1
{
    uint64_t u;
    struct cavm_mhbwx_timeout_jce_w1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a job timeout. */
#else /* Word 0 - Little Endian */
        uint64_t ms_word               : 64; /**< [ 63:  0](R/W) The second word of the PSM command to send on a job timeout. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mhbwx_timeout_jce_w1_s cn; */
};
typedef union cavm_mhbwx_timeout_jce_w1 cavm_mhbwx_timeout_jce_w1_t;

static inline uint64_t CAVM_MHBWX_TIMEOUT_JCE_W1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MHBWX_TIMEOUT_JCE_W1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=27))
        return 0x87e043020058ll + 0x80000ll * ((a) & 0x1f);
    __cavm_csr_fatal("MHBWX_TIMEOUT_JCE_W1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_MHBWX_TIMEOUT_JCE_W1(a) cavm_mhbwx_timeout_jce_w1_t
#define bustype_CAVM_MHBWX_TIMEOUT_JCE_W1(a) CSR_TYPE_RSL
#define basename_CAVM_MHBWX_TIMEOUT_JCE_W1(a) "MHBWX_TIMEOUT_JCE_W1"
#define busnum_CAVM_MHBWX_TIMEOUT_JCE_W1(a) (a)
#define arguments_CAVM_MHBWX_TIMEOUT_JCE_W1(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_MHBW_H__ */
