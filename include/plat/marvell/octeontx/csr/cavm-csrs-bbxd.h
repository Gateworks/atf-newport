#ifndef __CAVM_CSRS_BBXD_H__
#define __CAVM_CSRS_BBXD_H__
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
 * OcteonTX BBXD.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) bbxd#_config_0_0
 *
 * BBX4 Configuration Register 00
 * Job Configuration
 */
union cavm_bbxdx_config_0_0
{
    uint64_t u;
    struct cavm_bbxdx_config_0_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t config_0_0_1          : 17; /**< [ 32: 16](R/W) -- */
        uint64_t reserved_4_15         : 12;
        uint64_t config_0_0_0          : 4;  /**< [  3:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_0_0          : 4;  /**< [  3:  0](R/W) -- */
        uint64_t reserved_4_15         : 12;
        uint64_t config_0_0_1          : 17; /**< [ 32: 16](R/W) -- */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_0_s cn; */
};
typedef union cavm_bbxdx_config_0_0 cavm_bbxdx_config_0_0_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_0(a) cavm_bbxdx_config_0_0_t
#define bustype_CAVM_BBXDX_CONFIG_0_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_0(a) "BBXDX_CONFIG_0_0"
#define busnum_CAVM_BBXDX_CONFIG_0_0(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_1
 *
 * BBX4 Configuration Register 01
 * Job Configuration
 */
union cavm_bbxdx_config_0_1
{
    uint64_t u;
    struct cavm_bbxdx_config_0_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_0_1_3          : 28; /**< [ 59: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_1_2          : 13; /**< [ 28: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_1_1          : 7;  /**< [ 12:  6](R/W) -- */
        uint64_t reserved_5            : 1;
        uint64_t config_0_1_0          : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_1_0          : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5            : 1;
        uint64_t config_0_1_1          : 7;  /**< [ 12:  6](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_1_2          : 13; /**< [ 28: 16](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_1_3          : 28; /**< [ 59: 32](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_1_s cn; */
};
typedef union cavm_bbxdx_config_0_1 cavm_bbxdx_config_0_1_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_1(a) cavm_bbxdx_config_0_1_t
#define bustype_CAVM_BBXDX_CONFIG_0_1(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_1(a) "BBXDX_CONFIG_0_1"
#define busnum_CAVM_BBXDX_CONFIG_0_1(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_1(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_10
 *
 * BBX4 Configuration Register 010
 * Job Configuration
 */
union cavm_bbxdx_config_0_10
{
    uint64_t u;
    struct cavm_bbxdx_config_0_10_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_10           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_10           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_10_s cn; */
};
typedef union cavm_bbxdx_config_0_10 cavm_bbxdx_config_0_10_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_10(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_10(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782050ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_10", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_10(a) cavm_bbxdx_config_0_10_t
#define bustype_CAVM_BBXDX_CONFIG_0_10(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_10(a) "BBXDX_CONFIG_0_10"
#define busnum_CAVM_BBXDX_CONFIG_0_10(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_10(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_100
 *
 * BBX4 Configuration Register 0100
 * Job Configuration
 */
union cavm_bbxdx_config_0_100
{
    uint64_t u;
    struct cavm_bbxdx_config_0_100_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_100_8        : 1;  /**< [ 63: 63](R/W) -- */
        uint64_t reserved_61_62        : 2;
        uint64_t config_0_100_7        : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_100_6        : 1;  /**< [ 52: 52](R/W) -- */
        uint64_t reserved_49_51        : 3;
        uint64_t config_0_100_5        : 1;  /**< [ 48: 48](R/W) -- */
        uint64_t reserved_47           : 1;
        uint64_t config_0_100_4        : 7;  /**< [ 46: 40](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_0_100_3        : 7;  /**< [ 38: 32](R/W) -- */
        uint64_t reserved_23_31        : 9;
        uint64_t config_0_100_2        : 7;  /**< [ 22: 16](R/W) -- */
        uint64_t reserved_10_15        : 6;
        uint64_t config_0_100_1        : 2;  /**< [  9:  8](R/W) -- */
        uint64_t reserved_7            : 1;
        uint64_t config_0_100_0        : 7;  /**< [  6:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_100_0        : 7;  /**< [  6:  0](R/W) -- */
        uint64_t reserved_7            : 1;
        uint64_t config_0_100_1        : 2;  /**< [  9:  8](R/W) -- */
        uint64_t reserved_10_15        : 6;
        uint64_t config_0_100_2        : 7;  /**< [ 22: 16](R/W) -- */
        uint64_t reserved_23_31        : 9;
        uint64_t config_0_100_3        : 7;  /**< [ 38: 32](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_0_100_4        : 7;  /**< [ 46: 40](R/W) -- */
        uint64_t reserved_47           : 1;
        uint64_t config_0_100_5        : 1;  /**< [ 48: 48](R/W) -- */
        uint64_t reserved_49_51        : 3;
        uint64_t config_0_100_6        : 1;  /**< [ 52: 52](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_100_7        : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_62        : 2;
        uint64_t config_0_100_8        : 1;  /**< [ 63: 63](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_100_s cn; */
};
typedef union cavm_bbxdx_config_0_100 cavm_bbxdx_config_0_100_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_100(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_100(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782320ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_100", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_100(a) cavm_bbxdx_config_0_100_t
#define bustype_CAVM_BBXDX_CONFIG_0_100(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_100(a) "BBXDX_CONFIG_0_100"
#define busnum_CAVM_BBXDX_CONFIG_0_100(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_100(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_101
 *
 * BBX4 Configuration Register 0101
 * Job Configuration
 */
union cavm_bbxdx_config_0_101
{
    uint64_t u;
    struct cavm_bbxdx_config_0_101_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_0_101          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_101          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_101_s cn; */
};
typedef union cavm_bbxdx_config_0_101 cavm_bbxdx_config_0_101_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_101(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_101(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782328ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_101", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_101(a) cavm_bbxdx_config_0_101_t
#define bustype_CAVM_BBXDX_CONFIG_0_101(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_101(a) "BBXDX_CONFIG_0_101"
#define busnum_CAVM_BBXDX_CONFIG_0_101(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_101(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_102
 *
 * BBX4 Configuration Register 0102
 * Job Configuration
 */
union cavm_bbxdx_config_0_102
{
    uint64_t u;
    struct cavm_bbxdx_config_0_102_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_0_102          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_102          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_102_s cn; */
};
typedef union cavm_bbxdx_config_0_102 cavm_bbxdx_config_0_102_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_102(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_102(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782330ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_102", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_102(a) cavm_bbxdx_config_0_102_t
#define bustype_CAVM_BBXDX_CONFIG_0_102(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_102(a) "BBXDX_CONFIG_0_102"
#define busnum_CAVM_BBXDX_CONFIG_0_102(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_102(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_103
 *
 * BBX4 Configuration Register 0103
 * Job Configuration
 */
union cavm_bbxdx_config_0_103
{
    uint64_t u;
    struct cavm_bbxdx_config_0_103_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_0_103          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_103          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_103_s cn; */
};
typedef union cavm_bbxdx_config_0_103 cavm_bbxdx_config_0_103_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_103(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_103(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782338ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_103", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_103(a) cavm_bbxdx_config_0_103_t
#define bustype_CAVM_BBXDX_CONFIG_0_103(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_103(a) "BBXDX_CONFIG_0_103"
#define busnum_CAVM_BBXDX_CONFIG_0_103(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_103(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_104
 *
 * BBX4 Configuration Register 0104
 * Job Configuration
 */
union cavm_bbxdx_config_0_104
{
    uint64_t u;
    struct cavm_bbxdx_config_0_104_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_0_104          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_104          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_104_s cn; */
};
typedef union cavm_bbxdx_config_0_104 cavm_bbxdx_config_0_104_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_104(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_104(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782340ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_104", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_104(a) cavm_bbxdx_config_0_104_t
#define bustype_CAVM_BBXDX_CONFIG_0_104(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_104(a) "BBXDX_CONFIG_0_104"
#define busnum_CAVM_BBXDX_CONFIG_0_104(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_104(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_105
 *
 * BBX4 Configuration Register 0105
 * Job Configuration
 */
union cavm_bbxdx_config_0_105
{
    uint64_t u;
    struct cavm_bbxdx_config_0_105_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_0_105          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_105          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_105_s cn; */
};
typedef union cavm_bbxdx_config_0_105 cavm_bbxdx_config_0_105_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_105(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_105(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782348ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_105", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_105(a) cavm_bbxdx_config_0_105_t
#define bustype_CAVM_BBXDX_CONFIG_0_105(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_105(a) "BBXDX_CONFIG_0_105"
#define busnum_CAVM_BBXDX_CONFIG_0_105(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_105(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_106
 *
 * BBX4 Configuration Register 0106
 * Job Configuration
 */
union cavm_bbxdx_config_0_106
{
    uint64_t u;
    struct cavm_bbxdx_config_0_106_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_0_106          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_106          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_106_s cn; */
};
typedef union cavm_bbxdx_config_0_106 cavm_bbxdx_config_0_106_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_106(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_106(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782350ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_106", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_106(a) cavm_bbxdx_config_0_106_t
#define bustype_CAVM_BBXDX_CONFIG_0_106(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_106(a) "BBXDX_CONFIG_0_106"
#define busnum_CAVM_BBXDX_CONFIG_0_106(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_106(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_107
 *
 * BBX4 Configuration Register 0107
 * Job Configuration
 */
union cavm_bbxdx_config_0_107
{
    uint64_t u;
    struct cavm_bbxdx_config_0_107_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_0_107          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_107          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_107_s cn; */
};
typedef union cavm_bbxdx_config_0_107 cavm_bbxdx_config_0_107_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_107(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_107(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782358ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_107", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_107(a) cavm_bbxdx_config_0_107_t
#define bustype_CAVM_BBXDX_CONFIG_0_107(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_107(a) "BBXDX_CONFIG_0_107"
#define busnum_CAVM_BBXDX_CONFIG_0_107(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_107(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_108
 *
 * BBX4 Configuration Register 0108
 * Job Configuration
 */
union cavm_bbxdx_config_0_108
{
    uint64_t u;
    struct cavm_bbxdx_config_0_108_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_108_1        : 1;  /**< [ 63: 63](R/W) -- */
        uint64_t reserved_31_62        : 32;
        uint64_t config_0_108_0        : 31; /**< [ 30:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_108_0        : 31; /**< [ 30:  0](R/W) -- */
        uint64_t reserved_31_62        : 32;
        uint64_t config_0_108_1        : 1;  /**< [ 63: 63](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_108_s cn; */
};
typedef union cavm_bbxdx_config_0_108 cavm_bbxdx_config_0_108_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_108(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_108(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782360ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_108", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_108(a) cavm_bbxdx_config_0_108_t
#define bustype_CAVM_BBXDX_CONFIG_0_108(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_108(a) "BBXDX_CONFIG_0_108"
#define busnum_CAVM_BBXDX_CONFIG_0_108(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_108(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_11
 *
 * BBX4 Configuration Register 011
 * Job Configuration
 */
union cavm_bbxdx_config_0_11
{
    uint64_t u;
    struct cavm_bbxdx_config_0_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_11           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_11           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_11_s cn; */
};
typedef union cavm_bbxdx_config_0_11 cavm_bbxdx_config_0_11_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782058ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_11", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_11(a) cavm_bbxdx_config_0_11_t
#define bustype_CAVM_BBXDX_CONFIG_0_11(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_11(a) "BBXDX_CONFIG_0_11"
#define busnum_CAVM_BBXDX_CONFIG_0_11(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_11(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_12
 *
 * BBX4 Configuration Register 012
 * Job Configuration
 */
union cavm_bbxdx_config_0_12
{
    uint64_t u;
    struct cavm_bbxdx_config_0_12_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_12           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_12           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_12_s cn; */
};
typedef union cavm_bbxdx_config_0_12 cavm_bbxdx_config_0_12_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_12(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_12(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782060ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_12", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_12(a) cavm_bbxdx_config_0_12_t
#define bustype_CAVM_BBXDX_CONFIG_0_12(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_12(a) "BBXDX_CONFIG_0_12"
#define busnum_CAVM_BBXDX_CONFIG_0_12(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_12(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_13
 *
 * BBX4 Configuration Register 013
 * Job Configuration
 */
union cavm_bbxdx_config_0_13
{
    uint64_t u;
    struct cavm_bbxdx_config_0_13_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_13           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_13           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_13_s cn; */
};
typedef union cavm_bbxdx_config_0_13 cavm_bbxdx_config_0_13_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_13(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_13(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782068ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_13", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_13(a) cavm_bbxdx_config_0_13_t
#define bustype_CAVM_BBXDX_CONFIG_0_13(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_13(a) "BBXDX_CONFIG_0_13"
#define busnum_CAVM_BBXDX_CONFIG_0_13(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_13(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_14
 *
 * BBX4 Configuration Register 014
 * Job Configuration
 */
union cavm_bbxdx_config_0_14
{
    uint64_t u;
    struct cavm_bbxdx_config_0_14_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_14           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_14           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_14_s cn; */
};
typedef union cavm_bbxdx_config_0_14 cavm_bbxdx_config_0_14_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_14(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_14(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782070ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_14", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_14(a) cavm_bbxdx_config_0_14_t
#define bustype_CAVM_BBXDX_CONFIG_0_14(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_14(a) "BBXDX_CONFIG_0_14"
#define busnum_CAVM_BBXDX_CONFIG_0_14(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_14(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_15
 *
 * BBX4 Configuration Register 015
 * Job Configuration
 */
union cavm_bbxdx_config_0_15
{
    uint64_t u;
    struct cavm_bbxdx_config_0_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_15           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_15           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_15_s cn; */
};
typedef union cavm_bbxdx_config_0_15 cavm_bbxdx_config_0_15_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782078ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_15(a) cavm_bbxdx_config_0_15_t
#define bustype_CAVM_BBXDX_CONFIG_0_15(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_15(a) "BBXDX_CONFIG_0_15"
#define busnum_CAVM_BBXDX_CONFIG_0_15(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_15(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_16
 *
 * BBX4 Configuration Register 016
 * Job Configuration
 */
union cavm_bbxdx_config_0_16
{
    uint64_t u;
    struct cavm_bbxdx_config_0_16_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_16           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_16           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_16_s cn; */
};
typedef union cavm_bbxdx_config_0_16 cavm_bbxdx_config_0_16_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_16(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_16(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782080ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_16", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_16(a) cavm_bbxdx_config_0_16_t
#define bustype_CAVM_BBXDX_CONFIG_0_16(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_16(a) "BBXDX_CONFIG_0_16"
#define busnum_CAVM_BBXDX_CONFIG_0_16(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_16(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_17
 *
 * BBX4 Configuration Register 017
 * Job Configuration
 */
union cavm_bbxdx_config_0_17
{
    uint64_t u;
    struct cavm_bbxdx_config_0_17_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_17           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_17           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_17_s cn; */
};
typedef union cavm_bbxdx_config_0_17 cavm_bbxdx_config_0_17_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_17(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_17(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782088ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_17", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_17(a) cavm_bbxdx_config_0_17_t
#define bustype_CAVM_BBXDX_CONFIG_0_17(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_17(a) "BBXDX_CONFIG_0_17"
#define busnum_CAVM_BBXDX_CONFIG_0_17(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_17(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_18
 *
 * BBX4 Configuration Register 018
 * Job Configuration
 */
union cavm_bbxdx_config_0_18
{
    uint64_t u;
    struct cavm_bbxdx_config_0_18_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_18           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_18           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_18_s cn; */
};
typedef union cavm_bbxdx_config_0_18 cavm_bbxdx_config_0_18_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_18(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_18(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782090ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_18", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_18(a) cavm_bbxdx_config_0_18_t
#define bustype_CAVM_BBXDX_CONFIG_0_18(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_18(a) "BBXDX_CONFIG_0_18"
#define busnum_CAVM_BBXDX_CONFIG_0_18(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_18(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_19
 *
 * BBX4 Configuration Register 019
 * Job Configuration
 */
union cavm_bbxdx_config_0_19
{
    uint64_t u;
    struct cavm_bbxdx_config_0_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_19           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_19           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_19_s cn; */
};
typedef union cavm_bbxdx_config_0_19 cavm_bbxdx_config_0_19_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782098ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_19", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_19(a) cavm_bbxdx_config_0_19_t
#define bustype_CAVM_BBXDX_CONFIG_0_19(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_19(a) "BBXDX_CONFIG_0_19"
#define busnum_CAVM_BBXDX_CONFIG_0_19(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_19(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_2
 *
 * BBX4 Configuration Register 02
 * Job Configuration
 */
union cavm_bbxdx_config_0_2
{
    uint64_t u;
    struct cavm_bbxdx_config_0_2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_2            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_2            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_2_s cn; */
};
typedef union cavm_bbxdx_config_0_2 cavm_bbxdx_config_0_2_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782010ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_2", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_2(a) cavm_bbxdx_config_0_2_t
#define bustype_CAVM_BBXDX_CONFIG_0_2(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_2(a) "BBXDX_CONFIG_0_2"
#define busnum_CAVM_BBXDX_CONFIG_0_2(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_2(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_20
 *
 * BBX4 Configuration Register 020
 * Job Configuration
 */
union cavm_bbxdx_config_0_20
{
    uint64_t u;
    struct cavm_bbxdx_config_0_20_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_20           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_20           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_20_s cn; */
};
typedef union cavm_bbxdx_config_0_20 cavm_bbxdx_config_0_20_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_20(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_20(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_20", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_20(a) cavm_bbxdx_config_0_20_t
#define bustype_CAVM_BBXDX_CONFIG_0_20(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_20(a) "BBXDX_CONFIG_0_20"
#define busnum_CAVM_BBXDX_CONFIG_0_20(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_20(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_21
 *
 * BBX4 Configuration Register 021
 * Job Configuration
 */
union cavm_bbxdx_config_0_21
{
    uint64_t u;
    struct cavm_bbxdx_config_0_21_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_21           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_21           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_21_s cn; */
};
typedef union cavm_bbxdx_config_0_21 cavm_bbxdx_config_0_21_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_21(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_21(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_21", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_21(a) cavm_bbxdx_config_0_21_t
#define bustype_CAVM_BBXDX_CONFIG_0_21(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_21(a) "BBXDX_CONFIG_0_21"
#define busnum_CAVM_BBXDX_CONFIG_0_21(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_21(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_22
 *
 * BBX4 Configuration Register 022
 * Job Configuration
 */
union cavm_bbxdx_config_0_22
{
    uint64_t u;
    struct cavm_bbxdx_config_0_22_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_22           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_22           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_22_s cn; */
};
typedef union cavm_bbxdx_config_0_22 cavm_bbxdx_config_0_22_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_22(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_22(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_22", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_22(a) cavm_bbxdx_config_0_22_t
#define bustype_CAVM_BBXDX_CONFIG_0_22(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_22(a) "BBXDX_CONFIG_0_22"
#define busnum_CAVM_BBXDX_CONFIG_0_22(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_22(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_23
 *
 * BBX4 Configuration Register 023
 * Job Configuration
 */
union cavm_bbxdx_config_0_23
{
    uint64_t u;
    struct cavm_bbxdx_config_0_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_23           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_23           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_23_s cn; */
};
typedef union cavm_bbxdx_config_0_23 cavm_bbxdx_config_0_23_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_23(a) cavm_bbxdx_config_0_23_t
#define bustype_CAVM_BBXDX_CONFIG_0_23(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_23(a) "BBXDX_CONFIG_0_23"
#define busnum_CAVM_BBXDX_CONFIG_0_23(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_23(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_24
 *
 * BBX4 Configuration Register 024
 * Job Configuration
 */
union cavm_bbxdx_config_0_24
{
    uint64_t u;
    struct cavm_bbxdx_config_0_24_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_24           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_24           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_24_s cn; */
};
typedef union cavm_bbxdx_config_0_24 cavm_bbxdx_config_0_24_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_24(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_24(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_24", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_24(a) cavm_bbxdx_config_0_24_t
#define bustype_CAVM_BBXDX_CONFIG_0_24(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_24(a) "BBXDX_CONFIG_0_24"
#define busnum_CAVM_BBXDX_CONFIG_0_24(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_24(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_25
 *
 * BBX4 Configuration Register 025
 * Job Configuration
 */
union cavm_bbxdx_config_0_25
{
    uint64_t u;
    struct cavm_bbxdx_config_0_25_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_25           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_25           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_25_s cn; */
};
typedef union cavm_bbxdx_config_0_25 cavm_bbxdx_config_0_25_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_25(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_25(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_25", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_25(a) cavm_bbxdx_config_0_25_t
#define bustype_CAVM_BBXDX_CONFIG_0_25(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_25(a) "BBXDX_CONFIG_0_25"
#define busnum_CAVM_BBXDX_CONFIG_0_25(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_25(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_26
 *
 * BBX4 Configuration Register 026
 * Job Configuration
 */
union cavm_bbxdx_config_0_26
{
    uint64_t u;
    struct cavm_bbxdx_config_0_26_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_26           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_26           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_26_s cn; */
};
typedef union cavm_bbxdx_config_0_26 cavm_bbxdx_config_0_26_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_26(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_26(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_26", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_26(a) cavm_bbxdx_config_0_26_t
#define bustype_CAVM_BBXDX_CONFIG_0_26(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_26(a) "BBXDX_CONFIG_0_26"
#define busnum_CAVM_BBXDX_CONFIG_0_26(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_26(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_27
 *
 * BBX4 Configuration Register 027
 * Job Configuration
 */
union cavm_bbxdx_config_0_27
{
    uint64_t u;
    struct cavm_bbxdx_config_0_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_27           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_27           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_27_s cn; */
};
typedef union cavm_bbxdx_config_0_27 cavm_bbxdx_config_0_27_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_27", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_27(a) cavm_bbxdx_config_0_27_t
#define bustype_CAVM_BBXDX_CONFIG_0_27(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_27(a) "BBXDX_CONFIG_0_27"
#define busnum_CAVM_BBXDX_CONFIG_0_27(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_27(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_28
 *
 * BBX4 Configuration Register 028
 * Job Configuration
 */
union cavm_bbxdx_config_0_28
{
    uint64_t u;
    struct cavm_bbxdx_config_0_28_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_28           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_28           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_28_s cn; */
};
typedef union cavm_bbxdx_config_0_28 cavm_bbxdx_config_0_28_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_28(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_28(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_28", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_28(a) cavm_bbxdx_config_0_28_t
#define bustype_CAVM_BBXDX_CONFIG_0_28(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_28(a) "BBXDX_CONFIG_0_28"
#define busnum_CAVM_BBXDX_CONFIG_0_28(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_28(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_29
 *
 * BBX4 Configuration Register 029
 * Job Configuration
 */
union cavm_bbxdx_config_0_29
{
    uint64_t u;
    struct cavm_bbxdx_config_0_29_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_29           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_29           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_29_s cn; */
};
typedef union cavm_bbxdx_config_0_29 cavm_bbxdx_config_0_29_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_29(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_29(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_29", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_29(a) cavm_bbxdx_config_0_29_t
#define bustype_CAVM_BBXDX_CONFIG_0_29(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_29(a) "BBXDX_CONFIG_0_29"
#define busnum_CAVM_BBXDX_CONFIG_0_29(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_29(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_3
 *
 * BBX4 Configuration Register 03
 * Job Configuration
 */
union cavm_bbxdx_config_0_3
{
    uint64_t u;
    struct cavm_bbxdx_config_0_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_3            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_3            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_3_s cn; */
};
typedef union cavm_bbxdx_config_0_3 cavm_bbxdx_config_0_3_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_3(a) cavm_bbxdx_config_0_3_t
#define bustype_CAVM_BBXDX_CONFIG_0_3(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_3(a) "BBXDX_CONFIG_0_3"
#define busnum_CAVM_BBXDX_CONFIG_0_3(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_3(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_30
 *
 * BBX4 Configuration Register 030
 * Job Configuration
 */
union cavm_bbxdx_config_0_30
{
    uint64_t u;
    struct cavm_bbxdx_config_0_30_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_30           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_30           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_30_s cn; */
};
typedef union cavm_bbxdx_config_0_30 cavm_bbxdx_config_0_30_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_30(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_30(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_30", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_30(a) cavm_bbxdx_config_0_30_t
#define bustype_CAVM_BBXDX_CONFIG_0_30(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_30(a) "BBXDX_CONFIG_0_30"
#define busnum_CAVM_BBXDX_CONFIG_0_30(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_30(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_31
 *
 * BBX4 Configuration Register 031
 * Job Configuration
 */
union cavm_bbxdx_config_0_31
{
    uint64_t u;
    struct cavm_bbxdx_config_0_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_31           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_31           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_31_s cn; */
};
typedef union cavm_bbxdx_config_0_31 cavm_bbxdx_config_0_31_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437820f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_31(a) cavm_bbxdx_config_0_31_t
#define bustype_CAVM_BBXDX_CONFIG_0_31(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_31(a) "BBXDX_CONFIG_0_31"
#define busnum_CAVM_BBXDX_CONFIG_0_31(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_31(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_32
 *
 * BBX4 Configuration Register 032
 * Job Configuration
 */
union cavm_bbxdx_config_0_32
{
    uint64_t u;
    struct cavm_bbxdx_config_0_32_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_32           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_32           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_32_s cn; */
};
typedef union cavm_bbxdx_config_0_32 cavm_bbxdx_config_0_32_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_32(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_32(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782100ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_32", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_32(a) cavm_bbxdx_config_0_32_t
#define bustype_CAVM_BBXDX_CONFIG_0_32(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_32(a) "BBXDX_CONFIG_0_32"
#define busnum_CAVM_BBXDX_CONFIG_0_32(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_32(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_33
 *
 * BBX4 Configuration Register 033
 * Job Configuration
 */
union cavm_bbxdx_config_0_33
{
    uint64_t u;
    struct cavm_bbxdx_config_0_33_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_33           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_33           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_33_s cn; */
};
typedef union cavm_bbxdx_config_0_33 cavm_bbxdx_config_0_33_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_33(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_33(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782108ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_33", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_33(a) cavm_bbxdx_config_0_33_t
#define bustype_CAVM_BBXDX_CONFIG_0_33(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_33(a) "BBXDX_CONFIG_0_33"
#define busnum_CAVM_BBXDX_CONFIG_0_33(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_33(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_34
 *
 * BBX4 Configuration Register 034
 * Job Configuration
 */
union cavm_bbxdx_config_0_34
{
    uint64_t u;
    struct cavm_bbxdx_config_0_34_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_34           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_34           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_34_s cn; */
};
typedef union cavm_bbxdx_config_0_34 cavm_bbxdx_config_0_34_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_34(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_34(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782110ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_34", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_34(a) cavm_bbxdx_config_0_34_t
#define bustype_CAVM_BBXDX_CONFIG_0_34(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_34(a) "BBXDX_CONFIG_0_34"
#define busnum_CAVM_BBXDX_CONFIG_0_34(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_34(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_35
 *
 * BBX4 Configuration Register 035
 * Job Configuration
 */
union cavm_bbxdx_config_0_35
{
    uint64_t u;
    struct cavm_bbxdx_config_0_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_35           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_35           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_35_s cn; */
};
typedef union cavm_bbxdx_config_0_35 cavm_bbxdx_config_0_35_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782118ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_35", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_35(a) cavm_bbxdx_config_0_35_t
#define bustype_CAVM_BBXDX_CONFIG_0_35(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_35(a) "BBXDX_CONFIG_0_35"
#define busnum_CAVM_BBXDX_CONFIG_0_35(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_35(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_36
 *
 * BBX4 Configuration Register 036
 * Job Configuration
 */
union cavm_bbxdx_config_0_36
{
    uint64_t u;
    struct cavm_bbxdx_config_0_36_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_36           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_36           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_36_s cn; */
};
typedef union cavm_bbxdx_config_0_36 cavm_bbxdx_config_0_36_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_36(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_36(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782120ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_36", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_36(a) cavm_bbxdx_config_0_36_t
#define bustype_CAVM_BBXDX_CONFIG_0_36(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_36(a) "BBXDX_CONFIG_0_36"
#define busnum_CAVM_BBXDX_CONFIG_0_36(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_36(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_37
 *
 * BBX4 Configuration Register 037
 * Job Configuration
 */
union cavm_bbxdx_config_0_37
{
    uint64_t u;
    struct cavm_bbxdx_config_0_37_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_37           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_37           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_37_s cn; */
};
typedef union cavm_bbxdx_config_0_37 cavm_bbxdx_config_0_37_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_37(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_37(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782128ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_37", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_37(a) cavm_bbxdx_config_0_37_t
#define bustype_CAVM_BBXDX_CONFIG_0_37(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_37(a) "BBXDX_CONFIG_0_37"
#define busnum_CAVM_BBXDX_CONFIG_0_37(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_37(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_38
 *
 * BBX4 Configuration Register 038
 * Job Configuration
 */
union cavm_bbxdx_config_0_38
{
    uint64_t u;
    struct cavm_bbxdx_config_0_38_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_38           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_38           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_38_s cn; */
};
typedef union cavm_bbxdx_config_0_38 cavm_bbxdx_config_0_38_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_38(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_38(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782130ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_38", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_38(a) cavm_bbxdx_config_0_38_t
#define bustype_CAVM_BBXDX_CONFIG_0_38(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_38(a) "BBXDX_CONFIG_0_38"
#define busnum_CAVM_BBXDX_CONFIG_0_38(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_38(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_39
 *
 * BBX4 Configuration Register 039
 * Job Configuration
 */
union cavm_bbxdx_config_0_39
{
    uint64_t u;
    struct cavm_bbxdx_config_0_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_39           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_39           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_39_s cn; */
};
typedef union cavm_bbxdx_config_0_39 cavm_bbxdx_config_0_39_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782138ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_39(a) cavm_bbxdx_config_0_39_t
#define bustype_CAVM_BBXDX_CONFIG_0_39(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_39(a) "BBXDX_CONFIG_0_39"
#define busnum_CAVM_BBXDX_CONFIG_0_39(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_39(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_4
 *
 * BBX4 Configuration Register 04
 * Job Configuration
 */
union cavm_bbxdx_config_0_4
{
    uint64_t u;
    struct cavm_bbxdx_config_0_4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_4            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_4            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_4_s cn; */
};
typedef union cavm_bbxdx_config_0_4 cavm_bbxdx_config_0_4_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_4(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782020ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_4", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_4(a) cavm_bbxdx_config_0_4_t
#define bustype_CAVM_BBXDX_CONFIG_0_4(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_4(a) "BBXDX_CONFIG_0_4"
#define busnum_CAVM_BBXDX_CONFIG_0_4(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_4(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_40
 *
 * BBX4 Configuration Register 040
 * Job Configuration
 */
union cavm_bbxdx_config_0_40
{
    uint64_t u;
    struct cavm_bbxdx_config_0_40_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_40           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_40           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_40_s cn; */
};
typedef union cavm_bbxdx_config_0_40 cavm_bbxdx_config_0_40_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_40(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_40(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782140ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_40", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_40(a) cavm_bbxdx_config_0_40_t
#define bustype_CAVM_BBXDX_CONFIG_0_40(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_40(a) "BBXDX_CONFIG_0_40"
#define busnum_CAVM_BBXDX_CONFIG_0_40(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_40(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_41
 *
 * BBX4 Configuration Register 041
 * Job Configuration
 */
union cavm_bbxdx_config_0_41
{
    uint64_t u;
    struct cavm_bbxdx_config_0_41_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_41           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_41           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_41_s cn; */
};
typedef union cavm_bbxdx_config_0_41 cavm_bbxdx_config_0_41_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_41(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_41(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782148ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_41", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_41(a) cavm_bbxdx_config_0_41_t
#define bustype_CAVM_BBXDX_CONFIG_0_41(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_41(a) "BBXDX_CONFIG_0_41"
#define busnum_CAVM_BBXDX_CONFIG_0_41(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_41(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_42
 *
 * BBX4 Configuration Register 042
 * Job Configuration
 */
union cavm_bbxdx_config_0_42
{
    uint64_t u;
    struct cavm_bbxdx_config_0_42_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_42           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_42           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_42_s cn; */
};
typedef union cavm_bbxdx_config_0_42 cavm_bbxdx_config_0_42_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_42(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_42(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782150ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_42", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_42(a) cavm_bbxdx_config_0_42_t
#define bustype_CAVM_BBXDX_CONFIG_0_42(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_42(a) "BBXDX_CONFIG_0_42"
#define busnum_CAVM_BBXDX_CONFIG_0_42(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_42(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_43
 *
 * BBX4 Configuration Register 043
 * Job Configuration
 */
union cavm_bbxdx_config_0_43
{
    uint64_t u;
    struct cavm_bbxdx_config_0_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_43           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_43           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_43_s cn; */
};
typedef union cavm_bbxdx_config_0_43 cavm_bbxdx_config_0_43_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782158ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_43", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_43(a) cavm_bbxdx_config_0_43_t
#define bustype_CAVM_BBXDX_CONFIG_0_43(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_43(a) "BBXDX_CONFIG_0_43"
#define busnum_CAVM_BBXDX_CONFIG_0_43(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_43(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_44
 *
 * BBX4 Configuration Register 044
 * Job Configuration
 */
union cavm_bbxdx_config_0_44
{
    uint64_t u;
    struct cavm_bbxdx_config_0_44_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_44           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_44           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_44_s cn; */
};
typedef union cavm_bbxdx_config_0_44 cavm_bbxdx_config_0_44_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_44(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_44(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782160ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_44", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_44(a) cavm_bbxdx_config_0_44_t
#define bustype_CAVM_BBXDX_CONFIG_0_44(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_44(a) "BBXDX_CONFIG_0_44"
#define busnum_CAVM_BBXDX_CONFIG_0_44(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_44(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_45
 *
 * BBX4 Configuration Register 045
 * Job Configuration
 */
union cavm_bbxdx_config_0_45
{
    uint64_t u;
    struct cavm_bbxdx_config_0_45_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_45           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_45           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_45_s cn; */
};
typedef union cavm_bbxdx_config_0_45 cavm_bbxdx_config_0_45_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_45(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_45(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782168ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_45", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_45(a) cavm_bbxdx_config_0_45_t
#define bustype_CAVM_BBXDX_CONFIG_0_45(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_45(a) "BBXDX_CONFIG_0_45"
#define busnum_CAVM_BBXDX_CONFIG_0_45(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_45(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_46
 *
 * BBX4 Configuration Register 046
 * Job Configuration
 */
union cavm_bbxdx_config_0_46
{
    uint64_t u;
    struct cavm_bbxdx_config_0_46_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_46           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_46           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_46_s cn; */
};
typedef union cavm_bbxdx_config_0_46 cavm_bbxdx_config_0_46_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_46(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_46(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782170ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_46", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_46(a) cavm_bbxdx_config_0_46_t
#define bustype_CAVM_BBXDX_CONFIG_0_46(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_46(a) "BBXDX_CONFIG_0_46"
#define busnum_CAVM_BBXDX_CONFIG_0_46(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_46(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_47
 *
 * BBX4 Configuration Register 047
 * Job Configuration
 */
union cavm_bbxdx_config_0_47
{
    uint64_t u;
    struct cavm_bbxdx_config_0_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_47           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_47           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_47_s cn; */
};
typedef union cavm_bbxdx_config_0_47 cavm_bbxdx_config_0_47_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782178ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_47(a) cavm_bbxdx_config_0_47_t
#define bustype_CAVM_BBXDX_CONFIG_0_47(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_47(a) "BBXDX_CONFIG_0_47"
#define busnum_CAVM_BBXDX_CONFIG_0_47(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_47(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_48
 *
 * BBX4 Configuration Register 048
 * Job Configuration
 */
union cavm_bbxdx_config_0_48
{
    uint64_t u;
    struct cavm_bbxdx_config_0_48_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_48           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_48           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_48_s cn; */
};
typedef union cavm_bbxdx_config_0_48 cavm_bbxdx_config_0_48_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_48(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_48(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782180ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_48", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_48(a) cavm_bbxdx_config_0_48_t
#define bustype_CAVM_BBXDX_CONFIG_0_48(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_48(a) "BBXDX_CONFIG_0_48"
#define busnum_CAVM_BBXDX_CONFIG_0_48(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_48(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_49
 *
 * BBX4 Configuration Register 049
 * Job Configuration
 */
union cavm_bbxdx_config_0_49
{
    uint64_t u;
    struct cavm_bbxdx_config_0_49_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_49           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_49           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_49_s cn; */
};
typedef union cavm_bbxdx_config_0_49 cavm_bbxdx_config_0_49_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_49(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_49(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782188ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_49", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_49(a) cavm_bbxdx_config_0_49_t
#define bustype_CAVM_BBXDX_CONFIG_0_49(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_49(a) "BBXDX_CONFIG_0_49"
#define busnum_CAVM_BBXDX_CONFIG_0_49(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_49(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_5
 *
 * BBX4 Configuration Register 05
 * Job Configuration
 */
union cavm_bbxdx_config_0_5
{
    uint64_t u;
    struct cavm_bbxdx_config_0_5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_5            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_5            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_5_s cn; */
};
typedef union cavm_bbxdx_config_0_5 cavm_bbxdx_config_0_5_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_5(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782028ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_5", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_5(a) cavm_bbxdx_config_0_5_t
#define bustype_CAVM_BBXDX_CONFIG_0_5(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_5(a) "BBXDX_CONFIG_0_5"
#define busnum_CAVM_BBXDX_CONFIG_0_5(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_5(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_50
 *
 * BBX4 Configuration Register 050
 * Job Configuration
 */
union cavm_bbxdx_config_0_50
{
    uint64_t u;
    struct cavm_bbxdx_config_0_50_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_50_3         : 16; /**< [ 63: 48](R/W) -- */
        uint64_t reserved_41_47        : 7;
        uint64_t config_0_50_2         : 17; /**< [ 40: 24](R/W) -- */
        uint64_t reserved_23           : 1;
        uint64_t config_0_50_1         : 15; /**< [ 22:  8](R/W) -- */
        uint64_t reserved_2_7          : 6;
        uint64_t config_0_50_0         : 2;  /**< [  1:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_50_0         : 2;  /**< [  1:  0](R/W) -- */
        uint64_t reserved_2_7          : 6;
        uint64_t config_0_50_1         : 15; /**< [ 22:  8](R/W) -- */
        uint64_t reserved_23           : 1;
        uint64_t config_0_50_2         : 17; /**< [ 40: 24](R/W) -- */
        uint64_t reserved_41_47        : 7;
        uint64_t config_0_50_3         : 16; /**< [ 63: 48](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_50_s cn; */
};
typedef union cavm_bbxdx_config_0_50 cavm_bbxdx_config_0_50_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_50(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_50(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782190ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_50", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_50(a) cavm_bbxdx_config_0_50_t
#define bustype_CAVM_BBXDX_CONFIG_0_50(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_50(a) "BBXDX_CONFIG_0_50"
#define busnum_CAVM_BBXDX_CONFIG_0_50(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_50(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_51
 *
 * BBX4 Configuration Register 051
 * Job Configuration
 */
union cavm_bbxdx_config_0_51
{
    uint64_t u;
    struct cavm_bbxdx_config_0_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_51           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_51           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_51_s cn; */
};
typedef union cavm_bbxdx_config_0_51 cavm_bbxdx_config_0_51_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782198ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_51", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_51(a) cavm_bbxdx_config_0_51_t
#define bustype_CAVM_BBXDX_CONFIG_0_51(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_51(a) "BBXDX_CONFIG_0_51"
#define busnum_CAVM_BBXDX_CONFIG_0_51(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_51(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_52
 *
 * BBX4 Configuration Register 052
 * Job Configuration
 */
union cavm_bbxdx_config_0_52
{
    uint64_t u;
    struct cavm_bbxdx_config_0_52_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_52_1         : 32; /**< [ 63: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_52_0         : 29; /**< [ 28:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_52_0         : 29; /**< [ 28:  0](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_52_1         : 32; /**< [ 63: 32](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_52_s cn; */
};
typedef union cavm_bbxdx_config_0_52 cavm_bbxdx_config_0_52_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_52(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_52(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_52", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_52(a) cavm_bbxdx_config_0_52_t
#define bustype_CAVM_BBXDX_CONFIG_0_52(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_52(a) "BBXDX_CONFIG_0_52"
#define busnum_CAVM_BBXDX_CONFIG_0_52(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_52(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_53
 *
 * BBX4 Configuration Register 053
 * Job Configuration
 */
union cavm_bbxdx_config_0_53
{
    uint64_t u;
    struct cavm_bbxdx_config_0_53_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_53_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_53_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_53_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_53_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_53_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_53_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_53_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_53_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_53_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_53_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_53_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_53_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_53_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_53_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_53_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_53_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_53_s cn; */
};
typedef union cavm_bbxdx_config_0_53 cavm_bbxdx_config_0_53_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_53(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_53(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_53", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_53(a) cavm_bbxdx_config_0_53_t
#define bustype_CAVM_BBXDX_CONFIG_0_53(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_53(a) "BBXDX_CONFIG_0_53"
#define busnum_CAVM_BBXDX_CONFIG_0_53(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_53(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_54
 *
 * BBX4 Configuration Register 054
 * Job Configuration
 */
union cavm_bbxdx_config_0_54
{
    uint64_t u;
    struct cavm_bbxdx_config_0_54_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_54_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_54_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_54_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_54_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_54_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_54_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_54_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_54_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_54_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_54_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_54_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_54_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_54_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_54_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_54_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_54_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_54_s cn; */
};
typedef union cavm_bbxdx_config_0_54 cavm_bbxdx_config_0_54_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_54(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_54(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_54", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_54(a) cavm_bbxdx_config_0_54_t
#define bustype_CAVM_BBXDX_CONFIG_0_54(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_54(a) "BBXDX_CONFIG_0_54"
#define busnum_CAVM_BBXDX_CONFIG_0_54(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_54(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_55
 *
 * BBX4 Configuration Register 055
 * Job Configuration
 */
union cavm_bbxdx_config_0_55
{
    uint64_t u;
    struct cavm_bbxdx_config_0_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_55_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_55_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_55_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_55_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_55_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_55_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_55_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_55_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_55_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_55_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_55_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_55_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_55_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_55_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_55_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_55_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_55_s cn; */
};
typedef union cavm_bbxdx_config_0_55 cavm_bbxdx_config_0_55_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_55(a) cavm_bbxdx_config_0_55_t
#define bustype_CAVM_BBXDX_CONFIG_0_55(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_55(a) "BBXDX_CONFIG_0_55"
#define busnum_CAVM_BBXDX_CONFIG_0_55(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_55(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_56
 *
 * BBX4 Configuration Register 056
 * Job Configuration
 */
union cavm_bbxdx_config_0_56
{
    uint64_t u;
    struct cavm_bbxdx_config_0_56_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_56_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_56_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_56_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_56_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_56_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_56_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_56_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_56_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_56_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_56_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_56_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_56_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_56_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_56_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_56_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_56_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_56_s cn; */
};
typedef union cavm_bbxdx_config_0_56 cavm_bbxdx_config_0_56_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_56(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_56(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_56", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_56(a) cavm_bbxdx_config_0_56_t
#define bustype_CAVM_BBXDX_CONFIG_0_56(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_56(a) "BBXDX_CONFIG_0_56"
#define busnum_CAVM_BBXDX_CONFIG_0_56(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_56(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_57
 *
 * BBX4 Configuration Register 057
 * Job Configuration
 */
union cavm_bbxdx_config_0_57
{
    uint64_t u;
    struct cavm_bbxdx_config_0_57_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_57_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_57_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_57_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_57_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_57_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_57_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_57_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_57_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_57_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_57_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_57_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_57_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_57_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_57_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_57_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_57_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_57_s cn; */
};
typedef union cavm_bbxdx_config_0_57 cavm_bbxdx_config_0_57_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_57(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_57(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_57", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_57(a) cavm_bbxdx_config_0_57_t
#define bustype_CAVM_BBXDX_CONFIG_0_57(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_57(a) "BBXDX_CONFIG_0_57"
#define busnum_CAVM_BBXDX_CONFIG_0_57(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_57(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_58
 *
 * BBX4 Configuration Register 058
 * Job Configuration
 */
union cavm_bbxdx_config_0_58
{
    uint64_t u;
    struct cavm_bbxdx_config_0_58_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_58_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_58_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_58_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_58_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_58_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_58_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_58_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_58_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_58_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_58_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_58_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_58_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_58_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_58_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_58_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_58_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_58_s cn; */
};
typedef union cavm_bbxdx_config_0_58 cavm_bbxdx_config_0_58_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_58(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_58(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_58", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_58(a) cavm_bbxdx_config_0_58_t
#define bustype_CAVM_BBXDX_CONFIG_0_58(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_58(a) "BBXDX_CONFIG_0_58"
#define busnum_CAVM_BBXDX_CONFIG_0_58(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_58(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_59
 *
 * BBX4 Configuration Register 059
 * Job Configuration
 */
union cavm_bbxdx_config_0_59
{
    uint64_t u;
    struct cavm_bbxdx_config_0_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_59_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_59_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_59_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_59_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_59_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_59_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_59_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_59_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_59_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_59_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_59_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_59_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_59_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_59_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_59_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_59_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_59_s cn; */
};
typedef union cavm_bbxdx_config_0_59 cavm_bbxdx_config_0_59_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_59", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_59(a) cavm_bbxdx_config_0_59_t
#define bustype_CAVM_BBXDX_CONFIG_0_59(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_59(a) "BBXDX_CONFIG_0_59"
#define busnum_CAVM_BBXDX_CONFIG_0_59(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_59(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_6
 *
 * BBX4 Configuration Register 06
 * Job Configuration
 */
union cavm_bbxdx_config_0_6
{
    uint64_t u;
    struct cavm_bbxdx_config_0_6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_6            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_6            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_6_s cn; */
};
typedef union cavm_bbxdx_config_0_6 cavm_bbxdx_config_0_6_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_6(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_6", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_6(a) cavm_bbxdx_config_0_6_t
#define bustype_CAVM_BBXDX_CONFIG_0_6(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_6(a) "BBXDX_CONFIG_0_6"
#define busnum_CAVM_BBXDX_CONFIG_0_6(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_6(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_60
 *
 * BBX4 Configuration Register 060
 * Job Configuration
 */
union cavm_bbxdx_config_0_60
{
    uint64_t u;
    struct cavm_bbxdx_config_0_60_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_60_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_60_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_60_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_60_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_60_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_60_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_60_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_60_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_60_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_60_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_60_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_60_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_60_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_60_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_60_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_60_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_60_s cn; */
};
typedef union cavm_bbxdx_config_0_60 cavm_bbxdx_config_0_60_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_60(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_60(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_60", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_60(a) cavm_bbxdx_config_0_60_t
#define bustype_CAVM_BBXDX_CONFIG_0_60(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_60(a) "BBXDX_CONFIG_0_60"
#define busnum_CAVM_BBXDX_CONFIG_0_60(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_60(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_61
 *
 * BBX4 Configuration Register 061
 * Job Configuration
 */
union cavm_bbxdx_config_0_61
{
    uint64_t u;
    struct cavm_bbxdx_config_0_61_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_61_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_61_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_61_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_61_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_61_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_61_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_61_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_61_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_61_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_61_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_61_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_61_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_61_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_61_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_61_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_61_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_61_s cn; */
};
typedef union cavm_bbxdx_config_0_61 cavm_bbxdx_config_0_61_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_61(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_61(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_61", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_61(a) cavm_bbxdx_config_0_61_t
#define bustype_CAVM_BBXDX_CONFIG_0_61(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_61(a) "BBXDX_CONFIG_0_61"
#define busnum_CAVM_BBXDX_CONFIG_0_61(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_61(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_62
 *
 * BBX4 Configuration Register 062
 * Job Configuration
 */
union cavm_bbxdx_config_0_62
{
    uint64_t u;
    struct cavm_bbxdx_config_0_62_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_62_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_62_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_62_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_62_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_62_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_62_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_62_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_62_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_62_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_62_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_62_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_62_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_62_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_62_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_62_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_62_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_62_s cn; */
};
typedef union cavm_bbxdx_config_0_62 cavm_bbxdx_config_0_62_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_62(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_62(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_62", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_62(a) cavm_bbxdx_config_0_62_t
#define bustype_CAVM_BBXDX_CONFIG_0_62(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_62(a) "BBXDX_CONFIG_0_62"
#define busnum_CAVM_BBXDX_CONFIG_0_62(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_62(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_63
 *
 * BBX4 Configuration Register 063
 * Job Configuration
 */
union cavm_bbxdx_config_0_63
{
    uint64_t u;
    struct cavm_bbxdx_config_0_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_63_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_63_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_63_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_63_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_63_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_63_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_63_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_63_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_63_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_63_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_63_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_63_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_63_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_63_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_63_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_63_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_63_s cn; */
};
typedef union cavm_bbxdx_config_0_63 cavm_bbxdx_config_0_63_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437821f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_63(a) cavm_bbxdx_config_0_63_t
#define bustype_CAVM_BBXDX_CONFIG_0_63(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_63(a) "BBXDX_CONFIG_0_63"
#define busnum_CAVM_BBXDX_CONFIG_0_63(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_63(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_64
 *
 * BBX4 Configuration Register 064
 * Job Configuration
 */
union cavm_bbxdx_config_0_64
{
    uint64_t u;
    struct cavm_bbxdx_config_0_64_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_64_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_64_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_64_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_64_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_64_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_64_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_64_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_64_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_64_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_64_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_64_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_64_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_64_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_64_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_64_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_64_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_64_s cn; */
};
typedef union cavm_bbxdx_config_0_64 cavm_bbxdx_config_0_64_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_64(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_64(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782200ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_64", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_64(a) cavm_bbxdx_config_0_64_t
#define bustype_CAVM_BBXDX_CONFIG_0_64(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_64(a) "BBXDX_CONFIG_0_64"
#define busnum_CAVM_BBXDX_CONFIG_0_64(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_64(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_65
 *
 * BBX4 Configuration Register 065
 * Job Configuration
 */
union cavm_bbxdx_config_0_65
{
    uint64_t u;
    struct cavm_bbxdx_config_0_65_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_65_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_65_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_65_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_65_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_65_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_65_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_65_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_65_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_65_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_65_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_65_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_65_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_65_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_65_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_65_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_65_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_65_s cn; */
};
typedef union cavm_bbxdx_config_0_65 cavm_bbxdx_config_0_65_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_65(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_65(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782208ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_65", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_65(a) cavm_bbxdx_config_0_65_t
#define bustype_CAVM_BBXDX_CONFIG_0_65(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_65(a) "BBXDX_CONFIG_0_65"
#define busnum_CAVM_BBXDX_CONFIG_0_65(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_65(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_66
 *
 * BBX4 Configuration Register 066
 * Job Configuration
 */
union cavm_bbxdx_config_0_66
{
    uint64_t u;
    struct cavm_bbxdx_config_0_66_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_0_66_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_66_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_66_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_66_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_66_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_66_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_66_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_66_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_66_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_66_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_66_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_66_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_66_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_66_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_66_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_66_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_66_s cn; */
};
typedef union cavm_bbxdx_config_0_66 cavm_bbxdx_config_0_66_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_66(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_66(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782210ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_66", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_66(a) cavm_bbxdx_config_0_66_t
#define bustype_CAVM_BBXDX_CONFIG_0_66(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_66(a) "BBXDX_CONFIG_0_66"
#define busnum_CAVM_BBXDX_CONFIG_0_66(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_66(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_67
 *
 * BBX4 Configuration Register 067
 * Job Configuration
 */
union cavm_bbxdx_config_0_67
{
    uint64_t u;
    struct cavm_bbxdx_config_0_67_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_67_7         : 8;  /**< [ 63: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_67_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_67_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_67_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_67_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_67_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_67_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_67_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_67_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_67_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_67_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_67_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_67_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_67_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_67_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_67_7         : 8;  /**< [ 63: 56](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_67_s cn; */
};
typedef union cavm_bbxdx_config_0_67 cavm_bbxdx_config_0_67_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_67(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_67(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782218ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_67", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_67(a) cavm_bbxdx_config_0_67_t
#define bustype_CAVM_BBXDX_CONFIG_0_67(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_67(a) "BBXDX_CONFIG_0_67"
#define busnum_CAVM_BBXDX_CONFIG_0_67(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_67(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_68
 *
 * BBX4 Configuration Register 068
 * Job Configuration
 */
union cavm_bbxdx_config_0_68
{
    uint64_t u;
    struct cavm_bbxdx_config_0_68_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_68_7         : 8;  /**< [ 63: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_68_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_68_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_68_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_68_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_68_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_68_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_68_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_68_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_0_68_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_0_68_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_0_68_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_0_68_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_0_68_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_0_68_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_0_68_7         : 8;  /**< [ 63: 56](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_68_s cn; */
};
typedef union cavm_bbxdx_config_0_68 cavm_bbxdx_config_0_68_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_68(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_68(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782220ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_68", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_68(a) cavm_bbxdx_config_0_68_t
#define bustype_CAVM_BBXDX_CONFIG_0_68(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_68(a) "BBXDX_CONFIG_0_68"
#define busnum_CAVM_BBXDX_CONFIG_0_68(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_68(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_69
 *
 * BBX4 Configuration Register 069
 * Job Configuration
 */
union cavm_bbxdx_config_0_69
{
    uint64_t u;
    struct cavm_bbxdx_config_0_69_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_69           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_69           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_69_s cn; */
};
typedef union cavm_bbxdx_config_0_69 cavm_bbxdx_config_0_69_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_69(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_69(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782228ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_69", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_69(a) cavm_bbxdx_config_0_69_t
#define bustype_CAVM_BBXDX_CONFIG_0_69(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_69(a) "BBXDX_CONFIG_0_69"
#define busnum_CAVM_BBXDX_CONFIG_0_69(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_69(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_7
 *
 * BBX4 Configuration Register 07
 * Job Configuration
 */
union cavm_bbxdx_config_0_7
{
    uint64_t u;
    struct cavm_bbxdx_config_0_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_7            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_7            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_7_s cn; */
};
typedef union cavm_bbxdx_config_0_7 cavm_bbxdx_config_0_7_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_7(a) cavm_bbxdx_config_0_7_t
#define bustype_CAVM_BBXDX_CONFIG_0_7(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_7(a) "BBXDX_CONFIG_0_7"
#define busnum_CAVM_BBXDX_CONFIG_0_7(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_7(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_70
 *
 * BBX4 Configuration Register 070
 * Job Configuration
 */
union cavm_bbxdx_config_0_70
{
    uint64_t u;
    struct cavm_bbxdx_config_0_70_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_70           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_70           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_70_s cn; */
};
typedef union cavm_bbxdx_config_0_70 cavm_bbxdx_config_0_70_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_70(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_70(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782230ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_70", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_70(a) cavm_bbxdx_config_0_70_t
#define bustype_CAVM_BBXDX_CONFIG_0_70(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_70(a) "BBXDX_CONFIG_0_70"
#define busnum_CAVM_BBXDX_CONFIG_0_70(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_70(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_71
 *
 * BBX4 Configuration Register 071
 * Job Configuration
 */
union cavm_bbxdx_config_0_71
{
    uint64_t u;
    struct cavm_bbxdx_config_0_71_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_71           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_71           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_71_s cn; */
};
typedef union cavm_bbxdx_config_0_71 cavm_bbxdx_config_0_71_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_71(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_71(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782238ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_71", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_71(a) cavm_bbxdx_config_0_71_t
#define bustype_CAVM_BBXDX_CONFIG_0_71(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_71(a) "BBXDX_CONFIG_0_71"
#define busnum_CAVM_BBXDX_CONFIG_0_71(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_71(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_72
 *
 * BBX4 Configuration Register 072
 * Job Configuration
 */
union cavm_bbxdx_config_0_72
{
    uint64_t u;
    struct cavm_bbxdx_config_0_72_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_72           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_72           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_72_s cn; */
};
typedef union cavm_bbxdx_config_0_72 cavm_bbxdx_config_0_72_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_72(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_72(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782240ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_72", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_72(a) cavm_bbxdx_config_0_72_t
#define bustype_CAVM_BBXDX_CONFIG_0_72(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_72(a) "BBXDX_CONFIG_0_72"
#define busnum_CAVM_BBXDX_CONFIG_0_72(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_72(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_73
 *
 * BBX4 Configuration Register 073
 * Job Configuration
 */
union cavm_bbxdx_config_0_73
{
    uint64_t u;
    struct cavm_bbxdx_config_0_73_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_73           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_73           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_73_s cn; */
};
typedef union cavm_bbxdx_config_0_73 cavm_bbxdx_config_0_73_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_73(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_73(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782248ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_73", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_73(a) cavm_bbxdx_config_0_73_t
#define bustype_CAVM_BBXDX_CONFIG_0_73(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_73(a) "BBXDX_CONFIG_0_73"
#define busnum_CAVM_BBXDX_CONFIG_0_73(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_73(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_74
 *
 * BBX4 Configuration Register 074
 * Job Configuration
 */
union cavm_bbxdx_config_0_74
{
    uint64_t u;
    struct cavm_bbxdx_config_0_74_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_74           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_74           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_74_s cn; */
};
typedef union cavm_bbxdx_config_0_74 cavm_bbxdx_config_0_74_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_74(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_74(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782250ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_74", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_74(a) cavm_bbxdx_config_0_74_t
#define bustype_CAVM_BBXDX_CONFIG_0_74(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_74(a) "BBXDX_CONFIG_0_74"
#define busnum_CAVM_BBXDX_CONFIG_0_74(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_74(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_75
 *
 * BBX4 Configuration Register 075
 * Job Configuration
 */
union cavm_bbxdx_config_0_75
{
    uint64_t u;
    struct cavm_bbxdx_config_0_75_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_75           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_75           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_75_s cn; */
};
typedef union cavm_bbxdx_config_0_75 cavm_bbxdx_config_0_75_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_75(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_75(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782258ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_75", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_75(a) cavm_bbxdx_config_0_75_t
#define bustype_CAVM_BBXDX_CONFIG_0_75(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_75(a) "BBXDX_CONFIG_0_75"
#define busnum_CAVM_BBXDX_CONFIG_0_75(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_75(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_76
 *
 * BBX4 Configuration Register 076
 * Job Configuration
 */
union cavm_bbxdx_config_0_76
{
    uint64_t u;
    struct cavm_bbxdx_config_0_76_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_76           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_76           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_76_s cn; */
};
typedef union cavm_bbxdx_config_0_76 cavm_bbxdx_config_0_76_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_76(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_76(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782260ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_76", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_76(a) cavm_bbxdx_config_0_76_t
#define bustype_CAVM_BBXDX_CONFIG_0_76(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_76(a) "BBXDX_CONFIG_0_76"
#define busnum_CAVM_BBXDX_CONFIG_0_76(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_76(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_77
 *
 * BBX4 Configuration Register 077
 * Job Configuration
 */
union cavm_bbxdx_config_0_77
{
    uint64_t u;
    struct cavm_bbxdx_config_0_77_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_77           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_77           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_77_s cn; */
};
typedef union cavm_bbxdx_config_0_77 cavm_bbxdx_config_0_77_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_77(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_77(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782268ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_77", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_77(a) cavm_bbxdx_config_0_77_t
#define bustype_CAVM_BBXDX_CONFIG_0_77(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_77(a) "BBXDX_CONFIG_0_77"
#define busnum_CAVM_BBXDX_CONFIG_0_77(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_77(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_78
 *
 * BBX4 Configuration Register 078
 * Job Configuration
 */
union cavm_bbxdx_config_0_78
{
    uint64_t u;
    struct cavm_bbxdx_config_0_78_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_78           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_78           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_78_s cn; */
};
typedef union cavm_bbxdx_config_0_78 cavm_bbxdx_config_0_78_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_78(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_78(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782270ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_78", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_78(a) cavm_bbxdx_config_0_78_t
#define bustype_CAVM_BBXDX_CONFIG_0_78(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_78(a) "BBXDX_CONFIG_0_78"
#define busnum_CAVM_BBXDX_CONFIG_0_78(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_78(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_79
 *
 * BBX4 Configuration Register 079
 * Job Configuration
 */
union cavm_bbxdx_config_0_79
{
    uint64_t u;
    struct cavm_bbxdx_config_0_79_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_79           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_79           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_79_s cn; */
};
typedef union cavm_bbxdx_config_0_79 cavm_bbxdx_config_0_79_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_79(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_79(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782278ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_79", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_79(a) cavm_bbxdx_config_0_79_t
#define bustype_CAVM_BBXDX_CONFIG_0_79(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_79(a) "BBXDX_CONFIG_0_79"
#define busnum_CAVM_BBXDX_CONFIG_0_79(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_79(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_8
 *
 * BBX4 Configuration Register 08
 * Job Configuration
 */
union cavm_bbxdx_config_0_8
{
    uint64_t u;
    struct cavm_bbxdx_config_0_8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_8            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_8            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_8_s cn; */
};
typedef union cavm_bbxdx_config_0_8 cavm_bbxdx_config_0_8_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_8(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_8(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_8", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_8(a) cavm_bbxdx_config_0_8_t
#define bustype_CAVM_BBXDX_CONFIG_0_8(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_8(a) "BBXDX_CONFIG_0_8"
#define busnum_CAVM_BBXDX_CONFIG_0_8(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_8(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_80
 *
 * BBX4 Configuration Register 080
 * Job Configuration
 */
union cavm_bbxdx_config_0_80
{
    uint64_t u;
    struct cavm_bbxdx_config_0_80_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_80           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_80           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_80_s cn; */
};
typedef union cavm_bbxdx_config_0_80 cavm_bbxdx_config_0_80_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_80(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_80(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782280ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_80", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_80(a) cavm_bbxdx_config_0_80_t
#define bustype_CAVM_BBXDX_CONFIG_0_80(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_80(a) "BBXDX_CONFIG_0_80"
#define busnum_CAVM_BBXDX_CONFIG_0_80(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_80(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_81
 *
 * BBX4 Configuration Register 081
 * Job Configuration
 */
union cavm_bbxdx_config_0_81
{
    uint64_t u;
    struct cavm_bbxdx_config_0_81_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_81           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_81           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_81_s cn; */
};
typedef union cavm_bbxdx_config_0_81 cavm_bbxdx_config_0_81_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_81(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_81(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782288ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_81", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_81(a) cavm_bbxdx_config_0_81_t
#define bustype_CAVM_BBXDX_CONFIG_0_81(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_81(a) "BBXDX_CONFIG_0_81"
#define busnum_CAVM_BBXDX_CONFIG_0_81(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_81(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_82
 *
 * BBX4 Configuration Register 082
 * Job Configuration
 */
union cavm_bbxdx_config_0_82
{
    uint64_t u;
    struct cavm_bbxdx_config_0_82_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_82           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_82           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_82_s cn; */
};
typedef union cavm_bbxdx_config_0_82 cavm_bbxdx_config_0_82_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_82(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_82(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782290ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_82", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_82(a) cavm_bbxdx_config_0_82_t
#define bustype_CAVM_BBXDX_CONFIG_0_82(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_82(a) "BBXDX_CONFIG_0_82"
#define busnum_CAVM_BBXDX_CONFIG_0_82(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_82(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_83
 *
 * BBX4 Configuration Register 083
 * Job Configuration
 */
union cavm_bbxdx_config_0_83
{
    uint64_t u;
    struct cavm_bbxdx_config_0_83_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_83           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_83           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_83_s cn; */
};
typedef union cavm_bbxdx_config_0_83 cavm_bbxdx_config_0_83_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_83(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_83(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782298ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_83", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_83(a) cavm_bbxdx_config_0_83_t
#define bustype_CAVM_BBXDX_CONFIG_0_83(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_83(a) "BBXDX_CONFIG_0_83"
#define busnum_CAVM_BBXDX_CONFIG_0_83(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_83(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_84
 *
 * BBX4 Configuration Register 084
 * Job Configuration
 */
union cavm_bbxdx_config_0_84
{
    uint64_t u;
    struct cavm_bbxdx_config_0_84_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_84           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_84           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_84_s cn; */
};
typedef union cavm_bbxdx_config_0_84 cavm_bbxdx_config_0_84_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_84(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_84(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_84", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_84(a) cavm_bbxdx_config_0_84_t
#define bustype_CAVM_BBXDX_CONFIG_0_84(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_84(a) "BBXDX_CONFIG_0_84"
#define busnum_CAVM_BBXDX_CONFIG_0_84(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_84(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_85
 *
 * BBX4 Configuration Register 085
 * Job Configuration
 */
union cavm_bbxdx_config_0_85
{
    uint64_t u;
    struct cavm_bbxdx_config_0_85_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_85           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_85           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_85_s cn; */
};
typedef union cavm_bbxdx_config_0_85 cavm_bbxdx_config_0_85_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_85(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_85(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_85", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_85(a) cavm_bbxdx_config_0_85_t
#define bustype_CAVM_BBXDX_CONFIG_0_85(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_85(a) "BBXDX_CONFIG_0_85"
#define busnum_CAVM_BBXDX_CONFIG_0_85(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_85(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_86
 *
 * BBX4 Configuration Register 086
 * Job Configuration
 */
union cavm_bbxdx_config_0_86
{
    uint64_t u;
    struct cavm_bbxdx_config_0_86_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_86           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_86           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_86_s cn; */
};
typedef union cavm_bbxdx_config_0_86 cavm_bbxdx_config_0_86_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_86(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_86(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_86", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_86(a) cavm_bbxdx_config_0_86_t
#define bustype_CAVM_BBXDX_CONFIG_0_86(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_86(a) "BBXDX_CONFIG_0_86"
#define busnum_CAVM_BBXDX_CONFIG_0_86(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_86(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_87
 *
 * BBX4 Configuration Register 087
 * Job Configuration
 */
union cavm_bbxdx_config_0_87
{
    uint64_t u;
    struct cavm_bbxdx_config_0_87_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_87           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_87           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_87_s cn; */
};
typedef union cavm_bbxdx_config_0_87 cavm_bbxdx_config_0_87_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_87(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_87(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_87", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_87(a) cavm_bbxdx_config_0_87_t
#define bustype_CAVM_BBXDX_CONFIG_0_87(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_87(a) "BBXDX_CONFIG_0_87"
#define busnum_CAVM_BBXDX_CONFIG_0_87(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_87(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_88
 *
 * BBX4 Configuration Register 088
 * Job Configuration
 */
union cavm_bbxdx_config_0_88
{
    uint64_t u;
    struct cavm_bbxdx_config_0_88_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_88           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_88           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_88_s cn; */
};
typedef union cavm_bbxdx_config_0_88 cavm_bbxdx_config_0_88_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_88(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_88(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_88", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_88(a) cavm_bbxdx_config_0_88_t
#define bustype_CAVM_BBXDX_CONFIG_0_88(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_88(a) "BBXDX_CONFIG_0_88"
#define busnum_CAVM_BBXDX_CONFIG_0_88(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_88(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_89
 *
 * BBX4 Configuration Register 089
 * Job Configuration
 */
union cavm_bbxdx_config_0_89
{
    uint64_t u;
    struct cavm_bbxdx_config_0_89_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_89           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_89           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_89_s cn; */
};
typedef union cavm_bbxdx_config_0_89 cavm_bbxdx_config_0_89_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_89(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_89(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_89", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_89(a) cavm_bbxdx_config_0_89_t
#define bustype_CAVM_BBXDX_CONFIG_0_89(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_89(a) "BBXDX_CONFIG_0_89"
#define busnum_CAVM_BBXDX_CONFIG_0_89(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_89(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_9
 *
 * BBX4 Configuration Register 09
 * Job Configuration
 */
union cavm_bbxdx_config_0_9
{
    uint64_t u;
    struct cavm_bbxdx_config_0_9_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_0_9            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_9            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_9_s cn; */
};
typedef union cavm_bbxdx_config_0_9 cavm_bbxdx_config_0_9_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_9(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_9(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_9", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_9(a) cavm_bbxdx_config_0_9_t
#define bustype_CAVM_BBXDX_CONFIG_0_9(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_9(a) "BBXDX_CONFIG_0_9"
#define busnum_CAVM_BBXDX_CONFIG_0_9(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_9(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_90
 *
 * BBX4 Configuration Register 090
 * Job Configuration
 */
union cavm_bbxdx_config_0_90
{
    uint64_t u;
    struct cavm_bbxdx_config_0_90_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_90           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_90           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_90_s cn; */
};
typedef union cavm_bbxdx_config_0_90 cavm_bbxdx_config_0_90_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_90(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_90(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_90", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_90(a) cavm_bbxdx_config_0_90_t
#define bustype_CAVM_BBXDX_CONFIG_0_90(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_90(a) "BBXDX_CONFIG_0_90"
#define busnum_CAVM_BBXDX_CONFIG_0_90(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_90(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_91
 *
 * BBX4 Configuration Register 091
 * Job Configuration
 */
union cavm_bbxdx_config_0_91
{
    uint64_t u;
    struct cavm_bbxdx_config_0_91_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_91           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_91           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_91_s cn; */
};
typedef union cavm_bbxdx_config_0_91 cavm_bbxdx_config_0_91_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_91(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_91(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_91", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_91(a) cavm_bbxdx_config_0_91_t
#define bustype_CAVM_BBXDX_CONFIG_0_91(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_91(a) "BBXDX_CONFIG_0_91"
#define busnum_CAVM_BBXDX_CONFIG_0_91(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_91(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_92
 *
 * BBX4 Configuration Register 092
 * Job Configuration
 */
union cavm_bbxdx_config_0_92
{
    uint64_t u;
    struct cavm_bbxdx_config_0_92_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_92           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_92           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_92_s cn; */
};
typedef union cavm_bbxdx_config_0_92 cavm_bbxdx_config_0_92_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_92(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_92(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_92", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_92(a) cavm_bbxdx_config_0_92_t
#define bustype_CAVM_BBXDX_CONFIG_0_92(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_92(a) "BBXDX_CONFIG_0_92"
#define busnum_CAVM_BBXDX_CONFIG_0_92(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_92(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_93
 *
 * BBX4 Configuration Register 093
 * Job Configuration
 */
union cavm_bbxdx_config_0_93
{
    uint64_t u;
    struct cavm_bbxdx_config_0_93_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_93           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_93           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_93_s cn; */
};
typedef union cavm_bbxdx_config_0_93 cavm_bbxdx_config_0_93_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_93(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_93(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_93", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_93(a) cavm_bbxdx_config_0_93_t
#define bustype_CAVM_BBXDX_CONFIG_0_93(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_93(a) "BBXDX_CONFIG_0_93"
#define busnum_CAVM_BBXDX_CONFIG_0_93(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_93(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_94
 *
 * BBX4 Configuration Register 094
 * Job Configuration
 */
union cavm_bbxdx_config_0_94
{
    uint64_t u;
    struct cavm_bbxdx_config_0_94_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_94           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_94           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_94_s cn; */
};
typedef union cavm_bbxdx_config_0_94 cavm_bbxdx_config_0_94_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_94(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_94(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_94", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_94(a) cavm_bbxdx_config_0_94_t
#define bustype_CAVM_BBXDX_CONFIG_0_94(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_94(a) "BBXDX_CONFIG_0_94"
#define busnum_CAVM_BBXDX_CONFIG_0_94(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_94(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_95
 *
 * BBX4 Configuration Register 095
 * Job Configuration
 */
union cavm_bbxdx_config_0_95
{
    uint64_t u;
    struct cavm_bbxdx_config_0_95_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_0_95           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_95           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_95_s cn; */
};
typedef union cavm_bbxdx_config_0_95 cavm_bbxdx_config_0_95_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_95(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_95(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437822f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_95", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_95(a) cavm_bbxdx_config_0_95_t
#define bustype_CAVM_BBXDX_CONFIG_0_95(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_95(a) "BBXDX_CONFIG_0_95"
#define busnum_CAVM_BBXDX_CONFIG_0_95(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_95(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_96
 *
 * BBX4 Configuration Register 096
 * Job Configuration
 */
union cavm_bbxdx_config_0_96
{
    uint64_t u;
    struct cavm_bbxdx_config_0_96_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_0_96           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_96           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_96_s cn; */
};
typedef union cavm_bbxdx_config_0_96 cavm_bbxdx_config_0_96_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_96(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_96(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782300ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_96", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_96(a) cavm_bbxdx_config_0_96_t
#define bustype_CAVM_BBXDX_CONFIG_0_96(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_96(a) "BBXDX_CONFIG_0_96"
#define busnum_CAVM_BBXDX_CONFIG_0_96(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_96(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_97
 *
 * BBX4 Configuration Register 097
 * Job Configuration
 */
union cavm_bbxdx_config_0_97
{
    uint64_t u;
    struct cavm_bbxdx_config_0_97_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_0_97           : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_97           : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_97_s cn; */
};
typedef union cavm_bbxdx_config_0_97 cavm_bbxdx_config_0_97_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_97(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_97(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782308ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_97", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_97(a) cavm_bbxdx_config_0_97_t
#define bustype_CAVM_BBXDX_CONFIG_0_97(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_97(a) "BBXDX_CONFIG_0_97"
#define busnum_CAVM_BBXDX_CONFIG_0_97(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_97(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_98
 *
 * BBX4 Configuration Register 098
 * Job Configuration
 */
union cavm_bbxdx_config_0_98
{
    uint64_t u;
    struct cavm_bbxdx_config_0_98_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_0_98           : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_98           : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_98_s cn; */
};
typedef union cavm_bbxdx_config_0_98 cavm_bbxdx_config_0_98_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_98(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_98(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782310ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_98", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_98(a) cavm_bbxdx_config_0_98_t
#define bustype_CAVM_BBXDX_CONFIG_0_98(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_98(a) "BBXDX_CONFIG_0_98"
#define busnum_CAVM_BBXDX_CONFIG_0_98(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_98(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_0_99
 *
 * BBX4 Configuration Register 099
 * Job Configuration
 */
union cavm_bbxdx_config_0_99
{
    uint64_t u;
    struct cavm_bbxdx_config_0_99_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t config_0_99           : 9;  /**< [  8:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_0_99           : 9;  /**< [  8:  0](R/W) -- */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_0_99_s cn; */
};
typedef union cavm_bbxdx_config_0_99 cavm_bbxdx_config_0_99_t;

static inline uint64_t CAVM_BBXDX_CONFIG_0_99(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_0_99(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043782318ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_0_99", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_0_99(a) cavm_bbxdx_config_0_99_t
#define bustype_CAVM_BBXDX_CONFIG_0_99(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_0_99(a) "BBXDX_CONFIG_0_99"
#define busnum_CAVM_BBXDX_CONFIG_0_99(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_0_99(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_0
 *
 * BBX4 Configuration Register 10
 * Job Configuration
 */
union cavm_bbxdx_config_1_0
{
    uint64_t u;
    struct cavm_bbxdx_config_1_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t config_1_0_1          : 17; /**< [ 32: 16](R/W) -- */
        uint64_t reserved_4_15         : 12;
        uint64_t config_1_0_0          : 4;  /**< [  3:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_0_0          : 4;  /**< [  3:  0](R/W) -- */
        uint64_t reserved_4_15         : 12;
        uint64_t config_1_0_1          : 17; /**< [ 32: 16](R/W) -- */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_0_s cn; */
};
typedef union cavm_bbxdx_config_1_0 cavm_bbxdx_config_1_0_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_0(a) cavm_bbxdx_config_1_0_t
#define bustype_CAVM_BBXDX_CONFIG_1_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_0(a) "BBXDX_CONFIG_1_0"
#define busnum_CAVM_BBXDX_CONFIG_1_0(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_1
 *
 * BBX4 Configuration Register 11
 * Job Configuration
 */
union cavm_bbxdx_config_1_1
{
    uint64_t u;
    struct cavm_bbxdx_config_1_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_1_1_3          : 28; /**< [ 59: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_1_2          : 13; /**< [ 28: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_1_1          : 7;  /**< [ 12:  6](R/W) -- */
        uint64_t reserved_5            : 1;
        uint64_t config_1_1_0          : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_1_0          : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5            : 1;
        uint64_t config_1_1_1          : 7;  /**< [ 12:  6](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_1_2          : 13; /**< [ 28: 16](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_1_3          : 28; /**< [ 59: 32](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_1_s cn; */
};
typedef union cavm_bbxdx_config_1_1 cavm_bbxdx_config_1_1_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_1(a) cavm_bbxdx_config_1_1_t
#define bustype_CAVM_BBXDX_CONFIG_1_1(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_1(a) "BBXDX_CONFIG_1_1"
#define busnum_CAVM_BBXDX_CONFIG_1_1(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_1(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_10
 *
 * BBX4 Configuration Register 110
 * Job Configuration
 */
union cavm_bbxdx_config_1_10
{
    uint64_t u;
    struct cavm_bbxdx_config_1_10_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_10           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_10           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_10_s cn; */
};
typedef union cavm_bbxdx_config_1_10 cavm_bbxdx_config_1_10_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_10(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_10(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784050ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_10", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_10(a) cavm_bbxdx_config_1_10_t
#define bustype_CAVM_BBXDX_CONFIG_1_10(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_10(a) "BBXDX_CONFIG_1_10"
#define busnum_CAVM_BBXDX_CONFIG_1_10(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_10(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_100
 *
 * BBX4 Configuration Register 1100
 * Job Configuration
 */
union cavm_bbxdx_config_1_100
{
    uint64_t u;
    struct cavm_bbxdx_config_1_100_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_100_8        : 1;  /**< [ 63: 63](R/W) -- */
        uint64_t reserved_61_62        : 2;
        uint64_t config_1_100_7        : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_100_6        : 1;  /**< [ 52: 52](R/W) -- */
        uint64_t reserved_49_51        : 3;
        uint64_t config_1_100_5        : 1;  /**< [ 48: 48](R/W) -- */
        uint64_t reserved_47           : 1;
        uint64_t config_1_100_4        : 7;  /**< [ 46: 40](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_1_100_3        : 7;  /**< [ 38: 32](R/W) -- */
        uint64_t reserved_23_31        : 9;
        uint64_t config_1_100_2        : 7;  /**< [ 22: 16](R/W) -- */
        uint64_t reserved_10_15        : 6;
        uint64_t config_1_100_1        : 2;  /**< [  9:  8](R/W) -- */
        uint64_t reserved_7            : 1;
        uint64_t config_1_100_0        : 7;  /**< [  6:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_100_0        : 7;  /**< [  6:  0](R/W) -- */
        uint64_t reserved_7            : 1;
        uint64_t config_1_100_1        : 2;  /**< [  9:  8](R/W) -- */
        uint64_t reserved_10_15        : 6;
        uint64_t config_1_100_2        : 7;  /**< [ 22: 16](R/W) -- */
        uint64_t reserved_23_31        : 9;
        uint64_t config_1_100_3        : 7;  /**< [ 38: 32](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_1_100_4        : 7;  /**< [ 46: 40](R/W) -- */
        uint64_t reserved_47           : 1;
        uint64_t config_1_100_5        : 1;  /**< [ 48: 48](R/W) -- */
        uint64_t reserved_49_51        : 3;
        uint64_t config_1_100_6        : 1;  /**< [ 52: 52](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_100_7        : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_62        : 2;
        uint64_t config_1_100_8        : 1;  /**< [ 63: 63](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_100_s cn; */
};
typedef union cavm_bbxdx_config_1_100 cavm_bbxdx_config_1_100_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_100(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_100(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784320ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_100", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_100(a) cavm_bbxdx_config_1_100_t
#define bustype_CAVM_BBXDX_CONFIG_1_100(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_100(a) "BBXDX_CONFIG_1_100"
#define busnum_CAVM_BBXDX_CONFIG_1_100(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_100(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_101
 *
 * BBX4 Configuration Register 1101
 * Job Configuration
 */
union cavm_bbxdx_config_1_101
{
    uint64_t u;
    struct cavm_bbxdx_config_1_101_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_1_101          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_101          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_101_s cn; */
};
typedef union cavm_bbxdx_config_1_101 cavm_bbxdx_config_1_101_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_101(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_101(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784328ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_101", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_101(a) cavm_bbxdx_config_1_101_t
#define bustype_CAVM_BBXDX_CONFIG_1_101(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_101(a) "BBXDX_CONFIG_1_101"
#define busnum_CAVM_BBXDX_CONFIG_1_101(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_101(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_102
 *
 * BBX4 Configuration Register 1102
 * Job Configuration
 */
union cavm_bbxdx_config_1_102
{
    uint64_t u;
    struct cavm_bbxdx_config_1_102_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_1_102          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_102          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_102_s cn; */
};
typedef union cavm_bbxdx_config_1_102 cavm_bbxdx_config_1_102_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_102(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_102(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784330ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_102", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_102(a) cavm_bbxdx_config_1_102_t
#define bustype_CAVM_BBXDX_CONFIG_1_102(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_102(a) "BBXDX_CONFIG_1_102"
#define busnum_CAVM_BBXDX_CONFIG_1_102(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_102(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_103
 *
 * BBX4 Configuration Register 1103
 * Job Configuration
 */
union cavm_bbxdx_config_1_103
{
    uint64_t u;
    struct cavm_bbxdx_config_1_103_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_1_103          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_103          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_103_s cn; */
};
typedef union cavm_bbxdx_config_1_103 cavm_bbxdx_config_1_103_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_103(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_103(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784338ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_103", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_103(a) cavm_bbxdx_config_1_103_t
#define bustype_CAVM_BBXDX_CONFIG_1_103(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_103(a) "BBXDX_CONFIG_1_103"
#define busnum_CAVM_BBXDX_CONFIG_1_103(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_103(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_104
 *
 * BBX4 Configuration Register 1104
 * Job Configuration
 */
union cavm_bbxdx_config_1_104
{
    uint64_t u;
    struct cavm_bbxdx_config_1_104_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_1_1084         : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_1084         : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_104_s cn; */
};
typedef union cavm_bbxdx_config_1_104 cavm_bbxdx_config_1_104_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_104(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_104(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784340ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_104", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_104(a) cavm_bbxdx_config_1_104_t
#define bustype_CAVM_BBXDX_CONFIG_1_104(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_104(a) "BBXDX_CONFIG_1_104"
#define busnum_CAVM_BBXDX_CONFIG_1_104(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_104(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_105
 *
 * BBX4 Configuration Register 1105
 * Job Configuration
 */
union cavm_bbxdx_config_1_105
{
    uint64_t u;
    struct cavm_bbxdx_config_1_105_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_1_105          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_105          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_105_s cn; */
};
typedef union cavm_bbxdx_config_1_105 cavm_bbxdx_config_1_105_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_105(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_105(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784348ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_105", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_105(a) cavm_bbxdx_config_1_105_t
#define bustype_CAVM_BBXDX_CONFIG_1_105(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_105(a) "BBXDX_CONFIG_1_105"
#define busnum_CAVM_BBXDX_CONFIG_1_105(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_105(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_106
 *
 * BBX4 Configuration Register 1106
 * Job Configuration
 */
union cavm_bbxdx_config_1_106
{
    uint64_t u;
    struct cavm_bbxdx_config_1_106_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_1_106          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_106          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_106_s cn; */
};
typedef union cavm_bbxdx_config_1_106 cavm_bbxdx_config_1_106_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_106(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_106(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784350ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_106", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_106(a) cavm_bbxdx_config_1_106_t
#define bustype_CAVM_BBXDX_CONFIG_1_106(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_106(a) "BBXDX_CONFIG_1_106"
#define busnum_CAVM_BBXDX_CONFIG_1_106(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_106(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_107
 *
 * BBX4 Configuration Register 1107
 * Job Configuration
 */
union cavm_bbxdx_config_1_107
{
    uint64_t u;
    struct cavm_bbxdx_config_1_107_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_1_107          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_107          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_107_s cn; */
};
typedef union cavm_bbxdx_config_1_107 cavm_bbxdx_config_1_107_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_107(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_107(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784358ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_107", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_107(a) cavm_bbxdx_config_1_107_t
#define bustype_CAVM_BBXDX_CONFIG_1_107(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_107(a) "BBXDX_CONFIG_1_107"
#define busnum_CAVM_BBXDX_CONFIG_1_107(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_107(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_108
 *
 * BBX4 Configuration Register 1108
 * Job Configuration
 */
union cavm_bbxdx_config_1_108
{
    uint64_t u;
    struct cavm_bbxdx_config_1_108_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_108_1        : 1;  /**< [ 63: 63](R/W) -- */
        uint64_t reserved_31_62        : 32;
        uint64_t config_1_108_0        : 31; /**< [ 30:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_108_0        : 31; /**< [ 30:  0](R/W) -- */
        uint64_t reserved_31_62        : 32;
        uint64_t config_1_108_1        : 1;  /**< [ 63: 63](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_108_s cn; */
};
typedef union cavm_bbxdx_config_1_108 cavm_bbxdx_config_1_108_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_108(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_108(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784360ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_108", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_108(a) cavm_bbxdx_config_1_108_t
#define bustype_CAVM_BBXDX_CONFIG_1_108(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_108(a) "BBXDX_CONFIG_1_108"
#define busnum_CAVM_BBXDX_CONFIG_1_108(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_108(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_11
 *
 * BBX4 Configuration Register 111
 * Job Configuration
 */
union cavm_bbxdx_config_1_11
{
    uint64_t u;
    struct cavm_bbxdx_config_1_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_11           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_11           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_11_s cn; */
};
typedef union cavm_bbxdx_config_1_11 cavm_bbxdx_config_1_11_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784058ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_11", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_11(a) cavm_bbxdx_config_1_11_t
#define bustype_CAVM_BBXDX_CONFIG_1_11(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_11(a) "BBXDX_CONFIG_1_11"
#define busnum_CAVM_BBXDX_CONFIG_1_11(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_11(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_12
 *
 * BBX4 Configuration Register 112
 * Job Configuration
 */
union cavm_bbxdx_config_1_12
{
    uint64_t u;
    struct cavm_bbxdx_config_1_12_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_12           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_12           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_12_s cn; */
};
typedef union cavm_bbxdx_config_1_12 cavm_bbxdx_config_1_12_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_12(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_12(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784060ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_12", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_12(a) cavm_bbxdx_config_1_12_t
#define bustype_CAVM_BBXDX_CONFIG_1_12(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_12(a) "BBXDX_CONFIG_1_12"
#define busnum_CAVM_BBXDX_CONFIG_1_12(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_12(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_13
 *
 * BBX4 Configuration Register 113
 * Job Configuration
 */
union cavm_bbxdx_config_1_13
{
    uint64_t u;
    struct cavm_bbxdx_config_1_13_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_13           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_13           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_13_s cn; */
};
typedef union cavm_bbxdx_config_1_13 cavm_bbxdx_config_1_13_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_13(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_13(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784068ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_13", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_13(a) cavm_bbxdx_config_1_13_t
#define bustype_CAVM_BBXDX_CONFIG_1_13(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_13(a) "BBXDX_CONFIG_1_13"
#define busnum_CAVM_BBXDX_CONFIG_1_13(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_13(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_14
 *
 * BBX4 Configuration Register 114
 * Job Configuration
 */
union cavm_bbxdx_config_1_14
{
    uint64_t u;
    struct cavm_bbxdx_config_1_14_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_14           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_14           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_14_s cn; */
};
typedef union cavm_bbxdx_config_1_14 cavm_bbxdx_config_1_14_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_14(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_14(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784070ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_14", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_14(a) cavm_bbxdx_config_1_14_t
#define bustype_CAVM_BBXDX_CONFIG_1_14(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_14(a) "BBXDX_CONFIG_1_14"
#define busnum_CAVM_BBXDX_CONFIG_1_14(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_14(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_15
 *
 * BBX4 Configuration Register 115
 * Job Configuration
 */
union cavm_bbxdx_config_1_15
{
    uint64_t u;
    struct cavm_bbxdx_config_1_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_15           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_15           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_15_s cn; */
};
typedef union cavm_bbxdx_config_1_15 cavm_bbxdx_config_1_15_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784078ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_15(a) cavm_bbxdx_config_1_15_t
#define bustype_CAVM_BBXDX_CONFIG_1_15(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_15(a) "BBXDX_CONFIG_1_15"
#define busnum_CAVM_BBXDX_CONFIG_1_15(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_15(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_16
 *
 * BBX4 Configuration Register 116
 * Job Configuration
 */
union cavm_bbxdx_config_1_16
{
    uint64_t u;
    struct cavm_bbxdx_config_1_16_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_16           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_16           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_16_s cn; */
};
typedef union cavm_bbxdx_config_1_16 cavm_bbxdx_config_1_16_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_16(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_16(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784080ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_16", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_16(a) cavm_bbxdx_config_1_16_t
#define bustype_CAVM_BBXDX_CONFIG_1_16(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_16(a) "BBXDX_CONFIG_1_16"
#define busnum_CAVM_BBXDX_CONFIG_1_16(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_16(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_17
 *
 * BBX4 Configuration Register 117
 * Job Configuration
 */
union cavm_bbxdx_config_1_17
{
    uint64_t u;
    struct cavm_bbxdx_config_1_17_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_17           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_17           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_17_s cn; */
};
typedef union cavm_bbxdx_config_1_17 cavm_bbxdx_config_1_17_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_17(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_17(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784088ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_17", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_17(a) cavm_bbxdx_config_1_17_t
#define bustype_CAVM_BBXDX_CONFIG_1_17(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_17(a) "BBXDX_CONFIG_1_17"
#define busnum_CAVM_BBXDX_CONFIG_1_17(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_17(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_18
 *
 * BBX4 Configuration Register 118
 * Job Configuration
 */
union cavm_bbxdx_config_1_18
{
    uint64_t u;
    struct cavm_bbxdx_config_1_18_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_18           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_18           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_18_s cn; */
};
typedef union cavm_bbxdx_config_1_18 cavm_bbxdx_config_1_18_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_18(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_18(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784090ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_18", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_18(a) cavm_bbxdx_config_1_18_t
#define bustype_CAVM_BBXDX_CONFIG_1_18(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_18(a) "BBXDX_CONFIG_1_18"
#define busnum_CAVM_BBXDX_CONFIG_1_18(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_18(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_19
 *
 * BBX4 Configuration Register 119
 * Job Configuration
 */
union cavm_bbxdx_config_1_19
{
    uint64_t u;
    struct cavm_bbxdx_config_1_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_19           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_19           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_19_s cn; */
};
typedef union cavm_bbxdx_config_1_19 cavm_bbxdx_config_1_19_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784098ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_19", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_19(a) cavm_bbxdx_config_1_19_t
#define bustype_CAVM_BBXDX_CONFIG_1_19(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_19(a) "BBXDX_CONFIG_1_19"
#define busnum_CAVM_BBXDX_CONFIG_1_19(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_19(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_2
 *
 * BBX4 Configuration Register 12
 * Job Configuration
 */
union cavm_bbxdx_config_1_2
{
    uint64_t u;
    struct cavm_bbxdx_config_1_2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_2            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_2            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_2_s cn; */
};
typedef union cavm_bbxdx_config_1_2 cavm_bbxdx_config_1_2_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784010ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_2", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_2(a) cavm_bbxdx_config_1_2_t
#define bustype_CAVM_BBXDX_CONFIG_1_2(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_2(a) "BBXDX_CONFIG_1_2"
#define busnum_CAVM_BBXDX_CONFIG_1_2(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_2(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_20
 *
 * BBX4 Configuration Register 120
 * Job Configuration
 */
union cavm_bbxdx_config_1_20
{
    uint64_t u;
    struct cavm_bbxdx_config_1_20_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_20           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_20           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_20_s cn; */
};
typedef union cavm_bbxdx_config_1_20 cavm_bbxdx_config_1_20_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_20(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_20(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_20", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_20(a) cavm_bbxdx_config_1_20_t
#define bustype_CAVM_BBXDX_CONFIG_1_20(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_20(a) "BBXDX_CONFIG_1_20"
#define busnum_CAVM_BBXDX_CONFIG_1_20(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_20(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_21
 *
 * BBX4 Configuration Register 121
 * Job Configuration
 */
union cavm_bbxdx_config_1_21
{
    uint64_t u;
    struct cavm_bbxdx_config_1_21_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_21           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_21           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_21_s cn; */
};
typedef union cavm_bbxdx_config_1_21 cavm_bbxdx_config_1_21_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_21(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_21(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_21", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_21(a) cavm_bbxdx_config_1_21_t
#define bustype_CAVM_BBXDX_CONFIG_1_21(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_21(a) "BBXDX_CONFIG_1_21"
#define busnum_CAVM_BBXDX_CONFIG_1_21(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_21(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_22
 *
 * BBX4 Configuration Register 122
 * Job Configuration
 */
union cavm_bbxdx_config_1_22
{
    uint64_t u;
    struct cavm_bbxdx_config_1_22_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_22           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_22           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_22_s cn; */
};
typedef union cavm_bbxdx_config_1_22 cavm_bbxdx_config_1_22_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_22(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_22(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_22", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_22(a) cavm_bbxdx_config_1_22_t
#define bustype_CAVM_BBXDX_CONFIG_1_22(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_22(a) "BBXDX_CONFIG_1_22"
#define busnum_CAVM_BBXDX_CONFIG_1_22(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_22(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_23
 *
 * BBX4 Configuration Register 123
 * Job Configuration
 */
union cavm_bbxdx_config_1_23
{
    uint64_t u;
    struct cavm_bbxdx_config_1_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_23           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_23           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_23_s cn; */
};
typedef union cavm_bbxdx_config_1_23 cavm_bbxdx_config_1_23_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_23(a) cavm_bbxdx_config_1_23_t
#define bustype_CAVM_BBXDX_CONFIG_1_23(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_23(a) "BBXDX_CONFIG_1_23"
#define busnum_CAVM_BBXDX_CONFIG_1_23(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_23(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_24
 *
 * BBX4 Configuration Register 124
 * Job Configuration
 */
union cavm_bbxdx_config_1_24
{
    uint64_t u;
    struct cavm_bbxdx_config_1_24_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_24           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_24           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_24_s cn; */
};
typedef union cavm_bbxdx_config_1_24 cavm_bbxdx_config_1_24_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_24(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_24(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_24", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_24(a) cavm_bbxdx_config_1_24_t
#define bustype_CAVM_BBXDX_CONFIG_1_24(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_24(a) "BBXDX_CONFIG_1_24"
#define busnum_CAVM_BBXDX_CONFIG_1_24(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_24(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_25
 *
 * BBX4 Configuration Register 125
 * Job Configuration
 */
union cavm_bbxdx_config_1_25
{
    uint64_t u;
    struct cavm_bbxdx_config_1_25_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_25           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_25           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_25_s cn; */
};
typedef union cavm_bbxdx_config_1_25 cavm_bbxdx_config_1_25_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_25(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_25(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_25", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_25(a) cavm_bbxdx_config_1_25_t
#define bustype_CAVM_BBXDX_CONFIG_1_25(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_25(a) "BBXDX_CONFIG_1_25"
#define busnum_CAVM_BBXDX_CONFIG_1_25(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_25(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_26
 *
 * BBX4 Configuration Register 126
 * Job Configuration
 */
union cavm_bbxdx_config_1_26
{
    uint64_t u;
    struct cavm_bbxdx_config_1_26_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_26           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_26           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_26_s cn; */
};
typedef union cavm_bbxdx_config_1_26 cavm_bbxdx_config_1_26_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_26(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_26(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_26", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_26(a) cavm_bbxdx_config_1_26_t
#define bustype_CAVM_BBXDX_CONFIG_1_26(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_26(a) "BBXDX_CONFIG_1_26"
#define busnum_CAVM_BBXDX_CONFIG_1_26(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_26(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_27
 *
 * BBX4 Configuration Register 127
 * Job Configuration
 */
union cavm_bbxdx_config_1_27
{
    uint64_t u;
    struct cavm_bbxdx_config_1_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_27           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_27           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_27_s cn; */
};
typedef union cavm_bbxdx_config_1_27 cavm_bbxdx_config_1_27_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_27", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_27(a) cavm_bbxdx_config_1_27_t
#define bustype_CAVM_BBXDX_CONFIG_1_27(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_27(a) "BBXDX_CONFIG_1_27"
#define busnum_CAVM_BBXDX_CONFIG_1_27(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_27(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_28
 *
 * BBX4 Configuration Register 128
 * Job Configuration
 */
union cavm_bbxdx_config_1_28
{
    uint64_t u;
    struct cavm_bbxdx_config_1_28_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_28           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_28           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_28_s cn; */
};
typedef union cavm_bbxdx_config_1_28 cavm_bbxdx_config_1_28_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_28(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_28(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_28", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_28(a) cavm_bbxdx_config_1_28_t
#define bustype_CAVM_BBXDX_CONFIG_1_28(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_28(a) "BBXDX_CONFIG_1_28"
#define busnum_CAVM_BBXDX_CONFIG_1_28(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_28(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_29
 *
 * BBX4 Configuration Register 129
 * Job Configuration
 */
union cavm_bbxdx_config_1_29
{
    uint64_t u;
    struct cavm_bbxdx_config_1_29_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_29           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_29           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_29_s cn; */
};
typedef union cavm_bbxdx_config_1_29 cavm_bbxdx_config_1_29_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_29(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_29(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_29", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_29(a) cavm_bbxdx_config_1_29_t
#define bustype_CAVM_BBXDX_CONFIG_1_29(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_29(a) "BBXDX_CONFIG_1_29"
#define busnum_CAVM_BBXDX_CONFIG_1_29(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_29(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_3
 *
 * BBX4 Configuration Register 13
 * Job Configuration
 */
union cavm_bbxdx_config_1_3
{
    uint64_t u;
    struct cavm_bbxdx_config_1_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_3            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_3            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_3_s cn; */
};
typedef union cavm_bbxdx_config_1_3 cavm_bbxdx_config_1_3_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_3(a) cavm_bbxdx_config_1_3_t
#define bustype_CAVM_BBXDX_CONFIG_1_3(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_3(a) "BBXDX_CONFIG_1_3"
#define busnum_CAVM_BBXDX_CONFIG_1_3(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_3(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_30
 *
 * BBX4 Configuration Register 130
 * Job Configuration
 */
union cavm_bbxdx_config_1_30
{
    uint64_t u;
    struct cavm_bbxdx_config_1_30_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_30           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_30           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_30_s cn; */
};
typedef union cavm_bbxdx_config_1_30 cavm_bbxdx_config_1_30_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_30(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_30(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_30", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_30(a) cavm_bbxdx_config_1_30_t
#define bustype_CAVM_BBXDX_CONFIG_1_30(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_30(a) "BBXDX_CONFIG_1_30"
#define busnum_CAVM_BBXDX_CONFIG_1_30(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_30(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_31
 *
 * BBX4 Configuration Register 131
 * Job Configuration
 */
union cavm_bbxdx_config_1_31
{
    uint64_t u;
    struct cavm_bbxdx_config_1_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_31           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_31           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_31_s cn; */
};
typedef union cavm_bbxdx_config_1_31 cavm_bbxdx_config_1_31_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437840f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_31(a) cavm_bbxdx_config_1_31_t
#define bustype_CAVM_BBXDX_CONFIG_1_31(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_31(a) "BBXDX_CONFIG_1_31"
#define busnum_CAVM_BBXDX_CONFIG_1_31(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_31(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_32
 *
 * BBX4 Configuration Register 132
 * Job Configuration
 */
union cavm_bbxdx_config_1_32
{
    uint64_t u;
    struct cavm_bbxdx_config_1_32_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_32           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_32           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_32_s cn; */
};
typedef union cavm_bbxdx_config_1_32 cavm_bbxdx_config_1_32_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_32(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_32(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784100ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_32", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_32(a) cavm_bbxdx_config_1_32_t
#define bustype_CAVM_BBXDX_CONFIG_1_32(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_32(a) "BBXDX_CONFIG_1_32"
#define busnum_CAVM_BBXDX_CONFIG_1_32(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_32(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_33
 *
 * BBX4 Configuration Register 133
 * Job Configuration
 */
union cavm_bbxdx_config_1_33
{
    uint64_t u;
    struct cavm_bbxdx_config_1_33_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_33           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_33           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_33_s cn; */
};
typedef union cavm_bbxdx_config_1_33 cavm_bbxdx_config_1_33_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_33(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_33(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784108ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_33", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_33(a) cavm_bbxdx_config_1_33_t
#define bustype_CAVM_BBXDX_CONFIG_1_33(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_33(a) "BBXDX_CONFIG_1_33"
#define busnum_CAVM_BBXDX_CONFIG_1_33(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_33(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_34
 *
 * BBX4 Configuration Register 134
 * Job Configuration
 */
union cavm_bbxdx_config_1_34
{
    uint64_t u;
    struct cavm_bbxdx_config_1_34_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_34           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_34           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_34_s cn; */
};
typedef union cavm_bbxdx_config_1_34 cavm_bbxdx_config_1_34_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_34(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_34(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784110ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_34", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_34(a) cavm_bbxdx_config_1_34_t
#define bustype_CAVM_BBXDX_CONFIG_1_34(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_34(a) "BBXDX_CONFIG_1_34"
#define busnum_CAVM_BBXDX_CONFIG_1_34(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_34(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_35
 *
 * BBX4 Configuration Register 135
 * Job Configuration
 */
union cavm_bbxdx_config_1_35
{
    uint64_t u;
    struct cavm_bbxdx_config_1_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_35           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_35           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_35_s cn; */
};
typedef union cavm_bbxdx_config_1_35 cavm_bbxdx_config_1_35_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784118ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_35", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_35(a) cavm_bbxdx_config_1_35_t
#define bustype_CAVM_BBXDX_CONFIG_1_35(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_35(a) "BBXDX_CONFIG_1_35"
#define busnum_CAVM_BBXDX_CONFIG_1_35(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_35(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_36
 *
 * BBX4 Configuration Register 136
 * Job Configuration
 */
union cavm_bbxdx_config_1_36
{
    uint64_t u;
    struct cavm_bbxdx_config_1_36_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_36           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_36           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_36_s cn; */
};
typedef union cavm_bbxdx_config_1_36 cavm_bbxdx_config_1_36_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_36(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_36(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784120ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_36", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_36(a) cavm_bbxdx_config_1_36_t
#define bustype_CAVM_BBXDX_CONFIG_1_36(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_36(a) "BBXDX_CONFIG_1_36"
#define busnum_CAVM_BBXDX_CONFIG_1_36(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_36(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_37
 *
 * BBX4 Configuration Register 137
 * Job Configuration
 */
union cavm_bbxdx_config_1_37
{
    uint64_t u;
    struct cavm_bbxdx_config_1_37_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_37           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_37           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_37_s cn; */
};
typedef union cavm_bbxdx_config_1_37 cavm_bbxdx_config_1_37_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_37(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_37(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784128ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_37", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_37(a) cavm_bbxdx_config_1_37_t
#define bustype_CAVM_BBXDX_CONFIG_1_37(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_37(a) "BBXDX_CONFIG_1_37"
#define busnum_CAVM_BBXDX_CONFIG_1_37(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_37(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_38
 *
 * BBX4 Configuration Register 138
 * Job Configuration
 */
union cavm_bbxdx_config_1_38
{
    uint64_t u;
    struct cavm_bbxdx_config_1_38_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_38           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_38           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_38_s cn; */
};
typedef union cavm_bbxdx_config_1_38 cavm_bbxdx_config_1_38_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_38(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_38(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784130ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_38", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_38(a) cavm_bbxdx_config_1_38_t
#define bustype_CAVM_BBXDX_CONFIG_1_38(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_38(a) "BBXDX_CONFIG_1_38"
#define busnum_CAVM_BBXDX_CONFIG_1_38(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_38(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_39
 *
 * BBX4 Configuration Register 139
 * Job Configuration
 */
union cavm_bbxdx_config_1_39
{
    uint64_t u;
    struct cavm_bbxdx_config_1_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_39           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_39           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_39_s cn; */
};
typedef union cavm_bbxdx_config_1_39 cavm_bbxdx_config_1_39_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784138ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_39(a) cavm_bbxdx_config_1_39_t
#define bustype_CAVM_BBXDX_CONFIG_1_39(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_39(a) "BBXDX_CONFIG_1_39"
#define busnum_CAVM_BBXDX_CONFIG_1_39(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_39(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_4
 *
 * BBX4 Configuration Register 14
 * Job Configuration
 */
union cavm_bbxdx_config_1_4
{
    uint64_t u;
    struct cavm_bbxdx_config_1_4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_4            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_4            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_4_s cn; */
};
typedef union cavm_bbxdx_config_1_4 cavm_bbxdx_config_1_4_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_4(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784020ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_4", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_4(a) cavm_bbxdx_config_1_4_t
#define bustype_CAVM_BBXDX_CONFIG_1_4(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_4(a) "BBXDX_CONFIG_1_4"
#define busnum_CAVM_BBXDX_CONFIG_1_4(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_4(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_40
 *
 * BBX4 Configuration Register 140
 * Job Configuration
 */
union cavm_bbxdx_config_1_40
{
    uint64_t u;
    struct cavm_bbxdx_config_1_40_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_40           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_40           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_40_s cn; */
};
typedef union cavm_bbxdx_config_1_40 cavm_bbxdx_config_1_40_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_40(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_40(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784140ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_40", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_40(a) cavm_bbxdx_config_1_40_t
#define bustype_CAVM_BBXDX_CONFIG_1_40(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_40(a) "BBXDX_CONFIG_1_40"
#define busnum_CAVM_BBXDX_CONFIG_1_40(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_40(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_41
 *
 * BBX4 Configuration Register 141
 * Job Configuration
 */
union cavm_bbxdx_config_1_41
{
    uint64_t u;
    struct cavm_bbxdx_config_1_41_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_41           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_41           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_41_s cn; */
};
typedef union cavm_bbxdx_config_1_41 cavm_bbxdx_config_1_41_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_41(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_41(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784148ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_41", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_41(a) cavm_bbxdx_config_1_41_t
#define bustype_CAVM_BBXDX_CONFIG_1_41(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_41(a) "BBXDX_CONFIG_1_41"
#define busnum_CAVM_BBXDX_CONFIG_1_41(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_41(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_42
 *
 * BBX4 Configuration Register 142
 * Job Configuration
 */
union cavm_bbxdx_config_1_42
{
    uint64_t u;
    struct cavm_bbxdx_config_1_42_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_42           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_42           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_42_s cn; */
};
typedef union cavm_bbxdx_config_1_42 cavm_bbxdx_config_1_42_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_42(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_42(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784150ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_42", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_42(a) cavm_bbxdx_config_1_42_t
#define bustype_CAVM_BBXDX_CONFIG_1_42(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_42(a) "BBXDX_CONFIG_1_42"
#define busnum_CAVM_BBXDX_CONFIG_1_42(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_42(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_43
 *
 * BBX4 Configuration Register 143
 * Job Configuration
 */
union cavm_bbxdx_config_1_43
{
    uint64_t u;
    struct cavm_bbxdx_config_1_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_43           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_43           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_43_s cn; */
};
typedef union cavm_bbxdx_config_1_43 cavm_bbxdx_config_1_43_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784158ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_43", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_43(a) cavm_bbxdx_config_1_43_t
#define bustype_CAVM_BBXDX_CONFIG_1_43(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_43(a) "BBXDX_CONFIG_1_43"
#define busnum_CAVM_BBXDX_CONFIG_1_43(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_43(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_44
 *
 * BBX4 Configuration Register 144
 * Job Configuration
 */
union cavm_bbxdx_config_1_44
{
    uint64_t u;
    struct cavm_bbxdx_config_1_44_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_44           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_44           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_44_s cn; */
};
typedef union cavm_bbxdx_config_1_44 cavm_bbxdx_config_1_44_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_44(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_44(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784160ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_44", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_44(a) cavm_bbxdx_config_1_44_t
#define bustype_CAVM_BBXDX_CONFIG_1_44(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_44(a) "BBXDX_CONFIG_1_44"
#define busnum_CAVM_BBXDX_CONFIG_1_44(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_44(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_45
 *
 * BBX4 Configuration Register 145
 * Job Configuration
 */
union cavm_bbxdx_config_1_45
{
    uint64_t u;
    struct cavm_bbxdx_config_1_45_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_45           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_45           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_45_s cn; */
};
typedef union cavm_bbxdx_config_1_45 cavm_bbxdx_config_1_45_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_45(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_45(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784168ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_45", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_45(a) cavm_bbxdx_config_1_45_t
#define bustype_CAVM_BBXDX_CONFIG_1_45(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_45(a) "BBXDX_CONFIG_1_45"
#define busnum_CAVM_BBXDX_CONFIG_1_45(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_45(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_46
 *
 * BBX4 Configuration Register 146
 * Job Configuration
 */
union cavm_bbxdx_config_1_46
{
    uint64_t u;
    struct cavm_bbxdx_config_1_46_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_46           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_46           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_46_s cn; */
};
typedef union cavm_bbxdx_config_1_46 cavm_bbxdx_config_1_46_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_46(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_46(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784170ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_46", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_46(a) cavm_bbxdx_config_1_46_t
#define bustype_CAVM_BBXDX_CONFIG_1_46(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_46(a) "BBXDX_CONFIG_1_46"
#define busnum_CAVM_BBXDX_CONFIG_1_46(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_46(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_47
 *
 * BBX4 Configuration Register 147
 * Job Configuration
 */
union cavm_bbxdx_config_1_47
{
    uint64_t u;
    struct cavm_bbxdx_config_1_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_47           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_47           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_47_s cn; */
};
typedef union cavm_bbxdx_config_1_47 cavm_bbxdx_config_1_47_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784178ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_47(a) cavm_bbxdx_config_1_47_t
#define bustype_CAVM_BBXDX_CONFIG_1_47(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_47(a) "BBXDX_CONFIG_1_47"
#define busnum_CAVM_BBXDX_CONFIG_1_47(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_47(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_48
 *
 * BBX4 Configuration Register 148
 * Job Configuration
 */
union cavm_bbxdx_config_1_48
{
    uint64_t u;
    struct cavm_bbxdx_config_1_48_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_48           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_48           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_48_s cn; */
};
typedef union cavm_bbxdx_config_1_48 cavm_bbxdx_config_1_48_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_48(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_48(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784180ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_48", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_48(a) cavm_bbxdx_config_1_48_t
#define bustype_CAVM_BBXDX_CONFIG_1_48(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_48(a) "BBXDX_CONFIG_1_48"
#define busnum_CAVM_BBXDX_CONFIG_1_48(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_48(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_49
 *
 * BBX4 Configuration Register 149
 * Job Configuration
 */
union cavm_bbxdx_config_1_49
{
    uint64_t u;
    struct cavm_bbxdx_config_1_49_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_49           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_49           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_49_s cn; */
};
typedef union cavm_bbxdx_config_1_49 cavm_bbxdx_config_1_49_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_49(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_49(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784188ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_49", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_49(a) cavm_bbxdx_config_1_49_t
#define bustype_CAVM_BBXDX_CONFIG_1_49(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_49(a) "BBXDX_CONFIG_1_49"
#define busnum_CAVM_BBXDX_CONFIG_1_49(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_49(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_5
 *
 * BBX4 Configuration Register 15
 * Job Configuration
 */
union cavm_bbxdx_config_1_5
{
    uint64_t u;
    struct cavm_bbxdx_config_1_5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_5            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_5            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_5_s cn; */
};
typedef union cavm_bbxdx_config_1_5 cavm_bbxdx_config_1_5_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_5(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784028ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_5", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_5(a) cavm_bbxdx_config_1_5_t
#define bustype_CAVM_BBXDX_CONFIG_1_5(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_5(a) "BBXDX_CONFIG_1_5"
#define busnum_CAVM_BBXDX_CONFIG_1_5(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_5(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_50
 *
 * BBX4 Configuration Register 150
 * Job Configuration
 */
union cavm_bbxdx_config_1_50
{
    uint64_t u;
    struct cavm_bbxdx_config_1_50_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_50_3         : 16; /**< [ 63: 48](R/W) -- */
        uint64_t reserved_41_47        : 7;
        uint64_t config_1_50_2         : 17; /**< [ 40: 24](R/W) -- */
        uint64_t reserved_23           : 1;
        uint64_t config_1_50_1         : 15; /**< [ 22:  8](R/W) -- */
        uint64_t reserved_2_7          : 6;
        uint64_t config_1_50_0         : 2;  /**< [  1:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_50_0         : 2;  /**< [  1:  0](R/W) -- */
        uint64_t reserved_2_7          : 6;
        uint64_t config_1_50_1         : 15; /**< [ 22:  8](R/W) -- */
        uint64_t reserved_23           : 1;
        uint64_t config_1_50_2         : 17; /**< [ 40: 24](R/W) -- */
        uint64_t reserved_41_47        : 7;
        uint64_t config_1_50_3         : 16; /**< [ 63: 48](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_50_s cn; */
};
typedef union cavm_bbxdx_config_1_50 cavm_bbxdx_config_1_50_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_50(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_50(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784190ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_50", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_50(a) cavm_bbxdx_config_1_50_t
#define bustype_CAVM_BBXDX_CONFIG_1_50(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_50(a) "BBXDX_CONFIG_1_50"
#define busnum_CAVM_BBXDX_CONFIG_1_50(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_50(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_51
 *
 * BBX4 Configuration Register 151
 * Job Configuration
 */
union cavm_bbxdx_config_1_51
{
    uint64_t u;
    struct cavm_bbxdx_config_1_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_51           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_51           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_51_s cn; */
};
typedef union cavm_bbxdx_config_1_51 cavm_bbxdx_config_1_51_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784198ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_51", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_51(a) cavm_bbxdx_config_1_51_t
#define bustype_CAVM_BBXDX_CONFIG_1_51(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_51(a) "BBXDX_CONFIG_1_51"
#define busnum_CAVM_BBXDX_CONFIG_1_51(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_51(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_52
 *
 * BBX4 Configuration Register 152
 * Job Configuration
 */
union cavm_bbxdx_config_1_52
{
    uint64_t u;
    struct cavm_bbxdx_config_1_52_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_52_1         : 32; /**< [ 63: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_52_0         : 29; /**< [ 28:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_52_0         : 29; /**< [ 28:  0](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_52_1         : 32; /**< [ 63: 32](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_52_s cn; */
};
typedef union cavm_bbxdx_config_1_52 cavm_bbxdx_config_1_52_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_52(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_52(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_52", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_52(a) cavm_bbxdx_config_1_52_t
#define bustype_CAVM_BBXDX_CONFIG_1_52(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_52(a) "BBXDX_CONFIG_1_52"
#define busnum_CAVM_BBXDX_CONFIG_1_52(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_52(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_53
 *
 * BBX4 Configuration Register 153
 * Job Configuration
 */
union cavm_bbxdx_config_1_53
{
    uint64_t u;
    struct cavm_bbxdx_config_1_53_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_53_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_53_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_53_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_53_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_53_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_53_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_53_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_53_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_53_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_53_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_53_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_53_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_53_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_53_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_53_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_53_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_53_s cn; */
};
typedef union cavm_bbxdx_config_1_53 cavm_bbxdx_config_1_53_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_53(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_53(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_53", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_53(a) cavm_bbxdx_config_1_53_t
#define bustype_CAVM_BBXDX_CONFIG_1_53(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_53(a) "BBXDX_CONFIG_1_53"
#define busnum_CAVM_BBXDX_CONFIG_1_53(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_53(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_54
 *
 * BBX4 Configuration Register 154
 * Job Configuration
 */
union cavm_bbxdx_config_1_54
{
    uint64_t u;
    struct cavm_bbxdx_config_1_54_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_54_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_54_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_54_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_54_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_54_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_54_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_54_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_54_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_54_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_54_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_54_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_54_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_54_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_54_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_54_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_54_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_54_s cn; */
};
typedef union cavm_bbxdx_config_1_54 cavm_bbxdx_config_1_54_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_54(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_54(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_54", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_54(a) cavm_bbxdx_config_1_54_t
#define bustype_CAVM_BBXDX_CONFIG_1_54(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_54(a) "BBXDX_CONFIG_1_54"
#define busnum_CAVM_BBXDX_CONFIG_1_54(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_54(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_55
 *
 * BBX4 Configuration Register 155
 * Job Configuration
 */
union cavm_bbxdx_config_1_55
{
    uint64_t u;
    struct cavm_bbxdx_config_1_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_55_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_55_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_55_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_55_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_55_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_55_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_55_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_55_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_55_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_55_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_55_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_55_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_55_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_55_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_55_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_55_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_55_s cn; */
};
typedef union cavm_bbxdx_config_1_55 cavm_bbxdx_config_1_55_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_55(a) cavm_bbxdx_config_1_55_t
#define bustype_CAVM_BBXDX_CONFIG_1_55(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_55(a) "BBXDX_CONFIG_1_55"
#define busnum_CAVM_BBXDX_CONFIG_1_55(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_55(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_56
 *
 * BBX4 Configuration Register 156
 * Job Configuration
 */
union cavm_bbxdx_config_1_56
{
    uint64_t u;
    struct cavm_bbxdx_config_1_56_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_56_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_56_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_56_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_56_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_56_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_56_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_56_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_56_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_56_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_56_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_56_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_56_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_56_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_56_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_56_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_56_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_56_s cn; */
};
typedef union cavm_bbxdx_config_1_56 cavm_bbxdx_config_1_56_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_56(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_56(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_56", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_56(a) cavm_bbxdx_config_1_56_t
#define bustype_CAVM_BBXDX_CONFIG_1_56(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_56(a) "BBXDX_CONFIG_1_56"
#define busnum_CAVM_BBXDX_CONFIG_1_56(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_56(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_57
 *
 * BBX4 Configuration Register 157
 * Job Configuration
 */
union cavm_bbxdx_config_1_57
{
    uint64_t u;
    struct cavm_bbxdx_config_1_57_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_57_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_57_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_57_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_57_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_57_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_57_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_57_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_57_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_57_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_57_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_57_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_57_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_57_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_57_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_57_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_57_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_57_s cn; */
};
typedef union cavm_bbxdx_config_1_57 cavm_bbxdx_config_1_57_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_57(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_57(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_57", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_57(a) cavm_bbxdx_config_1_57_t
#define bustype_CAVM_BBXDX_CONFIG_1_57(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_57(a) "BBXDX_CONFIG_1_57"
#define busnum_CAVM_BBXDX_CONFIG_1_57(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_57(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_58
 *
 * BBX4 Configuration Register 158
 * Job Configuration
 */
union cavm_bbxdx_config_1_58
{
    uint64_t u;
    struct cavm_bbxdx_config_1_58_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_58_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_58_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_58_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_58_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_58_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_58_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_58_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_58_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_58_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_58_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_58_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_58_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_58_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_58_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_58_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_58_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_58_s cn; */
};
typedef union cavm_bbxdx_config_1_58 cavm_bbxdx_config_1_58_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_58(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_58(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_58", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_58(a) cavm_bbxdx_config_1_58_t
#define bustype_CAVM_BBXDX_CONFIG_1_58(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_58(a) "BBXDX_CONFIG_1_58"
#define busnum_CAVM_BBXDX_CONFIG_1_58(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_58(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_59
 *
 * BBX4 Configuration Register 159
 * Job Configuration
 */
union cavm_bbxdx_config_1_59
{
    uint64_t u;
    struct cavm_bbxdx_config_1_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_59_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_59_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_59_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_59_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_59_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_59_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_59_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_59_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_59_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_59_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_59_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_59_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_59_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_59_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_59_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_59_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_59_s cn; */
};
typedef union cavm_bbxdx_config_1_59 cavm_bbxdx_config_1_59_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_59", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_59(a) cavm_bbxdx_config_1_59_t
#define bustype_CAVM_BBXDX_CONFIG_1_59(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_59(a) "BBXDX_CONFIG_1_59"
#define busnum_CAVM_BBXDX_CONFIG_1_59(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_59(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_6
 *
 * BBX4 Configuration Register 16
 * Job Configuration
 */
union cavm_bbxdx_config_1_6
{
    uint64_t u;
    struct cavm_bbxdx_config_1_6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_6            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_6            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_6_s cn; */
};
typedef union cavm_bbxdx_config_1_6 cavm_bbxdx_config_1_6_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_6(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_6", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_6(a) cavm_bbxdx_config_1_6_t
#define bustype_CAVM_BBXDX_CONFIG_1_6(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_6(a) "BBXDX_CONFIG_1_6"
#define busnum_CAVM_BBXDX_CONFIG_1_6(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_6(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_60
 *
 * BBX4 Configuration Register 160
 * Job Configuration
 */
union cavm_bbxdx_config_1_60
{
    uint64_t u;
    struct cavm_bbxdx_config_1_60_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_60_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_60_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_60_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_60_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_60_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_60_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_60_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_60_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_60_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_60_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_60_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_60_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_60_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_60_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_60_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_60_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_60_s cn; */
};
typedef union cavm_bbxdx_config_1_60 cavm_bbxdx_config_1_60_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_60(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_60(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_60", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_60(a) cavm_bbxdx_config_1_60_t
#define bustype_CAVM_BBXDX_CONFIG_1_60(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_60(a) "BBXDX_CONFIG_1_60"
#define busnum_CAVM_BBXDX_CONFIG_1_60(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_60(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_61
 *
 * BBX4 Configuration Register 161
 * Job Configuration
 */
union cavm_bbxdx_config_1_61
{
    uint64_t u;
    struct cavm_bbxdx_config_1_61_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_61_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_61_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_61_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_61_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_61_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_61_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_61_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_61_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_61_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_61_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_61_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_61_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_61_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_61_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_61_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_61_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_61_s cn; */
};
typedef union cavm_bbxdx_config_1_61 cavm_bbxdx_config_1_61_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_61(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_61(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_61", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_61(a) cavm_bbxdx_config_1_61_t
#define bustype_CAVM_BBXDX_CONFIG_1_61(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_61(a) "BBXDX_CONFIG_1_61"
#define busnum_CAVM_BBXDX_CONFIG_1_61(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_61(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_62
 *
 * BBX4 Configuration Register 162
 * Job Configuration
 */
union cavm_bbxdx_config_1_62
{
    uint64_t u;
    struct cavm_bbxdx_config_1_62_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_62_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_62_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_62_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t onfig_1_62_4          : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_62_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_62_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_62_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_62_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_62_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_62_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_62_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_62_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t onfig_1_62_4          : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_62_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_62_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_62_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_62_s cn; */
};
typedef union cavm_bbxdx_config_1_62 cavm_bbxdx_config_1_62_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_62(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_62(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_62", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_62(a) cavm_bbxdx_config_1_62_t
#define bustype_CAVM_BBXDX_CONFIG_1_62(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_62(a) "BBXDX_CONFIG_1_62"
#define busnum_CAVM_BBXDX_CONFIG_1_62(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_62(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_63
 *
 * BBX4 Configuration Register 163
 * Job Configuration
 */
union cavm_bbxdx_config_1_63
{
    uint64_t u;
    struct cavm_bbxdx_config_1_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_63_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_63_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_63_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_63_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_63_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_63_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_63_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_63_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_63_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_63_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_63_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_63_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_63_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_63_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_63_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_63_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_63_s cn; */
};
typedef union cavm_bbxdx_config_1_63 cavm_bbxdx_config_1_63_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437841f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_63(a) cavm_bbxdx_config_1_63_t
#define bustype_CAVM_BBXDX_CONFIG_1_63(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_63(a) "BBXDX_CONFIG_1_63"
#define busnum_CAVM_BBXDX_CONFIG_1_63(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_63(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_64
 *
 * BBX4 Configuration Register 164
 * Job Configuration
 */
union cavm_bbxdx_config_1_64
{
    uint64_t u;
    struct cavm_bbxdx_config_1_64_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_64_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_64_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_64_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_64_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_64_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_64_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_64_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_64_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_64_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_64_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_64_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_64_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_64_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_64_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_64_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_64_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_64_s cn; */
};
typedef union cavm_bbxdx_config_1_64 cavm_bbxdx_config_1_64_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_64(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_64(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784200ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_64", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_64(a) cavm_bbxdx_config_1_64_t
#define bustype_CAVM_BBXDX_CONFIG_1_64(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_64(a) "BBXDX_CONFIG_1_64"
#define busnum_CAVM_BBXDX_CONFIG_1_64(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_64(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_65
 *
 * BBX4 Configuration Register 165
 * Job Configuration
 */
union cavm_bbxdx_config_1_65
{
    uint64_t u;
    struct cavm_bbxdx_config_1_65_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_65_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_65_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_65_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_65_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_65_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_65_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_65_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_65_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_65_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_65_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_65_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_65_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_65_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_65_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_65_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_65_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_65_s cn; */
};
typedef union cavm_bbxdx_config_1_65 cavm_bbxdx_config_1_65_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_65(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_65(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784208ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_65", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_65(a) cavm_bbxdx_config_1_65_t
#define bustype_CAVM_BBXDX_CONFIG_1_65(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_65(a) "BBXDX_CONFIG_1_65"
#define busnum_CAVM_BBXDX_CONFIG_1_65(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_65(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_66
 *
 * BBX4 Configuration Register 166
 * Job Configuration
 */
union cavm_bbxdx_config_1_66
{
    uint64_t u;
    struct cavm_bbxdx_config_1_66_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_1_66_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_66_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_66_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_66_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_66_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_66_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_66_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_66_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_66_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_66_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_66_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_66_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_66_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_66_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_66_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_66_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_66_s cn; */
};
typedef union cavm_bbxdx_config_1_66 cavm_bbxdx_config_1_66_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_66(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_66(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784210ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_66", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_66(a) cavm_bbxdx_config_1_66_t
#define bustype_CAVM_BBXDX_CONFIG_1_66(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_66(a) "BBXDX_CONFIG_1_66"
#define busnum_CAVM_BBXDX_CONFIG_1_66(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_66(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_67
 *
 * BBX4 Configuration Register 167
 * Job Configuration
 */
union cavm_bbxdx_config_1_67
{
    uint64_t u;
    struct cavm_bbxdx_config_1_67_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_67_7         : 8;  /**< [ 63: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_67_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_67_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_67_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_67_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_67_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_67_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_67_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_67_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_67_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_67_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_67_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_67_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_67_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_67_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_67_7         : 8;  /**< [ 63: 56](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_67_s cn; */
};
typedef union cavm_bbxdx_config_1_67 cavm_bbxdx_config_1_67_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_67(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_67(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784218ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_67", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_67(a) cavm_bbxdx_config_1_67_t
#define bustype_CAVM_BBXDX_CONFIG_1_67(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_67(a) "BBXDX_CONFIG_1_67"
#define busnum_CAVM_BBXDX_CONFIG_1_67(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_67(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_68
 *
 * BBX4 Configuration Register 168
 * Job Configuration
 */
union cavm_bbxdx_config_1_68
{
    uint64_t u;
    struct cavm_bbxdx_config_1_68_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_68_7         : 8;  /**< [ 63: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_68_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_68_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_68_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_68_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_68_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_68_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_68_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_68_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_1_68_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_1_68_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_1_68_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_1_68_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_1_68_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_1_68_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_1_68_7         : 8;  /**< [ 63: 56](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_68_s cn; */
};
typedef union cavm_bbxdx_config_1_68 cavm_bbxdx_config_1_68_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_68(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_68(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784220ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_68", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_68(a) cavm_bbxdx_config_1_68_t
#define bustype_CAVM_BBXDX_CONFIG_1_68(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_68(a) "BBXDX_CONFIG_1_68"
#define busnum_CAVM_BBXDX_CONFIG_1_68(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_68(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_69
 *
 * BBX4 Configuration Register 169
 * Job Configuration
 */
union cavm_bbxdx_config_1_69
{
    uint64_t u;
    struct cavm_bbxdx_config_1_69_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_69           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_69           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_69_s cn; */
};
typedef union cavm_bbxdx_config_1_69 cavm_bbxdx_config_1_69_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_69(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_69(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784228ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_69", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_69(a) cavm_bbxdx_config_1_69_t
#define bustype_CAVM_BBXDX_CONFIG_1_69(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_69(a) "BBXDX_CONFIG_1_69"
#define busnum_CAVM_BBXDX_CONFIG_1_69(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_69(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_7
 *
 * BBX4 Configuration Register 17
 * Job Configuration
 */
union cavm_bbxdx_config_1_7
{
    uint64_t u;
    struct cavm_bbxdx_config_1_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_7            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_7            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_7_s cn; */
};
typedef union cavm_bbxdx_config_1_7 cavm_bbxdx_config_1_7_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_7(a) cavm_bbxdx_config_1_7_t
#define bustype_CAVM_BBXDX_CONFIG_1_7(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_7(a) "BBXDX_CONFIG_1_7"
#define busnum_CAVM_BBXDX_CONFIG_1_7(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_7(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_70
 *
 * BBX4 Configuration Register 170
 * Job Configuration
 */
union cavm_bbxdx_config_1_70
{
    uint64_t u;
    struct cavm_bbxdx_config_1_70_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_70           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_70           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_70_s cn; */
};
typedef union cavm_bbxdx_config_1_70 cavm_bbxdx_config_1_70_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_70(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_70(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784230ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_70", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_70(a) cavm_bbxdx_config_1_70_t
#define bustype_CAVM_BBXDX_CONFIG_1_70(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_70(a) "BBXDX_CONFIG_1_70"
#define busnum_CAVM_BBXDX_CONFIG_1_70(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_70(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_71
 *
 * BBX4 Configuration Register 171
 * Job Configuration
 */
union cavm_bbxdx_config_1_71
{
    uint64_t u;
    struct cavm_bbxdx_config_1_71_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_71           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_71           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_71_s cn; */
};
typedef union cavm_bbxdx_config_1_71 cavm_bbxdx_config_1_71_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_71(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_71(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784238ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_71", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_71(a) cavm_bbxdx_config_1_71_t
#define bustype_CAVM_BBXDX_CONFIG_1_71(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_71(a) "BBXDX_CONFIG_1_71"
#define busnum_CAVM_BBXDX_CONFIG_1_71(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_71(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_72
 *
 * BBX4 Configuration Register 172
 * Job Configuration
 */
union cavm_bbxdx_config_1_72
{
    uint64_t u;
    struct cavm_bbxdx_config_1_72_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_72           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_72           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_72_s cn; */
};
typedef union cavm_bbxdx_config_1_72 cavm_bbxdx_config_1_72_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_72(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_72(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784240ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_72", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_72(a) cavm_bbxdx_config_1_72_t
#define bustype_CAVM_BBXDX_CONFIG_1_72(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_72(a) "BBXDX_CONFIG_1_72"
#define busnum_CAVM_BBXDX_CONFIG_1_72(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_72(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_73
 *
 * BBX4 Configuration Register 173
 * Job Configuration
 */
union cavm_bbxdx_config_1_73
{
    uint64_t u;
    struct cavm_bbxdx_config_1_73_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_73           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_73           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_73_s cn; */
};
typedef union cavm_bbxdx_config_1_73 cavm_bbxdx_config_1_73_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_73(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_73(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784248ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_73", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_73(a) cavm_bbxdx_config_1_73_t
#define bustype_CAVM_BBXDX_CONFIG_1_73(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_73(a) "BBXDX_CONFIG_1_73"
#define busnum_CAVM_BBXDX_CONFIG_1_73(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_73(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_74
 *
 * BBX4 Configuration Register 174
 * Job Configuration
 */
union cavm_bbxdx_config_1_74
{
    uint64_t u;
    struct cavm_bbxdx_config_1_74_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_74           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_74           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_74_s cn; */
};
typedef union cavm_bbxdx_config_1_74 cavm_bbxdx_config_1_74_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_74(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_74(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784250ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_74", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_74(a) cavm_bbxdx_config_1_74_t
#define bustype_CAVM_BBXDX_CONFIG_1_74(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_74(a) "BBXDX_CONFIG_1_74"
#define busnum_CAVM_BBXDX_CONFIG_1_74(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_74(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_75
 *
 * BBX4 Configuration Register 175
 * Job Configuration
 */
union cavm_bbxdx_config_1_75
{
    uint64_t u;
    struct cavm_bbxdx_config_1_75_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_75           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_75           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_75_s cn; */
};
typedef union cavm_bbxdx_config_1_75 cavm_bbxdx_config_1_75_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_75(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_75(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784258ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_75", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_75(a) cavm_bbxdx_config_1_75_t
#define bustype_CAVM_BBXDX_CONFIG_1_75(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_75(a) "BBXDX_CONFIG_1_75"
#define busnum_CAVM_BBXDX_CONFIG_1_75(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_75(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_76
 *
 * BBX4 Configuration Register 176
 * Job Configuration
 */
union cavm_bbxdx_config_1_76
{
    uint64_t u;
    struct cavm_bbxdx_config_1_76_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_76           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_76           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_76_s cn; */
};
typedef union cavm_bbxdx_config_1_76 cavm_bbxdx_config_1_76_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_76(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_76(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784260ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_76", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_76(a) cavm_bbxdx_config_1_76_t
#define bustype_CAVM_BBXDX_CONFIG_1_76(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_76(a) "BBXDX_CONFIG_1_76"
#define busnum_CAVM_BBXDX_CONFIG_1_76(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_76(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_77
 *
 * BBX4 Configuration Register 177
 * Job Configuration
 */
union cavm_bbxdx_config_1_77
{
    uint64_t u;
    struct cavm_bbxdx_config_1_77_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_77           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_77           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_77_s cn; */
};
typedef union cavm_bbxdx_config_1_77 cavm_bbxdx_config_1_77_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_77(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_77(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784268ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_77", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_77(a) cavm_bbxdx_config_1_77_t
#define bustype_CAVM_BBXDX_CONFIG_1_77(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_77(a) "BBXDX_CONFIG_1_77"
#define busnum_CAVM_BBXDX_CONFIG_1_77(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_77(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_78
 *
 * BBX4 Configuration Register 178
 * Job Configuration
 */
union cavm_bbxdx_config_1_78
{
    uint64_t u;
    struct cavm_bbxdx_config_1_78_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_78           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_78           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_78_s cn; */
};
typedef union cavm_bbxdx_config_1_78 cavm_bbxdx_config_1_78_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_78(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_78(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784270ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_78", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_78(a) cavm_bbxdx_config_1_78_t
#define bustype_CAVM_BBXDX_CONFIG_1_78(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_78(a) "BBXDX_CONFIG_1_78"
#define busnum_CAVM_BBXDX_CONFIG_1_78(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_78(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_79
 *
 * BBX4 Configuration Register 179
 * Job Configuration
 */
union cavm_bbxdx_config_1_79
{
    uint64_t u;
    struct cavm_bbxdx_config_1_79_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_79           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_79           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_79_s cn; */
};
typedef union cavm_bbxdx_config_1_79 cavm_bbxdx_config_1_79_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_79(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_79(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784278ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_79", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_79(a) cavm_bbxdx_config_1_79_t
#define bustype_CAVM_BBXDX_CONFIG_1_79(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_79(a) "BBXDX_CONFIG_1_79"
#define busnum_CAVM_BBXDX_CONFIG_1_79(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_79(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_8
 *
 * BBX4 Configuration Register 18
 * Job Configuration
 */
union cavm_bbxdx_config_1_8
{
    uint64_t u;
    struct cavm_bbxdx_config_1_8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_8            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_8            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_8_s cn; */
};
typedef union cavm_bbxdx_config_1_8 cavm_bbxdx_config_1_8_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_8(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_8(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_8", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_8(a) cavm_bbxdx_config_1_8_t
#define bustype_CAVM_BBXDX_CONFIG_1_8(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_8(a) "BBXDX_CONFIG_1_8"
#define busnum_CAVM_BBXDX_CONFIG_1_8(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_8(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_80
 *
 * BBX4 Configuration Register 180
 * Job Configuration
 */
union cavm_bbxdx_config_1_80
{
    uint64_t u;
    struct cavm_bbxdx_config_1_80_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_80           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_80           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_80_s cn; */
};
typedef union cavm_bbxdx_config_1_80 cavm_bbxdx_config_1_80_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_80(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_80(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784280ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_80", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_80(a) cavm_bbxdx_config_1_80_t
#define bustype_CAVM_BBXDX_CONFIG_1_80(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_80(a) "BBXDX_CONFIG_1_80"
#define busnum_CAVM_BBXDX_CONFIG_1_80(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_80(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_81
 *
 * BBX4 Configuration Register 181
 * Job Configuration
 */
union cavm_bbxdx_config_1_81
{
    uint64_t u;
    struct cavm_bbxdx_config_1_81_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_81           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_81           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_81_s cn; */
};
typedef union cavm_bbxdx_config_1_81 cavm_bbxdx_config_1_81_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_81(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_81(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784288ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_81", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_81(a) cavm_bbxdx_config_1_81_t
#define bustype_CAVM_BBXDX_CONFIG_1_81(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_81(a) "BBXDX_CONFIG_1_81"
#define busnum_CAVM_BBXDX_CONFIG_1_81(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_81(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_82
 *
 * BBX4 Configuration Register 182
 * Job Configuration
 */
union cavm_bbxdx_config_1_82
{
    uint64_t u;
    struct cavm_bbxdx_config_1_82_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_82           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_82           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_82_s cn; */
};
typedef union cavm_bbxdx_config_1_82 cavm_bbxdx_config_1_82_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_82(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_82(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784290ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_82", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_82(a) cavm_bbxdx_config_1_82_t
#define bustype_CAVM_BBXDX_CONFIG_1_82(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_82(a) "BBXDX_CONFIG_1_82"
#define busnum_CAVM_BBXDX_CONFIG_1_82(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_82(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_83
 *
 * BBX4 Configuration Register 183
 * Job Configuration
 */
union cavm_bbxdx_config_1_83
{
    uint64_t u;
    struct cavm_bbxdx_config_1_83_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_83           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_83           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_83_s cn; */
};
typedef union cavm_bbxdx_config_1_83 cavm_bbxdx_config_1_83_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_83(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_83(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784298ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_83", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_83(a) cavm_bbxdx_config_1_83_t
#define bustype_CAVM_BBXDX_CONFIG_1_83(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_83(a) "BBXDX_CONFIG_1_83"
#define busnum_CAVM_BBXDX_CONFIG_1_83(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_83(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_84
 *
 * BBX4 Configuration Register 184
 * Job Configuration
 */
union cavm_bbxdx_config_1_84
{
    uint64_t u;
    struct cavm_bbxdx_config_1_84_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_84           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_84           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_84_s cn; */
};
typedef union cavm_bbxdx_config_1_84 cavm_bbxdx_config_1_84_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_84(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_84(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_84", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_84(a) cavm_bbxdx_config_1_84_t
#define bustype_CAVM_BBXDX_CONFIG_1_84(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_84(a) "BBXDX_CONFIG_1_84"
#define busnum_CAVM_BBXDX_CONFIG_1_84(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_84(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_85
 *
 * BBX4 Configuration Register 185
 * Job Configuration
 */
union cavm_bbxdx_config_1_85
{
    uint64_t u;
    struct cavm_bbxdx_config_1_85_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_85           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_85           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_85_s cn; */
};
typedef union cavm_bbxdx_config_1_85 cavm_bbxdx_config_1_85_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_85(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_85(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_85", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_85(a) cavm_bbxdx_config_1_85_t
#define bustype_CAVM_BBXDX_CONFIG_1_85(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_85(a) "BBXDX_CONFIG_1_85"
#define busnum_CAVM_BBXDX_CONFIG_1_85(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_85(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_86
 *
 * BBX4 Configuration Register 186
 * Job Configuration
 */
union cavm_bbxdx_config_1_86
{
    uint64_t u;
    struct cavm_bbxdx_config_1_86_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_86           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_86           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_86_s cn; */
};
typedef union cavm_bbxdx_config_1_86 cavm_bbxdx_config_1_86_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_86(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_86(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_86", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_86(a) cavm_bbxdx_config_1_86_t
#define bustype_CAVM_BBXDX_CONFIG_1_86(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_86(a) "BBXDX_CONFIG_1_86"
#define busnum_CAVM_BBXDX_CONFIG_1_86(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_86(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_87
 *
 * BBX4 Configuration Register 187
 * Job Configuration
 */
union cavm_bbxdx_config_1_87
{
    uint64_t u;
    struct cavm_bbxdx_config_1_87_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_87           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_87           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_87_s cn; */
};
typedef union cavm_bbxdx_config_1_87 cavm_bbxdx_config_1_87_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_87(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_87(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_87", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_87(a) cavm_bbxdx_config_1_87_t
#define bustype_CAVM_BBXDX_CONFIG_1_87(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_87(a) "BBXDX_CONFIG_1_87"
#define busnum_CAVM_BBXDX_CONFIG_1_87(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_87(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_88
 *
 * BBX4 Configuration Register 188
 * Job Configuration
 */
union cavm_bbxdx_config_1_88
{
    uint64_t u;
    struct cavm_bbxdx_config_1_88_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_88           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_88           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_88_s cn; */
};
typedef union cavm_bbxdx_config_1_88 cavm_bbxdx_config_1_88_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_88(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_88(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_88", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_88(a) cavm_bbxdx_config_1_88_t
#define bustype_CAVM_BBXDX_CONFIG_1_88(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_88(a) "BBXDX_CONFIG_1_88"
#define busnum_CAVM_BBXDX_CONFIG_1_88(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_88(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_89
 *
 * BBX4 Configuration Register 189
 * Job Configuration
 */
union cavm_bbxdx_config_1_89
{
    uint64_t u;
    struct cavm_bbxdx_config_1_89_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_89           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_89           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_89_s cn; */
};
typedef union cavm_bbxdx_config_1_89 cavm_bbxdx_config_1_89_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_89(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_89(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_89", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_89(a) cavm_bbxdx_config_1_89_t
#define bustype_CAVM_BBXDX_CONFIG_1_89(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_89(a) "BBXDX_CONFIG_1_89"
#define busnum_CAVM_BBXDX_CONFIG_1_89(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_89(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_9
 *
 * BBX4 Configuration Register 19
 * Job Configuration
 */
union cavm_bbxdx_config_1_9
{
    uint64_t u;
    struct cavm_bbxdx_config_1_9_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_1_9            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_9            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_9_s cn; */
};
typedef union cavm_bbxdx_config_1_9 cavm_bbxdx_config_1_9_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_9(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_9(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_9", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_9(a) cavm_bbxdx_config_1_9_t
#define bustype_CAVM_BBXDX_CONFIG_1_9(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_9(a) "BBXDX_CONFIG_1_9"
#define busnum_CAVM_BBXDX_CONFIG_1_9(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_9(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_90
 *
 * BBX4 Configuration Register 190
 * Job Configuration
 */
union cavm_bbxdx_config_1_90
{
    uint64_t u;
    struct cavm_bbxdx_config_1_90_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_90           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_90           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_90_s cn; */
};
typedef union cavm_bbxdx_config_1_90 cavm_bbxdx_config_1_90_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_90(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_90(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_90", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_90(a) cavm_bbxdx_config_1_90_t
#define bustype_CAVM_BBXDX_CONFIG_1_90(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_90(a) "BBXDX_CONFIG_1_90"
#define busnum_CAVM_BBXDX_CONFIG_1_90(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_90(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_91
 *
 * BBX4 Configuration Register 191
 * Job Configuration
 */
union cavm_bbxdx_config_1_91
{
    uint64_t u;
    struct cavm_bbxdx_config_1_91_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_91           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_91           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_91_s cn; */
};
typedef union cavm_bbxdx_config_1_91 cavm_bbxdx_config_1_91_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_91(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_91(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_91", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_91(a) cavm_bbxdx_config_1_91_t
#define bustype_CAVM_BBXDX_CONFIG_1_91(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_91(a) "BBXDX_CONFIG_1_91"
#define busnum_CAVM_BBXDX_CONFIG_1_91(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_91(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_92
 *
 * BBX4 Configuration Register 192
 * Job Configuration
 */
union cavm_bbxdx_config_1_92
{
    uint64_t u;
    struct cavm_bbxdx_config_1_92_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_92           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_92           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_92_s cn; */
};
typedef union cavm_bbxdx_config_1_92 cavm_bbxdx_config_1_92_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_92(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_92(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_92", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_92(a) cavm_bbxdx_config_1_92_t
#define bustype_CAVM_BBXDX_CONFIG_1_92(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_92(a) "BBXDX_CONFIG_1_92"
#define busnum_CAVM_BBXDX_CONFIG_1_92(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_92(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_93
 *
 * BBX4 Configuration Register 193
 * Job Configuration
 */
union cavm_bbxdx_config_1_93
{
    uint64_t u;
    struct cavm_bbxdx_config_1_93_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_93           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_93           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_93_s cn; */
};
typedef union cavm_bbxdx_config_1_93 cavm_bbxdx_config_1_93_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_93(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_93(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_93", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_93(a) cavm_bbxdx_config_1_93_t
#define bustype_CAVM_BBXDX_CONFIG_1_93(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_93(a) "BBXDX_CONFIG_1_93"
#define busnum_CAVM_BBXDX_CONFIG_1_93(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_93(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_94
 *
 * BBX4 Configuration Register 194
 * Job Configuration
 */
union cavm_bbxdx_config_1_94
{
    uint64_t u;
    struct cavm_bbxdx_config_1_94_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_94           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_94           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_94_s cn; */
};
typedef union cavm_bbxdx_config_1_94 cavm_bbxdx_config_1_94_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_94(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_94(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_94", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_94(a) cavm_bbxdx_config_1_94_t
#define bustype_CAVM_BBXDX_CONFIG_1_94(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_94(a) "BBXDX_CONFIG_1_94"
#define busnum_CAVM_BBXDX_CONFIG_1_94(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_94(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_95
 *
 * BBX4 Configuration Register 195
 * Job Configuration
 */
union cavm_bbxdx_config_1_95
{
    uint64_t u;
    struct cavm_bbxdx_config_1_95_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_1_95           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_95           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_95_s cn; */
};
typedef union cavm_bbxdx_config_1_95 cavm_bbxdx_config_1_95_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_95(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_95(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437842f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_95", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_95(a) cavm_bbxdx_config_1_95_t
#define bustype_CAVM_BBXDX_CONFIG_1_95(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_95(a) "BBXDX_CONFIG_1_95"
#define busnum_CAVM_BBXDX_CONFIG_1_95(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_95(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_96
 *
 * BBX4 Configuration Register 196
 * Job Configuration
 */
union cavm_bbxdx_config_1_96
{
    uint64_t u;
    struct cavm_bbxdx_config_1_96_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_1_96           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_96           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_96_s cn; */
};
typedef union cavm_bbxdx_config_1_96 cavm_bbxdx_config_1_96_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_96(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_96(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784300ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_96", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_96(a) cavm_bbxdx_config_1_96_t
#define bustype_CAVM_BBXDX_CONFIG_1_96(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_96(a) "BBXDX_CONFIG_1_96"
#define busnum_CAVM_BBXDX_CONFIG_1_96(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_96(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_97
 *
 * BBX4 Configuration Register 197
 * Job Configuration
 */
union cavm_bbxdx_config_1_97
{
    uint64_t u;
    struct cavm_bbxdx_config_1_97_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_1_97           : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_97           : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_97_s cn; */
};
typedef union cavm_bbxdx_config_1_97 cavm_bbxdx_config_1_97_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_97(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_97(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784308ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_97", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_97(a) cavm_bbxdx_config_1_97_t
#define bustype_CAVM_BBXDX_CONFIG_1_97(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_97(a) "BBXDX_CONFIG_1_97"
#define busnum_CAVM_BBXDX_CONFIG_1_97(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_97(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_98
 *
 * BBX4 Configuration Register 198
 * Job Configuration
 */
union cavm_bbxdx_config_1_98
{
    uint64_t u;
    struct cavm_bbxdx_config_1_98_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_1_98           : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_98           : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_98_s cn; */
};
typedef union cavm_bbxdx_config_1_98 cavm_bbxdx_config_1_98_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_98(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_98(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784310ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_98", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_98(a) cavm_bbxdx_config_1_98_t
#define bustype_CAVM_BBXDX_CONFIG_1_98(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_98(a) "BBXDX_CONFIG_1_98"
#define busnum_CAVM_BBXDX_CONFIG_1_98(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_98(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_1_99
 *
 * BBX4 Configuration Register 199
 * Job Configuration
 */
union cavm_bbxdx_config_1_99
{
    uint64_t u;
    struct cavm_bbxdx_config_1_99_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t config_1_99           : 9;  /**< [  8:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_1_99           : 9;  /**< [  8:  0](R/W) -- */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_1_99_s cn; */
};
typedef union cavm_bbxdx_config_1_99 cavm_bbxdx_config_1_99_t;

static inline uint64_t CAVM_BBXDX_CONFIG_1_99(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_1_99(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043784318ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_1_99", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_1_99(a) cavm_bbxdx_config_1_99_t
#define bustype_CAVM_BBXDX_CONFIG_1_99(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_1_99(a) "BBXDX_CONFIG_1_99"
#define busnum_CAVM_BBXDX_CONFIG_1_99(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_1_99(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_0
 *
 * BBX4 Configuration Register 20
 * Job Configuration
 */
union cavm_bbxdx_config_2_0
{
    uint64_t u;
    struct cavm_bbxdx_config_2_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t config_2_0_1          : 17; /**< [ 32: 16](R/W) -- */
        uint64_t reserved_4_15         : 12;
        uint64_t config_2_0_0          : 4;  /**< [  3:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_0_0          : 4;  /**< [  3:  0](R/W) -- */
        uint64_t reserved_4_15         : 12;
        uint64_t config_2_0_1          : 17; /**< [ 32: 16](R/W) -- */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_0_s cn; */
};
typedef union cavm_bbxdx_config_2_0 cavm_bbxdx_config_2_0_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_0(a) cavm_bbxdx_config_2_0_t
#define bustype_CAVM_BBXDX_CONFIG_2_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_0(a) "BBXDX_CONFIG_2_0"
#define busnum_CAVM_BBXDX_CONFIG_2_0(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_1
 *
 * BBX4 Configuration Register 21
 * Job Configuration
 */
union cavm_bbxdx_config_2_1
{
    uint64_t u;
    struct cavm_bbxdx_config_2_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_2_1_3          : 28; /**< [ 59: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_1_2          : 13; /**< [ 28: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_1_1          : 7;  /**< [ 12:  6](R/W) -- */
        uint64_t reserved_5            : 1;
        uint64_t config_2_1_0          : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_1_0          : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5            : 1;
        uint64_t config_2_1_1          : 7;  /**< [ 12:  6](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_1_2          : 13; /**< [ 28: 16](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_1_3          : 28; /**< [ 59: 32](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_1_s cn; */
};
typedef union cavm_bbxdx_config_2_1 cavm_bbxdx_config_2_1_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_1(a) cavm_bbxdx_config_2_1_t
#define bustype_CAVM_BBXDX_CONFIG_2_1(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_1(a) "BBXDX_CONFIG_2_1"
#define busnum_CAVM_BBXDX_CONFIG_2_1(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_1(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_10
 *
 * BBX4 Configuration Register 210
 * Job Configuration
 */
union cavm_bbxdx_config_2_10
{
    uint64_t u;
    struct cavm_bbxdx_config_2_10_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_10           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_10           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_10_s cn; */
};
typedef union cavm_bbxdx_config_2_10 cavm_bbxdx_config_2_10_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_10(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_10(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786050ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_10", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_10(a) cavm_bbxdx_config_2_10_t
#define bustype_CAVM_BBXDX_CONFIG_2_10(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_10(a) "BBXDX_CONFIG_2_10"
#define busnum_CAVM_BBXDX_CONFIG_2_10(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_10(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_100
 *
 * BBX4 Configuration Register 2100
 * Job Configuration
 */
union cavm_bbxdx_config_2_100
{
    uint64_t u;
    struct cavm_bbxdx_config_2_100_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_100_8        : 1;  /**< [ 63: 63](R/W) -- */
        uint64_t reserved_61_62        : 2;
        uint64_t config_2_100_7        : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_100_6        : 1;  /**< [ 52: 52](R/W) -- */
        uint64_t reserved_49_51        : 3;
        uint64_t config_2_100_5        : 1;  /**< [ 48: 48](R/W) -- */
        uint64_t reserved_47           : 1;
        uint64_t config_2_100_4        : 7;  /**< [ 46: 40](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_2_100_3        : 7;  /**< [ 38: 32](R/W) -- */
        uint64_t reserved_23_31        : 9;
        uint64_t config_2_100_2        : 7;  /**< [ 22: 16](R/W) -- */
        uint64_t reserved_10_15        : 6;
        uint64_t config_2_100_1        : 2;  /**< [  9:  8](R/W) -- */
        uint64_t reserved_7            : 1;
        uint64_t config_2_100_0        : 7;  /**< [  6:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_100_0        : 7;  /**< [  6:  0](R/W) -- */
        uint64_t reserved_7            : 1;
        uint64_t config_2_100_1        : 2;  /**< [  9:  8](R/W) -- */
        uint64_t reserved_10_15        : 6;
        uint64_t config_2_100_2        : 7;  /**< [ 22: 16](R/W) -- */
        uint64_t reserved_23_31        : 9;
        uint64_t config_2_100_3        : 7;  /**< [ 38: 32](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_2_100_4        : 7;  /**< [ 46: 40](R/W) -- */
        uint64_t reserved_47           : 1;
        uint64_t config_2_100_5        : 1;  /**< [ 48: 48](R/W) -- */
        uint64_t reserved_49_51        : 3;
        uint64_t config_2_100_6        : 1;  /**< [ 52: 52](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_100_7        : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_62        : 2;
        uint64_t config_2_100_8        : 1;  /**< [ 63: 63](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_100_s cn; */
};
typedef union cavm_bbxdx_config_2_100 cavm_bbxdx_config_2_100_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_100(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_100(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786320ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_100", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_100(a) cavm_bbxdx_config_2_100_t
#define bustype_CAVM_BBXDX_CONFIG_2_100(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_100(a) "BBXDX_CONFIG_2_100"
#define busnum_CAVM_BBXDX_CONFIG_2_100(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_100(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_101
 *
 * BBX4 Configuration Register 2101
 * Job Configuration
 */
union cavm_bbxdx_config_2_101
{
    uint64_t u;
    struct cavm_bbxdx_config_2_101_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_2_101          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_101          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_101_s cn; */
};
typedef union cavm_bbxdx_config_2_101 cavm_bbxdx_config_2_101_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_101(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_101(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786328ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_101", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_101(a) cavm_bbxdx_config_2_101_t
#define bustype_CAVM_BBXDX_CONFIG_2_101(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_101(a) "BBXDX_CONFIG_2_101"
#define busnum_CAVM_BBXDX_CONFIG_2_101(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_101(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_102
 *
 * BBX4 Configuration Register 2102
 * Job Configuration
 */
union cavm_bbxdx_config_2_102
{
    uint64_t u;
    struct cavm_bbxdx_config_2_102_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_2_102          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_102          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_102_s cn; */
};
typedef union cavm_bbxdx_config_2_102 cavm_bbxdx_config_2_102_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_102(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_102(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786330ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_102", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_102(a) cavm_bbxdx_config_2_102_t
#define bustype_CAVM_BBXDX_CONFIG_2_102(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_102(a) "BBXDX_CONFIG_2_102"
#define busnum_CAVM_BBXDX_CONFIG_2_102(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_102(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_103
 *
 * BBX4 Configuration Register 2103
 * Job Configuration
 */
union cavm_bbxdx_config_2_103
{
    uint64_t u;
    struct cavm_bbxdx_config_2_103_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_2_103          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_103          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_103_s cn; */
};
typedef union cavm_bbxdx_config_2_103 cavm_bbxdx_config_2_103_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_103(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_103(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786338ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_103", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_103(a) cavm_bbxdx_config_2_103_t
#define bustype_CAVM_BBXDX_CONFIG_2_103(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_103(a) "BBXDX_CONFIG_2_103"
#define busnum_CAVM_BBXDX_CONFIG_2_103(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_103(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_104
 *
 * BBX4 Configuration Register 2104
 * Job Configuration
 */
union cavm_bbxdx_config_2_104
{
    uint64_t u;
    struct cavm_bbxdx_config_2_104_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_2_104          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_104          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_104_s cn; */
};
typedef union cavm_bbxdx_config_2_104 cavm_bbxdx_config_2_104_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_104(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_104(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786340ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_104", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_104(a) cavm_bbxdx_config_2_104_t
#define bustype_CAVM_BBXDX_CONFIG_2_104(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_104(a) "BBXDX_CONFIG_2_104"
#define busnum_CAVM_BBXDX_CONFIG_2_104(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_104(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_105
 *
 * BBX4 Configuration Register 2105
 * Job Configuration
 */
union cavm_bbxdx_config_2_105
{
    uint64_t u;
    struct cavm_bbxdx_config_2_105_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_2_105          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_105          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_105_s cn; */
};
typedef union cavm_bbxdx_config_2_105 cavm_bbxdx_config_2_105_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_105(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_105(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786348ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_105", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_105(a) cavm_bbxdx_config_2_105_t
#define bustype_CAVM_BBXDX_CONFIG_2_105(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_105(a) "BBXDX_CONFIG_2_105"
#define busnum_CAVM_BBXDX_CONFIG_2_105(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_105(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_106
 *
 * BBX4 Configuration Register 2106
 * Job Configuration
 */
union cavm_bbxdx_config_2_106
{
    uint64_t u;
    struct cavm_bbxdx_config_2_106_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_2_106          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_106          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_106_s cn; */
};
typedef union cavm_bbxdx_config_2_106 cavm_bbxdx_config_2_106_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_106(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_106(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786350ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_106", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_106(a) cavm_bbxdx_config_2_106_t
#define bustype_CAVM_BBXDX_CONFIG_2_106(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_106(a) "BBXDX_CONFIG_2_106"
#define busnum_CAVM_BBXDX_CONFIG_2_106(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_106(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_107
 *
 * BBX4 Configuration Register 2107
 * Job Configuration
 */
union cavm_bbxdx_config_2_107
{
    uint64_t u;
    struct cavm_bbxdx_config_2_107_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_2_107          : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_107          : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_107_s cn; */
};
typedef union cavm_bbxdx_config_2_107 cavm_bbxdx_config_2_107_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_107(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_107(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786358ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_107", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_107(a) cavm_bbxdx_config_2_107_t
#define bustype_CAVM_BBXDX_CONFIG_2_107(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_107(a) "BBXDX_CONFIG_2_107"
#define busnum_CAVM_BBXDX_CONFIG_2_107(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_107(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_108
 *
 * BBX4 Configuration Register 2108
 * Job Configuration
 */
union cavm_bbxdx_config_2_108
{
    uint64_t u;
    struct cavm_bbxdx_config_2_108_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_108_1        : 1;  /**< [ 63: 63](R/W) -- */
        uint64_t reserved_31_62        : 32;
        uint64_t config_2_108_0        : 31; /**< [ 30:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_108_0        : 31; /**< [ 30:  0](R/W) -- */
        uint64_t reserved_31_62        : 32;
        uint64_t config_2_108_1        : 1;  /**< [ 63: 63](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_108_s cn; */
};
typedef union cavm_bbxdx_config_2_108 cavm_bbxdx_config_2_108_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_108(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_108(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786360ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_108", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_108(a) cavm_bbxdx_config_2_108_t
#define bustype_CAVM_BBXDX_CONFIG_2_108(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_108(a) "BBXDX_CONFIG_2_108"
#define busnum_CAVM_BBXDX_CONFIG_2_108(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_108(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_11
 *
 * BBX4 Configuration Register 211
 * Job Configuration
 */
union cavm_bbxdx_config_2_11
{
    uint64_t u;
    struct cavm_bbxdx_config_2_11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_11           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_11           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_11_s cn; */
};
typedef union cavm_bbxdx_config_2_11 cavm_bbxdx_config_2_11_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786058ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_11", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_11(a) cavm_bbxdx_config_2_11_t
#define bustype_CAVM_BBXDX_CONFIG_2_11(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_11(a) "BBXDX_CONFIG_2_11"
#define busnum_CAVM_BBXDX_CONFIG_2_11(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_11(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_12
 *
 * BBX4 Configuration Register 212
 * Job Configuration
 */
union cavm_bbxdx_config_2_12
{
    uint64_t u;
    struct cavm_bbxdx_config_2_12_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_12           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_12           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_12_s cn; */
};
typedef union cavm_bbxdx_config_2_12 cavm_bbxdx_config_2_12_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_12(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_12(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786060ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_12", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_12(a) cavm_bbxdx_config_2_12_t
#define bustype_CAVM_BBXDX_CONFIG_2_12(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_12(a) "BBXDX_CONFIG_2_12"
#define busnum_CAVM_BBXDX_CONFIG_2_12(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_12(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_13
 *
 * BBX4 Configuration Register 213
 * Job Configuration
 */
union cavm_bbxdx_config_2_13
{
    uint64_t u;
    struct cavm_bbxdx_config_2_13_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_13           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_13           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_13_s cn; */
};
typedef union cavm_bbxdx_config_2_13 cavm_bbxdx_config_2_13_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_13(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_13(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786068ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_13", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_13(a) cavm_bbxdx_config_2_13_t
#define bustype_CAVM_BBXDX_CONFIG_2_13(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_13(a) "BBXDX_CONFIG_2_13"
#define busnum_CAVM_BBXDX_CONFIG_2_13(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_13(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_14
 *
 * BBX4 Configuration Register 214
 * Job Configuration
 */
union cavm_bbxdx_config_2_14
{
    uint64_t u;
    struct cavm_bbxdx_config_2_14_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_14           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_14           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_14_s cn; */
};
typedef union cavm_bbxdx_config_2_14 cavm_bbxdx_config_2_14_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_14(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_14(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786070ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_14", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_14(a) cavm_bbxdx_config_2_14_t
#define bustype_CAVM_BBXDX_CONFIG_2_14(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_14(a) "BBXDX_CONFIG_2_14"
#define busnum_CAVM_BBXDX_CONFIG_2_14(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_14(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_15
 *
 * BBX4 Configuration Register 215
 * Job Configuration
 */
union cavm_bbxdx_config_2_15
{
    uint64_t u;
    struct cavm_bbxdx_config_2_15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_15           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_15           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_15_s cn; */
};
typedef union cavm_bbxdx_config_2_15 cavm_bbxdx_config_2_15_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786078ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_15", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_15(a) cavm_bbxdx_config_2_15_t
#define bustype_CAVM_BBXDX_CONFIG_2_15(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_15(a) "BBXDX_CONFIG_2_15"
#define busnum_CAVM_BBXDX_CONFIG_2_15(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_15(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_16
 *
 * BBX4 Configuration Register 216
 * Job Configuration
 */
union cavm_bbxdx_config_2_16
{
    uint64_t u;
    struct cavm_bbxdx_config_2_16_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_16           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_16           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_16_s cn; */
};
typedef union cavm_bbxdx_config_2_16 cavm_bbxdx_config_2_16_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_16(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_16(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786080ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_16", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_16(a) cavm_bbxdx_config_2_16_t
#define bustype_CAVM_BBXDX_CONFIG_2_16(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_16(a) "BBXDX_CONFIG_2_16"
#define busnum_CAVM_BBXDX_CONFIG_2_16(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_16(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_17
 *
 * BBX4 Configuration Register 217
 * Job Configuration
 */
union cavm_bbxdx_config_2_17
{
    uint64_t u;
    struct cavm_bbxdx_config_2_17_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_17           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_17           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_17_s cn; */
};
typedef union cavm_bbxdx_config_2_17 cavm_bbxdx_config_2_17_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_17(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_17(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786088ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_17", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_17(a) cavm_bbxdx_config_2_17_t
#define bustype_CAVM_BBXDX_CONFIG_2_17(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_17(a) "BBXDX_CONFIG_2_17"
#define busnum_CAVM_BBXDX_CONFIG_2_17(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_17(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_18
 *
 * BBX4 Configuration Register 218
 * Job Configuration
 */
union cavm_bbxdx_config_2_18
{
    uint64_t u;
    struct cavm_bbxdx_config_2_18_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_18           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_18           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_18_s cn; */
};
typedef union cavm_bbxdx_config_2_18 cavm_bbxdx_config_2_18_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_18(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_18(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786090ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_18", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_18(a) cavm_bbxdx_config_2_18_t
#define bustype_CAVM_BBXDX_CONFIG_2_18(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_18(a) "BBXDX_CONFIG_2_18"
#define busnum_CAVM_BBXDX_CONFIG_2_18(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_18(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_19
 *
 * BBX4 Configuration Register 219
 * Job Configuration
 */
union cavm_bbxdx_config_2_19
{
    uint64_t u;
    struct cavm_bbxdx_config_2_19_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_19           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_19           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_19_s cn; */
};
typedef union cavm_bbxdx_config_2_19 cavm_bbxdx_config_2_19_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786098ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_19", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_19(a) cavm_bbxdx_config_2_19_t
#define bustype_CAVM_BBXDX_CONFIG_2_19(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_19(a) "BBXDX_CONFIG_2_19"
#define busnum_CAVM_BBXDX_CONFIG_2_19(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_19(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_2
 *
 * BBX4 Configuration Register 22
 * Job Configuration
 */
union cavm_bbxdx_config_2_2
{
    uint64_t u;
    struct cavm_bbxdx_config_2_2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_2            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_2            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_2_s cn; */
};
typedef union cavm_bbxdx_config_2_2 cavm_bbxdx_config_2_2_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786010ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_2", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_2(a) cavm_bbxdx_config_2_2_t
#define bustype_CAVM_BBXDX_CONFIG_2_2(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_2(a) "BBXDX_CONFIG_2_2"
#define busnum_CAVM_BBXDX_CONFIG_2_2(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_2(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_20
 *
 * BBX4 Configuration Register 220
 * Job Configuration
 */
union cavm_bbxdx_config_2_20
{
    uint64_t u;
    struct cavm_bbxdx_config_2_20_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_20           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_20           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_20_s cn; */
};
typedef union cavm_bbxdx_config_2_20 cavm_bbxdx_config_2_20_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_20(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_20(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_20", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_20(a) cavm_bbxdx_config_2_20_t
#define bustype_CAVM_BBXDX_CONFIG_2_20(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_20(a) "BBXDX_CONFIG_2_20"
#define busnum_CAVM_BBXDX_CONFIG_2_20(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_20(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_21
 *
 * BBX4 Configuration Register 221
 * Job Configuration
 */
union cavm_bbxdx_config_2_21
{
    uint64_t u;
    struct cavm_bbxdx_config_2_21_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_21           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_21           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_21_s cn; */
};
typedef union cavm_bbxdx_config_2_21 cavm_bbxdx_config_2_21_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_21(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_21(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_21", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_21(a) cavm_bbxdx_config_2_21_t
#define bustype_CAVM_BBXDX_CONFIG_2_21(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_21(a) "BBXDX_CONFIG_2_21"
#define busnum_CAVM_BBXDX_CONFIG_2_21(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_21(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_22
 *
 * BBX4 Configuration Register 222
 * Job Configuration
 */
union cavm_bbxdx_config_2_22
{
    uint64_t u;
    struct cavm_bbxdx_config_2_22_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_22           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_22           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_22_s cn; */
};
typedef union cavm_bbxdx_config_2_22 cavm_bbxdx_config_2_22_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_22(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_22(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_22", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_22(a) cavm_bbxdx_config_2_22_t
#define bustype_CAVM_BBXDX_CONFIG_2_22(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_22(a) "BBXDX_CONFIG_2_22"
#define busnum_CAVM_BBXDX_CONFIG_2_22(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_22(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_23
 *
 * BBX4 Configuration Register 223
 * Job Configuration
 */
union cavm_bbxdx_config_2_23
{
    uint64_t u;
    struct cavm_bbxdx_config_2_23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_23           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_23           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_23_s cn; */
};
typedef union cavm_bbxdx_config_2_23 cavm_bbxdx_config_2_23_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_23", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_23(a) cavm_bbxdx_config_2_23_t
#define bustype_CAVM_BBXDX_CONFIG_2_23(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_23(a) "BBXDX_CONFIG_2_23"
#define busnum_CAVM_BBXDX_CONFIG_2_23(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_23(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_24
 *
 * BBX4 Configuration Register 224
 * Job Configuration
 */
union cavm_bbxdx_config_2_24
{
    uint64_t u;
    struct cavm_bbxdx_config_2_24_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_24           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_24           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_24_s cn; */
};
typedef union cavm_bbxdx_config_2_24 cavm_bbxdx_config_2_24_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_24(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_24(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_24", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_24(a) cavm_bbxdx_config_2_24_t
#define bustype_CAVM_BBXDX_CONFIG_2_24(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_24(a) "BBXDX_CONFIG_2_24"
#define busnum_CAVM_BBXDX_CONFIG_2_24(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_24(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_25
 *
 * BBX4 Configuration Register 225
 * Job Configuration
 */
union cavm_bbxdx_config_2_25
{
    uint64_t u;
    struct cavm_bbxdx_config_2_25_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_25           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_25           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_25_s cn; */
};
typedef union cavm_bbxdx_config_2_25 cavm_bbxdx_config_2_25_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_25(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_25(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_25", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_25(a) cavm_bbxdx_config_2_25_t
#define bustype_CAVM_BBXDX_CONFIG_2_25(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_25(a) "BBXDX_CONFIG_2_25"
#define busnum_CAVM_BBXDX_CONFIG_2_25(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_25(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_26
 *
 * BBX4 Configuration Register 226
 * Job Configuration
 */
union cavm_bbxdx_config_2_26
{
    uint64_t u;
    struct cavm_bbxdx_config_2_26_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_26           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_26           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_26_s cn; */
};
typedef union cavm_bbxdx_config_2_26 cavm_bbxdx_config_2_26_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_26(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_26(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_26", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_26(a) cavm_bbxdx_config_2_26_t
#define bustype_CAVM_BBXDX_CONFIG_2_26(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_26(a) "BBXDX_CONFIG_2_26"
#define busnum_CAVM_BBXDX_CONFIG_2_26(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_26(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_27
 *
 * BBX4 Configuration Register 227
 * Job Configuration
 */
union cavm_bbxdx_config_2_27
{
    uint64_t u;
    struct cavm_bbxdx_config_2_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_27           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_27           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_27_s cn; */
};
typedef union cavm_bbxdx_config_2_27 cavm_bbxdx_config_2_27_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_27", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_27(a) cavm_bbxdx_config_2_27_t
#define bustype_CAVM_BBXDX_CONFIG_2_27(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_27(a) "BBXDX_CONFIG_2_27"
#define busnum_CAVM_BBXDX_CONFIG_2_27(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_27(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_28
 *
 * BBX4 Configuration Register 228
 * Job Configuration
 */
union cavm_bbxdx_config_2_28
{
    uint64_t u;
    struct cavm_bbxdx_config_2_28_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_28           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_28           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_28_s cn; */
};
typedef union cavm_bbxdx_config_2_28 cavm_bbxdx_config_2_28_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_28(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_28(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_28", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_28(a) cavm_bbxdx_config_2_28_t
#define bustype_CAVM_BBXDX_CONFIG_2_28(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_28(a) "BBXDX_CONFIG_2_28"
#define busnum_CAVM_BBXDX_CONFIG_2_28(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_28(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_29
 *
 * BBX4 Configuration Register 229
 * Job Configuration
 */
union cavm_bbxdx_config_2_29
{
    uint64_t u;
    struct cavm_bbxdx_config_2_29_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_29           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_29           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_29_s cn; */
};
typedef union cavm_bbxdx_config_2_29 cavm_bbxdx_config_2_29_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_29(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_29(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_29", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_29(a) cavm_bbxdx_config_2_29_t
#define bustype_CAVM_BBXDX_CONFIG_2_29(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_29(a) "BBXDX_CONFIG_2_29"
#define busnum_CAVM_BBXDX_CONFIG_2_29(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_29(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_3
 *
 * BBX4 Configuration Register 23
 * Job Configuration
 */
union cavm_bbxdx_config_2_3
{
    uint64_t u;
    struct cavm_bbxdx_config_2_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_3            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_3            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_3_s cn; */
};
typedef union cavm_bbxdx_config_2_3 cavm_bbxdx_config_2_3_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_3(a) cavm_bbxdx_config_2_3_t
#define bustype_CAVM_BBXDX_CONFIG_2_3(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_3(a) "BBXDX_CONFIG_2_3"
#define busnum_CAVM_BBXDX_CONFIG_2_3(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_3(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_30
 *
 * BBX4 Configuration Register 230
 * Job Configuration
 */
union cavm_bbxdx_config_2_30
{
    uint64_t u;
    struct cavm_bbxdx_config_2_30_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_30           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_30           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_30_s cn; */
};
typedef union cavm_bbxdx_config_2_30 cavm_bbxdx_config_2_30_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_30(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_30(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_30", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_30(a) cavm_bbxdx_config_2_30_t
#define bustype_CAVM_BBXDX_CONFIG_2_30(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_30(a) "BBXDX_CONFIG_2_30"
#define busnum_CAVM_BBXDX_CONFIG_2_30(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_30(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_31
 *
 * BBX4 Configuration Register 231
 * Job Configuration
 */
union cavm_bbxdx_config_2_31
{
    uint64_t u;
    struct cavm_bbxdx_config_2_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_31           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_31           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_31_s cn; */
};
typedef union cavm_bbxdx_config_2_31 cavm_bbxdx_config_2_31_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437860f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_31", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_31(a) cavm_bbxdx_config_2_31_t
#define bustype_CAVM_BBXDX_CONFIG_2_31(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_31(a) "BBXDX_CONFIG_2_31"
#define busnum_CAVM_BBXDX_CONFIG_2_31(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_31(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_32
 *
 * BBX4 Configuration Register 232
 * Job Configuration
 */
union cavm_bbxdx_config_2_32
{
    uint64_t u;
    struct cavm_bbxdx_config_2_32_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_32           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_32           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_32_s cn; */
};
typedef union cavm_bbxdx_config_2_32 cavm_bbxdx_config_2_32_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_32(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_32(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786100ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_32", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_32(a) cavm_bbxdx_config_2_32_t
#define bustype_CAVM_BBXDX_CONFIG_2_32(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_32(a) "BBXDX_CONFIG_2_32"
#define busnum_CAVM_BBXDX_CONFIG_2_32(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_32(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_33
 *
 * BBX4 Configuration Register 233
 * Job Configuration
 */
union cavm_bbxdx_config_2_33
{
    uint64_t u;
    struct cavm_bbxdx_config_2_33_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_33           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_33           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_33_s cn; */
};
typedef union cavm_bbxdx_config_2_33 cavm_bbxdx_config_2_33_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_33(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_33(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786108ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_33", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_33(a) cavm_bbxdx_config_2_33_t
#define bustype_CAVM_BBXDX_CONFIG_2_33(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_33(a) "BBXDX_CONFIG_2_33"
#define busnum_CAVM_BBXDX_CONFIG_2_33(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_33(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_34
 *
 * BBX4 Configuration Register 234
 * Job Configuration
 */
union cavm_bbxdx_config_2_34
{
    uint64_t u;
    struct cavm_bbxdx_config_2_34_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_34           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_34           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_34_s cn; */
};
typedef union cavm_bbxdx_config_2_34 cavm_bbxdx_config_2_34_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_34(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_34(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786110ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_34", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_34(a) cavm_bbxdx_config_2_34_t
#define bustype_CAVM_BBXDX_CONFIG_2_34(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_34(a) "BBXDX_CONFIG_2_34"
#define busnum_CAVM_BBXDX_CONFIG_2_34(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_34(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_35
 *
 * BBX4 Configuration Register 235
 * Job Configuration
 */
union cavm_bbxdx_config_2_35
{
    uint64_t u;
    struct cavm_bbxdx_config_2_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_35           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_35           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_35_s cn; */
};
typedef union cavm_bbxdx_config_2_35 cavm_bbxdx_config_2_35_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786118ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_35", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_35(a) cavm_bbxdx_config_2_35_t
#define bustype_CAVM_BBXDX_CONFIG_2_35(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_35(a) "BBXDX_CONFIG_2_35"
#define busnum_CAVM_BBXDX_CONFIG_2_35(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_35(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_36
 *
 * BBX4 Configuration Register 236
 * Job Configuration
 */
union cavm_bbxdx_config_2_36
{
    uint64_t u;
    struct cavm_bbxdx_config_2_36_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_36           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_36           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_36_s cn; */
};
typedef union cavm_bbxdx_config_2_36 cavm_bbxdx_config_2_36_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_36(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_36(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786120ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_36", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_36(a) cavm_bbxdx_config_2_36_t
#define bustype_CAVM_BBXDX_CONFIG_2_36(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_36(a) "BBXDX_CONFIG_2_36"
#define busnum_CAVM_BBXDX_CONFIG_2_36(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_36(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_37
 *
 * BBX4 Configuration Register 237
 * Job Configuration
 */
union cavm_bbxdx_config_2_37
{
    uint64_t u;
    struct cavm_bbxdx_config_2_37_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_37           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_37           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_37_s cn; */
};
typedef union cavm_bbxdx_config_2_37 cavm_bbxdx_config_2_37_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_37(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_37(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786128ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_37", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_37(a) cavm_bbxdx_config_2_37_t
#define bustype_CAVM_BBXDX_CONFIG_2_37(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_37(a) "BBXDX_CONFIG_2_37"
#define busnum_CAVM_BBXDX_CONFIG_2_37(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_37(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_38
 *
 * BBX4 Configuration Register 238
 * Job Configuration
 */
union cavm_bbxdx_config_2_38
{
    uint64_t u;
    struct cavm_bbxdx_config_2_38_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_38           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_38           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_38_s cn; */
};
typedef union cavm_bbxdx_config_2_38 cavm_bbxdx_config_2_38_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_38(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_38(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786130ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_38", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_38(a) cavm_bbxdx_config_2_38_t
#define bustype_CAVM_BBXDX_CONFIG_2_38(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_38(a) "BBXDX_CONFIG_2_38"
#define busnum_CAVM_BBXDX_CONFIG_2_38(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_38(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_39
 *
 * BBX4 Configuration Register 239
 * Job Configuration
 */
union cavm_bbxdx_config_2_39
{
    uint64_t u;
    struct cavm_bbxdx_config_2_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_39           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_39           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_39_s cn; */
};
typedef union cavm_bbxdx_config_2_39 cavm_bbxdx_config_2_39_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786138ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_39", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_39(a) cavm_bbxdx_config_2_39_t
#define bustype_CAVM_BBXDX_CONFIG_2_39(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_39(a) "BBXDX_CONFIG_2_39"
#define busnum_CAVM_BBXDX_CONFIG_2_39(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_39(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_4
 *
 * BBX4 Configuration Register 24
 * Job Configuration
 */
union cavm_bbxdx_config_2_4
{
    uint64_t u;
    struct cavm_bbxdx_config_2_4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_4            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_4            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_4_s cn; */
};
typedef union cavm_bbxdx_config_2_4 cavm_bbxdx_config_2_4_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_4(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786020ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_4", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_4(a) cavm_bbxdx_config_2_4_t
#define bustype_CAVM_BBXDX_CONFIG_2_4(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_4(a) "BBXDX_CONFIG_2_4"
#define busnum_CAVM_BBXDX_CONFIG_2_4(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_4(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_40
 *
 * BBX4 Configuration Register 240
 * Job Configuration
 */
union cavm_bbxdx_config_2_40
{
    uint64_t u;
    struct cavm_bbxdx_config_2_40_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_40           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_40           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_40_s cn; */
};
typedef union cavm_bbxdx_config_2_40 cavm_bbxdx_config_2_40_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_40(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_40(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786140ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_40", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_40(a) cavm_bbxdx_config_2_40_t
#define bustype_CAVM_BBXDX_CONFIG_2_40(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_40(a) "BBXDX_CONFIG_2_40"
#define busnum_CAVM_BBXDX_CONFIG_2_40(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_40(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_41
 *
 * BBX4 Configuration Register 241
 * Job Configuration
 */
union cavm_bbxdx_config_2_41
{
    uint64_t u;
    struct cavm_bbxdx_config_2_41_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_41           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_41           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_41_s cn; */
};
typedef union cavm_bbxdx_config_2_41 cavm_bbxdx_config_2_41_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_41(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_41(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786148ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_41", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_41(a) cavm_bbxdx_config_2_41_t
#define bustype_CAVM_BBXDX_CONFIG_2_41(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_41(a) "BBXDX_CONFIG_2_41"
#define busnum_CAVM_BBXDX_CONFIG_2_41(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_41(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_42
 *
 * BBX4 Configuration Register 242
 * Job Configuration
 */
union cavm_bbxdx_config_2_42
{
    uint64_t u;
    struct cavm_bbxdx_config_2_42_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_42           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_42           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_42_s cn; */
};
typedef union cavm_bbxdx_config_2_42 cavm_bbxdx_config_2_42_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_42(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_42(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786150ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_42", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_42(a) cavm_bbxdx_config_2_42_t
#define bustype_CAVM_BBXDX_CONFIG_2_42(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_42(a) "BBXDX_CONFIG_2_42"
#define busnum_CAVM_BBXDX_CONFIG_2_42(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_42(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_43
 *
 * BBX4 Configuration Register 243
 * Job Configuration
 */
union cavm_bbxdx_config_2_43
{
    uint64_t u;
    struct cavm_bbxdx_config_2_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_43           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_43           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_43_s cn; */
};
typedef union cavm_bbxdx_config_2_43 cavm_bbxdx_config_2_43_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786158ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_43", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_43(a) cavm_bbxdx_config_2_43_t
#define bustype_CAVM_BBXDX_CONFIG_2_43(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_43(a) "BBXDX_CONFIG_2_43"
#define busnum_CAVM_BBXDX_CONFIG_2_43(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_43(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_44
 *
 * BBX4 Configuration Register 244
 * Job Configuration
 */
union cavm_bbxdx_config_2_44
{
    uint64_t u;
    struct cavm_bbxdx_config_2_44_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_44           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_44           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_44_s cn; */
};
typedef union cavm_bbxdx_config_2_44 cavm_bbxdx_config_2_44_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_44(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_44(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786160ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_44", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_44(a) cavm_bbxdx_config_2_44_t
#define bustype_CAVM_BBXDX_CONFIG_2_44(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_44(a) "BBXDX_CONFIG_2_44"
#define busnum_CAVM_BBXDX_CONFIG_2_44(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_44(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_45
 *
 * BBX4 Configuration Register 245
 * Job Configuration
 */
union cavm_bbxdx_config_2_45
{
    uint64_t u;
    struct cavm_bbxdx_config_2_45_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_45           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_45           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_45_s cn; */
};
typedef union cavm_bbxdx_config_2_45 cavm_bbxdx_config_2_45_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_45(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_45(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786168ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_45", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_45(a) cavm_bbxdx_config_2_45_t
#define bustype_CAVM_BBXDX_CONFIG_2_45(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_45(a) "BBXDX_CONFIG_2_45"
#define busnum_CAVM_BBXDX_CONFIG_2_45(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_45(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_46
 *
 * BBX4 Configuration Register 246
 * Job Configuration
 */
union cavm_bbxdx_config_2_46
{
    uint64_t u;
    struct cavm_bbxdx_config_2_46_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_46           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_46           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_46_s cn; */
};
typedef union cavm_bbxdx_config_2_46 cavm_bbxdx_config_2_46_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_46(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_46(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786170ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_46", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_46(a) cavm_bbxdx_config_2_46_t
#define bustype_CAVM_BBXDX_CONFIG_2_46(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_46(a) "BBXDX_CONFIG_2_46"
#define busnum_CAVM_BBXDX_CONFIG_2_46(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_46(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_47
 *
 * BBX4 Configuration Register 247
 * Job Configuration
 */
union cavm_bbxdx_config_2_47
{
    uint64_t u;
    struct cavm_bbxdx_config_2_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_47           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_47           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_47_s cn; */
};
typedef union cavm_bbxdx_config_2_47 cavm_bbxdx_config_2_47_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786178ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_47", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_47(a) cavm_bbxdx_config_2_47_t
#define bustype_CAVM_BBXDX_CONFIG_2_47(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_47(a) "BBXDX_CONFIG_2_47"
#define busnum_CAVM_BBXDX_CONFIG_2_47(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_47(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_48
 *
 * BBX4 Configuration Register 248
 * Job Configuration
 */
union cavm_bbxdx_config_2_48
{
    uint64_t u;
    struct cavm_bbxdx_config_2_48_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_48           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_48           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_48_s cn; */
};
typedef union cavm_bbxdx_config_2_48 cavm_bbxdx_config_2_48_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_48(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_48(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786180ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_48", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_48(a) cavm_bbxdx_config_2_48_t
#define bustype_CAVM_BBXDX_CONFIG_2_48(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_48(a) "BBXDX_CONFIG_2_48"
#define busnum_CAVM_BBXDX_CONFIG_2_48(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_48(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_49
 *
 * BBX4 Configuration Register 249
 * Job Configuration
 */
union cavm_bbxdx_config_2_49
{
    uint64_t u;
    struct cavm_bbxdx_config_2_49_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_49           : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_49           : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_49_s cn; */
};
typedef union cavm_bbxdx_config_2_49 cavm_bbxdx_config_2_49_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_49(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_49(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786188ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_49", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_49(a) cavm_bbxdx_config_2_49_t
#define bustype_CAVM_BBXDX_CONFIG_2_49(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_49(a) "BBXDX_CONFIG_2_49"
#define busnum_CAVM_BBXDX_CONFIG_2_49(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_49(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_5
 *
 * BBX4 Configuration Register 25
 * Job Configuration
 */
union cavm_bbxdx_config_2_5
{
    uint64_t u;
    struct cavm_bbxdx_config_2_5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_5            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_5            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_5_s cn; */
};
typedef union cavm_bbxdx_config_2_5 cavm_bbxdx_config_2_5_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_5(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786028ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_5", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_5(a) cavm_bbxdx_config_2_5_t
#define bustype_CAVM_BBXDX_CONFIG_2_5(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_5(a) "BBXDX_CONFIG_2_5"
#define busnum_CAVM_BBXDX_CONFIG_2_5(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_5(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_50
 *
 * BBX4 Configuration Register 250
 * Job Configuration
 */
union cavm_bbxdx_config_2_50
{
    uint64_t u;
    struct cavm_bbxdx_config_2_50_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_50_3         : 16; /**< [ 63: 48](R/W) -- */
        uint64_t reserved_41_47        : 7;
        uint64_t config_2_50_2         : 17; /**< [ 40: 24](R/W) -- */
        uint64_t reserved_23           : 1;
        uint64_t config_2_50_1         : 15; /**< [ 22:  8](R/W) -- */
        uint64_t reserved_2_7          : 6;
        uint64_t config_2_50_0         : 2;  /**< [  1:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_50_0         : 2;  /**< [  1:  0](R/W) -- */
        uint64_t reserved_2_7          : 6;
        uint64_t config_2_50_1         : 15; /**< [ 22:  8](R/W) -- */
        uint64_t reserved_23           : 1;
        uint64_t config_2_50_2         : 17; /**< [ 40: 24](R/W) -- */
        uint64_t reserved_41_47        : 7;
        uint64_t config_2_50_3         : 16; /**< [ 63: 48](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_50_s cn; */
};
typedef union cavm_bbxdx_config_2_50 cavm_bbxdx_config_2_50_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_50(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_50(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786190ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_50", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_50(a) cavm_bbxdx_config_2_50_t
#define bustype_CAVM_BBXDX_CONFIG_2_50(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_50(a) "BBXDX_CONFIG_2_50"
#define busnum_CAVM_BBXDX_CONFIG_2_50(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_50(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_51
 *
 * BBX4 Configuration Register 251
 * Job Configuration
 */
union cavm_bbxdx_config_2_51
{
    uint64_t u;
    struct cavm_bbxdx_config_2_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_51           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_51           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_51_s cn; */
};
typedef union cavm_bbxdx_config_2_51 cavm_bbxdx_config_2_51_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786198ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_51", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_51(a) cavm_bbxdx_config_2_51_t
#define bustype_CAVM_BBXDX_CONFIG_2_51(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_51(a) "BBXDX_CONFIG_2_51"
#define busnum_CAVM_BBXDX_CONFIG_2_51(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_51(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_52
 *
 * BBX4 Configuration Register 252
 * Job Configuration
 */
union cavm_bbxdx_config_2_52
{
    uint64_t u;
    struct cavm_bbxdx_config_2_52_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_52_1         : 32; /**< [ 63: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_52_0         : 29; /**< [ 28:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_52_0         : 29; /**< [ 28:  0](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_52_1         : 32; /**< [ 63: 32](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_52_s cn; */
};
typedef union cavm_bbxdx_config_2_52 cavm_bbxdx_config_2_52_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_52(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_52(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_52", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_52(a) cavm_bbxdx_config_2_52_t
#define bustype_CAVM_BBXDX_CONFIG_2_52(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_52(a) "BBXDX_CONFIG_2_52"
#define busnum_CAVM_BBXDX_CONFIG_2_52(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_52(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_53
 *
 * BBX4 Configuration Register 253
 * Job Configuration
 */
union cavm_bbxdx_config_2_53
{
    uint64_t u;
    struct cavm_bbxdx_config_2_53_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_53_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_53_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_53_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_53_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_53_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_53_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_53_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_53_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_53_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_53_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_53_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_53_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_53_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_53_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_53_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_53_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_53_s cn; */
};
typedef union cavm_bbxdx_config_2_53 cavm_bbxdx_config_2_53_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_53(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_53(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_53", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_53(a) cavm_bbxdx_config_2_53_t
#define bustype_CAVM_BBXDX_CONFIG_2_53(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_53(a) "BBXDX_CONFIG_2_53"
#define busnum_CAVM_BBXDX_CONFIG_2_53(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_53(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_54
 *
 * BBX4 Configuration Register 254
 * Job Configuration
 */
union cavm_bbxdx_config_2_54
{
    uint64_t u;
    struct cavm_bbxdx_config_2_54_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_54_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_54_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_54_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_54_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_54_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_54_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_54_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_54_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_54_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_54_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_54_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_54_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_54_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_54_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_54_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_54_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_54_s cn; */
};
typedef union cavm_bbxdx_config_2_54 cavm_bbxdx_config_2_54_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_54(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_54(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_54", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_54(a) cavm_bbxdx_config_2_54_t
#define bustype_CAVM_BBXDX_CONFIG_2_54(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_54(a) "BBXDX_CONFIG_2_54"
#define busnum_CAVM_BBXDX_CONFIG_2_54(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_54(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_55
 *
 * BBX4 Configuration Register 255
 * Job Configuration
 */
union cavm_bbxdx_config_2_55
{
    uint64_t u;
    struct cavm_bbxdx_config_2_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_55_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_55_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_55_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_55_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_55_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_55_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_55_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_55_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_55_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_55_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_55_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_55_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_55_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_55_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_55_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_55_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_55_s cn; */
};
typedef union cavm_bbxdx_config_2_55 cavm_bbxdx_config_2_55_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_55", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_55(a) cavm_bbxdx_config_2_55_t
#define bustype_CAVM_BBXDX_CONFIG_2_55(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_55(a) "BBXDX_CONFIG_2_55"
#define busnum_CAVM_BBXDX_CONFIG_2_55(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_55(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_56
 *
 * BBX4 Configuration Register 256
 * Job Configuration
 */
union cavm_bbxdx_config_2_56
{
    uint64_t u;
    struct cavm_bbxdx_config_2_56_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_56_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_56_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_56_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_56_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_56_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_56_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_56_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_56_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_56_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_56_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_56_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_56_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_56_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_56_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_56_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_56_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_56_s cn; */
};
typedef union cavm_bbxdx_config_2_56 cavm_bbxdx_config_2_56_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_56(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_56(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_56", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_56(a) cavm_bbxdx_config_2_56_t
#define bustype_CAVM_BBXDX_CONFIG_2_56(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_56(a) "BBXDX_CONFIG_2_56"
#define busnum_CAVM_BBXDX_CONFIG_2_56(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_56(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_57
 *
 * BBX4 Configuration Register 257
 * Job Configuration
 */
union cavm_bbxdx_config_2_57
{
    uint64_t u;
    struct cavm_bbxdx_config_2_57_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_57_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_57_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_57_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_57_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_57_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_57_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_57_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_57_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_57_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_57_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_57_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_57_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_57_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_57_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_57_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_57_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_57_s cn; */
};
typedef union cavm_bbxdx_config_2_57 cavm_bbxdx_config_2_57_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_57(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_57(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_57", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_57(a) cavm_bbxdx_config_2_57_t
#define bustype_CAVM_BBXDX_CONFIG_2_57(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_57(a) "BBXDX_CONFIG_2_57"
#define busnum_CAVM_BBXDX_CONFIG_2_57(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_57(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_58
 *
 * BBX4 Configuration Register 258
 * Job Configuration
 */
union cavm_bbxdx_config_2_58
{
    uint64_t u;
    struct cavm_bbxdx_config_2_58_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_58_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_58_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_58_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_58_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_58_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_58_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_58_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_58_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_58_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_58_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_58_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_58_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_58_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_58_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_58_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_58_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_58_s cn; */
};
typedef union cavm_bbxdx_config_2_58 cavm_bbxdx_config_2_58_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_58(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_58(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_58", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_58(a) cavm_bbxdx_config_2_58_t
#define bustype_CAVM_BBXDX_CONFIG_2_58(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_58(a) "BBXDX_CONFIG_2_58"
#define busnum_CAVM_BBXDX_CONFIG_2_58(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_58(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_59
 *
 * BBX4 Configuration Register 259
 * Job Configuration
 */
union cavm_bbxdx_config_2_59
{
    uint64_t u;
    struct cavm_bbxdx_config_2_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_59_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_59_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_59_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_59_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_59_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_59_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_59_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_59_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_59_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_59_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_59_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_59_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_59_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_59_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_59_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_59_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_59_s cn; */
};
typedef union cavm_bbxdx_config_2_59 cavm_bbxdx_config_2_59_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_59", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_59(a) cavm_bbxdx_config_2_59_t
#define bustype_CAVM_BBXDX_CONFIG_2_59(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_59(a) "BBXDX_CONFIG_2_59"
#define busnum_CAVM_BBXDX_CONFIG_2_59(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_59(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_6
 *
 * BBX4 Configuration Register 26
 * Job Configuration
 */
union cavm_bbxdx_config_2_6
{
    uint64_t u;
    struct cavm_bbxdx_config_2_6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_6            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_6            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_6_s cn; */
};
typedef union cavm_bbxdx_config_2_6 cavm_bbxdx_config_2_6_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_6(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_6", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_6(a) cavm_bbxdx_config_2_6_t
#define bustype_CAVM_BBXDX_CONFIG_2_6(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_6(a) "BBXDX_CONFIG_2_6"
#define busnum_CAVM_BBXDX_CONFIG_2_6(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_6(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_60
 *
 * BBX4 Configuration Register 260
 * Job Configuration
 */
union cavm_bbxdx_config_2_60
{
    uint64_t u;
    struct cavm_bbxdx_config_2_60_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_60_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_60_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_60_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_60_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_60_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_60_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_60_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_60_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_60_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_60_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_60_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_60_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_60_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_60_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_60_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_60_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_60_s cn; */
};
typedef union cavm_bbxdx_config_2_60 cavm_bbxdx_config_2_60_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_60(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_60(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_60", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_60(a) cavm_bbxdx_config_2_60_t
#define bustype_CAVM_BBXDX_CONFIG_2_60(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_60(a) "BBXDX_CONFIG_2_60"
#define busnum_CAVM_BBXDX_CONFIG_2_60(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_60(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_61
 *
 * BBX4 Configuration Register 261
 * Job Configuration
 */
union cavm_bbxdx_config_2_61
{
    uint64_t u;
    struct cavm_bbxdx_config_2_61_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_61_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_61_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_61_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_61_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_61_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_61_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_61_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_61_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_61_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_61_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_61_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_61_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_61_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_61_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_61_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_61_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_61_s cn; */
};
typedef union cavm_bbxdx_config_2_61 cavm_bbxdx_config_2_61_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_61(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_61(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_61", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_61(a) cavm_bbxdx_config_2_61_t
#define bustype_CAVM_BBXDX_CONFIG_2_61(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_61(a) "BBXDX_CONFIG_2_61"
#define busnum_CAVM_BBXDX_CONFIG_2_61(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_61(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_62
 *
 * BBX4 Configuration Register 262
 * Job Configuration
 */
union cavm_bbxdx_config_2_62
{
    uint64_t u;
    struct cavm_bbxdx_config_2_62_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_62_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_62_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_62_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_62_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_62_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_62_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_62_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_62_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_62_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_62_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_62_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_62_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_62_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_62_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_62_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_62_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_62_s cn; */
};
typedef union cavm_bbxdx_config_2_62 cavm_bbxdx_config_2_62_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_62(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_62(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_62", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_62(a) cavm_bbxdx_config_2_62_t
#define bustype_CAVM_BBXDX_CONFIG_2_62(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_62(a) "BBXDX_CONFIG_2_62"
#define busnum_CAVM_BBXDX_CONFIG_2_62(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_62(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_63
 *
 * BBX4 Configuration Register 263
 * Job Configuration
 */
union cavm_bbxdx_config_2_63
{
    uint64_t u;
    struct cavm_bbxdx_config_2_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_63_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_63_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_63_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_63_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_63_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_63_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_63_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_63_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_63_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_63_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_63_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_63_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_63_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_63_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_63_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_63_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_63_s cn; */
};
typedef union cavm_bbxdx_config_2_63 cavm_bbxdx_config_2_63_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437861f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_63", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_63(a) cavm_bbxdx_config_2_63_t
#define bustype_CAVM_BBXDX_CONFIG_2_63(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_63(a) "BBXDX_CONFIG_2_63"
#define busnum_CAVM_BBXDX_CONFIG_2_63(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_63(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_64
 *
 * BBX4 Configuration Register 264
 * Job Configuration
 */
union cavm_bbxdx_config_2_64
{
    uint64_t u;
    struct cavm_bbxdx_config_2_64_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_64_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_64_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_64_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_64_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_64_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_64_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_64_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_64_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_64_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_64_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_64_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_64_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_64_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_64_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_64_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_64_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_64_s cn; */
};
typedef union cavm_bbxdx_config_2_64 cavm_bbxdx_config_2_64_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_64(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_64(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786200ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_64", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_64(a) cavm_bbxdx_config_2_64_t
#define bustype_CAVM_BBXDX_CONFIG_2_64(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_64(a) "BBXDX_CONFIG_2_64"
#define busnum_CAVM_BBXDX_CONFIG_2_64(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_64(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_65
 *
 * BBX4 Configuration Register 265
 * Job Configuration
 */
union cavm_bbxdx_config_2_65
{
    uint64_t u;
    struct cavm_bbxdx_config_2_65_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_65_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_65_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_65_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_65_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_65_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_65_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_65_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_65_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_65_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_65_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_65_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_65_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_65_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_65_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_65_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_65_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_65_s cn; */
};
typedef union cavm_bbxdx_config_2_65 cavm_bbxdx_config_2_65_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_65(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_65(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786208ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_65", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_65(a) cavm_bbxdx_config_2_65_t
#define bustype_CAVM_BBXDX_CONFIG_2_65(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_65(a) "BBXDX_CONFIG_2_65"
#define busnum_CAVM_BBXDX_CONFIG_2_65(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_65(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_66
 *
 * BBX4 Configuration Register 266
 * Job Configuration
 */
union cavm_bbxdx_config_2_66
{
    uint64_t u;
    struct cavm_bbxdx_config_2_66_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t config_2_66_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_66_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_66_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_66_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_66_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_66_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_66_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_66_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_66_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_66_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_66_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_66_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_66_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_66_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_66_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_66_7         : 5;  /**< [ 60: 56](R/W) -- */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_66_s cn; */
};
typedef union cavm_bbxdx_config_2_66 cavm_bbxdx_config_2_66_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_66(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_66(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786210ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_66", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_66(a) cavm_bbxdx_config_2_66_t
#define bustype_CAVM_BBXDX_CONFIG_2_66(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_66(a) "BBXDX_CONFIG_2_66"
#define busnum_CAVM_BBXDX_CONFIG_2_66(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_66(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_67
 *
 * BBX4 Configuration Register 267
 * Job Configuration
 */
union cavm_bbxdx_config_2_67
{
    uint64_t u;
    struct cavm_bbxdx_config_2_67_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_67_7         : 8;  /**< [ 63: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_67_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_67_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_67_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_67_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_67_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_67_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_67_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_67_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_67_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_67_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_67_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_67_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_67_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_67_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_67_7         : 8;  /**< [ 63: 56](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_67_s cn; */
};
typedef union cavm_bbxdx_config_2_67 cavm_bbxdx_config_2_67_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_67(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_67(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786218ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_67", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_67(a) cavm_bbxdx_config_2_67_t
#define bustype_CAVM_BBXDX_CONFIG_2_67(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_67(a) "BBXDX_CONFIG_2_67"
#define busnum_CAVM_BBXDX_CONFIG_2_67(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_67(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_68
 *
 * BBX4 Configuration Register 268
 * Job Configuration
 */
union cavm_bbxdx_config_2_68
{
    uint64_t u;
    struct cavm_bbxdx_config_2_68_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_68_7         : 8;  /**< [ 63: 56](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_68_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_68_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_68_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_68_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_68_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_68_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_68_0         : 5;  /**< [  4:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_68_0         : 5;  /**< [  4:  0](R/W) -- */
        uint64_t reserved_5_7          : 3;
        uint64_t config_2_68_1         : 5;  /**< [ 12:  8](R/W) -- */
        uint64_t reserved_13_15        : 3;
        uint64_t config_2_68_2         : 5;  /**< [ 20: 16](R/W) -- */
        uint64_t reserved_21_23        : 3;
        uint64_t config_2_68_3         : 5;  /**< [ 28: 24](R/W) -- */
        uint64_t reserved_29_31        : 3;
        uint64_t config_2_68_4         : 5;  /**< [ 36: 32](R/W) -- */
        uint64_t reserved_37_39        : 3;
        uint64_t config_2_68_5         : 5;  /**< [ 44: 40](R/W) -- */
        uint64_t reserved_45_47        : 3;
        uint64_t config_2_68_6         : 5;  /**< [ 52: 48](R/W) -- */
        uint64_t reserved_53_55        : 3;
        uint64_t config_2_68_7         : 8;  /**< [ 63: 56](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_68_s cn; */
};
typedef union cavm_bbxdx_config_2_68 cavm_bbxdx_config_2_68_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_68(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_68(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786220ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_68", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_68(a) cavm_bbxdx_config_2_68_t
#define bustype_CAVM_BBXDX_CONFIG_2_68(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_68(a) "BBXDX_CONFIG_2_68"
#define busnum_CAVM_BBXDX_CONFIG_2_68(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_68(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_69
 *
 * BBX4 Configuration Register 269
 * Job Configuration
 */
union cavm_bbxdx_config_2_69
{
    uint64_t u;
    struct cavm_bbxdx_config_2_69_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_69           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_69           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_69_s cn; */
};
typedef union cavm_bbxdx_config_2_69 cavm_bbxdx_config_2_69_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_69(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_69(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786228ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_69", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_69(a) cavm_bbxdx_config_2_69_t
#define bustype_CAVM_BBXDX_CONFIG_2_69(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_69(a) "BBXDX_CONFIG_2_69"
#define busnum_CAVM_BBXDX_CONFIG_2_69(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_69(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_7
 *
 * BBX4 Configuration Register 27
 * Job Configuration
 */
union cavm_bbxdx_config_2_7
{
    uint64_t u;
    struct cavm_bbxdx_config_2_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_7            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_7            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_7_s cn; */
};
typedef union cavm_bbxdx_config_2_7 cavm_bbxdx_config_2_7_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_7", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_7(a) cavm_bbxdx_config_2_7_t
#define bustype_CAVM_BBXDX_CONFIG_2_7(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_7(a) "BBXDX_CONFIG_2_7"
#define busnum_CAVM_BBXDX_CONFIG_2_7(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_7(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_70
 *
 * BBX4 Configuration Register 270
 * Job Configuration
 */
union cavm_bbxdx_config_2_70
{
    uint64_t u;
    struct cavm_bbxdx_config_2_70_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_70           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_70           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_70_s cn; */
};
typedef union cavm_bbxdx_config_2_70 cavm_bbxdx_config_2_70_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_70(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_70(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786230ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_70", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_70(a) cavm_bbxdx_config_2_70_t
#define bustype_CAVM_BBXDX_CONFIG_2_70(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_70(a) "BBXDX_CONFIG_2_70"
#define busnum_CAVM_BBXDX_CONFIG_2_70(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_70(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_71
 *
 * BBX4 Configuration Register 271
 * Job Configuration
 */
union cavm_bbxdx_config_2_71
{
    uint64_t u;
    struct cavm_bbxdx_config_2_71_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_71           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_71           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_71_s cn; */
};
typedef union cavm_bbxdx_config_2_71 cavm_bbxdx_config_2_71_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_71(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_71(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786238ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_71", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_71(a) cavm_bbxdx_config_2_71_t
#define bustype_CAVM_BBXDX_CONFIG_2_71(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_71(a) "BBXDX_CONFIG_2_71"
#define busnum_CAVM_BBXDX_CONFIG_2_71(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_71(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_72
 *
 * BBX4 Configuration Register 272
 * Job Configuration
 */
union cavm_bbxdx_config_2_72
{
    uint64_t u;
    struct cavm_bbxdx_config_2_72_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_72           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_72           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_72_s cn; */
};
typedef union cavm_bbxdx_config_2_72 cavm_bbxdx_config_2_72_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_72(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_72(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786240ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_72", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_72(a) cavm_bbxdx_config_2_72_t
#define bustype_CAVM_BBXDX_CONFIG_2_72(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_72(a) "BBXDX_CONFIG_2_72"
#define busnum_CAVM_BBXDX_CONFIG_2_72(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_72(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_73
 *
 * BBX4 Configuration Register 273
 * Job Configuration
 */
union cavm_bbxdx_config_2_73
{
    uint64_t u;
    struct cavm_bbxdx_config_2_73_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_73           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_73           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_73_s cn; */
};
typedef union cavm_bbxdx_config_2_73 cavm_bbxdx_config_2_73_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_73(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_73(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786248ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_73", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_73(a) cavm_bbxdx_config_2_73_t
#define bustype_CAVM_BBXDX_CONFIG_2_73(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_73(a) "BBXDX_CONFIG_2_73"
#define busnum_CAVM_BBXDX_CONFIG_2_73(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_73(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_74
 *
 * BBX4 Configuration Register 274
 * Job Configuration
 */
union cavm_bbxdx_config_2_74
{
    uint64_t u;
    struct cavm_bbxdx_config_2_74_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_74           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_74           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_74_s cn; */
};
typedef union cavm_bbxdx_config_2_74 cavm_bbxdx_config_2_74_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_74(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_74(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786250ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_74", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_74(a) cavm_bbxdx_config_2_74_t
#define bustype_CAVM_BBXDX_CONFIG_2_74(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_74(a) "BBXDX_CONFIG_2_74"
#define busnum_CAVM_BBXDX_CONFIG_2_74(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_74(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_75
 *
 * BBX4 Configuration Register 275
 * Job Configuration
 */
union cavm_bbxdx_config_2_75
{
    uint64_t u;
    struct cavm_bbxdx_config_2_75_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_75           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_75           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_75_s cn; */
};
typedef union cavm_bbxdx_config_2_75 cavm_bbxdx_config_2_75_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_75(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_75(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786258ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_75", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_75(a) cavm_bbxdx_config_2_75_t
#define bustype_CAVM_BBXDX_CONFIG_2_75(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_75(a) "BBXDX_CONFIG_2_75"
#define busnum_CAVM_BBXDX_CONFIG_2_75(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_75(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_76
 *
 * BBX4 Configuration Register 276
 * Job Configuration
 */
union cavm_bbxdx_config_2_76
{
    uint64_t u;
    struct cavm_bbxdx_config_2_76_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_76           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_76           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_76_s cn; */
};
typedef union cavm_bbxdx_config_2_76 cavm_bbxdx_config_2_76_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_76(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_76(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786260ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_76", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_76(a) cavm_bbxdx_config_2_76_t
#define bustype_CAVM_BBXDX_CONFIG_2_76(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_76(a) "BBXDX_CONFIG_2_76"
#define busnum_CAVM_BBXDX_CONFIG_2_76(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_76(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_77
 *
 * BBX4 Configuration Register 277
 * Job Configuration
 */
union cavm_bbxdx_config_2_77
{
    uint64_t u;
    struct cavm_bbxdx_config_2_77_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_77           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_77           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_77_s cn; */
};
typedef union cavm_bbxdx_config_2_77 cavm_bbxdx_config_2_77_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_77(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_77(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786268ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_77", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_77(a) cavm_bbxdx_config_2_77_t
#define bustype_CAVM_BBXDX_CONFIG_2_77(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_77(a) "BBXDX_CONFIG_2_77"
#define busnum_CAVM_BBXDX_CONFIG_2_77(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_77(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_78
 *
 * BBX4 Configuration Register 278
 * Job Configuration
 */
union cavm_bbxdx_config_2_78
{
    uint64_t u;
    struct cavm_bbxdx_config_2_78_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_78           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_78           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_78_s cn; */
};
typedef union cavm_bbxdx_config_2_78 cavm_bbxdx_config_2_78_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_78(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_78(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786270ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_78", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_78(a) cavm_bbxdx_config_2_78_t
#define bustype_CAVM_BBXDX_CONFIG_2_78(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_78(a) "BBXDX_CONFIG_2_78"
#define busnum_CAVM_BBXDX_CONFIG_2_78(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_78(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_79
 *
 * BBX4 Configuration Register 279
 * Job Configuration
 */
union cavm_bbxdx_config_2_79
{
    uint64_t u;
    struct cavm_bbxdx_config_2_79_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_79           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_79           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_79_s cn; */
};
typedef union cavm_bbxdx_config_2_79 cavm_bbxdx_config_2_79_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_79(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_79(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786278ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_79", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_79(a) cavm_bbxdx_config_2_79_t
#define bustype_CAVM_BBXDX_CONFIG_2_79(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_79(a) "BBXDX_CONFIG_2_79"
#define busnum_CAVM_BBXDX_CONFIG_2_79(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_79(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_8
 *
 * BBX4 Configuration Register 28
 * Job Configuration
 */
union cavm_bbxdx_config_2_8
{
    uint64_t u;
    struct cavm_bbxdx_config_2_8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_8            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_8            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_8_s cn; */
};
typedef union cavm_bbxdx_config_2_8 cavm_bbxdx_config_2_8_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_8(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_8(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_8", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_8(a) cavm_bbxdx_config_2_8_t
#define bustype_CAVM_BBXDX_CONFIG_2_8(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_8(a) "BBXDX_CONFIG_2_8"
#define busnum_CAVM_BBXDX_CONFIG_2_8(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_8(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_80
 *
 * BBX4 Configuration Register 280
 * Job Configuration
 */
union cavm_bbxdx_config_2_80
{
    uint64_t u;
    struct cavm_bbxdx_config_2_80_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_80           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_80           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_80_s cn; */
};
typedef union cavm_bbxdx_config_2_80 cavm_bbxdx_config_2_80_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_80(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_80(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786280ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_80", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_80(a) cavm_bbxdx_config_2_80_t
#define bustype_CAVM_BBXDX_CONFIG_2_80(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_80(a) "BBXDX_CONFIG_2_80"
#define busnum_CAVM_BBXDX_CONFIG_2_80(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_80(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_81
 *
 * BBX4 Configuration Register 281
 * Job Configuration
 */
union cavm_bbxdx_config_2_81
{
    uint64_t u;
    struct cavm_bbxdx_config_2_81_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_81           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_81           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_81_s cn; */
};
typedef union cavm_bbxdx_config_2_81 cavm_bbxdx_config_2_81_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_81(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_81(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786288ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_81", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_81(a) cavm_bbxdx_config_2_81_t
#define bustype_CAVM_BBXDX_CONFIG_2_81(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_81(a) "BBXDX_CONFIG_2_81"
#define busnum_CAVM_BBXDX_CONFIG_2_81(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_81(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_82
 *
 * BBX4 Configuration Register 282
 * Job Configuration
 */
union cavm_bbxdx_config_2_82
{
    uint64_t u;
    struct cavm_bbxdx_config_2_82_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_82           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_82           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_82_s cn; */
};
typedef union cavm_bbxdx_config_2_82 cavm_bbxdx_config_2_82_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_82(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_82(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786290ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_82", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_82(a) cavm_bbxdx_config_2_82_t
#define bustype_CAVM_BBXDX_CONFIG_2_82(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_82(a) "BBXDX_CONFIG_2_82"
#define busnum_CAVM_BBXDX_CONFIG_2_82(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_82(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_83
 *
 * BBX4 Configuration Register 283
 * Job Configuration
 */
union cavm_bbxdx_config_2_83
{
    uint64_t u;
    struct cavm_bbxdx_config_2_83_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_83           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_83           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_83_s cn; */
};
typedef union cavm_bbxdx_config_2_83 cavm_bbxdx_config_2_83_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_83(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_83(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786298ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_83", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_83(a) cavm_bbxdx_config_2_83_t
#define bustype_CAVM_BBXDX_CONFIG_2_83(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_83(a) "BBXDX_CONFIG_2_83"
#define busnum_CAVM_BBXDX_CONFIG_2_83(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_83(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_84
 *
 * BBX4 Configuration Register 284
 * Job Configuration
 */
union cavm_bbxdx_config_2_84
{
    uint64_t u;
    struct cavm_bbxdx_config_2_84_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_84           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_84           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_84_s cn; */
};
typedef union cavm_bbxdx_config_2_84 cavm_bbxdx_config_2_84_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_84(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_84(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_84", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_84(a) cavm_bbxdx_config_2_84_t
#define bustype_CAVM_BBXDX_CONFIG_2_84(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_84(a) "BBXDX_CONFIG_2_84"
#define busnum_CAVM_BBXDX_CONFIG_2_84(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_84(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_85
 *
 * BBX4 Configuration Register 285
 * Job Configuration
 */
union cavm_bbxdx_config_2_85
{
    uint64_t u;
    struct cavm_bbxdx_config_2_85_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_85           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_85           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_85_s cn; */
};
typedef union cavm_bbxdx_config_2_85 cavm_bbxdx_config_2_85_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_85(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_85(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_85", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_85(a) cavm_bbxdx_config_2_85_t
#define bustype_CAVM_BBXDX_CONFIG_2_85(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_85(a) "BBXDX_CONFIG_2_85"
#define busnum_CAVM_BBXDX_CONFIG_2_85(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_85(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_86
 *
 * BBX4 Configuration Register 286
 * Job Configuration
 */
union cavm_bbxdx_config_2_86
{
    uint64_t u;
    struct cavm_bbxdx_config_2_86_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_86           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_86           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_86_s cn; */
};
typedef union cavm_bbxdx_config_2_86 cavm_bbxdx_config_2_86_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_86(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_86(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_86", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_86(a) cavm_bbxdx_config_2_86_t
#define bustype_CAVM_BBXDX_CONFIG_2_86(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_86(a) "BBXDX_CONFIG_2_86"
#define busnum_CAVM_BBXDX_CONFIG_2_86(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_86(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_87
 *
 * BBX4 Configuration Register 287
 * Job Configuration
 */
union cavm_bbxdx_config_2_87
{
    uint64_t u;
    struct cavm_bbxdx_config_2_87_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_87           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_87           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_87_s cn; */
};
typedef union cavm_bbxdx_config_2_87 cavm_bbxdx_config_2_87_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_87(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_87(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_87", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_87(a) cavm_bbxdx_config_2_87_t
#define bustype_CAVM_BBXDX_CONFIG_2_87(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_87(a) "BBXDX_CONFIG_2_87"
#define busnum_CAVM_BBXDX_CONFIG_2_87(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_87(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_88
 *
 * BBX4 Configuration Register 288
 * Job Configuration
 */
union cavm_bbxdx_config_2_88
{
    uint64_t u;
    struct cavm_bbxdx_config_2_88_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_88           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_88           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_88_s cn; */
};
typedef union cavm_bbxdx_config_2_88 cavm_bbxdx_config_2_88_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_88(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_88(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_88", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_88(a) cavm_bbxdx_config_2_88_t
#define bustype_CAVM_BBXDX_CONFIG_2_88(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_88(a) "BBXDX_CONFIG_2_88"
#define busnum_CAVM_BBXDX_CONFIG_2_88(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_88(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_89
 *
 * BBX4 Configuration Register 289
 * Job Configuration
 */
union cavm_bbxdx_config_2_89
{
    uint64_t u;
    struct cavm_bbxdx_config_2_89_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_89           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_89           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_89_s cn; */
};
typedef union cavm_bbxdx_config_2_89 cavm_bbxdx_config_2_89_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_89(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_89(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_89", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_89(a) cavm_bbxdx_config_2_89_t
#define bustype_CAVM_BBXDX_CONFIG_2_89(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_89(a) "BBXDX_CONFIG_2_89"
#define busnum_CAVM_BBXDX_CONFIG_2_89(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_89(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_9
 *
 * BBX4 Configuration Register 29
 * Job Configuration
 */
union cavm_bbxdx_config_2_9
{
    uint64_t u;
    struct cavm_bbxdx_config_2_9_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t config_2_9            : 63; /**< [ 62:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_9            : 63; /**< [ 62:  0](R/W) -- */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_9_s cn; */
};
typedef union cavm_bbxdx_config_2_9 cavm_bbxdx_config_2_9_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_9(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_9(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_9", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_9(a) cavm_bbxdx_config_2_9_t
#define bustype_CAVM_BBXDX_CONFIG_2_9(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_9(a) "BBXDX_CONFIG_2_9"
#define busnum_CAVM_BBXDX_CONFIG_2_9(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_9(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_90
 *
 * BBX4 Configuration Register 290
 * Job Configuration
 */
union cavm_bbxdx_config_2_90
{
    uint64_t u;
    struct cavm_bbxdx_config_2_90_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_90           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_90           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_90_s cn; */
};
typedef union cavm_bbxdx_config_2_90 cavm_bbxdx_config_2_90_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_90(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_90(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_90", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_90(a) cavm_bbxdx_config_2_90_t
#define bustype_CAVM_BBXDX_CONFIG_2_90(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_90(a) "BBXDX_CONFIG_2_90"
#define busnum_CAVM_BBXDX_CONFIG_2_90(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_90(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_91
 *
 * BBX4 Configuration Register 291
 * Job Configuration
 */
union cavm_bbxdx_config_2_91
{
    uint64_t u;
    struct cavm_bbxdx_config_2_91_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_91           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_91           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_91_s cn; */
};
typedef union cavm_bbxdx_config_2_91 cavm_bbxdx_config_2_91_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_91(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_91(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_91", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_91(a) cavm_bbxdx_config_2_91_t
#define bustype_CAVM_BBXDX_CONFIG_2_91(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_91(a) "BBXDX_CONFIG_2_91"
#define busnum_CAVM_BBXDX_CONFIG_2_91(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_91(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_92
 *
 * BBX4 Configuration Register 292
 * Job Configuration
 */
union cavm_bbxdx_config_2_92
{
    uint64_t u;
    struct cavm_bbxdx_config_2_92_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_92           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_92           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_92_s cn; */
};
typedef union cavm_bbxdx_config_2_92 cavm_bbxdx_config_2_92_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_92(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_92(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_92", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_92(a) cavm_bbxdx_config_2_92_t
#define bustype_CAVM_BBXDX_CONFIG_2_92(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_92(a) "BBXDX_CONFIG_2_92"
#define busnum_CAVM_BBXDX_CONFIG_2_92(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_92(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_93
 *
 * BBX4 Configuration Register 293
 * Job Configuration
 */
union cavm_bbxdx_config_2_93
{
    uint64_t u;
    struct cavm_bbxdx_config_2_93_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_93           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_93           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_93_s cn; */
};
typedef union cavm_bbxdx_config_2_93 cavm_bbxdx_config_2_93_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_93(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_93(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_93", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_93(a) cavm_bbxdx_config_2_93_t
#define bustype_CAVM_BBXDX_CONFIG_2_93(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_93(a) "BBXDX_CONFIG_2_93"
#define busnum_CAVM_BBXDX_CONFIG_2_93(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_93(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_94
 *
 * BBX4 Configuration Register 294
 * Job Configuration
 */
union cavm_bbxdx_config_2_94
{
    uint64_t u;
    struct cavm_bbxdx_config_2_94_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_94           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_94           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_94_s cn; */
};
typedef union cavm_bbxdx_config_2_94 cavm_bbxdx_config_2_94_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_94(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_94(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_94", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_94(a) cavm_bbxdx_config_2_94_t
#define bustype_CAVM_BBXDX_CONFIG_2_94(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_94(a) "BBXDX_CONFIG_2_94"
#define busnum_CAVM_BBXDX_CONFIG_2_94(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_94(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_95
 *
 * BBX4 Configuration Register 295
 * Job Configuration
 */
union cavm_bbxdx_config_2_95
{
    uint64_t u;
    struct cavm_bbxdx_config_2_95_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_2_95           : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_95           : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_95_s cn; */
};
typedef union cavm_bbxdx_config_2_95 cavm_bbxdx_config_2_95_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_95(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_95(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e0437862f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_95", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_95(a) cavm_bbxdx_config_2_95_t
#define bustype_CAVM_BBXDX_CONFIG_2_95(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_95(a) "BBXDX_CONFIG_2_95"
#define busnum_CAVM_BBXDX_CONFIG_2_95(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_95(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_96
 *
 * BBX4 Configuration Register 296
 * Job Configuration
 */
union cavm_bbxdx_config_2_96
{
    uint64_t u;
    struct cavm_bbxdx_config_2_96_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t config_2_96           : 32; /**< [ 31:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_96           : 32; /**< [ 31:  0](R/W) -- */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_96_s cn; */
};
typedef union cavm_bbxdx_config_2_96 cavm_bbxdx_config_2_96_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_96(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_96(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786300ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_96", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_96(a) cavm_bbxdx_config_2_96_t
#define bustype_CAVM_BBXDX_CONFIG_2_96(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_96(a) "BBXDX_CONFIG_2_96"
#define busnum_CAVM_BBXDX_CONFIG_2_96(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_96(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_97
 *
 * BBX4 Configuration Register 297
 * Job Configuration
 */
union cavm_bbxdx_config_2_97
{
    uint64_t u;
    struct cavm_bbxdx_config_2_97_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_2_97           : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_97           : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_97_s cn; */
};
typedef union cavm_bbxdx_config_2_97 cavm_bbxdx_config_2_97_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_97(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_97(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786308ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_97", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_97(a) cavm_bbxdx_config_2_97_t
#define bustype_CAVM_BBXDX_CONFIG_2_97(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_97(a) "BBXDX_CONFIG_2_97"
#define busnum_CAVM_BBXDX_CONFIG_2_97(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_97(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_98
 *
 * BBX4 Configuration Register 298
 * Job Configuration
 */
union cavm_bbxdx_config_2_98
{
    uint64_t u;
    struct cavm_bbxdx_config_2_98_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_2_98           : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_98           : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_98_s cn; */
};
typedef union cavm_bbxdx_config_2_98 cavm_bbxdx_config_2_98_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_98(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_98(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786310ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_98", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_98(a) cavm_bbxdx_config_2_98_t
#define bustype_CAVM_BBXDX_CONFIG_2_98(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_98(a) "BBXDX_CONFIG_2_98"
#define busnum_CAVM_BBXDX_CONFIG_2_98(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_98(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_config_2_99
 *
 * BBX4 Configuration Register 299
 * Job Configuration
 */
union cavm_bbxdx_config_2_99
{
    uint64_t u;
    struct cavm_bbxdx_config_2_99_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t config_2_99           : 9;  /**< [  8:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_2_99           : 9;  /**< [  8:  0](R/W) -- */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_config_2_99_s cn; */
};
typedef union cavm_bbxdx_config_2_99 cavm_bbxdx_config_2_99_t;

static inline uint64_t CAVM_BBXDX_CONFIG_2_99(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONFIG_2_99(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043786318ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONFIG_2_99", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONFIG_2_99(a) cavm_bbxdx_config_2_99_t
#define bustype_CAVM_BBXDX_CONFIG_2_99(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONFIG_2_99(a) "BBXDX_CONFIG_2_99"
#define busnum_CAVM_BBXDX_CONFIG_2_99(a) (a)
#define arguments_CAVM_BBXDX_CONFIG_2_99(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_control_main
 *
 * BBX4 Main Control Register
 * HAB Control
 */
union cavm_bbxdx_control_main
{
    uint64_t u;
    struct cavm_bbxdx_control_main_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_id_2              : 16; /**< [ 63: 48](R/W) Job ID 2 */
        uint64_t job_id_1              : 16; /**< [ 47: 32](R/W) Job ID 1 */
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t job_id_0              : 16; /**< [ 31: 16](R/W) Job ID 0 */
        uint64_t job_id_1              : 16; /**< [ 47: 32](R/W) Job ID 1 */
        uint64_t job_id_2              : 16; /**< [ 63: 48](R/W) Job ID 2 */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_control_main_s cn; */
};
typedef union cavm_bbxdx_control_main cavm_bbxdx_control_main_t;

static inline uint64_t CAVM_BBXDX_CONTROL_MAIN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONTROL_MAIN(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043780000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONTROL_MAIN", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONTROL_MAIN(a) cavm_bbxdx_control_main_t
#define bustype_CAVM_BBXDX_CONTROL_MAIN(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONTROL_MAIN(a) "BBXDX_CONTROL_MAIN"
#define busnum_CAVM_BBXDX_CONTROL_MAIN(a) (a)
#define arguments_CAVM_BBXDX_CONTROL_MAIN(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_control_status
 *
 * BBX4 Status Register
 * HAB Control
 */
union cavm_bbxdx_control_status
{
    uint64_t u;
    struct cavm_bbxdx_control_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO) Ready to receive the next job */
        uint64_t reserved_3            : 1;
        uint64_t busy_2                : 1;  /**< [  2:  2](RO) Busy for CONFIGURATION 2 */
        uint64_t busy_1                : 1;  /**< [  1:  1](RO) Busy for CONFIGURATION 1 */
        uint64_t busy_0                : 1;  /**< [  0:  0](RO) Busy for CONFIGURATION 0 */
#else /* Word 0 - Little Endian */
        uint64_t busy_0                : 1;  /**< [  0:  0](RO) Busy for CONFIGURATION 0 */
        uint64_t busy_1                : 1;  /**< [  1:  1](RO) Busy for CONFIGURATION 1 */
        uint64_t busy_2                : 1;  /**< [  2:  2](RO) Busy for CONFIGURATION 2 */
        uint64_t reserved_3            : 1;
        uint64_t ready                 : 1;  /**< [  4:  4](RO) Ready to receive the next job */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_control_status_s cn; */
};
typedef union cavm_bbxdx_control_status cavm_bbxdx_control_status_t;

static inline uint64_t CAVM_BBXDX_CONTROL_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_CONTROL_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043780018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_CONTROL_STATUS", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_CONTROL_STATUS(a) cavm_bbxdx_control_status_t
#define bustype_CAVM_BBXDX_CONTROL_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_CONTROL_STATUS(a) "BBXDX_CONTROL_STATUS"
#define busnum_CAVM_BBXDX_CONTROL_STATUS(a) (a)
#define arguments_CAVM_BBXDX_CONTROL_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_debug_0
 *
 * BBX4 Debug Register 0
 * HAB information
 */
union cavm_bbxdx_debug_0
{
    uint64_t u;
    struct cavm_bbxdx_debug_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t hab_info              : 32; /**< [ 31:  0](RO) BBX4 RTL Version */
#else /* Word 0 - Little Endian */
        uint64_t hab_info              : 32; /**< [ 31:  0](RO) BBX4 RTL Version */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_debug_0_s cn; */
};
typedef union cavm_bbxdx_debug_0 cavm_bbxdx_debug_0_t;

static inline uint64_t CAVM_BBXDX_DEBUG_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_DEBUG_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043781000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_DEBUG_0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_DEBUG_0(a) cavm_bbxdx_debug_0_t
#define bustype_CAVM_BBXDX_DEBUG_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_DEBUG_0(a) "BBXDX_DEBUG_0"
#define busnum_CAVM_BBXDX_DEBUG_0(a) (a)
#define arguments_CAVM_BBXDX_DEBUG_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_debug_01
 *
 * BBX4 Debug Register 1
 * AB Processing Throught for job
 */
union cavm_bbxdx_debug_01
{
    uint64_t u;
    struct cavm_bbxdx_debug_01_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t read_if_throughput_job : 32;/**< [ 63: 32](RO) clock count with 1Ghz through the Read IF */
        uint64_t opr_throughput        : 32; /**< [ 31:  0](RO) clock count with 1Ghz through the Write IF */
#else /* Word 0 - Little Endian */
        uint64_t opr_throughput        : 32; /**< [ 31:  0](RO) clock count with 1Ghz through the Write IF */
        uint64_t read_if_throughput_job : 32;/**< [ 63: 32](RO) clock count with 1Ghz through the Read IF */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_debug_01_s cn; */
};
typedef union cavm_bbxdx_debug_01 cavm_bbxdx_debug_01_t;

static inline uint64_t CAVM_BBXDX_DEBUG_01(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_DEBUG_01(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043781008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_DEBUG_01", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_DEBUG_01(a) cavm_bbxdx_debug_01_t
#define bustype_CAVM_BBXDX_DEBUG_01(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_DEBUG_01(a) "BBXDX_DEBUG_01"
#define busnum_CAVM_BBXDX_DEBUG_01(a) (a)
#define arguments_CAVM_BBXDX_DEBUG_01(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_error_register_0
 *
 * BBX4 Error Register 0
 * HAB Control
 */
union cavm_bbxdx_error_register_0
{
    uint64_t u;
    struct cavm_bbxdx_error_register_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t job_id_dma_error_2    : 16; /**< [ 63: 48](R/W1C) Job ID 2 for DMA error */
        uint64_t job_id_dma_error_1    : 16; /**< [ 47: 32](R/W1C) Job ID 1 for DMA error */
        uint64_t job_id_dma_error_0    : 16; /**< [ 31: 16](R/W1C) Job ID 0 for DMA error */
        uint64_t reserved_5_15         : 11;
        uint64_t rp0_overflow          : 1;  /**< [  4:  4](R/W1C) Read Port 0 Overflow */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_underflow         : 1;  /**< [  0:  0](R/W1C) Read Port 0 Underflow */
#else /* Word 0 - Little Endian */
        uint64_t rp0_underflow         : 1;  /**< [  0:  0](R/W1C) Read Port 0 Underflow */
        uint64_t reserved_1_3          : 3;
        uint64_t rp0_overflow          : 1;  /**< [  4:  4](R/W1C) Read Port 0 Overflow */
        uint64_t reserved_5_15         : 11;
        uint64_t job_id_dma_error_0    : 16; /**< [ 31: 16](R/W1C) Job ID 0 for DMA error */
        uint64_t job_id_dma_error_1    : 16; /**< [ 47: 32](R/W1C) Job ID 1 for DMA error */
        uint64_t job_id_dma_error_2    : 16; /**< [ 63: 48](R/W1C) Job ID 2 for DMA error */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_error_register_0_s cn; */
};
typedef union cavm_bbxdx_error_register_0 cavm_bbxdx_error_register_0_t;

static inline uint64_t CAVM_BBXDX_ERROR_REGISTER_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_ERROR_REGISTER_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043780030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_ERROR_REGISTER_0", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_ERROR_REGISTER_0(a) cavm_bbxdx_error_register_0_t
#define bustype_CAVM_BBXDX_ERROR_REGISTER_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_ERROR_REGISTER_0(a) "BBXDX_ERROR_REGISTER_0"
#define busnum_CAVM_BBXDX_ERROR_REGISTER_0(a) (a)
#define arguments_CAVM_BBXDX_ERROR_REGISTER_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_error_register_1
 *
 * BBX4 Error Register 1
 * HAB Control
 */
union cavm_bbxdx_error_register_1
{
    uint64_t u;
    struct cavm_bbxdx_error_register_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t inter_err_job_id_2    : 16; /**< [ 63: 48](R/W1C) internal error jib ID 2 for Error Register 1 */
        uint64_t inter_err_job_id_1    : 16; /**< [ 47: 32](R/W1C) internal error jib ID 1 for Error Register 1 */
        uint64_t inter_err_job_id_0    : 16; /**< [ 31: 16](R/W1C) internal error jib ID 0 for Error Register 1 */
        uint64_t reserved_13_15        : 3;
        uint64_t job_error_3           : 1;  /**< [ 12: 12](R/W1C) Job error 3 */
        uint64_t reserved_9_11         : 3;
        uint64_t job_error_2           : 1;  /**< [  8:  8](R/W1C) Job error 2 */
        uint64_t reserved_5_7          : 3;
        uint64_t irc_job_error_1       : 1;  /**< [  4:  4](R/W1C) IRC and job error 1 */
        uint64_t reserved_1_3          : 3;
        uint64_t job_error_0           : 1;  /**< [  0:  0](R/W1C) Job error 0 */
#else /* Word 0 - Little Endian */
        uint64_t job_error_0           : 1;  /**< [  0:  0](R/W1C) Job error 0 */
        uint64_t reserved_1_3          : 3;
        uint64_t irc_job_error_1       : 1;  /**< [  4:  4](R/W1C) IRC and job error 1 */
        uint64_t reserved_5_7          : 3;
        uint64_t job_error_2           : 1;  /**< [  8:  8](R/W1C) Job error 2 */
        uint64_t reserved_9_11         : 3;
        uint64_t job_error_3           : 1;  /**< [ 12: 12](R/W1C) Job error 3 */
        uint64_t reserved_13_15        : 3;
        uint64_t inter_err_job_id_0    : 16; /**< [ 31: 16](R/W1C) internal error jib ID 0 for Error Register 1 */
        uint64_t inter_err_job_id_1    : 16; /**< [ 47: 32](R/W1C) internal error jib ID 1 for Error Register 1 */
        uint64_t inter_err_job_id_2    : 16; /**< [ 63: 48](R/W1C) internal error jib ID 2 for Error Register 1 */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_error_register_1_s cn; */
};
typedef union cavm_bbxdx_error_register_1 cavm_bbxdx_error_register_1_t;

static inline uint64_t CAVM_BBXDX_ERROR_REGISTER_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_ERROR_REGISTER_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043780038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_ERROR_REGISTER_1", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_ERROR_REGISTER_1(a) cavm_bbxdx_error_register_1_t
#define bustype_CAVM_BBXDX_ERROR_REGISTER_1(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_ERROR_REGISTER_1(a) "BBXDX_ERROR_REGISTER_1"
#define busnum_CAVM_BBXDX_ERROR_REGISTER_1(a) (a)
#define arguments_CAVM_BBXDX_ERROR_REGISTER_1(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_error_register_2
 *
 * BBX4 Error Register 2
 * HAB Control
 */
union cavm_bbxdx_error_register_2
{
    uint64_t u;
    struct cavm_bbxdx_error_register_2_s
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
    /* struct cavm_bbxdx_error_register_2_s cn; */
};
typedef union cavm_bbxdx_error_register_2 cavm_bbxdx_error_register_2_t;

static inline uint64_t CAVM_BBXDX_ERROR_REGISTER_2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_ERROR_REGISTER_2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043780040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_ERROR_REGISTER_2", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_ERROR_REGISTER_2(a) cavm_bbxdx_error_register_2_t
#define bustype_CAVM_BBXDX_ERROR_REGISTER_2(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_ERROR_REGISTER_2(a) "BBXDX_ERROR_REGISTER_2"
#define busnum_CAVM_BBXDX_ERROR_REGISTER_2(a) (a)
#define arguments_CAVM_BBXDX_ERROR_REGISTER_2(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxd#_error_register_3
 *
 * BBX4 Error Register 3
 * HAB Control
 */
union cavm_bbxdx_error_register_3
{
    uint64_t u;
    struct cavm_bbxdx_error_register_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t hab_error_en          : 1;  /**< [  0:  0](R/W) HAB specific Error Enable */
#else /* Word 0 - Little Endian */
        uint64_t hab_error_en          : 1;  /**< [  0:  0](R/W) HAB specific Error Enable */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxdx_error_register_3_s cn; */
};
typedef union cavm_bbxdx_error_register_3 cavm_bbxdx_error_register_3_t;

static inline uint64_t CAVM_BBXDX_ERROR_REGISTER_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXDX_ERROR_REGISTER_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043780048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXDX_ERROR_REGISTER_3", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_BBXDX_ERROR_REGISTER_3(a) cavm_bbxdx_error_register_3_t
#define bustype_CAVM_BBXDX_ERROR_REGISTER_3(a) CSR_TYPE_RSL
#define basename_CAVM_BBXDX_ERROR_REGISTER_3(a) "BBXDX_ERROR_REGISTER_3"
#define busnum_CAVM_BBXDX_ERROR_REGISTER_3(a) (a)
#define arguments_CAVM_BBXDX_ERROR_REGISTER_3(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_BBXD_H__ */
