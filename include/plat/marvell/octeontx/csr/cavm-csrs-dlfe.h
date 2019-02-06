#ifndef __CAVM_CSRS_DLFE_H__
#define __CAVM_CSRS_DLFE_H__
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
 * OcteonTX DLFE.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Structure dlfe_jcfg0_s
 *
 * DLFE JCFG0 Structure
 * This structure specifies the format for the first word of the job
 * configuration for Normal DLFE jobs.
 */
union cavm_dlfe_jcfg0_s
{
    uint64_t u;
    struct cavm_dlfe_jcfg0_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_type              : 1;  /**< [ 63: 63] The type of job configuration.
                                                                 0 = Semi-static parameter update (SSUP) job.
                                                                 1 = Normal DLFE pipeline job.
                                                                 Must be 1 when using DLFE_JCFG0_S (which is only for Normal jobs). */
        uint64_t ant_idx               : 6;  /**< [ 62: 57] Specifies the Antenna Index for the processing job. */
        uint64_t num_dma_words         : 10; /**< [ 56: 47] DMA block size to read from RD-DMA port, in 128-bit words. Each DMA word
                                                                 contains 4 baseband signal samples, since each baseband signal sample is
                                                                 (16b+16b) complex integer. The maximum RB size is 275, which is equal to 3300
                                                                 subcarriers. As such, [NUM_DMA_WORDS] must be in the range [1, 875]. */
        uint64_t fft_size_idx          : 2;  /**< [ 46: 45] Determines the FFT size.
                                                                 0x0 = 512.
                                                                 0x1 = 1024.
                                                                 0x2 = 2048.
                                                                 0x3 = 4096. */
        uint64_t cp_size               : 9;  /**< [ 44: 36] Cyclic Prefix Size for current antenna symbol. Actual number of samples for CP
                                                                 is an integer multiple of 4. The configuration parameter doesn't include the
                                                                 lower 2 bits for the sample index and number of samples = 4x [CP_SIZE]. */
        uint64_t cdd_offset            : 10; /**< [ 35: 26] CDD Size for current antenna symbol. Actual number of samples for CDD (sample
                                                                 index rotation) is an integer multiple of 4. The configuration parameter doesn't
                                                                 include the lower 2 bits for the sample index and number of samples = 4x
                                                                 [CDD_OFFSET]. */
        uint64_t zero_dc_subcarrier    : 1;  /**< [ 25: 25] Zero DC Subcarrier Insert Enable. When 1, Zero DC Subcarrier insertion is enabled. */
        uint64_t k0                    : 2;  /**< [ 24: 23] Subcarrier Offset K0 parameter.
                                                                 0x0 = Offset -6 subcarriers.
                                                                 0x1 = Offset 0 subcarriers.
                                                                 0x2 = Offset +6 subcarriers.
                                                                 0x3 = Reserved. */
        uint64_t fft_shift_enable      : 1;  /**< [ 22: 22] FFT Shift Enable Flag. When 1, enables zero padding, DC zero insert, and FFT shift procedure
                                                                 performed before IFFT. If disabled, [NUM_DMA_WORDS] must be set to
                                                                 (FFT size)/4, where the FFT size is determined by [FFT_SIZE_IDX]. */
        uint64_t calibration_enable    : 1;  /**< [ 21: 21] Calibration Enable. When 1, Calibration is enabled. */
        uint64_t ifft_enable           : 1;  /**< [ 20: 20] IFFT Enable. When 1, IFFT is enabled. For verification use only. */
        uint64_t scaler_enable         : 1;  /**< [ 19: 19] Scaler Enable. When 1, Antenna gain scaling is enabled. */
        uint64_t tssi_measurement_reset : 1; /**< [ 18: 18] If 1, it resets the TSSI accumulator buffer for the current antenna at the start of the job. */
        uint64_t tssi_measurement_report : 1;/**< [ 17: 17] If 1, the TSSI accumulator buffer for the current antenna will be reported to
                                                                 the CSR at the end of the job. */
        uint64_t reserved_0_16         : 17;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_16         : 17;
        uint64_t tssi_measurement_report : 1;/**< [ 17: 17] If 1, the TSSI accumulator buffer for the current antenna will be reported to
                                                                 the CSR at the end of the job. */
        uint64_t tssi_measurement_reset : 1; /**< [ 18: 18] If 1, it resets the TSSI accumulator buffer for the current antenna at the start of the job. */
        uint64_t scaler_enable         : 1;  /**< [ 19: 19] Scaler Enable. When 1, Antenna gain scaling is enabled. */
        uint64_t ifft_enable           : 1;  /**< [ 20: 20] IFFT Enable. When 1, IFFT is enabled. For verification use only. */
        uint64_t calibration_enable    : 1;  /**< [ 21: 21] Calibration Enable. When 1, Calibration is enabled. */
        uint64_t fft_shift_enable      : 1;  /**< [ 22: 22] FFT Shift Enable Flag. When 1, enables zero padding, DC zero insert, and FFT shift procedure
                                                                 performed before IFFT. If disabled, [NUM_DMA_WORDS] must be set to
                                                                 (FFT size)/4, where the FFT size is determined by [FFT_SIZE_IDX]. */
        uint64_t k0                    : 2;  /**< [ 24: 23] Subcarrier Offset K0 parameter.
                                                                 0x0 = Offset -6 subcarriers.
                                                                 0x1 = Offset 0 subcarriers.
                                                                 0x2 = Offset +6 subcarriers.
                                                                 0x3 = Reserved. */
        uint64_t zero_dc_subcarrier    : 1;  /**< [ 25: 25] Zero DC Subcarrier Insert Enable. When 1, Zero DC Subcarrier insertion is enabled. */
        uint64_t cdd_offset            : 10; /**< [ 35: 26] CDD Size for current antenna symbol. Actual number of samples for CDD (sample
                                                                 index rotation) is an integer multiple of 4. The configuration parameter doesn't
                                                                 include the lower 2 bits for the sample index and number of samples = 4x
                                                                 [CDD_OFFSET]. */
        uint64_t cp_size               : 9;  /**< [ 44: 36] Cyclic Prefix Size for current antenna symbol. Actual number of samples for CP
                                                                 is an integer multiple of 4. The configuration parameter doesn't include the
                                                                 lower 2 bits for the sample index and number of samples = 4x [CP_SIZE]. */
        uint64_t fft_size_idx          : 2;  /**< [ 46: 45] Determines the FFT size.
                                                                 0x0 = 512.
                                                                 0x1 = 1024.
                                                                 0x2 = 2048.
                                                                 0x3 = 4096. */
        uint64_t num_dma_words         : 10; /**< [ 56: 47] DMA block size to read from RD-DMA port, in 128-bit words. Each DMA word
                                                                 contains 4 baseband signal samples, since each baseband signal sample is
                                                                 (16b+16b) complex integer. The maximum RB size is 275, which is equal to 3300
                                                                 subcarriers. As such, [NUM_DMA_WORDS] must be in the range [1, 875]. */
        uint64_t ant_idx               : 6;  /**< [ 62: 57] Specifies the Antenna Index for the processing job. */
        uint64_t job_type              : 1;  /**< [ 63: 63] The type of job configuration.
                                                                 0 = Semi-static parameter update (SSUP) job.
                                                                 1 = Normal DLFE pipeline job.
                                                                 Must be 1 when using DLFE_JCFG0_S (which is only for Normal jobs). */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_jcfg0_s_s cn; */
};

/**
 * Structure dlfe_jcfg1_s
 *
 * DLFE JCFG1 Structure
 * This structure specifies the format of the second job configuration word
 * for Normal DLFE jobs.
 */
union cavm_dlfe_jcfg1_s
{
    uint64_t u;
    struct cavm_dlfe_jcfg1_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t complex_weight_im     : 12; /**< [ 63: 52] Complex weight imaginary part for symbol-by-symbol phase rotation. Complex
                                                                 weight rotation can be used to support BWP (bandwidth part). */
        uint64_t complex_weight_re     : 12; /**< [ 51: 40] Complex weight real part for symbol-by-symbol phase rotation. Complex weight
                                                                 rotation can be used to support BWP (bandwidth part). */
        uint64_t reserved_0_39         : 40;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_39         : 40;
        uint64_t complex_weight_re     : 12; /**< [ 51: 40] Complex weight real part for symbol-by-symbol phase rotation. Complex weight
                                                                 rotation can be used to support BWP (bandwidth part). */
        uint64_t complex_weight_im     : 12; /**< [ 63: 52] Complex weight imaginary part for symbol-by-symbol phase rotation. Complex
                                                                 weight rotation can be used to support BWP (bandwidth part). */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_jcfg1_s_s cn; */
};

/**
 * Structure dlfe_ssup_s
 *
 * DLFE SSUP Structure
 * This structure specifies the format for the first and only job configuration word for SSUP jobs.
 */
union cavm_dlfe_ssup_s
{
    uint64_t u;
    struct cavm_dlfe_ssup_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_type              : 1;  /**< [ 63: 63] The type of job configuration.
                                                                 0 = Semi-static parameter update (SSUP) job.
                                                                 1 = Normal DLFE pipeline job.
                                                                 Must be 0 when using DLFE_SSUP_S (which is only for SSUP jobs). */
        uint64_t reserved_58_62        : 5;
        uint64_t ss_param_type         : 2;  /**< [ 57: 56] Indicates which SSUP parameters to update, as follows:
                                                                 0x0 = Calibration coefficient for resource map.
                                                                 0x1 = Calibration coefficient.
                                                                 0x2 = Calibration coefficient exponent.
                                                                 0x3 = Antenna gain. */
        uint64_t reserved_54_55        : 2;
        uint64_t ant_idx               : 6;  /**< [ 53: 48] Specifies the antenna index for update of calibration coefficients.
                                                                 Only valid when [SS_PARAM_TYPE] = 0x1. */
        uint64_t reserved_14_47        : 34;
        uint64_t coeff_size            : 14; /**< [ 13:  0] Read DMA block size for calibration coefficient update, in 128-bit words.
                                                                 Only valid when [SS_PARAM_TYPE] = 0x1. */
#else /* Word 0 - Little Endian */
        uint64_t coeff_size            : 14; /**< [ 13:  0] Read DMA block size for calibration coefficient update, in 128-bit words.
                                                                 Only valid when [SS_PARAM_TYPE] = 0x1. */
        uint64_t reserved_14_47        : 34;
        uint64_t ant_idx               : 6;  /**< [ 53: 48] Specifies the antenna index for update of calibration coefficients.
                                                                 Only valid when [SS_PARAM_TYPE] = 0x1. */
        uint64_t reserved_54_55        : 2;
        uint64_t ss_param_type         : 2;  /**< [ 57: 56] Indicates which SSUP parameters to update, as follows:
                                                                 0x0 = Calibration coefficient for resource map.
                                                                 0x1 = Calibration coefficient.
                                                                 0x2 = Calibration coefficient exponent.
                                                                 0x3 = Antenna gain. */
        uint64_t reserved_58_62        : 5;
        uint64_t job_type              : 1;  /**< [ 63: 63] The type of job configuration.
                                                                 0 = Semi-static parameter update (SSUP) job.
                                                                 1 = Normal DLFE pipeline job.
                                                                 Must be 0 when using DLFE_SSUP_S (which is only for SSUP jobs). */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_ssup_s_s cn; */
};

/**
 * Register (RSL) dlfe_acal_addr
 *
 * DLFE ACAL Address Register
 * Antenna calibration memory address register.
 */
union cavm_dlfe_acal_addr
{
    uint64_t u;
    struct cavm_dlfe_acal_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t addr                  : 16; /**< [ 15:  0](R/W) Address of ACAL coefficient to be operated upon. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 16; /**< [ 15:  0](R/W) Address of ACAL coefficient to be operated upon. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_acal_addr_s cn; */
};
typedef union cavm_dlfe_acal_addr cavm_dlfe_acal_addr_t;

#define CAVM_DLFE_ACAL_ADDR CAVM_DLFE_ACAL_ADDR_FUNC()
static inline uint64_t CAVM_DLFE_ACAL_ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_ACAL_ADDR_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043180408ll;
    __cavm_csr_fatal("DLFE_ACAL_ADDR", 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DLFE_ACAL_ADDR cavm_dlfe_acal_addr_t
#define bustype_CAVM_DLFE_ACAL_ADDR CSR_TYPE_RSL
#define basename_CAVM_DLFE_ACAL_ADDR "DLFE_ACAL_ADDR"
#define busnum_CAVM_DLFE_ACAL_ADDR 0
#define arguments_CAVM_DLFE_ACAL_ADDR -1,-1,-1,-1

/**
 * Register (RSL) dlfe_acal_coef
 *
 * DLFE ACAL COEFF Register
 * This register writes to, or reads antenna calibration coefficient at the address specified by
 * DLFE_ACAL_ADDR.
 * DLFE_ACAL_ADDR must be written to before reading or writing this register.
 */
union cavm_dlfe_acal_coef
{
    uint64_t u;
    struct cavm_dlfe_acal_coef_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t coef_im               : 12; /**< [ 23: 12](R/W/H) Imaginary component of calibration coefficient. */
        uint64_t coef_re               : 12; /**< [ 11:  0](R/W/H) Real component of calibration coefficient. */
#else /* Word 0 - Little Endian */
        uint64_t coef_re               : 12; /**< [ 11:  0](R/W/H) Real component of calibration coefficient. */
        uint64_t coef_im               : 12; /**< [ 23: 12](R/W/H) Imaginary component of calibration coefficient. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_acal_coef_s cn; */
};
typedef union cavm_dlfe_acal_coef cavm_dlfe_acal_coef_t;

#define CAVM_DLFE_ACAL_COEF CAVM_DLFE_ACAL_COEF_FUNC()
static inline uint64_t CAVM_DLFE_ACAL_COEF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_ACAL_COEF_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043180400ll;
    __cavm_csr_fatal("DLFE_ACAL_COEF", 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DLFE_ACAL_COEF cavm_dlfe_acal_coef_t
#define bustype_CAVM_DLFE_ACAL_COEF CSR_TYPE_RSL
#define basename_CAVM_DLFE_ACAL_COEF "DLFE_ACAL_COEF"
#define busnum_CAVM_DLFE_ACAL_COEF 0
#define arguments_CAVM_DLFE_ACAL_COEF -1,-1,-1,-1

/**
 * Register (RSL) dlfe_ant_exp#
 *
 * DLFE Antenna Exponent Register
 * This register contains the antenna calibration exponent values.
 */
union cavm_dlfe_ant_expx
{
    uint64_t u;
    struct cavm_dlfe_ant_expx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t ant7                  : 4;  /**< [ 59: 56](R/W) ACAL exp 7. */
        uint64_t reserved_52_55        : 4;
        uint64_t ant6                  : 4;  /**< [ 51: 48](R/W) ACAL exp 6. */
        uint64_t reserved_44_47        : 4;
        uint64_t ant5                  : 4;  /**< [ 43: 40](R/W) ACAL exp 7. */
        uint64_t reserved_36_39        : 4;
        uint64_t ant4                  : 4;  /**< [ 35: 32](R/W) ACAL exp 6. */
        uint64_t reserved_28_31        : 4;
        uint64_t ant3                  : 4;  /**< [ 27: 24](R/W) ACAL exp 7. */
        uint64_t reserved_20_23        : 4;
        uint64_t ant2                  : 4;  /**< [ 19: 16](R/W) ACAL exp 6. */
        uint64_t reserved_12_15        : 4;
        uint64_t ant1                  : 4;  /**< [ 11:  8](R/W) ACAL exp 7. */
        uint64_t reserved_4_7          : 4;
        uint64_t ant0                  : 4;  /**< [  3:  0](R/W) ACAL exp 6. */
#else /* Word 0 - Little Endian */
        uint64_t ant0                  : 4;  /**< [  3:  0](R/W) ACAL exp 6. */
        uint64_t reserved_4_7          : 4;
        uint64_t ant1                  : 4;  /**< [ 11:  8](R/W) ACAL exp 7. */
        uint64_t reserved_12_15        : 4;
        uint64_t ant2                  : 4;  /**< [ 19: 16](R/W) ACAL exp 6. */
        uint64_t reserved_20_23        : 4;
        uint64_t ant3                  : 4;  /**< [ 27: 24](R/W) ACAL exp 7. */
        uint64_t reserved_28_31        : 4;
        uint64_t ant4                  : 4;  /**< [ 35: 32](R/W) ACAL exp 6. */
        uint64_t reserved_36_39        : 4;
        uint64_t ant5                  : 4;  /**< [ 43: 40](R/W) ACAL exp 7. */
        uint64_t reserved_44_47        : 4;
        uint64_t ant6                  : 4;  /**< [ 51: 48](R/W) ACAL exp 6. */
        uint64_t reserved_52_55        : 4;
        uint64_t ant7                  : 4;  /**< [ 59: 56](R/W) ACAL exp 7. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_ant_expx_s cn; */
};
typedef union cavm_dlfe_ant_expx cavm_dlfe_ant_expx_t;

static inline uint64_t CAVM_DLFE_ANT_EXPX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_ANT_EXPX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=5))
        return 0x87e043180580ll + 8ll * ((a) & 0x7);
    __cavm_csr_fatal("DLFE_ANT_EXPX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DLFE_ANT_EXPX(a) cavm_dlfe_ant_expx_t
#define bustype_CAVM_DLFE_ANT_EXPX(a) CSR_TYPE_RSL
#define basename_CAVM_DLFE_ANT_EXPX(a) "DLFE_ANT_EXPX"
#define busnum_CAVM_DLFE_ANT_EXPX(a) (a)
#define arguments_CAVM_DLFE_ANT_EXPX(a) (a),-1,-1,-1

/**
 * Register (RSL) dlfe_ant_gain#
 *
 * DLFE Antenna Gain Register
 * This register contains the antenna gain values.
 */
union cavm_dlfe_ant_gainx
{
    uint64_t u;
    struct cavm_dlfe_ant_gainx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t ant3                  : 14; /**< [ 61: 48](R/W) Ant Gain 3. */
        uint64_t reserved_46_47        : 2;
        uint64_t ant2                  : 14; /**< [ 45: 32](R/W) Ant Gain 2. */
        uint64_t reserved_30_31        : 2;
        uint64_t ant1                  : 14; /**< [ 29: 16](R/W) Ant Gain 1. */
        uint64_t reserved_14_15        : 2;
        uint64_t ant0                  : 14; /**< [ 13:  0](R/W) Ant Gain 0. */
#else /* Word 0 - Little Endian */
        uint64_t ant0                  : 14; /**< [ 13:  0](R/W) Ant Gain 0. */
        uint64_t reserved_14_15        : 2;
        uint64_t ant1                  : 14; /**< [ 29: 16](R/W) Ant Gain 1. */
        uint64_t reserved_30_31        : 2;
        uint64_t ant2                  : 14; /**< [ 45: 32](R/W) Ant Gain 2. */
        uint64_t reserved_46_47        : 2;
        uint64_t ant3                  : 14; /**< [ 61: 48](R/W) Ant Gain 3. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_ant_gainx_s cn; */
};
typedef union cavm_dlfe_ant_gainx cavm_dlfe_ant_gainx_t;

static inline uint64_t CAVM_DLFE_ANT_GAINX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_ANT_GAINX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=11))
        return 0x87e043180500ll + 8ll * ((a) & 0xf);
    __cavm_csr_fatal("DLFE_ANT_GAINX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DLFE_ANT_GAINX(a) cavm_dlfe_ant_gainx_t
#define bustype_CAVM_DLFE_ANT_GAINX(a) CSR_TYPE_RSL
#define basename_CAVM_DLFE_ANT_GAINX(a) "DLFE_ANT_GAINX"
#define busnum_CAVM_DLFE_ANT_GAINX(a) (a)
#define arguments_CAVM_DLFE_ANT_GAINX(a) (a),-1,-1,-1

/**
 * Register (RSL) dlfe_config0_data#
 *
 * DLFE_CONFIG0 Registers
 * This register block contains the DLFE job 0 configuration data.
 */
union cavm_dlfe_config0_datax
{
    uint64_t u;
    struct cavm_dlfe_config0_datax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jcfg0                 : 64; /**< [ 63:  0](R/W) DLFE Job Configuration Word. */
#else /* Word 0 - Little Endian */
        uint64_t jcfg0                 : 64; /**< [ 63:  0](R/W) DLFE Job Configuration Word. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_config0_datax_s cn; */
};
typedef union cavm_dlfe_config0_datax cavm_dlfe_config0_datax_t;

static inline uint64_t CAVM_DLFE_CONFIG0_DATAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_CONFIG0_DATAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043182000ll + 8ll * ((a) & 0x1);
    __cavm_csr_fatal("DLFE_CONFIG0_DATAX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DLFE_CONFIG0_DATAX(a) cavm_dlfe_config0_datax_t
#define bustype_CAVM_DLFE_CONFIG0_DATAX(a) CSR_TYPE_RSL
#define basename_CAVM_DLFE_CONFIG0_DATAX(a) "DLFE_CONFIG0_DATAX"
#define busnum_CAVM_DLFE_CONFIG0_DATAX(a) (a)
#define arguments_CAVM_DLFE_CONFIG0_DATAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dlfe_config1_data#
 *
 * DLFE_CONFIG1 Registers
 * This register block contains the DLFE job 1 configuration data.
 */
union cavm_dlfe_config1_datax
{
    uint64_t u;
    struct cavm_dlfe_config1_datax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jcfg1                 : 64; /**< [ 63:  0](R/W) DLFE Job Configuration Word. */
#else /* Word 0 - Little Endian */
        uint64_t jcfg1                 : 64; /**< [ 63:  0](R/W) DLFE Job Configuration Word. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_config1_datax_s cn; */
};
typedef union cavm_dlfe_config1_datax cavm_dlfe_config1_datax_t;

static inline uint64_t CAVM_DLFE_CONFIG1_DATAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_CONFIG1_DATAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043184000ll + 8ll * ((a) & 0x1);
    __cavm_csr_fatal("DLFE_CONFIG1_DATAX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DLFE_CONFIG1_DATAX(a) cavm_dlfe_config1_datax_t
#define bustype_CAVM_DLFE_CONFIG1_DATAX(a) CSR_TYPE_RSL
#define basename_CAVM_DLFE_CONFIG1_DATAX(a) "DLFE_CONFIG1_DATAX"
#define busnum_CAVM_DLFE_CONFIG1_DATAX(a) (a)
#define arguments_CAVM_DLFE_CONFIG1_DATAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dlfe_config2_data#
 *
 * DLFE_CONFIG2 Registers
 * This register block contains the DLFE job 2 configuration data.
 */
union cavm_dlfe_config2_datax
{
    uint64_t u;
    struct cavm_dlfe_config2_datax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jcfg2                 : 64; /**< [ 63:  0](R/W) DLFE Job Configuration Word. */
#else /* Word 0 - Little Endian */
        uint64_t jcfg2                 : 64; /**< [ 63:  0](R/W) DLFE Job Configuration Word. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_config2_datax_s cn; */
};
typedef union cavm_dlfe_config2_datax cavm_dlfe_config2_datax_t;

static inline uint64_t CAVM_DLFE_CONFIG2_DATAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_CONFIG2_DATAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043186000ll + 8ll * ((a) & 0x1);
    __cavm_csr_fatal("DLFE_CONFIG2_DATAX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DLFE_CONFIG2_DATAX(a) cavm_dlfe_config2_datax_t
#define bustype_CAVM_DLFE_CONFIG2_DATAX(a) CSR_TYPE_RSL
#define basename_CAVM_DLFE_CONFIG2_DATAX(a) "DLFE_CONFIG2_DATAX"
#define busnum_CAVM_DLFE_CONFIG2_DATAX(a) (a)
#define arguments_CAVM_DLFE_CONFIG2_DATAX(a) (a),-1,-1,-1

/**
 * Register (RSL) dlfe_control
 *
 * DLFE_CONTROL Register
 * This register is used to start DLFE HAB processing.
 */
union cavm_dlfe_control
{
    uint64_t u;
    struct cavm_dlfe_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t jobid2                : 16; /**< [ 63: 48](R/W/H) Job ID2 */
        uint64_t jobid1                : 16; /**< [ 47: 32](R/W/H) Job ID1 */
        uint64_t jobid0                : 16; /**< [ 31: 16](R/W/H) Job ID0 */
        uint64_t reserved_3_15         : 13;
        uint64_t start2                : 1;  /**< [  2:  2](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 DLFE_CONFIG2_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (DLFE_STATUS[STATUS2] = 1). */
        uint64_t start1                : 1;  /**< [  1:  1](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 DLFE_CONFIG1_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (DLFE_STATUS[STATUS1] = 1). */
        uint64_t start0                : 1;  /**< [  0:  0](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 DLFE_CONFIG0_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (DLFE_STATUS[STATUS0] = 1). */
#else /* Word 0 - Little Endian */
        uint64_t start0                : 1;  /**< [  0:  0](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 DLFE_CONFIG0_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (DLFE_STATUS[STATUS0] = 1). */
        uint64_t start1                : 1;  /**< [  1:  1](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 DLFE_CONFIG1_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (DLFE_STATUS[STATUS1] = 1). */
        uint64_t start2                : 1;  /**< [  2:  2](R/W/H) A write of 1 will start the HAB using the configuration in
                                                                 DLFE_CONFIG2_DATA(). This bit auto-clears, and it is ignored if the
                                                                 HAB status is busy (DLFE_STATUS[STATUS2] = 1). */
        uint64_t reserved_3_15         : 13;
        uint64_t jobid0                : 16; /**< [ 31: 16](R/W/H) Job ID0 */
        uint64_t jobid1                : 16; /**< [ 47: 32](R/W/H) Job ID1 */
        uint64_t jobid2                : 16; /**< [ 63: 48](R/W/H) Job ID2 */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_control_s cn; */
};
typedef union cavm_dlfe_control cavm_dlfe_control_t;

#define CAVM_DLFE_CONTROL CAVM_DLFE_CONTROL_FUNC()
static inline uint64_t CAVM_DLFE_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_CONTROL_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043180000ll;
    __cavm_csr_fatal("DLFE_CONTROL", 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DLFE_CONTROL cavm_dlfe_control_t
#define bustype_CAVM_DLFE_CONTROL CSR_TYPE_RSL
#define basename_CAVM_DLFE_CONTROL "DLFE_CONTROL"
#define busnum_CAVM_DLFE_CONTROL 0
#define arguments_CAVM_DLFE_CONTROL -1,-1,-1,-1

/**
 * Register (RSL) dlfe_eco
 *
 * INTERNAL: DLFE ECO Register
 */
union cavm_dlfe_eco
{
    uint64_t u;
    struct cavm_dlfe_eco_s
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
    /* struct cavm_dlfe_eco_s cn; */
};
typedef union cavm_dlfe_eco cavm_dlfe_eco_t;

#define CAVM_DLFE_ECO CAVM_DLFE_ECO_FUNC()
static inline uint64_t CAVM_DLFE_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_ECO_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043180008ll;
    __cavm_csr_fatal("DLFE_ECO", 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DLFE_ECO cavm_dlfe_eco_t
#define bustype_CAVM_DLFE_ECO CSR_TYPE_RSL
#define basename_CAVM_DLFE_ECO "DLFE_ECO"
#define busnum_CAVM_DLFE_ECO 0
#define arguments_CAVM_DLFE_ECO -1,-1,-1,-1

/**
 * Register (RSL) dlfe_error_enable0
 *
 * DLFE Error Enable 0 Register
 * This register enables error reporting for DLFE_ERROR_SOURCE0 register.
 */
union cavm_dlfe_error_enable0
{
    uint64_t u;
    struct cavm_dlfe_error_enable0_s
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
    /* struct cavm_dlfe_error_enable0_s cn; */
};
typedef union cavm_dlfe_error_enable0 cavm_dlfe_error_enable0_t;

#define CAVM_DLFE_ERROR_ENABLE0 CAVM_DLFE_ERROR_ENABLE0_FUNC()
static inline uint64_t CAVM_DLFE_ERROR_ENABLE0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_ERROR_ENABLE0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043180040ll;
    __cavm_csr_fatal("DLFE_ERROR_ENABLE0", 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DLFE_ERROR_ENABLE0 cavm_dlfe_error_enable0_t
#define bustype_CAVM_DLFE_ERROR_ENABLE0 CSR_TYPE_RSL
#define basename_CAVM_DLFE_ERROR_ENABLE0 "DLFE_ERROR_ENABLE0"
#define busnum_CAVM_DLFE_ERROR_ENABLE0 0
#define arguments_CAVM_DLFE_ERROR_ENABLE0 -1,-1,-1,-1

/**
 * Register (RSL) dlfe_error_source0
 *
 * DLFE Error Source Register 0
 * This register reports the source of read DMA overflow/underflow errors.
 */
union cavm_dlfe_error_source0
{
    uint64_t u;
    struct cavm_dlfe_error_source0_s
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
    /* struct cavm_dlfe_error_source0_s cn; */
};
typedef union cavm_dlfe_error_source0 cavm_dlfe_error_source0_t;

#define CAVM_DLFE_ERROR_SOURCE0 CAVM_DLFE_ERROR_SOURCE0_FUNC()
static inline uint64_t CAVM_DLFE_ERROR_SOURCE0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_ERROR_SOURCE0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043180030ll;
    __cavm_csr_fatal("DLFE_ERROR_SOURCE0", 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DLFE_ERROR_SOURCE0 cavm_dlfe_error_source0_t
#define bustype_CAVM_DLFE_ERROR_SOURCE0 CSR_TYPE_RSL
#define basename_CAVM_DLFE_ERROR_SOURCE0 "DLFE_ERROR_SOURCE0"
#define busnum_CAVM_DLFE_ERROR_SOURCE0 0
#define arguments_CAVM_DLFE_ERROR_SOURCE0 -1,-1,-1,-1

/**
 * Register (RSL) dlfe_res_map#
 *
 * DLFE Resource Map Register
 * This register contains the resource map values.
 */
union cavm_dlfe_res_mapx
{
    uint64_t u;
    struct cavm_dlfe_res_mapx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t ptr3                  : 14; /**< [ 61: 48](R/W) ACAL pointer 3. */
        uint64_t reserved_46_47        : 2;
        uint64_t ptr2                  : 14; /**< [ 45: 32](R/W) ACAL pointer 2. */
        uint64_t reserved_30_31        : 2;
        uint64_t ptr1                  : 14; /**< [ 29: 16](R/W) ACAL pointer 1. */
        uint64_t reserved_14_15        : 2;
        uint64_t ptr0                  : 14; /**< [ 13:  0](R/W) ACAL pointer 0. */
#else /* Word 0 - Little Endian */
        uint64_t ptr0                  : 14; /**< [ 13:  0](R/W) ACAL pointer 0. */
        uint64_t reserved_14_15        : 2;
        uint64_t ptr1                  : 14; /**< [ 29: 16](R/W) ACAL pointer 1. */
        uint64_t reserved_30_31        : 2;
        uint64_t ptr2                  : 14; /**< [ 45: 32](R/W) ACAL pointer 2. */
        uint64_t reserved_46_47        : 2;
        uint64_t ptr3                  : 14; /**< [ 61: 48](R/W) ACAL pointer 3. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_res_mapx_s cn; */
};
typedef union cavm_dlfe_res_mapx cavm_dlfe_res_mapx_t;

static inline uint64_t CAVM_DLFE_RES_MAPX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_RES_MAPX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=11))
        return 0x87e043180480ll + 8ll * ((a) & 0xf);
    __cavm_csr_fatal("DLFE_RES_MAPX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DLFE_RES_MAPX(a) cavm_dlfe_res_mapx_t
#define bustype_CAVM_DLFE_RES_MAPX(a) CSR_TYPE_RSL
#define basename_CAVM_DLFE_RES_MAPX(a) "DLFE_RES_MAPX"
#define busnum_CAVM_DLFE_RES_MAPX(a) (a)
#define arguments_CAVM_DLFE_RES_MAPX(a) (a),-1,-1,-1

/**
 * Register (RSL) dlfe_scratch
 *
 * INTERNAL: Scratch Registers
 *
 * Scratch register.
 */
union cavm_dlfe_scratch
{
    uint64_t u;
    struct cavm_dlfe_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_scratch_s cn; */
};
typedef union cavm_dlfe_scratch cavm_dlfe_scratch_t;

#define CAVM_DLFE_SCRATCH CAVM_DLFE_SCRATCH_FUNC()
static inline uint64_t CAVM_DLFE_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_SCRATCH_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043180080ll;
    __cavm_csr_fatal("DLFE_SCRATCH", 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DLFE_SCRATCH cavm_dlfe_scratch_t
#define bustype_CAVM_DLFE_SCRATCH CSR_TYPE_RSL
#define basename_CAVM_DLFE_SCRATCH "DLFE_SCRATCH"
#define busnum_CAVM_DLFE_SCRATCH 0
#define arguments_CAVM_DLFE_SCRATCH -1,-1,-1,-1

/**
 * Register (RSL) dlfe_status
 *
 * DLFE Status Register
 * DLFE Status Register.
 */
union cavm_dlfe_status
{
    uint64_t u;
    struct cavm_dlfe_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, indicates the DLFE HAB is ready to receive next job. */
        uint64_t reserved_3            : 1;
        uint64_t status2               : 1;  /**< [  2:  2](RO/H) When set, indicates the DLFE HAB is busy processing a job. */
        uint64_t status1               : 1;  /**< [  1:  1](RO/H) When set, indicates the DLFE HAB is busy processing a job. */
        uint64_t status0               : 1;  /**< [  0:  0](RO/H) When set, indicates the DLFE HAB is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t status0               : 1;  /**< [  0:  0](RO/H) When set, indicates the DLFE HAB is busy processing a job. */
        uint64_t status1               : 1;  /**< [  1:  1](RO/H) When set, indicates the DLFE HAB is busy processing a job. */
        uint64_t status2               : 1;  /**< [  2:  2](RO/H) When set, indicates the DLFE HAB is busy processing a job. */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, indicates the DLFE HAB is ready to receive next job. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_status_s cn; */
};
typedef union cavm_dlfe_status cavm_dlfe_status_t;

#define CAVM_DLFE_STATUS CAVM_DLFE_STATUS_FUNC()
static inline uint64_t CAVM_DLFE_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_STATUS_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e043180018ll;
    __cavm_csr_fatal("DLFE_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DLFE_STATUS cavm_dlfe_status_t
#define bustype_CAVM_DLFE_STATUS CSR_TYPE_RSL
#define basename_CAVM_DLFE_STATUS "DLFE_STATUS"
#define busnum_CAVM_DLFE_STATUS 0
#define arguments_CAVM_DLFE_STATUS -1,-1,-1,-1

/**
 * Register (RSL) dlfe_tssi#
 *
 * DLFE TSSI Register
 * This register reports TSSI values.
 */
union cavm_dlfe_tssix
{
    uint64_t u;
    struct cavm_dlfe_tssix_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tssi                  : 64; /**< [ 63:  0](RO/H) TSSI Report value for Antenna(x) */
#else /* Word 0 - Little Endian */
        uint64_t tssi                  : 64; /**< [ 63:  0](RO/H) TSSI Report value for Antenna(x) */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dlfe_tssix_s cn; */
};
typedef union cavm_dlfe_tssix cavm_dlfe_tssix_t;

static inline uint64_t CAVM_DLFE_TSSIX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DLFE_TSSIX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=47))
        return 0x87e043180200ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("DLFE_TSSIX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_DLFE_TSSIX(a) cavm_dlfe_tssix_t
#define bustype_CAVM_DLFE_TSSIX(a) CSR_TYPE_RSL
#define basename_CAVM_DLFE_TSSIX(a) "DLFE_TSSIX"
#define busnum_CAVM_DLFE_TSSIX(a) (a)
#define arguments_CAVM_DLFE_TSSIX(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_DLFE_H__ */
