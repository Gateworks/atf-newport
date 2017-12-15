#ifndef __CAVM_CSRS_SSO_H__
#define __CAVM_CSRS_SSO_H__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.

 *   * Neither the name of Cavium Inc. nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.

 * This Software, including technical data, may be subject to U.S. export  control
 * laws, including the U.S. Export Administration Act and its  associated
 * regulations, and may be subject to export or import  regulations in other
 * countries.

 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR
 * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO
 * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR
 * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM
 * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,
 * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF
 * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR
 * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 ***********************license end**************************************/


/**
 * @file
 *
 * Configuration and status register (CSR) address and type definitions for
 * Cavium SSO.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration sso_bar_e
 *
 * SSO Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define CAVM_SSO_BAR_E_SSO_PF_BAR0 (0x860000000000ll)
#define CAVM_SSO_BAR_E_SSO_PF_BAR0_SIZE 0x100000000ull
#define CAVM_SSO_BAR_E_SSO_PF_BAR4 (0x860700000000ll)
#define CAVM_SSO_BAR_E_SSO_PF_BAR4_SIZE 0x100000ull
#define CAVM_SSO_BAR_E_SSO_VFX_BAR0(a) (0x860800000000ll + 0x100000ll * (a))
#define CAVM_SSO_BAR_E_SSO_VFX_BAR0_SIZE 0x100000ull
#define CAVM_SSO_BAR_E_SSO_VFX_BAR2(a) (0x862800000000ll + 0x100000ll * (a))
#define CAVM_SSO_BAR_E_SSO_VFX_BAR2_SIZE 0x100000ull
#define CAVM_SSO_BAR_E_SSO_VFX_BAR4(a) (0x860c00000000ll + 0x100000ll * (a))
#define CAVM_SSO_BAR_E_SSO_VFX_BAR4_SIZE 0x100000ull

/**
 * Enumeration sso_op_e
 *
 * INTERNAL: SSO Operation Code Enumeration
 *
 * Enumerates the different SSO operation codes.  For RTL use only.
 */
#define CAVM_SSO_OP_E_ADDWQ (4)
#define CAVM_SSO_OP_E_CLR_NSCHED (7)
#define CAVM_SSO_OP_E_DESCH (3)
#define CAVM_SSO_OP_E_NOP (0xf)
#define CAVM_SSO_OP_E_SWTAG (0)
#define CAVM_SSO_OP_E_SWTAG_DESCH (2)
#define CAVM_SSO_OP_E_SWTAG_FULL (1)
#define CAVM_SSO_OP_E_UPD_WQP_GRP (5)

/**
 * Enumeration sso_pf_int_vec_e
 *
 * SSO MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define CAVM_SSO_PF_INT_VEC_E_ERR0 (0)
#define CAVM_SSO_PF_INT_VEC_E_ERR1 (1)
#define CAVM_SSO_PF_INT_VEC_E_ERR2 (2)
#define CAVM_SSO_PF_INT_VEC_E_MBOXX(a) (3 + (a))

/**
 * Enumeration sso_tt_e
 *
 * SSO Tag Type Enumeration
 * Enumerates the different SSO tag types.
 */
#define CAVM_SSO_TT_E_ATOMIC (1)
#define CAVM_SSO_TT_E_EMPTY (3)
#define CAVM_SSO_TT_E_ORDERED (0)
#define CAVM_SSO_TT_E_UNTAGGED (2)

/**
 * Enumeration sso_vf_int_vec_e
 *
 * SSO MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define CAVM_SSO_VF_INT_VEC_E_GRP (0)

/**
 * Enumeration sso_wa_e
 *
 * SSO Work Add Interface Enumeration
 * Enumerates the different SSO work-add interfaces bit fields in SSO_AW_INP_CTL[WA_DIS].
 */
#define CAVM_SSO_WA_E_ADDWQ (3)
#define CAVM_SSO_WA_E_CPT0 (2)
#define CAVM_SSO_WA_E_CPT1 (4)
#define CAVM_SSO_WA_E_DDF (0xc)
#define CAVM_SSO_WA_E_DFA (5)
#define CAVM_SSO_WA_E_DPI (6)
#define CAVM_SSO_WA_E_HNA (7)
#define CAVM_SSO_WA_E_IOBN (0)
#define CAVM_SSO_WA_E_PKI (1)
#define CAVM_SSO_WA_E_PKO (8)
#define CAVM_SSO_WA_E_RAD (9)
#define CAVM_SSO_WA_E_TIM (0xa)
#define CAVM_SSO_WA_E_ZIP (0xb)

/**
 * Register (NCB) sso_active_cycles0
 *
 * SSO PF Active Cycles Register
 */
union cavm_sso_active_cycles0
{
    uint64_t u;
    struct cavm_sso_active_cycles0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts every coprocessor-clock cycle that the SSO clocks are active in SSO AW. */
#else /* Word 0 - Little Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts every coprocessor-clock cycle that the SSO clocks are active in SSO AW. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_active_cycles0_s cn; */
};
typedef union cavm_sso_active_cycles0 cavm_sso_active_cycles0_t;

#define CAVM_SSO_ACTIVE_CYCLES0 CAVM_SSO_ACTIVE_CYCLES0_FUNC()
static inline uint64_t CAVM_SSO_ACTIVE_CYCLES0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ACTIVE_CYCLES0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001100ll;
    __cavm_csr_fatal("SSO_ACTIVE_CYCLES0", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ACTIVE_CYCLES0 cavm_sso_active_cycles0_t
#define bustype_CAVM_SSO_ACTIVE_CYCLES0 CSR_TYPE_NCB
#define basename_CAVM_SSO_ACTIVE_CYCLES0 "SSO_ACTIVE_CYCLES0"
#define device_bar_CAVM_SSO_ACTIVE_CYCLES0 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ACTIVE_CYCLES0 0
#define arguments_CAVM_SSO_ACTIVE_CYCLES0 -1,-1,-1,-1

/**
 * Register (NCB) sso_active_cycles1
 *
 * SSO PF Active Cycles Register
 */
union cavm_sso_active_cycles1
{
    uint64_t u;
    struct cavm_sso_active_cycles1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts every coprocessor-clock cycle that the SSO clocks are active in SSO GW. */
#else /* Word 0 - Little Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts every coprocessor-clock cycle that the SSO clocks are active in SSO GW. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_active_cycles1_s cn; */
};
typedef union cavm_sso_active_cycles1 cavm_sso_active_cycles1_t;

#define CAVM_SSO_ACTIVE_CYCLES1 CAVM_SSO_ACTIVE_CYCLES1_FUNC()
static inline uint64_t CAVM_SSO_ACTIVE_CYCLES1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ACTIVE_CYCLES1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001108ll;
    __cavm_csr_fatal("SSO_ACTIVE_CYCLES1", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ACTIVE_CYCLES1 cavm_sso_active_cycles1_t
#define bustype_CAVM_SSO_ACTIVE_CYCLES1 CSR_TYPE_NCB
#define basename_CAVM_SSO_ACTIVE_CYCLES1 "SSO_ACTIVE_CYCLES1"
#define device_bar_CAVM_SSO_ACTIVE_CYCLES1 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ACTIVE_CYCLES1 0
#define arguments_CAVM_SSO_ACTIVE_CYCLES1 -1,-1,-1,-1

/**
 * Register (NCB) sso_active_cycles2
 *
 * SSO PF Active Cycles Register
 */
union cavm_sso_active_cycles2
{
    uint64_t u;
    struct cavm_sso_active_cycles2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts every coprocessor-clock cycle that the SSO clocks are active in SSO WS. */
#else /* Word 0 - Little Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts every coprocessor-clock cycle that the SSO clocks are active in SSO WS. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_active_cycles2_s cn; */
};
typedef union cavm_sso_active_cycles2 cavm_sso_active_cycles2_t;

#define CAVM_SSO_ACTIVE_CYCLES2 CAVM_SSO_ACTIVE_CYCLES2_FUNC()
static inline uint64_t CAVM_SSO_ACTIVE_CYCLES2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ACTIVE_CYCLES2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001110ll;
    __cavm_csr_fatal("SSO_ACTIVE_CYCLES2", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ACTIVE_CYCLES2 cavm_sso_active_cycles2_t
#define bustype_CAVM_SSO_ACTIVE_CYCLES2 CSR_TYPE_NCB
#define basename_CAVM_SSO_ACTIVE_CYCLES2 "SSO_ACTIVE_CYCLES2"
#define device_bar_CAVM_SSO_ACTIVE_CYCLES2 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ACTIVE_CYCLES2 0
#define arguments_CAVM_SSO_ACTIVE_CYCLES2 -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_add
 *
 * SSO PF Work-Entries Add Register
 */
union cavm_sso_aw_add
{
    uint64_t u;
    struct cavm_sso_aw_add_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t rsvd_free             : 14; /**< [ 29: 16](WO) Written value is added to SSO_AW_WE[RSVD_FREE] to prevent races between software and
                                                                 hardware changes. This is a two's complement value so subtraction may also be performed. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t rsvd_free             : 14; /**< [ 29: 16](WO) Written value is added to SSO_AW_WE[RSVD_FREE] to prevent races between software and
                                                                 hardware changes. This is a two's complement value so subtraction may also be performed. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_aw_add_s cn; */
};
typedef union cavm_sso_aw_add cavm_sso_aw_add_t;

#define CAVM_SSO_AW_ADD CAVM_SSO_AW_ADD_FUNC()
static inline uint64_t CAVM_SSO_AW_ADD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_AW_ADD_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002080ll;
    __cavm_csr_fatal("SSO_AW_ADD", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_AW_ADD cavm_sso_aw_add_t
#define bustype_CAVM_SSO_AW_ADD CSR_TYPE_NCB
#define basename_CAVM_SSO_AW_ADD "SSO_AW_ADD"
#define device_bar_CAVM_SSO_AW_ADD 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_AW_ADD 0
#define arguments_CAVM_SSO_AW_ADD -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_cfg
 *
 * SSO PF Add-Work Configuration Register
 * This register controls the operation of the add-work block (AW).
 */
union cavm_sso_aw_cfg
{
    uint64_t u;
    struct cavm_sso_aw_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t ldt_short             : 1;  /**< [  8:  8](R/W) Use LDT to bypass L2 allocations when reading short form work. */
        uint64_t lol                   : 1;  /**< [  7:  7](R/W) Reserved. */
        uint64_t xaq_alloc_dis         : 1;  /**< [  6:  6](R/W) Disable FPA alloc requests to fill the SSO page cache. Also all existing cached free
                                                                 buffers will be returned to FPA and will not be cached. */
        uint64_t ocla_bp               : 1;  /**< [  5:  5](R/W) OCLA backpressure enable. When OCLA FIFOs are near full, allow OCLA to backpressure AW pipeline. */
        uint64_t xaq_byp_dis           : 1;  /**< [  4:  4](R/W) Disable bypass path in add-work engine. For diagnostic use only. */
        uint64_t stt                   : 1;  /**< [  3:  3](R/W) Use STT to bypass L2 allocation for XAQ store operations. When this bit is not set it uses STF. */
        uint64_t ldt                   : 1;  /**< [  2:  2](R/W) Use LDT to bypass L2 allocation for XAQ load operations when [LDWB] is not
                                                                 set. When [LDT] and [LDWB] are both clear, uses LDD load type. */
        uint64_t ldwb                  : 1;  /**< [  1:  1](R/W) When reading XAQ cache lines, use LDWB transactions to invalidate the cache
                                                                 line. When clear, use [LDT] to determine load type. */
        uint64_t rwen                  : 1;  /**< [  0:  0](R/W) Enable XAQ operations. This bit should be set after SSO_XAQ()_HEAD_PTR and
                                                                 SSO_XAQ()_TAIL_PTR have been programmed. If cleared, all cached buffers will be
                                                                 returned from the FPA as soon as possible, and TAQ arbitration is simplified. */
#else /* Word 0 - Little Endian */
        uint64_t rwen                  : 1;  /**< [  0:  0](R/W) Enable XAQ operations. This bit should be set after SSO_XAQ()_HEAD_PTR and
                                                                 SSO_XAQ()_TAIL_PTR have been programmed. If cleared, all cached buffers will be
                                                                 returned from the FPA as soon as possible, and TAQ arbitration is simplified. */
        uint64_t ldwb                  : 1;  /**< [  1:  1](R/W) When reading XAQ cache lines, use LDWB transactions to invalidate the cache
                                                                 line. When clear, use [LDT] to determine load type. */
        uint64_t ldt                   : 1;  /**< [  2:  2](R/W) Use LDT to bypass L2 allocation for XAQ load operations when [LDWB] is not
                                                                 set. When [LDT] and [LDWB] are both clear, uses LDD load type. */
        uint64_t stt                   : 1;  /**< [  3:  3](R/W) Use STT to bypass L2 allocation for XAQ store operations. When this bit is not set it uses STF. */
        uint64_t xaq_byp_dis           : 1;  /**< [  4:  4](R/W) Disable bypass path in add-work engine. For diagnostic use only. */
        uint64_t ocla_bp               : 1;  /**< [  5:  5](R/W) OCLA backpressure enable. When OCLA FIFOs are near full, allow OCLA to backpressure AW pipeline. */
        uint64_t xaq_alloc_dis         : 1;  /**< [  6:  6](R/W) Disable FPA alloc requests to fill the SSO page cache. Also all existing cached free
                                                                 buffers will be returned to FPA and will not be cached. */
        uint64_t lol                   : 1;  /**< [  7:  7](R/W) Reserved. */
        uint64_t ldt_short             : 1;  /**< [  8:  8](R/W) Use LDT to bypass L2 allocations when reading short form work. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_aw_cfg_s cn; */
};
typedef union cavm_sso_aw_cfg cavm_sso_aw_cfg_t;

#define CAVM_SSO_AW_CFG CAVM_SSO_AW_CFG_FUNC()
static inline uint64_t CAVM_SSO_AW_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_AW_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000010f0ll;
    __cavm_csr_fatal("SSO_AW_CFG", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_AW_CFG cavm_sso_aw_cfg_t
#define bustype_CAVM_SSO_AW_CFG CSR_TYPE_NCB
#define basename_CAVM_SSO_AW_CFG "SSO_AW_CFG"
#define device_bar_CAVM_SSO_AW_CFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_AW_CFG 0
#define arguments_CAVM_SSO_AW_CFG -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_eco
 *
 * INTERNAL: SSO PF AW ECO Register
 */
union cavm_sso_aw_eco
{
    uint64_t u;
    struct cavm_sso_aw_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t eco_rw                : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_aw_eco_s cn; */
};
typedef union cavm_sso_aw_eco cavm_sso_aw_eco_t;

#define CAVM_SSO_AW_ECO CAVM_SSO_AW_ECO_FUNC()
static inline uint64_t CAVM_SSO_AW_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_AW_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001030ll;
    __cavm_csr_fatal("SSO_AW_ECO", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_AW_ECO cavm_sso_aw_eco_t
#define bustype_CAVM_SSO_AW_ECO CSR_TYPE_NCB
#define basename_CAVM_SSO_AW_ECO "SSO_AW_ECO"
#define device_bar_CAVM_SSO_AW_ECO 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_AW_ECO 0
#define arguments_CAVM_SSO_AW_ECO -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_inp_ctl
 *
 * SSO PF Add-Work Input Control Register
 */
union cavm_sso_aw_inp_ctl
{
    uint64_t u;
    struct cavm_sso_aw_inp_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t wa_dis                : 13; /**< [ 12:  0](R/W) Add-work input disable.  Each bit corresponds to a hardware input queue, and if
                                                                 set add-works from the corresponding coprocessor will be dropped.
                                                                 Bit numbers enumerated by SSO_WA_E. */
#else /* Word 0 - Little Endian */
        uint64_t wa_dis                : 13; /**< [ 12:  0](R/W) Add-work input disable.  Each bit corresponds to a hardware input queue, and if
                                                                 set add-works from the corresponding coprocessor will be dropped.
                                                                 Bit numbers enumerated by SSO_WA_E. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_aw_inp_ctl_s cn; */
};
typedef union cavm_sso_aw_inp_ctl cavm_sso_aw_inp_ctl_t;

#define CAVM_SSO_AW_INP_CTL CAVM_SSO_AW_INP_CTL_FUNC()
static inline uint64_t CAVM_SSO_AW_INP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_AW_INP_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002070ll;
    __cavm_csr_fatal("SSO_AW_INP_CTL", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_AW_INP_CTL cavm_sso_aw_inp_ctl_t
#define bustype_CAVM_SSO_AW_INP_CTL CSR_TYPE_NCB
#define basename_CAVM_SSO_AW_INP_CTL "SSO_AW_INP_CTL"
#define device_bar_CAVM_SSO_AW_INP_CTL 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_AW_INP_CTL 0
#define arguments_CAVM_SSO_AW_INP_CTL -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_read_arb
 *
 * SSO PF Read Arbitration Register
 * This register fine tunes the AW read arbiter and is for diagnostic use.
 */
union cavm_sso_aw_read_arb
{
    uint64_t u;
    struct cavm_sso_aw_read_arb_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t xaq_lev               : 6;  /**< [ 29: 24](RO/H) Current number of XAQ reads outstanding. */
        uint64_t reserved_21_23        : 3;
        uint64_t xaq_min               : 5;  /**< [ 20: 16](R/W) Number of read slots reserved for XAQ exclusive use. Values > 16 will not result in
                                                                 additional XAQ reads in flight, but will reduce maximum AW_TAG reads in flight. */
        uint64_t reserved_14_15        : 2;
        uint64_t aw_tag_lev            : 6;  /**< [ 13:  8](RO/H) Current number of tag reads outstanding. */
        uint64_t reserved_5_7          : 3;
        uint64_t aw_tag_min            : 5;  /**< [  4:  0](R/W) Number of read slots reserved for AQ tag read exclusive use. */
#else /* Word 0 - Little Endian */
        uint64_t aw_tag_min            : 5;  /**< [  4:  0](R/W) Number of read slots reserved for AQ tag read exclusive use. */
        uint64_t reserved_5_7          : 3;
        uint64_t aw_tag_lev            : 6;  /**< [ 13:  8](RO/H) Current number of tag reads outstanding. */
        uint64_t reserved_14_15        : 2;
        uint64_t xaq_min               : 5;  /**< [ 20: 16](R/W) Number of read slots reserved for XAQ exclusive use. Values > 16 will not result in
                                                                 additional XAQ reads in flight, but will reduce maximum AW_TAG reads in flight. */
        uint64_t reserved_21_23        : 3;
        uint64_t xaq_lev               : 6;  /**< [ 29: 24](RO/H) Current number of XAQ reads outstanding. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_aw_read_arb_s cn; */
};
typedef union cavm_sso_aw_read_arb cavm_sso_aw_read_arb_t;

#define CAVM_SSO_AW_READ_ARB CAVM_SSO_AW_READ_ARB_FUNC()
static inline uint64_t CAVM_SSO_AW_READ_ARB_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_AW_READ_ARB_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002090ll;
    __cavm_csr_fatal("SSO_AW_READ_ARB", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_AW_READ_ARB cavm_sso_aw_read_arb_t
#define bustype_CAVM_SSO_AW_READ_ARB CSR_TYPE_NCB
#define basename_CAVM_SSO_AW_READ_ARB "SSO_AW_READ_ARB"
#define device_bar_CAVM_SSO_AW_READ_ARB 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_AW_READ_ARB 0
#define arguments_CAVM_SSO_AW_READ_ARB -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_status
 *
 * SSO PF Add-Work Status Register
 * This register indicates the status of the add-work block (AW).
 */
union cavm_sso_aw_status
{
    uint64_t u;
    struct cavm_sso_aw_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t xaq_buf_cached        : 6;  /**< [  5:  0](RO/H) Indicates number of FPA buffers cached inside SSO. */
#else /* Word 0 - Little Endian */
        uint64_t xaq_buf_cached        : 6;  /**< [  5:  0](RO/H) Indicates number of FPA buffers cached inside SSO. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_aw_status_s cn; */
};
typedef union cavm_sso_aw_status cavm_sso_aw_status_t;

#define CAVM_SSO_AW_STATUS CAVM_SSO_AW_STATUS_FUNC()
static inline uint64_t CAVM_SSO_AW_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_AW_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000010e0ll;
    __cavm_csr_fatal("SSO_AW_STATUS", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_AW_STATUS cavm_sso_aw_status_t
#define bustype_CAVM_SSO_AW_STATUS CSR_TYPE_NCB
#define basename_CAVM_SSO_AW_STATUS "SSO_AW_STATUS"
#define device_bar_CAVM_SSO_AW_STATUS 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_AW_STATUS 0
#define arguments_CAVM_SSO_AW_STATUS -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_tag_latency_pc
 *
 * SSO PF Short Form Tag Requests Perf-Count Register
 */
union cavm_sso_aw_tag_latency_pc
{
    uint64_t u;
    struct cavm_sso_aw_tag_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for tag read returns. This may be divided by SSO_AW_TAG_REQ_PC to
                                                                 determine the average read latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for tag read returns. This may be divided by SSO_AW_TAG_REQ_PC to
                                                                 determine the average read latency. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_aw_tag_latency_pc_s cn; */
};
typedef union cavm_sso_aw_tag_latency_pc cavm_sso_aw_tag_latency_pc_t;

#define CAVM_SSO_AW_TAG_LATENCY_PC CAVM_SSO_AW_TAG_LATENCY_PC_FUNC()
static inline uint64_t CAVM_SSO_AW_TAG_LATENCY_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_AW_TAG_LATENCY_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020a8ll;
    __cavm_csr_fatal("SSO_AW_TAG_LATENCY_PC", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_AW_TAG_LATENCY_PC cavm_sso_aw_tag_latency_pc_t
#define bustype_CAVM_SSO_AW_TAG_LATENCY_PC CSR_TYPE_NCB
#define basename_CAVM_SSO_AW_TAG_LATENCY_PC "SSO_AW_TAG_LATENCY_PC"
#define device_bar_CAVM_SSO_AW_TAG_LATENCY_PC 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_AW_TAG_LATENCY_PC 0
#define arguments_CAVM_SSO_AW_TAG_LATENCY_PC -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_tag_req_pc
 *
 * SSO PF Short Form Tag Latency Perf-Count Register
 */
union cavm_sso_aw_tag_req_pc
{
    uint64_t u;
    struct cavm_sso_aw_tag_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of tag read requests. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of tag read requests. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_aw_tag_req_pc_s cn; */
};
typedef union cavm_sso_aw_tag_req_pc cavm_sso_aw_tag_req_pc_t;

#define CAVM_SSO_AW_TAG_REQ_PC CAVM_SSO_AW_TAG_REQ_PC_FUNC()
static inline uint64_t CAVM_SSO_AW_TAG_REQ_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_AW_TAG_REQ_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020a0ll;
    __cavm_csr_fatal("SSO_AW_TAG_REQ_PC", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_AW_TAG_REQ_PC cavm_sso_aw_tag_req_pc_t
#define bustype_CAVM_SSO_AW_TAG_REQ_PC CSR_TYPE_NCB
#define basename_CAVM_SSO_AW_TAG_REQ_PC "SSO_AW_TAG_REQ_PC"
#define device_bar_CAVM_SSO_AW_TAG_REQ_PC 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_AW_TAG_REQ_PC 0
#define arguments_CAVM_SSO_AW_TAG_REQ_PC -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_we
 *
 * SSO PF Work-Entries Count Register
 */
union cavm_sso_aw_we
{
    uint64_t u;
    struct cavm_sso_aw_we_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t rsvd_free             : 13; /**< [ 28: 16](R/W/H) Number of free reserved entries. Used to ensure that each hardware-group can get
                                                                 a specific number of entries. Must always be greater than or equal to the sum
                                                                 across all SSO_GRP()_IAQ_THR[RSVD_THR], and will generally be equal to that sum
                                                                 unless changes to RSVD_THR are going to be made. To prevent races, software
                                                                 should not change this register when SSO is being used; instead use
                                                                 SSO_AW_ADD[RSVD_FREE]. */
        uint64_t reserved_13_15        : 3;
        uint64_t free_cnt              : 13; /**< [ 12:  0](RO/H) Number of total free entries. */
#else /* Word 0 - Little Endian */
        uint64_t free_cnt              : 13; /**< [ 12:  0](RO/H) Number of total free entries. */
        uint64_t reserved_13_15        : 3;
        uint64_t rsvd_free             : 13; /**< [ 28: 16](R/W/H) Number of free reserved entries. Used to ensure that each hardware-group can get
                                                                 a specific number of entries. Must always be greater than or equal to the sum
                                                                 across all SSO_GRP()_IAQ_THR[RSVD_THR], and will generally be equal to that sum
                                                                 unless changes to RSVD_THR are going to be made. To prevent races, software
                                                                 should not change this register when SSO is being used; instead use
                                                                 SSO_AW_ADD[RSVD_FREE]. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_aw_we_s cn; */
};
typedef union cavm_sso_aw_we cavm_sso_aw_we_t;

#define CAVM_SSO_AW_WE CAVM_SSO_AW_WE_FUNC()
static inline uint64_t CAVM_SSO_AW_WE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_AW_WE_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001080ll;
    __cavm_csr_fatal("SSO_AW_WE", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_AW_WE cavm_sso_aw_we_t
#define bustype_CAVM_SSO_AW_WE CSR_TYPE_NCB
#define basename_CAVM_SSO_AW_WE "SSO_AW_WE"
#define device_bar_CAVM_SSO_AW_WE 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_AW_WE 0
#define arguments_CAVM_SSO_AW_WE -1,-1,-1,-1

/**
 * Register (NCB) sso_bist_status0
 *
 * SSO PF BIST Status Register
 * Contains the BIST status for the SSO memories.
 */
union cavm_sso_bist_status0
{
    uint64_t u;
    struct cavm_sso_bist_status0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t bist                  : 12; /**< [ 11:  0](RO/H) Memory BIST status.
                                                                 0 = Pass.
                                                                 1 = Fail.

                                                                 Internal:
                                                                 <11> = XAQ_CNT.
                                                                 <10> = XAQ_LIMIT.
                                                                  <9> = WES.
                                                                  <8> = FFF.
                                                                  <7> = XAQ.
                                                                  <6> = QTC.
                                                                  <5> = INP.
                                                                  <4> = LLM.
                                                                  <3> = TIAQ_HPTR.
                                                                  <2> = TIAQ_TPTR.
                                                                  <1> = TOAQ_HPTR.
                                                                  <0> = TOAQ_TPTR. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 12; /**< [ 11:  0](RO/H) Memory BIST status.
                                                                 0 = Pass.
                                                                 1 = Fail.

                                                                 Internal:
                                                                 <11> = XAQ_CNT.
                                                                 <10> = XAQ_LIMIT.
                                                                  <9> = WES.
                                                                  <8> = FFF.
                                                                  <7> = XAQ.
                                                                  <6> = QTC.
                                                                  <5> = INP.
                                                                  <4> = LLM.
                                                                  <3> = TIAQ_HPTR.
                                                                  <2> = TIAQ_TPTR.
                                                                  <1> = TOAQ_HPTR.
                                                                  <0> = TOAQ_TPTR. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_bist_status0_s cn; */
};
typedef union cavm_sso_bist_status0 cavm_sso_bist_status0_t;

#define CAVM_SSO_BIST_STATUS0 CAVM_SSO_BIST_STATUS0_FUNC()
static inline uint64_t CAVM_SSO_BIST_STATUS0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_BIST_STATUS0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001200ll;
    __cavm_csr_fatal("SSO_BIST_STATUS0", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_BIST_STATUS0 cavm_sso_bist_status0_t
#define bustype_CAVM_SSO_BIST_STATUS0 CSR_TYPE_NCB
#define basename_CAVM_SSO_BIST_STATUS0 "SSO_BIST_STATUS0"
#define device_bar_CAVM_SSO_BIST_STATUS0 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_BIST_STATUS0 0
#define arguments_CAVM_SSO_BIST_STATUS0 -1,-1,-1,-1

/**
 * Register (NCB) sso_bist_status1
 *
 * SSO PF BIST Status 1 Register
 * Contains the BIST status for the SSO memories.
 */
union cavm_sso_bist_status1
{
    uint64_t u;
    struct cavm_sso_bist_status1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t bist                  : 8;  /**< [  7:  0](RO/H) Memory BIST status.
                                                                 0 = Pass.
                                                                 1 = Fail.

                                                                 Internal:
                                                                 <7> = MBOX_MEM,
                                                                 <6> = THRINT.
                                                                 <5> = MASK.
                                                                 <4> = GDW.
                                                                 <3> = QIDX.
                                                                 <2> = TPTR.
                                                                 <1> = HPTR.
                                                                 <0> = CNTR. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 8;  /**< [  7:  0](RO/H) Memory BIST status.
                                                                 0 = Pass.
                                                                 1 = Fail.

                                                                 Internal:
                                                                 <7> = MBOX_MEM,
                                                                 <6> = THRINT.
                                                                 <5> = MASK.
                                                                 <4> = GDW.
                                                                 <3> = QIDX.
                                                                 <2> = TPTR.
                                                                 <1> = HPTR.
                                                                 <0> = CNTR. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_bist_status1_s cn; */
};
typedef union cavm_sso_bist_status1 cavm_sso_bist_status1_t;

#define CAVM_SSO_BIST_STATUS1 CAVM_SSO_BIST_STATUS1_FUNC()
static inline uint64_t CAVM_SSO_BIST_STATUS1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_BIST_STATUS1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001208ll;
    __cavm_csr_fatal("SSO_BIST_STATUS1", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_BIST_STATUS1 cavm_sso_bist_status1_t
#define bustype_CAVM_SSO_BIST_STATUS1 CSR_TYPE_NCB
#define basename_CAVM_SSO_BIST_STATUS1 "SSO_BIST_STATUS1"
#define device_bar_CAVM_SSO_BIST_STATUS1 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_BIST_STATUS1 0
#define arguments_CAVM_SSO_BIST_STATUS1 -1,-1,-1,-1

/**
 * Register (NCB) sso_bist_status2
 *
 * SSO PF BIST Status 2 Register
 * Contains the BIST status for the SSO memories.
 */
union cavm_sso_bist_status2
{
    uint64_t u;
    struct cavm_sso_bist_status2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t bist                  : 12; /**< [ 11:  0](RO/H) Memory BIST status.
                                                                 0 = Pass.
                                                                 1 = Fail.

                                                                 Internal:
                                                                 <11> = VHGRP.
                                                                 <10> = HWSX_GMCTL.
                                                                 <9>  = PCC.
                                                                 <8>  = PC_WS.
                                                                 <7>  = PC_WA.
                                                                 <6>  = PC_TS.
                                                                 <5>  = PC_DS.
                                                                 <4>  = NCB0.
                                                                 <3>  = PND.
                                                                 <2>  = OTH.
                                                                 <1>  = NIDX.
                                                                 <0>  = PIDX. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 12; /**< [ 11:  0](RO/H) Memory BIST status.
                                                                 0 = Pass.
                                                                 1 = Fail.

                                                                 Internal:
                                                                 <11> = VHGRP.
                                                                 <10> = HWSX_GMCTL.
                                                                 <9>  = PCC.
                                                                 <8>  = PC_WS.
                                                                 <7>  = PC_WA.
                                                                 <6>  = PC_TS.
                                                                 <5>  = PC_DS.
                                                                 <4>  = NCB0.
                                                                 <3>  = PND.
                                                                 <2>  = OTH.
                                                                 <1>  = NIDX.
                                                                 <0>  = PIDX. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_bist_status2_s cn; */
};
typedef union cavm_sso_bist_status2 cavm_sso_bist_status2_t;

#define CAVM_SSO_BIST_STATUS2 CAVM_SSO_BIST_STATUS2_FUNC()
static inline uint64_t CAVM_SSO_BIST_STATUS2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_BIST_STATUS2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001210ll;
    __cavm_csr_fatal("SSO_BIST_STATUS2", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_BIST_STATUS2 cavm_sso_bist_status2_t
#define bustype_CAVM_SSO_BIST_STATUS2 CSR_TYPE_NCB
#define basename_CAVM_SSO_BIST_STATUS2 "SSO_BIST_STATUS2"
#define device_bar_CAVM_SSO_BIST_STATUS2 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_BIST_STATUS2 0
#define arguments_CAVM_SSO_BIST_STATUS2 -1,-1,-1,-1

/**
 * Register (NCB) sso_bp_test0
 *
 * INTERNAL: SSO PF Backpressure Test Register 0
 */
union cavm_sso_bp_test0
{
    uint64_t u;
    struct cavm_sso_bp_test0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved.
                                                                 <62> = Reserved.
                                                                 <61> = Reserved.
                                                                 <60> = Limit the aw aq credit decrement returns */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
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
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved.
                                                                 <62> = Reserved.
                                                                 <61> = Reserved.
                                                                 <60> = Limit the aw aq credit decrement returns */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_bp_test0_s cn; */
};
typedef union cavm_sso_bp_test0 cavm_sso_bp_test0_t;

#define CAVM_SSO_BP_TEST0 CAVM_SSO_BP_TEST0_FUNC()
static inline uint64_t CAVM_SSO_BP_TEST0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_BP_TEST0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001380ll;
    __cavm_csr_fatal("SSO_BP_TEST0", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_BP_TEST0 cavm_sso_bp_test0_t
#define bustype_CAVM_SSO_BP_TEST0 CSR_TYPE_NCB
#define basename_CAVM_SSO_BP_TEST0 "SSO_BP_TEST0"
#define device_bar_CAVM_SSO_BP_TEST0 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_BP_TEST0 0
#define arguments_CAVM_SSO_BP_TEST0 -1,-1,-1,-1

/**
 * Register (NCB) sso_bp_test1
 *
 * INTERNAL: SSO PF Backpressure Test Register 1
 */
union cavm_sso_bp_test1
{
    uint64_t u;
    struct cavm_sso_bp_test1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved.
                                                                 <62> = Reserved.
                                                                 <61> = Reserved.
                                                                 <60> = Limit the gw_csr_rxfifo from asserting valid for the next request. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
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
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved.
                                                                 <62> = Reserved.
                                                                 <61> = Reserved.
                                                                 <60> = Limit the gw_csr_rxfifo from asserting valid for the next request. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_bp_test1_s cn; */
};
typedef union cavm_sso_bp_test1 cavm_sso_bp_test1_t;

#define CAVM_SSO_BP_TEST1 CAVM_SSO_BP_TEST1_FUNC()
static inline uint64_t CAVM_SSO_BP_TEST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_BP_TEST1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001390ll;
    __cavm_csr_fatal("SSO_BP_TEST1", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_BP_TEST1 cavm_sso_bp_test1_t
#define bustype_CAVM_SSO_BP_TEST1 CSR_TYPE_NCB
#define basename_CAVM_SSO_BP_TEST1 "SSO_BP_TEST1"
#define device_bar_CAVM_SSO_BP_TEST1 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_BP_TEST1 0
#define arguments_CAVM_SSO_BP_TEST1 -1,-1,-1,-1

/**
 * Register (NCB) sso_bp_test2
 *
 * INTERNAL: SSO PF Backpressure Test Register 2
 */
union cavm_sso_bp_test2
{
    uint64_t u;
    struct cavm_sso_bp_test2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved.
                                                                 <62> = Reserved.
                                                                 <61> = Reserved.
                                                                 <60> = Limit the ncbo FIFO from asserting valid for the next request. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
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
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved.
                                                                 <62> = Reserved.
                                                                 <61> = Reserved.
                                                                 <60> = Limit the ncbo FIFO from asserting valid for the next request. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_bp_test2_s cn; */
};
typedef union cavm_sso_bp_test2 cavm_sso_bp_test2_t;

#define CAVM_SSO_BP_TEST2 CAVM_SSO_BP_TEST2_FUNC()
static inline uint64_t CAVM_SSO_BP_TEST2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_BP_TEST2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000013a0ll;
    __cavm_csr_fatal("SSO_BP_TEST2", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_BP_TEST2 cavm_sso_bp_test2_t
#define bustype_CAVM_SSO_BP_TEST2 CSR_TYPE_NCB
#define basename_CAVM_SSO_BP_TEST2 "SSO_BP_TEST2"
#define device_bar_CAVM_SSO_BP_TEST2 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_BP_TEST2 0
#define arguments_CAVM_SSO_BP_TEST2 -1,-1,-1,-1

/**
 * Register (NCB) sso_const
 *
 * SSO PF Constants Register
 * This register contains constants for software discovery.
 */
union cavm_sso_const
{
    uint64_t u;
    struct cavm_sso_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t hws                   : 8;  /**< [ 63: 56](RO) Number of hardware work slots. */
        uint64_t taq_b                 : 8;  /**< [ 55: 48](RAZ) Number of TAQ entries per line.  Multiply [TAQ_A] times [TAQ_B] to find total entries. */
        uint64_t taq_a                 : 16; /**< [ 47: 32](RO) Number of TAQ lines.  Multiply [TAQ_A] times [TAQ_B] to find total entries. */
        uint64_t iue                   : 16; /**< [ 31: 16](RO) Number of in-unit entries. */
        uint64_t grp                   : 16; /**< [ 15:  0](RO) Number of hardware-groups. */
#else /* Word 0 - Little Endian */
        uint64_t grp                   : 16; /**< [ 15:  0](RO) Number of hardware-groups. */
        uint64_t iue                   : 16; /**< [ 31: 16](RO) Number of in-unit entries. */
        uint64_t taq_a                 : 16; /**< [ 47: 32](RO) Number of TAQ lines.  Multiply [TAQ_A] times [TAQ_B] to find total entries. */
        uint64_t taq_b                 : 8;  /**< [ 55: 48](RAZ) Number of TAQ entries per line.  Multiply [TAQ_A] times [TAQ_B] to find total entries. */
        uint64_t hws                   : 8;  /**< [ 63: 56](RO) Number of hardware work slots. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_const_s cn; */
};
typedef union cavm_sso_const cavm_sso_const_t;

#define CAVM_SSO_CONST CAVM_SSO_CONST_FUNC()
static inline uint64_t CAVM_SSO_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001000ll;
    __cavm_csr_fatal("SSO_CONST", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_CONST cavm_sso_const_t
#define bustype_CAVM_SSO_CONST CSR_TYPE_NCB
#define basename_CAVM_SSO_CONST "SSO_CONST"
#define device_bar_CAVM_SSO_CONST 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_CONST 0
#define arguments_CAVM_SSO_CONST -1,-1,-1,-1

/**
 * Register (NCB) sso_const1
 *
 * SSO PF Constants Register 1
 * This register contains constants for software discovery.
 */
union cavm_sso_const1
{
    uint64_t u;
    struct cavm_sso_const1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t maps                  : 12; /**< [ 43: 32](RO) Number of entries in SSO_PF_MAP(). */
        uint64_t xae_waes              : 16; /**< [ 31: 16](RO) Number of WAEs (work entries) in a XAQ buffer. */
        uint64_t xaq_buf_size          : 16; /**< [ 15:  0](RO) Number of bytes in a XAQ buffer. */
#else /* Word 0 - Little Endian */
        uint64_t xaq_buf_size          : 16; /**< [ 15:  0](RO) Number of bytes in a XAQ buffer. */
        uint64_t xae_waes              : 16; /**< [ 31: 16](RO) Number of WAEs (work entries) in a XAQ buffer. */
        uint64_t maps                  : 12; /**< [ 43: 32](RO) Number of entries in SSO_PF_MAP(). */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_const1_s cn; */
};
typedef union cavm_sso_const1 cavm_sso_const1_t;

#define CAVM_SSO_CONST1 CAVM_SSO_CONST1_FUNC()
static inline uint64_t CAVM_SSO_CONST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_CONST1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001008ll;
    __cavm_csr_fatal("SSO_CONST1", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_CONST1 cavm_sso_const1_t
#define bustype_CAVM_SSO_CONST1 CSR_TYPE_NCB
#define basename_CAVM_SSO_CONST1 "SSO_CONST1"
#define device_bar_CAVM_SSO_CONST1 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_CONST1 0
#define arguments_CAVM_SSO_CONST1 -1,-1,-1,-1

/**
 * Register (NCB) sso_ecc_ctl0
 *
 * SSO PF ECC Control 0 Register
 */
union cavm_sso_ecc_ctl0
{
    uint64_t u;
    struct cavm_sso_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t xaq_cnt_flip          : 2;  /**< [ 35: 34](R/W) XAQ_CNT flip syndrome bits on write. */
        uint64_t xaq_cnt_cdis          : 1;  /**< [ 33: 33](R/W) XAQ_CNT ECC correction disable. */
        uint64_t xaq_limit_flip        : 2;  /**< [ 32: 31](R/W) XAQ_LIMIT flip syndrome bits on write. */
        uint64_t xaq_limit_cdis        : 1;  /**< [ 30: 30](R/W) XAQ_LIMIT ECC correction disable. */
        uint64_t toaqt_flip            : 2;  /**< [ 29: 28](R/W) TOAQT flip syndrome bits on write. */
        uint64_t toaqt_cdis            : 1;  /**< [ 27: 27](R/W) TOAQT ECC correction disable. */
        uint64_t toaqh_flip            : 2;  /**< [ 26: 25](R/W) TOAQH flip syndrome bits on write. */
        uint64_t toaqh_cdis            : 1;  /**< [ 24: 24](R/W) TOAQH ECC correction disable. */
        uint64_t tiaqt_flip            : 2;  /**< [ 23: 22](R/W) TIAQT flip syndrome bits on write. */
        uint64_t tiaqt_cdis            : 1;  /**< [ 21: 21](R/W) TIAQT ECC correction disable. */
        uint64_t tiaqh_flip            : 2;  /**< [ 20: 19](R/W) TIAQH flip syndrome bits on write. */
        uint64_t tiaqh_cdis            : 1;  /**< [ 18: 18](R/W) TIAQH ECC correction disable. */
        uint64_t llm_flip              : 2;  /**< [ 17: 16](R/W) LLM flip syndrome bits on write. */
        uint64_t llm_cdis              : 1;  /**< [ 15: 15](R/W) LLM ECC correction disable. */
        uint64_t inp_flip              : 2;  /**< [ 14: 13](R/W) INP flip syndrome bits on write. */
        uint64_t inp_cdis              : 1;  /**< [ 12: 12](R/W) INP ECC correction disable. */
        uint64_t qtc_flip              : 2;  /**< [ 11: 10](R/W) QTC flip syndrome bits on write. */
        uint64_t qtc_cdis              : 1;  /**< [  9:  9](R/W) QTC ECC correction disable. */
        uint64_t xaq_flip              : 2;  /**< [  8:  7](R/W) XAQ flip syndrome bits on write. */
        uint64_t xaq_cdis              : 1;  /**< [  6:  6](R/W) XAQ ECC correction disable. */
        uint64_t fff_flip              : 2;  /**< [  5:  4](R/W) FFF flip syndrome bits on write. */
        uint64_t fff_cdis              : 1;  /**< [  3:  3](R/W) FFF ECC correction disable. */
        uint64_t wes_flip              : 2;  /**< [  2:  1](R/W) WES flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t wes_cdis              : 1;  /**< [  0:  0](R/W) WES ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t wes_cdis              : 1;  /**< [  0:  0](R/W) WES ECC correction disable. */
        uint64_t wes_flip              : 2;  /**< [  2:  1](R/W) WES flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t fff_cdis              : 1;  /**< [  3:  3](R/W) FFF ECC correction disable. */
        uint64_t fff_flip              : 2;  /**< [  5:  4](R/W) FFF flip syndrome bits on write. */
        uint64_t xaq_cdis              : 1;  /**< [  6:  6](R/W) XAQ ECC correction disable. */
        uint64_t xaq_flip              : 2;  /**< [  8:  7](R/W) XAQ flip syndrome bits on write. */
        uint64_t qtc_cdis              : 1;  /**< [  9:  9](R/W) QTC ECC correction disable. */
        uint64_t qtc_flip              : 2;  /**< [ 11: 10](R/W) QTC flip syndrome bits on write. */
        uint64_t inp_cdis              : 1;  /**< [ 12: 12](R/W) INP ECC correction disable. */
        uint64_t inp_flip              : 2;  /**< [ 14: 13](R/W) INP flip syndrome bits on write. */
        uint64_t llm_cdis              : 1;  /**< [ 15: 15](R/W) LLM ECC correction disable. */
        uint64_t llm_flip              : 2;  /**< [ 17: 16](R/W) LLM flip syndrome bits on write. */
        uint64_t tiaqh_cdis            : 1;  /**< [ 18: 18](R/W) TIAQH ECC correction disable. */
        uint64_t tiaqh_flip            : 2;  /**< [ 20: 19](R/W) TIAQH flip syndrome bits on write. */
        uint64_t tiaqt_cdis            : 1;  /**< [ 21: 21](R/W) TIAQT ECC correction disable. */
        uint64_t tiaqt_flip            : 2;  /**< [ 23: 22](R/W) TIAQT flip syndrome bits on write. */
        uint64_t toaqh_cdis            : 1;  /**< [ 24: 24](R/W) TOAQH ECC correction disable. */
        uint64_t toaqh_flip            : 2;  /**< [ 26: 25](R/W) TOAQH flip syndrome bits on write. */
        uint64_t toaqt_cdis            : 1;  /**< [ 27: 27](R/W) TOAQT ECC correction disable. */
        uint64_t toaqt_flip            : 2;  /**< [ 29: 28](R/W) TOAQT flip syndrome bits on write. */
        uint64_t xaq_limit_cdis        : 1;  /**< [ 30: 30](R/W) XAQ_LIMIT ECC correction disable. */
        uint64_t xaq_limit_flip        : 2;  /**< [ 32: 31](R/W) XAQ_LIMIT flip syndrome bits on write. */
        uint64_t xaq_cnt_cdis          : 1;  /**< [ 33: 33](R/W) XAQ_CNT ECC correction disable. */
        uint64_t xaq_cnt_flip          : 2;  /**< [ 35: 34](R/W) XAQ_CNT flip syndrome bits on write. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ecc_ctl0_s cn; */
};
typedef union cavm_sso_ecc_ctl0 cavm_sso_ecc_ctl0_t;

#define CAVM_SSO_ECC_CTL0 CAVM_SSO_ECC_CTL0_FUNC()
static inline uint64_t CAVM_SSO_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001280ll;
    __cavm_csr_fatal("SSO_ECC_CTL0", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ECC_CTL0 cavm_sso_ecc_ctl0_t
#define bustype_CAVM_SSO_ECC_CTL0 CSR_TYPE_NCB
#define basename_CAVM_SSO_ECC_CTL0 "SSO_ECC_CTL0"
#define device_bar_CAVM_SSO_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ECC_CTL0 0
#define arguments_CAVM_SSO_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) sso_ecc_ctl1
 *
 * SSO PF ECC Control 1 Register
 */
union cavm_sso_ecc_ctl1
{
    uint64_t u;
    struct cavm_sso_ecc_ctl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t mbox_mem_flip         : 2;  /**< [ 23: 22](R/W) MBOX_MEM flip syndrome bits on write. */
        uint64_t mbox_mem_cdis         : 1;  /**< [ 21: 21](R/W) MBOX_MEM ECC correction disable. */
        uint64_t thrint_flip           : 2;  /**< [ 20: 19](R/W) THRINT flip syndrome bits on write. */
        uint64_t thrint_cdis           : 1;  /**< [ 18: 18](R/W) THRINT ECC correction disable. */
        uint64_t mask_flip             : 2;  /**< [ 17: 16](R/W) MASK flip syndrome bits on write. */
        uint64_t mask_cdis             : 1;  /**< [ 15: 15](R/W) MASK ECC correction disable. */
        uint64_t gdw_flip              : 2;  /**< [ 14: 13](R/W) GDW flip syndrome bits on write. */
        uint64_t gdw_cdis              : 1;  /**< [ 12: 12](R/W) GDW ECC correction disable. */
        uint64_t qidx_flip             : 2;  /**< [ 11: 10](R/W) QIDX flip syndrome bits on write. */
        uint64_t qidx_cdis             : 1;  /**< [  9:  9](R/W) QIDX ECC correction disable. */
        uint64_t tptr_flip             : 2;  /**< [  8:  7](R/W) TPTR flip syndrome bits on write. */
        uint64_t tptr_cdis             : 1;  /**< [  6:  6](R/W) TPTR ECC correction disable. */
        uint64_t hptr_flip             : 2;  /**< [  5:  4](R/W) HPTR flip syndrome bits on write. */
        uint64_t hptr_cdis             : 1;  /**< [  3:  3](R/W) HPTR ECC correction disable. */
        uint64_t cntr_flip             : 2;  /**< [  2:  1](R/W) CNTR flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t cntr_cdis             : 1;  /**< [  0:  0](R/W) CNTR ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_cdis             : 1;  /**< [  0:  0](R/W) CNTR ECC correction disable. */
        uint64_t cntr_flip             : 2;  /**< [  2:  1](R/W) CNTR flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t hptr_cdis             : 1;  /**< [  3:  3](R/W) HPTR ECC correction disable. */
        uint64_t hptr_flip             : 2;  /**< [  5:  4](R/W) HPTR flip syndrome bits on write. */
        uint64_t tptr_cdis             : 1;  /**< [  6:  6](R/W) TPTR ECC correction disable. */
        uint64_t tptr_flip             : 2;  /**< [  8:  7](R/W) TPTR flip syndrome bits on write. */
        uint64_t qidx_cdis             : 1;  /**< [  9:  9](R/W) QIDX ECC correction disable. */
        uint64_t qidx_flip             : 2;  /**< [ 11: 10](R/W) QIDX flip syndrome bits on write. */
        uint64_t gdw_cdis              : 1;  /**< [ 12: 12](R/W) GDW ECC correction disable. */
        uint64_t gdw_flip              : 2;  /**< [ 14: 13](R/W) GDW flip syndrome bits on write. */
        uint64_t mask_cdis             : 1;  /**< [ 15: 15](R/W) MASK ECC correction disable. */
        uint64_t mask_flip             : 2;  /**< [ 17: 16](R/W) MASK flip syndrome bits on write. */
        uint64_t thrint_cdis           : 1;  /**< [ 18: 18](R/W) THRINT ECC correction disable. */
        uint64_t thrint_flip           : 2;  /**< [ 20: 19](R/W) THRINT flip syndrome bits on write. */
        uint64_t mbox_mem_cdis         : 1;  /**< [ 21: 21](R/W) MBOX_MEM ECC correction disable. */
        uint64_t mbox_mem_flip         : 2;  /**< [ 23: 22](R/W) MBOX_MEM flip syndrome bits on write. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ecc_ctl1_s cn; */
};
typedef union cavm_sso_ecc_ctl1 cavm_sso_ecc_ctl1_t;

#define CAVM_SSO_ECC_CTL1 CAVM_SSO_ECC_CTL1_FUNC()
static inline uint64_t CAVM_SSO_ECC_CTL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ECC_CTL1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001288ll;
    __cavm_csr_fatal("SSO_ECC_CTL1", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ECC_CTL1 cavm_sso_ecc_ctl1_t
#define bustype_CAVM_SSO_ECC_CTL1 CSR_TYPE_NCB
#define basename_CAVM_SSO_ECC_CTL1 "SSO_ECC_CTL1"
#define device_bar_CAVM_SSO_ECC_CTL1 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ECC_CTL1 0
#define arguments_CAVM_SSO_ECC_CTL1 -1,-1,-1,-1

/**
 * Register (NCB) sso_ecc_ctl2
 *
 * SSO PF ECC Control 2 Register
 */
union cavm_sso_ecc_ctl2
{
    uint64_t u;
    struct cavm_sso_ecc_ctl2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t pcc_flip              : 2;  /**< [ 23: 22](R/W) PCC flip syndrome bits on write. */
        uint64_t pcc_cdis              : 1;  /**< [ 21: 21](R/W) PCC ECC correction disable. */
        uint64_t vhgrp_flip            : 2;  /**< [ 20: 19](R/W) VHGRP flip syndrome bits on write. */
        uint64_t vhgrp_cdis            : 1;  /**< [ 18: 18](R/W) VHGRP ECC correction disable. */
        uint64_t hwsx_gmctl_flip       : 2;  /**< [ 17: 16](R/W) HWSX_GMCTL flip syndrome bits on write. */
        uint64_t hwsx_gmctl_cdis       : 1;  /**< [ 15: 15](R/W) HWSX_GMCTL ECC correction disable. */
        uint64_t ncbo_flip             : 2;  /**< [ 14: 13](R/W) NCBO flip syndrome bits on write. */
        uint64_t ncbo_cdis             : 1;  /**< [ 12: 12](R/W) NCBO ECC correction disable. */
        uint64_t pnd_flip              : 2;  /**< [ 11: 10](R/W) PND flip syndrome bits on write. */
        uint64_t pnd_cdis              : 1;  /**< [  9:  9](R/W) PND ECC correction disable. */
        uint64_t oth_flip              : 2;  /**< [  8:  7](R/W) OTH flip syndrome bits on write. */
        uint64_t oth_cdis              : 1;  /**< [  6:  6](R/W) OTH ECC correction disable. */
        uint64_t nidx_flip             : 2;  /**< [  5:  4](R/W) NIDX flip syndrome bits on write. */
        uint64_t nidx_cdis             : 1;  /**< [  3:  3](R/W) NIDX ECC correction disable. */
        uint64_t pidx_flip             : 2;  /**< [  2:  1](R/W) PIDX flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t pidx_cdis             : 1;  /**< [  0:  0](R/W) PIDX ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t pidx_cdis             : 1;  /**< [  0:  0](R/W) PIDX ECC correction disable. */
        uint64_t pidx_flip             : 2;  /**< [  2:  1](R/W) PIDX flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t nidx_cdis             : 1;  /**< [  3:  3](R/W) NIDX ECC correction disable. */
        uint64_t nidx_flip             : 2;  /**< [  5:  4](R/W) NIDX flip syndrome bits on write. */
        uint64_t oth_cdis              : 1;  /**< [  6:  6](R/W) OTH ECC correction disable. */
        uint64_t oth_flip              : 2;  /**< [  8:  7](R/W) OTH flip syndrome bits on write. */
        uint64_t pnd_cdis              : 1;  /**< [  9:  9](R/W) PND ECC correction disable. */
        uint64_t pnd_flip              : 2;  /**< [ 11: 10](R/W) PND flip syndrome bits on write. */
        uint64_t ncbo_cdis             : 1;  /**< [ 12: 12](R/W) NCBO ECC correction disable. */
        uint64_t ncbo_flip             : 2;  /**< [ 14: 13](R/W) NCBO flip syndrome bits on write. */
        uint64_t hwsx_gmctl_cdis       : 1;  /**< [ 15: 15](R/W) HWSX_GMCTL ECC correction disable. */
        uint64_t hwsx_gmctl_flip       : 2;  /**< [ 17: 16](R/W) HWSX_GMCTL flip syndrome bits on write. */
        uint64_t vhgrp_cdis            : 1;  /**< [ 18: 18](R/W) VHGRP ECC correction disable. */
        uint64_t vhgrp_flip            : 2;  /**< [ 20: 19](R/W) VHGRP flip syndrome bits on write. */
        uint64_t pcc_cdis              : 1;  /**< [ 21: 21](R/W) PCC ECC correction disable. */
        uint64_t pcc_flip              : 2;  /**< [ 23: 22](R/W) PCC flip syndrome bits on write. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ecc_ctl2_s cn; */
};
typedef union cavm_sso_ecc_ctl2 cavm_sso_ecc_ctl2_t;

#define CAVM_SSO_ECC_CTL2 CAVM_SSO_ECC_CTL2_FUNC()
static inline uint64_t CAVM_SSO_ECC_CTL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ECC_CTL2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001290ll;
    __cavm_csr_fatal("SSO_ECC_CTL2", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ECC_CTL2 cavm_sso_ecc_ctl2_t
#define bustype_CAVM_SSO_ECC_CTL2 CSR_TYPE_NCB
#define basename_CAVM_SSO_ECC_CTL2 "SSO_ECC_CTL2"
#define device_bar_CAVM_SSO_ECC_CTL2 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ECC_CTL2 0
#define arguments_CAVM_SSO_ECC_CTL2 -1,-1,-1,-1

/**
 * Register (NCB) sso_err0
 *
 * SSO PF Error 0 Register
 * This register contains ECC and other miscellaneous error bits.
 */
union cavm_sso_err0
{
    uint64_t u;
    struct cavm_sso_err0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t xaq_cnt_dbe           : 1;  /**< [ 55: 55](R/W1C/H) Double-bit error for XAQ_CNT RAM. */
        uint64_t xaq_cnt_sbe           : 1;  /**< [ 54: 54](R/W1C/H) Single-bit error for XAQ_CNT RAM. */
        uint64_t xaq_limit_dbe         : 1;  /**< [ 53: 53](R/W1C/H) Double-bit error for XAQ_LIMIT RAM. */
        uint64_t xaq_limit_sbe         : 1;  /**< [ 52: 52](R/W1C/H) Single-bit error for XAQ_LIMIT RAM. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1C/H) Double-bit error for TOAQT RAM. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1C/H) Single-bit error for TOAQT RAM. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1C/H) Double-bit error for TOAQH RAM. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1C/H) Single-bit error for TOAQH RAM. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1C/H) Double-bit error for TIAQT RAM. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1C/H) Single-bit error for TIAQT RAM. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Double-bit error for TIAQH RAM. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Single-bit error for TIAQH RAM. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Double-bit error for LLM RAM. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Single-bit error for LLM RAM. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1C/H) Double-bit error for INP RAM. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1C/H) Single-bit error for INP RAM. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Double-bit error for QTC RAM. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Single-bit error for QTC RAM. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Double-bit error for XAQ RAM. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Single-bit error for XAQ RAM. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1C/H) Double-bit error for  RAM. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1C/H) Single-bit error for  RAM. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Double-bit error for WES RAM. */
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Single-bit error for WES RAM. */
        uint64_t reserved_12_31        : 20;
        uint64_t gmid_multi            : 1;  /**< [ 11: 11](R/W1C/H) GMID map had double hit error. Set when either:

                                                                   * Coprocessor add-work is dropped due to SSO_PF_MAP() having a double
                                                                 hit. When a request thus dropped, even if this bit is already set,
                                                                 SSO_UNMAP_INFO is loaded. */
        uint64_t gmid_unmap            : 1;  /**< [ 10: 10](R/W1C/H) GMID mapping not found error. Set when either:

                                                                   * Coprocessor add-work dropped due to that coprocessor requesting with GMID
                                                                 not mapped in SSO_PF_MAP(). When a request thus dropped, even if this bit is
                                                                 already set, SSO_UNMAP_INFO is loaded. */
        uint64_t gmid0                 : 1;  /**< [  9:  9](R/W1C/H) GMID zero access error. Set when either:

                                                                   * Coprocessor add-work dropped due to that coprocessor requesting with
                                                                 GMID=0x0. See PKI_QPG_TBLB()[GMID], TIM_RING()_GMCTL[GMID], and other GMID
                                                                 registers. */
        uint64_t addwq_dropped_qctldis : 1;  /**< [  8:  8](R/W1C/H) Add work dropped due to QTL being disabled, 0x0. */
        uint64_t addwq_dropped_wqp0    : 1;  /**< [  7:  7](R/W1C/H) Add work dropped due to WQP being 0x0. */
        uint64_t addwq_dropped         : 1;  /**< [  6:  6](R/W1C/H) Add work dropped due to wrong command/DID requested. */
        uint64_t awempty               : 1;  /**< [  5:  5](R/W1C/H) Set when (a) received add work with tag type is specified as EMPTY, or (b) when
                                                                 SSO_AW_INP_CTL[WA_DIS] is set and work is added from disabled coprocessor. */
        uint64_t grpdis                : 1;  /**< [  4:  4](R/W1C/H) Add work to disabled hardware-group. An ADDWQ was received and dropped to a
                                                                 hardware-group with SSO_GRP()_IAQ_THR[RSVD_THR] = 0. */
        uint64_t bfpn                  : 1;  /**< [  3:  3](R/W1C/H) Bad-fill-packet NCB error. NCB detected error on fill data. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1C/H) Bad-fill-packet error. The WAE VLD_CRC field was incorrect, or the XAQ next address was
                                                                 zero. */
        uint64_t npf                   : 1;  /**< [  1:  1](R/W1C/H) No-pointer-fault error. The FPA returned indication of illegal combinatation of GMID/GAURA
                                                                 for a pointer request. */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1C/H) Free-page error. The free page error bit asserts when a new FPA page is requested and FPA
                                                                 indicates there are no remaining free pages. This bit does not get set for a [NPF] error. */
#else /* Word 0 - Little Endian */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1C/H) Free-page error. The free page error bit asserts when a new FPA page is requested and FPA
                                                                 indicates there are no remaining free pages. This bit does not get set for a [NPF] error. */
        uint64_t npf                   : 1;  /**< [  1:  1](R/W1C/H) No-pointer-fault error. The FPA returned indication of illegal combinatation of GMID/GAURA
                                                                 for a pointer request. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1C/H) Bad-fill-packet error. The WAE VLD_CRC field was incorrect, or the XAQ next address was
                                                                 zero. */
        uint64_t bfpn                  : 1;  /**< [  3:  3](R/W1C/H) Bad-fill-packet NCB error. NCB detected error on fill data. */
        uint64_t grpdis                : 1;  /**< [  4:  4](R/W1C/H) Add work to disabled hardware-group. An ADDWQ was received and dropped to a
                                                                 hardware-group with SSO_GRP()_IAQ_THR[RSVD_THR] = 0. */
        uint64_t awempty               : 1;  /**< [  5:  5](R/W1C/H) Set when (a) received add work with tag type is specified as EMPTY, or (b) when
                                                                 SSO_AW_INP_CTL[WA_DIS] is set and work is added from disabled coprocessor. */
        uint64_t addwq_dropped         : 1;  /**< [  6:  6](R/W1C/H) Add work dropped due to wrong command/DID requested. */
        uint64_t addwq_dropped_wqp0    : 1;  /**< [  7:  7](R/W1C/H) Add work dropped due to WQP being 0x0. */
        uint64_t addwq_dropped_qctldis : 1;  /**< [  8:  8](R/W1C/H) Add work dropped due to QTL being disabled, 0x0. */
        uint64_t gmid0                 : 1;  /**< [  9:  9](R/W1C/H) GMID zero access error. Set when either:

                                                                   * Coprocessor add-work dropped due to that coprocessor requesting with
                                                                 GMID=0x0. See PKI_QPG_TBLB()[GMID], TIM_RING()_GMCTL[GMID], and other GMID
                                                                 registers. */
        uint64_t gmid_unmap            : 1;  /**< [ 10: 10](R/W1C/H) GMID mapping not found error. Set when either:

                                                                   * Coprocessor add-work dropped due to that coprocessor requesting with GMID
                                                                 not mapped in SSO_PF_MAP(). When a request thus dropped, even if this bit is
                                                                 already set, SSO_UNMAP_INFO is loaded. */
        uint64_t gmid_multi            : 1;  /**< [ 11: 11](R/W1C/H) GMID map had double hit error. Set when either:

                                                                   * Coprocessor add-work is dropped due to SSO_PF_MAP() having a double
                                                                 hit. When a request thus dropped, even if this bit is already set,
                                                                 SSO_UNMAP_INFO is loaded. */
        uint64_t reserved_12_31        : 20;
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Single-bit error for WES RAM. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Double-bit error for WES RAM. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1C/H) Single-bit error for  RAM. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1C/H) Double-bit error for  RAM. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Single-bit error for XAQ RAM. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Double-bit error for XAQ RAM. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Single-bit error for QTC RAM. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Double-bit error for QTC RAM. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1C/H) Single-bit error for INP RAM. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1C/H) Double-bit error for INP RAM. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Single-bit error for LLM RAM. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Double-bit error for LLM RAM. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Single-bit error for TIAQH RAM. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Double-bit error for TIAQH RAM. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1C/H) Single-bit error for TIAQT RAM. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1C/H) Double-bit error for TIAQT RAM. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1C/H) Single-bit error for TOAQH RAM. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1C/H) Double-bit error for TOAQH RAM. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1C/H) Single-bit error for TOAQT RAM. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1C/H) Double-bit error for TOAQT RAM. */
        uint64_t xaq_limit_sbe         : 1;  /**< [ 52: 52](R/W1C/H) Single-bit error for XAQ_LIMIT RAM. */
        uint64_t xaq_limit_dbe         : 1;  /**< [ 53: 53](R/W1C/H) Double-bit error for XAQ_LIMIT RAM. */
        uint64_t xaq_cnt_sbe           : 1;  /**< [ 54: 54](R/W1C/H) Single-bit error for XAQ_CNT RAM. */
        uint64_t xaq_cnt_dbe           : 1;  /**< [ 55: 55](R/W1C/H) Double-bit error for XAQ_CNT RAM. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err0_s cn; */
};
typedef union cavm_sso_err0 cavm_sso_err0_t;

#define CAVM_SSO_ERR0 CAVM_SSO_ERR0_FUNC()
static inline uint64_t CAVM_SSO_ERR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001220ll;
    __cavm_csr_fatal("SSO_ERR0", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR0 cavm_sso_err0_t
#define bustype_CAVM_SSO_ERR0 CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR0 "SSO_ERR0"
#define device_bar_CAVM_SSO_ERR0 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR0 0
#define arguments_CAVM_SSO_ERR0 -1,-1,-1,-1

/**
 * Register (NCB) sso_err0_ena_w1c
 *
 * SSO PF Error 0 Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_sso_err0_ena_w1c
{
    uint64_t u;
    struct cavm_sso_err0_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t xaq_cnt_dbe           : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_CNT_DBE]. */
        uint64_t xaq_cnt_sbe           : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_CNT_SBE]. */
        uint64_t xaq_limit_dbe         : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_LIMIT_DBE]. */
        uint64_t xaq_limit_sbe         : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_LIMIT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQT_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQH_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQT_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQH_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for SSO_ERR0[LLM_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for SSO_ERR0[LLM_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for SSO_ERR0[INP_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for SSO_ERR0[INP_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for SSO_ERR0[QTC_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for SSO_ERR0[QTC_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for SSO_ERR0[FFF_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for SSO_ERR0[FFF_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for SSO_ERR0[WES_DBE]. */
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for SSO_ERR0[WES_SBE]. */
        uint64_t reserved_12_31        : 20;
        uint64_t gmid_multi            : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID_MULTI]. */
        uint64_t gmid_unmap            : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid0                 : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID0]. */
        uint64_t addwq_dropped_qctldis : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SSO_ERR0[ADDWQ_DROPPED_QCTLDIS]. */
        uint64_t addwq_dropped_wqp0    : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SSO_ERR0[ADDWQ_DROPPED_WQP0]. */
        uint64_t addwq_dropped         : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t awempty               : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SSO_ERR0[AWEMPTY]. */
        uint64_t grpdis                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SSO_ERR0[GRPDIS]. */
        uint64_t bfpn                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_ERR0[BFPN]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_ERR0[BFP]. */
        uint64_t npf                   : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_ERR0[NPF]. */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_ERR0[FPE]. */
#else /* Word 0 - Little Endian */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_ERR0[FPE]. */
        uint64_t npf                   : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_ERR0[NPF]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_ERR0[BFP]. */
        uint64_t bfpn                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_ERR0[BFPN]. */
        uint64_t grpdis                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SSO_ERR0[GRPDIS]. */
        uint64_t awempty               : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SSO_ERR0[AWEMPTY]. */
        uint64_t addwq_dropped         : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t addwq_dropped_wqp0    : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SSO_ERR0[ADDWQ_DROPPED_WQP0]. */
        uint64_t addwq_dropped_qctldis : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SSO_ERR0[ADDWQ_DROPPED_QCTLDIS]. */
        uint64_t gmid0                 : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID0]. */
        uint64_t gmid_unmap            : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid_multi            : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID_MULTI]. */
        uint64_t reserved_12_31        : 20;
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for SSO_ERR0[WES_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for SSO_ERR0[WES_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for SSO_ERR0[FFF_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for SSO_ERR0[FFF_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for SSO_ERR0[QTC_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for SSO_ERR0[QTC_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for SSO_ERR0[INP_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for SSO_ERR0[INP_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for SSO_ERR0[LLM_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for SSO_ERR0[LLM_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQH_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQT_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQH_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQT_DBE]. */
        uint64_t xaq_limit_sbe         : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_LIMIT_SBE]. */
        uint64_t xaq_limit_dbe         : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_LIMIT_DBE]. */
        uint64_t xaq_cnt_sbe           : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_CNT_SBE]. */
        uint64_t xaq_cnt_dbe           : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_CNT_DBE]. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err0_ena_w1c_s cn; */
};
typedef union cavm_sso_err0_ena_w1c cavm_sso_err0_ena_w1c_t;

#define CAVM_SSO_ERR0_ENA_W1C CAVM_SSO_ERR0_ENA_W1C_FUNC()
static inline uint64_t CAVM_SSO_ERR0_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR0_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001230ll;
    __cavm_csr_fatal("SSO_ERR0_ENA_W1C", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR0_ENA_W1C cavm_sso_err0_ena_w1c_t
#define bustype_CAVM_SSO_ERR0_ENA_W1C CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR0_ENA_W1C "SSO_ERR0_ENA_W1C"
#define device_bar_CAVM_SSO_ERR0_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR0_ENA_W1C 0
#define arguments_CAVM_SSO_ERR0_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) sso_err0_ena_w1s
 *
 * SSO PF Error 0 Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_sso_err0_ena_w1s
{
    uint64_t u;
    struct cavm_sso_err0_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t xaq_cnt_dbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_CNT_DBE]. */
        uint64_t xaq_cnt_sbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_CNT_SBE]. */
        uint64_t xaq_limit_dbe         : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_LIMIT_DBE]. */
        uint64_t xaq_limit_sbe         : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_LIMIT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQT_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQH_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQT_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQH_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for SSO_ERR0[LLM_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for SSO_ERR0[LLM_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for SSO_ERR0[INP_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for SSO_ERR0[INP_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for SSO_ERR0[QTC_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for SSO_ERR0[QTC_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for SSO_ERR0[FFF_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for SSO_ERR0[FFF_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for SSO_ERR0[WES_DBE]. */
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for SSO_ERR0[WES_SBE]. */
        uint64_t reserved_12_31        : 20;
        uint64_t gmid_multi            : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID_MULTI]. */
        uint64_t gmid_unmap            : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid0                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID0]. */
        uint64_t addwq_dropped_qctldis : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SSO_ERR0[ADDWQ_DROPPED_QCTLDIS]. */
        uint64_t addwq_dropped_wqp0    : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SSO_ERR0[ADDWQ_DROPPED_WQP0]. */
        uint64_t addwq_dropped         : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t awempty               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SSO_ERR0[AWEMPTY]. */
        uint64_t grpdis                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SSO_ERR0[GRPDIS]. */
        uint64_t bfpn                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_ERR0[BFPN]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_ERR0[BFP]. */
        uint64_t npf                   : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_ERR0[NPF]. */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_ERR0[FPE]. */
#else /* Word 0 - Little Endian */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_ERR0[FPE]. */
        uint64_t npf                   : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_ERR0[NPF]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_ERR0[BFP]. */
        uint64_t bfpn                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_ERR0[BFPN]. */
        uint64_t grpdis                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SSO_ERR0[GRPDIS]. */
        uint64_t awempty               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SSO_ERR0[AWEMPTY]. */
        uint64_t addwq_dropped         : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t addwq_dropped_wqp0    : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SSO_ERR0[ADDWQ_DROPPED_WQP0]. */
        uint64_t addwq_dropped_qctldis : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SSO_ERR0[ADDWQ_DROPPED_QCTLDIS]. */
        uint64_t gmid0                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID0]. */
        uint64_t gmid_unmap            : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid_multi            : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID_MULTI]. */
        uint64_t reserved_12_31        : 20;
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for SSO_ERR0[WES_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for SSO_ERR0[WES_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for SSO_ERR0[FFF_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for SSO_ERR0[FFF_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for SSO_ERR0[QTC_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for SSO_ERR0[QTC_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for SSO_ERR0[INP_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for SSO_ERR0[INP_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for SSO_ERR0[LLM_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for SSO_ERR0[LLM_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQH_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQT_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQH_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQT_DBE]. */
        uint64_t xaq_limit_sbe         : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_LIMIT_SBE]. */
        uint64_t xaq_limit_dbe         : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_LIMIT_DBE]. */
        uint64_t xaq_cnt_sbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_CNT_SBE]. */
        uint64_t xaq_cnt_dbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_CNT_DBE]. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err0_ena_w1s_s cn; */
};
typedef union cavm_sso_err0_ena_w1s cavm_sso_err0_ena_w1s_t;

#define CAVM_SSO_ERR0_ENA_W1S CAVM_SSO_ERR0_ENA_W1S_FUNC()
static inline uint64_t CAVM_SSO_ERR0_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR0_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001238ll;
    __cavm_csr_fatal("SSO_ERR0_ENA_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR0_ENA_W1S cavm_sso_err0_ena_w1s_t
#define bustype_CAVM_SSO_ERR0_ENA_W1S CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR0_ENA_W1S "SSO_ERR0_ENA_W1S"
#define device_bar_CAVM_SSO_ERR0_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR0_ENA_W1S 0
#define arguments_CAVM_SSO_ERR0_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err0_w1s
 *
 * SSO PF Error 0 Set Register
 * This register sets interrupt bits.
 */
union cavm_sso_err0_w1s
{
    uint64_t u;
    struct cavm_sso_err0_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t xaq_cnt_dbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets SSO_ERR0[XAQ_CNT_DBE]. */
        uint64_t xaq_cnt_sbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets SSO_ERR0[XAQ_CNT_SBE]. */
        uint64_t xaq_limit_dbe         : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets SSO_ERR0[XAQ_LIMIT_DBE]. */
        uint64_t xaq_limit_sbe         : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets SSO_ERR0[XAQ_LIMIT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets SSO_ERR0[TOAQT_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets SSO_ERR0[TOAQH_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets SSO_ERR0[TIAQT_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets SSO_ERR0[TIAQH_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets SSO_ERR0[LLM_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets SSO_ERR0[LLM_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets SSO_ERR0[INP_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets SSO_ERR0[INP_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets SSO_ERR0[QTC_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets SSO_ERR0[QTC_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets SSO_ERR0[XAQ_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets SSO_ERR0[XAQ_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets SSO_ERR0[FFF_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets SSO_ERR0[FFF_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets SSO_ERR0[WES_DBE]. */
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets SSO_ERR0[WES_SBE]. */
        uint64_t reserved_12_31        : 20;
        uint64_t gmid_multi            : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets SSO_ERR0[GMID_MULTI]. */
        uint64_t gmid_unmap            : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid0                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets SSO_ERR0[GMID0]. */
        uint64_t addwq_dropped_qctldis : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SSO_ERR0[ADDWQ_DROPPED_QCTLDIS]. */
        uint64_t addwq_dropped_wqp0    : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SSO_ERR0[ADDWQ_DROPPED_WQP0]. */
        uint64_t addwq_dropped         : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t awempty               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SSO_ERR0[AWEMPTY]. */
        uint64_t grpdis                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SSO_ERR0[GRPDIS]. */
        uint64_t bfpn                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_ERR0[BFPN]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_ERR0[BFP]. */
        uint64_t npf                   : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_ERR0[NPF]. */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_ERR0[FPE]. */
#else /* Word 0 - Little Endian */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_ERR0[FPE]. */
        uint64_t npf                   : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_ERR0[NPF]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_ERR0[BFP]. */
        uint64_t bfpn                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_ERR0[BFPN]. */
        uint64_t grpdis                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SSO_ERR0[GRPDIS]. */
        uint64_t awempty               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SSO_ERR0[AWEMPTY]. */
        uint64_t addwq_dropped         : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t addwq_dropped_wqp0    : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SSO_ERR0[ADDWQ_DROPPED_WQP0]. */
        uint64_t addwq_dropped_qctldis : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SSO_ERR0[ADDWQ_DROPPED_QCTLDIS]. */
        uint64_t gmid0                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets SSO_ERR0[GMID0]. */
        uint64_t gmid_unmap            : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid_multi            : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets SSO_ERR0[GMID_MULTI]. */
        uint64_t reserved_12_31        : 20;
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets SSO_ERR0[WES_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets SSO_ERR0[WES_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets SSO_ERR0[FFF_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets SSO_ERR0[FFF_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets SSO_ERR0[XAQ_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets SSO_ERR0[XAQ_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets SSO_ERR0[QTC_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets SSO_ERR0[QTC_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets SSO_ERR0[INP_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets SSO_ERR0[INP_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets SSO_ERR0[LLM_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets SSO_ERR0[LLM_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets SSO_ERR0[TIAQH_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets SSO_ERR0[TIAQT_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets SSO_ERR0[TOAQH_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets SSO_ERR0[TOAQT_DBE]. */
        uint64_t xaq_limit_sbe         : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets SSO_ERR0[XAQ_LIMIT_SBE]. */
        uint64_t xaq_limit_dbe         : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets SSO_ERR0[XAQ_LIMIT_DBE]. */
        uint64_t xaq_cnt_sbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets SSO_ERR0[XAQ_CNT_SBE]. */
        uint64_t xaq_cnt_dbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets SSO_ERR0[XAQ_CNT_DBE]. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err0_w1s_s cn; */
};
typedef union cavm_sso_err0_w1s cavm_sso_err0_w1s_t;

#define CAVM_SSO_ERR0_W1S CAVM_SSO_ERR0_W1S_FUNC()
static inline uint64_t CAVM_SSO_ERR0_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR0_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001228ll;
    __cavm_csr_fatal("SSO_ERR0_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR0_W1S cavm_sso_err0_w1s_t
#define bustype_CAVM_SSO_ERR0_W1S CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR0_W1S "SSO_ERR0_W1S"
#define device_bar_CAVM_SSO_ERR0_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR0_W1S 0
#define arguments_CAVM_SSO_ERR0_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err1
 *
 * SSO PF Error 1 Register
 * This register contains ECC and other miscellaneous error bits.
 */
union cavm_sso_err1
{
    uint64_t u;
    struct cavm_sso_err1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1C/H) Double-bit error for MBOX_MEM RAM. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1C/H) Single-bit error for MBOX_MEM RAM. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1C/H) Double-bit error for THRINT RAM. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1C/H) Single-bit error for THRINT RAM. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Double-bit error for MASK RAM. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Single-bit error for MASK RAM. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1C/H) Double-bit error for GDW RAM. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1C/H) Single-bit error for GDW RAM. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1C/H) Double-bit error for QIDX RAM. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1C/H) Single-bit error for QIDX RAM. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1C/H) Double-bit error for TPTR RAM. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1C/H) Single-bit error for TPTR RAM. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1C/H) Double-bit error for HPTR RAM. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1C/H) Single-bit error for HPTR RAM. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1C/H) Double-bit error for CNTR RAM. */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1C/H) Single-bit error for CNTR RAM. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1C/H) Single-bit error for CNTR RAM. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1C/H) Double-bit error for CNTR RAM. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1C/H) Single-bit error for HPTR RAM. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1C/H) Double-bit error for HPTR RAM. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1C/H) Single-bit error for TPTR RAM. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1C/H) Double-bit error for TPTR RAM. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1C/H) Single-bit error for QIDX RAM. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1C/H) Double-bit error for QIDX RAM. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1C/H) Single-bit error for GDW RAM. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1C/H) Double-bit error for GDW RAM. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Single-bit error for MASK RAM. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Double-bit error for MASK RAM. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1C/H) Single-bit error for THRINT RAM. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1C/H) Double-bit error for THRINT RAM. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1C/H) Single-bit error for MBOX_MEM RAM. */
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1C/H) Double-bit error for MBOX_MEM RAM. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err1_s cn; */
};
typedef union cavm_sso_err1 cavm_sso_err1_t;

#define CAVM_SSO_ERR1 CAVM_SSO_ERR1_FUNC()
static inline uint64_t CAVM_SSO_ERR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001240ll;
    __cavm_csr_fatal("SSO_ERR1", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR1 cavm_sso_err1_t
#define bustype_CAVM_SSO_ERR1 CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR1 "SSO_ERR1"
#define device_bar_CAVM_SSO_ERR1 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR1 0
#define arguments_CAVM_SSO_ERR1 -1,-1,-1,-1

/**
 * Register (NCB) sso_err1_ena_w1c
 *
 * SSO PF Error 1 Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_sso_err1_ena_w1c
{
    uint64_t u;
    struct cavm_sso_err1_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for SSO_ERR1[THRINT_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for SSO_ERR1[THRINT_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for SSO_ERR1[MASK_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for SSO_ERR1[MASK_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for SSO_ERR1[GDW_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SSO_ERR1[GDW_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SSO_ERR1[QIDX_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SSO_ERR1[QIDX_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SSO_ERR1[TPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SSO_ERR1[TPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_ERR1[HPTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_ERR1[HPTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_ERR1[CNTR_DBE]. */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_ERR1[CNTR_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_ERR1[CNTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_ERR1[CNTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_ERR1[HPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_ERR1[HPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SSO_ERR1[TPTR_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SSO_ERR1[TPTR_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SSO_ERR1[QIDX_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SSO_ERR1[QIDX_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SSO_ERR1[GDW_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for SSO_ERR1[GDW_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for SSO_ERR1[MASK_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for SSO_ERR1[MASK_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for SSO_ERR1[THRINT_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for SSO_ERR1[THRINT_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err1_ena_w1c_s cn; */
};
typedef union cavm_sso_err1_ena_w1c cavm_sso_err1_ena_w1c_t;

#define CAVM_SSO_ERR1_ENA_W1C CAVM_SSO_ERR1_ENA_W1C_FUNC()
static inline uint64_t CAVM_SSO_ERR1_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR1_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001250ll;
    __cavm_csr_fatal("SSO_ERR1_ENA_W1C", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR1_ENA_W1C cavm_sso_err1_ena_w1c_t
#define bustype_CAVM_SSO_ERR1_ENA_W1C CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR1_ENA_W1C "SSO_ERR1_ENA_W1C"
#define device_bar_CAVM_SSO_ERR1_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR1_ENA_W1C 0
#define arguments_CAVM_SSO_ERR1_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) sso_err1_ena_w1s
 *
 * SSO PF Error 1 Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_sso_err1_ena_w1s
{
    uint64_t u;
    struct cavm_sso_err1_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for SSO_ERR1[THRINT_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for SSO_ERR1[THRINT_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for SSO_ERR1[MASK_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for SSO_ERR1[MASK_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for SSO_ERR1[GDW_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SSO_ERR1[GDW_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SSO_ERR1[QIDX_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SSO_ERR1[QIDX_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SSO_ERR1[TPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SSO_ERR1[TPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_ERR1[HPTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_ERR1[HPTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_ERR1[CNTR_DBE]. */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_ERR1[CNTR_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_ERR1[CNTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_ERR1[CNTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_ERR1[HPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_ERR1[HPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SSO_ERR1[TPTR_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SSO_ERR1[TPTR_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SSO_ERR1[QIDX_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SSO_ERR1[QIDX_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SSO_ERR1[GDW_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for SSO_ERR1[GDW_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for SSO_ERR1[MASK_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for SSO_ERR1[MASK_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for SSO_ERR1[THRINT_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for SSO_ERR1[THRINT_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err1_ena_w1s_s cn; */
};
typedef union cavm_sso_err1_ena_w1s cavm_sso_err1_ena_w1s_t;

#define CAVM_SSO_ERR1_ENA_W1S CAVM_SSO_ERR1_ENA_W1S_FUNC()
static inline uint64_t CAVM_SSO_ERR1_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR1_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001258ll;
    __cavm_csr_fatal("SSO_ERR1_ENA_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR1_ENA_W1S cavm_sso_err1_ena_w1s_t
#define bustype_CAVM_SSO_ERR1_ENA_W1S CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR1_ENA_W1S "SSO_ERR1_ENA_W1S"
#define device_bar_CAVM_SSO_ERR1_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR1_ENA_W1S 0
#define arguments_CAVM_SSO_ERR1_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err1_w1s
 *
 * SSO PF Error 1 Set Register
 * This register sets interrupt bits.
 */
union cavm_sso_err1_w1s
{
    uint64_t u;
    struct cavm_sso_err1_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets SSO_ERR1[THRINT_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets SSO_ERR1[THRINT_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets SSO_ERR1[MASK_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets SSO_ERR1[MASK_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets SSO_ERR1[GDW_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SSO_ERR1[GDW_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SSO_ERR1[QIDX_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SSO_ERR1[QIDX_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SSO_ERR1[TPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SSO_ERR1[TPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_ERR1[HPTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_ERR1[HPTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_ERR1[CNTR_DBE]. */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_ERR1[CNTR_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_ERR1[CNTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_ERR1[CNTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_ERR1[HPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_ERR1[HPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SSO_ERR1[TPTR_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SSO_ERR1[TPTR_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SSO_ERR1[QIDX_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SSO_ERR1[QIDX_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SSO_ERR1[GDW_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets SSO_ERR1[GDW_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets SSO_ERR1[MASK_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets SSO_ERR1[MASK_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets SSO_ERR1[THRINT_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets SSO_ERR1[THRINT_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err1_w1s_s cn; */
};
typedef union cavm_sso_err1_w1s cavm_sso_err1_w1s_t;

#define CAVM_SSO_ERR1_W1S CAVM_SSO_ERR1_W1S_FUNC()
static inline uint64_t CAVM_SSO_ERR1_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR1_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001248ll;
    __cavm_csr_fatal("SSO_ERR1_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR1_W1S cavm_sso_err1_w1s_t
#define bustype_CAVM_SSO_ERR1_W1S CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR1_W1S "SSO_ERR1_W1S"
#define device_bar_CAVM_SSO_ERR1_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR1_W1S 0
#define arguments_CAVM_SSO_ERR1_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err2
 *
 * SSO PF Error 2 Register
 * This register contains ECC and other miscellaneous error bits.
 */
union cavm_sso_err2
{
    uint64_t u;
    struct cavm_sso_err2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t pcc_dbe               : 1;  /**< [ 47: 47](R/W1C/H) Double-bit error for PCC RAM. */
        uint64_t pcc_sbe               : 1;  /**< [ 46: 46](R/W1C/H) Single-bit error for PCC RAM. */
        uint64_t vhgrp_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Double-bit error for VHGRP RAM. */
        uint64_t vhgrp_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Single-bit error for VHGRP RAM. */
        uint64_t hwsx_gmctl_dbe        : 1;  /**< [ 43: 43](R/W1C/H) Double-bit error for HWSX_GMCTL RAM. */
        uint64_t hwsx_gmctl_sbe        : 1;  /**< [ 42: 42](R/W1C/H) Single-bit error for HWSX_GMCTL RAM. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1C/H) Double-bit error for NCBO RAM. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1C/H) Single-bit error for NCBO RAM. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Double-bit error for PND RAM. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Single-bit error for PND RAM. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Double-bit error for odd OTH RAM. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Single-bit error for odd OTH RAM. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1C/H) Double-bit error for IDX RAM. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1C/H) Single-bit error for IDX RAM. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1C/H) Double-bit error for FIDX RAM. */
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1C/H) Single-bit error for FIDX RAM. */
        uint64_t reserved_31           : 1;
        uint64_t ws_gmid0              : 1;  /**< [ 30: 30](R/W1C/H) Work-slot operation found a SSO_PF_MAP() with GMID=0x0; no-work was returned or the
                                                                 switch-tag was not performed. When a request thus dropped, even if this bit is
                                                                 already set. */
        uint64_t ws_multi              : 1;  /**< [ 29: 29](R/W1C/H) Work-slot operation found a SSO_PF_MAP() double hit; no-work was returned or the
                                                                 switch-tag was not performed. When a request thus dropped, even if this bit is
                                                                 already set, SSO_UNMAP_INFO2 is loaded. */
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](R/W1C/H) Work-slot operation found a SSO_PF_MAP() double hit; no-work was returned or the
                                                                 switch-tag was not performed. When a request thus dropped, even if this bit is
                                                                 already set, SSO_UNMAP_INFO2 is loaded. */
        uint64_t reserved_15_27        : 13;
        uint64_t iop                   : 15; /**< [ 14:  0](R/W1C/H) Illegal operation errors:
                                                                 <14> = Received command before SSO_RESET[BUSY] cleared.
                                                                 <13> = Received illegal opcode.
                                                                 <12> = Received GET_WORK(INDEXED) when SSO_HWS()_GMCTL[GW_INDX_ENA] is zero.
                                                                 <11> = Received illegal load for work slot op.
                                                                 <10> = Received illegal store for work slot op.
                                                                 <9> = Received UPD_WQP_GRP/SWTAG_FULL/CLR_NSCHED with WQP=0
                                                                 <8> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE from work
                                                                 slot with CLR_NSCHED pending.
                                                                 <7> = Received CLR_NSCHED from work slot with SWTAG_DESCH/DESCH/CLR_NSCHED pending.
                                                                 <6> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE/CLR_NSCHED
                                                                 from work slot with ALLOC_WE pending.
                                                                 <5> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE/CLR_NSCHED
                                                                 from work slot with GET_WORK pending.
                                                                 <4> = Received SWTAG_FULL/SWTAG_DESCH with tag specified as UNTAGGED.
                                                                 <3> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH with tag specified as EMPTY.
                                                                 <2> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/GET_WORK from work slot with pending tag
                                                                 switch to ORDERED or ATOMIC.
                                                                 <1> = Received SWTAG/SWTAG_DESCH/DESCH/UPD_WQP_GRP from work slot in UNTAGGED state.
                                                                 <0> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP from work slot in EMPTY
                                                                 state. */
#else /* Word 0 - Little Endian */
        uint64_t iop                   : 15; /**< [ 14:  0](R/W1C/H) Illegal operation errors:
                                                                 <14> = Received command before SSO_RESET[BUSY] cleared.
                                                                 <13> = Received illegal opcode.
                                                                 <12> = Received GET_WORK(INDEXED) when SSO_HWS()_GMCTL[GW_INDX_ENA] is zero.
                                                                 <11> = Received illegal load for work slot op.
                                                                 <10> = Received illegal store for work slot op.
                                                                 <9> = Received UPD_WQP_GRP/SWTAG_FULL/CLR_NSCHED with WQP=0
                                                                 <8> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE from work
                                                                 slot with CLR_NSCHED pending.
                                                                 <7> = Received CLR_NSCHED from work slot with SWTAG_DESCH/DESCH/CLR_NSCHED pending.
                                                                 <6> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE/CLR_NSCHED
                                                                 from work slot with ALLOC_WE pending.
                                                                 <5> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE/CLR_NSCHED
                                                                 from work slot with GET_WORK pending.
                                                                 <4> = Received SWTAG_FULL/SWTAG_DESCH with tag specified as UNTAGGED.
                                                                 <3> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH with tag specified as EMPTY.
                                                                 <2> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/GET_WORK from work slot with pending tag
                                                                 switch to ORDERED or ATOMIC.
                                                                 <1> = Received SWTAG/SWTAG_DESCH/DESCH/UPD_WQP_GRP from work slot in UNTAGGED state.
                                                                 <0> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP from work slot in EMPTY
                                                                 state. */
        uint64_t reserved_15_27        : 13;
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](R/W1C/H) Work-slot operation found a SSO_PF_MAP() double hit; no-work was returned or the
                                                                 switch-tag was not performed. When a request thus dropped, even if this bit is
                                                                 already set, SSO_UNMAP_INFO2 is loaded. */
        uint64_t ws_multi              : 1;  /**< [ 29: 29](R/W1C/H) Work-slot operation found a SSO_PF_MAP() double hit; no-work was returned or the
                                                                 switch-tag was not performed. When a request thus dropped, even if this bit is
                                                                 already set, SSO_UNMAP_INFO2 is loaded. */
        uint64_t ws_gmid0              : 1;  /**< [ 30: 30](R/W1C/H) Work-slot operation found a SSO_PF_MAP() with GMID=0x0; no-work was returned or the
                                                                 switch-tag was not performed. When a request thus dropped, even if this bit is
                                                                 already set. */
        uint64_t reserved_31           : 1;
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1C/H) Single-bit error for FIDX RAM. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1C/H) Double-bit error for FIDX RAM. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1C/H) Single-bit error for IDX RAM. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1C/H) Double-bit error for IDX RAM. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Single-bit error for odd OTH RAM. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Double-bit error for odd OTH RAM. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Single-bit error for PND RAM. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Double-bit error for PND RAM. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1C/H) Single-bit error for NCBO RAM. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1C/H) Double-bit error for NCBO RAM. */
        uint64_t hwsx_gmctl_sbe        : 1;  /**< [ 42: 42](R/W1C/H) Single-bit error for HWSX_GMCTL RAM. */
        uint64_t hwsx_gmctl_dbe        : 1;  /**< [ 43: 43](R/W1C/H) Double-bit error for HWSX_GMCTL RAM. */
        uint64_t vhgrp_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Single-bit error for VHGRP RAM. */
        uint64_t vhgrp_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Double-bit error for VHGRP RAM. */
        uint64_t pcc_sbe               : 1;  /**< [ 46: 46](R/W1C/H) Single-bit error for PCC RAM. */
        uint64_t pcc_dbe               : 1;  /**< [ 47: 47](R/W1C/H) Double-bit error for PCC RAM. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err2_s cn; */
};
typedef union cavm_sso_err2 cavm_sso_err2_t;

#define CAVM_SSO_ERR2 CAVM_SSO_ERR2_FUNC()
static inline uint64_t CAVM_SSO_ERR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001260ll;
    __cavm_csr_fatal("SSO_ERR2", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR2 cavm_sso_err2_t
#define bustype_CAVM_SSO_ERR2 CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR2 "SSO_ERR2"
#define device_bar_CAVM_SSO_ERR2 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR2 0
#define arguments_CAVM_SSO_ERR2 -1,-1,-1,-1

/**
 * Register (NCB) sso_err2_ena_w1c
 *
 * SSO PF Error 2 Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_sso_err2_ena_w1c
{
    uint64_t u;
    struct cavm_sso_err2_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t pcc_dbe               : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for SSO_ERR2[PCC_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for SSO_ERR2[PCC_SBE]. */
        uint64_t vhgrp_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for SSO_ERR2[VHGRP_DBE]. */
        uint64_t vhgrp_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for SSO_ERR2[VHGRP_SBE]. */
        uint64_t hwsx_gmctl_dbe        : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for SSO_ERR2[HWSX_GMCTL_DBE]. */
        uint64_t hwsx_gmctl_sbe        : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for SSO_ERR2[HWSX_GMCTL_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for SSO_ERR2[NCBO_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for SSO_ERR2[NCBO_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for SSO_ERR2[PND_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for SSO_ERR2[PND_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for SSO_ERR2[OTH_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for SSO_ERR2[OTH_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for SSO_ERR2[NIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for SSO_ERR2[NIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for SSO_ERR2[PIDX_DBE]. */
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for SSO_ERR2[PIDX_SBE]. */
        uint64_t reserved_31           : 1;
        uint64_t ws_gmid0              : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for SSO_ERR2[WS_GMID0]. */
        uint64_t ws_multi              : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for SSO_ERR2[WS_MULTI]. */
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for SSO_ERR2[WS_UNMAP]. */
        uint64_t reserved_15_27        : 13;
        uint64_t iop                   : 15; /**< [ 14:  0](R/W1C/H) Reads or clears enable for SSO_ERR2[IOP]. */
#else /* Word 0 - Little Endian */
        uint64_t iop                   : 15; /**< [ 14:  0](R/W1C/H) Reads or clears enable for SSO_ERR2[IOP]. */
        uint64_t reserved_15_27        : 13;
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for SSO_ERR2[WS_UNMAP]. */
        uint64_t ws_multi              : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for SSO_ERR2[WS_MULTI]. */
        uint64_t ws_gmid0              : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for SSO_ERR2[WS_GMID0]. */
        uint64_t reserved_31           : 1;
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for SSO_ERR2[PIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for SSO_ERR2[PIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for SSO_ERR2[NIDX_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for SSO_ERR2[NIDX_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for SSO_ERR2[OTH_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for SSO_ERR2[OTH_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for SSO_ERR2[PND_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for SSO_ERR2[PND_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for SSO_ERR2[NCBO_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for SSO_ERR2[NCBO_DBE]. */
        uint64_t hwsx_gmctl_sbe        : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for SSO_ERR2[HWSX_GMCTL_SBE]. */
        uint64_t hwsx_gmctl_dbe        : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for SSO_ERR2[HWSX_GMCTL_DBE]. */
        uint64_t vhgrp_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for SSO_ERR2[VHGRP_SBE]. */
        uint64_t vhgrp_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for SSO_ERR2[VHGRP_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for SSO_ERR2[PCC_SBE]. */
        uint64_t pcc_dbe               : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for SSO_ERR2[PCC_DBE]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err2_ena_w1c_s cn; */
};
typedef union cavm_sso_err2_ena_w1c cavm_sso_err2_ena_w1c_t;

#define CAVM_SSO_ERR2_ENA_W1C CAVM_SSO_ERR2_ENA_W1C_FUNC()
static inline uint64_t CAVM_SSO_ERR2_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR2_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001270ll;
    __cavm_csr_fatal("SSO_ERR2_ENA_W1C", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR2_ENA_W1C cavm_sso_err2_ena_w1c_t
#define bustype_CAVM_SSO_ERR2_ENA_W1C CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR2_ENA_W1C "SSO_ERR2_ENA_W1C"
#define device_bar_CAVM_SSO_ERR2_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR2_ENA_W1C 0
#define arguments_CAVM_SSO_ERR2_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) sso_err2_ena_w1s
 *
 * SSO PF Error 2 Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_sso_err2_ena_w1s
{
    uint64_t u;
    struct cavm_sso_err2_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t pcc_dbe               : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for SSO_ERR2[PCC_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for SSO_ERR2[PCC_SBE]. */
        uint64_t vhgrp_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for SSO_ERR2[VHGRP_DBE]. */
        uint64_t vhgrp_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for SSO_ERR2[VHGRP_SBE]. */
        uint64_t hwsx_gmctl_dbe        : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for SSO_ERR2[HWSX_GMCTL_DBE]. */
        uint64_t hwsx_gmctl_sbe        : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for SSO_ERR2[HWSX_GMCTL_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for SSO_ERR2[NCBO_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for SSO_ERR2[NCBO_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for SSO_ERR2[PND_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for SSO_ERR2[PND_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for SSO_ERR2[OTH_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for SSO_ERR2[OTH_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for SSO_ERR2[NIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for SSO_ERR2[NIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for SSO_ERR2[PIDX_DBE]. */
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for SSO_ERR2[PIDX_SBE]. */
        uint64_t reserved_31           : 1;
        uint64_t ws_gmid0              : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for SSO_ERR2[WS_GMID0]. */
        uint64_t ws_multi              : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for SSO_ERR2[WS_MULTI]. */
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for SSO_ERR2[WS_UNMAP]. */
        uint64_t reserved_15_27        : 13;
        uint64_t iop                   : 15; /**< [ 14:  0](R/W1S/H) Reads or sets enable for SSO_ERR2[IOP]. */
#else /* Word 0 - Little Endian */
        uint64_t iop                   : 15; /**< [ 14:  0](R/W1S/H) Reads or sets enable for SSO_ERR2[IOP]. */
        uint64_t reserved_15_27        : 13;
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for SSO_ERR2[WS_UNMAP]. */
        uint64_t ws_multi              : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for SSO_ERR2[WS_MULTI]. */
        uint64_t ws_gmid0              : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for SSO_ERR2[WS_GMID0]. */
        uint64_t reserved_31           : 1;
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for SSO_ERR2[PIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for SSO_ERR2[PIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for SSO_ERR2[NIDX_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for SSO_ERR2[NIDX_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for SSO_ERR2[OTH_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for SSO_ERR2[OTH_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for SSO_ERR2[PND_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for SSO_ERR2[PND_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for SSO_ERR2[NCBO_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for SSO_ERR2[NCBO_DBE]. */
        uint64_t hwsx_gmctl_sbe        : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for SSO_ERR2[HWSX_GMCTL_SBE]. */
        uint64_t hwsx_gmctl_dbe        : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for SSO_ERR2[HWSX_GMCTL_DBE]. */
        uint64_t vhgrp_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for SSO_ERR2[VHGRP_SBE]. */
        uint64_t vhgrp_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for SSO_ERR2[VHGRP_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for SSO_ERR2[PCC_SBE]. */
        uint64_t pcc_dbe               : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for SSO_ERR2[PCC_DBE]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err2_ena_w1s_s cn; */
};
typedef union cavm_sso_err2_ena_w1s cavm_sso_err2_ena_w1s_t;

#define CAVM_SSO_ERR2_ENA_W1S CAVM_SSO_ERR2_ENA_W1S_FUNC()
static inline uint64_t CAVM_SSO_ERR2_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR2_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001278ll;
    __cavm_csr_fatal("SSO_ERR2_ENA_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR2_ENA_W1S cavm_sso_err2_ena_w1s_t
#define bustype_CAVM_SSO_ERR2_ENA_W1S CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR2_ENA_W1S "SSO_ERR2_ENA_W1S"
#define device_bar_CAVM_SSO_ERR2_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR2_ENA_W1S 0
#define arguments_CAVM_SSO_ERR2_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err2_w1s
 *
 * SSO PF Error 2 Set Register
 * This register sets interrupt bits.
 */
union cavm_sso_err2_w1s
{
    uint64_t u;
    struct cavm_sso_err2_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t pcc_dbe               : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets SSO_ERR2[PCC_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets SSO_ERR2[PCC_SBE]. */
        uint64_t vhgrp_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets SSO_ERR2[VHGRP_DBE]. */
        uint64_t vhgrp_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets SSO_ERR2[VHGRP_SBE]. */
        uint64_t hwsx_gmctl_dbe        : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets SSO_ERR2[HWSX_GMCTL_DBE]. */
        uint64_t hwsx_gmctl_sbe        : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets SSO_ERR2[HWSX_GMCTL_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets SSO_ERR2[NCBO_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets SSO_ERR2[NCBO_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets SSO_ERR2[PND_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets SSO_ERR2[PND_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets SSO_ERR2[OTH_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets SSO_ERR2[OTH_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets SSO_ERR2[NIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets SSO_ERR2[NIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets SSO_ERR2[PIDX_DBE]. */
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets SSO_ERR2[PIDX_SBE]. */
        uint64_t reserved_31           : 1;
        uint64_t ws_gmid0              : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets SSO_ERR2[WS_GMID0]. */
        uint64_t ws_multi              : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets SSO_ERR2[WS_MULTI]. */
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets SSO_ERR2[WS_UNMAP]. */
        uint64_t reserved_15_27        : 13;
        uint64_t iop                   : 15; /**< [ 14:  0](R/W1S/H) Reads or sets SSO_ERR2[IOP]. */
#else /* Word 0 - Little Endian */
        uint64_t iop                   : 15; /**< [ 14:  0](R/W1S/H) Reads or sets SSO_ERR2[IOP]. */
        uint64_t reserved_15_27        : 13;
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets SSO_ERR2[WS_UNMAP]. */
        uint64_t ws_multi              : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets SSO_ERR2[WS_MULTI]. */
        uint64_t ws_gmid0              : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets SSO_ERR2[WS_GMID0]. */
        uint64_t reserved_31           : 1;
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets SSO_ERR2[PIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets SSO_ERR2[PIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets SSO_ERR2[NIDX_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets SSO_ERR2[NIDX_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets SSO_ERR2[OTH_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets SSO_ERR2[OTH_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets SSO_ERR2[PND_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets SSO_ERR2[PND_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets SSO_ERR2[NCBO_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets SSO_ERR2[NCBO_DBE]. */
        uint64_t hwsx_gmctl_sbe        : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets SSO_ERR2[HWSX_GMCTL_SBE]. */
        uint64_t hwsx_gmctl_dbe        : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets SSO_ERR2[HWSX_GMCTL_DBE]. */
        uint64_t vhgrp_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets SSO_ERR2[VHGRP_SBE]. */
        uint64_t vhgrp_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets SSO_ERR2[VHGRP_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets SSO_ERR2[PCC_SBE]. */
        uint64_t pcc_dbe               : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets SSO_ERR2[PCC_DBE]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_err2_w1s_s cn; */
};
typedef union cavm_sso_err2_w1s cavm_sso_err2_w1s_t;

#define CAVM_SSO_ERR2_W1S CAVM_SSO_ERR2_W1S_FUNC()
static inline uint64_t CAVM_SSO_ERR2_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_ERR2_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001268ll;
    __cavm_csr_fatal("SSO_ERR2_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_ERR2_W1S cavm_sso_err2_w1s_t
#define bustype_CAVM_SSO_ERR2_W1S CSR_TYPE_NCB
#define basename_CAVM_SSO_ERR2_W1S "SSO_ERR2_W1S"
#define device_bar_CAVM_SSO_ERR2_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_ERR2_W1S 0
#define arguments_CAVM_SSO_ERR2_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_grp#_ds_pc
 *
 * SSO PF Hardware-Group Deschedule Performance Counter Register
 * Counts the number of deschedule requests for each hardware-group. Counter rolls over
 * through zero when max value exceeded.
 */
union cavm_sso_grpx_ds_pc
{
    uint64_t u;
    struct cavm_sso_grpx_ds_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Deschedule performance counter. Writes are for diagnostic use only, and defined only when
                                                                 neither work nor GET_WORKs are present in the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Deschedule performance counter. Writes are for diagnostic use only, and defined only when
                                                                 neither work nor GET_WORKs are present in the SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_grpx_ds_pc_s cn; */
};
typedef union cavm_sso_grpx_ds_pc cavm_sso_grpx_ds_pc_t;

static inline uint64_t CAVM_SSO_GRPX_DS_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GRPX_DS_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001400ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_GRPX_DS_PC", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GRPX_DS_PC(a) cavm_sso_grpx_ds_pc_t
#define bustype_CAVM_SSO_GRPX_DS_PC(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_GRPX_DS_PC(a) "SSO_GRPX_DS_PC"
#define device_bar_CAVM_SSO_GRPX_DS_PC(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GRPX_DS_PC(a) (a)
#define arguments_CAVM_SSO_GRPX_DS_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_ext_pc
 *
 * SSO PF Hardware-Group External Schedule Performance Counter Register
 * Counts the number of cache lines of WAEs sent to L2/DDR. Counter rolls over through zero when
 * max value exceeded.
 */
union cavm_sso_grpx_ext_pc
{
    uint64_t u;
    struct cavm_sso_grpx_ext_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) External admission queue cache lines written. Each write corresponds to 11 WAEs. Writes
                                                                 are for diagnostic use only, and defined only when neither work nor GET_WORKs are present
                                                                 in the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) External admission queue cache lines written. Each write corresponds to 11 WAEs. Writes
                                                                 are for diagnostic use only, and defined only when neither work nor GET_WORKs are present
                                                                 in the SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_grpx_ext_pc_s cn; */
};
typedef union cavm_sso_grpx_ext_pc cavm_sso_grpx_ext_pc_t;

static inline uint64_t CAVM_SSO_GRPX_EXT_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GRPX_EXT_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001100ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_GRPX_EXT_PC", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GRPX_EXT_PC(a) cavm_sso_grpx_ext_pc_t
#define bustype_CAVM_SSO_GRPX_EXT_PC(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_GRPX_EXT_PC(a) "SSO_GRPX_EXT_PC"
#define device_bar_CAVM_SSO_GRPX_EXT_PC(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GRPX_EXT_PC(a) (a)
#define arguments_CAVM_SSO_GRPX_EXT_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_iaq_thr
 *
 * SSO PF Hardware-Group In-unit Admission Queue Threshold Registers
 * These registers contain the thresholds for allocating SSO in-unit admission queue entries.
 */
union cavm_sso_grpx_iaq_thr
{
    uint64_t u;
    struct cavm_sso_grpx_iaq_thr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t grp_cnt               : 13; /**< [ 60: 48](RO/H) Hardware-group's entry count. Number of internal entries allocated to IAQ,
                                                                 conflicted work, or CQ in this hardware-group.

                                                                 Internal:
                                                                 Increments on admission to IAQ, decrements on scheduling into
                                                                 work slot. */
        uint64_t reserved_45_47        : 3;
        uint64_t max_thr               : 13; /**< [ 44: 32](R/W) Max threshold for this internal admission queue. If nonzero, must be >= [RSVD_THR] + 4.
                                                                 To ensure full streaming performance to all cores, should be at least 208. Must not be
                                                                 changed after traffic is sent to this hardware-group. */
        uint64_t reserved_13_31        : 19;
        uint64_t rsvd_thr              : 13; /**< [ 12:  0](R/W) Reserved threshold for this internal hardware-group queue. Should be at least 1
                                                                 for any hardware-groups that must make forward progress when other
                                                                 hardware-group's work is pending. Updates to this field must also update
                                                                 SSO_AW_ADD[RSVD_FREE]. Must not be changed after traffic is sent to this
                                                                 hardware-group. */
#else /* Word 0 - Little Endian */
        uint64_t rsvd_thr              : 13; /**< [ 12:  0](R/W) Reserved threshold for this internal hardware-group queue. Should be at least 1
                                                                 for any hardware-groups that must make forward progress when other
                                                                 hardware-group's work is pending. Updates to this field must also update
                                                                 SSO_AW_ADD[RSVD_FREE]. Must not be changed after traffic is sent to this
                                                                 hardware-group. */
        uint64_t reserved_13_31        : 19;
        uint64_t max_thr               : 13; /**< [ 44: 32](R/W) Max threshold for this internal admission queue. If nonzero, must be >= [RSVD_THR] + 4.
                                                                 To ensure full streaming performance to all cores, should be at least 208. Must not be
                                                                 changed after traffic is sent to this hardware-group. */
        uint64_t reserved_45_47        : 3;
        uint64_t grp_cnt               : 13; /**< [ 60: 48](RO/H) Hardware-group's entry count. Number of internal entries allocated to IAQ,
                                                                 conflicted work, or CQ in this hardware-group.

                                                                 Internal:
                                                                 Increments on admission to IAQ, decrements on scheduling into
                                                                 work slot. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_grpx_iaq_thr_s cn; */
};
typedef union cavm_sso_grpx_iaq_thr cavm_sso_grpx_iaq_thr_t;

static inline uint64_t CAVM_SSO_GRPX_IAQ_THR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GRPX_IAQ_THR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020000000ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_GRPX_IAQ_THR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GRPX_IAQ_THR(a) cavm_sso_grpx_iaq_thr_t
#define bustype_CAVM_SSO_GRPX_IAQ_THR(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_GRPX_IAQ_THR(a) "SSO_GRPX_IAQ_THR"
#define device_bar_CAVM_SSO_GRPX_IAQ_THR(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GRPX_IAQ_THR(a) (a)
#define arguments_CAVM_SSO_GRPX_IAQ_THR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_pri
 *
 * SSO PF Hardware-Group Priority Register
 * Controls the priority and hardware-group affinity arbitration for each hardware-group.
 */
union cavm_sso_grpx_pri
{
    uint64_t u;
    struct cavm_sso_grpx_pri_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t wgt_left              : 6;  /**< [ 29: 24](RO/H) Arbitration credits remaining on this hardware-group. */
        uint64_t reserved_22_23        : 2;
        uint64_t weight                : 6;  /**< [ 21: 16](R/W) Arbitration weight to apply to this hardware-group. Must be >= 0x2. */
        uint64_t reserved_12_15        : 4;
        uint64_t affinity              : 4;  /**< [ 11:  8](R/W) Processor affinity arbitration weight to apply to this hardware-group. If zero, affinity
                                                                 is disabled. A change to [AFFINITY] will not take effect until the old [AFFINITY]'s
                                                                 value loaded into SSO_HWS()_ARB[AFF_LEFT] has drained to zero. */
        uint64_t reserved_3_7          : 5;
        uint64_t pri                   : 3;  /**< [  2:  0](R/W) Priority for this hardware-group relative to other hardware-groups. To prevent a
                                                                 HWS from receiving work use SSO_HWS()_S()_GRPMSK().

                                                                 0x0 = highest priority.
                                                                 0x7 = lowest priority.

                                                                 Changing priority while GET_WORKs are in flight may result in a GET_WORK using either the
                                                                 old or new priority, or a mix thereof. */
#else /* Word 0 - Little Endian */
        uint64_t pri                   : 3;  /**< [  2:  0](R/W) Priority for this hardware-group relative to other hardware-groups. To prevent a
                                                                 HWS from receiving work use SSO_HWS()_S()_GRPMSK().

                                                                 0x0 = highest priority.
                                                                 0x7 = lowest priority.

                                                                 Changing priority while GET_WORKs are in flight may result in a GET_WORK using either the
                                                                 old or new priority, or a mix thereof. */
        uint64_t reserved_3_7          : 5;
        uint64_t affinity              : 4;  /**< [ 11:  8](R/W) Processor affinity arbitration weight to apply to this hardware-group. If zero, affinity
                                                                 is disabled. A change to [AFFINITY] will not take effect until the old [AFFINITY]'s
                                                                 value loaded into SSO_HWS()_ARB[AFF_LEFT] has drained to zero. */
        uint64_t reserved_12_15        : 4;
        uint64_t weight                : 6;  /**< [ 21: 16](R/W) Arbitration weight to apply to this hardware-group. Must be >= 0x2. */
        uint64_t reserved_22_23        : 2;
        uint64_t wgt_left              : 6;  /**< [ 29: 24](RO/H) Arbitration credits remaining on this hardware-group. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_grpx_pri_s cn; */
};
typedef union cavm_sso_grpx_pri cavm_sso_grpx_pri_t;

static inline uint64_t CAVM_SSO_GRPX_PRI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GRPX_PRI(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020000200ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_GRPX_PRI", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GRPX_PRI(a) cavm_sso_grpx_pri_t
#define bustype_CAVM_SSO_GRPX_PRI(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_GRPX_PRI(a) "SSO_GRPX_PRI"
#define device_bar_CAVM_SSO_GRPX_PRI(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GRPX_PRI(a) (a)
#define arguments_CAVM_SSO_GRPX_PRI(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_taq_thr
 *
 * SSO PF Hardware-Group Transitory Admission Queue Threshold Registers
 * These registers contain the thresholds for allocating SSO transitory admission queue storage
 * buffers, indexed by hardware-group.
 */
union cavm_sso_grpx_taq_thr
{
    uint64_t u;
    struct cavm_sso_grpx_taq_thr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_59_63        : 5;
        uint64_t grp_cnt               : 11; /**< [ 58: 48](RO/H) Hardware-group's entry count. Number of transitory admission buffers allocated to this group. */
        uint64_t reserved_43_47        : 5;
        uint64_t max_thr               : 11; /**< [ 42: 32](R/W) Max threshold for this transitory admission queue, in buffers of 11
                                                                 entries. Must be >= 3, must be >= [RSVD_THR], and to insure full streaming
                                                                 performance on this hardware-group, should be at least 16 buffers. SSO may
                                                                 exceed this count using unreserved free buffers if and only if persistently
                                                                 backpressured by IOBI. Must not be changed after traffic is sent to this
                                                                 hardware-group. */
        uint64_t reserved_11_31        : 21;
        uint64_t rsvd_thr              : 11; /**< [ 10:  0](R/W) Reserved threshold for this transitory admission queue, in buffers of 11
                                                                 entries. Must be at least 3 buffers for any hardware-groups that are to be
                                                                 used. Changes to this field must also update SSO_TAQ_ADD[RSVD_FREE]. Must not be
                                                                 changed after traffic is sent to this hardware-group. */
#else /* Word 0 - Little Endian */
        uint64_t rsvd_thr              : 11; /**< [ 10:  0](R/W) Reserved threshold for this transitory admission queue, in buffers of 11
                                                                 entries. Must be at least 3 buffers for any hardware-groups that are to be
                                                                 used. Changes to this field must also update SSO_TAQ_ADD[RSVD_FREE]. Must not be
                                                                 changed after traffic is sent to this hardware-group. */
        uint64_t reserved_11_31        : 21;
        uint64_t max_thr               : 11; /**< [ 42: 32](R/W) Max threshold for this transitory admission queue, in buffers of 11
                                                                 entries. Must be >= 3, must be >= [RSVD_THR], and to insure full streaming
                                                                 performance on this hardware-group, should be at least 16 buffers. SSO may
                                                                 exceed this count using unreserved free buffers if and only if persistently
                                                                 backpressured by IOBI. Must not be changed after traffic is sent to this
                                                                 hardware-group. */
        uint64_t reserved_43_47        : 5;
        uint64_t grp_cnt               : 11; /**< [ 58: 48](RO/H) Hardware-group's entry count. Number of transitory admission buffers allocated to this group. */
        uint64_t reserved_59_63        : 5;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_grpx_taq_thr_s cn; */
};
typedef union cavm_sso_grpx_taq_thr cavm_sso_grpx_taq_thr_t;

static inline uint64_t CAVM_SSO_GRPX_TAQ_THR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GRPX_TAQ_THR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020000100ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_GRPX_TAQ_THR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GRPX_TAQ_THR(a) cavm_sso_grpx_taq_thr_t
#define bustype_CAVM_SSO_GRPX_TAQ_THR(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_GRPX_TAQ_THR(a) "SSO_GRPX_TAQ_THR"
#define device_bar_CAVM_SSO_GRPX_TAQ_THR(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GRPX_TAQ_THR(a) (a)
#define arguments_CAVM_SSO_GRPX_TAQ_THR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_ts_pc
 *
 * SSO PF Hardware-Group Tag Switch Performance Counter Register
 * Counts the number of tag switch requests for each hardware-group being switched
 * to. Counter rolls over through zero when max value exceeded.
 */
union cavm_sso_grpx_ts_pc
{
    uint64_t u;
    struct cavm_sso_grpx_ts_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Tag switch performance counter. Writes are for diagnostic use only, and defined only when
                                                                 neither work nor GET_WORKs are present in the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Tag switch performance counter. Writes are for diagnostic use only, and defined only when
                                                                 neither work nor GET_WORKs are present in the SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_grpx_ts_pc_s cn; */
};
typedef union cavm_sso_grpx_ts_pc cavm_sso_grpx_ts_pc_t;

static inline uint64_t CAVM_SSO_GRPX_TS_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GRPX_TS_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001300ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_GRPX_TS_PC", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GRPX_TS_PC(a) cavm_sso_grpx_ts_pc_t
#define bustype_CAVM_SSO_GRPX_TS_PC(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_GRPX_TS_PC(a) "SSO_GRPX_TS_PC"
#define device_bar_CAVM_SSO_GRPX_TS_PC(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GRPX_TS_PC(a) (a)
#define arguments_CAVM_SSO_GRPX_TS_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_wa_pc
 *
 * SSO PF Hardware-Group Work-Add Performance Counter Registers
 * Counts the number of add new work requests for each hardware-group. The counter
 * rolls over through zero when the max value exceeded.
 */
union cavm_sso_grpx_wa_pc
{
    uint64_t u;
    struct cavm_sso_grpx_wa_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Work add performance counter for hardware-group. Increments when work moves into
                                                                 IAQ. Writes are for diagnostic use only, and defined only when neither work nor
                                                                 GET_WORKs are present in the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Work add performance counter for hardware-group. Increments when work moves into
                                                                 IAQ. Writes are for diagnostic use only, and defined only when neither work nor
                                                                 GET_WORKs are present in the SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_grpx_wa_pc_s cn; */
};
typedef union cavm_sso_grpx_wa_pc cavm_sso_grpx_wa_pc_t;

static inline uint64_t CAVM_SSO_GRPX_WA_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GRPX_WA_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001200ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_GRPX_WA_PC", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GRPX_WA_PC(a) cavm_sso_grpx_wa_pc_t
#define bustype_CAVM_SSO_GRPX_WA_PC(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_GRPX_WA_PC(a) "SSO_GRPX_WA_PC"
#define device_bar_CAVM_SSO_GRPX_WA_PC(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GRPX_WA_PC(a) (a)
#define arguments_CAVM_SSO_GRPX_WA_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_ws_pc
 *
 * SSO PF Hardware-Group Work-Schedule Performance Counter Registers
 * Counts the number of work schedules for each hardware-group. The counter rolls over
 * through zero when the maximum value is exceeded.
 */
union cavm_sso_grpx_ws_pc
{
    uint64_t u;
    struct cavm_sso_grpx_ws_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Work schedule performance counter for hardware-group. Writes are for diagnostic
                                                                 use only, and defined only when neither work nor GET_WORKs are present in the
                                                                 SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Work schedule performance counter for hardware-group. Writes are for diagnostic
                                                                 use only, and defined only when neither work nor GET_WORKs are present in the
                                                                 SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_grpx_ws_pc_s cn; */
};
typedef union cavm_sso_grpx_ws_pc cavm_sso_grpx_ws_pc_t;

static inline uint64_t CAVM_SSO_GRPX_WS_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GRPX_WS_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001000ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_GRPX_WS_PC", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GRPX_WS_PC(a) cavm_sso_grpx_ws_pc_t
#define bustype_CAVM_SSO_GRPX_WS_PC(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_GRPX_WS_PC(a) "SSO_GRPX_WS_PC"
#define device_bar_CAVM_SSO_GRPX_WS_PC(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GRPX_WS_PC(a) (a)
#define arguments_CAVM_SSO_GRPX_WS_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_xaq_limit
 *
 * SSO PF Hardware-Group External Admission Queue Limit Registers
 */
union cavm_sso_grpx_xaq_limit
{
    uint64_t u;
    struct cavm_sso_grpx_xaq_limit_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t xaq_limit             : 33; /**< [ 32:  0](R/W) XAQ limit. Each count holds 11 work entries. If an add work is requested to a
                                                                 group where SSO_VHGRP()_XAQ_CNT[XAQ_CNT] >= [XAQ_LIMIT], then the add work is
                                                                 dropped and will SSO_VHGRP()_QCTL[ENA] is cleared and SSO_VHGRP()_INT[XAQ_LIMIT] is
                                                                 set. When 0x0, limiting is disabled. Due to pipelining, hardware may exceed this
                                                                 limit by up to the TAQ size (320) entries. */
#else /* Word 0 - Little Endian */
        uint64_t xaq_limit             : 33; /**< [ 32:  0](R/W) XAQ limit. Each count holds 11 work entries. If an add work is requested to a
                                                                 group where SSO_VHGRP()_XAQ_CNT[XAQ_CNT] >= [XAQ_LIMIT], then the add work is
                                                                 dropped and will SSO_VHGRP()_QCTL[ENA] is cleared and SSO_VHGRP()_INT[XAQ_LIMIT] is
                                                                 set. When 0x0, limiting is disabled. Due to pipelining, hardware may exceed this
                                                                 limit by up to the TAQ size (320) entries. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_grpx_xaq_limit_s cn; */
};
typedef union cavm_sso_grpx_xaq_limit cavm_sso_grpx_xaq_limit_t;

static inline uint64_t CAVM_SSO_GRPX_XAQ_LIMIT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GRPX_XAQ_LIMIT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020000220ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_GRPX_XAQ_LIMIT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GRPX_XAQ_LIMIT(a) cavm_sso_grpx_xaq_limit_t
#define bustype_CAVM_SSO_GRPX_XAQ_LIMIT(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_GRPX_XAQ_LIMIT(a) "SSO_GRPX_XAQ_LIMIT"
#define device_bar_CAVM_SSO_GRPX_XAQ_LIMIT(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GRPX_XAQ_LIMIT(a) (a)
#define arguments_CAVM_SSO_GRPX_XAQ_LIMIT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_gw_eco
 *
 * INTERNAL: SSO PF GW ECO Register
 */
union cavm_sso_gw_eco
{
    uint64_t u;
    struct cavm_sso_gw_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t eco_rw                : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_gw_eco_s cn; */
};
typedef union cavm_sso_gw_eco cavm_sso_gw_eco_t;

#define CAVM_SSO_GW_ECO CAVM_SSO_GW_ECO_FUNC()
static inline uint64_t CAVM_SSO_GW_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GW_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001038ll;
    __cavm_csr_fatal("SSO_GW_ECO", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GW_ECO cavm_sso_gw_eco_t
#define bustype_CAVM_SSO_GW_ECO CSR_TYPE_NCB
#define basename_CAVM_SSO_GW_ECO "SSO_GW_ECO"
#define device_bar_CAVM_SSO_GW_ECO 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GW_ECO 0
#define arguments_CAVM_SSO_GW_ECO -1,-1,-1,-1

/**
 * Register (NCB) sso_gwe_cfg
 *
 * SSO PF Get-Work Examiner Configuration Register
 * This register controls the operation of the get-work examiner (GWE).
 */
union cavm_sso_gwe_cfg
{
    uint64_t u;
    struct cavm_sso_gwe_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t dis_wgt_credit        : 1;  /**< [  8:  8](R/W) Disable hardware-group weight credits. When set, groups have infinite weight credit. */
        uint64_t ws_retries            : 8;  /**< [  7:  0](R/W) Work slot retries. When a given work-slot performs this number of retries without
                                                                 successfully finding work then NO_WORK will be returned. Values 0, 1, 2, 3 are reserved. */
#else /* Word 0 - Little Endian */
        uint64_t ws_retries            : 8;  /**< [  7:  0](R/W) Work slot retries. When a given work-slot performs this number of retries without
                                                                 successfully finding work then NO_WORK will be returned. Values 0, 1, 2, 3 are reserved. */
        uint64_t dis_wgt_credit        : 1;  /**< [  8:  8](R/W) Disable hardware-group weight credits. When set, groups have infinite weight credit. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_gwe_cfg_s cn; */
};
typedef union cavm_sso_gwe_cfg cavm_sso_gwe_cfg_t;

#define CAVM_SSO_GWE_CFG CAVM_SSO_GWE_CFG_FUNC()
static inline uint64_t CAVM_SSO_GWE_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GWE_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001098ll;
    __cavm_csr_fatal("SSO_GWE_CFG", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GWE_CFG cavm_sso_gwe_cfg_t
#define bustype_CAVM_SSO_GWE_CFG CSR_TYPE_NCB
#define basename_CAVM_SSO_GWE_CFG "SSO_GWE_CFG"
#define device_bar_CAVM_SSO_GWE_CFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GWE_CFG 0
#define arguments_CAVM_SSO_GWE_CFG -1,-1,-1,-1

/**
 * Register (NCB) sso_gwe_random
 *
 * SSO PF Get-Work Examiner Random Register
 * This register contains the random search start position for the get-work examiner (GWE).
 */
union cavm_sso_gwe_random
{
    uint64_t u;
    struct cavm_sso_gwe_random_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t rnd                   : 16; /**< [ 15:  0](R/W/H) Current random value, with low 8 bits indicating first hardware-group to start
                                                                 next get-work search at. Implementation defined as to when changes.
                                                                 For diagnostic use only, must not be zero.

                                                                 Internal:
                                                                 Changes on each work search, even if unsuccessful or retried.

                                                                 Uses 16, 15, 13, 4 tap LFSR (this choice is important to
                                                                 insure even hardware-group probabilities) with the formula:
                                                                 _ grp_to_start_arb_at = RND[7:0];
                                                                 _ RND_next[15:8] = RND[7:0];
                                                                 _ RND_next[7] = ^(RND[15:0] & 0xd008);
                                                                 _ RND_next[6] = ^(RND[15:0] & 0x6804);
                                                                 _ RND_next[5] = ^(RND[15:0] & 0x3402);
                                                                 _ RND_next[4] = ^(RND[15:0] & 0x1a01);
                                                                 _ RND_next[3] = ^(RND[15:0] & 0xdd08);
                                                                 _ RND_next[2] = ^(RND[15:0] & 0x6e84);
                                                                 _ RND_next[1] = ^(RND[15:0] & 0x3742);
                                                                 _ RND_next[0] = ^(RND[15:0] & 0x1ba1); */
#else /* Word 0 - Little Endian */
        uint64_t rnd                   : 16; /**< [ 15:  0](R/W/H) Current random value, with low 8 bits indicating first hardware-group to start
                                                                 next get-work search at. Implementation defined as to when changes.
                                                                 For diagnostic use only, must not be zero.

                                                                 Internal:
                                                                 Changes on each work search, even if unsuccessful or retried.

                                                                 Uses 16, 15, 13, 4 tap LFSR (this choice is important to
                                                                 insure even hardware-group probabilities) with the formula:
                                                                 _ grp_to_start_arb_at = RND[7:0];
                                                                 _ RND_next[15:8] = RND[7:0];
                                                                 _ RND_next[7] = ^(RND[15:0] & 0xd008);
                                                                 _ RND_next[6] = ^(RND[15:0] & 0x6804);
                                                                 _ RND_next[5] = ^(RND[15:0] & 0x3402);
                                                                 _ RND_next[4] = ^(RND[15:0] & 0x1a01);
                                                                 _ RND_next[3] = ^(RND[15:0] & 0xdd08);
                                                                 _ RND_next[2] = ^(RND[15:0] & 0x6e84);
                                                                 _ RND_next[1] = ^(RND[15:0] & 0x3742);
                                                                 _ RND_next[0] = ^(RND[15:0] & 0x1ba1); */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_gwe_random_s cn; */
};
typedef union cavm_sso_gwe_random cavm_sso_gwe_random_t;

#define CAVM_SSO_GWE_RANDOM CAVM_SSO_GWE_RANDOM_FUNC()
static inline uint64_t CAVM_SSO_GWE_RANDOM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_GWE_RANDOM_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000010b0ll;
    __cavm_csr_fatal("SSO_GWE_RANDOM", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_GWE_RANDOM cavm_sso_gwe_random_t
#define bustype_CAVM_SSO_GWE_RANDOM CSR_TYPE_NCB
#define basename_CAVM_SSO_GWE_RANDOM "SSO_GWE_RANDOM"
#define device_bar_CAVM_SSO_GWE_RANDOM 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_GWE_RANDOM 0
#define arguments_CAVM_SSO_GWE_RANDOM -1,-1,-1,-1

/**
 * Register (NCB) sso_hws#_arb
 *
 * SSO PF HWS Arbitration State Register
 * For diagnostic use, returns the arbitration state for each HWS.
 */
union cavm_sso_hwsx_arb
{
    uint64_t u;
    struct cavm_sso_hwsx_arb_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t aff_left              : 4;  /**< [ 19: 16](RO/H) HWS affinity arbitration credits remaining on the last serviced hardware-group. */
        uint64_t reserved_8_15         : 8;
        uint64_t last_grp              : 8;  /**< [  7:  0](RO/H) Last hardware-group number serviced by this HWS. */
#else /* Word 0 - Little Endian */
        uint64_t last_grp              : 8;  /**< [  7:  0](RO/H) Last hardware-group number serviced by this HWS. */
        uint64_t reserved_8_15         : 8;
        uint64_t aff_left              : 4;  /**< [ 19: 16](RO/H) HWS affinity arbitration credits remaining on the last serviced hardware-group. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_hwsx_arb_s cn; */
};
typedef union cavm_sso_hwsx_arb cavm_sso_hwsx_arb_t;

static inline uint64_t CAVM_SSO_HWSX_ARB(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_HWSX_ARB(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x860040000100ll + 0x100000ll * ((a) & 0x1f);
    __cavm_csr_fatal("SSO_HWSX_ARB", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_HWSX_ARB(a) cavm_sso_hwsx_arb_t
#define bustype_CAVM_SSO_HWSX_ARB(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_HWSX_ARB(a) "SSO_HWSX_ARB"
#define device_bar_CAVM_SSO_HWSX_ARB(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_HWSX_ARB(a) (a)
#define arguments_CAVM_SSO_HWSX_ARB(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_hws#_gmctl
 *
 * SSO PF HWS Guest Machine Control Register
 */
union cavm_sso_hwsx_gmctl
{
    uint64_t u;
    struct cavm_sso_hwsx_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t gw_indx_ena           : 1;  /**< [ 16: 16](R/W) Get work indexeded enable.
                                                                 0 = Get work indexed operations for the given HWS will immediately return
                                                                 error response.
                                                                 1 = Get-work indexed operations are allowed. However software can only perform
                                                                 get-work indexed for entries that were previously descheduled by a HWS, and have
                                                                 a vhgroup which has a valid guest-group mapping for the GMID which is performing
                                                                 the get-work indexed.

                                                                 Violation of these conditions may result in unpredictable behavior, including
                                                                 corruption of other GMIDs using SSO. */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) GMID assigned to this VHWS.
                                                                 Used to translate the following CSRs:

                                                                   * SSOW_VHWS()_GRPMSK_CHG()[GGRP].
                                                                   * SSOW_VHWS()_TAG[GGRP].
                                                                   * SSOW_VHWS()_LINKS[GGRP].
                                                                   * SSOW_VHWS()_OP_UPD_WQP_GRP0[GGRP].
                                                                   * SSOW_VHWS()_OP_SWTAG_NOSCHED[GGRP].
                                                                   * SSOW_VHWS()_OP_SWTAG_FULL0[GGRP].
                                                                   * SSOW_VHWS()_OP_SWTAG_DESCHED[GGRP].
                                                                   * SSOW_VHWS()_OP_GET_WORK0[GGRP].
                                                                   * SSOW_VHWS()_OP_GET_WORK0/1's SSOW_GET_WORK_ADDR_S[INDEX_GGRP_MASK].

                                                                 If 0x0, (which normally represents a disabled-GMID), results are unpredictable.

                                                                 Else if 0x1, then the above CSRs will not be translated; the value read from the
                                                                 field above will be a hardware-group number.

                                                                 Else (if not 0x0 nor 0x1), see the CSR descriptions above for the
                                                                 transformations performed; which generally use SSO_PF_MAP(). */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) GMID assigned to this VHWS.
                                                                 Used to translate the following CSRs:

                                                                   * SSOW_VHWS()_GRPMSK_CHG()[GGRP].
                                                                   * SSOW_VHWS()_TAG[GGRP].
                                                                   * SSOW_VHWS()_LINKS[GGRP].
                                                                   * SSOW_VHWS()_OP_UPD_WQP_GRP0[GGRP].
                                                                   * SSOW_VHWS()_OP_SWTAG_NOSCHED[GGRP].
                                                                   * SSOW_VHWS()_OP_SWTAG_FULL0[GGRP].
                                                                   * SSOW_VHWS()_OP_SWTAG_DESCHED[GGRP].
                                                                   * SSOW_VHWS()_OP_GET_WORK0[GGRP].
                                                                   * SSOW_VHWS()_OP_GET_WORK0/1's SSOW_GET_WORK_ADDR_S[INDEX_GGRP_MASK].

                                                                 If 0x0, (which normally represents a disabled-GMID), results are unpredictable.

                                                                 Else if 0x1, then the above CSRs will not be translated; the value read from the
                                                                 field above will be a hardware-group number.

                                                                 Else (if not 0x0 nor 0x1), see the CSR descriptions above for the
                                                                 transformations performed; which generally use SSO_PF_MAP(). */
        uint64_t gw_indx_ena           : 1;  /**< [ 16: 16](R/W) Get work indexeded enable.
                                                                 0 = Get work indexed operations for the given HWS will immediately return
                                                                 error response.
                                                                 1 = Get-work indexed operations are allowed. However software can only perform
                                                                 get-work indexed for entries that were previously descheduled by a HWS, and have
                                                                 a vhgroup which has a valid guest-group mapping for the GMID which is performing
                                                                 the get-work indexed.

                                                                 Violation of these conditions may result in unpredictable behavior, including
                                                                 corruption of other GMIDs using SSO. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_hwsx_gmctl_s cn; */
};
typedef union cavm_sso_hwsx_gmctl cavm_sso_hwsx_gmctl_t;

static inline uint64_t CAVM_SSO_HWSX_GMCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_HWSX_GMCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x860040000200ll + 0x100000ll * ((a) & 0x1f);
    __cavm_csr_fatal("SSO_HWSX_GMCTL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_HWSX_GMCTL(a) cavm_sso_hwsx_gmctl_t
#define bustype_CAVM_SSO_HWSX_GMCTL(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_HWSX_GMCTL(a) "SSO_HWSX_GMCTL"
#define device_bar_CAVM_SSO_HWSX_GMCTL(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_HWSX_GMCTL(a) (a)
#define arguments_CAVM_SSO_HWSX_GMCTL(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_hws#_s#_grpmsk#
 *
 * SSO PF HWS Hardware-Group Mask Registers
 * These registers select which hardware-group(s) a HWS belongs to. There are 2 sets of
 * masks per HWS, each with 1 register corresponding to 64 hardware-groups.
 *
 * Note bit-fields are indexed by hardware-group, not the guest-group; therefore this
 * register should not be exposed as-is to guest drivers.
 */
union cavm_sso_hwsx_sx_grpmskx
{
    uint64_t u;
    struct cavm_sso_hwsx_sx_grpmskx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t grp_msk               : 64; /**< [ 63:  0](R/W) HWS hardware-group mask. A one in any bit position sets the HWS's membership in
                                                                 the corresponding hardware-group for hardware-groups <63:0>.

                                                                 A value of 0x0 in GRPMSK for a given HWS prevents the HWS from receiving new
                                                                 work. HWSs that will never receive work should use GRPMSK=0x0; while this
                                                                 setting is not special in SSO, for backward and forward compatibility this may
                                                                 enable reallocation of internal resources to the remaining (nonzero-mask)
                                                                 hardware work-slots.

                                                                 This register is intended only for large-scale save-restore of masks.
                                                                 Individual changes should use SSOW_VHWS()_GRPMSK_CHG().

                                                                 Internal:
                                                                 SSO virtualization will only allow PF access; this register will only be used
                                                                 for paging HWS in or out.  Guests must use SSOW_VHWS()_GRPMSK_CHG(). */
#else /* Word 0 - Little Endian */
        uint64_t grp_msk               : 64; /**< [ 63:  0](R/W) HWS hardware-group mask. A one in any bit position sets the HWS's membership in
                                                                 the corresponding hardware-group for hardware-groups <63:0>.

                                                                 A value of 0x0 in GRPMSK for a given HWS prevents the HWS from receiving new
                                                                 work. HWSs that will never receive work should use GRPMSK=0x0; while this
                                                                 setting is not special in SSO, for backward and forward compatibility this may
                                                                 enable reallocation of internal resources to the remaining (nonzero-mask)
                                                                 hardware work-slots.

                                                                 This register is intended only for large-scale save-restore of masks.
                                                                 Individual changes should use SSOW_VHWS()_GRPMSK_CHG().

                                                                 Internal:
                                                                 SSO virtualization will only allow PF access; this register will only be used
                                                                 for paging HWS in or out.  Guests must use SSOW_VHWS()_GRPMSK_CHG(). */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_hwsx_sx_grpmskx_s cn; */
};
typedef union cavm_sso_hwsx_sx_grpmskx cavm_sso_hwsx_sx_grpmskx_t;

static inline uint64_t CAVM_SSO_HWSX_SX_GRPMSKX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_HWSX_SX_GRPMSKX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=1) && (c==0)))
        return 0x860040001000ll + 0x100000ll * ((a) & 0x1f) + 0x20ll * ((b) & 0x1) + 8ll * ((c) & 0x0);
    __cavm_csr_fatal("SSO_HWSX_SX_GRPMSKX", 3, a, b, c, 0);
   return 0;
}

#define typedef_CAVM_SSO_HWSX_SX_GRPMSKX(a,b,c) cavm_sso_hwsx_sx_grpmskx_t
#define bustype_CAVM_SSO_HWSX_SX_GRPMSKX(a,b,c) CSR_TYPE_NCB
#define basename_CAVM_SSO_HWSX_SX_GRPMSKX(a,b,c) "SSO_HWSX_SX_GRPMSKX"
#define device_bar_CAVM_SSO_HWSX_SX_GRPMSKX(a,b,c) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_HWSX_SX_GRPMSKX(a,b,c) (a)
#define arguments_CAVM_SSO_HWSX_SX_GRPMSKX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) sso_ient#_grp
 *
 * SSO PF Internal Entry Hardware-Group Registers
 * Returns unit memory status for an index.
 */
union cavm_sso_ientx_grp
{
    uint64_t u;
    struct cavm_sso_ientx_grp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t head                  : 1;  /**< [ 61: 61](RO/H) SSO entry is at the head of a tag chain that is descheduled. */
        uint64_t nosched               : 1;  /**< [ 60: 60](RO/H) The nosched bit for the SSO entry. */
        uint64_t reserved_56_59        : 4;
        uint64_t grp                   : 8;  /**< [ 55: 48](RO/H) Hardware-group of the SSO entry. This register is typically only for diagnostic
                                                                 use; however if this value is delivered to guest drivers, [GRP] must be
                                                                 converted to a guest-group by the hypervisor software. */
        uint64_t reserved_0_47         : 48;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_47         : 48;
        uint64_t grp                   : 8;  /**< [ 55: 48](RO/H) Hardware-group of the SSO entry. This register is typically only for diagnostic
                                                                 use; however if this value is delivered to guest drivers, [GRP] must be
                                                                 converted to a guest-group by the hypervisor software. */
        uint64_t reserved_56_59        : 4;
        uint64_t nosched               : 1;  /**< [ 60: 60](RO/H) The nosched bit for the SSO entry. */
        uint64_t head                  : 1;  /**< [ 61: 61](RO/H) SSO entry is at the head of a tag chain that is descheduled. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ientx_grp_s cn; */
};
typedef union cavm_sso_ientx_grp cavm_sso_ientx_grp_t;

static inline uint64_t CAVM_SSO_IENTX_GRP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IENTX_GRP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0020000ll + 8ll * ((a) & 0x3ff);
    __cavm_csr_fatal("SSO_IENTX_GRP", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IENTX_GRP(a) cavm_sso_ientx_grp_t
#define bustype_CAVM_SSO_IENTX_GRP(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IENTX_GRP(a) "SSO_IENTX_GRP"
#define device_bar_CAVM_SSO_IENTX_GRP(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IENTX_GRP(a) (a)
#define arguments_CAVM_SSO_IENTX_GRP(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_links
 *
 * SSO PF Internal Entry Links Registers
 * Returns unit memory status for an index.
 */
union cavm_sso_ientx_links
{
    uint64_t u;
    struct cavm_sso_ientx_links_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t prev_index            : 10; /**< [ 25: 16](RO/H) The previous entry in the tag chain. Unpredictable if the entry is at the head of the list
                                                                 or the head of a conflicted tag chain. */
        uint64_t reserved_11_15        : 5;
        uint64_t next_index_vld        : 1;  /**< [ 10: 10](RO/H) The [NEXT_INDEX] is valid. Unpredictable unless the entry is the tail entry of an atomic tag chain. */
        uint64_t next_index            : 10; /**< [  9:  0](RO/H) The next entry in the tag chain or conflicted tag chain. Unpredictable if the entry is at
                                                                 the tail of the list. */
#else /* Word 0 - Little Endian */
        uint64_t next_index            : 10; /**< [  9:  0](RO/H) The next entry in the tag chain or conflicted tag chain. Unpredictable if the entry is at
                                                                 the tail of the list. */
        uint64_t next_index_vld        : 1;  /**< [ 10: 10](RO/H) The [NEXT_INDEX] is valid. Unpredictable unless the entry is the tail entry of an atomic tag chain. */
        uint64_t reserved_11_15        : 5;
        uint64_t prev_index            : 10; /**< [ 25: 16](RO/H) The previous entry in the tag chain. Unpredictable if the entry is at the head of the list
                                                                 or the head of a conflicted tag chain. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ientx_links_s cn; */
};
typedef union cavm_sso_ientx_links cavm_sso_ientx_links_t;

static inline uint64_t CAVM_SSO_IENTX_LINKS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IENTX_LINKS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0060000ll + 8ll * ((a) & 0x3ff);
    __cavm_csr_fatal("SSO_IENTX_LINKS", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IENTX_LINKS(a) cavm_sso_ientx_links_t
#define bustype_CAVM_SSO_IENTX_LINKS(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IENTX_LINKS(a) "SSO_IENTX_LINKS"
#define device_bar_CAVM_SSO_IENTX_LINKS(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IENTX_LINKS(a) (a)
#define arguments_CAVM_SSO_IENTX_LINKS(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_pendtag
 *
 * SSO PF Internal Entry Pending Tag Registers
 * Returns unit memory status for an index.
 */
union cavm_sso_ientx_pendtag
{
    uint64_t u;
    struct cavm_sso_ientx_pendtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t pend_switch           : 1;  /**< [ 37: 37](RO/H) Set when there is a pending non-UNTAGGED SWTAG or SWTAG_FULL and the SSO entry has not
                                                                 left the list for the original tag. */
        uint64_t reserved_34_36        : 3;
        uint64_t pend_tt               : 2;  /**< [ 33: 32](RO/H) The next tag type for the new tag list when PEND_SWITCH is set. Enumerated by SSO_TT_E. */
        uint64_t pend_tag              : 32; /**< [ 31:  0](RO/H) The next tag for the new tag list when PEND_SWITCH is set. */
#else /* Word 0 - Little Endian */
        uint64_t pend_tag              : 32; /**< [ 31:  0](RO/H) The next tag for the new tag list when PEND_SWITCH is set. */
        uint64_t pend_tt               : 2;  /**< [ 33: 32](RO/H) The next tag type for the new tag list when PEND_SWITCH is set. Enumerated by SSO_TT_E. */
        uint64_t reserved_34_36        : 3;
        uint64_t pend_switch           : 1;  /**< [ 37: 37](RO/H) Set when there is a pending non-UNTAGGED SWTAG or SWTAG_FULL and the SSO entry has not
                                                                 left the list for the original tag. */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ientx_pendtag_s cn; */
};
typedef union cavm_sso_ientx_pendtag cavm_sso_ientx_pendtag_t;

static inline uint64_t CAVM_SSO_IENTX_PENDTAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IENTX_PENDTAG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0040000ll + 8ll * ((a) & 0x3ff);
    __cavm_csr_fatal("SSO_IENTX_PENDTAG", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IENTX_PENDTAG(a) cavm_sso_ientx_pendtag_t
#define bustype_CAVM_SSO_IENTX_PENDTAG(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IENTX_PENDTAG(a) "SSO_IENTX_PENDTAG"
#define device_bar_CAVM_SSO_IENTX_PENDTAG(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IENTX_PENDTAG(a) (a)
#define arguments_CAVM_SSO_IENTX_PENDTAG(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_qlinks
 *
 * SSO PF Internal Queue Links Registers
 * Returns unit memory status for an index.
 */
union cavm_sso_ientx_qlinks
{
    uint64_t u;
    struct cavm_sso_ientx_qlinks_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t next_index            : 12; /**< [ 11:  0](RO/H) The next entry in the AQ/CQ/DQ. */
#else /* Word 0 - Little Endian */
        uint64_t next_index            : 12; /**< [ 11:  0](RO/H) The next entry in the AQ/CQ/DQ. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ientx_qlinks_s cn; */
};
typedef union cavm_sso_ientx_qlinks cavm_sso_ientx_qlinks_t;

static inline uint64_t CAVM_SSO_IENTX_QLINKS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IENTX_QLINKS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0080000ll + 8ll * ((a) & 0x3ff);
    __cavm_csr_fatal("SSO_IENTX_QLINKS", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IENTX_QLINKS(a) cavm_sso_ientx_qlinks_t
#define bustype_CAVM_SSO_IENTX_QLINKS(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IENTX_QLINKS(a) "SSO_IENTX_QLINKS"
#define device_bar_CAVM_SSO_IENTX_QLINKS(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IENTX_QLINKS(a) (a)
#define arguments_CAVM_SSO_IENTX_QLINKS(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_tag
 *
 * SSO PF Internal Entry Tag Registers
 * Returns unit memory status for an index.
 */
union cavm_sso_ientx_tag
{
    uint64_t u;
    struct cavm_sso_ientx_tag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_39_63        : 25;
        uint64_t tailc                 : 1;  /**< [ 38: 38](RO/H) The SSO entry is the tail of tag chain that is conflicted. No conflicted chain exists if
                                                                 [TAIL] is also set on the same entry. */
        uint64_t tail                  : 1;  /**< [ 37: 37](RO/H) The SSO entry is the tail of tag chain that is descheduled.
                                                                 Internal:
                                                                 Read from the SOC. */
        uint64_t reserved_34_36        : 3;
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type of the SSO entry. Enumerated by SSO_TT_E. */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag of the SSO entry. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag of the SSO entry. */
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type of the SSO entry. Enumerated by SSO_TT_E. */
        uint64_t reserved_34_36        : 3;
        uint64_t tail                  : 1;  /**< [ 37: 37](RO/H) The SSO entry is the tail of tag chain that is descheduled.
                                                                 Internal:
                                                                 Read from the SOC. */
        uint64_t tailc                 : 1;  /**< [ 38: 38](RO/H) The SSO entry is the tail of tag chain that is conflicted. No conflicted chain exists if
                                                                 [TAIL] is also set on the same entry. */
        uint64_t reserved_39_63        : 25;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ientx_tag_s cn; */
};
typedef union cavm_sso_ientx_tag cavm_sso_ientx_tag_t;

static inline uint64_t CAVM_SSO_IENTX_TAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IENTX_TAG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0000000ll + 8ll * ((a) & 0x3ff);
    __cavm_csr_fatal("SSO_IENTX_TAG", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IENTX_TAG(a) cavm_sso_ientx_tag_t
#define bustype_CAVM_SSO_IENTX_TAG(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IENTX_TAG(a) "SSO_IENTX_TAG"
#define device_bar_CAVM_SSO_IENTX_TAG(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IENTX_TAG(a) (a)
#define arguments_CAVM_SSO_IENTX_TAG(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_wqp
 *
 * SSO PF Internal Entry WQP Registers
 * Returns unit memory status for an index.
 */
union cavm_sso_ientx_wqp
{
    uint64_t u;
    struct cavm_sso_ientx_wqp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](RO/H) Work queue IOVA held in the SSO entry.
                                                                 Bits <63:49> are a sign extension of <48>.  Bits <2:0> are 0x0. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](RO/H) Work queue IOVA held in the SSO entry.
                                                                 Bits <63:49> are a sign extension of <48>.  Bits <2:0> are 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ientx_wqp_s cn; */
};
typedef union cavm_sso_ientx_wqp cavm_sso_ientx_wqp_t;

static inline uint64_t CAVM_SSO_IENTX_WQP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IENTX_WQP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a00a0000ll + 8ll * ((a) & 0x3ff);
    __cavm_csr_fatal("SSO_IENTX_WQP", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IENTX_WQP(a) cavm_sso_ientx_wqp_t
#define bustype_CAVM_SSO_IENTX_WQP(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IENTX_WQP(a) "SSO_IENTX_WQP"
#define device_bar_CAVM_SSO_IENTX_WQP(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IENTX_WQP(a) (a)
#define arguments_CAVM_SSO_IENTX_WQP(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ipl_conf#
 *
 * SSO PF Hardware-Group Conflicted List State Registers
 * Returns list status for the conflicted list indexed by hardware-group. Register
 * fields are identical to those in SSO_IPL_IAQ() above.
 */
union cavm_sso_ipl_confx
{
    uint64_t u;
    struct cavm_sso_ipl_confx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
#else /* Word 0 - Little Endian */
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ipl_confx_s cn; */
};
typedef union cavm_sso_ipl_confx cavm_sso_ipl_confx_t;

static inline uint64_t CAVM_SSO_IPL_CONFX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IPL_CONFX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860080080000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_IPL_CONFX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IPL_CONFX(a) cavm_sso_ipl_confx_t
#define bustype_CAVM_SSO_IPL_CONFX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IPL_CONFX(a) "SSO_IPL_CONFX"
#define device_bar_CAVM_SSO_IPL_CONFX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IPL_CONFX(a) (a)
#define arguments_CAVM_SSO_IPL_CONFX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ipl_desched#
 *
 * SSO PF Hardware-Group Deschedule List State Registers
 * Returns list status for the deschedule list indexed by hardware-group. Register
 * fields are identical to those in SSO_IPL_IAQ() above.
 */
union cavm_sso_ipl_deschedx
{
    uint64_t u;
    struct cavm_sso_ipl_deschedx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
#else /* Word 0 - Little Endian */
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ipl_deschedx_s cn; */
};
typedef union cavm_sso_ipl_deschedx cavm_sso_ipl_deschedx_t;

static inline uint64_t CAVM_SSO_IPL_DESCHEDX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IPL_DESCHEDX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860080060000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_IPL_DESCHEDX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IPL_DESCHEDX(a) cavm_sso_ipl_deschedx_t
#define bustype_CAVM_SSO_IPL_DESCHEDX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IPL_DESCHEDX(a) "SSO_IPL_DESCHEDX"
#define device_bar_CAVM_SSO_IPL_DESCHEDX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IPL_DESCHEDX(a) (a)
#define arguments_CAVM_SSO_IPL_DESCHEDX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ipl_free#
 *
 * SSO PF Free List State Registers
 * Returns list status.
 */
union cavm_sso_ipl_freex
{
    uint64_t u;
    struct cavm_sso_ipl_freex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t qnum_head             : 3;  /**< [ 61: 59](RO/H) Subqueue with current head. */
        uint64_t qnum_tail             : 3;  /**< [ 58: 56](RO/H) Subqueue for next tail. */
        uint64_t reserved_28_55        : 28;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in this subqueue. */
        uint64_t reserved_23_26        : 4;
        uint64_t queue_head            : 10; /**< [ 22: 13](RO/H) Index of entry at the head of this subqueue. */
        uint64_t reserved_10_12        : 3;
        uint64_t queue_tail            : 10; /**< [  9:  0](RO/H) Index of entry at the tail of this subqueue. */
#else /* Word 0 - Little Endian */
        uint64_t queue_tail            : 10; /**< [  9:  0](RO/H) Index of entry at the tail of this subqueue. */
        uint64_t reserved_10_12        : 3;
        uint64_t queue_head            : 10; /**< [ 22: 13](RO/H) Index of entry at the head of this subqueue. */
        uint64_t reserved_23_26        : 4;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in this subqueue. */
        uint64_t reserved_28_55        : 28;
        uint64_t qnum_tail             : 3;  /**< [ 58: 56](RO/H) Subqueue for next tail. */
        uint64_t qnum_head             : 3;  /**< [ 61: 59](RO/H) Subqueue with current head. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ipl_freex_s cn; */
};
typedef union cavm_sso_ipl_freex cavm_sso_ipl_freex_t;

static inline uint64_t CAVM_SSO_IPL_FREEX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IPL_FREEX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=4))
        return 0x860080000000ll + 8ll * ((a) & 0x7);
    __cavm_csr_fatal("SSO_IPL_FREEX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IPL_FREEX(a) cavm_sso_ipl_freex_t
#define bustype_CAVM_SSO_IPL_FREEX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IPL_FREEX(a) "SSO_IPL_FREEX"
#define device_bar_CAVM_SSO_IPL_FREEX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IPL_FREEX(a) (a)
#define arguments_CAVM_SSO_IPL_FREEX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ipl_iaq#
 *
 * SSO PF Hardware-Group IAQ List State Registers
 * Returns list status for the internal admission queue indexed by hardware-group.
 */
union cavm_sso_ipl_iaqx
{
    uint64_t u;
    struct cavm_sso_ipl_iaqx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
#else /* Word 0 - Little Endian */
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ipl_iaqx_s cn; */
};
typedef union cavm_sso_ipl_iaqx cavm_sso_ipl_iaqx_t;

static inline uint64_t CAVM_SSO_IPL_IAQX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_IPL_IAQX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860080040000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_IPL_IAQX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_IPL_IAQX(a) cavm_sso_ipl_iaqx_t
#define bustype_CAVM_SSO_IPL_IAQX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_IPL_IAQX(a) "SSO_IPL_IAQX"
#define device_bar_CAVM_SSO_IPL_IAQX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_IPL_IAQX(a) (a)
#define arguments_CAVM_SSO_IPL_IAQX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_nos_cnt
 *
 * SSO PF No-schedule Count Register
 * Contains the number of work-queue entries on the no-schedule list.
 */
union cavm_sso_nos_cnt
{
    uint64_t u;
    struct cavm_sso_nos_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t nos_cnt               : 13; /**< [ 12:  0](RO/H) Number of work-queue entries on the no-schedule list. */
#else /* Word 0 - Little Endian */
        uint64_t nos_cnt               : 13; /**< [ 12:  0](RO/H) Number of work-queue entries on the no-schedule list. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_nos_cnt_s cn; */
};
typedef union cavm_sso_nos_cnt cavm_sso_nos_cnt_t;

#define CAVM_SSO_NOS_CNT CAVM_SSO_NOS_CNT_FUNC()
static inline uint64_t CAVM_SSO_NOS_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_NOS_CNT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001040ll;
    __cavm_csr_fatal("SSO_NOS_CNT", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_NOS_CNT cavm_sso_nos_cnt_t
#define bustype_CAVM_SSO_NOS_CNT CSR_TYPE_NCB
#define basename_CAVM_SSO_NOS_CNT "SSO_NOS_CNT"
#define device_bar_CAVM_SSO_NOS_CNT 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_NOS_CNT 0
#define arguments_CAVM_SSO_NOS_CNT -1,-1,-1,-1

/**
 * Register (NCB) sso_nw_tim
 *
 * SSO PF New-Work Timer Period Register
 * Sets the minimum period for a new-work-request timeout. The period is specified in n-1
 * notation, with the increment value of 1024 clock cycles. Thus, a value of 0x0 in this register
 * translates to 1024 cycles, 0x1 translates to 2048 cycles, 0x2 translates to 3072 cycles, etc.
 */
union cavm_sso_nw_tim
{
    uint64_t u;
    struct cavm_sso_nw_tim_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t nw_tim                : 10; /**< [  9:  0](R/W) New-work-timer period.
                                                                 0x0 = 1024 clock cycles.
                                                                 0x1 = 2048 clock cycles.
                                                                 0x2 = 3072 clock cycles.
                                                                 _ ... etc. */
#else /* Word 0 - Little Endian */
        uint64_t nw_tim                : 10; /**< [  9:  0](R/W) New-work-timer period.
                                                                 0x0 = 1024 clock cycles.
                                                                 0x1 = 2048 clock cycles.
                                                                 0x2 = 3072 clock cycles.
                                                                 _ ... etc. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_nw_tim_s cn; */
};
typedef union cavm_sso_nw_tim cavm_sso_nw_tim_t;

#define CAVM_SSO_NW_TIM CAVM_SSO_NW_TIM_FUNC()
static inline uint64_t CAVM_SSO_NW_TIM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_NW_TIM_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001028ll;
    __cavm_csr_fatal("SSO_NW_TIM", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_NW_TIM cavm_sso_nw_tim_t
#define bustype_CAVM_SSO_NW_TIM CSR_TYPE_NCB
#define basename_CAVM_SSO_NW_TIM "SSO_NW_TIM"
#define device_bar_CAVM_SSO_NW_TIM 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_NW_TIM 0
#define arguments_CAVM_SSO_NW_TIM -1,-1,-1,-1

/**
 * Register (NCB) sso_page_cnt
 *
 * SSO PF In-use Page Count Register
 */
union cavm_sso_page_cnt
{
    uint64_t u;
    struct cavm_sso_page_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t cnt                   : 32; /**< [ 31:  0](R/W/H) In-use page count. Number of pages SSO has allocated and not yet returned. Excludes unused
                                                                 pointers cached in SSO. Hardware updates this register. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 32; /**< [ 31:  0](R/W/H) In-use page count. Number of pages SSO has allocated and not yet returned. Excludes unused
                                                                 pointers cached in SSO. Hardware updates this register. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_page_cnt_s cn; */
};
typedef union cavm_sso_page_cnt cavm_sso_page_cnt_t;

#define CAVM_SSO_PAGE_CNT CAVM_SSO_PAGE_CNT_FUNC()
static inline uint64_t CAVM_SSO_PAGE_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PAGE_CNT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001090ll;
    __cavm_csr_fatal("SSO_PAGE_CNT", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PAGE_CNT cavm_sso_page_cnt_t
#define bustype_CAVM_SSO_PAGE_CNT CSR_TYPE_NCB
#define basename_CAVM_SSO_PAGE_CNT "SSO_PAGE_CNT"
#define device_bar_CAVM_SSO_PAGE_CNT 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_PAGE_CNT 0
#define arguments_CAVM_SSO_PAGE_CNT -1,-1,-1,-1

/**
 * Register (NCB) sso_pf_map#
 *
 * SSO PF VF Mapping Registers
 * These registers map GMIDs and guest-groups to hardware-groups, and GMIDs and
 * hardware-groups to GGRPs. An entry must not be changed if there is traffic in flight
 * that may potentially match that entry's GMID/VHGRP/GGRP.
 *
 * The mapping algorithm depends on the type of operation:
 *
 * * Coprocessors make add-work requests with a GMID and guest-group, which
 *   is translated to a hardware-group as follows:
 *
 *   o Regardless of this mapping table, GMID 0x0 is always invalid and use of 0x0 will
 *     cause a SSO_ERR0[GMID0] error and the add-work is dropped.
 *
 *   o else, regardless of this mapping table, GMID 0x1 is always a one-to-one mapping
 *     of GGRP into VHGRP.
 *
 *   o else (excluding GMID 0x0 and 0x1), a lookup is performed across all SSO_PF_MAP()
 *     entries, looking for a entry where [VALID] is set, the request's GMID = entry's
 *     [GMID], and the request's GGRP = entry's [GGRP].
 *
 *   o if the lookup hits a single entry, the resulting hardware-group is from the
 *     matching entry's [VHGRP].
 *
 *   o if the lookup does not hit any entries a SSO_ERR0[GMID_UNMAP] error is reported
 *     and the add-work is dropped.
 *
 *   o if the lookup hits duplicate entries a SSO_ERR0[GMID_MULTI] error is reported
 *     and the add-work is dropped.
 *
 * * HWS operations make guest-group requests, where the GMID is from
 *   SSO_HWS()_GMCTL[GMID] and the GGRP is from SSOW_VHWS()_GRPMSK_CHG()[GGRP],
 *   SSOW_VHWS()_OP_GET_WORK0[GGRP], SSOW_VHWS()_OP_UPD_WQP_GRP0[GGRP],
 *   SSOW_VHWS()_OP_SWTAG_NOSCHED[GGRP], SSOW_VHWS()_OP_SWTAG_FULL0[GGRP],
 *   SSOW_VHWS()_OP_SWTAG_DESCHED[GGRP], or SSOW_VHWS()_OP_GET_WORK0/1's
 *   SSOW_GET_WORK_ADDR_S[INDEX_GGRP_MASK]. These are translated to a hardware-group as
 *   follows:
 *
 *   o Regardless of this mapping table, using GMID 0x0 is unpredictable.
 *
 *   o else, regardless of this mapping table, GMID 0x1 is always a one-to-one mapping
 *     of GGRP into VHGRP.
 *
 *   o else (excluding GMID 0x0 and 0x1), a lookup is performed across all SSO_PF_MAP()
 *     entries, looking for a entry where [VALID] is set, the request's GMID = entry's
 *     [GMID], and the request's GGRP = entry's [GGRP].
 *
 *   o if the lookup hits a single entry, the resulting hardware-group is from the
 *     matching entry's [VHGRP].
 *
 *   o if the lookup does not hit any entries a SSO_ERR2[WS_UNMAP] error is reported
 *     and the group-mask change or switch-tag is dropped.
 *
 *   o if the lookup hits duplicate entries a SSO_ERR2[WS_MULTI] error is reported and
 *     the group-mask change or switch-tag is dropped.
 *
 * * HWS reads, where the GMID is from SSO_HWS()_GMCTL[GMID], return a guest-group in
 *   SSOW_VHWS()_TAG[GGRP] and SSOW_VHWS()_LINKS[GGRP]. These are translated from the
 *   HWS's storage of a hardware-group to the operation's read value's guest-group
 *   follows:
 *
 *   o Regardless of this mapping table, using GMID 0x0 is unprefictable.
 *
 *   o else, regardless of this mapping table, GMID 0x1 is always a one-to-one mapping
 *     of VHGRP into GGRP.
 *
 *   o else (excluding GMID 0x0 and 0x1), a lookup is performed across all SSO_PF_MAP()
 *     entries, looking for a entry where [VALID] is set, the request's GMID = entry's
 *     [GMID], and the request's VHGRP = entry's [VHGRP].
 *
 *   o if the lookup hits a single entry, the resulting guest-group is from the
 *     matching entry's [GGRP].
 *
 *   o if the lookup does not hit any entriesa a SSO_ERR2[WS_UNMAP] error is reported
 *     and the GGRP returned is the VHGRP.
 *
 *  o if the lookup hits duplicate entries a SSO_ERR2[WS_MULTI] error is reported and
 *     the GGRP returned is the VHGRP.
 */
union cavm_sso_pf_mapx
{
    uint64_t u;
    struct cavm_sso_pf_mapx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t valid                 : 1;  /**< [ 63: 63](R/W) This entry is valid for matching. See register description. */
        uint64_t reserved_38_62        : 25;
        uint64_t vhgrp                 : 6;  /**< [ 37: 32](R/W) Entry's hardware-group. See register description. */
        uint64_t reserved_26_31        : 6;
        uint64_t ggrp                  : 10; /**< [ 25: 16](R/W) Entry's guest-group. See register description. */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Entry's guest machine ID. See register description. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Entry's guest machine ID. See register description. */
        uint64_t ggrp                  : 10; /**< [ 25: 16](R/W) Entry's guest-group. See register description. */
        uint64_t reserved_26_31        : 6;
        uint64_t vhgrp                 : 6;  /**< [ 37: 32](R/W) Entry's hardware-group. See register description. */
        uint64_t reserved_38_62        : 25;
        uint64_t valid                 : 1;  /**< [ 63: 63](R/W) This entry is valid for matching. See register description. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_pf_mapx_s cn; */
};
typedef union cavm_sso_pf_mapx cavm_sso_pf_mapx_t;

static inline uint64_t CAVM_SSO_PF_MAPX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PF_MAPX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=71))
        return 0x860000004000ll + 8ll * ((a) & 0x7f);
    __cavm_csr_fatal("SSO_PF_MAPX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PF_MAPX(a) cavm_sso_pf_mapx_t
#define bustype_CAVM_SSO_PF_MAPX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_PF_MAPX(a) "SSO_PF_MAPX"
#define device_bar_CAVM_SSO_PF_MAPX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_PF_MAPX(a) (a)
#define arguments_CAVM_SSO_PF_MAPX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_mbox_ena_w1c#
 *
 * SSO PF Mailbox Enable Clear Registers
 * This register clears interrupt enable bits.
 */
union cavm_sso_pf_mbox_ena_w1cx
{
    uint64_t u;
    struct cavm_sso_pf_mbox_ena_w1cx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for SSO_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for SSO_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_pf_mbox_ena_w1cx_s cn; */
};
typedef union cavm_sso_pf_mbox_ena_w1cx cavm_sso_pf_mbox_ena_w1cx_t;

static inline uint64_t CAVM_SSO_PF_MBOX_ENA_W1CX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PF_MBOX_ENA_W1CX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x860000001480ll + 8ll * ((a) & 0x0);
    __cavm_csr_fatal("SSO_PF_MBOX_ENA_W1CX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PF_MBOX_ENA_W1CX(a) cavm_sso_pf_mbox_ena_w1cx_t
#define bustype_CAVM_SSO_PF_MBOX_ENA_W1CX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_PF_MBOX_ENA_W1CX(a) "SSO_PF_MBOX_ENA_W1CX"
#define device_bar_CAVM_SSO_PF_MBOX_ENA_W1CX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_PF_MBOX_ENA_W1CX(a) (a)
#define arguments_CAVM_SSO_PF_MBOX_ENA_W1CX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_mbox_ena_w1s#
 *
 * SSO PF Mailbox Enable Set Registers
 * This register sets interrupt enable bits.
 */
union cavm_sso_pf_mbox_ena_w1sx
{
    uint64_t u;
    struct cavm_sso_pf_mbox_ena_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for SSO_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for SSO_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_pf_mbox_ena_w1sx_s cn; */
};
typedef union cavm_sso_pf_mbox_ena_w1sx cavm_sso_pf_mbox_ena_w1sx_t;

static inline uint64_t CAVM_SSO_PF_MBOX_ENA_W1SX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PF_MBOX_ENA_W1SX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x8600000014c0ll + 8ll * ((a) & 0x0);
    __cavm_csr_fatal("SSO_PF_MBOX_ENA_W1SX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PF_MBOX_ENA_W1SX(a) cavm_sso_pf_mbox_ena_w1sx_t
#define bustype_CAVM_SSO_PF_MBOX_ENA_W1SX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_PF_MBOX_ENA_W1SX(a) "SSO_PF_MBOX_ENA_W1SX"
#define device_bar_CAVM_SSO_PF_MBOX_ENA_W1SX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_PF_MBOX_ENA_W1SX(a) (a)
#define arguments_CAVM_SSO_PF_MBOX_ENA_W1SX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_mbox_int#
 *
 * SSO PF Mailbox Interrupt Registers
 */
union cavm_sso_pf_mbox_intx
{
    uint64_t u;
    struct cavm_sso_pf_mbox_intx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 SSO_VHGRP(0..63)_PF_MBOX(1) is written. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 SSO_VHGRP(0..63)_PF_MBOX(1) is written. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_pf_mbox_intx_s cn; */
};
typedef union cavm_sso_pf_mbox_intx cavm_sso_pf_mbox_intx_t;

static inline uint64_t CAVM_SSO_PF_MBOX_INTX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PF_MBOX_INTX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x860000001400ll + 8ll * ((a) & 0x0);
    __cavm_csr_fatal("SSO_PF_MBOX_INTX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PF_MBOX_INTX(a) cavm_sso_pf_mbox_intx_t
#define bustype_CAVM_SSO_PF_MBOX_INTX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_PF_MBOX_INTX(a) "SSO_PF_MBOX_INTX"
#define device_bar_CAVM_SSO_PF_MBOX_INTX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_PF_MBOX_INTX(a) (a)
#define arguments_CAVM_SSO_PF_MBOX_INTX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_mbox_int_w1s#
 *
 * SSO PF Mailbox Interrupt Set Registers
 * This register sets interrupt bits.
 */
union cavm_sso_pf_mbox_int_w1sx
{
    uint64_t u;
    struct cavm_sso_pf_mbox_int_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets SSO_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets SSO_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_pf_mbox_int_w1sx_s cn; */
};
typedef union cavm_sso_pf_mbox_int_w1sx cavm_sso_pf_mbox_int_w1sx_t;

static inline uint64_t CAVM_SSO_PF_MBOX_INT_W1SX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PF_MBOX_INT_W1SX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x860000001440ll + 8ll * ((a) & 0x0);
    __cavm_csr_fatal("SSO_PF_MBOX_INT_W1SX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PF_MBOX_INT_W1SX(a) cavm_sso_pf_mbox_int_w1sx_t
#define bustype_CAVM_SSO_PF_MBOX_INT_W1SX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_PF_MBOX_INT_W1SX(a) "SSO_PF_MBOX_INT_W1SX"
#define device_bar_CAVM_SSO_PF_MBOX_INT_W1SX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_PF_MBOX_INT_W1SX(a) (a)
#define arguments_CAVM_SSO_PF_MBOX_INT_W1SX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_msix_pba#
 *
 * SSO PF MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the SSO_PF_INT_VEC_E
 * enumeration.
 */
union cavm_sso_pf_msix_pbax
{
    uint64_t u;
    struct cavm_sso_pf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SSO_PF_MSIX_VEC()_CTL, enumerated by
                                                                 SSO_PF_INT_VEC_E. Bits that have no associated SSO_PF_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SSO_PF_MSIX_VEC()_CTL, enumerated by
                                                                 SSO_PF_INT_VEC_E. Bits that have no associated SSO_PF_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_pf_msix_pbax_s cn; */
};
typedef union cavm_sso_pf_msix_pbax cavm_sso_pf_msix_pbax_t;

static inline uint64_t CAVM_SSO_PF_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PF_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x8607000f0000ll + 8ll * ((a) & 0x0);
    __cavm_csr_fatal("SSO_PF_MSIX_PBAX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PF_MSIX_PBAX(a) cavm_sso_pf_msix_pbax_t
#define bustype_CAVM_SSO_PF_MSIX_PBAX(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_PF_MSIX_PBAX(a) "SSO_PF_MSIX_PBAX"
#define device_bar_CAVM_SSO_PF_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_SSO_PF_MSIX_PBAX(a) (a)
#define arguments_CAVM_SSO_PF_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_msix_vec#_addr
 *
 * SSO PF MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the SSO_PF_INT_VEC_E enumeration.
 */
union cavm_sso_pf_msix_vecx_addr
{
    uint64_t u;
    struct cavm_sso_pf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's SSO_PF_MSIX_VEC()_ADDR, SSO_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SSO_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_SSO_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's SSO_PF_MSIX_VEC()_ADDR, SSO_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SSO_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_SSO_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_pf_msix_vecx_addr_s cn; */
};
typedef union cavm_sso_pf_msix_vecx_addr cavm_sso_pf_msix_vecx_addr_t;

static inline uint64_t CAVM_SSO_PF_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PF_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x860700000000ll + 0x10ll * ((a) & 0x3);
    __cavm_csr_fatal("SSO_PF_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PF_MSIX_VECX_ADDR(a) cavm_sso_pf_msix_vecx_addr_t
#define bustype_CAVM_SSO_PF_MSIX_VECX_ADDR(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_PF_MSIX_VECX_ADDR(a) "SSO_PF_MSIX_VECX_ADDR"
#define device_bar_CAVM_SSO_PF_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_SSO_PF_MSIX_VECX_ADDR(a) (a)
#define arguments_CAVM_SSO_PF_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_msix_vec#_ctl
 *
 * SSO PF MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the SSO_PF_INT_VEC_E enumeration.
 */
union cavm_sso_pf_msix_vecx_ctl
{
    uint64_t u;
    struct cavm_sso_pf_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_pf_msix_vecx_ctl_s cn; */
};
typedef union cavm_sso_pf_msix_vecx_ctl cavm_sso_pf_msix_vecx_ctl_t;

static inline uint64_t CAVM_SSO_PF_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PF_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x860700000008ll + 0x10ll * ((a) & 0x3);
    __cavm_csr_fatal("SSO_PF_MSIX_VECX_CTL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PF_MSIX_VECX_CTL(a) cavm_sso_pf_msix_vecx_ctl_t
#define bustype_CAVM_SSO_PF_MSIX_VECX_CTL(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_PF_MSIX_VECX_CTL(a) "SSO_PF_MSIX_VECX_CTL"
#define device_bar_CAVM_SSO_PF_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_SSO_PF_MSIX_VECX_CTL(a) (a)
#define arguments_CAVM_SSO_PF_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_vhgrp#_mbox#
 *
 * SSO PF/VF Mailbox Registers
 */
union cavm_sso_pf_vhgrpx_mboxx
{
    uint64_t u;
    struct cavm_sso_pf_vhgrpx_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 SSO_VHGRP()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing SSO_PF_VHGRP(0..63)_MBOX(0) (but not
                                                                 SSO_VHGRP(0..63)_PF_MBOX(0)) will set the corresponding
                                                                 SSO_VHGRP()_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 SSO_VHGRP()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing SSO_PF_VHGRP(0..63)_MBOX(0) (but not
                                                                 SSO_VHGRP(0..63)_PF_MBOX(0)) will set the corresponding
                                                                 SSO_VHGRP()_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_pf_vhgrpx_mboxx_s cn; */
};
typedef union cavm_sso_pf_vhgrpx_mboxx cavm_sso_pf_vhgrpx_mboxx_t;

static inline uint64_t CAVM_SSO_PF_VHGRPX_MBOXX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_PF_VHGRPX_MBOXX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b<=1)))
        return 0x860020000400ll + 0x100000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("SSO_PF_VHGRPX_MBOXX", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_PF_VHGRPX_MBOXX(a,b) cavm_sso_pf_vhgrpx_mboxx_t
#define bustype_CAVM_SSO_PF_VHGRPX_MBOXX(a,b) CSR_TYPE_NCB
#define basename_CAVM_SSO_PF_VHGRPX_MBOXX(a,b) "SSO_PF_VHGRPX_MBOXX"
#define device_bar_CAVM_SSO_PF_VHGRPX_MBOXX(a,b) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_PF_VHGRPX_MBOXX(a,b) (a)
#define arguments_CAVM_SSO_PF_VHGRPX_MBOXX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_reset
 *
 * SSO PF Soft Reset Register
 * Writing a 1 to SSO_RESET[RESET] resets the SSO. After receiving a store to this CSR, the SSO
 * must not be sent any other operations for 2500 coprocessor (SCLK) cycles. Note that the
 * contents of this register are reset along with the rest of the SSO.
 */
union cavm_sso_reset
{
    uint64_t u;
    struct cavm_sso_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Initialization in progress. After reset asserts, SSO will set this bit until internal
                                                                 structures are initialized. This bit must read as zero before any configuration may be
                                                                 done. */
        uint64_t reserved_1_62         : 62;
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1/H) Reset the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1/H) Reset the SSO. */
        uint64_t reserved_1_62         : 62;
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Initialization in progress. After reset asserts, SSO will set this bit until internal
                                                                 structures are initialized. This bit must read as zero before any configuration may be
                                                                 done. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_reset_s cn; */
};
typedef union cavm_sso_reset cavm_sso_reset_t;

#define CAVM_SSO_RESET CAVM_SSO_RESET_FUNC()
static inline uint64_t CAVM_SSO_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_RESET_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000010f8ll;
    __cavm_csr_fatal("SSO_RESET", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_RESET cavm_sso_reset_t
#define bustype_CAVM_SSO_RESET CSR_TYPE_NCB
#define basename_CAVM_SSO_RESET "SSO_RESET"
#define device_bar_CAVM_SSO_RESET 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_RESET 0
#define arguments_CAVM_SSO_RESET -1,-1,-1,-1

/**
 * Register (NCB) sso_taq#_link
 *
 * SSO PF Transitory Admission Queue Link Registers
 * Returns TAQ status for a given line.
 */
union cavm_sso_taqx_link
{
    uint64_t u;
    struct cavm_sso_taqx_link_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t next                  : 11; /**< [ 10:  0](RO/H) Next TAQ entry in linked list. Only valid when not at the tail of the list. */
#else /* Word 0 - Little Endian */
        uint64_t next                  : 11; /**< [ 10:  0](RO/H) Next TAQ entry in linked list. Only valid when not at the tail of the list. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_taqx_link_s cn; */
};
typedef union cavm_sso_taqx_link cavm_sso_taqx_link_t;

static inline uint64_t CAVM_SSO_TAQX_LINK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_TAQX_LINK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=319))
        return 0x8600c0000000ll + 0x1000ll * ((a) & 0x1ff);
    __cavm_csr_fatal("SSO_TAQX_LINK", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_TAQX_LINK(a) cavm_sso_taqx_link_t
#define bustype_CAVM_SSO_TAQX_LINK(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_TAQX_LINK(a) "SSO_TAQX_LINK"
#define device_bar_CAVM_SSO_TAQX_LINK(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_TAQX_LINK(a) (a)
#define arguments_CAVM_SSO_TAQX_LINK(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_taq#_wae#_tag
 *
 * SSO PF Transitory Admission Queue Tag Registers
 * Returns TAQ status for a given line and WAE within that line.
 */
union cavm_sso_taqx_waex_tag
{
    uint64_t u;
    struct cavm_sso_taqx_waex_tag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type of the TAQ entry. Enumerated by SSO_TT_E. */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag of the TAQ entry. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag of the TAQ entry. */
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type of the TAQ entry. Enumerated by SSO_TT_E. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_taqx_waex_tag_s cn; */
};
typedef union cavm_sso_taqx_waex_tag cavm_sso_taqx_waex_tag_t;

static inline uint64_t CAVM_SSO_TAQX_WAEX_TAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_TAQX_WAEX_TAG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=319) && (b<=10)))
        return 0x8600d0000000ll + 0x1000ll * ((a) & 0x1ff) + 0x10ll * ((b) & 0xf);
    __cavm_csr_fatal("SSO_TAQX_WAEX_TAG", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_TAQX_WAEX_TAG(a,b) cavm_sso_taqx_waex_tag_t
#define bustype_CAVM_SSO_TAQX_WAEX_TAG(a,b) CSR_TYPE_NCB
#define basename_CAVM_SSO_TAQX_WAEX_TAG(a,b) "SSO_TAQX_WAEX_TAG"
#define device_bar_CAVM_SSO_TAQX_WAEX_TAG(a,b) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_TAQX_WAEX_TAG(a,b) (a)
#define arguments_CAVM_SSO_TAQX_WAEX_TAG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_taq#_wae#_wqp
 *
 * SSO PF Transitory Admission Queue Pointer Registers
 * Returns TAQ status for a given line and WAE within that line.
 */
union cavm_sso_taqx_waex_wqp
{
    uint64_t u;
    struct cavm_sso_taqx_waex_wqp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](RO/H) Work queue IOVA held in the TAQ entry.
                                                                 Bits <63:49> are a sign extension of <48>.  Bits <2:0> are 0x0. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](RO/H) Work queue IOVA held in the TAQ entry.
                                                                 Bits <63:49> are a sign extension of <48>.  Bits <2:0> are 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_taqx_waex_wqp_s cn; */
};
typedef union cavm_sso_taqx_waex_wqp cavm_sso_taqx_waex_wqp_t;

static inline uint64_t CAVM_SSO_TAQX_WAEX_WQP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_TAQX_WAEX_WQP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=319) && (b<=10)))
        return 0x8600d0000008ll + 0x1000ll * ((a) & 0x1ff) + 0x10ll * ((b) & 0xf);
    __cavm_csr_fatal("SSO_TAQX_WAEX_WQP", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_TAQX_WAEX_WQP(a,b) cavm_sso_taqx_waex_wqp_t
#define bustype_CAVM_SSO_TAQX_WAEX_WQP(a,b) CSR_TYPE_NCB
#define basename_CAVM_SSO_TAQX_WAEX_WQP(a,b) "SSO_TAQX_WAEX_WQP"
#define device_bar_CAVM_SSO_TAQX_WAEX_WQP(a,b) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_TAQX_WAEX_WQP(a,b) (a)
#define arguments_CAVM_SSO_TAQX_WAEX_WQP(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_taq_add
 *
 * SSO PF Transitory Admission Queue Add Register
 */
union cavm_sso_taq_add
{
    uint64_t u;
    struct cavm_sso_taq_add_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t rsvd_free             : 13; /**< [ 28: 16](WO) Written value is added to SSO_TAQ_CNT[RSVD_FREE] to prevent races between software and
                                                                 hardware changes. This is a two's complement value so subtraction may also be performed. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t rsvd_free             : 13; /**< [ 28: 16](WO) Written value is added to SSO_TAQ_CNT[RSVD_FREE] to prevent races between software and
                                                                 hardware changes. This is a two's complement value so subtraction may also be performed. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_taq_add_s cn; */
};
typedef union cavm_sso_taq_add cavm_sso_taq_add_t;

#define CAVM_SSO_TAQ_ADD CAVM_SSO_TAQ_ADD_FUNC()
static inline uint64_t CAVM_SSO_TAQ_ADD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_TAQ_ADD_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020e0ll;
    __cavm_csr_fatal("SSO_TAQ_ADD", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_TAQ_ADD cavm_sso_taq_add_t
#define bustype_CAVM_SSO_TAQ_ADD CSR_TYPE_NCB
#define basename_CAVM_SSO_TAQ_ADD "SSO_TAQ_ADD"
#define device_bar_CAVM_SSO_TAQ_ADD 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_TAQ_ADD 0
#define arguments_CAVM_SSO_TAQ_ADD -1,-1,-1,-1

/**
 * Register (NCB) sso_taq_cnt
 *
 * SSO PF Transitory Admission Queue Count Register
 */
union cavm_sso_taq_cnt
{
    uint64_t u;
    struct cavm_sso_taq_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t rsvd_free             : 11; /**< [ 26: 16](R/W/H) Number of free reserved buffers. Used to insure each hardware-group may get a
                                                                 specific number of buffers. Must always be greater than or equal to the sum
                                                                 across all SSO_GRP()_TAQ_THR[RSVD_THR], and will generally be equal to that sum
                                                                 unless changes to RSVD_THR are going to be made. To prevent races, software
                                                                 should not change this register when SSO is being used; instead use
                                                                 SSO_TAQ_ADD[RSVD_FREE]. Legal values are 0..0x140 */
        uint64_t reserved_11_15        : 5;
        uint64_t free_cnt              : 11; /**< [ 10:  0](RO/H) Number of total free buffers. */
#else /* Word 0 - Little Endian */
        uint64_t free_cnt              : 11; /**< [ 10:  0](RO/H) Number of total free buffers. */
        uint64_t reserved_11_15        : 5;
        uint64_t rsvd_free             : 11; /**< [ 26: 16](R/W/H) Number of free reserved buffers. Used to insure each hardware-group may get a
                                                                 specific number of buffers. Must always be greater than or equal to the sum
                                                                 across all SSO_GRP()_TAQ_THR[RSVD_THR], and will generally be equal to that sum
                                                                 unless changes to RSVD_THR are going to be made. To prevent races, software
                                                                 should not change this register when SSO is being used; instead use
                                                                 SSO_TAQ_ADD[RSVD_FREE]. Legal values are 0..0x140 */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_taq_cnt_s cn; */
};
typedef union cavm_sso_taq_cnt cavm_sso_taq_cnt_t;

#define CAVM_SSO_TAQ_CNT CAVM_SSO_TAQ_CNT_FUNC()
static inline uint64_t CAVM_SSO_TAQ_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_TAQ_CNT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020c0ll;
    __cavm_csr_fatal("SSO_TAQ_CNT", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_TAQ_CNT cavm_sso_taq_cnt_t
#define bustype_CAVM_SSO_TAQ_CNT CSR_TYPE_NCB
#define basename_CAVM_SSO_TAQ_CNT "SSO_TAQ_CNT"
#define device_bar_CAVM_SSO_TAQ_CNT 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_TAQ_CNT 0
#define arguments_CAVM_SSO_TAQ_CNT -1,-1,-1,-1

/**
 * Register (NCB) sso_tiaq#_status
 *
 * SSO PF Hardware-Group Transitory Input Admission Queue Status Registers
 * This register returns TAQ inbound status indexed by hardware-group.
 */
union cavm_sso_tiaqx_status
{
    uint64_t u;
    struct cavm_sso_tiaqx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t wae_head              : 4;  /**< [ 63: 60](RO/H) Head's WAE number within current cache line, 0-10. This provides the second index into
                                                                 SSO_TAQ()_WAE()_TAG and SSO_TAQ()_WAE()_WQP. */
        uint64_t wae_tail              : 4;  /**< [ 59: 56](RO/H) When [WAE_USED] is nonzero, this provides the next free WAE number in the cache
                                                                 line of the tail entry. If 0x0, the next entry will be placed at the beginning of
                                                                 a new cache line. This provides the second index into SSO_TAQ()_WAE()_TAG and
                                                                 SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_47_55        : 9;
        uint64_t wae_used              : 15; /**< [ 46: 32](RO/H) Number of WAEs in use. */
        uint64_t reserved_23_31        : 9;
        uint64_t ent_head              : 11; /**< [ 22: 12](RO/H) Head's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_11           : 1;
        uint64_t ent_tail              : 11; /**< [ 10:  0](RO/H) Tail's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
#else /* Word 0 - Little Endian */
        uint64_t ent_tail              : 11; /**< [ 10:  0](RO/H) Tail's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_11           : 1;
        uint64_t ent_head              : 11; /**< [ 22: 12](RO/H) Head's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_23_31        : 9;
        uint64_t wae_used              : 15; /**< [ 46: 32](RO/H) Number of WAEs in use. */
        uint64_t reserved_47_55        : 9;
        uint64_t wae_tail              : 4;  /**< [ 59: 56](RO/H) When [WAE_USED] is nonzero, this provides the next free WAE number in the cache
                                                                 line of the tail entry. If 0x0, the next entry will be placed at the beginning of
                                                                 a new cache line. This provides the second index into SSO_TAQ()_WAE()_TAG and
                                                                 SSO_TAQ()_WAE()_WQP. */
        uint64_t wae_head              : 4;  /**< [ 63: 60](RO/H) Head's WAE number within current cache line, 0-10. This provides the second index into
                                                                 SSO_TAQ()_WAE()_TAG and SSO_TAQ()_WAE()_WQP. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_tiaqx_status_s cn; */
};
typedef union cavm_sso_tiaqx_status cavm_sso_tiaqx_status_t;

static inline uint64_t CAVM_SSO_TIAQX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_TIAQX_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8600000c0000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_TIAQX_STATUS", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_TIAQX_STATUS(a) cavm_sso_tiaqx_status_t
#define bustype_CAVM_SSO_TIAQX_STATUS(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_TIAQX_STATUS(a) "SSO_TIAQX_STATUS"
#define device_bar_CAVM_SSO_TIAQX_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_TIAQX_STATUS(a) (a)
#define arguments_CAVM_SSO_TIAQX_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_toaq#_status
 *
 * SSO PF Hardware-Group Transitory Output Admission Queue Status Registers
 * This register returns TAQ outbound status indexed by hardware-group.
 */
union cavm_sso_toaqx_status
{
    uint64_t u;
    struct cavm_sso_toaqx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t ext_vld               : 1;  /**< [ 61: 61](RO/H) External queuing is in use on this hardware-group. */
        uint64_t partial               : 1;  /**< [ 60: 60](RO/H) Partial cache line is allocated to tail of queue. */
        uint64_t wae_tail              : 4;  /**< [ 59: 56](RO/H) If [PARTIAL] is set, this provides the next free WAE number in the cache line of
                                                                 the tail entry. If [PARTIAL] is clear, the next entry will be placed at the
                                                                 beginning of a new cache line. This provides the second index into
                                                                 SSO_TAQ()_WAE()_TAG and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_43_55        : 13;
        uint64_t cl_used               : 11; /**< [ 42: 32](RO/H) Number of cache lines in use. */
        uint64_t reserved_23_31        : 9;
        uint64_t ent_head              : 11; /**< [ 22: 12](RO/H) Head's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_11           : 1;
        uint64_t ent_tail              : 11; /**< [ 10:  0](RO/H) Tail's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
#else /* Word 0 - Little Endian */
        uint64_t ent_tail              : 11; /**< [ 10:  0](RO/H) Tail's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_11           : 1;
        uint64_t ent_head              : 11; /**< [ 22: 12](RO/H) Head's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_23_31        : 9;
        uint64_t cl_used               : 11; /**< [ 42: 32](RO/H) Number of cache lines in use. */
        uint64_t reserved_43_55        : 13;
        uint64_t wae_tail              : 4;  /**< [ 59: 56](RO/H) If [PARTIAL] is set, this provides the next free WAE number in the cache line of
                                                                 the tail entry. If [PARTIAL] is clear, the next entry will be placed at the
                                                                 beginning of a new cache line. This provides the second index into
                                                                 SSO_TAQ()_WAE()_TAG and SSO_TAQ()_WAE()_WQP. */
        uint64_t partial               : 1;  /**< [ 60: 60](RO/H) Partial cache line is allocated to tail of queue. */
        uint64_t ext_vld               : 1;  /**< [ 61: 61](RO/H) External queuing is in use on this hardware-group. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_toaqx_status_s cn; */
};
typedef union cavm_sso_toaqx_status cavm_sso_toaqx_status_t;

static inline uint64_t CAVM_SSO_TOAQX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_TOAQX_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8600000d0000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_TOAQX_STATUS", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_TOAQX_STATUS(a) cavm_sso_toaqx_status_t
#define bustype_CAVM_SSO_TOAQX_STATUS(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_TOAQX_STATUS(a) "SSO_TOAQX_STATUS"
#define device_bar_CAVM_SSO_TOAQX_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_TOAQX_STATUS(a) (a)
#define arguments_CAVM_SSO_TOAQX_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_unmap_info
 *
 * SSO PF Unmapped Error Information Register
 * When any SSO_ERR0[GMID_UNMAP] , SSO_ERR0[GMID_MULTI], or SSO_ERR0[ADDWQ_DROPPED_WQP0]
 * error occurs, this register is latched with information from the original request.
 * This register latches the first error detected for SSO_ERR0[ADDWQ_DROPPED_WQP0] and
 * the first error detected for SSO_ERR0[GMID_UNMAP] or SSO_ERR0[GMID_MULTI]. Values in
 * register are held until errors are cleared in SSO_ERR0 register.
 */
union cavm_sso_unmap_info
{
    uint64_t u;
    struct cavm_sso_unmap_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_42_63        : 22;
        uint64_t wqp0_src              : 10; /**< [ 41: 32](RO/H) Illegal WQP0 error source. This field is updated when
                                                                 SSO_ERR0[ADDWQ_DROPPED_WQP0] error occurs, and is held until
                                                                 SSO_ERR0[ADDWQ_DROPPED_WQP0] is cleared.
                                                                 <9> = DDF.
                                                                 <8> = ZIP.
                                                                 <7> = TIM.
                                                                 <6> = RAD.
                                                                 <5> = PKO.
                                                                 <4> = DPI.
                                                                 <3> = CPT1.
                                                                 <2> = ADDWQ.
                                                                 <1> = CPT0.
                                                                 <0> = PKI. */
        uint64_t reserved_30_31        : 2;
        uint64_t gmid_multi            : 1;  /**< [ 29: 29](RO/H) GMID map had double hit error. Set when SSO_ERR0[GMID_MULTI] is set
                                                                 and held until SSO_ERR0[GMID_MULTI] and SSO_ERR0[GMID_unmap] are cleared. */
        uint64_t gmid_unmap            : 1;  /**< [ 28: 28](RO/H) GMID mapping not found error. Set when SSO_ERR0[GMID_UNMAP] is set and held
                                                                 until SSO_ERR0[GMID_UNMAP] and SSO_ERR0[GMID_MULTI] are cleared */
        uint64_t reserved_26_27        : 2;
        uint64_t ggrp                  : 10; /**< [ 25: 16](RO/H) This field indicates the failing GGRP. This field is updated when
                                                                 any of he following errors occur: SSO_ERR0[GMID_UNMAP] or
                                                                 SSO_ERR0[GMID_MULTI] and is held until both errors are cleared in
                                                                 SSO_ERR0. */
        uint64_t gmid                  : 16; /**< [ 15:  0](RO/H) Failing GMID. This field is updated when any of he following errors occur:
                                                                 SSO_ERR0[GMID_UNMAP] or SSO_ERR0[GMID_MULTI] and is held until both errors
                                                                 have been cleared in SSO_ERR0. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](RO/H) Failing GMID. This field is updated when any of he following errors occur:
                                                                 SSO_ERR0[GMID_UNMAP] or SSO_ERR0[GMID_MULTI] and is held until both errors
                                                                 have been cleared in SSO_ERR0. */
        uint64_t ggrp                  : 10; /**< [ 25: 16](RO/H) This field indicates the failing GGRP. This field is updated when
                                                                 any of he following errors occur: SSO_ERR0[GMID_UNMAP] or
                                                                 SSO_ERR0[GMID_MULTI] and is held until both errors are cleared in
                                                                 SSO_ERR0. */
        uint64_t reserved_26_27        : 2;
        uint64_t gmid_unmap            : 1;  /**< [ 28: 28](RO/H) GMID mapping not found error. Set when SSO_ERR0[GMID_UNMAP] is set and held
                                                                 until SSO_ERR0[GMID_UNMAP] and SSO_ERR0[GMID_MULTI] are cleared */
        uint64_t gmid_multi            : 1;  /**< [ 29: 29](RO/H) GMID map had double hit error. Set when SSO_ERR0[GMID_MULTI] is set
                                                                 and held until SSO_ERR0[GMID_MULTI] and SSO_ERR0[GMID_unmap] are cleared. */
        uint64_t reserved_30_31        : 2;
        uint64_t wqp0_src              : 10; /**< [ 41: 32](RO/H) Illegal WQP0 error source. This field is updated when
                                                                 SSO_ERR0[ADDWQ_DROPPED_WQP0] error occurs, and is held until
                                                                 SSO_ERR0[ADDWQ_DROPPED_WQP0] is cleared.
                                                                 <9> = DDF.
                                                                 <8> = ZIP.
                                                                 <7> = TIM.
                                                                 <6> = RAD.
                                                                 <5> = PKO.
                                                                 <4> = DPI.
                                                                 <3> = CPT1.
                                                                 <2> = ADDWQ.
                                                                 <1> = CPT0.
                                                                 <0> = PKI. */
        uint64_t reserved_42_63        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_unmap_info_s cn; */
};
typedef union cavm_sso_unmap_info cavm_sso_unmap_info_t;

#define CAVM_SSO_UNMAP_INFO CAVM_SSO_UNMAP_INFO_FUNC()
static inline uint64_t CAVM_SSO_UNMAP_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_UNMAP_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000012f0ll;
    __cavm_csr_fatal("SSO_UNMAP_INFO", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_UNMAP_INFO cavm_sso_unmap_info_t
#define bustype_CAVM_SSO_UNMAP_INFO CSR_TYPE_NCB
#define basename_CAVM_SSO_UNMAP_INFO "SSO_UNMAP_INFO"
#define device_bar_CAVM_SSO_UNMAP_INFO 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_UNMAP_INFO 0
#define arguments_CAVM_SSO_UNMAP_INFO -1,-1,-1,-1

/**
 * Register (NCB) sso_unmap_info2
 *
 * SSO PF Unmapped Error2 Information Register
 * When any SSO_ERR2[WS_UNMAP] or SSO_ERR2[WS_MULTI] error occurs, this
 * register is latched with information from the original request. This register
 * latches the first error and will not be updated again until all of the
 * corresponding SSO_ERR2 bits are cleared.
 */
union cavm_sso_unmap_info2
{
    uint64_t u;
    struct cavm_sso_unmap_info2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_35_63        : 29;
        uint64_t cam_src               : 3;  /**< [ 34: 32](RO/H) Failing WS_GCAM error path. This field is updated when one of he following errors
                                                                 occur: SSO_ERR0[GMID_UNMAP] or SSO_ERR0[GMID_MULTI] and is held until both
                                                                 errors are cleared from SSO_ERR2. When multiple errors occur at the same
                                                                 time, the prioritiy to latch error information is as follows: WS to PP, NCBO1 to WS,
                                                                 NCBO0 to WS.
                                                                 <2> = From WS to PP (VHGRP to GGRP).
                                                                 <1> = From NCBO1 to WS (GGRP to VHGRP).
                                                                 <0> = From NCBO0 to WS (GGRP to VHGRP). */
        uint64_t reserved_30_31        : 2;
        uint64_t ws_multi              : 1;  /**< [ 29: 29](RO/H) GMID map had double hit error. Set when SSO_ERR2[WS_MULTI] is set
                                                                 and held until SSO_ERR2[WS_MULTI] and SSO_ERR2[WS_UNMAP] are cleared. */
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](RO/H) GMID mapping not found error. Set when SSO_ERR2[GMID_UNMAP] is set and held
                                                                 until SSO_ERR2[WS_UNMAP] and SS2_ERR0[WS_MULTI] are cleared */
        uint64_t reserved_26_27        : 2;
        uint64_t ggrp                  : 10; /**< [ 25: 16](RO/H) This field indicates the failing GGRP or VHGRP. See [CAM_SRC] to identify the
                                                                 type. This field is updated when  any of he following errors occur:
                                                                 SSO_ERR2[WS_UNMAP] or SSO_ERR2[WS_MULTI] and is held until all both
                                                                 errors are cleared in SSO_ERR2. */
        uint64_t gmid                  : 16; /**< [ 15:  0](RO/H) Failing GMID. This field is updated when any of he following errors occur:
                                                                 SSO_ERR2[WS_UNMAP] or SSO_ERR2[WS_MULTI] and is held until both errors
                                                                 are cleared from SSO_ERR2. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](RO/H) Failing GMID. This field is updated when any of he following errors occur:
                                                                 SSO_ERR2[WS_UNMAP] or SSO_ERR2[WS_MULTI] and is held until both errors
                                                                 are cleared from SSO_ERR2. */
        uint64_t ggrp                  : 10; /**< [ 25: 16](RO/H) This field indicates the failing GGRP or VHGRP. See [CAM_SRC] to identify the
                                                                 type. This field is updated when  any of he following errors occur:
                                                                 SSO_ERR2[WS_UNMAP] or SSO_ERR2[WS_MULTI] and is held until all both
                                                                 errors are cleared in SSO_ERR2. */
        uint64_t reserved_26_27        : 2;
        uint64_t ws_unmap              : 1;  /**< [ 28: 28](RO/H) GMID mapping not found error. Set when SSO_ERR2[GMID_UNMAP] is set and held
                                                                 until SSO_ERR2[WS_UNMAP] and SS2_ERR0[WS_MULTI] are cleared */
        uint64_t ws_multi              : 1;  /**< [ 29: 29](RO/H) GMID map had double hit error. Set when SSO_ERR2[WS_MULTI] is set
                                                                 and held until SSO_ERR2[WS_MULTI] and SSO_ERR2[WS_UNMAP] are cleared. */
        uint64_t reserved_30_31        : 2;
        uint64_t cam_src               : 3;  /**< [ 34: 32](RO/H) Failing WS_GCAM error path. This field is updated when one of he following errors
                                                                 occur: SSO_ERR0[GMID_UNMAP] or SSO_ERR0[GMID_MULTI] and is held until both
                                                                 errors are cleared from SSO_ERR2. When multiple errors occur at the same
                                                                 time, the prioritiy to latch error information is as follows: WS to PP, NCBO1 to WS,
                                                                 NCBO0 to WS.
                                                                 <2> = From WS to PP (VHGRP to GGRP).
                                                                 <1> = From NCBO1 to WS (GGRP to VHGRP).
                                                                 <0> = From NCBO0 to WS (GGRP to VHGRP). */
        uint64_t reserved_35_63        : 29;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_unmap_info2_s cn; */
};
typedef union cavm_sso_unmap_info2 cavm_sso_unmap_info2_t;

#define CAVM_SSO_UNMAP_INFO2 CAVM_SSO_UNMAP_INFO2_FUNC()
static inline uint64_t CAVM_SSO_UNMAP_INFO2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_UNMAP_INFO2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001300ll;
    __cavm_csr_fatal("SSO_UNMAP_INFO2", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_UNMAP_INFO2 cavm_sso_unmap_info2_t
#define bustype_CAVM_SSO_UNMAP_INFO2 CSR_TYPE_NCB
#define basename_CAVM_SSO_UNMAP_INFO2 "SSO_UNMAP_INFO2"
#define device_bar_CAVM_SSO_UNMAP_INFO2 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_UNMAP_INFO2 0
#define arguments_CAVM_SSO_UNMAP_INFO2 -1,-1,-1,-1

/**
 * Register (NCB) sso_vf#_msix_pba#
 *
 * SSO VF MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the SSO_VF_INT_VEC_E
 * enumeration.
 */
union cavm_sso_vfx_msix_pbax
{
    uint64_t u;
    struct cavm_sso_vfx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SSO_VF_MSIX_VEC()_CTL, enumerated by
                                                                 SSO_VF_INT_VEC_E. Bits that have no associated SSO_VF_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SSO_VF_MSIX_VEC()_CTL, enumerated by
                                                                 SSO_VF_INT_VEC_E. Bits that have no associated SSO_VF_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vfx_msix_pbax_s cn; */
};
typedef union cavm_sso_vfx_msix_pbax cavm_sso_vfx_msix_pbax_t;

static inline uint64_t CAVM_SSO_VFX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VFX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b==0)))
        return 0x860c000f0000ll + 0x100000ll * ((a) & 0x3f) + 8ll * ((b) & 0x0);
    __cavm_csr_fatal("SSO_VFX_MSIX_PBAX", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VFX_MSIX_PBAX(a,b) cavm_sso_vfx_msix_pbax_t
#define bustype_CAVM_SSO_VFX_MSIX_PBAX(a,b) CSR_TYPE_NCB
#define basename_CAVM_SSO_VFX_MSIX_PBAX(a,b) "SSO_VFX_MSIX_PBAX"
#define device_bar_CAVM_SSO_VFX_MSIX_PBAX(a,b) 0x14 /* VF_BAR4 */
#define busnum_CAVM_SSO_VFX_MSIX_PBAX(a,b) (a)
#define arguments_CAVM_SSO_VFX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_vf#_msix_vec#_addr
 *
 * SSO VF MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the SSO_VF_INT_VEC_E enumeration.
 */
union cavm_sso_vfx_msix_vecx_addr
{
    uint64_t u;
    struct cavm_sso_vfx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_SSO_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_SSO_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vfx_msix_vecx_addr_s cn; */
};
typedef union cavm_sso_vfx_msix_vecx_addr cavm_sso_vfx_msix_vecx_addr_t;

static inline uint64_t CAVM_SSO_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b==0)))
        return 0x860c00000000ll + 0x100000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x0);
    __cavm_csr_fatal("SSO_VFX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VFX_MSIX_VECX_ADDR(a,b) cavm_sso_vfx_msix_vecx_addr_t
#define bustype_CAVM_SSO_VFX_MSIX_VECX_ADDR(a,b) CSR_TYPE_NCB
#define basename_CAVM_SSO_VFX_MSIX_VECX_ADDR(a,b) "SSO_VFX_MSIX_VECX_ADDR"
#define device_bar_CAVM_SSO_VFX_MSIX_VECX_ADDR(a,b) 0x14 /* VF_BAR4 */
#define busnum_CAVM_SSO_VFX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_CAVM_SSO_VFX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_vf#_msix_vec#_ctl
 *
 * SSO VF MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the SSO_VF_INT_VEC_E enumeration.
 */
union cavm_sso_vfx_msix_vecx_ctl
{
    uint64_t u;
    struct cavm_sso_vfx_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vfx_msix_vecx_ctl_s cn; */
};
typedef union cavm_sso_vfx_msix_vecx_ctl cavm_sso_vfx_msix_vecx_ctl_t;

static inline uint64_t CAVM_SSO_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b==0)))
        return 0x860c00000008ll + 0x100000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x0);
    __cavm_csr_fatal("SSO_VFX_MSIX_VECX_CTL", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VFX_MSIX_VECX_CTL(a,b) cavm_sso_vfx_msix_vecx_ctl_t
#define bustype_CAVM_SSO_VFX_MSIX_VECX_CTL(a,b) CSR_TYPE_NCB
#define basename_CAVM_SSO_VFX_MSIX_VECX_CTL(a,b) "SSO_VFX_MSIX_VECX_CTL"
#define device_bar_CAVM_SSO_VFX_MSIX_VECX_CTL(a,b) 0x14 /* VF_BAR4 */
#define busnum_CAVM_SSO_VFX_MSIX_VECX_CTL(a,b) (a)
#define arguments_CAVM_SSO_VFX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_vhgrp#_aq_cnt
 *
 * SSO VF Hardware-Group Admission Queue Count Registers
 */
union cavm_sso_vhgrpx_aq_cnt
{
    uint64_t u;
    struct cavm_sso_vhgrpx_aq_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t aq_cnt                : 33; /**< [ 32:  0](RO/H) Number of total in-unit, transitional and external admission queue entries for this hardware-group. */
#else /* Word 0 - Little Endian */
        uint64_t aq_cnt                : 33; /**< [ 32:  0](RO/H) Number of total in-unit, transitional and external admission queue entries for this hardware-group. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_aq_cnt_s cn; */
};
typedef union cavm_sso_vhgrpx_aq_cnt cavm_sso_vhgrpx_aq_cnt_t;

static inline uint64_t CAVM_SSO_VHGRPX_AQ_CNT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_AQ_CNT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8608000001c0ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_AQ_CNT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_AQ_CNT(a) cavm_sso_vhgrpx_aq_cnt_t
#define bustype_CAVM_SSO_VHGRPX_AQ_CNT(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_AQ_CNT(a) "SSO_VHGRPX_AQ_CNT"
#define device_bar_CAVM_SSO_VHGRPX_AQ_CNT(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_AQ_CNT(a) (a)
#define arguments_CAVM_SSO_VHGRPX_AQ_CNT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_aq_thr
 *
 * SSO VF Hardware-Group Total Admission Queue Threshold Register
 */
union cavm_sso_vhgrpx_aq_thr
{
    uint64_t u;
    struct cavm_sso_vhgrpx_aq_thr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t aq_thr                : 33; /**< [ 32:  0](R/W) Total admission queue entry threshold. Compared against SSO_VHGRP()_AQ_CNT for
                                                                 triggering AQ interrupts. */
#else /* Word 0 - Little Endian */
        uint64_t aq_thr                : 33; /**< [ 32:  0](R/W) Total admission queue entry threshold. Compared against SSO_VHGRP()_AQ_CNT for
                                                                 triggering AQ interrupts. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_aq_thr_s cn; */
};
typedef union cavm_sso_vhgrpx_aq_thr cavm_sso_vhgrpx_aq_thr_t;

static inline uint64_t CAVM_SSO_VHGRPX_AQ_THR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_AQ_THR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8608000001e0ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_AQ_THR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_AQ_THR(a) cavm_sso_vhgrpx_aq_thr_t
#define bustype_CAVM_SSO_VHGRPX_AQ_THR(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_AQ_THR(a) "SSO_VHGRPX_AQ_THR"
#define device_bar_CAVM_SSO_VHGRPX_AQ_THR(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_AQ_THR(a) (a)
#define arguments_CAVM_SSO_VHGRPX_AQ_THR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int
 *
 * SSO VF Hardware-Group Interrupt Register
 * Contains the per-hardware-group interrupts and are used to clear these
 * interrupts. For more information on this register, refer to Interrupts.
 */
union cavm_sso_vhgrpx_int
{
    uint64_t u;
    struct cavm_sso_vhgrpx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this hardware-group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
        uint64_t reserved_4_62         : 59;
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1C/H) PF to VF mailbox interrupt. Set when SSO_VHGRP(0..63)_MBOX(0) is written. */
        uint64_t xaq_limit             : 1;  /**< [  2:  2](R/W1C/H) Hardware-group AQ exceeded allocation limit error; add-works to this VHGRP may
                                                                 be dropped. Set when SSO_VHGRP()_XAQ_CNT[XAQ_CNT] >=
                                                                 SSO_GRP()_XAQ_LIMIT[XAQ_LIMIT]. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1C/H) Work-executable interrupt. Generally used to indicate work is waiting for software.
                                                                 Set by hardware whenever:

                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] >= SSO_VHGRP()_INT_THR [IAQ_THR] and [IAQ_THR] != 0
                                                                 and [EXE_DIS] is clear.

                                                                 * SSO_VHGRP()_INT_CNT[DS_CNT] >= SSO_VHGRP()_INT_THR[DS_THR] and [DS_THR] != 0.

                                                                 * SSO_VHGRP()_INT_CNT[CQ_CNT] >= SSO_VHGRP()_INT_THR[CQ_THR] and [CQ_THR] != 0.

                                                                 * SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0 and SSO_VHGRP()_INT_THR[TC_EN] is set and at least one of the following is
                                                                 true:
                                                                 _ SSO_VHGRP()_INT_CNT[IAQ_CNT] > 0
                                                                 _ SSO_VHGRP()_INT_CNT[DS_CNT] > 0
                                                                 _ SSO_VHGRP()_INT_CNT[CQ_CNT] > 0 */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1C/H) AQ threshold interrupt. Set if SSO_VHGRP()_AQ_CNT changes, and the
                                                                 resulting value is equal to SSO_VHGRP()_AQ_THR. */
#else /* Word 0 - Little Endian */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1C/H) AQ threshold interrupt. Set if SSO_VHGRP()_AQ_CNT changes, and the
                                                                 resulting value is equal to SSO_VHGRP()_AQ_THR. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1C/H) Work-executable interrupt. Generally used to indicate work is waiting for software.
                                                                 Set by hardware whenever:

                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] >= SSO_VHGRP()_INT_THR [IAQ_THR] and [IAQ_THR] != 0
                                                                 and [EXE_DIS] is clear.

                                                                 * SSO_VHGRP()_INT_CNT[DS_CNT] >= SSO_VHGRP()_INT_THR[DS_THR] and [DS_THR] != 0.

                                                                 * SSO_VHGRP()_INT_CNT[CQ_CNT] >= SSO_VHGRP()_INT_THR[CQ_THR] and [CQ_THR] != 0.

                                                                 * SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0 and SSO_VHGRP()_INT_THR[TC_EN] is set and at least one of the following is
                                                                 true:
                                                                 _ SSO_VHGRP()_INT_CNT[IAQ_CNT] > 0
                                                                 _ SSO_VHGRP()_INT_CNT[DS_CNT] > 0
                                                                 _ SSO_VHGRP()_INT_CNT[CQ_CNT] > 0 */
        uint64_t xaq_limit             : 1;  /**< [  2:  2](R/W1C/H) Hardware-group AQ exceeded allocation limit error; add-works to this VHGRP may
                                                                 be dropped. Set when SSO_VHGRP()_XAQ_CNT[XAQ_CNT] >=
                                                                 SSO_GRP()_XAQ_LIMIT[XAQ_LIMIT]. */
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1C/H) PF to VF mailbox interrupt. Set when SSO_VHGRP(0..63)_MBOX(0) is written. */
        uint64_t reserved_4_62         : 59;
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this hardware-group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_int_s cn; */
};
typedef union cavm_sso_vhgrpx_int cavm_sso_vhgrpx_int_t;

static inline uint64_t CAVM_SSO_VHGRPX_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000100ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_INT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_INT(a) cavm_sso_vhgrpx_int_t
#define bustype_CAVM_SSO_VHGRPX_INT(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_INT(a) "SSO_VHGRPX_INT"
#define device_bar_CAVM_SSO_VHGRPX_INT(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_INT(a) (a)
#define arguments_CAVM_SSO_VHGRPX_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_cnt
 *
 * SSO VF Hardware-Group Work-Queue Interrupt Count Registers
 * These registers contain a read-only copy of the counts used to trigger work-queue interrupts
 * (one per hardware-group). For more information on this register, refer to Interrupts.
 */
union cavm_sso_vhgrpx_int_cnt
{
    uint64_t u;
    struct cavm_sso_vhgrpx_int_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t tc_cnt                : 13; /**< [ 60: 48](RO/H) Time counter current value. Hardware sets this field to the value of
                                                                 SSO_VHGRP()_INT_THR[TC_THR] whenever:
                                                                 * Corresponding SSO_VHGRP()_INT_CNT[IAQ_CNT, DS_CNT and CQ_CNT] are all equal to 0.
                                                                 * Corresponding SSO_VHGRP()_INT[EXE_INT] is written with a one to clear by software.
                                                                 * Corresponding SSO_VHGRP()_INT[EXE_DIS] is written with a one to set by software.
                                                                 * Corresponding SSO_VHGRP()_INT_THR is written by software.
                                                                 * TC_CNT is equal to 1 and periodic counter SSO_WQ_INT_PC[PC] is equal to 0.

                                                                 Otherwise, hardware decrements this field whenever the periodic counter SSO_WQ_INT_PC[PC]
                                                                 is equal to 0. This field is 0 whenever SSO_VHGRP()_INT_THR[TC_THR] is equal to 0. */
        uint64_t reserved_45_47        : 3;
        uint64_t cq_cnt                : 13; /**< [ 44: 32](RO/H) Conflicted queue executable count. */
        uint64_t reserved_29_31        : 3;
        uint64_t ds_cnt                : 13; /**< [ 28: 16](RO/H) Deschedule executable count. */
        uint64_t reserved_13_15        : 3;
        uint64_t iaq_cnt               : 13; /**< [ 12:  0](RO/H) Work-queue entries for this in-unit admission queue. */
#else /* Word 0 - Little Endian */
        uint64_t iaq_cnt               : 13; /**< [ 12:  0](RO/H) Work-queue entries for this in-unit admission queue. */
        uint64_t reserved_13_15        : 3;
        uint64_t ds_cnt                : 13; /**< [ 28: 16](RO/H) Deschedule executable count. */
        uint64_t reserved_29_31        : 3;
        uint64_t cq_cnt                : 13; /**< [ 44: 32](RO/H) Conflicted queue executable count. */
        uint64_t reserved_45_47        : 3;
        uint64_t tc_cnt                : 13; /**< [ 60: 48](RO/H) Time counter current value. Hardware sets this field to the value of
                                                                 SSO_VHGRP()_INT_THR[TC_THR] whenever:
                                                                 * Corresponding SSO_VHGRP()_INT_CNT[IAQ_CNT, DS_CNT and CQ_CNT] are all equal to 0.
                                                                 * Corresponding SSO_VHGRP()_INT[EXE_INT] is written with a one to clear by software.
                                                                 * Corresponding SSO_VHGRP()_INT[EXE_DIS] is written with a one to set by software.
                                                                 * Corresponding SSO_VHGRP()_INT_THR is written by software.
                                                                 * TC_CNT is equal to 1 and periodic counter SSO_WQ_INT_PC[PC] is equal to 0.

                                                                 Otherwise, hardware decrements this field whenever the periodic counter SSO_WQ_INT_PC[PC]
                                                                 is equal to 0. This field is 0 whenever SSO_VHGRP()_INT_THR[TC_THR] is equal to 0. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_int_cnt_s cn; */
};
typedef union cavm_sso_vhgrpx_int_cnt cavm_sso_vhgrpx_int_cnt_t;

static inline uint64_t CAVM_SSO_VHGRPX_INT_CNT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_INT_CNT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000180ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_INT_CNT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_INT_CNT(a) cavm_sso_vhgrpx_int_cnt_t
#define bustype_CAVM_SSO_VHGRPX_INT_CNT(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_INT_CNT(a) "SSO_VHGRPX_INT_CNT"
#define device_bar_CAVM_SSO_VHGRPX_INT_CNT(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_INT_CNT(a) (a)
#define arguments_CAVM_SSO_VHGRPX_INT_CNT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_ena_w1c
 *
 * SSO VF Hardware-Group Interrupt Enable Clear Register
 */
union cavm_sso_vhgrpx_int_ena_w1c
{
    uint64_t u;
    struct cavm_sso_vhgrpx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1C/H) Internal:
                                                                 This bit exists to enable auto-generation of the CSR and work
                                                                 around the inheritance_disabled attribute issue. This bit
                                                                 will not be connected to the EXE_DIS flop in SSO_VHGRP()_INT.
                                                                 See Bugzilla - bug 2050. */
        uint64_t reserved_4_62         : 59;
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1C/H) PF to VF mailbox interrupt. */
        uint64_t xaq_limit             : 1;  /**< [  2:  2](R/W1C/H) Group AQ exceeded allocation limit. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1C/H) Work-executable interrupt enable W1C. */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1C/H) External group queue threshold interrupt enable W1C. */
#else /* Word 0 - Little Endian */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1C/H) External group queue threshold interrupt enable W1C. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1C/H) Work-executable interrupt enable W1C. */
        uint64_t xaq_limit             : 1;  /**< [  2:  2](R/W1C/H) Group AQ exceeded allocation limit. */
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1C/H) PF to VF mailbox interrupt. */
        uint64_t reserved_4_62         : 59;
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1C/H) Internal:
                                                                 This bit exists to enable auto-generation of the CSR and work
                                                                 around the inheritance_disabled attribute issue. This bit
                                                                 will not be connected to the EXE_DIS flop in SSO_VHGRP()_INT.
                                                                 See Bugzilla - bug 2050. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_int_ena_w1c_s cn; */
};
typedef union cavm_sso_vhgrpx_int_ena_w1c cavm_sso_vhgrpx_int_ena_w1c_t;

static inline uint64_t CAVM_SSO_VHGRPX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000118ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_INT_ENA_W1C", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_INT_ENA_W1C(a) cavm_sso_vhgrpx_int_ena_w1c_t
#define bustype_CAVM_SSO_VHGRPX_INT_ENA_W1C(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_INT_ENA_W1C(a) "SSO_VHGRPX_INT_ENA_W1C"
#define device_bar_CAVM_SSO_VHGRPX_INT_ENA_W1C(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_INT_ENA_W1C(a) (a)
#define arguments_CAVM_SSO_VHGRPX_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_ena_w1s
 *
 * SSO VF Hardware-Group Interrupt Enable Set Register
 */
union cavm_sso_vhgrpx_int_ena_w1s
{
    uint64_t u;
    struct cavm_sso_vhgrpx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Internal:
                                                                 This bit exists to enable auto-generation of the CSR and work
                                                                 around the inheritance_disabled attribute issue. This bit
                                                                 will not be connected to the EXE_DIS flop in SSO_VHGRP()_INT.
                                                                 See Bugzilla - bug 2050. */
        uint64_t reserved_4_62         : 59;
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1S/H) PF to VF mailbox interrupt enable. */
        uint64_t xaq_limit             : 1;  /**< [  2:  2](R/W1S/H) Hardware-group AQ exceeded allocation limit error enable. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1S/H) Work-executable interrupt enable W1S. */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1S/H) External group queue threshold interrupt enable W1S. */
#else /* Word 0 - Little Endian */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1S/H) External group queue threshold interrupt enable W1S. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1S/H) Work-executable interrupt enable W1S. */
        uint64_t xaq_limit             : 1;  /**< [  2:  2](R/W1S/H) Hardware-group AQ exceeded allocation limit error enable. */
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1S/H) PF to VF mailbox interrupt enable. */
        uint64_t reserved_4_62         : 59;
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Internal:
                                                                 This bit exists to enable auto-generation of the CSR and work
                                                                 around the inheritance_disabled attribute issue. This bit
                                                                 will not be connected to the EXE_DIS flop in SSO_VHGRP()_INT.
                                                                 See Bugzilla - bug 2050. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_int_ena_w1s_s cn; */
};
typedef union cavm_sso_vhgrpx_int_ena_w1s cavm_sso_vhgrpx_int_ena_w1s_t;

static inline uint64_t CAVM_SSO_VHGRPX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000110ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_INT_ENA_W1S", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_INT_ENA_W1S(a) cavm_sso_vhgrpx_int_ena_w1s_t
#define bustype_CAVM_SSO_VHGRPX_INT_ENA_W1S(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_INT_ENA_W1S(a) "SSO_VHGRPX_INT_ENA_W1S"
#define device_bar_CAVM_SSO_VHGRPX_INT_ENA_W1S(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_INT_ENA_W1S(a) (a)
#define arguments_CAVM_SSO_VHGRPX_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_thr
 *
 * SSO VF Hardware-Group Work-Queue Interrupt Threshold Registers
 * These registers contain the thresholds for enabling and setting work-queue interrupts (one per
 * hardware-group). For more information on this register, refer to Interrupts.
 */
union cavm_sso_vhgrpx_int_thr
{
    uint64_t u;
    struct cavm_sso_vhgrpx_int_thr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tc_en                 : 1;  /**< [ 63: 63](R/W) Time counter interrupt enable for this hardware-group. This field must be zero when [TC_THR] is 0. */
        uint64_t reserved_61_62        : 2;
        uint64_t tc_thr                : 13; /**< [ 60: 48](R/W) Time counter interrupt threshold for this hardware-group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT]. When this field is equal to 0,
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is zero. */
        uint64_t reserved_45_47        : 3;
        uint64_t cq_thr                : 13; /**< [ 44: 32](R/W) Conflicted queue count threshold for this hardware-group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[CQ_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
        uint64_t reserved_29_31        : 3;
        uint64_t ds_thr                : 13; /**< [ 28: 16](R/W) Deschedule count threshold for this hardware-group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[DS_CNT]. When
                                                                 this field is 0, the threshold interrupt is disabled. */
        uint64_t reserved_13_15        : 3;
        uint64_t iaq_thr               : 13; /**< [ 12:  0](R/W) In-unit admission queue threshold for this hardware-group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[IAQ_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
#else /* Word 0 - Little Endian */
        uint64_t iaq_thr               : 13; /**< [ 12:  0](R/W) In-unit admission queue threshold for this hardware-group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[IAQ_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
        uint64_t reserved_13_15        : 3;
        uint64_t ds_thr                : 13; /**< [ 28: 16](R/W) Deschedule count threshold for this hardware-group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[DS_CNT]. When
                                                                 this field is 0, the threshold interrupt is disabled. */
        uint64_t reserved_29_31        : 3;
        uint64_t cq_thr                : 13; /**< [ 44: 32](R/W) Conflicted queue count threshold for this hardware-group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[CQ_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
        uint64_t reserved_45_47        : 3;
        uint64_t tc_thr                : 13; /**< [ 60: 48](R/W) Time counter interrupt threshold for this hardware-group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT]. When this field is equal to 0,
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is zero. */
        uint64_t reserved_61_62        : 2;
        uint64_t tc_en                 : 1;  /**< [ 63: 63](R/W) Time counter interrupt enable for this hardware-group. This field must be zero when [TC_THR] is 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_int_thr_s cn; */
};
typedef union cavm_sso_vhgrpx_int_thr cavm_sso_vhgrpx_int_thr_t;

static inline uint64_t CAVM_SSO_VHGRPX_INT_THR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_INT_THR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000140ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_INT_THR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_INT_THR(a) cavm_sso_vhgrpx_int_thr_t
#define bustype_CAVM_SSO_VHGRPX_INT_THR(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_INT_THR(a) "SSO_VHGRPX_INT_THR"
#define device_bar_CAVM_SSO_VHGRPX_INT_THR(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_INT_THR(a) (a)
#define arguments_CAVM_SSO_VHGRPX_INT_THR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_w1s
 *
 * SSO VF Hardware-Group Interrupt Set Register
 */
union cavm_sso_vhgrpx_int_w1s
{
    uint64_t u;
    struct cavm_sso_vhgrpx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this hardware-group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
        uint64_t reserved_4_62         : 59;
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1S/H) PF to VF mailbox interrupt. */
        uint64_t xaq_limit             : 1;  /**< [  2:  2](R/W1S/H) Hardware-group AQ exceeded allocation limit error; */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1S/H) Work-executable interrupt W1S. Generally used to indicate work is waiting for software. */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1S/H) Aq threshold interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1S/H) Aq threshold interrupt. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1S/H) Work-executable interrupt W1S. Generally used to indicate work is waiting for software. */
        uint64_t xaq_limit             : 1;  /**< [  2:  2](R/W1S/H) Hardware-group AQ exceeded allocation limit error; */
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1S/H) PF to VF mailbox interrupt. */
        uint64_t reserved_4_62         : 59;
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this hardware-group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_int_w1s_s cn; */
};
typedef union cavm_sso_vhgrpx_int_w1s cavm_sso_vhgrpx_int_w1s_t;

static inline uint64_t CAVM_SSO_VHGRPX_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000108ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_INT_W1S", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_INT_W1S(a) cavm_sso_vhgrpx_int_w1s_t
#define bustype_CAVM_SSO_VHGRPX_INT_W1S(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_INT_W1S(a) "SSO_VHGRPX_INT_W1S"
#define device_bar_CAVM_SSO_VHGRPX_INT_W1S(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_INT_W1S(a) (a)
#define arguments_CAVM_SSO_VHGRPX_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_op_add_work0
 *
 * SSO VF Hardware-Group Add Work Register 0
 * See SSO_VHGRP()_OP_ADD_WORK1.
 */
union cavm_sso_vhgrpx_op_add_work0
{
    uint64_t u;
    struct cavm_sso_vhgrpx_op_add_work0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) Tag type to add, enumerated by SSO_TT_E.  Must not be EMPTY. */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag of the work-queue entry, if [TT] is ATOMIC or ORDERED. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag of the work-queue entry, if [TT] is ATOMIC or ORDERED. */
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) Tag type to add, enumerated by SSO_TT_E.  Must not be EMPTY. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_op_add_work0_s cn; */
};
typedef union cavm_sso_vhgrpx_op_add_work0 cavm_sso_vhgrpx_op_add_work0_t;

static inline uint64_t CAVM_SSO_VHGRPX_OP_ADD_WORK0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_OP_ADD_WORK0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x862800000000ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_OP_ADD_WORK0", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_OP_ADD_WORK0(a) cavm_sso_vhgrpx_op_add_work0_t
#define bustype_CAVM_SSO_VHGRPX_OP_ADD_WORK0(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_OP_ADD_WORK0(a) "SSO_VHGRPX_OP_ADD_WORK0"
#define device_bar_CAVM_SSO_VHGRPX_OP_ADD_WORK0(a) 0x12 /* VF_BAR2 */
#define busnum_CAVM_SSO_VHGRPX_OP_ADD_WORK0(a) (a)
#define arguments_CAVM_SSO_VHGRPX_OP_ADD_WORK0(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_op_add_work1
 *
 * SSO VF Hardware-Group Add Work Register 1
 * A write to this register performs an add work. Either:
 * * A single-transaction 128-bit store (SDP) is used to ADD_WORK0 and ADD_WORK1 to
 * perform a single add work with both a tag and work pointer.
 * * Or, a single 64-bit store is used to ADD_WORK1 to perform a single add work which
 * is untagged.
 * * Writing SSO_VHGRP()_OP_ADD_WORK0 without a simultanious write to ADD_WORK1
 * as described above is ignored.
 */
union cavm_sso_vhgrpx_op_add_work1
{
    uint64_t u;
    struct cavm_sso_vhgrpx_op_add_work1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](WO) IOVA of the work-queue entry.  Bits <63:49> and <2:0> are ignored. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](WO) IOVA of the work-queue entry.  Bits <63:49> and <2:0> are ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_op_add_work1_s cn; */
};
typedef union cavm_sso_vhgrpx_op_add_work1 cavm_sso_vhgrpx_op_add_work1_t;

static inline uint64_t CAVM_SSO_VHGRPX_OP_ADD_WORK1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_OP_ADD_WORK1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x862800000008ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_OP_ADD_WORK1", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_OP_ADD_WORK1(a) cavm_sso_vhgrpx_op_add_work1_t
#define bustype_CAVM_SSO_VHGRPX_OP_ADD_WORK1(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_OP_ADD_WORK1(a) "SSO_VHGRPX_OP_ADD_WORK1"
#define device_bar_CAVM_SSO_VHGRPX_OP_ADD_WORK1(a) 0x12 /* VF_BAR2 */
#define busnum_CAVM_SSO_VHGRPX_OP_ADD_WORK1(a) (a)
#define arguments_CAVM_SSO_VHGRPX_OP_ADD_WORK1(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_pf_mbox#
 *
 * SSO VF/PF Mailbox Registers
 */
union cavm_sso_vhgrpx_pf_mboxx
{
    uint64_t u;
    struct cavm_sso_vhgrpx_pf_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using SSO_PF_VHGRP()_MBOX(). MBOX(0)
                                                                 is typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 SSO_VHGRP(0..63)_PF_MBOX(1) (but not SSO_PF_VHGRP(0..63)_MBOX(1)) will set the
                                                                 corresponding SSO_PF_MBOX_INT() bit, which if appropriately enabled will send
                                                                 an interrupt to the PF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using SSO_PF_VHGRP()_MBOX(). MBOX(0)
                                                                 is typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 SSO_VHGRP(0..63)_PF_MBOX(1) (but not SSO_PF_VHGRP(0..63)_MBOX(1)) will set the
                                                                 corresponding SSO_PF_MBOX_INT() bit, which if appropriately enabled will send
                                                                 an interrupt to the PF. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_pf_mboxx_s cn; */
};
typedef union cavm_sso_vhgrpx_pf_mboxx cavm_sso_vhgrpx_pf_mboxx_t;

static inline uint64_t CAVM_SSO_VHGRPX_PF_MBOXX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_PF_MBOXX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b<=1)))
        return 0x860800000200ll + 0x100000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    __cavm_csr_fatal("SSO_VHGRPX_PF_MBOXX", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_PF_MBOXX(a,b) cavm_sso_vhgrpx_pf_mboxx_t
#define bustype_CAVM_SSO_VHGRPX_PF_MBOXX(a,b) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_PF_MBOXX(a,b) "SSO_VHGRPX_PF_MBOXX"
#define device_bar_CAVM_SSO_VHGRPX_PF_MBOXX(a,b) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_PF_MBOXX(a,b) (a)
#define arguments_CAVM_SSO_VHGRPX_PF_MBOXX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_vhgrp#_qctl
 *
 * SSO Admission Queue Control Registers
 */
union cavm_sso_vhgrpx_qctl
{
    uint64_t u;
    struct cavm_sso_vhgrpx_qctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t ena                   : 1;  /**< [  0:  0](R/W/H) VHGRP enable. If clear, add work is dropped.

                                                                 Cleared by hardware when SSO_GRP()_XAQ_LIMIT[XAQ_LIMIT] >=
                                                                 SSO_VHGRP()_XAQ_CNT[XAQ_CNT]. */
#else /* Word 0 - Little Endian */
        uint64_t ena                   : 1;  /**< [  0:  0](R/W/H) VHGRP enable. If clear, add work is dropped.

                                                                 Cleared by hardware when SSO_GRP()_XAQ_LIMIT[XAQ_LIMIT] >=
                                                                 SSO_VHGRP()_XAQ_CNT[XAQ_CNT]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_qctl_s cn; */
};
typedef union cavm_sso_vhgrpx_qctl cavm_sso_vhgrpx_qctl_t;

static inline uint64_t CAVM_SSO_VHGRPX_QCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_QCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000010ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_QCTL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_QCTL(a) cavm_sso_vhgrpx_qctl_t
#define bustype_CAVM_SSO_VHGRPX_QCTL(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_QCTL(a) "SSO_VHGRPX_QCTL"
#define device_bar_CAVM_SSO_VHGRPX_QCTL(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_QCTL(a) (a)
#define arguments_CAVM_SSO_VHGRPX_QCTL(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_xaq_cnt
 *
 * SSO VF Hardware-Group External Queue Count Registers
 */
union cavm_sso_vhgrpx_xaq_cnt
{
    uint64_t u;
    struct cavm_sso_vhgrpx_xaq_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t xaq_cnt               : 33; /**< [ 32:  0](RO/H) Number of external admission queue entries for this hardware-group. */
#else /* Word 0 - Little Endian */
        uint64_t xaq_cnt               : 33; /**< [ 32:  0](RO/H) Number of external admission queue entries for this hardware-group. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_vhgrpx_xaq_cnt_s cn; */
};
typedef union cavm_sso_vhgrpx_xaq_cnt cavm_sso_vhgrpx_xaq_cnt_t;

static inline uint64_t CAVM_SSO_VHGRPX_XAQ_CNT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_VHGRPX_XAQ_CNT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8608000001b0ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_VHGRPX_XAQ_CNT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_VHGRPX_XAQ_CNT(a) cavm_sso_vhgrpx_xaq_cnt_t
#define bustype_CAVM_SSO_VHGRPX_XAQ_CNT(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_VHGRPX_XAQ_CNT(a) "SSO_VHGRPX_XAQ_CNT"
#define device_bar_CAVM_SSO_VHGRPX_XAQ_CNT(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_SSO_VHGRPX_XAQ_CNT(a) (a)
#define arguments_CAVM_SSO_VHGRPX_XAQ_CNT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_wq_int_pc
 *
 * SSO PF Work-Queue Interrupt Periodic Counter Register
 * Contains the threshold value for the work-executable interrupt periodic counter and also a
 * read-only copy of the periodic counter. For more information on this register, refer to
 * Interrupts.
 */
union cavm_sso_wq_int_pc
{
    uint64_t u;
    struct cavm_sso_wq_int_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t pc                    : 28; /**< [ 59: 32](RO/H) Work-executable interrupt periodic counter. */
        uint64_t reserved_28_31        : 4;
        uint64_t pc_thr                : 20; /**< [ 27:  8](R/W) Work-executable interrupt periodic counter threshold. Zero disables the counter.
                                                                 If nonzero, the value must be >= 3. */
        uint64_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_7          : 8;
        uint64_t pc_thr                : 20; /**< [ 27:  8](R/W) Work-executable interrupt periodic counter threshold. Zero disables the counter.
                                                                 If nonzero, the value must be >= 3. */
        uint64_t reserved_28_31        : 4;
        uint64_t pc                    : 28; /**< [ 59: 32](RO/H) Work-executable interrupt periodic counter. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_wq_int_pc_s cn; */
};
typedef union cavm_sso_wq_int_pc cavm_sso_wq_int_pc_t;

#define CAVM_SSO_WQ_INT_PC CAVM_SSO_WQ_INT_PC_FUNC()
static inline uint64_t CAVM_SSO_WQ_INT_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_WQ_INT_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001020ll;
    __cavm_csr_fatal("SSO_WQ_INT_PC", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_WQ_INT_PC cavm_sso_wq_int_pc_t
#define bustype_CAVM_SSO_WQ_INT_PC CSR_TYPE_NCB
#define basename_CAVM_SSO_WQ_INT_PC "SSO_WQ_INT_PC"
#define device_bar_CAVM_SSO_WQ_INT_PC 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_WQ_INT_PC 0
#define arguments_CAVM_SSO_WQ_INT_PC -1,-1,-1,-1

/**
 * Register (NCB) sso_ws_cfg
 *
 * SSO PF Configuration Register
 * This register contains various SSO work-slot configuration bits.
 */
union cavm_sso_ws_cfg
{
    uint64_t u;
    struct cavm_sso_ws_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t ocla_bp               : 8;  /**< [ 55: 48](R/W) Enable OCLA backpressure stalls. For diagnostic use only.
                                                                 Internal:
                                                                 <55> = NCBB input fifo stall (ncbo).
                                                                 <54> = Work-slot response. (arbrsp).
                                                                 <53> = Work-slot switching of descheduled work entries. (arbx).
                                                                 <52> = Work-slot SWTAG response. (arbs).
                                                                 <51> = Work-slot access to get-work engine. (arbgw).
                                                                 <50> = Work-slot CAM access. (arbc).
                                                                 <49> = Work-slot RAM access. (arbr).
                                                                 <48> = Work-slot pushes to AQ, CQ, DQ. (arbq). */
        uint64_t reserved_31_47        : 17;
        uint64_t bp_interval           : 3;  /**< [ 30: 28](R/W) Coprocessor-clock cycles between each 16 cycle interval of HWS backpressure.
                                                                 For diagnostic use only.
                                                                 0x0 = Disable this backpressure mechanism.
                                                                 0x1 =   64 cycles.
                                                                 0x2 =  128 cycles.
                                                                 0x3 =  256 cycles.
                                                                 0x4 =  512 cycles.
                                                                 0x5 = 1024 cycles.
                                                                 0x6 = 2048 cycles.
                                                                 0x7 = 4096 cycles. */
        uint64_t dqrd_replay_thr       : 12; /**< [ 27: 16](R/W) Theshold for the number of consecutive DQ reads that are aborted due
                                                                 to hazards without a successful DQ read. Equalling or exceeding the
                                                                 threshold indicates a potential deadlock due to a circular dependency
                                                                 of hazards and results in 16 cycles of backpressure to DQ readers
                                                                 to break free of the deadlock. A threshold of zero disables this
                                                                 backpressure mechanism.
                                                                 For diagnostic use only.

                                                                 Internal:
                                                                 The deadlock is caused by a HWS or AGTX making another HWS replay RAM
                                                                 reads while waiting for a CAM grant. The CAM grant gets aborted on
                                                                 seeing the replayed reads in progress, doesn't make forward progress,
                                                                 and makes other HWSs replay RAM reads. Applying backpressure to ARBR
                                                                 requests from the HWSs trying to replay RAM reads breaks the deadlock. */
        uint64_t reserved_8_15         : 8;
        uint64_t sai_flush             : 1;  /**< [  7:  7](R/W1) When written with one, send a pulse to invalidate the VHWS switch tag cache
                                                                 inside the cores.  Reads as zero. For diagnostic use only. */
        uint64_t aw_clk_dis            : 1;  /**< [  6:  6](R/W) Reserved. */
        uint64_t gw_clk_dis            : 1;  /**< [  5:  5](R/W) Reserved. */
        uint64_t disable_pw            : 1;  /**< [  4:  4](R/W) Reserved. */
        uint64_t arbc_step_en          : 1;  /**< [  3:  3](R/W) Enable single-stepping WS CAM arbiter, twice per 16 clocks. For diagnostic use only. */
        uint64_t ncbo_step_en          : 1;  /**< [  2:  2](R/W) Enable single-stepping commands from NCBO, once per 32 clocks. For diagnostic use only. */
        uint64_t soc_ccam_dis          : 1;  /**< [  1:  1](R/W) Disable power saving SOC conditional CAM. */
        uint64_t sso_cclk_dis          : 1;  /**< [  0:  0](R/W) Disable power saving SSO conditional clocking, */
#else /* Word 0 - Little Endian */
        uint64_t sso_cclk_dis          : 1;  /**< [  0:  0](R/W) Disable power saving SSO conditional clocking, */
        uint64_t soc_ccam_dis          : 1;  /**< [  1:  1](R/W) Disable power saving SOC conditional CAM. */
        uint64_t ncbo_step_en          : 1;  /**< [  2:  2](R/W) Enable single-stepping commands from NCBO, once per 32 clocks. For diagnostic use only. */
        uint64_t arbc_step_en          : 1;  /**< [  3:  3](R/W) Enable single-stepping WS CAM arbiter, twice per 16 clocks. For diagnostic use only. */
        uint64_t disable_pw            : 1;  /**< [  4:  4](R/W) Reserved. */
        uint64_t gw_clk_dis            : 1;  /**< [  5:  5](R/W) Reserved. */
        uint64_t aw_clk_dis            : 1;  /**< [  6:  6](R/W) Reserved. */
        uint64_t sai_flush             : 1;  /**< [  7:  7](R/W1) When written with one, send a pulse to invalidate the VHWS switch tag cache
                                                                 inside the cores.  Reads as zero. For diagnostic use only. */
        uint64_t reserved_8_15         : 8;
        uint64_t dqrd_replay_thr       : 12; /**< [ 27: 16](R/W) Theshold for the number of consecutive DQ reads that are aborted due
                                                                 to hazards without a successful DQ read. Equalling or exceeding the
                                                                 threshold indicates a potential deadlock due to a circular dependency
                                                                 of hazards and results in 16 cycles of backpressure to DQ readers
                                                                 to break free of the deadlock. A threshold of zero disables this
                                                                 backpressure mechanism.
                                                                 For diagnostic use only.

                                                                 Internal:
                                                                 The deadlock is caused by a HWS or AGTX making another HWS replay RAM
                                                                 reads while waiting for a CAM grant. The CAM grant gets aborted on
                                                                 seeing the replayed reads in progress, doesn't make forward progress,
                                                                 and makes other HWSs replay RAM reads. Applying backpressure to ARBR
                                                                 requests from the HWSs trying to replay RAM reads breaks the deadlock. */
        uint64_t bp_interval           : 3;  /**< [ 30: 28](R/W) Coprocessor-clock cycles between each 16 cycle interval of HWS backpressure.
                                                                 For diagnostic use only.
                                                                 0x0 = Disable this backpressure mechanism.
                                                                 0x1 =   64 cycles.
                                                                 0x2 =  128 cycles.
                                                                 0x3 =  256 cycles.
                                                                 0x4 =  512 cycles.
                                                                 0x5 = 1024 cycles.
                                                                 0x6 = 2048 cycles.
                                                                 0x7 = 4096 cycles. */
        uint64_t reserved_31_47        : 17;
        uint64_t ocla_bp               : 8;  /**< [ 55: 48](R/W) Enable OCLA backpressure stalls. For diagnostic use only.
                                                                 Internal:
                                                                 <55> = NCBB input fifo stall (ncbo).
                                                                 <54> = Work-slot response. (arbrsp).
                                                                 <53> = Work-slot switching of descheduled work entries. (arbx).
                                                                 <52> = Work-slot SWTAG response. (arbs).
                                                                 <51> = Work-slot access to get-work engine. (arbgw).
                                                                 <50> = Work-slot CAM access. (arbc).
                                                                 <49> = Work-slot RAM access. (arbr).
                                                                 <48> = Work-slot pushes to AQ, CQ, DQ. (arbq). */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ws_cfg_s cn; */
};
typedef union cavm_sso_ws_cfg cavm_sso_ws_cfg_t;

#define CAVM_SSO_WS_CFG CAVM_SSO_WS_CFG_FUNC()
static inline uint64_t CAVM_SSO_WS_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_WS_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001088ll;
    __cavm_csr_fatal("SSO_WS_CFG", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_WS_CFG cavm_sso_ws_cfg_t
#define bustype_CAVM_SSO_WS_CFG CSR_TYPE_NCB
#define basename_CAVM_SSO_WS_CFG "SSO_WS_CFG"
#define device_bar_CAVM_SSO_WS_CFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_WS_CFG 0
#define arguments_CAVM_SSO_WS_CFG -1,-1,-1,-1

/**
 * Register (NCB) sso_ws_eco
 *
 * INTERNAL: SSO PF WS ECO Register
 */
union cavm_sso_ws_eco
{
    uint64_t u;
    struct cavm_sso_ws_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t eco_rw                : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_ws_eco_s cn; */
};
typedef union cavm_sso_ws_eco cavm_sso_ws_eco_t;

#define CAVM_SSO_WS_ECO CAVM_SSO_WS_ECO_FUNC()
static inline uint64_t CAVM_SSO_WS_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_WS_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001048ll;
    __cavm_csr_fatal("SSO_WS_ECO", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_WS_ECO cavm_sso_ws_eco_t
#define bustype_CAVM_SSO_WS_ECO CSR_TYPE_NCB
#define basename_CAVM_SSO_WS_ECO "SSO_WS_ECO"
#define device_bar_CAVM_SSO_WS_ECO 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_WS_ECO 0
#define arguments_CAVM_SSO_WS_ECO -1,-1,-1,-1

/**
 * Register (NCB) sso_xaq#_head_next
 *
 * SSO PF Hardware-Group External Admission Queue Head Next Register
 * These registers contain the pointer to the next buffer to become the head when the final cache
 * line in this buffer is read.
 *
 * This register must not be written when SSO_VHGRP()_QCTL[ENA] is set.
 */
union cavm_sso_xaqx_head_next
{
    uint64_t u;
    struct cavm_sso_xaqx_head_next_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_0_6          : 7;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_6          : 7;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_xaqx_head_next_s cn; */
};
typedef union cavm_sso_xaqx_head_next cavm_sso_xaqx_head_next_t;

static inline uint64_t CAVM_SSO_XAQX_HEAD_NEXT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_XAQX_HEAD_NEXT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8600000a0000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_XAQX_HEAD_NEXT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_XAQX_HEAD_NEXT(a) cavm_sso_xaqx_head_next_t
#define bustype_CAVM_SSO_XAQX_HEAD_NEXT(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_XAQX_HEAD_NEXT(a) "SSO_XAQX_HEAD_NEXT"
#define device_bar_CAVM_SSO_XAQX_HEAD_NEXT(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_XAQX_HEAD_NEXT(a) (a)
#define arguments_CAVM_SSO_XAQX_HEAD_NEXT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_xaq#_head_ptr
 *
 * SSO PF Hardware-Group External Admission Queue Head Pointer Register
 * These registers contain the pointer to the first entry of the external linked
 * list(s) for a particular hardware-group. Software must initialize the external
 * linked list(s) by programming SSO_XAQ()_HEAD_PTR, SSO_XAQ()_HEAD_NEXT,
 * SSO_XAQ()_TAIL_PTR and SSO_XAQ()_TAIL_NEXT to identical values.
 *
 * This register must not be written when SSO_VHGRP()_QCTL[ENA] is set.
 */
union cavm_sso_xaqx_head_ptr
{
    uint64_t u;
    struct cavm_sso_xaqx_head_ptr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_5_6          : 2;
        uint64_t cl                    : 5;  /**< [  4:  0](R/W/H) Cache line number in buffer. Cache line zero contains the next pointer. */
#else /* Word 0 - Little Endian */
        uint64_t cl                    : 5;  /**< [  4:  0](R/W/H) Cache line number in buffer. Cache line zero contains the next pointer. */
        uint64_t reserved_5_6          : 2;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_xaqx_head_ptr_s cn; */
};
typedef union cavm_sso_xaqx_head_ptr cavm_sso_xaqx_head_ptr_t;

static inline uint64_t CAVM_SSO_XAQX_HEAD_PTR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_XAQX_HEAD_PTR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860000080000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_XAQX_HEAD_PTR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_XAQX_HEAD_PTR(a) cavm_sso_xaqx_head_ptr_t
#define bustype_CAVM_SSO_XAQX_HEAD_PTR(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_XAQX_HEAD_PTR(a) "SSO_XAQX_HEAD_PTR"
#define device_bar_CAVM_SSO_XAQX_HEAD_PTR(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_XAQX_HEAD_PTR(a) (a)
#define arguments_CAVM_SSO_XAQX_HEAD_PTR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_xaq#_tail_next
 *
 * SSO PF Hardware-Group External Admission Queue Tail Next Register
 * These registers contain the pointer to the next buffer to become the tail when the final cache
 * line in this buffer is written.  Register fields are identical to those in
 * SSO_XAQ()_HEAD_NEXT above.
 *
 * This register must not be written when SSO_VHGRP()_QCTL[ENA] is set.
 */
union cavm_sso_xaqx_tail_next
{
    uint64_t u;
    struct cavm_sso_xaqx_tail_next_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_0_6          : 7;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_6          : 7;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_xaqx_tail_next_s cn; */
};
typedef union cavm_sso_xaqx_tail_next cavm_sso_xaqx_tail_next_t;

static inline uint64_t CAVM_SSO_XAQX_TAIL_NEXT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_XAQX_TAIL_NEXT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8600000b0000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_XAQX_TAIL_NEXT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_XAQX_TAIL_NEXT(a) cavm_sso_xaqx_tail_next_t
#define bustype_CAVM_SSO_XAQX_TAIL_NEXT(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_XAQX_TAIL_NEXT(a) "SSO_XAQX_TAIL_NEXT"
#define device_bar_CAVM_SSO_XAQX_TAIL_NEXT(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_XAQX_TAIL_NEXT(a) (a)
#define arguments_CAVM_SSO_XAQX_TAIL_NEXT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_xaq#_tail_ptr
 *
 * SSO PF Hardware-Group External Admission Queue Tail Pointer Register
 * These registers contain the pointer to the last entry of the external linked list(s)
 * for a particular hardware-group. Register fields are identical to those in
 * SSO_XAQ()_HEAD_PTR above. Software must initialize the external linked list(s) by
 * programming SSO_XAQ()_HEAD_PTR, SSO_XAQ()_HEAD_NEXT, SSO_XAQ()_TAIL_PTR and
 * SSO_XAQ()_TAIL_NEXT to identical values.
 *
 * This register must not be written when SSO_VHGRP()_QCTL[ENA] is set.
 */
union cavm_sso_xaqx_tail_ptr
{
    uint64_t u;
    struct cavm_sso_xaqx_tail_ptr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_5_6          : 2;
        uint64_t cl                    : 5;  /**< [  4:  0](R/W/H) Cache line number in buffer. Cache line zero contains the next pointer. */
#else /* Word 0 - Little Endian */
        uint64_t cl                    : 5;  /**< [  4:  0](R/W/H) Cache line number in buffer. Cache line zero contains the next pointer. */
        uint64_t reserved_5_6          : 2;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_xaqx_tail_ptr_s cn; */
};
typedef union cavm_sso_xaqx_tail_ptr cavm_sso_xaqx_tail_ptr_t;

static inline uint64_t CAVM_SSO_XAQX_TAIL_PTR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_XAQX_TAIL_PTR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860000090000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("SSO_XAQX_TAIL_PTR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_XAQX_TAIL_PTR(a) cavm_sso_xaqx_tail_ptr_t
#define bustype_CAVM_SSO_XAQX_TAIL_PTR(a) CSR_TYPE_NCB
#define basename_CAVM_SSO_XAQX_TAIL_PTR(a) "SSO_XAQX_TAIL_PTR"
#define device_bar_CAVM_SSO_XAQX_TAIL_PTR(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_XAQX_TAIL_PTR(a) (a)
#define arguments_CAVM_SSO_XAQX_TAIL_PTR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_xaq_aura
 *
 * SSO PF External Admission Queue Aura Register
 */
union cavm_sso_xaq_aura
{
    uint64_t u;
    struct cavm_sso_xaq_aura_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t laura                 : 12; /**< [ 11:  0](R/W) FPA guest-aura to use for SSO XAQ allocations and frees. The FPA guest-aura
                                                                 selected by [LAURA] must correspond to a pool where the buffers (after any
                                                                 FPA_POOL()_CFG[BUF_OFFSET]) are at least 4 KB.
                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and SSO_XAQ_GMCTL[GMID] as valid. */
#else /* Word 0 - Little Endian */
        uint64_t laura                 : 12; /**< [ 11:  0](R/W) FPA guest-aura to use for SSO XAQ allocations and frees. The FPA guest-aura
                                                                 selected by [LAURA] must correspond to a pool where the buffers (after any
                                                                 FPA_POOL()_CFG[BUF_OFFSET]) are at least 4 KB.
                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and SSO_XAQ_GMCTL[GMID] as valid. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_xaq_aura_s cn; */
};
typedef union cavm_sso_xaq_aura cavm_sso_xaq_aura_t;

#define CAVM_SSO_XAQ_AURA CAVM_SSO_XAQ_AURA_FUNC()
static inline uint64_t CAVM_SSO_XAQ_AURA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_XAQ_AURA_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002100ll;
    __cavm_csr_fatal("SSO_XAQ_AURA", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_XAQ_AURA cavm_sso_xaq_aura_t
#define bustype_CAVM_SSO_XAQ_AURA CSR_TYPE_NCB
#define basename_CAVM_SSO_XAQ_AURA "SSO_XAQ_AURA"
#define device_bar_CAVM_SSO_XAQ_AURA 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_XAQ_AURA 0
#define arguments_CAVM_SSO_XAQ_AURA -1,-1,-1,-1

/**
 * Register (NCB) sso_xaq_gmctl
 *
 * SSO PF External Admission Queue Guest Machine Control Register
 */
union cavm_sso_xaq_gmctl
{
    uint64_t u;
    struct cavm_sso_xaq_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for all buffer
                                                                 free/allocates.
                                                                 Must be nonzero or FPA will drop requests; see FPA_PF_MAP(). */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for all buffer
                                                                 free/allocates.
                                                                 Must be nonzero or FPA will drop requests; see FPA_PF_MAP(). */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_xaq_gmctl_s cn; */
};
typedef union cavm_sso_xaq_gmctl cavm_sso_xaq_gmctl_t;

#define CAVM_SSO_XAQ_GMCTL CAVM_SSO_XAQ_GMCTL_FUNC()
static inline uint64_t CAVM_SSO_XAQ_GMCTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_XAQ_GMCTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002110ll;
    __cavm_csr_fatal("SSO_XAQ_GMCTL", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_XAQ_GMCTL cavm_sso_xaq_gmctl_t
#define bustype_CAVM_SSO_XAQ_GMCTL CSR_TYPE_NCB
#define basename_CAVM_SSO_XAQ_GMCTL "SSO_XAQ_GMCTL"
#define device_bar_CAVM_SSO_XAQ_GMCTL 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_XAQ_GMCTL 0
#define arguments_CAVM_SSO_XAQ_GMCTL -1,-1,-1,-1

/**
 * Register (NCB) sso_xaq_latency_pc
 *
 * SSO PF External Admission Queue Latency Perf-Count Register
 */
union cavm_sso_xaq_latency_pc
{
    uint64_t u;
    struct cavm_sso_xaq_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for XAQ read returns. This may be divided by SSO_XAQ_REQ_PC to
                                                                 determine the average read latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for XAQ read returns. This may be divided by SSO_XAQ_REQ_PC to
                                                                 determine the average read latency. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_xaq_latency_pc_s cn; */
};
typedef union cavm_sso_xaq_latency_pc cavm_sso_xaq_latency_pc_t;

#define CAVM_SSO_XAQ_LATENCY_PC CAVM_SSO_XAQ_LATENCY_PC_FUNC()
static inline uint64_t CAVM_SSO_XAQ_LATENCY_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_XAQ_LATENCY_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020b8ll;
    __cavm_csr_fatal("SSO_XAQ_LATENCY_PC", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_XAQ_LATENCY_PC cavm_sso_xaq_latency_pc_t
#define bustype_CAVM_SSO_XAQ_LATENCY_PC CSR_TYPE_NCB
#define basename_CAVM_SSO_XAQ_LATENCY_PC "SSO_XAQ_LATENCY_PC"
#define device_bar_CAVM_SSO_XAQ_LATENCY_PC 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_XAQ_LATENCY_PC 0
#define arguments_CAVM_SSO_XAQ_LATENCY_PC -1,-1,-1,-1

/**
 * Register (NCB) sso_xaq_req_pc
 *
 * SSO PF External Admission Queue Requests Perf-Count Register
 */
union cavm_sso_xaq_req_pc
{
    uint64_t u;
    struct cavm_sso_xaq_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of XAQ read requests. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of XAQ read requests. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_sso_xaq_req_pc_s cn; */
};
typedef union cavm_sso_xaq_req_pc cavm_sso_xaq_req_pc_t;

#define CAVM_SSO_XAQ_REQ_PC CAVM_SSO_XAQ_REQ_PC_FUNC()
static inline uint64_t CAVM_SSO_XAQ_REQ_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_SSO_XAQ_REQ_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020b0ll;
    __cavm_csr_fatal("SSO_XAQ_REQ_PC", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_SSO_XAQ_REQ_PC cavm_sso_xaq_req_pc_t
#define bustype_CAVM_SSO_XAQ_REQ_PC CSR_TYPE_NCB
#define basename_CAVM_SSO_XAQ_REQ_PC "SSO_XAQ_REQ_PC"
#define device_bar_CAVM_SSO_XAQ_REQ_PC 0x0 /* PF_BAR0 */
#define busnum_CAVM_SSO_XAQ_REQ_PC 0
#define arguments_CAVM_SSO_XAQ_REQ_PC -1,-1,-1,-1

#endif /* __CAVM_CSRS_SSO_H__ */
