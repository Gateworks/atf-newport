#ifndef __CAVM_CSRS_ETF_VERTICAL_H__
#define __CAVM_CSRS_ETF_VERTICAL_H__
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
 * OcteonTX ETF_VERTICAL.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL32b) etf_vertical#_authstatus
 *
 * ETF Vertical Authstatus Register
 * Reports the current status of the authentication control signals.
 */
union cavm_etf_verticalx_authstatus
{
    uint32_t u;
    struct cavm_etf_verticalx_authstatus_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 20; /**< [ 31: 12](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t hnid                  : 2;  /**< [ 11: 10](RO) Hypervisor non-invasive debug. */
        uint32_t hid                   : 2;  /**< [  9:  8](RO) Hypervisor invasive debug. */
        uint32_t snid                  : 2;  /**< [  7:  6](RO) Secure non-invasive debug. */
        uint32_t sid                   : 2;  /**< [  5:  4](RO) Secure invasive debug. */
        uint32_t nsnid                 : 2;  /**< [  3:  2](RO) Non-secure non-invasive debug. */
        uint32_t nsid                  : 2;  /**< [  1:  0](RO) Non-secure invasive debug. */
#else /* Word 0 - Little Endian */
        uint32_t nsid                  : 2;  /**< [  1:  0](RO) Non-secure invasive debug. */
        uint32_t nsnid                 : 2;  /**< [  3:  2](RO) Non-secure non-invasive debug. */
        uint32_t sid                   : 2;  /**< [  5:  4](RO) Secure invasive debug. */
        uint32_t snid                  : 2;  /**< [  7:  6](RO) Secure non-invasive debug. */
        uint32_t hid                   : 2;  /**< [  9:  8](RO) Hypervisor invasive debug. */
        uint32_t hnid                  : 2;  /**< [ 11: 10](RO) Hypervisor non-invasive debug. */
        uint32_t res0_0                : 20; /**< [ 31: 12](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_authstatus_s cn; */
};
typedef union cavm_etf_verticalx_authstatus cavm_etf_verticalx_authstatus_t;

static inline uint64_t CAVM_ETF_VERTICALX_AUTHSTATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_AUTHSTATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fb8ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_AUTHSTATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_AUTHSTATUS(a) cavm_etf_verticalx_authstatus_t
#define bustype_CAVM_ETF_VERTICALX_AUTHSTATUS(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_AUTHSTATUS(a) "ETF_VERTICALX_AUTHSTATUS"
#define busnum_CAVM_ETF_VERTICALX_AUTHSTATUS(a) (a)
#define arguments_CAVM_ETF_VERTICALX_AUTHSTATUS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_bufwm
 *
 * ETF Vertical Bufwm Register
 * The value that is programmed into this register indicates the desired threshold
 * vacancy level in 32-bit words in the trace memory. When the available space in the
 * FIFO is less than or equal to this value, that is, fill level \>= (MEM_SIZE - BUFWM),
 * the full output is asserted and the STS.Full bit is set. This register is used only
 * in the FIFO modes, that is, SWF1, SWF2, and HWF modes. In CB mode, the same
 * functionality is obtained by programming the RWP to the desired vacancy trigger
 * level, so that when the pointer wraps around, the full output gets asserted
 * indicating that the vacancy level has fallen below the desired level. Reading this
 * register returns the programmed value. The maximum value that can be written into
 * this register is MEM_SIZE - 1, in which case the full output is asserted after the
 * first 32-bit word is written to trace memory. Writing to this register other than
 * when in Disabled state results in UNPREDICTABLE behavior. Any software using it must
 * program it with an initial value before setting the CTL.TraceCaptEn bit to 1.
 */
union cavm_etf_verticalx_bufwm
{
    uint32_t u;
    struct cavm_etf_verticalx_bufwm_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 20; /**< [ 31: 12](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t bufwm                 : 12; /**< [ 11:  0](R/W) Buffer Level Watermark. Indicates the desired threshold vacancy level in 32-bit
                                                                 words in the trace memory. The width of the register is log2(MEM_SIZE). */
#else /* Word 0 - Little Endian */
        uint32_t bufwm                 : 12; /**< [ 11:  0](R/W) Buffer Level Watermark. Indicates the desired threshold vacancy level in 32-bit
                                                                 words in the trace memory. The width of the register is log2(MEM_SIZE). */
        uint32_t razwi_0               : 20; /**< [ 31: 12](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_bufwm_s cn; */
};
typedef union cavm_etf_verticalx_bufwm cavm_etf_verticalx_bufwm_t;

static inline uint64_t CAVM_ETF_VERTICALX_BUFWM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_BUFWM(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103034ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_BUFWM", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_BUFWM(a) cavm_etf_verticalx_bufwm_t
#define bustype_CAVM_ETF_VERTICALX_BUFWM(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_BUFWM(a) "ETF_VERTICALX_BUFWM"
#define busnum_CAVM_ETF_VERTICALX_BUFWM(a) (a)
#define arguments_CAVM_ETF_VERTICALX_BUFWM(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_cbuflevel
 *
 * ETF Vertical Cbuflevel Register
 * The CBUFLEVEL register indicates the current fill level of the trace memory in units
 * of 32-bit words. When the TMC leaves Disabled state, this register dynamically
 * indicates the current fill level of trace memory. It retains its value on entering
 * Disabled state. It is not affected by the reprogramming of pointer registers in
 * Disabled state. However, RRD reads when using the Circular Buffer in Disabled state
 * are a special case. In this case the register indicates the updated fill level on
 * RRD reads.
 */
union cavm_etf_verticalx_cbuflevel
{
    uint32_t u;
    struct cavm_etf_verticalx_cbuflevel_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 19; /**< [ 31: 13](RO) Read-As-Zero, Writes Ignored. */
        uint32_t cbuflevel             : 13; /**< [ 12:  0](RO) Current Buffer Fill Level. Indicates the current fill level of the trace memory
                                                                 in 32-bit words. The width of the register is 1 + log2(MEM_SIZE). */
#else /* Word 0 - Little Endian */
        uint32_t cbuflevel             : 13; /**< [ 12:  0](RO) Current Buffer Fill Level. Indicates the current fill level of the trace memory
                                                                 in 32-bit words. The width of the register is 1 + log2(MEM_SIZE). */
        uint32_t razwi_0               : 19; /**< [ 31: 13](RO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_cbuflevel_s cn; */
};
typedef union cavm_etf_verticalx_cbuflevel cavm_etf_verticalx_cbuflevel_t;

static inline uint64_t CAVM_ETF_VERTICALX_CBUFLEVEL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_CBUFLEVEL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103030ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_CBUFLEVEL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_CBUFLEVEL(a) cavm_etf_verticalx_cbuflevel_t
#define bustype_CAVM_ETF_VERTICALX_CBUFLEVEL(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_CBUFLEVEL(a) "ETF_VERTICALX_CBUFLEVEL"
#define busnum_CAVM_ETF_VERTICALX_CBUFLEVEL(a) (a)
#define arguments_CAVM_ETF_VERTICALX_CBUFLEVEL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_cidr0
 *
 * ETF Vertical Cidr0 Register
 * The CIDR0 register is part of the set of component identification registers.
 */
union cavm_etf_verticalx_cidr0
{
    uint32_t u;
    struct cavm_etf_verticalx_cidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t prmbl_0               : 8;  /**< [  7:  0](RO) Preamble. Returns 0x0D. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_0               : 8;  /**< [  7:  0](RO) Preamble. Returns 0x0D. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_cidr0_s cn; */
};
typedef union cavm_etf_verticalx_cidr0 cavm_etf_verticalx_cidr0_t;

static inline uint64_t CAVM_ETF_VERTICALX_CIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_CIDR0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ff0ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_CIDR0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_CIDR0(a) cavm_etf_verticalx_cidr0_t
#define bustype_CAVM_ETF_VERTICALX_CIDR0(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_CIDR0(a) "ETF_VERTICALX_CIDR0"
#define busnum_CAVM_ETF_VERTICALX_CIDR0(a) (a)
#define arguments_CAVM_ETF_VERTICALX_CIDR0(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_cidr1
 *
 * ETF Vertical Cidr1 Register
 * The CIDR1 register is part of the set of component identification registers.
 */
union cavm_etf_verticalx_cidr1
{
    uint32_t u;
    struct cavm_etf_verticalx_cidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t class_f               : 4;  /**< [  7:  4](RO) Component class. Returns 0x9, indicating this is a CoreSight component. */
        uint32_t prmbl_1               : 4;  /**< [  3:  0](RO) Preamble. Returns 0x0. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_1               : 4;  /**< [  3:  0](RO) Preamble. Returns 0x0. */
        uint32_t class_f               : 4;  /**< [  7:  4](RO) Component class. Returns 0x9, indicating this is a CoreSight component. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_cidr1_s cn; */
};
typedef union cavm_etf_verticalx_cidr1 cavm_etf_verticalx_cidr1_t;

static inline uint64_t CAVM_ETF_VERTICALX_CIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_CIDR1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ff4ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_CIDR1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_CIDR1(a) cavm_etf_verticalx_cidr1_t
#define bustype_CAVM_ETF_VERTICALX_CIDR1(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_CIDR1(a) "ETF_VERTICALX_CIDR1"
#define busnum_CAVM_ETF_VERTICALX_CIDR1(a) (a)
#define arguments_CAVM_ETF_VERTICALX_CIDR1(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_cidr2
 *
 * ETF Vertical Cidr2 Register
 * The CIDR2 register is part of the set of component identification registers.
 */
union cavm_etf_verticalx_cidr2
{
    uint32_t u;
    struct cavm_etf_verticalx_cidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t prmbl_2               : 8;  /**< [  7:  0](RO) Preamble. Returns 0x05. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_2               : 8;  /**< [  7:  0](RO) Preamble. Returns 0x05. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_cidr2_s cn; */
};
typedef union cavm_etf_verticalx_cidr2 cavm_etf_verticalx_cidr2_t;

static inline uint64_t CAVM_ETF_VERTICALX_CIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_CIDR2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ff8ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_CIDR2", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_CIDR2(a) cavm_etf_verticalx_cidr2_t
#define bustype_CAVM_ETF_VERTICALX_CIDR2(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_CIDR2(a) "ETF_VERTICALX_CIDR2"
#define busnum_CAVM_ETF_VERTICALX_CIDR2(a) (a)
#define arguments_CAVM_ETF_VERTICALX_CIDR2(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_cidr3
 *
 * ETF Vertical Cidr3 Register
 * The CIDR3 register is part of the set of component identification registers.
 */
union cavm_etf_verticalx_cidr3
{
    uint32_t u;
    struct cavm_etf_verticalx_cidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t prmbl_3               : 8;  /**< [  7:  0](RO) Preamble. Returns 0xB1. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_3               : 8;  /**< [  7:  0](RO) Preamble. Returns 0xB1. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_cidr3_s cn; */
};
typedef union cavm_etf_verticalx_cidr3 cavm_etf_verticalx_cidr3_t;

static inline uint64_t CAVM_ETF_VERTICALX_CIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_CIDR3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ffcll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_CIDR3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_CIDR3(a) cavm_etf_verticalx_cidr3_t
#define bustype_CAVM_ETF_VERTICALX_CIDR3(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_CIDR3(a) "ETF_VERTICALX_CIDR3"
#define busnum_CAVM_ETF_VERTICALX_CIDR3(a) (a)
#define arguments_CAVM_ETF_VERTICALX_CIDR3(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_claimclr
 *
 * ETF Vertical Claimclr Register
 * This register forms one half of the claim tag value. On writes, this location
 * enables individual bits to be cleared. On reads, it returns the current claim tag
 * value.
 */
union cavm_etf_verticalx_claimclr
{
    uint32_t u;
    struct cavm_etf_verticalx_claimclr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 28; /**< [ 31:  4](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t clr                   : 4;  /**< [  3:  0](R/W) A bit-programmable register bank that clears the claim tag value. It is zero at
                                                                 reset. It is used by software agents to signal to each other ownership of the
                                                                 hardware. It has no direct effect on the hardware itself. */
#else /* Word 0 - Little Endian */
        uint32_t clr                   : 4;  /**< [  3:  0](R/W) A bit-programmable register bank that clears the claim tag value. It is zero at
                                                                 reset. It is used by software agents to signal to each other ownership of the
                                                                 hardware. It has no direct effect on the hardware itself. */
        uint32_t razwi_0               : 28; /**< [ 31:  4](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_claimclr_s cn; */
};
typedef union cavm_etf_verticalx_claimclr cavm_etf_verticalx_claimclr_t;

static inline uint64_t CAVM_ETF_VERTICALX_CLAIMCLR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_CLAIMCLR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fa4ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_CLAIMCLR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_CLAIMCLR(a) cavm_etf_verticalx_claimclr_t
#define bustype_CAVM_ETF_VERTICALX_CLAIMCLR(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_CLAIMCLR(a) "ETF_VERTICALX_CLAIMCLR"
#define busnum_CAVM_ETF_VERTICALX_CLAIMCLR(a) (a)
#define arguments_CAVM_ETF_VERTICALX_CLAIMCLR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_claimset
 *
 * ETF Vertical Claimset Register
 * This register forms one half of the claim tag value. On writes, this location
 * enables individual bits to be set. On reads, it returns the number of bits that can
 * be set.
 */
union cavm_etf_verticalx_claimset
{
    uint32_t u;
    struct cavm_etf_verticalx_claimset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 28; /**< [ 31:  4](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t set                   : 4;  /**< [  3:  0](R/W) A bit-programmable register bank that sets the claim tag value. A read returns a
                                                                 logic 1 for all implemented locations. */
#else /* Word 0 - Little Endian */
        uint32_t set                   : 4;  /**< [  3:  0](R/W) A bit-programmable register bank that sets the claim tag value. A read returns a
                                                                 logic 1 for all implemented locations. */
        uint32_t razwi_0               : 28; /**< [ 31:  4](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_claimset_s cn; */
};
typedef union cavm_etf_verticalx_claimset cavm_etf_verticalx_claimset_t;

static inline uint64_t CAVM_ETF_VERTICALX_CLAIMSET(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_CLAIMSET(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fa0ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_CLAIMSET", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_CLAIMSET(a) cavm_etf_verticalx_claimset_t
#define bustype_CAVM_ETF_VERTICALX_CLAIMSET(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_CLAIMSET(a) "ETF_VERTICALX_CLAIMSET"
#define busnum_CAVM_ETF_VERTICALX_CLAIMSET(a) (a)
#define arguments_CAVM_ETF_VERTICALX_CLAIMSET(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_ctl
 *
 * ETF Vertical Ctl Register
 * This register controls trace stream capture. Setting the CTL.TraceCaptEn bit to 1
 * enables the TMC to capture the trace data. When trace capture is enabled, the
 * formatter behavior is controlled by the FFCR register.
 */
union cavm_etf_verticalx_ctl
{
    uint32_t u;
    struct cavm_etf_verticalx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 31; /**< [ 31:  1](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t tracecapten           : 1;  /**< [  0:  0](R/W) Trace capture enable. */
#else /* Word 0 - Little Endian */
        uint32_t tracecapten           : 1;  /**< [  0:  0](R/W) Trace capture enable. */
        uint32_t razwi_0               : 31; /**< [ 31:  1](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_ctl_s cn; */
};
typedef union cavm_etf_verticalx_ctl cavm_etf_verticalx_ctl_t;

static inline uint64_t CAVM_ETF_VERTICALX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_CTL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103020ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_CTL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_CTL(a) cavm_etf_verticalx_ctl_t
#define bustype_CAVM_ETF_VERTICALX_CTL(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_CTL(a) "ETF_VERTICALX_CTL"
#define busnum_CAVM_ETF_VERTICALX_CTL(a) (a)
#define arguments_CAVM_ETF_VERTICALX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_devid
 *
 * ETF Vertical Devid Register
 * This register is IMPLEMENTATION DEFINED for each Part Number and Designer. The
 * register indicates the capabilities of the component.
 */
union cavm_etf_verticalx_devid
{
    uint32_t u;
    struct cavm_etf_verticalx_devid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 21; /**< [ 31: 11](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t memwidth              : 3;  /**< [ 10:  8](RO) This value is twice ATB_DATA_WIDTH. */
        uint32_t configtype            : 2;  /**< [  7:  6](RO) Returns 0x2, indicating ETF configuration. */
        uint32_t clkscheme             : 1;  /**< [  5:  5](RO) RAM Clocking Scheme. This value indicates the TMC RAM clocking scheme used, that
                                                                 is, whether the TMC RAM operates synchronously or asynchronously to the TMC
                                                                 clock. Fixed to 0 indicating that TMC RAM clock is synchronous to the clk input. */
        uint32_t atbinportcount        : 5;  /**< [  4:  0](RO) Hidden Level of ATB input multiplexing. This value indicates the type/number of
                                                                 ATB multiplexing present on the input ATB. Fixed to 0x00 indicating that no
                                                                 multiplexing is present. */
#else /* Word 0 - Little Endian */
        uint32_t atbinportcount        : 5;  /**< [  4:  0](RO) Hidden Level of ATB input multiplexing. This value indicates the type/number of
                                                                 ATB multiplexing present on the input ATB. Fixed to 0x00 indicating that no
                                                                 multiplexing is present. */
        uint32_t clkscheme             : 1;  /**< [  5:  5](RO) RAM Clocking Scheme. This value indicates the TMC RAM clocking scheme used, that
                                                                 is, whether the TMC RAM operates synchronously or asynchronously to the TMC
                                                                 clock. Fixed to 0 indicating that TMC RAM clock is synchronous to the clk input. */
        uint32_t configtype            : 2;  /**< [  7:  6](RO) Returns 0x2, indicating ETF configuration. */
        uint32_t memwidth              : 3;  /**< [ 10:  8](RO) This value is twice ATB_DATA_WIDTH. */
        uint32_t res0_0                : 21; /**< [ 31: 11](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_devid_s cn; */
};
typedef union cavm_etf_verticalx_devid cavm_etf_verticalx_devid_t;

static inline uint64_t CAVM_ETF_VERTICALX_DEVID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_DEVID(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fc8ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_DEVID", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_DEVID(a) cavm_etf_verticalx_devid_t
#define bustype_CAVM_ETF_VERTICALX_DEVID(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_DEVID(a) "ETF_VERTICALX_DEVID"
#define busnum_CAVM_ETF_VERTICALX_DEVID(a) (a)
#define arguments_CAVM_ETF_VERTICALX_DEVID(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_devid1
 *
 * ETF Vertical Devid1 Register
 * Contains an IMPLEMENTATION DEFINED value.
 */
union cavm_etf_verticalx_devid1
{
    uint32_t u;
    struct cavm_etf_verticalx_devid1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 31; /**< [ 31:  1](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t rmc                   : 1;  /**< [  0:  0](RO) Register management mode. TMC implements register management mode 1. */
#else /* Word 0 - Little Endian */
        uint32_t rmc                   : 1;  /**< [  0:  0](RO) Register management mode. TMC implements register management mode 1. */
        uint32_t res0_0                : 31; /**< [ 31:  1](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_devid1_s cn; */
};
typedef union cavm_etf_verticalx_devid1 cavm_etf_verticalx_devid1_t;

static inline uint64_t CAVM_ETF_VERTICALX_DEVID1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_DEVID1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fc4ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_DEVID1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_DEVID1(a) cavm_etf_verticalx_devid1_t
#define bustype_CAVM_ETF_VERTICALX_DEVID1(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_DEVID1(a) "ETF_VERTICALX_DEVID1"
#define busnum_CAVM_ETF_VERTICALX_DEVID1(a) (a)
#define arguments_CAVM_ETF_VERTICALX_DEVID1(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_devtype
 *
 * ETF Vertical Devtype Register
 * A debugger can use this register to get information about a component that has an
 * unrecognized Part number.
 */
union cavm_etf_verticalx_devtype
{
    uint32_t u;
    struct cavm_etf_verticalx_devtype_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t sub                   : 4;  /**< [  7:  4](RO) Minor classification. Returns 0x3, indicating this component is a FIFO. */
        uint32_t major                 : 4;  /**< [  3:  0](RO) Major classification. Returns 0x2, indicating this component is a Trace Link. */
#else /* Word 0 - Little Endian */
        uint32_t major                 : 4;  /**< [  3:  0](RO) Major classification. Returns 0x2, indicating this component is a Trace Link. */
        uint32_t sub                   : 4;  /**< [  7:  4](RO) Minor classification. Returns 0x3, indicating this component is a FIFO. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_devtype_s cn; */
};
typedef union cavm_etf_verticalx_devtype cavm_etf_verticalx_devtype_t;

static inline uint64_t CAVM_ETF_VERTICALX_DEVTYPE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_DEVTYPE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fccll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_DEVTYPE", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_DEVTYPE(a) cavm_etf_verticalx_devtype_t
#define bustype_CAVM_ETF_VERTICALX_DEVTYPE(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_DEVTYPE(a) "ETF_VERTICALX_DEVTYPE"
#define busnum_CAVM_ETF_VERTICALX_DEVTYPE(a) (a)
#define arguments_CAVM_ETF_VERTICALX_DEVTYPE(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_ffcr
 *
 * ETF Vertical Ffcr Register
 * This register allows user control of the stop, trigger, and flush events.
 */
union cavm_etf_verticalx_ffcr
{
    uint32_t u;
    struct cavm_etf_verticalx_ffcr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_3               : 16; /**< [ 31: 16](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t embedflush            : 1;  /**< [ 15: 15](R/W) Embed Flush ID (flush completion packet). Enables insertion of Flush ID 0x7B
                                                                 with a single byte of data payload = 0x00 in the output trace, immediately after
                                                                 the last flush data byte, when a flush completes on the ATB slave interface.
                                                                 This bit is effective only in Normal formatting modes. In Bypass mode, the Flush
                                                                 ID insertion remains disabled and this bit is ignored. */
        uint32_t drainbuffer           : 1;  /**< [ 14: 14](R/W) Drain Buffer. This bit is used to enable draining of the trace data through the
                                                                 ATB master interface after the formatter has stopped. It is useful in CB mode to
                                                                 capture trace data into trace memory and then to drain the captured trace
                                                                 through the ATB master interface. Writing a 1 to this bit when in Stopped state
                                                                 starts the drain of the contents of trace buffer. This bit always reads as 0.
                                                                 The STS.TMCReady bit goes LOW while the drain is in progress. This bit is
                                                                 functional only when the TMC is in CB mode and formatting is enabled, that is,
                                                                 FFCR.EnFt=1. Setting this bit when the TMC is in any other mode, or when not in
                                                                 Stopped state, results in UNPREDICTABLE behavior. When trace capture is complete
                                                                 in CB mode, all of the captured trace must be retrieved from the trace memory,
                                                                 either by reading all trace data out through RRD reads, or draining all trace
                                                                 data by setting the FFCR.DrainBuffer bit. Setting this bit after some of the
                                                                 captured trace has been read out through RRD results in UNPREDICTABLE behavior. */
        uint32_t stopontrigevt         : 1;  /**< [ 13: 13](R/W) Stop On Trigger Event. If this bit is set, the formatter is stopped when a
                                                                 Trigger Event has been observed. This bit must be used only in CB mode because
                                                                 in FIFO modes, the TMC is a trace link rather than a trace sink and trigger
                                                                 events are related to trace sink functionality. If trace capture is enabled in
                                                                 SWF1, SWF2, or HWF mode with this bit set, it results in UNPREDICTABLE behavior. */
        uint32_t stoponfl              : 1;  /**< [ 12: 12](R/W) Stop On Flush. If this bit is set, the formatter is stopped on completion of a
                                                                 flush operation. The initiation of a flush operation is controlled by
                                                                 programming the register bits FFCR.FlushMan, FFCR.FOnTrigEvt, and FFCR.FOnFlIn.
                                                                 When a flush-initiation condition occurs, afvalid_s is asserted, and when the
                                                                 flush completion is received, that is, afready_s=1, trace capture is stopped.
                                                                 Any remaining data in the formatter is appended with a post-amble and written to
                                                                 trace memory. The flush operation is then complete. When the TMC is configured
                                                                 as an ETF, if a flush is initiated by the ATB Master interface, its completion
                                                                 does not lead to a formatter stop regardless of the value that is programmed in
                                                                 this bit. */
        uint32_t razwi_2               : 1;  /**< [ 11: 11](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t trigonfl              : 1;  /**< [ 10: 10](R/W) Indicate on trace stream the completion of flush. If this bit is set, a trigger
                                                                 is indicated on the trace stream when afready_s is received for a flush in
                                                                 progress. If this bit is clear, no triggers are embedded in the trace stream on
                                                                 flush completion. If Trigger Insertion is disabled, that is, FFCR.EnTI=0, then
                                                                 trigger indication on the trace stream is blocked regardless of the value that
                                                                 is programmed in this bit. When the TMC is configured as ETF, if a flush is
                                                                 initiated by the ATB Master interface, its completion does not lead to a trigger
                                                                 indication on the trace stream regardless of the value that is programmed in
                                                                 this bit. */
        uint32_t trigontrigevt         : 1;  /**< [  9:  9](R/W) Indicate on trace stream the occurrence of a Trigger Event. If this bit is set,
                                                                 a trigger is indicated on the output trace stream when a Trigger Event occurs.
                                                                 If Trigger Insertion is disabled, that is, FFCR.EnTI=0, then trigger indication
                                                                 on the trace stream is blocked regardless of the value that is programmed in
                                                                 this bit. This bit must be used only in CB mode because in FIFO modes, the TMC
                                                                 is a trace link rather than a trace sink and trigger events are related to trace
                                                                 sink functionality. If trace capture is enabled in SWF1, SWF2, or HWF mode with
                                                                 this bit set, it results in UNPREDICTABLE behavior. */
        uint32_t trigontrigin          : 1;  /**< [  8:  8](R/W) Indicate on trace stream the occurrence of a rising edge on trigin. If this bit
                                                                 is set, a trigger is indicated on the trace stream when a rising edge is
                                                                 detected on the trigin input. If Trigger Insertion is disabled, that is,
                                                                 FFCR.EnTI=0, then trigger indication on the trace stream is blocked regardless
                                                                 of the value that is programmed in this bit. */
        uint32_t razwi_1               : 1;  /**< [  7:  7](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t flushman              : 1;  /**< [  6:  6](R/W) Manually generate a flush of the system. Writing 1 to this bit causes a flush to
                                                                 be generated. This bit is cleared automatically when, in formatter bypass mode,
                                                                 afready_s was sampled high, or, in normal formatting mode, afready_s was sampled
                                                                 high and all flush data was output to the trace memory. If CTL.TraceCaptEn=0,
                                                                 writes to this bit are ignored. */
        uint32_t fontrigevt            : 1;  /**< [  5:  5](R/W) Flush on Trigger Event. Setting this bit generates a flush when a Trigger Event
                                                                 occurs. If FFCR.StopOnTrigEvt is set, this bit is ignored. This bit must be used
                                                                 only in CB mode because in FIFO modes, the TMC is a trace link rather than a
                                                                 trace sink and trigger events are related to trace sink functionality. If trace
                                                                 capture is enabled in SWF1, SWF2, or HWF mode with this bit set, it results in
                                                                 UNPREDICTABLE behavior. */
        uint32_t fonflin               : 1;  /**< [  4:  4](R/W) Setting this bit enables the detection of transitions on the flushin input by
                                                                 the TMC. If this bit is set and the formatter has not already stopped, a rising
                                                                 edge on flushin initiates a flush request. */
        uint32_t razwi_0               : 2;  /**< [  3:  2](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t enti                  : 1;  /**< [  1:  1](R/W) Enable Trigger Insertion. Setting this bit enables the insertion of triggers in
                                                                 the formatted trace stream. A trigger is indicated by inserting one byte of data
                                                                 0x00 with atid_s=0x7D in the trace stream. Trigger indication on the trace
                                                                 stream is also controlled by the register bits FFCR.TrigOnFl,
                                                                 FFCR.TrigOnTrigEvt, and FFCR.TrigOnTrigIn. This bit can only be changed when the
                                                                 TMC is in Disabled state. If FFCR.EnTI bit is set when FFCR.EnFt is 0, it
                                                                 results in formatting being enabled. */
        uint32_t enft                  : 1;  /**< [  0:  0](R/W) Enable Formatter. If this bit is set, formatting is enabled. This bit takes
                                                                 effect when not in Disabled state, and is ignored in Disabled state. If this bit
                                                                 is clear, formatting is disabled. In this case, the incoming trace data is
                                                                 assumed to be from a single trace source. If multiple trace IDs are received by
                                                                 the TMC when trace capture is enabled and the formatter is disabled, it results
                                                                 in interleaving of trace data. Disabling of formatting is deprecated, and is
                                                                 supported in the TMC for backwards-compatibility with earlier versions of the
                                                                 ETB. Therefore, disabling of formatting is supported only in CB mode. Features
                                                                 in the TMC such as the FIFO modes and the FFCR.DrainBuffer bit that are not part
                                                                 of the earlier versions of the ETB do not support disabling of formatting. This
                                                                 bit can only be changed when TMC is in Disabled state. If FFCR.EnTI bit is set
                                                                 when FFCR.EnFt is 0, it results in formatting being enabled. If the TMC is
                                                                 enabled in a mode other than Circular Buffer mode with formatting disabled, it
                                                                 results in formatting being enabled. */
#else /* Word 0 - Little Endian */
        uint32_t enft                  : 1;  /**< [  0:  0](R/W) Enable Formatter. If this bit is set, formatting is enabled. This bit takes
                                                                 effect when not in Disabled state, and is ignored in Disabled state. If this bit
                                                                 is clear, formatting is disabled. In this case, the incoming trace data is
                                                                 assumed to be from a single trace source. If multiple trace IDs are received by
                                                                 the TMC when trace capture is enabled and the formatter is disabled, it results
                                                                 in interleaving of trace data. Disabling of formatting is deprecated, and is
                                                                 supported in the TMC for backwards-compatibility with earlier versions of the
                                                                 ETB. Therefore, disabling of formatting is supported only in CB mode. Features
                                                                 in the TMC such as the FIFO modes and the FFCR.DrainBuffer bit that are not part
                                                                 of the earlier versions of the ETB do not support disabling of formatting. This
                                                                 bit can only be changed when TMC is in Disabled state. If FFCR.EnTI bit is set
                                                                 when FFCR.EnFt is 0, it results in formatting being enabled. If the TMC is
                                                                 enabled in a mode other than Circular Buffer mode with formatting disabled, it
                                                                 results in formatting being enabled. */
        uint32_t enti                  : 1;  /**< [  1:  1](R/W) Enable Trigger Insertion. Setting this bit enables the insertion of triggers in
                                                                 the formatted trace stream. A trigger is indicated by inserting one byte of data
                                                                 0x00 with atid_s=0x7D in the trace stream. Trigger indication on the trace
                                                                 stream is also controlled by the register bits FFCR.TrigOnFl,
                                                                 FFCR.TrigOnTrigEvt, and FFCR.TrigOnTrigIn. This bit can only be changed when the
                                                                 TMC is in Disabled state. If FFCR.EnTI bit is set when FFCR.EnFt is 0, it
                                                                 results in formatting being enabled. */
        uint32_t razwi_0               : 2;  /**< [  3:  2](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t fonflin               : 1;  /**< [  4:  4](R/W) Setting this bit enables the detection of transitions on the flushin input by
                                                                 the TMC. If this bit is set and the formatter has not already stopped, a rising
                                                                 edge on flushin initiates a flush request. */
        uint32_t fontrigevt            : 1;  /**< [  5:  5](R/W) Flush on Trigger Event. Setting this bit generates a flush when a Trigger Event
                                                                 occurs. If FFCR.StopOnTrigEvt is set, this bit is ignored. This bit must be used
                                                                 only in CB mode because in FIFO modes, the TMC is a trace link rather than a
                                                                 trace sink and trigger events are related to trace sink functionality. If trace
                                                                 capture is enabled in SWF1, SWF2, or HWF mode with this bit set, it results in
                                                                 UNPREDICTABLE behavior. */
        uint32_t flushman              : 1;  /**< [  6:  6](R/W) Manually generate a flush of the system. Writing 1 to this bit causes a flush to
                                                                 be generated. This bit is cleared automatically when, in formatter bypass mode,
                                                                 afready_s was sampled high, or, in normal formatting mode, afready_s was sampled
                                                                 high and all flush data was output to the trace memory. If CTL.TraceCaptEn=0,
                                                                 writes to this bit are ignored. */
        uint32_t razwi_1               : 1;  /**< [  7:  7](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t trigontrigin          : 1;  /**< [  8:  8](R/W) Indicate on trace stream the occurrence of a rising edge on trigin. If this bit
                                                                 is set, a trigger is indicated on the trace stream when a rising edge is
                                                                 detected on the trigin input. If Trigger Insertion is disabled, that is,
                                                                 FFCR.EnTI=0, then trigger indication on the trace stream is blocked regardless
                                                                 of the value that is programmed in this bit. */
        uint32_t trigontrigevt         : 1;  /**< [  9:  9](R/W) Indicate on trace stream the occurrence of a Trigger Event. If this bit is set,
                                                                 a trigger is indicated on the output trace stream when a Trigger Event occurs.
                                                                 If Trigger Insertion is disabled, that is, FFCR.EnTI=0, then trigger indication
                                                                 on the trace stream is blocked regardless of the value that is programmed in
                                                                 this bit. This bit must be used only in CB mode because in FIFO modes, the TMC
                                                                 is a trace link rather than a trace sink and trigger events are related to trace
                                                                 sink functionality. If trace capture is enabled in SWF1, SWF2, or HWF mode with
                                                                 this bit set, it results in UNPREDICTABLE behavior. */
        uint32_t trigonfl              : 1;  /**< [ 10: 10](R/W) Indicate on trace stream the completion of flush. If this bit is set, a trigger
                                                                 is indicated on the trace stream when afready_s is received for a flush in
                                                                 progress. If this bit is clear, no triggers are embedded in the trace stream on
                                                                 flush completion. If Trigger Insertion is disabled, that is, FFCR.EnTI=0, then
                                                                 trigger indication on the trace stream is blocked regardless of the value that
                                                                 is programmed in this bit. When the TMC is configured as ETF, if a flush is
                                                                 initiated by the ATB Master interface, its completion does not lead to a trigger
                                                                 indication on the trace stream regardless of the value that is programmed in
                                                                 this bit. */
        uint32_t razwi_2               : 1;  /**< [ 11: 11](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t stoponfl              : 1;  /**< [ 12: 12](R/W) Stop On Flush. If this bit is set, the formatter is stopped on completion of a
                                                                 flush operation. The initiation of a flush operation is controlled by
                                                                 programming the register bits FFCR.FlushMan, FFCR.FOnTrigEvt, and FFCR.FOnFlIn.
                                                                 When a flush-initiation condition occurs, afvalid_s is asserted, and when the
                                                                 flush completion is received, that is, afready_s=1, trace capture is stopped.
                                                                 Any remaining data in the formatter is appended with a post-amble and written to
                                                                 trace memory. The flush operation is then complete. When the TMC is configured
                                                                 as an ETF, if a flush is initiated by the ATB Master interface, its completion
                                                                 does not lead to a formatter stop regardless of the value that is programmed in
                                                                 this bit. */
        uint32_t stopontrigevt         : 1;  /**< [ 13: 13](R/W) Stop On Trigger Event. If this bit is set, the formatter is stopped when a
                                                                 Trigger Event has been observed. This bit must be used only in CB mode because
                                                                 in FIFO modes, the TMC is a trace link rather than a trace sink and trigger
                                                                 events are related to trace sink functionality. If trace capture is enabled in
                                                                 SWF1, SWF2, or HWF mode with this bit set, it results in UNPREDICTABLE behavior. */
        uint32_t drainbuffer           : 1;  /**< [ 14: 14](R/W) Drain Buffer. This bit is used to enable draining of the trace data through the
                                                                 ATB master interface after the formatter has stopped. It is useful in CB mode to
                                                                 capture trace data into trace memory and then to drain the captured trace
                                                                 through the ATB master interface. Writing a 1 to this bit when in Stopped state
                                                                 starts the drain of the contents of trace buffer. This bit always reads as 0.
                                                                 The STS.TMCReady bit goes LOW while the drain is in progress. This bit is
                                                                 functional only when the TMC is in CB mode and formatting is enabled, that is,
                                                                 FFCR.EnFt=1. Setting this bit when the TMC is in any other mode, or when not in
                                                                 Stopped state, results in UNPREDICTABLE behavior. When trace capture is complete
                                                                 in CB mode, all of the captured trace must be retrieved from the trace memory,
                                                                 either by reading all trace data out through RRD reads, or draining all trace
                                                                 data by setting the FFCR.DrainBuffer bit. Setting this bit after some of the
                                                                 captured trace has been read out through RRD results in UNPREDICTABLE behavior. */
        uint32_t embedflush            : 1;  /**< [ 15: 15](R/W) Embed Flush ID (flush completion packet). Enables insertion of Flush ID 0x7B
                                                                 with a single byte of data payload = 0x00 in the output trace, immediately after
                                                                 the last flush data byte, when a flush completes on the ATB slave interface.
                                                                 This bit is effective only in Normal formatting modes. In Bypass mode, the Flush
                                                                 ID insertion remains disabled and this bit is ignored. */
        uint32_t razwi_3               : 16; /**< [ 31: 16](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_ffcr_s cn; */
};
typedef union cavm_etf_verticalx_ffcr cavm_etf_verticalx_ffcr_t;

static inline uint64_t CAVM_ETF_VERTICALX_FFCR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_FFCR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103304ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_FFCR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_FFCR(a) cavm_etf_verticalx_ffcr_t
#define bustype_CAVM_ETF_VERTICALX_FFCR(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_FFCR(a) "ETF_VERTICALX_FFCR"
#define busnum_CAVM_ETF_VERTICALX_FFCR(a) (a)
#define arguments_CAVM_ETF_VERTICALX_FFCR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_ffsr
 *
 * ETF Vertical Ffsr Register
 * This register indicates the status of the Formatter, and the status of Flush request.
 */
union cavm_etf_verticalx_ffsr
{
    uint32_t u;
    struct cavm_etf_verticalx_ffsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 30; /**< [ 31:  2](RO) Read-As-Zero, Writes Ignored. */
        uint32_t ftstopped             : 1;  /**< [  1:  1](RO) Formatter Stopped. This bit behaves the same way as STS.FtEmpty. It is cleared
                                                                 to 0 when leaving the Disabled state and retains its value when entering the
                                                                 Disabled state. The FFCR.FtStopped bit is deprecated and is present in this
                                                                 register to support backwards-compatibility with earlier versions of the ETB. */
        uint32_t flinprog              : 1;  /**< [  0:  0](RO) Flush In Progress. This bit indicates whether the TMC is currently processing a
                                                                 flush request. In the ETB and ETR configurations, the flush initiation is
                                                                 controlled by the flush control bits in the FFCR register. This bit is cleared
                                                                 to 0 when leaving the Disabled state and retains its value when entering the
                                                                 Disabled state. When in Disabled state, this bit is not updated. */
#else /* Word 0 - Little Endian */
        uint32_t flinprog              : 1;  /**< [  0:  0](RO) Flush In Progress. This bit indicates whether the TMC is currently processing a
                                                                 flush request. In the ETB and ETR configurations, the flush initiation is
                                                                 controlled by the flush control bits in the FFCR register. This bit is cleared
                                                                 to 0 when leaving the Disabled state and retains its value when entering the
                                                                 Disabled state. When in Disabled state, this bit is not updated. */
        uint32_t ftstopped             : 1;  /**< [  1:  1](RO) Formatter Stopped. This bit behaves the same way as STS.FtEmpty. It is cleared
                                                                 to 0 when leaving the Disabled state and retains its value when entering the
                                                                 Disabled state. The FFCR.FtStopped bit is deprecated and is present in this
                                                                 register to support backwards-compatibility with earlier versions of the ETB. */
        uint32_t razwi_0               : 30; /**< [ 31:  2](RO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_ffsr_s cn; */
};
typedef union cavm_etf_verticalx_ffsr cavm_etf_verticalx_ffsr_t;

static inline uint64_t CAVM_ETF_VERTICALX_FFSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_FFSR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103300ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_FFSR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_FFSR(a) cavm_etf_verticalx_ffsr_t
#define bustype_CAVM_ETF_VERTICALX_FFSR(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_FFSR(a) "ETF_VERTICALX_FFSR"
#define busnum_CAVM_ETF_VERTICALX_FFSR(a) (a)
#define arguments_CAVM_ETF_VERTICALX_FFSR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_itatbctr0
 *
 * ETF Vertical Itatbctr0 Register
 * This register captures the values of ATB slave inputs atvalid_s, afready_s,
 * atwakeup_s, and atbytes_s in integration mode. In functional mode, this register
 * behaves as RAZ/WI. In integration mode, writes to this register are ignored and the
 * reads return the value of corresponding input pins. The width of this register is
 * given by: 8+log2(ATB DATA WIDTH/8).
 */
union cavm_etf_verticalx_itatbctr0
{
    uint32_t u;
    struct cavm_etf_verticalx_itatbctr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_1               : 22; /**< [ 31: 10](RO) Read-As-Zero, Writes Ignored. */
        uint32_t atbytess              : 2;  /**< [  9:  8](RO) Returns the value of atbytes_s input in integration mode. N=8+log2(ATB DATA WIDTH/8). */
        uint32_t razwi_0               : 5;  /**< [  7:  3](RO) Read-As-Zero, Writes Ignored. */
        uint32_t atwakeups             : 1;  /**< [  2:  2](RO) Returns the value of atwakeup_s input in integration mode. */
        uint32_t afreadys              : 1;  /**< [  1:  1](RO) Returns the value of afready_s input in integration mode. */
        uint32_t atvalids              : 1;  /**< [  0:  0](RO) Returns the value of atvalid_s input in integration mode. */
#else /* Word 0 - Little Endian */
        uint32_t atvalids              : 1;  /**< [  0:  0](RO) Returns the value of atvalid_s input in integration mode. */
        uint32_t afreadys              : 1;  /**< [  1:  1](RO) Returns the value of afready_s input in integration mode. */
        uint32_t atwakeups             : 1;  /**< [  2:  2](RO) Returns the value of atwakeup_s input in integration mode. */
        uint32_t razwi_0               : 5;  /**< [  7:  3](RO) Read-As-Zero, Writes Ignored. */
        uint32_t atbytess              : 2;  /**< [  9:  8](RO) Returns the value of atbytes_s input in integration mode. N=8+log2(ATB DATA WIDTH/8). */
        uint32_t razwi_1               : 22; /**< [ 31: 10](RO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_itatbctr0_s cn; */
};
typedef union cavm_etf_verticalx_itatbctr0 cavm_etf_verticalx_itatbctr0_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITATBCTR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITATBCTR0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ef8ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITATBCTR0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITATBCTR0(a) cavm_etf_verticalx_itatbctr0_t
#define bustype_CAVM_ETF_VERTICALX_ITATBCTR0(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITATBCTR0(a) "ETF_VERTICALX_ITATBCTR0"
#define busnum_CAVM_ETF_VERTICALX_ITATBCTR0(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITATBCTR0(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_itatbctr1
 *
 * ETF Vertical Itatbctr1 Register
 * This register captures the value of the atid_s[6:0] input in integration mode. In
 * functional mode, this register behaves as RAZ/WI. In integration mode, writes to
 * this register are ignored and the reads return the value of atid_s input.
 */
union cavm_etf_verticalx_itatbctr1
{
    uint32_t u;
    struct cavm_etf_verticalx_itatbctr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 25; /**< [ 31:  7](RO) Read-As-Zero, Writes Ignored. */
        uint32_t atids                 : 7;  /**< [  6:  0](RO) Returns the value of atid_s[6:0] input in integration mode. */
#else /* Word 0 - Little Endian */
        uint32_t atids                 : 7;  /**< [  6:  0](RO) Returns the value of atid_s[6:0] input in integration mode. */
        uint32_t razwi_0               : 25; /**< [ 31:  7](RO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_itatbctr1_s cn; */
};
typedef union cavm_etf_verticalx_itatbctr1 cavm_etf_verticalx_itatbctr1_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITATBCTR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITATBCTR1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ef4ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITATBCTR1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITATBCTR1(a) cavm_etf_verticalx_itatbctr1_t
#define bustype_CAVM_ETF_VERTICALX_ITATBCTR1(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITATBCTR1(a) "ETF_VERTICALX_ITATBCTR1"
#define busnum_CAVM_ETF_VERTICALX_ITATBCTR1(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITATBCTR1(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_itatbctr2
 *
 * ETF Vertical Itatbctr2 Register
 * This register enables control of ATB slave outputs atready_s, afvalid_s, and
 * syncreq_s in integration mode. In functional mode, this register behaves as RAZ/WI.
 * In integration mode, the value that is written to any bit of this register is driven
 * on the output pin that is controlled by that bit and the reads return 0x0.
 */
union cavm_etf_verticalx_itatbctr2
{
    uint32_t u;
    struct cavm_etf_verticalx_itatbctr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 29; /**< [ 31:  3](WO) Read-As-Zero, Writes Ignored. */
        uint32_t syncreqs              : 1;  /**< [  2:  2](WO) Controls the value of syncreq_s output in integration mode. */
        uint32_t afvalids              : 1;  /**< [  1:  1](WO) Controls the value of afvalid_s output in integration mode. */
        uint32_t atreadys              : 1;  /**< [  0:  0](WO) Controls the value of atready_s output in integration mode. */
#else /* Word 0 - Little Endian */
        uint32_t atreadys              : 1;  /**< [  0:  0](WO) Controls the value of atready_s output in integration mode. */
        uint32_t afvalids              : 1;  /**< [  1:  1](WO) Controls the value of afvalid_s output in integration mode. */
        uint32_t syncreqs              : 1;  /**< [  2:  2](WO) Controls the value of syncreq_s output in integration mode. */
        uint32_t razwi_0               : 29; /**< [ 31:  3](WO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_itatbctr2_s cn; */
};
typedef union cavm_etf_verticalx_itatbctr2 cavm_etf_verticalx_itatbctr2_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITATBCTR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITATBCTR2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ef0ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITATBCTR2", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITATBCTR2(a) cavm_etf_verticalx_itatbctr2_t
#define bustype_CAVM_ETF_VERTICALX_ITATBCTR2(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITATBCTR2(a) "ETF_VERTICALX_ITATBCTR2"
#define busnum_CAVM_ETF_VERTICALX_ITATBCTR2(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITATBCTR2(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_itatbdata0
 *
 * ETF Vertical Itatbdata0 Register
 * This register captures the value of atdata_s input in integration mode. In
 * functional mode, this register behaves as RAZ/WI. In integration mode, writes to
 * this register are ignored and the reads return the value of corresponding atdata_s
 * bits. The width of this register is given by: 1+(ATB DATA WIDTH)/8.
 */
union cavm_etf_verticalx_itatbdata0
{
    uint32_t u;
    struct cavm_etf_verticalx_itatbdata0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 27; /**< [ 31:  5](RO) Read-As-Zero, Writes Ignored. */
        uint32_t atdatasbit31          : 1;  /**< [  4:  4](RO) Returns the value of atdata_s[31] input in integration mode. */
        uint32_t atdatasbit23          : 1;  /**< [  3:  3](RO) Returns the value of atdata_s[23] input in integration mode. */
        uint32_t atdatasbit15          : 1;  /**< [  2:  2](RO) Returns the value of atdata_s[15] input in integration mode. */
        uint32_t atdatasbit7           : 1;  /**< [  1:  1](RO) Returns the value of atdata_s[7] input in integration mode. */
        uint32_t atdatasbit0           : 1;  /**< [  0:  0](RO) Returns the value of atdata_s[0] input in integration mode. */
#else /* Word 0 - Little Endian */
        uint32_t atdatasbit0           : 1;  /**< [  0:  0](RO) Returns the value of atdata_s[0] input in integration mode. */
        uint32_t atdatasbit7           : 1;  /**< [  1:  1](RO) Returns the value of atdata_s[7] input in integration mode. */
        uint32_t atdatasbit15          : 1;  /**< [  2:  2](RO) Returns the value of atdata_s[15] input in integration mode. */
        uint32_t atdatasbit23          : 1;  /**< [  3:  3](RO) Returns the value of atdata_s[23] input in integration mode. */
        uint32_t atdatasbit31          : 1;  /**< [  4:  4](RO) Returns the value of atdata_s[31] input in integration mode. */
        uint32_t razwi_0               : 27; /**< [ 31:  5](RO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_itatbdata0_s cn; */
};
typedef union cavm_etf_verticalx_itatbdata0 cavm_etf_verticalx_itatbdata0_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITATBDATA0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITATBDATA0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103eecll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITATBDATA0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITATBDATA0(a) cavm_etf_verticalx_itatbdata0_t
#define bustype_CAVM_ETF_VERTICALX_ITATBDATA0(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITATBDATA0(a) "ETF_VERTICALX_ITATBDATA0"
#define busnum_CAVM_ETF_VERTICALX_ITATBDATA0(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITATBDATA0(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_itatbmctr1
 *
 * ETF Vertical Itatbmctr1 Register
 * This register enables control of the atid_m output in integration mode. In
 * functional mode, this register behaves as RAZ/WI. In integration mode, the value
 * that is written to this register is driven on the atid_m output and the reads return
 * 0x0.
 */
union cavm_etf_verticalx_itatbmctr1
{
    uint32_t u;
    struct cavm_etf_verticalx_itatbmctr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 25; /**< [ 31:  7](WO) Read-As-Zero, Writes Ignored. */
        uint32_t atidm                 : 7;  /**< [  6:  0](WO) Controls the value of the atid_m[6:0] output in integration mode. */
#else /* Word 0 - Little Endian */
        uint32_t atidm                 : 7;  /**< [  6:  0](WO) Controls the value of the atid_m[6:0] output in integration mode. */
        uint32_t razwi_0               : 25; /**< [ 31:  7](WO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_itatbmctr1_s cn; */
};
typedef union cavm_etf_verticalx_itatbmctr1 cavm_etf_verticalx_itatbmctr1_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITATBMCTR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITATBMCTR1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ed8ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITATBMCTR1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITATBMCTR1(a) cavm_etf_verticalx_itatbmctr1_t
#define bustype_CAVM_ETF_VERTICALX_ITATBMCTR1(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITATBMCTR1(a) "ETF_VERTICALX_ITATBMCTR1"
#define busnum_CAVM_ETF_VERTICALX_ITATBMCTR1(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITATBMCTR1(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_itatbmctr2
 *
 * ETF Vertical Itatbmctr2 Register
 * This register captures the values of ATB master inputs atready_m, afvalid_m, and
 * syncreq_m in integration mode. In functional mode, this register behaves as RAZ/WI.
 */
union cavm_etf_verticalx_itatbmctr2
{
    uint32_t u;
    struct cavm_etf_verticalx_itatbmctr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 29; /**< [ 31:  3](RO) Read-As-Zero, Writes Ignored. */
        uint32_t syncreqm              : 1;  /**< [  2:  2](RO) Integration status of syncreq_m input. In integration mode, this bit latches to
                                                                 1 on a rising edge of syncreq_m input, which is cleared when this register is
                                                                 read or when integration mode is disabled. */
        uint32_t afvalidm              : 1;  /**< [  1:  1](RO) Integration status of afvalid_m input. In integration mode, writes are ignored
                                                                 and reads return the value of afvalid_m input. */
        uint32_t atreadym              : 1;  /**< [  0:  0](RO) Integration status of atready_m input. In integration mode, writes are ignored
                                                                 and reads return the value of the atready_m input. */
#else /* Word 0 - Little Endian */
        uint32_t atreadym              : 1;  /**< [  0:  0](RO) Integration status of atready_m input. In integration mode, writes are ignored
                                                                 and reads return the value of the atready_m input. */
        uint32_t afvalidm              : 1;  /**< [  1:  1](RO) Integration status of afvalid_m input. In integration mode, writes are ignored
                                                                 and reads return the value of afvalid_m input. */
        uint32_t syncreqm              : 1;  /**< [  2:  2](RO) Integration status of syncreq_m input. In integration mode, this bit latches to
                                                                 1 on a rising edge of syncreq_m input, which is cleared when this register is
                                                                 read or when integration mode is disabled. */
        uint32_t razwi_0               : 29; /**< [ 31:  3](RO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_itatbmctr2_s cn; */
};
typedef union cavm_etf_verticalx_itatbmctr2 cavm_etf_verticalx_itatbmctr2_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITATBMCTR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITATBMCTR2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ed4ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITATBMCTR2", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITATBMCTR2(a) cavm_etf_verticalx_itatbmctr2_t
#define bustype_CAVM_ETF_VERTICALX_ITATBMCTR2(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITATBMCTR2(a) "ETF_VERTICALX_ITATBMCTR2"
#define busnum_CAVM_ETF_VERTICALX_ITATBMCTR2(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITATBMCTR2(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_itatbmdata0
 *
 * ETF Vertical Itatbmdata0 Register
 * This register enables control of the atdata_m output in integration mode. In
 * functional mode, this register behaves as RAZ/WI. In integration mode, the value
 * that is written to any given bit is driven on the output pin that is controlled by
 * that bit and the reads return 0x0. The width of this register is given by 1+(ATB
 * DATA WIDTH)/8.
 */
union cavm_etf_verticalx_itatbmdata0
{
    uint32_t u;
    struct cavm_etf_verticalx_itatbmdata0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 27; /**< [ 31:  5](WO) Read-As-Zero, Writes Ignored. */
        uint32_t atdatmbit31           : 1;  /**< [  4:  4](WO) Controls the value of atdata_m[31] output in integration mode. */
        uint32_t atdatmbit23           : 1;  /**< [  3:  3](WO) Controls the value of atdata_m[23] output in integration mode. */
        uint32_t atdatmbit15           : 1;  /**< [  2:  2](WO) Controls the value of atdata_m[15] output in integration mode. */
        uint32_t atdatmbit7            : 1;  /**< [  1:  1](WO) Controls the value of atdata_m[7] output in integration mode. */
        uint32_t atdatmbit0            : 1;  /**< [  0:  0](WO) Controls the value of atdata_m[0] output in integration mode. */
#else /* Word 0 - Little Endian */
        uint32_t atdatmbit0            : 1;  /**< [  0:  0](WO) Controls the value of atdata_m[0] output in integration mode. */
        uint32_t atdatmbit7            : 1;  /**< [  1:  1](WO) Controls the value of atdata_m[7] output in integration mode. */
        uint32_t atdatmbit15           : 1;  /**< [  2:  2](WO) Controls the value of atdata_m[15] output in integration mode. */
        uint32_t atdatmbit23           : 1;  /**< [  3:  3](WO) Controls the value of atdata_m[23] output in integration mode. */
        uint32_t atdatmbit31           : 1;  /**< [  4:  4](WO) Controls the value of atdata_m[31] output in integration mode. */
        uint32_t razwi_0               : 27; /**< [ 31:  5](WO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_itatbmdata0_s cn; */
};
typedef union cavm_etf_verticalx_itatbmdata0 cavm_etf_verticalx_itatbmdata0_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITATBMDATA0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITATBMDATA0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ed0ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITATBMDATA0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITATBMDATA0(a) cavm_etf_verticalx_itatbmdata0_t
#define bustype_CAVM_ETF_VERTICALX_ITATBMDATA0(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITATBMDATA0(a) "ETF_VERTICALX_ITATBMDATA0"
#define busnum_CAVM_ETF_VERTICALX_ITATBMDATA0(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITATBMDATA0(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_itctrl
 *
 * ETF Vertical Itctrl Register
 * The Integration Mode Control register is used to enable topology detection.
 */
union cavm_etf_verticalx_itctrl
{
    uint32_t u;
    struct cavm_etf_verticalx_itctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 31; /**< [ 31:  1](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t ime                   : 1;  /**< [  0:  0](R/W) Integration Mode Enable. When set, the component enters integration mode,
                                                                 enabling topology detection or integration testing to be performed. */
#else /* Word 0 - Little Endian */
        uint32_t ime                   : 1;  /**< [  0:  0](R/W) Integration Mode Enable. When set, the component enters integration mode,
                                                                 enabling topology detection or integration testing to be performed. */
        uint32_t razwi_0               : 31; /**< [ 31:  1](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_itctrl_s cn; */
};
typedef union cavm_etf_verticalx_itctrl cavm_etf_verticalx_itctrl_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITCTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITCTRL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103f00ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITCTRL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITCTRL(a) cavm_etf_verticalx_itctrl_t
#define bustype_CAVM_ETF_VERTICALX_ITCTRL(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITCTRL(a) "ETF_VERTICALX_ITCTRL"
#define busnum_CAVM_ETF_VERTICALX_ITCTRL(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITCTRL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_itevtintr
 *
 * ETF Vertical Itevtintr Register
 * This register controls the values of event and interrupt outputs in integration
 * mode. In functional mode, this register behaves as RAZ/WI. In integration mode, the
 * value that is written to any bit of this register is driven on the output pin that
 * is controlled by that bit and the reads return 0x0.
 */
union cavm_etf_verticalx_itevtintr
{
    uint32_t u;
    struct cavm_etf_verticalx_itevtintr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 29; /**< [ 31:  3](WO) Read-As-Zero, Writes Ignored. */
        uint32_t flushcomp             : 1;  /**< [  2:  2](WO) Controls the value of flushcomp output in integration mode. */
        uint32_t full                  : 1;  /**< [  1:  1](WO) Controls the value of full output in integration mode. */
        uint32_t acqcomp               : 1;  /**< [  0:  0](WO) Controls the value of acqcomp output in integration mode. */
#else /* Word 0 - Little Endian */
        uint32_t acqcomp               : 1;  /**< [  0:  0](WO) Controls the value of acqcomp output in integration mode. */
        uint32_t full                  : 1;  /**< [  1:  1](WO) Controls the value of full output in integration mode. */
        uint32_t flushcomp             : 1;  /**< [  2:  2](WO) Controls the value of flushcomp output in integration mode. */
        uint32_t razwi_0               : 29; /**< [ 31:  3](WO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_itevtintr_s cn; */
};
typedef union cavm_etf_verticalx_itevtintr cavm_etf_verticalx_itevtintr_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITEVTINTR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITEVTINTR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ee0ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITEVTINTR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITEVTINTR(a) cavm_etf_verticalx_itevtintr_t
#define bustype_CAVM_ETF_VERTICALX_ITEVTINTR(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITEVTINTR(a) "ETF_VERTICALX_ITEVTINTR"
#define busnum_CAVM_ETF_VERTICALX_ITEVTINTR(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITEVTINTR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_ittrflin
 *
 * ETF Vertical Ittrflin Register
 * This register captures the values of the flushin and trigin inputs in integration
 * mode. In functional mode, this register behaves as RAZ/WI.
 */
union cavm_etf_verticalx_ittrflin
{
    uint32_t u;
    struct cavm_etf_verticalx_ittrflin_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 30; /**< [ 31:  2](RO) Read-As-Zero, Writes Ignored. */
        uint32_t flushin               : 1;  /**< [  1:  1](RO) Integration status of flushin input. In integration mode, this bit latches to 1
                                                                 on a rising edge of the flushin input. It is cleared when the register is read
                                                                 or when integration mode is disabled. */
        uint32_t trigin                : 1;  /**< [  0:  0](RO) Integration status of trigin input. In integration mode, this bit latches to 1
                                                                 on a rising edge of the trigin input. It is cleared when the register is read or
                                                                 when integration mode is disabled. */
#else /* Word 0 - Little Endian */
        uint32_t trigin                : 1;  /**< [  0:  0](RO) Integration status of trigin input. In integration mode, this bit latches to 1
                                                                 on a rising edge of the trigin input. It is cleared when the register is read or
                                                                 when integration mode is disabled. */
        uint32_t flushin               : 1;  /**< [  1:  1](RO) Integration status of flushin input. In integration mode, this bit latches to 1
                                                                 on a rising edge of the flushin input. It is cleared when the register is read
                                                                 or when integration mode is disabled. */
        uint32_t razwi_0               : 30; /**< [ 31:  2](RO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_ittrflin_s cn; */
};
typedef union cavm_etf_verticalx_ittrflin cavm_etf_verticalx_ittrflin_t;

static inline uint64_t CAVM_ETF_VERTICALX_ITTRFLIN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_ITTRFLIN(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103ee8ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_ITTRFLIN", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_ITTRFLIN(a) cavm_etf_verticalx_ittrflin_t
#define bustype_CAVM_ETF_VERTICALX_ITTRFLIN(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_ITTRFLIN(a) "ETF_VERTICALX_ITTRFLIN"
#define busnum_CAVM_ETF_VERTICALX_ITTRFLIN(a) (a)
#define arguments_CAVM_ETF_VERTICALX_ITTRFLIN(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_lbuflevel
 *
 * ETF Vertical Lbuflevel Register
 * Reading this register returns the maximum fill level of the trace memory in 32-bit
 * words since this register was last read. Reading this register also results in its
 * contents being updated to the current fill level. When entering Disabled state, it
 * retains its last value. While in Disabled state, reads from this register do not
 * affect its value. When exiting Disabled state, the LBUFLEVEL register is updated to
 * the current fill level.
 */
union cavm_etf_verticalx_lbuflevel
{
    uint32_t u;
    struct cavm_etf_verticalx_lbuflevel_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 19; /**< [ 31: 13](RO) Read-As-Zero, Writes Ignored. */
        uint32_t lbuflevel             : 13; /**< [ 12:  0](RO) Latched Buffer Fill Level. Indicates the maximum fill level of the trace memory
                                                                 in 32-bit words since this register was last read. The width of the register is
                                                                 1 + log2(MEM_SIZE). */
#else /* Word 0 - Little Endian */
        uint32_t lbuflevel             : 13; /**< [ 12:  0](RO) Latched Buffer Fill Level. Indicates the maximum fill level of the trace memory
                                                                 in 32-bit words since this register was last read. The width of the register is
                                                                 1 + log2(MEM_SIZE). */
        uint32_t razwi_0               : 19; /**< [ 31: 13](RO) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_lbuflevel_s cn; */
};
typedef union cavm_etf_verticalx_lbuflevel cavm_etf_verticalx_lbuflevel_t;

static inline uint64_t CAVM_ETF_VERTICALX_LBUFLEVEL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_LBUFLEVEL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e04610302cll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_LBUFLEVEL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_LBUFLEVEL(a) cavm_etf_verticalx_lbuflevel_t
#define bustype_CAVM_ETF_VERTICALX_LBUFLEVEL(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_LBUFLEVEL(a) "ETF_VERTICALX_LBUFLEVEL"
#define busnum_CAVM_ETF_VERTICALX_LBUFLEVEL(a) (a)
#define arguments_CAVM_ETF_VERTICALX_LBUFLEVEL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_mode
 *
 * ETF Vertical Mode Register
 * This register controls the TMC operating mode. The operating mode can only be
 * changed when the TMC is in Disabled state, that is, when CTL.TraceCaptEn = 0.
 * Attempting to write to this register in any other state results in UNPREDICTABLE
 * behavior. The operating mode is ignored when in Disabled state.
 */
union cavm_etf_verticalx_mode
{
    uint32_t u;
    struct cavm_etf_verticalx_mode_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_1               : 27; /**< [ 31:  5](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t stallonstop           : 1;  /**< [  4:  4](R/W) Stall On Stop. If this bit is set and the formatter stops as a result of a stop
                                                                 event, the output atready_s is de-asserted to stall the ATB interface and avoid
                                                                 loss of trace. If this bit is clear and the formatter stops as a result of a
                                                                 stop event, signal atready_s remains asserted but the TMC discards further
                                                                 incoming trace. */
        uint32_t razwi_0               : 2;  /**< [  3:  2](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t mode                  : 2;  /**< [  1:  0](R/W) Selects the operating mode. If a reserved MODE value is programmed and trace
                                                                 capture is enabled, the TMC starts to operate in SWF1 mode. However, reading the
                                                                 MODE.MODE field returns the programmed value. */
#else /* Word 0 - Little Endian */
        uint32_t mode                  : 2;  /**< [  1:  0](R/W) Selects the operating mode. If a reserved MODE value is programmed and trace
                                                                 capture is enabled, the TMC starts to operate in SWF1 mode. However, reading the
                                                                 MODE.MODE field returns the programmed value. */
        uint32_t razwi_0               : 2;  /**< [  3:  2](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t stallonstop           : 1;  /**< [  4:  4](R/W) Stall On Stop. If this bit is set and the formatter stops as a result of a stop
                                                                 event, the output atready_s is de-asserted to stall the ATB interface and avoid
                                                                 loss of trace. If this bit is clear and the formatter stops as a result of a
                                                                 stop event, signal atready_s remains asserted but the TMC discards further
                                                                 incoming trace. */
        uint32_t razwi_1               : 27; /**< [ 31:  5](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_mode_s cn; */
};
typedef union cavm_etf_verticalx_mode cavm_etf_verticalx_mode_t;

static inline uint64_t CAVM_ETF_VERTICALX_MODE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_MODE(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103028ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_MODE", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_MODE(a) cavm_etf_verticalx_mode_t
#define bustype_CAVM_ETF_VERTICALX_MODE(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_MODE(a) "ETF_VERTICALX_MODE"
#define busnum_CAVM_ETF_VERTICALX_MODE(a) (a)
#define arguments_CAVM_ETF_VERTICALX_MODE(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_pidr0
 *
 * ETF Vertical Pidr0 Register
 * The PIDR0 register is part of the set of peripheral identification registers.
 */
union cavm_etf_verticalx_pidr0
{
    uint32_t u;
    struct cavm_etf_verticalx_pidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t part_0                : 8;  /**< [  7:  0](RO) Part number (lower 8 bits). Returns 0xea, indicating TMC ETF. */
#else /* Word 0 - Little Endian */
        uint32_t part_0                : 8;  /**< [  7:  0](RO) Part number (lower 8 bits). Returns 0xea, indicating TMC ETF. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_pidr0_s cn; */
};
typedef union cavm_etf_verticalx_pidr0 cavm_etf_verticalx_pidr0_t;

static inline uint64_t CAVM_ETF_VERTICALX_PIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_PIDR0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fe0ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_PIDR0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_PIDR0(a) cavm_etf_verticalx_pidr0_t
#define bustype_CAVM_ETF_VERTICALX_PIDR0(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_PIDR0(a) "ETF_VERTICALX_PIDR0"
#define busnum_CAVM_ETF_VERTICALX_PIDR0(a) (a)
#define arguments_CAVM_ETF_VERTICALX_PIDR0(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_pidr1
 *
 * ETF Vertical Pidr1 Register
 * The PIDR1 register is part of the set of peripheral identification registers.
 */
union cavm_etf_verticalx_pidr1
{
    uint32_t u;
    struct cavm_etf_verticalx_pidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t des_0                 : 4;  /**< [  7:  4](RO) JEP106 identification code, bits[3:0]. Together, with PIDR4.DES_2 and
                                                                 PIDR2.DES_1, they indicate the designer of the component and not the
                                                                 implementer, except where the two are the same. */
        uint32_t part_1                : 4;  /**< [  3:  0](RO) Part number, bits[11:8]. Taken together with PIDR0.PART_0 it indicates the
                                                                 component. The Part Number is selected by the designer of the component. */
#else /* Word 0 - Little Endian */
        uint32_t part_1                : 4;  /**< [  3:  0](RO) Part number, bits[11:8]. Taken together with PIDR0.PART_0 it indicates the
                                                                 component. The Part Number is selected by the designer of the component. */
        uint32_t des_0                 : 4;  /**< [  7:  4](RO) JEP106 identification code, bits[3:0]. Together, with PIDR4.DES_2 and
                                                                 PIDR2.DES_1, they indicate the designer of the component and not the
                                                                 implementer, except where the two are the same. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_pidr1_s cn; */
};
typedef union cavm_etf_verticalx_pidr1 cavm_etf_verticalx_pidr1_t;

static inline uint64_t CAVM_ETF_VERTICALX_PIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_PIDR1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fe4ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_PIDR1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_PIDR1(a) cavm_etf_verticalx_pidr1_t
#define bustype_CAVM_ETF_VERTICALX_PIDR1(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_PIDR1(a) "ETF_VERTICALX_PIDR1"
#define busnum_CAVM_ETF_VERTICALX_PIDR1(a) (a)
#define arguments_CAVM_ETF_VERTICALX_PIDR1(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_pidr2
 *
 * ETF Vertical Pidr2 Register
 * The PIDR2 register is part of the set of peripheral identification registers.
 */
union cavm_etf_verticalx_pidr2
{
    uint32_t u;
    struct cavm_etf_verticalx_pidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) Revision. It is an incremental value starting at 0x0 for the first design of a
                                                                 component. See the css600 Component list in Chapter 1 for information on the RTL
                                                                 revision of the component. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) 1 - Always set. Indicates that a JEDEC assigned value is used. */
        uint32_t des_1                 : 3;  /**< [  2:  0](RO) JEP106 identification code, bits[6:4]. Together, with PIDR4.DES_2 and
                                                                 PIDR1.DES_0, they indicate the designer of the component and not the
                                                                 implementer, except where the two are the same. */
#else /* Word 0 - Little Endian */
        uint32_t des_1                 : 3;  /**< [  2:  0](RO) JEP106 identification code, bits[6:4]. Together, with PIDR4.DES_2 and
                                                                 PIDR1.DES_0, they indicate the designer of the component and not the
                                                                 implementer, except where the two are the same. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) 1 - Always set. Indicates that a JEDEC assigned value is used. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) Revision. It is an incremental value starting at 0x0 for the first design of a
                                                                 component. See the css600 Component list in Chapter 1 for information on the RTL
                                                                 revision of the component. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_pidr2_s cn; */
};
typedef union cavm_etf_verticalx_pidr2 cavm_etf_verticalx_pidr2_t;

static inline uint64_t CAVM_ETF_VERTICALX_PIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_PIDR2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fe8ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_PIDR2", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_PIDR2(a) cavm_etf_verticalx_pidr2_t
#define bustype_CAVM_ETF_VERTICALX_PIDR2(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_PIDR2(a) "ETF_VERTICALX_PIDR2"
#define busnum_CAVM_ETF_VERTICALX_PIDR2(a) (a)
#define arguments_CAVM_ETF_VERTICALX_PIDR2(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_pidr3
 *
 * ETF Vertical Pidr3 Register
 * The PIDR3 register is part of the set of peripheral identification registers.
 */
union cavm_etf_verticalx_pidr3
{
    uint32_t u;
    struct cavm_etf_verticalx_pidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) This field indicates minor errata fixes specific to this design, for example
                                                                 metal fixes after implementation. In most cases this field is 0x0. */
        uint32_t cmod                  : 4;  /**< [  3:  0](RO) Customer Modified. Where the component is reusable IP, this value indicates if
                                                                 the customer has modified the behavior of the component. In most cases this
                                                                 field is 0x0. */
#else /* Word 0 - Little Endian */
        uint32_t cmod                  : 4;  /**< [  3:  0](RO) Customer Modified. Where the component is reusable IP, this value indicates if
                                                                 the customer has modified the behavior of the component. In most cases this
                                                                 field is 0x0. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) This field indicates minor errata fixes specific to this design, for example
                                                                 metal fixes after implementation. In most cases this field is 0x0. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_pidr3_s cn; */
};
typedef union cavm_etf_verticalx_pidr3 cavm_etf_verticalx_pidr3_t;

static inline uint64_t CAVM_ETF_VERTICALX_PIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_PIDR3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fecll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_PIDR3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_PIDR3(a) cavm_etf_verticalx_pidr3_t
#define bustype_CAVM_ETF_VERTICALX_PIDR3(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_PIDR3(a) "ETF_VERTICALX_PIDR3"
#define busnum_CAVM_ETF_VERTICALX_PIDR3(a) (a)
#define arguments_CAVM_ETF_VERTICALX_PIDR3(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_pidr4
 *
 * ETF Vertical Pidr4 Register
 * The PIDR4 register is part of the set of peripheral identification registers.
 */
union cavm_etf_verticalx_pidr4
{
    uint32_t u;
    struct cavm_etf_verticalx_pidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t size                  : 4;  /**< [  7:  4](RO) Indicates the memory size that is used by this component. Returns 0 indicating
                                                                 that the component uses an UNKNOWN number of 4KB blocks. Using the SIZE field to
                                                                 indicate the size of the component is deprecated. */
        uint32_t des_2                 : 4;  /**< [  3:  0](RO) JEP106 continuation code. Together, with PIDR2.DES_1 and PIDR1.DES_0, they
                                                                 indicate the designer of the component and not the implementer, except where the
                                                                 two are the same. */
#else /* Word 0 - Little Endian */
        uint32_t des_2                 : 4;  /**< [  3:  0](RO) JEP106 continuation code. Together, with PIDR2.DES_1 and PIDR1.DES_0, they
                                                                 indicate the designer of the component and not the implementer, except where the
                                                                 two are the same. */
        uint32_t size                  : 4;  /**< [  7:  4](RO) Indicates the memory size that is used by this component. Returns 0 indicating
                                                                 that the component uses an UNKNOWN number of 4KB blocks. Using the SIZE field to
                                                                 indicate the size of the component is deprecated. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_pidr4_s cn; */
};
typedef union cavm_etf_verticalx_pidr4 cavm_etf_verticalx_pidr4_t;

static inline uint64_t CAVM_ETF_VERTICALX_PIDR4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_PIDR4(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fd0ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_PIDR4", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_PIDR4(a) cavm_etf_verticalx_pidr4_t
#define bustype_CAVM_ETF_VERTICALX_PIDR4(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_PIDR4(a) "ETF_VERTICALX_PIDR4"
#define busnum_CAVM_ETF_VERTICALX_PIDR4(a) (a)
#define arguments_CAVM_ETF_VERTICALX_PIDR4(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_pidr5
 *
 * ETF Vertical Pidr5 Register
 * The PIDR5 register is part of the set of peripheral identification registers.
 */
union cavm_etf_verticalx_pidr5
{
    uint32_t u;
    struct cavm_etf_verticalx_pidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t pidr5                 : 8;  /**< [  7:  0](RO) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t pidr5                 : 8;  /**< [  7:  0](RO) Reserved. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_pidr5_s cn; */
};
typedef union cavm_etf_verticalx_pidr5 cavm_etf_verticalx_pidr5_t;

static inline uint64_t CAVM_ETF_VERTICALX_PIDR5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_PIDR5(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fd4ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_PIDR5", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_PIDR5(a) cavm_etf_verticalx_pidr5_t
#define bustype_CAVM_ETF_VERTICALX_PIDR5(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_PIDR5(a) "ETF_VERTICALX_PIDR5"
#define busnum_CAVM_ETF_VERTICALX_PIDR5(a) (a)
#define arguments_CAVM_ETF_VERTICALX_PIDR5(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_pidr6
 *
 * ETF Vertical Pidr6 Register
 * The PIDR6 register is part of the set of peripheral identification registers.
 */
union cavm_etf_verticalx_pidr6
{
    uint32_t u;
    struct cavm_etf_verticalx_pidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t pidr6                 : 8;  /**< [  7:  0](RO) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t pidr6                 : 8;  /**< [  7:  0](RO) Reserved. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_pidr6_s cn; */
};
typedef union cavm_etf_verticalx_pidr6 cavm_etf_verticalx_pidr6_t;

static inline uint64_t CAVM_ETF_VERTICALX_PIDR6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_PIDR6(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fd8ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_PIDR6", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_PIDR6(a) cavm_etf_verticalx_pidr6_t
#define bustype_CAVM_ETF_VERTICALX_PIDR6(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_PIDR6(a) "ETF_VERTICALX_PIDR6"
#define busnum_CAVM_ETF_VERTICALX_PIDR6(a) (a)
#define arguments_CAVM_ETF_VERTICALX_PIDR6(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_pidr7
 *
 * ETF Vertical Pidr7 Register
 * The PIDR7 register is part of the set of peripheral identification registers.
 */
union cavm_etf_verticalx_pidr7
{
    uint32_t u;
    struct cavm_etf_verticalx_pidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
        uint32_t pidr7                 : 8;  /**< [  7:  0](RO) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t pidr7                 : 8;  /**< [  7:  0](RO) Reserved. */
        uint32_t res0_0                : 24; /**< [ 31:  8](RO) Reserved bit or field with Should-Be-Zero-or-Preserved (SBZP) behavior. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_pidr7_s cn; */
};
typedef union cavm_etf_verticalx_pidr7 cavm_etf_verticalx_pidr7_t;

static inline uint64_t CAVM_ETF_VERTICALX_PIDR7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_PIDR7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103fdcll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_PIDR7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_PIDR7(a) cavm_etf_verticalx_pidr7_t
#define bustype_CAVM_ETF_VERTICALX_PIDR7(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_PIDR7(a) "ETF_VERTICALX_PIDR7"
#define busnum_CAVM_ETF_VERTICALX_PIDR7(a) (a)
#define arguments_CAVM_ETF_VERTICALX_PIDR7(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_pscr
 *
 * ETF Vertical Pscr Register
 * This register determines the reload value of the Periodic Synchronization Counter.
 * This counter enables the frequency of sync packets to be optimized to the trace
 * capture buffer size. The default behavior of the counter is to generate periodic
 * synchronization requests, syncreq_s, on the ATB slave interface.
 */
union cavm_etf_verticalx_pscr
{
    uint32_t u;
    struct cavm_etf_verticalx_pscr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 27; /**< [ 31:  5](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t pscount               : 5;  /**< [  4:  0](R/W) Periodic Synchronization Count. Determines the reload value of the
                                                                 Synchronization Counter. The reload value takes effect the next time the counter
                                                                 reaches zero. When trace capture is enabled, the Synchronization Counter counts
                                                                 the number of bytes of trace data that is stored into the trace memory,
                                                                 regardless of whether the trace data has been formatted by the TMC or not, since
                                                                 the occurrence of the last sync request on the ATB slave interface. When the
                                                                 counter reaches 0, a sync request is sent on the ATB slave interface. Reads from
                                                                 this register return the reload value that is programmed in this register. This
                                                                 field resets to 0x0A, that is, the default sync period is 2^10 bytes. If a
                                                                 reserved value is programmed in this register field, the value 0x1B is used
                                                                 instead, and subsequent reads from this register also return 0x1B. The following
                                                                 constraints apply to the values written to the PSCount field: 0x0 -
                                                                 synchronization is disabled, 0x1-0x6 - reserved, 0x7-0x1B - synchronization
                                                                 period is 2^PSCount bytes. The smallest value 0x7 gives a sync period of 128
                                                                 bytes. The maximum allowed value 0x1B gives a sync period of 2^27 bytes, 0x1C-
                                                                 0x1F - reserved. */
#else /* Word 0 - Little Endian */
        uint32_t pscount               : 5;  /**< [  4:  0](R/W) Periodic Synchronization Count. Determines the reload value of the
                                                                 Synchronization Counter. The reload value takes effect the next time the counter
                                                                 reaches zero. When trace capture is enabled, the Synchronization Counter counts
                                                                 the number of bytes of trace data that is stored into the trace memory,
                                                                 regardless of whether the trace data has been formatted by the TMC or not, since
                                                                 the occurrence of the last sync request on the ATB slave interface. When the
                                                                 counter reaches 0, a sync request is sent on the ATB slave interface. Reads from
                                                                 this register return the reload value that is programmed in this register. This
                                                                 field resets to 0x0A, that is, the default sync period is 2^10 bytes. If a
                                                                 reserved value is programmed in this register field, the value 0x1B is used
                                                                 instead, and subsequent reads from this register also return 0x1B. The following
                                                                 constraints apply to the values written to the PSCount field: 0x0 -
                                                                 synchronization is disabled, 0x1-0x6 - reserved, 0x7-0x1B - synchronization
                                                                 period is 2^PSCount bytes. The smallest value 0x7 gives a sync period of 128
                                                                 bytes. The maximum allowed value 0x1B gives a sync period of 2^27 bytes, 0x1C-
                                                                 0x1F - reserved. */
        uint32_t razwi_0               : 27; /**< [ 31:  5](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_pscr_s cn; */
};
typedef union cavm_etf_verticalx_pscr cavm_etf_verticalx_pscr_t;

static inline uint64_t CAVM_ETF_VERTICALX_PSCR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_PSCR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103308ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_PSCR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_PSCR(a) cavm_etf_verticalx_pscr_t
#define bustype_CAVM_ETF_VERTICALX_PSCR(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_PSCR(a) "ETF_VERTICALX_PSCR"
#define busnum_CAVM_ETF_VERTICALX_PSCR(a) (a)
#define arguments_CAVM_ETF_VERTICALX_PSCR(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_rrd
 *
 * ETF Vertical Rrd Register
 * Reading this register allows data to be read from the trace memory. When the memory
 * width is greater than the APB width (32-bit), multiple reads to the same location
 * must be performed to get the complete memory dataword. The RRP register is
 * incremented only after the last of the required number of read accesses to fetch one
 * memory dataword completes. When the trace memory is empty, this register returns
 * 0xFFFFFFFF. This value is chosen because it cannot be generated as part of trace
 * data when the formatter is enabled.
 */
union cavm_etf_verticalx_rrd
{
    uint32_t u;
    struct cavm_etf_verticalx_rrd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t rrd                   : 32; /**< [ 31:  0](RO) Returns the data read from trace memory. */
#else /* Word 0 - Little Endian */
        uint32_t rrd                   : 32; /**< [ 31:  0](RO) Returns the data read from trace memory. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_rrd_s cn; */
};
typedef union cavm_etf_verticalx_rrd cavm_etf_verticalx_rrd_t;

static inline uint64_t CAVM_ETF_VERTICALX_RRD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_RRD(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103010ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_RRD", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_RRD(a) cavm_etf_verticalx_rrd_t
#define bustype_CAVM_ETF_VERTICALX_RRD(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_RRD(a) "ETF_VERTICALX_RRD"
#define busnum_CAVM_ETF_VERTICALX_RRD(a) (a)
#define arguments_CAVM_ETF_VERTICALX_RRD(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_rrp
 *
 * ETF Vertical Rrp Register
 * The RAM Read Pointer Register contains the value of the read pointer that is used to
 * read entries from trace memory over the APB interface. Software must program it
 * before enabling trace capture.
 */
union cavm_etf_verticalx_rrp
{
    uint32_t u;
    struct cavm_etf_verticalx_rrp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 18; /**< [ 31: 14](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t rrp                   : 14; /**< [ 13:  0](R/W) The RRP width depends on the size of trace memory and is given by log2(MEM_SIZE
                                                                 x 4). The remaining MSBs of the 32-bit register are of type RAZ/WI. */
#else /* Word 0 - Little Endian */
        uint32_t rrp                   : 14; /**< [ 13:  0](R/W) The RRP width depends on the size of trace memory and is given by log2(MEM_SIZE
                                                                 x 4). The remaining MSBs of the 32-bit register are of type RAZ/WI. */
        uint32_t razwi_0               : 18; /**< [ 31: 14](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_rrp_s cn; */
};
typedef union cavm_etf_verticalx_rrp cavm_etf_verticalx_rrp_t;

static inline uint64_t CAVM_ETF_VERTICALX_RRP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_RRP(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103014ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_RRP", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_RRP(a) cavm_etf_verticalx_rrp_t
#define bustype_CAVM_ETF_VERTICALX_RRP(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_RRP(a) "ETF_VERTICALX_RRP"
#define busnum_CAVM_ETF_VERTICALX_RRP(a) (a)
#define arguments_CAVM_ETF_VERTICALX_RRP(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_rsz
 *
 * ETF Vertical Rsz Register
 * Defines the size of trace memory in units of 32-bit words.
 */
union cavm_etf_verticalx_rsz
{
    uint32_t u;
    struct cavm_etf_verticalx_rsz_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 1;  /**< [ 31: 31](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t rsz                   : 31; /**< [ 30:  0](RO) RAM size. Indicates the size of the RAM in 32-bit words. Returns the programmed
                                                                 value on reading. For example: Returns 0x00000100 if trace memory size is 1KB,
                                                                 0x40000000 if trace memory size is 4GB. This field has the same value as the
                                                                 MEM_SIZE parameter. */
#else /* Word 0 - Little Endian */
        uint32_t rsz                   : 31; /**< [ 30:  0](RO) RAM size. Indicates the size of the RAM in 32-bit words. Returns the programmed
                                                                 value on reading. For example: Returns 0x00000100 if trace memory size is 1KB,
                                                                 0x40000000 if trace memory size is 4GB. This field has the same value as the
                                                                 MEM_SIZE parameter. */
        uint32_t razwi_0               : 1;  /**< [ 31: 31](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_rsz_s cn; */
};
typedef union cavm_etf_verticalx_rsz cavm_etf_verticalx_rsz_t;

static inline uint64_t CAVM_ETF_VERTICALX_RSZ(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_RSZ(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103004ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_RSZ", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_RSZ(a) cavm_etf_verticalx_rsz_t
#define bustype_CAVM_ETF_VERTICALX_RSZ(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_RSZ(a) "ETF_VERTICALX_RSZ"
#define busnum_CAVM_ETF_VERTICALX_RSZ(a) (a)
#define arguments_CAVM_ETF_VERTICALX_RSZ(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_rwd
 *
 * ETF Vertical Rwd Register
 * The RAM Write Data register enables testing of trace memory connectivity to the TMC.
 * When in Disabled state, a write to this register stores data at the location pointed
 * to by the RWP/RWPHI registers. When not in Disabled state, writes are ignored. When
 * the memory data width, as indicated by the DEVID.MEM_WIDTH register field, is
 * greater than 32 bits, multiple writes to this register must be performed together to
 * write a full memory width of data. For example, if the memory width is 128 bits,
 * then writes to this register must be performed 4 at a time. When a full memory width
 * of data has been written to this register, the data is written to the trace memory
 * and the RWP is incremented to the next memory word.
 */
union cavm_etf_verticalx_rwd
{
    uint32_t u;
    struct cavm_etf_verticalx_rwd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t rwd                   : 32; /**< [ 31:  0](WO) Data written to this register is placed in the trace memory. */
#else /* Word 0 - Little Endian */
        uint32_t rwd                   : 32; /**< [ 31:  0](WO) Data written to this register is placed in the trace memory. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_rwd_s cn; */
};
typedef union cavm_etf_verticalx_rwd cavm_etf_verticalx_rwd_t;

static inline uint64_t CAVM_ETF_VERTICALX_RWD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_RWD(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103024ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_RWD", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_RWD(a) cavm_etf_verticalx_rwd_t
#define bustype_CAVM_ETF_VERTICALX_RWD(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_RWD(a) "ETF_VERTICALX_RWD"
#define busnum_CAVM_ETF_VERTICALX_RWD(a) (a)
#define arguments_CAVM_ETF_VERTICALX_RWD(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_rwp
 *
 * ETF Vertical Rwp Register
 * RAM Write Pointer Register sets the write pointer that is used to write entries into
 * the trace memory. Software must program it before enabling trace capture.
 */
union cavm_etf_verticalx_rwp
{
    uint32_t u;
    struct cavm_etf_verticalx_rwp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 18; /**< [ 31: 14](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t rwp                   : 14; /**< [ 13:  0](R/W) The RWP width depends on the size of trace memory and is given by log2(MEM_SIZE
                                                                 x 4). The remaining MSBs of the 32-bit register are of type RAZ/WI. */
#else /* Word 0 - Little Endian */
        uint32_t rwp                   : 14; /**< [ 13:  0](R/W) The RWP width depends on the size of trace memory and is given by log2(MEM_SIZE
                                                                 x 4). The remaining MSBs of the 32-bit register are of type RAZ/WI. */
        uint32_t razwi_0               : 18; /**< [ 31: 14](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_rwp_s cn; */
};
typedef union cavm_etf_verticalx_rwp cavm_etf_verticalx_rwp_t;

static inline uint64_t CAVM_ETF_VERTICALX_RWP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_RWP(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e046103018ll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_RWP", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_RWP(a) cavm_etf_verticalx_rwp_t
#define bustype_CAVM_ETF_VERTICALX_RWP(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_RWP(a) "ETF_VERTICALX_RWP"
#define busnum_CAVM_ETF_VERTICALX_RWP(a) (a)
#define arguments_CAVM_ETF_VERTICALX_RWP(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_sts
 *
 * ETF Vertical Sts Register
 * Indicates the status of the Trace Memory Controller. After a reset, software must
 * ignore all the fields of this register except STS.TMCReady. The other fields have
 * meaning only when the TMC has left the Disabled state. Writes to all RO fields of
 * this register are ignored.
 */
union cavm_etf_verticalx_sts
{
    uint32_t u;
    struct cavm_etf_verticalx_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 27; /**< [ 31:  5](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t empty                 : 1;  /**< [  4:  4](RO) Trace buffer empty. If set, this bit indicates that the trace memory does not
                                                                 contain any valid trace data. However, this does not mean that the pipeline
                                                                 stages within the TMC are empty. To determine whether the internal pipeline
                                                                 stages are empty, the software must read the STS.TMCReady bit. */
        uint32_t ftempty               : 1;  /**< [  3:  3](RO) Formatter pipeline empty. This bit is deprecated and is present in this register
                                                                 to support backwards compatibility with earlier versions of the ETB. It is set
                                                                 when trace capture has stopped, and all internal pipelines and buffers have
                                                                 drained. Unlike STS.TMCReady, it is not affected by buffer drains and AXI
                                                                 accesses. It is cleared to 0 when leaving the Disabled state and retains its
                                                                 value when entering the Disabled state. */
        uint32_t tmcready              : 1;  /**< [  2:  2](RO) TMC ready. This flag is set when trace capture has stopped and all internal
                                                                 pipelines and buffers have drained, the TMC is not draining as a result of
                                                                 FFCR.DrainBuffer bit being set (ETF only), and the AXI interface is not busy and
                                                                 the response for final AXI write has been received (ETR only) are all true. This
                                                                 bit is cleared to 0 when leaving the Disabled state and retains its value when
                                                                 entering the Disabled state. */
        uint32_t triggered             : 1;  /**< [  1:  1](RO) TMC triggered. This bit is set when trace capture is in progress and the TMC has
                                                                 detected a trigger event. This bit is cleared to 0 when leaving the Disabled
                                                                 state and retains its value when entering the Disabled state. A trigger event is
                                                                 when the TMC has written a set number of data words, as programmed in the TRG
                                                                 register, into the trace memory after a rising edge of trigin input, or a
                                                                 trigger packet (atid_s = 0x7D) is received in the input trace. */
        uint32_t full                  : 1;  /**< [  0:  0](RO) Trace memory full. This bit helps in determining the amount of valid data
                                                                 present in the trace memory. It is not affected by the reprogramming of pointer
                                                                 registers in Disabled state. It is cleared when the TMC leaves Disabled state. */
#else /* Word 0 - Little Endian */
        uint32_t full                  : 1;  /**< [  0:  0](RO) Trace memory full. This bit helps in determining the amount of valid data
                                                                 present in the trace memory. It is not affected by the reprogramming of pointer
                                                                 registers in Disabled state. It is cleared when the TMC leaves Disabled state. */
        uint32_t triggered             : 1;  /**< [  1:  1](RO) TMC triggered. This bit is set when trace capture is in progress and the TMC has
                                                                 detected a trigger event. This bit is cleared to 0 when leaving the Disabled
                                                                 state and retains its value when entering the Disabled state. A trigger event is
                                                                 when the TMC has written a set number of data words, as programmed in the TRG
                                                                 register, into the trace memory after a rising edge of trigin input, or a
                                                                 trigger packet (atid_s = 0x7D) is received in the input trace. */
        uint32_t tmcready              : 1;  /**< [  2:  2](RO) TMC ready. This flag is set when trace capture has stopped and all internal
                                                                 pipelines and buffers have drained, the TMC is not draining as a result of
                                                                 FFCR.DrainBuffer bit being set (ETF only), and the AXI interface is not busy and
                                                                 the response for final AXI write has been received (ETR only) are all true. This
                                                                 bit is cleared to 0 when leaving the Disabled state and retains its value when
                                                                 entering the Disabled state. */
        uint32_t ftempty               : 1;  /**< [  3:  3](RO) Formatter pipeline empty. This bit is deprecated and is present in this register
                                                                 to support backwards compatibility with earlier versions of the ETB. It is set
                                                                 when trace capture has stopped, and all internal pipelines and buffers have
                                                                 drained. Unlike STS.TMCReady, it is not affected by buffer drains and AXI
                                                                 accesses. It is cleared to 0 when leaving the Disabled state and retains its
                                                                 value when entering the Disabled state. */
        uint32_t empty                 : 1;  /**< [  4:  4](RO) Trace buffer empty. If set, this bit indicates that the trace memory does not
                                                                 contain any valid trace data. However, this does not mean that the pipeline
                                                                 stages within the TMC are empty. To determine whether the internal pipeline
                                                                 stages are empty, the software must read the STS.TMCReady bit. */
        uint32_t razwi_0               : 27; /**< [ 31:  5](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_sts_s cn; */
};
typedef union cavm_etf_verticalx_sts cavm_etf_verticalx_sts_t;

static inline uint64_t CAVM_ETF_VERTICALX_STS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_STS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e04610300cll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_STS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_STS(a) cavm_etf_verticalx_sts_t
#define bustype_CAVM_ETF_VERTICALX_STS(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_STS(a) "ETF_VERTICALX_STS"
#define busnum_CAVM_ETF_VERTICALX_STS(a) (a)
#define arguments_CAVM_ETF_VERTICALX_STS(a) (a),-1,-1,-1

/**
 * Register (RSL32b) etf_vertical#_trg
 *
 * ETF Vertical Trg Register
 * In Circular Buffer mode, the Trigger Counter register specifies the number of 32-bit
 * words to capture in the trace memory, after detection of either a rising edge on the
 * trigin input or a trigger packet in the incoming trace stream, that is, where atid_s
 * = 0x7D. The value programmed must be aligned to the frame length of 128 bits.
 */
union cavm_etf_verticalx_trg
{
    uint32_t u;
    struct cavm_etf_verticalx_trg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t razwi_0               : 20; /**< [ 31: 12](R/W) Read-As-Zero, Writes Ignored. */
        uint32_t trg                   : 12; /**< [ 11:  0](R/W) Trigger count. This count represents the number of 32-bit words of trace that
                                                                 are captured between a trigger packet and a trigger event. */
#else /* Word 0 - Little Endian */
        uint32_t trg                   : 12; /**< [ 11:  0](R/W) Trigger count. This count represents the number of 32-bit words of trace that
                                                                 are captured between a trigger packet and a trigger event. */
        uint32_t razwi_0               : 20; /**< [ 31: 12](R/W) Read-As-Zero, Writes Ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_etf_verticalx_trg_s cn; */
};
typedef union cavm_etf_verticalx_trg cavm_etf_verticalx_trg_t;

static inline uint64_t CAVM_ETF_VERTICALX_TRG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_ETF_VERTICALX_TRG(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=3))
        return 0x87e04610301cll + 0x100000ll * ((a) & 0x3);
    __cavm_csr_fatal("ETF_VERTICALX_TRG", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_ETF_VERTICALX_TRG(a) cavm_etf_verticalx_trg_t
#define bustype_CAVM_ETF_VERTICALX_TRG(a) CSR_TYPE_RSL32b
#define basename_CAVM_ETF_VERTICALX_TRG(a) "ETF_VERTICALX_TRG"
#define busnum_CAVM_ETF_VERTICALX_TRG(a) (a)
#define arguments_CAVM_ETF_VERTICALX_TRG(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_ETF_VERTICAL_H__ */
