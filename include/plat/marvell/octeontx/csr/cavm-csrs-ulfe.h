#ifndef __CAVM_CSRS_ULFE_H__
#define __CAVM_CSRS_ULFE_H__
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
 * OcteonTX ULFE.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure ulfe_normal_job_s
 *
 * ULFE Normal Job Structure
 * This structure specifies the format of the job configuration for ULFE normal jobs.
 */
union cavm_ulfe_normal_job_s
{
    uint64_t u[29];
    struct cavm_ulfe_normal_job_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_type           : 1;  /**< [ 63: 63] Job configuration type. Must be 0x1 for normal symbol jobs. */
        uint64_t ant_idx               : 6;  /**< [ 62: 57] Antenna index. Valid range is [0,47]. */
        uint64_t trch_fe_enable        : 1;  /**< [ 56: 56] Traffic channel frontend processing control:
                                                                 0x0 = Disable traffic channel processing.
                                                                 0x1 = Enable traffic channel processing. */
        uint64_t fft_size_idx          : 2;  /**< [ 55: 54] FFT size index.
                                                                 0x0 = 512 point FFT.
                                                                 0x1 = 1024 point FFT.
                                                                 0x2 = 2048 point FFT.
                                                                 0x3 = 4096 point FFT. */
        uint64_t scs                   : 3;  /**< [ 53: 51] Subcarrier spacing:
                                                                 0x0 = 15 kHz.
                                                                 0x1 = 30 kHz.
                                                                 0x2 = 60 kHz.
                                                                 0x3 = 120 kHz.
                                                                 0x4 = 240 kHz.
                                                                 0x5-0x7 = Reserved. */
        uint64_t cp_size               : 9;  /**< [ 50: 42] Cyclic prefix size. The cyclic prefix is 4 x [CP_SIZE] samples. Valid
                                                                 range of [CP_SIZE] is [0,256]. */
        uint64_t num_rb                : 9;  /**< [ 41: 33] Number of RBs. Valid range is [6,275]. */
        uint64_t dcrm_enable           : 1;  /**< [ 32: 32] Enable DC removal:
                                                                 0x0 = Disable (bypass) DC removal filter.
                                                                 0x1 = Enable DC removal filter. */
        uint64_t dcrm_mode             : 1;  /**< [ 31: 31] DC removal mode:
                                                                 0x0 = Filter mode.
                                                                 0x1 = Block average mode. */
        uint64_t dcrm_coef             : 4;  /**< [ 30: 27] DC removal filter coefficient. See [DCRM_COEF_EXP]. */
        uint64_t dcrm_coef_exp         : 5;  /**< [ 26: 22] DC removal filter coefficient exponent. The DC removal filter coefficient is
                                                                 [DCRM_COEF] x 2^(-[DCRM_COEF_EXP]). Valid range is [4,20]. */
        uint64_t dcrm_block_size       : 2;  /**< [ 21: 20] Block size in DC removal mode.
                                                                 0x0 = 30720.
                                                                 0x1 = 30720 x 2.
                                                                 0x2 = 30720 x 4.
                                                                 0x3 = 30720 x 8. */
        uint64_t freq_shift_enable     : 1;  /**< [ 19: 19] Enables frequency shift when set. */
        uint64_t trch_hf_downshift     : 1;  /**< [ 18: 18] Half-tone down shift for traffic channels.
                                                                 0x0 = Disable half tone down shift.
                                                                 0x1 = Enable half tone down shift. */
        uint64_t freq_shift            : 18; /**< [ 17:  0] Frequency shift, in units of 100 Hz. This is a two's-complement signed value,
                                                                 with a valid range of [-131072,131071]. */
#else /* Word 0 - Little Endian */
        uint64_t freq_shift            : 18; /**< [ 17:  0] Frequency shift, in units of 100 Hz. This is a two's-complement signed value,
                                                                 with a valid range of [-131072,131071]. */
        uint64_t trch_hf_downshift     : 1;  /**< [ 18: 18] Half-tone down shift for traffic channels.
                                                                 0x0 = Disable half tone down shift.
                                                                 0x1 = Enable half tone down shift. */
        uint64_t freq_shift_enable     : 1;  /**< [ 19: 19] Enables frequency shift when set. */
        uint64_t dcrm_block_size       : 2;  /**< [ 21: 20] Block size in DC removal mode.
                                                                 0x0 = 30720.
                                                                 0x1 = 30720 x 2.
                                                                 0x2 = 30720 x 4.
                                                                 0x3 = 30720 x 8. */
        uint64_t dcrm_coef_exp         : 5;  /**< [ 26: 22] DC removal filter coefficient exponent. The DC removal filter coefficient is
                                                                 [DCRM_COEF] x 2^(-[DCRM_COEF_EXP]). Valid range is [4,20]. */
        uint64_t dcrm_coef             : 4;  /**< [ 30: 27] DC removal filter coefficient. See [DCRM_COEF_EXP]. */
        uint64_t dcrm_mode             : 1;  /**< [ 31: 31] DC removal mode:
                                                                 0x0 = Filter mode.
                                                                 0x1 = Block average mode. */
        uint64_t dcrm_enable           : 1;  /**< [ 32: 32] Enable DC removal:
                                                                 0x0 = Disable (bypass) DC removal filter.
                                                                 0x1 = Enable DC removal filter. */
        uint64_t num_rb                : 9;  /**< [ 41: 33] Number of RBs. Valid range is [6,275]. */
        uint64_t cp_size               : 9;  /**< [ 50: 42] Cyclic prefix size. The cyclic prefix is 4 x [CP_SIZE] samples. Valid
                                                                 range of [CP_SIZE] is [0,256]. */
        uint64_t scs                   : 3;  /**< [ 53: 51] Subcarrier spacing:
                                                                 0x0 = 15 kHz.
                                                                 0x1 = 30 kHz.
                                                                 0x2 = 60 kHz.
                                                                 0x3 = 120 kHz.
                                                                 0x4 = 240 kHz.
                                                                 0x5-0x7 = Reserved. */
        uint64_t fft_size_idx          : 2;  /**< [ 55: 54] FFT size index.
                                                                 0x0 = 512 point FFT.
                                                                 0x1 = 1024 point FFT.
                                                                 0x2 = 2048 point FFT.
                                                                 0x3 = 4096 point FFT. */
        uint64_t trch_fe_enable        : 1;  /**< [ 56: 56] Traffic channel frontend processing control:
                                                                 0x0 = Disable traffic channel processing.
                                                                 0x1 = Enable traffic channel processing. */
        uint64_t ant_idx               : 6;  /**< [ 62: 57] Antenna index. Valid range is [0,47]. */
        uint64_t config_type           : 1;  /**< [ 63: 63] Job configuration type. Must be 0x1 for normal symbol jobs. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t cprm_mode             : 1;  /**< [127:127] CP removal mode.
                                                                 0x0 = N_FFT samples.
                                                                 0x1 = [CPRM_OFFSET1] samples and then zeros.

                                                                 Note that CP removal block is bypassed during the second pass. */
        uint64_t user_def_phase        : 12; /**< [126:115] User defined phase rotation. Rotated phase is \pi x [USER_DEF_PHASE]/2048. Two's
                                                                 complement value in the range [-2048,2047]. */
        uint64_t iss_enable            : 1;  /**< [114:114] Input signal scaler control.
                                                                 0x0 = Disable (bypass) ISS.
                                                                 0x1 = Enable ISS. */
        uint64_t iss_mode              : 2;  /**< [113:112] Input signal scaler mode:
                                                                 0x0 = Gain hold.
                                                                 0x1 = Gain update.
                                                                 0x2 = Fixed gain.
                                                                 0x3 = Reserved. */
        uint64_t iss_target_level      : 6;  /**< [111:106] Input signal scaler target level. Target level for [ISS_MODE] = 0x1. Fixed gain
                                                                 for [ISS_MODE] = 0x2. */
        uint64_t iss_gain_limit        : 6;  /**< [105:100] Input signal scaler gain limit. ISS gain is limited to this value only when
                                                                 [ISS_MODE] = 0x1. Valid range is [-32,31]. */
        uint64_t cprm_offset0          : 11; /**< [ 99: 89] CP removal offset for first process. Valid range is [0,1024]. */
        uint64_t cprm_offset1          : 11; /**< [ 88: 78] CP removal offset for second process. Valid range is [0,1024]. */
        uint64_t fft_enable            : 1;  /**< [ 77: 77] Enable FFT. */
        uint64_t dcrm_reset            : 1;  /**< [ 76: 76] DC removal reset control.
                                                                 0x0 = Do nothing.
                                                                 0x1 = Reset the DC removal state variables (i.e., sample count, block
                                                                 sum, and DC estimate). */
        uint64_t reserved_64_75        : 12;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64_75        : 12;
        uint64_t dcrm_reset            : 1;  /**< [ 76: 76] DC removal reset control.
                                                                 0x0 = Do nothing.
                                                                 0x1 = Reset the DC removal state variables (i.e., sample count, block
                                                                 sum, and DC estimate). */
        uint64_t fft_enable            : 1;  /**< [ 77: 77] Enable FFT. */
        uint64_t cprm_offset1          : 11; /**< [ 88: 78] CP removal offset for second process. Valid range is [0,1024]. */
        uint64_t cprm_offset0          : 11; /**< [ 99: 89] CP removal offset for first process. Valid range is [0,1024]. */
        uint64_t iss_gain_limit        : 6;  /**< [105:100] Input signal scaler gain limit. ISS gain is limited to this value only when
                                                                 [ISS_MODE] = 0x1. Valid range is [-32,31]. */
        uint64_t iss_target_level      : 6;  /**< [111:106] Input signal scaler target level. Target level for [ISS_MODE] = 0x1. Fixed gain
                                                                 for [ISS_MODE] = 0x2. */
        uint64_t iss_mode              : 2;  /**< [113:112] Input signal scaler mode:
                                                                 0x0 = Gain hold.
                                                                 0x1 = Gain update.
                                                                 0x2 = Fixed gain.
                                                                 0x3 = Reserved. */
        uint64_t iss_enable            : 1;  /**< [114:114] Input signal scaler control.
                                                                 0x0 = Disable (bypass) ISS.
                                                                 0x1 = Enable ISS. */
        uint64_t user_def_phase        : 12; /**< [126:115] User defined phase rotation. Rotated phase is \pi x [USER_DEF_PHASE]/2048. Two's
                                                                 complement value in the range [-2048,2047]. */
        uint64_t cprm_mode             : 1;  /**< [127:127] CP removal mode.
                                                                 0x0 = N_FFT samples.
                                                                 0x1 = [CPRM_OFFSET1] samples and then zeros.

                                                                 Note that CP removal block is bypassed during the second pass. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t cyclic_time_shift_enable : 1;/**< [191:191] Enable cyclic time shift for both passes. */
        uint64_t cyclic_time_shift0    : 13; /**< [190:178] Cyclic time shift for the first pass. Two's complement value in the range [-4096,4095]. */
        uint64_t cyclic_time_shift1    : 13; /**< [177:165] Cyclic time shift for the second pass. Two's complement value in the range [-4096,4095]. */
        uint64_t k0                    : 2;  /**< [164:163] Subcarrier offset (i.e., parameter k0):
                                                                 0x0 = -6.
                                                                 0x1 = 0.
                                                                 0x2 = 6.
                                                                 0x3 = Reserved. */
        uint64_t signal_level_normalize : 1; /**< [162:162] Enable signal level normalization. */
        uint64_t calibration_enable    : 1;  /**< [161:161] Enable antenna calibration. */
        uint64_t second_pass_out       : 1;  /**< [160:160] Second pass output control.
                                                                 0x0 = Do not send the second pass output.
                                                                 0x1 = Send the second pass output. */
        uint64_t measurement_reset     : 3;  /**< [159:157] Reset meausrement values. Each bit, when set, resets the
                                                                 accumulated of values for a given measurement:
                                                                 * bit\<0\> = TD-RSSI.
                                                                 * bit\<1\> = FD-RSSI.
                                                                 * bit\<2\> = FD-XCORR. */
        uint64_t measurement_trigger   : 3;  /**< [156:154] Trigger meausrement accumulation. Each bit, when set, triggers the
                                                                 accumulation of a measured value for the current symbol:
                                                                 * bit\<0\> = TD-RSSI.
                                                                 * bit\<1\> = FD-RSSI.
                                                                 * bit\<2\> = FD-XCORR.

                                                                 Accumulated values can be reported via DMA by setting
                                                                 [MEASUREMENT_REPORT] for this job or on a subsequent symbol job. */
        uint64_t measurement_report    : 3;  /**< [153:151] Enable meausrement report outputs. Each bit, when set, enables the
                                                                 DMA output of a given measurement report:
                                                                 * bit\<0\> = TD-RSSI report.
                                                                 * bit\<1\> = FD-RSSI report.
                                                                 * bit\<2\> = FD-XCORR report. */
        uint64_t rach_config_update    : 1;  /**< [150:150] RACH configuration update:
                                                                 0x0 = No update.
                                                                 0x1 = Update RACH FE configuration according to job config. */
        uint64_t bwp_map_update        : 1;  /**< [149:149] BWP map update control:
                                                                 0x0 = No update.
                                                                 0x1 = Update BWP map according to job config. */
        uint64_t reserved_128_148      : 21;
#else /* Word 2 - Little Endian */
        uint64_t reserved_128_148      : 21;
        uint64_t bwp_map_update        : 1;  /**< [149:149] BWP map update control:
                                                                 0x0 = No update.
                                                                 0x1 = Update BWP map according to job config. */
        uint64_t rach_config_update    : 1;  /**< [150:150] RACH configuration update:
                                                                 0x0 = No update.
                                                                 0x1 = Update RACH FE configuration according to job config. */
        uint64_t measurement_report    : 3;  /**< [153:151] Enable meausrement report outputs. Each bit, when set, enables the
                                                                 DMA output of a given measurement report:
                                                                 * bit\<0\> = TD-RSSI report.
                                                                 * bit\<1\> = FD-RSSI report.
                                                                 * bit\<2\> = FD-XCORR report. */
        uint64_t measurement_trigger   : 3;  /**< [156:154] Trigger meausrement accumulation. Each bit, when set, triggers the
                                                                 accumulation of a measured value for the current symbol:
                                                                 * bit\<0\> = TD-RSSI.
                                                                 * bit\<1\> = FD-RSSI.
                                                                 * bit\<2\> = FD-XCORR.

                                                                 Accumulated values can be reported via DMA by setting
                                                                 [MEASUREMENT_REPORT] for this job or on a subsequent symbol job. */
        uint64_t measurement_reset     : 3;  /**< [159:157] Reset meausrement values. Each bit, when set, resets the
                                                                 accumulated of values for a given measurement:
                                                                 * bit\<0\> = TD-RSSI.
                                                                 * bit\<1\> = FD-RSSI.
                                                                 * bit\<2\> = FD-XCORR. */
        uint64_t second_pass_out       : 1;  /**< [160:160] Second pass output control.
                                                                 0x0 = Do not send the second pass output.
                                                                 0x1 = Send the second pass output. */
        uint64_t calibration_enable    : 1;  /**< [161:161] Enable antenna calibration. */
        uint64_t signal_level_normalize : 1; /**< [162:162] Enable signal level normalization. */
        uint64_t k0                    : 2;  /**< [164:163] Subcarrier offset (i.e., parameter k0):
                                                                 0x0 = -6.
                                                                 0x1 = 0.
                                                                 0x2 = 6.
                                                                 0x3 = Reserved. */
        uint64_t cyclic_time_shift1    : 13; /**< [177:165] Cyclic time shift for the second pass. Two's complement value in the range [-4096,4095]. */
        uint64_t cyclic_time_shift0    : 13; /**< [190:178] Cyclic time shift for the first pass. Two's complement value in the range [-4096,4095]. */
        uint64_t cyclic_time_shift_enable : 1;/**< [191:191] Enable cyclic time shift for both passes. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t bwp_weight1           : 32; /**< [255:224] Complex weight for BWP 1 with the following bit map, [imag real(LSB)]. */
        uint64_t bwp_weight2           : 32; /**< [223:192] Complex weight for BWP 2 with the following bit map, [imag real(LSB)]. */
#else /* Word 3 - Little Endian */
        uint64_t bwp_weight2           : 32; /**< [223:192] Complex weight for BWP 2 with the following bit map, [imag real(LSB)]. */
        uint64_t bwp_weight1           : 32; /**< [255:224] Complex weight for BWP 1 with the following bit map, [imag real(LSB)]. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t bwp_weight3           : 32; /**< [319:288] Complex weight for BWP 3 with the following bit map, [imag real(LSB)]. */
        uint64_t bwp_weight4           : 32; /**< [287:256] Complex weight for BWP 4 with the following bit map, [imag real(LSB)]. */
#else /* Word 4 - Little Endian */
        uint64_t bwp_weight4           : 32; /**< [287:256] Complex weight for BWP 4 with the following bit map, [imag real(LSB)]. */
        uint64_t bwp_weight3           : 32; /**< [319:288] Complex weight for BWP 3 with the following bit map, [imag real(LSB)]. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t bwp_weight5           : 32; /**< [383:352] Complex weight for BWP 5 with the following bit map, [imag real(LSB)]. */
        uint64_t bwp_weight_exp        : 4;  /**< [351:348] Block exponent for BWP weights. Valid range is [0,15]. */
        uint64_t td_rssi_db_adj        : 12; /**< [347:336] TD-RSSI dB adjustment value. The adjustment value added to dB value converted
                                                                 from the TD-RSSI measurement. Valid range is [-2048,2047] which is equivalent to
                                                                 [-204.8, 204.7] dB in dB unit. */
        uint64_t reserved_320_335      : 16;
#else /* Word 5 - Little Endian */
        uint64_t reserved_320_335      : 16;
        uint64_t td_rssi_db_adj        : 12; /**< [347:336] TD-RSSI dB adjustment value. The adjustment value added to dB value converted
                                                                 from the TD-RSSI measurement. Valid range is [-2048,2047] which is equivalent to
                                                                 [-204.8, 204.7] dB in dB unit. */
        uint64_t bwp_weight_exp        : 4;  /**< [351:348] Block exponent for BWP weights. Valid range is [0,15]. */
        uint64_t bwp_weight5           : 32; /**< [383:352] Complex weight for BWP 5 with the following bit map, [imag real(LSB)]. */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t rach_fe_enable0       : 1;  /**< [447:447] Enable RACH front-end 0. */
        uint64_t rach_freq_shift0      : 15; /**< [446:432] Frequency shift in RACH FE0. The frequency shift will be
                                                                 (-[RACH_FREQ_SHIFT0]*7.5) kHz regardless of SCS.
                                                                 Note that the frequency of the input signal is shifted in the negative direction. */
        uint64_t oversample_ratio0     : 2;  /**< [431:430] Oversampling ratio for RACH FE0:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling.
                                                                 0x3 = Reserved. */
        uint64_t decim_ratio0          : 6;  /**< [429:424] CIC decimation ratio for RACH FE0:
                                                                 0x0, 0x1 =  Bypass.
                                                                 0x2-0x30 =  [DECIM_RATIO0]-1 input samples of every [DECIM_RATIO0] samples. */
        uint64_t output_level_atten0   : 5;  /**< [423:419] Output level attenuation for RACH FE0. Valid range is [0,26] which is equivalent
                                                                 to [0,-156] dB attenuation with 6 dB step. */
        uint64_t state_reset0          : 1;  /**< [418:418] RACH FE0 sample rate converter/TD-RSSI reset.
                                                                 0x0 = Hold.
                                                                 0x1 = Reset (set to 0). */
        uint64_t rach_wr_offset0       : 2;  /**< [417:416] Write offset for RACH FE0. */
        uint64_t rach_fe_enable1       : 1;  /**< [415:415] Enable RACH front-end 1. */
        uint64_t rach_freq_shift1      : 15; /**< [414:400] Frequency shift in RACH FE1. See [RACH_FREQ_SHIFT0]. */
        uint64_t oversample_ratio1     : 2;  /**< [399:398] Oversampling ratio for RACH FE1:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling.
                                                                 0x3 = Reserved. */
        uint64_t decim_ratio1          : 6;  /**< [397:392] CIC decimation ratio for RACH FE1:

                                                                 _ 0x0, 0x1 = Bypass.

                                                                 _ 0x2-0x30 = Decimate [DECIM_RATIO1]-1 input samples of every [DECIM_RATIO1] samples. */
        uint64_t output_level_atten1   : 5;  /**< [391:387] Output level attenuation for RACH FE1. See [OUTPUT_LEVEL_ATTEN0]. */
        uint64_t state_reset1          : 1;  /**< [386:386] RACH FE1 sample rate converter/TD-RSSI reset.
                                                                 0x0 =  Hold.
                                                                 0x1 =  Reset (set to 0). */
        uint64_t rach_wr_offset1       : 2;  /**< [385:384] Write offset for RACH FE 1. */
#else /* Word 6 - Little Endian */
        uint64_t rach_wr_offset1       : 2;  /**< [385:384] Write offset for RACH FE 1. */
        uint64_t state_reset1          : 1;  /**< [386:386] RACH FE1 sample rate converter/TD-RSSI reset.
                                                                 0x0 =  Hold.
                                                                 0x1 =  Reset (set to 0). */
        uint64_t output_level_atten1   : 5;  /**< [391:387] Output level attenuation for RACH FE1. See [OUTPUT_LEVEL_ATTEN0]. */
        uint64_t decim_ratio1          : 6;  /**< [397:392] CIC decimation ratio for RACH FE1:

                                                                 _ 0x0, 0x1 = Bypass.

                                                                 _ 0x2-0x30 = Decimate [DECIM_RATIO1]-1 input samples of every [DECIM_RATIO1] samples. */
        uint64_t oversample_ratio1     : 2;  /**< [399:398] Oversampling ratio for RACH FE1:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling.
                                                                 0x3 = Reserved. */
        uint64_t rach_freq_shift1      : 15; /**< [414:400] Frequency shift in RACH FE1. See [RACH_FREQ_SHIFT0]. */
        uint64_t rach_fe_enable1       : 1;  /**< [415:415] Enable RACH front-end 1. */
        uint64_t rach_wr_offset0       : 2;  /**< [417:416] Write offset for RACH FE0. */
        uint64_t state_reset0          : 1;  /**< [418:418] RACH FE0 sample rate converter/TD-RSSI reset.
                                                                 0x0 = Hold.
                                                                 0x1 = Reset (set to 0). */
        uint64_t output_level_atten0   : 5;  /**< [423:419] Output level attenuation for RACH FE0. Valid range is [0,26] which is equivalent
                                                                 to [0,-156] dB attenuation with 6 dB step. */
        uint64_t decim_ratio0          : 6;  /**< [429:424] CIC decimation ratio for RACH FE0:
                                                                 0x0, 0x1 =  Bypass.
                                                                 0x2-0x30 =  [DECIM_RATIO0]-1 input samples of every [DECIM_RATIO0] samples. */
        uint64_t oversample_ratio0     : 2;  /**< [431:430] Oversampling ratio for RACH FE0:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling.
                                                                 0x3 = Reserved. */
        uint64_t rach_freq_shift0      : 15; /**< [446:432] Frequency shift in RACH FE0. The frequency shift will be
                                                                 (-[RACH_FREQ_SHIFT0]*7.5) kHz regardless of SCS.
                                                                 Note that the frequency of the input signal is shifted in the negative direction. */
        uint64_t rach_fe_enable0       : 1;  /**< [447:447] Enable RACH front-end 0. */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t rach_fe_enable2       : 1;  /**< [511:511] Enable RACH front-end 2. */
        uint64_t rach_freq_shift2      : 15; /**< [510:496] Frequency shift in RACH FE2. See [RACH_FREQ_SHIFT0]. */
        uint64_t oversample_ratio2     : 2;  /**< [495:494] Oversampling ratio for RACH FE2:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling.
                                                                 0x3 = Reserved. */
        uint64_t decim_ratio2          : 6;  /**< [493:488] CIC decimation ratio for RACH FE2:
                                                                 0x0, 0x1 =  Bypass.
                                                                 0x2-0x30 =  Decimate [DECIM_RATIO2]-1 input samples of every [DECIM_RATIO2] samples. */
        uint64_t output_level_atten2   : 5;  /**< [487:483] Output level attenuation for RACH FE2. See [OUTPUT_LEVEL_ATTEN0]. */
        uint64_t state_reset2          : 1;  /**< [482:482] RACH FE2 sample rate converter/TD-RSSI reset.
                                                                 0x0 = Hold.
                                                                 0x1 = Reset (set to 0). */
        uint64_t rach_wr_offset2       : 2;  /**< [481:480] Write offset for RACH FE2. */
        uint64_t rach_fe_enable3       : 1;  /**< [479:479] Enable RACH front-end 3. */
        uint64_t rach_freq_shift3      : 15; /**< [478:464] Frequency shift in RACH FE3. See [RACH_FREQ_SHIFT0]. */
        uint64_t oversample_ratio3     : 2;  /**< [463:462] Oversampling ratio for RACH FE3:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling.
                                                                 0x3 = Reserved. */
        uint64_t decim_ratio3          : 6;  /**< [461:456] CIC decimation ratio for RACH FE3:
                                                                 0x0, 0x1 = Bypass.
                                                                 0x2-0x30 = Decimate [DECIM_RATIO3]-1 input samples of every [DECIM_RATIO3] samples. */
        uint64_t output_level_atten3   : 5;  /**< [455:451] Output level attenuation for RACH FE3. See [OUTPUT_LEVEL_ATTEN0]. */
        uint64_t state_reset3          : 1;  /**< [450:450] RACH FE3 sample rate converter/TD-RSSI reset.
                                                                 0x0 =  Hold.
                                                                 0x1 =  Reset (set to 0). */
        uint64_t rach_wr_offset3       : 2;  /**< [449:448] Write offset for RACH FE 3. */
#else /* Word 7 - Little Endian */
        uint64_t rach_wr_offset3       : 2;  /**< [449:448] Write offset for RACH FE 3. */
        uint64_t state_reset3          : 1;  /**< [450:450] RACH FE3 sample rate converter/TD-RSSI reset.
                                                                 0x0 =  Hold.
                                                                 0x1 =  Reset (set to 0). */
        uint64_t output_level_atten3   : 5;  /**< [455:451] Output level attenuation for RACH FE3. See [OUTPUT_LEVEL_ATTEN0]. */
        uint64_t decim_ratio3          : 6;  /**< [461:456] CIC decimation ratio for RACH FE3:
                                                                 0x0, 0x1 = Bypass.
                                                                 0x2-0x30 = Decimate [DECIM_RATIO3]-1 input samples of every [DECIM_RATIO3] samples. */
        uint64_t oversample_ratio3     : 2;  /**< [463:462] Oversampling ratio for RACH FE3:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling.
                                                                 0x3 = Reserved. */
        uint64_t rach_freq_shift3      : 15; /**< [478:464] Frequency shift in RACH FE3. See [RACH_FREQ_SHIFT0]. */
        uint64_t rach_fe_enable3       : 1;  /**< [479:479] Enable RACH front-end 3. */
        uint64_t rach_wr_offset2       : 2;  /**< [481:480] Write offset for RACH FE2. */
        uint64_t state_reset2          : 1;  /**< [482:482] RACH FE2 sample rate converter/TD-RSSI reset.
                                                                 0x0 = Hold.
                                                                 0x1 = Reset (set to 0). */
        uint64_t output_level_atten2   : 5;  /**< [487:483] Output level attenuation for RACH FE2. See [OUTPUT_LEVEL_ATTEN0]. */
        uint64_t decim_ratio2          : 6;  /**< [493:488] CIC decimation ratio for RACH FE2:
                                                                 0x0, 0x1 =  Bypass.
                                                                 0x2-0x30 =  Decimate [DECIM_RATIO2]-1 input samples of every [DECIM_RATIO2] samples. */
        uint64_t oversample_ratio2     : 2;  /**< [495:494] Oversampling ratio for RACH FE2:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling.
                                                                 0x3 = Reserved. */
        uint64_t rach_freq_shift2      : 15; /**< [510:496] Frequency shift in RACH FE2. See [RACH_FREQ_SHIFT0]. */
        uint64_t rach_fe_enable2       : 1;  /**< [511:511] Enable RACH front-end 2. */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t rach_fe_enable4       : 1;  /**< [575:575] Enable RACH front-end 4. */
        uint64_t rach_freq_shift4      : 15; /**< [574:560] Frequency shift in RACH FE4. See [RACH_FREQ_SHIFT0]. */
        uint64_t oversample_ratio4     : 2;  /**< [559:558] Oversampling ratio for RACH FE4:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling. */
        uint64_t decim_ratio4          : 6;  /**< [557:552] CIC decimation ratio for RACH FE4:
                                                                 0x0, 0x1 = Bypass.
                                                                 0x2-0x30 = Decimate [DECIM_RATIO4]-1 input samples of every [DECIM_RATIO4] samples. */
        uint64_t output_level_atten4   : 5;  /**< [551:547] Output level attenuation for RACH FE4. See [OUTPUT_LEVEL_ATTEN0]. */
        uint64_t state_reset4          : 1;  /**< [546:546] RACH FE4 sample rate converter/TD-RSSI reset.
                                                                 0x0 = Hold.
                                                                 0x1 = Reset (set to 0). */
        uint64_t rach_wr_offset4       : 2;  /**< [545:544] Write offset for RACH FE4. */
        uint64_t reserved_512_543      : 32;
#else /* Word 8 - Little Endian */
        uint64_t reserved_512_543      : 32;
        uint64_t rach_wr_offset4       : 2;  /**< [545:544] Write offset for RACH FE4. */
        uint64_t state_reset4          : 1;  /**< [546:546] RACH FE4 sample rate converter/TD-RSSI reset.
                                                                 0x0 = Hold.
                                                                 0x1 = Reset (set to 0). */
        uint64_t output_level_atten4   : 5;  /**< [551:547] Output level attenuation for RACH FE4. See [OUTPUT_LEVEL_ATTEN0]. */
        uint64_t decim_ratio4          : 6;  /**< [557:552] CIC decimation ratio for RACH FE4:
                                                                 0x0, 0x1 = Bypass.
                                                                 0x2-0x30 = Decimate [DECIM_RATIO4]-1 input samples of every [DECIM_RATIO4] samples. */
        uint64_t oversample_ratio4     : 2;  /**< [559:558] Oversampling ratio for RACH FE4:
                                                                 0x0 = Bypass.
                                                                 0x1 = 2x oversampling.
                                                                 0x2 = 4x oversampling. */
        uint64_t rach_freq_shift4      : 15; /**< [574:560] Frequency shift in RACH FE4. See [RACH_FREQ_SHIFT0]. */
        uint64_t rach_fe_enable4       : 1;  /**< [575:575] Enable RACH front-end 4. */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t bwp_weight_map0       : 64; /**< [639:576] "Bandwidth part (BWP) weight map for RB0 to RB15. Contains a four-bit
                                                                 BWP index for each RB to select one of BWP #1 to BWP #5, or 0 for no
                                                                 BWP." */
#else /* Word 9 - Little Endian */
        uint64_t bwp_weight_map0       : 64; /**< [639:576] "Bandwidth part (BWP) weight map for RB0 to RB15. Contains a four-bit
                                                                 BWP index for each RB to select one of BWP #1 to BWP #5, or 0 for no
                                                                 BWP." */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t bwp_weight_map1       : 64; /**< [703:640] Bandwidth part (BWP) weight map for RB16 to RB31. */
#else /* Word 10 - Little Endian */
        uint64_t bwp_weight_map1       : 64; /**< [703:640] Bandwidth part (BWP) weight map for RB16 to RB31. */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t bwp_weight_map2       : 64; /**< [767:704] Bandwidth part (BWP) weight map for RB32 to RB47. */
#else /* Word 11 - Little Endian */
        uint64_t bwp_weight_map2       : 64; /**< [767:704] Bandwidth part (BWP) weight map for RB32 to RB47. */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t bwp_weight_map3       : 64; /**< [831:768] Bandwidth part (BWP) weight map for RB48 to RB63. */
#else /* Word 12 - Little Endian */
        uint64_t bwp_weight_map3       : 64; /**< [831:768] Bandwidth part (BWP) weight map for RB48 to RB63. */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t bwp_weight_map4       : 64; /**< [895:832] Bandwidth part (BWP) weight map for RB64 to RB79. */
#else /* Word 13 - Little Endian */
        uint64_t bwp_weight_map4       : 64; /**< [895:832] Bandwidth part (BWP) weight map for RB64 to RB79. */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t bwp_weight_map5       : 64; /**< [959:896] Bandwidth part (BWP) weight map for RB80 to RB95. */
#else /* Word 14 - Little Endian */
        uint64_t bwp_weight_map5       : 64; /**< [959:896] Bandwidth part (BWP) weight map for RB80 to RB95. */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t bwp_weight_map6       : 64; /**< [1023:960] Bandwidth part (BWP) weight map for RB96 to RB111. */
#else /* Word 15 - Little Endian */
        uint64_t bwp_weight_map6       : 64; /**< [1023:960] Bandwidth part (BWP) weight map for RB96 to RB111. */
#endif /* Word 15 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 16 - Big Endian */
        uint64_t bwp_weight_map7       : 64; /**< [1087:1024] Bandwidth part (BWP) weight map for RB112 to RB127. */
#else /* Word 16 - Little Endian */
        uint64_t bwp_weight_map7       : 64; /**< [1087:1024] Bandwidth part (BWP) weight map for RB112 to RB127. */
#endif /* Word 16 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 17 - Big Endian */
        uint64_t bwp_weight_map8       : 64; /**< [1151:1088] Bandwidth part (BWP) weight map for RB128 to RB143. */
#else /* Word 17 - Little Endian */
        uint64_t bwp_weight_map8       : 64; /**< [1151:1088] Bandwidth part (BWP) weight map for RB128 to RB143. */
#endif /* Word 17 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 18 - Big Endian */
        uint64_t bwp_weight_map9       : 64; /**< [1215:1152] Bandwidth part (BWP) weight map for RB144 to RB159. */
#else /* Word 18 - Little Endian */
        uint64_t bwp_weight_map9       : 64; /**< [1215:1152] Bandwidth part (BWP) weight map for RB144 to RB159. */
#endif /* Word 18 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 19 - Big Endian */
        uint64_t bwp_weight_map10      : 64; /**< [1279:1216] Bandwidth part (BWP) weight map for RB160 to RB175. */
#else /* Word 19 - Little Endian */
        uint64_t bwp_weight_map10      : 64; /**< [1279:1216] Bandwidth part (BWP) weight map for RB160 to RB175. */
#endif /* Word 19 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 20 - Big Endian */
        uint64_t bwp_weight_map11      : 64; /**< [1343:1280] Bandwidth part (BWP) weight map for RB176 to RB191. */
#else /* Word 20 - Little Endian */
        uint64_t bwp_weight_map11      : 64; /**< [1343:1280] Bandwidth part (BWP) weight map for RB176 to RB191. */
#endif /* Word 20 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 21 - Big Endian */
        uint64_t bwp_weight_map12      : 64; /**< [1407:1344] Bandwidth part (BWP) weight map for RB192 to RB207. */
#else /* Word 21 - Little Endian */
        uint64_t bwp_weight_map12      : 64; /**< [1407:1344] Bandwidth part (BWP) weight map for RB192 to RB207. */
#endif /* Word 21 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 22 - Big Endian */
        uint64_t bwp_weight_map13      : 64; /**< [1471:1408] Bandwidth part (BWP) weight map for RB208 to RB223. */
#else /* Word 22 - Little Endian */
        uint64_t bwp_weight_map13      : 64; /**< [1471:1408] Bandwidth part (BWP) weight map for RB208 to RB223. */
#endif /* Word 22 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 23 - Big Endian */
        uint64_t bwp_weight_map14      : 64; /**< [1535:1472] Bandwidth part (BWP) weight map for RB224 to RB239. */
#else /* Word 23 - Little Endian */
        uint64_t bwp_weight_map14      : 64; /**< [1535:1472] Bandwidth part (BWP) weight map for RB224 to RB239. */
#endif /* Word 23 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 24 - Big Endian */
        uint64_t bwp_weight_map15      : 64; /**< [1599:1536] Bandwidth part (BWP) weight map for RB240 to RB255. */
#else /* Word 24 - Little Endian */
        uint64_t bwp_weight_map15      : 64; /**< [1599:1536] Bandwidth part (BWP) weight map for RB240 to RB255. */
#endif /* Word 24 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 25 - Big Endian */
        uint64_t bwp_weight_map16      : 64; /**< [1663:1600] Bandwidth part (BWP) weight map for RB256 to RB271. */
#else /* Word 25 - Little Endian */
        uint64_t bwp_weight_map16      : 64; /**< [1663:1600] Bandwidth part (BWP) weight map for RB256 to RB271. */
#endif /* Word 25 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 26 - Big Endian */
        uint64_t bwp_weight_map17      : 6;  /**< [1727:1722] Bandwidth part (BWP) weight map for RB272 to RB274. */
        uint64_t reserved_1664_1721    : 58;
#else /* Word 26 - Little Endian */
        uint64_t reserved_1664_1721    : 58;
        uint64_t bwp_weight_map17      : 6;  /**< [1727:1722] Bandwidth part (BWP) weight map for RB272 to RB274. */
#endif /* Word 26 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 27 - Big Endian */
        uint64_t sc_att_scidx0         : 12; /**< [1791:1780] Subcarrier index 0 for subcarrier-wise attenuation. All 6 subcarrier indexes
                                                                 must be listed in the ascending order (lower index first). Valid range is
                                                                 [3329,0]. Subcarrier index larger than 3329 is disregarded. */
        uint64_t sc_att_scidx1         : 12; /**< [1779:1768] Subcarrier index 1 for subcarrier-wise attenuation. See
                                                                 [SC_ATT_SCIDX0]. */
        uint64_t sc_att_scidx2         : 12; /**< [1767:1756] Subcarrier index 2 for subcarrier-wise attenuation. See
                                                                 [SC_ATT_SCIDX0]. */
        uint64_t sc_att_scidx3         : 12; /**< [1755:1744] Subcarrier index 3 for subcarrier-wise attenuation. See
                                                                 [SC_ATT_SCIDX0]. */
        uint64_t sc_att_scidx4         : 12; /**< [1743:1732] Subcarrier index 4 for subcarrier-wise attenuation. See [SC_ATT_SCIDX0]. */
        uint64_t reserved_1728_1731    : 4;
#else /* Word 27 - Little Endian */
        uint64_t reserved_1728_1731    : 4;
        uint64_t sc_att_scidx4         : 12; /**< [1743:1732] Subcarrier index 4 for subcarrier-wise attenuation. See [SC_ATT_SCIDX0]. */
        uint64_t sc_att_scidx3         : 12; /**< [1755:1744] Subcarrier index 3 for subcarrier-wise attenuation. See
                                                                 [SC_ATT_SCIDX0]. */
        uint64_t sc_att_scidx2         : 12; /**< [1767:1756] Subcarrier index 2 for subcarrier-wise attenuation. See
                                                                 [SC_ATT_SCIDX0]. */
        uint64_t sc_att_scidx1         : 12; /**< [1779:1768] Subcarrier index 1 for subcarrier-wise attenuation. See
                                                                 [SC_ATT_SCIDX0]. */
        uint64_t sc_att_scidx0         : 12; /**< [1791:1780] Subcarrier index 0 for subcarrier-wise attenuation. All 6 subcarrier indexes
                                                                 must be listed in the ascending order (lower index first). Valid range is
                                                                 [3329,0]. Subcarrier index larger than 3329 is disregarded. */
#endif /* Word 27 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 28 - Big Endian */
        uint64_t sc_att_scidx5         : 12; /**< [1855:1844] Subcarrier index 5 for subcarrier-wise attenuation. See
                                                                 [SC_ATT_SCIDX0]. */
        uint64_t sc_att_bitmap         : 12; /**< [1843:1832] Subcarrier attenuation bitmap for six subcarriers with 2-bit switches for the
                                                                 attenuation of each subcarrier. Switches for 6 subcarriers are mapped in-order
                                                                 with subcarrier 0 in the most-signficant bits, and subcarrier 5 in the least
                                                                 significant bits. Each 2-bit switch specifies the attenuation as:
                                                                 0x0 = No scaling.
                                                                 0x1 = -6 dB attenuation.
                                                                 0x2 = -12 dB attenuation.
                                                                 0x3 = zeroing (set the selected subcarrier to 0). */
        uint64_t reserved_1792_1831    : 40;
#else /* Word 28 - Little Endian */
        uint64_t reserved_1792_1831    : 40;
        uint64_t sc_att_bitmap         : 12; /**< [1843:1832] Subcarrier attenuation bitmap for six subcarriers with 2-bit switches for the
                                                                 attenuation of each subcarrier. Switches for 6 subcarriers are mapped in-order
                                                                 with subcarrier 0 in the most-signficant bits, and subcarrier 5 in the least
                                                                 significant bits. Each 2-bit switch specifies the attenuation as:
                                                                 0x0 = No scaling.
                                                                 0x1 = -6 dB attenuation.
                                                                 0x2 = -12 dB attenuation.
                                                                 0x3 = zeroing (set the selected subcarrier to 0). */
        uint64_t sc_att_scidx5         : 12; /**< [1855:1844] Subcarrier index 5 for subcarrier-wise attenuation. See
                                                                 [SC_ATT_SCIDX0]. */
#endif /* Word 28 - End */
    } s;
    /* struct cavm_ulfe_normal_job_s_s cn; */
};

/**
 * Structure ulfe_semistatic_s
 *
 * ULFE Semi-Static Structure
 * This structure specifies the format of the job configuration for ULFE semi-static
 * parameter update jobs.
 */
union cavm_ulfe_semistatic_s
{
    uint64_t u;
    struct cavm_ulfe_semistatic_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_type           : 1;  /**< [ 63: 63] Job configuration type. It must be set to 0x0 for semi-static parameter update job type. */
        uint64_t reserved_62           : 1;
        uint64_t ant_idx               : 6;  /**< [ 61: 56] Antenna index. When updating calibration coefficients (i.e.,
                                                                 [SS_PARAM_TYPE]=0x1), this value specifies the starting antenna index of the
                                                                 calibration coefficients to be updated. Otherwise ([SS_PARAM_TYPE]= 0x0, 0x2, or
                                                                 0x3), this value is ignored. The coefficient pointers in the resource map must
                                                                 be configured before the coefficient update. */
        uint64_t reserved_50_55        : 6;
        uint64_t ss_param_type         : 2;  /**< [ 49: 48] Semi-static parameter type.
                                                                 0x0 = Resource map for 48 antennas.
                                                                 0x1 = Calibration coefficients.
                                                                 0x2 = Calibration coefficient block exponent for 48 antennas.
                                                                 0x3 = Reserved. */
        uint64_t reserved_13_47        : 35;
        uint64_t coef_size             : 13; /**< [ 12:  0] Coefficient size (in RB scale). Only used when updating calibration
                                                                 coefficients (i.e., [SS_PARAM_TYPE]=0x1), otherwise ignored. Note that
                                                                 each RB uses 6 coefficients, e.g., [COEF_SIZE]=0x4 would update 24
                                                                 coefficients, 6 for each of 4 RBs. */
#else /* Word 0 - Little Endian */
        uint64_t coef_size             : 13; /**< [ 12:  0] Coefficient size (in RB scale). Only used when updating calibration
                                                                 coefficients (i.e., [SS_PARAM_TYPE]=0x1), otherwise ignored. Note that
                                                                 each RB uses 6 coefficients, e.g., [COEF_SIZE]=0x4 would update 24
                                                                 coefficients, 6 for each of 4 RBs. */
        uint64_t reserved_13_47        : 35;
        uint64_t ss_param_type         : 2;  /**< [ 49: 48] Semi-static parameter type.
                                                                 0x0 = Resource map for 48 antennas.
                                                                 0x1 = Calibration coefficients.
                                                                 0x2 = Calibration coefficient block exponent for 48 antennas.
                                                                 0x3 = Reserved. */
        uint64_t reserved_50_55        : 6;
        uint64_t ant_idx               : 6;  /**< [ 61: 56] Antenna index. When updating calibration coefficients (i.e.,
                                                                 [SS_PARAM_TYPE]=0x1), this value specifies the starting antenna index of the
                                                                 calibration coefficients to be updated. Otherwise ([SS_PARAM_TYPE]= 0x0, 0x2, or
                                                                 0x3), this value is ignored. The coefficient pointers in the resource map must
                                                                 be configured before the coefficient update. */
        uint64_t reserved_62           : 1;
        uint64_t config_type           : 1;  /**< [ 63: 63] Job configuration type. It must be set to 0x0 for semi-static parameter update job type. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ulfe_semistatic_s_s cn; */
};

/**
 * Register (RSL) ulfe_config0_data#
 *
 * ULFE_CONFIG0 Registers
 * This register block contains the ULFE job 0 configuration data.
 */
union cavm_ulfe_config0_datax
{
    uint64_t u;
    struct cavm_ulfe_config0_datax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jcfg0                 : 64; /**< [ 63:  0](R/W) ULFE Job Configuration Word. */
#else /* Word 0 - Little Endian */
        uint64_t jcfg0                 : 64; /**< [ 63:  0](R/W) ULFE Job Configuration Word. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ulfe_config0_datax_s cn; */
};
typedef union cavm_ulfe_config0_datax cavm_ulfe_config0_datax_t;

static inline uint64_t CAVM_ULFE_CONFIG0_DATAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_CONFIG0_DATAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043082000ll + 8ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043082000ll + 8ll * ((a) & 0x1);
    __cavm_csr_fatal("ULFE_CONFIG0_DATAX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_CONFIG0_DATAX(a) cavm_ulfe_config0_datax_t
#define bustype_CAVM_ULFE_CONFIG0_DATAX(a) CSR_TYPE_RSL
#define basename_CAVM_ULFE_CONFIG0_DATAX(a) "ULFE_CONFIG0_DATAX"
#define busnum_CAVM_ULFE_CONFIG0_DATAX(a) (a)
#define arguments_CAVM_ULFE_CONFIG0_DATAX(a) (a),-1,-1,-1

/**
 * Register (RSL) ulfe_config1_data#
 *
 * ULFE_CONFIG1 Registers
 * This register block contains the ULFE job 1 configuration data.
 */
union cavm_ulfe_config1_datax
{
    uint64_t u;
    struct cavm_ulfe_config1_datax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jcfg1                 : 64; /**< [ 63:  0](R/W) ULFE Job Configuration Word. */
#else /* Word 0 - Little Endian */
        uint64_t jcfg1                 : 64; /**< [ 63:  0](R/W) ULFE Job Configuration Word. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ulfe_config1_datax_s cn; */
};
typedef union cavm_ulfe_config1_datax cavm_ulfe_config1_datax_t;

static inline uint64_t CAVM_ULFE_CONFIG1_DATAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_CONFIG1_DATAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043084000ll + 8ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043084000ll + 8ll * ((a) & 0x1);
    __cavm_csr_fatal("ULFE_CONFIG1_DATAX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_CONFIG1_DATAX(a) cavm_ulfe_config1_datax_t
#define bustype_CAVM_ULFE_CONFIG1_DATAX(a) CSR_TYPE_RSL
#define basename_CAVM_ULFE_CONFIG1_DATAX(a) "ULFE_CONFIG1_DATAX"
#define busnum_CAVM_ULFE_CONFIG1_DATAX(a) (a)
#define arguments_CAVM_ULFE_CONFIG1_DATAX(a) (a),-1,-1,-1

/**
 * Register (RSL) ulfe_config2_data#
 *
 * ULFE_CONFIG2 Registers
 * This register block contains the ULFE job 2 configuration data.
 */
union cavm_ulfe_config2_datax
{
    uint64_t u;
    struct cavm_ulfe_config2_datax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jcfg2                 : 64; /**< [ 63:  0](R/W) ULFE Job Configuration Word. */
#else /* Word 0 - Little Endian */
        uint64_t jcfg2                 : 64; /**< [ 63:  0](R/W) ULFE Job Configuration Word. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ulfe_config2_datax_s cn; */
};
typedef union cavm_ulfe_config2_datax cavm_ulfe_config2_datax_t;

static inline uint64_t CAVM_ULFE_CONFIG2_DATAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_CONFIG2_DATAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043086000ll + 8ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=1))
        return 0x87e043086000ll + 8ll * ((a) & 0x1);
    __cavm_csr_fatal("ULFE_CONFIG2_DATAX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_CONFIG2_DATAX(a) cavm_ulfe_config2_datax_t
#define bustype_CAVM_ULFE_CONFIG2_DATAX(a) CSR_TYPE_RSL
#define basename_CAVM_ULFE_CONFIG2_DATAX(a) "ULFE_CONFIG2_DATAX"
#define busnum_CAVM_ULFE_CONFIG2_DATAX(a) (a)
#define arguments_CAVM_ULFE_CONFIG2_DATAX(a) (a),-1,-1,-1

/**
 * Register (RSL) ulfe_control
 *
 * ULFE_CONTROL Register
 * This register is used to start ULFE HAB processing.
 */
union cavm_ulfe_control
{
    uint64_t u;
    struct cavm_ulfe_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jobid2                : 16; /**< [ 63: 48](R/W/H) Job ID2 */
        uint64_t jobid1                : 16; /**< [ 47: 32](R/W/H) Job ID1 */
        uint64_t jobid0                : 16; /**< [ 31: 16](R/W/H) Job ID0 */
        uint64_t reserved_3_15         : 13;
        uint64_t start2                : 1;  /**< [  2:  2](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 ULFE_CONFIG2_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (ULFE_STATUS[STATUS2] = 1). */
        uint64_t start1                : 1;  /**< [  1:  1](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 ULFE_CONFIG1_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (ULFE_STATUS[STATUS1] = 1). */
        uint64_t start0                : 1;  /**< [  0:  0](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 ULFE_CONFIG0_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (ULFE_STATUS[STATUS0] = 1). */
#else /* Word 0 - Little Endian */
        uint64_t start0                : 1;  /**< [  0:  0](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 ULFE_CONFIG0_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (ULFE_STATUS[STATUS0] = 1). */
        uint64_t start1                : 1;  /**< [  1:  1](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 ULFE_CONFIG1_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (ULFE_STATUS[STATUS1] = 1). */
        uint64_t start2                : 1;  /**< [  2:  2](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 ULFE_CONFIG2_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (ULFE_STATUS[STATUS2] = 1). */
        uint64_t reserved_3_15         : 13;
        uint64_t jobid0                : 16; /**< [ 31: 16](R/W/H) Job ID0 */
        uint64_t jobid1                : 16; /**< [ 47: 32](R/W/H) Job ID1 */
        uint64_t jobid2                : 16; /**< [ 63: 48](R/W/H) Job ID2 */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ulfe_control_s cn; */
};
typedef union cavm_ulfe_control cavm_ulfe_control_t;

#define CAVM_ULFE_CONTROL CAVM_ULFE_CONTROL_FUNC()
static inline uint64_t CAVM_ULFE_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_CONTROL_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043080000ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043080000ll;
    __cavm_csr_fatal("ULFE_CONTROL", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_CONTROL cavm_ulfe_control_t
#define bustype_CAVM_ULFE_CONTROL CSR_TYPE_RSL
#define basename_CAVM_ULFE_CONTROL "ULFE_CONTROL"
#define busnum_CAVM_ULFE_CONTROL 0
#define arguments_CAVM_ULFE_CONTROL -1,-1,-1,-1

/**
 * Register (RSL) ulfe_eco
 *
 * INTERNAL: ULFE ECO Register
 */
union cavm_ulfe_eco
{
    uint64_t u;
    struct cavm_ulfe_eco_s
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
    /* struct cavm_ulfe_eco_s cn; */
};
typedef union cavm_ulfe_eco cavm_ulfe_eco_t;

#define CAVM_ULFE_ECO CAVM_ULFE_ECO_FUNC()
static inline uint64_t CAVM_ULFE_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_ECO_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043080008ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043080008ll;
    __cavm_csr_fatal("ULFE_ECO", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_ECO cavm_ulfe_eco_t
#define bustype_CAVM_ULFE_ECO CSR_TYPE_RSL
#define basename_CAVM_ULFE_ECO "ULFE_ECO"
#define busnum_CAVM_ULFE_ECO 0
#define arguments_CAVM_ULFE_ECO -1,-1,-1,-1

/**
 * Register (RSL) ulfe_error_enable0
 *
 * ULFE Error Enable 0 Register
 * This register enables error reporting for ULFE_ERROR_SOURCE0 register.
 */
union cavm_ulfe_error_enable0
{
    uint64_t u;
    struct cavm_ulfe_error_enable0_s
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
    /* struct cavm_ulfe_error_enable0_s cn; */
};
typedef union cavm_ulfe_error_enable0 cavm_ulfe_error_enable0_t;

#define CAVM_ULFE_ERROR_ENABLE0 CAVM_ULFE_ERROR_ENABLE0_FUNC()
static inline uint64_t CAVM_ULFE_ERROR_ENABLE0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_ERROR_ENABLE0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043080040ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043080040ll;
    __cavm_csr_fatal("ULFE_ERROR_ENABLE0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_ERROR_ENABLE0 cavm_ulfe_error_enable0_t
#define bustype_CAVM_ULFE_ERROR_ENABLE0 CSR_TYPE_RSL
#define basename_CAVM_ULFE_ERROR_ENABLE0 "ULFE_ERROR_ENABLE0"
#define busnum_CAVM_ULFE_ERROR_ENABLE0 0
#define arguments_CAVM_ULFE_ERROR_ENABLE0 -1,-1,-1,-1

/**
 * Register (RSL) ulfe_error_enable1
 *
 * ULFE Error Enable Register 1
 * This register enables report particular HAB errors
 */
union cavm_ulfe_error_enable1
{
    uint64_t u;
    struct cavm_ulfe_error_enable1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t e35                   : 29; /**< [ 63: 35](R/W) Reserved. */
        uint64_t e34                   : 1;  /**< [ 34: 34](RO/H) illegal rach4 output_level_atten */
        uint64_t e33                   : 1;  /**< [ 33: 33](R/W) illegal rach4 oversample_ratio */
        uint64_t e32                   : 1;  /**< [ 32: 32](R/W) illegal rach4 decimation */
        uint64_t e31                   : 1;  /**< [ 31: 31](R/W) Reserved. */
        uint64_t e30                   : 1;  /**< [ 30: 30](R/W) illegal rach3 output_level_atten */
        uint64_t e29                   : 1;  /**< [ 29: 29](R/W) illegal rach3 oversample_ratio */
        uint64_t e28                   : 1;  /**< [ 28: 28](R/W) illegal rach3 decimation */
        uint64_t e27                   : 1;  /**< [ 27: 27](R/W) Reserved. */
        uint64_t e26                   : 1;  /**< [ 26: 26](R/W) illegal rach2 output_level_atten */
        uint64_t e25                   : 1;  /**< [ 25: 25](R/W) illegal rach2 oversample_ratio */
        uint64_t e24                   : 1;  /**< [ 24: 24](R/W) illegal rach2 decimation */
        uint64_t e23                   : 1;  /**< [ 23: 23](R/W) Reserved. */
        uint64_t e22                   : 1;  /**< [ 22: 22](R/W) illegal rach1 output_level_atten */
        uint64_t e21                   : 1;  /**< [ 21: 21](R/W) illegal rach1 oversample_ratio */
        uint64_t e20                   : 1;  /**< [ 20: 20](R/W) illegal rach1 decimation */
        uint64_t e19                   : 1;  /**< [ 19: 19](R/W) Reserved. */
        uint64_t e18                   : 1;  /**< [ 18: 18](R/W) illegal rach0 output_level_atten */
        uint64_t e17                   : 1;  /**< [ 17: 17](R/W) illegal rach0 oversample_ratio */
        uint64_t e16                   : 1;  /**< [ 16: 16](R/W) illegal rach0 decimation */
        uint64_t e9                    : 7;  /**< [ 15:  9](R/W) Reserved. */
        uint64_t e8                    : 1;  /**< [  8:  8](R/W) illegal k0 */
        uint64_t e7                    : 1;  /**< [  7:  7](R/W) illegal cprm_offset1 */
        uint64_t e6                    : 1;  /**< [  6:  6](R/W) illegal cprm_offset0 */
        uint64_t e5                    : 1;  /**< [  5:  5](R/W) illegal cprm_offset1 */
        uint64_t e4                    : 1;  /**< [  4:  4](R/W) illegal cprm_offset0 */
        uint64_t e3                    : 1;  /**< [  3:  3](R/W) illegal num_rb */
        uint64_t e2                    : 1;  /**< [  2:  2](R/W) illegal cp_size */
        uint64_t e1                    : 1;  /**< [  1:  1](R/W) illegal scs */
        uint64_t e0                    : 1;  /**< [  0:  0](R/W) illegal ant_idx */
#else /* Word 0 - Little Endian */
        uint64_t e0                    : 1;  /**< [  0:  0](R/W) illegal ant_idx */
        uint64_t e1                    : 1;  /**< [  1:  1](R/W) illegal scs */
        uint64_t e2                    : 1;  /**< [  2:  2](R/W) illegal cp_size */
        uint64_t e3                    : 1;  /**< [  3:  3](R/W) illegal num_rb */
        uint64_t e4                    : 1;  /**< [  4:  4](R/W) illegal cprm_offset0 */
        uint64_t e5                    : 1;  /**< [  5:  5](R/W) illegal cprm_offset1 */
        uint64_t e6                    : 1;  /**< [  6:  6](R/W) illegal cprm_offset0 */
        uint64_t e7                    : 1;  /**< [  7:  7](R/W) illegal cprm_offset1 */
        uint64_t e8                    : 1;  /**< [  8:  8](R/W) illegal k0 */
        uint64_t e9                    : 7;  /**< [ 15:  9](R/W) Reserved. */
        uint64_t e16                   : 1;  /**< [ 16: 16](R/W) illegal rach0 decimation */
        uint64_t e17                   : 1;  /**< [ 17: 17](R/W) illegal rach0 oversample_ratio */
        uint64_t e18                   : 1;  /**< [ 18: 18](R/W) illegal rach0 output_level_atten */
        uint64_t e19                   : 1;  /**< [ 19: 19](R/W) Reserved. */
        uint64_t e20                   : 1;  /**< [ 20: 20](R/W) illegal rach1 decimation */
        uint64_t e21                   : 1;  /**< [ 21: 21](R/W) illegal rach1 oversample_ratio */
        uint64_t e22                   : 1;  /**< [ 22: 22](R/W) illegal rach1 output_level_atten */
        uint64_t e23                   : 1;  /**< [ 23: 23](R/W) Reserved. */
        uint64_t e24                   : 1;  /**< [ 24: 24](R/W) illegal rach2 decimation */
        uint64_t e25                   : 1;  /**< [ 25: 25](R/W) illegal rach2 oversample_ratio */
        uint64_t e26                   : 1;  /**< [ 26: 26](R/W) illegal rach2 output_level_atten */
        uint64_t e27                   : 1;  /**< [ 27: 27](R/W) Reserved. */
        uint64_t e28                   : 1;  /**< [ 28: 28](R/W) illegal rach3 decimation */
        uint64_t e29                   : 1;  /**< [ 29: 29](R/W) illegal rach3 oversample_ratio */
        uint64_t e30                   : 1;  /**< [ 30: 30](R/W) illegal rach3 output_level_atten */
        uint64_t e31                   : 1;  /**< [ 31: 31](R/W) Reserved. */
        uint64_t e32                   : 1;  /**< [ 32: 32](R/W) illegal rach4 decimation */
        uint64_t e33                   : 1;  /**< [ 33: 33](R/W) illegal rach4 oversample_ratio */
        uint64_t e34                   : 1;  /**< [ 34: 34](RO/H) illegal rach4 output_level_atten */
        uint64_t e35                   : 29; /**< [ 63: 35](R/W) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ulfe_error_enable1_s cn; */
};
typedef union cavm_ulfe_error_enable1 cavm_ulfe_error_enable1_t;

#define CAVM_ULFE_ERROR_ENABLE1 CAVM_ULFE_ERROR_ENABLE1_FUNC()
static inline uint64_t CAVM_ULFE_ERROR_ENABLE1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_ERROR_ENABLE1_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043080048ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043080048ll;
    __cavm_csr_fatal("ULFE_ERROR_ENABLE1", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_ERROR_ENABLE1 cavm_ulfe_error_enable1_t
#define bustype_CAVM_ULFE_ERROR_ENABLE1 CSR_TYPE_RSL
#define basename_CAVM_ULFE_ERROR_ENABLE1 "ULFE_ERROR_ENABLE1"
#define busnum_CAVM_ULFE_ERROR_ENABLE1 0
#define arguments_CAVM_ULFE_ERROR_ENABLE1 -1,-1,-1,-1

/**
 * Register (RSL) ulfe_error_source0
 *
 * ULFE Error Source Register 0
 * This register reports the source of read DMA overflow/underflow errors.
 */
union cavm_ulfe_error_source0
{
    uint64_t u;
    struct cavm_ulfe_error_source0_s
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
    /* struct cavm_ulfe_error_source0_s cn; */
};
typedef union cavm_ulfe_error_source0 cavm_ulfe_error_source0_t;

#define CAVM_ULFE_ERROR_SOURCE0 CAVM_ULFE_ERROR_SOURCE0_FUNC()
static inline uint64_t CAVM_ULFE_ERROR_SOURCE0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_ERROR_SOURCE0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043080030ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043080030ll;
    __cavm_csr_fatal("ULFE_ERROR_SOURCE0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_ERROR_SOURCE0 cavm_ulfe_error_source0_t
#define bustype_CAVM_ULFE_ERROR_SOURCE0 CSR_TYPE_RSL
#define basename_CAVM_ULFE_ERROR_SOURCE0 "ULFE_ERROR_SOURCE0"
#define busnum_CAVM_ULFE_ERROR_SOURCE0 0
#define arguments_CAVM_ULFE_ERROR_SOURCE0 -1,-1,-1,-1

/**
 * Register (RSL) ulfe_error_source1
 *
 * ULFE Error Source Register 1
 * This register reports the source of HAB specific errors
 */
union cavm_ulfe_error_source1
{
    uint64_t u;
    struct cavm_ulfe_error_source1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_35_63        : 29;
        uint64_t e34                   : 1;  /**< [ 34: 34](RO/H) illegal rach4 output_level_atten */
        uint64_t e33                   : 1;  /**< [ 33: 33](RO/H) illegal rach4 oversample_ratio */
        uint64_t e32                   : 1;  /**< [ 32: 32](RO/H) illegal rach4 decimation */
        uint64_t reserved_31           : 1;
        uint64_t e30                   : 1;  /**< [ 30: 30](RO/H) illegal rach3 output_level_atten */
        uint64_t e29                   : 1;  /**< [ 29: 29](RO/H) illegal rach3 oversample_ratio */
        uint64_t e28                   : 1;  /**< [ 28: 28](RO/H) illegal rach3 decimation */
        uint64_t reserved_27           : 1;
        uint64_t e26                   : 1;  /**< [ 26: 26](RO/H) illegal rach2 output_level_atten */
        uint64_t e25                   : 1;  /**< [ 25: 25](RO/H) illegal rach2 oversample_ratio */
        uint64_t e24                   : 1;  /**< [ 24: 24](RO/H) illegal rach2 decimation */
        uint64_t reserved_23           : 1;
        uint64_t e22                   : 1;  /**< [ 22: 22](RO/H) illegal rach1 output_level_atten */
        uint64_t e21                   : 1;  /**< [ 21: 21](RO/H) illegal rach1 oversample_ratio */
        uint64_t e20                   : 1;  /**< [ 20: 20](RO/H) illegal rach1 decimation */
        uint64_t reserved_19           : 1;
        uint64_t e18                   : 1;  /**< [ 18: 18](RO/H) illegal rach0 output_level_atten */
        uint64_t e17                   : 1;  /**< [ 17: 17](RO/H) illegal rach0 oversample_ratio */
        uint64_t e16                   : 1;  /**< [ 16: 16](RO/H) illegal rach0 decimation */
        uint64_t reserved_9_15         : 7;
        uint64_t e8                    : 1;  /**< [  8:  8](RO/H) illegal k0 */
        uint64_t e7                    : 1;  /**< [  7:  7](RO/H) illegal cprm_offset1 */
        uint64_t e6                    : 1;  /**< [  6:  6](RO/H) illegal cprm_offset0 */
        uint64_t e5                    : 1;  /**< [  5:  5](RO/H) illegal cprm_offset1 */
        uint64_t e4                    : 1;  /**< [  4:  4](RO/H) illegal cprm_offset0 */
        uint64_t e3                    : 1;  /**< [  3:  3](RO/H) illegal num_rb */
        uint64_t e2                    : 1;  /**< [  2:  2](RO/H) illegal cp_size */
        uint64_t e1                    : 1;  /**< [  1:  1](RO/H) illegal scs */
        uint64_t e0                    : 1;  /**< [  0:  0](RO/H) illegal ant_idx */
#else /* Word 0 - Little Endian */
        uint64_t e0                    : 1;  /**< [  0:  0](RO/H) illegal ant_idx */
        uint64_t e1                    : 1;  /**< [  1:  1](RO/H) illegal scs */
        uint64_t e2                    : 1;  /**< [  2:  2](RO/H) illegal cp_size */
        uint64_t e3                    : 1;  /**< [  3:  3](RO/H) illegal num_rb */
        uint64_t e4                    : 1;  /**< [  4:  4](RO/H) illegal cprm_offset0 */
        uint64_t e5                    : 1;  /**< [  5:  5](RO/H) illegal cprm_offset1 */
        uint64_t e6                    : 1;  /**< [  6:  6](RO/H) illegal cprm_offset0 */
        uint64_t e7                    : 1;  /**< [  7:  7](RO/H) illegal cprm_offset1 */
        uint64_t e8                    : 1;  /**< [  8:  8](RO/H) illegal k0 */
        uint64_t reserved_9_15         : 7;
        uint64_t e16                   : 1;  /**< [ 16: 16](RO/H) illegal rach0 decimation */
        uint64_t e17                   : 1;  /**< [ 17: 17](RO/H) illegal rach0 oversample_ratio */
        uint64_t e18                   : 1;  /**< [ 18: 18](RO/H) illegal rach0 output_level_atten */
        uint64_t reserved_19           : 1;
        uint64_t e20                   : 1;  /**< [ 20: 20](RO/H) illegal rach1 decimation */
        uint64_t e21                   : 1;  /**< [ 21: 21](RO/H) illegal rach1 oversample_ratio */
        uint64_t e22                   : 1;  /**< [ 22: 22](RO/H) illegal rach1 output_level_atten */
        uint64_t reserved_23           : 1;
        uint64_t e24                   : 1;  /**< [ 24: 24](RO/H) illegal rach2 decimation */
        uint64_t e25                   : 1;  /**< [ 25: 25](RO/H) illegal rach2 oversample_ratio */
        uint64_t e26                   : 1;  /**< [ 26: 26](RO/H) illegal rach2 output_level_atten */
        uint64_t reserved_27           : 1;
        uint64_t e28                   : 1;  /**< [ 28: 28](RO/H) illegal rach3 decimation */
        uint64_t e29                   : 1;  /**< [ 29: 29](RO/H) illegal rach3 oversample_ratio */
        uint64_t e30                   : 1;  /**< [ 30: 30](RO/H) illegal rach3 output_level_atten */
        uint64_t reserved_31           : 1;
        uint64_t e32                   : 1;  /**< [ 32: 32](RO/H) illegal rach4 decimation */
        uint64_t e33                   : 1;  /**< [ 33: 33](RO/H) illegal rach4 oversample_ratio */
        uint64_t e34                   : 1;  /**< [ 34: 34](RO/H) illegal rach4 output_level_atten */
        uint64_t reserved_35_63        : 29;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ulfe_error_source1_s cn; */
};
typedef union cavm_ulfe_error_source1 cavm_ulfe_error_source1_t;

#define CAVM_ULFE_ERROR_SOURCE1 CAVM_ULFE_ERROR_SOURCE1_FUNC()
static inline uint64_t CAVM_ULFE_ERROR_SOURCE1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_ERROR_SOURCE1_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043080038ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043080038ll;
    __cavm_csr_fatal("ULFE_ERROR_SOURCE1", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_ERROR_SOURCE1 cavm_ulfe_error_source1_t
#define bustype_CAVM_ULFE_ERROR_SOURCE1 CSR_TYPE_RSL
#define basename_CAVM_ULFE_ERROR_SOURCE1 "ULFE_ERROR_SOURCE1"
#define busnum_CAVM_ULFE_ERROR_SOURCE1 0
#define arguments_CAVM_ULFE_ERROR_SOURCE1 -1,-1,-1,-1

/**
 * Register (RSL) ulfe_scratch
 *
 * INTERNAL: Scratch Registers
 *
 * Scratch register.
 */
union cavm_ulfe_scratch
{
    uint64_t u;
    struct cavm_ulfe_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ulfe_scratch_s cn; */
};
typedef union cavm_ulfe_scratch cavm_ulfe_scratch_t;

#define CAVM_ULFE_SCRATCH CAVM_ULFE_SCRATCH_FUNC()
static inline uint64_t CAVM_ULFE_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_SCRATCH_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043080080ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043080080ll;
    __cavm_csr_fatal("ULFE_SCRATCH", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_SCRATCH cavm_ulfe_scratch_t
#define bustype_CAVM_ULFE_SCRATCH CSR_TYPE_RSL
#define basename_CAVM_ULFE_SCRATCH "ULFE_SCRATCH"
#define busnum_CAVM_ULFE_SCRATCH 0
#define arguments_CAVM_ULFE_SCRATCH -1,-1,-1,-1

/**
 * Register (RSL) ulfe_status
 *
 * ULFE Status Register
 * ULFE Status Register.
 */
union cavm_ulfe_status
{
    uint64_t u;
    struct cavm_ulfe_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, indicates the ULFE HAB is ready to receive next job. */
        uint64_t reserved_3            : 1;
        uint64_t status2               : 1;  /**< [  2:  2](RO/H) When set, indicates the ULFE HAB is busy processing a job. */
        uint64_t status1               : 1;  /**< [  1:  1](RO/H) When set, indicates the ULFE HAB is busy processing a job. */
        uint64_t status0               : 1;  /**< [  0:  0](RO/H) When set, indicates the ULFE HAB is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t status0               : 1;  /**< [  0:  0](RO/H) When set, indicates the ULFE HAB is busy processing a job. */
        uint64_t status1               : 1;  /**< [  1:  1](RO/H) When set, indicates the ULFE HAB is busy processing a job. */
        uint64_t status2               : 1;  /**< [  2:  2](RO/H) When set, indicates the ULFE HAB is busy processing a job. */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, indicates the ULFE HAB is ready to receive next job. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ulfe_status_s cn; */
};
typedef union cavm_ulfe_status cavm_ulfe_status_t;

#define CAVM_ULFE_STATUS CAVM_ULFE_STATUS_FUNC()
static inline uint64_t CAVM_ULFE_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ULFE_STATUS_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043080018ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043080018ll;
    __cavm_csr_fatal("ULFE_STATUS", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ULFE_STATUS cavm_ulfe_status_t
#define bustype_CAVM_ULFE_STATUS CSR_TYPE_RSL
#define basename_CAVM_ULFE_STATUS "ULFE_STATUS"
#define busnum_CAVM_ULFE_STATUS 0
#define arguments_CAVM_ULFE_STATUS -1,-1,-1,-1

#endif /* __CAVM_CSRS_ULFE_H__ */
