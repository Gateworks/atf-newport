#ifndef __CAVM_CSRS_PNB_H__
#define __CAVM_CSRS_PNB_H__
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
 * OcteonTX PNB.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) pnb#_ap_push_arb_wt
 *
 * PNB AP Core Push Arbitration Weight Register
 * This register specifies the arbitration weights for AP core requests to
 * SMEM. The same weight is used for both reads and writes. All requests use
 * either the high or low-priority weight depending on the setting of
 * PNB()_CONFIG[AP_REQ_PRIORITY].
 */
union cavm_pnbx_ap_push_arb_wt
{
    uint64_t u;
    struct cavm_pnbx_ap_push_arb_wt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_22_63        : 42;
        uint64_t hp_wgt                : 6;  /**< [ 21: 16](R/W) Arbitration weight when AP Core requests have high priority. */
        uint64_t reserved_6_15         : 10;
        uint64_t lp_wgt                : 6;  /**< [  5:  0](R/W) Arbitration weight when AP Core requests have low priority. */
#else /* Word 0 - Little Endian */
        uint64_t lp_wgt                : 6;  /**< [  5:  0](R/W) Arbitration weight when AP Core requests have low priority. */
        uint64_t reserved_6_15         : 10;
        uint64_t hp_wgt                : 6;  /**< [ 21: 16](R/W) Arbitration weight when AP Core requests have high priority. */
        uint64_t reserved_22_63        : 42;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_ap_push_arb_wt_s cn; */
};
typedef union cavm_pnbx_ap_push_arb_wt cavm_pnbx_ap_push_arb_wt_t;

static inline uint64_t CAVM_PNBX_AP_PUSH_ARB_WT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_AP_PUSH_ARB_WT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000150ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_AP_PUSH_ARB_WT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_AP_PUSH_ARB_WT(a) cavm_pnbx_ap_push_arb_wt_t
#define bustype_CAVM_PNBX_AP_PUSH_ARB_WT(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_AP_PUSH_ARB_WT(a) "PNBX_AP_PUSH_ARB_WT"
#define busnum_CAVM_PNBX_AP_PUSH_ARB_WT(a) (a)
#define arguments_CAVM_PNBX_AP_PUSH_ARB_WT(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_config
 *
 * PNB Configuration Register
 */
union cavm_pnbx_config
{
    uint64_t u;
    struct cavm_pnbx_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t clken                 : 1;  /**< [  1:  1](R/W) Force the conditional clocking within PNB to be always on. For diagnostic use only. */
        uint64_t ap_req_priority       : 1;  /**< [  0:  0](R/W) Select the priority for SMEM requests from AP cores:
                                                                 0 = Low priority.
                                                                 1 = High priority. */
#else /* Word 0 - Little Endian */
        uint64_t ap_req_priority       : 1;  /**< [  0:  0](R/W) Select the priority for SMEM requests from AP cores:
                                                                 0 = Low priority.
                                                                 1 = High priority. */
        uint64_t clken                 : 1;  /**< [  1:  1](R/W) Force the conditional clocking within PNB to be always on. For diagnostic use only. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_config_s cn; */
};
typedef union cavm_pnbx_config cavm_pnbx_config_t;

static inline uint64_t CAVM_PNBX_CONFIG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_CONFIG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000000ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_CONFIG", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_CONFIG(a) cavm_pnbx_config_t
#define bustype_CAVM_PNBX_CONFIG(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_CONFIG(a) "PNBX_CONFIG"
#define busnum_CAVM_PNBX_CONFIG(a) (a)
#define arguments_CAVM_PNBX_CONFIG(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_dma_strid
 *
 * PNB DMA StreamID Register
 */
union cavm_pnbx_dma_strid
{
    uint64_t u;
    struct cavm_pnbx_dma_strid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t func                  : 8;  /**< [  7:  0](R/W) Bottom bits of the IOVA stream ID for requests from the PNB
                                                                 DMA MHAB. */
#else /* Word 0 - Little Endian */
        uint64_t func                  : 8;  /**< [  7:  0](R/W) Bottom bits of the IOVA stream ID for requests from the PNB
                                                                 DMA MHAB. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_dma_strid_s cn; */
};
typedef union cavm_pnbx_dma_strid cavm_pnbx_dma_strid_t;

static inline uint64_t CAVM_PNBX_DMA_STRID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_DMA_STRID(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000318ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_DMA_STRID", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_DMA_STRID(a) cavm_pnbx_dma_strid_t
#define bustype_CAVM_PNBX_DMA_STRID(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_DMA_STRID(a) "PNBX_DMA_STRID"
#define busnum_CAVM_PNBX_DMA_STRID(a) (a)
#define arguments_CAVM_PNBX_DMA_STRID(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_eco
 *
 * INTERNAL: PNB ECO Register
 *
 * An ECO CSR.
 */
union cavm_pnbx_eco
{
    uint64_t u;
    struct cavm_pnbx_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_eco_s cn; */
};
typedef union cavm_pnbx_eco cavm_pnbx_eco_t;

static inline uint64_t CAVM_PNBX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_ECO(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000300ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_ECO", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_ECO(a) cavm_pnbx_eco_t
#define bustype_CAVM_PNBX_ECO(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_ECO(a) "PNBX_ECO"
#define busnum_CAVM_PNBX_ECO(a) (a)
#define arguments_CAVM_PNBX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_eco_scratch
 *
 * INTERNAL: PNB Scratch Register
 */
union cavm_pnbx_eco_scratch
{
    uint64_t u;
    struct cavm_pnbx_eco_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t scratch               : 64; /**< [ 63:  0](R/W)  */
#else /* Word 0 - Little Endian */
        uint64_t scratch               : 64; /**< [ 63:  0](R/W)  */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_eco_scratch_s cn; */
};
typedef union cavm_pnbx_eco_scratch cavm_pnbx_eco_scratch_t;

static inline uint64_t CAVM_PNBX_ECO_SCRATCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_ECO_SCRATCH(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000308ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_ECO_SCRATCH", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_ECO_SCRATCH(a) cavm_pnbx_eco_scratch_t
#define bustype_CAVM_PNBX_ECO_SCRATCH(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_ECO_SCRATCH(a) "PNBX_ECO_SCRATCH"
#define busnum_CAVM_PNBX_ECO_SCRATCH(a) (a)
#define arguments_CAVM_PNBX_ECO_SCRATCH(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_ghab#_pull_arb_wt
 *
 * PNB GHAB Read Pull Arbitration Weight Register
 * This register specifies the arbitration weights used when accepting GHAB
 * requests to system memory. Each GHAB specifies one weight for high
 * priority reads and writes, and one weight for low-priority reads and
 * writes.
 */
union cavm_pnbx_ghabx_pull_arb_wt
{
    uint64_t u;
    struct cavm_pnbx_ghabx_pull_arb_wt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_22_63        : 42;
        uint64_t hp_wgt                : 6;  /**< [ 21: 16](R/W) Arbitration weight for high-priority reads and writes. */
        uint64_t reserved_6_15         : 10;
        uint64_t lp_wgt                : 6;  /**< [  5:  0](R/W) Arbitration weight for low-priority reads and writes. */
#else /* Word 0 - Little Endian */
        uint64_t lp_wgt                : 6;  /**< [  5:  0](R/W) Arbitration weight for low-priority reads and writes. */
        uint64_t reserved_6_15         : 10;
        uint64_t hp_wgt                : 6;  /**< [ 21: 16](R/W) Arbitration weight for high-priority reads and writes. */
        uint64_t reserved_22_63        : 42;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_ghabx_pull_arb_wt_s cn; */
};
typedef union cavm_pnbx_ghabx_pull_arb_wt cavm_pnbx_ghabx_pull_arb_wt_t;

static inline uint64_t CAVM_PNBX_GHABX_PULL_ARB_WT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_GHABX_PULL_ARB_WT(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=7)))
        return 0x87e041000100ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0x7);
    __cavm_csr_fatal("PNBX_GHABX_PULL_ARB_WT", 2, a, b, 0, 0);
}

#define typedef_CAVM_PNBX_GHABX_PULL_ARB_WT(a,b) cavm_pnbx_ghabx_pull_arb_wt_t
#define bustype_CAVM_PNBX_GHABX_PULL_ARB_WT(a,b) CSR_TYPE_RSL
#define basename_CAVM_PNBX_GHABX_PULL_ARB_WT(a,b) "PNBX_GHABX_PULL_ARB_WT"
#define busnum_CAVM_PNBX_GHABX_PULL_ARB_WT(a,b) (a)
#define arguments_CAVM_PNBX_GHABX_PULL_ARB_WT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pnb#_ghab_inb_arb_wt
 *
 * PNB GHAB Inbound Arbitration Weight Register
 * This register specifies the arbitration weights used when arbitrating
 * between PNBD DMA requests and GHAB requests to system memory.
 */
union cavm_pnbx_ghab_inb_arb_wt
{
    uint64_t u;
    struct cavm_pnbx_ghab_inb_arb_wt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t hp_wr_wgt             : 6;  /**< [ 53: 48](R/W) Arbitration weight for high-priority writes. */
        uint64_t reserved_38_47        : 10;
        uint64_t lp_wr_wgt             : 6;  /**< [ 37: 32](R/W) Arbitration weight for low-priority writes. */
        uint64_t reserved_22_31        : 10;
        uint64_t hp_rd_wgt             : 6;  /**< [ 21: 16](R/W) Arbitration weight for high-priority reads. */
        uint64_t reserved_6_15         : 10;
        uint64_t lp_rd_wgt             : 6;  /**< [  5:  0](R/W) Arbitration weight for low-priority reads. */
#else /* Word 0 - Little Endian */
        uint64_t lp_rd_wgt             : 6;  /**< [  5:  0](R/W) Arbitration weight for low-priority reads. */
        uint64_t reserved_6_15         : 10;
        uint64_t hp_rd_wgt             : 6;  /**< [ 21: 16](R/W) Arbitration weight for high-priority reads. */
        uint64_t reserved_22_31        : 10;
        uint64_t lp_wr_wgt             : 6;  /**< [ 37: 32](R/W) Arbitration weight for low-priority writes. */
        uint64_t reserved_38_47        : 10;
        uint64_t hp_wr_wgt             : 6;  /**< [ 53: 48](R/W) Arbitration weight for high-priority writes. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_ghab_inb_arb_wt_s cn; */
};
typedef union cavm_pnbx_ghab_inb_arb_wt cavm_pnbx_ghab_inb_arb_wt_t;

static inline uint64_t CAVM_PNBX_GHAB_INB_ARB_WT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_GHAB_INB_ARB_WT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000140ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_GHAB_INB_ARB_WT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_GHAB_INB_ARB_WT(a) cavm_pnbx_ghab_inb_arb_wt_t
#define bustype_CAVM_PNBX_GHAB_INB_ARB_WT(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_GHAB_INB_ARB_WT(a) "PNBX_GHAB_INB_ARB_WT"
#define busnum_CAVM_PNBX_GHAB_INB_ARB_WT(a) (a)
#define arguments_CAVM_PNBX_GHAB_INB_ARB_WT(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_ghab_pull_bushog_max
 *
 * PNB GHAB Pull Arbiter Bus-Hog Limit Register
 * This register controls the bus-hog limit when arbitrating for system
 * memory requests coming from the GHABs.
 */
union cavm_pnbx_ghab_pull_bushog_max
{
    uint64_t u;
    struct cavm_pnbx_ghab_pull_bushog_max_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t bushog_max            : 8;  /**< [  7:  0](R/W) The maximum number of consecutive high-priority requests that can win
                                                                 arbitration over a waiting low-priority request. If set to zero, no
                                                                 limit is enforced and low-priority requests might be starved. */
#else /* Word 0 - Little Endian */
        uint64_t bushog_max            : 8;  /**< [  7:  0](R/W) The maximum number of consecutive high-priority requests that can win
                                                                 arbitration over a waiting low-priority request. If set to zero, no
                                                                 limit is enforced and low-priority requests might be starved. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_ghab_pull_bushog_max_s cn; */
};
typedef union cavm_pnbx_ghab_pull_bushog_max cavm_pnbx_ghab_pull_bushog_max_t;

static inline uint64_t CAVM_PNBX_GHAB_PULL_BUSHOG_MAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_GHAB_PULL_BUSHOG_MAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000010ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_GHAB_PULL_BUSHOG_MAX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_GHAB_PULL_BUSHOG_MAX(a) cavm_pnbx_ghab_pull_bushog_max_t
#define bustype_CAVM_PNBX_GHAB_PULL_BUSHOG_MAX(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_GHAB_PULL_BUSHOG_MAX(a) "PNBX_GHAB_PULL_BUSHOG_MAX"
#define busnum_CAVM_PNBX_GHAB_PULL_BUSHOG_MAX(a) (a)
#define arguments_CAVM_PNBX_GHAB_PULL_BUSHOG_MAX(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_inb_arb_bushog_max
 *
 * PNB Inbound Arbiter Bus-Hog Limit Register
 * This register specifies the bus-hog limit when arbitrating between PNBD
 * DMA engine requests and GHAB requests to system memory.
 */
union cavm_pnbx_inb_arb_bushog_max
{
    uint64_t u;
    struct cavm_pnbx_inb_arb_bushog_max_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t bushog_max            : 8;  /**< [  7:  0](R/W) The maximum number of consecutive high-priority requests. */
#else /* Word 0 - Little Endian */
        uint64_t bushog_max            : 8;  /**< [  7:  0](R/W) The maximum number of consecutive high-priority requests. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_inb_arb_bushog_max_s cn; */
};
typedef union cavm_pnbx_inb_arb_bushog_max cavm_pnbx_inb_arb_bushog_max_t;

static inline uint64_t CAVM_PNBX_INB_ARB_BUSHOG_MAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_INB_ARB_BUSHOG_MAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000020ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_INB_ARB_BUSHOG_MAX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_INB_ARB_BUSHOG_MAX(a) cavm_pnbx_inb_arb_bushog_max_t
#define bustype_CAVM_PNBX_INB_ARB_BUSHOG_MAX(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_INB_ARB_BUSHOG_MAX(a) "PNBX_INB_ARB_BUSHOG_MAX"
#define busnum_CAVM_PNBX_INB_ARB_BUSHOG_MAX(a) (a)
#define arguments_CAVM_PNBX_INB_ARB_BUSHOG_MAX(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_mab#_strid
 *
 * PNB MHAB/MDAB StreamID Register
 */
union cavm_pnbx_mabx_strid
{
    uint64_t u;
    struct cavm_pnbx_mabx_strid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t func                  : 8;  /**< [  7:  0](R/W) Bottom bits of the IOVA stream ID for MHAB/MDAB requests. The
                                                                 MHAB/MDAB {a} is encoded as {GHAB\<2:0\>, MAB\<2:0\>}, where MAB\<2:0\> is
                                                                 the MHAB/MDAB index within the GHAB (e.g., 0...4). */
#else /* Word 0 - Little Endian */
        uint64_t func                  : 8;  /**< [  7:  0](R/W) Bottom bits of the IOVA stream ID for MHAB/MDAB requests. The
                                                                 MHAB/MDAB {a} is encoded as {GHAB\<2:0\>, MAB\<2:0\>}, where MAB\<2:0\> is
                                                                 the MHAB/MDAB index within the GHAB (e.g., 0...4). */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_mabx_strid_s cn; */
};
typedef union cavm_pnbx_mabx_strid cavm_pnbx_mabx_strid_t;

static inline uint64_t CAVM_PNBX_MABX_STRID(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_MABX_STRID(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=63)))
        return 0x87e041000400ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0x3f);
    __cavm_csr_fatal("PNBX_MABX_STRID", 2, a, b, 0, 0);
}

#define typedef_CAVM_PNBX_MABX_STRID(a,b) cavm_pnbx_mabx_strid_t
#define bustype_CAVM_PNBX_MABX_STRID(a,b) CSR_TYPE_RSL
#define basename_CAVM_PNBX_MABX_STRID(a,b) "PNBX_MABX_STRID"
#define busnum_CAVM_PNBX_MABX_STRID(a,b) (a)
#define arguments_CAVM_PNBX_MABX_STRID(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pnb#_psm_inb_arb_wt
 *
 * PNB GHAB Inbound Arbitration Weight Register
 * This register specifies the arbitration weights used when arbitrating
 * between PNBD DMA requests and GHAB requests to system memory.
 */
union cavm_pnbx_psm_inb_arb_wt
{
    uint64_t u;
    struct cavm_pnbx_psm_inb_arb_wt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t hp_wr_wgt             : 6;  /**< [ 53: 48](R/W) Arbitration weight for high-priority writes. */
        uint64_t reserved_38_47        : 10;
        uint64_t lp_wr_wgt             : 6;  /**< [ 37: 32](R/W) Arbitration weight for low-priority writes. */
        uint64_t reserved_22_31        : 10;
        uint64_t hp_rd_wgt             : 6;  /**< [ 21: 16](R/W) Arbitration weight for high-priority reads. */
        uint64_t reserved_6_15         : 10;
        uint64_t lp_rd_wgt             : 6;  /**< [  5:  0](R/W) Arbitration weight for low-priority reads. */
#else /* Word 0 - Little Endian */
        uint64_t lp_rd_wgt             : 6;  /**< [  5:  0](R/W) Arbitration weight for low-priority reads. */
        uint64_t reserved_6_15         : 10;
        uint64_t hp_rd_wgt             : 6;  /**< [ 21: 16](R/W) Arbitration weight for high-priority reads. */
        uint64_t reserved_22_31        : 10;
        uint64_t lp_wr_wgt             : 6;  /**< [ 37: 32](R/W) Arbitration weight for low-priority writes. */
        uint64_t reserved_38_47        : 10;
        uint64_t hp_wr_wgt             : 6;  /**< [ 53: 48](R/W) Arbitration weight for high-priority writes. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_psm_inb_arb_wt_s cn; */
};
typedef union cavm_pnbx_psm_inb_arb_wt cavm_pnbx_psm_inb_arb_wt_t;

static inline uint64_t CAVM_PNBX_PSM_INB_ARB_WT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_PSM_INB_ARB_WT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000148ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_PSM_INB_ARB_WT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_PSM_INB_ARB_WT(a) cavm_pnbx_psm_inb_arb_wt_t
#define bustype_CAVM_PNBX_PSM_INB_ARB_WT(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_PSM_INB_ARB_WT(a) "PNBX_PSM_INB_ARB_WT"
#define busnum_CAVM_PNBX_PSM_INB_ARB_WT(a) (a)
#define arguments_CAVM_PNBX_PSM_INB_ARB_WT(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_psm_push_arb_wt
 *
 * PNB PSM Push Arbitration Weight Register
 * This register specifies the arbitration weight for PSM writes to SMEM
 * (from WRSTS commands). Note that PSM writes always have low priority.
 * All PSM requests are sered by PNB0, and the value in
 * PNB(1)_PSM_PUSH_ARB_WT has no significance.
 */
union cavm_pnbx_psm_push_arb_wt
{
    uint64_t u;
    struct cavm_pnbx_psm_push_arb_wt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_22_63        : 42;
        uint64_t hp_wgt                : 6;  /**< [ 21: 16](R/W) TODO
                                                                 Internal:
                                                                 High-priority weight. Unused since PSM writes are always low
                                                                 priority. */
        uint64_t reserved_6_15         : 10;
        uint64_t lp_wgt                : 6;  /**< [  5:  0](R/W) Arbitration weight for PSM writes to SMEM. */
#else /* Word 0 - Little Endian */
        uint64_t lp_wgt                : 6;  /**< [  5:  0](R/W) Arbitration weight for PSM writes to SMEM. */
        uint64_t reserved_6_15         : 10;
        uint64_t hp_wgt                : 6;  /**< [ 21: 16](R/W) TODO
                                                                 Internal:
                                                                 High-priority weight. Unused since PSM writes are always low
                                                                 priority. */
        uint64_t reserved_22_63        : 42;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_psm_push_arb_wt_s cn; */
};
typedef union cavm_pnbx_psm_push_arb_wt cavm_pnbx_psm_push_arb_wt_t;

static inline uint64_t CAVM_PNBX_PSM_PUSH_ARB_WT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_PSM_PUSH_ARB_WT(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000160ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_PSM_PUSH_ARB_WT", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_PSM_PUSH_ARB_WT(a) cavm_pnbx_psm_push_arb_wt_t
#define bustype_CAVM_PNBX_PSM_PUSH_ARB_WT(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_PSM_PUSH_ARB_WT(a) "PNBX_PSM_PUSH_ARB_WT"
#define busnum_CAVM_PNBX_PSM_PUSH_ARB_WT(a) (a)
#define arguments_CAVM_PNBX_PSM_PUSH_ARB_WT(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_psm_strid
 *
 * PNB PSM StreamID Register
 */
union cavm_pnbx_psm_strid
{
    uint64_t u;
    struct cavm_pnbx_psm_strid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t func                  : 8;  /**< [  7:  0](R/W) Bottom bits of the IOVA stream ID for requests from PSM. */
#else /* Word 0 - Little Endian */
        uint64_t func                  : 8;  /**< [  7:  0](R/W) Bottom bits of the IOVA stream ID for requests from PSM. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_psm_strid_s cn; */
};
typedef union cavm_pnbx_psm_strid cavm_pnbx_psm_strid_t;

static inline uint64_t CAVM_PNBX_PSM_STRID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_PSM_STRID(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000310ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_PSM_STRID", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_PSM_STRID(a) cavm_pnbx_psm_strid_t
#define bustype_CAVM_PNBX_PSM_STRID(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_PSM_STRID(a) "PNBX_PSM_STRID"
#define busnum_CAVM_PNBX_PSM_STRID(a) (a)
#define arguments_CAVM_PNBX_PSM_STRID(a) (a),-1,-1,-1

/**
 * Register (RSL) pnb#_smem_push_bushog_max
 *
 * PNB SMEM Push Arbiter Bus-Hog Limit Register
 * This register specifies the bus-hog limit when arbitrating for requests to
 * SMEM from the AP cores, the PNBD DMA engines, and PSM WRSTS requests.
 */
union cavm_pnbx_smem_push_bushog_max
{
    uint64_t u;
    struct cavm_pnbx_smem_push_bushog_max_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t bushog_max            : 8;  /**< [  7:  0](R/W) The maximum number of consecutive high-priority requests. */
#else /* Word 0 - Little Endian */
        uint64_t bushog_max            : 8;  /**< [  7:  0](R/W) The maximum number of consecutive high-priority requests. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_pnbx_smem_push_bushog_max_s cn; */
};
typedef union cavm_pnbx_smem_push_bushog_max cavm_pnbx_smem_push_bushog_max_t;

static inline uint64_t CAVM_PNBX_SMEM_PUSH_BUSHOG_MAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_PNBX_SMEM_PUSH_BUSHOG_MAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e041000018ll + 0x1000000ll * ((a) & 0x1);
    __cavm_csr_fatal("PNBX_SMEM_PUSH_BUSHOG_MAX", 1, a, 0, 0, 0);
}

#define typedef_CAVM_PNBX_SMEM_PUSH_BUSHOG_MAX(a) cavm_pnbx_smem_push_bushog_max_t
#define bustype_CAVM_PNBX_SMEM_PUSH_BUSHOG_MAX(a) CSR_TYPE_RSL
#define basename_CAVM_PNBX_SMEM_PUSH_BUSHOG_MAX(a) "PNBX_SMEM_PUSH_BUSHOG_MAX"
#define busnum_CAVM_PNBX_SMEM_PUSH_BUSHOG_MAX(a) (a)
#define arguments_CAVM_PNBX_SMEM_PUSH_BUSHOG_MAX(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_PNB_H__ */
