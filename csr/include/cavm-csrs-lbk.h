#ifndef __CAVM_CSRS_LBK_H__
#define __CAVM_CSRS_LBK_H__
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
 * Cavium LBK.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration lbk_bar_e
 *
 * LBK Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define CAVM_LBK_BAR_E_LBKX_PF_BAR0(a) (0x87e018000000ll + 0x1000000ll * (a))
#define CAVM_LBK_BAR_E_LBKX_PF_BAR0_SIZE 0x100000ull
#define CAVM_LBK_BAR_E_LBKX_PF_BAR4(a) (0x87e018f00000ll + 0x1000000ll * (a))
#define CAVM_LBK_BAR_E_LBKX_PF_BAR4_SIZE 0x100000ull

/**
 * Enumeration lbk_connect_e
 *
 * LBK Source Connection Enumeration
 * Enumerates LBK()_CONST[SRC] and LBK()_CONST[DEST].
 */
#define CAVM_LBK_CONNECT_E_NICX(a) (0 + (a))
#define CAVM_LBK_CONNECT_E_PKIX(a) (4 + (a))
#define CAVM_LBK_CONNECT_E_PKOX(a) (8 + (a))

/**
 * Enumeration lbk_int_vec_e
 *
 * LBK MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define CAVM_LBK_INT_VEC_E_ERR (0)

/**
 * Register (RSL) lbk#_bist_result
 *
 * Loopback BIST Result Register
 * This register provides access to the internal BIST results. Each bit is the BIST result of an
 * individual memory (per bit, 0 = pass and 1 = fail).
 */
union cavm_lbkx_bist_result
{
    uint64_t u;
    struct cavm_lbkx_bist_result_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t dat                   : 1;  /**< [  0:  0](RO) BIST result of the data FIFO RAM. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 1;  /**< [  0:  0](RO) BIST result of the data FIFO RAM. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lbkx_bist_result_s cn; */
};
typedef union cavm_lbkx_bist_result cavm_lbkx_bist_result_t;

static inline uint64_t CAVM_LBKX_BIST_RESULT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_BIST_RESULT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000020ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000020ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_BIST_RESULT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_BIST_RESULT(a) cavm_lbkx_bist_result_t
#define bustype_CAVM_LBKX_BIST_RESULT(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_BIST_RESULT(a) "LBKX_BIST_RESULT"
#define device_bar_CAVM_LBKX_BIST_RESULT(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_BIST_RESULT(a) (a)
#define arguments_CAVM_LBKX_BIST_RESULT(a) (a),-1,-1,-1

/**
 * Register (RSL) lbk#_ch#_pkind
 *
 * Loopback Channel to Port Kind Register
 */
union cavm_lbkx_chx_pkind
{
    uint64_t u;
    struct cavm_lbkx_chx_pkind_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t pkind                 : 6;  /**< [  5:  0](R/W) Loopback pkind for the respective loopback channel. */
#else /* Word 0 - Little Endian */
        uint64_t pkind                 : 6;  /**< [  5:  0](R/W) Loopback pkind for the respective loopback channel. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lbkx_chx_pkind_s cn; */
};
typedef union cavm_lbkx_chx_pkind cavm_lbkx_chx_pkind_t;

static inline uint64_t CAVM_LBKX_CHX_PKIND(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_CHX_PKIND(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x87e018000200ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=63)))
        return 0x87e018000200ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x3f);
    __cavm_csr_fatal("LBKX_CHX_PKIND", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_CHX_PKIND(a,b) cavm_lbkx_chx_pkind_t
#define bustype_CAVM_LBKX_CHX_PKIND(a,b) CSR_TYPE_RSL
#define basename_CAVM_LBKX_CHX_PKIND(a,b) "LBKX_CHX_PKIND"
#define device_bar_CAVM_LBKX_CHX_PKIND(a,b) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_CHX_PKIND(a,b) (a)
#define arguments_CAVM_LBKX_CHX_PKIND(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lbk#_clk_gate_ctl
 *
 * Loopback Reset Register
 * This register is for diagnostic use only.
 */
union cavm_lbkx_clk_gate_ctl
{
    uint64_t u;
    struct cavm_lbkx_clk_gate_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t dis                   : 1;  /**< [  0:  0](R/W) Clock gate disable. When set, forces gated clock to always on. */
#else /* Word 0 - Little Endian */
        uint64_t dis                   : 1;  /**< [  0:  0](R/W) Clock gate disable. When set, forces gated clock to always on. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lbkx_clk_gate_ctl_s cn; */
};
typedef union cavm_lbkx_clk_gate_ctl cavm_lbkx_clk_gate_ctl_t;

static inline uint64_t CAVM_LBKX_CLK_GATE_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_CLK_GATE_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000008ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000008ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_CLK_GATE_CTL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_CLK_GATE_CTL(a) cavm_lbkx_clk_gate_ctl_t
#define bustype_CAVM_LBKX_CLK_GATE_CTL(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_CLK_GATE_CTL(a) "LBKX_CLK_GATE_CTL"
#define device_bar_CAVM_LBKX_CLK_GATE_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_CLK_GATE_CTL(a) (a)
#define arguments_CAVM_LBKX_CLK_GATE_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) lbk#_const
 *
 * Loopback Constants Register
 * This register contains constants for software discovery.
 */
union cavm_lbkx_const
{
    uint64_t u;
    struct cavm_lbkx_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t chan                  : 16; /**< [ 47: 32](RO) Number of channels supported. */
        uint64_t dest                  : 4;  /**< [ 31: 28](RO) What blocks this LBK connects. Enumerated by LBK_CONNECT_E.
                                                                 For LBK0, indicates LBK_CONNECT_E::PKI(0).
                                                                 For LBK1, indicates LBK_CONNECT_E::PKI(0).
                                                                 For LBK2, indicates LBK_CONNECT_E::NIC(0).
                                                                 For LBK3, indicates LBK_CONNECT_E::NIC(0).

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t src                   : 4;  /**< [ 27: 24](RO) What blocks this LBK connects. Enumerated by LBK_CONNECT_E.
                                                                 For LBK0, indicates LBK_CONNECT_E::PKO(0).
                                                                 For LBK1, indicates LBK_CONNECT_E::NIC(0).
                                                                 For LBK2, indicates LBK_CONNECT_E::PKO(0).
                                                                 For LBK3, indicates LBK_CONNECT_E::NIC(0).

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t buf_size              : 24; /**< [ 23:  0](RO) Number of bytes in loopback data FIFO.
                                                                 For LBK0, 0x1000.
                                                                 For LBK1, 0x3000.
                                                                 For LBK2, 0x1000.
                                                                 For LBK3, 0x3000.

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
#else /* Word 0 - Little Endian */
        uint64_t buf_size              : 24; /**< [ 23:  0](RO) Number of bytes in loopback data FIFO.
                                                                 For LBK0, 0x1000.
                                                                 For LBK1, 0x3000.
                                                                 For LBK2, 0x1000.
                                                                 For LBK3, 0x3000.

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t src                   : 4;  /**< [ 27: 24](RO) What blocks this LBK connects. Enumerated by LBK_CONNECT_E.
                                                                 For LBK0, indicates LBK_CONNECT_E::PKO(0).
                                                                 For LBK1, indicates LBK_CONNECT_E::NIC(0).
                                                                 For LBK2, indicates LBK_CONNECT_E::PKO(0).
                                                                 For LBK3, indicates LBK_CONNECT_E::NIC(0).

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t dest                  : 4;  /**< [ 31: 28](RO) What blocks this LBK connects. Enumerated by LBK_CONNECT_E.
                                                                 For LBK0, indicates LBK_CONNECT_E::PKI(0).
                                                                 For LBK1, indicates LBK_CONNECT_E::PKI(0).
                                                                 For LBK2, indicates LBK_CONNECT_E::NIC(0).
                                                                 For LBK3, indicates LBK_CONNECT_E::NIC(0).

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t chan                  : 16; /**< [ 47: 32](RO) Number of channels supported. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct cavm_lbkx_const_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t chan                  : 16; /**< [ 47: 32](RO) Number of channels supported. */
        uint64_t dest                  : 4;  /**< [ 31: 28](RO) What blocks this LBK transmits traffic to. Enumerated by LBK_CONNECT_E.
                                                                 For LBK0, indicates LBK_CONNECT_E::NIC(0).

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t src                   : 4;  /**< [ 27: 24](RO) What blocks this LBK receives traffic from. Enumerated by LBK_CONNECT_E.
                                                                 For LBK0, indicates LBK_CONNECT_E::NIC(0).

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t buf_size              : 24; /**< [ 23:  0](RO) Number of bytes in loopback data FIFO.
                                                                 For LBK0, 0x3000.

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
#else /* Word 0 - Little Endian */
        uint64_t buf_size              : 24; /**< [ 23:  0](RO) Number of bytes in loopback data FIFO.
                                                                 For LBK0, 0x3000.

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t src                   : 4;  /**< [ 27: 24](RO) What blocks this LBK receives traffic from. Enumerated by LBK_CONNECT_E.
                                                                 For LBK0, indicates LBK_CONNECT_E::NIC(0).

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t dest                  : 4;  /**< [ 31: 28](RO) What blocks this LBK transmits traffic to. Enumerated by LBK_CONNECT_E.
                                                                 For LBK0, indicates LBK_CONNECT_E::NIC(0).

                                                                 Internal:
                                                                 lbk.v takes this from input straps set by the instantiation. */
        uint64_t chan                  : 16; /**< [ 47: 32](RO) Number of channels supported. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct cavm_lbkx_const_s cn83xx; */
};
typedef union cavm_lbkx_const cavm_lbkx_const_t;

static inline uint64_t CAVM_LBKX_CONST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_CONST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000010ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000010ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_CONST", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_CONST(a) cavm_lbkx_const_t
#define bustype_CAVM_LBKX_CONST(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_CONST(a) "LBKX_CONST"
#define device_bar_CAVM_LBKX_CONST(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_CONST(a) (a)
#define arguments_CAVM_LBKX_CONST(a) (a),-1,-1,-1

/**
 * Register (RSL) lbk#_const1
 *
 * Loopback Constants Register
 * This register contains constants for software discovery.
 */
union cavm_lbkx_const1
{
    uint64_t u;
    struct cavm_lbkx_const1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lbkx_const1_s cn; */
};
typedef union cavm_lbkx_const1 cavm_lbkx_const1_t;

static inline uint64_t CAVM_LBKX_CONST1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_CONST1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000018ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000018ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_CONST1", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_CONST1(a) cavm_lbkx_const1_t
#define bustype_CAVM_LBKX_CONST1(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_CONST1(a) "LBKX_CONST1"
#define device_bar_CAVM_LBKX_CONST1(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_CONST1(a) (a)
#define arguments_CAVM_LBKX_CONST1(a) (a),-1,-1,-1

/**
 * Register (RSL) lbk#_ecc_cfg
 *
 * Loopback ECC Configuration Register
 */
union cavm_lbkx_ecc_cfg
{
    uint64_t u;
    struct cavm_lbkx_ecc_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t dat_flip              : 2;  /**< [  2:  1](R/W) Testing feature. Flip syndrome bits <1:0> on writes to the data FIFO RAM to test
                                                                 single-bit or double-bit errors. */
        uint64_t dat_cdis              : 1;  /**< [  0:  0](R/W) Disable ECC corrector on data FIFO RAM outputs. */
#else /* Word 0 - Little Endian */
        uint64_t dat_cdis              : 1;  /**< [  0:  0](R/W) Disable ECC corrector on data FIFO RAM outputs. */
        uint64_t dat_flip              : 2;  /**< [  2:  1](R/W) Testing feature. Flip syndrome bits <1:0> on writes to the data FIFO RAM to test
                                                                 single-bit or double-bit errors. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lbkx_ecc_cfg_s cn; */
};
typedef union cavm_lbkx_ecc_cfg cavm_lbkx_ecc_cfg_t;

static inline uint64_t CAVM_LBKX_ECC_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_ECC_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000060ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000060ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_ECC_CFG", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_ECC_CFG(a) cavm_lbkx_ecc_cfg_t
#define bustype_CAVM_LBKX_ECC_CFG(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_ECC_CFG(a) "LBKX_ECC_CFG"
#define device_bar_CAVM_LBKX_ECC_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_ECC_CFG(a) (a)
#define arguments_CAVM_LBKX_ECC_CFG(a) (a),-1,-1,-1

/**
 * Register (RSL) lbk#_err_int
 *
 * Loopback Error Interrupt Register
 */
union cavm_lbkx_err_int
{
    uint64_t u;
    struct cavm_lbkx_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1C/H) Internal assertion, packet channel credit FIFO had an overflow. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1C/H) Internal assertion, packet channel credit FIFO had an underflow. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1C/H) Internal assertion, packet data FIFO had an overflow. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1C/H) Internal assertion, packet data FIFO had an underflow. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1C/H) Data RAM had a ECC double bit error. */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1C/H) Data RAM had a ECC single bit error. */
#else /* Word 0 - Little Endian */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1C/H) Data RAM had a ECC single bit error. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1C/H) Data RAM had a ECC double bit error. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1C/H) Internal assertion, packet data FIFO had an underflow. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1C/H) Internal assertion, packet data FIFO had an overflow. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1C/H) Internal assertion, packet channel credit FIFO had an underflow. */
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1C/H) Internal assertion, packet channel credit FIFO had an overflow. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lbkx_err_int_s cn; */
};
typedef union cavm_lbkx_err_int cavm_lbkx_err_int_t;

static inline uint64_t CAVM_LBKX_ERR_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_ERR_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000040ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000040ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_ERR_INT", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_ERR_INT(a) cavm_lbkx_err_int_t
#define bustype_CAVM_LBKX_ERR_INT(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_ERR_INT(a) "LBKX_ERR_INT"
#define device_bar_CAVM_LBKX_ERR_INT(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_ERR_INT(a) (a)
#define arguments_CAVM_LBKX_ERR_INT(a) (a),-1,-1,-1

/**
 * Register (RSL) lbk#_err_int_ena_w1c
 *
 * Loopback Error Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_lbkx_err_int_ena_w1c
{
    uint64_t u;
    struct cavm_lbkx_err_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[CHAN_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[CHAN_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[DAT_OFLOW]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[DAT_DBE]. */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[DAT_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[DAT_SBE]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[DAT_DBE]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[DAT_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[CHAN_UFLOW]. */
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for LBK(0..3)_ERR_INT[CHAN_OFLOW]. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    struct cavm_lbkx_err_int_ena_w1c_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[CHAN_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[CHAN_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[DAT_OFLOW]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[DAT_DBE]. */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[DAT_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[DAT_SBE]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[DAT_DBE]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[DAT_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[CHAN_UFLOW]. */
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for LBK(0)_ERR_INT[CHAN_OFLOW]. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct cavm_lbkx_err_int_ena_w1c_s cn83xx; */
};
typedef union cavm_lbkx_err_int_ena_w1c cavm_lbkx_err_int_ena_w1c_t;

static inline uint64_t CAVM_LBKX_ERR_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_ERR_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000050ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000050ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_ERR_INT_ENA_W1C", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_ERR_INT_ENA_W1C(a) cavm_lbkx_err_int_ena_w1c_t
#define bustype_CAVM_LBKX_ERR_INT_ENA_W1C(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_ERR_INT_ENA_W1C(a) "LBKX_ERR_INT_ENA_W1C"
#define device_bar_CAVM_LBKX_ERR_INT_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_ERR_INT_ENA_W1C(a) (a)
#define arguments_CAVM_LBKX_ERR_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) lbk#_err_int_ena_w1s
 *
 * Loopback Error Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_lbkx_err_int_ena_w1s
{
    uint64_t u;
    struct cavm_lbkx_err_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[CHAN_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[CHAN_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[DAT_OFLOW]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[DAT_DBE]. */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[DAT_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[DAT_SBE]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[DAT_DBE]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[DAT_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[CHAN_UFLOW]. */
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for LBK(0..3)_ERR_INT[CHAN_OFLOW]. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    struct cavm_lbkx_err_int_ena_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[CHAN_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[CHAN_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[DAT_OFLOW]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[DAT_DBE]. */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[DAT_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[DAT_SBE]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[DAT_DBE]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[DAT_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[CHAN_UFLOW]. */
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for LBK(0)_ERR_INT[CHAN_OFLOW]. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct cavm_lbkx_err_int_ena_w1s_s cn83xx; */
};
typedef union cavm_lbkx_err_int_ena_w1s cavm_lbkx_err_int_ena_w1s_t;

static inline uint64_t CAVM_LBKX_ERR_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_ERR_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000058ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000058ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_ERR_INT_ENA_W1S", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_ERR_INT_ENA_W1S(a) cavm_lbkx_err_int_ena_w1s_t
#define bustype_CAVM_LBKX_ERR_INT_ENA_W1S(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_ERR_INT_ENA_W1S(a) "LBKX_ERR_INT_ENA_W1S"
#define device_bar_CAVM_LBKX_ERR_INT_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_ERR_INT_ENA_W1S(a) (a)
#define arguments_CAVM_LBKX_ERR_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) lbk#_err_int_w1s
 *
 * Loopback Error Interrupt Set Register
 * This register sets interrupt bits.
 */
union cavm_lbkx_err_int_w1s
{
    uint64_t u;
    struct cavm_lbkx_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[CHAN_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[CHAN_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[DAT_OFLOW]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[DAT_DBE]. */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[DAT_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[DAT_SBE]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[DAT_DBE]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[DAT_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[CHAN_UFLOW]. */
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets LBK(0..3)_ERR_INT[CHAN_OFLOW]. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    struct cavm_lbkx_err_int_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets LBK(0)_ERR_INT[CHAN_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets LBK(0)_ERR_INT[CHAN_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets LBK(0)_ERR_INT[DAT_OFLOW]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1S/H) Reads or sets LBK(0)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets LBK(0)_ERR_INT[DAT_DBE]. */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets LBK(0)_ERR_INT[DAT_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t dat_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets LBK(0)_ERR_INT[DAT_SBE]. */
        uint64_t dat_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets LBK(0)_ERR_INT[DAT_DBE]. */
        uint64_t dat_uflow             : 1;  /**< [  2:  2](R/W1S/H) Reads or sets LBK(0)_ERR_INT[DAT_UFLOW]. */
        uint64_t dat_oflow             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets LBK(0)_ERR_INT[DAT_OFLOW]. */
        uint64_t chan_uflow            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets LBK(0)_ERR_INT[CHAN_UFLOW]. */
        uint64_t chan_oflow            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets LBK(0)_ERR_INT[CHAN_OFLOW]. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct cavm_lbkx_err_int_w1s_s cn83xx; */
};
typedef union cavm_lbkx_err_int_w1s cavm_lbkx_err_int_w1s_t;

static inline uint64_t CAVM_LBKX_ERR_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_ERR_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000048ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000048ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_ERR_INT_W1S", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_ERR_INT_W1S(a) cavm_lbkx_err_int_w1s_t
#define bustype_CAVM_LBKX_ERR_INT_W1S(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_ERR_INT_W1S(a) "LBKX_ERR_INT_W1S"
#define device_bar_CAVM_LBKX_ERR_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_ERR_INT_W1S(a) (a)
#define arguments_CAVM_LBKX_ERR_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) lbk#_msix_pba#
 *
 * LBK MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the LBK_INT_VEC_E enumeration.
 */
union cavm_lbkx_msix_pbax
{
    uint64_t u;
    struct cavm_lbkx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated LBK()_MSIX_VEC()_CTL, enumerated by
                                                                 LBK_INT_VEC_E. Bits that have no associated LBK_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated LBK()_MSIX_VEC()_CTL, enumerated by
                                                                 LBK_INT_VEC_E. Bits that have no associated LBK_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lbkx_msix_pbax_s cn; */
};
typedef union cavm_lbkx_msix_pbax cavm_lbkx_msix_pbax_t;

static inline uint64_t CAVM_LBKX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x87e018ff0000ll + 0x1000000ll * ((a) & 0x0) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b==0)))
        return 0x87e018ff0000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x0);
    __cavm_csr_fatal("LBKX_MSIX_PBAX", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_MSIX_PBAX(a,b) cavm_lbkx_msix_pbax_t
#define bustype_CAVM_LBKX_MSIX_PBAX(a,b) CSR_TYPE_RSL
#define basename_CAVM_LBKX_MSIX_PBAX(a,b) "LBKX_MSIX_PBAX"
#define device_bar_CAVM_LBKX_MSIX_PBAX(a,b) 0x4 /* PF_BAR4 */
#define busnum_CAVM_LBKX_MSIX_PBAX(a,b) (a)
#define arguments_CAVM_LBKX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lbk#_msix_vec#_addr
 *
 * LBK MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the LBK_INT_VEC_E enumeration.
 */
union cavm_lbkx_msix_vecx_addr
{
    uint64_t u;
    struct cavm_lbkx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's LBK()_MSIX_VEC()_ADDR, LBK()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of LBK()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_LBK_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's LBK()_MSIX_VEC()_ADDR, LBK()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of LBK()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_LBK_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lbkx_msix_vecx_addr_s cn; */
};
typedef union cavm_lbkx_msix_vecx_addr cavm_lbkx_msix_vecx_addr_t;

static inline uint64_t CAVM_LBKX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x87e018f00000ll + 0x1000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b==0)))
        return 0x87e018f00000ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x0);
    __cavm_csr_fatal("LBKX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_MSIX_VECX_ADDR(a,b) cavm_lbkx_msix_vecx_addr_t
#define bustype_CAVM_LBKX_MSIX_VECX_ADDR(a,b) CSR_TYPE_RSL
#define basename_CAVM_LBKX_MSIX_VECX_ADDR(a,b) "LBKX_MSIX_VECX_ADDR"
#define device_bar_CAVM_LBKX_MSIX_VECX_ADDR(a,b) 0x4 /* PF_BAR4 */
#define busnum_CAVM_LBKX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_CAVM_LBKX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lbk#_msix_vec#_ctl
 *
 * LBK MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the LBK_INT_VEC_E enumeration.
 */
union cavm_lbkx_msix_vecx_ctl
{
    uint64_t u;
    struct cavm_lbkx_msix_vecx_ctl_s
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
    /* struct cavm_lbkx_msix_vecx_ctl_s cn; */
};
typedef union cavm_lbkx_msix_vecx_ctl cavm_lbkx_msix_vecx_ctl_t;

static inline uint64_t CAVM_LBKX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b==0)))
        return 0x87e018f00008ll + 0x1000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b==0)))
        return 0x87e018f00008ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x0);
    __cavm_csr_fatal("LBKX_MSIX_VECX_CTL", 2, a, b, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_MSIX_VECX_CTL(a,b) cavm_lbkx_msix_vecx_ctl_t
#define bustype_CAVM_LBKX_MSIX_VECX_CTL(a,b) CSR_TYPE_RSL
#define basename_CAVM_LBKX_MSIX_VECX_CTL(a,b) "LBKX_MSIX_VECX_CTL"
#define device_bar_CAVM_LBKX_MSIX_VECX_CTL(a,b) 0x4 /* PF_BAR4 */
#define busnum_CAVM_LBKX_MSIX_VECX_CTL(a,b) (a)
#define arguments_CAVM_LBKX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) lbk#_sft_rst
 *
 * Loopback Reset Register
 */
union cavm_lbkx_sft_rst
{
    uint64_t u;
    struct cavm_lbkx_sft_rst_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset. When set, causes a reset of LBK, excluding RSL. */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset. When set, causes a reset of LBK, excluding RSL. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_lbkx_sft_rst_s cn; */
};
typedef union cavm_lbkx_sft_rst cavm_lbkx_sft_rst_t;

static inline uint64_t CAVM_LBKX_SFT_RST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_LBKX_SFT_RST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e018000000ll + 0x1000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e018000000ll + 0x1000000ll * ((a) & 0x3);
    __cavm_csr_fatal("LBKX_SFT_RST", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_LBKX_SFT_RST(a) cavm_lbkx_sft_rst_t
#define bustype_CAVM_LBKX_SFT_RST(a) CSR_TYPE_RSL
#define basename_CAVM_LBKX_SFT_RST(a) "LBKX_SFT_RST"
#define device_bar_CAVM_LBKX_SFT_RST(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_LBKX_SFT_RST(a) (a)
#define arguments_CAVM_LBKX_SFT_RST(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_LBK_H__ */
