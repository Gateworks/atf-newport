#ifndef __CAVM_CSRS_PRACH_H__
#define __CAVM_CSRS_PRACH_H__
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
 * OcteonTX PRACH.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure prach_jd_cal_parm_s
 *
 * PRACH Calibration Structure
 */
union cavm_prach_jd_cal_parm_s
{
    uint64_t u;
    struct cavm_prach_jd_cal_parm_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27] Represents the power to which the input signal must be scaled to.
                                                                 Default : 0xC */
        uint64_t reserved_16_26        : 11;
        uint64_t m_rs                  : 4;  /**< [ 15: 12] Used only when PRACH_JD_SYS_CFG_S[MRC_MODE]=1.
                                                                 Adjusts MRC right shift after antenna correlation power sample is scaled by
                                                                 noise power value, to adjust the accuracy of MRC combiner. */
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11] Used only when PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET]\>0x0
                                                                 Default: 0x0 */
        uint64_t rtl_debug2            : 1;  /**< [ 10: 10] rtl debug */
        uint64_t min_noise             : 10; /**< [  9:  0] The minimum value at which the estimated noise value capped
                                                                 Default : 0x1 */
#else /* Word 0 - Little Endian */
        uint64_t min_noise             : 10; /**< [  9:  0] The minimum value at which the estimated noise value capped
                                                                 Default : 0x1 */
        uint64_t rtl_debug2            : 1;  /**< [ 10: 10] rtl debug */
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11] Used only when PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET]\>0x0
                                                                 Default: 0x0 */
        uint64_t m_rs                  : 4;  /**< [ 15: 12] Used only when PRACH_JD_SYS_CFG_S[MRC_MODE]=1.
                                                                 Adjusts MRC right shift after antenna correlation power sample is scaled by
                                                                 noise power value, to adjust the accuracy of MRC combiner. */
        uint64_t reserved_16_26        : 11;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27] Represents the power to which the input signal must be scaled to.
                                                                 Default : 0xC */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_prach_jd_cal_parm_s_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t reserved_32_47        : 16;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27] Represents the power to which the input signal must be scaled to.
                                                                 Default : 0xC */
        uint64_t reserved_16_26        : 11;
        uint64_t m_rs                  : 4;  /**< [ 15: 12] Used only when PRACH_JD_SYS_CFG_S[MRC_MODE]=1.
                                                                 Adjusts MRC right shift after antenna correlation power sample is scaled by
                                                                 noise power value, to adjust the accuracy of MRC combiner. */
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11] Used only when PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET]\>0x0
                                                                 Default: 0x0 */
        uint64_t rtl_debug2            : 1;  /**< [ 10: 10] rtl debug */
        uint64_t min_noise             : 10; /**< [  9:  0] The minimum value at which the estimated noise value capped
                                                                 Default : 0x1 */
#else /* Word 0 - Little Endian */
        uint64_t min_noise             : 10; /**< [  9:  0] The minimum value at which the estimated noise value capped
                                                                 Default : 0x1 */
        uint64_t rtl_debug2            : 1;  /**< [ 10: 10] rtl debug */
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11] Used only when PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET]\>0x0
                                                                 Default: 0x0 */
        uint64_t m_rs                  : 4;  /**< [ 15: 12] Used only when PRACH_JD_SYS_CFG_S[MRC_MODE]=1.
                                                                 Adjusts MRC right shift after antenna correlation power sample is scaled by
                                                                 noise power value, to adjust the accuracy of MRC combiner. */
        uint64_t reserved_16_26        : 11;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27] Represents the power to which the input signal must be scaled to.
                                                                 Default : 0xC */
        uint64_t reserved_32_47        : 16;
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_prach_jd_cal_parm_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t reserved_32_47        : 16;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27] Represents the power to which the input signal must be scaled to. Default = 0xC. */
        uint64_t reserved_16_26        : 11;
        uint64_t m_rs                  : 4;  /**< [ 15: 12] Used only when PRACH_JD_SYS_CFG_S[MRC_MODE] = 1.
                                                                 Adjusts MRC right-shift after antenna correlation power sample is scaled by
                                                                 the noise power value, to adjust the accuracy of MRC combiner. */
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11] Used only when PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET] \> 0x0. Default = 0x0. */
        uint64_t rtl_debug2            : 1;  /**< [ 10: 10] rtl debug */
        uint64_t min_noise             : 10; /**< [  9:  0] The minimum value at which the estimated noise value is capped. Default = 0x1. */
#else /* Word 0 - Little Endian */
        uint64_t min_noise             : 10; /**< [  9:  0] The minimum value at which the estimated noise value is capped. Default = 0x1. */
        uint64_t rtl_debug2            : 1;  /**< [ 10: 10] rtl debug */
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11] Used only when PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET] \> 0x0. Default = 0x0. */
        uint64_t m_rs                  : 4;  /**< [ 15: 12] Used only when PRACH_JD_SYS_CFG_S[MRC_MODE] = 1.
                                                                 Adjusts MRC right-shift after antenna correlation power sample is scaled by
                                                                 the noise power value, to adjust the accuracy of MRC combiner. */
        uint64_t reserved_16_26        : 11;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27] Represents the power to which the input signal must be scaled to. Default = 0xC. */
        uint64_t reserved_32_47        : 16;
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } loki;
};

/**
 * Structure prach_jd_det_param_s
 *
 * PRACH Detection Structure
 */
union cavm_prach_jd_det_param_s
{
    uint64_t u;
    struct cavm_prach_jd_det_param_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t demap_offset          : 4;  /**< [ 19: 16] Number of samples of offset applied to the output of IFFT before demapping.
                                                                 Default : 0x0 */
        uint64_t freq_bypass           : 1;  /**< [ 15: 15] If this value is 0x1, FFT output is read from read DMA
                                                                 Default : 0x0 */
        uint64_t sncs_start            : 9;  /**< [ 14:  6] Start sample of Ncs in short seq.
                                                                 Default : 0x0 */
        uint64_t num_of_root_seq       : 6;  /**< [  5:  0] The number of root sequences to generate for detection. */
#else /* Word 0 - Little Endian */
        uint64_t num_of_root_seq       : 6;  /**< [  5:  0] The number of root sequences to generate for detection. */
        uint64_t sncs_start            : 9;  /**< [ 14:  6] Start sample of Ncs in short seq.
                                                                 Default : 0x0 */
        uint64_t freq_bypass           : 1;  /**< [ 15: 15] If this value is 0x1, FFT output is read from read DMA
                                                                 Default : 0x0 */
        uint64_t demap_offset          : 4;  /**< [ 19: 16] Number of samples of offset applied to the output of IFFT before demapping.
                                                                 Default : 0x0 */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_jd_det_param_s_s cnf95xx; */
    struct cavm_prach_jd_det_param_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t demap_offset          : 4;  /**< [ 19: 16] Number of samples of offset applied to the output of IFFT before demapping. Default = 0x0. */
        uint64_t freq_bypass           : 1;  /**< [ 15: 15] If this value is 0x1, FFT output is read from read DMA. Default = 0x0. */
        uint64_t sncs_start            : 9;  /**< [ 14:  6] Start sample of Ncs in short sequence. Default = 0x0. */
        uint64_t num_of_root_seq       : 6;  /**< [  5:  0] The number of root sequences to generate for detection. */
#else /* Word 0 - Little Endian */
        uint64_t num_of_root_seq       : 6;  /**< [  5:  0] The number of root sequences to generate for detection. */
        uint64_t sncs_start            : 9;  /**< [ 14:  6] Start sample of Ncs in short sequence. Default = 0x0. */
        uint64_t freq_bypass           : 1;  /**< [ 15: 15] If this value is 0x1, FFT output is read from read DMA. Default = 0x0. */
        uint64_t demap_offset          : 4;  /**< [ 19: 16] Number of samples of offset applied to the output of IFFT before demapping. Default = 0x0. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } loki;
};

/**
 * Structure prach_jd_dstart2_s
 *
 * PRACH Dstart2 Structure
 */
union cavm_prach_jd_dstart2_s
{
    uint64_t u[16];
    struct cavm_prach_jd_dstart2_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_3             : 16; /**< [ 63: 48] Available Dstart2 Of 4th Dstart2 */
        uint64_t dstart2_2             : 16; /**< [ 47: 32] Available Dstart2 Of 3rd Dstart2 */
        uint64_t dstart2_1             : 16; /**< [ 31: 16] Available Dstart2 Of 2nd Dstart2 */
        uint64_t dstart2_0             : 16; /**< [ 15:  0] Available Dstart2 Of start Dstart2 */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_0             : 16; /**< [ 15:  0] Available Dstart2 Of start Dstart2 */
        uint64_t dstart2_1             : 16; /**< [ 31: 16] Available Dstart2 Of 2nd Dstart2 */
        uint64_t dstart2_2             : 16; /**< [ 47: 32] Available Dstart2 Of 3rd Dstart2 */
        uint64_t dstart2_3             : 16; /**< [ 63: 48] Available Dstart2 Of 4th Dstart2 */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t dstart2_7             : 16; /**< [127:112] Available Dstart2 Of 8th Dstart2 */
        uint64_t dstart2_6             : 16; /**< [111: 96] Available Dstart2 Of 7th Dstart2 */
        uint64_t dstart2_5             : 16; /**< [ 95: 80] Available Dstart2 Of 6th Dstart2 */
        uint64_t dstart2_4             : 16; /**< [ 79: 64] Available Dstart2 Of 5th Dstart2 */
#else /* Word 1 - Little Endian */
        uint64_t dstart2_4             : 16; /**< [ 79: 64] Available Dstart2 Of 5th Dstart2 */
        uint64_t dstart2_5             : 16; /**< [ 95: 80] Available Dstart2 Of 6th Dstart2 */
        uint64_t dstart2_6             : 16; /**< [111: 96] Available Dstart2 Of 7th Dstart2 */
        uint64_t dstart2_7             : 16; /**< [127:112] Available Dstart2 Of 8th Dstart2 */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t dstart2_11            : 16; /**< [191:176] Available Dstart2 Of 12nd Dstart2 */
        uint64_t dstart2_10            : 16; /**< [175:160] Available Dstart2 Of 11st Dstart2 */
        uint64_t dstart2_9             : 16; /**< [159:144] Available Dstart2 Of 10th Dstart2 */
        uint64_t dstart2_8             : 16; /**< [143:128] Available Dstart2 Of 9th Dstart2 */
#else /* Word 2 - Little Endian */
        uint64_t dstart2_8             : 16; /**< [143:128] Available Dstart2 Of 9th Dstart2 */
        uint64_t dstart2_9             : 16; /**< [159:144] Available Dstart2 Of 10th Dstart2 */
        uint64_t dstart2_10            : 16; /**< [175:160] Available Dstart2 Of 11st Dstart2 */
        uint64_t dstart2_11            : 16; /**< [191:176] Available Dstart2 Of 12nd Dstart2 */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t dstart2_15            : 16; /**< [255:240] Available Dstart2 Of 16th Dstart2 */
        uint64_t dstart2_14            : 16; /**< [239:224] Available Dstart2 Of 15th Dstart2 */
        uint64_t dstart2_13            : 16; /**< [223:208] Available Dstart2 Of 14th Dstart2 */
        uint64_t dstart2_12            : 16; /**< [207:192] Available Dstart2 Of 13rd Dstart2 */
#else /* Word 3 - Little Endian */
        uint64_t dstart2_12            : 16; /**< [207:192] Available Dstart2 Of 13rd Dstart2 */
        uint64_t dstart2_13            : 16; /**< [223:208] Available Dstart2 Of 14th Dstart2 */
        uint64_t dstart2_14            : 16; /**< [239:224] Available Dstart2 Of 15th Dstart2 */
        uint64_t dstart2_15            : 16; /**< [255:240] Available Dstart2 Of 16th Dstart2 */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t dstart2_19            : 16; /**< [319:304] Available Dstart2 Of 20th Dstart2 */
        uint64_t dstart2_18            : 16; /**< [303:288] Available Dstart2 Of 19th Dstart2 */
        uint64_t dstart2_17            : 16; /**< [287:272] Available Dstart2 Of 18th Dstart2 */
        uint64_t dstart2_16            : 16; /**< [271:256] Available Dstart2 Of 17th Dstart2 */
#else /* Word 4 - Little Endian */
        uint64_t dstart2_16            : 16; /**< [271:256] Available Dstart2 Of 17th Dstart2 */
        uint64_t dstart2_17            : 16; /**< [287:272] Available Dstart2 Of 18th Dstart2 */
        uint64_t dstart2_18            : 16; /**< [303:288] Available Dstart2 Of 19th Dstart2 */
        uint64_t dstart2_19            : 16; /**< [319:304] Available Dstart2 Of 20th Dstart2 */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t dstart2_23            : 16; /**< [383:368] Available Dstart2 Of 24th Dstart2 */
        uint64_t dstart2_22            : 16; /**< [367:352] Available Dstart2 Of 23rd Dstart2 */
        uint64_t dstart2_21            : 16; /**< [351:336] Available Dstart2 Of 22nd Dstart2 */
        uint64_t dstart2_20            : 16; /**< [335:320] Available Dstart2 Of 21st Dstart2 */
#else /* Word 5 - Little Endian */
        uint64_t dstart2_20            : 16; /**< [335:320] Available Dstart2 Of 21st Dstart2 */
        uint64_t dstart2_21            : 16; /**< [351:336] Available Dstart2 Of 22nd Dstart2 */
        uint64_t dstart2_22            : 16; /**< [367:352] Available Dstart2 Of 23rd Dstart2 */
        uint64_t dstart2_23            : 16; /**< [383:368] Available Dstart2 Of 24th Dstart2 */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t dstart2_27            : 16; /**< [447:432] Available Dstart2 Of 28th Dstart2 */
        uint64_t dstart2_26            : 16; /**< [431:416] Available Dstart2 Of 27th Dstart2 */
        uint64_t dstart2_25            : 16; /**< [415:400] Available Dstart2 Of 26th Dstart2 */
        uint64_t dstart2_24            : 16; /**< [399:384] Available Dstart2 Of 25th Dstart2 */
#else /* Word 6 - Little Endian */
        uint64_t dstart2_24            : 16; /**< [399:384] Available Dstart2 Of 25th Dstart2 */
        uint64_t dstart2_25            : 16; /**< [415:400] Available Dstart2 Of 26th Dstart2 */
        uint64_t dstart2_26            : 16; /**< [431:416] Available Dstart2 Of 27th Dstart2 */
        uint64_t dstart2_27            : 16; /**< [447:432] Available Dstart2 Of 28th Dstart2 */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t dstart2_31            : 16; /**< [511:496] Available Dstart2 Of 32nd Dstart2 */
        uint64_t dstart2_30            : 16; /**< [495:480] Available Dstart2 Of 31st Dstart2 */
        uint64_t dstart2_29            : 16; /**< [479:464] Available Dstart2 Of 30th Dstart2 */
        uint64_t dstart2_28            : 16; /**< [463:448] Available Dstart2 Of 29th Dstart2 */
#else /* Word 7 - Little Endian */
        uint64_t dstart2_28            : 16; /**< [463:448] Available Dstart2 Of 29th Dstart2 */
        uint64_t dstart2_29            : 16; /**< [479:464] Available Dstart2 Of 30th Dstart2 */
        uint64_t dstart2_30            : 16; /**< [495:480] Available Dstart2 Of 31st Dstart2 */
        uint64_t dstart2_31            : 16; /**< [511:496] Available Dstart2 Of 32nd Dstart2 */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t dstart2_35            : 16; /**< [575:560] Available Dstart2 Of 36th Dstart2 */
        uint64_t dstart2_34            : 16; /**< [559:544] Available Dstart2 Of 35th Dstart2 */
        uint64_t dstart2_33            : 16; /**< [543:528] Available Dstart2 Of 34th Dstart2 */
        uint64_t dstart2_32            : 16; /**< [527:512] Available Dstart2 Of 33rd Dstart2 */
#else /* Word 8 - Little Endian */
        uint64_t dstart2_32            : 16; /**< [527:512] Available Dstart2 Of 33rd Dstart2 */
        uint64_t dstart2_33            : 16; /**< [543:528] Available Dstart2 Of 34th Dstart2 */
        uint64_t dstart2_34            : 16; /**< [559:544] Available Dstart2 Of 35th Dstart2 */
        uint64_t dstart2_35            : 16; /**< [575:560] Available Dstart2 Of 36th Dstart2 */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t dstart2_39            : 16; /**< [639:624] Available Dstart2 Of 40th Dstart2 */
        uint64_t dstart2_38            : 16; /**< [623:608] Available Dstart2 Of 39th Dstart2 */
        uint64_t dstart2_37            : 16; /**< [607:592] Available Dstart2 Of 38th Dstart2 */
        uint64_t dstart2_36            : 16; /**< [591:576] Available Dstart2 Of 37th Dstart2 */
#else /* Word 9 - Little Endian */
        uint64_t dstart2_36            : 16; /**< [591:576] Available Dstart2 Of 37th Dstart2 */
        uint64_t dstart2_37            : 16; /**< [607:592] Available Dstart2 Of 38th Dstart2 */
        uint64_t dstart2_38            : 16; /**< [623:608] Available Dstart2 Of 39th Dstart2 */
        uint64_t dstart2_39            : 16; /**< [639:624] Available Dstart2 Of 40th Dstart2 */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t dstart2_43            : 16; /**< [703:688] Available Dstart2 Of 44th Dstart2 */
        uint64_t dstart2_42            : 16; /**< [687:672] Available Dstart2 Of 43rd Dstart2 */
        uint64_t dstart2_41            : 16; /**< [671:656] Available Dstart2 Of 42nd Dstart2 */
        uint64_t dstart2_40            : 16; /**< [655:640] Available Dstart2 Of 41st Dstart2 */
#else /* Word 10 - Little Endian */
        uint64_t dstart2_40            : 16; /**< [655:640] Available Dstart2 Of 41st Dstart2 */
        uint64_t dstart2_41            : 16; /**< [671:656] Available Dstart2 Of 42nd Dstart2 */
        uint64_t dstart2_42            : 16; /**< [687:672] Available Dstart2 Of 43rd Dstart2 */
        uint64_t dstart2_43            : 16; /**< [703:688] Available Dstart2 Of 44th Dstart2 */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t dstart2_47            : 16; /**< [767:752] Available Dstart2 Of 48th Dstart2 */
        uint64_t dstart2_46            : 16; /**< [751:736] Available Dstart2 Of 47th Dstart2 */
        uint64_t dstart2_45            : 16; /**< [735:720] Available Dstart2 Of 46th Dstart2 */
        uint64_t dstart2_44            : 16; /**< [719:704] Available Dstart2 Of 45th Dstart2 */
#else /* Word 11 - Little Endian */
        uint64_t dstart2_44            : 16; /**< [719:704] Available Dstart2 Of 45th Dstart2 */
        uint64_t dstart2_45            : 16; /**< [735:720] Available Dstart2 Of 46th Dstart2 */
        uint64_t dstart2_46            : 16; /**< [751:736] Available Dstart2 Of 47th Dstart2 */
        uint64_t dstart2_47            : 16; /**< [767:752] Available Dstart2 Of 48th Dstart2 */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t dstart2_51            : 16; /**< [831:816] Available Dstart2 Of 52nd Dstart2 */
        uint64_t dstart2_50            : 16; /**< [815:800] Available Dstart2 Of 51st Dstart2 */
        uint64_t dstart2_49            : 16; /**< [799:784] Available Dstart2 Of 50th Dstart2 */
        uint64_t dstart2_48            : 16; /**< [783:768] Available Dstart2 Of 49th Dstart2 */
#else /* Word 12 - Little Endian */
        uint64_t dstart2_48            : 16; /**< [783:768] Available Dstart2 Of 49th Dstart2 */
        uint64_t dstart2_49            : 16; /**< [799:784] Available Dstart2 Of 50th Dstart2 */
        uint64_t dstart2_50            : 16; /**< [815:800] Available Dstart2 Of 51st Dstart2 */
        uint64_t dstart2_51            : 16; /**< [831:816] Available Dstart2 Of 52nd Dstart2 */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t dstart2_55            : 16; /**< [895:880] Available Dstart2 Of 56th Dstart2 */
        uint64_t dstart2_54            : 16; /**< [879:864] Available Dstart2 Of 55th Dstart2 */
        uint64_t dstart2_53            : 16; /**< [863:848] Available Dstart2 Of 54th Dstart2 */
        uint64_t dstart2_52            : 16; /**< [847:832] Available Dstart2 Of 53rd Dstart2 */
#else /* Word 13 - Little Endian */
        uint64_t dstart2_52            : 16; /**< [847:832] Available Dstart2 Of 53rd Dstart2 */
        uint64_t dstart2_53            : 16; /**< [863:848] Available Dstart2 Of 54th Dstart2 */
        uint64_t dstart2_54            : 16; /**< [879:864] Available Dstart2 Of 55th Dstart2 */
        uint64_t dstart2_55            : 16; /**< [895:880] Available Dstart2 Of 56th Dstart2 */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t dstart2_59            : 16; /**< [959:944] Available Dstart2 Of 60th Dstart2 */
        uint64_t dstart2_58            : 16; /**< [943:928] Available Dstart2 Of 59th Dstart2 */
        uint64_t dstart2_57            : 16; /**< [927:912] Available Dstart2 Of 58th Dstart2 */
        uint64_t dstart2_56            : 16; /**< [911:896] Available Dstart2 Of 57th Dstart2 */
#else /* Word 14 - Little Endian */
        uint64_t dstart2_56            : 16; /**< [911:896] Available Dstart2 Of 57th Dstart2 */
        uint64_t dstart2_57            : 16; /**< [927:912] Available Dstart2 Of 58th Dstart2 */
        uint64_t dstart2_58            : 16; /**< [943:928] Available Dstart2 Of 59th Dstart2 */
        uint64_t dstart2_59            : 16; /**< [959:944] Available Dstart2 Of 60th Dstart2 */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t dstart2_63            : 16; /**< [1023:1008] Available Dstart2 Of 64th Dstart2 */
        uint64_t dstart2_62            : 16; /**< [1007:992] Available Dstart2 Of 63rd Dstart2 */
        uint64_t dstart2_61            : 16; /**< [991:976] Available Dstart2 Of 62nd Dstart2 */
        uint64_t dstart2_60            : 16; /**< [975:960] Available Dstart2 Of 61st Dstart2 */
#else /* Word 15 - Little Endian */
        uint64_t dstart2_60            : 16; /**< [975:960] Available Dstart2 Of 61st Dstart2 */
        uint64_t dstart2_61            : 16; /**< [991:976] Available Dstart2 Of 62nd Dstart2 */
        uint64_t dstart2_62            : 16; /**< [1007:992] Available Dstart2 Of 63rd Dstart2 */
        uint64_t dstart2_63            : 16; /**< [1023:1008] Available Dstart2 Of 64th Dstart2 */
#endif /* Word 15 - End */
    } s;
    /* struct cavm_prach_jd_dstart2_s_s cn; */
};

/**
 * Structure prach_jd_dstart3_s
 *
 * PRACH Dstart3 Structure
 */
union cavm_prach_jd_dstart3_s
{
    uint64_t u[16];
    struct cavm_prach_jd_dstart3_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_3             : 16; /**< [ 63: 48] Available Dstart3 Of 4th Dstart3 */
        uint64_t dstart3_2             : 16; /**< [ 47: 32] Available Dstart3 Of 3rd Dstart3 */
        uint64_t dstart3_1             : 16; /**< [ 31: 16] Available Dstart3 Of 2nd Dstart3 */
        uint64_t dstart3_0             : 16; /**< [ 15:  0] Available Dstart3 Of start Dstart3 */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_0             : 16; /**< [ 15:  0] Available Dstart3 Of start Dstart3 */
        uint64_t dstart3_1             : 16; /**< [ 31: 16] Available Dstart3 Of 2nd Dstart3 */
        uint64_t dstart3_2             : 16; /**< [ 47: 32] Available Dstart3 Of 3rd Dstart3 */
        uint64_t dstart3_3             : 16; /**< [ 63: 48] Available Dstart3 Of 4th Dstart3 */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t dstart3_7             : 16; /**< [127:112] Available Dstart3 Of 8th Dstart3 */
        uint64_t dstart3_6             : 16; /**< [111: 96] Available Dstart3 Of 7th Dstart3 */
        uint64_t dstart3_5             : 16; /**< [ 95: 80] Available Dstart3 Of 6th Dstart3 */
        uint64_t dstart3_4             : 16; /**< [ 79: 64] Available Dstart3 Of 5th Dstart3 */
#else /* Word 1 - Little Endian */
        uint64_t dstart3_4             : 16; /**< [ 79: 64] Available Dstart3 Of 5th Dstart3 */
        uint64_t dstart3_5             : 16; /**< [ 95: 80] Available Dstart3 Of 6th Dstart3 */
        uint64_t dstart3_6             : 16; /**< [111: 96] Available Dstart3 Of 7th Dstart3 */
        uint64_t dstart3_7             : 16; /**< [127:112] Available Dstart3 Of 8th Dstart3 */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t dstart3_11            : 16; /**< [191:176] Available Dstart3 Of 12nd Dstart3 */
        uint64_t dstart3_10            : 16; /**< [175:160] Available Dstart3 Of 11st Dstart3 */
        uint64_t dstart3_9             : 16; /**< [159:144] Available Dstart3 Of 10th Dstart3 */
        uint64_t dstart3_8             : 16; /**< [143:128] Available Dstart3 Of 9th Dstart3 */
#else /* Word 2 - Little Endian */
        uint64_t dstart3_8             : 16; /**< [143:128] Available Dstart3 Of 9th Dstart3 */
        uint64_t dstart3_9             : 16; /**< [159:144] Available Dstart3 Of 10th Dstart3 */
        uint64_t dstart3_10            : 16; /**< [175:160] Available Dstart3 Of 11st Dstart3 */
        uint64_t dstart3_11            : 16; /**< [191:176] Available Dstart3 Of 12nd Dstart3 */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t dstart3_15            : 16; /**< [255:240] Available Dstart3 Of 16th Dstart3 */
        uint64_t dstart3_14            : 16; /**< [239:224] Available Dstart3 Of 15th Dstart3 */
        uint64_t dstart3_13            : 16; /**< [223:208] Available Dstart3 Of 14th Dstart3 */
        uint64_t dstart3_12            : 16; /**< [207:192] Available Dstart3 Of 13rd Dstart3 */
#else /* Word 3 - Little Endian */
        uint64_t dstart3_12            : 16; /**< [207:192] Available Dstart3 Of 13rd Dstart3 */
        uint64_t dstart3_13            : 16; /**< [223:208] Available Dstart3 Of 14th Dstart3 */
        uint64_t dstart3_14            : 16; /**< [239:224] Available Dstart3 Of 15th Dstart3 */
        uint64_t dstart3_15            : 16; /**< [255:240] Available Dstart3 Of 16th Dstart3 */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t dstart3_19            : 16; /**< [319:304] Available Dstart3 Of 20th Dstart3 */
        uint64_t dstart3_18            : 16; /**< [303:288] Available Dstart3 Of 19th Dstart3 */
        uint64_t dstart3_17            : 16; /**< [287:272] Available Dstart3 Of 18th Dstart3 */
        uint64_t dstart3_16            : 16; /**< [271:256] Available Dstart3 Of 17th Dstart3 */
#else /* Word 4 - Little Endian */
        uint64_t dstart3_16            : 16; /**< [271:256] Available Dstart3 Of 17th Dstart3 */
        uint64_t dstart3_17            : 16; /**< [287:272] Available Dstart3 Of 18th Dstart3 */
        uint64_t dstart3_18            : 16; /**< [303:288] Available Dstart3 Of 19th Dstart3 */
        uint64_t dstart3_19            : 16; /**< [319:304] Available Dstart3 Of 20th Dstart3 */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t dstart3_23            : 16; /**< [383:368] Available Dstart3 Of 24th Dstart3 */
        uint64_t dstart3_22            : 16; /**< [367:352] Available Dstart3 Of 23rd Dstart3 */
        uint64_t dstart3_21            : 16; /**< [351:336] Available Dstart3 Of 22nd Dstart3 */
        uint64_t dstart3_20            : 16; /**< [335:320] Available Dstart3 Of 21st Dstart3 */
#else /* Word 5 - Little Endian */
        uint64_t dstart3_20            : 16; /**< [335:320] Available Dstart3 Of 21st Dstart3 */
        uint64_t dstart3_21            : 16; /**< [351:336] Available Dstart3 Of 22nd Dstart3 */
        uint64_t dstart3_22            : 16; /**< [367:352] Available Dstart3 Of 23rd Dstart3 */
        uint64_t dstart3_23            : 16; /**< [383:368] Available Dstart3 Of 24th Dstart3 */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t dstart3_27            : 16; /**< [447:432] Available Dstart3 Of 28th Dstart3 */
        uint64_t dstart3_26            : 16; /**< [431:416] Available Dstart3 Of 27th Dstart3 */
        uint64_t dstart3_25            : 16; /**< [415:400] Available Dstart3 Of 26th Dstart3 */
        uint64_t dstart3_24            : 16; /**< [399:384] Available Dstart3 Of 25th Dstart3 */
#else /* Word 6 - Little Endian */
        uint64_t dstart3_24            : 16; /**< [399:384] Available Dstart3 Of 25th Dstart3 */
        uint64_t dstart3_25            : 16; /**< [415:400] Available Dstart3 Of 26th Dstart3 */
        uint64_t dstart3_26            : 16; /**< [431:416] Available Dstart3 Of 27th Dstart3 */
        uint64_t dstart3_27            : 16; /**< [447:432] Available Dstart3 Of 28th Dstart3 */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t dstart3_31            : 16; /**< [511:496] Available Dstart3 Of 32nd Dstart3 */
        uint64_t dstart3_30            : 16; /**< [495:480] Available Dstart3 Of 31st Dstart3 */
        uint64_t dstart3_29            : 16; /**< [479:464] Available Dstart3 Of 30th Dstart3 */
        uint64_t dstart3_28            : 16; /**< [463:448] Available Dstart3 Of 29th Dstart3 */
#else /* Word 7 - Little Endian */
        uint64_t dstart3_28            : 16; /**< [463:448] Available Dstart3 Of 29th Dstart3 */
        uint64_t dstart3_29            : 16; /**< [479:464] Available Dstart3 Of 30th Dstart3 */
        uint64_t dstart3_30            : 16; /**< [495:480] Available Dstart3 Of 31st Dstart3 */
        uint64_t dstart3_31            : 16; /**< [511:496] Available Dstart3 Of 32nd Dstart3 */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t dstart3_35            : 16; /**< [575:560] Available Dstart3 Of 36th Dstart3 */
        uint64_t dstart3_34            : 16; /**< [559:544] Available Dstart3 Of 35th Dstart3 */
        uint64_t dstart3_33            : 16; /**< [543:528] Available Dstart3 Of 34th Dstart3 */
        uint64_t dstart3_32            : 16; /**< [527:512] Available Dstart3 Of 33rd Dstart3 */
#else /* Word 8 - Little Endian */
        uint64_t dstart3_32            : 16; /**< [527:512] Available Dstart3 Of 33rd Dstart3 */
        uint64_t dstart3_33            : 16; /**< [543:528] Available Dstart3 Of 34th Dstart3 */
        uint64_t dstart3_34            : 16; /**< [559:544] Available Dstart3 Of 35th Dstart3 */
        uint64_t dstart3_35            : 16; /**< [575:560] Available Dstart3 Of 36th Dstart3 */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t dstart3_39            : 16; /**< [639:624] Available Dstart3 Of 40th Dstart3 */
        uint64_t dstart3_38            : 16; /**< [623:608] Available Dstart3 Of 39th Dstart3 */
        uint64_t dstart3_37            : 16; /**< [607:592] Available Dstart3 Of 38th Dstart3 */
        uint64_t dstart3_36            : 16; /**< [591:576] Available Dstart3 Of 37th Dstart3 */
#else /* Word 9 - Little Endian */
        uint64_t dstart3_36            : 16; /**< [591:576] Available Dstart3 Of 37th Dstart3 */
        uint64_t dstart3_37            : 16; /**< [607:592] Available Dstart3 Of 38th Dstart3 */
        uint64_t dstart3_38            : 16; /**< [623:608] Available Dstart3 Of 39th Dstart3 */
        uint64_t dstart3_39            : 16; /**< [639:624] Available Dstart3 Of 40th Dstart3 */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t dstart3_43            : 16; /**< [703:688] Available Dstart3 Of 44th Dstart3 */
        uint64_t dstart3_42            : 16; /**< [687:672] Available Dstart3 Of 43rd Dstart3 */
        uint64_t dstart3_41            : 16; /**< [671:656] Available Dstart3 Of 42nd Dstart3 */
        uint64_t dstart3_40            : 16; /**< [655:640] Available Dstart3 Of 41st Dstart3 */
#else /* Word 10 - Little Endian */
        uint64_t dstart3_40            : 16; /**< [655:640] Available Dstart3 Of 41st Dstart3 */
        uint64_t dstart3_41            : 16; /**< [671:656] Available Dstart3 Of 42nd Dstart3 */
        uint64_t dstart3_42            : 16; /**< [687:672] Available Dstart3 Of 43rd Dstart3 */
        uint64_t dstart3_43            : 16; /**< [703:688] Available Dstart3 Of 44th Dstart3 */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t dstart3_47            : 16; /**< [767:752] Available Dstart3 Of 48th Dstart3 */
        uint64_t dstart3_46            : 16; /**< [751:736] Available Dstart3 Of 47th Dstart3 */
        uint64_t dstart3_45            : 16; /**< [735:720] Available Dstart3 Of 46th Dstart3 */
        uint64_t dstart3_44            : 16; /**< [719:704] Available Dstart3 Of 45th Dstart3 */
#else /* Word 11 - Little Endian */
        uint64_t dstart3_44            : 16; /**< [719:704] Available Dstart3 Of 45th Dstart3 */
        uint64_t dstart3_45            : 16; /**< [735:720] Available Dstart3 Of 46th Dstart3 */
        uint64_t dstart3_46            : 16; /**< [751:736] Available Dstart3 Of 47th Dstart3 */
        uint64_t dstart3_47            : 16; /**< [767:752] Available Dstart3 Of 48th Dstart3 */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t dstart3_51            : 16; /**< [831:816] Available Dstart3 Of 52nd Dstart3 */
        uint64_t dstart3_50            : 16; /**< [815:800] Available Dstart3 Of 51st Dstart3 */
        uint64_t dstart3_49            : 16; /**< [799:784] Available Dstart3 Of 50th Dstart3 */
        uint64_t dstart3_48            : 16; /**< [783:768] Available Dstart3 Of 49th Dstart3 */
#else /* Word 12 - Little Endian */
        uint64_t dstart3_48            : 16; /**< [783:768] Available Dstart3 Of 49th Dstart3 */
        uint64_t dstart3_49            : 16; /**< [799:784] Available Dstart3 Of 50th Dstart3 */
        uint64_t dstart3_50            : 16; /**< [815:800] Available Dstart3 Of 51st Dstart3 */
        uint64_t dstart3_51            : 16; /**< [831:816] Available Dstart3 Of 52nd Dstart3 */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t dstart3_55            : 16; /**< [895:880] Available Dstart3 Of 56th Dstart3 */
        uint64_t dstart3_54            : 16; /**< [879:864] Available Dstart3 Of 55th Dstart3 */
        uint64_t dstart3_53            : 16; /**< [863:848] Available Dstart3 Of 54th Dstart3 */
        uint64_t dstart3_52            : 16; /**< [847:832] Available Dstart3 Of 53rd Dstart3 */
#else /* Word 13 - Little Endian */
        uint64_t dstart3_52            : 16; /**< [847:832] Available Dstart3 Of 53rd Dstart3 */
        uint64_t dstart3_53            : 16; /**< [863:848] Available Dstart3 Of 54th Dstart3 */
        uint64_t dstart3_54            : 16; /**< [879:864] Available Dstart3 Of 55th Dstart3 */
        uint64_t dstart3_55            : 16; /**< [895:880] Available Dstart3 Of 56th Dstart3 */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t dstart3_59            : 16; /**< [959:944] Available Dstart3 Of 60th Dstart3 */
        uint64_t dstart3_58            : 16; /**< [943:928] Available Dstart3 Of 59th Dstart3 */
        uint64_t dstart3_57            : 16; /**< [927:912] Available Dstart3 Of 58th Dstart3 */
        uint64_t dstart3_56            : 16; /**< [911:896] Available Dstart3 Of 57th Dstart3 */
#else /* Word 14 - Little Endian */
        uint64_t dstart3_56            : 16; /**< [911:896] Available Dstart3 Of 57th Dstart3 */
        uint64_t dstart3_57            : 16; /**< [927:912] Available Dstart3 Of 58th Dstart3 */
        uint64_t dstart3_58            : 16; /**< [943:928] Available Dstart3 Of 59th Dstart3 */
        uint64_t dstart3_59            : 16; /**< [959:944] Available Dstart3 Of 60th Dstart3 */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t dstart3_63            : 16; /**< [1023:1008] Available Dstart3 Of 64th Dstart3 */
        uint64_t dstart3_62            : 16; /**< [1007:992] Available Dstart3 Of 63rd Dstart3 */
        uint64_t dstart3_61            : 16; /**< [991:976] Available Dstart3 Of 62nd Dstart3 */
        uint64_t dstart3_60            : 16; /**< [975:960] Available Dstart3 Of 61st Dstart3 */
#else /* Word 15 - Little Endian */
        uint64_t dstart3_60            : 16; /**< [975:960] Available Dstart3 Of 61st Dstart3 */
        uint64_t dstart3_61            : 16; /**< [991:976] Available Dstart3 Of 62nd Dstart3 */
        uint64_t dstart3_62            : 16; /**< [1007:992] Available Dstart3 Of 63rd Dstart3 */
        uint64_t dstart3_63            : 16; /**< [1023:1008] Available Dstart3 Of 64th Dstart3 */
#endif /* Word 15 - End */
    } s;
    /* struct cavm_prach_jd_dstart3_s_s cn; */
};

/**
 * Structure prach_jd_dstart_s
 *
 * PRACH Dstart Structure
 */
union cavm_prach_jd_dstart_s
{
    uint64_t u[16];
    struct cavm_prach_jd_dstart_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_3              : 16; /**< [ 63: 48] Available Dstart Of 4th Dstart */
        uint64_t dstart_2              : 16; /**< [ 47: 32] Available Dstart Of 3rd Dstart */
        uint64_t dstart_1              : 16; /**< [ 31: 16] Available Dstart Of 2nd Dstart */
        uint64_t dstart_0              : 16; /**< [ 15:  0] Available Dstart Of start Dstart */
#else /* Word 0 - Little Endian */
        uint64_t dstart_0              : 16; /**< [ 15:  0] Available Dstart Of start Dstart */
        uint64_t dstart_1              : 16; /**< [ 31: 16] Available Dstart Of 2nd Dstart */
        uint64_t dstart_2              : 16; /**< [ 47: 32] Available Dstart Of 3rd Dstart */
        uint64_t dstart_3              : 16; /**< [ 63: 48] Available Dstart Of 4th Dstart */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t dstart_7              : 16; /**< [127:112] Available Dstart Of 8th Dstart */
        uint64_t dstart_6              : 16; /**< [111: 96] Available Dstart Of 7th Dstart */
        uint64_t dstart_5              : 16; /**< [ 95: 80] Available Dstart Of 6th Dstart */
        uint64_t dstart_4              : 16; /**< [ 79: 64] Available Dstart Of 5th Dstart */
#else /* Word 1 - Little Endian */
        uint64_t dstart_4              : 16; /**< [ 79: 64] Available Dstart Of 5th Dstart */
        uint64_t dstart_5              : 16; /**< [ 95: 80] Available Dstart Of 6th Dstart */
        uint64_t dstart_6              : 16; /**< [111: 96] Available Dstart Of 7th Dstart */
        uint64_t dstart_7              : 16; /**< [127:112] Available Dstart Of 8th Dstart */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t dstart_11             : 16; /**< [191:176] Available Dstart Of 12nd Dstart */
        uint64_t dstart_10             : 16; /**< [175:160] Available Dstart Of 11st Dstart */
        uint64_t dstart_9              : 16; /**< [159:144] Available Dstart Of 10th Dstart */
        uint64_t dstart_8              : 16; /**< [143:128] Available Dstart Of 9th Dstart */
#else /* Word 2 - Little Endian */
        uint64_t dstart_8              : 16; /**< [143:128] Available Dstart Of 9th Dstart */
        uint64_t dstart_9              : 16; /**< [159:144] Available Dstart Of 10th Dstart */
        uint64_t dstart_10             : 16; /**< [175:160] Available Dstart Of 11st Dstart */
        uint64_t dstart_11             : 16; /**< [191:176] Available Dstart Of 12nd Dstart */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t dstart_15             : 16; /**< [255:240] Available Dstart Of 16th Dstart */
        uint64_t dstart_14             : 16; /**< [239:224] Available Dstart Of 15th Dstart */
        uint64_t dstart_13             : 16; /**< [223:208] Available Dstart Of 14th Dstart */
        uint64_t dstart_12             : 16; /**< [207:192] Available Dstart Of 13rd Dstart */
#else /* Word 3 - Little Endian */
        uint64_t dstart_12             : 16; /**< [207:192] Available Dstart Of 13rd Dstart */
        uint64_t dstart_13             : 16; /**< [223:208] Available Dstart Of 14th Dstart */
        uint64_t dstart_14             : 16; /**< [239:224] Available Dstart Of 15th Dstart */
        uint64_t dstart_15             : 16; /**< [255:240] Available Dstart Of 16th Dstart */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t dstart_19             : 16; /**< [319:304] Available Dstart Of 20th Dstart */
        uint64_t dstart_18             : 16; /**< [303:288] Available Dstart Of 19th Dstart */
        uint64_t dstart_17             : 16; /**< [287:272] Available Dstart Of 18th Dstart */
        uint64_t dstart_16             : 16; /**< [271:256] Available Dstart Of 17th Dstart */
#else /* Word 4 - Little Endian */
        uint64_t dstart_16             : 16; /**< [271:256] Available Dstart Of 17th Dstart */
        uint64_t dstart_17             : 16; /**< [287:272] Available Dstart Of 18th Dstart */
        uint64_t dstart_18             : 16; /**< [303:288] Available Dstart Of 19th Dstart */
        uint64_t dstart_19             : 16; /**< [319:304] Available Dstart Of 20th Dstart */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t dstart_23             : 16; /**< [383:368] Available Dstart Of 24th Dstart */
        uint64_t dstart_22             : 16; /**< [367:352] Available Dstart Of 23rd Dstart */
        uint64_t dstart_21             : 16; /**< [351:336] Available Dstart Of 22nd Dstart */
        uint64_t dstart_20             : 16; /**< [335:320] Available Dstart Of 21st Dstart */
#else /* Word 5 - Little Endian */
        uint64_t dstart_20             : 16; /**< [335:320] Available Dstart Of 21st Dstart */
        uint64_t dstart_21             : 16; /**< [351:336] Available Dstart Of 22nd Dstart */
        uint64_t dstart_22             : 16; /**< [367:352] Available Dstart Of 23rd Dstart */
        uint64_t dstart_23             : 16; /**< [383:368] Available Dstart Of 24th Dstart */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t dstart_27             : 16; /**< [447:432] Available Dstart Of 28th Dstart */
        uint64_t dstart_26             : 16; /**< [431:416] Available Dstart Of 27th Dstart */
        uint64_t dstart_25             : 16; /**< [415:400] Available Dstart Of 26th Dstart */
        uint64_t dstart_24             : 16; /**< [399:384] Available Dstart Of 25th Dstart */
#else /* Word 6 - Little Endian */
        uint64_t dstart_24             : 16; /**< [399:384] Available Dstart Of 25th Dstart */
        uint64_t dstart_25             : 16; /**< [415:400] Available Dstart Of 26th Dstart */
        uint64_t dstart_26             : 16; /**< [431:416] Available Dstart Of 27th Dstart */
        uint64_t dstart_27             : 16; /**< [447:432] Available Dstart Of 28th Dstart */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t dstart_31             : 16; /**< [511:496] Available Dstart Of 32nd Dstart */
        uint64_t dstart_30             : 16; /**< [495:480] Available Dstart Of 31st Dstart */
        uint64_t dstart_29             : 16; /**< [479:464] Available Dstart Of 30th Dstart */
        uint64_t dstart_28             : 16; /**< [463:448] Available Dstart Of 29th Dstart */
#else /* Word 7 - Little Endian */
        uint64_t dstart_28             : 16; /**< [463:448] Available Dstart Of 29th Dstart */
        uint64_t dstart_29             : 16; /**< [479:464] Available Dstart Of 30th Dstart */
        uint64_t dstart_30             : 16; /**< [495:480] Available Dstart Of 31st Dstart */
        uint64_t dstart_31             : 16; /**< [511:496] Available Dstart Of 32nd Dstart */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t dstart_35             : 16; /**< [575:560] Available Dstart Of 36th Dstart */
        uint64_t dstart_34             : 16; /**< [559:544] Available Dstart Of 35th Dstart */
        uint64_t dstart_33             : 16; /**< [543:528] Available Dstart Of 34th Dstart */
        uint64_t dstart_32             : 16; /**< [527:512] Available Dstart Of 33rd Dstart */
#else /* Word 8 - Little Endian */
        uint64_t dstart_32             : 16; /**< [527:512] Available Dstart Of 33rd Dstart */
        uint64_t dstart_33             : 16; /**< [543:528] Available Dstart Of 34th Dstart */
        uint64_t dstart_34             : 16; /**< [559:544] Available Dstart Of 35th Dstart */
        uint64_t dstart_35             : 16; /**< [575:560] Available Dstart Of 36th Dstart */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t dstart_39             : 16; /**< [639:624] Available Dstart Of 40th Dstart */
        uint64_t dstart_38             : 16; /**< [623:608] Available Dstart Of 39th Dstart */
        uint64_t dstart_37             : 16; /**< [607:592] Available Dstart Of 38th Dstart */
        uint64_t dstart_36             : 16; /**< [591:576] Available Dstart Of 37th Dstart */
#else /* Word 9 - Little Endian */
        uint64_t dstart_36             : 16; /**< [591:576] Available Dstart Of 37th Dstart */
        uint64_t dstart_37             : 16; /**< [607:592] Available Dstart Of 38th Dstart */
        uint64_t dstart_38             : 16; /**< [623:608] Available Dstart Of 39th Dstart */
        uint64_t dstart_39             : 16; /**< [639:624] Available Dstart Of 40th Dstart */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t dstart_43             : 16; /**< [703:688] Available Dstart Of 44th Dstart */
        uint64_t dstart_42             : 16; /**< [687:672] Available Dstart Of 43rd Dstart */
        uint64_t dstart_41             : 16; /**< [671:656] Available Dstart Of 42nd Dstart */
        uint64_t dstart_40             : 16; /**< [655:640] Available Dstart Of 41st Dstart */
#else /* Word 10 - Little Endian */
        uint64_t dstart_40             : 16; /**< [655:640] Available Dstart Of 41st Dstart */
        uint64_t dstart_41             : 16; /**< [671:656] Available Dstart Of 42nd Dstart */
        uint64_t dstart_42             : 16; /**< [687:672] Available Dstart Of 43rd Dstart */
        uint64_t dstart_43             : 16; /**< [703:688] Available Dstart Of 44th Dstart */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t dstart_47             : 16; /**< [767:752] Available Dstart Of 48th Dstart */
        uint64_t dstart_46             : 16; /**< [751:736] Available Dstart Of 47th Dstart */
        uint64_t dstart_45             : 16; /**< [735:720] Available Dstart Of 46th Dstart */
        uint64_t dstart_44             : 16; /**< [719:704] Available Dstart Of 45th Dstart */
#else /* Word 11 - Little Endian */
        uint64_t dstart_44             : 16; /**< [719:704] Available Dstart Of 45th Dstart */
        uint64_t dstart_45             : 16; /**< [735:720] Available Dstart Of 46th Dstart */
        uint64_t dstart_46             : 16; /**< [751:736] Available Dstart Of 47th Dstart */
        uint64_t dstart_47             : 16; /**< [767:752] Available Dstart Of 48th Dstart */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t dstart_51             : 16; /**< [831:816] Available Dstart Of 52nd Dstart */
        uint64_t dstart_50             : 16; /**< [815:800] Available Dstart Of 51st Dstart */
        uint64_t dstart_49             : 16; /**< [799:784] Available Dstart Of 50th Dstart */
        uint64_t dstart_48             : 16; /**< [783:768] Available Dstart Of 49th Dstart */
#else /* Word 12 - Little Endian */
        uint64_t dstart_48             : 16; /**< [783:768] Available Dstart Of 49th Dstart */
        uint64_t dstart_49             : 16; /**< [799:784] Available Dstart Of 50th Dstart */
        uint64_t dstart_50             : 16; /**< [815:800] Available Dstart Of 51st Dstart */
        uint64_t dstart_51             : 16; /**< [831:816] Available Dstart Of 52nd Dstart */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t dstart_55             : 16; /**< [895:880] Available Dstart Of 56th Dstart */
        uint64_t dstart_54             : 16; /**< [879:864] Available Dstart Of 55th Dstart */
        uint64_t dstart_53             : 16; /**< [863:848] Available Dstart Of 54th Dstart */
        uint64_t dstart_52             : 16; /**< [847:832] Available Dstart Of 53rd Dstart */
#else /* Word 13 - Little Endian */
        uint64_t dstart_52             : 16; /**< [847:832] Available Dstart Of 53rd Dstart */
        uint64_t dstart_53             : 16; /**< [863:848] Available Dstart Of 54th Dstart */
        uint64_t dstart_54             : 16; /**< [879:864] Available Dstart Of 55th Dstart */
        uint64_t dstart_55             : 16; /**< [895:880] Available Dstart Of 56th Dstart */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t dstart_59             : 16; /**< [959:944] Available Dstart Of 60th Dstart */
        uint64_t dstart_58             : 16; /**< [943:928] Available Dstart Of 59th Dstart */
        uint64_t dstart_57             : 16; /**< [927:912] Available Dstart Of 58th Dstart */
        uint64_t dstart_56             : 16; /**< [911:896] Available Dstart Of 57th Dstart */
#else /* Word 14 - Little Endian */
        uint64_t dstart_56             : 16; /**< [911:896] Available Dstart Of 57th Dstart */
        uint64_t dstart_57             : 16; /**< [927:912] Available Dstart Of 58th Dstart */
        uint64_t dstart_58             : 16; /**< [943:928] Available Dstart Of 59th Dstart */
        uint64_t dstart_59             : 16; /**< [959:944] Available Dstart Of 60th Dstart */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t dstart_63             : 16; /**< [1023:1008] Available Dstart Of 64th Dstart */
        uint64_t dstart_62             : 16; /**< [1007:992] Available Dstart Of 63rd Dstart */
        uint64_t dstart_61             : 16; /**< [991:976] Available Dstart Of 62nd Dstart */
        uint64_t dstart_60             : 16; /**< [975:960] Available Dstart Of 61st Dstart */
#else /* Word 15 - Little Endian */
        uint64_t dstart_60             : 16; /**< [975:960] Available Dstart Of 61st Dstart */
        uint64_t dstart_61             : 16; /**< [991:976] Available Dstart Of 62nd Dstart */
        uint64_t dstart_62             : 16; /**< [1007:992] Available Dstart Of 63rd Dstart */
        uint64_t dstart_63             : 16; /**< [1023:1008] Available Dstart Of 64th Dstart */
#endif /* Word 15 - End */
    } s;
    /* struct cavm_prach_jd_dstart_s_s cn; */
};

/**
 * Structure prach_jd_du_s
 *
 * PRACH Du Structure
 */
union cavm_prach_jd_du_s
{
    uint64_t u[16];
    struct cavm_prach_jd_du_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_3                  : 16; /**< [ 63: 48] Available Du Of 4th Du */
        uint64_t du_2                  : 16; /**< [ 47: 32] Available Du Of 3rd Du */
        uint64_t du_1                  : 16; /**< [ 31: 16] Available Du Of 2nd Du */
        uint64_t du_0                  : 16; /**< [ 15:  0] Available Du Of start Du */
#else /* Word 0 - Little Endian */
        uint64_t du_0                  : 16; /**< [ 15:  0] Available Du Of start Du */
        uint64_t du_1                  : 16; /**< [ 31: 16] Available Du Of 2nd Du */
        uint64_t du_2                  : 16; /**< [ 47: 32] Available Du Of 3rd Du */
        uint64_t du_3                  : 16; /**< [ 63: 48] Available Du Of 4th Du */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t du_7                  : 16; /**< [127:112] Available Du Of 8th Du */
        uint64_t du_6                  : 16; /**< [111: 96] Available Du Of 7th Du */
        uint64_t du_5                  : 16; /**< [ 95: 80] Available Du Of 6th Du */
        uint64_t du_4                  : 16; /**< [ 79: 64] Available Du Of 5th Du */
#else /* Word 1 - Little Endian */
        uint64_t du_4                  : 16; /**< [ 79: 64] Available Du Of 5th Du */
        uint64_t du_5                  : 16; /**< [ 95: 80] Available Du Of 6th Du */
        uint64_t du_6                  : 16; /**< [111: 96] Available Du Of 7th Du */
        uint64_t du_7                  : 16; /**< [127:112] Available Du Of 8th Du */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t du_11                 : 16; /**< [191:176] Available Du Of 12nd Du */
        uint64_t du_10                 : 16; /**< [175:160] Available Du Of 11st Du */
        uint64_t du_9                  : 16; /**< [159:144] Available Du Of 10th Du */
        uint64_t du_8                  : 16; /**< [143:128] Available Du Of 9th Du */
#else /* Word 2 - Little Endian */
        uint64_t du_8                  : 16; /**< [143:128] Available Du Of 9th Du */
        uint64_t du_9                  : 16; /**< [159:144] Available Du Of 10th Du */
        uint64_t du_10                 : 16; /**< [175:160] Available Du Of 11st Du */
        uint64_t du_11                 : 16; /**< [191:176] Available Du Of 12nd Du */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t du_15                 : 16; /**< [255:240] Available Du Of 16th Du */
        uint64_t du_14                 : 16; /**< [239:224] Available Du Of 15th Du */
        uint64_t du_13                 : 16; /**< [223:208] Available Du Of 14th Du */
        uint64_t du_12                 : 16; /**< [207:192] Available Du Of 13rd Du */
#else /* Word 3 - Little Endian */
        uint64_t du_12                 : 16; /**< [207:192] Available Du Of 13rd Du */
        uint64_t du_13                 : 16; /**< [223:208] Available Du Of 14th Du */
        uint64_t du_14                 : 16; /**< [239:224] Available Du Of 15th Du */
        uint64_t du_15                 : 16; /**< [255:240] Available Du Of 16th Du */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t du_19                 : 16; /**< [319:304] Available Du Of 20th Du */
        uint64_t du_18                 : 16; /**< [303:288] Available Du Of 19th Du */
        uint64_t du_17                 : 16; /**< [287:272] Available Du Of 18th Du */
        uint64_t du_16                 : 16; /**< [271:256] Available Du Of 17th Du */
#else /* Word 4 - Little Endian */
        uint64_t du_16                 : 16; /**< [271:256] Available Du Of 17th Du */
        uint64_t du_17                 : 16; /**< [287:272] Available Du Of 18th Du */
        uint64_t du_18                 : 16; /**< [303:288] Available Du Of 19th Du */
        uint64_t du_19                 : 16; /**< [319:304] Available Du Of 20th Du */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t du_23                 : 16; /**< [383:368] Available Du Of 24th Du */
        uint64_t du_22                 : 16; /**< [367:352] Available Du Of 23rd Du */
        uint64_t du_21                 : 16; /**< [351:336] Available Du Of 22nd Du */
        uint64_t du_20                 : 16; /**< [335:320] Available Du Of 21st Du */
#else /* Word 5 - Little Endian */
        uint64_t du_20                 : 16; /**< [335:320] Available Du Of 21st Du */
        uint64_t du_21                 : 16; /**< [351:336] Available Du Of 22nd Du */
        uint64_t du_22                 : 16; /**< [367:352] Available Du Of 23rd Du */
        uint64_t du_23                 : 16; /**< [383:368] Available Du Of 24th Du */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t du_27                 : 16; /**< [447:432] Available Du Of 28th Du */
        uint64_t du_26                 : 16; /**< [431:416] Available Du Of 27th Du */
        uint64_t du_25                 : 16; /**< [415:400] Available Du Of 26th Du */
        uint64_t du_24                 : 16; /**< [399:384] Available Du Of 25th Du */
#else /* Word 6 - Little Endian */
        uint64_t du_24                 : 16; /**< [399:384] Available Du Of 25th Du */
        uint64_t du_25                 : 16; /**< [415:400] Available Du Of 26th Du */
        uint64_t du_26                 : 16; /**< [431:416] Available Du Of 27th Du */
        uint64_t du_27                 : 16; /**< [447:432] Available Du Of 28th Du */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t du_31                 : 16; /**< [511:496] Available Du Of 32nd Du */
        uint64_t du_30                 : 16; /**< [495:480] Available Du Of 31st Du */
        uint64_t du_29                 : 16; /**< [479:464] Available Du Of 30th Du */
        uint64_t du_28                 : 16; /**< [463:448] Available Du Of 29th Du */
#else /* Word 7 - Little Endian */
        uint64_t du_28                 : 16; /**< [463:448] Available Du Of 29th Du */
        uint64_t du_29                 : 16; /**< [479:464] Available Du Of 30th Du */
        uint64_t du_30                 : 16; /**< [495:480] Available Du Of 31st Du */
        uint64_t du_31                 : 16; /**< [511:496] Available Du Of 32nd Du */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t du_35                 : 16; /**< [575:560] Available Du Of 36th Du */
        uint64_t du_34                 : 16; /**< [559:544] Available Du Of 35th Du */
        uint64_t du_33                 : 16; /**< [543:528] Available Du Of 34th Du */
        uint64_t du_32                 : 16; /**< [527:512] Available Du Of 33rd Du */
#else /* Word 8 - Little Endian */
        uint64_t du_32                 : 16; /**< [527:512] Available Du Of 33rd Du */
        uint64_t du_33                 : 16; /**< [543:528] Available Du Of 34th Du */
        uint64_t du_34                 : 16; /**< [559:544] Available Du Of 35th Du */
        uint64_t du_35                 : 16; /**< [575:560] Available Du Of 36th Du */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t du_39                 : 16; /**< [639:624] Available Du Of 40th Du */
        uint64_t du_38                 : 16; /**< [623:608] Available Du Of 39th Du */
        uint64_t du_37                 : 16; /**< [607:592] Available Du Of 38th Du */
        uint64_t du_36                 : 16; /**< [591:576] Available Du Of 37th Du */
#else /* Word 9 - Little Endian */
        uint64_t du_36                 : 16; /**< [591:576] Available Du Of 37th Du */
        uint64_t du_37                 : 16; /**< [607:592] Available Du Of 38th Du */
        uint64_t du_38                 : 16; /**< [623:608] Available Du Of 39th Du */
        uint64_t du_39                 : 16; /**< [639:624] Available Du Of 40th Du */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t du_43                 : 16; /**< [703:688] Available Du Of 44th Du */
        uint64_t du_42                 : 16; /**< [687:672] Available Du Of 43rd Du */
        uint64_t du_41                 : 16; /**< [671:656] Available Du Of 42nd Du */
        uint64_t du_40                 : 16; /**< [655:640] Available Du Of 41st Du */
#else /* Word 10 - Little Endian */
        uint64_t du_40                 : 16; /**< [655:640] Available Du Of 41st Du */
        uint64_t du_41                 : 16; /**< [671:656] Available Du Of 42nd Du */
        uint64_t du_42                 : 16; /**< [687:672] Available Du Of 43rd Du */
        uint64_t du_43                 : 16; /**< [703:688] Available Du Of 44th Du */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t du_47                 : 16; /**< [767:752] Available Du Of 48th Du */
        uint64_t du_46                 : 16; /**< [751:736] Available Du Of 47th Du */
        uint64_t du_45                 : 16; /**< [735:720] Available Du Of 46th Du */
        uint64_t du_44                 : 16; /**< [719:704] Available Du Of 45th Du */
#else /* Word 11 - Little Endian */
        uint64_t du_44                 : 16; /**< [719:704] Available Du Of 45th Du */
        uint64_t du_45                 : 16; /**< [735:720] Available Du Of 46th Du */
        uint64_t du_46                 : 16; /**< [751:736] Available Du Of 47th Du */
        uint64_t du_47                 : 16; /**< [767:752] Available Du Of 48th Du */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t du_51                 : 16; /**< [831:816] Available Du Of 52nd Du */
        uint64_t du_50                 : 16; /**< [815:800] Available Du Of 51st Du */
        uint64_t du_49                 : 16; /**< [799:784] Available Du Of 50th Du */
        uint64_t du_48                 : 16; /**< [783:768] Available Du Of 49th Du */
#else /* Word 12 - Little Endian */
        uint64_t du_48                 : 16; /**< [783:768] Available Du Of 49th Du */
        uint64_t du_49                 : 16; /**< [799:784] Available Du Of 50th Du */
        uint64_t du_50                 : 16; /**< [815:800] Available Du Of 51st Du */
        uint64_t du_51                 : 16; /**< [831:816] Available Du Of 52nd Du */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t du_55                 : 16; /**< [895:880] Available Du Of 56th Du */
        uint64_t du_54                 : 16; /**< [879:864] Available Du Of 55th Du */
        uint64_t du_53                 : 16; /**< [863:848] Available Du Of 54th Du */
        uint64_t du_52                 : 16; /**< [847:832] Available Du Of 53rd Du */
#else /* Word 13 - Little Endian */
        uint64_t du_52                 : 16; /**< [847:832] Available Du Of 53rd Du */
        uint64_t du_53                 : 16; /**< [863:848] Available Du Of 54th Du */
        uint64_t du_54                 : 16; /**< [879:864] Available Du Of 55th Du */
        uint64_t du_55                 : 16; /**< [895:880] Available Du Of 56th Du */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t du_59                 : 16; /**< [959:944] Available Du Of 60th Du */
        uint64_t du_58                 : 16; /**< [943:928] Available Du Of 59th Du */
        uint64_t du_57                 : 16; /**< [927:912] Available Du Of 58th Du */
        uint64_t du_56                 : 16; /**< [911:896] Available Du Of 57th Du */
#else /* Word 14 - Little Endian */
        uint64_t du_56                 : 16; /**< [911:896] Available Du Of 57th Du */
        uint64_t du_57                 : 16; /**< [927:912] Available Du Of 58th Du */
        uint64_t du_58                 : 16; /**< [943:928] Available Du Of 59th Du */
        uint64_t du_59                 : 16; /**< [959:944] Available Du Of 60th Du */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t du_63                 : 16; /**< [1023:1008] Available Du Of 64th Du */
        uint64_t du_62                 : 16; /**< [1007:992] Available Du Of 63rd Du */
        uint64_t du_61                 : 16; /**< [991:976] Available Du Of 62nd Du */
        uint64_t du_60                 : 16; /**< [975:960] Available Du Of 61st Du */
#else /* Word 15 - Little Endian */
        uint64_t du_60                 : 16; /**< [975:960] Available Du Of 61st Du */
        uint64_t du_61                 : 16; /**< [991:976] Available Du Of 62nd Du */
        uint64_t du_62                 : 16; /**< [1007:992] Available Du Of 63rd Du */
        uint64_t du_63                 : 16; /**< [1023:1008] Available Du Of 64th Du */
#endif /* Word 15 - End */
    } s;
    /* struct cavm_prach_jd_du_s_s cn; */
};

/**
 * Structure prach_jd_jobcfg_s
 *
 * PRACH Job Configuration Structure
 */
union cavm_prach_jd_jobcfg_s
{
    uint64_t u;
    struct cavm_prach_jd_jobcfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t job_config            : 2;  /**< [  1:  0] Define job type:
                                                                 0x0: Job type 0 - used for \<= 8 antennas and only one job.
                                                                 0x1: Job type 1 - first job when combining power profiles.
                                                                 0x2: Job type 2 - middle job when combining power profiles.
                                                                 0x3: Job type 3 - last job when combining power profiles. */
#else /* Word 0 - Little Endian */
        uint64_t job_config            : 2;  /**< [  1:  0] Define job type:
                                                                 0x0: Job type 0 - used for \<= 8 antennas and only one job.
                                                                 0x1: Job type 1 - first job when combining power profiles.
                                                                 0x2: Job type 2 - middle job when combining power profiles.
                                                                 0x3: Job type 3 - last job when combining power profiles. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_jd_jobcfg_s_s cnf95xx; */
    struct cavm_prach_jd_jobcfg_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t job_config            : 2;  /**< [  1:  0] Define job type:
                                                                 0x0 = Job type 0. Used for \<= 8 antennas and only one job.
                                                                 0x1 = Job type 1. First job when combining power profiles.
                                                                 0x2 = Job type 2. Middle job when combining power profiles.
                                                                 0x3 = Job type 3. Last job when combining power profiles. */
#else /* Word 0 - Little Endian */
        uint64_t job_config            : 2;  /**< [  1:  0] Define job type:
                                                                 0x0 = Job type 0. Used for \<= 8 antennas and only one job.
                                                                 0x1 = Job type 1. First job when combining power profiles.
                                                                 0x2 = Job type 2. Middle job when combining power profiles.
                                                                 0x3 = Job type 3. Last job when combining power profiles. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } loki;
};

/**
 * Structure prach_jd_logical_idx_s
 *
 * PRACH Logical Index Structure
 */
union cavm_prach_jd_logical_idx_s
{
    uint64_t u[16];
    struct cavm_prach_jd_logical_idx_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_3       : 16; /**< [ 63: 48] Available logical index Of 4th logical index */
        uint64_t logical_index_2       : 16; /**< [ 47: 32] Available logical index Of 3rd logical index */
        uint64_t logical_index_1       : 16; /**< [ 31: 16] Available logical index Of 2nd logical index */
        uint64_t logical_index_0       : 16; /**< [ 15:  0] Available logical index Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_0       : 16; /**< [ 15:  0] Available logical index Of start logical index */
        uint64_t logical_index_1       : 16; /**< [ 31: 16] Available logical index Of 2nd logical index */
        uint64_t logical_index_2       : 16; /**< [ 47: 32] Available logical index Of 3rd logical index */
        uint64_t logical_index_3       : 16; /**< [ 63: 48] Available logical index Of 4th logical index */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t logical_index_7       : 16; /**< [127:112] Available logical index Of 8th logical index */
        uint64_t logical_index_6       : 16; /**< [111: 96] Available logical index Of 7th logical index */
        uint64_t logical_index_5       : 16; /**< [ 95: 80] Available logical index Of 6th logical index */
        uint64_t logical_index_4       : 16; /**< [ 79: 64] Available logical index Of 5th logical index */
#else /* Word 1 - Little Endian */
        uint64_t logical_index_4       : 16; /**< [ 79: 64] Available logical index Of 5th logical index */
        uint64_t logical_index_5       : 16; /**< [ 95: 80] Available logical index Of 6th logical index */
        uint64_t logical_index_6       : 16; /**< [111: 96] Available logical index Of 7th logical index */
        uint64_t logical_index_7       : 16; /**< [127:112] Available logical index Of 8th logical index */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t logical_index_11      : 16; /**< [191:176] Available logical index Of 12nd logical index */
        uint64_t logical_index_10      : 16; /**< [175:160] Available logical index Of 11st logical index */
        uint64_t logical_index_9       : 16; /**< [159:144] Available logical index Of 10th logical index */
        uint64_t logical_index_8       : 16; /**< [143:128] Available logical index Of 9th logical index */
#else /* Word 2 - Little Endian */
        uint64_t logical_index_8       : 16; /**< [143:128] Available logical index Of 9th logical index */
        uint64_t logical_index_9       : 16; /**< [159:144] Available logical index Of 10th logical index */
        uint64_t logical_index_10      : 16; /**< [175:160] Available logical index Of 11st logical index */
        uint64_t logical_index_11      : 16; /**< [191:176] Available logical index Of 12nd logical index */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t logical_index_15      : 16; /**< [255:240] Available logical index Of 16th logical index */
        uint64_t logical_index_14      : 16; /**< [239:224] Available logical index Of 15th logical index */
        uint64_t logical_index_13      : 16; /**< [223:208] Available logical index Of 14th logical index */
        uint64_t logical_index_12      : 16; /**< [207:192] Available logical index Of 13rd logical index */
#else /* Word 3 - Little Endian */
        uint64_t logical_index_12      : 16; /**< [207:192] Available logical index Of 13rd logical index */
        uint64_t logical_index_13      : 16; /**< [223:208] Available logical index Of 14th logical index */
        uint64_t logical_index_14      : 16; /**< [239:224] Available logical index Of 15th logical index */
        uint64_t logical_index_15      : 16; /**< [255:240] Available logical index Of 16th logical index */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t logical_index_19      : 16; /**< [319:304] Available logical index Of 20th logical index */
        uint64_t logical_index_18      : 16; /**< [303:288] Available logical index Of 19th logical index */
        uint64_t logical_index_17      : 16; /**< [287:272] Available logical index Of 18th logical index */
        uint64_t logical_index_16      : 16; /**< [271:256] Available logical index Of 17th logical index */
#else /* Word 4 - Little Endian */
        uint64_t logical_index_16      : 16; /**< [271:256] Available logical index Of 17th logical index */
        uint64_t logical_index_17      : 16; /**< [287:272] Available logical index Of 18th logical index */
        uint64_t logical_index_18      : 16; /**< [303:288] Available logical index Of 19th logical index */
        uint64_t logical_index_19      : 16; /**< [319:304] Available logical index Of 20th logical index */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t logical_index_23      : 16; /**< [383:368] Available logical index Of 24th logical index */
        uint64_t logical_index_22      : 16; /**< [367:352] Available logical index Of 23rd logical index */
        uint64_t logical_index_21      : 16; /**< [351:336] Available logical index Of 22nd logical index */
        uint64_t logical_index_20      : 16; /**< [335:320] Available logical index Of 21st logical index */
#else /* Word 5 - Little Endian */
        uint64_t logical_index_20      : 16; /**< [335:320] Available logical index Of 21st logical index */
        uint64_t logical_index_21      : 16; /**< [351:336] Available logical index Of 22nd logical index */
        uint64_t logical_index_22      : 16; /**< [367:352] Available logical index Of 23rd logical index */
        uint64_t logical_index_23      : 16; /**< [383:368] Available logical index Of 24th logical index */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t logical_index_27      : 16; /**< [447:432] Available logical index Of 28th logical index */
        uint64_t logical_index_26      : 16; /**< [431:416] Available logical index Of 27th logical index */
        uint64_t logical_index_25      : 16; /**< [415:400] Available logical index Of 26th logical index */
        uint64_t logical_index_24      : 16; /**< [399:384] Available logical index Of 25th logical index */
#else /* Word 6 - Little Endian */
        uint64_t logical_index_24      : 16; /**< [399:384] Available logical index Of 25th logical index */
        uint64_t logical_index_25      : 16; /**< [415:400] Available logical index Of 26th logical index */
        uint64_t logical_index_26      : 16; /**< [431:416] Available logical index Of 27th logical index */
        uint64_t logical_index_27      : 16; /**< [447:432] Available logical index Of 28th logical index */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t logical_index_31      : 16; /**< [511:496] Available logical index Of 32nd logical index */
        uint64_t logical_index_30      : 16; /**< [495:480] Available logical index Of 31st logical index */
        uint64_t logical_index_29      : 16; /**< [479:464] Available logical index Of 30th logical index */
        uint64_t logical_index_28      : 16; /**< [463:448] Available logical index Of 29th logical index */
#else /* Word 7 - Little Endian */
        uint64_t logical_index_28      : 16; /**< [463:448] Available logical index Of 29th logical index */
        uint64_t logical_index_29      : 16; /**< [479:464] Available logical index Of 30th logical index */
        uint64_t logical_index_30      : 16; /**< [495:480] Available logical index Of 31st logical index */
        uint64_t logical_index_31      : 16; /**< [511:496] Available logical index Of 32nd logical index */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t logical_index_35      : 16; /**< [575:560] Available logical index Of 36th logical index */
        uint64_t logical_index_34      : 16; /**< [559:544] Available logical index Of 35th logical index */
        uint64_t logical_index_33      : 16; /**< [543:528] Available logical index Of 34th logical index */
        uint64_t logical_index_32      : 16; /**< [527:512] Available logical index Of 33rd logical index */
#else /* Word 8 - Little Endian */
        uint64_t logical_index_32      : 16; /**< [527:512] Available logical index Of 33rd logical index */
        uint64_t logical_index_33      : 16; /**< [543:528] Available logical index Of 34th logical index */
        uint64_t logical_index_34      : 16; /**< [559:544] Available logical index Of 35th logical index */
        uint64_t logical_index_35      : 16; /**< [575:560] Available logical index Of 36th logical index */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t logical_index_39      : 16; /**< [639:624] Available logical index Of 40th logical index */
        uint64_t logical_index_38      : 16; /**< [623:608] Available logical index Of 39th logical index */
        uint64_t logical_index_37      : 16; /**< [607:592] Available logical index Of 38th logical index */
        uint64_t logical_index_36      : 16; /**< [591:576] Available logical index Of 37th logical index */
#else /* Word 9 - Little Endian */
        uint64_t logical_index_36      : 16; /**< [591:576] Available logical index Of 37th logical index */
        uint64_t logical_index_37      : 16; /**< [607:592] Available logical index Of 38th logical index */
        uint64_t logical_index_38      : 16; /**< [623:608] Available logical index Of 39th logical index */
        uint64_t logical_index_39      : 16; /**< [639:624] Available logical index Of 40th logical index */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t logical_index_43      : 16; /**< [703:688] Available logical index Of 44th logical index */
        uint64_t logical_index_42      : 16; /**< [687:672] Available logical index Of 43rd logical index */
        uint64_t logical_index_41      : 16; /**< [671:656] Available logical index Of 42nd logical index */
        uint64_t logical_index_40      : 16; /**< [655:640] Available logical index Of 41st logical index */
#else /* Word 10 - Little Endian */
        uint64_t logical_index_40      : 16; /**< [655:640] Available logical index Of 41st logical index */
        uint64_t logical_index_41      : 16; /**< [671:656] Available logical index Of 42nd logical index */
        uint64_t logical_index_42      : 16; /**< [687:672] Available logical index Of 43rd logical index */
        uint64_t logical_index_43      : 16; /**< [703:688] Available logical index Of 44th logical index */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t logical_index_47      : 16; /**< [767:752] Available logical index Of 48th logical index */
        uint64_t logical_index_46      : 16; /**< [751:736] Available logical index Of 47th logical index */
        uint64_t logical_index_45      : 16; /**< [735:720] Available logical index Of 46th logical index */
        uint64_t logical_index_44      : 16; /**< [719:704] Available logical index Of 45th logical index */
#else /* Word 11 - Little Endian */
        uint64_t logical_index_44      : 16; /**< [719:704] Available logical index Of 45th logical index */
        uint64_t logical_index_45      : 16; /**< [735:720] Available logical index Of 46th logical index */
        uint64_t logical_index_46      : 16; /**< [751:736] Available logical index Of 47th logical index */
        uint64_t logical_index_47      : 16; /**< [767:752] Available logical index Of 48th logical index */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t logical_index_51      : 16; /**< [831:816] Available logical index Of 52nd logical index */
        uint64_t logical_index_50      : 16; /**< [815:800] Available logical index Of 51st logical index */
        uint64_t logical_index_49      : 16; /**< [799:784] Available logical index Of 50th logical index */
        uint64_t logical_index_48      : 16; /**< [783:768] Available logical index Of 49th logical index */
#else /* Word 12 - Little Endian */
        uint64_t logical_index_48      : 16; /**< [783:768] Available logical index Of 49th logical index */
        uint64_t logical_index_49      : 16; /**< [799:784] Available logical index Of 50th logical index */
        uint64_t logical_index_50      : 16; /**< [815:800] Available logical index Of 51st logical index */
        uint64_t logical_index_51      : 16; /**< [831:816] Available logical index Of 52nd logical index */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t logical_index_55      : 16; /**< [895:880] Available logical index Of 56th logical index */
        uint64_t logical_index_54      : 16; /**< [879:864] Available logical index Of 55th logical index */
        uint64_t logical_index_53      : 16; /**< [863:848] Available logical index Of 54th logical index */
        uint64_t logical_index_52      : 16; /**< [847:832] Available logical index Of 53rd logical index */
#else /* Word 13 - Little Endian */
        uint64_t logical_index_52      : 16; /**< [847:832] Available logical index Of 53rd logical index */
        uint64_t logical_index_53      : 16; /**< [863:848] Available logical index Of 54th logical index */
        uint64_t logical_index_54      : 16; /**< [879:864] Available logical index Of 55th logical index */
        uint64_t logical_index_55      : 16; /**< [895:880] Available logical index Of 56th logical index */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t logical_index_59      : 16; /**< [959:944] Available logical index Of 60th logical index */
        uint64_t logical_index_58      : 16; /**< [943:928] Available logical index Of 59th logical index */
        uint64_t logical_index_57      : 16; /**< [927:912] Available logical index Of 58th logical index */
        uint64_t logical_index_56      : 16; /**< [911:896] Available logical index Of 57th logical index */
#else /* Word 14 - Little Endian */
        uint64_t logical_index_56      : 16; /**< [911:896] Available logical index Of 57th logical index */
        uint64_t logical_index_57      : 16; /**< [927:912] Available logical index Of 58th logical index */
        uint64_t logical_index_58      : 16; /**< [943:928] Available logical index Of 59th logical index */
        uint64_t logical_index_59      : 16; /**< [959:944] Available logical index Of 60th logical index */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t logical_index_63      : 16; /**< [1023:1008] Available logical index Of 64th logical index */
        uint64_t logical_index_62      : 16; /**< [1007:992] Available logical index Of 63rd logical index */
        uint64_t logical_index_61      : 16; /**< [991:976] Available logical index Of 62nd logical index */
        uint64_t logical_index_60      : 16; /**< [975:960] Available logical index Of 61st logical index */
#else /* Word 15 - Little Endian */
        uint64_t logical_index_60      : 16; /**< [975:960] Available logical index Of 61st logical index */
        uint64_t logical_index_61      : 16; /**< [991:976] Available logical index Of 62nd logical index */
        uint64_t logical_index_62      : 16; /**< [1007:992] Available logical index Of 63rd logical index */
        uint64_t logical_index_63      : 16; /**< [1023:1008] Available logical index Of 64th logical index */
#endif /* Word 15 - End */
    } s;
    /* struct cavm_prach_jd_logical_idx_s_s cn; */
};

/**
 * Structure prach_jd_ngroup_s
 *
 * PRACH Ngourp Structure
 */
union cavm_prach_jd_ngroup_s
{
    uint64_t u[8];
    struct cavm_prach_jd_ngroup_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ngroup_7              : 8;  /**< [ 63: 56] Available Ngroup Of 8th Ngroup */
        uint64_t ngroup_6              : 8;  /**< [ 55: 48] Available Ngroup Of 7th Ngroup */
        uint64_t ngroup_5              : 8;  /**< [ 47: 40] Available Ngroup Of 6th Ngroup */
        uint64_t ngroup_4              : 8;  /**< [ 39: 32] Available Ngroup Of 5th Ngroup */
        uint64_t ngroup_3              : 8;  /**< [ 31: 24] Available Ngroup Of 4th Ngroup */
        uint64_t ngroup_2              : 8;  /**< [ 23: 16] Available Ngroup Of 3rd Ngroup */
        uint64_t ngroup_1              : 8;  /**< [ 15:  8] Available Ngroup Of 2nd Ngroup */
        uint64_t ngroup_0              : 8;  /**< [  7:  0] Available Ngroup Of start Ngroup */
#else /* Word 0 - Little Endian */
        uint64_t ngroup_0              : 8;  /**< [  7:  0] Available Ngroup Of start Ngroup */
        uint64_t ngroup_1              : 8;  /**< [ 15:  8] Available Ngroup Of 2nd Ngroup */
        uint64_t ngroup_2              : 8;  /**< [ 23: 16] Available Ngroup Of 3rd Ngroup */
        uint64_t ngroup_3              : 8;  /**< [ 31: 24] Available Ngroup Of 4th Ngroup */
        uint64_t ngroup_4              : 8;  /**< [ 39: 32] Available Ngroup Of 5th Ngroup */
        uint64_t ngroup_5              : 8;  /**< [ 47: 40] Available Ngroup Of 6th Ngroup */
        uint64_t ngroup_6              : 8;  /**< [ 55: 48] Available Ngroup Of 7th Ngroup */
        uint64_t ngroup_7              : 8;  /**< [ 63: 56] Available Ngroup Of 8th Ngroup */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t ngroup_15             : 8;  /**< [127:120] Available Ngroup Of 16th Ngroup */
        uint64_t ngroup_14             : 8;  /**< [119:112] Available Ngroup Of 15th Ngroup */
        uint64_t ngroup_13             : 8;  /**< [111:104] Available Ngroup Of 14th Ngroup */
        uint64_t ngroup_12             : 8;  /**< [103: 96] Available Ngroup Of 13rd Ngroup */
        uint64_t ngroup_11             : 8;  /**< [ 95: 88] Available Ngroup Of 12nd Ngroup */
        uint64_t ngroup_10             : 8;  /**< [ 87: 80] Available Ngroup Of 11st Ngroup */
        uint64_t ngroup_9              : 8;  /**< [ 79: 72] Available Ngroup Of 10th Ngroup */
        uint64_t ngroup_8              : 8;  /**< [ 71: 64] Available Ngroup Of 9th Ngroup */
#else /* Word 1 - Little Endian */
        uint64_t ngroup_8              : 8;  /**< [ 71: 64] Available Ngroup Of 9th Ngroup */
        uint64_t ngroup_9              : 8;  /**< [ 79: 72] Available Ngroup Of 10th Ngroup */
        uint64_t ngroup_10             : 8;  /**< [ 87: 80] Available Ngroup Of 11st Ngroup */
        uint64_t ngroup_11             : 8;  /**< [ 95: 88] Available Ngroup Of 12nd Ngroup */
        uint64_t ngroup_12             : 8;  /**< [103: 96] Available Ngroup Of 13rd Ngroup */
        uint64_t ngroup_13             : 8;  /**< [111:104] Available Ngroup Of 14th Ngroup */
        uint64_t ngroup_14             : 8;  /**< [119:112] Available Ngroup Of 15th Ngroup */
        uint64_t ngroup_15             : 8;  /**< [127:120] Available Ngroup Of 16th Ngroup */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t ngroup_23             : 8;  /**< [191:184] Available Ngroup Of 24th Ngroup */
        uint64_t ngroup_22             : 8;  /**< [183:176] Available Ngroup Of 23rd Ngroup */
        uint64_t ngroup_21             : 8;  /**< [175:168] Available Ngroup Of 22nd Ngroup */
        uint64_t ngroup_20             : 8;  /**< [167:160] Available Ngroup Of 21st Ngroup */
        uint64_t ngroup_19             : 8;  /**< [159:152] Available Ngroup Of 20th Ngroup */
        uint64_t ngroup_18             : 8;  /**< [151:144] Available Ngroup Of 19th Ngroup */
        uint64_t ngroup_17             : 8;  /**< [143:136] Available Ngroup Of 18th Ngroup */
        uint64_t ngroup_16             : 8;  /**< [135:128] Available Ngroup Of 17th Ngroup */
#else /* Word 2 - Little Endian */
        uint64_t ngroup_16             : 8;  /**< [135:128] Available Ngroup Of 17th Ngroup */
        uint64_t ngroup_17             : 8;  /**< [143:136] Available Ngroup Of 18th Ngroup */
        uint64_t ngroup_18             : 8;  /**< [151:144] Available Ngroup Of 19th Ngroup */
        uint64_t ngroup_19             : 8;  /**< [159:152] Available Ngroup Of 20th Ngroup */
        uint64_t ngroup_20             : 8;  /**< [167:160] Available Ngroup Of 21st Ngroup */
        uint64_t ngroup_21             : 8;  /**< [175:168] Available Ngroup Of 22nd Ngroup */
        uint64_t ngroup_22             : 8;  /**< [183:176] Available Ngroup Of 23rd Ngroup */
        uint64_t ngroup_23             : 8;  /**< [191:184] Available Ngroup Of 24th Ngroup */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t ngroup_31             : 8;  /**< [255:248] Available Ngroup Of 32nd Ngroup */
        uint64_t ngroup_30             : 8;  /**< [247:240] Available Ngroup Of 31st Ngroup */
        uint64_t ngroup_29             : 8;  /**< [239:232] Available Ngroup Of 30th Ngroup */
        uint64_t ngroup_28             : 8;  /**< [231:224] Available Ngroup Of 29th Ngroup */
        uint64_t ngroup_27             : 8;  /**< [223:216] Available Ngroup Of 28th Ngroup */
        uint64_t ngroup_26             : 8;  /**< [215:208] Available Ngroup Of 27th Ngroup */
        uint64_t ngroup_25             : 8;  /**< [207:200] Available Ngroup Of 26th Ngroup */
        uint64_t ngroup_24             : 8;  /**< [199:192] Available Ngroup Of 25th Ngroup */
#else /* Word 3 - Little Endian */
        uint64_t ngroup_24             : 8;  /**< [199:192] Available Ngroup Of 25th Ngroup */
        uint64_t ngroup_25             : 8;  /**< [207:200] Available Ngroup Of 26th Ngroup */
        uint64_t ngroup_26             : 8;  /**< [215:208] Available Ngroup Of 27th Ngroup */
        uint64_t ngroup_27             : 8;  /**< [223:216] Available Ngroup Of 28th Ngroup */
        uint64_t ngroup_28             : 8;  /**< [231:224] Available Ngroup Of 29th Ngroup */
        uint64_t ngroup_29             : 8;  /**< [239:232] Available Ngroup Of 30th Ngroup */
        uint64_t ngroup_30             : 8;  /**< [247:240] Available Ngroup Of 31st Ngroup */
        uint64_t ngroup_31             : 8;  /**< [255:248] Available Ngroup Of 32nd Ngroup */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t ngroup_39             : 8;  /**< [319:312] Available Ngroup Of 40th Ngroup */
        uint64_t ngroup_38             : 8;  /**< [311:304] Available Ngroup Of 39th Ngroup */
        uint64_t ngroup_37             : 8;  /**< [303:296] Available Ngroup Of 38th Ngroup */
        uint64_t ngroup_36             : 8;  /**< [295:288] Available Ngroup Of 37th Ngroup */
        uint64_t ngroup_35             : 8;  /**< [287:280] Available Ngroup Of 36th Ngroup */
        uint64_t ngroup_34             : 8;  /**< [279:272] Available Ngroup Of 35th Ngroup */
        uint64_t ngroup_33             : 8;  /**< [271:264] Available Ngroup Of 34th Ngroup */
        uint64_t ngroup_32             : 8;  /**< [263:256] Available Ngroup Of 33rd Ngroup */
#else /* Word 4 - Little Endian */
        uint64_t ngroup_32             : 8;  /**< [263:256] Available Ngroup Of 33rd Ngroup */
        uint64_t ngroup_33             : 8;  /**< [271:264] Available Ngroup Of 34th Ngroup */
        uint64_t ngroup_34             : 8;  /**< [279:272] Available Ngroup Of 35th Ngroup */
        uint64_t ngroup_35             : 8;  /**< [287:280] Available Ngroup Of 36th Ngroup */
        uint64_t ngroup_36             : 8;  /**< [295:288] Available Ngroup Of 37th Ngroup */
        uint64_t ngroup_37             : 8;  /**< [303:296] Available Ngroup Of 38th Ngroup */
        uint64_t ngroup_38             : 8;  /**< [311:304] Available Ngroup Of 39th Ngroup */
        uint64_t ngroup_39             : 8;  /**< [319:312] Available Ngroup Of 40th Ngroup */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t ngroup_47             : 8;  /**< [383:376] Available Ngroup Of 48th Ngroup */
        uint64_t ngroup_46             : 8;  /**< [375:368] Available Ngroup Of 47th Ngroup */
        uint64_t ngroup_45             : 8;  /**< [367:360] Available Ngroup Of 46th Ngroup */
        uint64_t ngroup_44             : 8;  /**< [359:352] Available Ngroup Of 45th Ngroup */
        uint64_t ngroup_43             : 8;  /**< [351:344] Available Ngroup Of 44th Ngroup */
        uint64_t ngroup_42             : 8;  /**< [343:336] Available Ngroup Of 43rd Ngroup */
        uint64_t ngroup_41             : 8;  /**< [335:328] Available Ngroup Of 42nd Ngroup */
        uint64_t ngroup_40             : 8;  /**< [327:320] Available Ngroup Of 41st Ngroup */
#else /* Word 5 - Little Endian */
        uint64_t ngroup_40             : 8;  /**< [327:320] Available Ngroup Of 41st Ngroup */
        uint64_t ngroup_41             : 8;  /**< [335:328] Available Ngroup Of 42nd Ngroup */
        uint64_t ngroup_42             : 8;  /**< [343:336] Available Ngroup Of 43rd Ngroup */
        uint64_t ngroup_43             : 8;  /**< [351:344] Available Ngroup Of 44th Ngroup */
        uint64_t ngroup_44             : 8;  /**< [359:352] Available Ngroup Of 45th Ngroup */
        uint64_t ngroup_45             : 8;  /**< [367:360] Available Ngroup Of 46th Ngroup */
        uint64_t ngroup_46             : 8;  /**< [375:368] Available Ngroup Of 47th Ngroup */
        uint64_t ngroup_47             : 8;  /**< [383:376] Available Ngroup Of 48th Ngroup */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t ngroup_55             : 8;  /**< [447:440] Available Ngroup Of 56th Ngroup */
        uint64_t ngroup_54             : 8;  /**< [439:432] Available Ngroup Of 55th Ngroup */
        uint64_t ngroup_53             : 8;  /**< [431:424] Available Ngroup Of 54th Ngroup */
        uint64_t ngroup_52             : 8;  /**< [423:416] Available Ngroup Of 53rd Ngroup */
        uint64_t ngroup_51             : 8;  /**< [415:408] Available Ngroup Of 52nd Ngroup */
        uint64_t ngroup_50             : 8;  /**< [407:400] Available Ngroup Of 51st Ngroup */
        uint64_t ngroup_49             : 8;  /**< [399:392] Available Ngroup Of 50th Ngroup */
        uint64_t ngroup_48             : 8;  /**< [391:384] Available Ngroup Of 49th Ngroup */
#else /* Word 6 - Little Endian */
        uint64_t ngroup_48             : 8;  /**< [391:384] Available Ngroup Of 49th Ngroup */
        uint64_t ngroup_49             : 8;  /**< [399:392] Available Ngroup Of 50th Ngroup */
        uint64_t ngroup_50             : 8;  /**< [407:400] Available Ngroup Of 51st Ngroup */
        uint64_t ngroup_51             : 8;  /**< [415:408] Available Ngroup Of 52nd Ngroup */
        uint64_t ngroup_52             : 8;  /**< [423:416] Available Ngroup Of 53rd Ngroup */
        uint64_t ngroup_53             : 8;  /**< [431:424] Available Ngroup Of 54th Ngroup */
        uint64_t ngroup_54             : 8;  /**< [439:432] Available Ngroup Of 55th Ngroup */
        uint64_t ngroup_55             : 8;  /**< [447:440] Available Ngroup Of 56th Ngroup */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t ngroup_63             : 8;  /**< [511:504] Available Ngroup Of 64th Ngroup */
        uint64_t ngroup_62             : 8;  /**< [503:496] Available Ngroup Of 63rd Ngroup */
        uint64_t ngroup_61             : 8;  /**< [495:488] Available Ngroup Of 62nd Ngroup */
        uint64_t ngroup_60             : 8;  /**< [487:480] Available Ngroup Of 61st Ngroup */
        uint64_t ngroup_59             : 8;  /**< [479:472] Available Ngroup Of 60th Ngroup */
        uint64_t ngroup_58             : 8;  /**< [471:464] Available Ngroup Of 59th Ngroup */
        uint64_t ngroup_57             : 8;  /**< [463:456] Available Ngroup Of 58th Ngroup */
        uint64_t ngroup_56             : 8;  /**< [455:448] Available Ngroup Of 57th Ngroup */
#else /* Word 7 - Little Endian */
        uint64_t ngroup_56             : 8;  /**< [455:448] Available Ngroup Of 57th Ngroup */
        uint64_t ngroup_57             : 8;  /**< [463:456] Available Ngroup Of 58th Ngroup */
        uint64_t ngroup_58             : 8;  /**< [471:464] Available Ngroup Of 59th Ngroup */
        uint64_t ngroup_59             : 8;  /**< [479:472] Available Ngroup Of 60th Ngroup */
        uint64_t ngroup_60             : 8;  /**< [487:480] Available Ngroup Of 61st Ngroup */
        uint64_t ngroup_61             : 8;  /**< [495:488] Available Ngroup Of 62nd Ngroup */
        uint64_t ngroup_62             : 8;  /**< [503:496] Available Ngroup Of 63rd Ngroup */
        uint64_t ngroup_63             : 8;  /**< [511:504] Available Ngroup Of 64th Ngroup */
#endif /* Word 7 - End */
    } s;
    /* struct cavm_prach_jd_ngroup_s_s cn; */
};

/**
 * Structure prach_jd_nshift_bar2_s
 *
 * PRACH Nshift_bar_2 Structure
 */
union cavm_prach_jd_nshift_bar2_s
{
    uint64_t u[4];
    struct cavm_prach_jd_nshift_bar2_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar2_15        : 4;  /**< [ 63: 60] Available Nshift_bar2 Of 16th Nshift_bar2 */
        uint64_t nshift_bar2_14        : 4;  /**< [ 59: 56] Available Nshift_bar2 Of 15th Nshift_bar2 */
        uint64_t nshift_bar2_13        : 4;  /**< [ 55: 52] Available Nshift_bar2 Of 14th Nshift_bar2 */
        uint64_t nshift_bar2_12        : 4;  /**< [ 51: 48] Available Nshift_bar2 Of 13rd Nshift_bar2 */
        uint64_t nshift_bar2_11        : 4;  /**< [ 47: 44] Available Nshift_bar2 Of 12nd Nshift_bar2 */
        uint64_t nshift_bar2_10        : 4;  /**< [ 43: 40] Available Nshift_bar2 Of 11st Nshift_bar2 */
        uint64_t nshift_bar2_9         : 4;  /**< [ 39: 36] Available Nshift_bar2 Of 10th Nshift_bar2 */
        uint64_t nshift_bar2_8         : 4;  /**< [ 35: 32] Available Nshift_bar2 Of 9th Nshift_bar2 */
        uint64_t nshift_bar2_7         : 4;  /**< [ 31: 28] Available Nshift_bar2 Of 8th Nshift_bar2 */
        uint64_t nshift_bar2_6         : 4;  /**< [ 27: 24] Available Nshift_bar2 Of 7th Nshift_bar2 */
        uint64_t nshift_bar2_5         : 4;  /**< [ 23: 20] Available Nshift_bar2 Of 6th Nshift_bar2 */
        uint64_t nshift_bar2_4         : 4;  /**< [ 19: 16] Available Nshift_bar2 Of 5th Nshift_bar2 */
        uint64_t nshift_bar2_3         : 4;  /**< [ 15: 12] Available Nshift_bar2 Of 4th Nshift_bar2 */
        uint64_t nshift_bar2_2         : 4;  /**< [ 11:  8] Available Nshift_bar2 Of 3rd Nshift_bar2 */
        uint64_t nshift_bar2_1         : 4;  /**< [  7:  4] Available Nshift_bar2 Of 2nd Nshift_bar2 */
        uint64_t nshift_bar2_0         : 4;  /**< [  3:  0] Available Nshift_bar2 Of start Nshift */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar2_0         : 4;  /**< [  3:  0] Available Nshift_bar2 Of start Nshift */
        uint64_t nshift_bar2_1         : 4;  /**< [  7:  4] Available Nshift_bar2 Of 2nd Nshift_bar2 */
        uint64_t nshift_bar2_2         : 4;  /**< [ 11:  8] Available Nshift_bar2 Of 3rd Nshift_bar2 */
        uint64_t nshift_bar2_3         : 4;  /**< [ 15: 12] Available Nshift_bar2 Of 4th Nshift_bar2 */
        uint64_t nshift_bar2_4         : 4;  /**< [ 19: 16] Available Nshift_bar2 Of 5th Nshift_bar2 */
        uint64_t nshift_bar2_5         : 4;  /**< [ 23: 20] Available Nshift_bar2 Of 6th Nshift_bar2 */
        uint64_t nshift_bar2_6         : 4;  /**< [ 27: 24] Available Nshift_bar2 Of 7th Nshift_bar2 */
        uint64_t nshift_bar2_7         : 4;  /**< [ 31: 28] Available Nshift_bar2 Of 8th Nshift_bar2 */
        uint64_t nshift_bar2_8         : 4;  /**< [ 35: 32] Available Nshift_bar2 Of 9th Nshift_bar2 */
        uint64_t nshift_bar2_9         : 4;  /**< [ 39: 36] Available Nshift_bar2 Of 10th Nshift_bar2 */
        uint64_t nshift_bar2_10        : 4;  /**< [ 43: 40] Available Nshift_bar2 Of 11st Nshift_bar2 */
        uint64_t nshift_bar2_11        : 4;  /**< [ 47: 44] Available Nshift_bar2 Of 12nd Nshift_bar2 */
        uint64_t nshift_bar2_12        : 4;  /**< [ 51: 48] Available Nshift_bar2 Of 13rd Nshift_bar2 */
        uint64_t nshift_bar2_13        : 4;  /**< [ 55: 52] Available Nshift_bar2 Of 14th Nshift_bar2 */
        uint64_t nshift_bar2_14        : 4;  /**< [ 59: 56] Available Nshift_bar2 Of 15th Nshift_bar2 */
        uint64_t nshift_bar2_15        : 4;  /**< [ 63: 60] Available Nshift_bar2 Of 16th Nshift_bar2 */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t nshift_bar2_31        : 4;  /**< [127:124] Available Nshift_bar2 Of 32nd Nshift_bar2 */
        uint64_t nshift_bar2_30        : 4;  /**< [123:120] Available Nshift_bar2 Of 31st Nshift_bar2 */
        uint64_t nshift_bar2_29        : 4;  /**< [119:116] Available Nshift_bar2 Of 30th Nshift_bar2 */
        uint64_t nshift_bar2_28        : 4;  /**< [115:112] Available Nshift_bar2 Of 29th Nshift_bar2 */
        uint64_t nshift_bar2_27        : 4;  /**< [111:108] Available Nshift_bar2 Of 28th Nshift_bar2 */
        uint64_t nshift_bar2_26        : 4;  /**< [107:104] Available Nshift_bar2 Of 27th Nshift_bar2 */
        uint64_t nshift_bar2_25        : 4;  /**< [103:100] Available Nshift_bar2 Of 26th Nshift_bar2 */
        uint64_t nshift_bar2_24        : 4;  /**< [ 99: 96] Available Nshift_bar2 Of 25th Nshift_bar2 */
        uint64_t nshift_bar2_23        : 4;  /**< [ 95: 92] Available Nshift_bar2 Of 24th Nshift_bar2 */
        uint64_t nshift_bar2_22        : 4;  /**< [ 91: 88] Available Nshift_bar2 Of 23rd Nshift_bar2 */
        uint64_t nshift_bar2_21        : 4;  /**< [ 87: 84] Available Nshift_bar2 Of 22nd Nshift_bar2 */
        uint64_t nshift_bar2_20        : 4;  /**< [ 83: 80] Available Nshift_bar2 Of 21st Nshift_bar2 */
        uint64_t nshift_bar2_19        : 4;  /**< [ 79: 76] Available Nshift_bar2 Of 20th Nshift_bar2 */
        uint64_t nshift_bar2_18        : 4;  /**< [ 75: 72] Available Nshift_bar2 Of 19th Nshift_bar2 */
        uint64_t nshift_bar2_17        : 4;  /**< [ 71: 68] Available Nshift_bar2 Of 18th Nshift_bar2 */
        uint64_t nshift_bar2_16        : 4;  /**< [ 67: 64] Available Nshift_bar2 Of 17th Nshift_bar2 */
#else /* Word 1 - Little Endian */
        uint64_t nshift_bar2_16        : 4;  /**< [ 67: 64] Available Nshift_bar2 Of 17th Nshift_bar2 */
        uint64_t nshift_bar2_17        : 4;  /**< [ 71: 68] Available Nshift_bar2 Of 18th Nshift_bar2 */
        uint64_t nshift_bar2_18        : 4;  /**< [ 75: 72] Available Nshift_bar2 Of 19th Nshift_bar2 */
        uint64_t nshift_bar2_19        : 4;  /**< [ 79: 76] Available Nshift_bar2 Of 20th Nshift_bar2 */
        uint64_t nshift_bar2_20        : 4;  /**< [ 83: 80] Available Nshift_bar2 Of 21st Nshift_bar2 */
        uint64_t nshift_bar2_21        : 4;  /**< [ 87: 84] Available Nshift_bar2 Of 22nd Nshift_bar2 */
        uint64_t nshift_bar2_22        : 4;  /**< [ 91: 88] Available Nshift_bar2 Of 23rd Nshift_bar2 */
        uint64_t nshift_bar2_23        : 4;  /**< [ 95: 92] Available Nshift_bar2 Of 24th Nshift_bar2 */
        uint64_t nshift_bar2_24        : 4;  /**< [ 99: 96] Available Nshift_bar2 Of 25th Nshift_bar2 */
        uint64_t nshift_bar2_25        : 4;  /**< [103:100] Available Nshift_bar2 Of 26th Nshift_bar2 */
        uint64_t nshift_bar2_26        : 4;  /**< [107:104] Available Nshift_bar2 Of 27th Nshift_bar2 */
        uint64_t nshift_bar2_27        : 4;  /**< [111:108] Available Nshift_bar2 Of 28th Nshift_bar2 */
        uint64_t nshift_bar2_28        : 4;  /**< [115:112] Available Nshift_bar2 Of 29th Nshift_bar2 */
        uint64_t nshift_bar2_29        : 4;  /**< [119:116] Available Nshift_bar2 Of 30th Nshift_bar2 */
        uint64_t nshift_bar2_30        : 4;  /**< [123:120] Available Nshift_bar2 Of 31st Nshift_bar2 */
        uint64_t nshift_bar2_31        : 4;  /**< [127:124] Available Nshift_bar2 Of 32nd Nshift_bar2 */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t nshift_bar2_47        : 4;  /**< [191:188] Available Nshift_bar2 Of 48th Nshift_bar2 */
        uint64_t nshift_bar2_46        : 4;  /**< [187:184] Available Nshift_bar2 Of 47th Nshift_bar2 */
        uint64_t nshift_bar2_45        : 4;  /**< [183:180] Available Nshift_bar2 Of 46th Nshift_bar2 */
        uint64_t nshift_bar2_44        : 4;  /**< [179:176] Available Nshift_bar2 Of 45th Nshift_bar2 */
        uint64_t nshift_bar2_43        : 4;  /**< [175:172] Available Nshift_bar2 Of 44th Nshift_bar2 */
        uint64_t nshift_bar2_42        : 4;  /**< [171:168] Available Nshift_bar2 Of 43rd Nshift_bar2 */
        uint64_t nshift_bar2_41        : 4;  /**< [167:164] Available Nshift_bar2 Of 42nd Nshift_bar2 */
        uint64_t nshift_bar2_40        : 4;  /**< [163:160] Available Nshift_bar2 Of 41st Nshift_bar2 */
        uint64_t nshift_bar2_39        : 4;  /**< [159:156] Available Nshift_bar2 Of 40th Nshift_bar2 */
        uint64_t nshift_bar2_38        : 4;  /**< [155:152] Available Nshift_bar2 Of 39th Nshift_bar2 */
        uint64_t nshift_bar2_37        : 4;  /**< [151:148] Available Nshift_bar2 Of 38th Nshift_bar2 */
        uint64_t nshift_bar2_36        : 4;  /**< [147:144] Available Nshift_bar2 Of 37th Nshift_bar2 */
        uint64_t nshift_bar2_35        : 4;  /**< [143:140] Available Nshift_bar2 Of 36th Nshift_bar2 */
        uint64_t nshift_bar2_34        : 4;  /**< [139:136] Available Nshift_bar2 Of 35th Nshift_bar2 */
        uint64_t nshift_bar2_33        : 4;  /**< [135:132] Available Nshift_bar2 Of 34th Nshift_bar2 */
        uint64_t nshift_bar2_32        : 4;  /**< [131:128] Available Nshift_bar2 Of 33rd Nshift_bar2 */
#else /* Word 2 - Little Endian */
        uint64_t nshift_bar2_32        : 4;  /**< [131:128] Available Nshift_bar2 Of 33rd Nshift_bar2 */
        uint64_t nshift_bar2_33        : 4;  /**< [135:132] Available Nshift_bar2 Of 34th Nshift_bar2 */
        uint64_t nshift_bar2_34        : 4;  /**< [139:136] Available Nshift_bar2 Of 35th Nshift_bar2 */
        uint64_t nshift_bar2_35        : 4;  /**< [143:140] Available Nshift_bar2 Of 36th Nshift_bar2 */
        uint64_t nshift_bar2_36        : 4;  /**< [147:144] Available Nshift_bar2 Of 37th Nshift_bar2 */
        uint64_t nshift_bar2_37        : 4;  /**< [151:148] Available Nshift_bar2 Of 38th Nshift_bar2 */
        uint64_t nshift_bar2_38        : 4;  /**< [155:152] Available Nshift_bar2 Of 39th Nshift_bar2 */
        uint64_t nshift_bar2_39        : 4;  /**< [159:156] Available Nshift_bar2 Of 40th Nshift_bar2 */
        uint64_t nshift_bar2_40        : 4;  /**< [163:160] Available Nshift_bar2 Of 41st Nshift_bar2 */
        uint64_t nshift_bar2_41        : 4;  /**< [167:164] Available Nshift_bar2 Of 42nd Nshift_bar2 */
        uint64_t nshift_bar2_42        : 4;  /**< [171:168] Available Nshift_bar2 Of 43rd Nshift_bar2 */
        uint64_t nshift_bar2_43        : 4;  /**< [175:172] Available Nshift_bar2 Of 44th Nshift_bar2 */
        uint64_t nshift_bar2_44        : 4;  /**< [179:176] Available Nshift_bar2 Of 45th Nshift_bar2 */
        uint64_t nshift_bar2_45        : 4;  /**< [183:180] Available Nshift_bar2 Of 46th Nshift_bar2 */
        uint64_t nshift_bar2_46        : 4;  /**< [187:184] Available Nshift_bar2 Of 47th Nshift_bar2 */
        uint64_t nshift_bar2_47        : 4;  /**< [191:188] Available Nshift_bar2 Of 48th Nshift_bar2 */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t nshift_bar2_63        : 4;  /**< [255:252] Available Nshift_bar2 Of 64th Nshift_bar2 */
        uint64_t nshift_bar2_62        : 4;  /**< [251:248] Available Nshift_bar2 Of 63rd Nshift_bar2 */
        uint64_t nshift_bar2_61        : 4;  /**< [247:244] Available Nshift_bar2 Of 62nd Nshift_bar2 */
        uint64_t nshift_bar2_60        : 4;  /**< [243:240] Available Nshift_bar2 Of 61st Nshift_bar2 */
        uint64_t nshift_bar2_59        : 4;  /**< [239:236] Available Nshift_bar2 Of 60th Nshift_bar2 */
        uint64_t nshift_bar2_58        : 4;  /**< [235:232] Available Nshift_bar2 Of 59th Nshift_bar2 */
        uint64_t nshift_bar2_57        : 4;  /**< [231:228] Available Nshift_bar2 Of 58th Nshift_bar2 */
        uint64_t nshift_bar2_56        : 4;  /**< [227:224] Available Nshift_bar2 Of 57th Nshift_bar2 */
        uint64_t nshift_bar2_55        : 4;  /**< [223:220] Available Nshift_bar2 Of 56th Nshift_bar2 */
        uint64_t nshift_bar2_54        : 4;  /**< [219:216] Available Nshift_bar2 Of 55th Nshift_bar2 */
        uint64_t nshift_bar2_53        : 4;  /**< [215:212] Available Nshift_bar2 Of 54th Nshift_bar2 */
        uint64_t nshift_bar2_52        : 4;  /**< [211:208] Available Nshift_bar2 Of 53rd Nshift_bar2 */
        uint64_t nshift_bar2_51        : 4;  /**< [207:204] Available Nshift_bar2 Of 52nd Nshift_bar2 */
        uint64_t nshift_bar2_50        : 4;  /**< [203:200] Available Nshift_bar2 Of 51st Nshift_bar2 */
        uint64_t nshift_bar2_49        : 4;  /**< [199:196] Available Nshift_bar2 Of 50th Nshift_bar2 */
        uint64_t nshift_bar2_48        : 4;  /**< [195:192] Available Nshift_bar2 Of 49th Nshift_bar2 */
#else /* Word 3 - Little Endian */
        uint64_t nshift_bar2_48        : 4;  /**< [195:192] Available Nshift_bar2 Of 49th Nshift_bar2 */
        uint64_t nshift_bar2_49        : 4;  /**< [199:196] Available Nshift_bar2 Of 50th Nshift_bar2 */
        uint64_t nshift_bar2_50        : 4;  /**< [203:200] Available Nshift_bar2 Of 51st Nshift_bar2 */
        uint64_t nshift_bar2_51        : 4;  /**< [207:204] Available Nshift_bar2 Of 52nd Nshift_bar2 */
        uint64_t nshift_bar2_52        : 4;  /**< [211:208] Available Nshift_bar2 Of 53rd Nshift_bar2 */
        uint64_t nshift_bar2_53        : 4;  /**< [215:212] Available Nshift_bar2 Of 54th Nshift_bar2 */
        uint64_t nshift_bar2_54        : 4;  /**< [219:216] Available Nshift_bar2 Of 55th Nshift_bar2 */
        uint64_t nshift_bar2_55        : 4;  /**< [223:220] Available Nshift_bar2 Of 56th Nshift_bar2 */
        uint64_t nshift_bar2_56        : 4;  /**< [227:224] Available Nshift_bar2 Of 57th Nshift_bar2 */
        uint64_t nshift_bar2_57        : 4;  /**< [231:228] Available Nshift_bar2 Of 58th Nshift_bar2 */
        uint64_t nshift_bar2_58        : 4;  /**< [235:232] Available Nshift_bar2 Of 59th Nshift_bar2 */
        uint64_t nshift_bar2_59        : 4;  /**< [239:236] Available Nshift_bar2 Of 60th Nshift_bar2 */
        uint64_t nshift_bar2_60        : 4;  /**< [243:240] Available Nshift_bar2 Of 61st Nshift_bar2 */
        uint64_t nshift_bar2_61        : 4;  /**< [247:244] Available Nshift_bar2 Of 62nd Nshift_bar2 */
        uint64_t nshift_bar2_62        : 4;  /**< [251:248] Available Nshift_bar2 Of 63rd Nshift_bar2 */
        uint64_t nshift_bar2_63        : 4;  /**< [255:252] Available Nshift_bar2 Of 64th Nshift_bar2 */
#endif /* Word 3 - End */
    } s;
    /* struct cavm_prach_jd_nshift_bar2_s_s cn; */
};

/**
 * Structure prach_jd_nshift_bar3_s
 *
 * PRACH Nshift_bar_3 Structure
 */
union cavm_prach_jd_nshift_bar3_s
{
    uint64_t u[4];
    struct cavm_prach_jd_nshift_bar3_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar3_15        : 4;  /**< [ 63: 60] Available Nshift_bar3 Of 16th Nshift_bar3 */
        uint64_t nshift_bar3_14        : 4;  /**< [ 59: 56] Available Nshift_bar3 Of 15th Nshift_bar3 */
        uint64_t nshift_bar3_13        : 4;  /**< [ 55: 52] Available Nshift_bar3 Of 14th Nshift_bar3 */
        uint64_t nshift_bar3_12        : 4;  /**< [ 51: 48] Available Nshift_bar3 Of 13rd Nshift_bar3 */
        uint64_t nshift_bar3_11        : 4;  /**< [ 47: 44] Available Nshift_bar3 Of 12nd Nshift_bar3 */
        uint64_t nshift_bar3_10        : 4;  /**< [ 43: 40] Available Nshift_bar3 Of 11st Nshift_bar3 */
        uint64_t nshift_bar3_9         : 4;  /**< [ 39: 36] Available Nshift_bar3 Of 10th Nshift_bar3 */
        uint64_t nshift_bar3_8         : 4;  /**< [ 35: 32] Available Nshift_bar3 Of 9th Nshift_bar3 */
        uint64_t nshift_bar3_7         : 4;  /**< [ 31: 28] Available Nshift_bar3 Of 8th Nshift_bar3 */
        uint64_t nshift_bar3_6         : 4;  /**< [ 27: 24] Available Nshift_bar3 Of 7th Nshift_bar3 */
        uint64_t nshift_bar3_5         : 4;  /**< [ 23: 20] Available Nshift_bar3 Of 6th Nshift_bar3 */
        uint64_t nshift_bar3_4         : 4;  /**< [ 19: 16] Available Nshift_bar3 Of 5th Nshift_bar3 */
        uint64_t nshift_bar3_3         : 4;  /**< [ 15: 12] Available Nshift_bar3 Of 4th Nshift_bar3 */
        uint64_t nshift_bar3_2         : 4;  /**< [ 11:  8] Available Nshift_bar3 Of 3rd Nshift_bar3 */
        uint64_t nshift_bar3_1         : 4;  /**< [  7:  4] Available Nshift_bar3 Of 2nd Nshift_bar3 */
        uint64_t nshift_bar3_0         : 4;  /**< [  3:  0] Available Nshift_bar3 Of start Nshift */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar3_0         : 4;  /**< [  3:  0] Available Nshift_bar3 Of start Nshift */
        uint64_t nshift_bar3_1         : 4;  /**< [  7:  4] Available Nshift_bar3 Of 2nd Nshift_bar3 */
        uint64_t nshift_bar3_2         : 4;  /**< [ 11:  8] Available Nshift_bar3 Of 3rd Nshift_bar3 */
        uint64_t nshift_bar3_3         : 4;  /**< [ 15: 12] Available Nshift_bar3 Of 4th Nshift_bar3 */
        uint64_t nshift_bar3_4         : 4;  /**< [ 19: 16] Available Nshift_bar3 Of 5th Nshift_bar3 */
        uint64_t nshift_bar3_5         : 4;  /**< [ 23: 20] Available Nshift_bar3 Of 6th Nshift_bar3 */
        uint64_t nshift_bar3_6         : 4;  /**< [ 27: 24] Available Nshift_bar3 Of 7th Nshift_bar3 */
        uint64_t nshift_bar3_7         : 4;  /**< [ 31: 28] Available Nshift_bar3 Of 8th Nshift_bar3 */
        uint64_t nshift_bar3_8         : 4;  /**< [ 35: 32] Available Nshift_bar3 Of 9th Nshift_bar3 */
        uint64_t nshift_bar3_9         : 4;  /**< [ 39: 36] Available Nshift_bar3 Of 10th Nshift_bar3 */
        uint64_t nshift_bar3_10        : 4;  /**< [ 43: 40] Available Nshift_bar3 Of 11st Nshift_bar3 */
        uint64_t nshift_bar3_11        : 4;  /**< [ 47: 44] Available Nshift_bar3 Of 12nd Nshift_bar3 */
        uint64_t nshift_bar3_12        : 4;  /**< [ 51: 48] Available Nshift_bar3 Of 13rd Nshift_bar3 */
        uint64_t nshift_bar3_13        : 4;  /**< [ 55: 52] Available Nshift_bar3 Of 14th Nshift_bar3 */
        uint64_t nshift_bar3_14        : 4;  /**< [ 59: 56] Available Nshift_bar3 Of 15th Nshift_bar3 */
        uint64_t nshift_bar3_15        : 4;  /**< [ 63: 60] Available Nshift_bar3 Of 16th Nshift_bar3 */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t nshift_bar3_31        : 4;  /**< [127:124] Available Nshift_bar3 Of 32nd Nshift_bar3 */
        uint64_t nshift_bar3_30        : 4;  /**< [123:120] Available Nshift_bar3 Of 31st Nshift_bar3 */
        uint64_t nshift_bar3_29        : 4;  /**< [119:116] Available Nshift_bar3 Of 30th Nshift_bar3 */
        uint64_t nshift_bar3_28        : 4;  /**< [115:112] Available Nshift_bar3 Of 29th Nshift_bar3 */
        uint64_t nshift_bar3_27        : 4;  /**< [111:108] Available Nshift_bar3 Of 28th Nshift_bar3 */
        uint64_t nshift_bar3_26        : 4;  /**< [107:104] Available Nshift_bar3 Of 27th Nshift_bar3 */
        uint64_t nshift_bar3_25        : 4;  /**< [103:100] Available Nshift_bar3 Of 26th Nshift_bar3 */
        uint64_t nshift_bar3_24        : 4;  /**< [ 99: 96] Available Nshift_bar3 Of 25th Nshift_bar3 */
        uint64_t nshift_bar3_23        : 4;  /**< [ 95: 92] Available Nshift_bar3 Of 24th Nshift_bar3 */
        uint64_t nshift_bar3_22        : 4;  /**< [ 91: 88] Available Nshift_bar3 Of 23rd Nshift_bar3 */
        uint64_t nshift_bar3_21        : 4;  /**< [ 87: 84] Available Nshift_bar3 Of 22nd Nshift_bar3 */
        uint64_t nshift_bar3_20        : 4;  /**< [ 83: 80] Available Nshift_bar3 Of 21st Nshift_bar3 */
        uint64_t nshift_bar3_19        : 4;  /**< [ 79: 76] Available Nshift_bar3 Of 20th Nshift_bar3 */
        uint64_t nshift_bar3_18        : 4;  /**< [ 75: 72] Available Nshift_bar3 Of 19th Nshift_bar3 */
        uint64_t nshift_bar3_17        : 4;  /**< [ 71: 68] Available Nshift_bar3 Of 18th Nshift_bar3 */
        uint64_t nshift_bar3_16        : 4;  /**< [ 67: 64] Available Nshift_bar3 Of 17th Nshift_bar3 */
#else /* Word 1 - Little Endian */
        uint64_t nshift_bar3_16        : 4;  /**< [ 67: 64] Available Nshift_bar3 Of 17th Nshift_bar3 */
        uint64_t nshift_bar3_17        : 4;  /**< [ 71: 68] Available Nshift_bar3 Of 18th Nshift_bar3 */
        uint64_t nshift_bar3_18        : 4;  /**< [ 75: 72] Available Nshift_bar3 Of 19th Nshift_bar3 */
        uint64_t nshift_bar3_19        : 4;  /**< [ 79: 76] Available Nshift_bar3 Of 20th Nshift_bar3 */
        uint64_t nshift_bar3_20        : 4;  /**< [ 83: 80] Available Nshift_bar3 Of 21st Nshift_bar3 */
        uint64_t nshift_bar3_21        : 4;  /**< [ 87: 84] Available Nshift_bar3 Of 22nd Nshift_bar3 */
        uint64_t nshift_bar3_22        : 4;  /**< [ 91: 88] Available Nshift_bar3 Of 23rd Nshift_bar3 */
        uint64_t nshift_bar3_23        : 4;  /**< [ 95: 92] Available Nshift_bar3 Of 24th Nshift_bar3 */
        uint64_t nshift_bar3_24        : 4;  /**< [ 99: 96] Available Nshift_bar3 Of 25th Nshift_bar3 */
        uint64_t nshift_bar3_25        : 4;  /**< [103:100] Available Nshift_bar3 Of 26th Nshift_bar3 */
        uint64_t nshift_bar3_26        : 4;  /**< [107:104] Available Nshift_bar3 Of 27th Nshift_bar3 */
        uint64_t nshift_bar3_27        : 4;  /**< [111:108] Available Nshift_bar3 Of 28th Nshift_bar3 */
        uint64_t nshift_bar3_28        : 4;  /**< [115:112] Available Nshift_bar3 Of 29th Nshift_bar3 */
        uint64_t nshift_bar3_29        : 4;  /**< [119:116] Available Nshift_bar3 Of 30th Nshift_bar3 */
        uint64_t nshift_bar3_30        : 4;  /**< [123:120] Available Nshift_bar3 Of 31st Nshift_bar3 */
        uint64_t nshift_bar3_31        : 4;  /**< [127:124] Available Nshift_bar3 Of 32nd Nshift_bar3 */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t nshift_bar3_47        : 4;  /**< [191:188] Available Nshift_bar3 Of 48th Nshift_bar3 */
        uint64_t nshift_bar3_46        : 4;  /**< [187:184] Available Nshift_bar3 Of 47th Nshift_bar3 */
        uint64_t nshift_bar3_45        : 4;  /**< [183:180] Available Nshift_bar3 Of 46th Nshift_bar3 */
        uint64_t nshift_bar3_44        : 4;  /**< [179:176] Available Nshift_bar3 Of 45th Nshift_bar3 */
        uint64_t nshift_bar3_43        : 4;  /**< [175:172] Available Nshift_bar3 Of 44th Nshift_bar3 */
        uint64_t nshift_bar3_42        : 4;  /**< [171:168] Available Nshift_bar3 Of 43rd Nshift_bar3 */
        uint64_t nshift_bar3_41        : 4;  /**< [167:164] Available Nshift_bar3 Of 42nd Nshift_bar3 */
        uint64_t nshift_bar3_40        : 4;  /**< [163:160] Available Nshift_bar3 Of 41st Nshift_bar3 */
        uint64_t nshift_bar3_39        : 4;  /**< [159:156] Available Nshift_bar3 Of 40th Nshift_bar3 */
        uint64_t nshift_bar3_38        : 4;  /**< [155:152] Available Nshift_bar3 Of 39th Nshift_bar3 */
        uint64_t nshift_bar3_37        : 4;  /**< [151:148] Available Nshift_bar3 Of 38th Nshift_bar3 */
        uint64_t nshift_bar3_36        : 4;  /**< [147:144] Available Nshift_bar3 Of 37th Nshift_bar3 */
        uint64_t nshift_bar3_35        : 4;  /**< [143:140] Available Nshift_bar3 Of 36th Nshift_bar3 */
        uint64_t nshift_bar3_34        : 4;  /**< [139:136] Available Nshift_bar3 Of 35th Nshift_bar3 */
        uint64_t nshift_bar3_33        : 4;  /**< [135:132] Available Nshift_bar3 Of 34th Nshift_bar3 */
        uint64_t nshift_bar3_32        : 4;  /**< [131:128] Available Nshift_bar3 Of 33rd Nshift_bar3 */
#else /* Word 2 - Little Endian */
        uint64_t nshift_bar3_32        : 4;  /**< [131:128] Available Nshift_bar3 Of 33rd Nshift_bar3 */
        uint64_t nshift_bar3_33        : 4;  /**< [135:132] Available Nshift_bar3 Of 34th Nshift_bar3 */
        uint64_t nshift_bar3_34        : 4;  /**< [139:136] Available Nshift_bar3 Of 35th Nshift_bar3 */
        uint64_t nshift_bar3_35        : 4;  /**< [143:140] Available Nshift_bar3 Of 36th Nshift_bar3 */
        uint64_t nshift_bar3_36        : 4;  /**< [147:144] Available Nshift_bar3 Of 37th Nshift_bar3 */
        uint64_t nshift_bar3_37        : 4;  /**< [151:148] Available Nshift_bar3 Of 38th Nshift_bar3 */
        uint64_t nshift_bar3_38        : 4;  /**< [155:152] Available Nshift_bar3 Of 39th Nshift_bar3 */
        uint64_t nshift_bar3_39        : 4;  /**< [159:156] Available Nshift_bar3 Of 40th Nshift_bar3 */
        uint64_t nshift_bar3_40        : 4;  /**< [163:160] Available Nshift_bar3 Of 41st Nshift_bar3 */
        uint64_t nshift_bar3_41        : 4;  /**< [167:164] Available Nshift_bar3 Of 42nd Nshift_bar3 */
        uint64_t nshift_bar3_42        : 4;  /**< [171:168] Available Nshift_bar3 Of 43rd Nshift_bar3 */
        uint64_t nshift_bar3_43        : 4;  /**< [175:172] Available Nshift_bar3 Of 44th Nshift_bar3 */
        uint64_t nshift_bar3_44        : 4;  /**< [179:176] Available Nshift_bar3 Of 45th Nshift_bar3 */
        uint64_t nshift_bar3_45        : 4;  /**< [183:180] Available Nshift_bar3 Of 46th Nshift_bar3 */
        uint64_t nshift_bar3_46        : 4;  /**< [187:184] Available Nshift_bar3 Of 47th Nshift_bar3 */
        uint64_t nshift_bar3_47        : 4;  /**< [191:188] Available Nshift_bar3 Of 48th Nshift_bar3 */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t nshift_bar3_63        : 4;  /**< [255:252] Available Nshift_bar3 Of 64th Nshift_bar3 */
        uint64_t nshift_bar3_62        : 4;  /**< [251:248] Available Nshift_bar3 Of 63rd Nshift_bar3 */
        uint64_t nshift_bar3_61        : 4;  /**< [247:244] Available Nshift_bar3 Of 62nd Nshift_bar3 */
        uint64_t nshift_bar3_60        : 4;  /**< [243:240] Available Nshift_bar3 Of 61st Nshift_bar3 */
        uint64_t nshift_bar3_59        : 4;  /**< [239:236] Available Nshift_bar3 Of 60th Nshift_bar3 */
        uint64_t nshift_bar3_58        : 4;  /**< [235:232] Available Nshift_bar3 Of 59th Nshift_bar3 */
        uint64_t nshift_bar3_57        : 4;  /**< [231:228] Available Nshift_bar3 Of 58th Nshift_bar3 */
        uint64_t nshift_bar3_56        : 4;  /**< [227:224] Available Nshift_bar3 Of 57th Nshift_bar3 */
        uint64_t nshift_bar3_55        : 4;  /**< [223:220] Available Nshift_bar3 Of 56th Nshift_bar3 */
        uint64_t nshift_bar3_54        : 4;  /**< [219:216] Available Nshift_bar3 Of 55th Nshift_bar3 */
        uint64_t nshift_bar3_53        : 4;  /**< [215:212] Available Nshift_bar3 Of 54th Nshift_bar3 */
        uint64_t nshift_bar3_52        : 4;  /**< [211:208] Available Nshift_bar3 Of 53rd Nshift_bar3 */
        uint64_t nshift_bar3_51        : 4;  /**< [207:204] Available Nshift_bar3 Of 52nd Nshift_bar3 */
        uint64_t nshift_bar3_50        : 4;  /**< [203:200] Available Nshift_bar3 Of 51st Nshift_bar3 */
        uint64_t nshift_bar3_49        : 4;  /**< [199:196] Available Nshift_bar3 Of 50th Nshift_bar3 */
        uint64_t nshift_bar3_48        : 4;  /**< [195:192] Available Nshift_bar3 Of 49th Nshift_bar3 */
#else /* Word 3 - Little Endian */
        uint64_t nshift_bar3_48        : 4;  /**< [195:192] Available Nshift_bar3 Of 49th Nshift_bar3 */
        uint64_t nshift_bar3_49        : 4;  /**< [199:196] Available Nshift_bar3 Of 50th Nshift_bar3 */
        uint64_t nshift_bar3_50        : 4;  /**< [203:200] Available Nshift_bar3 Of 51st Nshift_bar3 */
        uint64_t nshift_bar3_51        : 4;  /**< [207:204] Available Nshift_bar3 Of 52nd Nshift_bar3 */
        uint64_t nshift_bar3_52        : 4;  /**< [211:208] Available Nshift_bar3 Of 53rd Nshift_bar3 */
        uint64_t nshift_bar3_53        : 4;  /**< [215:212] Available Nshift_bar3 Of 54th Nshift_bar3 */
        uint64_t nshift_bar3_54        : 4;  /**< [219:216] Available Nshift_bar3 Of 55th Nshift_bar3 */
        uint64_t nshift_bar3_55        : 4;  /**< [223:220] Available Nshift_bar3 Of 56th Nshift_bar3 */
        uint64_t nshift_bar3_56        : 4;  /**< [227:224] Available Nshift_bar3 Of 57th Nshift_bar3 */
        uint64_t nshift_bar3_57        : 4;  /**< [231:228] Available Nshift_bar3 Of 58th Nshift_bar3 */
        uint64_t nshift_bar3_58        : 4;  /**< [235:232] Available Nshift_bar3 Of 59th Nshift_bar3 */
        uint64_t nshift_bar3_59        : 4;  /**< [239:236] Available Nshift_bar3 Of 60th Nshift_bar3 */
        uint64_t nshift_bar3_60        : 4;  /**< [243:240] Available Nshift_bar3 Of 61st Nshift_bar3 */
        uint64_t nshift_bar3_61        : 4;  /**< [247:244] Available Nshift_bar3 Of 62nd Nshift_bar3 */
        uint64_t nshift_bar3_62        : 4;  /**< [251:248] Available Nshift_bar3 Of 63rd Nshift_bar3 */
        uint64_t nshift_bar3_63        : 4;  /**< [255:252] Available Nshift_bar3 Of 64th Nshift_bar3 */
#endif /* Word 3 - End */
    } s;
    /* struct cavm_prach_jd_nshift_bar3_s_s cn; */
};

/**
 * Structure prach_jd_nshift_bar_s
 *
 * PRACH NSHIFT_BAR Structure
 */
union cavm_prach_jd_nshift_bar_s
{
    uint64_t u[8];
    struct cavm_prach_jd_nshift_bar_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar_7          : 8;  /**< [ 63: 56] Available Nshift_bar Of 8th Nshift_bar */
        uint64_t nshift_bar_6          : 8;  /**< [ 55: 48] Available Nshift_bar Of 7th Nshift_bar */
        uint64_t nshift_bar_5          : 8;  /**< [ 47: 40] Available Nshift_bar Of 6th Nshift_bar */
        uint64_t nshift_bar_4          : 8;  /**< [ 39: 32] Available Nshift_bar Of 5th Nshift_bar */
        uint64_t nshift_bar_3          : 8;  /**< [ 31: 24] Available Nshift_bar Of 4th Nshift_bar */
        uint64_t nshift_bar_2          : 8;  /**< [ 23: 16] Available Nshift_bar Of 3rd Nshift_bar */
        uint64_t nshift_bar_1          : 8;  /**< [ 15:  8] Available Nshift_bar Of 2nd Nshift_bar */
        uint64_t nshift_bar_0          : 8;  /**< [  7:  0] Available Nshift_bar Of start Nshift_bar */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar_0          : 8;  /**< [  7:  0] Available Nshift_bar Of start Nshift_bar */
        uint64_t nshift_bar_1          : 8;  /**< [ 15:  8] Available Nshift_bar Of 2nd Nshift_bar */
        uint64_t nshift_bar_2          : 8;  /**< [ 23: 16] Available Nshift_bar Of 3rd Nshift_bar */
        uint64_t nshift_bar_3          : 8;  /**< [ 31: 24] Available Nshift_bar Of 4th Nshift_bar */
        uint64_t nshift_bar_4          : 8;  /**< [ 39: 32] Available Nshift_bar Of 5th Nshift_bar */
        uint64_t nshift_bar_5          : 8;  /**< [ 47: 40] Available Nshift_bar Of 6th Nshift_bar */
        uint64_t nshift_bar_6          : 8;  /**< [ 55: 48] Available Nshift_bar Of 7th Nshift_bar */
        uint64_t nshift_bar_7          : 8;  /**< [ 63: 56] Available Nshift_bar Of 8th Nshift_bar */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t nshift_bar_15         : 8;  /**< [127:120] Available Nshift_bar Of 16th Nshift_bar */
        uint64_t nshift_bar_14         : 8;  /**< [119:112] Available Nshift_bar Of 15th Nshift_bar */
        uint64_t nshift_bar_13         : 8;  /**< [111:104] Available Nshift_bar Of 14th Nshift_bar */
        uint64_t nshift_bar_12         : 8;  /**< [103: 96] Available Nshift_bar Of 13rd Nshift_bar */
        uint64_t nshift_bar_11         : 8;  /**< [ 95: 88] Available Nshift_bar Of 12nd Nshift_bar */
        uint64_t nshift_bar_10         : 8;  /**< [ 87: 80] Available Nshift_bar Of 11st Nshift_bar */
        uint64_t nshift_bar_9          : 8;  /**< [ 79: 72] Available Nshift_bar Of 10th Nshift_bar */
        uint64_t nshift_bar_8          : 8;  /**< [ 71: 64] Available Nshift_bar Of 9th Nshift_bar */
#else /* Word 1 - Little Endian */
        uint64_t nshift_bar_8          : 8;  /**< [ 71: 64] Available Nshift_bar Of 9th Nshift_bar */
        uint64_t nshift_bar_9          : 8;  /**< [ 79: 72] Available Nshift_bar Of 10th Nshift_bar */
        uint64_t nshift_bar_10         : 8;  /**< [ 87: 80] Available Nshift_bar Of 11st Nshift_bar */
        uint64_t nshift_bar_11         : 8;  /**< [ 95: 88] Available Nshift_bar Of 12nd Nshift_bar */
        uint64_t nshift_bar_12         : 8;  /**< [103: 96] Available Nshift_bar Of 13rd Nshift_bar */
        uint64_t nshift_bar_13         : 8;  /**< [111:104] Available Nshift_bar Of 14th Nshift_bar */
        uint64_t nshift_bar_14         : 8;  /**< [119:112] Available Nshift_bar Of 15th Nshift_bar */
        uint64_t nshift_bar_15         : 8;  /**< [127:120] Available Nshift_bar Of 16th Nshift_bar */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t nshift_bar_23         : 8;  /**< [191:184] Available Nshift_bar Of 24th Nshift_bar */
        uint64_t nshift_bar_22         : 8;  /**< [183:176] Available Nshift_bar Of 23rd Nshift_bar */
        uint64_t nshift_bar_21         : 8;  /**< [175:168] Available Nshift_bar Of 22nd Nshift_bar */
        uint64_t nshift_bar_20         : 8;  /**< [167:160] Available Nshift_bar Of 21st Nshift_bar */
        uint64_t nshift_bar_19         : 8;  /**< [159:152] Available Nshift_bar Of 20th Nshift_bar */
        uint64_t nshift_bar_18         : 8;  /**< [151:144] Available Nshift_bar Of 19th Nshift_bar */
        uint64_t nshift_bar_17         : 8;  /**< [143:136] Available Nshift_bar Of 18th Nshift_bar */
        uint64_t nshift_bar_16         : 8;  /**< [135:128] Available Nshift_bar Of 17th Nshift_bar */
#else /* Word 2 - Little Endian */
        uint64_t nshift_bar_16         : 8;  /**< [135:128] Available Nshift_bar Of 17th Nshift_bar */
        uint64_t nshift_bar_17         : 8;  /**< [143:136] Available Nshift_bar Of 18th Nshift_bar */
        uint64_t nshift_bar_18         : 8;  /**< [151:144] Available Nshift_bar Of 19th Nshift_bar */
        uint64_t nshift_bar_19         : 8;  /**< [159:152] Available Nshift_bar Of 20th Nshift_bar */
        uint64_t nshift_bar_20         : 8;  /**< [167:160] Available Nshift_bar Of 21st Nshift_bar */
        uint64_t nshift_bar_21         : 8;  /**< [175:168] Available Nshift_bar Of 22nd Nshift_bar */
        uint64_t nshift_bar_22         : 8;  /**< [183:176] Available Nshift_bar Of 23rd Nshift_bar */
        uint64_t nshift_bar_23         : 8;  /**< [191:184] Available Nshift_bar Of 24th Nshift_bar */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t nshift_bar_31         : 8;  /**< [255:248] Available Nshift_bar Of 32nd Nshift_bar */
        uint64_t nshift_bar_30         : 8;  /**< [247:240] Available Nshift_bar Of 31st Nshift_bar */
        uint64_t nshift_bar_29         : 8;  /**< [239:232] Available Nshift_bar Of 30th Nshift_bar */
        uint64_t nshift_bar_28         : 8;  /**< [231:224] Available Nshift_bar Of 29th Nshift_bar */
        uint64_t nshift_bar_27         : 8;  /**< [223:216] Available Nshift_bar Of 28th Nshift_bar */
        uint64_t nshift_bar_26         : 8;  /**< [215:208] Available Nshift_bar Of 27th Nshift_bar */
        uint64_t nshift_bar_25         : 8;  /**< [207:200] Available Nshift_bar Of 26th Nshift_bar */
        uint64_t nshift_bar_24         : 8;  /**< [199:192] Available Nshift_bar Of 25th Nshift_bar */
#else /* Word 3 - Little Endian */
        uint64_t nshift_bar_24         : 8;  /**< [199:192] Available Nshift_bar Of 25th Nshift_bar */
        uint64_t nshift_bar_25         : 8;  /**< [207:200] Available Nshift_bar Of 26th Nshift_bar */
        uint64_t nshift_bar_26         : 8;  /**< [215:208] Available Nshift_bar Of 27th Nshift_bar */
        uint64_t nshift_bar_27         : 8;  /**< [223:216] Available Nshift_bar Of 28th Nshift_bar */
        uint64_t nshift_bar_28         : 8;  /**< [231:224] Available Nshift_bar Of 29th Nshift_bar */
        uint64_t nshift_bar_29         : 8;  /**< [239:232] Available Nshift_bar Of 30th Nshift_bar */
        uint64_t nshift_bar_30         : 8;  /**< [247:240] Available Nshift_bar Of 31st Nshift_bar */
        uint64_t nshift_bar_31         : 8;  /**< [255:248] Available Nshift_bar Of 32nd Nshift_bar */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t nshift_bar_39         : 8;  /**< [319:312] Available Nshift_bar Of 40th Nshift_bar */
        uint64_t nshift_bar_38         : 8;  /**< [311:304] Available Nshift_bar Of 39th Nshift_bar */
        uint64_t nshift_bar_37         : 8;  /**< [303:296] Available Nshift_bar Of 38th Nshift_bar */
        uint64_t nshift_bar_36         : 8;  /**< [295:288] Available Nshift_bar Of 37th Nshift_bar */
        uint64_t nshift_bar_35         : 8;  /**< [287:280] Available Nshift_bar Of 36th Nshift_bar */
        uint64_t nshift_bar_34         : 8;  /**< [279:272] Available Nshift_bar Of 35th Nshift_bar */
        uint64_t nshift_bar_33         : 8;  /**< [271:264] Available Nshift_bar Of 34th Nshift_bar */
        uint64_t nshift_bar_32         : 8;  /**< [263:256] Available Nshift_bar Of 33rd Nshift_bar */
#else /* Word 4 - Little Endian */
        uint64_t nshift_bar_32         : 8;  /**< [263:256] Available Nshift_bar Of 33rd Nshift_bar */
        uint64_t nshift_bar_33         : 8;  /**< [271:264] Available Nshift_bar Of 34th Nshift_bar */
        uint64_t nshift_bar_34         : 8;  /**< [279:272] Available Nshift_bar Of 35th Nshift_bar */
        uint64_t nshift_bar_35         : 8;  /**< [287:280] Available Nshift_bar Of 36th Nshift_bar */
        uint64_t nshift_bar_36         : 8;  /**< [295:288] Available Nshift_bar Of 37th Nshift_bar */
        uint64_t nshift_bar_37         : 8;  /**< [303:296] Available Nshift_bar Of 38th Nshift_bar */
        uint64_t nshift_bar_38         : 8;  /**< [311:304] Available Nshift_bar Of 39th Nshift_bar */
        uint64_t nshift_bar_39         : 8;  /**< [319:312] Available Nshift_bar Of 40th Nshift_bar */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t nshift_bar_47         : 8;  /**< [383:376] Available Nshift_bar Of 48th Nshift_bar */
        uint64_t nshift_bar_46         : 8;  /**< [375:368] Available Nshift_bar Of 47th Nshift_bar */
        uint64_t nshift_bar_45         : 8;  /**< [367:360] Available Nshift_bar Of 46th Nshift_bar */
        uint64_t nshift_bar_44         : 8;  /**< [359:352] Available Nshift_bar Of 45th Nshift_bar */
        uint64_t nshift_bar_43         : 8;  /**< [351:344] Available Nshift_bar Of 44th Nshift_bar */
        uint64_t nshift_bar_42         : 8;  /**< [343:336] Available Nshift_bar Of 43rd Nshift_bar */
        uint64_t nshift_bar_41         : 8;  /**< [335:328] Available Nshift_bar Of 42nd Nshift_bar */
        uint64_t nshift_bar_40         : 8;  /**< [327:320] Available Nshift_bar Of 41st Nshift_bar */
#else /* Word 5 - Little Endian */
        uint64_t nshift_bar_40         : 8;  /**< [327:320] Available Nshift_bar Of 41st Nshift_bar */
        uint64_t nshift_bar_41         : 8;  /**< [335:328] Available Nshift_bar Of 42nd Nshift_bar */
        uint64_t nshift_bar_42         : 8;  /**< [343:336] Available Nshift_bar Of 43rd Nshift_bar */
        uint64_t nshift_bar_43         : 8;  /**< [351:344] Available Nshift_bar Of 44th Nshift_bar */
        uint64_t nshift_bar_44         : 8;  /**< [359:352] Available Nshift_bar Of 45th Nshift_bar */
        uint64_t nshift_bar_45         : 8;  /**< [367:360] Available Nshift_bar Of 46th Nshift_bar */
        uint64_t nshift_bar_46         : 8;  /**< [375:368] Available Nshift_bar Of 47th Nshift_bar */
        uint64_t nshift_bar_47         : 8;  /**< [383:376] Available Nshift_bar Of 48th Nshift_bar */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t nshift_bar_55         : 8;  /**< [447:440] Available Nshift_bar Of 56th Nshift_bar */
        uint64_t nshift_bar_54         : 8;  /**< [439:432] Available Nshift_bar Of 55th Nshift_bar */
        uint64_t nshift_bar_53         : 8;  /**< [431:424] Available Nshift_bar Of 54th Nshift_bar */
        uint64_t nshift_bar_52         : 8;  /**< [423:416] Available Nshift_bar Of 53rd Nshift_bar */
        uint64_t nshift_bar_51         : 8;  /**< [415:408] Available Nshift_bar Of 52nd Nshift_bar */
        uint64_t nshift_bar_50         : 8;  /**< [407:400] Available Nshift_bar Of 51st Nshift_bar */
        uint64_t nshift_bar_49         : 8;  /**< [399:392] Available Nshift_bar Of 50th Nshift_bar */
        uint64_t nshift_bar_48         : 8;  /**< [391:384] Available Nshift_bar Of 49th Nshift_bar */
#else /* Word 6 - Little Endian */
        uint64_t nshift_bar_48         : 8;  /**< [391:384] Available Nshift_bar Of 49th Nshift_bar */
        uint64_t nshift_bar_49         : 8;  /**< [399:392] Available Nshift_bar Of 50th Nshift_bar */
        uint64_t nshift_bar_50         : 8;  /**< [407:400] Available Nshift_bar Of 51st Nshift_bar */
        uint64_t nshift_bar_51         : 8;  /**< [415:408] Available Nshift_bar Of 52nd Nshift_bar */
        uint64_t nshift_bar_52         : 8;  /**< [423:416] Available Nshift_bar Of 53rd Nshift_bar */
        uint64_t nshift_bar_53         : 8;  /**< [431:424] Available Nshift_bar Of 54th Nshift_bar */
        uint64_t nshift_bar_54         : 8;  /**< [439:432] Available Nshift_bar Of 55th Nshift_bar */
        uint64_t nshift_bar_55         : 8;  /**< [447:440] Available Nshift_bar Of 56th Nshift_bar */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t nshift_bar_63         : 8;  /**< [511:504] Available Nshift_bar Of 64th Nshift_bar */
        uint64_t nshift_bar_62         : 8;  /**< [503:496] Available Nshift_bar Of 63rd Nshift_bar */
        uint64_t nshift_bar_61         : 8;  /**< [495:488] Available Nshift_bar Of 62nd Nshift_bar */
        uint64_t nshift_bar_60         : 8;  /**< [487:480] Available Nshift_bar Of 61st Nshift_bar */
        uint64_t nshift_bar_59         : 8;  /**< [479:472] Available Nshift_bar Of 60th Nshift_bar */
        uint64_t nshift_bar_58         : 8;  /**< [471:464] Available Nshift_bar Of 59th Nshift_bar */
        uint64_t nshift_bar_57         : 8;  /**< [463:456] Available Nshift_bar Of 58th Nshift_bar */
        uint64_t nshift_bar_56         : 8;  /**< [455:448] Available Nshift_bar Of 57th Nshift_bar */
#else /* Word 7 - Little Endian */
        uint64_t nshift_bar_56         : 8;  /**< [455:448] Available Nshift_bar Of 57th Nshift_bar */
        uint64_t nshift_bar_57         : 8;  /**< [463:456] Available Nshift_bar Of 58th Nshift_bar */
        uint64_t nshift_bar_58         : 8;  /**< [471:464] Available Nshift_bar Of 59th Nshift_bar */
        uint64_t nshift_bar_59         : 8;  /**< [479:472] Available Nshift_bar Of 60th Nshift_bar */
        uint64_t nshift_bar_60         : 8;  /**< [487:480] Available Nshift_bar Of 61st Nshift_bar */
        uint64_t nshift_bar_61         : 8;  /**< [495:488] Available Nshift_bar Of 62nd Nshift_bar */
        uint64_t nshift_bar_62         : 8;  /**< [503:496] Available Nshift_bar Of 63rd Nshift_bar */
        uint64_t nshift_bar_63         : 8;  /**< [511:504] Available Nshift_bar Of 64th Nshift_bar */
#endif /* Word 7 - End */
    } s;
    /* struct cavm_prach_jd_nshift_bar_s_s cn; */
};

/**
 * Structure prach_jd_nshift_s
 *
 * PRACH Nshift Structure
 */
union cavm_prach_jd_nshift_s
{
    uint64_t u[8];
    struct cavm_prach_jd_nshift_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_7              : 8;  /**< [ 63: 56] Available Nshift Of 8th Nshift */
        uint64_t nshift_6              : 8;  /**< [ 55: 48] Available Nshift Of 7th Nshift */
        uint64_t nshift_5              : 8;  /**< [ 47: 40] Available Nshift Of 6th Nshift */
        uint64_t nshift_4              : 8;  /**< [ 39: 32] Available Nshift Of 5th Nshift */
        uint64_t nshift_3              : 8;  /**< [ 31: 24] Available Nshift Of 4th Nshift */
        uint64_t nshift_2              : 8;  /**< [ 23: 16] Available Nshift Of 3rd Nshift */
        uint64_t nshift_1              : 8;  /**< [ 15:  8] Available Nshift Of 2nd Nshift */
        uint64_t nshift_0              : 8;  /**< [  7:  0] Available Nshift Of start Nshift */
#else /* Word 0 - Little Endian */
        uint64_t nshift_0              : 8;  /**< [  7:  0] Available Nshift Of start Nshift */
        uint64_t nshift_1              : 8;  /**< [ 15:  8] Available Nshift Of 2nd Nshift */
        uint64_t nshift_2              : 8;  /**< [ 23: 16] Available Nshift Of 3rd Nshift */
        uint64_t nshift_3              : 8;  /**< [ 31: 24] Available Nshift Of 4th Nshift */
        uint64_t nshift_4              : 8;  /**< [ 39: 32] Available Nshift Of 5th Nshift */
        uint64_t nshift_5              : 8;  /**< [ 47: 40] Available Nshift Of 6th Nshift */
        uint64_t nshift_6              : 8;  /**< [ 55: 48] Available Nshift Of 7th Nshift */
        uint64_t nshift_7              : 8;  /**< [ 63: 56] Available Nshift Of 8th Nshift */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t nshift_15             : 8;  /**< [127:120] Available Nshift Of 16th Nshift */
        uint64_t nshift_14             : 8;  /**< [119:112] Available Nshift Of 15th Nshift */
        uint64_t nshift_13             : 8;  /**< [111:104] Available Nshift Of 14th Nshift */
        uint64_t nshift_12             : 8;  /**< [103: 96] Available Nshift Of 13rd Nshift */
        uint64_t nshift_11             : 8;  /**< [ 95: 88] Available Nshift Of 12nd Nshift */
        uint64_t nshift_10             : 8;  /**< [ 87: 80] Available Nshift Of 11st Nshift */
        uint64_t nshift_9              : 8;  /**< [ 79: 72] Available Nshift Of 10th Nshift */
        uint64_t nshift_8              : 8;  /**< [ 71: 64] Available Nshift Of 9th Nshift */
#else /* Word 1 - Little Endian */
        uint64_t nshift_8              : 8;  /**< [ 71: 64] Available Nshift Of 9th Nshift */
        uint64_t nshift_9              : 8;  /**< [ 79: 72] Available Nshift Of 10th Nshift */
        uint64_t nshift_10             : 8;  /**< [ 87: 80] Available Nshift Of 11st Nshift */
        uint64_t nshift_11             : 8;  /**< [ 95: 88] Available Nshift Of 12nd Nshift */
        uint64_t nshift_12             : 8;  /**< [103: 96] Available Nshift Of 13rd Nshift */
        uint64_t nshift_13             : 8;  /**< [111:104] Available Nshift Of 14th Nshift */
        uint64_t nshift_14             : 8;  /**< [119:112] Available Nshift Of 15th Nshift */
        uint64_t nshift_15             : 8;  /**< [127:120] Available Nshift Of 16th Nshift */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t nshift_23             : 8;  /**< [191:184] Available Nshift Of 24th Nshift */
        uint64_t nshift_22             : 8;  /**< [183:176] Available Nshift Of 23rd Nshift */
        uint64_t nshift_21             : 8;  /**< [175:168] Available Nshift Of 22nd Nshift */
        uint64_t nshift_20             : 8;  /**< [167:160] Available Nshift Of 21st Nshift */
        uint64_t nshift_19             : 8;  /**< [159:152] Available Nshift Of 20th Nshift */
        uint64_t nshift_18             : 8;  /**< [151:144] Available Nshift Of 19th Nshift */
        uint64_t nshift_17             : 8;  /**< [143:136] Available Nshift Of 18th Nshift */
        uint64_t nshift_16             : 8;  /**< [135:128] Available Nshift Of 17th Nshift */
#else /* Word 2 - Little Endian */
        uint64_t nshift_16             : 8;  /**< [135:128] Available Nshift Of 17th Nshift */
        uint64_t nshift_17             : 8;  /**< [143:136] Available Nshift Of 18th Nshift */
        uint64_t nshift_18             : 8;  /**< [151:144] Available Nshift Of 19th Nshift */
        uint64_t nshift_19             : 8;  /**< [159:152] Available Nshift Of 20th Nshift */
        uint64_t nshift_20             : 8;  /**< [167:160] Available Nshift Of 21st Nshift */
        uint64_t nshift_21             : 8;  /**< [175:168] Available Nshift Of 22nd Nshift */
        uint64_t nshift_22             : 8;  /**< [183:176] Available Nshift Of 23rd Nshift */
        uint64_t nshift_23             : 8;  /**< [191:184] Available Nshift Of 24th Nshift */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t nshift_31             : 8;  /**< [255:248] Available Nshift Of 32nd Nshift */
        uint64_t nshift_30             : 8;  /**< [247:240] Available Nshift Of 31st Nshift */
        uint64_t nshift_29             : 8;  /**< [239:232] Available Nshift Of 30th Nshift */
        uint64_t nshift_28             : 8;  /**< [231:224] Available Nshift Of 29th Nshift */
        uint64_t nshift_27             : 8;  /**< [223:216] Available Nshift Of 28th Nshift */
        uint64_t nshift_26             : 8;  /**< [215:208] Available Nshift Of 27th Nshift */
        uint64_t nshift_25             : 8;  /**< [207:200] Available Nshift Of 26th Nshift */
        uint64_t nshift_24             : 8;  /**< [199:192] Available Nshift Of 25th Nshift */
#else /* Word 3 - Little Endian */
        uint64_t nshift_24             : 8;  /**< [199:192] Available Nshift Of 25th Nshift */
        uint64_t nshift_25             : 8;  /**< [207:200] Available Nshift Of 26th Nshift */
        uint64_t nshift_26             : 8;  /**< [215:208] Available Nshift Of 27th Nshift */
        uint64_t nshift_27             : 8;  /**< [223:216] Available Nshift Of 28th Nshift */
        uint64_t nshift_28             : 8;  /**< [231:224] Available Nshift Of 29th Nshift */
        uint64_t nshift_29             : 8;  /**< [239:232] Available Nshift Of 30th Nshift */
        uint64_t nshift_30             : 8;  /**< [247:240] Available Nshift Of 31st Nshift */
        uint64_t nshift_31             : 8;  /**< [255:248] Available Nshift Of 32nd Nshift */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t nshift_39             : 8;  /**< [319:312] Available Nshift Of 40th Nshift */
        uint64_t nshift_38             : 8;  /**< [311:304] Available Nshift Of 39th Nshift */
        uint64_t nshift_37             : 8;  /**< [303:296] Available Nshift Of 38th Nshift */
        uint64_t nshift_36             : 8;  /**< [295:288] Available Nshift Of 37th Nshift */
        uint64_t nshift_35             : 8;  /**< [287:280] Available Nshift Of 36th Nshift */
        uint64_t nshift_34             : 8;  /**< [279:272] Available Nshift Of 35th Nshift */
        uint64_t nshift_33             : 8;  /**< [271:264] Available Nshift Of 34th Nshift */
        uint64_t nshift_32             : 8;  /**< [263:256] Available Nshift Of 33rd Nshift */
#else /* Word 4 - Little Endian */
        uint64_t nshift_32             : 8;  /**< [263:256] Available Nshift Of 33rd Nshift */
        uint64_t nshift_33             : 8;  /**< [271:264] Available Nshift Of 34th Nshift */
        uint64_t nshift_34             : 8;  /**< [279:272] Available Nshift Of 35th Nshift */
        uint64_t nshift_35             : 8;  /**< [287:280] Available Nshift Of 36th Nshift */
        uint64_t nshift_36             : 8;  /**< [295:288] Available Nshift Of 37th Nshift */
        uint64_t nshift_37             : 8;  /**< [303:296] Available Nshift Of 38th Nshift */
        uint64_t nshift_38             : 8;  /**< [311:304] Available Nshift Of 39th Nshift */
        uint64_t nshift_39             : 8;  /**< [319:312] Available Nshift Of 40th Nshift */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t nshift_47             : 8;  /**< [383:376] Available Nshift Of 48th Nshift */
        uint64_t nshift_46             : 8;  /**< [375:368] Available Nshift Of 47th Nshift */
        uint64_t nshift_45             : 8;  /**< [367:360] Available Nshift Of 46th Nshift */
        uint64_t nshift_44             : 8;  /**< [359:352] Available Nshift Of 45th Nshift */
        uint64_t nshift_43             : 8;  /**< [351:344] Available Nshift Of 44th Nshift */
        uint64_t nshift_42             : 8;  /**< [343:336] Available Nshift Of 43rd Nshift */
        uint64_t nshift_41             : 8;  /**< [335:328] Available Nshift Of 42nd Nshift */
        uint64_t nshift_40             : 8;  /**< [327:320] Available Nshift Of 41st Nshift */
#else /* Word 5 - Little Endian */
        uint64_t nshift_40             : 8;  /**< [327:320] Available Nshift Of 41st Nshift */
        uint64_t nshift_41             : 8;  /**< [335:328] Available Nshift Of 42nd Nshift */
        uint64_t nshift_42             : 8;  /**< [343:336] Available Nshift Of 43rd Nshift */
        uint64_t nshift_43             : 8;  /**< [351:344] Available Nshift Of 44th Nshift */
        uint64_t nshift_44             : 8;  /**< [359:352] Available Nshift Of 45th Nshift */
        uint64_t nshift_45             : 8;  /**< [367:360] Available Nshift Of 46th Nshift */
        uint64_t nshift_46             : 8;  /**< [375:368] Available Nshift Of 47th Nshift */
        uint64_t nshift_47             : 8;  /**< [383:376] Available Nshift Of 48th Nshift */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t nshift_55             : 8;  /**< [447:440] Available Nshift Of 56th Nshift */
        uint64_t nshift_54             : 8;  /**< [439:432] Available Nshift Of 55th Nshift */
        uint64_t nshift_53             : 8;  /**< [431:424] Available Nshift Of 54th Nshift */
        uint64_t nshift_52             : 8;  /**< [423:416] Available Nshift Of 53rd Nshift */
        uint64_t nshift_51             : 8;  /**< [415:408] Available Nshift Of 52nd Nshift */
        uint64_t nshift_50             : 8;  /**< [407:400] Available Nshift Of 51st Nshift */
        uint64_t nshift_49             : 8;  /**< [399:392] Available Nshift Of 50th Nshift */
        uint64_t nshift_48             : 8;  /**< [391:384] Available Nshift Of 49th Nshift */
#else /* Word 6 - Little Endian */
        uint64_t nshift_48             : 8;  /**< [391:384] Available Nshift Of 49th Nshift */
        uint64_t nshift_49             : 8;  /**< [399:392] Available Nshift Of 50th Nshift */
        uint64_t nshift_50             : 8;  /**< [407:400] Available Nshift Of 51st Nshift */
        uint64_t nshift_51             : 8;  /**< [415:408] Available Nshift Of 52nd Nshift */
        uint64_t nshift_52             : 8;  /**< [423:416] Available Nshift Of 53rd Nshift */
        uint64_t nshift_53             : 8;  /**< [431:424] Available Nshift Of 54th Nshift */
        uint64_t nshift_54             : 8;  /**< [439:432] Available Nshift Of 55th Nshift */
        uint64_t nshift_55             : 8;  /**< [447:440] Available Nshift Of 56th Nshift */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t nshift_63             : 8;  /**< [511:504] Available Nshift Of 64th Nshift */
        uint64_t nshift_62             : 8;  /**< [503:496] Available Nshift Of 63rd Nshift */
        uint64_t nshift_61             : 8;  /**< [495:488] Available Nshift Of 62nd Nshift */
        uint64_t nshift_60             : 8;  /**< [487:480] Available Nshift Of 61st Nshift */
        uint64_t nshift_59             : 8;  /**< [479:472] Available Nshift Of 60th Nshift */
        uint64_t nshift_58             : 8;  /**< [471:464] Available Nshift Of 59th Nshift */
        uint64_t nshift_57             : 8;  /**< [463:456] Available Nshift Of 58th Nshift */
        uint64_t nshift_56             : 8;  /**< [455:448] Available Nshift Of 57th Nshift */
#else /* Word 7 - Little Endian */
        uint64_t nshift_56             : 8;  /**< [455:448] Available Nshift Of 57th Nshift */
        uint64_t nshift_57             : 8;  /**< [463:456] Available Nshift Of 58th Nshift */
        uint64_t nshift_58             : 8;  /**< [471:464] Available Nshift Of 59th Nshift */
        uint64_t nshift_59             : 8;  /**< [479:472] Available Nshift Of 60th Nshift */
        uint64_t nshift_60             : 8;  /**< [487:480] Available Nshift Of 61st Nshift */
        uint64_t nshift_61             : 8;  /**< [495:488] Available Nshift Of 62nd Nshift */
        uint64_t nshift_62             : 8;  /**< [503:496] Available Nshift Of 63rd Nshift */
        uint64_t nshift_63             : 8;  /**< [511:504] Available Nshift Of 64th Nshift */
#endif /* Word 7 - End */
    } s;
    /* struct cavm_prach_jd_nshift_s_s cn; */
};

/**
 * Structure prach_jd_prof_coh_comb_s
 *
 * PRACH Coherence Combination Structure
 */
union cavm_prach_jd_prof_coh_comb_s
{
    uint64_t u;
    struct cavm_prach_jd_prof_coh_comb_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t rtl_debug3            : 12; /**< [ 35: 24] rtl debug
                                                                 Must be 0xFFF */
        uint64_t psym_bitmapa          : 12; /**< [ 23: 12] For PRACH formats with multiple symbol, this parameter is used to exclude
                                                                 certain symbols from coherent combining. Bit position means symbol number from
                                                                 LSB
                                                                 Default : 0xFFF */
        uint64_t reserved_10_11        : 2;
        uint64_t tab_off               : 4;  /**< [  9:  6] Used to reduce the peak power searching window.
                                                                 Default : 0x3 */
        uint64_t smax_w                : 6;  /**< [  5:  0] The number of samples over which to search for 2nd preamble detection peaks
                                                                 Valid range: 0x3~0x28
                                                                 Default :
                                                                 0xD (format 0,1,2,3)
                                                                 0x14 (format 4) */
#else /* Word 0 - Little Endian */
        uint64_t smax_w                : 6;  /**< [  5:  0] The number of samples over which to search for 2nd preamble detection peaks
                                                                 Valid range: 0x3~0x28
                                                                 Default :
                                                                 0xD (format 0,1,2,3)
                                                                 0x14 (format 4) */
        uint64_t tab_off               : 4;  /**< [  9:  6] Used to reduce the peak power searching window.
                                                                 Default : 0x3 */
        uint64_t reserved_10_11        : 2;
        uint64_t psym_bitmapa          : 12; /**< [ 23: 12] For PRACH formats with multiple symbol, this parameter is used to exclude
                                                                 certain symbols from coherent combining. Bit position means symbol number from
                                                                 LSB
                                                                 Default : 0xFFF */
        uint64_t rtl_debug3            : 12; /**< [ 35: 24] rtl debug
                                                                 Must be 0xFFF */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_jd_prof_coh_comb_s_s cnf95xx; */
    struct cavm_prach_jd_prof_coh_comb_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t rtl_debug3            : 12; /**< [ 35: 24] Reserved. Must be 0xFFF. */
        uint64_t psym_bitmapa          : 12; /**< [ 23: 12] For PRACH formats with multiple symbols, this parameter is used to exclude
                                                                 certain symbols from coherent combining. Bit position means symbol number from
                                                                 LSB. Default = 0xFFF. */
        uint64_t reserved_10_11        : 2;
        uint64_t tab_off               : 4;  /**< [  9:  6] Used to reduce the peak power searching window. Default = 0x3. */
        uint64_t smax_w                : 6;  /**< [  5:  0] The number of samples over which to search for second preamble detection peaks.
                                                                 Valid range is 0x3~0x28. Default is 0xD (format 0,1,2,3) or 0x14 (format 4). */
#else /* Word 0 - Little Endian */
        uint64_t smax_w                : 6;  /**< [  5:  0] The number of samples over which to search for second preamble detection peaks.
                                                                 Valid range is 0x3~0x28. Default is 0xD (format 0,1,2,3) or 0x14 (format 4). */
        uint64_t tab_off               : 4;  /**< [  9:  6] Used to reduce the peak power searching window. Default = 0x3. */
        uint64_t reserved_10_11        : 2;
        uint64_t psym_bitmapa          : 12; /**< [ 23: 12] For PRACH formats with multiple symbols, this parameter is used to exclude
                                                                 certain symbols from coherent combining. Bit position means symbol number from
                                                                 LSB. Default = 0xFFF. */
        uint64_t rtl_debug3            : 12; /**< [ 35: 24] Reserved. Must be 0xFFF. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } loki;
};

/**
 * Structure prach_jd_rep_comb_chk_s
 *
 * PRACH Combination Structure
 */
union cavm_prach_jd_rep_comb_chk_s
{
    uint64_t u;
    struct cavm_prach_jd_rep_comb_chk_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t rtl_debug6            : 14; /**< [ 29: 16] RTL debug */
        uint64_t rtl_debug5            : 14; /**< [ 15:  2] RTL debug */
        uint64_t rtl_debug4            : 2;  /**< [  1:  0] RTL debug */
#else /* Word 0 - Little Endian */
        uint64_t rtl_debug4            : 2;  /**< [  1:  0] RTL debug */
        uint64_t rtl_debug5            : 14; /**< [ 15:  2] RTL debug */
        uint64_t rtl_debug6            : 14; /**< [ 29: 16] RTL debug */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_jd_rep_comb_chk_s_s cn; */
};

/**
 * Structure prach_jd_sys_cfg_s
 *
 * PRACH System Configuration Structure
 */
union cavm_prach_jd_sys_cfg_s
{
    uint64_t u;
    struct cavm_prach_jd_sys_cfg_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t zcmseq_mode           : 2;  /**< [ 63: 62] 0x0 : root seq is internally generated
                                                                 0x2 : root seq is externally generated and read through RD DMA. Only valid for short preamble
                                                                 Default: 0x0 */
        uint64_t antenna_7_on          : 1;  /**< [ 61: 61] A bitmap to turn the 7th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_6_on          : 1;  /**< [ 60: 60] A bitmap to turn the 6th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_5_on          : 1;  /**< [ 59: 59] A bitmap to turn the 5th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_4_on          : 1;  /**< [ 58: 58] A bitmap to turn the 4th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_3_on          : 1;  /**< [ 57: 57] A bitmap to turn the 3rd antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_2_on          : 1;  /**< [ 56: 56] A bitmap to turn the 2nd antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_1_on          : 1;  /**< [ 55: 55] A bitmap to turn the 1st antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_0_on          : 1;  /**< [ 54: 54] A bitmap to turn the 0th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t n_repetition          : 3;  /**< [ 53: 51] Number of repetition for eMTC in processing job, given by 2^N_repetition
                                                                 Default : 0x0 */
        uint64_t freq_pos              : 1;  /**< [ 50: 50] If PRACH_JD_SYS_CFG_S[FFT_1024] is set to 0x1, then PRACH_JD_SYS_CFG_S[FREQ_POS]
                                                                 determines which one of the two consecutive PRACH must be processed
                                                                 Default : 0x0 */
        uint64_t fft_1024              : 1;  /**< [ 49: 49] Determines if the input data contains two LTE Format 4 PRACH.
                                                                 0x0: Single PRACH
                                                                 0x1: Two PRACH
                                                                 Default : 0x0 */
        uint64_t in_sam_offset         : 1;  /**< [ 48: 48] Determines if a dummy sample is added to the beginning of input samples. 0x0: no
                                                                 dummy sample. 0x1: one dummy sample
                                                                 Default : 0 */
        uint64_t num_of_preamble       : 6;  /**< [ 47: 42] PRACH_JD_SYS_CFG_S[Num_OF_PREAMBLE] +1 defines the number of preamble to be
                                                                 detected. (PRACH_JD_SYS_CFG_S[Num_OF_PREAMBLE] +1) should be multiples of 4.
                                                                 Default: 0x63 */
        uint64_t n_coh                 : 3;  /**< [ 41: 39] Determines how many symbols are coherently combined before computing the PRACH
                                                                 power. The powers of coherently combined symbols are added up across entire
                                                                 transmission. E.g. When number of symbols is 4, and PRACH_JD_SYS_CFG_S[N_COH] is
                                                                 0x1, then the power of PRACH is computed as(sym0+sym1)^2+(sym2+sym3)^2
                                                                 0x0 : 1
                                                                 0x1 : 2
                                                                 0x2 : 3
                                                                 0x3 : 4
                                                                 0x4 : 6
                                                                 0x5 : 8
                                                                 0x6 : 12 */
        uint64_t num_of_ant            : 3;  /**< [ 38: 36] Defines the number of antenna
                                                                 0x0 : 2 antenna
                                                                 0x1 : 4 antenna
                                                                 0x2 : 8 antenna
                                                                 0x3 : 16 antenna
                                                                 0x4 : 24 antenna
                                                                 0x5 : 32 antenna */
        uint64_t prach_type            : 2;  /**< [ 35: 34] Indicates the PRACH type.
                                                                 0x0 : LTE
                                                                 0x1 : LTE eMTC
                                                                 0x2 : NR long
                                                                 0x3 : NR short */
        uint64_t preamble_format       : 4;  /**< [ 33: 30] Define preamble format
                                                                 LTE (PRACH_JD_SYS_CFG_S[PRACH_type] = 0x0 or 0x1)
                                                                 0x0 : LTE f0
                                                                 0x1 : LTE f1
                                                                 0x2 : LTE f2
                                                                 0x3 : LTE f3
                                                                 0x4 : LTE f4

                                                                 NR long(PRACH_JD_SYS_CFG_S[PRACH_type] = 0x2)
                                                                 0x0 : NR long f0
                                                                 0x1 : NR long f1
                                                                 0x2 : NR long f2
                                                                 0x3 : NR long f3

                                                                 NR short (PRACH_JD_SYS_CFG_S[PRACH_type] =0x3)
                                                                 0x0 : NR short A0
                                                                 0x1 : NR short A1
                                                                 0x2 : NR short A2
                                                                 0x3 : NR short A3
                                                                 0x4 : NR short B1
                                                                 0x5 : NR short B2
                                                                 0x6 : NR short B3
                                                                 0x7 : NR short B4
                                                                 0x8 : NR short C0
                                                                 0x9 : NR short C2 */
        uint64_t rtl_debug_mode        : 2;  /**< [ 29: 28] Must be 0x0 */
        uint64_t tagc_psym             : 2;  /**< [ 27: 26] Index of the symbol on which the RACH power is computed for determining the TAGC. 0x0=1st symbol
                                                                 Default: 0x0 */
        uint64_t db_conv_mode          : 1;  /**< [ 25: 25] 0x0: 0.1dB resolution; 0x1: 0.01 dB resolution */
        uint64_t eng_1r_sel_mode       : 1;  /**< [ 24: 24] 0x0 : PEngdB_out criterion; 0x1 : EngdB_out criterion
                                                                 Valid if PRACH_JD_SYS_CFG_S[ENG_1R_REPORT_MODE] is 0x1
                                                                 Default : 0x1 */
        uint64_t eng_1r_report_mode    : 1;  /**< [ 23: 23] 1R energy report on/off. 0x0 : off; 0x1 : on
                                                                 Default : 0x0 */
        uint64_t mrc_mode              : 1;  /**< [ 22: 22] Determines if power profiles across two antennas are combined without
                                                                 consideration of their noise estimates (Equal gain combining-EGC), or scaled by
                                                                 the noise estimates to generate Maximal ratio combine (MRC)
                                                                 0x0 : EGC mode
                                                                 0x1 : MRC mode
                                                                 Default : 0x0 */
        uint64_t high_speed_set        : 2;  /**< [ 21: 20] 0x0: normal mode(unrestricted set); 0x1 : high speed mode (restricted set type
                                                                 A); 0x2 : very high speed mode(restricted set type B) */
        uint64_t n_zone                : 6;  /**< [ 19: 14] Determines the Number of zero correlation zone per root sequence which is
                                                                 equivalent to  number of cyclically shifted sequence that can be generated from
                                                                 a single root sequence.
                                                                 Valid when NCS_INPUT_MODE[NCS_INPUT_MODE] = 0x1, and is calculated as Floor(839/
                                                                 NCS_INPUT_MODE[NCS_VALUE_DIRECT])
                                                                 Valid only NCS_INPUT_MODE[HIGH_SPEED_SET]= 0x0 */
        uint64_t ncs_input_mode        : 1;  /**< [ 13: 13] This field is used to define how ncs is generated. 0x0 : use configuration
                                                                 value(PRACH_JD_SYS_CFG_S[NCS_CONFIGURATION]) to decide ncs; 0x1 : NCS =
                                                                 (PRACH_JD_SYS_CFG_S[NCS_VALUE_DIRECT]) */
        uint64_t ncs_value_direct      : 9;  /**< [ 12:  4] This field corresponds to NCS value when PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x1. */
        uint64_t ncs_configuration     : 4;  /**< [  3:  0] This field corresponds to the zeroCorrelationZoneConfig when
                                                                 PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x0. Not used when
                                                                 PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x1. */
#else /* Word 0 - Little Endian */
        uint64_t ncs_configuration     : 4;  /**< [  3:  0] This field corresponds to the zeroCorrelationZoneConfig when
                                                                 PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x0. Not used when
                                                                 PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x1. */
        uint64_t ncs_value_direct      : 9;  /**< [ 12:  4] This field corresponds to NCS value when PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x1. */
        uint64_t ncs_input_mode        : 1;  /**< [ 13: 13] This field is used to define how ncs is generated. 0x0 : use configuration
                                                                 value(PRACH_JD_SYS_CFG_S[NCS_CONFIGURATION]) to decide ncs; 0x1 : NCS =
                                                                 (PRACH_JD_SYS_CFG_S[NCS_VALUE_DIRECT]) */
        uint64_t n_zone                : 6;  /**< [ 19: 14] Determines the Number of zero correlation zone per root sequence which is
                                                                 equivalent to  number of cyclically shifted sequence that can be generated from
                                                                 a single root sequence.
                                                                 Valid when NCS_INPUT_MODE[NCS_INPUT_MODE] = 0x1, and is calculated as Floor(839/
                                                                 NCS_INPUT_MODE[NCS_VALUE_DIRECT])
                                                                 Valid only NCS_INPUT_MODE[HIGH_SPEED_SET]= 0x0 */
        uint64_t high_speed_set        : 2;  /**< [ 21: 20] 0x0: normal mode(unrestricted set); 0x1 : high speed mode (restricted set type
                                                                 A); 0x2 : very high speed mode(restricted set type B) */
        uint64_t mrc_mode              : 1;  /**< [ 22: 22] Determines if power profiles across two antennas are combined without
                                                                 consideration of their noise estimates (Equal gain combining-EGC), or scaled by
                                                                 the noise estimates to generate Maximal ratio combine (MRC)
                                                                 0x0 : EGC mode
                                                                 0x1 : MRC mode
                                                                 Default : 0x0 */
        uint64_t eng_1r_report_mode    : 1;  /**< [ 23: 23] 1R energy report on/off. 0x0 : off; 0x1 : on
                                                                 Default : 0x0 */
        uint64_t eng_1r_sel_mode       : 1;  /**< [ 24: 24] 0x0 : PEngdB_out criterion; 0x1 : EngdB_out criterion
                                                                 Valid if PRACH_JD_SYS_CFG_S[ENG_1R_REPORT_MODE] is 0x1
                                                                 Default : 0x1 */
        uint64_t db_conv_mode          : 1;  /**< [ 25: 25] 0x0: 0.1dB resolution; 0x1: 0.01 dB resolution */
        uint64_t tagc_psym             : 2;  /**< [ 27: 26] Index of the symbol on which the RACH power is computed for determining the TAGC. 0x0=1st symbol
                                                                 Default: 0x0 */
        uint64_t rtl_debug_mode        : 2;  /**< [ 29: 28] Must be 0x0 */
        uint64_t preamble_format       : 4;  /**< [ 33: 30] Define preamble format
                                                                 LTE (PRACH_JD_SYS_CFG_S[PRACH_type] = 0x0 or 0x1)
                                                                 0x0 : LTE f0
                                                                 0x1 : LTE f1
                                                                 0x2 : LTE f2
                                                                 0x3 : LTE f3
                                                                 0x4 : LTE f4

                                                                 NR long(PRACH_JD_SYS_CFG_S[PRACH_type] = 0x2)
                                                                 0x0 : NR long f0
                                                                 0x1 : NR long f1
                                                                 0x2 : NR long f2
                                                                 0x3 : NR long f3

                                                                 NR short (PRACH_JD_SYS_CFG_S[PRACH_type] =0x3)
                                                                 0x0 : NR short A0
                                                                 0x1 : NR short A1
                                                                 0x2 : NR short A2
                                                                 0x3 : NR short A3
                                                                 0x4 : NR short B1
                                                                 0x5 : NR short B2
                                                                 0x6 : NR short B3
                                                                 0x7 : NR short B4
                                                                 0x8 : NR short C0
                                                                 0x9 : NR short C2 */
        uint64_t prach_type            : 2;  /**< [ 35: 34] Indicates the PRACH type.
                                                                 0x0 : LTE
                                                                 0x1 : LTE eMTC
                                                                 0x2 : NR long
                                                                 0x3 : NR short */
        uint64_t num_of_ant            : 3;  /**< [ 38: 36] Defines the number of antenna
                                                                 0x0 : 2 antenna
                                                                 0x1 : 4 antenna
                                                                 0x2 : 8 antenna
                                                                 0x3 : 16 antenna
                                                                 0x4 : 24 antenna
                                                                 0x5 : 32 antenna */
        uint64_t n_coh                 : 3;  /**< [ 41: 39] Determines how many symbols are coherently combined before computing the PRACH
                                                                 power. The powers of coherently combined symbols are added up across entire
                                                                 transmission. E.g. When number of symbols is 4, and PRACH_JD_SYS_CFG_S[N_COH] is
                                                                 0x1, then the power of PRACH is computed as(sym0+sym1)^2+(sym2+sym3)^2
                                                                 0x0 : 1
                                                                 0x1 : 2
                                                                 0x2 : 3
                                                                 0x3 : 4
                                                                 0x4 : 6
                                                                 0x5 : 8
                                                                 0x6 : 12 */
        uint64_t num_of_preamble       : 6;  /**< [ 47: 42] PRACH_JD_SYS_CFG_S[Num_OF_PREAMBLE] +1 defines the number of preamble to be
                                                                 detected. (PRACH_JD_SYS_CFG_S[Num_OF_PREAMBLE] +1) should be multiples of 4.
                                                                 Default: 0x63 */
        uint64_t in_sam_offset         : 1;  /**< [ 48: 48] Determines if a dummy sample is added to the beginning of input samples. 0x0: no
                                                                 dummy sample. 0x1: one dummy sample
                                                                 Default : 0 */
        uint64_t fft_1024              : 1;  /**< [ 49: 49] Determines if the input data contains two LTE Format 4 PRACH.
                                                                 0x0: Single PRACH
                                                                 0x1: Two PRACH
                                                                 Default : 0x0 */
        uint64_t freq_pos              : 1;  /**< [ 50: 50] If PRACH_JD_SYS_CFG_S[FFT_1024] is set to 0x1, then PRACH_JD_SYS_CFG_S[FREQ_POS]
                                                                 determines which one of the two consecutive PRACH must be processed
                                                                 Default : 0x0 */
        uint64_t n_repetition          : 3;  /**< [ 53: 51] Number of repetition for eMTC in processing job, given by 2^N_repetition
                                                                 Default : 0x0 */
        uint64_t antenna_0_on          : 1;  /**< [ 54: 54] A bitmap to turn the 0th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_1_on          : 1;  /**< [ 55: 55] A bitmap to turn the 1st antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_2_on          : 1;  /**< [ 56: 56] A bitmap to turn the 2nd antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_3_on          : 1;  /**< [ 57: 57] A bitmap to turn the 3rd antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_4_on          : 1;  /**< [ 58: 58] A bitmap to turn the 4th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_5_on          : 1;  /**< [ 59: 59] A bitmap to turn the 5th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_6_on          : 1;  /**< [ 60: 60] A bitmap to turn the 6th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t antenna_7_on          : 1;  /**< [ 61: 61] A bitmap to turn the 7th antenna on or off
                                                                 0x0 : off
                                                                 0x1: on */
        uint64_t zcmseq_mode           : 2;  /**< [ 63: 62] 0x0 : root seq is internally generated
                                                                 0x2 : root seq is externally generated and read through RD DMA. Only valid for short preamble
                                                                 Default: 0x0 */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_jd_sys_cfg_s_s cnf95xx; */
    struct cavm_prach_jd_sys_cfg_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t zcmseq_mode           : 2;  /**< [ 63: 62] Root sequence mode. Default = 0x0.
                                                                   0x0 = Root sequence is internally generated.
                                                                   0x2 = Root sequence is externally generated and read through RD DMA.

                                                                 Only valid for short preamble. */
        uint64_t antenna_7_on          : 1;  /**< [ 61: 61] A bitmap to turn the 7th antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_6_on          : 1;  /**< [ 60: 60] A bitmap to turn the 6th antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_5_on          : 1;  /**< [ 59: 59] A bitmap to turn the 5th antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_4_on          : 1;  /**< [ 58: 58] A bitmap to turn the 4th antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_3_on          : 1;  /**< [ 57: 57] A bitmap to turn the 3rd antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_2_on          : 1;  /**< [ 56: 56] A bitmap to turn the 2nd antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_1_on          : 1;  /**< [ 55: 55] A bitmap to turn the 1st antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_0_on          : 1;  /**< [ 54: 54] A bitmap to turn the 0th antenna on or off. 0 = off , 1 = on. */
        uint64_t n_repetition          : 3;  /**< [ 53: 51] Number of repetitions for eMTC in processing job, given by 2^N_repetition. Default = 0x0. */
        uint64_t freq_pos              : 1;  /**< [ 50: 50] If PRACH_JD_SYS_CFG_S[FFT_1024] is set to 0x1, then PRACH_JD_SYS_CFG_S[FREQ_POS]
                                                                 determines which of the two consecutive PRACH must be processed. Default = 0x0. */
        uint64_t fft_1024              : 1;  /**< [ 49: 49] Determines if the input data contains two LTE Format 4 PRACH. Default = 0x0.
                                                                 0x0 = Single PRACH.
                                                                 0x1 = Two PRACH. */
        uint64_t in_sam_offset         : 1;  /**< [ 48: 48] Determines if a dummy sample is added to the beginning of input samples. Default = 0x0.
                                                                   0x0 = No dummy sample.
                                                                   0x1 = One dummy sample. */
        uint64_t num_of_preamble       : 6;  /**< [ 47: 42] NUM_OF_PREAMBLE + 1 defines the number of preambles to be
                                                                 detected. (NUM_OF_PREAMBLE + 1) should be a multiple of 4. Default = 0x63. */
        uint64_t n_coh                 : 3;  /**< [ 41: 39] Determines how many symbols are coherently combined before computing the PRACH
                                                                 power. The powers of coherently combined symbols are summed across the entire
                                                                 transmission. For example, when the number of symbols is 4 and
                                                                 PRACH_JD_SYS_CFG_S[N_COH] = 0x1, the power of PRACH is computed as (sym0+sym1)^2 + (sym2+sym3)^2.
                                                                 0x0 = 1.
                                                                 0x1 = 2.
                                                                 0x2 = 3.
                                                                 0x3 = 4.
                                                                 0x4 = 6.
                                                                 0x5 = 8.
                                                                 0x6 = 12. */
        uint64_t num_of_ant            : 3;  /**< [ 38: 36] Defines the number of antennas.
                                                                 0x0 = 2 antennas.
                                                                 0x1 = 4 antennas.
                                                                 0x2 = 8 antennas.
                                                                 0x3 = 16 antennas.
                                                                 0x4 = 24 antennas.
                                                                 0x5 = 32 antennas. */
        uint64_t prach_type            : 2;  /**< [ 35: 34] Indicates the PRACH type.
                                                                 0x0 = LTE.
                                                                 0x1 = LTE eMTC.
                                                                 0x2 = NR long.
                                                                 0x3 = NR short. */
        uint64_t preamble_format       : 4;  /**< [ 33: 30] Define preamble format.
                                                                 For LTE - PRACH_JD_SYS_CFG_S[PRACH_TYPE] = 0x0 or 0x1:
                                                                 0x0 = LTE f0.
                                                                 0x1 = LTE f1.
                                                                 0x2 = LTE f2.
                                                                 0x3 = LTE f3.
                                                                 0x4 = LTE f4.

                                                                 For NR long - PRACH_JD_SYS_CFG_S[PRACH_TYPE] = 0x2:
                                                                 0x0 = NR long f0.
                                                                 0x1 = NR long f1.
                                                                 0x2 = NR long f2.
                                                                 0x3 = NR long f3.

                                                                 For NR short - PRACH_JD_SYS_CFG_S[PRACH_TYPE] = 0x3:
                                                                 0x0 = NR short A0.
                                                                 0x1 = NR short A1.
                                                                 0x2 = NR short A2.
                                                                 0x3 = NR short A3.
                                                                 0x4 = NR short B1.
                                                                 0x5 = NR short B2.
                                                                 0x6 = NR short B3.
                                                                 0x7 = NR short B4.
                                                                 0x8 = NR short C0.
                                                                 0x9 = NR short C2. */
        uint64_t rtl_debug_mode        : 2;  /**< [ 29: 28] Must be 0x0. */
        uint64_t tagc_psym             : 2;  /**< [ 27: 26] Index of the symbol on which the PRACH power is computed for determining the TAGC. Default = 0x0.
                                                                   0x0 = First symbol. */
        uint64_t db_conv_mode          : 1;  /**< [ 25: 25] 0x0 = 0.1 dB resolution.
                                                                 0x1 = 0.01 dB resolution. */
        uint64_t eng_1r_sel_mode       : 1;  /**< [ 24: 24] Eng 1R mode select.
                                                                   0x0 = PEngdB_out criterion.
                                                                   0x1 = EngdB_out criterion.

                                                                 Valid if PRACH_JD_SYS_CFG_S[ENG_1R_REPORT_MODE] = 0x1. Default = 0x1. */
        uint64_t eng_1r_report_mode    : 1;  /**< [ 23: 23] 1R energy report on/off. Default = 0x0.
                                                                   0x0 = Off.
                                                                   0x1 = On. */
        uint64_t mrc_mode              : 1;  /**< [ 22: 22] Determines if power profiles across two antennas are combined without
                                                                 considering their noise estimates (EGC), or scaled by
                                                                 the noise estimates to generate maximal ratio combining (MRC). Default = 0x0.
                                                                 0x0 = EGC (equal gain combining) mode.
                                                                 0x1 = MRC mode. */
        uint64_t high_speed_set        : 2;  /**< [ 21: 20] Set high speed mode.
                                                                   0x0 = Normal mode (unrestricted set).
                                                                   0x1 = High speed mode (restricted set type A).
                                                                   0x2 = Very high speed mode (restricted set type B). */
        uint64_t n_zone                : 6;  /**< [ 19: 14] Determines the number of zero correlation zones per root sequence. This is
                                                                 equivalent to the number of cyclically shifted sequences that can be generated from
                                                                 a single root sequence.
                                                                 Valid when NCS_INPUT_MODE[NCS_INPUT_MODE] = 0x1, and is calculated as
                                                                 Floor(839/NCS_INPUT_MODE[NCS_VALUE_DIRECT]).
                                                                 Valid only when NCS_INPUT_MODE[HIGH_SPEED_SET] = 0x0. */
        uint64_t ncs_input_mode        : 1;  /**< [ 13: 13] This field defines how NCS is generated.
                                                                   0x0 = Use configuration value PRACH_JD_SYS_CFG_S[NCS_CONFIGURATION] to decide NCS.
                                                                   0x1 = NCS equal to PRACH_JD_SYS_CFG_S[NCS_VALUE_DIRECT]. */
        uint64_t ncs_value_direct      : 9;  /**< [ 12:  4] This field corresponds to the NCS value when PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x1. */
        uint64_t ncs_configuration     : 4;  /**< [  3:  0] This field corresponds to the zeroCorrelationZoneConfig when
                                                                 PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x0. Not used when
                                                                 PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x1. */
#else /* Word 0 - Little Endian */
        uint64_t ncs_configuration     : 4;  /**< [  3:  0] This field corresponds to the zeroCorrelationZoneConfig when
                                                                 PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x0. Not used when
                                                                 PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x1. */
        uint64_t ncs_value_direct      : 9;  /**< [ 12:  4] This field corresponds to the NCS value when PRACH_JD_SYS_CFG_S[NCS_INPUT_MODE] = 0x1. */
        uint64_t ncs_input_mode        : 1;  /**< [ 13: 13] This field defines how NCS is generated.
                                                                   0x0 = Use configuration value PRACH_JD_SYS_CFG_S[NCS_CONFIGURATION] to decide NCS.
                                                                   0x1 = NCS equal to PRACH_JD_SYS_CFG_S[NCS_VALUE_DIRECT]. */
        uint64_t n_zone                : 6;  /**< [ 19: 14] Determines the number of zero correlation zones per root sequence. This is
                                                                 equivalent to the number of cyclically shifted sequences that can be generated from
                                                                 a single root sequence.
                                                                 Valid when NCS_INPUT_MODE[NCS_INPUT_MODE] = 0x1, and is calculated as
                                                                 Floor(839/NCS_INPUT_MODE[NCS_VALUE_DIRECT]).
                                                                 Valid only when NCS_INPUT_MODE[HIGH_SPEED_SET] = 0x0. */
        uint64_t high_speed_set        : 2;  /**< [ 21: 20] Set high speed mode.
                                                                   0x0 = Normal mode (unrestricted set).
                                                                   0x1 = High speed mode (restricted set type A).
                                                                   0x2 = Very high speed mode (restricted set type B). */
        uint64_t mrc_mode              : 1;  /**< [ 22: 22] Determines if power profiles across two antennas are combined without
                                                                 considering their noise estimates (EGC), or scaled by
                                                                 the noise estimates to generate maximal ratio combining (MRC). Default = 0x0.
                                                                 0x0 = EGC (equal gain combining) mode.
                                                                 0x1 = MRC mode. */
        uint64_t eng_1r_report_mode    : 1;  /**< [ 23: 23] 1R energy report on/off. Default = 0x0.
                                                                   0x0 = Off.
                                                                   0x1 = On. */
        uint64_t eng_1r_sel_mode       : 1;  /**< [ 24: 24] Eng 1R mode select.
                                                                   0x0 = PEngdB_out criterion.
                                                                   0x1 = EngdB_out criterion.

                                                                 Valid if PRACH_JD_SYS_CFG_S[ENG_1R_REPORT_MODE] = 0x1. Default = 0x1. */
        uint64_t db_conv_mode          : 1;  /**< [ 25: 25] 0x0 = 0.1 dB resolution.
                                                                 0x1 = 0.01 dB resolution. */
        uint64_t tagc_psym             : 2;  /**< [ 27: 26] Index of the symbol on which the PRACH power is computed for determining the TAGC. Default = 0x0.
                                                                   0x0 = First symbol. */
        uint64_t rtl_debug_mode        : 2;  /**< [ 29: 28] Must be 0x0. */
        uint64_t preamble_format       : 4;  /**< [ 33: 30] Define preamble format.
                                                                 For LTE - PRACH_JD_SYS_CFG_S[PRACH_TYPE] = 0x0 or 0x1:
                                                                 0x0 = LTE f0.
                                                                 0x1 = LTE f1.
                                                                 0x2 = LTE f2.
                                                                 0x3 = LTE f3.
                                                                 0x4 = LTE f4.

                                                                 For NR long - PRACH_JD_SYS_CFG_S[PRACH_TYPE] = 0x2:
                                                                 0x0 = NR long f0.
                                                                 0x1 = NR long f1.
                                                                 0x2 = NR long f2.
                                                                 0x3 = NR long f3.

                                                                 For NR short - PRACH_JD_SYS_CFG_S[PRACH_TYPE] = 0x3:
                                                                 0x0 = NR short A0.
                                                                 0x1 = NR short A1.
                                                                 0x2 = NR short A2.
                                                                 0x3 = NR short A3.
                                                                 0x4 = NR short B1.
                                                                 0x5 = NR short B2.
                                                                 0x6 = NR short B3.
                                                                 0x7 = NR short B4.
                                                                 0x8 = NR short C0.
                                                                 0x9 = NR short C2. */
        uint64_t prach_type            : 2;  /**< [ 35: 34] Indicates the PRACH type.
                                                                 0x0 = LTE.
                                                                 0x1 = LTE eMTC.
                                                                 0x2 = NR long.
                                                                 0x3 = NR short. */
        uint64_t num_of_ant            : 3;  /**< [ 38: 36] Defines the number of antennas.
                                                                 0x0 = 2 antennas.
                                                                 0x1 = 4 antennas.
                                                                 0x2 = 8 antennas.
                                                                 0x3 = 16 antennas.
                                                                 0x4 = 24 antennas.
                                                                 0x5 = 32 antennas. */
        uint64_t n_coh                 : 3;  /**< [ 41: 39] Determines how many symbols are coherently combined before computing the PRACH
                                                                 power. The powers of coherently combined symbols are summed across the entire
                                                                 transmission. For example, when the number of symbols is 4 and
                                                                 PRACH_JD_SYS_CFG_S[N_COH] = 0x1, the power of PRACH is computed as (sym0+sym1)^2 + (sym2+sym3)^2.
                                                                 0x0 = 1.
                                                                 0x1 = 2.
                                                                 0x2 = 3.
                                                                 0x3 = 4.
                                                                 0x4 = 6.
                                                                 0x5 = 8.
                                                                 0x6 = 12. */
        uint64_t num_of_preamble       : 6;  /**< [ 47: 42] NUM_OF_PREAMBLE + 1 defines the number of preambles to be
                                                                 detected. (NUM_OF_PREAMBLE + 1) should be a multiple of 4. Default = 0x63. */
        uint64_t in_sam_offset         : 1;  /**< [ 48: 48] Determines if a dummy sample is added to the beginning of input samples. Default = 0x0.
                                                                   0x0 = No dummy sample.
                                                                   0x1 = One dummy sample. */
        uint64_t fft_1024              : 1;  /**< [ 49: 49] Determines if the input data contains two LTE Format 4 PRACH. Default = 0x0.
                                                                 0x0 = Single PRACH.
                                                                 0x1 = Two PRACH. */
        uint64_t freq_pos              : 1;  /**< [ 50: 50] If PRACH_JD_SYS_CFG_S[FFT_1024] is set to 0x1, then PRACH_JD_SYS_CFG_S[FREQ_POS]
                                                                 determines which of the two consecutive PRACH must be processed. Default = 0x0. */
        uint64_t n_repetition          : 3;  /**< [ 53: 51] Number of repetitions for eMTC in processing job, given by 2^N_repetition. Default = 0x0. */
        uint64_t antenna_0_on          : 1;  /**< [ 54: 54] A bitmap to turn the 0th antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_1_on          : 1;  /**< [ 55: 55] A bitmap to turn the 1st antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_2_on          : 1;  /**< [ 56: 56] A bitmap to turn the 2nd antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_3_on          : 1;  /**< [ 57: 57] A bitmap to turn the 3rd antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_4_on          : 1;  /**< [ 58: 58] A bitmap to turn the 4th antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_5_on          : 1;  /**< [ 59: 59] A bitmap to turn the 5th antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_6_on          : 1;  /**< [ 60: 60] A bitmap to turn the 6th antenna on or off. 0 = off , 1 = on. */
        uint64_t antenna_7_on          : 1;  /**< [ 61: 61] A bitmap to turn the 7th antenna on or off. 0 = off , 1 = on. */
        uint64_t zcmseq_mode           : 2;  /**< [ 63: 62] Root sequence mode. Default = 0x0.
                                                                   0x0 = Root sequence is internally generated.
                                                                   0x2 = Root sequence is externally generated and read through RD DMA.

                                                                 Only valid for short preamble. */
#endif /* Word 0 - End */
    } loki;
};

/**
 * Structure prach_jd_thrsh_cp_s
 *
 * PRACH threshold computation Structure
 */
union cavm_prach_jd_thrsh_cp_s
{
    uint64_t u;
    struct cavm_prach_jd_thrsh_cp_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rtl_debug1            : 16; /**< [ 63: 48] Must be 0x0 */
        uint64_t res_sthr_const_1r     : 16; /**< [ 47: 32] Second threshold of restricted combiner for 1R report */
        uint64_t res_sthr_const        : 16; /**< [ 31: 16] Threshold for Restricted mode combiner. Only used for PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET]\>0x0
                                                                 Default: 0xFFFF */
        uint64_t sthreshold_const      : 16; /**< [ 15:  0] Used to detect a second peak. If detected, the corresponding sample power will
                                                                 be added to the main sample power and reported separately as preamble signal
                                                                 power.
                                                                 Default : 0xFFFF */
#else /* Word 0 - Little Endian */
        uint64_t sthreshold_const      : 16; /**< [ 15:  0] Used to detect a second peak. If detected, the corresponding sample power will
                                                                 be added to the main sample power and reported separately as preamble signal
                                                                 power.
                                                                 Default : 0xFFFF */
        uint64_t res_sthr_const        : 16; /**< [ 31: 16] Threshold for Restricted mode combiner. Only used for PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET]\>0x0
                                                                 Default: 0xFFFF */
        uint64_t res_sthr_const_1r     : 16; /**< [ 47: 32] Second threshold of restricted combiner for 1R report */
        uint64_t rtl_debug1            : 16; /**< [ 63: 48] Must be 0x0 */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_jd_thrsh_cp_s_s cnf95xx; */
    struct cavm_prach_jd_thrsh_cp_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rtl_debug1            : 16; /**< [ 63: 48] Must be 0x0. */
        uint64_t res_sthr_const_1r     : 16; /**< [ 47: 32] Second threshold of restricted combiner for 1R report. */
        uint64_t res_sthr_const        : 16; /**< [ 31: 16] Threshold for restricted mode combiner. Only used for
                                                                 PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET] \> 0x0. Default = 0xFFFF. */
        uint64_t sthreshold_const      : 16; /**< [ 15:  0] Used to detect a second peak. If detected, the corresponding sample power
                                                                 is added to the main sample power and reported separately as preamble signal
                                                                 power. Default = 0xFFFF. */
#else /* Word 0 - Little Endian */
        uint64_t sthreshold_const      : 16; /**< [ 15:  0] Used to detect a second peak. If detected, the corresponding sample power
                                                                 is added to the main sample power and reported separately as preamble signal
                                                                 power. Default = 0xFFFF. */
        uint64_t res_sthr_const        : 16; /**< [ 31: 16] Threshold for restricted mode combiner. Only used for
                                                                 PRACH_JD_SYS_CFG_S[HIGH_SPEED_SET] \> 0x0. Default = 0xFFFF. */
        uint64_t res_sthr_const_1r     : 16; /**< [ 47: 32] Second threshold of restricted combiner for 1R report. */
        uint64_t rtl_debug1            : 16; /**< [ 63: 48] Must be 0x0. */
#endif /* Word 0 - End */
    } loki;
};

/**
 * Structure prach_jd_whn_param_s
 *
 * PRACH Whitening Structure
 */
union cavm_prach_jd_whn_param_s
{
    uint64_t u;
    struct cavm_prach_jd_whn_param_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t wfagc_backofff        : 5;  /**< [ 61: 57] Frequency-domain AGC backoff is increasing by 3dB when
                                                                 PRACH_JD_WHN_PARAM_S[WFAGC_BACKOFFF] increases by 0x1 */
        uint64_t wfagc_avgn            : 3;  /**< [ 56: 54] Subcarrier average size of Rnn calibration. Applied on frequency-domain AGC.
                                                                 0x0~0x2, 0x5 (format 0,1,2,3, NR long seq.),
                                                                 0x3~0x4, 0x6 (format 4, NR short seq.) */
        uint64_t wfagc_on              : 1;  /**< [ 53: 53] Enable of disable frequency domain AGC
                                                                 0x0 : off
                                                                 0x1 : on */
        uint64_t reserved_2_52         : 51;
        uint64_t rtl_debug8            : 1;  /**< [  1:  1] Must be 0 */
        uint64_t rtl_debug7            : 1;  /**< [  0:  0] Must be 0 */
#else /* Word 0 - Little Endian */
        uint64_t rtl_debug7            : 1;  /**< [  0:  0] Must be 0 */
        uint64_t rtl_debug8            : 1;  /**< [  1:  1] Must be 0 */
        uint64_t reserved_2_52         : 51;
        uint64_t wfagc_on              : 1;  /**< [ 53: 53] Enable of disable frequency domain AGC
                                                                 0x0 : off
                                                                 0x1 : on */
        uint64_t wfagc_avgn            : 3;  /**< [ 56: 54] Subcarrier average size of Rnn calibration. Applied on frequency-domain AGC.
                                                                 0x0~0x2, 0x5 (format 0,1,2,3, NR long seq.),
                                                                 0x3~0x4, 0x6 (format 4, NR short seq.) */
        uint64_t wfagc_backofff        : 5;  /**< [ 61: 57] Frequency-domain AGC backoff is increasing by 3dB when
                                                                 PRACH_JD_WHN_PARAM_S[WFAGC_BACKOFFF] increases by 0x1 */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    struct cavm_prach_jd_whn_param_s_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t wfagc_backofff        : 5;  /**< [ 61: 57] Frequency-domain AGC backoff is increasing by 3dB when
                                                                 PRACH_JD_WHN_PARAM_S[WFAGC_BACKOFFF] increases by 0x1 */
        uint64_t wfagc_avgn            : 3;  /**< [ 56: 54] Subcarrier average size of Rnn calibration. Applied on frequency-domain AGC.
                                                                 0x0~0x2, 0x5 (format 0,1,2,3, NR long seq.),
                                                                 0x3~0x4, 0x6 (format 4, NR short seq.) */
        uint64_t wfagc_on              : 1;  /**< [ 53: 53] Enable of disable frequency domain AGC
                                                                 0x0 : off
                                                                 0x1 : on */
        uint64_t reserved_50_52        : 3;
        uint64_t reserved_47_49        : 3;
        uint64_t reserved_44_46        : 3;
        uint64_t reserved_34_43        : 10;
        uint64_t reserved_27_33        : 7;
        uint64_t reserved_17_26        : 10;
        uint64_t reserved_15_16        : 2;
        uint64_t reserved_5_14         : 10;
        uint64_t reserved_4            : 1;
        uint64_t reserved_2_3          : 2;
        uint64_t rtl_debug8            : 1;  /**< [  1:  1] Must be 0 */
        uint64_t rtl_debug7            : 1;  /**< [  0:  0] Must be 0 */
#else /* Word 0 - Little Endian */
        uint64_t rtl_debug7            : 1;  /**< [  0:  0] Must be 0 */
        uint64_t rtl_debug8            : 1;  /**< [  1:  1] Must be 0 */
        uint64_t reserved_2_3          : 2;
        uint64_t reserved_4            : 1;
        uint64_t reserved_5_14         : 10;
        uint64_t reserved_15_16        : 2;
        uint64_t reserved_17_26        : 10;
        uint64_t reserved_27_33        : 7;
        uint64_t reserved_34_43        : 10;
        uint64_t reserved_44_46        : 3;
        uint64_t reserved_47_49        : 3;
        uint64_t reserved_50_52        : 3;
        uint64_t wfagc_on              : 1;  /**< [ 53: 53] Enable of disable frequency domain AGC
                                                                 0x0 : off
                                                                 0x1 : on */
        uint64_t wfagc_avgn            : 3;  /**< [ 56: 54] Subcarrier average size of Rnn calibration. Applied on frequency-domain AGC.
                                                                 0x0~0x2, 0x5 (format 0,1,2,3, NR long seq.),
                                                                 0x3~0x4, 0x6 (format 4, NR short seq.) */
        uint64_t wfagc_backofff        : 5;  /**< [ 61: 57] Frequency-domain AGC backoff is increasing by 3dB when
                                                                 PRACH_JD_WHN_PARAM_S[WFAGC_BACKOFFF] increases by 0x1 */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_prach_jd_whn_param_s_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t wfagc_backofff        : 5;  /**< [ 61: 57] Frequency-domain AGC backoff increases by 3 dB when
                                                                 PRACH_JD_WHN_PARAM_S[WFAGC_BACKOFFF] increases by 0x1. */
        uint64_t wfagc_avgn            : 3;  /**< [ 56: 54] Subcarrier average size of Rnn calibration. Applied on frequency-domain AGC.
                                                                 0x0~0x2, 0x5 (format 0,1,2,3, NR long sequence).
                                                                 0x3~0x4, 0x6 (format 4, NR short sequence). */
        uint64_t wfagc_on              : 1;  /**< [ 53: 53] Enable of disable frequency-domain AGC.
                                                                 0x0 = Off.
                                                                 0x1 = On. */
        uint64_t reserved_50_52        : 3;
        uint64_t reserved_47_49        : 3;
        uint64_t reserved_44_46        : 3;
        uint64_t reserved_34_43        : 10;
        uint64_t reserved_27_33        : 7;
        uint64_t reserved_17_26        : 10;
        uint64_t reserved_15_16        : 2;
        uint64_t reserved_5_14         : 10;
        uint64_t reserved_4            : 1;
        uint64_t reserved_2_3          : 2;
        uint64_t rtl_debug8            : 1;  /**< [  1:  1] Must be 0. */
        uint64_t rtl_debug7            : 1;  /**< [  0:  0] Must be 0. */
#else /* Word 0 - Little Endian */
        uint64_t rtl_debug7            : 1;  /**< [  0:  0] Must be 0. */
        uint64_t rtl_debug8            : 1;  /**< [  1:  1] Must be 0. */
        uint64_t reserved_2_3          : 2;
        uint64_t reserved_4            : 1;
        uint64_t reserved_5_14         : 10;
        uint64_t reserved_15_16        : 2;
        uint64_t reserved_17_26        : 10;
        uint64_t reserved_27_33        : 7;
        uint64_t reserved_34_43        : 10;
        uint64_t reserved_44_46        : 3;
        uint64_t reserved_47_49        : 3;
        uint64_t reserved_50_52        : 3;
        uint64_t wfagc_on              : 1;  /**< [ 53: 53] Enable of disable frequency-domain AGC.
                                                                 0x0 = Off.
                                                                 0x1 = On. */
        uint64_t wfagc_avgn            : 3;  /**< [ 56: 54] Subcarrier average size of Rnn calibration. Applied on frequency-domain AGC.
                                                                 0x0~0x2, 0x5 (format 0,1,2,3, NR long sequence).
                                                                 0x3~0x4, 0x6 (format 4, NR short sequence). */
        uint64_t wfagc_backofff        : 5;  /**< [ 61: 57] Frequency-domain AGC backoff increases by 3 dB when
                                                                 PRACH_JD_WHN_PARAM_S[WFAGC_BACKOFFF] increases by 0x1. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } loki;
};

/**
 * Register (RSL) prach_ab#_cal_parameter
 *
 * INTERNAL: CAL Parameter Register
 */
union cavm_prach_abx_cal_parameter
{
    uint64_t u;
    struct cavm_prach_abx_cal_parameter_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27](R/W) Time domain agc back off. 0~31, Default - 12 */
        uint64_t reserved_16_26        : 11;
        uint64_t m_rs                  : 4;  /**< [ 15: 12](R/W) MRC, Noise estimation right shift value. 4 ~ 10. Default :8 (F0~3), 7 (F4) */
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11](R/W) 0- +-du, 0, +-2du, 1- selection for restricted set type. Default- 0 */
        uint64_t reserved_10           : 1;
        uint64_t min_noise             : 10; /**< [  9:  0](R/W) Min. value of noise estimation 0 ~ 1023. Default - 1 */
#else /* Word 0 - Little Endian */
        uint64_t min_noise             : 10; /**< [  9:  0](R/W) Min. value of noise estimation 0 ~ 1023. Default - 1 */
        uint64_t reserved_10           : 1;
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11](R/W) 0- +-du, 0, +-2du, 1- selection for restricted set type. Default- 0 */
        uint64_t m_rs                  : 4;  /**< [ 15: 12](R/W) MRC, Noise estimation right shift value. 4 ~ 10. Default :8 (F0~3), 7 (F4) */
        uint64_t reserved_16_26        : 11;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27](R/W) Time domain agc back off. 0~31, Default - 12 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_cal_parameter_s cnf95xx; */
    struct cavm_prach_abx_cal_parameter_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27](R/W) Time domain agc back off. 0~31, Default - 12 */
        uint64_t reserved_16_26        : 11;
        uint64_t m_rs                  : 4;  /**< [ 15: 12](R/W) MRC, Noise estimation right shift value. 4 ~ 10. Default: 8 (F0~3), 7 (F4) */
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11](R/W) 0- +-du, 0, +-2du, 1- selection for restricted set type. Default- 0 */
        uint64_t reserved_10           : 1;
        uint64_t min_noise             : 10; /**< [  9:  0](R/W) Min. value of noise estimation 0 ~ 1023. Default - 1 */
#else /* Word 0 - Little Endian */
        uint64_t min_noise             : 10; /**< [  9:  0](R/W) Min. value of noise estimation 0 ~ 1023. Default - 1 */
        uint64_t reserved_10           : 1;
        uint64_t restrictedwin_mode    : 1;  /**< [ 11: 11](R/W) 0- +-du, 0, +-2du, 1- selection for restricted set type. Default- 0 */
        uint64_t m_rs                  : 4;  /**< [ 15: 12](R/W) MRC, Noise estimation right shift value. 4 ~ 10. Default: 8 (F0~3), 7 (F4) */
        uint64_t reserved_16_26        : 11;
        uint64_t tagc_backoff          : 5;  /**< [ 31: 27](R/W) Time domain agc back off. 0~31, Default - 12 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_prach_abx_cal_parameter cavm_prach_abx_cal_parameter_t;

static inline uint64_t CAVM_PRACH_ABX_CAL_PARAMETER(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_CAL_PARAMETER(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002020ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002020ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_CAL_PARAMETER", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_CAL_PARAMETER(a) cavm_prach_abx_cal_parameter_t
#define bustype_CAVM_PRACH_ABX_CAL_PARAMETER(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_CAL_PARAMETER(a) "PRACH_ABX_CAL_PARAMETER"
#define busnum_CAVM_PRACH_ABX_CAL_PARAMETER(a) (a)
#define arguments_CAVM_PRACH_ABX_CAL_PARAMETER(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_control
 *
 * PRACH Control Register
 * This register is used to start PRACH HAB processing.
 */
union cavm_prach_abx_control
{
    uint64_t u;
    struct cavm_prach_abx_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t reserved_1_15         : 15;
        uint64_t start_cfg_0           : 1;  /**< [  0:  0](R/W) 1 = start the HAB per config in CONFIGURATION 0 (auto-clear).
                                                                 HAB start ignored if HAB status is busy (HAP_STATUS[0]=1). */
#else /* Word 0 - Little Endian */
        uint64_t start_cfg_0           : 1;  /**< [  0:  0](R/W) 1 = start the HAB per config in CONFIGURATION 0 (auto-clear).
                                                                 HAB start ignored if HAB status is busy (HAP_STATUS[0]=1). */
        uint64_t reserved_1_15         : 15;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_control_s cnf95xx; */
    struct cavm_prach_abx_control_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t reserved_1_15         : 15;
        uint64_t start_cfg_0           : 1;  /**< [  0:  0](R/W) Set this bit to start the PRCH HAB per configuration in CONFIGURATION 0 (auto-clear).
                                                                 HAB start is ignored if HAB status is busy (PRACH_AB(0..1)_HAB_STATUS[STATUS]=1). */
#else /* Word 0 - Little Endian */
        uint64_t start_cfg_0           : 1;  /**< [  0:  0](R/W) Set this bit to start the PRCH HAB per configuration in CONFIGURATION 0 (auto-clear).
                                                                 HAB start is ignored if HAB status is busy (PRACH_AB(0..1)_HAB_STATUS[STATUS]=1). */
        uint64_t reserved_1_15         : 15;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_prach_abx_control cavm_prach_abx_control_t;

static inline uint64_t CAVM_PRACH_ABX_CONTROL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_CONTROL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043000000ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043000000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_CONTROL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_CONTROL(a) cavm_prach_abx_control_t
#define bustype_CAVM_PRACH_ABX_CONTROL(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_CONTROL(a) "PRACH_ABX_CONTROL"
#define busnum_CAVM_PRACH_ABX_CONTROL(a) (a)
#define arguments_CAVM_PRACH_ABX_CONTROL(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_det_param
 *
 * INTERNAL: DET PARAM Register
 */
union cavm_prach_abx_det_param
{
    uint64_t u;
    struct cavm_prach_abx_det_param_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t demap_offset          : 4;  /**< [ 19: 16](R/W) 0 ~ 12 (long seq.) FFT output deamapping offset
                                                                 0 ~ 2 (short seq.)
                                                                 Default - 0 */
        uint64_t freq_bypass           : 1;  /**< [ 15: 15](R/W) If this value is 1, FFT output is read from read I/F. 0 - off, 1 - on. Default - 0 */
        uint64_t sncs_start            : 9;  /**< [ 14:  6](R/W) Start sample of Ncs in short seq.- 0~511. Default - 0 */
        uint64_t num_of_root_seq       : 6;  /**< [  5:  0](R/W) Necessary Number of root seq. for detection- 0-1, 1-2 ... 63 - 64 */
#else /* Word 0 - Little Endian */
        uint64_t num_of_root_seq       : 6;  /**< [  5:  0](R/W) Necessary Number of root seq. for detection- 0-1, 1-2 ... 63 - 64 */
        uint64_t sncs_start            : 9;  /**< [ 14:  6](R/W) Start sample of Ncs in short seq.- 0~511. Default - 0 */
        uint64_t freq_bypass           : 1;  /**< [ 15: 15](R/W) If this value is 1, FFT output is read from read I/F. 0 - off, 1 - on. Default - 0 */
        uint64_t demap_offset          : 4;  /**< [ 19: 16](R/W) 0 ~ 12 (long seq.) FFT output deamapping offset
                                                                 0 ~ 2 (short seq.)
                                                                 Default - 0 */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_det_param_s cn; */
};
typedef union cavm_prach_abx_det_param cavm_prach_abx_det_param_t;

static inline uint64_t CAVM_PRACH_ABX_DET_PARAM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DET_PARAM(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002030ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DET_PARAM", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DET_PARAM(a) cavm_prach_abx_det_param_t
#define bustype_CAVM_PRACH_ABX_DET_PARAM(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DET_PARAM(a) "PRACH_ABX_DET_PARAM"
#define busnum_CAVM_PRACH_ABX_DET_PARAM(a) (a)
#define arguments_CAVM_PRACH_ABX_DET_PARAM(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_0_3
 *
 * INTERNAL: Available Dstart2 0 to 3 Register
 */
union cavm_prach_abx_dstart2_0_3
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_0_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_3             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2 Of 4th logical index */
        uint64_t dstart2_2             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2 Of 3rd logical index */
        uint64_t dstart2_1             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2 Of 2nd logical index */
        uint64_t dstart2_0             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2 Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_0             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2 Of start logical index */
        uint64_t dstart2_1             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2 Of 2nd logical index */
        uint64_t dstart2_2             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2 Of 3rd logical index */
        uint64_t dstart2_3             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2 Of 4th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_0_3_s cn; */
};
typedef union cavm_prach_abx_dstart2_0_3 cavm_prach_abx_dstart2_0_3_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_0_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_0_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002240ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002240ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_0_3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_0_3(a) cavm_prach_abx_dstart2_0_3_t
#define bustype_CAVM_PRACH_ABX_DSTART2_0_3(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_0_3(a) "PRACH_ABX_DSTART2_0_3"
#define busnum_CAVM_PRACH_ABX_DSTART2_0_3(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_0_3(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_12_15
 *
 * INTERNAL: Available Dstart2 12 to 15 Register
 */
union cavm_prach_abx_dstart2_12_15
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_12_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_15            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 15th logical index */
        uint64_t dstart2_14            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 14th logical index */
        uint64_t dstart2_13            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 13th logical index */
        uint64_t dstart2_12            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 12th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_12            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 12th logical index */
        uint64_t dstart2_13            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 13th logical index */
        uint64_t dstart2_14            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 14th logical index */
        uint64_t dstart2_15            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 15th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_12_15_s cn; */
};
typedef union cavm_prach_abx_dstart2_12_15 cavm_prach_abx_dstart2_12_15_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_12_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_12_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002258ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002258ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_12_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_12_15(a) cavm_prach_abx_dstart2_12_15_t
#define bustype_CAVM_PRACH_ABX_DSTART2_12_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_12_15(a) "PRACH_ABX_DSTART2_12_15"
#define busnum_CAVM_PRACH_ABX_DSTART2_12_15(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_12_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_16_19
 *
 * INTERNAL: Available Dstart2 16 to 19 Register
 */
union cavm_prach_abx_dstart2_16_19
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_16_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_19            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 19th logical index */
        uint64_t dstart2_18            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 18th logical index */
        uint64_t dstart2_17            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 17th logical index */
        uint64_t dstart2_16            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_16            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 16th logical index */
        uint64_t dstart2_17            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 17th logical index */
        uint64_t dstart2_18            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 18th logical index */
        uint64_t dstart2_19            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 19th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_16_19_s cn; */
};
typedef union cavm_prach_abx_dstart2_16_19 cavm_prach_abx_dstart2_16_19_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_16_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_16_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002260ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002260ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_16_19", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_16_19(a) cavm_prach_abx_dstart2_16_19_t
#define bustype_CAVM_PRACH_ABX_DSTART2_16_19(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_16_19(a) "PRACH_ABX_DSTART2_16_19"
#define busnum_CAVM_PRACH_ABX_DSTART2_16_19(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_16_19(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_20_23
 *
 * INTERNAL: Available Dstart2 20 to 23 Register
 */
union cavm_prach_abx_dstart2_20_23
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_20_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_23            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 23th logical index */
        uint64_t dstart2_22            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 22th logical index */
        uint64_t dstart2_21            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 21th logical index */
        uint64_t dstart2_20            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 20th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_20            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 20th logical index */
        uint64_t dstart2_21            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 21th logical index */
        uint64_t dstart2_22            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 22th logical index */
        uint64_t dstart2_23            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 23th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_20_23_s cn; */
};
typedef union cavm_prach_abx_dstart2_20_23 cavm_prach_abx_dstart2_20_23_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_20_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_20_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002268ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002268ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_20_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_20_23(a) cavm_prach_abx_dstart2_20_23_t
#define bustype_CAVM_PRACH_ABX_DSTART2_20_23(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_20_23(a) "PRACH_ABX_DSTART2_20_23"
#define busnum_CAVM_PRACH_ABX_DSTART2_20_23(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_20_23(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_24_27
 *
 * INTERNAL: Available Dstart2 24 to 27 Register
 */
union cavm_prach_abx_dstart2_24_27
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_24_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_27            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 27th logical index */
        uint64_t dstart2_26            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 26th logical index */
        uint64_t dstart2_25            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 25th logical index */
        uint64_t dstart2_24            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 24th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_24            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 24th logical index */
        uint64_t dstart2_25            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 25th logical index */
        uint64_t dstart2_26            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 26th logical index */
        uint64_t dstart2_27            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 27th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_24_27_s cn; */
};
typedef union cavm_prach_abx_dstart2_24_27 cavm_prach_abx_dstart2_24_27_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_24_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_24_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002270ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002270ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_24_27", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_24_27(a) cavm_prach_abx_dstart2_24_27_t
#define bustype_CAVM_PRACH_ABX_DSTART2_24_27(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_24_27(a) "PRACH_ABX_DSTART2_24_27"
#define busnum_CAVM_PRACH_ABX_DSTART2_24_27(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_24_27(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_28_31
 *
 * INTERNAL: Available Dstart2 28 to 31 Register
 */
union cavm_prach_abx_dstart2_28_31
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_28_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_31            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 31th logical index */
        uint64_t dstart2_30            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 30th logical index */
        uint64_t dstart2_29            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 29th logical index */
        uint64_t dstart2_28            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 28th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_28            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 28th logical index */
        uint64_t dstart2_29            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 29th logical index */
        uint64_t dstart2_30            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 30th logical index */
        uint64_t dstart2_31            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_28_31_s cn; */
};
typedef union cavm_prach_abx_dstart2_28_31 cavm_prach_abx_dstart2_28_31_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_28_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_28_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002278ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002278ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_28_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_28_31(a) cavm_prach_abx_dstart2_28_31_t
#define bustype_CAVM_PRACH_ABX_DSTART2_28_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_28_31(a) "PRACH_ABX_DSTART2_28_31"
#define busnum_CAVM_PRACH_ABX_DSTART2_28_31(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_28_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_32_35
 *
 * INTERNAL: Available Dstart2 32 to 35 Register
 */
union cavm_prach_abx_dstart2_32_35
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_32_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_35            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 35th logical index */
        uint64_t dstart2_34            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 34th logical index */
        uint64_t dstart2_33            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 33th logical index */
        uint64_t dstart2_32            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_32            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 32th logical index */
        uint64_t dstart2_33            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 33th logical index */
        uint64_t dstart2_34            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 34th logical index */
        uint64_t dstart2_35            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 35th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_32_35_s cn; */
};
typedef union cavm_prach_abx_dstart2_32_35 cavm_prach_abx_dstart2_32_35_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_32_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_32_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002280ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002280ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_32_35", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_32_35(a) cavm_prach_abx_dstart2_32_35_t
#define bustype_CAVM_PRACH_ABX_DSTART2_32_35(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_32_35(a) "PRACH_ABX_DSTART2_32_35"
#define busnum_CAVM_PRACH_ABX_DSTART2_32_35(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_32_35(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_36_39
 *
 * INTERNAL: Available Dstart2 36 to 39 Register
 */
union cavm_prach_abx_dstart2_36_39
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_36_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_39            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 39th logical index */
        uint64_t dstart2_38            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 38th logical index */
        uint64_t dstart2_37            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 37th logical index */
        uint64_t dstart2_36            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 36th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_36            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 36th logical index */
        uint64_t dstart2_37            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 37th logical index */
        uint64_t dstart2_38            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 38th logical index */
        uint64_t dstart2_39            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 39th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_36_39_s cn; */
};
typedef union cavm_prach_abx_dstart2_36_39 cavm_prach_abx_dstart2_36_39_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_36_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_36_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002288ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002288ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_36_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_36_39(a) cavm_prach_abx_dstart2_36_39_t
#define bustype_CAVM_PRACH_ABX_DSTART2_36_39(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_36_39(a) "PRACH_ABX_DSTART2_36_39"
#define busnum_CAVM_PRACH_ABX_DSTART2_36_39(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_36_39(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_40_43
 *
 * INTERNAL: Available Dstart2 40 to 43 Register
 */
union cavm_prach_abx_dstart2_40_43
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_40_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_43            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 43th logical index */
        uint64_t dstart2_42            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 42th logical index */
        uint64_t dstart2_41            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 41th logical index */
        uint64_t dstart2_40            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 40th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_40            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 40th logical index */
        uint64_t dstart2_41            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 41th logical index */
        uint64_t dstart2_42            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 42th logical index */
        uint64_t dstart2_43            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 43th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_40_43_s cn; */
};
typedef union cavm_prach_abx_dstart2_40_43 cavm_prach_abx_dstart2_40_43_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_40_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_40_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002290ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002290ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_40_43", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_40_43(a) cavm_prach_abx_dstart2_40_43_t
#define bustype_CAVM_PRACH_ABX_DSTART2_40_43(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_40_43(a) "PRACH_ABX_DSTART2_40_43"
#define busnum_CAVM_PRACH_ABX_DSTART2_40_43(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_40_43(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_44_47
 *
 * INTERNAL: Available Dstart2 44 to 47 Register
 */
union cavm_prach_abx_dstart2_44_47
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_44_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_47            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 47th logical index */
        uint64_t dstart2_46            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 46th logical index */
        uint64_t dstart2_45            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 45th logical index */
        uint64_t dstart2_44            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 44th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_44            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 44th logical index */
        uint64_t dstart2_45            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 45th logical index */
        uint64_t dstart2_46            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 46th logical index */
        uint64_t dstart2_47            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_44_47_s cn; */
};
typedef union cavm_prach_abx_dstart2_44_47 cavm_prach_abx_dstart2_44_47_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_44_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_44_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002298ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002298ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_44_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_44_47(a) cavm_prach_abx_dstart2_44_47_t
#define bustype_CAVM_PRACH_ABX_DSTART2_44_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_44_47(a) "PRACH_ABX_DSTART2_44_47"
#define busnum_CAVM_PRACH_ABX_DSTART2_44_47(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_44_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_48_51
 *
 * INTERNAL: Available Dstart2 48 to 51 Register
 */
union cavm_prach_abx_dstart2_48_51
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_48_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_51            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 51th logical index */
        uint64_t dstart2_50            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 50th logical index */
        uint64_t dstart2_49            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 49th logical index */
        uint64_t dstart2_48            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_48            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 48th logical index */
        uint64_t dstart2_49            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 49th logical index */
        uint64_t dstart2_50            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 50th logical index */
        uint64_t dstart2_51            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 51th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_48_51_s cn; */
};
typedef union cavm_prach_abx_dstart2_48_51 cavm_prach_abx_dstart2_48_51_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_48_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_48_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022a0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_48_51", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_48_51(a) cavm_prach_abx_dstart2_48_51_t
#define bustype_CAVM_PRACH_ABX_DSTART2_48_51(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_48_51(a) "PRACH_ABX_DSTART2_48_51"
#define busnum_CAVM_PRACH_ABX_DSTART2_48_51(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_48_51(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_4_7
 *
 * INTERNAL: Available Dstart2 4 to 7 Register
 */
union cavm_prach_abx_dstart2_4_7
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_4_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_7             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 7th logical index */
        uint64_t dstart2_6             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 6th logical index */
        uint64_t dstart2_5             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 5th logical index */
        uint64_t dstart2_4             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 4th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_4             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 4th logical index */
        uint64_t dstart2_5             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 5th logical index */
        uint64_t dstart2_6             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 6th logical index */
        uint64_t dstart2_7             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 7th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_4_7_s cn; */
};
typedef union cavm_prach_abx_dstart2_4_7 cavm_prach_abx_dstart2_4_7_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_4_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_4_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002248ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002248ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_4_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_4_7(a) cavm_prach_abx_dstart2_4_7_t
#define bustype_CAVM_PRACH_ABX_DSTART2_4_7(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_4_7(a) "PRACH_ABX_DSTART2_4_7"
#define busnum_CAVM_PRACH_ABX_DSTART2_4_7(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_4_7(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_52_55
 *
 * INTERNAL: Available Dstart2 52 to 55 Register
 */
union cavm_prach_abx_dstart2_52_55
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_52_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_55            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 55th logical index */
        uint64_t dstart2_54            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 54th logical index */
        uint64_t dstart2_53            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 53th logical index */
        uint64_t dstart2_52            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 52th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_52            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 52th logical index */
        uint64_t dstart2_53            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 53th logical index */
        uint64_t dstart2_54            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 54th logical index */
        uint64_t dstart2_55            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 55th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_52_55_s cn; */
};
typedef union cavm_prach_abx_dstart2_52_55 cavm_prach_abx_dstart2_52_55_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_52_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_52_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022a8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_52_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_52_55(a) cavm_prach_abx_dstart2_52_55_t
#define bustype_CAVM_PRACH_ABX_DSTART2_52_55(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_52_55(a) "PRACH_ABX_DSTART2_52_55"
#define busnum_CAVM_PRACH_ABX_DSTART2_52_55(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_52_55(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_56_59
 *
 * INTERNAL: Available Dstart2 56 to 59 Register
 */
union cavm_prach_abx_dstart2_56_59
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_56_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_59            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 59th logical index */
        uint64_t dstart2_58            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 58th logical index */
        uint64_t dstart2_57            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 57th logical index */
        uint64_t dstart2_56            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 56th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_56            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 56th logical index */
        uint64_t dstart2_57            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 57th logical index */
        uint64_t dstart2_58            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 58th logical index */
        uint64_t dstart2_59            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 59th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_56_59_s cn; */
};
typedef union cavm_prach_abx_dstart2_56_59 cavm_prach_abx_dstart2_56_59_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_56_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_56_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022b0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_56_59", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_56_59(a) cavm_prach_abx_dstart2_56_59_t
#define bustype_CAVM_PRACH_ABX_DSTART2_56_59(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_56_59(a) "PRACH_ABX_DSTART2_56_59"
#define busnum_CAVM_PRACH_ABX_DSTART2_56_59(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_56_59(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_60_63
 *
 * INTERNAL: Available Dstart2 60 to 63 Register
 */
union cavm_prach_abx_dstart2_60_63
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_60_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_63            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 63th logical index */
        uint64_t dstart2_62            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 62th logical index */
        uint64_t dstart2_61            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 61th logical index */
        uint64_t dstart2_60            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 60th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_60            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 60th logical index */
        uint64_t dstart2_61            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 61th logical index */
        uint64_t dstart2_62            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 62th logical index */
        uint64_t dstart2_63            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_60_63_s cn; */
};
typedef union cavm_prach_abx_dstart2_60_63 cavm_prach_abx_dstart2_60_63_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_60_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_60_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022b8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_60_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_60_63(a) cavm_prach_abx_dstart2_60_63_t
#define bustype_CAVM_PRACH_ABX_DSTART2_60_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_60_63(a) "PRACH_ABX_DSTART2_60_63"
#define busnum_CAVM_PRACH_ABX_DSTART2_60_63(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_60_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart2_8_11
 *
 * INTERNAL: Available Dstart2 8 to 11 Register
 */
union cavm_prach_abx_dstart2_8_11
{
    uint64_t u;
    struct cavm_prach_abx_dstart2_8_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart2_11            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 11th logical index */
        uint64_t dstart2_10            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 10th logical index */
        uint64_t dstart2_9             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 9th logical index */
        uint64_t dstart2_8             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 8th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart2_8             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 8th logical index */
        uint64_t dstart2_9             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 9th logical index */
        uint64_t dstart2_10            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 10th logical index */
        uint64_t dstart2_11            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart2. Of 11th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart2_8_11_s cn; */
};
typedef union cavm_prach_abx_dstart2_8_11 cavm_prach_abx_dstart2_8_11_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART2_8_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART2_8_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002250ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002250ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART2_8_11", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART2_8_11(a) cavm_prach_abx_dstart2_8_11_t
#define bustype_CAVM_PRACH_ABX_DSTART2_8_11(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART2_8_11(a) "PRACH_ABX_DSTART2_8_11"
#define busnum_CAVM_PRACH_ABX_DSTART2_8_11(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART2_8_11(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_0_3
 *
 * INTERNAL: Available Dstart3 0 to 3 Register
 */
union cavm_prach_abx_dstart3_0_3
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_0_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_3             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3 Of 4th logical index */
        uint64_t dstart3_2             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3 Of 3rd logical index */
        uint64_t dstart3_1             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3 Of 2nd logical index */
        uint64_t dstart3_0             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3 Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_0             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3 Of start logical index */
        uint64_t dstart3_1             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3 Of 2nd logical index */
        uint64_t dstart3_2             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3 Of 3rd logical index */
        uint64_t dstart3_3             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3 Of 4th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_0_3_s cn; */
};
typedef union cavm_prach_abx_dstart3_0_3 cavm_prach_abx_dstart3_0_3_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_0_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_0_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022c0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_0_3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_0_3(a) cavm_prach_abx_dstart3_0_3_t
#define bustype_CAVM_PRACH_ABX_DSTART3_0_3(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_0_3(a) "PRACH_ABX_DSTART3_0_3"
#define busnum_CAVM_PRACH_ABX_DSTART3_0_3(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_0_3(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_12_15
 *
 * INTERNAL: Available Dstart3 12 to 15 Register
 */
union cavm_prach_abx_dstart3_12_15
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_12_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_15            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 15th logical index */
        uint64_t dstart3_14            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 14th logical index */
        uint64_t dstart3_13            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 13th logical index */
        uint64_t dstart3_12            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 12th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_12            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 12th logical index */
        uint64_t dstart3_13            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 13th logical index */
        uint64_t dstart3_14            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 14th logical index */
        uint64_t dstart3_15            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 15th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_12_15_s cn; */
};
typedef union cavm_prach_abx_dstart3_12_15 cavm_prach_abx_dstart3_12_15_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_12_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_12_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022d8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_12_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_12_15(a) cavm_prach_abx_dstart3_12_15_t
#define bustype_CAVM_PRACH_ABX_DSTART3_12_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_12_15(a) "PRACH_ABX_DSTART3_12_15"
#define busnum_CAVM_PRACH_ABX_DSTART3_12_15(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_12_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_16_19
 *
 * INTERNAL: Available Dstart3 16 to 19 Register
 */
union cavm_prach_abx_dstart3_16_19
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_16_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_19            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 19th logical index */
        uint64_t dstart3_18            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 18th logical index */
        uint64_t dstart3_17            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 17th logical index */
        uint64_t dstart3_16            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_16            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 16th logical index */
        uint64_t dstart3_17            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 17th logical index */
        uint64_t dstart3_18            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 18th logical index */
        uint64_t dstart3_19            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 19th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_16_19_s cn; */
};
typedef union cavm_prach_abx_dstart3_16_19 cavm_prach_abx_dstart3_16_19_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_16_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_16_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022e0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_16_19", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_16_19(a) cavm_prach_abx_dstart3_16_19_t
#define bustype_CAVM_PRACH_ABX_DSTART3_16_19(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_16_19(a) "PRACH_ABX_DSTART3_16_19"
#define busnum_CAVM_PRACH_ABX_DSTART3_16_19(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_16_19(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_20_23
 *
 * INTERNAL: Available Dstart3 20 to 23 Register
 */
union cavm_prach_abx_dstart3_20_23
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_20_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_23            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 23th logical index */
        uint64_t dstart3_22            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 22th logical index */
        uint64_t dstart3_21            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 21th logical index */
        uint64_t dstart3_20            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 20th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_20            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 20th logical index */
        uint64_t dstart3_21            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 21th logical index */
        uint64_t dstart3_22            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 22th logical index */
        uint64_t dstart3_23            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 23th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_20_23_s cn; */
};
typedef union cavm_prach_abx_dstart3_20_23 cavm_prach_abx_dstart3_20_23_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_20_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_20_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022e8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_20_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_20_23(a) cavm_prach_abx_dstart3_20_23_t
#define bustype_CAVM_PRACH_ABX_DSTART3_20_23(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_20_23(a) "PRACH_ABX_DSTART3_20_23"
#define busnum_CAVM_PRACH_ABX_DSTART3_20_23(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_20_23(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_24_27
 *
 * INTERNAL: Available Dstart3 24 to 27 Register
 */
union cavm_prach_abx_dstart3_24_27
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_24_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_27            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 27th logical index */
        uint64_t dstart3_26            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 26th logical index */
        uint64_t dstart3_25            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 25th logical index */
        uint64_t dstart3_24            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 24th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_24            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 24th logical index */
        uint64_t dstart3_25            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 25th logical index */
        uint64_t dstart3_26            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 26th logical index */
        uint64_t dstart3_27            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 27th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_24_27_s cn; */
};
typedef union cavm_prach_abx_dstart3_24_27 cavm_prach_abx_dstart3_24_27_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_24_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_24_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022f0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_24_27", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_24_27(a) cavm_prach_abx_dstart3_24_27_t
#define bustype_CAVM_PRACH_ABX_DSTART3_24_27(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_24_27(a) "PRACH_ABX_DSTART3_24_27"
#define busnum_CAVM_PRACH_ABX_DSTART3_24_27(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_24_27(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_28_31
 *
 * INTERNAL: Available Dstart3 28 to 31 Register
 */
union cavm_prach_abx_dstart3_28_31
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_28_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_31            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 31th logical index */
        uint64_t dstart3_30            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 30th logical index */
        uint64_t dstart3_29            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 29th logical index */
        uint64_t dstart3_28            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 28th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_28            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 28th logical index */
        uint64_t dstart3_29            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 29th logical index */
        uint64_t dstart3_30            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 30th logical index */
        uint64_t dstart3_31            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_28_31_s cn; */
};
typedef union cavm_prach_abx_dstart3_28_31 cavm_prach_abx_dstart3_28_31_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_28_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_28_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022f8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_28_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_28_31(a) cavm_prach_abx_dstart3_28_31_t
#define bustype_CAVM_PRACH_ABX_DSTART3_28_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_28_31(a) "PRACH_ABX_DSTART3_28_31"
#define busnum_CAVM_PRACH_ABX_DSTART3_28_31(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_28_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_32_35
 *
 * INTERNAL: Available Dstart3 32 to 35 Register
 */
union cavm_prach_abx_dstart3_32_35
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_32_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_35            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 35th logical index */
        uint64_t dstart3_34            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 34th logical index */
        uint64_t dstart3_33            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 33th logical index */
        uint64_t dstart3_32            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_32            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 32th logical index */
        uint64_t dstart3_33            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 33th logical index */
        uint64_t dstart3_34            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 34th logical index */
        uint64_t dstart3_35            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 35th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_32_35_s cn; */
};
typedef union cavm_prach_abx_dstart3_32_35 cavm_prach_abx_dstart3_32_35_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_32_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_32_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002300ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002300ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_32_35", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_32_35(a) cavm_prach_abx_dstart3_32_35_t
#define bustype_CAVM_PRACH_ABX_DSTART3_32_35(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_32_35(a) "PRACH_ABX_DSTART3_32_35"
#define busnum_CAVM_PRACH_ABX_DSTART3_32_35(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_32_35(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_36_39
 *
 * INTERNAL: Available Dstart3 36 to 39 Register
 */
union cavm_prach_abx_dstart3_36_39
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_36_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_39            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 39th logical index */
        uint64_t dstart3_38            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 38th logical index */
        uint64_t dstart3_37            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 37th logical index */
        uint64_t dstart3_36            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 36th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_36            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 36th logical index */
        uint64_t dstart3_37            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 37th logical index */
        uint64_t dstart3_38            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 38th logical index */
        uint64_t dstart3_39            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 39th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_36_39_s cn; */
};
typedef union cavm_prach_abx_dstart3_36_39 cavm_prach_abx_dstart3_36_39_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_36_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_36_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002308ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002308ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_36_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_36_39(a) cavm_prach_abx_dstart3_36_39_t
#define bustype_CAVM_PRACH_ABX_DSTART3_36_39(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_36_39(a) "PRACH_ABX_DSTART3_36_39"
#define busnum_CAVM_PRACH_ABX_DSTART3_36_39(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_36_39(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_40_43
 *
 * INTERNAL: Available Dstart3 40 to 43 Register
 */
union cavm_prach_abx_dstart3_40_43
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_40_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_43            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 43th logical index */
        uint64_t dstart3_42            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 42th logical index */
        uint64_t dstart3_41            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 41th logical index */
        uint64_t dstart3_40            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 40th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_40            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 40th logical index */
        uint64_t dstart3_41            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 41th logical index */
        uint64_t dstart3_42            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 42th logical index */
        uint64_t dstart3_43            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 43th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_40_43_s cn; */
};
typedef union cavm_prach_abx_dstart3_40_43 cavm_prach_abx_dstart3_40_43_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_40_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_40_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002310ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002310ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_40_43", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_40_43(a) cavm_prach_abx_dstart3_40_43_t
#define bustype_CAVM_PRACH_ABX_DSTART3_40_43(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_40_43(a) "PRACH_ABX_DSTART3_40_43"
#define busnum_CAVM_PRACH_ABX_DSTART3_40_43(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_40_43(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_44_47
 *
 * INTERNAL: Available Dstart3 44 to 47 Register
 */
union cavm_prach_abx_dstart3_44_47
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_44_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_47            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 47th logical index */
        uint64_t dstart3_46            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 46th logical index */
        uint64_t dstart3_45            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 45th logical index */
        uint64_t dstart3_44            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 44th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_44            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 44th logical index */
        uint64_t dstart3_45            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 45th logical index */
        uint64_t dstart3_46            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 46th logical index */
        uint64_t dstart3_47            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_44_47_s cn; */
};
typedef union cavm_prach_abx_dstart3_44_47 cavm_prach_abx_dstart3_44_47_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_44_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_44_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002318ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002318ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_44_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_44_47(a) cavm_prach_abx_dstart3_44_47_t
#define bustype_CAVM_PRACH_ABX_DSTART3_44_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_44_47(a) "PRACH_ABX_DSTART3_44_47"
#define busnum_CAVM_PRACH_ABX_DSTART3_44_47(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_44_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_48_51
 *
 * INTERNAL: Available Dstart3 48 to 51 Register
 */
union cavm_prach_abx_dstart3_48_51
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_48_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_51            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 51th logical index */
        uint64_t dstart3_50            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 50th logical index */
        uint64_t dstart3_49            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 49th logical index */
        uint64_t dstart3_48            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_48            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 48th logical index */
        uint64_t dstart3_49            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 49th logical index */
        uint64_t dstart3_50            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 50th logical index */
        uint64_t dstart3_51            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 51th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_48_51_s cn; */
};
typedef union cavm_prach_abx_dstart3_48_51 cavm_prach_abx_dstart3_48_51_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_48_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_48_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002320ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002320ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_48_51", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_48_51(a) cavm_prach_abx_dstart3_48_51_t
#define bustype_CAVM_PRACH_ABX_DSTART3_48_51(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_48_51(a) "PRACH_ABX_DSTART3_48_51"
#define busnum_CAVM_PRACH_ABX_DSTART3_48_51(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_48_51(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_4_7
 *
 * INTERNAL: Available Dstart3 4 to 7 Register
 */
union cavm_prach_abx_dstart3_4_7
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_4_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_7             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 7th logical index */
        uint64_t dstart3_6             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 6th logical index */
        uint64_t dstart3_5             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 5th logical index */
        uint64_t dstart3_4             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 4th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_4             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 4th logical index */
        uint64_t dstart3_5             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 5th logical index */
        uint64_t dstart3_6             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 6th logical index */
        uint64_t dstart3_7             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 7th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_4_7_s cn; */
};
typedef union cavm_prach_abx_dstart3_4_7 cavm_prach_abx_dstart3_4_7_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_4_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_4_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022c8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_4_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_4_7(a) cavm_prach_abx_dstart3_4_7_t
#define bustype_CAVM_PRACH_ABX_DSTART3_4_7(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_4_7(a) "PRACH_ABX_DSTART3_4_7"
#define busnum_CAVM_PRACH_ABX_DSTART3_4_7(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_4_7(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_52_55
 *
 * INTERNAL: Available Dstart3 52 to 55 Register
 */
union cavm_prach_abx_dstart3_52_55
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_52_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_55            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 55th logical index */
        uint64_t dstart3_54            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 54th logical index */
        uint64_t dstart3_53            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 53th logical index */
        uint64_t dstart3_52            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 52th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_52            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 52th logical index */
        uint64_t dstart3_53            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 53th logical index */
        uint64_t dstart3_54            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 54th logical index */
        uint64_t dstart3_55            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 55th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_52_55_s cn; */
};
typedef union cavm_prach_abx_dstart3_52_55 cavm_prach_abx_dstart3_52_55_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_52_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_52_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002328ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002328ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_52_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_52_55(a) cavm_prach_abx_dstart3_52_55_t
#define bustype_CAVM_PRACH_ABX_DSTART3_52_55(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_52_55(a) "PRACH_ABX_DSTART3_52_55"
#define busnum_CAVM_PRACH_ABX_DSTART3_52_55(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_52_55(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_56_59
 *
 * INTERNAL: Available Dstart3 56 to 59 Register
 */
union cavm_prach_abx_dstart3_56_59
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_56_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_59            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 59th logical index */
        uint64_t dstart3_58            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 58th logical index */
        uint64_t dstart3_57            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 57th logical index */
        uint64_t dstart3_56            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 56th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_56            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 56th logical index */
        uint64_t dstart3_57            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 57th logical index */
        uint64_t dstart3_58            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 58th logical index */
        uint64_t dstart3_59            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 59th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_56_59_s cn; */
};
typedef union cavm_prach_abx_dstart3_56_59 cavm_prach_abx_dstart3_56_59_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_56_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_56_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002330ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002330ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_56_59", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_56_59(a) cavm_prach_abx_dstart3_56_59_t
#define bustype_CAVM_PRACH_ABX_DSTART3_56_59(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_56_59(a) "PRACH_ABX_DSTART3_56_59"
#define busnum_CAVM_PRACH_ABX_DSTART3_56_59(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_56_59(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_60_63
 *
 * INTERNAL: Available Dstart3 60 to 63 Register
 */
union cavm_prach_abx_dstart3_60_63
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_60_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_63            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 63th logical index */
        uint64_t dstart3_62            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 62th logical index */
        uint64_t dstart3_61            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 61th logical index */
        uint64_t dstart3_60            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 60th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_60            : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 60th logical index */
        uint64_t dstart3_61            : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 61th logical index */
        uint64_t dstart3_62            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 62th logical index */
        uint64_t dstart3_63            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_60_63_s cn; */
};
typedef union cavm_prach_abx_dstart3_60_63 cavm_prach_abx_dstart3_60_63_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_60_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_60_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002338ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002338ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_60_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_60_63(a) cavm_prach_abx_dstart3_60_63_t
#define bustype_CAVM_PRACH_ABX_DSTART3_60_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_60_63(a) "PRACH_ABX_DSTART3_60_63"
#define busnum_CAVM_PRACH_ABX_DSTART3_60_63(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_60_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart3_8_11
 *
 * INTERNAL: Available Dstart3 8 to 11 Register
 */
union cavm_prach_abx_dstart3_8_11
{
    uint64_t u;
    struct cavm_prach_abx_dstart3_8_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart3_11            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 11th logical index */
        uint64_t dstart3_10            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 10th logical index */
        uint64_t dstart3_9             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 9th logical index */
        uint64_t dstart3_8             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 8th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart3_8             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 8th logical index */
        uint64_t dstart3_9             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 9th logical index */
        uint64_t dstart3_10            : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 10th logical index */
        uint64_t dstart3_11            : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart3. Of 11th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart3_8_11_s cn; */
};
typedef union cavm_prach_abx_dstart3_8_11 cavm_prach_abx_dstart3_8_11_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART3_8_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART3_8_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430022d0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430022d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART3_8_11", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART3_8_11(a) cavm_prach_abx_dstart3_8_11_t
#define bustype_CAVM_PRACH_ABX_DSTART3_8_11(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART3_8_11(a) "PRACH_ABX_DSTART3_8_11"
#define busnum_CAVM_PRACH_ABX_DSTART3_8_11(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART3_8_11(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_0_3
 *
 * INTERNAL: Available Dstart 0 to 3 Register
 */
union cavm_prach_abx_dstart_0_3
{
    uint64_t u;
    struct cavm_prach_abx_dstart_0_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_3              : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 4th logical index */
        uint64_t dstart_2              : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 3rd logical index */
        uint64_t dstart_1              : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 2nd logical index */
        uint64_t dstart_0              : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_0              : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of start logical index */
        uint64_t dstart_1              : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 2nd logical index */
        uint64_t dstart_2              : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 3rd logical index */
        uint64_t dstart_3              : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 4th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_0_3_s cn; */
};
typedef union cavm_prach_abx_dstart_0_3 cavm_prach_abx_dstart_0_3_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_0_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_0_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002100ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002100ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_0_3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_0_3(a) cavm_prach_abx_dstart_0_3_t
#define bustype_CAVM_PRACH_ABX_DSTART_0_3(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_0_3(a) "PRACH_ABX_DSTART_0_3"
#define busnum_CAVM_PRACH_ABX_DSTART_0_3(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_0_3(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_12_15
 *
 * INTERNAL: Available Dstart 12 to 15 Register
 */
union cavm_prach_abx_dstart_12_15
{
    uint64_t u;
    struct cavm_prach_abx_dstart_12_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_15             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 15th logical index */
        uint64_t dstart_14             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 14th logical index */
        uint64_t dstart_13             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 13th logical index */
        uint64_t dstart_12             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 12th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_12             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 12th logical index */
        uint64_t dstart_13             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 13th logical index */
        uint64_t dstart_14             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 14th logical index */
        uint64_t dstart_15             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 15th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_12_15_s cn; */
};
typedef union cavm_prach_abx_dstart_12_15 cavm_prach_abx_dstart_12_15_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_12_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_12_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002118ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002118ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_12_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_12_15(a) cavm_prach_abx_dstart_12_15_t
#define bustype_CAVM_PRACH_ABX_DSTART_12_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_12_15(a) "PRACH_ABX_DSTART_12_15"
#define busnum_CAVM_PRACH_ABX_DSTART_12_15(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_12_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_16_19
 *
 * INTERNAL: Available Dstart 16 to 19 Register
 */
union cavm_prach_abx_dstart_16_19
{
    uint64_t u;
    struct cavm_prach_abx_dstart_16_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_19             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 19th logical index */
        uint64_t dstart_18             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 18th logical index */
        uint64_t dstart_17             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 17th logical index */
        uint64_t dstart_16             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_16             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 16th logical index */
        uint64_t dstart_17             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 17th logical index */
        uint64_t dstart_18             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 18th logical index */
        uint64_t dstart_19             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 19th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_16_19_s cn; */
};
typedef union cavm_prach_abx_dstart_16_19 cavm_prach_abx_dstart_16_19_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_16_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_16_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002120ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002120ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_16_19", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_16_19(a) cavm_prach_abx_dstart_16_19_t
#define bustype_CAVM_PRACH_ABX_DSTART_16_19(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_16_19(a) "PRACH_ABX_DSTART_16_19"
#define busnum_CAVM_PRACH_ABX_DSTART_16_19(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_16_19(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_20_23
 *
 * INTERNAL: Available Dstart 20 to 23 Register
 */
union cavm_prach_abx_dstart_20_23
{
    uint64_t u;
    struct cavm_prach_abx_dstart_20_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_23             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 23th logical index */
        uint64_t dstart_22             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 22th logical index */
        uint64_t dstart_21             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 21th logical index */
        uint64_t dstart_20             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 20th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_20             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 20th logical index */
        uint64_t dstart_21             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 21th logical index */
        uint64_t dstart_22             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 22th logical index */
        uint64_t dstart_23             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 23th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_20_23_s cn; */
};
typedef union cavm_prach_abx_dstart_20_23 cavm_prach_abx_dstart_20_23_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_20_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_20_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002128ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002128ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_20_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_20_23(a) cavm_prach_abx_dstart_20_23_t
#define bustype_CAVM_PRACH_ABX_DSTART_20_23(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_20_23(a) "PRACH_ABX_DSTART_20_23"
#define busnum_CAVM_PRACH_ABX_DSTART_20_23(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_20_23(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_24_27
 *
 * INTERNAL: Available Dstart 24 to 27 Register
 */
union cavm_prach_abx_dstart_24_27
{
    uint64_t u;
    struct cavm_prach_abx_dstart_24_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_27             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 27th logical index */
        uint64_t dstart_26             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 26th logical index */
        uint64_t dstart_25             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 25th logical index */
        uint64_t dstart_24             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 24th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_24             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 24th logical index */
        uint64_t dstart_25             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 25th logical index */
        uint64_t dstart_26             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 26th logical index */
        uint64_t dstart_27             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 27th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_24_27_s cn; */
};
typedef union cavm_prach_abx_dstart_24_27 cavm_prach_abx_dstart_24_27_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_24_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_24_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002130ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002130ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_24_27", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_24_27(a) cavm_prach_abx_dstart_24_27_t
#define bustype_CAVM_PRACH_ABX_DSTART_24_27(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_24_27(a) "PRACH_ABX_DSTART_24_27"
#define busnum_CAVM_PRACH_ABX_DSTART_24_27(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_24_27(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_28_31
 *
 * INTERNAL: Available Dstart 28 to 31 Register
 */
union cavm_prach_abx_dstart_28_31
{
    uint64_t u;
    struct cavm_prach_abx_dstart_28_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_31             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 31th logical index */
        uint64_t dstart_30             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 30th logical index */
        uint64_t dstart_29             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 29th logical index */
        uint64_t dstart_28             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 28th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_28             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 28th logical index */
        uint64_t dstart_29             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 29th logical index */
        uint64_t dstart_30             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 30th logical index */
        uint64_t dstart_31             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_28_31_s cn; */
};
typedef union cavm_prach_abx_dstart_28_31 cavm_prach_abx_dstart_28_31_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_28_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_28_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002138ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002138ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_28_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_28_31(a) cavm_prach_abx_dstart_28_31_t
#define bustype_CAVM_PRACH_ABX_DSTART_28_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_28_31(a) "PRACH_ABX_DSTART_28_31"
#define busnum_CAVM_PRACH_ABX_DSTART_28_31(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_28_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_32_35
 *
 * INTERNAL: Available Dstart 32 to 35 Register
 */
union cavm_prach_abx_dstart_32_35
{
    uint64_t u;
    struct cavm_prach_abx_dstart_32_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_35             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 35th logical index */
        uint64_t dstart_34             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 34th logical index */
        uint64_t dstart_33             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 33th logical index */
        uint64_t dstart_32             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_32             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 32th logical index */
        uint64_t dstart_33             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 33th logical index */
        uint64_t dstart_34             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 34th logical index */
        uint64_t dstart_35             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 35th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_32_35_s cn; */
};
typedef union cavm_prach_abx_dstart_32_35 cavm_prach_abx_dstart_32_35_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_32_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_32_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002140ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002140ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_32_35", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_32_35(a) cavm_prach_abx_dstart_32_35_t
#define bustype_CAVM_PRACH_ABX_DSTART_32_35(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_32_35(a) "PRACH_ABX_DSTART_32_35"
#define busnum_CAVM_PRACH_ABX_DSTART_32_35(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_32_35(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_36_39
 *
 * INTERNAL: Available Dstart 36 to 39 Register
 */
union cavm_prach_abx_dstart_36_39
{
    uint64_t u;
    struct cavm_prach_abx_dstart_36_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_39             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 39th logical index */
        uint64_t dstart_38             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 38th logical index */
        uint64_t dstart_37             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 37th logical index */
        uint64_t dstart_36             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 36th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_36             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 36th logical index */
        uint64_t dstart_37             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 37th logical index */
        uint64_t dstart_38             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 38th logical index */
        uint64_t dstart_39             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 39th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_36_39_s cn; */
};
typedef union cavm_prach_abx_dstart_36_39 cavm_prach_abx_dstart_36_39_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_36_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_36_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002148ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002148ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_36_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_36_39(a) cavm_prach_abx_dstart_36_39_t
#define bustype_CAVM_PRACH_ABX_DSTART_36_39(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_36_39(a) "PRACH_ABX_DSTART_36_39"
#define busnum_CAVM_PRACH_ABX_DSTART_36_39(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_36_39(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_40_43
 *
 * INTERNAL: Available Dstart 40 to 43 Register
 */
union cavm_prach_abx_dstart_40_43
{
    uint64_t u;
    struct cavm_prach_abx_dstart_40_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_43             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 43th logical index */
        uint64_t dstart_42             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 42th logical index */
        uint64_t dstart_41             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 41th logical index */
        uint64_t dstart_40             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 40th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_40             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 40th logical index */
        uint64_t dstart_41             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 41th logical index */
        uint64_t dstart_42             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 42th logical index */
        uint64_t dstart_43             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 43th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_40_43_s cn; */
};
typedef union cavm_prach_abx_dstart_40_43 cavm_prach_abx_dstart_40_43_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_40_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_40_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002150ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002150ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_40_43", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_40_43(a) cavm_prach_abx_dstart_40_43_t
#define bustype_CAVM_PRACH_ABX_DSTART_40_43(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_40_43(a) "PRACH_ABX_DSTART_40_43"
#define busnum_CAVM_PRACH_ABX_DSTART_40_43(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_40_43(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_44_47
 *
 * INTERNAL: Available Dstart 44 to 47 Register
 */
union cavm_prach_abx_dstart_44_47
{
    uint64_t u;
    struct cavm_prach_abx_dstart_44_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_47             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 47th logical index */
        uint64_t dstart_46             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 46th logical index */
        uint64_t dstart_45             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 45th logical index */
        uint64_t dstart_44             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 44th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_44             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 44th logical index */
        uint64_t dstart_45             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 45th logical index */
        uint64_t dstart_46             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 46th logical index */
        uint64_t dstart_47             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_44_47_s cn; */
};
typedef union cavm_prach_abx_dstart_44_47 cavm_prach_abx_dstart_44_47_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_44_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_44_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002158ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002158ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_44_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_44_47(a) cavm_prach_abx_dstart_44_47_t
#define bustype_CAVM_PRACH_ABX_DSTART_44_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_44_47(a) "PRACH_ABX_DSTART_44_47"
#define busnum_CAVM_PRACH_ABX_DSTART_44_47(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_44_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_48_51
 *
 * INTERNAL: Available Dstart 48 to 51 Register
 */
union cavm_prach_abx_dstart_48_51
{
    uint64_t u;
    struct cavm_prach_abx_dstart_48_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_51             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 51th logical index */
        uint64_t dstart_50             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 50th logical index */
        uint64_t dstart_49             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 49th logical index */
        uint64_t dstart_48             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_48             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 48th logical index */
        uint64_t dstart_49             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 49th logical index */
        uint64_t dstart_50             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 50th logical index */
        uint64_t dstart_51             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 51th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_48_51_s cn; */
};
typedef union cavm_prach_abx_dstart_48_51 cavm_prach_abx_dstart_48_51_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_48_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_48_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002160ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002160ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_48_51", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_48_51(a) cavm_prach_abx_dstart_48_51_t
#define bustype_CAVM_PRACH_ABX_DSTART_48_51(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_48_51(a) "PRACH_ABX_DSTART_48_51"
#define busnum_CAVM_PRACH_ABX_DSTART_48_51(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_48_51(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_4_7
 *
 * INTERNAL: Available Dstart 4 to 7 Register
 */
union cavm_prach_abx_dstart_4_7
{
    uint64_t u;
    struct cavm_prach_abx_dstart_4_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_7              : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 7th logical index */
        uint64_t dstart_6              : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 6th logical index */
        uint64_t dstart_5              : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 5th logical index */
        uint64_t dstart_4              : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 4th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_4              : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 4th logical index */
        uint64_t dstart_5              : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 5th logical index */
        uint64_t dstart_6              : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 6th logical index */
        uint64_t dstart_7              : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 7th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_4_7_s cn; */
};
typedef union cavm_prach_abx_dstart_4_7 cavm_prach_abx_dstart_4_7_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_4_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_4_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002108ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002108ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_4_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_4_7(a) cavm_prach_abx_dstart_4_7_t
#define bustype_CAVM_PRACH_ABX_DSTART_4_7(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_4_7(a) "PRACH_ABX_DSTART_4_7"
#define busnum_CAVM_PRACH_ABX_DSTART_4_7(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_4_7(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_52_55
 *
 * INTERNAL: Available Dstart 52 to 55 Register
 */
union cavm_prach_abx_dstart_52_55
{
    uint64_t u;
    struct cavm_prach_abx_dstart_52_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_55             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 55th logical index */
        uint64_t dstart_54             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 54th logical index */
        uint64_t dstart_53             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 53th logical index */
        uint64_t dstart_52             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 52th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_52             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 52th logical index */
        uint64_t dstart_53             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 53th logical index */
        uint64_t dstart_54             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 54th logical index */
        uint64_t dstart_55             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 55th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_52_55_s cn; */
};
typedef union cavm_prach_abx_dstart_52_55 cavm_prach_abx_dstart_52_55_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_52_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_52_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002168ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002168ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_52_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_52_55(a) cavm_prach_abx_dstart_52_55_t
#define bustype_CAVM_PRACH_ABX_DSTART_52_55(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_52_55(a) "PRACH_ABX_DSTART_52_55"
#define busnum_CAVM_PRACH_ABX_DSTART_52_55(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_52_55(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_56_59
 *
 * INTERNAL: Available Dstart 56 to 59 Register
 */
union cavm_prach_abx_dstart_56_59
{
    uint64_t u;
    struct cavm_prach_abx_dstart_56_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_59             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 59th logical index */
        uint64_t dstart_58             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 58th logical index */
        uint64_t dstart_57             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 57th logical index */
        uint64_t dstart_56             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 56th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_56             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 56th logical index */
        uint64_t dstart_57             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 57th logical index */
        uint64_t dstart_58             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 58th logical index */
        uint64_t dstart_59             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 59th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_56_59_s cn; */
};
typedef union cavm_prach_abx_dstart_56_59 cavm_prach_abx_dstart_56_59_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_56_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_56_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002170ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002170ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_56_59", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_56_59(a) cavm_prach_abx_dstart_56_59_t
#define bustype_CAVM_PRACH_ABX_DSTART_56_59(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_56_59(a) "PRACH_ABX_DSTART_56_59"
#define busnum_CAVM_PRACH_ABX_DSTART_56_59(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_56_59(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_60_63
 *
 * INTERNAL: Available Dstart 60 to 63 Register
 */
union cavm_prach_abx_dstart_60_63
{
    uint64_t u;
    struct cavm_prach_abx_dstart_60_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_63             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 63th logical index */
        uint64_t dstart_62             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 62th logical index */
        uint64_t dstart_61             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 61th logical index */
        uint64_t dstart_60             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 60th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_60             : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 60th logical index */
        uint64_t dstart_61             : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 61th logical index */
        uint64_t dstart_62             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 62th logical index */
        uint64_t dstart_63             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_60_63_s cn; */
};
typedef union cavm_prach_abx_dstart_60_63 cavm_prach_abx_dstart_60_63_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_60_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_60_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002178ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002178ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_60_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_60_63(a) cavm_prach_abx_dstart_60_63_t
#define bustype_CAVM_PRACH_ABX_DSTART_60_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_60_63(a) "PRACH_ABX_DSTART_60_63"
#define busnum_CAVM_PRACH_ABX_DSTART_60_63(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_60_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_dstart_8_11
 *
 * INTERNAL: Available Dstart 8 to 11 Register
 */
union cavm_prach_abx_dstart_8_11
{
    uint64_t u;
    struct cavm_prach_abx_dstart_8_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dstart_11             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 11th logical index */
        uint64_t dstart_10             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 10th logical index */
        uint64_t dstart_9              : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 9th logical index */
        uint64_t dstart_8              : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 8th logical index */
#else /* Word 0 - Little Endian */
        uint64_t dstart_8              : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 8th logical index */
        uint64_t dstart_9              : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 9th logical index */
        uint64_t dstart_10             : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 10th logical index */
        uint64_t dstart_11             : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available Dstart. Of 11th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_dstart_8_11_s cn; */
};
typedef union cavm_prach_abx_dstart_8_11 cavm_prach_abx_dstart_8_11_t;

static inline uint64_t CAVM_PRACH_ABX_DSTART_8_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DSTART_8_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002110ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002110ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DSTART_8_11", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DSTART_8_11(a) cavm_prach_abx_dstart_8_11_t
#define bustype_CAVM_PRACH_ABX_DSTART_8_11(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DSTART_8_11(a) "PRACH_ABX_DSTART_8_11"
#define busnum_CAVM_PRACH_ABX_DSTART_8_11(a) (a)
#define arguments_CAVM_PRACH_ABX_DSTART_8_11(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_0_3
 *
 * INTERNAL: Available Du 0 to 3 Register
 */
union cavm_prach_abx_du_0_3
{
    uint64_t u;
    struct cavm_prach_abx_du_0_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_3                  : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du Of 4th logical index */
        uint64_t du_2                  : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du Of 3rd logical index */
        uint64_t du_1                  : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du Of 2nd logical index */
        uint64_t du_0                  : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_0                  : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du Of start logical index */
        uint64_t du_1                  : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du Of 2nd logical index */
        uint64_t du_2                  : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du Of 3rd logical index */
        uint64_t du_3                  : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du Of 4th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_0_3_s cn; */
};
typedef union cavm_prach_abx_du_0_3 cavm_prach_abx_du_0_3_t;

static inline uint64_t CAVM_PRACH_ABX_DU_0_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_0_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002340ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002340ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_0_3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_0_3(a) cavm_prach_abx_du_0_3_t
#define bustype_CAVM_PRACH_ABX_DU_0_3(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_0_3(a) "PRACH_ABX_DU_0_3"
#define busnum_CAVM_PRACH_ABX_DU_0_3(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_0_3(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_12_15
 *
 * INTERNAL: Available Du 12 to 15 Register
 */
union cavm_prach_abx_du_12_15
{
    uint64_t u;
    struct cavm_prach_abx_du_12_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_15                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 15th logical index */
        uint64_t du_14                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 14th logical index */
        uint64_t du_13                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 13th logical index */
        uint64_t du_12                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 12th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_12                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 12th logical index */
        uint64_t du_13                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 13th logical index */
        uint64_t du_14                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 14th logical index */
        uint64_t du_15                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 15th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_12_15_s cn; */
};
typedef union cavm_prach_abx_du_12_15 cavm_prach_abx_du_12_15_t;

static inline uint64_t CAVM_PRACH_ABX_DU_12_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_12_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002358ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002358ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_12_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_12_15(a) cavm_prach_abx_du_12_15_t
#define bustype_CAVM_PRACH_ABX_DU_12_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_12_15(a) "PRACH_ABX_DU_12_15"
#define busnum_CAVM_PRACH_ABX_DU_12_15(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_12_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_16_19
 *
 * INTERNAL: Available Du 16 to 19 Register
 */
union cavm_prach_abx_du_16_19
{
    uint64_t u;
    struct cavm_prach_abx_du_16_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_19                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 19th logical index */
        uint64_t du_18                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 18th logical index */
        uint64_t du_17                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 17th logical index */
        uint64_t du_16                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_16                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 16th logical index */
        uint64_t du_17                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 17th logical index */
        uint64_t du_18                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 18th logical index */
        uint64_t du_19                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 19th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_16_19_s cn; */
};
typedef union cavm_prach_abx_du_16_19 cavm_prach_abx_du_16_19_t;

static inline uint64_t CAVM_PRACH_ABX_DU_16_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_16_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002360ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002360ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_16_19", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_16_19(a) cavm_prach_abx_du_16_19_t
#define bustype_CAVM_PRACH_ABX_DU_16_19(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_16_19(a) "PRACH_ABX_DU_16_19"
#define busnum_CAVM_PRACH_ABX_DU_16_19(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_16_19(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_20_23
 *
 * INTERNAL: Available Du 20 to 23 Register
 */
union cavm_prach_abx_du_20_23
{
    uint64_t u;
    struct cavm_prach_abx_du_20_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_23                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 23th logical index */
        uint64_t du_22                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 22th logical index */
        uint64_t du_21                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 21th logical index */
        uint64_t du_20                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 20th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_20                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 20th logical index */
        uint64_t du_21                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 21th logical index */
        uint64_t du_22                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 22th logical index */
        uint64_t du_23                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 23th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_20_23_s cn; */
};
typedef union cavm_prach_abx_du_20_23 cavm_prach_abx_du_20_23_t;

static inline uint64_t CAVM_PRACH_ABX_DU_20_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_20_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002368ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002368ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_20_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_20_23(a) cavm_prach_abx_du_20_23_t
#define bustype_CAVM_PRACH_ABX_DU_20_23(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_20_23(a) "PRACH_ABX_DU_20_23"
#define busnum_CAVM_PRACH_ABX_DU_20_23(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_20_23(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_24_27
 *
 * INTERNAL: Available Du 24 to 27 Register
 */
union cavm_prach_abx_du_24_27
{
    uint64_t u;
    struct cavm_prach_abx_du_24_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_27                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 27th logical index */
        uint64_t du_26                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 26th logical index */
        uint64_t du_25                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 25th logical index */
        uint64_t du_24                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 24th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_24                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 24th logical index */
        uint64_t du_25                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 25th logical index */
        uint64_t du_26                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 26th logical index */
        uint64_t du_27                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 27th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_24_27_s cn; */
};
typedef union cavm_prach_abx_du_24_27 cavm_prach_abx_du_24_27_t;

static inline uint64_t CAVM_PRACH_ABX_DU_24_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_24_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002370ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002370ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_24_27", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_24_27(a) cavm_prach_abx_du_24_27_t
#define bustype_CAVM_PRACH_ABX_DU_24_27(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_24_27(a) "PRACH_ABX_DU_24_27"
#define busnum_CAVM_PRACH_ABX_DU_24_27(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_24_27(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_28_31
 *
 * INTERNAL: Available Du 28 to 31 Register
 */
union cavm_prach_abx_du_28_31
{
    uint64_t u;
    struct cavm_prach_abx_du_28_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_31                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 31th logical index */
        uint64_t du_30                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 30th logical index */
        uint64_t du_29                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 29th logical index */
        uint64_t du_28                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 28th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_28                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 28th logical index */
        uint64_t du_29                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 29th logical index */
        uint64_t du_30                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 30th logical index */
        uint64_t du_31                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_28_31_s cn; */
};
typedef union cavm_prach_abx_du_28_31 cavm_prach_abx_du_28_31_t;

static inline uint64_t CAVM_PRACH_ABX_DU_28_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_28_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002378ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002378ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_28_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_28_31(a) cavm_prach_abx_du_28_31_t
#define bustype_CAVM_PRACH_ABX_DU_28_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_28_31(a) "PRACH_ABX_DU_28_31"
#define busnum_CAVM_PRACH_ABX_DU_28_31(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_28_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_32_35
 *
 * INTERNAL: Available Du 32 to 35 Register
 */
union cavm_prach_abx_du_32_35
{
    uint64_t u;
    struct cavm_prach_abx_du_32_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_35                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 35th logical index */
        uint64_t du_34                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 34th logical index */
        uint64_t du_33                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 33th logical index */
        uint64_t du_32                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_32                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 32th logical index */
        uint64_t du_33                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 33th logical index */
        uint64_t du_34                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 34th logical index */
        uint64_t du_35                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 35th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_32_35_s cn; */
};
typedef union cavm_prach_abx_du_32_35 cavm_prach_abx_du_32_35_t;

static inline uint64_t CAVM_PRACH_ABX_DU_32_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_32_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002380ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002380ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_32_35", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_32_35(a) cavm_prach_abx_du_32_35_t
#define bustype_CAVM_PRACH_ABX_DU_32_35(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_32_35(a) "PRACH_ABX_DU_32_35"
#define busnum_CAVM_PRACH_ABX_DU_32_35(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_32_35(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_36_39
 *
 * INTERNAL: Available Du 36 to 39 Register
 */
union cavm_prach_abx_du_36_39
{
    uint64_t u;
    struct cavm_prach_abx_du_36_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_39                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 39th logical index */
        uint64_t du_38                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 38th logical index */
        uint64_t du_37                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 37th logical index */
        uint64_t du_36                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 36th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_36                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 36th logical index */
        uint64_t du_37                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 37th logical index */
        uint64_t du_38                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 38th logical index */
        uint64_t du_39                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 39th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_36_39_s cn; */
};
typedef union cavm_prach_abx_du_36_39 cavm_prach_abx_du_36_39_t;

static inline uint64_t CAVM_PRACH_ABX_DU_36_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_36_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002388ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002388ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_36_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_36_39(a) cavm_prach_abx_du_36_39_t
#define bustype_CAVM_PRACH_ABX_DU_36_39(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_36_39(a) "PRACH_ABX_DU_36_39"
#define busnum_CAVM_PRACH_ABX_DU_36_39(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_36_39(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_40_43
 *
 * INTERNAL: Available Du 40 to 43 Register
 */
union cavm_prach_abx_du_40_43
{
    uint64_t u;
    struct cavm_prach_abx_du_40_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_43                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 43th logical index */
        uint64_t du_42                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 42th logical index */
        uint64_t du_41                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 41th logical index */
        uint64_t du_40                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 40th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_40                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 40th logical index */
        uint64_t du_41                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 41th logical index */
        uint64_t du_42                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 42th logical index */
        uint64_t du_43                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 43th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_40_43_s cn; */
};
typedef union cavm_prach_abx_du_40_43 cavm_prach_abx_du_40_43_t;

static inline uint64_t CAVM_PRACH_ABX_DU_40_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_40_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002390ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002390ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_40_43", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_40_43(a) cavm_prach_abx_du_40_43_t
#define bustype_CAVM_PRACH_ABX_DU_40_43(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_40_43(a) "PRACH_ABX_DU_40_43"
#define busnum_CAVM_PRACH_ABX_DU_40_43(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_40_43(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_44_47
 *
 * INTERNAL: Available Du 44 to 47 Register
 */
union cavm_prach_abx_du_44_47
{
    uint64_t u;
    struct cavm_prach_abx_du_44_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_47                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 47th logical index */
        uint64_t du_46                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 46th logical index */
        uint64_t du_45                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 45th logical index */
        uint64_t du_44                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 44th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_44                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 44th logical index */
        uint64_t du_45                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 45th logical index */
        uint64_t du_46                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 46th logical index */
        uint64_t du_47                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_44_47_s cn; */
};
typedef union cavm_prach_abx_du_44_47 cavm_prach_abx_du_44_47_t;

static inline uint64_t CAVM_PRACH_ABX_DU_44_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_44_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002398ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002398ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_44_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_44_47(a) cavm_prach_abx_du_44_47_t
#define bustype_CAVM_PRACH_ABX_DU_44_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_44_47(a) "PRACH_ABX_DU_44_47"
#define busnum_CAVM_PRACH_ABX_DU_44_47(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_44_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_48_51
 *
 * INTERNAL: Available Du 48 to 51 Register
 */
union cavm_prach_abx_du_48_51
{
    uint64_t u;
    struct cavm_prach_abx_du_48_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_51                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 51th logical index */
        uint64_t du_50                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 50th logical index */
        uint64_t du_49                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 49th logical index */
        uint64_t du_48                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_48                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 48th logical index */
        uint64_t du_49                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 49th logical index */
        uint64_t du_50                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 50th logical index */
        uint64_t du_51                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 51th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_48_51_s cn; */
};
typedef union cavm_prach_abx_du_48_51 cavm_prach_abx_du_48_51_t;

static inline uint64_t CAVM_PRACH_ABX_DU_48_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_48_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430023a0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430023a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_48_51", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_48_51(a) cavm_prach_abx_du_48_51_t
#define bustype_CAVM_PRACH_ABX_DU_48_51(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_48_51(a) "PRACH_ABX_DU_48_51"
#define busnum_CAVM_PRACH_ABX_DU_48_51(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_48_51(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_4_7
 *
 * INTERNAL: Available Du 4 to 7 Register
 */
union cavm_prach_abx_du_4_7
{
    uint64_t u;
    struct cavm_prach_abx_du_4_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_7                  : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 7th logical index */
        uint64_t du_6                  : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 6th logical index */
        uint64_t du_5                  : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 5th logical index */
        uint64_t du_4                  : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 4th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_4                  : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 4th logical index */
        uint64_t du_5                  : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 5th logical index */
        uint64_t du_6                  : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 6th logical index */
        uint64_t du_7                  : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 7th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_4_7_s cn; */
};
typedef union cavm_prach_abx_du_4_7 cavm_prach_abx_du_4_7_t;

static inline uint64_t CAVM_PRACH_ABX_DU_4_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_4_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002348ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002348ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_4_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_4_7(a) cavm_prach_abx_du_4_7_t
#define bustype_CAVM_PRACH_ABX_DU_4_7(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_4_7(a) "PRACH_ABX_DU_4_7"
#define busnum_CAVM_PRACH_ABX_DU_4_7(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_4_7(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_52_55
 *
 * INTERNAL: Available Du 52 to 55 Register
 */
union cavm_prach_abx_du_52_55
{
    uint64_t u;
    struct cavm_prach_abx_du_52_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_55                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 55th logical index */
        uint64_t du_54                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 54th logical index */
        uint64_t du_53                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 53th logical index */
        uint64_t du_52                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 52th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_52                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 52th logical index */
        uint64_t du_53                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 53th logical index */
        uint64_t du_54                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 54th logical index */
        uint64_t du_55                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 55th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_52_55_s cn; */
};
typedef union cavm_prach_abx_du_52_55 cavm_prach_abx_du_52_55_t;

static inline uint64_t CAVM_PRACH_ABX_DU_52_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_52_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430023a8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430023a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_52_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_52_55(a) cavm_prach_abx_du_52_55_t
#define bustype_CAVM_PRACH_ABX_DU_52_55(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_52_55(a) "PRACH_ABX_DU_52_55"
#define busnum_CAVM_PRACH_ABX_DU_52_55(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_52_55(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_56_59
 *
 * INTERNAL: Available Du 56 to 59 Register
 */
union cavm_prach_abx_du_56_59
{
    uint64_t u;
    struct cavm_prach_abx_du_56_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_59                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 59th logical index */
        uint64_t du_58                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 58th logical index */
        uint64_t du_57                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 57th logical index */
        uint64_t du_56                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 56th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_56                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 56th logical index */
        uint64_t du_57                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 57th logical index */
        uint64_t du_58                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 58th logical index */
        uint64_t du_59                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 59th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_56_59_s cn; */
};
typedef union cavm_prach_abx_du_56_59 cavm_prach_abx_du_56_59_t;

static inline uint64_t CAVM_PRACH_ABX_DU_56_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_56_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430023b0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430023b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_56_59", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_56_59(a) cavm_prach_abx_du_56_59_t
#define bustype_CAVM_PRACH_ABX_DU_56_59(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_56_59(a) "PRACH_ABX_DU_56_59"
#define busnum_CAVM_PRACH_ABX_DU_56_59(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_56_59(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_60_63
 *
 * INTERNAL: Available Du 60 to 63 Register
 */
union cavm_prach_abx_du_60_63
{
    uint64_t u;
    struct cavm_prach_abx_du_60_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_63                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 63th logical index */
        uint64_t du_62                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 62th logical index */
        uint64_t du_61                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 61th logical index */
        uint64_t du_60                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 60th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_60                 : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 60th logical index */
        uint64_t du_61                 : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 61th logical index */
        uint64_t du_62                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 62th logical index */
        uint64_t du_63                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_60_63_s cn; */
};
typedef union cavm_prach_abx_du_60_63 cavm_prach_abx_du_60_63_t;

static inline uint64_t CAVM_PRACH_ABX_DU_60_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_60_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430023b8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430023b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_60_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_60_63(a) cavm_prach_abx_du_60_63_t
#define bustype_CAVM_PRACH_ABX_DU_60_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_60_63(a) "PRACH_ABX_DU_60_63"
#define busnum_CAVM_PRACH_ABX_DU_60_63(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_60_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_du_8_11
 *
 * INTERNAL: Available Du 8 to 11 Register
 */
union cavm_prach_abx_du_8_11
{
    uint64_t u;
    struct cavm_prach_abx_du_8_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t du_11                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 11th logical index */
        uint64_t du_10                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 10th logical index */
        uint64_t du_9                  : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 9th logical index */
        uint64_t du_8                  : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 8th logical index */
#else /* Word 0 - Little Endian */
        uint64_t du_8                  : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~838)) Available Du. Of 8th logical index */
        uint64_t du_9                  : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~838)) Available Du. Of 9th logical index */
        uint64_t du_10                 : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~838)) Available Du. Of 10th logical index */
        uint64_t du_11                 : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~838)) Available Du. Of 11th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_du_8_11_s cn; */
};
typedef union cavm_prach_abx_du_8_11 cavm_prach_abx_du_8_11_t;

static inline uint64_t CAVM_PRACH_ABX_DU_8_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_DU_8_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002350ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002350ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_DU_8_11", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_DU_8_11(a) cavm_prach_abx_du_8_11_t
#define bustype_CAVM_PRACH_ABX_DU_8_11(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_DU_8_11(a) "PRACH_ABX_DU_8_11"
#define busnum_CAVM_PRACH_ABX_DU_8_11(a) (a)
#define arguments_CAVM_PRACH_ABX_DU_8_11(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_err_enable_0
 *
 * Error Enable Register 0
 */
union cavm_prach_abx_err_enable_0
{
    uint64_t u;
    struct cavm_prach_abx_err_enable_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t rd_port_0_ovf         : 1;  /**< [  4:  4](R/W) Error enable (Read port0 overflow)
                                                                 0 = not enabled (default), 1 = enabled */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_port_0_unf         : 1;  /**< [  0:  0](R/W) Error enable (Read port0 underflow)
                                                                 0 = not enabled (default), 1 = enabled */
#else /* Word 0 - Little Endian */
        uint64_t rd_port_0_unf         : 1;  /**< [  0:  0](R/W) Error enable (Read port0 underflow)
                                                                 0 = not enabled (default), 1 = enabled */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_port_0_ovf         : 1;  /**< [  4:  4](R/W) Error enable (Read port0 overflow)
                                                                 0 = not enabled (default), 1 = enabled */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_err_enable_0_s cnf95xx; */
    struct cavm_prach_abx_err_enable_0_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t rd_port_0_ovf         : 1;  /**< [  4:  4](R/W) Error enable (read port 0 overflow).
                                                                  0 = Not enabled (default).
                                                                  1 = Enabled */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_port_0_unf         : 1;  /**< [  0:  0](R/W) Error enable (read port 0 underflow).
                                                                   0 = Not enabled (default).
                                                                   1 = Enabled. */
#else /* Word 0 - Little Endian */
        uint64_t rd_port_0_unf         : 1;  /**< [  0:  0](R/W) Error enable (read port 0 underflow).
                                                                   0 = Not enabled (default).
                                                                   1 = Enabled. */
        uint64_t reserved_1_3          : 3;
        uint64_t rd_port_0_ovf         : 1;  /**< [  4:  4](R/W) Error enable (read port 0 overflow).
                                                                  0 = Not enabled (default).
                                                                  1 = Enabled */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_prach_abx_err_enable_0 cavm_prach_abx_err_enable_0_t;

static inline uint64_t CAVM_PRACH_ABX_ERR_ENABLE_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_ERR_ENABLE_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043000040ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043000040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_ERR_ENABLE_0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_ERR_ENABLE_0(a) cavm_prach_abx_err_enable_0_t
#define bustype_CAVM_PRACH_ABX_ERR_ENABLE_0(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_ERR_ENABLE_0(a) "PRACH_ABX_ERR_ENABLE_0"
#define busnum_CAVM_PRACH_ABX_ERR_ENABLE_0(a) (a)
#define arguments_CAVM_PRACH_ABX_ERR_ENABLE_0(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_err_enable_1
 *
 * Error Enable Register 1
 */
union cavm_prach_abx_err_enable_1
{
    uint64_t u;
    struct cavm_prach_abx_err_enable_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Error enable, 0 = not enabled (default), 1 = enabled */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Error enable, 0 = not enabled (default), 1 = enabled */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_err_enable_1_s cnf95xx; */
    struct cavm_prach_abx_err_enable_1_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Error enable.
                                                                   0 = Not enabled (default).
                                                                   1 = Enabled. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Error enable.
                                                                   0 = Not enabled (default).
                                                                   1 = Enabled. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_prach_abx_err_enable_1 cavm_prach_abx_err_enable_1_t;

static inline uint64_t CAVM_PRACH_ABX_ERR_ENABLE_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_ERR_ENABLE_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043000048ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043000048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_ERR_ENABLE_1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_ERR_ENABLE_1(a) cavm_prach_abx_err_enable_1_t
#define bustype_CAVM_PRACH_ABX_ERR_ENABLE_1(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_ERR_ENABLE_1(a) "PRACH_ABX_ERR_ENABLE_1"
#define busnum_CAVM_PRACH_ABX_ERR_ENABLE_1(a) (a)
#define arguments_CAVM_PRACH_ABX_ERR_ENABLE_1(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_err_src
 *
 * Error Source Register
 */
union cavm_prach_abx_err_src
{
    uint64_t u;
    struct cavm_prach_abx_err_src_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rd_ovf_unf_id2        : 16; /**< [ 63: 48](R/W1C) Read port overflow/underflow job ID 2 (optional) */
        uint64_t rd_ovf_unf_id1        : 16; /**< [ 47: 32](R/W1C) Read port overflow/underflow job ID 1 (optional) */
        uint64_t rd_ovf_unf_id0        : 16; /**< [ 31: 16](R/W1C) Read port overflow/underflow job ID 0 */
        uint64_t reserved_8_15         : 8;
        uint64_t rd_port_3_ovf         : 1;  /**< [  7:  7](R/W1C) Read port3 overflow (optional) */
        uint64_t rd_port_2_ovf         : 1;  /**< [  6:  6](R/W1C) Read port2 overflow (optional) */
        uint64_t rd_port_1_ovf         : 1;  /**< [  5:  5](R/W1C) Read port1 overflow (optional) */
        uint64_t rd_port_0_ovf         : 1;  /**< [  4:  4](R/W1C) Read port0 overflow */
        uint64_t rd_port_3_unf         : 1;  /**< [  3:  3](R/W1C) Read port3 underflow (optional) */
        uint64_t rd_port_2_unf         : 1;  /**< [  2:  2](R/W1C) Read port2 underflow (optional) */
        uint64_t rd_port_1_unf         : 1;  /**< [  1:  1](R/W1C) Read port1 underflow (optional) */
        uint64_t rd_port_0_unf         : 1;  /**< [  0:  0](R/W1C) Read port0 underflow */
#else /* Word 0 - Little Endian */
        uint64_t rd_port_0_unf         : 1;  /**< [  0:  0](R/W1C) Read port0 underflow */
        uint64_t rd_port_1_unf         : 1;  /**< [  1:  1](R/W1C) Read port1 underflow (optional) */
        uint64_t rd_port_2_unf         : 1;  /**< [  2:  2](R/W1C) Read port2 underflow (optional) */
        uint64_t rd_port_3_unf         : 1;  /**< [  3:  3](R/W1C) Read port3 underflow (optional) */
        uint64_t rd_port_0_ovf         : 1;  /**< [  4:  4](R/W1C) Read port0 overflow */
        uint64_t rd_port_1_ovf         : 1;  /**< [  5:  5](R/W1C) Read port1 overflow (optional) */
        uint64_t rd_port_2_ovf         : 1;  /**< [  6:  6](R/W1C) Read port2 overflow (optional) */
        uint64_t rd_port_3_ovf         : 1;  /**< [  7:  7](R/W1C) Read port3 overflow (optional) */
        uint64_t reserved_8_15         : 8;
        uint64_t rd_ovf_unf_id0        : 16; /**< [ 31: 16](R/W1C) Read port overflow/underflow job ID 0 */
        uint64_t rd_ovf_unf_id1        : 16; /**< [ 47: 32](R/W1C) Read port overflow/underflow job ID 1 (optional) */
        uint64_t rd_ovf_unf_id2        : 16; /**< [ 63: 48](R/W1C) Read port overflow/underflow job ID 2 (optional) */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_err_src_s cnf95xx; */
    struct cavm_prach_abx_err_src_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rd_ovf_unf_id2        : 16; /**< [ 63: 48](R/W1C) Read port overflow/underflow job ID 2 (optional). */
        uint64_t rd_ovf_unf_id1        : 16; /**< [ 47: 32](R/W1C) Read port overflow/underflow job ID 1 (optional). */
        uint64_t rd_ovf_unf_id0        : 16; /**< [ 31: 16](R/W1C) Read port overflow/underflow job ID 0. */
        uint64_t reserved_8_15         : 8;
        uint64_t rd_port_3_ovf         : 1;  /**< [  7:  7](R/W1C) Read port3 overflow (optional). */
        uint64_t rd_port_2_ovf         : 1;  /**< [  6:  6](R/W1C) Read port2 overflow (optional). */
        uint64_t rd_port_1_ovf         : 1;  /**< [  5:  5](R/W1C) Read port1 overflow (optional). */
        uint64_t rd_port_0_ovf         : 1;  /**< [  4:  4](R/W1C) Read port0 overflow. */
        uint64_t rd_port_3_unf         : 1;  /**< [  3:  3](R/W1C) Read port3 underflow (optional). */
        uint64_t rd_port_2_unf         : 1;  /**< [  2:  2](R/W1C) Read port2 underflow (optional). */
        uint64_t rd_port_1_unf         : 1;  /**< [  1:  1](R/W1C) Read port1 underflow (optional). */
        uint64_t rd_port_0_unf         : 1;  /**< [  0:  0](R/W1C) Read port0 underflow. */
#else /* Word 0 - Little Endian */
        uint64_t rd_port_0_unf         : 1;  /**< [  0:  0](R/W1C) Read port0 underflow. */
        uint64_t rd_port_1_unf         : 1;  /**< [  1:  1](R/W1C) Read port1 underflow (optional). */
        uint64_t rd_port_2_unf         : 1;  /**< [  2:  2](R/W1C) Read port2 underflow (optional). */
        uint64_t rd_port_3_unf         : 1;  /**< [  3:  3](R/W1C) Read port3 underflow (optional). */
        uint64_t rd_port_0_ovf         : 1;  /**< [  4:  4](R/W1C) Read port0 overflow. */
        uint64_t rd_port_1_ovf         : 1;  /**< [  5:  5](R/W1C) Read port1 overflow (optional). */
        uint64_t rd_port_2_ovf         : 1;  /**< [  6:  6](R/W1C) Read port2 overflow (optional). */
        uint64_t rd_port_3_ovf         : 1;  /**< [  7:  7](R/W1C) Read port3 overflow (optional). */
        uint64_t reserved_8_15         : 8;
        uint64_t rd_ovf_unf_id0        : 16; /**< [ 31: 16](R/W1C) Read port overflow/underflow job ID 0. */
        uint64_t rd_ovf_unf_id1        : 16; /**< [ 47: 32](R/W1C) Read port overflow/underflow job ID 1 (optional). */
        uint64_t rd_ovf_unf_id2        : 16; /**< [ 63: 48](R/W1C) Read port overflow/underflow job ID 2 (optional). */
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_prach_abx_err_src cavm_prach_abx_err_src_t;

static inline uint64_t CAVM_PRACH_ABX_ERR_SRC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_ERR_SRC(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043000030ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043000030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_ERR_SRC", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_ERR_SRC(a) cavm_prach_abx_err_src_t
#define bustype_CAVM_PRACH_ABX_ERR_SRC(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_ERR_SRC(a) "PRACH_ABX_ERR_SRC"
#define busnum_CAVM_PRACH_ABX_ERR_SRC(a) (a)
#define arguments_CAVM_PRACH_ABX_ERR_SRC(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_hab_config
 *
 * INTERNAL: HAB Configuration Register
 *
 * Contains AB specific control and configuration information set 0
 */
union cavm_prach_abx_hab_config
{
    uint64_t u;
    struct cavm_prach_abx_hab_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t job_config            : 3;  /**< [  2:  0](R/W) "Job definition
                                                                 0 : Normal job.
                                                                 - legacy LTE support (2R, 4R, 8R),
                                                                 - NR support (2R, 4R, 8R)
                                                                 1: eMTC start job
                                                                 first repetition preamble input process for eMTC or 16R, 24R, 32R or ant#0 ~
                                                                 ant#7 preamble input process (16R case)
                                                                 -\> IFFT power transmission by write I/F for combine
                                                                 2: eMTC correlation job
                                                                 2nd ~ (final-1) repertition preamble input process
                                                                 -\> IFFT power receiving by read I/F for combine
                                                                 -\> IFFT power transmission by write I/F for combine
                                                                 3: eMTC peak detection job
                                                                 final repertition preamble input process or ant#8 ~ ant#15 preamble input process (16R case)
                                                                 -\> IFFT power receiving by read I/F for combine
                                                                 -\> IFFT power transmission by write I/F for combine
                                                                 -\> peak detection result report by write I/F" */
#else /* Word 0 - Little Endian */
        uint64_t job_config            : 3;  /**< [  2:  0](R/W) "Job definition
                                                                 0 : Normal job.
                                                                 - legacy LTE support (2R, 4R, 8R),
                                                                 - NR support (2R, 4R, 8R)
                                                                 1: eMTC start job
                                                                 first repetition preamble input process for eMTC or 16R, 24R, 32R or ant#0 ~
                                                                 ant#7 preamble input process (16R case)
                                                                 -\> IFFT power transmission by write I/F for combine
                                                                 2: eMTC correlation job
                                                                 2nd ~ (final-1) repertition preamble input process
                                                                 -\> IFFT power receiving by read I/F for combine
                                                                 -\> IFFT power transmission by write I/F for combine
                                                                 3: eMTC peak detection job
                                                                 final repertition preamble input process or ant#8 ~ ant#15 preamble input process (16R case)
                                                                 -\> IFFT power receiving by read I/F for combine
                                                                 -\> IFFT power transmission by write I/F for combine
                                                                 -\> peak detection result report by write I/F" */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_hab_config_s cnf95xx; */
    struct cavm_prach_abx_hab_config_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t job_config            : 3;  /**< [  2:  0](R/W) Job definition.
                                                                 0 = Normal job. LTE support (2R, 4R, 8R), NR support (2R, 4R, 8R).
                                                                 1 = eMTC start job. First repetition preamble input process for eMTC or 16R,
                                                                 24R, 32R or antenna 0-7 preamble input process (16R case). IFFT power
                                                                 transmission by write DMA for combine.
                                                                 2 = eMTC correlation job.  2nd to (final-1) repetition preamble input process.
                                                                   o IFFT power receiving by read DMA for combine.
                                                                   o IFFT power transmission by write DMA for combine.
                                                                 3 = eMTC peak detection job. Final repertition preamble input process or antenna
                                                                 8-15 preamble input process (16R case).
                                                                   o IFFT power receiving by read DMA for combine.
                                                                   o IFFT power transmission by write DMA for combine.
                                                                   o Peak detection result report by write DMA. */
#else /* Word 0 - Little Endian */
        uint64_t job_config            : 3;  /**< [  2:  0](R/W) Job definition.
                                                                 0 = Normal job. LTE support (2R, 4R, 8R), NR support (2R, 4R, 8R).
                                                                 1 = eMTC start job. First repetition preamble input process for eMTC or 16R,
                                                                 24R, 32R or antenna 0-7 preamble input process (16R case). IFFT power
                                                                 transmission by write DMA for combine.
                                                                 2 = eMTC correlation job.  2nd to (final-1) repetition preamble input process.
                                                                   o IFFT power receiving by read DMA for combine.
                                                                   o IFFT power transmission by write DMA for combine.
                                                                 3 = eMTC peak detection job. Final repertition preamble input process or antenna
                                                                 8-15 preamble input process (16R case).
                                                                   o IFFT power receiving by read DMA for combine.
                                                                   o IFFT power transmission by write DMA for combine.
                                                                   o Peak detection result report by write DMA. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_prach_abx_hab_config cavm_prach_abx_hab_config_t;

static inline uint64_t CAVM_PRACH_ABX_HAB_CONFIG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_HAB_CONFIG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002000ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_HAB_CONFIG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_HAB_CONFIG(a) cavm_prach_abx_hab_config_t
#define bustype_CAVM_PRACH_ABX_HAB_CONFIG(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_HAB_CONFIG(a) "PRACH_ABX_HAB_CONFIG"
#define busnum_CAVM_PRACH_ABX_HAB_CONFIG(a) (a)
#define arguments_CAVM_PRACH_ABX_HAB_CONFIG(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_hab_status
 *
 * HAB Status Register
 */
union cavm_prach_abx_hab_status
{
    uint64_t u;
    struct cavm_prach_abx_hab_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t status                : 1;  /**< [  0:  0](RO) Indicates if the HAB is busy processing a job with CONFIGURATION 0.
                                                                 0 = ready (default), 1 = busy */
#else /* Word 0 - Little Endian */
        uint64_t status                : 1;  /**< [  0:  0](RO) Indicates if the HAB is busy processing a job with CONFIGURATION 0.
                                                                 0 = ready (default), 1 = busy */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_hab_status_s cnf95xx; */
    struct cavm_prach_abx_hab_status_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t status                : 1;  /**< [  0:  0](RO) Indicates if the PRCH HAB is busy processing a job with CONFIGURATION 0.
                                                                 0 = Ready (default).
                                                                 1 = Busy. */
#else /* Word 0 - Little Endian */
        uint64_t status                : 1;  /**< [  0:  0](RO) Indicates if the PRCH HAB is busy processing a job with CONFIGURATION 0.
                                                                 0 = Ready (default).
                                                                 1 = Busy. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_prach_abx_hab_status cavm_prach_abx_hab_status_t;

static inline uint64_t CAVM_PRACH_ABX_HAB_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_HAB_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043000018ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043000018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_HAB_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_HAB_STATUS(a) cavm_prach_abx_hab_status_t
#define bustype_CAVM_PRACH_ABX_HAB_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_HAB_STATUS(a) "PRACH_ABX_HAB_STATUS"
#define busnum_CAVM_PRACH_ABX_HAB_STATUS(a) (a)
#define arguments_CAVM_PRACH_ABX_HAB_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_0_3
 *
 * INTERNAL: Available Logical Index 0 to 3 Register
 */
union cavm_prach_abx_logical_idx_0_3
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_0_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_3       : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 4th logical index */
        uint64_t logical_index_2       : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 3rd logical index */
        uint64_t logical_index_1       : 16; /**< [ 31: 16](R/W) (6'0, 10'd(0~837)) Available logical_index. Of 2nd logical index */
        uint64_t logical_index_0       : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_0       : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of start logical index */
        uint64_t logical_index_1       : 16; /**< [ 31: 16](R/W) (6'0, 10'd(0~837)) Available logical_index. Of 2nd logical index */
        uint64_t logical_index_2       : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 3rd logical index */
        uint64_t logical_index_3       : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 4th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_0_3_s cn; */
};
typedef union cavm_prach_abx_logical_idx_0_3 cavm_prach_abx_logical_idx_0_3_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_0_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_0_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002040ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_0_3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_0_3(a) cavm_prach_abx_logical_idx_0_3_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_0_3(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_0_3(a) "PRACH_ABX_LOGICAL_IDX_0_3"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_0_3(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_0_3(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_12_15
 *
 * INTERNAL: Available Logical Index 12 to 15 Register
 */
union cavm_prach_abx_logical_idx_12_15
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_12_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_15      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 15th logical index */
        uint64_t logical_index_14      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 14th logical index */
        uint64_t logical_index_13      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 13th logical index */
        uint64_t logical_index_12      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 12th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_12      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 12th logical index */
        uint64_t logical_index_13      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 13th logical index */
        uint64_t logical_index_14      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 14th logical index */
        uint64_t logical_index_15      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 15th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_12_15_s cn; */
};
typedef union cavm_prach_abx_logical_idx_12_15 cavm_prach_abx_logical_idx_12_15_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_12_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_12_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002058ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002058ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_12_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_12_15(a) cavm_prach_abx_logical_idx_12_15_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_12_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_12_15(a) "PRACH_ABX_LOGICAL_IDX_12_15"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_12_15(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_12_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_16_19
 *
 * INTERNAL: Available Logical Index 16 to 19 Register
 */
union cavm_prach_abx_logical_idx_16_19
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_16_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_19      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 19th logical index */
        uint64_t logical_index_18      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 18th logical index */
        uint64_t logical_index_17      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 17th logical index */
        uint64_t logical_index_16      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_16      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 16th logical index */
        uint64_t logical_index_17      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 17th logical index */
        uint64_t logical_index_18      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 18th logical index */
        uint64_t logical_index_19      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 19th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_16_19_s cn; */
};
typedef union cavm_prach_abx_logical_idx_16_19 cavm_prach_abx_logical_idx_16_19_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_16_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_16_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002060ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002060ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_16_19", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_16_19(a) cavm_prach_abx_logical_idx_16_19_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_16_19(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_16_19(a) "PRACH_ABX_LOGICAL_IDX_16_19"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_16_19(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_16_19(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_20_23
 *
 * INTERNAL: Available Logical Index 20 to 23 Register
 */
union cavm_prach_abx_logical_idx_20_23
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_20_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_23      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 23th logical index */
        uint64_t logical_index_22      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 22th logical index */
        uint64_t logical_index_21      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 21th logical index */
        uint64_t logical_index_20      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 20th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_20      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 20th logical index */
        uint64_t logical_index_21      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 21th logical index */
        uint64_t logical_index_22      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 22th logical index */
        uint64_t logical_index_23      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 23th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_20_23_s cn; */
};
typedef union cavm_prach_abx_logical_idx_20_23 cavm_prach_abx_logical_idx_20_23_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_20_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_20_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002068ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002068ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_20_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_20_23(a) cavm_prach_abx_logical_idx_20_23_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_20_23(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_20_23(a) "PRACH_ABX_LOGICAL_IDX_20_23"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_20_23(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_20_23(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_24_27
 *
 * INTERNAL: Available Logical Index 24 to 27 Register
 */
union cavm_prach_abx_logical_idx_24_27
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_24_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_27      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 27th logical index */
        uint64_t logical_index_26      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 26th logical index */
        uint64_t logical_index_25      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 25th logical index */
        uint64_t logical_index_24      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 24th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_24      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 24th logical index */
        uint64_t logical_index_25      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 25th logical index */
        uint64_t logical_index_26      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 26th logical index */
        uint64_t logical_index_27      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 27th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_24_27_s cn; */
};
typedef union cavm_prach_abx_logical_idx_24_27 cavm_prach_abx_logical_idx_24_27_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_24_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_24_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002070ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002070ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_24_27", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_24_27(a) cavm_prach_abx_logical_idx_24_27_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_24_27(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_24_27(a) "PRACH_ABX_LOGICAL_IDX_24_27"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_24_27(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_24_27(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_28_31
 *
 * INTERNAL: Available Logical Index 28 to 31 Register
 */
union cavm_prach_abx_logical_idx_28_31
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_28_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_31      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 31th logical index */
        uint64_t logical_index_30      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 30th logical index */
        uint64_t logical_index_29      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 29th logical index */
        uint64_t logical_index_28      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 28th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_28      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 28th logical index */
        uint64_t logical_index_29      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 29th logical index */
        uint64_t logical_index_30      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 30th logical index */
        uint64_t logical_index_31      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_28_31_s cn; */
};
typedef union cavm_prach_abx_logical_idx_28_31 cavm_prach_abx_logical_idx_28_31_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_28_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_28_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002078ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002078ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_28_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_28_31(a) cavm_prach_abx_logical_idx_28_31_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_28_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_28_31(a) "PRACH_ABX_LOGICAL_IDX_28_31"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_28_31(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_28_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_32_35
 *
 * INTERNAL: Available Logical Index 32 to 35 Register
 */
union cavm_prach_abx_logical_idx_32_35
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_32_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_35      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 35th logical index */
        uint64_t logical_index_34      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 34th logical index */
        uint64_t logical_index_33      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 33th logical index */
        uint64_t logical_index_32      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_32      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 32th logical index */
        uint64_t logical_index_33      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 33th logical index */
        uint64_t logical_index_34      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 34th logical index */
        uint64_t logical_index_35      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 35th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_32_35_s cn; */
};
typedef union cavm_prach_abx_logical_idx_32_35 cavm_prach_abx_logical_idx_32_35_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_32_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_32_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002080ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002080ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_32_35", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_32_35(a) cavm_prach_abx_logical_idx_32_35_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_32_35(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_32_35(a) "PRACH_ABX_LOGICAL_IDX_32_35"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_32_35(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_32_35(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_36_39
 *
 * INTERNAL: Available Logical Index 36 to 39 Register
 */
union cavm_prach_abx_logical_idx_36_39
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_36_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_39      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 39th logical index */
        uint64_t logical_index_38      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 38th logical index */
        uint64_t logical_index_37      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 37th logical index */
        uint64_t logical_index_36      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 36th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_36      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 36th logical index */
        uint64_t logical_index_37      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 37th logical index */
        uint64_t logical_index_38      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 38th logical index */
        uint64_t logical_index_39      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 39th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_36_39_s cn; */
};
typedef union cavm_prach_abx_logical_idx_36_39 cavm_prach_abx_logical_idx_36_39_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_36_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_36_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002088ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002088ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_36_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_36_39(a) cavm_prach_abx_logical_idx_36_39_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_36_39(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_36_39(a) "PRACH_ABX_LOGICAL_IDX_36_39"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_36_39(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_36_39(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_40_43
 *
 * INTERNAL: Available Logical Index 40 to 43 Register
 */
union cavm_prach_abx_logical_idx_40_43
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_40_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_43      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 43th logical index */
        uint64_t logical_index_42      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 42th logical index */
        uint64_t logical_index_41      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 41th logical index */
        uint64_t logical_index_40      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 40th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_40      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 40th logical index */
        uint64_t logical_index_41      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 41th logical index */
        uint64_t logical_index_42      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 42th logical index */
        uint64_t logical_index_43      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 43th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_40_43_s cn; */
};
typedef union cavm_prach_abx_logical_idx_40_43 cavm_prach_abx_logical_idx_40_43_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_40_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_40_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002090ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002090ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_40_43", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_40_43(a) cavm_prach_abx_logical_idx_40_43_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_40_43(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_40_43(a) "PRACH_ABX_LOGICAL_IDX_40_43"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_40_43(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_40_43(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_44_47
 *
 * INTERNAL: Available Logical Index 44 to 47 Register
 */
union cavm_prach_abx_logical_idx_44_47
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_44_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_47      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 47th logical index */
        uint64_t logical_index_46      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 46th logical index */
        uint64_t logical_index_45      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 45th logical index */
        uint64_t logical_index_44      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 44th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_44      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 44th logical index */
        uint64_t logical_index_45      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 45th logical index */
        uint64_t logical_index_46      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 46th logical index */
        uint64_t logical_index_47      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_44_47_s cn; */
};
typedef union cavm_prach_abx_logical_idx_44_47 cavm_prach_abx_logical_idx_44_47_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_44_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_44_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002098ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002098ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_44_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_44_47(a) cavm_prach_abx_logical_idx_44_47_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_44_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_44_47(a) "PRACH_ABX_LOGICAL_IDX_44_47"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_44_47(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_44_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_48_51
 *
 * INTERNAL: Available Logical Index 48 to 51 Register
 */
union cavm_prach_abx_logical_idx_48_51
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_48_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_51      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 51th logical index */
        uint64_t logical_index_50      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 50th logical index */
        uint64_t logical_index_49      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 49th logical index */
        uint64_t logical_index_48      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_48      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 48th logical index */
        uint64_t logical_index_49      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 49th logical index */
        uint64_t logical_index_50      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 50th logical index */
        uint64_t logical_index_51      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 51th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_48_51_s cn; */
};
typedef union cavm_prach_abx_logical_idx_48_51 cavm_prach_abx_logical_idx_48_51_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_48_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_48_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020a0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_48_51", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_48_51(a) cavm_prach_abx_logical_idx_48_51_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_48_51(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_48_51(a) "PRACH_ABX_LOGICAL_IDX_48_51"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_48_51(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_48_51(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_4_7
 *
 * INTERNAL: Available Logical Index 4 to 7 Register
 */
union cavm_prach_abx_logical_idx_4_7
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_4_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_7       : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 8th logical index */
        uint64_t logical_index_6       : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 7th logical index */
        uint64_t logical_index_5       : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 6th logical index */
        uint64_t logical_index_4       : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 5th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_4       : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 5th logical index */
        uint64_t logical_index_5       : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 6th logical index */
        uint64_t logical_index_6       : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 7th logical index */
        uint64_t logical_index_7       : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 8th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_4_7_s cn; */
};
typedef union cavm_prach_abx_logical_idx_4_7 cavm_prach_abx_logical_idx_4_7_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_4_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_4_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002048ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_4_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_4_7(a) cavm_prach_abx_logical_idx_4_7_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_4_7(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_4_7(a) "PRACH_ABX_LOGICAL_IDX_4_7"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_4_7(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_4_7(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_52_55
 *
 * INTERNAL: Available Logical Index 52 to 55 Register
 */
union cavm_prach_abx_logical_idx_52_55
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_52_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_55      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 55th logical index */
        uint64_t logical_index_54      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 54th logical index */
        uint64_t logical_index_53      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 53th logical index */
        uint64_t logical_index_52      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 52th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_52      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 52th logical index */
        uint64_t logical_index_53      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 53th logical index */
        uint64_t logical_index_54      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 54th logical index */
        uint64_t logical_index_55      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 55th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_52_55_s cn; */
};
typedef union cavm_prach_abx_logical_idx_52_55 cavm_prach_abx_logical_idx_52_55_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_52_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_52_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020a8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_52_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_52_55(a) cavm_prach_abx_logical_idx_52_55_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_52_55(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_52_55(a) "PRACH_ABX_LOGICAL_IDX_52_55"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_52_55(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_52_55(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_56_59
 *
 * INTERNAL: Available Logical Index 56 to 59 Register
 */
union cavm_prach_abx_logical_idx_56_59
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_56_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_59      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 59th logical index */
        uint64_t logical_index_58      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 58th logical index */
        uint64_t logical_index_57      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 57th logical index */
        uint64_t logical_index_56      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 56th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_56      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 56th logical index */
        uint64_t logical_index_57      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 57th logical index */
        uint64_t logical_index_58      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 58th logical index */
        uint64_t logical_index_59      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 59th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_56_59_s cn; */
};
typedef union cavm_prach_abx_logical_idx_56_59 cavm_prach_abx_logical_idx_56_59_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_56_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_56_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020b0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_56_59", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_56_59(a) cavm_prach_abx_logical_idx_56_59_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_56_59(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_56_59(a) "PRACH_ABX_LOGICAL_IDX_56_59"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_56_59(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_56_59(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_60_63
 *
 * INTERNAL: Available Logical Index 60 to 63 Register
 */
union cavm_prach_abx_logical_idx_60_63
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_60_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_63      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 63th logical index */
        uint64_t logical_index_62      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 62th logical index */
        uint64_t logical_index_61      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 61th logical index */
        uint64_t logical_index_60      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 60th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_60      : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 60th logical index */
        uint64_t logical_index_61      : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 61th logical index */
        uint64_t logical_index_62      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 62th logical index */
        uint64_t logical_index_63      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_60_63_s cn; */
};
typedef union cavm_prach_abx_logical_idx_60_63 cavm_prach_abx_logical_idx_60_63_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_60_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_60_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020b8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_60_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_60_63(a) cavm_prach_abx_logical_idx_60_63_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_60_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_60_63(a) "PRACH_ABX_LOGICAL_IDX_60_63"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_60_63(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_60_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_logical_idx_8_11
 *
 * INTERNAL: Available Logical Index 8 to 11 Register
 */
union cavm_prach_abx_logical_idx_8_11
{
    uint64_t u;
    struct cavm_prach_abx_logical_idx_8_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t logical_index_11      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 11th logical index */
        uint64_t logical_index_10      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 10th logical index */
        uint64_t logical_index_9       : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 9th logical index */
        uint64_t logical_index_8       : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 8th logical index */
#else /* Word 0 - Little Endian */
        uint64_t logical_index_8       : 16; /**< [ 15:  0](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 8th logical index */
        uint64_t logical_index_9       : 16; /**< [ 31: 16](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 9th logical index */
        uint64_t logical_index_10      : 16; /**< [ 47: 32](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 10th logical index */
        uint64_t logical_index_11      : 16; /**< [ 63: 48](R/W) (6'd0, 10'd(0~837)) Available logical_index. Of 11th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_logical_idx_8_11_s cn; */
};
typedef union cavm_prach_abx_logical_idx_8_11 cavm_prach_abx_logical_idx_8_11_t;

static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_8_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_LOGICAL_IDX_8_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002050ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002050ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_LOGICAL_IDX_8_11", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_LOGICAL_IDX_8_11(a) cavm_prach_abx_logical_idx_8_11_t
#define bustype_CAVM_PRACH_ABX_LOGICAL_IDX_8_11(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_LOGICAL_IDX_8_11(a) "PRACH_ABX_LOGICAL_IDX_8_11"
#define busnum_CAVM_PRACH_ABX_LOGICAL_IDX_8_11(a) (a)
#define arguments_CAVM_PRACH_ABX_LOGICAL_IDX_8_11(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_ngroup_0_7
 *
 * INTERNAL: Available Ngroup Register
 */
union cavm_prach_abx_ngroup_0_7
{
    uint64_t u;
    struct cavm_prach_abx_ngroup_0_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ngroup_7              : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 8th logical index */
        uint64_t ngroup_6              : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 7th logical index */
        uint64_t ngroup_5              : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 6th logical inde */
        uint64_t ngroup_4              : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 5th logical index */
        uint64_t ngroup_3              : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 4th logical index */
        uint64_t ngroup_2              : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 3rd logical index x */
        uint64_t ngroup_1              : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 2nd logical index */
        uint64_t ngroup_0              : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t ngroup_0              : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of start logical index */
        uint64_t ngroup_1              : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 2nd logical index */
        uint64_t ngroup_2              : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 3rd logical index x */
        uint64_t ngroup_3              : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 4th logical index */
        uint64_t ngroup_4              : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 5th logical index */
        uint64_t ngroup_5              : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 6th logical inde */
        uint64_t ngroup_6              : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 7th logical index */
        uint64_t ngroup_7              : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Ngroup. Of 8th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_ngroup_0_7_s cn; */
};
typedef union cavm_prach_abx_ngroup_0_7 cavm_prach_abx_ngroup_0_7_t;

static inline uint64_t CAVM_PRACH_ABX_NGROUP_0_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NGROUP_0_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021c0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NGROUP_0_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NGROUP_0_7(a) cavm_prach_abx_ngroup_0_7_t
#define bustype_CAVM_PRACH_ABX_NGROUP_0_7(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NGROUP_0_7(a) "PRACH_ABX_NGROUP_0_7"
#define busnum_CAVM_PRACH_ABX_NGROUP_0_7(a) (a)
#define arguments_CAVM_PRACH_ABX_NGROUP_0_7(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_ngroup_16_23
 *
 * INTERNAL: Available Ngroup 16 to 23 Register
 */
union cavm_prach_abx_ngroup_16_23
{
    uint64_t u;
    struct cavm_prach_abx_ngroup_16_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ngroup_23             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 23th logical index */
        uint64_t ngroup_22             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 22th logical index */
        uint64_t ngroup_21             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 21th logical index */
        uint64_t ngroup_20             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 20th logical index */
        uint64_t ngroup_19             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 19th logical index */
        uint64_t ngroup_18             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 18th logical index */
        uint64_t ngroup_17             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 17th logical index */
        uint64_t ngroup_16             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t ngroup_16             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 16th logical index */
        uint64_t ngroup_17             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 17th logical index */
        uint64_t ngroup_18             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 18th logical index */
        uint64_t ngroup_19             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 19th logical index */
        uint64_t ngroup_20             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 20th logical index */
        uint64_t ngroup_21             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 21th logical index */
        uint64_t ngroup_22             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 22th logical index */
        uint64_t ngroup_23             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 23th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_ngroup_16_23_s cn; */
};
typedef union cavm_prach_abx_ngroup_16_23 cavm_prach_abx_ngroup_16_23_t;

static inline uint64_t CAVM_PRACH_ABX_NGROUP_16_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NGROUP_16_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021d0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NGROUP_16_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NGROUP_16_23(a) cavm_prach_abx_ngroup_16_23_t
#define bustype_CAVM_PRACH_ABX_NGROUP_16_23(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NGROUP_16_23(a) "PRACH_ABX_NGROUP_16_23"
#define busnum_CAVM_PRACH_ABX_NGROUP_16_23(a) (a)
#define arguments_CAVM_PRACH_ABX_NGROUP_16_23(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_ngroup_24_31
 *
 * INTERNAL: Available Ngroup 24 to 31 Register
 */
union cavm_prach_abx_ngroup_24_31
{
    uint64_t u;
    struct cavm_prach_abx_ngroup_24_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ngroup_31             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 31th logical index */
        uint64_t ngroup_30             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 30th logical index */
        uint64_t ngroup_29             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 29th logical index */
        uint64_t ngroup_28             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 28th logical index */
        uint64_t ngroup_27             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 27th logical index */
        uint64_t ngroup_26             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 26th logical index */
        uint64_t ngroup_25             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 25th logical index */
        uint64_t ngroup_24             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 24th logical index */
#else /* Word 0 - Little Endian */
        uint64_t ngroup_24             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 24th logical index */
        uint64_t ngroup_25             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 25th logical index */
        uint64_t ngroup_26             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 26th logical index */
        uint64_t ngroup_27             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 27th logical index */
        uint64_t ngroup_28             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 28th logical index */
        uint64_t ngroup_29             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 29th logical index */
        uint64_t ngroup_30             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 30th logical index */
        uint64_t ngroup_31             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_ngroup_24_31_s cn; */
};
typedef union cavm_prach_abx_ngroup_24_31 cavm_prach_abx_ngroup_24_31_t;

static inline uint64_t CAVM_PRACH_ABX_NGROUP_24_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NGROUP_24_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021d8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NGROUP_24_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NGROUP_24_31(a) cavm_prach_abx_ngroup_24_31_t
#define bustype_CAVM_PRACH_ABX_NGROUP_24_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NGROUP_24_31(a) "PRACH_ABX_NGROUP_24_31"
#define busnum_CAVM_PRACH_ABX_NGROUP_24_31(a) (a)
#define arguments_CAVM_PRACH_ABX_NGROUP_24_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_ngroup_32_39
 *
 * INTERNAL: Available Ngroup 32 to 39 Register
 */
union cavm_prach_abx_ngroup_32_39
{
    uint64_t u;
    struct cavm_prach_abx_ngroup_32_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ngroup_39             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 39th logical index */
        uint64_t ngroup_38             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 38th logical index */
        uint64_t ngroup_37             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 37th logical index */
        uint64_t ngroup_36             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 36th logical index */
        uint64_t ngroup_35             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 35th logical index */
        uint64_t ngroup_34             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 34th logical index */
        uint64_t ngroup_33             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 33th logical index */
        uint64_t ngroup_32             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t ngroup_32             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 32th logical index */
        uint64_t ngroup_33             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 33th logical index */
        uint64_t ngroup_34             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 34th logical index */
        uint64_t ngroup_35             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 35th logical index */
        uint64_t ngroup_36             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 36th logical index */
        uint64_t ngroup_37             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 37th logical index */
        uint64_t ngroup_38             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 38th logical index */
        uint64_t ngroup_39             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 39th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_ngroup_32_39_s cn; */
};
typedef union cavm_prach_abx_ngroup_32_39 cavm_prach_abx_ngroup_32_39_t;

static inline uint64_t CAVM_PRACH_ABX_NGROUP_32_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NGROUP_32_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021e0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NGROUP_32_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NGROUP_32_39(a) cavm_prach_abx_ngroup_32_39_t
#define bustype_CAVM_PRACH_ABX_NGROUP_32_39(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NGROUP_32_39(a) "PRACH_ABX_NGROUP_32_39"
#define busnum_CAVM_PRACH_ABX_NGROUP_32_39(a) (a)
#define arguments_CAVM_PRACH_ABX_NGROUP_32_39(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_ngroup_40_47
 *
 * INTERNAL: Available Ngroup 40 to 47 Register
 */
union cavm_prach_abx_ngroup_40_47
{
    uint64_t u;
    struct cavm_prach_abx_ngroup_40_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ngroup_47             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 47th logical index */
        uint64_t ngroup_46             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 46th logical index */
        uint64_t ngroup_45             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 45th logical index */
        uint64_t ngroup_44             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 44th logical index */
        uint64_t ngroup_43             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 43th logical index */
        uint64_t ngroup_42             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 42th logical index */
        uint64_t ngroup_41             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 41th logical index */
        uint64_t ngroup_40             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 40th logical index */
#else /* Word 0 - Little Endian */
        uint64_t ngroup_40             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 40th logical index */
        uint64_t ngroup_41             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 41th logical index */
        uint64_t ngroup_42             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 42th logical index */
        uint64_t ngroup_43             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 43th logical index */
        uint64_t ngroup_44             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 44th logical index */
        uint64_t ngroup_45             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 45th logical index */
        uint64_t ngroup_46             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 46th logical index */
        uint64_t ngroup_47             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_ngroup_40_47_s cn; */
};
typedef union cavm_prach_abx_ngroup_40_47 cavm_prach_abx_ngroup_40_47_t;

static inline uint64_t CAVM_PRACH_ABX_NGROUP_40_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NGROUP_40_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021e8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NGROUP_40_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NGROUP_40_47(a) cavm_prach_abx_ngroup_40_47_t
#define bustype_CAVM_PRACH_ABX_NGROUP_40_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NGROUP_40_47(a) "PRACH_ABX_NGROUP_40_47"
#define busnum_CAVM_PRACH_ABX_NGROUP_40_47(a) (a)
#define arguments_CAVM_PRACH_ABX_NGROUP_40_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_ngroup_48_55
 *
 * INTERNAL: Available Ngroup 48 to 55 Register
 */
union cavm_prach_abx_ngroup_48_55
{
    uint64_t u;
    struct cavm_prach_abx_ngroup_48_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ngroup_55             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 55th logical index */
        uint64_t ngroup_54             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 54th logical index */
        uint64_t ngroup_53             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 53th logical index */
        uint64_t ngroup_52             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 52th logical index */
        uint64_t ngroup_51             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 51th logical index */
        uint64_t ngroup_50             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 50th logical index */
        uint64_t ngroup_49             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 49th logical index */
        uint64_t ngroup_48             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t ngroup_48             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 48th logical index */
        uint64_t ngroup_49             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 49th logical index */
        uint64_t ngroup_50             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 50th logical index */
        uint64_t ngroup_51             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 51th logical index */
        uint64_t ngroup_52             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 52th logical index */
        uint64_t ngroup_53             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 53th logical index */
        uint64_t ngroup_54             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 54th logical index */
        uint64_t ngroup_55             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 55th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_ngroup_48_55_s cn; */
};
typedef union cavm_prach_abx_ngroup_48_55 cavm_prach_abx_ngroup_48_55_t;

static inline uint64_t CAVM_PRACH_ABX_NGROUP_48_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NGROUP_48_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021f0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NGROUP_48_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NGROUP_48_55(a) cavm_prach_abx_ngroup_48_55_t
#define bustype_CAVM_PRACH_ABX_NGROUP_48_55(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NGROUP_48_55(a) "PRACH_ABX_NGROUP_48_55"
#define busnum_CAVM_PRACH_ABX_NGROUP_48_55(a) (a)
#define arguments_CAVM_PRACH_ABX_NGROUP_48_55(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_ngroup_56_63
 *
 * INTERNAL: Available Ngroup 56 to 63 Register
 */
union cavm_prach_abx_ngroup_56_63
{
    uint64_t u;
    struct cavm_prach_abx_ngroup_56_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ngroup_63             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 63th logical index */
        uint64_t ngroup_62             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 62th logical index */
        uint64_t ngroup_61             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 61th logical index */
        uint64_t ngroup_60             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 60th logical index */
        uint64_t ngroup_59             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 59th logical index */
        uint64_t ngroup_58             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 58th logical index */
        uint64_t ngroup_57             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 57th logical index */
        uint64_t ngroup_56             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 56th logical index */
#else /* Word 0 - Little Endian */
        uint64_t ngroup_56             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 56th logical index */
        uint64_t ngroup_57             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 57th logical index */
        uint64_t ngroup_58             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 58th logical index */
        uint64_t ngroup_59             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 59th logical index */
        uint64_t ngroup_60             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 60th logical index */
        uint64_t ngroup_61             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 61th logical index */
        uint64_t ngroup_62             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 62th logical index */
        uint64_t ngroup_63             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_ngroup_56_63_s cn; */
};
typedef union cavm_prach_abx_ngroup_56_63 cavm_prach_abx_ngroup_56_63_t;

static inline uint64_t CAVM_PRACH_ABX_NGROUP_56_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NGROUP_56_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021f8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NGROUP_56_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NGROUP_56_63(a) cavm_prach_abx_ngroup_56_63_t
#define bustype_CAVM_PRACH_ABX_NGROUP_56_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NGROUP_56_63(a) "PRACH_ABX_NGROUP_56_63"
#define busnum_CAVM_PRACH_ABX_NGROUP_56_63(a) (a)
#define arguments_CAVM_PRACH_ABX_NGROUP_56_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_ngroup_8_15
 *
 * INTERNAL: Available Ngroup 8 to 15 Register
 */
union cavm_prach_abx_ngroup_8_15
{
    uint64_t u;
    struct cavm_prach_abx_ngroup_8_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ngroup_15             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 15th logical index */
        uint64_t ngroup_14             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 14th logical index */
        uint64_t ngroup_13             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 13th logical index */
        uint64_t ngroup_12             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 12th logical index */
        uint64_t ngroup_11             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 11th logical index */
        uint64_t ngroup_10             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 10th logical index */
        uint64_t ngroup_9              : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 9th logical index */
        uint64_t ngroup_8              : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 8th logical index */
#else /* Word 0 - Little Endian */
        uint64_t ngroup_8              : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 8th logical index */
        uint64_t ngroup_9              : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 9th logical index */
        uint64_t ngroup_10             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 10th logical index */
        uint64_t ngroup_11             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 11th logical index */
        uint64_t ngroup_12             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 12th logical index */
        uint64_t ngroup_13             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 13th logical index */
        uint64_t ngroup_14             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 14th logical index */
        uint64_t ngroup_15             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 15th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_ngroup_8_15_s cn; */
};
typedef union cavm_prach_abx_ngroup_8_15 cavm_prach_abx_ngroup_8_15_t;

static inline uint64_t CAVM_PRACH_ABX_NGROUP_8_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NGROUP_8_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021c8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NGROUP_8_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NGROUP_8_15(a) cavm_prach_abx_ngroup_8_15_t
#define bustype_CAVM_PRACH_ABX_NGROUP_8_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NGROUP_8_15(a) "PRACH_ABX_NGROUP_8_15"
#define busnum_CAVM_PRACH_ABX_NGROUP_8_15(a) (a)
#define arguments_CAVM_PRACH_ABX_NGROUP_8_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_0_7
 *
 * INTERNAL: Available Nshift 0 to 7 Register
 */
union cavm_prach_abx_nshift_0_7
{
    uint64_t u;
    struct cavm_prach_abx_nshift_0_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_7              : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 8th logical index */
        uint64_t nshift_6              : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 7th logical index */
        uint64_t nshift_5              : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 6th logical index */
        uint64_t nshift_4              : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 5th logical index */
        uint64_t nshift_3              : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 4th logical index */
        uint64_t nshift_2              : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 3rdh logical index */
        uint64_t nshift_1              : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 2ndh logical index */
        uint64_t nshift_0              : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_0              : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of start logical index */
        uint64_t nshift_1              : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 2ndh logical index */
        uint64_t nshift_2              : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 3rdh logical index */
        uint64_t nshift_3              : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 4th logical index */
        uint64_t nshift_4              : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 5th logical index */
        uint64_t nshift_5              : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 6th logical index */
        uint64_t nshift_6              : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 7th logical index */
        uint64_t nshift_7              : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 8th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_0_7_s cn; */
};
typedef union cavm_prach_abx_nshift_0_7 cavm_prach_abx_nshift_0_7_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_0_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_0_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002180ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002180ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_0_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_0_7(a) cavm_prach_abx_nshift_0_7_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_0_7(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_0_7(a) "PRACH_ABX_NSHIFT_0_7"
#define busnum_CAVM_PRACH_ABX_NSHIFT_0_7(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_0_7(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_16_23
 *
 * INTERNAL: Available Nshift 16 to 23 Register
 */
union cavm_prach_abx_nshift_16_23
{
    uint64_t u;
    struct cavm_prach_abx_nshift_16_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_23             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 23th logical index */
        uint64_t nshift_22             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 22th logical index */
        uint64_t nshift_21             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 21th logical index */
        uint64_t nshift_20             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 20th logical index */
        uint64_t nshift_19             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 19th logical index */
        uint64_t nshift_18             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 18th logical index */
        uint64_t nshift_17             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 17th logical index */
        uint64_t nshift_16             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_16             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 16th logical index */
        uint64_t nshift_17             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 17th logical index */
        uint64_t nshift_18             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 18th logical index */
        uint64_t nshift_19             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 19th logical index */
        uint64_t nshift_20             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 20th logical index */
        uint64_t nshift_21             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 21th logical index */
        uint64_t nshift_22             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 22th logical index */
        uint64_t nshift_23             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 23th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_16_23_s cn; */
};
typedef union cavm_prach_abx_nshift_16_23 cavm_prach_abx_nshift_16_23_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_16_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_16_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002190ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002190ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_16_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_16_23(a) cavm_prach_abx_nshift_16_23_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_16_23(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_16_23(a) "PRACH_ABX_NSHIFT_16_23"
#define busnum_CAVM_PRACH_ABX_NSHIFT_16_23(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_16_23(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_24_31
 *
 * INTERNAL: Available Nshift 24 to 31 Register
 */
union cavm_prach_abx_nshift_24_31
{
    uint64_t u;
    struct cavm_prach_abx_nshift_24_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_31             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 31th logical index */
        uint64_t nshift_30             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 30th logical index */
        uint64_t nshift_29             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 29th logical index */
        uint64_t nshift_28             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 28th logical index */
        uint64_t nshift_27             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 27th logical index */
        uint64_t nshift_26             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 26th logical index */
        uint64_t nshift_25             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 25th logical index */
        uint64_t nshift_24             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 24th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_24             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 24th logical index */
        uint64_t nshift_25             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 25th logical index */
        uint64_t nshift_26             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 26th logical index */
        uint64_t nshift_27             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 27th logical index */
        uint64_t nshift_28             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 28th logical index */
        uint64_t nshift_29             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 29th logical index */
        uint64_t nshift_30             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 30th logical index */
        uint64_t nshift_31             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_24_31_s cn; */
};
typedef union cavm_prach_abx_nshift_24_31 cavm_prach_abx_nshift_24_31_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_24_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_24_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002198ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002198ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_24_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_24_31(a) cavm_prach_abx_nshift_24_31_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_24_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_24_31(a) "PRACH_ABX_NSHIFT_24_31"
#define busnum_CAVM_PRACH_ABX_NSHIFT_24_31(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_24_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_32_39
 *
 * INTERNAL: Available Nshift 32 to 39 Register
 */
union cavm_prach_abx_nshift_32_39
{
    uint64_t u;
    struct cavm_prach_abx_nshift_32_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_39             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 39th logical index */
        uint64_t nshift_38             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 38th logical index */
        uint64_t nshift_37             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 37th logical index */
        uint64_t nshift_36             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 36th logical index */
        uint64_t nshift_35             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 35th logical index */
        uint64_t nshift_34             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 34th logical index */
        uint64_t nshift_33             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 33th logical index */
        uint64_t nshift_32             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_32             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 32th logical index */
        uint64_t nshift_33             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 33th logical index */
        uint64_t nshift_34             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 34th logical index */
        uint64_t nshift_35             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 35th logical index */
        uint64_t nshift_36             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 36th logical index */
        uint64_t nshift_37             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 37th logical index */
        uint64_t nshift_38             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 38th logical index */
        uint64_t nshift_39             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 39th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_32_39_s cn; */
};
typedef union cavm_prach_abx_nshift_32_39 cavm_prach_abx_nshift_32_39_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_32_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_32_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021a0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_32_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_32_39(a) cavm_prach_abx_nshift_32_39_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_32_39(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_32_39(a) "PRACH_ABX_NSHIFT_32_39"
#define busnum_CAVM_PRACH_ABX_NSHIFT_32_39(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_32_39(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_40_47
 *
 * INTERNAL: Available Nshift 40 to 47 Register
 */
union cavm_prach_abx_nshift_40_47
{
    uint64_t u;
    struct cavm_prach_abx_nshift_40_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_47             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 47th logical index */
        uint64_t nshift_46             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 46th logical index */
        uint64_t nshift_45             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 45th logical index */
        uint64_t nshift_44             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 44th logical index */
        uint64_t nshift_43             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 43th logical index */
        uint64_t nshift_42             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 42th logical index */
        uint64_t nshift_41             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 41th logical index */
        uint64_t nshift_40             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 40th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_40             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 40th logical index */
        uint64_t nshift_41             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 41th logical index */
        uint64_t nshift_42             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 42th logical index */
        uint64_t nshift_43             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 43th logical index */
        uint64_t nshift_44             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 44th logical index */
        uint64_t nshift_45             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 45th logical index */
        uint64_t nshift_46             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 46th logical index */
        uint64_t nshift_47             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_40_47_s cn; */
};
typedef union cavm_prach_abx_nshift_40_47 cavm_prach_abx_nshift_40_47_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_40_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_40_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021a8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_40_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_40_47(a) cavm_prach_abx_nshift_40_47_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_40_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_40_47(a) "PRACH_ABX_NSHIFT_40_47"
#define busnum_CAVM_PRACH_ABX_NSHIFT_40_47(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_40_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_48_55
 *
 * INTERNAL: Available Nshift 48 to 55 Register
 */
union cavm_prach_abx_nshift_48_55
{
    uint64_t u;
    struct cavm_prach_abx_nshift_48_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_55             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 55th logical index */
        uint64_t nshift_54             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 54th logical index */
        uint64_t nshift_53             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 53th logical index */
        uint64_t nshift_52             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 52th logical index */
        uint64_t nshift_51             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 51th logical index */
        uint64_t nshift_50             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 50th logical index */
        uint64_t nshift_49             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 49th logical index */
        uint64_t nshift_48             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_48             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 48th logical index */
        uint64_t nshift_49             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 49th logical index */
        uint64_t nshift_50             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 50th logical index */
        uint64_t nshift_51             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 51th logical index */
        uint64_t nshift_52             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 52th logical index */
        uint64_t nshift_53             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 53th logical index */
        uint64_t nshift_54             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 54th logical index */
        uint64_t nshift_55             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 55th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_48_55_s cn; */
};
typedef union cavm_prach_abx_nshift_48_55 cavm_prach_abx_nshift_48_55_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_48_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_48_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021b0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_48_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_48_55(a) cavm_prach_abx_nshift_48_55_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_48_55(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_48_55(a) "PRACH_ABX_NSHIFT_48_55"
#define busnum_CAVM_PRACH_ABX_NSHIFT_48_55(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_48_55(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_56_63
 *
 * INTERNAL: Available Nshift 56 to 63 Register
 */
union cavm_prach_abx_nshift_56_63
{
    uint64_t u;
    struct cavm_prach_abx_nshift_56_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_63             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 63th logical index */
        uint64_t nshift_62             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 62th logical index */
        uint64_t nshift_61             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 61th logical index */
        uint64_t nshift_60             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 60th logical index */
        uint64_t nshift_59             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 59th logical index */
        uint64_t nshift_58             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 58th logical index */
        uint64_t nshift_57             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 57th logical index */
        uint64_t nshift_56             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 56th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_56             : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 56th logical index */
        uint64_t nshift_57             : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 57th logical index */
        uint64_t nshift_58             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 58th logical index */
        uint64_t nshift_59             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 59th logical index */
        uint64_t nshift_60             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 60th logical index */
        uint64_t nshift_61             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 61th logical index */
        uint64_t nshift_62             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 62th logical index */
        uint64_t nshift_63             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_56_63_s cn; */
};
typedef union cavm_prach_abx_nshift_56_63 cavm_prach_abx_nshift_56_63_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_56_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_56_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430021b8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430021b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_56_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_56_63(a) cavm_prach_abx_nshift_56_63_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_56_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_56_63(a) "PRACH_ABX_NSHIFT_56_63"
#define busnum_CAVM_PRACH_ABX_NSHIFT_56_63(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_56_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_8_15
 *
 * INTERNAL: Available Nshift 8 to 15 Register
 */
union cavm_prach_abx_nshift_8_15
{
    uint64_t u;
    struct cavm_prach_abx_nshift_8_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_15             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 15th logical index */
        uint64_t nshift_14             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 14th logical index */
        uint64_t nshift_13             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 13th logical index */
        uint64_t nshift_12             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 12th logical index */
        uint64_t nshift_11             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 11th logical index */
        uint64_t nshift_10             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 10th logical index */
        uint64_t nshift_9              : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 9th logical index */
        uint64_t nshift_8              : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 8th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_8              : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 8th logical index */
        uint64_t nshift_9              : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 9th logical index */
        uint64_t nshift_10             : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 10th logical index */
        uint64_t nshift_11             : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 11th logical index */
        uint64_t nshift_12             : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 12th logical index */
        uint64_t nshift_13             : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 13th logical index */
        uint64_t nshift_14             : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 14th logical index */
        uint64_t nshift_15             : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~31)) Available Nshift. Of 15th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_8_15_s cn; */
};
typedef union cavm_prach_abx_nshift_8_15 cavm_prach_abx_nshift_8_15_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_8_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_8_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002188ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002188ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_8_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_8_15(a) cavm_prach_abx_nshift_8_15_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_8_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_8_15(a) "PRACH_ABX_NSHIFT_8_15"
#define busnum_CAVM_PRACH_ABX_NSHIFT_8_15(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_8_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar2_0_15
 *
 * INTERNAL: Available Nshift_bar2 0 to 15 Register
 */
union cavm_prach_abx_nshift_bar2_0_15
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar2_0_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar2_15        : 4;  /**< [ 63: 60](R/W) 0~5. Available Nshift_bar2. Of 16th logical index */
        uint64_t nshift_bar2_14        : 4;  /**< [ 59: 56](R/W) 0~5. Available Nshift_bar2. Of 15th logical index */
        uint64_t nshift_bar2_13        : 4;  /**< [ 55: 52](R/W) 0~5. Available Nshift_bar2. Of 14th logical index */
        uint64_t nshift_bar2_12        : 4;  /**< [ 51: 48](R/W) 0~5. Available Nshift_bar2. Of 13th logical index */
        uint64_t nshift_bar2_11        : 4;  /**< [ 47: 44](R/W) 0~5. Available Nshift_bar2. Of 12th logical index */
        uint64_t nshift_bar2_10        : 4;  /**< [ 43: 40](R/W) 0~5. Available Nshift_bar2. Of 11th  logical index */
        uint64_t nshift_bar2_9         : 4;  /**< [ 39: 36](R/W) 0~5. Available Nshift_bar2. Of 10th logical index */
        uint64_t nshift_bar2_8         : 4;  /**< [ 35: 32](R/W) 0~5. Available Nshift_bar2. Of 9th logical index */
        uint64_t nshift_bar2_7         : 4;  /**< [ 31: 28](R/W) 0~5. Available Nshift_bar2. Of 8th logical index */
        uint64_t nshift_bar2_6         : 4;  /**< [ 27: 24](R/W) 0~5. Available Nshift_bar2. Of 7th logical index */
        uint64_t nshift_bar2_5         : 4;  /**< [ 23: 20](R/W) 0~5. Available Nshift_bar2. Of 6th logical index */
        uint64_t nshift_bar2_4         : 4;  /**< [ 19: 16](R/W) 0~5. Available Nshift_bar2. Of 5th logical index */
        uint64_t nshift_bar2_3         : 4;  /**< [ 15: 12](R/W) 0~5. Available Nshift_bar2. Of 4th logical index */
        uint64_t nshift_bar2_2         : 4;  /**< [ 11:  8](R/W) 0~5. Available Nshift_bar2. Of 3rd logical index */
        uint64_t nshift_bar2_1         : 4;  /**< [  7:  4](R/W) 0~5. Available Nshift_bar2. Of 2nd logical index */
        uint64_t nshift_bar2_0         : 4;  /**< [  3:  0](R/W) 0~5. Available Nshift_bar2. Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar2_0         : 4;  /**< [  3:  0](R/W) 0~5. Available Nshift_bar2. Of start logical index */
        uint64_t nshift_bar2_1         : 4;  /**< [  7:  4](R/W) 0~5. Available Nshift_bar2. Of 2nd logical index */
        uint64_t nshift_bar2_2         : 4;  /**< [ 11:  8](R/W) 0~5. Available Nshift_bar2. Of 3rd logical index */
        uint64_t nshift_bar2_3         : 4;  /**< [ 15: 12](R/W) 0~5. Available Nshift_bar2. Of 4th logical index */
        uint64_t nshift_bar2_4         : 4;  /**< [ 19: 16](R/W) 0~5. Available Nshift_bar2. Of 5th logical index */
        uint64_t nshift_bar2_5         : 4;  /**< [ 23: 20](R/W) 0~5. Available Nshift_bar2. Of 6th logical index */
        uint64_t nshift_bar2_6         : 4;  /**< [ 27: 24](R/W) 0~5. Available Nshift_bar2. Of 7th logical index */
        uint64_t nshift_bar2_7         : 4;  /**< [ 31: 28](R/W) 0~5. Available Nshift_bar2. Of 8th logical index */
        uint64_t nshift_bar2_8         : 4;  /**< [ 35: 32](R/W) 0~5. Available Nshift_bar2. Of 9th logical index */
        uint64_t nshift_bar2_9         : 4;  /**< [ 39: 36](R/W) 0~5. Available Nshift_bar2. Of 10th logical index */
        uint64_t nshift_bar2_10        : 4;  /**< [ 43: 40](R/W) 0~5. Available Nshift_bar2. Of 11th  logical index */
        uint64_t nshift_bar2_11        : 4;  /**< [ 47: 44](R/W) 0~5. Available Nshift_bar2. Of 12th logical index */
        uint64_t nshift_bar2_12        : 4;  /**< [ 51: 48](R/W) 0~5. Available Nshift_bar2. Of 13th logical index */
        uint64_t nshift_bar2_13        : 4;  /**< [ 55: 52](R/W) 0~5. Available Nshift_bar2. Of 14th logical index */
        uint64_t nshift_bar2_14        : 4;  /**< [ 59: 56](R/W) 0~5. Available Nshift_bar2. Of 15th logical index */
        uint64_t nshift_bar2_15        : 4;  /**< [ 63: 60](R/W) 0~5. Available Nshift_bar2. Of 16th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar2_0_15_s cn; */
};
typedef union cavm_prach_abx_nshift_bar2_0_15 cavm_prach_abx_nshift_bar2_0_15_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR2_0_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR2_0_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002200ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002200ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR2_0_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR2_0_15(a) cavm_prach_abx_nshift_bar2_0_15_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR2_0_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR2_0_15(a) "PRACH_ABX_NSHIFT_BAR2_0_15"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR2_0_15(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR2_0_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar2_16_31
 *
 * INTERNAL: Available Nshift_bar2 16 to 31 Register
 */
union cavm_prach_abx_nshift_bar2_16_31
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar2_16_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar2_31        : 4;  /**< [ 63: 60](R/W) 0~5. Available Nshift_bar2. Of 31th logical index */
        uint64_t nshift_bar2_30        : 4;  /**< [ 59: 56](R/W) 0~5. Available Nshift_bar2. Of 30th logical index */
        uint64_t nshift_bar2_29        : 4;  /**< [ 55: 52](R/W) 0~5. Available Nshift_bar2. Of 29th logical index */
        uint64_t nshift_bar2_28        : 4;  /**< [ 51: 48](R/W) 0~5. Available Nshift_bar2. Of 28th logical index */
        uint64_t nshift_bar2_27        : 4;  /**< [ 47: 44](R/W) 0~5. Available Nshift_bar2. Of 27th logical index */
        uint64_t nshift_bar2_26        : 4;  /**< [ 43: 40](R/W) 0~5. Available Nshift_bar2. Of 26th logical index */
        uint64_t nshift_bar2_25        : 4;  /**< [ 39: 36](R/W) 0~5. Available Nshift_bar2. Of 25th logical index */
        uint64_t nshift_bar2_24        : 4;  /**< [ 35: 32](R/W) 0~5. Available Nshift_bar2. Of 24th logical index */
        uint64_t nshift_bar2_23        : 4;  /**< [ 31: 28](R/W) 0~5. Available Nshift_bar2. Of 23th logical index */
        uint64_t nshift_bar2_22        : 4;  /**< [ 27: 24](R/W) 0~5. Available Nshift_bar2. Of 22th logical index */
        uint64_t nshift_bar2_21        : 4;  /**< [ 23: 20](R/W) 0~5. Available Nshift_bar2. Of 21th logical index */
        uint64_t nshift_bar2_20        : 4;  /**< [ 19: 16](R/W) 0~5. Available Nshift_bar2. Of 20th logical index */
        uint64_t nshift_bar2_19        : 4;  /**< [ 15: 12](R/W) 0~5. Available Nshift_bar2. Of 19th logical index */
        uint64_t nshift_bar2_18        : 4;  /**< [ 11:  8](R/W) 0~5. Available Nshift_bar2. Of 18th logical index */
        uint64_t nshift_bar2_17        : 4;  /**< [  7:  4](R/W) 0~5. Available Nshift_bar2. Of 17th logical index */
        uint64_t nshift_bar2_16        : 4;  /**< [  3:  0](R/W) 0~5. Available Nshift_bar2. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar2_16        : 4;  /**< [  3:  0](R/W) 0~5. Available Nshift_bar2. Of 16th logical index */
        uint64_t nshift_bar2_17        : 4;  /**< [  7:  4](R/W) 0~5. Available Nshift_bar2. Of 17th logical index */
        uint64_t nshift_bar2_18        : 4;  /**< [ 11:  8](R/W) 0~5. Available Nshift_bar2. Of 18th logical index */
        uint64_t nshift_bar2_19        : 4;  /**< [ 15: 12](R/W) 0~5. Available Nshift_bar2. Of 19th logical index */
        uint64_t nshift_bar2_20        : 4;  /**< [ 19: 16](R/W) 0~5. Available Nshift_bar2. Of 20th logical index */
        uint64_t nshift_bar2_21        : 4;  /**< [ 23: 20](R/W) 0~5. Available Nshift_bar2. Of 21th logical index */
        uint64_t nshift_bar2_22        : 4;  /**< [ 27: 24](R/W) 0~5. Available Nshift_bar2. Of 22th logical index */
        uint64_t nshift_bar2_23        : 4;  /**< [ 31: 28](R/W) 0~5. Available Nshift_bar2. Of 23th logical index */
        uint64_t nshift_bar2_24        : 4;  /**< [ 35: 32](R/W) 0~5. Available Nshift_bar2. Of 24th logical index */
        uint64_t nshift_bar2_25        : 4;  /**< [ 39: 36](R/W) 0~5. Available Nshift_bar2. Of 25th logical index */
        uint64_t nshift_bar2_26        : 4;  /**< [ 43: 40](R/W) 0~5. Available Nshift_bar2. Of 26th logical index */
        uint64_t nshift_bar2_27        : 4;  /**< [ 47: 44](R/W) 0~5. Available Nshift_bar2. Of 27th logical index */
        uint64_t nshift_bar2_28        : 4;  /**< [ 51: 48](R/W) 0~5. Available Nshift_bar2. Of 28th logical index */
        uint64_t nshift_bar2_29        : 4;  /**< [ 55: 52](R/W) 0~5. Available Nshift_bar2. Of 29th logical index */
        uint64_t nshift_bar2_30        : 4;  /**< [ 59: 56](R/W) 0~5. Available Nshift_bar2. Of 30th logical index */
        uint64_t nshift_bar2_31        : 4;  /**< [ 63: 60](R/W) 0~5. Available Nshift_bar2. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar2_16_31_s cn; */
};
typedef union cavm_prach_abx_nshift_bar2_16_31 cavm_prach_abx_nshift_bar2_16_31_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR2_16_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR2_16_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002208ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002208ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR2_16_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR2_16_31(a) cavm_prach_abx_nshift_bar2_16_31_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR2_16_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR2_16_31(a) "PRACH_ABX_NSHIFT_BAR2_16_31"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR2_16_31(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR2_16_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar2_32_47
 *
 * INTERNAL: Available Nshift_bar2 32 to 47 Register
 */
union cavm_prach_abx_nshift_bar2_32_47
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar2_32_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar2_47        : 4;  /**< [ 63: 60](R/W) 0~5. Available Nshift_bar2. Of 47th logical index */
        uint64_t nshift_bar2_46        : 4;  /**< [ 59: 56](R/W) 0~5. Available Nshift_bar2. Of 46th logical index */
        uint64_t nshift_bar2_45        : 4;  /**< [ 55: 52](R/W) 0~5. Available Nshift_bar2. Of 45th logical index */
        uint64_t nshift_bar2_44        : 4;  /**< [ 51: 48](R/W) 0~5. Available Nshift_bar2. Of 44th logical index */
        uint64_t nshift_bar2_43        : 4;  /**< [ 47: 44](R/W) 0~5. Available Nshift_bar2. Of 43th logical index */
        uint64_t nshift_bar2_42        : 4;  /**< [ 43: 40](R/W) 0~5. Available Nshift_bar2. Of 42th logical index */
        uint64_t nshift_bar2_41        : 4;  /**< [ 39: 36](R/W) 0~5. Available Nshift_bar2. Of 41th logical index */
        uint64_t nshift_bar2_40        : 4;  /**< [ 35: 32](R/W) 0~5. Available Nshift_bar2. Of 40th logical index */
        uint64_t nshift_bar2_39        : 4;  /**< [ 31: 28](R/W) 0~5. Available Nshift_bar2. Of 39th logical index */
        uint64_t nshift_bar2_38        : 4;  /**< [ 27: 24](R/W) 0~5. Available Nshift_bar2. Of 38th logical index */
        uint64_t nshift_bar2_37        : 4;  /**< [ 23: 20](R/W) 0~5. Available Nshift_bar2. Of 37th logical index */
        uint64_t nshift_bar2_36        : 4;  /**< [ 19: 16](R/W) 0~5. Available Nshift_bar2. Of 36th logical index */
        uint64_t nshift_bar2_35        : 4;  /**< [ 15: 12](R/W) 0~5. Available Nshift_bar2. Of 35th logical index */
        uint64_t nshift_bar2_34        : 4;  /**< [ 11:  8](R/W) 0~5. Available Nshift_bar2. Of 34th logical index */
        uint64_t nshift_bar2_33        : 4;  /**< [  7:  4](R/W) 0~5. Available Nshift_bar2. Of 33th logical index */
        uint64_t nshift_bar2_32        : 4;  /**< [  3:  0](R/W) 0~5. Available Nshift_bar2. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar2_32        : 4;  /**< [  3:  0](R/W) 0~5. Available Nshift_bar2. Of 32th logical index */
        uint64_t nshift_bar2_33        : 4;  /**< [  7:  4](R/W) 0~5. Available Nshift_bar2. Of 33th logical index */
        uint64_t nshift_bar2_34        : 4;  /**< [ 11:  8](R/W) 0~5. Available Nshift_bar2. Of 34th logical index */
        uint64_t nshift_bar2_35        : 4;  /**< [ 15: 12](R/W) 0~5. Available Nshift_bar2. Of 35th logical index */
        uint64_t nshift_bar2_36        : 4;  /**< [ 19: 16](R/W) 0~5. Available Nshift_bar2. Of 36th logical index */
        uint64_t nshift_bar2_37        : 4;  /**< [ 23: 20](R/W) 0~5. Available Nshift_bar2. Of 37th logical index */
        uint64_t nshift_bar2_38        : 4;  /**< [ 27: 24](R/W) 0~5. Available Nshift_bar2. Of 38th logical index */
        uint64_t nshift_bar2_39        : 4;  /**< [ 31: 28](R/W) 0~5. Available Nshift_bar2. Of 39th logical index */
        uint64_t nshift_bar2_40        : 4;  /**< [ 35: 32](R/W) 0~5. Available Nshift_bar2. Of 40th logical index */
        uint64_t nshift_bar2_41        : 4;  /**< [ 39: 36](R/W) 0~5. Available Nshift_bar2. Of 41th logical index */
        uint64_t nshift_bar2_42        : 4;  /**< [ 43: 40](R/W) 0~5. Available Nshift_bar2. Of 42th logical index */
        uint64_t nshift_bar2_43        : 4;  /**< [ 47: 44](R/W) 0~5. Available Nshift_bar2. Of 43th logical index */
        uint64_t nshift_bar2_44        : 4;  /**< [ 51: 48](R/W) 0~5. Available Nshift_bar2. Of 44th logical index */
        uint64_t nshift_bar2_45        : 4;  /**< [ 55: 52](R/W) 0~5. Available Nshift_bar2. Of 45th logical index */
        uint64_t nshift_bar2_46        : 4;  /**< [ 59: 56](R/W) 0~5. Available Nshift_bar2. Of 46th logical index */
        uint64_t nshift_bar2_47        : 4;  /**< [ 63: 60](R/W) 0~5. Available Nshift_bar2. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar2_32_47_s cn; */
};
typedef union cavm_prach_abx_nshift_bar2_32_47 cavm_prach_abx_nshift_bar2_32_47_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR2_32_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR2_32_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002210ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002210ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR2_32_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR2_32_47(a) cavm_prach_abx_nshift_bar2_32_47_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR2_32_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR2_32_47(a) "PRACH_ABX_NSHIFT_BAR2_32_47"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR2_32_47(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR2_32_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar2_48_63
 *
 * INTERNAL: Available Nshift_bar2 48 to 63 Register
 */
union cavm_prach_abx_nshift_bar2_48_63
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar2_48_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar2_63        : 4;  /**< [ 63: 60](R/W) 0~5. Available Nshift_bar2. Of 63th logical index */
        uint64_t nshift_bar2_62        : 4;  /**< [ 59: 56](R/W) 0~5. Available Nshift_bar2. Of 62th logical index */
        uint64_t nshift_bar2_61        : 4;  /**< [ 55: 52](R/W) 0~5. Available Nshift_bar2. Of 61th logical index */
        uint64_t nshift_bar2_60        : 4;  /**< [ 51: 48](R/W) 0~5. Available Nshift_bar2. Of 60th logical index */
        uint64_t nshift_bar2_59        : 4;  /**< [ 47: 44](R/W) 0~5. Available Nshift_bar2. Of 59th logical index */
        uint64_t nshift_bar2_58        : 4;  /**< [ 43: 40](R/W) 0~5. Available Nshift_bar2. Of 58th logical index */
        uint64_t nshift_bar2_57        : 4;  /**< [ 39: 36](R/W) 0~5. Available Nshift_bar2. Of 57th logical index */
        uint64_t nshift_bar2_56        : 4;  /**< [ 35: 32](R/W) 0~5. Available Nshift_bar2. Of 56th logical index */
        uint64_t nshift_bar2_55        : 4;  /**< [ 31: 28](R/W) 0~5. Available Nshift_bar2. Of 55th logical index */
        uint64_t nshift_bar2_54        : 4;  /**< [ 27: 24](R/W) 0~5. Available Nshift_bar2. Of 54th logical index */
        uint64_t nshift_bar2_53        : 4;  /**< [ 23: 20](R/W) 0~5. Available Nshift_bar2. Of 53th logical index */
        uint64_t nshift_bar2_52        : 4;  /**< [ 19: 16](R/W) 0~5. Available Nshift_bar2. Of 52th logical index */
        uint64_t nshift_bar2_51        : 4;  /**< [ 15: 12](R/W) 0~5. Available Nshift_bar2. Of 51th logical index */
        uint64_t nshift_bar2_50        : 4;  /**< [ 11:  8](R/W) 0~5. Available Nshift_bar2. Of 50th logical index */
        uint64_t nshift_bar2_49        : 4;  /**< [  7:  4](R/W) 0~5. Available Nshift_bar2. Of 49th logical index */
        uint64_t nshift_bar2_48        : 4;  /**< [  3:  0](R/W) 0~5. Available Nshift_bar2. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar2_48        : 4;  /**< [  3:  0](R/W) 0~5. Available Nshift_bar2. Of 48th logical index */
        uint64_t nshift_bar2_49        : 4;  /**< [  7:  4](R/W) 0~5. Available Nshift_bar2. Of 49th logical index */
        uint64_t nshift_bar2_50        : 4;  /**< [ 11:  8](R/W) 0~5. Available Nshift_bar2. Of 50th logical index */
        uint64_t nshift_bar2_51        : 4;  /**< [ 15: 12](R/W) 0~5. Available Nshift_bar2. Of 51th logical index */
        uint64_t nshift_bar2_52        : 4;  /**< [ 19: 16](R/W) 0~5. Available Nshift_bar2. Of 52th logical index */
        uint64_t nshift_bar2_53        : 4;  /**< [ 23: 20](R/W) 0~5. Available Nshift_bar2. Of 53th logical index */
        uint64_t nshift_bar2_54        : 4;  /**< [ 27: 24](R/W) 0~5. Available Nshift_bar2. Of 54th logical index */
        uint64_t nshift_bar2_55        : 4;  /**< [ 31: 28](R/W) 0~5. Available Nshift_bar2. Of 55th logical index */
        uint64_t nshift_bar2_56        : 4;  /**< [ 35: 32](R/W) 0~5. Available Nshift_bar2. Of 56th logical index */
        uint64_t nshift_bar2_57        : 4;  /**< [ 39: 36](R/W) 0~5. Available Nshift_bar2. Of 57th logical index */
        uint64_t nshift_bar2_58        : 4;  /**< [ 43: 40](R/W) 0~5. Available Nshift_bar2. Of 58th logical index */
        uint64_t nshift_bar2_59        : 4;  /**< [ 47: 44](R/W) 0~5. Available Nshift_bar2. Of 59th logical index */
        uint64_t nshift_bar2_60        : 4;  /**< [ 51: 48](R/W) 0~5. Available Nshift_bar2. Of 60th logical index */
        uint64_t nshift_bar2_61        : 4;  /**< [ 55: 52](R/W) 0~5. Available Nshift_bar2. Of 61th logical index */
        uint64_t nshift_bar2_62        : 4;  /**< [ 59: 56](R/W) 0~5. Available Nshift_bar2. Of 62th logical index */
        uint64_t nshift_bar2_63        : 4;  /**< [ 63: 60](R/W) 0~5. Available Nshift_bar2. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar2_48_63_s cn; */
};
typedef union cavm_prach_abx_nshift_bar2_48_63 cavm_prach_abx_nshift_bar2_48_63_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR2_48_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR2_48_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002218ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002218ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR2_48_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR2_48_63(a) cavm_prach_abx_nshift_bar2_48_63_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR2_48_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR2_48_63(a) "PRACH_ABX_NSHIFT_BAR2_48_63"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR2_48_63(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR2_48_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar3_0_15
 *
 * INTERNAL: Available Nshift_bar3 0 to 15 Register
 */
union cavm_prach_abx_nshift_bar3_0_15
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar3_0_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar3_15        : 4;  /**< [ 63: 60](R/W) 0~1 Available Nshift_bar3. Of 16th logical index */
        uint64_t nshift_bar3_14        : 4;  /**< [ 59: 56](R/W) 0~1 Available Nshift_bar3. Of 15th logical index */
        uint64_t nshift_bar3_13        : 4;  /**< [ 55: 52](R/W) 0~1 Available Nshift_bar3. Of 14th logical index */
        uint64_t nshift_bar3_12        : 4;  /**< [ 51: 48](R/W) 0~1 Available Nshift_bar3. Of 13th logical index */
        uint64_t nshift_bar3_11        : 4;  /**< [ 47: 44](R/W) 0~1 Available Nshift_bar3. Of 12th logical index */
        uint64_t nshift_bar3_10        : 4;  /**< [ 43: 40](R/W) 0~1 Available Nshift_bar3. Of 11th  logical index */
        uint64_t nshift_bar3_9         : 4;  /**< [ 39: 36](R/W) 0~1 Available Nshift_bar3. Of 10th logical index */
        uint64_t nshift_bar3_8         : 4;  /**< [ 35: 32](R/W) 0~1 Available Nshift_bar3. Of 9th logical index */
        uint64_t nshift_bar3_7         : 4;  /**< [ 31: 28](R/W) 0~1 Available Nshift_bar3. Of 8th logical index */
        uint64_t nshift_bar3_6         : 4;  /**< [ 27: 24](R/W) 0~1 Available Nshift_bar3. Of 7th logical index */
        uint64_t nshift_bar3_5         : 4;  /**< [ 23: 20](R/W) 0~1 Available Nshift_bar3. Of 6th logical index */
        uint64_t nshift_bar3_4         : 4;  /**< [ 19: 16](R/W) 0~1 Available Nshift_bar3. Of 5th logical index */
        uint64_t nshift_bar3_3         : 4;  /**< [ 15: 12](R/W) 0~1 Available Nshift_bar3. Of 4th logical index */
        uint64_t nshift_bar3_2         : 4;  /**< [ 11:  8](R/W) 0~1 Available Nshift_bar3. Of 3rd logical index */
        uint64_t nshift_bar3_1         : 4;  /**< [  7:  4](R/W) 0~1 Available Nshift_bar3. Of 2nd logical index */
        uint64_t nshift_bar3_0         : 4;  /**< [  3:  0](R/W) 0~1 Available Nshift_bar3. Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar3_0         : 4;  /**< [  3:  0](R/W) 0~1 Available Nshift_bar3. Of start logical index */
        uint64_t nshift_bar3_1         : 4;  /**< [  7:  4](R/W) 0~1 Available Nshift_bar3. Of 2nd logical index */
        uint64_t nshift_bar3_2         : 4;  /**< [ 11:  8](R/W) 0~1 Available Nshift_bar3. Of 3rd logical index */
        uint64_t nshift_bar3_3         : 4;  /**< [ 15: 12](R/W) 0~1 Available Nshift_bar3. Of 4th logical index */
        uint64_t nshift_bar3_4         : 4;  /**< [ 19: 16](R/W) 0~1 Available Nshift_bar3. Of 5th logical index */
        uint64_t nshift_bar3_5         : 4;  /**< [ 23: 20](R/W) 0~1 Available Nshift_bar3. Of 6th logical index */
        uint64_t nshift_bar3_6         : 4;  /**< [ 27: 24](R/W) 0~1 Available Nshift_bar3. Of 7th logical index */
        uint64_t nshift_bar3_7         : 4;  /**< [ 31: 28](R/W) 0~1 Available Nshift_bar3. Of 8th logical index */
        uint64_t nshift_bar3_8         : 4;  /**< [ 35: 32](R/W) 0~1 Available Nshift_bar3. Of 9th logical index */
        uint64_t nshift_bar3_9         : 4;  /**< [ 39: 36](R/W) 0~1 Available Nshift_bar3. Of 10th logical index */
        uint64_t nshift_bar3_10        : 4;  /**< [ 43: 40](R/W) 0~1 Available Nshift_bar3. Of 11th  logical index */
        uint64_t nshift_bar3_11        : 4;  /**< [ 47: 44](R/W) 0~1 Available Nshift_bar3. Of 12th logical index */
        uint64_t nshift_bar3_12        : 4;  /**< [ 51: 48](R/W) 0~1 Available Nshift_bar3. Of 13th logical index */
        uint64_t nshift_bar3_13        : 4;  /**< [ 55: 52](R/W) 0~1 Available Nshift_bar3. Of 14th logical index */
        uint64_t nshift_bar3_14        : 4;  /**< [ 59: 56](R/W) 0~1 Available Nshift_bar3. Of 15th logical index */
        uint64_t nshift_bar3_15        : 4;  /**< [ 63: 60](R/W) 0~1 Available Nshift_bar3. Of 16th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar3_0_15_s cn; */
};
typedef union cavm_prach_abx_nshift_bar3_0_15 cavm_prach_abx_nshift_bar3_0_15_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR3_0_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR3_0_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002220ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002220ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR3_0_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR3_0_15(a) cavm_prach_abx_nshift_bar3_0_15_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR3_0_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR3_0_15(a) "PRACH_ABX_NSHIFT_BAR3_0_15"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR3_0_15(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR3_0_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar3_16_31
 *
 * INTERNAL: Available Nshift_bar3 16 to 31 Register
 */
union cavm_prach_abx_nshift_bar3_16_31
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar3_16_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar3_31        : 4;  /**< [ 63: 60](R/W) 0~1. Available Nshift_bar3. Of 31th logical index */
        uint64_t nshift_bar3_30        : 4;  /**< [ 59: 56](R/W) 0~1. Available Nshift_bar3. Of 30th logical index */
        uint64_t nshift_bar3_29        : 4;  /**< [ 55: 52](R/W) 0~1. Available Nshift_bar3. Of 29th logical index */
        uint64_t nshift_bar3_28        : 4;  /**< [ 51: 48](R/W) 0~1. Available Nshift_bar3. Of 28th logical index */
        uint64_t nshift_bar3_27        : 4;  /**< [ 47: 44](R/W) 0~1. Available Nshift_bar3. Of 27th logical index */
        uint64_t nshift_bar3_26        : 4;  /**< [ 43: 40](R/W) 0~1. Available Nshift_bar3. Of 26th logical index */
        uint64_t nshift_bar3_25        : 4;  /**< [ 39: 36](R/W) 0~1. Available Nshift_bar3. Of 25th logical index */
        uint64_t nshift_bar3_24        : 4;  /**< [ 35: 32](R/W) 0~1. Available Nshift_bar3. Of 24th logical index */
        uint64_t nshift_bar3_23        : 4;  /**< [ 31: 28](R/W) 0~1. Available Nshift_bar3. Of 23th logical index */
        uint64_t nshift_bar3_22        : 4;  /**< [ 27: 24](R/W) 0~1. Available Nshift_bar3. Of 22th logical index */
        uint64_t nshift_bar3_21        : 4;  /**< [ 23: 20](R/W) 0~1. Available Nshift_bar3. Of 21th logical index */
        uint64_t nshift_bar3_20        : 4;  /**< [ 19: 16](R/W) 0~1. Available Nshift_bar3. Of 20th logical index */
        uint64_t nshift_bar3_19        : 4;  /**< [ 15: 12](R/W) 0~1. Available Nshift_bar3. Of 19th logical index */
        uint64_t nshift_bar3_18        : 4;  /**< [ 11:  8](R/W) 0~1. Available Nshift_bar3. Of 18th logical index */
        uint64_t nshift_bar3_17        : 4;  /**< [  7:  4](R/W) 0~1. Available Nshift_bar3. Of 17th logical index */
        uint64_t nshift_bar3_16        : 4;  /**< [  3:  0](R/W) 0~1. Available Nshift_bar3. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar3_16        : 4;  /**< [  3:  0](R/W) 0~1. Available Nshift_bar3. Of 16th logical index */
        uint64_t nshift_bar3_17        : 4;  /**< [  7:  4](R/W) 0~1. Available Nshift_bar3. Of 17th logical index */
        uint64_t nshift_bar3_18        : 4;  /**< [ 11:  8](R/W) 0~1. Available Nshift_bar3. Of 18th logical index */
        uint64_t nshift_bar3_19        : 4;  /**< [ 15: 12](R/W) 0~1. Available Nshift_bar3. Of 19th logical index */
        uint64_t nshift_bar3_20        : 4;  /**< [ 19: 16](R/W) 0~1. Available Nshift_bar3. Of 20th logical index */
        uint64_t nshift_bar3_21        : 4;  /**< [ 23: 20](R/W) 0~1. Available Nshift_bar3. Of 21th logical index */
        uint64_t nshift_bar3_22        : 4;  /**< [ 27: 24](R/W) 0~1. Available Nshift_bar3. Of 22th logical index */
        uint64_t nshift_bar3_23        : 4;  /**< [ 31: 28](R/W) 0~1. Available Nshift_bar3. Of 23th logical index */
        uint64_t nshift_bar3_24        : 4;  /**< [ 35: 32](R/W) 0~1. Available Nshift_bar3. Of 24th logical index */
        uint64_t nshift_bar3_25        : 4;  /**< [ 39: 36](R/W) 0~1. Available Nshift_bar3. Of 25th logical index */
        uint64_t nshift_bar3_26        : 4;  /**< [ 43: 40](R/W) 0~1. Available Nshift_bar3. Of 26th logical index */
        uint64_t nshift_bar3_27        : 4;  /**< [ 47: 44](R/W) 0~1. Available Nshift_bar3. Of 27th logical index */
        uint64_t nshift_bar3_28        : 4;  /**< [ 51: 48](R/W) 0~1. Available Nshift_bar3. Of 28th logical index */
        uint64_t nshift_bar3_29        : 4;  /**< [ 55: 52](R/W) 0~1. Available Nshift_bar3. Of 29th logical index */
        uint64_t nshift_bar3_30        : 4;  /**< [ 59: 56](R/W) 0~1. Available Nshift_bar3. Of 30th logical index */
        uint64_t nshift_bar3_31        : 4;  /**< [ 63: 60](R/W) 0~1. Available Nshift_bar3. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar3_16_31_s cn; */
};
typedef union cavm_prach_abx_nshift_bar3_16_31 cavm_prach_abx_nshift_bar3_16_31_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR3_16_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR3_16_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002228ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002228ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR3_16_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR3_16_31(a) cavm_prach_abx_nshift_bar3_16_31_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR3_16_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR3_16_31(a) "PRACH_ABX_NSHIFT_BAR3_16_31"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR3_16_31(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR3_16_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar3_32_47
 *
 * INTERNAL: Available Nshift_bar3 32 to 47 Register
 */
union cavm_prach_abx_nshift_bar3_32_47
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar3_32_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar3_47        : 4;  /**< [ 63: 60](R/W) 0~1. Available Nshift_bar3. Of 47th logical index */
        uint64_t nshift_bar3_46        : 4;  /**< [ 59: 56](R/W) 0~1. Available Nshift_bar3. Of 46th logical index */
        uint64_t nshift_bar3_45        : 4;  /**< [ 55: 52](R/W) 0~1. Available Nshift_bar3. Of 45th logical index */
        uint64_t nshift_bar3_44        : 4;  /**< [ 51: 48](R/W) 0~1. Available Nshift_bar3. Of 44th logical index */
        uint64_t nshift_bar3_43        : 4;  /**< [ 47: 44](R/W) 0~1. Available Nshift_bar3. Of 43th logical index */
        uint64_t nshift_bar3_42        : 4;  /**< [ 43: 40](R/W) 0~1. Available Nshift_bar3. Of 42th logical index */
        uint64_t nshift_bar3_41        : 4;  /**< [ 39: 36](R/W) 0~1. Available Nshift_bar3. Of 41th logical index */
        uint64_t nshift_bar3_40        : 4;  /**< [ 35: 32](R/W) 0~1. Available Nshift_bar3. Of 40th logical index */
        uint64_t nshift_bar3_39        : 4;  /**< [ 31: 28](R/W) 0~1. Available Nshift_bar3. Of 39th logical index */
        uint64_t nshift_bar3_38        : 4;  /**< [ 27: 24](R/W) 0~1. Available Nshift_bar3. Of 38th logical index */
        uint64_t nshift_bar3_37        : 4;  /**< [ 23: 20](R/W) 0~1. Available Nshift_bar3. Of 37th logical index */
        uint64_t nshift_bar3_36        : 4;  /**< [ 19: 16](R/W) 0~1. Available Nshift_bar3. Of 36th logical index */
        uint64_t nshift_bar3_35        : 4;  /**< [ 15: 12](R/W) 0~1. Available Nshift_bar3. Of 35th logical index */
        uint64_t nshift_bar3_34        : 4;  /**< [ 11:  8](R/W) 0~1. Available Nshift_bar3. Of 34th logical index */
        uint64_t nshift_bar3_33        : 4;  /**< [  7:  4](R/W) 0~1. Available Nshift_bar3. Of 33th logical index */
        uint64_t nshift_bar3_32        : 4;  /**< [  3:  0](R/W) 0~1. Available Nshift_bar3. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar3_32        : 4;  /**< [  3:  0](R/W) 0~1. Available Nshift_bar3. Of 32th logical index */
        uint64_t nshift_bar3_33        : 4;  /**< [  7:  4](R/W) 0~1. Available Nshift_bar3. Of 33th logical index */
        uint64_t nshift_bar3_34        : 4;  /**< [ 11:  8](R/W) 0~1. Available Nshift_bar3. Of 34th logical index */
        uint64_t nshift_bar3_35        : 4;  /**< [ 15: 12](R/W) 0~1. Available Nshift_bar3. Of 35th logical index */
        uint64_t nshift_bar3_36        : 4;  /**< [ 19: 16](R/W) 0~1. Available Nshift_bar3. Of 36th logical index */
        uint64_t nshift_bar3_37        : 4;  /**< [ 23: 20](R/W) 0~1. Available Nshift_bar3. Of 37th logical index */
        uint64_t nshift_bar3_38        : 4;  /**< [ 27: 24](R/W) 0~1. Available Nshift_bar3. Of 38th logical index */
        uint64_t nshift_bar3_39        : 4;  /**< [ 31: 28](R/W) 0~1. Available Nshift_bar3. Of 39th logical index */
        uint64_t nshift_bar3_40        : 4;  /**< [ 35: 32](R/W) 0~1. Available Nshift_bar3. Of 40th logical index */
        uint64_t nshift_bar3_41        : 4;  /**< [ 39: 36](R/W) 0~1. Available Nshift_bar3. Of 41th logical index */
        uint64_t nshift_bar3_42        : 4;  /**< [ 43: 40](R/W) 0~1. Available Nshift_bar3. Of 42th logical index */
        uint64_t nshift_bar3_43        : 4;  /**< [ 47: 44](R/W) 0~1. Available Nshift_bar3. Of 43th logical index */
        uint64_t nshift_bar3_44        : 4;  /**< [ 51: 48](R/W) 0~1. Available Nshift_bar3. Of 44th logical index */
        uint64_t nshift_bar3_45        : 4;  /**< [ 55: 52](R/W) 0~1. Available Nshift_bar3. Of 45th logical index */
        uint64_t nshift_bar3_46        : 4;  /**< [ 59: 56](R/W) 0~1. Available Nshift_bar3. Of 46th logical index */
        uint64_t nshift_bar3_47        : 4;  /**< [ 63: 60](R/W) 0~1. Available Nshift_bar3. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar3_32_47_s cn; */
};
typedef union cavm_prach_abx_nshift_bar3_32_47 cavm_prach_abx_nshift_bar3_32_47_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR3_32_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR3_32_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002230ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002230ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR3_32_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR3_32_47(a) cavm_prach_abx_nshift_bar3_32_47_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR3_32_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR3_32_47(a) "PRACH_ABX_NSHIFT_BAR3_32_47"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR3_32_47(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR3_32_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar3_48_63
 *
 * INTERNAL: Available Nshift_bar3 48 to 63 Register
 */
union cavm_prach_abx_nshift_bar3_48_63
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar3_48_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar3_63        : 4;  /**< [ 63: 60](R/W) 0~1. Available Nshift_bar3. Of 63th logical index */
        uint64_t nshift_bar3_62        : 4;  /**< [ 59: 56](R/W) 0~1. Available Nshift_bar3. Of 62th logical index */
        uint64_t nshift_bar3_61        : 4;  /**< [ 55: 52](R/W) 0~1. Available Nshift_bar3. Of 61th logical index */
        uint64_t nshift_bar3_60        : 4;  /**< [ 51: 48](R/W) 0~1. Available Nshift_bar3. Of 60th logical index */
        uint64_t nshift_bar3_59        : 4;  /**< [ 47: 44](R/W) 0~1. Available Nshift_bar3. Of 59th logical index */
        uint64_t nshift_bar3_58        : 4;  /**< [ 43: 40](R/W) 0~1. Available Nshift_bar3. Of 58th logical index */
        uint64_t nshift_bar3_57        : 4;  /**< [ 39: 36](R/W) 0~1. Available Nshift_bar3. Of 57th logical index */
        uint64_t nshift_bar3_56        : 4;  /**< [ 35: 32](R/W) 0~1. Available Nshift_bar3. Of 56th logical index */
        uint64_t nshift_bar3_55        : 4;  /**< [ 31: 28](R/W) 0~1. Available Nshift_bar3. Of 55th logical index */
        uint64_t nshift_bar3_54        : 4;  /**< [ 27: 24](R/W) 0~1. Available Nshift_bar3. Of 54th logical index */
        uint64_t nshift_bar3_53        : 4;  /**< [ 23: 20](R/W) 0~1. Available Nshift_bar3. Of 53th logical index */
        uint64_t nshift_bar3_52        : 4;  /**< [ 19: 16](R/W) 0~1. Available Nshift_bar3. Of 52th logical index */
        uint64_t nshift_bar3_51        : 4;  /**< [ 15: 12](R/W) 0~1. Available Nshift_bar3. Of 51th logical index */
        uint64_t nshift_bar3_50        : 4;  /**< [ 11:  8](R/W) 0~1. Available Nshift_bar3. Of 50th logical index */
        uint64_t nshift_bar3_49        : 4;  /**< [  7:  4](R/W) 0~1. Available Nshift_bar3. Of 49th logical index */
        uint64_t nshift_bar3_48        : 4;  /**< [  3:  0](R/W) 0~1. Available Nshift_bar3. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar3_48        : 4;  /**< [  3:  0](R/W) 0~1. Available Nshift_bar3. Of 48th logical index */
        uint64_t nshift_bar3_49        : 4;  /**< [  7:  4](R/W) 0~1. Available Nshift_bar3. Of 49th logical index */
        uint64_t nshift_bar3_50        : 4;  /**< [ 11:  8](R/W) 0~1. Available Nshift_bar3. Of 50th logical index */
        uint64_t nshift_bar3_51        : 4;  /**< [ 15: 12](R/W) 0~1. Available Nshift_bar3. Of 51th logical index */
        uint64_t nshift_bar3_52        : 4;  /**< [ 19: 16](R/W) 0~1. Available Nshift_bar3. Of 52th logical index */
        uint64_t nshift_bar3_53        : 4;  /**< [ 23: 20](R/W) 0~1. Available Nshift_bar3. Of 53th logical index */
        uint64_t nshift_bar3_54        : 4;  /**< [ 27: 24](R/W) 0~1. Available Nshift_bar3. Of 54th logical index */
        uint64_t nshift_bar3_55        : 4;  /**< [ 31: 28](R/W) 0~1. Available Nshift_bar3. Of 55th logical index */
        uint64_t nshift_bar3_56        : 4;  /**< [ 35: 32](R/W) 0~1. Available Nshift_bar3. Of 56th logical index */
        uint64_t nshift_bar3_57        : 4;  /**< [ 39: 36](R/W) 0~1. Available Nshift_bar3. Of 57th logical index */
        uint64_t nshift_bar3_58        : 4;  /**< [ 43: 40](R/W) 0~1. Available Nshift_bar3. Of 58th logical index */
        uint64_t nshift_bar3_59        : 4;  /**< [ 47: 44](R/W) 0~1. Available Nshift_bar3. Of 59th logical index */
        uint64_t nshift_bar3_60        : 4;  /**< [ 51: 48](R/W) 0~1. Available Nshift_bar3. Of 60th logical index */
        uint64_t nshift_bar3_61        : 4;  /**< [ 55: 52](R/W) 0~1. Available Nshift_bar3. Of 61th logical index */
        uint64_t nshift_bar3_62        : 4;  /**< [ 59: 56](R/W) 0~1. Available Nshift_bar3. Of 62th logical index */
        uint64_t nshift_bar3_63        : 4;  /**< [ 63: 60](R/W) 0~1. Available Nshift_bar3. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar3_48_63_s cn; */
};
typedef union cavm_prach_abx_nshift_bar3_48_63 cavm_prach_abx_nshift_bar3_48_63_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR3_48_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR3_48_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002238ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002238ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR3_48_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR3_48_63(a) cavm_prach_abx_nshift_bar3_48_63_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR3_48_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR3_48_63(a) "PRACH_ABX_NSHIFT_BAR3_48_63"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR3_48_63(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR3_48_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar_0_7
 *
 * INTERNAL: Available Nshift_bar 0_7 Register
 */
union cavm_prach_abx_nshift_bar_0_7
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar_0_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar_7          : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 8th logical index */
        uint64_t nshift_bar_6          : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 7th logical index */
        uint64_t nshift_bar_5          : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 6th logical index */
        uint64_t nshift_bar_4          : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 5th logical index */
        uint64_t nshift_bar_3          : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 4th logical index */
        uint64_t nshift_bar_2          : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 3rd logical index */
        uint64_t nshift_bar_1          : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 2nd logical index */
        uint64_t nshift_bar_0          : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of start logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar_0          : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of start logical index */
        uint64_t nshift_bar_1          : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 2nd logical index */
        uint64_t nshift_bar_2          : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 3rd logical index */
        uint64_t nshift_bar_3          : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 4th logical index */
        uint64_t nshift_bar_4          : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 5th logical index */
        uint64_t nshift_bar_5          : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 6th logical index */
        uint64_t nshift_bar_6          : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 7th logical index */
        uint64_t nshift_bar_7          : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 8th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar_0_7_s cn; */
};
typedef union cavm_prach_abx_nshift_bar_0_7 cavm_prach_abx_nshift_bar_0_7_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_0_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_0_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020c0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR_0_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR_0_7(a) cavm_prach_abx_nshift_bar_0_7_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR_0_7(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR_0_7(a) "PRACH_ABX_NSHIFT_BAR_0_7"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR_0_7(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR_0_7(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar_16_23
 *
 * INTERNAL: Available Nshift_bar 16 to 23 Register
 */
union cavm_prach_abx_nshift_bar_16_23
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar_16_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar_23         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 23th logical index */
        uint64_t nshift_bar_22         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 22th logical index */
        uint64_t nshift_bar_21         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 21th logical index */
        uint64_t nshift_bar_20         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 20th logical index */
        uint64_t nshift_bar_19         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 19th logical index */
        uint64_t nshift_bar_18         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 18th logical index */
        uint64_t nshift_bar_17         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 17th logical index */
        uint64_t nshift_bar_16         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 16th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar_16         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 16th logical index */
        uint64_t nshift_bar_17         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 17th logical index */
        uint64_t nshift_bar_18         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 18th logical index */
        uint64_t nshift_bar_19         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 19th logical index */
        uint64_t nshift_bar_20         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 20th logical index */
        uint64_t nshift_bar_21         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 21th logical index */
        uint64_t nshift_bar_22         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 22th logical index */
        uint64_t nshift_bar_23         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 23th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar_16_23_s cn; */
};
typedef union cavm_prach_abx_nshift_bar_16_23 cavm_prach_abx_nshift_bar_16_23_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_16_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_16_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020d0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR_16_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR_16_23(a) cavm_prach_abx_nshift_bar_16_23_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR_16_23(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR_16_23(a) "PRACH_ABX_NSHIFT_BAR_16_23"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR_16_23(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR_16_23(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar_24_31
 *
 * INTERNAL: Available Nshift_bar 24 to 31 Register
 */
union cavm_prach_abx_nshift_bar_24_31
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar_24_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar_31         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 31th logical index */
        uint64_t nshift_bar_30         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 30th logical index */
        uint64_t nshift_bar_29         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 29th logical index */
        uint64_t nshift_bar_28         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 28th logical index */
        uint64_t nshift_bar_27         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 27th logical index */
        uint64_t nshift_bar_26         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 26th logical index */
        uint64_t nshift_bar_25         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 25th logical index */
        uint64_t nshift_bar_24         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 24th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar_24         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 24th logical index */
        uint64_t nshift_bar_25         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 25th logical index */
        uint64_t nshift_bar_26         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 26th logical index */
        uint64_t nshift_bar_27         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 27th logical index */
        uint64_t nshift_bar_28         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 28th logical index */
        uint64_t nshift_bar_29         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 29th logical index */
        uint64_t nshift_bar_30         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 30th logical index */
        uint64_t nshift_bar_31         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 31th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar_24_31_s cn; */
};
typedef union cavm_prach_abx_nshift_bar_24_31 cavm_prach_abx_nshift_bar_24_31_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_24_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_24_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020d8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR_24_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR_24_31(a) cavm_prach_abx_nshift_bar_24_31_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR_24_31(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR_24_31(a) "PRACH_ABX_NSHIFT_BAR_24_31"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR_24_31(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR_24_31(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar_32_39
 *
 * INTERNAL: Available Nshift_bar 32 to 39 Register
 */
union cavm_prach_abx_nshift_bar_32_39
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar_32_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar_39         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 39th logical index */
        uint64_t nshift_bar_38         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 38th logical index */
        uint64_t nshift_bar_37         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 37th logical index */
        uint64_t nshift_bar_36         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 36th logical index */
        uint64_t nshift_bar_35         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 35th logical index */
        uint64_t nshift_bar_34         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 34th logical index */
        uint64_t nshift_bar_33         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 33th logical index */
        uint64_t nshift_bar_32         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 32th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar_32         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 32th logical index */
        uint64_t nshift_bar_33         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 33th logical index */
        uint64_t nshift_bar_34         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 34th logical index */
        uint64_t nshift_bar_35         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 35th logical index */
        uint64_t nshift_bar_36         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 36th logical index */
        uint64_t nshift_bar_37         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 37th logical index */
        uint64_t nshift_bar_38         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 38th logical index */
        uint64_t nshift_bar_39         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 39th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar_32_39_s cn; */
};
typedef union cavm_prach_abx_nshift_bar_32_39 cavm_prach_abx_nshift_bar_32_39_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_32_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_32_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020e0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR_32_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR_32_39(a) cavm_prach_abx_nshift_bar_32_39_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR_32_39(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR_32_39(a) "PRACH_ABX_NSHIFT_BAR_32_39"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR_32_39(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR_32_39(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar_40_47
 *
 * INTERNAL: Available Nshift_bar 40 to 47 Register
 */
union cavm_prach_abx_nshift_bar_40_47
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar_40_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar_47         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 47th logical index */
        uint64_t nshift_bar_46         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 46th logical index */
        uint64_t nshift_bar_45         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 45th logical index */
        uint64_t nshift_bar_44         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 44th logical index */
        uint64_t nshift_bar_43         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 43th logical index */
        uint64_t nshift_bar_42         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 42th logical index */
        uint64_t nshift_bar_41         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 41th logical index */
        uint64_t nshift_bar_40         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 40th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar_40         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 40th logical index */
        uint64_t nshift_bar_41         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 41th logical index */
        uint64_t nshift_bar_42         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 42th logical index */
        uint64_t nshift_bar_43         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 43th logical index */
        uint64_t nshift_bar_44         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 44th logical index */
        uint64_t nshift_bar_45         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 45th logical index */
        uint64_t nshift_bar_46         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 46th logical index */
        uint64_t nshift_bar_47         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 47th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar_40_47_s cn; */
};
typedef union cavm_prach_abx_nshift_bar_40_47 cavm_prach_abx_nshift_bar_40_47_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_40_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_40_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020e8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR_40_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR_40_47(a) cavm_prach_abx_nshift_bar_40_47_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR_40_47(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR_40_47(a) "PRACH_ABX_NSHIFT_BAR_40_47"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR_40_47(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR_40_47(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar_48_55
 *
 * INTERNAL: Available Nshift_bar 48 to 55 Register
 */
union cavm_prach_abx_nshift_bar_48_55
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar_48_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar_55         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 55th logical index */
        uint64_t nshift_bar_54         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 54th logical index */
        uint64_t nshift_bar_53         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 53th logical index */
        uint64_t nshift_bar_52         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 52th logical index */
        uint64_t nshift_bar_51         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 51th logical index */
        uint64_t nshift_bar_50         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 50th logical index */
        uint64_t nshift_bar_49         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 49th logical index */
        uint64_t nshift_bar_48         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 48th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar_48         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 48th logical index */
        uint64_t nshift_bar_49         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 49th logical index */
        uint64_t nshift_bar_50         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 50th logical index */
        uint64_t nshift_bar_51         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 51th logical index */
        uint64_t nshift_bar_52         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 52th logical index */
        uint64_t nshift_bar_53         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 53th logical index */
        uint64_t nshift_bar_54         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 54th logical index */
        uint64_t nshift_bar_55         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 55th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar_48_55_s cn; */
};
typedef union cavm_prach_abx_nshift_bar_48_55 cavm_prach_abx_nshift_bar_48_55_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_48_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_48_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020f0ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR_48_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR_48_55(a) cavm_prach_abx_nshift_bar_48_55_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR_48_55(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR_48_55(a) "PRACH_ABX_NSHIFT_BAR_48_55"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR_48_55(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR_48_55(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar_56_63
 *
 * INTERNAL: Available Nshift_bar 56 to 63 Register
 */
union cavm_prach_abx_nshift_bar_56_63
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar_56_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar_63         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 63th logical index */
        uint64_t nshift_bar_62         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 62th logical index */
        uint64_t nshift_bar_61         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 61th logical index */
        uint64_t nshift_bar_60         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 60th logical index */
        uint64_t nshift_bar_59         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 59th logical index */
        uint64_t nshift_bar_58         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 58th logical index */
        uint64_t nshift_bar_57         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 57th logical index */
        uint64_t nshift_bar_56         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 56th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar_56         : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 56th logical index */
        uint64_t nshift_bar_57         : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 57th logical index */
        uint64_t nshift_bar_58         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 58th logical index */
        uint64_t nshift_bar_59         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 59th logical index */
        uint64_t nshift_bar_60         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 60th logical index */
        uint64_t nshift_bar_61         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 61th logical index */
        uint64_t nshift_bar_62         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 62th logical index */
        uint64_t nshift_bar_63         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 63th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar_56_63_s cn; */
};
typedef union cavm_prach_abx_nshift_bar_56_63 cavm_prach_abx_nshift_bar_56_63_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_56_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_56_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020f8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR_56_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR_56_63(a) cavm_prach_abx_nshift_bar_56_63_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR_56_63(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR_56_63(a) "PRACH_ABX_NSHIFT_BAR_56_63"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR_56_63(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR_56_63(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_nshift_bar_8_15
 *
 * INTERNAL: Available Nshift_bar 8 to 15 Register
 */
union cavm_prach_abx_nshift_bar_8_15
{
    uint64_t u;
    struct cavm_prach_abx_nshift_bar_8_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nshift_bar_15         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 15th logical index */
        uint64_t nshift_bar_14         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 14th logical index */
        uint64_t nshift_bar_13         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 13th logical index */
        uint64_t nshift_bar_12         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 12th logical index */
        uint64_t nshift_bar_11         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 11th logical index */
        uint64_t nshift_bar_10         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 10th logical index */
        uint64_t nshift_bar_9          : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 9th logical index */
        uint64_t nshift_bar_8          : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 8th logical index */
#else /* Word 0 - Little Endian */
        uint64_t nshift_bar_8          : 8;  /**< [  7:  0](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 8th logical index */
        uint64_t nshift_bar_9          : 8;  /**< [ 15:  8](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 9th logical index */
        uint64_t nshift_bar_10         : 8;  /**< [ 23: 16](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 10th logical index */
        uint64_t nshift_bar_11         : 8;  /**< [ 31: 24](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 11th logical index */
        uint64_t nshift_bar_12         : 8;  /**< [ 39: 32](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 12th logical index */
        uint64_t nshift_bar_13         : 8;  /**< [ 47: 40](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 13th logical index */
        uint64_t nshift_bar_14         : 8;  /**< [ 55: 48](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 14th logical index */
        uint64_t nshift_bar_15         : 8;  /**< [ 63: 56](R/W) (3'd0, 5'd(0~18)) Available Nshift_bar. Of 15th logical index */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_nshift_bar_8_15_s cn; */
};
typedef union cavm_prach_abx_nshift_bar_8_15 cavm_prach_abx_nshift_bar_8_15_t;

static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_8_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_NSHIFT_BAR_8_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0430020c8ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e0430020c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_NSHIFT_BAR_8_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_NSHIFT_BAR_8_15(a) cavm_prach_abx_nshift_bar_8_15_t
#define bustype_CAVM_PRACH_ABX_NSHIFT_BAR_8_15(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_NSHIFT_BAR_8_15(a) "PRACH_ABX_NSHIFT_BAR_8_15"
#define busnum_CAVM_PRACH_ABX_NSHIFT_BAR_8_15(a) (a)
#define arguments_CAVM_PRACH_ABX_NSHIFT_BAR_8_15(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_profiler_coh_comb
 *
 * INTERNAL: Profiler COH_COMB Register
 */
union cavm_prach_abx_profiler_coh_comb
{
    uint64_t u;
    struct cavm_prach_abx_profiler_coh_comb_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t psym_bitmapb          : 12; /**< [ 35: 24](R/W) Specific symbol on/off for coherent combine (Detector B)- 0~0xfff
                                                                 Bit postion means symbol number from LSB. Default - 0xfff */
        uint64_t psym_bitmapa          : 12; /**< [ 23: 12](R/W) Specific symbol on/off for coherent combine (Detector A)- 0~0xfff
                                                                 Bit postion means symbol number from LSB. Default - 0xfff */
        uint64_t reserved_10_11        : 2;
        uint64_t tab_off               : 4;  /**< [  9:  6](R/W) Zero correlation zone size reduce for eliminating flase alarm:-0~15. Default - 3 */
        uint64_t smax_w                : 6;  /**< [  5:  0](R/W) Multipath search window- 3~40. Default - 13 (format 0,1,2,3),  20 (format 4) */
#else /* Word 0 - Little Endian */
        uint64_t smax_w                : 6;  /**< [  5:  0](R/W) Multipath search window- 3~40. Default - 13 (format 0,1,2,3),  20 (format 4) */
        uint64_t tab_off               : 4;  /**< [  9:  6](R/W) Zero correlation zone size reduce for eliminating flase alarm:-0~15. Default - 3 */
        uint64_t reserved_10_11        : 2;
        uint64_t psym_bitmapa          : 12; /**< [ 23: 12](R/W) Specific symbol on/off for coherent combine (Detector A)- 0~0xfff
                                                                 Bit postion means symbol number from LSB. Default - 0xfff */
        uint64_t psym_bitmapb          : 12; /**< [ 35: 24](R/W) Specific symbol on/off for coherent combine (Detector B)- 0~0xfff
                                                                 Bit postion means symbol number from LSB. Default - 0xfff */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_profiler_coh_comb_s cn; */
};
typedef union cavm_prach_abx_profiler_coh_comb cavm_prach_abx_profiler_coh_comb_t;

static inline uint64_t CAVM_PRACH_ABX_PROFILER_COH_COMB(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_PROFILER_COH_COMB(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002028ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002028ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_PROFILER_COH_COMB", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_PROFILER_COH_COMB(a) cavm_prach_abx_profiler_coh_comb_t
#define bustype_CAVM_PRACH_ABX_PROFILER_COH_COMB(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_PROFILER_COH_COMB(a) "PRACH_ABX_PROFILER_COH_COMB"
#define busnum_CAVM_PRACH_ABX_PROFILER_COH_COMB(a) (a)
#define arguments_CAVM_PRACH_ABX_PROFILER_COH_COMB(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_reserved_reg_0
 *
 * INTERNAL: Reserved Register 0
 */
union cavm_prach_abx_reserved_reg_0
{
    uint64_t u;
    struct cavm_prach_abx_reserved_reg_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_reserved_reg_0_s cn; */
};
typedef union cavm_prach_abx_reserved_reg_0 cavm_prach_abx_reserved_reg_0_t;

static inline uint64_t CAVM_PRACH_ABX_RESERVED_REG_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_RESERVED_REG_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002018ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_RESERVED_REG_0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_RESERVED_REG_0(a) cavm_prach_abx_reserved_reg_0_t
#define bustype_CAVM_PRACH_ABX_RESERVED_REG_0(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_RESERVED_REG_0(a) "PRACH_ABX_RESERVED_REG_0"
#define busnum_CAVM_PRACH_ABX_RESERVED_REG_0(a) (a)
#define arguments_CAVM_PRACH_ABX_RESERVED_REG_0(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_reserved_reg_1
 *
 * INTERNAL: Reserved Register 1
 */
union cavm_prach_abx_reserved_reg_1
{
    uint64_t u;
    struct cavm_prach_abx_reserved_reg_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_reserved_reg_1_s cn; */
};
typedef union cavm_prach_abx_reserved_reg_1 cavm_prach_abx_reserved_reg_1_t;

static inline uint64_t CAVM_PRACH_ABX_RESERVED_REG_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_RESERVED_REG_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002038ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_RESERVED_REG_1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_RESERVED_REG_1(a) cavm_prach_abx_reserved_reg_1_t
#define bustype_CAVM_PRACH_ABX_RESERVED_REG_1(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_RESERVED_REG_1(a) "PRACH_ABX_RESERVED_REG_1"
#define busnum_CAVM_PRACH_ABX_RESERVED_REG_1(a) (a)
#define arguments_CAVM_PRACH_ABX_RESERVED_REG_1(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_system_config
 *
 * INTERNAL: System Configuration Register
 */
union cavm_prach_abx_system_config
{
    uint64_t u;
    struct cavm_prach_abx_system_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t antenna_7_on          : 1;  /**< [ 61: 61](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_6_on          : 1;  /**< [ 60: 60](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_5_on          : 1;  /**< [ 59: 59](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_4_on          : 1;  /**< [ 58: 58](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_3_on          : 1;  /**< [ 57: 57](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_2_on          : 1;  /**< [ 56: 56](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_1_on          : 1;  /**< [ 55: 55](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_0_on          : 1;  /**< [ 54: 54](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t n_repetition          : 3;  /**< [ 53: 51](R/W) Number of repetition for eMTC in processing job. Default - 0
                                                                   0-1
                                                                   1-2
                                                                   2-4
                                                                   3-8
                                                                   4-16
                                                                   5-32
                                                                   6-64
                                                                   7-128 */
        uint64_t freq_pos              : 1;  /**< [ 50: 50](R/W) 0~1, Frequency position for 1024 FFT. Default - 0 */
        uint64_t fft_1024              : 1;  /**< [ 49: 49](R/W) 1024 FFT selection for legacy F4 freq. multiplexing
                                                                 0 - 1024 FFT mode off, 1 - 1024 FFT mode on. Default - 0 */
        uint64_t in_sam_offset         : 1;  /**< [ 48: 48](R/W) Input sample offset (0 or 1) Default - 0 */
        uint64_t num_of_preamble       : 6;  /**< [ 47: 42](R/W) Number of preamble for detection. Default - 63
                                                                 0-1, 1-2, ... 63-64 */
        uint64_t n_coh                 : 3;  /**< [ 41: 39](R/W) Number of  symbol for coherent combine. Default - 0
                                                                        0-1
                                                                        1-2
                                                                        2-3
                                                                        3-4
                                                                        4-6
                                                                        5-8
                                                                        6-12
                                                                        7-24 */
        uint64_t num_of_ant            : 3;  /**< [ 38: 36](R/W) "This field  should be like bellows according to iteration of job
                                                                 At 1st job (eMTC start job) Set 2 (ant #0 ~ ant #7)]
                                                                 At 2nd job (eMTC correlation job) set 3 (ant #8 ~ ant #15)]
                                                                 At 3rd job (eMTC correlation job) Set 4 (ant #16 ~ ant #23)]
                                                                 At 4th job (eMTC peak detection job) Set 5 (ant #24 ~ ant #31)]
                                                                 0 : 2 antenna
                                                                 1 : 4 antenna
                                                                 2 : 8 antenna
                                                                 3 : 16 antenna
                                                                 4 : 24 antenna
                                                                 5 : 32 antenna" */
        uint64_t prach_type            : 2;  /**< [ 35: 34](R/W) PRACH type
                                                                 0 : LTE
                                                                 1 : eMTC
                                                                 2 : NR long
                                                                 3 : NR short */
        uint64_t preamble_format       : 4;  /**< [ 33: 30](R/W) LTE, NR input format
                                                                 - LTE, eMTC
                                                                 0 : LTE f0
                                                                 1 : LTE f1
                                                                 2 : LTE f2
                                                                 3 : LTE f3
                                                                 4 : LTE f4
                                                                 - NR long
                                                                 0 : NR long f0
                                                                 1 : NR long f1
                                                                 2 : NR long f2
                                                                 3 : NR long f3
                                                                 - NR short
                                                                 0 : NR short A0
                                                                 1 : NR short A1
                                                                 2 : NR short A2
                                                                 3 : NR short A3
                                                                 4 : NR short B1
                                                                 5 : NR short B2
                                                                 6 : NR short B3
                                                                 7 : NR short B4
                                                                 8 : NR short C0
                                                                 9 : NR short C2 */
        uint64_t reserved_28_29        : 2;
        uint64_t tagc_psym             : 2;  /**< [ 27: 26](R/W) Preamble symbol position for TAGC power calculation, 0~2. Default : 0 */
        uint64_t db_conv_mode          : 1;  /**< [ 25: 25](R/W) 0: 0.1dB resolution (default)
                                                                 1: 0.01 dB resolution */
        uint64_t reserved_23_24        : 2;
        uint64_t mrc_mode              : 1;  /**< [ 22: 22](R/W) 0 - EGC mode (defult), 1 - MRC mode */
        uint64_t high_speed_set        : 2;  /**< [ 21: 20](R/W) 0 - normal mode (unrestricted set)
                                                                 1 - high speed mode (restricted set type A)
                                                                 2 - very high speed mode (restricted set type B)
                                                                 Default - 0. 1 or 2 - when CE_OCC_MODE is 0 */
        uint64_t n_zone                : 6;  /**< [ 19: 14](R/W) Number of zero correlation zone per 1 root seq.
                                                                 Floor(839/Ncs) or Floor(139/ncs)
                                                                 This field is Valid if NCS_INPUT_MODE = 1
                                                                 0:1, 1:2 ... 63:64 */
        uint64_t ncs_input_mode        : 1;  /**< [ 13: 13](R/W) 0 - configuration value input (NCS_CONFIGURATION). Default - 0
                                                                 1 - Ncs value direct input (NCS_VALUE_DIRECT) */
        uint64_t ncs_value_direct      : 9;  /**< [ 12:  4](R/W) Ncs value. For preparation of spec. change
                                                                 This field is Valid if NCS_INPUT_MODE = 1 */
        uint64_t ncs_configuration     : 4;  /**< [  3:  0](R/W) Zero correlation zone config. value (0~15)
                                                                 Necessary number of root sequences is decided by this filed
                                                                 (cf. Table 5.7.2-2, 3 (36.211 spec.)) */
#else /* Word 0 - Little Endian */
        uint64_t ncs_configuration     : 4;  /**< [  3:  0](R/W) Zero correlation zone config. value (0~15)
                                                                 Necessary number of root sequences is decided by this filed
                                                                 (cf. Table 5.7.2-2, 3 (36.211 spec.)) */
        uint64_t ncs_value_direct      : 9;  /**< [ 12:  4](R/W) Ncs value. For preparation of spec. change
                                                                 This field is Valid if NCS_INPUT_MODE = 1 */
        uint64_t ncs_input_mode        : 1;  /**< [ 13: 13](R/W) 0 - configuration value input (NCS_CONFIGURATION). Default - 0
                                                                 1 - Ncs value direct input (NCS_VALUE_DIRECT) */
        uint64_t n_zone                : 6;  /**< [ 19: 14](R/W) Number of zero correlation zone per 1 root seq.
                                                                 Floor(839/Ncs) or Floor(139/ncs)
                                                                 This field is Valid if NCS_INPUT_MODE = 1
                                                                 0:1, 1:2 ... 63:64 */
        uint64_t high_speed_set        : 2;  /**< [ 21: 20](R/W) 0 - normal mode (unrestricted set)
                                                                 1 - high speed mode (restricted set type A)
                                                                 2 - very high speed mode (restricted set type B)
                                                                 Default - 0. 1 or 2 - when CE_OCC_MODE is 0 */
        uint64_t mrc_mode              : 1;  /**< [ 22: 22](R/W) 0 - EGC mode (defult), 1 - MRC mode */
        uint64_t reserved_23_24        : 2;
        uint64_t db_conv_mode          : 1;  /**< [ 25: 25](R/W) 0: 0.1dB resolution (default)
                                                                 1: 0.01 dB resolution */
        uint64_t tagc_psym             : 2;  /**< [ 27: 26](R/W) Preamble symbol position for TAGC power calculation, 0~2. Default : 0 */
        uint64_t reserved_28_29        : 2;
        uint64_t preamble_format       : 4;  /**< [ 33: 30](R/W) LTE, NR input format
                                                                 - LTE, eMTC
                                                                 0 : LTE f0
                                                                 1 : LTE f1
                                                                 2 : LTE f2
                                                                 3 : LTE f3
                                                                 4 : LTE f4
                                                                 - NR long
                                                                 0 : NR long f0
                                                                 1 : NR long f1
                                                                 2 : NR long f2
                                                                 3 : NR long f3
                                                                 - NR short
                                                                 0 : NR short A0
                                                                 1 : NR short A1
                                                                 2 : NR short A2
                                                                 3 : NR short A3
                                                                 4 : NR short B1
                                                                 5 : NR short B2
                                                                 6 : NR short B3
                                                                 7 : NR short B4
                                                                 8 : NR short C0
                                                                 9 : NR short C2 */
        uint64_t prach_type            : 2;  /**< [ 35: 34](R/W) PRACH type
                                                                 0 : LTE
                                                                 1 : eMTC
                                                                 2 : NR long
                                                                 3 : NR short */
        uint64_t num_of_ant            : 3;  /**< [ 38: 36](R/W) "This field  should be like bellows according to iteration of job
                                                                 At 1st job (eMTC start job) Set 2 (ant #0 ~ ant #7)]
                                                                 At 2nd job (eMTC correlation job) set 3 (ant #8 ~ ant #15)]
                                                                 At 3rd job (eMTC correlation job) Set 4 (ant #16 ~ ant #23)]
                                                                 At 4th job (eMTC peak detection job) Set 5 (ant #24 ~ ant #31)]
                                                                 0 : 2 antenna
                                                                 1 : 4 antenna
                                                                 2 : 8 antenna
                                                                 3 : 16 antenna
                                                                 4 : 24 antenna
                                                                 5 : 32 antenna" */
        uint64_t n_coh                 : 3;  /**< [ 41: 39](R/W) Number of  symbol for coherent combine. Default - 0
                                                                        0-1
                                                                        1-2
                                                                        2-3
                                                                        3-4
                                                                        4-6
                                                                        5-8
                                                                        6-12
                                                                        7-24 */
        uint64_t num_of_preamble       : 6;  /**< [ 47: 42](R/W) Number of preamble for detection. Default - 63
                                                                 0-1, 1-2, ... 63-64 */
        uint64_t in_sam_offset         : 1;  /**< [ 48: 48](R/W) Input sample offset (0 or 1) Default - 0 */
        uint64_t fft_1024              : 1;  /**< [ 49: 49](R/W) 1024 FFT selection for legacy F4 freq. multiplexing
                                                                 0 - 1024 FFT mode off, 1 - 1024 FFT mode on. Default - 0 */
        uint64_t freq_pos              : 1;  /**< [ 50: 50](R/W) 0~1, Frequency position for 1024 FFT. Default - 0 */
        uint64_t n_repetition          : 3;  /**< [ 53: 51](R/W) Number of repetition for eMTC in processing job. Default - 0
                                                                   0-1
                                                                   1-2
                                                                   2-4
                                                                   3-8
                                                                   4-16
                                                                   5-32
                                                                   6-64
                                                                   7-128 */
        uint64_t antenna_0_on          : 1;  /**< [ 54: 54](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_1_on          : 1;  /**< [ 55: 55](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_2_on          : 1;  /**< [ 56: 56](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_3_on          : 1;  /**< [ 57: 57](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_4_on          : 1;  /**< [ 58: 58](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_5_on          : 1;  /**< [ 59: 59](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_6_on          : 1;  /**< [ 60: 60](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t antenna_7_on          : 1;  /**< [ 61: 61](R/W) 0 - off, i - on. If this field is 0, antenna input value becomes zero */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_system_config_s cnf95xx; */
    struct cavm_prach_abx_system_config_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t antenna_7_on          : 1;  /**< [ 61: 61](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_6_on          : 1;  /**< [ 60: 60](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_5_on          : 1;  /**< [ 59: 59](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_4_on          : 1;  /**< [ 58: 58](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_3_on          : 1;  /**< [ 57: 57](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_2_on          : 1;  /**< [ 56: 56](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_1_on          : 1;  /**< [ 55: 55](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_0_on          : 1;  /**< [ 54: 54](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t n_repetition          : 3;  /**< [ 53: 51](R/W) Number of repetition for eMTC in processing job. Default is 0.
                                                                   0 = 1 repetition.
                                                                   1 = 2 repetitions.
                                                                   2 = 4 repetitions.
                                                                   3 = 8 repetitions.
                                                                   4 = 16 repetitions.
                                                                   5 = 32 repetitions.
                                                                   6 = 64 repetitions.
                                                                   7 = 128 repetitions. */
        uint64_t freq_pos              : 1;  /**< [ 50: 50](R/W) 0~1, Frequency position for 1024 FFT. Default is 0. */
        uint64_t fft_1024              : 1;  /**< [ 49: 49](R/W) 1024 FFT selection for legacy F4 frequency multiplexing.
                                                                 0 = 1024 FFT mode off.
                                                                 1 = 1024 FFT mode on.

                                                                 Default is 0. */
        uint64_t in_sam_offset         : 1;  /**< [ 48: 48](R/W) Input sample offset (0 or 1) Default is 0. */
        uint64_t num_of_preamble       : 6;  /**< [ 47: 42](R/W) Number of preamble for detection minus 1. Default is 63 (i.e., 64
                                                                 preambles). */
        uint64_t n_coh                 : 3;  /**< [ 41: 39](R/W) Number of symbols for coherent combine. Default is 0.
                                                                  0 = 1 symbol.
                                                                  1 = 2 symbols.
                                                                  2 = 3 symbols.
                                                                  3 = 4 symbols.
                                                                  4 = 6 symbols.
                                                                  5 = 8 symbols.
                                                                  6 = 12 symbols.
                                                                  7 = 24 symbols. */
        uint64_t num_of_ant            : 3;  /**< [ 38: 36](R/W) Number of antennas:
                                                                 0 = 2 antennas.
                                                                 1 = 4 antennas.
                                                                 2 = 8 antennas.
                                                                 3 = 16 antennas.
                                                                 4 = 24 antennas.
                                                                 5 = 32 antennas.

                                                                 Requirements:
                                                                 * 1st job (eMTC start job) set to 2 (antennas 0-7).
                                                                 * 2nd job (eMTC correlation job) set to 3 (antennas 8-15).
                                                                 * 3rd job (eMTC correlation job) Set to 4 (antennas 16-23).
                                                                 * 4th job (eMTC peak detection job) set to 5 (antennas 24-31). */
        uint64_t prach_type            : 2;  /**< [ 35: 34](R/W) PRACH type:
                                                                 0 = LTE.
                                                                 1 = eMTC.
                                                                 2 = NR long.
                                                                 3 = NR short. */
        uint64_t preamble_format       : 4;  /**< [ 33: 30](R/W) LTE, NR input format
                                                                 - LTE, eMTC
                                                                 0 : LTE f0
                                                                 1 : LTE f1
                                                                 2 : LTE f2
                                                                 3 : LTE f3
                                                                 4 : LTE f4
                                                                 - NR long
                                                                 0 : NR long f0
                                                                 1 : NR long f1
                                                                 2 : NR long f2
                                                                 3 : NR long f3
                                                                 - NR short
                                                                 0 : NR short A0
                                                                 1 : NR short A1
                                                                 2 : NR short A2
                                                                 3 : NR short A3
                                                                 4 : NR short B1
                                                                 5 : NR short B2
                                                                 6 : NR short B3
                                                                 7 : NR short B4
                                                                 8 : NR short C0
                                                                 9 : NR short C2 */
        uint64_t reserved_28_29        : 2;
        uint64_t tagc_psym             : 2;  /**< [ 27: 26](R/W) Preamble symbol position for TAGC power calculation, 0~2. Default: 0 */
        uint64_t db_conv_mode          : 1;  /**< [ 25: 25](R/W) 0: 0.1dB resolution (default)
                                                                 1: 0.01 dB resolution */
        uint64_t reserved_23_24        : 2;
        uint64_t mrc_mode              : 1;  /**< [ 22: 22](R/W) 0 - EGC mode (defult), 1 - MRC mode */
        uint64_t high_speed_set        : 2;  /**< [ 21: 20](R/W) 0 - normal mode (unrestricted set)
                                                                 1 - high speed mode (restricted set type A)
                                                                 2 - very high speed mode (restricted set type B)
                                                                 Default - 0. 1 or 2 - when CE_OCC_MODE is 0 */
        uint64_t n_zone                : 6;  /**< [ 19: 14](R/W) Number of zero correlation zone per 1 root seq.
                                                                 Floor(839/Ncs) or Floor(139/ncs)
                                                                 This field is Valid if NCS_INPUT_MODE = 1
                                                                 0:1, 1:2 ... 63:64 */
        uint64_t ncs_input_mode        : 1;  /**< [ 13: 13](R/W) 0 - configuration value input (NCS_CONFIGURATION). Default - 0
                                                                 1 - Ncs value direct input (NCS_VALUE_DIRECT) */
        uint64_t ncs_value_direct      : 9;  /**< [ 12:  4](R/W) Ncs value. For preparation of spec. change
                                                                 This field is Valid if NCS_INPUT_MODE = 1 */
        uint64_t ncs_configuration     : 4;  /**< [  3:  0](R/W) Zero correlation zone config. value (0~15)
                                                                 Necessary number of root sequences is decided by this filed
                                                                 (cf. Table 5.7.2-2, 3 (36.211 spec.)) */
#else /* Word 0 - Little Endian */
        uint64_t ncs_configuration     : 4;  /**< [  3:  0](R/W) Zero correlation zone config. value (0~15)
                                                                 Necessary number of root sequences is decided by this filed
                                                                 (cf. Table 5.7.2-2, 3 (36.211 spec.)) */
        uint64_t ncs_value_direct      : 9;  /**< [ 12:  4](R/W) Ncs value. For preparation of spec. change
                                                                 This field is Valid if NCS_INPUT_MODE = 1 */
        uint64_t ncs_input_mode        : 1;  /**< [ 13: 13](R/W) 0 - configuration value input (NCS_CONFIGURATION). Default - 0
                                                                 1 - Ncs value direct input (NCS_VALUE_DIRECT) */
        uint64_t n_zone                : 6;  /**< [ 19: 14](R/W) Number of zero correlation zone per 1 root seq.
                                                                 Floor(839/Ncs) or Floor(139/ncs)
                                                                 This field is Valid if NCS_INPUT_MODE = 1
                                                                 0:1, 1:2 ... 63:64 */
        uint64_t high_speed_set        : 2;  /**< [ 21: 20](R/W) 0 - normal mode (unrestricted set)
                                                                 1 - high speed mode (restricted set type A)
                                                                 2 - very high speed mode (restricted set type B)
                                                                 Default - 0. 1 or 2 - when CE_OCC_MODE is 0 */
        uint64_t mrc_mode              : 1;  /**< [ 22: 22](R/W) 0 - EGC mode (defult), 1 - MRC mode */
        uint64_t reserved_23_24        : 2;
        uint64_t db_conv_mode          : 1;  /**< [ 25: 25](R/W) 0: 0.1dB resolution (default)
                                                                 1: 0.01 dB resolution */
        uint64_t tagc_psym             : 2;  /**< [ 27: 26](R/W) Preamble symbol position for TAGC power calculation, 0~2. Default: 0 */
        uint64_t reserved_28_29        : 2;
        uint64_t preamble_format       : 4;  /**< [ 33: 30](R/W) LTE, NR input format
                                                                 - LTE, eMTC
                                                                 0 : LTE f0
                                                                 1 : LTE f1
                                                                 2 : LTE f2
                                                                 3 : LTE f3
                                                                 4 : LTE f4
                                                                 - NR long
                                                                 0 : NR long f0
                                                                 1 : NR long f1
                                                                 2 : NR long f2
                                                                 3 : NR long f3
                                                                 - NR short
                                                                 0 : NR short A0
                                                                 1 : NR short A1
                                                                 2 : NR short A2
                                                                 3 : NR short A3
                                                                 4 : NR short B1
                                                                 5 : NR short B2
                                                                 6 : NR short B3
                                                                 7 : NR short B4
                                                                 8 : NR short C0
                                                                 9 : NR short C2 */
        uint64_t prach_type            : 2;  /**< [ 35: 34](R/W) PRACH type:
                                                                 0 = LTE.
                                                                 1 = eMTC.
                                                                 2 = NR long.
                                                                 3 = NR short. */
        uint64_t num_of_ant            : 3;  /**< [ 38: 36](R/W) Number of antennas:
                                                                 0 = 2 antennas.
                                                                 1 = 4 antennas.
                                                                 2 = 8 antennas.
                                                                 3 = 16 antennas.
                                                                 4 = 24 antennas.
                                                                 5 = 32 antennas.

                                                                 Requirements:
                                                                 * 1st job (eMTC start job) set to 2 (antennas 0-7).
                                                                 * 2nd job (eMTC correlation job) set to 3 (antennas 8-15).
                                                                 * 3rd job (eMTC correlation job) Set to 4 (antennas 16-23).
                                                                 * 4th job (eMTC peak detection job) set to 5 (antennas 24-31). */
        uint64_t n_coh                 : 3;  /**< [ 41: 39](R/W) Number of symbols for coherent combine. Default is 0.
                                                                  0 = 1 symbol.
                                                                  1 = 2 symbols.
                                                                  2 = 3 symbols.
                                                                  3 = 4 symbols.
                                                                  4 = 6 symbols.
                                                                  5 = 8 symbols.
                                                                  6 = 12 symbols.
                                                                  7 = 24 symbols. */
        uint64_t num_of_preamble       : 6;  /**< [ 47: 42](R/W) Number of preamble for detection minus 1. Default is 63 (i.e., 64
                                                                 preambles). */
        uint64_t in_sam_offset         : 1;  /**< [ 48: 48](R/W) Input sample offset (0 or 1) Default is 0. */
        uint64_t fft_1024              : 1;  /**< [ 49: 49](R/W) 1024 FFT selection for legacy F4 frequency multiplexing.
                                                                 0 = 1024 FFT mode off.
                                                                 1 = 1024 FFT mode on.

                                                                 Default is 0. */
        uint64_t freq_pos              : 1;  /**< [ 50: 50](R/W) 0~1, Frequency position for 1024 FFT. Default is 0. */
        uint64_t n_repetition          : 3;  /**< [ 53: 51](R/W) Number of repetition for eMTC in processing job. Default is 0.
                                                                   0 = 1 repetition.
                                                                   1 = 2 repetitions.
                                                                   2 = 4 repetitions.
                                                                   3 = 8 repetitions.
                                                                   4 = 16 repetitions.
                                                                   5 = 32 repetitions.
                                                                   6 = 64 repetitions.
                                                                   7 = 128 repetitions. */
        uint64_t antenna_0_on          : 1;  /**< [ 54: 54](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_1_on          : 1;  /**< [ 55: 55](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_2_on          : 1;  /**< [ 56: 56](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_3_on          : 1;  /**< [ 57: 57](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_4_on          : 1;  /**< [ 58: 58](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_5_on          : 1;  /**< [ 59: 59](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_6_on          : 1;  /**< [ 60: 60](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t antenna_7_on          : 1;  /**< [ 61: 61](R/W) 0 - off, 1 - on. If this field is 0, antenna input value becomes zero. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_prach_abx_system_config cavm_prach_abx_system_config_t;

static inline uint64_t CAVM_PRACH_ABX_SYSTEM_CONFIG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_SYSTEM_CONFIG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002008ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_SYSTEM_CONFIG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_SYSTEM_CONFIG(a) cavm_prach_abx_system_config_t
#define bustype_CAVM_PRACH_ABX_SYSTEM_CONFIG(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_SYSTEM_CONFIG(a) "PRACH_ABX_SYSTEM_CONFIG"
#define busnum_CAVM_PRACH_ABX_SYSTEM_CONFIG(a) (a)
#define arguments_CAVM_PRACH_ABX_SYSTEM_CONFIG(a) (a),-1,-1,-1

/**
 * Register (RSL) prach_ab#_threshold_cp
 *
 * INTERNAL: Threshold Value Configuration Register
 *
 * Threshold value
 */
union cavm_prach_abx_threshold_cp
{
    uint64_t u;
    struct cavm_prach_abx_threshold_cp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t res_sthr_const        : 16; /**< [ 31: 16](R/W) Second threshold of restricted combiner
                                                                 Value for Restricted mode combiner. Default: 65535 */
        uint64_t sthreshold_const      : 16; /**< [ 15:  0](R/W) Second threshold of profiler (multipath combiner)
                                                                 Value for calculation second threshold in Sec. max energy combiner. Default - 65535 */
#else /* Word 0 - Little Endian */
        uint64_t sthreshold_const      : 16; /**< [ 15:  0](R/W) Second threshold of profiler (multipath combiner)
                                                                 Value for calculation second threshold in Sec. max energy combiner. Default - 65535 */
        uint64_t res_sthr_const        : 16; /**< [ 31: 16](R/W) Second threshold of restricted combiner
                                                                 Value for Restricted mode combiner. Default: 65535 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_prach_abx_threshold_cp_s cn; */
};
typedef union cavm_prach_abx_threshold_cp cavm_prach_abx_threshold_cp_t;

static inline uint64_t CAVM_PRACH_ABX_THRESHOLD_CP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PRACH_ABX_THRESHOLD_CP(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043002010ll + 0x8000ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043002010ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("PRACH_ABX_THRESHOLD_CP", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_PRACH_ABX_THRESHOLD_CP(a) cavm_prach_abx_threshold_cp_t
#define bustype_CAVM_PRACH_ABX_THRESHOLD_CP(a) CSR_TYPE_RSL
#define basename_CAVM_PRACH_ABX_THRESHOLD_CP(a) "PRACH_ABX_THRESHOLD_CP"
#define busnum_CAVM_PRACH_ABX_THRESHOLD_CP(a) (a)
#define arguments_CAVM_PRACH_ABX_THRESHOLD_CP(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_PRACH_H__ */
