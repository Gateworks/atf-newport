#ifndef __CAVM_CSRS_LENC_H__
#define __CAVM_CSRS_LENC_H__
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
 * OcteonTX LENC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure lenc_cb_cfg_s
 *
 * LENC Code Block Configuration Structure
 * This structure specifies the code block configuration.
 */
union cavm_lenc_cb_cfg_s
{
    uint64_t u[2];
    struct cavm_lenc_cb_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rm_e                  : 21; /**< [ 63: 43] Rate matching size. Valid range is [ [CB_SIZE] / 0.95 , 0x166500 ].
                                                                 * Must be \> 0x0.
                                                                 * Must be an exact multiple of LENC_TASK_CFG_S[MOD_ORDER]. */
        uint64_t nfiller               : 14; /**< [ 42: 29] The number of filler bits. */
        uint64_t reserved_26_28        : 3;
        uint64_t cb_size               : 14; /**< [ 25: 12] The code block size including CB CRC. It corresponds to 'K' in 38.212
                                                                 and includes filler bits. K = 22*Z for BG1,  K = 10*Z for BG2.
                                                                 The valid range is [0x28, 0x2100], where the minimum size is the
                                                                 minimum LENC_TASK_CFG_S[TB_SIZE] of 24 bits plus the 16-bit TB CRC. */
        uint64_t code_id               : 3;  /**< [ 11:  9] Reserved.
                                                                 Internal:
                                                                 Used only in DOCSIS.
                                                                 0x3: UL traffic, Long (Z=360).
                                                                 0x4: UL traffic, Medium (Z=180).
                                                                 0x5: UL traffic, Short (Z=56).
                                                                 0x6: Initial ranging.
                                                                 0x7: Fine ranging.
                                                                 0x0-0x2 : Reserved. */
        uint64_t num_cb                : 9;  /**< [  8:  0] The number of consecutive code blocks with this CB configuration. Valid range is [0x1, 0x98]. */
#else /* Word 0 - Little Endian */
        uint64_t num_cb                : 9;  /**< [  8:  0] The number of consecutive code blocks with this CB configuration. Valid range is [0x1, 0x98]. */
        uint64_t code_id               : 3;  /**< [ 11:  9] Reserved.
                                                                 Internal:
                                                                 Used only in DOCSIS.
                                                                 0x3: UL traffic, Long (Z=360).
                                                                 0x4: UL traffic, Medium (Z=180).
                                                                 0x5: UL traffic, Short (Z=56).
                                                                 0x6: Initial ranging.
                                                                 0x7: Fine ranging.
                                                                 0x0-0x2 : Reserved. */
        uint64_t cb_size               : 14; /**< [ 25: 12] The code block size including CB CRC. It corresponds to 'K' in 38.212
                                                                 and includes filler bits. K = 22*Z for BG1,  K = 10*Z for BG2.
                                                                 The valid range is [0x28, 0x2100], where the minimum size is the
                                                                 minimum LENC_TASK_CFG_S[TB_SIZE] of 24 bits plus the 16-bit TB CRC. */
        uint64_t reserved_26_28        : 3;
        uint64_t nfiller               : 14; /**< [ 42: 29] The number of filler bits. */
        uint64_t rm_e                  : 21; /**< [ 63: 43] Rate matching size. Valid range is [ [CB_SIZE] / 0.95 , 0x166500 ].
                                                                 * Must be \> 0x0.
                                                                 * Must be an exact multiple of LENC_TASK_CFG_S[MOD_ORDER]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_72_127       : 56;
        uint64_t next_cb_cfg_consecutive : 1;/**< [ 71: 71] Consecutive CB_CFG indicator:

                                                                 _ 0 = The next CB_CFG has its payload not contiguous with the current CB_CFG.
                                                                 This implies trimming for the current CB_CFG and prefix trimming for the next
                                                                 CB_CFG.

                                                                 _ 1 = The next CB_CFG of the task has its payload contiguous with the current
                                                                 CB_CFG. This implies no prefix/suffix trimming.

                                                                 [NEXT_CB_CFG_CONSECUTIVE] must be set to 0 for the last CB_CFG. */
        uint64_t cb_skip_flag          : 1;  /**< [ 70: 70] CB skip flag:
                                                                 0 = CBs belonging to this CB_CFG entry go through the whole processing chain.
                                                                 1 = Only TB CRC is calculated for these CBs. All other operations are bypassed.
                                                                 [CB_SKIP_FLAG] must be set to 0 for the last CB_CFG. */
        uint64_t prefix_bit_idx        : 6;  /**< [ 69: 64] The bit position of the first CB in first 64 bits. This field is ignored
                                                                 if the current CB_CFG is not
                                                                 immediately following the previous CB_CFG. Valid range is [0x0, 0x3F].  Must be 0x0 for
                                                                 the first CB_CFG when LENC_TASK_CFG_S[TB_CRC_FROM_CFG_FLAG] = 0. */
#else /* Word 1 - Little Endian */
        uint64_t prefix_bit_idx        : 6;  /**< [ 69: 64] The bit position of the first CB in first 64 bits. This field is ignored
                                                                 if the current CB_CFG is not
                                                                 immediately following the previous CB_CFG. Valid range is [0x0, 0x3F].  Must be 0x0 for
                                                                 the first CB_CFG when LENC_TASK_CFG_S[TB_CRC_FROM_CFG_FLAG] = 0. */
        uint64_t cb_skip_flag          : 1;  /**< [ 70: 70] CB skip flag:
                                                                 0 = CBs belonging to this CB_CFG entry go through the whole processing chain.
                                                                 1 = Only TB CRC is calculated for these CBs. All other operations are bypassed.
                                                                 [CB_SKIP_FLAG] must be set to 0 for the last CB_CFG. */
        uint64_t next_cb_cfg_consecutive : 1;/**< [ 71: 71] Consecutive CB_CFG indicator:

                                                                 _ 0 = The next CB_CFG has its payload not contiguous with the current CB_CFG.
                                                                 This implies trimming for the current CB_CFG and prefix trimming for the next
                                                                 CB_CFG.

                                                                 _ 1 = The next CB_CFG of the task has its payload contiguous with the current
                                                                 CB_CFG. This implies no prefix/suffix trimming.

                                                                 [NEXT_CB_CFG_CONSECUTIVE] must be set to 0 for the last CB_CFG. */
        uint64_t reserved_72_127       : 56;
#endif /* Word 1 - End */
    } s;
    /* struct cavm_lenc_cb_cfg_s_s cn; */
};

/**
 * Structure lenc_common_cfg_s
 *
 * LENC Common Job Configuration Structure
 * This structure defines the format of the first word of the job
 * configuration for all LENC jobs.
 */
union cavm_lenc_common_cfg_s
{
    uint64_t u;
    struct cavm_lenc_common_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t phy_mode              : 1;  /**< [  5:  5] The job type.
                                                                 0 = 3GPP NR.
                                                                 1 = Reserved.

                                                                 Internal:
                                                                 1 = DOCSIS. */
        uint64_t num_tasks             : 5;  /**< [  4:  0] Number of tasks in the job.  Valid range is [0x1, 0x10]. */
#else /* Word 0 - Little Endian */
        uint64_t num_tasks             : 5;  /**< [  4:  0] Number of tasks in the job.  Valid range is [0x1, 0x10]. */
        uint64_t phy_mode              : 1;  /**< [  5:  5] The job type.
                                                                 0 = 3GPP NR.
                                                                 1 = Reserved.

                                                                 Internal:
                                                                 1 = DOCSIS. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lenc_common_cfg_s_s cn; */
};

/**
 * Structure lenc_task_cfg_s
 *
 * LENC Task Configuration Structure
 * This structure defines the configuration parameters for an individual
 * task. The job configuration section for a LENC job should
 * contain one of these structures for each task.
 */
union cavm_lenc_task_cfg_s
{
    uint64_t u[8];
    struct cavm_lenc_task_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mod_order             : 4;  /**< [ 63: 60] Modulation order:
                                                                 0x1 = {pi}/2 BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16-QAM.
                                                                 0x6 = 64-QAM.
                                                                 0x8 = 256-QAM.
                                                                 0xA = 1024-QAM. */
        uint64_t bypass_scrambling     : 1;  /**< [ 59: 59] Bypass scrambling when set. */
        uint64_t input_data_order      : 3;  /**< [ 58: 56] Bit 56:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Bits \<58:57\>:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2.
                                                                 0x3 = Reserved. */
        uint64_t tb_crc                : 24; /**< [ 55: 32] TB CRC calculated for initial transmission. If CRC length is 16, the 16 least-significant bits
                                                                 of [TB_CRC] are valid. */
        uint64_t tb_crc_from_cfg_flag  : 1;  /**< [ 31: 31] _ 0 = Do not use [TB_CRC]. If [TB_CRC_SELECT] = 0x1 or 0x2, TB CRC is calculated internally.

                                                                 _ 1 = Append [TB_CRC] of length selected by [TB_CRC_SELECT] = 0x1 or 0x2 to the
                                                                 end of the input bits of the current task. */
        uint64_t tb_crc_output_flag    : 1;  /**< [ 30: 30] Output raw TB CRC:
                                                                 0 = no raw TB CRC (before scrambling) output.
                                                                 1 = raw TB CRC (before scrambling) output.
                                                                 When [TB_CRC_SELECT] \> 0x0, [TB_CRC_OUTPUT_FLAG] must be 0. */
        uint64_t tb_crc_select         : 2;  /**< [ 29: 28] CRC polynomial used for the calculation of TB CRC and CB level TB CRC contribution.
                                                                 0x0 = no CRC (i.e. CRC added before Core).
                                                                 0x1 = use CRC-16.
                                                                 0x2 = use CRC-24A.
                                                                 0x3 = Reserved. */
        uint64_t reserved_27           : 1;
        uint64_t cb_crc_select         : 1;  /**< [ 26: 26] CB CRC polynomial select
                                                                 0 = no CRC.
                                                                 1 = use CRC-24B.
                                                                 When LENC_CB_CFG_S[NUM_CB] = 0x1, [CB_CRC_SELECT] must be 0.
                                                                 When LENC_CB_CFG_S[NUM_CB] \> 0x1 and [TB_CRC_SELECT] \> 0x0, [CB_CRC_SELECT] must be 1. */
        uint64_t basegraph             : 1;  /**< [ 25: 25] LDPC basegraph
                                                                 0 = BG1.
                                                                 1 = BG2. */
        uint64_t mixed_mod             : 1;  /**< [ 24: 24] Reserved.
                                                                 Internal:
                                                                 Used only in DOCSIS mode.

                                                                 0: Do not use mixed modulation.
                                                                 1: Use mixed modulation.
                                                                 Ignored if shortening is applied or when LENC_CB_CFG_S[CODE_ID] \> 0x0. */
        uint64_t num_cb_cfg            : 8;  /**< [ 23: 16] The number of CB configuration entries. Valid range is [0x1, 0x8]. */
        uint64_t task_id               : 16; /**< [ 15:  0] Each task in a job must have a unique ID. The task ID will be
                                                                 included in the output to correctly identify the output for each task. */
#else /* Word 0 - Little Endian */
        uint64_t task_id               : 16; /**< [ 15:  0] Each task in a job must have a unique ID. The task ID will be
                                                                 included in the output to correctly identify the output for each task. */
        uint64_t num_cb_cfg            : 8;  /**< [ 23: 16] The number of CB configuration entries. Valid range is [0x1, 0x8]. */
        uint64_t mixed_mod             : 1;  /**< [ 24: 24] Reserved.
                                                                 Internal:
                                                                 Used only in DOCSIS mode.

                                                                 0: Do not use mixed modulation.
                                                                 1: Use mixed modulation.
                                                                 Ignored if shortening is applied or when LENC_CB_CFG_S[CODE_ID] \> 0x0. */
        uint64_t basegraph             : 1;  /**< [ 25: 25] LDPC basegraph
                                                                 0 = BG1.
                                                                 1 = BG2. */
        uint64_t cb_crc_select         : 1;  /**< [ 26: 26] CB CRC polynomial select
                                                                 0 = no CRC.
                                                                 1 = use CRC-24B.
                                                                 When LENC_CB_CFG_S[NUM_CB] = 0x1, [CB_CRC_SELECT] must be 0.
                                                                 When LENC_CB_CFG_S[NUM_CB] \> 0x1 and [TB_CRC_SELECT] \> 0x0, [CB_CRC_SELECT] must be 1. */
        uint64_t reserved_27           : 1;
        uint64_t tb_crc_select         : 2;  /**< [ 29: 28] CRC polynomial used for the calculation of TB CRC and CB level TB CRC contribution.
                                                                 0x0 = no CRC (i.e. CRC added before Core).
                                                                 0x1 = use CRC-16.
                                                                 0x2 = use CRC-24A.
                                                                 0x3 = Reserved. */
        uint64_t tb_crc_output_flag    : 1;  /**< [ 30: 30] Output raw TB CRC:
                                                                 0 = no raw TB CRC (before scrambling) output.
                                                                 1 = raw TB CRC (before scrambling) output.
                                                                 When [TB_CRC_SELECT] \> 0x0, [TB_CRC_OUTPUT_FLAG] must be 0. */
        uint64_t tb_crc_from_cfg_flag  : 1;  /**< [ 31: 31] _ 0 = Do not use [TB_CRC]. If [TB_CRC_SELECT] = 0x1 or 0x2, TB CRC is calculated internally.

                                                                 _ 1 = Append [TB_CRC] of length selected by [TB_CRC_SELECT] = 0x1 or 0x2 to the
                                                                 end of the input bits of the current task. */
        uint64_t tb_crc                : 24; /**< [ 55: 32] TB CRC calculated for initial transmission. If CRC length is 16, the 16 least-significant bits
                                                                 of [TB_CRC] are valid. */
        uint64_t input_data_order      : 3;  /**< [ 58: 56] Bit 56:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Bits \<58:57\>:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2.
                                                                 0x3 = Reserved. */
        uint64_t bypass_scrambling     : 1;  /**< [ 59: 59] Bypass scrambling when set. */
        uint64_t mod_order             : 4;  /**< [ 63: 60] Modulation order:
                                                                 0x1 = {pi}/2 BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16-QAM.
                                                                 0x6 = 64-QAM.
                                                                 0x8 = 256-QAM.
                                                                 0xA = 1024-QAM. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t k0                    : 16; /**< [127:112] k0 value representing offset of Rx data in unpruned circular buffer as defined
                                                                 in Table 5.4.2.1-2 of [R1]. It must be less than [NCB_SIZE]. */
        uint64_t ncb_size              : 16; /**< [111: 96] Soft buffer size for each code block as specified in Section
                                                                 5.4.2.1 of [R1]. Maximum value is 0x6300. */
        uint64_t tb_size               : 32; /**< [ 95: 64] Transport Block size. It corresponds to 'A' defined in Section 5.1
                                                                 of [R1]. Valid range is [0x18, 0x138028]. */
#else /* Word 1 - Little Endian */
        uint64_t tb_size               : 32; /**< [ 95: 64] Transport Block size. It corresponds to 'A' defined in Section 5.1
                                                                 of [R1]. Valid range is [0x18, 0x138028]. */
        uint64_t ncb_size              : 16; /**< [111: 96] Soft buffer size for each code block as specified in Section
                                                                 5.4.2.1 of [R1]. Maximum value is 0x6300. */
        uint64_t k0                    : 16; /**< [127:112] k0 value representing offset of Rx data in unpruned circular buffer as defined
                                                                 in Table 5.4.2.1-2 of [R1]. It must be less than [NCB_SIZE]. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t scrambling_init       : 31; /**< [191:161] The initialization value of the 2nd m-sequence of the scrambler. */
        uint64_t bypass_segmentation   : 1;  /**< [160:160] When set to 0, the output is segmented, with extra padding inserted.
                                                                 See [SEG_PAD] for more details.

                                                                 When set to 1, the output bits are sent contiguously to output. */
        uint64_t symb_byte_aligned     : 2;  /**< [159:158] Select the alignment and interleaving for output bits.
                                                                 0x0 = Bypass mode. Bits are written consecutively, with no per-symbol
                                                                 alignment.
                                                                 0x1: Byte alignment for [MOD_ORDER] \< 0xA. Every [MOD_ORDER] bits are aligned to a bit
                                                                 boundary.
                                                                 0x2 = Interleaved byte alignment for [MOD_ORDER] = 0xA. For each symbol, the five
                                                                 even bits are packed in one byte, and the five odd bits are packed
                                                                 in the next byte.
                                                                 0x3 = Consecutive byte alignment for [MOD_ORDER] = 0xA. For each symbol, bits 0-4
                                                                 are written in one byte and bits 5-9 are written in the next
                                                                 subsequent byte. */
        uint64_t bypass_intlv          : 1;  /**< [157:157] Bypass bit interleaving when set. */
        uint64_t seg_pad               : 1;  /**< [156:156] This flag is used only when [BYPASS_SEGMENTATION] = 0 and ignored otherwise.

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x0, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x [MOD_ORDER] segments and padded with
                                                                 [MOD_ORDER] x [NUM_LAYER] x ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size
                                                                 of each segment will be [MOD_ORDER] x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x1, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x 8 segments and padded with 8 x [NUM_LAYER] x
                                                                 ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size of each segment will be 8 x
                                                                 [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x2 or 0x3, the output data will be separated into
                                                                 segments with 16 x [SEGx_SYMS] x [NUM_LAYER] segments and padded with 16 x
                                                                 [NUM_LAYER] x ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size of each
                                                                 segment will be 16 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x0, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x [MOD_ORDER] segments and padded with zero such
                                                                 that ([MOD_ORDER] x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0.

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x1, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x 8 segments and padded with zero such that
                                                                 (8 x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0.

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x2 or 0x3, the output data will be separated into
                                                                 segments with 16 x [SEGx_SYMS] x [NUM_LAYER] segments and padded with zero such
                                                                 that (16 x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0. */
        uint64_t num_layer             : 4;  /**< [155:152] number of layers the transport block will be mapped to. Valid range is
                                                                 [0x1, 0x4]. */
        uint64_t num_total_sym_per_layer : 24;/**< [151:128] When [SEG_PAD] = 1, it specifies the total number of symbols in all segments. When
                                                                 [SEG_PAD] = 0, this field is ignored.
                                                                 Each segment is padded to this size. [NUM_TOTAL_SYM_PER_LAYER] must be \>=
                                                                 MAX[SEGx_SYMS], for x = 0,...,13.

                                                                 Note that when [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x0, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that ([MOD_ORDER] x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0.

                                                                 When [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x1, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that (8 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0.

                                                                 When [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x2 or 0x3, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that (16 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0. */
#else /* Word 2 - Little Endian */
        uint64_t num_total_sym_per_layer : 24;/**< [151:128] When [SEG_PAD] = 1, it specifies the total number of symbols in all segments. When
                                                                 [SEG_PAD] = 0, this field is ignored.
                                                                 Each segment is padded to this size. [NUM_TOTAL_SYM_PER_LAYER] must be \>=
                                                                 MAX[SEGx_SYMS], for x = 0,...,13.

                                                                 Note that when [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x0, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that ([MOD_ORDER] x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0.

                                                                 When [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x1, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that (8 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0.

                                                                 When [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x2 or 0x3, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that (16 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0. */
        uint64_t num_layer             : 4;  /**< [155:152] number of layers the transport block will be mapped to. Valid range is
                                                                 [0x1, 0x4]. */
        uint64_t seg_pad               : 1;  /**< [156:156] This flag is used only when [BYPASS_SEGMENTATION] = 0 and ignored otherwise.

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x0, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x [MOD_ORDER] segments and padded with
                                                                 [MOD_ORDER] x [NUM_LAYER] x ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size
                                                                 of each segment will be [MOD_ORDER] x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x1, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x 8 segments and padded with 8 x [NUM_LAYER] x
                                                                 ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size of each segment will be 8 x
                                                                 [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x2 or 0x3, the output data will be separated into
                                                                 segments with 16 x [SEGx_SYMS] x [NUM_LAYER] segments and padded with 16 x
                                                                 [NUM_LAYER] x ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size of each
                                                                 segment will be 16 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x0, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x [MOD_ORDER] segments and padded with zero such
                                                                 that ([MOD_ORDER] x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0.

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x1, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x 8 segments and padded with zero such that
                                                                 (8 x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0.

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x2 or 0x3, the output data will be separated into
                                                                 segments with 16 x [SEGx_SYMS] x [NUM_LAYER] segments and padded with zero such
                                                                 that (16 x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0. */
        uint64_t bypass_intlv          : 1;  /**< [157:157] Bypass bit interleaving when set. */
        uint64_t symb_byte_aligned     : 2;  /**< [159:158] Select the alignment and interleaving for output bits.
                                                                 0x0 = Bypass mode. Bits are written consecutively, with no per-symbol
                                                                 alignment.
                                                                 0x1: Byte alignment for [MOD_ORDER] \< 0xA. Every [MOD_ORDER] bits are aligned to a bit
                                                                 boundary.
                                                                 0x2 = Interleaved byte alignment for [MOD_ORDER] = 0xA. For each symbol, the five
                                                                 even bits are packed in one byte, and the five odd bits are packed
                                                                 in the next byte.
                                                                 0x3 = Consecutive byte alignment for [MOD_ORDER] = 0xA. For each symbol, bits 0-4
                                                                 are written in one byte and bits 5-9 are written in the next
                                                                 subsequent byte. */
        uint64_t bypass_segmentation   : 1;  /**< [160:160] When set to 0, the output is segmented, with extra padding inserted.
                                                                 See [SEG_PAD] for more details.

                                                                 When set to 1, the output bits are sent contiguously to output. */
        uint64_t scrambling_init       : 31; /**< [191:161] The initialization value of the 2nd m-sequence of the scrambler. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t seg3_syms             : 16; /**< [255:240] See [SEG_PAD]. */
        uint64_t seg2_syms             : 16; /**< [239:224] See [SEG_PAD]. */
        uint64_t seg1_syms             : 16; /**< [223:208] See [SEG_PAD]. */
        uint64_t seg0_syms             : 16; /**< [207:192] See [SEG_PAD]. */
#else /* Word 3 - Little Endian */
        uint64_t seg0_syms             : 16; /**< [207:192] See [SEG_PAD]. */
        uint64_t seg1_syms             : 16; /**< [223:208] See [SEG_PAD]. */
        uint64_t seg2_syms             : 16; /**< [239:224] See [SEG_PAD]. */
        uint64_t seg3_syms             : 16; /**< [255:240] See [SEG_PAD]. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t seg7_syms             : 16; /**< [319:304] See [SEG_PAD]. */
        uint64_t seg6_syms             : 16; /**< [303:288] See [SEG_PAD]. */
        uint64_t seg5_syms             : 16; /**< [287:272] See [SEG_PAD]. */
        uint64_t seg4_syms             : 16; /**< [271:256] See [SEG_PAD]. */
#else /* Word 4 - Little Endian */
        uint64_t seg4_syms             : 16; /**< [271:256] See [SEG_PAD]. */
        uint64_t seg5_syms             : 16; /**< [287:272] See [SEG_PAD]. */
        uint64_t seg6_syms             : 16; /**< [303:288] See [SEG_PAD]. */
        uint64_t seg7_syms             : 16; /**< [319:304] See [SEG_PAD]. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t seg11_syms            : 16; /**< [383:368] See [SEG_PAD]. */
        uint64_t seg10_syms            : 16; /**< [367:352] See [SEG_PAD]. */
        uint64_t seg9_syms             : 16; /**< [351:336] See [SEG_PAD]. */
        uint64_t seg8_syms             : 16; /**< [335:320] See [SEG_PAD]. */
#else /* Word 5 - Little Endian */
        uint64_t seg8_syms             : 16; /**< [335:320] See [SEG_PAD]. */
        uint64_t seg9_syms             : 16; /**< [351:336] See [SEG_PAD]. */
        uint64_t seg10_syms            : 16; /**< [367:352] See [SEG_PAD]. */
        uint64_t seg11_syms            : 16; /**< [383:368] See [SEG_PAD]. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_419_447      : 29;
        uint64_t output_data_order     : 3;  /**< [418:416] Bit 34:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Bits \<33:32\>:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2.
                                                                 0x3 = Reserved. */
        uint64_t seg13_syms            : 16; /**< [415:400] See [SEG_PAD]. */
        uint64_t seg12_syms            : 16; /**< [399:384] See [SEG_PAD]. */
#else /* Word 6 - Little Endian */
        uint64_t seg12_syms            : 16; /**< [399:384] See [SEG_PAD]. */
        uint64_t seg13_syms            : 16; /**< [415:400] See [SEG_PAD]. */
        uint64_t output_data_order     : 3;  /**< [418:416] Bit 34:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Bits \<33:32\>:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2.
                                                                 0x3 = Reserved. */
        uint64_t reserved_419_447      : 29;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t num_wr0_wrds          : 32; /**< [511:480] Number of words to write to write DMA port 0 for this task. Valid range is [0x1, 0x1D640]. */
        uint64_t num_rd0_wrds          : 32; /**< [479:448] Number of words to read from read DMA port 0 for this task. Valid range is [0x1, 0x4E20]. */
#else /* Word 7 - Little Endian */
        uint64_t num_rd0_wrds          : 32; /**< [479:448] Number of words to read from read DMA port 0 for this task. Valid range is [0x1, 0x4E20]. */
        uint64_t num_wr0_wrds          : 32; /**< [511:480] Number of words to write to write DMA port 0 for this task. Valid range is [0x1, 0x1D640]. */
#endif /* Word 7 - End */
    } s;
    /* struct cavm_lenc_task_cfg_s_s cnf95xx; */
    struct cavm_lenc_task_cfg_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mod_order             : 4;  /**< [ 63: 60] Modulation order:
                                                                 0x1 = {pi}/2 BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16-QAM.
                                                                 0x6 = 64-QAM.
                                                                 0x8 = 256-QAM.
                                                                 0xA = 1024-QAM. */
        uint64_t bypass_scrambling     : 1;  /**< [ 59: 59] Bypass scrambling when set. */
        uint64_t input_data_order      : 3;  /**< [ 58: 56] Bit 56:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Bits \<58:57\>:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2.
                                                                 0x3 = Reserved. */
        uint64_t tb_crc                : 24; /**< [ 55: 32] TB CRC calculated for initial transmission. If CRC length is 16, the 16 least-significant bits
                                                                 of [TB_CRC] are valid. */
        uint64_t tb_crc_from_cfg_flag  : 1;  /**< [ 31: 31] _ 0 = Do not use [TB_CRC]. If [TB_CRC_SELECT] = 0x1 or 0x2, TB CRC is calculated internally.

                                                                 _ 1 = Append [TB_CRC] of length selected by [TB_CRC_SELECT] = 0x1 or 0x2 to the
                                                                 end of the input bits of the current task. */
        uint64_t tb_crc_output_flag    : 1;  /**< [ 30: 30] Output raw TB CRC:
                                                                 0 = no raw TB CRC (before scrambling) output.
                                                                 1 = raw TB CRC (before scrambling) output.
                                                                 When [TB_CRC_SELECT] \> 0x0, [TB_CRC_OUTPUT_FLAG] must be 0. */
        uint64_t tb_crc_select         : 2;  /**< [ 29: 28] CRC polynomial used for the calculation of TB CRC and CB level TB CRC contribution.
                                                                 0x0 = no CRC (i.e. CRC added before Core).
                                                                 0x1 = use CRC-16.
                                                                 0x2 = use CRC-24A.
                                                                 0x3 = Reserved. */
        uint64_t reserved_27           : 1;
        uint64_t cb_crc_select         : 1;  /**< [ 26: 26] CB CRC polynomial select
                                                                 0 = no CRC.
                                                                 1 = use CRC-24B.
                                                                 When LENC_CB_CFG_S[NUM_CB] = 0x1, [CB_CRC_SELECT] must be 0.
                                                                 When LENC_CB_CFG_S[NUM_CB] \> 0x1 and [TB_CRC_SELECT] \> 0x0, [CB_CRC_SELECT] must be 1. */
        uint64_t basegraph             : 1;  /**< [ 25: 25] LDPC basegraph
                                                                 0 = BG1.
                                                                 1 = BG2. */
        uint64_t mixed_mod             : 1;  /**< [ 24: 24] Reserved.
                                                                 Internal:
                                                                 Used only in DOCSIS mode.

                                                                 0: Do not use mixed modulation.
                                                                 1: Use mixed modulation.
                                                                 Ignored if shortening is applied or when LENC_CB_CFG_S[CODE_ID] \> 0x0. */
        uint64_t num_cb_cfg            : 8;  /**< [ 23: 16] The number of CB configuration entries. Valid range is [0x1, 0x8]. */
        uint64_t task_id               : 16; /**< [ 15:  0] Each task in a job must have a unique ID. The task ID will be
                                                                 included in the output to correctly identify the output for each task. */
#else /* Word 0 - Little Endian */
        uint64_t task_id               : 16; /**< [ 15:  0] Each task in a job must have a unique ID. The task ID will be
                                                                 included in the output to correctly identify the output for each task. */
        uint64_t num_cb_cfg            : 8;  /**< [ 23: 16] The number of CB configuration entries. Valid range is [0x1, 0x8]. */
        uint64_t mixed_mod             : 1;  /**< [ 24: 24] Reserved.
                                                                 Internal:
                                                                 Used only in DOCSIS mode.

                                                                 0: Do not use mixed modulation.
                                                                 1: Use mixed modulation.
                                                                 Ignored if shortening is applied or when LENC_CB_CFG_S[CODE_ID] \> 0x0. */
        uint64_t basegraph             : 1;  /**< [ 25: 25] LDPC basegraph
                                                                 0 = BG1.
                                                                 1 = BG2. */
        uint64_t cb_crc_select         : 1;  /**< [ 26: 26] CB CRC polynomial select
                                                                 0 = no CRC.
                                                                 1 = use CRC-24B.
                                                                 When LENC_CB_CFG_S[NUM_CB] = 0x1, [CB_CRC_SELECT] must be 0.
                                                                 When LENC_CB_CFG_S[NUM_CB] \> 0x1 and [TB_CRC_SELECT] \> 0x0, [CB_CRC_SELECT] must be 1. */
        uint64_t reserved_27           : 1;
        uint64_t tb_crc_select         : 2;  /**< [ 29: 28] CRC polynomial used for the calculation of TB CRC and CB level TB CRC contribution.
                                                                 0x0 = no CRC (i.e. CRC added before Core).
                                                                 0x1 = use CRC-16.
                                                                 0x2 = use CRC-24A.
                                                                 0x3 = Reserved. */
        uint64_t tb_crc_output_flag    : 1;  /**< [ 30: 30] Output raw TB CRC:
                                                                 0 = no raw TB CRC (before scrambling) output.
                                                                 1 = raw TB CRC (before scrambling) output.
                                                                 When [TB_CRC_SELECT] \> 0x0, [TB_CRC_OUTPUT_FLAG] must be 0. */
        uint64_t tb_crc_from_cfg_flag  : 1;  /**< [ 31: 31] _ 0 = Do not use [TB_CRC]. If [TB_CRC_SELECT] = 0x1 or 0x2, TB CRC is calculated internally.

                                                                 _ 1 = Append [TB_CRC] of length selected by [TB_CRC_SELECT] = 0x1 or 0x2 to the
                                                                 end of the input bits of the current task. */
        uint64_t tb_crc                : 24; /**< [ 55: 32] TB CRC calculated for initial transmission. If CRC length is 16, the 16 least-significant bits
                                                                 of [TB_CRC] are valid. */
        uint64_t input_data_order      : 3;  /**< [ 58: 56] Bit 56:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Bits \<58:57\>:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2.
                                                                 0x3 = Reserved. */
        uint64_t bypass_scrambling     : 1;  /**< [ 59: 59] Bypass scrambling when set. */
        uint64_t mod_order             : 4;  /**< [ 63: 60] Modulation order:
                                                                 0x1 = {pi}/2 BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16-QAM.
                                                                 0x6 = 64-QAM.
                                                                 0x8 = 256-QAM.
                                                                 0xA = 1024-QAM. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t k0                    : 16; /**< [127:112] k0 value representing offset of Rx data in unpruned circular buffer as defined
                                                                 in Table 5.4.2.1-2 of [R1]. It must be less than [NCB_SIZE]. */
        uint64_t ncb_size              : 16; /**< [111: 96] Soft buffer size for each code block as specified in Section
                                                                 5.4.2.1 of [R1]. Maximum value is 0x6300. */
        uint64_t tb_size               : 32; /**< [ 95: 64] Transport Block size. It corresponds to 'A' defined in Section 5.1
                                                                 of [R1]. Valid range is [0x18, 0x138028]. */
#else /* Word 1 - Little Endian */
        uint64_t tb_size               : 32; /**< [ 95: 64] Transport Block size. It corresponds to 'A' defined in Section 5.1
                                                                 of [R1]. Valid range is [0x18, 0x138028]. */
        uint64_t ncb_size              : 16; /**< [111: 96] Soft buffer size for each code block as specified in Section
                                                                 5.4.2.1 of [R1]. Maximum value is 0x6300. */
        uint64_t k0                    : 16; /**< [127:112] k0 value representing offset of Rx data in unpruned circular buffer as defined
                                                                 in Table 5.4.2.1-2 of [R1]. It must be less than [NCB_SIZE]. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t scrambling_init       : 31; /**< [191:161] The initialization value of the 2nd m-sequence of the scrambler. */
        uint64_t bypass_segmentation   : 1;  /**< [160:160] When set to 0, the output is segmented, with extra padding inserted.
                                                                 See [SEG_PAD] for more details.

                                                                 When set to 1, the output bits are sent contiguously to output. */
        uint64_t symb_byte_aligned     : 2;  /**< [159:158] Select the alignment and interleaving for output bits.
                                                                 0x0 = Bypass mode. Bits are written consecutively, with no per-symbol
                                                                 alignment.
                                                                 0x1: Byte alignment for [MOD_ORDER] \< 0xA. Every [MOD_ORDER] bits are aligned to a bit
                                                                 boundary.
                                                                 0x2 = Interleaved byte alignment for [MOD_ORDER] = 0xA. For each symbol, the five
                                                                 even bits are packed in one byte, and the five odd bits are packed
                                                                 in the next byte.
                                                                 0x3 = Consecutive byte alignment for [MOD_ORDER] = 0xA. For each symbol, bits 0-4
                                                                 are written in one byte and bits 5-9 are written in the next
                                                                 subsequent byte. */
        uint64_t bypass_intlv          : 1;  /**< [157:157] Bypass bit interleaving when set. */
        uint64_t seg_pad               : 1;  /**< [156:156] This flag is used only when [BYPASS_SEGMENTATION] = 0 and ignored otherwise.

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x0, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x [MOD_ORDER] segments and padded with
                                                                 [MOD_ORDER] x [NUM_LAYER] x ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size
                                                                 of each segment will be [MOD_ORDER] x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x1, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x 8 segments and padded with 8 x [NUM_LAYER] x
                                                                 ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size of each segment will be 8 x
                                                                 [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x2 or 0x3, the output data will be separated into
                                                                 segments with 16 x [SEGx_SYMS] x [NUM_LAYER] segments and padded with 16 x
                                                                 [NUM_LAYER] x ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size of each
                                                                 segment will be 16 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x0, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x [MOD_ORDER] segments and padded with zero such
                                                                 that ([MOD_ORDER] x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0.

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x1, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x 8 segments and padded with zero such that
                                                                 (8 x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0.

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x2 or 0x3, the output data will be separated into
                                                                 segments with 16 x [SEGx_SYMS] x [NUM_LAYER] segments and padded with zero such
                                                                 that (16 x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0. */
        uint64_t num_layer             : 4;  /**< [155:152] number of layers the transport block will be mapped to. Valid range is
                                                                 [0x1, 0x4]. */
        uint64_t num_total_sym_per_layer : 24;/**< [151:128] When [SEG_PAD] = 1, it specifies the total number of symbols in all segments. When
                                                                 [SEG_PAD] = 0, this field is ignored.
                                                                 Each segment is padded to this size. [NUM_TOTAL_SYM_PER_LAYER] must be \>=
                                                                 MAX[SEGx_SYMS], for x = 0,...,13.

                                                                 Note that when [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x0, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that ([MOD_ORDER] x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0.

                                                                 When [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x1, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that (8 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0.

                                                                 When [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x2 or 0x3, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that (16 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0. */
#else /* Word 2 - Little Endian */
        uint64_t num_total_sym_per_layer : 24;/**< [151:128] When [SEG_PAD] = 1, it specifies the total number of symbols in all segments. When
                                                                 [SEG_PAD] = 0, this field is ignored.
                                                                 Each segment is padded to this size. [NUM_TOTAL_SYM_PER_LAYER] must be \>=
                                                                 MAX[SEGx_SYMS], for x = 0,...,13.

                                                                 Note that when [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x0, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that ([MOD_ORDER] x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0.

                                                                 When [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x1, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that (8 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0.

                                                                 When [SEG_PAD] = 1 and [SYMB_BYTE_ALIGN] = 0x2 or 0x3, [NUM_TOTAL_SYM_PER_LAYER] must be
                                                                 set such that (16 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER]) % 128 = 0. */
        uint64_t num_layer             : 4;  /**< [155:152] number of layers the transport block will be mapped to. Valid range is
                                                                 [0x1, 0x4]. */
        uint64_t seg_pad               : 1;  /**< [156:156] This flag is used only when [BYPASS_SEGMENTATION] = 0 and ignored otherwise.

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x0, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x [MOD_ORDER] segments and padded with
                                                                 [MOD_ORDER] x [NUM_LAYER] x ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size
                                                                 of each segment will be [MOD_ORDER] x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x1, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x 8 segments and padded with 8 x [NUM_LAYER] x
                                                                 ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size of each segment will be 8 x
                                                                 [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 1, and [SYMB_BYTE_ALIGNED] = 0x2 or 0x3, the output data will be separated into
                                                                 segments with 16 x [SEGx_SYMS] x [NUM_LAYER] segments and padded with 16 x
                                                                 [NUM_LAYER] x ([NUM_TOTAL_SYM_PER_LAYER] - SEGx_SYMS]) zero. The total size of each
                                                                 segment will be 16 x [NUM_LAYER] x [NUM_TOTAL_SYM_PER_LAYER].

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x0, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x [MOD_ORDER] segments and padded with zero such
                                                                 that ([MOD_ORDER] x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0.

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x1, the output data will be separated into segments
                                                                 with [SEGx_SYMS] x [NUM_LAYER] x 8 segments and padded with zero such that
                                                                 (8 x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0.

                                                                 When [SEG_PAD] = 0, and [SYMB_BYTE_ALIGNED] = 0x2 or 0x3, the output data will be separated into
                                                                 segments with 16 x [SEGx_SYMS] x [NUM_LAYER] segments and padded with zero such
                                                                 that (16 x [NUM_LAYER] x SEGx_SYMS]) % 128 = 0. */
        uint64_t bypass_intlv          : 1;  /**< [157:157] Bypass bit interleaving when set. */
        uint64_t symb_byte_aligned     : 2;  /**< [159:158] Select the alignment and interleaving for output bits.
                                                                 0x0 = Bypass mode. Bits are written consecutively, with no per-symbol
                                                                 alignment.
                                                                 0x1: Byte alignment for [MOD_ORDER] \< 0xA. Every [MOD_ORDER] bits are aligned to a bit
                                                                 boundary.
                                                                 0x2 = Interleaved byte alignment for [MOD_ORDER] = 0xA. For each symbol, the five
                                                                 even bits are packed in one byte, and the five odd bits are packed
                                                                 in the next byte.
                                                                 0x3 = Consecutive byte alignment for [MOD_ORDER] = 0xA. For each symbol, bits 0-4
                                                                 are written in one byte and bits 5-9 are written in the next
                                                                 subsequent byte. */
        uint64_t bypass_segmentation   : 1;  /**< [160:160] When set to 0, the output is segmented, with extra padding inserted.
                                                                 See [SEG_PAD] for more details.

                                                                 When set to 1, the output bits are sent contiguously to output. */
        uint64_t scrambling_init       : 31; /**< [191:161] The initialization value of the 2nd m-sequence of the scrambler. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t seg3_syms             : 16; /**< [255:240] See [SEG_PAD]. */
        uint64_t seg2_syms             : 16; /**< [239:224] See [SEG_PAD]. */
        uint64_t seg1_syms             : 16; /**< [223:208] See [SEG_PAD]. */
        uint64_t seg0_syms             : 16; /**< [207:192] See [SEG_PAD]. */
#else /* Word 3 - Little Endian */
        uint64_t seg0_syms             : 16; /**< [207:192] See [SEG_PAD]. */
        uint64_t seg1_syms             : 16; /**< [223:208] See [SEG_PAD]. */
        uint64_t seg2_syms             : 16; /**< [239:224] See [SEG_PAD]. */
        uint64_t seg3_syms             : 16; /**< [255:240] See [SEG_PAD]. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t seg7_syms             : 16; /**< [319:304] See [SEG_PAD]. */
        uint64_t seg6_syms             : 16; /**< [303:288] See [SEG_PAD]. */
        uint64_t seg5_syms             : 16; /**< [287:272] See [SEG_PAD]. */
        uint64_t seg4_syms             : 16; /**< [271:256] See [SEG_PAD]. */
#else /* Word 4 - Little Endian */
        uint64_t seg4_syms             : 16; /**< [271:256] See [SEG_PAD]. */
        uint64_t seg5_syms             : 16; /**< [287:272] See [SEG_PAD]. */
        uint64_t seg6_syms             : 16; /**< [303:288] See [SEG_PAD]. */
        uint64_t seg7_syms             : 16; /**< [319:304] See [SEG_PAD]. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t seg11_syms            : 16; /**< [383:368] See [SEG_PAD]. */
        uint64_t seg10_syms            : 16; /**< [367:352] See [SEG_PAD]. */
        uint64_t seg9_syms             : 16; /**< [351:336] See [SEG_PAD]. */
        uint64_t seg8_syms             : 16; /**< [335:320] See [SEG_PAD]. */
#else /* Word 5 - Little Endian */
        uint64_t seg8_syms             : 16; /**< [335:320] See [SEG_PAD]. */
        uint64_t seg9_syms             : 16; /**< [351:336] See [SEG_PAD]. */
        uint64_t seg10_syms            : 16; /**< [367:352] See [SEG_PAD]. */
        uint64_t seg11_syms            : 16; /**< [383:368] See [SEG_PAD]. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_419_447      : 29;
        uint64_t output_data_order     : 3;  /**< [418:416] Bit 34:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Bits \<33:32\>:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2.
                                                                 0x3 = Reserved. */
        uint64_t seg13_syms            : 16; /**< [415:400] See [SEG_PAD]. */
        uint64_t seg12_syms            : 16; /**< [399:384] See [SEG_PAD]. */
#else /* Word 6 - Little Endian */
        uint64_t seg12_syms            : 16; /**< [399:384] See [SEG_PAD]. */
        uint64_t seg13_syms            : 16; /**< [415:400] See [SEG_PAD]. */
        uint64_t output_data_order     : 3;  /**< [418:416] Bit 34:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Bits \<33:32\>:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2.
                                                                 0x3 = Reserved. */
        uint64_t reserved_419_447      : 29;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t num_wr0_wrds          : 32; /**< [511:480] Number of words to write to write DMA port 0 for this task. Valid range is [0x1, 0x1D640]. */
        uint64_t num_rd0_wrds          : 32; /**< [479:448] Number of words to read from read DMA port 0 for this task. The recommended
                                                                 range is [0x1, 0x4E20] for NR. This is not a hard limit, however. */
#else /* Word 7 - Little Endian */
        uint64_t num_rd0_wrds          : 32; /**< [479:448] Number of words to read from read DMA port 0 for this task. The recommended
                                                                 range is [0x1, 0x4E20] for NR. This is not a hard limit, however. */
        uint64_t num_wr0_wrds          : 32; /**< [511:480] Number of words to write to write DMA port 0 for this task. Valid range is [0x1, 0x1D640]. */
#endif /* Word 7 - End */
    } loki;
};

/**
 * Register (RSL) lenc#_ab#_control
 *
 * LENC Control Register
 */
union cavm_lencx_abx_control
{
    uint64_t u;
    struct cavm_lencx_abx_control_s
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
    /* struct cavm_lencx_abx_control_s cn; */
};
typedef union cavm_lencx_abx_control cavm_lencx_abx_control_t;

static inline uint64_t CAVM_LENCX_ABX_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_CONTROL(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043300000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043300000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_CONTROL", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_CONTROL(a,b) cavm_lencx_abx_control_t
#define bustype_CAVM_LENCX_ABX_CONTROL(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_CONTROL(a,b) "LENCX_ABX_CONTROL"
#define busnum_CAVM_LENCX_ABX_CONTROL(a,b) (a)
#define arguments_CAVM_LENCX_ABX_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_eco
 *
 * INTERNAL: LENC ECO Register
 */
union cavm_lencx_abx_eco
{
    uint64_t u;
    struct cavm_lencx_abx_eco_s
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
    /* struct cavm_lencx_abx_eco_s cn; */
};
typedef union cavm_lencx_abx_eco cavm_lencx_abx_eco_t;

static inline uint64_t CAVM_LENCX_ABX_ECO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_ECO(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043300008ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043300008ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_ECO", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_ECO(a,b) cavm_lencx_abx_eco_t
#define bustype_CAVM_LENCX_ABX_ECO(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_ECO(a,b) "LENCX_ABX_ECO"
#define busnum_CAVM_LENCX_ABX_ECO(a,b) (a)
#define arguments_CAVM_LENCX_ABX_ECO(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_error_enable0
 *
 * LENC Error Enable 0 Register
 * This register enables error reporting for read overflow/underflow errors.
 */
union cavm_lencx_abx_error_enable0
{
    uint64_t u;
    struct cavm_lencx_abx_error_enable0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t rp0_of_en             : 1;  /**< [  4:  4](R/W) Read port 0 overflow enable. */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W) Read Port 0 underflow enable. */
#else /* Word 0 - Little Endian */
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W) Read Port 0 underflow enable. */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_of_en             : 1;  /**< [  4:  4](R/W) Read port 0 overflow enable. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_error_enable0_s cn; */
};
typedef union cavm_lencx_abx_error_enable0 cavm_lencx_abx_error_enable0_t;

static inline uint64_t CAVM_LENCX_ABX_ERROR_ENABLE0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_ERROR_ENABLE0(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043300040ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043300040ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_ERROR_ENABLE0", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_ERROR_ENABLE0(a,b) cavm_lencx_abx_error_enable0_t
#define bustype_CAVM_LENCX_ABX_ERROR_ENABLE0(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_ERROR_ENABLE0(a,b) "LENCX_ABX_ERROR_ENABLE0"
#define busnum_CAVM_LENCX_ABX_ERROR_ENABLE0(a,b) (a)
#define arguments_CAVM_LENCX_ABX_ERROR_ENABLE0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_error_source0
 *
 * LENC Error Source 0 Register
 * This register indicates the source of read overflow/underflow errors.
 */
union cavm_lencx_abx_error_source0
{
    uint64_t u;
    struct cavm_lencx_abx_error_source0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t rp0_jid               : 16; /**< [ 31: 16](RO/H) Job ID of the job which reported the overflow/underflow error on read
                                                                 port 1. */
        uint64_t reserved_5_15         : 11;
        uint64_t rp0_of                : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_uf                : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
#else /* Word 0 - Little Endian */
        uint64_t rp0_uf                : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_of                : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t reserved_5_15         : 11;
        uint64_t rp0_jid               : 16; /**< [ 31: 16](RO/H) Job ID of the job which reported the overflow/underflow error on read
                                                                 port 1. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_error_source0_s cn; */
};
typedef union cavm_lencx_abx_error_source0 cavm_lencx_abx_error_source0_t;

static inline uint64_t CAVM_LENCX_ABX_ERROR_SOURCE0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_ERROR_SOURCE0(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043300030ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043300030ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_ERROR_SOURCE0", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_ERROR_SOURCE0(a,b) cavm_lencx_abx_error_source0_t
#define bustype_CAVM_LENCX_ABX_ERROR_SOURCE0(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_ERROR_SOURCE0(a,b) "LENCX_ABX_ERROR_SOURCE0"
#define busnum_CAVM_LENCX_ABX_ERROR_SOURCE0(a,b) (a)
#define arguments_CAVM_LENCX_ABX_ERROR_SOURCE0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_hab_jcfg0_ram#_data
 *
 * LENC HAB Job Configuration 0 RAM Register
 * This register range stores the job configuration for slot 0.
 */
union cavm_lencx_abx_hab_jcfg0_ramx_data
{
    uint64_t u;
    struct cavm_lencx_abx_hab_jcfg0_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG0 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG0 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_hab_jcfg0_ramx_data_s cn; */
};
typedef union cavm_lencx_abx_hab_jcfg0_ramx_data cavm_lencx_abx_hab_jcfg0_ramx_data_t;

static inline uint64_t CAVM_LENCX_ABX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1) && (c<=384)))
        return 0x87e043302000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1) && (c<=384)))
        return 0x87e043302000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    __cavm_csr_fatal("LENCX_ABX_HAB_JCFG0_RAMX_DATA", 3, a, b, c, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) cavm_lencx_abx_hab_jcfg0_ramx_data_t
#define bustype_CAVM_LENCX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) "LENCX_ABX_HAB_JCFG0_RAMX_DATA"
#define busnum_CAVM_LENCX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) (a)
#define arguments_CAVM_LENCX_ABX_HAB_JCFG0_RAMX_DATA(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) lenc#_ab#_hab_jcfg1_ram#_data
 *
 * LENC HAB Job Configuration 1 RAM Register
 * This register range stores the job configuration for slot 1.
 */
union cavm_lencx_abx_hab_jcfg1_ramx_data
{
    uint64_t u;
    struct cavm_lencx_abx_hab_jcfg1_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG1 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG1 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_hab_jcfg1_ramx_data_s cn; */
};
typedef union cavm_lencx_abx_hab_jcfg1_ramx_data cavm_lencx_abx_hab_jcfg1_ramx_data_t;

static inline uint64_t CAVM_LENCX_ABX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1) && (c<=384)))
        return 0x87e043304000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1) && (c<=384)))
        return 0x87e043304000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    __cavm_csr_fatal("LENCX_ABX_HAB_JCFG1_RAMX_DATA", 3, a, b, c, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) cavm_lencx_abx_hab_jcfg1_ramx_data_t
#define bustype_CAVM_LENCX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) "LENCX_ABX_HAB_JCFG1_RAMX_DATA"
#define busnum_CAVM_LENCX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) (a)
#define arguments_CAVM_LENCX_ABX_HAB_JCFG1_RAMX_DATA(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) lenc#_ab#_hab_jcfg2_ram#_data
 *
 * LENC HAB Job Configuration 2 RAM Register
 * This register range stores the job configuration for slot 2.
 */
union cavm_lencx_abx_hab_jcfg2_ramx_data
{
    uint64_t u;
    struct cavm_lencx_abx_hab_jcfg2_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG2 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG2 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_hab_jcfg2_ramx_data_s cn; */
};
typedef union cavm_lencx_abx_hab_jcfg2_ramx_data cavm_lencx_abx_hab_jcfg2_ramx_data_t;

static inline uint64_t CAVM_LENCX_ABX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1) && (c<=384)))
        return 0x87e043306000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1) && (c<=384)))
        return 0x87e043306000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x1ff);
    __cavm_csr_fatal("LENCX_ABX_HAB_JCFG2_RAMX_DATA", 3, a, b, c, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) cavm_lencx_abx_hab_jcfg2_ramx_data_t
#define bustype_CAVM_LENCX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) "LENCX_ABX_HAB_JCFG2_RAMX_DATA"
#define busnum_CAVM_LENCX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) (a)
#define arguments_CAVM_LENCX_ABX_HAB_JCFG2_RAMX_DATA(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) lenc#_ab#_scratch
 *
 * INTERNAL: Scratch Register
 *
 * Scratch register.
 */
union cavm_lencx_abx_scratch
{
    uint64_t u;
    struct cavm_lencx_abx_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_scratch_s cn; */
};
typedef union cavm_lencx_abx_scratch cavm_lencx_abx_scratch_t;

static inline uint64_t CAVM_LENCX_ABX_SCRATCH(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_SCRATCH(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043300080ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043300080ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_SCRATCH", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_SCRATCH(a,b) cavm_lencx_abx_scratch_t
#define bustype_CAVM_LENCX_ABX_SCRATCH(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_SCRATCH(a,b) "LENCX_ABX_SCRATCH"
#define busnum_CAVM_LENCX_ABX_SCRATCH(a,b) (a)
#define arguments_CAVM_LENCX_ABX_SCRATCH(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_status
 *
 * LENC Status Register
 */
union cavm_lencx_abx_status
{
    uint64_t u;
    struct cavm_lencx_abx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the LENC HAB is ready to receive the next job. */
        uint64_t reserved_3            : 1;
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the LENC HAB is ready to receive the next job. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_status_s cn; */
};
typedef union cavm_lencx_abx_status cavm_lencx_abx_status_t;

static inline uint64_t CAVM_LENCX_ABX_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_STATUS(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043300018ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043300018ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_STATUS", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_STATUS(a,b) cavm_lencx_abx_status_t
#define bustype_CAVM_LENCX_ABX_STATUS(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_STATUS(a,b) "LENCX_ABX_STATUS"
#define busnum_CAVM_LENCX_ABX_STATUS(a,b) (a)
#define arguments_CAVM_LENCX_ABX_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_tc_config#
 *
 * INTERNAL: TC Task Config Registers
 *
 * TC task config registers.
 */
union cavm_lencx_abx_tc_configx
{
    uint64_t u;
    struct cavm_lencx_abx_tc_configx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_tc_configx_s cn; */
};
typedef union cavm_lencx_abx_tc_configx cavm_lencx_abx_tc_configx_t;

static inline uint64_t CAVM_LENCX_ABX_TC_CONFIGX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_TC_CONFIGX(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1) && (c<=7)))
        return 0x87e043301400ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x7);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1) && (c<=7)))
        return 0x87e043301400ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1) + 8ll * ((c) & 0x7);
    __cavm_csr_fatal("LENCX_ABX_TC_CONFIGX", 3, a, b, c, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_TC_CONFIGX(a,b,c) cavm_lencx_abx_tc_configx_t
#define bustype_CAVM_LENCX_ABX_TC_CONFIGX(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_TC_CONFIGX(a,b,c) "LENCX_ABX_TC_CONFIGX"
#define busnum_CAVM_LENCX_ABX_TC_CONFIGX(a,b,c) (a)
#define arguments_CAVM_LENCX_ABX_TC_CONFIGX(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) lenc#_ab#_tc_config_err_flags
 *
 * LENC Task Configuration Error Flags Register
 * This register reports task configuration errors that occur when a
 * specified parameter value is outside the acceptable range.
 */
union cavm_lencx_abx_tc_config_err_flags
{
    uint64_t u;
    struct cavm_lencx_abx_tc_config_err_flags_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t invalid_scrambling_init : 1;/**< [ 18: 18](RO/H) Invalid LENC_TASK_CFG_S[SCRAMBLING_INIT] value. */
        uint64_t invalid_symb_byte_aligned : 1;/**< [ 17: 17](RO/H) Invalid LENC_TASK_CFG_S[SYMB_BYTE_ALIGNED] value. */
        uint64_t invalid_bypass_intlv  : 1;  /**< [ 16: 16](RO/H) Invalid LENC_TASK_CFG_S[BYPASS_INTLV] value. */
        uint64_t invalid_k0            : 1;  /**< [ 15: 15](RO/H) Invalid LENC_TASK_CFG_S[K0] value. */
        uint64_t invalid_ncb_size      : 1;  /**< [ 14: 14](RO/H) Invalid LENC_TASK_CFG_S[NCB_SIZE] value. */
        uint64_t reserved_13           : 1;
        uint64_t invalid_mod_order     : 1;  /**< [ 12: 12](RO/H) Invalid LENC_TASK_CFG_S[MOD_ORDER] value. */
        uint64_t invalid_bypass_scrambling : 1;/**< [ 11: 11](RO/H) Invalid LENC_TASK_CFG_S[BYPASS_SCRAMBLING] value. */
        uint64_t invalid_input_data_order : 1;/**< [ 10: 10](RO/H) Invalid LENC_TASK_CFG_S[INPUT_DATA_ORDER] value. */
        uint64_t invalid_tb_crc        : 1;  /**< [  9:  9](RO/H) Invalid LENC_TASK_CFG_S[TB_CRC] value. */
        uint64_t invalid_tb_crc_from_cfg_flag : 1;/**< [  8:  8](RO/H) Invalid LENC_TASK_CFG_S[TB_CRC_FROM_CFG_FLAG] value. */
        uint64_t invalid_tb_crc_output_flag : 1;/**< [  7:  7](RO/H) Invalid LENC_TASK_CFG_S[TB_CRC_OUTPUT_FLAG] value. */
        uint64_t invalid_tb_crc_select : 1;  /**< [  6:  6](RO/H) Invalid LENC_TASK_CFG_S[TB_CRC_SELECT] value. */
        uint64_t invalid_cb_crc_select : 1;  /**< [  5:  5](RO/H) Invalid LENC_TASK_CFG_S[CB_CRC_SELECT] value. */
        uint64_t invalid_basegraph     : 1;  /**< [  4:  4](RO/H) Invalid LENC_TASK_CFG_S[BASEGRAPH] value. */
        uint64_t reserved_3            : 1;
        uint64_t invalid_num_cb_cfg    : 1;  /**< [  2:  2](RO/H) Invalid LENC_TASK_CFG_S[NUM_CB_CFG] value. */
        uint64_t reserved_1            : 1;
        uint64_t invalid_phy_mode      : 1;  /**< [  0:  0](RO/H) Invalid LENC_COMMON_CFG_S[PHY_MODE] value. */
#else /* Word 0 - Little Endian */
        uint64_t invalid_phy_mode      : 1;  /**< [  0:  0](RO/H) Invalid LENC_COMMON_CFG_S[PHY_MODE] value. */
        uint64_t reserved_1            : 1;
        uint64_t invalid_num_cb_cfg    : 1;  /**< [  2:  2](RO/H) Invalid LENC_TASK_CFG_S[NUM_CB_CFG] value. */
        uint64_t reserved_3            : 1;
        uint64_t invalid_basegraph     : 1;  /**< [  4:  4](RO/H) Invalid LENC_TASK_CFG_S[BASEGRAPH] value. */
        uint64_t invalid_cb_crc_select : 1;  /**< [  5:  5](RO/H) Invalid LENC_TASK_CFG_S[CB_CRC_SELECT] value. */
        uint64_t invalid_tb_crc_select : 1;  /**< [  6:  6](RO/H) Invalid LENC_TASK_CFG_S[TB_CRC_SELECT] value. */
        uint64_t invalid_tb_crc_output_flag : 1;/**< [  7:  7](RO/H) Invalid LENC_TASK_CFG_S[TB_CRC_OUTPUT_FLAG] value. */
        uint64_t invalid_tb_crc_from_cfg_flag : 1;/**< [  8:  8](RO/H) Invalid LENC_TASK_CFG_S[TB_CRC_FROM_CFG_FLAG] value. */
        uint64_t invalid_tb_crc        : 1;  /**< [  9:  9](RO/H) Invalid LENC_TASK_CFG_S[TB_CRC] value. */
        uint64_t invalid_input_data_order : 1;/**< [ 10: 10](RO/H) Invalid LENC_TASK_CFG_S[INPUT_DATA_ORDER] value. */
        uint64_t invalid_bypass_scrambling : 1;/**< [ 11: 11](RO/H) Invalid LENC_TASK_CFG_S[BYPASS_SCRAMBLING] value. */
        uint64_t invalid_mod_order     : 1;  /**< [ 12: 12](RO/H) Invalid LENC_TASK_CFG_S[MOD_ORDER] value. */
        uint64_t reserved_13           : 1;
        uint64_t invalid_ncb_size      : 1;  /**< [ 14: 14](RO/H) Invalid LENC_TASK_CFG_S[NCB_SIZE] value. */
        uint64_t invalid_k0            : 1;  /**< [ 15: 15](RO/H) Invalid LENC_TASK_CFG_S[K0] value. */
        uint64_t invalid_bypass_intlv  : 1;  /**< [ 16: 16](RO/H) Invalid LENC_TASK_CFG_S[BYPASS_INTLV] value. */
        uint64_t invalid_symb_byte_aligned : 1;/**< [ 17: 17](RO/H) Invalid LENC_TASK_CFG_S[SYMB_BYTE_ALIGNED] value. */
        uint64_t invalid_scrambling_init : 1;/**< [ 18: 18](RO/H) Invalid LENC_TASK_CFG_S[SCRAMBLING_INIT] value. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_tc_config_err_flags_s cn; */
};
typedef union cavm_lencx_abx_tc_config_err_flags cavm_lencx_abx_tc_config_err_flags_t;

static inline uint64_t CAVM_LENCX_ABX_TC_CONFIG_ERR_FLAGS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_TC_CONFIG_ERR_FLAGS(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043301040ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043301040ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_TC_CONFIG_ERR_FLAGS", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_TC_CONFIG_ERR_FLAGS(a,b) cavm_lencx_abx_tc_config_err_flags_t
#define bustype_CAVM_LENCX_ABX_TC_CONFIG_ERR_FLAGS(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_TC_CONFIG_ERR_FLAGS(a,b) "LENCX_ABX_TC_CONFIG_ERR_FLAGS"
#define busnum_CAVM_LENCX_ABX_TC_CONFIG_ERR_FLAGS(a,b) (a)
#define arguments_CAVM_LENCX_ABX_TC_CONFIG_ERR_FLAGS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_tc_control
 *
 * LENC Encoder Control Register
 * This register configures the LENC internal encoder core.
 */
union cavm_lencx_abx_tc_control
{
    uint64_t u;
    struct cavm_lencx_abx_tc_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) Internal core static control inputs.
                                                                 [0] = Clock gating disable.
                                                                 [1] = Configuration check disable.
                                                                 [2] = Wait until the core is idle before accepting the next task
                                                                       (degrades the throughput).
                                                                 [3] = Wait until the core is idle before accepting the next task
                                                                       in case of changing phy_mode (degrades the throughput).
                                                                 [4] = Wait until the core is idle before accepting the next task
                                                                       in case of changing channel_mode (degrades the throughput). */
#else /* Word 0 - Little Endian */
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) Internal core static control inputs.
                                                                 [0] = Clock gating disable.
                                                                 [1] = Configuration check disable.
                                                                 [2] = Wait until the core is idle before accepting the next task
                                                                       (degrades the throughput).
                                                                 [3] = Wait until the core is idle before accepting the next task
                                                                       in case of changing phy_mode (degrades the throughput).
                                                                 [4] = Wait until the core is idle before accepting the next task
                                                                       in case of changing channel_mode (degrades the throughput). */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_tc_control_s cn; */
};
typedef union cavm_lencx_abx_tc_control cavm_lencx_abx_tc_control_t;

static inline uint64_t CAVM_LENCX_ABX_TC_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_TC_CONTROL(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043301010ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043301010ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_TC_CONTROL", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_TC_CONTROL(a,b) cavm_lencx_abx_tc_control_t
#define bustype_CAVM_LENCX_ABX_TC_CONTROL(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_TC_CONTROL(a,b) "LENCX_ABX_TC_CONTROL"
#define busnum_CAVM_LENCX_ABX_TC_CONTROL(a,b) (a)
#define arguments_CAVM_LENCX_ABX_TC_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_tc_error
 *
 * LENC Encoder Error Register
 * This register reports various error conditions.
 *
 * All errors reported in this register are reported as FATAL errors, and the
 * MHBW registers can be inspected to determine the job tag(s) associated with
 * the error(s).
 */
union cavm_lencx_abx_tc_error
{
    uint64_t u;
    struct cavm_lencx_abx_tc_error_s
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
    /* struct cavm_lencx_abx_tc_error_s cn; */
};
typedef union cavm_lencx_abx_tc_error cavm_lencx_abx_tc_error_t;

static inline uint64_t CAVM_LENCX_ABX_TC_ERROR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_TC_ERROR(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043301038ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043301038ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_TC_ERROR", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_TC_ERROR(a,b) cavm_lencx_abx_tc_error_t
#define bustype_CAVM_LENCX_ABX_TC_ERROR(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_TC_ERROR(a,b) "LENCX_ABX_TC_ERROR"
#define busnum_CAVM_LENCX_ABX_TC_ERROR(a,b) (a)
#define arguments_CAVM_LENCX_ABX_TC_ERROR(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_tc_error_mask
 *
 * LENC Encoder Core Error Mask Register
 * This register enables internal encoder errors. Errors reported in
 * LENC()_AB()_TC_ERROR will generate an error signal only when the
 * corresponding bit is set in LENC()_AB()_TC_ERROR_MASK[ERR_MASK].
 */
union cavm_lencx_abx_tc_error_mask
{
    uint64_t u;
    struct cavm_lencx_abx_tc_error_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
#else /* Word 0 - Little Endian */
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_tc_error_mask_s cn; */
};
typedef union cavm_lencx_abx_tc_error_mask cavm_lencx_abx_tc_error_mask_t;

static inline uint64_t CAVM_LENCX_ABX_TC_ERROR_MASK(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_TC_ERROR_MASK(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043301030ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043301030ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_TC_ERROR_MASK", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_TC_ERROR_MASK(a,b) cavm_lencx_abx_tc_error_mask_t
#define bustype_CAVM_LENCX_ABX_TC_ERROR_MASK(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_TC_ERROR_MASK(a,b) "LENCX_ABX_TC_ERROR_MASK"
#define busnum_CAVM_LENCX_ABX_TC_ERROR_MASK(a,b) (a)
#define arguments_CAVM_LENCX_ABX_TC_ERROR_MASK(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_tc_main_reset
 *
 * LENC Encoder Reset Register
 * Internal encoder core reset register.
 */
union cavm_lencx_abx_tc_main_reset
{
    uint64_t u;
    struct cavm_lencx_abx_tc_main_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Any write to this register will reset the internal encoder core. */
#else /* Word 0 - Little Endian */
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Any write to this register will reset the internal encoder core. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_tc_main_reset_s cn; */
};
typedef union cavm_lencx_abx_tc_main_reset cavm_lencx_abx_tc_main_reset_t;

static inline uint64_t CAVM_LENCX_ABX_TC_MAIN_RESET(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_TC_MAIN_RESET(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043301000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043301000ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_TC_MAIN_RESET", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_TC_MAIN_RESET(a,b) cavm_lencx_abx_tc_main_reset_t
#define bustype_CAVM_LENCX_ABX_TC_MAIN_RESET(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_TC_MAIN_RESET(a,b) "LENCX_ABX_TC_MAIN_RESET"
#define busnum_CAVM_LENCX_ABX_TC_MAIN_RESET(a,b) (a)
#define arguments_CAVM_LENCX_ABX_TC_MAIN_RESET(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_tc_main_start
 *
 * INTERNAL: TC Start Register
 *
 * TC start register.
 */
union cavm_lencx_abx_tc_main_start
{
    uint64_t u;
    struct cavm_lencx_abx_tc_main_start_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
#else /* Word 0 - Little Endian */
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_tc_main_start_s cn; */
};
typedef union cavm_lencx_abx_tc_main_start cavm_lencx_abx_tc_main_start_t;

static inline uint64_t CAVM_LENCX_ABX_TC_MAIN_START(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_TC_MAIN_START(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043301008ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043301008ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_TC_MAIN_START", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_TC_MAIN_START(a,b) cavm_lencx_abx_tc_main_start_t
#define bustype_CAVM_LENCX_ABX_TC_MAIN_START(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_TC_MAIN_START(a,b) "LENCX_ABX_TC_MAIN_START"
#define busnum_CAVM_LENCX_ABX_TC_MAIN_START(a,b) (a)
#define arguments_CAVM_LENCX_ABX_TC_MAIN_START(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_tc_mon
 *
 * INTERNAL: TC Monitoring 0 Registers
 *
 * TC task output monitoring registers.
 */
union cavm_lencx_abx_tc_mon
{
    uint64_t u;
    struct cavm_lencx_abx_tc_mon_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bus_val               : 16; /**< [ 15:  0](RO/H) Encoder core task output monitoring values. */
#else /* Word 0 - Little Endian */
        uint64_t bus_val               : 16; /**< [ 15:  0](RO/H) Encoder core task output monitoring values. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_tc_mon_s cn; */
};
typedef union cavm_lencx_abx_tc_mon cavm_lencx_abx_tc_mon_t;

static inline uint64_t CAVM_LENCX_ABX_TC_MON(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_TC_MON(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043301300ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043301300ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_TC_MON", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_TC_MON(a,b) cavm_lencx_abx_tc_mon_t
#define bustype_CAVM_LENCX_ABX_TC_MON(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_TC_MON(a,b) "LENCX_ABX_TC_MON"
#define busnum_CAVM_LENCX_ABX_TC_MON(a,b) (a)
#define arguments_CAVM_LENCX_ABX_TC_MON(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lenc#_ab#_tc_status
 *
 * LENC Encoder Status Register
 * This register reports status from the internal encoder core.
 */
union cavm_lencx_abx_tc_status
{
    uint64_t u;
    struct cavm_lencx_abx_tc_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t monitor_bus           : 32; /**< [ 63: 32](RO/H) core dependent */
        uint64_t reserved_1_31         : 31;
        uint64_t idle                  : 1;  /**< [  0:  0](RO/H) When set to 1, the encoder is idle. */
#else /* Word 0 - Little Endian */
        uint64_t idle                  : 1;  /**< [  0:  0](RO/H) When set to 1, the encoder is idle. */
        uint64_t reserved_1_31         : 31;
        uint64_t monitor_bus           : 32; /**< [ 63: 32](RO/H) core dependent */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lencx_abx_tc_status_s cn; */
};
typedef union cavm_lencx_abx_tc_status cavm_lencx_abx_tc_status_t;

static inline uint64_t CAVM_LENCX_ABX_TC_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LENCX_ABX_TC_STATUS(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043301020ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && ((a<=1) && (b<=1)))
        return 0x87e043301020ll + 0x580000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("LENCX_ABX_TC_STATUS", 2, a, b, 0, 0, 0, 0);
}

#define typedef_CAVM_LENCX_ABX_TC_STATUS(a,b) cavm_lencx_abx_tc_status_t
#define bustype_CAVM_LENCX_ABX_TC_STATUS(a,b) CSR_TYPE_RSL
#define basename_CAVM_LENCX_ABX_TC_STATUS(a,b) "LENCX_ABX_TC_STATUS"
#define busnum_CAVM_LENCX_ABX_TC_STATUS(a,b) (a)
#define arguments_CAVM_LENCX_ABX_TC_STATUS(a,b) (a),(b),-1,-1

#endif /* __CAVM_CSRS_LENC_H__ */
