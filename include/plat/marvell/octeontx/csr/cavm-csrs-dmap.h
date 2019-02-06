#ifndef __CAVM_CSRS_DMAP_H__
#define __CAVM_CSRS_DMAP_H__
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
 * OcteonTX DMAP.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration dmap_cp_type_e
 *
 * DMAP LTE Cyclic Prefix Enumeration
 */
#define CAVM_DMAP_CP_TYPE_E_EXTENDED (1)
#define CAVM_DMAP_CP_TYPE_E_NORMAL (0)

/**
 * Enumeration dmap_csi1_enc_cat_e
 *
 * DMAP NR CSI1 Encoding Category Enumeration
 */
#define CAVM_DMAP_CSI1_ENC_CAT_E_NO_CSI1 (0)
#define CAVM_DMAP_CSI1_ENC_CAT_E_OCSI1_1 (1)
#define CAVM_DMAP_CSI1_ENC_CAT_E_OCSI1_11 (4)
#define CAVM_DMAP_CSI1_ENC_CAT_E_OCSI1_2 (2)
#define CAVM_DMAP_CSI1_ENC_CAT_E_OCSI1_3_11 (3)
#define CAVM_DMAP_CSI1_ENC_CAT_E_RSDV0 (5)
#define CAVM_DMAP_CSI1_ENC_CAT_E_RSDV1 (6)
#define CAVM_DMAP_CSI1_ENC_CAT_E_RSDV2 (7)

/**
 * Enumeration dmap_csi2_enc_cat_e
 *
 * DMAP NR CSI2 Encoding Category Enumeration
 */
#define CAVM_DMAP_CSI2_ENC_CAT_E_NO_CSI2 (0)
#define CAVM_DMAP_CSI2_ENC_CAT_E_OCSI2_1 (1)
#define CAVM_DMAP_CSI2_ENC_CAT_E_OCSI2_11 (4)
#define CAVM_DMAP_CSI2_ENC_CAT_E_OCSI2_2 (2)
#define CAVM_DMAP_CSI2_ENC_CAT_E_OCSI2_3_11 (3)
#define CAVM_DMAP_CSI2_ENC_CAT_E_RSDV0 (5)
#define CAVM_DMAP_CSI2_ENC_CAT_E_RSDV1 (6)
#define CAVM_DMAP_CSI2_ENC_CAT_E_RSDV2 (7)

/**
 * Enumeration dmap_lte_ack_enc_cat_e
 *
 * DMAP LTE ACK Encoding Category Enumeration
 */
#define CAVM_DMAP_LTE_ACK_ENC_CAT_E_ACK_1 (1)
#define CAVM_DMAP_LTE_ACK_ENC_CAT_E_ACK_1_BDLG (2)
#define CAVM_DMAP_LTE_ACK_ENC_CAT_E_ACK_2 (3)
#define CAVM_DMAP_LTE_ACK_ENC_CAT_E_ACK_22 (7)
#define CAVM_DMAP_LTE_ACK_ENC_CAT_E_ACK_2_BDLG (4)
#define CAVM_DMAP_LTE_ACK_ENC_CAT_E_NO_ACK (0)
#define CAVM_DMAP_LTE_ACK_ENC_CAT_E_ORI_11_22 (6)
#define CAVM_DMAP_LTE_ACK_ENC_CAT_E_ORI_3_11 (5)

/**
 * Enumeration dmap_mod_order_e
 *
 * DMAP NR Modulation Order Enumeration
 */
#define CAVM_DMAP_MOD_ORDER_E_MO_16QAM (4)
#define CAVM_DMAP_MOD_ORDER_E_MO_256QAM (8)
#define CAVM_DMAP_MOD_ORDER_E_MO_64QAM (6)
#define CAVM_DMAP_MOD_ORDER_E_MO_BPSK (1)
#define CAVM_DMAP_MOD_ORDER_E_MO_QPSK (2)
#define CAVM_DMAP_MOD_ORDER_E_RSVD0 (3)
#define CAVM_DMAP_MOD_ORDER_E_RSVD1 (5)
#define CAVM_DMAP_MOD_ORDER_E_RSVD2 (7)
#define CAVM_DMAP_MOD_ORDER_E_RSVD3 (9)
#define CAVM_DMAP_MOD_ORDER_E_RSVD4 (0xa)
#define CAVM_DMAP_MOD_ORDER_E_RSVD5 (0xb)
#define CAVM_DMAP_MOD_ORDER_E_RSVD6 (0xc)
#define CAVM_DMAP_MOD_ORDER_E_RSVD7 (0xd)
#define CAVM_DMAP_MOD_ORDER_E_RSVD8 (0xe)
#define CAVM_DMAP_MOD_ORDER_E_RSVD9 (0xf)

/**
 * Enumeration dmap_ndft_idx_e
 *
 * DMAP IDFT Size Index Enumeration
 */
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_108 (7)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1080 (0x1f)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1152 (0x20)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_12 (0)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_120 (8)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1200 (0x21)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1296 (0x22)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_144 (9)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1440 (0x23)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1500 (0x24)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1536 (0x25)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1620 (0x26)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1728 (0x27)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_180 (0xa)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1800 (0x28)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_192 (0xb)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1920 (0x29)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_1944 (0x2a)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_2 (0x35)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_216 (0xc)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_2160 (0x2b)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_2304 (0x2c)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_24 (1)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_240 (0xd)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_2400 (0x2d)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_2592 (0x2e)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_2700 (0x2f)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_288 (0xe)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_2880 (0x30)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_2916 (0x31)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_3 (0x36)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_300 (0xf)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_3000 (0x32)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_3072 (0x33)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_324 (0x10)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_3240 (0x34)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_36 (2)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_360 (0x11)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_384 (0x12)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_432 (0x13)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_48 (3)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_480 (0x14)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_540 (0x15)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_576 (0x16)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_6 (0x37)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_60 (4)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_600 (0x17)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_648 (0x18)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_72 (5)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_720 (0x19)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_768 (0x1a)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_864 (0x1b)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_900 (0x1c)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_96 (6)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_960 (0x1d)
#define CAVM_DMAP_NDFT_IDX_E_IDFT_SIZE_972 (0x1e)

/**
 * Enumeration dmap_nr_ack_enc_cat_e
 *
 * DMAP NR ACK Encoding Category Enumeration
 */
#define CAVM_DMAP_NR_ACK_ENC_CAT_E_ACK_1 (1)
#define CAVM_DMAP_NR_ACK_ENC_CAT_E_ACK_2 (2)
#define CAVM_DMAP_NR_ACK_ENC_CAT_E_NO_ACK (0)
#define CAVM_DMAP_NR_ACK_ENC_CAT_E_ORI_11 (4)
#define CAVM_DMAP_NR_ACK_ENC_CAT_E_ORI_3_11 (3)
#define CAVM_DMAP_NR_ACK_ENC_CAT_E_RSDV0 (5)
#define CAVM_DMAP_NR_ACK_ENC_CAT_E_RSDV1 (6)
#define CAVM_DMAP_NR_ACK_ENC_CAT_E_RSDV2 (7)

/**
 * Enumeration dmap_proc_type_e
 *
 * DMAP NR Processing Type Enumeration
 */
#define CAVM_DMAP_PROC_TYPE_E_DFT_IDFT_ONLY (8)
#define CAVM_DMAP_PROC_TYPE_E_LTE_SP_SF (4)
#define CAVM_DMAP_PROC_TYPE_E_LTE_SUB_PRB (3)
#define CAVM_DMAP_PROC_TYPE_E_NR_CP_OFDM (6)
#define CAVM_DMAP_PROC_TYPE_E_NR_DFT_S_OFDM (5)
#define CAVM_DMAP_PROC_TYPE_E_NR_PUCCH_F4 (7)
#define CAVM_DMAP_PROC_TYPE_E_TTI_1MS (0)
#define CAVM_DMAP_PROC_TYPE_E_TTI_2_3OS (2)
#define CAVM_DMAP_PROC_TYPE_E_TTI_7OS (1)

/**
 * Enumeration dmap_ri_ack_scomb_method_e
 *
 * DMAP LTE RI and ACK Soft Combining Method Enumeration
 */
#define CAVM_DMAP_RI_ACK_SCOMB_METHOD_E_ABSOLUTE (1)
#define CAVM_DMAP_RI_ACK_SCOMB_METHOD_E_REGULAR (0)

/**
 * Enumeration dmap_ri_enc_cat_e
 *
 * DMAP LTE RI Encoding Category Enumeration
 */
#define CAVM_DMAP_RI_ENC_CAT_E_NO_RI (0)
#define CAVM_DMAP_RI_ENC_CAT_E_ORI_1 (1)
#define CAVM_DMAP_RI_ENC_CAT_E_ORI_11_22 (4)
#define CAVM_DMAP_RI_ENC_CAT_E_ORI_2 (2)
#define CAVM_DMAP_RI_ENC_CAT_E_ORI_22 (5)
#define CAVM_DMAP_RI_ENC_CAT_E_ORI_3_11 (3)
#define CAVM_DMAP_RI_ENC_CAT_E_RSVD0 (6)
#define CAVM_DMAP_RI_ENC_CAT_E_RSVD1 (7)

/**
 * Enumeration dmap_sinr_type_e
 *
 * DMAP NR SINR Type Enumeration
 */
#define CAVM_DMAP_SINR_TYPE_E_CP_OFDM (0)
#define CAVM_DMAP_SINR_TYPE_E_LTE_SUB_PRB (3)
#define CAVM_DMAP_SINR_TYPE_E_MSE (2)
#define CAVM_DMAP_SINR_TYPE_E_NORM_GAIN (1)

/**
 * Structure dmap_jd_lte_cfg_s
 *
 * DMAP LTE Job Configuration Structure
 */
union cavm_dmap_jd_lte_cfg_s
{
    uint64_t u[4];
    struct cavm_dmap_jd_lte_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_39_63        : 25;
        uint64_t ack_scomb_bypass      : 1;  /**< [ 38: 38] Set to 1 for ACK soft-combining bypass (for LTE only). This feature is
                                                                 independent of RI extraction or marking/erasure. */
        uint64_t ri_scomb_bypass       : 1;  /**< [ 37: 37] Set to 1 for RI soft-combining bypass (for LTE only). This feature is
                                                                 independent of RI extraction or marking/erasure. */
        uint64_t cqi_scomb_bypass      : 1;  /**< [ 36: 36] CQI soft combining bypass (for LTE only). When set to 1, indicates CQI is not RM
                                                                 encoded and soft-combining will be bypassed as a result. */
        uint64_t ack_extract_bypass    : 1;  /**< [ 35: 35] Set to 1 for ACK extraction bypass (for LTE only). If set to 0, ACK extraction
                                                                 takes place independent of soft combining or erasure/marking.

                                                                 This field must be set to 1 if [NUM_ACK_RE] = 0. */
        uint64_t ri_extract_bypass     : 1;  /**< [ 34: 34] Set to 1 for RI extraction bypass (for LTE only). This feature is independent of
                                                                 RI soft combining or marking/erasure. */
        uint64_t ack_scomb_method      : 1;  /**< [ 33: 33] ACK soft-combining mode, enumerated by DMAP_RI_ACK_SCOMB_METHOD_E. */
        uint64_t ri_scomb_method       : 1;  /**< [ 32: 32] RI soft-combining mode, enumerated by DMAP_RI_ACK_SCOMB_METHOD_E. */
        uint64_t reserved_29_31        : 3;
        uint64_t ri_sym                : 1;  /**< [ 28: 28] RI symbol selector (for LTE normal CP only):
                                                                 0x0 = RI LLRs are on symbol indices {1, 4, 7, 10}.
                                                                 0x1 = RI LLRs are on symbol indices {0, 3, 6, 9}. */
        uint64_t reserved_25_27        : 3;
        uint64_t ack_sym_idx           : 1;  /**< [ 24: 24] ACK symbol index (for LTE 2/3-OS sTTI with 2 data symbols only):
                                                                 0x0 = ACK is present in symbol 0.
                                                                 0x1 = ACK is present in symbol 1.

                                                                 This parameter implies the symbol index for RI. (1 - [ACK_SYM_IDX])
                                                                 refers to the symbol index for RI.

                                                                 This field must be zero when [PROCESSING_TYPE] = 2 and [NUM_SYM] = 1 (1 symbol 2/3 OS sTTI case). */
        uint64_t reserved_21_23        : 3;
        uint64_t cp_type               : 1;  /**< [ 20: 20] Cyclic prefix type, enumerated by DMAP_CP_TYPE_E. */
        uint64_t reserved_18_19        : 2;
        uint64_t slot_id               : 2;  /**< [ 17: 16] Slot identifier (for LTE only).
                                                                 0x0 = Slot 0.
                                                                 0x1 = Slot 1.
                                                                 0x2 = Subframe.
                                                                 0x3 = Reserved. */
        uint64_t reserved_15           : 1;
        uint64_t ack_enc_cat           : 3;  /**< [ 14: 12] ACK encoding category, enumerated by DMAP_ACK_ENC_CAT_E. */
        uint64_t reserved_8_11         : 4;
        uint64_t num_sym_cqi           : 4;  /**< [  7:  4] Number of symbols on which CQI is mapped. */
        uint64_t reserved_3            : 1;
        uint64_t ri_enc_cat            : 3;  /**< [  2:  0] RI encoding category, enumerated by DMAP_RI_ENC_CAT_E. */
#else /* Word 0 - Little Endian */
        uint64_t ri_enc_cat            : 3;  /**< [  2:  0] RI encoding category, enumerated by DMAP_RI_ENC_CAT_E. */
        uint64_t reserved_3            : 1;
        uint64_t num_sym_cqi           : 4;  /**< [  7:  4] Number of symbols on which CQI is mapped. */
        uint64_t reserved_8_11         : 4;
        uint64_t ack_enc_cat           : 3;  /**< [ 14: 12] ACK encoding category, enumerated by DMAP_ACK_ENC_CAT_E. */
        uint64_t reserved_15           : 1;
        uint64_t slot_id               : 2;  /**< [ 17: 16] Slot identifier (for LTE only).
                                                                 0x0 = Slot 0.
                                                                 0x1 = Slot 1.
                                                                 0x2 = Subframe.
                                                                 0x3 = Reserved. */
        uint64_t reserved_18_19        : 2;
        uint64_t cp_type               : 1;  /**< [ 20: 20] Cyclic prefix type, enumerated by DMAP_CP_TYPE_E. */
        uint64_t reserved_21_23        : 3;
        uint64_t ack_sym_idx           : 1;  /**< [ 24: 24] ACK symbol index (for LTE 2/3-OS sTTI with 2 data symbols only):
                                                                 0x0 = ACK is present in symbol 0.
                                                                 0x1 = ACK is present in symbol 1.

                                                                 This parameter implies the symbol index for RI. (1 - [ACK_SYM_IDX])
                                                                 refers to the symbol index for RI.

                                                                 This field must be zero when [PROCESSING_TYPE] = 2 and [NUM_SYM] = 1 (1 symbol 2/3 OS sTTI case). */
        uint64_t reserved_25_27        : 3;
        uint64_t ri_sym                : 1;  /**< [ 28: 28] RI symbol selector (for LTE normal CP only):
                                                                 0x0 = RI LLRs are on symbol indices {1, 4, 7, 10}.
                                                                 0x1 = RI LLRs are on symbol indices {0, 3, 6, 9}. */
        uint64_t reserved_29_31        : 3;
        uint64_t ri_scomb_method       : 1;  /**< [ 32: 32] RI soft-combining mode, enumerated by DMAP_RI_ACK_SCOMB_METHOD_E. */
        uint64_t ack_scomb_method      : 1;  /**< [ 33: 33] ACK soft-combining mode, enumerated by DMAP_RI_ACK_SCOMB_METHOD_E. */
        uint64_t ri_extract_bypass     : 1;  /**< [ 34: 34] Set to 1 for RI extraction bypass (for LTE only). This feature is independent of
                                                                 RI soft combining or marking/erasure. */
        uint64_t ack_extract_bypass    : 1;  /**< [ 35: 35] Set to 1 for ACK extraction bypass (for LTE only). If set to 0, ACK extraction
                                                                 takes place independent of soft combining or erasure/marking.

                                                                 This field must be set to 1 if [NUM_ACK_RE] = 0. */
        uint64_t cqi_scomb_bypass      : 1;  /**< [ 36: 36] CQI soft combining bypass (for LTE only). When set to 1, indicates CQI is not RM
                                                                 encoded and soft-combining will be bypassed as a result. */
        uint64_t ri_scomb_bypass       : 1;  /**< [ 37: 37] Set to 1 for RI soft-combining bypass (for LTE only). This feature is
                                                                 independent of RI extraction or marking/erasure. */
        uint64_t ack_scomb_bypass      : 1;  /**< [ 38: 38] Set to 1 for ACK soft-combining bypass (for LTE only). This feature is
                                                                 independent of RI extraction or marking/erasure. */
        uint64_t reserved_39_63        : 25;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_109_127      : 19;
        uint64_t num_ack_re            : 13; /**< [108: 96] Number of ACK REs per layer (for LTE only). */
        uint64_t reserved_77_95        : 19;
        uint64_t num_ri_re             : 13; /**< [ 76: 64] Number of RI REs per layer (for LTE only). */
#else /* Word 1 - Little Endian */
        uint64_t num_ri_re             : 13; /**< [ 76: 64] Number of RI REs per layer (for LTE only). */
        uint64_t reserved_77_95        : 19;
        uint64_t num_ack_re            : 13; /**< [108: 96] Number of ACK REs per layer (for LTE only). */
        uint64_t reserved_109_127      : 19;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_190_191      : 2;
        uint64_t num_cqi_re0           : 14; /**< [189:176] Number of CQI REs per layer for hypothesis 0 (for LTE only). */
        uint64_t reserved_174_175      : 2;
        uint64_t num_cqi_re1           : 14; /**< [173:160] Number of CQI REs per layer for hypothesis 1 (for LTE only). */
        uint64_t reserved_158_159      : 2;
        uint64_t num_cqi_re2           : 14; /**< [157:144] Number of CQI REs per layer for hypothesis 2 (for LTE only). */
        uint64_t reserved_142_143      : 2;
        uint64_t num_cqi_re3           : 14; /**< [141:128] Number of CQI REs per layer for hypothesis 3 (for LTE only). */
#else /* Word 2 - Little Endian */
        uint64_t num_cqi_re3           : 14; /**< [141:128] Number of CQI REs per layer for hypothesis 3 (for LTE only). */
        uint64_t reserved_142_143      : 2;
        uint64_t num_cqi_re2           : 14; /**< [157:144] Number of CQI REs per layer for hypothesis 2 (for LTE only). */
        uint64_t reserved_158_159      : 2;
        uint64_t num_cqi_re1           : 14; /**< [173:160] Number of CQI REs per layer for hypothesis 1 (for LTE only). */
        uint64_t reserved_174_175      : 2;
        uint64_t num_cqi_re0           : 14; /**< [189:176] Number of CQI REs per layer for hypothesis 0 (for LTE only). */
        uint64_t reserved_190_191      : 2;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_254_255      : 2;
        uint64_t num_cqi_re4           : 14; /**< [253:240] Number of CQI REs per layer for hypothesis 4 (for LTE only). */
        uint64_t reserved_238_239      : 2;
        uint64_t num_cqi_re5           : 14; /**< [237:224] Number of CQI REs per layer for hypothesis 5 (for LTE only). */
        uint64_t reserved_222_223      : 2;
        uint64_t num_cqi_re6           : 14; /**< [221:208] Number of CQI REs per layer for hypothesis 6 (for LTE only). */
        uint64_t reserved_206_207      : 2;
        uint64_t num_cqi_re7           : 14; /**< [205:192] Number of CQI REs per layer for hypothesis 7 (for LTE only). */
#else /* Word 3 - Little Endian */
        uint64_t num_cqi_re7           : 14; /**< [205:192] Number of CQI REs per layer for hypothesis 7 (for LTE only). */
        uint64_t reserved_206_207      : 2;
        uint64_t num_cqi_re6           : 14; /**< [221:208] Number of CQI REs per layer for hypothesis 6 (for LTE only). */
        uint64_t reserved_222_223      : 2;
        uint64_t num_cqi_re5           : 14; /**< [237:224] Number of CQI REs per layer for hypothesis 5 (for LTE only). */
        uint64_t reserved_238_239      : 2;
        uint64_t num_cqi_re4           : 14; /**< [253:240] Number of CQI REs per layer for hypothesis 4 (for LTE only). */
        uint64_t reserved_254_255      : 2;
#endif /* Word 3 - End */
    } s;
    /* struct cavm_dmap_jd_lte_cfg_s_s cn; */
};

/**
 * Structure dmap_jd_nr_cfg_s
 *
 * DMAP NR Job Configuration Structure
 */
union cavm_dmap_jd_nr_cfg_s
{
    uint64_t u[16];
    struct cavm_dmap_jd_nr_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t csi1_extract_bypass   : 1;  /**< [ 61: 61] Set to 1 for CSI1 extraction bypass. */
        uint64_t ack_extract_bypass    : 1;  /**< [ 60: 60] Set to 1 for ACK extraction bypass. */
        uint64_t ack_scomb_bypass      : 1;  /**< [ 59: 59] Set to 1 for ACK soft combining bypass. */
        uint64_t csi1_scomb_bypass     : 1;  /**< [ 58: 58] Set to 1 for CSI1 soft combining bypass. */
        uint64_t csi2_scomb_bypass     : 1;  /**< [ 57: 57] Set to 1 for CSI2 soft combining bypass. */
        uint64_t ack_scomb_method      : 1;  /**< [ 56: 56] ACK soft combining method.
                                                                 0x0 = Regular combining.
                                                                 0x1 = Absolute value combining. */
        uint64_t layer_mux_ack         : 1;  /**< [ 55: 55] ACK layer multiplexing control.
                                                                 0x0 = ACK copied across layers.
                                                                 0x1 = ACK multiplexed across layers. */
        uint64_t layer_mux_csi1        : 1;  /**< [ 54: 54] CSI1 layer multiplexing control.
                                                                 0x0 = CSI1 copied across layers.
                                                                 0x1 = CSI1 multiplexed across layers. */
        uint64_t layer_mux_csi2        : 1;  /**< [ 53: 53] CSI2 layer multiplexing control.
                                                                 0x0 = CSI2 copied across layers.
                                                                 0x1 = CSI2 multiplexed across layers. */
        uint64_t ptrs                  : 1;  /**< [ 52: 52] PTRS control.
                                                                 0x0 = No PTRS is present.
                                                                 0x1 = PTRS is present. */
        uint64_t reserved_48_51        : 4;
        uint64_t dmrs_mux_idx          : 4;  /**< [ 47: 44] DMRS Multiplexing index.
                                                                 Note if [DMRS_MUX_IDX] != 0, No UCI is present in the symbol.
                                                                 0x0 = No DMRS.
                                                                 0x1 = m=2s,    where s=0,1...
                                                                 0x2 = m=2s+1,  where s=0,1...
                                                                 0x3 = m=6s+k,  where s=0,1... and k=0,1.
                                                                 0x4 = m=6s+k,  where s=0,1... and k=2,3.
                                                                 0x5 = m=6s+k,  where s=0,1... and k=4,5.
                                                                 0x6 = m=6s+k,  where s=0,1... and k=0,1,2,3.
                                                                 0x7 = m=6s+k,  where s=0,1... and k=0,1,4,5.
                                                                 0x8 = m=6s+k,  where s=0,1... and k=2,3,4,5.

                                                                 m is the subcarrier index of non-data samples. */
        uint64_t reserved_43           : 1;
        uint64_t ptrs_map_idx          : 3;  /**< [ 42: 40] PTRS mapping index for NT DFT-s-OFDM only.
                                                                 Note PTRS mapping index cannot be 5 or 6, if [MOD_ORDER] = 1.
                                                                 0x0 = Two PTR-RS groups with two samples per group.
                                                                 0x1 = Two PTR-RS groups with four samples per group.
                                                                 0x2 = Four PTR-RS groups with two samples per group.
                                                                 0x3 = Four PTR-RS groups with four samples per group.
                                                                 0x4 = Eight PTR-RS groups with four samples per group.
                                                                 0x5 = Sixteen PTR-RS groups with one sample per group with a subcarrier
                                                                 offset value equal to -1.
                                                                 0x6 = Sixteen PTR-RS groups with one sample per group with no subcarrier offset. */
        uint64_t reserved_38_39        : 2;
        uint64_t ptrs_map_type         : 2;  /**< [ 37: 36] PTRS mapping type (for NR CP-OFDM).
                                                                 0x0 = Distributed PRB.
                                                                 0x1 = Distributed VRB.
                                                                 0x2 = Localized.
                                                                 0x3 = Reserved. */
        uint64_t reserved_34_35        : 2;
        uint64_t ptrs_rb_offset0       : 2;  /**< [ 33: 32] NR CP-OFDM PTRS resource block offset for [PTRS_MAP_TYPE] = 0 or 1. This is
                                                                 interpreted as RB offset for the even numbered VRBs for [PTRS_MAP_TYPE] = 1.
                                                                 Refer to K_RB_ref for details. */
        uint64_t reserved_31           : 1;
        uint64_t ptrs_rb_step          : 3;  /**< [ 30: 28] NR CP-OFDM PTRS resource block step for [PTRS_MAP_TYPE] = 0. Refer to K_RPTRS for details. */
        uint64_t reserved_27           : 1;
        uint64_t ptrs_num_ports        : 3;  /**< [ 26: 24] Number of ports for NR CP-OFDM PTRS mapping with [PTRS_MAP_TYPE] = 0 and 1. Valid range is 1 to 4. */
        uint64_t reserved_20_23        : 4;
        uint64_t ptrs_re_offset0       : 4;  /**< [ 19: 16] NR CP-OFDM PTRS resource element offset for [PTRS_MAP_TYPE] = 0. Refer to
                                                                 K_RE_ref as defined in the 3GPP standard. */
        uint64_t reserved_12_15        : 4;
        uint64_t ptrs_re_offset1       : 4;  /**< [ 11:  8] NR CP-OFDM PTRS resource element offset for [PTRS_MAP_TYPE] = 0. Refer to
                                                                 K_RE_ref as defined in the 3GPP standard. */
        uint64_t reserved_4_7          : 4;
        uint64_t ptrs_re_offset2       : 4;  /**< [  3:  0] NR CP-OFDM PTRS resource element offset for [PTRS_MAP_TYPE] = 0. Refer to
                                                                 K_RE_ref as defined in the 3GPP standard.

                                                                 [PTRS_RE_OFFSET0] to [PTRS_RE_OFFSETn] must be in the ascending order, where n =
                                                                 [PTRS_NUM_PORTS] - 1. */
#else /* Word 0 - Little Endian */
        uint64_t ptrs_re_offset2       : 4;  /**< [  3:  0] NR CP-OFDM PTRS resource element offset for [PTRS_MAP_TYPE] = 0. Refer to
                                                                 K_RE_ref as defined in the 3GPP standard.

                                                                 [PTRS_RE_OFFSET0] to [PTRS_RE_OFFSETn] must be in the ascending order, where n =
                                                                 [PTRS_NUM_PORTS] - 1. */
        uint64_t reserved_4_7          : 4;
        uint64_t ptrs_re_offset1       : 4;  /**< [ 11:  8] NR CP-OFDM PTRS resource element offset for [PTRS_MAP_TYPE] = 0. Refer to
                                                                 K_RE_ref as defined in the 3GPP standard. */
        uint64_t reserved_12_15        : 4;
        uint64_t ptrs_re_offset0       : 4;  /**< [ 19: 16] NR CP-OFDM PTRS resource element offset for [PTRS_MAP_TYPE] = 0. Refer to
                                                                 K_RE_ref as defined in the 3GPP standard. */
        uint64_t reserved_20_23        : 4;
        uint64_t ptrs_num_ports        : 3;  /**< [ 26: 24] Number of ports for NR CP-OFDM PTRS mapping with [PTRS_MAP_TYPE] = 0 and 1. Valid range is 1 to 4. */
        uint64_t reserved_27           : 1;
        uint64_t ptrs_rb_step          : 3;  /**< [ 30: 28] NR CP-OFDM PTRS resource block step for [PTRS_MAP_TYPE] = 0. Refer to K_RPTRS for details. */
        uint64_t reserved_31           : 1;
        uint64_t ptrs_rb_offset0       : 2;  /**< [ 33: 32] NR CP-OFDM PTRS resource block offset for [PTRS_MAP_TYPE] = 0 or 1. This is
                                                                 interpreted as RB offset for the even numbered VRBs for [PTRS_MAP_TYPE] = 1.
                                                                 Refer to K_RB_ref for details. */
        uint64_t reserved_34_35        : 2;
        uint64_t ptrs_map_type         : 2;  /**< [ 37: 36] PTRS mapping type (for NR CP-OFDM).
                                                                 0x0 = Distributed PRB.
                                                                 0x1 = Distributed VRB.
                                                                 0x2 = Localized.
                                                                 0x3 = Reserved. */
        uint64_t reserved_38_39        : 2;
        uint64_t ptrs_map_idx          : 3;  /**< [ 42: 40] PTRS mapping index for NT DFT-s-OFDM only.
                                                                 Note PTRS mapping index cannot be 5 or 6, if [MOD_ORDER] = 1.
                                                                 0x0 = Two PTR-RS groups with two samples per group.
                                                                 0x1 = Two PTR-RS groups with four samples per group.
                                                                 0x2 = Four PTR-RS groups with two samples per group.
                                                                 0x3 = Four PTR-RS groups with four samples per group.
                                                                 0x4 = Eight PTR-RS groups with four samples per group.
                                                                 0x5 = Sixteen PTR-RS groups with one sample per group with a subcarrier
                                                                 offset value equal to -1.
                                                                 0x6 = Sixteen PTR-RS groups with one sample per group with no subcarrier offset. */
        uint64_t reserved_43           : 1;
        uint64_t dmrs_mux_idx          : 4;  /**< [ 47: 44] DMRS Multiplexing index.
                                                                 Note if [DMRS_MUX_IDX] != 0, No UCI is present in the symbol.
                                                                 0x0 = No DMRS.
                                                                 0x1 = m=2s,    where s=0,1...
                                                                 0x2 = m=2s+1,  where s=0,1...
                                                                 0x3 = m=6s+k,  where s=0,1... and k=0,1.
                                                                 0x4 = m=6s+k,  where s=0,1... and k=2,3.
                                                                 0x5 = m=6s+k,  where s=0,1... and k=4,5.
                                                                 0x6 = m=6s+k,  where s=0,1... and k=0,1,2,3.
                                                                 0x7 = m=6s+k,  where s=0,1... and k=0,1,4,5.
                                                                 0x8 = m=6s+k,  where s=0,1... and k=2,3,4,5.

                                                                 m is the subcarrier index of non-data samples. */
        uint64_t reserved_48_51        : 4;
        uint64_t ptrs                  : 1;  /**< [ 52: 52] PTRS control.
                                                                 0x0 = No PTRS is present.
                                                                 0x1 = PTRS is present. */
        uint64_t layer_mux_csi2        : 1;  /**< [ 53: 53] CSI2 layer multiplexing control.
                                                                 0x0 = CSI2 copied across layers.
                                                                 0x1 = CSI2 multiplexed across layers. */
        uint64_t layer_mux_csi1        : 1;  /**< [ 54: 54] CSI1 layer multiplexing control.
                                                                 0x0 = CSI1 copied across layers.
                                                                 0x1 = CSI1 multiplexed across layers. */
        uint64_t layer_mux_ack         : 1;  /**< [ 55: 55] ACK layer multiplexing control.
                                                                 0x0 = ACK copied across layers.
                                                                 0x1 = ACK multiplexed across layers. */
        uint64_t ack_scomb_method      : 1;  /**< [ 56: 56] ACK soft combining method.
                                                                 0x0 = Regular combining.
                                                                 0x1 = Absolute value combining. */
        uint64_t csi2_scomb_bypass     : 1;  /**< [ 57: 57] Set to 1 for CSI2 soft combining bypass. */
        uint64_t csi1_scomb_bypass     : 1;  /**< [ 58: 58] Set to 1 for CSI1 soft combining bypass. */
        uint64_t ack_scomb_bypass      : 1;  /**< [ 59: 59] Set to 1 for ACK soft combining bypass. */
        uint64_t ack_extract_bypass    : 1;  /**< [ 60: 60] Set to 1 for ACK extraction bypass. */
        uint64_t csi1_extract_bypass   : 1;  /**< [ 61: 61] Set to 1 for CSI1 extraction bypass. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_127          : 1;
        uint64_t vrb_prb_bundle_size   : 3;  /**< [126:124] Bundle size for VRB to PRB mapping. Valid range is {2, 4}. */
        uint64_t reserved_122_123      : 2;
        uint64_t ptrs_rb_offset1       : 2;  /**< [121:120] For NR CP-OFDM with [PTRS_MAP_TYPE] = 1, RB offset (K_RB_ref) for the odd numbered VRBs. */
        uint64_t reserved_116_119      : 4;
        uint64_t ptrs_re_offset3       : 4;  /**< [115:112] NR CP-OFDM PTRS resource element offset for [PTRS_MAP_TYPE] = 0. Refer to
                                                                 K_RE_ref as defined in the 3GPP standard. */
        uint64_t reserved_108_111      : 4;
        uint64_t ue_vrb_start_idx      : 12; /**< [107: 96] Only for NR CP-OFDM with [PTRS_MAP_TYPE] = 1. Starting VRB idx for the UE allocation. */
        uint64_t reserved_92_95        : 4;
        uint64_t ptrs_start_re_idx0    : 12; /**< [ 91: 80] NR CP-OFDM PTRS resource element start index for [PTRS_MAP_TYPE] = 2.
                                                                 Note [PTRS_START_RE_IDX0] must be smaller than [PTRS_START_RE_IDX1]. */
        uint64_t reserved_74_79        : 6;
        uint64_t ptrs_num_re0          : 10; /**< [ 73: 64] NR CP-OFDM PTRS number of resource elements starting from the RE index given by
                                                                 PTRS_START_RE_IDX0 for [PTRS_MAP_TYPE] = 2. */
#else /* Word 1 - Little Endian */
        uint64_t ptrs_num_re0          : 10; /**< [ 73: 64] NR CP-OFDM PTRS number of resource elements starting from the RE index given by
                                                                 PTRS_START_RE_IDX0 for [PTRS_MAP_TYPE] = 2. */
        uint64_t reserved_74_79        : 6;
        uint64_t ptrs_start_re_idx0    : 12; /**< [ 91: 80] NR CP-OFDM PTRS resource element start index for [PTRS_MAP_TYPE] = 2.
                                                                 Note [PTRS_START_RE_IDX0] must be smaller than [PTRS_START_RE_IDX1]. */
        uint64_t reserved_92_95        : 4;
        uint64_t ue_vrb_start_idx      : 12; /**< [107: 96] Only for NR CP-OFDM with [PTRS_MAP_TYPE] = 1. Starting VRB idx for the UE allocation. */
        uint64_t reserved_108_111      : 4;
        uint64_t ptrs_re_offset3       : 4;  /**< [115:112] NR CP-OFDM PTRS resource element offset for [PTRS_MAP_TYPE] = 0. Refer to
                                                                 K_RE_ref as defined in the 3GPP standard. */
        uint64_t reserved_116_119      : 4;
        uint64_t ptrs_rb_offset1       : 2;  /**< [121:120] For NR CP-OFDM with [PTRS_MAP_TYPE] = 1, RB offset (K_RB_ref) for the odd numbered VRBs. */
        uint64_t reserved_122_123      : 2;
        uint64_t vrb_prb_bundle_size   : 3;  /**< [126:124] Bundle size for VRB to PRB mapping. Valid range is {2, 4}. */
        uint64_t reserved_127          : 1;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_184_191      : 8;
        uint64_t ptrs_start_re_idx1    : 12; /**< [183:172] NR CP-OFDM PTRS resource element start index for [PTRS_MAP_TYPE] = 1.
                                                                 Note [PTRS_START_RE_IDX1] must be larger than [PTRS_START_RE_IDX0]. */
        uint64_t reserved_166_171      : 6;
        uint64_t ptrs_num_re1          : 10; /**< [165:156] NR CP-OFDM PTRS number of resource elements starting from the RE index given by
                                                                 PTRS_START_RE_IDX1 for [PTRS_MAP_TYPE] = 2.
                                                                 Note [PTRS_START_RE_IDX1] must be larger than [PTRS_START_RE_IDX0]. */
        uint64_t reserved_155          : 1;
        uint64_t ack_enc_cat           : 3;  /**< [154:152] ACK encoding category, see DMAP_NR_ACK_ENC_CAT_E. */
        uint64_t reserved_148_151      : 4;
        uint64_t num_ack_re            : 12; /**< [147:136] Number of ACK REs. */
        uint64_t reserved_133_135      : 3;
        uint64_t ack_bit_idx           : 5;  /**< [132:128] Starting ACK bit index for soft combining. */
#else /* Word 2 - Little Endian */
        uint64_t ack_bit_idx           : 5;  /**< [132:128] Starting ACK bit index for soft combining. */
        uint64_t reserved_133_135      : 3;
        uint64_t num_ack_re            : 12; /**< [147:136] Number of ACK REs. */
        uint64_t reserved_148_151      : 4;
        uint64_t ack_enc_cat           : 3;  /**< [154:152] ACK encoding category, see DMAP_NR_ACK_ENC_CAT_E. */
        uint64_t reserved_155          : 1;
        uint64_t ptrs_num_re1          : 10; /**< [165:156] NR CP-OFDM PTRS number of resource elements starting from the RE index given by
                                                                 PTRS_START_RE_IDX1 for [PTRS_MAP_TYPE] = 2.
                                                                 Note [PTRS_START_RE_IDX1] must be larger than [PTRS_START_RE_IDX0]. */
        uint64_t reserved_166_171      : 6;
        uint64_t ptrs_start_re_idx1    : 12; /**< [183:172] NR CP-OFDM PTRS resource element start index for [PTRS_MAP_TYPE] = 1.
                                                                 Note [PTRS_START_RE_IDX1] must be larger than [PTRS_START_RE_IDX0]. */
        uint64_t reserved_184_191      : 8;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_248_255      : 8;
        uint64_t d_ack                 : 12; /**< [247:236] Distance parameter for ACK. */
        uint64_t reserved_235          : 1;
        uint64_t csi1_enc_cat          : 3;  /**< [234:232] CSI1 encoding category, see DMAP_CSI1_ENC_CAT_E. */
        uint64_t reserved_228_231      : 4;
        uint64_t num_csi1_re           : 12; /**< [227:216] Number of CSI1 REs. For [PROCESSING_TYPE] = 7, this represents the number of
                                                                 CSI1 REs after despreading. */
        uint64_t reserved_212_215      : 4;
        uint64_t d_csi1                : 12; /**< [211:200] Distance parameter for CSI1. Must be 1 for [PROCESSING_TYPE] = 7. */
        uint64_t reserved_197_199      : 3;
        uint64_t csi1_bit_idx          : 5;  /**< [196:192] Starting CSI1 bit index for soft combining. */
#else /* Word 3 - Little Endian */
        uint64_t csi1_bit_idx          : 5;  /**< [196:192] Starting CSI1 bit index for soft combining. */
        uint64_t reserved_197_199      : 3;
        uint64_t d_csi1                : 12; /**< [211:200] Distance parameter for CSI1. Must be 1 for [PROCESSING_TYPE] = 7. */
        uint64_t reserved_212_215      : 4;
        uint64_t num_csi1_re           : 12; /**< [227:216] Number of CSI1 REs. For [PROCESSING_TYPE] = 7, this represents the number of
                                                                 CSI1 REs after despreading. */
        uint64_t reserved_228_231      : 4;
        uint64_t csi1_enc_cat          : 3;  /**< [234:232] CSI1 encoding category, see DMAP_CSI1_ENC_CAT_E. */
        uint64_t reserved_235          : 1;
        uint64_t d_ack                 : 12; /**< [247:236] Distance parameter for ACK. */
        uint64_t reserved_248_255      : 8;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_296_319      : 24;
        uint64_t num_rvd_re            : 12; /**< [295:284] Number of reserved REs. */
        uint64_t reserved_280_283      : 4;
        uint64_t d_rvd                 : 12; /**< [279:268] Distance parameter for reserved REs. */
        uint64_t reserved_263_267      : 5;
        uint64_t pucch4_spread_seq_id  : 3;  /**< [262:260] PUCCH format 4 spreading sequence identifier (only for
                                                                 DMAP(0..1)_JD(0..2)_CFG0[PROCESSING_TYPE] = NR_PUCCH_F4). Valid range is [4,0]. */
        uint64_t reserved_257_259      : 3;
        uint64_t pucch4_spread_type    : 1;  /**< [256:256] PUCCH format 4 spreading type (only for DMAP(0..1)_JD(0..2)_CFG0[POCESSING_TYPE] = 7)
                                                                 0x0 = Spreading factor of 2 (N_SF = 2).
                                                                 0x1 = Spreading factor of 4 (N_SF = 4). */
#else /* Word 4 - Little Endian */
        uint64_t pucch4_spread_type    : 1;  /**< [256:256] PUCCH format 4 spreading type (only for DMAP(0..1)_JD(0..2)_CFG0[POCESSING_TYPE] = 7)
                                                                 0x0 = Spreading factor of 2 (N_SF = 2).
                                                                 0x1 = Spreading factor of 4 (N_SF = 4). */
        uint64_t reserved_257_259      : 3;
        uint64_t pucch4_spread_seq_id  : 3;  /**< [262:260] PUCCH format 4 spreading sequence identifier (only for
                                                                 DMAP(0..1)_JD(0..2)_CFG0[PROCESSING_TYPE] = NR_PUCCH_F4). Valid range is [4,0]. */
        uint64_t reserved_263_267      : 5;
        uint64_t d_rvd                 : 12; /**< [279:268] Distance parameter for reserved REs. */
        uint64_t reserved_280_283      : 4;
        uint64_t num_rvd_re            : 12; /**< [295:284] Number of reserved REs. */
        uint64_t reserved_296_319      : 24;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_356_383      : 28;
        uint64_t num_csi2_re0          : 12; /**< [355:344] Number of CSI2 REs hypothesis 0. */
        uint64_t reserved_340_343      : 4;
        uint64_t d_csi20               : 12; /**< [339:328] Distance parameter for CSI2 Res hypothesis 0. */
        uint64_t reserved_325_327      : 3;
        uint64_t csi2_bit_idx0         : 5;  /**< [324:320] Starting CSI2 bit index for soft combining hypothesis 0. */
#else /* Word 5 - Little Endian */
        uint64_t csi2_bit_idx0         : 5;  /**< [324:320] Starting CSI2 bit index for soft combining hypothesis 0. */
        uint64_t reserved_325_327      : 3;
        uint64_t d_csi20               : 12; /**< [339:328] Distance parameter for CSI2 Res hypothesis 0. */
        uint64_t reserved_340_343      : 4;
        uint64_t num_csi2_re0          : 12; /**< [355:344] Number of CSI2 REs hypothesis 0. */
        uint64_t reserved_356_383      : 28;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_420_447      : 28;
        uint64_t num_csi2_re1          : 12; /**< [419:408] Number of CSI2 REs hypothesis 1. */
        uint64_t reserved_404_407      : 4;
        uint64_t d_csi21               : 12; /**< [403:392] Distance parameter for CSI2 Res hypothesis 1. */
        uint64_t reserved_389_391      : 3;
        uint64_t csi2_bit_idx1         : 5;  /**< [388:384] Starting CSI2 bit index for soft combining hypothesis 1. */
#else /* Word 6 - Little Endian */
        uint64_t csi2_bit_idx1         : 5;  /**< [388:384] Starting CSI2 bit index for soft combining hypothesis 1. */
        uint64_t reserved_389_391      : 3;
        uint64_t d_csi21               : 12; /**< [403:392] Distance parameter for CSI2 Res hypothesis 1. */
        uint64_t reserved_404_407      : 4;
        uint64_t num_csi2_re1          : 12; /**< [419:408] Number of CSI2 REs hypothesis 1. */
        uint64_t reserved_420_447      : 28;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t reserved_484_511      : 28;
        uint64_t num_csi2_re2          : 12; /**< [483:472] Number of CSI2 Res hypothesis 2. */
        uint64_t reserved_468_471      : 4;
        uint64_t d_csi22               : 12; /**< [467:456] Distance parameter for CSI2 REs hypothesis 2. */
        uint64_t reserved_453_455      : 3;
        uint64_t csi2_bit_idx2         : 5;  /**< [452:448] Starting CSI2 bit index for soft combining hypothesis 2. */
#else /* Word 7 - Little Endian */
        uint64_t csi2_bit_idx2         : 5;  /**< [452:448] Starting CSI2 bit index for soft combining hypothesis 2. */
        uint64_t reserved_453_455      : 3;
        uint64_t d_csi22               : 12; /**< [467:456] Distance parameter for CSI2 REs hypothesis 2. */
        uint64_t reserved_468_471      : 4;
        uint64_t num_csi2_re2          : 12; /**< [483:472] Number of CSI2 Res hypothesis 2. */
        uint64_t reserved_484_511      : 28;
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t reserved_548_575      : 28;
        uint64_t num_csi2_re3          : 12; /**< [547:536] Number of CSI2 REs hypothesis 3. */
        uint64_t reserved_532_535      : 4;
        uint64_t d_csi23               : 12; /**< [531:520] Distance parameter for CSI2 REs hypothesis 3. */
        uint64_t reserved_517_519      : 3;
        uint64_t csi2_bit_idx3         : 5;  /**< [516:512] Starting CSI2 bit index for soft combining hypothesis 3. */
#else /* Word 8 - Little Endian */
        uint64_t csi2_bit_idx3         : 5;  /**< [516:512] Starting CSI2 bit index for soft combining hypothesis 3. */
        uint64_t reserved_517_519      : 3;
        uint64_t d_csi23               : 12; /**< [531:520] Distance parameter for CSI2 REs hypothesis 3. */
        uint64_t reserved_532_535      : 4;
        uint64_t num_csi2_re3          : 12; /**< [547:536] Number of CSI2 REs hypothesis 3. */
        uint64_t reserved_548_575      : 28;
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t reserved_612_639      : 28;
        uint64_t num_csi2_re4          : 12; /**< [611:600] Number of CSI2 Res hypothesis 4. */
        uint64_t reserved_596_599      : 4;
        uint64_t d_csi24               : 12; /**< [595:584] Distance parameter for CSI2 REs hypothesis 4. */
        uint64_t reserved_581_583      : 3;
        uint64_t csi2_bit_idx4         : 5;  /**< [580:576] Starting CSI2 bit index for soft combining hypothesis 4. */
#else /* Word 9 - Little Endian */
        uint64_t csi2_bit_idx4         : 5;  /**< [580:576] Starting CSI2 bit index for soft combining hypothesis 4. */
        uint64_t reserved_581_583      : 3;
        uint64_t d_csi24               : 12; /**< [595:584] Distance parameter for CSI2 REs hypothesis 4. */
        uint64_t reserved_596_599      : 4;
        uint64_t num_csi2_re4          : 12; /**< [611:600] Number of CSI2 Res hypothesis 4. */
        uint64_t reserved_612_639      : 28;
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t reserved_676_703      : 28;
        uint64_t num_csi2_re5          : 12; /**< [675:664] Number of CSI2 REs hypothesis 5. */
        uint64_t reserved_660_663      : 4;
        uint64_t d_csi25               : 12; /**< [659:648] Distance parameter for CSI2 REs hypothesis 5. */
        uint64_t reserved_645_647      : 3;
        uint64_t csi2_bit_idx5         : 5;  /**< [644:640] Starting CSI2 bit index for soft combining hypothesis 5. */
#else /* Word 10 - Little Endian */
        uint64_t csi2_bit_idx5         : 5;  /**< [644:640] Starting CSI2 bit index for soft combining hypothesis 5. */
        uint64_t reserved_645_647      : 3;
        uint64_t d_csi25               : 12; /**< [659:648] Distance parameter for CSI2 REs hypothesis 5. */
        uint64_t reserved_660_663      : 4;
        uint64_t num_csi2_re5          : 12; /**< [675:664] Number of CSI2 REs hypothesis 5. */
        uint64_t reserved_676_703      : 28;
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t reserved_740_767      : 28;
        uint64_t num_csi2_re6          : 12; /**< [739:728] Number of CSI2 REs hypothesis 6. */
        uint64_t reserved_724_727      : 4;
        uint64_t d_csi26               : 12; /**< [723:712] Distance parameter for CSI2 REs hypothesis 6. */
        uint64_t reserved_709_711      : 3;
        uint64_t csi2_bit_idx6         : 5;  /**< [708:704] Starting CSI2 bit index for soft combining hypothesis 6. */
#else /* Word 11 - Little Endian */
        uint64_t csi2_bit_idx6         : 5;  /**< [708:704] Starting CSI2 bit index for soft combining hypothesis 6. */
        uint64_t reserved_709_711      : 3;
        uint64_t d_csi26               : 12; /**< [723:712] Distance parameter for CSI2 REs hypothesis 6. */
        uint64_t reserved_724_727      : 4;
        uint64_t num_csi2_re6          : 12; /**< [739:728] Number of CSI2 REs hypothesis 6. */
        uint64_t reserved_740_767      : 28;
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t reserved_804_831      : 28;
        uint64_t num_csi2_re7          : 12; /**< [803:792] Number of CSI2 REs hypothesis 7. */
        uint64_t reserved_788_791      : 4;
        uint64_t d_csi27               : 12; /**< [787:776] Distance parameter for CSI2 REs hypothesis 7. */
        uint64_t reserved_773_775      : 3;
        uint64_t csi2_bit_idx7         : 5;  /**< [772:768] Starting CSI2 bit index for soft combining hypothesis 7. */
#else /* Word 12 - Little Endian */
        uint64_t csi2_bit_idx7         : 5;  /**< [772:768] Starting CSI2 bit index for soft combining hypothesis 7. */
        uint64_t reserved_773_775      : 3;
        uint64_t d_csi27               : 12; /**< [787:776] Distance parameter for CSI2 REs hypothesis 7. */
        uint64_t reserved_788_791      : 4;
        uint64_t num_csi2_re7          : 12; /**< [803:792] Number of CSI2 REs hypothesis 7. */
        uint64_t reserved_804_831      : 28;
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t reserved_868_895      : 28;
        uint64_t num_csi2_re8          : 12; /**< [867:856] Number of CSI2 REs hypothesis 8. */
        uint64_t reserved_852_855      : 4;
        uint64_t d_csi28               : 12; /**< [851:840] Distance parameter for CSI2 REs hypothesis 8. */
        uint64_t reserved_837_839      : 3;
        uint64_t csi2_bit_idx8         : 5;  /**< [836:832] Starting CSI2 bit index for soft combining hypothesis 8. */
#else /* Word 13 - Little Endian */
        uint64_t csi2_bit_idx8         : 5;  /**< [836:832] Starting CSI2 bit index for soft combining hypothesis 8. */
        uint64_t reserved_837_839      : 3;
        uint64_t d_csi28               : 12; /**< [851:840] Distance parameter for CSI2 REs hypothesis 8. */
        uint64_t reserved_852_855      : 4;
        uint64_t num_csi2_re8          : 12; /**< [867:856] Number of CSI2 REs hypothesis 8. */
        uint64_t reserved_868_895      : 28;
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t reserved_932_959      : 28;
        uint64_t num_csi2_re9          : 12; /**< [931:920] Number of CSI2 REs hypothesis 9. */
        uint64_t reserved_916_919      : 4;
        uint64_t d_csi29               : 12; /**< [915:904] Distance parameter for CSI2 REs hypothesis 9. */
        uint64_t reserved_901_903      : 3;
        uint64_t csi2_bit_idx9         : 5;  /**< [900:896] Starting CSI2 bit index for soft combining hypothesis 9. */
#else /* Word 14 - Little Endian */
        uint64_t csi2_bit_idx9         : 5;  /**< [900:896] Starting CSI2 bit index for soft combining hypothesis 9. */
        uint64_t reserved_901_903      : 3;
        uint64_t d_csi29               : 12; /**< [915:904] Distance parameter for CSI2 REs hypothesis 9. */
        uint64_t reserved_916_919      : 4;
        uint64_t num_csi2_re9          : 12; /**< [931:920] Number of CSI2 REs hypothesis 9. */
        uint64_t reserved_932_959      : 28;
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t reserved_996_1023     : 28;
        uint64_t num_csi2_re10         : 12; /**< [995:984] Number of CSI2 REs hypothesis 10. */
        uint64_t reserved_980_983      : 4;
        uint64_t d_csi210              : 12; /**< [979:968] Distance parameter for CSI2 REs hypothesis 10. */
        uint64_t reserved_965_967      : 3;
        uint64_t csi2_bit_idx10        : 5;  /**< [964:960] Starting CSI2 bit index for soft combining hypothesis 10. */
#else /* Word 15 - Little Endian */
        uint64_t csi2_bit_idx10        : 5;  /**< [964:960] Starting CSI2 bit index for soft combining hypothesis 10. */
        uint64_t reserved_965_967      : 3;
        uint64_t d_csi210              : 12; /**< [979:968] Distance parameter for CSI2 REs hypothesis 10. */
        uint64_t reserved_980_983      : 4;
        uint64_t num_csi2_re10         : 12; /**< [995:984] Number of CSI2 REs hypothesis 10. */
        uint64_t reserved_996_1023     : 28;
#endif /* Word 15 - End */
    } s;
    /* struct cavm_dmap_jd_nr_cfg_s_s cn; */
};

/**
 * Register (RSL) dmap#_bp_test0
 *
 * INTERNAL: DMAP Back Pressure Test 0 Register
 *
 * This register is used to stress internal Hardware backpressure points for Testing
 */
union cavm_dmapx_bp_test0
{
    uint64_t u;
    struct cavm_dmapx_bp_test0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = LDMP_IN_BUF_STALL.
                                                                 \<62\> = DESP_IN_STALL.
                                                                 \<61\> = GAIN_IN_STALL.
                                                                 \<60\> = DMAP_RDDMA_STALL. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Enable backpressure. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Enable backpressure. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = LDMP_IN_BUF_STALL.
                                                                 \<62\> = DESP_IN_STALL.
                                                                 \<61\> = GAIN_IN_STALL.
                                                                 \<60\> = DMAP_RDDMA_STALL. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_bp_test0_s cn; */
};
typedef union cavm_dmapx_bp_test0 cavm_dmapx_bp_test0_t;

static inline uint64_t CAVM_DMAPX_BP_TEST0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_BP_TEST0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043a80010ll + 0x80000ll * ((a) & 0x1);
    __cavm_csr_fatal("DMAPX_BP_TEST0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DMAPX_BP_TEST0(a) cavm_dmapx_bp_test0_t
#define bustype_CAVM_DMAPX_BP_TEST0(a) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_BP_TEST0(a) "DMAPX_BP_TEST0"
#define busnum_CAVM_DMAPX_BP_TEST0(a) (a)
#define arguments_CAVM_DMAPX_BP_TEST0(a) (a),-1,-1,-1

/**
 * Register (RSL) dmap#_bp_test1
 *
 * INTERNAL: DMAP Back Pressure Test 1 Register
 *
 * This register is used to stress internal Hardware backpressure points for Testing
 */
union cavm_dmapx_bp_test1
{
    uint64_t u;
    struct cavm_dmapx_bp_test1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = COM_IN_STALL.
                                                                 \<62\> = DESC_IN_STALL.
                                                                 \<61\> = SDMP_IN_STALL.
                                                                 \<60\> = RSRM_IN_STALL. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Enable backpressure. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Enable backpressure. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = COM_IN_STALL.
                                                                 \<62\> = DESC_IN_STALL.
                                                                 \<61\> = SDMP_IN_STALL.
                                                                 \<60\> = RSRM_IN_STALL. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_bp_test1_s cn; */
};
typedef union cavm_dmapx_bp_test1 cavm_dmapx_bp_test1_t;

static inline uint64_t CAVM_DMAPX_BP_TEST1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_BP_TEST1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043a80020ll + 0x80000ll * ((a) & 0x1);
    __cavm_csr_fatal("DMAPX_BP_TEST1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DMAPX_BP_TEST1(a) cavm_dmapx_bp_test1_t
#define bustype_CAVM_DMAPX_BP_TEST1(a) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_BP_TEST1(a) "DMAPX_BP_TEST1"
#define busnum_CAVM_DMAPX_BP_TEST1(a) (a)
#define arguments_CAVM_DMAPX_BP_TEST1(a) (a),-1,-1,-1

/**
 * Register (RSL) dmap#_bp_test2
 *
 * INTERNAL: DMAP Back Pressure Test2 Register
 *
 * This register is used to stress internal Hardware backpressure points for Testing
 */
union cavm_dmapx_bp_test2
{
    uint64_t u;
    struct cavm_dmapx_bp_test2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = reserved.
                                                                 \<62\> = reserved.
                                                                 \<61\> = MHBW_HR_STALL.
                                                                 \<60\> = DMAP_WRDMA_STALL */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Enable backpressure. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Enable backpressure. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = reserved.
                                                                 \<62\> = reserved.
                                                                 \<61\> = MHBW_HR_STALL.
                                                                 \<60\> = DMAP_WRDMA_STALL */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_bp_test2_s cn; */
};
typedef union cavm_dmapx_bp_test2 cavm_dmapx_bp_test2_t;

static inline uint64_t CAVM_DMAPX_BP_TEST2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_BP_TEST2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043a80028ll + 0x80000ll * ((a) & 0x1);
    __cavm_csr_fatal("DMAPX_BP_TEST2", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DMAPX_BP_TEST2(a) cavm_dmapx_bp_test2_t
#define bustype_CAVM_DMAPX_BP_TEST2(a) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_BP_TEST2(a) "DMAPX_BP_TEST2"
#define busnum_CAVM_DMAPX_BP_TEST2(a) (a)
#define arguments_CAVM_DMAPX_BP_TEST2(a) (a),-1,-1,-1

/**
 * Register (RSL) dmap#_control
 *
 * DMAP Control Register
 */
union cavm_dmapx_control
{
    uint64_t u;
    struct cavm_dmapx_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jobid2                : 16; /**< [ 63: 48](R/W) Job ID for slot 1. */
        uint64_t jobid1                : 16; /**< [ 47: 32](R/W) Job ID for slot 1. */
        uint64_t jobid0                : 16; /**< [ 31: 16](R/W) Job ID for slot 0. */
        uint64_t reserved_3_15         : 13;
        uint64_t start2                : 1;  /**< [  2:  2](R/W/H) Start processing job in slot 1. */
        uint64_t start1                : 1;  /**< [  1:  1](R/W/H) Start processing job in slot 1. */
        uint64_t start0                : 1;  /**< [  0:  0](R/W/H) Start processing job in slot 0. */
#else /* Word 0 - Little Endian */
        uint64_t start0                : 1;  /**< [  0:  0](R/W/H) Start processing job in slot 0. */
        uint64_t start1                : 1;  /**< [  1:  1](R/W/H) Start processing job in slot 1. */
        uint64_t start2                : 1;  /**< [  2:  2](R/W/H) Start processing job in slot 1. */
        uint64_t reserved_3_15         : 13;
        uint64_t jobid0                : 16; /**< [ 31: 16](R/W) Job ID for slot 0. */
        uint64_t jobid1                : 16; /**< [ 47: 32](R/W) Job ID for slot 1. */
        uint64_t jobid2                : 16; /**< [ 63: 48](R/W) Job ID for slot 1. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_control_s cn; */
};
typedef union cavm_dmapx_control cavm_dmapx_control_t;

static inline uint64_t CAVM_DMAPX_CONTROL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_CONTROL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043a80000ll + 0x80000ll * ((a) & 0x1);
    __cavm_csr_fatal("DMAPX_CONTROL", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DMAPX_CONTROL(a) cavm_dmapx_control_t
#define bustype_CAVM_DMAPX_CONTROL(a) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_CONTROL(a) "DMAPX_CONTROL"
#define busnum_CAVM_DMAPX_CONTROL(a) (a)
#define arguments_CAVM_DMAPX_CONTROL(a) (a),-1,-1,-1

/**
 * Register (RSL) dmap#_eco
 *
 * INTERNAL: DMAP ECO Register
 *
 * An ECO CSR
 */
union cavm_dmapx_eco
{
    uint64_t u;
    struct cavm_dmapx_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_eco_s cn; */
};
typedef union cavm_dmapx_eco cavm_dmapx_eco_t;

static inline uint64_t CAVM_DMAPX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_ECO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043a80008ll + 0x80000ll * ((a) & 0x1);
    __cavm_csr_fatal("DMAPX_ECO", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DMAPX_ECO(a) cavm_dmapx_eco_t
#define bustype_CAVM_DMAPX_ECO(a) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_ECO(a) "DMAPX_ECO"
#define busnum_CAVM_DMAPX_ECO(a) (a)
#define arguments_CAVM_DMAPX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) dmap#_jd#_cfg0
 *
 * DMAP Job Configuration Register 0
 */
union cavm_dmapx_jdx_cfg0
{
    uint64_t u;
    struct cavm_dmapx_jdx_cfg0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t sinr_calc_bypass      : 1;  /**< [ 59: 59](R/W) Set to 1 for SINR calculation bypass. */
        uint64_t gain_norm_bypass      : 1;  /**< [ 58: 58](R/W) Set to 1 for GAIN normalisation bypass. */
        uint64_t dft_bypass            : 1;  /**< [ 57: 57](R/W) Set to 1 for IDFT/DFT bypass. */
        uint64_t despreader_bypass     : 1;  /**< [ 56: 56](R/W) Set to 1 for Despreading operation bypass. Feature required for PUCCH format 4. */
        uint64_t layer_dmp_bypass      : 1;  /**< [ 55: 55](R/W) Set to 1 for Layer Demapper bypass. */
        uint64_t rs_removal_bypass     : 1;  /**< [ 54: 54](R/W) Set to 1 for RS Removal bypass. */
        uint64_t soft_dmp_bypass       : 1;  /**< [ 53: 53](R/W) Set to 1 for Soft Demapper bypass. */
        uint64_t descrambler_bypass    : 1;  /**< [ 52: 52](R/W) Descrambler bypass. Set to 1 to bypass the descrambler and all
                                                                 subsequent processing. */
        uint64_t reserved_48_51        : 4;
        uint64_t processing_type       : 4;  /**< [ 47: 44](R/W) DMAP processing type, see DMAP_PROC_TYPE_E. */
        uint64_t reserved_40_43        : 4;
        uint64_t num_sym               : 4;  /**< [ 39: 36](R/W) Number of symbols to be processed. */
        uint64_t reserved_33_35        : 3;
        uint64_t num_rb                : 9;  /**< [ 32: 24](R/W) Number of RBs for CP-OFDM case. For other cases, [NDFT_INDX] indicates the number of RBs. */
        uint64_t reserved_20_23        : 4;
        uint64_t num_sc_nonrs          : 12; /**< [ 19:  8](R/W) Number of subcarriers excluding PTRS or DMRS. For LTE, this will be equivalent
                                                                 to 12*[NUM_RB], where [NUM_RB] is the number of RBs pointed by the [NDFT_INDX]
                                                                 index.
                                                                 It represents the number of subcarrier after RS removal block. For
                                                                 [PROCESSING_TYPE] = 7, this will be equal to 12/spreading_factor. */
        uint64_t reserved_5_7          : 3;
        uint64_t configured_sinr       : 5;  /**< [  4:  0](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation. */
#else /* Word 0 - Little Endian */
        uint64_t configured_sinr       : 5;  /**< [  4:  0](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation. */
        uint64_t reserved_5_7          : 3;
        uint64_t num_sc_nonrs          : 12; /**< [ 19:  8](R/W) Number of subcarriers excluding PTRS or DMRS. For LTE, this will be equivalent
                                                                 to 12*[NUM_RB], where [NUM_RB] is the number of RBs pointed by the [NDFT_INDX]
                                                                 index.
                                                                 It represents the number of subcarrier after RS removal block. For
                                                                 [PROCESSING_TYPE] = 7, this will be equal to 12/spreading_factor. */
        uint64_t reserved_20_23        : 4;
        uint64_t num_rb                : 9;  /**< [ 32: 24](R/W) Number of RBs for CP-OFDM case. For other cases, [NDFT_INDX] indicates the number of RBs. */
        uint64_t reserved_33_35        : 3;
        uint64_t num_sym               : 4;  /**< [ 39: 36](R/W) Number of symbols to be processed. */
        uint64_t reserved_40_43        : 4;
        uint64_t processing_type       : 4;  /**< [ 47: 44](R/W) DMAP processing type, see DMAP_PROC_TYPE_E. */
        uint64_t reserved_48_51        : 4;
        uint64_t descrambler_bypass    : 1;  /**< [ 52: 52](R/W) Descrambler bypass. Set to 1 to bypass the descrambler and all
                                                                 subsequent processing. */
        uint64_t soft_dmp_bypass       : 1;  /**< [ 53: 53](R/W) Set to 1 for Soft Demapper bypass. */
        uint64_t rs_removal_bypass     : 1;  /**< [ 54: 54](R/W) Set to 1 for RS Removal bypass. */
        uint64_t layer_dmp_bypass      : 1;  /**< [ 55: 55](R/W) Set to 1 for Layer Demapper bypass. */
        uint64_t despreader_bypass     : 1;  /**< [ 56: 56](R/W) Set to 1 for Despreading operation bypass. Feature required for PUCCH format 4. */
        uint64_t dft_bypass            : 1;  /**< [ 57: 57](R/W) Set to 1 for IDFT/DFT bypass. */
        uint64_t gain_norm_bypass      : 1;  /**< [ 58: 58](R/W) Set to 1 for GAIN normalisation bypass. */
        uint64_t sinr_calc_bypass      : 1;  /**< [ 59: 59](R/W) Set to 1 for SINR calculation bypass. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_jdx_cfg0_s cn; */
};
typedef union cavm_dmapx_jdx_cfg0 cavm_dmapx_jdx_cfg0_t;

static inline uint64_t CAVM_DMAPX_JDX_CFG0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_JDX_CFG0(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=2)))
        return 0x87e043a82000ll + 0x80000ll * ((a) & 0x1) + 0x2000ll * ((b) & 0x3);
    __cavm_csr_fatal("DMAPX_JDX_CFG0", 2, a, b, 0, 0);
}

#define typedef_CAVM_DMAPX_JDX_CFG0(a,b) cavm_dmapx_jdx_cfg0_t
#define bustype_CAVM_DMAPX_JDX_CFG0(a,b) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_JDX_CFG0(a,b) "DMAPX_JDX_CFG0"
#define busnum_CAVM_DMAPX_JDX_CFG0(a,b) (a)
#define arguments_CAVM_DMAPX_JDX_CFG0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dmap#_jd#_cfg1
 *
 * DMAP Job Configuration Register 1
 */
union cavm_dmapx_jdx_cfg1
{
    uint64_t u;
    struct cavm_dmapx_jdx_cfg1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t bpsk_freq_rot         : 1;  /**< [ 57: 57](R/W) Set to 1 for I+Q even subcarrier LLR generation and -I+Q odd subcarrier LLR generation.
                                                                 Set to 0 for only I+Q based LLR generation. */
        uint64_t dmp_special           : 1;  /**< [ 56: 56](R/W) Set to 1 for demapper to treat 1-bit and 2-bit ACK/RICSI1 REs a special way,
                                                                 considering only outermost corner constellation points. */
        uint64_t gain_norm_default     : 1;  /**< [ 55: 55](R/W) Applicable only if [GAIN_NORM_BYPASS] = 0.
                                                                 Set to 0 for I/Q samples to be normalized with the calculated normalized value.
                                                                 Set to 1 for I/Q samples to be normalized with the default value of 2^10. */
        uint64_t simo_rnn_irc_on       : 1;  /**< [ 54: 54](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation. */
        uint64_t sel_irc_mode_sym0     : 1;  /**< [ 53: 53](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 0. */
        uint64_t sel_irc_mode_sym1     : 1;  /**< [ 52: 52](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 1. */
        uint64_t sel_irc_mode_sym2     : 1;  /**< [ 51: 51](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 2. */
        uint64_t sel_irc_mode_sym3     : 1;  /**< [ 50: 50](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 3. */
        uint64_t sel_irc_mode_sym4     : 1;  /**< [ 49: 49](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 4. */
        uint64_t sel_irc_mode_sym5     : 1;  /**< [ 48: 48](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 5. */
        uint64_t sel_irc_mode_sym6     : 1;  /**< [ 47: 47](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 6. */
        uint64_t sel_irc_mode_sym7     : 1;  /**< [ 46: 46](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 7. */
        uint64_t sel_irc_mode_sym8     : 1;  /**< [ 45: 45](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 8. */
        uint64_t sel_irc_mode_sym9     : 1;  /**< [ 44: 44](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 9. */
        uint64_t sel_irc_mode_sym10    : 1;  /**< [ 43: 43](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 10. */
        uint64_t sel_irc_mode_sym11    : 1;  /**< [ 42: 42](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 11. */
        uint64_t tx_on                 : 1;  /**< [ 41: 41](R/W) Transmit diversity flag.
                                                                 Set to 1 for summation of measurements (Norm_gain, delta and mse) to be done
                                                                 over layers. [NUM_MEAS_LAYER] must be 2.
                                                                 Set to 0 for summation over HABs only. [NUM_MEAS_LAYER] must be 1. */
        uint64_t sinr_overwrite        : 1;  /**< [ 40: 40](R/W) pSINR overwrite control when equal to 0.
                                                                 Set to 0 to use pSINR as calculated.
                                                                 Set to 1 to replace SINR with SINR_EXT when SINR=0 */
        uint64_t reserved_38_39        : 2;
        uint64_t sinr_offset           : 10; /**< [ 37: 28](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation. */
        uint64_t reserved_0_27         : 28;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_27         : 28;
        uint64_t sinr_offset           : 10; /**< [ 37: 28](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation. */
        uint64_t reserved_38_39        : 2;
        uint64_t sinr_overwrite        : 1;  /**< [ 40: 40](R/W) pSINR overwrite control when equal to 0.
                                                                 Set to 0 to use pSINR as calculated.
                                                                 Set to 1 to replace SINR with SINR_EXT when SINR=0 */
        uint64_t tx_on                 : 1;  /**< [ 41: 41](R/W) Transmit diversity flag.
                                                                 Set to 1 for summation of measurements (Norm_gain, delta and mse) to be done
                                                                 over layers. [NUM_MEAS_LAYER] must be 2.
                                                                 Set to 0 for summation over HABs only. [NUM_MEAS_LAYER] must be 1. */
        uint64_t sel_irc_mode_sym11    : 1;  /**< [ 42: 42](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 11. */
        uint64_t sel_irc_mode_sym10    : 1;  /**< [ 43: 43](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 10. */
        uint64_t sel_irc_mode_sym9     : 1;  /**< [ 44: 44](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 9. */
        uint64_t sel_irc_mode_sym8     : 1;  /**< [ 45: 45](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 8. */
        uint64_t sel_irc_mode_sym7     : 1;  /**< [ 46: 46](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 7. */
        uint64_t sel_irc_mode_sym6     : 1;  /**< [ 47: 47](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 6. */
        uint64_t sel_irc_mode_sym5     : 1;  /**< [ 48: 48](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 5. */
        uint64_t sel_irc_mode_sym4     : 1;  /**< [ 49: 49](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 4. */
        uint64_t sel_irc_mode_sym3     : 1;  /**< [ 50: 50](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 3. */
        uint64_t sel_irc_mode_sym2     : 1;  /**< [ 51: 51](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 2. */
        uint64_t sel_irc_mode_sym1     : 1;  /**< [ 52: 52](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 1. */
        uint64_t sel_irc_mode_sym0     : 1;  /**< [ 53: 53](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation for symbol 0. */
        uint64_t simo_rnn_irc_on       : 1;  /**< [ 54: 54](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation. */
        uint64_t gain_norm_default     : 1;  /**< [ 55: 55](R/W) Applicable only if [GAIN_NORM_BYPASS] = 0.
                                                                 Set to 0 for I/Q samples to be normalized with the calculated normalized value.
                                                                 Set to 1 for I/Q samples to be normalized with the default value of 2^10. */
        uint64_t dmp_special           : 1;  /**< [ 56: 56](R/W) Set to 1 for demapper to treat 1-bit and 2-bit ACK/RICSI1 REs a special way,
                                                                 considering only outermost corner constellation points. */
        uint64_t bpsk_freq_rot         : 1;  /**< [ 57: 57](R/W) Set to 1 for I+Q even subcarrier LLR generation and -I+Q odd subcarrier LLR generation.
                                                                 Set to 0 for only I+Q based LLR generation. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_jdx_cfg1_s cn; */
};
typedef union cavm_dmapx_jdx_cfg1 cavm_dmapx_jdx_cfg1_t;

static inline uint64_t CAVM_DMAPX_JDX_CFG1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_JDX_CFG1(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=2)))
        return 0x87e043a82008ll + 0x80000ll * ((a) & 0x1) + 0x2000ll * ((b) & 0x3);
    __cavm_csr_fatal("DMAPX_JDX_CFG1", 2, a, b, 0, 0);
}

#define typedef_CAVM_DMAPX_JDX_CFG1(a,b) cavm_dmapx_jdx_cfg1_t
#define bustype_CAVM_DMAPX_JDX_CFG1(a,b) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_JDX_CFG1(a,b) "DMAPX_JDX_CFG1"
#define busnum_CAVM_DMAPX_JDX_CFG1(a,b) (a)
#define arguments_CAVM_DMAPX_JDX_CFG1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dmap#_jd#_cfg2
 *
 * DMAP Job Configuration Register 2
 */
union cavm_dmapx_jdx_cfg2
{
    uint64_t u;
    struct cavm_dmapx_jdx_cfg2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t sinr_pwr_deboost      : 13; /**< [ 60: 48](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation. */
        uint64_t reserved_44_47        : 4;
        uint64_t mod_scale             : 16; /**< [ 43: 28](R/W) Offset value used for calculating the norm_gain based pSINR value. */
        uint64_t reserved_26_27        : 2;
        uint64_t num_meas_hab          : 2;  /**< [ 25: 24](R/W) Number of HAB measurements for norm_gain, mse and delta. */
        uint64_t reserved_22_23        : 2;
        uint64_t num_meas_layer        : 2;  /**< [ 21: 20](R/W) Number of layer measurements for norm_gain, mse and delta. Must be 1 when [TX_ON] = 0. */
        uint64_t reserved_18_19        : 2;
        uint64_t sinr_type             : 2;  /**< [ 17: 16](R/W) SINR type, see DMAP_SINR_TYPE_E. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t sinr_type             : 2;  /**< [ 17: 16](R/W) SINR type, see DMAP_SINR_TYPE_E. */
        uint64_t reserved_18_19        : 2;
        uint64_t num_meas_layer        : 2;  /**< [ 21: 20](R/W) Number of layer measurements for norm_gain, mse and delta. Must be 1 when [TX_ON] = 0. */
        uint64_t reserved_22_23        : 2;
        uint64_t num_meas_hab          : 2;  /**< [ 25: 24](R/W) Number of HAB measurements for norm_gain, mse and delta. */
        uint64_t reserved_26_27        : 2;
        uint64_t mod_scale             : 16; /**< [ 43: 28](R/W) Offset value used for calculating the norm_gain based pSINR value. */
        uint64_t reserved_44_47        : 4;
        uint64_t sinr_pwr_deboost      : 13; /**< [ 60: 48](R/W) Parameter used in WH (Norm-gain-based) pSINR calculation. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_jdx_cfg2_s cn; */
};
typedef union cavm_dmapx_jdx_cfg2 cavm_dmapx_jdx_cfg2_t;

static inline uint64_t CAVM_DMAPX_JDX_CFG2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_JDX_CFG2(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=2)))
        return 0x87e043a82010ll + 0x80000ll * ((a) & 0x1) + 0x2000ll * ((b) & 0x3);
    __cavm_csr_fatal("DMAPX_JDX_CFG2", 2, a, b, 0, 0);
}

#define typedef_CAVM_DMAPX_JDX_CFG2(a,b) cavm_dmapx_jdx_cfg2_t
#define bustype_CAVM_DMAPX_JDX_CFG2(a,b) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_JDX_CFG2(a,b) "DMAPX_JDX_CFG2"
#define busnum_CAVM_DMAPX_JDX_CFG2(a,b) (a)
#define arguments_CAVM_DMAPX_JDX_CFG2(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dmap#_jd#_cfg3
 *
 * DMAP Job Configuration Register 3
 */
union cavm_dmapx_jdx_cfg3
{
    uint64_t u;
    struct cavm_dmapx_jdx_cfg3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dmp_comp_coeffq       : 16; /**< [ 63: 48](R/W) Imaginary part of complex coefficient applied to all REs befire soft demapping
                                                                 operation in Q14 format. */
        uint64_t dmp_comp_coeffi       : 16; /**< [ 47: 32](R/W) Real part of complex coefficient applied to all REs befire soft demapping operation in Q14 format. */
        uint64_t reserved_22_31        : 10;
        uint64_t ndft_indx             : 6;  /**< [ 21: 16](R/W) See DMAP_NDFT_IDX_E. */
        uint64_t reserved_13_15        : 3;
        uint64_t idft_dft              : 1;  /**< [ 12: 12](R/W) Set to 0 for DFT or 1 for IDFT. */
        uint64_t reserved_9_11         : 3;
        uint64_t rs_bits_last          : 5;  /**< [  8:  4](R/W) Parameter used to control the output scaling at the last stage of DFT/IDFT.
                                                                 Set to 15 for unity DFT gain. */
        uint64_t reserved_3            : 1;
        uint64_t num_layers            : 3;  /**< [  2:  0](R/W) Number of layers
                                                                 0x0 = 1 layer
                                                                 0x2 = 2 layers
                                                                 0x3 = 3 layers
                                                                 0x4 = 4 layers
                                                                 For LTE, num_layers \<= 2
                                                                 For NR, num_layers \<= 4 */
#else /* Word 0 - Little Endian */
        uint64_t num_layers            : 3;  /**< [  2:  0](R/W) Number of layers
                                                                 0x0 = 1 layer
                                                                 0x2 = 2 layers
                                                                 0x3 = 3 layers
                                                                 0x4 = 4 layers
                                                                 For LTE, num_layers \<= 2
                                                                 For NR, num_layers \<= 4 */
        uint64_t reserved_3            : 1;
        uint64_t rs_bits_last          : 5;  /**< [  8:  4](R/W) Parameter used to control the output scaling at the last stage of DFT/IDFT.
                                                                 Set to 15 for unity DFT gain. */
        uint64_t reserved_9_11         : 3;
        uint64_t idft_dft              : 1;  /**< [ 12: 12](R/W) Set to 0 for DFT or 1 for IDFT. */
        uint64_t reserved_13_15        : 3;
        uint64_t ndft_indx             : 6;  /**< [ 21: 16](R/W) See DMAP_NDFT_IDX_E. */
        uint64_t reserved_22_31        : 10;
        uint64_t dmp_comp_coeffi       : 16; /**< [ 47: 32](R/W) Real part of complex coefficient applied to all REs befire soft demapping operation in Q14 format. */
        uint64_t dmp_comp_coeffq       : 16; /**< [ 63: 48](R/W) Imaginary part of complex coefficient applied to all REs befire soft demapping
                                                                 operation in Q14 format. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_jdx_cfg3_s cn; */
};
typedef union cavm_dmapx_jdx_cfg3 cavm_dmapx_jdx_cfg3_t;

static inline uint64_t CAVM_DMAPX_JDX_CFG3(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_JDX_CFG3(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=2)))
        return 0x87e043a82018ll + 0x80000ll * ((a) & 0x1) + 0x2000ll * ((b) & 0x3);
    __cavm_csr_fatal("DMAPX_JDX_CFG3", 2, a, b, 0, 0);
}

#define typedef_CAVM_DMAPX_JDX_CFG3(a,b) cavm_dmapx_jdx_cfg3_t
#define bustype_CAVM_DMAPX_JDX_CFG3(a,b) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_JDX_CFG3(a,b) "DMAPX_JDX_CFG3"
#define busnum_CAVM_DMAPX_JDX_CFG3(a,b) (a)
#define arguments_CAVM_DMAPX_JDX_CFG3(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dmap#_jd#_cfg4
 *
 * DMAP Job Configuration Register 4
 */
union cavm_dmapx_jdx_cfg4
{
    uint64_t u;
    struct cavm_dmapx_jdx_cfg4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t mod_order             : 4;  /**< [ 51: 48](R/W) Modulation order, see DMAP_MOD_ORDER_E. */
        uint64_t reserved_44_47        : 4;
        uint64_t q_format              : 4;  /**< [ 43: 40](R/W) Fixed point Q format for the demapper. */
        uint64_t reserved_36_39        : 4;
        uint64_t scaled_sinr_rsft      : 4;  /**< [ 35: 32](R/W) Right shift applied after multiplying SCALE by SINR. Refer to RS1 in figure 2.17. */
        uint64_t reserved_30_31        : 2;
        uint64_t mod_rsft              : 6;  /**< [ 29: 24](R/W) Modulation dependent right shift factor. Refer to RS2 in figure 2.17. */
        uint64_t reserved_20_23        : 4;
        uint64_t llr_bit_width         : 4;  /**< [ 19: 16](R/W) LLR bit width. Must be either 6, 7, or 8. */
        uint64_t reserved_15           : 1;
        uint64_t llr_offset_input      : 7;  /**< [ 14:  8](R/W) LLR offset value ranging from 0 to 2^([LLR_BIT_WIDTH]-1)-1. */
        uint64_t reserved_5_7          : 3;
        uint64_t des_offset            : 1;  /**< [  4:  4](R/W) Set to 0 for no offset added to LFSR states. Set to 1 to add a 1600 offset to the LFSR states. */
        uint64_t reserved_1_3          : 3;
        uint64_t layer_id              : 1;  /**< [  0:  0](R/W) Layer identifier (LTE only).
                                                                 0 = layer 0.
                                                                 1 = layer 1.

                                                                 Must be zero if [NUM_LAYERS]=1 and for non-LTE scenarios. */
#else /* Word 0 - Little Endian */
        uint64_t layer_id              : 1;  /**< [  0:  0](R/W) Layer identifier (LTE only).
                                                                 0 = layer 0.
                                                                 1 = layer 1.

                                                                 Must be zero if [NUM_LAYERS]=1 and for non-LTE scenarios. */
        uint64_t reserved_1_3          : 3;
        uint64_t des_offset            : 1;  /**< [  4:  4](R/W) Set to 0 for no offset added to LFSR states. Set to 1 to add a 1600 offset to the LFSR states. */
        uint64_t reserved_5_7          : 3;
        uint64_t llr_offset_input      : 7;  /**< [ 14:  8](R/W) LLR offset value ranging from 0 to 2^([LLR_BIT_WIDTH]-1)-1. */
        uint64_t reserved_15           : 1;
        uint64_t llr_bit_width         : 4;  /**< [ 19: 16](R/W) LLR bit width. Must be either 6, 7, or 8. */
        uint64_t reserved_20_23        : 4;
        uint64_t mod_rsft              : 6;  /**< [ 29: 24](R/W) Modulation dependent right shift factor. Refer to RS2 in figure 2.17. */
        uint64_t reserved_30_31        : 2;
        uint64_t scaled_sinr_rsft      : 4;  /**< [ 35: 32](R/W) Right shift applied after multiplying SCALE by SINR. Refer to RS1 in figure 2.17. */
        uint64_t reserved_36_39        : 4;
        uint64_t q_format              : 4;  /**< [ 43: 40](R/W) Fixed point Q format for the demapper. */
        uint64_t reserved_44_47        : 4;
        uint64_t mod_order             : 4;  /**< [ 51: 48](R/W) Modulation order, see DMAP_MOD_ORDER_E. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_jdx_cfg4_s cn; */
};
typedef union cavm_dmapx_jdx_cfg4 cavm_dmapx_jdx_cfg4_t;

static inline uint64_t CAVM_DMAPX_JDX_CFG4(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_JDX_CFG4(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=2)))
        return 0x87e043a82020ll + 0x80000ll * ((a) & 0x1) + 0x2000ll * ((b) & 0x3);
    __cavm_csr_fatal("DMAPX_JDX_CFG4", 2, a, b, 0, 0);
}

#define typedef_CAVM_DMAPX_JDX_CFG4(a,b) cavm_dmapx_jdx_cfg4_t
#define bustype_CAVM_DMAPX_JDX_CFG4(a,b) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_JDX_CFG4(a,b) "DMAPX_JDX_CFG4"
#define busnum_CAVM_DMAPX_JDX_CFG4(a,b) (a)
#define arguments_CAVM_DMAPX_JDX_CFG4(a,b) (a),(b),-1,-1

/**
 * Register (RSL) dmap#_jd#_lte_nr_cfg#
 *
 * DMAP Job Configuration Register 5
 */
union cavm_dmapx_jdx_lte_nr_cfgx
{
    uint64_t u;
    struct cavm_dmapx_jdx_lte_nr_cfgx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Generic register used either for LTE or NR configuration. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Generic register used either for LTE or NR configuration. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_jdx_lte_nr_cfgx_s cn; */
};
typedef union cavm_dmapx_jdx_lte_nr_cfgx cavm_dmapx_jdx_lte_nr_cfgx_t;

static inline uint64_t CAVM_DMAPX_JDX_LTE_NR_CFGX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_JDX_LTE_NR_CFGX(unsigned long a, unsigned long b, unsigned long c)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=2) && (c<=15)))
        return 0x87e043a82028ll + 0x80000ll * ((a) & 0x1) + 0x2000ll * ((b) & 0x3) + 8ll * ((c) & 0xf);
    __cavm_csr_fatal("DMAPX_JDX_LTE_NR_CFGX", 3, a, b, c, 0);
}

#define typedef_CAVM_DMAPX_JDX_LTE_NR_CFGX(a,b,c) cavm_dmapx_jdx_lte_nr_cfgx_t
#define bustype_CAVM_DMAPX_JDX_LTE_NR_CFGX(a,b,c) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_JDX_LTE_NR_CFGX(a,b,c) "DMAPX_JDX_LTE_NR_CFGX"
#define busnum_CAVM_DMAPX_JDX_LTE_NR_CFGX(a,b,c) (a)
#define arguments_CAVM_DMAPX_JDX_LTE_NR_CFGX(a,b,c) (a),(b),(c),-1

/**
 * Register (RSL) dmap#_status
 *
 * DMAP Status Register
 */
union cavm_dmapx_status
{
    uint64_t u;
    struct cavm_dmapx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t status2               : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t status1               : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t status0               : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t status0               : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
        uint64_t status1               : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t status2               : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dmapx_status_s cn; */
};
typedef union cavm_dmapx_status cavm_dmapx_status_t;

static inline uint64_t CAVM_DMAPX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DMAPX_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043a80018ll + 0x80000ll * ((a) & 0x1);
    __cavm_csr_fatal("DMAPX_STATUS", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DMAPX_STATUS(a) cavm_dmapx_status_t
#define bustype_CAVM_DMAPX_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_DMAPX_STATUS(a) "DMAPX_STATUS"
#define busnum_CAVM_DMAPX_STATUS(a) (a)
#define arguments_CAVM_DMAPX_STATUS(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_DMAP_H__ */
