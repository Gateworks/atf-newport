#ifndef __CAVM_CSRS_BBXE_H__
#define __CAVM_CSRS_BBXE_H__
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
 * OcteonTX BBXE.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) bbxe#_config_0
 *
 * BBX5 Configuration Register 0
 * Job Configuration
 */
union cavm_bbxex_config_0
{
    uint64_t u;
    struct cavm_bbxex_config_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t config_f_1            : 17; /**< [ 32: 16](R/W) -- */
        uint64_t reserved_4_15         : 12;
        uint64_t config_f_0            : 4;  /**< [  3:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 4;  /**< [  3:  0](R/W) -- */
        uint64_t reserved_4_15         : 12;
        uint64_t config_f_1            : 17; /**< [ 32: 16](R/W) -- */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_0_s cn; */
};
typedef union cavm_bbxex_config_0 cavm_bbxex_config_0_t;

static inline uint64_t CAVM_BBXEX_CONFIG_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_0(a) cavm_bbxex_config_0_t
#define bustype_CAVM_BBXEX_CONFIG_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_0(a) "BBXEX_CONFIG_0"
#define busnum_CAVM_BBXEX_CONFIG_0(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_1
 *
 * BBX5 Configuration Register 1
 * Job Configuration
 */
union cavm_bbxex_config_1
{
    uint64_t u;
    struct cavm_bbxex_config_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_41_63        : 23;
        uint64_t config_f_1            : 31; /**< [ 40: 10](R/W) -- */
        uint64_t reserved_9            : 1;
        uint64_t config_f_0            : 9;  /**< [  8:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 9;  /**< [  8:  0](R/W) -- */
        uint64_t reserved_9            : 1;
        uint64_t config_f_1            : 31; /**< [ 40: 10](R/W) -- */
        uint64_t reserved_41_63        : 23;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_1_s cn; */
};
typedef union cavm_bbxex_config_1 cavm_bbxex_config_1_t;

static inline uint64_t CAVM_BBXEX_CONFIG_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_1(a) cavm_bbxex_config_1_t
#define bustype_CAVM_BBXEX_CONFIG_1(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_1(a) "BBXEX_CONFIG_1"
#define busnum_CAVM_BBXEX_CONFIG_1(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_1(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_10
 *
 * BBX5 Configuration Register 10
 * Job Configuration
 */
union cavm_bbxex_config_10
{
    uint64_t u;
    struct cavm_bbxex_config_10_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_10_s cn; */
};
typedef union cavm_bbxex_config_10 cavm_bbxex_config_10_t;

static inline uint64_t CAVM_BBXEX_CONFIG_10(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_10(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02050ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_10", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_10(a) cavm_bbxex_config_10_t
#define bustype_CAVM_BBXEX_CONFIG_10(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_10(a) "BBXEX_CONFIG_10"
#define busnum_CAVM_BBXEX_CONFIG_10(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_10(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_100
 *
 * BBX5 Configuration Register 100
 * Job Configuration
 */
union cavm_bbxex_config_100
{
    uint64_t u;
    struct cavm_bbxex_config_100_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_100_s cn; */
};
typedef union cavm_bbxex_config_100 cavm_bbxex_config_100_t;

static inline uint64_t CAVM_BBXEX_CONFIG_100(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_100(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02320ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_100", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_100(a) cavm_bbxex_config_100_t
#define bustype_CAVM_BBXEX_CONFIG_100(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_100(a) "BBXEX_CONFIG_100"
#define busnum_CAVM_BBXEX_CONFIG_100(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_100(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_101
 *
 * BBX5 Configuration Register 101
 * Job Configuration
 */
union cavm_bbxex_config_101
{
    uint64_t u;
    struct cavm_bbxex_config_101_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_101_s cn; */
};
typedef union cavm_bbxex_config_101 cavm_bbxex_config_101_t;

static inline uint64_t CAVM_BBXEX_CONFIG_101(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_101(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02328ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_101", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_101(a) cavm_bbxex_config_101_t
#define bustype_CAVM_BBXEX_CONFIG_101(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_101(a) "BBXEX_CONFIG_101"
#define busnum_CAVM_BBXEX_CONFIG_101(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_101(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_102
 *
 * BBX5 Configuration Register 102
 * Job Configuration
 */
union cavm_bbxex_config_102
{
    uint64_t u;
    struct cavm_bbxex_config_102_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_102_s cn; */
};
typedef union cavm_bbxex_config_102 cavm_bbxex_config_102_t;

static inline uint64_t CAVM_BBXEX_CONFIG_102(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_102(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02330ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_102", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_102(a) cavm_bbxex_config_102_t
#define bustype_CAVM_BBXEX_CONFIG_102(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_102(a) "BBXEX_CONFIG_102"
#define busnum_CAVM_BBXEX_CONFIG_102(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_102(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_103
 *
 * BBX5 Configuration Register 103
 * Job Configuration
 */
union cavm_bbxex_config_103
{
    uint64_t u;
    struct cavm_bbxex_config_103_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_103_s cn; */
};
typedef union cavm_bbxex_config_103 cavm_bbxex_config_103_t;

static inline uint64_t CAVM_BBXEX_CONFIG_103(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_103(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02338ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_103", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_103(a) cavm_bbxex_config_103_t
#define bustype_CAVM_BBXEX_CONFIG_103(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_103(a) "BBXEX_CONFIG_103"
#define busnum_CAVM_BBXEX_CONFIG_103(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_103(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_104
 *
 * BBX5 Configuration Register 104
 * Job Configuration
 */
union cavm_bbxex_config_104
{
    uint64_t u;
    struct cavm_bbxex_config_104_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_104_s cn; */
};
typedef union cavm_bbxex_config_104 cavm_bbxex_config_104_t;

static inline uint64_t CAVM_BBXEX_CONFIG_104(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_104(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02340ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_104", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_104(a) cavm_bbxex_config_104_t
#define bustype_CAVM_BBXEX_CONFIG_104(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_104(a) "BBXEX_CONFIG_104"
#define busnum_CAVM_BBXEX_CONFIG_104(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_104(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_105
 *
 * BBX5 Configuration Register 105
 * Job Configuration
 */
union cavm_bbxex_config_105
{
    uint64_t u;
    struct cavm_bbxex_config_105_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_105_s cn; */
};
typedef union cavm_bbxex_config_105 cavm_bbxex_config_105_t;

static inline uint64_t CAVM_BBXEX_CONFIG_105(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_105(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02348ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_105", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_105(a) cavm_bbxex_config_105_t
#define bustype_CAVM_BBXEX_CONFIG_105(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_105(a) "BBXEX_CONFIG_105"
#define busnum_CAVM_BBXEX_CONFIG_105(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_105(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_106
 *
 * BBX5 Configuration Register 106
 * Job Configuration
 */
union cavm_bbxex_config_106
{
    uint64_t u;
    struct cavm_bbxex_config_106_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_106_s cn; */
};
typedef union cavm_bbxex_config_106 cavm_bbxex_config_106_t;

static inline uint64_t CAVM_BBXEX_CONFIG_106(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_106(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02350ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_106", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_106(a) cavm_bbxex_config_106_t
#define bustype_CAVM_BBXEX_CONFIG_106(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_106(a) "BBXEX_CONFIG_106"
#define busnum_CAVM_BBXEX_CONFIG_106(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_106(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_107
 *
 * BBX5 Configuration Register 107
 * Job Configuration
 */
union cavm_bbxex_config_107
{
    uint64_t u;
    struct cavm_bbxex_config_107_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_107_s cn; */
};
typedef union cavm_bbxex_config_107 cavm_bbxex_config_107_t;

static inline uint64_t CAVM_BBXEX_CONFIG_107(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_107(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02358ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_107", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_107(a) cavm_bbxex_config_107_t
#define bustype_CAVM_BBXEX_CONFIG_107(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_107(a) "BBXEX_CONFIG_107"
#define busnum_CAVM_BBXEX_CONFIG_107(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_107(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_108
 *
 * BBX5 Configuration Register 108
 * Job Configuration
 */
union cavm_bbxex_config_108
{
    uint64_t u;
    struct cavm_bbxex_config_108_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_108_s cn; */
};
typedef union cavm_bbxex_config_108 cavm_bbxex_config_108_t;

static inline uint64_t CAVM_BBXEX_CONFIG_108(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_108(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02360ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_108", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_108(a) cavm_bbxex_config_108_t
#define bustype_CAVM_BBXEX_CONFIG_108(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_108(a) "BBXEX_CONFIG_108"
#define busnum_CAVM_BBXEX_CONFIG_108(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_108(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_109
 *
 * BBX5 Configuration Register 109
 * Job Configuration
 */
union cavm_bbxex_config_109
{
    uint64_t u;
    struct cavm_bbxex_config_109_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_109_s cn; */
};
typedef union cavm_bbxex_config_109 cavm_bbxex_config_109_t;

static inline uint64_t CAVM_BBXEX_CONFIG_109(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_109(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02368ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_109", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_109(a) cavm_bbxex_config_109_t
#define bustype_CAVM_BBXEX_CONFIG_109(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_109(a) "BBXEX_CONFIG_109"
#define busnum_CAVM_BBXEX_CONFIG_109(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_109(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_11
 *
 * BBX5 Configuration Register 11
 * Job Configuration
 */
union cavm_bbxex_config_11
{
    uint64_t u;
    struct cavm_bbxex_config_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_11_s cn; */
};
typedef union cavm_bbxex_config_11 cavm_bbxex_config_11_t;

static inline uint64_t CAVM_BBXEX_CONFIG_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02058ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_11", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_11(a) cavm_bbxex_config_11_t
#define bustype_CAVM_BBXEX_CONFIG_11(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_11(a) "BBXEX_CONFIG_11"
#define busnum_CAVM_BBXEX_CONFIG_11(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_11(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_110
 *
 * BBX5 Configuration Register 110
 * Job Configuration
 */
union cavm_bbxex_config_110
{
    uint64_t u;
    struct cavm_bbxex_config_110_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_110_s cn; */
};
typedef union cavm_bbxex_config_110 cavm_bbxex_config_110_t;

static inline uint64_t CAVM_BBXEX_CONFIG_110(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_110(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02370ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_110", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_110(a) cavm_bbxex_config_110_t
#define bustype_CAVM_BBXEX_CONFIG_110(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_110(a) "BBXEX_CONFIG_110"
#define busnum_CAVM_BBXEX_CONFIG_110(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_110(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_111
 *
 * BBX5 Configuration Register 111
 * Job Configuration
 */
union cavm_bbxex_config_111
{
    uint64_t u;
    struct cavm_bbxex_config_111_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_111_s cn; */
};
typedef union cavm_bbxex_config_111 cavm_bbxex_config_111_t;

static inline uint64_t CAVM_BBXEX_CONFIG_111(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_111(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02378ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_111", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_111(a) cavm_bbxex_config_111_t
#define bustype_CAVM_BBXEX_CONFIG_111(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_111(a) "BBXEX_CONFIG_111"
#define busnum_CAVM_BBXEX_CONFIG_111(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_111(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_112
 *
 * BBX5 Configuration Register 112
 * Job Configuration
 */
union cavm_bbxex_config_112
{
    uint64_t u;
    struct cavm_bbxex_config_112_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_112_s cn; */
};
typedef union cavm_bbxex_config_112 cavm_bbxex_config_112_t;

static inline uint64_t CAVM_BBXEX_CONFIG_112(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_112(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02380ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_112", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_112(a) cavm_bbxex_config_112_t
#define bustype_CAVM_BBXEX_CONFIG_112(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_112(a) "BBXEX_CONFIG_112"
#define busnum_CAVM_BBXEX_CONFIG_112(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_112(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_113
 *
 * BBX5 Configuration Register 113
 * Job Configuration
 */
union cavm_bbxex_config_113
{
    uint64_t u;
    struct cavm_bbxex_config_113_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_113_s cn; */
};
typedef union cavm_bbxex_config_113 cavm_bbxex_config_113_t;

static inline uint64_t CAVM_BBXEX_CONFIG_113(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_113(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02388ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_113", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_113(a) cavm_bbxex_config_113_t
#define bustype_CAVM_BBXEX_CONFIG_113(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_113(a) "BBXEX_CONFIG_113"
#define busnum_CAVM_BBXEX_CONFIG_113(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_113(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_114
 *
 * BBX5 Configuration Register 114
 * Job Configuration
 */
union cavm_bbxex_config_114
{
    uint64_t u;
    struct cavm_bbxex_config_114_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_114_s cn; */
};
typedef union cavm_bbxex_config_114 cavm_bbxex_config_114_t;

static inline uint64_t CAVM_BBXEX_CONFIG_114(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_114(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02390ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_114", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_114(a) cavm_bbxex_config_114_t
#define bustype_CAVM_BBXEX_CONFIG_114(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_114(a) "BBXEX_CONFIG_114"
#define busnum_CAVM_BBXEX_CONFIG_114(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_114(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_115
 *
 * BBX5 Configuration Register 115
 * Job Configuration
 */
union cavm_bbxex_config_115
{
    uint64_t u;
    struct cavm_bbxex_config_115_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_115_s cn; */
};
typedef union cavm_bbxex_config_115 cavm_bbxex_config_115_t;

static inline uint64_t CAVM_BBXEX_CONFIG_115(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_115(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02398ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_115", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_115(a) cavm_bbxex_config_115_t
#define bustype_CAVM_BBXEX_CONFIG_115(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_115(a) "BBXEX_CONFIG_115"
#define busnum_CAVM_BBXEX_CONFIG_115(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_115(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_116
 *
 * BBX5 Configuration Register 116
 * Job Configuration
 */
union cavm_bbxex_config_116
{
    uint64_t u;
    struct cavm_bbxex_config_116_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_116_s cn; */
};
typedef union cavm_bbxex_config_116 cavm_bbxex_config_116_t;

static inline uint64_t CAVM_BBXEX_CONFIG_116(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_116(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_116", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_116(a) cavm_bbxex_config_116_t
#define bustype_CAVM_BBXEX_CONFIG_116(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_116(a) "BBXEX_CONFIG_116"
#define busnum_CAVM_BBXEX_CONFIG_116(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_116(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_117
 *
 * BBX5 Configuration Register 117
 * Job Configuration
 */
union cavm_bbxex_config_117
{
    uint64_t u;
    struct cavm_bbxex_config_117_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_117_s cn; */
};
typedef union cavm_bbxex_config_117 cavm_bbxex_config_117_t;

static inline uint64_t CAVM_BBXEX_CONFIG_117(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_117(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_117", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_117(a) cavm_bbxex_config_117_t
#define bustype_CAVM_BBXEX_CONFIG_117(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_117(a) "BBXEX_CONFIG_117"
#define busnum_CAVM_BBXEX_CONFIG_117(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_117(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_118
 *
 * BBX5 Configuration Register 118
 * Job Configuration
 */
union cavm_bbxex_config_118
{
    uint64_t u;
    struct cavm_bbxex_config_118_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_118_s cn; */
};
typedef union cavm_bbxex_config_118 cavm_bbxex_config_118_t;

static inline uint64_t CAVM_BBXEX_CONFIG_118(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_118(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_118", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_118(a) cavm_bbxex_config_118_t
#define bustype_CAVM_BBXEX_CONFIG_118(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_118(a) "BBXEX_CONFIG_118"
#define busnum_CAVM_BBXEX_CONFIG_118(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_118(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_119
 *
 * BBX5 Configuration Register 119
 * Job Configuration
 */
union cavm_bbxex_config_119
{
    uint64_t u;
    struct cavm_bbxex_config_119_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_119_s cn; */
};
typedef union cavm_bbxex_config_119 cavm_bbxex_config_119_t;

static inline uint64_t CAVM_BBXEX_CONFIG_119(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_119(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_119", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_119(a) cavm_bbxex_config_119_t
#define bustype_CAVM_BBXEX_CONFIG_119(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_119(a) "BBXEX_CONFIG_119"
#define busnum_CAVM_BBXEX_CONFIG_119(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_119(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_12
 *
 * BBX5 Configuration Register 12
 * Job Configuration
 */
union cavm_bbxex_config_12
{
    uint64_t u;
    struct cavm_bbxex_config_12_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_12_s cn; */
};
typedef union cavm_bbxex_config_12 cavm_bbxex_config_12_t;

static inline uint64_t CAVM_BBXEX_CONFIG_12(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_12(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02060ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_12", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_12(a) cavm_bbxex_config_12_t
#define bustype_CAVM_BBXEX_CONFIG_12(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_12(a) "BBXEX_CONFIG_12"
#define busnum_CAVM_BBXEX_CONFIG_12(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_12(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_120
 *
 * BBX5 Configuration Register 120
 * Job Configuration
 */
union cavm_bbxex_config_120
{
    uint64_t u;
    struct cavm_bbxex_config_120_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_120_s cn; */
};
typedef union cavm_bbxex_config_120 cavm_bbxex_config_120_t;

static inline uint64_t CAVM_BBXEX_CONFIG_120(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_120(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_120", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_120(a) cavm_bbxex_config_120_t
#define bustype_CAVM_BBXEX_CONFIG_120(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_120(a) "BBXEX_CONFIG_120"
#define busnum_CAVM_BBXEX_CONFIG_120(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_120(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_121
 *
 * BBX5 Configuration Register 121
 * Job Configuration
 */
union cavm_bbxex_config_121
{
    uint64_t u;
    struct cavm_bbxex_config_121_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_121_s cn; */
};
typedef union cavm_bbxex_config_121 cavm_bbxex_config_121_t;

static inline uint64_t CAVM_BBXEX_CONFIG_121(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_121(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_121", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_121(a) cavm_bbxex_config_121_t
#define bustype_CAVM_BBXEX_CONFIG_121(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_121(a) "BBXEX_CONFIG_121"
#define busnum_CAVM_BBXEX_CONFIG_121(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_121(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_122
 *
 * BBX5 Configuration Register 122
 * Job Configuration
 */
union cavm_bbxex_config_122
{
    uint64_t u;
    struct cavm_bbxex_config_122_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_122_s cn; */
};
typedef union cavm_bbxex_config_122 cavm_bbxex_config_122_t;

static inline uint64_t CAVM_BBXEX_CONFIG_122(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_122(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_122", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_122(a) cavm_bbxex_config_122_t
#define bustype_CAVM_BBXEX_CONFIG_122(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_122(a) "BBXEX_CONFIG_122"
#define busnum_CAVM_BBXEX_CONFIG_122(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_122(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_123
 *
 * BBX5 Configuration Register 123
 * Job Configuration
 */
union cavm_bbxex_config_123
{
    uint64_t u;
    struct cavm_bbxex_config_123_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_123_s cn; */
};
typedef union cavm_bbxex_config_123 cavm_bbxex_config_123_t;

static inline uint64_t CAVM_BBXEX_CONFIG_123(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_123(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_123", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_123(a) cavm_bbxex_config_123_t
#define bustype_CAVM_BBXEX_CONFIG_123(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_123(a) "BBXEX_CONFIG_123"
#define busnum_CAVM_BBXEX_CONFIG_123(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_123(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_124
 *
 * BBX5 Configuration Register 124
 * Job Configuration
 */
union cavm_bbxex_config_124
{
    uint64_t u;
    struct cavm_bbxex_config_124_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_124_s cn; */
};
typedef union cavm_bbxex_config_124 cavm_bbxex_config_124_t;

static inline uint64_t CAVM_BBXEX_CONFIG_124(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_124(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_124", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_124(a) cavm_bbxex_config_124_t
#define bustype_CAVM_BBXEX_CONFIG_124(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_124(a) "BBXEX_CONFIG_124"
#define busnum_CAVM_BBXEX_CONFIG_124(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_124(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_125
 *
 * BBX5 Configuration Register 125
 * Job Configuration
 */
union cavm_bbxex_config_125
{
    uint64_t u;
    struct cavm_bbxex_config_125_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_125_s cn; */
};
typedef union cavm_bbxex_config_125 cavm_bbxex_config_125_t;

static inline uint64_t CAVM_BBXEX_CONFIG_125(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_125(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_125", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_125(a) cavm_bbxex_config_125_t
#define bustype_CAVM_BBXEX_CONFIG_125(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_125(a) "BBXEX_CONFIG_125"
#define busnum_CAVM_BBXEX_CONFIG_125(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_125(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_126
 *
 * BBX5 Configuration Register 126
 * Job Configuration
 */
union cavm_bbxex_config_126
{
    uint64_t u;
    struct cavm_bbxex_config_126_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_126_s cn; */
};
typedef union cavm_bbxex_config_126 cavm_bbxex_config_126_t;

static inline uint64_t CAVM_BBXEX_CONFIG_126(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_126(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_126", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_126(a) cavm_bbxex_config_126_t
#define bustype_CAVM_BBXEX_CONFIG_126(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_126(a) "BBXEX_CONFIG_126"
#define busnum_CAVM_BBXEX_CONFIG_126(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_126(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_127
 *
 * BBX5 Configuration Register 127
 * Job Configuration
 */
union cavm_bbxex_config_127
{
    uint64_t u;
    struct cavm_bbxex_config_127_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_127_s cn; */
};
typedef union cavm_bbxex_config_127 cavm_bbxex_config_127_t;

static inline uint64_t CAVM_BBXEX_CONFIG_127(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_127(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c023f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_127", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_127(a) cavm_bbxex_config_127_t
#define bustype_CAVM_BBXEX_CONFIG_127(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_127(a) "BBXEX_CONFIG_127"
#define busnum_CAVM_BBXEX_CONFIG_127(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_127(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_128
 *
 * BBX5 Configuration Register 128
 * Job Configuration
 */
union cavm_bbxex_config_128
{
    uint64_t u;
    struct cavm_bbxex_config_128_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_128_s cn; */
};
typedef union cavm_bbxex_config_128 cavm_bbxex_config_128_t;

static inline uint64_t CAVM_BBXEX_CONFIG_128(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_128(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02400ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_128", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_128(a) cavm_bbxex_config_128_t
#define bustype_CAVM_BBXEX_CONFIG_128(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_128(a) "BBXEX_CONFIG_128"
#define busnum_CAVM_BBXEX_CONFIG_128(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_128(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_129
 *
 * BBX5 Configuration Register 129
 * Job Configuration
 */
union cavm_bbxex_config_129
{
    uint64_t u;
    struct cavm_bbxex_config_129_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_129_s cn; */
};
typedef union cavm_bbxex_config_129 cavm_bbxex_config_129_t;

static inline uint64_t CAVM_BBXEX_CONFIG_129(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_129(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02408ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_129", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_129(a) cavm_bbxex_config_129_t
#define bustype_CAVM_BBXEX_CONFIG_129(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_129(a) "BBXEX_CONFIG_129"
#define busnum_CAVM_BBXEX_CONFIG_129(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_129(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_13
 *
 * BBX5 Configuration Register 13
 * Job Configuration
 */
union cavm_bbxex_config_13
{
    uint64_t u;
    struct cavm_bbxex_config_13_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_13_s cn; */
};
typedef union cavm_bbxex_config_13 cavm_bbxex_config_13_t;

static inline uint64_t CAVM_BBXEX_CONFIG_13(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_13(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02068ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_13", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_13(a) cavm_bbxex_config_13_t
#define bustype_CAVM_BBXEX_CONFIG_13(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_13(a) "BBXEX_CONFIG_13"
#define busnum_CAVM_BBXEX_CONFIG_13(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_13(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_130
 *
 * BBX5 Configuration Register 130
 * Job Configuration
 */
union cavm_bbxex_config_130
{
    uint64_t u;
    struct cavm_bbxex_config_130_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_130_s cn; */
};
typedef union cavm_bbxex_config_130 cavm_bbxex_config_130_t;

static inline uint64_t CAVM_BBXEX_CONFIG_130(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_130(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02410ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_130", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_130(a) cavm_bbxex_config_130_t
#define bustype_CAVM_BBXEX_CONFIG_130(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_130(a) "BBXEX_CONFIG_130"
#define busnum_CAVM_BBXEX_CONFIG_130(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_130(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_131
 *
 * BBX5 Configuration Register 131
 * Job Configuration
 */
union cavm_bbxex_config_131
{
    uint64_t u;
    struct cavm_bbxex_config_131_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_131_s cn; */
};
typedef union cavm_bbxex_config_131 cavm_bbxex_config_131_t;

static inline uint64_t CAVM_BBXEX_CONFIG_131(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_131(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02418ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_131", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_131(a) cavm_bbxex_config_131_t
#define bustype_CAVM_BBXEX_CONFIG_131(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_131(a) "BBXEX_CONFIG_131"
#define busnum_CAVM_BBXEX_CONFIG_131(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_131(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_132
 *
 * BBX5 Configuration Register 132
 * Job Configuration
 */
union cavm_bbxex_config_132
{
    uint64_t u;
    struct cavm_bbxex_config_132_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_132_s cn; */
};
typedef union cavm_bbxex_config_132 cavm_bbxex_config_132_t;

static inline uint64_t CAVM_BBXEX_CONFIG_132(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_132(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02420ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_132", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_132(a) cavm_bbxex_config_132_t
#define bustype_CAVM_BBXEX_CONFIG_132(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_132(a) "BBXEX_CONFIG_132"
#define busnum_CAVM_BBXEX_CONFIG_132(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_132(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_133
 *
 * BBX5 Configuration Register 133
 * Job Configuration
 */
union cavm_bbxex_config_133
{
    uint64_t u;
    struct cavm_bbxex_config_133_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_133_s cn; */
};
typedef union cavm_bbxex_config_133 cavm_bbxex_config_133_t;

static inline uint64_t CAVM_BBXEX_CONFIG_133(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_133(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02428ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_133", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_133(a) cavm_bbxex_config_133_t
#define bustype_CAVM_BBXEX_CONFIG_133(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_133(a) "BBXEX_CONFIG_133"
#define busnum_CAVM_BBXEX_CONFIG_133(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_133(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_134
 *
 * BBX5 Configuration Register 134
 * Job Configuration
 */
union cavm_bbxex_config_134
{
    uint64_t u;
    struct cavm_bbxex_config_134_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_134_s cn; */
};
typedef union cavm_bbxex_config_134 cavm_bbxex_config_134_t;

static inline uint64_t CAVM_BBXEX_CONFIG_134(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_134(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02430ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_134", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_134(a) cavm_bbxex_config_134_t
#define bustype_CAVM_BBXEX_CONFIG_134(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_134(a) "BBXEX_CONFIG_134"
#define busnum_CAVM_BBXEX_CONFIG_134(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_134(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_135
 *
 * BBX5 Configuration Register 135
 * Job Configuration
 */
union cavm_bbxex_config_135
{
    uint64_t u;
    struct cavm_bbxex_config_135_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_135_s cn; */
};
typedef union cavm_bbxex_config_135 cavm_bbxex_config_135_t;

static inline uint64_t CAVM_BBXEX_CONFIG_135(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_135(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02438ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_135", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_135(a) cavm_bbxex_config_135_t
#define bustype_CAVM_BBXEX_CONFIG_135(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_135(a) "BBXEX_CONFIG_135"
#define busnum_CAVM_BBXEX_CONFIG_135(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_135(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_136
 *
 * BBX5 Configuration Register 136
 * Job Configuration
 */
union cavm_bbxex_config_136
{
    uint64_t u;
    struct cavm_bbxex_config_136_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_136_s cn; */
};
typedef union cavm_bbxex_config_136 cavm_bbxex_config_136_t;

static inline uint64_t CAVM_BBXEX_CONFIG_136(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_136(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02440ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_136", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_136(a) cavm_bbxex_config_136_t
#define bustype_CAVM_BBXEX_CONFIG_136(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_136(a) "BBXEX_CONFIG_136"
#define busnum_CAVM_BBXEX_CONFIG_136(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_136(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_137
 *
 * BBX5 Configuration Register 137
 * Job Configuration
 */
union cavm_bbxex_config_137
{
    uint64_t u;
    struct cavm_bbxex_config_137_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_137_s cn; */
};
typedef union cavm_bbxex_config_137 cavm_bbxex_config_137_t;

static inline uint64_t CAVM_BBXEX_CONFIG_137(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_137(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02448ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_137", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_137(a) cavm_bbxex_config_137_t
#define bustype_CAVM_BBXEX_CONFIG_137(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_137(a) "BBXEX_CONFIG_137"
#define busnum_CAVM_BBXEX_CONFIG_137(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_137(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_138
 *
 * BBX5 Configuration Register 138
 * Job Configuration
 */
union cavm_bbxex_config_138
{
    uint64_t u;
    struct cavm_bbxex_config_138_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_138_s cn; */
};
typedef union cavm_bbxex_config_138 cavm_bbxex_config_138_t;

static inline uint64_t CAVM_BBXEX_CONFIG_138(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_138(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02450ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_138", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_138(a) cavm_bbxex_config_138_t
#define bustype_CAVM_BBXEX_CONFIG_138(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_138(a) "BBXEX_CONFIG_138"
#define busnum_CAVM_BBXEX_CONFIG_138(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_138(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_139
 *
 * BBX5 Configuration Register 139
 * Job Configuration
 */
union cavm_bbxex_config_139
{
    uint64_t u;
    struct cavm_bbxex_config_139_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_139_s cn; */
};
typedef union cavm_bbxex_config_139 cavm_bbxex_config_139_t;

static inline uint64_t CAVM_BBXEX_CONFIG_139(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_139(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02458ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_139", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_139(a) cavm_bbxex_config_139_t
#define bustype_CAVM_BBXEX_CONFIG_139(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_139(a) "BBXEX_CONFIG_139"
#define busnum_CAVM_BBXEX_CONFIG_139(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_139(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_14
 *
 * BBX5 Configuration Register 14
 * Job Configuration
 */
union cavm_bbxex_config_14
{
    uint64_t u;
    struct cavm_bbxex_config_14_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_14_s cn; */
};
typedef union cavm_bbxex_config_14 cavm_bbxex_config_14_t;

static inline uint64_t CAVM_BBXEX_CONFIG_14(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_14(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02070ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_14", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_14(a) cavm_bbxex_config_14_t
#define bustype_CAVM_BBXEX_CONFIG_14(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_14(a) "BBXEX_CONFIG_14"
#define busnum_CAVM_BBXEX_CONFIG_14(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_14(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_140
 *
 * BBX5 Configuration Register 140
 * Job Configuration
 */
union cavm_bbxex_config_140
{
    uint64_t u;
    struct cavm_bbxex_config_140_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_140_s cn; */
};
typedef union cavm_bbxex_config_140 cavm_bbxex_config_140_t;

static inline uint64_t CAVM_BBXEX_CONFIG_140(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_140(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02460ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_140", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_140(a) cavm_bbxex_config_140_t
#define bustype_CAVM_BBXEX_CONFIG_140(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_140(a) "BBXEX_CONFIG_140"
#define busnum_CAVM_BBXEX_CONFIG_140(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_140(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_141
 *
 * BBX5 Configuration Register 141
 * Job Configuration
 */
union cavm_bbxex_config_141
{
    uint64_t u;
    struct cavm_bbxex_config_141_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_141_s cn; */
};
typedef union cavm_bbxex_config_141 cavm_bbxex_config_141_t;

static inline uint64_t CAVM_BBXEX_CONFIG_141(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_141(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02468ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_141", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_141(a) cavm_bbxex_config_141_t
#define bustype_CAVM_BBXEX_CONFIG_141(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_141(a) "BBXEX_CONFIG_141"
#define busnum_CAVM_BBXEX_CONFIG_141(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_141(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_142
 *
 * BBX5 Configuration Register 142
 * Job Configuration
 */
union cavm_bbxex_config_142
{
    uint64_t u;
    struct cavm_bbxex_config_142_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_142_s cn; */
};
typedef union cavm_bbxex_config_142 cavm_bbxex_config_142_t;

static inline uint64_t CAVM_BBXEX_CONFIG_142(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_142(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02470ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_142", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_142(a) cavm_bbxex_config_142_t
#define bustype_CAVM_BBXEX_CONFIG_142(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_142(a) "BBXEX_CONFIG_142"
#define busnum_CAVM_BBXEX_CONFIG_142(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_142(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_143
 *
 * BBX5 Configuration Register 143
 * Job Configuration
 */
union cavm_bbxex_config_143
{
    uint64_t u;
    struct cavm_bbxex_config_143_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_143_s cn; */
};
typedef union cavm_bbxex_config_143 cavm_bbxex_config_143_t;

static inline uint64_t CAVM_BBXEX_CONFIG_143(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_143(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02478ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_143", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_143(a) cavm_bbxex_config_143_t
#define bustype_CAVM_BBXEX_CONFIG_143(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_143(a) "BBXEX_CONFIG_143"
#define busnum_CAVM_BBXEX_CONFIG_143(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_143(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_144
 *
 * BBX5 Configuration Register 144
 * Job Configuration
 */
union cavm_bbxex_config_144
{
    uint64_t u;
    struct cavm_bbxex_config_144_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_144_s cn; */
};
typedef union cavm_bbxex_config_144 cavm_bbxex_config_144_t;

static inline uint64_t CAVM_BBXEX_CONFIG_144(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_144(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02480ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_144", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_144(a) cavm_bbxex_config_144_t
#define bustype_CAVM_BBXEX_CONFIG_144(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_144(a) "BBXEX_CONFIG_144"
#define busnum_CAVM_BBXEX_CONFIG_144(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_144(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_145
 *
 * BBX5 Configuration Register 145
 * Job Configuration
 */
union cavm_bbxex_config_145
{
    uint64_t u;
    struct cavm_bbxex_config_145_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_145_s cn; */
};
typedef union cavm_bbxex_config_145 cavm_bbxex_config_145_t;

static inline uint64_t CAVM_BBXEX_CONFIG_145(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_145(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02488ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_145", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_145(a) cavm_bbxex_config_145_t
#define bustype_CAVM_BBXEX_CONFIG_145(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_145(a) "BBXEX_CONFIG_145"
#define busnum_CAVM_BBXEX_CONFIG_145(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_145(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_146
 *
 * BBX5 Configuration Register 146
 * Job Configuration
 */
union cavm_bbxex_config_146
{
    uint64_t u;
    struct cavm_bbxex_config_146_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_146_s cn; */
};
typedef union cavm_bbxex_config_146 cavm_bbxex_config_146_t;

static inline uint64_t CAVM_BBXEX_CONFIG_146(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_146(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02490ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_146", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_146(a) cavm_bbxex_config_146_t
#define bustype_CAVM_BBXEX_CONFIG_146(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_146(a) "BBXEX_CONFIG_146"
#define busnum_CAVM_BBXEX_CONFIG_146(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_146(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_147
 *
 * BBX5 Configuration Register 147
 * Job Configuration
 */
union cavm_bbxex_config_147
{
    uint64_t u;
    struct cavm_bbxex_config_147_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_147_s cn; */
};
typedef union cavm_bbxex_config_147 cavm_bbxex_config_147_t;

static inline uint64_t CAVM_BBXEX_CONFIG_147(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_147(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02498ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_147", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_147(a) cavm_bbxex_config_147_t
#define bustype_CAVM_BBXEX_CONFIG_147(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_147(a) "BBXEX_CONFIG_147"
#define busnum_CAVM_BBXEX_CONFIG_147(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_147(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_148
 *
 * BBX5 Configuration Register 148
 * Job Configuration
 */
union cavm_bbxex_config_148
{
    uint64_t u;
    struct cavm_bbxex_config_148_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_148_s cn; */
};
typedef union cavm_bbxex_config_148 cavm_bbxex_config_148_t;

static inline uint64_t CAVM_BBXEX_CONFIG_148(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_148(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_148", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_148(a) cavm_bbxex_config_148_t
#define bustype_CAVM_BBXEX_CONFIG_148(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_148(a) "BBXEX_CONFIG_148"
#define busnum_CAVM_BBXEX_CONFIG_148(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_148(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_149
 *
 * BBX5 Configuration Register 149
 * Job Configuration
 */
union cavm_bbxex_config_149
{
    uint64_t u;
    struct cavm_bbxex_config_149_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_149_s cn; */
};
typedef union cavm_bbxex_config_149 cavm_bbxex_config_149_t;

static inline uint64_t CAVM_BBXEX_CONFIG_149(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_149(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_149", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_149(a) cavm_bbxex_config_149_t
#define bustype_CAVM_BBXEX_CONFIG_149(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_149(a) "BBXEX_CONFIG_149"
#define busnum_CAVM_BBXEX_CONFIG_149(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_149(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_15
 *
 * BBX5 Configuration Register 15
 * Job Configuration
 */
union cavm_bbxex_config_15
{
    uint64_t u;
    struct cavm_bbxex_config_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_15_s cn; */
};
typedef union cavm_bbxex_config_15 cavm_bbxex_config_15_t;

static inline uint64_t CAVM_BBXEX_CONFIG_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02078ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_15", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_15(a) cavm_bbxex_config_15_t
#define bustype_CAVM_BBXEX_CONFIG_15(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_15(a) "BBXEX_CONFIG_15"
#define busnum_CAVM_BBXEX_CONFIG_15(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_15(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_150
 *
 * BBX5 Configuration Register 150
 * Job Configuration
 */
union cavm_bbxex_config_150
{
    uint64_t u;
    struct cavm_bbxex_config_150_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_150_s cn; */
};
typedef union cavm_bbxex_config_150 cavm_bbxex_config_150_t;

static inline uint64_t CAVM_BBXEX_CONFIG_150(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_150(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_150", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_150(a) cavm_bbxex_config_150_t
#define bustype_CAVM_BBXEX_CONFIG_150(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_150(a) "BBXEX_CONFIG_150"
#define busnum_CAVM_BBXEX_CONFIG_150(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_150(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_151
 *
 * BBX5 Configuration Register 151
 * Job Configuration
 */
union cavm_bbxex_config_151
{
    uint64_t u;
    struct cavm_bbxex_config_151_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_151_s cn; */
};
typedef union cavm_bbxex_config_151 cavm_bbxex_config_151_t;

static inline uint64_t CAVM_BBXEX_CONFIG_151(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_151(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_151", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_151(a) cavm_bbxex_config_151_t
#define bustype_CAVM_BBXEX_CONFIG_151(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_151(a) "BBXEX_CONFIG_151"
#define busnum_CAVM_BBXEX_CONFIG_151(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_151(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_152
 *
 * BBX5 Configuration Register 152
 * Job Configuration
 */
union cavm_bbxex_config_152
{
    uint64_t u;
    struct cavm_bbxex_config_152_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_152_s cn; */
};
typedef union cavm_bbxex_config_152 cavm_bbxex_config_152_t;

static inline uint64_t CAVM_BBXEX_CONFIG_152(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_152(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_152", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_152(a) cavm_bbxex_config_152_t
#define bustype_CAVM_BBXEX_CONFIG_152(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_152(a) "BBXEX_CONFIG_152"
#define busnum_CAVM_BBXEX_CONFIG_152(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_152(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_153
 *
 * BBX5 Configuration Register 153
 * Job Configuration
 */
union cavm_bbxex_config_153
{
    uint64_t u;
    struct cavm_bbxex_config_153_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_153_s cn; */
};
typedef union cavm_bbxex_config_153 cavm_bbxex_config_153_t;

static inline uint64_t CAVM_BBXEX_CONFIG_153(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_153(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_153", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_153(a) cavm_bbxex_config_153_t
#define bustype_CAVM_BBXEX_CONFIG_153(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_153(a) "BBXEX_CONFIG_153"
#define busnum_CAVM_BBXEX_CONFIG_153(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_153(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_154
 *
 * BBX5 Configuration Register 154
 * Job Configuration
 */
union cavm_bbxex_config_154
{
    uint64_t u;
    struct cavm_bbxex_config_154_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_154_s cn; */
};
typedef union cavm_bbxex_config_154 cavm_bbxex_config_154_t;

static inline uint64_t CAVM_BBXEX_CONFIG_154(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_154(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_154", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_154(a) cavm_bbxex_config_154_t
#define bustype_CAVM_BBXEX_CONFIG_154(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_154(a) "BBXEX_CONFIG_154"
#define busnum_CAVM_BBXEX_CONFIG_154(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_154(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_155
 *
 * BBX5 Configuration Register 155
 * Job Configuration
 */
union cavm_bbxex_config_155
{
    uint64_t u;
    struct cavm_bbxex_config_155_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_155_s cn; */
};
typedef union cavm_bbxex_config_155 cavm_bbxex_config_155_t;

static inline uint64_t CAVM_BBXEX_CONFIG_155(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_155(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_155", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_155(a) cavm_bbxex_config_155_t
#define bustype_CAVM_BBXEX_CONFIG_155(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_155(a) "BBXEX_CONFIG_155"
#define busnum_CAVM_BBXEX_CONFIG_155(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_155(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_156
 *
 * BBX5 Configuration Register 156
 * Job Configuration
 */
union cavm_bbxex_config_156
{
    uint64_t u;
    struct cavm_bbxex_config_156_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_156_s cn; */
};
typedef union cavm_bbxex_config_156 cavm_bbxex_config_156_t;

static inline uint64_t CAVM_BBXEX_CONFIG_156(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_156(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_156", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_156(a) cavm_bbxex_config_156_t
#define bustype_CAVM_BBXEX_CONFIG_156(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_156(a) "BBXEX_CONFIG_156"
#define busnum_CAVM_BBXEX_CONFIG_156(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_156(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_157
 *
 * BBX5 Configuration Register 157
 * Job Configuration
 */
union cavm_bbxex_config_157
{
    uint64_t u;
    struct cavm_bbxex_config_157_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_157_s cn; */
};
typedef union cavm_bbxex_config_157 cavm_bbxex_config_157_t;

static inline uint64_t CAVM_BBXEX_CONFIG_157(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_157(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_157", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_157(a) cavm_bbxex_config_157_t
#define bustype_CAVM_BBXEX_CONFIG_157(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_157(a) "BBXEX_CONFIG_157"
#define busnum_CAVM_BBXEX_CONFIG_157(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_157(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_158
 *
 * BBX5 Configuration Register 158
 * Job Configuration
 */
union cavm_bbxex_config_158
{
    uint64_t u;
    struct cavm_bbxex_config_158_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_158_s cn; */
};
typedef union cavm_bbxex_config_158 cavm_bbxex_config_158_t;

static inline uint64_t CAVM_BBXEX_CONFIG_158(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_158(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_158", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_158(a) cavm_bbxex_config_158_t
#define bustype_CAVM_BBXEX_CONFIG_158(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_158(a) "BBXEX_CONFIG_158"
#define busnum_CAVM_BBXEX_CONFIG_158(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_158(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_159
 *
 * BBX5 Configuration Register 159
 * Job Configuration
 */
union cavm_bbxex_config_159
{
    uint64_t u;
    struct cavm_bbxex_config_159_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_159_s cn; */
};
typedef union cavm_bbxex_config_159 cavm_bbxex_config_159_t;

static inline uint64_t CAVM_BBXEX_CONFIG_159(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_159(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c024f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_159", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_159(a) cavm_bbxex_config_159_t
#define bustype_CAVM_BBXEX_CONFIG_159(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_159(a) "BBXEX_CONFIG_159"
#define busnum_CAVM_BBXEX_CONFIG_159(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_159(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_16
 *
 * BBX5 Configuration Register 16
 * Job Configuration
 */
union cavm_bbxex_config_16
{
    uint64_t u;
    struct cavm_bbxex_config_16_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_16_s cn; */
};
typedef union cavm_bbxex_config_16 cavm_bbxex_config_16_t;

static inline uint64_t CAVM_BBXEX_CONFIG_16(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_16(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02080ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_16", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_16(a) cavm_bbxex_config_16_t
#define bustype_CAVM_BBXEX_CONFIG_16(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_16(a) "BBXEX_CONFIG_16"
#define busnum_CAVM_BBXEX_CONFIG_16(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_16(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_160
 *
 * BBX5 Configuration Register 160
 * Job Configuration
 */
union cavm_bbxex_config_160
{
    uint64_t u;
    struct cavm_bbxex_config_160_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_160_s cn; */
};
typedef union cavm_bbxex_config_160 cavm_bbxex_config_160_t;

static inline uint64_t CAVM_BBXEX_CONFIG_160(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_160(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02500ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_160", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_160(a) cavm_bbxex_config_160_t
#define bustype_CAVM_BBXEX_CONFIG_160(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_160(a) "BBXEX_CONFIG_160"
#define busnum_CAVM_BBXEX_CONFIG_160(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_160(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_161
 *
 * BBX5 Configuration Register 161
 * Job Configuration
 */
union cavm_bbxex_config_161
{
    uint64_t u;
    struct cavm_bbxex_config_161_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_161_s cn; */
};
typedef union cavm_bbxex_config_161 cavm_bbxex_config_161_t;

static inline uint64_t CAVM_BBXEX_CONFIG_161(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_161(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02508ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_161", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_161(a) cavm_bbxex_config_161_t
#define bustype_CAVM_BBXEX_CONFIG_161(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_161(a) "BBXEX_CONFIG_161"
#define busnum_CAVM_BBXEX_CONFIG_161(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_161(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_162
 *
 * BBX5 Configuration Register 162
 * Job Configuration
 */
union cavm_bbxex_config_162
{
    uint64_t u;
    struct cavm_bbxex_config_162_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_162_s cn; */
};
typedef union cavm_bbxex_config_162 cavm_bbxex_config_162_t;

static inline uint64_t CAVM_BBXEX_CONFIG_162(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_162(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02510ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_162", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_162(a) cavm_bbxex_config_162_t
#define bustype_CAVM_BBXEX_CONFIG_162(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_162(a) "BBXEX_CONFIG_162"
#define busnum_CAVM_BBXEX_CONFIG_162(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_162(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_163
 *
 * BBX5 Configuration Register 163
 * Job Configuration
 */
union cavm_bbxex_config_163
{
    uint64_t u;
    struct cavm_bbxex_config_163_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_163_s cn; */
};
typedef union cavm_bbxex_config_163 cavm_bbxex_config_163_t;

static inline uint64_t CAVM_BBXEX_CONFIG_163(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_163(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02518ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_163", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_163(a) cavm_bbxex_config_163_t
#define bustype_CAVM_BBXEX_CONFIG_163(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_163(a) "BBXEX_CONFIG_163"
#define busnum_CAVM_BBXEX_CONFIG_163(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_163(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_164
 *
 * BBX5 Configuration Register 164
 * Job Configuration
 */
union cavm_bbxex_config_164
{
    uint64_t u;
    struct cavm_bbxex_config_164_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_164_s cn; */
};
typedef union cavm_bbxex_config_164 cavm_bbxex_config_164_t;

static inline uint64_t CAVM_BBXEX_CONFIG_164(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_164(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02520ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_164", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_164(a) cavm_bbxex_config_164_t
#define bustype_CAVM_BBXEX_CONFIG_164(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_164(a) "BBXEX_CONFIG_164"
#define busnum_CAVM_BBXEX_CONFIG_164(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_164(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_165
 *
 * BBX5 Configuration Register 165
 * Job Configuration
 */
union cavm_bbxex_config_165
{
    uint64_t u;
    struct cavm_bbxex_config_165_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_165_s cn; */
};
typedef union cavm_bbxex_config_165 cavm_bbxex_config_165_t;

static inline uint64_t CAVM_BBXEX_CONFIG_165(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_165(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02528ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_165", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_165(a) cavm_bbxex_config_165_t
#define bustype_CAVM_BBXEX_CONFIG_165(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_165(a) "BBXEX_CONFIG_165"
#define busnum_CAVM_BBXEX_CONFIG_165(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_165(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_166
 *
 * BBX5 Configuration Register 166
 * Job Configuration
 */
union cavm_bbxex_config_166
{
    uint64_t u;
    struct cavm_bbxex_config_166_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_166_s cn; */
};
typedef union cavm_bbxex_config_166 cavm_bbxex_config_166_t;

static inline uint64_t CAVM_BBXEX_CONFIG_166(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_166(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02530ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_166", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_166(a) cavm_bbxex_config_166_t
#define bustype_CAVM_BBXEX_CONFIG_166(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_166(a) "BBXEX_CONFIG_166"
#define busnum_CAVM_BBXEX_CONFIG_166(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_166(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_167
 *
 * BBX5 Configuration Register 167
 * Job Configuration
 */
union cavm_bbxex_config_167
{
    uint64_t u;
    struct cavm_bbxex_config_167_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_167_s cn; */
};
typedef union cavm_bbxex_config_167 cavm_bbxex_config_167_t;

static inline uint64_t CAVM_BBXEX_CONFIG_167(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_167(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02538ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_167", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_167(a) cavm_bbxex_config_167_t
#define bustype_CAVM_BBXEX_CONFIG_167(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_167(a) "BBXEX_CONFIG_167"
#define busnum_CAVM_BBXEX_CONFIG_167(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_167(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_168
 *
 * BBX5 Configuration Register 168
 * Job Configuration
 */
union cavm_bbxex_config_168
{
    uint64_t u;
    struct cavm_bbxex_config_168_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_168_s cn; */
};
typedef union cavm_bbxex_config_168 cavm_bbxex_config_168_t;

static inline uint64_t CAVM_BBXEX_CONFIG_168(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_168(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02540ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_168", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_168(a) cavm_bbxex_config_168_t
#define bustype_CAVM_BBXEX_CONFIG_168(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_168(a) "BBXEX_CONFIG_168"
#define busnum_CAVM_BBXEX_CONFIG_168(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_168(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_169
 *
 * BBX5 Configuration Register 169
 * Job Configuration
 */
union cavm_bbxex_config_169
{
    uint64_t u;
    struct cavm_bbxex_config_169_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_169_s cn; */
};
typedef union cavm_bbxex_config_169 cavm_bbxex_config_169_t;

static inline uint64_t CAVM_BBXEX_CONFIG_169(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_169(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02548ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_169", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_169(a) cavm_bbxex_config_169_t
#define bustype_CAVM_BBXEX_CONFIG_169(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_169(a) "BBXEX_CONFIG_169"
#define busnum_CAVM_BBXEX_CONFIG_169(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_169(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_17
 *
 * BBX5 Configuration Register 17
 * Job Configuration
 */
union cavm_bbxex_config_17
{
    uint64_t u;
    struct cavm_bbxex_config_17_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_17_s cn; */
};
typedef union cavm_bbxex_config_17 cavm_bbxex_config_17_t;

static inline uint64_t CAVM_BBXEX_CONFIG_17(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_17(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02088ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_17", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_17(a) cavm_bbxex_config_17_t
#define bustype_CAVM_BBXEX_CONFIG_17(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_17(a) "BBXEX_CONFIG_17"
#define busnum_CAVM_BBXEX_CONFIG_17(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_17(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_170
 *
 * BBX5 Configuration Register 170
 * Job Configuration
 */
union cavm_bbxex_config_170
{
    uint64_t u;
    struct cavm_bbxex_config_170_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_170_s cn; */
};
typedef union cavm_bbxex_config_170 cavm_bbxex_config_170_t;

static inline uint64_t CAVM_BBXEX_CONFIG_170(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_170(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02550ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_170", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_170(a) cavm_bbxex_config_170_t
#define bustype_CAVM_BBXEX_CONFIG_170(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_170(a) "BBXEX_CONFIG_170"
#define busnum_CAVM_BBXEX_CONFIG_170(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_170(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_171
 *
 * BBX5 Configuration Register 171
 * Job Configuration
 */
union cavm_bbxex_config_171
{
    uint64_t u;
    struct cavm_bbxex_config_171_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_171_s cn; */
};
typedef union cavm_bbxex_config_171 cavm_bbxex_config_171_t;

static inline uint64_t CAVM_BBXEX_CONFIG_171(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_171(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02558ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_171", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_171(a) cavm_bbxex_config_171_t
#define bustype_CAVM_BBXEX_CONFIG_171(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_171(a) "BBXEX_CONFIG_171"
#define busnum_CAVM_BBXEX_CONFIG_171(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_171(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_172
 *
 * BBX5 Configuration Register 172
 * Job Configuration
 */
union cavm_bbxex_config_172
{
    uint64_t u;
    struct cavm_bbxex_config_172_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_172_s cn; */
};
typedef union cavm_bbxex_config_172 cavm_bbxex_config_172_t;

static inline uint64_t CAVM_BBXEX_CONFIG_172(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_172(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02560ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_172", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_172(a) cavm_bbxex_config_172_t
#define bustype_CAVM_BBXEX_CONFIG_172(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_172(a) "BBXEX_CONFIG_172"
#define busnum_CAVM_BBXEX_CONFIG_172(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_172(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_173
 *
 * BBX5 Configuration Register 173
 * Job Configuration
 */
union cavm_bbxex_config_173
{
    uint64_t u;
    struct cavm_bbxex_config_173_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_173_s cn; */
};
typedef union cavm_bbxex_config_173 cavm_bbxex_config_173_t;

static inline uint64_t CAVM_BBXEX_CONFIG_173(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_173(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02568ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_173", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_173(a) cavm_bbxex_config_173_t
#define bustype_CAVM_BBXEX_CONFIG_173(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_173(a) "BBXEX_CONFIG_173"
#define busnum_CAVM_BBXEX_CONFIG_173(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_173(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_174
 *
 * BBX5 Configuration Register 174
 * Job Configuration
 */
union cavm_bbxex_config_174
{
    uint64_t u;
    struct cavm_bbxex_config_174_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_174_s cn; */
};
typedef union cavm_bbxex_config_174 cavm_bbxex_config_174_t;

static inline uint64_t CAVM_BBXEX_CONFIG_174(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_174(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02570ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_174", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_174(a) cavm_bbxex_config_174_t
#define bustype_CAVM_BBXEX_CONFIG_174(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_174(a) "BBXEX_CONFIG_174"
#define busnum_CAVM_BBXEX_CONFIG_174(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_174(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_175
 *
 * BBX5 Configuration Register 175
 * Job Configuration
 */
union cavm_bbxex_config_175
{
    uint64_t u;
    struct cavm_bbxex_config_175_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_175_s cn; */
};
typedef union cavm_bbxex_config_175 cavm_bbxex_config_175_t;

static inline uint64_t CAVM_BBXEX_CONFIG_175(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_175(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02578ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_175", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_175(a) cavm_bbxex_config_175_t
#define bustype_CAVM_BBXEX_CONFIG_175(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_175(a) "BBXEX_CONFIG_175"
#define busnum_CAVM_BBXEX_CONFIG_175(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_175(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_176
 *
 * BBX5 Configuration Register 176
 * Job Configuration
 */
union cavm_bbxex_config_176
{
    uint64_t u;
    struct cavm_bbxex_config_176_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_176_s cn; */
};
typedef union cavm_bbxex_config_176 cavm_bbxex_config_176_t;

static inline uint64_t CAVM_BBXEX_CONFIG_176(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_176(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02580ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_176", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_176(a) cavm_bbxex_config_176_t
#define bustype_CAVM_BBXEX_CONFIG_176(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_176(a) "BBXEX_CONFIG_176"
#define busnum_CAVM_BBXEX_CONFIG_176(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_176(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_177
 *
 * BBX5 Configuration Register 177
 * Job Configuration
 */
union cavm_bbxex_config_177
{
    uint64_t u;
    struct cavm_bbxex_config_177_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_177_s cn; */
};
typedef union cavm_bbxex_config_177 cavm_bbxex_config_177_t;

static inline uint64_t CAVM_BBXEX_CONFIG_177(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_177(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02588ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_177", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_177(a) cavm_bbxex_config_177_t
#define bustype_CAVM_BBXEX_CONFIG_177(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_177(a) "BBXEX_CONFIG_177"
#define busnum_CAVM_BBXEX_CONFIG_177(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_177(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_178
 *
 * BBX5 Configuration Register 178
 * Job Configuration
 */
union cavm_bbxex_config_178
{
    uint64_t u;
    struct cavm_bbxex_config_178_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_178_s cn; */
};
typedef union cavm_bbxex_config_178 cavm_bbxex_config_178_t;

static inline uint64_t CAVM_BBXEX_CONFIG_178(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_178(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02590ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_178", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_178(a) cavm_bbxex_config_178_t
#define bustype_CAVM_BBXEX_CONFIG_178(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_178(a) "BBXEX_CONFIG_178"
#define busnum_CAVM_BBXEX_CONFIG_178(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_178(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_179
 *
 * BBX5 Configuration Register 179
 * Job Configuration
 */
union cavm_bbxex_config_179
{
    uint64_t u;
    struct cavm_bbxex_config_179_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_179_s cn; */
};
typedef union cavm_bbxex_config_179 cavm_bbxex_config_179_t;

static inline uint64_t CAVM_BBXEX_CONFIG_179(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_179(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02598ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_179", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_179(a) cavm_bbxex_config_179_t
#define bustype_CAVM_BBXEX_CONFIG_179(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_179(a) "BBXEX_CONFIG_179"
#define busnum_CAVM_BBXEX_CONFIG_179(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_179(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_18
 *
 * BBX5 Configuration Register 18
 * Job Configuration
 */
union cavm_bbxex_config_18
{
    uint64_t u;
    struct cavm_bbxex_config_18_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t config_f_1            : 2;  /**< [ 33: 32](R/W) -- */
        uint64_t reserved_31           : 1;
        uint64_t config_f_0            : 31; /**< [ 30:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 31; /**< [ 30:  0](R/W) -- */
        uint64_t reserved_31           : 1;
        uint64_t config_f_1            : 2;  /**< [ 33: 32](R/W) -- */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_18_s cn; */
};
typedef union cavm_bbxex_config_18 cavm_bbxex_config_18_t;

static inline uint64_t CAVM_BBXEX_CONFIG_18(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_18(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02090ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_18", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_18(a) cavm_bbxex_config_18_t
#define bustype_CAVM_BBXEX_CONFIG_18(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_18(a) "BBXEX_CONFIG_18"
#define busnum_CAVM_BBXEX_CONFIG_18(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_18(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_180
 *
 * BBX5 Configuration Register 180
 * Job Configuration
 */
union cavm_bbxex_config_180
{
    uint64_t u;
    struct cavm_bbxex_config_180_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_180_s cn; */
};
typedef union cavm_bbxex_config_180 cavm_bbxex_config_180_t;

static inline uint64_t CAVM_BBXEX_CONFIG_180(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_180(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_180", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_180(a) cavm_bbxex_config_180_t
#define bustype_CAVM_BBXEX_CONFIG_180(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_180(a) "BBXEX_CONFIG_180"
#define busnum_CAVM_BBXEX_CONFIG_180(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_180(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_181
 *
 * BBX5 Configuration Register 181
 * Job Configuration
 */
union cavm_bbxex_config_181
{
    uint64_t u;
    struct cavm_bbxex_config_181_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_181_s cn; */
};
typedef union cavm_bbxex_config_181 cavm_bbxex_config_181_t;

static inline uint64_t CAVM_BBXEX_CONFIG_181(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_181(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_181", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_181(a) cavm_bbxex_config_181_t
#define bustype_CAVM_BBXEX_CONFIG_181(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_181(a) "BBXEX_CONFIG_181"
#define busnum_CAVM_BBXEX_CONFIG_181(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_181(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_182
 *
 * BBX5 Configuration Register 182
 * Job Configuration
 */
union cavm_bbxex_config_182
{
    uint64_t u;
    struct cavm_bbxex_config_182_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_182_s cn; */
};
typedef union cavm_bbxex_config_182 cavm_bbxex_config_182_t;

static inline uint64_t CAVM_BBXEX_CONFIG_182(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_182(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_182", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_182(a) cavm_bbxex_config_182_t
#define bustype_CAVM_BBXEX_CONFIG_182(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_182(a) "BBXEX_CONFIG_182"
#define busnum_CAVM_BBXEX_CONFIG_182(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_182(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_183
 *
 * BBX5 Configuration Register 183
 * Job Configuration
 */
union cavm_bbxex_config_183
{
    uint64_t u;
    struct cavm_bbxex_config_183_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_183_s cn; */
};
typedef union cavm_bbxex_config_183 cavm_bbxex_config_183_t;

static inline uint64_t CAVM_BBXEX_CONFIG_183(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_183(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_183", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_183(a) cavm_bbxex_config_183_t
#define bustype_CAVM_BBXEX_CONFIG_183(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_183(a) "BBXEX_CONFIG_183"
#define busnum_CAVM_BBXEX_CONFIG_183(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_183(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_184
 *
 * BBX5 Configuration Register 184
 * Job Configuration
 */
union cavm_bbxex_config_184
{
    uint64_t u;
    struct cavm_bbxex_config_184_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_184_s cn; */
};
typedef union cavm_bbxex_config_184 cavm_bbxex_config_184_t;

static inline uint64_t CAVM_BBXEX_CONFIG_184(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_184(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_184", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_184(a) cavm_bbxex_config_184_t
#define bustype_CAVM_BBXEX_CONFIG_184(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_184(a) "BBXEX_CONFIG_184"
#define busnum_CAVM_BBXEX_CONFIG_184(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_184(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_185
 *
 * BBX5 Configuration Register 185
 * Job Configuration
 */
union cavm_bbxex_config_185
{
    uint64_t u;
    struct cavm_bbxex_config_185_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_185_s cn; */
};
typedef union cavm_bbxex_config_185 cavm_bbxex_config_185_t;

static inline uint64_t CAVM_BBXEX_CONFIG_185(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_185(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_185", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_185(a) cavm_bbxex_config_185_t
#define bustype_CAVM_BBXEX_CONFIG_185(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_185(a) "BBXEX_CONFIG_185"
#define busnum_CAVM_BBXEX_CONFIG_185(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_185(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_186
 *
 * BBX5 Configuration Register 186
 * Job Configuration
 */
union cavm_bbxex_config_186
{
    uint64_t u;
    struct cavm_bbxex_config_186_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_186_s cn; */
};
typedef union cavm_bbxex_config_186 cavm_bbxex_config_186_t;

static inline uint64_t CAVM_BBXEX_CONFIG_186(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_186(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_186", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_186(a) cavm_bbxex_config_186_t
#define bustype_CAVM_BBXEX_CONFIG_186(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_186(a) "BBXEX_CONFIG_186"
#define busnum_CAVM_BBXEX_CONFIG_186(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_186(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_187
 *
 * BBX5 Configuration Register 187
 * Job Configuration
 */
union cavm_bbxex_config_187
{
    uint64_t u;
    struct cavm_bbxex_config_187_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_187_s cn; */
};
typedef union cavm_bbxex_config_187 cavm_bbxex_config_187_t;

static inline uint64_t CAVM_BBXEX_CONFIG_187(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_187(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_187", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_187(a) cavm_bbxex_config_187_t
#define bustype_CAVM_BBXEX_CONFIG_187(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_187(a) "BBXEX_CONFIG_187"
#define busnum_CAVM_BBXEX_CONFIG_187(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_187(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_188
 *
 * BBX5 Configuration Register 188
 * Job Configuration
 */
union cavm_bbxex_config_188
{
    uint64_t u;
    struct cavm_bbxex_config_188_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_188_s cn; */
};
typedef union cavm_bbxex_config_188 cavm_bbxex_config_188_t;

static inline uint64_t CAVM_BBXEX_CONFIG_188(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_188(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_188", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_188(a) cavm_bbxex_config_188_t
#define bustype_CAVM_BBXEX_CONFIG_188(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_188(a) "BBXEX_CONFIG_188"
#define busnum_CAVM_BBXEX_CONFIG_188(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_188(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_189
 *
 * BBX5 Configuration Register 189
 * Job Configuration
 */
union cavm_bbxex_config_189
{
    uint64_t u;
    struct cavm_bbxex_config_189_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_189_s cn; */
};
typedef union cavm_bbxex_config_189 cavm_bbxex_config_189_t;

static inline uint64_t CAVM_BBXEX_CONFIG_189(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_189(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_189", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_189(a) cavm_bbxex_config_189_t
#define bustype_CAVM_BBXEX_CONFIG_189(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_189(a) "BBXEX_CONFIG_189"
#define busnum_CAVM_BBXEX_CONFIG_189(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_189(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_19
 *
 * BBX5 Configuration Register 19
 * Job Configuration
 */
union cavm_bbxex_config_19
{
    uint64_t u;
    struct cavm_bbxex_config_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_19_s cn; */
};
typedef union cavm_bbxex_config_19 cavm_bbxex_config_19_t;

static inline uint64_t CAVM_BBXEX_CONFIG_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02098ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_19", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_19(a) cavm_bbxex_config_19_t
#define bustype_CAVM_BBXEX_CONFIG_19(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_19(a) "BBXEX_CONFIG_19"
#define busnum_CAVM_BBXEX_CONFIG_19(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_19(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_190
 *
 * BBX5 Configuration Register 190
 * Job Configuration
 */
union cavm_bbxex_config_190
{
    uint64_t u;
    struct cavm_bbxex_config_190_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_190_s cn; */
};
typedef union cavm_bbxex_config_190 cavm_bbxex_config_190_t;

static inline uint64_t CAVM_BBXEX_CONFIG_190(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_190(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_190", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_190(a) cavm_bbxex_config_190_t
#define bustype_CAVM_BBXEX_CONFIG_190(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_190(a) "BBXEX_CONFIG_190"
#define busnum_CAVM_BBXEX_CONFIG_190(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_190(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_191
 *
 * BBX5 Configuration Register 191
 * Job Configuration
 */
union cavm_bbxex_config_191
{
    uint64_t u;
    struct cavm_bbxex_config_191_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_191_s cn; */
};
typedef union cavm_bbxex_config_191 cavm_bbxex_config_191_t;

static inline uint64_t CAVM_BBXEX_CONFIG_191(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_191(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c025f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_191", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_191(a) cavm_bbxex_config_191_t
#define bustype_CAVM_BBXEX_CONFIG_191(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_191(a) "BBXEX_CONFIG_191"
#define busnum_CAVM_BBXEX_CONFIG_191(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_191(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_192
 *
 * BBX5 Configuration Register 192
 * Job Configuration
 */
union cavm_bbxex_config_192
{
    uint64_t u;
    struct cavm_bbxex_config_192_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_192_s cn; */
};
typedef union cavm_bbxex_config_192 cavm_bbxex_config_192_t;

static inline uint64_t CAVM_BBXEX_CONFIG_192(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_192(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02600ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_192", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_192(a) cavm_bbxex_config_192_t
#define bustype_CAVM_BBXEX_CONFIG_192(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_192(a) "BBXEX_CONFIG_192"
#define busnum_CAVM_BBXEX_CONFIG_192(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_192(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_193
 *
 * BBX5 Configuration Register 193
 * Job Configuration
 */
union cavm_bbxex_config_193
{
    uint64_t u;
    struct cavm_bbxex_config_193_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_193_s cn; */
};
typedef union cavm_bbxex_config_193 cavm_bbxex_config_193_t;

static inline uint64_t CAVM_BBXEX_CONFIG_193(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_193(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02608ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_193", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_193(a) cavm_bbxex_config_193_t
#define bustype_CAVM_BBXEX_CONFIG_193(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_193(a) "BBXEX_CONFIG_193"
#define busnum_CAVM_BBXEX_CONFIG_193(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_193(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_194
 *
 * BBX5 Configuration Register 194
 * Job Configuration
 */
union cavm_bbxex_config_194
{
    uint64_t u;
    struct cavm_bbxex_config_194_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_194_s cn; */
};
typedef union cavm_bbxex_config_194 cavm_bbxex_config_194_t;

static inline uint64_t CAVM_BBXEX_CONFIG_194(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_194(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02610ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_194", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_194(a) cavm_bbxex_config_194_t
#define bustype_CAVM_BBXEX_CONFIG_194(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_194(a) "BBXEX_CONFIG_194"
#define busnum_CAVM_BBXEX_CONFIG_194(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_194(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_195
 *
 * BBX5 Configuration Register 195
 * Job Configuration
 */
union cavm_bbxex_config_195
{
    uint64_t u;
    struct cavm_bbxex_config_195_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_195_s cn; */
};
typedef union cavm_bbxex_config_195 cavm_bbxex_config_195_t;

static inline uint64_t CAVM_BBXEX_CONFIG_195(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_195(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02618ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_195", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_195(a) cavm_bbxex_config_195_t
#define bustype_CAVM_BBXEX_CONFIG_195(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_195(a) "BBXEX_CONFIG_195"
#define busnum_CAVM_BBXEX_CONFIG_195(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_195(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_196
 *
 * BBX5 Configuration Register 196
 * Job Configuration
 */
union cavm_bbxex_config_196
{
    uint64_t u;
    struct cavm_bbxex_config_196_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_196_s cn; */
};
typedef union cavm_bbxex_config_196 cavm_bbxex_config_196_t;

static inline uint64_t CAVM_BBXEX_CONFIG_196(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_196(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02620ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_196", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_196(a) cavm_bbxex_config_196_t
#define bustype_CAVM_BBXEX_CONFIG_196(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_196(a) "BBXEX_CONFIG_196"
#define busnum_CAVM_BBXEX_CONFIG_196(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_196(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_197
 *
 * BBX5 Configuration Register 197
 * Job Configuration
 */
union cavm_bbxex_config_197
{
    uint64_t u;
    struct cavm_bbxex_config_197_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_197_s cn; */
};
typedef union cavm_bbxex_config_197 cavm_bbxex_config_197_t;

static inline uint64_t CAVM_BBXEX_CONFIG_197(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_197(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02628ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_197", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_197(a) cavm_bbxex_config_197_t
#define bustype_CAVM_BBXEX_CONFIG_197(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_197(a) "BBXEX_CONFIG_197"
#define busnum_CAVM_BBXEX_CONFIG_197(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_197(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_198
 *
 * BBX5 Configuration Register 198
 * Job Configuration
 */
union cavm_bbxex_config_198
{
    uint64_t u;
    struct cavm_bbxex_config_198_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_198_s cn; */
};
typedef union cavm_bbxex_config_198 cavm_bbxex_config_198_t;

static inline uint64_t CAVM_BBXEX_CONFIG_198(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_198(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02630ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_198", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_198(a) cavm_bbxex_config_198_t
#define bustype_CAVM_BBXEX_CONFIG_198(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_198(a) "BBXEX_CONFIG_198"
#define busnum_CAVM_BBXEX_CONFIG_198(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_198(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_199
 *
 * BBX5 Configuration Register 199
 * Job Configuration
 */
union cavm_bbxex_config_199
{
    uint64_t u;
    struct cavm_bbxex_config_199_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_199_s cn; */
};
typedef union cavm_bbxex_config_199 cavm_bbxex_config_199_t;

static inline uint64_t CAVM_BBXEX_CONFIG_199(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_199(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02638ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_199", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_199(a) cavm_bbxex_config_199_t
#define bustype_CAVM_BBXEX_CONFIG_199(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_199(a) "BBXEX_CONFIG_199"
#define busnum_CAVM_BBXEX_CONFIG_199(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_199(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_2
 *
 * BBX5 Configuration Register 2
 * Job Configuration
 */
union cavm_bbxex_config_2
{
    uint64_t u;
    struct cavm_bbxex_config_2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_2_s cn; */
};
typedef union cavm_bbxex_config_2 cavm_bbxex_config_2_t;

static inline uint64_t CAVM_BBXEX_CONFIG_2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02010ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_2", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_2(a) cavm_bbxex_config_2_t
#define bustype_CAVM_BBXEX_CONFIG_2(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_2(a) "BBXEX_CONFIG_2"
#define busnum_CAVM_BBXEX_CONFIG_2(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_2(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_20
 *
 * BBX5 Configuration Register 20
 * Job Configuration
 */
union cavm_bbxex_config_20
{
    uint64_t u;
    struct cavm_bbxex_config_20_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_20_s cn; */
};
typedef union cavm_bbxex_config_20 cavm_bbxex_config_20_t;

static inline uint64_t CAVM_BBXEX_CONFIG_20(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_20(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_20", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_20(a) cavm_bbxex_config_20_t
#define bustype_CAVM_BBXEX_CONFIG_20(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_20(a) "BBXEX_CONFIG_20"
#define busnum_CAVM_BBXEX_CONFIG_20(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_20(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_200
 *
 * BBX5 Configuration Register 200
 * Job Configuration
 */
union cavm_bbxex_config_200
{
    uint64_t u;
    struct cavm_bbxex_config_200_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_200_s cn; */
};
typedef union cavm_bbxex_config_200 cavm_bbxex_config_200_t;

static inline uint64_t CAVM_BBXEX_CONFIG_200(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_200(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02640ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_200", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_200(a) cavm_bbxex_config_200_t
#define bustype_CAVM_BBXEX_CONFIG_200(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_200(a) "BBXEX_CONFIG_200"
#define busnum_CAVM_BBXEX_CONFIG_200(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_200(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_201
 *
 * BBX5 Configuration Register 201
 * Job Configuration
 */
union cavm_bbxex_config_201
{
    uint64_t u;
    struct cavm_bbxex_config_201_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_201_s cn; */
};
typedef union cavm_bbxex_config_201 cavm_bbxex_config_201_t;

static inline uint64_t CAVM_BBXEX_CONFIG_201(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_201(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02648ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_201", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_201(a) cavm_bbxex_config_201_t
#define bustype_CAVM_BBXEX_CONFIG_201(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_201(a) "BBXEX_CONFIG_201"
#define busnum_CAVM_BBXEX_CONFIG_201(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_201(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_202
 *
 * BBX5 Configuration Register 202
 * Job Configuration
 */
union cavm_bbxex_config_202
{
    uint64_t u;
    struct cavm_bbxex_config_202_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_202_s cn; */
};
typedef union cavm_bbxex_config_202 cavm_bbxex_config_202_t;

static inline uint64_t CAVM_BBXEX_CONFIG_202(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_202(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02650ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_202", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_202(a) cavm_bbxex_config_202_t
#define bustype_CAVM_BBXEX_CONFIG_202(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_202(a) "BBXEX_CONFIG_202"
#define busnum_CAVM_BBXEX_CONFIG_202(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_202(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_203
 *
 * BBX5 Configuration Register 203
 * Job Configuration
 */
union cavm_bbxex_config_203
{
    uint64_t u;
    struct cavm_bbxex_config_203_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_203_s cn; */
};
typedef union cavm_bbxex_config_203 cavm_bbxex_config_203_t;

static inline uint64_t CAVM_BBXEX_CONFIG_203(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_203(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02658ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_203", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_203(a) cavm_bbxex_config_203_t
#define bustype_CAVM_BBXEX_CONFIG_203(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_203(a) "BBXEX_CONFIG_203"
#define busnum_CAVM_BBXEX_CONFIG_203(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_203(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_204
 *
 * BBX5 Configuration Register 204
 * Job Configuration
 */
union cavm_bbxex_config_204
{
    uint64_t u;
    struct cavm_bbxex_config_204_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_204_s cn; */
};
typedef union cavm_bbxex_config_204 cavm_bbxex_config_204_t;

static inline uint64_t CAVM_BBXEX_CONFIG_204(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_204(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02660ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_204", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_204(a) cavm_bbxex_config_204_t
#define bustype_CAVM_BBXEX_CONFIG_204(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_204(a) "BBXEX_CONFIG_204"
#define busnum_CAVM_BBXEX_CONFIG_204(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_204(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_205
 *
 * BBX5 Configuration Register 205
 * Job Configuration
 */
union cavm_bbxex_config_205
{
    uint64_t u;
    struct cavm_bbxex_config_205_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_205_s cn; */
};
typedef union cavm_bbxex_config_205 cavm_bbxex_config_205_t;

static inline uint64_t CAVM_BBXEX_CONFIG_205(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_205(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02668ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_205", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_205(a) cavm_bbxex_config_205_t
#define bustype_CAVM_BBXEX_CONFIG_205(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_205(a) "BBXEX_CONFIG_205"
#define busnum_CAVM_BBXEX_CONFIG_205(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_205(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_206
 *
 * BBX5 Configuration Register 206
 * Job Configuration
 */
union cavm_bbxex_config_206
{
    uint64_t u;
    struct cavm_bbxex_config_206_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_206_s cn; */
};
typedef union cavm_bbxex_config_206 cavm_bbxex_config_206_t;

static inline uint64_t CAVM_BBXEX_CONFIG_206(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_206(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02670ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_206", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_206(a) cavm_bbxex_config_206_t
#define bustype_CAVM_BBXEX_CONFIG_206(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_206(a) "BBXEX_CONFIG_206"
#define busnum_CAVM_BBXEX_CONFIG_206(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_206(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_207
 *
 * BBX5 Configuration Register 207
 * Job Configuration
 */
union cavm_bbxex_config_207
{
    uint64_t u;
    struct cavm_bbxex_config_207_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_207_s cn; */
};
typedef union cavm_bbxex_config_207 cavm_bbxex_config_207_t;

static inline uint64_t CAVM_BBXEX_CONFIG_207(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_207(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02678ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_207", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_207(a) cavm_bbxex_config_207_t
#define bustype_CAVM_BBXEX_CONFIG_207(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_207(a) "BBXEX_CONFIG_207"
#define busnum_CAVM_BBXEX_CONFIG_207(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_207(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_208
 *
 * BBX5 Configuration Register 208
 * Job Configuration
 */
union cavm_bbxex_config_208
{
    uint64_t u;
    struct cavm_bbxex_config_208_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_208_s cn; */
};
typedef union cavm_bbxex_config_208 cavm_bbxex_config_208_t;

static inline uint64_t CAVM_BBXEX_CONFIG_208(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_208(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02680ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_208", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_208(a) cavm_bbxex_config_208_t
#define bustype_CAVM_BBXEX_CONFIG_208(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_208(a) "BBXEX_CONFIG_208"
#define busnum_CAVM_BBXEX_CONFIG_208(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_208(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_209
 *
 * BBX5 Configuration Register 209
 * Job Configuration
 */
union cavm_bbxex_config_209
{
    uint64_t u;
    struct cavm_bbxex_config_209_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_209_s cn; */
};
typedef union cavm_bbxex_config_209 cavm_bbxex_config_209_t;

static inline uint64_t CAVM_BBXEX_CONFIG_209(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_209(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02688ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_209", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_209(a) cavm_bbxex_config_209_t
#define bustype_CAVM_BBXEX_CONFIG_209(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_209(a) "BBXEX_CONFIG_209"
#define busnum_CAVM_BBXEX_CONFIG_209(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_209(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_21
 *
 * BBX5 Configuration Register 21
 * Job Configuration
 */
union cavm_bbxex_config_21
{
    uint64_t u;
    struct cavm_bbxex_config_21_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_21_s cn; */
};
typedef union cavm_bbxex_config_21 cavm_bbxex_config_21_t;

static inline uint64_t CAVM_BBXEX_CONFIG_21(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_21(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_21", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_21(a) cavm_bbxex_config_21_t
#define bustype_CAVM_BBXEX_CONFIG_21(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_21(a) "BBXEX_CONFIG_21"
#define busnum_CAVM_BBXEX_CONFIG_21(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_21(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_210
 *
 * BBX5 Configuration Register 210
 * Job Configuration
 */
union cavm_bbxex_config_210
{
    uint64_t u;
    struct cavm_bbxex_config_210_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_210_s cn; */
};
typedef union cavm_bbxex_config_210 cavm_bbxex_config_210_t;

static inline uint64_t CAVM_BBXEX_CONFIG_210(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_210(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02690ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_210", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_210(a) cavm_bbxex_config_210_t
#define bustype_CAVM_BBXEX_CONFIG_210(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_210(a) "BBXEX_CONFIG_210"
#define busnum_CAVM_BBXEX_CONFIG_210(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_210(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_211
 *
 * BBX5 Configuration Register 211
 * Job Configuration
 */
union cavm_bbxex_config_211
{
    uint64_t u;
    struct cavm_bbxex_config_211_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_211_s cn; */
};
typedef union cavm_bbxex_config_211 cavm_bbxex_config_211_t;

static inline uint64_t CAVM_BBXEX_CONFIG_211(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_211(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02698ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_211", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_211(a) cavm_bbxex_config_211_t
#define bustype_CAVM_BBXEX_CONFIG_211(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_211(a) "BBXEX_CONFIG_211"
#define busnum_CAVM_BBXEX_CONFIG_211(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_211(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_212
 *
 * BBX5 Configuration Register 212
 * Job Configuration
 */
union cavm_bbxex_config_212
{
    uint64_t u;
    struct cavm_bbxex_config_212_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_212_s cn; */
};
typedef union cavm_bbxex_config_212 cavm_bbxex_config_212_t;

static inline uint64_t CAVM_BBXEX_CONFIG_212(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_212(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_212", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_212(a) cavm_bbxex_config_212_t
#define bustype_CAVM_BBXEX_CONFIG_212(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_212(a) "BBXEX_CONFIG_212"
#define busnum_CAVM_BBXEX_CONFIG_212(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_212(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_213
 *
 * BBX5 Configuration Register 213
 * Job Configuration
 */
union cavm_bbxex_config_213
{
    uint64_t u;
    struct cavm_bbxex_config_213_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_213_s cn; */
};
typedef union cavm_bbxex_config_213 cavm_bbxex_config_213_t;

static inline uint64_t CAVM_BBXEX_CONFIG_213(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_213(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_213", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_213(a) cavm_bbxex_config_213_t
#define bustype_CAVM_BBXEX_CONFIG_213(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_213(a) "BBXEX_CONFIG_213"
#define busnum_CAVM_BBXEX_CONFIG_213(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_213(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_214
 *
 * BBX5 Configuration Register 214
 * Job Configuration
 */
union cavm_bbxex_config_214
{
    uint64_t u;
    struct cavm_bbxex_config_214_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_214_s cn; */
};
typedef union cavm_bbxex_config_214 cavm_bbxex_config_214_t;

static inline uint64_t CAVM_BBXEX_CONFIG_214(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_214(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_214", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_214(a) cavm_bbxex_config_214_t
#define bustype_CAVM_BBXEX_CONFIG_214(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_214(a) "BBXEX_CONFIG_214"
#define busnum_CAVM_BBXEX_CONFIG_214(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_214(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_215
 *
 * BBX5 Configuration Register 215
 * Job Configuration
 */
union cavm_bbxex_config_215
{
    uint64_t u;
    struct cavm_bbxex_config_215_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_215_s cn; */
};
typedef union cavm_bbxex_config_215 cavm_bbxex_config_215_t;

static inline uint64_t CAVM_BBXEX_CONFIG_215(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_215(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_215", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_215(a) cavm_bbxex_config_215_t
#define bustype_CAVM_BBXEX_CONFIG_215(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_215(a) "BBXEX_CONFIG_215"
#define busnum_CAVM_BBXEX_CONFIG_215(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_215(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_216
 *
 * BBX5 Configuration Register 216
 * Job Configuration
 */
union cavm_bbxex_config_216
{
    uint64_t u;
    struct cavm_bbxex_config_216_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_216_s cn; */
};
typedef union cavm_bbxex_config_216 cavm_bbxex_config_216_t;

static inline uint64_t CAVM_BBXEX_CONFIG_216(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_216(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_216", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_216(a) cavm_bbxex_config_216_t
#define bustype_CAVM_BBXEX_CONFIG_216(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_216(a) "BBXEX_CONFIG_216"
#define busnum_CAVM_BBXEX_CONFIG_216(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_216(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_217
 *
 * BBX5 Configuration Register 217
 * Job Configuration
 */
union cavm_bbxex_config_217
{
    uint64_t u;
    struct cavm_bbxex_config_217_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_217_s cn; */
};
typedef union cavm_bbxex_config_217 cavm_bbxex_config_217_t;

static inline uint64_t CAVM_BBXEX_CONFIG_217(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_217(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_217", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_217(a) cavm_bbxex_config_217_t
#define bustype_CAVM_BBXEX_CONFIG_217(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_217(a) "BBXEX_CONFIG_217"
#define busnum_CAVM_BBXEX_CONFIG_217(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_217(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_218
 *
 * BBX5 Configuration Register 218
 * Job Configuration
 */
union cavm_bbxex_config_218
{
    uint64_t u;
    struct cavm_bbxex_config_218_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_218_s cn; */
};
typedef union cavm_bbxex_config_218 cavm_bbxex_config_218_t;

static inline uint64_t CAVM_BBXEX_CONFIG_218(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_218(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_218", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_218(a) cavm_bbxex_config_218_t
#define bustype_CAVM_BBXEX_CONFIG_218(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_218(a) "BBXEX_CONFIG_218"
#define busnum_CAVM_BBXEX_CONFIG_218(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_218(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_219
 *
 * BBX5 Configuration Register 219
 * Job Configuration
 */
union cavm_bbxex_config_219
{
    uint64_t u;
    struct cavm_bbxex_config_219_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_219_s cn; */
};
typedef union cavm_bbxex_config_219 cavm_bbxex_config_219_t;

static inline uint64_t CAVM_BBXEX_CONFIG_219(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_219(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_219", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_219(a) cavm_bbxex_config_219_t
#define bustype_CAVM_BBXEX_CONFIG_219(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_219(a) "BBXEX_CONFIG_219"
#define busnum_CAVM_BBXEX_CONFIG_219(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_219(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_22
 *
 * BBX5 Configuration Register 22
 * Job Configuration
 */
union cavm_bbxex_config_22
{
    uint64_t u;
    struct cavm_bbxex_config_22_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_22_s cn; */
};
typedef union cavm_bbxex_config_22 cavm_bbxex_config_22_t;

static inline uint64_t CAVM_BBXEX_CONFIG_22(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_22(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_22", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_22(a) cavm_bbxex_config_22_t
#define bustype_CAVM_BBXEX_CONFIG_22(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_22(a) "BBXEX_CONFIG_22"
#define busnum_CAVM_BBXEX_CONFIG_22(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_22(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_220
 *
 * BBX5 Configuration Register 220
 * Job Configuration
 */
union cavm_bbxex_config_220
{
    uint64_t u;
    struct cavm_bbxex_config_220_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_220_s cn; */
};
typedef union cavm_bbxex_config_220 cavm_bbxex_config_220_t;

static inline uint64_t CAVM_BBXEX_CONFIG_220(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_220(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_220", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_220(a) cavm_bbxex_config_220_t
#define bustype_CAVM_BBXEX_CONFIG_220(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_220(a) "BBXEX_CONFIG_220"
#define busnum_CAVM_BBXEX_CONFIG_220(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_220(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_221
 *
 * BBX5 Configuration Register 221
 * Job Configuration
 */
union cavm_bbxex_config_221
{
    uint64_t u;
    struct cavm_bbxex_config_221_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_221_s cn; */
};
typedef union cavm_bbxex_config_221 cavm_bbxex_config_221_t;

static inline uint64_t CAVM_BBXEX_CONFIG_221(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_221(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_221", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_221(a) cavm_bbxex_config_221_t
#define bustype_CAVM_BBXEX_CONFIG_221(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_221(a) "BBXEX_CONFIG_221"
#define busnum_CAVM_BBXEX_CONFIG_221(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_221(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_222
 *
 * BBX5 Configuration Register 222
 * Job Configuration
 */
union cavm_bbxex_config_222
{
    uint64_t u;
    struct cavm_bbxex_config_222_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_222_s cn; */
};
typedef union cavm_bbxex_config_222 cavm_bbxex_config_222_t;

static inline uint64_t CAVM_BBXEX_CONFIG_222(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_222(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_222", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_222(a) cavm_bbxex_config_222_t
#define bustype_CAVM_BBXEX_CONFIG_222(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_222(a) "BBXEX_CONFIG_222"
#define busnum_CAVM_BBXEX_CONFIG_222(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_222(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_223
 *
 * BBX5 Configuration Register 223
 * Job Configuration
 */
union cavm_bbxex_config_223
{
    uint64_t u;
    struct cavm_bbxex_config_223_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_223_s cn; */
};
typedef union cavm_bbxex_config_223 cavm_bbxex_config_223_t;

static inline uint64_t CAVM_BBXEX_CONFIG_223(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_223(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c026f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_223", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_223(a) cavm_bbxex_config_223_t
#define bustype_CAVM_BBXEX_CONFIG_223(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_223(a) "BBXEX_CONFIG_223"
#define busnum_CAVM_BBXEX_CONFIG_223(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_223(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_224
 *
 * BBX5 Configuration Register 224
 * Job Configuration
 */
union cavm_bbxex_config_224
{
    uint64_t u;
    struct cavm_bbxex_config_224_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_224_s cn; */
};
typedef union cavm_bbxex_config_224 cavm_bbxex_config_224_t;

static inline uint64_t CAVM_BBXEX_CONFIG_224(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_224(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02700ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_224", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_224(a) cavm_bbxex_config_224_t
#define bustype_CAVM_BBXEX_CONFIG_224(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_224(a) "BBXEX_CONFIG_224"
#define busnum_CAVM_BBXEX_CONFIG_224(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_224(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_225
 *
 * BBX5 Configuration Register 225
 * Job Configuration
 */
union cavm_bbxex_config_225
{
    uint64_t u;
    struct cavm_bbxex_config_225_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_225_s cn; */
};
typedef union cavm_bbxex_config_225 cavm_bbxex_config_225_t;

static inline uint64_t CAVM_BBXEX_CONFIG_225(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_225(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02708ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_225", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_225(a) cavm_bbxex_config_225_t
#define bustype_CAVM_BBXEX_CONFIG_225(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_225(a) "BBXEX_CONFIG_225"
#define busnum_CAVM_BBXEX_CONFIG_225(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_225(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_226
 *
 * BBX5 Configuration Register 226
 * Job Configuration
 */
union cavm_bbxex_config_226
{
    uint64_t u;
    struct cavm_bbxex_config_226_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_226_s cn; */
};
typedef union cavm_bbxex_config_226 cavm_bbxex_config_226_t;

static inline uint64_t CAVM_BBXEX_CONFIG_226(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_226(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02710ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_226", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_226(a) cavm_bbxex_config_226_t
#define bustype_CAVM_BBXEX_CONFIG_226(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_226(a) "BBXEX_CONFIG_226"
#define busnum_CAVM_BBXEX_CONFIG_226(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_226(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_227
 *
 * BBX5 Configuration Register 227
 * Job Configuration
 */
union cavm_bbxex_config_227
{
    uint64_t u;
    struct cavm_bbxex_config_227_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_227_s cn; */
};
typedef union cavm_bbxex_config_227 cavm_bbxex_config_227_t;

static inline uint64_t CAVM_BBXEX_CONFIG_227(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_227(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02718ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_227", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_227(a) cavm_bbxex_config_227_t
#define bustype_CAVM_BBXEX_CONFIG_227(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_227(a) "BBXEX_CONFIG_227"
#define busnum_CAVM_BBXEX_CONFIG_227(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_227(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_228
 *
 * BBX5 Configuration Register 228
 * Job Configuration
 */
union cavm_bbxex_config_228
{
    uint64_t u;
    struct cavm_bbxex_config_228_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_228_s cn; */
};
typedef union cavm_bbxex_config_228 cavm_bbxex_config_228_t;

static inline uint64_t CAVM_BBXEX_CONFIG_228(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_228(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02720ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_228", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_228(a) cavm_bbxex_config_228_t
#define bustype_CAVM_BBXEX_CONFIG_228(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_228(a) "BBXEX_CONFIG_228"
#define busnum_CAVM_BBXEX_CONFIG_228(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_228(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_229
 *
 * BBX5 Configuration Register 229
 * Job Configuration
 */
union cavm_bbxex_config_229
{
    uint64_t u;
    struct cavm_bbxex_config_229_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_229_s cn; */
};
typedef union cavm_bbxex_config_229 cavm_bbxex_config_229_t;

static inline uint64_t CAVM_BBXEX_CONFIG_229(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_229(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02728ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_229", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_229(a) cavm_bbxex_config_229_t
#define bustype_CAVM_BBXEX_CONFIG_229(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_229(a) "BBXEX_CONFIG_229"
#define busnum_CAVM_BBXEX_CONFIG_229(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_229(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_23
 *
 * BBX5 Configuration Register 23
 * Job Configuration
 */
union cavm_bbxex_config_23
{
    uint64_t u;
    struct cavm_bbxex_config_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_23_s cn; */
};
typedef union cavm_bbxex_config_23 cavm_bbxex_config_23_t;

static inline uint64_t CAVM_BBXEX_CONFIG_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_23", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_23(a) cavm_bbxex_config_23_t
#define bustype_CAVM_BBXEX_CONFIG_23(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_23(a) "BBXEX_CONFIG_23"
#define busnum_CAVM_BBXEX_CONFIG_23(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_23(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_230
 *
 * BBX5 Configuration Register 230
 * Job Configuration
 */
union cavm_bbxex_config_230
{
    uint64_t u;
    struct cavm_bbxex_config_230_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_230_s cn; */
};
typedef union cavm_bbxex_config_230 cavm_bbxex_config_230_t;

static inline uint64_t CAVM_BBXEX_CONFIG_230(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_230(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02730ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_230", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_230(a) cavm_bbxex_config_230_t
#define bustype_CAVM_BBXEX_CONFIG_230(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_230(a) "BBXEX_CONFIG_230"
#define busnum_CAVM_BBXEX_CONFIG_230(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_230(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_231
 *
 * BBX5 Configuration Register 231
 * Job Configuration
 */
union cavm_bbxex_config_231
{
    uint64_t u;
    struct cavm_bbxex_config_231_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_231_s cn; */
};
typedef union cavm_bbxex_config_231 cavm_bbxex_config_231_t;

static inline uint64_t CAVM_BBXEX_CONFIG_231(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_231(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02738ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_231", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_231(a) cavm_bbxex_config_231_t
#define bustype_CAVM_BBXEX_CONFIG_231(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_231(a) "BBXEX_CONFIG_231"
#define busnum_CAVM_BBXEX_CONFIG_231(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_231(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_232
 *
 * BBX5 Configuration Register 232
 * Job Configuration
 */
union cavm_bbxex_config_232
{
    uint64_t u;
    struct cavm_bbxex_config_232_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_232_s cn; */
};
typedef union cavm_bbxex_config_232 cavm_bbxex_config_232_t;

static inline uint64_t CAVM_BBXEX_CONFIG_232(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_232(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02740ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_232", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_232(a) cavm_bbxex_config_232_t
#define bustype_CAVM_BBXEX_CONFIG_232(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_232(a) "BBXEX_CONFIG_232"
#define busnum_CAVM_BBXEX_CONFIG_232(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_232(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_233
 *
 * BBX5 Configuration Register 233
 * Job Configuration
 */
union cavm_bbxex_config_233
{
    uint64_t u;
    struct cavm_bbxex_config_233_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_233_s cn; */
};
typedef union cavm_bbxex_config_233 cavm_bbxex_config_233_t;

static inline uint64_t CAVM_BBXEX_CONFIG_233(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_233(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02748ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_233", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_233(a) cavm_bbxex_config_233_t
#define bustype_CAVM_BBXEX_CONFIG_233(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_233(a) "BBXEX_CONFIG_233"
#define busnum_CAVM_BBXEX_CONFIG_233(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_233(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_234
 *
 * BBX5 Configuration Register 234
 * Job Configuration
 */
union cavm_bbxex_config_234
{
    uint64_t u;
    struct cavm_bbxex_config_234_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_234_s cn; */
};
typedef union cavm_bbxex_config_234 cavm_bbxex_config_234_t;

static inline uint64_t CAVM_BBXEX_CONFIG_234(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_234(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02750ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_234", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_234(a) cavm_bbxex_config_234_t
#define bustype_CAVM_BBXEX_CONFIG_234(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_234(a) "BBXEX_CONFIG_234"
#define busnum_CAVM_BBXEX_CONFIG_234(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_234(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_235
 *
 * BBX5 Configuration Register 235
 * Job Configuration
 */
union cavm_bbxex_config_235
{
    uint64_t u;
    struct cavm_bbxex_config_235_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_235_s cn; */
};
typedef union cavm_bbxex_config_235 cavm_bbxex_config_235_t;

static inline uint64_t CAVM_BBXEX_CONFIG_235(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_235(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02758ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_235", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_235(a) cavm_bbxex_config_235_t
#define bustype_CAVM_BBXEX_CONFIG_235(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_235(a) "BBXEX_CONFIG_235"
#define busnum_CAVM_BBXEX_CONFIG_235(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_235(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_236
 *
 * BBX5 Configuration Register 236
 * Job Configuration
 */
union cavm_bbxex_config_236
{
    uint64_t u;
    struct cavm_bbxex_config_236_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_236_s cn; */
};
typedef union cavm_bbxex_config_236 cavm_bbxex_config_236_t;

static inline uint64_t CAVM_BBXEX_CONFIG_236(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_236(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02760ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_236", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_236(a) cavm_bbxex_config_236_t
#define bustype_CAVM_BBXEX_CONFIG_236(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_236(a) "BBXEX_CONFIG_236"
#define busnum_CAVM_BBXEX_CONFIG_236(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_236(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_237
 *
 * BBX5 Configuration Register 237
 * Job Configuration
 */
union cavm_bbxex_config_237
{
    uint64_t u;
    struct cavm_bbxex_config_237_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_237_s cn; */
};
typedef union cavm_bbxex_config_237 cavm_bbxex_config_237_t;

static inline uint64_t CAVM_BBXEX_CONFIG_237(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_237(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02768ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_237", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_237(a) cavm_bbxex_config_237_t
#define bustype_CAVM_BBXEX_CONFIG_237(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_237(a) "BBXEX_CONFIG_237"
#define busnum_CAVM_BBXEX_CONFIG_237(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_237(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_238
 *
 * BBX5 Configuration Register 238
 * Job Configuration
 */
union cavm_bbxex_config_238
{
    uint64_t u;
    struct cavm_bbxex_config_238_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_238_s cn; */
};
typedef union cavm_bbxex_config_238 cavm_bbxex_config_238_t;

static inline uint64_t CAVM_BBXEX_CONFIG_238(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_238(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02770ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_238", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_238(a) cavm_bbxex_config_238_t
#define bustype_CAVM_BBXEX_CONFIG_238(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_238(a) "BBXEX_CONFIG_238"
#define busnum_CAVM_BBXEX_CONFIG_238(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_238(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_239
 *
 * BBX5 Configuration Register 239
 * Job Configuration
 */
union cavm_bbxex_config_239
{
    uint64_t u;
    struct cavm_bbxex_config_239_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_239_s cn; */
};
typedef union cavm_bbxex_config_239 cavm_bbxex_config_239_t;

static inline uint64_t CAVM_BBXEX_CONFIG_239(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_239(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02778ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_239", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_239(a) cavm_bbxex_config_239_t
#define bustype_CAVM_BBXEX_CONFIG_239(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_239(a) "BBXEX_CONFIG_239"
#define busnum_CAVM_BBXEX_CONFIG_239(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_239(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_24
 *
 * BBX5 Configuration Register 24
 * Job Configuration
 */
union cavm_bbxex_config_24
{
    uint64_t u;
    struct cavm_bbxex_config_24_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_24_s cn; */
};
typedef union cavm_bbxex_config_24 cavm_bbxex_config_24_t;

static inline uint64_t CAVM_BBXEX_CONFIG_24(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_24(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_24", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_24(a) cavm_bbxex_config_24_t
#define bustype_CAVM_BBXEX_CONFIG_24(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_24(a) "BBXEX_CONFIG_24"
#define busnum_CAVM_BBXEX_CONFIG_24(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_24(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_240
 *
 * BBX5 Configuration Register 240
 * Job Configuration
 */
union cavm_bbxex_config_240
{
    uint64_t u;
    struct cavm_bbxex_config_240_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_240_s cn; */
};
typedef union cavm_bbxex_config_240 cavm_bbxex_config_240_t;

static inline uint64_t CAVM_BBXEX_CONFIG_240(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_240(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02780ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_240", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_240(a) cavm_bbxex_config_240_t
#define bustype_CAVM_BBXEX_CONFIG_240(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_240(a) "BBXEX_CONFIG_240"
#define busnum_CAVM_BBXEX_CONFIG_240(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_240(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_241
 *
 * BBX5 Configuration Register 241
 * Job Configuration
 */
union cavm_bbxex_config_241
{
    uint64_t u;
    struct cavm_bbxex_config_241_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_241_s cn; */
};
typedef union cavm_bbxex_config_241 cavm_bbxex_config_241_t;

static inline uint64_t CAVM_BBXEX_CONFIG_241(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_241(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02788ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_241", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_241(a) cavm_bbxex_config_241_t
#define bustype_CAVM_BBXEX_CONFIG_241(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_241(a) "BBXEX_CONFIG_241"
#define busnum_CAVM_BBXEX_CONFIG_241(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_241(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_242
 *
 * BBX5 Configuration Register 242
 * Job Configuration
 */
union cavm_bbxex_config_242
{
    uint64_t u;
    struct cavm_bbxex_config_242_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_242_s cn; */
};
typedef union cavm_bbxex_config_242 cavm_bbxex_config_242_t;

static inline uint64_t CAVM_BBXEX_CONFIG_242(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_242(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02790ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_242", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_242(a) cavm_bbxex_config_242_t
#define bustype_CAVM_BBXEX_CONFIG_242(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_242(a) "BBXEX_CONFIG_242"
#define busnum_CAVM_BBXEX_CONFIG_242(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_242(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_243
 *
 * BBX5 Configuration Register 243
 * Job Configuration
 */
union cavm_bbxex_config_243
{
    uint64_t u;
    struct cavm_bbxex_config_243_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_243_s cn; */
};
typedef union cavm_bbxex_config_243 cavm_bbxex_config_243_t;

static inline uint64_t CAVM_BBXEX_CONFIG_243(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_243(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02798ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_243", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_243(a) cavm_bbxex_config_243_t
#define bustype_CAVM_BBXEX_CONFIG_243(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_243(a) "BBXEX_CONFIG_243"
#define busnum_CAVM_BBXEX_CONFIG_243(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_243(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_244
 *
 * BBX5 Configuration Register 244
 * Job Configuration
 */
union cavm_bbxex_config_244
{
    uint64_t u;
    struct cavm_bbxex_config_244_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_244_s cn; */
};
typedef union cavm_bbxex_config_244 cavm_bbxex_config_244_t;

static inline uint64_t CAVM_BBXEX_CONFIG_244(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_244(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_244", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_244(a) cavm_bbxex_config_244_t
#define bustype_CAVM_BBXEX_CONFIG_244(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_244(a) "BBXEX_CONFIG_244"
#define busnum_CAVM_BBXEX_CONFIG_244(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_244(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_245
 *
 * BBX5 Configuration Register 245
 * Job Configuration
 */
union cavm_bbxex_config_245
{
    uint64_t u;
    struct cavm_bbxex_config_245_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_245_s cn; */
};
typedef union cavm_bbxex_config_245 cavm_bbxex_config_245_t;

static inline uint64_t CAVM_BBXEX_CONFIG_245(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_245(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_245", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_245(a) cavm_bbxex_config_245_t
#define bustype_CAVM_BBXEX_CONFIG_245(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_245(a) "BBXEX_CONFIG_245"
#define busnum_CAVM_BBXEX_CONFIG_245(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_245(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_246
 *
 * BBX5 Configuration Register 246
 * Job Configuration
 */
union cavm_bbxex_config_246
{
    uint64_t u;
    struct cavm_bbxex_config_246_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_246_s cn; */
};
typedef union cavm_bbxex_config_246 cavm_bbxex_config_246_t;

static inline uint64_t CAVM_BBXEX_CONFIG_246(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_246(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_246", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_246(a) cavm_bbxex_config_246_t
#define bustype_CAVM_BBXEX_CONFIG_246(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_246(a) "BBXEX_CONFIG_246"
#define busnum_CAVM_BBXEX_CONFIG_246(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_246(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_247
 *
 * BBX5 Configuration Register 247
 * Job Configuration
 */
union cavm_bbxex_config_247
{
    uint64_t u;
    struct cavm_bbxex_config_247_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_247_s cn; */
};
typedef union cavm_bbxex_config_247 cavm_bbxex_config_247_t;

static inline uint64_t CAVM_BBXEX_CONFIG_247(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_247(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_247", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_247(a) cavm_bbxex_config_247_t
#define bustype_CAVM_BBXEX_CONFIG_247(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_247(a) "BBXEX_CONFIG_247"
#define busnum_CAVM_BBXEX_CONFIG_247(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_247(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_248
 *
 * BBX5 Configuration Register 248
 * Job Configuration
 */
union cavm_bbxex_config_248
{
    uint64_t u;
    struct cavm_bbxex_config_248_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_248_s cn; */
};
typedef union cavm_bbxex_config_248 cavm_bbxex_config_248_t;

static inline uint64_t CAVM_BBXEX_CONFIG_248(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_248(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_248", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_248(a) cavm_bbxex_config_248_t
#define bustype_CAVM_BBXEX_CONFIG_248(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_248(a) "BBXEX_CONFIG_248"
#define busnum_CAVM_BBXEX_CONFIG_248(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_248(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_249
 *
 * BBX5 Configuration Register 249
 * Job Configuration
 */
union cavm_bbxex_config_249
{
    uint64_t u;
    struct cavm_bbxex_config_249_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_249_s cn; */
};
typedef union cavm_bbxex_config_249 cavm_bbxex_config_249_t;

static inline uint64_t CAVM_BBXEX_CONFIG_249(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_249(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_249", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_249(a) cavm_bbxex_config_249_t
#define bustype_CAVM_BBXEX_CONFIG_249(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_249(a) "BBXEX_CONFIG_249"
#define busnum_CAVM_BBXEX_CONFIG_249(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_249(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_25
 *
 * BBX5 Configuration Register 25
 * Job Configuration
 */
union cavm_bbxex_config_25
{
    uint64_t u;
    struct cavm_bbxex_config_25_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_25_s cn; */
};
typedef union cavm_bbxex_config_25 cavm_bbxex_config_25_t;

static inline uint64_t CAVM_BBXEX_CONFIG_25(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_25(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_25", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_25(a) cavm_bbxex_config_25_t
#define bustype_CAVM_BBXEX_CONFIG_25(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_25(a) "BBXEX_CONFIG_25"
#define busnum_CAVM_BBXEX_CONFIG_25(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_25(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_250
 *
 * BBX5 Configuration Register 250
 * Job Configuration
 */
union cavm_bbxex_config_250
{
    uint64_t u;
    struct cavm_bbxex_config_250_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_250_s cn; */
};
typedef union cavm_bbxex_config_250 cavm_bbxex_config_250_t;

static inline uint64_t CAVM_BBXEX_CONFIG_250(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_250(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_250", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_250(a) cavm_bbxex_config_250_t
#define bustype_CAVM_BBXEX_CONFIG_250(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_250(a) "BBXEX_CONFIG_250"
#define busnum_CAVM_BBXEX_CONFIG_250(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_250(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_251
 *
 * BBX5 Configuration Register 251
 * Job Configuration
 */
union cavm_bbxex_config_251
{
    uint64_t u;
    struct cavm_bbxex_config_251_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_251_s cn; */
};
typedef union cavm_bbxex_config_251 cavm_bbxex_config_251_t;

static inline uint64_t CAVM_BBXEX_CONFIG_251(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_251(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_251", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_251(a) cavm_bbxex_config_251_t
#define bustype_CAVM_BBXEX_CONFIG_251(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_251(a) "BBXEX_CONFIG_251"
#define busnum_CAVM_BBXEX_CONFIG_251(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_251(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_252
 *
 * BBX5 Configuration Register 252
 * Job Configuration
 */
union cavm_bbxex_config_252
{
    uint64_t u;
    struct cavm_bbxex_config_252_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_252_s cn; */
};
typedef union cavm_bbxex_config_252 cavm_bbxex_config_252_t;

static inline uint64_t CAVM_BBXEX_CONFIG_252(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_252(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_252", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_252(a) cavm_bbxex_config_252_t
#define bustype_CAVM_BBXEX_CONFIG_252(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_252(a) "BBXEX_CONFIG_252"
#define busnum_CAVM_BBXEX_CONFIG_252(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_252(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_253
 *
 * BBX5 Configuration Register 253
 * Job Configuration
 */
union cavm_bbxex_config_253
{
    uint64_t u;
    struct cavm_bbxex_config_253_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_253_s cn; */
};
typedef union cavm_bbxex_config_253 cavm_bbxex_config_253_t;

static inline uint64_t CAVM_BBXEX_CONFIG_253(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_253(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_253", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_253(a) cavm_bbxex_config_253_t
#define bustype_CAVM_BBXEX_CONFIG_253(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_253(a) "BBXEX_CONFIG_253"
#define busnum_CAVM_BBXEX_CONFIG_253(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_253(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_254
 *
 * BBX5 Configuration Register 254
 * Job Configuration
 */
union cavm_bbxex_config_254
{
    uint64_t u;
    struct cavm_bbxex_config_254_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_254_s cn; */
};
typedef union cavm_bbxex_config_254 cavm_bbxex_config_254_t;

static inline uint64_t CAVM_BBXEX_CONFIG_254(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_254(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_254", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_254(a) cavm_bbxex_config_254_t
#define bustype_CAVM_BBXEX_CONFIG_254(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_254(a) "BBXEX_CONFIG_254"
#define busnum_CAVM_BBXEX_CONFIG_254(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_254(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_255
 *
 * BBX5 Configuration Register 255
 * Job Configuration
 */
union cavm_bbxex_config_255
{
    uint64_t u;
    struct cavm_bbxex_config_255_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_255_s cn; */
};
typedef union cavm_bbxex_config_255 cavm_bbxex_config_255_t;

static inline uint64_t CAVM_BBXEX_CONFIG_255(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_255(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c027f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_255", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_255(a) cavm_bbxex_config_255_t
#define bustype_CAVM_BBXEX_CONFIG_255(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_255(a) "BBXEX_CONFIG_255"
#define busnum_CAVM_BBXEX_CONFIG_255(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_255(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_256
 *
 * BBX5 Configuration Register 256
 * Job Configuration
 */
union cavm_bbxex_config_256
{
    uint64_t u;
    struct cavm_bbxex_config_256_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_256_s cn; */
};
typedef union cavm_bbxex_config_256 cavm_bbxex_config_256_t;

static inline uint64_t CAVM_BBXEX_CONFIG_256(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_256(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02800ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_256", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_256(a) cavm_bbxex_config_256_t
#define bustype_CAVM_BBXEX_CONFIG_256(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_256(a) "BBXEX_CONFIG_256"
#define busnum_CAVM_BBXEX_CONFIG_256(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_256(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_257
 *
 * BBX5 Configuration Register 257
 * Job Configuration
 */
union cavm_bbxex_config_257
{
    uint64_t u;
    struct cavm_bbxex_config_257_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_257_s cn; */
};
typedef union cavm_bbxex_config_257 cavm_bbxex_config_257_t;

static inline uint64_t CAVM_BBXEX_CONFIG_257(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_257(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02808ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_257", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_257(a) cavm_bbxex_config_257_t
#define bustype_CAVM_BBXEX_CONFIG_257(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_257(a) "BBXEX_CONFIG_257"
#define busnum_CAVM_BBXEX_CONFIG_257(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_257(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_258
 *
 * BBX5 Configuration Register 258
 * Job Configuration
 */
union cavm_bbxex_config_258
{
    uint64_t u;
    struct cavm_bbxex_config_258_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_258_s cn; */
};
typedef union cavm_bbxex_config_258 cavm_bbxex_config_258_t;

static inline uint64_t CAVM_BBXEX_CONFIG_258(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_258(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02810ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_258", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_258(a) cavm_bbxex_config_258_t
#define bustype_CAVM_BBXEX_CONFIG_258(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_258(a) "BBXEX_CONFIG_258"
#define busnum_CAVM_BBXEX_CONFIG_258(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_258(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_259
 *
 * BBX5 Configuration Register 259
 * Job Configuration
 */
union cavm_bbxex_config_259
{
    uint64_t u;
    struct cavm_bbxex_config_259_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_259_s cn; */
};
typedef union cavm_bbxex_config_259 cavm_bbxex_config_259_t;

static inline uint64_t CAVM_BBXEX_CONFIG_259(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_259(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02818ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_259", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_259(a) cavm_bbxex_config_259_t
#define bustype_CAVM_BBXEX_CONFIG_259(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_259(a) "BBXEX_CONFIG_259"
#define busnum_CAVM_BBXEX_CONFIG_259(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_259(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_26
 *
 * BBX5 Configuration Register 26
 * Job Configuration
 */
union cavm_bbxex_config_26
{
    uint64_t u;
    struct cavm_bbxex_config_26_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_26_s cn; */
};
typedef union cavm_bbxex_config_26 cavm_bbxex_config_26_t;

static inline uint64_t CAVM_BBXEX_CONFIG_26(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_26(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_26", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_26(a) cavm_bbxex_config_26_t
#define bustype_CAVM_BBXEX_CONFIG_26(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_26(a) "BBXEX_CONFIG_26"
#define busnum_CAVM_BBXEX_CONFIG_26(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_26(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_260
 *
 * BBX5 Configuration Register 260
 * Job Configuration
 */
union cavm_bbxex_config_260
{
    uint64_t u;
    struct cavm_bbxex_config_260_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_260_s cn; */
};
typedef union cavm_bbxex_config_260 cavm_bbxex_config_260_t;

static inline uint64_t CAVM_BBXEX_CONFIG_260(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_260(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02820ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_260", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_260(a) cavm_bbxex_config_260_t
#define bustype_CAVM_BBXEX_CONFIG_260(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_260(a) "BBXEX_CONFIG_260"
#define busnum_CAVM_BBXEX_CONFIG_260(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_260(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_261
 *
 * BBX5 Configuration Register 261
 * Job Configuration
 */
union cavm_bbxex_config_261
{
    uint64_t u;
    struct cavm_bbxex_config_261_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_261_s cn; */
};
typedef union cavm_bbxex_config_261 cavm_bbxex_config_261_t;

static inline uint64_t CAVM_BBXEX_CONFIG_261(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_261(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02828ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_261", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_261(a) cavm_bbxex_config_261_t
#define bustype_CAVM_BBXEX_CONFIG_261(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_261(a) "BBXEX_CONFIG_261"
#define busnum_CAVM_BBXEX_CONFIG_261(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_261(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_262
 *
 * BBX5 Configuration Register 262
 * Job Configuration
 */
union cavm_bbxex_config_262
{
    uint64_t u;
    struct cavm_bbxex_config_262_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_262_s cn; */
};
typedef union cavm_bbxex_config_262 cavm_bbxex_config_262_t;

static inline uint64_t CAVM_BBXEX_CONFIG_262(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_262(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02830ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_262", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_262(a) cavm_bbxex_config_262_t
#define bustype_CAVM_BBXEX_CONFIG_262(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_262(a) "BBXEX_CONFIG_262"
#define busnum_CAVM_BBXEX_CONFIG_262(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_262(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_263
 *
 * BBX5 Configuration Register 263
 * Job Configuration
 */
union cavm_bbxex_config_263
{
    uint64_t u;
    struct cavm_bbxex_config_263_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_263_s cn; */
};
typedef union cavm_bbxex_config_263 cavm_bbxex_config_263_t;

static inline uint64_t CAVM_BBXEX_CONFIG_263(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_263(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02838ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_263", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_263(a) cavm_bbxex_config_263_t
#define bustype_CAVM_BBXEX_CONFIG_263(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_263(a) "BBXEX_CONFIG_263"
#define busnum_CAVM_BBXEX_CONFIG_263(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_263(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_264
 *
 * BBX5 Configuration Register 264
 * Job Configuration
 */
union cavm_bbxex_config_264
{
    uint64_t u;
    struct cavm_bbxex_config_264_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_264_s cn; */
};
typedef union cavm_bbxex_config_264 cavm_bbxex_config_264_t;

static inline uint64_t CAVM_BBXEX_CONFIG_264(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_264(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02840ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_264", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_264(a) cavm_bbxex_config_264_t
#define bustype_CAVM_BBXEX_CONFIG_264(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_264(a) "BBXEX_CONFIG_264"
#define busnum_CAVM_BBXEX_CONFIG_264(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_264(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_265
 *
 * BBX5 Configuration Register 265
 * Job Configuration
 */
union cavm_bbxex_config_265
{
    uint64_t u;
    struct cavm_bbxex_config_265_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_265_s cn; */
};
typedef union cavm_bbxex_config_265 cavm_bbxex_config_265_t;

static inline uint64_t CAVM_BBXEX_CONFIG_265(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_265(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02848ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_265", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_265(a) cavm_bbxex_config_265_t
#define bustype_CAVM_BBXEX_CONFIG_265(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_265(a) "BBXEX_CONFIG_265"
#define busnum_CAVM_BBXEX_CONFIG_265(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_265(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_266
 *
 * BBX5 Configuration Register 266
 * Job Configuration
 */
union cavm_bbxex_config_266
{
    uint64_t u;
    struct cavm_bbxex_config_266_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_266_s cn; */
};
typedef union cavm_bbxex_config_266 cavm_bbxex_config_266_t;

static inline uint64_t CAVM_BBXEX_CONFIG_266(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_266(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02850ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_266", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_266(a) cavm_bbxex_config_266_t
#define bustype_CAVM_BBXEX_CONFIG_266(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_266(a) "BBXEX_CONFIG_266"
#define busnum_CAVM_BBXEX_CONFIG_266(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_266(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_267
 *
 * BBX5 Configuration Register 267
 * Job Configuration
 */
union cavm_bbxex_config_267
{
    uint64_t u;
    struct cavm_bbxex_config_267_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_267_s cn; */
};
typedef union cavm_bbxex_config_267 cavm_bbxex_config_267_t;

static inline uint64_t CAVM_BBXEX_CONFIG_267(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_267(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02858ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_267", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_267(a) cavm_bbxex_config_267_t
#define bustype_CAVM_BBXEX_CONFIG_267(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_267(a) "BBXEX_CONFIG_267"
#define busnum_CAVM_BBXEX_CONFIG_267(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_267(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_268
 *
 * BBX5 Configuration Register 268
 * Job Configuration
 */
union cavm_bbxex_config_268
{
    uint64_t u;
    struct cavm_bbxex_config_268_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_268_s cn; */
};
typedef union cavm_bbxex_config_268 cavm_bbxex_config_268_t;

static inline uint64_t CAVM_BBXEX_CONFIG_268(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_268(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02860ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_268", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_268(a) cavm_bbxex_config_268_t
#define bustype_CAVM_BBXEX_CONFIG_268(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_268(a) "BBXEX_CONFIG_268"
#define busnum_CAVM_BBXEX_CONFIG_268(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_268(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_269
 *
 * BBX5 Configuration Register 269
 * Job Configuration
 */
union cavm_bbxex_config_269
{
    uint64_t u;
    struct cavm_bbxex_config_269_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_269_s cn; */
};
typedef union cavm_bbxex_config_269 cavm_bbxex_config_269_t;

static inline uint64_t CAVM_BBXEX_CONFIG_269(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_269(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02868ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_269", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_269(a) cavm_bbxex_config_269_t
#define bustype_CAVM_BBXEX_CONFIG_269(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_269(a) "BBXEX_CONFIG_269"
#define busnum_CAVM_BBXEX_CONFIG_269(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_269(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_27
 *
 * BBX5 Configuration Register 27
 * Job Configuration
 */
union cavm_bbxex_config_27
{
    uint64_t u;
    struct cavm_bbxex_config_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_27_s cn; */
};
typedef union cavm_bbxex_config_27 cavm_bbxex_config_27_t;

static inline uint64_t CAVM_BBXEX_CONFIG_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_27", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_27(a) cavm_bbxex_config_27_t
#define bustype_CAVM_BBXEX_CONFIG_27(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_27(a) "BBXEX_CONFIG_27"
#define busnum_CAVM_BBXEX_CONFIG_27(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_27(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_270
 *
 * BBX5 Configuration Register 270
 * Job Configuration
 */
union cavm_bbxex_config_270
{
    uint64_t u;
    struct cavm_bbxex_config_270_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_270_s cn; */
};
typedef union cavm_bbxex_config_270 cavm_bbxex_config_270_t;

static inline uint64_t CAVM_BBXEX_CONFIG_270(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_270(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02870ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_270", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_270(a) cavm_bbxex_config_270_t
#define bustype_CAVM_BBXEX_CONFIG_270(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_270(a) "BBXEX_CONFIG_270"
#define busnum_CAVM_BBXEX_CONFIG_270(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_270(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_271
 *
 * BBX5 Configuration Register 271
 * Job Configuration
 */
union cavm_bbxex_config_271
{
    uint64_t u;
    struct cavm_bbxex_config_271_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_271_s cn; */
};
typedef union cavm_bbxex_config_271 cavm_bbxex_config_271_t;

static inline uint64_t CAVM_BBXEX_CONFIG_271(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_271(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02878ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_271", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_271(a) cavm_bbxex_config_271_t
#define bustype_CAVM_BBXEX_CONFIG_271(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_271(a) "BBXEX_CONFIG_271"
#define busnum_CAVM_BBXEX_CONFIG_271(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_271(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_272
 *
 * BBX5 Configuration Register 272
 * Job Configuration
 */
union cavm_bbxex_config_272
{
    uint64_t u;
    struct cavm_bbxex_config_272_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_272_s cn; */
};
typedef union cavm_bbxex_config_272 cavm_bbxex_config_272_t;

static inline uint64_t CAVM_BBXEX_CONFIG_272(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_272(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02880ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_272", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_272(a) cavm_bbxex_config_272_t
#define bustype_CAVM_BBXEX_CONFIG_272(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_272(a) "BBXEX_CONFIG_272"
#define busnum_CAVM_BBXEX_CONFIG_272(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_272(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_273
 *
 * BBX5 Configuration Register 273
 * Job Configuration
 */
union cavm_bbxex_config_273
{
    uint64_t u;
    struct cavm_bbxex_config_273_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_273_s cn; */
};
typedef union cavm_bbxex_config_273 cavm_bbxex_config_273_t;

static inline uint64_t CAVM_BBXEX_CONFIG_273(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_273(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02888ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_273", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_273(a) cavm_bbxex_config_273_t
#define bustype_CAVM_BBXEX_CONFIG_273(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_273(a) "BBXEX_CONFIG_273"
#define busnum_CAVM_BBXEX_CONFIG_273(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_273(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_274
 *
 * BBX5 Configuration Register 274
 * Job Configuration
 */
union cavm_bbxex_config_274
{
    uint64_t u;
    struct cavm_bbxex_config_274_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_274_s cn; */
};
typedef union cavm_bbxex_config_274 cavm_bbxex_config_274_t;

static inline uint64_t CAVM_BBXEX_CONFIG_274(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_274(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02890ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_274", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_274(a) cavm_bbxex_config_274_t
#define bustype_CAVM_BBXEX_CONFIG_274(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_274(a) "BBXEX_CONFIG_274"
#define busnum_CAVM_BBXEX_CONFIG_274(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_274(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_275
 *
 * BBX5 Configuration Register 275
 * Job Configuration
 */
union cavm_bbxex_config_275
{
    uint64_t u;
    struct cavm_bbxex_config_275_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_275_s cn; */
};
typedef union cavm_bbxex_config_275 cavm_bbxex_config_275_t;

static inline uint64_t CAVM_BBXEX_CONFIG_275(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_275(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02898ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_275", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_275(a) cavm_bbxex_config_275_t
#define bustype_CAVM_BBXEX_CONFIG_275(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_275(a) "BBXEX_CONFIG_275"
#define busnum_CAVM_BBXEX_CONFIG_275(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_275(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_276
 *
 * BBX5 Configuration Register 276
 * Job Configuration
 */
union cavm_bbxex_config_276
{
    uint64_t u;
    struct cavm_bbxex_config_276_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_276_s cn; */
};
typedef union cavm_bbxex_config_276 cavm_bbxex_config_276_t;

static inline uint64_t CAVM_BBXEX_CONFIG_276(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_276(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_276", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_276(a) cavm_bbxex_config_276_t
#define bustype_CAVM_BBXEX_CONFIG_276(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_276(a) "BBXEX_CONFIG_276"
#define busnum_CAVM_BBXEX_CONFIG_276(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_276(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_277
 *
 * BBX5 Configuration Register 277
 * Job Configuration
 */
union cavm_bbxex_config_277
{
    uint64_t u;
    struct cavm_bbxex_config_277_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_277_s cn; */
};
typedef union cavm_bbxex_config_277 cavm_bbxex_config_277_t;

static inline uint64_t CAVM_BBXEX_CONFIG_277(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_277(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_277", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_277(a) cavm_bbxex_config_277_t
#define bustype_CAVM_BBXEX_CONFIG_277(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_277(a) "BBXEX_CONFIG_277"
#define busnum_CAVM_BBXEX_CONFIG_277(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_277(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_278
 *
 * BBX5 Configuration Register 278
 * Job Configuration
 */
union cavm_bbxex_config_278
{
    uint64_t u;
    struct cavm_bbxex_config_278_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_278_s cn; */
};
typedef union cavm_bbxex_config_278 cavm_bbxex_config_278_t;

static inline uint64_t CAVM_BBXEX_CONFIG_278(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_278(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_278", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_278(a) cavm_bbxex_config_278_t
#define bustype_CAVM_BBXEX_CONFIG_278(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_278(a) "BBXEX_CONFIG_278"
#define busnum_CAVM_BBXEX_CONFIG_278(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_278(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_279
 *
 * BBX5 Configuration Register 279
 * Job Configuration
 */
union cavm_bbxex_config_279
{
    uint64_t u;
    struct cavm_bbxex_config_279_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_279_s cn; */
};
typedef union cavm_bbxex_config_279 cavm_bbxex_config_279_t;

static inline uint64_t CAVM_BBXEX_CONFIG_279(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_279(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_279", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_279(a) cavm_bbxex_config_279_t
#define bustype_CAVM_BBXEX_CONFIG_279(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_279(a) "BBXEX_CONFIG_279"
#define busnum_CAVM_BBXEX_CONFIG_279(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_279(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_28
 *
 * BBX5 Configuration Register 28
 * Job Configuration
 */
union cavm_bbxex_config_28
{
    uint64_t u;
    struct cavm_bbxex_config_28_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_28_s cn; */
};
typedef union cavm_bbxex_config_28 cavm_bbxex_config_28_t;

static inline uint64_t CAVM_BBXEX_CONFIG_28(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_28(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_28", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_28(a) cavm_bbxex_config_28_t
#define bustype_CAVM_BBXEX_CONFIG_28(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_28(a) "BBXEX_CONFIG_28"
#define busnum_CAVM_BBXEX_CONFIG_28(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_28(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_280
 *
 * BBX5 Configuration Register 280
 * Job Configuration
 */
union cavm_bbxex_config_280
{
    uint64_t u;
    struct cavm_bbxex_config_280_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_280_s cn; */
};
typedef union cavm_bbxex_config_280 cavm_bbxex_config_280_t;

static inline uint64_t CAVM_BBXEX_CONFIG_280(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_280(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_280", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_280(a) cavm_bbxex_config_280_t
#define bustype_CAVM_BBXEX_CONFIG_280(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_280(a) "BBXEX_CONFIG_280"
#define busnum_CAVM_BBXEX_CONFIG_280(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_280(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_281
 *
 * BBX5 Configuration Register 281
 * Job Configuration
 */
union cavm_bbxex_config_281
{
    uint64_t u;
    struct cavm_bbxex_config_281_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_281_s cn; */
};
typedef union cavm_bbxex_config_281 cavm_bbxex_config_281_t;

static inline uint64_t CAVM_BBXEX_CONFIG_281(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_281(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_281", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_281(a) cavm_bbxex_config_281_t
#define bustype_CAVM_BBXEX_CONFIG_281(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_281(a) "BBXEX_CONFIG_281"
#define busnum_CAVM_BBXEX_CONFIG_281(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_281(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_282
 *
 * BBX5 Configuration Register 282
 * Job Configuration
 */
union cavm_bbxex_config_282
{
    uint64_t u;
    struct cavm_bbxex_config_282_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_282_s cn; */
};
typedef union cavm_bbxex_config_282 cavm_bbxex_config_282_t;

static inline uint64_t CAVM_BBXEX_CONFIG_282(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_282(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_282", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_282(a) cavm_bbxex_config_282_t
#define bustype_CAVM_BBXEX_CONFIG_282(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_282(a) "BBXEX_CONFIG_282"
#define busnum_CAVM_BBXEX_CONFIG_282(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_282(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_283
 *
 * BBX5 Configuration Register 283
 * Job Configuration
 */
union cavm_bbxex_config_283
{
    uint64_t u;
    struct cavm_bbxex_config_283_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_283_s cn; */
};
typedef union cavm_bbxex_config_283 cavm_bbxex_config_283_t;

static inline uint64_t CAVM_BBXEX_CONFIG_283(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_283(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_283", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_283(a) cavm_bbxex_config_283_t
#define bustype_CAVM_BBXEX_CONFIG_283(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_283(a) "BBXEX_CONFIG_283"
#define busnum_CAVM_BBXEX_CONFIG_283(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_283(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_284
 *
 * BBX5 Configuration Register 284
 * Job Configuration
 */
union cavm_bbxex_config_284
{
    uint64_t u;
    struct cavm_bbxex_config_284_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_284_s cn; */
};
typedef union cavm_bbxex_config_284 cavm_bbxex_config_284_t;

static inline uint64_t CAVM_BBXEX_CONFIG_284(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_284(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_284", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_284(a) cavm_bbxex_config_284_t
#define bustype_CAVM_BBXEX_CONFIG_284(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_284(a) "BBXEX_CONFIG_284"
#define busnum_CAVM_BBXEX_CONFIG_284(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_284(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_285
 *
 * BBX5 Configuration Register 285
 * Job Configuration
 */
union cavm_bbxex_config_285
{
    uint64_t u;
    struct cavm_bbxex_config_285_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_285_s cn; */
};
typedef union cavm_bbxex_config_285 cavm_bbxex_config_285_t;

static inline uint64_t CAVM_BBXEX_CONFIG_285(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_285(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_285", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_285(a) cavm_bbxex_config_285_t
#define bustype_CAVM_BBXEX_CONFIG_285(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_285(a) "BBXEX_CONFIG_285"
#define busnum_CAVM_BBXEX_CONFIG_285(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_285(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_286
 *
 * BBX5 Configuration Register 286
 * Job Configuration
 */
union cavm_bbxex_config_286
{
    uint64_t u;
    struct cavm_bbxex_config_286_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_286_s cn; */
};
typedef union cavm_bbxex_config_286 cavm_bbxex_config_286_t;

static inline uint64_t CAVM_BBXEX_CONFIG_286(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_286(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_286", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_286(a) cavm_bbxex_config_286_t
#define bustype_CAVM_BBXEX_CONFIG_286(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_286(a) "BBXEX_CONFIG_286"
#define busnum_CAVM_BBXEX_CONFIG_286(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_286(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_287
 *
 * BBX5 Configuration Register 287
 * Job Configuration
 */
union cavm_bbxex_config_287
{
    uint64_t u;
    struct cavm_bbxex_config_287_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_287_s cn; */
};
typedef union cavm_bbxex_config_287 cavm_bbxex_config_287_t;

static inline uint64_t CAVM_BBXEX_CONFIG_287(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_287(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c028f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_287", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_287(a) cavm_bbxex_config_287_t
#define bustype_CAVM_BBXEX_CONFIG_287(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_287(a) "BBXEX_CONFIG_287"
#define busnum_CAVM_BBXEX_CONFIG_287(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_287(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_288
 *
 * BBX5 Configuration Register 288
 * Job Configuration
 */
union cavm_bbxex_config_288
{
    uint64_t u;
    struct cavm_bbxex_config_288_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_288_s cn; */
};
typedef union cavm_bbxex_config_288 cavm_bbxex_config_288_t;

static inline uint64_t CAVM_BBXEX_CONFIG_288(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_288(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02900ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_288", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_288(a) cavm_bbxex_config_288_t
#define bustype_CAVM_BBXEX_CONFIG_288(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_288(a) "BBXEX_CONFIG_288"
#define busnum_CAVM_BBXEX_CONFIG_288(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_288(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_289
 *
 * BBX5 Configuration Register 289
 * Job Configuration
 */
union cavm_bbxex_config_289
{
    uint64_t u;
    struct cavm_bbxex_config_289_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_289_s cn; */
};
typedef union cavm_bbxex_config_289 cavm_bbxex_config_289_t;

static inline uint64_t CAVM_BBXEX_CONFIG_289(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_289(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02908ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_289", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_289(a) cavm_bbxex_config_289_t
#define bustype_CAVM_BBXEX_CONFIG_289(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_289(a) "BBXEX_CONFIG_289"
#define busnum_CAVM_BBXEX_CONFIG_289(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_289(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_29
 *
 * BBX5 Configuration Register 29
 * Job Configuration
 */
union cavm_bbxex_config_29
{
    uint64_t u;
    struct cavm_bbxex_config_29_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_29_s cn; */
};
typedef union cavm_bbxex_config_29 cavm_bbxex_config_29_t;

static inline uint64_t CAVM_BBXEX_CONFIG_29(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_29(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_29", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_29(a) cavm_bbxex_config_29_t
#define bustype_CAVM_BBXEX_CONFIG_29(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_29(a) "BBXEX_CONFIG_29"
#define busnum_CAVM_BBXEX_CONFIG_29(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_29(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_290
 *
 * BBX5 Configuration Register 290
 * Job Configuration
 */
union cavm_bbxex_config_290
{
    uint64_t u;
    struct cavm_bbxex_config_290_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_290_s cn; */
};
typedef union cavm_bbxex_config_290 cavm_bbxex_config_290_t;

static inline uint64_t CAVM_BBXEX_CONFIG_290(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_290(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02910ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_290", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_290(a) cavm_bbxex_config_290_t
#define bustype_CAVM_BBXEX_CONFIG_290(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_290(a) "BBXEX_CONFIG_290"
#define busnum_CAVM_BBXEX_CONFIG_290(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_290(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_291
 *
 * BBX5 Configuration Register 291
 * Job Configuration
 */
union cavm_bbxex_config_291
{
    uint64_t u;
    struct cavm_bbxex_config_291_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_291_s cn; */
};
typedef union cavm_bbxex_config_291 cavm_bbxex_config_291_t;

static inline uint64_t CAVM_BBXEX_CONFIG_291(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_291(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02918ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_291", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_291(a) cavm_bbxex_config_291_t
#define bustype_CAVM_BBXEX_CONFIG_291(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_291(a) "BBXEX_CONFIG_291"
#define busnum_CAVM_BBXEX_CONFIG_291(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_291(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_292
 *
 * BBX5 Configuration Register 292
 * Job Configuration
 */
union cavm_bbxex_config_292
{
    uint64_t u;
    struct cavm_bbxex_config_292_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_292_s cn; */
};
typedef union cavm_bbxex_config_292 cavm_bbxex_config_292_t;

static inline uint64_t CAVM_BBXEX_CONFIG_292(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_292(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02920ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_292", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_292(a) cavm_bbxex_config_292_t
#define bustype_CAVM_BBXEX_CONFIG_292(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_292(a) "BBXEX_CONFIG_292"
#define busnum_CAVM_BBXEX_CONFIG_292(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_292(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_293
 *
 * BBX5 Configuration Register 293
 * Job Configuration
 */
union cavm_bbxex_config_293
{
    uint64_t u;
    struct cavm_bbxex_config_293_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_293_s cn; */
};
typedef union cavm_bbxex_config_293 cavm_bbxex_config_293_t;

static inline uint64_t CAVM_BBXEX_CONFIG_293(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_293(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02928ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_293", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_293(a) cavm_bbxex_config_293_t
#define bustype_CAVM_BBXEX_CONFIG_293(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_293(a) "BBXEX_CONFIG_293"
#define busnum_CAVM_BBXEX_CONFIG_293(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_293(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_294
 *
 * BBX5 Configuration Register 294
 * Job Configuration
 */
union cavm_bbxex_config_294
{
    uint64_t u;
    struct cavm_bbxex_config_294_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_294_s cn; */
};
typedef union cavm_bbxex_config_294 cavm_bbxex_config_294_t;

static inline uint64_t CAVM_BBXEX_CONFIG_294(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_294(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02930ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_294", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_294(a) cavm_bbxex_config_294_t
#define bustype_CAVM_BBXEX_CONFIG_294(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_294(a) "BBXEX_CONFIG_294"
#define busnum_CAVM_BBXEX_CONFIG_294(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_294(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_295
 *
 * BBX5 Configuration Register 295
 * Job Configuration
 */
union cavm_bbxex_config_295
{
    uint64_t u;
    struct cavm_bbxex_config_295_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_295_s cn; */
};
typedef union cavm_bbxex_config_295 cavm_bbxex_config_295_t;

static inline uint64_t CAVM_BBXEX_CONFIG_295(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_295(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02938ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_295", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_295(a) cavm_bbxex_config_295_t
#define bustype_CAVM_BBXEX_CONFIG_295(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_295(a) "BBXEX_CONFIG_295"
#define busnum_CAVM_BBXEX_CONFIG_295(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_295(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_296
 *
 * BBX5 Configuration Register 296
 * Job Configuration
 */
union cavm_bbxex_config_296
{
    uint64_t u;
    struct cavm_bbxex_config_296_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_296_s cn; */
};
typedef union cavm_bbxex_config_296 cavm_bbxex_config_296_t;

static inline uint64_t CAVM_BBXEX_CONFIG_296(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_296(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02940ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_296", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_296(a) cavm_bbxex_config_296_t
#define bustype_CAVM_BBXEX_CONFIG_296(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_296(a) "BBXEX_CONFIG_296"
#define busnum_CAVM_BBXEX_CONFIG_296(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_296(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_297
 *
 * BBX5 Configuration Register 297
 * Job Configuration
 */
union cavm_bbxex_config_297
{
    uint64_t u;
    struct cavm_bbxex_config_297_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_297_s cn; */
};
typedef union cavm_bbxex_config_297 cavm_bbxex_config_297_t;

static inline uint64_t CAVM_BBXEX_CONFIG_297(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_297(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02948ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_297", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_297(a) cavm_bbxex_config_297_t
#define bustype_CAVM_BBXEX_CONFIG_297(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_297(a) "BBXEX_CONFIG_297"
#define busnum_CAVM_BBXEX_CONFIG_297(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_297(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_298
 *
 * BBX5 Configuration Register 298
 * Job Configuration
 */
union cavm_bbxex_config_298
{
    uint64_t u;
    struct cavm_bbxex_config_298_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_298_s cn; */
};
typedef union cavm_bbxex_config_298 cavm_bbxex_config_298_t;

static inline uint64_t CAVM_BBXEX_CONFIG_298(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_298(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02950ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_298", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_298(a) cavm_bbxex_config_298_t
#define bustype_CAVM_BBXEX_CONFIG_298(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_298(a) "BBXEX_CONFIG_298"
#define busnum_CAVM_BBXEX_CONFIG_298(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_298(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_299
 *
 * BBX5 Configuration Register 299
 * Job Configuration
 */
union cavm_bbxex_config_299
{
    uint64_t u;
    struct cavm_bbxex_config_299_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_299_s cn; */
};
typedef union cavm_bbxex_config_299 cavm_bbxex_config_299_t;

static inline uint64_t CAVM_BBXEX_CONFIG_299(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_299(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02958ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_299", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_299(a) cavm_bbxex_config_299_t
#define bustype_CAVM_BBXEX_CONFIG_299(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_299(a) "BBXEX_CONFIG_299"
#define busnum_CAVM_BBXEX_CONFIG_299(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_299(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_3
 *
 * BBX5 Configuration Register 3
 * Job Configuration
 */
union cavm_bbxex_config_3
{
    uint64_t u;
    struct cavm_bbxex_config_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_3_s cn; */
};
typedef union cavm_bbxex_config_3 cavm_bbxex_config_3_t;

static inline uint64_t CAVM_BBXEX_CONFIG_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_3", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_3(a) cavm_bbxex_config_3_t
#define bustype_CAVM_BBXEX_CONFIG_3(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_3(a) "BBXEX_CONFIG_3"
#define busnum_CAVM_BBXEX_CONFIG_3(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_3(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_30
 *
 * BBX5 Configuration Register 30
 * Job Configuration
 */
union cavm_bbxex_config_30
{
    uint64_t u;
    struct cavm_bbxex_config_30_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_30_s cn; */
};
typedef union cavm_bbxex_config_30 cavm_bbxex_config_30_t;

static inline uint64_t CAVM_BBXEX_CONFIG_30(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_30(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_30", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_30(a) cavm_bbxex_config_30_t
#define bustype_CAVM_BBXEX_CONFIG_30(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_30(a) "BBXEX_CONFIG_30"
#define busnum_CAVM_BBXEX_CONFIG_30(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_30(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_300
 *
 * BBX5 Configuration Register 300
 * Job Configuration
 */
union cavm_bbxex_config_300
{
    uint64_t u;
    struct cavm_bbxex_config_300_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_300_s cn; */
};
typedef union cavm_bbxex_config_300 cavm_bbxex_config_300_t;

static inline uint64_t CAVM_BBXEX_CONFIG_300(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_300(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02960ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_300", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_300(a) cavm_bbxex_config_300_t
#define bustype_CAVM_BBXEX_CONFIG_300(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_300(a) "BBXEX_CONFIG_300"
#define busnum_CAVM_BBXEX_CONFIG_300(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_300(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_301
 *
 * BBX5 Configuration Register 301
 * Job Configuration
 */
union cavm_bbxex_config_301
{
    uint64_t u;
    struct cavm_bbxex_config_301_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_301_s cn; */
};
typedef union cavm_bbxex_config_301 cavm_bbxex_config_301_t;

static inline uint64_t CAVM_BBXEX_CONFIG_301(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_301(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02968ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_301", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_301(a) cavm_bbxex_config_301_t
#define bustype_CAVM_BBXEX_CONFIG_301(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_301(a) "BBXEX_CONFIG_301"
#define busnum_CAVM_BBXEX_CONFIG_301(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_301(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_302
 *
 * BBX5 Configuration Register 302
 * Job Configuration
 */
union cavm_bbxex_config_302
{
    uint64_t u;
    struct cavm_bbxex_config_302_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_302_s cn; */
};
typedef union cavm_bbxex_config_302 cavm_bbxex_config_302_t;

static inline uint64_t CAVM_BBXEX_CONFIG_302(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_302(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02970ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_302", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_302(a) cavm_bbxex_config_302_t
#define bustype_CAVM_BBXEX_CONFIG_302(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_302(a) "BBXEX_CONFIG_302"
#define busnum_CAVM_BBXEX_CONFIG_302(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_302(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_303
 *
 * BBX5 Configuration Register 303
 * Job Configuration
 */
union cavm_bbxex_config_303
{
    uint64_t u;
    struct cavm_bbxex_config_303_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_303_s cn; */
};
typedef union cavm_bbxex_config_303 cavm_bbxex_config_303_t;

static inline uint64_t CAVM_BBXEX_CONFIG_303(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_303(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02978ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_303", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_303(a) cavm_bbxex_config_303_t
#define bustype_CAVM_BBXEX_CONFIG_303(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_303(a) "BBXEX_CONFIG_303"
#define busnum_CAVM_BBXEX_CONFIG_303(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_303(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_304
 *
 * BBX5 Configuration Register 304
 * Job Configuration
 */
union cavm_bbxex_config_304
{
    uint64_t u;
    struct cavm_bbxex_config_304_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_304_s cn; */
};
typedef union cavm_bbxex_config_304 cavm_bbxex_config_304_t;

static inline uint64_t CAVM_BBXEX_CONFIG_304(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_304(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02980ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_304", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_304(a) cavm_bbxex_config_304_t
#define bustype_CAVM_BBXEX_CONFIG_304(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_304(a) "BBXEX_CONFIG_304"
#define busnum_CAVM_BBXEX_CONFIG_304(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_304(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_305
 *
 * BBX5 Configuration Register 305
 * Job Configuration
 */
union cavm_bbxex_config_305
{
    uint64_t u;
    struct cavm_bbxex_config_305_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_305_s cn; */
};
typedef union cavm_bbxex_config_305 cavm_bbxex_config_305_t;

static inline uint64_t CAVM_BBXEX_CONFIG_305(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_305(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02988ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_305", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_305(a) cavm_bbxex_config_305_t
#define bustype_CAVM_BBXEX_CONFIG_305(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_305(a) "BBXEX_CONFIG_305"
#define busnum_CAVM_BBXEX_CONFIG_305(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_305(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_306
 *
 * BBX5 Configuration Register 306
 * Job Configuration
 */
union cavm_bbxex_config_306
{
    uint64_t u;
    struct cavm_bbxex_config_306_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_306_s cn; */
};
typedef union cavm_bbxex_config_306 cavm_bbxex_config_306_t;

static inline uint64_t CAVM_BBXEX_CONFIG_306(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_306(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02990ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_306", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_306(a) cavm_bbxex_config_306_t
#define bustype_CAVM_BBXEX_CONFIG_306(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_306(a) "BBXEX_CONFIG_306"
#define busnum_CAVM_BBXEX_CONFIG_306(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_306(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_307
 *
 * BBX5 Configuration Register 307
 * Job Configuration
 */
union cavm_bbxex_config_307
{
    uint64_t u;
    struct cavm_bbxex_config_307_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_307_s cn; */
};
typedef union cavm_bbxex_config_307 cavm_bbxex_config_307_t;

static inline uint64_t CAVM_BBXEX_CONFIG_307(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_307(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02998ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_307", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_307(a) cavm_bbxex_config_307_t
#define bustype_CAVM_BBXEX_CONFIG_307(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_307(a) "BBXEX_CONFIG_307"
#define busnum_CAVM_BBXEX_CONFIG_307(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_307(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_308
 *
 * BBX5 Configuration Register 308
 * Job Configuration
 */
union cavm_bbxex_config_308
{
    uint64_t u;
    struct cavm_bbxex_config_308_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_308_s cn; */
};
typedef union cavm_bbxex_config_308 cavm_bbxex_config_308_t;

static inline uint64_t CAVM_BBXEX_CONFIG_308(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_308(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_308", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_308(a) cavm_bbxex_config_308_t
#define bustype_CAVM_BBXEX_CONFIG_308(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_308(a) "BBXEX_CONFIG_308"
#define busnum_CAVM_BBXEX_CONFIG_308(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_308(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_309
 *
 * BBX5 Configuration Register 309
 * Job Configuration
 */
union cavm_bbxex_config_309
{
    uint64_t u;
    struct cavm_bbxex_config_309_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_309_s cn; */
};
typedef union cavm_bbxex_config_309 cavm_bbxex_config_309_t;

static inline uint64_t CAVM_BBXEX_CONFIG_309(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_309(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_309", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_309(a) cavm_bbxex_config_309_t
#define bustype_CAVM_BBXEX_CONFIG_309(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_309(a) "BBXEX_CONFIG_309"
#define busnum_CAVM_BBXEX_CONFIG_309(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_309(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_31
 *
 * BBX5 Configuration Register 31
 * Job Configuration
 */
union cavm_bbxex_config_31
{
    uint64_t u;
    struct cavm_bbxex_config_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_31_s cn; */
};
typedef union cavm_bbxex_config_31 cavm_bbxex_config_31_t;

static inline uint64_t CAVM_BBXEX_CONFIG_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c020f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_31", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_31(a) cavm_bbxex_config_31_t
#define bustype_CAVM_BBXEX_CONFIG_31(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_31(a) "BBXEX_CONFIG_31"
#define busnum_CAVM_BBXEX_CONFIG_31(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_31(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_310
 *
 * BBX5 Configuration Register 310
 * Job Configuration
 */
union cavm_bbxex_config_310
{
    uint64_t u;
    struct cavm_bbxex_config_310_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_310_s cn; */
};
typedef union cavm_bbxex_config_310 cavm_bbxex_config_310_t;

static inline uint64_t CAVM_BBXEX_CONFIG_310(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_310(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_310", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_310(a) cavm_bbxex_config_310_t
#define bustype_CAVM_BBXEX_CONFIG_310(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_310(a) "BBXEX_CONFIG_310"
#define busnum_CAVM_BBXEX_CONFIG_310(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_310(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_311
 *
 * BBX5 Configuration Register 311
 * Job Configuration
 */
union cavm_bbxex_config_311
{
    uint64_t u;
    struct cavm_bbxex_config_311_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_311_s cn; */
};
typedef union cavm_bbxex_config_311 cavm_bbxex_config_311_t;

static inline uint64_t CAVM_BBXEX_CONFIG_311(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_311(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_311", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_311(a) cavm_bbxex_config_311_t
#define bustype_CAVM_BBXEX_CONFIG_311(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_311(a) "BBXEX_CONFIG_311"
#define busnum_CAVM_BBXEX_CONFIG_311(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_311(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_312
 *
 * BBX5 Configuration Register 312
 * Job Configuration
 */
union cavm_bbxex_config_312
{
    uint64_t u;
    struct cavm_bbxex_config_312_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_312_s cn; */
};
typedef union cavm_bbxex_config_312 cavm_bbxex_config_312_t;

static inline uint64_t CAVM_BBXEX_CONFIG_312(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_312(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_312", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_312(a) cavm_bbxex_config_312_t
#define bustype_CAVM_BBXEX_CONFIG_312(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_312(a) "BBXEX_CONFIG_312"
#define busnum_CAVM_BBXEX_CONFIG_312(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_312(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_313
 *
 * BBX5 Configuration Register 313
 * Job Configuration
 */
union cavm_bbxex_config_313
{
    uint64_t u;
    struct cavm_bbxex_config_313_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_313_s cn; */
};
typedef union cavm_bbxex_config_313 cavm_bbxex_config_313_t;

static inline uint64_t CAVM_BBXEX_CONFIG_313(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_313(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_313", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_313(a) cavm_bbxex_config_313_t
#define bustype_CAVM_BBXEX_CONFIG_313(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_313(a) "BBXEX_CONFIG_313"
#define busnum_CAVM_BBXEX_CONFIG_313(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_313(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_314
 *
 * BBX5 Configuration Register 314
 * Job Configuration
 */
union cavm_bbxex_config_314
{
    uint64_t u;
    struct cavm_bbxex_config_314_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_314_s cn; */
};
typedef union cavm_bbxex_config_314 cavm_bbxex_config_314_t;

static inline uint64_t CAVM_BBXEX_CONFIG_314(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_314(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_314", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_314(a) cavm_bbxex_config_314_t
#define bustype_CAVM_BBXEX_CONFIG_314(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_314(a) "BBXEX_CONFIG_314"
#define busnum_CAVM_BBXEX_CONFIG_314(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_314(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_315
 *
 * BBX5 Configuration Register 315
 * Job Configuration
 */
union cavm_bbxex_config_315
{
    uint64_t u;
    struct cavm_bbxex_config_315_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_315_s cn; */
};
typedef union cavm_bbxex_config_315 cavm_bbxex_config_315_t;

static inline uint64_t CAVM_BBXEX_CONFIG_315(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_315(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_315", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_315(a) cavm_bbxex_config_315_t
#define bustype_CAVM_BBXEX_CONFIG_315(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_315(a) "BBXEX_CONFIG_315"
#define busnum_CAVM_BBXEX_CONFIG_315(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_315(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_316
 *
 * BBX5 Configuration Register 316
 * Job Configuration
 */
union cavm_bbxex_config_316
{
    uint64_t u;
    struct cavm_bbxex_config_316_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_316_s cn; */
};
typedef union cavm_bbxex_config_316 cavm_bbxex_config_316_t;

static inline uint64_t CAVM_BBXEX_CONFIG_316(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_316(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_316", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_316(a) cavm_bbxex_config_316_t
#define bustype_CAVM_BBXEX_CONFIG_316(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_316(a) "BBXEX_CONFIG_316"
#define busnum_CAVM_BBXEX_CONFIG_316(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_316(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_317
 *
 * BBX5 Configuration Register 317
 * Job Configuration
 */
union cavm_bbxex_config_317
{
    uint64_t u;
    struct cavm_bbxex_config_317_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_317_s cn; */
};
typedef union cavm_bbxex_config_317 cavm_bbxex_config_317_t;

static inline uint64_t CAVM_BBXEX_CONFIG_317(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_317(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_317", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_317(a) cavm_bbxex_config_317_t
#define bustype_CAVM_BBXEX_CONFIG_317(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_317(a) "BBXEX_CONFIG_317"
#define busnum_CAVM_BBXEX_CONFIG_317(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_317(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_318
 *
 * BBX5 Configuration Register 318
 * Job Configuration
 */
union cavm_bbxex_config_318
{
    uint64_t u;
    struct cavm_bbxex_config_318_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_318_s cn; */
};
typedef union cavm_bbxex_config_318 cavm_bbxex_config_318_t;

static inline uint64_t CAVM_BBXEX_CONFIG_318(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_318(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_318", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_318(a) cavm_bbxex_config_318_t
#define bustype_CAVM_BBXEX_CONFIG_318(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_318(a) "BBXEX_CONFIG_318"
#define busnum_CAVM_BBXEX_CONFIG_318(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_318(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_319
 *
 * BBX5 Configuration Register 319
 * Job Configuration
 */
union cavm_bbxex_config_319
{
    uint64_t u;
    struct cavm_bbxex_config_319_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_319_s cn; */
};
typedef union cavm_bbxex_config_319 cavm_bbxex_config_319_t;

static inline uint64_t CAVM_BBXEX_CONFIG_319(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_319(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c029f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_319", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_319(a) cavm_bbxex_config_319_t
#define bustype_CAVM_BBXEX_CONFIG_319(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_319(a) "BBXEX_CONFIG_319"
#define busnum_CAVM_BBXEX_CONFIG_319(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_319(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_32
 *
 * BBX5 Configuration Register 32
 * Job Configuration
 */
union cavm_bbxex_config_32
{
    uint64_t u;
    struct cavm_bbxex_config_32_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_32_s cn; */
};
typedef union cavm_bbxex_config_32 cavm_bbxex_config_32_t;

static inline uint64_t CAVM_BBXEX_CONFIG_32(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_32(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02100ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_32", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_32(a) cavm_bbxex_config_32_t
#define bustype_CAVM_BBXEX_CONFIG_32(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_32(a) "BBXEX_CONFIG_32"
#define busnum_CAVM_BBXEX_CONFIG_32(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_32(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_320
 *
 * BBX5 Configuration Register 320
 * Job Configuration
 */
union cavm_bbxex_config_320
{
    uint64_t u;
    struct cavm_bbxex_config_320_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_320_s cn; */
};
typedef union cavm_bbxex_config_320 cavm_bbxex_config_320_t;

static inline uint64_t CAVM_BBXEX_CONFIG_320(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_320(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a00ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_320", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_320(a) cavm_bbxex_config_320_t
#define bustype_CAVM_BBXEX_CONFIG_320(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_320(a) "BBXEX_CONFIG_320"
#define busnum_CAVM_BBXEX_CONFIG_320(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_320(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_321
 *
 * BBX5 Configuration Register 321
 * Job Configuration
 */
union cavm_bbxex_config_321
{
    uint64_t u;
    struct cavm_bbxex_config_321_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_321_s cn; */
};
typedef union cavm_bbxex_config_321 cavm_bbxex_config_321_t;

static inline uint64_t CAVM_BBXEX_CONFIG_321(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_321(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a08ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_321", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_321(a) cavm_bbxex_config_321_t
#define bustype_CAVM_BBXEX_CONFIG_321(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_321(a) "BBXEX_CONFIG_321"
#define busnum_CAVM_BBXEX_CONFIG_321(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_321(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_322
 *
 * BBX5 Configuration Register 322
 * Job Configuration
 */
union cavm_bbxex_config_322
{
    uint64_t u;
    struct cavm_bbxex_config_322_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_322_s cn; */
};
typedef union cavm_bbxex_config_322 cavm_bbxex_config_322_t;

static inline uint64_t CAVM_BBXEX_CONFIG_322(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_322(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a10ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_322", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_322(a) cavm_bbxex_config_322_t
#define bustype_CAVM_BBXEX_CONFIG_322(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_322(a) "BBXEX_CONFIG_322"
#define busnum_CAVM_BBXEX_CONFIG_322(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_322(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_323
 *
 * BBX5 Configuration Register 323
 * Job Configuration
 */
union cavm_bbxex_config_323
{
    uint64_t u;
    struct cavm_bbxex_config_323_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_323_s cn; */
};
typedef union cavm_bbxex_config_323 cavm_bbxex_config_323_t;

static inline uint64_t CAVM_BBXEX_CONFIG_323(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_323(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a18ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_323", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_323(a) cavm_bbxex_config_323_t
#define bustype_CAVM_BBXEX_CONFIG_323(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_323(a) "BBXEX_CONFIG_323"
#define busnum_CAVM_BBXEX_CONFIG_323(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_323(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_324
 *
 * BBX5 Configuration Register 324
 * Job Configuration
 */
union cavm_bbxex_config_324
{
    uint64_t u;
    struct cavm_bbxex_config_324_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_324_s cn; */
};
typedef union cavm_bbxex_config_324 cavm_bbxex_config_324_t;

static inline uint64_t CAVM_BBXEX_CONFIG_324(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_324(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a20ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_324", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_324(a) cavm_bbxex_config_324_t
#define bustype_CAVM_BBXEX_CONFIG_324(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_324(a) "BBXEX_CONFIG_324"
#define busnum_CAVM_BBXEX_CONFIG_324(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_324(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_325
 *
 * BBX5 Configuration Register 325
 * Job Configuration
 */
union cavm_bbxex_config_325
{
    uint64_t u;
    struct cavm_bbxex_config_325_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_325_s cn; */
};
typedef union cavm_bbxex_config_325 cavm_bbxex_config_325_t;

static inline uint64_t CAVM_BBXEX_CONFIG_325(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_325(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a28ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_325", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_325(a) cavm_bbxex_config_325_t
#define bustype_CAVM_BBXEX_CONFIG_325(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_325(a) "BBXEX_CONFIG_325"
#define busnum_CAVM_BBXEX_CONFIG_325(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_325(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_326
 *
 * BBX5 Configuration Register 326
 * Job Configuration
 */
union cavm_bbxex_config_326
{
    uint64_t u;
    struct cavm_bbxex_config_326_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_326_s cn; */
};
typedef union cavm_bbxex_config_326 cavm_bbxex_config_326_t;

static inline uint64_t CAVM_BBXEX_CONFIG_326(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_326(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a30ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_326", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_326(a) cavm_bbxex_config_326_t
#define bustype_CAVM_BBXEX_CONFIG_326(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_326(a) "BBXEX_CONFIG_326"
#define busnum_CAVM_BBXEX_CONFIG_326(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_326(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_327
 *
 * BBX5 Configuration Register 327
 * Job Configuration
 */
union cavm_bbxex_config_327
{
    uint64_t u;
    struct cavm_bbxex_config_327_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_327_s cn; */
};
typedef union cavm_bbxex_config_327 cavm_bbxex_config_327_t;

static inline uint64_t CAVM_BBXEX_CONFIG_327(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_327(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a38ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_327", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_327(a) cavm_bbxex_config_327_t
#define bustype_CAVM_BBXEX_CONFIG_327(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_327(a) "BBXEX_CONFIG_327"
#define busnum_CAVM_BBXEX_CONFIG_327(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_327(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_328
 *
 * BBX5 Configuration Register 328
 * Job Configuration
 */
union cavm_bbxex_config_328
{
    uint64_t u;
    struct cavm_bbxex_config_328_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_328_s cn; */
};
typedef union cavm_bbxex_config_328 cavm_bbxex_config_328_t;

static inline uint64_t CAVM_BBXEX_CONFIG_328(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_328(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a40ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_328", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_328(a) cavm_bbxex_config_328_t
#define bustype_CAVM_BBXEX_CONFIG_328(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_328(a) "BBXEX_CONFIG_328"
#define busnum_CAVM_BBXEX_CONFIG_328(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_328(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_329
 *
 * BBX5 Configuration Register 329
 * Job Configuration
 */
union cavm_bbxex_config_329
{
    uint64_t u;
    struct cavm_bbxex_config_329_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_329_s cn; */
};
typedef union cavm_bbxex_config_329 cavm_bbxex_config_329_t;

static inline uint64_t CAVM_BBXEX_CONFIG_329(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_329(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a48ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_329", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_329(a) cavm_bbxex_config_329_t
#define bustype_CAVM_BBXEX_CONFIG_329(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_329(a) "BBXEX_CONFIG_329"
#define busnum_CAVM_BBXEX_CONFIG_329(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_329(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_33
 *
 * BBX5 Configuration Register 33
 * Job Configuration
 */
union cavm_bbxex_config_33
{
    uint64_t u;
    struct cavm_bbxex_config_33_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_33_s cn; */
};
typedef union cavm_bbxex_config_33 cavm_bbxex_config_33_t;

static inline uint64_t CAVM_BBXEX_CONFIG_33(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_33(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02108ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_33", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_33(a) cavm_bbxex_config_33_t
#define bustype_CAVM_BBXEX_CONFIG_33(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_33(a) "BBXEX_CONFIG_33"
#define busnum_CAVM_BBXEX_CONFIG_33(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_33(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_330
 *
 * BBX5 Configuration Register 330
 * Job Configuration
 */
union cavm_bbxex_config_330
{
    uint64_t u;
    struct cavm_bbxex_config_330_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_330_s cn; */
};
typedef union cavm_bbxex_config_330 cavm_bbxex_config_330_t;

static inline uint64_t CAVM_BBXEX_CONFIG_330(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_330(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a50ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_330", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_330(a) cavm_bbxex_config_330_t
#define bustype_CAVM_BBXEX_CONFIG_330(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_330(a) "BBXEX_CONFIG_330"
#define busnum_CAVM_BBXEX_CONFIG_330(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_330(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_331
 *
 * BBX5 Configuration Register 331
 * Job Configuration
 */
union cavm_bbxex_config_331
{
    uint64_t u;
    struct cavm_bbxex_config_331_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_331_s cn; */
};
typedef union cavm_bbxex_config_331 cavm_bbxex_config_331_t;

static inline uint64_t CAVM_BBXEX_CONFIG_331(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_331(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a58ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_331", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_331(a) cavm_bbxex_config_331_t
#define bustype_CAVM_BBXEX_CONFIG_331(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_331(a) "BBXEX_CONFIG_331"
#define busnum_CAVM_BBXEX_CONFIG_331(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_331(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_332
 *
 * BBX5 Configuration Register 332
 * Job Configuration
 */
union cavm_bbxex_config_332
{
    uint64_t u;
    struct cavm_bbxex_config_332_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_332_s cn; */
};
typedef union cavm_bbxex_config_332 cavm_bbxex_config_332_t;

static inline uint64_t CAVM_BBXEX_CONFIG_332(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_332(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a60ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_332", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_332(a) cavm_bbxex_config_332_t
#define bustype_CAVM_BBXEX_CONFIG_332(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_332(a) "BBXEX_CONFIG_332"
#define busnum_CAVM_BBXEX_CONFIG_332(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_332(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_333
 *
 * BBX5 Configuration Register 333
 * Job Configuration
 */
union cavm_bbxex_config_333
{
    uint64_t u;
    struct cavm_bbxex_config_333_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_333_s cn; */
};
typedef union cavm_bbxex_config_333 cavm_bbxex_config_333_t;

static inline uint64_t CAVM_BBXEX_CONFIG_333(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_333(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a68ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_333", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_333(a) cavm_bbxex_config_333_t
#define bustype_CAVM_BBXEX_CONFIG_333(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_333(a) "BBXEX_CONFIG_333"
#define busnum_CAVM_BBXEX_CONFIG_333(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_333(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_334
 *
 * BBX5 Configuration Register 334
 * Job Configuration
 */
union cavm_bbxex_config_334
{
    uint64_t u;
    struct cavm_bbxex_config_334_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_334_s cn; */
};
typedef union cavm_bbxex_config_334 cavm_bbxex_config_334_t;

static inline uint64_t CAVM_BBXEX_CONFIG_334(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_334(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a70ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_334", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_334(a) cavm_bbxex_config_334_t
#define bustype_CAVM_BBXEX_CONFIG_334(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_334(a) "BBXEX_CONFIG_334"
#define busnum_CAVM_BBXEX_CONFIG_334(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_334(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_335
 *
 * BBX5 Configuration Register 335
 * Job Configuration
 */
union cavm_bbxex_config_335
{
    uint64_t u;
    struct cavm_bbxex_config_335_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_335_s cn; */
};
typedef union cavm_bbxex_config_335 cavm_bbxex_config_335_t;

static inline uint64_t CAVM_BBXEX_CONFIG_335(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_335(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a78ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_335", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_335(a) cavm_bbxex_config_335_t
#define bustype_CAVM_BBXEX_CONFIG_335(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_335(a) "BBXEX_CONFIG_335"
#define busnum_CAVM_BBXEX_CONFIG_335(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_335(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_336
 *
 * BBX5 Configuration Register 336
 * Job Configuration
 */
union cavm_bbxex_config_336
{
    uint64_t u;
    struct cavm_bbxex_config_336_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_336_s cn; */
};
typedef union cavm_bbxex_config_336 cavm_bbxex_config_336_t;

static inline uint64_t CAVM_BBXEX_CONFIG_336(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_336(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a80ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_336", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_336(a) cavm_bbxex_config_336_t
#define bustype_CAVM_BBXEX_CONFIG_336(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_336(a) "BBXEX_CONFIG_336"
#define busnum_CAVM_BBXEX_CONFIG_336(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_336(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_337
 *
 * BBX5 Configuration Register 337
 * Job Configuration
 */
union cavm_bbxex_config_337
{
    uint64_t u;
    struct cavm_bbxex_config_337_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_337_s cn; */
};
typedef union cavm_bbxex_config_337 cavm_bbxex_config_337_t;

static inline uint64_t CAVM_BBXEX_CONFIG_337(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_337(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a88ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_337", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_337(a) cavm_bbxex_config_337_t
#define bustype_CAVM_BBXEX_CONFIG_337(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_337(a) "BBXEX_CONFIG_337"
#define busnum_CAVM_BBXEX_CONFIG_337(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_337(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_338
 *
 * BBX5 Configuration Register 338
 * Job Configuration
 */
union cavm_bbxex_config_338
{
    uint64_t u;
    struct cavm_bbxex_config_338_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_338_s cn; */
};
typedef union cavm_bbxex_config_338 cavm_bbxex_config_338_t;

static inline uint64_t CAVM_BBXEX_CONFIG_338(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_338(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a90ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_338", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_338(a) cavm_bbxex_config_338_t
#define bustype_CAVM_BBXEX_CONFIG_338(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_338(a) "BBXEX_CONFIG_338"
#define busnum_CAVM_BBXEX_CONFIG_338(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_338(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_339
 *
 * BBX5 Configuration Register 339
 * Job Configuration
 */
union cavm_bbxex_config_339
{
    uint64_t u;
    struct cavm_bbxex_config_339_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_339_s cn; */
};
typedef union cavm_bbxex_config_339 cavm_bbxex_config_339_t;

static inline uint64_t CAVM_BBXEX_CONFIG_339(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_339(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02a98ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_339", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_339(a) cavm_bbxex_config_339_t
#define bustype_CAVM_BBXEX_CONFIG_339(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_339(a) "BBXEX_CONFIG_339"
#define busnum_CAVM_BBXEX_CONFIG_339(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_339(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_34
 *
 * BBX5 Configuration Register 34
 * Job Configuration
 */
union cavm_bbxex_config_34
{
    uint64_t u;
    struct cavm_bbxex_config_34_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_34_s cn; */
};
typedef union cavm_bbxex_config_34 cavm_bbxex_config_34_t;

static inline uint64_t CAVM_BBXEX_CONFIG_34(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_34(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02110ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_34", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_34(a) cavm_bbxex_config_34_t
#define bustype_CAVM_BBXEX_CONFIG_34(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_34(a) "BBXEX_CONFIG_34"
#define busnum_CAVM_BBXEX_CONFIG_34(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_34(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_340
 *
 * BBX5 Configuration Register 340
 * Job Configuration
 */
union cavm_bbxex_config_340
{
    uint64_t u;
    struct cavm_bbxex_config_340_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_340_s cn; */
};
typedef union cavm_bbxex_config_340 cavm_bbxex_config_340_t;

static inline uint64_t CAVM_BBXEX_CONFIG_340(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_340(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02aa0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_340", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_340(a) cavm_bbxex_config_340_t
#define bustype_CAVM_BBXEX_CONFIG_340(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_340(a) "BBXEX_CONFIG_340"
#define busnum_CAVM_BBXEX_CONFIG_340(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_340(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_341
 *
 * BBX5 Configuration Register 341
 * Job Configuration
 */
union cavm_bbxex_config_341
{
    uint64_t u;
    struct cavm_bbxex_config_341_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_341_s cn; */
};
typedef union cavm_bbxex_config_341 cavm_bbxex_config_341_t;

static inline uint64_t CAVM_BBXEX_CONFIG_341(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_341(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02aa8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_341", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_341(a) cavm_bbxex_config_341_t
#define bustype_CAVM_BBXEX_CONFIG_341(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_341(a) "BBXEX_CONFIG_341"
#define busnum_CAVM_BBXEX_CONFIG_341(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_341(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_342
 *
 * BBX5 Configuration Register 342
 * Job Configuration
 */
union cavm_bbxex_config_342
{
    uint64_t u;
    struct cavm_bbxex_config_342_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_342_s cn; */
};
typedef union cavm_bbxex_config_342 cavm_bbxex_config_342_t;

static inline uint64_t CAVM_BBXEX_CONFIG_342(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_342(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ab0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_342", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_342(a) cavm_bbxex_config_342_t
#define bustype_CAVM_BBXEX_CONFIG_342(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_342(a) "BBXEX_CONFIG_342"
#define busnum_CAVM_BBXEX_CONFIG_342(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_342(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_343
 *
 * BBX5 Configuration Register 343
 * Job Configuration
 */
union cavm_bbxex_config_343
{
    uint64_t u;
    struct cavm_bbxex_config_343_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_343_s cn; */
};
typedef union cavm_bbxex_config_343 cavm_bbxex_config_343_t;

static inline uint64_t CAVM_BBXEX_CONFIG_343(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_343(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ab8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_343", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_343(a) cavm_bbxex_config_343_t
#define bustype_CAVM_BBXEX_CONFIG_343(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_343(a) "BBXEX_CONFIG_343"
#define busnum_CAVM_BBXEX_CONFIG_343(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_343(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_344
 *
 * BBX5 Configuration Register 344
 * Job Configuration
 */
union cavm_bbxex_config_344
{
    uint64_t u;
    struct cavm_bbxex_config_344_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_344_s cn; */
};
typedef union cavm_bbxex_config_344 cavm_bbxex_config_344_t;

static inline uint64_t CAVM_BBXEX_CONFIG_344(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_344(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ac0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_344", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_344(a) cavm_bbxex_config_344_t
#define bustype_CAVM_BBXEX_CONFIG_344(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_344(a) "BBXEX_CONFIG_344"
#define busnum_CAVM_BBXEX_CONFIG_344(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_344(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_345
 *
 * BBX5 Configuration Register 345
 * Job Configuration
 */
union cavm_bbxex_config_345
{
    uint64_t u;
    struct cavm_bbxex_config_345_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_345_s cn; */
};
typedef union cavm_bbxex_config_345 cavm_bbxex_config_345_t;

static inline uint64_t CAVM_BBXEX_CONFIG_345(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_345(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ac8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_345", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_345(a) cavm_bbxex_config_345_t
#define bustype_CAVM_BBXEX_CONFIG_345(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_345(a) "BBXEX_CONFIG_345"
#define busnum_CAVM_BBXEX_CONFIG_345(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_345(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_346
 *
 * BBX5 Configuration Register 346
 * Job Configuration
 */
union cavm_bbxex_config_346
{
    uint64_t u;
    struct cavm_bbxex_config_346_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_346_s cn; */
};
typedef union cavm_bbxex_config_346 cavm_bbxex_config_346_t;

static inline uint64_t CAVM_BBXEX_CONFIG_346(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_346(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ad0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_346", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_346(a) cavm_bbxex_config_346_t
#define bustype_CAVM_BBXEX_CONFIG_346(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_346(a) "BBXEX_CONFIG_346"
#define busnum_CAVM_BBXEX_CONFIG_346(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_346(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_347
 *
 * BBX5 Configuration Register 347
 * Job Configuration
 */
union cavm_bbxex_config_347
{
    uint64_t u;
    struct cavm_bbxex_config_347_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_347_s cn; */
};
typedef union cavm_bbxex_config_347 cavm_bbxex_config_347_t;

static inline uint64_t CAVM_BBXEX_CONFIG_347(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_347(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ad8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_347", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_347(a) cavm_bbxex_config_347_t
#define bustype_CAVM_BBXEX_CONFIG_347(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_347(a) "BBXEX_CONFIG_347"
#define busnum_CAVM_BBXEX_CONFIG_347(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_347(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_348
 *
 * BBX5 Configuration Register 348
 * Job Configuration
 */
union cavm_bbxex_config_348
{
    uint64_t u;
    struct cavm_bbxex_config_348_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_348_s cn; */
};
typedef union cavm_bbxex_config_348 cavm_bbxex_config_348_t;

static inline uint64_t CAVM_BBXEX_CONFIG_348(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_348(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ae0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_348", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_348(a) cavm_bbxex_config_348_t
#define bustype_CAVM_BBXEX_CONFIG_348(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_348(a) "BBXEX_CONFIG_348"
#define busnum_CAVM_BBXEX_CONFIG_348(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_348(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_349
 *
 * BBX5 Configuration Register 349
 * Job Configuration
 */
union cavm_bbxex_config_349
{
    uint64_t u;
    struct cavm_bbxex_config_349_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_349_s cn; */
};
typedef union cavm_bbxex_config_349 cavm_bbxex_config_349_t;

static inline uint64_t CAVM_BBXEX_CONFIG_349(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_349(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ae8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_349", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_349(a) cavm_bbxex_config_349_t
#define bustype_CAVM_BBXEX_CONFIG_349(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_349(a) "BBXEX_CONFIG_349"
#define busnum_CAVM_BBXEX_CONFIG_349(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_349(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_35
 *
 * BBX5 Configuration Register 35
 * Job Configuration
 */
union cavm_bbxex_config_35
{
    uint64_t u;
    struct cavm_bbxex_config_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t config_f              : 33; /**< [ 32:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 33; /**< [ 32:  0](R/W) -- */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_35_s cn; */
};
typedef union cavm_bbxex_config_35 cavm_bbxex_config_35_t;

static inline uint64_t CAVM_BBXEX_CONFIG_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02118ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_35", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_35(a) cavm_bbxex_config_35_t
#define bustype_CAVM_BBXEX_CONFIG_35(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_35(a) "BBXEX_CONFIG_35"
#define busnum_CAVM_BBXEX_CONFIG_35(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_35(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_350
 *
 * BBX5 Configuration Register 350
 * Job Configuration
 */
union cavm_bbxex_config_350
{
    uint64_t u;
    struct cavm_bbxex_config_350_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_350_s cn; */
};
typedef union cavm_bbxex_config_350 cavm_bbxex_config_350_t;

static inline uint64_t CAVM_BBXEX_CONFIG_350(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_350(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02af0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_350", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_350(a) cavm_bbxex_config_350_t
#define bustype_CAVM_BBXEX_CONFIG_350(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_350(a) "BBXEX_CONFIG_350"
#define busnum_CAVM_BBXEX_CONFIG_350(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_350(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_351
 *
 * BBX5 Configuration Register 351
 * Job Configuration
 */
union cavm_bbxex_config_351
{
    uint64_t u;
    struct cavm_bbxex_config_351_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_351_s cn; */
};
typedef union cavm_bbxex_config_351 cavm_bbxex_config_351_t;

static inline uint64_t CAVM_BBXEX_CONFIG_351(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_351(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02af8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_351", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_351(a) cavm_bbxex_config_351_t
#define bustype_CAVM_BBXEX_CONFIG_351(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_351(a) "BBXEX_CONFIG_351"
#define busnum_CAVM_BBXEX_CONFIG_351(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_351(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_352
 *
 * BBX5 Configuration Register 352
 * Job Configuration
 */
union cavm_bbxex_config_352
{
    uint64_t u;
    struct cavm_bbxex_config_352_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_352_s cn; */
};
typedef union cavm_bbxex_config_352 cavm_bbxex_config_352_t;

static inline uint64_t CAVM_BBXEX_CONFIG_352(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_352(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b00ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_352", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_352(a) cavm_bbxex_config_352_t
#define bustype_CAVM_BBXEX_CONFIG_352(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_352(a) "BBXEX_CONFIG_352"
#define busnum_CAVM_BBXEX_CONFIG_352(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_352(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_353
 *
 * BBX5 Configuration Register 353
 * Job Configuration
 */
union cavm_bbxex_config_353
{
    uint64_t u;
    struct cavm_bbxex_config_353_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_353_s cn; */
};
typedef union cavm_bbxex_config_353 cavm_bbxex_config_353_t;

static inline uint64_t CAVM_BBXEX_CONFIG_353(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_353(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b08ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_353", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_353(a) cavm_bbxex_config_353_t
#define bustype_CAVM_BBXEX_CONFIG_353(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_353(a) "BBXEX_CONFIG_353"
#define busnum_CAVM_BBXEX_CONFIG_353(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_353(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_354
 *
 * BBX5 Configuration Register 354
 * Job Configuration
 */
union cavm_bbxex_config_354
{
    uint64_t u;
    struct cavm_bbxex_config_354_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_354_s cn; */
};
typedef union cavm_bbxex_config_354 cavm_bbxex_config_354_t;

static inline uint64_t CAVM_BBXEX_CONFIG_354(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_354(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b10ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_354", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_354(a) cavm_bbxex_config_354_t
#define bustype_CAVM_BBXEX_CONFIG_354(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_354(a) "BBXEX_CONFIG_354"
#define busnum_CAVM_BBXEX_CONFIG_354(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_354(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_355
 *
 * BBX5 Configuration Register 355
 * Job Configuration
 */
union cavm_bbxex_config_355
{
    uint64_t u;
    struct cavm_bbxex_config_355_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_355_s cn; */
};
typedef union cavm_bbxex_config_355 cavm_bbxex_config_355_t;

static inline uint64_t CAVM_BBXEX_CONFIG_355(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_355(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b18ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_355", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_355(a) cavm_bbxex_config_355_t
#define bustype_CAVM_BBXEX_CONFIG_355(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_355(a) "BBXEX_CONFIG_355"
#define busnum_CAVM_BBXEX_CONFIG_355(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_355(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_356
 *
 * BBX5 Configuration Register 356
 * Job Configuration
 */
union cavm_bbxex_config_356
{
    uint64_t u;
    struct cavm_bbxex_config_356_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_356_s cn; */
};
typedef union cavm_bbxex_config_356 cavm_bbxex_config_356_t;

static inline uint64_t CAVM_BBXEX_CONFIG_356(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_356(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b20ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_356", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_356(a) cavm_bbxex_config_356_t
#define bustype_CAVM_BBXEX_CONFIG_356(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_356(a) "BBXEX_CONFIG_356"
#define busnum_CAVM_BBXEX_CONFIG_356(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_356(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_357
 *
 * BBX5 Configuration Register 357
 * Job Configuration
 */
union cavm_bbxex_config_357
{
    uint64_t u;
    struct cavm_bbxex_config_357_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_357_s cn; */
};
typedef union cavm_bbxex_config_357 cavm_bbxex_config_357_t;

static inline uint64_t CAVM_BBXEX_CONFIG_357(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_357(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b28ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_357", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_357(a) cavm_bbxex_config_357_t
#define bustype_CAVM_BBXEX_CONFIG_357(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_357(a) "BBXEX_CONFIG_357"
#define busnum_CAVM_BBXEX_CONFIG_357(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_357(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_358
 *
 * BBX5 Configuration Register 358
 * Job Configuration
 */
union cavm_bbxex_config_358
{
    uint64_t u;
    struct cavm_bbxex_config_358_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_358_s cn; */
};
typedef union cavm_bbxex_config_358 cavm_bbxex_config_358_t;

static inline uint64_t CAVM_BBXEX_CONFIG_358(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_358(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b30ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_358", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_358(a) cavm_bbxex_config_358_t
#define bustype_CAVM_BBXEX_CONFIG_358(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_358(a) "BBXEX_CONFIG_358"
#define busnum_CAVM_BBXEX_CONFIG_358(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_358(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_359
 *
 * BBX5 Configuration Register 359
 * Job Configuration
 */
union cavm_bbxex_config_359
{
    uint64_t u;
    struct cavm_bbxex_config_359_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_359_s cn; */
};
typedef union cavm_bbxex_config_359 cavm_bbxex_config_359_t;

static inline uint64_t CAVM_BBXEX_CONFIG_359(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_359(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b38ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_359", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_359(a) cavm_bbxex_config_359_t
#define bustype_CAVM_BBXEX_CONFIG_359(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_359(a) "BBXEX_CONFIG_359"
#define busnum_CAVM_BBXEX_CONFIG_359(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_359(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_36
 *
 * BBX5 Configuration Register 36
 * Job Configuration
 */
union cavm_bbxex_config_36
{
    uint64_t u;
    struct cavm_bbxex_config_36_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_36_s cn; */
};
typedef union cavm_bbxex_config_36 cavm_bbxex_config_36_t;

static inline uint64_t CAVM_BBXEX_CONFIG_36(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_36(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02120ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_36", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_36(a) cavm_bbxex_config_36_t
#define bustype_CAVM_BBXEX_CONFIG_36(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_36(a) "BBXEX_CONFIG_36"
#define busnum_CAVM_BBXEX_CONFIG_36(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_36(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_360
 *
 * BBX5 Configuration Register 360
 * Job Configuration
 */
union cavm_bbxex_config_360
{
    uint64_t u;
    struct cavm_bbxex_config_360_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_360_s cn; */
};
typedef union cavm_bbxex_config_360 cavm_bbxex_config_360_t;

static inline uint64_t CAVM_BBXEX_CONFIG_360(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_360(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b40ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_360", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_360(a) cavm_bbxex_config_360_t
#define bustype_CAVM_BBXEX_CONFIG_360(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_360(a) "BBXEX_CONFIG_360"
#define busnum_CAVM_BBXEX_CONFIG_360(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_360(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_361
 *
 * BBX5 Configuration Register 361
 * Job Configuration
 */
union cavm_bbxex_config_361
{
    uint64_t u;
    struct cavm_bbxex_config_361_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_361_s cn; */
};
typedef union cavm_bbxex_config_361 cavm_bbxex_config_361_t;

static inline uint64_t CAVM_BBXEX_CONFIG_361(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_361(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b48ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_361", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_361(a) cavm_bbxex_config_361_t
#define bustype_CAVM_BBXEX_CONFIG_361(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_361(a) "BBXEX_CONFIG_361"
#define busnum_CAVM_BBXEX_CONFIG_361(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_361(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_362
 *
 * BBX5 Configuration Register 362
 * Job Configuration
 */
union cavm_bbxex_config_362
{
    uint64_t u;
    struct cavm_bbxex_config_362_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_362_s cn; */
};
typedef union cavm_bbxex_config_362 cavm_bbxex_config_362_t;

static inline uint64_t CAVM_BBXEX_CONFIG_362(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_362(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b50ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_362", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_362(a) cavm_bbxex_config_362_t
#define bustype_CAVM_BBXEX_CONFIG_362(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_362(a) "BBXEX_CONFIG_362"
#define busnum_CAVM_BBXEX_CONFIG_362(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_362(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_363
 *
 * BBX5 Configuration Register 363
 * Job Configuration
 */
union cavm_bbxex_config_363
{
    uint64_t u;
    struct cavm_bbxex_config_363_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_363_s cn; */
};
typedef union cavm_bbxex_config_363 cavm_bbxex_config_363_t;

static inline uint64_t CAVM_BBXEX_CONFIG_363(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_363(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b58ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_363", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_363(a) cavm_bbxex_config_363_t
#define bustype_CAVM_BBXEX_CONFIG_363(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_363(a) "BBXEX_CONFIG_363"
#define busnum_CAVM_BBXEX_CONFIG_363(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_363(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_364
 *
 * BBX5 Configuration Register 364
 * Job Configuration
 */
union cavm_bbxex_config_364
{
    uint64_t u;
    struct cavm_bbxex_config_364_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_364_s cn; */
};
typedef union cavm_bbxex_config_364 cavm_bbxex_config_364_t;

static inline uint64_t CAVM_BBXEX_CONFIG_364(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_364(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b60ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_364", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_364(a) cavm_bbxex_config_364_t
#define bustype_CAVM_BBXEX_CONFIG_364(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_364(a) "BBXEX_CONFIG_364"
#define busnum_CAVM_BBXEX_CONFIG_364(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_364(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_365
 *
 * BBX5 Configuration Register 365
 * Job Configuration
 */
union cavm_bbxex_config_365
{
    uint64_t u;
    struct cavm_bbxex_config_365_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_365_s cn; */
};
typedef union cavm_bbxex_config_365 cavm_bbxex_config_365_t;

static inline uint64_t CAVM_BBXEX_CONFIG_365(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_365(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b68ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_365", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_365(a) cavm_bbxex_config_365_t
#define bustype_CAVM_BBXEX_CONFIG_365(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_365(a) "BBXEX_CONFIG_365"
#define busnum_CAVM_BBXEX_CONFIG_365(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_365(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_366
 *
 * BBX5 Configuration Register 366
 * Job Configuration
 */
union cavm_bbxex_config_366
{
    uint64_t u;
    struct cavm_bbxex_config_366_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_366_s cn; */
};
typedef union cavm_bbxex_config_366 cavm_bbxex_config_366_t;

static inline uint64_t CAVM_BBXEX_CONFIG_366(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_366(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b70ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_366", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_366(a) cavm_bbxex_config_366_t
#define bustype_CAVM_BBXEX_CONFIG_366(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_366(a) "BBXEX_CONFIG_366"
#define busnum_CAVM_BBXEX_CONFIG_366(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_366(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_367
 *
 * BBX5 Configuration Register 367
 * Job Configuration
 */
union cavm_bbxex_config_367
{
    uint64_t u;
    struct cavm_bbxex_config_367_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_367_s cn; */
};
typedef union cavm_bbxex_config_367 cavm_bbxex_config_367_t;

static inline uint64_t CAVM_BBXEX_CONFIG_367(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_367(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b78ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_367", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_367(a) cavm_bbxex_config_367_t
#define bustype_CAVM_BBXEX_CONFIG_367(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_367(a) "BBXEX_CONFIG_367"
#define busnum_CAVM_BBXEX_CONFIG_367(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_367(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_368
 *
 * BBX5 Configuration Register 368
 * Job Configuration
 */
union cavm_bbxex_config_368
{
    uint64_t u;
    struct cavm_bbxex_config_368_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_368_s cn; */
};
typedef union cavm_bbxex_config_368 cavm_bbxex_config_368_t;

static inline uint64_t CAVM_BBXEX_CONFIG_368(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_368(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b80ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_368", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_368(a) cavm_bbxex_config_368_t
#define bustype_CAVM_BBXEX_CONFIG_368(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_368(a) "BBXEX_CONFIG_368"
#define busnum_CAVM_BBXEX_CONFIG_368(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_368(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_369
 *
 * BBX5 Configuration Register 369
 * Job Configuration
 */
union cavm_bbxex_config_369
{
    uint64_t u;
    struct cavm_bbxex_config_369_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_369_s cn; */
};
typedef union cavm_bbxex_config_369 cavm_bbxex_config_369_t;

static inline uint64_t CAVM_BBXEX_CONFIG_369(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_369(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b88ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_369", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_369(a) cavm_bbxex_config_369_t
#define bustype_CAVM_BBXEX_CONFIG_369(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_369(a) "BBXEX_CONFIG_369"
#define busnum_CAVM_BBXEX_CONFIG_369(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_369(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_37
 *
 * BBX5 Configuration Register 37
 * Job Configuration
 */
union cavm_bbxex_config_37
{
    uint64_t u;
    struct cavm_bbxex_config_37_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_37_s cn; */
};
typedef union cavm_bbxex_config_37 cavm_bbxex_config_37_t;

static inline uint64_t CAVM_BBXEX_CONFIG_37(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_37(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02128ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_37", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_37(a) cavm_bbxex_config_37_t
#define bustype_CAVM_BBXEX_CONFIG_37(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_37(a) "BBXEX_CONFIG_37"
#define busnum_CAVM_BBXEX_CONFIG_37(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_37(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_370
 *
 * BBX5 Configuration Register 370
 * Job Configuration
 */
union cavm_bbxex_config_370
{
    uint64_t u;
    struct cavm_bbxex_config_370_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_370_s cn; */
};
typedef union cavm_bbxex_config_370 cavm_bbxex_config_370_t;

static inline uint64_t CAVM_BBXEX_CONFIG_370(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_370(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b90ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_370", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_370(a) cavm_bbxex_config_370_t
#define bustype_CAVM_BBXEX_CONFIG_370(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_370(a) "BBXEX_CONFIG_370"
#define busnum_CAVM_BBXEX_CONFIG_370(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_370(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_371
 *
 * BBX5 Configuration Register 371
 * Job Configuration
 */
union cavm_bbxex_config_371
{
    uint64_t u;
    struct cavm_bbxex_config_371_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_371_s cn; */
};
typedef union cavm_bbxex_config_371 cavm_bbxex_config_371_t;

static inline uint64_t CAVM_BBXEX_CONFIG_371(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_371(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02b98ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_371", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_371(a) cavm_bbxex_config_371_t
#define bustype_CAVM_BBXEX_CONFIG_371(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_371(a) "BBXEX_CONFIG_371"
#define busnum_CAVM_BBXEX_CONFIG_371(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_371(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_372
 *
 * BBX5 Configuration Register 372
 * Job Configuration
 */
union cavm_bbxex_config_372
{
    uint64_t u;
    struct cavm_bbxex_config_372_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_372_s cn; */
};
typedef union cavm_bbxex_config_372 cavm_bbxex_config_372_t;

static inline uint64_t CAVM_BBXEX_CONFIG_372(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_372(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ba0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_372", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_372(a) cavm_bbxex_config_372_t
#define bustype_CAVM_BBXEX_CONFIG_372(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_372(a) "BBXEX_CONFIG_372"
#define busnum_CAVM_BBXEX_CONFIG_372(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_372(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_373
 *
 * BBX5 Configuration Register 373
 * Job Configuration
 */
union cavm_bbxex_config_373
{
    uint64_t u;
    struct cavm_bbxex_config_373_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_373_s cn; */
};
typedef union cavm_bbxex_config_373 cavm_bbxex_config_373_t;

static inline uint64_t CAVM_BBXEX_CONFIG_373(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_373(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ba8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_373", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_373(a) cavm_bbxex_config_373_t
#define bustype_CAVM_BBXEX_CONFIG_373(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_373(a) "BBXEX_CONFIG_373"
#define busnum_CAVM_BBXEX_CONFIG_373(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_373(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_374
 *
 * BBX5 Configuration Register 374
 * Job Configuration
 */
union cavm_bbxex_config_374
{
    uint64_t u;
    struct cavm_bbxex_config_374_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_374_s cn; */
};
typedef union cavm_bbxex_config_374 cavm_bbxex_config_374_t;

static inline uint64_t CAVM_BBXEX_CONFIG_374(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_374(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02bb0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_374", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_374(a) cavm_bbxex_config_374_t
#define bustype_CAVM_BBXEX_CONFIG_374(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_374(a) "BBXEX_CONFIG_374"
#define busnum_CAVM_BBXEX_CONFIG_374(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_374(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_375
 *
 * BBX5 Configuration Register 375
 * Job Configuration
 */
union cavm_bbxex_config_375
{
    uint64_t u;
    struct cavm_bbxex_config_375_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_375_s cn; */
};
typedef union cavm_bbxex_config_375 cavm_bbxex_config_375_t;

static inline uint64_t CAVM_BBXEX_CONFIG_375(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_375(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02bb8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_375", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_375(a) cavm_bbxex_config_375_t
#define bustype_CAVM_BBXEX_CONFIG_375(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_375(a) "BBXEX_CONFIG_375"
#define busnum_CAVM_BBXEX_CONFIG_375(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_375(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_376
 *
 * BBX5 Configuration Register 376
 * Job Configuration
 */
union cavm_bbxex_config_376
{
    uint64_t u;
    struct cavm_bbxex_config_376_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_376_s cn; */
};
typedef union cavm_bbxex_config_376 cavm_bbxex_config_376_t;

static inline uint64_t CAVM_BBXEX_CONFIG_376(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_376(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02bc0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_376", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_376(a) cavm_bbxex_config_376_t
#define bustype_CAVM_BBXEX_CONFIG_376(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_376(a) "BBXEX_CONFIG_376"
#define busnum_CAVM_BBXEX_CONFIG_376(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_376(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_377
 *
 * BBX5 Configuration Register 377
 * Job Configuration
 */
union cavm_bbxex_config_377
{
    uint64_t u;
    struct cavm_bbxex_config_377_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_377_s cn; */
};
typedef union cavm_bbxex_config_377 cavm_bbxex_config_377_t;

static inline uint64_t CAVM_BBXEX_CONFIG_377(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_377(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02bc8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_377", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_377(a) cavm_bbxex_config_377_t
#define bustype_CAVM_BBXEX_CONFIG_377(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_377(a) "BBXEX_CONFIG_377"
#define busnum_CAVM_BBXEX_CONFIG_377(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_377(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_378
 *
 * BBX5 Configuration Register 378
 * Job Configuration
 */
union cavm_bbxex_config_378
{
    uint64_t u;
    struct cavm_bbxex_config_378_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_378_s cn; */
};
typedef union cavm_bbxex_config_378 cavm_bbxex_config_378_t;

static inline uint64_t CAVM_BBXEX_CONFIG_378(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_378(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02bd0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_378", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_378(a) cavm_bbxex_config_378_t
#define bustype_CAVM_BBXEX_CONFIG_378(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_378(a) "BBXEX_CONFIG_378"
#define busnum_CAVM_BBXEX_CONFIG_378(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_378(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_379
 *
 * BBX5 Configuration Register 379
 * Job Configuration
 */
union cavm_bbxex_config_379
{
    uint64_t u;
    struct cavm_bbxex_config_379_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_379_s cn; */
};
typedef union cavm_bbxex_config_379 cavm_bbxex_config_379_t;

static inline uint64_t CAVM_BBXEX_CONFIG_379(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_379(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02bd8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_379", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_379(a) cavm_bbxex_config_379_t
#define bustype_CAVM_BBXEX_CONFIG_379(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_379(a) "BBXEX_CONFIG_379"
#define busnum_CAVM_BBXEX_CONFIG_379(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_379(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_38
 *
 * BBX5 Configuration Register 38
 * Job Configuration
 */
union cavm_bbxex_config_38
{
    uint64_t u;
    struct cavm_bbxex_config_38_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_38_s cn; */
};
typedef union cavm_bbxex_config_38 cavm_bbxex_config_38_t;

static inline uint64_t CAVM_BBXEX_CONFIG_38(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_38(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02130ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_38", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_38(a) cavm_bbxex_config_38_t
#define bustype_CAVM_BBXEX_CONFIG_38(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_38(a) "BBXEX_CONFIG_38"
#define busnum_CAVM_BBXEX_CONFIG_38(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_38(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_380
 *
 * BBX5 Configuration Register 380
 * Job Configuration
 */
union cavm_bbxex_config_380
{
    uint64_t u;
    struct cavm_bbxex_config_380_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_380_s cn; */
};
typedef union cavm_bbxex_config_380 cavm_bbxex_config_380_t;

static inline uint64_t CAVM_BBXEX_CONFIG_380(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_380(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02be0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_380", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_380(a) cavm_bbxex_config_380_t
#define bustype_CAVM_BBXEX_CONFIG_380(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_380(a) "BBXEX_CONFIG_380"
#define busnum_CAVM_BBXEX_CONFIG_380(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_380(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_381
 *
 * BBX5 Configuration Register 381
 * Job Configuration
 */
union cavm_bbxex_config_381
{
    uint64_t u;
    struct cavm_bbxex_config_381_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_381_s cn; */
};
typedef union cavm_bbxex_config_381 cavm_bbxex_config_381_t;

static inline uint64_t CAVM_BBXEX_CONFIG_381(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_381(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02be8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_381", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_381(a) cavm_bbxex_config_381_t
#define bustype_CAVM_BBXEX_CONFIG_381(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_381(a) "BBXEX_CONFIG_381"
#define busnum_CAVM_BBXEX_CONFIG_381(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_381(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_382
 *
 * BBX5 Configuration Register 382
 * Job Configuration
 */
union cavm_bbxex_config_382
{
    uint64_t u;
    struct cavm_bbxex_config_382_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_382_s cn; */
};
typedef union cavm_bbxex_config_382 cavm_bbxex_config_382_t;

static inline uint64_t CAVM_BBXEX_CONFIG_382(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_382(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02bf0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_382", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_382(a) cavm_bbxex_config_382_t
#define bustype_CAVM_BBXEX_CONFIG_382(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_382(a) "BBXEX_CONFIG_382"
#define busnum_CAVM_BBXEX_CONFIG_382(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_382(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_383
 *
 * BBX5 Configuration Register 383
 * Job Configuration
 */
union cavm_bbxex_config_383
{
    uint64_t u;
    struct cavm_bbxex_config_383_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_383_s cn; */
};
typedef union cavm_bbxex_config_383 cavm_bbxex_config_383_t;

static inline uint64_t CAVM_BBXEX_CONFIG_383(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_383(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02bf8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_383", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_383(a) cavm_bbxex_config_383_t
#define bustype_CAVM_BBXEX_CONFIG_383(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_383(a) "BBXEX_CONFIG_383"
#define busnum_CAVM_BBXEX_CONFIG_383(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_383(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_384
 *
 * BBX5 Configuration Register 384
 * Job Configuration
 */
union cavm_bbxex_config_384
{
    uint64_t u;
    struct cavm_bbxex_config_384_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_384_s cn; */
};
typedef union cavm_bbxex_config_384 cavm_bbxex_config_384_t;

static inline uint64_t CAVM_BBXEX_CONFIG_384(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_384(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c00ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_384", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_384(a) cavm_bbxex_config_384_t
#define bustype_CAVM_BBXEX_CONFIG_384(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_384(a) "BBXEX_CONFIG_384"
#define busnum_CAVM_BBXEX_CONFIG_384(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_384(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_385
 *
 * BBX5 Configuration Register 385
 * Job Configuration
 */
union cavm_bbxex_config_385
{
    uint64_t u;
    struct cavm_bbxex_config_385_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_385_s cn; */
};
typedef union cavm_bbxex_config_385 cavm_bbxex_config_385_t;

static inline uint64_t CAVM_BBXEX_CONFIG_385(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_385(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c08ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_385", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_385(a) cavm_bbxex_config_385_t
#define bustype_CAVM_BBXEX_CONFIG_385(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_385(a) "BBXEX_CONFIG_385"
#define busnum_CAVM_BBXEX_CONFIG_385(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_385(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_386
 *
 * BBX5 Configuration Register 386
 * Job Configuration
 */
union cavm_bbxex_config_386
{
    uint64_t u;
    struct cavm_bbxex_config_386_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_386_s cn; */
};
typedef union cavm_bbxex_config_386 cavm_bbxex_config_386_t;

static inline uint64_t CAVM_BBXEX_CONFIG_386(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_386(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c10ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_386", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_386(a) cavm_bbxex_config_386_t
#define bustype_CAVM_BBXEX_CONFIG_386(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_386(a) "BBXEX_CONFIG_386"
#define busnum_CAVM_BBXEX_CONFIG_386(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_386(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_387
 *
 * BBX5 Configuration Register 387
 * Job Configuration
 */
union cavm_bbxex_config_387
{
    uint64_t u;
    struct cavm_bbxex_config_387_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_387_s cn; */
};
typedef union cavm_bbxex_config_387 cavm_bbxex_config_387_t;

static inline uint64_t CAVM_BBXEX_CONFIG_387(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_387(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c18ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_387", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_387(a) cavm_bbxex_config_387_t
#define bustype_CAVM_BBXEX_CONFIG_387(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_387(a) "BBXEX_CONFIG_387"
#define busnum_CAVM_BBXEX_CONFIG_387(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_387(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_388
 *
 * BBX5 Configuration Register 388
 * Job Configuration
 */
union cavm_bbxex_config_388
{
    uint64_t u;
    struct cavm_bbxex_config_388_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_388_s cn; */
};
typedef union cavm_bbxex_config_388 cavm_bbxex_config_388_t;

static inline uint64_t CAVM_BBXEX_CONFIG_388(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_388(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c20ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_388", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_388(a) cavm_bbxex_config_388_t
#define bustype_CAVM_BBXEX_CONFIG_388(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_388(a) "BBXEX_CONFIG_388"
#define busnum_CAVM_BBXEX_CONFIG_388(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_388(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_389
 *
 * BBX5 Configuration Register 389
 * Job Configuration
 */
union cavm_bbxex_config_389
{
    uint64_t u;
    struct cavm_bbxex_config_389_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_389_s cn; */
};
typedef union cavm_bbxex_config_389 cavm_bbxex_config_389_t;

static inline uint64_t CAVM_BBXEX_CONFIG_389(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_389(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c28ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_389", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_389(a) cavm_bbxex_config_389_t
#define bustype_CAVM_BBXEX_CONFIG_389(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_389(a) "BBXEX_CONFIG_389"
#define busnum_CAVM_BBXEX_CONFIG_389(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_389(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_39
 *
 * BBX5 Configuration Register 39
 * Job Configuration
 */
union cavm_bbxex_config_39
{
    uint64_t u;
    struct cavm_bbxex_config_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_39_s cn; */
};
typedef union cavm_bbxex_config_39 cavm_bbxex_config_39_t;

static inline uint64_t CAVM_BBXEX_CONFIG_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02138ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_39", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_39(a) cavm_bbxex_config_39_t
#define bustype_CAVM_BBXEX_CONFIG_39(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_39(a) "BBXEX_CONFIG_39"
#define busnum_CAVM_BBXEX_CONFIG_39(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_39(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_390
 *
 * BBX5 Configuration Register 390
 * Job Configuration
 */
union cavm_bbxex_config_390
{
    uint64_t u;
    struct cavm_bbxex_config_390_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_390_s cn; */
};
typedef union cavm_bbxex_config_390 cavm_bbxex_config_390_t;

static inline uint64_t CAVM_BBXEX_CONFIG_390(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_390(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c30ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_390", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_390(a) cavm_bbxex_config_390_t
#define bustype_CAVM_BBXEX_CONFIG_390(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_390(a) "BBXEX_CONFIG_390"
#define busnum_CAVM_BBXEX_CONFIG_390(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_390(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_391
 *
 * BBX5 Configuration Register 391
 * Job Configuration
 */
union cavm_bbxex_config_391
{
    uint64_t u;
    struct cavm_bbxex_config_391_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_391_s cn; */
};
typedef union cavm_bbxex_config_391 cavm_bbxex_config_391_t;

static inline uint64_t CAVM_BBXEX_CONFIG_391(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_391(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c38ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_391", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_391(a) cavm_bbxex_config_391_t
#define bustype_CAVM_BBXEX_CONFIG_391(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_391(a) "BBXEX_CONFIG_391"
#define busnum_CAVM_BBXEX_CONFIG_391(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_391(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_392
 *
 * BBX5 Configuration Register 392
 * Job Configuration
 */
union cavm_bbxex_config_392
{
    uint64_t u;
    struct cavm_bbxex_config_392_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_392_s cn; */
};
typedef union cavm_bbxex_config_392 cavm_bbxex_config_392_t;

static inline uint64_t CAVM_BBXEX_CONFIG_392(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_392(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c40ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_392", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_392(a) cavm_bbxex_config_392_t
#define bustype_CAVM_BBXEX_CONFIG_392(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_392(a) "BBXEX_CONFIG_392"
#define busnum_CAVM_BBXEX_CONFIG_392(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_392(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_393
 *
 * BBX5 Configuration Register 393
 * Job Configuration
 */
union cavm_bbxex_config_393
{
    uint64_t u;
    struct cavm_bbxex_config_393_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_393_s cn; */
};
typedef union cavm_bbxex_config_393 cavm_bbxex_config_393_t;

static inline uint64_t CAVM_BBXEX_CONFIG_393(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_393(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c48ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_393", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_393(a) cavm_bbxex_config_393_t
#define bustype_CAVM_BBXEX_CONFIG_393(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_393(a) "BBXEX_CONFIG_393"
#define busnum_CAVM_BBXEX_CONFIG_393(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_393(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_394
 *
 * BBX5 Configuration Register 394
 * Job Configuration
 */
union cavm_bbxex_config_394
{
    uint64_t u;
    struct cavm_bbxex_config_394_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_394_s cn; */
};
typedef union cavm_bbxex_config_394 cavm_bbxex_config_394_t;

static inline uint64_t CAVM_BBXEX_CONFIG_394(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_394(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c50ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_394", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_394(a) cavm_bbxex_config_394_t
#define bustype_CAVM_BBXEX_CONFIG_394(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_394(a) "BBXEX_CONFIG_394"
#define busnum_CAVM_BBXEX_CONFIG_394(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_394(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_395
 *
 * BBX5 Configuration Register 395
 * Job Configuration
 */
union cavm_bbxex_config_395
{
    uint64_t u;
    struct cavm_bbxex_config_395_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_395_s cn; */
};
typedef union cavm_bbxex_config_395 cavm_bbxex_config_395_t;

static inline uint64_t CAVM_BBXEX_CONFIG_395(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_395(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c58ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_395", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_395(a) cavm_bbxex_config_395_t
#define bustype_CAVM_BBXEX_CONFIG_395(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_395(a) "BBXEX_CONFIG_395"
#define busnum_CAVM_BBXEX_CONFIG_395(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_395(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_396
 *
 * BBX5 Configuration Register 396
 * Job Configuration
 */
union cavm_bbxex_config_396
{
    uint64_t u;
    struct cavm_bbxex_config_396_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_396_s cn; */
};
typedef union cavm_bbxex_config_396 cavm_bbxex_config_396_t;

static inline uint64_t CAVM_BBXEX_CONFIG_396(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_396(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c60ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_396", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_396(a) cavm_bbxex_config_396_t
#define bustype_CAVM_BBXEX_CONFIG_396(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_396(a) "BBXEX_CONFIG_396"
#define busnum_CAVM_BBXEX_CONFIG_396(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_396(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_397
 *
 * BBX5 Configuration Register 397
 * Job Configuration
 */
union cavm_bbxex_config_397
{
    uint64_t u;
    struct cavm_bbxex_config_397_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_397_s cn; */
};
typedef union cavm_bbxex_config_397 cavm_bbxex_config_397_t;

static inline uint64_t CAVM_BBXEX_CONFIG_397(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_397(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c68ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_397", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_397(a) cavm_bbxex_config_397_t
#define bustype_CAVM_BBXEX_CONFIG_397(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_397(a) "BBXEX_CONFIG_397"
#define busnum_CAVM_BBXEX_CONFIG_397(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_397(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_398
 *
 * BBX5 Configuration Register 398
 * Job Configuration
 */
union cavm_bbxex_config_398
{
    uint64_t u;
    struct cavm_bbxex_config_398_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_398_s cn; */
};
typedef union cavm_bbxex_config_398 cavm_bbxex_config_398_t;

static inline uint64_t CAVM_BBXEX_CONFIG_398(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_398(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c70ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_398", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_398(a) cavm_bbxex_config_398_t
#define bustype_CAVM_BBXEX_CONFIG_398(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_398(a) "BBXEX_CONFIG_398"
#define busnum_CAVM_BBXEX_CONFIG_398(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_398(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_399
 *
 * BBX5 Configuration Register 399
 * Job Configuration
 */
union cavm_bbxex_config_399
{
    uint64_t u;
    struct cavm_bbxex_config_399_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_399_s cn; */
};
typedef union cavm_bbxex_config_399 cavm_bbxex_config_399_t;

static inline uint64_t CAVM_BBXEX_CONFIG_399(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_399(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c78ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_399", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_399(a) cavm_bbxex_config_399_t
#define bustype_CAVM_BBXEX_CONFIG_399(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_399(a) "BBXEX_CONFIG_399"
#define busnum_CAVM_BBXEX_CONFIG_399(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_399(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_4
 *
 * BBX5 Configuration Register 4
 * Job Configuration
 */
union cavm_bbxex_config_4
{
    uint64_t u;
    struct cavm_bbxex_config_4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_4_s cn; */
};
typedef union cavm_bbxex_config_4 cavm_bbxex_config_4_t;

static inline uint64_t CAVM_BBXEX_CONFIG_4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_4(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02020ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_4", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_4(a) cavm_bbxex_config_4_t
#define bustype_CAVM_BBXEX_CONFIG_4(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_4(a) "BBXEX_CONFIG_4"
#define busnum_CAVM_BBXEX_CONFIG_4(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_4(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_40
 *
 * BBX5 Configuration Register 40
 * Job Configuration
 */
union cavm_bbxex_config_40
{
    uint64_t u;
    struct cavm_bbxex_config_40_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_40_s cn; */
};
typedef union cavm_bbxex_config_40 cavm_bbxex_config_40_t;

static inline uint64_t CAVM_BBXEX_CONFIG_40(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_40(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02140ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_40", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_40(a) cavm_bbxex_config_40_t
#define bustype_CAVM_BBXEX_CONFIG_40(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_40(a) "BBXEX_CONFIG_40"
#define busnum_CAVM_BBXEX_CONFIG_40(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_40(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_400
 *
 * BBX5 Configuration Register 400
 * Job Configuration
 */
union cavm_bbxex_config_400
{
    uint64_t u;
    struct cavm_bbxex_config_400_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_400_s cn; */
};
typedef union cavm_bbxex_config_400 cavm_bbxex_config_400_t;

static inline uint64_t CAVM_BBXEX_CONFIG_400(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_400(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c80ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_400", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_400(a) cavm_bbxex_config_400_t
#define bustype_CAVM_BBXEX_CONFIG_400(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_400(a) "BBXEX_CONFIG_400"
#define busnum_CAVM_BBXEX_CONFIG_400(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_400(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_401
 *
 * BBX5 Configuration Register 401
 * Job Configuration
 */
union cavm_bbxex_config_401
{
    uint64_t u;
    struct cavm_bbxex_config_401_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_401_s cn; */
};
typedef union cavm_bbxex_config_401 cavm_bbxex_config_401_t;

static inline uint64_t CAVM_BBXEX_CONFIG_401(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_401(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c88ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_401", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_401(a) cavm_bbxex_config_401_t
#define bustype_CAVM_BBXEX_CONFIG_401(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_401(a) "BBXEX_CONFIG_401"
#define busnum_CAVM_BBXEX_CONFIG_401(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_401(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_402
 *
 * BBX5 Configuration Register 402
 * Job Configuration
 */
union cavm_bbxex_config_402
{
    uint64_t u;
    struct cavm_bbxex_config_402_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_402_s cn; */
};
typedef union cavm_bbxex_config_402 cavm_bbxex_config_402_t;

static inline uint64_t CAVM_BBXEX_CONFIG_402(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_402(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c90ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_402", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_402(a) cavm_bbxex_config_402_t
#define bustype_CAVM_BBXEX_CONFIG_402(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_402(a) "BBXEX_CONFIG_402"
#define busnum_CAVM_BBXEX_CONFIG_402(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_402(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_403
 *
 * BBX5 Configuration Register 403
 * Job Configuration
 */
union cavm_bbxex_config_403
{
    uint64_t u;
    struct cavm_bbxex_config_403_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_403_s cn; */
};
typedef union cavm_bbxex_config_403 cavm_bbxex_config_403_t;

static inline uint64_t CAVM_BBXEX_CONFIG_403(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_403(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02c98ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_403", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_403(a) cavm_bbxex_config_403_t
#define bustype_CAVM_BBXEX_CONFIG_403(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_403(a) "BBXEX_CONFIG_403"
#define busnum_CAVM_BBXEX_CONFIG_403(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_403(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_404
 *
 * BBX5 Configuration Register 404
 * Job Configuration
 */
union cavm_bbxex_config_404
{
    uint64_t u;
    struct cavm_bbxex_config_404_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_404_s cn; */
};
typedef union cavm_bbxex_config_404 cavm_bbxex_config_404_t;

static inline uint64_t CAVM_BBXEX_CONFIG_404(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_404(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ca0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_404", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_404(a) cavm_bbxex_config_404_t
#define bustype_CAVM_BBXEX_CONFIG_404(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_404(a) "BBXEX_CONFIG_404"
#define busnum_CAVM_BBXEX_CONFIG_404(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_404(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_405
 *
 * BBX5 Configuration Register 405
 * Job Configuration
 */
union cavm_bbxex_config_405
{
    uint64_t u;
    struct cavm_bbxex_config_405_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_405_s cn; */
};
typedef union cavm_bbxex_config_405 cavm_bbxex_config_405_t;

static inline uint64_t CAVM_BBXEX_CONFIG_405(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_405(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ca8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_405", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_405(a) cavm_bbxex_config_405_t
#define bustype_CAVM_BBXEX_CONFIG_405(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_405(a) "BBXEX_CONFIG_405"
#define busnum_CAVM_BBXEX_CONFIG_405(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_405(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_406
 *
 * BBX5 Configuration Register 406
 * Job Configuration
 */
union cavm_bbxex_config_406
{
    uint64_t u;
    struct cavm_bbxex_config_406_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_406_s cn; */
};
typedef union cavm_bbxex_config_406 cavm_bbxex_config_406_t;

static inline uint64_t CAVM_BBXEX_CONFIG_406(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_406(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02cb0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_406", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_406(a) cavm_bbxex_config_406_t
#define bustype_CAVM_BBXEX_CONFIG_406(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_406(a) "BBXEX_CONFIG_406"
#define busnum_CAVM_BBXEX_CONFIG_406(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_406(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_407
 *
 * BBX5 Configuration Register 407
 * Job Configuration
 */
union cavm_bbxex_config_407
{
    uint64_t u;
    struct cavm_bbxex_config_407_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_407_s cn; */
};
typedef union cavm_bbxex_config_407 cavm_bbxex_config_407_t;

static inline uint64_t CAVM_BBXEX_CONFIG_407(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_407(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02cb8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_407", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_407(a) cavm_bbxex_config_407_t
#define bustype_CAVM_BBXEX_CONFIG_407(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_407(a) "BBXEX_CONFIG_407"
#define busnum_CAVM_BBXEX_CONFIG_407(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_407(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_408
 *
 * BBX5 Configuration Register 408
 * Job Configuration
 */
union cavm_bbxex_config_408
{
    uint64_t u;
    struct cavm_bbxex_config_408_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_408_s cn; */
};
typedef union cavm_bbxex_config_408 cavm_bbxex_config_408_t;

static inline uint64_t CAVM_BBXEX_CONFIG_408(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_408(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02cc0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_408", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_408(a) cavm_bbxex_config_408_t
#define bustype_CAVM_BBXEX_CONFIG_408(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_408(a) "BBXEX_CONFIG_408"
#define busnum_CAVM_BBXEX_CONFIG_408(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_408(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_409
 *
 * BBX5 Configuration Register 409
 * Job Configuration
 */
union cavm_bbxex_config_409
{
    uint64_t u;
    struct cavm_bbxex_config_409_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_409_s cn; */
};
typedef union cavm_bbxex_config_409 cavm_bbxex_config_409_t;

static inline uint64_t CAVM_BBXEX_CONFIG_409(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_409(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02cc8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_409", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_409(a) cavm_bbxex_config_409_t
#define bustype_CAVM_BBXEX_CONFIG_409(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_409(a) "BBXEX_CONFIG_409"
#define busnum_CAVM_BBXEX_CONFIG_409(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_409(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_41
 *
 * BBX5 Configuration Register 41
 * Job Configuration
 */
union cavm_bbxex_config_41
{
    uint64_t u;
    struct cavm_bbxex_config_41_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_41_s cn; */
};
typedef union cavm_bbxex_config_41 cavm_bbxex_config_41_t;

static inline uint64_t CAVM_BBXEX_CONFIG_41(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_41(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02148ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_41", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_41(a) cavm_bbxex_config_41_t
#define bustype_CAVM_BBXEX_CONFIG_41(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_41(a) "BBXEX_CONFIG_41"
#define busnum_CAVM_BBXEX_CONFIG_41(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_41(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_410
 *
 * BBX5 Configuration Register 410
 * Job Configuration
 */
union cavm_bbxex_config_410
{
    uint64_t u;
    struct cavm_bbxex_config_410_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_410_s cn; */
};
typedef union cavm_bbxex_config_410 cavm_bbxex_config_410_t;

static inline uint64_t CAVM_BBXEX_CONFIG_410(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_410(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02cd0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_410", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_410(a) cavm_bbxex_config_410_t
#define bustype_CAVM_BBXEX_CONFIG_410(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_410(a) "BBXEX_CONFIG_410"
#define busnum_CAVM_BBXEX_CONFIG_410(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_410(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_411
 *
 * BBX5 Configuration Register 411
 * Job Configuration
 */
union cavm_bbxex_config_411
{
    uint64_t u;
    struct cavm_bbxex_config_411_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_411_s cn; */
};
typedef union cavm_bbxex_config_411 cavm_bbxex_config_411_t;

static inline uint64_t CAVM_BBXEX_CONFIG_411(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_411(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02cd8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_411", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_411(a) cavm_bbxex_config_411_t
#define bustype_CAVM_BBXEX_CONFIG_411(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_411(a) "BBXEX_CONFIG_411"
#define busnum_CAVM_BBXEX_CONFIG_411(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_411(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_412
 *
 * BBX5 Configuration Register 412
 * Job Configuration
 */
union cavm_bbxex_config_412
{
    uint64_t u;
    struct cavm_bbxex_config_412_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_412_s cn; */
};
typedef union cavm_bbxex_config_412 cavm_bbxex_config_412_t;

static inline uint64_t CAVM_BBXEX_CONFIG_412(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_412(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ce0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_412", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_412(a) cavm_bbxex_config_412_t
#define bustype_CAVM_BBXEX_CONFIG_412(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_412(a) "BBXEX_CONFIG_412"
#define busnum_CAVM_BBXEX_CONFIG_412(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_412(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_413
 *
 * BBX5 Configuration Register 413
 * Job Configuration
 */
union cavm_bbxex_config_413
{
    uint64_t u;
    struct cavm_bbxex_config_413_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_413_s cn; */
};
typedef union cavm_bbxex_config_413 cavm_bbxex_config_413_t;

static inline uint64_t CAVM_BBXEX_CONFIG_413(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_413(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ce8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_413", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_413(a) cavm_bbxex_config_413_t
#define bustype_CAVM_BBXEX_CONFIG_413(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_413(a) "BBXEX_CONFIG_413"
#define busnum_CAVM_BBXEX_CONFIG_413(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_413(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_414
 *
 * BBX5 Configuration Register 414
 * Job Configuration
 */
union cavm_bbxex_config_414
{
    uint64_t u;
    struct cavm_bbxex_config_414_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_414_s cn; */
};
typedef union cavm_bbxex_config_414 cavm_bbxex_config_414_t;

static inline uint64_t CAVM_BBXEX_CONFIG_414(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_414(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02cf0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_414", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_414(a) cavm_bbxex_config_414_t
#define bustype_CAVM_BBXEX_CONFIG_414(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_414(a) "BBXEX_CONFIG_414"
#define busnum_CAVM_BBXEX_CONFIG_414(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_414(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_415
 *
 * BBX5 Configuration Register 415
 * Job Configuration
 */
union cavm_bbxex_config_415
{
    uint64_t u;
    struct cavm_bbxex_config_415_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_415_s cn; */
};
typedef union cavm_bbxex_config_415 cavm_bbxex_config_415_t;

static inline uint64_t CAVM_BBXEX_CONFIG_415(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_415(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02cf8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_415", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_415(a) cavm_bbxex_config_415_t
#define bustype_CAVM_BBXEX_CONFIG_415(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_415(a) "BBXEX_CONFIG_415"
#define busnum_CAVM_BBXEX_CONFIG_415(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_415(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_416
 *
 * BBX5 Configuration Register 416
 * Job Configuration
 */
union cavm_bbxex_config_416
{
    uint64_t u;
    struct cavm_bbxex_config_416_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_416_s cn; */
};
typedef union cavm_bbxex_config_416 cavm_bbxex_config_416_t;

static inline uint64_t CAVM_BBXEX_CONFIG_416(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_416(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d00ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_416", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_416(a) cavm_bbxex_config_416_t
#define bustype_CAVM_BBXEX_CONFIG_416(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_416(a) "BBXEX_CONFIG_416"
#define busnum_CAVM_BBXEX_CONFIG_416(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_416(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_417
 *
 * BBX5 Configuration Register 417
 * Job Configuration
 */
union cavm_bbxex_config_417
{
    uint64_t u;
    struct cavm_bbxex_config_417_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_417_s cn; */
};
typedef union cavm_bbxex_config_417 cavm_bbxex_config_417_t;

static inline uint64_t CAVM_BBXEX_CONFIG_417(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_417(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d08ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_417", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_417(a) cavm_bbxex_config_417_t
#define bustype_CAVM_BBXEX_CONFIG_417(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_417(a) "BBXEX_CONFIG_417"
#define busnum_CAVM_BBXEX_CONFIG_417(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_417(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_418
 *
 * BBX5 Configuration Register 418
 * Job Configuration
 */
union cavm_bbxex_config_418
{
    uint64_t u;
    struct cavm_bbxex_config_418_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_418_s cn; */
};
typedef union cavm_bbxex_config_418 cavm_bbxex_config_418_t;

static inline uint64_t CAVM_BBXEX_CONFIG_418(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_418(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d10ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_418", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_418(a) cavm_bbxex_config_418_t
#define bustype_CAVM_BBXEX_CONFIG_418(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_418(a) "BBXEX_CONFIG_418"
#define busnum_CAVM_BBXEX_CONFIG_418(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_418(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_419
 *
 * BBX5 Configuration Register 419
 * Job Configuration
 */
union cavm_bbxex_config_419
{
    uint64_t u;
    struct cavm_bbxex_config_419_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_419_s cn; */
};
typedef union cavm_bbxex_config_419 cavm_bbxex_config_419_t;

static inline uint64_t CAVM_BBXEX_CONFIG_419(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_419(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d18ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_419", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_419(a) cavm_bbxex_config_419_t
#define bustype_CAVM_BBXEX_CONFIG_419(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_419(a) "BBXEX_CONFIG_419"
#define busnum_CAVM_BBXEX_CONFIG_419(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_419(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_42
 *
 * BBX5 Configuration Register 42
 * Job Configuration
 */
union cavm_bbxex_config_42
{
    uint64_t u;
    struct cavm_bbxex_config_42_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_42_s cn; */
};
typedef union cavm_bbxex_config_42 cavm_bbxex_config_42_t;

static inline uint64_t CAVM_BBXEX_CONFIG_42(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_42(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02150ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_42", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_42(a) cavm_bbxex_config_42_t
#define bustype_CAVM_BBXEX_CONFIG_42(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_42(a) "BBXEX_CONFIG_42"
#define busnum_CAVM_BBXEX_CONFIG_42(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_42(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_420
 *
 * BBX5 Configuration Register 420
 * Job Configuration
 */
union cavm_bbxex_config_420
{
    uint64_t u;
    struct cavm_bbxex_config_420_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_420_s cn; */
};
typedef union cavm_bbxex_config_420 cavm_bbxex_config_420_t;

static inline uint64_t CAVM_BBXEX_CONFIG_420(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_420(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d20ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_420", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_420(a) cavm_bbxex_config_420_t
#define bustype_CAVM_BBXEX_CONFIG_420(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_420(a) "BBXEX_CONFIG_420"
#define busnum_CAVM_BBXEX_CONFIG_420(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_420(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_421
 *
 * BBX5 Configuration Register 421
 * Job Configuration
 */
union cavm_bbxex_config_421
{
    uint64_t u;
    struct cavm_bbxex_config_421_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_421_s cn; */
};
typedef union cavm_bbxex_config_421 cavm_bbxex_config_421_t;

static inline uint64_t CAVM_BBXEX_CONFIG_421(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_421(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d28ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_421", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_421(a) cavm_bbxex_config_421_t
#define bustype_CAVM_BBXEX_CONFIG_421(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_421(a) "BBXEX_CONFIG_421"
#define busnum_CAVM_BBXEX_CONFIG_421(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_421(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_422
 *
 * BBX5 Configuration Register 422
 * Job Configuration
 */
union cavm_bbxex_config_422
{
    uint64_t u;
    struct cavm_bbxex_config_422_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_422_s cn; */
};
typedef union cavm_bbxex_config_422 cavm_bbxex_config_422_t;

static inline uint64_t CAVM_BBXEX_CONFIG_422(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_422(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d30ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_422", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_422(a) cavm_bbxex_config_422_t
#define bustype_CAVM_BBXEX_CONFIG_422(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_422(a) "BBXEX_CONFIG_422"
#define busnum_CAVM_BBXEX_CONFIG_422(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_422(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_423
 *
 * BBX5 Configuration Register 423
 * Job Configuration
 */
union cavm_bbxex_config_423
{
    uint64_t u;
    struct cavm_bbxex_config_423_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_423_s cn; */
};
typedef union cavm_bbxex_config_423 cavm_bbxex_config_423_t;

static inline uint64_t CAVM_BBXEX_CONFIG_423(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_423(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d38ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_423", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_423(a) cavm_bbxex_config_423_t
#define bustype_CAVM_BBXEX_CONFIG_423(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_423(a) "BBXEX_CONFIG_423"
#define busnum_CAVM_BBXEX_CONFIG_423(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_423(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_424
 *
 * BBX5 Configuration Register 424
 * Job Configuration
 */
union cavm_bbxex_config_424
{
    uint64_t u;
    struct cavm_bbxex_config_424_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_424_s cn; */
};
typedef union cavm_bbxex_config_424 cavm_bbxex_config_424_t;

static inline uint64_t CAVM_BBXEX_CONFIG_424(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_424(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d40ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_424", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_424(a) cavm_bbxex_config_424_t
#define bustype_CAVM_BBXEX_CONFIG_424(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_424(a) "BBXEX_CONFIG_424"
#define busnum_CAVM_BBXEX_CONFIG_424(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_424(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_425
 *
 * BBX5 Configuration Register 425
 * Job Configuration
 */
union cavm_bbxex_config_425
{
    uint64_t u;
    struct cavm_bbxex_config_425_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_425_s cn; */
};
typedef union cavm_bbxex_config_425 cavm_bbxex_config_425_t;

static inline uint64_t CAVM_BBXEX_CONFIG_425(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_425(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d48ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_425", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_425(a) cavm_bbxex_config_425_t
#define bustype_CAVM_BBXEX_CONFIG_425(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_425(a) "BBXEX_CONFIG_425"
#define busnum_CAVM_BBXEX_CONFIG_425(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_425(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_426
 *
 * BBX5 Configuration Register 426
 * Job Configuration
 */
union cavm_bbxex_config_426
{
    uint64_t u;
    struct cavm_bbxex_config_426_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_426_s cn; */
};
typedef union cavm_bbxex_config_426 cavm_bbxex_config_426_t;

static inline uint64_t CAVM_BBXEX_CONFIG_426(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_426(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d50ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_426", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_426(a) cavm_bbxex_config_426_t
#define bustype_CAVM_BBXEX_CONFIG_426(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_426(a) "BBXEX_CONFIG_426"
#define busnum_CAVM_BBXEX_CONFIG_426(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_426(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_427
 *
 * BBX5 Configuration Register 427
 * Job Configuration
 */
union cavm_bbxex_config_427
{
    uint64_t u;
    struct cavm_bbxex_config_427_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_427_s cn; */
};
typedef union cavm_bbxex_config_427 cavm_bbxex_config_427_t;

static inline uint64_t CAVM_BBXEX_CONFIG_427(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_427(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d58ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_427", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_427(a) cavm_bbxex_config_427_t
#define bustype_CAVM_BBXEX_CONFIG_427(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_427(a) "BBXEX_CONFIG_427"
#define busnum_CAVM_BBXEX_CONFIG_427(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_427(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_428
 *
 * BBX5 Configuration Register 428
 * Job Configuration
 */
union cavm_bbxex_config_428
{
    uint64_t u;
    struct cavm_bbxex_config_428_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_428_s cn; */
};
typedef union cavm_bbxex_config_428 cavm_bbxex_config_428_t;

static inline uint64_t CAVM_BBXEX_CONFIG_428(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_428(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d60ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_428", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_428(a) cavm_bbxex_config_428_t
#define bustype_CAVM_BBXEX_CONFIG_428(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_428(a) "BBXEX_CONFIG_428"
#define busnum_CAVM_BBXEX_CONFIG_428(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_428(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_429
 *
 * BBX5 Configuration Register 429
 * Job Configuration
 */
union cavm_bbxex_config_429
{
    uint64_t u;
    struct cavm_bbxex_config_429_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_429_s cn; */
};
typedef union cavm_bbxex_config_429 cavm_bbxex_config_429_t;

static inline uint64_t CAVM_BBXEX_CONFIG_429(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_429(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d68ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_429", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_429(a) cavm_bbxex_config_429_t
#define bustype_CAVM_BBXEX_CONFIG_429(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_429(a) "BBXEX_CONFIG_429"
#define busnum_CAVM_BBXEX_CONFIG_429(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_429(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_43
 *
 * BBX5 Configuration Register 43
 * Job Configuration
 */
union cavm_bbxex_config_43
{
    uint64_t u;
    struct cavm_bbxex_config_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_43_s cn; */
};
typedef union cavm_bbxex_config_43 cavm_bbxex_config_43_t;

static inline uint64_t CAVM_BBXEX_CONFIG_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02158ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_43", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_43(a) cavm_bbxex_config_43_t
#define bustype_CAVM_BBXEX_CONFIG_43(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_43(a) "BBXEX_CONFIG_43"
#define busnum_CAVM_BBXEX_CONFIG_43(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_43(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_430
 *
 * BBX5 Configuration Register 430
 * Job Configuration
 */
union cavm_bbxex_config_430
{
    uint64_t u;
    struct cavm_bbxex_config_430_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_430_s cn; */
};
typedef union cavm_bbxex_config_430 cavm_bbxex_config_430_t;

static inline uint64_t CAVM_BBXEX_CONFIG_430(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_430(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d70ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_430", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_430(a) cavm_bbxex_config_430_t
#define bustype_CAVM_BBXEX_CONFIG_430(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_430(a) "BBXEX_CONFIG_430"
#define busnum_CAVM_BBXEX_CONFIG_430(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_430(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_431
 *
 * BBX5 Configuration Register 431
 * Job Configuration
 */
union cavm_bbxex_config_431
{
    uint64_t u;
    struct cavm_bbxex_config_431_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_431_s cn; */
};
typedef union cavm_bbxex_config_431 cavm_bbxex_config_431_t;

static inline uint64_t CAVM_BBXEX_CONFIG_431(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_431(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d78ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_431", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_431(a) cavm_bbxex_config_431_t
#define bustype_CAVM_BBXEX_CONFIG_431(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_431(a) "BBXEX_CONFIG_431"
#define busnum_CAVM_BBXEX_CONFIG_431(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_431(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_432
 *
 * BBX5 Configuration Register 432
 * Job Configuration
 */
union cavm_bbxex_config_432
{
    uint64_t u;
    struct cavm_bbxex_config_432_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_432_s cn; */
};
typedef union cavm_bbxex_config_432 cavm_bbxex_config_432_t;

static inline uint64_t CAVM_BBXEX_CONFIG_432(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_432(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d80ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_432", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_432(a) cavm_bbxex_config_432_t
#define bustype_CAVM_BBXEX_CONFIG_432(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_432(a) "BBXEX_CONFIG_432"
#define busnum_CAVM_BBXEX_CONFIG_432(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_432(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_433
 *
 * BBX5 Configuration Register 433
 * Job Configuration
 */
union cavm_bbxex_config_433
{
    uint64_t u;
    struct cavm_bbxex_config_433_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_433_s cn; */
};
typedef union cavm_bbxex_config_433 cavm_bbxex_config_433_t;

static inline uint64_t CAVM_BBXEX_CONFIG_433(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_433(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d88ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_433", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_433(a) cavm_bbxex_config_433_t
#define bustype_CAVM_BBXEX_CONFIG_433(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_433(a) "BBXEX_CONFIG_433"
#define busnum_CAVM_BBXEX_CONFIG_433(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_433(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_434
 *
 * BBX5 Configuration Register 434
 * Job Configuration
 */
union cavm_bbxex_config_434
{
    uint64_t u;
    struct cavm_bbxex_config_434_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_434_s cn; */
};
typedef union cavm_bbxex_config_434 cavm_bbxex_config_434_t;

static inline uint64_t CAVM_BBXEX_CONFIG_434(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_434(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d90ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_434", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_434(a) cavm_bbxex_config_434_t
#define bustype_CAVM_BBXEX_CONFIG_434(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_434(a) "BBXEX_CONFIG_434"
#define busnum_CAVM_BBXEX_CONFIG_434(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_434(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_435
 *
 * BBX5 Configuration Register 435
 * Job Configuration
 */
union cavm_bbxex_config_435
{
    uint64_t u;
    struct cavm_bbxex_config_435_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_435_s cn; */
};
typedef union cavm_bbxex_config_435 cavm_bbxex_config_435_t;

static inline uint64_t CAVM_BBXEX_CONFIG_435(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_435(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02d98ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_435", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_435(a) cavm_bbxex_config_435_t
#define bustype_CAVM_BBXEX_CONFIG_435(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_435(a) "BBXEX_CONFIG_435"
#define busnum_CAVM_BBXEX_CONFIG_435(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_435(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_436
 *
 * BBX5 Configuration Register 436
 * Job Configuration
 */
union cavm_bbxex_config_436
{
    uint64_t u;
    struct cavm_bbxex_config_436_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_436_s cn; */
};
typedef union cavm_bbxex_config_436 cavm_bbxex_config_436_t;

static inline uint64_t CAVM_BBXEX_CONFIG_436(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_436(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02da0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_436", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_436(a) cavm_bbxex_config_436_t
#define bustype_CAVM_BBXEX_CONFIG_436(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_436(a) "BBXEX_CONFIG_436"
#define busnum_CAVM_BBXEX_CONFIG_436(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_436(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_437
 *
 * BBX5 Configuration Register 437
 * Job Configuration
 */
union cavm_bbxex_config_437
{
    uint64_t u;
    struct cavm_bbxex_config_437_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_437_s cn; */
};
typedef union cavm_bbxex_config_437 cavm_bbxex_config_437_t;

static inline uint64_t CAVM_BBXEX_CONFIG_437(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_437(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02da8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_437", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_437(a) cavm_bbxex_config_437_t
#define bustype_CAVM_BBXEX_CONFIG_437(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_437(a) "BBXEX_CONFIG_437"
#define busnum_CAVM_BBXEX_CONFIG_437(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_437(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_438
 *
 * BBX5 Configuration Register 438
 * Job Configuration
 */
union cavm_bbxex_config_438
{
    uint64_t u;
    struct cavm_bbxex_config_438_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_438_s cn; */
};
typedef union cavm_bbxex_config_438 cavm_bbxex_config_438_t;

static inline uint64_t CAVM_BBXEX_CONFIG_438(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_438(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02db0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_438", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_438(a) cavm_bbxex_config_438_t
#define bustype_CAVM_BBXEX_CONFIG_438(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_438(a) "BBXEX_CONFIG_438"
#define busnum_CAVM_BBXEX_CONFIG_438(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_438(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_439
 *
 * BBX5 Configuration Register 439
 * Job Configuration
 */
union cavm_bbxex_config_439
{
    uint64_t u;
    struct cavm_bbxex_config_439_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_439_s cn; */
};
typedef union cavm_bbxex_config_439 cavm_bbxex_config_439_t;

static inline uint64_t CAVM_BBXEX_CONFIG_439(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_439(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02db8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_439", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_439(a) cavm_bbxex_config_439_t
#define bustype_CAVM_BBXEX_CONFIG_439(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_439(a) "BBXEX_CONFIG_439"
#define busnum_CAVM_BBXEX_CONFIG_439(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_439(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_44
 *
 * BBX5 Configuration Register 44
 * Job Configuration
 */
union cavm_bbxex_config_44
{
    uint64_t u;
    struct cavm_bbxex_config_44_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_44_s cn; */
};
typedef union cavm_bbxex_config_44 cavm_bbxex_config_44_t;

static inline uint64_t CAVM_BBXEX_CONFIG_44(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_44(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02160ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_44", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_44(a) cavm_bbxex_config_44_t
#define bustype_CAVM_BBXEX_CONFIG_44(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_44(a) "BBXEX_CONFIG_44"
#define busnum_CAVM_BBXEX_CONFIG_44(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_44(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_440
 *
 * BBX5 Configuration Register 440
 * Job Configuration
 */
union cavm_bbxex_config_440
{
    uint64_t u;
    struct cavm_bbxex_config_440_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_440_s cn; */
};
typedef union cavm_bbxex_config_440 cavm_bbxex_config_440_t;

static inline uint64_t CAVM_BBXEX_CONFIG_440(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_440(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02dc0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_440", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_440(a) cavm_bbxex_config_440_t
#define bustype_CAVM_BBXEX_CONFIG_440(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_440(a) "BBXEX_CONFIG_440"
#define busnum_CAVM_BBXEX_CONFIG_440(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_440(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_441
 *
 * BBX5 Configuration Register 441
 * Job Configuration
 */
union cavm_bbxex_config_441
{
    uint64_t u;
    struct cavm_bbxex_config_441_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_441_s cn; */
};
typedef union cavm_bbxex_config_441 cavm_bbxex_config_441_t;

static inline uint64_t CAVM_BBXEX_CONFIG_441(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_441(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02dc8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_441", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_441(a) cavm_bbxex_config_441_t
#define bustype_CAVM_BBXEX_CONFIG_441(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_441(a) "BBXEX_CONFIG_441"
#define busnum_CAVM_BBXEX_CONFIG_441(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_441(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_442
 *
 * BBX5 Configuration Register 442
 * Job Configuration
 */
union cavm_bbxex_config_442
{
    uint64_t u;
    struct cavm_bbxex_config_442_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_442_s cn; */
};
typedef union cavm_bbxex_config_442 cavm_bbxex_config_442_t;

static inline uint64_t CAVM_BBXEX_CONFIG_442(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_442(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02dd0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_442", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_442(a) cavm_bbxex_config_442_t
#define bustype_CAVM_BBXEX_CONFIG_442(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_442(a) "BBXEX_CONFIG_442"
#define busnum_CAVM_BBXEX_CONFIG_442(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_442(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_443
 *
 * BBX5 Configuration Register 443
 * Job Configuration
 */
union cavm_bbxex_config_443
{
    uint64_t u;
    struct cavm_bbxex_config_443_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_443_s cn; */
};
typedef union cavm_bbxex_config_443 cavm_bbxex_config_443_t;

static inline uint64_t CAVM_BBXEX_CONFIG_443(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_443(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02dd8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_443", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_443(a) cavm_bbxex_config_443_t
#define bustype_CAVM_BBXEX_CONFIG_443(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_443(a) "BBXEX_CONFIG_443"
#define busnum_CAVM_BBXEX_CONFIG_443(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_443(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_444
 *
 * BBX5 Configuration Register 444
 * Job Configuration
 */
union cavm_bbxex_config_444
{
    uint64_t u;
    struct cavm_bbxex_config_444_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_444_s cn; */
};
typedef union cavm_bbxex_config_444 cavm_bbxex_config_444_t;

static inline uint64_t CAVM_BBXEX_CONFIG_444(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_444(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02de0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_444", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_444(a) cavm_bbxex_config_444_t
#define bustype_CAVM_BBXEX_CONFIG_444(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_444(a) "BBXEX_CONFIG_444"
#define busnum_CAVM_BBXEX_CONFIG_444(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_444(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_445
 *
 * BBX5 Configuration Register 445
 * Job Configuration
 */
union cavm_bbxex_config_445
{
    uint64_t u;
    struct cavm_bbxex_config_445_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_445_s cn; */
};
typedef union cavm_bbxex_config_445 cavm_bbxex_config_445_t;

static inline uint64_t CAVM_BBXEX_CONFIG_445(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_445(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02de8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_445", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_445(a) cavm_bbxex_config_445_t
#define bustype_CAVM_BBXEX_CONFIG_445(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_445(a) "BBXEX_CONFIG_445"
#define busnum_CAVM_BBXEX_CONFIG_445(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_445(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_446
 *
 * BBX5 Configuration Register 446
 * Job Configuration
 */
union cavm_bbxex_config_446
{
    uint64_t u;
    struct cavm_bbxex_config_446_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_446_s cn; */
};
typedef union cavm_bbxex_config_446 cavm_bbxex_config_446_t;

static inline uint64_t CAVM_BBXEX_CONFIG_446(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_446(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02df0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_446", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_446(a) cavm_bbxex_config_446_t
#define bustype_CAVM_BBXEX_CONFIG_446(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_446(a) "BBXEX_CONFIG_446"
#define busnum_CAVM_BBXEX_CONFIG_446(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_446(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_447
 *
 * BBX5 Configuration Register 447
 * Job Configuration
 */
union cavm_bbxex_config_447
{
    uint64_t u;
    struct cavm_bbxex_config_447_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_447_s cn; */
};
typedef union cavm_bbxex_config_447 cavm_bbxex_config_447_t;

static inline uint64_t CAVM_BBXEX_CONFIG_447(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_447(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02df8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_447", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_447(a) cavm_bbxex_config_447_t
#define bustype_CAVM_BBXEX_CONFIG_447(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_447(a) "BBXEX_CONFIG_447"
#define busnum_CAVM_BBXEX_CONFIG_447(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_447(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_448
 *
 * BBX5 Configuration Register 448
 * Job Configuration
 */
union cavm_bbxex_config_448
{
    uint64_t u;
    struct cavm_bbxex_config_448_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_448_s cn; */
};
typedef union cavm_bbxex_config_448 cavm_bbxex_config_448_t;

static inline uint64_t CAVM_BBXEX_CONFIG_448(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_448(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e00ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_448", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_448(a) cavm_bbxex_config_448_t
#define bustype_CAVM_BBXEX_CONFIG_448(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_448(a) "BBXEX_CONFIG_448"
#define busnum_CAVM_BBXEX_CONFIG_448(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_448(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_449
 *
 * BBX5 Configuration Register 449
 * Job Configuration
 */
union cavm_bbxex_config_449
{
    uint64_t u;
    struct cavm_bbxex_config_449_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_449_s cn; */
};
typedef union cavm_bbxex_config_449 cavm_bbxex_config_449_t;

static inline uint64_t CAVM_BBXEX_CONFIG_449(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_449(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e08ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_449", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_449(a) cavm_bbxex_config_449_t
#define bustype_CAVM_BBXEX_CONFIG_449(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_449(a) "BBXEX_CONFIG_449"
#define busnum_CAVM_BBXEX_CONFIG_449(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_449(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_45
 *
 * BBX5 Configuration Register 45
 * Job Configuration
 */
union cavm_bbxex_config_45
{
    uint64_t u;
    struct cavm_bbxex_config_45_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_45_s cn; */
};
typedef union cavm_bbxex_config_45 cavm_bbxex_config_45_t;

static inline uint64_t CAVM_BBXEX_CONFIG_45(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_45(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02168ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_45", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_45(a) cavm_bbxex_config_45_t
#define bustype_CAVM_BBXEX_CONFIG_45(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_45(a) "BBXEX_CONFIG_45"
#define busnum_CAVM_BBXEX_CONFIG_45(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_45(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_450
 *
 * BBX5 Configuration Register 450
 * Job Configuration
 */
union cavm_bbxex_config_450
{
    uint64_t u;
    struct cavm_bbxex_config_450_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_450_s cn; */
};
typedef union cavm_bbxex_config_450 cavm_bbxex_config_450_t;

static inline uint64_t CAVM_BBXEX_CONFIG_450(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_450(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e10ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_450", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_450(a) cavm_bbxex_config_450_t
#define bustype_CAVM_BBXEX_CONFIG_450(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_450(a) "BBXEX_CONFIG_450"
#define busnum_CAVM_BBXEX_CONFIG_450(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_450(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_451
 *
 * BBX5 Configuration Register 451
 * Job Configuration
 */
union cavm_bbxex_config_451
{
    uint64_t u;
    struct cavm_bbxex_config_451_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_451_s cn; */
};
typedef union cavm_bbxex_config_451 cavm_bbxex_config_451_t;

static inline uint64_t CAVM_BBXEX_CONFIG_451(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_451(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e18ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_451", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_451(a) cavm_bbxex_config_451_t
#define bustype_CAVM_BBXEX_CONFIG_451(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_451(a) "BBXEX_CONFIG_451"
#define busnum_CAVM_BBXEX_CONFIG_451(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_451(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_452
 *
 * BBX5 Configuration Register 452
 * Job Configuration
 */
union cavm_bbxex_config_452
{
    uint64_t u;
    struct cavm_bbxex_config_452_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_452_s cn; */
};
typedef union cavm_bbxex_config_452 cavm_bbxex_config_452_t;

static inline uint64_t CAVM_BBXEX_CONFIG_452(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_452(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e20ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_452", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_452(a) cavm_bbxex_config_452_t
#define bustype_CAVM_BBXEX_CONFIG_452(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_452(a) "BBXEX_CONFIG_452"
#define busnum_CAVM_BBXEX_CONFIG_452(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_452(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_453
 *
 * BBX5 Configuration Register 453
 * Job Configuration
 */
union cavm_bbxex_config_453
{
    uint64_t u;
    struct cavm_bbxex_config_453_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_453_s cn; */
};
typedef union cavm_bbxex_config_453 cavm_bbxex_config_453_t;

static inline uint64_t CAVM_BBXEX_CONFIG_453(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_453(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e28ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_453", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_453(a) cavm_bbxex_config_453_t
#define bustype_CAVM_BBXEX_CONFIG_453(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_453(a) "BBXEX_CONFIG_453"
#define busnum_CAVM_BBXEX_CONFIG_453(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_453(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_454
 *
 * BBX5 Configuration Register 454
 * Job Configuration
 */
union cavm_bbxex_config_454
{
    uint64_t u;
    struct cavm_bbxex_config_454_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_454_s cn; */
};
typedef union cavm_bbxex_config_454 cavm_bbxex_config_454_t;

static inline uint64_t CAVM_BBXEX_CONFIG_454(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_454(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e30ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_454", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_454(a) cavm_bbxex_config_454_t
#define bustype_CAVM_BBXEX_CONFIG_454(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_454(a) "BBXEX_CONFIG_454"
#define busnum_CAVM_BBXEX_CONFIG_454(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_454(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_455
 *
 * BBX5 Configuration Register 455
 * Job Configuration
 */
union cavm_bbxex_config_455
{
    uint64_t u;
    struct cavm_bbxex_config_455_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_455_s cn; */
};
typedef union cavm_bbxex_config_455 cavm_bbxex_config_455_t;

static inline uint64_t CAVM_BBXEX_CONFIG_455(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_455(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e38ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_455", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_455(a) cavm_bbxex_config_455_t
#define bustype_CAVM_BBXEX_CONFIG_455(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_455(a) "BBXEX_CONFIG_455"
#define busnum_CAVM_BBXEX_CONFIG_455(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_455(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_456
 *
 * BBX5 Configuration Register 456
 * Job Configuration
 */
union cavm_bbxex_config_456
{
    uint64_t u;
    struct cavm_bbxex_config_456_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_456_s cn; */
};
typedef union cavm_bbxex_config_456 cavm_bbxex_config_456_t;

static inline uint64_t CAVM_BBXEX_CONFIG_456(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_456(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e40ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_456", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_456(a) cavm_bbxex_config_456_t
#define bustype_CAVM_BBXEX_CONFIG_456(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_456(a) "BBXEX_CONFIG_456"
#define busnum_CAVM_BBXEX_CONFIG_456(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_456(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_457
 *
 * BBX5 Configuration Register 457
 * Job Configuration
 */
union cavm_bbxex_config_457
{
    uint64_t u;
    struct cavm_bbxex_config_457_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_457_s cn; */
};
typedef union cavm_bbxex_config_457 cavm_bbxex_config_457_t;

static inline uint64_t CAVM_BBXEX_CONFIG_457(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_457(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e48ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_457", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_457(a) cavm_bbxex_config_457_t
#define bustype_CAVM_BBXEX_CONFIG_457(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_457(a) "BBXEX_CONFIG_457"
#define busnum_CAVM_BBXEX_CONFIG_457(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_457(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_458
 *
 * BBX5 Configuration Register 458
 * Job Configuration
 */
union cavm_bbxex_config_458
{
    uint64_t u;
    struct cavm_bbxex_config_458_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_458_s cn; */
};
typedef union cavm_bbxex_config_458 cavm_bbxex_config_458_t;

static inline uint64_t CAVM_BBXEX_CONFIG_458(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_458(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e50ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_458", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_458(a) cavm_bbxex_config_458_t
#define bustype_CAVM_BBXEX_CONFIG_458(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_458(a) "BBXEX_CONFIG_458"
#define busnum_CAVM_BBXEX_CONFIG_458(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_458(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_459
 *
 * BBX5 Configuration Register 459
 * Job Configuration
 */
union cavm_bbxex_config_459
{
    uint64_t u;
    struct cavm_bbxex_config_459_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_459_s cn; */
};
typedef union cavm_bbxex_config_459 cavm_bbxex_config_459_t;

static inline uint64_t CAVM_BBXEX_CONFIG_459(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_459(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e58ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_459", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_459(a) cavm_bbxex_config_459_t
#define bustype_CAVM_BBXEX_CONFIG_459(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_459(a) "BBXEX_CONFIG_459"
#define busnum_CAVM_BBXEX_CONFIG_459(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_459(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_46
 *
 * BBX5 Configuration Register 46
 * Job Configuration
 */
union cavm_bbxex_config_46
{
    uint64_t u;
    struct cavm_bbxex_config_46_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_46_s cn; */
};
typedef union cavm_bbxex_config_46 cavm_bbxex_config_46_t;

static inline uint64_t CAVM_BBXEX_CONFIG_46(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_46(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02170ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_46", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_46(a) cavm_bbxex_config_46_t
#define bustype_CAVM_BBXEX_CONFIG_46(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_46(a) "BBXEX_CONFIG_46"
#define busnum_CAVM_BBXEX_CONFIG_46(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_46(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_460
 *
 * BBX5 Configuration Register 460
 * Job Configuration
 */
union cavm_bbxex_config_460
{
    uint64_t u;
    struct cavm_bbxex_config_460_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_460_s cn; */
};
typedef union cavm_bbxex_config_460 cavm_bbxex_config_460_t;

static inline uint64_t CAVM_BBXEX_CONFIG_460(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_460(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e60ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_460", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_460(a) cavm_bbxex_config_460_t
#define bustype_CAVM_BBXEX_CONFIG_460(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_460(a) "BBXEX_CONFIG_460"
#define busnum_CAVM_BBXEX_CONFIG_460(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_460(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_461
 *
 * BBX5 Configuration Register 461
 * Job Configuration
 */
union cavm_bbxex_config_461
{
    uint64_t u;
    struct cavm_bbxex_config_461_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_461_s cn; */
};
typedef union cavm_bbxex_config_461 cavm_bbxex_config_461_t;

static inline uint64_t CAVM_BBXEX_CONFIG_461(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_461(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e68ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_461", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_461(a) cavm_bbxex_config_461_t
#define bustype_CAVM_BBXEX_CONFIG_461(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_461(a) "BBXEX_CONFIG_461"
#define busnum_CAVM_BBXEX_CONFIG_461(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_461(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_462
 *
 * BBX5 Configuration Register 462
 * Job Configuration
 */
union cavm_bbxex_config_462
{
    uint64_t u;
    struct cavm_bbxex_config_462_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_462_s cn; */
};
typedef union cavm_bbxex_config_462 cavm_bbxex_config_462_t;

static inline uint64_t CAVM_BBXEX_CONFIG_462(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_462(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e70ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_462", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_462(a) cavm_bbxex_config_462_t
#define bustype_CAVM_BBXEX_CONFIG_462(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_462(a) "BBXEX_CONFIG_462"
#define busnum_CAVM_BBXEX_CONFIG_462(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_462(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_463
 *
 * BBX5 Configuration Register 463
 * Job Configuration
 */
union cavm_bbxex_config_463
{
    uint64_t u;
    struct cavm_bbxex_config_463_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_463_s cn; */
};
typedef union cavm_bbxex_config_463 cavm_bbxex_config_463_t;

static inline uint64_t CAVM_BBXEX_CONFIG_463(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_463(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e78ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_463", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_463(a) cavm_bbxex_config_463_t
#define bustype_CAVM_BBXEX_CONFIG_463(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_463(a) "BBXEX_CONFIG_463"
#define busnum_CAVM_BBXEX_CONFIG_463(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_463(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_464
 *
 * BBX5 Configuration Register 464
 * Job Configuration
 */
union cavm_bbxex_config_464
{
    uint64_t u;
    struct cavm_bbxex_config_464_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_464_s cn; */
};
typedef union cavm_bbxex_config_464 cavm_bbxex_config_464_t;

static inline uint64_t CAVM_BBXEX_CONFIG_464(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_464(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e80ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_464", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_464(a) cavm_bbxex_config_464_t
#define bustype_CAVM_BBXEX_CONFIG_464(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_464(a) "BBXEX_CONFIG_464"
#define busnum_CAVM_BBXEX_CONFIG_464(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_464(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_465
 *
 * BBX5 Configuration Register 465
 * Job Configuration
 */
union cavm_bbxex_config_465
{
    uint64_t u;
    struct cavm_bbxex_config_465_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_465_s cn; */
};
typedef union cavm_bbxex_config_465 cavm_bbxex_config_465_t;

static inline uint64_t CAVM_BBXEX_CONFIG_465(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_465(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e88ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_465", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_465(a) cavm_bbxex_config_465_t
#define bustype_CAVM_BBXEX_CONFIG_465(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_465(a) "BBXEX_CONFIG_465"
#define busnum_CAVM_BBXEX_CONFIG_465(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_465(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_466
 *
 * BBX5 Configuration Register 466
 * Job Configuration
 */
union cavm_bbxex_config_466
{
    uint64_t u;
    struct cavm_bbxex_config_466_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_466_s cn; */
};
typedef union cavm_bbxex_config_466 cavm_bbxex_config_466_t;

static inline uint64_t CAVM_BBXEX_CONFIG_466(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_466(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e90ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_466", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_466(a) cavm_bbxex_config_466_t
#define bustype_CAVM_BBXEX_CONFIG_466(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_466(a) "BBXEX_CONFIG_466"
#define busnum_CAVM_BBXEX_CONFIG_466(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_466(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_467
 *
 * BBX5 Configuration Register 467
 * Job Configuration
 */
union cavm_bbxex_config_467
{
    uint64_t u;
    struct cavm_bbxex_config_467_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_467_s cn; */
};
typedef union cavm_bbxex_config_467 cavm_bbxex_config_467_t;

static inline uint64_t CAVM_BBXEX_CONFIG_467(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_467(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02e98ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_467", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_467(a) cavm_bbxex_config_467_t
#define bustype_CAVM_BBXEX_CONFIG_467(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_467(a) "BBXEX_CONFIG_467"
#define busnum_CAVM_BBXEX_CONFIG_467(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_467(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_468
 *
 * BBX5 Configuration Register 468
 * Job Configuration
 */
union cavm_bbxex_config_468
{
    uint64_t u;
    struct cavm_bbxex_config_468_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_468_s cn; */
};
typedef union cavm_bbxex_config_468 cavm_bbxex_config_468_t;

static inline uint64_t CAVM_BBXEX_CONFIG_468(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_468(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ea0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_468", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_468(a) cavm_bbxex_config_468_t
#define bustype_CAVM_BBXEX_CONFIG_468(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_468(a) "BBXEX_CONFIG_468"
#define busnum_CAVM_BBXEX_CONFIG_468(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_468(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_469
 *
 * BBX5 Configuration Register 469
 * Job Configuration
 */
union cavm_bbxex_config_469
{
    uint64_t u;
    struct cavm_bbxex_config_469_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_469_s cn; */
};
typedef union cavm_bbxex_config_469 cavm_bbxex_config_469_t;

static inline uint64_t CAVM_BBXEX_CONFIG_469(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_469(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ea8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_469", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_469(a) cavm_bbxex_config_469_t
#define bustype_CAVM_BBXEX_CONFIG_469(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_469(a) "BBXEX_CONFIG_469"
#define busnum_CAVM_BBXEX_CONFIG_469(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_469(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_47
 *
 * BBX5 Configuration Register 47
 * Job Configuration
 */
union cavm_bbxex_config_47
{
    uint64_t u;
    struct cavm_bbxex_config_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_47_s cn; */
};
typedef union cavm_bbxex_config_47 cavm_bbxex_config_47_t;

static inline uint64_t CAVM_BBXEX_CONFIG_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02178ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_47", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_47(a) cavm_bbxex_config_47_t
#define bustype_CAVM_BBXEX_CONFIG_47(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_47(a) "BBXEX_CONFIG_47"
#define busnum_CAVM_BBXEX_CONFIG_47(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_47(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_470
 *
 * BBX5 Configuration Register 470
 * Job Configuration
 */
union cavm_bbxex_config_470
{
    uint64_t u;
    struct cavm_bbxex_config_470_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_470_s cn; */
};
typedef union cavm_bbxex_config_470 cavm_bbxex_config_470_t;

static inline uint64_t CAVM_BBXEX_CONFIG_470(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_470(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02eb0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_470", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_470(a) cavm_bbxex_config_470_t
#define bustype_CAVM_BBXEX_CONFIG_470(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_470(a) "BBXEX_CONFIG_470"
#define busnum_CAVM_BBXEX_CONFIG_470(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_470(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_471
 *
 * BBX5 Configuration Register 471
 * Job Configuration
 */
union cavm_bbxex_config_471
{
    uint64_t u;
    struct cavm_bbxex_config_471_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_471_s cn; */
};
typedef union cavm_bbxex_config_471 cavm_bbxex_config_471_t;

static inline uint64_t CAVM_BBXEX_CONFIG_471(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_471(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02eb8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_471", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_471(a) cavm_bbxex_config_471_t
#define bustype_CAVM_BBXEX_CONFIG_471(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_471(a) "BBXEX_CONFIG_471"
#define busnum_CAVM_BBXEX_CONFIG_471(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_471(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_472
 *
 * BBX5 Configuration Register 472
 * Job Configuration
 */
union cavm_bbxex_config_472
{
    uint64_t u;
    struct cavm_bbxex_config_472_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_472_s cn; */
};
typedef union cavm_bbxex_config_472 cavm_bbxex_config_472_t;

static inline uint64_t CAVM_BBXEX_CONFIG_472(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_472(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ec0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_472", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_472(a) cavm_bbxex_config_472_t
#define bustype_CAVM_BBXEX_CONFIG_472(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_472(a) "BBXEX_CONFIG_472"
#define busnum_CAVM_BBXEX_CONFIG_472(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_472(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_473
 *
 * BBX5 Configuration Register 473
 * Job Configuration
 */
union cavm_bbxex_config_473
{
    uint64_t u;
    struct cavm_bbxex_config_473_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_473_s cn; */
};
typedef union cavm_bbxex_config_473 cavm_bbxex_config_473_t;

static inline uint64_t CAVM_BBXEX_CONFIG_473(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_473(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ec8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_473", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_473(a) cavm_bbxex_config_473_t
#define bustype_CAVM_BBXEX_CONFIG_473(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_473(a) "BBXEX_CONFIG_473"
#define busnum_CAVM_BBXEX_CONFIG_473(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_473(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_474
 *
 * BBX5 Configuration Register 474
 * Job Configuration
 */
union cavm_bbxex_config_474
{
    uint64_t u;
    struct cavm_bbxex_config_474_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_474_s cn; */
};
typedef union cavm_bbxex_config_474 cavm_bbxex_config_474_t;

static inline uint64_t CAVM_BBXEX_CONFIG_474(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_474(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ed0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_474", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_474(a) cavm_bbxex_config_474_t
#define bustype_CAVM_BBXEX_CONFIG_474(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_474(a) "BBXEX_CONFIG_474"
#define busnum_CAVM_BBXEX_CONFIG_474(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_474(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_475
 *
 * BBX5 Configuration Register 475
 * Job Configuration
 */
union cavm_bbxex_config_475
{
    uint64_t u;
    struct cavm_bbxex_config_475_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_475_s cn; */
};
typedef union cavm_bbxex_config_475 cavm_bbxex_config_475_t;

static inline uint64_t CAVM_BBXEX_CONFIG_475(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_475(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ed8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_475", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_475(a) cavm_bbxex_config_475_t
#define bustype_CAVM_BBXEX_CONFIG_475(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_475(a) "BBXEX_CONFIG_475"
#define busnum_CAVM_BBXEX_CONFIG_475(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_475(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_476
 *
 * BBX5 Configuration Register 476
 * Job Configuration
 */
union cavm_bbxex_config_476
{
    uint64_t u;
    struct cavm_bbxex_config_476_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_476_s cn; */
};
typedef union cavm_bbxex_config_476 cavm_bbxex_config_476_t;

static inline uint64_t CAVM_BBXEX_CONFIG_476(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_476(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ee0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_476", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_476(a) cavm_bbxex_config_476_t
#define bustype_CAVM_BBXEX_CONFIG_476(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_476(a) "BBXEX_CONFIG_476"
#define busnum_CAVM_BBXEX_CONFIG_476(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_476(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_477
 *
 * BBX5 Configuration Register 477
 * Job Configuration
 */
union cavm_bbxex_config_477
{
    uint64_t u;
    struct cavm_bbxex_config_477_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_477_s cn; */
};
typedef union cavm_bbxex_config_477 cavm_bbxex_config_477_t;

static inline uint64_t CAVM_BBXEX_CONFIG_477(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_477(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ee8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_477", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_477(a) cavm_bbxex_config_477_t
#define bustype_CAVM_BBXEX_CONFIG_477(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_477(a) "BBXEX_CONFIG_477"
#define busnum_CAVM_BBXEX_CONFIG_477(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_477(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_478
 *
 * BBX5 Configuration Register 478
 * Job Configuration
 */
union cavm_bbxex_config_478
{
    uint64_t u;
    struct cavm_bbxex_config_478_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_478_s cn; */
};
typedef union cavm_bbxex_config_478 cavm_bbxex_config_478_t;

static inline uint64_t CAVM_BBXEX_CONFIG_478(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_478(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ef0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_478", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_478(a) cavm_bbxex_config_478_t
#define bustype_CAVM_BBXEX_CONFIG_478(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_478(a) "BBXEX_CONFIG_478"
#define busnum_CAVM_BBXEX_CONFIG_478(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_478(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_479
 *
 * BBX5 Configuration Register 479
 * Job Configuration
 */
union cavm_bbxex_config_479
{
    uint64_t u;
    struct cavm_bbxex_config_479_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_479_s cn; */
};
typedef union cavm_bbxex_config_479 cavm_bbxex_config_479_t;

static inline uint64_t CAVM_BBXEX_CONFIG_479(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_479(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ef8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_479", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_479(a) cavm_bbxex_config_479_t
#define bustype_CAVM_BBXEX_CONFIG_479(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_479(a) "BBXEX_CONFIG_479"
#define busnum_CAVM_BBXEX_CONFIG_479(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_479(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_48
 *
 * BBX5 Configuration Register 48
 * Job Configuration
 */
union cavm_bbxex_config_48
{
    uint64_t u;
    struct cavm_bbxex_config_48_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_48_s cn; */
};
typedef union cavm_bbxex_config_48 cavm_bbxex_config_48_t;

static inline uint64_t CAVM_BBXEX_CONFIG_48(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_48(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02180ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_48", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_48(a) cavm_bbxex_config_48_t
#define bustype_CAVM_BBXEX_CONFIG_48(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_48(a) "BBXEX_CONFIG_48"
#define busnum_CAVM_BBXEX_CONFIG_48(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_48(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_480
 *
 * BBX5 Configuration Register 480
 * Job Configuration
 */
union cavm_bbxex_config_480
{
    uint64_t u;
    struct cavm_bbxex_config_480_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_480_s cn; */
};
typedef union cavm_bbxex_config_480 cavm_bbxex_config_480_t;

static inline uint64_t CAVM_BBXEX_CONFIG_480(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_480(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f00ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_480", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_480(a) cavm_bbxex_config_480_t
#define bustype_CAVM_BBXEX_CONFIG_480(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_480(a) "BBXEX_CONFIG_480"
#define busnum_CAVM_BBXEX_CONFIG_480(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_480(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_481
 *
 * BBX5 Configuration Register 481
 * Job Configuration
 */
union cavm_bbxex_config_481
{
    uint64_t u;
    struct cavm_bbxex_config_481_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_481_s cn; */
};
typedef union cavm_bbxex_config_481 cavm_bbxex_config_481_t;

static inline uint64_t CAVM_BBXEX_CONFIG_481(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_481(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f08ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_481", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_481(a) cavm_bbxex_config_481_t
#define bustype_CAVM_BBXEX_CONFIG_481(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_481(a) "BBXEX_CONFIG_481"
#define busnum_CAVM_BBXEX_CONFIG_481(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_481(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_482
 *
 * BBX5 Configuration Register 482
 * Job Configuration
 */
union cavm_bbxex_config_482
{
    uint64_t u;
    struct cavm_bbxex_config_482_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_482_s cn; */
};
typedef union cavm_bbxex_config_482 cavm_bbxex_config_482_t;

static inline uint64_t CAVM_BBXEX_CONFIG_482(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_482(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f10ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_482", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_482(a) cavm_bbxex_config_482_t
#define bustype_CAVM_BBXEX_CONFIG_482(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_482(a) "BBXEX_CONFIG_482"
#define busnum_CAVM_BBXEX_CONFIG_482(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_482(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_483
 *
 * BBX5 Configuration Register 483
 * Job Configuration
 */
union cavm_bbxex_config_483
{
    uint64_t u;
    struct cavm_bbxex_config_483_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_483_s cn; */
};
typedef union cavm_bbxex_config_483 cavm_bbxex_config_483_t;

static inline uint64_t CAVM_BBXEX_CONFIG_483(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_483(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f18ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_483", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_483(a) cavm_bbxex_config_483_t
#define bustype_CAVM_BBXEX_CONFIG_483(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_483(a) "BBXEX_CONFIG_483"
#define busnum_CAVM_BBXEX_CONFIG_483(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_483(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_484
 *
 * BBX5 Configuration Register 484
 * Job Configuration
 */
union cavm_bbxex_config_484
{
    uint64_t u;
    struct cavm_bbxex_config_484_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_484_s cn; */
};
typedef union cavm_bbxex_config_484 cavm_bbxex_config_484_t;

static inline uint64_t CAVM_BBXEX_CONFIG_484(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_484(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f20ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_484", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_484(a) cavm_bbxex_config_484_t
#define bustype_CAVM_BBXEX_CONFIG_484(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_484(a) "BBXEX_CONFIG_484"
#define busnum_CAVM_BBXEX_CONFIG_484(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_484(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_485
 *
 * BBX5 Configuration Register 485
 * Job Configuration
 */
union cavm_bbxex_config_485
{
    uint64_t u;
    struct cavm_bbxex_config_485_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_485_s cn; */
};
typedef union cavm_bbxex_config_485 cavm_bbxex_config_485_t;

static inline uint64_t CAVM_BBXEX_CONFIG_485(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_485(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f28ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_485", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_485(a) cavm_bbxex_config_485_t
#define bustype_CAVM_BBXEX_CONFIG_485(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_485(a) "BBXEX_CONFIG_485"
#define busnum_CAVM_BBXEX_CONFIG_485(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_485(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_486
 *
 * BBX5 Configuration Register 486
 * Job Configuration
 */
union cavm_bbxex_config_486
{
    uint64_t u;
    struct cavm_bbxex_config_486_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_486_s cn; */
};
typedef union cavm_bbxex_config_486 cavm_bbxex_config_486_t;

static inline uint64_t CAVM_BBXEX_CONFIG_486(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_486(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f30ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_486", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_486(a) cavm_bbxex_config_486_t
#define bustype_CAVM_BBXEX_CONFIG_486(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_486(a) "BBXEX_CONFIG_486"
#define busnum_CAVM_BBXEX_CONFIG_486(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_486(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_487
 *
 * BBX5 Configuration Register 487
 * Job Configuration
 */
union cavm_bbxex_config_487
{
    uint64_t u;
    struct cavm_bbxex_config_487_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_487_s cn; */
};
typedef union cavm_bbxex_config_487 cavm_bbxex_config_487_t;

static inline uint64_t CAVM_BBXEX_CONFIG_487(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_487(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f38ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_487", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_487(a) cavm_bbxex_config_487_t
#define bustype_CAVM_BBXEX_CONFIG_487(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_487(a) "BBXEX_CONFIG_487"
#define busnum_CAVM_BBXEX_CONFIG_487(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_487(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_488
 *
 * BBX5 Configuration Register 488
 * Job Configuration
 */
union cavm_bbxex_config_488
{
    uint64_t u;
    struct cavm_bbxex_config_488_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_488_s cn; */
};
typedef union cavm_bbxex_config_488 cavm_bbxex_config_488_t;

static inline uint64_t CAVM_BBXEX_CONFIG_488(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_488(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f40ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_488", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_488(a) cavm_bbxex_config_488_t
#define bustype_CAVM_BBXEX_CONFIG_488(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_488(a) "BBXEX_CONFIG_488"
#define busnum_CAVM_BBXEX_CONFIG_488(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_488(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_489
 *
 * BBX5 Configuration Register 489
 * Job Configuration
 */
union cavm_bbxex_config_489
{
    uint64_t u;
    struct cavm_bbxex_config_489_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_489_s cn; */
};
typedef union cavm_bbxex_config_489 cavm_bbxex_config_489_t;

static inline uint64_t CAVM_BBXEX_CONFIG_489(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_489(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f48ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_489", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_489(a) cavm_bbxex_config_489_t
#define bustype_CAVM_BBXEX_CONFIG_489(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_489(a) "BBXEX_CONFIG_489"
#define busnum_CAVM_BBXEX_CONFIG_489(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_489(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_49
 *
 * BBX5 Configuration Register 49
 * Job Configuration
 */
union cavm_bbxex_config_49
{
    uint64_t u;
    struct cavm_bbxex_config_49_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_49_s cn; */
};
typedef union cavm_bbxex_config_49 cavm_bbxex_config_49_t;

static inline uint64_t CAVM_BBXEX_CONFIG_49(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_49(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02188ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_49", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_49(a) cavm_bbxex_config_49_t
#define bustype_CAVM_BBXEX_CONFIG_49(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_49(a) "BBXEX_CONFIG_49"
#define busnum_CAVM_BBXEX_CONFIG_49(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_49(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_490
 *
 * BBX5 Configuration Register 490
 * Job Configuration
 */
union cavm_bbxex_config_490
{
    uint64_t u;
    struct cavm_bbxex_config_490_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_490_s cn; */
};
typedef union cavm_bbxex_config_490 cavm_bbxex_config_490_t;

static inline uint64_t CAVM_BBXEX_CONFIG_490(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_490(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f50ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_490", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_490(a) cavm_bbxex_config_490_t
#define bustype_CAVM_BBXEX_CONFIG_490(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_490(a) "BBXEX_CONFIG_490"
#define busnum_CAVM_BBXEX_CONFIG_490(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_490(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_491
 *
 * BBX5 Configuration Register 491
 * Job Configuration
 */
union cavm_bbxex_config_491
{
    uint64_t u;
    struct cavm_bbxex_config_491_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_491_s cn; */
};
typedef union cavm_bbxex_config_491 cavm_bbxex_config_491_t;

static inline uint64_t CAVM_BBXEX_CONFIG_491(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_491(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f58ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_491", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_491(a) cavm_bbxex_config_491_t
#define bustype_CAVM_BBXEX_CONFIG_491(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_491(a) "BBXEX_CONFIG_491"
#define busnum_CAVM_BBXEX_CONFIG_491(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_491(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_492
 *
 * BBX5 Configuration Register 492
 * Job Configuration
 */
union cavm_bbxex_config_492
{
    uint64_t u;
    struct cavm_bbxex_config_492_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_492_s cn; */
};
typedef union cavm_bbxex_config_492 cavm_bbxex_config_492_t;

static inline uint64_t CAVM_BBXEX_CONFIG_492(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_492(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f60ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_492", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_492(a) cavm_bbxex_config_492_t
#define bustype_CAVM_BBXEX_CONFIG_492(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_492(a) "BBXEX_CONFIG_492"
#define busnum_CAVM_BBXEX_CONFIG_492(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_492(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_493
 *
 * BBX5 Configuration Register 493
 * Job Configuration
 */
union cavm_bbxex_config_493
{
    uint64_t u;
    struct cavm_bbxex_config_493_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_493_s cn; */
};
typedef union cavm_bbxex_config_493 cavm_bbxex_config_493_t;

static inline uint64_t CAVM_BBXEX_CONFIG_493(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_493(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f68ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_493", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_493(a) cavm_bbxex_config_493_t
#define bustype_CAVM_BBXEX_CONFIG_493(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_493(a) "BBXEX_CONFIG_493"
#define busnum_CAVM_BBXEX_CONFIG_493(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_493(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_494
 *
 * BBX5 Configuration Register 494
 * Job Configuration
 */
union cavm_bbxex_config_494
{
    uint64_t u;
    struct cavm_bbxex_config_494_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_494_s cn; */
};
typedef union cavm_bbxex_config_494 cavm_bbxex_config_494_t;

static inline uint64_t CAVM_BBXEX_CONFIG_494(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_494(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f70ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_494", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_494(a) cavm_bbxex_config_494_t
#define bustype_CAVM_BBXEX_CONFIG_494(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_494(a) "BBXEX_CONFIG_494"
#define busnum_CAVM_BBXEX_CONFIG_494(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_494(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_495
 *
 * BBX5 Configuration Register 495
 * Job Configuration
 */
union cavm_bbxex_config_495
{
    uint64_t u;
    struct cavm_bbxex_config_495_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_495_s cn; */
};
typedef union cavm_bbxex_config_495 cavm_bbxex_config_495_t;

static inline uint64_t CAVM_BBXEX_CONFIG_495(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_495(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f78ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_495", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_495(a) cavm_bbxex_config_495_t
#define bustype_CAVM_BBXEX_CONFIG_495(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_495(a) "BBXEX_CONFIG_495"
#define busnum_CAVM_BBXEX_CONFIG_495(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_495(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_496
 *
 * BBX5 Configuration Register 496
 * Job Configuration
 */
union cavm_bbxex_config_496
{
    uint64_t u;
    struct cavm_bbxex_config_496_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_496_s cn; */
};
typedef union cavm_bbxex_config_496 cavm_bbxex_config_496_t;

static inline uint64_t CAVM_BBXEX_CONFIG_496(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_496(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f80ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_496", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_496(a) cavm_bbxex_config_496_t
#define bustype_CAVM_BBXEX_CONFIG_496(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_496(a) "BBXEX_CONFIG_496"
#define busnum_CAVM_BBXEX_CONFIG_496(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_496(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_497
 *
 * BBX5 Configuration Register 497
 * Job Configuration
 */
union cavm_bbxex_config_497
{
    uint64_t u;
    struct cavm_bbxex_config_497_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_497_s cn; */
};
typedef union cavm_bbxex_config_497 cavm_bbxex_config_497_t;

static inline uint64_t CAVM_BBXEX_CONFIG_497(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_497(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f88ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_497", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_497(a) cavm_bbxex_config_497_t
#define bustype_CAVM_BBXEX_CONFIG_497(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_497(a) "BBXEX_CONFIG_497"
#define busnum_CAVM_BBXEX_CONFIG_497(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_497(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_498
 *
 * BBX5 Configuration Register 498
 * Job Configuration
 */
union cavm_bbxex_config_498
{
    uint64_t u;
    struct cavm_bbxex_config_498_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_498_s cn; */
};
typedef union cavm_bbxex_config_498 cavm_bbxex_config_498_t;

static inline uint64_t CAVM_BBXEX_CONFIG_498(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_498(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f90ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_498", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_498(a) cavm_bbxex_config_498_t
#define bustype_CAVM_BBXEX_CONFIG_498(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_498(a) "BBXEX_CONFIG_498"
#define busnum_CAVM_BBXEX_CONFIG_498(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_498(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_499
 *
 * BBX5 Configuration Register 499
 * Job Configuration
 */
union cavm_bbxex_config_499
{
    uint64_t u;
    struct cavm_bbxex_config_499_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_499_s cn; */
};
typedef union cavm_bbxex_config_499 cavm_bbxex_config_499_t;

static inline uint64_t CAVM_BBXEX_CONFIG_499(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_499(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02f98ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_499", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_499(a) cavm_bbxex_config_499_t
#define bustype_CAVM_BBXEX_CONFIG_499(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_499(a) "BBXEX_CONFIG_499"
#define busnum_CAVM_BBXEX_CONFIG_499(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_499(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_5
 *
 * BBX5 Configuration Register 5
 * Job Configuration
 */
union cavm_bbxex_config_5
{
    uint64_t u;
    struct cavm_bbxex_config_5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_5_s cn; */
};
typedef union cavm_bbxex_config_5 cavm_bbxex_config_5_t;

static inline uint64_t CAVM_BBXEX_CONFIG_5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_5(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02028ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_5", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_5(a) cavm_bbxex_config_5_t
#define bustype_CAVM_BBXEX_CONFIG_5(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_5(a) "BBXEX_CONFIG_5"
#define busnum_CAVM_BBXEX_CONFIG_5(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_5(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_50
 *
 * BBX5 Configuration Register 50
 * Job Configuration
 */
union cavm_bbxex_config_50
{
    uint64_t u;
    struct cavm_bbxex_config_50_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_50_s cn; */
};
typedef union cavm_bbxex_config_50 cavm_bbxex_config_50_t;

static inline uint64_t CAVM_BBXEX_CONFIG_50(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_50(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02190ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_50", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_50(a) cavm_bbxex_config_50_t
#define bustype_CAVM_BBXEX_CONFIG_50(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_50(a) "BBXEX_CONFIG_50"
#define busnum_CAVM_BBXEX_CONFIG_50(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_50(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_500
 *
 * BBX5 Configuration Register 500
 * Job Configuration
 */
union cavm_bbxex_config_500
{
    uint64_t u;
    struct cavm_bbxex_config_500_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_500_s cn; */
};
typedef union cavm_bbxex_config_500 cavm_bbxex_config_500_t;

static inline uint64_t CAVM_BBXEX_CONFIG_500(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_500(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fa0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_500", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_500(a) cavm_bbxex_config_500_t
#define bustype_CAVM_BBXEX_CONFIG_500(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_500(a) "BBXEX_CONFIG_500"
#define busnum_CAVM_BBXEX_CONFIG_500(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_500(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_501
 *
 * BBX5 Configuration Register 501
 * Job Configuration
 */
union cavm_bbxex_config_501
{
    uint64_t u;
    struct cavm_bbxex_config_501_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_501_s cn; */
};
typedef union cavm_bbxex_config_501 cavm_bbxex_config_501_t;

static inline uint64_t CAVM_BBXEX_CONFIG_501(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_501(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fa8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_501", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_501(a) cavm_bbxex_config_501_t
#define bustype_CAVM_BBXEX_CONFIG_501(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_501(a) "BBXEX_CONFIG_501"
#define busnum_CAVM_BBXEX_CONFIG_501(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_501(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_502
 *
 * BBX5 Configuration Register 502
 * Job Configuration
 */
union cavm_bbxex_config_502
{
    uint64_t u;
    struct cavm_bbxex_config_502_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_502_s cn; */
};
typedef union cavm_bbxex_config_502 cavm_bbxex_config_502_t;

static inline uint64_t CAVM_BBXEX_CONFIG_502(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_502(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fb0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_502", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_502(a) cavm_bbxex_config_502_t
#define bustype_CAVM_BBXEX_CONFIG_502(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_502(a) "BBXEX_CONFIG_502"
#define busnum_CAVM_BBXEX_CONFIG_502(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_502(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_503
 *
 * BBX5 Configuration Register 503
 * Job Configuration
 */
union cavm_bbxex_config_503
{
    uint64_t u;
    struct cavm_bbxex_config_503_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_503_s cn; */
};
typedef union cavm_bbxex_config_503 cavm_bbxex_config_503_t;

static inline uint64_t CAVM_BBXEX_CONFIG_503(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_503(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fb8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_503", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_503(a) cavm_bbxex_config_503_t
#define bustype_CAVM_BBXEX_CONFIG_503(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_503(a) "BBXEX_CONFIG_503"
#define busnum_CAVM_BBXEX_CONFIG_503(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_503(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_504
 *
 * BBX5 Configuration Register 504
 * Job Configuration
 */
union cavm_bbxex_config_504
{
    uint64_t u;
    struct cavm_bbxex_config_504_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_504_s cn; */
};
typedef union cavm_bbxex_config_504 cavm_bbxex_config_504_t;

static inline uint64_t CAVM_BBXEX_CONFIG_504(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_504(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fc0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_504", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_504(a) cavm_bbxex_config_504_t
#define bustype_CAVM_BBXEX_CONFIG_504(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_504(a) "BBXEX_CONFIG_504"
#define busnum_CAVM_BBXEX_CONFIG_504(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_504(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_505
 *
 * BBX5 Configuration Register 505
 * Job Configuration
 */
union cavm_bbxex_config_505
{
    uint64_t u;
    struct cavm_bbxex_config_505_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_505_s cn; */
};
typedef union cavm_bbxex_config_505 cavm_bbxex_config_505_t;

static inline uint64_t CAVM_BBXEX_CONFIG_505(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_505(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fc8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_505", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_505(a) cavm_bbxex_config_505_t
#define bustype_CAVM_BBXEX_CONFIG_505(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_505(a) "BBXEX_CONFIG_505"
#define busnum_CAVM_BBXEX_CONFIG_505(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_505(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_506
 *
 * BBX5 Configuration Register 506
 * Job Configuration
 */
union cavm_bbxex_config_506
{
    uint64_t u;
    struct cavm_bbxex_config_506_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_506_s cn; */
};
typedef union cavm_bbxex_config_506 cavm_bbxex_config_506_t;

static inline uint64_t CAVM_BBXEX_CONFIG_506(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_506(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fd0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_506", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_506(a) cavm_bbxex_config_506_t
#define bustype_CAVM_BBXEX_CONFIG_506(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_506(a) "BBXEX_CONFIG_506"
#define busnum_CAVM_BBXEX_CONFIG_506(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_506(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_507
 *
 * BBX5 Configuration Register 507
 * Job Configuration
 */
union cavm_bbxex_config_507
{
    uint64_t u;
    struct cavm_bbxex_config_507_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_507_s cn; */
};
typedef union cavm_bbxex_config_507 cavm_bbxex_config_507_t;

static inline uint64_t CAVM_BBXEX_CONFIG_507(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_507(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fd8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_507", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_507(a) cavm_bbxex_config_507_t
#define bustype_CAVM_BBXEX_CONFIG_507(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_507(a) "BBXEX_CONFIG_507"
#define busnum_CAVM_BBXEX_CONFIG_507(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_507(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_508
 *
 * BBX5 Configuration Register 508
 * Job Configuration
 */
union cavm_bbxex_config_508
{
    uint64_t u;
    struct cavm_bbxex_config_508_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_508_s cn; */
};
typedef union cavm_bbxex_config_508 cavm_bbxex_config_508_t;

static inline uint64_t CAVM_BBXEX_CONFIG_508(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_508(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fe0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_508", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_508(a) cavm_bbxex_config_508_t
#define bustype_CAVM_BBXEX_CONFIG_508(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_508(a) "BBXEX_CONFIG_508"
#define busnum_CAVM_BBXEX_CONFIG_508(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_508(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_509
 *
 * BBX5 Configuration Register 509
 * Job Configuration
 */
union cavm_bbxex_config_509
{
    uint64_t u;
    struct cavm_bbxex_config_509_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_509_s cn; */
};
typedef union cavm_bbxex_config_509 cavm_bbxex_config_509_t;

static inline uint64_t CAVM_BBXEX_CONFIG_509(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_509(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02fe8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_509", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_509(a) cavm_bbxex_config_509_t
#define bustype_CAVM_BBXEX_CONFIG_509(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_509(a) "BBXEX_CONFIG_509"
#define busnum_CAVM_BBXEX_CONFIG_509(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_509(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_51
 *
 * BBX5 Configuration Register 51
 * Job Configuration
 */
union cavm_bbxex_config_51
{
    uint64_t u;
    struct cavm_bbxex_config_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_51_s cn; */
};
typedef union cavm_bbxex_config_51 cavm_bbxex_config_51_t;

static inline uint64_t CAVM_BBXEX_CONFIG_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02198ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_51", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_51(a) cavm_bbxex_config_51_t
#define bustype_CAVM_BBXEX_CONFIG_51(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_51(a) "BBXEX_CONFIG_51"
#define busnum_CAVM_BBXEX_CONFIG_51(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_51(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_510
 *
 * BBX5 Configuration Register 510
 * Job Configuration
 */
union cavm_bbxex_config_510
{
    uint64_t u;
    struct cavm_bbxex_config_510_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_510_s cn; */
};
typedef union cavm_bbxex_config_510 cavm_bbxex_config_510_t;

static inline uint64_t CAVM_BBXEX_CONFIG_510(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_510(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ff0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_510", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_510(a) cavm_bbxex_config_510_t
#define bustype_CAVM_BBXEX_CONFIG_510(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_510(a) "BBXEX_CONFIG_510"
#define busnum_CAVM_BBXEX_CONFIG_510(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_510(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_511
 *
 * BBX5 Configuration Register 511
 * Job Configuration
 */
union cavm_bbxex_config_511
{
    uint64_t u;
    struct cavm_bbxex_config_511_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_511_s cn; */
};
typedef union cavm_bbxex_config_511 cavm_bbxex_config_511_t;

static inline uint64_t CAVM_BBXEX_CONFIG_511(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_511(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02ff8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_511", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_511(a) cavm_bbxex_config_511_t
#define bustype_CAVM_BBXEX_CONFIG_511(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_511(a) "BBXEX_CONFIG_511"
#define busnum_CAVM_BBXEX_CONFIG_511(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_511(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_512
 *
 * BBX5 Configuration Register 512
 * Job Configuration
 */
union cavm_bbxex_config_512
{
    uint64_t u;
    struct cavm_bbxex_config_512_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_512_s cn; */
};
typedef union cavm_bbxex_config_512 cavm_bbxex_config_512_t;

static inline uint64_t CAVM_BBXEX_CONFIG_512(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_512(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_512", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_512(a) cavm_bbxex_config_512_t
#define bustype_CAVM_BBXEX_CONFIG_512(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_512(a) "BBXEX_CONFIG_512"
#define busnum_CAVM_BBXEX_CONFIG_512(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_512(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_513
 *
 * BBX5 Configuration Register 513
 * Job Configuration
 */
union cavm_bbxex_config_513
{
    uint64_t u;
    struct cavm_bbxex_config_513_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_513_s cn; */
};
typedef union cavm_bbxex_config_513 cavm_bbxex_config_513_t;

static inline uint64_t CAVM_BBXEX_CONFIG_513(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_513(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_513", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_513(a) cavm_bbxex_config_513_t
#define bustype_CAVM_BBXEX_CONFIG_513(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_513(a) "BBXEX_CONFIG_513"
#define busnum_CAVM_BBXEX_CONFIG_513(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_513(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_514
 *
 * BBX5 Configuration Register 514
 * Job Configuration
 */
union cavm_bbxex_config_514
{
    uint64_t u;
    struct cavm_bbxex_config_514_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_514_s cn; */
};
typedef union cavm_bbxex_config_514 cavm_bbxex_config_514_t;

static inline uint64_t CAVM_BBXEX_CONFIG_514(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_514(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03010ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_514", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_514(a) cavm_bbxex_config_514_t
#define bustype_CAVM_BBXEX_CONFIG_514(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_514(a) "BBXEX_CONFIG_514"
#define busnum_CAVM_BBXEX_CONFIG_514(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_514(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_515
 *
 * BBX5 Configuration Register 515
 * Job Configuration
 */
union cavm_bbxex_config_515
{
    uint64_t u;
    struct cavm_bbxex_config_515_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_515_s cn; */
};
typedef union cavm_bbxex_config_515 cavm_bbxex_config_515_t;

static inline uint64_t CAVM_BBXEX_CONFIG_515(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_515(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_515", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_515(a) cavm_bbxex_config_515_t
#define bustype_CAVM_BBXEX_CONFIG_515(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_515(a) "BBXEX_CONFIG_515"
#define busnum_CAVM_BBXEX_CONFIG_515(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_515(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_516
 *
 * BBX5 Configuration Register 516
 * Job Configuration
 */
union cavm_bbxex_config_516
{
    uint64_t u;
    struct cavm_bbxex_config_516_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_516_s cn; */
};
typedef union cavm_bbxex_config_516 cavm_bbxex_config_516_t;

static inline uint64_t CAVM_BBXEX_CONFIG_516(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_516(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03020ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_516", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_516(a) cavm_bbxex_config_516_t
#define bustype_CAVM_BBXEX_CONFIG_516(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_516(a) "BBXEX_CONFIG_516"
#define busnum_CAVM_BBXEX_CONFIG_516(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_516(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_517
 *
 * BBX5 Configuration Register 517
 * Job Configuration
 */
union cavm_bbxex_config_517
{
    uint64_t u;
    struct cavm_bbxex_config_517_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_517_s cn; */
};
typedef union cavm_bbxex_config_517 cavm_bbxex_config_517_t;

static inline uint64_t CAVM_BBXEX_CONFIG_517(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_517(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03028ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_517", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_517(a) cavm_bbxex_config_517_t
#define bustype_CAVM_BBXEX_CONFIG_517(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_517(a) "BBXEX_CONFIG_517"
#define busnum_CAVM_BBXEX_CONFIG_517(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_517(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_518
 *
 * BBX5 Configuration Register 518
 * Job Configuration
 */
union cavm_bbxex_config_518
{
    uint64_t u;
    struct cavm_bbxex_config_518_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_518_s cn; */
};
typedef union cavm_bbxex_config_518 cavm_bbxex_config_518_t;

static inline uint64_t CAVM_BBXEX_CONFIG_518(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_518(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_518", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_518(a) cavm_bbxex_config_518_t
#define bustype_CAVM_BBXEX_CONFIG_518(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_518(a) "BBXEX_CONFIG_518"
#define busnum_CAVM_BBXEX_CONFIG_518(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_518(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_519
 *
 * BBX5 Configuration Register 519
 * Job Configuration
 */
union cavm_bbxex_config_519
{
    uint64_t u;
    struct cavm_bbxex_config_519_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_519_s cn; */
};
typedef union cavm_bbxex_config_519 cavm_bbxex_config_519_t;

static inline uint64_t CAVM_BBXEX_CONFIG_519(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_519(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_519", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_519(a) cavm_bbxex_config_519_t
#define bustype_CAVM_BBXEX_CONFIG_519(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_519(a) "BBXEX_CONFIG_519"
#define busnum_CAVM_BBXEX_CONFIG_519(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_519(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_52
 *
 * BBX5 Configuration Register 52
 * Job Configuration
 */
union cavm_bbxex_config_52
{
    uint64_t u;
    struct cavm_bbxex_config_52_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_52_s cn; */
};
typedef union cavm_bbxex_config_52 cavm_bbxex_config_52_t;

static inline uint64_t CAVM_BBXEX_CONFIG_52(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_52(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_52", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_52(a) cavm_bbxex_config_52_t
#define bustype_CAVM_BBXEX_CONFIG_52(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_52(a) "BBXEX_CONFIG_52"
#define busnum_CAVM_BBXEX_CONFIG_52(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_52(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_520
 *
 * BBX5 Configuration Register 520
 * Job Configuration
 */
union cavm_bbxex_config_520
{
    uint64_t u;
    struct cavm_bbxex_config_520_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_520_s cn; */
};
typedef union cavm_bbxex_config_520 cavm_bbxex_config_520_t;

static inline uint64_t CAVM_BBXEX_CONFIG_520(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_520(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_520", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_520(a) cavm_bbxex_config_520_t
#define bustype_CAVM_BBXEX_CONFIG_520(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_520(a) "BBXEX_CONFIG_520"
#define busnum_CAVM_BBXEX_CONFIG_520(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_520(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_521
 *
 * BBX5 Configuration Register 521
 * Job Configuration
 */
union cavm_bbxex_config_521
{
    uint64_t u;
    struct cavm_bbxex_config_521_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_521_s cn; */
};
typedef union cavm_bbxex_config_521 cavm_bbxex_config_521_t;

static inline uint64_t CAVM_BBXEX_CONFIG_521(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_521(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_521", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_521(a) cavm_bbxex_config_521_t
#define bustype_CAVM_BBXEX_CONFIG_521(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_521(a) "BBXEX_CONFIG_521"
#define busnum_CAVM_BBXEX_CONFIG_521(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_521(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_522
 *
 * BBX5 Configuration Register 522
 * Job Configuration
 */
union cavm_bbxex_config_522
{
    uint64_t u;
    struct cavm_bbxex_config_522_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_522_s cn; */
};
typedef union cavm_bbxex_config_522 cavm_bbxex_config_522_t;

static inline uint64_t CAVM_BBXEX_CONFIG_522(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_522(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03050ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_522", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_522(a) cavm_bbxex_config_522_t
#define bustype_CAVM_BBXEX_CONFIG_522(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_522(a) "BBXEX_CONFIG_522"
#define busnum_CAVM_BBXEX_CONFIG_522(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_522(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_523
 *
 * BBX5 Configuration Register 523
 * Job Configuration
 */
union cavm_bbxex_config_523
{
    uint64_t u;
    struct cavm_bbxex_config_523_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_523_s cn; */
};
typedef union cavm_bbxex_config_523 cavm_bbxex_config_523_t;

static inline uint64_t CAVM_BBXEX_CONFIG_523(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_523(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03058ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_523", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_523(a) cavm_bbxex_config_523_t
#define bustype_CAVM_BBXEX_CONFIG_523(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_523(a) "BBXEX_CONFIG_523"
#define busnum_CAVM_BBXEX_CONFIG_523(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_523(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_524
 *
 * BBX5 Configuration Register 524
 * Job Configuration
 */
union cavm_bbxex_config_524
{
    uint64_t u;
    struct cavm_bbxex_config_524_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_524_s cn; */
};
typedef union cavm_bbxex_config_524 cavm_bbxex_config_524_t;

static inline uint64_t CAVM_BBXEX_CONFIG_524(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_524(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03060ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_524", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_524(a) cavm_bbxex_config_524_t
#define bustype_CAVM_BBXEX_CONFIG_524(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_524(a) "BBXEX_CONFIG_524"
#define busnum_CAVM_BBXEX_CONFIG_524(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_524(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_525
 *
 * BBX5 Configuration Register 525
 * Job Configuration
 */
union cavm_bbxex_config_525
{
    uint64_t u;
    struct cavm_bbxex_config_525_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_525_s cn; */
};
typedef union cavm_bbxex_config_525 cavm_bbxex_config_525_t;

static inline uint64_t CAVM_BBXEX_CONFIG_525(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_525(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03068ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_525", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_525(a) cavm_bbxex_config_525_t
#define bustype_CAVM_BBXEX_CONFIG_525(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_525(a) "BBXEX_CONFIG_525"
#define busnum_CAVM_BBXEX_CONFIG_525(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_525(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_526
 *
 * BBX5 Configuration Register 526
 * Job Configuration
 */
union cavm_bbxex_config_526
{
    uint64_t u;
    struct cavm_bbxex_config_526_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_526_s cn; */
};
typedef union cavm_bbxex_config_526 cavm_bbxex_config_526_t;

static inline uint64_t CAVM_BBXEX_CONFIG_526(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_526(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03070ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_526", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_526(a) cavm_bbxex_config_526_t
#define bustype_CAVM_BBXEX_CONFIG_526(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_526(a) "BBXEX_CONFIG_526"
#define busnum_CAVM_BBXEX_CONFIG_526(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_526(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_527
 *
 * BBX5 Configuration Register 527
 * Job Configuration
 */
union cavm_bbxex_config_527
{
    uint64_t u;
    struct cavm_bbxex_config_527_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_527_s cn; */
};
typedef union cavm_bbxex_config_527 cavm_bbxex_config_527_t;

static inline uint64_t CAVM_BBXEX_CONFIG_527(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_527(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03078ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_527", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_527(a) cavm_bbxex_config_527_t
#define bustype_CAVM_BBXEX_CONFIG_527(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_527(a) "BBXEX_CONFIG_527"
#define busnum_CAVM_BBXEX_CONFIG_527(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_527(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_528
 *
 * BBX5 Configuration Register 528
 * Job Configuration
 */
union cavm_bbxex_config_528
{
    uint64_t u;
    struct cavm_bbxex_config_528_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_528_s cn; */
};
typedef union cavm_bbxex_config_528 cavm_bbxex_config_528_t;

static inline uint64_t CAVM_BBXEX_CONFIG_528(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_528(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03080ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_528", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_528(a) cavm_bbxex_config_528_t
#define bustype_CAVM_BBXEX_CONFIG_528(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_528(a) "BBXEX_CONFIG_528"
#define busnum_CAVM_BBXEX_CONFIG_528(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_528(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_529
 *
 * BBX5 Configuration Register 529
 * Job Configuration
 */
union cavm_bbxex_config_529
{
    uint64_t u;
    struct cavm_bbxex_config_529_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_529_s cn; */
};
typedef union cavm_bbxex_config_529 cavm_bbxex_config_529_t;

static inline uint64_t CAVM_BBXEX_CONFIG_529(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_529(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03088ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_529", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_529(a) cavm_bbxex_config_529_t
#define bustype_CAVM_BBXEX_CONFIG_529(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_529(a) "BBXEX_CONFIG_529"
#define busnum_CAVM_BBXEX_CONFIG_529(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_529(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_53
 *
 * BBX5 Configuration Register 53
 * Job Configuration
 */
union cavm_bbxex_config_53
{
    uint64_t u;
    struct cavm_bbxex_config_53_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_53_s cn; */
};
typedef union cavm_bbxex_config_53 cavm_bbxex_config_53_t;

static inline uint64_t CAVM_BBXEX_CONFIG_53(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_53(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_53", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_53(a) cavm_bbxex_config_53_t
#define bustype_CAVM_BBXEX_CONFIG_53(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_53(a) "BBXEX_CONFIG_53"
#define busnum_CAVM_BBXEX_CONFIG_53(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_53(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_530
 *
 * BBX5 Configuration Register 530
 * Job Configuration
 */
union cavm_bbxex_config_530
{
    uint64_t u;
    struct cavm_bbxex_config_530_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_530_s cn; */
};
typedef union cavm_bbxex_config_530 cavm_bbxex_config_530_t;

static inline uint64_t CAVM_BBXEX_CONFIG_530(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_530(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03090ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_530", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_530(a) cavm_bbxex_config_530_t
#define bustype_CAVM_BBXEX_CONFIG_530(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_530(a) "BBXEX_CONFIG_530"
#define busnum_CAVM_BBXEX_CONFIG_530(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_530(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_531
 *
 * BBX5 Configuration Register 531
 * Job Configuration
 */
union cavm_bbxex_config_531
{
    uint64_t u;
    struct cavm_bbxex_config_531_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_531_s cn; */
};
typedef union cavm_bbxex_config_531 cavm_bbxex_config_531_t;

static inline uint64_t CAVM_BBXEX_CONFIG_531(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_531(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03098ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_531", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_531(a) cavm_bbxex_config_531_t
#define bustype_CAVM_BBXEX_CONFIG_531(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_531(a) "BBXEX_CONFIG_531"
#define busnum_CAVM_BBXEX_CONFIG_531(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_531(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_532
 *
 * BBX5 Configuration Register 532
 * Job Configuration
 */
union cavm_bbxex_config_532
{
    uint64_t u;
    struct cavm_bbxex_config_532_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_532_s cn; */
};
typedef union cavm_bbxex_config_532 cavm_bbxex_config_532_t;

static inline uint64_t CAVM_BBXEX_CONFIG_532(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_532(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_532", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_532(a) cavm_bbxex_config_532_t
#define bustype_CAVM_BBXEX_CONFIG_532(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_532(a) "BBXEX_CONFIG_532"
#define busnum_CAVM_BBXEX_CONFIG_532(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_532(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_533
 *
 * BBX5 Configuration Register 533
 * Job Configuration
 */
union cavm_bbxex_config_533
{
    uint64_t u;
    struct cavm_bbxex_config_533_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_533_s cn; */
};
typedef union cavm_bbxex_config_533 cavm_bbxex_config_533_t;

static inline uint64_t CAVM_BBXEX_CONFIG_533(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_533(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_533", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_533(a) cavm_bbxex_config_533_t
#define bustype_CAVM_BBXEX_CONFIG_533(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_533(a) "BBXEX_CONFIG_533"
#define busnum_CAVM_BBXEX_CONFIG_533(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_533(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_534
 *
 * BBX5 Configuration Register 534
 * Job Configuration
 */
union cavm_bbxex_config_534
{
    uint64_t u;
    struct cavm_bbxex_config_534_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_534_s cn; */
};
typedef union cavm_bbxex_config_534 cavm_bbxex_config_534_t;

static inline uint64_t CAVM_BBXEX_CONFIG_534(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_534(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_534", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_534(a) cavm_bbxex_config_534_t
#define bustype_CAVM_BBXEX_CONFIG_534(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_534(a) "BBXEX_CONFIG_534"
#define busnum_CAVM_BBXEX_CONFIG_534(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_534(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_535
 *
 * BBX5 Configuration Register 535
 * Job Configuration
 */
union cavm_bbxex_config_535
{
    uint64_t u;
    struct cavm_bbxex_config_535_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_535_s cn; */
};
typedef union cavm_bbxex_config_535 cavm_bbxex_config_535_t;

static inline uint64_t CAVM_BBXEX_CONFIG_535(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_535(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_535", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_535(a) cavm_bbxex_config_535_t
#define bustype_CAVM_BBXEX_CONFIG_535(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_535(a) "BBXEX_CONFIG_535"
#define busnum_CAVM_BBXEX_CONFIG_535(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_535(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_536
 *
 * BBX5 Configuration Register 536
 * Job Configuration
 */
union cavm_bbxex_config_536
{
    uint64_t u;
    struct cavm_bbxex_config_536_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_536_s cn; */
};
typedef union cavm_bbxex_config_536 cavm_bbxex_config_536_t;

static inline uint64_t CAVM_BBXEX_CONFIG_536(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_536(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_536", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_536(a) cavm_bbxex_config_536_t
#define bustype_CAVM_BBXEX_CONFIG_536(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_536(a) "BBXEX_CONFIG_536"
#define busnum_CAVM_BBXEX_CONFIG_536(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_536(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_537
 *
 * BBX5 Configuration Register 537
 * Job Configuration
 */
union cavm_bbxex_config_537
{
    uint64_t u;
    struct cavm_bbxex_config_537_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_537_s cn; */
};
typedef union cavm_bbxex_config_537 cavm_bbxex_config_537_t;

static inline uint64_t CAVM_BBXEX_CONFIG_537(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_537(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_537", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_537(a) cavm_bbxex_config_537_t
#define bustype_CAVM_BBXEX_CONFIG_537(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_537(a) "BBXEX_CONFIG_537"
#define busnum_CAVM_BBXEX_CONFIG_537(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_537(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_538
 *
 * BBX5 Configuration Register 538
 * Job Configuration
 */
union cavm_bbxex_config_538
{
    uint64_t u;
    struct cavm_bbxex_config_538_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_538_s cn; */
};
typedef union cavm_bbxex_config_538 cavm_bbxex_config_538_t;

static inline uint64_t CAVM_BBXEX_CONFIG_538(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_538(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_538", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_538(a) cavm_bbxex_config_538_t
#define bustype_CAVM_BBXEX_CONFIG_538(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_538(a) "BBXEX_CONFIG_538"
#define busnum_CAVM_BBXEX_CONFIG_538(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_538(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_539
 *
 * BBX5 Configuration Register 539
 * Job Configuration
 */
union cavm_bbxex_config_539
{
    uint64_t u;
    struct cavm_bbxex_config_539_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_539_s cn; */
};
typedef union cavm_bbxex_config_539 cavm_bbxex_config_539_t;

static inline uint64_t CAVM_BBXEX_CONFIG_539(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_539(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_539", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_539(a) cavm_bbxex_config_539_t
#define bustype_CAVM_BBXEX_CONFIG_539(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_539(a) "BBXEX_CONFIG_539"
#define busnum_CAVM_BBXEX_CONFIG_539(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_539(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_54
 *
 * BBX5 Configuration Register 54
 * Job Configuration
 */
union cavm_bbxex_config_54
{
    uint64_t u;
    struct cavm_bbxex_config_54_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_54_s cn; */
};
typedef union cavm_bbxex_config_54 cavm_bbxex_config_54_t;

static inline uint64_t CAVM_BBXEX_CONFIG_54(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_54(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_54", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_54(a) cavm_bbxex_config_54_t
#define bustype_CAVM_BBXEX_CONFIG_54(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_54(a) "BBXEX_CONFIG_54"
#define busnum_CAVM_BBXEX_CONFIG_54(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_54(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_540
 *
 * BBX5 Configuration Register 540
 * Job Configuration
 */
union cavm_bbxex_config_540
{
    uint64_t u;
    struct cavm_bbxex_config_540_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_540_s cn; */
};
typedef union cavm_bbxex_config_540 cavm_bbxex_config_540_t;

static inline uint64_t CAVM_BBXEX_CONFIG_540(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_540(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_540", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_540(a) cavm_bbxex_config_540_t
#define bustype_CAVM_BBXEX_CONFIG_540(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_540(a) "BBXEX_CONFIG_540"
#define busnum_CAVM_BBXEX_CONFIG_540(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_540(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_541
 *
 * BBX5 Configuration Register 541
 * Job Configuration
 */
union cavm_bbxex_config_541
{
    uint64_t u;
    struct cavm_bbxex_config_541_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_541_s cn; */
};
typedef union cavm_bbxex_config_541 cavm_bbxex_config_541_t;

static inline uint64_t CAVM_BBXEX_CONFIG_541(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_541(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_541", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_541(a) cavm_bbxex_config_541_t
#define bustype_CAVM_BBXEX_CONFIG_541(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_541(a) "BBXEX_CONFIG_541"
#define busnum_CAVM_BBXEX_CONFIG_541(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_541(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_542
 *
 * BBX5 Configuration Register 542
 * Job Configuration
 */
union cavm_bbxex_config_542
{
    uint64_t u;
    struct cavm_bbxex_config_542_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_542_s cn; */
};
typedef union cavm_bbxex_config_542 cavm_bbxex_config_542_t;

static inline uint64_t CAVM_BBXEX_CONFIG_542(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_542(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_542", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_542(a) cavm_bbxex_config_542_t
#define bustype_CAVM_BBXEX_CONFIG_542(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_542(a) "BBXEX_CONFIG_542"
#define busnum_CAVM_BBXEX_CONFIG_542(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_542(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_543
 *
 * BBX5 Configuration Register 543
 * Job Configuration
 */
union cavm_bbxex_config_543
{
    uint64_t u;
    struct cavm_bbxex_config_543_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_543_s cn; */
};
typedef union cavm_bbxex_config_543 cavm_bbxex_config_543_t;

static inline uint64_t CAVM_BBXEX_CONFIG_543(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_543(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c030f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_543", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_543(a) cavm_bbxex_config_543_t
#define bustype_CAVM_BBXEX_CONFIG_543(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_543(a) "BBXEX_CONFIG_543"
#define busnum_CAVM_BBXEX_CONFIG_543(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_543(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_544
 *
 * BBX5 Configuration Register 544
 * Job Configuration
 */
union cavm_bbxex_config_544
{
    uint64_t u;
    struct cavm_bbxex_config_544_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_544_s cn; */
};
typedef union cavm_bbxex_config_544 cavm_bbxex_config_544_t;

static inline uint64_t CAVM_BBXEX_CONFIG_544(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_544(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03100ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_544", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_544(a) cavm_bbxex_config_544_t
#define bustype_CAVM_BBXEX_CONFIG_544(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_544(a) "BBXEX_CONFIG_544"
#define busnum_CAVM_BBXEX_CONFIG_544(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_544(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_545
 *
 * BBX5 Configuration Register 545
 * Job Configuration
 */
union cavm_bbxex_config_545
{
    uint64_t u;
    struct cavm_bbxex_config_545_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_545_s cn; */
};
typedef union cavm_bbxex_config_545 cavm_bbxex_config_545_t;

static inline uint64_t CAVM_BBXEX_CONFIG_545(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_545(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03108ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_545", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_545(a) cavm_bbxex_config_545_t
#define bustype_CAVM_BBXEX_CONFIG_545(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_545(a) "BBXEX_CONFIG_545"
#define busnum_CAVM_BBXEX_CONFIG_545(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_545(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_546
 *
 * BBX5 Configuration Register 546
 * Job Configuration
 */
union cavm_bbxex_config_546
{
    uint64_t u;
    struct cavm_bbxex_config_546_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_546_s cn; */
};
typedef union cavm_bbxex_config_546 cavm_bbxex_config_546_t;

static inline uint64_t CAVM_BBXEX_CONFIG_546(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_546(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03110ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_546", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_546(a) cavm_bbxex_config_546_t
#define bustype_CAVM_BBXEX_CONFIG_546(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_546(a) "BBXEX_CONFIG_546"
#define busnum_CAVM_BBXEX_CONFIG_546(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_546(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_547
 *
 * BBX5 Configuration Register 547
 * Job Configuration
 */
union cavm_bbxex_config_547
{
    uint64_t u;
    struct cavm_bbxex_config_547_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_547_s cn; */
};
typedef union cavm_bbxex_config_547 cavm_bbxex_config_547_t;

static inline uint64_t CAVM_BBXEX_CONFIG_547(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_547(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03118ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_547", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_547(a) cavm_bbxex_config_547_t
#define bustype_CAVM_BBXEX_CONFIG_547(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_547(a) "BBXEX_CONFIG_547"
#define busnum_CAVM_BBXEX_CONFIG_547(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_547(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_548
 *
 * BBX5 Configuration Register 548
 * Job Configuration
 */
union cavm_bbxex_config_548
{
    uint64_t u;
    struct cavm_bbxex_config_548_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_548_s cn; */
};
typedef union cavm_bbxex_config_548 cavm_bbxex_config_548_t;

static inline uint64_t CAVM_BBXEX_CONFIG_548(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_548(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03120ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_548", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_548(a) cavm_bbxex_config_548_t
#define bustype_CAVM_BBXEX_CONFIG_548(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_548(a) "BBXEX_CONFIG_548"
#define busnum_CAVM_BBXEX_CONFIG_548(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_548(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_549
 *
 * BBX5 Configuration Register 549
 * Job Configuration
 */
union cavm_bbxex_config_549
{
    uint64_t u;
    struct cavm_bbxex_config_549_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_549_s cn; */
};
typedef union cavm_bbxex_config_549 cavm_bbxex_config_549_t;

static inline uint64_t CAVM_BBXEX_CONFIG_549(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_549(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03128ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_549", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_549(a) cavm_bbxex_config_549_t
#define bustype_CAVM_BBXEX_CONFIG_549(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_549(a) "BBXEX_CONFIG_549"
#define busnum_CAVM_BBXEX_CONFIG_549(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_549(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_55
 *
 * BBX5 Configuration Register 55
 * Job Configuration
 */
union cavm_bbxex_config_55
{
    uint64_t u;
    struct cavm_bbxex_config_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_55_s cn; */
};
typedef union cavm_bbxex_config_55 cavm_bbxex_config_55_t;

static inline uint64_t CAVM_BBXEX_CONFIG_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_55", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_55(a) cavm_bbxex_config_55_t
#define bustype_CAVM_BBXEX_CONFIG_55(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_55(a) "BBXEX_CONFIG_55"
#define busnum_CAVM_BBXEX_CONFIG_55(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_55(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_550
 *
 * BBX5 Configuration Register 550
 * Job Configuration
 */
union cavm_bbxex_config_550
{
    uint64_t u;
    struct cavm_bbxex_config_550_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_550_s cn; */
};
typedef union cavm_bbxex_config_550 cavm_bbxex_config_550_t;

static inline uint64_t CAVM_BBXEX_CONFIG_550(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_550(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03130ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_550", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_550(a) cavm_bbxex_config_550_t
#define bustype_CAVM_BBXEX_CONFIG_550(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_550(a) "BBXEX_CONFIG_550"
#define busnum_CAVM_BBXEX_CONFIG_550(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_550(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_551
 *
 * BBX5 Configuration Register 551
 * Job Configuration
 */
union cavm_bbxex_config_551
{
    uint64_t u;
    struct cavm_bbxex_config_551_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_551_s cn; */
};
typedef union cavm_bbxex_config_551 cavm_bbxex_config_551_t;

static inline uint64_t CAVM_BBXEX_CONFIG_551(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_551(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03138ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_551", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_551(a) cavm_bbxex_config_551_t
#define bustype_CAVM_BBXEX_CONFIG_551(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_551(a) "BBXEX_CONFIG_551"
#define busnum_CAVM_BBXEX_CONFIG_551(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_551(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_552
 *
 * BBX5 Configuration Register 552
 * Job Configuration
 */
union cavm_bbxex_config_552
{
    uint64_t u;
    struct cavm_bbxex_config_552_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_552_s cn; */
};
typedef union cavm_bbxex_config_552 cavm_bbxex_config_552_t;

static inline uint64_t CAVM_BBXEX_CONFIG_552(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_552(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03140ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_552", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_552(a) cavm_bbxex_config_552_t
#define bustype_CAVM_BBXEX_CONFIG_552(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_552(a) "BBXEX_CONFIG_552"
#define busnum_CAVM_BBXEX_CONFIG_552(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_552(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_553
 *
 * BBX5 Configuration Register 553
 * Job Configuration
 */
union cavm_bbxex_config_553
{
    uint64_t u;
    struct cavm_bbxex_config_553_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_553_s cn; */
};
typedef union cavm_bbxex_config_553 cavm_bbxex_config_553_t;

static inline uint64_t CAVM_BBXEX_CONFIG_553(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_553(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03148ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_553", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_553(a) cavm_bbxex_config_553_t
#define bustype_CAVM_BBXEX_CONFIG_553(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_553(a) "BBXEX_CONFIG_553"
#define busnum_CAVM_BBXEX_CONFIG_553(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_553(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_554
 *
 * BBX5 Configuration Register 554
 * Job Configuration
 */
union cavm_bbxex_config_554
{
    uint64_t u;
    struct cavm_bbxex_config_554_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_554_s cn; */
};
typedef union cavm_bbxex_config_554 cavm_bbxex_config_554_t;

static inline uint64_t CAVM_BBXEX_CONFIG_554(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_554(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03150ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_554", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_554(a) cavm_bbxex_config_554_t
#define bustype_CAVM_BBXEX_CONFIG_554(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_554(a) "BBXEX_CONFIG_554"
#define busnum_CAVM_BBXEX_CONFIG_554(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_554(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_555
 *
 * BBX5 Configuration Register 555
 * Job Configuration
 */
union cavm_bbxex_config_555
{
    uint64_t u;
    struct cavm_bbxex_config_555_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_555_s cn; */
};
typedef union cavm_bbxex_config_555 cavm_bbxex_config_555_t;

static inline uint64_t CAVM_BBXEX_CONFIG_555(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_555(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03158ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_555", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_555(a) cavm_bbxex_config_555_t
#define bustype_CAVM_BBXEX_CONFIG_555(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_555(a) "BBXEX_CONFIG_555"
#define busnum_CAVM_BBXEX_CONFIG_555(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_555(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_556
 *
 * BBX5 Configuration Register 556
 * Job Configuration
 */
union cavm_bbxex_config_556
{
    uint64_t u;
    struct cavm_bbxex_config_556_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_556_s cn; */
};
typedef union cavm_bbxex_config_556 cavm_bbxex_config_556_t;

static inline uint64_t CAVM_BBXEX_CONFIG_556(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_556(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03160ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_556", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_556(a) cavm_bbxex_config_556_t
#define bustype_CAVM_BBXEX_CONFIG_556(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_556(a) "BBXEX_CONFIG_556"
#define busnum_CAVM_BBXEX_CONFIG_556(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_556(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_557
 *
 * BBX5 Configuration Register 557
 * Job Configuration
 */
union cavm_bbxex_config_557
{
    uint64_t u;
    struct cavm_bbxex_config_557_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_557_s cn; */
};
typedef union cavm_bbxex_config_557 cavm_bbxex_config_557_t;

static inline uint64_t CAVM_BBXEX_CONFIG_557(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_557(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03168ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_557", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_557(a) cavm_bbxex_config_557_t
#define bustype_CAVM_BBXEX_CONFIG_557(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_557(a) "BBXEX_CONFIG_557"
#define busnum_CAVM_BBXEX_CONFIG_557(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_557(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_558
 *
 * BBX5 Configuration Register 558
 * Job Configuration
 */
union cavm_bbxex_config_558
{
    uint64_t u;
    struct cavm_bbxex_config_558_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_558_s cn; */
};
typedef union cavm_bbxex_config_558 cavm_bbxex_config_558_t;

static inline uint64_t CAVM_BBXEX_CONFIG_558(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_558(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03170ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_558", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_558(a) cavm_bbxex_config_558_t
#define bustype_CAVM_BBXEX_CONFIG_558(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_558(a) "BBXEX_CONFIG_558"
#define busnum_CAVM_BBXEX_CONFIG_558(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_558(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_559
 *
 * BBX5 Configuration Register 559
 * Job Configuration
 */
union cavm_bbxex_config_559
{
    uint64_t u;
    struct cavm_bbxex_config_559_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_559_s cn; */
};
typedef union cavm_bbxex_config_559 cavm_bbxex_config_559_t;

static inline uint64_t CAVM_BBXEX_CONFIG_559(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_559(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03178ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_559", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_559(a) cavm_bbxex_config_559_t
#define bustype_CAVM_BBXEX_CONFIG_559(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_559(a) "BBXEX_CONFIG_559"
#define busnum_CAVM_BBXEX_CONFIG_559(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_559(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_56
 *
 * BBX5 Configuration Register 56
 * Job Configuration
 */
union cavm_bbxex_config_56
{
    uint64_t u;
    struct cavm_bbxex_config_56_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_56_s cn; */
};
typedef union cavm_bbxex_config_56 cavm_bbxex_config_56_t;

static inline uint64_t CAVM_BBXEX_CONFIG_56(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_56(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_56", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_56(a) cavm_bbxex_config_56_t
#define bustype_CAVM_BBXEX_CONFIG_56(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_56(a) "BBXEX_CONFIG_56"
#define busnum_CAVM_BBXEX_CONFIG_56(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_56(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_560
 *
 * BBX5 Configuration Register 560
 * Job Configuration
 */
union cavm_bbxex_config_560
{
    uint64_t u;
    struct cavm_bbxex_config_560_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_560_s cn; */
};
typedef union cavm_bbxex_config_560 cavm_bbxex_config_560_t;

static inline uint64_t CAVM_BBXEX_CONFIG_560(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_560(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03180ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_560", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_560(a) cavm_bbxex_config_560_t
#define bustype_CAVM_BBXEX_CONFIG_560(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_560(a) "BBXEX_CONFIG_560"
#define busnum_CAVM_BBXEX_CONFIG_560(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_560(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_561
 *
 * BBX5 Configuration Register 561
 * Job Configuration
 */
union cavm_bbxex_config_561
{
    uint64_t u;
    struct cavm_bbxex_config_561_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_561_s cn; */
};
typedef union cavm_bbxex_config_561 cavm_bbxex_config_561_t;

static inline uint64_t CAVM_BBXEX_CONFIG_561(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_561(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03188ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_561", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_561(a) cavm_bbxex_config_561_t
#define bustype_CAVM_BBXEX_CONFIG_561(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_561(a) "BBXEX_CONFIG_561"
#define busnum_CAVM_BBXEX_CONFIG_561(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_561(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_562
 *
 * BBX5 Configuration Register 562
 * Job Configuration
 */
union cavm_bbxex_config_562
{
    uint64_t u;
    struct cavm_bbxex_config_562_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_562_s cn; */
};
typedef union cavm_bbxex_config_562 cavm_bbxex_config_562_t;

static inline uint64_t CAVM_BBXEX_CONFIG_562(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_562(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03190ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_562", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_562(a) cavm_bbxex_config_562_t
#define bustype_CAVM_BBXEX_CONFIG_562(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_562(a) "BBXEX_CONFIG_562"
#define busnum_CAVM_BBXEX_CONFIG_562(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_562(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_563
 *
 * BBX5 Configuration Register 563
 * Job Configuration
 */
union cavm_bbxex_config_563
{
    uint64_t u;
    struct cavm_bbxex_config_563_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_563_s cn; */
};
typedef union cavm_bbxex_config_563 cavm_bbxex_config_563_t;

static inline uint64_t CAVM_BBXEX_CONFIG_563(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_563(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c03198ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_563", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_563(a) cavm_bbxex_config_563_t
#define bustype_CAVM_BBXEX_CONFIG_563(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_563(a) "BBXEX_CONFIG_563"
#define busnum_CAVM_BBXEX_CONFIG_563(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_563(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_564
 *
 * BBX5 Configuration Register 564
 * Job Configuration
 */
union cavm_bbxex_config_564
{
    uint64_t u;
    struct cavm_bbxex_config_564_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_564_s cn; */
};
typedef union cavm_bbxex_config_564 cavm_bbxex_config_564_t;

static inline uint64_t CAVM_BBXEX_CONFIG_564(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_564(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c031a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_564", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_564(a) cavm_bbxex_config_564_t
#define bustype_CAVM_BBXEX_CONFIG_564(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_564(a) "BBXEX_CONFIG_564"
#define busnum_CAVM_BBXEX_CONFIG_564(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_564(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_565
 *
 * BBX5 Configuration Register 565
 * Job Configuration
 */
union cavm_bbxex_config_565
{
    uint64_t u;
    struct cavm_bbxex_config_565_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_565_s cn; */
};
typedef union cavm_bbxex_config_565 cavm_bbxex_config_565_t;

static inline uint64_t CAVM_BBXEX_CONFIG_565(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_565(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c031a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_565", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_565(a) cavm_bbxex_config_565_t
#define bustype_CAVM_BBXEX_CONFIG_565(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_565(a) "BBXEX_CONFIG_565"
#define busnum_CAVM_BBXEX_CONFIG_565(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_565(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_566
 *
 * BBX5 Configuration Register 566
 * Job Configuration
 */
union cavm_bbxex_config_566
{
    uint64_t u;
    struct cavm_bbxex_config_566_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_566_s cn; */
};
typedef union cavm_bbxex_config_566 cavm_bbxex_config_566_t;

static inline uint64_t CAVM_BBXEX_CONFIG_566(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_566(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c031b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_566", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_566(a) cavm_bbxex_config_566_t
#define bustype_CAVM_BBXEX_CONFIG_566(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_566(a) "BBXEX_CONFIG_566"
#define busnum_CAVM_BBXEX_CONFIG_566(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_566(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_567
 *
 * BBX5 Configuration Register 567
 * Job Configuration
 */
union cavm_bbxex_config_567
{
    uint64_t u;
    struct cavm_bbxex_config_567_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_567_s cn; */
};
typedef union cavm_bbxex_config_567 cavm_bbxex_config_567_t;

static inline uint64_t CAVM_BBXEX_CONFIG_567(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_567(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c031b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_567", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_567(a) cavm_bbxex_config_567_t
#define bustype_CAVM_BBXEX_CONFIG_567(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_567(a) "BBXEX_CONFIG_567"
#define busnum_CAVM_BBXEX_CONFIG_567(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_567(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_568
 *
 * BBX5 Configuration Register 568
 * Job Configuration
 */
union cavm_bbxex_config_568
{
    uint64_t u;
    struct cavm_bbxex_config_568_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_568_s cn; */
};
typedef union cavm_bbxex_config_568 cavm_bbxex_config_568_t;

static inline uint64_t CAVM_BBXEX_CONFIG_568(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_568(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c031c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_568", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_568(a) cavm_bbxex_config_568_t
#define bustype_CAVM_BBXEX_CONFIG_568(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_568(a) "BBXEX_CONFIG_568"
#define busnum_CAVM_BBXEX_CONFIG_568(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_568(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_569
 *
 * BBX5 Configuration Register 569
 * Job Configuration
 */
union cavm_bbxex_config_569
{
    uint64_t u;
    struct cavm_bbxex_config_569_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_569_s cn; */
};
typedef union cavm_bbxex_config_569 cavm_bbxex_config_569_t;

static inline uint64_t CAVM_BBXEX_CONFIG_569(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_569(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c031c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_569", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_569(a) cavm_bbxex_config_569_t
#define bustype_CAVM_BBXEX_CONFIG_569(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_569(a) "BBXEX_CONFIG_569"
#define busnum_CAVM_BBXEX_CONFIG_569(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_569(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_57
 *
 * BBX5 Configuration Register 57
 * Job Configuration
 */
union cavm_bbxex_config_57
{
    uint64_t u;
    struct cavm_bbxex_config_57_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_57_s cn; */
};
typedef union cavm_bbxex_config_57 cavm_bbxex_config_57_t;

static inline uint64_t CAVM_BBXEX_CONFIG_57(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_57(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_57", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_57(a) cavm_bbxex_config_57_t
#define bustype_CAVM_BBXEX_CONFIG_57(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_57(a) "BBXEX_CONFIG_57"
#define busnum_CAVM_BBXEX_CONFIG_57(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_57(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_570
 *
 * BBX5 Configuration Register 570
 * Job Configuration
 */
union cavm_bbxex_config_570
{
    uint64_t u;
    struct cavm_bbxex_config_570_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_570_s cn; */
};
typedef union cavm_bbxex_config_570 cavm_bbxex_config_570_t;

static inline uint64_t CAVM_BBXEX_CONFIG_570(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_570(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c031d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_570", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_570(a) cavm_bbxex_config_570_t
#define bustype_CAVM_BBXEX_CONFIG_570(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_570(a) "BBXEX_CONFIG_570"
#define busnum_CAVM_BBXEX_CONFIG_570(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_570(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_571
 *
 * BBX5 Configuration Register 571
 * Job Configuration
 */
union cavm_bbxex_config_571
{
    uint64_t u;
    struct cavm_bbxex_config_571_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 38; /**< [ 37:  0](R/W) -- */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_571_s cn; */
};
typedef union cavm_bbxex_config_571 cavm_bbxex_config_571_t;

static inline uint64_t CAVM_BBXEX_CONFIG_571(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_571(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c031d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_571", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_571(a) cavm_bbxex_config_571_t
#define bustype_CAVM_BBXEX_CONFIG_571(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_571(a) "BBXEX_CONFIG_571"
#define busnum_CAVM_BBXEX_CONFIG_571(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_571(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_58
 *
 * BBX5 Configuration Register 58
 * Job Configuration
 */
union cavm_bbxex_config_58
{
    uint64_t u;
    struct cavm_bbxex_config_58_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_58_s cn; */
};
typedef union cavm_bbxex_config_58 cavm_bbxex_config_58_t;

static inline uint64_t CAVM_BBXEX_CONFIG_58(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_58(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_58", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_58(a) cavm_bbxex_config_58_t
#define bustype_CAVM_BBXEX_CONFIG_58(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_58(a) "BBXEX_CONFIG_58"
#define busnum_CAVM_BBXEX_CONFIG_58(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_58(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_59
 *
 * BBX5 Configuration Register 59
 * Job Configuration
 */
union cavm_bbxex_config_59
{
    uint64_t u;
    struct cavm_bbxex_config_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_59_s cn; */
};
typedef union cavm_bbxex_config_59 cavm_bbxex_config_59_t;

static inline uint64_t CAVM_BBXEX_CONFIG_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_59", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_59(a) cavm_bbxex_config_59_t
#define bustype_CAVM_BBXEX_CONFIG_59(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_59(a) "BBXEX_CONFIG_59"
#define busnum_CAVM_BBXEX_CONFIG_59(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_59(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_6
 *
 * BBX5 Configuration Register 6
 * Job Configuration
 */
union cavm_bbxex_config_6
{
    uint64_t u;
    struct cavm_bbxex_config_6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_6_s cn; */
};
typedef union cavm_bbxex_config_6 cavm_bbxex_config_6_t;

static inline uint64_t CAVM_BBXEX_CONFIG_6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_6(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_6", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_6(a) cavm_bbxex_config_6_t
#define bustype_CAVM_BBXEX_CONFIG_6(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_6(a) "BBXEX_CONFIG_6"
#define busnum_CAVM_BBXEX_CONFIG_6(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_6(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_60
 *
 * BBX5 Configuration Register 60
 * Job Configuration
 */
union cavm_bbxex_config_60
{
    uint64_t u;
    struct cavm_bbxex_config_60_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_60_s cn; */
};
typedef union cavm_bbxex_config_60 cavm_bbxex_config_60_t;

static inline uint64_t CAVM_BBXEX_CONFIG_60(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_60(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_60", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_60(a) cavm_bbxex_config_60_t
#define bustype_CAVM_BBXEX_CONFIG_60(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_60(a) "BBXEX_CONFIG_60"
#define busnum_CAVM_BBXEX_CONFIG_60(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_60(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_61
 *
 * BBX5 Configuration Register 61
 * Job Configuration
 */
union cavm_bbxex_config_61
{
    uint64_t u;
    struct cavm_bbxex_config_61_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_61_s cn; */
};
typedef union cavm_bbxex_config_61 cavm_bbxex_config_61_t;

static inline uint64_t CAVM_BBXEX_CONFIG_61(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_61(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_61", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_61(a) cavm_bbxex_config_61_t
#define bustype_CAVM_BBXEX_CONFIG_61(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_61(a) "BBXEX_CONFIG_61"
#define busnum_CAVM_BBXEX_CONFIG_61(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_61(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_62
 *
 * BBX5 Configuration Register 62
 * Job Configuration
 */
union cavm_bbxex_config_62
{
    uint64_t u;
    struct cavm_bbxex_config_62_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_62_s cn; */
};
typedef union cavm_bbxex_config_62 cavm_bbxex_config_62_t;

static inline uint64_t CAVM_BBXEX_CONFIG_62(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_62(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_62", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_62(a) cavm_bbxex_config_62_t
#define bustype_CAVM_BBXEX_CONFIG_62(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_62(a) "BBXEX_CONFIG_62"
#define busnum_CAVM_BBXEX_CONFIG_62(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_62(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_63
 *
 * BBX5 Configuration Register 63
 * Job Configuration
 */
union cavm_bbxex_config_63
{
    uint64_t u;
    struct cavm_bbxex_config_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_63_s cn; */
};
typedef union cavm_bbxex_config_63 cavm_bbxex_config_63_t;

static inline uint64_t CAVM_BBXEX_CONFIG_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c021f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_63", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_63(a) cavm_bbxex_config_63_t
#define bustype_CAVM_BBXEX_CONFIG_63(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_63(a) "BBXEX_CONFIG_63"
#define busnum_CAVM_BBXEX_CONFIG_63(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_63(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_64
 *
 * BBX5 Configuration Register 64
 * Job Configuration
 */
union cavm_bbxex_config_64
{
    uint64_t u;
    struct cavm_bbxex_config_64_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_64_s cn; */
};
typedef union cavm_bbxex_config_64 cavm_bbxex_config_64_t;

static inline uint64_t CAVM_BBXEX_CONFIG_64(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_64(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02200ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_64", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_64(a) cavm_bbxex_config_64_t
#define bustype_CAVM_BBXEX_CONFIG_64(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_64(a) "BBXEX_CONFIG_64"
#define busnum_CAVM_BBXEX_CONFIG_64(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_64(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_65
 *
 * BBX5 Configuration Register 65
 * Job Configuration
 */
union cavm_bbxex_config_65
{
    uint64_t u;
    struct cavm_bbxex_config_65_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_65_s cn; */
};
typedef union cavm_bbxex_config_65 cavm_bbxex_config_65_t;

static inline uint64_t CAVM_BBXEX_CONFIG_65(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_65(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02208ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_65", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_65(a) cavm_bbxex_config_65_t
#define bustype_CAVM_BBXEX_CONFIG_65(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_65(a) "BBXEX_CONFIG_65"
#define busnum_CAVM_BBXEX_CONFIG_65(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_65(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_66
 *
 * BBX5 Configuration Register 66
 * Job Configuration
 */
union cavm_bbxex_config_66
{
    uint64_t u;
    struct cavm_bbxex_config_66_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_66_s cn; */
};
typedef union cavm_bbxex_config_66 cavm_bbxex_config_66_t;

static inline uint64_t CAVM_BBXEX_CONFIG_66(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_66(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02210ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_66", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_66(a) cavm_bbxex_config_66_t
#define bustype_CAVM_BBXEX_CONFIG_66(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_66(a) "BBXEX_CONFIG_66"
#define busnum_CAVM_BBXEX_CONFIG_66(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_66(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_67
 *
 * BBX5 Configuration Register 67
 * Job Configuration
 */
union cavm_bbxex_config_67
{
    uint64_t u;
    struct cavm_bbxex_config_67_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_67_s cn; */
};
typedef union cavm_bbxex_config_67 cavm_bbxex_config_67_t;

static inline uint64_t CAVM_BBXEX_CONFIG_67(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_67(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02218ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_67", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_67(a) cavm_bbxex_config_67_t
#define bustype_CAVM_BBXEX_CONFIG_67(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_67(a) "BBXEX_CONFIG_67"
#define busnum_CAVM_BBXEX_CONFIG_67(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_67(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_68
 *
 * BBX5 Configuration Register 68
 * Job Configuration
 */
union cavm_bbxex_config_68
{
    uint64_t u;
    struct cavm_bbxex_config_68_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_68_s cn; */
};
typedef union cavm_bbxex_config_68 cavm_bbxex_config_68_t;

static inline uint64_t CAVM_BBXEX_CONFIG_68(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_68(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02220ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_68", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_68(a) cavm_bbxex_config_68_t
#define bustype_CAVM_BBXEX_CONFIG_68(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_68(a) "BBXEX_CONFIG_68"
#define busnum_CAVM_BBXEX_CONFIG_68(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_68(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_69
 *
 * BBX5 Configuration Register 69
 * Job Configuration
 */
union cavm_bbxex_config_69
{
    uint64_t u;
    struct cavm_bbxex_config_69_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_69_s cn; */
};
typedef union cavm_bbxex_config_69 cavm_bbxex_config_69_t;

static inline uint64_t CAVM_BBXEX_CONFIG_69(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_69(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02228ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_69", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_69(a) cavm_bbxex_config_69_t
#define bustype_CAVM_BBXEX_CONFIG_69(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_69(a) "BBXEX_CONFIG_69"
#define busnum_CAVM_BBXEX_CONFIG_69(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_69(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_7
 *
 * BBX5 Configuration Register 7
 * Job Configuration
 */
union cavm_bbxex_config_7
{
    uint64_t u;
    struct cavm_bbxex_config_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_7_s cn; */
};
typedef union cavm_bbxex_config_7 cavm_bbxex_config_7_t;

static inline uint64_t CAVM_BBXEX_CONFIG_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_7", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_7(a) cavm_bbxex_config_7_t
#define bustype_CAVM_BBXEX_CONFIG_7(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_7(a) "BBXEX_CONFIG_7"
#define busnum_CAVM_BBXEX_CONFIG_7(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_7(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_70
 *
 * BBX5 Configuration Register 70
 * Job Configuration
 */
union cavm_bbxex_config_70
{
    uint64_t u;
    struct cavm_bbxex_config_70_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_70_s cn; */
};
typedef union cavm_bbxex_config_70 cavm_bbxex_config_70_t;

static inline uint64_t CAVM_BBXEX_CONFIG_70(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_70(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02230ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_70", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_70(a) cavm_bbxex_config_70_t
#define bustype_CAVM_BBXEX_CONFIG_70(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_70(a) "BBXEX_CONFIG_70"
#define busnum_CAVM_BBXEX_CONFIG_70(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_70(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_71
 *
 * BBX5 Configuration Register 71
 * Job Configuration
 */
union cavm_bbxex_config_71
{
    uint64_t u;
    struct cavm_bbxex_config_71_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_71_s cn; */
};
typedef union cavm_bbxex_config_71 cavm_bbxex_config_71_t;

static inline uint64_t CAVM_BBXEX_CONFIG_71(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_71(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02238ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_71", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_71(a) cavm_bbxex_config_71_t
#define bustype_CAVM_BBXEX_CONFIG_71(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_71(a) "BBXEX_CONFIG_71"
#define busnum_CAVM_BBXEX_CONFIG_71(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_71(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_72
 *
 * BBX5 Configuration Register 72
 * Job Configuration
 */
union cavm_bbxex_config_72
{
    uint64_t u;
    struct cavm_bbxex_config_72_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_72_s cn; */
};
typedef union cavm_bbxex_config_72 cavm_bbxex_config_72_t;

static inline uint64_t CAVM_BBXEX_CONFIG_72(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_72(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02240ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_72", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_72(a) cavm_bbxex_config_72_t
#define bustype_CAVM_BBXEX_CONFIG_72(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_72(a) "BBXEX_CONFIG_72"
#define busnum_CAVM_BBXEX_CONFIG_72(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_72(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_73
 *
 * BBX5 Configuration Register 73
 * Job Configuration
 */
union cavm_bbxex_config_73
{
    uint64_t u;
    struct cavm_bbxex_config_73_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_73_s cn; */
};
typedef union cavm_bbxex_config_73 cavm_bbxex_config_73_t;

static inline uint64_t CAVM_BBXEX_CONFIG_73(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_73(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02248ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_73", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_73(a) cavm_bbxex_config_73_t
#define bustype_CAVM_BBXEX_CONFIG_73(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_73(a) "BBXEX_CONFIG_73"
#define busnum_CAVM_BBXEX_CONFIG_73(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_73(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_74
 *
 * BBX5 Configuration Register 74
 * Job Configuration
 */
union cavm_bbxex_config_74
{
    uint64_t u;
    struct cavm_bbxex_config_74_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_74_s cn; */
};
typedef union cavm_bbxex_config_74 cavm_bbxex_config_74_t;

static inline uint64_t CAVM_BBXEX_CONFIG_74(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_74(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02250ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_74", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_74(a) cavm_bbxex_config_74_t
#define bustype_CAVM_BBXEX_CONFIG_74(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_74(a) "BBXEX_CONFIG_74"
#define busnum_CAVM_BBXEX_CONFIG_74(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_74(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_75
 *
 * BBX5 Configuration Register 75
 * Job Configuration
 */
union cavm_bbxex_config_75
{
    uint64_t u;
    struct cavm_bbxex_config_75_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_75_s cn; */
};
typedef union cavm_bbxex_config_75 cavm_bbxex_config_75_t;

static inline uint64_t CAVM_BBXEX_CONFIG_75(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_75(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02258ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_75", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_75(a) cavm_bbxex_config_75_t
#define bustype_CAVM_BBXEX_CONFIG_75(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_75(a) "BBXEX_CONFIG_75"
#define busnum_CAVM_BBXEX_CONFIG_75(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_75(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_76
 *
 * BBX5 Configuration Register 76
 * Job Configuration
 */
union cavm_bbxex_config_76
{
    uint64_t u;
    struct cavm_bbxex_config_76_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_76_s cn; */
};
typedef union cavm_bbxex_config_76 cavm_bbxex_config_76_t;

static inline uint64_t CAVM_BBXEX_CONFIG_76(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_76(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02260ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_76", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_76(a) cavm_bbxex_config_76_t
#define bustype_CAVM_BBXEX_CONFIG_76(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_76(a) "BBXEX_CONFIG_76"
#define busnum_CAVM_BBXEX_CONFIG_76(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_76(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_77
 *
 * BBX5 Configuration Register 77
 * Job Configuration
 */
union cavm_bbxex_config_77
{
    uint64_t u;
    struct cavm_bbxex_config_77_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_77_s cn; */
};
typedef union cavm_bbxex_config_77 cavm_bbxex_config_77_t;

static inline uint64_t CAVM_BBXEX_CONFIG_77(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_77(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02268ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_77", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_77(a) cavm_bbxex_config_77_t
#define bustype_CAVM_BBXEX_CONFIG_77(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_77(a) "BBXEX_CONFIG_77"
#define busnum_CAVM_BBXEX_CONFIG_77(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_77(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_78
 *
 * BBX5 Configuration Register 78
 * Job Configuration
 */
union cavm_bbxex_config_78
{
    uint64_t u;
    struct cavm_bbxex_config_78_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_78_s cn; */
};
typedef union cavm_bbxex_config_78 cavm_bbxex_config_78_t;

static inline uint64_t CAVM_BBXEX_CONFIG_78(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_78(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02270ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_78", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_78(a) cavm_bbxex_config_78_t
#define bustype_CAVM_BBXEX_CONFIG_78(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_78(a) "BBXEX_CONFIG_78"
#define busnum_CAVM_BBXEX_CONFIG_78(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_78(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_79
 *
 * BBX5 Configuration Register 79
 * Job Configuration
 */
union cavm_bbxex_config_79
{
    uint64_t u;
    struct cavm_bbxex_config_79_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_79_s cn; */
};
typedef union cavm_bbxex_config_79 cavm_bbxex_config_79_t;

static inline uint64_t CAVM_BBXEX_CONFIG_79(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_79(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02278ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_79", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_79(a) cavm_bbxex_config_79_t
#define bustype_CAVM_BBXEX_CONFIG_79(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_79(a) "BBXEX_CONFIG_79"
#define busnum_CAVM_BBXEX_CONFIG_79(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_79(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_8
 *
 * BBX5 Configuration Register 8
 * Job Configuration
 */
union cavm_bbxex_config_8
{
    uint64_t u;
    struct cavm_bbxex_config_8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_8_s cn; */
};
typedef union cavm_bbxex_config_8 cavm_bbxex_config_8_t;

static inline uint64_t CAVM_BBXEX_CONFIG_8(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_8(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_8", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_8(a) cavm_bbxex_config_8_t
#define bustype_CAVM_BBXEX_CONFIG_8(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_8(a) "BBXEX_CONFIG_8"
#define busnum_CAVM_BBXEX_CONFIG_8(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_8(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_80
 *
 * BBX5 Configuration Register 80
 * Job Configuration
 */
union cavm_bbxex_config_80
{
    uint64_t u;
    struct cavm_bbxex_config_80_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_80_s cn; */
};
typedef union cavm_bbxex_config_80 cavm_bbxex_config_80_t;

static inline uint64_t CAVM_BBXEX_CONFIG_80(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_80(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02280ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_80", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_80(a) cavm_bbxex_config_80_t
#define bustype_CAVM_BBXEX_CONFIG_80(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_80(a) "BBXEX_CONFIG_80"
#define busnum_CAVM_BBXEX_CONFIG_80(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_80(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_81
 *
 * BBX5 Configuration Register 81
 * Job Configuration
 */
union cavm_bbxex_config_81
{
    uint64_t u;
    struct cavm_bbxex_config_81_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_81_s cn; */
};
typedef union cavm_bbxex_config_81 cavm_bbxex_config_81_t;

static inline uint64_t CAVM_BBXEX_CONFIG_81(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_81(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02288ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_81", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_81(a) cavm_bbxex_config_81_t
#define bustype_CAVM_BBXEX_CONFIG_81(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_81(a) "BBXEX_CONFIG_81"
#define busnum_CAVM_BBXEX_CONFIG_81(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_81(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_82
 *
 * BBX5 Configuration Register 82
 * Job Configuration
 */
union cavm_bbxex_config_82
{
    uint64_t u;
    struct cavm_bbxex_config_82_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_82_s cn; */
};
typedef union cavm_bbxex_config_82 cavm_bbxex_config_82_t;

static inline uint64_t CAVM_BBXEX_CONFIG_82(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_82(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02290ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_82", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_82(a) cavm_bbxex_config_82_t
#define bustype_CAVM_BBXEX_CONFIG_82(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_82(a) "BBXEX_CONFIG_82"
#define busnum_CAVM_BBXEX_CONFIG_82(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_82(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_83
 *
 * BBX5 Configuration Register 83
 * Job Configuration
 */
union cavm_bbxex_config_83
{
    uint64_t u;
    struct cavm_bbxex_config_83_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_83_s cn; */
};
typedef union cavm_bbxex_config_83 cavm_bbxex_config_83_t;

static inline uint64_t CAVM_BBXEX_CONFIG_83(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_83(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02298ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_83", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_83(a) cavm_bbxex_config_83_t
#define bustype_CAVM_BBXEX_CONFIG_83(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_83(a) "BBXEX_CONFIG_83"
#define busnum_CAVM_BBXEX_CONFIG_83(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_83(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_84
 *
 * BBX5 Configuration Register 84
 * Job Configuration
 */
union cavm_bbxex_config_84
{
    uint64_t u;
    struct cavm_bbxex_config_84_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_84_s cn; */
};
typedef union cavm_bbxex_config_84 cavm_bbxex_config_84_t;

static inline uint64_t CAVM_BBXEX_CONFIG_84(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_84(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_84", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_84(a) cavm_bbxex_config_84_t
#define bustype_CAVM_BBXEX_CONFIG_84(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_84(a) "BBXEX_CONFIG_84"
#define busnum_CAVM_BBXEX_CONFIG_84(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_84(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_85
 *
 * BBX5 Configuration Register 85
 * Job Configuration
 */
union cavm_bbxex_config_85
{
    uint64_t u;
    struct cavm_bbxex_config_85_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_85_s cn; */
};
typedef union cavm_bbxex_config_85 cavm_bbxex_config_85_t;

static inline uint64_t CAVM_BBXEX_CONFIG_85(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_85(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_85", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_85(a) cavm_bbxex_config_85_t
#define bustype_CAVM_BBXEX_CONFIG_85(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_85(a) "BBXEX_CONFIG_85"
#define busnum_CAVM_BBXEX_CONFIG_85(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_85(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_86
 *
 * BBX5 Configuration Register 86
 * Job Configuration
 */
union cavm_bbxex_config_86
{
    uint64_t u;
    struct cavm_bbxex_config_86_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_86_s cn; */
};
typedef union cavm_bbxex_config_86 cavm_bbxex_config_86_t;

static inline uint64_t CAVM_BBXEX_CONFIG_86(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_86(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_86", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_86(a) cavm_bbxex_config_86_t
#define bustype_CAVM_BBXEX_CONFIG_86(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_86(a) "BBXEX_CONFIG_86"
#define busnum_CAVM_BBXEX_CONFIG_86(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_86(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_87
 *
 * BBX5 Configuration Register 87
 * Job Configuration
 */
union cavm_bbxex_config_87
{
    uint64_t u;
    struct cavm_bbxex_config_87_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_87_s cn; */
};
typedef union cavm_bbxex_config_87 cavm_bbxex_config_87_t;

static inline uint64_t CAVM_BBXEX_CONFIG_87(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_87(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_87", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_87(a) cavm_bbxex_config_87_t
#define bustype_CAVM_BBXEX_CONFIG_87(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_87(a) "BBXEX_CONFIG_87"
#define busnum_CAVM_BBXEX_CONFIG_87(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_87(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_88
 *
 * BBX5 Configuration Register 88
 * Job Configuration
 */
union cavm_bbxex_config_88
{
    uint64_t u;
    struct cavm_bbxex_config_88_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_88_s cn; */
};
typedef union cavm_bbxex_config_88 cavm_bbxex_config_88_t;

static inline uint64_t CAVM_BBXEX_CONFIG_88(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_88(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_88", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_88(a) cavm_bbxex_config_88_t
#define bustype_CAVM_BBXEX_CONFIG_88(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_88(a) "BBXEX_CONFIG_88"
#define busnum_CAVM_BBXEX_CONFIG_88(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_88(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_89
 *
 * BBX5 Configuration Register 89
 * Job Configuration
 */
union cavm_bbxex_config_89
{
    uint64_t u;
    struct cavm_bbxex_config_89_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_89_s cn; */
};
typedef union cavm_bbxex_config_89 cavm_bbxex_config_89_t;

static inline uint64_t CAVM_BBXEX_CONFIG_89(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_89(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_89", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_89(a) cavm_bbxex_config_89_t
#define bustype_CAVM_BBXEX_CONFIG_89(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_89(a) "BBXEX_CONFIG_89"
#define busnum_CAVM_BBXEX_CONFIG_89(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_89(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_9
 *
 * BBX5 Configuration Register 9
 * Job Configuration
 */
union cavm_bbxex_config_9
{
    uint64_t u;
    struct cavm_bbxex_config_9_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 30; /**< [ 29:  0](R/W) -- */
        uint64_t reserved_30_31        : 2;
        uint64_t config_f_1            : 30; /**< [ 61: 32](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_9_s cn; */
};
typedef union cavm_bbxex_config_9 cavm_bbxex_config_9_t;

static inline uint64_t CAVM_BBXEX_CONFIG_9(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_9(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_9", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_9(a) cavm_bbxex_config_9_t
#define bustype_CAVM_BBXEX_CONFIG_9(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_9(a) "BBXEX_CONFIG_9"
#define busnum_CAVM_BBXEX_CONFIG_9(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_9(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_90
 *
 * BBX5 Configuration Register 90
 * Job Configuration
 */
union cavm_bbxex_config_90
{
    uint64_t u;
    struct cavm_bbxex_config_90_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_90_s cn; */
};
typedef union cavm_bbxex_config_90 cavm_bbxex_config_90_t;

static inline uint64_t CAVM_BBXEX_CONFIG_90(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_90(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_90", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_90(a) cavm_bbxex_config_90_t
#define bustype_CAVM_BBXEX_CONFIG_90(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_90(a) "BBXEX_CONFIG_90"
#define busnum_CAVM_BBXEX_CONFIG_90(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_90(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_91
 *
 * BBX5 Configuration Register 91
 * Job Configuration
 */
union cavm_bbxex_config_91
{
    uint64_t u;
    struct cavm_bbxex_config_91_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_91_s cn; */
};
typedef union cavm_bbxex_config_91 cavm_bbxex_config_91_t;

static inline uint64_t CAVM_BBXEX_CONFIG_91(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_91(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_91", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_91(a) cavm_bbxex_config_91_t
#define bustype_CAVM_BBXEX_CONFIG_91(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_91(a) "BBXEX_CONFIG_91"
#define busnum_CAVM_BBXEX_CONFIG_91(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_91(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_92
 *
 * BBX5 Configuration Register 92
 * Job Configuration
 */
union cavm_bbxex_config_92
{
    uint64_t u;
    struct cavm_bbxex_config_92_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_92_s cn; */
};
typedef union cavm_bbxex_config_92 cavm_bbxex_config_92_t;

static inline uint64_t CAVM_BBXEX_CONFIG_92(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_92(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_92", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_92(a) cavm_bbxex_config_92_t
#define bustype_CAVM_BBXEX_CONFIG_92(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_92(a) "BBXEX_CONFIG_92"
#define busnum_CAVM_BBXEX_CONFIG_92(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_92(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_93
 *
 * BBX5 Configuration Register 93
 * Job Configuration
 */
union cavm_bbxex_config_93
{
    uint64_t u;
    struct cavm_bbxex_config_93_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_93_s cn; */
};
typedef union cavm_bbxex_config_93 cavm_bbxex_config_93_t;

static inline uint64_t CAVM_BBXEX_CONFIG_93(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_93(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_93", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_93(a) cavm_bbxex_config_93_t
#define bustype_CAVM_BBXEX_CONFIG_93(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_93(a) "BBXEX_CONFIG_93"
#define busnum_CAVM_BBXEX_CONFIG_93(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_93(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_94
 *
 * BBX5 Configuration Register 94
 * Job Configuration
 */
union cavm_bbxex_config_94
{
    uint64_t u;
    struct cavm_bbxex_config_94_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_94_s cn; */
};
typedef union cavm_bbxex_config_94 cavm_bbxex_config_94_t;

static inline uint64_t CAVM_BBXEX_CONFIG_94(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_94(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_94", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_94(a) cavm_bbxex_config_94_t
#define bustype_CAVM_BBXEX_CONFIG_94(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_94(a) "BBXEX_CONFIG_94"
#define busnum_CAVM_BBXEX_CONFIG_94(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_94(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_95
 *
 * BBX5 Configuration Register 95
 * Job Configuration
 */
union cavm_bbxex_config_95
{
    uint64_t u;
    struct cavm_bbxex_config_95_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_95_s cn; */
};
typedef union cavm_bbxex_config_95 cavm_bbxex_config_95_t;

static inline uint64_t CAVM_BBXEX_CONFIG_95(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_95(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c022f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_95", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_95(a) cavm_bbxex_config_95_t
#define bustype_CAVM_BBXEX_CONFIG_95(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_95(a) "BBXEX_CONFIG_95"
#define busnum_CAVM_BBXEX_CONFIG_95(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_95(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_96
 *
 * BBX5 Configuration Register 96
 * Job Configuration
 */
union cavm_bbxex_config_96
{
    uint64_t u;
    struct cavm_bbxex_config_96_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_96_s cn; */
};
typedef union cavm_bbxex_config_96 cavm_bbxex_config_96_t;

static inline uint64_t CAVM_BBXEX_CONFIG_96(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_96(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02300ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_96", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_96(a) cavm_bbxex_config_96_t
#define bustype_CAVM_BBXEX_CONFIG_96(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_96(a) "BBXEX_CONFIG_96"
#define busnum_CAVM_BBXEX_CONFIG_96(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_96(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_97
 *
 * BBX5 Configuration Register 97
 * Job Configuration
 */
union cavm_bbxex_config_97
{
    uint64_t u;
    struct cavm_bbxex_config_97_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_97_s cn; */
};
typedef union cavm_bbxex_config_97 cavm_bbxex_config_97_t;

static inline uint64_t CAVM_BBXEX_CONFIG_97(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_97(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02308ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_97", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_97(a) cavm_bbxex_config_97_t
#define bustype_CAVM_BBXEX_CONFIG_97(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_97(a) "BBXEX_CONFIG_97"
#define busnum_CAVM_BBXEX_CONFIG_97(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_97(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_98
 *
 * BBX5 Configuration Register 98
 * Job Configuration
 */
union cavm_bbxex_config_98
{
    uint64_t u;
    struct cavm_bbxex_config_98_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_98_s cn; */
};
typedef union cavm_bbxex_config_98 cavm_bbxex_config_98_t;

static inline uint64_t CAVM_BBXEX_CONFIG_98(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_98(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02310ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_98", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_98(a) cavm_bbxex_config_98_t
#define bustype_CAVM_BBXEX_CONFIG_98(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_98(a) "BBXEX_CONFIG_98"
#define busnum_CAVM_BBXEX_CONFIG_98(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_98(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_config_99
 *
 * BBX5 Configuration Register 99
 * Job Configuration
 */
union cavm_bbxex_config_99
{
    uint64_t u;
    struct cavm_bbxex_config_99_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_config_99_s cn; */
};
typedef union cavm_bbxex_config_99 cavm_bbxex_config_99_t;

static inline uint64_t CAVM_BBXEX_CONFIG_99(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONFIG_99(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c02318ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONFIG_99", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONFIG_99(a) cavm_bbxex_config_99_t
#define bustype_CAVM_BBXEX_CONFIG_99(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONFIG_99(a) "BBXEX_CONFIG_99"
#define busnum_CAVM_BBXEX_CONFIG_99(a) (a)
#define arguments_CAVM_BBXEX_CONFIG_99(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_control_main
 *
 * BBX5 Main Control Register
 * HAB Control
 */
union cavm_bbxex_control_main
{
    uint64_t u;
    struct cavm_bbxex_control_main_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t reserved_1_15         : 15;
        uint64_t job_start_0           : 1;  /**< [  0:  0](R/W) Job start */
#else /* Word 0 - Little Endian */
        uint64_t job_start_0           : 1;  /**< [  0:  0](R/W) Job start */
        uint64_t reserved_1_15         : 15;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_control_main_s cn; */
};
typedef union cavm_bbxex_control_main cavm_bbxex_control_main_t;

static inline uint64_t CAVM_BBXEX_CONTROL_MAIN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONTROL_MAIN(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c00000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONTROL_MAIN", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONTROL_MAIN(a) cavm_bbxex_control_main_t
#define bustype_CAVM_BBXEX_CONTROL_MAIN(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONTROL_MAIN(a) "BBXEX_CONTROL_MAIN"
#define busnum_CAVM_BBXEX_CONTROL_MAIN(a) (a)
#define arguments_CAVM_BBXEX_CONTROL_MAIN(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_control_status
 *
 * BBX5 Status Register
 * HAB Control
 */
union cavm_bbxex_control_status
{
    uint64_t u;
    struct cavm_bbxex_control_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) Ready to receive the next job */
        uint64_t reserved_1_3          : 3;
        uint64_t busy                  : 1;  /**< [  0:  0](RO/H) Busy for CONFIGURATION 0 */
#else /* Word 0 - Little Endian */
        uint64_t busy                  : 1;  /**< [  0:  0](RO/H) Busy for CONFIGURATION 0 */
        uint64_t reserved_1_3          : 3;
        uint64_t ready                 : 1;  /**< [  4:  4](RO/H) Ready to receive the next job */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_control_status_s cn; */
};
typedef union cavm_bbxex_control_status cavm_bbxex_control_status_t;

static inline uint64_t CAVM_BBXEX_CONTROL_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_CONTROL_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c00018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_CONTROL_STATUS", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_CONTROL_STATUS(a) cavm_bbxex_control_status_t
#define bustype_CAVM_BBXEX_CONTROL_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_CONTROL_STATUS(a) "BBXEX_CONTROL_STATUS"
#define busnum_CAVM_BBXEX_CONTROL_STATUS(a) (a)
#define arguments_CAVM_BBXEX_CONTROL_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_debug_0
 *
 * BBX5 Debug Register 0
 * HAB information
 */
union cavm_bbxex_debug_0
{
    uint64_t u;
    struct cavm_bbxex_debug_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t hab_info              : 32; /**< [ 31:  0](RO) BBX5 RTL Version */
#else /* Word 0 - Little Endian */
        uint64_t hab_info              : 32; /**< [ 31:  0](RO) BBX5 RTL Version */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_debug_0_s cn; */
};
typedef union cavm_bbxex_debug_0 cavm_bbxex_debug_0_t;

static inline uint64_t CAVM_BBXEX_DEBUG_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_DEBUG_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c01000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_DEBUG_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_DEBUG_0(a) cavm_bbxex_debug_0_t
#define bustype_CAVM_BBXEX_DEBUG_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_DEBUG_0(a) "BBXEX_DEBUG_0"
#define busnum_CAVM_BBXEX_DEBUG_0(a) (a)
#define arguments_CAVM_BBXEX_DEBUG_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_debug_01
 *
 * BBX5 Debug Register 1
 * AB Processing Throught for job
 */
union cavm_bbxex_debug_01
{
    uint64_t u;
    struct cavm_bbxex_debug_01_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t read_if_throughput_job : 32;/**< [ 63: 32](RO) clock count with 1Ghz through the Read IF */
        uint64_t opr_throughput        : 32; /**< [ 31:  0](RO) clock count with 1Ghz through the Write IF */
#else /* Word 0 - Little Endian */
        uint64_t opr_throughput        : 32; /**< [ 31:  0](RO) clock count with 1Ghz through the Write IF */
        uint64_t read_if_throughput_job : 32;/**< [ 63: 32](RO) clock count with 1Ghz through the Read IF */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_debug_01_s cn; */
};
typedef union cavm_bbxex_debug_01 cavm_bbxex_debug_01_t;

static inline uint64_t CAVM_BBXEX_DEBUG_01(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_DEBUG_01(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c01008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_DEBUG_01", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_DEBUG_01(a) cavm_bbxex_debug_01_t
#define bustype_CAVM_BBXEX_DEBUG_01(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_DEBUG_01(a) "BBXEX_DEBUG_01"
#define busnum_CAVM_BBXEX_DEBUG_01(a) (a)
#define arguments_CAVM_BBXEX_DEBUG_01(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_error_register_0
 *
 * BBX5 Error Register 0
 * HAB Control
 */
union cavm_bbxex_error_register_0
{
    uint64_t u;
    struct cavm_bbxex_error_register_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t job_id_dma_error      : 16; /**< [ 31: 16](R/W1C) Job ID for DMA error */
        uint64_t reserved_5_15         : 11;
        uint64_t rp0_overflow          : 1;  /**< [  4:  4](R/W1C) Read Port 0 Overflow */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_underflow         : 1;  /**< [  0:  0](R/W1C) Read Port 0 Underflow */
#else /* Word 0 - Little Endian */
        uint64_t rp0_underflow         : 1;  /**< [  0:  0](R/W1C) Read Port 0 Underflow */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_overflow          : 1;  /**< [  4:  4](R/W1C) Read Port 0 Overflow */
        uint64_t reserved_5_15         : 11;
        uint64_t job_id_dma_error      : 16; /**< [ 31: 16](R/W1C) Job ID for DMA error */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_error_register_0_s cn; */
};
typedef union cavm_bbxex_error_register_0 cavm_bbxex_error_register_0_t;

static inline uint64_t CAVM_BBXEX_ERROR_REGISTER_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_ERROR_REGISTER_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c00030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_ERROR_REGISTER_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_ERROR_REGISTER_0(a) cavm_bbxex_error_register_0_t
#define bustype_CAVM_BBXEX_ERROR_REGISTER_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_ERROR_REGISTER_0(a) "BBXEX_ERROR_REGISTER_0"
#define busnum_CAVM_BBXEX_ERROR_REGISTER_0(a) (a)
#define arguments_CAVM_BBXEX_ERROR_REGISTER_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_error_register_1
 *
 * BBX5 Error Register 1
 * HAB Control
 */
union cavm_bbxex_error_register_1
{
    uint64_t u;
    struct cavm_bbxex_error_register_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t inter_err_job_id      : 16; /**< [ 31: 16](R/W1C) internal error jib ID for Error Register 1 */
        uint64_t reserved_8_15         : 8;
        uint64_t sample_size_mis_match : 1;  /**< [  7:  7](R/W1C) sample data size mis-match for setting size */
        uint64_t reserved_1_6          : 6;
        uint64_t job_data_size_over    : 1;  /**< [  0:  0](R/W1C) Data size over */
#else /* Word 0 - Little Endian */
        uint64_t job_data_size_over    : 1;  /**< [  0:  0](R/W1C) Data size over */
        uint64_t reserved_1_6          : 6;
        uint64_t sample_size_mis_match : 1;  /**< [  7:  7](R/W1C) sample data size mis-match for setting size */
        uint64_t reserved_8_15         : 8;
        uint64_t inter_err_job_id      : 16; /**< [ 31: 16](R/W1C) internal error jib ID for Error Register 1 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_error_register_1_s cn; */
};
typedef union cavm_bbxex_error_register_1 cavm_bbxex_error_register_1_t;

static inline uint64_t CAVM_BBXEX_ERROR_REGISTER_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_ERROR_REGISTER_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c00038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_ERROR_REGISTER_1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_ERROR_REGISTER_1(a) cavm_bbxex_error_register_1_t
#define bustype_CAVM_BBXEX_ERROR_REGISTER_1(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_ERROR_REGISTER_1(a) "BBXEX_ERROR_REGISTER_1"
#define busnum_CAVM_BBXEX_ERROR_REGISTER_1(a) (a)
#define arguments_CAVM_BBXEX_ERROR_REGISTER_1(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_error_register_2
 *
 * BBX5 Error Register 2
 * HAB Control
 */
union cavm_bbxex_error_register_2
{
    uint64_t u;
    struct cavm_bbxex_error_register_2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t rp0_overflow_en       : 1;  /**< [  4:  4](R/W) Read Port 0 Overflow Error Enable */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_underflow_en      : 1;  /**< [  0:  0](R/W) Read Port 0 Underflow Error Enable */
#else /* Word 0 - Little Endian */
        uint64_t rp0_underflow_en      : 1;  /**< [  0:  0](R/W) Read Port 0 Underflow Error Enable */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_overflow_en       : 1;  /**< [  4:  4](R/W) Read Port 0 Overflow Error Enable */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_error_register_2_s cn; */
};
typedef union cavm_bbxex_error_register_2 cavm_bbxex_error_register_2_t;

static inline uint64_t CAVM_BBXEX_ERROR_REGISTER_2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_ERROR_REGISTER_2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c00040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_ERROR_REGISTER_2", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_ERROR_REGISTER_2(a) cavm_bbxex_error_register_2_t
#define bustype_CAVM_BBXEX_ERROR_REGISTER_2(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_ERROR_REGISTER_2(a) "BBXEX_ERROR_REGISTER_2"
#define busnum_CAVM_BBXEX_ERROR_REGISTER_2(a) (a)
#define arguments_CAVM_BBXEX_ERROR_REGISTER_2(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxe#_error_register_3
 *
 * BBX5 Error Register 3
 * HAB Control
 */
union cavm_bbxex_error_register_3
{
    uint64_t u;
    struct cavm_bbxex_error_register_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t hab_error_en          : 1;  /**< [  0:  0](R/W) HAB specific Error Enable */
#else /* Word 0 - Little Endian */
        uint64_t hab_error_en          : 1;  /**< [  0:  0](R/W) HAB specific Error Enable */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxex_error_register_3_s cn; */
};
typedef union cavm_bbxex_error_register_3 cavm_bbxex_error_register_3_t;

static inline uint64_t CAVM_BBXEX_ERROR_REGISTER_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXEX_ERROR_REGISTER_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c00048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXEX_ERROR_REGISTER_3", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXEX_ERROR_REGISTER_3(a) cavm_bbxex_error_register_3_t
#define bustype_CAVM_BBXEX_ERROR_REGISTER_3(a) CSR_TYPE_RSL
#define basename_CAVM_BBXEX_ERROR_REGISTER_3(a) "BBXEX_ERROR_REGISTER_3"
#define busnum_CAVM_BBXEX_ERROR_REGISTER_3(a) (a)
#define arguments_CAVM_BBXEX_ERROR_REGISTER_3(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_BBXE_H__ */
