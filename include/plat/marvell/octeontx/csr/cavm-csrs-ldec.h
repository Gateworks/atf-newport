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
 * This structure specifies the code block configuraiton.
 */
union cavm_ldec_cb_cfg_s
{
    uint64_t u[3];
    struct cavm_ldec_cb_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rm_e                  : 16; /**< [ 63: 48] Rate matching size, Er, as defined in section 5.4.2.1 of 38.212.
                                                                 Valid range [cb_size/0.95 : cb_size*12] */
        uint64_t reserved_46_47        : 2;
        uint64_t nfiller               : 14; /**< [ 45: 32] Number of filler bits, as defined in section 5.2.2 of 38.212. nfiller = K-K. */
        uint64_t reserved_30_31        : 2;
        uint64_t cb_size               : 14; /**< [ 29: 16] Code block size including CB CRC, Range 40 to 8448 includes filler bits
                                                                 corresponds to notation K in 38.212.
                                                                 K=22*Z for BG1
                                                                 K=10*Z for BG2 */
        uint64_t reserved_9_15         : 7;
        uint64_t num_cb                : 9;  /**< [  8:  0] Number of consecutive code blocks with this CB configuration Valid range [1:152] */
#else /* Word 0 - Little Endian */
        uint64_t num_cb                : 9;  /**< [  8:  0] Number of consecutive code blocks with this CB configuration Valid range [1:152] */
        uint64_t reserved_9_15         : 7;
        uint64_t cb_size               : 14; /**< [ 29: 16] Code block size including CB CRC, Range 40 to 8448 includes filler bits
                                                                 corresponds to notation K in 38.212.
                                                                 K=22*Z for BG1
                                                                 K=10*Z for BG2 */
        uint64_t reserved_30_31        : 2;
        uint64_t nfiller               : 14; /**< [ 45: 32] Number of filler bits, as defined in section 5.2.2 of 38.212. nfiller = K-K. */
        uint64_t reserved_46_47        : 2;
        uint64_t rm_e                  : 16; /**< [ 63: 48] Rate matching size, Er, as defined in section 5.4.2.1 of 38.212.
                                                                 Valid range [cb_size/0.95 : cb_size*12] */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_112_127      : 16;
        uint64_t hcout_size1           : 16; /**< [111: 96] Length of second section of HARQ output starting from offset "hcout_offset" in
                                                                 pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcout_size0           : 16; /**< [ 95: 80] Length of first section of HARQ output starting from the beginning of the pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcout_offset          : 16; /**< [ 79: 64] Offset in pruned circular buffer starting from which second section of HARQ output is transmitted.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
#else /* Word 1 - Little Endian */
        uint64_t hcout_offset          : 16; /**< [ 79: 64] Offset in pruned circular buffer starting from which second section of HARQ output is transmitted.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcout_size0           : 16; /**< [ 95: 80] Length of first section of HARQ output starting from the beginning of the pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcout_size1           : 16; /**< [111: 96] Length of second section of HARQ output starting from offset "hcout_offset" in
                                                                 pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t reserved_112_127      : 16;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_176_191      : 16;
        uint64_t hcin_size1            : 16; /**< [175:160] Length of second section of HARQ input starting from offset "hcin_offset" in
                                                                 pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcin_size0            : 16; /**< [159:144] Length of first section of HARQ input starting from the beginning of the pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcin_offset           : 16; /**< [143:128] Offset in pruned circular buffer starting from which second section of HARQ input is provided.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
#else /* Word 2 - Little Endian */
        uint64_t hcin_offset           : 16; /**< [143:128] Offset in pruned circular buffer starting from which second section of HARQ input is provided.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcin_size0            : 16; /**< [159:144] Length of first section of HARQ input starting from the beginning of the pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcin_size1            : 16; /**< [175:160] Length of second section of HARQ input starting from offset "hcin_offset" in
                                                                 pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t reserved_176_191      : 16;
#endif /* Word 2 - End */
    } s;
    struct cavm_ldec_cb_cfg_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rm_e                  : 16; /**< [ 63: 48] Rate matching size, Er, as defined in section 5.4.2.1 of 38.212.
                                                                 Valid range [cb_size/0.95 : cb_size*12] */
        uint64_t reserved_46_47        : 2;
        uint64_t nfiller               : 14; /**< [ 45: 32] Number of filler bits, as defined in section 5.2.2 of 38.212. nfiller = K-K. */
        uint64_t reserved_30_31        : 2;
        uint64_t cb_size               : 14; /**< [ 29: 16] Code block size including CB CRC, Range 40 to 8448 includes filler bits
                                                                 corresponds to notation K in 38.212.
                                                                 K=22*Z for BG1
                                                                 K=10*Z for BG2 */
        uint64_t reserved_12_15        : 4;
        uint64_t reserved_9_11         : 3;
        uint64_t num_cb                : 9;  /**< [  8:  0] Number of consecutive code blocks with this CB configuration Valid range [1:152] */
#else /* Word 0 - Little Endian */
        uint64_t num_cb                : 9;  /**< [  8:  0] Number of consecutive code blocks with this CB configuration Valid range [1:152] */
        uint64_t reserved_9_11         : 3;
        uint64_t reserved_12_15        : 4;
        uint64_t cb_size               : 14; /**< [ 29: 16] Code block size including CB CRC, Range 40 to 8448 includes filler bits
                                                                 corresponds to notation K in 38.212.
                                                                 K=22*Z for BG1
                                                                 K=10*Z for BG2 */
        uint64_t reserved_30_31        : 2;
        uint64_t nfiller               : 14; /**< [ 45: 32] Number of filler bits, as defined in section 5.2.2 of 38.212. nfiller = K-K. */
        uint64_t reserved_46_47        : 2;
        uint64_t rm_e                  : 16; /**< [ 63: 48] Rate matching size, Er, as defined in section 5.4.2.1 of 38.212.
                                                                 Valid range [cb_size/0.95 : cb_size*12] */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_112_127      : 16;
        uint64_t hcout_size1           : 16; /**< [111: 96] Length of second section of HARQ output starting from offset "hcout_offset" in
                                                                 pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcout_size0           : 16; /**< [ 95: 80] Length of first section of HARQ output starting from the beginning of the pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcout_offset          : 16; /**< [ 79: 64] Offset in pruned circular buffer starting from which second section of HARQ output is transmitted.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
#else /* Word 1 - Little Endian */
        uint64_t hcout_offset          : 16; /**< [ 79: 64] Offset in pruned circular buffer starting from which second section of HARQ output is transmitted.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcout_size0           : 16; /**< [ 95: 80] Length of first section of HARQ output starting from the beginning of the pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcout_size1           : 16; /**< [111: 96] Length of second section of HARQ output starting from offset "hcout_offset" in
                                                                 pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t reserved_112_127      : 16;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_176_191      : 16;
        uint64_t hcin_size1            : 16; /**< [175:160] Length of second section of HARQ input starting from offset "hcin_offset" in
                                                                 pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcin_size0            : 16; /**< [159:144] Length of first section of HARQ input starting from the beginning of the pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcin_offset           : 16; /**< [143:128] Offset in pruned circular buffer starting from which second section of HARQ input is provided.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
#else /* Word 2 - Little Endian */
        uint64_t hcin_offset           : 16; /**< [143:128] Offset in pruned circular buffer starting from which second section of HARQ input is provided.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcin_size0            : 16; /**< [159:144] Length of first section of HARQ input starting from the beginning of the pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t hcin_size1            : 16; /**< [175:160] Length of second section of HARQ input starting from offset "hcin_offset" in
                                                                 pruned circular buffer.
                                                                 An exact multiple of 16
                                                                 Valid range [0:ncb_size] */
        uint64_t reserved_176_191      : 16;
#endif /* Word 2 - End */
    } cn;
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
        uint64_t num_words_partial_tb_proc : 4;/**< [ 27: 24] Number of words for specification of parameters for partial TB processing.
                                                                 Currently 6 words */
        uint64_t num_words_per_cb_cfg  : 8;  /**< [ 23: 16] Number of words for each CB configuration appended at the end of common configuration.
                                                                 Currently 3 words. */
        uint64_t num_words_task_com_cfg : 8; /**< [ 15:  8] Number of common configuration words per task.
                                                                 Currently 11 words. */
        uint64_t reserved_6_7          : 2;
        uint64_t phy_mode              : 1;  /**< [  5:  5] The task type.
                                                                 0x0 = 3GPP 5G NR
                                                                 0x1 = DCOSIS */
        uint64_t num_bundled_tasks     : 5;  /**< [  4:  0] Number of tasks that are bundled in one job. Range [1-16]. */
#else /* Word 0 - Little Endian */
        uint64_t num_bundled_tasks     : 5;  /**< [  4:  0] Number of tasks that are bundled in one job. Range [1-16]. */
        uint64_t phy_mode              : 1;  /**< [  5:  5] The task type.
                                                                 0x0 = 3GPP 5G NR
                                                                 0x1 = DCOSIS */
        uint64_t reserved_6_7          : 2;
        uint64_t num_words_task_com_cfg : 8; /**< [ 15:  8] Number of common configuration words per task.
                                                                 Currently 11 words. */
        uint64_t num_words_per_cb_cfg  : 8;  /**< [ 23: 16] Number of words for each CB configuration appended at the end of common configuration.
                                                                 Currently 3 words. */
        uint64_t num_words_partial_tb_proc : 4;/**< [ 27: 24] Number of words for specification of parameters for partial TB processing.
                                                                 Currently 6 words */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ldec_common_cfg_s_s cn; */
};

/**
 * Structure ldec_opt_task_cfg_s
 *
 * LDEC Mandatory Task Configuration Structure
 * This structure specifies the optional task configuraiton for a task.
 */
union cavm_ldec_opt_task_cfg_s
{
    uint64_t u[6];
    struct cavm_ldec_opt_task_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t hd_prefix_word        : 64; /**< [ 63:  0] 64 bits prefix word to be merged with the first part of decoded bits of the
                                                                 first CB if hd_prefix_bit_index \> 0 */
#else /* Word 0 - Little Endian */
        uint64_t hd_prefix_word        : 64; /**< [ 63:  0] 64 bits prefix word to be merged with the first part of decoded bits of the
                                                                 first CB if hd_prefix_bit_index \> 0 */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t hd_suffix_word        : 64; /**< [127: 64] 64 bits suffix word to be merged with the end of decoded bits of the last CB in the task. */
#else /* Word 1 - Little Endian */
        uint64_t hd_suffix_word        : 64; /**< [127: 64] 64 bits suffix word to be merged with the end of decoded bits of the last CB in the task. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reenc_prefix_word     : 64; /**< [191:128] Prefix word to be stitched to the beginning of the re-encoded output of the
                                                                 first CB if reenc_prefix_bit_index \> 0 */
#else /* Word 2 - Little Endian */
        uint64_t reenc_prefix_word     : 64; /**< [191:128] Prefix word to be stitched to the beginning of the re-encoded output of the
                                                                 first CB if reenc_prefix_bit_index \> 0 */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t so_prefix_word0       : 64; /**< [255:192] 64 LSBs of prefix word to be stitched to the beginning of the re-encoded soft
                                                                 output of the first CB if so_prefix_llr_index \> 0 */
#else /* Word 3 - Little Endian */
        uint64_t so_prefix_word0       : 64; /**< [255:192] 64 LSBs of prefix word to be stitched to the beginning of the re-encoded soft
                                                                 output of the first CB if so_prefix_llr_index \> 0 */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t so_prefix_word1       : 64; /**< [319:256] 64 MSBs of prefix word to be stitched to the beginning of the re-encoded soft
                                                                 output of the first CB if so_prefix_llr_index \> 0 */
#else /* Word 4 - Little Endian */
        uint64_t so_prefix_word1       : 64; /**< [319:256] 64 MSBs of prefix word to be stitched to the beginning of the re-encoded soft
                                                                 output of the first CB if so_prefix_llr_index \> 0 */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t tb_crc_contrib_jump   : 32; /**< [383:352] Maximum 32 bits to represent jump of TB CRC state from the beginning of the first CB
                                                                 in the task till the end of TB.
                                                                 Valid range [0:tb_size] */
        uint64_t reserved_340_351      : 12;
        uint64_t so_prefix_llr_index   : 4;  /**< [339:336] Applicable only to CB processing mode.
                                                                 LLR index in the prefix word from which the soft output of the current CB task output is written.
                                                                 Valid range [0:15]
                                                                 0 : prefix merge is bypassed */
        uint64_t reserved_334_335      : 2;
        uint64_t reenc_prefix_bit_index : 6; /**< [333:328] Applicable only to CB processing mode.
                                                                 Bit index in the prefix word from which the re-encoded output of the current CB
                                                                 task output is written.
                                                                 Valid range [0:63]
                                                                 0 : prefix merge is bypassed */
        uint64_t reserved_326_327      : 2;
        uint64_t hd_prefix_bit_index   : 6;  /**< [325:320] Bit position of first decoded bit of CBG in 64-bit prefix word provided.
                                                                 Valid range [0:63]
                                                                 0 : prefix merge is bypassed */
#else /* Word 5 - Little Endian */
        uint64_t hd_prefix_bit_index   : 6;  /**< [325:320] Bit position of first decoded bit of CBG in 64-bit prefix word provided.
                                                                 Valid range [0:63]
                                                                 0 : prefix merge is bypassed */
        uint64_t reserved_326_327      : 2;
        uint64_t reenc_prefix_bit_index : 6; /**< [333:328] Applicable only to CB processing mode.
                                                                 Bit index in the prefix word from which the re-encoded output of the current CB
                                                                 task output is written.
                                                                 Valid range [0:63]
                                                                 0 : prefix merge is bypassed */
        uint64_t reserved_334_335      : 2;
        uint64_t so_prefix_llr_index   : 4;  /**< [339:336] Applicable only to CB processing mode.
                                                                 LLR index in the prefix word from which the soft output of the current CB task output is written.
                                                                 Valid range [0:15]
                                                                 0 : prefix merge is bypassed */
        uint64_t reserved_340_351      : 12;
        uint64_t tb_crc_contrib_jump   : 32; /**< [383:352] Maximum 32 bits to represent jump of TB CRC state from the beginning of the first CB
                                                                 in the task till the end of TB.
                                                                 Valid range [0:tb_size] */
#endif /* Word 5 - End */
    } s;
    /* struct cavm_ldec_opt_task_cfg_s_s cn; */
};

/**
 * Structure ldec_task_cfg_s
 *
 * LDEC Mandatory Task Configuration Structure
 * This structure specifies the configuraiton for a task.
 */
union cavm_ldec_task_cfg_s
{
    uint64_t u[11];
    struct cavm_ldec_task_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t negstop_th            : 16; /**< [ 63: 48] Negative stopping threshold. */
        uint64_t stop_it               : 2;  /**< [ 47: 46] Activates the early iteration stopping mechanism upon parity check pass.
                                                                 0 : No stop
                                                                 1 : Syndrome check based stop
                                                                 Valid range [0:1] */
        uint64_t so_it                 : 7;  /**< [ 45: 39] Decoder iteration after which soft output shall be released.
                                                                 If decoder stops before, the soft output of the last iteration will be released.
                                                                 Valid range [1:127] */
        uint64_t max_it                : 7;  /**< [ 38: 32] Maximum number of LDPC decoder iterations. Valid range [1:127] */
        uint64_t tb_tail               : 1;  /**< [ 31: 31] 0 : task does not contain the last CB of TB
                                                                 1 : task contains the last CB of TB
                                                                 Valid range [0:1] */
        uint64_t llr_sign_format       : 1;  /**< [ 30: 30] Sign format of the input LLRs
                                                                 0: 0p format. 0 bit corresponding to +ve LLR
                                                                 1: 1p format. 1 bit corresponding to +ve LLR
                                                                 Valid range [0:1] */
        uint64_t mod_order             : 4;  /**< [ 29: 26] 5G Modulation order. Valid range: [1,2,4,6,8,10] */
        uint64_t basegraph             : 2;  /**< [ 25: 24] 5G NR LDPC base graph
                                                                 0: BG1
                                                                 1: BG2
                                                                 Valid range [0:1] */
        uint64_t reserved_23           : 1;
        uint64_t bypass_partial_tb_proc : 1; /**< [ 22: 22] 0: Partial TB processing enabled with optional words in table 3 present
                                                                 following task common configuration
                                                                 1: Full TB processing. Optional words in table 3 are absent following task common configuration.
                                                                 Valid range [0:1] */
        uint64_t num_cb_cfg            : 6;  /**< [ 21: 16] Number of CB configurations appended to this task.
                                                                 Each configuration specifies a string of consecutive CBs sharing the same configuration.
                                                                 Valid range [1:8] */
        uint64_t task_id               : 16; /**< [ 15:  0] Index associated with this decoding task.
                                                                 Current design assumes up to 16 tasks are bundled within a job.
                                                                 SW shall make sure task_ids assigned to different tasks bundled within a job do not collide.
                                                                 Valid range [0:2^16-1] */
#else /* Word 0 - Little Endian */
        uint64_t task_id               : 16; /**< [ 15:  0] Index associated with this decoding task.
                                                                 Current design assumes up to 16 tasks are bundled within a job.
                                                                 SW shall make sure task_ids assigned to different tasks bundled within a job do not collide.
                                                                 Valid range [0:2^16-1] */
        uint64_t num_cb_cfg            : 6;  /**< [ 21: 16] Number of CB configurations appended to this task.
                                                                 Each configuration specifies a string of consecutive CBs sharing the same configuration.
                                                                 Valid range [1:8] */
        uint64_t bypass_partial_tb_proc : 1; /**< [ 22: 22] 0: Partial TB processing enabled with optional words in table 3 present
                                                                 following task common configuration
                                                                 1: Full TB processing. Optional words in table 3 are absent following task common configuration.
                                                                 Valid range [0:1] */
        uint64_t reserved_23           : 1;
        uint64_t basegraph             : 2;  /**< [ 25: 24] 5G NR LDPC base graph
                                                                 0: BG1
                                                                 1: BG2
                                                                 Valid range [0:1] */
        uint64_t mod_order             : 4;  /**< [ 29: 26] 5G Modulation order. Valid range: [1,2,4,6,8,10] */
        uint64_t llr_sign_format       : 1;  /**< [ 30: 30] Sign format of the input LLRs
                                                                 0: 0p format. 0 bit corresponding to +ve LLR
                                                                 1: 1p format. 1 bit corresponding to +ve LLR
                                                                 Valid range [0:1] */
        uint64_t tb_tail               : 1;  /**< [ 31: 31] 0 : task does not contain the last CB of TB
                                                                 1 : task contains the last CB of TB
                                                                 Valid range [0:1] */
        uint64_t max_it                : 7;  /**< [ 38: 32] Maximum number of LDPC decoder iterations. Valid range [1:127] */
        uint64_t so_it                 : 7;  /**< [ 45: 39] Decoder iteration after which soft output shall be released.
                                                                 If decoder stops before, the soft output of the last iteration will be released.
                                                                 Valid range [1:127] */
        uint64_t stop_it               : 2;  /**< [ 47: 46] Activates the early iteration stopping mechanism upon parity check pass.
                                                                 0 : No stop
                                                                 1 : Syndrome check based stop
                                                                 Valid range [0:1] */
        uint64_t negstop_th            : 16; /**< [ 63: 48] Negative stopping threshold. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_125_127      : 3;
        uint64_t bypass_monitor_words  : 1;  /**< [124:124] 0: All 13 monitoring words are appended to HD output.
                                                                 1: Only first 2 monitoring words are appended to HD output.
                                                                 Following TB CRC contribution words are sent or not depending on the flag bypass_tb_crc_contrib
                                                                 Valid range [0:1] */
        uint64_t tb_tx_bit_size        : 24; /**< [123:100] Total number of input LLR values across all CBS to be used by the task.
                                                                 These are LLRs excluding the ones dropped at the beginning/end and the tagged values.
                                                                 Valid range [1:1362816] */
        uint64_t hcout_llr_comp_mode   : 3;  /**< [ 99: 97] HARQ LLR output compression scheme
                                                                 0: bypass (do nothing)
                                                                 1: Saturate to 6 bits (8 to 6 bits)
                                                                 2: Right shift 1 bit with rounding and saturate to 6 bits (8 to 6 bits)
                                                                 3: Right shift 2 bits with rounding (8 to 6 bits)
                                                                 4: Round(log2)quantization (8 to 4 bits)
                                                                 Valid range [0:4] */
        uint64_t hcout_en              : 1;  /**< [ 96: 96] 1: HCout vector is released after HARQ combining.
                                                                 0: No HCout vector is released. HARQ combining can still be enabled.
                                                                     This feature can optionally be used when decoding the last transmission.
                                                                 Valid range [0:1] */
        uint64_t hcin_llr_decomp_mode  : 3;  /**< [ 95: 93] HARQ LLR input decompression scheme
                                                                 0: bypass (do nothing)
                                                                 1: Sign extension (6 to 8 bits)
                                                                 2: Left shift 1 bit and sign extend(6 to 8 bits)
                                                                 3: Left shift 2 bits(6 to 8 bits)
                                                                 4: Reverse the operation of round(log2)quantization (4 bits to 8 bits)
                                                                 Valid range [0:4] */
        uint64_t hcin_en               : 1;  /**< [ 92: 92] 0: Only input LLRs are expected to be received. HARQ is either disabled or this
                                                                 is the first transmission.
                                                                 1: HARQ input is enabled. The core expects to receive HCin stream once all input LLRs are received.
                                                                 Valid range [0:1] */
        uint64_t reenc_data_order      : 3;  /**< [ 91: 89] Bit 25:
                                                                   0: DATA_BIT_MSB_FIRST
                                                                   1: DATA_BIT_LSB_FIRST
                                                                   Refer to [R1] for data packing details.
                                                                 Bits 26:27:
                                                                   0: DATA_BYTE_ORDER_MODE_0
                                                                   1: DATA_BYTE_ORDER_MODE_1
                                                                   2: DATA_BYTE_ORDER_MODE_2
                                                                   Refer to [R1] for data packing details.
                                                                   As per current assumptions, it shall be set to DATA_BYTE_ORDER_MODE_0.
                                                                   Valid range [0:7] */
        uint64_t reenc_qm_with_crc     : 1;  /**< [ 88: 88] 1 : Add 1-bit CB CRC result to each set of Qm bits output.
                                                                 0 : No CRC addition
                                                                 Not possible to have this enabled when reenc_symb_byte_aligned \> 0
                                                                 Valid range [0,1] */
        uint64_t reenc_symb_byte_aligned : 2;/**< [ 87: 86] 0: bypass mode. Data bits are sent out back to back.
                                                                 1: can be used only for Qm\<10. Each Qm bit is mapped to one byte (as illustrated in Figure 18.
                                                                  Qm data bits are mapped in little endian format. 8-Qm MSB bits of that byte are set to 0.
                                                                 2: can be used only when Qm = 10; from each 10 bits mapped to one symbol,
                                                                   the even bits are mapped to first byte and odd bits are mapped to the next byte.
                                                                   Data bit are mapped in little endian format and 3 MSB bits of each byte are set to 0
                                                                   (Option 1 as described in Section Error! Reference source not found..)
                                                                 3: can be used only when Qm = 10; from each 10 bits mapped to one symbol,
                                                                   the first five bits are mapped to first byte and the next five bits are mapped
                                                                   to the next byte. Data bit are mapped in little endian format and 3 MSB bits of each
                                                                   byte are set to 0 (Option 2 as described in Section Error! Reference source not found..)
                                                                 Valid range [0:3] */
        uint64_t hd_data_order         : 3;  /**< [ 85: 83] Bit 19:
                                                                   0: DATA_BIT_MSB_FIRST
                                                                   1: DATA_BIT_LSB_FIRST
                                                                   Refer to [R1] for data packing details.
                                                                   As per current assumptions, it shall be set to DATA_BIT_MSB_FIRST.
                                                                 Bits 21:20:
                                                                   0: DATA_BYTE_ORDER_MODE_0
                                                                   1: DATA_BYTE_ORDER_MODE_1
                                                                   2: DATA_BYTE_ORDER_MODE_2
                                                                 Refer to [R1] for data packing details.
                                                                 As per current assumptions, it shall be set to DATA_BYTE_ORDER_MODE_0.
                                                                 Valid range [0:7] */
        uint64_t bypass_reenc_rm       : 1;  /**< [ 82: 82] 0: rate matching is performed on re-encoded hard bits. The core generates Er bits for r-th CB.
                                                                 1: rate matching is bypassed.
                                                                 Valid range [0,1] */
        uint64_t generate_reenc        : 1;  /**< [ 81: 81] 1: re-encoding is enabled.
                                                                 0: re-encoding is bypassed.
                                                                 Valid range [0,1] */
        uint64_t bypass_so_rm          : 1;  /**< [ 80: 80] Bypass the rate matching on soft output. Valid range [0,1] */
        uint64_t generate_so           : 1;  /**< [ 79: 79] 0: Soft bit output generation is bypassed. Only hard decision outputs are generated and available.
                                                                 1: Soft bit output generation is enabled.
                                                                 If soft output generation is enabled, it will generate "num_llr" soft outputs.
                                                                 Valid range [0,1] */
        uint64_t bypass_bit_intlv      : 1;  /**< [ 78: 78] 0 : perform bit-level interleaver
                                                                 1 : bypass bit-level interleaver (applies on both Rx and soft-out streams)
                                                                 Valid range [0,1] */
        uint64_t bypass_decoder        : 1;  /**< [ 77: 77] 0: LDPC decoding is enabled.
                                                                 1: LDPC decoding of the combined vector is bypassed.
                                                                 This mode can optionally be used for only performing HARQ combining.
                                                                 The Core only performs HARQ combining and generates HARQ output.
                                                                 Valid range [0,1] */
        uint64_t bypass_tb_crc_contrib : 1;  /**< [ 76: 76] Bypass TB CRC contribution calculation from each CB.
                                                                 When bypassed, no TB CRC contribution words are appended to hard decision output.
                                                                 Valid range [0,1] */
        uint64_t bypass_tb_crc         : 1;  /**< [ 75: 75] Bypass TB CRC calculation.
                                                                 When not bypassed, TB CRC is calculated and stripped off from hard output.
                                                                 Valid range [0,1] */
        uint64_t tb_crc_select         : 2;  /**< [ 74: 73] CRC polynomial used for the calculation of TB CRC and CB level TB CRC contribution
                                                                 1 : CRC-16
                                                                 2 : CRC-24A
                                                                 Valid range [1,2]
                                                                 Note : value 0 not allowed. */
        uint64_t cb_crc_select         : 1;  /**< [ 72: 72] CB CRC polynomial select
                                                                 0:bypass
                                                                 1:gCRC24B
                                                                 Valid range [0,1] */
        uint64_t negstop_en            : 1;  /**< [ 71: 71] Activates the negative stopping mechanism, using which uncorrectable frames are discarded early.
                                                                 Valid range [0,1] */
        uint64_t negstop_it            : 7;  /**< [ 70: 64] Sets at which iteration the negative stopping condition is evaluated. Valid range [1:127] */
#else /* Word 1 - Little Endian */
        uint64_t negstop_it            : 7;  /**< [ 70: 64] Sets at which iteration the negative stopping condition is evaluated. Valid range [1:127] */
        uint64_t negstop_en            : 1;  /**< [ 71: 71] Activates the negative stopping mechanism, using which uncorrectable frames are discarded early.
                                                                 Valid range [0,1] */
        uint64_t cb_crc_select         : 1;  /**< [ 72: 72] CB CRC polynomial select
                                                                 0:bypass
                                                                 1:gCRC24B
                                                                 Valid range [0,1] */
        uint64_t tb_crc_select         : 2;  /**< [ 74: 73] CRC polynomial used for the calculation of TB CRC and CB level TB CRC contribution
                                                                 1 : CRC-16
                                                                 2 : CRC-24A
                                                                 Valid range [1,2]
                                                                 Note : value 0 not allowed. */
        uint64_t bypass_tb_crc         : 1;  /**< [ 75: 75] Bypass TB CRC calculation.
                                                                 When not bypassed, TB CRC is calculated and stripped off from hard output.
                                                                 Valid range [0,1] */
        uint64_t bypass_tb_crc_contrib : 1;  /**< [ 76: 76] Bypass TB CRC contribution calculation from each CB.
                                                                 When bypassed, no TB CRC contribution words are appended to hard decision output.
                                                                 Valid range [0,1] */
        uint64_t bypass_decoder        : 1;  /**< [ 77: 77] 0: LDPC decoding is enabled.
                                                                 1: LDPC decoding of the combined vector is bypassed.
                                                                 This mode can optionally be used for only performing HARQ combining.
                                                                 The Core only performs HARQ combining and generates HARQ output.
                                                                 Valid range [0,1] */
        uint64_t bypass_bit_intlv      : 1;  /**< [ 78: 78] 0 : perform bit-level interleaver
                                                                 1 : bypass bit-level interleaver (applies on both Rx and soft-out streams)
                                                                 Valid range [0,1] */
        uint64_t generate_so           : 1;  /**< [ 79: 79] 0: Soft bit output generation is bypassed. Only hard decision outputs are generated and available.
                                                                 1: Soft bit output generation is enabled.
                                                                 If soft output generation is enabled, it will generate "num_llr" soft outputs.
                                                                 Valid range [0,1] */
        uint64_t bypass_so_rm          : 1;  /**< [ 80: 80] Bypass the rate matching on soft output. Valid range [0,1] */
        uint64_t generate_reenc        : 1;  /**< [ 81: 81] 1: re-encoding is enabled.
                                                                 0: re-encoding is bypassed.
                                                                 Valid range [0,1] */
        uint64_t bypass_reenc_rm       : 1;  /**< [ 82: 82] 0: rate matching is performed on re-encoded hard bits. The core generates Er bits for r-th CB.
                                                                 1: rate matching is bypassed.
                                                                 Valid range [0,1] */
        uint64_t hd_data_order         : 3;  /**< [ 85: 83] Bit 19:
                                                                   0: DATA_BIT_MSB_FIRST
                                                                   1: DATA_BIT_LSB_FIRST
                                                                   Refer to [R1] for data packing details.
                                                                   As per current assumptions, it shall be set to DATA_BIT_MSB_FIRST.
                                                                 Bits 21:20:
                                                                   0: DATA_BYTE_ORDER_MODE_0
                                                                   1: DATA_BYTE_ORDER_MODE_1
                                                                   2: DATA_BYTE_ORDER_MODE_2
                                                                 Refer to [R1] for data packing details.
                                                                 As per current assumptions, it shall be set to DATA_BYTE_ORDER_MODE_0.
                                                                 Valid range [0:7] */
        uint64_t reenc_symb_byte_aligned : 2;/**< [ 87: 86] 0: bypass mode. Data bits are sent out back to back.
                                                                 1: can be used only for Qm\<10. Each Qm bit is mapped to one byte (as illustrated in Figure 18.
                                                                  Qm data bits are mapped in little endian format. 8-Qm MSB bits of that byte are set to 0.
                                                                 2: can be used only when Qm = 10; from each 10 bits mapped to one symbol,
                                                                   the even bits are mapped to first byte and odd bits are mapped to the next byte.
                                                                   Data bit are mapped in little endian format and 3 MSB bits of each byte are set to 0
                                                                   (Option 1 as described in Section Error! Reference source not found..)
                                                                 3: can be used only when Qm = 10; from each 10 bits mapped to one symbol,
                                                                   the first five bits are mapped to first byte and the next five bits are mapped
                                                                   to the next byte. Data bit are mapped in little endian format and 3 MSB bits of each
                                                                   byte are set to 0 (Option 2 as described in Section Error! Reference source not found..)
                                                                 Valid range [0:3] */
        uint64_t reenc_qm_with_crc     : 1;  /**< [ 88: 88] 1 : Add 1-bit CB CRC result to each set of Qm bits output.
                                                                 0 : No CRC addition
                                                                 Not possible to have this enabled when reenc_symb_byte_aligned \> 0
                                                                 Valid range [0,1] */
        uint64_t reenc_data_order      : 3;  /**< [ 91: 89] Bit 25:
                                                                   0: DATA_BIT_MSB_FIRST
                                                                   1: DATA_BIT_LSB_FIRST
                                                                   Refer to [R1] for data packing details.
                                                                 Bits 26:27:
                                                                   0: DATA_BYTE_ORDER_MODE_0
                                                                   1: DATA_BYTE_ORDER_MODE_1
                                                                   2: DATA_BYTE_ORDER_MODE_2
                                                                   Refer to [R1] for data packing details.
                                                                   As per current assumptions, it shall be set to DATA_BYTE_ORDER_MODE_0.
                                                                   Valid range [0:7] */
        uint64_t hcin_en               : 1;  /**< [ 92: 92] 0: Only input LLRs are expected to be received. HARQ is either disabled or this
                                                                 is the first transmission.
                                                                 1: HARQ input is enabled. The core expects to receive HCin stream once all input LLRs are received.
                                                                 Valid range [0:1] */
        uint64_t hcin_llr_decomp_mode  : 3;  /**< [ 95: 93] HARQ LLR input decompression scheme
                                                                 0: bypass (do nothing)
                                                                 1: Sign extension (6 to 8 bits)
                                                                 2: Left shift 1 bit and sign extend(6 to 8 bits)
                                                                 3: Left shift 2 bits(6 to 8 bits)
                                                                 4: Reverse the operation of round(log2)quantization (4 bits to 8 bits)
                                                                 Valid range [0:4] */
        uint64_t hcout_en              : 1;  /**< [ 96: 96] 1: HCout vector is released after HARQ combining.
                                                                 0: No HCout vector is released. HARQ combining can still be enabled.
                                                                     This feature can optionally be used when decoding the last transmission.
                                                                 Valid range [0:1] */
        uint64_t hcout_llr_comp_mode   : 3;  /**< [ 99: 97] HARQ LLR output compression scheme
                                                                 0: bypass (do nothing)
                                                                 1: Saturate to 6 bits (8 to 6 bits)
                                                                 2: Right shift 1 bit with rounding and saturate to 6 bits (8 to 6 bits)
                                                                 3: Right shift 2 bits with rounding (8 to 6 bits)
                                                                 4: Round(log2)quantization (8 to 4 bits)
                                                                 Valid range [0:4] */
        uint64_t tb_tx_bit_size        : 24; /**< [123:100] Total number of input LLR values across all CBS to be used by the task.
                                                                 These are LLRs excluding the ones dropped at the beginning/end and the tagged values.
                                                                 Valid range [1:1362816] */
        uint64_t bypass_monitor_words  : 1;  /**< [124:124] 0: All 13 monitoring words are appended to HD output.
                                                                 1: Only first 2 monitoring words are appended to HD output.
                                                                 Following TB CRC contribution words are sent or not depending on the flag bypass_tb_crc_contrib
                                                                 Valid range [0:1] */
        uint64_t reserved_125_127      : 3;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_184_191      : 8;
        uint64_t k0                    : 16; /**< [183:168] k0 value representing offset of Rx data in unpruned circular buffer as defined
                                                                 in Table 5.4.2.1-2 in 38.212 Need to be less than ncb size */
        uint64_t gain_h                : 8;  /**< [167:160] Scaling factor for HARQ input LLRs in HARQ combining (also called GH in this document).
                                                                 Valid range [0:255] */
        uint64_t gain_i                : 8;  /**< [159:152] Scaling factor for Rx input LLRs in HARQ combining (also called GI in this document).
                                                                 Valid range [0:255] */
        uint64_t hcout_llr_cnv         : 4;  /**< [151:148] scaling applied to LLR samples between HARQ combine and HCout release.
                                                                 Samples have their amplitude right-shifted by hcout_conv_llr bits
                                                                 Valid range [0:8] */
        uint64_t dec_llr_cnv           : 4;  /**< [147:144] scaling applied to LLR samples between HARQ combine and LDPC decoder.
                                                                 Samples have their amplitude right-shifted by dec_conv_llr bits
                                                                 Valid range [0:8] */
        uint64_t ncb_size              : 16; /**< [143:128] soft buffer size of each code block as defined in section 5.4.2.1 in 38.212. Maximum value 25344 */
#else /* Word 2 - Little Endian */
        uint64_t ncb_size              : 16; /**< [143:128] soft buffer size of each code block as defined in section 5.4.2.1 in 38.212. Maximum value 25344 */
        uint64_t dec_llr_cnv           : 4;  /**< [147:144] scaling applied to LLR samples between HARQ combine and LDPC decoder.
                                                                 Samples have their amplitude right-shifted by dec_conv_llr bits
                                                                 Valid range [0:8] */
        uint64_t hcout_llr_cnv         : 4;  /**< [151:148] scaling applied to LLR samples between HARQ combine and HCout release.
                                                                 Samples have their amplitude right-shifted by hcout_conv_llr bits
                                                                 Valid range [0:8] */
        uint64_t gain_i                : 8;  /**< [159:152] Scaling factor for Rx input LLRs in HARQ combining (also called GI in this document).
                                                                 Valid range [0:255] */
        uint64_t gain_h                : 8;  /**< [167:160] Scaling factor for HARQ input LLRs in HARQ combining (also called GH in this document).
                                                                 Valid range [0:255] */
        uint64_t k0                    : 16; /**< [183:168] k0 value representing offset of Rx data in unpruned circular buffer as defined
                                                                 in Table 5.4.2.1-2 in 38.212 Need to be less than ncb size */
        uint64_t reserved_184_191      : 8;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_254_255      : 2;
        uint64_t preproc_p0_csi2_len2  : 19; /**< [253:235] Size of burst 2, CSI2 part0. Valid range : [0:422399] */
        uint64_t preproc_p0_csi2_len1  : 19; /**< [234:216] Size of burst 1, CSI2 part0. Valid range : [0:422399] */
        uint64_t preproc_p0_csi2_len0  : 19; /**< [215:197] Size of burst 0, CSI2 part0. Valid range : [0:422399] */
        uint64_t reserved_194_196      : 3;
        uint64_t preproc_enable        : 1;  /**< [193:193] 0 : disable pre-processor 1: enable pre-processor */
        uint64_t preproc_mode          : 1;  /**< [192:192] Flag indicating the mode of LLR pre-processing block
                                                                 0 : Keep CSI2 LLRs 1 : Keep data LLRs */
#else /* Word 3 - Little Endian */
        uint64_t preproc_mode          : 1;  /**< [192:192] Flag indicating the mode of LLR pre-processing block
                                                                 0 : Keep CSI2 LLRs 1 : Keep data LLRs */
        uint64_t preproc_enable        : 1;  /**< [193:193] 0 : disable pre-processor 1: enable pre-processor */
        uint64_t reserved_194_196      : 3;
        uint64_t preproc_p0_csi2_len0  : 19; /**< [215:197] Size of burst 0, CSI2 part0. Valid range : [0:422399] */
        uint64_t preproc_p0_csi2_len1  : 19; /**< [234:216] Size of burst 1, CSI2 part0. Valid range : [0:422399] */
        uint64_t preproc_p0_csi2_len2  : 19; /**< [253:235] Size of burst 2, CSI2 part0. Valid range : [0:422399] */
        uint64_t reserved_254_255      : 2;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_319          : 1;
        uint64_t preproc_csi2_repeat_burst_size : 6;/**< [318:313] Burst size of CSI2 LLRs in each repeat of both part 0 and part 1.
                                                                 Valid range : [1,2,3,4,6,8,10,12,16,18,20,24,30,32,40] */
        uint64_t preproc_p1_csi2_len2  : 19; /**< [312:294] Size of burst 2, CSI2 part1. Valid range : [0:422399] */
        uint64_t preproc_p1_csi2_len1  : 19; /**< [293:275] Size of burst 1, CSI2 part1. Valid range : [0:422399] */
        uint64_t preproc_p1_csi2_len0  : 19; /**< [274:256] Size of burst 0, CSI2 part1. Valid range : [0:422399] */
#else /* Word 4 - Little Endian */
        uint64_t preproc_p1_csi2_len0  : 19; /**< [274:256] Size of burst 0, CSI2 part1. Valid range : [0:422399] */
        uint64_t preproc_p1_csi2_len1  : 19; /**< [293:275] Size of burst 1, CSI2 part1. Valid range : [0:422399] */
        uint64_t preproc_p1_csi2_len2  : 19; /**< [312:294] Size of burst 2, CSI2 part1. Valid range : [0:422399] */
        uint64_t preproc_csi2_repeat_burst_size : 6;/**< [318:313] Burst size of CSI2 LLRs in each repeat of both part 0 and part 1.
                                                                 Valid range : [1,2,3,4,6,8,10,12,16,18,20,24,30,32,40] */
        uint64_t reserved_319          : 1;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_382_383      : 2;
        uint64_t preproc_p0_num_repeat : 11; /**< [381:371] Number of periodic repetitions in part 0. Valid range : [0:2047] */
        uint64_t preproc_p1_data_len0  : 17; /**< [370:354] Size of burst 0, data part 1. Valid range : [0:105599] */
        uint64_t preproc_p0_data_len1  : 17; /**< [353:337] Size of burst 1, data part 0. Valid range : [0:105599] */
        uint64_t preproc_p0_data_len0  : 17; /**< [336:320] Size of burst 0, data part 0. Valid range : [0:105599] */
#else /* Word 5 - Little Endian */
        uint64_t preproc_p0_data_len0  : 17; /**< [336:320] Size of burst 0, data part 0. Valid range : [0:105599] */
        uint64_t preproc_p0_data_len1  : 17; /**< [353:337] Size of burst 1, data part 0. Valid range : [0:105599] */
        uint64_t preproc_p1_data_len0  : 17; /**< [370:354] Size of burst 0, data part 1. Valid range : [0:105599] */
        uint64_t preproc_p0_num_repeat : 11; /**< [381:371] Number of periodic repetitions in part 0. Valid range : [0:2047] */
        uint64_t reserved_382_383      : 2;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_444_447      : 4;
        uint64_t preproc_p1_num_repeat : 11; /**< [443:433] Number of periodic repetitions in part 1. Valid range : [0:2047] */
        uint64_t preproc_p1_csi2_repeat_period : 16;/**< [432:417] Periodicity of Repeated CSI2 LLRs followed by part 1 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents number of LLRs of each period. Valid range : [0:52800] */
        uint64_t preproc_p0_csi2_repeat_period : 16;/**< [416:401] Periodicity of Repeated CSI2 LLRs followed by part 0 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents number of LLRs of each period. Valid range : [0:52800] */
        uint64_t preproc_p1_data_len1  : 17; /**< [400:384] Size of burst 1, data part 1. Valid range : [0:105599] */
#else /* Word 6 - Little Endian */
        uint64_t preproc_p1_data_len1  : 17; /**< [400:384] Size of burst 1, data part 1. Valid range : [0:105599] */
        uint64_t preproc_p0_csi2_repeat_period : 16;/**< [416:401] Periodicity of Repeated CSI2 LLRs followed by part 0 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents number of LLRs of each period. Valid range : [0:52800] */
        uint64_t preproc_p1_csi2_repeat_period : 16;/**< [432:417] Periodicity of Repeated CSI2 LLRs followed by part 1 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents number of LLRs of each period. Valid range : [0:52800] */
        uint64_t preproc_p1_num_repeat : 11; /**< [443:433] Number of periodic repetitions in part 1. Valid range : [0:2047] */
        uint64_t reserved_444_447      : 4;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t preproc_num_rd_dma_words_p1 : 32;/**< [511:480] Number of read DMA words for part 1. Need to satisfy the constraint preproc_num_rd_dma_words_p0+
                                                                 preproc_num_rd_dma_words_p1 = num_rd0_dma_words Valid range : [0:10648] */
        uint64_t preproc_num_rd_dma_words_p0 : 32;/**< [479:448] Number of read DMA words for part 0. Need to satisfy the constraint preproc_num_rd_dma_words_p0+
                                                                 preproc_num_rd_dma_words_p1 = num_rd0_dma_words Valid range : [0:10648] */
#else /* Word 7 - Little Endian */
        uint64_t preproc_num_rd_dma_words_p0 : 32;/**< [479:448] Number of read DMA words for part 0. Need to satisfy the constraint preproc_num_rd_dma_words_p0+
                                                                 preproc_num_rd_dma_words_p1 = num_rd0_dma_words Valid range : [0:10648] */
        uint64_t preproc_num_rd_dma_words_p1 : 32;/**< [511:480] Number of read DMA words for part 1. Need to satisfy the constraint preproc_num_rd_dma_words_p0+
                                                                 preproc_num_rd_dma_words_p1 = num_rd0_dma_words Valid range : [0:10648] */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t num_rd1_dma_words     : 32; /**< [575:544] Number of 128-bit words read from Port1 input DMA. Valid range : [0:240768] */
        uint64_t num_rd0_dma_words     : 32; /**< [543:512] Number of 128-bit words read from Port0 input DMA. Valid range : [0:10648] */
#else /* Word 8 - Little Endian */
        uint64_t num_rd0_dma_words     : 32; /**< [543:512] Number of 128-bit words read from Port0 input DMA. Valid range : [0:10648] */
        uint64_t num_rd1_dma_words     : 32; /**< [575:544] Number of 128-bit words read from Port1 input DMA. Valid range : [0:240768] */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t num_wr1_dma_words     : 32; /**< [639:608] Number of 128-bit words written to Port1 output DMA. Valid range : [0:240768] */
        uint64_t num_wr0_dma_words     : 32; /**< [607:576] Number of 128-bit words written to Port0 output DMA. Valid range : [0:240768] */
#else /* Word 9 - Little Endian */
        uint64_t num_wr0_dma_words     : 32; /**< [607:576] Number of 128-bit words written to Port0 output DMA. Valid range : [0:240768] */
        uint64_t num_wr1_dma_words     : 32; /**< [639:608] Number of 128-bit words written to Port1 output DMA. Valid range : [0:240768] */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t num_wr3_dma_words     : 32; /**< [703:672] Number of 64-bit words written to Port3 output DMA. Valid range : [0:60192] */
        uint64_t num_wr2_dma_words     : 32; /**< [671:640] Number of 64-bit words written to Port2 output DMA. Valid range : [0:20064] */
#else /* Word 10 - Little Endian */
        uint64_t num_wr2_dma_words     : 32; /**< [671:640] Number of 64-bit words written to Port2 output DMA. Valid range : [0:20064] */
        uint64_t num_wr3_dma_words     : 32; /**< [703:672] Number of 64-bit words written to Port3 output DMA. Valid range : [0:60192] */
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
    __cavm_csr_fatal("LDECX_ABX_CONTROL", 2, a, b, 0, 0);
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
    __cavm_csr_fatal("LDECX_ABX_ECO", 2, a, b, 0, 0);
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
    __cavm_csr_fatal("LDECX_ABX_ERROR_ENABLE0", 2, a, b, 0, 0);
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
    __cavm_csr_fatal("LDECX_ABX_ERROR_ENABLE1", 2, a, b, 0, 0);
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
    __cavm_csr_fatal("LDECX_ABX_ERROR_SOURCE0", 2, a, b, 0, 0);
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
    __cavm_csr_fatal("LDECX_ABX_ERROR_SOURCE1", 2, a, b, 0, 0);
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
        uint64_t entry                 : 64; /**< [ 63:  0](R/W) JCFG0 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W) JCFG0 RAM CSRs */
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
    __cavm_csr_fatal("LDECX_ABX_HAB_JCFG0_RAMX_DATA", 3, a, b, c, 0);
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
        uint64_t entry                 : 64; /**< [ 63:  0](R/W) JCFG1 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W) JCFG1 RAM CSRs */
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
    __cavm_csr_fatal("LDECX_ABX_HAB_JCFG1_RAMX_DATA", 3, a, b, c, 0);
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
        uint64_t entry                 : 64; /**< [ 63:  0](R/W) JCFG2 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W) JCFG2 RAM CSRs */
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
    __cavm_csr_fatal("LDECX_ABX_HAB_JCFG2_RAMX_DATA", 3, a, b, c, 0);
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
    __cavm_csr_fatal("LDECX_ABX_SCRATCH", 2, a, b, 0, 0);
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
    __cavm_csr_fatal("LDECX_ABX_STATUS", 2, a, b, 0, 0);
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
        uint64_t entry                 : 64; /**< [ 63:  0](R/W) Config bits. */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W) Config bits. */
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
    __cavm_csr_fatal("LDECX_ABX_TC_CONFIGX", 3, a, b, c, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) cavm_ldecx_abx_tc_configx_t
#define bustype_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) "LDECX_ABX_TC_CONFIGX"
#define busnum_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) (a)
#define arguments_CAVM_LDECX_ABX_TC_CONFIGX(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) ldec#_ab#_tc_config_err_flags
 *
 * LDEC Task Confiuration Error Flags Register
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
    __cavm_csr_fatal("LDECX_ABX_TC_CONFIG_ERR_FLAGS", 2, a, b, 0, 0);
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
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) tc1830 static control inputs.
                                                                 [0] = clock gating disable.
                                                                 [1] = configuration check disable.
                                                                 [2] = wait until the core is idle until accepting the next task
                                                                       (degrades the throughput).
                                                                 [3] = wait until the core is idle until accepting the next task
                                                                       (degrades the throughput) in case of changing phy_mode.
                                                                 [4] = wait until the core is idle until accepting the next task
                                                                       (degrades the throughput) in case of changing channel_mode. */
#else /* Word 0 - Little Endian */
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) tc1830 static control inputs.
                                                                 [0] = clock gating disable.
                                                                 [1] = configuration check disable.
                                                                 [2] = wait until the core is idle until accepting the next task
                                                                       (degrades the throughput).
                                                                 [3] = wait until the core is idle until accepting the next task
                                                                       (degrades the throughput) in case of changing phy_mode.
                                                                 [4] = wait until the core is idle until accepting the next task
                                                                       (degrades the throughput) in case of changing channel_mode. */
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
    __cavm_csr_fatal("LDECX_ABX_TC_CONTROL", 2, a, b, 0, 0);
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
 * Errors are cleared by writing the specific error bits to zero.
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
        uint64_t inv_cfg               : 1;  /**< [  8:  8](R/W) Invalid task configuration -- aborted job. */
        uint64_t reserved_4_7          : 4;
        uint64_t ign_read              : 1;  /**< [  3:  3](R/W) Ignored a read access while another read was in process. */
        uint64_t inv_read              : 1;  /**< [  2:  2](R/W) Invalid read access to an out-of-range address. */
        uint64_t inv_write             : 1;  /**< [  1:  1](R/W) Invalid write access to an out-of-range address. */
        uint64_t inv_start             : 1;  /**< [  0:  0](R/W) Invalid task start. */
#else /* Word 0 - Little Endian */
        uint64_t inv_start             : 1;  /**< [  0:  0](R/W) Invalid task start. */
        uint64_t inv_write             : 1;  /**< [  1:  1](R/W) Invalid write access to an out-of-range address. */
        uint64_t inv_read              : 1;  /**< [  2:  2](R/W) Invalid read access to an out-of-range address. */
        uint64_t ign_read              : 1;  /**< [  3:  3](R/W) Ignored a read access while another read was in process. */
        uint64_t reserved_4_7          : 4;
        uint64_t inv_cfg               : 1;  /**< [  8:  8](R/W) Invalid task configuration -- aborted job. */
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
    __cavm_csr_fatal("LDECX_ABX_TC_ERROR", 2, a, b, 0, 0);
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
 * LDEC()_TC_ERROR will generate an error signal only when the
 * corresponding bit is set in LDEC()_TC_ERROR[ERR_MASK].
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
    __cavm_csr_fatal("LDECX_ABX_TC_ERROR_MASK", 2, a, b, 0, 0);
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
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W) Reset bit. */
#else /* Word 0 - Little Endian */
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W) Reset bit. */
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
    __cavm_csr_fatal("LDECX_ABX_TC_MAIN_RESET", 2, a, b, 0, 0);
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
        uint64_t start                 : 1;  /**< [  0:  0](R/W) Start bit. */
#else /* Word 0 - Little Endian */
        uint64_t start                 : 1;  /**< [  0:  0](R/W) Start bit. */
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
    __cavm_csr_fatal("LDECX_ABX_TC_MAIN_START", 2, a, b, 0, 0);
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
        uint64_t bus_val               : 64; /**< [ 63:  0](RO) tc1830 task output monitoring values.
                                                                 mon_reg0_bus = Identifier associated to the Q output interface. Valid when q_avl is HIGH.
                                                                 mon_reg1_bus = Identifier associated to the R output interface. Valid when r_avl is HIGH.
                                                                 mon_reg2_bus = Identifier associated to the S output interface. Valid when s_avl is HIGH.
                                                                 mon_reg3_bus = Identifier associated to the H output interface. Valid when h_avl is HIGH. */
#else /* Word 0 - Little Endian */
        uint64_t bus_val               : 64; /**< [ 63:  0](RO) tc1830 task output monitoring values.
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
    __cavm_csr_fatal("LDECX_ABX_TC_MONX", 3, a, b, c, 0);
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
        uint64_t monitor_bus           : 32; /**< [ 63: 32](RO) core dependent */
        uint64_t reserved_1_31         : 31;
        uint64_t idle                  : 1;  /**< [  0:  0](RO) Idle status bit. High means core is idle. */
#else /* Word 0 - Little Endian */
        uint64_t idle                  : 1;  /**< [  0:  0](RO) Idle status bit. High means core is idle. */
        uint64_t reserved_1_31         : 31;
        uint64_t monitor_bus           : 32; /**< [ 63: 32](RO) core dependent */
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
    __cavm_csr_fatal("LDECX_ABX_TC_STATUS", 2, a, b, 0, 0);
}

#define typedef_CAVM_LDECX_ABX_TC_STATUS(a,b) cavm_ldecx_abx_tc_status_t
#define bustype_CAVM_LDECX_ABX_TC_STATUS(a,b) CSR_TYPE_RSL
#define basename_CAVM_LDECX_ABX_TC_STATUS(a,b) "LDECX_ABX_TC_STATUS"
#define busnum_CAVM_LDECX_ABX_TC_STATUS(a,b) (a)
#define arguments_CAVM_LDECX_ABX_TC_STATUS(a,b) (a),(b),-1,-1

#endif /* __CAVM_CSRS_LDEC_H__ */
