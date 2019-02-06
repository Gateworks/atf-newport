#ifndef __CAVM_CSRS_BBXF_H__
#define __CAVM_CSRS_BBXF_H__
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
 * OcteonTX BBXF.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) bbxf#_config_0
 *
 * BBX6 Configuration Register 0
 * Job Configuration
 */
union cavm_bbxfx_config_0
{
    uint64_t u;
    struct cavm_bbxfx_config_0_s
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
    /* struct cavm_bbxfx_config_0_s cn; */
};
typedef union cavm_bbxfx_config_0 cavm_bbxfx_config_0_t;

static inline uint64_t CAVM_BBXFX_CONFIG_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_0(a) cavm_bbxfx_config_0_t
#define bustype_CAVM_BBXFX_CONFIG_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_0(a) "BBXFX_CONFIG_0"
#define busnum_CAVM_BBXFX_CONFIG_0(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_1
 *
 * BBX6 Configuration Register 1
 * Job Configuration
 */
union cavm_bbxfx_config_1
{
    uint64_t u;
    struct cavm_bbxfx_config_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f_6            : 4;  /**< [ 63: 60](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_5            : 7;  /**< [ 58: 52](R/W) -- */
        uint64_t reserved_51           : 1;
        uint64_t config_f_4            : 19; /**< [ 50: 32](R/W) -- */
        uint64_t reserved_31           : 1;
        uint64_t config_f_3            : 19; /**< [ 30: 12](R/W) -- */
        uint64_t reserved_11           : 1;
        uint64_t config_f_2            : 3;  /**< [ 10:  8](R/W) -- */
        uint64_t reserved_7            : 1;
        uint64_t config_f_1            : 3;  /**< [  6:  4](R/W) -- */
        uint64_t reserved_3            : 1;
        uint64_t config_f_0            : 3;  /**< [  2:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 3;  /**< [  2:  0](R/W) -- */
        uint64_t reserved_3            : 1;
        uint64_t config_f_1            : 3;  /**< [  6:  4](R/W) -- */
        uint64_t reserved_7            : 1;
        uint64_t config_f_2            : 3;  /**< [ 10:  8](R/W) -- */
        uint64_t reserved_11           : 1;
        uint64_t config_f_3            : 19; /**< [ 30: 12](R/W) -- */
        uint64_t reserved_31           : 1;
        uint64_t config_f_4            : 19; /**< [ 50: 32](R/W) -- */
        uint64_t reserved_51           : 1;
        uint64_t config_f_5            : 7;  /**< [ 58: 52](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_6            : 4;  /**< [ 63: 60](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_1_s cn; */
};
typedef union cavm_bbxfx_config_1 cavm_bbxfx_config_1_t;

static inline uint64_t CAVM_BBXFX_CONFIG_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_1(a) cavm_bbxfx_config_1_t
#define bustype_CAVM_BBXFX_CONFIG_1(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_1(a) "BBXFX_CONFIG_1"
#define busnum_CAVM_BBXFX_CONFIG_1(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_1(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_10
 *
 * BBX6 Configuration Register 10
 * Job Configuration
 */
union cavm_bbxfx_config_10
{
    uint64_t u;
    struct cavm_bbxfx_config_10_s
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
    /* struct cavm_bbxfx_config_10_s cn; */
};
typedef union cavm_bbxfx_config_10 cavm_bbxfx_config_10_t;

static inline uint64_t CAVM_BBXFX_CONFIG_10(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_10(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82050ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_10", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_10(a) cavm_bbxfx_config_10_t
#define bustype_CAVM_BBXFX_CONFIG_10(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_10(a) "BBXFX_CONFIG_10"
#define busnum_CAVM_BBXFX_CONFIG_10(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_10(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_100
 *
 * BBX6 Configuration Register 100
 * Job Configuration
 */
union cavm_bbxfx_config_100
{
    uint64_t u;
    struct cavm_bbxfx_config_100_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_100_s cn; */
};
typedef union cavm_bbxfx_config_100 cavm_bbxfx_config_100_t;

static inline uint64_t CAVM_BBXFX_CONFIG_100(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_100(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82320ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_100", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_100(a) cavm_bbxfx_config_100_t
#define bustype_CAVM_BBXFX_CONFIG_100(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_100(a) "BBXFX_CONFIG_100"
#define busnum_CAVM_BBXFX_CONFIG_100(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_100(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_101
 *
 * BBX6 Configuration Register 101
 * Job Configuration
 */
union cavm_bbxfx_config_101
{
    uint64_t u;
    struct cavm_bbxfx_config_101_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_101_s cn; */
};
typedef union cavm_bbxfx_config_101 cavm_bbxfx_config_101_t;

static inline uint64_t CAVM_BBXFX_CONFIG_101(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_101(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82328ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_101", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_101(a) cavm_bbxfx_config_101_t
#define bustype_CAVM_BBXFX_CONFIG_101(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_101(a) "BBXFX_CONFIG_101"
#define busnum_CAVM_BBXFX_CONFIG_101(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_101(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_102
 *
 * BBX6 Configuration Register 102
 * Job Configuration
 */
union cavm_bbxfx_config_102
{
    uint64_t u;
    struct cavm_bbxfx_config_102_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_102_s cn; */
};
typedef union cavm_bbxfx_config_102 cavm_bbxfx_config_102_t;

static inline uint64_t CAVM_BBXFX_CONFIG_102(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_102(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82330ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_102", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_102(a) cavm_bbxfx_config_102_t
#define bustype_CAVM_BBXFX_CONFIG_102(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_102(a) "BBXFX_CONFIG_102"
#define busnum_CAVM_BBXFX_CONFIG_102(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_102(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_103
 *
 * BBX6 Configuration Register 103
 * Job Configuration
 */
union cavm_bbxfx_config_103
{
    uint64_t u;
    struct cavm_bbxfx_config_103_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_103_s cn; */
};
typedef union cavm_bbxfx_config_103 cavm_bbxfx_config_103_t;

static inline uint64_t CAVM_BBXFX_CONFIG_103(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_103(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82338ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_103", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_103(a) cavm_bbxfx_config_103_t
#define bustype_CAVM_BBXFX_CONFIG_103(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_103(a) "BBXFX_CONFIG_103"
#define busnum_CAVM_BBXFX_CONFIG_103(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_103(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_104
 *
 * BBX6 Configuration Register 104
 * Job Configuration
 */
union cavm_bbxfx_config_104
{
    uint64_t u;
    struct cavm_bbxfx_config_104_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_104_s cn; */
};
typedef union cavm_bbxfx_config_104 cavm_bbxfx_config_104_t;

static inline uint64_t CAVM_BBXFX_CONFIG_104(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_104(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82340ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_104", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_104(a) cavm_bbxfx_config_104_t
#define bustype_CAVM_BBXFX_CONFIG_104(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_104(a) "BBXFX_CONFIG_104"
#define busnum_CAVM_BBXFX_CONFIG_104(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_104(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_105
 *
 * BBX6 Configuration Register 105
 * Job Configuration
 */
union cavm_bbxfx_config_105
{
    uint64_t u;
    struct cavm_bbxfx_config_105_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_105_s cn; */
};
typedef union cavm_bbxfx_config_105 cavm_bbxfx_config_105_t;

static inline uint64_t CAVM_BBXFX_CONFIG_105(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_105(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82348ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_105", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_105(a) cavm_bbxfx_config_105_t
#define bustype_CAVM_BBXFX_CONFIG_105(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_105(a) "BBXFX_CONFIG_105"
#define busnum_CAVM_BBXFX_CONFIG_105(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_105(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_106
 *
 * BBX6 Configuration Register 106
 * Job Configuration
 */
union cavm_bbxfx_config_106
{
    uint64_t u;
    struct cavm_bbxfx_config_106_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_106_s cn; */
};
typedef union cavm_bbxfx_config_106 cavm_bbxfx_config_106_t;

static inline uint64_t CAVM_BBXFX_CONFIG_106(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_106(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82350ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_106", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_106(a) cavm_bbxfx_config_106_t
#define bustype_CAVM_BBXFX_CONFIG_106(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_106(a) "BBXFX_CONFIG_106"
#define busnum_CAVM_BBXFX_CONFIG_106(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_106(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_107
 *
 * BBX6 Configuration Register 107
 * Job Configuration
 */
union cavm_bbxfx_config_107
{
    uint64_t u;
    struct cavm_bbxfx_config_107_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_107_s cn; */
};
typedef union cavm_bbxfx_config_107 cavm_bbxfx_config_107_t;

static inline uint64_t CAVM_BBXFX_CONFIG_107(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_107(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82358ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_107", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_107(a) cavm_bbxfx_config_107_t
#define bustype_CAVM_BBXFX_CONFIG_107(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_107(a) "BBXFX_CONFIG_107"
#define busnum_CAVM_BBXFX_CONFIG_107(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_107(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_108
 *
 * BBX6 Configuration Register 108
 * Job Configuration
 */
union cavm_bbxfx_config_108
{
    uint64_t u;
    struct cavm_bbxfx_config_108_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_108_s cn; */
};
typedef union cavm_bbxfx_config_108 cavm_bbxfx_config_108_t;

static inline uint64_t CAVM_BBXFX_CONFIG_108(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_108(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82360ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_108", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_108(a) cavm_bbxfx_config_108_t
#define bustype_CAVM_BBXFX_CONFIG_108(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_108(a) "BBXFX_CONFIG_108"
#define busnum_CAVM_BBXFX_CONFIG_108(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_108(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_109
 *
 * BBX6 Configuration Register 109
 * Job Configuration
 */
union cavm_bbxfx_config_109
{
    uint64_t u;
    struct cavm_bbxfx_config_109_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_109_s cn; */
};
typedef union cavm_bbxfx_config_109 cavm_bbxfx_config_109_t;

static inline uint64_t CAVM_BBXFX_CONFIG_109(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_109(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82368ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_109", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_109(a) cavm_bbxfx_config_109_t
#define bustype_CAVM_BBXFX_CONFIG_109(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_109(a) "BBXFX_CONFIG_109"
#define busnum_CAVM_BBXFX_CONFIG_109(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_109(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_11
 *
 * BBX6 Configuration Register 11
 * Job Configuration
 */
union cavm_bbxfx_config_11
{
    uint64_t u;
    struct cavm_bbxfx_config_11_s
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
    /* struct cavm_bbxfx_config_11_s cn; */
};
typedef union cavm_bbxfx_config_11 cavm_bbxfx_config_11_t;

static inline uint64_t CAVM_BBXFX_CONFIG_11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_11(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82058ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_11", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_11(a) cavm_bbxfx_config_11_t
#define bustype_CAVM_BBXFX_CONFIG_11(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_11(a) "BBXFX_CONFIG_11"
#define busnum_CAVM_BBXFX_CONFIG_11(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_11(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_110
 *
 * BBX6 Configuration Register 110
 * Job Configuration
 */
union cavm_bbxfx_config_110
{
    uint64_t u;
    struct cavm_bbxfx_config_110_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_110_s cn; */
};
typedef union cavm_bbxfx_config_110 cavm_bbxfx_config_110_t;

static inline uint64_t CAVM_BBXFX_CONFIG_110(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_110(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82370ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_110", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_110(a) cavm_bbxfx_config_110_t
#define bustype_CAVM_BBXFX_CONFIG_110(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_110(a) "BBXFX_CONFIG_110"
#define busnum_CAVM_BBXFX_CONFIG_110(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_110(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_111
 *
 * BBX6 Configuration Register 111
 * Job Configuration
 */
union cavm_bbxfx_config_111
{
    uint64_t u;
    struct cavm_bbxfx_config_111_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_111_s cn; */
};
typedef union cavm_bbxfx_config_111 cavm_bbxfx_config_111_t;

static inline uint64_t CAVM_BBXFX_CONFIG_111(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_111(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82378ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_111", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_111(a) cavm_bbxfx_config_111_t
#define bustype_CAVM_BBXFX_CONFIG_111(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_111(a) "BBXFX_CONFIG_111"
#define busnum_CAVM_BBXFX_CONFIG_111(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_111(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_112
 *
 * BBX6 Configuration Register 112
 * Job Configuration
 */
union cavm_bbxfx_config_112
{
    uint64_t u;
    struct cavm_bbxfx_config_112_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_112_s cn; */
};
typedef union cavm_bbxfx_config_112 cavm_bbxfx_config_112_t;

static inline uint64_t CAVM_BBXFX_CONFIG_112(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_112(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82380ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_112", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_112(a) cavm_bbxfx_config_112_t
#define bustype_CAVM_BBXFX_CONFIG_112(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_112(a) "BBXFX_CONFIG_112"
#define busnum_CAVM_BBXFX_CONFIG_112(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_112(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_113
 *
 * BBX6 Configuration Register 113
 * Job Configuration
 */
union cavm_bbxfx_config_113
{
    uint64_t u;
    struct cavm_bbxfx_config_113_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_113_s cn; */
};
typedef union cavm_bbxfx_config_113 cavm_bbxfx_config_113_t;

static inline uint64_t CAVM_BBXFX_CONFIG_113(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_113(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82388ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_113", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_113(a) cavm_bbxfx_config_113_t
#define bustype_CAVM_BBXFX_CONFIG_113(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_113(a) "BBXFX_CONFIG_113"
#define busnum_CAVM_BBXFX_CONFIG_113(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_113(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_114
 *
 * BBX6 Configuration Register 114
 * Job Configuration
 */
union cavm_bbxfx_config_114
{
    uint64_t u;
    struct cavm_bbxfx_config_114_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_114_s cn; */
};
typedef union cavm_bbxfx_config_114 cavm_bbxfx_config_114_t;

static inline uint64_t CAVM_BBXFX_CONFIG_114(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_114(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82390ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_114", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_114(a) cavm_bbxfx_config_114_t
#define bustype_CAVM_BBXFX_CONFIG_114(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_114(a) "BBXFX_CONFIG_114"
#define busnum_CAVM_BBXFX_CONFIG_114(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_114(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_115
 *
 * BBX6 Configuration Register 115
 * Job Configuration
 */
union cavm_bbxfx_config_115
{
    uint64_t u;
    struct cavm_bbxfx_config_115_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_115_s cn; */
};
typedef union cavm_bbxfx_config_115 cavm_bbxfx_config_115_t;

static inline uint64_t CAVM_BBXFX_CONFIG_115(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_115(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82398ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_115", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_115(a) cavm_bbxfx_config_115_t
#define bustype_CAVM_BBXFX_CONFIG_115(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_115(a) "BBXFX_CONFIG_115"
#define busnum_CAVM_BBXFX_CONFIG_115(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_115(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_116
 *
 * BBX6 Configuration Register 116
 * Job Configuration
 */
union cavm_bbxfx_config_116
{
    uint64_t u;
    struct cavm_bbxfx_config_116_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_116_s cn; */
};
typedef union cavm_bbxfx_config_116 cavm_bbxfx_config_116_t;

static inline uint64_t CAVM_BBXFX_CONFIG_116(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_116(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_116", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_116(a) cavm_bbxfx_config_116_t
#define bustype_CAVM_BBXFX_CONFIG_116(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_116(a) "BBXFX_CONFIG_116"
#define busnum_CAVM_BBXFX_CONFIG_116(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_116(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_117
 *
 * BBX6 Configuration Register 117
 * Job Configuration
 */
union cavm_bbxfx_config_117
{
    uint64_t u;
    struct cavm_bbxfx_config_117_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_117_s cn; */
};
typedef union cavm_bbxfx_config_117 cavm_bbxfx_config_117_t;

static inline uint64_t CAVM_BBXFX_CONFIG_117(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_117(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_117", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_117(a) cavm_bbxfx_config_117_t
#define bustype_CAVM_BBXFX_CONFIG_117(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_117(a) "BBXFX_CONFIG_117"
#define busnum_CAVM_BBXFX_CONFIG_117(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_117(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_118
 *
 * BBX6 Configuration Register 118
 * Job Configuration
 */
union cavm_bbxfx_config_118
{
    uint64_t u;
    struct cavm_bbxfx_config_118_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_118_s cn; */
};
typedef union cavm_bbxfx_config_118 cavm_bbxfx_config_118_t;

static inline uint64_t CAVM_BBXFX_CONFIG_118(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_118(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_118", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_118(a) cavm_bbxfx_config_118_t
#define bustype_CAVM_BBXFX_CONFIG_118(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_118(a) "BBXFX_CONFIG_118"
#define busnum_CAVM_BBXFX_CONFIG_118(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_118(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_119
 *
 * BBX6 Configuration Register 119
 * Job Configuration
 */
union cavm_bbxfx_config_119
{
    uint64_t u;
    struct cavm_bbxfx_config_119_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_119_s cn; */
};
typedef union cavm_bbxfx_config_119 cavm_bbxfx_config_119_t;

static inline uint64_t CAVM_BBXFX_CONFIG_119(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_119(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_119", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_119(a) cavm_bbxfx_config_119_t
#define bustype_CAVM_BBXFX_CONFIG_119(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_119(a) "BBXFX_CONFIG_119"
#define busnum_CAVM_BBXFX_CONFIG_119(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_119(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_12
 *
 * BBX6 Configuration Register 12
 * Job Configuration
 */
union cavm_bbxfx_config_12
{
    uint64_t u;
    struct cavm_bbxfx_config_12_s
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
    /* struct cavm_bbxfx_config_12_s cn; */
};
typedef union cavm_bbxfx_config_12 cavm_bbxfx_config_12_t;

static inline uint64_t CAVM_BBXFX_CONFIG_12(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_12(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82060ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_12", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_12(a) cavm_bbxfx_config_12_t
#define bustype_CAVM_BBXFX_CONFIG_12(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_12(a) "BBXFX_CONFIG_12"
#define busnum_CAVM_BBXFX_CONFIG_12(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_12(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_120
 *
 * BBX6 Configuration Register 120
 * Job Configuration
 */
union cavm_bbxfx_config_120
{
    uint64_t u;
    struct cavm_bbxfx_config_120_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_120_s cn; */
};
typedef union cavm_bbxfx_config_120 cavm_bbxfx_config_120_t;

static inline uint64_t CAVM_BBXFX_CONFIG_120(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_120(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_120", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_120(a) cavm_bbxfx_config_120_t
#define bustype_CAVM_BBXFX_CONFIG_120(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_120(a) "BBXFX_CONFIG_120"
#define busnum_CAVM_BBXFX_CONFIG_120(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_120(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_121
 *
 * BBX6 Configuration Register 121
 * Job Configuration
 */
union cavm_bbxfx_config_121
{
    uint64_t u;
    struct cavm_bbxfx_config_121_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_121_s cn; */
};
typedef union cavm_bbxfx_config_121 cavm_bbxfx_config_121_t;

static inline uint64_t CAVM_BBXFX_CONFIG_121(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_121(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_121", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_121(a) cavm_bbxfx_config_121_t
#define bustype_CAVM_BBXFX_CONFIG_121(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_121(a) "BBXFX_CONFIG_121"
#define busnum_CAVM_BBXFX_CONFIG_121(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_121(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_122
 *
 * BBX6 Configuration Register 122
 * Job Configuration
 */
union cavm_bbxfx_config_122
{
    uint64_t u;
    struct cavm_bbxfx_config_122_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_122_s cn; */
};
typedef union cavm_bbxfx_config_122 cavm_bbxfx_config_122_t;

static inline uint64_t CAVM_BBXFX_CONFIG_122(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_122(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_122", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_122(a) cavm_bbxfx_config_122_t
#define bustype_CAVM_BBXFX_CONFIG_122(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_122(a) "BBXFX_CONFIG_122"
#define busnum_CAVM_BBXFX_CONFIG_122(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_122(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_123
 *
 * BBX6 Configuration Register 123
 * Job Configuration
 */
union cavm_bbxfx_config_123
{
    uint64_t u;
    struct cavm_bbxfx_config_123_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_123_s cn; */
};
typedef union cavm_bbxfx_config_123 cavm_bbxfx_config_123_t;

static inline uint64_t CAVM_BBXFX_CONFIG_123(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_123(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_123", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_123(a) cavm_bbxfx_config_123_t
#define bustype_CAVM_BBXFX_CONFIG_123(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_123(a) "BBXFX_CONFIG_123"
#define busnum_CAVM_BBXFX_CONFIG_123(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_123(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_124
 *
 * BBX6 Configuration Register 124
 * Job Configuration
 */
union cavm_bbxfx_config_124
{
    uint64_t u;
    struct cavm_bbxfx_config_124_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_124_s cn; */
};
typedef union cavm_bbxfx_config_124 cavm_bbxfx_config_124_t;

static inline uint64_t CAVM_BBXFX_CONFIG_124(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_124(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_124", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_124(a) cavm_bbxfx_config_124_t
#define bustype_CAVM_BBXFX_CONFIG_124(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_124(a) "BBXFX_CONFIG_124"
#define busnum_CAVM_BBXFX_CONFIG_124(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_124(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_125
 *
 * BBX6 Configuration Register 125
 * Job Configuration
 */
union cavm_bbxfx_config_125
{
    uint64_t u;
    struct cavm_bbxfx_config_125_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_125_s cn; */
};
typedef union cavm_bbxfx_config_125 cavm_bbxfx_config_125_t;

static inline uint64_t CAVM_BBXFX_CONFIG_125(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_125(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_125", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_125(a) cavm_bbxfx_config_125_t
#define bustype_CAVM_BBXFX_CONFIG_125(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_125(a) "BBXFX_CONFIG_125"
#define busnum_CAVM_BBXFX_CONFIG_125(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_125(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_126
 *
 * BBX6 Configuration Register 126
 * Job Configuration
 */
union cavm_bbxfx_config_126
{
    uint64_t u;
    struct cavm_bbxfx_config_126_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_126_s cn; */
};
typedef union cavm_bbxfx_config_126 cavm_bbxfx_config_126_t;

static inline uint64_t CAVM_BBXFX_CONFIG_126(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_126(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_126", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_126(a) cavm_bbxfx_config_126_t
#define bustype_CAVM_BBXFX_CONFIG_126(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_126(a) "BBXFX_CONFIG_126"
#define busnum_CAVM_BBXFX_CONFIG_126(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_126(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_127
 *
 * BBX6 Configuration Register 127
 * Job Configuration
 */
union cavm_bbxfx_config_127
{
    uint64_t u;
    struct cavm_bbxfx_config_127_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_127_s cn; */
};
typedef union cavm_bbxfx_config_127 cavm_bbxfx_config_127_t;

static inline uint64_t CAVM_BBXFX_CONFIG_127(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_127(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c823f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_127", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_127(a) cavm_bbxfx_config_127_t
#define bustype_CAVM_BBXFX_CONFIG_127(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_127(a) "BBXFX_CONFIG_127"
#define busnum_CAVM_BBXFX_CONFIG_127(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_127(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_128
 *
 * BBX6 Configuration Register 128
 * Job Configuration
 */
union cavm_bbxfx_config_128
{
    uint64_t u;
    struct cavm_bbxfx_config_128_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_128_s cn; */
};
typedef union cavm_bbxfx_config_128 cavm_bbxfx_config_128_t;

static inline uint64_t CAVM_BBXFX_CONFIG_128(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_128(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82400ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_128", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_128(a) cavm_bbxfx_config_128_t
#define bustype_CAVM_BBXFX_CONFIG_128(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_128(a) "BBXFX_CONFIG_128"
#define busnum_CAVM_BBXFX_CONFIG_128(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_128(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_129
 *
 * BBX6 Configuration Register 129
 * Job Configuration
 */
union cavm_bbxfx_config_129
{
    uint64_t u;
    struct cavm_bbxfx_config_129_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_129_s cn; */
};
typedef union cavm_bbxfx_config_129 cavm_bbxfx_config_129_t;

static inline uint64_t CAVM_BBXFX_CONFIG_129(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_129(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82408ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_129", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_129(a) cavm_bbxfx_config_129_t
#define bustype_CAVM_BBXFX_CONFIG_129(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_129(a) "BBXFX_CONFIG_129"
#define busnum_CAVM_BBXFX_CONFIG_129(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_129(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_13
 *
 * BBX6 Configuration Register 13
 * Job Configuration
 */
union cavm_bbxfx_config_13
{
    uint64_t u;
    struct cavm_bbxfx_config_13_s
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
    /* struct cavm_bbxfx_config_13_s cn; */
};
typedef union cavm_bbxfx_config_13 cavm_bbxfx_config_13_t;

static inline uint64_t CAVM_BBXFX_CONFIG_13(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_13(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82068ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_13", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_13(a) cavm_bbxfx_config_13_t
#define bustype_CAVM_BBXFX_CONFIG_13(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_13(a) "BBXFX_CONFIG_13"
#define busnum_CAVM_BBXFX_CONFIG_13(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_13(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_130
 *
 * BBX6 Configuration Register 130
 * Job Configuration
 */
union cavm_bbxfx_config_130
{
    uint64_t u;
    struct cavm_bbxfx_config_130_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_130_s cn; */
};
typedef union cavm_bbxfx_config_130 cavm_bbxfx_config_130_t;

static inline uint64_t CAVM_BBXFX_CONFIG_130(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_130(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82410ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_130", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_130(a) cavm_bbxfx_config_130_t
#define bustype_CAVM_BBXFX_CONFIG_130(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_130(a) "BBXFX_CONFIG_130"
#define busnum_CAVM_BBXFX_CONFIG_130(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_130(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_131
 *
 * BBX6 Configuration Register 131
 * Job Configuration
 */
union cavm_bbxfx_config_131
{
    uint64_t u;
    struct cavm_bbxfx_config_131_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_131_s cn; */
};
typedef union cavm_bbxfx_config_131 cavm_bbxfx_config_131_t;

static inline uint64_t CAVM_BBXFX_CONFIG_131(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_131(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82418ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_131", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_131(a) cavm_bbxfx_config_131_t
#define bustype_CAVM_BBXFX_CONFIG_131(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_131(a) "BBXFX_CONFIG_131"
#define busnum_CAVM_BBXFX_CONFIG_131(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_131(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_132
 *
 * BBX6 Configuration Register 132
 * Job Configuration
 */
union cavm_bbxfx_config_132
{
    uint64_t u;
    struct cavm_bbxfx_config_132_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_132_s cn; */
};
typedef union cavm_bbxfx_config_132 cavm_bbxfx_config_132_t;

static inline uint64_t CAVM_BBXFX_CONFIG_132(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_132(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82420ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_132", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_132(a) cavm_bbxfx_config_132_t
#define bustype_CAVM_BBXFX_CONFIG_132(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_132(a) "BBXFX_CONFIG_132"
#define busnum_CAVM_BBXFX_CONFIG_132(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_132(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_133
 *
 * BBX6 Configuration Register 133
 * Job Configuration
 */
union cavm_bbxfx_config_133
{
    uint64_t u;
    struct cavm_bbxfx_config_133_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_133_s cn; */
};
typedef union cavm_bbxfx_config_133 cavm_bbxfx_config_133_t;

static inline uint64_t CAVM_BBXFX_CONFIG_133(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_133(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82428ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_133", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_133(a) cavm_bbxfx_config_133_t
#define bustype_CAVM_BBXFX_CONFIG_133(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_133(a) "BBXFX_CONFIG_133"
#define busnum_CAVM_BBXFX_CONFIG_133(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_133(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_134
 *
 * BBX6 Configuration Register 134
 * Job Configuration
 */
union cavm_bbxfx_config_134
{
    uint64_t u;
    struct cavm_bbxfx_config_134_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_134_s cn; */
};
typedef union cavm_bbxfx_config_134 cavm_bbxfx_config_134_t;

static inline uint64_t CAVM_BBXFX_CONFIG_134(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_134(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82430ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_134", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_134(a) cavm_bbxfx_config_134_t
#define bustype_CAVM_BBXFX_CONFIG_134(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_134(a) "BBXFX_CONFIG_134"
#define busnum_CAVM_BBXFX_CONFIG_134(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_134(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_135
 *
 * BBX6 Configuration Register 135
 * Job Configuration
 */
union cavm_bbxfx_config_135
{
    uint64_t u;
    struct cavm_bbxfx_config_135_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_135_s cn; */
};
typedef union cavm_bbxfx_config_135 cavm_bbxfx_config_135_t;

static inline uint64_t CAVM_BBXFX_CONFIG_135(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_135(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82438ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_135", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_135(a) cavm_bbxfx_config_135_t
#define bustype_CAVM_BBXFX_CONFIG_135(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_135(a) "BBXFX_CONFIG_135"
#define busnum_CAVM_BBXFX_CONFIG_135(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_135(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_136
 *
 * BBX6 Configuration Register 136
 * Job Configuration
 */
union cavm_bbxfx_config_136
{
    uint64_t u;
    struct cavm_bbxfx_config_136_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_136_s cn; */
};
typedef union cavm_bbxfx_config_136 cavm_bbxfx_config_136_t;

static inline uint64_t CAVM_BBXFX_CONFIG_136(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_136(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82440ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_136", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_136(a) cavm_bbxfx_config_136_t
#define bustype_CAVM_BBXFX_CONFIG_136(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_136(a) "BBXFX_CONFIG_136"
#define busnum_CAVM_BBXFX_CONFIG_136(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_136(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_137
 *
 * BBX6 Configuration Register 137
 * Job Configuration
 */
union cavm_bbxfx_config_137
{
    uint64_t u;
    struct cavm_bbxfx_config_137_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_137_s cn; */
};
typedef union cavm_bbxfx_config_137 cavm_bbxfx_config_137_t;

static inline uint64_t CAVM_BBXFX_CONFIG_137(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_137(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82448ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_137", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_137(a) cavm_bbxfx_config_137_t
#define bustype_CAVM_BBXFX_CONFIG_137(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_137(a) "BBXFX_CONFIG_137"
#define busnum_CAVM_BBXFX_CONFIG_137(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_137(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_138
 *
 * BBX6 Configuration Register 138
 * Job Configuration
 */
union cavm_bbxfx_config_138
{
    uint64_t u;
    struct cavm_bbxfx_config_138_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_138_s cn; */
};
typedef union cavm_bbxfx_config_138 cavm_bbxfx_config_138_t;

static inline uint64_t CAVM_BBXFX_CONFIG_138(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_138(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82450ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_138", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_138(a) cavm_bbxfx_config_138_t
#define bustype_CAVM_BBXFX_CONFIG_138(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_138(a) "BBXFX_CONFIG_138"
#define busnum_CAVM_BBXFX_CONFIG_138(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_138(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_139
 *
 * BBX6 Configuration Register 139
 * Job Configuration
 */
union cavm_bbxfx_config_139
{
    uint64_t u;
    struct cavm_bbxfx_config_139_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_139_s cn; */
};
typedef union cavm_bbxfx_config_139 cavm_bbxfx_config_139_t;

static inline uint64_t CAVM_BBXFX_CONFIG_139(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_139(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82458ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_139", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_139(a) cavm_bbxfx_config_139_t
#define bustype_CAVM_BBXFX_CONFIG_139(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_139(a) "BBXFX_CONFIG_139"
#define busnum_CAVM_BBXFX_CONFIG_139(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_139(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_14
 *
 * BBX6 Configuration Register 14
 * Job Configuration
 */
union cavm_bbxfx_config_14
{
    uint64_t u;
    struct cavm_bbxfx_config_14_s
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
    /* struct cavm_bbxfx_config_14_s cn; */
};
typedef union cavm_bbxfx_config_14 cavm_bbxfx_config_14_t;

static inline uint64_t CAVM_BBXFX_CONFIG_14(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_14(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82070ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_14", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_14(a) cavm_bbxfx_config_14_t
#define bustype_CAVM_BBXFX_CONFIG_14(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_14(a) "BBXFX_CONFIG_14"
#define busnum_CAVM_BBXFX_CONFIG_14(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_14(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_140
 *
 * BBX6 Configuration Register 140
 * Job Configuration
 */
union cavm_bbxfx_config_140
{
    uint64_t u;
    struct cavm_bbxfx_config_140_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_140_s cn; */
};
typedef union cavm_bbxfx_config_140 cavm_bbxfx_config_140_t;

static inline uint64_t CAVM_BBXFX_CONFIG_140(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_140(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82460ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_140", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_140(a) cavm_bbxfx_config_140_t
#define bustype_CAVM_BBXFX_CONFIG_140(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_140(a) "BBXFX_CONFIG_140"
#define busnum_CAVM_BBXFX_CONFIG_140(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_140(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_141
 *
 * BBX6 Configuration Register 141
 * Job Configuration
 */
union cavm_bbxfx_config_141
{
    uint64_t u;
    struct cavm_bbxfx_config_141_s
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
    /* struct cavm_bbxfx_config_141_s cn; */
};
typedef union cavm_bbxfx_config_141 cavm_bbxfx_config_141_t;

static inline uint64_t CAVM_BBXFX_CONFIG_141(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_141(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82468ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_141", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_141(a) cavm_bbxfx_config_141_t
#define bustype_CAVM_BBXFX_CONFIG_141(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_141(a) "BBXFX_CONFIG_141"
#define busnum_CAVM_BBXFX_CONFIG_141(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_141(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_142
 *
 * BBX6 Configuration Register 142
 * Job Configuration
 */
union cavm_bbxfx_config_142
{
    uint64_t u;
    struct cavm_bbxfx_config_142_s
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
    /* struct cavm_bbxfx_config_142_s cn; */
};
typedef union cavm_bbxfx_config_142 cavm_bbxfx_config_142_t;

static inline uint64_t CAVM_BBXFX_CONFIG_142(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_142(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82470ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_142", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_142(a) cavm_bbxfx_config_142_t
#define bustype_CAVM_BBXFX_CONFIG_142(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_142(a) "BBXFX_CONFIG_142"
#define busnum_CAVM_BBXFX_CONFIG_142(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_142(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_143
 *
 * BBX6 Configuration Register 143
 * Job Configuration
 */
union cavm_bbxfx_config_143
{
    uint64_t u;
    struct cavm_bbxfx_config_143_s
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
    /* struct cavm_bbxfx_config_143_s cn; */
};
typedef union cavm_bbxfx_config_143 cavm_bbxfx_config_143_t;

static inline uint64_t CAVM_BBXFX_CONFIG_143(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_143(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82478ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_143", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_143(a) cavm_bbxfx_config_143_t
#define bustype_CAVM_BBXFX_CONFIG_143(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_143(a) "BBXFX_CONFIG_143"
#define busnum_CAVM_BBXFX_CONFIG_143(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_143(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_144
 *
 * BBX6 Configuration Register 144
 * Job Configuration
 */
union cavm_bbxfx_config_144
{
    uint64_t u;
    struct cavm_bbxfx_config_144_s
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
    /* struct cavm_bbxfx_config_144_s cn; */
};
typedef union cavm_bbxfx_config_144 cavm_bbxfx_config_144_t;

static inline uint64_t CAVM_BBXFX_CONFIG_144(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_144(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82480ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_144", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_144(a) cavm_bbxfx_config_144_t
#define bustype_CAVM_BBXFX_CONFIG_144(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_144(a) "BBXFX_CONFIG_144"
#define busnum_CAVM_BBXFX_CONFIG_144(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_144(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_145
 *
 * BBX6 Configuration Register 145
 * Job Configuration
 */
union cavm_bbxfx_config_145
{
    uint64_t u;
    struct cavm_bbxfx_config_145_s
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
    /* struct cavm_bbxfx_config_145_s cn; */
};
typedef union cavm_bbxfx_config_145 cavm_bbxfx_config_145_t;

static inline uint64_t CAVM_BBXFX_CONFIG_145(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_145(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82488ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_145", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_145(a) cavm_bbxfx_config_145_t
#define bustype_CAVM_BBXFX_CONFIG_145(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_145(a) "BBXFX_CONFIG_145"
#define busnum_CAVM_BBXFX_CONFIG_145(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_145(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_146
 *
 * BBX6 Configuration Register 146
 * Job Configuration
 */
union cavm_bbxfx_config_146
{
    uint64_t u;
    struct cavm_bbxfx_config_146_s
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
    /* struct cavm_bbxfx_config_146_s cn; */
};
typedef union cavm_bbxfx_config_146 cavm_bbxfx_config_146_t;

static inline uint64_t CAVM_BBXFX_CONFIG_146(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_146(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82490ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_146", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_146(a) cavm_bbxfx_config_146_t
#define bustype_CAVM_BBXFX_CONFIG_146(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_146(a) "BBXFX_CONFIG_146"
#define busnum_CAVM_BBXFX_CONFIG_146(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_146(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_147
 *
 * BBX6 Configuration Register 147
 * Job Configuration
 */
union cavm_bbxfx_config_147
{
    uint64_t u;
    struct cavm_bbxfx_config_147_s
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
    /* struct cavm_bbxfx_config_147_s cn; */
};
typedef union cavm_bbxfx_config_147 cavm_bbxfx_config_147_t;

static inline uint64_t CAVM_BBXFX_CONFIG_147(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_147(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82498ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_147", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_147(a) cavm_bbxfx_config_147_t
#define bustype_CAVM_BBXFX_CONFIG_147(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_147(a) "BBXFX_CONFIG_147"
#define busnum_CAVM_BBXFX_CONFIG_147(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_147(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_148
 *
 * BBX6 Configuration Register 148
 * Job Configuration
 */
union cavm_bbxfx_config_148
{
    uint64_t u;
    struct cavm_bbxfx_config_148_s
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
    /* struct cavm_bbxfx_config_148_s cn; */
};
typedef union cavm_bbxfx_config_148 cavm_bbxfx_config_148_t;

static inline uint64_t CAVM_BBXFX_CONFIG_148(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_148(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_148", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_148(a) cavm_bbxfx_config_148_t
#define bustype_CAVM_BBXFX_CONFIG_148(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_148(a) "BBXFX_CONFIG_148"
#define busnum_CAVM_BBXFX_CONFIG_148(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_148(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_149
 *
 * BBX6 Configuration Register 149
 * Job Configuration
 */
union cavm_bbxfx_config_149
{
    uint64_t u;
    struct cavm_bbxfx_config_149_s
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
    /* struct cavm_bbxfx_config_149_s cn; */
};
typedef union cavm_bbxfx_config_149 cavm_bbxfx_config_149_t;

static inline uint64_t CAVM_BBXFX_CONFIG_149(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_149(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_149", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_149(a) cavm_bbxfx_config_149_t
#define bustype_CAVM_BBXFX_CONFIG_149(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_149(a) "BBXFX_CONFIG_149"
#define busnum_CAVM_BBXFX_CONFIG_149(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_149(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_15
 *
 * BBX6 Configuration Register 15
 * Job Configuration
 */
union cavm_bbxfx_config_15
{
    uint64_t u;
    struct cavm_bbxfx_config_15_s
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
    /* struct cavm_bbxfx_config_15_s cn; */
};
typedef union cavm_bbxfx_config_15 cavm_bbxfx_config_15_t;

static inline uint64_t CAVM_BBXFX_CONFIG_15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_15(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82078ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_15", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_15(a) cavm_bbxfx_config_15_t
#define bustype_CAVM_BBXFX_CONFIG_15(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_15(a) "BBXFX_CONFIG_15"
#define busnum_CAVM_BBXFX_CONFIG_15(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_15(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_150
 *
 * BBX6 Configuration Register 150
 * Job Configuration
 */
union cavm_bbxfx_config_150
{
    uint64_t u;
    struct cavm_bbxfx_config_150_s
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
    /* struct cavm_bbxfx_config_150_s cn; */
};
typedef union cavm_bbxfx_config_150 cavm_bbxfx_config_150_t;

static inline uint64_t CAVM_BBXFX_CONFIG_150(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_150(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_150", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_150(a) cavm_bbxfx_config_150_t
#define bustype_CAVM_BBXFX_CONFIG_150(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_150(a) "BBXFX_CONFIG_150"
#define busnum_CAVM_BBXFX_CONFIG_150(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_150(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_151
 *
 * BBX6 Configuration Register 151
 * Job Configuration
 */
union cavm_bbxfx_config_151
{
    uint64_t u;
    struct cavm_bbxfx_config_151_s
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
    /* struct cavm_bbxfx_config_151_s cn; */
};
typedef union cavm_bbxfx_config_151 cavm_bbxfx_config_151_t;

static inline uint64_t CAVM_BBXFX_CONFIG_151(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_151(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_151", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_151(a) cavm_bbxfx_config_151_t
#define bustype_CAVM_BBXFX_CONFIG_151(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_151(a) "BBXFX_CONFIG_151"
#define busnum_CAVM_BBXFX_CONFIG_151(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_151(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_152
 *
 * BBX6 Configuration Register 152
 * Job Configuration
 */
union cavm_bbxfx_config_152
{
    uint64_t u;
    struct cavm_bbxfx_config_152_s
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
    /* struct cavm_bbxfx_config_152_s cn; */
};
typedef union cavm_bbxfx_config_152 cavm_bbxfx_config_152_t;

static inline uint64_t CAVM_BBXFX_CONFIG_152(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_152(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_152", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_152(a) cavm_bbxfx_config_152_t
#define bustype_CAVM_BBXFX_CONFIG_152(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_152(a) "BBXFX_CONFIG_152"
#define busnum_CAVM_BBXFX_CONFIG_152(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_152(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_153
 *
 * BBX6 Configuration Register 153
 * Job Configuration
 */
union cavm_bbxfx_config_153
{
    uint64_t u;
    struct cavm_bbxfx_config_153_s
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
    /* struct cavm_bbxfx_config_153_s cn; */
};
typedef union cavm_bbxfx_config_153 cavm_bbxfx_config_153_t;

static inline uint64_t CAVM_BBXFX_CONFIG_153(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_153(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_153", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_153(a) cavm_bbxfx_config_153_t
#define bustype_CAVM_BBXFX_CONFIG_153(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_153(a) "BBXFX_CONFIG_153"
#define busnum_CAVM_BBXFX_CONFIG_153(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_153(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_154
 *
 * BBX6 Configuration Register 154
 * Job Configuration
 */
union cavm_bbxfx_config_154
{
    uint64_t u;
    struct cavm_bbxfx_config_154_s
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
    /* struct cavm_bbxfx_config_154_s cn; */
};
typedef union cavm_bbxfx_config_154 cavm_bbxfx_config_154_t;

static inline uint64_t CAVM_BBXFX_CONFIG_154(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_154(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_154", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_154(a) cavm_bbxfx_config_154_t
#define bustype_CAVM_BBXFX_CONFIG_154(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_154(a) "BBXFX_CONFIG_154"
#define busnum_CAVM_BBXFX_CONFIG_154(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_154(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_155
 *
 * BBX6 Configuration Register 155
 * Job Configuration
 */
union cavm_bbxfx_config_155
{
    uint64_t u;
    struct cavm_bbxfx_config_155_s
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
    /* struct cavm_bbxfx_config_155_s cn; */
};
typedef union cavm_bbxfx_config_155 cavm_bbxfx_config_155_t;

static inline uint64_t CAVM_BBXFX_CONFIG_155(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_155(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_155", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_155(a) cavm_bbxfx_config_155_t
#define bustype_CAVM_BBXFX_CONFIG_155(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_155(a) "BBXFX_CONFIG_155"
#define busnum_CAVM_BBXFX_CONFIG_155(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_155(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_156
 *
 * BBX6 Configuration Register 156
 * Job Configuration
 */
union cavm_bbxfx_config_156
{
    uint64_t u;
    struct cavm_bbxfx_config_156_s
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
    /* struct cavm_bbxfx_config_156_s cn; */
};
typedef union cavm_bbxfx_config_156 cavm_bbxfx_config_156_t;

static inline uint64_t CAVM_BBXFX_CONFIG_156(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_156(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_156", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_156(a) cavm_bbxfx_config_156_t
#define bustype_CAVM_BBXFX_CONFIG_156(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_156(a) "BBXFX_CONFIG_156"
#define busnum_CAVM_BBXFX_CONFIG_156(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_156(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_157
 *
 * BBX6 Configuration Register 157
 * Job Configuration
 */
union cavm_bbxfx_config_157
{
    uint64_t u;
    struct cavm_bbxfx_config_157_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_157_s cn; */
};
typedef union cavm_bbxfx_config_157 cavm_bbxfx_config_157_t;

static inline uint64_t CAVM_BBXFX_CONFIG_157(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_157(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_157", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_157(a) cavm_bbxfx_config_157_t
#define bustype_CAVM_BBXFX_CONFIG_157(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_157(a) "BBXFX_CONFIG_157"
#define busnum_CAVM_BBXFX_CONFIG_157(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_157(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_158
 *
 * BBX6 Configuration Register 158
 * Job Configuration
 */
union cavm_bbxfx_config_158
{
    uint64_t u;
    struct cavm_bbxfx_config_158_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_158_s cn; */
};
typedef union cavm_bbxfx_config_158 cavm_bbxfx_config_158_t;

static inline uint64_t CAVM_BBXFX_CONFIG_158(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_158(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_158", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_158(a) cavm_bbxfx_config_158_t
#define bustype_CAVM_BBXFX_CONFIG_158(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_158(a) "BBXFX_CONFIG_158"
#define busnum_CAVM_BBXFX_CONFIG_158(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_158(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_159
 *
 * BBX6 Configuration Register 159
 * Job Configuration
 */
union cavm_bbxfx_config_159
{
    uint64_t u;
    struct cavm_bbxfx_config_159_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_159_s cn; */
};
typedef union cavm_bbxfx_config_159 cavm_bbxfx_config_159_t;

static inline uint64_t CAVM_BBXFX_CONFIG_159(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_159(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c824f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_159", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_159(a) cavm_bbxfx_config_159_t
#define bustype_CAVM_BBXFX_CONFIG_159(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_159(a) "BBXFX_CONFIG_159"
#define busnum_CAVM_BBXFX_CONFIG_159(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_159(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_16
 *
 * BBX6 Configuration Register 16
 * Job Configuration
 */
union cavm_bbxfx_config_16
{
    uint64_t u;
    struct cavm_bbxfx_config_16_s
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
    /* struct cavm_bbxfx_config_16_s cn; */
};
typedef union cavm_bbxfx_config_16 cavm_bbxfx_config_16_t;

static inline uint64_t CAVM_BBXFX_CONFIG_16(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_16(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82080ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_16", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_16(a) cavm_bbxfx_config_16_t
#define bustype_CAVM_BBXFX_CONFIG_16(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_16(a) "BBXFX_CONFIG_16"
#define busnum_CAVM_BBXFX_CONFIG_16(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_16(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_160
 *
 * BBX6 Configuration Register 160
 * Job Configuration
 */
union cavm_bbxfx_config_160
{
    uint64_t u;
    struct cavm_bbxfx_config_160_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_160_s cn; */
};
typedef union cavm_bbxfx_config_160 cavm_bbxfx_config_160_t;

static inline uint64_t CAVM_BBXFX_CONFIG_160(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_160(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82500ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_160", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_160(a) cavm_bbxfx_config_160_t
#define bustype_CAVM_BBXFX_CONFIG_160(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_160(a) "BBXFX_CONFIG_160"
#define busnum_CAVM_BBXFX_CONFIG_160(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_160(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_161
 *
 * BBX6 Configuration Register 161
 * Job Configuration
 */
union cavm_bbxfx_config_161
{
    uint64_t u;
    struct cavm_bbxfx_config_161_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_161_s cn; */
};
typedef union cavm_bbxfx_config_161 cavm_bbxfx_config_161_t;

static inline uint64_t CAVM_BBXFX_CONFIG_161(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_161(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82508ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_161", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_161(a) cavm_bbxfx_config_161_t
#define bustype_CAVM_BBXFX_CONFIG_161(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_161(a) "BBXFX_CONFIG_161"
#define busnum_CAVM_BBXFX_CONFIG_161(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_161(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_162
 *
 * BBX6 Configuration Register 162
 * Job Configuration
 */
union cavm_bbxfx_config_162
{
    uint64_t u;
    struct cavm_bbxfx_config_162_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_162_s cn; */
};
typedef union cavm_bbxfx_config_162 cavm_bbxfx_config_162_t;

static inline uint64_t CAVM_BBXFX_CONFIG_162(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_162(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82510ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_162", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_162(a) cavm_bbxfx_config_162_t
#define bustype_CAVM_BBXFX_CONFIG_162(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_162(a) "BBXFX_CONFIG_162"
#define busnum_CAVM_BBXFX_CONFIG_162(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_162(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_163
 *
 * BBX6 Configuration Register 163
 * Job Configuration
 */
union cavm_bbxfx_config_163
{
    uint64_t u;
    struct cavm_bbxfx_config_163_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_163_s cn; */
};
typedef union cavm_bbxfx_config_163 cavm_bbxfx_config_163_t;

static inline uint64_t CAVM_BBXFX_CONFIG_163(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_163(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82518ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_163", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_163(a) cavm_bbxfx_config_163_t
#define bustype_CAVM_BBXFX_CONFIG_163(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_163(a) "BBXFX_CONFIG_163"
#define busnum_CAVM_BBXFX_CONFIG_163(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_163(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_164
 *
 * BBX6 Configuration Register 164
 * Job Configuration
 */
union cavm_bbxfx_config_164
{
    uint64_t u;
    struct cavm_bbxfx_config_164_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_164_s cn; */
};
typedef union cavm_bbxfx_config_164 cavm_bbxfx_config_164_t;

static inline uint64_t CAVM_BBXFX_CONFIG_164(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_164(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82520ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_164", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_164(a) cavm_bbxfx_config_164_t
#define bustype_CAVM_BBXFX_CONFIG_164(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_164(a) "BBXFX_CONFIG_164"
#define busnum_CAVM_BBXFX_CONFIG_164(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_164(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_165
 *
 * BBX6 Configuration Register 165
 * Job Configuration
 */
union cavm_bbxfx_config_165
{
    uint64_t u;
    struct cavm_bbxfx_config_165_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_165_s cn; */
};
typedef union cavm_bbxfx_config_165 cavm_bbxfx_config_165_t;

static inline uint64_t CAVM_BBXFX_CONFIG_165(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_165(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82528ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_165", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_165(a) cavm_bbxfx_config_165_t
#define bustype_CAVM_BBXFX_CONFIG_165(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_165(a) "BBXFX_CONFIG_165"
#define busnum_CAVM_BBXFX_CONFIG_165(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_165(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_166
 *
 * BBX6 Configuration Register 166
 * Job Configuration
 */
union cavm_bbxfx_config_166
{
    uint64_t u;
    struct cavm_bbxfx_config_166_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_166_s cn; */
};
typedef union cavm_bbxfx_config_166 cavm_bbxfx_config_166_t;

static inline uint64_t CAVM_BBXFX_CONFIG_166(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_166(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82530ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_166", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_166(a) cavm_bbxfx_config_166_t
#define bustype_CAVM_BBXFX_CONFIG_166(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_166(a) "BBXFX_CONFIG_166"
#define busnum_CAVM_BBXFX_CONFIG_166(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_166(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_167
 *
 * BBX6 Configuration Register 167
 * Job Configuration
 */
union cavm_bbxfx_config_167
{
    uint64_t u;
    struct cavm_bbxfx_config_167_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_167_s cn; */
};
typedef union cavm_bbxfx_config_167 cavm_bbxfx_config_167_t;

static inline uint64_t CAVM_BBXFX_CONFIG_167(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_167(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82538ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_167", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_167(a) cavm_bbxfx_config_167_t
#define bustype_CAVM_BBXFX_CONFIG_167(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_167(a) "BBXFX_CONFIG_167"
#define busnum_CAVM_BBXFX_CONFIG_167(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_167(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_168
 *
 * BBX6 Configuration Register 168
 * Job Configuration
 */
union cavm_bbxfx_config_168
{
    uint64_t u;
    struct cavm_bbxfx_config_168_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_168_s cn; */
};
typedef union cavm_bbxfx_config_168 cavm_bbxfx_config_168_t;

static inline uint64_t CAVM_BBXFX_CONFIG_168(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_168(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82540ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_168", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_168(a) cavm_bbxfx_config_168_t
#define bustype_CAVM_BBXFX_CONFIG_168(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_168(a) "BBXFX_CONFIG_168"
#define busnum_CAVM_BBXFX_CONFIG_168(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_168(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_169
 *
 * BBX6 Configuration Register 169
 * Job Configuration
 */
union cavm_bbxfx_config_169
{
    uint64_t u;
    struct cavm_bbxfx_config_169_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_169_s cn; */
};
typedef union cavm_bbxfx_config_169 cavm_bbxfx_config_169_t;

static inline uint64_t CAVM_BBXFX_CONFIG_169(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_169(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82548ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_169", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_169(a) cavm_bbxfx_config_169_t
#define bustype_CAVM_BBXFX_CONFIG_169(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_169(a) "BBXFX_CONFIG_169"
#define busnum_CAVM_BBXFX_CONFIG_169(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_169(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_17
 *
 * BBX6 Configuration Register 17
 * Job Configuration
 */
union cavm_bbxfx_config_17
{
    uint64_t u;
    struct cavm_bbxfx_config_17_s
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
    /* struct cavm_bbxfx_config_17_s cn; */
};
typedef union cavm_bbxfx_config_17 cavm_bbxfx_config_17_t;

static inline uint64_t CAVM_BBXFX_CONFIG_17(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_17(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82088ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_17", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_17(a) cavm_bbxfx_config_17_t
#define bustype_CAVM_BBXFX_CONFIG_17(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_17(a) "BBXFX_CONFIG_17"
#define busnum_CAVM_BBXFX_CONFIG_17(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_17(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_170
 *
 * BBX6 Configuration Register 170
 * Job Configuration
 */
union cavm_bbxfx_config_170
{
    uint64_t u;
    struct cavm_bbxfx_config_170_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_170_s cn; */
};
typedef union cavm_bbxfx_config_170 cavm_bbxfx_config_170_t;

static inline uint64_t CAVM_BBXFX_CONFIG_170(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_170(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82550ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_170", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_170(a) cavm_bbxfx_config_170_t
#define bustype_CAVM_BBXFX_CONFIG_170(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_170(a) "BBXFX_CONFIG_170"
#define busnum_CAVM_BBXFX_CONFIG_170(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_170(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_171
 *
 * BBX6 Configuration Register 171
 * Job Configuration
 */
union cavm_bbxfx_config_171
{
    uint64_t u;
    struct cavm_bbxfx_config_171_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_171_s cn; */
};
typedef union cavm_bbxfx_config_171 cavm_bbxfx_config_171_t;

static inline uint64_t CAVM_BBXFX_CONFIG_171(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_171(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82558ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_171", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_171(a) cavm_bbxfx_config_171_t
#define bustype_CAVM_BBXFX_CONFIG_171(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_171(a) "BBXFX_CONFIG_171"
#define busnum_CAVM_BBXFX_CONFIG_171(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_171(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_172
 *
 * BBX6 Configuration Register 172
 * Job Configuration
 */
union cavm_bbxfx_config_172
{
    uint64_t u;
    struct cavm_bbxfx_config_172_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_172_s cn; */
};
typedef union cavm_bbxfx_config_172 cavm_bbxfx_config_172_t;

static inline uint64_t CAVM_BBXFX_CONFIG_172(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_172(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82560ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_172", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_172(a) cavm_bbxfx_config_172_t
#define bustype_CAVM_BBXFX_CONFIG_172(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_172(a) "BBXFX_CONFIG_172"
#define busnum_CAVM_BBXFX_CONFIG_172(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_172(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_173
 *
 * BBX6 Configuration Register 173
 * Job Configuration
 */
union cavm_bbxfx_config_173
{
    uint64_t u;
    struct cavm_bbxfx_config_173_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_173_s cn; */
};
typedef union cavm_bbxfx_config_173 cavm_bbxfx_config_173_t;

static inline uint64_t CAVM_BBXFX_CONFIG_173(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_173(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82568ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_173", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_173(a) cavm_bbxfx_config_173_t
#define bustype_CAVM_BBXFX_CONFIG_173(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_173(a) "BBXFX_CONFIG_173"
#define busnum_CAVM_BBXFX_CONFIG_173(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_173(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_174
 *
 * BBX6 Configuration Register 174
 * Job Configuration
 */
union cavm_bbxfx_config_174
{
    uint64_t u;
    struct cavm_bbxfx_config_174_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_174_s cn; */
};
typedef union cavm_bbxfx_config_174 cavm_bbxfx_config_174_t;

static inline uint64_t CAVM_BBXFX_CONFIG_174(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_174(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82570ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_174", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_174(a) cavm_bbxfx_config_174_t
#define bustype_CAVM_BBXFX_CONFIG_174(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_174(a) "BBXFX_CONFIG_174"
#define busnum_CAVM_BBXFX_CONFIG_174(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_174(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_175
 *
 * BBX6 Configuration Register 175
 * Job Configuration
 */
union cavm_bbxfx_config_175
{
    uint64_t u;
    struct cavm_bbxfx_config_175_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_175_s cn; */
};
typedef union cavm_bbxfx_config_175 cavm_bbxfx_config_175_t;

static inline uint64_t CAVM_BBXFX_CONFIG_175(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_175(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82578ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_175", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_175(a) cavm_bbxfx_config_175_t
#define bustype_CAVM_BBXFX_CONFIG_175(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_175(a) "BBXFX_CONFIG_175"
#define busnum_CAVM_BBXFX_CONFIG_175(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_175(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_176
 *
 * BBX6 Configuration Register 176
 * Job Configuration
 */
union cavm_bbxfx_config_176
{
    uint64_t u;
    struct cavm_bbxfx_config_176_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_176_s cn; */
};
typedef union cavm_bbxfx_config_176 cavm_bbxfx_config_176_t;

static inline uint64_t CAVM_BBXFX_CONFIG_176(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_176(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82580ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_176", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_176(a) cavm_bbxfx_config_176_t
#define bustype_CAVM_BBXFX_CONFIG_176(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_176(a) "BBXFX_CONFIG_176"
#define busnum_CAVM_BBXFX_CONFIG_176(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_176(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_177
 *
 * BBX6 Configuration Register 177
 * Job Configuration
 */
union cavm_bbxfx_config_177
{
    uint64_t u;
    struct cavm_bbxfx_config_177_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_177_s cn; */
};
typedef union cavm_bbxfx_config_177 cavm_bbxfx_config_177_t;

static inline uint64_t CAVM_BBXFX_CONFIG_177(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_177(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82588ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_177", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_177(a) cavm_bbxfx_config_177_t
#define bustype_CAVM_BBXFX_CONFIG_177(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_177(a) "BBXFX_CONFIG_177"
#define busnum_CAVM_BBXFX_CONFIG_177(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_177(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_178
 *
 * BBX6 Configuration Register 178
 * Job Configuration
 */
union cavm_bbxfx_config_178
{
    uint64_t u;
    struct cavm_bbxfx_config_178_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_178_s cn; */
};
typedef union cavm_bbxfx_config_178 cavm_bbxfx_config_178_t;

static inline uint64_t CAVM_BBXFX_CONFIG_178(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_178(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82590ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_178", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_178(a) cavm_bbxfx_config_178_t
#define bustype_CAVM_BBXFX_CONFIG_178(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_178(a) "BBXFX_CONFIG_178"
#define busnum_CAVM_BBXFX_CONFIG_178(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_178(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_179
 *
 * BBX6 Configuration Register 179
 * Job Configuration
 */
union cavm_bbxfx_config_179
{
    uint64_t u;
    struct cavm_bbxfx_config_179_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_179_s cn; */
};
typedef union cavm_bbxfx_config_179 cavm_bbxfx_config_179_t;

static inline uint64_t CAVM_BBXFX_CONFIG_179(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_179(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82598ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_179", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_179(a) cavm_bbxfx_config_179_t
#define bustype_CAVM_BBXFX_CONFIG_179(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_179(a) "BBXFX_CONFIG_179"
#define busnum_CAVM_BBXFX_CONFIG_179(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_179(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_18
 *
 * BBX6 Configuration Register 18
 * Job Configuration
 */
union cavm_bbxfx_config_18
{
    uint64_t u;
    struct cavm_bbxfx_config_18_s
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
    /* struct cavm_bbxfx_config_18_s cn; */
};
typedef union cavm_bbxfx_config_18 cavm_bbxfx_config_18_t;

static inline uint64_t CAVM_BBXFX_CONFIG_18(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_18(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82090ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_18", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_18(a) cavm_bbxfx_config_18_t
#define bustype_CAVM_BBXFX_CONFIG_18(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_18(a) "BBXFX_CONFIG_18"
#define busnum_CAVM_BBXFX_CONFIG_18(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_18(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_180
 *
 * BBX6 Configuration Register 180
 * Job Configuration
 */
union cavm_bbxfx_config_180
{
    uint64_t u;
    struct cavm_bbxfx_config_180_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_180_s cn; */
};
typedef union cavm_bbxfx_config_180 cavm_bbxfx_config_180_t;

static inline uint64_t CAVM_BBXFX_CONFIG_180(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_180(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_180", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_180(a) cavm_bbxfx_config_180_t
#define bustype_CAVM_BBXFX_CONFIG_180(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_180(a) "BBXFX_CONFIG_180"
#define busnum_CAVM_BBXFX_CONFIG_180(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_180(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_181
 *
 * BBX6 Configuration Register 181
 * Job Configuration
 */
union cavm_bbxfx_config_181
{
    uint64_t u;
    struct cavm_bbxfx_config_181_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_181_s cn; */
};
typedef union cavm_bbxfx_config_181 cavm_bbxfx_config_181_t;

static inline uint64_t CAVM_BBXFX_CONFIG_181(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_181(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_181", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_181(a) cavm_bbxfx_config_181_t
#define bustype_CAVM_BBXFX_CONFIG_181(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_181(a) "BBXFX_CONFIG_181"
#define busnum_CAVM_BBXFX_CONFIG_181(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_181(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_182
 *
 * BBX6 Configuration Register 182
 * Job Configuration
 */
union cavm_bbxfx_config_182
{
    uint64_t u;
    struct cavm_bbxfx_config_182_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_182_s cn; */
};
typedef union cavm_bbxfx_config_182 cavm_bbxfx_config_182_t;

static inline uint64_t CAVM_BBXFX_CONFIG_182(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_182(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_182", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_182(a) cavm_bbxfx_config_182_t
#define bustype_CAVM_BBXFX_CONFIG_182(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_182(a) "BBXFX_CONFIG_182"
#define busnum_CAVM_BBXFX_CONFIG_182(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_182(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_183
 *
 * BBX6 Configuration Register 183
 * Job Configuration
 */
union cavm_bbxfx_config_183
{
    uint64_t u;
    struct cavm_bbxfx_config_183_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_183_s cn; */
};
typedef union cavm_bbxfx_config_183 cavm_bbxfx_config_183_t;

static inline uint64_t CAVM_BBXFX_CONFIG_183(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_183(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_183", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_183(a) cavm_bbxfx_config_183_t
#define bustype_CAVM_BBXFX_CONFIG_183(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_183(a) "BBXFX_CONFIG_183"
#define busnum_CAVM_BBXFX_CONFIG_183(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_183(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_184
 *
 * BBX6 Configuration Register 184
 * Job Configuration
 */
union cavm_bbxfx_config_184
{
    uint64_t u;
    struct cavm_bbxfx_config_184_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_184_s cn; */
};
typedef union cavm_bbxfx_config_184 cavm_bbxfx_config_184_t;

static inline uint64_t CAVM_BBXFX_CONFIG_184(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_184(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_184", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_184(a) cavm_bbxfx_config_184_t
#define bustype_CAVM_BBXFX_CONFIG_184(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_184(a) "BBXFX_CONFIG_184"
#define busnum_CAVM_BBXFX_CONFIG_184(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_184(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_185
 *
 * BBX6 Configuration Register 185
 * Job Configuration
 */
union cavm_bbxfx_config_185
{
    uint64_t u;
    struct cavm_bbxfx_config_185_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_185_s cn; */
};
typedef union cavm_bbxfx_config_185 cavm_bbxfx_config_185_t;

static inline uint64_t CAVM_BBXFX_CONFIG_185(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_185(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_185", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_185(a) cavm_bbxfx_config_185_t
#define bustype_CAVM_BBXFX_CONFIG_185(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_185(a) "BBXFX_CONFIG_185"
#define busnum_CAVM_BBXFX_CONFIG_185(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_185(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_186
 *
 * BBX6 Configuration Register 186
 * Job Configuration
 */
union cavm_bbxfx_config_186
{
    uint64_t u;
    struct cavm_bbxfx_config_186_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_186_s cn; */
};
typedef union cavm_bbxfx_config_186 cavm_bbxfx_config_186_t;

static inline uint64_t CAVM_BBXFX_CONFIG_186(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_186(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_186", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_186(a) cavm_bbxfx_config_186_t
#define bustype_CAVM_BBXFX_CONFIG_186(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_186(a) "BBXFX_CONFIG_186"
#define busnum_CAVM_BBXFX_CONFIG_186(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_186(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_187
 *
 * BBX6 Configuration Register 187
 * Job Configuration
 */
union cavm_bbxfx_config_187
{
    uint64_t u;
    struct cavm_bbxfx_config_187_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_187_s cn; */
};
typedef union cavm_bbxfx_config_187 cavm_bbxfx_config_187_t;

static inline uint64_t CAVM_BBXFX_CONFIG_187(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_187(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_187", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_187(a) cavm_bbxfx_config_187_t
#define bustype_CAVM_BBXFX_CONFIG_187(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_187(a) "BBXFX_CONFIG_187"
#define busnum_CAVM_BBXFX_CONFIG_187(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_187(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_188
 *
 * BBX6 Configuration Register 188
 * Job Configuration
 */
union cavm_bbxfx_config_188
{
    uint64_t u;
    struct cavm_bbxfx_config_188_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_188_s cn; */
};
typedef union cavm_bbxfx_config_188 cavm_bbxfx_config_188_t;

static inline uint64_t CAVM_BBXFX_CONFIG_188(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_188(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_188", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_188(a) cavm_bbxfx_config_188_t
#define bustype_CAVM_BBXFX_CONFIG_188(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_188(a) "BBXFX_CONFIG_188"
#define busnum_CAVM_BBXFX_CONFIG_188(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_188(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_189
 *
 * BBX6 Configuration Register 189
 * Job Configuration
 */
union cavm_bbxfx_config_189
{
    uint64_t u;
    struct cavm_bbxfx_config_189_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_189_s cn; */
};
typedef union cavm_bbxfx_config_189 cavm_bbxfx_config_189_t;

static inline uint64_t CAVM_BBXFX_CONFIG_189(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_189(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_189", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_189(a) cavm_bbxfx_config_189_t
#define bustype_CAVM_BBXFX_CONFIG_189(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_189(a) "BBXFX_CONFIG_189"
#define busnum_CAVM_BBXFX_CONFIG_189(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_189(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_19
 *
 * BBX6 Configuration Register 19
 * Job Configuration
 */
union cavm_bbxfx_config_19
{
    uint64_t u;
    struct cavm_bbxfx_config_19_s
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
    /* struct cavm_bbxfx_config_19_s cn; */
};
typedef union cavm_bbxfx_config_19 cavm_bbxfx_config_19_t;

static inline uint64_t CAVM_BBXFX_CONFIG_19(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_19(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82098ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_19", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_19(a) cavm_bbxfx_config_19_t
#define bustype_CAVM_BBXFX_CONFIG_19(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_19(a) "BBXFX_CONFIG_19"
#define busnum_CAVM_BBXFX_CONFIG_19(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_19(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_190
 *
 * BBX6 Configuration Register 190
 * Job Configuration
 */
union cavm_bbxfx_config_190
{
    uint64_t u;
    struct cavm_bbxfx_config_190_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_190_s cn; */
};
typedef union cavm_bbxfx_config_190 cavm_bbxfx_config_190_t;

static inline uint64_t CAVM_BBXFX_CONFIG_190(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_190(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_190", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_190(a) cavm_bbxfx_config_190_t
#define bustype_CAVM_BBXFX_CONFIG_190(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_190(a) "BBXFX_CONFIG_190"
#define busnum_CAVM_BBXFX_CONFIG_190(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_190(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_191
 *
 * BBX6 Configuration Register 191
 * Job Configuration
 */
union cavm_bbxfx_config_191
{
    uint64_t u;
    struct cavm_bbxfx_config_191_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_191_s cn; */
};
typedef union cavm_bbxfx_config_191 cavm_bbxfx_config_191_t;

static inline uint64_t CAVM_BBXFX_CONFIG_191(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_191(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c825f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_191", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_191(a) cavm_bbxfx_config_191_t
#define bustype_CAVM_BBXFX_CONFIG_191(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_191(a) "BBXFX_CONFIG_191"
#define busnum_CAVM_BBXFX_CONFIG_191(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_191(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_192
 *
 * BBX6 Configuration Register 192
 * Job Configuration
 */
union cavm_bbxfx_config_192
{
    uint64_t u;
    struct cavm_bbxfx_config_192_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_192_s cn; */
};
typedef union cavm_bbxfx_config_192 cavm_bbxfx_config_192_t;

static inline uint64_t CAVM_BBXFX_CONFIG_192(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_192(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82600ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_192", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_192(a) cavm_bbxfx_config_192_t
#define bustype_CAVM_BBXFX_CONFIG_192(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_192(a) "BBXFX_CONFIG_192"
#define busnum_CAVM_BBXFX_CONFIG_192(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_192(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_193
 *
 * BBX6 Configuration Register 193
 * Job Configuration
 */
union cavm_bbxfx_config_193
{
    uint64_t u;
    struct cavm_bbxfx_config_193_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_193_s cn; */
};
typedef union cavm_bbxfx_config_193 cavm_bbxfx_config_193_t;

static inline uint64_t CAVM_BBXFX_CONFIG_193(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_193(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82608ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_193", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_193(a) cavm_bbxfx_config_193_t
#define bustype_CAVM_BBXFX_CONFIG_193(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_193(a) "BBXFX_CONFIG_193"
#define busnum_CAVM_BBXFX_CONFIG_193(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_193(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_194
 *
 * BBX6 Configuration Register 194
 * Job Configuration
 */
union cavm_bbxfx_config_194
{
    uint64_t u;
    struct cavm_bbxfx_config_194_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_194_s cn; */
};
typedef union cavm_bbxfx_config_194 cavm_bbxfx_config_194_t;

static inline uint64_t CAVM_BBXFX_CONFIG_194(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_194(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82610ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_194", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_194(a) cavm_bbxfx_config_194_t
#define bustype_CAVM_BBXFX_CONFIG_194(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_194(a) "BBXFX_CONFIG_194"
#define busnum_CAVM_BBXFX_CONFIG_194(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_194(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_195
 *
 * BBX6 Configuration Register 195
 * Job Configuration
 */
union cavm_bbxfx_config_195
{
    uint64_t u;
    struct cavm_bbxfx_config_195_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_195_s cn; */
};
typedef union cavm_bbxfx_config_195 cavm_bbxfx_config_195_t;

static inline uint64_t CAVM_BBXFX_CONFIG_195(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_195(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82618ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_195", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_195(a) cavm_bbxfx_config_195_t
#define bustype_CAVM_BBXFX_CONFIG_195(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_195(a) "BBXFX_CONFIG_195"
#define busnum_CAVM_BBXFX_CONFIG_195(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_195(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_196
 *
 * BBX6 Configuration Register 196
 * Job Configuration
 */
union cavm_bbxfx_config_196
{
    uint64_t u;
    struct cavm_bbxfx_config_196_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_196_s cn; */
};
typedef union cavm_bbxfx_config_196 cavm_bbxfx_config_196_t;

static inline uint64_t CAVM_BBXFX_CONFIG_196(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_196(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82620ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_196", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_196(a) cavm_bbxfx_config_196_t
#define bustype_CAVM_BBXFX_CONFIG_196(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_196(a) "BBXFX_CONFIG_196"
#define busnum_CAVM_BBXFX_CONFIG_196(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_196(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_197
 *
 * BBX6 Configuration Register 197
 * Job Configuration
 */
union cavm_bbxfx_config_197
{
    uint64_t u;
    struct cavm_bbxfx_config_197_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_197_s cn; */
};
typedef union cavm_bbxfx_config_197 cavm_bbxfx_config_197_t;

static inline uint64_t CAVM_BBXFX_CONFIG_197(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_197(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82628ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_197", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_197(a) cavm_bbxfx_config_197_t
#define bustype_CAVM_BBXFX_CONFIG_197(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_197(a) "BBXFX_CONFIG_197"
#define busnum_CAVM_BBXFX_CONFIG_197(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_197(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_198
 *
 * BBX6 Configuration Register 198
 * Job Configuration
 */
union cavm_bbxfx_config_198
{
    uint64_t u;
    struct cavm_bbxfx_config_198_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_198_s cn; */
};
typedef union cavm_bbxfx_config_198 cavm_bbxfx_config_198_t;

static inline uint64_t CAVM_BBXFX_CONFIG_198(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_198(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82630ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_198", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_198(a) cavm_bbxfx_config_198_t
#define bustype_CAVM_BBXFX_CONFIG_198(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_198(a) "BBXFX_CONFIG_198"
#define busnum_CAVM_BBXFX_CONFIG_198(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_198(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_199
 *
 * BBX6 Configuration Register 199
 * Job Configuration
 */
union cavm_bbxfx_config_199
{
    uint64_t u;
    struct cavm_bbxfx_config_199_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_199_s cn; */
};
typedef union cavm_bbxfx_config_199 cavm_bbxfx_config_199_t;

static inline uint64_t CAVM_BBXFX_CONFIG_199(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_199(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82638ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_199", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_199(a) cavm_bbxfx_config_199_t
#define bustype_CAVM_BBXFX_CONFIG_199(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_199(a) "BBXFX_CONFIG_199"
#define busnum_CAVM_BBXFX_CONFIG_199(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_199(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_2
 *
 * BBX6 Configuration Register 2
 * Job Configuration
 */
union cavm_bbxfx_config_2
{
    uint64_t u;
    struct cavm_bbxfx_config_2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f_1            : 8;  /**< [ 55: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_0            : 44; /**< [ 43:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 44; /**< [ 43:  0](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_1            : 8;  /**< [ 55: 48](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_2_s cn; */
};
typedef union cavm_bbxfx_config_2 cavm_bbxfx_config_2_t;

static inline uint64_t CAVM_BBXFX_CONFIG_2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82010ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_2", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_2(a) cavm_bbxfx_config_2_t
#define bustype_CAVM_BBXFX_CONFIG_2(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_2(a) "BBXFX_CONFIG_2"
#define busnum_CAVM_BBXFX_CONFIG_2(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_2(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_20
 *
 * BBX6 Configuration Register 20
 * Job Configuration
 */
union cavm_bbxfx_config_20
{
    uint64_t u;
    struct cavm_bbxfx_config_20_s
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
    /* struct cavm_bbxfx_config_20_s cn; */
};
typedef union cavm_bbxfx_config_20 cavm_bbxfx_config_20_t;

static inline uint64_t CAVM_BBXFX_CONFIG_20(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_20(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_20", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_20(a) cavm_bbxfx_config_20_t
#define bustype_CAVM_BBXFX_CONFIG_20(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_20(a) "BBXFX_CONFIG_20"
#define busnum_CAVM_BBXFX_CONFIG_20(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_20(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_200
 *
 * BBX6 Configuration Register 200
 * Job Configuration
 */
union cavm_bbxfx_config_200
{
    uint64_t u;
    struct cavm_bbxfx_config_200_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_200_s cn; */
};
typedef union cavm_bbxfx_config_200 cavm_bbxfx_config_200_t;

static inline uint64_t CAVM_BBXFX_CONFIG_200(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_200(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82640ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_200", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_200(a) cavm_bbxfx_config_200_t
#define bustype_CAVM_BBXFX_CONFIG_200(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_200(a) "BBXFX_CONFIG_200"
#define busnum_CAVM_BBXFX_CONFIG_200(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_200(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_21
 *
 * BBX6 Configuration Register 21
 * Job Configuration
 */
union cavm_bbxfx_config_21
{
    uint64_t u;
    struct cavm_bbxfx_config_21_s
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
    /* struct cavm_bbxfx_config_21_s cn; */
};
typedef union cavm_bbxfx_config_21 cavm_bbxfx_config_21_t;

static inline uint64_t CAVM_BBXFX_CONFIG_21(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_21(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_21", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_21(a) cavm_bbxfx_config_21_t
#define bustype_CAVM_BBXFX_CONFIG_21(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_21(a) "BBXFX_CONFIG_21"
#define busnum_CAVM_BBXFX_CONFIG_21(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_21(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_22
 *
 * BBX6 Configuration Register 22
 * Job Configuration
 */
union cavm_bbxfx_config_22
{
    uint64_t u;
    struct cavm_bbxfx_config_22_s
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
    /* struct cavm_bbxfx_config_22_s cn; */
};
typedef union cavm_bbxfx_config_22 cavm_bbxfx_config_22_t;

static inline uint64_t CAVM_BBXFX_CONFIG_22(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_22(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_22", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_22(a) cavm_bbxfx_config_22_t
#define bustype_CAVM_BBXFX_CONFIG_22(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_22(a) "BBXFX_CONFIG_22"
#define busnum_CAVM_BBXFX_CONFIG_22(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_22(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_23
 *
 * BBX6 Configuration Register 23
 * Job Configuration
 */
union cavm_bbxfx_config_23
{
    uint64_t u;
    struct cavm_bbxfx_config_23_s
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
    /* struct cavm_bbxfx_config_23_s cn; */
};
typedef union cavm_bbxfx_config_23 cavm_bbxfx_config_23_t;

static inline uint64_t CAVM_BBXFX_CONFIG_23(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_23(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_23", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_23(a) cavm_bbxfx_config_23_t
#define bustype_CAVM_BBXFX_CONFIG_23(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_23(a) "BBXFX_CONFIG_23"
#define busnum_CAVM_BBXFX_CONFIG_23(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_23(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_24
 *
 * BBX6 Configuration Register 24
 * Job Configuration
 */
union cavm_bbxfx_config_24
{
    uint64_t u;
    struct cavm_bbxfx_config_24_s
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
    /* struct cavm_bbxfx_config_24_s cn; */
};
typedef union cavm_bbxfx_config_24 cavm_bbxfx_config_24_t;

static inline uint64_t CAVM_BBXFX_CONFIG_24(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_24(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_24", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_24(a) cavm_bbxfx_config_24_t
#define bustype_CAVM_BBXFX_CONFIG_24(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_24(a) "BBXFX_CONFIG_24"
#define busnum_CAVM_BBXFX_CONFIG_24(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_24(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_25
 *
 * BBX6 Configuration Register 25
 * Job Configuration
 */
union cavm_bbxfx_config_25
{
    uint64_t u;
    struct cavm_bbxfx_config_25_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_25_s cn; */
};
typedef union cavm_bbxfx_config_25 cavm_bbxfx_config_25_t;

static inline uint64_t CAVM_BBXFX_CONFIG_25(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_25(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_25", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_25(a) cavm_bbxfx_config_25_t
#define bustype_CAVM_BBXFX_CONFIG_25(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_25(a) "BBXFX_CONFIG_25"
#define busnum_CAVM_BBXFX_CONFIG_25(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_25(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_26
 *
 * BBX6 Configuration Register 26
 * Job Configuration
 */
union cavm_bbxfx_config_26
{
    uint64_t u;
    struct cavm_bbxfx_config_26_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_26_s cn; */
};
typedef union cavm_bbxfx_config_26 cavm_bbxfx_config_26_t;

static inline uint64_t CAVM_BBXFX_CONFIG_26(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_26(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_26", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_26(a) cavm_bbxfx_config_26_t
#define bustype_CAVM_BBXFX_CONFIG_26(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_26(a) "BBXFX_CONFIG_26"
#define busnum_CAVM_BBXFX_CONFIG_26(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_26(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_27
 *
 * BBX6 Configuration Register 27
 * Job Configuration
 */
union cavm_bbxfx_config_27
{
    uint64_t u;
    struct cavm_bbxfx_config_27_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_27_s cn; */
};
typedef union cavm_bbxfx_config_27 cavm_bbxfx_config_27_t;

static inline uint64_t CAVM_BBXFX_CONFIG_27(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_27(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_27", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_27(a) cavm_bbxfx_config_27_t
#define bustype_CAVM_BBXFX_CONFIG_27(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_27(a) "BBXFX_CONFIG_27"
#define busnum_CAVM_BBXFX_CONFIG_27(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_27(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_28
 *
 * BBX6 Configuration Register 28
 * Job Configuration
 */
union cavm_bbxfx_config_28
{
    uint64_t u;
    struct cavm_bbxfx_config_28_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_28_s cn; */
};
typedef union cavm_bbxfx_config_28 cavm_bbxfx_config_28_t;

static inline uint64_t CAVM_BBXFX_CONFIG_28(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_28(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_28", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_28(a) cavm_bbxfx_config_28_t
#define bustype_CAVM_BBXFX_CONFIG_28(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_28(a) "BBXFX_CONFIG_28"
#define busnum_CAVM_BBXFX_CONFIG_28(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_28(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_29
 *
 * BBX6 Configuration Register 29
 * Job Configuration
 */
union cavm_bbxfx_config_29
{
    uint64_t u;
    struct cavm_bbxfx_config_29_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_29_s cn; */
};
typedef union cavm_bbxfx_config_29 cavm_bbxfx_config_29_t;

static inline uint64_t CAVM_BBXFX_CONFIG_29(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_29(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_29", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_29(a) cavm_bbxfx_config_29_t
#define bustype_CAVM_BBXFX_CONFIG_29(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_29(a) "BBXFX_CONFIG_29"
#define busnum_CAVM_BBXFX_CONFIG_29(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_29(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_3
 *
 * BBX6 Configuration Register 3
 * Job Configuration
 */
union cavm_bbxfx_config_3
{
    uint64_t u;
    struct cavm_bbxfx_config_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_f              : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_3_s cn; */
};
typedef union cavm_bbxfx_config_3 cavm_bbxfx_config_3_t;

static inline uint64_t CAVM_BBXFX_CONFIG_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_3", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_3(a) cavm_bbxfx_config_3_t
#define bustype_CAVM_BBXFX_CONFIG_3(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_3(a) "BBXFX_CONFIG_3"
#define busnum_CAVM_BBXFX_CONFIG_3(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_3(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_30
 *
 * BBX6 Configuration Register 30
 * Job Configuration
 */
union cavm_bbxfx_config_30
{
    uint64_t u;
    struct cavm_bbxfx_config_30_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_30_s cn; */
};
typedef union cavm_bbxfx_config_30 cavm_bbxfx_config_30_t;

static inline uint64_t CAVM_BBXFX_CONFIG_30(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_30(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_30", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_30(a) cavm_bbxfx_config_30_t
#define bustype_CAVM_BBXFX_CONFIG_30(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_30(a) "BBXFX_CONFIG_30"
#define busnum_CAVM_BBXFX_CONFIG_30(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_30(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_31
 *
 * BBX6 Configuration Register 31
 * Job Configuration
 */
union cavm_bbxfx_config_31
{
    uint64_t u;
    struct cavm_bbxfx_config_31_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_31_s cn; */
};
typedef union cavm_bbxfx_config_31 cavm_bbxfx_config_31_t;

static inline uint64_t CAVM_BBXFX_CONFIG_31(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_31(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c820f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_31", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_31(a) cavm_bbxfx_config_31_t
#define bustype_CAVM_BBXFX_CONFIG_31(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_31(a) "BBXFX_CONFIG_31"
#define busnum_CAVM_BBXFX_CONFIG_31(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_31(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_32
 *
 * BBX6 Configuration Register 32
 * Job Configuration
 */
union cavm_bbxfx_config_32
{
    uint64_t u;
    struct cavm_bbxfx_config_32_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_32_s cn; */
};
typedef union cavm_bbxfx_config_32 cavm_bbxfx_config_32_t;

static inline uint64_t CAVM_BBXFX_CONFIG_32(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_32(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82100ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_32", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_32(a) cavm_bbxfx_config_32_t
#define bustype_CAVM_BBXFX_CONFIG_32(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_32(a) "BBXFX_CONFIG_32"
#define busnum_CAVM_BBXFX_CONFIG_32(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_32(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_33
 *
 * BBX6 Configuration Register 33
 * Job Configuration
 */
union cavm_bbxfx_config_33
{
    uint64_t u;
    struct cavm_bbxfx_config_33_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_33_s cn; */
};
typedef union cavm_bbxfx_config_33 cavm_bbxfx_config_33_t;

static inline uint64_t CAVM_BBXFX_CONFIG_33(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_33(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82108ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_33", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_33(a) cavm_bbxfx_config_33_t
#define bustype_CAVM_BBXFX_CONFIG_33(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_33(a) "BBXFX_CONFIG_33"
#define busnum_CAVM_BBXFX_CONFIG_33(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_33(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_34
 *
 * BBX6 Configuration Register 34
 * Job Configuration
 */
union cavm_bbxfx_config_34
{
    uint64_t u;
    struct cavm_bbxfx_config_34_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_34_s cn; */
};
typedef union cavm_bbxfx_config_34 cavm_bbxfx_config_34_t;

static inline uint64_t CAVM_BBXFX_CONFIG_34(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_34(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82110ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_34", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_34(a) cavm_bbxfx_config_34_t
#define bustype_CAVM_BBXFX_CONFIG_34(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_34(a) "BBXFX_CONFIG_34"
#define busnum_CAVM_BBXFX_CONFIG_34(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_34(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_35
 *
 * BBX6 Configuration Register 35
 * Job Configuration
 */
union cavm_bbxfx_config_35
{
    uint64_t u;
    struct cavm_bbxfx_config_35_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_35_s cn; */
};
typedef union cavm_bbxfx_config_35 cavm_bbxfx_config_35_t;

static inline uint64_t CAVM_BBXFX_CONFIG_35(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_35(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82118ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_35", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_35(a) cavm_bbxfx_config_35_t
#define bustype_CAVM_BBXFX_CONFIG_35(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_35(a) "BBXFX_CONFIG_35"
#define busnum_CAVM_BBXFX_CONFIG_35(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_35(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_36
 *
 * BBX6 Configuration Register 36
 * Job Configuration
 */
union cavm_bbxfx_config_36
{
    uint64_t u;
    struct cavm_bbxfx_config_36_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_36_s cn; */
};
typedef union cavm_bbxfx_config_36 cavm_bbxfx_config_36_t;

static inline uint64_t CAVM_BBXFX_CONFIG_36(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_36(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82120ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_36", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_36(a) cavm_bbxfx_config_36_t
#define bustype_CAVM_BBXFX_CONFIG_36(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_36(a) "BBXFX_CONFIG_36"
#define busnum_CAVM_BBXFX_CONFIG_36(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_36(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_37
 *
 * BBX6 Configuration Register 37
 * Job Configuration
 */
union cavm_bbxfx_config_37
{
    uint64_t u;
    struct cavm_bbxfx_config_37_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_37_s cn; */
};
typedef union cavm_bbxfx_config_37 cavm_bbxfx_config_37_t;

static inline uint64_t CAVM_BBXFX_CONFIG_37(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_37(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82128ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_37", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_37(a) cavm_bbxfx_config_37_t
#define bustype_CAVM_BBXFX_CONFIG_37(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_37(a) "BBXFX_CONFIG_37"
#define busnum_CAVM_BBXFX_CONFIG_37(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_37(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_38
 *
 * BBX6 Configuration Register 38
 * Job Configuration
 */
union cavm_bbxfx_config_38
{
    uint64_t u;
    struct cavm_bbxfx_config_38_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_38_s cn; */
};
typedef union cavm_bbxfx_config_38 cavm_bbxfx_config_38_t;

static inline uint64_t CAVM_BBXFX_CONFIG_38(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_38(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82130ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_38", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_38(a) cavm_bbxfx_config_38_t
#define bustype_CAVM_BBXFX_CONFIG_38(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_38(a) "BBXFX_CONFIG_38"
#define busnum_CAVM_BBXFX_CONFIG_38(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_38(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_39
 *
 * BBX6 Configuration Register 39
 * Job Configuration
 */
union cavm_bbxfx_config_39
{
    uint64_t u;
    struct cavm_bbxfx_config_39_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_39_s cn; */
};
typedef union cavm_bbxfx_config_39 cavm_bbxfx_config_39_t;

static inline uint64_t CAVM_BBXFX_CONFIG_39(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_39(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82138ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_39", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_39(a) cavm_bbxfx_config_39_t
#define bustype_CAVM_BBXFX_CONFIG_39(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_39(a) "BBXFX_CONFIG_39"
#define busnum_CAVM_BBXFX_CONFIG_39(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_39(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_4
 *
 * BBX6 Configuration Register 4
 * Job Configuration
 */
union cavm_bbxfx_config_4
{
    uint64_t u;
    struct cavm_bbxfx_config_4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t config_f              : 48; /**< [ 47:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 48; /**< [ 47:  0](R/W) -- */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_4_s cn; */
};
typedef union cavm_bbxfx_config_4 cavm_bbxfx_config_4_t;

static inline uint64_t CAVM_BBXFX_CONFIG_4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_4(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82020ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_4", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_4(a) cavm_bbxfx_config_4_t
#define bustype_CAVM_BBXFX_CONFIG_4(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_4(a) "BBXFX_CONFIG_4"
#define busnum_CAVM_BBXFX_CONFIG_4(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_4(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_40
 *
 * BBX6 Configuration Register 40
 * Job Configuration
 */
union cavm_bbxfx_config_40
{
    uint64_t u;
    struct cavm_bbxfx_config_40_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_40_s cn; */
};
typedef union cavm_bbxfx_config_40 cavm_bbxfx_config_40_t;

static inline uint64_t CAVM_BBXFX_CONFIG_40(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_40(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82140ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_40", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_40(a) cavm_bbxfx_config_40_t
#define bustype_CAVM_BBXFX_CONFIG_40(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_40(a) "BBXFX_CONFIG_40"
#define busnum_CAVM_BBXFX_CONFIG_40(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_40(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_41
 *
 * BBX6 Configuration Register 41
 * Job Configuration
 */
union cavm_bbxfx_config_41
{
    uint64_t u;
    struct cavm_bbxfx_config_41_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_41_s cn; */
};
typedef union cavm_bbxfx_config_41 cavm_bbxfx_config_41_t;

static inline uint64_t CAVM_BBXFX_CONFIG_41(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_41(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82148ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_41", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_41(a) cavm_bbxfx_config_41_t
#define bustype_CAVM_BBXFX_CONFIG_41(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_41(a) "BBXFX_CONFIG_41"
#define busnum_CAVM_BBXFX_CONFIG_41(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_41(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_42
 *
 * BBX6 Configuration Register 42
 * Job Configuration
 */
union cavm_bbxfx_config_42
{
    uint64_t u;
    struct cavm_bbxfx_config_42_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_42_s cn; */
};
typedef union cavm_bbxfx_config_42 cavm_bbxfx_config_42_t;

static inline uint64_t CAVM_BBXFX_CONFIG_42(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_42(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82150ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_42", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_42(a) cavm_bbxfx_config_42_t
#define bustype_CAVM_BBXFX_CONFIG_42(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_42(a) "BBXFX_CONFIG_42"
#define busnum_CAVM_BBXFX_CONFIG_42(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_42(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_43
 *
 * BBX6 Configuration Register 43
 * Job Configuration
 */
union cavm_bbxfx_config_43
{
    uint64_t u;
    struct cavm_bbxfx_config_43_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_43_s cn; */
};
typedef union cavm_bbxfx_config_43 cavm_bbxfx_config_43_t;

static inline uint64_t CAVM_BBXFX_CONFIG_43(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_43(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82158ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_43", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_43(a) cavm_bbxfx_config_43_t
#define bustype_CAVM_BBXFX_CONFIG_43(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_43(a) "BBXFX_CONFIG_43"
#define busnum_CAVM_BBXFX_CONFIG_43(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_43(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_44
 *
 * BBX6 Configuration Register 44
 * Job Configuration
 */
union cavm_bbxfx_config_44
{
    uint64_t u;
    struct cavm_bbxfx_config_44_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_44_s cn; */
};
typedef union cavm_bbxfx_config_44 cavm_bbxfx_config_44_t;

static inline uint64_t CAVM_BBXFX_CONFIG_44(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_44(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82160ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_44", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_44(a) cavm_bbxfx_config_44_t
#define bustype_CAVM_BBXFX_CONFIG_44(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_44(a) "BBXFX_CONFIG_44"
#define busnum_CAVM_BBXFX_CONFIG_44(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_44(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_45
 *
 * BBX6 Configuration Register 45
 * Job Configuration
 */
union cavm_bbxfx_config_45
{
    uint64_t u;
    struct cavm_bbxfx_config_45_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_45_s cn; */
};
typedef union cavm_bbxfx_config_45 cavm_bbxfx_config_45_t;

static inline uint64_t CAVM_BBXFX_CONFIG_45(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_45(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82168ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_45", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_45(a) cavm_bbxfx_config_45_t
#define bustype_CAVM_BBXFX_CONFIG_45(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_45(a) "BBXFX_CONFIG_45"
#define busnum_CAVM_BBXFX_CONFIG_45(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_45(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_46
 *
 * BBX6 Configuration Register 46
 * Job Configuration
 */
union cavm_bbxfx_config_46
{
    uint64_t u;
    struct cavm_bbxfx_config_46_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_46_s cn; */
};
typedef union cavm_bbxfx_config_46 cavm_bbxfx_config_46_t;

static inline uint64_t CAVM_BBXFX_CONFIG_46(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_46(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82170ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_46", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_46(a) cavm_bbxfx_config_46_t
#define bustype_CAVM_BBXFX_CONFIG_46(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_46(a) "BBXFX_CONFIG_46"
#define busnum_CAVM_BBXFX_CONFIG_46(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_46(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_47
 *
 * BBX6 Configuration Register 47
 * Job Configuration
 */
union cavm_bbxfx_config_47
{
    uint64_t u;
    struct cavm_bbxfx_config_47_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_47_s cn; */
};
typedef union cavm_bbxfx_config_47 cavm_bbxfx_config_47_t;

static inline uint64_t CAVM_BBXFX_CONFIG_47(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_47(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82178ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_47", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_47(a) cavm_bbxfx_config_47_t
#define bustype_CAVM_BBXFX_CONFIG_47(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_47(a) "BBXFX_CONFIG_47"
#define busnum_CAVM_BBXFX_CONFIG_47(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_47(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_48
 *
 * BBX6 Configuration Register 48
 * Job Configuration
 */
union cavm_bbxfx_config_48
{
    uint64_t u;
    struct cavm_bbxfx_config_48_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_48_s cn; */
};
typedef union cavm_bbxfx_config_48 cavm_bbxfx_config_48_t;

static inline uint64_t CAVM_BBXFX_CONFIG_48(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_48(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82180ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_48", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_48(a) cavm_bbxfx_config_48_t
#define bustype_CAVM_BBXFX_CONFIG_48(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_48(a) "BBXFX_CONFIG_48"
#define busnum_CAVM_BBXFX_CONFIG_48(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_48(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_49
 *
 * BBX6 Configuration Register 49
 * Job Configuration
 */
union cavm_bbxfx_config_49
{
    uint64_t u;
    struct cavm_bbxfx_config_49_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_49_s cn; */
};
typedef union cavm_bbxfx_config_49 cavm_bbxfx_config_49_t;

static inline uint64_t CAVM_BBXFX_CONFIG_49(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_49(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82188ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_49", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_49(a) cavm_bbxfx_config_49_t
#define bustype_CAVM_BBXFX_CONFIG_49(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_49(a) "BBXFX_CONFIG_49"
#define busnum_CAVM_BBXFX_CONFIG_49(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_49(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_5
 *
 * BBX6 Configuration Register 5
 * Job Configuration
 */
union cavm_bbxfx_config_5
{
    uint64_t u;
    struct cavm_bbxfx_config_5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_5_s cn; */
};
typedef union cavm_bbxfx_config_5 cavm_bbxfx_config_5_t;

static inline uint64_t CAVM_BBXFX_CONFIG_5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_5(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82028ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_5", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_5(a) cavm_bbxfx_config_5_t
#define bustype_CAVM_BBXFX_CONFIG_5(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_5(a) "BBXFX_CONFIG_5"
#define busnum_CAVM_BBXFX_CONFIG_5(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_5(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_50
 *
 * BBX6 Configuration Register 50
 * Job Configuration
 */
union cavm_bbxfx_config_50
{
    uint64_t u;
    struct cavm_bbxfx_config_50_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_50_s cn; */
};
typedef union cavm_bbxfx_config_50 cavm_bbxfx_config_50_t;

static inline uint64_t CAVM_BBXFX_CONFIG_50(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_50(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82190ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_50", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_50(a) cavm_bbxfx_config_50_t
#define bustype_CAVM_BBXFX_CONFIG_50(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_50(a) "BBXFX_CONFIG_50"
#define busnum_CAVM_BBXFX_CONFIG_50(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_50(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_51
 *
 * BBX6 Configuration Register 51
 * Job Configuration
 */
union cavm_bbxfx_config_51
{
    uint64_t u;
    struct cavm_bbxfx_config_51_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_51_s cn; */
};
typedef union cavm_bbxfx_config_51 cavm_bbxfx_config_51_t;

static inline uint64_t CAVM_BBXFX_CONFIG_51(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_51(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82198ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_51", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_51(a) cavm_bbxfx_config_51_t
#define bustype_CAVM_BBXFX_CONFIG_51(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_51(a) "BBXFX_CONFIG_51"
#define busnum_CAVM_BBXFX_CONFIG_51(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_51(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_52
 *
 * BBX6 Configuration Register 52
 * Job Configuration
 */
union cavm_bbxfx_config_52
{
    uint64_t u;
    struct cavm_bbxfx_config_52_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_52_s cn; */
};
typedef union cavm_bbxfx_config_52 cavm_bbxfx_config_52_t;

static inline uint64_t CAVM_BBXFX_CONFIG_52(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_52(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_52", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_52(a) cavm_bbxfx_config_52_t
#define bustype_CAVM_BBXFX_CONFIG_52(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_52(a) "BBXFX_CONFIG_52"
#define busnum_CAVM_BBXFX_CONFIG_52(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_52(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_53
 *
 * BBX6 Configuration Register 53
 * Job Configuration
 */
union cavm_bbxfx_config_53
{
    uint64_t u;
    struct cavm_bbxfx_config_53_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_53_s cn; */
};
typedef union cavm_bbxfx_config_53 cavm_bbxfx_config_53_t;

static inline uint64_t CAVM_BBXFX_CONFIG_53(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_53(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_53", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_53(a) cavm_bbxfx_config_53_t
#define bustype_CAVM_BBXFX_CONFIG_53(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_53(a) "BBXFX_CONFIG_53"
#define busnum_CAVM_BBXFX_CONFIG_53(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_53(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_54
 *
 * BBX6 Configuration Register 54
 * Job Configuration
 */
union cavm_bbxfx_config_54
{
    uint64_t u;
    struct cavm_bbxfx_config_54_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_54_s cn; */
};
typedef union cavm_bbxfx_config_54 cavm_bbxfx_config_54_t;

static inline uint64_t CAVM_BBXFX_CONFIG_54(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_54(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_54", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_54(a) cavm_bbxfx_config_54_t
#define bustype_CAVM_BBXFX_CONFIG_54(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_54(a) "BBXFX_CONFIG_54"
#define busnum_CAVM_BBXFX_CONFIG_54(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_54(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_55
 *
 * BBX6 Configuration Register 55
 * Job Configuration
 */
union cavm_bbxfx_config_55
{
    uint64_t u;
    struct cavm_bbxfx_config_55_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_55_s cn; */
};
typedef union cavm_bbxfx_config_55 cavm_bbxfx_config_55_t;

static inline uint64_t CAVM_BBXFX_CONFIG_55(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_55(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_55", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_55(a) cavm_bbxfx_config_55_t
#define bustype_CAVM_BBXFX_CONFIG_55(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_55(a) "BBXFX_CONFIG_55"
#define busnum_CAVM_BBXFX_CONFIG_55(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_55(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_56
 *
 * BBX6 Configuration Register 56
 * Job Configuration
 */
union cavm_bbxfx_config_56
{
    uint64_t u;
    struct cavm_bbxfx_config_56_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_56_s cn; */
};
typedef union cavm_bbxfx_config_56 cavm_bbxfx_config_56_t;

static inline uint64_t CAVM_BBXFX_CONFIG_56(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_56(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_56", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_56(a) cavm_bbxfx_config_56_t
#define bustype_CAVM_BBXFX_CONFIG_56(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_56(a) "BBXFX_CONFIG_56"
#define busnum_CAVM_BBXFX_CONFIG_56(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_56(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_57
 *
 * BBX6 Configuration Register 57
 * Job Configuration
 */
union cavm_bbxfx_config_57
{
    uint64_t u;
    struct cavm_bbxfx_config_57_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_57_s cn; */
};
typedef union cavm_bbxfx_config_57 cavm_bbxfx_config_57_t;

static inline uint64_t CAVM_BBXFX_CONFIG_57(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_57(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_57", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_57(a) cavm_bbxfx_config_57_t
#define bustype_CAVM_BBXFX_CONFIG_57(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_57(a) "BBXFX_CONFIG_57"
#define busnum_CAVM_BBXFX_CONFIG_57(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_57(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_58
 *
 * BBX6 Configuration Register 58
 * Job Configuration
 */
union cavm_bbxfx_config_58
{
    uint64_t u;
    struct cavm_bbxfx_config_58_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_58_s cn; */
};
typedef union cavm_bbxfx_config_58 cavm_bbxfx_config_58_t;

static inline uint64_t CAVM_BBXFX_CONFIG_58(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_58(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_58", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_58(a) cavm_bbxfx_config_58_t
#define bustype_CAVM_BBXFX_CONFIG_58(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_58(a) "BBXFX_CONFIG_58"
#define busnum_CAVM_BBXFX_CONFIG_58(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_58(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_59
 *
 * BBX6 Configuration Register 59
 * Job Configuration
 */
union cavm_bbxfx_config_59
{
    uint64_t u;
    struct cavm_bbxfx_config_59_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_59_s cn; */
};
typedef union cavm_bbxfx_config_59 cavm_bbxfx_config_59_t;

static inline uint64_t CAVM_BBXFX_CONFIG_59(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_59(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_59", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_59(a) cavm_bbxfx_config_59_t
#define bustype_CAVM_BBXFX_CONFIG_59(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_59(a) "BBXFX_CONFIG_59"
#define busnum_CAVM_BBXFX_CONFIG_59(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_59(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_6
 *
 * BBX6 Configuration Register 6
 * Job Configuration
 */
union cavm_bbxfx_config_6
{
    uint64_t u;
    struct cavm_bbxfx_config_6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_59_63        : 5;
        uint64_t config_f_7            : 2;  /**< [ 58: 57](R/W) -- */
        uint64_t reserved_56           : 1;
        uint64_t config_f_6            : 1;  /**< [ 55: 55](R/W) -- */
        uint64_t reserved_54           : 1;
        uint64_t config_f_5            : 2;  /**< [ 53: 52](R/W) -- */
        uint64_t reserved_46_51        : 6;
        uint64_t config_f_4            : 14; /**< [ 45: 32](R/W) -- */
        uint64_t reserved_27_31        : 5;
        uint64_t config_f_3            : 3;  /**< [ 26: 24](R/W) -- */
        uint64_t reserved_23           : 1;
        uint64_t config_f_2            : 3;  /**< [ 22: 20](R/W) -- */
        uint64_t reserved_19           : 1;
        uint64_t config_f_1            : 7;  /**< [ 18: 12](R/W) -- */
        uint64_t reserved_11           : 1;
        uint64_t config_f_0            : 11; /**< [ 10:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 11; /**< [ 10:  0](R/W) -- */
        uint64_t reserved_11           : 1;
        uint64_t config_f_1            : 7;  /**< [ 18: 12](R/W) -- */
        uint64_t reserved_19           : 1;
        uint64_t config_f_2            : 3;  /**< [ 22: 20](R/W) -- */
        uint64_t reserved_23           : 1;
        uint64_t config_f_3            : 3;  /**< [ 26: 24](R/W) -- */
        uint64_t reserved_27_31        : 5;
        uint64_t config_f_4            : 14; /**< [ 45: 32](R/W) -- */
        uint64_t reserved_46_51        : 6;
        uint64_t config_f_5            : 2;  /**< [ 53: 52](R/W) -- */
        uint64_t reserved_54           : 1;
        uint64_t config_f_6            : 1;  /**< [ 55: 55](R/W) -- */
        uint64_t reserved_56           : 1;
        uint64_t config_f_7            : 2;  /**< [ 58: 57](R/W) -- */
        uint64_t reserved_59_63        : 5;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_6_s cn; */
};
typedef union cavm_bbxfx_config_6 cavm_bbxfx_config_6_t;

static inline uint64_t CAVM_BBXFX_CONFIG_6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_6(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_6", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_6(a) cavm_bbxfx_config_6_t
#define bustype_CAVM_BBXFX_CONFIG_6(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_6(a) "BBXFX_CONFIG_6"
#define busnum_CAVM_BBXFX_CONFIG_6(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_6(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_60
 *
 * BBX6 Configuration Register 60
 * Job Configuration
 */
union cavm_bbxfx_config_60
{
    uint64_t u;
    struct cavm_bbxfx_config_60_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_60_s cn; */
};
typedef union cavm_bbxfx_config_60 cavm_bbxfx_config_60_t;

static inline uint64_t CAVM_BBXFX_CONFIG_60(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_60(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_60", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_60(a) cavm_bbxfx_config_60_t
#define bustype_CAVM_BBXFX_CONFIG_60(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_60(a) "BBXFX_CONFIG_60"
#define busnum_CAVM_BBXFX_CONFIG_60(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_60(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_61
 *
 * BBX6 Configuration Register 61
 * Job Configuration
 */
union cavm_bbxfx_config_61
{
    uint64_t u;
    struct cavm_bbxfx_config_61_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_61_s cn; */
};
typedef union cavm_bbxfx_config_61 cavm_bbxfx_config_61_t;

static inline uint64_t CAVM_BBXFX_CONFIG_61(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_61(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_61", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_61(a) cavm_bbxfx_config_61_t
#define bustype_CAVM_BBXFX_CONFIG_61(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_61(a) "BBXFX_CONFIG_61"
#define busnum_CAVM_BBXFX_CONFIG_61(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_61(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_62
 *
 * BBX6 Configuration Register 62
 * Job Configuration
 */
union cavm_bbxfx_config_62
{
    uint64_t u;
    struct cavm_bbxfx_config_62_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_62_s cn; */
};
typedef union cavm_bbxfx_config_62 cavm_bbxfx_config_62_t;

static inline uint64_t CAVM_BBXFX_CONFIG_62(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_62(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_62", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_62(a) cavm_bbxfx_config_62_t
#define bustype_CAVM_BBXFX_CONFIG_62(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_62(a) "BBXFX_CONFIG_62"
#define busnum_CAVM_BBXFX_CONFIG_62(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_62(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_63
 *
 * BBX6 Configuration Register 63
 * Job Configuration
 */
union cavm_bbxfx_config_63
{
    uint64_t u;
    struct cavm_bbxfx_config_63_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_63_s cn; */
};
typedef union cavm_bbxfx_config_63 cavm_bbxfx_config_63_t;

static inline uint64_t CAVM_BBXFX_CONFIG_63(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_63(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c821f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_63", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_63(a) cavm_bbxfx_config_63_t
#define bustype_CAVM_BBXFX_CONFIG_63(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_63(a) "BBXFX_CONFIG_63"
#define busnum_CAVM_BBXFX_CONFIG_63(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_63(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_64
 *
 * BBX6 Configuration Register 64
 * Job Configuration
 */
union cavm_bbxfx_config_64
{
    uint64_t u;
    struct cavm_bbxfx_config_64_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_64_s cn; */
};
typedef union cavm_bbxfx_config_64 cavm_bbxfx_config_64_t;

static inline uint64_t CAVM_BBXFX_CONFIG_64(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_64(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82200ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_64", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_64(a) cavm_bbxfx_config_64_t
#define bustype_CAVM_BBXFX_CONFIG_64(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_64(a) "BBXFX_CONFIG_64"
#define busnum_CAVM_BBXFX_CONFIG_64(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_64(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_65
 *
 * BBX6 Configuration Register 65
 * Job Configuration
 */
union cavm_bbxfx_config_65
{
    uint64_t u;
    struct cavm_bbxfx_config_65_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_65_s cn; */
};
typedef union cavm_bbxfx_config_65 cavm_bbxfx_config_65_t;

static inline uint64_t CAVM_BBXFX_CONFIG_65(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_65(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82208ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_65", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_65(a) cavm_bbxfx_config_65_t
#define bustype_CAVM_BBXFX_CONFIG_65(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_65(a) "BBXFX_CONFIG_65"
#define busnum_CAVM_BBXFX_CONFIG_65(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_65(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_66
 *
 * BBX6 Configuration Register 66
 * Job Configuration
 */
union cavm_bbxfx_config_66
{
    uint64_t u;
    struct cavm_bbxfx_config_66_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_66_s cn; */
};
typedef union cavm_bbxfx_config_66 cavm_bbxfx_config_66_t;

static inline uint64_t CAVM_BBXFX_CONFIG_66(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_66(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82210ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_66", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_66(a) cavm_bbxfx_config_66_t
#define bustype_CAVM_BBXFX_CONFIG_66(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_66(a) "BBXFX_CONFIG_66"
#define busnum_CAVM_BBXFX_CONFIG_66(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_66(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_67
 *
 * BBX6 Configuration Register 67
 * Job Configuration
 */
union cavm_bbxfx_config_67
{
    uint64_t u;
    struct cavm_bbxfx_config_67_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_67_s cn; */
};
typedef union cavm_bbxfx_config_67 cavm_bbxfx_config_67_t;

static inline uint64_t CAVM_BBXFX_CONFIG_67(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_67(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82218ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_67", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_67(a) cavm_bbxfx_config_67_t
#define bustype_CAVM_BBXFX_CONFIG_67(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_67(a) "BBXFX_CONFIG_67"
#define busnum_CAVM_BBXFX_CONFIG_67(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_67(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_68
 *
 * BBX6 Configuration Register 68
 * Job Configuration
 */
union cavm_bbxfx_config_68
{
    uint64_t u;
    struct cavm_bbxfx_config_68_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_68_s cn; */
};
typedef union cavm_bbxfx_config_68 cavm_bbxfx_config_68_t;

static inline uint64_t CAVM_BBXFX_CONFIG_68(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_68(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82220ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_68", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_68(a) cavm_bbxfx_config_68_t
#define bustype_CAVM_BBXFX_CONFIG_68(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_68(a) "BBXFX_CONFIG_68"
#define busnum_CAVM_BBXFX_CONFIG_68(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_68(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_69
 *
 * BBX6 Configuration Register 69
 * Job Configuration
 */
union cavm_bbxfx_config_69
{
    uint64_t u;
    struct cavm_bbxfx_config_69_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_69_s cn; */
};
typedef union cavm_bbxfx_config_69 cavm_bbxfx_config_69_t;

static inline uint64_t CAVM_BBXFX_CONFIG_69(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_69(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82228ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_69", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_69(a) cavm_bbxfx_config_69_t
#define bustype_CAVM_BBXFX_CONFIG_69(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_69(a) "BBXFX_CONFIG_69"
#define busnum_CAVM_BBXFX_CONFIG_69(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_69(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_7
 *
 * BBX6 Configuration Register 7
 * Job Configuration
 */
union cavm_bbxfx_config_7
{
    uint64_t u;
    struct cavm_bbxfx_config_7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_7_s cn; */
};
typedef union cavm_bbxfx_config_7 cavm_bbxfx_config_7_t;

static inline uint64_t CAVM_BBXFX_CONFIG_7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_7(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_7", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_7(a) cavm_bbxfx_config_7_t
#define bustype_CAVM_BBXFX_CONFIG_7(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_7(a) "BBXFX_CONFIG_7"
#define busnum_CAVM_BBXFX_CONFIG_7(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_7(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_70
 *
 * BBX6 Configuration Register 70
 * Job Configuration
 */
union cavm_bbxfx_config_70
{
    uint64_t u;
    struct cavm_bbxfx_config_70_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_70_s cn; */
};
typedef union cavm_bbxfx_config_70 cavm_bbxfx_config_70_t;

static inline uint64_t CAVM_BBXFX_CONFIG_70(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_70(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82230ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_70", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_70(a) cavm_bbxfx_config_70_t
#define bustype_CAVM_BBXFX_CONFIG_70(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_70(a) "BBXFX_CONFIG_70"
#define busnum_CAVM_BBXFX_CONFIG_70(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_70(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_71
 *
 * BBX6 Configuration Register 71
 * Job Configuration
 */
union cavm_bbxfx_config_71
{
    uint64_t u;
    struct cavm_bbxfx_config_71_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_71_s cn; */
};
typedef union cavm_bbxfx_config_71 cavm_bbxfx_config_71_t;

static inline uint64_t CAVM_BBXFX_CONFIG_71(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_71(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82238ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_71", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_71(a) cavm_bbxfx_config_71_t
#define bustype_CAVM_BBXFX_CONFIG_71(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_71(a) "BBXFX_CONFIG_71"
#define busnum_CAVM_BBXFX_CONFIG_71(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_71(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_72
 *
 * BBX6 Configuration Register 72
 * Job Configuration
 */
union cavm_bbxfx_config_72
{
    uint64_t u;
    struct cavm_bbxfx_config_72_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_72_s cn; */
};
typedef union cavm_bbxfx_config_72 cavm_bbxfx_config_72_t;

static inline uint64_t CAVM_BBXFX_CONFIG_72(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_72(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82240ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_72", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_72(a) cavm_bbxfx_config_72_t
#define bustype_CAVM_BBXFX_CONFIG_72(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_72(a) "BBXFX_CONFIG_72"
#define busnum_CAVM_BBXFX_CONFIG_72(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_72(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_73
 *
 * BBX6 Configuration Register 73
 * Job Configuration
 */
union cavm_bbxfx_config_73
{
    uint64_t u;
    struct cavm_bbxfx_config_73_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_73_s cn; */
};
typedef union cavm_bbxfx_config_73 cavm_bbxfx_config_73_t;

static inline uint64_t CAVM_BBXFX_CONFIG_73(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_73(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82248ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_73", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_73(a) cavm_bbxfx_config_73_t
#define bustype_CAVM_BBXFX_CONFIG_73(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_73(a) "BBXFX_CONFIG_73"
#define busnum_CAVM_BBXFX_CONFIG_73(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_73(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_74
 *
 * BBX6 Configuration Register 74
 * Job Configuration
 */
union cavm_bbxfx_config_74
{
    uint64_t u;
    struct cavm_bbxfx_config_74_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_74_s cn; */
};
typedef union cavm_bbxfx_config_74 cavm_bbxfx_config_74_t;

static inline uint64_t CAVM_BBXFX_CONFIG_74(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_74(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82250ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_74", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_74(a) cavm_bbxfx_config_74_t
#define bustype_CAVM_BBXFX_CONFIG_74(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_74(a) "BBXFX_CONFIG_74"
#define busnum_CAVM_BBXFX_CONFIG_74(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_74(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_75
 *
 * BBX6 Configuration Register 75
 * Job Configuration
 */
union cavm_bbxfx_config_75
{
    uint64_t u;
    struct cavm_bbxfx_config_75_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_75_s cn; */
};
typedef union cavm_bbxfx_config_75 cavm_bbxfx_config_75_t;

static inline uint64_t CAVM_BBXFX_CONFIG_75(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_75(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82258ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_75", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_75(a) cavm_bbxfx_config_75_t
#define bustype_CAVM_BBXFX_CONFIG_75(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_75(a) "BBXFX_CONFIG_75"
#define busnum_CAVM_BBXFX_CONFIG_75(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_75(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_76
 *
 * BBX6 Configuration Register 76
 * Job Configuration
 */
union cavm_bbxfx_config_76
{
    uint64_t u;
    struct cavm_bbxfx_config_76_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_76_s cn; */
};
typedef union cavm_bbxfx_config_76 cavm_bbxfx_config_76_t;

static inline uint64_t CAVM_BBXFX_CONFIG_76(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_76(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82260ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_76", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_76(a) cavm_bbxfx_config_76_t
#define bustype_CAVM_BBXFX_CONFIG_76(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_76(a) "BBXFX_CONFIG_76"
#define busnum_CAVM_BBXFX_CONFIG_76(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_76(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_77
 *
 * BBX6 Configuration Register 77
 * Job Configuration
 */
union cavm_bbxfx_config_77
{
    uint64_t u;
    struct cavm_bbxfx_config_77_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_77_s cn; */
};
typedef union cavm_bbxfx_config_77 cavm_bbxfx_config_77_t;

static inline uint64_t CAVM_BBXFX_CONFIG_77(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_77(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82268ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_77", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_77(a) cavm_bbxfx_config_77_t
#define bustype_CAVM_BBXFX_CONFIG_77(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_77(a) "BBXFX_CONFIG_77"
#define busnum_CAVM_BBXFX_CONFIG_77(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_77(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_78
 *
 * BBX6 Configuration Register 78
 * Job Configuration
 */
union cavm_bbxfx_config_78
{
    uint64_t u;
    struct cavm_bbxfx_config_78_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_78_s cn; */
};
typedef union cavm_bbxfx_config_78 cavm_bbxfx_config_78_t;

static inline uint64_t CAVM_BBXFX_CONFIG_78(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_78(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82270ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_78", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_78(a) cavm_bbxfx_config_78_t
#define bustype_CAVM_BBXFX_CONFIG_78(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_78(a) "BBXFX_CONFIG_78"
#define busnum_CAVM_BBXFX_CONFIG_78(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_78(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_79
 *
 * BBX6 Configuration Register 79
 * Job Configuration
 */
union cavm_bbxfx_config_79
{
    uint64_t u;
    struct cavm_bbxfx_config_79_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_79_s cn; */
};
typedef union cavm_bbxfx_config_79 cavm_bbxfx_config_79_t;

static inline uint64_t CAVM_BBXFX_CONFIG_79(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_79(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82278ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_79", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_79(a) cavm_bbxfx_config_79_t
#define bustype_CAVM_BBXFX_CONFIG_79(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_79(a) "BBXFX_CONFIG_79"
#define busnum_CAVM_BBXFX_CONFIG_79(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_79(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_8
 *
 * BBX6 Configuration Register 8
 * Job Configuration
 */
union cavm_bbxfx_config_8
{
    uint64_t u;
    struct cavm_bbxfx_config_8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_8_s cn; */
};
typedef union cavm_bbxfx_config_8 cavm_bbxfx_config_8_t;

static inline uint64_t CAVM_BBXFX_CONFIG_8(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_8(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_8", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_8(a) cavm_bbxfx_config_8_t
#define bustype_CAVM_BBXFX_CONFIG_8(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_8(a) "BBXFX_CONFIG_8"
#define busnum_CAVM_BBXFX_CONFIG_8(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_8(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_80
 *
 * BBX6 Configuration Register 80
 * Job Configuration
 */
union cavm_bbxfx_config_80
{
    uint64_t u;
    struct cavm_bbxfx_config_80_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_80_s cn; */
};
typedef union cavm_bbxfx_config_80 cavm_bbxfx_config_80_t;

static inline uint64_t CAVM_BBXFX_CONFIG_80(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_80(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82280ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_80", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_80(a) cavm_bbxfx_config_80_t
#define bustype_CAVM_BBXFX_CONFIG_80(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_80(a) "BBXFX_CONFIG_80"
#define busnum_CAVM_BBXFX_CONFIG_80(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_80(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_81
 *
 * BBX6 Configuration Register 81
 * Job Configuration
 */
union cavm_bbxfx_config_81
{
    uint64_t u;
    struct cavm_bbxfx_config_81_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_81_s cn; */
};
typedef union cavm_bbxfx_config_81 cavm_bbxfx_config_81_t;

static inline uint64_t CAVM_BBXFX_CONFIG_81(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_81(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82288ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_81", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_81(a) cavm_bbxfx_config_81_t
#define bustype_CAVM_BBXFX_CONFIG_81(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_81(a) "BBXFX_CONFIG_81"
#define busnum_CAVM_BBXFX_CONFIG_81(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_81(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_82
 *
 * BBX6 Configuration Register 82
 * Job Configuration
 */
union cavm_bbxfx_config_82
{
    uint64_t u;
    struct cavm_bbxfx_config_82_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_82_s cn; */
};
typedef union cavm_bbxfx_config_82 cavm_bbxfx_config_82_t;

static inline uint64_t CAVM_BBXFX_CONFIG_82(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_82(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82290ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_82", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_82(a) cavm_bbxfx_config_82_t
#define bustype_CAVM_BBXFX_CONFIG_82(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_82(a) "BBXFX_CONFIG_82"
#define busnum_CAVM_BBXFX_CONFIG_82(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_82(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_83
 *
 * BBX6 Configuration Register 83
 * Job Configuration
 */
union cavm_bbxfx_config_83
{
    uint64_t u;
    struct cavm_bbxfx_config_83_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_83_s cn; */
};
typedef union cavm_bbxfx_config_83 cavm_bbxfx_config_83_t;

static inline uint64_t CAVM_BBXFX_CONFIG_83(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_83(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82298ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_83", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_83(a) cavm_bbxfx_config_83_t
#define bustype_CAVM_BBXFX_CONFIG_83(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_83(a) "BBXFX_CONFIG_83"
#define busnum_CAVM_BBXFX_CONFIG_83(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_83(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_84
 *
 * BBX6 Configuration Register 84
 * Job Configuration
 */
union cavm_bbxfx_config_84
{
    uint64_t u;
    struct cavm_bbxfx_config_84_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_84_s cn; */
};
typedef union cavm_bbxfx_config_84 cavm_bbxfx_config_84_t;

static inline uint64_t CAVM_BBXFX_CONFIG_84(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_84(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822a0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_84", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_84(a) cavm_bbxfx_config_84_t
#define bustype_CAVM_BBXFX_CONFIG_84(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_84(a) "BBXFX_CONFIG_84"
#define busnum_CAVM_BBXFX_CONFIG_84(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_84(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_85
 *
 * BBX6 Configuration Register 85
 * Job Configuration
 */
union cavm_bbxfx_config_85
{
    uint64_t u;
    struct cavm_bbxfx_config_85_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_85_s cn; */
};
typedef union cavm_bbxfx_config_85 cavm_bbxfx_config_85_t;

static inline uint64_t CAVM_BBXFX_CONFIG_85(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_85(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822a8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_85", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_85(a) cavm_bbxfx_config_85_t
#define bustype_CAVM_BBXFX_CONFIG_85(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_85(a) "BBXFX_CONFIG_85"
#define busnum_CAVM_BBXFX_CONFIG_85(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_85(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_86
 *
 * BBX6 Configuration Register 86
 * Job Configuration
 */
union cavm_bbxfx_config_86
{
    uint64_t u;
    struct cavm_bbxfx_config_86_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_86_s cn; */
};
typedef union cavm_bbxfx_config_86 cavm_bbxfx_config_86_t;

static inline uint64_t CAVM_BBXFX_CONFIG_86(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_86(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822b0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_86", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_86(a) cavm_bbxfx_config_86_t
#define bustype_CAVM_BBXFX_CONFIG_86(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_86(a) "BBXFX_CONFIG_86"
#define busnum_CAVM_BBXFX_CONFIG_86(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_86(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_87
 *
 * BBX6 Configuration Register 87
 * Job Configuration
 */
union cavm_bbxfx_config_87
{
    uint64_t u;
    struct cavm_bbxfx_config_87_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_87_s cn; */
};
typedef union cavm_bbxfx_config_87 cavm_bbxfx_config_87_t;

static inline uint64_t CAVM_BBXFX_CONFIG_87(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_87(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822b8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_87", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_87(a) cavm_bbxfx_config_87_t
#define bustype_CAVM_BBXFX_CONFIG_87(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_87(a) "BBXFX_CONFIG_87"
#define busnum_CAVM_BBXFX_CONFIG_87(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_87(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_88
 *
 * BBX6 Configuration Register 88
 * Job Configuration
 */
union cavm_bbxfx_config_88
{
    uint64_t u;
    struct cavm_bbxfx_config_88_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_88_s cn; */
};
typedef union cavm_bbxfx_config_88 cavm_bbxfx_config_88_t;

static inline uint64_t CAVM_BBXFX_CONFIG_88(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_88(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822c0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_88", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_88(a) cavm_bbxfx_config_88_t
#define bustype_CAVM_BBXFX_CONFIG_88(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_88(a) "BBXFX_CONFIG_88"
#define busnum_CAVM_BBXFX_CONFIG_88(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_88(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_89
 *
 * BBX6 Configuration Register 89
 * Job Configuration
 */
union cavm_bbxfx_config_89
{
    uint64_t u;
    struct cavm_bbxfx_config_89_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 49; /**< [ 48:  0](R/W) -- */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_89_s cn; */
};
typedef union cavm_bbxfx_config_89 cavm_bbxfx_config_89_t;

static inline uint64_t CAVM_BBXFX_CONFIG_89(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_89(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822c8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_89", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_89(a) cavm_bbxfx_config_89_t
#define bustype_CAVM_BBXFX_CONFIG_89(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_89(a) "BBXFX_CONFIG_89"
#define busnum_CAVM_BBXFX_CONFIG_89(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_89(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_9
 *
 * BBX6 Configuration Register 9
 * Job Configuration
 */
union cavm_bbxfx_config_9
{
    uint64_t u;
    struct cavm_bbxfx_config_9_s
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
    /* struct cavm_bbxfx_config_9_s cn; */
};
typedef union cavm_bbxfx_config_9 cavm_bbxfx_config_9_t;

static inline uint64_t CAVM_BBXFX_CONFIG_9(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_9(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_9", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_9(a) cavm_bbxfx_config_9_t
#define bustype_CAVM_BBXFX_CONFIG_9(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_9(a) "BBXFX_CONFIG_9"
#define busnum_CAVM_BBXFX_CONFIG_9(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_9(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_90
 *
 * BBX6 Configuration Register 90
 * Job Configuration
 */
union cavm_bbxfx_config_90
{
    uint64_t u;
    struct cavm_bbxfx_config_90_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 43; /**< [ 42:  0](R/W) -- */
        uint64_t reserved_43_47        : 5;
        uint64_t config_f_1            : 11; /**< [ 58: 48](R/W) -- */
        uint64_t reserved_59           : 1;
        uint64_t config_f_2            : 2;  /**< [ 61: 60](R/W) -- */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_90_s cn; */
};
typedef union cavm_bbxfx_config_90 cavm_bbxfx_config_90_t;

static inline uint64_t CAVM_BBXFX_CONFIG_90(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_90(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822d0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_90", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_90(a) cavm_bbxfx_config_90_t
#define bustype_CAVM_BBXFX_CONFIG_90(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_90(a) "BBXFX_CONFIG_90"
#define busnum_CAVM_BBXFX_CONFIG_90(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_90(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_91
 *
 * BBX6 Configuration Register 91
 * Job Configuration
 */
union cavm_bbxfx_config_91
{
    uint64_t u;
    struct cavm_bbxfx_config_91_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_91_s cn; */
};
typedef union cavm_bbxfx_config_91 cavm_bbxfx_config_91_t;

static inline uint64_t CAVM_BBXFX_CONFIG_91(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_91(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822d8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_91", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_91(a) cavm_bbxfx_config_91_t
#define bustype_CAVM_BBXFX_CONFIG_91(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_91(a) "BBXFX_CONFIG_91"
#define busnum_CAVM_BBXFX_CONFIG_91(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_91(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_92
 *
 * BBX6 Configuration Register 92
 * Job Configuration
 */
union cavm_bbxfx_config_92
{
    uint64_t u;
    struct cavm_bbxfx_config_92_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 28; /**< [ 27:  0](R/W) -- */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_92_s cn; */
};
typedef union cavm_bbxfx_config_92 cavm_bbxfx_config_92_t;

static inline uint64_t CAVM_BBXFX_CONFIG_92(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_92(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822e0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_92", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_92(a) cavm_bbxfx_config_92_t
#define bustype_CAVM_BBXFX_CONFIG_92(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_92(a) "BBXFX_CONFIG_92"
#define busnum_CAVM_BBXFX_CONFIG_92(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_92(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_93
 *
 * BBX6 Configuration Register 93
 * Job Configuration
 */
union cavm_bbxfx_config_93
{
    uint64_t u;
    struct cavm_bbxfx_config_93_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 64; /**< [ 63:  0](R/W) -- */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_93_s cn; */
};
typedef union cavm_bbxfx_config_93 cavm_bbxfx_config_93_t;

static inline uint64_t CAVM_BBXFX_CONFIG_93(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_93(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822e8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_93", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_93(a) cavm_bbxfx_config_93_t
#define bustype_CAVM_BBXFX_CONFIG_93(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_93(a) "BBXFX_CONFIG_93"
#define busnum_CAVM_BBXFX_CONFIG_93(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_93(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_94
 *
 * BBX6 Configuration Register 94
 * Job Configuration
 */
union cavm_bbxfx_config_94
{
    uint64_t u;
    struct cavm_bbxfx_config_94_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 35; /**< [ 34:  0](R/W) -- */
        uint64_t reserved_35           : 1;
        uint64_t config_f_1            : 3;  /**< [ 38: 36](R/W) -- */
        uint64_t reserved_39           : 1;
        uint64_t config_f_2            : 15; /**< [ 54: 40](R/W) -- */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_94_s cn; */
};
typedef union cavm_bbxfx_config_94 cavm_bbxfx_config_94_t;

static inline uint64_t CAVM_BBXFX_CONFIG_94(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_94(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822f0ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_94", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_94(a) cavm_bbxfx_config_94_t
#define bustype_CAVM_BBXFX_CONFIG_94(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_94(a) "BBXFX_CONFIG_94"
#define busnum_CAVM_BBXFX_CONFIG_94(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_94(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_95
 *
 * BBX6 Configuration Register 95
 * Job Configuration
 */
union cavm_bbxfx_config_95
{
    uint64_t u;
    struct cavm_bbxfx_config_95_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f              : 56; /**< [ 55:  0](R/W) -- */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_95_s cn; */
};
typedef union cavm_bbxfx_config_95 cavm_bbxfx_config_95_t;

static inline uint64_t CAVM_BBXFX_CONFIG_95(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_95(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c822f8ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_95", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_95(a) cavm_bbxfx_config_95_t
#define bustype_CAVM_BBXFX_CONFIG_95(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_95(a) "BBXFX_CONFIG_95"
#define busnum_CAVM_BBXFX_CONFIG_95(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_95(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_96
 *
 * BBX6 Configuration Register 96
 * Job Configuration
 */
union cavm_bbxfx_config_96
{
    uint64_t u;
    struct cavm_bbxfx_config_96_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_96_s cn; */
};
typedef union cavm_bbxfx_config_96 cavm_bbxfx_config_96_t;

static inline uint64_t CAVM_BBXFX_CONFIG_96(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_96(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82300ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_96", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_96(a) cavm_bbxfx_config_96_t
#define bustype_CAVM_BBXFX_CONFIG_96(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_96(a) "BBXFX_CONFIG_96"
#define busnum_CAVM_BBXFX_CONFIG_96(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_96(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_97
 *
 * BBX6 Configuration Register 97
 * Job Configuration
 */
union cavm_bbxfx_config_97
{
    uint64_t u;
    struct cavm_bbxfx_config_97_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_97_s cn; */
};
typedef union cavm_bbxfx_config_97 cavm_bbxfx_config_97_t;

static inline uint64_t CAVM_BBXFX_CONFIG_97(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_97(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82308ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_97", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_97(a) cavm_bbxfx_config_97_t
#define bustype_CAVM_BBXFX_CONFIG_97(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_97(a) "BBXFX_CONFIG_97"
#define busnum_CAVM_BBXFX_CONFIG_97(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_97(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_98
 *
 * BBX6 Configuration Register 98
 * Job Configuration
 */
union cavm_bbxfx_config_98
{
    uint64_t u;
    struct cavm_bbxfx_config_98_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_98_s cn; */
};
typedef union cavm_bbxfx_config_98 cavm_bbxfx_config_98_t;

static inline uint64_t CAVM_BBXFX_CONFIG_98(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_98(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82310ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_98", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_98(a) cavm_bbxfx_config_98_t
#define bustype_CAVM_BBXFX_CONFIG_98(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_98(a) "BBXFX_CONFIG_98"
#define busnum_CAVM_BBXFX_CONFIG_98(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_98(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_config_99
 *
 * BBX6 Configuration Register 99
 * Job Configuration
 */
union cavm_bbxfx_config_99
{
    uint64_t u;
    struct cavm_bbxfx_config_99_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
#else /* Word 0 - Little Endian */
        uint64_t config_f_0            : 12; /**< [ 11:  0](R/W) -- */
        uint64_t reserved_12_15        : 4;
        uint64_t config_f_1            : 12; /**< [ 27: 16](R/W) -- */
        uint64_t reserved_28_31        : 4;
        uint64_t config_f_2            : 12; /**< [ 43: 32](R/W) -- */
        uint64_t reserved_44_47        : 4;
        uint64_t config_f_3            : 12; /**< [ 59: 48](R/W) -- */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_config_99_s cn; */
};
typedef union cavm_bbxfx_config_99 cavm_bbxfx_config_99_t;

static inline uint64_t CAVM_BBXFX_CONFIG_99(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONFIG_99(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c82318ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONFIG_99", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONFIG_99(a) cavm_bbxfx_config_99_t
#define bustype_CAVM_BBXFX_CONFIG_99(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONFIG_99(a) "BBXFX_CONFIG_99"
#define busnum_CAVM_BBXFX_CONFIG_99(a) (a)
#define arguments_CAVM_BBXFX_CONFIG_99(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_control_main
 *
 * BBX6 Main Control Register
 * HAB Control
 */
union cavm_bbxfx_control_main
{
    uint64_t u;
    struct cavm_bbxfx_control_main_s
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
    /* struct cavm_bbxfx_control_main_s cn; */
};
typedef union cavm_bbxfx_control_main cavm_bbxfx_control_main_t;

static inline uint64_t CAVM_BBXFX_CONTROL_MAIN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONTROL_MAIN(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c80000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONTROL_MAIN", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONTROL_MAIN(a) cavm_bbxfx_control_main_t
#define bustype_CAVM_BBXFX_CONTROL_MAIN(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONTROL_MAIN(a) "BBXFX_CONTROL_MAIN"
#define busnum_CAVM_BBXFX_CONTROL_MAIN(a) (a)
#define arguments_CAVM_BBXFX_CONTROL_MAIN(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_control_status
 *
 * BBX6 Status Register
 * HAB Control
 */
union cavm_bbxfx_control_status
{
    uint64_t u;
    struct cavm_bbxfx_control_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ready                 : 1;  /**< [  4:  4](RO) Ready to receive the next job */
        uint64_t reserved_1_3          : 3;
        uint64_t busy                  : 1;  /**< [  0:  0](RO) Busy for CONFIGURATION 0 */
#else /* Word 0 - Little Endian */
        uint64_t busy                  : 1;  /**< [  0:  0](RO) Busy for CONFIGURATION 0 */
        uint64_t reserved_1_3          : 3;
        uint64_t ready                 : 1;  /**< [  4:  4](RO) Ready to receive the next job */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_control_status_s cn; */
};
typedef union cavm_bbxfx_control_status cavm_bbxfx_control_status_t;

static inline uint64_t CAVM_BBXFX_CONTROL_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_CONTROL_STATUS(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c80018ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_CONTROL_STATUS", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_CONTROL_STATUS(a) cavm_bbxfx_control_status_t
#define bustype_CAVM_BBXFX_CONTROL_STATUS(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_CONTROL_STATUS(a) "BBXFX_CONTROL_STATUS"
#define busnum_CAVM_BBXFX_CONTROL_STATUS(a) (a)
#define arguments_CAVM_BBXFX_CONTROL_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_debug_0
 *
 * BBX6 Debug Register 0
 * HAB information
 */
union cavm_bbxfx_debug_0
{
    uint64_t u;
    struct cavm_bbxfx_debug_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t hab_info              : 32; /**< [ 31:  0](RO) BBX6 RTL Version */
#else /* Word 0 - Little Endian */
        uint64_t hab_info              : 32; /**< [ 31:  0](RO) BBX6 RTL Version */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_debug_0_s cn; */
};
typedef union cavm_bbxfx_debug_0 cavm_bbxfx_debug_0_t;

static inline uint64_t CAVM_BBXFX_DEBUG_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_DEBUG_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c81000ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_DEBUG_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_DEBUG_0(a) cavm_bbxfx_debug_0_t
#define bustype_CAVM_BBXFX_DEBUG_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_DEBUG_0(a) "BBXFX_DEBUG_0"
#define busnum_CAVM_BBXFX_DEBUG_0(a) (a)
#define arguments_CAVM_BBXFX_DEBUG_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_debug_01
 *
 * BBX6 Debug Register 1
 * AB Processing Throught for job
 */
union cavm_bbxfx_debug_01
{
    uint64_t u;
    struct cavm_bbxfx_debug_01_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t read_if_throughput_job : 32;/**< [ 63: 32](RO) clock count with 1Ghz through the Read IF */
        uint64_t opr_throughput        : 32; /**< [ 31:  0](RO) clock count with 1Ghz through the Write IF */
#else /* Word 0 - Little Endian */
        uint64_t opr_throughput        : 32; /**< [ 31:  0](RO) clock count with 1Ghz through the Write IF */
        uint64_t read_if_throughput_job : 32;/**< [ 63: 32](RO) clock count with 1Ghz through the Read IF */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_debug_01_s cn; */
};
typedef union cavm_bbxfx_debug_01 cavm_bbxfx_debug_01_t;

static inline uint64_t CAVM_BBXFX_DEBUG_01(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_DEBUG_01(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c81008ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_DEBUG_01", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_DEBUG_01(a) cavm_bbxfx_debug_01_t
#define bustype_CAVM_BBXFX_DEBUG_01(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_DEBUG_01(a) "BBXFX_DEBUG_01"
#define busnum_CAVM_BBXFX_DEBUG_01(a) (a)
#define arguments_CAVM_BBXFX_DEBUG_01(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_error_register_0
 *
 * BBX6 Error Register 0
 * HAB Control
 */
union cavm_bbxfx_error_register_0
{
    uint64_t u;
    struct cavm_bbxfx_error_register_0_s
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
    /* struct cavm_bbxfx_error_register_0_s cn; */
};
typedef union cavm_bbxfx_error_register_0 cavm_bbxfx_error_register_0_t;

static inline uint64_t CAVM_BBXFX_ERROR_REGISTER_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_ERROR_REGISTER_0(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c80030ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_ERROR_REGISTER_0", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_ERROR_REGISTER_0(a) cavm_bbxfx_error_register_0_t
#define bustype_CAVM_BBXFX_ERROR_REGISTER_0(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_ERROR_REGISTER_0(a) "BBXFX_ERROR_REGISTER_0"
#define busnum_CAVM_BBXFX_ERROR_REGISTER_0(a) (a)
#define arguments_CAVM_BBXFX_ERROR_REGISTER_0(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_error_register_1
 *
 * BBX6 Error Register 1
 * HAB Control
 */
union cavm_bbxfx_error_register_1
{
    uint64_t u;
    struct cavm_bbxfx_error_register_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t inter_err_job_id      : 16; /**< [ 31: 16](R/W1C) internal error jib ID for Error Register 1 */
        uint64_t reserved_8_15         : 8;
        uint64_t sample_size_mis_match : 1;  /**< [  7:  7](R/W1C) sample data size mis-match for setting size */
        uint64_t reserved_2_6          : 5;
        uint64_t job_ue_size_over      : 1;  /**< [  1:  1](R/W1C) Data ue over */
        uint64_t job_data_size_over    : 1;  /**< [  0:  0](R/W1C) Data size over */
#else /* Word 0 - Little Endian */
        uint64_t job_data_size_over    : 1;  /**< [  0:  0](R/W1C) Data size over */
        uint64_t job_ue_size_over      : 1;  /**< [  1:  1](R/W1C) Data ue over */
        uint64_t reserved_2_6          : 5;
        uint64_t sample_size_mis_match : 1;  /**< [  7:  7](R/W1C) sample data size mis-match for setting size */
        uint64_t reserved_8_15         : 8;
        uint64_t inter_err_job_id      : 16; /**< [ 31: 16](R/W1C) internal error jib ID for Error Register 1 */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_error_register_1_s cn; */
};
typedef union cavm_bbxfx_error_register_1 cavm_bbxfx_error_register_1_t;

static inline uint64_t CAVM_BBXFX_ERROR_REGISTER_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_ERROR_REGISTER_1(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c80038ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_ERROR_REGISTER_1", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_ERROR_REGISTER_1(a) cavm_bbxfx_error_register_1_t
#define bustype_CAVM_BBXFX_ERROR_REGISTER_1(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_ERROR_REGISTER_1(a) "BBXFX_ERROR_REGISTER_1"
#define busnum_CAVM_BBXFX_ERROR_REGISTER_1(a) (a)
#define arguments_CAVM_BBXFX_ERROR_REGISTER_1(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_error_register_2
 *
 * BBX6 Error Register 2
 * HAB Control
 */
union cavm_bbxfx_error_register_2
{
    uint64_t u;
    struct cavm_bbxfx_error_register_2_s
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
    /* struct cavm_bbxfx_error_register_2_s cn; */
};
typedef union cavm_bbxfx_error_register_2 cavm_bbxfx_error_register_2_t;

static inline uint64_t CAVM_BBXFX_ERROR_REGISTER_2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_ERROR_REGISTER_2(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c80040ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_ERROR_REGISTER_2", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_ERROR_REGISTER_2(a) cavm_bbxfx_error_register_2_t
#define bustype_CAVM_BBXFX_ERROR_REGISTER_2(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_ERROR_REGISTER_2(a) "BBXFX_ERROR_REGISTER_2"
#define busnum_CAVM_BBXFX_ERROR_REGISTER_2(a) (a)
#define arguments_CAVM_BBXFX_ERROR_REGISTER_2(a) (a),-1,-1,-1

/**
 * Register (RSL) bbxf#_error_register_3
 *
 * BBX6 Error Register 3
 * HAB Control
 */
union cavm_bbxfx_error_register_3
{
    uint64_t u;
    struct cavm_bbxfx_error_register_3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t hab_error_en          : 1;  /**< [  0:  0](R/W) HAB specific Error Enable */
#else /* Word 0 - Little Endian */
        uint64_t hab_error_en          : 1;  /**< [  0:  0](R/W) HAB specific Error Enable */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_bbxfx_error_register_3_s cn; */
};
typedef union cavm_bbxfx_error_register_3 cavm_bbxfx_error_register_3_t;

static inline uint64_t CAVM_BBXFX_ERROR_REGISTER_3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_BBXFX_ERROR_REGISTER_3(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=1))
        return 0x87e043c80048ll + 0x8000ll * ((a) & 0x1);
    __cavm_csr_fatal("BBXFX_ERROR_REGISTER_3", 1, a, 0, 0, 0);
}

#define typedef_CAVM_BBXFX_ERROR_REGISTER_3(a) cavm_bbxfx_error_register_3_t
#define bustype_CAVM_BBXFX_ERROR_REGISTER_3(a) CSR_TYPE_RSL
#define basename_CAVM_BBXFX_ERROR_REGISTER_3(a) "BBXFX_ERROR_REGISTER_3"
#define busnum_CAVM_BBXFX_ERROR_REGISTER_3(a) (a)
#define arguments_CAVM_BBXFX_ERROR_REGISTER_3(a) (a),-1,-1,-1

#endif /* __CAVM_CSRS_BBXF_H__ */
