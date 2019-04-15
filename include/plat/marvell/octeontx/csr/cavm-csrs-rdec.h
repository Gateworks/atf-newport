#ifndef __CAVM_CSRS_RDEC_H__
#define __CAVM_CSRS_RDEC_H__
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
 * OcteonTX RDEC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure rdec_common_cfg_s
 *
 * RDEC Common Configuration Parameters Structure
 * This structure defines the format for the job configuration for RDEC jobs.
 */
union cavm_rdec_common_cfg_s
{
    uint64_t u;
    struct cavm_rdec_common_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t data_byte_order       : 2;  /**< [ 53: 52] The byte order for the decoded output data.  See Baseband PHY (BPHY):
                                                                 Data Packing section for details. */
        uint64_t data_bit_order        : 1;  /**< [ 51: 51] The bit order for the decoded output data.  See Baseband PHY (BPHY):
                                                                 Data Packing section for details. */
        uint64_t num_reported_correlations : 3;/**< [ 50: 48] Number of best correlation outputs to be reported. Must be in range 1-4. */
        uint64_t reserved_46_47        : 2;
        uint64_t ue_dsp_report_size    : 5;  /**< [ 45: 41] The size of per UE DSP report in 128-bit words. */
        uint64_t rb_dsp_report_size    : 5;  /**< [ 40: 36] The size of per RB DSP report in 128-bit words. */
        uint64_t num_words_per_task_cnfg : 4;/**< [ 35: 32] Number of 128-bit words per task configuration. Must be set to 1. */
        uint64_t reserved_26_31        : 6;
        uint64_t num_data_words        : 10; /**< [ 25: 16] Number of 128-bit data words for this job. This should be the total
                                                                 size of all DSP reports and input LLRs read into the internal buffer.

                                                                 The total number of read DMA words for the job must equal
                                                                 [NUM_DATA_WORDS] + [NUM_BUNDLED_TASKS]. */
        uint64_t reserved_9_15         : 7;
        uint64_t num_bundled_tasks     : 9;  /**< [  8:  0] Number of tasks that are bundled in one job. */
#else /* Word 0 - Little Endian */
        uint64_t num_bundled_tasks     : 9;  /**< [  8:  0] Number of tasks that are bundled in one job. */
        uint64_t reserved_9_15         : 7;
        uint64_t num_data_words        : 10; /**< [ 25: 16] Number of 128-bit data words for this job. This should be the total
                                                                 size of all DSP reports and input LLRs read into the internal buffer.

                                                                 The total number of read DMA words for the job must equal
                                                                 [NUM_DATA_WORDS] + [NUM_BUNDLED_TASKS]. */
        uint64_t reserved_26_31        : 6;
        uint64_t num_words_per_task_cnfg : 4;/**< [ 35: 32] Number of 128-bit words per task configuration. Must be set to 1. */
        uint64_t rb_dsp_report_size    : 5;  /**< [ 40: 36] The size of per RB DSP report in 128-bit words. */
        uint64_t ue_dsp_report_size    : 5;  /**< [ 45: 41] The size of per UE DSP report in 128-bit words. */
        uint64_t reserved_46_47        : 2;
        uint64_t num_reported_correlations : 3;/**< [ 50: 48] Number of best correlation outputs to be reported. Must be in range 1-4. */
        uint64_t data_bit_order        : 1;  /**< [ 51: 51] The bit order for the decoded output data.  See Baseband PHY (BPHY):
                                                                 Data Packing section for details. */
        uint64_t data_byte_order       : 2;  /**< [ 53: 52] The byte order for the decoded output data.  See Baseband PHY (BPHY):
                                                                 Data Packing section for details. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdec_common_cfg_s_s cn; */
};

/**
 * Structure rdec_reenc_output_s
 *
 * RDEC Re-Encoded Output Structure
 * This structure specifies the format of the RDEC re-encoded output.
 * When a task is configured with RDEC_TASK_CFG_S[REENC_ENA] = 1, each RDEC
 * report (RDEC_REPORT_S) is followed by the re-encoded output specified
 * using this format.
 */
union cavm_rdec_reenc_output_s
{
    uint64_t u[2];
    struct cavm_rdec_reenc_output_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t second_reenc_out      : 32; /**< [ 63: 32] Re-encoded output from the second RM decoder. Only valid when the task
                                                                 configuration had RDEC_TASK_CFG_S[TASK_TYPE] = 4 or 6. */
        uint64_t first_reenc_out       : 32; /**< [ 31:  0] Re-encoded output from the first RM decoder. */
#else /* Word 0 - Little Endian */
        uint64_t first_reenc_out       : 32; /**< [ 31:  0] Re-encoded output from the first RM decoder. */
        uint64_t second_reenc_out      : 32; /**< [ 63: 32] Re-encoded output from the second RM decoder. Only valid when the task
                                                                 configuration had RDEC_TASK_CFG_S[TASK_TYPE] = 4 or 6. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_64_127       : 64;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64_127       : 64;
#endif /* Word 1 - End */
    } s;
    /* struct cavm_rdec_reenc_output_s_s cn; */
};

/**
 * Structure rdec_report_s
 *
 * RDEC Task Report Structure
 * This structure specifies the format of the RDEC report output. RDEC
 * produces one report for each of the best correlations, with the number of
 * correlations determined by
 * RDEC_COMMON_CFG_S[NUM_REPORTED_CORRELATIONS]. The M^th report output
 * contains details for the M^th best correlation, and when there are more
 * reports than possible decodings, any extra reports will set [DECODED_UCI]
 * and [BEST_CORR_0] to 0.
 */
union cavm_rdec_report_s
{
    uint64_t u[2];
    struct cavm_rdec_report_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_45_63        : 19;
        uint64_t best_corr_0           : 13; /**< [ 44: 32] The M^th best correlation output for the first RM decoding as a signed
                                                                 integer. */
        uint64_t decoded_uci           : 32; /**< [ 31:  0] The decoded UCI for this output. */
#else /* Word 0 - Little Endian */
        uint64_t decoded_uci           : 32; /**< [ 31:  0] The decoded UCI for this output. */
        uint64_t best_corr_0           : 13; /**< [ 44: 32] The M^th best correlation output for the first RM decoding as a signed
                                                                 integer. */
        uint64_t reserved_45_63        : 19;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t task_id               : 16; /**< [127:112] Per-task ID from RDEC_TASK_CFG_S[TASK_ID]. */
        uint64_t reserved_98_111       : 14;
        uint64_t harq_ack              : 2;  /**< [ 97: 96] The HARQ_ACK hypothesis index. Only valid for
                                                                 RDEC_TASK_CFG_S[TASK_TYPE] = 1 or 2:

                                                                 _ RDEC_TASK_CFG_S[TASK_TYPE] = 1 (Format 2a). [HARQ_ACK]\<0\> is the codeword index, and
                                                                 [HARQ_ACK]\<1\> is unused.

                                                                 _ RDEC_TASK_CFG_S[TASK_TYPE] = 2 (Format 2b). [HARQ_ACK]\<0\> is the index for codeword 1,
                                                                 and [HARQ_ACK]\<1\> is the index for codeword 0. */
        uint64_t reserved_77_95        : 19;
        uint64_t best_corr_1           : 13; /**< [ 76: 64] The M^th best correlation output for the second RM decoding as a
                                                                 signed integer. Only valid when the configuration had
                                                                 RDEC_TASK_CFG_S[TASK_TYPE] = 4 or 6. */
#else /* Word 1 - Little Endian */
        uint64_t best_corr_1           : 13; /**< [ 76: 64] The M^th best correlation output for the second RM decoding as a
                                                                 signed integer. Only valid when the configuration had
                                                                 RDEC_TASK_CFG_S[TASK_TYPE] = 4 or 6. */
        uint64_t reserved_77_95        : 19;
        uint64_t harq_ack              : 2;  /**< [ 97: 96] The HARQ_ACK hypothesis index. Only valid for
                                                                 RDEC_TASK_CFG_S[TASK_TYPE] = 1 or 2:

                                                                 _ RDEC_TASK_CFG_S[TASK_TYPE] = 1 (Format 2a). [HARQ_ACK]\<0\> is the codeword index, and
                                                                 [HARQ_ACK]\<1\> is unused.

                                                                 _ RDEC_TASK_CFG_S[TASK_TYPE] = 2 (Format 2b). [HARQ_ACK]\<0\> is the index for codeword 1,
                                                                 and [HARQ_ACK]\<1\> is the index for codeword 0. */
        uint64_t reserved_98_111       : 14;
        uint64_t task_id               : 16; /**< [127:112] Per-task ID from RDEC_TASK_CFG_S[TASK_ID]. */
#endif /* Word 1 - End */
    } s;
    /* struct cavm_rdec_report_s_s cn; */
};

/**
 * Structure rdec_task_cfg_s
 *
 * RDEC Task Configuration Structure
 * This structure is used to specify the configuration for an individual
 * RDEC task.  The task configurations are read by the RDEC via the
 * read DMA port, after all the LLR data is read.
 */
union cavm_rdec_task_cfg_s
{
    uint64_t u[2];
    struct cavm_rdec_task_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t word_offset1          : 10; /**< [ 57: 48] Offset to the beginning of the LLRs for antenna port 1 in the RDEC
                                                                 internal buffer. Specified in number of 128 bit words. This value is
                                                                 only valid if [TASK_TYPE] = 0..4 and [SORTD] = 1. */
        uint64_t reserved_42_47        : 6;
        uint64_t word_offset0          : 10; /**< [ 41: 32] Offset to the beginning of the LLRs for antenna port 0 in the RDEC
                                                                 internal buffer. Specified in number of 128 bit words. */
        uint64_t reserved_24_31        : 8;
        uint64_t nr_table_idx          : 3;  /**< [ 23: 21] General Mode table index for RM decoder.
                                                                 0 = LTE table
                                                                 1 = General Mode A table, configured via RDEC(0..1)_NR_S/MTBL_A
                                                                 2 = General Mode B table, configured via RDEC(0..1)_NR_S/MTBL_B
                                                                 3-7 = Reserved */
        uint64_t uci_bits              : 5;  /**< [ 20: 16] Number of UCI information bits to be decoded.
                                                                 In LTE mode, must meet the following limits.
                                                                 * [TASK_TYPE] = 0..2: [UCI_BITS] \<= 13.
                                                                 * [TASK_TYPE] = 3 or 5: [UCI_BITS] \<= 11.
                                                                 * [TASK_TYPE] = 4: [UCI_BITS] \<= 22.
                                                                 * [TASK_TYPE] = 6: [UCI_BITS] \<= 20.
                                                                 In general mode, must meet the following limits.
                                                                 * [TASK_TYPE] = 7: [UCI_BITS] \<= 13. */
        uint64_t reserved_14_15        : 2;
        uint64_t llr_negate            : 1;  /**< [ 13: 13] 1 = Enable LLR negation. 0 = Disable LLR negation.

                                                                 LLR negations should only be used when the input LLRs have been
                                                                 negated relative to the standard specification. */
        uint64_t rev_alt_concat        : 1;  /**< [ 12: 12] Enables reverse-alternate concatenation:
                                                                 0 = Disabled.
                                                                 1 = Enabled. Only valid for [TASK_TYPE] = 4. */
        uint64_t sortd_ena             : 1;  /**< [ 11: 11] Enables [SORTD] when set to 1. Must be set to 0 for [TASK_TYPE] = 5..7. */
        uint64_t num_hyp               : 3;  /**< [ 10:  8] Number of hypotheses. Only valid for [TASK_TYPE] = 1 or 2. Must be 1
                                                                 otherwise. */
        uint64_t num_streams           : 4;  /**< [  7:  4] Total number of input streams. Must be 1 unless [TASK_TYPE] = 5 or 6.
                                                                 Task types 5 and 6 support 1..8 streams (up to 4 layers with up to two
                                                                 streams each). */
        uint64_t task_type             : 3;  /**< [  3:  1] Describes the type of task based on the channel type and encoding
                                                                 format:
                                                                 0x0 = Format 2. Input LLRs have 3 words per stream.
                                                                 0x1 = Format 2a. Input LLRs have 5 words per stream.
                                                                 0x2 = Format 2b. Input LLRs have 10 words per stream.
                                                                 0x3 = Format 3 with single RM decoding ([UCI_BITS] \<= 11). Input LLRs
                                                                 have 6 words per stream.
                                                                 0x4 = Format 3 with double RM decoding ([UCI_BITS] \> 11). Input LLRs
                                                                 have 6 words per stream.
                                                                 0x5 = PUSCH UCI with single RM decoding ([UCI_BITS] \<= 11). Input LLRs
                                                                 have 4 words per stream.
                                                                 0x6 = PUSCH UCI with double RM decoding ([UCI_BITS] \> 11). Input LLRs
                                                                 have 8 words per stream.
                                                                 0x7 = General. */
        uint64_t op_mode               : 1;  /**< [  0:  0] Operation mode:
                                                                 0 = LTE mode.
                                                                 1 = General mode. */
#else /* Word 0 - Little Endian */
        uint64_t op_mode               : 1;  /**< [  0:  0] Operation mode:
                                                                 0 = LTE mode.
                                                                 1 = General mode. */
        uint64_t task_type             : 3;  /**< [  3:  1] Describes the type of task based on the channel type and encoding
                                                                 format:
                                                                 0x0 = Format 2. Input LLRs have 3 words per stream.
                                                                 0x1 = Format 2a. Input LLRs have 5 words per stream.
                                                                 0x2 = Format 2b. Input LLRs have 10 words per stream.
                                                                 0x3 = Format 3 with single RM decoding ([UCI_BITS] \<= 11). Input LLRs
                                                                 have 6 words per stream.
                                                                 0x4 = Format 3 with double RM decoding ([UCI_BITS] \> 11). Input LLRs
                                                                 have 6 words per stream.
                                                                 0x5 = PUSCH UCI with single RM decoding ([UCI_BITS] \<= 11). Input LLRs
                                                                 have 4 words per stream.
                                                                 0x6 = PUSCH UCI with double RM decoding ([UCI_BITS] \> 11). Input LLRs
                                                                 have 8 words per stream.
                                                                 0x7 = General. */
        uint64_t num_streams           : 4;  /**< [  7:  4] Total number of input streams. Must be 1 unless [TASK_TYPE] = 5 or 6.
                                                                 Task types 5 and 6 support 1..8 streams (up to 4 layers with up to two
                                                                 streams each). */
        uint64_t num_hyp               : 3;  /**< [ 10:  8] Number of hypotheses. Only valid for [TASK_TYPE] = 1 or 2. Must be 1
                                                                 otherwise. */
        uint64_t sortd_ena             : 1;  /**< [ 11: 11] Enables [SORTD] when set to 1. Must be set to 0 for [TASK_TYPE] = 5..7. */
        uint64_t rev_alt_concat        : 1;  /**< [ 12: 12] Enables reverse-alternate concatenation:
                                                                 0 = Disabled.
                                                                 1 = Enabled. Only valid for [TASK_TYPE] = 4. */
        uint64_t llr_negate            : 1;  /**< [ 13: 13] 1 = Enable LLR negation. 0 = Disable LLR negation.

                                                                 LLR negations should only be used when the input LLRs have been
                                                                 negated relative to the standard specification. */
        uint64_t reserved_14_15        : 2;
        uint64_t uci_bits              : 5;  /**< [ 20: 16] Number of UCI information bits to be decoded.
                                                                 In LTE mode, must meet the following limits.
                                                                 * [TASK_TYPE] = 0..2: [UCI_BITS] \<= 13.
                                                                 * [TASK_TYPE] = 3 or 5: [UCI_BITS] \<= 11.
                                                                 * [TASK_TYPE] = 4: [UCI_BITS] \<= 22.
                                                                 * [TASK_TYPE] = 6: [UCI_BITS] \<= 20.
                                                                 In general mode, must meet the following limits.
                                                                 * [TASK_TYPE] = 7: [UCI_BITS] \<= 13. */
        uint64_t nr_table_idx          : 3;  /**< [ 23: 21] General Mode table index for RM decoder.
                                                                 0 = LTE table
                                                                 1 = General Mode A table, configured via RDEC(0..1)_NR_S/MTBL_A
                                                                 2 = General Mode B table, configured via RDEC(0..1)_NR_S/MTBL_B
                                                                 3-7 = Reserved */
        uint64_t reserved_24_31        : 8;
        uint64_t word_offset0          : 10; /**< [ 41: 32] Offset to the beginning of the LLRs for antenna port 0 in the RDEC
                                                                 internal buffer. Specified in number of 128 bit words. */
        uint64_t reserved_42_47        : 6;
        uint64_t word_offset1          : 10; /**< [ 57: 48] Offset to the beginning of the LLRs for antenna port 1 in the RDEC
                                                                 internal buffer. Specified in number of 128 bit words. This value is
                                                                 only valid if [TASK_TYPE] = 0..4 and [SORTD] = 1. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t task_id               : 16; /**< [127:112] Per-task ID that is written to the report output. Each task in a job
                                                                 MUST specify a unique ID. */
        uint64_t reserved_106_111      : 6;
        uint64_t reenc_ena             : 1;  /**< [105:105] Enables RM re-encoding when set to 1. */
        uint64_t rb_rpt_incl1          : 1;  /**< [104:104] Per-RB report included in antenna port 1 input. This parameter is only

                                                                 used when [SORTD_ENA] = 1.  When set to 1, the first (RDEC_COMMON_CFG_S[UE_DSP_REPORT_SIZE]
                                                                 + RDEC_COMMON_CFG_S[RB_DSP_REPORT_SIZE]) words of the antenna port 1 input will be
                                                                 bypassed to the output to form the DSP report. If set to 0, only
                                                                 RDEC_COMMON_CFG_S[UE_DSP_REPORT_SIZE] words are bypassed. */
        uint64_t rb_rpt_incl0          : 1;  /**< [103:103] Per-RB report included in antenna port 0 input. When set to 1, the
                                                                 first (RDEC_COMMON_CFG_S[UE_DSP_REPORT_SIZE] +
                                                                 RDEC_COMMON_CFG_S[RB_DSP_REPORT_SIZE]) words of the antenna port 0
                                                                 input will be bypassed to the output to form the DSP report. If set to
                                                                 0, only RDEC_COMMON_CFG_S[UE_DSP_REPORT_SIZE] words are bypassed. */
        uint64_t double_rm_mode        : 1;  /**< [102:102] Selects the output format when double RM decoding is used (i.e., for
                                                                 [TASK_TYPE] = 4 and 6):
                                                                 0 = Concatenate two RM decoder outputs.
                                                                 1 = Interleave the two RM decoder outputs bit-by-bit (i.e. first
                                                                 decoder output maps to even bits, second decoder output maps to odd
                                                                 bits). */
        uint64_t llr_conv_lvl          : 4;  /**< [101: 98] Rounding level used when [LLR_CONV_MODE] = 0. Rounding is performed as
                                                                 follows:

                                                                 _ LLR \> 0: (LLR + (1 \<\< ([LLR_CONV_LVL]-1)) \>\> [LLR_CONV_LVL]

                                                                 _ LLR \< 0: (LLR + NEG((1 \<\< ([LLR_CONV_LVL]-1))) \>\> [LLR_CONV_LVL]

                                                                 The result is then saturated to 8 bits (symmetrically). */
        uint64_t llr_conv_mode         : 2;  /**< [ 97: 96] Determines how 18-bit LLRs are converted to 8-bit LLRs prior to
                                                                 decoding. Available LLR conversion modes are:
                                                                 0x0 = Use [LLR_CONV_LVL] as the rounding level.
                                                                 0x1 = Use rounding level derived from average of input LLRs.
                                                                 0x2 = Use rounding level derived from maximum input LLR.
                                                                 0x3 = Reserved.
                                                                 In all cases, the rounded LLRs are saturated to 8 bits. */
        uint64_t reserved_86_95        : 10;
        uint64_t mask                  : 22; /**< [ 85: 64] Bit-mask of known zeros in decoded bits. If S_i is zero, then bit i of
                                                                 the output is known to be zero and any non-conforming decoding
                                                                 candidates are discarded. Only the [UCI_BITS] most significant bits are
                                                                 used, and bits are numbered starting from the most significant bit,
                                                                 significant bit, i.e., S_i = [MASK]\<21-i\>.

                                                                 For [TASK_TYPE] = 4 or 6, the S_i bits for the two RM decodings
                                                                 are either concatenated or interleaved according to the value of
                                                                 [DOUBLE_RM_MODE]:

                                                                 * [DOUBLE_RM_MODE] = 0: The S_i bits for the two RM decodings
                                                                 are concatenated.  The first RM decoding uses S_i = [MASK]\<21-i\>,
                                                                 and the second RM decoding uses S_i = [MASK]\<21-[UCI_BITS]/2-i\>.

                                                                 * [DOUBLE_RM_MODE] = 1: The S_i bits for the two RM decodings
                                                                 are interleaved.  The first RM decoding uses S_i = [MASK]\<21-2i\>,
                                                                 and the second RM decoding uses S_i = [MASK]\<21-2i-1\>. */
#else /* Word 1 - Little Endian */
        uint64_t mask                  : 22; /**< [ 85: 64] Bit-mask of known zeros in decoded bits. If S_i is zero, then bit i of
                                                                 the output is known to be zero and any non-conforming decoding
                                                                 candidates are discarded. Only the [UCI_BITS] most significant bits are
                                                                 used, and bits are numbered starting from the most significant bit,
                                                                 significant bit, i.e., S_i = [MASK]\<21-i\>.

                                                                 For [TASK_TYPE] = 4 or 6, the S_i bits for the two RM decodings
                                                                 are either concatenated or interleaved according to the value of
                                                                 [DOUBLE_RM_MODE]:

                                                                 * [DOUBLE_RM_MODE] = 0: The S_i bits for the two RM decodings
                                                                 are concatenated.  The first RM decoding uses S_i = [MASK]\<21-i\>,
                                                                 and the second RM decoding uses S_i = [MASK]\<21-[UCI_BITS]/2-i\>.

                                                                 * [DOUBLE_RM_MODE] = 1: The S_i bits for the two RM decodings
                                                                 are interleaved.  The first RM decoding uses S_i = [MASK]\<21-2i\>,
                                                                 and the second RM decoding uses S_i = [MASK]\<21-2i-1\>. */
        uint64_t reserved_86_95        : 10;
        uint64_t llr_conv_mode         : 2;  /**< [ 97: 96] Determines how 18-bit LLRs are converted to 8-bit LLRs prior to
                                                                 decoding. Available LLR conversion modes are:
                                                                 0x0 = Use [LLR_CONV_LVL] as the rounding level.
                                                                 0x1 = Use rounding level derived from average of input LLRs.
                                                                 0x2 = Use rounding level derived from maximum input LLR.
                                                                 0x3 = Reserved.
                                                                 In all cases, the rounded LLRs are saturated to 8 bits. */
        uint64_t llr_conv_lvl          : 4;  /**< [101: 98] Rounding level used when [LLR_CONV_MODE] = 0. Rounding is performed as
                                                                 follows:

                                                                 _ LLR \> 0: (LLR + (1 \<\< ([LLR_CONV_LVL]-1)) \>\> [LLR_CONV_LVL]

                                                                 _ LLR \< 0: (LLR + NEG((1 \<\< ([LLR_CONV_LVL]-1))) \>\> [LLR_CONV_LVL]

                                                                 The result is then saturated to 8 bits (symmetrically). */
        uint64_t double_rm_mode        : 1;  /**< [102:102] Selects the output format when double RM decoding is used (i.e., for
                                                                 [TASK_TYPE] = 4 and 6):
                                                                 0 = Concatenate two RM decoder outputs.
                                                                 1 = Interleave the two RM decoder outputs bit-by-bit (i.e. first
                                                                 decoder output maps to even bits, second decoder output maps to odd
                                                                 bits). */
        uint64_t rb_rpt_incl0          : 1;  /**< [103:103] Per-RB report included in antenna port 0 input. When set to 1, the
                                                                 first (RDEC_COMMON_CFG_S[UE_DSP_REPORT_SIZE] +
                                                                 RDEC_COMMON_CFG_S[RB_DSP_REPORT_SIZE]) words of the antenna port 0
                                                                 input will be bypassed to the output to form the DSP report. If set to
                                                                 0, only RDEC_COMMON_CFG_S[UE_DSP_REPORT_SIZE] words are bypassed. */
        uint64_t rb_rpt_incl1          : 1;  /**< [104:104] Per-RB report included in antenna port 1 input. This parameter is only

                                                                 used when [SORTD_ENA] = 1.  When set to 1, the first (RDEC_COMMON_CFG_S[UE_DSP_REPORT_SIZE]
                                                                 + RDEC_COMMON_CFG_S[RB_DSP_REPORT_SIZE]) words of the antenna port 1 input will be
                                                                 bypassed to the output to form the DSP report. If set to 0, only
                                                                 RDEC_COMMON_CFG_S[UE_DSP_REPORT_SIZE] words are bypassed. */
        uint64_t reenc_ena             : 1;  /**< [105:105] Enables RM re-encoding when set to 1. */
        uint64_t reserved_106_111      : 6;
        uint64_t task_id               : 16; /**< [127:112] Per-task ID that is written to the report output. Each task in a job
                                                                 MUST specify a unique ID. */
#endif /* Word 1 - End */
    } s;
    /* struct cavm_rdec_task_cfg_s_s cn; */
};

/**
 * Register (RSL) rdec#_configuration
 *
 * RDEC CONFIGURATION Register
 * This register space contains the RDEC job configuration data.
 *
 * Software should not write this register directly, but instead use this
 * format when writing the job configuration section of the job descriptor.
 */
union cavm_rdecx_configuration
{
    uint64_t u;
    struct cavm_rdecx_configuration_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t data_byte_order       : 2;  /**< [ 53: 52](R/W) 0: DATA_BYTE_ORDER_MODE_0
                                                                 1: DATA_BYTE_ORDER_MODE_1
                                                                 2: DATA_BYTE_ORDER_MODE_2 */
        uint64_t data_bit_order        : 1;  /**< [ 51: 51](R/W) 0: DATA_BIT_MSB_FIRST
                                                                 1: DATA_BIT_LSB_FIRST */
        uint64_t num_reported_correlations : 3;/**< [ 50: 48](R/W) Number of best correlation outputs to be reported. Must be in rage 1-4. */
        uint64_t reserved_46_47        : 2;
        uint64_t ue_dsp_report_size    : 5;  /**< [ 45: 41](R/W) The size of per UE DSP report in 128-bit words. */
        uint64_t rb_dsp_report_size    : 5;  /**< [ 40: 36](R/W) The size of per RB DSP report in 128-bit words. */
        uint64_t num_words_per_task_cnfg : 4;/**< [ 35: 32](R/W) Number of 128-bit words per task configuration. Must be set to 1. */
        uint64_t reserved_26_31        : 6;
        uint64_t num_data_words        : 10; /**< [ 25: 16](R/W) Number of 128-bit data words for this job. This should be the total
                                                                 size of all DSP reports and input LLRs read into the internal buffer.

                                                                 The total number of read DMA words for the job must equal
                                                                 [NUM_DATA_WORDS] + [NUM_BUNDLED_TASKS]. */
        uint64_t reserved_9_15         : 7;
        uint64_t num_bundled_tasks     : 9;  /**< [  8:  0](R/W) Number of tasks that are bundled in one job. */
#else /* Word 0 - Little Endian */
        uint64_t num_bundled_tasks     : 9;  /**< [  8:  0](R/W) Number of tasks that are bundled in one job. */
        uint64_t reserved_9_15         : 7;
        uint64_t num_data_words        : 10; /**< [ 25: 16](R/W) Number of 128-bit data words for this job. This should be the total
                                                                 size of all DSP reports and input LLRs read into the internal buffer.

                                                                 The total number of read DMA words for the job must equal
                                                                 [NUM_DATA_WORDS] + [NUM_BUNDLED_TASKS]. */
        uint64_t reserved_26_31        : 6;
        uint64_t num_words_per_task_cnfg : 4;/**< [ 35: 32](R/W) Number of 128-bit words per task configuration. Must be set to 1. */
        uint64_t rb_dsp_report_size    : 5;  /**< [ 40: 36](R/W) The size of per RB DSP report in 128-bit words. */
        uint64_t ue_dsp_report_size    : 5;  /**< [ 45: 41](R/W) The size of per UE DSP report in 128-bit words. */
        uint64_t reserved_46_47        : 2;
        uint64_t num_reported_correlations : 3;/**< [ 50: 48](R/W) Number of best correlation outputs to be reported. Must be in rage 1-4. */
        uint64_t data_bit_order        : 1;  /**< [ 51: 51](R/W) 0: DATA_BIT_MSB_FIRST
                                                                 1: DATA_BIT_LSB_FIRST */
        uint64_t data_byte_order       : 2;  /**< [ 53: 52](R/W) 0: DATA_BYTE_ORDER_MODE_0
                                                                 1: DATA_BYTE_ORDER_MODE_1
                                                                 2: DATA_BYTE_ORDER_MODE_2 */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_configuration_s cn; */
};
typedef union cavm_rdecx_configuration cavm_rdecx_configuration_t;

static inline uint64_t CAVM_RDECX_CONFIGURATION(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_CONFIGURATION(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043102000ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("RDECX_CONFIGURATION", 1, a, 0, 0, 0);
}

#define typedef_CAVM_RDECX_CONFIGURATION(a) cavm_rdecx_configuration_t
#define bustype_CAVM_RDECX_CONFIGURATION(a) CSR_TYPE_RSL
#define basename_CAVM_RDECX_CONFIGURATION(a) "RDECX_CONFIGURATION"
#define busnum_CAVM_RDECX_CONFIGURATION(a) (a)
#define arguments_CAVM_RDECX_CONFIGURATION(a) (a),-1,-1,-1

/**
 * Register (RSL) rdec#_control
 *
 * RDEC_CONTROL Register
 * This register is used to start RDEC HAB processing.
 */
union cavm_rdecx_control
{
    uint64_t u;
    struct cavm_rdecx_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t jobid                 : 16; /**< [ 31: 16](R/W/H) Job ID0 */
        uint64_t reserved_1_15         : 15;
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 RDEC()_CONFIGURATION. This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (RDEC()_STATUS[STATUS0] = 1). */
#else /* Word 0 - Little Endian */
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 RDEC()_CONFIGURATION. This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (RDEC()_STATUS[STATUS0] = 1). */
        uint64_t reserved_1_15         : 15;
        uint64_t jobid                 : 16; /**< [ 31: 16](R/W/H) Job ID0 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_control_s cn; */
};
typedef union cavm_rdecx_control cavm_rdecx_control_t;

static inline uint64_t CAVM_RDECX_CONTROL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_CONTROL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043100000ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("RDECX_CONTROL", 1, a, 0, 0, 0);
}

#define typedef_CAVM_RDECX_CONTROL(a) cavm_rdecx_control_t
#define bustype_CAVM_RDECX_CONTROL(a) CSR_TYPE_RSL
#define basename_CAVM_RDECX_CONTROL(a) "RDECX_CONTROL"
#define busnum_CAVM_RDECX_CONTROL(a) (a)
#define arguments_CAVM_RDECX_CONTROL(a) (a),-1,-1,-1

/**
 * Register (RSL) rdec#_eco
 *
 * INTERNAL: RDEC ECO Register
 */
union cavm_rdecx_eco
{
    uint64_t u;
    struct cavm_rdecx_eco_s
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
    /* struct cavm_rdecx_eco_s cn; */
};
typedef union cavm_rdecx_eco cavm_rdecx_eco_t;

static inline uint64_t CAVM_RDECX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_ECO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043100008ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("RDECX_ECO", 1, a, 0, 0, 0);
}

#define typedef_CAVM_RDECX_ECO(a) cavm_rdecx_eco_t
#define bustype_CAVM_RDECX_ECO(a) CSR_TYPE_RSL
#define basename_CAVM_RDECX_ECO(a) "RDECX_ECO"
#define busnum_CAVM_RDECX_ECO(a) (a)
#define arguments_CAVM_RDECX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) rdec#_error_enable0
 *
 * RDEC Error Enable 0 Register
 * This register enables error reporting for RDEC_ERROR_SOURCE0 register.
 */
union cavm_rdecx_error_enable0
{
    uint64_t u;
    struct cavm_rdecx_error_enable0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t rp0_of_en             : 1;  /**< [  1:  1](R/W) Read port 0 overflow enable. */
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W) Read port 0 underflow enable. */
#else /* Word 0 - Little Endian */
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W) Read port 0 underflow enable. */
        uint64_t rp0_of_en             : 1;  /**< [  1:  1](R/W) Read port 0 overflow enable. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_error_enable0_s cn; */
};
typedef union cavm_rdecx_error_enable0 cavm_rdecx_error_enable0_t;

static inline uint64_t CAVM_RDECX_ERROR_ENABLE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_ERROR_ENABLE0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043100040ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("RDECX_ERROR_ENABLE0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_RDECX_ERROR_ENABLE0(a) cavm_rdecx_error_enable0_t
#define bustype_CAVM_RDECX_ERROR_ENABLE0(a) CSR_TYPE_RSL
#define basename_CAVM_RDECX_ERROR_ENABLE0(a) "RDECX_ERROR_ENABLE0"
#define busnum_CAVM_RDECX_ERROR_ENABLE0(a) (a)
#define arguments_CAVM_RDECX_ERROR_ENABLE0(a) (a),-1,-1,-1

/**
 * Register (RSL) rdec#_error_source0
 *
 * RDEC Error Source Register 0
 * This register reports the source of read DMA overflow/underflow errors.
 */
union cavm_rdecx_error_source0
{
    uint64_t u;
    struct cavm_rdecx_error_source0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t rp0_jobid             : 16; /**< [ 31: 16](RO/H) Job ID for read port 0 overflow/underflow. */
        uint64_t reserved_5_15         : 11;
        uint64_t rp0_of                : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_uf                : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
#else /* Word 0 - Little Endian */
        uint64_t rp0_uf                : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_of                : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t reserved_5_15         : 11;
        uint64_t rp0_jobid             : 16; /**< [ 31: 16](RO/H) Job ID for read port 0 overflow/underflow. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_error_source0_s cn; */
};
typedef union cavm_rdecx_error_source0 cavm_rdecx_error_source0_t;

static inline uint64_t CAVM_RDECX_ERROR_SOURCE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_ERROR_SOURCE0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043100030ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("RDECX_ERROR_SOURCE0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_RDECX_ERROR_SOURCE0(a) cavm_rdecx_error_source0_t
#define bustype_CAVM_RDECX_ERROR_SOURCE0(a) CSR_TYPE_RSL
#define basename_CAVM_RDECX_ERROR_SOURCE0(a) "RDECX_ERROR_SOURCE0"
#define busnum_CAVM_RDECX_ERROR_SOURCE0(a) (a)
#define arguments_CAVM_RDECX_ERROR_SOURCE0(a) (a),-1,-1,-1

/**
 * Register (RSL) rdec#_nr_mtbl_a#
 *
 * RDEC MASK TABLE A Register
 * This register space contains the RDEC general mode mask table A.
 *
 * Software should write this register directly.
 */
union cavm_rdecx_nr_mtbl_ax
{
    uint64_t u;
    struct cavm_rdecx_nr_mtbl_ax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t mask_table_entry      : 32; /**< [ 31:  0](R/W) Mask table entry corresponding to the register index. */
#else /* Word 0 - Little Endian */
        uint64_t mask_table_entry      : 32; /**< [ 31:  0](R/W) Mask table entry corresponding to the register index. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_nr_mtbl_ax_s cn; */
};
typedef union cavm_rdecx_nr_mtbl_ax cavm_rdecx_nr_mtbl_ax_t;

static inline uint64_t CAVM_RDECX_NR_MTBL_AX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_NR_MTBL_AX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=127)))
        return 0x87e043103000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x7f);
    __cavm_csr_fatal("RDECX_NR_MTBL_AX", 2, a, b, 0, 0);
}

#define typedef_CAVM_RDECX_NR_MTBL_AX(a,b) cavm_rdecx_nr_mtbl_ax_t
#define bustype_CAVM_RDECX_NR_MTBL_AX(a,b) CSR_TYPE_RSL
#define basename_CAVM_RDECX_NR_MTBL_AX(a,b) "RDECX_NR_MTBL_AX"
#define busnum_CAVM_RDECX_NR_MTBL_AX(a,b) (a)
#define arguments_CAVM_RDECX_NR_MTBL_AX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) rdec#_nr_mtbl_b#
 *
 * RDEC MASK TABLE B Register
 * This register space contains the RDEC general mode mask table B.
 *
 * Software should write this register directly.
 */
union cavm_rdecx_nr_mtbl_bx
{
    uint64_t u;
    struct cavm_rdecx_nr_mtbl_bx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t mask_table_entry      : 32; /**< [ 31:  0](R/W) Mask table entry corresponding to the register index. */
#else /* Word 0 - Little Endian */
        uint64_t mask_table_entry      : 32; /**< [ 31:  0](R/W) Mask table entry corresponding to the register index. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_nr_mtbl_bx_s cn; */
};
typedef union cavm_rdecx_nr_mtbl_bx cavm_rdecx_nr_mtbl_bx_t;

static inline uint64_t CAVM_RDECX_NR_MTBL_BX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_NR_MTBL_BX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=127)))
        return 0x87e043103400ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x7f);
    __cavm_csr_fatal("RDECX_NR_MTBL_BX", 2, a, b, 0, 0);
}

#define typedef_CAVM_RDECX_NR_MTBL_BX(a,b) cavm_rdecx_nr_mtbl_bx_t
#define bustype_CAVM_RDECX_NR_MTBL_BX(a,b) CSR_TYPE_RSL
#define basename_CAVM_RDECX_NR_MTBL_BX(a,b) "RDECX_NR_MTBL_BX"
#define busnum_CAVM_RDECX_NR_MTBL_BX(a,b) (a)
#define arguments_CAVM_RDECX_NR_MTBL_BX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) rdec#_nr_rtbl_a#
 *
 * RDEC RE-ENCODING TABLE A Register
 * This register space contains the RDEC general mode re-encoding table table A.
 *
 * Software should write this register directly.
 */
union cavm_rdecx_nr_rtbl_ax
{
    uint64_t u;
    struct cavm_rdecx_nr_rtbl_ax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t table_entry           : 13; /**< [ 12:  0](R/W) Re-encoding table entry corresponding to the register index. */
#else /* Word 0 - Little Endian */
        uint64_t table_entry           : 13; /**< [ 12:  0](R/W) Re-encoding table entry corresponding to the register index. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_nr_rtbl_ax_s cn; */
};
typedef union cavm_rdecx_nr_rtbl_ax cavm_rdecx_nr_rtbl_ax_t;

static inline uint64_t CAVM_RDECX_NR_RTBL_AX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_NR_RTBL_AX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=31)))
        return 0x87e043104000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1f);
    __cavm_csr_fatal("RDECX_NR_RTBL_AX", 2, a, b, 0, 0);
}

#define typedef_CAVM_RDECX_NR_RTBL_AX(a,b) cavm_rdecx_nr_rtbl_ax_t
#define bustype_CAVM_RDECX_NR_RTBL_AX(a,b) CSR_TYPE_RSL
#define basename_CAVM_RDECX_NR_RTBL_AX(a,b) "RDECX_NR_RTBL_AX"
#define busnum_CAVM_RDECX_NR_RTBL_AX(a,b) (a)
#define arguments_CAVM_RDECX_NR_RTBL_AX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) rdec#_nr_rtbl_b#
 *
 * RDEC RE-ENCODING TABLE B Register
 * This register space contains the RDEC general mode re-encoding table B.
 *
 * Software should write this register directly.
 */
union cavm_rdecx_nr_rtbl_bx
{
    uint64_t u;
    struct cavm_rdecx_nr_rtbl_bx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t table_entry           : 13; /**< [ 12:  0](R/W) Re-encoding table entry corresponding to the register index. */
#else /* Word 0 - Little Endian */
        uint64_t table_entry           : 13; /**< [ 12:  0](R/W) Re-encoding table entry corresponding to the register index. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_nr_rtbl_bx_s cn; */
};
typedef union cavm_rdecx_nr_rtbl_bx cavm_rdecx_nr_rtbl_bx_t;

static inline uint64_t CAVM_RDECX_NR_RTBL_BX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_NR_RTBL_BX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=31)))
        return 0x87e043104400ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1f);
    __cavm_csr_fatal("RDECX_NR_RTBL_BX", 2, a, b, 0, 0);
}

#define typedef_CAVM_RDECX_NR_RTBL_BX(a,b) cavm_rdecx_nr_rtbl_bx_t
#define bustype_CAVM_RDECX_NR_RTBL_BX(a,b) CSR_TYPE_RSL
#define basename_CAVM_RDECX_NR_RTBL_BX(a,b) "RDECX_NR_RTBL_BX"
#define busnum_CAVM_RDECX_NR_RTBL_BX(a,b) (a)
#define arguments_CAVM_RDECX_NR_RTBL_BX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) rdec#_nr_stbl_a#
 *
 * RDEC SHIFT TABLE A Register
 * This register space contains the RDEC general mode shift table A.
 *
 * Software should write this register directly.
 */
union cavm_rdecx_nr_stbl_ax
{
    uint64_t u;
    struct cavm_rdecx_nr_stbl_ax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t shift_table_entry     : 5;  /**< [  4:  0](R/W) Shift table entry corresponding to the register index. */
#else /* Word 0 - Little Endian */
        uint64_t shift_table_entry     : 5;  /**< [  4:  0](R/W) Shift table entry corresponding to the register index. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_nr_stbl_ax_s cn; */
};
typedef union cavm_rdecx_nr_stbl_ax cavm_rdecx_nr_stbl_ax_t;

static inline uint64_t CAVM_RDECX_NR_STBL_AX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_NR_STBL_AX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=31)))
        return 0x87e043103800ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1f);
    __cavm_csr_fatal("RDECX_NR_STBL_AX", 2, a, b, 0, 0);
}

#define typedef_CAVM_RDECX_NR_STBL_AX(a,b) cavm_rdecx_nr_stbl_ax_t
#define bustype_CAVM_RDECX_NR_STBL_AX(a,b) CSR_TYPE_RSL
#define basename_CAVM_RDECX_NR_STBL_AX(a,b) "RDECX_NR_STBL_AX"
#define busnum_CAVM_RDECX_NR_STBL_AX(a,b) (a)
#define arguments_CAVM_RDECX_NR_STBL_AX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) rdec#_nr_stbl_b#
 *
 * RDEC SHIFT TABLE B Register
 * This register space contains the RDEC general mode shift table B.
 *
 * Software should write this register directly.
 */
union cavm_rdecx_nr_stbl_bx
{
    uint64_t u;
    struct cavm_rdecx_nr_stbl_bx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t shift_table_entry     : 5;  /**< [  4:  0](R/W) Shift table entry corresponding to the register index. */
#else /* Word 0 - Little Endian */
        uint64_t shift_table_entry     : 5;  /**< [  4:  0](R/W) Shift table entry corresponding to the register index. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_nr_stbl_bx_s cn; */
};
typedef union cavm_rdecx_nr_stbl_bx cavm_rdecx_nr_stbl_bx_t;

static inline uint64_t CAVM_RDECX_NR_STBL_BX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_NR_STBL_BX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=31)))
        return 0x87e043103c00ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x1f);
    __cavm_csr_fatal("RDECX_NR_STBL_BX", 2, a, b, 0, 0);
}

#define typedef_CAVM_RDECX_NR_STBL_BX(a,b) cavm_rdecx_nr_stbl_bx_t
#define bustype_CAVM_RDECX_NR_STBL_BX(a,b) CSR_TYPE_RSL
#define basename_CAVM_RDECX_NR_STBL_BX(a,b) "RDECX_NR_STBL_BX"
#define busnum_CAVM_RDECX_NR_STBL_BX(a,b) (a)
#define arguments_CAVM_RDECX_NR_STBL_BX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) rdec#_scratch
 *
 * INTERNAL: Scratch Registers
 *
 * Scratch register.
 */
union cavm_rdecx_scratch
{
    uint64_t u;
    struct cavm_rdecx_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_scratch_s cn; */
};
typedef union cavm_rdecx_scratch cavm_rdecx_scratch_t;

static inline uint64_t CAVM_RDECX_SCRATCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_SCRATCH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043100080ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("RDECX_SCRATCH", 1, a, 0, 0, 0);
}

#define typedef_CAVM_RDECX_SCRATCH(a) cavm_rdecx_scratch_t
#define bustype_CAVM_RDECX_SCRATCH(a) CSR_TYPE_RSL
#define basename_CAVM_RDECX_SCRATCH(a) "RDECX_SCRATCH"
#define busnum_CAVM_RDECX_SCRATCH(a) (a)
#define arguments_CAVM_RDECX_SCRATCH(a) (a),-1,-1,-1

/**
 * Register (RSL) rdec#_status
 *
 * RDEC Status Register
 * RDEC Status Register.
 */
union cavm_rdecx_status
{
    uint64_t u;
    struct cavm_rdecx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, indicates the RDEC HAB is ready to receive next job. */
        uint64_t reserved_1_3          : 3;
        uint64_t status0               : 1;  /**< [  0:  0](RO/H) When set, indicates the RDEC HAB is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t status0               : 1;  /**< [  0:  0](RO/H) When set, indicates the RDEC HAB is busy processing a job. */
        uint64_t reserved_1_3          : 3;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, indicates the RDEC HAB is ready to receive next job. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rdecx_status_s cn; */
};
typedef union cavm_rdecx_status cavm_rdecx_status_t;

static inline uint64_t CAVM_RDECX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RDECX_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043100018ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("RDECX_STATUS", 1, a, 0, 0, 0);
}

#define typedef_CAVM_RDECX_STATUS(a) cavm_rdecx_status_t
#define bustype_CAVM_RDECX_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_RDECX_STATUS(a) "RDECX_STATUS"
#define busnum_CAVM_RDECX_STATUS(a) (a)
#define arguments_CAVM_RDECX_STATUS(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_RDEC_H__ */
