#ifndef __CAVM_CSRS_NCBW_H__
#define __CAVM_CSRS_NCBW_H__
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
 * OcteonTX NCBW.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) ncbw_bp_test
 *
 * INTERNAL: NCBW Backpressure Test Register
 */
union cavm_ncbw_bp_test
{
    uint64_t u;
    struct cavm_ncbw_bp_test_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Bit \<63\> limits the NCBO credit return.
                                                                 Bit \<62\> limits the NCBI NP request.
                                                                 Bit \<61\> limits the NCBI P request.
                                                                 Bit \<60\> limits the NCBI CR request. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                 bit \<23:22\> controls NCBO credit return BP.
                                                                 bit \<21:20\> controls NCBI NP request BP.
                                                                 bit \<19:18\> controls NCBI P request BP.
                                                                 bit \<17:16\> controls NCBO CR request BP. */
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
                                                                 bit \<23:22\> controls NCBO credit return BP.
                                                                 bit \<21:20\> controls NCBI NP request BP.
                                                                 bit \<19:18\> controls NCBI P request BP.
                                                                 bit \<17:16\> controls NCBO CR request BP. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 Bit \<63\> limits the NCBO credit return.
                                                                 Bit \<62\> limits the NCBI NP request.
                                                                 Bit \<61\> limits the NCBI P request.
                                                                 Bit \<60\> limits the NCBI CR request. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_bp_test_s cn; */
};
typedef union cavm_ncbw_bp_test cavm_ncbw_bp_test_t;

#define CAVM_NCBW_BP_TEST CAVM_NCBW_BP_TEST_FUNC()
static inline uint64_t CAVM_NCBW_BP_TEST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_BP_TEST_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e040000200ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000200ll;
    __cavm_csr_fatal("NCBW_BP_TEST", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_BP_TEST cavm_ncbw_bp_test_t
#define bustype_CAVM_NCBW_BP_TEST CSR_TYPE_RSL
#define basename_CAVM_NCBW_BP_TEST "NCBW_BP_TEST"
#define busnum_CAVM_NCBW_BP_TEST 0
#define arguments_CAVM_NCBW_BP_TEST -1,-1,-1,-1

/**
 * Register (RSL) ncbw_cfg
 *
 * NCBW Global Configuration Register
 */
union cavm_ncbw_cfg
{
    uint64_t u;
    struct cavm_ncbw_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t ncbo_rsp_dbg_sel      : 2;  /**< [  9:  8](R/W/H) dbg3 mux select for device[2:0] read and write response. */
        uint64_t mio_timestp_tick      : 4;  /**< [  7:  4](R/W/H) MIO timestamp tick clock. This field specifies the number of ticks in
                                                                 system clock to sample the timestamp value and pass the timestamp value
                                                                 into the BPHY clock domain. The default is to sample once every four system clocks.
                                                                 Setting this field to 1 will sample the timestamp every system clock until
                                                                 an internal 8-entry FIFO is full.
                                                                 Setting this field to 0 will sample the timestamp every 16th system clock. */
        uint64_t reserved_2_3          : 2;
        uint64_t rst_flush             : 1;  /**< [  1:  1](R/W/H) Set one to flush incoming requests from all BPHY devices and to put NCBO requests
                                                                 in bypass mode. For BPHY reset only. */
        uint64_t wgt_clken             : 1;  /**< [  0:  0](R/W) Force the conditional clocking for NCBW itself. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t wgt_clken             : 1;  /**< [  0:  0](R/W) Force the conditional clocking for NCBW itself. For diagnostic use only. */
        uint64_t rst_flush             : 1;  /**< [  1:  1](R/W/H) Set one to flush incoming requests from all BPHY devices and to put NCBO requests
                                                                 in bypass mode. For BPHY reset only. */
        uint64_t reserved_2_3          : 2;
        uint64_t mio_timestp_tick      : 4;  /**< [  7:  4](R/W/H) MIO timestamp tick clock. This field specifies the number of ticks in
                                                                 system clock to sample the timestamp value and pass the timestamp value
                                                                 into the BPHY clock domain. The default is to sample once every four system clocks.
                                                                 Setting this field to 1 will sample the timestamp every system clock until
                                                                 an internal 8-entry FIFO is full.
                                                                 Setting this field to 0 will sample the timestamp every 16th system clock. */
        uint64_t ncbo_rsp_dbg_sel      : 2;  /**< [  9:  8](R/W/H) dbg3 mux select for device[2:0] read and write response. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_cfg_s cn; */
};
typedef union cavm_ncbw_cfg cavm_ncbw_cfg_t;

#define CAVM_NCBW_CFG CAVM_NCBW_CFG_FUNC()
static inline uint64_t CAVM_NCBW_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_CFG_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e040000000ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000000ll;
    __cavm_csr_fatal("NCBW_CFG", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_CFG cavm_ncbw_cfg_t
#define bustype_CAVM_NCBW_CFG CSR_TYPE_RSL
#define basename_CAVM_NCBW_CFG "NCBW_CFG"
#define busnum_CAVM_NCBW_CFG 0
#define arguments_CAVM_NCBW_CFG -1,-1,-1,-1

/**
 * Register (RSL) ncbw_eco
 *
 * INTERNAL: NCBW ECO Register
 */
union cavm_ncbw_eco
{
    uint64_t u;
    struct cavm_ncbw_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) TODO
                                                                 Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) TODO
                                                                 Internal:
                                                                 Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_eco_s cn; */
};
typedef union cavm_ncbw_eco cavm_ncbw_eco_t;

#define CAVM_NCBW_ECO CAVM_NCBW_ECO_FUNC()
static inline uint64_t CAVM_NCBW_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_ECO_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e040000100ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000100ll;
    __cavm_csr_fatal("NCBW_ECO", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_ECO cavm_ncbw_eco_t
#define bustype_CAVM_NCBW_ECO CSR_TYPE_RSL
#define basename_CAVM_NCBW_ECO "NCBW_ECO"
#define busnum_CAVM_NCBW_ECO 0
#define arguments_CAVM_NCBW_ECO -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbi_debug0
 *
 * INTERNAL: NCBW NCBI Debug Register 0
 */
union cavm_ncbw_ncbi_debug0
{
    uint64_t u;
    struct cavm_ncbw_ncbi_debug0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbi_dev0_pr_cnt      : 32; /**< [ 63: 32](RO/H) Device 0 to NCBW write command count. */
        uint64_t ncbi_dev0_npr_cnt     : 32; /**< [ 31:  0](RO/H) Device 0 to NCBW read command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_dev0_npr_cnt     : 32; /**< [ 31:  0](RO/H) Device 0 to NCBW read command count. */
        uint64_t ncbi_dev0_pr_cnt      : 32; /**< [ 63: 32](RO/H) Device 0 to NCBW write command count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbi_debug0_s cn; */
};
typedef union cavm_ncbw_ncbi_debug0 cavm_ncbw_ncbi_debug0_t;

#define CAVM_NCBW_NCBI_DEBUG0 CAVM_NCBW_NCBI_DEBUG0_FUNC()
static inline uint64_t CAVM_NCBW_NCBI_DEBUG0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBI_DEBUG0_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000080ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000080ll;
    __cavm_csr_fatal("NCBW_NCBI_DEBUG0", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBI_DEBUG0 cavm_ncbw_ncbi_debug0_t
#define bustype_CAVM_NCBW_NCBI_DEBUG0 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBI_DEBUG0 "NCBW_NCBI_DEBUG0"
#define busnum_CAVM_NCBW_NCBI_DEBUG0 0
#define arguments_CAVM_NCBW_NCBI_DEBUG0 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbi_debug1
 *
 * INTERNAL: NCBW NCBI Debug Register 1
 */
union cavm_ncbw_ncbi_debug1
{
    uint64_t u;
    struct cavm_ncbw_ncbi_debug1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbi_dev1_pr_cnt      : 32; /**< [ 63: 32](RO/H) Device 1 to NCBW write command count. */
        uint64_t ncbi_dev1_npr_cnt     : 32; /**< [ 31:  0](RO/H) Device 1 to NCBW read command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_dev1_npr_cnt     : 32; /**< [ 31:  0](RO/H) Device 1 to NCBW read command count. */
        uint64_t ncbi_dev1_pr_cnt      : 32; /**< [ 63: 32](RO/H) Device 1 to NCBW write command count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbi_debug1_s cn; */
};
typedef union cavm_ncbw_ncbi_debug1 cavm_ncbw_ncbi_debug1_t;

#define CAVM_NCBW_NCBI_DEBUG1 CAVM_NCBW_NCBI_DEBUG1_FUNC()
static inline uint64_t CAVM_NCBW_NCBI_DEBUG1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBI_DEBUG1_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000088ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000088ll;
    __cavm_csr_fatal("NCBW_NCBI_DEBUG1", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBI_DEBUG1 cavm_ncbw_ncbi_debug1_t
#define bustype_CAVM_NCBW_NCBI_DEBUG1 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBI_DEBUG1 "NCBW_NCBI_DEBUG1"
#define busnum_CAVM_NCBW_NCBI_DEBUG1 0
#define arguments_CAVM_NCBW_NCBI_DEBUG1 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbi_debug2
 *
 * INTERNAL: NCBW NCBI Debug Register 2
 */
union cavm_ncbw_ncbi_debug2
{
    uint64_t u;
    struct cavm_ncbw_ncbi_debug2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbi_dev2_pr_cnt      : 32; /**< [ 63: 32](RO/H) Device 2 to NCBW write command count. */
        uint64_t ncbi_dev2_npr_cnt     : 32; /**< [ 31:  0](RO/H) Device 2 to NCBW read command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_dev2_npr_cnt     : 32; /**< [ 31:  0](RO/H) Device 2 to NCBW read command count. */
        uint64_t ncbi_dev2_pr_cnt      : 32; /**< [ 63: 32](RO/H) Device 2 to NCBW write command count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbi_debug2_s cn; */
};
typedef union cavm_ncbw_ncbi_debug2 cavm_ncbw_ncbi_debug2_t;

#define CAVM_NCBW_NCBI_DEBUG2 CAVM_NCBW_NCBI_DEBUG2_FUNC()
static inline uint64_t CAVM_NCBW_NCBI_DEBUG2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBI_DEBUG2_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000090ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000090ll;
    __cavm_csr_fatal("NCBW_NCBI_DEBUG2", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBI_DEBUG2 cavm_ncbw_ncbi_debug2_t
#define bustype_CAVM_NCBW_NCBI_DEBUG2 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBI_DEBUG2 "NCBW_NCBI_DEBUG2"
#define busnum_CAVM_NCBW_NCBI_DEBUG2 0
#define arguments_CAVM_NCBW_NCBI_DEBUG2 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbi_debug3
 *
 * INTERNAL: NCBW NCBI Debug Register 3
 */
union cavm_ncbw_ncbi_debug3
{
    uint64_t u;
    struct cavm_ncbw_ncbi_debug3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbi_dev0_cdt_cnt     : 32; /**< [ 63: 32](RO/H) NCBW to Device 0 credit return count. */
        uint64_t ncbi_dev0_cr_cnt      : 32; /**< [ 31:  0](RO/H) Device 0 to NCBW write command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_dev0_cr_cnt      : 32; /**< [ 31:  0](RO/H) Device 0 to NCBW write command count. */
        uint64_t ncbi_dev0_cdt_cnt     : 32; /**< [ 63: 32](RO/H) NCBW to Device 0 credit return count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbi_debug3_s cn; */
};
typedef union cavm_ncbw_ncbi_debug3 cavm_ncbw_ncbi_debug3_t;

#define CAVM_NCBW_NCBI_DEBUG3 CAVM_NCBW_NCBI_DEBUG3_FUNC()
static inline uint64_t CAVM_NCBW_NCBI_DEBUG3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBI_DEBUG3_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000098ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000098ll;
    __cavm_csr_fatal("NCBW_NCBI_DEBUG3", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBI_DEBUG3 cavm_ncbw_ncbi_debug3_t
#define bustype_CAVM_NCBW_NCBI_DEBUG3 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBI_DEBUG3 "NCBW_NCBI_DEBUG3"
#define busnum_CAVM_NCBW_NCBI_DEBUG3 0
#define arguments_CAVM_NCBW_NCBI_DEBUG3 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbi_debug4
 *
 * INTERNAL: NCBW NCBI Debug Register 4
 */
union cavm_ncbw_ncbi_debug4
{
    uint64_t u;
    struct cavm_ncbw_ncbi_debug4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbi_dev1_cdt_cnt     : 32; /**< [ 63: 32](RO/H) NCBW to Device 1 credit return count. */
        uint64_t ncbi_dev1_cr_cnt      : 32; /**< [ 31:  0](RO/H) Device 1 to NCBW write command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_dev1_cr_cnt      : 32; /**< [ 31:  0](RO/H) Device 1 to NCBW write command count. */
        uint64_t ncbi_dev1_cdt_cnt     : 32; /**< [ 63: 32](RO/H) NCBW to Device 1 credit return count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbi_debug4_s cn; */
};
typedef union cavm_ncbw_ncbi_debug4 cavm_ncbw_ncbi_debug4_t;

#define CAVM_NCBW_NCBI_DEBUG4 CAVM_NCBW_NCBI_DEBUG4_FUNC()
static inline uint64_t CAVM_NCBW_NCBI_DEBUG4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBI_DEBUG4_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e0400000a0ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e0400000a0ll;
    __cavm_csr_fatal("NCBW_NCBI_DEBUG4", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBI_DEBUG4 cavm_ncbw_ncbi_debug4_t
#define bustype_CAVM_NCBW_NCBI_DEBUG4 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBI_DEBUG4 "NCBW_NCBI_DEBUG4"
#define busnum_CAVM_NCBW_NCBI_DEBUG4 0
#define arguments_CAVM_NCBW_NCBI_DEBUG4 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbi_debug5
 *
 * INTERNAL: NCBW NCBI Debug Register 5
 */
union cavm_ncbw_ncbi_debug5
{
    uint64_t u;
    struct cavm_ncbw_ncbi_debug5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbi_dev2_cdt_cnt     : 32; /**< [ 63: 32](RO/H) NCBW to Device 2 credit return count. */
        uint64_t ncbi_dev2_cr_cnt      : 32; /**< [ 31:  0](RO/H) Device 2 to NCBW write command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_dev2_cr_cnt      : 32; /**< [ 31:  0](RO/H) Device 2 to NCBW write command count. */
        uint64_t ncbi_dev2_cdt_cnt     : 32; /**< [ 63: 32](RO/H) NCBW to Device 2 credit return count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbi_debug5_s cn; */
};
typedef union cavm_ncbw_ncbi_debug5 cavm_ncbw_ncbi_debug5_t;

#define CAVM_NCBW_NCBI_DEBUG5 CAVM_NCBW_NCBI_DEBUG5_FUNC()
static inline uint64_t CAVM_NCBW_NCBI_DEBUG5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBI_DEBUG5_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e0400000a8ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e0400000a8ll;
    __cavm_csr_fatal("NCBW_NCBI_DEBUG5", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBI_DEBUG5 cavm_ncbw_ncbi_debug5_t
#define bustype_CAVM_NCBW_NCBI_DEBUG5 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBI_DEBUG5 "NCBW_NCBI_DEBUG5"
#define busnum_CAVM_NCBW_NCBI_DEBUG5 0
#define arguments_CAVM_NCBW_NCBI_DEBUG5 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug
 *
 * INTERNAL: NCBW NCBO Debug Register
 */
union cavm_ncbw_ncbo_debug
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbo_cdt_cnt          : 32; /**< [ 63: 32](RO/H) NCBW to NCBO return credit count. */
        uint64_t ncbo_req_cnt          : 32; /**< [ 31:  0](RO/H) NCBO to NCBW request count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_req_cnt          : 32; /**< [ 31:  0](RO/H) NCBO to NCBW request count. */
        uint64_t ncbo_cdt_cnt          : 32; /**< [ 63: 32](RO/H) NCBW to NCBO return credit count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug_s cn; */
};
typedef union cavm_ncbw_ncbo_debug cavm_ncbw_ncbo_debug_t;

#define CAVM_NCBW_NCBO_DEBUG CAVM_NCBW_NCBO_DEBUG_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e040000020ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000020ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG cavm_ncbw_ncbo_debug_t
#define bustype_CAVM_NCBW_NCBO_DEBUG CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG "NCBW_NCBO_DEBUG"
#define busnum_CAVM_NCBW_NCBO_DEBUG 0
#define arguments_CAVM_NCBW_NCBO_DEBUG -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug1
 *
 * INTERNAL: NCBW NCBO Debug Register 1
 */
union cavm_ncbw_ncbo_debug1
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbo_npr_cnt          : 32; /**< [ 63: 32](RO/H) NCBO to NCBW read command count. */
        uint64_t ncbo_pr_cnt           : 32; /**< [ 31:  0](RO/H) NCBO to NCBW write command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_pr_cnt           : 32; /**< [ 31:  0](RO/H) NCBO to NCBW write command count. */
        uint64_t ncbo_npr_cnt          : 32; /**< [ 63: 32](RO/H) NCBO to NCBW read command count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug1_s cn; */
};
typedef union cavm_ncbw_ncbo_debug1 cavm_ncbw_ncbo_debug1_t;

#define CAVM_NCBW_NCBO_DEBUG1 CAVM_NCBW_NCBO_DEBUG1_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG1_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000028ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000028ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG1", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG1 cavm_ncbw_ncbo_debug1_t
#define bustype_CAVM_NCBW_NCBO_DEBUG1 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG1 "NCBW_NCBO_DEBUG1"
#define busnum_CAVM_NCBW_NCBO_DEBUG1 0
#define arguments_CAVM_NCBW_NCBO_DEBUG1 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug2
 *
 * INTERNAL: NCBW NCBO Debug Register 2
 */
union cavm_ncbw_ncbo_debug2
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t ncbo_cr_cnt           : 32; /**< [ 31:  0](RO/H) NCBO to NCBW completion command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_cr_cnt           : 32; /**< [ 31:  0](RO/H) NCBO to NCBW completion command count. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug2_s cn; */
};
typedef union cavm_ncbw_ncbo_debug2 cavm_ncbw_ncbo_debug2_t;

#define CAVM_NCBW_NCBO_DEBUG2 CAVM_NCBW_NCBO_DEBUG2_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG2_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000030ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000030ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG2", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG2 cavm_ncbw_ncbo_debug2_t
#define bustype_CAVM_NCBW_NCBO_DEBUG2 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG2 "NCBW_NCBO_DEBUG2"
#define busnum_CAVM_NCBW_NCBO_DEBUG2 0
#define arguments_CAVM_NCBW_NCBO_DEBUG2 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug3
 *
 * INTERNAL: NCBW NCBO Debug Register 3
 */
union cavm_ncbw_ncbo_debug3
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbo_unsup_cnt        : 32; /**< [ 63: 32](RO/H) NCBO to NCBW unsupported command count. */
        uint64_t ncbo_ldbyp_cnt        : 32; /**< [ 31:  0](RO/H) NCBO to NCBW IOBLDx command count during reset flush. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_ldbyp_cnt        : 32; /**< [ 31:  0](RO/H) NCBO to NCBW IOBLDx command count during reset flush. */
        uint64_t ncbo_unsup_cnt        : 32; /**< [ 63: 32](RO/H) NCBO to NCBW unsupported command count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug3_s cn; */
};
typedef union cavm_ncbw_ncbo_debug3 cavm_ncbw_ncbo_debug3_t;

#define CAVM_NCBW_NCBO_DEBUG3 CAVM_NCBW_NCBO_DEBUG3_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG3_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000038ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000038ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG3", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG3 cavm_ncbw_ncbo_debug3_t
#define bustype_CAVM_NCBW_NCBO_DEBUG3 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG3 "NCBW_NCBO_DEBUG3"
#define busnum_CAVM_NCBW_NCBO_DEBUG3 0
#define arguments_CAVM_NCBW_NCBO_DEBUG3 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug4
 *
 * INTERNAL: NCBW NCBO Debug Register 4
 */
union cavm_ncbw_ncbo_debug4
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbo_dev0_cdt_cnt     : 32; /**< [ 63: 32](RO/H) Device 0 to NCBW credit return count. */
        uint64_t ncbo_dev0_req_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 0 request command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_dev0_req_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 0 request command count. */
        uint64_t ncbo_dev0_cdt_cnt     : 32; /**< [ 63: 32](RO/H) Device 0 to NCBW credit return count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug4_s cn; */
};
typedef union cavm_ncbw_ncbo_debug4 cavm_ncbw_ncbo_debug4_t;

#define CAVM_NCBW_NCBO_DEBUG4 CAVM_NCBW_NCBO_DEBUG4_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG4_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000040ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000040ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG4", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG4 cavm_ncbw_ncbo_debug4_t
#define bustype_CAVM_NCBW_NCBO_DEBUG4 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG4 "NCBW_NCBO_DEBUG4"
#define busnum_CAVM_NCBW_NCBO_DEBUG4 0
#define arguments_CAVM_NCBW_NCBO_DEBUG4 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug5
 *
 * INTERNAL: NCBW NCBO Debug Register 5
 */
union cavm_ncbw_ncbo_debug5
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbo_dev1_cdt_cnt     : 32; /**< [ 63: 32](RO/H) Device 1 to NCBW credit return count. */
        uint64_t ncbo_dev1_req_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 1 request command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_dev1_req_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 1 request command count. */
        uint64_t ncbo_dev1_cdt_cnt     : 32; /**< [ 63: 32](RO/H) Device 1 to NCBW credit return count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug5_s cn; */
};
typedef union cavm_ncbw_ncbo_debug5 cavm_ncbw_ncbo_debug5_t;

#define CAVM_NCBW_NCBO_DEBUG5 CAVM_NCBW_NCBO_DEBUG5_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG5_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000048ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000048ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG5", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG5 cavm_ncbw_ncbo_debug5_t
#define bustype_CAVM_NCBW_NCBO_DEBUG5 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG5 "NCBW_NCBO_DEBUG5"
#define busnum_CAVM_NCBW_NCBO_DEBUG5 0
#define arguments_CAVM_NCBW_NCBO_DEBUG5 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug6
 *
 * INTERNAL: NCBW NCBO Debug Register 6
 */
union cavm_ncbw_ncbo_debug6
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbo_dev2_cdt_cnt     : 32; /**< [ 63: 32](RO/H) Device 2 to NCBW credit return count. */
        uint64_t ncbo_dev2_req_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 2 request command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_dev2_req_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 2 request command count. */
        uint64_t ncbo_dev2_cdt_cnt     : 32; /**< [ 63: 32](RO/H) Device 2 to NCBW credit return count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug6_s cn; */
};
typedef union cavm_ncbw_ncbo_debug6 cavm_ncbw_ncbo_debug6_t;

#define CAVM_NCBW_NCBO_DEBUG6 CAVM_NCBW_NCBO_DEBUG6_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG6_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000050ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000050ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG6", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG6 cavm_ncbw_ncbo_debug6_t
#define bustype_CAVM_NCBW_NCBO_DEBUG6 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG6 "NCBW_NCBO_DEBUG6"
#define busnum_CAVM_NCBW_NCBO_DEBUG6 0
#define arguments_CAVM_NCBW_NCBO_DEBUG6 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug7
 *
 * INTERNAL: NCBW NCBO Debug Register 7
 */
union cavm_ncbw_ncbo_debug7
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbo_dev0_pr_cnt      : 32; /**< [ 63: 32](RO/H) NCBW to Device 0 write command count. */
        uint64_t ncbo_dev0_npr_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 0 read command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_dev0_npr_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 0 read command count. */
        uint64_t ncbo_dev0_pr_cnt      : 32; /**< [ 63: 32](RO/H) NCBW to Device 0 write command count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug7_s cn; */
};
typedef union cavm_ncbw_ncbo_debug7 cavm_ncbw_ncbo_debug7_t;

#define CAVM_NCBW_NCBO_DEBUG7 CAVM_NCBW_NCBO_DEBUG7_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG7_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000058ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000058ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG7", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG7 cavm_ncbw_ncbo_debug7_t
#define bustype_CAVM_NCBW_NCBO_DEBUG7 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG7 "NCBW_NCBO_DEBUG7"
#define busnum_CAVM_NCBW_NCBO_DEBUG7 0
#define arguments_CAVM_NCBW_NCBO_DEBUG7 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug8
 *
 * INTERNAL: NCBW NCBO Debug Register 8
 */
union cavm_ncbw_ncbo_debug8
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbo_dev1_pr_cnt      : 32; /**< [ 63: 32](RO/H) NCBW to Device 1 write command count. */
        uint64_t ncbo_dev1_npr_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 1 read command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_dev1_npr_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 1 read command count. */
        uint64_t ncbo_dev1_pr_cnt      : 32; /**< [ 63: 32](RO/H) NCBW to Device 1 write command count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug8_s cn; */
};
typedef union cavm_ncbw_ncbo_debug8 cavm_ncbw_ncbo_debug8_t;

#define CAVM_NCBW_NCBO_DEBUG8 CAVM_NCBW_NCBO_DEBUG8_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG8_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG8_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000060ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000060ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG8", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG8 cavm_ncbw_ncbo_debug8_t
#define bustype_CAVM_NCBW_NCBO_DEBUG8 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG8 "NCBW_NCBO_DEBUG8"
#define busnum_CAVM_NCBW_NCBO_DEBUG8 0
#define arguments_CAVM_NCBW_NCBO_DEBUG8 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_ncbo_debug9
 *
 * INTERNAL: NCBW NCBO Debug Register 9
 */
union cavm_ncbw_ncbo_debug9
{
    uint64_t u;
    struct cavm_ncbw_ncbo_debug9_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ncbo_dev2_pr_cnt      : 32; /**< [ 63: 32](RO/H) NCBW to Device 2 write command count. */
        uint64_t ncbo_dev2_npr_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 2 read command count. */
#else /* Word 0 - Little Endian */
        uint64_t ncbo_dev2_npr_cnt     : 32; /**< [ 31:  0](RO/H) NCBW to Device 2 read command count. */
        uint64_t ncbo_dev2_pr_cnt      : 32; /**< [ 63: 32](RO/H) NCBW to Device 2 write command count. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_ncbo_debug9_s cn; */
};
typedef union cavm_ncbw_ncbo_debug9 cavm_ncbw_ncbo_debug9_t;

#define CAVM_NCBW_NCBO_DEBUG9 CAVM_NCBW_NCBO_DEBUG9_FUNC()
static inline uint64_t CAVM_NCBW_NCBO_DEBUG9_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_NCBO_DEBUG9_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX_PASS2_X))
        return 0x87e040000068ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000068ll;
    __cavm_csr_fatal("NCBW_NCBO_DEBUG9", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_NCBO_DEBUG9 cavm_ncbw_ncbo_debug9_t
#define bustype_CAVM_NCBW_NCBO_DEBUG9 CSR_TYPE_RSL
#define basename_CAVM_NCBW_NCBO_DEBUG9 "NCBW_NCBO_DEBUG9"
#define busnum_CAVM_NCBW_NCBO_DEBUG9 0
#define arguments_CAVM_NCBW_NCBO_DEBUG9 -1,-1,-1,-1

/**
 * Register (RSL) ncbw_scratch
 *
 * INTERNAL: NCBW Scratch Register
 */
union cavm_ncbw_scratch
{
    uint64_t u;
    struct cavm_ncbw_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t scratch               : 64; /**< [ 63:  0](R/W) TODO */
#else /* Word 0 - Little Endian */
        uint64_t scratch               : 64; /**< [ 63:  0](R/W) TODO */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_scratch_s cn; */
};
typedef union cavm_ncbw_scratch cavm_ncbw_scratch_t;

#define CAVM_NCBW_SCRATCH CAVM_NCBW_SCRATCH_FUNC()
static inline uint64_t CAVM_NCBW_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_SCRATCH_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e040000108ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000108ll;
    __cavm_csr_fatal("NCBW_SCRATCH", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_SCRATCH cavm_ncbw_scratch_t
#define bustype_CAVM_NCBW_SCRATCH CSR_TYPE_RSL
#define basename_CAVM_NCBW_SCRATCH "NCBW_SCRATCH"
#define busnum_CAVM_NCBW_SCRATCH 0
#define arguments_CAVM_NCBW_SCRATCH -1,-1,-1,-1

/**
 * Register (RSL) ncbw_status
 *
 * NCBW Global Status Register
 */
union cavm_ncbw_status
{
    uint64_t u;
    struct cavm_ncbw_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t bphy_freq_changing    : 1;  /**< [  8:  8](RO/H) BPHY-PLL is changing frequency when set to one. */
        uint64_t reserved_5_7          : 3;
        uint64_t ncbw_flush_done       : 1;  /**< [  4:  4](RO/H) NCBW reset flush done. It is set by hardware when SSO, NPA, NCBI, and NCBO reset
                                                                 flush are done. */
        uint64_t sso_flush_done        : 1;  /**< [  3:  3](RO/H) SSO interface flush done when set to one. For BPHY reset only. */
        uint64_t npa_flush_done        : 1;  /**< [  2:  2](RO/H) NPA interface flush done when set to one. For BPHY reset only. */
        uint64_t ncbo_flush_done       : 1;  /**< [  1:  1](RO/H) NCBO interface flush done when set to one. For BPHY reset only. */
        uint64_t ncbi_flush_done       : 1;  /**< [  0:  0](RO/H) NCBI interface flush done when set to one. For BPHY reset only. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_flush_done       : 1;  /**< [  0:  0](RO/H) NCBI interface flush done when set to one. For BPHY reset only. */
        uint64_t ncbo_flush_done       : 1;  /**< [  1:  1](RO/H) NCBO interface flush done when set to one. For BPHY reset only. */
        uint64_t npa_flush_done        : 1;  /**< [  2:  2](RO/H) NPA interface flush done when set to one. For BPHY reset only. */
        uint64_t sso_flush_done        : 1;  /**< [  3:  3](RO/H) SSO interface flush done when set to one. For BPHY reset only. */
        uint64_t ncbw_flush_done       : 1;  /**< [  4:  4](RO/H) NCBW reset flush done. It is set by hardware when SSO, NPA, NCBI, and NCBO reset
                                                                 flush are done. */
        uint64_t reserved_5_7          : 3;
        uint64_t bphy_freq_changing    : 1;  /**< [  8:  8](RO/H) BPHY-PLL is changing frequency when set to one. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_ncbw_status_s cn; */
};
typedef union cavm_ncbw_status cavm_ncbw_status_t;

#define CAVM_NCBW_STATUS CAVM_NCBW_STATUS_FUNC()
static inline uint64_t CAVM_NCBW_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_NCBW_STATUS_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CNF95XX))
        return 0x87e040000008ll;
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e040000008ll;
    __cavm_csr_fatal("NCBW_STATUS", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_NCBW_STATUS cavm_ncbw_status_t
#define bustype_CAVM_NCBW_STATUS CSR_TYPE_RSL
#define basename_CAVM_NCBW_STATUS "NCBW_STATUS"
#define busnum_CAVM_NCBW_STATUS 0
#define arguments_CAVM_NCBW_STATUS -1,-1,-1,-1

#endif /* __CAVM_CSRS_NCBW_H__ */
