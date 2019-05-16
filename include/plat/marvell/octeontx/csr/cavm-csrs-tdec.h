#ifndef __CAVM_CSRS_TDEC_H__
#define __CAVM_CSRS_TDEC_H__
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
 * OcteonTX TDEC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure tdec_common_cfg_s
 *
 * TDEC Common Configuration Structure
 * This structure defines the first word of the job configuration for all
 * TDEC jobs.
 */
union cavm_tdec_common_cfg_s
{
    uint64_t u;
    struct cavm_tdec_common_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t cfg_wrds_per_task     : 8;  /**< [ 31: 24] The number of job configuration words for each task. This field must
                                                                 be set to 0x8. */
        uint64_t reserved_21_23        : 3;
        uint64_t task_type             : 3;  /**< [ 20: 18] Task type:
                                                                 0x0 = LTE.
                                                                 0x1 - 0x3 = Reserved. */
        uint64_t phy_mode              : 2;  /**< [ 17: 16] PHY mode:
                                                                 0x0 = LTE.
                                                                 0x1 - 0x3 = Reserved. */
        uint64_t reserved_5_15         : 11;
        uint64_t num_tasks             : 5;  /**< [  4:  0] The number of tasks in this job. Must be in the range [0x1, 0x10]. */
#else /* Word 0 - Little Endian */
        uint64_t num_tasks             : 5;  /**< [  4:  0] The number of tasks in this job. Must be in the range [0x1, 0x10]. */
        uint64_t reserved_5_15         : 11;
        uint64_t phy_mode              : 2;  /**< [ 17: 16] PHY mode:
                                                                 0x0 = LTE.
                                                                 0x1 - 0x3 = Reserved. */
        uint64_t task_type             : 3;  /**< [ 20: 18] Task type:
                                                                 0x0 = LTE.
                                                                 0x1 - 0x3 = Reserved. */
        uint64_t reserved_21_23        : 3;
        uint64_t cfg_wrds_per_task     : 8;  /**< [ 31: 24] The number of job configuration words for each task. This field must
                                                                 be set to 0x8. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdec_common_cfg_s_s cn; */
};

/**
 * Structure tdec_harq_hdr_s
 *
 * TDEC HARQ Header Structure
 * This structure defines the HARQ header which is included as the first word
 * of HARQ output, and which must be used as the first word of the
 * HARQ input.
 */
union cavm_tdec_harq_hdr_s
{
    uint64_t u[2];
    struct cavm_tdec_harq_hdr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t hc_e                  : 20; /**< [ 51: 32] Number of HARQ LLRs in the input/output. */
        uint64_t reserved_23_31        : 9;
        uint64_t hc_k0_div_r           : 7;  /**< [ 22: 16] Offset column k0/R, where R = number of rows. Valid range is [0x0, 0x5F]. */
        uint64_t hc_k0_p               : 16; /**< [ 15:  0] Offset in the pruned virtual circular buffer. */
#else /* Word 0 - Little Endian */
        uint64_t hc_k0_p               : 16; /**< [ 15:  0] Offset in the pruned virtual circular buffer. */
        uint64_t hc_k0_div_r           : 7;  /**< [ 22: 16] Offset column k0/R, where R = number of rows. Valid range is [0x0, 0x5F]. */
        uint64_t reserved_23_31        : 9;
        uint64_t hc_e                  : 20; /**< [ 51: 32] Number of HARQ LLRs in the input/output. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_84_127       : 44;
        uint64_t hc_length             : 20; /**< [ 83: 64] Number of bytes in the HARQ input stream, including the 16 byte
                                                                 header, i.e., [HC_LENGTH] = 16 + [HC_E]. */
#else /* Word 1 - Little Endian */
        uint64_t hc_length             : 20; /**< [ 83: 64] Number of bytes in the HARQ input stream, including the 16 byte
                                                                 header, i.e., [HC_LENGTH] = 16 + [HC_E]. */
        uint64_t reserved_84_127       : 44;
#endif /* Word 1 - End */
    } s;
    /* struct cavm_tdec_harq_hdr_s_s cn; */
};

/**
 * Structure tdec_lte_report_s
 *
 * TDEC LTE Report Structure
 * This structure defines the report output for LTE jobs. For each task, this
 * report is appended to the output on either port 1 or port 2.
 *
 * __ When TDEC_LTE_TASK_CFG_S[HD_OUT_ENA] = 1, this report is appended to the
 * hard output written to port 2.
 *
 * __ When TDEC_LTE_TASK_CFG_S[HD_OUT_ENA] = 0 and
 * TDEC_LTE_TASK_CFG_S[SO_ENA] = 1, this report is appended to
 * the soft-bit output written to port 1.
 *
 * __ If both soft output and decoded output are disabled, then no report is
 * produced.
 */
union cavm_tdec_lte_report_s
{
    uint64_t u[4];
    struct cavm_tdec_lte_report_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tb_crc_calc           : 24; /**< [ 63: 40] The calculated transport block CRC. This field is valid only when
                                                                 [BYPS_TB_PROC] = 0. */
        uint64_t tb_crc_decoded        : 24; /**< [ 39: 16] The decoded transport block CRC. This field is valid only when
                                                                 [BYPS_TB_PROC] = 0. Note that the CRC is removed from the
                                                                 decoded output. */
        uint64_t task_id               : 16; /**< [ 15:  0] The task ID specified in the job configuration. */
#else /* Word 0 - Little Endian */
        uint64_t task_id               : 16; /**< [ 15:  0] The task ID specified in the job configuration. */
        uint64_t tb_crc_decoded        : 24; /**< [ 39: 16] The decoded transport block CRC. This field is valid only when
                                                                 [BYPS_TB_PROC] = 0. Note that the CRC is removed from the
                                                                 decoded output. */
        uint64_t tb_crc_calc           : 24; /**< [ 63: 40] The calculated transport block CRC. This field is valid only when
                                                                 [BYPS_TB_PROC] = 0. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_122_127      : 6;
        uint64_t max_half_it           : 6;  /**< [121:116] The maximum number of half-iterations performed for any one code
                                                                 block. */
        uint64_t cber                  : 20; /**< [115: 96] The cumulative bit error rate estimate across all code blocks. The BER
                                                                 is estimated as the number of differences between the input sign and
                                                                 the decoded value. */
        uint64_t reserved_93_95        : 3;
        uint64_t max_ber               : 13; /**< [ 92: 80] Maximum bit error rate. The BER is calculated for each code block, and
                                                                 this field reports the maximum BER across all code blocks. */
        uint64_t half_it_done          : 13; /**< [ 79: 67] The cumulative number of half-iterations performed over all code
                                                                 blocks. The upper bound is [NUM_CB] x [HALF_IT], but the actual value might
                                                                 be lower if early stopping is activated. */
        uint64_t reserved_66           : 1;
        uint64_t cb_crc_error_any      : 1;  /**< [ 65: 65] Indicates whether any code block CRCs had errors (i.e., decoded value
                                                                 did not match calculated value). */
        uint64_t tb_crc_error          : 1;  /**< [ 64: 64] When set, this bit indicates that the decoded transport block CRC does
                                                                 not match the calculated transport block CRC. When this bit is zero,
                                                                 the decoded and calculated CRCs match. Note, this field is only valid
                                                                 when [BYPS_TB_PROC] = 0. */
#else /* Word 1 - Little Endian */
        uint64_t tb_crc_error          : 1;  /**< [ 64: 64] When set, this bit indicates that the decoded transport block CRC does
                                                                 not match the calculated transport block CRC. When this bit is zero,
                                                                 the decoded and calculated CRCs match. Note, this field is only valid
                                                                 when [BYPS_TB_PROC] = 0. */
        uint64_t cb_crc_error_any      : 1;  /**< [ 65: 65] Indicates whether any code block CRCs had errors (i.e., decoded value
                                                                 did not match calculated value). */
        uint64_t reserved_66           : 1;
        uint64_t half_it_done          : 13; /**< [ 79: 67] The cumulative number of half-iterations performed over all code
                                                                 blocks. The upper bound is [NUM_CB] x [HALF_IT], but the actual value might
                                                                 be lower if early stopping is activated. */
        uint64_t max_ber               : 13; /**< [ 92: 80] Maximum bit error rate. The BER is calculated for each code block, and
                                                                 this field reports the maximum BER across all code blocks. */
        uint64_t reserved_93_95        : 3;
        uint64_t cber                  : 20; /**< [115: 96] The cumulative bit error rate estimate across all code blocks. The BER
                                                                 is estimated as the number of differences between the input sign and
                                                                 the decoded value. */
        uint64_t max_half_it           : 6;  /**< [121:116] The maximum number of half-iterations performed for any one code
                                                                 block. */
        uint64_t reserved_122_127      : 6;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t per_cb_crc_error0     : 64; /**< [191:128] CRC error indicators for the first 64 code blocks.  Each bit indicates
                                                                 whether a given code block had a CRC error, with bits 0...63 mapping
                                                                 to code blocks 0..63.  A value of 1 indicates a CRC error. */
#else /* Word 2 - Little Endian */
        uint64_t per_cb_crc_error0     : 64; /**< [191:128] CRC error indicators for the first 64 code blocks.  Each bit indicates
                                                                 whether a given code block had a CRC error, with bits 0...63 mapping
                                                                 to code blocks 0..63.  A value of 1 indicates a CRC error. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t per_cb_crc_error1     : 64; /**< [255:192] CRC error indicators for the second 64 code blocks.  Each bit indicates
                                                                 whether a given code block had a CRC error, with bits 0...63 mapping
                                                                 to code blocks 64..127.  A value of 1 indicates a CRC error. */
#else /* Word 3 - Little Endian */
        uint64_t per_cb_crc_error1     : 64; /**< [255:192] CRC error indicators for the second 64 code blocks.  Each bit indicates
                                                                 whether a given code block had a CRC error, with bits 0...63 mapping
                                                                 to code blocks 64..127.  A value of 1 indicates a CRC error. */
#endif /* Word 3 - End */
    } s;
    /* struct cavm_tdec_lte_report_s_s cn; */
};

/**
 * Structure tdec_lte_task_cfg_s
 *
 * TDEC LTE Task Configuration Structure
 * This structure specifies the configuration for an LTE task. The job
 * configuration for an LTE job must have one instance of this structure
 * for each task (TDEC_COMMON_CFG_S[NUM_TASKS]).
 */
union cavm_tdec_lte_task_cfg_s
{
    uint64_t u[8];
    struct cavm_tdec_lte_task_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t payload               : 20; /**< [ 63: 44] The number of bits in the decoded transport block payload, not including the
                                                                 TB CRC. Must be in the range [0x10, 0x33BE0]. */
        uint64_t reserved_39_43        : 5;
        uint64_t ch_deint_mode         : 1;  /**< [ 38: 38] Must be set to 0.
                                                                 Internal:
                                                                 Frequency-first mode is no longer needed for this block,
                                                                 but the logic is still present.
                                                                 When 0, time-first mode is enabled, and multi-threaded DMA must
                                                                 be used.  When 1, frequency-first mode is enabled, and a
                                                                 sequential DMA per symbol, or a 2D DMA across all symbols is used. */
        uint64_t mod_order             : 4;  /**< [ 37: 34] Modulation order:
                                                                 0x1 = BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16QAM.
                                                                 0x6 = 64QAM.
                                                                 0x8 = 256QAM.
                                                                 0x0, 0x3, 0x5, 0x7, 0x9-0xF = Reserved.

                                                                 Internal:
                                                                 0xA specifies 1024QAM, but this mode is not supported by
                                                                 the channel deinterleaver. */
        uint64_t byps_layer_demap      : 1;  /**< [ 33: 33] Bypasses layer de-mapping in the decoder core. If [BYPS_CH_DEINT] = 0, then [BYPS_LAYER_DEMAP]
                                                                 must be set to 1. Otherwise, when set to 1 layer de-mapping is
                                                                 bypassed, and when set to 0, layer demapping is performed by the
                                                                 decoder core.
                                                                 Must be set to 1 when [BYPS_TB_PROC] = 1. */
        uint64_t byps_ch_deint         : 1;  /**< [ 32: 32] When set to 1, bypasses channel de-interleaving.
                                                                 When set to 0, channel de-interleaving and layer de-mapping are
                                                                 performed by the input DMA engine.
                                                                 Must be set to 1 when [BYPS_TB_PROC] = 1. */
        uint64_t ch_deint_off          : 16; /**< [ 31: 16] Number of REs per layer to be discarded from the beginning
                                                                 of channel deinterleaver (excluding RI LLRs that are marked
                                                                 by their value set to 0x80).
                                                                 The actual number of discarded LLRs is [CH_DEINT_OFF] * [MOD_ORDER]. */
        uint64_t task_id               : 16; /**< [ 15:  0] Each task in a job must specify a unique ID. */
#else /* Word 0 - Little Endian */
        uint64_t task_id               : 16; /**< [ 15:  0] Each task in a job must specify a unique ID. */
        uint64_t ch_deint_off          : 16; /**< [ 31: 16] Number of REs per layer to be discarded from the beginning
                                                                 of channel deinterleaver (excluding RI LLRs that are marked
                                                                 by their value set to 0x80).
                                                                 The actual number of discarded LLRs is [CH_DEINT_OFF] * [MOD_ORDER]. */
        uint64_t byps_ch_deint         : 1;  /**< [ 32: 32] When set to 1, bypasses channel de-interleaving.
                                                                 When set to 0, channel de-interleaving and layer de-mapping are
                                                                 performed by the input DMA engine.
                                                                 Must be set to 1 when [BYPS_TB_PROC] = 1. */
        uint64_t byps_layer_demap      : 1;  /**< [ 33: 33] Bypasses layer de-mapping in the decoder core. If [BYPS_CH_DEINT] = 0, then [BYPS_LAYER_DEMAP]
                                                                 must be set to 1. Otherwise, when set to 1 layer de-mapping is
                                                                 bypassed, and when set to 0, layer demapping is performed by the
                                                                 decoder core.
                                                                 Must be set to 1 when [BYPS_TB_PROC] = 1. */
        uint64_t mod_order             : 4;  /**< [ 37: 34] Modulation order:
                                                                 0x1 = BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16QAM.
                                                                 0x6 = 64QAM.
                                                                 0x8 = 256QAM.
                                                                 0x0, 0x3, 0x5, 0x7, 0x9-0xF = Reserved.

                                                                 Internal:
                                                                 0xA specifies 1024QAM, but this mode is not supported by
                                                                 the channel deinterleaver. */
        uint64_t ch_deint_mode         : 1;  /**< [ 38: 38] Must be set to 0.
                                                                 Internal:
                                                                 Frequency-first mode is no longer needed for this block,
                                                                 but the logic is still present.
                                                                 When 0, time-first mode is enabled, and multi-threaded DMA must
                                                                 be used.  When 1, frequency-first mode is enabled, and a
                                                                 sequential DMA per symbol, or a 2D DMA across all symbols is used. */
        uint64_t reserved_39_43        : 5;
        uint64_t payload               : 20; /**< [ 63: 44] The number of bits in the decoded transport block payload, not including the
                                                                 TB CRC. Must be in the range [0x10, 0x33BE0]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t first_cb_rm           : 20; /**< [127:108] The rate-matched size of the first code block, in bits. Note that when
                                                                 [BYPS_TB_PROC] = 1, each task processes just a single code block and
                                                                 this field should be size of that code block. */
        uint64_t reserved_107          : 1;
        uint64_t cb_crc                : 2;  /**< [106:105] Selects the code block CRC mode when operating in per-CB mode (i.e.,
                                                                 when [BYPS_TB_PROC] = 1). The supported modes are:
                                                                 0x0 = No CRC.
                                                                 0x1 = CRC24A.
                                                                 0x2 = CRC24B.
                                                                 0x3 = Reserved.
                                                                 Note that when CRC24B is selected (0x2), the CRC is removed from the decoded
                                                                 output and CRC checks are performed.

                                                                 This field is ignored when [BYPS_TB_PROC] = 0. */
        uint64_t byps_llr_negate       : 1;  /**< [104:104] When set to 1, bypass LLR negation. */
        uint64_t num_cb                : 7;  /**< [103: 97] Number of code blocks in the transport block. */
        uint64_t byps_tb_proc          : 1;  /**< [ 96: 96] When set to one, bypasses the following transport block processing:
                                                                 * Inverse code block concatenation.
                                                                 * Transport block CRC check.
                                                                 * Inverse code block segmentation.
                                                                 * Soft-bit code block concatenation.
                                                                 * Re-encoded code block concatenation.
                                                                 * Data and control path multiplexing.
                                                                 * Channel interleaving.
                                                                 * Scrambling.
                                                                 In this mode, each task processes a single code block. Where other
                                                                 parameters refer to the "first" CB, when [BYPS_TB_PROC] = 1, this refers
                                                                 to the CB being processed (as opposed to the first CB in a transport
                                                                 block).

                                                                 Note that [BYPS_CH_DEINT] and [BYPS_LAYER_DEMAP] must be set to 1 if
                                                                 [BYPS_TB_PROC] = 1. */
        uint64_t reserved_94_95        : 2;
        uint64_t tx_bits               : 20; /**< [ 93: 74] The total number of bits available for transmission of the transport
                                                                 block (i.e., the parameter G in 3GPP TS36.212).
                                                                 Must be in the range [0x1, 0x4D580]. */
        uint64_t num_layers            : 2;  /**< [ 73: 72] Number of layers the transport block is mapped to. Must be either 0x1 or
                                                                 0x2. */
        uint64_t reserved_69_71        : 3;
        uint64_t total_num_sym         : 5;  /**< [ 68: 64] The number of input symbols to be deinterleaved.

                                                                 _ When [BYPS_CH_DEINT] = 0, [TOTAL_NUM_SYM] shall be set to the total
                                                                 number of OFDM symbols [0x1, 0x18] onto which the data/control LLR
                                                                 values are mapped.  This is the same as the number of input threads
                                                                 to be de-interleaved.

                                                                 _ When [BYPS_CH_DEINT] = 1 and [BYPS_LAYER_DEMAP] = 1, then [TOTAL_NUM_SYM]
                                                                 must be set to 0x1.

                                                                 _ When [BYPS_CH_DEINT] = 1 and [BYPS_LAYER_DEMAP] = 0, then [TOTAL_NUM_SYM]
                                                                 must be set to 0x2. */
#else /* Word 1 - Little Endian */
        uint64_t total_num_sym         : 5;  /**< [ 68: 64] The number of input symbols to be deinterleaved.

                                                                 _ When [BYPS_CH_DEINT] = 0, [TOTAL_NUM_SYM] shall be set to the total
                                                                 number of OFDM symbols [0x1, 0x18] onto which the data/control LLR
                                                                 values are mapped.  This is the same as the number of input threads
                                                                 to be de-interleaved.

                                                                 _ When [BYPS_CH_DEINT] = 1 and [BYPS_LAYER_DEMAP] = 1, then [TOTAL_NUM_SYM]
                                                                 must be set to 0x1.

                                                                 _ When [BYPS_CH_DEINT] = 1 and [BYPS_LAYER_DEMAP] = 0, then [TOTAL_NUM_SYM]
                                                                 must be set to 0x2. */
        uint64_t reserved_69_71        : 3;
        uint64_t num_layers            : 2;  /**< [ 73: 72] Number of layers the transport block is mapped to. Must be either 0x1 or
                                                                 0x2. */
        uint64_t tx_bits               : 20; /**< [ 93: 74] The total number of bits available for transmission of the transport
                                                                 block (i.e., the parameter G in 3GPP TS36.212).
                                                                 Must be in the range [0x1, 0x4D580]. */
        uint64_t reserved_94_95        : 2;
        uint64_t byps_tb_proc          : 1;  /**< [ 96: 96] When set to one, bypasses the following transport block processing:
                                                                 * Inverse code block concatenation.
                                                                 * Transport block CRC check.
                                                                 * Inverse code block segmentation.
                                                                 * Soft-bit code block concatenation.
                                                                 * Re-encoded code block concatenation.
                                                                 * Data and control path multiplexing.
                                                                 * Channel interleaving.
                                                                 * Scrambling.
                                                                 In this mode, each task processes a single code block. Where other
                                                                 parameters refer to the "first" CB, when [BYPS_TB_PROC] = 1, this refers
                                                                 to the CB being processed (as opposed to the first CB in a transport
                                                                 block).

                                                                 Note that [BYPS_CH_DEINT] and [BYPS_LAYER_DEMAP] must be set to 1 if
                                                                 [BYPS_TB_PROC] = 1. */
        uint64_t num_cb                : 7;  /**< [103: 97] Number of code blocks in the transport block. */
        uint64_t byps_llr_negate       : 1;  /**< [104:104] When set to 1, bypass LLR negation. */
        uint64_t cb_crc                : 2;  /**< [106:105] Selects the code block CRC mode when operating in per-CB mode (i.e.,
                                                                 when [BYPS_TB_PROC] = 1). The supported modes are:
                                                                 0x0 = No CRC.
                                                                 0x1 = CRC24A.
                                                                 0x2 = CRC24B.
                                                                 0x3 = Reserved.
                                                                 Note that when CRC24B is selected (0x2), the CRC is removed from the decoded
                                                                 output and CRC checks are performed.

                                                                 This field is ignored when [BYPS_TB_PROC] = 0. */
        uint64_t reserved_107          : 1;
        uint64_t first_cb_rm           : 20; /**< [127:108] The rate-matched size of the first code block, in bits. Note that when
                                                                 [BYPS_TB_PROC] = 1, each task processes just a single code block and
                                                                 this field should be size of that code block. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t tb_crc_msk            : 24; /**< [191:168] When [BYPS_CRC_MSK] is cleared, the calculated TB CRC is XORed with
                                                                 [TB_CRC_MSK], and the result is compared against the decoded CRC.
                                                                 There is no CRC mask in LTE, and this field should be 0x0. */
        uint64_t byps_crc_msk          : 1;  /**< [167:167] When set to one, bypass TB CRC masking (see [TB_CRC_MSK]). */
        uint64_t gamma                 : 7;  /**< [166:160] The rate matching parameter, calculated as

                                                                 _ ( [TX_BITS] / ([MOD_ORDER] * [NUM_LAYERS]) ) mod [NUM_CB] */
        uint64_t k0_p                  : 16; /**< [159:144] The bit offset in the pruned virtual circular buffer for the first
                                                                 CB. This value must be in the range [0x0, 3 x [FIRST_CB_SIZE] + 12 -
                                                                 2 x [FILLER] - 1]. */
        uint64_t byps_bit_sel          : 1;  /**< [143:143] When set to 1, bypasses inverse bit selection function, including NULL
                                                                 bit insertion. In this case, the number of input samples must be
                                                                 3 x K_PI (see 3GPP TS36.212).

                                                                 Note, this field is ignored when [BYPS_TB_PROC] = 1. */
        uint64_t rv_idx                : 2;  /**< [142:141] Redundancy revision index. */
        uint64_t first_cb_size         : 13; /**< [140:128] Payload size in bits, including CRC, of the first code block. Must be
                                                                 a valid value in the range [0x28, 0x1800] according to Table 5.1.3-3 in
                                                                 3GPP TS36.212. */
#else /* Word 2 - Little Endian */
        uint64_t first_cb_size         : 13; /**< [140:128] Payload size in bits, including CRC, of the first code block. Must be
                                                                 a valid value in the range [0x28, 0x1800] according to Table 5.1.3-3 in
                                                                 3GPP TS36.212. */
        uint64_t rv_idx                : 2;  /**< [142:141] Redundancy revision index. */
        uint64_t byps_bit_sel          : 1;  /**< [143:143] When set to 1, bypasses inverse bit selection function, including NULL
                                                                 bit insertion. In this case, the number of input samples must be
                                                                 3 x K_PI (see 3GPP TS36.212).

                                                                 Note, this field is ignored when [BYPS_TB_PROC] = 1. */
        uint64_t k0_p                  : 16; /**< [159:144] The bit offset in the pruned virtual circular buffer for the first
                                                                 CB. This value must be in the range [0x0, 3 x [FIRST_CB_SIZE] + 12 -
                                                                 2 x [FILLER] - 1]. */
        uint64_t gamma                 : 7;  /**< [166:160] The rate matching parameter, calculated as

                                                                 _ ( [TX_BITS] / ([MOD_ORDER] * [NUM_LAYERS]) ) mod [NUM_CB] */
        uint64_t byps_crc_msk          : 1;  /**< [167:167] When set to one, bypass TB CRC masking (see [TB_CRC_MSK]). */
        uint64_t tb_crc_msk            : 24; /**< [191:168] When [BYPS_CRC_MSK] is cleared, the calculated TB CRC is XORed with
                                                                 [TB_CRC_MSK], and the result is compared against the decoded CRC.
                                                                 There is no CRC mask in LTE, and this field should be 0x0. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_252_255      : 4;
        uint64_t dec_rnd               : 4;  /**< [251:248] The saturation and rounding level used to convert 8-bit HARQ combining
                                                                 output LLRs to 6-bit decoder input LLRs. Valid range is [0x0, 0x2]. */
        uint64_t sw_speed              : 5;  /**< [247:243] Determines how many decoder engines to use for this task. The TDEC HAB
                                                                 has 16 internal decoder engines.

                                                                 _ If [FIRST_CB_SIZE] \<= 0x100, then this field specifies how many decoder
                                                                 engines to use. The value must be either 0x0 (use all 16 engines), 0x2, or 0x4. Other values are
                                                                 reserved.

                                                                 _ If 0x100 \< [FIRST_CB_SIZE] \< 0x200, TDEC always uses 8 engines, and this
                                                                 field is ignored.

                                                                 _ If [FIRST_CB_SIZE] \> 0x200, TDEC always uses all 16 engines, and this
                                                                 field is ignored. */
        uint64_t dyn_stop              : 3;  /**< [242:240] Dynamic early stopping configuration:
                                                                 0x0 = Disabled - always run [HALF_IT] half iterations.
                                                                 0x1 = Early stopping enabled.
                                                                 0x2 - 0x7 = Reserved. */
        uint64_t reserved_238_239      : 2;
        uint64_t half_it_so            : 6;  /**< [237:232] The number of half iterations performed prior to producing the
                                                                 soft-bit output. When [SO_SEL] = 1, this value must be an even number,
                                                                 less than or equal to [HALF_IT]. */
        uint64_t half_it               : 6;  /**< [231:226] The number of half iterations for CTC decoding.  This value must
                                                                 be even. */
        uint64_t reserved_225          : 1;
        uint64_t byps_bs_so            : 1;  /**< [224:224] When set to 1, bypass bit selection and NULL bit
                                                                 suppression for soft bit outputs. In this case, TDEC writes 3 x K_PI soft
                                                                 bits. This field must be set to 1 when bit selection is bypassed for the input LLRs
                                                                 ([BYPS_BIT_SEL] = 1).

                                                                 Note, this is valid only in per-CB mode (when [BYPS_TB_PROC] = 1). */
        uint64_t so_sel                : 1;  /**< [223:223] Select the type of soft output:
                                                                 0 = A posteriori LLRs (APP).
                                                                 1 = Extrinsic LLRs.
                                                                 Note, extrinsic = APP - input LLRs. */
        uint64_t so_ena                : 1;  /**< [222:222] Enable soft-bit output. When enabled (i.e., set to 1), [TX_BITS]
                                                                 soft-bits will be written to output DMA port 1.

                                                                 If [SO_ENA] = 0, then [HD_OUT_ENA] must be 1. */
        uint64_t hd_byte_order         : 2;  /**< [221:220] The byte order for the decoded hard-bit output data.  See Baseband PHY
                                                                 (BPHY): Data Packing section for details. For normal usage, this should
                                                                 be set to 0x0. */
        uint64_t hd_bit_order          : 1;  /**< [219:219] The bit order for the decoded hard-bit output data.  See Baseband PHY
                                                                 (BPHY): Data Packing section for details. For normal usage, this should
                                                                 be set to 0. */
        uint64_t hd_out_ena            : 1;  /**< [218:218] When set to 1, hard-bit output is enabled and [TX_BITS] bits of decoded output
                                                                 will be written to port 2. When set to 0, no hard outputs are
                                                                 generated, no CRC computation is performed, and no re-encoding can be
                                                                 performed (i.e., [REENC_ENA] is ignored and treated as 0).

                                                                 If [HD_OUT_ENA] = 0, then [SO_ENA] must be 1.

                                                                 When set to 1, TDEC_LTE_REPORT_S will be written to port 2 after the
                                                                 decoded output.

                                                                 When set to 0, TDEC_LTE_REPORT_S will be written to port 1 after the
                                                                 soft-bit output. */
        uint64_t hc_out_ena            : 1;  /**< [217:217] Enable HARQ output. When set to one, the HARQ output is generated for
                                                                 this task and written to output port 0. When cleared, no HARQ outputs
                                                                 are written and output port 0 is not used by this task. */
        uint64_t byps_hc_comp          : 1;  /**< [216:216] Bypass HARQ compression.

                                                                 _ When set to 0, the HARQ input and output are compressed, and only
                                                                 a portion of the pruned virtual circular buffer is read/written.

                                                                 _ When set to 1, the HARQ input and output are both the entire pruned
                                                                 virtual circular buffer (as defined in 3GPP TS36.212). */
        uint64_t gain_h                : 8;  /**< [215:208] Scaling factor for HARQ input LLRs in HARQ combining. */
        uint64_t gain_i                : 8;  /**< [207:200] Scaling factor for RX input LLRs in HARQ combining. */
        uint64_t hc_in_ena             : 1;  /**< [199:199] Enable HARQ inputs. When set to 1, TDEC will perform HARQ combining.
                                                                 The input DMA port 1 must be configured to read the HARQ input.
                                                                 When set to 0, no HARQ combining is performed, and input port 1 is not
                                                                 used for this task. */
        uint64_t byps_dec              : 1;  /**< [198:198] When set to 1, bypass the turbo decoding function. HARQ combining will
                                                                 be performed, but decoded output, re-encoded output and soft-bit outputs cannot be
                                                                 written. */
        uint64_t filler                : 6;  /**< [197:192] The number of filler bits in the first code block. */
#else /* Word 3 - Little Endian */
        uint64_t filler                : 6;  /**< [197:192] The number of filler bits in the first code block. */
        uint64_t byps_dec              : 1;  /**< [198:198] When set to 1, bypass the turbo decoding function. HARQ combining will
                                                                 be performed, but decoded output, re-encoded output and soft-bit outputs cannot be
                                                                 written. */
        uint64_t hc_in_ena             : 1;  /**< [199:199] Enable HARQ inputs. When set to 1, TDEC will perform HARQ combining.
                                                                 The input DMA port 1 must be configured to read the HARQ input.
                                                                 When set to 0, no HARQ combining is performed, and input port 1 is not
                                                                 used for this task. */
        uint64_t gain_i                : 8;  /**< [207:200] Scaling factor for RX input LLRs in HARQ combining. */
        uint64_t gain_h                : 8;  /**< [215:208] Scaling factor for HARQ input LLRs in HARQ combining. */
        uint64_t byps_hc_comp          : 1;  /**< [216:216] Bypass HARQ compression.

                                                                 _ When set to 0, the HARQ input and output are compressed, and only
                                                                 a portion of the pruned virtual circular buffer is read/written.

                                                                 _ When set to 1, the HARQ input and output are both the entire pruned
                                                                 virtual circular buffer (as defined in 3GPP TS36.212). */
        uint64_t hc_out_ena            : 1;  /**< [217:217] Enable HARQ output. When set to one, the HARQ output is generated for
                                                                 this task and written to output port 0. When cleared, no HARQ outputs
                                                                 are written and output port 0 is not used by this task. */
        uint64_t hd_out_ena            : 1;  /**< [218:218] When set to 1, hard-bit output is enabled and [TX_BITS] bits of decoded output
                                                                 will be written to port 2. When set to 0, no hard outputs are
                                                                 generated, no CRC computation is performed, and no re-encoding can be
                                                                 performed (i.e., [REENC_ENA] is ignored and treated as 0).

                                                                 If [HD_OUT_ENA] = 0, then [SO_ENA] must be 1.

                                                                 When set to 1, TDEC_LTE_REPORT_S will be written to port 2 after the
                                                                 decoded output.

                                                                 When set to 0, TDEC_LTE_REPORT_S will be written to port 1 after the
                                                                 soft-bit output. */
        uint64_t hd_bit_order          : 1;  /**< [219:219] The bit order for the decoded hard-bit output data.  See Baseband PHY
                                                                 (BPHY): Data Packing section for details. For normal usage, this should
                                                                 be set to 0. */
        uint64_t hd_byte_order         : 2;  /**< [221:220] The byte order for the decoded hard-bit output data.  See Baseband PHY
                                                                 (BPHY): Data Packing section for details. For normal usage, this should
                                                                 be set to 0x0. */
        uint64_t so_ena                : 1;  /**< [222:222] Enable soft-bit output. When enabled (i.e., set to 1), [TX_BITS]
                                                                 soft-bits will be written to output DMA port 1.

                                                                 If [SO_ENA] = 0, then [HD_OUT_ENA] must be 1. */
        uint64_t so_sel                : 1;  /**< [223:223] Select the type of soft output:
                                                                 0 = A posteriori LLRs (APP).
                                                                 1 = Extrinsic LLRs.
                                                                 Note, extrinsic = APP - input LLRs. */
        uint64_t byps_bs_so            : 1;  /**< [224:224] When set to 1, bypass bit selection and NULL bit
                                                                 suppression for soft bit outputs. In this case, TDEC writes 3 x K_PI soft
                                                                 bits. This field must be set to 1 when bit selection is bypassed for the input LLRs
                                                                 ([BYPS_BIT_SEL] = 1).

                                                                 Note, this is valid only in per-CB mode (when [BYPS_TB_PROC] = 1). */
        uint64_t reserved_225          : 1;
        uint64_t half_it               : 6;  /**< [231:226] The number of half iterations for CTC decoding.  This value must
                                                                 be even. */
        uint64_t half_it_so            : 6;  /**< [237:232] The number of half iterations performed prior to producing the
                                                                 soft-bit output. When [SO_SEL] = 1, this value must be an even number,
                                                                 less than or equal to [HALF_IT]. */
        uint64_t reserved_238_239      : 2;
        uint64_t dyn_stop              : 3;  /**< [242:240] Dynamic early stopping configuration:
                                                                 0x0 = Disabled - always run [HALF_IT] half iterations.
                                                                 0x1 = Early stopping enabled.
                                                                 0x2 - 0x7 = Reserved. */
        uint64_t sw_speed              : 5;  /**< [247:243] Determines how many decoder engines to use for this task. The TDEC HAB
                                                                 has 16 internal decoder engines.

                                                                 _ If [FIRST_CB_SIZE] \<= 0x100, then this field specifies how many decoder
                                                                 engines to use. The value must be either 0x0 (use all 16 engines), 0x2, or 0x4. Other values are
                                                                 reserved.

                                                                 _ If 0x100 \< [FIRST_CB_SIZE] \< 0x200, TDEC always uses 8 engines, and this
                                                                 field is ignored.

                                                                 _ If [FIRST_CB_SIZE] \> 0x200, TDEC always uses all 16 engines, and this
                                                                 field is ignored. */
        uint64_t dec_rnd               : 4;  /**< [251:248] The saturation and rounding level used to convert 8-bit HARQ combining
                                                                 output LLRs to 6-bit decoder input LLRs. Valid range is [0x0, 0x2]. */
        uint64_t reserved_252_255      : 4;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t deint_skip_offset1    : 16; /**< [319:304] Reserved.
                                                                 Internal:
                                                                 Applicable only to frequency-first mode.
                                                                 The number of initial REs to be discarded in the first
                                                                 [SKIP_OFFSET1_NUM_SYM] symbols (including tagged LLRs marked
                                                                 with the value 0x80).  The actual number of LLRs that are
                                                                 discarded in each symbol is [DEINT_SKIP_OFFSET1] * [MOD_ORDER]. */
        uint64_t reserved_297_303      : 7;
        uint64_t skip_offset1_num_sym  : 5;  /**< [296:292] Reserved.
                                                                 Internal:
                                                                 Applicable only to frequency-first mode.
                                                                 Indicates the number of OFDM symbols for which the
                                                                 [DEINT_SKIP_OFFSET1] parameter applies. */
        uint64_t symb_byte_align       : 2;  /**< [291:290] When 0x1, each [MOD_ORDER] bits of reencoded output are mapped to one
                                                                 byte, with the (8 - [MOD_ORDER]) most significant bits padded with zeros.
                                                                 When 0x0, the reencoded output bits are packed with no extra padding.

                                                                 Internal:
                                                                 Values of 0x2 and 0x3 are applicable only to 1024QAM.
                                                                 When 0x2, from each 10 bits mapped to one symbol, the even bits
                                                                 are mapped to the first byte and the odd bits are mapped to the
                                                                 next byte.  The data bits are mapped in little endian format, and
                                                                 the 3 MSB bits are set to 0.
                                                                 When 0x3, from each 10 bits mapped to one symbol, the first 5 bits
                                                                 are mapped to the first byte and the next 5 bits are mapped to the
                                                                 next byte.  The data bits are mapped in little endian format, and
                                                                 the 3 MSB bits are set to 0. */
        uint64_t reenc_byte_order      : 2;  /**< [289:288] The byte order for the re-encoded output.  See Baseband PHY
                                                                 (BPHY): Data Packing section for details. For normal usage, this should
                                                                 be set to 0x0. */
        uint64_t reenc_bit_order       : 1;  /**< [287:287] The bit order for the re-encoded output.  See Baseband PHY
                                                                 (BPHY): Data Packing section for details. */
        uint64_t byps_rm               : 1;  /**< [286:286] When set to one, bypasses rate-matching of the re-encoded output. In
                                                                 this case, 3 x K_r + 12 bits are output for code block r, where K_r
                                                                 is defined in 3GPP TS36.212.

                                                                 When set to zero, the re-encoded output is rate matched. The output
                                                                 for code block r will be E_r, as defined in 3GPP TS36.212. */
        uint64_t reenc_ena             : 1;  /**< [285:285] Enable re-encoding. */
        uint64_t tbl_sel               : 2;  /**< [284:283] Selects the decoding algorithm and table size:
                                                                 0x0 = Max-Log-MAP algorithm.
                                                                 0x1 = Log-MAP algorithm with large table.
                                                                 0x2 = Log-MAP algorithm with small table.
                                                                 Note that the Max-Log-MAP algorithm leads to a degradation of 0.1 - 0.2
                                                                 dB compared with the Log-MAP algorithms.
                                                                 It is recommended to use [TBL_SEL] = 0x1. */
        uint64_t algo                  : 3;  /**< [282:280] Selects the decoding algorithm:
                                                                 0x0 = Standard algorithm, recommended for low code rates.
                                                                 0x1 = Algorithm 1, provides slightly better decoding performance at
                                                                 the cost of lower throughput than the standard algorithm. Recommended
                                                                 for high code rates.
                                                                 0x2 = Reserved.
                                                                 0x3 = Algorithm 3, provides fast convergence, at slightly lower
                                                                 throughput than algorithm 1. This option is only valid when
                                                                 [FIRST_CB_SIZE] \<= 0x100. */
        uint64_t thresh                : 8;  /**< [279:272] The threshold for early dynamic stopping. This parameter is only used
                                                                 when [DYN_STOP] = 0x1 and there is no CRC present. Higher thresholds will
                                                                 result in more iterations, causing better decoding performance at the
                                                                 cost of lower throughput.  This value must be in the range [0x0, 0x3f].
                                                                 When set to 0x0, the default threshold of 0x20 is used. */
        uint64_t reserved_260_271      : 12;
        uint64_t harq_rnd              : 4;  /**< [259:256] The saturation and rounding level applied to the output of the
                                                                 HARQ combining unit. The combiner produces 19-bit outputs that are
                                                                 rounded and saturated to 8-bit values before being written to the output or passed to
                                                                 the decoder. Valid range is [0x0, 0xB]. */
#else /* Word 4 - Little Endian */
        uint64_t harq_rnd              : 4;  /**< [259:256] The saturation and rounding level applied to the output of the
                                                                 HARQ combining unit. The combiner produces 19-bit outputs that are
                                                                 rounded and saturated to 8-bit values before being written to the output or passed to
                                                                 the decoder. Valid range is [0x0, 0xB]. */
        uint64_t reserved_260_271      : 12;
        uint64_t thresh                : 8;  /**< [279:272] The threshold for early dynamic stopping. This parameter is only used
                                                                 when [DYN_STOP] = 0x1 and there is no CRC present. Higher thresholds will
                                                                 result in more iterations, causing better decoding performance at the
                                                                 cost of lower throughput.  This value must be in the range [0x0, 0x3f].
                                                                 When set to 0x0, the default threshold of 0x20 is used. */
        uint64_t algo                  : 3;  /**< [282:280] Selects the decoding algorithm:
                                                                 0x0 = Standard algorithm, recommended for low code rates.
                                                                 0x1 = Algorithm 1, provides slightly better decoding performance at
                                                                 the cost of lower throughput than the standard algorithm. Recommended
                                                                 for high code rates.
                                                                 0x2 = Reserved.
                                                                 0x3 = Algorithm 3, provides fast convergence, at slightly lower
                                                                 throughput than algorithm 1. This option is only valid when
                                                                 [FIRST_CB_SIZE] \<= 0x100. */
        uint64_t tbl_sel               : 2;  /**< [284:283] Selects the decoding algorithm and table size:
                                                                 0x0 = Max-Log-MAP algorithm.
                                                                 0x1 = Log-MAP algorithm with large table.
                                                                 0x2 = Log-MAP algorithm with small table.
                                                                 Note that the Max-Log-MAP algorithm leads to a degradation of 0.1 - 0.2
                                                                 dB compared with the Log-MAP algorithms.
                                                                 It is recommended to use [TBL_SEL] = 0x1. */
        uint64_t reenc_ena             : 1;  /**< [285:285] Enable re-encoding. */
        uint64_t byps_rm               : 1;  /**< [286:286] When set to one, bypasses rate-matching of the re-encoded output. In
                                                                 this case, 3 x K_r + 12 bits are output for code block r, where K_r
                                                                 is defined in 3GPP TS36.212.

                                                                 When set to zero, the re-encoded output is rate matched. The output
                                                                 for code block r will be E_r, as defined in 3GPP TS36.212. */
        uint64_t reenc_bit_order       : 1;  /**< [287:287] The bit order for the re-encoded output.  See Baseband PHY
                                                                 (BPHY): Data Packing section for details. */
        uint64_t reenc_byte_order      : 2;  /**< [289:288] The byte order for the re-encoded output.  See Baseband PHY
                                                                 (BPHY): Data Packing section for details. For normal usage, this should
                                                                 be set to 0x0. */
        uint64_t symb_byte_align       : 2;  /**< [291:290] When 0x1, each [MOD_ORDER] bits of reencoded output are mapped to one
                                                                 byte, with the (8 - [MOD_ORDER]) most significant bits padded with zeros.
                                                                 When 0x0, the reencoded output bits are packed with no extra padding.

                                                                 Internal:
                                                                 Values of 0x2 and 0x3 are applicable only to 1024QAM.
                                                                 When 0x2, from each 10 bits mapped to one symbol, the even bits
                                                                 are mapped to the first byte and the odd bits are mapped to the
                                                                 next byte.  The data bits are mapped in little endian format, and
                                                                 the 3 MSB bits are set to 0.
                                                                 When 0x3, from each 10 bits mapped to one symbol, the first 5 bits
                                                                 are mapped to the first byte and the next 5 bits are mapped to the
                                                                 next byte.  The data bits are mapped in little endian format, and
                                                                 the 3 MSB bits are set to 0. */
        uint64_t skip_offset1_num_sym  : 5;  /**< [296:292] Reserved.
                                                                 Internal:
                                                                 Applicable only to frequency-first mode.
                                                                 Indicates the number of OFDM symbols for which the
                                                                 [DEINT_SKIP_OFFSET1] parameter applies. */
        uint64_t reserved_297_303      : 7;
        uint64_t deint_skip_offset1    : 16; /**< [319:304] Reserved.
                                                                 Internal:
                                                                 Applicable only to frequency-first mode.
                                                                 The number of initial REs to be discarded in the first
                                                                 [SKIP_OFFSET1_NUM_SYM] symbols (including tagged LLRs marked
                                                                 with the value 0x80).  The actual number of LLRs that are
                                                                 discarded in each symbol is [DEINT_SKIP_OFFSET1] * [MOD_ORDER]. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_336_383      : 48;
        uint64_t deint_skip_offset2    : 16; /**< [335:320] Reserved.
                                                                 Internal:
                                                                 Applicable only to frequency-first mode.
                                                                 The number of initial REs to be discarded in the remaining
                                                                 symbols after the first [SKIP_OFFSET1_NUM_SYM] symbols (including
                                                                 tagged LLRs marked with the value 0x80).  The actual number of
                                                                 LLRs that are discarded in each symbol is [DEINT_SKIP_OFFSET2] *
                                                                 [MOD_ORDER]. */
#else /* Word 5 - Little Endian */
        uint64_t deint_skip_offset2    : 16; /**< [335:320] Reserved.
                                                                 Internal:
                                                                 Applicable only to frequency-first mode.
                                                                 The number of initial REs to be discarded in the remaining
                                                                 symbols after the first [SKIP_OFFSET1_NUM_SYM] symbols (including
                                                                 tagged LLRs marked with the value 0x80).  The actual number of
                                                                 LLRs that are discarded in each symbol is [DEINT_SKIP_OFFSET2] *
                                                                 [MOD_ORDER]. */
        uint64_t reserved_336_383      : 48;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t num_wr0_wrds          : 16; /**< [447:432] The number of 128-bit words this task will write to output DMA port 0. */
        uint64_t num_rd0_dma_wrds_per_sym : 16;/**< [431:416] This is the same as the number of words per thread.
                                                                 Internal:
                                                                 Number of 128-bit words of DMA input per OFDM symbol.
                                                                 In time-first mode, this is the same as the number of words per thread.
                                                                 In frequency-first mode, this is the same as [NUM_RD_WRDS] / [TOTAL_NUM_SYM]. */
        uint64_t num_rd1_wrds          : 16; /**< [415:400] The number of 128-bit words to read from input DMA port 1. */
        uint64_t num_rd0_wrds          : 16; /**< [399:384] The number of 128-bit words to read from input DMA port 0. */
#else /* Word 6 - Little Endian */
        uint64_t num_rd0_wrds          : 16; /**< [399:384] The number of 128-bit words to read from input DMA port 0. */
        uint64_t num_rd1_wrds          : 16; /**< [415:400] The number of 128-bit words to read from input DMA port 1. */
        uint64_t num_rd0_dma_wrds_per_sym : 16;/**< [431:416] This is the same as the number of words per thread.
                                                                 Internal:
                                                                 Number of 128-bit words of DMA input per OFDM symbol.
                                                                 In time-first mode, this is the same as the number of words per thread.
                                                                 In frequency-first mode, this is the same as [NUM_RD_WRDS] / [TOTAL_NUM_SYM]. */
        uint64_t num_wr0_wrds          : 16; /**< [447:432] The number of 128-bit words this task will write to output DMA port 0. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t reserved_496_511      : 16;
        uint64_t num_wr3_wrds          : 16; /**< [495:480] The number of 64-bit words this task will write to output DMA port 3. */
        uint64_t num_wr2_wrds          : 16; /**< [479:464] The number of 64-bit words this task will write to output DMA port 2. */
        uint64_t num_wr1_wrds          : 16; /**< [463:448] The number of 64-bit words this task will write to output DMA port 1. */
#else /* Word 7 - Little Endian */
        uint64_t num_wr1_wrds          : 16; /**< [463:448] The number of 64-bit words this task will write to output DMA port 1. */
        uint64_t num_wr2_wrds          : 16; /**< [479:464] The number of 64-bit words this task will write to output DMA port 2. */
        uint64_t num_wr3_wrds          : 16; /**< [495:480] The number of 64-bit words this task will write to output DMA port 3. */
        uint64_t reserved_496_511      : 16;
#endif /* Word 7 - End */
    } s;
    /* struct cavm_tdec_lte_task_cfg_s_s cn; */
};

/**
 * Register (RSL) tdec#_control
 *
 * TDEC Control Register
 */
union cavm_tdecx_control
{
    uint64_t u;
    struct cavm_tdecx_control_s
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
    /* struct cavm_tdecx_control_s cn; */
};
typedef union cavm_tdecx_control cavm_tdecx_control_t;

static inline uint64_t CAVM_TDECX_CONTROL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_CONTROL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043600000ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043600000ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_CONTROL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_CONTROL(a) cavm_tdecx_control_t
#define bustype_CAVM_TDECX_CONTROL(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_CONTROL(a) "TDECX_CONTROL"
#define busnum_CAVM_TDECX_CONTROL(a) (a)
#define arguments_CAVM_TDECX_CONTROL(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_eco
 *
 * INTERNAL: TDEC ECO Register
 */
union cavm_tdecx_eco
{
    uint64_t u;
    struct cavm_tdecx_eco_s
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
    /* struct cavm_tdecx_eco_s cn; */
};
typedef union cavm_tdecx_eco cavm_tdecx_eco_t;

static inline uint64_t CAVM_TDECX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_ECO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043600008ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043600008ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_ECO", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_ECO(a) cavm_tdecx_eco_t
#define bustype_CAVM_TDECX_ECO(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_ECO(a) "TDECX_ECO"
#define busnum_CAVM_TDECX_ECO(a) (a)
#define arguments_CAVM_TDECX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_error_enable0
 *
 * TDEC Error Enable 0 Register
 * This register enables error reporting for read overflow/underflow errors.
 */
union cavm_tdecx_error_enable0
{
    uint64_t u;
    struct cavm_tdecx_error_enable0_s
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
    /* struct cavm_tdecx_error_enable0_s cn; */
};
typedef union cavm_tdecx_error_enable0 cavm_tdecx_error_enable0_t;

static inline uint64_t CAVM_TDECX_ERROR_ENABLE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_ERROR_ENABLE0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043600040ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043600040ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_ERROR_ENABLE0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_ERROR_ENABLE0(a) cavm_tdecx_error_enable0_t
#define bustype_CAVM_TDECX_ERROR_ENABLE0(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_ERROR_ENABLE0(a) "TDECX_ERROR_ENABLE0"
#define busnum_CAVM_TDECX_ERROR_ENABLE0(a) (a)
#define arguments_CAVM_TDECX_ERROR_ENABLE0(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_error_source0
 *
 * TDEC Error Source 0 Register
 * This register indicates the source of read overflow/underflow errors.
 */
union cavm_tdecx_error_source0
{
    uint64_t u;
    struct cavm_tdecx_error_source0_s
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
    /* struct cavm_tdecx_error_source0_s cn; */
};
typedef union cavm_tdecx_error_source0 cavm_tdecx_error_source0_t;

static inline uint64_t CAVM_TDECX_ERROR_SOURCE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_ERROR_SOURCE0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043600030ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043600030ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_ERROR_SOURCE0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_ERROR_SOURCE0(a) cavm_tdecx_error_source0_t
#define bustype_CAVM_TDECX_ERROR_SOURCE0(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_ERROR_SOURCE0(a) "TDECX_ERROR_SOURCE0"
#define busnum_CAVM_TDECX_ERROR_SOURCE0(a) (a)
#define arguments_CAVM_TDECX_ERROR_SOURCE0(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_hab_jcfg0_ram#_data
 *
 * TDEC HAB Job Configuration 0 RAM Register
 * This register range accesses the job configuration RAM for slot 0.
 */
union cavm_tdecx_hab_jcfg0_ramx_data
{
    uint64_t u;
    struct cavm_tdecx_hab_jcfg0_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Job configuration RAM entry. */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Job configuration RAM entry. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_hab_jcfg0_ramx_data_s cn; */
};
typedef union cavm_tdecx_hab_jcfg0_ramx_data cavm_tdecx_hab_jcfg0_ramx_data_t;

static inline uint64_t CAVM_TDECX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=255)))
        return 0x87e043602000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=2) && (b<=255)))
        return 0x87e043602000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    __cavm_csr_fatal("TDECX_HAB_JCFG0_RAMX_DATA", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_HAB_JCFG0_RAMX_DATA(a,b) cavm_tdecx_hab_jcfg0_ramx_data_t
#define bustype_CAVM_TDECX_HAB_JCFG0_RAMX_DATA(a,b) CSR_TYPE_RSL
#define basename_CAVM_TDECX_HAB_JCFG0_RAMX_DATA(a,b) "TDECX_HAB_JCFG0_RAMX_DATA"
#define busnum_CAVM_TDECX_HAB_JCFG0_RAMX_DATA(a,b) (a)
#define arguments_CAVM_TDECX_HAB_JCFG0_RAMX_DATA(a,b) (a),(b),-1,-1

/**
 * Register (RSL) tdec#_hab_jcfg1_ram#_data
 *
 * TDEC HAB Job Configuration 1 RAM Register
 * This register range accesses the job configuration RAM for slot 1.
 */
union cavm_tdecx_hab_jcfg1_ramx_data
{
    uint64_t u;
    struct cavm_tdecx_hab_jcfg1_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Job configuration RAM entry. */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Job configuration RAM entry. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_hab_jcfg1_ramx_data_s cn; */
};
typedef union cavm_tdecx_hab_jcfg1_ramx_data cavm_tdecx_hab_jcfg1_ramx_data_t;

static inline uint64_t CAVM_TDECX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=255)))
        return 0x87e043604000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=2) && (b<=255)))
        return 0x87e043604000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    __cavm_csr_fatal("TDECX_HAB_JCFG1_RAMX_DATA", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_HAB_JCFG1_RAMX_DATA(a,b) cavm_tdecx_hab_jcfg1_ramx_data_t
#define bustype_CAVM_TDECX_HAB_JCFG1_RAMX_DATA(a,b) CSR_TYPE_RSL
#define basename_CAVM_TDECX_HAB_JCFG1_RAMX_DATA(a,b) "TDECX_HAB_JCFG1_RAMX_DATA"
#define busnum_CAVM_TDECX_HAB_JCFG1_RAMX_DATA(a,b) (a)
#define arguments_CAVM_TDECX_HAB_JCFG1_RAMX_DATA(a,b) (a),(b),-1,-1

/**
 * Register (RSL) tdec#_hab_jcfg2_ram#_data
 *
 * TDEC HAB Job Configuration 2 RAM Register
 * This register range accesses the job configuration RAM for slot 2.
 */
union cavm_tdecx_hab_jcfg2_ramx_data
{
    uint64_t u;
    struct cavm_tdecx_hab_jcfg2_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Job configuration RAM entry. */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Job configuration RAM entry. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_hab_jcfg2_ramx_data_s cn; */
};
typedef union cavm_tdecx_hab_jcfg2_ramx_data cavm_tdecx_hab_jcfg2_ramx_data_t;

static inline uint64_t CAVM_TDECX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=255)))
        return 0x87e043606000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=2) && (b<=255)))
        return 0x87e043606000ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0xff);
    __cavm_csr_fatal("TDECX_HAB_JCFG2_RAMX_DATA", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_HAB_JCFG2_RAMX_DATA(a,b) cavm_tdecx_hab_jcfg2_ramx_data_t
#define bustype_CAVM_TDECX_HAB_JCFG2_RAMX_DATA(a,b) CSR_TYPE_RSL
#define basename_CAVM_TDECX_HAB_JCFG2_RAMX_DATA(a,b) "TDECX_HAB_JCFG2_RAMX_DATA"
#define busnum_CAVM_TDECX_HAB_JCFG2_RAMX_DATA(a,b) (a)
#define arguments_CAVM_TDECX_HAB_JCFG2_RAMX_DATA(a,b) (a),(b),-1,-1

/**
 * Register (RSL) tdec#_scratch
 *
 * INTERNAL: Scratch Register
 *
 * Scratch register.
 */
union cavm_tdecx_scratch
{
    uint64_t u;
    struct cavm_tdecx_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_scratch_s cn; */
};
typedef union cavm_tdecx_scratch cavm_tdecx_scratch_t;

static inline uint64_t CAVM_TDECX_SCRATCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_SCRATCH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043600080ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043600080ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_SCRATCH", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_SCRATCH(a) cavm_tdecx_scratch_t
#define bustype_CAVM_TDECX_SCRATCH(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_SCRATCH(a) "TDECX_SCRATCH"
#define busnum_CAVM_TDECX_SCRATCH(a) (a)
#define arguments_CAVM_TDECX_SCRATCH(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_status
 *
 * TDEC Status Register
 */
union cavm_tdecx_status
{
    uint64_t u;
    struct cavm_tdecx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the TDEC HAB is ready to receive the next job. */
        uint64_t reserved_3            : 1;
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the TDEC HAB is ready to receive the next job. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_status_s cn; */
};
typedef union cavm_tdecx_status cavm_tdecx_status_t;

static inline uint64_t CAVM_TDECX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043600018ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043600018ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_STATUS(a) cavm_tdecx_status_t
#define bustype_CAVM_TDECX_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_STATUS(a) "TDECX_STATUS"
#define busnum_CAVM_TDECX_STATUS(a) (a)
#define arguments_CAVM_TDECX_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_tc_config_err_flags_reg
 *
 * TDEC Task Configuration Error Flags Register
 * This register reports task configuration errors that occur when a
 * specified parameter value is outside the acceptable range.
 */
union cavm_tdecx_tc_config_err_flags_reg
{
    uint64_t u;
    struct cavm_tdecx_tc_config_err_flags_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t invalid_bypass_scrambling : 1;/**< [ 52: 52](RO/H) Reserved.
                                                                 Internal:
                                                                 Was invalid bypass_scrambling mode, but that has been removed
                                                                 from the decoder core. */
        uint64_t invalid_reenc_byte_order : 1;/**< [ 51: 51](RO/H) Invalid TDEC_LTE_TASK_CFG_S[REENC_BYTE_ORDER] value. */
        uint64_t invalid_reenc_bit_order : 1;/**< [ 50: 50](RO/H) Invalid TDEC_LTE_TASK_CFG_S[REENC_BIT_ORDER] value. */
        uint64_t invalid_symb_byte_align : 1;/**< [ 49: 49](RO/H) Invalid TDEC_LTE_TASK_CFG_S[SYMB_BYTE_ALIGN] value. */
        uint64_t reserved_48           : 1;
        uint64_t invalid_byps_rm       : 1;  /**< [ 47: 47](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_RM] value. */
        uint64_t invalid_reenc_ena     : 1;  /**< [ 46: 46](RO/H) Invalid TDEC_LTE_TASK_CFG_S[REENC_ENA] value. */
        uint64_t invalid_so_sel        : 1;  /**< [ 45: 45](RO/H) Invalid TDEC_LTE_TASK_CFG_S[SO_SEL] value. */
        uint64_t invalid_half_it_so    : 1;  /**< [ 44: 44](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HALF_IT_SO] value. */
        uint64_t invalid_byps_bs_so    : 1;  /**< [ 43: 43](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_BS_SO] value. */
        uint64_t invalid_so_ena        : 1;  /**< [ 42: 42](RO/H) Invalid TDEC_LTE_TASK_CFG_S[SO_ENA] value. */
        uint64_t invalid_cb_crc        : 1;  /**< [ 41: 41](RO/H) Invalid TDEC_LTE_TASK_CFG_S[CB_CRC] value. */
        uint64_t invalid_hd_byte_order : 1;  /**< [ 40: 40](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HD_BYTE_ORDER] value. */
        uint64_t invalid_hd_bit_order  : 1;  /**< [ 39: 39](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HD_BIT_ORDER] value. */
        uint64_t invalid_hd_out_ena    : 1;  /**< [ 38: 38](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HD_OUT_ENA] value. */
        uint64_t invalid_algo          : 1;  /**< [ 37: 37](RO/H) Invalid TDEC_LTE_TASK_CFG_S[ALGO] value. */
        uint64_t invalid_sw_speed      : 1;  /**< [ 36: 36](RO/H) Invalid TDEC_LTE_TASK_CFG_S[SW_SPEED] value. */
        uint64_t invalid_tbl_sel       : 1;  /**< [ 35: 35](RO/H) Invalid TDEC_LTE_TASK_CFG_S[TBL_SEL] value. */
        uint64_t invalid_thresh        : 1;  /**< [ 34: 34](RO/H) Invalid TDEC_LTE_TASK_CFG_S[THRESH] value. */
        uint64_t invalid_dyn_stop      : 1;  /**< [ 33: 33](RO/H) Invalid TDEC_LTE_TASK_CFG_S[DYN_STOP] value. */
        uint64_t invalid_half_it       : 1;  /**< [ 32: 32](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HALF_IT] value. */
        uint64_t invalid_harq_rnd      : 1;  /**< [ 31: 31](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HARQ_RND] value. */
        uint64_t invalid_dec_rnd       : 1;  /**< [ 30: 30](RO/H) Invalid TDEC_LTE_TASK_CFG_S[DEC_RND] value. */
        uint64_t invalid_gain_h        : 1;  /**< [ 29: 29](RO/H) Invalid TDEC_LTE_TASK_CFG_S[GAIN_H] value. */
        uint64_t invalid_gain_i        : 1;  /**< [ 28: 28](RO/H) Invalid TDEC_LTE_TASK_CFG_S[GAIN_I] value. */
        uint64_t invalid_byps_llr_negate : 1;/**< [ 27: 27](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_LLR_NEGATE] value. */
        uint64_t invalid_k0_p          : 1;  /**< [ 26: 26](RO/H) Invalid TDEC_LTE_TASK_CFG_S[K0_P] value. */
        uint64_t invalid_hc_out_ena    : 1;  /**< [ 25: 25](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HC_OUT_ENA] value. */
        uint64_t invalid_byps_hc_comp  : 1;  /**< [ 24: 24](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_HC_COMP] value. */
        uint64_t invalid_hc_in_ena     : 1;  /**< [ 23: 23](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HC_IN_ENA] value. */
        uint64_t invalid_filler        : 1;  /**< [ 22: 22](RO/H) Invalid TDEC_LTE_TASK_CFG_S[FILLER] value. */
        uint64_t invalid_byps_bit_sel  : 1;  /**< [ 21: 21](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_BIT_SEL] value. */
        uint64_t invalid_byps_tb_proc  : 1;  /**< [ 20: 20](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_TB_PROC] value. */
        uint64_t invalid_num_layers    : 1;  /**< [ 19: 19](RO/H) Invalid TDEC_LTE_TASK_CFG_S[NUM_LAYERS] value. */
        uint64_t invalid_byps_dec      : 1;  /**< [ 18: 18](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_DEC] value. */
        uint64_t invalid_mod_order     : 1;  /**< [ 17: 17](RO/H) Invalid TDEC_LTE_TASK_CFG_S[MOD_ORDER] value. */
        uint64_t invalid_byps_layer_demap : 1;/**< [ 16: 16](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_LAYER_DEMAP] value. */
        uint64_t reserved_15           : 1;
        uint64_t invalid_byps_crc_msk  : 1;  /**< [ 14: 14](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_CRC_MSK] value. */
        uint64_t invalid_rv_idx        : 1;  /**< [ 13: 13](RO/H) Invalid TDEC_LTE_TASK_CFG_S[RV_IDX] value. */
        uint64_t invalid_gamma         : 1;  /**< [ 12: 12](RO/H) Invalid TDEC_LTE_TASK_CFG_S[GAMMA] value. */
        uint64_t invalid_first_cb_rm   : 1;  /**< [ 11: 11](RO/H) Invalid TDEC_LTE_TASK_CFG_S[FIRST_CB_RM] value. */
        uint64_t invalid_first_cb_size : 1;  /**< [ 10: 10](RO/H) Invalid TDEC_LTE_TASK_CFG_S[FIRST_CB_SIZE] value. */
        uint64_t invalid_tx_bits       : 1;  /**< [  9:  9](RO/H) Invalid TDEC_LTE_TASK_CFG_S[TX_BITS] value. */
        uint64_t invalid_payload       : 1;  /**< [  8:  8](RO/H) Invalid TDEC_LTE_TASK_CFG_S[PAYLOAD] value. */
        uint64_t invalid_num_cb        : 1;  /**< [  7:  7](RO/H) Invalid TDEC_LTE_TASK_CFG_S[NUM_CB] value. */
        uint64_t reserved_6            : 1;
        uint64_t error5                : 1;  /**< [  5:  5](RO/H) Reserved.
                                                                 Internal:
                                                                 The decoder core implements the check described below, but there
                                                                 doesn't seem to be any prohibition of this setting in the spec.
                                                                 Invalid combination of TDEC_LTE_TASK_CFG_S[BYPS_BIT_SEL] = 1 and
                                                                 non-zero TDEC_LTE_TASK_CFG_S[DEC_RND]. */
        uint64_t error4                : 1;  /**< [  4:  4](RO/H) Invalid combination of TDEC_LTE_TASK_CFG_S[BYPS_DEC],
                                                                 TDEC_LTE_TASK_CFG_S[HD_OUT_ENA], TDEC_LTE_TASK_CFG_S[REENC_ENA],
                                                                 and TDEC_LTE_TASK_CFG_S[SO_ENA] (decoded and re-encoded outputs not
                                                                 available when TDEC_LTE_TASK_CFG_S[BYPS_DEC] = 1). */
        uint64_t reserved_3            : 1;
        uint64_t error2                : 1;  /**< [  2:  2](RO/H) Invalid combination of TDEC_LTE_TASK_CFG_S[HC_OUT_ENA] = 0 and
                                                                 TDEC_LTE_TASK_CFG_S[BYPS_DEC] = 1. */
        uint64_t error1                : 1;  /**< [  1:  1](RO/H) Invalid combination of TDEC_LTE_TASK_CFG_S[HD_OUT_ENA],
                                                                 TDEC_LTE_TASK_CFG_S[SO_ENA], TDEC_LTE_TASK_CFG_S[HC_OUT_ENA],
                                                                 TDEC_LTE_TASK_CFG_S[REENC_ENA].  At least one output must be selected. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t error1                : 1;  /**< [  1:  1](RO/H) Invalid combination of TDEC_LTE_TASK_CFG_S[HD_OUT_ENA],
                                                                 TDEC_LTE_TASK_CFG_S[SO_ENA], TDEC_LTE_TASK_CFG_S[HC_OUT_ENA],
                                                                 TDEC_LTE_TASK_CFG_S[REENC_ENA].  At least one output must be selected. */
        uint64_t error2                : 1;  /**< [  2:  2](RO/H) Invalid combination of TDEC_LTE_TASK_CFG_S[HC_OUT_ENA] = 0 and
                                                                 TDEC_LTE_TASK_CFG_S[BYPS_DEC] = 1. */
        uint64_t reserved_3            : 1;
        uint64_t error4                : 1;  /**< [  4:  4](RO/H) Invalid combination of TDEC_LTE_TASK_CFG_S[BYPS_DEC],
                                                                 TDEC_LTE_TASK_CFG_S[HD_OUT_ENA], TDEC_LTE_TASK_CFG_S[REENC_ENA],
                                                                 and TDEC_LTE_TASK_CFG_S[SO_ENA] (decoded and re-encoded outputs not
                                                                 available when TDEC_LTE_TASK_CFG_S[BYPS_DEC] = 1). */
        uint64_t error5                : 1;  /**< [  5:  5](RO/H) Reserved.
                                                                 Internal:
                                                                 The decoder core implements the check described below, but there
                                                                 doesn't seem to be any prohibition of this setting in the spec.
                                                                 Invalid combination of TDEC_LTE_TASK_CFG_S[BYPS_BIT_SEL] = 1 and
                                                                 non-zero TDEC_LTE_TASK_CFG_S[DEC_RND]. */
        uint64_t reserved_6            : 1;
        uint64_t invalid_num_cb        : 1;  /**< [  7:  7](RO/H) Invalid TDEC_LTE_TASK_CFG_S[NUM_CB] value. */
        uint64_t invalid_payload       : 1;  /**< [  8:  8](RO/H) Invalid TDEC_LTE_TASK_CFG_S[PAYLOAD] value. */
        uint64_t invalid_tx_bits       : 1;  /**< [  9:  9](RO/H) Invalid TDEC_LTE_TASK_CFG_S[TX_BITS] value. */
        uint64_t invalid_first_cb_size : 1;  /**< [ 10: 10](RO/H) Invalid TDEC_LTE_TASK_CFG_S[FIRST_CB_SIZE] value. */
        uint64_t invalid_first_cb_rm   : 1;  /**< [ 11: 11](RO/H) Invalid TDEC_LTE_TASK_CFG_S[FIRST_CB_RM] value. */
        uint64_t invalid_gamma         : 1;  /**< [ 12: 12](RO/H) Invalid TDEC_LTE_TASK_CFG_S[GAMMA] value. */
        uint64_t invalid_rv_idx        : 1;  /**< [ 13: 13](RO/H) Invalid TDEC_LTE_TASK_CFG_S[RV_IDX] value. */
        uint64_t invalid_byps_crc_msk  : 1;  /**< [ 14: 14](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_CRC_MSK] value. */
        uint64_t reserved_15           : 1;
        uint64_t invalid_byps_layer_demap : 1;/**< [ 16: 16](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_LAYER_DEMAP] value. */
        uint64_t invalid_mod_order     : 1;  /**< [ 17: 17](RO/H) Invalid TDEC_LTE_TASK_CFG_S[MOD_ORDER] value. */
        uint64_t invalid_byps_dec      : 1;  /**< [ 18: 18](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_DEC] value. */
        uint64_t invalid_num_layers    : 1;  /**< [ 19: 19](RO/H) Invalid TDEC_LTE_TASK_CFG_S[NUM_LAYERS] value. */
        uint64_t invalid_byps_tb_proc  : 1;  /**< [ 20: 20](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_TB_PROC] value. */
        uint64_t invalid_byps_bit_sel  : 1;  /**< [ 21: 21](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_BIT_SEL] value. */
        uint64_t invalid_filler        : 1;  /**< [ 22: 22](RO/H) Invalid TDEC_LTE_TASK_CFG_S[FILLER] value. */
        uint64_t invalid_hc_in_ena     : 1;  /**< [ 23: 23](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HC_IN_ENA] value. */
        uint64_t invalid_byps_hc_comp  : 1;  /**< [ 24: 24](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_HC_COMP] value. */
        uint64_t invalid_hc_out_ena    : 1;  /**< [ 25: 25](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HC_OUT_ENA] value. */
        uint64_t invalid_k0_p          : 1;  /**< [ 26: 26](RO/H) Invalid TDEC_LTE_TASK_CFG_S[K0_P] value. */
        uint64_t invalid_byps_llr_negate : 1;/**< [ 27: 27](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_LLR_NEGATE] value. */
        uint64_t invalid_gain_i        : 1;  /**< [ 28: 28](RO/H) Invalid TDEC_LTE_TASK_CFG_S[GAIN_I] value. */
        uint64_t invalid_gain_h        : 1;  /**< [ 29: 29](RO/H) Invalid TDEC_LTE_TASK_CFG_S[GAIN_H] value. */
        uint64_t invalid_dec_rnd       : 1;  /**< [ 30: 30](RO/H) Invalid TDEC_LTE_TASK_CFG_S[DEC_RND] value. */
        uint64_t invalid_harq_rnd      : 1;  /**< [ 31: 31](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HARQ_RND] value. */
        uint64_t invalid_half_it       : 1;  /**< [ 32: 32](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HALF_IT] value. */
        uint64_t invalid_dyn_stop      : 1;  /**< [ 33: 33](RO/H) Invalid TDEC_LTE_TASK_CFG_S[DYN_STOP] value. */
        uint64_t invalid_thresh        : 1;  /**< [ 34: 34](RO/H) Invalid TDEC_LTE_TASK_CFG_S[THRESH] value. */
        uint64_t invalid_tbl_sel       : 1;  /**< [ 35: 35](RO/H) Invalid TDEC_LTE_TASK_CFG_S[TBL_SEL] value. */
        uint64_t invalid_sw_speed      : 1;  /**< [ 36: 36](RO/H) Invalid TDEC_LTE_TASK_CFG_S[SW_SPEED] value. */
        uint64_t invalid_algo          : 1;  /**< [ 37: 37](RO/H) Invalid TDEC_LTE_TASK_CFG_S[ALGO] value. */
        uint64_t invalid_hd_out_ena    : 1;  /**< [ 38: 38](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HD_OUT_ENA] value. */
        uint64_t invalid_hd_bit_order  : 1;  /**< [ 39: 39](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HD_BIT_ORDER] value. */
        uint64_t invalid_hd_byte_order : 1;  /**< [ 40: 40](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HD_BYTE_ORDER] value. */
        uint64_t invalid_cb_crc        : 1;  /**< [ 41: 41](RO/H) Invalid TDEC_LTE_TASK_CFG_S[CB_CRC] value. */
        uint64_t invalid_so_ena        : 1;  /**< [ 42: 42](RO/H) Invalid TDEC_LTE_TASK_CFG_S[SO_ENA] value. */
        uint64_t invalid_byps_bs_so    : 1;  /**< [ 43: 43](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_BS_SO] value. */
        uint64_t invalid_half_it_so    : 1;  /**< [ 44: 44](RO/H) Invalid TDEC_LTE_TASK_CFG_S[HALF_IT_SO] value. */
        uint64_t invalid_so_sel        : 1;  /**< [ 45: 45](RO/H) Invalid TDEC_LTE_TASK_CFG_S[SO_SEL] value. */
        uint64_t invalid_reenc_ena     : 1;  /**< [ 46: 46](RO/H) Invalid TDEC_LTE_TASK_CFG_S[REENC_ENA] value. */
        uint64_t invalid_byps_rm       : 1;  /**< [ 47: 47](RO/H) Invalid TDEC_LTE_TASK_CFG_S[BYPS_RM] value. */
        uint64_t reserved_48           : 1;
        uint64_t invalid_symb_byte_align : 1;/**< [ 49: 49](RO/H) Invalid TDEC_LTE_TASK_CFG_S[SYMB_BYTE_ALIGN] value. */
        uint64_t invalid_reenc_bit_order : 1;/**< [ 50: 50](RO/H) Invalid TDEC_LTE_TASK_CFG_S[REENC_BIT_ORDER] value. */
        uint64_t invalid_reenc_byte_order : 1;/**< [ 51: 51](RO/H) Invalid TDEC_LTE_TASK_CFG_S[REENC_BYTE_ORDER] value. */
        uint64_t invalid_bypass_scrambling : 1;/**< [ 52: 52](RO/H) Reserved.
                                                                 Internal:
                                                                 Was invalid bypass_scrambling mode, but that has been removed
                                                                 from the decoder core. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_config_err_flags_reg_s cn; */
};
typedef union cavm_tdecx_tc_config_err_flags_reg cavm_tdecx_tc_config_err_flags_reg_t;

static inline uint64_t CAVM_TDECX_TC_CONFIG_ERR_FLAGS_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_CONFIG_ERR_FLAGS_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043601040ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043601040ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_TC_CONFIG_ERR_FLAGS_REG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_CONFIG_ERR_FLAGS_REG(a) cavm_tdecx_tc_config_err_flags_reg_t
#define bustype_CAVM_TDECX_TC_CONFIG_ERR_FLAGS_REG(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_CONFIG_ERR_FLAGS_REG(a) "TDECX_TC_CONFIG_ERR_FLAGS_REG"
#define busnum_CAVM_TDECX_TC_CONFIG_ERR_FLAGS_REG(a) (a)
#define arguments_CAVM_TDECX_TC_CONFIG_ERR_FLAGS_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_tc_config_reg#
 *
 * INTERNAL: TC Task Config Registers
 *
 * TC task config registers.
 */
union cavm_tdecx_tc_config_regx
{
    uint64_t u;
    struct cavm_tdecx_tc_config_regx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_config_regx_s cn; */
};
typedef union cavm_tdecx_tc_config_regx cavm_tdecx_tc_config_regx_t;

static inline uint64_t CAVM_TDECX_TC_CONFIG_REGX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_CONFIG_REGX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=12)))
        return 0x87e043601400ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0xf);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=2) && (b<=12)))
        return 0x87e043601400ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0xf);
    __cavm_csr_fatal("TDECX_TC_CONFIG_REGX", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_CONFIG_REGX(a,b) cavm_tdecx_tc_config_regx_t
#define bustype_CAVM_TDECX_TC_CONFIG_REGX(a,b) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_CONFIG_REGX(a,b) "TDECX_TC_CONFIG_REGX"
#define busnum_CAVM_TDECX_TC_CONFIG_REGX(a,b) (a)
#define arguments_CAVM_TDECX_TC_CONFIG_REGX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) tdec#_tc_control_reg
 *
 * TDEC Decoder Control Register
 * This register configures the TDEC internal decoder core.
 */
union cavm_tdecx_tc_control_reg
{
    uint64_t u;
    struct cavm_tdecx_tc_control_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t single_task_chnl_en   : 1;  /**< [  4:  4](R/W) Must be set to 0.
                                                                 Internal:
                                                                 This bit is reserved because the decoder core only has one channel mode now. */
        uint64_t single_task_phy_en    : 1;  /**< [  3:  3](R/W) Must be set to 0.
                                                                 Internal:
                                                                 This bit is reserved because the decoder core only has one PHY mode now. */
        uint64_t single_task_en        : 1;  /**< [  2:  2](R/W) When set to 1, the core will always wait until idle before
                                                                 starting the next task. */
        uint64_t cfg_chk_dis           : 1;  /**< [  1:  1](R/W) When set to 1, disables config checks. Tasks with
                                                                 invalid configurations will still be processed. */
        uint64_t clk_gate_dis          : 1;  /**< [  0:  0](R/W) When set to 1, disables clock gating. */
#else /* Word 0 - Little Endian */
        uint64_t clk_gate_dis          : 1;  /**< [  0:  0](R/W) When set to 1, disables clock gating. */
        uint64_t cfg_chk_dis           : 1;  /**< [  1:  1](R/W) When set to 1, disables config checks. Tasks with
                                                                 invalid configurations will still be processed. */
        uint64_t single_task_en        : 1;  /**< [  2:  2](R/W) When set to 1, the core will always wait until idle before
                                                                 starting the next task. */
        uint64_t single_task_phy_en    : 1;  /**< [  3:  3](R/W) Must be set to 0.
                                                                 Internal:
                                                                 This bit is reserved because the decoder core only has one PHY mode now. */
        uint64_t single_task_chnl_en   : 1;  /**< [  4:  4](R/W) Must be set to 0.
                                                                 Internal:
                                                                 This bit is reserved because the decoder core only has one channel mode now. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_control_reg_s cn; */
};
typedef union cavm_tdecx_tc_control_reg cavm_tdecx_tc_control_reg_t;

static inline uint64_t CAVM_TDECX_TC_CONTROL_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_CONTROL_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043601010ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043601010ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_TC_CONTROL_REG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_CONTROL_REG(a) cavm_tdecx_tc_control_reg_t
#define bustype_CAVM_TDECX_TC_CONTROL_REG(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_CONTROL_REG(a) "TDECX_TC_CONTROL_REG"
#define busnum_CAVM_TDECX_TC_CONTROL_REG(a) (a)
#define arguments_CAVM_TDECX_TC_CONTROL_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_tc_error_mask_reg
 *
 * TDEC Decoder Core Error Mask Register
 * This register enables internal decoder errors. Errors reported in
 * TDEC()_TC_ERROR_REG will generate an error signal only when the
 * corresponding bit is set in TDEC()_TC_ERROR_MASK_REG[ERR_MASK].
 */
union cavm_tdecx_tc_error_mask_reg
{
    uint64_t u;
    struct cavm_tdecx_tc_error_mask_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
#else /* Word 0 - Little Endian */
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_error_mask_reg_s cn; */
};
typedef union cavm_tdecx_tc_error_mask_reg cavm_tdecx_tc_error_mask_reg_t;

static inline uint64_t CAVM_TDECX_TC_ERROR_MASK_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_ERROR_MASK_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043601030ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043601030ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_TC_ERROR_MASK_REG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_ERROR_MASK_REG(a) cavm_tdecx_tc_error_mask_reg_t
#define bustype_CAVM_TDECX_TC_ERROR_MASK_REG(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_ERROR_MASK_REG(a) "TDECX_TC_ERROR_MASK_REG"
#define busnum_CAVM_TDECX_TC_ERROR_MASK_REG(a) (a)
#define arguments_CAVM_TDECX_TC_ERROR_MASK_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_tc_error_reg
 *
 * TDEC Decoder Error Register
 * This register reports various error conditions.
 *
 * All errors reported in this register are reported as FATAL errors, and the
 * MHBW registers can be inspected to determine the job tag(s) associated with
 * the error(s).
 */
union cavm_tdecx_tc_error_reg
{
    uint64_t u;
    struct cavm_tdecx_tc_error_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t hcout_int_err         : 1;  /**< [ 19: 19](R/W1C/H) HARQ output internal error due to insufficient data. */
        uint64_t hcin_input_err        : 1;  /**< [ 18: 18](R/W1C/H) HARQ input error due to one or more missing CB. */
        uint64_t hcin_size_err         : 1;  /**< [ 17: 17](R/W1C/H) HARQ input size error. */
        uint64_t reserved_9_16         : 8;
        uint64_t inv_cfg               : 1;  /**< [  8:  8](R/W1C/H) Invalid task configuration -- aborted job.  Further information is
                                                                 captured in TDEC()_TC_CONFIG_ERR_FLAGS_REG. */
        uint64_t reg_mask_err          : 4;  /**< [  7:  4](RAZ) Reserved. */
        uint64_t ign_read              : 1;  /**< [  3:  3](R/W1C/H) Ignored read access error -- one already in progress. */
        uint64_t inv_read              : 1;  /**< [  2:  2](R/W1C/H) Invalid read access error. */
        uint64_t inv_write             : 1;  /**< [  1:  1](R/W1C/H) Invalid write access error. */
        uint64_t inv_start             : 1;  /**< [  0:  0](R/W1C/H) Invalid start task error. */
#else /* Word 0 - Little Endian */
        uint64_t inv_start             : 1;  /**< [  0:  0](R/W1C/H) Invalid start task error. */
        uint64_t inv_write             : 1;  /**< [  1:  1](R/W1C/H) Invalid write access error. */
        uint64_t inv_read              : 1;  /**< [  2:  2](R/W1C/H) Invalid read access error. */
        uint64_t ign_read              : 1;  /**< [  3:  3](R/W1C/H) Ignored read access error -- one already in progress. */
        uint64_t reg_mask_err          : 4;  /**< [  7:  4](RAZ) Reserved. */
        uint64_t inv_cfg               : 1;  /**< [  8:  8](R/W1C/H) Invalid task configuration -- aborted job.  Further information is
                                                                 captured in TDEC()_TC_CONFIG_ERR_FLAGS_REG. */
        uint64_t reserved_9_16         : 8;
        uint64_t hcin_size_err         : 1;  /**< [ 17: 17](R/W1C/H) HARQ input size error. */
        uint64_t hcin_input_err        : 1;  /**< [ 18: 18](R/W1C/H) HARQ input error due to one or more missing CB. */
        uint64_t hcout_int_err         : 1;  /**< [ 19: 19](R/W1C/H) HARQ output internal error due to insufficient data. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_error_reg_s cn; */
};
typedef union cavm_tdecx_tc_error_reg cavm_tdecx_tc_error_reg_t;

static inline uint64_t CAVM_TDECX_TC_ERROR_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_ERROR_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043601038ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043601038ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_TC_ERROR_REG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_ERROR_REG(a) cavm_tdecx_tc_error_reg_t
#define bustype_CAVM_TDECX_TC_ERROR_REG(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_ERROR_REG(a) "TDECX_TC_ERROR_REG"
#define busnum_CAVM_TDECX_TC_ERROR_REG(a) (a)
#define arguments_CAVM_TDECX_TC_ERROR_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_tc_main_reset_reg
 *
 * TDEC Decoder Reset Register
 * Internal decoder core reset register.
 */
union cavm_tdecx_tc_main_reset_reg
{
    uint64_t u;
    struct cavm_tdecx_tc_main_reset_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Reset bit.  Write any value to reset the TDEC decoder core. */
#else /* Word 0 - Little Endian */
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Reset bit.  Write any value to reset the TDEC decoder core. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_main_reset_reg_s cn; */
};
typedef union cavm_tdecx_tc_main_reset_reg cavm_tdecx_tc_main_reset_reg_t;

static inline uint64_t CAVM_TDECX_TC_MAIN_RESET_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_MAIN_RESET_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043601000ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043601000ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_TC_MAIN_RESET_REG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_MAIN_RESET_REG(a) cavm_tdecx_tc_main_reset_reg_t
#define bustype_CAVM_TDECX_TC_MAIN_RESET_REG(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_MAIN_RESET_REG(a) "TDECX_TC_MAIN_RESET_REG"
#define busnum_CAVM_TDECX_TC_MAIN_RESET_REG(a) (a)
#define arguments_CAVM_TDECX_TC_MAIN_RESET_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_tc_main_start_reg
 *
 * INTERNAL: TC Start Register
 *
 * TC start register.
 */
union cavm_tdecx_tc_main_start_reg
{
    uint64_t u;
    struct cavm_tdecx_tc_main_start_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
#else /* Word 0 - Little Endian */
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_main_start_reg_s cn; */
};
typedef union cavm_tdecx_tc_main_start_reg cavm_tdecx_tc_main_start_reg_t;

static inline uint64_t CAVM_TDECX_TC_MAIN_START_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_MAIN_START_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043601008ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043601008ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_TC_MAIN_START_REG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_MAIN_START_REG(a) cavm_tdecx_tc_main_start_reg_t
#define bustype_CAVM_TDECX_TC_MAIN_START_REG(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_MAIN_START_REG(a) "TDECX_TC_MAIN_START_REG"
#define busnum_CAVM_TDECX_TC_MAIN_START_REG(a) (a)
#define arguments_CAVM_TDECX_TC_MAIN_START_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_tc_mon_reg#
 *
 * INTERNAL: TC Monitoring Registers
 *
 * TC mon registers.
 */
union cavm_tdecx_tc_mon_regx
{
    uint64_t u;
    struct cavm_tdecx_tc_mon_regx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bus_val               : 16; /**< [ 15:  0](RO/H) Output bus monitoring values. */
#else /* Word 0 - Little Endian */
        uint64_t bus_val               : 16; /**< [ 15:  0](RO/H) Output bus monitoring values. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_mon_regx_s cn; */
};
typedef union cavm_tdecx_tc_mon_regx cavm_tdecx_tc_mon_regx_t;

static inline uint64_t CAVM_TDECX_TC_MON_REGX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_MON_REGX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=2) && (b<=3)))
        return 0x87e043601300ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=2) && (b<=3)))
        return 0x87e043601300ll + 0x8000ll * ((a) & 0x3) + 8ll * ((b) & 0x3);
    __cavm_csr_fatal("TDECX_TC_MON_REGX", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_MON_REGX(a,b) cavm_tdecx_tc_mon_regx_t
#define bustype_CAVM_TDECX_TC_MON_REGX(a,b) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_MON_REGX(a,b) "TDECX_TC_MON_REGX"
#define busnum_CAVM_TDECX_TC_MON_REGX(a,b) (a)
#define arguments_CAVM_TDECX_TC_MON_REGX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) tdec#_tc_status0_reg
 *
 * TDEC Decoder Status Register
 * This register reports status from the internal decoder core.
 */
union cavm_tdecx_tc_status0_reg
{
    uint64_t u;
    struct cavm_tdecx_tc_status0_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t core_stat             : 32; /**< [ 63: 32](RO/H) Reserved.
                                                                 Internal:
                                                                 un-documented, core-dependent status bits. */
        uint64_t reserved_1_31         : 31;
        uint64_t idle                  : 1;  /**< [  0:  0](RO/H) Idle status bit. */
#else /* Word 0 - Little Endian */
        uint64_t idle                  : 1;  /**< [  0:  0](RO/H) Idle status bit. */
        uint64_t reserved_1_31         : 31;
        uint64_t core_stat             : 32; /**< [ 63: 32](RO/H) Reserved.
                                                                 Internal:
                                                                 un-documented, core-dependent status bits. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_status0_reg_s cn; */
};
typedef union cavm_tdecx_tc_status0_reg cavm_tdecx_tc_status0_reg_t;

static inline uint64_t CAVM_TDECX_TC_STATUS0_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_STATUS0_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043601020ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043601020ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_TC_STATUS0_REG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_STATUS0_REG(a) cavm_tdecx_tc_status0_reg_t
#define bustype_CAVM_TDECX_TC_STATUS0_REG(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_STATUS0_REG(a) "TDECX_TC_STATUS0_REG"
#define busnum_CAVM_TDECX_TC_STATUS0_REG(a) (a)
#define arguments_CAVM_TDECX_TC_STATUS0_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) tdec#_tc_status1_reg
 *
 * INTERNAL: TC Status 1 Register
 *
 * TC status 1 register.
 * Internal:
 * There's no register implemented in the TC core, but removing this
 * from the CSR file might change the csr_bridge RTL.
 */
union cavm_tdecx_tc_status1_reg
{
    uint64_t u;
    struct cavm_tdecx_tc_status1_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t core_stat             : 64; /**< [ 63:  0](RO) Core-dependent bits. */
#else /* Word 0 - Little Endian */
        uint64_t core_stat             : 64; /**< [ 63:  0](RO) Core-dependent bits. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tdecx_tc_status1_reg_s cn; */
};
typedef union cavm_tdecx_tc_status1_reg cavm_tdecx_tc_status1_reg_t;

static inline uint64_t CAVM_TDECX_TC_STATUS1_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TDECX_TC_STATUS1_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x87e043601028ll + 0x8000ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043601028ll + 0x8000ll * ((a) & 0x3);
    __cavm_csr_fatal("TDECX_TC_STATUS1_REG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_TDECX_TC_STATUS1_REG(a) cavm_tdecx_tc_status1_reg_t
#define bustype_CAVM_TDECX_TC_STATUS1_REG(a) CSR_TYPE_RSL
#define basename_CAVM_TDECX_TC_STATUS1_REG(a) "TDECX_TC_STATUS1_REG"
#define busnum_CAVM_TDECX_TC_STATUS1_REG(a) (a)
#define arguments_CAVM_TDECX_TC_STATUS1_REG(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_TDEC_H__ */
