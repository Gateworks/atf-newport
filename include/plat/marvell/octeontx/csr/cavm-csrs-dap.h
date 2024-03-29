#ifndef __CAVM_CSRS_DAP_H__
#define __CAVM_CSRS_DAP_H__
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
 * OcteonTX DAP.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration dap_bar_e
 *
 * DAP Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define CAVM_DAP_BAR_E_DAP_PF_BAR0 (0x87e002000000ll)
#define CAVM_DAP_BAR_E_DAP_PF_BAR0_SIZE 0x100000ull
#define CAVM_DAP_BAR_E_DAP_PF_BAR2_CN8 (0x87a080000000ll)
#define CAVM_DAP_BAR_E_DAP_PF_BAR2_CN8_SIZE 0x2000000ull
#define CAVM_DAP_BAR_E_DAP_PF_BAR2_CN9 (0x87a000000000ll)
#define CAVM_DAP_BAR_E_DAP_PF_BAR2_CN9_SIZE 0x100000000ull

/**
 * Structure dap_cab_addr_s
 *
 * DAP Core Access Address Structure
 * A CVM-AP (CAB) access address is formed using this structure.
 */
union cavm_dap_cab_addr_s
{
    uint64_t u;
    struct cavm_dap_cab_addr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t io                    : 5;  /**< [ 51: 47] Indicates I/O space. */
        uint64_t reserved_46           : 1;
        uint64_t node                  : 2;  /**< [ 45: 44] Reserved.
                                                                 Internal:
                                                                 CCPI node number. */
        uint64_t did                   : 8;  /**< [ 43: 36] Indicates CAB access. */
        uint64_t sec                   : 1;  /**< [ 35: 35] Secure access. See the DAP Chapter for information on the protections related to
                                                                 this field.
                                                                 0 = Nonsecure.
                                                                 1 = Secure. */
        uint64_t reserved_25_34        : 10;
        uint64_t core                  : 6;  /**< [ 24: 19] AP core number. */
        uint64_t regnum                : 16; /**< [ 18:  3] System register number within the given AP core. */
        uint64_t reserved_0_2          : 3;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_2          : 3;
        uint64_t regnum                : 16; /**< [ 18:  3] System register number within the given AP core. */
        uint64_t core                  : 6;  /**< [ 24: 19] AP core number. */
        uint64_t reserved_25_34        : 10;
        uint64_t sec                   : 1;  /**< [ 35: 35] Secure access. See the DAP Chapter for information on the protections related to
                                                                 this field.
                                                                 0 = Nonsecure.
                                                                 1 = Secure. */
        uint64_t did                   : 8;  /**< [ 43: 36] Indicates CAB access. */
        uint64_t node                  : 2;  /**< [ 45: 44] Reserved.
                                                                 Internal:
                                                                 CCPI node number. */
        uint64_t reserved_46           : 1;
        uint64_t io                    : 5;  /**< [ 51: 47] Indicates I/O space. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_cab_addr_s_s cn; */
};

/**
 * Register (RSL) dap_const
 *
 * DAP Constant Register
 * This register contains constant for software discovery.
 */
union cavm_dap_const
{
    uint64_t u;
    struct cavm_dap_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_const_s cn; */
};
typedef union cavm_dap_const cavm_dap_const_t;

#define CAVM_DAP_CONST CAVM_DAP_CONST_FUNC()
static inline uint64_t CAVM_DAP_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_CONST_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x87e002000130ll;
    __cavm_csr_fatal("DAP_CONST", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DAP_CONST cavm_dap_const_t
#define bustype_CAVM_DAP_CONST CSR_TYPE_RSL
#define basename_CAVM_DAP_CONST "DAP_CONST"
#define device_bar_CAVM_DAP_CONST 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_CONST 0
#define arguments_CAVM_DAP_CONST -1,-1,-1,-1

/**
 * Register (RSL) dap_eco
 *
 * INTERNAL: DAP ECO Register
 */
union cavm_dap_eco
{
    uint64_t u;
    struct cavm_dap_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_ro                : 16; /**< [ 31: 16](RO) Reserved for ECO usage. */
        uint64_t eco_rw                : 16; /**< [ 15:  0](R/W) Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 16; /**< [ 15:  0](R/W) Reserved for ECO usage. */
        uint64_t eco_ro                : 16; /**< [ 31: 16](RO) Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_eco_s cn; */
};
typedef union cavm_dap_eco cavm_dap_eco_t;

#define CAVM_DAP_ECO CAVM_DAP_ECO_FUNC()
static inline uint64_t CAVM_DAP_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_ECO_FUNC(void)
{
    return 0x87e002000120ll;
}

#define typedef_CAVM_DAP_ECO cavm_dap_eco_t
#define bustype_CAVM_DAP_ECO CSR_TYPE_RSL
#define basename_CAVM_DAP_ECO "DAP_ECO"
#define device_bar_CAVM_DAP_ECO 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_ECO 0
#define arguments_CAVM_DAP_ECO -1,-1,-1,-1

/**
 * Register (RSL32b) dap_hwpoll_cnt
 *
 * DAP Hardware Poll Counter Register
 */
union cavm_dap_hwpoll_cnt
{
    uint32_t u;
    struct cavm_dap_hwpoll_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t poll_dis              : 1;  /**< [ 31: 31](R/W) Disable hardware polling. For diagnostic use only. */
        uint32_t reserved_16_30        : 15;
        uint32_t count                 : 16; /**< [ 15:  0](R/W) Number of coprocessor-clocks between DAP bus poll intervals.
                                                                 With the approximate transaction delay of 256 cycles, the default
                                                                 results in a poll approximately every 2048 cycles.
                                                                 Must not be zero. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint32_t count                 : 16; /**< [ 15:  0](R/W) Number of coprocessor-clocks between DAP bus poll intervals.
                                                                 With the approximate transaction delay of 256 cycles, the default
                                                                 results in a poll approximately every 2048 cycles.
                                                                 Must not be zero. For diagnostic use only. */
        uint32_t reserved_16_30        : 15;
        uint32_t poll_dis              : 1;  /**< [ 31: 31](R/W) Disable hardware polling. For diagnostic use only. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_hwpoll_cnt_s cn; */
};
typedef union cavm_dap_hwpoll_cnt cavm_dap_hwpoll_cnt_t;

#define CAVM_DAP_HWPOLL_CNT CAVM_DAP_HWPOLL_CNT_FUNC()
static inline uint64_t CAVM_DAP_HWPOLL_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_HWPOLL_CNT_FUNC(void)
{
    return 0x87e002000114ll;
}

#define typedef_CAVM_DAP_HWPOLL_CNT cavm_dap_hwpoll_cnt_t
#define bustype_CAVM_DAP_HWPOLL_CNT CSR_TYPE_RSL32b
#define basename_CAVM_DAP_HWPOLL_CNT "DAP_HWPOLL_CNT"
#define device_bar_CAVM_DAP_HWPOLL_CNT 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_HWPOLL_CNT 0
#define arguments_CAVM_DAP_HWPOLL_CNT -1,-1,-1,-1

/**
 * Register (RSL32b) dap_imp_dar
 *
 * DAP Debug Authentication Register
 * This register controls the device enables and secure/nonsecure access permissions.
 */
union cavm_dap_imp_dar
{
    uint32_t u;
    struct cavm_dap_imp_dar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t distracefeature       : 1;  /**< [ 29: 29](R/W) Reserved.
                                                                 Internal:
                                                                 Passed to trace unit, but not presently used.
                                                                 0 = Future trace feature enabled.
                                                                 1 = Future trace feature disabled. */
        uint32_t distrace              : 1;  /**< [ 28: 28](R/W) Disable trace unit discovery.
                                                                 0 = Trace unit is discoverable by software.
                                                                 1 = Trace unit is hidden. */
        uint32_t reserved_11_27        : 17;
        uint32_t cabnsen               : 1;  /**< [ 10: 10](R/W) Enable nonsecure CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault on nonsecure CAB accesses.
                                                                 1 = Enable nonsecure CAB accesses. */
        uint32_t caben                 : 1;  /**< [  9:  9](R/W) Enable CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault for all CAB accesses.
                                                                 1 = Enable all CAB accesses.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t reserved_6_8          : 3;
        uint32_t deviceen              : 1;  /**< [  5:  5](R/W) Set this bit to use CVM-AP inside DAP for CNXXXX addressing accesses.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t dabdeviceen           : 1;  /**< [  4:  4](R/W) Set this bit to use Arm-AP inside DAP for DAB serial bus accesses.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t spniden               : 1;  /**< [  3:  3](R/W) Set this bit to enable secure noninvasive debug enable.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t spiden                : 1;  /**< [  2:  2](R/W) Set this bit to enable secure invasive debug enable.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t niden                 : 1;  /**< [  1:  1](R/W) Set this bit to enable nonsecure invasive debug enable.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t dbgen                 : 1;  /**< [  0:  0](R/W) Set this bit to enable debug enable.

                                                                 When in trusted mode resets to zero, else one. */
#else /* Word 0 - Little Endian */
        uint32_t dbgen                 : 1;  /**< [  0:  0](R/W) Set this bit to enable debug enable.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t niden                 : 1;  /**< [  1:  1](R/W) Set this bit to enable nonsecure invasive debug enable.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t spiden                : 1;  /**< [  2:  2](R/W) Set this bit to enable secure invasive debug enable.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t spniden               : 1;  /**< [  3:  3](R/W) Set this bit to enable secure noninvasive debug enable.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t dabdeviceen           : 1;  /**< [  4:  4](R/W) Set this bit to use Arm-AP inside DAP for DAB serial bus accesses.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t deviceen              : 1;  /**< [  5:  5](R/W) Set this bit to use CVM-AP inside DAP for CNXXXX addressing accesses.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t reserved_6_8          : 3;
        uint32_t caben                 : 1;  /**< [  9:  9](R/W) Enable CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault for all CAB accesses.
                                                                 1 = Enable all CAB accesses.

                                                                 When in trusted mode resets to zero, else one. */
        uint32_t cabnsen               : 1;  /**< [ 10: 10](R/W) Enable nonsecure CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault on nonsecure CAB accesses.
                                                                 1 = Enable nonsecure CAB accesses. */
        uint32_t reserved_11_27        : 17;
        uint32_t distrace              : 1;  /**< [ 28: 28](R/W) Disable trace unit discovery.
                                                                 0 = Trace unit is discoverable by software.
                                                                 1 = Trace unit is hidden. */
        uint32_t distracefeature       : 1;  /**< [ 29: 29](R/W) Reserved.
                                                                 Internal:
                                                                 Passed to trace unit, but not presently used.
                                                                 0 = Future trace feature enabled.
                                                                 1 = Future trace feature disabled. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_imp_dar_s cn8; */
    struct cavm_dap_imp_dar_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t distracefeature       : 1;  /**< [ 29: 29](R/W) Reserved.
                                                                 Internal:
                                                                 Passed to trace unit, but not presently used.
                                                                 0 = Future trace feature enabled.
                                                                 1 = Future trace feature disabled. */
        uint32_t distrace              : 1;  /**< [ 28: 28](RO) Trace unit is always discoverable in CNXXXX.
                                                                 0 = Trace unit is discoverable by software.
                                                                 1 = Trace unit is hidden.

                                                                 In CNXXXX, always discoverable. */
        uint32_t reserved_11_27        : 17;
        uint32_t cabnsen               : 1;  /**< [ 10: 10](R/W) Enable nonsecure CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault on nonsecure CAB accesses.
                                                                 1 = Enable nonsecure CAB accesses. */
        uint32_t caben                 : 1;  /**< [  9:  9](R/W) Enable CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault for all CAB accesses.
                                                                 1 = Enable all CAB accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1, resets to zero, else one. */
        uint32_t reserved_6_8          : 3;
        uint32_t deviceen              : 1;  /**< [  5:  5](R/W) Set this bit to use CVM-AP inside DAP for CNXXXX addressing accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t dabdeviceen           : 1;  /**< [  4:  4](R/W) Set this bit to use ARM-AP inside DAP for DAB serial bus accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t spniden               : 1;  /**< [  3:  3](R/W) Set this bit to enable secure noninvasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t spiden                : 1;  /**< [  2:  2](R/W) Set this bit to enable secure invasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t niden                 : 1;  /**< [  1:  1](R/W) Set this bit to enable nonsecure invasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t dbgen                 : 1;  /**< [  0:  0](R/W) Set this bit to enable debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
#else /* Word 0 - Little Endian */
        uint32_t dbgen                 : 1;  /**< [  0:  0](R/W) Set this bit to enable debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t niden                 : 1;  /**< [  1:  1](R/W) Set this bit to enable nonsecure invasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t spiden                : 1;  /**< [  2:  2](R/W) Set this bit to enable secure invasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t spniden               : 1;  /**< [  3:  3](R/W) Set this bit to enable secure noninvasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t dabdeviceen           : 1;  /**< [  4:  4](R/W) Set this bit to use ARM-AP inside DAP for DAB serial bus accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t deviceen              : 1;  /**< [  5:  5](R/W) Set this bit to use CVM-AP inside DAP for CNXXXX addressing accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t reserved_6_8          : 3;
        uint32_t caben                 : 1;  /**< [  9:  9](R/W) Enable CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault for all CAB accesses.
                                                                 1 = Enable all CAB accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1, resets to zero, else one. */
        uint32_t cabnsen               : 1;  /**< [ 10: 10](R/W) Enable nonsecure CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault on nonsecure CAB accesses.
                                                                 1 = Enable nonsecure CAB accesses. */
        uint32_t reserved_11_27        : 17;
        uint32_t distrace              : 1;  /**< [ 28: 28](RO) Trace unit is always discoverable in CNXXXX.
                                                                 0 = Trace unit is discoverable by software.
                                                                 1 = Trace unit is hidden.

                                                                 In CNXXXX, always discoverable. */
        uint32_t distracefeature       : 1;  /**< [ 29: 29](R/W) Reserved.
                                                                 Internal:
                                                                 Passed to trace unit, but not presently used.
                                                                 0 = Future trace feature enabled.
                                                                 1 = Future trace feature disabled. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } cn9;
    /* struct cavm_dap_imp_dar_cn9 cn96xxp1; */
    struct cavm_dap_imp_dar_cn96xxp3
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t distracefeature       : 1;  /**< [ 29: 29](R/W) Reserved.
                                                                 Internal:
                                                                 Passed to trace unit, but not presently used.
                                                                 0 = Future trace feature enabled.
                                                                 1 = Future trace feature disabled. */
        uint32_t distrace              : 1;  /**< [ 28: 28](RO) Trace unit is always discoverable in CNXXXX.
                                                                 0 = Trace unit is discoverable by software.
                                                                 1 = Trace unit is hidden.

                                                                 In CNXXXX, always discoverable. */
        uint32_t reserved_11_27        : 17;
        uint32_t cabnsen               : 1;  /**< [ 10: 10](R/W) Enable nonsecure CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault on nonsecure CAB accesses.
                                                                 1 = Enable nonsecure CAB accesses. */
        uint32_t caben                 : 1;  /**< [  9:  9](R/W) Enable CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault for all CAB accesses.
                                                                 1 = Enable all CAB accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1, resets to zero, else one. */
        uint32_t reserved_6_8          : 3;
        uint32_t deviceen              : 1;  /**< [  5:  5](R/W) Set this bit to use CVM-AP inside DAP for CNXXXX addressing accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t dabdeviceen           : 1;  /**< [  4:  4](R/W) Set this bit to use Arm-AP inside DAP for DAB serial bus accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t spniden               : 1;  /**< [  3:  3](R/W) Set this bit to enable secure noninvasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t spiden                : 1;  /**< [  2:  2](R/W) Set this bit to enable secure invasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t niden                 : 1;  /**< [  1:  1](R/W) Set this bit to enable nonsecure invasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t dbgen                 : 1;  /**< [  0:  0](R/W) Set this bit to enable debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
#else /* Word 0 - Little Endian */
        uint32_t dbgen                 : 1;  /**< [  0:  0](R/W) Set this bit to enable debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t niden                 : 1;  /**< [  1:  1](R/W) Set this bit to enable nonsecure invasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t spiden                : 1;  /**< [  2:  2](R/W) Set this bit to enable secure invasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t spniden               : 1;  /**< [  3:  3](R/W) Set this bit to enable secure noninvasive debug enable.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t dabdeviceen           : 1;  /**< [  4:  4](R/W) Set this bit to use Arm-AP inside DAP for DAB serial bus accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t deviceen              : 1;  /**< [  5:  5](R/W) Set this bit to use CVM-AP inside DAP for CNXXXX addressing accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1 resets to zero, else one. */
        uint32_t reserved_6_8          : 3;
        uint32_t caben                 : 1;  /**< [  9:  9](R/W) Enable CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault for all CAB accesses.
                                                                 1 = Enable all CAB accesses.

                                                                 When in trusted mode or RST_BOOT[JTAGDIS]=1, resets to zero, else one. */
        uint32_t cabnsen               : 1;  /**< [ 10: 10](R/W) Enable nonsecure CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault on nonsecure CAB accesses.
                                                                 1 = Enable nonsecure CAB accesses. */
        uint32_t reserved_11_27        : 17;
        uint32_t distrace              : 1;  /**< [ 28: 28](RO) Trace unit is always discoverable in CNXXXX.
                                                                 0 = Trace unit is discoverable by software.
                                                                 1 = Trace unit is hidden.

                                                                 In CNXXXX, always discoverable. */
        uint32_t distracefeature       : 1;  /**< [ 29: 29](R/W) Reserved.
                                                                 Internal:
                                                                 Passed to trace unit, but not presently used.
                                                                 0 = Future trace feature enabled.
                                                                 1 = Future trace feature disabled. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } cn96xxp3;
    /* struct cavm_dap_imp_dar_cn96xxp3 cn98xx; */
    /* struct cavm_dap_imp_dar_cn96xxp3 cnf95xx; */
    /* struct cavm_dap_imp_dar_cn96xxp3 loki; */
};
typedef union cavm_dap_imp_dar cavm_dap_imp_dar_t;

#define CAVM_DAP_IMP_DAR CAVM_DAP_IMP_DAR_FUNC()
static inline uint64_t CAVM_DAP_IMP_DAR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_IMP_DAR_FUNC(void)
{
    return 0x87e002000100ll;
}

#define typedef_CAVM_DAP_IMP_DAR cavm_dap_imp_dar_t
#define bustype_CAVM_DAP_IMP_DAR CSR_TYPE_RSL32b
#define basename_CAVM_DAP_IMP_DAR "DAP_IMP_DAR"
#define device_bar_CAVM_DAP_IMP_DAR 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_IMP_DAR 0
#define arguments_CAVM_DAP_IMP_DAR -1,-1,-1,-1

/**
 * Register (RSL32b) dap_owb_to
 *
 * DAP One-Wire-Bus Timeout Register
 * This register configures the one-wire bus.
 */
union cavm_dap_owb_to
{
    uint32_t u;
    struct cavm_dap_owb_to_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t to_dis                : 1;  /**< [ 31: 31](R/W) Disable timeout mechanism. */
        uint32_t reserved_16_30        : 15;
        uint32_t tovalue               : 16; /**< [ 15:  0](R/W) Timeout value. If an OWB transaction is longer than this number
                                                                 of coprocessor-clock cycles, it will timeout. */
#else /* Word 0 - Little Endian */
        uint32_t tovalue               : 16; /**< [ 15:  0](R/W) Timeout value. If an OWB transaction is longer than this number
                                                                 of coprocessor-clock cycles, it will timeout. */
        uint32_t reserved_16_30        : 15;
        uint32_t to_dis                : 1;  /**< [ 31: 31](R/W) Disable timeout mechanism. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_owb_to_s cn8; */
    struct cavm_dap_owb_to_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t to_dis                : 1;  /**< [ 31: 31](R/W) Disable timeout mechanism. */
        uint32_t reserved_16_30        : 15;
        uint32_t tovalue               : 16; /**< [ 15:  0](R/W) Timeout value. If an OWB transaction is longer than this number
                                                                 of coprocessor-clock cycles, it will timeout.

                                                                 For slow core-clock to coprocessor clock ratios, must be
                                                                 programmed to 0xFFFF to avoid overlapping transactions. */
#else /* Word 0 - Little Endian */
        uint32_t tovalue               : 16; /**< [ 15:  0](R/W) Timeout value. If an OWB transaction is longer than this number
                                                                 of coprocessor-clock cycles, it will timeout.

                                                                 For slow core-clock to coprocessor clock ratios, must be
                                                                 programmed to 0xFFFF to avoid overlapping transactions. */
        uint32_t reserved_16_30        : 15;
        uint32_t to_dis                : 1;  /**< [ 31: 31](R/W) Disable timeout mechanism. */
#endif /* Word 0 - End */
    } cn9;
};
typedef union cavm_dap_owb_to cavm_dap_owb_to_t;

#define CAVM_DAP_OWB_TO CAVM_DAP_OWB_TO_FUNC()
static inline uint64_t CAVM_DAP_OWB_TO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_OWB_TO_FUNC(void)
{
    return 0x87e002000110ll;
}

#define typedef_CAVM_DAP_OWB_TO cavm_dap_owb_to_t
#define bustype_CAVM_DAP_OWB_TO CSR_TYPE_RSL32b
#define basename_CAVM_DAP_OWB_TO "DAP_OWB_TO"
#define device_bar_CAVM_DAP_OWB_TO 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_OWB_TO 0
#define arguments_CAVM_DAP_OWB_TO -1,-1,-1,-1

/**
 * Register (RSL) dap_owb_to_status
 *
 * DAP One Wire Bus Timeout Status Register
 * This register reports error status.
 */
union cavm_dap_owb_to_status
{
    uint64_t u;
    struct cavm_dap_owb_to_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t time_out              : 1;  /**< [  0:  0](R/W1C/H) This bit will be set if there is timeout in one wire bus activity. */
#else /* Word 0 - Little Endian */
        uint64_t time_out              : 1;  /**< [  0:  0](R/W1C/H) This bit will be set if there is timeout in one wire bus activity. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_owb_to_status_s cn; */
};
typedef union cavm_dap_owb_to_status cavm_dap_owb_to_status_t;

#define CAVM_DAP_OWB_TO_STATUS CAVM_DAP_OWB_TO_STATUS_FUNC()
static inline uint64_t CAVM_DAP_OWB_TO_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_OWB_TO_STATUS_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x87e002000138ll;
    __cavm_csr_fatal("DAP_OWB_TO_STATUS", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_DAP_OWB_TO_STATUS cavm_dap_owb_to_status_t
#define bustype_CAVM_DAP_OWB_TO_STATUS CSR_TYPE_RSL
#define basename_CAVM_DAP_OWB_TO_STATUS "DAP_OWB_TO_STATUS"
#define device_bar_CAVM_DAP_OWB_TO_STATUS 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_OWB_TO_STATUS 0
#define arguments_CAVM_DAP_OWB_TO_STATUS -1,-1,-1,-1

/**
 * Register (RSL) dap_rst_on_warm
 *
 * DAP Reset On Warm Reset Register
 */
union cavm_dap_rst_on_warm
{
    uint64_t u;
    struct cavm_dap_rst_on_warm_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rst_on_warm           : 1;  /**< [  0:  0](R/W1S) Always reset DAR register.
                                                                 Once set this bit cannot be cleared until the next cold reset.
                                                                 [RST_ON_WARM] is set to one when trusted-mode changes from zero to one (i.e. a
                                                                 non-trusted boot is followed by a trusted boot). */
#else /* Word 0 - Little Endian */
        uint64_t rst_on_warm           : 1;  /**< [  0:  0](R/W1S) Always reset DAR register.
                                                                 Once set this bit cannot be cleared until the next cold reset.
                                                                 [RST_ON_WARM] is set to one when trusted-mode changes from zero to one (i.e. a
                                                                 non-trusted boot is followed by a trusted boot). */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_rst_on_warm_s cn8; */
    struct cavm_dap_rst_on_warm_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rst_on_warm           : 1;  /**< [  0:  0](R/W1S) DAP_IMP_DAR reset control.
                                                                 0 = Reset on cold domain reset.
                                                                 1 = Reset on cold domain or chip domain or debugger (JTAG) reset.

                                                                 Once set this bit cannot be cleared until the next cold reset.
                                                                 [RST_ON_WARM] is set to one when trusted-mode changes from zero to one (i.e. a
                                                                 non-trusted boot is followed by a trusted boot). */
#else /* Word 0 - Little Endian */
        uint64_t rst_on_warm           : 1;  /**< [  0:  0](R/W1S) DAP_IMP_DAR reset control.
                                                                 0 = Reset on cold domain reset.
                                                                 1 = Reset on cold domain or chip domain or debugger (JTAG) reset.

                                                                 Once set this bit cannot be cleared until the next cold reset.
                                                                 [RST_ON_WARM] is set to one when trusted-mode changes from zero to one (i.e. a
                                                                 non-trusted boot is followed by a trusted boot). */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } cn9;
};
typedef union cavm_dap_rst_on_warm cavm_dap_rst_on_warm_t;

#define CAVM_DAP_RST_ON_WARM CAVM_DAP_RST_ON_WARM_FUNC()
static inline uint64_t CAVM_DAP_RST_ON_WARM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_RST_ON_WARM_FUNC(void)
{
    return 0x87e002000128ll;
}

#define typedef_CAVM_DAP_RST_ON_WARM cavm_dap_rst_on_warm_t
#define bustype_CAVM_DAP_RST_ON_WARM CSR_TYPE_RSL
#define basename_CAVM_DAP_RST_ON_WARM "DAP_RST_ON_WARM"
#define device_bar_CAVM_DAP_RST_ON_WARM 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_RST_ON_WARM 0
#define arguments_CAVM_DAP_RST_ON_WARM -1,-1,-1,-1

/**
 * Register (RSL) dap_scratch
 *
 * INTERNAL: DAP Scratch Register
 *
 * This register is a scratch register for software use.
 */
union cavm_dap_scratch
{
    uint64_t u;
    struct cavm_dap_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data, not used by hardware. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data, not used by hardware. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_scratch_s cn; */
};
typedef union cavm_dap_scratch cavm_dap_scratch_t;

#define CAVM_DAP_SCRATCH CAVM_DAP_SCRATCH_FUNC()
static inline uint64_t CAVM_DAP_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_SCRATCH_FUNC(void)
{
    return 0x87e002000118ll;
}

#define typedef_CAVM_DAP_SCRATCH cavm_dap_scratch_t
#define bustype_CAVM_DAP_SCRATCH CSR_TYPE_RSL
#define basename_CAVM_DAP_SCRATCH "DAP_SCRATCH"
#define device_bar_CAVM_DAP_SCRATCH 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_SCRATCH 0
#define arguments_CAVM_DAP_SCRATCH -1,-1,-1,-1

/**
 * Register (RSL32b) dap_sraaddr
 *
 * DAP RSL Devices Broadcast Write Polling Register
 * This register controls broadcast write or polling to the cores.
 */
union cavm_dap_sraaddr
{
    uint32_t u;
    struct cavm_dap_sraaddr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t cabdabsel             : 1;  /**< [ 28: 28](R/W) CAB or DAB bus access selection for polling/broadcast write.
                                                                 0 = Polling/broadcast write is for DAB bus, bits \<20:5\> is the address offset.
                                                                 1 = Polling/broadcast write is for CAB bus, bits \<19:5\> is the register number. */
        uint32_t reserved_21_27        : 7;
        uint32_t regnum                : 16; /**< [ 20:  5](R/W) If [CABDABSEL]=1, then \<19:5\> is the register number with these bit definitions:
                                                                 \<19\>: Op0[0].
                                                                 \<18:16\>: Op1.
                                                                 \<15:12\>: CRn.
                                                                 \<11:8\>: CRm.
                                                                 \<7:5\>: Op.

                                                                 If [CABDABSEL]=0, then [REGNUM] is the register offset. */
        uint32_t reserved_2_4          : 3;
        uint32_t errstatus             : 1;  /**< [  1:  1](RAZ) Reserved. */
        uint32_t busy                  : 1;  /**< [  0:  0](RO/H) Busy indicator if the broadcast write or polling still in progress.
                                                                 0 = Idle.
                                                                 1 = Broadcast write or polling still in progress. */
#else /* Word 0 - Little Endian */
        uint32_t busy                  : 1;  /**< [  0:  0](RO/H) Busy indicator if the broadcast write or polling still in progress.
                                                                 0 = Idle.
                                                                 1 = Broadcast write or polling still in progress. */
        uint32_t errstatus             : 1;  /**< [  1:  1](RAZ) Reserved. */
        uint32_t reserved_2_4          : 3;
        uint32_t regnum                : 16; /**< [ 20:  5](R/W) If [CABDABSEL]=1, then \<19:5\> is the register number with these bit definitions:
                                                                 \<19\>: Op0[0].
                                                                 \<18:16\>: Op1.
                                                                 \<15:12\>: CRn.
                                                                 \<11:8\>: CRm.
                                                                 \<7:5\>: Op.

                                                                 If [CABDABSEL]=0, then [REGNUM] is the register offset. */
        uint32_t reserved_21_27        : 7;
        uint32_t cabdabsel             : 1;  /**< [ 28: 28](R/W) CAB or DAB bus access selection for polling/broadcast write.
                                                                 0 = Polling/broadcast write is for DAB bus, bits \<20:5\> is the address offset.
                                                                 1 = Polling/broadcast write is for CAB bus, bits \<19:5\> is the register number. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_sraaddr_s cn; */
};
typedef union cavm_dap_sraaddr cavm_dap_sraaddr_t;

#define CAVM_DAP_SRAADDR CAVM_DAP_SRAADDR_FUNC()
static inline uint64_t CAVM_DAP_SRAADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_SRAADDR_FUNC(void)
{
    return 0x87e002000104ll;
}

#define typedef_CAVM_DAP_SRAADDR cavm_dap_sraaddr_t
#define bustype_CAVM_DAP_SRAADDR CSR_TYPE_RSL32b
#define basename_CAVM_DAP_SRAADDR "DAP_SRAADDR"
#define device_bar_CAVM_DAP_SRAADDR 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_SRAADDR 0
#define arguments_CAVM_DAP_SRAADDR -1,-1,-1,-1

/**
 * Register (RSL) dap_sradata
 *
 * DAP Broadcast Write Data Register
 * Data register for broadcast writes and polling from the cores.
 */
union cavm_dap_sradata
{
    uint64_t u;
    struct cavm_dap_sradata_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_dap_sradata_s cn; */
};
typedef union cavm_dap_sradata cavm_dap_sradata_t;

#define CAVM_DAP_SRADATA CAVM_DAP_SRADATA_FUNC()
static inline uint64_t CAVM_DAP_SRADATA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_DAP_SRADATA_FUNC(void)
{
    return 0x87e002000108ll;
}

#define typedef_CAVM_DAP_SRADATA cavm_dap_sradata_t
#define bustype_CAVM_DAP_SRADATA CSR_TYPE_RSL
#define basename_CAVM_DAP_SRADATA "DAP_SRADATA"
#define device_bar_CAVM_DAP_SRADATA 0x0 /* PF_BAR0 */
#define busnum_CAVM_DAP_SRADATA 0
#define arguments_CAVM_DAP_SRADATA -1,-1,-1,-1

#endif /* __CAVM_CSRS_DAP_H__ */
