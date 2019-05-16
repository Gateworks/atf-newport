#ifndef __CAVM_CSRS_VDR_H__
#define __CAVM_CSRS_VDR_H__
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
 * OcteonTX VDR.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) vdr_ctl
 *
 * INTERNAL: VDR Control Register
 *
 * This register controls the configuration of the voltage drop mitigation logic.
 */
union cavm_vdr_ctl
{
    uint64_t u;
    struct cavm_vdr_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t fsm_err               : 1;  /**< [ 32: 32](R/W/H) When set, indicates that the voltage droop mitigation FSM had encountered an
                                                                 error. */
        uint64_t reserved_28_31        : 4;
        uint64_t clk_cnt5_6            : 4;  /**< [ 27: 24](R/W) Number of clock cycles for which the core clock will remain at 5/6 frequency
                                                                 after a voltage drop event. */
        uint64_t reserved_20_23        : 4;
        uint64_t clk_cnt2_3            : 4;  /**< [ 19: 16](R/W) Number of clock cycles for which the core clock will remain at 2/3 frequency
                                                                 after a voltage drop event. */
        uint64_t reserved_10_15        : 6;
        uint64_t clk_cnt1_2            : 6;  /**< [  9:  4](R/W) Number of clock cycles for which the core clock will remain at 1/2 frequency
                                                                 after a voltage drop event. */
        uint64_t bypass_sync           : 1;  /**< [  3:  3](R/W) When set, bypasses the synchronizer at the input of the droop mitigation logic. */
        uint64_t force_ddet            : 1;  /**< [  2:  2](R/W) Force a voltage drop detection event. */
        uint64_t no_steps              : 1;  /**< [  1:  1](R/W) No steps.
                                                                 0 = Clock frequency will gradually increase from half speed to full speed.
                                                                 1 = Clock frequency will immediately go back to full speed. */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enables the frequency reduction when voltage drop is detected. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) Enables the frequency reduction when voltage drop is detected. */
        uint64_t no_steps              : 1;  /**< [  1:  1](R/W) No steps.
                                                                 0 = Clock frequency will gradually increase from half speed to full speed.
                                                                 1 = Clock frequency will immediately go back to full speed. */
        uint64_t force_ddet            : 1;  /**< [  2:  2](R/W) Force a voltage drop detection event. */
        uint64_t bypass_sync           : 1;  /**< [  3:  3](R/W) When set, bypasses the synchronizer at the input of the droop mitigation logic. */
        uint64_t clk_cnt1_2            : 6;  /**< [  9:  4](R/W) Number of clock cycles for which the core clock will remain at 1/2 frequency
                                                                 after a voltage drop event. */
        uint64_t reserved_10_15        : 6;
        uint64_t clk_cnt2_3            : 4;  /**< [ 19: 16](R/W) Number of clock cycles for which the core clock will remain at 2/3 frequency
                                                                 after a voltage drop event. */
        uint64_t reserved_20_23        : 4;
        uint64_t clk_cnt5_6            : 4;  /**< [ 27: 24](R/W) Number of clock cycles for which the core clock will remain at 5/6 frequency
                                                                 after a voltage drop event. */
        uint64_t reserved_28_31        : 4;
        uint64_t fsm_err               : 1;  /**< [ 32: 32](R/W/H) When set, indicates that the voltage droop mitigation FSM had encountered an
                                                                 error. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_vdr_ctl_s cn; */
};
typedef union cavm_vdr_ctl cavm_vdr_ctl_t;

#define CAVM_VDR_CTL CAVM_VDR_CTL_FUNC()
static inline uint64_t CAVM_VDR_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_VDR_CTL_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x87e01e000000ll;
    __cavm_csr_fatal("VDR_CTL", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_VDR_CTL cavm_vdr_ctl_t
#define bustype_CAVM_VDR_CTL CSR_TYPE_RSL
#define basename_CAVM_VDR_CTL "VDR_CTL"
#define busnum_CAVM_VDR_CTL 0
#define arguments_CAVM_VDR_CTL -1,-1,-1,-1

/**
 * Register (RSL) vdr_eco
 *
 * INTERNAL: VDR ECO Register
 */
union cavm_vdr_eco
{
    uint64_t u;
    struct cavm_vdr_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_vdr_eco_s cn; */
};
typedef union cavm_vdr_eco cavm_vdr_eco_t;

#define CAVM_VDR_ECO CAVM_VDR_ECO_FUNC()
static inline uint64_t CAVM_VDR_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_VDR_ECO_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x87e01e000010ll;
    __cavm_csr_fatal("VDR_ECO", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_VDR_ECO cavm_vdr_eco_t
#define bustype_CAVM_VDR_ECO CSR_TYPE_RSL
#define basename_CAVM_VDR_ECO "VDR_ECO"
#define busnum_CAVM_VDR_ECO 0
#define arguments_CAVM_VDR_ECO -1,-1,-1,-1

#endif /* __CAVM_CSRS_VDR_H__ */
