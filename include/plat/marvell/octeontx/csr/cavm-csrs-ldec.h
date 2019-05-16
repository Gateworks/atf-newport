#ifndef __CAVM_CSRS_LDEC_H__
#define __CAVM_CSRS_LDEC_H__
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
 * OcteonTX LDEC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure ldec_cb_cfg_s
 *
 * LDEC Code Block Configuration Structure
 * This structure specifies the code block configuration.
 */
union cavm_ldec_cb_cfg_s
{
    uint64_t u[3];
    struct cavm_ldec_cb_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rm_e                  : 21; /**< [ 63: 43] Rate matching size, Er, as defined in section 5.4.2.1 of 38.212.
                                                                 Valid range is [ [CB_SIZE] / 0.95 , [CB_SIZE] * 12 ]. */
        uint64_t nfiller               : 14; /**< [ 42: 29] Number of filler bits, as defined in section 5.2.2 of 38.212. nfiller = K-K. */
        uint64_t reserved_26_28        : 3;
        uint64_t cb_size               : 14; /**< [ 25: 12] Code block size including CB CRC, including filler bits.
                                                                 This corresponds to notation K in 38.212.
                                                                 K = 22*Z for BG1.
                                                                 K = 10*Z for BG2.
                                                                 The valid range is [0x28, 0x2100]. */
        uint64_t code_id               : 3;  /**< [ 11:  9] Reserved.
                                                                 Internal:
                                                                 Used only in DOCSIS.
                                                                 0x3: UL traffic, Long (Z=360).
                                                                 0x4: UL traffic, Medium (Z=180).
                                                                 0x5: UL traffic, Short (Z=56).
                                                                 0x6: Initial ranging.
                                                                 0x7: Fine ranging.
                                                                 0x0 - 0x2: Reserved. */
        uint64_t num_cb                : 9;  /**< [  8:  0] Number of consecutive code blocks with this CB configuration Valid range [0x1, 0x98]. */
#else /* Word 0 - Little Endian */
        uint64_t num_cb                : 9;  /**< [  8:  0] Number of consecutive code blocks with this CB configuration Valid range [0x1, 0x98]. */
        uint64_t code_id               : 3;  /**< [ 11:  9] Reserved.
                                                                 Internal:
                                                                 Used only in DOCSIS.
                                                                 0x3: UL traffic, Long (Z=360).
                                                                 0x4: UL traffic, Medium (Z=180).
                                                                 0x5: UL traffic, Short (Z=56).
                                                                 0x6: Initial ranging.
                                                                 0x7: Fine ranging.
                                                                 0x0 - 0x2: Reserved. */
        uint64_t cb_size               : 14; /**< [ 25: 12] Code block size including CB CRC, including filler bits.
                                                                 This corresponds to notation K in 38.212.
                                                                 K = 22*Z for BG1.
                                                                 K = 10*Z for BG2.
                                                                 The valid range is [0x28, 0x2100]. */
        uint64_t reserved_26_28        : 3;
        uint64_t nfiller               : 14; /**< [ 42: 29] Number of filler bits, as defined in section 5.2.2 of 38.212. nfiller = K-K. */
        uint64_t rm_e                  : 21; /**< [ 63: 43] Rate matching size, Er, as defined in section 5.4.2.1 of 38.212.
                                                                 Valid range is [ [CB_SIZE] / 0.95 , [CB_SIZE] * 12 ]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_112_127      : 16;
        uint64_t hcout_size1           : 16; /**< [111: 96] Length of second section of HARQ output starting from offset [HCOUT_OFFSET] in
                                                                 the pruned circular buffer.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t hcout_size0           : 16; /**< [ 95: 80] Length of first section of HARQ output starting from the beginning of the pruned circular buffer.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t hcout_offset          : 16; /**< [ 79: 64] Offset in pruned circular buffer starting from which the second section of HARQ
                                                                 output is transmitted.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
#else /* Word 1 - Little Endian */
        uint64_t hcout_offset          : 16; /**< [ 79: 64] Offset in pruned circular buffer starting from which the second section of HARQ
                                                                 output is transmitted.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t hcout_size0           : 16; /**< [ 95: 80] Length of first section of HARQ output starting from the beginning of the pruned circular buffer.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t hcout_size1           : 16; /**< [111: 96] Length of second section of HARQ output starting from offset [HCOUT_OFFSET] in
                                                                 the pruned circular buffer.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t reserved_112_127      : 16;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_176_191      : 16;
        uint64_t hcin_size1            : 16; /**< [175:160] Length of the second section of HARQ input starting from offset [HCIN_OFFSET] in
                                                                 the pruned circular buffer.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t hcin_size0            : 16; /**< [159:144] Length of the first section of HARQ input starting from the beginning of the
                                                                 pruned circular buffer.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t hcin_offset           : 16; /**< [143:128] Offset in the pruned circular buffer starting from which the second section of
                                                                 HARQ input is provided.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
#else /* Word 2 - Little Endian */
        uint64_t hcin_offset           : 16; /**< [143:128] Offset in the pruned circular buffer starting from which the second section of
                                                                 HARQ input is provided.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t hcin_size0            : 16; /**< [159:144] Length of the first section of HARQ input starting from the beginning of the
                                                                 pruned circular buffer.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t hcin_size1            : 16; /**< [175:160] Length of the second section of HARQ input starting from offset [HCIN_OFFSET] in
                                                                 the pruned circular buffer.
                                                                 Must be an exact multiple of 16.
                                                                 The valid range is [ 0x0, [NCB_SIZE] ]. */
        uint64_t reserved_176_191      : 16;
#endif /* Word 2 - End */
    } s;
    /* struct cavm_ldec_cb_cfg_s_s cn; */
};

/**
 * Structure ldec_common_cfg_s
 *
 * LDEC Common Task Configuration Structure
 * This structure defines the first word of the job configuration for all
 * LDEC jobs.
 */
union cavm_ldec_common_cfg_s
{
    uint64_t u;
    struct cavm_ldec_common_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t num_words_partial_tb_proc : 4;/**< [ 27: 24] Number of words for specification of parameters for partial TB processing, as
                                                                 defined in the LDEC_OPT_TASK_CFG_S structure.
                                                                 Must be 0x6. */
        uint64_t num_words_per_cb_cfg  : 8;  /**< [ 23: 16] Number of words for each CB configuration appended at the end of the task configuration.
                                                                 Must be 0x3. */
        uint64_t num_words_task_com_cfg : 8; /**< [ 15:  8] Number of mandatory task configuration words per task.
                                                                 Must be 0xB. */
        uint64_t reserved_6_7          : 2;
        uint64_t phy_mode              : 1;  /**< [  5:  5] The task type.
                                                                 0 = 3GPP 5G NR.
                                                                 1 = Reserved.

                                                                 Internal:
                                                                 1 = DOCSIS. */
        uint64_t num_bundled_tasks     : 5;  /**< [  4:  0] Number of tasks that are bundled in one job.  Range [0x1, 0x10]. */
#else /* Word 0 - Little Endian */
        uint64_t num_bundled_tasks     : 5;  /**< [  4:  0] Number of tasks that are bundled in one job.  Range [0x1, 0x10]. */
        uint64_t phy_mode              : 1;  /**< [  5:  5] The task type.
                                                                 0 = 3GPP 5G NR.
                                                                 1 = Reserved.

                                                                 Internal:
                                                                 1 = DOCSIS. */
        uint64_t reserved_6_7          : 2;
        uint64_t num_words_task_com_cfg : 8; /**< [ 15:  8] Number of mandatory task configuration words per task.
                                                                 Must be 0xB. */
        uint64_t num_words_per_cb_cfg  : 8;  /**< [ 23: 16] Number of words for each CB configuration appended at the end of the task configuration.
                                                                 Must be 0x3. */
        uint64_t num_words_partial_tb_proc : 4;/**< [ 27: 24] Number of words for specification of parameters for partial TB processing, as
                                                                 defined in the LDEC_OPT_TASK_CFG_S structure.
                                                                 Must be 0x6. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldec_common_cfg_s_s cn; */
};

/**
 * Structure ldec_opt_task_cfg_s
 *
 * LDEC Optional Task Configuration Structure
 * This structure specifies the optional task configuration for a task for partial TB processing.
 */
union cavm_ldec_opt_task_cfg_s
{
    uint64_t u[6];
    struct cavm_ldec_opt_task_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t hd_prefix_word        : 64; /**< [ 63:  0] 64-bit prefix word to be merged with the first part of decoded bits of the
                                                                 first CB if [HD_PREFIX_BIT_INDEX] \> 0x0 */
#else /* Word 0 - Little Endian */
        uint64_t hd_prefix_word        : 64; /**< [ 63:  0] 64-bit prefix word to be merged with the first part of decoded bits of the
                                                                 first CB if [HD_PREFIX_BIT_INDEX] \> 0x0 */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t hd_suffix_word        : 64; /**< [127: 64] 64-bit suffix word to be merged with the end of decoded bits of the last CB in the task. */
#else /* Word 1 - Little Endian */
        uint64_t hd_suffix_word        : 64; /**< [127: 64] 64-bit suffix word to be merged with the end of decoded bits of the last CB in the task. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reenc_prefix_word     : 64; /**< [191:128] Prefix word to be stitched to the beginning of the re-encoded output of the
                                                                 first CB if [REENC_PREFIX_BIT_INDEX] \> 0x0 */
#else /* Word 2 - Little Endian */
        uint64_t reenc_prefix_word     : 64; /**< [191:128] Prefix word to be stitched to the beginning of the re-encoded output of the
                                                                 first CB if [REENC_PREFIX_BIT_INDEX] \> 0x0 */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t so_prefix_word0       : 64; /**< [255:192] 64 LSBs of prefix word to be stitched to the beginning of the re-encoded soft
                                                                 output of the first CB if [SO_PREFIX_LLR_INDEX] \> 0x0 */
#else /* Word 3 - Little Endian */
        uint64_t so_prefix_word0       : 64; /**< [255:192] 64 LSBs of prefix word to be stitched to the beginning of the re-encoded soft
                                                                 output of the first CB if [SO_PREFIX_LLR_INDEX] \> 0x0 */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t so_prefix_word1       : 64; /**< [319:256] 64 MSBs of prefix word to be stitched to the beginning of the re-encoded soft
                                                                 output of the first CB if [SO_PREFIX_LLR_INDEX] \> 0x0 */
#else /* Word 4 - Little Endian */
        uint64_t so_prefix_word1       : 64; /**< [319:256] 64 MSBs of prefix word to be stitched to the beginning of the re-encoded soft
                                                                 output of the first CB if [SO_PREFIX_LLR_INDEX] \> 0x0 */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t tb_crc_contrib_jump   : 32; /**< [383:352] Maximum 32 bits to represent the jump of TB CRC state from the beginning of the first CB
                                                                 in the task until the end of the TB.
                                                                 Valid range [0x0, TB size]. */
        uint64_t reserved_340_351      : 12;
        uint64_t so_prefix_llr_index   : 4;  /**< [339:336] Applicable only to CB processing mode.
                                                                 LLR index in the prefix word from which the soft output of the current CB task output is written.
                                                                 Valid range [0x0, 0xF].  A value of 0x0 indicates that prefix merge is bypassed. */
        uint64_t reserved_334_335      : 2;
        uint64_t reenc_prefix_bit_index : 6; /**< [333:328] Applicable only to CB processing mode.
                                                                 Bit index in the prefix word from which the re-encoded output of the current CB
                                                                 task output is written.
                                                                 Valid range [0x0, 0x3F].  A value of 0x0 indicates that prefix merge is bypassed. */
        uint64_t reserved_326_327      : 2;
        uint64_t hd_prefix_bit_index   : 6;  /**< [325:320] Bit position of first decoded bit of CBG in 64-bit prefix word provided.
                                                                 Valid range [0x0, 0x3F].  A value of 0x0 indicates that prefix merge is bypassed. */
#else /* Word 5 - Little Endian */
        uint64_t hd_prefix_bit_index   : 6;  /**< [325:320] Bit position of first decoded bit of CBG in 64-bit prefix word provided.
                                                                 Valid range [0x0, 0x3F].  A value of 0x0 indicates that prefix merge is bypassed. */
        uint64_t reserved_326_327      : 2;
        uint64_t reenc_prefix_bit_index : 6; /**< [333:328] Applicable only to CB processing mode.
                                                                 Bit index in the prefix word from which the re-encoded output of the current CB
                                                                 task output is written.
                                                                 Valid range [0x0, 0x3F].  A value of 0x0 indicates that prefix merge is bypassed. */
        uint64_t reserved_334_335      : 2;
        uint64_t so_prefix_llr_index   : 4;  /**< [339:336] Applicable only to CB processing mode.
                                                                 LLR index in the prefix word from which the soft output of the current CB task output is written.
                                                                 Valid range [0x0, 0xF].  A value of 0x0 indicates that prefix merge is bypassed. */
        uint64_t reserved_340_351      : 12;
        uint64_t tb_crc_contrib_jump   : 32; /**< [383:352] Maximum 32 bits to represent the jump of TB CRC state from the beginning of the first CB
                                                                 in the task until the end of the TB.
                                                                 Valid range [0x0, TB size]. */
#endif /* Word 5 - End */
    } s;
    /* struct cavm_ldec_opt_task_cfg_s_s cn; */
};

/**
 * Structure ldec_task_cfg_s
 *
 * LDEC Mandatory Task Configuration Structure
 * This structure specifies the configuration for a task.
 */
union cavm_ldec_task_cfg_s
{
    uint64_t u[11];
    struct cavm_ldec_task_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t negstop_th            : 16; /**< [ 63: 48] Negative stopping threshold. */
        uint64_t stop_it               : 2;  /**< [ 47: 46] Activates the early iteration stopping mechanism upon parity check pass.
                                                                 0 = No stop.
                                                                 1 = Syndrome check based stop. */
        uint64_t so_it                 : 7;  /**< [ 45: 39] Decoder iteration after which soft output shall be released.
                                                                 If decoder stops before, the soft output of the last iteration will be released.
                                                                 Valid range [0x1, 0x7F]. */
        uint64_t max_it                : 7;  /**< [ 38: 32] Maximum number of LDPC decoder iterations. Valid range [0x1, 0x7F]. */
        uint64_t tb_tail               : 1;  /**< [ 31: 31] 0 : Task does not contain the last CB of TB.
                                                                 1 : Task contains the last CB of TB. */
        uint64_t llr_sign_format       : 1;  /**< [ 30: 30] LLR sign format.
                                                                 0 = Zero sign bit indicates positive LLR.
                                                                 1 = One sign bit indicates positive LLR. */
        uint64_t mod_order             : 4;  /**< [ 29: 26] 5G Modulation order. Valid range:  {0x1, 0x2, 0x4, 0x6, 0x8, 0xA}. */
        uint64_t basegraph             : 2;  /**< [ 25: 24] 5G NR LDPC base graph.
                                                                 0: BG1.
                                                                 1: BG2. */
        uint64_t reserved_23           : 1;
        uint64_t bypass_partial_tb_proc : 1; /**< [ 22: 22] 0: Partial TB processing is enabled with the LDEC_OPT_TASK_CFG_S structure present
                                                                 following the mandatory task configuration structure.
                                                                 1: Full TB processing.  The LDEC_OPT_TASK_CFG_S structure is
                                                                 not present following the mandatory task configuration structure. */
        uint64_t num_cb_cfg            : 6;  /**< [ 21: 16] Number of CB configurations appended to this task.
                                                                 Each configuration specifies a string of consecutive CBs sharing the same configuration.
                                                                 Valid range [0x1,0x8] */
        uint64_t task_id               : 16; /**< [ 15:  0] ID associated with this decoding task.
                                                                 Up to 16 tasks can be bundled within a job.
                                                                 SW shall make sure [TASK_ID] values assigned to different tasks bundled within a
                                                                 job do not collide.
                                                                 Valid range [0x0, 0xFFFF]. */
#else /* Word 0 - Little Endian */
        uint64_t task_id               : 16; /**< [ 15:  0] ID associated with this decoding task.
                                                                 Up to 16 tasks can be bundled within a job.
                                                                 SW shall make sure [TASK_ID] values assigned to different tasks bundled within a
                                                                 job do not collide.
                                                                 Valid range [0x0, 0xFFFF]. */
        uint64_t num_cb_cfg            : 6;  /**< [ 21: 16] Number of CB configurations appended to this task.
                                                                 Each configuration specifies a string of consecutive CBs sharing the same configuration.
                                                                 Valid range [0x1,0x8] */
        uint64_t bypass_partial_tb_proc : 1; /**< [ 22: 22] 0: Partial TB processing is enabled with the LDEC_OPT_TASK_CFG_S structure present
                                                                 following the mandatory task configuration structure.
                                                                 1: Full TB processing.  The LDEC_OPT_TASK_CFG_S structure is
                                                                 not present following the mandatory task configuration structure. */
        uint64_t reserved_23           : 1;
        uint64_t basegraph             : 2;  /**< [ 25: 24] 5G NR LDPC base graph.
                                                                 0: BG1.
                                                                 1: BG2. */
        uint64_t mod_order             : 4;  /**< [ 29: 26] 5G Modulation order. Valid range:  {0x1, 0x2, 0x4, 0x6, 0x8, 0xA}. */
        uint64_t llr_sign_format       : 1;  /**< [ 30: 30] LLR sign format.
                                                                 0 = Zero sign bit indicates positive LLR.
                                                                 1 = One sign bit indicates positive LLR. */
        uint64_t tb_tail               : 1;  /**< [ 31: 31] 0 : Task does not contain the last CB of TB.
                                                                 1 : Task contains the last CB of TB. */
        uint64_t max_it                : 7;  /**< [ 38: 32] Maximum number of LDPC decoder iterations. Valid range [0x1, 0x7F]. */
        uint64_t so_it                 : 7;  /**< [ 45: 39] Decoder iteration after which soft output shall be released.
                                                                 If decoder stops before, the soft output of the last iteration will be released.
                                                                 Valid range [0x1, 0x7F]. */
        uint64_t stop_it               : 2;  /**< [ 47: 46] Activates the early iteration stopping mechanism upon parity check pass.
                                                                 0 = No stop.
                                                                 1 = Syndrome check based stop. */
        uint64_t negstop_th            : 16; /**< [ 63: 48] Negative stopping threshold. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_126_127      : 2;
        uint64_t reenc_qm_with_synd    : 1;  /**< [125:125] Reserved.
                                                                 Internal:
                                                                 When set to 1, attach the syndrome bit to each set of [MOD_ORDER] bits,
                                                                 where a value of 1 indicates a passing syndrome and a value of
                                                                 0 indicates a failing syndrome.
                                                                 Not possible to have this enabled when [REENC_SYMB_BYTE_ALIGNED] \> 0x0,
                                                                 or if [REENC_QM_WITH_CRC] is enabled. */
        uint64_t bypass_monitor_words  : 1;  /**< [124:124] 0: All 13 monitoring words are appended to HD output.
                                                                 1: Only first 2 monitoring words are appended to HD output.
                                                                 Following TB CRC contribution words are sent or not depending on the flag [BYPASS_TB_CRC_CONTRIB]. */
        uint64_t tb_tx_bit_size        : 24; /**< [123:100] Total number of input LLR values across all CBs to be used by the task.
                                                                 These are LLRs excluding the ones dropped at the beginning/end and the tagged values.
                                                                 Valid range [0x1, 0x14CB80]. */
        uint64_t hcout_llr_comp_mode   : 3;  /**< [ 99: 97] HARQ LLR output compression scheme.
                                                                 0x0: Bypass (do nothing).
                                                                 0x1: Saturate to 6 bits (8 to 6 bits).
                                                                 0x2: Right shift 1 bit with rounding and saturate to 6 bits (8 to 6 bits).
                                                                 0x3: Right shift 2 bits with rounding (8 to 6 bits).
                                                                 0x4: Round(log2)quantization (8 to 4 bits).
                                                                 Valid range [0x0, 0x4]. */
        uint64_t hcout_en              : 1;  /**< [ 96: 96] 1: HCout vector is released after HARQ combining.
                                                                 0: No HCout vector is released. HARQ combining can still be enabled.
                                                                 This feature can optionally be used when decoding the last transmission. */
        uint64_t hcin_llr_decomp_mode  : 3;  /**< [ 95: 93] HARQ LLR input decompression scheme.
                                                                 0x0: bypass (do nothing).
                                                                 0x1: Sign extension (6 to 8 bits).
                                                                 0x2: Left shift 1 bit and sign extend(6 to 8 bits).
                                                                 0x3: Left shift 2 bits(6 to 8 bits).
                                                                 0x4: Reverse the operation of round(log2)quantization (4 bits to 8 bits).
                                                                 Valid range [0x0, 0x4]. */
        uint64_t hcin_en               : 1;  /**< [ 92: 92] 0: Only input LLRs are expected to be received. HARQ is either disabled or this
                                                                 is the first transmission.
                                                                 1: HARQ input is enabled. The core expects to receive HCin stream once all input LLRs are received. */
        uint64_t reenc_data_order      : 3;  /**< [ 91: 89] Bit 25:
                                                                   0: DATA_BIT_MSB_FIRST.
                                                                   1: DATA_BIT_LSB_FIRST.
                                                                   Refer to [R1] for data packing details.
                                                                 Bits 26:27:
                                                                   0x0: DATA_BYTE_ORDER_MODE_0.
                                                                   0x1: DATA_BYTE_ORDER_MODE_1.
                                                                   0x2: DATA_BYTE_ORDER_MODE_2.
                                                                   Refer to [R1] for data packing details.
                                                                   For normal usage, it shall be set to DATA_BYTE_ORDER_MODE_0. */
        uint64_t reenc_qm_with_crc     : 1;  /**< [ 88: 88] 1 : Add 1-bit CB CRC result to each set of [MOD_ORDER] bits output.
                                                                 0 : No CRC addition.
                                                                 This feature can be enabled only when [REENC_SYMB_SYMB_ALIGNED] = 0x0. */
        uint64_t reenc_symb_byte_aligned : 2;/**< [ 87: 86] Alignment mode.

                                                                 _ 0x0 = No alignment. Data bits are written out back to back.

                                                                 _ 0x1 = Byte alignment. Every [MOD_ORDER] bits are mapped to one byte
                                                                 in little endian format, with zero padding in the upper bits in each
                                                                 byte. Can only be used when [MOD_ORDER] \< 0xA.

                                                                 _ 0x2 = Two-byte interleaved mode. Every 10 bits are mapped to a
                                                                 two-byte symbol, with even bits mapped to the first byte, and odd bits
                                                                 mapped to the second byte, with zero padding in the upper three bits of each
                                                                 byte. Can only be used when [MOD_ORDER] = 0xA.

                                                                 _ 0x3 = Two-byte consecutive mode. Every 10 bits are mapped to a
                                                                 two-byte symbol, with the first five bits mapped to the first byte, and the second five bits
                                                                 mapped to the second byte, with zero padding in the upper three bits of each
                                                                 byte. Can only be used when [MOD_ORDER] = 0xA. */
        uint64_t hd_data_order         : 3;  /**< [ 85: 83] Bit 19:
                                                                   0: DATA_BIT_MSB_FIRST.
                                                                   1: DATA_BIT_LSB_FIRST.
                                                                   Refer to [R1] for data packing details.
                                                                   For normal usage, it shall be set to DATA_BIT_MSB_FIRST.
                                                                 Bits 21:20:
                                                                   0x0: DATA_BYTE_ORDER_MODE_0.
                                                                   0x1: DATA_BYTE_ORDER_MODE_1.
                                                                   0x2: DATA_BYTE_ORDER_MODE_2.
                                                                   Refer to [R1] for data packing details.
                                                                   For normal usage, it shall be set to DATA_BYTE_ORDER_MODE_0. */
        uint64_t bypass_reenc_rm       : 1;  /**< [ 82: 82] 0: Rate matching is performed on re-encoded hard bits. The core generates Er bits for r-th CB.
                                                                 1: Rate matching is bypassed. */
        uint64_t generate_reenc        : 1;  /**< [ 81: 81] 1: Re-encoding is enabled.
                                                                 0: Re-encoding is bypassed. */
        uint64_t bypass_so_rm          : 1;  /**< [ 80: 80] Bypass the rate matching on soft output. */
        uint64_t generate_so           : 1;  /**< [ 79: 79] 0: Soft bit output generation is bypassed. Only hard decision outputs are generated and available.
                                                                 1: Soft bit output generation is enabled.
                                                                 If soft output generation is enabled, it will generate "num_llr" soft outputs. */
        uint64_t bypass_bit_intlv      : 1;  /**< [ 78: 78] 0 : Perform bit-level interleaving.
                                                                 1 : Bypass bit-level interleaving (applies on both Rx and soft-out streams). */
        uint64_t bypass_decoder        : 1;  /**< [ 77: 77] 0: LDPC decoding is enabled.
                                                                 1: LDPC decoding of the combined vector is bypassed.
                                                                 This mode can optionally be used for performing only HARQ combining,
                                                                 where the decoder only performs HARQ combining and generates HARQ output. */
        uint64_t bypass_tb_crc_contrib : 1;  /**< [ 76: 76] Bypass TB CRC contribution calculation from each CB.
                                                                 When bypassed, no TB CRC contribution words are appended to hard decision output. */
        uint64_t bypass_tb_crc         : 1;  /**< [ 75: 75] Bypass TB CRC calculation.
                                                                 When not bypassed, TB CRC is calculated and stripped off from hard output. */
        uint64_t tb_crc_select         : 2;  /**< [ 74: 73] CRC polynomial used for the calculation of TB CRC and CB level TB CRC contribution.
                                                                 0x0 : Reserved.
                                                                 0x1 : CRC-16.
                                                                 0x2 : CRC-24A.
                                                                 0x3 : Reserved. */
        uint64_t cb_crc_select         : 1;  /**< [ 72: 72] CB CRC polynomial select.
                                                                 0 : bypass.
                                                                 1 : gCRC24B. */
        uint64_t negstop_en            : 1;  /**< [ 71: 71] Activates the negative stopping mechanism, by which uncorrectable frames are discarded early. */
        uint64_t negstop_it            : 7;  /**< [ 70: 64] Sets the level at which iteration the negative stopping condition is evaluated.
                                                                 Valid range [0x1, 0x7F]. */
#else /* Word 1 - Little Endian */
        uint64_t negstop_it            : 7;  /**< [ 70: 64] Sets the level at which iteration the negative stopping condition is evaluated.
                                                                 Valid range [0x1, 0x7F]. */
        uint64_t negstop_en            : 1;  /**< [ 71: 71] Activates the negative stopping mechanism, by which uncorrectable frames are discarded early. */
        uint64_t cb_crc_select         : 1;  /**< [ 72: 72] CB CRC polynomial select.
                                                                 0 : bypass.
                                                                 1 : gCRC24B. */
        uint64_t tb_crc_select         : 2;  /**< [ 74: 73] CRC polynomial used for the calculation of TB CRC and CB level TB CRC contribution.
                                                                 0x0 : Reserved.
                                                                 0x1 : CRC-16.
                                                                 0x2 : CRC-24A.
                                                                 0x3 : Reserved. */
        uint64_t bypass_tb_crc         : 1;  /**< [ 75: 75] Bypass TB CRC calculation.
                                                                 When not bypassed, TB CRC is calculated and stripped off from hard output. */
        uint64_t bypass_tb_crc_contrib : 1;  /**< [ 76: 76] Bypass TB CRC contribution calculation from each CB.
                                                                 When bypassed, no TB CRC contribution words are appended to hard decision output. */
        uint64_t bypass_decoder        : 1;  /**< [ 77: 77] 0: LDPC decoding is enabled.
                                                                 1: LDPC decoding of the combined vector is bypassed.
                                                                 This mode can optionally be used for performing only HARQ combining,
                                                                 where the decoder only performs HARQ combining and generates HARQ output. */
        uint64_t bypass_bit_intlv      : 1;  /**< [ 78: 78] 0 : Perform bit-level interleaving.
                                                                 1 : Bypass bit-level interleaving (applies on both Rx and soft-out streams). */
        uint64_t generate_so           : 1;  /**< [ 79: 79] 0: Soft bit output generation is bypassed. Only hard decision outputs are generated and available.
                                                                 1: Soft bit output generation is enabled.
                                                                 If soft output generation is enabled, it will generate "num_llr" soft outputs. */
        uint64_t bypass_so_rm          : 1;  /**< [ 80: 80] Bypass the rate matching on soft output. */
        uint64_t generate_reenc        : 1;  /**< [ 81: 81] 1: Re-encoding is enabled.
                                                                 0: Re-encoding is bypassed. */
        uint64_t bypass_reenc_rm       : 1;  /**< [ 82: 82] 0: Rate matching is performed on re-encoded hard bits. The core generates Er bits for r-th CB.
                                                                 1: Rate matching is bypassed. */
        uint64_t hd_data_order         : 3;  /**< [ 85: 83] Bit 19:
                                                                   0: DATA_BIT_MSB_FIRST.
                                                                   1: DATA_BIT_LSB_FIRST.
                                                                   Refer to [R1] for data packing details.
                                                                   For normal usage, it shall be set to DATA_BIT_MSB_FIRST.
                                                                 Bits 21:20:
                                                                   0x0: DATA_BYTE_ORDER_MODE_0.
                                                                   0x1: DATA_BYTE_ORDER_MODE_1.
                                                                   0x2: DATA_BYTE_ORDER_MODE_2.
                                                                   Refer to [R1] for data packing details.
                                                                   For normal usage, it shall be set to DATA_BYTE_ORDER_MODE_0. */
        uint64_t reenc_symb_byte_aligned : 2;/**< [ 87: 86] Alignment mode.

                                                                 _ 0x0 = No alignment. Data bits are written out back to back.

                                                                 _ 0x1 = Byte alignment. Every [MOD_ORDER] bits are mapped to one byte
                                                                 in little endian format, with zero padding in the upper bits in each
                                                                 byte. Can only be used when [MOD_ORDER] \< 0xA.

                                                                 _ 0x2 = Two-byte interleaved mode. Every 10 bits are mapped to a
                                                                 two-byte symbol, with even bits mapped to the first byte, and odd bits
                                                                 mapped to the second byte, with zero padding in the upper three bits of each
                                                                 byte. Can only be used when [MOD_ORDER] = 0xA.

                                                                 _ 0x3 = Two-byte consecutive mode. Every 10 bits are mapped to a
                                                                 two-byte symbol, with the first five bits mapped to the first byte, and the second five bits
                                                                 mapped to the second byte, with zero padding in the upper three bits of each
                                                                 byte. Can only be used when [MOD_ORDER] = 0xA. */
        uint64_t reenc_qm_with_crc     : 1;  /**< [ 88: 88] 1 : Add 1-bit CB CRC result to each set of [MOD_ORDER] bits output.
                                                                 0 : No CRC addition.
                                                                 This feature can be enabled only when [REENC_SYMB_SYMB_ALIGNED] = 0x0. */
        uint64_t reenc_data_order      : 3;  /**< [ 91: 89] Bit 25:
                                                                   0: DATA_BIT_MSB_FIRST.
                                                                   1: DATA_BIT_LSB_FIRST.
                                                                   Refer to [R1] for data packing details.
                                                                 Bits 26:27:
                                                                   0x0: DATA_BYTE_ORDER_MODE_0.
                                                                   0x1: DATA_BYTE_ORDER_MODE_1.
                                                                   0x2: DATA_BYTE_ORDER_MODE_2.
                                                                   Refer to [R1] for data packing details.
                                                                   For normal usage, it shall be set to DATA_BYTE_ORDER_MODE_0. */
        uint64_t hcin_en               : 1;  /**< [ 92: 92] 0: Only input LLRs are expected to be received. HARQ is either disabled or this
                                                                 is the first transmission.
                                                                 1: HARQ input is enabled. The core expects to receive HCin stream once all input LLRs are received. */
        uint64_t hcin_llr_decomp_mode  : 3;  /**< [ 95: 93] HARQ LLR input decompression scheme.
                                                                 0x0: bypass (do nothing).
                                                                 0x1: Sign extension (6 to 8 bits).
                                                                 0x2: Left shift 1 bit and sign extend(6 to 8 bits).
                                                                 0x3: Left shift 2 bits(6 to 8 bits).
                                                                 0x4: Reverse the operation of round(log2)quantization (4 bits to 8 bits).
                                                                 Valid range [0x0, 0x4]. */
        uint64_t hcout_en              : 1;  /**< [ 96: 96] 1: HCout vector is released after HARQ combining.
                                                                 0: No HCout vector is released. HARQ combining can still be enabled.
                                                                 This feature can optionally be used when decoding the last transmission. */
        uint64_t hcout_llr_comp_mode   : 3;  /**< [ 99: 97] HARQ LLR output compression scheme.
                                                                 0x0: Bypass (do nothing).
                                                                 0x1: Saturate to 6 bits (8 to 6 bits).
                                                                 0x2: Right shift 1 bit with rounding and saturate to 6 bits (8 to 6 bits).
                                                                 0x3: Right shift 2 bits with rounding (8 to 6 bits).
                                                                 0x4: Round(log2)quantization (8 to 4 bits).
                                                                 Valid range [0x0, 0x4]. */
        uint64_t tb_tx_bit_size        : 24; /**< [123:100] Total number of input LLR values across all CBs to be used by the task.
                                                                 These are LLRs excluding the ones dropped at the beginning/end and the tagged values.
                                                                 Valid range [0x1, 0x14CB80]. */
        uint64_t bypass_monitor_words  : 1;  /**< [124:124] 0: All 13 monitoring words are appended to HD output.
                                                                 1: Only first 2 monitoring words are appended to HD output.
                                                                 Following TB CRC contribution words are sent or not depending on the flag [BYPASS_TB_CRC_CONTRIB]. */
        uint64_t reenc_qm_with_synd    : 1;  /**< [125:125] Reserved.
                                                                 Internal:
                                                                 When set to 1, attach the syndrome bit to each set of [MOD_ORDER] bits,
                                                                 where a value of 1 indicates a passing syndrome and a value of
                                                                 0 indicates a failing syndrome.
                                                                 Not possible to have this enabled when [REENC_SYMB_BYTE_ALIGNED] \> 0x0,
                                                                 or if [REENC_QM_WITH_CRC] is enabled. */
        uint64_t reserved_126_127      : 2;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_184_191      : 8;
        uint64_t k0                    : 16; /**< [183:168] k0 value representing offset of Rx data in unpruned circular buffer as defined
                                                                 in Table 5.4.2.1-2 in 38.212.  Must be less than [NCB_SIZE]. */
        uint64_t gain_h                : 8;  /**< [167:160] Scaling factor for HARQ input LLRs in HARQ combining (also called GH in this document).
                                                                 Valid range [0x0, 0xFF]. */
        uint64_t gain_i                : 8;  /**< [159:152] Scaling factor for Rx input LLRs in HARQ combining (also called GI in this document).
                                                                 Valid range [0x0, 0xFF]. */
        uint64_t hcout_llr_cnv         : 4;  /**< [151:148] Scaling applied to LLR samples between HARQ combining and HCout release.
                                                                 Samples have their amplitude right-shifted by [HCOUT_LLR_CNV] bits.
                                                                 Valid range [0x0, 0x8]. */
        uint64_t dec_llr_cnv           : 4;  /**< [147:144] Scaling applied to LLR samples between HARQ combining and LDPC decoding.
                                                                 Samples have their amplitude right-shifted by [DEC_LLR_CNV] bits.
                                                                 Valid range [0x0, 0x8]. */
        uint64_t ncb_size              : 16; /**< [143:128] Soft buffer size of each code block as defined in section 5.4.2.1 in 38.212. Maximum value 0x6300. */
#else /* Word 2 - Little Endian */
        uint64_t ncb_size              : 16; /**< [143:128] Soft buffer size of each code block as defined in section 5.4.2.1 in 38.212. Maximum value 0x6300. */
        uint64_t dec_llr_cnv           : 4;  /**< [147:144] Scaling applied to LLR samples between HARQ combining and LDPC decoding.
                                                                 Samples have their amplitude right-shifted by [DEC_LLR_CNV] bits.
                                                                 Valid range [0x0, 0x8]. */
        uint64_t hcout_llr_cnv         : 4;  /**< [151:148] Scaling applied to LLR samples between HARQ combining and HCout release.
                                                                 Samples have their amplitude right-shifted by [HCOUT_LLR_CNV] bits.
                                                                 Valid range [0x0, 0x8]. */
        uint64_t gain_i                : 8;  /**< [159:152] Scaling factor for Rx input LLRs in HARQ combining (also called GI in this document).
                                                                 Valid range [0x0, 0xFF]. */
        uint64_t gain_h                : 8;  /**< [167:160] Scaling factor for HARQ input LLRs in HARQ combining (also called GH in this document).
                                                                 Valid range [0x0, 0xFF]. */
        uint64_t k0                    : 16; /**< [183:168] k0 value representing offset of Rx data in unpruned circular buffer as defined
                                                                 in Table 5.4.2.1-2 in 38.212.  Must be less than [NCB_SIZE]. */
        uint64_t reserved_184_191      : 8;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_254_255      : 2;
        uint64_t preproc_p0_csi2_len2  : 19; /**< [253:235] Size of burst 2, CSI2 part0. Valid range is [0x0, 0x671FF]. */
        uint64_t preproc_p0_csi2_len1  : 19; /**< [234:216] Size of burst 1, CSI2 part0. Valid range is [0x0, 0x671FF]. */
        uint64_t preproc_p0_csi2_len0  : 19; /**< [215:197] Size of burst 0, CSI2 part0. Valid range is [0x0, 0x671FF]. */
        uint64_t reserved_194_196      : 3;
        uint64_t preproc_enable        : 1;  /**< [193:193] 0 : disable pre-processor.
                                                                 1 : enable pre-processor. */
        uint64_t preproc_mode          : 1;  /**< [192:192] Flag indicating the mode of LLR pre-processing block
                                                                 0 : Keep CSI2 LLRs.
                                                                 1 : Keep data LLR. */
#else /* Word 3 - Little Endian */
        uint64_t preproc_mode          : 1;  /**< [192:192] Flag indicating the mode of LLR pre-processing block
                                                                 0 : Keep CSI2 LLRs.
                                                                 1 : Keep data LLR. */
        uint64_t preproc_enable        : 1;  /**< [193:193] 0 : disable pre-processor.
                                                                 1 : enable pre-processor. */
        uint64_t reserved_194_196      : 3;
        uint64_t preproc_p0_csi2_len0  : 19; /**< [215:197] Size of burst 0, CSI2 part0. Valid range is [0x0, 0x671FF]. */
        uint64_t preproc_p0_csi2_len1  : 19; /**< [234:216] Size of burst 1, CSI2 part0. Valid range is [0x0, 0x671FF]. */
        uint64_t preproc_p0_csi2_len2  : 19; /**< [253:235] Size of burst 2, CSI2 part0. Valid range is [0x0, 0x671FF]. */
        uint64_t reserved_254_255      : 2;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_319          : 1;
        uint64_t preproc_csi2_repeat_burst_size : 6;/**< [318:313] Burst size of CSI2 LLRs in each repeat of both part 0 and part 1.
                                                                 Valid range : {0x1, 0x2, 0x3, 0x4, 0x6, 0x8, 0xA, 0xC, 0x10, 0x12, 0x14, 0x18, 0x1E, 0x20, 0x28} */
        uint64_t preproc_p1_csi2_len2  : 19; /**< [312:294] Size of burst 2, CSI2 part1. Valid range is [0x0, 0x671FF]. */
        uint64_t preproc_p1_csi2_len1  : 19; /**< [293:275] Size of burst 1, CSI2 part1. Valid range is [0x0, 0x671FF]. */
        uint64_t preproc_p1_csi2_len0  : 19; /**< [274:256] Size of burst 0, CSI2 part1. Valid range is [0x0, 0x671FF]. */
#else /* Word 4 - Little Endian */
        uint64_t preproc_p1_csi2_len0  : 19; /**< [274:256] Size of burst 0, CSI2 part1. Valid range is [0x0, 0x671FF]. */
        uint64_t preproc_p1_csi2_len1  : 19; /**< [293:275] Size of burst 1, CSI2 part1. Valid range is [0x0, 0x671FF]. */
        uint64_t preproc_p1_csi2_len2  : 19; /**< [312:294] Size of burst 2, CSI2 part1. Valid range is [0x0, 0x671FF]. */
        uint64_t preproc_csi2_repeat_burst_size : 6;/**< [318:313] Burst size of CSI2 LLRs in each repeat of both part 0 and part 1.
                                                                 Valid range : {0x1, 0x2, 0x3, 0x4, 0x6, 0x8, 0xA, 0xC, 0x10, 0x12, 0x14, 0x18, 0x1E, 0x20, 0x28} */
        uint64_t reserved_319          : 1;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_382_383      : 2;
        uint64_t preproc_p0_num_repeat : 11; /**< [381:371] Number of periodic repetitions in part 0. Valid range is [0x0, 0x7FF]. */
        uint64_t preproc_p1_data_len0  : 17; /**< [370:354] Size of burst 0, data part 1. Valid range is [0x0, 0x19C7F]. */
        uint64_t preproc_p0_data_len1  : 17; /**< [353:337] Size of burst 1, data part 0. Valid range is [0x0, 0x19C7F]. */
        uint64_t preproc_p0_data_len0  : 17; /**< [336:320] Size of burst 0, data part 0. Valid range is [0x0, 0x19C7F]. */
#else /* Word 5 - Little Endian */
        uint64_t preproc_p0_data_len0  : 17; /**< [336:320] Size of burst 0, data part 0. Valid range is [0x0, 0x19C7F]. */
        uint64_t preproc_p0_data_len1  : 17; /**< [353:337] Size of burst 1, data part 0. Valid range is [0x0, 0x19C7F]. */
        uint64_t preproc_p1_data_len0  : 17; /**< [370:354] Size of burst 0, data part 1. Valid range is [0x0, 0x19C7F]. */
        uint64_t preproc_p0_num_repeat : 11; /**< [381:371] Number of periodic repetitions in part 0. Valid range is [0x0, 0x7FF]. */
        uint64_t reserved_382_383      : 2;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_444_447      : 4;
        uint64_t preproc_p1_num_repeat : 11; /**< [443:433] Number of periodic repetitions in part 1. Valid range is [0x0, 0x7FF]. */
        uint64_t preproc_p1_csi2_repeat_period : 16;/**< [432:417] Periodicity of Repeated CSI2 LLRs followed by part 1 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents number of LLRs of each period. Valid range is [0x0, 0xCE40]. */
        uint64_t preproc_p0_csi2_repeat_period : 16;/**< [416:401] Periodicity of Repeated CSI2 LLRs followed by part 0 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents number of LLRs of each period. Valid range is [0x0, 0xCE40]. */
        uint64_t preproc_p1_data_len1  : 17; /**< [400:384] Size of burst 1, data part 1. Valid range is [0x0, 0x19C7F]. */
#else /* Word 6 - Little Endian */
        uint64_t preproc_p1_data_len1  : 17; /**< [400:384] Size of burst 1, data part 1. Valid range is [0x0, 0x19C7F]. */
        uint64_t preproc_p0_csi2_repeat_period : 16;/**< [416:401] Periodicity of Repeated CSI2 LLRs followed by part 0 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents number of LLRs of each period. Valid range is [0x0, 0xCE40]. */
        uint64_t preproc_p1_csi2_repeat_period : 16;/**< [432:417] Periodicity of Repeated CSI2 LLRs followed by part 1 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents number of LLRs of each period. Valid range is [0x0, 0xCE40]. */
        uint64_t preproc_p1_num_repeat : 11; /**< [443:433] Number of periodic repetitions in part 1. Valid range is [0x0, 0x7FF]. */
        uint64_t reserved_444_447      : 4;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t preproc_num_rd_dma_words_p1 : 32;/**< [511:480] Number of read DMA words for part 1. Valid range is [0x0, 0x2998].
                                                                 The read DMA parameters must satisfy the constraint
                                                                 [PREPROC_NUM_RD_DMA_WORDS_P0] + [PREPROC_NUM_RD_DMA_WORDS_P1] =
                                                                 [NUM_RD0_DMA_WORDS] . */
        uint64_t preproc_num_rd_dma_words_p0 : 32;/**< [479:448] Number of read DMA words for part 0. Valid range is [0x0, 0x2998].
                                                                 The read DMA parameters must satisfy the constraint
                                                                 [PREPROC_NUM_RD_DMA_WORDS_P0] + [PREPROC_NUM_RD_DMA_WORDS_P1] =
                                                                 [NUM_RD0_DMA_WORDS] . */
#else /* Word 7 - Little Endian */
        uint64_t preproc_num_rd_dma_words_p0 : 32;/**< [479:448] Number of read DMA words for part 0. Valid range is [0x0, 0x2998].
                                                                 The read DMA parameters must satisfy the constraint
                                                                 [PREPROC_NUM_RD_DMA_WORDS_P0] + [PREPROC_NUM_RD_DMA_WORDS_P1] =
                                                                 [NUM_RD0_DMA_WORDS] . */
        uint64_t preproc_num_rd_dma_words_p1 : 32;/**< [511:480] Number of read DMA words for part 1. Valid range is [0x0, 0x2998].
                                                                 The read DMA parameters must satisfy the constraint
                                                                 [PREPROC_NUM_RD_DMA_WORDS_P0] + [PREPROC_NUM_RD_DMA_WORDS_P1] =
                                                                 [NUM_RD0_DMA_WORDS] . */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t num_rd1_dma_words     : 32; /**< [575:544] Number of 128-bit words read from Port1 input DMA. Valid range is [0x0, 0x3AC80]. */
        uint64_t num_rd0_dma_words     : 32; /**< [543:512] Number of 128-bit words read from Port0 input DMA. Valid range is [0x0, 0x2998]. */
#else /* Word 8 - Little Endian */
        uint64_t num_rd0_dma_words     : 32; /**< [543:512] Number of 128-bit words read from Port0 input DMA. Valid range is [0x0, 0x2998]. */
        uint64_t num_rd1_dma_words     : 32; /**< [575:544] Number of 128-bit words read from Port1 input DMA. Valid range is [0x0, 0x3AC80]. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t num_wr1_dma_words     : 32; /**< [639:608] Number of 128-bit words written to Port1 output DMA. Valid range is [0x0, 0x3AC80]. */
        uint64_t num_wr0_dma_words     : 32; /**< [607:576] Number of 128-bit words written to Port0 output DMA. Valid range is [0x0, 0x3AC80]. */
#else /* Word 9 - Little Endian */
        uint64_t num_wr0_dma_words     : 32; /**< [607:576] Number of 128-bit words written to Port0 output DMA. Valid range is [0x0, 0x3AC80]. */
        uint64_t num_wr1_dma_words     : 32; /**< [639:608] Number of 128-bit words written to Port1 output DMA. Valid range is [0x0, 0x3AC80]. */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t num_wr3_dma_words     : 32; /**< [703:672] Number of 64-bit words written to Port3 output DMA. Valid range is [0x0, 0xEB20]. */
        uint64_t num_wr2_dma_words     : 32; /**< [671:640] Number of 64-bit words written to Port2 output DMA. Valid range is [0x0, 0x4E60]. */
#else /* Word 10 - Little Endian */
        uint64_t num_wr2_dma_words     : 32; /**< [671:640] Number of 64-bit words written to Port2 output DMA. Valid range is [0x0, 0x4E60]. */
        uint64_t num_wr3_dma_words     : 32; /**< [703:672] Number of 64-bit words written to Port3 output DMA. Valid range is [0x0, 0xEB20]. */
#endif /* Word 10 - End */
    } s;
    /* struct cavm_ldec_task_cfg_s_s cn; */
};

/**
 * Register (RSL) ldec#_ab#_control
 *
 * LDEC Control Register
 */
union cavm_ldecx_abx_control
{
    uint64_t u;
    struct cavm_ldecx_abx_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jobid2                : 16; /**< [ 63: 48](R/W/H) Job ID for slot 2. */
        uint64_t jobid1                : 16; /**< [ 47: 32](R/W/H) Job ID for slot 1. */
        uint64_t jobid0                : 16; /**< [ 31: 16](R/W/H) Job ID for slot 0. */
        uint64_t reserved_3_15         : 13;
        uint64_t start2                : 1;  /**< [  2:  2](R/W/H) Start processing job in slot 2. */
        uint64_t start1                : 1;  /**< [  1:  1](R/W/H) Start processing job in slot 1. */
        uint64_t start0                : 1;  /**< [  0:  0](R/W/H) Start processing job in slot 0. */
#else /* Word 0 - Little Endian */
        uint64_t start0                : 1;  /**< [  0:  0](R/W/H) Start processing job in slot 0. */
        uint64_t start1                : 1;  /**< [  1:  1](R/W/H) Start processing job in slot 1. */
        uint64_t start2                : 1;  /**< [  2:  2](R/W/H) Start processing job in slot 2. */
        uint64_t reserved_3_15         : 13;
        uint64_t jobid0                : 16; /**< [ 31: 16](R/W/H) Job ID for slot 0. */
        uint64_t jobid1                : 16; /**< [ 47: 32](R/W/H) Job ID for slot 1. */
        uint64_t jobid2                : 16; /**< [ 63: 48](R/W/H) Job ID for slot 2. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_control_s cn; */
};
typedef union cavm_ldecx_abx_control cavm_ldecx_abx_control_t;

static inline uint64_t CAVM_LDECX_ABX_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_CONTROL(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043680000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043680000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_CONTROL", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_CONTROL(a,b) cavm_ldecx_abx_control_t
#define bustype_CAVM_LDECX_ABX_CONTROL(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_CONTROL(a,b) "LDECX_ABX_CONTROL"
#define busnum_CAVM_LDECX_ABX_CONTROL(a,b) (a)
#define arguments_CAVM_LDECX_ABX_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_eco
 *
 * INTERNAL: LDEC ECO Register
 */
union cavm_ldecx_abx_eco
{
    uint64_t u;
    struct cavm_ldecx_abx_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_eco_s cn; */
};
typedef union cavm_ldecx_abx_eco cavm_ldecx_abx_eco_t;

static inline uint64_t CAVM_LDECX_ABX_ECO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_ECO(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043680008ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043680008ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_ECO", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_ECO(a,b) cavm_ldecx_abx_eco_t
#define bustype_CAVM_LDECX_ABX_ECO(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_ECO(a,b) "LDECX_ABX_ECO"
#define busnum_CAVM_LDECX_ABX_ECO(a,b) (a)
#define arguments_CAVM_LDECX_ABX_ECO(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_error_enable0
 *
 * LDEC Error Enable 0 Register
 * This register enables error reporting for read overflow/underflow errors.
 */
union cavm_ldecx_abx_error_enable0
{
    uint64_t u;
    struct cavm_ldecx_abx_error_enable0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t rp1_of_en             : 1;  /**< [  5:  5](R/W) Read port 1 overflow enable. */
        uint64_t rp0_of_en             : 1;  /**< [  4:  4](R/W) Read port 0 overflow enable. */
        uint64_t reserved_2_3          : 2;
        uint64_t rp1_uf_en             : 1;  /**< [  1:  1](R/W) Read Port 1 underflow enable. */
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W) Read Port 0 underflow enable. */
#else /* Word 0 - Little Endian */
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W) Read Port 0 underflow enable. */
        uint64_t rp1_uf_en             : 1;  /**< [  1:  1](R/W) Read Port 1 underflow enable. */
        uint64_t reserved_2_3          : 2;
        uint64_t rp0_of_en             : 1;  /**< [  4:  4](R/W) Read port 0 overflow enable. */
        uint64_t rp1_of_en             : 1;  /**< [  5:  5](R/W) Read port 1 overflow enable. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_error_enable0_s cn; */
};
typedef union cavm_ldecx_abx_error_enable0 cavm_ldecx_abx_error_enable0_t;

static inline uint64_t CAVM_LDECX_ABX_ERROR_ENABLE0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_ERROR_ENABLE0(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043680040ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043680040ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_ERROR_ENABLE0", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_ERROR_ENABLE0(a,b) cavm_ldecx_abx_error_enable0_t
#define bustype_CAVM_LDECX_ABX_ERROR_ENABLE0(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_ERROR_ENABLE0(a,b) "LDECX_ABX_ERROR_ENABLE0"
#define busnum_CAVM_LDECX_ABX_ERROR_ENABLE0(a,b) (a)
#define arguments_CAVM_LDECX_ABX_ERROR_ENABLE0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_error_enable1
 *
 * LDEC Error Enable 1 Register
 * This register enables error reporting of ECC errors.
 */
union cavm_ldecx_abx_error_enable1
{
    uint64_t u;
    struct cavm_ldecx_abx_error_enable1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t jcfg2_ded_ecc         : 1;  /**< [  6:  6](R/W) Job configuration 2 double-bit ECC error enable. */
        uint64_t jcfg1_ded_ecc         : 1;  /**< [  5:  5](R/W) Job configuration 1 double-bit ECC error enable. */
        uint64_t jcfg0_ded_ecc         : 1;  /**< [  4:  4](R/W) Job configuration 0 double-bit ECC error enable. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t jcfg0_ded_ecc         : 1;  /**< [  4:  4](R/W) Job configuration 0 double-bit ECC error enable. */
        uint64_t jcfg1_ded_ecc         : 1;  /**< [  5:  5](R/W) Job configuration 1 double-bit ECC error enable. */
        uint64_t jcfg2_ded_ecc         : 1;  /**< [  6:  6](R/W) Job configuration 2 double-bit ECC error enable. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_error_enable1_s cn; */
};
typedef union cavm_ldecx_abx_error_enable1 cavm_ldecx_abx_error_enable1_t;

static inline uint64_t CAVM_LDECX_ABX_ERROR_ENABLE1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_ERROR_ENABLE1(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043680048ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043680048ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_ERROR_ENABLE1", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_ERROR_ENABLE1(a,b) cavm_ldecx_abx_error_enable1_t
#define bustype_CAVM_LDECX_ABX_ERROR_ENABLE1(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_ERROR_ENABLE1(a,b) "LDECX_ABX_ERROR_ENABLE1"
#define busnum_CAVM_LDECX_ABX_ERROR_ENABLE1(a,b) (a)
#define arguments_CAVM_LDECX_ABX_ERROR_ENABLE1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_error_source0
 *
 * LDEC Error Source 0 Register
 * This register indicates the source of read overflow/underflow errors.
 */
union cavm_ldecx_abx_error_source0
{
    uint64_t u;
    struct cavm_ldecx_abx_error_source0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t rp1_jid               : 16; /**< [ 47: 32](RO/H) Job ID of the job which reported the overflow/underflow error on read
                                                                 port 1. */
        uint64_t rp0_jid               : 16; /**< [ 31: 16](RO/H) Job ID of the job which reported the overflow/underflow error on read
                                                                 port 0. */
        uint64_t reserved_6_15         : 10;
        uint64_t rp1_of                : 1;  /**< [  5:  5](R/W1C/H) Read port 1 overflow. */
        uint64_t rp0_of                : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t reserved_2_3          : 2;
        uint64_t rp1_uf                : 1;  /**< [  1:  1](R/W1C/H) Read port 1 underflow. */
        uint64_t rp0_uf                : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
#else /* Word 0 - Little Endian */
        uint64_t rp0_uf                : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
        uint64_t rp1_uf                : 1;  /**< [  1:  1](R/W1C/H) Read port 1 underflow. */
        uint64_t reserved_2_3          : 2;
        uint64_t rp0_of                : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t rp1_of                : 1;  /**< [  5:  5](R/W1C/H) Read port 1 overflow. */
        uint64_t reserved_6_15         : 10;
        uint64_t rp0_jid               : 16; /**< [ 31: 16](RO/H) Job ID of the job which reported the overflow/underflow error on read
                                                                 port 0. */
        uint64_t rp1_jid               : 16; /**< [ 47: 32](RO/H) Job ID of the job which reported the overflow/underflow error on read
                                                                 port 1. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_error_source0_s cn; */
};
typedef union cavm_ldecx_abx_error_source0 cavm_ldecx_abx_error_source0_t;

static inline uint64_t CAVM_LDECX_ABX_ERROR_SOURCE0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_ERROR_SOURCE0(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043680030ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043680030ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_ERROR_SOURCE0", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_ERROR_SOURCE0(a,b) cavm_ldecx_abx_error_source0_t
#define bustype_CAVM_LDECX_ABX_ERROR_SOURCE0(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_ERROR_SOURCE0(a,b) "LDECX_ABX_ERROR_SOURCE0"
#define busnum_CAVM_LDECX_ABX_ERROR_SOURCE0(a,b) (a)
#define arguments_CAVM_LDECX_ABX_ERROR_SOURCE0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_error_source1
 *
 * LDEC Error Source 1 Register
 * This register reports the source of ECC errors.
 */
union cavm_ldecx_abx_error_source1
{
    uint64_t u;
    struct cavm_ldecx_abx_error_source1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t jcfg2_ded_ecc         : 1;  /**< [  6:  6](R/W1C/H) Job configuration 2 double-bit error detected. */
        uint64_t jcfg1_ded_ecc         : 1;  /**< [  5:  5](R/W1C/H) Job configuration 1 double-bit error detected. */
        uint64_t jcfg0_ded_ecc         : 1;  /**< [  4:  4](R/W1C/H) Job configuration 0 double-bit error detected. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t jcfg0_ded_ecc         : 1;  /**< [  4:  4](R/W1C/H) Job configuration 0 double-bit error detected. */
        uint64_t jcfg1_ded_ecc         : 1;  /**< [  5:  5](R/W1C/H) Job configuration 1 double-bit error detected. */
        uint64_t jcfg2_ded_ecc         : 1;  /**< [  6:  6](R/W1C/H) Job configuration 2 double-bit error detected. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_error_source1_s cn; */
};
typedef union cavm_ldecx_abx_error_source1 cavm_ldecx_abx_error_source1_t;

static inline uint64_t CAVM_LDECX_ABX_ERROR_SOURCE1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_ERROR_SOURCE1(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043680038ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043680038ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_ERROR_SOURCE1", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_ERROR_SOURCE1(a,b) cavm_ldecx_abx_error_source1_t
#define bustype_CAVM_LDECX_ABX_ERROR_SOURCE1(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_ERROR_SOURCE1(a,b) "LDECX_ABX_ERROR_SOURCE1"
#define busnum_CAVM_LDECX_ABX_ERROR_SOURCE1(a,b) (a)
#define arguments_CAVM_LDECX_ABX_ERROR_SOURCE1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_hab_jcfg0_ram#_data
 *
 * LDEC HAB Job Configuration 0 RAM Register
 * This register range stores the job configuration for slot 0.
 */
union cavm_ldecx_abx_hab_jcfg0_ramx_data
{
    uint64_t u;
    struct cavm_ldecx_abx_hab_jcfg0_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG0 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG0 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_hab_jcfg0_ramx_data_s cn; */
};
typedef union cavm_ldecx_abx_hab_jcfg0_ramx_data cavm_ldecx_abx_hab_jcfg0_ramx_data_t;

static inline uint64_t CAVM_LDECX_ABX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1) && (c<=511)))
        return 0x87e043682000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1) && (c<=511)))
        return 0x87e043682000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    __cavm_csr_fatal("LDECX_ABX_HAB_JCFG0_RAMX_DATA", 3, a, b, c, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) cavm_ldecx_abx_hab_jcfg0_ramx_data_t
#define bustype_CAVM_LDECX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) "LDECX_ABX_HAB_JCFG0_RAMX_DATA"
#define busnum_CAVM_LDECX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) (a)
#define arguments_CAVM_LDECX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) ldec#_ab#_hab_jcfg1_ram#_data
 *
 * LDEC HAB Job Configuration 1 RAM Register
 * This register range stores the job configuration for slot 1.
 */
union cavm_ldecx_abx_hab_jcfg1_ramx_data
{
    uint64_t u;
    struct cavm_ldecx_abx_hab_jcfg1_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG1 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG1 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_hab_jcfg1_ramx_data_s cn; */
};
typedef union cavm_ldecx_abx_hab_jcfg1_ramx_data cavm_ldecx_abx_hab_jcfg1_ramx_data_t;

static inline uint64_t CAVM_LDECX_ABX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1) && (c<=511)))
        return 0x87e043684000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1) && (c<=511)))
        return 0x87e043684000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    __cavm_csr_fatal("LDECX_ABX_HAB_JCFG1_RAMX_DATA", 3, a, b, c, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) cavm_ldecx_abx_hab_jcfg1_ramx_data_t
#define bustype_CAVM_LDECX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) "LDECX_ABX_HAB_JCFG1_RAMX_DATA"
#define busnum_CAVM_LDECX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) (a)
#define arguments_CAVM_LDECX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) ldec#_ab#_hab_jcfg2_ram#_data
 *
 * LDEC HAB Job Configuration 2 RAM Register
 * This register range stores the job configuration for slot 2.
 */
union cavm_ldecx_abx_hab_jcfg2_ramx_data
{
    uint64_t u;
    struct cavm_ldecx_abx_hab_jcfg2_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG2 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG2 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_hab_jcfg2_ramx_data_s cn; */
};
typedef union cavm_ldecx_abx_hab_jcfg2_ramx_data cavm_ldecx_abx_hab_jcfg2_ramx_data_t;

static inline uint64_t CAVM_LDECX_ABX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1) && (c<=511)))
        return 0x87e043686000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1) && (c<=511)))
        return 0x87e043686000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    __cavm_csr_fatal("LDECX_ABX_HAB_JCFG2_RAMX_DATA", 3, a, b, c, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) cavm_ldecx_abx_hab_jcfg2_ramx_data_t
#define bustype_CAVM_LDECX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) "LDECX_ABX_HAB_JCFG2_RAMX_DATA"
#define busnum_CAVM_LDECX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) (a)
#define arguments_CAVM_LDECX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) ldec#_ab#_scratch
 *
 * INTERNAL: Scratch Register
 *
 * Scratch register.
 */
union cavm_ldecx_abx_scratch
{
    uint64_t u;
    struct cavm_ldecx_abx_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_scratch_s cn; */
};
typedef union cavm_ldecx_abx_scratch cavm_ldecx_abx_scratch_t;

static inline uint64_t CAVM_LDECX_ABX_SCRATCH(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_SCRATCH(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043680080ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043680080ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_SCRATCH", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_SCRATCH(a,b) cavm_ldecx_abx_scratch_t
#define bustype_CAVM_LDECX_ABX_SCRATCH(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_SCRATCH(a,b) "LDECX_ABX_SCRATCH"
#define busnum_CAVM_LDECX_ABX_SCRATCH(a,b) (a)
#define arguments_CAVM_LDECX_ABX_SCRATCH(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_status
 *
 * LDEC Status Register
 */
union cavm_ldecx_abx_status
{
    uint64_t u;
    struct cavm_ldecx_abx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the LDEC HAB is ready to receive the next job. */
        uint64_t reserved_3            : 1;
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the LDEC HAB is ready to receive the next job. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_status_s cn; */
};
typedef union cavm_ldecx_abx_status cavm_ldecx_abx_status_t;

static inline uint64_t CAVM_LDECX_ABX_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_STATUS(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043680018ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043680018ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_STATUS", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_STATUS(a,b) cavm_ldecx_abx_status_t
#define bustype_CAVM_LDECX_ABX_STATUS(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_STATUS(a,b) "LDECX_ABX_STATUS"
#define busnum_CAVM_LDECX_ABX_STATUS(a,b) (a)
#define arguments_CAVM_LDECX_ABX_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_tc_config#
 *
 * INTERNAL: TC Task Config Registers
 *
 * TC task config registers.
 */
union cavm_ldecx_abx_tc_configx
{
    uint64_t u;
    struct cavm_ldecx_abx_tc_configx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_tc_configx_s cn; */
};
typedef union cavm_ldecx_abx_tc_configx cavm_ldecx_abx_tc_configx_t;

static inline uint64_t CAVM_LDECX_ABX_TC_CONFIGX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_TC_CONFIGX(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1) && (c<=7)))
        return 0x87e043681400ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x7);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1) && (c<=7)))
        return 0x87e043681400ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x7);
    __cavm_csr_fatal("LDECX_ABX_TC_CONFIGX", 3, a, b, c, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) cavm_ldecx_abx_tc_configx_t
#define bustype_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) "LDECX_ABX_TC_CONFIGX"
#define busnum_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) (a)
#define arguments_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) ldec#_ab#_tc_config_err_flags
 *
 * LDEC Task Configuration Error Flags Register
 * This register reports task configuration errors that occur when a
 * specified parameter value is outside the acceptable range.
 */
union cavm_ldecx_abx_tc_config_err_flags
{
    uint64_t u;
    struct cavm_ldecx_abx_tc_config_err_flags_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    struct cavm_ldecx_abx_tc_config_err_flags_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_31         : 32;
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_ldecx_abx_tc_config_err_flags cavm_ldecx_abx_tc_config_err_flags_t;

static inline uint64_t CAVM_LDECX_ABX_TC_CONFIG_ERR_FLAGS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_TC_CONFIG_ERR_FLAGS(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043681040ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043681040ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_TC_CONFIG_ERR_FLAGS", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_CONFIG_ERR_FLAGS(a,b) cavm_ldecx_abx_tc_config_err_flags_t
#define bustype_CAVM_LDECX_ABX_TC_CONFIG_ERR_FLAGS(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_CONFIG_ERR_FLAGS(a,b) "LDECX_ABX_TC_CONFIG_ERR_FLAGS"
#define busnum_CAVM_LDECX_ABX_TC_CONFIG_ERR_FLAGS(a,b) (a)
#define arguments_CAVM_LDECX_ABX_TC_CONFIG_ERR_FLAGS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_tc_control
 *
 * LDEC Decoder Control Register
 * This register configures the LDEC internal decoder core.
 */
union cavm_ldecx_abx_tc_control
{
    uint64_t u;
    struct cavm_ldecx_abx_tc_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) Decoder core static control inputs.
                                                                 [0] = clock gating disable.
                                                                 [1] = configuration check disable.
                                                                 [2] = wait until the core is idle before accepting the next task
                                                                       (degrades the throughput).
                                                                 [3] = wait until the core is idle before accepting the next task
                                                                       in case of changing phy_mode (degrades the throughput).
                                                                 [4] = wait until the core is idle before accepting the next task
                                                                       in case of changing channel_mode (degrades the throughput). */
#else /* Word 0 - Little Endian */
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) Decoder core static control inputs.
                                                                 [0] = clock gating disable.
                                                                 [1] = configuration check disable.
                                                                 [2] = wait until the core is idle before accepting the next task
                                                                       (degrades the throughput).
                                                                 [3] = wait until the core is idle before accepting the next task
                                                                       in case of changing phy_mode (degrades the throughput).
                                                                 [4] = wait until the core is idle before accepting the next task
                                                                       in case of changing channel_mode (degrades the throughput). */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_tc_control_s cn; */
};
typedef union cavm_ldecx_abx_tc_control cavm_ldecx_abx_tc_control_t;

static inline uint64_t CAVM_LDECX_ABX_TC_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_TC_CONTROL(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043681010ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043681010ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_TC_CONTROL", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_CONTROL(a,b) cavm_ldecx_abx_tc_control_t
#define bustype_CAVM_LDECX_ABX_TC_CONTROL(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_CONTROL(a,b) "LDECX_ABX_TC_CONTROL"
#define busnum_CAVM_LDECX_ABX_TC_CONTROL(a,b) (a)
#define arguments_CAVM_LDECX_ABX_TC_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_tc_error
 *
 * LDEC Decoder Error Register
 * This register reports various error conditions.
 *
 * All errors reported in this register are reported as FATAL errors, and the
 * MHBW registers can be inspected to determine the job tag(s) associated with
 * the error(s).
 */
union cavm_ldecx_abx_tc_error
{
    uint64_t u;
    struct cavm_ldecx_abx_tc_error_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t inv_cfg               : 1;  /**< [  8:  8](R/W1C/H) Invalid task configuration -- aborted job. */
        uint64_t reserved_4_7          : 4;
        uint64_t ign_read              : 1;  /**< [  3:  3](R/W1C/H) Ignored a read access while another read was in process. */
        uint64_t inv_read              : 1;  /**< [  2:  2](R/W1C/H) Invalid read access to an out-of-range address. */
        uint64_t inv_write             : 1;  /**< [  1:  1](R/W1C/H) Invalid write access to an out-of-range address. */
        uint64_t inv_start             : 1;  /**< [  0:  0](R/W1C/H) Invalid task start. */
#else /* Word 0 - Little Endian */
        uint64_t inv_start             : 1;  /**< [  0:  0](R/W1C/H) Invalid task start. */
        uint64_t inv_write             : 1;  /**< [  1:  1](R/W1C/H) Invalid write access to an out-of-range address. */
        uint64_t inv_read              : 1;  /**< [  2:  2](R/W1C/H) Invalid read access to an out-of-range address. */
        uint64_t ign_read              : 1;  /**< [  3:  3](R/W1C/H) Ignored a read access while another read was in process. */
        uint64_t reserved_4_7          : 4;
        uint64_t inv_cfg               : 1;  /**< [  8:  8](R/W1C/H) Invalid task configuration -- aborted job. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_tc_error_s cn; */
};
typedef union cavm_ldecx_abx_tc_error cavm_ldecx_abx_tc_error_t;

static inline uint64_t CAVM_LDECX_ABX_TC_ERROR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_TC_ERROR(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043681038ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043681038ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_TC_ERROR", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_ERROR(a,b) cavm_ldecx_abx_tc_error_t
#define bustype_CAVM_LDECX_ABX_TC_ERROR(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_ERROR(a,b) "LDECX_ABX_TC_ERROR"
#define busnum_CAVM_LDECX_ABX_TC_ERROR(a,b) (a)
#define arguments_CAVM_LDECX_ABX_TC_ERROR(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_tc_error_mask
 *
 * LDEC Decoder Core Error Mask Register
 * This register enables internal decoder errors. Errors reported in
 * LDEC()_AB()_TC_ERROR will generate an error signal only when the
 * corresponding bit is set in LDEC()_AB()_TC_ERROR_MASK[ERR_MASK].
 */
union cavm_ldecx_abx_tc_error_mask
{
    uint64_t u;
    struct cavm_ldecx_abx_tc_error_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
#else /* Word 0 - Little Endian */
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_tc_error_mask_s cn; */
};
typedef union cavm_ldecx_abx_tc_error_mask cavm_ldecx_abx_tc_error_mask_t;

static inline uint64_t CAVM_LDECX_ABX_TC_ERROR_MASK(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_TC_ERROR_MASK(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043681030ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043681030ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_TC_ERROR_MASK", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_ERROR_MASK(a,b) cavm_ldecx_abx_tc_error_mask_t
#define bustype_CAVM_LDECX_ABX_TC_ERROR_MASK(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_ERROR_MASK(a,b) "LDECX_ABX_TC_ERROR_MASK"
#define busnum_CAVM_LDECX_ABX_TC_ERROR_MASK(a,b) (a)
#define arguments_CAVM_LDECX_ABX_TC_ERROR_MASK(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_tc_main_reset
 *
 * LDEC Decoder Reset Register
 * Internal decoder core reset register.
 */
union cavm_ldecx_abx_tc_main_reset
{
    uint64_t u;
    struct cavm_ldecx_abx_tc_main_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Any write to this register will reset the internal decoder core. */
#else /* Word 0 - Little Endian */
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Any write to this register will reset the internal decoder core. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_tc_main_reset_s cn; */
};
typedef union cavm_ldecx_abx_tc_main_reset cavm_ldecx_abx_tc_main_reset_t;

static inline uint64_t CAVM_LDECX_ABX_TC_MAIN_RESET(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_TC_MAIN_RESET(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043681000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043681000ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_TC_MAIN_RESET", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_MAIN_RESET(a,b) cavm_ldecx_abx_tc_main_reset_t
#define bustype_CAVM_LDECX_ABX_TC_MAIN_RESET(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_MAIN_RESET(a,b) "LDECX_ABX_TC_MAIN_RESET"
#define busnum_CAVM_LDECX_ABX_TC_MAIN_RESET(a,b) (a)
#define arguments_CAVM_LDECX_ABX_TC_MAIN_RESET(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_tc_main_start
 *
 * INTERNAL: TC Start Register
 *
 * TC start register.
 */
union cavm_ldecx_abx_tc_main_start
{
    uint64_t u;
    struct cavm_ldecx_abx_tc_main_start_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
#else /* Word 0 - Little Endian */
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_tc_main_start_s cn; */
};
typedef union cavm_ldecx_abx_tc_main_start cavm_ldecx_abx_tc_main_start_t;

static inline uint64_t CAVM_LDECX_ABX_TC_MAIN_START(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_TC_MAIN_START(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043681008ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043681008ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_TC_MAIN_START", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_MAIN_START(a,b) cavm_ldecx_abx_tc_main_start_t
#define bustype_CAVM_LDECX_ABX_TC_MAIN_START(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_MAIN_START(a,b) "LDECX_ABX_TC_MAIN_START"
#define busnum_CAVM_LDECX_ABX_TC_MAIN_START(a,b) (a)
#define arguments_CAVM_LDECX_ABX_TC_MAIN_START(a,b) (a),(b),-1,-1

/**
 * Register (RSL) ldec#_ab#_tc_mon#
 *
 * INTERNAL: TC Monitoring 0 Registers
 *
 * TC task output monitoring registers.
 */
union cavm_ldecx_abx_tc_monx
{
    uint64_t u;
    struct cavm_ldecx_abx_tc_monx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t bus_val               : 64; /**< [ 63:  0](RO/H) Decoder core task output monitoring values.
                                                                 mon_reg0_bus = Identifier associated to the Q output interface. Valid when q_avl is HIGH.
                                                                 mon_reg1_bus = Identifier associated to the R output interface. Valid when r_avl is HIGH.
                                                                 mon_reg2_bus = Identifier associated to the S output interface. Valid when s_avl is HIGH.
                                                                 mon_reg3_bus = Identifier associated to the H output interface. Valid when h_avl is HIGH. */
#else /* Word 0 - Little Endian */
        uint64_t bus_val               : 64; /**< [ 63:  0](RO/H) Decoder core task output monitoring values.
                                                                 mon_reg0_bus = Identifier associated to the Q output interface. Valid when q_avl is HIGH.
                                                                 mon_reg1_bus = Identifier associated to the R output interface. Valid when r_avl is HIGH.
                                                                 mon_reg2_bus = Identifier associated to the S output interface. Valid when s_avl is HIGH.
                                                                 mon_reg3_bus = Identifier associated to the H output interface. Valid when h_avl is HIGH. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_tc_monx_s cn; */
};
typedef union cavm_ldecx_abx_tc_monx cavm_ldecx_abx_tc_monx_t;

static inline uint64_t CAVM_LDECX_ABX_TC_MONX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_TC_MONX(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1) && (c<=3)))
        return 0x87e043681300ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1) && (c<=3)))
        return 0x87e043681300ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x3);
    __cavm_csr_fatal("LDECX_ABX_TC_MONX", 3, a, b, c, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_MONX(a,b,c) cavm_ldecx_abx_tc_monx_t
#define bustype_CAVM_LDECX_ABX_TC_MONX(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_MONX(a,b,c) "LDECX_ABX_TC_MONX"
#define busnum_CAVM_LDECX_ABX_TC_MONX(a,b,c) (a)
#define arguments_CAVM_LDECX_ABX_TC_MONX(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) ldec#_ab#_tc_status
 *
 * LDEC Decoder Status Register
 * This register reports status from the internal decoder core.
 */
union cavm_ldecx_abx_tc_status
{
    uint64_t u;
    struct cavm_ldecx_abx_tc_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t monitor_bus           : 32; /**< [ 63: 32](RO/H) core dependent */
        uint64_t reserved_1_31         : 31;
        uint64_t idle                  : 1;  /**< [  0:  0](RO/H) Idle status bit. High means core is idle. */
#else /* Word 0 - Little Endian */
        uint64_t idle                  : 1;  /**< [  0:  0](RO/H) Idle status bit. High means core is idle. */
        uint64_t reserved_1_31         : 31;
        uint64_t monitor_bus           : 32; /**< [ 63: 32](RO/H) core dependent */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldecx_abx_tc_status_s cn; */
};
typedef union cavm_ldecx_abx_tc_status cavm_ldecx_abx_tc_status_t;

static inline uint64_t CAVM_LDECX_ABX_TC_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LDECX_ABX_TC_STATUS(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043681020ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043681020ll + 0x500000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LDECX_ABX_TC_STATUS", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_STATUS(a,b) cavm_ldecx_abx_tc_status_t
#define bustype_CAVM_LDECX_ABX_TC_STATUS(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_STATUS(a,b) "LDECX_ABX_TC_STATUS"
#define busnum_CAVM_LDECX_ABX_TC_STATUS(a,b) (a)
#define arguments_CAVM_LDECX_ABX_TC_STATUS(a,b) (a),(b),-1,-1

#endif /* __CAVM_CSRS_LDEC_H__ */
