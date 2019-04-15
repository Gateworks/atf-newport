#ifndef __CAVM_CSRS_PENC_H__
#define __CAVM_CSRS_PENC_H__
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
 * OcteonTX PENC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure penc_common_cfg_s
 *
 * PENC Common Job Configuration Structure
 * This structure defines the format of the first word of the job
 * configuration for all PENC jobs.
 */
union cavm_penc_common_cfg_s
{
    uint64_t u;
    struct cavm_penc_common_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t num_cfg_words_per_task : 8; /**< [ 31: 24] Number of configuration words per task. Must be 0x9 for all PENC jobs. */
        uint64_t reserved_5_23         : 19;
        uint64_t num_tasks             : 5;  /**< [  4:  0] Number of tasks in the job.  Permitted values are 0x1 - 0x10. */
#else /* Word 0 - Little Endian */
        uint64_t num_tasks             : 5;  /**< [  4:  0] Number of tasks in the job.  Permitted values are 0x1 - 0x10. */
        uint64_t reserved_5_23         : 19;
        uint64_t num_cfg_words_per_task : 8; /**< [ 31: 24] Number of configuration words per task. Must be 0x9 for all PENC jobs. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_penc_common_cfg_s_s cn; */
};

/**
 * Structure penc_task_cfg_s
 *
 * PENC Task Configuration Structure
 * This structure defines the configuration parameters for an individual
 * task. The job configuration section for a PENC job should
 * contain one of these structures for each task.
 */
union cavm_penc_task_cfg_s
{
    uint64_t u[9];
    struct cavm_penc_task_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_45_63        : 19;
        uint64_t g_size                : 13; /**< [ 44: 32] Size after rate matching (corresponds to G in 3GPP).

                                                                 In encoder-only mode (when [CH_SELECTION] = 0x3), this is the length
                                                                 of mother code. When [SYMB_ALIGNED] = 0x1 or [BYPASS_SEGMENTATION] =
                                                                 0, [G_SIZE] must be an exact multiple of [MOD_ORDER].

                                                                 When:

                                                                 _ [CH_SELECTION] = 0x2, [G_SIZE] must be 0x360.

                                                                 _ [CH_SELECTION] = 0x3, [G_SIZE] must be one of {0x20,0x40,0x80,0x100,0x200}.

                                                                 _ Otherwise, [G_SIZE] must be in the range [[K_SIZE] , 0x1FFF]. */
        uint64_t reserved_24_31        : 8;
        uint64_t k_size                : 8;  /**< [ 23: 16] Payload size including CRC.

                                                                 Must be set to 0x0 for scrambling sequence output mode (when [CH_SELECTION] = 0x2).

                                                                 When [BYPASS_CRC] = 0x0, [K_SIZE] must be in the range [0x19, 0xA4].

                                                                 When [BYPASS_CRC] = 0x1, [K_SIZE] must be in the range [0x1, 0xA4].

                                                                 The length of the input stream is [K_SIZE] when [BYPASS_CRC] = 0x1, [K_SIZE] - 0x18 otherwise.
                                                                 Note that, although [K_SIZE] could be less than 0x24, to comply with the 3GPP standard (38.212
                                                                 7.3.1), if the number of information bits in DCI is less
                                                                 than 12 bits, zeros must be appended to input bit stream to make payload size
                                                                 0xC (i.e, [K_SIZE] = 0x24). */
        uint64_t task_id               : 16; /**< [ 15:  0] Each task in a job must be assigned a unique ID. The task ID will be
                                                                 included in the output to correctly identify the output for each task. */
#else /* Word 0 - Little Endian */
        uint64_t task_id               : 16; /**< [ 15:  0] Each task in a job must be assigned a unique ID. The task ID will be
                                                                 included in the output to correctly identify the output for each task. */
        uint64_t k_size                : 8;  /**< [ 23: 16] Payload size including CRC.

                                                                 Must be set to 0x0 for scrambling sequence output mode (when [CH_SELECTION] = 0x2).

                                                                 When [BYPASS_CRC] = 0x0, [K_SIZE] must be in the range [0x19, 0xA4].

                                                                 When [BYPASS_CRC] = 0x1, [K_SIZE] must be in the range [0x1, 0xA4].

                                                                 The length of the input stream is [K_SIZE] when [BYPASS_CRC] = 0x1, [K_SIZE] - 0x18 otherwise.
                                                                 Note that, although [K_SIZE] could be less than 0x24, to comply with the 3GPP standard (38.212
                                                                 7.3.1), if the number of information bits in DCI is less
                                                                 than 12 bits, zeros must be appended to input bit stream to make payload size
                                                                 0xC (i.e, [K_SIZE] = 0x24). */
        uint64_t reserved_24_31        : 8;
        uint64_t g_size                : 13; /**< [ 44: 32] Size after rate matching (corresponds to G in 3GPP).

                                                                 In encoder-only mode (when [CH_SELECTION] = 0x3), this is the length
                                                                 of mother code. When [SYMB_ALIGNED] = 0x1 or [BYPASS_SEGMENTATION] =
                                                                 0, [G_SIZE] must be an exact multiple of [MOD_ORDER].

                                                                 When:

                                                                 _ [CH_SELECTION] = 0x2, [G_SIZE] must be 0x360.

                                                                 _ [CH_SELECTION] = 0x3, [G_SIZE] must be one of {0x20,0x40,0x80,0x100,0x200}.

                                                                 _ Otherwise, [G_SIZE] must be in the range [[K_SIZE] , 0x1FFF]. */
        uint64_t reserved_45_63        : 19;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_123_127      : 5;
        uint64_t v_pbch_2nd_scrm       : 3;  /**< [122:120] The v value for 2nd scramling on PBCH (section 7.3.3.1 in 38.211).

                                                                 Must be set to 0x0 if [CH_SELECTION] != 0x1. */
        uint64_t reserved_119          : 1;
        uint64_t symb_aligned          : 2;  /**< [118:117] Alignment mode.

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
        uint64_t mod_order             : 4;  /**< [116:113] Modulation order:
                                                                 0x1 = BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16-QAM.
                                                                 0x6 = 64-QAM.
                                                                 0x8 = 256-QAM.
                                                                 0xA = 1024-QAM.
                                                                 Other values = Reserved.

                                                                 Must be set to 0x2 (QPSK) for PBCH. */
        uint64_t output_data_order     : 3;  /**< [112:110] LSB bit:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Two MSB bits:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2. */
        uint64_t bypass_pbch_1st_scrm  : 1;  /**< [109:109] Bypass PBCH first scrambling:
                                                                 0 = Do not bypass first scrambler in PBCH channel.
                                                                 1 = bypass first scrambler in PBCH channel.

                                                                 Ignored when [CH_SELECTION] != 0x1.

                                                                 Must be set to 1 when [BYPASS_CRC] = 1.

                                                                 Must be set to 1 when [K_SIZE] \> 0x38. */
        uint64_t bypass_scrm           : 1;  /**< [108:108] Bypass scrambling:
                                                                 0 = not bypassed.
                                                                 1 = bypass scrambler after rate-matching. */
        uint64_t bypass_dcrc_intlv     : 1;  /**< [107:107] Bypass D-CRC interleaving:
                                                                 0 = Do not bypass D-CRC interleaving.
                                                                 1 = bypass D-CRC interleaving function. */
        uint64_t bypass_crc            : 1;  /**< [106:106] Bypass CRC generation:
                                                                 0 = Do not bypass CRC generation/attachment.
                                                                 1 = bypass CRC generation/attachment. In case of PBCH, PBCH scrambling is also bypassed

                                                                 [BYPASS_CRC] must set to 0x1 when [CH_SELECTION] = 0x3. */
        uint64_t input_data_order      : 3;  /**< [105:103] LSB bit:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Two MSB bits:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2. */
        uint64_t ch_selection          : 2;  /**< [102:101] Channel selection:
                                                                 0x0 = Control channel.
                                                                 0x1 = PBCH.
                                                                 0x2 = Scrambling sequence output.
                                                                 0x3 = Encoder only. */
        uint64_t reserved_81_100       : 20;
        uint64_t scrm_offset           : 17; /**< [ 80: 64] Offset of scrambler after rate-matching used for [CH_SELECTION] = 0x0 or 0x2.

                                                                 Note that the total offset will be equal to [SCRM_OFFSET] + Nc (= 0x640).

                                                                 This parameter must be set to 0x0 when [CH_SELECTION] = 0x1 or 0x3. In PBCH,
                                                                 scrambler offset is controlled by
                                                                 config parameter [V_PBCH_2ND_SCRM] when [CH_SELECTION] = 0x1. */
#else /* Word 1 - Little Endian */
        uint64_t scrm_offset           : 17; /**< [ 80: 64] Offset of scrambler after rate-matching used for [CH_SELECTION] = 0x0 or 0x2.

                                                                 Note that the total offset will be equal to [SCRM_OFFSET] + Nc (= 0x640).

                                                                 This parameter must be set to 0x0 when [CH_SELECTION] = 0x1 or 0x3. In PBCH,
                                                                 scrambler offset is controlled by
                                                                 config parameter [V_PBCH_2ND_SCRM] when [CH_SELECTION] = 0x1. */
        uint64_t reserved_81_100       : 20;
        uint64_t ch_selection          : 2;  /**< [102:101] Channel selection:
                                                                 0x0 = Control channel.
                                                                 0x1 = PBCH.
                                                                 0x2 = Scrambling sequence output.
                                                                 0x3 = Encoder only. */
        uint64_t input_data_order      : 3;  /**< [105:103] LSB bit:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Two MSB bits:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2. */
        uint64_t bypass_crc            : 1;  /**< [106:106] Bypass CRC generation:
                                                                 0 = Do not bypass CRC generation/attachment.
                                                                 1 = bypass CRC generation/attachment. In case of PBCH, PBCH scrambling is also bypassed

                                                                 [BYPASS_CRC] must set to 0x1 when [CH_SELECTION] = 0x3. */
        uint64_t bypass_dcrc_intlv     : 1;  /**< [107:107] Bypass D-CRC interleaving:
                                                                 0 = Do not bypass D-CRC interleaving.
                                                                 1 = bypass D-CRC interleaving function. */
        uint64_t bypass_scrm           : 1;  /**< [108:108] Bypass scrambling:
                                                                 0 = not bypassed.
                                                                 1 = bypass scrambler after rate-matching. */
        uint64_t bypass_pbch_1st_scrm  : 1;  /**< [109:109] Bypass PBCH first scrambling:
                                                                 0 = Do not bypass first scrambler in PBCH channel.
                                                                 1 = bypass first scrambler in PBCH channel.

                                                                 Ignored when [CH_SELECTION] != 0x1.

                                                                 Must be set to 1 when [BYPASS_CRC] = 1.

                                                                 Must be set to 1 when [K_SIZE] \> 0x38. */
        uint64_t output_data_order     : 3;  /**< [112:110] LSB bit:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Two MSB bits:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2. */
        uint64_t mod_order             : 4;  /**< [116:113] Modulation order:
                                                                 0x1 = BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16-QAM.
                                                                 0x6 = 64-QAM.
                                                                 0x8 = 256-QAM.
                                                                 0xA = 1024-QAM.
                                                                 Other values = Reserved.

                                                                 Must be set to 0x2 (QPSK) for PBCH. */
        uint64_t symb_aligned          : 2;  /**< [118:117] Alignment mode.

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
        uint64_t reserved_119          : 1;
        uint64_t v_pbch_2nd_scrm       : 3;  /**< [122:120] The v value for 2nd scramling on PBCH (section 7.3.3.1 in 38.211).

                                                                 Must be set to 0x0 if [CH_SELECTION] != 0x1. */
        uint64_t reserved_123_127      : 5;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_191          : 1;
        uint64_t pbch_1st_scrm_init    : 31; /**< [190:160] Only used for PBCH channel. The value is used as initial value for the first
                                                                 scrambler before CRC attachment. */
        uint64_t reserved_159          : 1;
        uint64_t scrm_init             : 31; /**< [158:128] Seed to initialize scrambler for both control channel and PBCH. */
#else /* Word 2 - Little Endian */
        uint64_t scrm_init             : 31; /**< [158:128] Seed to initialize scrambler for both control channel and PBCH. */
        uint64_t reserved_159          : 1;
        uint64_t pbch_1st_scrm_init    : 31; /**< [190:160] Only used for PBCH channel. The value is used as initial value for the first
                                                                 scrambler before CRC attachment. */
        uint64_t reserved_191          : 1;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_255          : 1;
        uint64_t vm_pbch_1st_scrm      : 7;  /**< [254:248] Value of vM described in 38.212 section 7.1.2. Starting position of pseudo-random sequence. */
        uint64_t dci_crc_mask          : 24; /**< [247:224] Mask of which CRC bits RNTI masks. Only used when [CH_SELECTION] = 0x0.

                                                                 Mapping:

                                                                 _ Assume RNTI = [x0,.., x15].

                                                                 _ [DCI_CRC_MASK][0x17:0] = [00000000 x0,..., x15].

                                                                 _ x15 is mapped on [DCI_CRC_MASK][0x0].

                                                                 _ x0 is mapped on [DCI_CRC_MASK][0xf].

                                                                 Example:

                                                                 _ [x0,.., x15] = [100000000000011] and [DCI_CRC_MASK][0x17:0x10] = [00000001].

                                                                 _ [DCI_CRC_MASK][0x17:0] = [00000001100000000000011] = 0x018003. */
        uint64_t pbch_1st_scrm_mask    : 32; /**< [223:192] Scrambling mask for first scrambling in PBCH. Only used for PBCH.

                                                                 Note that the order of masking is reversed compared to the masking order of
                                                                 config param [DCI_CRC_MASK].

                                                                 Example:

                                                                 _ If [PBCH_1ST_SCRM_MASK][0x1F:0] = [00000000...0001], first bit is scrambled. */
#else /* Word 3 - Little Endian */
        uint64_t pbch_1st_scrm_mask    : 32; /**< [223:192] Scrambling mask for first scrambling in PBCH. Only used for PBCH.

                                                                 Note that the order of masking is reversed compared to the masking order of
                                                                 config param [DCI_CRC_MASK].

                                                                 Example:

                                                                 _ If [PBCH_1ST_SCRM_MASK][0x1F:0] = [00000000...0001], first bit is scrambled. */
        uint64_t dci_crc_mask          : 24; /**< [247:224] Mask of which CRC bits RNTI masks. Only used when [CH_SELECTION] = 0x0.

                                                                 Mapping:

                                                                 _ Assume RNTI = [x0,.., x15].

                                                                 _ [DCI_CRC_MASK][0x17:0] = [00000000 x0,..., x15].

                                                                 _ x15 is mapped on [DCI_CRC_MASK][0x0].

                                                                 _ x0 is mapped on [DCI_CRC_MASK][0xf].

                                                                 Example:

                                                                 _ [x0,.., x15] = [100000000000011] and [DCI_CRC_MASK][0x17:0x10] = [00000001].

                                                                 _ [DCI_CRC_MASK][0x17:0] = [00000001100000000000011] = 0x018003. */
        uint64_t vm_pbch_1st_scrm      : 7;  /**< [254:248] Value of vM described in 38.212 section 7.1.2. Starting position of pseudo-random sequence. */
        uint64_t reserved_255          : 1;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t num_seg3_sym          : 16; /**< [319:304] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg2_sym          : 16; /**< [303:288] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg1_sym          : 16; /**< [287:272] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg0_sym          : 16; /**< [271:256] See [SEGMENT_PADDING_FLAG]. */
#else /* Word 4 - Little Endian */
        uint64_t num_seg0_sym          : 16; /**< [271:256] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg1_sym          : 16; /**< [287:272] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg2_sym          : 16; /**< [303:288] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg3_sym          : 16; /**< [319:304] See [SEGMENT_PADDING_FLAG]. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t num_seg7_sym          : 16; /**< [383:368] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg6_sym          : 16; /**< [367:352] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg5_sym          : 16; /**< [351:336] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg4_sym          : 16; /**< [335:320] See [SEGMENT_PADDING_FLAG]. */
#else /* Word 5 - Little Endian */
        uint64_t num_seg4_sym          : 16; /**< [335:320] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg5_sym          : 16; /**< [351:336] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg6_sym          : 16; /**< [367:352] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg7_sym          : 16; /**< [383:368] See [SEGMENT_PADDING_FLAG]. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t num_seg11_sym         : 16; /**< [447:432] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg10_sym         : 16; /**< [431:416] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg9_sym          : 16; /**< [415:400] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg8_sym          : 16; /**< [399:384] See [SEGMENT_PADDING_FLAG]. */
#else /* Word 6 - Little Endian */
        uint64_t num_seg8_sym          : 16; /**< [399:384] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg9_sym          : 16; /**< [415:400] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg10_sym         : 16; /**< [431:416] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg11_sym         : 16; /**< [447:432] See [SEGMENT_PADDING_FLAG]. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t reserved_506_511      : 6;
        uint64_t num_total_sym         : 24; /**< [505:482] When [SEGMENT_PADDING_FLAG] = 1, specifies the total number of symbols in all
                                                                 segments.  Each segment is padded to this size.

                                                                 Note that when [SEGMENT_PADDING_FLAG] = 1 and [SYMB_ALIGNED] = 0x0, [SYM_PER_SEG] must be
                                                                 set such that ([MOD_ORDER] x [NUM_TOTAL_SYM]) % 128 = 0.

                                                                 When [SEGMENT_PADDING_FLAG] = 1 and [SYMB_ALIGNED] = 0x1, [NUM_TOTAL_SYM] must be
                                                                 set such that (8 x [NUM_TOTAL_SYM]) % 128 = 0.

                                                                 When [SEGMENT_PADDING_FLAG] = 1 and [SYMB_ALIGNED] = 0x2 or 0x3, [NUM_TOTAL_SYM] must be
                                                                 set such that (16 x [NUM_TOTAL_SYM]) % 128 = 0. */
        uint64_t segment_padding_flag  : 1;  /**< [481:481] Segment padding mode:
                                                                 0: Pad each segment to the next multiple of 128-bit words after
                                                                 writing [NUM_SEGx_SYMS].
                                                                 1: Pad all segments to contain a total of [NUM_TOTAL_SYM] symbols.
                                                                 See [NUM_TOTAL_SYM] for more details.

                                                                 Only used when [CH_SELECTION] = 0x0 or 0x1 and
                                                                 [BYPASS_SEGMENTATION] = 0x0. Ignored otherwise.

                                                                 Each segment consists of [MOD_ORDER] x [NUM_SEGx_SYM] bits before padding. */
        uint64_t bypass_segmentation   : 1;  /**< [480:480] Used only when ([CH_SELECTION] = 0x0 or [CH_SELECTION] = 0x1); otherwise, set the value to 1.
                                                                 When set to 0, the output is segmented, with extra padding inserted.
                                                                 See [SEGMENT_PADDING_FLAG] for more details.
                                                                 When set to 1, the output bits are written contiguously with no extra padding
                                                                 inserted to segment the output. */
        uint64_t num_seg13_sym         : 16; /**< [479:464] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg12_sym         : 16; /**< [463:448] See [SEGMENT_PADDING_FLAG]. */
#else /* Word 7 - Little Endian */
        uint64_t num_seg12_sym         : 16; /**< [463:448] See [SEGMENT_PADDING_FLAG]. */
        uint64_t num_seg13_sym         : 16; /**< [479:464] See [SEGMENT_PADDING_FLAG]. */
        uint64_t bypass_segmentation   : 1;  /**< [480:480] Used only when ([CH_SELECTION] = 0x0 or [CH_SELECTION] = 0x1); otherwise, set the value to 1.
                                                                 When set to 0, the output is segmented, with extra padding inserted.
                                                                 See [SEGMENT_PADDING_FLAG] for more details.
                                                                 When set to 1, the output bits are written contiguously with no extra padding
                                                                 inserted to segment the output. */
        uint64_t segment_padding_flag  : 1;  /**< [481:481] Segment padding mode:
                                                                 0: Pad each segment to the next multiple of 128-bit words after
                                                                 writing [NUM_SEGx_SYMS].
                                                                 1: Pad all segments to contain a total of [NUM_TOTAL_SYM] symbols.
                                                                 See [NUM_TOTAL_SYM] for more details.

                                                                 Only used when [CH_SELECTION] = 0x0 or 0x1 and
                                                                 [BYPASS_SEGMENTATION] = 0x0. Ignored otherwise.

                                                                 Each segment consists of [MOD_ORDER] x [NUM_SEGx_SYM] bits before padding. */
        uint64_t num_total_sym         : 24; /**< [505:482] When [SEGMENT_PADDING_FLAG] = 1, specifies the total number of symbols in all
                                                                 segments.  Each segment is padded to this size.

                                                                 Note that when [SEGMENT_PADDING_FLAG] = 1 and [SYMB_ALIGNED] = 0x0, [SYM_PER_SEG] must be
                                                                 set such that ([MOD_ORDER] x [NUM_TOTAL_SYM]) % 128 = 0.

                                                                 When [SEGMENT_PADDING_FLAG] = 1 and [SYMB_ALIGNED] = 0x1, [NUM_TOTAL_SYM] must be
                                                                 set such that (8 x [NUM_TOTAL_SYM]) % 128 = 0.

                                                                 When [SEGMENT_PADDING_FLAG] = 1 and [SYMB_ALIGNED] = 0x2 or 0x3, [NUM_TOTAL_SYM] must be
                                                                 set such that (16 x [NUM_TOTAL_SYM]) % 128 = 0. */
        uint64_t reserved_506_511      : 6;
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t num_wr0_dma_words     : 32; /**< [575:544] Number of words to write from write DMA port 0 for this task. */
        uint64_t num_rd0_dma_words     : 32; /**< [543:512] Number of words to read from read DMA port 0 for this task. */
#else /* Word 8 - Little Endian */
        uint64_t num_rd0_dma_words     : 32; /**< [543:512] Number of words to read from read DMA port 0 for this task. */
        uint64_t num_wr0_dma_words     : 32; /**< [575:544] Number of words to write from write DMA port 0 for this task. */
#endif /* Word 8 - End */
    } s;
    /* struct cavm_penc_task_cfg_s_s cn; */
};

/**
 * Register (RSL) penc#_control
 *
 * PENC Control Register
 */
union cavm_pencx_control
{
    uint64_t u;
    struct cavm_pencx_control_s
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
    /* struct cavm_pencx_control_s cn; */
};
typedef union cavm_pencx_control cavm_pencx_control_t;

static inline uint64_t CAVM_PENCX_CONTROL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_CONTROL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043280000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_CONTROL", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_CONTROL(a) cavm_pencx_control_t
#define bustype_CAVM_PENCX_CONTROL(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_CONTROL(a) "PENCX_CONTROL"
#define busnum_CAVM_PENCX_CONTROL(a) (a)
#define arguments_CAVM_PENCX_CONTROL(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_eco
 *
 * INTERNAL: PENC ECO Register
 */
union cavm_pencx_eco
{
    uint64_t u;
    struct cavm_pencx_eco_s
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
    /* struct cavm_pencx_eco_s cn; */
};
typedef union cavm_pencx_eco cavm_pencx_eco_t;

static inline uint64_t CAVM_PENCX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_ECO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043280008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_ECO", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_ECO(a) cavm_pencx_eco_t
#define bustype_CAVM_PENCX_ECO(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_ECO(a) "PENCX_ECO"
#define busnum_CAVM_PENCX_ECO(a) (a)
#define arguments_CAVM_PENCX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_error_enable0
 *
 * Error Enable 0 Register
 * This register enables error reporting for read overflow/underflow errors.
 */
union cavm_pencx_error_enable0
{
    uint64_t u;
    struct cavm_pencx_error_enable0_s
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
    /* struct cavm_pencx_error_enable0_s cn; */
};
typedef union cavm_pencx_error_enable0 cavm_pencx_error_enable0_t;

static inline uint64_t CAVM_PENCX_ERROR_ENABLE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_ERROR_ENABLE0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043280040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_ERROR_ENABLE0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_ERROR_ENABLE0(a) cavm_pencx_error_enable0_t
#define bustype_CAVM_PENCX_ERROR_ENABLE0(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_ERROR_ENABLE0(a) "PENCX_ERROR_ENABLE0"
#define busnum_CAVM_PENCX_ERROR_ENABLE0(a) (a)
#define arguments_CAVM_PENCX_ERROR_ENABLE0(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_error_source0
 *
 * PENC Error Source 0 Register
 * This register indicates the source of read overflow/underflow errors.
 */
union cavm_pencx_error_source0
{
    uint64_t u;
    struct cavm_pencx_error_source0_s
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
    /* struct cavm_pencx_error_source0_s cn; */
};
typedef union cavm_pencx_error_source0 cavm_pencx_error_source0_t;

static inline uint64_t CAVM_PENCX_ERROR_SOURCE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_ERROR_SOURCE0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043280030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_ERROR_SOURCE0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_ERROR_SOURCE0(a) cavm_pencx_error_source0_t
#define bustype_CAVM_PENCX_ERROR_SOURCE0(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_ERROR_SOURCE0(a) "PENCX_ERROR_SOURCE0"
#define busnum_CAVM_PENCX_ERROR_SOURCE0(a) (a)
#define arguments_CAVM_PENCX_ERROR_SOURCE0(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_hab_jcfg0_ram#_data
 *
 * PENC Job Configuration 0 RAM Register
 * This register range stores the job configuration for slot 0.
 */
union cavm_pencx_hab_jcfg0_ramx_data
{
    uint64_t u;
    struct cavm_pencx_hab_jcfg0_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG0 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG0 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_hab_jcfg0_ramx_data_s cn; */
};
typedef union cavm_pencx_hab_jcfg0_ramx_data cavm_pencx_hab_jcfg0_ramx_data_t;

static inline uint64_t CAVM_PENCX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=255)))
        return 0x87e043282000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    __cavm_csr_fatal("PENCX_HAB_JCFG0_RAMX_DATA", 2, a, b, 0, 0);
}

#define typedef_CAVM_PENCX_HAB_JCFG0_RAMX_DATA(a,b) cavm_pencx_hab_jcfg0_ramx_data_t
#define bustype_CAVM_PENCX_HAB_JCFG0_RAMX_DATA(a,b) CSR_TYPE_RSL
#define basename_CAVM_PENCX_HAB_JCFG0_RAMX_DATA(a,b) "PENCX_HAB_JCFG0_RAMX_DATA"
#define busnum_CAVM_PENCX_HAB_JCFG0_RAMX_DATA(a,b) (a)
#define arguments_CAVM_PENCX_HAB_JCFG0_RAMX_DATA(a,b) (a),(b),-1,-1

/**
 * Register (RSL) penc#_hab_jcfg1_ram#_data
 *
 * PENC Job Configuration 1 RAM Register
 * This register range stores the job configuration for slot 1.
 */
union cavm_pencx_hab_jcfg1_ramx_data
{
    uint64_t u;
    struct cavm_pencx_hab_jcfg1_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG1 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG1 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_hab_jcfg1_ramx_data_s cn; */
};
typedef union cavm_pencx_hab_jcfg1_ramx_data cavm_pencx_hab_jcfg1_ramx_data_t;

static inline uint64_t CAVM_PENCX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=255)))
        return 0x87e043284000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    __cavm_csr_fatal("PENCX_HAB_JCFG1_RAMX_DATA", 2, a, b, 0, 0);
}

#define typedef_CAVM_PENCX_HAB_JCFG1_RAMX_DATA(a,b) cavm_pencx_hab_jcfg1_ramx_data_t
#define bustype_CAVM_PENCX_HAB_JCFG1_RAMX_DATA(a,b) CSR_TYPE_RSL
#define basename_CAVM_PENCX_HAB_JCFG1_RAMX_DATA(a,b) "PENCX_HAB_JCFG1_RAMX_DATA"
#define busnum_CAVM_PENCX_HAB_JCFG1_RAMX_DATA(a,b) (a)
#define arguments_CAVM_PENCX_HAB_JCFG1_RAMX_DATA(a,b) (a),(b),-1,-1

/**
 * Register (RSL) penc#_hab_jcfg2_ram#_data
 *
 * PENC Job Configuration 2 RAM Register
 * This register range stores the job configuration for slot 2.
 */
union cavm_pencx_hab_jcfg2_ramx_data
{
    uint64_t u;
    struct cavm_pencx_hab_jcfg2_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG2 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG2 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_hab_jcfg2_ramx_data_s cn; */
};
typedef union cavm_pencx_hab_jcfg2_ramx_data cavm_pencx_hab_jcfg2_ramx_data_t;

static inline uint64_t CAVM_PENCX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=255)))
        return 0x87e043286000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    __cavm_csr_fatal("PENCX_HAB_JCFG2_RAMX_DATA", 2, a, b, 0, 0);
}

#define typedef_CAVM_PENCX_HAB_JCFG2_RAMX_DATA(a,b) cavm_pencx_hab_jcfg2_ramx_data_t
#define bustype_CAVM_PENCX_HAB_JCFG2_RAMX_DATA(a,b) CSR_TYPE_RSL
#define basename_CAVM_PENCX_HAB_JCFG2_RAMX_DATA(a,b) "PENCX_HAB_JCFG2_RAMX_DATA"
#define busnum_CAVM_PENCX_HAB_JCFG2_RAMX_DATA(a,b) (a)
#define arguments_CAVM_PENCX_HAB_JCFG2_RAMX_DATA(a,b) (a),(b),-1,-1

/**
 * Register (RSL) penc#_scratch
 *
 * INTERNAL: Scratch Register
 *
 * Scratch register.
 */
union cavm_pencx_scratch
{
    uint64_t u;
    struct cavm_pencx_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_scratch_s cn; */
};
typedef union cavm_pencx_scratch cavm_pencx_scratch_t;

static inline uint64_t CAVM_PENCX_SCRATCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_SCRATCH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043280080ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_SCRATCH", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_SCRATCH(a) cavm_pencx_scratch_t
#define bustype_CAVM_PENCX_SCRATCH(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_SCRATCH(a) "PENCX_SCRATCH"
#define busnum_CAVM_PENCX_SCRATCH(a) (a)
#define arguments_CAVM_PENCX_SCRATCH(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_status
 *
 * PENC Status Register
 */
union cavm_pencx_status
{
    uint64_t u;
    struct cavm_pencx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the PENC HAB is ready to receive the next job. */
        uint64_t reserved_3            : 1;
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the PENC HAB is ready to receive the next job. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_status_s cn; */
};
typedef union cavm_pencx_status cavm_pencx_status_t;

static inline uint64_t CAVM_PENCX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043280018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_STATUS", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_STATUS(a) cavm_pencx_status_t
#define bustype_CAVM_PENCX_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_STATUS(a) "PENCX_STATUS"
#define busnum_CAVM_PENCX_STATUS(a) (a)
#define arguments_CAVM_PENCX_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_tc_config_err_flags_reg
 *
 * PENC Task Configuration Error Flags Register
 * This register reports task configuration errors that occur when a
 * specified parameter value is outside the acceptable range.
 */
union cavm_pencx_tc_config_err_flags_reg
{
    uint64_t u;
    struct cavm_pencx_tc_config_err_flags_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t invalid_vm_pbch_1st_scrm : 1;/**< [ 18: 18](RO/H) Invalid PENC_TASK_CFG_S[VM_PBCH_1ST_SCRM] value. */
        uint64_t invalid_dci_crc_mask  : 1;  /**< [ 17: 17](RO/H) Invalid PENC_TASK_CFG_S[DCI_CRC_MASK] value. */
        uint64_t reserved_16           : 1;
        uint64_t invalid_pbch_1st_scrm_init : 1;/**< [ 15: 15](RO/H) Invalid PENC_TASK_CFG_S[PBCH_1ST_SCRM_INIT] value. */
        uint64_t invalid_scrm_init     : 1;  /**< [ 14: 14](RO/H) Invalid PENC_TASK_CFG_S[SCRM_INIT] value. */
        uint64_t invalid_v_pbch_2nd_scrm : 1;/**< [ 13: 13](RO/H) Invalid PENC_TASK_CFG_S[V_PBCH_2ND_SCRM] value. */
        uint64_t invalid_symb_aligned  : 1;  /**< [ 12: 12](RO/H) Invalid PENC_TASK_CFG_S[SYMB_ALIGNED] value. */
        uint64_t invalid_mod_order     : 1;  /**< [ 11: 11](RO/H) Invalid PENC_TASK_CFG_S[MOD_ORDER] value. */
        uint64_t invalid_output_data_order : 1;/**< [ 10: 10](RO/H) Invalid PENC_TASK_CFG_S[OUTPUT_DATA_ORDER] value. */
        uint64_t invalid_bypass_pbch_1st_scrm : 1;/**< [  9:  9](RO/H) Invalid PENC_TASK_CFG_S[BYPASS_PBCH_1ST_SCRM] value. */
        uint64_t invalid_scrm_offset   : 1;  /**< [  8:  8](RO/H) Invalid PENC_TASK_CFG_S[SCRM_OFFSET] value. */
        uint64_t invalid_bypass_scrm   : 1;  /**< [  7:  7](RO/H) Invalid PENC_TASK_CFG_S[BYPASS_SCRM] value. */
        uint64_t invalid_bypass_dcrc_intlv : 1;/**< [  6:  6](RO/H) Invalid PENC_TASK_CFG_S[BYPASS_DCRC_INTLV] value. */
        uint64_t invalid_bypass_crc    : 1;  /**< [  5:  5](RO/H) Invalid PENC_TASK_CFG_S[BYPASS_CRC] value. */
        uint64_t invalid_input_data_order : 1;/**< [  4:  4](RO/H) Invalid PENC_TASK_CFG_S[INPUT_DATA_ORDER] value. */
        uint64_t invalid_ch_selection  : 1;  /**< [  3:  3](RO/H) Invalid PENC_TASK_CFG_S[CH_SELECTION] value. */
        uint64_t invalid_g_size        : 1;  /**< [  2:  2](RO/H) Invalid PENC_TASK_CFG_S[G_SIZE] value. */
        uint64_t invalid_k_size        : 1;  /**< [  1:  1](RO/H) Invalid PENC_TASK_CFG_S[K_SIZE] value. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t invalid_k_size        : 1;  /**< [  1:  1](RO/H) Invalid PENC_TASK_CFG_S[K_SIZE] value. */
        uint64_t invalid_g_size        : 1;  /**< [  2:  2](RO/H) Invalid PENC_TASK_CFG_S[G_SIZE] value. */
        uint64_t invalid_ch_selection  : 1;  /**< [  3:  3](RO/H) Invalid PENC_TASK_CFG_S[CH_SELECTION] value. */
        uint64_t invalid_input_data_order : 1;/**< [  4:  4](RO/H) Invalid PENC_TASK_CFG_S[INPUT_DATA_ORDER] value. */
        uint64_t invalid_bypass_crc    : 1;  /**< [  5:  5](RO/H) Invalid PENC_TASK_CFG_S[BYPASS_CRC] value. */
        uint64_t invalid_bypass_dcrc_intlv : 1;/**< [  6:  6](RO/H) Invalid PENC_TASK_CFG_S[BYPASS_DCRC_INTLV] value. */
        uint64_t invalid_bypass_scrm   : 1;  /**< [  7:  7](RO/H) Invalid PENC_TASK_CFG_S[BYPASS_SCRM] value. */
        uint64_t invalid_scrm_offset   : 1;  /**< [  8:  8](RO/H) Invalid PENC_TASK_CFG_S[SCRM_OFFSET] value. */
        uint64_t invalid_bypass_pbch_1st_scrm : 1;/**< [  9:  9](RO/H) Invalid PENC_TASK_CFG_S[BYPASS_PBCH_1ST_SCRM] value. */
        uint64_t invalid_output_data_order : 1;/**< [ 10: 10](RO/H) Invalid PENC_TASK_CFG_S[OUTPUT_DATA_ORDER] value. */
        uint64_t invalid_mod_order     : 1;  /**< [ 11: 11](RO/H) Invalid PENC_TASK_CFG_S[MOD_ORDER] value. */
        uint64_t invalid_symb_aligned  : 1;  /**< [ 12: 12](RO/H) Invalid PENC_TASK_CFG_S[SYMB_ALIGNED] value. */
        uint64_t invalid_v_pbch_2nd_scrm : 1;/**< [ 13: 13](RO/H) Invalid PENC_TASK_CFG_S[V_PBCH_2ND_SCRM] value. */
        uint64_t invalid_scrm_init     : 1;  /**< [ 14: 14](RO/H) Invalid PENC_TASK_CFG_S[SCRM_INIT] value. */
        uint64_t invalid_pbch_1st_scrm_init : 1;/**< [ 15: 15](RO/H) Invalid PENC_TASK_CFG_S[PBCH_1ST_SCRM_INIT] value. */
        uint64_t reserved_16           : 1;
        uint64_t invalid_dci_crc_mask  : 1;  /**< [ 17: 17](RO/H) Invalid PENC_TASK_CFG_S[DCI_CRC_MASK] value. */
        uint64_t invalid_vm_pbch_1st_scrm : 1;/**< [ 18: 18](RO/H) Invalid PENC_TASK_CFG_S[VM_PBCH_1ST_SCRM] value. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_tc_config_err_flags_reg_s cn; */
};
typedef union cavm_pencx_tc_config_err_flags_reg cavm_pencx_tc_config_err_flags_reg_t;

static inline uint64_t CAVM_PENCX_TC_CONFIG_ERR_FLAGS_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_TC_CONFIG_ERR_FLAGS_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043281040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_TC_CONFIG_ERR_FLAGS_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_TC_CONFIG_ERR_FLAGS_REG(a) cavm_pencx_tc_config_err_flags_reg_t
#define bustype_CAVM_PENCX_TC_CONFIG_ERR_FLAGS_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_TC_CONFIG_ERR_FLAGS_REG(a) "PENCX_TC_CONFIG_ERR_FLAGS_REG"
#define busnum_CAVM_PENCX_TC_CONFIG_ERR_FLAGS_REG(a) (a)
#define arguments_CAVM_PENCX_TC_CONFIG_ERR_FLAGS_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_tc_config_reg#
 *
 * INTERNAL: TC Task Config Registers
 *
 * TC task config registers.
 */
union cavm_pencx_tc_config_regx
{
    uint64_t u;
    struct cavm_pencx_tc_config_regx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_tc_config_regx_s cn; */
};
typedef union cavm_pencx_tc_config_regx cavm_pencx_tc_config_regx_t;

static inline uint64_t CAVM_PENCX_TC_CONFIG_REGX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_TC_CONFIG_REGX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=2)))
        return 0x87e043281400ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x3);
    __cavm_csr_fatal("PENCX_TC_CONFIG_REGX", 2, a, b, 0, 0);
}

#define typedef_CAVM_PENCX_TC_CONFIG_REGX(a,b) cavm_pencx_tc_config_regx_t
#define bustype_CAVM_PENCX_TC_CONFIG_REGX(a,b) CSR_TYPE_RSL
#define basename_CAVM_PENCX_TC_CONFIG_REGX(a,b) "PENCX_TC_CONFIG_REGX"
#define busnum_CAVM_PENCX_TC_CONFIG_REGX(a,b) (a)
#define arguments_CAVM_PENCX_TC_CONFIG_REGX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) penc#_tc_control_reg
 *
 * PENC Encoder Control Register
 * This register configures the PENC internal encoder core.
 */
union cavm_pencx_tc_control_reg
{
    uint64_t u;
    struct cavm_pencx_tc_control_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) Internal core control bits:
                                                                 bit\<0\> = clock gating disable.
                                                                 bit\<1\> = configuration check disable.
                                                                 bit\<2\> = wait until the core is idle before accepting the next task
                                                                 (degrades the throughput).
                                                                 bit\<3\>  = wait until the core is idle before accepting the next task
                                                                 in case of changing phy_mode (degrades the throughput).
                                                                 bit\<4\> = wait until the core is idle before accepting the next task
                                                                 in case of changing channel_mode (degrades the throughput). */
#else /* Word 0 - Little Endian */
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) Internal core control bits:
                                                                 bit\<0\> = clock gating disable.
                                                                 bit\<1\> = configuration check disable.
                                                                 bit\<2\> = wait until the core is idle before accepting the next task
                                                                 (degrades the throughput).
                                                                 bit\<3\>  = wait until the core is idle before accepting the next task
                                                                 in case of changing phy_mode (degrades the throughput).
                                                                 bit\<4\> = wait until the core is idle before accepting the next task
                                                                 in case of changing channel_mode (degrades the throughput). */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    struct cavm_pencx_tc_control_reg_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t reserved_5_31         : 27;
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) Internal core control bits:
                                                                 bit\<0\> = clock gating disable.
                                                                 bit\<1\> = configuration check disable.
                                                                 bit\<2\> = wait until the core is idle before accepting the next task
                                                                 (degrades the throughput).
                                                                 bit\<3\>  = wait until the core is idle before accepting the next task
                                                                 in case of changing phy_mode (degrades the throughput).
                                                                 bit\<4\> = wait until the core is idle before accepting the next task
                                                                 in case of changing channel_mode (degrades the throughput). */
#else /* Word 0 - Little Endian */
        uint64_t control_bus           : 5;  /**< [  4:  0](R/W) Internal core control bits:
                                                                 bit\<0\> = clock gating disable.
                                                                 bit\<1\> = configuration check disable.
                                                                 bit\<2\> = wait until the core is idle before accepting the next task
                                                                 (degrades the throughput).
                                                                 bit\<3\>  = wait until the core is idle before accepting the next task
                                                                 in case of changing phy_mode (degrades the throughput).
                                                                 bit\<4\> = wait until the core is idle before accepting the next task
                                                                 in case of changing channel_mode (degrades the throughput). */
        uint64_t reserved_5_31         : 27;
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_pencx_tc_control_reg cavm_pencx_tc_control_reg_t;

static inline uint64_t CAVM_PENCX_TC_CONTROL_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_TC_CONTROL_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043281010ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_TC_CONTROL_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_TC_CONTROL_REG(a) cavm_pencx_tc_control_reg_t
#define bustype_CAVM_PENCX_TC_CONTROL_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_TC_CONTROL_REG(a) "PENCX_TC_CONTROL_REG"
#define busnum_CAVM_PENCX_TC_CONTROL_REG(a) (a)
#define arguments_CAVM_PENCX_TC_CONTROL_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_tc_error_mask_reg
 *
 * PENC Encoder Core Error Mask Register
 * This register enables internal encoder errors. Errors reported in
 * PENC()_TC_ERROR_REG will generate an error signal only when the
 * corresponding bit is set in PENC()_TC_ERROR_MASK_REG.
 */
union cavm_pencx_tc_error_mask_reg
{
    uint64_t u;
    struct cavm_pencx_tc_error_mask_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
#else /* Word 0 - Little Endian */
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_tc_error_mask_reg_s cn; */
};
typedef union cavm_pencx_tc_error_mask_reg cavm_pencx_tc_error_mask_reg_t;

static inline uint64_t CAVM_PENCX_TC_ERROR_MASK_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_TC_ERROR_MASK_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043281030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_TC_ERROR_MASK_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_TC_ERROR_MASK_REG(a) cavm_pencx_tc_error_mask_reg_t
#define bustype_CAVM_PENCX_TC_ERROR_MASK_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_TC_ERROR_MASK_REG(a) "PENCX_TC_ERROR_MASK_REG"
#define busnum_CAVM_PENCX_TC_ERROR_MASK_REG(a) (a)
#define arguments_CAVM_PENCX_TC_ERROR_MASK_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_tc_error_reg
 *
 * PENC Encoder Error Register
 * This register reports various error conditions.
 *
 * All errors reported in this register are reported as FATAL errors, and the
 * MHBW registers can be inspected to determine the job tag(s) associated with
 * the error(s).
 */
union cavm_pencx_tc_error_reg
{
    uint64_t u;
    struct cavm_pencx_tc_error_reg_s
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
    /* struct cavm_pencx_tc_error_reg_s cn; */
};
typedef union cavm_pencx_tc_error_reg cavm_pencx_tc_error_reg_t;

static inline uint64_t CAVM_PENCX_TC_ERROR_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_TC_ERROR_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043281038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_TC_ERROR_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_TC_ERROR_REG(a) cavm_pencx_tc_error_reg_t
#define bustype_CAVM_PENCX_TC_ERROR_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_TC_ERROR_REG(a) "PENCX_TC_ERROR_REG"
#define busnum_CAVM_PENCX_TC_ERROR_REG(a) (a)
#define arguments_CAVM_PENCX_TC_ERROR_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_tc_main_reset_reg
 *
 * PENC Encoder Reset Register
 * This register provides a reset for the internal encoder core.
 */
union cavm_pencx_tc_main_reset_reg
{
    uint64_t u;
    struct cavm_pencx_tc_main_reset_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Any write to this register will reset the internal encoder core. */
#else /* Word 0 - Little Endian */
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Any write to this register will reset the internal encoder core. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_tc_main_reset_reg_s cn; */
};
typedef union cavm_pencx_tc_main_reset_reg cavm_pencx_tc_main_reset_reg_t;

static inline uint64_t CAVM_PENCX_TC_MAIN_RESET_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_TC_MAIN_RESET_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043281000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_TC_MAIN_RESET_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_TC_MAIN_RESET_REG(a) cavm_pencx_tc_main_reset_reg_t
#define bustype_CAVM_PENCX_TC_MAIN_RESET_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_TC_MAIN_RESET_REG(a) "PENCX_TC_MAIN_RESET_REG"
#define busnum_CAVM_PENCX_TC_MAIN_RESET_REG(a) (a)
#define arguments_CAVM_PENCX_TC_MAIN_RESET_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_tc_main_start_reg
 *
 * INTERNAL: TC Start Register
 *
 * TC start register.
 */
union cavm_pencx_tc_main_start_reg
{
    uint64_t u;
    struct cavm_pencx_tc_main_start_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
#else /* Word 0 - Little Endian */
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_tc_main_start_reg_s cn; */
};
typedef union cavm_pencx_tc_main_start_reg cavm_pencx_tc_main_start_reg_t;

static inline uint64_t CAVM_PENCX_TC_MAIN_START_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_TC_MAIN_START_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043281008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_TC_MAIN_START_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_TC_MAIN_START_REG(a) cavm_pencx_tc_main_start_reg_t
#define bustype_CAVM_PENCX_TC_MAIN_START_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_TC_MAIN_START_REG(a) "PENCX_TC_MAIN_START_REG"
#define busnum_CAVM_PENCX_TC_MAIN_START_REG(a) (a)
#define arguments_CAVM_PENCX_TC_MAIN_START_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_tc_mon_reg
 *
 * INTERNAL: TC Monitoring Registers
 *
 * TC mon registers.
 */
union cavm_pencx_tc_mon_reg
{
    uint64_t u;
    struct cavm_pencx_tc_mon_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bus_val               : 16; /**< [ 15:  0](RO/H) Encoder core task output monitoring values.
                                                                 mon_reg0_bus = Identifier associated to the Q output interface. Valid when q_avl is HIGH. */
#else /* Word 0 - Little Endian */
        uint64_t bus_val               : 16; /**< [ 15:  0](RO/H) Encoder core task output monitoring values.
                                                                 mon_reg0_bus = Identifier associated to the Q output interface. Valid when q_avl is HIGH. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pencx_tc_mon_reg_s cn; */
};
typedef union cavm_pencx_tc_mon_reg cavm_pencx_tc_mon_reg_t;

static inline uint64_t CAVM_PENCX_TC_MON_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_TC_MON_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043281300ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_TC_MON_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_TC_MON_REG(a) cavm_pencx_tc_mon_reg_t
#define bustype_CAVM_PENCX_TC_MON_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_TC_MON_REG(a) "PENCX_TC_MON_REG"
#define busnum_CAVM_PENCX_TC_MON_REG(a) (a)
#define arguments_CAVM_PENCX_TC_MON_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) penc#_tc_status_reg
 *
 * PENC Encoder Status Register
 * This register reports status from the internal encoder core.
 */
union cavm_pencx_tc_status_reg
{
    uint64_t u;
    struct cavm_pencx_tc_status_reg_s
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
    /* struct cavm_pencx_tc_status_reg_s cn; */
};
typedef union cavm_pencx_tc_status_reg cavm_pencx_tc_status_reg_t;

static inline uint64_t CAVM_PENCX_TC_STATUS_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PENCX_TC_STATUS_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043281020ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PENCX_TC_STATUS_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PENCX_TC_STATUS_REG(a) cavm_pencx_tc_status_reg_t
#define bustype_CAVM_PENCX_TC_STATUS_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PENCX_TC_STATUS_REG(a) "PENCX_TC_STATUS_REG"
#define busnum_CAVM_PENCX_TC_STATUS_REG(a) (a)
#define arguments_CAVM_PENCX_TC_STATUS_REG(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_PENC_H__ */
