#ifndef __CAVM_CSRS_TIM_H__
#define __CAVM_CSRS_TIM_H__
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
 * Cavium TIM.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration tim_bar_e
 *
 * TIM Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define CAVM_TIM_BAR_E_TIM_PF_BAR0 (0x858000000000ll)
#define CAVM_TIM_BAR_E_TIM_PF_BAR0_SIZE 0x100000ull
#define CAVM_TIM_BAR_E_TIM_PF_BAR4 (0x858000f00000ll)
#define CAVM_TIM_BAR_E_TIM_PF_BAR4_SIZE 0x100000ull
#define CAVM_TIM_BAR_E_TIM_VFX_BAR0(a) (0x858010000000ll + 0x100000ll * (a))
#define CAVM_TIM_BAR_E_TIM_VFX_BAR0_SIZE 0x100000ull
#define CAVM_TIM_BAR_E_TIM_VFX_BAR4(a) (0x858020000000ll + 0x100000ll * (a))
#define CAVM_TIM_BAR_E_TIM_VFX_BAR4_SIZE 0x100000ull

/**
 * Enumeration tim_clk_srcs_e
 *
 * TIM Clock Sources Enumeration
 * Enumerates TIM_RING()_CTL1[CLK_SRC].
 */
#define CAVM_TIM_CLK_SRCS_E_GPIO (1)
#define CAVM_TIM_CLK_SRCS_E_GTI (2)
#define CAVM_TIM_CLK_SRCS_E_PTP (3)
#define CAVM_TIM_CLK_SRCS_E_SCLK (0)

/**
 * Enumeration tim_pf_int_vec_e
 *
 * TIM PF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define CAVM_TIM_PF_INT_VEC_E_BKT_SKIP_INT (1)
#define CAVM_TIM_PF_INT_VEC_E_ECCERR (0)

/**
 * Enumeration tim_vf_int_vec_e
 *
 * TIM VF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define CAVM_TIM_VF_INT_VEC_E_NRSPERR (0)

/**
 * Structure tim_mem_bucket_s
 *
 * TIM Memory Bucket Structure
 */
union cavm_tim_mem_bucket_s
{
    uint64_t u[4];
    struct cavm_tim_mem_bucket_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t first_chunk           : 64; /**< [ 63:  0] Pointer to first chunk memory. <63:49,2:0> must be zero. Updated by software when a first
                                                                 chunk is added. Read by timer hardware. */
#else /* Word 0 - Little Endian */
        uint64_t first_chunk           : 64; /**< [ 63:  0] Pointer to first chunk memory. <63:49,2:0> must be zero. Updated by software when a first
                                                                 chunk is added. Read by timer hardware. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t chunk_remainder       : 16; /**< [127:112] Number of remaining entries for software to enter in the list. This number should always
                                                                 be smaller than chunk size. This field is decremented by software whenever software adds
                                                                 an entry. If [NUM_ENTRIES] is nonzero, written to zeros by hardware when hardware
                                                                 processes the entry unless TIM_RING()_CTL1[ENA_PRD] is set.

                                                                 Internal:
                                                                 Field must include bit w1<63> as it may underflow negative. */
        uint64_t lock                  : 8;  /**< [111:104] Count of how many outstanding software threads are working on the bucket.
                                                                 The field must be atomically incremented and decremented by software.
                                                                 Note that this allows up to 255 threads doing parallel operations.

                                                                 Hardware never writes this byte.

                                                                 Internal:
                                                                 Cannot overflow/underflow. MSB msut be on 8/16/32/64-bit boundary. */
        uint64_t reserved_99_103       : 5;
        uint64_t bsk                   : 1;  /**< [ 98: 98] Bucket skip indicator. Set by hardware to indicate to software that hardware has
                                                                 skipped processing the bucket because it was unable to gain the bucket lock.

                                                                 Cleared by the entity that traverses the bucket (either software or hardware). */
        uint64_t hbt                   : 1;  /**< [ 97: 97] Hardware bucket traversal indicator.
                                                                 Indicates that hardware is currently attempting to traverse the bucket. */
        uint64_t sbt                   : 1;  /**< [ 96: 96] Software bucket traversal indicator.
                                                                 Indicates that software is currently attempting to traverse the bucket. */
        uint64_t num_entries           : 32; /**< [ 95: 64] Number of entries that software added to the list. Incremented whenever software adds an
                                                                 entry. Written to zeros by hardware when hardware processes the list unless
                                                                 TIM_RING()_CTL1[ENA_PRD] is set. */
#else /* Word 1 - Little Endian */
        uint64_t num_entries           : 32; /**< [ 95: 64] Number of entries that software added to the list. Incremented whenever software adds an
                                                                 entry. Written to zeros by hardware when hardware processes the list unless
                                                                 TIM_RING()_CTL1[ENA_PRD] is set. */
        uint64_t sbt                   : 1;  /**< [ 96: 96] Software bucket traversal indicator.
                                                                 Indicates that software is currently attempting to traverse the bucket. */
        uint64_t hbt                   : 1;  /**< [ 97: 97] Hardware bucket traversal indicator.
                                                                 Indicates that hardware is currently attempting to traverse the bucket. */
        uint64_t bsk                   : 1;  /**< [ 98: 98] Bucket skip indicator. Set by hardware to indicate to software that hardware has
                                                                 skipped processing the bucket because it was unable to gain the bucket lock.

                                                                 Cleared by the entity that traverses the bucket (either software or hardware). */
        uint64_t reserved_99_103       : 5;
        uint64_t lock                  : 8;  /**< [111:104] Count of how many outstanding software threads are working on the bucket.
                                                                 The field must be atomically incremented and decremented by software.
                                                                 Note that this allows up to 255 threads doing parallel operations.

                                                                 Hardware never writes this byte.

                                                                 Internal:
                                                                 Cannot overflow/underflow. MSB msut be on 8/16/32/64-bit boundary. */
        uint64_t chunk_remainder       : 16; /**< [127:112] Number of remaining entries for software to enter in the list. This number should always
                                                                 be smaller than chunk size. This field is decremented by software whenever software adds
                                                                 an entry. If [NUM_ENTRIES] is nonzero, written to zeros by hardware when hardware
                                                                 processes the entry unless TIM_RING()_CTL1[ENA_PRD] is set.

                                                                 Internal:
                                                                 Field must include bit w1<63> as it may underflow negative. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t current_chunk         : 64; /**< [191:128] Not used by timer hardware. Points to the last chunk in the list and is updated by
                                                                 software whenever chunk is added to the list. */
#else /* Word 2 - Little Endian */
        uint64_t current_chunk         : 64; /**< [191:128] Not used by timer hardware. Points to the last chunk in the list and is updated by
                                                                 software whenever chunk is added to the list. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t pad                   : 64; /**< [255:192] Padding, not used by hardware. */
#else /* Word 3 - Little Endian */
        uint64_t pad                   : 64; /**< [255:192] Padding, not used by hardware. */
#endif /* Word 3 - End */
    } s;
    /* struct cavm_tim_mem_bucket_s_s cn; */
};

/**
 * Structure tim_mem_entry_s
 *
 * TIM Memory Entry Structure
 * Chunks contain 32-byte entries:
 */
union cavm_tim_mem_entry_s
{
    uint64_t u[2];
    struct cavm_tim_mem_entry_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t grp                   : 10; /**< [ 43: 34] SSO guest-group.
                                                                 For the SSO to not discard the add-work request, SSO_PF_MAP() must map
                                                                 [GRP] and TIM_VRING()_GMCTL[GMID] as valid. */
        uint64_t tt                    : 2;  /**< [ 33: 32] SSO tag type.  Enumerated by SSO_TT_E. */
        uint64_t tag                   : 32; /**< [ 31:  0] SSO tag. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0] SSO tag. */
        uint64_t tt                    : 2;  /**< [ 33: 32] SSO tag type.  Enumerated by SSO_TT_E. */
        uint64_t grp                   : 10; /**< [ 43: 34] SSO guest-group.
                                                                 For the SSO to not discard the add-work request, SSO_PF_MAP() must map
                                                                 [GRP] and TIM_VRING()_GMCTL[GMID] as valid. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t wqp                   : 64; /**< [127: 64] Pointer to a work-queue entry. An all-zero [WQP] is not sent to the SSO and may be used as
                                                                 a NOP.

                                                                 Bits <2:0> must be zero.  Bits <63:49> are ignored by hardware; software should
                                                                 store a sign-extended [WQP]<48> for forward compatibility. */
#else /* Word 1 - Little Endian */
        uint64_t wqp                   : 64; /**< [127: 64] Pointer to a work-queue entry. An all-zero [WQP] is not sent to the SSO and may be used as
                                                                 a NOP.

                                                                 Bits <2:0> must be zero.  Bits <63:49> are ignored by hardware; software should
                                                                 store a sign-extended [WQP]<48> for forward compatibility. */
#endif /* Word 1 - End */
    } s;
    /* struct cavm_tim_mem_entry_s_s cn; */
};

/**
 * Register (NCB) tim_bist_result
 *
 * TIM BIST Result Register
 * This register provides access to the internal timer BIST results. Each bit is the BIST result
 * of an individual memory (per bit, 0 = pass and 1 = fail).
 */
union cavm_tim_bist_result
{
    uint64_t u;
    struct cavm_tim_bist_result_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t bsk_mem               : 1;  /**< [  9:  9](RO/H) BIST result of the BSK memory. */
        uint64_t pf_msix_mem           : 1;  /**< [  8:  8](RO/H) BIST result of the PF_MSIX memory. */
        uint64_t vf_msix_mem           : 1;  /**< [  7:  7](RO/H) BIST result of the VF_MSIX memory. */
        uint64_t wqe_fifo              : 1;  /**< [  6:  6](RO/H) BIST result of the NCB WQE FIFO. */
        uint64_t csrf_fifo             : 1;  /**< [  5:  5](RO/H) Not used for this memory. Held at 0. */
        uint64_t lslr_fifo             : 1;  /**< [  4:  4](RO/H) BIST result of the NCB LSLR FIFO. */
        uint64_t ctl2                  : 1;  /**< [  3:  3](RO/H) BIST result of the CTL2 memory. */
        uint64_t ctl1                  : 1;  /**< [  2:  2](RO/H) BIST result of the CTL1 memory. */
        uint64_t base                  : 1;  /**< [  1:  1](RO/H) BIST result of the BASE memory. */
        uint64_t ctl0_mem              : 1;  /**< [  0:  0](RO/H) BIST result of the CTL0 memory. */
#else /* Word 0 - Little Endian */
        uint64_t ctl0_mem              : 1;  /**< [  0:  0](RO/H) BIST result of the CTL0 memory. */
        uint64_t base                  : 1;  /**< [  1:  1](RO/H) BIST result of the BASE memory. */
        uint64_t ctl1                  : 1;  /**< [  2:  2](RO/H) BIST result of the CTL1 memory. */
        uint64_t ctl2                  : 1;  /**< [  3:  3](RO/H) BIST result of the CTL2 memory. */
        uint64_t lslr_fifo             : 1;  /**< [  4:  4](RO/H) BIST result of the NCB LSLR FIFO. */
        uint64_t csrf_fifo             : 1;  /**< [  5:  5](RO/H) Not used for this memory. Held at 0. */
        uint64_t wqe_fifo              : 1;  /**< [  6:  6](RO/H) BIST result of the NCB WQE FIFO. */
        uint64_t vf_msix_mem           : 1;  /**< [  7:  7](RO/H) BIST result of the VF_MSIX memory. */
        uint64_t pf_msix_mem           : 1;  /**< [  8:  8](RO/H) BIST result of the PF_MSIX memory. */
        uint64_t bsk_mem               : 1;  /**< [  9:  9](RO/H) BIST result of the BSK memory. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_bist_result_s cn; */
};
typedef union cavm_tim_bist_result cavm_tim_bist_result_t;

#define CAVM_TIM_BIST_RESULT CAVM_TIM_BIST_RESULT_FUNC()
static inline uint64_t CAVM_TIM_BIST_RESULT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_BIST_RESULT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000020ll;
    __cavm_csr_fatal("TIM_BIST_RESULT", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_BIST_RESULT cavm_tim_bist_result_t
#define bustype_CAVM_TIM_BIST_RESULT CSR_TYPE_NCB
#define basename_CAVM_TIM_BIST_RESULT "TIM_BIST_RESULT"
#define device_bar_CAVM_TIM_BIST_RESULT 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_BIST_RESULT 0
#define arguments_CAVM_TIM_BIST_RESULT -1,-1,-1,-1

/**
 * Register (NCB) tim_bkt_skip_ena_w1c
 *
 * TIM Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_tim_bkt_skip_ena_w1c
{
    uint64_t u;
    struct cavm_tim_bkt_skip_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t bkt_skip              : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for TIM_BKT_SKIP_INT[BKT_SKIP]. */
#else /* Word 0 - Little Endian */
        uint64_t bkt_skip              : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for TIM_BKT_SKIP_INT[BKT_SKIP]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_bkt_skip_ena_w1c_s cn; */
};
typedef union cavm_tim_bkt_skip_ena_w1c cavm_tim_bkt_skip_ena_w1c_t;

#define CAVM_TIM_BKT_SKIP_ENA_W1C CAVM_TIM_BKT_SKIP_ENA_W1C_FUNC()
static inline uint64_t CAVM_TIM_BKT_SKIP_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_BKT_SKIP_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000100ll;
    __cavm_csr_fatal("TIM_BKT_SKIP_ENA_W1C", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_BKT_SKIP_ENA_W1C cavm_tim_bkt_skip_ena_w1c_t
#define bustype_CAVM_TIM_BKT_SKIP_ENA_W1C CSR_TYPE_NCB
#define basename_CAVM_TIM_BKT_SKIP_ENA_W1C "TIM_BKT_SKIP_ENA_W1C"
#define device_bar_CAVM_TIM_BKT_SKIP_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_BKT_SKIP_ENA_W1C 0
#define arguments_CAVM_TIM_BKT_SKIP_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) tim_bkt_skip_ena_w1s
 *
 * TIM Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_tim_bkt_skip_ena_w1s
{
    uint64_t u;
    struct cavm_tim_bkt_skip_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t bkt_skip              : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for TIM_BKT_SKIP_INT[BKT_SKIP]. */
#else /* Word 0 - Little Endian */
        uint64_t bkt_skip              : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for TIM_BKT_SKIP_INT[BKT_SKIP]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_bkt_skip_ena_w1s_s cn; */
};
typedef union cavm_tim_bkt_skip_ena_w1s cavm_tim_bkt_skip_ena_w1s_t;

#define CAVM_TIM_BKT_SKIP_ENA_W1S CAVM_TIM_BKT_SKIP_ENA_W1S_FUNC()
static inline uint64_t CAVM_TIM_BKT_SKIP_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_BKT_SKIP_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000108ll;
    __cavm_csr_fatal("TIM_BKT_SKIP_ENA_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_BKT_SKIP_ENA_W1S cavm_tim_bkt_skip_ena_w1s_t
#define bustype_CAVM_TIM_BKT_SKIP_ENA_W1S CSR_TYPE_NCB
#define basename_CAVM_TIM_BKT_SKIP_ENA_W1S "TIM_BKT_SKIP_ENA_W1S"
#define device_bar_CAVM_TIM_BKT_SKIP_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_BKT_SKIP_ENA_W1S 0
#define arguments_CAVM_TIM_BKT_SKIP_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) tim_bkt_skip_int
 *
 * TIM BKT_SKIP_INT Interrupt Register
 */
union cavm_tim_bkt_skip_int
{
    uint64_t u;
    struct cavm_tim_bkt_skip_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t bkt_skip              : 64; /**< [ 63:  0](R/W1C/H) Interrupt bit per ring. Each bit corresponds to rings 63:0 respectively.
                                                                 If set, at least one bucket was skipped by hardware, when a ring has expired.
                                                                 Hardware sets this when TIM attempted traversal but the bucket's
                                                                 TIM_MEM_BUCKET_S[SBT] was set or TIM_MEM_BUCKET_S[LOCK] was non-zero. */
#else /* Word 0 - Little Endian */
        uint64_t bkt_skip              : 64; /**< [ 63:  0](R/W1C/H) Interrupt bit per ring. Each bit corresponds to rings 63:0 respectively.
                                                                 If set, at least one bucket was skipped by hardware, when a ring has expired.
                                                                 Hardware sets this when TIM attempted traversal but the bucket's
                                                                 TIM_MEM_BUCKET_S[SBT] was set or TIM_MEM_BUCKET_S[LOCK] was non-zero. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_bkt_skip_int_s cn; */
};
typedef union cavm_tim_bkt_skip_int cavm_tim_bkt_skip_int_t;

#define CAVM_TIM_BKT_SKIP_INT CAVM_TIM_BKT_SKIP_INT_FUNC()
static inline uint64_t CAVM_TIM_BKT_SKIP_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_BKT_SKIP_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000030ll;
    __cavm_csr_fatal("TIM_BKT_SKIP_INT", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_BKT_SKIP_INT cavm_tim_bkt_skip_int_t
#define bustype_CAVM_TIM_BKT_SKIP_INT CSR_TYPE_NCB
#define basename_CAVM_TIM_BKT_SKIP_INT "TIM_BKT_SKIP_INT"
#define device_bar_CAVM_TIM_BKT_SKIP_INT 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_BKT_SKIP_INT 0
#define arguments_CAVM_TIM_BKT_SKIP_INT -1,-1,-1,-1

/**
 * Register (NCB) tim_bkt_skip_int_status#
 *
 * TIM BKT_SKIP_INT Ring Status Register
 */
union cavm_tim_bkt_skip_int_statusx
{
    uint64_t u;
    struct cavm_tim_bkt_skip_int_statusx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t bkt_skip_id           : 20; /**< [ 19:  0](RO/H) When TIM_BKT_SKIP_INT<{a}> gets set, this field reflects the bucket that was skipped
                                                                 for ring {a}. For diagnostic use only, as only one ring's status is kept. */
#else /* Word 0 - Little Endian */
        uint64_t bkt_skip_id           : 20; /**< [ 19:  0](RO/H) When TIM_BKT_SKIP_INT<{a}> gets set, this field reflects the bucket that was skipped
                                                                 for ring {a}. For diagnostic use only, as only one ring's status is kept. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_bkt_skip_int_statusx_s cn; */
};
typedef union cavm_tim_bkt_skip_int_statusx cavm_tim_bkt_skip_int_statusx_t;

static inline uint64_t CAVM_TIM_BKT_SKIP_INT_STATUSX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_BKT_SKIP_INT_STATUSX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858000002c00ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_BKT_SKIP_INT_STATUSX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_BKT_SKIP_INT_STATUSX(a) cavm_tim_bkt_skip_int_statusx_t
#define bustype_CAVM_TIM_BKT_SKIP_INT_STATUSX(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_BKT_SKIP_INT_STATUSX(a) "TIM_BKT_SKIP_INT_STATUSX"
#define device_bar_CAVM_TIM_BKT_SKIP_INT_STATUSX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_BKT_SKIP_INT_STATUSX(a) (a)
#define arguments_CAVM_TIM_BKT_SKIP_INT_STATUSX(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_bkt_skip_int_w1s
 *
 * TIM Interrupt Set Register
 * This register sets interrupt bits.
 */
union cavm_tim_bkt_skip_int_w1s
{
    uint64_t u;
    struct cavm_tim_bkt_skip_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t bkt_skip              : 64; /**< [ 63:  0](R/W1S/H) Reads or sets TIM_BKT_SKIP_INT[BKT_SKIP]. */
#else /* Word 0 - Little Endian */
        uint64_t bkt_skip              : 64; /**< [ 63:  0](R/W1S/H) Reads or sets TIM_BKT_SKIP_INT[BKT_SKIP]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_bkt_skip_int_w1s_s cn; */
};
typedef union cavm_tim_bkt_skip_int_w1s cavm_tim_bkt_skip_int_w1s_t;

#define CAVM_TIM_BKT_SKIP_INT_W1S CAVM_TIM_BKT_SKIP_INT_W1S_FUNC()
static inline uint64_t CAVM_TIM_BKT_SKIP_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_BKT_SKIP_INT_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000040ll;
    __cavm_csr_fatal("TIM_BKT_SKIP_INT_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_BKT_SKIP_INT_W1S cavm_tim_bkt_skip_int_w1s_t
#define bustype_CAVM_TIM_BKT_SKIP_INT_W1S CSR_TYPE_NCB
#define basename_CAVM_TIM_BKT_SKIP_INT_W1S "TIM_BKT_SKIP_INT_W1S"
#define device_bar_CAVM_TIM_BKT_SKIP_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_BKT_SKIP_INT_W1S 0
#define arguments_CAVM_TIM_BKT_SKIP_INT_W1S -1,-1,-1,-1

/**
 * Register (NCB) tim_bp_test
 *
 * INTERNAL: TIM Backpressure Test Register
 */
union cavm_tim_bp_test
{
    uint64_t u;
    struct cavm_tim_bp_test_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t ncb_wqe_bp            : 1;  /**< [ 11: 11](R/W) NCB WQE CSR FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_wqe FIFO valid
                                                                 (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill. */
        uint64_t ncbmux_dstmem_bp      : 1;  /**< [ 10: 10](R/W) NCBMUX DSTMEM FIFO backpressure.
                                                                 When asserted, the tim.tim_csr.tim_csr_ncbmux.ncb_dstmem FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill.
                                                                 Only the RSL path can be used when this bit is set. */
        uint64_t ncbmux_ctlmem_bp      : 1;  /**< [  9:  9](R/W) NCBMUX CTLMEM FIFO backpressure.
                                                                 When asserted, the tim.tim_csr.tim_csr_ncbmux.ncb_ctlmem FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill.
                                                                 Only the RSL path can be used when this bit is set. */
        uint64_t ncb_fpa_bp            : 1;  /**< [  8:  8](R/W) NCB CSR FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.ncbi_csrf FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill. */
        uint64_t ncb_sta_bp            : 4;  /**< [  7:  4](R/W) NCB STA backpressure.
                                                                 When asserted, this blocks specific STAs (3-0) from sending
                                                                 requests. This combines the tim.tim_ncb.tim_ncb_tag.sfsta[3:0]_fifo
                                                                 and tim.tim_ncb.tim_ncb_tag.nwfsta[3:0]_fifo backpressuring. */
        uint64_t ncb_csrf_bp           : 1;  /**< [  3:  3](R/W) NCB CSR FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.ncbi_csrf FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, beyond what was already arbitrated
                                                                 for the NCBI bus, allowing it to fill.
                                                                 Only the RSL path can be used for access when this bit is
                                                                 set. All NCB-based CSR accesses will not respond, and NCB
                                                                 credits will not be returned, once the downstream FIFOs
                                                                 fill up. */
        uint64_t ncb_lslr_bp           : 1;  /**< [  2:  2](R/W) NCB LSLR FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.lslr_mem FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, beyond what was already arbitrated
                                                                 for the NCBI bus, allowing it to fill.
                                                                 This will stop requests from the STA engines, when the
                                                                 FIFO reaches full. */
        uint64_t ncbi_rsp_gnt_bp       : 1;  /**< [  1:  1](R/W) NCBI response grant FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.ncbi_cgntf FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill.
                                                                 Only the RSL path can be used for access when this bit is
                                                                 set. All NCB-based CSR accesses will not respond, and NCB
                                                                 credits will not be returned, once the downstream FIFOs
                                                                 fill up. */
        uint64_t ncbi_req_gnt_bp       : 1;  /**< [  0:  0](R/W) NCBI request grant FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.ncbi_lgntf FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill.
                                                                 This will stop requests from the STA engines, when both
                                                                 this FIFO, and the LSLR FIFO reaches full. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_req_gnt_bp       : 1;  /**< [  0:  0](R/W) NCBI request grant FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.ncbi_lgntf FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill.
                                                                 This will stop requests from the STA engines, when both
                                                                 this FIFO, and the LSLR FIFO reaches full. */
        uint64_t ncbi_rsp_gnt_bp       : 1;  /**< [  1:  1](R/W) NCBI response grant FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.ncbi_cgntf FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill.
                                                                 Only the RSL path can be used for access when this bit is
                                                                 set. All NCB-based CSR accesses will not respond, and NCB
                                                                 credits will not be returned, once the downstream FIFOs
                                                                 fill up. */
        uint64_t ncb_lslr_bp           : 1;  /**< [  2:  2](R/W) NCB LSLR FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.lslr_mem FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, beyond what was already arbitrated
                                                                 for the NCBI bus, allowing it to fill.
                                                                 This will stop requests from the STA engines, when the
                                                                 FIFO reaches full. */
        uint64_t ncb_csrf_bp           : 1;  /**< [  3:  3](R/W) NCB CSR FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.ncbi_csrf FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, beyond what was already arbitrated
                                                                 for the NCBI bus, allowing it to fill.
                                                                 Only the RSL path can be used for access when this bit is
                                                                 set. All NCB-based CSR accesses will not respond, and NCB
                                                                 credits will not be returned, once the downstream FIFOs
                                                                 fill up. */
        uint64_t ncb_sta_bp            : 4;  /**< [  7:  4](R/W) NCB STA backpressure.
                                                                 When asserted, this blocks specific STAs (3-0) from sending
                                                                 requests. This combines the tim.tim_ncb.tim_ncb_tag.sfsta[3:0]_fifo
                                                                 and tim.tim_ncb.tim_ncb_tag.nwfsta[3:0]_fifo backpressuring. */
        uint64_t ncb_fpa_bp            : 1;  /**< [  8:  8](R/W) NCB CSR FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_ncb_arb.ncbi_csrf FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill. */
        uint64_t ncbmux_ctlmem_bp      : 1;  /**< [  9:  9](R/W) NCBMUX CTLMEM FIFO backpressure.
                                                                 When asserted, the tim.tim_csr.tim_csr_ncbmux.ncb_ctlmem FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill.
                                                                 Only the RSL path can be used when this bit is set. */
        uint64_t ncbmux_dstmem_bp      : 1;  /**< [ 10: 10](R/W) NCBMUX DSTMEM FIFO backpressure.
                                                                 When asserted, the tim.tim_csr.tim_csr_ncbmux.ncb_dstmem FIFO
                                                                 valid (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill.
                                                                 Only the RSL path can be used when this bit is set. */
        uint64_t ncb_wqe_bp            : 1;  /**< [ 11: 11](R/W) NCB WQE CSR FIFO backpressure.
                                                                 When asserted, the tim.tim_ncb.tim_wqe FIFO valid
                                                                 (an entry is in the FIFO) is blocked. This creates
                                                                 no popping of the FIFO, allowing it to fill. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_bp_test_s cn; */
};
typedef union cavm_tim_bp_test cavm_tim_bp_test_t;

#define CAVM_TIM_BP_TEST CAVM_TIM_BP_TEST_FUNC()
static inline uint64_t CAVM_TIM_BP_TEST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_BP_TEST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000150ll;
    __cavm_csr_fatal("TIM_BP_TEST", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_BP_TEST cavm_tim_bp_test_t
#define bustype_CAVM_TIM_BP_TEST CSR_TYPE_NCB
#define basename_CAVM_TIM_BP_TEST "TIM_BP_TEST"
#define device_bar_CAVM_TIM_BP_TEST 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_BP_TEST 0
#define arguments_CAVM_TIM_BP_TEST -1,-1,-1,-1

/**
 * Register (NCB) tim_dbg2
 *
 * TIM Debug 2 Register
 */
union cavm_tim_dbg2
{
    uint64_t u;
    struct cavm_tim_dbg2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mem_alloc_reg         : 8;  /**< [ 63: 56](RO/H) NCBI load memory allocation status. */
        uint64_t reserved_54_55        : 2;
        uint64_t cgnt_fifo_level       : 4;  /**< [ 53: 50](RO/H) NCBI grant for Response FIFO level. */
        uint64_t lgnt_fifo_level       : 4;  /**< [ 49: 46](RO/H) NCBI grant for Request FIFO level. */
        uint64_t reserved_45           : 1;
        uint64_t fpa_fifo_level        : 3;  /**< [ 44: 42](RO/H) FPA FIFO level. */
        uint64_t lslr_fifo_level       : 6;  /**< [ 41: 36](RO/H) NCBI requests FIFO level. */
        uint64_t csrf_fifo_level       : 4;  /**< [ 35: 32](RO/H) NCBI requests FIFO level. */
        uint64_t reserved_28_31        : 4;
        uint64_t wqe_fifo_level        : 8;  /**< [ 27: 20](RO/H) NCBI WQE LD FIFO level. */
        uint64_t fsm3_state            : 5;  /**< [ 19: 15](RO/H) FSM 3 current state. */
        uint64_t fsm2_state            : 5;  /**< [ 14: 10](RO/H) FSM 2 current state. */
        uint64_t fsm1_state            : 5;  /**< [  9:  5](RO/H) FSM 1 current state. */
        uint64_t fsm0_state            : 5;  /**< [  4:  0](RO/H) FSM 0 current state. */
#else /* Word 0 - Little Endian */
        uint64_t fsm0_state            : 5;  /**< [  4:  0](RO/H) FSM 0 current state. */
        uint64_t fsm1_state            : 5;  /**< [  9:  5](RO/H) FSM 1 current state. */
        uint64_t fsm2_state            : 5;  /**< [ 14: 10](RO/H) FSM 2 current state. */
        uint64_t fsm3_state            : 5;  /**< [ 19: 15](RO/H) FSM 3 current state. */
        uint64_t wqe_fifo_level        : 8;  /**< [ 27: 20](RO/H) NCBI WQE LD FIFO level. */
        uint64_t reserved_28_31        : 4;
        uint64_t csrf_fifo_level       : 4;  /**< [ 35: 32](RO/H) NCBI requests FIFO level. */
        uint64_t lslr_fifo_level       : 6;  /**< [ 41: 36](RO/H) NCBI requests FIFO level. */
        uint64_t fpa_fifo_level        : 3;  /**< [ 44: 42](RO/H) FPA FIFO level. */
        uint64_t reserved_45           : 1;
        uint64_t lgnt_fifo_level       : 4;  /**< [ 49: 46](RO/H) NCBI grant for Request FIFO level. */
        uint64_t cgnt_fifo_level       : 4;  /**< [ 53: 50](RO/H) NCBI grant for Response FIFO level. */
        uint64_t reserved_54_55        : 2;
        uint64_t mem_alloc_reg         : 8;  /**< [ 63: 56](RO/H) NCBI load memory allocation status. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_dbg2_s cn; */
};
typedef union cavm_tim_dbg2 cavm_tim_dbg2_t;

#define CAVM_TIM_DBG2 CAVM_TIM_DBG2_FUNC()
static inline uint64_t CAVM_TIM_DBG2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_DBG2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8580000000a0ll;
    __cavm_csr_fatal("TIM_DBG2", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_DBG2 cavm_tim_dbg2_t
#define bustype_CAVM_TIM_DBG2 CSR_TYPE_NCB
#define basename_CAVM_TIM_DBG2 "TIM_DBG2"
#define device_bar_CAVM_TIM_DBG2 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_DBG2 0
#define arguments_CAVM_TIM_DBG2 -1,-1,-1,-1

/**
 * Register (NCB) tim_dbg3
 *
 * TIM Debug 3 Register
 */
union cavm_tim_dbg3
{
    uint64_t u;
    struct cavm_tim_dbg3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rings_pending_vec     : 64; /**< [ 63:  0](RO/H) Pending rings vector. Indicates which ring in TIM are pending traversal. Bit 0 represents
                                                                 ring 0 while bit 63 represents ring 63. */
#else /* Word 0 - Little Endian */
        uint64_t rings_pending_vec     : 64; /**< [ 63:  0](RO/H) Pending rings vector. Indicates which ring in TIM are pending traversal. Bit 0 represents
                                                                 ring 0 while bit 63 represents ring 63. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_dbg3_s cn; */
};
typedef union cavm_tim_dbg3 cavm_tim_dbg3_t;

#define CAVM_TIM_DBG3 CAVM_TIM_DBG3_FUNC()
static inline uint64_t CAVM_TIM_DBG3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_DBG3_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8580000000a8ll;
    __cavm_csr_fatal("TIM_DBG3", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_DBG3 cavm_tim_dbg3_t
#define bustype_CAVM_TIM_DBG3 CSR_TYPE_NCB
#define basename_CAVM_TIM_DBG3 "TIM_DBG3"
#define device_bar_CAVM_TIM_DBG3 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_DBG3 0
#define arguments_CAVM_TIM_DBG3 -1,-1,-1,-1

/**
 * Register (NCB) tim_ecc_cfg
 *
 * TIM ECC Configuration Register
 */
union cavm_tim_ecc_cfg
{
    uint64_t u;
    struct cavm_tim_ecc_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t auto_corr             : 1;  /**< [  3:  3](R/W) Reserved.
                                                                 Internal:
                                                                 Must be 0.
                                                                 Enable ECC auto-correction of CTL0-2 and BASE RAM single-bit errors.
                                                                 The internal logic will write back the corrected
                                                                 data to the location reporting a single-bit error. */
        uint64_t ecc_flp_syn           : 2;  /**< [  2:  1](R/W) ECC flip syndrome. Flip the ECC's syndrome for testing purposes, to test SBE and DBE ECC
                                                                 interrupts. */
        uint64_t ecc_en                : 1;  /**< [  0:  0](R/W) Enable ECC correction of the ring data structure memory.
                                                                 Refer to TIM_ECCERR_INT for a list of ECC-protected memories. */
#else /* Word 0 - Little Endian */
        uint64_t ecc_en                : 1;  /**< [  0:  0](R/W) Enable ECC correction of the ring data structure memory.
                                                                 Refer to TIM_ECCERR_INT for a list of ECC-protected memories. */
        uint64_t ecc_flp_syn           : 2;  /**< [  2:  1](R/W) ECC flip syndrome. Flip the ECC's syndrome for testing purposes, to test SBE and DBE ECC
                                                                 interrupts. */
        uint64_t auto_corr             : 1;  /**< [  3:  3](R/W) Reserved.
                                                                 Internal:
                                                                 Must be 0.
                                                                 Enable ECC auto-correction of CTL0-2 and BASE RAM single-bit errors.
                                                                 The internal logic will write back the corrected
                                                                 data to the location reporting a single-bit error. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_ecc_cfg_s cn; */
};
typedef union cavm_tim_ecc_cfg cavm_tim_ecc_cfg_t;

#define CAVM_TIM_ECC_CFG CAVM_TIM_ECC_CFG_FUNC()
static inline uint64_t CAVM_TIM_ECC_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_ECC_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000018ll;
    __cavm_csr_fatal("TIM_ECC_CFG", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_ECC_CFG cavm_tim_ecc_cfg_t
#define bustype_CAVM_TIM_ECC_CFG CSR_TYPE_NCB
#define basename_CAVM_TIM_ECC_CFG "TIM_ECC_CFG"
#define device_bar_CAVM_TIM_ECC_CFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_ECC_CFG 0
#define arguments_CAVM_TIM_ECC_CFG -1,-1,-1,-1

/**
 * Register (NCB) tim_eccerr_ena_w1c
 *
 * TIM ECC Error Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_tim_eccerr_ena_w1c
{
    uint64_t u;
    struct cavm_tim_eccerr_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t msix_pmem_dbe         : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[MSIX_PMEM_DBE]. */
        uint64_t msix_pmem_sbe         : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[MSIX_PMEM_SBE]. */
        uint64_t msix_vmem_dbe         : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[MSIX_VMEM_DBE]. */
        uint64_t msix_vmem_sbe         : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[MSIX_VMEM_SBE]. */
        uint64_t ctl0_dbe              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL0_DBE]. */
        uint64_t ctl0_sbe              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL0_SBE]. */
        uint64_t ctl1_dbe              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL1_DBE]. */
        uint64_t ctl1_sbe              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL1_SBE]. */
        uint64_t ctl2_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL2_DBE]. */
        uint64_t ctl2_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL2_SBE]. */
        uint64_t base_dbe              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[BASE_DBE]. */
        uint64_t base_sbe              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[BASE_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t base_sbe              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[BASE_SBE]. */
        uint64_t base_dbe              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[BASE_DBE]. */
        uint64_t ctl2_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL2_SBE]. */
        uint64_t ctl2_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL2_DBE]. */
        uint64_t ctl1_sbe              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL1_SBE]. */
        uint64_t ctl1_dbe              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL1_DBE]. */
        uint64_t ctl0_sbe              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL0_SBE]. */
        uint64_t ctl0_dbe              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[CTL0_DBE]. */
        uint64_t msix_vmem_sbe         : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[MSIX_VMEM_SBE]. */
        uint64_t msix_vmem_dbe         : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[MSIX_VMEM_DBE]. */
        uint64_t msix_pmem_sbe         : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[MSIX_PMEM_SBE]. */
        uint64_t msix_pmem_dbe         : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for TIM_ECCERR_INT[MSIX_PMEM_DBE]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_eccerr_ena_w1c_s cn; */
};
typedef union cavm_tim_eccerr_ena_w1c cavm_tim_eccerr_ena_w1c_t;

#define CAVM_TIM_ECCERR_ENA_W1C CAVM_TIM_ECCERR_ENA_W1C_FUNC()
static inline uint64_t CAVM_TIM_ECCERR_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_ECCERR_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000110ll;
    __cavm_csr_fatal("TIM_ECCERR_ENA_W1C", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_ECCERR_ENA_W1C cavm_tim_eccerr_ena_w1c_t
#define bustype_CAVM_TIM_ECCERR_ENA_W1C CSR_TYPE_NCB
#define basename_CAVM_TIM_ECCERR_ENA_W1C "TIM_ECCERR_ENA_W1C"
#define device_bar_CAVM_TIM_ECCERR_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_ECCERR_ENA_W1C 0
#define arguments_CAVM_TIM_ECCERR_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) tim_eccerr_ena_w1s
 *
 * TIM ECC Error Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_tim_eccerr_ena_w1s
{
    uint64_t u;
    struct cavm_tim_eccerr_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t msix_pmem_dbe         : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[MSIX_PMEM_DBE]. */
        uint64_t msix_pmem_sbe         : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[MSIX_PMEM_SBE]. */
        uint64_t msix_vmem_dbe         : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[MSIX_VMEM_DBE]. */
        uint64_t msix_vmem_sbe         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[MSIX_VMEM_SBE]. */
        uint64_t ctl0_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL0_DBE]. */
        uint64_t ctl0_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL0_SBE]. */
        uint64_t ctl1_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL1_DBE]. */
        uint64_t ctl1_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL1_SBE]. */
        uint64_t ctl2_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL2_DBE]. */
        uint64_t ctl2_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL2_SBE]. */
        uint64_t base_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[BASE_DBE]. */
        uint64_t base_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[BASE_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t base_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[BASE_SBE]. */
        uint64_t base_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[BASE_DBE]. */
        uint64_t ctl2_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL2_SBE]. */
        uint64_t ctl2_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL2_DBE]. */
        uint64_t ctl1_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL1_SBE]. */
        uint64_t ctl1_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL1_DBE]. */
        uint64_t ctl0_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL0_SBE]. */
        uint64_t ctl0_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[CTL0_DBE]. */
        uint64_t msix_vmem_sbe         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[MSIX_VMEM_SBE]. */
        uint64_t msix_vmem_dbe         : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[MSIX_VMEM_DBE]. */
        uint64_t msix_pmem_sbe         : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[MSIX_PMEM_SBE]. */
        uint64_t msix_pmem_dbe         : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for TIM_ECCERR_INT[MSIX_PMEM_DBE]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_eccerr_ena_w1s_s cn; */
};
typedef union cavm_tim_eccerr_ena_w1s cavm_tim_eccerr_ena_w1s_t;

#define CAVM_TIM_ECCERR_ENA_W1S CAVM_TIM_ECCERR_ENA_W1S_FUNC()
static inline uint64_t CAVM_TIM_ECCERR_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_ECCERR_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000118ll;
    __cavm_csr_fatal("TIM_ECCERR_ENA_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_ECCERR_ENA_W1S cavm_tim_eccerr_ena_w1s_t
#define bustype_CAVM_TIM_ECCERR_ENA_W1S CSR_TYPE_NCB
#define basename_CAVM_TIM_ECCERR_ENA_W1S "TIM_ECCERR_ENA_W1S"
#define device_bar_CAVM_TIM_ECCERR_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_ECCERR_ENA_W1S 0
#define arguments_CAVM_TIM_ECCERR_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) tim_eccerr_int
 *
 * TIM ECC Error Interrupt Register
 */
union cavm_tim_eccerr_int
{
    uint64_t u;
    struct cavm_tim_eccerr_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t msix_pmem_dbe         : 1;  /**< [ 11: 11](R/W1C/H) MSIX PMEM memory had a double-bit error. */
        uint64_t msix_pmem_sbe         : 1;  /**< [ 10: 10](R/W1C/H) MSIX PMEM memory had a single-bit error. */
        uint64_t msix_vmem_dbe         : 1;  /**< [  9:  9](R/W1C/H) MSIX VMEM memory had a double-bit error. */
        uint64_t msix_vmem_sbe         : 1;  /**< [  8:  8](R/W1C/H) MSIX VMEM memory had a single-bit error. */
        uint64_t ctl0_dbe              : 1;  /**< [  7:  7](R/W1C/H) TIM CTL0 memory had a double-bit error. */
        uint64_t ctl0_sbe              : 1;  /**< [  6:  6](R/W1C/H) TIM CTL0 memory had a single-bit error. */
        uint64_t ctl1_dbe              : 1;  /**< [  5:  5](R/W1C/H) TIM CTL1 memory had a double-bit error. */
        uint64_t ctl1_sbe              : 1;  /**< [  4:  4](R/W1C/H) TIM CTL1 memory had a single-bit error. */
        uint64_t ctl2_dbe              : 1;  /**< [  3:  3](R/W1C/H) TIM CTL2 memory had a double-bit error. */
        uint64_t ctl2_sbe              : 1;  /**< [  2:  2](R/W1C/H) TIM CTL2 memory had a single-bit error. */
        uint64_t base_dbe              : 1;  /**< [  1:  1](R/W1C/H) TIM BASE memory had a double-bit error. */
        uint64_t base_sbe              : 1;  /**< [  0:  0](R/W1C/H) TIM BASE memory had a single-bit error. */
#else /* Word 0 - Little Endian */
        uint64_t base_sbe              : 1;  /**< [  0:  0](R/W1C/H) TIM BASE memory had a single-bit error. */
        uint64_t base_dbe              : 1;  /**< [  1:  1](R/W1C/H) TIM BASE memory had a double-bit error. */
        uint64_t ctl2_sbe              : 1;  /**< [  2:  2](R/W1C/H) TIM CTL2 memory had a single-bit error. */
        uint64_t ctl2_dbe              : 1;  /**< [  3:  3](R/W1C/H) TIM CTL2 memory had a double-bit error. */
        uint64_t ctl1_sbe              : 1;  /**< [  4:  4](R/W1C/H) TIM CTL1 memory had a single-bit error. */
        uint64_t ctl1_dbe              : 1;  /**< [  5:  5](R/W1C/H) TIM CTL1 memory had a double-bit error. */
        uint64_t ctl0_sbe              : 1;  /**< [  6:  6](R/W1C/H) TIM CTL0 memory had a single-bit error. */
        uint64_t ctl0_dbe              : 1;  /**< [  7:  7](R/W1C/H) TIM CTL0 memory had a double-bit error. */
        uint64_t msix_vmem_sbe         : 1;  /**< [  8:  8](R/W1C/H) MSIX VMEM memory had a single-bit error. */
        uint64_t msix_vmem_dbe         : 1;  /**< [  9:  9](R/W1C/H) MSIX VMEM memory had a double-bit error. */
        uint64_t msix_pmem_sbe         : 1;  /**< [ 10: 10](R/W1C/H) MSIX PMEM memory had a single-bit error. */
        uint64_t msix_pmem_dbe         : 1;  /**< [ 11: 11](R/W1C/H) MSIX PMEM memory had a double-bit error. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_eccerr_int_s cn; */
};
typedef union cavm_tim_eccerr_int cavm_tim_eccerr_int_t;

#define CAVM_TIM_ECCERR_INT CAVM_TIM_ECCERR_INT_FUNC()
static inline uint64_t CAVM_TIM_ECCERR_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_ECCERR_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000060ll;
    __cavm_csr_fatal("TIM_ECCERR_INT", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_ECCERR_INT cavm_tim_eccerr_int_t
#define bustype_CAVM_TIM_ECCERR_INT CSR_TYPE_NCB
#define basename_CAVM_TIM_ECCERR_INT "TIM_ECCERR_INT"
#define device_bar_CAVM_TIM_ECCERR_INT 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_ECCERR_INT 0
#define arguments_CAVM_TIM_ECCERR_INT -1,-1,-1,-1

/**
 * Register (NCB) tim_eccerr_int_w1s
 *
 * TIM ECC Error Interrupt Set Register
 * This register sets interrupt bits.
 */
union cavm_tim_eccerr_int_w1s
{
    uint64_t u;
    struct cavm_tim_eccerr_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t msix_pmem_dbe         : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets TIM_ECCERR_INT[MSIX_PMEM_DBE]. */
        uint64_t msix_pmem_sbe         : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets TIM_ECCERR_INT[MSIX_PMEM_SBE]. */
        uint64_t msix_vmem_dbe         : 1;  /**< [  9:  9](R/W1S/H) Reads or sets TIM_ECCERR_INT[MSIX_VMEM_DBE]. */
        uint64_t msix_vmem_sbe         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets TIM_ECCERR_INT[MSIX_VMEM_SBE]. */
        uint64_t ctl0_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL0_DBE]. */
        uint64_t ctl0_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL0_SBE]. */
        uint64_t ctl1_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL1_DBE]. */
        uint64_t ctl1_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL1_SBE]. */
        uint64_t ctl2_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL2_DBE]. */
        uint64_t ctl2_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL2_SBE]. */
        uint64_t base_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets TIM_ECCERR_INT[BASE_DBE]. */
        uint64_t base_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets TIM_ECCERR_INT[BASE_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t base_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets TIM_ECCERR_INT[BASE_SBE]. */
        uint64_t base_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets TIM_ECCERR_INT[BASE_DBE]. */
        uint64_t ctl2_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL2_SBE]. */
        uint64_t ctl2_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL2_DBE]. */
        uint64_t ctl1_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL1_SBE]. */
        uint64_t ctl1_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL1_DBE]. */
        uint64_t ctl0_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL0_SBE]. */
        uint64_t ctl0_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets TIM_ECCERR_INT[CTL0_DBE]. */
        uint64_t msix_vmem_sbe         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets TIM_ECCERR_INT[MSIX_VMEM_SBE]. */
        uint64_t msix_vmem_dbe         : 1;  /**< [  9:  9](R/W1S/H) Reads or sets TIM_ECCERR_INT[MSIX_VMEM_DBE]. */
        uint64_t msix_pmem_sbe         : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets TIM_ECCERR_INT[MSIX_PMEM_SBE]. */
        uint64_t msix_pmem_dbe         : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets TIM_ECCERR_INT[MSIX_PMEM_DBE]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_eccerr_int_w1s_s cn; */
};
typedef union cavm_tim_eccerr_int_w1s cavm_tim_eccerr_int_w1s_t;

#define CAVM_TIM_ECCERR_INT_W1S CAVM_TIM_ECCERR_INT_W1S_FUNC()
static inline uint64_t CAVM_TIM_ECCERR_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_ECCERR_INT_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000068ll;
    __cavm_csr_fatal("TIM_ECCERR_INT_W1S", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_ECCERR_INT_W1S cavm_tim_eccerr_int_w1s_t
#define bustype_CAVM_TIM_ECCERR_INT_W1S CSR_TYPE_NCB
#define basename_CAVM_TIM_ECCERR_INT_W1S "TIM_ECCERR_INT_W1S"
#define device_bar_CAVM_TIM_ECCERR_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_ECCERR_INT_W1S 0
#define arguments_CAVM_TIM_ECCERR_INT_W1S -1,-1,-1,-1

/**
 * Register (NCB) tim_eco
 *
 * INTERNAL: TIM ECO Register
 */
union cavm_tim_eco
{
    uint64_t u;
    struct cavm_tim_eco_s
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
    /* struct cavm_tim_eco_s cn; */
};
typedef union cavm_tim_eco cavm_tim_eco_t;

#define CAVM_TIM_ECO CAVM_TIM_ECO_FUNC()
static inline uint64_t CAVM_TIM_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000140ll;
    __cavm_csr_fatal("TIM_ECO", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_ECO cavm_tim_eco_t
#define bustype_CAVM_TIM_ECO CSR_TYPE_NCB
#define basename_CAVM_TIM_ECO "TIM_ECO"
#define device_bar_CAVM_TIM_ECO 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_ECO 0
#define arguments_CAVM_TIM_ECO -1,-1,-1,-1

/**
 * Register (NCB) tim_eng#_active
 *
 * TIM Engine Active Registers
 */
union cavm_tim_engx_active
{
    uint64_t u;
    struct cavm_tim_engx_active_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t act                   : 1;  /**< [  8:  8](RO/H) Engine active. For diagnostic use. */
        uint64_t reserved_6_7          : 2;
        uint64_t ring_id               : 6;  /**< [  5:  0](RO/H) Current ring ID. For diagnostic use. */
#else /* Word 0 - Little Endian */
        uint64_t ring_id               : 6;  /**< [  5:  0](RO/H) Current ring ID. For diagnostic use. */
        uint64_t reserved_6_7          : 2;
        uint64_t act                   : 1;  /**< [  8:  8](RO/H) Engine active. For diagnostic use. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_engx_active_s cn; */
};
typedef union cavm_tim_engx_active cavm_tim_engx_active_t;

static inline uint64_t CAVM_TIM_ENGX_ACTIVE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_ENGX_ACTIVE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x858000001000ll + 8ll * ((a) & 0x3);
    __cavm_csr_fatal("TIM_ENGX_ACTIVE", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_ENGX_ACTIVE(a) cavm_tim_engx_active_t
#define bustype_CAVM_TIM_ENGX_ACTIVE(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_ENGX_ACTIVE(a) "TIM_ENGX_ACTIVE"
#define device_bar_CAVM_TIM_ENGX_ACTIVE(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_ENGX_ACTIVE(a) (a)
#define arguments_CAVM_TIM_ENGX_ACTIVE(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_fr_rn_cycles
 *
 * TIM Free Running Cycle Count Register
 */
union cavm_tim_fr_rn_cycles
{
    uint64_t u;
    struct cavm_tim_fr_rn_cycles_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Count of system coprocessor-clock cycles. This register is only writable when
                                                                 TIM_REG_FLAGS[ENA_TIM] = 0. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Count of system coprocessor-clock cycles. This register is only writable when
                                                                 TIM_REG_FLAGS[ENA_TIM] = 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_fr_rn_cycles_s cn; */
};
typedef union cavm_tim_fr_rn_cycles cavm_tim_fr_rn_cycles_t;

#define CAVM_TIM_FR_RN_CYCLES CAVM_TIM_FR_RN_CYCLES_FUNC()
static inline uint64_t CAVM_TIM_FR_RN_CYCLES_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_FR_RN_CYCLES_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8580000000c0ll;
    __cavm_csr_fatal("TIM_FR_RN_CYCLES", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_FR_RN_CYCLES cavm_tim_fr_rn_cycles_t
#define bustype_CAVM_TIM_FR_RN_CYCLES CSR_TYPE_NCB
#define basename_CAVM_TIM_FR_RN_CYCLES "TIM_FR_RN_CYCLES"
#define device_bar_CAVM_TIM_FR_RN_CYCLES 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_FR_RN_CYCLES 0
#define arguments_CAVM_TIM_FR_RN_CYCLES -1,-1,-1,-1

/**
 * Register (NCB) tim_fr_rn_gpios
 *
 * TIM Free Running GPIO Count Register
 */
union cavm_tim_fr_rn_gpios
{
    uint64_t u;
    struct cavm_tim_fr_rn_gpios_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Count of GPIO cycles. This register is only writable when TIM_REG_FLAGS[ENA_TIM] = 0. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Count of GPIO cycles. This register is only writable when TIM_REG_FLAGS[ENA_TIM] = 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_fr_rn_gpios_s cn; */
};
typedef union cavm_tim_fr_rn_gpios cavm_tim_fr_rn_gpios_t;

#define CAVM_TIM_FR_RN_GPIOS CAVM_TIM_FR_RN_GPIOS_FUNC()
static inline uint64_t CAVM_TIM_FR_RN_GPIOS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_FR_RN_GPIOS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8580000000c8ll;
    __cavm_csr_fatal("TIM_FR_RN_GPIOS", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_FR_RN_GPIOS cavm_tim_fr_rn_gpios_t
#define bustype_CAVM_TIM_FR_RN_GPIOS CSR_TYPE_NCB
#define basename_CAVM_TIM_FR_RN_GPIOS "TIM_FR_RN_GPIOS"
#define device_bar_CAVM_TIM_FR_RN_GPIOS 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_FR_RN_GPIOS 0
#define arguments_CAVM_TIM_FR_RN_GPIOS -1,-1,-1,-1

/**
 * Register (NCB) tim_fr_rn_gti
 *
 * TIM Free Running System Clock Count Register
 */
union cavm_tim_fr_rn_gti
{
    uint64_t u;
    struct cavm_tim_fr_rn_gti_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Count of GTI system timer cycles. This register is only writable when TIM_REG_FLAGS[ENA_TIM] = 0. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Count of GTI system timer cycles. This register is only writable when TIM_REG_FLAGS[ENA_TIM] = 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_fr_rn_gti_s cn; */
};
typedef union cavm_tim_fr_rn_gti cavm_tim_fr_rn_gti_t;

#define CAVM_TIM_FR_RN_GTI CAVM_TIM_FR_RN_GTI_FUNC()
static inline uint64_t CAVM_TIM_FR_RN_GTI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_FR_RN_GTI_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8580000000d0ll;
    __cavm_csr_fatal("TIM_FR_RN_GTI", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_FR_RN_GTI cavm_tim_fr_rn_gti_t
#define bustype_CAVM_TIM_FR_RN_GTI CSR_TYPE_NCB
#define basename_CAVM_TIM_FR_RN_GTI "TIM_FR_RN_GTI"
#define device_bar_CAVM_TIM_FR_RN_GTI 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_FR_RN_GTI 0
#define arguments_CAVM_TIM_FR_RN_GTI -1,-1,-1,-1

/**
 * Register (NCB) tim_fr_rn_ptp
 *
 * TIM Free Running PTP Count Register
 */
union cavm_tim_fr_rn_ptp
{
    uint64_t u;
    struct cavm_tim_fr_rn_ptp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Count of PTP cycles. This register is only writable when TIM_REG_FLAGS[CTL_TIM] = 0. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Count of PTP cycles. This register is only writable when TIM_REG_FLAGS[CTL_TIM] = 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_fr_rn_ptp_s cn; */
};
typedef union cavm_tim_fr_rn_ptp cavm_tim_fr_rn_ptp_t;

#define CAVM_TIM_FR_RN_PTP CAVM_TIM_FR_RN_PTP_FUNC()
static inline uint64_t CAVM_TIM_FR_RN_PTP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_FR_RN_PTP_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8580000000d8ll;
    __cavm_csr_fatal("TIM_FR_RN_PTP", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_FR_RN_PTP cavm_tim_fr_rn_ptp_t
#define bustype_CAVM_TIM_FR_RN_PTP CSR_TYPE_NCB
#define basename_CAVM_TIM_FR_RN_PTP "TIM_FR_RN_PTP"
#define device_bar_CAVM_TIM_FR_RN_PTP 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_FR_RN_PTP 0
#define arguments_CAVM_TIM_FR_RN_PTP -1,-1,-1,-1

/**
 * Register (NCB) tim_nxt_min_cycles_expire
 *
 * INTERNAL: TIM Next Minimum Cycles Expiration Time Register
 */
union cavm_tim_nxt_min_cycles_expire
{
    uint64_t u;
    struct cavm_tim_nxt_min_cycles_expire_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t min_exp_time          : 33; /**< [ 32:  0](RO/H) Indicates the value TIM_FR_RN_CYCLES must reach before the next possible
                                                                 servicing of rings/buckets. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t min_exp_time          : 33; /**< [ 32:  0](RO/H) Indicates the value TIM_FR_RN_CYCLES must reach before the next possible
                                                                 servicing of rings/buckets. For diagnostic use only. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_nxt_min_cycles_expire_s cn; */
};
typedef union cavm_tim_nxt_min_cycles_expire cavm_tim_nxt_min_cycles_expire_t;

#define CAVM_TIM_NXT_MIN_CYCLES_EXPIRE CAVM_TIM_NXT_MIN_CYCLES_EXPIRE_FUNC()
static inline uint64_t CAVM_TIM_NXT_MIN_CYCLES_EXPIRE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_NXT_MIN_CYCLES_EXPIRE_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000001100ll;
    __cavm_csr_fatal("TIM_NXT_MIN_CYCLES_EXPIRE", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_NXT_MIN_CYCLES_EXPIRE cavm_tim_nxt_min_cycles_expire_t
#define bustype_CAVM_TIM_NXT_MIN_CYCLES_EXPIRE CSR_TYPE_NCB
#define basename_CAVM_TIM_NXT_MIN_CYCLES_EXPIRE "TIM_NXT_MIN_CYCLES_EXPIRE"
#define device_bar_CAVM_TIM_NXT_MIN_CYCLES_EXPIRE 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_NXT_MIN_CYCLES_EXPIRE 0
#define arguments_CAVM_TIM_NXT_MIN_CYCLES_EXPIRE -1,-1,-1,-1

/**
 * Register (NCB) tim_nxt_min_gpios_expire
 *
 * INTERNAL: TIM Next Minimum GPIOS Expiration Time Registers
 */
union cavm_tim_nxt_min_gpios_expire
{
    uint64_t u;
    struct cavm_tim_nxt_min_gpios_expire_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t min_exp_time          : 33; /**< [ 32:  0](RO/H) Indicates the value TIM_FR_RN_GPIOS must reach before the next possible
                                                                 servicing of rings/buckets. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t min_exp_time          : 33; /**< [ 32:  0](RO/H) Indicates the value TIM_FR_RN_GPIOS must reach before the next possible
                                                                 servicing of rings/buckets. For diagnostic use only. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_nxt_min_gpios_expire_s cn; */
};
typedef union cavm_tim_nxt_min_gpios_expire cavm_tim_nxt_min_gpios_expire_t;

#define CAVM_TIM_NXT_MIN_GPIOS_EXPIRE CAVM_TIM_NXT_MIN_GPIOS_EXPIRE_FUNC()
static inline uint64_t CAVM_TIM_NXT_MIN_GPIOS_EXPIRE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_NXT_MIN_GPIOS_EXPIRE_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000001108ll;
    __cavm_csr_fatal("TIM_NXT_MIN_GPIOS_EXPIRE", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_NXT_MIN_GPIOS_EXPIRE cavm_tim_nxt_min_gpios_expire_t
#define bustype_CAVM_TIM_NXT_MIN_GPIOS_EXPIRE CSR_TYPE_NCB
#define basename_CAVM_TIM_NXT_MIN_GPIOS_EXPIRE "TIM_NXT_MIN_GPIOS_EXPIRE"
#define device_bar_CAVM_TIM_NXT_MIN_GPIOS_EXPIRE 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_NXT_MIN_GPIOS_EXPIRE 0
#define arguments_CAVM_TIM_NXT_MIN_GPIOS_EXPIRE -1,-1,-1,-1

/**
 * Register (NCB) tim_nxt_min_gti_expire
 *
 * INTERNAL: TIM Next Minimum GTI Expire Time Registers
 */
union cavm_tim_nxt_min_gti_expire
{
    uint64_t u;
    struct cavm_tim_nxt_min_gti_expire_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t min_exp_time          : 33; /**< [ 32:  0](RO/H) This field indicates the value TIM_FR_RN_GTI must reach
                                                                 before the next possible servicing of rings/buckets.
                                                                 For diagnostic use. */
#else /* Word 0 - Little Endian */
        uint64_t min_exp_time          : 33; /**< [ 32:  0](RO/H) This field indicates the value TIM_FR_RN_GTI must reach
                                                                 before the next possible servicing of rings/buckets.
                                                                 For diagnostic use. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_nxt_min_gti_expire_s cn; */
};
typedef union cavm_tim_nxt_min_gti_expire cavm_tim_nxt_min_gti_expire_t;

#define CAVM_TIM_NXT_MIN_GTI_EXPIRE CAVM_TIM_NXT_MIN_GTI_EXPIRE_FUNC()
static inline uint64_t CAVM_TIM_NXT_MIN_GTI_EXPIRE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_NXT_MIN_GTI_EXPIRE_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000001110ll;
    __cavm_csr_fatal("TIM_NXT_MIN_GTI_EXPIRE", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_NXT_MIN_GTI_EXPIRE cavm_tim_nxt_min_gti_expire_t
#define bustype_CAVM_TIM_NXT_MIN_GTI_EXPIRE CSR_TYPE_NCB
#define basename_CAVM_TIM_NXT_MIN_GTI_EXPIRE "TIM_NXT_MIN_GTI_EXPIRE"
#define device_bar_CAVM_TIM_NXT_MIN_GTI_EXPIRE 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_NXT_MIN_GTI_EXPIRE 0
#define arguments_CAVM_TIM_NXT_MIN_GTI_EXPIRE -1,-1,-1,-1

/**
 * Register (NCB) tim_nxt_min_ptp_expire
 *
 * INTERNAL: TIM Next Minimum PTP Expire Time Registers
 */
union cavm_tim_nxt_min_ptp_expire
{
    uint64_t u;
    struct cavm_tim_nxt_min_ptp_expire_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t min_exp_time          : 33; /**< [ 32:  0](RO/H) This field indicates the value TIM_FR_RN_PTP must reach
                                                                 before the next possible servicing of rings/buckets.
                                                                 For diagnostic use. */
#else /* Word 0 - Little Endian */
        uint64_t min_exp_time          : 33; /**< [ 32:  0](RO/H) This field indicates the value TIM_FR_RN_PTP must reach
                                                                 before the next possible servicing of rings/buckets.
                                                                 For diagnostic use. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_nxt_min_ptp_expire_s cn; */
};
typedef union cavm_tim_nxt_min_ptp_expire cavm_tim_nxt_min_ptp_expire_t;

#define CAVM_TIM_NXT_MIN_PTP_EXPIRE CAVM_TIM_NXT_MIN_PTP_EXPIRE_FUNC()
static inline uint64_t CAVM_TIM_NXT_MIN_PTP_EXPIRE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_NXT_MIN_PTP_EXPIRE_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000001118ll;
    __cavm_csr_fatal("TIM_NXT_MIN_PTP_EXPIRE", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_NXT_MIN_PTP_EXPIRE cavm_tim_nxt_min_ptp_expire_t
#define bustype_CAVM_TIM_NXT_MIN_PTP_EXPIRE CSR_TYPE_NCB
#define basename_CAVM_TIM_NXT_MIN_PTP_EXPIRE "TIM_NXT_MIN_PTP_EXPIRE"
#define device_bar_CAVM_TIM_NXT_MIN_PTP_EXPIRE 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_NXT_MIN_PTP_EXPIRE 0
#define arguments_CAVM_TIM_NXT_MIN_PTP_EXPIRE -1,-1,-1,-1

/**
 * Register (NCB) tim_pf_msix_pba#
 *
 * TIM PF MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the TIM_PF_INT_VEC_E
 * enumeration.
 */
union cavm_tim_pf_msix_pbax
{
    uint64_t u;
    struct cavm_tim_pf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated TIM_PF_MSIX_VEC()_CTL, enumerated by
                                                                 TIM_PF_INT_VEC_E. Bits that have no associated TIM_PF_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated TIM_PF_MSIX_VEC()_CTL, enumerated by
                                                                 TIM_PF_INT_VEC_E. Bits that have no associated TIM_PF_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_pf_msix_pbax_s cn; */
};
typedef union cavm_tim_pf_msix_pbax cavm_tim_pf_msix_pbax_t;

static inline uint64_t CAVM_TIM_PF_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_PF_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x858000ff0000ll + 8ll * ((a) & 0x0);
    __cavm_csr_fatal("TIM_PF_MSIX_PBAX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_PF_MSIX_PBAX(a) cavm_tim_pf_msix_pbax_t
#define bustype_CAVM_TIM_PF_MSIX_PBAX(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_PF_MSIX_PBAX(a) "TIM_PF_MSIX_PBAX"
#define device_bar_CAVM_TIM_PF_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_TIM_PF_MSIX_PBAX(a) (a)
#define arguments_CAVM_TIM_PF_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_pf_msix_vec#_addr
 *
 * TIM PF MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the TIM_PF_INT_VEC_E enumeration.
 */
union cavm_tim_pf_msix_vecx_addr
{
    uint64_t u;
    struct cavm_tim_pf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's TIM_PF_MSIX_VEC()_ADDR, TIM_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of TIM_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_TIM_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's TIM_PF_MSIX_VEC()_ADDR, TIM_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of TIM_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_TIM_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_pf_msix_vecx_addr_s cn; */
};
typedef union cavm_tim_pf_msix_vecx_addr cavm_tim_pf_msix_vecx_addr_t;

static inline uint64_t CAVM_TIM_PF_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_PF_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x858000f00000ll + 0x10ll * ((a) & 0x1);
    __cavm_csr_fatal("TIM_PF_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_PF_MSIX_VECX_ADDR(a) cavm_tim_pf_msix_vecx_addr_t
#define bustype_CAVM_TIM_PF_MSIX_VECX_ADDR(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_PF_MSIX_VECX_ADDR(a) "TIM_PF_MSIX_VECX_ADDR"
#define device_bar_CAVM_TIM_PF_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_TIM_PF_MSIX_VECX_ADDR(a) (a)
#define arguments_CAVM_TIM_PF_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_pf_msix_vec#_ctl
 *
 * TIM PF MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the TIM_PF_INT_VEC_E enumeration.
 */
union cavm_tim_pf_msix_vecx_ctl
{
    uint64_t u;
    struct cavm_tim_pf_msix_vecx_ctl_s
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
    /* struct cavm_tim_pf_msix_vecx_ctl_s cn; */
};
typedef union cavm_tim_pf_msix_vecx_ctl cavm_tim_pf_msix_vecx_ctl_t;

static inline uint64_t CAVM_TIM_PF_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_PF_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x858000f00008ll + 0x10ll * ((a) & 0x1);
    __cavm_csr_fatal("TIM_PF_MSIX_VECX_CTL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_PF_MSIX_VECX_CTL(a) cavm_tim_pf_msix_vecx_ctl_t
#define bustype_CAVM_TIM_PF_MSIX_VECX_CTL(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_PF_MSIX_VECX_CTL(a) "TIM_PF_MSIX_VECX_CTL"
#define device_bar_CAVM_TIM_PF_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_TIM_PF_MSIX_VECX_CTL(a) (a)
#define arguments_CAVM_TIM_PF_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_reg_flags
 *
 * TIM Flags Register
 * This register provides flags for TIM.
 */
union cavm_tim_reg_flags
{
    uint64_t u;
    struct cavm_tim_reg_flags_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t gpio_edge             : 2;  /**< [  6:  5](R/W) Edge used for GPIO timing.
                                                                 0x0 = no edges and the timer tick is not generated.
                                                                 0x1 = TIM counts low to high transitions.
                                                                 0x2 = TIM counts high to low transitions.
                                                                 0x3 = TIM counts both low to high and high to low transitions. */
        uint64_t reserved_3_4          : 2;
        uint64_t reset                 : 1;  /**< [  2:  2](WO/H) Reset. One-shot pulse for free-running timers TIM_FR_RN_<CLOCK>. */
        uint64_t reserved_1            : 1;
        uint64_t ena_tim               : 1;  /**< [  0:  0](R/W) When set, TIM is in normal operation. When clear, time is effectively stopped for all
                                                                 rings in TIM.

                                                                 TIM has a counter (see TIM_FR_RN_CYCLES) that causes a periodic tick. This
                                                                 counter is shared by all rings. Each Timer tick causes the hardware to decrement
                                                                 the time count for all enabled rings.

                                                                 When [ENA_TIM] = 0, the hardware stops the shared periodic counter,
                                                                 TIM_FR_RN_CYCLES, so there are no more ticks, and there are no more new bucket
                                                                 traversals.

                                                                 If [ENA_TIM] transitions 1->0, TIM longer creates new bucket traversals, but
                                                                 does traverse any rings that previously expired and are pending hardware
                                                                 traversal. */
#else /* Word 0 - Little Endian */
        uint64_t ena_tim               : 1;  /**< [  0:  0](R/W) When set, TIM is in normal operation. When clear, time is effectively stopped for all
                                                                 rings in TIM.

                                                                 TIM has a counter (see TIM_FR_RN_CYCLES) that causes a periodic tick. This
                                                                 counter is shared by all rings. Each Timer tick causes the hardware to decrement
                                                                 the time count for all enabled rings.

                                                                 When [ENA_TIM] = 0, the hardware stops the shared periodic counter,
                                                                 TIM_FR_RN_CYCLES, so there are no more ticks, and there are no more new bucket
                                                                 traversals.

                                                                 If [ENA_TIM] transitions 1->0, TIM longer creates new bucket traversals, but
                                                                 does traverse any rings that previously expired and are pending hardware
                                                                 traversal. */
        uint64_t reserved_1            : 1;
        uint64_t reset                 : 1;  /**< [  2:  2](WO/H) Reset. One-shot pulse for free-running timers TIM_FR_RN_<CLOCK>. */
        uint64_t reserved_3_4          : 2;
        uint64_t gpio_edge             : 2;  /**< [  6:  5](R/W) Edge used for GPIO timing.
                                                                 0x0 = no edges and the timer tick is not generated.
                                                                 0x1 = TIM counts low to high transitions.
                                                                 0x2 = TIM counts high to low transitions.
                                                                 0x3 = TIM counts both low to high and high to low transitions. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_reg_flags_s cn; */
};
typedef union cavm_tim_reg_flags cavm_tim_reg_flags_t;

#define CAVM_TIM_REG_FLAGS CAVM_TIM_REG_FLAGS_FUNC()
static inline uint64_t CAVM_TIM_REG_FLAGS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_REG_FLAGS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x858000000000ll;
    __cavm_csr_fatal("TIM_REG_FLAGS", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_REG_FLAGS cavm_tim_reg_flags_t
#define bustype_CAVM_TIM_REG_FLAGS CSR_TYPE_NCB
#define basename_CAVM_TIM_REG_FLAGS "TIM_REG_FLAGS"
#define device_bar_CAVM_TIM_REG_FLAGS 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_REG_FLAGS 0
#define arguments_CAVM_TIM_REG_FLAGS -1,-1,-1,-1

/**
 * Register (NCB) tim_ring#_ctl0
 *
 * TIM Ring Control 0 Registers
 */
union cavm_tim_ringx_ctl0
{
    uint64_t u;
    struct cavm_tim_ringx_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t expire_offset         : 32; /**< [ 63: 32](R/W/H) Time at which the next bucket will be serviced, or offset. See also TIM_VRING()_REL
                                                                 for the position relative to current time.

                                                                 If TIM_RING()_CTL1[ENA] = 0, then contains an offset. When ENA transitions from a
                                                                 zero to a one this offset will be added to the current time and loaded back into
                                                                 [EXPIRE_OFFSET]. Thus the offset sets the delta time between ENA transitioning to one and
                                                                 the very first time the ring will be serviced. Software should program different offsets
                                                                 on each ring to reduce congestion to prevent many rings from otherwise expiring
                                                                 concurrently.

                                                                 If TIM_RING()_CTL1[ENA] = 1, then contains the time the next bucket will be serviced.

                                                                 When [EXPIRE_OFFSET] reaches the current time (TIM_FR_RN_CYCLES or TIM_FR_RN_GPIOS),
                                                                 [EXPIRE_OFFSET] is set to the next expiration time (current time plus
                                                                 TIM_RING()_CTL0[INTERVAL]).

                                                                 [EXPIRE_OFFSET] is unpredictable after TIM_RING()_CTL1[CLK_SRC] changes or
                                                                 TIM_RING()_CTL1[ENA] transitions from 1 to 0, and must be reprogrammed before
                                                                 (re-) setting TIM_RING()_CTL1[ENA]. */
        uint64_t interval              : 32; /**< [ 31:  0](R/W) Timer interval, measured in cycles, GTI or PTP clocks, or GPIO transitions.
                                                                 Minimum value is 256 for GPIO rings, 300 for GTI and PTP rings, and 512 for
                                                                 SCLK rings. Minimum time which this interval is recommended to represent is
                                                                 1 usec, or 1 usec for every 64 entries in the bucket, whichever is greater. */
#else /* Word 0 - Little Endian */
        uint64_t interval              : 32; /**< [ 31:  0](R/W) Timer interval, measured in cycles, GTI or PTP clocks, or GPIO transitions.
                                                                 Minimum value is 256 for GPIO rings, 300 for GTI and PTP rings, and 512 for
                                                                 SCLK rings. Minimum time which this interval is recommended to represent is
                                                                 1 usec, or 1 usec for every 64 entries in the bucket, whichever is greater. */
        uint64_t expire_offset         : 32; /**< [ 63: 32](R/W/H) Time at which the next bucket will be serviced, or offset. See also TIM_VRING()_REL
                                                                 for the position relative to current time.

                                                                 If TIM_RING()_CTL1[ENA] = 0, then contains an offset. When ENA transitions from a
                                                                 zero to a one this offset will be added to the current time and loaded back into
                                                                 [EXPIRE_OFFSET]. Thus the offset sets the delta time between ENA transitioning to one and
                                                                 the very first time the ring will be serviced. Software should program different offsets
                                                                 on each ring to reduce congestion to prevent many rings from otherwise expiring
                                                                 concurrently.

                                                                 If TIM_RING()_CTL1[ENA] = 1, then contains the time the next bucket will be serviced.

                                                                 When [EXPIRE_OFFSET] reaches the current time (TIM_FR_RN_CYCLES or TIM_FR_RN_GPIOS),
                                                                 [EXPIRE_OFFSET] is set to the next expiration time (current time plus
                                                                 TIM_RING()_CTL0[INTERVAL]).

                                                                 [EXPIRE_OFFSET] is unpredictable after TIM_RING()_CTL1[CLK_SRC] changes or
                                                                 TIM_RING()_CTL1[ENA] transitions from 1 to 0, and must be reprogrammed before
                                                                 (re-) setting TIM_RING()_CTL1[ENA]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_ringx_ctl0_s cn; */
};
typedef union cavm_tim_ringx_ctl0 cavm_tim_ringx_ctl0_t;

static inline uint64_t CAVM_TIM_RINGX_CTL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_RINGX_CTL0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858000002000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_RINGX_CTL0", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_RINGX_CTL0(a) cavm_tim_ringx_ctl0_t
#define bustype_CAVM_TIM_RINGX_CTL0(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_RINGX_CTL0(a) "TIM_RINGX_CTL0"
#define device_bar_CAVM_TIM_RINGX_CTL0(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_RINGX_CTL0(a) (a)
#define arguments_CAVM_TIM_RINGX_CTL0(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_ring#_ctl1
 *
 * TIM Ring Control 1 Registers
 */
union cavm_tim_ringx_ctl1
{
    uint64_t u;
    struct cavm_tim_ringx_ctl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t be                    : 1;  /**< [ 54: 54](R/W) Ring big-endian. If set, TIM_MEM_BUCKET_S and other in-memory structures are big endian. */
        uint64_t clk_src               : 3;  /**< [ 53: 51](R/W) Source of ring's timer tick. Enumerated by TIM_CLK_SRCS_E. To change [CLK_SRC]:

                                                                 1. TIM_RING()_CTL1[ENA] is cleared.

                                                                 2. [CLK_SRC] is changed.

                                                                 3. TIM_RING()_CTL0[EXPIRE_OFFSET] is reprogrammed appropriately.

                                                                 4. TIM_RING()_CTL1[ENA] is set. */
        uint64_t rcf_busy              : 1;  /**< [ 50: 50](RO/H) Ring reconfiguration busy. When [ENA] is cleared, this bit will be set, if an
                                                                 engine is currently scheduled to, or is processing, a ring. It will remain set until
                                                                 hardware completes the idling of the ring. [ENA] must not be re-enabled until clear. */
        uint64_t reserved_49           : 1;
        uint64_t lock_en               : 1;  /**< [ 48: 48](R/W) Enables bucket locking mechanism between hardware and software.
                                                                   0 = Hardware will always service the bucket when it expires.
                                                                   1 = Hardware skips buckets when it can't get the bucket's lock. */
        uint64_t ena                   : 1;  /**< [ 47: 47](R/W/H) Ring timer enable. After a 1 to 0 transition on ENA, the hardware still
                                                                 completes a bucket traversal for the ring if it were pending or active
                                                                 prior to the transition. When clearing, software must delay until
                                                                 [RCF_BUSY] = 0 to ensure the completion of the traversal before reprogramming
                                                                 the ring. Hardware will clear this bit when any TIM_VF()_NRSPERR_INT[*] bit
                                                                 is set by hardware. */
        uint64_t reserved_46           : 1;
        uint64_t ena_prd               : 1;  /**< [ 45: 45](R/W) Enable periodic mode, which disables the memory write of zeros to
                                                                 TIM_MEM_BUCKET_S[NUM_ENTRIES] and TIM_MEM_BUCKET_S[CHUNK_REMAINDER] when a
                                                                 bucket is traversed. In periodic mode, [ENA_LDWB] must be cleared.
                                                                 Also, in periodic mode, [ENA_DFB] should be 1, and 0 otherwise. */
        uint64_t ena_ldwb              : 1;  /**< [ 44: 44](R/W) When set, enables the use of load and don't-write-back when reading timer entry cache lines. */
        uint64_t ena_dfb               : 1;  /**< [ 43: 43](R/W) Enable don't free buffer. When set, chunk buffer is not released by the TIM back to FPA. */
        uint64_t reserved_40_42        : 3;
        uint64_t bucket                : 20; /**< [ 39: 20](R/W/H) Current bucket. Should be set to 0x0 by software at enable time. Incremented once per
                                                                 bucket traversal. */
        uint64_t bsize                 : 20; /**< [ 19:  0](R/W) Number of buckets minus one. If [BSIZE] = 0, there is only one bucket in the ring. */
#else /* Word 0 - Little Endian */
        uint64_t bsize                 : 20; /**< [ 19:  0](R/W) Number of buckets minus one. If [BSIZE] = 0, there is only one bucket in the ring. */
        uint64_t bucket                : 20; /**< [ 39: 20](R/W/H) Current bucket. Should be set to 0x0 by software at enable time. Incremented once per
                                                                 bucket traversal. */
        uint64_t reserved_40_42        : 3;
        uint64_t ena_dfb               : 1;  /**< [ 43: 43](R/W) Enable don't free buffer. When set, chunk buffer is not released by the TIM back to FPA. */
        uint64_t ena_ldwb              : 1;  /**< [ 44: 44](R/W) When set, enables the use of load and don't-write-back when reading timer entry cache lines. */
        uint64_t ena_prd               : 1;  /**< [ 45: 45](R/W) Enable periodic mode, which disables the memory write of zeros to
                                                                 TIM_MEM_BUCKET_S[NUM_ENTRIES] and TIM_MEM_BUCKET_S[CHUNK_REMAINDER] when a
                                                                 bucket is traversed. In periodic mode, [ENA_LDWB] must be cleared.
                                                                 Also, in periodic mode, [ENA_DFB] should be 1, and 0 otherwise. */
        uint64_t reserved_46           : 1;
        uint64_t ena                   : 1;  /**< [ 47: 47](R/W/H) Ring timer enable. After a 1 to 0 transition on ENA, the hardware still
                                                                 completes a bucket traversal for the ring if it were pending or active
                                                                 prior to the transition. When clearing, software must delay until
                                                                 [RCF_BUSY] = 0 to ensure the completion of the traversal before reprogramming
                                                                 the ring. Hardware will clear this bit when any TIM_VF()_NRSPERR_INT[*] bit
                                                                 is set by hardware. */
        uint64_t lock_en               : 1;  /**< [ 48: 48](R/W) Enables bucket locking mechanism between hardware and software.
                                                                   0 = Hardware will always service the bucket when it expires.
                                                                   1 = Hardware skips buckets when it can't get the bucket's lock. */
        uint64_t reserved_49           : 1;
        uint64_t rcf_busy              : 1;  /**< [ 50: 50](RO/H) Ring reconfiguration busy. When [ENA] is cleared, this bit will be set, if an
                                                                 engine is currently scheduled to, or is processing, a ring. It will remain set until
                                                                 hardware completes the idling of the ring. [ENA] must not be re-enabled until clear. */
        uint64_t clk_src               : 3;  /**< [ 53: 51](R/W) Source of ring's timer tick. Enumerated by TIM_CLK_SRCS_E. To change [CLK_SRC]:

                                                                 1. TIM_RING()_CTL1[ENA] is cleared.

                                                                 2. [CLK_SRC] is changed.

                                                                 3. TIM_RING()_CTL0[EXPIRE_OFFSET] is reprogrammed appropriately.

                                                                 4. TIM_RING()_CTL1[ENA] is set. */
        uint64_t be                    : 1;  /**< [ 54: 54](R/W) Ring big-endian. If set, TIM_MEM_BUCKET_S and other in-memory structures are big endian. */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_ringx_ctl1_s cn; */
};
typedef union cavm_tim_ringx_ctl1 cavm_tim_ringx_ctl1_t;

static inline uint64_t CAVM_TIM_RINGX_CTL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_RINGX_CTL1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858000002400ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_RINGX_CTL1", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_RINGX_CTL1(a) cavm_tim_ringx_ctl1_t
#define bustype_CAVM_TIM_RINGX_CTL1(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_RINGX_CTL1(a) "TIM_RINGX_CTL1"
#define device_bar_CAVM_TIM_RINGX_CTL1(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_RINGX_CTL1(a) (a)
#define arguments_CAVM_TIM_RINGX_CTL1(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_ring#_ctl2
 *
 * TIM Ring Control 2 Registers
 */
union cavm_tim_ringx_ctl2
{
    uint64_t u;
    struct cavm_tim_ringx_ctl2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t csize                 : 13; /**< [ 52: 40](R/W) Number of sixteen-byte words per chunk. [CSIZE] mod(8) should be zero. */
        uint64_t reserved_0_39         : 40;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_39         : 40;
        uint64_t csize                 : 13; /**< [ 52: 40](R/W) Number of sixteen-byte words per chunk. [CSIZE] mod(8) should be zero. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_ringx_ctl2_s cn; */
};
typedef union cavm_tim_ringx_ctl2 cavm_tim_ringx_ctl2_t;

static inline uint64_t CAVM_TIM_RINGX_CTL2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_RINGX_CTL2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858000002800ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_RINGX_CTL2", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_RINGX_CTL2(a) cavm_tim_ringx_ctl2_t
#define bustype_CAVM_TIM_RINGX_CTL2(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_RINGX_CTL2(a) "TIM_RINGX_CTL2"
#define device_bar_CAVM_TIM_RINGX_CTL2(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_RINGX_CTL2(a) (a)
#define arguments_CAVM_TIM_RINGX_CTL2(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_ring#_gmctl
 *
 * TIM Ring Guest Machine Control Register
 */
union cavm_tim_ringx_gmctl
{
    uint64_t u;
    struct cavm_tim_ringx_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for all buffer free, or to SSO
                                                                 for all submit work operations initiated by this ring.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for all buffer free, or to SSO
                                                                 for all submit work operations initiated by this ring.
                                                                 Must be nonzero or FPA/SSO will drop requests; see FPA_PF_MAP() and SSO_PF_MAP(). */
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Low 8 bits of the SMMU stream identifier to use when issuing requests.

                                                                 Stream 0x0 corresponds to the PF, and VFs start at 0x1.

                                                                 Reset such that VF0/index 0 is 0x1, VF1/index 1 is 0x2, etc. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_ringx_gmctl_s cn; */
};
typedef union cavm_tim_ringx_gmctl cavm_tim_ringx_gmctl_t;

static inline uint64_t CAVM_TIM_RINGX_GMCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_RINGX_GMCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858000002a00ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_RINGX_GMCTL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_RINGX_GMCTL(a) cavm_tim_ringx_gmctl_t
#define bustype_CAVM_TIM_RINGX_GMCTL(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_RINGX_GMCTL(a) "TIM_RINGX_GMCTL"
#define device_bar_CAVM_TIM_RINGX_GMCTL(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_RINGX_GMCTL(a) (a)
#define arguments_CAVM_TIM_RINGX_GMCTL(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vf#_msix_pba#
 *
 * TIM VF MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the TIM_VF_INT_VEC_E
 * enumeration.
 */
union cavm_tim_vfx_msix_pbax
{
    uint64_t u;
    struct cavm_tim_vfx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated TIM_PF_MSIX_VEC()_CTL, enumerated by
                                                                 TIM_PF_INT_VEC_E. Bits that have no associated TIM_PF_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated TIM_PF_MSIX_VEC()_CTL, enumerated by
                                                                 TIM_PF_INT_VEC_E. Bits that have no associated TIM_PF_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vfx_msix_pbax_s cn; */
};
typedef union cavm_tim_vfx_msix_pbax cavm_tim_vfx_msix_pbax_t;

static inline uint64_t CAVM_TIM_VFX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VFX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b==0)))
        return 0x8580200f0000ll + 0x100000ll * ((a) & 0x3f) + 8ll * ((b) & 0x0);
    __cavm_csr_fatal("TIM_VFX_MSIX_PBAX", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VFX_MSIX_PBAX(a,b) cavm_tim_vfx_msix_pbax_t
#define bustype_CAVM_TIM_VFX_MSIX_PBAX(a,b) CSR_TYPE_NCB
#define basename_CAVM_TIM_VFX_MSIX_PBAX(a,b) "TIM_VFX_MSIX_PBAX"
#define device_bar_CAVM_TIM_VFX_MSIX_PBAX(a,b) 0x14 /* VF_BAR4 */
#define busnum_CAVM_TIM_VFX_MSIX_PBAX(a,b) (a)
#define arguments_CAVM_TIM_VFX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) tim_vf#_msix_vec#_addr
 *
 * TIM VF MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the TIM_PF_INT_VEC_E enumeration.
 */
union cavm_tim_vfx_msix_vecx_addr
{
    uint64_t u;
    struct cavm_tim_vfx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_TIM_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_TIM_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vfx_msix_vecx_addr_s cn; */
};
typedef union cavm_tim_vfx_msix_vecx_addr cavm_tim_vfx_msix_vecx_addr_t;

static inline uint64_t CAVM_TIM_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b==0)))
        return 0x858020000000ll + 0x100000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x0);
    __cavm_csr_fatal("TIM_VFX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VFX_MSIX_VECX_ADDR(a,b) cavm_tim_vfx_msix_vecx_addr_t
#define bustype_CAVM_TIM_VFX_MSIX_VECX_ADDR(a,b) CSR_TYPE_NCB
#define basename_CAVM_TIM_VFX_MSIX_VECX_ADDR(a,b) "TIM_VFX_MSIX_VECX_ADDR"
#define device_bar_CAVM_TIM_VFX_MSIX_VECX_ADDR(a,b) 0x14 /* VF_BAR4 */
#define busnum_CAVM_TIM_VFX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_CAVM_TIM_VFX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) tim_vf#_msix_vec#_ctl
 *
 * TIM VF MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the TIM_VF_INT_VEC_E enumeration.
 */
union cavm_tim_vfx_msix_vecx_ctl
{
    uint64_t u;
    struct cavm_tim_vfx_msix_vecx_ctl_s
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
    /* struct cavm_tim_vfx_msix_vecx_ctl_s cn; */
};
typedef union cavm_tim_vfx_msix_vecx_ctl cavm_tim_vfx_msix_vecx_ctl_t;

static inline uint64_t CAVM_TIM_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b==0)))
        return 0x858020000008ll + 0x100000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x0);
    __cavm_csr_fatal("TIM_VFX_MSIX_VECX_CTL", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VFX_MSIX_VECX_CTL(a,b) cavm_tim_vfx_msix_vecx_ctl_t
#define bustype_CAVM_TIM_VFX_MSIX_VECX_CTL(a,b) CSR_TYPE_NCB
#define basename_CAVM_TIM_VFX_MSIX_VECX_CTL(a,b) "TIM_VFX_MSIX_VECX_CTL"
#define device_bar_CAVM_TIM_VFX_MSIX_VECX_CTL(a,b) 0x14 /* VF_BAR4 */
#define busnum_CAVM_TIM_VFX_MSIX_VECX_CTL(a,b) (a)
#define arguments_CAVM_TIM_VFX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) tim_vf#_nrsperr_ena_w1c
 *
 * TIM NCB Response Error Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_tim_vfx_nrsperr_ena_w1c
{
    uint64_t u;
    struct cavm_tim_vfx_nrsperr_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t atomic_err            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for TIM_VF(0..63)_NRSPERR_INT[ATOMIC_ERR]. */
        uint64_t load_err              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for TIM_VF(0..63)_NRSPERR_INT[LOAD_ERR]. */
        uint64_t stdn_err              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for TIM_VF(0..63)_NRSPERR_INT[STDN_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t stdn_err              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for TIM_VF(0..63)_NRSPERR_INT[STDN_ERR]. */
        uint64_t load_err              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for TIM_VF(0..63)_NRSPERR_INT[LOAD_ERR]. */
        uint64_t atomic_err            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for TIM_VF(0..63)_NRSPERR_INT[ATOMIC_ERR]. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vfx_nrsperr_ena_w1c_s cn; */
};
typedef union cavm_tim_vfx_nrsperr_ena_w1c cavm_tim_vfx_nrsperr_ena_w1c_t;

static inline uint64_t CAVM_TIM_VFX_NRSPERR_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VFX_NRSPERR_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000010ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VFX_NRSPERR_ENA_W1C", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VFX_NRSPERR_ENA_W1C(a) cavm_tim_vfx_nrsperr_ena_w1c_t
#define bustype_CAVM_TIM_VFX_NRSPERR_ENA_W1C(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VFX_NRSPERR_ENA_W1C(a) "TIM_VFX_NRSPERR_ENA_W1C"
#define device_bar_CAVM_TIM_VFX_NRSPERR_ENA_W1C(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VFX_NRSPERR_ENA_W1C(a) (a)
#define arguments_CAVM_TIM_VFX_NRSPERR_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vf#_nrsperr_ena_w1s
 *
 * TIM NCB Response Error Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_tim_vfx_nrsperr_ena_w1s
{
    uint64_t u;
    struct cavm_tim_vfx_nrsperr_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t atomic_err            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for TIM_VF(0..63)_NRSPERR_INT[ATOMIC_ERR]. */
        uint64_t load_err              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for TIM_VF(0..63)_NRSPERR_INT[LOAD_ERR]. */
        uint64_t stdn_err              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for TIM_VF(0..63)_NRSPERR_INT[STDN_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t stdn_err              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for TIM_VF(0..63)_NRSPERR_INT[STDN_ERR]. */
        uint64_t load_err              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for TIM_VF(0..63)_NRSPERR_INT[LOAD_ERR]. */
        uint64_t atomic_err            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for TIM_VF(0..63)_NRSPERR_INT[ATOMIC_ERR]. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vfx_nrsperr_ena_w1s_s cn; */
};
typedef union cavm_tim_vfx_nrsperr_ena_w1s cavm_tim_vfx_nrsperr_ena_w1s_t;

static inline uint64_t CAVM_TIM_VFX_NRSPERR_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VFX_NRSPERR_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000018ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VFX_NRSPERR_ENA_W1S", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VFX_NRSPERR_ENA_W1S(a) cavm_tim_vfx_nrsperr_ena_w1s_t
#define bustype_CAVM_TIM_VFX_NRSPERR_ENA_W1S(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VFX_NRSPERR_ENA_W1S(a) "TIM_VFX_NRSPERR_ENA_W1S"
#define device_bar_CAVM_TIM_VFX_NRSPERR_ENA_W1S(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VFX_NRSPERR_ENA_W1S(a) (a)
#define arguments_CAVM_TIM_VFX_NRSPERR_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vf#_nrsperr_int
 *
 * TIM NCB Response Error Interrupt Register
 */
union cavm_tim_vfx_nrsperr_int
{
    uint64_t u;
    struct cavm_tim_vfx_nrsperr_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t atomic_err            : 1;  /**< [  2:  2](R/W1C/H) Atomic error flag. Each VF bit corresponds to rings [63:0] respectively.
                                                                 This register reflects any atomic set/clear errors received for specific
                                                                 ring NCB atomic (SET64/CLR64) operations. */
        uint64_t load_err              : 1;  /**< [  1:  1](R/W1C/H) Load error flag. Set when a load fault was detected, e.g. a SMMU page fault to a
                                                                 bad IOVA request by this ring. */
        uint64_t stdn_err              : 1;  /**< [  0:  0](R/W1C/H) Store error flag. Set when a store fault was detected, e.g. a SMMU page fault to
                                                                 a bad IOVA request by this ring. */
#else /* Word 0 - Little Endian */
        uint64_t stdn_err              : 1;  /**< [  0:  0](R/W1C/H) Store error flag. Set when a store fault was detected, e.g. a SMMU page fault to
                                                                 a bad IOVA request by this ring. */
        uint64_t load_err              : 1;  /**< [  1:  1](R/W1C/H) Load error flag. Set when a load fault was detected, e.g. a SMMU page fault to a
                                                                 bad IOVA request by this ring. */
        uint64_t atomic_err            : 1;  /**< [  2:  2](R/W1C/H) Atomic error flag. Each VF bit corresponds to rings [63:0] respectively.
                                                                 This register reflects any atomic set/clear errors received for specific
                                                                 ring NCB atomic (SET64/CLR64) operations. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vfx_nrsperr_int_s cn; */
};
typedef union cavm_tim_vfx_nrsperr_int cavm_tim_vfx_nrsperr_int_t;

static inline uint64_t CAVM_TIM_VFX_NRSPERR_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VFX_NRSPERR_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000000ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VFX_NRSPERR_INT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VFX_NRSPERR_INT(a) cavm_tim_vfx_nrsperr_int_t
#define bustype_CAVM_TIM_VFX_NRSPERR_INT(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VFX_NRSPERR_INT(a) "TIM_VFX_NRSPERR_INT"
#define device_bar_CAVM_TIM_VFX_NRSPERR_INT(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VFX_NRSPERR_INT(a) (a)
#define arguments_CAVM_TIM_VFX_NRSPERR_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vf#_nrsperr_int_w1s
 *
 * TIM NCB Response Error Interrupt Set Register
 * This register sets interrupt bits.
 */
union cavm_tim_vfx_nrsperr_int_w1s
{
    uint64_t u;
    struct cavm_tim_vfx_nrsperr_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t atomic_err            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets TIM_VF(0..63)_NRSPERR_INT[ATOMIC_ERR]. */
        uint64_t load_err              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets TIM_VF(0..63)_NRSPERR_INT[LOAD_ERR]. */
        uint64_t stdn_err              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets TIM_VF(0..63)_NRSPERR_INT[STDN_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t stdn_err              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets TIM_VF(0..63)_NRSPERR_INT[STDN_ERR]. */
        uint64_t load_err              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets TIM_VF(0..63)_NRSPERR_INT[LOAD_ERR]. */
        uint64_t atomic_err            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets TIM_VF(0..63)_NRSPERR_INT[ATOMIC_ERR]. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vfx_nrsperr_int_w1s_s cn; */
};
typedef union cavm_tim_vfx_nrsperr_int_w1s cavm_tim_vfx_nrsperr_int_w1s_t;

static inline uint64_t CAVM_TIM_VFX_NRSPERR_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VFX_NRSPERR_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000008ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VFX_NRSPERR_INT_W1S", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VFX_NRSPERR_INT_W1S(a) cavm_tim_vfx_nrsperr_int_w1s_t
#define bustype_CAVM_TIM_VFX_NRSPERR_INT_W1S(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VFX_NRSPERR_INT_W1S(a) "TIM_VFX_NRSPERR_INT_W1S"
#define device_bar_CAVM_TIM_VFX_NRSPERR_INT_W1S(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VFX_NRSPERR_INT_W1S(a) (a)
#define arguments_CAVM_TIM_VFX_NRSPERR_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_aura
 *
 * TIM Ring Aura Registers
 */
union cavm_tim_vringx_aura
{
    uint64_t u;
    struct cavm_tim_vringx_aura_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t aura                  : 16; /**< [ 15:  0](R/W) Guest-aura number used to free and return chunks to. Bits <15:12> must be zero.
                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and TIM_VRING()_GMCTL[GMID] as valid. */
#else /* Word 0 - Little Endian */
        uint64_t aura                  : 16; /**< [ 15:  0](R/W) Guest-aura number used to free and return chunks to. Bits <15:12> must be zero.
                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and TIM_VRING()_GMCTL[GMID] as valid. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_aura_s cn; */
};
typedef union cavm_tim_vringx_aura cavm_tim_vringx_aura_t;

static inline uint64_t CAVM_TIM_VRINGX_AURA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_AURA(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000108ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_AURA", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_AURA(a) cavm_tim_vringx_aura_t
#define bustype_CAVM_TIM_VRINGX_AURA(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_AURA(a) "TIM_VRINGX_AURA"
#define device_bar_CAVM_TIM_VRINGX_AURA(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_AURA(a) (a)
#define arguments_CAVM_TIM_VRINGX_AURA(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_base
 *
 * TIM Ring Base Registers
 */
union cavm_tim_vringx_base
{
    uint64_t u;
    struct cavm_tim_vringx_base_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t base                  : 44; /**< [ 48:  5](R/W) IOVA pointer to bucket 0. */
        uint64_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_4          : 5;
        uint64_t base                  : 44; /**< [ 48:  5](R/W) IOVA pointer to bucket 0. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_base_s cn; */
};
typedef union cavm_tim_vringx_base cavm_tim_vringx_base_t;

static inline uint64_t CAVM_TIM_VRINGX_BASE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_BASE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000100ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_BASE", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_BASE(a) cavm_tim_vringx_base_t
#define bustype_CAVM_TIM_VRINGX_BASE(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_BASE(a) "TIM_VRINGX_BASE"
#define device_bar_CAVM_TIM_VRINGX_BASE(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_BASE(a) (a)
#define arguments_CAVM_TIM_VRINGX_BASE(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_ctl0
 *
 * TIM Ring Control 0 Registers
 * This register is a read-only copy of TIM_RING()_CTL0.
 */
union cavm_tim_vringx_ctl0
{
    uint64_t u;
    struct cavm_tim_vringx_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t expire_offset         : 32; /**< [ 63: 32](RO/H) Read-only TIM_RING(0..63)_CTL0[EXPIRE_OFFSET]. */
        uint64_t interval              : 32; /**< [ 31:  0](RO) Read-only TIM_RING(0..63)_CTL0[INTERVAL]. */
#else /* Word 0 - Little Endian */
        uint64_t interval              : 32; /**< [ 31:  0](RO) Read-only TIM_RING(0..63)_CTL0[INTERVAL]. */
        uint64_t expire_offset         : 32; /**< [ 63: 32](RO/H) Read-only TIM_RING(0..63)_CTL0[EXPIRE_OFFSET]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_ctl0_s cn; */
};
typedef union cavm_tim_vringx_ctl0 cavm_tim_vringx_ctl0_t;

static inline uint64_t CAVM_TIM_VRINGX_CTL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_CTL0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000040ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_CTL0", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_CTL0(a) cavm_tim_vringx_ctl0_t
#define bustype_CAVM_TIM_VRINGX_CTL0(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_CTL0(a) "TIM_VRINGX_CTL0"
#define device_bar_CAVM_TIM_VRINGX_CTL0(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_CTL0(a) (a)
#define arguments_CAVM_TIM_VRINGX_CTL0(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_ctl1
 *
 * TIM Ring Control 1 Registers
 * This register is a read-only copy of TIM_RING()_CTL1.
 */
union cavm_tim_vringx_ctl1
{
    uint64_t u;
    struct cavm_tim_vringx_ctl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t be                    : 1;  /**< [ 54: 54](RO) Read-only TIM_RING(0..63)_CTL1[BE]. */
        uint64_t clk_src               : 3;  /**< [ 53: 51](RO) Read-only TIM_RING(0..63)_CTL1[CLK_SRC]. */
        uint64_t rcf_busy              : 1;  /**< [ 50: 50](RO/H) Read-only TIM_RING(0..63)_CTL1[RCF_BUSY]. */
        uint64_t reserved_49           : 1;
        uint64_t lock_en               : 1;  /**< [ 48: 48](RO) Read-only TIM_RING(0..63)_CTL1[LOCK_EN]. */
        uint64_t ena                   : 1;  /**< [ 47: 47](RO/H) Read-only TIM_RING(0..63)_CTL1[ENA]. */
        uint64_t reserved_46           : 1;
        uint64_t ena_prd               : 1;  /**< [ 45: 45](RO) Read-only TIM_RING(0..63)_CTL1[ENA_PRD]. */
        uint64_t ena_ldwb              : 1;  /**< [ 44: 44](RO) Read-only TIM_RING(0..63)_CTL1[ENA_LDWB]. */
        uint64_t ena_dfb               : 1;  /**< [ 43: 43](RO) Read-only TIM_RING(0..63)_CTL1[ENA_DFB]. */
        uint64_t reserved_40_42        : 3;
        uint64_t bucket                : 20; /**< [ 39: 20](RO/H) Read-only TIM_RING(0..63)_CTL1[BUCKET]. */
        uint64_t bsize                 : 20; /**< [ 19:  0](RO) Read-only TIM_RING(0..63)_CTL1[BSIZE]. */
#else /* Word 0 - Little Endian */
        uint64_t bsize                 : 20; /**< [ 19:  0](RO) Read-only TIM_RING(0..63)_CTL1[BSIZE]. */
        uint64_t bucket                : 20; /**< [ 39: 20](RO/H) Read-only TIM_RING(0..63)_CTL1[BUCKET]. */
        uint64_t reserved_40_42        : 3;
        uint64_t ena_dfb               : 1;  /**< [ 43: 43](RO) Read-only TIM_RING(0..63)_CTL1[ENA_DFB]. */
        uint64_t ena_ldwb              : 1;  /**< [ 44: 44](RO) Read-only TIM_RING(0..63)_CTL1[ENA_LDWB]. */
        uint64_t ena_prd               : 1;  /**< [ 45: 45](RO) Read-only TIM_RING(0..63)_CTL1[ENA_PRD]. */
        uint64_t reserved_46           : 1;
        uint64_t ena                   : 1;  /**< [ 47: 47](RO/H) Read-only TIM_RING(0..63)_CTL1[ENA]. */
        uint64_t lock_en               : 1;  /**< [ 48: 48](RO) Read-only TIM_RING(0..63)_CTL1[LOCK_EN]. */
        uint64_t reserved_49           : 1;
        uint64_t rcf_busy              : 1;  /**< [ 50: 50](RO/H) Read-only TIM_RING(0..63)_CTL1[RCF_BUSY]. */
        uint64_t clk_src               : 3;  /**< [ 53: 51](RO) Read-only TIM_RING(0..63)_CTL1[CLK_SRC]. */
        uint64_t be                    : 1;  /**< [ 54: 54](RO) Read-only TIM_RING(0..63)_CTL1[BE]. */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_ctl1_s cn; */
};
typedef union cavm_tim_vringx_ctl1 cavm_tim_vringx_ctl1_t;

static inline uint64_t CAVM_TIM_VRINGX_CTL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_CTL1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000050ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_CTL1", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_CTL1(a) cavm_tim_vringx_ctl1_t
#define bustype_CAVM_TIM_VRINGX_CTL1(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_CTL1(a) "TIM_VRINGX_CTL1"
#define device_bar_CAVM_TIM_VRINGX_CTL1(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_CTL1(a) (a)
#define arguments_CAVM_TIM_VRINGX_CTL1(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_ctl2
 *
 * TIM Ring Control 2 Registers
 * This register is a read-only copy of TIM_RING()_CTL2.
 */
union cavm_tim_vringx_ctl2
{
    uint64_t u;
    struct cavm_tim_vringx_ctl2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t csize                 : 13; /**< [ 52: 40](RO) Read-only TIM_RING(0..63)_CTL2[CSIZE]. */
        uint64_t reserved_0_39         : 40;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_39         : 40;
        uint64_t csize                 : 13; /**< [ 52: 40](RO) Read-only TIM_RING(0..63)_CTL2[CSIZE]. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_ctl2_s cn; */
};
typedef union cavm_tim_vringx_ctl2 cavm_tim_vringx_ctl2_t;

static inline uint64_t CAVM_TIM_VRINGX_CTL2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_CTL2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000060ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_CTL2", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_CTL2(a) cavm_tim_vringx_ctl2_t
#define bustype_CAVM_TIM_VRINGX_CTL2(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_CTL2(a) "TIM_VRINGX_CTL2"
#define device_bar_CAVM_TIM_VRINGX_CTL2(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_CTL2(a) (a)
#define arguments_CAVM_TIM_VRINGX_CTL2(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_fr_rn_cycles
 *
 * TIM Ring Free Running Cycle Count Register
 * This register is a read-only copy of TIM_FR_RN_CYCLES.
 */
union cavm_tim_vringx_fr_rn_cycles
{
    uint64_t u;
    struct cavm_tim_vringx_fr_rn_cycles_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](RO/H) Read-only TIM_FR_RN_CYCLES[COUNT]. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](RO/H) Read-only TIM_FR_RN_CYCLES[COUNT]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_fr_rn_cycles_s cn; */
};
typedef union cavm_tim_vringx_fr_rn_cycles cavm_tim_vringx_fr_rn_cycles_t;

static inline uint64_t CAVM_TIM_VRINGX_FR_RN_CYCLES(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_FR_RN_CYCLES(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000020ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_FR_RN_CYCLES", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_FR_RN_CYCLES(a) cavm_tim_vringx_fr_rn_cycles_t
#define bustype_CAVM_TIM_VRINGX_FR_RN_CYCLES(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_FR_RN_CYCLES(a) "TIM_VRINGX_FR_RN_CYCLES"
#define device_bar_CAVM_TIM_VRINGX_FR_RN_CYCLES(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_FR_RN_CYCLES(a) (a)
#define arguments_CAVM_TIM_VRINGX_FR_RN_CYCLES(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_fr_rn_gpios
 *
 * TIM Ring Free Running GPIO Count Register
 * This register is a read-only copy of TIM_FR_RN_GPIOS.
 */
union cavm_tim_vringx_fr_rn_gpios
{
    uint64_t u;
    struct cavm_tim_vringx_fr_rn_gpios_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](RO/H) Read-only TIM_FR_RN_GPIOS[COUNT]. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](RO/H) Read-only TIM_FR_RN_GPIOS[COUNT]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_fr_rn_gpios_s cn; */
};
typedef union cavm_tim_vringx_fr_rn_gpios cavm_tim_vringx_fr_rn_gpios_t;

static inline uint64_t CAVM_TIM_VRINGX_FR_RN_GPIOS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_FR_RN_GPIOS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000028ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_FR_RN_GPIOS", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_FR_RN_GPIOS(a) cavm_tim_vringx_fr_rn_gpios_t
#define bustype_CAVM_TIM_VRINGX_FR_RN_GPIOS(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_FR_RN_GPIOS(a) "TIM_VRINGX_FR_RN_GPIOS"
#define device_bar_CAVM_TIM_VRINGX_FR_RN_GPIOS(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_FR_RN_GPIOS(a) (a)
#define arguments_CAVM_TIM_VRINGX_FR_RN_GPIOS(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_fr_rn_gti
 *
 * TIM Ring Free Running System Clock Count Register
 * This register is a read-only copy of TIM_FR_RN_GTI.
 */
union cavm_tim_vringx_fr_rn_gti
{
    uint64_t u;
    struct cavm_tim_vringx_fr_rn_gti_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](RO/H) Read-only TIM_FR_RN_GTI[COUNT]. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](RO/H) Read-only TIM_FR_RN_GTI[COUNT]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_fr_rn_gti_s cn; */
};
typedef union cavm_tim_vringx_fr_rn_gti cavm_tim_vringx_fr_rn_gti_t;

static inline uint64_t CAVM_TIM_VRINGX_FR_RN_GTI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_FR_RN_GTI(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000030ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_FR_RN_GTI", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_FR_RN_GTI(a) cavm_tim_vringx_fr_rn_gti_t
#define bustype_CAVM_TIM_VRINGX_FR_RN_GTI(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_FR_RN_GTI(a) "TIM_VRINGX_FR_RN_GTI"
#define device_bar_CAVM_TIM_VRINGX_FR_RN_GTI(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_FR_RN_GTI(a) (a)
#define arguments_CAVM_TIM_VRINGX_FR_RN_GTI(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_fr_rn_ptp
 *
 * TIM Ring Free Running PTP Count Register
 * This register is a read-only copy of TIM_FR_RN_PTP.
 */
union cavm_tim_vringx_fr_rn_ptp
{
    uint64_t u;
    struct cavm_tim_vringx_fr_rn_ptp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](RO/H) Read-only TIM_FR_RN_PTP[COUNT]. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](RO/H) Read-only TIM_FR_RN_PTP[COUNT]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_fr_rn_ptp_s cn; */
};
typedef union cavm_tim_vringx_fr_rn_ptp cavm_tim_vringx_fr_rn_ptp_t;

static inline uint64_t CAVM_TIM_VRINGX_FR_RN_PTP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_FR_RN_PTP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000038ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_FR_RN_PTP", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_FR_RN_PTP(a) cavm_tim_vringx_fr_rn_ptp_t
#define bustype_CAVM_TIM_VRINGX_FR_RN_PTP(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_FR_RN_PTP(a) "TIM_VRINGX_FR_RN_PTP"
#define device_bar_CAVM_TIM_VRINGX_FR_RN_PTP(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_FR_RN_PTP(a) (a)
#define arguments_CAVM_TIM_VRINGX_FR_RN_PTP(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_late
 *
 * TIM Ring Late Register
 */
union cavm_tim_vringx_late
{
    uint64_t u;
    struct cavm_tim_vringx_late_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t count                 : 20; /**< [ 19:  0](RO/H) Indicates how many buckets are late ([COUNT] > 1) to be processed in this ring.
                                                                 When the associated ring is late, TIM will make a best effort to catch up and
                                                                 processes all buckets that are late, back-to-back. Incremented by TIM for every
                                                                 ring expiration and decremented when a ring's bucket is serviced.
                                                                 When (TIM_VRING()_LATE[COUNT] >= TIM_RING()_CTL1[BSIZE+1]), or
                                                                 (TIM_VRING()_LATE[COUNT] 0xFFFFF, and to be incremented),
                                                                 hardware will set TIM_VRING()_LATE[COUNT] = 1.
                                                                 Hardware will set TIM_VRING()_LATE[COUNT] = 0 when TIM_RING()_CTL1[ENA]
                                                                 transitions from 0 to 1 or from 1 to 0. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 20; /**< [ 19:  0](RO/H) Indicates how many buckets are late ([COUNT] > 1) to be processed in this ring.
                                                                 When the associated ring is late, TIM will make a best effort to catch up and
                                                                 processes all buckets that are late, back-to-back. Incremented by TIM for every
                                                                 ring expiration and decremented when a ring's bucket is serviced.
                                                                 When (TIM_VRING()_LATE[COUNT] >= TIM_RING()_CTL1[BSIZE+1]), or
                                                                 (TIM_VRING()_LATE[COUNT] 0xFFFFF, and to be incremented),
                                                                 hardware will set TIM_VRING()_LATE[COUNT] = 1.
                                                                 Hardware will set TIM_VRING()_LATE[COUNT] = 0 when TIM_RING()_CTL1[ENA]
                                                                 transitions from 0 to 1 or from 1 to 0. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_late_s cn; */
};
typedef union cavm_tim_vringx_late cavm_tim_vringx_late_t;

static inline uint64_t CAVM_TIM_VRINGX_LATE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_LATE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858000002e00ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_LATE", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_LATE(a) cavm_tim_vringx_late_t
#define bustype_CAVM_TIM_VRINGX_LATE(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_LATE(a) "TIM_VRINGX_LATE"
#define device_bar_CAVM_TIM_VRINGX_LATE(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_LATE(a) (a)
#define arguments_CAVM_TIM_VRINGX_LATE(a) (a),-1,-1,-1

/**
 * Register (NCB) tim_vring#_rel
 *
 * TIM Ring Relative Position Register
 * Current positions and status of the TIM walker in both time and ring position,
 * for easy synchronization with software.
 *
 * Internal:
 * For VM-safety this register contains only read-only fields.
 */
union cavm_tim_vringx_rel
{
    uint64_t u;
    struct cavm_tim_vringx_rel_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cur_bucket            : 20; /**< [ 63: 44](RO/H) Current bucket. Indicates the ring's current bucket. See TIM_RING()_CTL1[BUCKET]. */
        uint64_t late_count_msbs       : 1;  /**< [ 43: 43](RO/H) Set when TIM_VRING()_LATE[COUNT]<19:11> != 0x0.
                                                                 Software should read TIM_VRING()_LATE[COUNT] to find how many buckets a ring is late. */
        uint64_t late_count            : 11; /**< [ 42: 32](RO/H) Identical to TIM_VRING(0..63)_LATE[COUNT]<10:0>. If [LATE_COUNT_MSBS] is zero,
                                                                 it indicates how many bucket are late to be scheduled per ring. See the HRM body
                                                                 text with regards to how software should consider TIM_VRING()_LATE[COUNT] when
                                                                 inserting an entry. */
        uint64_t timercount            : 32; /**< [ 31:  0](RO/H) Timer count indicates how many timer ticks are left until the interval
                                                                 expiration, calculated as TIM_RING()_CTL0[EXPIRE_OFFSET] minus current time
                                                                 (TIM_FR_RN_CYCLES, TIM_FR_RN_GPIOS, TIM_FR_RN_GTI, or TIM_FR_RN_PTP).

                                                                 Once TIM_RING()_CTL1[ENA] = 1, [TIMERCOUNT] will be observed to count down timer
                                                                 ticks. When [TIMERCOUNT] reaches 0x0, the ring's interval expired and the
                                                                 hardware forces a bucket traversal (and increments [RING_ESR]).

                                                                 Typical initialization value should be interval/constant; Cavium recommends that
                                                                 the constant be unique per ring. This creates an offset between the rings.
                                                                 [TIMERCOUNT] becomes and remains unpredictable whenever TIM_RING()_CTL1[ENA] = 0
                                                                 or TIM_RING()_CTL1[CLK_SRC] changes. It is software's responsibility to set
                                                                 [TIMERCOUNT] before TIM_RING()_CTL1[ENA] transitions from 0 to 1. */
#else /* Word 0 - Little Endian */
        uint64_t timercount            : 32; /**< [ 31:  0](RO/H) Timer count indicates how many timer ticks are left until the interval
                                                                 expiration, calculated as TIM_RING()_CTL0[EXPIRE_OFFSET] minus current time
                                                                 (TIM_FR_RN_CYCLES, TIM_FR_RN_GPIOS, TIM_FR_RN_GTI, or TIM_FR_RN_PTP).

                                                                 Once TIM_RING()_CTL1[ENA] = 1, [TIMERCOUNT] will be observed to count down timer
                                                                 ticks. When [TIMERCOUNT] reaches 0x0, the ring's interval expired and the
                                                                 hardware forces a bucket traversal (and increments [RING_ESR]).

                                                                 Typical initialization value should be interval/constant; Cavium recommends that
                                                                 the constant be unique per ring. This creates an offset between the rings.
                                                                 [TIMERCOUNT] becomes and remains unpredictable whenever TIM_RING()_CTL1[ENA] = 0
                                                                 or TIM_RING()_CTL1[CLK_SRC] changes. It is software's responsibility to set
                                                                 [TIMERCOUNT] before TIM_RING()_CTL1[ENA] transitions from 0 to 1. */
        uint64_t late_count            : 11; /**< [ 42: 32](RO/H) Identical to TIM_VRING(0..63)_LATE[COUNT]<10:0>. If [LATE_COUNT_MSBS] is zero,
                                                                 it indicates how many bucket are late to be scheduled per ring. See the HRM body
                                                                 text with regards to how software should consider TIM_VRING()_LATE[COUNT] when
                                                                 inserting an entry. */
        uint64_t late_count_msbs       : 1;  /**< [ 43: 43](RO/H) Set when TIM_VRING()_LATE[COUNT]<19:11> != 0x0.
                                                                 Software should read TIM_VRING()_LATE[COUNT] to find how many buckets a ring is late. */
        uint64_t cur_bucket            : 20; /**< [ 63: 44](RO/H) Current bucket. Indicates the ring's current bucket. See TIM_RING()_CTL1[BUCKET]. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_tim_vringx_rel_s cn; */
};
typedef union cavm_tim_vringx_rel cavm_tim_vringx_rel_t;

static inline uint64_t CAVM_TIM_VRINGX_REL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_TIM_VRINGX_REL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x858010000110ll + 0x100000ll * ((a) & 0x3f);
    __cavm_csr_fatal("TIM_VRINGX_REL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_TIM_VRINGX_REL(a) cavm_tim_vringx_rel_t
#define bustype_CAVM_TIM_VRINGX_REL(a) CSR_TYPE_NCB
#define basename_CAVM_TIM_VRINGX_REL(a) "TIM_VRINGX_REL"
#define device_bar_CAVM_TIM_VRINGX_REL(a) 0x10 /* VF_BAR0 */
#define busnum_CAVM_TIM_VRINGX_REL(a) (a)
#define arguments_CAVM_TIM_VRINGX_REL(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_TIM_H__ */
