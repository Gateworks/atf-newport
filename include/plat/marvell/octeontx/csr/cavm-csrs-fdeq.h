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
 * Register (RSL) fdeq#_active_ue_num_for_hop
 *
 * Register
 */
union cavm_fdeqx_active_ue_num_for_hop
{
    uint64_t u;
    struct cavm_fdeqx_active_ue_num_for_hop_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t hop_index_per_symbol  : 28; /**< [ 51: 24](R/W) 0-3 of symbol index [13-0] */
        uint64_t active_ue_num_of_hop_3 : 6; /**< [ 23: 18](R/W) 1-32 */
        uint64_t active_ue_num_of_hop_2 : 6; /**< [ 17: 12](R/W) 1-32 */
        uint64_t active_ue_num_of_hop_1 : 6; /**< [ 11:  6](R/W) 1-32 */
        uint64_t active_ue_num_of_hop_0 : 6; /**< [  5:  0](R/W) 1-32 */
#else /* Word 0 - Little Endian */
        uint64_t active_ue_num_of_hop_0 : 6; /**< [  5:  0](R/W) 1-32 */
        uint64_t active_ue_num_of_hop_1 : 6; /**< [ 11:  6](R/W) 1-32 */
        uint64_t active_ue_num_of_hop_2 : 6; /**< [ 17: 12](R/W) 1-32 */
        uint64_t active_ue_num_of_hop_3 : 6; /**< [ 23: 18](R/W) 1-32 */
        uint64_t hop_index_per_symbol  : 28; /**< [ 51: 24](R/W) 0-3 of symbol index [13-0] */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_active_ue_num_for_hop_s cn; */
};
typedef union cavm_fdeqx_active_ue_num_for_hop cavm_fdeqx_active_ue_num_for_hop_t;

static inline uint64_t CAVM_FDEQX_ACTIVE_UE_NUM_FOR_HOP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_ACTIVE_UE_NUM_FOR_HOP(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202040ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_ACTIVE_UE_NUM_FOR_HOP", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_ACTIVE_UE_NUM_FOR_HOP(a) cavm_fdeqx_active_ue_num_for_hop_t
#define bustype_CAVM_FDEQX_ACTIVE_UE_NUM_FOR_HOP(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_ACTIVE_UE_NUM_FOR_HOP(a) "FDEQX_ACTIVE_UE_NUM_FOR_HOP"
#define busnum_CAVM_FDEQX_ACTIVE_UE_NUM_FOR_HOP(a) (a)
#define arguments_CAVM_FDEQX_ACTIVE_UE_NUM_FOR_HOP(a) (a),-1,-1,-1

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
        uint64_t reserved_48_63        : 16;
        uint64_t port1_oflow_uflow_job_id : 16;/**< [ 47: 32](R/W1C) The first job ID which makes read port1 overflow/underflow, after
                                                                 reset or write clear */
        uint64_t port0_oflow_uflow_job_id : 16;/**< [ 31: 16](R/W1C) The first job ID which makes read port0 overflow/underflow, after
                                                                 reset or write clear */
        uint64_t reserved_6_15         : 10;
        uint64_t read_port1_overflow   : 1;  /**< [  5:  5](R/W1C) Read port1 overflow */
        uint64_t read_port0_overflow   : 1;  /**< [  4:  4](R/W1C) Read port0 overflow */
        uint64_t reserved_2_3          : 2;
        uint64_t read_port1_underflow  : 1;  /**< [  1:  1](R/W1C) Read port1 underflow */
        uint64_t read_port0_underflow  : 1;  /**< [  0:  0](R/W1C) Read port0 underflow */
#else /* Word 0 - Little Endian */
        uint64_t read_port0_underflow  : 1;  /**< [  0:  0](R/W1C) Read port0 underflow */
        uint64_t read_port1_underflow  : 1;  /**< [  1:  1](R/W1C) Read port1 underflow */
        uint64_t reserved_2_3          : 2;
        uint64_t read_port0_overflow   : 1;  /**< [  4:  4](R/W1C) Read port0 overflow */
        uint64_t read_port1_overflow   : 1;  /**< [  5:  5](R/W1C) Read port1 overflow */
        uint64_t reserved_6_15         : 10;
        uint64_t port0_oflow_uflow_job_id : 16;/**< [ 31: 16](R/W1C) The first job ID which makes read port0 overflow/underflow, after
                                                                 reset or write clear */
        uint64_t port1_oflow_uflow_job_id : 16;/**< [ 47: 32](R/W1C) The first job ID which makes read port1 overflow/underflow, after
                                                                 reset or write clear */
        uint64_t reserved_48_63        : 16;
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
 * Register (RSL) fdeq#_general_parameter
 *
 * Register
 */
union cavm_fdeqx_general_parameter
{
    uint64_t u;
    struct cavm_fdeqx_general_parameter_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t if_frequency_sparse   : 1;  /**< [ 63: 63](R/W) 0=every tone, 1=every other tone */
        uint64_t rb_number_include_subprb : 8;/**< [ 62: 55](R/W) num of ue in subprb_RBs + num of normal RBs */
        uint64_t h_dmrs_input_bitshift : 3;  /**< [ 54: 52](R/W) 0~4 */
        uint64_t x_dmrs_input_bitshift : 3;  /**< [ 51: 49](R/W) 0~5 */
        uint64_t soft_sic_on           : 1;  /**< [ 48: 48](R/W) 0= disable, 1= enable (DMA)receive and use soft_sic_p */
        uint64_t rs_frequency_sparse   : 1;  /**< [ 47: 47](R/W) 0=every tone, 1=every other tone */
        uint64_t data_frequency_sparse : 2;  /**< [ 46: 45](R/W) 0=every tone, 1=every other tone, 2=every 4tone */
        uint64_t reserved_32_44        : 13;
        uint64_t sic_with_crc_map      : 1;  /**< [ 31: 31](R/W) 0-1 */
        uint64_t rs3_symbol_index      : 4;  /**< [ 30: 27](R/W) 0..13 */
        uint64_t rs2_symbol_index      : 4;  /**< [ 26: 23](R/W) 0..13 */
        uint64_t rs1_symbol_index      : 4;  /**< [ 22: 19](R/W) symbol index of H_RS symbol 1 */
        uint64_t rs0_symbol_index      : 4;  /**< [ 18: 15](R/W) symbol index of H_RS symbol 0 */
        uint64_t sic_on_off            : 1;  /**< [ 14: 14](R/W) SIC on/off
                                                                 (DMA)receive and use x_hat_data
                                                                 0=off(1st decoding), 1=on(2nd decoding) */
        uint64_t timewf_set_number     : 4;  /**< [ 13: 10](R/W) (DMA)TimeWF_Weight set number 1~11 */
        uint64_t data_symbol_number    : 4;  /**< [  9:  6](R/W) (DMA) number of Data sybmol 1~14 */
        uint64_t ue_number             : 6;  /**< [  5:  0](R/W) (DMA)number of enabled UE 1~32 */
#else /* Word 0 - Little Endian */
        uint64_t ue_number             : 6;  /**< [  5:  0](R/W) (DMA)number of enabled UE 1~32 */
        uint64_t data_symbol_number    : 4;  /**< [  9:  6](R/W) (DMA) number of Data sybmol 1~14 */
        uint64_t timewf_set_number     : 4;  /**< [ 13: 10](R/W) (DMA)TimeWF_Weight set number 1~11 */
        uint64_t sic_on_off            : 1;  /**< [ 14: 14](R/W) SIC on/off
                                                                 (DMA)receive and use x_hat_data
                                                                 0=off(1st decoding), 1=on(2nd decoding) */
        uint64_t rs0_symbol_index      : 4;  /**< [ 18: 15](R/W) symbol index of H_RS symbol 0 */
        uint64_t rs1_symbol_index      : 4;  /**< [ 22: 19](R/W) symbol index of H_RS symbol 1 */
        uint64_t rs2_symbol_index      : 4;  /**< [ 26: 23](R/W) 0..13 */
        uint64_t rs3_symbol_index      : 4;  /**< [ 30: 27](R/W) 0..13 */
        uint64_t sic_with_crc_map      : 1;  /**< [ 31: 31](R/W) 0-1 */
        uint64_t reserved_32_44        : 13;
        uint64_t data_frequency_sparse : 2;  /**< [ 46: 45](R/W) 0=every tone, 1=every other tone, 2=every 4tone */
        uint64_t rs_frequency_sparse   : 1;  /**< [ 47: 47](R/W) 0=every tone, 1=every other tone */
        uint64_t soft_sic_on           : 1;  /**< [ 48: 48](R/W) 0= disable, 1= enable (DMA)receive and use soft_sic_p */
        uint64_t x_dmrs_input_bitshift : 3;  /**< [ 51: 49](R/W) 0~5 */
        uint64_t h_dmrs_input_bitshift : 3;  /**< [ 54: 52](R/W) 0~4 */
        uint64_t rb_number_include_subprb : 8;/**< [ 62: 55](R/W) num of ue in subprb_RBs + num of normal RBs */
        uint64_t if_frequency_sparse   : 1;  /**< [ 63: 63](R/W) 0=every tone, 1=every other tone */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_general_parameter_s cn; */
};
typedef union cavm_fdeqx_general_parameter cavm_fdeqx_general_parameter_t;

static inline uint64_t CAVM_FDEQX_GENERAL_PARAMETER(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_GENERAL_PARAMETER(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202020ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_GENERAL_PARAMETER", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_GENERAL_PARAMETER(a) cavm_fdeqx_general_parameter_t
#define bustype_CAVM_FDEQX_GENERAL_PARAMETER(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_GENERAL_PARAMETER(a) "FDEQX_GENERAL_PARAMETER"
#define busnum_CAVM_FDEQX_GENERAL_PARAMETER(a) (a)
#define arguments_CAVM_FDEQX_GENERAL_PARAMETER(a) (a),-1,-1,-1

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
 * Register (RSL) fdeq#_hrs_addr_offset_per_ant
 *
 * Register
 */
union cavm_fdeqx_hrs_addr_offset_per_ant
{
    uint64_t u;
    struct cavm_fdeqx_hrs_addr_offset_per_ant_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t subprb_job_enable     : 1;  /**< [ 32: 32](R/W) Select normal vs. subprb job type.
                                                                 0 = Normal job.
                                                                 1 = Subprb job, with no UE report at RS. */
        uint64_t gap_between_jobs      : 16; /**< [ 31: 16](R/W) 0= @(\<20 cycle),1=@+20 cycle */
        uint64_t reserved_9_15         : 7;
        uint64_t hrs_addr_offset_per_ant : 9;/**< [  8:  0](R/W) ceiling(RB*(tone/RB)/4,1) max = 420 */
#else /* Word 0 - Little Endian */
        uint64_t hrs_addr_offset_per_ant : 9;/**< [  8:  0](R/W) ceiling(RB*(tone/RB)/4,1) max = 420 */
        uint64_t reserved_9_15         : 7;
        uint64_t gap_between_jobs      : 16; /**< [ 31: 16](R/W) 0= @(\<20 cycle),1=@+20 cycle */
        uint64_t subprb_job_enable     : 1;  /**< [ 32: 32](R/W) Select normal vs. subprb job type.
                                                                 0 = Normal job.
                                                                 1 = Subprb job, with no UE report at RS. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_hrs_addr_offset_per_ant_s cn; */
};
typedef union cavm_fdeqx_hrs_addr_offset_per_ant cavm_fdeqx_hrs_addr_offset_per_ant_t;

static inline uint64_t CAVM_FDEQX_HRS_ADDR_OFFSET_PER_ANT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_HRS_ADDR_OFFSET_PER_ANT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202008ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_HRS_ADDR_OFFSET_PER_ANT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_HRS_ADDR_OFFSET_PER_ANT(a) cavm_fdeqx_hrs_addr_offset_per_ant_t
#define bustype_CAVM_FDEQX_HRS_ADDR_OFFSET_PER_ANT(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_HRS_ADDR_OFFSET_PER_ANT(a) "FDEQX_HRS_ADDR_OFFSET_PER_ANT"
#define busnum_CAVM_FDEQX_HRS_ADDR_OFFSET_PER_ANT(a) (a)
#define arguments_CAVM_FDEQX_HRS_ADDR_OFFSET_PER_ANT(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_hrs_buf_parameter_1
 *
 * Register
 */
union cavm_fdeqx_hrs_buf_parameter_1
{
    uint64_t u;
    struct cavm_fdeqx_hrs_buf_parameter_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t hrs_buf_start_offset_rs1_l7 : 7;/**< [ 55: 49](R/W) 2RS mode - RS3 layer-3 */
        uint64_t hrs_buf_start_offset_rs1_l6 : 7;/**< [ 48: 42](R/W) 2RS mode - RS3 layer-2 */
        uint64_t hrs_buf_start_offset_rs1_l5 : 7;/**< [ 41: 35](R/W) 2RS mode - RS3 layer-1 */
        uint64_t hrs_buf_start_offset_rs1_l4 : 7;/**< [ 34: 28](R/W) 2RS mode - RS3 layer-0 */
        uint64_t hrs_buf_start_offset_rs1_l3 : 7;/**< [ 27: 21](R/W) layer */
        uint64_t hrs_buf_start_offset_rs1_l2 : 7;/**< [ 20: 14](R/W) layer */
        uint64_t hrs_buf_start_offset_rs1_l1 : 7;/**< [ 13:  7](R/W) layer */
        uint64_t hrs_buf_start_offset_rs1_l0 : 7;/**< [  6:  0](R/W) layer */
#else /* Word 0 - Little Endian */
        uint64_t hrs_buf_start_offset_rs1_l0 : 7;/**< [  6:  0](R/W) layer */
        uint64_t hrs_buf_start_offset_rs1_l1 : 7;/**< [ 13:  7](R/W) layer */
        uint64_t hrs_buf_start_offset_rs1_l2 : 7;/**< [ 20: 14](R/W) layer */
        uint64_t hrs_buf_start_offset_rs1_l3 : 7;/**< [ 27: 21](R/W) layer */
        uint64_t hrs_buf_start_offset_rs1_l4 : 7;/**< [ 34: 28](R/W) 2RS mode - RS3 layer-0 */
        uint64_t hrs_buf_start_offset_rs1_l5 : 7;/**< [ 41: 35](R/W) 2RS mode - RS3 layer-1 */
        uint64_t hrs_buf_start_offset_rs1_l6 : 7;/**< [ 48: 42](R/W) 2RS mode - RS3 layer-2 */
        uint64_t hrs_buf_start_offset_rs1_l7 : 7;/**< [ 55: 49](R/W) 2RS mode - RS3 layer-3 */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_hrs_buf_parameter_1_s cn; */
};
typedef union cavm_fdeqx_hrs_buf_parameter_1 cavm_fdeqx_hrs_buf_parameter_1_t;

static inline uint64_t CAVM_FDEQX_HRS_BUF_PARAMETER_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_HRS_BUF_PARAMETER_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202018ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_HRS_BUF_PARAMETER_1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_HRS_BUF_PARAMETER_1(a) cavm_fdeqx_hrs_buf_parameter_1_t
#define bustype_CAVM_FDEQX_HRS_BUF_PARAMETER_1(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_HRS_BUF_PARAMETER_1(a) "FDEQX_HRS_BUF_PARAMETER_1"
#define busnum_CAVM_FDEQX_HRS_BUF_PARAMETER_1(a) (a)
#define arguments_CAVM_FDEQX_HRS_BUF_PARAMETER_1(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_hrs_buffer_param_0
 *
 * Register
 */
union cavm_fdeqx_hrs_buffer_param_0
{
    uint64_t u;
    struct cavm_fdeqx_hrs_buffer_param_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t active_ue_number      : 6;  /**< [ 62: 57](R/W) 1~32 */
        uint64_t mixes_hrs_memory_type_enable : 1;/**< [ 56: 56](R/W) 0= disable 1= enable */
        uint64_t hrs_buf_start_offset_rs0_l7 : 7;/**< [ 55: 49](R/W) 2RS_MODE - RS2_LAYER-3 */
        uint64_t hrs_buf_start_offset_rs0_l6 : 7;/**< [ 48: 42](R/W) 2RS_MODE - RS2_LAYER-2 */
        uint64_t hrs_buf_start_offset_rs0_l5 : 7;/**< [ 41: 35](R/W) 2RS_MODE - RS2_LAYER-1 */
        uint64_t hrs_buf_start_offset_rs0_l4 : 7;/**< [ 34: 28](R/W) 2RS_MODE - RS2_LAYER-0 */
        uint64_t hrs_buf_start_offset_rs0_l3 : 7;/**< [ 27: 21](R/W) layer */
        uint64_t hrs_buf_start_offset_rs0_l2 : 7;/**< [ 20: 14](R/W) layer */
        uint64_t hrs_buf_start_offset_rs0_l1 : 7;/**< [ 13:  7](R/W) layer */
        uint64_t hrs_buf_start_offset_rs0_l0 : 7;/**< [  6:  0](R/W) start offset of Hrs buffer layer-0 0~47
                                                                 (type-0)0~31 - 3840tone/memory
                                                                 (type-1)32~47 - 5760tone/memory */
#else /* Word 0 - Little Endian */
        uint64_t hrs_buf_start_offset_rs0_l0 : 7;/**< [  6:  0](R/W) start offset of Hrs buffer layer-0 0~47
                                                                 (type-0)0~31 - 3840tone/memory
                                                                 (type-1)32~47 - 5760tone/memory */
        uint64_t hrs_buf_start_offset_rs0_l1 : 7;/**< [ 13:  7](R/W) layer */
        uint64_t hrs_buf_start_offset_rs0_l2 : 7;/**< [ 20: 14](R/W) layer */
        uint64_t hrs_buf_start_offset_rs0_l3 : 7;/**< [ 27: 21](R/W) layer */
        uint64_t hrs_buf_start_offset_rs0_l4 : 7;/**< [ 34: 28](R/W) 2RS_MODE - RS2_LAYER-0 */
        uint64_t hrs_buf_start_offset_rs0_l5 : 7;/**< [ 41: 35](R/W) 2RS_MODE - RS2_LAYER-1 */
        uint64_t hrs_buf_start_offset_rs0_l6 : 7;/**< [ 48: 42](R/W) 2RS_MODE - RS2_LAYER-2 */
        uint64_t hrs_buf_start_offset_rs0_l7 : 7;/**< [ 55: 49](R/W) 2RS_MODE - RS2_LAYER-3 */
        uint64_t mixes_hrs_memory_type_enable : 1;/**< [ 56: 56](R/W) 0= disable 1= enable */
        uint64_t active_ue_number      : 6;  /**< [ 62: 57](R/W) 1~32 */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_hrs_buffer_param_0_s cn; */
};
typedef union cavm_fdeqx_hrs_buffer_param_0 cavm_fdeqx_hrs_buffer_param_0_t;

static inline uint64_t CAVM_FDEQX_HRS_BUFFER_PARAM_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_HRS_BUFFER_PARAM_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202010ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_HRS_BUFFER_PARAM_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_HRS_BUFFER_PARAM_0(a) cavm_fdeqx_hrs_buffer_param_0_t
#define bustype_CAVM_FDEQX_HRS_BUFFER_PARAM_0(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_HRS_BUFFER_PARAM_0(a) "FDEQX_HRS_BUFFER_PARAM_0"
#define busnum_CAVM_FDEQX_HRS_BUFFER_PARAM_0(a) (a)
#define arguments_CAVM_FDEQX_HRS_BUFFER_PARAM_0(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_hrs_sym_idx_for_tdce
 *
 * Register
 */
union cavm_fdeqx_hrs_sym_idx_for_tdce
{
    uint64_t u;
    struct cavm_fdeqx_hrs_sym_idx_for_tdce_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t rs1_symbol_13         : 2;  /**< [ 55: 54](R/W) symbol */
        uint64_t rs1_symbol_12         : 2;  /**< [ 53: 52](R/W) symbol */
        uint64_t rs1_symbol_11         : 2;  /**< [ 51: 50](R/W) symbol */
        uint64_t rs1_symbol_10         : 2;  /**< [ 49: 48](R/W) symbol */
        uint64_t rs1_symbol_9          : 2;  /**< [ 47: 46](R/W) symbol */
        uint64_t rs1_symbol_8          : 2;  /**< [ 45: 44](R/W) symbol */
        uint64_t rs1_symbol_7          : 2;  /**< [ 43: 42](R/W) symbol */
        uint64_t rs1_symbol_6          : 2;  /**< [ 41: 40](R/W) symbol */
        uint64_t rs1_symbol_5          : 2;  /**< [ 39: 38](R/W) symbol */
        uint64_t rs1_symbol_4          : 2;  /**< [ 37: 36](R/W) symbol */
        uint64_t rs1_symbol_3          : 2;  /**< [ 35: 34](R/W) symbol */
        uint64_t rs1_symbol_2          : 2;  /**< [ 33: 32](R/W) symbol */
        uint64_t rs1_symbol_1          : 2;  /**< [ 31: 30](R/W) symbol */
        uint64_t rs1_symbol_0          : 2;  /**< [ 29: 28](R/W) symbol */
        uint64_t rs0_symbol_13         : 2;  /**< [ 27: 26](R/W) symbol */
        uint64_t rs0_symbol_12         : 2;  /**< [ 25: 24](R/W) symbol */
        uint64_t rs0_symbol_11         : 2;  /**< [ 23: 22](R/W) symbol */
        uint64_t rs0_symbol_10         : 2;  /**< [ 21: 20](R/W) symbol */
        uint64_t rs0_symbol_9          : 2;  /**< [ 19: 18](R/W) symbol */
        uint64_t rs0_symbol_8          : 2;  /**< [ 17: 16](R/W) symbol */
        uint64_t rs0_symbol_7          : 2;  /**< [ 15: 14](R/W) symbol */
        uint64_t rs0_symbol_6          : 2;  /**< [ 13: 12](R/W) symbol */
        uint64_t rs0_symbol_5          : 2;  /**< [ 11: 10](R/W) symbol */
        uint64_t rs0_symbol_4          : 2;  /**< [  9:  8](R/W) symbol */
        uint64_t rs0_symbol_3          : 2;  /**< [  7:  6](R/W) symbol */
        uint64_t rs0_symbol_2          : 2;  /**< [  5:  4](R/W) symbol */
        uint64_t rs0_symbol_1          : 2;  /**< [  3:  2](R/W) symbol */
        uint64_t rs0_symbol_0          : 2;  /**< [  1:  0](R/W) symbol */
#else /* Word 0 - Little Endian */
        uint64_t rs0_symbol_0          : 2;  /**< [  1:  0](R/W) symbol */
        uint64_t rs0_symbol_1          : 2;  /**< [  3:  2](R/W) symbol */
        uint64_t rs0_symbol_2          : 2;  /**< [  5:  4](R/W) symbol */
        uint64_t rs0_symbol_3          : 2;  /**< [  7:  6](R/W) symbol */
        uint64_t rs0_symbol_4          : 2;  /**< [  9:  8](R/W) symbol */
        uint64_t rs0_symbol_5          : 2;  /**< [ 11: 10](R/W) symbol */
        uint64_t rs0_symbol_6          : 2;  /**< [ 13: 12](R/W) symbol */
        uint64_t rs0_symbol_7          : 2;  /**< [ 15: 14](R/W) symbol */
        uint64_t rs0_symbol_8          : 2;  /**< [ 17: 16](R/W) symbol */
        uint64_t rs0_symbol_9          : 2;  /**< [ 19: 18](R/W) symbol */
        uint64_t rs0_symbol_10         : 2;  /**< [ 21: 20](R/W) symbol */
        uint64_t rs0_symbol_11         : 2;  /**< [ 23: 22](R/W) symbol */
        uint64_t rs0_symbol_12         : 2;  /**< [ 25: 24](R/W) symbol */
        uint64_t rs0_symbol_13         : 2;  /**< [ 27: 26](R/W) symbol */
        uint64_t rs1_symbol_0          : 2;  /**< [ 29: 28](R/W) symbol */
        uint64_t rs1_symbol_1          : 2;  /**< [ 31: 30](R/W) symbol */
        uint64_t rs1_symbol_2          : 2;  /**< [ 33: 32](R/W) symbol */
        uint64_t rs1_symbol_3          : 2;  /**< [ 35: 34](R/W) symbol */
        uint64_t rs1_symbol_4          : 2;  /**< [ 37: 36](R/W) symbol */
        uint64_t rs1_symbol_5          : 2;  /**< [ 39: 38](R/W) symbol */
        uint64_t rs1_symbol_6          : 2;  /**< [ 41: 40](R/W) symbol */
        uint64_t rs1_symbol_7          : 2;  /**< [ 43: 42](R/W) symbol */
        uint64_t rs1_symbol_8          : 2;  /**< [ 45: 44](R/W) symbol */
        uint64_t rs1_symbol_9          : 2;  /**< [ 47: 46](R/W) symbol */
        uint64_t rs1_symbol_10         : 2;  /**< [ 49: 48](R/W) symbol */
        uint64_t rs1_symbol_11         : 2;  /**< [ 51: 50](R/W) symbol */
        uint64_t rs1_symbol_12         : 2;  /**< [ 53: 52](R/W) symbol */
        uint64_t rs1_symbol_13         : 2;  /**< [ 55: 54](R/W) symbol */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_hrs_sym_idx_for_tdce_s cn; */
};
typedef union cavm_fdeqx_hrs_sym_idx_for_tdce cavm_fdeqx_hrs_sym_idx_for_tdce_t;

static inline uint64_t CAVM_FDEQX_HRS_SYM_IDX_FOR_TDCE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_HRS_SYM_IDX_FOR_TDCE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202028ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_HRS_SYM_IDX_FOR_TDCE", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_HRS_SYM_IDX_FOR_TDCE(a) cavm_fdeqx_hrs_sym_idx_for_tdce_t
#define bustype_CAVM_FDEQX_HRS_SYM_IDX_FOR_TDCE(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_HRS_SYM_IDX_FOR_TDCE(a) "FDEQX_HRS_SYM_IDX_FOR_TDCE"
#define busnum_CAVM_FDEQX_HRS_SYM_IDX_FOR_TDCE(a) (a)
#define arguments_CAVM_FDEQX_HRS_SYM_IDX_FOR_TDCE(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_job_typeand_rs_param
 *
 * Register
 */
union cavm_fdeqx_job_typeand_rs_param
{
    uint64_t u;
    struct cavm_fdeqx_job_typeand_rs_param_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data_only_job_mode_enable : 1;/**< [ 63: 63](R/W) active high */
        uint64_t data_symbol_start_offset : 4;/**< [ 62: 59](R/W) 0~13 */
        uint64_t hrs_start_rb_offset   : 8;  /**< [ 58: 51](R/W) 0~139 */
        uint64_t rs3_rb_start_index    : 8;  /**< [ 50: 43](R/W) 0~139 */
        uint64_t rs2_rb_start_index    : 8;  /**< [ 42: 35](R/W) 0~139 */
        uint64_t rs1_rb_start_index    : 8;  /**< [ 34: 27](R/W) 0~139 */
        uint64_t rs0_rb_start_index    : 8;  /**< [ 26: 19](R/W) 0~139 */
        uint64_t data_only_job_indicator : 1;/**< [ 18: 18](R/W) 0=RS+DS, 1=Data only */
        uint64_t fdm_mode_enable       : 1;  /**< [ 17: 17](R/W) 0=generation FDE only data symbol
                                                                 1=generation FDE RS+data symbol */
        uint64_t rs_sequence_generation_enable : 1;/**< [ 16: 16](R/W) 0=disable, 1=enable */
        uint64_t antenna_mode          : 2;  /**< [ 15: 14](R/W) (DMA)antenna mode selection 0=2R, 1=4R, 2=8R, 3=16R */
        uint64_t layer_mode            : 2;  /**< [ 13: 12](R/W) number of layer 0=1layer, 1=2layer, 2=4layer, 3=8layer */
        uint64_t hrs_symbol_number     : 3;  /**< [ 11:  9](R/W) 1~4 */
        uint64_t hrs_rb_number         : 8;  /**< [  8:  1](R/W) RB number of Hrs 1~140 */
        uint64_t job_type              : 1;  /**< [  0:  0](R/W) 0= job type-0, 1= job type-1 */
#else /* Word 0 - Little Endian */
        uint64_t job_type              : 1;  /**< [  0:  0](R/W) 0= job type-0, 1= job type-1 */
        uint64_t hrs_rb_number         : 8;  /**< [  8:  1](R/W) RB number of Hrs 1~140 */
        uint64_t hrs_symbol_number     : 3;  /**< [ 11:  9](R/W) 1~4 */
        uint64_t layer_mode            : 2;  /**< [ 13: 12](R/W) number of layer 0=1layer, 1=2layer, 2=4layer, 3=8layer */
        uint64_t antenna_mode          : 2;  /**< [ 15: 14](R/W) (DMA)antenna mode selection 0=2R, 1=4R, 2=8R, 3=16R */
        uint64_t rs_sequence_generation_enable : 1;/**< [ 16: 16](R/W) 0=disable, 1=enable */
        uint64_t fdm_mode_enable       : 1;  /**< [ 17: 17](R/W) 0=generation FDE only data symbol
                                                                 1=generation FDE RS+data symbol */
        uint64_t data_only_job_indicator : 1;/**< [ 18: 18](R/W) 0=RS+DS, 1=Data only */
        uint64_t rs0_rb_start_index    : 8;  /**< [ 26: 19](R/W) 0~139 */
        uint64_t rs1_rb_start_index    : 8;  /**< [ 34: 27](R/W) 0~139 */
        uint64_t rs2_rb_start_index    : 8;  /**< [ 42: 35](R/W) 0~139 */
        uint64_t rs3_rb_start_index    : 8;  /**< [ 50: 43](R/W) 0~139 */
        uint64_t hrs_start_rb_offset   : 8;  /**< [ 58: 51](R/W) 0~139 */
        uint64_t data_symbol_start_offset : 4;/**< [ 62: 59](R/W) 0~13 */
        uint64_t data_only_job_mode_enable : 1;/**< [ 63: 63](R/W) active high */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_job_typeand_rs_param_s cn; */
};
typedef union cavm_fdeqx_job_typeand_rs_param cavm_fdeqx_job_typeand_rs_param_t;

static inline uint64_t CAVM_FDEQX_JOB_TYPEAND_RS_PARAM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_JOB_TYPEAND_RS_PARAM(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202000ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_JOB_TYPEAND_RS_PARAM", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_JOB_TYPEAND_RS_PARAM(a) cavm_fdeqx_job_typeand_rs_param_t
#define bustype_CAVM_FDEQX_JOB_TYPEAND_RS_PARAM(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_JOB_TYPEAND_RS_PARAM(a) "FDEQX_JOB_TYPEAND_RS_PARAM"
#define busnum_CAVM_FDEQX_JOB_TYPEAND_RS_PARAM(a) (a)
#define arguments_CAVM_FDEQX_JOB_TYPEAND_RS_PARAM(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_sxbc_map_0
 *
 * Register
 */
union cavm_fdeqx_sxbc_map_0
{
    uint64_t u;
    struct cavm_fdeqx_sxbc_map_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t txd_transform_mode    : 2;  /**< [ 53: 52](R/W) - 0= off - 1= SFBC on
                                                                   . (input) y_data- tone2rx mapping and pre-proc
                                                                   . (output) FDEQ- single layer and post-proc
                                                                 - 2= STBC on
                                                                   . (input) no tone2rx mapping, only (Extra ant.) y_data- pre-proc
                                                                   . (output) FDEQ- single layer and post-proc */
        uint64_t txd_transform_map_0_r0r1_t0 : 4;/**< [ 51: 48](R/W) R0/R1 tone index to map tone 0 */
        uint64_t txd_transform_map_0_r2r3_t0 : 4;/**< [ 47: 44](R/W) R2/R3 tone index to map tone 0 */
        uint64_t txd_transform_map_0r0r1_t1 : 4;/**< [ 43: 40](R/W) R0/R1 tone index to map tone 1 */
        uint64_t txd_transform_map_0_r2r3_t1 : 4;/**< [ 39: 36](R/W) R2/R3 tone index to map tone 1 */
        uint64_t txd_transform_map_0_r0r1_t2 : 4;/**< [ 35: 32](R/W) R0/R1 tone index to map tone 2 */
        uint64_t txd_transform_map_0_r2r3_t2 : 4;/**< [ 31: 28](R/W) R2/R3 tone index to map tone 2 */
        uint64_t txd_transform_map_0_r0r1_t3 : 4;/**< [ 27: 24](R/W) R0/R1 tone index to map tone 3 */
        uint64_t txd_transform_map_0_r2r3_t3 : 4;/**< [ 23: 20](R/W) R2/R3 tone index to map tone 3 */
        uint64_t txd_transform_map_0r0r1_t4 : 4;/**< [ 19: 16](R/W) R0/R1 tone index to map tone 4 */
        uint64_t txd_transform_map_0_r2r3_t4 : 4;/**< [ 15: 12](R/W) R2/R3 tone index to map tone 4 */
        uint64_t txd_transform_map_0_r0r1_t5 : 4;/**< [ 11:  8](R/W) R0/R1 tone index to map tone 5 */
        uint64_t txd_transform_map_0_r2r3_t5 : 4;/**< [  7:  4](R/W) R2/R3 tone index to map tone 5 */
        uint64_t txd_preprocess_0      : 2;  /**< [  3:  2](R/W) (Extra ant.) y_data - 0= off, 1= conjugate(), 2= -1*conjugate() */
        uint64_t txd_postprocess_0     : 2;  /**< [  1:  0](R/W) FDE single layer(only 2nd layer)
                                                                 0= off, 1= conjugate(), 2= -1*conjugate() */
#else /* Word 0 - Little Endian */
        uint64_t txd_postprocess_0     : 2;  /**< [  1:  0](R/W) FDE single layer(only 2nd layer)
                                                                 0= off, 1= conjugate(), 2= -1*conjugate() */
        uint64_t txd_preprocess_0      : 2;  /**< [  3:  2](R/W) (Extra ant.) y_data - 0= off, 1= conjugate(), 2= -1*conjugate() */
        uint64_t txd_transform_map_0_r2r3_t5 : 4;/**< [  7:  4](R/W) R2/R3 tone index to map tone 5 */
        uint64_t txd_transform_map_0_r0r1_t5 : 4;/**< [ 11:  8](R/W) R0/R1 tone index to map tone 5 */
        uint64_t txd_transform_map_0_r2r3_t4 : 4;/**< [ 15: 12](R/W) R2/R3 tone index to map tone 4 */
        uint64_t txd_transform_map_0r0r1_t4 : 4;/**< [ 19: 16](R/W) R0/R1 tone index to map tone 4 */
        uint64_t txd_transform_map_0_r2r3_t3 : 4;/**< [ 23: 20](R/W) R2/R3 tone index to map tone 3 */
        uint64_t txd_transform_map_0_r0r1_t3 : 4;/**< [ 27: 24](R/W) R0/R1 tone index to map tone 3 */
        uint64_t txd_transform_map_0_r2r3_t2 : 4;/**< [ 31: 28](R/W) R2/R3 tone index to map tone 2 */
        uint64_t txd_transform_map_0_r0r1_t2 : 4;/**< [ 35: 32](R/W) R0/R1 tone index to map tone 2 */
        uint64_t txd_transform_map_0_r2r3_t1 : 4;/**< [ 39: 36](R/W) R2/R3 tone index to map tone 1 */
        uint64_t txd_transform_map_0r0r1_t1 : 4;/**< [ 43: 40](R/W) R0/R1 tone index to map tone 1 */
        uint64_t txd_transform_map_0_r2r3_t0 : 4;/**< [ 47: 44](R/W) R2/R3 tone index to map tone 0 */
        uint64_t txd_transform_map_0_r0r1_t0 : 4;/**< [ 51: 48](R/W) R0/R1 tone index to map tone 0 */
        uint64_t txd_transform_mode    : 2;  /**< [ 53: 52](R/W) - 0= off - 1= SFBC on
                                                                   . (input) y_data- tone2rx mapping and pre-proc
                                                                   . (output) FDEQ- single layer and post-proc
                                                                 - 2= STBC on
                                                                   . (input) no tone2rx mapping, only (Extra ant.) y_data- pre-proc
                                                                   . (output) FDEQ- single layer and post-proc */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_sxbc_map_0_s cn; */
};
typedef union cavm_fdeqx_sxbc_map_0 cavm_fdeqx_sxbc_map_0_t;

static inline uint64_t CAVM_FDEQX_SXBC_MAP_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_SXBC_MAP_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202030ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_SXBC_MAP_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_SXBC_MAP_0(a) cavm_fdeqx_sxbc_map_0_t
#define bustype_CAVM_FDEQX_SXBC_MAP_0(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_SXBC_MAP_0(a) "FDEQX_SXBC_MAP_0"
#define busnum_CAVM_FDEQX_SXBC_MAP_0(a) (a)
#define arguments_CAVM_FDEQX_SXBC_MAP_0(a) (a),-1,-1,-1

/**
 * Register (RSL) fdeq#_sxbc_map_1
 *
 * Register
 */
union cavm_fdeqx_sxbc_map_1
{
    uint64_t u;
    struct cavm_fdeqx_sxbc_map_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t txd_transform_map_1_r0r1_t0 : 4;/**< [ 51: 48](R/W) R0/R1 tone index to map tone 0 */
        uint64_t txd_transform_map_1_r2r3_t0 : 4;/**< [ 47: 44](R/W) R2/R3 tone index to map tone 0 */
        uint64_t txd_transform_map_1_r0r1_t1 : 4;/**< [ 43: 40](R/W) R0/R1 tone index to map tone 1 */
        uint64_t txd_transform_map_1_r2r3_t1 : 4;/**< [ 39: 36](R/W) R2/R3 tone index to map tone 1 */
        uint64_t txd_transform_map_1_r0r1_t2 : 4;/**< [ 35: 32](R/W) R0/R1 tone index to map tone 2 */
        uint64_t txd_transform_map_1_r2r3_t2 : 4;/**< [ 31: 28](R/W) R2/R3 tone index to map tone 2 */
        uint64_t txd_transform_map_1_r0r1_t3 : 4;/**< [ 27: 24](R/W) R0/R1 tone index to map tone 3 */
        uint64_t txd_transform_map_1_r2r3_t3 : 4;/**< [ 23: 20](R/W) R2/R3 tone index to map tone 3 */
        uint64_t txd_transform_map_1_r0r1_t4 : 4;/**< [ 19: 16](R/W) R0/R1 tone index to map tone 4 */
        uint64_t txd_transform_map_1_r2r3_t4 : 4;/**< [ 15: 12](R/W) R2/R3 tone index to map tone 4 */
        uint64_t txd_transform_map_1_r0r1_t5 : 4;/**< [ 11:  8](R/W) R0/R1 tone index to map tone 5 */
        uint64_t txd_transform_map_1_r2r3_t5 : 4;/**< [  7:  4](R/W) R2/R3 tone index to map tone 5 */
        uint64_t txd_preprocess_1      : 2;  /**< [  3:  2](R/W) (Extra ant.) y_data - 0= off, 1= conjugate(), 2= -1*conjugate() */
        uint64_t txd_postprocess_1     : 2;  /**< [  1:  0](R/W) FDE single layer(only 2nd layer)
                                                                 0= off, 1= conjugate(), 2= -1*conjugate() */
#else /* Word 0 - Little Endian */
        uint64_t txd_postprocess_1     : 2;  /**< [  1:  0](R/W) FDE single layer(only 2nd layer)
                                                                 0= off, 1= conjugate(), 2= -1*conjugate() */
        uint64_t txd_preprocess_1      : 2;  /**< [  3:  2](R/W) (Extra ant.) y_data - 0= off, 1= conjugate(), 2= -1*conjugate() */
        uint64_t txd_transform_map_1_r2r3_t5 : 4;/**< [  7:  4](R/W) R2/R3 tone index to map tone 5 */
        uint64_t txd_transform_map_1_r0r1_t5 : 4;/**< [ 11:  8](R/W) R0/R1 tone index to map tone 5 */
        uint64_t txd_transform_map_1_r2r3_t4 : 4;/**< [ 15: 12](R/W) R2/R3 tone index to map tone 4 */
        uint64_t txd_transform_map_1_r0r1_t4 : 4;/**< [ 19: 16](R/W) R0/R1 tone index to map tone 4 */
        uint64_t txd_transform_map_1_r2r3_t3 : 4;/**< [ 23: 20](R/W) R2/R3 tone index to map tone 3 */
        uint64_t txd_transform_map_1_r0r1_t3 : 4;/**< [ 27: 24](R/W) R0/R1 tone index to map tone 3 */
        uint64_t txd_transform_map_1_r2r3_t2 : 4;/**< [ 31: 28](R/W) R2/R3 tone index to map tone 2 */
        uint64_t txd_transform_map_1_r0r1_t2 : 4;/**< [ 35: 32](R/W) R0/R1 tone index to map tone 2 */
        uint64_t txd_transform_map_1_r2r3_t1 : 4;/**< [ 39: 36](R/W) R2/R3 tone index to map tone 1 */
        uint64_t txd_transform_map_1_r0r1_t1 : 4;/**< [ 43: 40](R/W) R0/R1 tone index to map tone 1 */
        uint64_t txd_transform_map_1_r2r3_t0 : 4;/**< [ 47: 44](R/W) R2/R3 tone index to map tone 0 */
        uint64_t txd_transform_map_1_r0r1_t0 : 4;/**< [ 51: 48](R/W) R0/R1 tone index to map tone 0 */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_fdeqx_sxbc_map_1_s cn; */
};
typedef union cavm_fdeqx_sxbc_map_1 cavm_fdeqx_sxbc_map_1_t;

static inline uint64_t CAVM_FDEQX_SXBC_MAP_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_FDEQX_SXBC_MAP_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043202038ll + 0x800000ll * ((a) & 0x1);
    __cavm_csr_fatal("FDEQX_SXBC_MAP_1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_FDEQX_SXBC_MAP_1(a) cavm_fdeqx_sxbc_map_1_t
#define bustype_CAVM_FDEQX_SXBC_MAP_1(a) CSR_TYPE_RSL
#define basename_CAVM_FDEQX_SXBC_MAP_1(a) "FDEQX_SXBC_MAP_1"
#define busnum_CAVM_FDEQX_SXBC_MAP_1(a) (a)
#define arguments_CAVM_FDEQX_SXBC_MAP_1(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_FDEQ_H__ */
