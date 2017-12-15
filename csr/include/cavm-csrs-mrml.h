#ifndef __CAVM_CSRS_MRML_H__
#define __CAVM_CSRS_MRML_H__
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
 * Cavium MRML.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration mrml_bar_e
 *
 * MRML Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define CAVM_MRML_BAR_E_MRML_PF_BAR0 (0x87e0fc000000ll)
#define CAVM_MRML_BAR_E_MRML_PF_BAR0_SIZE 0x100000ull
#define CAVM_MRML_BAR_E_MRML_PF_BAR4 (0x87e0fcf00000ll)
#define CAVM_MRML_BAR_E_MRML_PF_BAR4_SIZE 0x100000ull

/**
 * Enumeration mrml_int_vec_e
 *
 * MRML MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define CAVM_MRML_INT_VEC_E_INTS (0)

/**
 * Register (RSL) mrml_int_ena_w1c
 *
 * MRML Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_mrml_int_ena_w1c
{
    uint64_t u;
    struct cavm_mrml_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t local_toe             : 1;  /**< [  1:  1](SR/W1C/H) Reads or clears enable for MRML_INT_SUM[LOCAL_TOE]. */
        uint64_t ocx_toe               : 1;  /**< [  0:  0](SR/W1C/H) Reads or clears enable for MRML_INT_SUM[OCX_TOE]. */
#else /* Word 0 - Little Endian */
        uint64_t ocx_toe               : 1;  /**< [  0:  0](SR/W1C/H) Reads or clears enable for MRML_INT_SUM[OCX_TOE]. */
        uint64_t local_toe             : 1;  /**< [  1:  1](SR/W1C/H) Reads or clears enable for MRML_INT_SUM[LOCAL_TOE]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_int_ena_w1c_s cn; */
};
typedef union cavm_mrml_int_ena_w1c cavm_mrml_int_ena_w1c_t;

#define CAVM_MRML_INT_ENA_W1C CAVM_MRML_INT_ENA_W1C_FUNC()
static inline uint64_t CAVM_MRML_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_INT_ENA_W1C_FUNC(void)
{
    return 0x87e0fc000880ll;
}

#define typedef_CAVM_MRML_INT_ENA_W1C cavm_mrml_int_ena_w1c_t
#define bustype_CAVM_MRML_INT_ENA_W1C CSR_TYPE_RSL
#define basename_CAVM_MRML_INT_ENA_W1C "MRML_INT_ENA_W1C"
#define device_bar_CAVM_MRML_INT_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_INT_ENA_W1C 0
#define arguments_CAVM_MRML_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (RSL) mrml_int_ena_w1s
 *
 * MRML Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_mrml_int_ena_w1s
{
    uint64_t u;
    struct cavm_mrml_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t local_toe             : 1;  /**< [  1:  1](SR/W1S/H) Reads or sets enable for MRML_INT_SUM[LOCAL_TOE]. */
        uint64_t ocx_toe               : 1;  /**< [  0:  0](SR/W1S/H) Reads or sets enable for MRML_INT_SUM[OCX_TOE]. */
#else /* Word 0 - Little Endian */
        uint64_t ocx_toe               : 1;  /**< [  0:  0](SR/W1S/H) Reads or sets enable for MRML_INT_SUM[OCX_TOE]. */
        uint64_t local_toe             : 1;  /**< [  1:  1](SR/W1S/H) Reads or sets enable for MRML_INT_SUM[LOCAL_TOE]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_int_ena_w1s_s cn; */
};
typedef union cavm_mrml_int_ena_w1s cavm_mrml_int_ena_w1s_t;

#define CAVM_MRML_INT_ENA_W1S CAVM_MRML_INT_ENA_W1S_FUNC()
static inline uint64_t CAVM_MRML_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_INT_ENA_W1S_FUNC(void)
{
    return 0x87e0fc001000ll;
}

#define typedef_CAVM_MRML_INT_ENA_W1S cavm_mrml_int_ena_w1s_t
#define bustype_CAVM_MRML_INT_ENA_W1S CSR_TYPE_RSL
#define basename_CAVM_MRML_INT_ENA_W1S "MRML_INT_ENA_W1S"
#define device_bar_CAVM_MRML_INT_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_INT_ENA_W1S 0
#define arguments_CAVM_MRML_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (RSL) mrml_int_local_to
 *
 * MRML Local-Node Timeout Register
 * Configures local-node timeouts.
 */
union cavm_mrml_int_local_to
{
    uint64_t u;
    struct cavm_mrml_int_local_to_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t tovalue               : 32; /**< [ 31:  0](SR/W) Local timeout value, in coprocessor clocks. */
#else /* Word 0 - Little Endian */
        uint64_t tovalue               : 32; /**< [ 31:  0](SR/W) Local timeout value, in coprocessor clocks. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_int_local_to_s cn; */
};
typedef union cavm_mrml_int_local_to cavm_mrml_int_local_to_t;

#define CAVM_MRML_INT_LOCAL_TO CAVM_MRML_INT_LOCAL_TO_FUNC()
static inline uint64_t CAVM_MRML_INT_LOCAL_TO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_INT_LOCAL_TO_FUNC(void)
{
    return 0x87e0fc000800ll;
}

#define typedef_CAVM_MRML_INT_LOCAL_TO cavm_mrml_int_local_to_t
#define bustype_CAVM_MRML_INT_LOCAL_TO CSR_TYPE_RSL
#define basename_CAVM_MRML_INT_LOCAL_TO "MRML_INT_LOCAL_TO"
#define device_bar_CAVM_MRML_INT_LOCAL_TO 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_INT_LOCAL_TO 0
#define arguments_CAVM_MRML_INT_LOCAL_TO -1,-1,-1,-1

/**
 * Register (RSL) mrml_int_ocx_to
 *
 * MRML OCX Timeout Register
 * Configures remote-node timeouts.
 */
union cavm_mrml_int_ocx_to
{
    uint64_t u;
    struct cavm_mrml_int_ocx_to_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t tovalue               : 32; /**< [ 31:  0](SR/W) OCX timeout value, in coprocessor clocks. */
#else /* Word 0 - Little Endian */
        uint64_t tovalue               : 32; /**< [ 31:  0](SR/W) OCX timeout value, in coprocessor clocks. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_int_ocx_to_s cn; */
};
typedef union cavm_mrml_int_ocx_to cavm_mrml_int_ocx_to_t;

#define CAVM_MRML_INT_OCX_TO CAVM_MRML_INT_OCX_TO_FUNC()
static inline uint64_t CAVM_MRML_INT_OCX_TO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_INT_OCX_TO_FUNC(void)
{
    return 0x87e0fc000808ll;
}

#define typedef_CAVM_MRML_INT_OCX_TO cavm_mrml_int_ocx_to_t
#define bustype_CAVM_MRML_INT_OCX_TO CSR_TYPE_RSL
#define basename_CAVM_MRML_INT_OCX_TO "MRML_INT_OCX_TO"
#define device_bar_CAVM_MRML_INT_OCX_TO 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_INT_OCX_TO 0
#define arguments_CAVM_MRML_INT_OCX_TO -1,-1,-1,-1

/**
 * Register (RSL) mrml_int_sum
 *
 * MRML Interrupt Summary Register
 * This register contains the different interrupt-summary bits of the MRML.
 */
union cavm_mrml_int_sum
{
    uint64_t u;
    struct cavm_mrml_int_sum_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t local_toe             : 1;  /**< [  1:  1](SR/W1C/H) Local timeout error. When set, a local timeout error has occurred. */
        uint64_t ocx_toe               : 1;  /**< [  0:  0](SR/W1C/H) OCX timeout error. When set, an OCX timeout error has occurred. */
#else /* Word 0 - Little Endian */
        uint64_t ocx_toe               : 1;  /**< [  0:  0](SR/W1C/H) OCX timeout error. When set, an OCX timeout error has occurred. */
        uint64_t local_toe             : 1;  /**< [  1:  1](SR/W1C/H) Local timeout error. When set, a local timeout error has occurred. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_int_sum_s cn; */
};
typedef union cavm_mrml_int_sum cavm_mrml_int_sum_t;

#define CAVM_MRML_INT_SUM CAVM_MRML_INT_SUM_FUNC()
static inline uint64_t CAVM_MRML_INT_SUM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_INT_SUM_FUNC(void)
{
    return 0x87e0fc000810ll;
}

#define typedef_CAVM_MRML_INT_SUM cavm_mrml_int_sum_t
#define bustype_CAVM_MRML_INT_SUM CSR_TYPE_RSL
#define basename_CAVM_MRML_INT_SUM "MRML_INT_SUM"
#define device_bar_CAVM_MRML_INT_SUM 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_INT_SUM 0
#define arguments_CAVM_MRML_INT_SUM -1,-1,-1,-1

/**
 * Register (RSL) mrml_int_sum_w1s
 *
 * MRML Interrupt Set Register
 * This register sets interrupt bits.
 */
union cavm_mrml_int_sum_w1s
{
    uint64_t u;
    struct cavm_mrml_int_sum_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t local_toe             : 1;  /**< [  1:  1](SR/W1S/H) Reads or sets MRML_INT_SUM[LOCAL_TOE]. */
        uint64_t ocx_toe               : 1;  /**< [  0:  0](SR/W1S/H) Reads or sets MRML_INT_SUM[OCX_TOE]. */
#else /* Word 0 - Little Endian */
        uint64_t ocx_toe               : 1;  /**< [  0:  0](SR/W1S/H) Reads or sets MRML_INT_SUM[OCX_TOE]. */
        uint64_t local_toe             : 1;  /**< [  1:  1](SR/W1S/H) Reads or sets MRML_INT_SUM[LOCAL_TOE]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_int_sum_w1s_s cn; */
};
typedef union cavm_mrml_int_sum_w1s cavm_mrml_int_sum_w1s_t;

#define CAVM_MRML_INT_SUM_W1S CAVM_MRML_INT_SUM_W1S_FUNC()
static inline uint64_t CAVM_MRML_INT_SUM_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_INT_SUM_W1S_FUNC(void)
{
    return 0x87e0fc000818ll;
}

#define typedef_CAVM_MRML_INT_SUM_W1S cavm_mrml_int_sum_w1s_t
#define bustype_CAVM_MRML_INT_SUM_W1S CSR_TYPE_RSL
#define basename_CAVM_MRML_INT_SUM_W1S "MRML_INT_SUM_W1S"
#define device_bar_CAVM_MRML_INT_SUM_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_INT_SUM_W1S 0
#define arguments_CAVM_MRML_INT_SUM_W1S -1,-1,-1,-1

/**
 * Register (RSL) mrml_msix_pba#
 *
 * MRML MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the MRML_INT_VEC_E enumeration.
 */
union cavm_mrml_msix_pbax
{
    uint64_t u;
    struct cavm_mrml_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated MRML_MSIX_VEC()_CTL, enumerated by MRML_INT_VEC_E.
                                                                 Bits that have no associated MRML_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated MRML_MSIX_VEC()_CTL, enumerated by MRML_INT_VEC_E.
                                                                 Bits that have no associated MRML_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_msix_pbax_s cn; */
};
typedef union cavm_mrml_msix_pbax cavm_mrml_msix_pbax_t;

static inline uint64_t CAVM_MRML_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_MSIX_PBAX(unsigned long a)
{
    if (a==0)
        return 0x87e0fcff0000ll + 8ll * ((a) & 0x0);
    __cavm_csr_fatal("MRML_MSIX_PBAX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MRML_MSIX_PBAX(a) cavm_mrml_msix_pbax_t
#define bustype_CAVM_MRML_MSIX_PBAX(a) CSR_TYPE_RSL
#define basename_CAVM_MRML_MSIX_PBAX(a) "MRML_MSIX_PBAX"
#define device_bar_CAVM_MRML_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_MRML_MSIX_PBAX(a) (a)
#define arguments_CAVM_MRML_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (RSL) mrml_msix_vec#_addr
 *
 * MRML MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the MRML_INT_VEC_E enumeration.
 */
union cavm_mrml_msix_vecx_addr
{
    uint64_t u;
    struct cavm_mrml_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's MRML_MSIX_VEC()_ADDR, MRML_MSIX_VEC()_CTL, and corresponding
                                                                 bit of MRML_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_MRML_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's MRML_MSIX_VEC()_ADDR, MRML_MSIX_VEC()_CTL, and corresponding
                                                                 bit of MRML_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_MRML_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_msix_vecx_addr_s cn; */
};
typedef union cavm_mrml_msix_vecx_addr cavm_mrml_msix_vecx_addr_t;

static inline uint64_t CAVM_MRML_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_MSIX_VECX_ADDR(unsigned long a)
{
    if (a==0)
        return 0x87e0fcf00000ll + 0x10ll * ((a) & 0x0);
    __cavm_csr_fatal("MRML_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MRML_MSIX_VECX_ADDR(a) cavm_mrml_msix_vecx_addr_t
#define bustype_CAVM_MRML_MSIX_VECX_ADDR(a) CSR_TYPE_RSL
#define basename_CAVM_MRML_MSIX_VECX_ADDR(a) "MRML_MSIX_VECX_ADDR"
#define device_bar_CAVM_MRML_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_MRML_MSIX_VECX_ADDR(a) (a)
#define arguments_CAVM_MRML_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL) mrml_msix_vec#_ctl
 *
 * MRML MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the MRML_INT_VEC_E enumeration.
 */
union cavm_mrml_msix_vecx_ctl
{
    uint64_t u;
    struct cavm_mrml_msix_vecx_ctl_s
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
    /* struct cavm_mrml_msix_vecx_ctl_s cn; */
};
typedef union cavm_mrml_msix_vecx_ctl cavm_mrml_msix_vecx_ctl_t;

static inline uint64_t CAVM_MRML_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_MSIX_VECX_CTL(unsigned long a)
{
    if (a==0)
        return 0x87e0fcf00008ll + 0x10ll * ((a) & 0x0);
    __cavm_csr_fatal("MRML_MSIX_VECX_CTL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MRML_MSIX_VECX_CTL(a) cavm_mrml_msix_vecx_ctl_t
#define bustype_CAVM_MRML_MSIX_VECX_CTL(a) CSR_TYPE_RSL
#define basename_CAVM_MRML_MSIX_VECX_CTL(a) "MRML_MSIX_VECX_CTL"
#define device_bar_CAVM_MRML_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_MRML_MSIX_VECX_CTL(a) (a)
#define arguments_CAVM_MRML_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) mrml_ncb#_sdev
 *
 * MRML NCB Secure Device Registers
 */
union cavm_mrml_ncbx_sdev
{
    uint64_t u;
    struct cavm_mrml_ncbx_sdev_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t sec                   : 64; /**< [ 63:  0](SR/W) NCB function secure.  Similar to MRML_RSL()_SDEV except applies to NCB devices. */
#else /* Word 0 - Little Endian */
        uint64_t sec                   : 64; /**< [ 63:  0](SR/W) NCB function secure.  Similar to MRML_RSL()_SDEV except applies to NCB devices. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_ncbx_sdev_s cn; */
};
typedef union cavm_mrml_ncbx_sdev cavm_mrml_ncbx_sdev_t;

static inline uint64_t CAVM_MRML_NCBX_SDEV(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_NCBX_SDEV(unsigned long a)
{
    if (a<=3)
        return 0x87e0fc000400ll + 8ll * ((a) & 0x3);
    __cavm_csr_fatal("MRML_NCBX_SDEV", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MRML_NCBX_SDEV(a) cavm_mrml_ncbx_sdev_t
#define bustype_CAVM_MRML_NCBX_SDEV(a) CSR_TYPE_RSL
#define basename_CAVM_MRML_NCBX_SDEV(a) "MRML_NCBX_SDEV"
#define device_bar_CAVM_MRML_NCBX_SDEV(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_NCBX_SDEV(a) (a)
#define arguments_CAVM_MRML_NCBX_SDEV(a) (a),-1,-1,-1

/**
 * Register (RSL) mrml_ncb#_skill
 *
 * MRML RSL Secure Kill-Device Registers
 */
union cavm_mrml_ncbx_skill
{
    uint64_t u;
    struct cavm_mrml_ncbx_skill_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t skill                 : 64; /**< [ 63:  0](SR/W1S) NCB function kill.  Similar to MRML_RSL()_SKILL except applies to NCB devices. */
#else /* Word 0 - Little Endian */
        uint64_t skill                 : 64; /**< [ 63:  0](SR/W1S) NCB function kill.  Similar to MRML_RSL()_SKILL except applies to NCB devices. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_ncbx_skill_s cn; */
};
typedef union cavm_mrml_ncbx_skill cavm_mrml_ncbx_skill_t;

static inline uint64_t CAVM_MRML_NCBX_SKILL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_NCBX_SKILL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=3))
        return 0x87e0fc000500ll + 8ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0fc000500ll + 8ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && (a<=3))
        return 0x87e0fc000500ll + 8ll * ((a) & 0x3);
    __cavm_csr_fatal("MRML_NCBX_SKILL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MRML_NCBX_SKILL(a) cavm_mrml_ncbx_skill_t
#define bustype_CAVM_MRML_NCBX_SKILL(a) CSR_TYPE_RSL
#define basename_CAVM_MRML_NCBX_SKILL(a) "MRML_NCBX_SKILL"
#define device_bar_CAVM_MRML_NCBX_SKILL(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_NCBX_SKILL(a) (a)
#define arguments_CAVM_MRML_NCBX_SKILL(a) (a),-1,-1,-1

/**
 * Register (RSL) mrml_rsl#_sdev
 *
 * MRML RSL Secure Device Registers
 */
union cavm_mrml_rslx_sdev
{
    uint64_t u;
    struct cavm_mrml_rslx_sdev_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t sec                   : 64; /**< [ 63:  0](SR/W) RSL function secure. If set, the corresponding RSL device ID will be secure access
                                                                 only. Read/writes from nonsecure agents will be RAZ/WI.
                                                                 The register index 0..3 indicates which group of 64 functions, and bit index indicates
                                                                 which mod-64 function, for 256 function bits total.

                                                                 For compatibility with ARM secure boot at least the following RSL devices typically
                                                                 need to be marked secure: DAP, FUSF, IOBN, KEY, L2C, L2C_CBC, L2C_MCI, L2C_TAD, LMC,
                                                                 MIO_BOOT, MIO_FUS, MRML, OCLA, OCX, PCCBR_MRML, RST, SLI, VRM.

                                                                 RSL function number 0xFF, which is not present but used internally by MRML, must
                                                                 be marked secure. */
#else /* Word 0 - Little Endian */
        uint64_t sec                   : 64; /**< [ 63:  0](SR/W) RSL function secure. If set, the corresponding RSL device ID will be secure access
                                                                 only. Read/writes from nonsecure agents will be RAZ/WI.
                                                                 The register index 0..3 indicates which group of 64 functions, and bit index indicates
                                                                 which mod-64 function, for 256 function bits total.

                                                                 For compatibility with ARM secure boot at least the following RSL devices typically
                                                                 need to be marked secure: DAP, FUSF, IOBN, KEY, L2C, L2C_CBC, L2C_MCI, L2C_TAD, LMC,
                                                                 MIO_BOOT, MIO_FUS, MRML, OCLA, OCX, PCCBR_MRML, RST, SLI, VRM.

                                                                 RSL function number 0xFF, which is not present but used internally by MRML, must
                                                                 be marked secure. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_rslx_sdev_s cn; */
};
typedef union cavm_mrml_rslx_sdev cavm_mrml_rslx_sdev_t;

static inline uint64_t CAVM_MRML_RSLX_SDEV(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_RSLX_SDEV(unsigned long a)
{
    if (a<=3)
        return 0x87e0fc000200ll + 8ll * ((a) & 0x3);
    __cavm_csr_fatal("MRML_RSLX_SDEV", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MRML_RSLX_SDEV(a) cavm_mrml_rslx_sdev_t
#define bustype_CAVM_MRML_RSLX_SDEV(a) CSR_TYPE_RSL
#define basename_CAVM_MRML_RSLX_SDEV(a) "MRML_RSLX_SDEV"
#define device_bar_CAVM_MRML_RSLX_SDEV(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_RSLX_SDEV(a) (a)
#define arguments_CAVM_MRML_RSLX_SDEV(a) (a),-1,-1,-1

/**
 * Register (RSL) mrml_rsl#_skill
 *
 * MRML RSL Secure Kill-Device Registers
 */
union cavm_mrml_rslx_skill
{
    uint64_t u;
    struct cavm_mrml_rslx_skill_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t skill                 : 64; /**< [ 63:  0](SR/W1S) RSL function kill. Write one to set, once set cannot be cleared
                                                                 until soft reset. If set, read/writes from any agent
                                                                 (secure/nonsecure) will be RAZ/WI.
                                                                 The register index 0..3 indicates which group of 64 functions, and bit index indicates
                                                                 which mod-64 function, for 256 function bits total. */
#else /* Word 0 - Little Endian */
        uint64_t skill                 : 64; /**< [ 63:  0](SR/W1S) RSL function kill. Write one to set, once set cannot be cleared
                                                                 until soft reset. If set, read/writes from any agent
                                                                 (secure/nonsecure) will be RAZ/WI.
                                                                 The register index 0..3 indicates which group of 64 functions, and bit index indicates
                                                                 which mod-64 function, for 256 function bits total. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_rslx_skill_s cn; */
};
typedef union cavm_mrml_rslx_skill cavm_mrml_rslx_skill_t;

static inline uint64_t CAVM_MRML_RSLX_SKILL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_RSLX_SKILL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=3))
        return 0x87e0fc000300ll + 8ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0fc000300ll + 8ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && (a<=3))
        return 0x87e0fc000300ll + 8ll * ((a) & 0x3);
    __cavm_csr_fatal("MRML_RSLX_SKILL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MRML_RSLX_SKILL(a) cavm_mrml_rslx_skill_t
#define bustype_CAVM_MRML_RSLX_SKILL(a) CSR_TYPE_RSL
#define basename_CAVM_MRML_RSLX_SKILL(a) "MRML_RSLX_SKILL"
#define device_bar_CAVM_MRML_RSLX_SKILL(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_RSLX_SKILL(a) (a)
#define arguments_CAVM_MRML_RSLX_SKILL(a) (a),-1,-1,-1

/**
 * Register (RSL) mrml_scfg
 *
 * MRML RSL Secure Configuration Register
 */
union cavm_mrml_scfg
{
    uint64_t u;
    struct cavm_mrml_scfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mrml_scfg_s cn; */
};
typedef union cavm_mrml_scfg cavm_mrml_scfg_t;

#define CAVM_MRML_SCFG CAVM_MRML_SCFG_FUNC()
static inline uint64_t CAVM_MRML_SCFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MRML_SCFG_FUNC(void)
{
    return 0x87e0fc000000ll;
}

#define typedef_CAVM_MRML_SCFG cavm_mrml_scfg_t
#define bustype_CAVM_MRML_SCFG CSR_TYPE_RSL
#define basename_CAVM_MRML_SCFG "MRML_SCFG"
#define device_bar_CAVM_MRML_SCFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_MRML_SCFG 0
#define arguments_CAVM_MRML_SCFG -1,-1,-1,-1

#endif /* __CAVM_CSRS_MRML_H__ */
