#ifndef __CAVM_CSRS_BBXB_H__
#define __CAVM_CSRS_BBXB_H__
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
 * OcteonTX BBXB.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) bbxb#_ab#_config_00
 *
 * BBX2 Configuration Register 0
 * Job Configuration
 */
union cavm_bbxbx_abx_config_00
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_00_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_00             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_00             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_00_s cn; */
};
typedef union cavm_bbxbx_abx_config_00 cavm_bbxbx_abx_config_00_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_00(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_00(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402000ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_00", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_00(a,b) cavm_bbxbx_abx_config_00_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_00(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_00(a,b) "BBXBX_ABX_CONFIG_00"
#define busnum_CAVM_BBXBX_ABX_CONFIG_00(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_00(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_01
 *
 * BBX2 Configuration Register 1
 * Job Configuration
 */
union cavm_bbxbx_abx_config_01
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_01_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_01             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_01             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_01_s cn; */
};
typedef union cavm_bbxbx_abx_config_01 cavm_bbxbx_abx_config_01_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_01(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_01(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402008ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_01", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_01(a,b) cavm_bbxbx_abx_config_01_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_01(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_01(a,b) "BBXBX_ABX_CONFIG_01"
#define busnum_CAVM_BBXBX_ABX_CONFIG_01(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_01(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_02
 *
 * BBX2 Configuration Register 2
 * Job Configuration
 */
union cavm_bbxbx_abx_config_02
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_02_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_02             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_02             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_02_s cn; */
};
typedef union cavm_bbxbx_abx_config_02 cavm_bbxbx_abx_config_02_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_02(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_02(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402010ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_02", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_02(a,b) cavm_bbxbx_abx_config_02_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_02(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_02(a,b) "BBXBX_ABX_CONFIG_02"
#define busnum_CAVM_BBXBX_ABX_CONFIG_02(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_02(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_03
 *
 * BBX2 Configuration Register 3
 * Job Configuration
 */
union cavm_bbxbx_abx_config_03
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_03_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_03             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_03             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_03_s cn; */
};
typedef union cavm_bbxbx_abx_config_03 cavm_bbxbx_abx_config_03_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_03(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_03(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402018ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_03", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_03(a,b) cavm_bbxbx_abx_config_03_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_03(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_03(a,b) "BBXBX_ABX_CONFIG_03"
#define busnum_CAVM_BBXBX_ABX_CONFIG_03(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_03(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_04
 *
 * BBX2 Configuration Register 4
 * Job Configuration
 */
union cavm_bbxbx_abx_config_04
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_04_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_04             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_04             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_04_s cn; */
};
typedef union cavm_bbxbx_abx_config_04 cavm_bbxbx_abx_config_04_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_04(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_04(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402020ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_04", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_04(a,b) cavm_bbxbx_abx_config_04_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_04(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_04(a,b) "BBXBX_ABX_CONFIG_04"
#define busnum_CAVM_BBXBX_ABX_CONFIG_04(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_04(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_05
 *
 * BBX2 Configuration Register 5
 * Job Configuration
 */
union cavm_bbxbx_abx_config_05
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_05_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_05             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_05             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_05_s cn; */
};
typedef union cavm_bbxbx_abx_config_05 cavm_bbxbx_abx_config_05_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_05(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_05(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402028ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_05", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_05(a,b) cavm_bbxbx_abx_config_05_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_05(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_05(a,b) "BBXBX_ABX_CONFIG_05"
#define busnum_CAVM_BBXBX_ABX_CONFIG_05(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_05(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_06
 *
 * BBX2 Configuration Register 6
 * Job Configuration
 */
union cavm_bbxbx_abx_config_06
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_06_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_06             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_06             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_06_s cn; */
};
typedef union cavm_bbxbx_abx_config_06 cavm_bbxbx_abx_config_06_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_06(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_06(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402030ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_06", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_06(a,b) cavm_bbxbx_abx_config_06_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_06(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_06(a,b) "BBXBX_ABX_CONFIG_06"
#define busnum_CAVM_BBXBX_ABX_CONFIG_06(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_06(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_07
 *
 * BBX2 Configuration Register 7
 * Job Configuration
 */
union cavm_bbxbx_abx_config_07
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_07_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_07             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_07             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_07_s cn; */
};
typedef union cavm_bbxbx_abx_config_07 cavm_bbxbx_abx_config_07_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_07(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_07(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402038ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_07", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_07(a,b) cavm_bbxbx_abx_config_07_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_07(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_07(a,b) "BBXBX_ABX_CONFIG_07"
#define busnum_CAVM_BBXBX_ABX_CONFIG_07(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_07(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_08
 *
 * BBX2 Configuration Register 8
 * Job Configuration
 */
union cavm_bbxbx_abx_config_08
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_08_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_08             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_08             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_08_s cn; */
};
typedef union cavm_bbxbx_abx_config_08 cavm_bbxbx_abx_config_08_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_08(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_08(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402040ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_08", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_08(a,b) cavm_bbxbx_abx_config_08_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_08(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_08(a,b) "BBXBX_ABX_CONFIG_08"
#define busnum_CAVM_BBXBX_ABX_CONFIG_08(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_08(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_09
 *
 * BBX2 Configuration Register 9
 * Job Configuration
 */
union cavm_bbxbx_abx_config_09
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_09_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_09             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_09             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_09_s cn; */
};
typedef union cavm_bbxbx_abx_config_09 cavm_bbxbx_abx_config_09_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_09(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_09(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402048ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_09", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_09(a,b) cavm_bbxbx_abx_config_09_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_09(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_09(a,b) "BBXBX_ABX_CONFIG_09"
#define busnum_CAVM_BBXBX_ABX_CONFIG_09(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_09(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_10
 *
 * BBX2 Configuration Register 10
 * Job Configuration
 */
union cavm_bbxbx_abx_config_10
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_10_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_10             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_10             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_10_s cn; */
};
typedef union cavm_bbxbx_abx_config_10 cavm_bbxbx_abx_config_10_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_10(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_10(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402050ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_10", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_10(a,b) cavm_bbxbx_abx_config_10_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_10(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_10(a,b) "BBXBX_ABX_CONFIG_10"
#define busnum_CAVM_BBXBX_ABX_CONFIG_10(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_10(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_11
 *
 * BBX2 Configuration Register 11
 * Job Configuration
 */
union cavm_bbxbx_abx_config_11
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_11             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_11             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_11_s cn; */
};
typedef union cavm_bbxbx_abx_config_11 cavm_bbxbx_abx_config_11_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_11(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_11(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402058ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_11", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_11(a,b) cavm_bbxbx_abx_config_11_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_11(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_11(a,b) "BBXBX_ABX_CONFIG_11"
#define busnum_CAVM_BBXBX_ABX_CONFIG_11(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_11(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_12
 *
 * BBX2 Configuration Register 12
 * Job Configuration
 */
union cavm_bbxbx_abx_config_12
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_12_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_12             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_12             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_12_s cn; */
};
typedef union cavm_bbxbx_abx_config_12 cavm_bbxbx_abx_config_12_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_12(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_12(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402060ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_12", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_12(a,b) cavm_bbxbx_abx_config_12_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_12(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_12(a,b) "BBXBX_ABX_CONFIG_12"
#define busnum_CAVM_BBXBX_ABX_CONFIG_12(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_12(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_13
 *
 * BBX2 Configuration Register 13
 * Job Configuration
 */
union cavm_bbxbx_abx_config_13
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_13_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_13             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_13             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_13_s cn; */
};
typedef union cavm_bbxbx_abx_config_13 cavm_bbxbx_abx_config_13_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_13(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_13(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402068ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_13", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_13(a,b) cavm_bbxbx_abx_config_13_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_13(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_13(a,b) "BBXBX_ABX_CONFIG_13"
#define busnum_CAVM_BBXBX_ABX_CONFIG_13(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_13(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_14
 *
 * BBX2 Configuration Register 14
 * Job Configuration
 */
union cavm_bbxbx_abx_config_14
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_14_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_14             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_14             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_14_s cn; */
};
typedef union cavm_bbxbx_abx_config_14 cavm_bbxbx_abx_config_14_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_14(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_14(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402070ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_14", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_14(a,b) cavm_bbxbx_abx_config_14_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_14(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_14(a,b) "BBXBX_ABX_CONFIG_14"
#define busnum_CAVM_BBXBX_ABX_CONFIG_14(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_14(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_15
 *
 * BBX2 Configuration Register 15
 * Job Configuration
 */
union cavm_bbxbx_abx_config_15
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_15             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_15             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_15_s cn; */
};
typedef union cavm_bbxbx_abx_config_15 cavm_bbxbx_abx_config_15_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_15(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_15(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402078ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_15", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_15(a,b) cavm_bbxbx_abx_config_15_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_15(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_15(a,b) "BBXBX_ABX_CONFIG_15"
#define busnum_CAVM_BBXBX_ABX_CONFIG_15(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_15(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_16
 *
 * BBX2 Configuration Register 16
 * Job Configuration
 */
union cavm_bbxbx_abx_config_16
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_16_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_16             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_16             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_16_s cn; */
};
typedef union cavm_bbxbx_abx_config_16 cavm_bbxbx_abx_config_16_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_16(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_16(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402080ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_16", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_16(a,b) cavm_bbxbx_abx_config_16_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_16(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_16(a,b) "BBXBX_ABX_CONFIG_16"
#define busnum_CAVM_BBXBX_ABX_CONFIG_16(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_16(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_17
 *
 * BBX2 Configuration Register 17
 * Job Configuration
 */
union cavm_bbxbx_abx_config_17
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_17_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_17             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_17             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_17_s cn; */
};
typedef union cavm_bbxbx_abx_config_17 cavm_bbxbx_abx_config_17_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_17(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_17(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402088ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_17", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_17(a,b) cavm_bbxbx_abx_config_17_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_17(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_17(a,b) "BBXBX_ABX_CONFIG_17"
#define busnum_CAVM_BBXBX_ABX_CONFIG_17(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_17(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_18
 *
 * BBX2 Configuration Register 18
 * Job Configuration
 */
union cavm_bbxbx_abx_config_18
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_18_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_18             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_18             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_18_s cn; */
};
typedef union cavm_bbxbx_abx_config_18 cavm_bbxbx_abx_config_18_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_18(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_18(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402090ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_18", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_18(a,b) cavm_bbxbx_abx_config_18_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_18(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_18(a,b) "BBXBX_ABX_CONFIG_18"
#define busnum_CAVM_BBXBX_ABX_CONFIG_18(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_18(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_19
 *
 * BBX2 Configuration Register 19
 * Job Configuration
 */
union cavm_bbxbx_abx_config_19
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_19             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_19             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_19_s cn; */
};
typedef union cavm_bbxbx_abx_config_19 cavm_bbxbx_abx_config_19_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_19(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_19(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402098ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_19", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_19(a,b) cavm_bbxbx_abx_config_19_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_19(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_19(a,b) "BBXBX_ABX_CONFIG_19"
#define busnum_CAVM_BBXBX_ABX_CONFIG_19(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_19(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_20
 *
 * BBX2 Configuration Register 20
 * Job Configuration
 */
union cavm_bbxbx_abx_config_20
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_20_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_20             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_20             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_20_s cn; */
};
typedef union cavm_bbxbx_abx_config_20 cavm_bbxbx_abx_config_20_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_20(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_20(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020a0ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_20", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_20(a,b) cavm_bbxbx_abx_config_20_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_20(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_20(a,b) "BBXBX_ABX_CONFIG_20"
#define busnum_CAVM_BBXBX_ABX_CONFIG_20(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_20(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_21
 *
 * BBX2 Configuration Register 21
 * Job Configuration
 */
union cavm_bbxbx_abx_config_21
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_21_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_21             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_21             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_21_s cn; */
};
typedef union cavm_bbxbx_abx_config_21 cavm_bbxbx_abx_config_21_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_21(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_21(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020a8ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_21", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_21(a,b) cavm_bbxbx_abx_config_21_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_21(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_21(a,b) "BBXBX_ABX_CONFIG_21"
#define busnum_CAVM_BBXBX_ABX_CONFIG_21(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_21(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_22
 *
 * BBX2 Configuration Register 22
 * Job Configuration
 */
union cavm_bbxbx_abx_config_22
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_22_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_22             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_22             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_22_s cn; */
};
typedef union cavm_bbxbx_abx_config_22 cavm_bbxbx_abx_config_22_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_22(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_22(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020b0ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_22", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_22(a,b) cavm_bbxbx_abx_config_22_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_22(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_22(a,b) "BBXBX_ABX_CONFIG_22"
#define busnum_CAVM_BBXBX_ABX_CONFIG_22(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_22(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_23
 *
 * BBX2 Configuration Register 23
 * Job Configuration
 */
union cavm_bbxbx_abx_config_23
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_23             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_23             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_23_s cn; */
};
typedef union cavm_bbxbx_abx_config_23 cavm_bbxbx_abx_config_23_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_23(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_23(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020b8ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_23", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_23(a,b) cavm_bbxbx_abx_config_23_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_23(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_23(a,b) "BBXBX_ABX_CONFIG_23"
#define busnum_CAVM_BBXBX_ABX_CONFIG_23(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_23(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_24
 *
 * BBX2 Configuration Register 24
 * Job Configuration
 */
union cavm_bbxbx_abx_config_24
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_24_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_24             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_24             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_24_s cn; */
};
typedef union cavm_bbxbx_abx_config_24 cavm_bbxbx_abx_config_24_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_24(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_24(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020c0ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_24", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_24(a,b) cavm_bbxbx_abx_config_24_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_24(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_24(a,b) "BBXBX_ABX_CONFIG_24"
#define busnum_CAVM_BBXBX_ABX_CONFIG_24(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_24(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_25
 *
 * BBX2 Configuration Register 25
 * Job Configuration
 */
union cavm_bbxbx_abx_config_25
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_25_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_25             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_25             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_25_s cn; */
};
typedef union cavm_bbxbx_abx_config_25 cavm_bbxbx_abx_config_25_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_25(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_25(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020c8ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_25", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_25(a,b) cavm_bbxbx_abx_config_25_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_25(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_25(a,b) "BBXBX_ABX_CONFIG_25"
#define busnum_CAVM_BBXBX_ABX_CONFIG_25(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_25(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_26
 *
 * BBX2 Configuration Register 26
 * Job Configuration
 */
union cavm_bbxbx_abx_config_26
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_26_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_26             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_26             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_26_s cn; */
};
typedef union cavm_bbxbx_abx_config_26 cavm_bbxbx_abx_config_26_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_26(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_26(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020d0ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_26", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_26(a,b) cavm_bbxbx_abx_config_26_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_26(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_26(a,b) "BBXBX_ABX_CONFIG_26"
#define busnum_CAVM_BBXBX_ABX_CONFIG_26(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_26(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_27
 *
 * BBX2 Configuration Register 27
 * Job Configuration
 */
union cavm_bbxbx_abx_config_27
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_27             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_27             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_27_s cn; */
};
typedef union cavm_bbxbx_abx_config_27 cavm_bbxbx_abx_config_27_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_27(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_27(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020d8ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_27", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_27(a,b) cavm_bbxbx_abx_config_27_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_27(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_27(a,b) "BBXBX_ABX_CONFIG_27"
#define busnum_CAVM_BBXBX_ABX_CONFIG_27(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_27(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_28
 *
 * BBX2 Configuration Register 28
 * Job Configuration
 */
union cavm_bbxbx_abx_config_28
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_28_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_28             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_28             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_28_s cn; */
};
typedef union cavm_bbxbx_abx_config_28 cavm_bbxbx_abx_config_28_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_28(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_28(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020e0ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_28", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_28(a,b) cavm_bbxbx_abx_config_28_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_28(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_28(a,b) "BBXBX_ABX_CONFIG_28"
#define busnum_CAVM_BBXBX_ABX_CONFIG_28(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_28(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_29
 *
 * BBX2 Configuration Register 29
 * Job Configuration
 */
union cavm_bbxbx_abx_config_29
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_29_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_29             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_29             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_29_s cn; */
};
typedef union cavm_bbxbx_abx_config_29 cavm_bbxbx_abx_config_29_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_29(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_29(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020e8ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_29", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_29(a,b) cavm_bbxbx_abx_config_29_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_29(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_29(a,b) "BBXBX_ABX_CONFIG_29"
#define busnum_CAVM_BBXBX_ABX_CONFIG_29(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_29(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_30
 *
 * BBX2 Configuration Register 30
 * Job Configuration
 */
union cavm_bbxbx_abx_config_30
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_30_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_30             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_30             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_30_s cn; */
};
typedef union cavm_bbxbx_abx_config_30 cavm_bbxbx_abx_config_30_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_30(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_30(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020f0ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_30", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_30(a,b) cavm_bbxbx_abx_config_30_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_30(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_30(a,b) "BBXBX_ABX_CONFIG_30"
#define busnum_CAVM_BBXBX_ABX_CONFIG_30(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_30(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_config_31
 *
 * BBX2 Configuration Register 31
 * Job Configuration
 */
union cavm_bbxbx_abx_config_31
{
    uint64_t u;
    struct cavm_bbxbx_abx_config_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_31             : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_31             : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_config_31_s cn; */
};
typedef union cavm_bbxbx_abx_config_31 cavm_bbxbx_abx_config_31_t;

static inline uint64_t CAVM_BBXBX_ABX_CONFIG_31(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONFIG_31(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e0434020f8ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONFIG_31", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONFIG_31(a,b) cavm_bbxbx_abx_config_31_t
#define bustype_CAVM_BBXBX_ABX_CONFIG_31(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONFIG_31(a,b) "BBXBX_ABX_CONFIG_31"
#define busnum_CAVM_BBXBX_ABX_CONFIG_31(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONFIG_31(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_control_error_00
 *
 * BBX2 Error Register 0
 * HAB Control
 */
union cavm_bbxbx_abx_control_error_00
{
    uint64_t u;
    struct cavm_bbxbx_abx_control_error_00_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_id_dma_error      : 16; /**< [ 31: 16](R/W/H) Job ID for DMA error (any write clears) */
        uint64_t reserved_6_15         : 10;
        uint64_t rp1_overflow          : 1;  /**< [  5:  5](R/W/H) Read Port 1 Overflow (any write clears) */
        uint64_t rp0_overflow          : 1;  /**< [  4:  4](R/W/H) Read Port 0 Overflow (any write clears) */
        uint64_t reserved_2_3          : 2;
        uint64_t rp1_underflow         : 1;  /**< [  1:  1](R/W/H) Read Port 1 Underflow (any write clears) */
        uint64_t rp0_underflow         : 1;  /**< [  0:  0](R/W/H) Read Port 0 Underflow (any write clears) */
#else /* Word 0 - Little Endian */
        uint64_t rp0_underflow         : 1;  /**< [  0:  0](R/W/H) Read Port 0 Underflow (any write clears) */
        uint64_t rp1_underflow         : 1;  /**< [  1:  1](R/W/H) Read Port 1 Underflow (any write clears) */
        uint64_t reserved_2_3          : 2;
        uint64_t rp0_overflow          : 1;  /**< [  4:  4](R/W/H) Read Port 0 Overflow (any write clears) */
        uint64_t rp1_overflow          : 1;  /**< [  5:  5](R/W/H) Read Port 1 Overflow (any write clears) */
        uint64_t reserved_6_15         : 10;
        uint64_t job_id_dma_error      : 16; /**< [ 31: 16](R/W/H) Job ID for DMA error (any write clears) */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_control_error_00_s cn; */
};
typedef union cavm_bbxbx_abx_control_error_00 cavm_bbxbx_abx_control_error_00_t;

static inline uint64_t CAVM_BBXBX_ABX_CONTROL_ERROR_00(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONTROL_ERROR_00(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043400030ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONTROL_ERROR_00", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONTROL_ERROR_00(a,b) cavm_bbxbx_abx_control_error_00_t
#define bustype_CAVM_BBXBX_ABX_CONTROL_ERROR_00(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONTROL_ERROR_00(a,b) "BBXBX_ABX_CONTROL_ERROR_00"
#define busnum_CAVM_BBXBX_ABX_CONTROL_ERROR_00(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONTROL_ERROR_00(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_control_error_01
 *
 * BBX2 Error Register 1
 * HAB Control
 */
union cavm_bbxbx_abx_control_error_01
{
    uint64_t u;
    struct cavm_bbxbx_abx_control_error_01_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t job_id_hab_error      : 16; /**< [ 47: 32](R/W/H) Job ID for HAB specific error (any write clears) */
        uint64_t hab_error             : 32; /**< [ 31:  0](R/W/H) HAB specific error (any write clears) */
#else /* Word 0 - Little Endian */
        uint64_t hab_error             : 32; /**< [ 31:  0](R/W/H) HAB specific error (any write clears) */
        uint64_t job_id_hab_error      : 16; /**< [ 47: 32](R/W/H) Job ID for HAB specific error (any write clears) */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_control_error_01_s cn; */
};
typedef union cavm_bbxbx_abx_control_error_01 cavm_bbxbx_abx_control_error_01_t;

static inline uint64_t CAVM_BBXBX_ABX_CONTROL_ERROR_01(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONTROL_ERROR_01(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043400038ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONTROL_ERROR_01", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONTROL_ERROR_01(a,b) cavm_bbxbx_abx_control_error_01_t
#define bustype_CAVM_BBXBX_ABX_CONTROL_ERROR_01(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONTROL_ERROR_01(a,b) "BBXBX_ABX_CONTROL_ERROR_01"
#define busnum_CAVM_BBXBX_ABX_CONTROL_ERROR_01(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONTROL_ERROR_01(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_control_error_02
 *
 * BBX2 Error Enable 0 Register
 * HAB Control
 */
union cavm_bbxbx_abx_control_error_02
{
    uint64_t u;
    struct cavm_bbxbx_abx_control_error_02_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t rp1_overflow_en       : 1;  /**< [  5:  5](R/W) Read Port 1 Overflow Error Enable */
        uint64_t rp0_overflow_en       : 1;  /**< [  4:  4](R/W) Read Port 0 Overflow Error Enable */
        uint64_t reserved_2_3          : 2;
        uint64_t rp1_underflow_en      : 1;  /**< [  1:  1](R/W) Read Port 1 Underflow Error Enable */
        uint64_t rp0_underflow_en      : 1;  /**< [  0:  0](R/W) Read Port 0 Underflow Error Enable */
#else /* Word 0 - Little Endian */
        uint64_t rp0_underflow_en      : 1;  /**< [  0:  0](R/W) Read Port 0 Underflow Error Enable */
        uint64_t rp1_underflow_en      : 1;  /**< [  1:  1](R/W) Read Port 1 Underflow Error Enable */
        uint64_t reserved_2_3          : 2;
        uint64_t rp0_overflow_en       : 1;  /**< [  4:  4](R/W) Read Port 0 Overflow Error Enable */
        uint64_t rp1_overflow_en       : 1;  /**< [  5:  5](R/W) Read Port 1 Overflow Error Enable */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    struct cavm_bbxbx_abx_control_error_02_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t reserved_6_7          : 2;
        uint64_t rp1_overflow_en       : 1;  /**< [  5:  5](R/W) Read Port 1 Overflow Error Enable */
        uint64_t rp0_overflow_en       : 1;  /**< [  4:  4](R/W) Read Port 0 Overflow Error Enable */
        uint64_t reserved_2_3          : 2;
        uint64_t rp1_underflow_en      : 1;  /**< [  1:  1](R/W) Read Port 1 Underflow Error Enable */
        uint64_t rp0_underflow_en      : 1;  /**< [  0:  0](R/W) Read Port 0 Underflow Error Enable */
#else /* Word 0 - Little Endian */
        uint64_t rp0_underflow_en      : 1;  /**< [  0:  0](R/W) Read Port 0 Underflow Error Enable */
        uint64_t rp1_underflow_en      : 1;  /**< [  1:  1](R/W) Read Port 1 Underflow Error Enable */
        uint64_t reserved_2_3          : 2;
        uint64_t rp0_overflow_en       : 1;  /**< [  4:  4](R/W) Read Port 0 Overflow Error Enable */
        uint64_t rp1_overflow_en       : 1;  /**< [  5:  5](R/W) Read Port 1 Overflow Error Enable */
        uint64_t reserved_6_7          : 2;
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } cn;
};
typedef union cavm_bbxbx_abx_control_error_02 cavm_bbxbx_abx_control_error_02_t;

static inline uint64_t CAVM_BBXBX_ABX_CONTROL_ERROR_02(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONTROL_ERROR_02(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043400040ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONTROL_ERROR_02", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONTROL_ERROR_02(a,b) cavm_bbxbx_abx_control_error_02_t
#define bustype_CAVM_BBXBX_ABX_CONTROL_ERROR_02(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONTROL_ERROR_02(a,b) "BBXBX_ABX_CONTROL_ERROR_02"
#define busnum_CAVM_BBXBX_ABX_CONTROL_ERROR_02(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONTROL_ERROR_02(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_control_error_03
 *
 * BBX2 Error Enable 1 Register
 * HAB Control
 */
union cavm_bbxbx_abx_control_error_03
{
    uint64_t u;
    struct cavm_bbxbx_abx_control_error_03_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t hab_error_en          : 7;  /**< [  6:  0](R/W) HAB specific Error Enable */
#else /* Word 0 - Little Endian */
        uint64_t hab_error_en          : 7;  /**< [  6:  0](R/W) HAB specific Error Enable */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_control_error_03_s cn; */
};
typedef union cavm_bbxbx_abx_control_error_03 cavm_bbxbx_abx_control_error_03_t;

static inline uint64_t CAVM_BBXBX_ABX_CONTROL_ERROR_03(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONTROL_ERROR_03(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043400048ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONTROL_ERROR_03", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONTROL_ERROR_03(a,b) cavm_bbxbx_abx_control_error_03_t
#define bustype_CAVM_BBXBX_ABX_CONTROL_ERROR_03(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONTROL_ERROR_03(a,b) "BBXBX_ABX_CONTROL_ERROR_03"
#define busnum_CAVM_BBXBX_ABX_CONTROL_ERROR_03(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONTROL_ERROR_03(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_control_main
 *
 * BBX2 Main Control Register
 * HAB Control
 */
union cavm_bbxbx_abx_control_main
{
    uint64_t u;
    struct cavm_bbxbx_abx_control_main_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_control_main_s cn; */
};
typedef union cavm_bbxbx_abx_control_main cavm_bbxbx_abx_control_main_t;

static inline uint64_t CAVM_BBXBX_ABX_CONTROL_MAIN(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONTROL_MAIN(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043400000ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONTROL_MAIN", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONTROL_MAIN(a,b) cavm_bbxbx_abx_control_main_t
#define bustype_CAVM_BBXBX_ABX_CONTROL_MAIN(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONTROL_MAIN(a,b) "BBXBX_ABX_CONTROL_MAIN"
#define busnum_CAVM_BBXBX_ABX_CONTROL_MAIN(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONTROL_MAIN(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_control_status
 *
 * BBX2 Status Register
 * HAB Control
 */
union cavm_bbxbx_abx_control_status
{
    uint64_t u;
    struct cavm_bbxbx_abx_control_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t job_cycle             : 24; /**< [ 55: 32](RO) Job Cycle Counter */
        uint64_t reserved_10_31        : 22;
        uint64_t main_fsm              : 5;  /**< [  9:  5](RO) BBX2 Main FSM state */
        uint64_t ready                 : 1;  /**< [  4:  4](RO) Ready to receive the next job */
        uint64_t reserved_1_3          : 3;
        uint64_t busy                  : 1;  /**< [  0:  0](RO) Busy for CONFIGURATION 0 */
#else /* Word 0 - Little Endian */
        uint64_t busy                  : 1;  /**< [  0:  0](RO) Busy for CONFIGURATION 0 */
        uint64_t reserved_1_3          : 3;
        uint64_t ready                 : 1;  /**< [  4:  4](RO) Ready to receive the next job */
        uint64_t main_fsm              : 5;  /**< [  9:  5](RO) BBX2 Main FSM state */
        uint64_t reserved_10_31        : 22;
        uint64_t job_cycle             : 24; /**< [ 55: 32](RO) Job Cycle Counter */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_control_status_s cn; */
};
typedef union cavm_bbxbx_abx_control_status cavm_bbxbx_abx_control_status_t;

static inline uint64_t CAVM_BBXBX_ABX_CONTROL_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_CONTROL_STATUS(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043400018ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_CONTROL_STATUS", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_CONTROL_STATUS(a,b) cavm_bbxbx_abx_control_status_t
#define bustype_CAVM_BBXBX_ABX_CONTROL_STATUS(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_CONTROL_STATUS(a,b) "BBXBX_ABX_CONTROL_STATUS"
#define busnum_CAVM_BBXBX_ABX_CONTROL_STATUS(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_CONTROL_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_debug_00
 *
 * BBX2 Debug Register 0
 * HAB information
 */
union cavm_bbxbx_abx_debug_00
{
    uint64_t u;
    struct cavm_bbxbx_abx_debug_00_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t hab_info              : 64; /**< [ 63:  0](RO) -- */
#else /* Word 0 - Little Endian */
        uint64_t hab_info              : 64; /**< [ 63:  0](RO) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_debug_00_s cn; */
};
typedef union cavm_bbxbx_abx_debug_00 cavm_bbxbx_abx_debug_00_t;

static inline uint64_t CAVM_BBXBX_ABX_DEBUG_00(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_DEBUG_00(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043401000ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_DEBUG_00", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_DEBUG_00(a,b) cavm_bbxbx_abx_debug_00_t
#define bustype_CAVM_BBXBX_ABX_DEBUG_00(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_DEBUG_00(a,b) "BBXBX_ABX_DEBUG_00"
#define busnum_CAVM_BBXBX_ABX_DEBUG_00(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_DEBUG_00(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_debug_01
 *
 * BBX2 Debug Register 1
 * HAB debug
 */
union cavm_bbxbx_abx_debug_01
{
    uint64_t u;
    struct cavm_bbxbx_abx_debug_01_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t hab_debug_0           : 64; /**< [ 63:  0](RO) -- */
#else /* Word 0 - Little Endian */
        uint64_t hab_debug_0           : 64; /**< [ 63:  0](RO) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_debug_01_s cn; */
};
typedef union cavm_bbxbx_abx_debug_01 cavm_bbxbx_abx_debug_01_t;

static inline uint64_t CAVM_BBXBX_ABX_DEBUG_01(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_DEBUG_01(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043401008ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_DEBUG_01", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_DEBUG_01(a,b) cavm_bbxbx_abx_debug_01_t
#define bustype_CAVM_BBXBX_ABX_DEBUG_01(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_DEBUG_01(a,b) "BBXBX_ABX_DEBUG_01"
#define busnum_CAVM_BBXBX_ABX_DEBUG_01(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_DEBUG_01(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_debug_02
 *
 * BBX2 Debug Register 2
 * HAB debug
 */
union cavm_bbxbx_abx_debug_02
{
    uint64_t u;
    struct cavm_bbxbx_abx_debug_02_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t hab_debug_1           : 8;  /**< [  7:  0](RO) -- */
#else /* Word 0 - Little Endian */
        uint64_t hab_debug_1           : 8;  /**< [  7:  0](RO) -- */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_debug_02_s cn; */
};
typedef union cavm_bbxbx_abx_debug_02 cavm_bbxbx_abx_debug_02_t;

static inline uint64_t CAVM_BBXBX_ABX_DEBUG_02(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_DEBUG_02(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043401010ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_DEBUG_02", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_DEBUG_02(a,b) cavm_bbxbx_abx_debug_02_t
#define bustype_CAVM_BBXBX_ABX_DEBUG_02(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_DEBUG_02(a,b) "BBXBX_ABX_DEBUG_02"
#define busnum_CAVM_BBXBX_ABX_DEBUG_02(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_DEBUG_02(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_table_00
 *
 * BBX2 Table Register 0
 * Job Configuration
 */
union cavm_bbxbx_abx_table_00
{
    uint64_t u;
    struct cavm_bbxbx_abx_table_00_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t table_00              : 40; /**< [ 39:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t table_00              : 40; /**< [ 39:  0](R/W) -- */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_table_00_s cn; */
};
typedef union cavm_bbxbx_abx_table_00 cavm_bbxbx_abx_table_00_t;

static inline uint64_t CAVM_BBXBX_ABX_TABLE_00(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_TABLE_00(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402100ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_TABLE_00", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_TABLE_00(a,b) cavm_bbxbx_abx_table_00_t
#define bustype_CAVM_BBXBX_ABX_TABLE_00(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_TABLE_00(a,b) "BBXBX_ABX_TABLE_00"
#define busnum_CAVM_BBXBX_ABX_TABLE_00(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_TABLE_00(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_table_01
 *
 * BBX2 Table Register 1
 * Job Configuration
 */
union cavm_bbxbx_abx_table_01
{
    uint64_t u;
    struct cavm_bbxbx_abx_table_01_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t table_01              : 40; /**< [ 39:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t table_01              : 40; /**< [ 39:  0](R/W) -- */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_table_01_s cn; */
};
typedef union cavm_bbxbx_abx_table_01 cavm_bbxbx_abx_table_01_t;

static inline uint64_t CAVM_BBXBX_ABX_TABLE_01(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_TABLE_01(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402108ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_TABLE_01", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_TABLE_01(a,b) cavm_bbxbx_abx_table_01_t
#define bustype_CAVM_BBXBX_ABX_TABLE_01(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_TABLE_01(a,b) "BBXBX_ABX_TABLE_01"
#define busnum_CAVM_BBXBX_ABX_TABLE_01(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_TABLE_01(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_table_02
 *
 * BBX2 Table Register 2
 * Job Configuration
 */
union cavm_bbxbx_abx_table_02
{
    uint64_t u;
    struct cavm_bbxbx_abx_table_02_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t table_02              : 40; /**< [ 39:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t table_02              : 40; /**< [ 39:  0](R/W) -- */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_table_02_s cn; */
};
typedef union cavm_bbxbx_abx_table_02 cavm_bbxbx_abx_table_02_t;

static inline uint64_t CAVM_BBXBX_ABX_TABLE_02(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_TABLE_02(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402110ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_TABLE_02", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_TABLE_02(a,b) cavm_bbxbx_abx_table_02_t
#define bustype_CAVM_BBXBX_ABX_TABLE_02(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_TABLE_02(a,b) "BBXBX_ABX_TABLE_02"
#define busnum_CAVM_BBXBX_ABX_TABLE_02(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_TABLE_02(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_table_03
 *
 * BBX2 Table Register 3
 * Job Configuration
 */
union cavm_bbxbx_abx_table_03
{
    uint64_t u;
    struct cavm_bbxbx_abx_table_03_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t table_03              : 40; /**< [ 39:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t table_03              : 40; /**< [ 39:  0](R/W) -- */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_table_03_s cn; */
};
typedef union cavm_bbxbx_abx_table_03 cavm_bbxbx_abx_table_03_t;

static inline uint64_t CAVM_BBXBX_ABX_TABLE_03(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_TABLE_03(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402118ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_TABLE_03", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_TABLE_03(a,b) cavm_bbxbx_abx_table_03_t
#define bustype_CAVM_BBXBX_ABX_TABLE_03(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_TABLE_03(a,b) "BBXBX_ABX_TABLE_03"
#define busnum_CAVM_BBXBX_ABX_TABLE_03(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_TABLE_03(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_table_04
 *
 * BBX2 Table Register 4
 * Job Configuration
 */
union cavm_bbxbx_abx_table_04
{
    uint64_t u;
    struct cavm_bbxbx_abx_table_04_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t table_04              : 40; /**< [ 39:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t table_04              : 40; /**< [ 39:  0](R/W) -- */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_table_04_s cn; */
};
typedef union cavm_bbxbx_abx_table_04 cavm_bbxbx_abx_table_04_t;

static inline uint64_t CAVM_BBXBX_ABX_TABLE_04(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_TABLE_04(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402120ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_TABLE_04", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_TABLE_04(a,b) cavm_bbxbx_abx_table_04_t
#define bustype_CAVM_BBXBX_ABX_TABLE_04(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_TABLE_04(a,b) "BBXBX_ABX_TABLE_04"
#define busnum_CAVM_BBXBX_ABX_TABLE_04(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_TABLE_04(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_table_05
 *
 * BBX2 Table Register 5
 * Job Configuration
 */
union cavm_bbxbx_abx_table_05
{
    uint64_t u;
    struct cavm_bbxbx_abx_table_05_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t table_05              : 40; /**< [ 39:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t table_05              : 40; /**< [ 39:  0](R/W) -- */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_table_05_s cn; */
};
typedef union cavm_bbxbx_abx_table_05 cavm_bbxbx_abx_table_05_t;

static inline uint64_t CAVM_BBXBX_ABX_TABLE_05(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_TABLE_05(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402128ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_TABLE_05", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_TABLE_05(a,b) cavm_bbxbx_abx_table_05_t
#define bustype_CAVM_BBXBX_ABX_TABLE_05(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_TABLE_05(a,b) "BBXBX_ABX_TABLE_05"
#define busnum_CAVM_BBXBX_ABX_TABLE_05(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_TABLE_05(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_table_06
 *
 * BBX2 Table Register 6
 * Job Configuration
 */
union cavm_bbxbx_abx_table_06
{
    uint64_t u;
    struct cavm_bbxbx_abx_table_06_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t table_06_0            : 25; /**< [ 56: 32](R/W) -- */
        uint64_t reserved_25_31        : 7;
        uint64_t table_06_1            : 25; /**< [ 24:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t table_06_1            : 25; /**< [ 24:  0](R/W) -- */
        uint64_t reserved_25_31        : 7;
        uint64_t table_06_0            : 25; /**< [ 56: 32](R/W) -- */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_table_06_s cn; */
};
typedef union cavm_bbxbx_abx_table_06 cavm_bbxbx_abx_table_06_t;

static inline uint64_t CAVM_BBXBX_ABX_TABLE_06(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_TABLE_06(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402130ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_TABLE_06", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_TABLE_06(a,b) cavm_bbxbx_abx_table_06_t
#define bustype_CAVM_BBXBX_ABX_TABLE_06(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_TABLE_06(a,b) "BBXBX_ABX_TABLE_06"
#define busnum_CAVM_BBXBX_ABX_TABLE_06(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_TABLE_06(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_table_07
 *
 * BBX2 Table Register 7
 * Job Configuration
 */
union cavm_bbxbx_abx_table_07
{
    uint64_t u;
    struct cavm_bbxbx_abx_table_07_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t table_07_0            : 25; /**< [ 56: 32](R/W) -- */
        uint64_t reserved_25_31        : 7;
        uint64_t table_07_1            : 25; /**< [ 24:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t table_07_1            : 25; /**< [ 24:  0](R/W) -- */
        uint64_t reserved_25_31        : 7;
        uint64_t table_07_0            : 25; /**< [ 56: 32](R/W) -- */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_table_07_s cn; */
};
typedef union cavm_bbxbx_abx_table_07 cavm_bbxbx_abx_table_07_t;

static inline uint64_t CAVM_BBXBX_ABX_TABLE_07(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_TABLE_07(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402138ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_TABLE_07", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_TABLE_07(a,b) cavm_bbxbx_abx_table_07_t
#define bustype_CAVM_BBXBX_ABX_TABLE_07(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_TABLE_07(a,b) "BBXBX_ABX_TABLE_07"
#define busnum_CAVM_BBXBX_ABX_TABLE_07(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_TABLE_07(a,b) (a),(b),-1,-1

/**
 * Register (RSL) bbxb#_ab#_table_08
 *
 * BBX2 Table Register 8
 * Job Configuration
 */
union cavm_bbxbx_abx_table_08
{
    uint64_t u;
    struct cavm_bbxbx_abx_table_08_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t table_08_0            : 25; /**< [ 56: 32](R/W) -- */
        uint64_t reserved_25_31        : 7;
        uint64_t table_08_1            : 25; /**< [ 24:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t table_08_1            : 25; /**< [ 24:  0](R/W) -- */
        uint64_t reserved_25_31        : 7;
        uint64_t table_08_0            : 25; /**< [ 56: 32](R/W) -- */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxbx_abx_table_08_s cn; */
};
typedef union cavm_bbxbx_abx_table_08 cavm_bbxbx_abx_table_08_t;

static inline uint64_t CAVM_BBXBX_ABX_TABLE_08(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXBX_ABX_TABLE_08(unsigned long a, unsigned long b)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && ((a<=1) && (b<=1)))
        return 0x87e043402140ll + 0x400000ll * ((a) & 0x1) + 0x8000ll * ((b) & 0x1);
    __cavm_csr_fatal("BBXBX_ABX_TABLE_08", 2, a, b, 0, 0);
}

#define typedef_CAVM_BBXBX_ABX_TABLE_08(a,b) cavm_bbxbx_abx_table_08_t
#define bustype_CAVM_BBXBX_ABX_TABLE_08(a,b) CSR_TYPE_RSL
#define basename_CAVM_BBXBX_ABX_TABLE_08(a,b) "BBXBX_ABX_TABLE_08"
#define busnum_CAVM_BBXBX_ABX_TABLE_08(a,b) (a)
#define arguments_CAVM_BBXBX_ABX_TABLE_08(a,b) (a),(b),-1,-1

#endif /* __CAVM_CSRS_BBXB_H__ */
