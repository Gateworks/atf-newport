#ifndef __CAVM_CSRS_FDEQ_H__
#define __CAVM_CSRS_FDEQ_H__
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
 * OcteonTX FDEQ.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure fdeq_rdcfg_rb_ant_layer_s
 *
 * FDEQ Read DMA Antenna Layer Parameter Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_rb_ant_layer_s
{
    uint64_t u[2];
    struct cavm_fdeq_rdcfg_rb_ant_layer_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t ant_0_layer_1_rs3_irc_mode : 1;/**< [ 56: 56] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_1_rs2_irc_mode : 1;/**< [ 55: 55] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_1_rs1_irc_mode : 1;/**< [ 54: 54] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_1_rs0_irc_mode : 1;/**< [ 53: 53] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_g_fagc_rs_1     : 5;  /**< [ 52: 48] Refer to [ANT_0_G_FAGC_RS_0]. */
        uint64_t reserved_46_47        : 2;
        uint64_t ant_0_layer_1_amplitude : 14;/**< [ 45: 32] Refer to [ANT_0_LAYER_0_AMPLITUDE]. */
        uint64_t reserved_25_31        : 7;
        uint64_t ant_0_layer_0_rs3_irc_mode : 1;/**< [ 24: 24] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_0_rs2_irc_mode : 1;/**< [ 23: 23] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_0_rs1_irc_mode : 1;/**< [ 22: 22] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_0_rs0_irc_mode : 1;/**< [ 21: 21] In the name ANT_a_LAYER_l_RSr IRC_MODE, the triplet (a,l,r) refer to Receive
                                                                 antenna index, layer index and RS index. If set to 0x0, the off diagonal elements
                                                                 of the R matrix of antenna a and layer l, for RS r are forced to zero. */
        uint64_t ant_0_g_fagc_rs_0     : 5;  /**< [ 20: 16] In the name  ANT_a_G_FAGC_RS_r, the tuple (a,r) refer to Receive antenna index
                                                                 and RS index. This specifies the FAGC value of  RS r for antenna a.
                                                                 Valid range is [-16,15]. */
        uint64_t reserved_14_15        : 2;
        uint64_t ant_0_layer_0_amplitude : 14;/**< [ 13:  0] In the name ANT_0_LAYER_1_AMPLITUDE the tuple (a,l) refer to Receive antenna
                                                                 index, and Layer index. If the mth bit is set to 0x0, the hrs for (a,l) for mth
                                                                 DS is forced to 0. Otherwise it is used as is. */
#else /* Word 0 - Little Endian */
        uint64_t ant_0_layer_0_amplitude : 14;/**< [ 13:  0] In the name ANT_0_LAYER_1_AMPLITUDE the tuple (a,l) refer to Receive antenna
                                                                 index, and Layer index. If the mth bit is set to 0x0, the hrs for (a,l) for mth
                                                                 DS is forced to 0. Otherwise it is used as is. */
        uint64_t reserved_14_15        : 2;
        uint64_t ant_0_g_fagc_rs_0     : 5;  /**< [ 20: 16] In the name  ANT_a_G_FAGC_RS_r, the tuple (a,r) refer to Receive antenna index
                                                                 and RS index. This specifies the FAGC value of  RS r for antenna a.
                                                                 Valid range is [-16,15]. */
        uint64_t ant_0_layer_0_rs0_irc_mode : 1;/**< [ 21: 21] In the name ANT_a_LAYER_l_RSr IRC_MODE, the triplet (a,l,r) refer to Receive
                                                                 antenna index, layer index and RS index. If set to 0x0, the off diagonal elements
                                                                 of the R matrix of antenna a and layer l, for RS r are forced to zero. */
        uint64_t ant_0_layer_0_rs1_irc_mode : 1;/**< [ 22: 22] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_0_rs2_irc_mode : 1;/**< [ 23: 23] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_0_rs3_irc_mode : 1;/**< [ 24: 24] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t reserved_25_31        : 7;
        uint64_t ant_0_layer_1_amplitude : 14;/**< [ 45: 32] Refer to [ANT_0_LAYER_0_AMPLITUDE]. */
        uint64_t reserved_46_47        : 2;
        uint64_t ant_0_g_fagc_rs_1     : 5;  /**< [ 52: 48] Refer to [ANT_0_G_FAGC_RS_0]. */
        uint64_t ant_0_layer_1_rs0_irc_mode : 1;/**< [ 53: 53] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_1_rs1_irc_mode : 1;/**< [ 54: 54] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_1_rs2_irc_mode : 1;/**< [ 55: 55] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_1_rs3_irc_mode : 1;/**< [ 56: 56] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_121_127      : 7;
        uint64_t ant_0_layer_3_rs3_irc_mode : 1;/**< [120:120] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_3_rs2_irc_mode : 1;/**< [119:119] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_3_rs1_irc_mode : 1;/**< [118:118] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_3_rs0_irc_mode : 1;/**< [117:117] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_g_fagc_rs_3     : 5;  /**< [116:112] Refer to [ANT_0_G_FAGC_RS_0]. */
        uint64_t reserved_110_111      : 2;
        uint64_t ant_0_layer_3_amplitude : 14;/**< [109: 96] Refer to [ANT_0_LAYER_0_AMPLITUDE]. */
        uint64_t reserved_89_95        : 7;
        uint64_t ant_0_layer_2_rs3_irc_mode : 1;/**< [ 88: 88] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_2_rs2_irc_mode : 1;/**< [ 87: 87] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_2_rs1_irc_mode : 1;/**< [ 86: 86] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_2_rs0_irc_mode : 1;/**< [ 85: 85] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_g_fagc_rs_2     : 5;  /**< [ 84: 80] Refer to [ANT_0_G_FAGC_RS_0]. */
        uint64_t reserved_78_79        : 2;
        uint64_t ant_0_layer_2_amplitude : 14;/**< [ 77: 64] Refer to [ANT_0_LAYER_0_AMPLITUDE]. */
#else /* Word 1 - Little Endian */
        uint64_t ant_0_layer_2_amplitude : 14;/**< [ 77: 64] Refer to [ANT_0_LAYER_0_AMPLITUDE]. */
        uint64_t reserved_78_79        : 2;
        uint64_t ant_0_g_fagc_rs_2     : 5;  /**< [ 84: 80] Refer to [ANT_0_G_FAGC_RS_0]. */
        uint64_t ant_0_layer_2_rs0_irc_mode : 1;/**< [ 85: 85] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_2_rs1_irc_mode : 1;/**< [ 86: 86] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_2_rs2_irc_mode : 1;/**< [ 87: 87] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_2_rs3_irc_mode : 1;/**< [ 88: 88] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t reserved_89_95        : 7;
        uint64_t ant_0_layer_3_amplitude : 14;/**< [109: 96] Refer to [ANT_0_LAYER_0_AMPLITUDE]. */
        uint64_t reserved_110_111      : 2;
        uint64_t ant_0_g_fagc_rs_3     : 5;  /**< [116:112] Refer to [ANT_0_G_FAGC_RS_0]. */
        uint64_t ant_0_layer_3_rs0_irc_mode : 1;/**< [117:117] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_3_rs1_irc_mode : 1;/**< [118:118] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_3_rs2_irc_mode : 1;/**< [119:119] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t ant_0_layer_3_rs3_irc_mode : 1;/**< [120:120] Refer to [ANT_0_LAYER_0_RS0_IRC_MODE]. */
        uint64_t reserved_121_127      : 7;
#endif /* Word 1 - End */
    } s;
    /* struct cavm_fdeq_rdcfg_rb_ant_layer_s_s cn; */
};

/**
 * Structure fdeq_rdcfg_rb_params_jt0_s
 *
 * FDEQ DMA Read, job type 0 RB  Parameter Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_rb_params_jt0_s
{
    uint64_t u[2];
    struct cavm_fdeq_rdcfg_rb_params_jt0_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ue_idx_rs_0_2_layer_6_2 : 5;/**< [ 63: 59] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_0_2_layer_5_1 : 5;/**< [ 58: 54] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_0_2_layer_4_0 : 5;/**< [ 53: 49] In name field UE_IDX_RS_r_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond to
                                                                 a RS index and layer index pair. This parameter  indicates the index of UE that
                                                                 is mapped to the active RS and layer tuple. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l) is the active
                                                                 tuple otherwise (s,m) is the active tuple. */
        uint64_t ue_idx_rs0_layer3     : 5;  /**< [ 48: 44] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer2     : 5;  /**< [ 43: 39] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer1     : 5;  /**< [ 38: 34] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer0     : 5;  /**< [ 33: 29] In name field UE_IDX_RS_r_LAYER_l, the tuple (r,l) correspond to a RS index and
                                                                 layer index pair. This parameter  indicates the index of UE that is mapped to RS
                                                                 and layer tuple. */
        uint64_t layer_mode            : 2;  /**< [ 28: 27] Number of layers in this RB.
                                                                 0x0 = 1.
                                                                 0x1 = 2.
                                                                 0x2 = 4.
                                                                 0x3 = 8. */
        uint64_t subprb_ue3_enable     : 1;  /**< [ 26: 26] If set to 1, the  UE3 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue2_enable     : 1;  /**< [ 25: 25] If set to 1, the  UE2 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue1_enable     : 1;  /**< [ 24: 24] If set to 1, the  UE1 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue0_enable     : 1;  /**< [ 23: 23] If set to 1, the  UE0 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_case_index     : 3;  /**< [ 22: 20] Indicates the SubPRB allocation. See section Configuration steps for subPRB Ues. */
        uint64_t layer_enable_rs1_layer7 : 1;/**< [ 19: 19] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer6 : 1;/**< [ 18: 18] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer5 : 1;/**< [ 17: 17] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer4 : 1;/**< [ 16: 16] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer3 : 1;/**< [ 15: 15] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer2 : 1;/**< [ 14: 14] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer1 : 1;/**< [ 13: 13] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer0 : 1;/**< [ 12: 12] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer7 : 1;/**< [ 11: 11] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer6 : 1;/**< [ 10: 10] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer5 : 1;/**< [  9:  9] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer4 : 1;/**< [  8:  8] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer3 : 1;/**< [  7:  7] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer2 : 1;/**< [  6:  6] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer1 : 1;/**< [  5:  5] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer0 : 1;/**< [  4:  4] In name field LAYER_ENABLE_RS_r_LAYER_l, the tuple (r,l) correspond to a RS
                                                                 index and layer index pair. If set to 1, layer l is active on RS r. */
        uint64_t rnn_rb                : 3;  /**< [  3:  1] Indicates the number of RBs over which Rnn is averaged.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RBs.
                                                                 0x2 = 3 RBs.
                                                                 0x3 = 4 RBs.
                                                                 0x4 = 5 RBs.
                                                                 0x5 = 6 RBs.
                                                                 0x6 = 7 RBs.
                                                                 0x7 = 8 RBs. */
        uint64_t subprb_enable         : 1;  /**< [  0:  0] If set to 1, this RB is configured as Sub PRB. */
#else /* Word 0 - Little Endian */
        uint64_t subprb_enable         : 1;  /**< [  0:  0] If set to 1, this RB is configured as Sub PRB. */
        uint64_t rnn_rb                : 3;  /**< [  3:  1] Indicates the number of RBs over which Rnn is averaged.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RBs.
                                                                 0x2 = 3 RBs.
                                                                 0x3 = 4 RBs.
                                                                 0x4 = 5 RBs.
                                                                 0x5 = 6 RBs.
                                                                 0x6 = 7 RBs.
                                                                 0x7 = 8 RBs. */
        uint64_t layer_enable_rs0_layer0 : 1;/**< [  4:  4] In name field LAYER_ENABLE_RS_r_LAYER_l, the tuple (r,l) correspond to a RS
                                                                 index and layer index pair. If set to 1, layer l is active on RS r. */
        uint64_t layer_enable_rs0_layer1 : 1;/**< [  5:  5] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer2 : 1;/**< [  6:  6] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer3 : 1;/**< [  7:  7] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer4 : 1;/**< [  8:  8] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer5 : 1;/**< [  9:  9] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer6 : 1;/**< [ 10: 10] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer7 : 1;/**< [ 11: 11] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer0 : 1;/**< [ 12: 12] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer1 : 1;/**< [ 13: 13] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer2 : 1;/**< [ 14: 14] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer3 : 1;/**< [ 15: 15] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer4 : 1;/**< [ 16: 16] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer5 : 1;/**< [ 17: 17] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer6 : 1;/**< [ 18: 18] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer7 : 1;/**< [ 19: 19] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t subprb_case_index     : 3;  /**< [ 22: 20] Indicates the SubPRB allocation. See section Configuration steps for subPRB Ues. */
        uint64_t subprb_ue0_enable     : 1;  /**< [ 23: 23] If set to 1, the  UE0 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue1_enable     : 1;  /**< [ 24: 24] If set to 1, the  UE1 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue2_enable     : 1;  /**< [ 25: 25] If set to 1, the  UE2 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue3_enable     : 1;  /**< [ 26: 26] If set to 1, the  UE3 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t layer_mode            : 2;  /**< [ 28: 27] Number of layers in this RB.
                                                                 0x0 = 1.
                                                                 0x1 = 2.
                                                                 0x2 = 4.
                                                                 0x3 = 8. */
        uint64_t ue_idx_rs0_layer0     : 5;  /**< [ 33: 29] In name field UE_IDX_RS_r_LAYER_l, the tuple (r,l) correspond to a RS index and
                                                                 layer index pair. This parameter  indicates the index of UE that is mapped to RS
                                                                 and layer tuple. */
        uint64_t ue_idx_rs0_layer1     : 5;  /**< [ 38: 34] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer2     : 5;  /**< [ 43: 39] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer3     : 5;  /**< [ 48: 44] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs_0_2_layer_4_0 : 5;/**< [ 53: 49] In name field UE_IDX_RS_r_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond to
                                                                 a RS index and layer index pair. This parameter  indicates the index of UE that
                                                                 is mapped to the active RS and layer tuple. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l) is the active
                                                                 tuple otherwise (s,m) is the active tuple. */
        uint64_t ue_idx_rs_0_2_layer_5_1 : 5;/**< [ 58: 54] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_0_2_layer_6_2 : 5;/**< [ 63: 59] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_127          : 1;
        uint64_t hrs_offset_rs1_3_layer_7_3 : 1;/**< [126:126] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_6_2 : 1;/**< [125:125] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_5_1 : 1;/**< [124:124] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_4_0 : 1;/**< [123:123] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_layer3 : 1;  /**< [122:122] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer2 : 1;  /**< [121:121] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer1 : 1;  /**< [120:120] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer0 : 1;  /**< [119:119] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_2_layer_7_3 : 1;/**< [118:118] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_6_2 : 1;/**< [117:117] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_5_1 : 1;/**< [116:116] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_4_0 : 1;/**< [115:115] In name field HRS_OFFSET_RSr_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond
                                                                 to a RS index and layer index pair. The parameter indicates whether the hrs
                                                                 corresponding to the active RS and layer tuple  begins at word boundary or
                                                                 middle of word. When FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2,
                                                                 (r,l) is the active tuple otherwise (s,m) is the active tuple. */
        uint64_t hrs_offset_rs0_layer3 : 1;  /**< [114:114] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer2 : 1;  /**< [113:113] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer1 : 1;  /**< [112:112] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer0 : 1;  /**< [111:111] In name field HRS_OFFSET_RSr_LAYER_l, the tuple (r,l) correspond to a RS index
                                                                 and layer index pair. The parameter indicates whether the hrs corresponding to
                                                                 the active RS and layer tuple  begins at word boundary or middle of word. */
        uint64_t ryy_rb                : 2;  /**< [110:109] The number of RBs over which Ryy is averaged.
                                                                 0x0 = 1RB.
                                                                 0x1 = 2RBs.
                                                                 0x2 = 3RBs.
                                                                 0x3 = 4RBs. */
        uint64_t ue_idx_rs_1_3_layer_7_3 : 5;/**< [108:104] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_6_2 : 5;/**< [103: 99] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_5_1 : 5;/**< [ 98: 94] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_4_0 : 5;/**< [ 93: 89] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs1_layer3     : 5;  /**< [ 88: 84] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer2     : 5;  /**< [ 83: 79] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer1     : 5;  /**< [ 78: 74] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer0     : 5;  /**< [ 73: 69] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs_0_2_layer_7_3 : 5;/**< [ 68: 64] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
#else /* Word 1 - Little Endian */
        uint64_t ue_idx_rs_0_2_layer_7_3 : 5;/**< [ 68: 64] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs1_layer0     : 5;  /**< [ 73: 69] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer1     : 5;  /**< [ 78: 74] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer2     : 5;  /**< [ 83: 79] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer3     : 5;  /**< [ 88: 84] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs_1_3_layer_4_0 : 5;/**< [ 93: 89] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_5_1 : 5;/**< [ 98: 94] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_6_2 : 5;/**< [103: 99] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_7_3 : 5;/**< [108:104] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ryy_rb                : 2;  /**< [110:109] The number of RBs over which Ryy is averaged.
                                                                 0x0 = 1RB.
                                                                 0x1 = 2RBs.
                                                                 0x2 = 3RBs.
                                                                 0x3 = 4RBs. */
        uint64_t hrs_offset_rs0_layer0 : 1;  /**< [111:111] In name field HRS_OFFSET_RSr_LAYER_l, the tuple (r,l) correspond to a RS index
                                                                 and layer index pair. The parameter indicates whether the hrs corresponding to
                                                                 the active RS and layer tuple  begins at word boundary or middle of word. */
        uint64_t hrs_offset_rs0_layer1 : 1;  /**< [112:112] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer2 : 1;  /**< [113:113] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer3 : 1;  /**< [114:114] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_2_layer_4_0 : 1;/**< [115:115] In name field HRS_OFFSET_RSr_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond
                                                                 to a RS index and layer index pair. The parameter indicates whether the hrs
                                                                 corresponding to the active RS and layer tuple  begins at word boundary or
                                                                 middle of word. When FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2,
                                                                 (r,l) is the active tuple otherwise (s,m) is the active tuple. */
        uint64_t hrs_offset_rs0_2_layer_5_1 : 1;/**< [116:116] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_6_2 : 1;/**< [117:117] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_7_3 : 1;/**< [118:118] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_layer0 : 1;  /**< [119:119] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer1 : 1;  /**< [120:120] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer2 : 1;  /**< [121:121] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer3 : 1;  /**< [122:122] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_3_layer_4_0 : 1;/**< [123:123] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_5_1 : 1;/**< [124:124] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_6_2 : 1;/**< [125:125] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_7_3 : 1;/**< [126:126] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t reserved_127          : 1;
#endif /* Word 1 - End */
    } s;
    /* struct cavm_fdeq_rdcfg_rb_params_jt0_s_s cn; */
};

/**
 * Structure fdeq_rdcfg_rb_params_jt1_s
 *
 * FDEQ DMA Read, job type 1 RB  Parameter Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_rb_params_jt1_s
{
    uint64_t u[8];
    struct cavm_fdeq_rdcfg_rb_params_jt1_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ue_idx_rs_0_2_layer_6_2 : 5;/**< [ 63: 59] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_0_2_layer_5_1 : 5;/**< [ 58: 54] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_0_2_layer_4_0 : 5;/**< [ 53: 49] In name field UE_IDX_RS_r_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond to
                                                                 a RS index and layer index pair. This parameter  indicates the index of UE that
                                                                 is mapped to the active RS and layer tuple. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l) is the active
                                                                 tuple otherwise (s,m) is the active tuple. */
        uint64_t ue_idx_rs0_layer3     : 5;  /**< [ 48: 44] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer2     : 5;  /**< [ 43: 39] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer1     : 5;  /**< [ 38: 34] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer0     : 5;  /**< [ 33: 29] In name field UE_IDX_RS_r_LAYER_l, the tuple (r,l) correspond to a RS index and
                                                                 layer index pair. This parameter  indicates the index of UE that is mapped to RS
                                                                 and layer tuple. */
        uint64_t layer_mode            : 2;  /**< [ 28: 27] Number of layers in this RB.
                                                                 0x0 = 1.
                                                                 0x1 = 2.
                                                                 0x2 = 4.
                                                                 0x3 = 8. */
        uint64_t subprb_ue3_enable     : 1;  /**< [ 26: 26] If set to 1, the  UE3 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue2_enable     : 1;  /**< [ 25: 25] If set to 1, the  UE2 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue1_enable     : 1;  /**< [ 24: 24] If set to 1, the  UE1 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue0_enable     : 1;  /**< [ 23: 23] If set to 1, the  UE0 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_case_index     : 3;  /**< [ 22: 20] Indicates the SubPRB allocation. See section Configuration steps for subPRB Ues. */
        uint64_t layer_enable_rs1_layer7 : 1;/**< [ 19: 19] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer6 : 1;/**< [ 18: 18] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer5 : 1;/**< [ 17: 17] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer4 : 1;/**< [ 16: 16] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer3 : 1;/**< [ 15: 15] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer2 : 1;/**< [ 14: 14] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer1 : 1;/**< [ 13: 13] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer0 : 1;/**< [ 12: 12] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer7 : 1;/**< [ 11: 11] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer6 : 1;/**< [ 10: 10] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer5 : 1;/**< [  9:  9] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer4 : 1;/**< [  8:  8] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer3 : 1;/**< [  7:  7] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer2 : 1;/**< [  6:  6] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer1 : 1;/**< [  5:  5] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer0 : 1;/**< [  4:  4] In name field LAYER_ENABLE_RS_r_LAYER_l, the tuple (r,l) correspond to a RS
                                                                 index and layer index pair. If set to 1, layer l is active on RS r. */
        uint64_t rnn_rb                : 3;  /**< [  3:  1] Indicates the number of RBs over which Rnn is averaged.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RBs.
                                                                 0x2 = 3 RBs.
                                                                 0x3 = 4 RBs.
                                                                 0x4 = 5 RBs.
                                                                 0x5 = 6 RBs.
                                                                 0x6 = 7 RBs.
                                                                 0x7 = 8 RBs. */
        uint64_t subprb_enable         : 1;  /**< [  0:  0] If set to 1, this RB is configured as Sub PRB. */
#else /* Word 0 - Little Endian */
        uint64_t subprb_enable         : 1;  /**< [  0:  0] If set to 1, this RB is configured as Sub PRB. */
        uint64_t rnn_rb                : 3;  /**< [  3:  1] Indicates the number of RBs over which Rnn is averaged.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RBs.
                                                                 0x2 = 3 RBs.
                                                                 0x3 = 4 RBs.
                                                                 0x4 = 5 RBs.
                                                                 0x5 = 6 RBs.
                                                                 0x6 = 7 RBs.
                                                                 0x7 = 8 RBs. */
        uint64_t layer_enable_rs0_layer0 : 1;/**< [  4:  4] In name field LAYER_ENABLE_RS_r_LAYER_l, the tuple (r,l) correspond to a RS
                                                                 index and layer index pair. If set to 1, layer l is active on RS r. */
        uint64_t layer_enable_rs0_layer1 : 1;/**< [  5:  5] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer2 : 1;/**< [  6:  6] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer3 : 1;/**< [  7:  7] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer4 : 1;/**< [  8:  8] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer5 : 1;/**< [  9:  9] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer6 : 1;/**< [ 10: 10] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer7 : 1;/**< [ 11: 11] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer0 : 1;/**< [ 12: 12] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer1 : 1;/**< [ 13: 13] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer2 : 1;/**< [ 14: 14] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer3 : 1;/**< [ 15: 15] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer4 : 1;/**< [ 16: 16] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer5 : 1;/**< [ 17: 17] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer6 : 1;/**< [ 18: 18] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer7 : 1;/**< [ 19: 19] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t subprb_case_index     : 3;  /**< [ 22: 20] Indicates the SubPRB allocation. See section Configuration steps for subPRB Ues. */
        uint64_t subprb_ue0_enable     : 1;  /**< [ 23: 23] If set to 1, the  UE0 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue1_enable     : 1;  /**< [ 24: 24] If set to 1, the  UE1 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue2_enable     : 1;  /**< [ 25: 25] If set to 1, the  UE2 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue3_enable     : 1;  /**< [ 26: 26] If set to 1, the  UE3 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t layer_mode            : 2;  /**< [ 28: 27] Number of layers in this RB.
                                                                 0x0 = 1.
                                                                 0x1 = 2.
                                                                 0x2 = 4.
                                                                 0x3 = 8. */
        uint64_t ue_idx_rs0_layer0     : 5;  /**< [ 33: 29] In name field UE_IDX_RS_r_LAYER_l, the tuple (r,l) correspond to a RS index and
                                                                 layer index pair. This parameter  indicates the index of UE that is mapped to RS
                                                                 and layer tuple. */
        uint64_t ue_idx_rs0_layer1     : 5;  /**< [ 38: 34] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer2     : 5;  /**< [ 43: 39] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer3     : 5;  /**< [ 48: 44] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs_0_2_layer_4_0 : 5;/**< [ 53: 49] In name field UE_IDX_RS_r_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond to
                                                                 a RS index and layer index pair. This parameter  indicates the index of UE that
                                                                 is mapped to the active RS and layer tuple. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l) is the active
                                                                 tuple otherwise (s,m) is the active tuple. */
        uint64_t ue_idx_rs_0_2_layer_5_1 : 5;/**< [ 58: 54] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_0_2_layer_6_2 : 5;/**< [ 63: 59] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_127          : 1;
        uint64_t hrs_offset_rs1_3_layer_7_3 : 1;/**< [126:126] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_6_2 : 1;/**< [125:125] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_5_1 : 1;/**< [124:124] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_4_0 : 1;/**< [123:123] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_layer3 : 1;  /**< [122:122] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer2 : 1;  /**< [121:121] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer1 : 1;  /**< [120:120] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer0 : 1;  /**< [119:119] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_2_layer_7_3 : 1;/**< [118:118] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_6_2 : 1;/**< [117:117] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_5_1 : 1;/**< [116:116] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_4_0 : 1;/**< [115:115] In name field HRS_OFFSET_RSr_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond
                                                                 to a RS index and layer index pair. The parameter indicates whether the hrs
                                                                 corresponding to the active RS and layer tuple  begins at word boundary or
                                                                 middle of word. When FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2,
                                                                 (r,l) is the active tuple otherwise (s,m) is the active tuple.. */
        uint64_t hrs_offset_rs0_layer3 : 1;  /**< [114:114] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer2 : 1;  /**< [113:113] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer1 : 1;  /**< [112:112] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer0 : 1;  /**< [111:111] In name field HRS_OFFSET_RSr_LAYER_l, the tuple (r,l) correspond to a RS index
                                                                 and layer index pair. The parameter indicates whether the hrs corresponding to
                                                                 the active RS and layer tuple  begins at word boundary or middle of word. */
        uint64_t ryy_rb                : 2;  /**< [110:109] The number of RBs over which Ryy is averaged.
                                                                 0x0 = 1RB.
                                                                 0x1 = 2RBs.
                                                                 0x2 = 3RBs.
                                                                 0x3 = 4RBs. */
        uint64_t ue_idx_rs_1_3_layer_7_3 : 5;/**< [108:104] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_6_2 : 5;/**< [103: 99] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_5_1 : 5;/**< [ 98: 94] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_4_0 : 5;/**< [ 93: 89] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs1_layer3     : 5;  /**< [ 88: 84] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer2     : 5;  /**< [ 83: 79] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer1     : 5;  /**< [ 78: 74] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer0     : 5;  /**< [ 73: 69] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs_0_2_layer_7_3 : 5;/**< [ 68: 64] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
#else /* Word 1 - Little Endian */
        uint64_t ue_idx_rs_0_2_layer_7_3 : 5;/**< [ 68: 64] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs1_layer0     : 5;  /**< [ 73: 69] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer1     : 5;  /**< [ 78: 74] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer2     : 5;  /**< [ 83: 79] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer3     : 5;  /**< [ 88: 84] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs_1_3_layer_4_0 : 5;/**< [ 93: 89] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_5_1 : 5;/**< [ 98: 94] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_6_2 : 5;/**< [103: 99] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_7_3 : 5;/**< [108:104] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ryy_rb                : 2;  /**< [110:109] The number of RBs over which Ryy is averaged.
                                                                 0x0 = 1RB.
                                                                 0x1 = 2RBs.
                                                                 0x2 = 3RBs.
                                                                 0x3 = 4RBs. */
        uint64_t hrs_offset_rs0_layer0 : 1;  /**< [111:111] In name field HRS_OFFSET_RSr_LAYER_l, the tuple (r,l) correspond to a RS index
                                                                 and layer index pair. The parameter indicates whether the hrs corresponding to
                                                                 the active RS and layer tuple  begins at word boundary or middle of word. */
        uint64_t hrs_offset_rs0_layer1 : 1;  /**< [112:112] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer2 : 1;  /**< [113:113] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer3 : 1;  /**< [114:114] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_2_layer_4_0 : 1;/**< [115:115] In name field HRS_OFFSET_RSr_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond
                                                                 to a RS index and layer index pair. The parameter indicates whether the hrs
                                                                 corresponding to the active RS and layer tuple  begins at word boundary or
                                                                 middle of word. When FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2,
                                                                 (r,l) is the active tuple otherwise (s,m) is the active tuple.. */
        uint64_t hrs_offset_rs0_2_layer_5_1 : 1;/**< [116:116] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_6_2 : 1;/**< [117:117] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_7_3 : 1;/**< [118:118] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_layer0 : 1;  /**< [119:119] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer1 : 1;  /**< [120:120] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer2 : 1;  /**< [121:121] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer3 : 1;  /**< [122:122] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_3_layer_4_0 : 1;/**< [123:123] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_5_1 : 1;/**< [124:124] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_6_2 : 1;/**< [125:125] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_7_3 : 1;/**< [126:126] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t reserved_127          : 1;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_186_191      : 6;
        uint64_t rs3_rnn_a             : 6;  /**< [185:180] Refer to [RS0_RNN_A]. */
        uint64_t rs3_noise_a           : 4;  /**< [179:176] Refer to [RS0_NOISE_A]. */
        uint64_t reserved_170_175      : 6;
        uint64_t rs2_rnn_a             : 6;  /**< [169:164] Refer to [RS0_RNN_A]. */
        uint64_t rs2_noise_a           : 4;  /**< [163:160] Refer to [RS0_NOISE_A]. */
        uint64_t reserved_154_159      : 6;
        uint64_t rs1_rnn_a             : 6;  /**< [153:148] Refer to [RS0_RNN_A]. */
        uint64_t rs1_noise_a           : 4;  /**< [147:144] Refer to [RS0_NOISE_A]. */
        uint64_t reserved_138_143      : 6;
        uint64_t rs0_rnn_a             : 6;  /**< [137:132] In the name RSr_RNN_A, r refers to the antenna number. This parameter scaling
                                                                 factor for the off diagonal terms of Rnn of RSr.
                                                                 Valid ranges is [63,0].
                                                                 Default value is  31 (no scaling). */
        uint64_t rs0_noise_a           : 4;  /**< [131:128] In the name RSr_NOISE_A, r refers to the antenna number. This parameter scaling
                                                                 factor for the diagonal terms of Rnn of RSr.
                                                                 Valid ranges is [12,0].
                                                                 Default value is  0 (no scaling). */
#else /* Word 2 - Little Endian */
        uint64_t rs0_noise_a           : 4;  /**< [131:128] In the name RSr_NOISE_A, r refers to the antenna number. This parameter scaling
                                                                 factor for the diagonal terms of Rnn of RSr.
                                                                 Valid ranges is [12,0].
                                                                 Default value is  0 (no scaling). */
        uint64_t rs0_rnn_a             : 6;  /**< [137:132] In the name RSr_RNN_A, r refers to the antenna number. This parameter scaling
                                                                 factor for the off diagonal terms of Rnn of RSr.
                                                                 Valid ranges is [63,0].
                                                                 Default value is  31 (no scaling). */
        uint64_t reserved_138_143      : 6;
        uint64_t rs1_noise_a           : 4;  /**< [147:144] Refer to [RS0_NOISE_A]. */
        uint64_t rs1_rnn_a             : 6;  /**< [153:148] Refer to [RS0_RNN_A]. */
        uint64_t reserved_154_159      : 6;
        uint64_t rs2_noise_a           : 4;  /**< [163:160] Refer to [RS0_NOISE_A]. */
        uint64_t rs2_rnn_a             : 6;  /**< [169:164] Refer to [RS0_RNN_A]. */
        uint64_t reserved_170_175      : 6;
        uint64_t rs3_noise_a           : 4;  /**< [179:176] Refer to [RS0_NOISE_A]. */
        uint64_t rs3_rnn_a             : 6;  /**< [185:180] Refer to [RS0_RNN_A]. */
        uint64_t reserved_186_191      : 6;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_232_255      : 24;
        uint64_t test_mode             : 3;  /**< [231:229] Must be set to 0x0. */
        uint64_t freq_interp_mode      : 1;  /**< [228:228] When enabled, hrs of this RB is not interpolated in frequency domain with the previous RB. */
        uint64_t ue_infoset_index      : 28; /**< [227:200] Each 2 bits indicates RS index to which FDEQ_RDCFG_RB_PARAMS_JT1_S[LAYER_ENABLE_RSx_LAYERy] and
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[UE_IDX_RSx_LAYERy] are referred for each DS.
                                                                 The two LSBs refer to RS index used for DS0 and two MSBs refer to RS index for
                                                                 DS 13. Intermediate bits refer to respective DS's. */
        uint64_t reserved_195_199      : 5;
        uint64_t rnn_symb              : 3;  /**< [194:192] Defines the number of RS over which Rnn are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 1,
                                                                 0x1 = Rnn is not averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 2,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS0 and RS1 are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 3,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS1 and RS2 are averaged.
                                                                 0x3 = Rnn on RS0, RS1, and RS2 are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 4,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS0 and RS1 are averaged and Rnn on RS2 and RS3 are averaged.
                                                                 0x4 = Rnn on RS0, RS1, RS2, and RS3 are averaged. */
#else /* Word 3 - Little Endian */
        uint64_t rnn_symb              : 3;  /**< [194:192] Defines the number of RS over which Rnn are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 1,
                                                                 0x1 = Rnn is not averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 2,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS0 and RS1 are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 3,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS1 and RS2 are averaged.
                                                                 0x3 = Rnn on RS0, RS1, and RS2 are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 4,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS0 and RS1 are averaged and Rnn on RS2 and RS3 are averaged.
                                                                 0x4 = Rnn on RS0, RS1, RS2, and RS3 are averaged. */
        uint64_t reserved_195_199      : 5;
        uint64_t ue_infoset_index      : 28; /**< [227:200] Each 2 bits indicates RS index to which FDEQ_RDCFG_RB_PARAMS_JT1_S[LAYER_ENABLE_RSx_LAYERy] and
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[UE_IDX_RSx_LAYERy] are referred for each DS.
                                                                 The two LSBs refer to RS index used for DS0 and two MSBs refer to RS index for
                                                                 DS 13. Intermediate bits refer to respective DS's. */
        uint64_t freq_interp_mode      : 1;  /**< [228:228] When enabled, hrs of this RB is not interpolated in frequency domain with the previous RB. */
        uint64_t test_mode             : 3;  /**< [231:229] Must be set to 0x0. */
        uint64_t reserved_232_255      : 24;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_318_319      : 2;
        uint64_t layer_3_crc_layer_rbxsymb : 14;/**< [317:304] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_302_303      : 2;
        uint64_t layer_2_crc_layer_rbxsymb : 14;/**< [301:288] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_286_287      : 2;
        uint64_t layer_1_crc_layer_rbxsymb : 14;/**< [285:272] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_270_271      : 2;
        uint64_t layer_0_crc_layer_rbxsymb : 14;/**< [269:256] In the name LAYER_l_CRC_LAYER_RBXSYMB, l refers to layer number.
                                                                 This bitmap indicates the CRC of each DS of layer l and this RB. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] = 1 and
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_WITH_CRC_MAP] = 1. DS is indexed in
                                                                 increasing order with LSB refering to DS0.
                                                                 0x0 = CRC PASS (SIC is performed).
                                                                 0x1 = CRC FAIL(SIC is not performed). */
#else /* Word 4 - Little Endian */
        uint64_t layer_0_crc_layer_rbxsymb : 14;/**< [269:256] In the name LAYER_l_CRC_LAYER_RBXSYMB, l refers to layer number.
                                                                 This bitmap indicates the CRC of each DS of layer l and this RB. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] = 1 and
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_WITH_CRC_MAP] = 1. DS is indexed in
                                                                 increasing order with LSB refering to DS0.
                                                                 0x0 = CRC PASS (SIC is performed).
                                                                 0x1 = CRC FAIL(SIC is not performed). */
        uint64_t reserved_270_271      : 2;
        uint64_t layer_1_crc_layer_rbxsymb : 14;/**< [285:272] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_286_287      : 2;
        uint64_t layer_2_crc_layer_rbxsymb : 14;/**< [301:288] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_302_303      : 2;
        uint64_t layer_3_crc_layer_rbxsymb : 14;/**< [317:304] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_318_319      : 2;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_382_383      : 2;
        uint64_t layer_7_crc_layer_rbxsymb : 14;/**< [381:368] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_366_367      : 2;
        uint64_t layer_6_crc_layer_rbxsymb : 14;/**< [365:352] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_350_351      : 2;
        uint64_t layer_5_crc_layer_rbxsymb : 14;/**< [349:336] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_334_335      : 2;
        uint64_t layer_4_crc_layer_rbxsymb : 14;/**< [333:320] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
#else /* Word 5 - Little Endian */
        uint64_t layer_4_crc_layer_rbxsymb : 14;/**< [333:320] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_334_335      : 2;
        uint64_t layer_5_crc_layer_rbxsymb : 14;/**< [349:336] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_350_351      : 2;
        uint64_t layer_6_crc_layer_rbxsymb : 14;/**< [365:352] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_366_367      : 2;
        uint64_t layer_7_crc_layer_rbxsymb : 14;/**< [381:368] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_382_383      : 2;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_444_447      : 4;
        uint64_t rnn_index_for_r_symbol_13 : 2;/**< [443:442] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_12 : 2;/**< [441:440] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_11 : 2;/**< [439:438] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_10 : 2;/**< [437:436] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_9 : 2;/**< [435:434] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_8 : 2;/**< [433:432] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_7 : 2;/**< [431:430] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_6 : 2;/**< [429:428] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_5 : 2;/**< [427:426] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_4 : 2;/**< [425:424] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_3 : 2;/**< [423:422] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_2 : 2;/**< [421:420] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_1 : 2;/**< [419:418] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_0 : 2;/**< [417:416] In the name RNN_INDEX_FOR_R_SYMBOL_k, k refers to DS  number. Indicates the RS
                                                                 index whose Rnn is used for filter kernel calculation.
                                                                 Valid range is [3,0]. */
        uint64_t reserved_412_415      : 4;
        uint64_t irc_mode_data_symbol_13 : 2;/**< [411:410] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_12 : 2;/**< [409:408] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_11 : 2;/**< [407:406] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_10 : 2;/**< [405:404] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_9 : 2; /**< [403:402] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_8 : 2; /**< [401:400] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_7 : 2; /**< [399:398] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_6 : 2; /**< [397:396] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_5 : 2; /**< [395:394] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_4 : 2; /**< [393:392] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_3 : 2; /**< [391:390] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_2 : 2; /**< [389:388] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_1 : 2; /**< [387:386] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_0 : 2; /**< [385:384] In the name IRC_MODE_DATA_SYMBOL_k , k refers to DS index. This selects the IRC
                                                                 method applied on the DS k.
                                                                 0x0 =  R is Rnn+Rhh or Rnn.
                                                                 0x1 = R is Ryy.
                                                                 0x2 = R is (Rnn+Rhh or Rnn) or Ryy based on internal algorithm 1.
                                                                 0x3 = R is (Rnn+Rhh or Rnn) or Ryy based on internal algorithm 2.
                                                                 When (Rnn+Rhh or Rnn) is selected,
                                                                 FDEQ_RDCFG_UE_PHYC_PARAMS_S[SIMO_RNN_BASED_IRC_ON] selects Rnn+Rhh or Rnn. */
#else /* Word 6 - Little Endian */
        uint64_t irc_mode_data_symbol_0 : 2; /**< [385:384] In the name IRC_MODE_DATA_SYMBOL_k , k refers to DS index. This selects the IRC
                                                                 method applied on the DS k.
                                                                 0x0 =  R is Rnn+Rhh or Rnn.
                                                                 0x1 = R is Ryy.
                                                                 0x2 = R is (Rnn+Rhh or Rnn) or Ryy based on internal algorithm 1.
                                                                 0x3 = R is (Rnn+Rhh or Rnn) or Ryy based on internal algorithm 2.
                                                                 When (Rnn+Rhh or Rnn) is selected,
                                                                 FDEQ_RDCFG_UE_PHYC_PARAMS_S[SIMO_RNN_BASED_IRC_ON] selects Rnn+Rhh or Rnn. */
        uint64_t irc_mode_data_symbol_1 : 2; /**< [387:386] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_2 : 2; /**< [389:388] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_3 : 2; /**< [391:390] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_4 : 2; /**< [393:392] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_5 : 2; /**< [395:394] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_6 : 2; /**< [397:396] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_7 : 2; /**< [399:398] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_8 : 2; /**< [401:400] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_9 : 2; /**< [403:402] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_10 : 2;/**< [405:404] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_11 : 2;/**< [407:406] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_12 : 2;/**< [409:408] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_13 : 2;/**< [411:410] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t reserved_412_415      : 4;
        uint64_t rnn_index_for_r_symbol_0 : 2;/**< [417:416] In the name RNN_INDEX_FOR_R_SYMBOL_k, k refers to DS  number. Indicates the RS
                                                                 index whose Rnn is used for filter kernel calculation.
                                                                 Valid range is [3,0]. */
        uint64_t rnn_index_for_r_symbol_1 : 2;/**< [419:418] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_2 : 2;/**< [421:420] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_3 : 2;/**< [423:422] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_4 : 2;/**< [425:424] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_5 : 2;/**< [427:426] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_6 : 2;/**< [429:428] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_7 : 2;/**< [431:430] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_8 : 2;/**< [433:432] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_9 : 2;/**< [435:434] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_10 : 2;/**< [437:436] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_11 : 2;/**< [439:438] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_12 : 2;/**< [441:440] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_13 : 2;/**< [443:442] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t reserved_444_447      : 4;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t reserved_500_511      : 12;
        uint64_t layer_7_rs_crc_layer_rbxsymb : 4;/**< [499:496] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_6_rs_crc_layer_rbxsymb : 4;/**< [495:492] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_5_rs_crc_layer_rbxsymb : 4;/**< [491:488] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_4_rs_crc_layer_rbxsymb : 4;/**< [487:484] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_3_rs_crc_layer_rbxsymb : 4;/**< [483:480] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_2_rs_crc_layer_rbxsymb : 4;/**< [479:476] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_1_rs_crc_layer_rbxsymb : 4;/**< [475:472] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_0_rs_crc_layer_rbxsymb : 4;/**< [471:468] In the name LAYER_l_RS_CRC_LAYER_RBXSYMB, l refers to layer number.
                                                                 This bitmap indicates the CRC of each RS of layer l and this RB. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] = 1 and
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_WITH_CRC_MAP] = 1. RS is indexed in
                                                                 increasing order with LSB refering to RS0.
                                                                 0x0 = CRC PASS (SIC is performed).
                                                                 0x1 = CRC FAIL (SIC is not performed).
                                                                 Must be set to 0 for FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 0x1 (CP_OFDM).
                                                                 Must be set to 0 or 1 if TB CRC = OK or NOK, respectively for
                                                                 FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 0x0 (DFTs-OFDM). */
        uint64_t rnn_calc_tone_bitmap  : 12; /**< [467:456] A bitmap, indicating if Rnn  is calculated on a tone in this RB. LSB refers to
                                                                 tone 0 and MSB refers to tone 11.
                                                                 0x0 = Rnn is not calculated.
                                                                 0x1 = Rnn is calculated.
                                                                 If FDEQ()_JD_RS_GENERAL_PARAMETER[RS_FREQ_SPARSE]=0x0, this must be all
                                                                 0x1.If FDEQ()_JD_RS_GENERAL_PARAMETER[RS_FREQ_SPARSE]=0x1, 6 out of 12 bits
                                                                 must be 0x1. */
        uint64_t reserved_452_455      : 4;
        uint64_t tdce_rs_on_pattern    : 4;  /**< [451:448] A bitmap indicating if a RS is included in Timer domain interpolation. LSB
                                                                 refers to RS0. 0x0 = exclude the RS. 0x1 = include the RS. */
#else /* Word 7 - Little Endian */
        uint64_t tdce_rs_on_pattern    : 4;  /**< [451:448] A bitmap indicating if a RS is included in Timer domain interpolation. LSB
                                                                 refers to RS0. 0x0 = exclude the RS. 0x1 = include the RS. */
        uint64_t reserved_452_455      : 4;
        uint64_t rnn_calc_tone_bitmap  : 12; /**< [467:456] A bitmap, indicating if Rnn  is calculated on a tone in this RB. LSB refers to
                                                                 tone 0 and MSB refers to tone 11.
                                                                 0x0 = Rnn is not calculated.
                                                                 0x1 = Rnn is calculated.
                                                                 If FDEQ()_JD_RS_GENERAL_PARAMETER[RS_FREQ_SPARSE]=0x0, this must be all
                                                                 0x1.If FDEQ()_JD_RS_GENERAL_PARAMETER[RS_FREQ_SPARSE]=0x1, 6 out of 12 bits
                                                                 must be 0x1. */
        uint64_t layer_0_rs_crc_layer_rbxsymb : 4;/**< [471:468] In the name LAYER_l_RS_CRC_LAYER_RBXSYMB, l refers to layer number.
                                                                 This bitmap indicates the CRC of each RS of layer l and this RB. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] = 1 and
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_WITH_CRC_MAP] = 1. RS is indexed in
                                                                 increasing order with LSB refering to RS0.
                                                                 0x0 = CRC PASS (SIC is performed).
                                                                 0x1 = CRC FAIL (SIC is not performed).
                                                                 Must be set to 0 for FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 0x1 (CP_OFDM).
                                                                 Must be set to 0 or 1 if TB CRC = OK or NOK, respectively for
                                                                 FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 0x0 (DFTs-OFDM). */
        uint64_t layer_1_rs_crc_layer_rbxsymb : 4;/**< [475:472] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_2_rs_crc_layer_rbxsymb : 4;/**< [479:476] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_3_rs_crc_layer_rbxsymb : 4;/**< [483:480] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_4_rs_crc_layer_rbxsymb : 4;/**< [487:484] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_5_rs_crc_layer_rbxsymb : 4;/**< [491:488] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_6_rs_crc_layer_rbxsymb : 4;/**< [495:492] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_7_rs_crc_layer_rbxsymb : 4;/**< [499:496] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_500_511      : 12;
#endif /* Word 7 - End */
    } s;
    struct cavm_fdeq_rdcfg_rb_params_jt1_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ue_idx_rs_0_2_layer_6_2 : 5;/**< [ 63: 59] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_0_2_layer_5_1 : 5;/**< [ 58: 54] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_0_2_layer_4_0 : 5;/**< [ 53: 49] In name field UE_IDX_RS_r_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond to
                                                                 a RS index and layer index pair. This parameter  indicates the index of UE that
                                                                 is mapped to the active RS and layer tuple. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l) is the active
                                                                 tuple otherwise (s,m) is the active tuple. */
        uint64_t ue_idx_rs0_layer3     : 5;  /**< [ 48: 44] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer2     : 5;  /**< [ 43: 39] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer1     : 5;  /**< [ 38: 34] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer0     : 5;  /**< [ 33: 29] In name field UE_IDX_RS_r_LAYER_l, the tuple (r,l) correspond to a RS index and
                                                                 layer index pair. This parameter  indicates the index of UE that is mapped to RS
                                                                 and layer tuple. */
        uint64_t layer_mode            : 2;  /**< [ 28: 27] Number of layers in this RB.
                                                                 0x0 = 1.
                                                                 0x1 = 2.
                                                                 0x2 = 4.
                                                                 0x3 = 8. */
        uint64_t subprb_ue3_enable     : 1;  /**< [ 26: 26] If set to 1, the  UE3 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue2_enable     : 1;  /**< [ 25: 25] If set to 1, the  UE2 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue1_enable     : 1;  /**< [ 24: 24] If set to 1, the  UE1 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue0_enable     : 1;  /**< [ 23: 23] If set to 1, the  UE0 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_case_index     : 3;  /**< [ 22: 20] Indicates the SubPRB allocation. See section Configuration steps for subPRB Ues. */
        uint64_t layer_enable_rs1_layer7 : 1;/**< [ 19: 19] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer6 : 1;/**< [ 18: 18] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer5 : 1;/**< [ 17: 17] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer4 : 1;/**< [ 16: 16] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer3 : 1;/**< [ 15: 15] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer2 : 1;/**< [ 14: 14] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer1 : 1;/**< [ 13: 13] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer0 : 1;/**< [ 12: 12] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer7 : 1;/**< [ 11: 11] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer6 : 1;/**< [ 10: 10] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer5 : 1;/**< [  9:  9] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer4 : 1;/**< [  8:  8] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer3 : 1;/**< [  7:  7] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer2 : 1;/**< [  6:  6] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer1 : 1;/**< [  5:  5] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer0 : 1;/**< [  4:  4] In name field LAYER_ENABLE_RS_r_LAYER_l, the tuple (r,l) correspond to a RS
                                                                 index and layer index pair. If set to 1, layer l is active on RS r. */
        uint64_t rnn_rb                : 3;  /**< [  3:  1] Indicates the number of RBs over which Rnn is averaged.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RBs.
                                                                 0x2 = 3 RBs.
                                                                 0x3 = 4 RBs.
                                                                 0x4 = 5 RBs.
                                                                 0x5 = 6 RBs.
                                                                 0x6 = 7 RBs.
                                                                 0x7 = 8 RBs. */
        uint64_t subprb_enable         : 1;  /**< [  0:  0] If set to 1, this RB is configured as Sub PRB. */
#else /* Word 0 - Little Endian */
        uint64_t subprb_enable         : 1;  /**< [  0:  0] If set to 1, this RB is configured as Sub PRB. */
        uint64_t rnn_rb                : 3;  /**< [  3:  1] Indicates the number of RBs over which Rnn is averaged.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RBs.
                                                                 0x2 = 3 RBs.
                                                                 0x3 = 4 RBs.
                                                                 0x4 = 5 RBs.
                                                                 0x5 = 6 RBs.
                                                                 0x6 = 7 RBs.
                                                                 0x7 = 8 RBs. */
        uint64_t layer_enable_rs0_layer0 : 1;/**< [  4:  4] In name field LAYER_ENABLE_RS_r_LAYER_l, the tuple (r,l) correspond to a RS
                                                                 index and layer index pair. If set to 1, layer l is active on RS r. */
        uint64_t layer_enable_rs0_layer1 : 1;/**< [  5:  5] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer2 : 1;/**< [  6:  6] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer3 : 1;/**< [  7:  7] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer4 : 1;/**< [  8:  8] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer5 : 1;/**< [  9:  9] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer6 : 1;/**< [ 10: 10] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs0_layer7 : 1;/**< [ 11: 11] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer0 : 1;/**< [ 12: 12] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer1 : 1;/**< [ 13: 13] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer2 : 1;/**< [ 14: 14] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer3 : 1;/**< [ 15: 15] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer4 : 1;/**< [ 16: 16] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer5 : 1;/**< [ 17: 17] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer6 : 1;/**< [ 18: 18] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t layer_enable_rs1_layer7 : 1;/**< [ 19: 19] Refer to [LAYER_ENABLE_RS0_LAYER0]. */
        uint64_t subprb_case_index     : 3;  /**< [ 22: 20] Indicates the SubPRB allocation. See section Configuration steps for subPRB Ues. */
        uint64_t subprb_ue0_enable     : 1;  /**< [ 23: 23] If set to 1, the  UE0 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue1_enable     : 1;  /**< [ 24: 24] If set to 1, the  UE1 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue2_enable     : 1;  /**< [ 25: 25] If set to 1, the  UE2 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t subprb_ue3_enable     : 1;  /**< [ 26: 26] If set to 1, the  UE3 in case specified by [SUBPRB_CASE_INDEX], is enabled. */
        uint64_t layer_mode            : 2;  /**< [ 28: 27] Number of layers in this RB.
                                                                 0x0 = 1.
                                                                 0x1 = 2.
                                                                 0x2 = 4.
                                                                 0x3 = 8. */
        uint64_t ue_idx_rs0_layer0     : 5;  /**< [ 33: 29] In name field UE_IDX_RS_r_LAYER_l, the tuple (r,l) correspond to a RS index and
                                                                 layer index pair. This parameter  indicates the index of UE that is mapped to RS
                                                                 and layer tuple. */
        uint64_t ue_idx_rs0_layer1     : 5;  /**< [ 38: 34] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer2     : 5;  /**< [ 43: 39] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs0_layer3     : 5;  /**< [ 48: 44] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs_0_2_layer_4_0 : 5;/**< [ 53: 49] In name field UE_IDX_RS_r_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond to
                                                                 a RS index and layer index pair. This parameter  indicates the index of UE that
                                                                 is mapped to the active RS and layer tuple. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l) is the active
                                                                 tuple otherwise (s,m) is the active tuple. */
        uint64_t ue_idx_rs_0_2_layer_5_1 : 5;/**< [ 58: 54] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_0_2_layer_6_2 : 5;/**< [ 63: 59] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_127          : 1;
        uint64_t hrs_offset_rs1_3_layer_7_3 : 1;/**< [126:126] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_6_2 : 1;/**< [125:125] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_5_1 : 1;/**< [124:124] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_4_0 : 1;/**< [123:123] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_layer3 : 1;  /**< [122:122] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer2 : 1;  /**< [121:121] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer1 : 1;  /**< [120:120] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer0 : 1;  /**< [119:119] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_2_layer_7_3 : 1;/**< [118:118] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_6_2 : 1;/**< [117:117] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_5_1 : 1;/**< [116:116] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_4_0 : 1;/**< [115:115] In name field HRS_OFFSET_RSr_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond
                                                                 to a RS index and layer index pair. The parameter indicates whether the hrs
                                                                 corresponding to the active RS and layer tuple  begins at word boundary or
                                                                 middle of word. When FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2,
                                                                 (r,l) is the active tuple otherwise (s,m) is the active tuple.. */
        uint64_t hrs_offset_rs0_layer3 : 1;  /**< [114:114] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer2 : 1;  /**< [113:113] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer1 : 1;  /**< [112:112] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer0 : 1;  /**< [111:111] In name field HRS_OFFSET_RSr_LAYER_l, the tuple (r,l) correspond to a RS index
                                                                 and layer index pair. The parameter indicates whether the hrs corresponding to
                                                                 the active RS and layer tuple  begins at word boundary or middle of word. */
        uint64_t ryy_rb                : 2;  /**< [110:109] The number of RBs over which Ryy is averaged.
                                                                 0x0 = 1RB.
                                                                 0x1 = 2RBs.
                                                                 0x2 = 3RBs.
                                                                 0x3 = 4RBs. */
        uint64_t ue_idx_rs_1_3_layer_7_3 : 5;/**< [108:104] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_6_2 : 5;/**< [103: 99] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_5_1 : 5;/**< [ 98: 94] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_4_0 : 5;/**< [ 93: 89] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs1_layer3     : 5;  /**< [ 88: 84] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer2     : 5;  /**< [ 83: 79] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer1     : 5;  /**< [ 78: 74] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer0     : 5;  /**< [ 73: 69] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs_0_2_layer_7_3 : 5;/**< [ 68: 64] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
#else /* Word 1 - Little Endian */
        uint64_t ue_idx_rs_0_2_layer_7_3 : 5;/**< [ 68: 64] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs1_layer0     : 5;  /**< [ 73: 69] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer1     : 5;  /**< [ 78: 74] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer2     : 5;  /**< [ 83: 79] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs1_layer3     : 5;  /**< [ 88: 84] Refer to [UE_IDX_RS0_LAYER0]. */
        uint64_t ue_idx_rs_1_3_layer_4_0 : 5;/**< [ 93: 89] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_5_1 : 5;/**< [ 98: 94] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_6_2 : 5;/**< [103: 99] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ue_idx_rs_1_3_layer_7_3 : 5;/**< [108:104] Refer to [UE_IDX_RS_0_2_LAYER_4_0]. */
        uint64_t ryy_rb                : 2;  /**< [110:109] The number of RBs over which Ryy is averaged.
                                                                 0x0 = 1RB.
                                                                 0x1 = 2RBs.
                                                                 0x2 = 3RBs.
                                                                 0x3 = 4RBs. */
        uint64_t hrs_offset_rs0_layer0 : 1;  /**< [111:111] In name field HRS_OFFSET_RSr_LAYER_l, the tuple (r,l) correspond to a RS index
                                                                 and layer index pair. The parameter indicates whether the hrs corresponding to
                                                                 the active RS and layer tuple  begins at word boundary or middle of word. */
        uint64_t hrs_offset_rs0_layer1 : 1;  /**< [112:112] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer2 : 1;  /**< [113:113] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_layer3 : 1;  /**< [114:114] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs0_2_layer_4_0 : 1;/**< [115:115] In name field HRS_OFFSET_RSr_s_LAYER_l_m, the tuples (r,l) and (s,m) correspond
                                                                 to a RS index and layer index pair. The parameter indicates whether the hrs
                                                                 corresponding to the active RS and layer tuple  begins at word boundary or
                                                                 middle of word. When FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2,
                                                                 (r,l) is the active tuple otherwise (s,m) is the active tuple.. */
        uint64_t hrs_offset_rs0_2_layer_5_1 : 1;/**< [116:116] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_6_2 : 1;/**< [117:117] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs0_2_layer_7_3 : 1;/**< [118:118] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_layer0 : 1;  /**< [119:119] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer1 : 1;  /**< [120:120] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer2 : 1;  /**< [121:121] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_layer3 : 1;  /**< [122:122] Refer to [HRS_OFFSET_RS0_LAYER0]. */
        uint64_t hrs_offset_rs1_3_layer_4_0 : 1;/**< [123:123] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_5_1 : 1;/**< [124:124] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_6_2 : 1;/**< [125:125] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t hrs_offset_rs1_3_layer_7_3 : 1;/**< [126:126] Refer to [HRS_OFFSET_RS0_2_LAYER_4_0]. */
        uint64_t reserved_127          : 1;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_186_191      : 6;
        uint64_t rs3_rnn_a             : 6;  /**< [185:180] Refer to [RS0_RNN_A]. */
        uint64_t rs3_noise_a           : 4;  /**< [179:176] Refer to [RS0_NOISE_A]. */
        uint64_t reserved_170_175      : 6;
        uint64_t rs2_rnn_a             : 6;  /**< [169:164] Refer to [RS0_RNN_A]. */
        uint64_t rs2_noise_a           : 4;  /**< [163:160] Refer to [RS0_NOISE_A]. */
        uint64_t reserved_154_159      : 6;
        uint64_t rs1_rnn_a             : 6;  /**< [153:148] Refer to [RS0_RNN_A]. */
        uint64_t rs1_noise_a           : 4;  /**< [147:144] Refer to [RS0_NOISE_A]. */
        uint64_t reserved_138_143      : 6;
        uint64_t rs0_rnn_a             : 6;  /**< [137:132] In the name RSr_RNN_A, r refers to the antenna number. This parameter scaling
                                                                 factor for the off diagonal terms of Rnn of RSr.
                                                                 Valid ranges is [63,0].
                                                                 Default value is  31 (no scaling). */
        uint64_t rs0_noise_a           : 4;  /**< [131:128] In the name RSr_NOISE_A, r refers to the antenna number. This parameter scaling
                                                                 factor for the diagonal terms of Rnn of RSr.
                                                                 Valid ranges is [12,0].
                                                                 Default value is  0 (no scaling). */
#else /* Word 2 - Little Endian */
        uint64_t rs0_noise_a           : 4;  /**< [131:128] In the name RSr_NOISE_A, r refers to the antenna number. This parameter scaling
                                                                 factor for the diagonal terms of Rnn of RSr.
                                                                 Valid ranges is [12,0].
                                                                 Default value is  0 (no scaling). */
        uint64_t rs0_rnn_a             : 6;  /**< [137:132] In the name RSr_RNN_A, r refers to the antenna number. This parameter scaling
                                                                 factor for the off diagonal terms of Rnn of RSr.
                                                                 Valid ranges is [63,0].
                                                                 Default value is  31 (no scaling). */
        uint64_t reserved_138_143      : 6;
        uint64_t rs1_noise_a           : 4;  /**< [147:144] Refer to [RS0_NOISE_A]. */
        uint64_t rs1_rnn_a             : 6;  /**< [153:148] Refer to [RS0_RNN_A]. */
        uint64_t reserved_154_159      : 6;
        uint64_t rs2_noise_a           : 4;  /**< [163:160] Refer to [RS0_NOISE_A]. */
        uint64_t rs2_rnn_a             : 6;  /**< [169:164] Refer to [RS0_RNN_A]. */
        uint64_t reserved_170_175      : 6;
        uint64_t rs3_noise_a           : 4;  /**< [179:176] Refer to [RS0_NOISE_A]. */
        uint64_t rs3_rnn_a             : 6;  /**< [185:180] Refer to [RS0_RNN_A]. */
        uint64_t reserved_186_191      : 6;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_233_255      : 23;
        uint64_t reserved_232          : 1;
        uint64_t test_mode             : 3;  /**< [231:229] Must be set to 0x0. */
        uint64_t freq_interp_mode      : 1;  /**< [228:228] When enabled, hrs of this RB is not interpolated in frequency domain with the previous RB. */
        uint64_t ue_infoset_index      : 28; /**< [227:200] Each 2 bits indicates RS index to which FDEQ_RDCFG_RB_PARAMS_JT1_S[LAYER_ENABLE_RSx_LAYERy] and
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[UE_IDX_RSx_LAYERy] are referred for each DS.
                                                                 The two LSBs refer to RS index used for DS0 and two MSBs refer to RS index for
                                                                 DS 13. Intermediate bits refer to respective DS's. */
        uint64_t reserved_195_199      : 5;
        uint64_t rnn_symb              : 3;  /**< [194:192] Defines the number of RS over which Rnn are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 1,
                                                                 0x1 = Rnn is not averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 2,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS0 and RS1 are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 3,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS1 and RS2 are averaged.
                                                                 0x3 = Rnn on RS0, RS1, and RS2 are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 4,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS0 and RS1 are averaged and Rnn on RS2 and RS3 are averaged.
                                                                 0x4 = Rnn on RS0, RS1, RS2, and RS3 are averaged. */
#else /* Word 3 - Little Endian */
        uint64_t rnn_symb              : 3;  /**< [194:192] Defines the number of RS over which Rnn are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 1,
                                                                 0x1 = Rnn is not averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 2,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS0 and RS1 are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 3,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS1 and RS2 are averaged.
                                                                 0x3 = Rnn on RS0, RS1, and RS2 are averaged.
                                                                 If FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 4,
                                                                 0x1 = Rnn is not averaged.
                                                                 0x2 = Rnn on RS0 and RS1 are averaged and Rnn on RS2 and RS3 are averaged.
                                                                 0x4 = Rnn on RS0, RS1, RS2, and RS3 are averaged. */
        uint64_t reserved_195_199      : 5;
        uint64_t ue_infoset_index      : 28; /**< [227:200] Each 2 bits indicates RS index to which FDEQ_RDCFG_RB_PARAMS_JT1_S[LAYER_ENABLE_RSx_LAYERy] and
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[UE_IDX_RSx_LAYERy] are referred for each DS.
                                                                 The two LSBs refer to RS index used for DS0 and two MSBs refer to RS index for
                                                                 DS 13. Intermediate bits refer to respective DS's. */
        uint64_t freq_interp_mode      : 1;  /**< [228:228] When enabled, hrs of this RB is not interpolated in frequency domain with the previous RB. */
        uint64_t test_mode             : 3;  /**< [231:229] Must be set to 0x0. */
        uint64_t reserved_232          : 1;
        uint64_t reserved_233_255      : 23;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t reserved_318_319      : 2;
        uint64_t layer_3_crc_layer_rbxsymb : 14;/**< [317:304] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_302_303      : 2;
        uint64_t layer_2_crc_layer_rbxsymb : 14;/**< [301:288] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_286_287      : 2;
        uint64_t layer_1_crc_layer_rbxsymb : 14;/**< [285:272] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_270_271      : 2;
        uint64_t layer_0_crc_layer_rbxsymb : 14;/**< [269:256] In the name LAYER_l_CRC_LAYER_RBXSYMB, l refers to layer number.
                                                                 This bitmap indicates the CRC of each DS of layer l and this RB. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] = 1 and
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_WITH_CRC_MAP] = 1. DS is indexed in
                                                                 increasing order with LSB refering to DS0.
                                                                 0x0 = CRC PASS (SIC is performed).
                                                                 0x1 = CRC FAIL(SIC is not performed). */
#else /* Word 4 - Little Endian */
        uint64_t layer_0_crc_layer_rbxsymb : 14;/**< [269:256] In the name LAYER_l_CRC_LAYER_RBXSYMB, l refers to layer number.
                                                                 This bitmap indicates the CRC of each DS of layer l and this RB. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] = 1 and
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_WITH_CRC_MAP] = 1. DS is indexed in
                                                                 increasing order with LSB refering to DS0.
                                                                 0x0 = CRC PASS (SIC is performed).
                                                                 0x1 = CRC FAIL(SIC is not performed). */
        uint64_t reserved_270_271      : 2;
        uint64_t layer_1_crc_layer_rbxsymb : 14;/**< [285:272] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_286_287      : 2;
        uint64_t layer_2_crc_layer_rbxsymb : 14;/**< [301:288] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_302_303      : 2;
        uint64_t layer_3_crc_layer_rbxsymb : 14;/**< [317:304] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_318_319      : 2;
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_382_383      : 2;
        uint64_t layer_7_crc_layer_rbxsymb : 14;/**< [381:368] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_366_367      : 2;
        uint64_t layer_6_crc_layer_rbxsymb : 14;/**< [365:352] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_350_351      : 2;
        uint64_t layer_5_crc_layer_rbxsymb : 14;/**< [349:336] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_334_335      : 2;
        uint64_t layer_4_crc_layer_rbxsymb : 14;/**< [333:320] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
#else /* Word 5 - Little Endian */
        uint64_t layer_4_crc_layer_rbxsymb : 14;/**< [333:320] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_334_335      : 2;
        uint64_t layer_5_crc_layer_rbxsymb : 14;/**< [349:336] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_350_351      : 2;
        uint64_t layer_6_crc_layer_rbxsymb : 14;/**< [365:352] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_366_367      : 2;
        uint64_t layer_7_crc_layer_rbxsymb : 14;/**< [381:368] Refer to [LAYER_0_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_382_383      : 2;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_444_447      : 4;
        uint64_t rnn_index_for_r_symbol_13 : 2;/**< [443:442] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_12 : 2;/**< [441:440] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_11 : 2;/**< [439:438] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_10 : 2;/**< [437:436] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_9 : 2;/**< [435:434] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_8 : 2;/**< [433:432] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_7 : 2;/**< [431:430] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_6 : 2;/**< [429:428] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_5 : 2;/**< [427:426] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_4 : 2;/**< [425:424] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_3 : 2;/**< [423:422] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_2 : 2;/**< [421:420] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_1 : 2;/**< [419:418] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_0 : 2;/**< [417:416] In the name RNN_INDEX_FOR_R_SYMBOL_k, k refers to DS  number. Indicates the RS
                                                                 index whose Rnn is used for filter kernel calculation.
                                                                 Valid range is [3,0]. */
        uint64_t reserved_412_415      : 4;
        uint64_t irc_mode_data_symbol_13 : 2;/**< [411:410] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_12 : 2;/**< [409:408] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_11 : 2;/**< [407:406] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_10 : 2;/**< [405:404] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_9 : 2; /**< [403:402] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_8 : 2; /**< [401:400] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_7 : 2; /**< [399:398] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_6 : 2; /**< [397:396] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_5 : 2; /**< [395:394] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_4 : 2; /**< [393:392] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_3 : 2; /**< [391:390] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_2 : 2; /**< [389:388] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_1 : 2; /**< [387:386] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_0 : 2; /**< [385:384] In the name IRC_MODE_DATA_SYMBOL_k , k refers to DS index. This selects the IRC
                                                                 method applied on the DS k.
                                                                 0x0 =  R is Rnn+Rhh or Rnn.
                                                                 0x1 = R is Ryy.
                                                                 0x2 = R is (Rnn+Rhh or Rnn) or Ryy based on internal algorithm 1.
                                                                 0x3 = R is (Rnn+Rhh or Rnn) or Ryy based on internal algorithm 2.
                                                                 When (Rnn+Rhh or Rnn) is selected,
                                                                 FDEQ_RDCFG_UE_PHYC_PARAMS_S[SIMO_RNN_BASED_IRC_ON] selects Rnn+Rhh or Rnn. */
#else /* Word 6 - Little Endian */
        uint64_t irc_mode_data_symbol_0 : 2; /**< [385:384] In the name IRC_MODE_DATA_SYMBOL_k , k refers to DS index. This selects the IRC
                                                                 method applied on the DS k.
                                                                 0x0 =  R is Rnn+Rhh or Rnn.
                                                                 0x1 = R is Ryy.
                                                                 0x2 = R is (Rnn+Rhh or Rnn) or Ryy based on internal algorithm 1.
                                                                 0x3 = R is (Rnn+Rhh or Rnn) or Ryy based on internal algorithm 2.
                                                                 When (Rnn+Rhh or Rnn) is selected,
                                                                 FDEQ_RDCFG_UE_PHYC_PARAMS_S[SIMO_RNN_BASED_IRC_ON] selects Rnn+Rhh or Rnn. */
        uint64_t irc_mode_data_symbol_1 : 2; /**< [387:386] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_2 : 2; /**< [389:388] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_3 : 2; /**< [391:390] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_4 : 2; /**< [393:392] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_5 : 2; /**< [395:394] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_6 : 2; /**< [397:396] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_7 : 2; /**< [399:398] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_8 : 2; /**< [401:400] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_9 : 2; /**< [403:402] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_10 : 2;/**< [405:404] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_11 : 2;/**< [407:406] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_12 : 2;/**< [409:408] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t irc_mode_data_symbol_13 : 2;/**< [411:410] Refer to [IRC_MODE_DATA_SYMBOL_0]. */
        uint64_t reserved_412_415      : 4;
        uint64_t rnn_index_for_r_symbol_0 : 2;/**< [417:416] In the name RNN_INDEX_FOR_R_SYMBOL_k, k refers to DS  number. Indicates the RS
                                                                 index whose Rnn is used for filter kernel calculation.
                                                                 Valid range is [3,0]. */
        uint64_t rnn_index_for_r_symbol_1 : 2;/**< [419:418] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_2 : 2;/**< [421:420] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_3 : 2;/**< [423:422] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_4 : 2;/**< [425:424] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_5 : 2;/**< [427:426] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_6 : 2;/**< [429:428] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_7 : 2;/**< [431:430] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_8 : 2;/**< [433:432] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_9 : 2;/**< [435:434] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_10 : 2;/**< [437:436] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_11 : 2;/**< [439:438] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_12 : 2;/**< [441:440] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t rnn_index_for_r_symbol_13 : 2;/**< [443:442] Refer to [RNN_INDEX_FOR_R_SYMBOL_0]. */
        uint64_t reserved_444_447      : 4;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t reserved_500_511      : 12;
        uint64_t layer_7_rs_crc_layer_rbxsymb : 4;/**< [499:496] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_6_rs_crc_layer_rbxsymb : 4;/**< [495:492] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_5_rs_crc_layer_rbxsymb : 4;/**< [491:488] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_4_rs_crc_layer_rbxsymb : 4;/**< [487:484] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_3_rs_crc_layer_rbxsymb : 4;/**< [483:480] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_2_rs_crc_layer_rbxsymb : 4;/**< [479:476] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_1_rs_crc_layer_rbxsymb : 4;/**< [475:472] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_0_rs_crc_layer_rbxsymb : 4;/**< [471:468] In the name LAYER_l_RS_CRC_LAYER_RBXSYMB, l refers to layer number.
                                                                 This bitmap indicates the CRC of each RS of layer l and this RB. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] = 1 and
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_WITH_CRC_MAP] = 1. RS is indexed in
                                                                 increasing order with LSB refering to RS0.
                                                                 0x0 = CRC PASS (SIC is performed).
                                                                 0x1 = CRC FAIL (SIC is not performed).
                                                                 Must be set to 0 for FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 0x1 (CP_OFDM).
                                                                 Must be set to 0 or 1 if TB CRC = OK or NOK, respectively for
                                                                 FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 0x0 (DFTs-OFDM). */
        uint64_t rnn_calc_tone_bitmap  : 12; /**< [467:456] A bitmap, indicating if Rnn  is calculated on a tone in this RB. LSB refers to
                                                                 tone 0 and MSB refers to tone 11.
                                                                 0x0 = Rnn is not calculated.
                                                                 0x1 = Rnn is calculated.
                                                                 If FDEQ()_JD_RS_GENERAL_PARAMETER[RS_FREQ_SPARSE]=0x0, this must be all
                                                                 0x1.If FDEQ()_JD_RS_GENERAL_PARAMETER[RS_FREQ_SPARSE]=0x1, 6 out of 12 bits
                                                                 must be 0x1. */
        uint64_t reserved_452_455      : 4;
        uint64_t tdce_rs_on_pattern    : 4;  /**< [451:448] A bitmap indicating if a RS is included in Timer domain interpolation. LSB
                                                                 refers to RS0. 0x0 = exclude the RS. 0x1 = include the RS. */
#else /* Word 7 - Little Endian */
        uint64_t tdce_rs_on_pattern    : 4;  /**< [451:448] A bitmap indicating if a RS is included in Timer domain interpolation. LSB
                                                                 refers to RS0. 0x0 = exclude the RS. 0x1 = include the RS. */
        uint64_t reserved_452_455      : 4;
        uint64_t rnn_calc_tone_bitmap  : 12; /**< [467:456] A bitmap, indicating if Rnn  is calculated on a tone in this RB. LSB refers to
                                                                 tone 0 and MSB refers to tone 11.
                                                                 0x0 = Rnn is not calculated.
                                                                 0x1 = Rnn is calculated.
                                                                 If FDEQ()_JD_RS_GENERAL_PARAMETER[RS_FREQ_SPARSE]=0x0, this must be all
                                                                 0x1.If FDEQ()_JD_RS_GENERAL_PARAMETER[RS_FREQ_SPARSE]=0x1, 6 out of 12 bits
                                                                 must be 0x1. */
        uint64_t layer_0_rs_crc_layer_rbxsymb : 4;/**< [471:468] In the name LAYER_l_RS_CRC_LAYER_RBXSYMB, l refers to layer number.
                                                                 This bitmap indicates the CRC of each RS of layer l and this RB. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] = 1 and
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_WITH_CRC_MAP] = 1. RS is indexed in
                                                                 increasing order with LSB refering to RS0.
                                                                 0x0 = CRC PASS (SIC is performed).
                                                                 0x1 = CRC FAIL (SIC is not performed).
                                                                 Must be set to 0 for FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 0x1 (CP_OFDM).
                                                                 Must be set to 0 or 1 if TB CRC = OK or NOK, respectively for
                                                                 FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 0x0 (DFTs-OFDM). */
        uint64_t layer_1_rs_crc_layer_rbxsymb : 4;/**< [475:472] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_2_rs_crc_layer_rbxsymb : 4;/**< [479:476] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_3_rs_crc_layer_rbxsymb : 4;/**< [483:480] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_4_rs_crc_layer_rbxsymb : 4;/**< [487:484] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_5_rs_crc_layer_rbxsymb : 4;/**< [491:488] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_6_rs_crc_layer_rbxsymb : 4;/**< [495:492] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t layer_7_rs_crc_layer_rbxsymb : 4;/**< [499:496] Refer to [LAYER_0_RS_CRC_LAYER_RBXSYMB]. */
        uint64_t reserved_500_511      : 12;
#endif /* Word 7 - End */
    } cn;
};

/**
 * Structure fdeq_rdcfg_twf_set_s
 *
 * FDEQ Read DMA TDCE weight filter set Parameter Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_twf_set_s
{
    uint64_t u[2];
    struct cavm_fdeq_rdcfg_twf_set_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t w1_symbol0_q_phase    : 14; /**< [ 61: 48] Q value of complex weight 1 for symbol 0. */
        uint64_t reserved_46_47        : 2;
        uint64_t w1_symbol0_i_phase    : 14; /**< [ 45: 32] I value of complex weight 1 for symbol 0 */
        uint64_t reserved_30_31        : 2;
        uint64_t w0_symbol0_q_phase    : 14; /**< [ 29: 16] Q value of complex weight 0 for symbol 0. */
        uint64_t reserved_14_15        : 2;
        uint64_t w0_symbol0_i_phase    : 14; /**< [ 13:  0] I value of complex weight 0 for symbol 0. */
#else /* Word 0 - Little Endian */
        uint64_t w0_symbol0_i_phase    : 14; /**< [ 13:  0] I value of complex weight 0 for symbol 0. */
        uint64_t reserved_14_15        : 2;
        uint64_t w0_symbol0_q_phase    : 14; /**< [ 29: 16] Q value of complex weight 0 for symbol 0. */
        uint64_t reserved_30_31        : 2;
        uint64_t w1_symbol0_i_phase    : 14; /**< [ 45: 32] I value of complex weight 1 for symbol 0 */
        uint64_t reserved_46_47        : 2;
        uint64_t w1_symbol0_q_phase    : 14; /**< [ 61: 48] Q value of complex weight 1 for symbol 0. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_126_127      : 2;
        uint64_t w1_symbol1_q_phase    : 14; /**< [125:112] Q value of complex weight 1 for symbol 1. */
        uint64_t reserved_110_111      : 2;
        uint64_t w1_symbol1_i_phase    : 14; /**< [109: 96] I value of complex weight 1 for symbol 1. */
        uint64_t reserved_94_95        : 2;
        uint64_t w0_symbol1_q_phase    : 14; /**< [ 93: 80] Q value of complex weight 0 for symbol 1. */
        uint64_t reserved_78_79        : 2;
        uint64_t w0_symbol1_i_phase    : 14; /**< [ 77: 64] I value of complex weight 0 for symbol 1. */
#else /* Word 1 - Little Endian */
        uint64_t w0_symbol1_i_phase    : 14; /**< [ 77: 64] I value of complex weight 0 for symbol 1. */
        uint64_t reserved_78_79        : 2;
        uint64_t w0_symbol1_q_phase    : 14; /**< [ 93: 80] Q value of complex weight 0 for symbol 1. */
        uint64_t reserved_94_95        : 2;
        uint64_t w1_symbol1_i_phase    : 14; /**< [109: 96] I value of complex weight 1 for symbol 1. */
        uint64_t reserved_110_111      : 2;
        uint64_t w1_symbol1_q_phase    : 14; /**< [125:112] Q value of complex weight 1 for symbol 1. */
        uint64_t reserved_126_127      : 2;
#endif /* Word 1 - End */
    } s;
    /* struct cavm_fdeq_rdcfg_twf_set_s_s cn; */
};

/**
 * Structure fdeq_rdcfg_ue_phase_16r_s
 *
 * FDEQ DMA Read port UE Phase for 16 receive antenna Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_ue_phase_16r_s
{
    uint64_t u[4];
    struct cavm_fdeq_rdcfg_ue_phase_16r_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t phase_antenna_3       : 16; /**< [ 63: 48] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_2       : 16; /**< [ 47: 32] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_1       : 16; /**< [ 31: 16] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_0       : 16; /**< [ 15:  0] In the name PHASE_ANTENNA_r, r refers to antenna index. This parameter defines
                                                                 phase offset on this data symbol and antenna r due to Frequncy Offset.
                                                                 It is used FO compensation and recompensation in TDCE block.
                                                                 Valid range is [4095,0].
                                                                 Unit is 2*pi/4096. */
#else /* Word 0 - Little Endian */
        uint64_t phase_antenna_0       : 16; /**< [ 15:  0] In the name PHASE_ANTENNA_r, r refers to antenna index. This parameter defines
                                                                 phase offset on this data symbol and antenna r due to Frequncy Offset.
                                                                 It is used FO compensation and recompensation in TDCE block.
                                                                 Valid range is [4095,0].
                                                                 Unit is 2*pi/4096. */
        uint64_t phase_antenna_1       : 16; /**< [ 31: 16] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_2       : 16; /**< [ 47: 32] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_3       : 16; /**< [ 63: 48] Refer to [PHASE_ANTENNA_0]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t phase_antenna_7       : 16; /**< [127:112] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_6       : 16; /**< [111: 96] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_5       : 16; /**< [ 95: 80] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_4       : 16; /**< [ 79: 64] Refer to [PHASE_ANTENNA_0]. */
#else /* Word 1 - Little Endian */
        uint64_t phase_antenna_4       : 16; /**< [ 79: 64] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_5       : 16; /**< [ 95: 80] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_6       : 16; /**< [111: 96] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_7       : 16; /**< [127:112] Refer to [PHASE_ANTENNA_0]. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t phase_antenna_11      : 16; /**< [191:176] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_10      : 16; /**< [175:160] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_9       : 16; /**< [159:144] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_8       : 16; /**< [143:128] Refer to [PHASE_ANTENNA_0]. */
#else /* Word 2 - Little Endian */
        uint64_t phase_antenna_8       : 16; /**< [143:128] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_9       : 16; /**< [159:144] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_10      : 16; /**< [175:160] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_11      : 16; /**< [191:176] Refer to [PHASE_ANTENNA_0]. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t phase_antenna_15      : 16; /**< [255:240] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_14      : 16; /**< [239:224] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_13      : 16; /**< [223:208] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_12      : 16; /**< [207:192] Refer to [PHASE_ANTENNA_0]. */
#else /* Word 3 - Little Endian */
        uint64_t phase_antenna_12      : 16; /**< [207:192] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_13      : 16; /**< [223:208] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_14      : 16; /**< [239:224] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_15      : 16; /**< [255:240] Refer to [PHASE_ANTENNA_0]. */
#endif /* Word 3 - End */
    } s;
    /* struct cavm_fdeq_rdcfg_ue_phase_16r_s_s cn; */
};

/**
 * Structure fdeq_rdcfg_ue_phase_8r_s
 *
 * FDEQ DMA Read port UE Phase for 8 receive antenna Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_ue_phase_8r_s
{
    uint64_t u[2];
    struct cavm_fdeq_rdcfg_ue_phase_8r_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t phase_antenna_3       : 16; /**< [ 63: 48] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_2       : 16; /**< [ 47: 32] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_1       : 16; /**< [ 31: 16] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_0       : 16; /**< [ 15:  0] In the name PHASE_ANTENNA_r, r refers to antenna index. This parameter defines
                                                                 phase offset on this data symbol and antenna r due to Frequncy Offset.
                                                                 It is used FO compensation and recompensation in TDCE block.
                                                                 Valid range is [4095,0].
                                                                 Unit is 2*pi/4096. */
#else /* Word 0 - Little Endian */
        uint64_t phase_antenna_0       : 16; /**< [ 15:  0] In the name PHASE_ANTENNA_r, r refers to antenna index. This parameter defines
                                                                 phase offset on this data symbol and antenna r due to Frequncy Offset.
                                                                 It is used FO compensation and recompensation in TDCE block.
                                                                 Valid range is [4095,0].
                                                                 Unit is 2*pi/4096. */
        uint64_t phase_antenna_1       : 16; /**< [ 31: 16] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_2       : 16; /**< [ 47: 32] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_3       : 16; /**< [ 63: 48] Refer to [PHASE_ANTENNA_0]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t phase_antenna_7       : 16; /**< [127:112] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_6       : 16; /**< [111: 96] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_5       : 16; /**< [ 95: 80] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_4       : 16; /**< [ 79: 64] Refer to [PHASE_ANTENNA_0]. */
#else /* Word 1 - Little Endian */
        uint64_t phase_antenna_4       : 16; /**< [ 79: 64] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_5       : 16; /**< [ 95: 80] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_6       : 16; /**< [111: 96] Refer to [PHASE_ANTENNA_0]. */
        uint64_t phase_antenna_7       : 16; /**< [127:112] Refer to [PHASE_ANTENNA_0]. */
#endif /* Word 1 - End */
    } s;
    /* struct cavm_fdeq_rdcfg_ue_phase_8r_s_s cn; */
};

/**
 * Structure fdeq_rdcfg_ue_phyc_params_s
 *
 * FDEQ Read DMA PHYC UE Parameter Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_ue_phyc_params_s
{
    uint64_t u[4];
    struct cavm_fdeq_rdcfg_ue_phyc_params_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t gain_norm_on          : 1;  /**< [ 60: 60] If enabled (0x1), equalized output is normalized by a scale derived from equalized weight.
                                                                 Only valid for CP-OFDM UE with FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 1.
                                                                 Must be enabled for all CP-OFDM UEs for normal operation. */
        uint64_t r_norm_target_level   : 3;  /**< [ 59: 57] Power level of the normalized R matrix, calculated as 2^(16+[R_NORM_TARGET_LEVEL]).
                                                                 Valid range is [4,2] */
        uint64_t rs_slot1_rb_offset    : 8;  /**< [ 56: 49] Indicate RB offset of DMRS sequence for slot 1 in the given job. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 Valid range is [107,0]. */
        uint64_t rs_slot0_rb_offset    : 8;  /**< [ 48: 41] Indicate RB offset of DMRS sequence for slot 0 in the given job.Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 Valid range is [107,0]. */
        uint64_t rs_slot1_cs           : 4;  /**< [ 40: 37] Cyclic Sshift for DMRS generation of slot 1. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. Valid range is
                                                                 [11,0]. */
        uint64_t rs_slot1_u            : 5;  /**< [ 36: 32] u for DMRS generation of slot 1.
                                                                 Valid range is [29,0]
                                                                 Valid when FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_slot1_v            : 1;  /**< [ 31: 31] v for DMRS generation of slot 1. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. Valid range is
                                                                 [1,0] */
        uint64_t rs_slot1_occ          : 1;  /**< [ 30: 30] OCC for DMRS generation of slot 1. 0x0 = [1,1] 0x1 = [1, 0].
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_slot0_cs           : 4;  /**< [ 29: 26] Definition same as slot 1. */
        uint64_t rs_slot0_u            : 5;  /**< [ 25: 21] Definition same as slot 1. */
        uint64_t rs_slot0_v            : 1;  /**< [ 20: 20] Definition same as slot 1. */
        uint64_t rs_slot0_occ          : 1;  /**< [ 19: 19] Definition same as slot 1. */
        uint64_t cp_ofdm_on            : 1;  /**< [ 18: 18] 0x0 = DFTs-OFDM.
                                                                 0x1 = CP-OFDM. */
        uint64_t antenna_on_off_bitmap : 16; /**< [ 17:  2] If the (15-n)th bit of the bitmap is 0, the hrs correponding to nth antenna is
                                                                 zeros out for the UE. */
        uint64_t reserved_1            : 1;
        uint64_t ue_enable             : 1;  /**< [  0:  0] If disabled, the UE is disabled. Disabled UE is not processed even if parameters
                                                                 are given in this config. */
#else /* Word 0 - Little Endian */
        uint64_t ue_enable             : 1;  /**< [  0:  0] If disabled, the UE is disabled. Disabled UE is not processed even if parameters
                                                                 are given in this config. */
        uint64_t reserved_1            : 1;
        uint64_t antenna_on_off_bitmap : 16; /**< [ 17:  2] If the (15-n)th bit of the bitmap is 0, the hrs correponding to nth antenna is
                                                                 zeros out for the UE. */
        uint64_t cp_ofdm_on            : 1;  /**< [ 18: 18] 0x0 = DFTs-OFDM.
                                                                 0x1 = CP-OFDM. */
        uint64_t rs_slot0_occ          : 1;  /**< [ 19: 19] Definition same as slot 1. */
        uint64_t rs_slot0_v            : 1;  /**< [ 20: 20] Definition same as slot 1. */
        uint64_t rs_slot0_u            : 5;  /**< [ 25: 21] Definition same as slot 1. */
        uint64_t rs_slot0_cs           : 4;  /**< [ 29: 26] Definition same as slot 1. */
        uint64_t rs_slot1_occ          : 1;  /**< [ 30: 30] OCC for DMRS generation of slot 1. 0x0 = [1,1] 0x1 = [1, 0].
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_slot1_v            : 1;  /**< [ 31: 31] v for DMRS generation of slot 1. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. Valid range is
                                                                 [1,0] */
        uint64_t rs_slot1_u            : 5;  /**< [ 36: 32] u for DMRS generation of slot 1.
                                                                 Valid range is [29,0]
                                                                 Valid when FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_slot1_cs           : 4;  /**< [ 40: 37] Cyclic Sshift for DMRS generation of slot 1. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. Valid range is
                                                                 [11,0]. */
        uint64_t rs_slot0_rb_offset    : 8;  /**< [ 48: 41] Indicate RB offset of DMRS sequence for slot 0 in the given job.Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 Valid range is [107,0]. */
        uint64_t rs_slot1_rb_offset    : 8;  /**< [ 56: 49] Indicate RB offset of DMRS sequence for slot 1 in the given job. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 Valid range is [107,0]. */
        uint64_t r_norm_target_level   : 3;  /**< [ 59: 57] Power level of the normalized R matrix, calculated as 2^(16+[R_NORM_TARGET_LEVEL]).
                                                                 Valid range is [4,2] */
        uint64_t gain_norm_on          : 1;  /**< [ 60: 60] If enabled (0x1), equalized output is normalized by a scale derived from equalized weight.
                                                                 Only valid for CP-OFDM UE with FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 1.
                                                                 Must be enabled for all CP-OFDM UEs for normal operation. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_123_127      : 5;
        uint64_t configured_psinr      : 5;  /**< [122:118] Override internally calculated PSINR when conditions in [PSINR_METHOD] are met.
                                                                 Valid range is [31,0]. */
        uint64_t psinr_method          : 1;  /**< [117:117] Defines PSINR calculation method.
                                                                 0x0 = Wh method.
                                                                 0x1 = Wy method.
                                                                 Set to 0 when [CP_OFDM_ON] =1. */
        uint64_t ref_tagc_mode         : 1;  /**< [116:116] Defines how to adjust gain difference between symbols with different TAGC values.
                                                                 0x0 = use TAGC of symbol 0 as reference.
                                                                 0x1 = use average TAGC of all symbols as reference. */
        uint64_t r_diagloading_threshold : 10;/**< [115:106] Used by FDEQ to seclect if R inversion with [R_DIAGLOADING_FACTOR_0] or R
                                                                 inversion with [R_DIAGLOADING_FACTOR_1] is used.
                                                                 Default value is 0x1.
                                                                 The default value selects R inversion with [R_DIAGLOADING_FACTOR_1]. */
        uint64_t reserved_104_105      : 2;
        uint64_t h_rs_average_on       : 1;  /**< [103:103] If enabled Hrs is averaged across all RS before Rnn calculation.
                                                                 Only valid if FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 2 or 4. */
        uint64_t rhh_bitshift          : 3;  /**< [102:100] Indicates the amount of right shift on the internally calculated Rhh in internal
                                                                 calculation. Valid range is [7,0].Default value is 0. */
        uint64_t ce_bitshift           : 2;  /**< [ 99: 98] Indiates the amount of right shift on Hrs in additional
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[H_DMRS_INPUT_BITSHIFT] and g_FAGC. Valid
                                                                 range is [3,0]. Default value is 0. */
        uint64_t r_diagloading_factor_0 : 10;/**< [ 97: 88] A bias factor applied to diagonal of the R matrix.
                                                                 Default value is 0x2.
                                                                 R_DIAGLOADING_FACTOR_0 must be greater than [R_DIAGLOADING_FACTOR_1]. */
        uint64_t r_diagloading_factor_1 : 10;/**< [ 87: 78] A bias factor applied to diagonal of the R matrix.
                                                                 Default value is 0x1.
                                                                 R_DIAGLOADING_FACTOR_1 must be less than [R_DIAGLOADING_FACTOR_0]. */
        uint64_t channel_interp_on     : 1;  /**< [ 77: 77] If set to 1, frequency domain interpolation of CE after TDCE is enabled for SIC
                                                                 operation. Valid only when FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] is
                                                                 0x1. */
        uint64_t channel_phasecomp_on  : 1;  /**< [ 76: 76] If enabled, phase compensation due to time offset is applied in frequency domain
                                                                 interpolation of Hrs on each data symbol. */
        uint64_t weight_interp_on      : 1;  /**< [ 75: 75] If enabled the equalizer weights in frequency domain are interpolated. */
        uint64_t weight_phasecomp_on   : 1;  /**< [ 74: 74] If enabled  phase compensation due to time Offset is applied in the frequency
                                                                 domain interpolation of equalizer weights. */
        uint64_t weight_scale          : 10; /**< [ 73: 64] Value of internal bit shift applied to the equalizer weights. Valid values are
                                                                 is [512,256,128,64,32,0]. Must be same as 32*2^[WSCALE_BITSHIFT] Default is 32
                                                                 or 64. */
#else /* Word 1 - Little Endian */
        uint64_t weight_scale          : 10; /**< [ 73: 64] Value of internal bit shift applied to the equalizer weights. Valid values are
                                                                 is [512,256,128,64,32,0]. Must be same as 32*2^[WSCALE_BITSHIFT] Default is 32
                                                                 or 64. */
        uint64_t weight_phasecomp_on   : 1;  /**< [ 74: 74] If enabled  phase compensation due to time Offset is applied in the frequency
                                                                 domain interpolation of equalizer weights. */
        uint64_t weight_interp_on      : 1;  /**< [ 75: 75] If enabled the equalizer weights in frequency domain are interpolated. */
        uint64_t channel_phasecomp_on  : 1;  /**< [ 76: 76] If enabled, phase compensation due to time offset is applied in frequency domain
                                                                 interpolation of Hrs on each data symbol. */
        uint64_t channel_interp_on     : 1;  /**< [ 77: 77] If set to 1, frequency domain interpolation of CE after TDCE is enabled for SIC
                                                                 operation. Valid only when FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] is
                                                                 0x1. */
        uint64_t r_diagloading_factor_1 : 10;/**< [ 87: 78] A bias factor applied to diagonal of the R matrix.
                                                                 Default value is 0x1.
                                                                 R_DIAGLOADING_FACTOR_1 must be less than [R_DIAGLOADING_FACTOR_0]. */
        uint64_t r_diagloading_factor_0 : 10;/**< [ 97: 88] A bias factor applied to diagonal of the R matrix.
                                                                 Default value is 0x2.
                                                                 R_DIAGLOADING_FACTOR_0 must be greater than [R_DIAGLOADING_FACTOR_1]. */
        uint64_t ce_bitshift           : 2;  /**< [ 99: 98] Indiates the amount of right shift on Hrs in additional
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[H_DMRS_INPUT_BITSHIFT] and g_FAGC. Valid
                                                                 range is [3,0]. Default value is 0. */
        uint64_t rhh_bitshift          : 3;  /**< [102:100] Indicates the amount of right shift on the internally calculated Rhh in internal
                                                                 calculation. Valid range is [7,0].Default value is 0. */
        uint64_t h_rs_average_on       : 1;  /**< [103:103] If enabled Hrs is averaged across all RS before Rnn calculation.
                                                                 Only valid if FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 2 or 4. */
        uint64_t reserved_104_105      : 2;
        uint64_t r_diagloading_threshold : 10;/**< [115:106] Used by FDEQ to seclect if R inversion with [R_DIAGLOADING_FACTOR_0] or R
                                                                 inversion with [R_DIAGLOADING_FACTOR_1] is used.
                                                                 Default value is 0x1.
                                                                 The default value selects R inversion with [R_DIAGLOADING_FACTOR_1]. */
        uint64_t ref_tagc_mode         : 1;  /**< [116:116] Defines how to adjust gain difference between symbols with different TAGC values.
                                                                 0x0 = use TAGC of symbol 0 as reference.
                                                                 0x1 = use average TAGC of all symbols as reference. */
        uint64_t psinr_method          : 1;  /**< [117:117] Defines PSINR calculation method.
                                                                 0x0 = Wh method.
                                                                 0x1 = Wy method.
                                                                 Set to 0 when [CP_OFDM_ON] =1. */
        uint64_t configured_psinr      : 5;  /**< [122:118] Override internally calculated PSINR when conditions in [PSINR_METHOD] are met.
                                                                 Valid range is [31,0]. */
        uint64_t reserved_123_127      : 5;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_189_191      : 3;
        uint64_t dmrs_pattern_bitmap   : 12; /**< [188:177] A bitmap indicating the DMRS pattern in CP-OFDM RB. MSB corresponds to tone index 0.
                                                                 0x0 = DTX or data.
                                                                 0x1 = DMRS. */
        uint64_t reserved_174_176      : 3;
        uint64_t rs_channel_phasecomp_on : 1;/**< [173:173] If enabled, Time Offset induced phase is compensated during  frequency domain
                                                                 interpolation of Hrs on each data symbol. */
        uint64_t tdce_phasecomp_on     : 1;  /**< [172:172] If enabled, Frequency offset induced phase is compensated prior to TDCE and reapplied after TDCE. */
        uint64_t wscale_bitshift       : 3;  /**< [171:169] Indicate the amount of right shift on Weight in internal calucation.
                                                                 Valid range is [5,0].
                                                                 Must be log2([WEIGHT_SCALE]/32)
                                                                 Default value is 1 or 2. */
        uint64_t freq_hopping_on       : 1;  /**< [168:168] If enabled, UE has frequency hopping. */
        uint64_t snrdb_offset          : 10; /**< [167:158] Offset value used to stabilize the final PSINR value by offseting value in internal stages. */
        uint64_t rs_omega              : 1;  /**< [157:157] Omega is used for DMRS generation. Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_delta              : 1;  /**< [156:156] Delta for DMRS generation.  Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 0x0 = IFDMA off.
                                                                 0x1 = IFDMA on. */
        uint64_t rb_size_index         : 6;  /**< [155:150] RB Size index for DMRS generation.Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RB.
                                                                 0x22 = 108 RB.
                                                                 Valid range is [34,0] */
        uint64_t noise_c               : 12; /**< [149:138] Stabilising bias term applied to the diagonal of the channel correlation matrix
                                                                 during the Rhh matrix normalization process.
                                                                 Valid range [4095,0].
                                                                 Default value 10. */
        uint64_t noise_th              : 7;  /**< [137:131] Bias factor added to diagonal terms of the Rnn matrix after scaling (with and
                                                                 before thresholding).The maximum value of 1023 corresponds to biasing the 17-bit
                                                                 scaleddiag(Rnn) by 21 dB. */
        uint64_t rnn_bitshift          : 3;  /**< [130:128] Indicates the amount of right shift on Rnn in internal calculation and must be [RHH_BITSHIFT].
                                                                 Valid range is [7,0].
                                                                 Default value is 0. */
#else /* Word 2 - Little Endian */
        uint64_t rnn_bitshift          : 3;  /**< [130:128] Indicates the amount of right shift on Rnn in internal calculation and must be [RHH_BITSHIFT].
                                                                 Valid range is [7,0].
                                                                 Default value is 0. */
        uint64_t noise_th              : 7;  /**< [137:131] Bias factor added to diagonal terms of the Rnn matrix after scaling (with and
                                                                 before thresholding).The maximum value of 1023 corresponds to biasing the 17-bit
                                                                 scaleddiag(Rnn) by 21 dB. */
        uint64_t noise_c               : 12; /**< [149:138] Stabilising bias term applied to the diagonal of the channel correlation matrix
                                                                 during the Rhh matrix normalization process.
                                                                 Valid range [4095,0].
                                                                 Default value 10. */
        uint64_t rb_size_index         : 6;  /**< [155:150] RB Size index for DMRS generation.Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RB.
                                                                 0x22 = 108 RB.
                                                                 Valid range is [34,0] */
        uint64_t rs_delta              : 1;  /**< [156:156] Delta for DMRS generation.  Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 0x0 = IFDMA off.
                                                                 0x1 = IFDMA on. */
        uint64_t rs_omega              : 1;  /**< [157:157] Omega is used for DMRS generation. Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t snrdb_offset          : 10; /**< [167:158] Offset value used to stabilize the final PSINR value by offseting value in internal stages. */
        uint64_t freq_hopping_on       : 1;  /**< [168:168] If enabled, UE has frequency hopping. */
        uint64_t wscale_bitshift       : 3;  /**< [171:169] Indicate the amount of right shift on Weight in internal calucation.
                                                                 Valid range is [5,0].
                                                                 Must be log2([WEIGHT_SCALE]/32)
                                                                 Default value is 1 or 2. */
        uint64_t tdce_phasecomp_on     : 1;  /**< [172:172] If enabled, Frequency offset induced phase is compensated prior to TDCE and reapplied after TDCE. */
        uint64_t rs_channel_phasecomp_on : 1;/**< [173:173] If enabled, Time Offset induced phase is compensated during  frequency domain
                                                                 interpolation of Hrs on each data symbol. */
        uint64_t reserved_174_176      : 3;
        uint64_t dmrs_pattern_bitmap   : 12; /**< [188:177] A bitmap indicating the DMRS pattern in CP-OFDM RB. MSB corresponds to tone index 0.
                                                                 0x0 = DTX or data.
                                                                 0x1 = DMRS. */
        uint64_t reserved_189_191      : 3;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_246_255      : 10;
        uint64_t subprb_3tone_case_idx : 2;  /**< [245:244] Indicates the UE allocation pattern in  subPRB.
                                                                 0x0 = all 3 tones.
                                                                 0x1 = upper two tones.
                                                                 0x2 = lower two tones. */
        uint64_t simo_rnn_based_irc_on : 1;  /**< [243:243] When enabled, the equalizer kernel is selected as Rnn. Valid when
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x0 or 0x2 or
                                                                 0x3.
                                                                 0x0 = Rnn+Rhh.
                                                                 0x1 = R=Rnn. */
        uint64_t reserved_242          : 1;
        uint64_t ryy_irc_threshold_p   : 10; /**< [241:232] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_threshold_m   : 10; /**< [231:222] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_off_th        : 10; /**< [221:212] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_diagloading_factor_0 : 10;/**< [211:202] A bias factor applied to diagonal of the Ryy matrix.
                                                                 Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_diagloading_factor_1 : 10;/**< [201:192] A bias factor applied to diagonal of the Ryy matrix.
                                                                 Assist in selection of equalizer kernel when
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
#else /* Word 3 - Little Endian */
        uint64_t ryy_diagloading_factor_1 : 10;/**< [201:192] A bias factor applied to diagonal of the Ryy matrix.
                                                                 Assist in selection of equalizer kernel when
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_diagloading_factor_0 : 10;/**< [211:202] A bias factor applied to diagonal of the Ryy matrix.
                                                                 Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_off_th        : 10; /**< [221:212] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_threshold_m   : 10; /**< [231:222] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_threshold_p   : 10; /**< [241:232] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t reserved_242          : 1;
        uint64_t simo_rnn_based_irc_on : 1;  /**< [243:243] When enabled, the equalizer kernel is selected as Rnn. Valid when
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x0 or 0x2 or
                                                                 0x3.
                                                                 0x0 = Rnn+Rhh.
                                                                 0x1 = R=Rnn. */
        uint64_t subprb_3tone_case_idx : 2;  /**< [245:244] Indicates the UE allocation pattern in  subPRB.
                                                                 0x0 = all 3 tones.
                                                                 0x1 = upper two tones.
                                                                 0x2 = lower two tones. */
        uint64_t reserved_246_255      : 10;
#endif /* Word 3 - End */
    } s;
    struct cavm_fdeq_rdcfg_ue_phyc_params_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t gain_norm_on          : 1;  /**< [ 60: 60] If enabled (0x1), equalized output is normalized by a scale derived from equalized weight.
                                                                 Only valid for CP-OFDM UE with FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 1.
                                                                 Must be enabled for all CP-OFDM UEs for normal operation. */
        uint64_t r_norm_target_level   : 3;  /**< [ 59: 57] Power level of the normalized R matrix, calculated as 2^(16+[R_NORM_TARGET_LEVEL]).
                                                                 Valid range is [4,2] */
        uint64_t rs_slot1_rb_offset    : 8;  /**< [ 56: 49] Indicate RB offset of DMRS sequence for slot 1 in the given job. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 Valid range is [107,0]. */
        uint64_t rs_slot0_rb_offset    : 8;  /**< [ 48: 41] Indicate RB offset of DMRS sequence for slot 0 in the given job.Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 Valid range is [107,0]. */
        uint64_t rs_slot1_cs           : 4;  /**< [ 40: 37] Cyclic Sshift for DMRS generation of slot 1. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. Valid range is
                                                                 [11,0]. */
        uint64_t rs_slot1_u            : 5;  /**< [ 36: 32] u for DMRS generation of slot 1.
                                                                 Valid range is [29,0]
                                                                 Valid when FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_slot1_v            : 1;  /**< [ 31: 31] v for DMRS generation of slot 1. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. Valid range is
                                                                 [1,0] */
        uint64_t rs_slot1_occ          : 1;  /**< [ 30: 30] OCC for DMRS generation of slot 1. 0x0 = [1,1] 0x1 = [1, 0].
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_slot0_cs           : 4;  /**< [ 29: 26] Definition same as slot 1. */
        uint64_t rs_slot0_u            : 5;  /**< [ 25: 21] Definition same as slot 1. */
        uint64_t rs_slot0_v            : 1;  /**< [ 20: 20] Definition same as slot 1. */
        uint64_t rs_slot0_occ          : 1;  /**< [ 19: 19] Definition same as slot 1. */
        uint64_t cp_ofdm_on            : 1;  /**< [ 18: 18] 0x0 = DFTs-OFDM.
                                                                 0x1 = CP-OFDM. */
        uint64_t antenna_on_off_bitmap : 16; /**< [ 17:  2] If the (15-n)th bit of the bitmap is 0, the hrs correponding to nth antenna is
                                                                 zeros out for the UE. */
        uint64_t reserved_1            : 1;
        uint64_t ue_enable             : 1;  /**< [  0:  0] If disabled, the UE is disabled. Disabled UE is not processed even if parameters
                                                                 are given in this config. */
#else /* Word 0 - Little Endian */
        uint64_t ue_enable             : 1;  /**< [  0:  0] If disabled, the UE is disabled. Disabled UE is not processed even if parameters
                                                                 are given in this config. */
        uint64_t reserved_1            : 1;
        uint64_t antenna_on_off_bitmap : 16; /**< [ 17:  2] If the (15-n)th bit of the bitmap is 0, the hrs correponding to nth antenna is
                                                                 zeros out for the UE. */
        uint64_t cp_ofdm_on            : 1;  /**< [ 18: 18] 0x0 = DFTs-OFDM.
                                                                 0x1 = CP-OFDM. */
        uint64_t rs_slot0_occ          : 1;  /**< [ 19: 19] Definition same as slot 1. */
        uint64_t rs_slot0_v            : 1;  /**< [ 20: 20] Definition same as slot 1. */
        uint64_t rs_slot0_u            : 5;  /**< [ 25: 21] Definition same as slot 1. */
        uint64_t rs_slot0_cs           : 4;  /**< [ 29: 26] Definition same as slot 1. */
        uint64_t rs_slot1_occ          : 1;  /**< [ 30: 30] OCC for DMRS generation of slot 1. 0x0 = [1,1] 0x1 = [1, 0].
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_slot1_v            : 1;  /**< [ 31: 31] v for DMRS generation of slot 1. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. Valid range is
                                                                 [1,0] */
        uint64_t rs_slot1_u            : 5;  /**< [ 36: 32] u for DMRS generation of slot 1.
                                                                 Valid range is [29,0]
                                                                 Valid when FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_slot1_cs           : 4;  /**< [ 40: 37] Cyclic Sshift for DMRS generation of slot 1. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. Valid range is
                                                                 [11,0]. */
        uint64_t rs_slot0_rb_offset    : 8;  /**< [ 48: 41] Indicate RB offset of DMRS sequence for slot 0 in the given job.Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 Valid range is [107,0]. */
        uint64_t rs_slot1_rb_offset    : 8;  /**< [ 56: 49] Indicate RB offset of DMRS sequence for slot 1 in the given job. Valid if
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 Valid range is [107,0]. */
        uint64_t r_norm_target_level   : 3;  /**< [ 59: 57] Power level of the normalized R matrix, calculated as 2^(16+[R_NORM_TARGET_LEVEL]).
                                                                 Valid range is [4,2] */
        uint64_t gain_norm_on          : 1;  /**< [ 60: 60] If enabled (0x1), equalized output is normalized by a scale derived from equalized weight.
                                                                 Only valid for CP-OFDM UE with FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] = 1.
                                                                 Must be enabled for all CP-OFDM UEs for normal operation. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_123_127      : 5;
        uint64_t configured_psinr      : 5;  /**< [122:118] Override internally calculated PSINR when conditions in [PSINR_METHOD] are met.
                                                                 Valid range is [31,0]. */
        uint64_t psinr_method          : 1;  /**< [117:117] Defines PSINR calculation method.
                                                                 0x0 = Wh method.
                                                                 0x1 = Wy method.
                                                                 Set to 0 when [CP_OFDM_ON] =1. */
        uint64_t ref_tagc_mode         : 1;  /**< [116:116] Defines how to adjust gain difference between symbols with different TAGC values.
                                                                 0x0 = use TAGC of symbol 0 as reference.
                                                                 0x1 = use average TAGC of all symbols as reference. */
        uint64_t r_diagloading_threshold : 10;/**< [115:106] Used by FDEQ to seclect if R inversion with [R_DIAGLOADING_FACTOR_0] or R
                                                                 inversion with [R_DIAGLOADING_FACTOR_1] is used.
                                                                 Default value is 0x1.
                                                                 The default value selects R inversion with [R_DIAGLOADING_FACTOR_1]. */
        uint64_t reserved_105          : 1;
        uint64_t reserved_104          : 1;
        uint64_t h_rs_average_on       : 1;  /**< [103:103] If enabled Hrs is averaged across all RS before Rnn calculation.
                                                                 Only valid if FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 2 or 4. */
        uint64_t rhh_bitshift          : 3;  /**< [102:100] Indicates the amount of right shift on the internally calculated Rhh in internal
                                                                 calculation. Valid range is [7,0].Default value is 0. */
        uint64_t ce_bitshift           : 2;  /**< [ 99: 98] Indiates the amount of right shift on Hrs in additional
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[H_DMRS_INPUT_BITSHIFT] and g_FAGC. Valid
                                                                 range is [3,0]. Default value is 0. */
        uint64_t r_diagloading_factor_0 : 10;/**< [ 97: 88] A bias factor applied to diagonal of the R matrix.
                                                                 Default value is 0x2.
                                                                 R_DIAGLOADING_FACTOR_0 must be greater than [R_DIAGLOADING_FACTOR_1]. */
        uint64_t r_diagloading_factor_1 : 10;/**< [ 87: 78] A bias factor applied to diagonal of the R matrix.
                                                                 Default value is 0x1.
                                                                 R_DIAGLOADING_FACTOR_1 must be less than [R_DIAGLOADING_FACTOR_0]. */
        uint64_t channel_interp_on     : 1;  /**< [ 77: 77] If set to 1, frequency domain interpolation of CE after TDCE is enabled for SIC
                                                                 operation. Valid only when FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] is
                                                                 0x1. */
        uint64_t channel_phasecomp_on  : 1;  /**< [ 76: 76] If enabled, phase compensation due to time offset is applied in frequency domain
                                                                 interpolation of Hrs on each data symbol. */
        uint64_t weight_interp_on      : 1;  /**< [ 75: 75] If enabled the equalizer weights in frequency domain are interpolated. */
        uint64_t weight_phasecomp_on   : 1;  /**< [ 74: 74] If enabled  phase compensation due to time Offset is applied in the frequency
                                                                 domain interpolation of equalizer weights. */
        uint64_t weight_scale          : 10; /**< [ 73: 64] Value of internal bit shift applied to the equalizer weights. Valid values are
                                                                 is [512,256,128,64,32,0]. Must be same as 32*2^[WSCALE_BITSHIFT] Default is 32
                                                                 or 64. */
#else /* Word 1 - Little Endian */
        uint64_t weight_scale          : 10; /**< [ 73: 64] Value of internal bit shift applied to the equalizer weights. Valid values are
                                                                 is [512,256,128,64,32,0]. Must be same as 32*2^[WSCALE_BITSHIFT] Default is 32
                                                                 or 64. */
        uint64_t weight_phasecomp_on   : 1;  /**< [ 74: 74] If enabled  phase compensation due to time Offset is applied in the frequency
                                                                 domain interpolation of equalizer weights. */
        uint64_t weight_interp_on      : 1;  /**< [ 75: 75] If enabled the equalizer weights in frequency domain are interpolated. */
        uint64_t channel_phasecomp_on  : 1;  /**< [ 76: 76] If enabled, phase compensation due to time offset is applied in frequency domain
                                                                 interpolation of Hrs on each data symbol. */
        uint64_t channel_interp_on     : 1;  /**< [ 77: 77] If set to 1, frequency domain interpolation of CE after TDCE is enabled for SIC
                                                                 operation. Valid only when FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] is
                                                                 0x1. */
        uint64_t r_diagloading_factor_1 : 10;/**< [ 87: 78] A bias factor applied to diagonal of the R matrix.
                                                                 Default value is 0x1.
                                                                 R_DIAGLOADING_FACTOR_1 must be less than [R_DIAGLOADING_FACTOR_0]. */
        uint64_t r_diagloading_factor_0 : 10;/**< [ 97: 88] A bias factor applied to diagonal of the R matrix.
                                                                 Default value is 0x2.
                                                                 R_DIAGLOADING_FACTOR_0 must be greater than [R_DIAGLOADING_FACTOR_1]. */
        uint64_t ce_bitshift           : 2;  /**< [ 99: 98] Indiates the amount of right shift on Hrs in additional
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[H_DMRS_INPUT_BITSHIFT] and g_FAGC. Valid
                                                                 range is [3,0]. Default value is 0. */
        uint64_t rhh_bitshift          : 3;  /**< [102:100] Indicates the amount of right shift on the internally calculated Rhh in internal
                                                                 calculation. Valid range is [7,0].Default value is 0. */
        uint64_t h_rs_average_on       : 1;  /**< [103:103] If enabled Hrs is averaged across all RS before Rnn calculation.
                                                                 Only valid if FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] = 2 or 4. */
        uint64_t reserved_104          : 1;
        uint64_t reserved_105          : 1;
        uint64_t r_diagloading_threshold : 10;/**< [115:106] Used by FDEQ to seclect if R inversion with [R_DIAGLOADING_FACTOR_0] or R
                                                                 inversion with [R_DIAGLOADING_FACTOR_1] is used.
                                                                 Default value is 0x1.
                                                                 The default value selects R inversion with [R_DIAGLOADING_FACTOR_1]. */
        uint64_t ref_tagc_mode         : 1;  /**< [116:116] Defines how to adjust gain difference between symbols with different TAGC values.
                                                                 0x0 = use TAGC of symbol 0 as reference.
                                                                 0x1 = use average TAGC of all symbols as reference. */
        uint64_t psinr_method          : 1;  /**< [117:117] Defines PSINR calculation method.
                                                                 0x0 = Wh method.
                                                                 0x1 = Wy method.
                                                                 Set to 0 when [CP_OFDM_ON] =1. */
        uint64_t configured_psinr      : 5;  /**< [122:118] Override internally calculated PSINR when conditions in [PSINR_METHOD] are met.
                                                                 Valid range is [31,0]. */
        uint64_t reserved_123_127      : 5;
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_189_191      : 3;
        uint64_t dmrs_pattern_bitmap   : 12; /**< [188:177] A bitmap indicating the DMRS pattern in CP-OFDM RB. MSB corresponds to tone index 0.
                                                                 0x0 = DTX or data.
                                                                 0x1 = DMRS. */
        uint64_t reserved_174_176      : 3;
        uint64_t rs_channel_phasecomp_on : 1;/**< [173:173] If enabled, Time Offset induced phase is compensated during  frequency domain
                                                                 interpolation of Hrs on each data symbol. */
        uint64_t tdce_phasecomp_on     : 1;  /**< [172:172] If enabled, Frequency offset induced phase is compensated prior to TDCE and reapplied after TDCE. */
        uint64_t wscale_bitshift       : 3;  /**< [171:169] Indicate the amount of right shift on Weight in internal calucation.
                                                                 Valid range is [5,0].
                                                                 Must be log2([WEIGHT_SCALE]/32)
                                                                 Default value is 1 or 2. */
        uint64_t freq_hopping_on       : 1;  /**< [168:168] If enabled, UE has frequency hopping. */
        uint64_t snrdb_offset          : 10; /**< [167:158] Offset value used to stabilize the final PSINR value by offseting value in internal stages. */
        uint64_t rs_omega              : 1;  /**< [157:157] Omega is used for DMRS generation. Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t rs_delta              : 1;  /**< [156:156] Delta for DMRS generation.  Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 0x0 = IFDMA off.
                                                                 0x1 = IFDMA on. */
        uint64_t rb_size_index         : 6;  /**< [155:150] RB Size index for DMRS generation.Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RB.
                                                                 0x22 = 108 RB.
                                                                 Valid range is [34,0] */
        uint64_t noise_c               : 12; /**< [149:138] Stabilising bias term applied to the diagonal of the channel correlation matrix
                                                                 during the Rhh matrix normalization process.
                                                                 Valid range [4095,0].
                                                                 Default value 10. */
        uint64_t noise_th              : 7;  /**< [137:131] Bias factor added to diagonal terms of the Rnn matrix after scaling (with and
                                                                 before thresholding).The maximum value of 1023 corresponds to biasing the 17-bit
                                                                 scaleddiag(Rnn) by 21 dB. */
        uint64_t rnn_bitshift          : 3;  /**< [130:128] Indicates the amount of right shift on Rnn in internal calculation and must be [RHH_BITSHIFT].
                                                                 Valid range is [7,0].
                                                                 Default value is 0. */
#else /* Word 2 - Little Endian */
        uint64_t rnn_bitshift          : 3;  /**< [130:128] Indicates the amount of right shift on Rnn in internal calculation and must be [RHH_BITSHIFT].
                                                                 Valid range is [7,0].
                                                                 Default value is 0. */
        uint64_t noise_th              : 7;  /**< [137:131] Bias factor added to diagonal terms of the Rnn matrix after scaling (with and
                                                                 before thresholding).The maximum value of 1023 corresponds to biasing the 17-bit
                                                                 scaleddiag(Rnn) by 21 dB. */
        uint64_t noise_c               : 12; /**< [149:138] Stabilising bias term applied to the diagonal of the channel correlation matrix
                                                                 during the Rhh matrix normalization process.
                                                                 Valid range [4095,0].
                                                                 Default value 10. */
        uint64_t rb_size_index         : 6;  /**< [155:150] RB Size index for DMRS generation.Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 0x0 = 1 RB.
                                                                 0x1 = 2 RB.
                                                                 0x22 = 108 RB.
                                                                 Valid range is [34,0] */
        uint64_t rs_delta              : 1;  /**< [156:156] Delta for DMRS generation.  Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1.
                                                                 0x0 = IFDMA off.
                                                                 0x1 = IFDMA on. */
        uint64_t rs_omega              : 1;  /**< [157:157] Omega is used for DMRS generation. Valid when
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[RS_SEQUENCE_GENERATION_ENABLE]=1. */
        uint64_t snrdb_offset          : 10; /**< [167:158] Offset value used to stabilize the final PSINR value by offseting value in internal stages. */
        uint64_t freq_hopping_on       : 1;  /**< [168:168] If enabled, UE has frequency hopping. */
        uint64_t wscale_bitshift       : 3;  /**< [171:169] Indicate the amount of right shift on Weight in internal calucation.
                                                                 Valid range is [5,0].
                                                                 Must be log2([WEIGHT_SCALE]/32)
                                                                 Default value is 1 or 2. */
        uint64_t tdce_phasecomp_on     : 1;  /**< [172:172] If enabled, Frequency offset induced phase is compensated prior to TDCE and reapplied after TDCE. */
        uint64_t rs_channel_phasecomp_on : 1;/**< [173:173] If enabled, Time Offset induced phase is compensated during  frequency domain
                                                                 interpolation of Hrs on each data symbol. */
        uint64_t reserved_174_176      : 3;
        uint64_t dmrs_pattern_bitmap   : 12; /**< [188:177] A bitmap indicating the DMRS pattern in CP-OFDM RB. MSB corresponds to tone index 0.
                                                                 0x0 = DTX or data.
                                                                 0x1 = DMRS. */
        uint64_t reserved_189_191      : 3;
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_246_255      : 10;
        uint64_t subprb_3tone_case_idx : 2;  /**< [245:244] Indicates the UE allocation pattern in  subPRB.
                                                                 0x0 = all 3 tones.
                                                                 0x1 = upper two tones.
                                                                 0x2 = lower two tones. */
        uint64_t simo_rnn_based_irc_on : 1;  /**< [243:243] When enabled, the equalizer kernel is selected as Rnn. Valid when
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x0 or 0x2 or
                                                                 0x3.
                                                                 0x0 = Rnn+Rhh.
                                                                 0x1 = R=Rnn. */
        uint64_t reserved_242          : 1;
        uint64_t ryy_irc_threshold_p   : 10; /**< [241:232] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_threshold_m   : 10; /**< [231:222] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_off_th        : 10; /**< [221:212] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_diagloading_factor_0 : 10;/**< [211:202] A bias factor applied to diagonal of the Ryy matrix.
                                                                 Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_diagloading_factor_1 : 10;/**< [201:192] A bias factor applied to diagonal of the Ryy matrix.
                                                                 Assist in selection of equalizer kernel when
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
#else /* Word 3 - Little Endian */
        uint64_t ryy_diagloading_factor_1 : 10;/**< [201:192] A bias factor applied to diagonal of the Ryy matrix.
                                                                 Assist in selection of equalizer kernel when
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_diagloading_factor_0 : 10;/**< [211:202] A bias factor applied to diagonal of the Ryy matrix.
                                                                 Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_off_th        : 10; /**< [221:212] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_threshold_m   : 10; /**< [231:222] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t ryy_irc_threshold_p   : 10; /**< [241:232] Assist in selection of equalizer kernel when FDEQ_RDCFG_RB_PARAMS_JT1_S[
                                                                 IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x2 or 0x03.
                                                                 Valid range is [1023,0]. */
        uint64_t reserved_242          : 1;
        uint64_t simo_rnn_based_irc_on : 1;  /**< [243:243] When enabled, the equalizer kernel is selected as Rnn. Valid when
                                                                 FDEQ_RDCFG_RB_PARAMS_JT1_S[IRC_MODE_DATA_SYMBOL_k], k=0..13, is 0x0 or 0x2 or
                                                                 0x3.
                                                                 0x0 = Rnn+Rhh.
                                                                 0x1 = R=Rnn. */
        uint64_t subprb_3tone_case_idx : 2;  /**< [245:244] Indicates the UE allocation pattern in  subPRB.
                                                                 0x0 = all 3 tones.
                                                                 0x1 = upper two tones.
                                                                 0x2 = lower two tones. */
        uint64_t reserved_246_255      : 10;
#endif /* Word 3 - End */
    } cn;
};

/**
 * Structure fdeq_rdcfg_ue_tagc_s
 *
 * FDEQ TAGC Parameter Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_ue_tagc_s
{
    uint64_t u[2];
    struct cavm_fdeq_rdcfg_ue_tagc_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t tagc_gain_ant_7       : 5;  /**< [ 60: 56] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_53_55        : 3;
        uint64_t tagc_gain_ant_6       : 5;  /**< [ 52: 48] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_45_47        : 3;
        uint64_t tagc_gain_ant_5       : 5;  /**< [ 44: 40] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_37_39        : 3;
        uint64_t tagc_gain_ant_4       : 5;  /**< [ 36: 32] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_29_31        : 3;
        uint64_t tagc_gain_ant_3       : 5;  /**< [ 28: 24] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_21_23        : 3;
        uint64_t tagc_gain_ant_2       : 5;  /**< [ 20: 16] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_13_15        : 3;
        uint64_t tagc_gain_ant_1       : 5;  /**< [ 12:  8] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_5_7          : 3;
        uint64_t tagc_gain_ant_0       : 5;  /**< [  4:  0] Indicates the value of time domain AGC for the refered antenna. A TAGC value of
                                                                 m is 2^(m-n) higher than an atenna with TAGC value of  n. Valid range is
                                                                 [-16,15]. */
#else /* Word 0 - Little Endian */
        uint64_t tagc_gain_ant_0       : 5;  /**< [  4:  0] Indicates the value of time domain AGC for the refered antenna. A TAGC value of
                                                                 m is 2^(m-n) higher than an atenna with TAGC value of  n. Valid range is
                                                                 [-16,15]. */
        uint64_t reserved_5_7          : 3;
        uint64_t tagc_gain_ant_1       : 5;  /**< [ 12:  8] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_13_15        : 3;
        uint64_t tagc_gain_ant_2       : 5;  /**< [ 20: 16] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_21_23        : 3;
        uint64_t tagc_gain_ant_3       : 5;  /**< [ 28: 24] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_29_31        : 3;
        uint64_t tagc_gain_ant_4       : 5;  /**< [ 36: 32] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_37_39        : 3;
        uint64_t tagc_gain_ant_5       : 5;  /**< [ 44: 40] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_45_47        : 3;
        uint64_t tagc_gain_ant_6       : 5;  /**< [ 52: 48] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_53_55        : 3;
        uint64_t tagc_gain_ant_7       : 5;  /**< [ 60: 56] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_125_127      : 3;
        uint64_t tagc_gain_ant_15      : 5;  /**< [124:120] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_117_119      : 3;
        uint64_t tagc_gain_ant_14      : 5;  /**< [116:112] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_109_111      : 3;
        uint64_t tagc_gain_ant_13      : 5;  /**< [108:104] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_101_103      : 3;
        uint64_t tagc_gain_ant_12      : 5;  /**< [100: 96] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_93_95        : 3;
        uint64_t tagc_gain_ant_11      : 5;  /**< [ 92: 88] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_85_87        : 3;
        uint64_t tagc_gain_ant_10      : 5;  /**< [ 84: 80] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_77_79        : 3;
        uint64_t tagc_gain_ant_9       : 5;  /**< [ 76: 72] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_69_71        : 3;
        uint64_t tagc_gain_ant_8       : 5;  /**< [ 68: 64] Refer to [TAGC_GAIN_ANT_0]. */
#else /* Word 1 - Little Endian */
        uint64_t tagc_gain_ant_8       : 5;  /**< [ 68: 64] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_69_71        : 3;
        uint64_t tagc_gain_ant_9       : 5;  /**< [ 76: 72] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_77_79        : 3;
        uint64_t tagc_gain_ant_10      : 5;  /**< [ 84: 80] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_85_87        : 3;
        uint64_t tagc_gain_ant_11      : 5;  /**< [ 92: 88] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_93_95        : 3;
        uint64_t tagc_gain_ant_12      : 5;  /**< [100: 96] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_101_103      : 3;
        uint64_t tagc_gain_ant_13      : 5;  /**< [108:104] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_109_111      : 3;
        uint64_t tagc_gain_ant_14      : 5;  /**< [116:112] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_117_119      : 3;
        uint64_t tagc_gain_ant_15      : 5;  /**< [124:120] Refer to [TAGC_GAIN_ANT_0]. */
        uint64_t reserved_125_127      : 3;
#endif /* Word 1 - End */
    } s;
    /* struct cavm_fdeq_rdcfg_ue_tagc_s_s cn; */
};

/**
 * Structure fdeq_rdcfg_ue_twf_to_16r_s
 *
 * FDEQ DMA Read port Time weight filter and Time offset for 16 receive antenna Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_ue_twf_to_16r_s
{
    uint64_t u[4];
    struct cavm_fdeq_rdcfg_ue_twf_to_16r_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t timewf_index_ant_3    : 4;  /**< [ 63: 60] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_3  : 12; /**< [ 59: 48] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_2    : 4;  /**< [ 47: 44] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_2  : 12; /**< [ 43: 32] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_1    : 4;  /**< [ 31: 28] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_1  : 12; /**< [ 27: 16] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_0    : 4;  /**< [ 15: 12] In the name TIMEWF_INDEX_ANT_r, r refers to antenna index.
                                                                 This parameter indicates the index of time domain weigth filter set used for antenna r.
                                                                 Valid range is [FDEQ()_JD_RS_GENERAL_PARAMETER[TIMEWF_SET_NUMBER]-1,0].
                                                                 Only the one specified for the RS
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER]-1 are valid and others are
                                                                 ignored. */
        uint64_t timeoffset_rs0_ant_0  : 12; /**< [ 11:  0] In the name TIMEOFFSET_RS_s_ANT_r, the tuple (s,r) refers to RS and antenna index.
                                                                 This parameter indicates the indicates the phase due to time offset on RS s and antenna r.
                                                                 Valid range is [4095,0].
                                                                 Unit is 2*pi/4096. */
#else /* Word 0 - Little Endian */
        uint64_t timeoffset_rs0_ant_0  : 12; /**< [ 11:  0] In the name TIMEOFFSET_RS_s_ANT_r, the tuple (s,r) refers to RS and antenna index.
                                                                 This parameter indicates the indicates the phase due to time offset on RS s and antenna r.
                                                                 Valid range is [4095,0].
                                                                 Unit is 2*pi/4096. */
        uint64_t timewf_index_ant_0    : 4;  /**< [ 15: 12] In the name TIMEWF_INDEX_ANT_r, r refers to antenna index.
                                                                 This parameter indicates the index of time domain weigth filter set used for antenna r.
                                                                 Valid range is [FDEQ()_JD_RS_GENERAL_PARAMETER[TIMEWF_SET_NUMBER]-1,0].
                                                                 Only the one specified for the RS
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER]-1 are valid and others are
                                                                 ignored. */
        uint64_t timeoffset_rs0_ant_1  : 12; /**< [ 27: 16] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_1    : 4;  /**< [ 31: 28] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_2  : 12; /**< [ 43: 32] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_2    : 4;  /**< [ 47: 44] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_3  : 12; /**< [ 59: 48] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_3    : 4;  /**< [ 63: 60] Refer [TIMEWF_INDEX_ANT_0]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t timewf_index_ant_7    : 4;  /**< [127:124] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_7  : 12; /**< [123:112] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_6    : 4;  /**< [111:108] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_6  : 12; /**< [107: 96] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_5    : 4;  /**< [ 95: 92] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_5  : 12; /**< [ 91: 80] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_4    : 4;  /**< [ 79: 76] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_4  : 12; /**< [ 75: 64] Refer [TIMEOFFSET_RS0_ANT_0]. */
#else /* Word 1 - Little Endian */
        uint64_t timeoffset_rs0_ant_4  : 12; /**< [ 75: 64] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_4    : 4;  /**< [ 79: 76] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_5  : 12; /**< [ 91: 80] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_5    : 4;  /**< [ 95: 92] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_6  : 12; /**< [107: 96] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_6    : 4;  /**< [111:108] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_7  : 12; /**< [123:112] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_7    : 4;  /**< [127:124] Refer [TIMEWF_INDEX_ANT_0]. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t timewf_index_ant_11   : 4;  /**< [191:188] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_11 : 12; /**< [187:176] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_10   : 4;  /**< [175:172] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_10 : 12; /**< [171:160] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_9    : 4;  /**< [159:156] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_9  : 12; /**< [155:144] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_8    : 4;  /**< [143:140] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_8  : 12; /**< [139:128] Refer [TIMEOFFSET_RS0_ANT_0]. */
#else /* Word 2 - Little Endian */
        uint64_t timeoffset_rs0_ant_8  : 12; /**< [139:128] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_8    : 4;  /**< [143:140] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_9  : 12; /**< [155:144] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_9    : 4;  /**< [159:156] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_10 : 12; /**< [171:160] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_10   : 4;  /**< [175:172] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_11 : 12; /**< [187:176] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_11   : 4;  /**< [191:188] Refer [TIMEWF_INDEX_ANT_0]. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t timewf_index_ant_15   : 4;  /**< [255:252] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_15 : 12; /**< [251:240] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_14   : 4;  /**< [239:236] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_14 : 12; /**< [235:224] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_13   : 4;  /**< [223:220] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_13 : 12; /**< [219:208] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_12   : 4;  /**< [207:204] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_12 : 12; /**< [203:192] Refer [TIMEOFFSET_RS0_ANT_0]. */
#else /* Word 3 - Little Endian */
        uint64_t timeoffset_rs0_ant_12 : 12; /**< [203:192] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_12   : 4;  /**< [207:204] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_13 : 12; /**< [219:208] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_13   : 4;  /**< [223:220] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_14 : 12; /**< [235:224] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_14   : 4;  /**< [239:236] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_15 : 12; /**< [251:240] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_15   : 4;  /**< [255:252] Refer [TIMEWF_INDEX_ANT_0]. */
#endif /* Word 3 - End */
    } s;
    /* struct cavm_fdeq_rdcfg_ue_twf_to_16r_s_s cn; */
};

/**
 * Structure fdeq_rdcfg_ue_twf_to_8r_s
 *
 * FDEQ DMA Read port Time weight filter and Time offset for 8 receive antenna Structure
 * This structure defines the format of the job configuration of FDEQ.
 */
union cavm_fdeq_rdcfg_ue_twf_to_8r_s
{
    uint64_t u[2];
    struct cavm_fdeq_rdcfg_ue_twf_to_8r_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t timewf_index_ant_3    : 4;  /**< [ 63: 60] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_3  : 12; /**< [ 59: 48] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_2    : 4;  /**< [ 47: 44] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_2  : 12; /**< [ 43: 32] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_1    : 4;  /**< [ 31: 28] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_1  : 12; /**< [ 27: 16] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_0    : 4;  /**< [ 15: 12] In the name TIMEWF_INDEX_ANT_r, r refers to antenna index.
                                                                 This parameter indicates the index of time domain weigth filter set used for antenna r.
                                                                 Valid range is [FDEQ()_JD_RS_GENERAL_PARAMETER[TIMEWF_SET_NUMBER]-1,0].
                                                                 Only the one specified for the RS
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] - 1 are valid and others are
                                                                 ignored. */
        uint64_t timeoffset_rs0_ant_0  : 12; /**< [ 11:  0] In the name TIMEOFFSET_RS_s_ANT_r, the tuple (s,r) refers to RS and antenna index.
                                                                 This parameter indicates the indicates the phase due to time offset on RS s and antenna r.
                                                                 Valid range is [4095,0].
                                                                 Unit is 2*pi/4096. */
#else /* Word 0 - Little Endian */
        uint64_t timeoffset_rs0_ant_0  : 12; /**< [ 11:  0] In the name TIMEOFFSET_RS_s_ANT_r, the tuple (s,r) refers to RS and antenna index.
                                                                 This parameter indicates the indicates the phase due to time offset on RS s and antenna r.
                                                                 Valid range is [4095,0].
                                                                 Unit is 2*pi/4096. */
        uint64_t timewf_index_ant_0    : 4;  /**< [ 15: 12] In the name TIMEWF_INDEX_ANT_r, r refers to antenna index.
                                                                 This parameter indicates the index of time domain weigth filter set used for antenna r.
                                                                 Valid range is [FDEQ()_JD_RS_GENERAL_PARAMETER[TIMEWF_SET_NUMBER]-1,0].
                                                                 Only the one specified for the RS
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] - 1 are valid and others are
                                                                 ignored. */
        uint64_t timeoffset_rs0_ant_1  : 12; /**< [ 27: 16] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_1    : 4;  /**< [ 31: 28] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_2  : 12; /**< [ 43: 32] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_2    : 4;  /**< [ 47: 44] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_3  : 12; /**< [ 59: 48] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_3    : 4;  /**< [ 63: 60] Refer [TIMEWF_INDEX_ANT_0]. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t timewf_index_ant_7    : 4;  /**< [127:124] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_7  : 12; /**< [123:112] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_6    : 4;  /**< [111:108] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_6  : 12; /**< [107: 96] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_5    : 4;  /**< [ 95: 92] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_5  : 12; /**< [ 91: 80] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_4    : 4;  /**< [ 79: 76] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_4  : 12; /**< [ 75: 64] Refer [TIMEOFFSET_RS0_ANT_0]. */
#else /* Word 1 - Little Endian */
        uint64_t timeoffset_rs0_ant_4  : 12; /**< [ 75: 64] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_4    : 4;  /**< [ 79: 76] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_5  : 12; /**< [ 91: 80] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_5    : 4;  /**< [ 95: 92] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_6  : 12; /**< [107: 96] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_6    : 4;  /**< [111:108] Refer [TIMEWF_INDEX_ANT_0]. */
        uint64_t timeoffset_rs0_ant_7  : 12; /**< [123:112] Refer [TIMEOFFSET_RS0_ANT_0]. */
        uint64_t timewf_index_ant_7    : 4;  /**< [127:124] Refer [TIMEWF_INDEX_ANT_0]. */
#endif /* Word 1 - End */
    } s;
    /* struct cavm_fdeq_rdcfg_ue_twf_to_8r_s_s cn; */
};

/**
 * Register (RSL) fdeq#_control
 *
 * Register
 */
union cavm_fdeqx_control
{
    uint64_t u;
    struct cavm_fdeqx_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_id_2              : 16; /**< [ 63: 48](R/W) Job ID 2, read only */
        uint64_t job_id_1              : 16; /**< [ 47: 32](R/W) Job ID 1, read only */
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0, read only */
        uint64_t reserved_3_15         : 13;
        uint64_t start_in_optional_config_2 : 1;/**< [  2:  2](R/W) "'1' = start the HAB per config in optional CONFIGURATION 2
                                                                 (auto-clear). HAB start ignored if HAB status is busy (0x18[2]=1)." */
        uint64_t start_in_optional_config_1 : 1;/**< [  1:  1](R/W) "'1' = start the HAB per config in optional CONFIGURATION 1
                                                                 (auto-clear). HAB start ignored if HAB status is busy (0x18[1]=1)." */
        uint64_t start_in_optional_config_0 : 1;/**< [  0:  0](R/W) "'1' = start the HAB per config in CONFIGURATION 0 (auto-clear).
                                                                 HAB start ignored if HAB status is busy (0x18[0]=1)." */
#else /* Word 0 - Little Endian */
        uint64_t start_in_optional_config_0 : 1;/**< [  0:  0](R/W) "'1' = start the HAB per config in CONFIGURATION 0 (auto-clear).
                                                                 HAB start ignored if HAB status is busy (0x18[0]=1)." */
        uint64_t start_in_optional_config_1 : 1;/**< [  1:  1](R/W) "'1' = start the HAB per config in optional CONFIGURATION 1
                                                                 (auto-clear). HAB start ignored if HAB status is busy (0x18[1]=1)." */
        uint64_t start_in_optional_config_2 : 1;/**< [  2:  2](R/W) "'1' = start the HAB per config in optional CONFIGURATION 2
                                                                 (auto-clear). HAB start ignored if HAB status is busy (0x18[2]=1)." */
        uint64_t reserved_3_15         : 13;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0, read only */
        uint64_t job_id_1              : 16; /**< [ 47: 32](R/W) Job ID 1, read only */
        uint64_t job_id_2              : 16; /**< [ 63: 48](R/W) Job ID 2, read only */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_control_s cn; */
};
typedef union cavm_fdeqx_control cavm_fdeqx_control_t;

static inline uint64_t CAVM_FDEQX_CONTROL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_CONTROL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043200000ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_CONTROL", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_CONTROL(a) cavm_fdeqx_control_t
#define bustype_CAVM_FDEQX_CONTROL(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_CONTROL(a) "FDEQX_CONTROL"
#define busnum_CAVM_FDEQX_CONTROL(a) (a)
#define arguments_CAVM_FDEQX_CONTROL(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_error_source_register_0
 *
 * Register
 */
union cavm_fdeqx_error_source_register_0
{
    uint64_t u;
    struct cavm_fdeqx_error_source_register_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t port2_oflow_uflow_job_id : 16;/**< [ 63: 48](R/W1C) The first job ID which makes read port2 overflow/underflow, after
                                                                 reset or write clear */
        uint64_t port1_oflow_uflow_job_id : 16;/**< [ 47: 32](R/W1C) The first job ID which makes read port1 overflow/underflow, after
                                                                 reset or write clear */
        uint64_t port0_oflow_uflow_job_id : 16;/**< [ 31: 16](R/W1C) The first job ID which makes read port0 overflow/underflow, after
                                                                 reset or write clear */
        uint64_t reserved_8_15         : 8;
        uint64_t read_port3_overflow   : 1;  /**< [  7:  7](R/W1C) Read port3 overflow. */
        uint64_t read_port2_overflow   : 1;  /**< [  6:  6](R/W1C) Read port2 overflow. */
        uint64_t read_port1_overflow   : 1;  /**< [  5:  5](R/W1C) Read port1 overflow */
        uint64_t read_port0_overflow   : 1;  /**< [  4:  4](R/W1C) Read port0 overflow */
        uint64_t read_port3_underflow  : 1;  /**< [  3:  3](R/W1C) Read port3 underflow. */
        uint64_t read_port2_underflow  : 1;  /**< [  2:  2](R/W1C) Read port2 underflow. */
        uint64_t read_port1_underflow  : 1;  /**< [  1:  1](R/W1C) Read port1 underflow */
        uint64_t read_port0_underflow  : 1;  /**< [  0:  0](R/W1C) Read port0 underflow */
#else /* Word 0 - Little Endian */
        uint64_t read_port0_underflow  : 1;  /**< [  0:  0](R/W1C) Read port0 underflow */
        uint64_t read_port1_underflow  : 1;  /**< [  1:  1](R/W1C) Read port1 underflow */
        uint64_t read_port2_underflow  : 1;  /**< [  2:  2](R/W1C) Read port2 underflow. */
        uint64_t read_port3_underflow  : 1;  /**< [  3:  3](R/W1C) Read port3 underflow. */
        uint64_t read_port0_overflow   : 1;  /**< [  4:  4](R/W1C) Read port0 overflow */
        uint64_t read_port1_overflow   : 1;  /**< [  5:  5](R/W1C) Read port1 overflow */
        uint64_t read_port2_overflow   : 1;  /**< [  6:  6](R/W1C) Read port2 overflow. */
        uint64_t read_port3_overflow   : 1;  /**< [  7:  7](R/W1C) Read port3 overflow. */
        uint64_t reserved_8_15         : 8;
        uint64_t port0_oflow_uflow_job_id : 16;/**< [ 31: 16](R/W1C) The first job ID which makes read port0 overflow/underflow, after
                                                                 reset or write clear */
        uint64_t port1_oflow_uflow_job_id : 16;/**< [ 47: 32](R/W1C) The first job ID which makes read port1 overflow/underflow, after
                                                                 reset or write clear */
        uint64_t port2_oflow_uflow_job_id : 16;/**< [ 63: 48](R/W1C) The first job ID which makes read port2 overflow/underflow, after
                                                                 reset or write clear */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_error_source_register_0_s cn; */
};
typedef union cavm_fdeqx_error_source_register_0 cavm_fdeqx_error_source_register_0_t;

static inline uint64_t CAVM_FDEQX_ERROR_SOURCE_REGISTER_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_ERROR_SOURCE_REGISTER_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043200030ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_ERROR_SOURCE_REGISTER_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_ERROR_SOURCE_REGISTER_0(a) cavm_fdeqx_error_source_register_0_t
#define bustype_CAVM_FDEQX_ERROR_SOURCE_REGISTER_0(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_ERROR_SOURCE_REGISTER_0(a) "FDEQX_ERROR_SOURCE_REGISTER_0"
#define busnum_CAVM_FDEQX_ERROR_SOURCE_REGISTER_0(a) (a)
#define arguments_CAVM_FDEQX_ERROR_SOURCE_REGISTER_0(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_hab_status
 *
 * Register
 */
union cavm_fdeqx_hab_status
{
    uint64_t u;
    struct cavm_fdeqx_hab_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO) Ready - Ready to receive the next job */
        uint64_t reserved_3            : 1;
        uint64_t hab_status_configuration_2 : 1;/**< [  2:  2](RO) Indicates if the HAB is busy processing a job with CONFIGURATION 2
                                                                 (optional). '0' = ready (default) '1' = busy */
        uint64_t hab_status_configuration_1 : 1;/**< [  1:  1](RO) Indicates if the HAB is busy processing a job with CONFIGURATION 1
                                                                 (optional). '0' = ready (default) '1' = busy */
        uint64_t hab_status_configuration_0 : 1;/**< [  0:  0](RO) Indicates if the HAB is busy processing a job with CONFIGURATION 0.
                                                                 '0' = ready (default) '1' = busy */
#else /* Word 0 - Little Endian */
        uint64_t hab_status_configuration_0 : 1;/**< [  0:  0](RO) Indicates if the HAB is busy processing a job with CONFIGURATION 0.
                                                                 '0' = ready (default) '1' = busy */
        uint64_t hab_status_configuration_1 : 1;/**< [  1:  1](RO) Indicates if the HAB is busy processing a job with CONFIGURATION 1
                                                                 (optional). '0' = ready (default) '1' = busy */
        uint64_t hab_status_configuration_2 : 1;/**< [  2:  2](RO) Indicates if the HAB is busy processing a job with CONFIGURATION 2
                                                                 (optional). '0' = ready (default) '1' = busy */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO) Ready - Ready to receive the next job */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_hab_status_s cn; */
};
typedef union cavm_fdeqx_hab_status cavm_fdeqx_hab_status_t;

static inline uint64_t CAVM_FDEQX_HAB_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_HAB_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043200018ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_HAB_STATUS", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_HAB_STATUS(a) cavm_fdeqx_hab_status_t
#define bustype_CAVM_FDEQX_HAB_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_HAB_STATUS(a) "FDEQX_HAB_STATUS"
#define busnum_CAVM_FDEQX_HAB_STATUS(a) (a)
#define arguments_CAVM_FDEQX_HAB_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_jd_act_ue_num_for_hop
 *
 * Register
 */
union cavm_fdeqx_jd_act_ue_num_for_hop
{
    uint64_t u;
    struct cavm_fdeqx_jd_act_ue_num_for_hop_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t hop_index_per_symbol  : 28; /**< [ 51: 24](R/W) A two bit indicator  that indicates which of four hops a data symbol falls into.
                                                                 The two LSBs are DS index 0x0 - 0x3. Every two consecutive bits are for
                                                                 sequentially increasing DS indices.
                                                                 The two MSB are for DS index 13.
                                                                 The two bits indicate:
                                                                 0x0 = hop 0.
                                                                 0x1 = hop 1.
                                                                 0x2 = hop 2.
                                                                 0x3 = hop 3. */
        uint64_t act_ue_num_of_hop_3   : 6;  /**< [ 23: 18](R/W) Number of active UEs in this hop. */
        uint64_t act_ue_num_of_hop_2   : 6;  /**< [ 17: 12](R/W) Number of active UEs in this hop. */
        uint64_t act_ue_num_of_hop_1   : 6;  /**< [ 11:  6](R/W) Number of active UEs in this hop. */
        uint64_t act_ue_num_of_hop_0   : 6;  /**< [  5:  0](R/W) Number of active UEs in this hop. */
#else /* Word 0 - Little Endian */
        uint64_t act_ue_num_of_hop_0   : 6;  /**< [  5:  0](R/W) Number of active UEs in this hop. */
        uint64_t act_ue_num_of_hop_1   : 6;  /**< [ 11:  6](R/W) Number of active UEs in this hop. */
        uint64_t act_ue_num_of_hop_2   : 6;  /**< [ 17: 12](R/W) Number of active UEs in this hop. */
        uint64_t act_ue_num_of_hop_3   : 6;  /**< [ 23: 18](R/W) Number of active UEs in this hop. */
        uint64_t hop_index_per_symbol  : 28; /**< [ 51: 24](R/W) A two bit indicator  that indicates which of four hops a data symbol falls into.
                                                                 The two LSBs are DS index 0x0 - 0x3. Every two consecutive bits are for
                                                                 sequentially increasing DS indices.
                                                                 The two MSB are for DS index 13.
                                                                 The two bits indicate:
                                                                 0x0 = hop 0.
                                                                 0x1 = hop 1.
                                                                 0x2 = hop 2.
                                                                 0x3 = hop 3. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_jd_act_ue_num_for_hop_s cn; */
};
typedef union cavm_fdeqx_jd_act_ue_num_for_hop cavm_fdeqx_jd_act_ue_num_for_hop_t;

static inline uint64_t CAVM_FDEQX_JD_ACT_UE_NUM_FOR_HOP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JD_ACT_UE_NUM_FOR_HOP(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202040ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JD_ACT_UE_NUM_FOR_HOP", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JD_ACT_UE_NUM_FOR_HOP(a) cavm_fdeqx_jd_act_ue_num_for_hop_t
#define bustype_CAVM_FDEQX_JD_ACT_UE_NUM_FOR_HOP(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JD_ACT_UE_NUM_FOR_HOP(a) "FDEQX_JD_ACT_UE_NUM_FOR_HOP"
#define busnum_CAVM_FDEQX_JD_ACT_UE_NUM_FOR_HOP(a) (a)
#define arguments_CAVM_FDEQX_JD_ACT_UE_NUM_FOR_HOP(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_jd_hrs_buffer_param_0
 *
 * Register
 */
union cavm_fdeqx_jd_hrs_buffer_param_0
{
    uint64_t u;
    struct cavm_fdeqx_jd_hrs_buffer_param_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t active_ue_number      : 6;  /**< [ 62: 57](R/W) Indicates the total number of UEs that are active.
                                                                 Valid range is [32,1].
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t mixed_hrs_memory_type_enable : 1;/**< [ 56: 56](R/W) If set to 1, two type-0 and one type-1 memories are collectively used  for
                                                                 allocation of hrs of a single sector,rs,layer combination. */
        uint64_t hrs_buf_sidx_rs0_3_layer_7_3 : 7;/**< [ 55: 49](R/W) Refer to [HRS_BUF_SIDX_RS0_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs0_3_layer_6_2 : 7;/**< [ 48: 42](R/W) Refer to [HRS_BUF_SIDX_RS0_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs0_3_layer_5_1 : 7;/**< [ 41: 35](R/W) Refer to [HRS_BUF_SIDX_RS0_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs0_3_layer_4_0 : 7;/**< [ 34: 28](R/W) In name field HRS_BUF_SIDX_RSr_s_LAYER_l_m, the tuple (r,l) and (s,m) corresponds
                                                                 to a RS index and layer index pair.The parameter indicates which internal hrs
                                                                 buffer the hrs corresponding
                                                                 to the active RS and layer tuple is placed. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l) is the active
                                                                 tuple otherwise (s,m) is the active tuple.
                                                                 Valid range is [47,0]. */
        uint64_t hrs_buf_sidx_rs0_layer_3 : 7;/**< [ 27: 21](R/W) Refer to [HRS_BUF_SIDX_RS0_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs0_layer_2 : 7;/**< [ 20: 14](R/W) Refer to [HRS_BUF_SIDX_RS0_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs0_layer_1 : 7;/**< [ 13:  7](R/W) Refer to [HRS_BUF_SIDX_RS0_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs0_layer_0 : 7;/**< [  6:  0](R/W) In name field HRS_BUF_SIDX_RSr_LAYER_l, the tuple (r,l) corresponds to a
                                                                 RS index and layer index pair. The parameter indicates which internal hrs buffer the hrs
                                                                 corresponding to the  RS and layer tuple is stored.
                                                                 Valid range is [47,0]. */
#else /* Word 0 - Little Endian */
        uint64_t hrs_buf_sidx_rs0_layer_0 : 7;/**< [  6:  0](R/W) In name field HRS_BUF_SIDX_RSr_LAYER_l, the tuple (r,l) corresponds to a
                                                                 RS index and layer index pair. The parameter indicates which internal hrs buffer the hrs
                                                                 corresponding to the  RS and layer tuple is stored.
                                                                 Valid range is [47,0]. */
        uint64_t hrs_buf_sidx_rs0_layer_1 : 7;/**< [ 13:  7](R/W) Refer to [HRS_BUF_SIDX_RS0_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs0_layer_2 : 7;/**< [ 20: 14](R/W) Refer to [HRS_BUF_SIDX_RS0_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs0_layer_3 : 7;/**< [ 27: 21](R/W) Refer to [HRS_BUF_SIDX_RS0_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs0_3_layer_4_0 : 7;/**< [ 34: 28](R/W) In name field HRS_BUF_SIDX_RSr_s_LAYER_l_m, the tuple (r,l) and (s,m) corresponds
                                                                 to a RS index and layer index pair.The parameter indicates which internal hrs
                                                                 buffer the hrs corresponding
                                                                 to the active RS and layer tuple is placed. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l) is the active
                                                                 tuple otherwise (s,m) is the active tuple.
                                                                 Valid range is [47,0]. */
        uint64_t hrs_buf_sidx_rs0_3_layer_5_1 : 7;/**< [ 41: 35](R/W) Refer to [HRS_BUF_SIDX_RS0_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs0_3_layer_6_2 : 7;/**< [ 48: 42](R/W) Refer to [HRS_BUF_SIDX_RS0_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs0_3_layer_7_3 : 7;/**< [ 55: 49](R/W) Refer to [HRS_BUF_SIDX_RS0_3_LAYER_4_0]. */
        uint64_t mixed_hrs_memory_type_enable : 1;/**< [ 56: 56](R/W) If set to 1, two type-0 and one type-1 memories are collectively used  for
                                                                 allocation of hrs of a single sector,rs,layer combination. */
        uint64_t active_ue_number      : 6;  /**< [ 62: 57](R/W) Indicates the total number of UEs that are active.
                                                                 Valid range is [32,1].
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_jd_hrs_buffer_param_0_s cn; */
};
typedef union cavm_fdeqx_jd_hrs_buffer_param_0 cavm_fdeqx_jd_hrs_buffer_param_0_t;

static inline uint64_t CAVM_FDEQX_JD_HRS_BUFFER_PARAM_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JD_HRS_BUFFER_PARAM_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202010ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JD_HRS_BUFFER_PARAM_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_0(a) cavm_fdeqx_jd_hrs_buffer_param_0_t
#define bustype_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_0(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_0(a) "FDEQX_JD_HRS_BUFFER_PARAM_0"
#define busnum_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_0(a) (a)
#define arguments_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_0(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_jd_hrs_buffer_param_1
 *
 * Register
 */
union cavm_fdeqx_jd_hrs_buffer_param_1
{
    uint64_t u;
    struct cavm_fdeqx_jd_hrs_buffer_param_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t hrs_buf_sidx_rs_1_3_layer_7_3 : 7;/**< [ 55: 49](R/W) Refer to [HRS_BUF_SIDX_RS_1_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs_1_3_layer_6_2 : 7;/**< [ 48: 42](R/W) Refer to [HRS_BUF_SIDX_RS_1_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs_1_3_layer_5_1 : 7;/**< [ 41: 35](R/W) Refer to [HRS_BUF_SIDX_RS_1_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs_1_3_layer_4_0 : 7;/**< [ 34: 28](R/W) In name field HRS_BUF_SIDX_RSr_s_LAYER_l_m, the tuple (r,l) and (s,m) corresponds
                                                                 to a RS index and layer index pair. The parameter indicates which internal hrs buffer the hrs
                                                                 corresponding to the active RS and layer tuple is placed. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l)
                                                                 is the active tuple otherwise (s,m) is the active tuple.
                                                                 Valid range is [47,0]. */
        uint64_t hrs_buf_sidx_rs_1_layer_3 : 7;/**< [ 27: 21](R/W) Refer to [HRS_BUF_SIDX_RS_1_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs_1_layer_2 : 7;/**< [ 20: 14](R/W) Refer to [HRS_BUF_SIDX_RS_1_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs_1_layer_1 : 7;/**< [ 13:  7](R/W) Refer to [HRS_BUF_SIDX_RS_1_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs_1_layer_0 : 7;/**< [  6:  0](R/W) In name field HRS_BUF_SIDX_RSr_LAYER_l, the tuple (r,l) corresponds to a RS index and
                                                                 layer index pair. The parameter indicates which internal hrs buffer the hrs corresponding to the
                                                                 RS and layer tuple is placed.
                                                                 Valid range is [47,0]. */
#else /* Word 0 - Little Endian */
        uint64_t hrs_buf_sidx_rs_1_layer_0 : 7;/**< [  6:  0](R/W) In name field HRS_BUF_SIDX_RSr_LAYER_l, the tuple (r,l) corresponds to a RS index and
                                                                 layer index pair. The parameter indicates which internal hrs buffer the hrs corresponding to the
                                                                 RS and layer tuple is placed.
                                                                 Valid range is [47,0]. */
        uint64_t hrs_buf_sidx_rs_1_layer_1 : 7;/**< [ 13:  7](R/W) Refer to [HRS_BUF_SIDX_RS_1_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs_1_layer_2 : 7;/**< [ 20: 14](R/W) Refer to [HRS_BUF_SIDX_RS_1_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs_1_layer_3 : 7;/**< [ 27: 21](R/W) Refer to [HRS_BUF_SIDX_RS_1_LAYER_0]. */
        uint64_t hrs_buf_sidx_rs_1_3_layer_4_0 : 7;/**< [ 34: 28](R/W) In name field HRS_BUF_SIDX_RSr_s_LAYER_l_m, the tuple (r,l) and (s,m) corresponds
                                                                 to a RS index and layer index pair. The parameter indicates which internal hrs buffer the hrs
                                                                 corresponding to the active RS and layer tuple is placed. When
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_SYMBOL_NUMBER] \<= 2, (r,l)
                                                                 is the active tuple otherwise (s,m) is the active tuple.
                                                                 Valid range is [47,0]. */
        uint64_t hrs_buf_sidx_rs_1_3_layer_5_1 : 7;/**< [ 41: 35](R/W) Refer to [HRS_BUF_SIDX_RS_1_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs_1_3_layer_6_2 : 7;/**< [ 48: 42](R/W) Refer to [HRS_BUF_SIDX_RS_1_3_LAYER_4_0]. */
        uint64_t hrs_buf_sidx_rs_1_3_layer_7_3 : 7;/**< [ 55: 49](R/W) Refer to [HRS_BUF_SIDX_RS_1_3_LAYER_4_0]. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_jd_hrs_buffer_param_1_s cn; */
};
typedef union cavm_fdeqx_jd_hrs_buffer_param_1 cavm_fdeqx_jd_hrs_buffer_param_1_t;

static inline uint64_t CAVM_FDEQX_JD_HRS_BUFFER_PARAM_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JD_HRS_BUFFER_PARAM_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202018ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JD_HRS_BUFFER_PARAM_1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_1(a) cavm_fdeqx_jd_hrs_buffer_param_1_t
#define bustype_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_1(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_1(a) "FDEQX_JD_HRS_BUFFER_PARAM_1"
#define busnum_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_1(a) (a)
#define arguments_CAVM_FDEQX_JD_HRS_BUFFER_PARAM_1(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_jd_hrs_offset_per_ant
 *
 * Register
 */
union cavm_fdeqx_jd_hrs_offset_per_ant
{
    uint64_t u;
    struct cavm_fdeqx_jd_hrs_offset_per_ant_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_35_63        : 29;
        uint64_t gap_reduc_with_lim_rd_bw : 1;/**< [ 34: 34](R/W) Must be set to 1. If FDEQ()_JD_JOB_TYPE_RS_PARAM[DATA_ONLY_JOB_MODE_ENABLE]
                                                                 = 1, this parameters toggles between succesive jobs.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t rb_param_buff_page    : 1;  /**< [ 33: 33](R/W) If FDEQ()_JD_JOB_TYPE_RS_PARAM[DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t subprb_job_enable     : 1;  /**< [ 32: 32](R/W) If set to 1, this is a SUBPRB job. Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t gap_between_jobs      : 16; /**< [ 31: 16](R/W) Indicates the gap between the end of the current
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1 to the next
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1 at RD DMA interface in the
                                                                 resolution of 20 cycles (i.e. 10 means 200 cycles). 0= @(\<20 cycle),1=@+20
                                                                 cycle. MAX value is 11.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_9_15         : 7;
        uint64_t hrs_addr_offs_per_ant : 9;  /**< [  8:  0](R/W) Address offset between subsequent antennas within internal Hrs_buffer of cell-
                                                                 rs-layer.Must be \>= ceiling(NRB*(Nhtone_per_RB)/4,1).
                                                                 Valid range is [420,0].
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
#else /* Word 0 - Little Endian */
        uint64_t hrs_addr_offs_per_ant : 9;  /**< [  8:  0](R/W) Address offset between subsequent antennas within internal Hrs_buffer of cell-
                                                                 rs-layer.Must be \>= ceiling(NRB*(Nhtone_per_RB)/4,1).
                                                                 Valid range is [420,0].
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_9_15         : 7;
        uint64_t gap_between_jobs      : 16; /**< [ 31: 16](R/W) Indicates the gap between the end of the current
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1 to the next
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1 at RD DMA interface in the
                                                                 resolution of 20 cycles (i.e. 10 means 200 cycles). 0= @(\<20 cycle),1=@+20
                                                                 cycle. MAX value is 11.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t subprb_job_enable     : 1;  /**< [ 32: 32](R/W) If set to 1, this is a SUBPRB job. Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t rb_param_buff_page    : 1;  /**< [ 33: 33](R/W) If FDEQ()_JD_JOB_TYPE_RS_PARAM[DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t gap_reduc_with_lim_rd_bw : 1;/**< [ 34: 34](R/W) Must be set to 1. If FDEQ()_JD_JOB_TYPE_RS_PARAM[DATA_ONLY_JOB_MODE_ENABLE]
                                                                 = 1, this parameters toggles between succesive jobs.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_35_63        : 29;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_jd_hrs_offset_per_ant_s cn; */
};
typedef union cavm_fdeqx_jd_hrs_offset_per_ant cavm_fdeqx_jd_hrs_offset_per_ant_t;

static inline uint64_t CAVM_FDEQX_JD_HRS_OFFSET_PER_ANT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JD_HRS_OFFSET_PER_ANT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202008ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JD_HRS_OFFSET_PER_ANT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JD_HRS_OFFSET_PER_ANT(a) cavm_fdeqx_jd_hrs_offset_per_ant_t
#define bustype_CAVM_FDEQX_JD_HRS_OFFSET_PER_ANT(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JD_HRS_OFFSET_PER_ANT(a) "FDEQX_JD_HRS_OFFSET_PER_ANT"
#define busnum_CAVM_FDEQX_JD_HRS_OFFSET_PER_ANT(a) (a)
#define arguments_CAVM_FDEQX_JD_HRS_OFFSET_PER_ANT(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_jd_hrs_sym_idx_for_tdce
 *
 * Register
 */
union cavm_fdeqx_jd_hrs_sym_idx_for_tdce
{
    uint64_t u;
    struct cavm_fdeqx_jd_hrs_sym_idx_for_tdce_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t rs1_symbol_13         : 2;  /**< [ 55: 54](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_12         : 2;  /**< [ 53: 52](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_11         : 2;  /**< [ 51: 50](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_10         : 2;  /**< [ 49: 48](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_9          : 2;  /**< [ 47: 46](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_8          : 2;  /**< [ 45: 44](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_7          : 2;  /**< [ 43: 42](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_6          : 2;  /**< [ 41: 40](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_5          : 2;  /**< [ 39: 38](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_4          : 2;  /**< [ 37: 36](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_3          : 2;  /**< [ 35: 34](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_2          : 2;  /**< [ 33: 32](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_1          : 2;  /**< [ 31: 30](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_0          : 2;  /**< [ 29: 28](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_13         : 2;  /**< [ 27: 26](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_12         : 2;  /**< [ 25: 24](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_11         : 2;  /**< [ 23: 22](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_10         : 2;  /**< [ 21: 20](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_9          : 2;  /**< [ 19: 18](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_8          : 2;  /**< [ 17: 16](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_7          : 2;  /**< [ 15: 14](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_6          : 2;  /**< [ 13: 12](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_5          : 2;  /**< [ 11: 10](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_4          : 2;  /**< [  9:  8](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_3          : 2;  /**< [  7:  6](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_2          : 2;  /**< [  5:  4](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_1          : 2;  /**< [  3:  2](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_0          : 2;  /**< [  1:  0](R/W) In the name RSr_SYMBOL_s, the tuple (r,s) refers to RS index and symbol index.
                                                                 This  which RS symbol is used as the  second of two channel estimate for  time
                                                                 domain interpolation for this symbol.
                                                                 0x0 = RS0.
                                                                 0x1 = RS1.
                                                                 0x2 = RS2.
                                                                 0x3 = RS3.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
#else /* Word 0 - Little Endian */
        uint64_t rs0_symbol_0          : 2;  /**< [  1:  0](R/W) In the name RSr_SYMBOL_s, the tuple (r,s) refers to RS index and symbol index.
                                                                 This  which RS symbol is used as the  second of two channel estimate for  time
                                                                 domain interpolation for this symbol.
                                                                 0x0 = RS0.
                                                                 0x1 = RS1.
                                                                 0x2 = RS2.
                                                                 0x3 = RS3.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t rs0_symbol_1          : 2;  /**< [  3:  2](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_2          : 2;  /**< [  5:  4](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_3          : 2;  /**< [  7:  6](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_4          : 2;  /**< [  9:  8](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_5          : 2;  /**< [ 11: 10](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_6          : 2;  /**< [ 13: 12](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_7          : 2;  /**< [ 15: 14](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_8          : 2;  /**< [ 17: 16](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_9          : 2;  /**< [ 19: 18](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_10         : 2;  /**< [ 21: 20](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_11         : 2;  /**< [ 23: 22](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_12         : 2;  /**< [ 25: 24](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs0_symbol_13         : 2;  /**< [ 27: 26](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_0          : 2;  /**< [ 29: 28](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_1          : 2;  /**< [ 31: 30](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_2          : 2;  /**< [ 33: 32](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_3          : 2;  /**< [ 35: 34](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_4          : 2;  /**< [ 37: 36](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_5          : 2;  /**< [ 39: 38](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_6          : 2;  /**< [ 41: 40](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_7          : 2;  /**< [ 43: 42](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_8          : 2;  /**< [ 45: 44](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_9          : 2;  /**< [ 47: 46](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_10         : 2;  /**< [ 49: 48](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_11         : 2;  /**< [ 51: 50](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_12         : 2;  /**< [ 53: 52](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t rs1_symbol_13         : 2;  /**< [ 55: 54](R/W) Refer to [RS0_SYMBOL_0]. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_jd_hrs_sym_idx_for_tdce_s cn; */
};
typedef union cavm_fdeqx_jd_hrs_sym_idx_for_tdce cavm_fdeqx_jd_hrs_sym_idx_for_tdce_t;

static inline uint64_t CAVM_FDEQX_JD_HRS_SYM_IDX_FOR_TDCE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JD_HRS_SYM_IDX_FOR_TDCE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202028ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JD_HRS_SYM_IDX_FOR_TDCE", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JD_HRS_SYM_IDX_FOR_TDCE(a) cavm_fdeqx_jd_hrs_sym_idx_for_tdce_t
#define bustype_CAVM_FDEQX_JD_HRS_SYM_IDX_FOR_TDCE(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JD_HRS_SYM_IDX_FOR_TDCE(a) "FDEQX_JD_HRS_SYM_IDX_FOR_TDCE"
#define busnum_CAVM_FDEQX_JD_HRS_SYM_IDX_FOR_TDCE(a) (a)
#define arguments_CAVM_FDEQX_JD_HRS_SYM_IDX_FOR_TDCE(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_jd_job_type_rs_param
 *
 * Register
 */
union cavm_fdeqx_jd_job_type_rs_param
{
    uint64_t u;
    struct cavm_fdeqx_jd_job_type_rs_param_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data_only_job_mode_enable : 1;/**< [ 63: 63](R/W) if enabled this job processes only the data symbols. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] is 1.
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t data_symbol_start_offset : 4;/**< [ 62: 59](R/W) Indicates First symbol that carries PUSCH. Valid when
                                                                 [DATA_ONLY_JOB_MODE_ENABLE] is 1. If [DATA_ONLY_JOB_MODE_ENABLE] is 0, this is
                                                                 set to 0.
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t hrs_start_rb_offset   : 8;  /**< [ 58: 51](R/W) Index of the first RB that is allocated in the job.
                                                                 Valid range is [139,0].
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t rs3_rb_start_index    : 8;  /**< [ 50: 43](R/W) Start index of the RS 3. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1. Valid
                                                                 range is [139,0]. Used only for [JOB_TYPE] = 0x1. */
        uint64_t rs2_rb_start_index    : 8;  /**< [ 42: 35](R/W) Start index of the RS 2. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 Valid range is [139,0].
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t rs1_rb_start_index    : 8;  /**< [ 34: 27](R/W) Start index of the RS 1. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 Valid range is [139,0].
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t rs0_rb_start_index    : 8;  /**< [ 26: 19](R/W) Start index of the RS 0. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 Valid range is [139,0].
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t data_only_job_indicator : 1;/**< [ 18: 18](R/W) Indicates if the job processes symbols that carry both DMRS and PUSCH or PUSCH
                                                                 only. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 0x0 = RS+DS.
                                                                 0x1 = DS.
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t fdm_mode_enable       : 1;  /**< [ 17: 17](R/W) If set to 1, it generates FDE output for refrence and data tones on RS. Valid
                                                                 for CPOFDM UEs for which FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] =1.
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t rs_sequence_generation_enable : 1;/**< [ 16: 16](R/W) If set to 1, internal RS sequence generation is enabled (only for LTE). When
                                                                 disabled, RS sequence is read via port 1. Used only for [JOB_TYPE] = 0x1. */
        uint64_t antenna_mode          : 2;  /**< [ 15: 14](R/W) Number of receive antenna.
                                                                 0x0 = 2R.
                                                                 0x1 = 4R.
                                                                 0x2 = 8R.
                                                                 0x3 = 16R. */
        uint64_t layer_mode            : 2;  /**< [ 13: 12](R/W) Number of layers.
                                                                 0x0 = 1 layer.
                                                                 0x1 = 2 layers.
                                                                 0x2 = 4 layers.
                                                                 0x3 = 8 layers. */
        uint64_t hrs_symbol_number     : 3;  /**< [ 11:  9](R/W) Number of RS.
                                                                 Valid range is [4,1]. */
        uint64_t hrs_rb_number         : 8;  /**< [  8:  1](R/W) Number of RBs.
                                                                 Valid range is [140,1]. */
        uint64_t job_type              : 1;  /**< [  0:  0](R/W) Specifies job type.
                                                                 0x0 = job type-0 (Hrs loading job).
                                                                 0x1 = job type-1 (Equalization job). */
#else /* Word 0 - Little Endian */
        uint64_t job_type              : 1;  /**< [  0:  0](R/W) Specifies job type.
                                                                 0x0 = job type-0 (Hrs loading job).
                                                                 0x1 = job type-1 (Equalization job). */
        uint64_t hrs_rb_number         : 8;  /**< [  8:  1](R/W) Number of RBs.
                                                                 Valid range is [140,1]. */
        uint64_t hrs_symbol_number     : 3;  /**< [ 11:  9](R/W) Number of RS.
                                                                 Valid range is [4,1]. */
        uint64_t layer_mode            : 2;  /**< [ 13: 12](R/W) Number of layers.
                                                                 0x0 = 1 layer.
                                                                 0x1 = 2 layers.
                                                                 0x2 = 4 layers.
                                                                 0x3 = 8 layers. */
        uint64_t antenna_mode          : 2;  /**< [ 15: 14](R/W) Number of receive antenna.
                                                                 0x0 = 2R.
                                                                 0x1 = 4R.
                                                                 0x2 = 8R.
                                                                 0x3 = 16R. */
        uint64_t rs_sequence_generation_enable : 1;/**< [ 16: 16](R/W) If set to 1, internal RS sequence generation is enabled (only for LTE). When
                                                                 disabled, RS sequence is read via port 1. Used only for [JOB_TYPE] = 0x1. */
        uint64_t fdm_mode_enable       : 1;  /**< [ 17: 17](R/W) If set to 1, it generates FDE output for refrence and data tones on RS. Valid
                                                                 for CPOFDM UEs for which FDEQ_RDCFG_UE_PHYC_PARAMS_S[CP_OFDM_ON] =1.
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t data_only_job_indicator : 1;/**< [ 18: 18](R/W) Indicates if the job processes symbols that carry both DMRS and PUSCH or PUSCH
                                                                 only. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 0x0 = RS+DS.
                                                                 0x1 = DS.
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t rs0_rb_start_index    : 8;  /**< [ 26: 19](R/W) Start index of the RS 0. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 Valid range is [139,0].
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t rs1_rb_start_index    : 8;  /**< [ 34: 27](R/W) Start index of the RS 1. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 Valid range is [139,0].
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t rs2_rb_start_index    : 8;  /**< [ 42: 35](R/W) Start index of the RS 2. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1.
                                                                 Valid range is [139,0].
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t rs3_rb_start_index    : 8;  /**< [ 50: 43](R/W) Start index of the RS 3. Used only when [DATA_ONLY_JOB_MODE_ENABLE] = 1. Valid
                                                                 range is [139,0]. Used only for [JOB_TYPE] = 0x1. */
        uint64_t hrs_start_rb_offset   : 8;  /**< [ 58: 51](R/W) Index of the first RB that is allocated in the job.
                                                                 Valid range is [139,0].
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t data_symbol_start_offset : 4;/**< [ 62: 59](R/W) Indicates First symbol that carries PUSCH. Valid when
                                                                 [DATA_ONLY_JOB_MODE_ENABLE] is 1. If [DATA_ONLY_JOB_MODE_ENABLE] is 0, this is
                                                                 set to 0.
                                                                 Used only for [JOB_TYPE] = 0x1. */
        uint64_t data_only_job_mode_enable : 1;/**< [ 63: 63](R/W) if enabled this job processes only the data symbols. Valid when
                                                                 FDEQ()_JD_RS_GENERAL_PARAMETER[SIC_ON_OFF] is 1.
                                                                 Used only for [JOB_TYPE] = 0x1. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_jd_job_type_rs_param_s cn; */
};
typedef union cavm_fdeqx_jd_job_type_rs_param cavm_fdeqx_jd_job_type_rs_param_t;

static inline uint64_t CAVM_FDEQX_JD_JOB_TYPE_RS_PARAM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JD_JOB_TYPE_RS_PARAM(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202000ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JD_JOB_TYPE_RS_PARAM", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JD_JOB_TYPE_RS_PARAM(a) cavm_fdeqx_jd_job_type_rs_param_t
#define bustype_CAVM_FDEQX_JD_JOB_TYPE_RS_PARAM(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JD_JOB_TYPE_RS_PARAM(a) "FDEQX_JD_JOB_TYPE_RS_PARAM"
#define busnum_CAVM_FDEQX_JD_JOB_TYPE_RS_PARAM(a) (a)
#define arguments_CAVM_FDEQX_JD_JOB_TYPE_RS_PARAM(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_jd_rs_general_parameter
 *
 * Register
 */
union cavm_fdeqx_jd_rs_general_parameter
{
    uint64_t u;
    struct cavm_fdeqx_jd_rs_general_parameter_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t if_frequency_sparse   : 1;  /**< [ 63: 63](R/W) If  set to one, hrs for only the odd numbered subcarrier (assuming tones are
                                                                 indexed begining with 0).
                                                                 are provided in job type 0. i.e. number of hrs per RB is 6. S */
        uint64_t rb_number_include_subprb : 8;/**< [ 62: 55](R/W) If FDEQ()_JD_HRS_OFFSET_PER_ANT[SUBPRB_JOB_ENABLE] is 1, number of non-
                                                                 subprb UEs + 4* number of subprb UEs otherwise, this is
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_RB_NUMBER]. */
        uint64_t h_dmrs_input_bitshift : 3;  /**< [ 54: 52](R/W) Number of bits of right shift applied to channel estimates inputs of job type 0 such that hrs is
                                                                 stored internally as  11 bits. */
        uint64_t x_dmrs_input_bitshift : 3;  /**< [ 51: 49](R/W) Number of bits of right shift applied to X_DMRS so that X_DMRS is used as 11 bit
                                                                 integer internally.
                                                                 If X_DMRS input in job 1 (FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1) is in
                                                                 Q(k+10) format, this values must be set to k. */
        uint64_t soft_sic_on           : 1;  /**< [ 48: 48](R/W) For test only, must be set to 0
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t rs_frequency_sparse   : 1;  /**< [ 47: 47](R/W) Define how often R is calculated on each RS for PSINR.
                                                                 0x0 = every tone.
                                                                 0x1 = every other tone.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t data_frequency_sparse : 2;  /**< [ 46: 45](R/W) Defines how often equalizer filter weights are calculated for each DS.
                                                                 0x0 = every tone.
                                                                 0x1 = every other tone.
                                                                 0x2 = every fourth tone.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_32_44        : 13;
        uint64_t sic_with_crc_map      : 1;  /**< [ 31: 31](R/W) If set to 1, SIC utilizes  the CRC information during SIC operation
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t rs3_symbol_index      : 4;  /**< [ 30: 27](R/W) Index of RS3 within subframe. */
        uint64_t rs2_symbol_index      : 4;  /**< [ 26: 23](R/W) Index of RS2 within subframe. */
        uint64_t rs1_symbol_index      : 4;  /**< [ 22: 19](R/W) Index of RS1 within subframe. */
        uint64_t rs0_symbol_index      : 4;  /**< [ 18: 15](R/W) Index of RS0 within subframe. */
        uint64_t sic_on_off            : 1;  /**< [ 14: 14](R/W) If set to 1, SIC mode is enabled. */
        uint64_t timewf_set_number     : 4;  /**< [ 13: 10](R/W) Number of Time doma in interpolation to choose from.
                                                                 Valid range is  [11,1] */
        uint64_t data_symbol_number    : 4;  /**< [  9:  6](R/W) Number of Data symbols in subframe. */
        uint64_t ue_number             : 6;  /**< [  5:  0](R/W) Number of UE in the job. */
#else /* Word 0 - Little Endian */
        uint64_t ue_number             : 6;  /**< [  5:  0](R/W) Number of UE in the job. */
        uint64_t data_symbol_number    : 4;  /**< [  9:  6](R/W) Number of Data symbols in subframe. */
        uint64_t timewf_set_number     : 4;  /**< [ 13: 10](R/W) Number of Time doma in interpolation to choose from.
                                                                 Valid range is  [11,1] */
        uint64_t sic_on_off            : 1;  /**< [ 14: 14](R/W) If set to 1, SIC mode is enabled. */
        uint64_t rs0_symbol_index      : 4;  /**< [ 18: 15](R/W) Index of RS0 within subframe. */
        uint64_t rs1_symbol_index      : 4;  /**< [ 22: 19](R/W) Index of RS1 within subframe. */
        uint64_t rs2_symbol_index      : 4;  /**< [ 26: 23](R/W) Index of RS2 within subframe. */
        uint64_t rs3_symbol_index      : 4;  /**< [ 30: 27](R/W) Index of RS3 within subframe. */
        uint64_t sic_with_crc_map      : 1;  /**< [ 31: 31](R/W) If set to 1, SIC utilizes  the CRC information during SIC operation
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_32_44        : 13;
        uint64_t data_frequency_sparse : 2;  /**< [ 46: 45](R/W) Defines how often equalizer filter weights are calculated for each DS.
                                                                 0x0 = every tone.
                                                                 0x1 = every other tone.
                                                                 0x2 = every fourth tone.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t rs_frequency_sparse   : 1;  /**< [ 47: 47](R/W) Define how often R is calculated on each RS for PSINR.
                                                                 0x0 = every tone.
                                                                 0x1 = every other tone.
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t soft_sic_on           : 1;  /**< [ 48: 48](R/W) For test only, must be set to 0
                                                                 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t x_dmrs_input_bitshift : 3;  /**< [ 51: 49](R/W) Number of bits of right shift applied to X_DMRS so that X_DMRS is used as 11 bit
                                                                 integer internally.
                                                                 If X_DMRS input in job 1 (FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1) is in
                                                                 Q(k+10) format, this values must be set to k. */
        uint64_t h_dmrs_input_bitshift : 3;  /**< [ 54: 52](R/W) Number of bits of right shift applied to channel estimates inputs of job type 0 such that hrs is
                                                                 stored internally as  11 bits. */
        uint64_t rb_number_include_subprb : 8;/**< [ 62: 55](R/W) If FDEQ()_JD_HRS_OFFSET_PER_ANT[SUBPRB_JOB_ENABLE] is 1, number of non-
                                                                 subprb UEs + 4* number of subprb UEs otherwise, this is
                                                                 FDEQ()_JD_JOB_TYPE_RS_PARAM[HRS_RB_NUMBER]. */
        uint64_t if_frequency_sparse   : 1;  /**< [ 63: 63](R/W) If  set to one, hrs for only the odd numbered subcarrier (assuming tones are
                                                                 indexed begining with 0).
                                                                 are provided in job type 0. i.e. number of hrs per RB is 6. S */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_jd_rs_general_parameter_s cn; */
};
typedef union cavm_fdeqx_jd_rs_general_parameter cavm_fdeqx_jd_rs_general_parameter_t;

static inline uint64_t CAVM_FDEQX_JD_RS_GENERAL_PARAMETER(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JD_RS_GENERAL_PARAMETER(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202020ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JD_RS_GENERAL_PARAMETER", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JD_RS_GENERAL_PARAMETER(a) cavm_fdeqx_jd_rs_general_parameter_t
#define bustype_CAVM_FDEQX_JD_RS_GENERAL_PARAMETER(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JD_RS_GENERAL_PARAMETER(a) "FDEQX_JD_RS_GENERAL_PARAMETER"
#define busnum_CAVM_FDEQX_JD_RS_GENERAL_PARAMETER(a) (a)
#define arguments_CAVM_FDEQX_JD_RS_GENERAL_PARAMETER(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_jd_rs_sxbc_map_0
 *
 * Register
 */
union cavm_fdeqx_jd_rs_sxbc_map_0
{
    uint64_t u;
    struct cavm_fdeqx_jd_rs_sxbc_map_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t test_mode             : 2;  /**< [ 53: 52](R/W) Must be 0 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_0_51         : 52;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_51         : 52;
        uint64_t test_mode             : 2;  /**< [ 53: 52](R/W) Must be 0 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_jd_rs_sxbc_map_0_s cn; */
};
typedef union cavm_fdeqx_jd_rs_sxbc_map_0 cavm_fdeqx_jd_rs_sxbc_map_0_t;

static inline uint64_t CAVM_FDEQX_JD_RS_SXBC_MAP_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JD_RS_SXBC_MAP_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202030ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JD_RS_SXBC_MAP_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JD_RS_SXBC_MAP_0(a) cavm_fdeqx_jd_rs_sxbc_map_0_t
#define bustype_CAVM_FDEQX_JD_RS_SXBC_MAP_0(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JD_RS_SXBC_MAP_0(a) "FDEQX_JD_RS_SXBC_MAP_0"
#define busnum_CAVM_FDEQX_JD_RS_SXBC_MAP_0(a) (a)
#define arguments_CAVM_FDEQX_JD_RS_SXBC_MAP_0(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_jd_rs_sxbc_map_1
 *
 * Register
 */
union cavm_fdeqx_jd_rs_sxbc_map_1
{
    uint64_t u;
    struct cavm_fdeqx_jd_rs_sxbc_map_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t test_mode             : 4;  /**< [ 51: 48](R/W) Must be 0 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_0_47         : 48;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_47         : 48;
        uint64_t test_mode             : 4;  /**< [ 51: 48](R/W) Must be 0 Used only for FDEQ()_JD_JOB_TYPE_RS_PARAM[JOB_TYPE] = 0x1. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_jd_rs_sxbc_map_1_s cn; */
};
typedef union cavm_fdeqx_jd_rs_sxbc_map_1 cavm_fdeqx_jd_rs_sxbc_map_1_t;

static inline uint64_t CAVM_FDEQX_JD_RS_SXBC_MAP_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JD_RS_SXBC_MAP_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202038ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JD_RS_SXBC_MAP_1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JD_RS_SXBC_MAP_1(a) cavm_fdeqx_jd_rs_sxbc_map_1_t
#define bustype_CAVM_FDEQX_JD_RS_SXBC_MAP_1(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JD_RS_SXBC_MAP_1(a) "FDEQX_JD_RS_SXBC_MAP_1"
#define busnum_CAVM_FDEQX_JD_RS_SXBC_MAP_1(a) (a)
#define arguments_CAVM_FDEQX_JD_RS_SXBC_MAP_1(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_FDEQ_H__ */
