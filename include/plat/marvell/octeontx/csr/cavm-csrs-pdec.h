#ifndef __CAVM_CSRS_PDEC_H__
#define __CAVM_CSRS_PDEC_H__
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
 * OcteonTX PDEC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure pdec_common_cfg_s
 *
 * PDEC Common Configuration Structure
 * This structure defines the first word of the job configuration for all
 * PDEC jobs.
 */
union cavm_pdec_common_cfg_s
{
    uint64_t u;
    struct cavm_pdec_common_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t num_cfg_words_per_task : 8; /**< [ 23: 16] The number of job configuration words for each task. This field must be programed to 0x9. */
        uint64_t reserved_5_15         : 11;
        uint64_t num_bundled_tasks     : 5;  /**< [  4:  0] The number of tasks in this job with the range of [0x1,0x10]. */
#else /* Word 0 - Little Endian */
        uint64_t num_bundled_tasks     : 5;  /**< [  4:  0] The number of tasks in this job with the range of [0x1,0x10]. */
        uint64_t reserved_5_15         : 11;
        uint64_t num_cfg_words_per_task : 8; /**< [ 23: 16] The number of job configuration words for each task. This field must be programed to 0x9. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdec_common_cfg_s_s cn; */
};

/**
 * Structure pdec_report_s
 *
 * PDEC Report Bit Structure
 * This structure defines the report output for each task. It is appended at
 * the end of the decoded output written to port 0.
 */
union cavm_pdec_report_s
{
    uint64_t u[36];
    struct cavm_pdec_report_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t crc_calculated0       : 11; /**< [ 59: 49] Calculated CRC of the reported path (For the first CB) */
        uint64_t crc_decoded0          : 11; /**< [ 48: 38] Decoded CRC of the reported path (For the first CB) */
        uint64_t nfpc_error0           : 5;  /**< [ 37: 33] Number of errors in FPC metric (for the first CB). */
        uint64_t idx_decoded0          : 6;  /**< [ 32: 27] For the first CB, it reports the index, within [CRC_TRIALS], of the path that is
                                                                 reported in the decoder output. */
        uint64_t crc_error0            : 1;  /**< [ 26: 26] For the first CB, it reports the result of the CRC check of the path that is
                                                                 reported in the decoder output. When all paths within [CRC_TRIALS] paths have
                                                                 a CRC error, this flag is 1. */
        uint64_t nlists                : 6;  /**< [ 25: 20] Number of lists that are considered in list decoding. It is equal to the number
                                                                 of lists selected by PDEC_TASK_CFG_S[LIST_SIZE]. */
        uint64_t num_cbs_out           : 4;  /**< [ 19: 16] Number of CBs in the range of {0x1,0x2}. It is equal to PDEC_TASK_CFG_S[NUM_CBS]
                                                                 in the task configuration. */
        uint64_t task_id               : 16; /**< [ 15:  0] The task ID specified in PDEC_TASK_CFG_S[TASK_ID]. */
#else /* Word 0 - Little Endian */
        uint64_t task_id               : 16; /**< [ 15:  0] The task ID specified in PDEC_TASK_CFG_S[TASK_ID]. */
        uint64_t num_cbs_out           : 4;  /**< [ 19: 16] Number of CBs in the range of {0x1,0x2}. It is equal to PDEC_TASK_CFG_S[NUM_CBS]
                                                                 in the task configuration. */
        uint64_t nlists                : 6;  /**< [ 25: 20] Number of lists that are considered in list decoding. It is equal to the number
                                                                 of lists selected by PDEC_TASK_CFG_S[LIST_SIZE]. */
        uint64_t crc_error0            : 1;  /**< [ 26: 26] For the first CB, it reports the result of the CRC check of the path that is
                                                                 reported in the decoder output. When all paths within [CRC_TRIALS] paths have
                                                                 a CRC error, this flag is 1. */
        uint64_t idx_decoded0          : 6;  /**< [ 32: 27] For the first CB, it reports the index, within [CRC_TRIALS], of the path that is
                                                                 reported in the decoder output. */
        uint64_t nfpc_error0           : 5;  /**< [ 37: 33] Number of errors in FPC metric (for the first CB). */
        uint64_t crc_decoded0          : 11; /**< [ 48: 38] Decoded CRC of the reported path (For the first CB) */
        uint64_t crc_calculated0       : 11; /**< [ 59: 49] Calculated CRC of the reported path (For the first CB) */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t pm_max0               : 16; /**< [127:112] For the first CB, it reports the maximum path metric of the [NLISTS] paths. */
        uint64_t pm_min0               : 16; /**< [111: 96] For the first CB, it reports the minimum path metric of the [NLISTS] paths. */
        uint64_t pm_decoded0           : 16; /**< [ 95: 80] For the first CB, it reports the path metric of the reported path. */
        uint64_t cber0                 : 16; /**< [ 79: 64] For the first CB, it reports the number of bit-wise differences between the bits
                                                                 from hard-decision of input LLRs and the re-encoded bits from the decoded bits. */
#else /* Word 1 - Little Endian */
        uint64_t cber0                 : 16; /**< [ 79: 64] For the first CB, it reports the number of bit-wise differences between the bits
                                                                 from hard-decision of input LLRs and the re-encoded bits from the decoded bits. */
        uint64_t pm_decoded0           : 16; /**< [ 95: 80] For the first CB, it reports the path metric of the reported path. */
        uint64_t pm_min0               : 16; /**< [111: 96] For the first CB, it reports the minimum path metric of the [NLISTS] paths. */
        uint64_t pm_max0               : 16; /**< [127:112] For the first CB, it reports the maximum path metric of the [NLISTS] paths. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_188_191      : 4;
        uint64_t crc_calculated1       : 11; /**< [187:177] Calculated CRC of the reported path (For the second CB). If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t crc_decoded1          : 11; /**< [176:166] Decoded CRC of the reported path (For the second CB). If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t nfpc_error1           : 5;  /**< [165:161] Number of errors in FPC metric for second CB. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1,
                                                                 this field is undefined. */
        uint64_t idx_decoded1          : 6;  /**< [160:155] For the second CB, it reports the index, within [CRC_TRIALS], of the path that
                                                                 is reported in the decoder output. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t crc_error1            : 1;  /**< [154:154] For the second CB, it reports the result of the CRC check of the path that is
                                                                 reported in the decoder output. When all paths within [CRC_TRIALS] paths have
                                                                 a CRC error this flag is 1. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t crc_trials            : 26; /**< [153:128] Number of codewords candidates that are tested by the CRC checker to select the output codeword. */
#else /* Word 2 - Little Endian */
        uint64_t crc_trials            : 26; /**< [153:128] Number of codewords candidates that are tested by the CRC checker to select the output codeword. */
        uint64_t crc_error1            : 1;  /**< [154:154] For the second CB, it reports the result of the CRC check of the path that is
                                                                 reported in the decoder output. When all paths within [CRC_TRIALS] paths have
                                                                 a CRC error this flag is 1. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t idx_decoded1          : 6;  /**< [160:155] For the second CB, it reports the index, within [CRC_TRIALS], of the path that
                                                                 is reported in the decoder output. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t nfpc_error1           : 5;  /**< [165:161] Number of errors in FPC metric for second CB. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1,
                                                                 this field is undefined. */
        uint64_t crc_decoded1          : 11; /**< [176:166] Decoded CRC of the reported path (For the second CB). If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t crc_calculated1       : 11; /**< [187:177] Calculated CRC of the reported path (For the second CB). If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t reserved_188_191      : 4;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t pm_max1               : 16; /**< [255:240] For second CB, it reports the maximum path metric of the [NLISTS] paths. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t pm_min1               : 16; /**< [239:224] For second CB, it reports the minimum path metric of the [NLISTS] paths. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t pm_decoded1           : 16; /**< [223:208] For second CB, it reports the path metric of selected list. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1,
                                                                 this field is undefined. */
        uint64_t cber1                 : 16; /**< [207:192] For second CB, it reports the number of bit-wise differences between the bits
                                                                 from hard-decision of input LLRs and the re-encoded bits from the decoded bits.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
#else /* Word 3 - Little Endian */
        uint64_t cber1                 : 16; /**< [207:192] For second CB, it reports the number of bit-wise differences between the bits
                                                                 from hard-decision of input LLRs and the re-encoded bits from the decoded bits.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t pm_decoded1           : 16; /**< [223:208] For second CB, it reports the path metric of selected list. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1,
                                                                 this field is undefined. */
        uint64_t pm_min1               : 16; /**< [239:224] For second CB, it reports the minimum path metric of the [NLISTS] paths. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
        uint64_t pm_max1               : 16; /**< [255:240] For second CB, it reports the maximum path metric of the [NLISTS] paths. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is undefined. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_300_319      : 20;
        uint64_t nfpc_error1_0         : 5;  /**< [299:295] For the second CB, it reports the number of errors in FPC metric of the first
                                                                 path. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_0                 : 16; /**< [294:279] For the second CB, it reports the calculated path metric of the first path. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_0          : 1;  /**< [278:278] For the second CB, it reports the result of the CRC check of the first path. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_0         : 5;  /**< [277:273] For the first CB, it reports the number of errors in FPC metric of the first path. */
        uint64_t pm0_0                 : 16; /**< [272:257] For the first CB, it reports the calculated path metric of the first path. */
        uint64_t crc_error0_0          : 1;  /**< [256:256] For the first CB, it reports the result of the CRC check of the first path. */
#else /* Word 4 - Little Endian */
        uint64_t crc_error0_0          : 1;  /**< [256:256] For the first CB, it reports the result of the CRC check of the first path. */
        uint64_t pm0_0                 : 16; /**< [272:257] For the first CB, it reports the calculated path metric of the first path. */
        uint64_t nfpc_error0_0         : 5;  /**< [277:273] For the first CB, it reports the number of errors in FPC metric of the first path. */
        uint64_t crc_error1_0          : 1;  /**< [278:278] For the second CB, it reports the result of the CRC check of the first path. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_0                 : 16; /**< [294:279] For the second CB, it reports the calculated path metric of the first path. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_0         : 5;  /**< [299:295] For the second CB, it reports the number of errors in FPC metric of the first
                                                                 path. If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_300_319      : 20;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_364_383      : 20;
        uint64_t nfpc_error1_1         : 5;  /**< [363:359] It reports the number of errors in FPC metric of the 2nd path for the second CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_1                 : 16; /**< [358:343] It reports the calculated path metric of the 2nd path for the second CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_1          : 1;  /**< [342:342] It reports the result of the CRC check of the 2nd path for the second CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_1         : 5;  /**< [341:337] It reports the number of errors in FPC metric of the 2nd path for the first CB. */
        uint64_t pm0_1                 : 16; /**< [336:321] It reports the calculated path metric of the 2nd path for the first CB. */
        uint64_t crc_error0_1          : 1;  /**< [320:320] It reports the result of the CRC check of the 2nd path for the first CB. */
#else /* Word 5 - Little Endian */
        uint64_t crc_error0_1          : 1;  /**< [320:320] It reports the result of the CRC check of the 2nd path for the first CB. */
        uint64_t pm0_1                 : 16; /**< [336:321] It reports the calculated path metric of the 2nd path for the first CB. */
        uint64_t nfpc_error0_1         : 5;  /**< [341:337] It reports the number of errors in FPC metric of the 2nd path for the first CB. */
        uint64_t crc_error1_1          : 1;  /**< [342:342] It reports the result of the CRC check of the 2nd path for the second CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_1                 : 16; /**< [358:343] It reports the calculated path metric of the 2nd path for the second CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_1         : 5;  /**< [363:359] It reports the number of errors in FPC metric of the 2nd path for the second CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_364_383      : 20;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_428_447      : 20;
        uint64_t nfpc_error1_2         : 5;  /**< [427:423] It reports the number of errors in FPC metric of the 3-rd path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_2                 : 16; /**< [422:407] It reports the calculated path metric of the 3-rd path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_2          : 1;  /**< [406:406] It reports the result of the CRC check of the 3-rd path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_2         : 5;  /**< [405:401] It reports the number of errors in FPC metric of the 3-rd path for the first CB. */
        uint64_t pm0_2                 : 16; /**< [400:385] It reports the calculated path metric of the 3-rd path for the first CB. */
        uint64_t crc_error0_2          : 1;  /**< [384:384] It reports the result of the CRC check of the 3-rd path for the first CB. */
#else /* Word 6 - Little Endian */
        uint64_t crc_error0_2          : 1;  /**< [384:384] It reports the result of the CRC check of the 3-rd path for the first CB. */
        uint64_t pm0_2                 : 16; /**< [400:385] It reports the calculated path metric of the 3-rd path for the first CB. */
        uint64_t nfpc_error0_2         : 5;  /**< [405:401] It reports the number of errors in FPC metric of the 3-rd path for the first CB. */
        uint64_t crc_error1_2          : 1;  /**< [406:406] It reports the result of the CRC check of the 3-rd path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_2                 : 16; /**< [422:407] It reports the calculated path metric of the 3-rd path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_2         : 5;  /**< [427:423] It reports the number of errors in FPC metric of the 3-rd path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_428_447      : 20;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t reserved_492_511      : 20;
        uint64_t nfpc_error1_3         : 5;  /**< [491:487] It reports the number of errors in FPC metric of the 4-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_3                 : 16; /**< [486:471] It reports the calculated path metric of the 4-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_3          : 1;  /**< [470:470] It reports the result of the CRC check of the 4-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_3         : 5;  /**< [469:465] It reports the number of errors in FPC metric of the 4-th path for the first CB. */
        uint64_t pm0_3                 : 16; /**< [464:449] It reports the calculated path metric of the 4-th path for the first CB. */
        uint64_t crc_error0_3          : 1;  /**< [448:448] It reports the result of the CRC check of the 4-th path for the first CB. */
#else /* Word 7 - Little Endian */
        uint64_t crc_error0_3          : 1;  /**< [448:448] It reports the result of the CRC check of the 4-th path for the first CB. */
        uint64_t pm0_3                 : 16; /**< [464:449] It reports the calculated path metric of the 4-th path for the first CB. */
        uint64_t nfpc_error0_3         : 5;  /**< [469:465] It reports the number of errors in FPC metric of the 4-th path for the first CB. */
        uint64_t crc_error1_3          : 1;  /**< [470:470] It reports the result of the CRC check of the 4-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_3                 : 16; /**< [486:471] It reports the calculated path metric of the 4-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_3         : 5;  /**< [491:487] It reports the number of errors in FPC metric of the 4-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_492_511      : 20;
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t reserved_556_575      : 20;
        uint64_t nfpc_error1_4         : 5;  /**< [555:551] It reports the number of errors in FPC metric of the 5-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_4                 : 16; /**< [550:535] It reports the calculated path metric of the 5-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_4          : 1;  /**< [534:534] It reports the result of the CRC check of the 5-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_4         : 5;  /**< [533:529] It reports the number of errors in FPC metric of the 5-th path for the first CB. */
        uint64_t pm0_4                 : 16; /**< [528:513] It reports the calculated path metric of the 5-th path for the first CB. */
        uint64_t crc_error0_4          : 1;  /**< [512:512] It reports the result of the CRC check of the 5-th path for the first CB. */
#else /* Word 8 - Little Endian */
        uint64_t crc_error0_4          : 1;  /**< [512:512] It reports the result of the CRC check of the 5-th path for the first CB. */
        uint64_t pm0_4                 : 16; /**< [528:513] It reports the calculated path metric of the 5-th path for the first CB. */
        uint64_t nfpc_error0_4         : 5;  /**< [533:529] It reports the number of errors in FPC metric of the 5-th path for the first CB. */
        uint64_t crc_error1_4          : 1;  /**< [534:534] It reports the result of the CRC check of the 5-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_4                 : 16; /**< [550:535] It reports the calculated path metric of the 5-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_4         : 5;  /**< [555:551] It reports the number of errors in FPC metric of the 5-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_556_575      : 20;
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t reserved_620_639      : 20;
        uint64_t nfpc_error1_5         : 5;  /**< [619:615] It reports the number of errors in FPC metric of the 6-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_5                 : 16; /**< [614:599] It reports the calculated path metric of the 6-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_5          : 1;  /**< [598:598] It reports the result of the CRC check of the 6-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_5         : 5;  /**< [597:593] It reports the number of errors in FPC metric of the 6-th path for the first CB. */
        uint64_t pm0_5                 : 16; /**< [592:577] It reports the calculated path metric of the 6-th path for the first CB. */
        uint64_t crc_error0_5          : 1;  /**< [576:576] It reports the result of the CRC check of the 6-th path for the first CB. */
#else /* Word 9 - Little Endian */
        uint64_t crc_error0_5          : 1;  /**< [576:576] It reports the result of the CRC check of the 6-th path for the first CB. */
        uint64_t pm0_5                 : 16; /**< [592:577] It reports the calculated path metric of the 6-th path for the first CB. */
        uint64_t nfpc_error0_5         : 5;  /**< [597:593] It reports the number of errors in FPC metric of the 6-th path for the first CB. */
        uint64_t crc_error1_5          : 1;  /**< [598:598] It reports the result of the CRC check of the 6-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_5                 : 16; /**< [614:599] It reports the calculated path metric of the 6-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_5         : 5;  /**< [619:615] It reports the number of errors in FPC metric of the 6-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_620_639      : 20;
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t reserved_684_703      : 20;
        uint64_t nfpc_error1_6         : 5;  /**< [683:679] It reports the number of errors in FPC metric of the 7-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_6                 : 16; /**< [678:663] It reports the calculated path metric of the 7-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_6          : 1;  /**< [662:662] It reports the result of the CRC check of the 7-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_6         : 5;  /**< [661:657] It reports the number of errors in FPC metric of the 7-th path for the first CB. */
        uint64_t pm0_6                 : 16; /**< [656:641] It reports the calculated path metric of the 7-th path for the first CB. */
        uint64_t crc_error0_6          : 1;  /**< [640:640] It reports the result of the CRC check of the 7-th path for the first CB. */
#else /* Word 10 - Little Endian */
        uint64_t crc_error0_6          : 1;  /**< [640:640] It reports the result of the CRC check of the 7-th path for the first CB. */
        uint64_t pm0_6                 : 16; /**< [656:641] It reports the calculated path metric of the 7-th path for the first CB. */
        uint64_t nfpc_error0_6         : 5;  /**< [661:657] It reports the number of errors in FPC metric of the 7-th path for the first CB. */
        uint64_t crc_error1_6          : 1;  /**< [662:662] It reports the result of the CRC check of the 7-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_6                 : 16; /**< [678:663] It reports the calculated path metric of the 7-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_6         : 5;  /**< [683:679] It reports the number of errors in FPC metric of the 7-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_684_703      : 20;
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t reserved_748_767      : 20;
        uint64_t nfpc_error1_7         : 5;  /**< [747:743] It reports the number of errors in FPC metric of the 8-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_7                 : 16; /**< [742:727] It reports the calculated path metric of the 8-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_7          : 1;  /**< [726:726] It reports the result of the CRC check of the 8-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_7         : 5;  /**< [725:721] It reports the number of errors in FPC metric of the 8-th path for the first CB. */
        uint64_t pm0_7                 : 16; /**< [720:705] It reports the calculated path metric of the 8-th path for the first CB. */
        uint64_t crc_error0_7          : 1;  /**< [704:704] It reports the result of the CRC check of the 8-th path for the first CB. */
#else /* Word 11 - Little Endian */
        uint64_t crc_error0_7          : 1;  /**< [704:704] It reports the result of the CRC check of the 8-th path for the first CB. */
        uint64_t pm0_7                 : 16; /**< [720:705] It reports the calculated path metric of the 8-th path for the first CB. */
        uint64_t nfpc_error0_7         : 5;  /**< [725:721] It reports the number of errors in FPC metric of the 8-th path for the first CB. */
        uint64_t crc_error1_7          : 1;  /**< [726:726] It reports the result of the CRC check of the 8-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_7                 : 16; /**< [742:727] It reports the calculated path metric of the 8-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_7         : 5;  /**< [747:743] It reports the number of errors in FPC metric of the 8-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_748_767      : 20;
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t reserved_812_831      : 20;
        uint64_t nfpc_error1_8         : 5;  /**< [811:807] It reports the number of errors in FPC metric of the 9-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_8                 : 16; /**< [806:791] It reports the calculated path metric of the 9-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_8          : 1;  /**< [790:790] It reports the result of the CRC check of the 9-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_8         : 5;  /**< [789:785] It reports the number of errors in FPC metric of the 9-th path for the first CB. */
        uint64_t pm0_8                 : 16; /**< [784:769] It reports the calculated path metric of the 9-th path for the first CB. */
        uint64_t crc_error0_8          : 1;  /**< [768:768] It reports the result of the CRC check of the 9-th path for the first CB. */
#else /* Word 12 - Little Endian */
        uint64_t crc_error0_8          : 1;  /**< [768:768] It reports the result of the CRC check of the 9-th path for the first CB. */
        uint64_t pm0_8                 : 16; /**< [784:769] It reports the calculated path metric of the 9-th path for the first CB. */
        uint64_t nfpc_error0_8         : 5;  /**< [789:785] It reports the number of errors in FPC metric of the 9-th path for the first CB. */
        uint64_t crc_error1_8          : 1;  /**< [790:790] It reports the result of the CRC check of the 9-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_8                 : 16; /**< [806:791] It reports the calculated path metric of the 9-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_8         : 5;  /**< [811:807] It reports the number of errors in FPC metric of the 9-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_812_831      : 20;
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t reserved_876_895      : 20;
        uint64_t nfpc_error1_9         : 5;  /**< [875:871] It reports the number of errors in FPC metric of the 10-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_9                 : 16; /**< [870:855] It reports the calculated path metric of the 10-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_9          : 1;  /**< [854:854] It reports the result of the CRC check of the 10-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_9         : 5;  /**< [853:849] It reports the number of errors in FPC metric of the 10-th path for the first CB. */
        uint64_t pm0_9                 : 16; /**< [848:833] It reports the calculated path metric of the 10-th path for the first CB. */
        uint64_t crc_error0_9          : 1;  /**< [832:832] It reports the result of the CRC check of the 10-th path for the first CB. */
#else /* Word 13 - Little Endian */
        uint64_t crc_error0_9          : 1;  /**< [832:832] It reports the result of the CRC check of the 10-th path for the first CB. */
        uint64_t pm0_9                 : 16; /**< [848:833] It reports the calculated path metric of the 10-th path for the first CB. */
        uint64_t nfpc_error0_9         : 5;  /**< [853:849] It reports the number of errors in FPC metric of the 10-th path for the first CB. */
        uint64_t crc_error1_9          : 1;  /**< [854:854] It reports the result of the CRC check of the 10-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_9                 : 16; /**< [870:855] It reports the calculated path metric of the 10-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_9         : 5;  /**< [875:871] It reports the number of errors in FPC metric of the 10-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_876_895      : 20;
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t reserved_940_959      : 20;
        uint64_t nfpc_error1_10        : 5;  /**< [939:935] It reports the number of errors in FPC metric of the 11-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_10                : 16; /**< [934:919] It reports the calculated path metric of the 11-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_10         : 1;  /**< [918:918] It reports the result of the CRC check of the 11-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_10        : 5;  /**< [917:913] It reports the number of errors in FPC metric of the 11-th path for the first CB. */
        uint64_t pm0_10                : 16; /**< [912:897] It reports the calculated path metric of the 11-th path for the first CB. */
        uint64_t crc_error0_10         : 1;  /**< [896:896] It reports the result of the CRC check of the 11-th path for the first CB. */
#else /* Word 14 - Little Endian */
        uint64_t crc_error0_10         : 1;  /**< [896:896] It reports the result of the CRC check of the 11-th path for the first CB. */
        uint64_t pm0_10                : 16; /**< [912:897] It reports the calculated path metric of the 11-th path for the first CB. */
        uint64_t nfpc_error0_10        : 5;  /**< [917:913] It reports the number of errors in FPC metric of the 11-th path for the first CB. */
        uint64_t crc_error1_10         : 1;  /**< [918:918] It reports the result of the CRC check of the 11-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_10                : 16; /**< [934:919] It reports the calculated path metric of the 11-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_10        : 5;  /**< [939:935] It reports the number of errors in FPC metric of the 11-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_940_959      : 20;
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t reserved_1004_1023    : 20;
        uint64_t nfpc_error1_11        : 5;  /**< [1003:999] It reports the number of errors in FPC metric of the 12-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_11                : 16; /**< [998:983] It reports the calculated path metric of the 12-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_11         : 1;  /**< [982:982] It reports the result of the CRC check of the 12-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_11        : 5;  /**< [981:977] It reports the number of errors in FPC metric of the 12-th path for the first CB. */
        uint64_t pm0_11                : 16; /**< [976:961] It reports the calculated path metric of the 12-th path for the first CB. */
        uint64_t crc_error0_11         : 1;  /**< [960:960] It reports the result of the CRC check of the 12-th path for the first CB. */
#else /* Word 15 - Little Endian */
        uint64_t crc_error0_11         : 1;  /**< [960:960] It reports the result of the CRC check of the 12-th path for the first CB. */
        uint64_t pm0_11                : 16; /**< [976:961] It reports the calculated path metric of the 12-th path for the first CB. */
        uint64_t nfpc_error0_11        : 5;  /**< [981:977] It reports the number of errors in FPC metric of the 12-th path for the first CB. */
        uint64_t crc_error1_11         : 1;  /**< [982:982] It reports the result of the CRC check of the 12-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_11                : 16; /**< [998:983] It reports the calculated path metric of the 12-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_11        : 5;  /**< [1003:999] It reports the number of errors in FPC metric of the 12-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_1004_1023    : 20;
#endif /* Word 15 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 16 - Big Endian */
        uint64_t reserved_1068_1087    : 20;
        uint64_t nfpc_error1_12        : 5;  /**< [1067:1063] It reports the number of errors in FPC metric of the 13-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_12                : 16; /**< [1062:1047] It reports the calculated path metric of the 13-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_12         : 1;  /**< [1046:1046] It reports the result of the CRC check of the 13-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_12        : 5;  /**< [1045:1041] It reports the number of errors in FPC metric of the 13-th path for the first CB. */
        uint64_t pm0_12                : 16; /**< [1040:1025] It reports the calculated path metric of the 13-th path for the first CB. */
        uint64_t crc_error0_12         : 1;  /**< [1024:1024] It reports the result of the CRC check of the 13-th path for the first CB. */
#else /* Word 16 - Little Endian */
        uint64_t crc_error0_12         : 1;  /**< [1024:1024] It reports the result of the CRC check of the 13-th path for the first CB. */
        uint64_t pm0_12                : 16; /**< [1040:1025] It reports the calculated path metric of the 13-th path for the first CB. */
        uint64_t nfpc_error0_12        : 5;  /**< [1045:1041] It reports the number of errors in FPC metric of the 13-th path for the first CB. */
        uint64_t crc_error1_12         : 1;  /**< [1046:1046] It reports the result of the CRC check of the 13-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_12                : 16; /**< [1062:1047] It reports the calculated path metric of the 13-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_12        : 5;  /**< [1067:1063] It reports the number of errors in FPC metric of the 13-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_1068_1087    : 20;
#endif /* Word 16 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 17 - Big Endian */
        uint64_t reserved_1132_1151    : 20;
        uint64_t nfpc_error1_13        : 5;  /**< [1131:1127] It reports the number of errors in FPC metric of the 14-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_13                : 16; /**< [1126:1111] It reports the calculated path metric of the 14-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_13         : 1;  /**< [1110:1110] It reports the result of the CRC check of the 14-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_13        : 5;  /**< [1109:1105] It reports the number of errors in FPC metric of the 14-th path for the first CB. */
        uint64_t pm0_13                : 16; /**< [1104:1089] It reports the calculated path metric of the 14-th path for the first CB. */
        uint64_t crc_error0_13         : 1;  /**< [1088:1088] It reports the result of the CRC check of the 14-th path for the first CB. */
#else /* Word 17 - Little Endian */
        uint64_t crc_error0_13         : 1;  /**< [1088:1088] It reports the result of the CRC check of the 14-th path for the first CB. */
        uint64_t pm0_13                : 16; /**< [1104:1089] It reports the calculated path metric of the 14-th path for the first CB. */
        uint64_t nfpc_error0_13        : 5;  /**< [1109:1105] It reports the number of errors in FPC metric of the 14-th path for the first CB. */
        uint64_t crc_error1_13         : 1;  /**< [1110:1110] It reports the result of the CRC check of the 14-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_13                : 16; /**< [1126:1111] It reports the calculated path metric of the 14-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_13        : 5;  /**< [1131:1127] It reports the number of errors in FPC metric of the 14-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_1132_1151    : 20;
#endif /* Word 17 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 18 - Big Endian */
        uint64_t reserved_1196_1215    : 20;
        uint64_t nfpc_error1_14        : 5;  /**< [1195:1191] It reports the number of errors in FPC metric of the 15-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_14                : 16; /**< [1190:1175] It reports the calculated path metric of the 15-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t crc_error1_14         : 1;  /**< [1174:1174] It reports the result of the CRC check of the 15-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error0_14        : 5;  /**< [1173:1169] It reports the number of errors in FPC metric of the 15-th path for the first CB. */
        uint64_t pm0_14                : 16; /**< [1168:1153] It reports the calculated path metric of the 15-th path for the first CB. */
        uint64_t crc_error0_14         : 1;  /**< [1152:1152] It reports the result of the CRC check of the 15-th path for the first CB. */
#else /* Word 18 - Little Endian */
        uint64_t crc_error0_14         : 1;  /**< [1152:1152] It reports the result of the CRC check of the 15-th path for the first CB. */
        uint64_t pm0_14                : 16; /**< [1168:1153] It reports the calculated path metric of the 15-th path for the first CB. */
        uint64_t nfpc_error0_14        : 5;  /**< [1173:1169] It reports the number of errors in FPC metric of the 15-th path for the first CB. */
        uint64_t crc_error1_14         : 1;  /**< [1174:1174] It reports the result of the CRC check of the 15-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t pm1_14                : 16; /**< [1190:1175] It reports the calculated path metric of the 15-th path for the 2nd CB. If
                                                                 PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t nfpc_error1_14        : 5;  /**< [1195:1191] It reports the number of errors in FPC metric of the 15-th path for the 2nd CB.
                                                                 If PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to zero. */
        uint64_t reserved_1196_1215    : 20;
#endif /* Word 18 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 19 - Big Endian */
        uint64_t reserved_1260_1279    : 20;
        uint64_t nfpc_error1_15        : 5;  /**< [1259:1255] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 16-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_15                : 16; /**< [1254:1239] When [NLISTS] = 0x20, it reports the calculated path metric of the 16-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_15         : 1;  /**< [1238:1238] When [NLISTS] = 0x20, it reports the result of the CRC check of the 16-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_15        : 5;  /**< [1237:1233] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 16-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_15                : 16; /**< [1232:1217] When [NLISTS] = 0x20, it reports the calculated path metric of the 16-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_15         : 1;  /**< [1216:1216] When [NLISTS] = 0x20, it reports the result of the CRC check of the 16-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to
                                                                 zero. */
#else /* Word 19 - Little Endian */
        uint64_t crc_error0_15         : 1;  /**< [1216:1216] When [NLISTS] = 0x20, it reports the result of the CRC check of the 16-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to
                                                                 zero. */
        uint64_t pm0_15                : 16; /**< [1232:1217] When [NLISTS] = 0x20, it reports the calculated path metric of the 16-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_15        : 5;  /**< [1237:1233] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 16-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_15         : 1;  /**< [1238:1238] When [NLISTS] = 0x20, it reports the result of the CRC check of the 16-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_15                : 16; /**< [1254:1239] When [NLISTS] = 0x20, it reports the calculated path metric of the 16-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_15        : 5;  /**< [1259:1255] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 16-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1260_1279    : 20;
#endif /* Word 19 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 20 - Big Endian */
        uint64_t reserved_1324_1343    : 20;
        uint64_t nfpc_error1_16        : 5;  /**< [1323:1319] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 17-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_16                : 16; /**< [1318:1303] When [NLISTS] = 0x20, it reports the calculated path metric of the 17-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_16         : 1;  /**< [1302:1302] When [NLISTS] = 0x20, it reports the result of the CRC check of the 17-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_16        : 5;  /**< [1301:1297] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 17-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_16                : 16; /**< [1296:1281] When [NLISTS] = 0x20, it reports the calculated path metric of the 17-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_16         : 1;  /**< [1280:1280] When [NLISTS] = 0x20, it reports the result of the CRC check of the 17-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 20 - Little Endian */
        uint64_t crc_error0_16         : 1;  /**< [1280:1280] When [NLISTS] = 0x20, it reports the result of the CRC check of the 17-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_16                : 16; /**< [1296:1281] When [NLISTS] = 0x20, it reports the calculated path metric of the 17-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_16        : 5;  /**< [1301:1297] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 17-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_16         : 1;  /**< [1302:1302] When [NLISTS] = 0x20, it reports the result of the CRC check of the 17-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_16                : 16; /**< [1318:1303] When [NLISTS] = 0x20, it reports the calculated path metric of the 17-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_16        : 5;  /**< [1323:1319] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 17-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1324_1343    : 20;
#endif /* Word 20 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 21 - Big Endian */
        uint64_t reserved_1388_1407    : 20;
        uint64_t nfpc_error1_17        : 5;  /**< [1387:1383] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 18-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_17                : 16; /**< [1382:1367] When [NLISTS] = 0x20, it reports the calculated path metric of the 18-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_17         : 1;  /**< [1366:1366] When [NLISTS] = 0x20, it reports the result of the CRC check of the 18-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_17        : 5;  /**< [1365:1361] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 18-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_17                : 16; /**< [1360:1345] When [NLISTS] = 0x20, it reports the calculated path metric of the 18-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_17         : 1;  /**< [1344:1344] When [NLISTS] = 0x20, it reports the result of the CRC check of the 18-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 21 - Little Endian */
        uint64_t crc_error0_17         : 1;  /**< [1344:1344] When [NLISTS] = 0x20, it reports the result of the CRC check of the 18-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_17                : 16; /**< [1360:1345] When [NLISTS] = 0x20, it reports the calculated path metric of the 18-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_17        : 5;  /**< [1365:1361] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 18-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_17         : 1;  /**< [1366:1366] When [NLISTS] = 0x20, it reports the result of the CRC check of the 18-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_17                : 16; /**< [1382:1367] When [NLISTS] = 0x20, it reports the calculated path metric of the 18-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_17        : 5;  /**< [1387:1383] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 18-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1388_1407    : 20;
#endif /* Word 21 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 22 - Big Endian */
        uint64_t reserved_1452_1471    : 20;
        uint64_t nfpc_error1_18        : 5;  /**< [1451:1447] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 19-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_18                : 16; /**< [1446:1431] When [NLISTS] = 0x20, it reports the calculated path metric of the 19-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_18         : 1;  /**< [1430:1430] When [NLISTS] = 0x20, it reports the result of the CRC check of the 19-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_18        : 5;  /**< [1429:1425] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 19-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_18                : 16; /**< [1424:1409] When [NLISTS] = 0x20, it reports the calculated path metric of the 19-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_18         : 1;  /**< [1408:1408] When [NLISTS] = 0x20, it reports the result of the CRC check of the 19-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 22 - Little Endian */
        uint64_t crc_error0_18         : 1;  /**< [1408:1408] When [NLISTS] = 0x20, it reports the result of the CRC check of the 19-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_18                : 16; /**< [1424:1409] When [NLISTS] = 0x20, it reports the calculated path metric of the 19-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_18        : 5;  /**< [1429:1425] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 19-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_18         : 1;  /**< [1430:1430] When [NLISTS] = 0x20, it reports the result of the CRC check of the 19-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_18                : 16; /**< [1446:1431] When [NLISTS] = 0x20, it reports the calculated path metric of the 19-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_18        : 5;  /**< [1451:1447] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 19-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1452_1471    : 20;
#endif /* Word 22 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 23 - Big Endian */
        uint64_t reserved_1516_1535    : 20;
        uint64_t nfpc_error1_19        : 5;  /**< [1515:1511] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 20-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_19                : 16; /**< [1510:1495] When [NLISTS] = 0x20, it reports the calculated path metric of the 20-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_19         : 1;  /**< [1494:1494] When [NLISTS] = 0x20, it reports the result of the CRC check of the 20-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_19        : 5;  /**< [1493:1489] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 20-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_19                : 16; /**< [1488:1473] When [NLISTS] = 0x20, it reports the calculated path metric of the 20-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_19         : 1;  /**< [1472:1472] When [NLISTS] = 0x20, it reports the result of the CRC check of the 20-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 23 - Little Endian */
        uint64_t crc_error0_19         : 1;  /**< [1472:1472] When [NLISTS] = 0x20, it reports the result of the CRC check of the 20-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_19                : 16; /**< [1488:1473] When [NLISTS] = 0x20, it reports the calculated path metric of the 20-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_19        : 5;  /**< [1493:1489] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 20-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_19         : 1;  /**< [1494:1494] When [NLISTS] = 0x20, it reports the result of the CRC check of the 20-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_19                : 16; /**< [1510:1495] When [NLISTS] = 0x20, it reports the calculated path metric of the 20-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_19        : 5;  /**< [1515:1511] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 20-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1516_1535    : 20;
#endif /* Word 23 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 24 - Big Endian */
        uint64_t reserved_1580_1599    : 20;
        uint64_t nfpc_error1_20        : 5;  /**< [1579:1575] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 21-st path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_20                : 16; /**< [1574:1559] When [NLISTS] = 0x20, it reports the calculated path metric of the 21-st path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_20         : 1;  /**< [1558:1558] When [NLISTS] = 0x20, it reports the result of the CRC check of the 21-st
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_20        : 5;  /**< [1557:1553] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 21-st path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_20                : 16; /**< [1552:1537] When [NLISTS] = 0x20, it reports the calculated path metric of the 21-st path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_20         : 1;  /**< [1536:1536] When [NLISTS] = 0x20, it reports the result of the CRC check of the 21-st
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 24 - Little Endian */
        uint64_t crc_error0_20         : 1;  /**< [1536:1536] When [NLISTS] = 0x20, it reports the result of the CRC check of the 21-st
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_20                : 16; /**< [1552:1537] When [NLISTS] = 0x20, it reports the calculated path metric of the 21-st path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_20        : 5;  /**< [1557:1553] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 21-st path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_20         : 1;  /**< [1558:1558] When [NLISTS] = 0x20, it reports the result of the CRC check of the 21-st
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_20                : 16; /**< [1574:1559] When [NLISTS] = 0x20, it reports the calculated path metric of the 21-st path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_20        : 5;  /**< [1579:1575] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 21-st path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1580_1599    : 20;
#endif /* Word 24 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 25 - Big Endian */
        uint64_t reserved_1644_1663    : 20;
        uint64_t nfpc_error1_21        : 5;  /**< [1643:1639] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 22-nd path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_21                : 16; /**< [1638:1623] When [NLISTS] = 0x20, it reports the calculated path metric of the 22-nd path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_21         : 1;  /**< [1622:1622] When [NLISTS] = 0x20, it reports the result of the CRC check of the 22-nd
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_21        : 5;  /**< [1621:1617] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 22-nd path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_21                : 16; /**< [1616:1601] When [NLISTS] = 0x20, it reports the calculated path metric of the 22-nd path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_21         : 1;  /**< [1600:1600] When [NLISTS] = 0x20, it reports the result of the CRC check of the 22-nd
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 25 - Little Endian */
        uint64_t crc_error0_21         : 1;  /**< [1600:1600] When [NLISTS] = 0x20, it reports the result of the CRC check of the 22-nd
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_21                : 16; /**< [1616:1601] When [NLISTS] = 0x20, it reports the calculated path metric of the 22-nd path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_21        : 5;  /**< [1621:1617] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 22-nd path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_21         : 1;  /**< [1622:1622] When [NLISTS] = 0x20, it reports the result of the CRC check of the 22-nd
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_21                : 16; /**< [1638:1623] When [NLISTS] = 0x20, it reports the calculated path metric of the 22-nd path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_21        : 5;  /**< [1643:1639] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 22-nd path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1644_1663    : 20;
#endif /* Word 25 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 26 - Big Endian */
        uint64_t reserved_1708_1727    : 20;
        uint64_t nfpc_error1_22        : 5;  /**< [1707:1703] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 23-rd path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_22                : 16; /**< [1702:1687] When [NLISTS] = 0x20, it reports the calculated path metric of the 23-rd path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_22         : 1;  /**< [1686:1686] When [NLISTS] = 0x20, it reports the result of the CRC check of the 23-rd
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_22        : 5;  /**< [1685:1681] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 23-rd path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_22                : 16; /**< [1680:1665] When [NLISTS] = 0x20, it reports the calculated path metric of the 23-rd path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_22         : 1;  /**< [1664:1664] When [NLISTS] = 0x20, it reports the result of the CRC check of the 23-rd
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 26 - Little Endian */
        uint64_t crc_error0_22         : 1;  /**< [1664:1664] When [NLISTS] = 0x20, it reports the result of the CRC check of the 23-rd
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_22                : 16; /**< [1680:1665] When [NLISTS] = 0x20, it reports the calculated path metric of the 23-rd path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_22        : 5;  /**< [1685:1681] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 23-rd path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_22         : 1;  /**< [1686:1686] When [NLISTS] = 0x20, it reports the result of the CRC check of the 23-rd
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_22                : 16; /**< [1702:1687] When [NLISTS] = 0x20, it reports the calculated path metric of the 23-rd path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_22        : 5;  /**< [1707:1703] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 23-rd path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1708_1727    : 20;
#endif /* Word 26 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 27 - Big Endian */
        uint64_t reserved_1772_1791    : 20;
        uint64_t nfpc_error1_23        : 5;  /**< [1771:1767] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 24-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_23                : 16; /**< [1766:1751] When [NLISTS] = 0x20, it reports the calculated path metric of the 24-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_23         : 1;  /**< [1750:1750] When [NLISTS] = 0x20, it reports the result of the CRC check of the 24-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_23        : 5;  /**< [1749:1745] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 24-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_23                : 16; /**< [1744:1729] When [NLISTS] = 0x20, it reports the calculated path metric of the 24-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_23         : 1;  /**< [1728:1728] When [NLISTS] = 0x20, it reports the result of the CRC check of the 24-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 27 - Little Endian */
        uint64_t crc_error0_23         : 1;  /**< [1728:1728] When [NLISTS] = 0x20, it reports the result of the CRC check of the 24-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_23                : 16; /**< [1744:1729] When [NLISTS] = 0x20, it reports the calculated path metric of the 24-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_23        : 5;  /**< [1749:1745] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 24-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_23         : 1;  /**< [1750:1750] When [NLISTS] = 0x20, it reports the result of the CRC check of the 24-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_23                : 16; /**< [1766:1751] When [NLISTS] = 0x20, it reports the calculated path metric of the 24-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_23        : 5;  /**< [1771:1767] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 24-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1772_1791    : 20;
#endif /* Word 27 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 28 - Big Endian */
        uint64_t reserved_1836_1855    : 20;
        uint64_t nfpc_error1_24        : 5;  /**< [1835:1831] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 25-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_24                : 16; /**< [1830:1815] When [NLISTS] = 0x20, it reports the calculated path metric of the 25-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_24         : 1;  /**< [1814:1814] When [NLISTS] = 0x20, it reports the result of the CRC check of the 25-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_24        : 5;  /**< [1813:1809] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 25-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_24                : 16; /**< [1808:1793] When [NLISTS] = 0x20, it reports the calculated path metric of the 25-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_24         : 1;  /**< [1792:1792] When [NLISTS] = 0x20, it reports the result of the CRC check of the 25-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 28 - Little Endian */
        uint64_t crc_error0_24         : 1;  /**< [1792:1792] When [NLISTS] = 0x20, it reports the result of the CRC check of the 25-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_24                : 16; /**< [1808:1793] When [NLISTS] = 0x20, it reports the calculated path metric of the 25-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_24        : 5;  /**< [1813:1809] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 25-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_24         : 1;  /**< [1814:1814] When [NLISTS] = 0x20, it reports the result of the CRC check of the 25-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_24                : 16; /**< [1830:1815] When [NLISTS] = 0x20, it reports the calculated path metric of the 25-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_24        : 5;  /**< [1835:1831] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 25-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1836_1855    : 20;
#endif /* Word 28 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 29 - Big Endian */
        uint64_t reserved_1900_1919    : 20;
        uint64_t nfpc_error1_25        : 5;  /**< [1899:1895] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 26-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_25                : 16; /**< [1894:1879] When [NLISTS] = 0x20, it reports the calculated path metric of the 26-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_25         : 1;  /**< [1878:1878] When [NLISTS] = 0x20, it reports the result of the CRC check of the 26-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_25        : 5;  /**< [1877:1873] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 26-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_25                : 16; /**< [1872:1857] When [NLISTS] = 0x20, it reports the calculated path metric of the 26-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_25         : 1;  /**< [1856:1856] When [NLISTS] = 0x20, it reports the result of the CRC check of the 26-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 29 - Little Endian */
        uint64_t crc_error0_25         : 1;  /**< [1856:1856] When [NLISTS] = 0x20, it reports the result of the CRC check of the 26-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_25                : 16; /**< [1872:1857] When [NLISTS] = 0x20, it reports the calculated path metric of the 26-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_25        : 5;  /**< [1877:1873] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 26-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_25         : 1;  /**< [1878:1878] When [NLISTS] = 0x20, it reports the result of the CRC check of the 26-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_25                : 16; /**< [1894:1879] When [NLISTS] = 0x20, it reports the calculated path metric of the 26-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_25        : 5;  /**< [1899:1895] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 26-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1900_1919    : 20;
#endif /* Word 29 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 30 - Big Endian */
        uint64_t reserved_1964_1983    : 20;
        uint64_t nfpc_error1_26        : 5;  /**< [1963:1959] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 27-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_26                : 16; /**< [1958:1943] When [NLISTS] = 0x20, it reports the calculated path metric of the 27-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_26         : 1;  /**< [1942:1942] When [NLISTS] = 0x20, it reports the result of the CRC check of the 27-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_26        : 5;  /**< [1941:1937] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 27-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_26                : 16; /**< [1936:1921] When [NLISTS] = 0x20, it reports the calculated path metric of the 27-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_26         : 1;  /**< [1920:1920] When [NLISTS] = 0x20, it reports the result of the CRC check of the 27-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 30 - Little Endian */
        uint64_t crc_error0_26         : 1;  /**< [1920:1920] When [NLISTS] = 0x20, it reports the result of the CRC check of the 27-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_26                : 16; /**< [1936:1921] When [NLISTS] = 0x20, it reports the calculated path metric of the 27-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_26        : 5;  /**< [1941:1937] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 27-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_26         : 1;  /**< [1942:1942] When [NLISTS] = 0x20, it reports the result of the CRC check of the 27-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_26                : 16; /**< [1958:1943] When [NLISTS] = 0x20, it reports the calculated path metric of the 27-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_26        : 5;  /**< [1963:1959] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 27-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_1964_1983    : 20;
#endif /* Word 30 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 31 - Big Endian */
        uint64_t reserved_2028_2047    : 20;
        uint64_t nfpc_error1_27        : 5;  /**< [2027:2023] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 28-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_27                : 16; /**< [2022:2007] When [NLISTS] = 0x20, it reports the calculated path metric of the 28-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_27         : 1;  /**< [2006:2006] When [NLISTS] = 0x20, it reports the result of the CRC check of the 28-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_27        : 5;  /**< [2005:2001] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 28-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_27                : 16; /**< [2000:1985] When [NLISTS] = 0x20, it reports the calculated path metric of the 28-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_27         : 1;  /**< [1984:1984] When [NLISTS] = 0x20, it reports the result of the CRC check of the 28-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 31 - Little Endian */
        uint64_t crc_error0_27         : 1;  /**< [1984:1984] When [NLISTS] = 0x20, it reports the result of the CRC check of the 28-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_27                : 16; /**< [2000:1985] When [NLISTS] = 0x20, it reports the calculated path metric of the 28-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_27        : 5;  /**< [2005:2001] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 28-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_27         : 1;  /**< [2006:2006] When [NLISTS] = 0x20, it reports the result of the CRC check of the 28-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_27                : 16; /**< [2022:2007] When [NLISTS] = 0x20, it reports the calculated path metric of the 28-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_27        : 5;  /**< [2027:2023] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 28-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_2028_2047    : 20;
#endif /* Word 31 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 32 - Big Endian */
        uint64_t reserved_2092_2111    : 20;
        uint64_t nfpc_error1_28        : 5;  /**< [2091:2087] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 29-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_28                : 16; /**< [2086:2071] When [NLISTS] = 0x20, it reports the calculated path metric of the 29-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_28         : 1;  /**< [2070:2070] When [NLISTS] = 0x20, it reports the result of the CRC check of the 29-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_28        : 5;  /**< [2069:2065] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 29-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_28                : 16; /**< [2064:2049] When [NLISTS] = 0x20, it reports the calculated path metric of the 29-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_28         : 1;  /**< [2048:2048] When [NLISTS] = 0x20, it reports the result of the CRC check of the 29-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 32 - Little Endian */
        uint64_t crc_error0_28         : 1;  /**< [2048:2048] When [NLISTS] = 0x20, it reports the result of the CRC check of the 29-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_28                : 16; /**< [2064:2049] When [NLISTS] = 0x20, it reports the calculated path metric of the 29-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_28        : 5;  /**< [2069:2065] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 29-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_28         : 1;  /**< [2070:2070] When [NLISTS] = 0x20, it reports the result of the CRC check of the 29-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_28                : 16; /**< [2086:2071] When [NLISTS] = 0x20, it reports the calculated path metric of the 29-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_28        : 5;  /**< [2091:2087] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 29-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_2092_2111    : 20;
#endif /* Word 32 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 33 - Big Endian */
        uint64_t reserved_2156_2175    : 20;
        uint64_t nfpc_error1_29        : 5;  /**< [2155:2151] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 30-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_29                : 16; /**< [2150:2135] When [NLISTS] = 0x20, it reports the calculated path metric of the 30-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_29         : 1;  /**< [2134:2134] When [NLISTS] = 0x20, it reports the result of the CRC check of the 30-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_29        : 5;  /**< [2133:2129] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 30-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_29                : 16; /**< [2128:2113] When [NLISTS] = 0x20, it reports the calculated path metric of the 30-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_29         : 1;  /**< [2112:2112] When [NLISTS] = 0x20, it reports the result of the CRC check of the 30-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 33 - Little Endian */
        uint64_t crc_error0_29         : 1;  /**< [2112:2112] When [NLISTS] = 0x20, it reports the result of the CRC check of the 30-th
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_29                : 16; /**< [2128:2113] When [NLISTS] = 0x20, it reports the calculated path metric of the 30-th path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_29        : 5;  /**< [2133:2129] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 30-th path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_29         : 1;  /**< [2134:2134] When [NLISTS] = 0x20, it reports the result of the CRC check of the 30-th
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_29                : 16; /**< [2150:2135] When [NLISTS] = 0x20, it reports the calculated path metric of the 30-th path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_29        : 5;  /**< [2155:2151] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 30-th path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_2156_2175    : 20;
#endif /* Word 33 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 34 - Big Endian */
        uint64_t reserved_2220_2239    : 20;
        uint64_t nfpc_error1_30        : 5;  /**< [2219:2215] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 31-st path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t pm1_30                : 16; /**< [2214:2199] When [NLISTS] = 0x20, it reports the calculated path metric of the 31-st path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t crc_error1_30         : 1;  /**< [2198:2198] When [NLISTS] = 0x20, it reports the result of the CRC check of the 31-st
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_30        : 5;  /**< [2197:2193] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 31-st path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_30                : 16; /**< [2192:2177] When [NLISTS] = 0x20, it reports the calculated path metric of the 31-st path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_30         : 1;  /**< [2176:2176] When [NLISTS] = 0x20, it reports the result of the CRC check of the 31-st
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 34 - Little Endian */
        uint64_t crc_error0_30         : 1;  /**< [2176:2176] When [NLISTS] = 0x20, it reports the result of the CRC check of the 31-st
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_30                : 16; /**< [2192:2177] When [NLISTS] = 0x20, it reports the calculated path metric of the 31-st path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_30        : 5;  /**< [2197:2193] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 31-st path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_30         : 1;  /**< [2198:2198] When [NLISTS] = 0x20, it reports the result of the CRC check of the 31-st
                                                                 path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is
                                                                 set to zero. */
        uint64_t pm1_30                : 16; /**< [2214:2199] When [NLISTS] = 0x20, it reports the calculated path metric of the 31-st path
                                                                 for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_30        : 5;  /**< [2219:2215] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 31-st path for the 2nd CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. */
        uint64_t reserved_2220_2239    : 20;
#endif /* Word 34 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 35 - Big Endian */
        uint64_t reserved_2284_2303    : 20;
        uint64_t nfpc_error1_31        : 5;  /**< [2283:2279] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 32-nd path for the second CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. When [NLISTS] = 0x10, this
                                                                 field is set to zero. */
        uint64_t pm1_31                : 16; /**< [2278:2263] When [NLISTS] = 0x20, it reports the calculated path metric of the 32-nd path
                                                                 for the second CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set
                                                                 to zero. When [NLISTS] = 0x10, this field is set to
                                                                 zero. */
        uint64_t crc_error1_31         : 1;  /**< [2262:2262] When [NLISTS] = 0x20, it reports the result of the CRC check of the 32-nd
                                                                 path for the second CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field
                                                                 is set to zero. When [NLISTS] = 0x10, this field is
                                                                 set to zero. */
        uint64_t nfpc_error0_31        : 5;  /**< [2261:2257] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 32-nd path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_31                : 16; /**< [2256:2241] When [NLISTS] = 0x20, it reports the calculated path metric of the 32-nd path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error0_31         : 1;  /**< [2240:2240] When [NLISTS] = 0x20, it reports the result of the CRC check of the 32-nd
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
#else /* Word 35 - Little Endian */
        uint64_t crc_error0_31         : 1;  /**< [2240:2240] When [NLISTS] = 0x20, it reports the result of the CRC check of the 32-nd
                                                                 path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t pm0_31                : 16; /**< [2256:2241] When [NLISTS] = 0x20, it reports the calculated path metric of the 32-nd path
                                                                 for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t nfpc_error0_31        : 5;  /**< [2261:2257] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 32-nd path for the first CB. When [NLISTS] = 0x10, this field is set to zero. */
        uint64_t crc_error1_31         : 1;  /**< [2262:2262] When [NLISTS] = 0x20, it reports the result of the CRC check of the 32-nd
                                                                 path for the second CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field
                                                                 is set to zero. When [NLISTS] = 0x10, this field is
                                                                 set to zero. */
        uint64_t pm1_31                : 16; /**< [2278:2263] When [NLISTS] = 0x20, it reports the calculated path metric of the 32-nd path
                                                                 for the second CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this field is set
                                                                 to zero. When [NLISTS] = 0x10, this field is set to
                                                                 zero. */
        uint64_t nfpc_error1_31        : 5;  /**< [2283:2279] When [NLISTS] = 0x20, it reports the number of errors in FPC metric of the
                                                                 32-nd path for the second CB. When [NLISTS] = 0x10 or PDEC_TASK_CFG_S[NUM_CBS] = 0x1, this
                                                                 field is set to zero. When [NLISTS] = 0x10, this
                                                                 field is set to zero. */
        uint64_t reserved_2284_2303    : 20;
#endif /* Word 35 - End */
    } s;
    /* struct cavm_pdec_report_s_s cn; */
};

/**
 * Structure pdec_task_cfg_s
 *
 * PDEC Task Configuration Structure
 * This structure specifies the configuration for each PDEC task.
 */
union cavm_pdec_task_cfg_s
{
    uint64_t u[9];
    struct cavm_pdec_task_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t npc_wm                : 2;  /**< [ 62: 61] Number of parity check bits with minimum row weight.

                                                                 _ if 0xC \<= [K_SIZE] \<= 0x13 : [NPC_WM] must be in {0x0,0x1}.

                                                                 _ if 0x14 \<= [K_SIZE] : [NPC_WM] must be 0x0. */
        uint64_t npc                   : 3;  /**< [ 60: 58] Number of parity check bits.

                                                                 _ if 0xC \<= [K_SIZE] \<= 0x13, [NPC] must be in {0x0,0x1,0x2,0x3}.

                                                                 _ if 0x14 \<= [K_SIZE] : [NPC] must be 0x0. */
        uint64_t k_size                : 12; /**< [ 57: 46] Payload block size including CRC for one CB. Range [0x12, 0x400].

                                                                 The length of the decoded stream is:

                                                                 _ ([K_SIZE] - [CRC_LEN]) * [NUM_CBS] - [NUM_FILLERS] */
        uint64_t reserved_45           : 1;
        uint64_t num_cbs               : 4;  /**< [ 44: 41] Number of CBs after CB segmentation. Valid range is {0x1,0x2}. */
        uint64_t list_size             : 1;  /**< [ 40: 40] List size to be used in list decoding in this task:
                                                                 0 = List size is 0x10.
                                                                 1 = List size is 0x20. */
        uint64_t llr_conv_lvl          : 3;  /**< [ 39: 37] Specifies the number of LSB bits to be truncated when converting the quantization
                                                                 width from 12 to 6. Must be in the range 0x0 to 0x6.

                                                                 Example:

                                                                 _ [LLR_CONV_LVL] = 0x0: takes the 6 LSBs with saturation.

                                                                 _ [LLR_CONV_LVL] = 0x6: takes the 6 MSBs with rounding. */
        uint64_t llr_sign_format       : 1;  /**< [ 36: 36] LLR sign format.
                                                                 0x0 = Zero sign bit indicates positive LLR.
                                                                 0x1 = One sign bit indicates positive LLR. */
        uint64_t mod_order             : 4;  /**< [ 35: 32] Modulation order:
                                                                 0x1 = BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16-QAM.
                                                                 0x6 = 64-QAM.
                                                                 0x8 = 256-QAM.
                                                                 0xA = 1024-QAM.
                                                                 Other values = Reserved. */
        uint64_t llr_offset            : 16; /**< [ 31: 16] It is possible that the first LLR associated to this task is not word-aligned.
                                                                 [LLR_OFFSET] indicates the offset of the first LLR associated with this task.
                                                                 The preprocessing block drops the first [LLR_OFFSET] LLRs. */
        uint64_t task_id               : 16; /**< [ 15:  0] Index associated with this decoding task. Its value will be relayed in
                                                                 the PDEC_REPORT_S and can be used for debugging purposes. */
#else /* Word 0 - Little Endian */
        uint64_t task_id               : 16; /**< [ 15:  0] Index associated with this decoding task. Its value will be relayed in
                                                                 the PDEC_REPORT_S and can be used for debugging purposes. */
        uint64_t llr_offset            : 16; /**< [ 31: 16] It is possible that the first LLR associated to this task is not word-aligned.
                                                                 [LLR_OFFSET] indicates the offset of the first LLR associated with this task.
                                                                 The preprocessing block drops the first [LLR_OFFSET] LLRs. */
        uint64_t mod_order             : 4;  /**< [ 35: 32] Modulation order:
                                                                 0x1 = BPSK.
                                                                 0x2 = QPSK.
                                                                 0x4 = 16-QAM.
                                                                 0x6 = 64-QAM.
                                                                 0x8 = 256-QAM.
                                                                 0xA = 1024-QAM.
                                                                 Other values = Reserved. */
        uint64_t llr_sign_format       : 1;  /**< [ 36: 36] LLR sign format.
                                                                 0x0 = Zero sign bit indicates positive LLR.
                                                                 0x1 = One sign bit indicates positive LLR. */
        uint64_t llr_conv_lvl          : 3;  /**< [ 39: 37] Specifies the number of LSB bits to be truncated when converting the quantization
                                                                 width from 12 to 6. Must be in the range 0x0 to 0x6.

                                                                 Example:

                                                                 _ [LLR_CONV_LVL] = 0x0: takes the 6 LSBs with saturation.

                                                                 _ [LLR_CONV_LVL] = 0x6: takes the 6 MSBs with rounding. */
        uint64_t list_size             : 1;  /**< [ 40: 40] List size to be used in list decoding in this task:
                                                                 0 = List size is 0x10.
                                                                 1 = List size is 0x20. */
        uint64_t num_cbs               : 4;  /**< [ 44: 41] Number of CBs after CB segmentation. Valid range is {0x1,0x2}. */
        uint64_t reserved_45           : 1;
        uint64_t k_size                : 12; /**< [ 57: 46] Payload block size including CRC for one CB. Range [0x12, 0x400].

                                                                 The length of the decoded stream is:

                                                                 _ ([K_SIZE] - [CRC_LEN]) * [NUM_CBS] - [NUM_FILLERS] */
        uint64_t npc                   : 3;  /**< [ 60: 58] Number of parity check bits.

                                                                 _ if 0xC \<= [K_SIZE] \<= 0x13, [NPC] must be in {0x0,0x1,0x2,0x3}.

                                                                 _ if 0x14 \<= [K_SIZE] : [NPC] must be 0x0. */
        uint64_t npc_wm                : 2;  /**< [ 62: 61] Number of parity check bits with minimum row weight.

                                                                 _ if 0xC \<= [K_SIZE] \<= 0x13 : [NPC_WM] must be in {0x0,0x1}.

                                                                 _ if 0x14 \<= [K_SIZE] : [NPC_WM] must be 0x0. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_123_127      : 5;
        uint64_t crc_trials            : 6;  /**< [122:117] Number of codeword candidates that are tested by the CRC checker to select the output codeword.
                                                                 Must be less than or equal to the list size selected by [LIST_SIZE].

                                                                 When [CRC_TRIALS] = 0x0, the codeword with the minimum metric is released.

                                                                 When [CRC_TRIALS] \> 0x0, the [CRC_TRIALS] codewords with minimum metric are
                                                                 passed through the CRC checker. The codeword that passes the CRC with minimal
                                                                 metric is released. */
        uint64_t reenc_qm_with_crc     : 1;  /**< [116:116] Output CRC within re-encoded data.
                                                                 0 = No CRC addition.
                                                                 1 = Add 1-bit CB CRC result to each set of [MOD_ORDER] bits of re-encoded output.

                                                                 This feature can be enabled only when [SYMB_ALIGNED] = 0x0. */
        uint64_t nfpc                  : 5;  /**< [115:111] Number of frozen bits decoded as info bits for FPC-based metric. */
        uint64_t symb_aligned          : 2;  /**< [110:109] Alignment mode.

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
        uint64_t reenc_data_order      : 3;  /**< [108:106] LSB bit:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Two MSB bits:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2. */
        uint64_t enable_reenc          : 1;  /**< [105:105] Enable re-encoding:
                                                                 0 = re-encoding is bypassed.
                                                                 1 = re-encoding is enabled. */
        uint64_t output_data_order     : 3;  /**< [104:102] LSB bit:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Two MSB bits:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2. */
        uint64_t num_padding           : 3;  /**< [101: 99] Number of padding LLRs that are present in the received input stream.
                                                                 [NUM_PADDING] bits from the end of the input stream are ignored. */
        uint64_t num_fillers           : 3;  /**< [ 98: 96] The number of filler bits to be removed after decoding.

                                                                 When [NUM_CBS] = 0x1, the first [NUM_FILLERS] bits are removed.

                                                                 When [NUM_CBS] = 0x2, the first [NUM_FILLERS] bits of the first CB are removed. */
        uint64_t crc_select            : 2;  /**< [ 95: 94] Select CRC polynomial.
                                                                 0x0 = use polynomial gCRC6.
                                                                 0x1 = use polynomial gCRC11.
                                                                 0x2 - 0x3 = Reserved.

                                                                 The same CRC polynomial is used for both CBs when [NUM_CBS] = 0x2. */
        uint64_t reserved_80_93        : 14;
        uint64_t bypass_intlv          : 1;  /**< [ 79: 79] Bypass de-interleaving.
                                                                 0: do not bypass.
                                                                 1: bypass triangular de-interleaving.

                                                                 This field is only applicable when [NUM_CBS] = 0x1. */
        uint64_t bypass_rm             : 1;  /**< [ 78: 78] Switch for bypassing de-rate matching.
                                                                 0 = do not bypass rate dematching.
                                                                 1 = bypass rate dematching.

                                                                 This field is only applicable when [NUM_CBS] = 0x1. */
        uint64_t e_size                : 14; /**< [ 77: 64] Number of input LLRs for one CB. Must be either 0x0 or in the range [0x12, 0x2000].

                                                                 When [E_SIZE] = 0x0, PDEC only generates monitoring words with [CRC_ERRORn] = 0x1.

                                                                 [E_SIZE] must be always \>= [K_SIZE] to ensure code rate \>= 1.0

                                                                 The length of the input stream is G = [NUM_CBS] x [E_SIZE] + [NUM_PADDING],
                                                                 where G corresponds to the parameter G in 38.212.

                                                                 When [BYPASS_RM] = 1, the length of the input stream is the size of the mother
                                                                 code described in Section 5.3.1 in 38.212. */
#else /* Word 1 - Little Endian */
        uint64_t e_size                : 14; /**< [ 77: 64] Number of input LLRs for one CB. Must be either 0x0 or in the range [0x12, 0x2000].

                                                                 When [E_SIZE] = 0x0, PDEC only generates monitoring words with [CRC_ERRORn] = 0x1.

                                                                 [E_SIZE] must be always \>= [K_SIZE] to ensure code rate \>= 1.0

                                                                 The length of the input stream is G = [NUM_CBS] x [E_SIZE] + [NUM_PADDING],
                                                                 where G corresponds to the parameter G in 38.212.

                                                                 When [BYPASS_RM] = 1, the length of the input stream is the size of the mother
                                                                 code described in Section 5.3.1 in 38.212. */
        uint64_t bypass_rm             : 1;  /**< [ 78: 78] Switch for bypassing de-rate matching.
                                                                 0 = do not bypass rate dematching.
                                                                 1 = bypass rate dematching.

                                                                 This field is only applicable when [NUM_CBS] = 0x1. */
        uint64_t bypass_intlv          : 1;  /**< [ 79: 79] Bypass de-interleaving.
                                                                 0: do not bypass.
                                                                 1: bypass triangular de-interleaving.

                                                                 This field is only applicable when [NUM_CBS] = 0x1. */
        uint64_t reserved_80_93        : 14;
        uint64_t crc_select            : 2;  /**< [ 95: 94] Select CRC polynomial.
                                                                 0x0 = use polynomial gCRC6.
                                                                 0x1 = use polynomial gCRC11.
                                                                 0x2 - 0x3 = Reserved.

                                                                 The same CRC polynomial is used for both CBs when [NUM_CBS] = 0x2. */
        uint64_t num_fillers           : 3;  /**< [ 98: 96] The number of filler bits to be removed after decoding.

                                                                 When [NUM_CBS] = 0x1, the first [NUM_FILLERS] bits are removed.

                                                                 When [NUM_CBS] = 0x2, the first [NUM_FILLERS] bits of the first CB are removed. */
        uint64_t num_padding           : 3;  /**< [101: 99] Number of padding LLRs that are present in the received input stream.
                                                                 [NUM_PADDING] bits from the end of the input stream are ignored. */
        uint64_t output_data_order     : 3;  /**< [104:102] LSB bit:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Two MSB bits:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2. */
        uint64_t enable_reenc          : 1;  /**< [105:105] Enable re-encoding:
                                                                 0 = re-encoding is bypassed.
                                                                 1 = re-encoding is enabled. */
        uint64_t reenc_data_order      : 3;  /**< [108:106] LSB bit:
                                                                 0 = DATA_BIT_MSB_FIRST.
                                                                 1 = DATA_BIT_LSB_FIRST.

                                                                 Two MSB bits:
                                                                 0x0 = DATA_BYTE_ORDER_MODE_0.
                                                                 0x1 = DATA_BYTE_ORDER_MODE_1.
                                                                 0x2 = DATA_BYTE_ORDER_MODE_2. */
        uint64_t symb_aligned          : 2;  /**< [110:109] Alignment mode.

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
        uint64_t nfpc                  : 5;  /**< [115:111] Number of frozen bits decoded as info bits for FPC-based metric. */
        uint64_t reenc_qm_with_crc     : 1;  /**< [116:116] Output CRC within re-encoded data.
                                                                 0 = No CRC addition.
                                                                 1 = Add 1-bit CB CRC result to each set of [MOD_ORDER] bits of re-encoded output.

                                                                 This feature can be enabled only when [SYMB_ALIGNED] = 0x0. */
        uint64_t crc_trials            : 6;  /**< [122:117] Number of codeword candidates that are tested by the CRC checker to select the output codeword.
                                                                 Must be less than or equal to the list size selected by [LIST_SIZE].

                                                                 When [CRC_TRIALS] = 0x0, the codeword with the minimum metric is released.

                                                                 When [CRC_TRIALS] \> 0x0, the [CRC_TRIALS] codewords with minimum metric are
                                                                 passed through the CRC checker. The codeword that passes the CRC with minimal
                                                                 metric is released. */
        uint64_t reserved_123_127      : 5;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_152_191      : 40;
        uint64_t tb_tx_bit_size        : 24; /**< [151:128] Number of LLRs to be sent to the decoder core. This field needs to be the same as [E_SIZE]. */
#else /* Word 2 - Little Endian */
        uint64_t tb_tx_bit_size        : 24; /**< [151:128] Number of LLRs to be sent to the decoder core. This field needs to be the same as [E_SIZE]. */
        uint64_t reserved_152_191      : 40;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_254_255      : 2;
        uint64_t preproc_p0_csi2_len2  : 19; /**< [253:235] Size of burst 2, CSI2 part0. Must be in the range [0x0, 0x671FF]. */
        uint64_t preproc_p0_csi2_len1  : 19; /**< [234:216] Size of burst 1, CSI2 part0. Must be in the range [0x0, 0x671FF]. */
        uint64_t preproc_p0_csi2_len0  : 19; /**< [215:197] Size of burst 0, CSI2 part0. Must be in the range [0x0, 0x671FF]. */
        uint64_t reserved_194_196      : 3;
        uint64_t preproc_enable        : 1;  /**< [193:193] LLR pre-processing enable.
                                                                 0 = disable pre-processor.
                                                                 1 = enable pre-processor. */
        uint64_t preproc_mode          : 1;  /**< [192:192] LLR pre-processing block mode.
                                                                 0 = Keep CSI2 LLRs.
                                                                 1 = Keep data LLRs. */
#else /* Word 3 - Little Endian */
        uint64_t preproc_mode          : 1;  /**< [192:192] LLR pre-processing block mode.
                                                                 0 = Keep CSI2 LLRs.
                                                                 1 = Keep data LLRs. */
        uint64_t preproc_enable        : 1;  /**< [193:193] LLR pre-processing enable.
                                                                 0 = disable pre-processor.
                                                                 1 = enable pre-processor. */
        uint64_t reserved_194_196      : 3;
        uint64_t preproc_p0_csi2_len0  : 19; /**< [215:197] Size of burst 0, CSI2 part0. Must be in the range [0x0, 0x671FF]. */
        uint64_t preproc_p0_csi2_len1  : 19; /**< [234:216] Size of burst 1, CSI2 part0. Must be in the range [0x0, 0x671FF]. */
        uint64_t preproc_p0_csi2_len2  : 19; /**< [253:235] Size of burst 2, CSI2 part0. Must be in the range [0x0, 0x671FF]. */
        uint64_t reserved_254_255      : 2;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_319          : 1;
        uint64_t preproc_csi2_repeat_burst_size : 6;/**< [318:313] Burst size of CSI2 LLRs in each repeat of both part 0 and part 1.

                                                                 Must be in the range {0x1-0x4,0x6,0x8,0xA,0xC,0x10,0x12,0x14,0x18,0x1E,0x20,0x28} */
        uint64_t preproc_p1_csi2_len2  : 19; /**< [312:294] Size of burst 2, CSI2 part1. Must be in the range [0x0, 0x671FF]. */
        uint64_t preproc_p1_csi2_len1  : 19; /**< [293:275] Size of burst 1, CSI2 part1. Must be in the range [0x0, 0x671FF]. */
        uint64_t preproc_p1_csi2_len0  : 19; /**< [274:256] Size of burst 0, CSI2 part1. Must be in the range [0x0, 0x671FF]. */
#else /* Word 4 - Little Endian */
        uint64_t preproc_p1_csi2_len0  : 19; /**< [274:256] Size of burst 0, CSI2 part1. Must be in the range [0x0, 0x671FF]. */
        uint64_t preproc_p1_csi2_len1  : 19; /**< [293:275] Size of burst 1, CSI2 part1. Must be in the range [0x0, 0x671FF]. */
        uint64_t preproc_p1_csi2_len2  : 19; /**< [312:294] Size of burst 2, CSI2 part1. Must be in the range [0x0, 0x671FF]. */
        uint64_t preproc_csi2_repeat_burst_size : 6;/**< [318:313] Burst size of CSI2 LLRs in each repeat of both part 0 and part 1.

                                                                 Must be in the range {0x1-0x4,0x6,0x8,0xA,0xC,0x10,0x12,0x14,0x18,0x1E,0x20,0x28} */
        uint64_t reserved_319          : 1;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_382_383      : 2;
        uint64_t preproc_p0_num_repeat : 11; /**< [381:371] Number of periodic repetitions in part 0. */
        uint64_t preproc_p1_data_len0  : 17; /**< [370:354] Size of burst 0, data part 1. Must be in the range [0x0, 0x19C7F]. */
        uint64_t preproc_p0_data_len1  : 17; /**< [353:337] Size of burst 1, data part 0. Must be in the range [0x0, 0x19C7F]. */
        uint64_t preproc_p0_data_len0  : 17; /**< [336:320] Size of burst 0, data part 0. Must be in the range [0x0, 0x19C7F]. */
#else /* Word 5 - Little Endian */
        uint64_t preproc_p0_data_len0  : 17; /**< [336:320] Size of burst 0, data part 0. Must be in the range [0x0, 0x19C7F]. */
        uint64_t preproc_p0_data_len1  : 17; /**< [353:337] Size of burst 1, data part 0. Must be in the range [0x0, 0x19C7F]. */
        uint64_t preproc_p1_data_len0  : 17; /**< [370:354] Size of burst 0, data part 1. Must be in the range [0x0, 0x19C7F]. */
        uint64_t preproc_p0_num_repeat : 11; /**< [381:371] Number of periodic repetitions in part 0. */
        uint64_t reserved_382_383      : 2;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_444_447      : 4;
        uint64_t preproc_p1_num_repeat : 11; /**< [443:433] Number of periodic repetitions in part 1. */
        uint64_t preproc_p1_csi2_repeat_period : 16;/**< [432:417] Periodicity of Repeated CSI2 LLRs followed by part 1 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents the number of LLRs in each period. Must be in the range [0x0, 0xCE40]. */
        uint64_t preproc_p0_csi2_repeat_period : 16;/**< [416:401] Periodicity of repeated CSI2 LLRs followed by part 0 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents the number of LLRs in each period. Must be in the range [0x0, 0xCE40]. */
        uint64_t preproc_p1_data_len1  : 17; /**< [400:384] Size of burst 1, data part 1. Must be in the range [0x0, 0x19C7F]. */
#else /* Word 6 - Little Endian */
        uint64_t preproc_p1_data_len1  : 17; /**< [400:384] Size of burst 1, data part 1. Must be in the range [0x0, 0x19C7F]. */
        uint64_t preproc_p0_csi2_repeat_period : 16;/**< [416:401] Periodicity of repeated CSI2 LLRs followed by part 0 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents the number of LLRs in each period. Must be in the range [0x0, 0xCE40]. */
        uint64_t preproc_p1_csi2_repeat_period : 16;/**< [432:417] Periodicity of Repeated CSI2 LLRs followed by part 1 (3 bursts of CSI2 and 2 bursts of data)
                                                                 LLRs. Represents the number of LLRs in each period. Must be in the range [0x0, 0xCE40]. */
        uint64_t preproc_p1_num_repeat : 11; /**< [443:433] Number of periodic repetitions in part 1. */
        uint64_t reserved_444_447      : 4;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t preproc_num_rd_dma_words_p1 : 32;/**< [511:480] Number of read DMA words for part 1. Must satisfy the constraint:

                                                                 _ [PREPROC_NUM_RD_DMA_WORDS_P0] + [PREPROC_NUM_RD_DMA_WORDS_P1] = [NUM_RD_DMA_WORDS]

                                                                 Must be in the range [0x0, 0x2998]. */
        uint64_t preproc_num_rd_dma_words_p0 : 32;/**< [479:448] Number of read DMA words for part 0. Must satisfy the constraint:

                                                                 _ [PREPROC_NUM_RD_DMA_WORDS_P0] + [PREPROC_NUM_RD_DMA_WORDS_P1] = [NUM_RD_DMA_WORDS]

                                                                 Must be in the range [0x0, 0x2998]. */
#else /* Word 7 - Little Endian */
        uint64_t preproc_num_rd_dma_words_p0 : 32;/**< [479:448] Number of read DMA words for part 0. Must satisfy the constraint:

                                                                 _ [PREPROC_NUM_RD_DMA_WORDS_P0] + [PREPROC_NUM_RD_DMA_WORDS_P1] = [NUM_RD_DMA_WORDS]

                                                                 Must be in the range [0x0, 0x2998]. */
        uint64_t preproc_num_rd_dma_words_p1 : 32;/**< [511:480] Number of read DMA words for part 1. Must satisfy the constraint:

                                                                 _ [PREPROC_NUM_RD_DMA_WORDS_P0] + [PREPROC_NUM_RD_DMA_WORDS_P1] = [NUM_RD_DMA_WORDS]

                                                                 Must be in the range [0x0, 0x2998]. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t num_wr1_dma_words     : 16; /**< [575:560] Number of 64-bit words written to Port 1 output DMA.
                                                                 Port 1 is used only when re-encoding is enabled. I.e., [NUM_WR1_DMA_WORDS] must
                                                                 be 0x0 when [ENABLE_REENC] = 0. */
        uint64_t num_wr0_dma_words     : 16; /**< [559:544] Number of 64-bit words written to Port 0 output DMA. */
        uint64_t num_rd_dma_words      : 32; /**< [543:512] Number of 128-bit words read from Port 0 input DMA. */
#else /* Word 8 - Little Endian */
        uint64_t num_rd_dma_words      : 32; /**< [543:512] Number of 128-bit words read from Port 0 input DMA. */
        uint64_t num_wr0_dma_words     : 16; /**< [559:544] Number of 64-bit words written to Port 0 output DMA. */
        uint64_t num_wr1_dma_words     : 16; /**< [575:560] Number of 64-bit words written to Port 1 output DMA.
                                                                 Port 1 is used only when re-encoding is enabled. I.e., [NUM_WR1_DMA_WORDS] must
                                                                 be 0x0 when [ENABLE_REENC] = 0. */
#endif /* Word 8 - End */
    } s;
    /* struct cavm_pdec_task_cfg_s_s cn; */
};

/**
 * Register (RSL) pdec#_control
 *
 * PDEC Control Register
 */
union cavm_pdecx_control
{
    uint64_t u;
    struct cavm_pdecx_control_s
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
    /* struct cavm_pdecx_control_s cn; */
};
typedef union cavm_pdecx_control cavm_pdecx_control_t;

static inline uint64_t CAVM_PDECX_CONTROL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_CONTROL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043580000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_CONTROL", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_CONTROL(a) cavm_pdecx_control_t
#define bustype_CAVM_PDECX_CONTROL(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_CONTROL(a) "PDECX_CONTROL"
#define busnum_CAVM_PDECX_CONTROL(a) (a)
#define arguments_CAVM_PDECX_CONTROL(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_eco
 *
 * INTERNAL: PDEC ECO Register
 */
union cavm_pdecx_eco
{
    uint64_t u;
    struct cavm_pdecx_eco_s
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
    /* struct cavm_pdecx_eco_s cn; */
};
typedef union cavm_pdecx_eco cavm_pdecx_eco_t;

static inline uint64_t CAVM_PDECX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_ECO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043580008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_ECO", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_ECO(a) cavm_pdecx_eco_t
#define bustype_CAVM_PDECX_ECO(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_ECO(a) "PDECX_ECO"
#define busnum_CAVM_PDECX_ECO(a) (a)
#define arguments_CAVM_PDECX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_error_enable0
 *
 * PDEC Error Enable 0 Register
 * This register enables error reporting for read overflow/underflow errors.
 */
union cavm_pdecx_error_enable0
{
    uint64_t u;
    struct cavm_pdecx_error_enable0_s
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
    /* struct cavm_pdecx_error_enable0_s cn; */
};
typedef union cavm_pdecx_error_enable0 cavm_pdecx_error_enable0_t;

static inline uint64_t CAVM_PDECX_ERROR_ENABLE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_ERROR_ENABLE0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043580040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_ERROR_ENABLE0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_ERROR_ENABLE0(a) cavm_pdecx_error_enable0_t
#define bustype_CAVM_PDECX_ERROR_ENABLE0(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_ERROR_ENABLE0(a) "PDECX_ERROR_ENABLE0"
#define busnum_CAVM_PDECX_ERROR_ENABLE0(a) (a)
#define arguments_CAVM_PDECX_ERROR_ENABLE0(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_error_enable1
 *
 * PDEC Error Enable 1 Register
 * This register enables error reporting of ECC errors.
 */
union cavm_pdecx_error_enable1
{
    uint64_t u;
    struct cavm_pdecx_error_enable1_s
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
    /* struct cavm_pdecx_error_enable1_s cn; */
};
typedef union cavm_pdecx_error_enable1 cavm_pdecx_error_enable1_t;

static inline uint64_t CAVM_PDECX_ERROR_ENABLE1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_ERROR_ENABLE1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043580048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_ERROR_ENABLE1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_ERROR_ENABLE1(a) cavm_pdecx_error_enable1_t
#define bustype_CAVM_PDECX_ERROR_ENABLE1(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_ERROR_ENABLE1(a) "PDECX_ERROR_ENABLE1"
#define busnum_CAVM_PDECX_ERROR_ENABLE1(a) (a)
#define arguments_CAVM_PDECX_ERROR_ENABLE1(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_error_source0
 *
 * PDEC Error Source 0 Register
 * This register indicates the source of read overflow/underflow errors.
 */
union cavm_pdecx_error_source0
{
    uint64_t u;
    struct cavm_pdecx_error_source0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t rp0_jid               : 16; /**< [ 31: 16](RO/H) Job ID of the job which reported the overflow/underflow error on read
                                                                 port 0. */
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
                                                                 port 0. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_error_source0_s cn; */
};
typedef union cavm_pdecx_error_source0 cavm_pdecx_error_source0_t;

static inline uint64_t CAVM_PDECX_ERROR_SOURCE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_ERROR_SOURCE0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043580030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_ERROR_SOURCE0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_ERROR_SOURCE0(a) cavm_pdecx_error_source0_t
#define bustype_CAVM_PDECX_ERROR_SOURCE0(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_ERROR_SOURCE0(a) "PDECX_ERROR_SOURCE0"
#define busnum_CAVM_PDECX_ERROR_SOURCE0(a) (a)
#define arguments_CAVM_PDECX_ERROR_SOURCE0(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_error_source1
 *
 * PDEC Error Source 1 Register
 * This register reports the source of ECC errors.
 */
union cavm_pdecx_error_source1
{
    uint64_t u;
    struct cavm_pdecx_error_source1_s
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
    /* struct cavm_pdecx_error_source1_s cn; */
};
typedef union cavm_pdecx_error_source1 cavm_pdecx_error_source1_t;

static inline uint64_t CAVM_PDECX_ERROR_SOURCE1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_ERROR_SOURCE1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043580038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_ERROR_SOURCE1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_ERROR_SOURCE1(a) cavm_pdecx_error_source1_t
#define bustype_CAVM_PDECX_ERROR_SOURCE1(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_ERROR_SOURCE1(a) "PDECX_ERROR_SOURCE1"
#define busnum_CAVM_PDECX_ERROR_SOURCE1(a) (a)
#define arguments_CAVM_PDECX_ERROR_SOURCE1(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_hab_jcfg0_ram#_data
 *
 * PDEC HAB Job Configuration 0 RAM Register
 * This register range stores the job configuration for slot 0.
 */
union cavm_pdecx_hab_jcfg0_ramx_data
{
    uint64_t u;
    struct cavm_pdecx_hab_jcfg0_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG0 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG0 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_hab_jcfg0_ramx_data_s cn; */
};
typedef union cavm_pdecx_hab_jcfg0_ramx_data cavm_pdecx_hab_jcfg0_ramx_data_t;

static inline uint64_t CAVM_PDECX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_HAB_JCFG0_RAMX_DATA(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=149)))
        return 0x87e043582000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    __cavm_csr_fatal("PDECX_HAB_JCFG0_RAMX_DATA", 2, a, b, 0, 0);
}

#define typedef_CAVM_PDECX_HAB_JCFG0_RAMX_DATA(a,b) cavm_pdecx_hab_jcfg0_ramx_data_t
#define bustype_CAVM_PDECX_HAB_JCFG0_RAMX_DATA(a,b) CSR_TYPE_RSL
#define basename_CAVM_PDECX_HAB_JCFG0_RAMX_DATA(a,b) "PDECX_HAB_JCFG0_RAMX_DATA"
#define busnum_CAVM_PDECX_HAB_JCFG0_RAMX_DATA(a,b) (a)
#define arguments_CAVM_PDECX_HAB_JCFG0_RAMX_DATA(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pdec#_hab_jcfg1_ram#_data
 *
 * PDEC HAB Job Configuration 1 RAM Register
 * This register range stores the job configuration for slot 1.
 */
union cavm_pdecx_hab_jcfg1_ramx_data
{
    uint64_t u;
    struct cavm_pdecx_hab_jcfg1_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG1 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG1 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_hab_jcfg1_ramx_data_s cn; */
};
typedef union cavm_pdecx_hab_jcfg1_ramx_data cavm_pdecx_hab_jcfg1_ramx_data_t;

static inline uint64_t CAVM_PDECX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_HAB_JCFG1_RAMX_DATA(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=149)))
        return 0x87e043584000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    __cavm_csr_fatal("PDECX_HAB_JCFG1_RAMX_DATA", 2, a, b, 0, 0);
}

#define typedef_CAVM_PDECX_HAB_JCFG1_RAMX_DATA(a,b) cavm_pdecx_hab_jcfg1_ramx_data_t
#define bustype_CAVM_PDECX_HAB_JCFG1_RAMX_DATA(a,b) CSR_TYPE_RSL
#define basename_CAVM_PDECX_HAB_JCFG1_RAMX_DATA(a,b) "PDECX_HAB_JCFG1_RAMX_DATA"
#define busnum_CAVM_PDECX_HAB_JCFG1_RAMX_DATA(a,b) (a)
#define arguments_CAVM_PDECX_HAB_JCFG1_RAMX_DATA(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pdec#_hab_jcfg2_ram#_data
 *
 * PDEC HAB Job Configuration 2 RAM Register
 * This register range stores the job configuration for slot 2.
 */
union cavm_pdecx_hab_jcfg2_ramx_data
{
    uint64_t u;
    struct cavm_pdecx_hab_jcfg2_ramx_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG2 RAM CSRs */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) JCFG2 RAM CSRs */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_hab_jcfg2_ramx_data_s cn; */
};
typedef union cavm_pdecx_hab_jcfg2_ramx_data cavm_pdecx_hab_jcfg2_ramx_data_t;

static inline uint64_t CAVM_PDECX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_HAB_JCFG2_RAMX_DATA(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=149)))
        return 0x87e043586000ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0xff);
    __cavm_csr_fatal("PDECX_HAB_JCFG2_RAMX_DATA", 2, a, b, 0, 0);
}

#define typedef_CAVM_PDECX_HAB_JCFG2_RAMX_DATA(a,b) cavm_pdecx_hab_jcfg2_ramx_data_t
#define bustype_CAVM_PDECX_HAB_JCFG2_RAMX_DATA(a,b) CSR_TYPE_RSL
#define basename_CAVM_PDECX_HAB_JCFG2_RAMX_DATA(a,b) "PDECX_HAB_JCFG2_RAMX_DATA"
#define busnum_CAVM_PDECX_HAB_JCFG2_RAMX_DATA(a,b) (a)
#define arguments_CAVM_PDECX_HAB_JCFG2_RAMX_DATA(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pdec#_scratch
 *
 * INTERNAL: Scratch Register
 *
 * Scratch register.
 */
union cavm_pdecx_scratch
{
    uint64_t u;
    struct cavm_pdecx_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_scratch_s cn; */
};
typedef union cavm_pdecx_scratch cavm_pdecx_scratch_t;

static inline uint64_t CAVM_PDECX_SCRATCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_SCRATCH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043580080ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_SCRATCH", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_SCRATCH(a) cavm_pdecx_scratch_t
#define bustype_CAVM_PDECX_SCRATCH(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_SCRATCH(a) "PDECX_SCRATCH"
#define busnum_CAVM_PDECX_SCRATCH(a) (a)
#define arguments_CAVM_PDECX_SCRATCH(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_status
 *
 * PDEC Status Register
 */
union cavm_pdecx_status
{
    uint64_t u;
    struct cavm_pdecx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the PDEC HAB is ready to receive the next job. */
        uint64_t reserved_3            : 1;
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, the PDEC HAB is ready to receive the next job. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_status_s cn; */
};
typedef union cavm_pdecx_status cavm_pdecx_status_t;

static inline uint64_t CAVM_PDECX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043580018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_STATUS", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_STATUS(a) cavm_pdecx_status_t
#define bustype_CAVM_PDECX_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_STATUS(a) "PDECX_STATUS"
#define busnum_CAVM_PDECX_STATUS(a) (a)
#define arguments_CAVM_PDECX_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_tc_config_err_flags_reg
 *
 * PDEC Task Configuration Error Flags Register
 * This register reports task configuration errors that occur when a
 * specified parameter value is outside the acceptable range.
 */
union cavm_pdecx_tc_config_err_flags_reg
{
    uint64_t u;
    struct cavm_pdecx_tc_config_err_flags_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_63        : 41;
        uint64_t error_output_size     : 1;  /**< [ 22: 22](RO/H) Output is empty since PDEC_TASK_CFG_S[K_SIZE] - CRC_LENGTH - PDEC_TASK_CFG_S[NUM_FILLERS] = 0. */
        uint64_t invalid_crc_trials    : 1;  /**< [ 21: 21](RO/H) Invalid PDEC_TASK_CFG_S[CRC_TRIALS] value. */
        uint64_t invalid_reenc_qm_with_crc : 1;/**< [ 20: 20](RO/H) Invalid PDEC_TASK_CFG_S[REENC_QM_WITH_CRC] value. */
        uint64_t invalid_nfpc          : 1;  /**< [ 19: 19](RO/H) Invalid PDEC_TASK_CFG_S[NFPC] value. */
        uint64_t invalid_symb_aligned  : 1;  /**< [ 18: 18](RO/H) Invalid PDEC_TASK_CFG_S[SYMB_ALIGNED] value. */
        uint64_t invalid_reenc_data_order : 1;/**< [ 17: 17](RO/H) Invalid PDEC_TASK_CFG_S[REENC_DATA_ORDER] value. */
        uint64_t invalid_enable_reenc  : 1;  /**< [ 16: 16](RO/H) Invalid PDEC_TASK_CFG_S[ENABLE_REENC] value. */
        uint64_t invalid_output_data_order : 1;/**< [ 15: 15](RO/H) Invalid PDEC_TASK_CFG_S[OUTPUT_DATA_ORDER] value. */
        uint64_t invalid_bypass_intlv  : 1;  /**< [ 14: 14](RO/H) Invalid PDEC_TASK_CFG_S[BYPASS_INTLV] value. */
        uint64_t invalid_bypass_rm     : 1;  /**< [ 13: 13](RO/H) Invalid PDEC_TASK_CFG_S[BYPASS_RM] value. */
        uint64_t invalid_npc_wm        : 1;  /**< [ 12: 12](RO/H) Invalid PDEC_TASK_CFG_S[NPC_WM] value. */
        uint64_t invalid_npc           : 1;  /**< [ 11: 11](RO/H) Invalid PDEC_TASK_CFG_S[NPC] value. */
        uint64_t invalid_num_padding   : 1;  /**< [ 10: 10](RO/H) Invalid PDEC_TASK_CFG_S[NUM_PADDING] value. */
        uint64_t invalid_num_fillers   : 1;  /**< [  9:  9](RO/H) Invalid PDEC_TASK_CFG_S[NUM_FILLERS] value. */
        uint64_t invalid_crc_select    : 1;  /**< [  8:  8](RO/H) Invalid PDEC_TASK_CFG_S[CRC_SELECT] value. */
        uint64_t invalid_e_size        : 1;  /**< [  7:  7](RO/H) Invalid PDEC_TASK_CFG_S[E_SIZE] value. */
        uint64_t invalid_k_size        : 1;  /**< [  6:  6](RO/H) Invalid PDEC_TASK_CFG_S[K_SIZE] value. */
        uint64_t invalid_num_cbs       : 1;  /**< [  5:  5](RO/H) Invalid PDEC_TASK_CFG_S[NUM_CBS] value. */
        uint64_t invalid_llr_conv_lvl  : 1;  /**< [  4:  4](RO/H) Invalid PDEC_TASK_CFG_S[LLR_CONV_LVL] value. */
        uint64_t invalid_llr_sign_format : 1;/**< [  3:  3](RO/H) Invalid PDEC_TASK_CFG_S[LLR_SIGN_FORMAT] value. */
        uint64_t invalid_mod_order     : 1;  /**< [  2:  2](RO/H) Invalid PDEC_TASK_CFG_S[MOD_ORDER] value. */
        uint64_t invalid_list_size     : 1;  /**< [  1:  1](RO/H) Invalid PDEC_TASK_CFG_S[LIST_SIZE] value. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t invalid_list_size     : 1;  /**< [  1:  1](RO/H) Invalid PDEC_TASK_CFG_S[LIST_SIZE] value. */
        uint64_t invalid_mod_order     : 1;  /**< [  2:  2](RO/H) Invalid PDEC_TASK_CFG_S[MOD_ORDER] value. */
        uint64_t invalid_llr_sign_format : 1;/**< [  3:  3](RO/H) Invalid PDEC_TASK_CFG_S[LLR_SIGN_FORMAT] value. */
        uint64_t invalid_llr_conv_lvl  : 1;  /**< [  4:  4](RO/H) Invalid PDEC_TASK_CFG_S[LLR_CONV_LVL] value. */
        uint64_t invalid_num_cbs       : 1;  /**< [  5:  5](RO/H) Invalid PDEC_TASK_CFG_S[NUM_CBS] value. */
        uint64_t invalid_k_size        : 1;  /**< [  6:  6](RO/H) Invalid PDEC_TASK_CFG_S[K_SIZE] value. */
        uint64_t invalid_e_size        : 1;  /**< [  7:  7](RO/H) Invalid PDEC_TASK_CFG_S[E_SIZE] value. */
        uint64_t invalid_crc_select    : 1;  /**< [  8:  8](RO/H) Invalid PDEC_TASK_CFG_S[CRC_SELECT] value. */
        uint64_t invalid_num_fillers   : 1;  /**< [  9:  9](RO/H) Invalid PDEC_TASK_CFG_S[NUM_FILLERS] value. */
        uint64_t invalid_num_padding   : 1;  /**< [ 10: 10](RO/H) Invalid PDEC_TASK_CFG_S[NUM_PADDING] value. */
        uint64_t invalid_npc           : 1;  /**< [ 11: 11](RO/H) Invalid PDEC_TASK_CFG_S[NPC] value. */
        uint64_t invalid_npc_wm        : 1;  /**< [ 12: 12](RO/H) Invalid PDEC_TASK_CFG_S[NPC_WM] value. */
        uint64_t invalid_bypass_rm     : 1;  /**< [ 13: 13](RO/H) Invalid PDEC_TASK_CFG_S[BYPASS_RM] value. */
        uint64_t invalid_bypass_intlv  : 1;  /**< [ 14: 14](RO/H) Invalid PDEC_TASK_CFG_S[BYPASS_INTLV] value. */
        uint64_t invalid_output_data_order : 1;/**< [ 15: 15](RO/H) Invalid PDEC_TASK_CFG_S[OUTPUT_DATA_ORDER] value. */
        uint64_t invalid_enable_reenc  : 1;  /**< [ 16: 16](RO/H) Invalid PDEC_TASK_CFG_S[ENABLE_REENC] value. */
        uint64_t invalid_reenc_data_order : 1;/**< [ 17: 17](RO/H) Invalid PDEC_TASK_CFG_S[REENC_DATA_ORDER] value. */
        uint64_t invalid_symb_aligned  : 1;  /**< [ 18: 18](RO/H) Invalid PDEC_TASK_CFG_S[SYMB_ALIGNED] value. */
        uint64_t invalid_nfpc          : 1;  /**< [ 19: 19](RO/H) Invalid PDEC_TASK_CFG_S[NFPC] value. */
        uint64_t invalid_reenc_qm_with_crc : 1;/**< [ 20: 20](RO/H) Invalid PDEC_TASK_CFG_S[REENC_QM_WITH_CRC] value. */
        uint64_t invalid_crc_trials    : 1;  /**< [ 21: 21](RO/H) Invalid PDEC_TASK_CFG_S[CRC_TRIALS] value. */
        uint64_t error_output_size     : 1;  /**< [ 22: 22](RO/H) Output is empty since PDEC_TASK_CFG_S[K_SIZE] - CRC_LENGTH - PDEC_TASK_CFG_S[NUM_FILLERS] = 0. */
        uint64_t reserved_23_63        : 41;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_tc_config_err_flags_reg_s cn; */
};
typedef union cavm_pdecx_tc_config_err_flags_reg cavm_pdecx_tc_config_err_flags_reg_t;

static inline uint64_t CAVM_PDECX_TC_CONFIG_ERR_FLAGS_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_TC_CONFIG_ERR_FLAGS_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043581040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_TC_CONFIG_ERR_FLAGS_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_TC_CONFIG_ERR_FLAGS_REG(a) cavm_pdecx_tc_config_err_flags_reg_t
#define bustype_CAVM_PDECX_TC_CONFIG_ERR_FLAGS_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_TC_CONFIG_ERR_FLAGS_REG(a) "PDECX_TC_CONFIG_ERR_FLAGS_REG"
#define busnum_CAVM_PDECX_TC_CONFIG_ERR_FLAGS_REG(a) (a)
#define arguments_CAVM_PDECX_TC_CONFIG_ERR_FLAGS_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_tc_config_reg#
 *
 * INTERNAL: TC Task Config Registers
 *
 * TC task config registers.
 */
union cavm_pdecx_tc_config_regx
{
    uint64_t u;
    struct cavm_pdecx_tc_config_regx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#else /* Word 0 - Little Endian */
        uint64_t entry                 : 64; /**< [ 63:  0](R/W/H) Config bits. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_tc_config_regx_s cn; */
};
typedef union cavm_pdecx_tc_config_regx cavm_pdecx_tc_config_regx_t;

static inline uint64_t CAVM_PDECX_TC_CONFIG_REGX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_TC_CONFIG_REGX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=2)))
        return 0x87e043581400ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x3);
    __cavm_csr_fatal("PDECX_TC_CONFIG_REGX", 2, a, b, 0, 0);
}

#define typedef_CAVM_PDECX_TC_CONFIG_REGX(a,b) cavm_pdecx_tc_config_regx_t
#define bustype_CAVM_PDECX_TC_CONFIG_REGX(a,b) CSR_TYPE_RSL
#define basename_CAVM_PDECX_TC_CONFIG_REGX(a,b) "PDECX_TC_CONFIG_REGX"
#define busnum_CAVM_PDECX_TC_CONFIG_REGX(a,b) (a)
#define arguments_CAVM_PDECX_TC_CONFIG_REGX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pdec#_tc_control_reg
 *
 * PDEC Decoder Control Register
 * This register configures the PDEC internal decoder core.
 */
union cavm_pdecx_tc_control_reg
{
    uint64_t u;
    struct cavm_pdecx_tc_control_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t single_task_chnl_en   : 1;  /**< [  4:  4](R/W) When set to 1, the core will wait until idle before accepting
                                                                 a new task in case of changing channel_mode. (degrades the throughput). */
        uint64_t single_task_phy_en    : 1;  /**< [  3:  3](R/W) When set to 1, the core will wait until idle before accepting
                                                                 a new task with a different PHY_MODE (degrades the throughput). */
        uint64_t single_task_en        : 1;  /**< [  2:  2](R/W) When set to 1, the core will always wait until idle before
                                                                 starting the next task (degrades the throughput). */
        uint64_t cfg_chk_dis           : 1;  /**< [  1:  1](R/W) When set to 1, disables config checks. Tasks with
                                                                 invalid configurations will still be processed. */
        uint64_t clk_gate_dis          : 1;  /**< [  0:  0](R/W) When set to 1, disables clock gating. */
#else /* Word 0 - Little Endian */
        uint64_t clk_gate_dis          : 1;  /**< [  0:  0](R/W) When set to 1, disables clock gating. */
        uint64_t cfg_chk_dis           : 1;  /**< [  1:  1](R/W) When set to 1, disables config checks. Tasks with
                                                                 invalid configurations will still be processed. */
        uint64_t single_task_en        : 1;  /**< [  2:  2](R/W) When set to 1, the core will always wait until idle before
                                                                 starting the next task (degrades the throughput). */
        uint64_t single_task_phy_en    : 1;  /**< [  3:  3](R/W) When set to 1, the core will wait until idle before accepting
                                                                 a new task with a different PHY_MODE (degrades the throughput). */
        uint64_t single_task_chnl_en   : 1;  /**< [  4:  4](R/W) When set to 1, the core will wait until idle before accepting
                                                                 a new task in case of changing channel_mode. (degrades the throughput). */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    struct cavm_pdecx_tc_control_reg_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t reserved_5_31         : 27;
        uint64_t single_task_chnl_en   : 1;  /**< [  4:  4](R/W) When set to 1, the core will wait until idle before accepting
                                                                 a new task in case of changing channel_mode. (degrades the throughput). */
        uint64_t single_task_phy_en    : 1;  /**< [  3:  3](R/W) When set to 1, the core will wait until idle before accepting
                                                                 a new task with a different PHY_MODE (degrades the throughput). */
        uint64_t single_task_en        : 1;  /**< [  2:  2](R/W) When set to 1, the core will always wait until idle before
                                                                 starting the next task (degrades the throughput). */
        uint64_t cfg_chk_dis           : 1;  /**< [  1:  1](R/W) When set to 1, disables config checks. Tasks with
                                                                 invalid configurations will still be processed. */
        uint64_t clk_gate_dis          : 1;  /**< [  0:  0](R/W) When set to 1, disables clock gating. */
#else /* Word 0 - Little Endian */
        uint64_t clk_gate_dis          : 1;  /**< [  0:  0](R/W) When set to 1, disables clock gating. */
        uint64_t cfg_chk_dis           : 1;  /**< [  1:  1](R/W) When set to 1, disables config checks. Tasks with
                                                                 invalid configurations will still be processed. */
        uint64_t single_task_en        : 1;  /**< [  2:  2](R/W) When set to 1, the core will always wait until idle before
                                                                 starting the next task (degrades the throughput). */
        uint64_t single_task_phy_en    : 1;  /**< [  3:  3](R/W) When set to 1, the core will wait until idle before accepting
                                                                 a new task with a different PHY_MODE (degrades the throughput). */
        uint64_t single_task_chnl_en   : 1;  /**< [  4:  4](R/W) When set to 1, the core will wait until idle before accepting
                                                                 a new task in case of changing channel_mode. (degrades the throughput). */
        uint64_t reserved_5_31         : 27;
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_pdecx_tc_control_reg cavm_pdecx_tc_control_reg_t;

static inline uint64_t CAVM_PDECX_TC_CONTROL_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_TC_CONTROL_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043581010ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_TC_CONTROL_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_TC_CONTROL_REG(a) cavm_pdecx_tc_control_reg_t
#define bustype_CAVM_PDECX_TC_CONTROL_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_TC_CONTROL_REG(a) "PDECX_TC_CONTROL_REG"
#define busnum_CAVM_PDECX_TC_CONTROL_REG(a) (a)
#define arguments_CAVM_PDECX_TC_CONTROL_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_tc_error_mask_reg
 *
 * PDEC Decoder Core Error Mask Register
 * This register enables internal decoder errors. Errors reported in
 * PDEC()_TC_ERROR_REG will generate an error signal only when the
 * corresponding bit is set in PDEC()_TC_ERROR_MASK_REG[ERR_MASK].
 */
union cavm_pdecx_tc_error_mask_reg
{
    uint64_t u;
    struct cavm_pdecx_tc_error_mask_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
#else /* Word 0 - Little Endian */
        uint64_t err_mask              : 32; /**< [ 31:  0](R/W) Error mask bits. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_tc_error_mask_reg_s cn; */
};
typedef union cavm_pdecx_tc_error_mask_reg cavm_pdecx_tc_error_mask_reg_t;

static inline uint64_t CAVM_PDECX_TC_ERROR_MASK_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_TC_ERROR_MASK_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043581030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_TC_ERROR_MASK_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_TC_ERROR_MASK_REG(a) cavm_pdecx_tc_error_mask_reg_t
#define bustype_CAVM_PDECX_TC_ERROR_MASK_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_TC_ERROR_MASK_REG(a) "PDECX_TC_ERROR_MASK_REG"
#define busnum_CAVM_PDECX_TC_ERROR_MASK_REG(a) (a)
#define arguments_CAVM_PDECX_TC_ERROR_MASK_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_tc_error_reg
 *
 * PDEC Decoder Error Register
 * This register reports various error conditions.
 *
 * All errors reported in this register are reported as FATAL errors, and the
 * MHBW registers can be inspected to determine the job tag(s) associated with
 * the error(s).
 */
union cavm_pdecx_tc_error_reg
{
    uint64_t u;
    struct cavm_pdecx_tc_error_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t inv_cfg               : 1;  /**< [  8:  8](R/W1C/H) Invalid task configuration. Task aborted. */
        uint64_t reg_mask_err          : 4;  /**< [  7:  4](R/W1C/H) Reserved. */
        uint64_t ign_read              : 1;  /**< [  3:  3](R/W1C/H) Ignored read access error -- one already in progress. */
        uint64_t inv_read              : 1;  /**< [  2:  2](R/W1C/H) Invalid read access error (out of range address). */
        uint64_t inv_write             : 1;  /**< [  1:  1](R/W1C/H) Invalid write access error (out of range address). */
        uint64_t inv_start             : 1;  /**< [  0:  0](R/W1C/H) Invalid start task error (core is busy processing a task). */
#else /* Word 0 - Little Endian */
        uint64_t inv_start             : 1;  /**< [  0:  0](R/W1C/H) Invalid start task error (core is busy processing a task). */
        uint64_t inv_write             : 1;  /**< [  1:  1](R/W1C/H) Invalid write access error (out of range address). */
        uint64_t inv_read              : 1;  /**< [  2:  2](R/W1C/H) Invalid read access error (out of range address). */
        uint64_t ign_read              : 1;  /**< [  3:  3](R/W1C/H) Ignored read access error -- one already in progress. */
        uint64_t reg_mask_err          : 4;  /**< [  7:  4](R/W1C/H) Reserved. */
        uint64_t inv_cfg               : 1;  /**< [  8:  8](R/W1C/H) Invalid task configuration. Task aborted. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_tc_error_reg_s cn; */
};
typedef union cavm_pdecx_tc_error_reg cavm_pdecx_tc_error_reg_t;

static inline uint64_t CAVM_PDECX_TC_ERROR_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_TC_ERROR_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043581038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_TC_ERROR_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_TC_ERROR_REG(a) cavm_pdecx_tc_error_reg_t
#define bustype_CAVM_PDECX_TC_ERROR_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_TC_ERROR_REG(a) "PDECX_TC_ERROR_REG"
#define busnum_CAVM_PDECX_TC_ERROR_REG(a) (a)
#define arguments_CAVM_PDECX_TC_ERROR_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_tc_main_reset_reg
 *
 * PDEC Decoder Reset Register
 * Internal decoder core reset register.
 */
union cavm_pdecx_tc_main_reset_reg
{
    uint64_t u;
    struct cavm_pdecx_tc_main_reset_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Any write to this register will reset the internal decoder core. */
#else /* Word 0 - Little Endian */
        uint64_t soft_reset            : 1;  /**< [  0:  0](R/W/H) Any write to this register will reset the internal decoder core. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_tc_main_reset_reg_s cn; */
};
typedef union cavm_pdecx_tc_main_reset_reg cavm_pdecx_tc_main_reset_reg_t;

static inline uint64_t CAVM_PDECX_TC_MAIN_RESET_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_TC_MAIN_RESET_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043581000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_TC_MAIN_RESET_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_TC_MAIN_RESET_REG(a) cavm_pdecx_tc_main_reset_reg_t
#define bustype_CAVM_PDECX_TC_MAIN_RESET_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_TC_MAIN_RESET_REG(a) "PDECX_TC_MAIN_RESET_REG"
#define busnum_CAVM_PDECX_TC_MAIN_RESET_REG(a) (a)
#define arguments_CAVM_PDECX_TC_MAIN_RESET_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_tc_main_start_reg
 *
 * INTERNAL: TC Start Register
 *
 * TC start register.
 */
union cavm_pdecx_tc_main_start_reg
{
    uint64_t u;
    struct cavm_pdecx_tc_main_start_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
#else /* Word 0 - Little Endian */
        uint64_t start                 : 1;  /**< [  0:  0](R/W/H) Start bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_tc_main_start_reg_s cn; */
};
typedef union cavm_pdecx_tc_main_start_reg cavm_pdecx_tc_main_start_reg_t;

static inline uint64_t CAVM_PDECX_TC_MAIN_START_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_TC_MAIN_START_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043581008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_TC_MAIN_START_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_TC_MAIN_START_REG(a) cavm_pdecx_tc_main_start_reg_t
#define bustype_CAVM_PDECX_TC_MAIN_START_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_TC_MAIN_START_REG(a) "PDECX_TC_MAIN_START_REG"
#define busnum_CAVM_PDECX_TC_MAIN_START_REG(a) (a)
#define arguments_CAVM_PDECX_TC_MAIN_START_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) pdec#_tc_mon_reg#
 *
 * INTERNAL: TC Monitoring 0 Registers
 *
 * TC task output monitoring registers.
 */
union cavm_pdecx_tc_mon_regx
{
    uint64_t u;
    struct cavm_pdecx_tc_mon_regx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t bus_val               : 64; /**< [ 63:  0](RO/H) Decoder core task output monitoring values.
                                                                 Note that PDEC only has Q and R outputs. mon_reg2|3_bus are placeholders.
                                                                 mon_reg0_bus = Identifier associated to the Q output interface. Valid when q_avl is HIGH.
                                                                 mon_reg1_bus = Identifier associated to the R output interface. Valid when r_avl is HIGH.
                                                                 mon_reg2_bus = Identifier associated to the S output interface. Valid when s_avl is HIGH.
                                                                 mon_reg3_bus = Identifier associated to the H output interface. Valid when h_avl is HIGH. */
#else /* Word 0 - Little Endian */
        uint64_t bus_val               : 64; /**< [ 63:  0](RO/H) Decoder core task output monitoring values.
                                                                 Note that PDEC only has Q and R outputs. mon_reg2|3_bus are placeholders.
                                                                 mon_reg0_bus = Identifier associated to the Q output interface. Valid when q_avl is HIGH.
                                                                 mon_reg1_bus = Identifier associated to the R output interface. Valid when r_avl is HIGH.
                                                                 mon_reg2_bus = Identifier associated to the S output interface. Valid when s_avl is HIGH.
                                                                 mon_reg3_bus = Identifier associated to the H output interface. Valid when h_avl is HIGH. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pdecx_tc_mon_regx_s cn; */
};
typedef union cavm_pdecx_tc_mon_regx cavm_pdecx_tc_mon_regx_t;

static inline uint64_t CAVM_PDECX_TC_MON_REGX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_TC_MON_REGX(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=3)))
        return 0x87e043581300ll + 0x8000ll * ((a) & 0x1) + 8ll * ((b) & 0x3);
    __cavm_csr_fatal("PDECX_TC_MON_REGX", 2, a, b, 0, 0);
}

#define typedef_CAVM_PDECX_TC_MON_REGX(a,b) cavm_pdecx_tc_mon_regx_t
#define bustype_CAVM_PDECX_TC_MON_REGX(a,b) CSR_TYPE_RSL
#define basename_CAVM_PDECX_TC_MON_REGX(a,b) "PDECX_TC_MON_REGX"
#define busnum_CAVM_PDECX_TC_MON_REGX(a,b) (a)
#define arguments_CAVM_PDECX_TC_MON_REGX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pdec#_tc_status_reg
 *
 * PDEC Decoder Status Register
 * This register reports status from the internal decoder core.
 */
union cavm_pdecx_tc_status_reg
{
    uint64_t u;
    struct cavm_pdecx_tc_status_reg_s
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
    /* struct cavm_pdecx_tc_status_reg_s cn; */
};
typedef union cavm_pdecx_tc_status_reg cavm_pdecx_tc_status_reg_t;

static inline uint64_t CAVM_PDECX_TC_STATUS_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PDECX_TC_STATUS_REG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043581020ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PDECX_TC_STATUS_REG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PDECX_TC_STATUS_REG(a) cavm_pdecx_tc_status_reg_t
#define bustype_CAVM_PDECX_TC_STATUS_REG(a) CSR_TYPE_RSL
#define basename_CAVM_PDECX_TC_STATUS_REG(a) "PDECX_TC_STATUS_REG"
#define busnum_CAVM_PDECX_TC_STATUS_REG(a) (a)
#define arguments_CAVM_PDECX_TC_STATUS_REG(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_PDEC_H__ */
