#ifndef __CAVM_CSRS_ECMP_H__
#define __CAVM_CSRS_ECMP_H__
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
 * OcteonTX ECMP.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration ecmp_comp_meth_e
 *
 * INTERNAL: ECMP Compression Method Enumeration
 *
 * Internal:
 * FIXME remove, use ECPRI_COMP_METH_E instead.
 */
#define CAVM_ECMP_COMP_METH_E_FBFPC (1)
#define CAVM_ECMP_COMP_METH_E_FMC (4)
#define CAVM_ECMP_COMP_METH_E_FULC (3)
#define CAVM_ECMP_COMP_METH_E_FUNC (0)

/**
 * Enumeration ecpri_comp_meth_e
 *
 * eCPRI Compression Method Enumeration
 * Enumerates values of ECPRI_SECTION_HDR_SW_S[UD_COMP_METH],
 * ECMP_JDX()_CFG[COMP_METH], and EDEC_JDX()_CFG[COMP_METH].
 */
#define CAVM_ECPRI_COMP_METH_E_BFP (1)
#define CAVM_ECPRI_COMP_METH_E_MODULATION (4)
#define CAVM_ECPRI_COMP_METH_E_MU_LAW (3)
#define CAVM_ECPRI_COMP_METH_E_NO_COMP (0)

/**
 * Structure ecpri_hdr_s
 *
 * eCPRI Transport Header Structure
 * This structure specifies the format of the eCPRI transport header as specified
 * by the eCPRI standard.
 */
union cavm_ecpri_hdr_s
{
    uint64_t u;
    struct cavm_ecpri_hdr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ver                   : 4;  /**< [ 63: 60] eCPRI version. */
        uint64_t reserved_57_59        : 3;
        uint64_t concatenation         : 1;  /**< [ 56: 56] Concatenation indicator. */
        uint64_t msg_type              : 8;  /**< [ 55: 48] Message type. */
        uint64_t pyld_size             : 16; /**< [ 47: 32] Payload size in bytes. */
        uint64_t pc_id                 : 16; /**< [ 31: 16] eAxC identifier. */
        uint64_t seq_id                : 16; /**< [ 15:  0] Sequence identifier. */
#else /* Word 0 - Little Endian */
        uint64_t seq_id                : 16; /**< [ 15:  0] Sequence identifier. */
        uint64_t pc_id                 : 16; /**< [ 31: 16] eAxC identifier. */
        uint64_t pyld_size             : 16; /**< [ 47: 32] Payload size in bytes. */
        uint64_t msg_type              : 8;  /**< [ 55: 48] Message type. */
        uint64_t concatenation         : 1;  /**< [ 56: 56] Concatenation indicator. */
        uint64_t reserved_57_59        : 3;
        uint64_t ver                   : 4;  /**< [ 63: 60] eCPRI version. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecpri_hdr_s_s cn; */
};

/**
 * Structure ecpri_hdr_sw_s
 *
 * eCPRI Transport Header Software Structure
 * This structure specifies the format of the eCPRI transport header used by
 * software for user plane packets processed by ECMP and EDEC.
 */
union cavm_ecpri_hdr_sw_s
{
    uint64_t u;
    struct cavm_ecpri_hdr_sw_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t seq_id                : 16; /**< [ 63: 48] Sequence identifier. */
        uint64_t pc_id                 : 16; /**< [ 47: 32] eAxC identifier. */
        uint64_t pyld_size             : 16; /**< [ 31: 16] Payload size in bytes. */
        uint64_t msg_type              : 8;  /**< [ 15:  8] Message type. */
        uint64_t concatenation         : 1;  /**< [  7:  7] Concatenation indicator. */
        uint64_t reserved_4_6          : 3;
        uint64_t ver                   : 4;  /**< [  3:  0] eCPRI version. */
#else /* Word 0 - Little Endian */
        uint64_t ver                   : 4;  /**< [  3:  0] eCPRI version. */
        uint64_t reserved_4_6          : 3;
        uint64_t concatenation         : 1;  /**< [  7:  7] Concatenation indicator. */
        uint64_t msg_type              : 8;  /**< [ 15:  8] Message type. */
        uint64_t pyld_size             : 16; /**< [ 31: 16] Payload size in bytes. */
        uint64_t pc_id                 : 16; /**< [ 47: 32] eAxC identifier. */
        uint64_t seq_id                : 16; /**< [ 63: 48] Sequence identifier. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecpri_hdr_sw_s_s cn; */
};

/**
 * Structure ecpri_section_hdr_s
 *
 * eCPRI Section Header Structure
 * This structure specifies the format of the section header in eCPRI user plane
 * packets as specified by the ORAN standard. There is one ECPRI_SECTION_HDR_S for
 * each data section in the packet.
 */
union cavm_ecpri_section_hdr_s
{
    uint32_t u;
    struct cavm_ecpri_section_hdr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t section_id            : 12; /**< [ 31: 20] Section identifier. */
        uint32_t rb                    : 1;  /**< [ 19: 19] Resource block indicator. */
        uint32_t sym_inc               : 1;  /**< [ 18: 18] Symbol number increment. */
        uint32_t start_prb             : 10; /**< [ 17:  8] Starting PRB in the associated data section. */
        uint32_t num_prb               : 8;  /**< [  7:  0] Number of PRBs within the associated data section. */
#else /* Word 0 - Little Endian */
        uint32_t num_prb               : 8;  /**< [  7:  0] Number of PRBs within the associated data section. */
        uint32_t start_prb             : 10; /**< [ 17:  8] Starting PRB in the associated data section. */
        uint32_t sym_inc               : 1;  /**< [ 18: 18] Symbol number increment. */
        uint32_t rb                    : 1;  /**< [ 19: 19] Resource block indicator. */
        uint32_t section_id            : 12; /**< [ 31: 20] Section identifier. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecpri_section_hdr_s_s cn; */
};

/**
 * Structure ecpri_section_hdr_sw_s
 *
 * eCPRI Section Header Software Structure
 * This structure specifies the format of the eCPRI section header used by
 * software for user plane packets processed by ECMP and EDEC.
 */
union cavm_ecpri_section_hdr_sw_s
{
    uint64_t u;
    struct cavm_ecpri_section_hdr_sw_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t ud_iqwidth            : 4;  /**< [ 59: 56] User data I/Q width. Bit width of each compressed I and Q sample in the
                                                                 associated data section in flexible compression mode.
                                                                 Reserved in fixed compression mode.

                                                                 For ECMP, valid when ECMP_JDX()_CFG[FIX_MODE_EN] is clear.
                                                                 If [UD_COMP_METH] = ECPRI_COMP_METH_E::MODULATION and [UD_IQWIDTH] = 0x0,
                                                                 indicates BPSK modulation compression with a compressed width of 2 bits for
                                                                 each I and Q sample. [UD_IQWIDTH] = 0x0 indicates a compressed width of 16
                                                                 bits for all other compression methods. */
        uint64_t reserved_52_55        : 4;
        uint64_t ud_comp_meth          : 4;  /**< [ 51: 48] User data compression method. Compression method for the associated data
                                                                 section in flexible compression mode, enumerated by ECPRI_COMP_METH_E.
                                                                 Reserved in fixed compression mode.

                                                                 For ECMP, valid when ECMP_JDX()_CFG[FIX_MODE_EN] is clear. */
        uint64_t num_prb               : 16; /**< [ 47: 32] Number of PRBs within the associated data section.

                                                                 For ECMP, if [NUM_PRB]\<15\> is set, hardware will zero out the associated
                                                                 ECPRI_SECTION_HDR_S[NUM_PRB] in the outgoing packet, indicating that the
                                                                 section contains the rest of PRBs in TBD. */
        uint64_t reserved_26_31        : 6;
        uint64_t start_prb             : 10; /**< [ 25: 16] Starting PRB in the associated data section. */
        uint64_t sym_inc               : 1;  /**< [ 15: 15] Symbol number increment. */
        uint64_t reserved_13_14        : 2;
        uint64_t rb                    : 1;  /**< [ 12: 12] Resource block indicator. */
        uint64_t section_id            : 12; /**< [ 11:  0] Section identifier. */
#else /* Word 0 - Little Endian */
        uint64_t section_id            : 12; /**< [ 11:  0] Section identifier. */
        uint64_t rb                    : 1;  /**< [ 12: 12] Resource block indicator. */
        uint64_t reserved_13_14        : 2;
        uint64_t sym_inc               : 1;  /**< [ 15: 15] Symbol number increment. */
        uint64_t start_prb             : 10; /**< [ 25: 16] Starting PRB in the associated data section. */
        uint64_t reserved_26_31        : 6;
        uint64_t num_prb               : 16; /**< [ 47: 32] Number of PRBs within the associated data section.

                                                                 For ECMP, if [NUM_PRB]\<15\> is set, hardware will zero out the associated
                                                                 ECPRI_SECTION_HDR_S[NUM_PRB] in the outgoing packet, indicating that the
                                                                 section contains the rest of PRBs in TBD. */
        uint64_t ud_comp_meth          : 4;  /**< [ 51: 48] User data compression method. Compression method for the associated data
                                                                 section in flexible compression mode, enumerated by ECPRI_COMP_METH_E.
                                                                 Reserved in fixed compression mode.

                                                                 For ECMP, valid when ECMP_JDX()_CFG[FIX_MODE_EN] is clear. */
        uint64_t reserved_52_55        : 4;
        uint64_t ud_iqwidth            : 4;  /**< [ 59: 56] User data I/Q width. Bit width of each compressed I and Q sample in the
                                                                 associated data section in flexible compression mode.
                                                                 Reserved in fixed compression mode.

                                                                 For ECMP, valid when ECMP_JDX()_CFG[FIX_MODE_EN] is clear.
                                                                 If [UD_COMP_METH] = ECPRI_COMP_METH_E::MODULATION and [UD_IQWIDTH] = 0x0,
                                                                 indicates BPSK modulation compression with a compressed width of 2 bits for
                                                                 each I and Q sample. [UD_IQWIDTH] = 0x0 indicates a compressed width of 16
                                                                 bits for all other compression methods. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecpri_section_hdr_sw_s_s cn; */
};

/**
 * Structure ecpri_timing_hdr_s
 *
 * eCPRI Timing Header Structure
 * This structure specifies the format of the eCPRI timing header as specified by
 * the ORAN standard.
 */
union cavm_ecpri_timing_hdr_s
{
    uint32_t u;
    struct cavm_ecpri_timing_hdr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t data_direction        : 1;  /**< [ 31: 31] Data direction.
                                                                 0 = Receive (uplink).
                                                                 1 = Transmit (downlink). */
        uint32_t payload_version       : 3;  /**< [ 30: 28] Payload version. Must be 0x1. */
        uint32_t filter_index          : 4;  /**< [ 27: 24] Filter index. */
        uint32_t frame_id              : 8;  /**< [ 23: 16] Frame identifier. */
        uint32_t subframe_id           : 4;  /**< [ 15: 12] Subframe identifier. */
        uint32_t slot_id               : 6;  /**< [ 11:  6] Slot identifier. */
        uint32_t symbol_id             : 6;  /**< [  5:  0] Symbol identifier. */
#else /* Word 0 - Little Endian */
        uint32_t symbol_id             : 6;  /**< [  5:  0] Symbol identifier. */
        uint32_t slot_id               : 6;  /**< [ 11:  6] Slot identifier. */
        uint32_t subframe_id           : 4;  /**< [ 15: 12] Subframe identifier. */
        uint32_t frame_id              : 8;  /**< [ 23: 16] Frame identifier. */
        uint32_t filter_index          : 4;  /**< [ 27: 24] Filter index. */
        uint32_t payload_version       : 3;  /**< [ 30: 28] Payload version. Must be 0x1. */
        uint32_t data_direction        : 1;  /**< [ 31: 31] Data direction.
                                                                 0 = Receive (uplink).
                                                                 1 = Transmit (downlink). */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecpri_timing_hdr_s_s cn; */
};

/**
 * Structure ecpri_timing_hdr_sw_s
 *
 * eCPRI Timing Header Software Structure
 * This structure specifies the format of the eCPRI timing header used by software
 * for U-Plane packets processed by ECMP and EDEC.
 */
union cavm_ecpri_timing_hdr_sw_s
{
    uint64_t u;
    struct cavm_ecpri_timing_hdr_sw_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t symbol_id             : 6;  /**< [ 53: 48] Symbol identifier. */
        uint64_t reserved_46_47        : 2;
        uint64_t slot_id               : 6;  /**< [ 45: 40] Slot identifier. */
        uint64_t reserved_36_39        : 4;
        uint64_t subframe_id           : 4;  /**< [ 35: 32] Subframe identifier. */
        uint64_t frame_id              : 8;  /**< [ 31: 24] Frame identifier. */
        uint64_t reserved_20_23        : 4;
        uint64_t filter_index          : 4;  /**< [ 19: 16] Filter index. */
        uint64_t reserved_11_15        : 5;
        uint64_t payload_version       : 3;  /**< [ 10:  8] Payload version. Must be 0x1. */
        uint64_t reserved_1_7          : 7;
        uint64_t data_direction        : 1;  /**< [  0:  0] Data direction.
                                                                 0 = Receive (uplink).
                                                                 1 = Transmit (downlink). */
#else /* Word 0 - Little Endian */
        uint64_t data_direction        : 1;  /**< [  0:  0] Data direction.
                                                                 0 = Receive (uplink).
                                                                 1 = Transmit (downlink). */
        uint64_t reserved_1_7          : 7;
        uint64_t payload_version       : 3;  /**< [ 10:  8] Payload version. Must be 0x1. */
        uint64_t reserved_11_15        : 5;
        uint64_t filter_index          : 4;  /**< [ 19: 16] Filter index. */
        uint64_t reserved_20_23        : 4;
        uint64_t frame_id              : 8;  /**< [ 31: 24] Frame identifier. */
        uint64_t subframe_id           : 4;  /**< [ 35: 32] Subframe identifier. */
        uint64_t reserved_36_39        : 4;
        uint64_t slot_id               : 6;  /**< [ 45: 40] Slot identifier. */
        uint64_t reserved_46_47        : 2;
        uint64_t symbol_id             : 6;  /**< [ 53: 48] Symbol identifier. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecpri_timing_hdr_sw_s_s cn; */
};

/**
 * Structure ecpri_ud_comp_hdr_s
 *
 * eCPRI User Data Compression Header Structure
 * This structure specifies the format of the user data compression header
 * (including reserved field) in eCPRI user plane packets as specified by the ORAN
 * standard. Not present in packets with fixed compression. In packets with
 * flexible compression, each packet section has a ECPRI_UD_COMP_HDR_S immediately
 * following the associated ECPRI_SECTION_HDR_S.
 */
union cavm_ecpri_ud_comp_hdr_s
{
    uint32_t u;
    struct cavm_ecpri_ud_comp_hdr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t ud_iqwidth            : 4;  /**< [ 15: 12] User data I/Q width. Bit width of each compressed I and Q sample in the
                                                                 associated data section. */
        uint32_t ud_comp_meth          : 4;  /**< [ 11:  8] User data compression method enumerated by ECPRI_COMP_METH_E. */
        uint32_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_7          : 8;
        uint32_t ud_comp_meth          : 4;  /**< [ 11:  8] User data compression method enumerated by ECPRI_COMP_METH_E. */
        uint32_t ud_iqwidth            : 4;  /**< [ 15: 12] User data I/Q width. Bit width of each compressed I and Q sample in the
                                                                 associated data section. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecpri_ud_comp_hdr_s_s cn; */
};

/**
 * Register (RSL) ecmp_bp_test0
 *
 * INTERNAL: ECMP Back Pressure Test 0 Register
 *
 * Internal:
 * Back Pressure
 */
union cavm_ecmp_bp_test0
{
    uint64_t u;
    struct cavm_ecmp_bp_test0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Prevents arb from granting.
                                                                 \<63\> = unused
                                                                 \<62\> = Compressed PRBs FIFO
                                                                 \<61\> = Compressed headers FIFO
                                                                 \<60\> = mhbw_wr_port */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                 \<23:22\> = unused
                                                                 \<21:20\> = Compressed PRBs FIFO
                                                                 \<19:18\> = Compressed headers FIFO
                                                                 \<17:16\> = mhbw_wr_port */
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
                                                                 \<23:22\> = unused
                                                                 \<21:20\> = Compressed PRBs FIFO
                                                                 \<19:18\> = Compressed headers FIFO
                                                                 \<17:16\> = mhbw_wr_port */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Prevents arb from granting.
                                                                 \<63\> = unused
                                                                 \<62\> = Compressed PRBs FIFO
                                                                 \<61\> = Compressed headers FIFO
                                                                 \<60\> = mhbw_wr_port */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_bp_test0_s cn; */
};
typedef union cavm_ecmp_bp_test0 cavm_ecmp_bp_test0_t;

#define CAVM_ECMP_BP_TEST0 CAVM_ECMP_BP_TEST0_FUNC()
static inline uint64_t CAVM_ECMP_BP_TEST0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_BP_TEST0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e0438000d0ll;
    __cavm_csr_fatal("ECMP_BP_TEST0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_BP_TEST0 cavm_ecmp_bp_test0_t
#define bustype_CAVM_ECMP_BP_TEST0 CSR_TYPE_RSL
#define basename_CAVM_ECMP_BP_TEST0 "ECMP_BP_TEST0"
#define busnum_CAVM_ECMP_BP_TEST0 0
#define arguments_CAVM_ECMP_BP_TEST0 -1,-1,-1,-1

/**
 * Register (RSL) ecmp_bp_test1
 *
 * INTERNAL: ECMP Back Pressure Test 1 Register
 *
 * Internal:
 * Back pressure to JCA and DMA paths
 */
union cavm_ecmp_bp_test1
{
    uint64_t u;
    struct cavm_ecmp_bp_test1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Prevents arb from granting.
                                                                 \<63\> = Unused
                                                                 \<62\> = Unused
                                                                 \<61\> = Header input buffer
                                                                 \<60\> = PRB input buffer */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                 \<23:22\> = Unused
                                                                 \<21:20\> = Unused
                                                                 \<19:18\> = Header input buffer
                                                                 \<17:16\> = PRB input buffer */
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
                                                                 \<23:22\> = Unused
                                                                 \<21:20\> = Unused
                                                                 \<19:18\> = Header input buffer
                                                                 \<17:16\> = PRB input buffer */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Prevents arb from granting.
                                                                 \<63\> = Unused
                                                                 \<62\> = Unused
                                                                 \<61\> = Header input buffer
                                                                 \<60\> = PRB input buffer */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_bp_test1_s cn; */
};
typedef union cavm_ecmp_bp_test1 cavm_ecmp_bp_test1_t;

#define CAVM_ECMP_BP_TEST1 CAVM_ECMP_BP_TEST1_FUNC()
static inline uint64_t CAVM_ECMP_BP_TEST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_BP_TEST1_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e0438000d8ll;
    __cavm_csr_fatal("ECMP_BP_TEST1", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_BP_TEST1 cavm_ecmp_bp_test1_t
#define bustype_CAVM_ECMP_BP_TEST1 CSR_TYPE_RSL
#define basename_CAVM_ECMP_BP_TEST1 "ECMP_BP_TEST1"
#define busnum_CAVM_ECMP_BP_TEST1 0
#define arguments_CAVM_ECMP_BP_TEST1 -1,-1,-1,-1

/**
 * Register (RSL) ecmp_config
 *
 * INTERNAL: ECMP CONFIG Register
 */
union cavm_ecmp_config
{
    uint64_t u;
    struct cavm_ecmp_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t force_cond_clk_en     : 1;  /**< [  4:  4](R/W) Force the conditional clocks active within the block. For diagnostic use only. */
        uint64_t reserved_1_3          : 3;
        uint64_t uncomp_shift_left     : 1;  /**< [  0:  0](R/W) If set, uncompressed I/Q with iqWidth \<16 will be shift left.
                                                                 if clear, uncompressed I/Q with iqWidth \< 16 will be shift right. */
#else /* Word 0 - Little Endian */
        uint64_t uncomp_shift_left     : 1;  /**< [  0:  0](R/W) If set, uncompressed I/Q with iqWidth \<16 will be shift left.
                                                                 if clear, uncompressed I/Q with iqWidth \< 16 will be shift right. */
        uint64_t reserved_1_3          : 3;
        uint64_t force_cond_clk_en     : 1;  /**< [  4:  4](R/W) Force the conditional clocks active within the block. For diagnostic use only. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_config_s cn; */
};
typedef union cavm_ecmp_config cavm_ecmp_config_t;

#define CAVM_ECMP_CONFIG CAVM_ECMP_CONFIG_FUNC()
static inline uint64_t CAVM_ECMP_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_CONFIG_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043800008ll;
    __cavm_csr_fatal("ECMP_CONFIG", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_CONFIG cavm_ecmp_config_t
#define bustype_CAVM_ECMP_CONFIG CSR_TYPE_RSL
#define basename_CAVM_ECMP_CONFIG "ECMP_CONFIG"
#define busnum_CAVM_ECMP_CONFIG 0
#define arguments_CAVM_ECMP_CONFIG -1,-1,-1,-1

/**
 * Register (RSL) ecmp_control
 *
 * ECMP Control Register
 */
union cavm_ecmp_control
{
    uint64_t u;
    struct cavm_ecmp_control_s
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
    /* struct cavm_ecmp_control_s cn; */
};
typedef union cavm_ecmp_control cavm_ecmp_control_t;

#define CAVM_ECMP_CONTROL CAVM_ECMP_CONTROL_FUNC()
static inline uint64_t CAVM_ECMP_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_CONTROL_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043800000ll;
    __cavm_csr_fatal("ECMP_CONTROL", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_CONTROL cavm_ecmp_control_t
#define bustype_CAVM_ECMP_CONTROL CSR_TYPE_RSL
#define basename_CAVM_ECMP_CONTROL "ECMP_CONTROL"
#define busnum_CAVM_ECMP_CONTROL 0
#define arguments_CAVM_ECMP_CONTROL -1,-1,-1,-1

/**
 * Register (RSL) ecmp_eco
 *
 * INTERNAL: ECMP ECO Register
 */
union cavm_ecmp_eco
{
    uint64_t u;
    struct cavm_ecmp_eco_s
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
    /* struct cavm_ecmp_eco_s cn; */
};
typedef union cavm_ecmp_eco cavm_ecmp_eco_t;

#define CAVM_ECMP_ECO CAVM_ECMP_ECO_FUNC()
static inline uint64_t CAVM_ECMP_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_ECO_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043800010ll;
    __cavm_csr_fatal("ECMP_ECO", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_ECO cavm_ecmp_eco_t
#define bustype_CAVM_ECMP_ECO CSR_TYPE_RSL
#define basename_CAVM_ECMP_ECO "ECMP_ECO"
#define busnum_CAVM_ECMP_ECO 0
#define arguments_CAVM_ECMP_ECO -1,-1,-1,-1

/**
 * Register (RSL) ecmp_error_ena_w1c
 *
 * ECMP Error Interrupt Message Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_ecmp_error_ena_w1c
{
    uint64_t u;
    struct cavm_ecmp_error_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[WRRSP_FAT]. */
        uint64_t reserved_5_11         : 7;
        uint64_t bfpc_param_err        : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[BFPC_PARAM_ERR]. */
        uint64_t ulaw_compbitwidth_err : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[ULAW_COMPBITWIDTH_ERR]. */
        uint64_t modc_iqwidth_err      : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[MODC_IQWIDTH_ERR]. */
        uint64_t bfpc_iqwidth_err      : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[BFPC_IQWIDTH_ERR]. */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[COMPMETH_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[COMPMETH_ERR]. */
        uint64_t bfpc_iqwidth_err      : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[BFPC_IQWIDTH_ERR]. */
        uint64_t modc_iqwidth_err      : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[MODC_IQWIDTH_ERR]. */
        uint64_t ulaw_compbitwidth_err : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[ULAW_COMPBITWIDTH_ERR]. */
        uint64_t bfpc_param_err        : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[BFPC_PARAM_ERR]. */
        uint64_t reserved_5_11         : 7;
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[WRRSP_FAT]. */
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for ECMP_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_error_ena_w1c_s cn; */
};
typedef union cavm_ecmp_error_ena_w1c cavm_ecmp_error_ena_w1c_t;

#define CAVM_ECMP_ERROR_ENA_W1C CAVM_ECMP_ERROR_ENA_W1C_FUNC()
static inline uint64_t CAVM_ECMP_ERROR_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_ERROR_ENA_W1C_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e0438000c0ll;
    __cavm_csr_fatal("ECMP_ERROR_ENA_W1C", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_ERROR_ENA_W1C cavm_ecmp_error_ena_w1c_t
#define bustype_CAVM_ECMP_ERROR_ENA_W1C CSR_TYPE_RSL
#define basename_CAVM_ECMP_ERROR_ENA_W1C "ECMP_ERROR_ENA_W1C"
#define busnum_CAVM_ECMP_ERROR_ENA_W1C 0
#define arguments_CAVM_ECMP_ERROR_ENA_W1C -1,-1,-1,-1

/**
 * Register (RSL) ecmp_error_ena_w1s
 *
 * ECMP Error Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_ecmp_error_ena_w1s
{
    uint64_t u;
    struct cavm_ecmp_error_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[WRRSP_FAT]. */
        uint64_t reserved_5_11         : 7;
        uint64_t bfpc_param_err        : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[BFPC_PARAM_ERR]. */
        uint64_t ulaw_compbitwidth_err : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[ULAW_COMPBITWIDTH_ERR]. */
        uint64_t modc_iqwidth_err      : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[MODC_IQWIDTH_ERR]. */
        uint64_t bfpc_iqwidth_err      : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[BFPC_IQWIDTH_ERR]. */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[COMPMETH_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[COMPMETH_ERR]. */
        uint64_t bfpc_iqwidth_err      : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[BFPC_IQWIDTH_ERR]. */
        uint64_t modc_iqwidth_err      : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[MODC_IQWIDTH_ERR]. */
        uint64_t ulaw_compbitwidth_err : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[ULAW_COMPBITWIDTH_ERR]. */
        uint64_t bfpc_param_err        : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[BFPC_PARAM_ERR]. */
        uint64_t reserved_5_11         : 7;
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[WRRSP_FAT]. */
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for ECMP_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_error_ena_w1s_s cn; */
};
typedef union cavm_ecmp_error_ena_w1s cavm_ecmp_error_ena_w1s_t;

#define CAVM_ECMP_ERROR_ENA_W1S CAVM_ECMP_ERROR_ENA_W1S_FUNC()
static inline uint64_t CAVM_ECMP_ERROR_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_ERROR_ENA_W1S_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e0438000b8ll;
    __cavm_csr_fatal("ECMP_ERROR_ENA_W1S", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_ERROR_ENA_W1S cavm_ecmp_error_ena_w1s_t
#define bustype_CAVM_ECMP_ERROR_ENA_W1S CSR_TYPE_RSL
#define basename_CAVM_ECMP_ERROR_ENA_W1S "ECMP_ERROR_ENA_W1S"
#define busnum_CAVM_ECMP_ERROR_ENA_W1S 0
#define arguments_CAVM_ECMP_ERROR_ENA_W1S -1,-1,-1,-1

/**
 * Register (RSL) ecmp_error_enable0
 *
 * ECMP Error Enable Register 0
 * This register enables reporting the source of read DMA overflow/underflow errors.
 */
union cavm_ecmp_error_enable0
{
    uint64_t u;
    struct cavm_ecmp_error_enable0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t rp1_of_en             : 1;  /**< [  5:  5](R/W1C/H) Read port 1 overflow. */
        uint64_t rp0_of_en             : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t reserved_2_3          : 2;
        uint64_t rp1_uf_en             : 1;  /**< [  1:  1](R/W1C/H) Read port 1 underflow. */
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
#else /* Word 0 - Little Endian */
        uint64_t rp0_uf_en             : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
        uint64_t rp1_uf_en             : 1;  /**< [  1:  1](R/W1C/H) Read port 1 underflow. */
        uint64_t reserved_2_3          : 2;
        uint64_t rp0_of_en             : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t rp1_of_en             : 1;  /**< [  5:  5](R/W1C/H) Read port 1 overflow. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_error_enable0_s cn; */
};
typedef union cavm_ecmp_error_enable0 cavm_ecmp_error_enable0_t;

#define CAVM_ECMP_ERROR_ENABLE0 CAVM_ECMP_ERROR_ENABLE0_FUNC()
static inline uint64_t CAVM_ECMP_ERROR_ENABLE0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_ERROR_ENABLE0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043800040ll;
    __cavm_csr_fatal("ECMP_ERROR_ENABLE0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_ERROR_ENABLE0 cavm_ecmp_error_enable0_t
#define bustype_CAVM_ECMP_ERROR_ENABLE0 CSR_TYPE_RSL
#define basename_CAVM_ECMP_ERROR_ENABLE0 "ECMP_ERROR_ENABLE0"
#define busnum_CAVM_ECMP_ERROR_ENABLE0 0
#define arguments_CAVM_ECMP_ERROR_ENABLE0 -1,-1,-1,-1

/**
 * Register (RSL) ecmp_error_int
 *
 * ECMP Error Interrupt Register
 * These registers record normal errors across the ECMP
 * When an error occurs, ECMP sends  message to PSM.
 */
union cavm_ecmp_error_int
{
    uint64_t u;
    struct cavm_ecmp_error_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1C/H) Write response returned a non-fatal non-NXM error.
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1C/H) Write response returned a fatal non-NXM error. */
        uint64_t reserved_5_11         : 7;
        uint64_t bfpc_param_err        : 1;  /**< [  4:  4](R/W1C/H) Block Floating Point Compression Parameter Error. Set if (iqWidth + exponent) \> 16
                                                                 and compression method is Block Floating Point. */
        uint64_t ulaw_compbitwidth_err : 1;  /**< [  3:  3](R/W1C/H) Fixed {mu}-Law Compression - compBitWidth Error. compBitWidth field is not
                                                                 supported for {mu}-Law Compression. */
        uint64_t modc_iqwidth_err      : 1;  /**< [  2:  2](R/W1C/H) Modulation Compression - iqWidth Error. IqWidth field is not supported for
                                                                 Modulation Compression. (iqWidth \> 5 and CompMeth== Modulation). */
        uint64_t bfpc_iqwidth_err      : 1;  /**< [  1:  1](R/W1C/H) Block Floating Point Compression - iqWidth Error. IqWidth field is not supported
                                                                 for Block Floating Point Compression. (iqWidth==16 and CompMeth== block Floating
                                                                 point). */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1C/H) CompMeth field is not supported (!=0,1,4) */
#else /* Word 0 - Little Endian */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1C/H) CompMeth field is not supported (!=0,1,4) */
        uint64_t bfpc_iqwidth_err      : 1;  /**< [  1:  1](R/W1C/H) Block Floating Point Compression - iqWidth Error. IqWidth field is not supported
                                                                 for Block Floating Point Compression. (iqWidth==16 and CompMeth== block Floating
                                                                 point). */
        uint64_t modc_iqwidth_err      : 1;  /**< [  2:  2](R/W1C/H) Modulation Compression - iqWidth Error. IqWidth field is not supported for
                                                                 Modulation Compression. (iqWidth \> 5 and CompMeth== Modulation). */
        uint64_t ulaw_compbitwidth_err : 1;  /**< [  3:  3](R/W1C/H) Fixed {mu}-Law Compression - compBitWidth Error. compBitWidth field is not
                                                                 supported for {mu}-Law Compression. */
        uint64_t bfpc_param_err        : 1;  /**< [  4:  4](R/W1C/H) Block Floating Point Compression Parameter Error. Set if (iqWidth + exponent) \> 16
                                                                 and compression method is Block Floating Point. */
        uint64_t reserved_5_11         : 7;
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1C/H) Write response returned a fatal non-NXM error. */
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1C/H) Write response returned a non-fatal non-NXM error.
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_error_int_s cn; */
};
typedef union cavm_ecmp_error_int cavm_ecmp_error_int_t;

#define CAVM_ECMP_ERROR_INT CAVM_ECMP_ERROR_INT_FUNC()
static inline uint64_t CAVM_ECMP_ERROR_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_ERROR_INT_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e0438000b0ll;
    __cavm_csr_fatal("ECMP_ERROR_INT", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_ERROR_INT cavm_ecmp_error_int_t
#define bustype_CAVM_ECMP_ERROR_INT CSR_TYPE_RSL
#define basename_CAVM_ECMP_ERROR_INT "ECMP_ERROR_INT"
#define busnum_CAVM_ECMP_ERROR_INT 0
#define arguments_CAVM_ECMP_ERROR_INT -1,-1,-1,-1

/**
 * Register (RSL) ecmp_error_int_w1s
 *
 * ECMP Error Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_ecmp_error_int_w1s
{
    uint64_t u;
    struct cavm_ecmp_error_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets ECMP_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets ECMP_ERROR_INT[WRRSP_FAT]. */
        uint64_t reserved_5_11         : 7;
        uint64_t bfpc_param_err        : 1;  /**< [  4:  4](R/W1S/H) Reads or sets ECMP_ERROR_INT[BFPC_PARAM_ERR]. */
        uint64_t ulaw_compbitwidth_err : 1;  /**< [  3:  3](R/W1S/H) Reads or sets ECMP_ERROR_INT[ULAW_COMPBITWIDTH_ERR]. */
        uint64_t modc_iqwidth_err      : 1;  /**< [  2:  2](R/W1S/H) Reads or sets ECMP_ERROR_INT[MODC_IQWIDTH_ERR]. */
        uint64_t bfpc_iqwidth_err      : 1;  /**< [  1:  1](R/W1S/H) Reads or sets ECMP_ERROR_INT[BFPC_IQWIDTH_ERR]. */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets ECMP_ERROR_INT[COMPMETH_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t compmeth_err          : 1;  /**< [  0:  0](R/W1S/H) Reads or sets ECMP_ERROR_INT[COMPMETH_ERR]. */
        uint64_t bfpc_iqwidth_err      : 1;  /**< [  1:  1](R/W1S/H) Reads or sets ECMP_ERROR_INT[BFPC_IQWIDTH_ERR]. */
        uint64_t modc_iqwidth_err      : 1;  /**< [  2:  2](R/W1S/H) Reads or sets ECMP_ERROR_INT[MODC_IQWIDTH_ERR]. */
        uint64_t ulaw_compbitwidth_err : 1;  /**< [  3:  3](R/W1S/H) Reads or sets ECMP_ERROR_INT[ULAW_COMPBITWIDTH_ERR]. */
        uint64_t bfpc_param_err        : 1;  /**< [  4:  4](R/W1S/H) Reads or sets ECMP_ERROR_INT[BFPC_PARAM_ERR]. */
        uint64_t reserved_5_11         : 7;
        uint64_t wrrsp_fat             : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets ECMP_ERROR_INT[WRRSP_FAT]. */
        uint64_t wrrsp_nfat            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets ECMP_ERROR_INT[WRRSP_NFAT].
                                                                 Internal:
                                                                 Should never occur. Including for completeness */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_error_int_w1s_s cn; */
};
typedef union cavm_ecmp_error_int_w1s cavm_ecmp_error_int_w1s_t;

#define CAVM_ECMP_ERROR_INT_W1S CAVM_ECMP_ERROR_INT_W1S_FUNC()
static inline uint64_t CAVM_ECMP_ERROR_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_ERROR_INT_W1S_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e0438000c8ll;
    __cavm_csr_fatal("ECMP_ERROR_INT_W1S", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_ERROR_INT_W1S cavm_ecmp_error_int_w1s_t
#define bustype_CAVM_ECMP_ERROR_INT_W1S CSR_TYPE_RSL
#define basename_CAVM_ECMP_ERROR_INT_W1S "ECMP_ERROR_INT_W1S"
#define busnum_CAVM_ECMP_ERROR_INT_W1S 0
#define arguments_CAVM_ECMP_ERROR_INT_W1S -1,-1,-1,-1

/**
 * Register (RSL) ecmp_error_source0
 *
 * ECMP Error Source Register 0
 * This register reports the source of read DMA overflow/underflow errors.
 */
union cavm_ecmp_error_source0
{
    uint64_t u;
    struct cavm_ecmp_error_source0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t rp1_jobid             : 16; /**< [ 47: 32](RO/H) Job ID for read port 0 overflow/underflow. */
        uint64_t rp0_jobid             : 16; /**< [ 31: 16](RO/H) Job ID for read port 0 overflow/underflow. */
        uint64_t reserved_6_15         : 10;
        uint64_t rp1_of                : 1;  /**< [  5:  5](R/W1C/H) Read port 1 overflow. */
        uint64_t rp0_of                : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t reserved_2_3          : 2;
        uint64_t rp1_uf                : 1;  /**< [  1:  1](R/W1C/H) Read port 1 underflow. */
        uint64_t rp0_uf                : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
#else /* Word 0 - Little Endian */
        uint64_t rp0_uf                : 1;  /**< [  0:  0](R/W1C/H) Read port 0 underflow. */
        uint64_t rp1_uf                : 1;  /**< [  1:  1](R/W1C/H) Read port 1 underflow. */
        uint64_t reserved_2_3          : 2;
        uint64_t rp0_of                : 1;  /**< [  4:  4](R/W1C/H) Read port 0 overflow. */
        uint64_t rp1_of                : 1;  /**< [  5:  5](R/W1C/H) Read port 1 overflow. */
        uint64_t reserved_6_15         : 10;
        uint64_t rp0_jobid             : 16; /**< [ 31: 16](RO/H) Job ID for read port 0 overflow/underflow. */
        uint64_t rp1_jobid             : 16; /**< [ 47: 32](RO/H) Job ID for read port 0 overflow/underflow. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_error_source0_s cn; */
};
typedef union cavm_ecmp_error_source0 cavm_ecmp_error_source0_t;

#define CAVM_ECMP_ERROR_SOURCE0 CAVM_ECMP_ERROR_SOURCE0_FUNC()
static inline uint64_t CAVM_ECMP_ERROR_SOURCE0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_ERROR_SOURCE0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043800030ll;
    __cavm_csr_fatal("ECMP_ERROR_SOURCE0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_ERROR_SOURCE0 cavm_ecmp_error_source0_t
#define bustype_CAVM_ECMP_ERROR_SOURCE0 CSR_TYPE_RSL
#define basename_CAVM_ECMP_ERROR_SOURCE0 "ECMP_ERROR_SOURCE0"
#define busnum_CAVM_ECMP_ERROR_SOURCE0 0
#define arguments_CAVM_ECMP_ERROR_SOURCE0 -1,-1,-1,-1

/**
 * Register (RSL) ecmp_jdx#_cfg
 *
 * ECMP AB Job Configuration Register
 * This register space contains the ECMP job configuration data.
 * Software should not write this register directly, but instead use this
 * format when writing the job configuration section of the job descriptor.
 */
union cavm_ecmp_jdxx_cfg
{
    uint64_t u;
    struct cavm_ecmp_jdxx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t num_sections          : 8;  /**< [ 31: 24](R/W) Number of data sections in the packet. Must be non-zero. */
        uint64_t reserved_16_23        : 8;
        uint64_t byte_swap_disable     : 1;  /**< [ 15: 15](R/W) Disables the byte swap toward MHBW. */
        uint64_t ecpri_hdr_present     : 1;  /**< [ 14: 14](R/W) eCPRI header present in input header buffer and assembled packet */
        uint64_t timing_hdr_present    : 1;  /**< [ 13: 13](R/W) Timing header present in input header buffer and assembled packet */
        uint64_t reserved_9_12         : 4;
        uint64_t fix_mode_en           : 1;  /**< [  8:  8](R/W) When set, the compression mode is fixed. The compression method and width
                                                                 for the entire packet are specified by [COMP_METH] and [IQWIDTH], respectively.

                                                                 When clear, the compression method and width are flexible. For each data
                                                                 section in the packet, the compression method and width are specified by
                                                                 ECPRI_SECTION_HDR_SW_S[UD_COMP_METH] and
                                                                 ECPRI_SECTION_HDR_SW_S[UD_IQWIDTH] in the associated section header. */
        uint64_t iqwidth               : 4;  /**< [  7:  4](R/W) I/Q width. Bit width of each compressed I and Q sample in the packet in
                                                                 fixed compression mode. Valid when [FIX_MODE_EN] is set.

                                                                 If [FIX_MODE_EN] is set, [COMP_METH] = ECPRI_COMP_METH_E::MODULATION and
                                                                 [IQWIDTH] = 0, indicates BPSK modulation compression with a compressed
                                                                 width of 2 bits for each I and Q sample. [IQWIDTH] = 0x0 indicates a
                                                                 compressed width of 16 bits for all other compression methods. */
        uint64_t comp_meth             : 4;  /**< [  3:  0](R/W) Compression method enumerated by ECPRI_COMP_METH_E. Valid when
                                                                 [FIX_MODE_EN] is set.

                                                                 Internal:
                                                                 FIXME change enumerated_by value to "ECPRI_COMP_METH_E" */
#else /* Word 0 - Little Endian */
        uint64_t comp_meth             : 4;  /**< [  3:  0](R/W) Compression method enumerated by ECPRI_COMP_METH_E. Valid when
                                                                 [FIX_MODE_EN] is set.

                                                                 Internal:
                                                                 FIXME change enumerated_by value to "ECPRI_COMP_METH_E" */
        uint64_t iqwidth               : 4;  /**< [  7:  4](R/W) I/Q width. Bit width of each compressed I and Q sample in the packet in
                                                                 fixed compression mode. Valid when [FIX_MODE_EN] is set.

                                                                 If [FIX_MODE_EN] is set, [COMP_METH] = ECPRI_COMP_METH_E::MODULATION and
                                                                 [IQWIDTH] = 0, indicates BPSK modulation compression with a compressed
                                                                 width of 2 bits for each I and Q sample. [IQWIDTH] = 0x0 indicates a
                                                                 compressed width of 16 bits for all other compression methods. */
        uint64_t fix_mode_en           : 1;  /**< [  8:  8](R/W) When set, the compression mode is fixed. The compression method and width
                                                                 for the entire packet are specified by [COMP_METH] and [IQWIDTH], respectively.

                                                                 When clear, the compression method and width are flexible. For each data
                                                                 section in the packet, the compression method and width are specified by
                                                                 ECPRI_SECTION_HDR_SW_S[UD_COMP_METH] and
                                                                 ECPRI_SECTION_HDR_SW_S[UD_IQWIDTH] in the associated section header. */
        uint64_t reserved_9_12         : 4;
        uint64_t timing_hdr_present    : 1;  /**< [ 13: 13](R/W) Timing header present in input header buffer and assembled packet */
        uint64_t ecpri_hdr_present     : 1;  /**< [ 14: 14](R/W) eCPRI header present in input header buffer and assembled packet */
        uint64_t byte_swap_disable     : 1;  /**< [ 15: 15](R/W) Disables the byte swap toward MHBW. */
        uint64_t reserved_16_23        : 8;
        uint64_t num_sections          : 8;  /**< [ 31: 24](R/W) Number of data sections in the packet. Must be non-zero. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_jdxx_cfg_s cn; */
};
typedef union cavm_ecmp_jdxx_cfg cavm_ecmp_jdxx_cfg_t;

static inline uint64_t CAVM_ECMP_JDXX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_JDXX_CFG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x87e043802000ll + 0x2000ll * ((a) & 0x3);
    __cavm_csr_fatal("ECMP_JDXX_CFG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_JDXX_CFG(a) cavm_ecmp_jdxx_cfg_t
#define bustype_CAVM_ECMP_JDXX_CFG(a) CSR_TYPE_RSL
#define basename_CAVM_ECMP_JDXX_CFG(a) "ECMP_JDXX_CFG"
#define busnum_CAVM_ECMP_JDXX_CFG(a) (a)
#define arguments_CAVM_ECMP_JDXX_CFG(a) (a),-1,-1,-1

/**
 * Register (RSL) ecmp_scratch
 *
 * INTERNAL: Scratch Register
 *
 * Scratch register.
 */
union cavm_ecmp_scratch
{
    uint64_t u;
    struct cavm_ecmp_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ecmp_scratch_s cn; */
};
typedef union cavm_ecmp_scratch cavm_ecmp_scratch_t;

#define CAVM_ECMP_SCRATCH CAVM_ECMP_SCRATCH_FUNC()
static inline uint64_t CAVM_ECMP_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_SCRATCH_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043800020ll;
    __cavm_csr_fatal("ECMP_SCRATCH", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_SCRATCH cavm_ecmp_scratch_t
#define bustype_CAVM_ECMP_SCRATCH CSR_TYPE_RSL
#define basename_CAVM_ECMP_SCRATCH "ECMP_SCRATCH"
#define busnum_CAVM_ECMP_SCRATCH 0
#define arguments_CAVM_ECMP_SCRATCH -1,-1,-1,-1

/**
 * Register (RSL) ecmp_status
 *
 * ECMP Status Register
 */
union cavm_ecmp_status
{
    uint64_t u;
    struct cavm_ecmp_status_s
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
    /* struct cavm_ecmp_status_s cn; */
};
typedef union cavm_ecmp_status cavm_ecmp_status_t;

#define CAVM_ECMP_STATUS CAVM_ECMP_STATUS_FUNC()
static inline uint64_t CAVM_ECMP_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ECMP_STATUS_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e043800018ll;
    __cavm_csr_fatal("ECMP_STATUS", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ECMP_STATUS cavm_ecmp_status_t
#define bustype_CAVM_ECMP_STATUS CSR_TYPE_RSL
#define basename_CAVM_ECMP_STATUS "ECMP_STATUS"
#define busnum_CAVM_ECMP_STATUS 0
#define arguments_CAVM_ECMP_STATUS -1,-1,-1,-1

#endif /* __CAVM_CSRS_ECMP_H__ */
