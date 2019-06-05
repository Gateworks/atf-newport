#ifndef __CAVM_CSRS_EDEC_H__
#define __CAVM_CSRS_EDEC_H__
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
 * OcteonTX EDEC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration edec_comp_meth_e
 *
 * INTERNAL: EDEC Compression Method Enumeration
 *
 * Enumerates compression method. See also ORAN v02.01 Table 6.4.
 * Internal:
 * FIXME remove, use ECPRI_COMP_METH_E instead.
 */
#define CAVM_EDEC_COMP_METH_E_FBFPC (1)
#define CAVM_EDEC_COMP_METH_E_FMC (4)
#define CAVM_EDEC_COMP_METH_E_FULC (3)
#define CAVM_EDEC_COMP_METH_E_FUNC (0)

/**
 * Structure edec_lut_csr0_s
 *
 * EDEC LUT CSR0 Structure
 * This defines the fields of the first (of 4) 64-bit structures used to read and write the EDEC LUT.
 */
union cavm_edec_lut_csr0_s
{
    uint64_t u;
    struct cavm_edec_lut_csr0_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t num_symbols_inv20     : 20; /**< [ 60: 41] Constant software needs to provide: 2**20 / NUM_SYMBOLS. */
        uint64_t next_buf_idx          : 8;  /**< [ 40: 33] Next available buffer index. This field is managed by hardware. */
        uint64_t fix_udcomp_hdr        : 8;  /**< [ 32: 25] Same as udCompHdr = {udIQWidth (3:0), udCompMeth (3:0)} in ORAN spec. */
        uint64_t fix_mode_en           : 1;  /**< [ 24: 24] Enable dynamic computing.
                                                                 0: Use Fixed Decompression method (described by [FIX_UDCOMP_HDR]).
                                                                 1: Use Dynamic Decompression method. */
        uint64_t num_slot_exp_1ms      : 2;  /**< [ 23: 22] Log base two of the number of slots per 1 ms.
                                                                 LTE: 0 or 1 (for 1 or 2 slots).
                                                                 5G-NR: 0, 1, 2, or 3 (for 1, 2, 4, or 8 slots). */
        uint64_t num_sym_per_slot      : 6;  /**< [ 21: 16] Number of symbols per slot minus 1. */
        uint64_t num_buffers           : 8;  /**< [ 15:  8] Number of buffers minus 1. */
        uint64_t num_symbols           : 6;  /**< [  7:  2] Number of symbols minus 1. */
        uint64_t en_addr_calc          : 1;  /**< [  1:  1] Address calculation type.
                                                                 0 = Based on sequence ID.
                                                                 1 = Based on address calculation.

                                                                 When sequence ID is used, the header and PRB (data) address calculations
                                                                 are solely based on the base addresses, buffer sizes and buffer indexes
                                                                 specified for each FLOW_ID in the LUT. For more details, consult the
                                                                 "Header Circular Buffer Address Calculation" and "Data (PRBs) Circular Buffer
                                                                 Address Calculation - EN_ADDR_CALC = 0" sections of the technical specification
                                                                 document.

                                                                 When the address calculation is used, the PRB (data) address calculation
                                                                 takes into account the subfrm_id, slot_id, and symbol_id from each timing header,
                                                                 symInc and rb from the section header
                                                                 as well as num_slot_exp_1ms, num_sym_per_slot, num_symbols, num_buffers,
                                                                 next_buf_id specified for each FLOW_ID in the LUT. The header address calculation
                                                                 remains the same as for the sequence ID case.
                                                                 For more details, consult the "Data (PRBs) Circular Buffer Address Calculation
                                                                 - EN_ADDR_CALC = 1" section of the technical specification document. */
        uint64_t flow_en               : 1;  /**< [  0:  0] Flow enable.
                                                                 0 = Flow is disabled.
                                                                 1 = Flow is enabled. */
#else /* Word 0 - Little Endian */
        uint64_t flow_en               : 1;  /**< [  0:  0] Flow enable.
                                                                 0 = Flow is disabled.
                                                                 1 = Flow is enabled. */
        uint64_t en_addr_calc          : 1;  /**< [  1:  1] Address calculation type.
                                                                 0 = Based on sequence ID.
                                                                 1 = Based on address calculation.

                                                                 When sequence ID is used, the header and PRB (data) address calculations
                                                                 are solely based on the base addresses, buffer sizes and buffer indexes
                                                                 specified for each FLOW_ID in the LUT. For more details, consult the
                                                                 "Header Circular Buffer Address Calculation" and "Data (PRBs) Circular Buffer
                                                                 Address Calculation - EN_ADDR_CALC = 0" sections of the technical specification
                                                                 document.

                                                                 When the address calculation is used, the PRB (data) address calculation
                                                                 takes into account the subfrm_id, slot_id, and symbol_id from each timing header,
                                                                 symInc and rb from the section header
                                                                 as well as num_slot_exp_1ms, num_sym_per_slot, num_symbols, num_buffers,
                                                                 next_buf_id specified for each FLOW_ID in the LUT. The header address calculation
                                                                 remains the same as for the sequence ID case.
                                                                 For more details, consult the "Data (PRBs) Circular Buffer Address Calculation
                                                                 - EN_ADDR_CALC = 1" section of the technical specification document. */
        uint64_t num_symbols           : 6;  /**< [  7:  2] Number of symbols minus 1. */
        uint64_t num_buffers           : 8;  /**< [ 15:  8] Number of buffers minus 1. */
        uint64_t num_sym_per_slot      : 6;  /**< [ 21: 16] Number of symbols per slot minus 1. */
        uint64_t num_slot_exp_1ms      : 2;  /**< [ 23: 22] Log base two of the number of slots per 1 ms.
                                                                 LTE: 0 or 1 (for 1 or 2 slots).
                                                                 5G-NR: 0, 1, 2, or 3 (for 1, 2, 4, or 8 slots). */
        uint64_t fix_mode_en           : 1;  /**< [ 24: 24] Enable dynamic computing.
                                                                 0: Use Fixed Decompression method (described by [FIX_UDCOMP_HDR]).
                                                                 1: Use Dynamic Decompression method. */
        uint64_t fix_udcomp_hdr        : 8;  /**< [ 32: 25] Same as udCompHdr = {udIQWidth (3:0), udCompMeth (3:0)} in ORAN spec. */
        uint64_t next_buf_idx          : 8;  /**< [ 40: 33] Next available buffer index. This field is managed by hardware. */
        uint64_t num_symbols_inv20     : 20; /**< [ 60: 41] Constant software needs to provide: 2**20 / NUM_SYMBOLS. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_csr0_s_s cn; */
};

/**
 * Structure edec_lut_csr1_s
 *
 * EDEC LUT CSR1 Structure
 * This defines the fields of the second (of 4) 64-bit structures used to read and write the EDEC LUT.
 */
union cavm_edec_lut_csr1_s
{
    uint64_t u;
    struct cavm_edec_lut_csr1_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t data_write_hp         : 1;  /**< [ 62: 62] Send data write command with high priority when set. */
        uint64_t data_write_cmd_type   : 2;  /**< [ 61: 60] Command to send when writing data to GHB.
                                                                 Enumerated by chip_mhbw_pkg::MHBW_PNB_WR_CMD_E_t. */
        uint64_t num_tot_prb           : 10; /**< [ 59: 50] Size of data buffers, expressed as number of 16-byte words minus 1. */
        uint64_t data_target_mem       : 1;  /**< [ 49: 49] Specifies the target memory for the address.
                                                                 Enumerated by MHBW_TMEM_SEL_E. */
        uint64_t base_addr_data        : 49; /**< [ 48:  0] 49b 16-byte aligned base address for data. */
#else /* Word 0 - Little Endian */
        uint64_t base_addr_data        : 49; /**< [ 48:  0] 49b 16-byte aligned base address for data. */
        uint64_t data_target_mem       : 1;  /**< [ 49: 49] Specifies the target memory for the address.
                                                                 Enumerated by MHBW_TMEM_SEL_E. */
        uint64_t num_tot_prb           : 10; /**< [ 59: 50] Size of data buffers, expressed as number of 16-byte words minus 1. */
        uint64_t data_write_cmd_type   : 2;  /**< [ 61: 60] Command to send when writing data to GHB.
                                                                 Enumerated by chip_mhbw_pkg::MHBW_PNB_WR_CMD_E_t. */
        uint64_t data_write_hp         : 1;  /**< [ 62: 62] Send data write command with high priority when set. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_csr1_s_s cn; */
};

/**
 * Structure edec_lut_csr2_s
 *
 * EDEC LUT CSR2 Structure
 * This defines the fields of the third (of 4) 64-bit structures used to read and write the EDEC LUT.
 */
union cavm_edec_lut_csr2_s
{
    uint64_t u;
    struct cavm_edec_lut_csr2_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t hdr_write_hp          : 1;  /**< [ 62: 62] Send header write command with high priority when set. */
        uint64_t hdr_read_cmd_type     : 2;  /**< [ 61: 60] Command to put in RD_RMA_CFG_WORD0 (see eDEC technical specification).
                                                                 Enumerated by chip_mhbw_pkg::MHBW_PNB_RD_CMD_E_t. */
        uint64_t hdr_write_cmd_type    : 2;  /**< [ 59: 58] Command to send when writing headers to GHB.
                                                                 Enumerated by chip_mhbw_pkg::MHBW_PNB_WR_CMD_E_t. */
        uint64_t hdr_buffer_size       : 8;  /**< [ 57: 50] Size of header buffers in 16 byte words minus 1. */
        uint64_t hdr_target_mem        : 1;  /**< [ 49: 49] Specifies the target memory for the address.
                                                                 Enumerated by MHBW_TMEM_SEL_E. */
        uint64_t base_addr_hdr         : 49; /**< [ 48:  0] 49b 16-byte aligned base address for headers. */
#else /* Word 0 - Little Endian */
        uint64_t base_addr_hdr         : 49; /**< [ 48:  0] 49b 16-byte aligned base address for headers. */
        uint64_t hdr_target_mem        : 1;  /**< [ 49: 49] Specifies the target memory for the address.
                                                                 Enumerated by MHBW_TMEM_SEL_E. */
        uint64_t hdr_buffer_size       : 8;  /**< [ 57: 50] Size of header buffers in 16 byte words minus 1. */
        uint64_t hdr_write_cmd_type    : 2;  /**< [ 59: 58] Command to send when writing headers to GHB.
                                                                 Enumerated by chip_mhbw_pkg::MHBW_PNB_WR_CMD_E_t. */
        uint64_t hdr_read_cmd_type     : 2;  /**< [ 61: 60] Command to put in RD_RMA_CFG_WORD0 (see eDEC technical specification).
                                                                 Enumerated by chip_mhbw_pkg::MHBW_PNB_RD_CMD_E_t. */
        uint64_t hdr_write_hp          : 1;  /**< [ 62: 62] Send header write command with high priority when set. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_csr2_s_s cn; */
};

/**
 * Structure edec_lut_csr3_s
 *
 * EDEC LUT CSR3 Structure
 * This defines the fields of the fourth (of 4) 64-bit structures used to read and write the EDEC LUT.
 */
union cavm_edec_lut_csr3_s
{
    uint64_t u;
    struct cavm_edec_lut_csr3_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t psm_job_cmd_word0     : 64; /**< [ 63:  0] PSM job command word 0. */
#else /* Word 0 - Little Endian */
        uint64_t psm_job_cmd_word0     : 64; /**< [ 63:  0] PSM job command word 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_csr3_s_s cn; */
};

/**
 * Register (RSL) edec_bp_test0
 *
 * INTERNAL: EDEC Back Pressure Test 0 Register
 *
 * Internal:
 * Back Pressure
 */
union cavm_edec_bp_test0
{
    uint64_t u;
    struct cavm_edec_bp_test0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Prevents arb from granting.
                                                                 \<63\> = unused.
                                                                 \<62\> = De-compressed PRBs FIFO.
                                                                 \<61\> = De-mpressed headers FIFO.
                                                                 \<60\> = Ghb_wr_port. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                 \<23:22\> = unused.
                                                                 \<21:20\> = De-compressed PRBs FIFO.
                                                                 \<19:18\> = De-compressed headers FIFO.
                                                                 \<17:16\> = Ghbw_wr_port. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                 \<23:22\> = unused.
                                                                 \<21:20\> = De-compressed PRBs FIFO.
                                                                 \<19:18\> = De-compressed headers FIFO.
                                                                 \<17:16\> = Ghbw_wr_port. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Prevents arb from granting.
                                                                 \<63\> = unused.
                                                                 \<62\> = De-compressed PRBs FIFO.
                                                                 \<61\> = De-mpressed headers FIFO.
                                                                 \<60\> = Ghb_wr_port. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_bp_test0_s cn; */
};
typedef union cavm_edec_bp_test0 cavm_edec_bp_test0_t;

#define CAVM_EDEC_BP_TEST0 CAVM_EDEC_BP_TEST0_FUNC()
static inline uint64_t CAVM_EDEC_BP_TEST0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_BP_TEST0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043401000ll;
    __cavm_csr_fatal("EDEC_BP_TEST0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_BP_TEST0 cavm_edec_bp_test0_t
#define bustype_CAVM_EDEC_BP_TEST0 CSR_TYPE_RSL
#define basename_CAVM_EDEC_BP_TEST0 "EDEC_BP_TEST0"
#define busnum_CAVM_EDEC_BP_TEST0 0
#define arguments_CAVM_EDEC_BP_TEST0 -1,-1,-1,-1

/**
 * Register (RSL) edec_bp_test1
 *
 * INTERNAL: EDEC Back Pressure Test 1 Register
 *
 * Internal:
 * Back pressure to JCA and DMA paths
 */
union cavm_edec_bp_test1
{
    uint64_t u;
    struct cavm_edec_bp_test1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Prevents arb from granting.
                                                                 \<63\> = Unused.
                                                                 \<62\> = Unused.
                                                                 \<61\> = Unused.
                                                                 \<60\> = Header + PRB input buffer. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                 \<23:22\> = Unused.
                                                                 \<21:20\> = Unused.
                                                                 \<19:18\> = Unused.
                                                                 \<17:16\> = Header + PRB input buffer. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                 \<23:22\> = Unused.
                                                                 \<21:20\> = Unused.
                                                                 \<19:18\> = Unused.
                                                                 \<17:16\> = Header + PRB input buffer. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Prevents arb from granting.
                                                                 \<63\> = Unused.
                                                                 \<62\> = Unused.
                                                                 \<61\> = Unused.
                                                                 \<60\> = Header + PRB input buffer. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_bp_test1_s cn; */
};
typedef union cavm_edec_bp_test1 cavm_edec_bp_test1_t;

#define CAVM_EDEC_BP_TEST1 CAVM_EDEC_BP_TEST1_FUNC()
static inline uint64_t CAVM_EDEC_BP_TEST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_BP_TEST1_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043401008ll;
    __cavm_csr_fatal("EDEC_BP_TEST1", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_BP_TEST1 cavm_edec_bp_test1_t
#define bustype_CAVM_EDEC_BP_TEST1 CSR_TYPE_RSL
#define basename_CAVM_EDEC_BP_TEST1 "EDEC_BP_TEST1"
#define busnum_CAVM_EDEC_BP_TEST1 0
#define arguments_CAVM_EDEC_BP_TEST1 -1,-1,-1,-1

/**
 * Register (RSL) edec_config
 *
 * INTERNAL: EDEC CONFIG Register
 */
union cavm_edec_config
{
    uint64_t u;
    struct cavm_edec_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t jobtag_max            : 16; /**< [ 23:  8](R/W) On LUT initialization or modification, for each initialized or modified FLOW_ID,
                                                                 the internal JOBTAG[FLOW_ID] counter is set to LUT[FLOW_ID].psm_job_cmd_word0.jobtag.

                                                                 For each processed job, JOBTAG[FLOW_ID] is incremented until it reaches JOBTAG_MAX.

                                                                 On subsequent job with same FLOW_ID, JOBTAG[FLOW_ID] resets to
                                                                 LUT[FLOW_ID].psm_job_cmd_word0.jobtag. */
        uint64_t reserved_5_7          : 3;
        uint64_t force_cond_clk_en     : 1;  /**< [  4:  4](R/W) Force the conditional clocks active within the block. For diagnostic use only. */
        uint64_t reserved_1_3          : 3;
        uint64_t comp_sign_ext         : 1;  /**< [  0:  0](R/W) If set, compressed I/Q with iqWidth \< 16 will be sign extended.
                                                                 If clear, compressed I/Q with iqWidth \< 16 will be padded with zeros. */
#else /* Word 0 - Little Endian */
        uint64_t comp_sign_ext         : 1;  /**< [  0:  0](R/W) If set, compressed I/Q with iqWidth \< 16 will be sign extended.
                                                                 If clear, compressed I/Q with iqWidth \< 16 will be padded with zeros. */
        uint64_t reserved_1_3          : 3;
        uint64_t force_cond_clk_en     : 1;  /**< [  4:  4](R/W) Force the conditional clocks active within the block. For diagnostic use only. */
        uint64_t reserved_5_7          : 3;
        uint64_t jobtag_max            : 16; /**< [ 23:  8](R/W) On LUT initialization or modification, for each initialized or modified FLOW_ID,
                                                                 the internal JOBTAG[FLOW_ID] counter is set to LUT[FLOW_ID].psm_job_cmd_word0.jobtag.

                                                                 For each processed job, JOBTAG[FLOW_ID] is incremented until it reaches JOBTAG_MAX.

                                                                 On subsequent job with same FLOW_ID, JOBTAG[FLOW_ID] resets to
                                                                 LUT[FLOW_ID].psm_job_cmd_word0.jobtag. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    struct cavm_edec_config_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t reserved_24_26        : 3;
        uint64_t jobtag_max            : 16; /**< [ 23:  8](R/W) On LUT initialization or modification, for each initialized or modified FLOW_ID,
                                                                 the internal JOBTAG[FLOW_ID] counter is set to LUT[FLOW_ID].psm_job_cmd_word0.jobtag.

                                                                 For each processed job, JOBTAG[FLOW_ID] is incremented until it reaches JOBTAG_MAX.

                                                                 On subsequent job with same FLOW_ID, JOBTAG[FLOW_ID] resets to
                                                                 LUT[FLOW_ID].psm_job_cmd_word0.jobtag. */
        uint64_t reserved_5_7          : 3;
        uint64_t force_cond_clk_en     : 1;  /**< [  4:  4](R/W) Force the conditional clocks active within the block. For diagnostic use only. */
        uint64_t reserved_1_3          : 3;
        uint64_t comp_sign_ext         : 1;  /**< [  0:  0](R/W) If set, compressed I/Q with iqWidth \< 16 will be sign extended.
                                                                 If clear, compressed I/Q with iqWidth \< 16 will be padded with zeros. */
#else /* Word 0 - Little Endian */
        uint64_t comp_sign_ext         : 1;  /**< [  0:  0](R/W) If set, compressed I/Q with iqWidth \< 16 will be sign extended.
                                                                 If clear, compressed I/Q with iqWidth \< 16 will be padded with zeros. */
        uint64_t reserved_1_3          : 3;
        uint64_t force_cond_clk_en     : 1;  /**< [  4:  4](R/W) Force the conditional clocks active within the block. For diagnostic use only. */
        uint64_t reserved_5_7          : 3;
        uint64_t jobtag_max            : 16; /**< [ 23:  8](R/W) On LUT initialization or modification, for each initialized or modified FLOW_ID,
                                                                 the internal JOBTAG[FLOW_ID] counter is set to LUT[FLOW_ID].psm_job_cmd_word0.jobtag.

                                                                 For each processed job, JOBTAG[FLOW_ID] is incremented until it reaches JOBTAG_MAX.

                                                                 On subsequent job with same FLOW_ID, JOBTAG[FLOW_ID] resets to
                                                                 LUT[FLOW_ID].psm_job_cmd_word0.jobtag. */
        uint64_t reserved_24_26        : 3;
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_edec_config cavm_edec_config_t;

#define CAVM_EDEC_CONFIG CAVM_EDEC_CONFIG_FUNC()
static inline uint64_t CAVM_EDEC_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_CONFIG_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400008ll;
    __cavm_csr_fatal("EDEC_CONFIG", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_CONFIG cavm_edec_config_t
#define bustype_CAVM_EDEC_CONFIG CSR_TYPE_RSL
#define basename_CAVM_EDEC_CONFIG "EDEC_CONFIG"
#define busnum_CAVM_EDEC_CONFIG 0
#define arguments_CAVM_EDEC_CONFIG -1,-1,-1,-1

/**
 * Register (RSL) edec_control
 *
 * EDEC Control Register
 */
union cavm_edec_control
{
    uint64_t u;
    struct cavm_edec_control_s
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
    /* struct cavm_edec_control_s cn; */
};
typedef union cavm_edec_control cavm_edec_control_t;

#define CAVM_EDEC_CONTROL CAVM_EDEC_CONTROL_FUNC()
static inline uint64_t CAVM_EDEC_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_CONTROL_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400000ll;
    __cavm_csr_fatal("EDEC_CONTROL", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_CONTROL cavm_edec_control_t
#define bustype_CAVM_EDEC_CONTROL CSR_TYPE_RSL
#define basename_CAVM_EDEC_CONTROL "EDEC_CONTROL"
#define busnum_CAVM_EDEC_CONTROL 0
#define arguments_CAVM_EDEC_CONTROL -1,-1,-1,-1

/**
 * Register (RSL) edec_eco
 *
 * INTERNAL: EDEC ECO Register
 */
union cavm_edec_eco
{
    uint64_t u;
    struct cavm_edec_eco_s
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
    /* struct cavm_edec_eco_s cn; */
};
typedef union cavm_edec_eco cavm_edec_eco_t;

#define CAVM_EDEC_ECO CAVM_EDEC_ECO_FUNC()
static inline uint64_t CAVM_EDEC_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_ECO_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043401300ll;
    __cavm_csr_fatal("EDEC_ECO", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_ECO cavm_edec_eco_t
#define bustype_CAVM_EDEC_ECO CSR_TYPE_RSL
#define basename_CAVM_EDEC_ECO "EDEC_ECO"
#define busnum_CAVM_EDEC_ECO 0
#define arguments_CAVM_EDEC_ECO -1,-1,-1,-1

/**
 * Register (RSL) edec_error_ena_w1c
 *
 * EDEC Interrupt Error Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_edec_error_ena_w1c
{
    uint64_t u;
    struct cavm_edec_error_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[WRRSP_FAT]. */
        uint64_t reserved_4_11         : 8;
        uint64_t block_floating_point_err : 1;/**< [  3:  3](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[BLOCK_FLOATING_POINT_ERR]. */
        uint64_t comb_iqwidth_compmeth_err : 1;/**< [  2:  2](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[COMB_IQWIDTH_COMPMETH_ERR]. */
        uint64_t iqwidth_err           : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[IQWIDTH_ERR]. */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[COMPMETH_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[COMPMETH_ERR]. */
        uint64_t iqwidth_err           : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[IQWIDTH_ERR]. */
        uint64_t comb_iqwidth_compmeth_err : 1;/**< [  2:  2](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[COMB_IQWIDTH_COMPMETH_ERR]. */
        uint64_t block_floating_point_err : 1;/**< [  3:  3](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[BLOCK_FLOATING_POINT_ERR]. */
        uint64_t reserved_4_11         : 8;
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[WRRSP_FAT]. */
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for EDEC_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_error_ena_w1c_s cn; */
};
typedef union cavm_edec_error_ena_w1c cavm_edec_error_ena_w1c_t;

#define CAVM_EDEC_ERROR_ENA_W1C CAVM_EDEC_ERROR_ENA_W1C_FUNC()
static inline uint64_t CAVM_EDEC_ERROR_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_ERROR_ENA_W1C_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400050ll;
    __cavm_csr_fatal("EDEC_ERROR_ENA_W1C", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_ERROR_ENA_W1C cavm_edec_error_ena_w1c_t
#define bustype_CAVM_EDEC_ERROR_ENA_W1C CSR_TYPE_RSL
#define basename_CAVM_EDEC_ERROR_ENA_W1C "EDEC_ERROR_ENA_W1C"
#define busnum_CAVM_EDEC_ERROR_ENA_W1C 0
#define arguments_CAVM_EDEC_ERROR_ENA_W1C -1,-1,-1,-1

/**
 * Register (RSL) edec_error_ena_w1s
 *
 * EDEC Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_edec_error_ena_w1s
{
    uint64_t u;
    struct cavm_edec_error_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[WRRSP_FAT]. */
        uint64_t reserved_4_11         : 8;
        uint64_t block_floating_point_err : 1;/**< [  3:  3](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[BLOCK_FLOATING_POINT_ERR]. */
        uint64_t comb_iqwidth_compmeth_err : 1;/**< [  2:  2](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[COMB_IQWIDTH_COMPMETH_ERR]. */
        uint64_t iqwidth_err           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[IQWIDTH_ERR]. */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[COMPMETH_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[COMPMETH_ERR]. */
        uint64_t iqwidth_err           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[IQWIDTH_ERR]. */
        uint64_t comb_iqwidth_compmeth_err : 1;/**< [  2:  2](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[COMB_IQWIDTH_COMPMETH_ERR]. */
        uint64_t block_floating_point_err : 1;/**< [  3:  3](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[BLOCK_FLOATING_POINT_ERR]. */
        uint64_t reserved_4_11         : 8;
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[WRRSP_FAT]. */
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for EDEC_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_error_ena_w1s_s cn; */
};
typedef union cavm_edec_error_ena_w1s cavm_edec_error_ena_w1s_t;

#define CAVM_EDEC_ERROR_ENA_W1S CAVM_EDEC_ERROR_ENA_W1S_FUNC()
static inline uint64_t CAVM_EDEC_ERROR_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_ERROR_ENA_W1S_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400048ll;
    __cavm_csr_fatal("EDEC_ERROR_ENA_W1S", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_ERROR_ENA_W1S cavm_edec_error_ena_w1s_t
#define bustype_CAVM_EDEC_ERROR_ENA_W1S CSR_TYPE_RSL
#define basename_CAVM_EDEC_ERROR_ENA_W1S "EDEC_ERROR_ENA_W1S"
#define busnum_CAVM_EDEC_ERROR_ENA_W1S 0
#define arguments_CAVM_EDEC_ERROR_ENA_W1S -1,-1,-1,-1

/**
 * Register (RSL) edec_error_enable0
 *
 * EDEC Error Enable Register 0
 * This register enables reporting the source of read DMA overflow/underflow errors.
 */
union cavm_edec_error_enable0
{
    uint64_t u;
    struct cavm_edec_error_enable0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t rp0_of_en             : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
#else /* Word 0 - Little Endian */
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_of_en             : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_error_enable0_s cn; */
};
typedef union cavm_edec_error_enable0 cavm_edec_error_enable0_t;

#define CAVM_EDEC_ERROR_ENABLE0 CAVM_EDEC_ERROR_ENABLE0_FUNC()
static inline uint64_t CAVM_EDEC_ERROR_ENABLE0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_ERROR_ENABLE0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400038ll;
    __cavm_csr_fatal("EDEC_ERROR_ENABLE0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_ERROR_ENABLE0 cavm_edec_error_enable0_t
#define bustype_CAVM_EDEC_ERROR_ENABLE0 CSR_TYPE_RSL
#define basename_CAVM_EDEC_ERROR_ENABLE0 "EDEC_ERROR_ENABLE0"
#define busnum_CAVM_EDEC_ERROR_ENABLE0 0
#define arguments_CAVM_EDEC_ERROR_ENABLE0 -1,-1,-1,-1

/**
 * Register (RSL) edec_error_int
 *
 * EDEC Error Interrupt Register
 * These registers record normal errors across the EDEC.
 * When an error occurs, EDEC sends  message to PSM.
 */
union cavm_edec_error_int
{
    uint64_t u;
    struct cavm_edec_error_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1C/H) Write response returned a non-fatal non-NXM error.
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1C/H) Write response returned a fatal non-NXM error. */
        uint64_t reserved_4_11         : 8;
        uint64_t block_floating_point_err : 1;/**< [  3:  3](R/W1C/H) iqWidth + exponent \> 16. */
        uint64_t comb_iqwidth_compmeth_err : 1;/**< [  2:  2](R/W1C/H) Combination of iqWidth and CompMeth fields is not supported (e.g. iqWidth==16 and
                                                                 CompMeth = Block Floating Point because 16 means not compressed). */
        uint64_t iqwidth_err           : 1;  /**< [  1:  1](R/W1C/H) iqWidth field is not supported (e.g. smaller than 6 for Block Floating Point). */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1C/H) CompMeth field is not supported (!=0,1). Encodings from O-RAN v01.00 pp 97
                                                                 Section 6.3.3.13 Table 6-4.

                                                                 \<pre\>
                                                                 Encoding | Method               | Supported | iQWidth range
                                                                 ---------+----------------------+-----------+--------------
                                                                    0     | No Compression       | Y         |      16
                                                                    1     | Block Floating Point | Y         |      6-15
                                                                    2     | Block Scaling        | N         |      ?
                                                                    3     | u-Law                | N         |      1-16
                                                                    4     | Modulation           | N         |      1-5
                                                                 \</pre\> */
#else /* Word 0 - Little Endian */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1C/H) CompMeth field is not supported (!=0,1). Encodings from O-RAN v01.00 pp 97
                                                                 Section 6.3.3.13 Table 6-4.

                                                                 \<pre\>
                                                                 Encoding | Method               | Supported | iQWidth range
                                                                 ---------+----------------------+-----------+--------------
                                                                    0     | No Compression       | Y         |      16
                                                                    1     | Block Floating Point | Y         |      6-15
                                                                    2     | Block Scaling        | N         |      ?
                                                                    3     | u-Law                | N         |      1-16
                                                                    4     | Modulation           | N         |      1-5
                                                                 \</pre\> */
        uint64_t iqwidth_err           : 1;  /**< [  1:  1](R/W1C/H) iqWidth field is not supported (e.g. smaller than 6 for Block Floating Point). */
        uint64_t comb_iqwidth_compmeth_err : 1;/**< [  2:  2](R/W1C/H) Combination of iqWidth and CompMeth fields is not supported (e.g. iqWidth==16 and
                                                                 CompMeth = Block Floating Point because 16 means not compressed). */
        uint64_t block_floating_point_err : 1;/**< [  3:  3](R/W1C/H) iqWidth + exponent \> 16. */
        uint64_t reserved_4_11         : 8;
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1C/H) Write response returned a fatal non-NXM error. */
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1C/H) Write response returned a non-fatal non-NXM error.
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_error_int_s cn; */
};
typedef union cavm_edec_error_int cavm_edec_error_int_t;

#define CAVM_EDEC_ERROR_INT CAVM_EDEC_ERROR_INT_FUNC()
static inline uint64_t CAVM_EDEC_ERROR_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_ERROR_INT_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400040ll;
    __cavm_csr_fatal("EDEC_ERROR_INT", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_ERROR_INT cavm_edec_error_int_t
#define bustype_CAVM_EDEC_ERROR_INT CSR_TYPE_RSL
#define basename_CAVM_EDEC_ERROR_INT "EDEC_ERROR_INT"
#define busnum_CAVM_EDEC_ERROR_INT 0
#define arguments_CAVM_EDEC_ERROR_INT -1,-1,-1,-1

/**
 * Register (RSL) edec_error_int_w1s
 *
 * EDEC Interrupt  Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_edec_error_int_w1s
{
    uint64_t u;
    struct cavm_edec_error_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets EDEC_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets EDEC_ERROR_INT[WRRSP_FAT]. */
        uint64_t reserved_4_11         : 8;
        uint64_t block_floating_point_err : 1;/**< [  3:  3](R/W1S/H) Reads or sets EDEC_ERROR_INT[BLOCK_FLOATING_POINT_ERR]. */
        uint64_t comb_iqwidth_compmeth_err : 1;/**< [  2:  2](R/W1S/H) Reads or sets EDEC_ERROR_INT[COMB_IQWIDTH_COMPMETH_ERR]. */
        uint64_t iqwidth_err           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets EDEC_ERROR_INT[IQWIDTH_ERR]. */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets EDEC_ERROR_INT[COMPMETH_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets EDEC_ERROR_INT[COMPMETH_ERR]. */
        uint64_t iqwidth_err           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets EDEC_ERROR_INT[IQWIDTH_ERR]. */
        uint64_t comb_iqwidth_compmeth_err : 1;/**< [  2:  2](R/W1S/H) Reads or sets EDEC_ERROR_INT[COMB_IQWIDTH_COMPMETH_ERR]. */
        uint64_t block_floating_point_err : 1;/**< [  3:  3](R/W1S/H) Reads or sets EDEC_ERROR_INT[BLOCK_FLOATING_POINT_ERR]. */
        uint64_t reserved_4_11         : 8;
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets EDEC_ERROR_INT[WRRSP_FAT]. */
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets EDEC_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_error_int_w1s_s cn; */
};
typedef union cavm_edec_error_int_w1s cavm_edec_error_int_w1s_t;

#define CAVM_EDEC_ERROR_INT_W1S CAVM_EDEC_ERROR_INT_W1S_FUNC()
static inline uint64_t CAVM_EDEC_ERROR_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_ERROR_INT_W1S_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400058ll;
    __cavm_csr_fatal("EDEC_ERROR_INT_W1S", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_ERROR_INT_W1S cavm_edec_error_int_w1s_t
#define bustype_CAVM_EDEC_ERROR_INT_W1S CSR_TYPE_RSL
#define basename_CAVM_EDEC_ERROR_INT_W1S "EDEC_ERROR_INT_W1S"
#define busnum_CAVM_EDEC_ERROR_INT_W1S 0
#define arguments_CAVM_EDEC_ERROR_INT_W1S -1,-1,-1,-1

/**
 * Register (RSL) edec_error_source0
 *
 * EDEC Error Source Register 0
 * This register reports the source of read DMA overflow/underflow errors.
 */
union cavm_edec_error_source0
{
    uint64_t u;
    struct cavm_edec_error_source0_s
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
    /* struct cavm_edec_error_source0_s cn; */
};
typedef union cavm_edec_error_source0 cavm_edec_error_source0_t;

#define CAVM_EDEC_ERROR_SOURCE0 CAVM_EDEC_ERROR_SOURCE0_FUNC()
static inline uint64_t CAVM_EDEC_ERROR_SOURCE0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_ERROR_SOURCE0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400030ll;
    __cavm_csr_fatal("EDEC_ERROR_SOURCE0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_ERROR_SOURCE0 cavm_edec_error_source0_t
#define bustype_CAVM_EDEC_ERROR_SOURCE0 CSR_TYPE_RSL
#define basename_CAVM_EDEC_ERROR_SOURCE0 "EDEC_ERROR_SOURCE0"
#define busnum_CAVM_EDEC_ERROR_SOURCE0 0
#define arguments_CAVM_EDEC_ERROR_SOURCE0 -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_access
 *
 * EDEC LUT Access Register
 * This register allows software to toggle between incremental LUT programming mode
 * where all LUT entries are written consecutively without specifying addresses,
 * and random R/W mode where data can be read/written from/to arbitrary FLOW_ID entries.
 */
union cavm_edec_lut_access
{
    uint64_t u;
    struct cavm_edec_lut_access_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t mode_change           : 1;  /**< [  1:  1](RO/H) Reserved.
                                                                 Internal:
                                                                 Set when EDEC_LUT_ACCESS[MODE] was changed by hardware */
        uint64_t mode                  : 1;  /**< [  0:  0](R/W/H) LUT access mode. Setting this bit:
                                                                 * Enables the incremental LUT programming mode.
                                                                 * Resets the internal counters FLOW_ID_IDX and FLOW_ID_WORD_IDX used
                                                                 by the incremental LUT programming mode.

                                                                 In incremental programming mode, writes to EDEC_LUT_INCR_WRITE[DATA]
                                                                 will populate the LUT and increment pointers till the table fills at
                                                                 which point this bit is reset by EDEC and subsequent writes to
                                                                 EDEC_LUT_INCR_WRITE[DATA] are ignored. In this mode, writes to all
                                                                 EDEC_LUT_RND_WRITE* registers are ignored and values in all
                                                                 EDEC_LUT_RND_READ* registers are undefined.

                                                                 Incremental programming can be aborted by setting [MODE]
                                                                 to 0 which will cause the pointers to reset but will leave LUT
                                                                 in the state it was after the last complete FLOW_ID write (each FLOW_ID
                                                                 entry contains four 64-bit words and is deemed completely written only
                                                                 when all four new words are written; aborted incomplete flow writes are
                                                                 not committed to LUT).

                                                                 When this bit is 0 (at end of incremental programming or from software write),
                                                                 the LUT is in random read/write access mode.

                                                                 In random R/W, to read a FLOW_ID entry software shall write the address to
                                                                 EDEC_LUT_RND_READ_CMD[FLOW_ID] and set EDEC_LUT_RND_READ_CMD[EN],
                                                                 (writing to EN will cause EDEC_LUT_RND_READ_CMD[VLD] to clear) and poll
                                                                 EDEC_LUT_RND_READ_CMD[VLD] till set. The valid FLOW_ID values can then
                                                                 be read from EDEC_LUT_RND_READ_DATA0 ... EDEC_LUT_RND_READ_DATA3.

                                                                 To write a FLOW_ID entry in random R/W mode, software needs to first write
                                                                 the 4 data entries to EDEC_LUT_RND_WRITE_DATA0 ... EDEC_LUT_RND_WRITE_DATA3
                                                                 then write EDEC_LUT_RND_WRITE_CMD[FLOW_ID] with the FLOW_ID, and set
                                                                 EDEC_LUT_RND_WRITE_CMD[EN] in the same CSR write (the writing of FLOW_ID
                                                                 and EN fields of register EDEC_LUT_RND_WRITE_CMD have to be part of the same
                                                                 CSR write).

                                                                 In random R/W, writes to EDEC_LUT_INCR_WRITE[DATA] are ignored. */
#else /* Word 0 - Little Endian */
        uint64_t mode                  : 1;  /**< [  0:  0](R/W/H) LUT access mode. Setting this bit:
                                                                 * Enables the incremental LUT programming mode.
                                                                 * Resets the internal counters FLOW_ID_IDX and FLOW_ID_WORD_IDX used
                                                                 by the incremental LUT programming mode.

                                                                 In incremental programming mode, writes to EDEC_LUT_INCR_WRITE[DATA]
                                                                 will populate the LUT and increment pointers till the table fills at
                                                                 which point this bit is reset by EDEC and subsequent writes to
                                                                 EDEC_LUT_INCR_WRITE[DATA] are ignored. In this mode, writes to all
                                                                 EDEC_LUT_RND_WRITE* registers are ignored and values in all
                                                                 EDEC_LUT_RND_READ* registers are undefined.

                                                                 Incremental programming can be aborted by setting [MODE]
                                                                 to 0 which will cause the pointers to reset but will leave LUT
                                                                 in the state it was after the last complete FLOW_ID write (each FLOW_ID
                                                                 entry contains four 64-bit words and is deemed completely written only
                                                                 when all four new words are written; aborted incomplete flow writes are
                                                                 not committed to LUT).

                                                                 When this bit is 0 (at end of incremental programming or from software write),
                                                                 the LUT is in random read/write access mode.

                                                                 In random R/W, to read a FLOW_ID entry software shall write the address to
                                                                 EDEC_LUT_RND_READ_CMD[FLOW_ID] and set EDEC_LUT_RND_READ_CMD[EN],
                                                                 (writing to EN will cause EDEC_LUT_RND_READ_CMD[VLD] to clear) and poll
                                                                 EDEC_LUT_RND_READ_CMD[VLD] till set. The valid FLOW_ID values can then
                                                                 be read from EDEC_LUT_RND_READ_DATA0 ... EDEC_LUT_RND_READ_DATA3.

                                                                 To write a FLOW_ID entry in random R/W mode, software needs to first write
                                                                 the 4 data entries to EDEC_LUT_RND_WRITE_DATA0 ... EDEC_LUT_RND_WRITE_DATA3
                                                                 then write EDEC_LUT_RND_WRITE_CMD[FLOW_ID] with the FLOW_ID, and set
                                                                 EDEC_LUT_RND_WRITE_CMD[EN] in the same CSR write (the writing of FLOW_ID
                                                                 and EN fields of register EDEC_LUT_RND_WRITE_CMD have to be part of the same
                                                                 CSR write).

                                                                 In random R/W, writes to EDEC_LUT_INCR_WRITE[DATA] are ignored. */
        uint64_t mode_change           : 1;  /**< [  1:  1](RO/H) Reserved.
                                                                 Internal:
                                                                 Set when EDEC_LUT_ACCESS[MODE] was changed by hardware */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_access_s cn; */
};
typedef union cavm_edec_lut_access cavm_edec_lut_access_t;

#define CAVM_EDEC_LUT_ACCESS CAVM_EDEC_LUT_ACCESS_FUNC()
static inline uint64_t CAVM_EDEC_LUT_ACCESS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_ACCESS_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400100ll;
    __cavm_csr_fatal("EDEC_LUT_ACCESS", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_ACCESS cavm_edec_lut_access_t
#define bustype_CAVM_EDEC_LUT_ACCESS CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_ACCESS "EDEC_LUT_ACCESS"
#define busnum_CAVM_EDEC_LUT_ACCESS 0
#define arguments_CAVM_EDEC_LUT_ACCESS -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_incr_write
 *
 * EDEC LUT Incremental Data Write Register
 * Register used for writing LUT data.
 */
union cavm_edec_lut_incr_write
{
    uint64_t u;
    struct cavm_edec_lut_incr_write_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](WO) Value written to LUT in incremental programming mode.
                                                                 Formatted according to EDEC_LUT_CSR0_S, EDEC_LUT_CSR1_S, EDEC_LUT_CSR2_S
                                                                 or EDEC_LUT_CSR3_S depending on the
                                                                 the number of writes to this register since writing
                                                                 EDEC_LUT_ACCESS[MODE]=1, modulo 4.

                                                                 See also EDEC_LUT_ACCESS[MODE]. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](WO) Value written to LUT in incremental programming mode.
                                                                 Formatted according to EDEC_LUT_CSR0_S, EDEC_LUT_CSR1_S, EDEC_LUT_CSR2_S
                                                                 or EDEC_LUT_CSR3_S depending on the
                                                                 the number of writes to this register since writing
                                                                 EDEC_LUT_ACCESS[MODE]=1, modulo 4.

                                                                 See also EDEC_LUT_ACCESS[MODE]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_incr_write_s cn; */
};
typedef union cavm_edec_lut_incr_write cavm_edec_lut_incr_write_t;

#define CAVM_EDEC_LUT_INCR_WRITE CAVM_EDEC_LUT_INCR_WRITE_FUNC()
static inline uint64_t CAVM_EDEC_LUT_INCR_WRITE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_INCR_WRITE_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400108ll;
    __cavm_csr_fatal("EDEC_LUT_INCR_WRITE", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_INCR_WRITE cavm_edec_lut_incr_write_t
#define bustype_CAVM_EDEC_LUT_INCR_WRITE CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_INCR_WRITE "EDEC_LUT_INCR_WRITE"
#define busnum_CAVM_EDEC_LUT_INCR_WRITE 0
#define arguments_CAVM_EDEC_LUT_INCR_WRITE -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_read_cmd
 *
 * EDEC LUT Random Read Command Register
 * Register used for randomly reading LUT data.
 */
union cavm_edec_lut_rnd_read_cmd
{
    uint64_t u;
    struct cavm_edec_lut_rnd_read_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t flow_id               : 10; /**< [ 11:  2](R/W) LUT access FLOW_ID. See also EDEC_LUT_ACCESS[MODE]. */
        uint64_t vld                   : 1;  /**< [  1:  1](RO/H) LUT read entry is valid when set.
                                                                 See also EDEC_LUT_ACCESS[MODE]. */
        uint64_t en                    : 1;  /**< [  0:  0](WO) Causes hardware to look-up LUT at EDEC_LUT_RND_READ_CMD[FLOW_ID] */
#else /* Word 0 - Little Endian */
        uint64_t en                    : 1;  /**< [  0:  0](WO) Causes hardware to look-up LUT at EDEC_LUT_RND_READ_CMD[FLOW_ID] */
        uint64_t vld                   : 1;  /**< [  1:  1](RO/H) LUT read entry is valid when set.
                                                                 See also EDEC_LUT_ACCESS[MODE]. */
        uint64_t flow_id               : 10; /**< [ 11:  2](R/W) LUT access FLOW_ID. See also EDEC_LUT_ACCESS[MODE]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_read_cmd_s cn; */
};
typedef union cavm_edec_lut_rnd_read_cmd cavm_edec_lut_rnd_read_cmd_t;

#define CAVM_EDEC_LUT_RND_READ_CMD CAVM_EDEC_LUT_RND_READ_CMD_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_READ_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_READ_CMD_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400110ll;
    __cavm_csr_fatal("EDEC_LUT_RND_READ_CMD", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_READ_CMD cavm_edec_lut_rnd_read_cmd_t
#define bustype_CAVM_EDEC_LUT_RND_READ_CMD CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_READ_CMD "EDEC_LUT_RND_READ_CMD"
#define busnum_CAVM_EDEC_LUT_RND_READ_CMD 0
#define arguments_CAVM_EDEC_LUT_RND_READ_CMD -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_read_data0
 *
 * EDEC LUT Random Read Data Register0
 * Register used for randomly reading LUT data.
 */
union cavm_edec_lut_rnd_read_data0
{
    uint64_t u;
    struct cavm_edec_lut_rnd_read_data0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO/H) Value read from LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR0_S. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO/H) Value read from LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR0_S. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_read_data0_s cn; */
};
typedef union cavm_edec_lut_rnd_read_data0 cavm_edec_lut_rnd_read_data0_t;

#define CAVM_EDEC_LUT_RND_READ_DATA0 CAVM_EDEC_LUT_RND_READ_DATA0_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_READ_DATA0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_READ_DATA0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400118ll;
    __cavm_csr_fatal("EDEC_LUT_RND_READ_DATA0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_READ_DATA0 cavm_edec_lut_rnd_read_data0_t
#define bustype_CAVM_EDEC_LUT_RND_READ_DATA0 CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_READ_DATA0 "EDEC_LUT_RND_READ_DATA0"
#define busnum_CAVM_EDEC_LUT_RND_READ_DATA0 0
#define arguments_CAVM_EDEC_LUT_RND_READ_DATA0 -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_read_data1
 *
 * EDEC LUT Random Read Data Register1
 * Register used for randomly reading LUT data.
 */
union cavm_edec_lut_rnd_read_data1
{
    uint64_t u;
    struct cavm_edec_lut_rnd_read_data1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO/H) Value read from LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR1_S. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO/H) Value read from LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR1_S. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_read_data1_s cn; */
};
typedef union cavm_edec_lut_rnd_read_data1 cavm_edec_lut_rnd_read_data1_t;

#define CAVM_EDEC_LUT_RND_READ_DATA1 CAVM_EDEC_LUT_RND_READ_DATA1_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_READ_DATA1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_READ_DATA1_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400120ll;
    __cavm_csr_fatal("EDEC_LUT_RND_READ_DATA1", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_READ_DATA1 cavm_edec_lut_rnd_read_data1_t
#define bustype_CAVM_EDEC_LUT_RND_READ_DATA1 CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_READ_DATA1 "EDEC_LUT_RND_READ_DATA1"
#define busnum_CAVM_EDEC_LUT_RND_READ_DATA1 0
#define arguments_CAVM_EDEC_LUT_RND_READ_DATA1 -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_read_data2
 *
 * EDEC LUT Random Read Data Register2
 * Register used for randomly reading LUT data.
 */
union cavm_edec_lut_rnd_read_data2
{
    uint64_t u;
    struct cavm_edec_lut_rnd_read_data2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO/H) Value read from LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR2_S. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO/H) Value read from LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR2_S. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_read_data2_s cn; */
};
typedef union cavm_edec_lut_rnd_read_data2 cavm_edec_lut_rnd_read_data2_t;

#define CAVM_EDEC_LUT_RND_READ_DATA2 CAVM_EDEC_LUT_RND_READ_DATA2_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_READ_DATA2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_READ_DATA2_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400128ll;
    __cavm_csr_fatal("EDEC_LUT_RND_READ_DATA2", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_READ_DATA2 cavm_edec_lut_rnd_read_data2_t
#define bustype_CAVM_EDEC_LUT_RND_READ_DATA2 CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_READ_DATA2 "EDEC_LUT_RND_READ_DATA2"
#define busnum_CAVM_EDEC_LUT_RND_READ_DATA2 0
#define arguments_CAVM_EDEC_LUT_RND_READ_DATA2 -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_read_data3
 *
 * EDEC LUT Random Read Data Register3
 * Register used for randomly reading LUT data.
 */
union cavm_edec_lut_rnd_read_data3
{
    uint64_t u;
    struct cavm_edec_lut_rnd_read_data3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO/H) Value read from LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR3_S. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](RO/H) Value read from LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR3_S. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_read_data3_s cn; */
};
typedef union cavm_edec_lut_rnd_read_data3 cavm_edec_lut_rnd_read_data3_t;

#define CAVM_EDEC_LUT_RND_READ_DATA3 CAVM_EDEC_LUT_RND_READ_DATA3_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_READ_DATA3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_READ_DATA3_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400130ll;
    __cavm_csr_fatal("EDEC_LUT_RND_READ_DATA3", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_READ_DATA3 cavm_edec_lut_rnd_read_data3_t
#define bustype_CAVM_EDEC_LUT_RND_READ_DATA3 CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_READ_DATA3 "EDEC_LUT_RND_READ_DATA3"
#define busnum_CAVM_EDEC_LUT_RND_READ_DATA3 0
#define arguments_CAVM_EDEC_LUT_RND_READ_DATA3 -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_write_cmd
 *
 * EDEC LUT Random Write Command Register
 * Register used for randomly writing LUT data.
 */
union cavm_edec_lut_rnd_write_cmd
{
    uint64_t u;
    struct cavm_edec_lut_rnd_write_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t flow_id               : 10; /**< [ 10:  1](R/W) LUT access FLOW_ID. See also EDEC_LUT_ACCESS[MODE]. */
        uint64_t en                    : 1;  /**< [  0:  0](WO) Causes hardware to write LUT at EDEC_LUT_RND_READ_CMD[FLOW_ID] with
                                                                 values in EDEC_LUT_RND_WRITE_DATA0 ... EDEC_LUT_RND_WRITE_DATA3.
                                                                 See also EDEC_LUT_ACCESS[MODE]. */
#else /* Word 0 - Little Endian */
        uint64_t en                    : 1;  /**< [  0:  0](WO) Causes hardware to write LUT at EDEC_LUT_RND_READ_CMD[FLOW_ID] with
                                                                 values in EDEC_LUT_RND_WRITE_DATA0 ... EDEC_LUT_RND_WRITE_DATA3.
                                                                 See also EDEC_LUT_ACCESS[MODE]. */
        uint64_t flow_id               : 10; /**< [ 10:  1](R/W) LUT access FLOW_ID. See also EDEC_LUT_ACCESS[MODE]. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_write_cmd_s cn; */
};
typedef union cavm_edec_lut_rnd_write_cmd cavm_edec_lut_rnd_write_cmd_t;

#define CAVM_EDEC_LUT_RND_WRITE_CMD CAVM_EDEC_LUT_RND_WRITE_CMD_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_CMD_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400138ll;
    __cavm_csr_fatal("EDEC_LUT_RND_WRITE_CMD", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_WRITE_CMD cavm_edec_lut_rnd_write_cmd_t
#define bustype_CAVM_EDEC_LUT_RND_WRITE_CMD CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_WRITE_CMD "EDEC_LUT_RND_WRITE_CMD"
#define busnum_CAVM_EDEC_LUT_RND_WRITE_CMD 0
#define arguments_CAVM_EDEC_LUT_RND_WRITE_CMD -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_write_data0
 *
 * EDEC LUT Random Write Data Register0
 * Register used for randomly writing LUT data.
 */
union cavm_edec_lut_rnd_write_data0
{
    uint64_t u;
    struct cavm_edec_lut_rnd_write_data0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Value written to LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR0_S. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Value written to LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR0_S. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_write_data0_s cn; */
};
typedef union cavm_edec_lut_rnd_write_data0 cavm_edec_lut_rnd_write_data0_t;

#define CAVM_EDEC_LUT_RND_WRITE_DATA0 CAVM_EDEC_LUT_RND_WRITE_DATA0_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_DATA0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_DATA0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400140ll;
    __cavm_csr_fatal("EDEC_LUT_RND_WRITE_DATA0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_WRITE_DATA0 cavm_edec_lut_rnd_write_data0_t
#define bustype_CAVM_EDEC_LUT_RND_WRITE_DATA0 CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_WRITE_DATA0 "EDEC_LUT_RND_WRITE_DATA0"
#define busnum_CAVM_EDEC_LUT_RND_WRITE_DATA0 0
#define arguments_CAVM_EDEC_LUT_RND_WRITE_DATA0 -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_write_data1
 *
 * EDEC LUT Random Write Data Register1
 * Register used for randomly writing LUT data.
 */
union cavm_edec_lut_rnd_write_data1
{
    uint64_t u;
    struct cavm_edec_lut_rnd_write_data1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Value written to LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR1_S. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Value written to LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR1_S. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_write_data1_s cn; */
};
typedef union cavm_edec_lut_rnd_write_data1 cavm_edec_lut_rnd_write_data1_t;

#define CAVM_EDEC_LUT_RND_WRITE_DATA1 CAVM_EDEC_LUT_RND_WRITE_DATA1_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_DATA1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_DATA1_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400148ll;
    __cavm_csr_fatal("EDEC_LUT_RND_WRITE_DATA1", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_WRITE_DATA1 cavm_edec_lut_rnd_write_data1_t
#define bustype_CAVM_EDEC_LUT_RND_WRITE_DATA1 CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_WRITE_DATA1 "EDEC_LUT_RND_WRITE_DATA1"
#define busnum_CAVM_EDEC_LUT_RND_WRITE_DATA1 0
#define arguments_CAVM_EDEC_LUT_RND_WRITE_DATA1 -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_write_data2
 *
 * EDEC LUT Random Write Data Register2
 * Register used for randomly writing LUT data.
 */
union cavm_edec_lut_rnd_write_data2
{
    uint64_t u;
    struct cavm_edec_lut_rnd_write_data2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Value written to LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR2_S. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Value written to LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR2_S. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_write_data2_s cn; */
};
typedef union cavm_edec_lut_rnd_write_data2 cavm_edec_lut_rnd_write_data2_t;

#define CAVM_EDEC_LUT_RND_WRITE_DATA2 CAVM_EDEC_LUT_RND_WRITE_DATA2_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_DATA2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_DATA2_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400150ll;
    __cavm_csr_fatal("EDEC_LUT_RND_WRITE_DATA2", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_WRITE_DATA2 cavm_edec_lut_rnd_write_data2_t
#define bustype_CAVM_EDEC_LUT_RND_WRITE_DATA2 CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_WRITE_DATA2 "EDEC_LUT_RND_WRITE_DATA2"
#define busnum_CAVM_EDEC_LUT_RND_WRITE_DATA2 0
#define arguments_CAVM_EDEC_LUT_RND_WRITE_DATA2 -1,-1,-1,-1

/**
 * Register (RSL) edec_lut_rnd_write_data3
 *
 * EDEC LUT Random Write Data Register3
 * Register used for randomly writing LUT data.
 */
union cavm_edec_lut_rnd_write_data3
{
    uint64_t u;
    struct cavm_edec_lut_rnd_write_data3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Value written to LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR3_S. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Value written to LUT. See also EDEC_LUT_ACCESS[MODE].
                                                                 Formatted according to EDEC_LUT_CSR3_S. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_lut_rnd_write_data3_s cn; */
};
typedef union cavm_edec_lut_rnd_write_data3 cavm_edec_lut_rnd_write_data3_t;

#define CAVM_EDEC_LUT_RND_WRITE_DATA3 CAVM_EDEC_LUT_RND_WRITE_DATA3_FUNC()
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_DATA3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_LUT_RND_WRITE_DATA3_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400158ll;
    __cavm_csr_fatal("EDEC_LUT_RND_WRITE_DATA3", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_LUT_RND_WRITE_DATA3 cavm_edec_lut_rnd_write_data3_t
#define bustype_CAVM_EDEC_LUT_RND_WRITE_DATA3 CSR_TYPE_RSL
#define basename_CAVM_EDEC_LUT_RND_WRITE_DATA3 "EDEC_LUT_RND_WRITE_DATA3"
#define busnum_CAVM_EDEC_LUT_RND_WRITE_DATA3 0
#define arguments_CAVM_EDEC_LUT_RND_WRITE_DATA3 -1,-1,-1,-1

/**
 * Register (RSL) edec_scratch
 *
 * INTERNAL: Scratch Register
 *
 * Scratch register.
 */
union cavm_edec_scratch
{
    uint64_t u;
    struct cavm_edec_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_scratch_s cn; */
};
typedef union cavm_edec_scratch cavm_edec_scratch_t;

#define CAVM_EDEC_SCRATCH CAVM_EDEC_SCRATCH_FUNC()
static inline uint64_t CAVM_EDEC_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_SCRATCH_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043401200ll;
    __cavm_csr_fatal("EDEC_SCRATCH", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_SCRATCH cavm_edec_scratch_t
#define bustype_CAVM_EDEC_SCRATCH CSR_TYPE_RSL
#define basename_CAVM_EDEC_SCRATCH "EDEC_SCRATCH"
#define busnum_CAVM_EDEC_SCRATCH 0
#define arguments_CAVM_EDEC_SCRATCH -1,-1,-1,-1

/**
 * Register (RSL) edec_slot#_cfg
 *
 * EDEC AB Job Configuration Register
 * This register space contains the EDEC job configuration data.
 * Software should not write this register directly, but instead use this
 * format when writing the job configuration section of the job descriptor.
 */
union cavm_edec_slotx_cfg
{
    uint64_t u;
    struct cavm_edec_slotx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t num_sections          : 8;  /**< [ 31: 24](R/W) Number of sections in the packet. */
        uint64_t reserved_16_23        : 8;
        uint64_t byte_swap_disable     : 1;  /**< [ 15: 15](R/W) Disables the byte swap toward MHBW. */
        uint64_t reserved_0_14         : 15;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_14         : 15;
        uint64_t byte_swap_disable     : 1;  /**< [ 15: 15](R/W) Disables the byte swap toward MHBW. */
        uint64_t reserved_16_23        : 8;
        uint64_t num_sections          : 8;  /**< [ 31: 24](R/W) Number of sections in the packet. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_slotx_cfg_s cn; */
};
typedef union cavm_edec_slotx_cfg cavm_edec_slotx_cfg_t;

static inline uint64_t CAVM_EDEC_SLOTX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_SLOTX_CFG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043402000ll + 0x2000ll * ((a) & 0x3);
    __cavm_csr_fatal("EDEC_SLOTX_CFG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_SLOTX_CFG(a) cavm_edec_slotx_cfg_t
#define bustype_CAVM_EDEC_SLOTX_CFG(a) CSR_TYPE_RSL
#define basename_CAVM_EDEC_SLOTX_CFG(a) "EDEC_SLOTX_CFG"
#define busnum_CAVM_EDEC_SLOTX_CFG(a) (a)
#define arguments_CAVM_EDEC_SLOTX_CFG(a) (a),-1,-1,-1

/**
 * Register (RSL) edec_slot#_hdr_out_cfg_word0
 *
 * EDEC Output Configuration Word0 Register
 * This register contains data EDEC uses to form the first half of
 * the AB configuration required to be written if so instructed by
 * LUT[FLOW_ID].psm_job_cmd_word0.opcode.
 */
union cavm_edec_slotx_hdr_out_cfg_word0
{
    uint64_t u;
    struct cavm_edec_slotx_hdr_out_cfg_word0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) When LUT[FLOW_ID].psm_job_cmd_word0.opcode & 0x1f == 0x1,
                                                                 EDEC writes out EDEC_SLOT(0..2)_HDR_OUT_CFG_WORD0[DATA] as
                                                                 CFG_SECTION_WORD0 immediately after RD_DMA_CFG_WORD0,1. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) When LUT[FLOW_ID].psm_job_cmd_word0.opcode & 0x1f == 0x1,
                                                                 EDEC writes out EDEC_SLOT(0..2)_HDR_OUT_CFG_WORD0[DATA] as
                                                                 CFG_SECTION_WORD0 immediately after RD_DMA_CFG_WORD0,1. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_slotx_hdr_out_cfg_word0_s cn; */
};
typedef union cavm_edec_slotx_hdr_out_cfg_word0 cavm_edec_slotx_hdr_out_cfg_word0_t;

static inline uint64_t CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043402010ll + 0x2000ll * ((a) & 0x3);
    __cavm_csr_fatal("EDEC_SLOTX_HDR_OUT_CFG_WORD0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD0(a) cavm_edec_slotx_hdr_out_cfg_word0_t
#define bustype_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD0(a) CSR_TYPE_RSL
#define basename_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD0(a) "EDEC_SLOTX_HDR_OUT_CFG_WORD0"
#define busnum_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD0(a) (a)
#define arguments_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD0(a) (a),-1,-1,-1

/**
 * Register (RSL) edec_slot#_hdr_out_cfg_word1
 *
 * EDEC Output Configuration Word1 Register
 * This register contains data EDEC uses to form the second half of
 * the AB configuration required to be written if so instructed by
 * LUT[FLOW_ID].psm_job_cmd_word0.opcode.
 */
union cavm_edec_slotx_hdr_out_cfg_word1
{
    uint64_t u;
    struct cavm_edec_slotx_hdr_out_cfg_word1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 48; /**< [ 63: 16](R/W) When LUT[FLOW_ID].psm_job_cmd_word0.opcode & 0x1f == 0x1,
                                                                 EDEC writes out EDEC_SLOT(0..2)_HDR_OUT_CFG_WORD1[DATA] as
                                                                 CFG_SECTION_WORD1 immediately after CFG_SECTION_WORD0.
                                                                 Note that EDEC will fill in CFG_SECTION_WORD1[15:0] with
                                                                 NUM_SECTIONS[15:0]. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t data                  : 48; /**< [ 63: 16](R/W) When LUT[FLOW_ID].psm_job_cmd_word0.opcode & 0x1f == 0x1,
                                                                 EDEC writes out EDEC_SLOT(0..2)_HDR_OUT_CFG_WORD1[DATA] as
                                                                 CFG_SECTION_WORD1 immediately after CFG_SECTION_WORD0.
                                                                 Note that EDEC will fill in CFG_SECTION_WORD1[15:0] with
                                                                 NUM_SECTIONS[15:0]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_slotx_hdr_out_cfg_word1_s cn; */
};
typedef union cavm_edec_slotx_hdr_out_cfg_word1 cavm_edec_slotx_hdr_out_cfg_word1_t;

static inline uint64_t CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043402018ll + 0x2000ll * ((a) & 0x3);
    __cavm_csr_fatal("EDEC_SLOTX_HDR_OUT_CFG_WORD1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD1(a) cavm_edec_slotx_hdr_out_cfg_word1_t
#define bustype_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD1(a) CSR_TYPE_RSL
#define basename_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD1(a) "EDEC_SLOTX_HDR_OUT_CFG_WORD1"
#define busnum_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD1(a) (a)
#define arguments_CAVM_EDEC_SLOTX_HDR_OUT_CFG_WORD1(a) (a),-1,-1,-1

/**
 * Register (RSL) edec_slot#_hdr_out_dsp_jd
 *
 * EDEC Output DSP Job Descriptor Register
 * This register contains data EDEC uses to form the job descriptor
 * it will send to PSM for processing by DSP block if so instructed
 * by LUT[FLOW_ID].psm_job_cmd_word0.opcode.
 */
union cavm_edec_slotx_hdr_out_dsp_jd
{
    uint64_t u;
    struct cavm_edec_slotx_hdr_out_dsp_jd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t toth                  : 4;  /**< [  7:  4](R/W) When LUT[FLOW_ID].psm_job_cmd_word0.opcode & 0x1f == 0x1, EDEC
                                                                 will start header write-back with a job-descriptor containing
                                                                 6 64-bit words destined for DSP. TOTH goes to bits 60..57 of
                                                                 the first descriptor word, MDBW_JD_HDR_WORD0. */
        uint64_t toth_tick             : 4;  /**< [  3:  0](R/W) When LUT[FLOW_ID].psm_job_cmd_word0.opcode & 0x1f == 0x1, EDEC
                                                                 will start header write-back with a job-descriptor containing
                                                                 6 64-bit words destined for DSP. TOTH_TICK goes to bits 56..53
                                                                 of the first descriptor word, MDBW_JD_HDR_WORD0. */
#else /* Word 0 - Little Endian */
        uint64_t toth_tick             : 4;  /**< [  3:  0](R/W) When LUT[FLOW_ID].psm_job_cmd_word0.opcode & 0x1f == 0x1, EDEC
                                                                 will start header write-back with a job-descriptor containing
                                                                 6 64-bit words destined for DSP. TOTH_TICK goes to bits 56..53
                                                                 of the first descriptor word, MDBW_JD_HDR_WORD0. */
        uint64_t toth                  : 4;  /**< [  7:  4](R/W) When LUT[FLOW_ID].psm_job_cmd_word0.opcode & 0x1f == 0x1, EDEC
                                                                 will start header write-back with a job-descriptor containing
                                                                 6 64-bit words destined for DSP. TOTH goes to bits 60..57 of
                                                                 the first descriptor word, MDBW_JD_HDR_WORD0. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_slotx_hdr_out_dsp_jd_s cn; */
};
typedef union cavm_edec_slotx_hdr_out_dsp_jd cavm_edec_slotx_hdr_out_dsp_jd_t;

static inline uint64_t CAVM_EDEC_SLOTX_HDR_OUT_DSP_JD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_SLOTX_HDR_OUT_DSP_JD(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043402008ll + 0x2000ll * ((a) & 0x3);
    __cavm_csr_fatal("EDEC_SLOTX_HDR_OUT_DSP_JD", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_SLOTX_HDR_OUT_DSP_JD(a) cavm_edec_slotx_hdr_out_dsp_jd_t
#define bustype_CAVM_EDEC_SLOTX_HDR_OUT_DSP_JD(a) CSR_TYPE_RSL
#define basename_CAVM_EDEC_SLOTX_HDR_OUT_DSP_JD(a) "EDEC_SLOTX_HDR_OUT_DSP_JD"
#define busnum_CAVM_EDEC_SLOTX_HDR_OUT_DSP_JD(a) (a)
#define arguments_CAVM_EDEC_SLOTX_HDR_OUT_DSP_JD(a) (a),-1,-1,-1

/**
 * Register (RSL) edec_status
 *
 * EDEC Status Register
 */
union cavm_edec_status
{
    uint64_t u;
    struct cavm_edec_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, HAB is ready to receive the next job. */
        uint64_t reserved_3            : 1;
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
#else /* Word 0 - Little Endian */
        uint64_t cfg0_busy             : 1;  /**< [  0:  0](RO/H) When set, slot 0 is busy processing a job. */
        uint64_t cfg1_busy             : 1;  /**< [  1:  1](RO/H) When set, slot 1 is busy processing a job. */
        uint64_t cfg2_busy             : 1;  /**< [  2:  2](RO/H) When set, slot 2 is busy processing a job. */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) When set, HAB is ready to receive the next job. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_edec_status_s cn; */
};
typedef union cavm_edec_status cavm_edec_status_t;

#define CAVM_EDEC_STATUS CAVM_EDEC_STATUS_FUNC()
static inline uint64_t CAVM_EDEC_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_EDEC_STATUS_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043400010ll;
    __cavm_csr_fatal("EDEC_STATUS", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_EDEC_STATUS cavm_edec_status_t
#define bustype_CAVM_EDEC_STATUS CSR_TYPE_RSL
#define basename_CAVM_EDEC_STATUS "EDEC_STATUS"
#define busnum_CAVM_EDEC_STATUS 0
#define arguments_CAVM_EDEC_STATUS -1,-1,-1,-1

#endif /* __CAVM_CSRS_EDEC_H__ */
