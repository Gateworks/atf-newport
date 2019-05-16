#ifndef __CAVM_CSRS_RTT_H__
#define __CAVM_CSRS_RTT_H__
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
 * OcteonTX RTT.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (RSL) rtt_axi_ncbw_addr_fault
 *
 * RTT AXI NCBW Address Fault Register
 * Logs the address for store to LLC/DRAM that has an SMMU fault.
 */
union cavm_rtt_axi_ncbw_addr_fault
{
    uint64_t u;
    struct cavm_rtt_axi_ncbw_addr_fault_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 60; /**< [ 63:  4](RO/H) Address that caused an SMMU fault. */
        uint64_t reserved_1_3          : 3;
        uint64_t fault                 : 1;  /**< [  0:  0](R/W1C/H) Set to one when an SMMU fault occurs on a store. Write one to clear
                                                                 after processing the fault. */
#else /* Word 0 - Little Endian */
        uint64_t fault                 : 1;  /**< [  0:  0](R/W1C/H) Set to one when an SMMU fault occurs on a store. Write one to clear
                                                                 after processing the fault. */
        uint64_t reserved_1_3          : 3;
        uint64_t addr                  : 60; /**< [ 63:  4](RO/H) Address that caused an SMMU fault. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rtt_axi_ncbw_addr_fault_s cn; */
};
typedef union cavm_rtt_axi_ncbw_addr_fault cavm_rtt_axi_ncbw_addr_fault_t;

#define CAVM_RTT_AXI_NCBW_ADDR_FAULT CAVM_RTT_AXI_NCBW_ADDR_FAULT_FUNC()
static inline uint64_t CAVM_RTT_AXI_NCBW_ADDR_FAULT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RTT_AXI_NCBW_ADDR_FAULT_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e046005000ll;
    __cavm_csr_fatal("RTT_AXI_NCBW_ADDR_FAULT", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_RTT_AXI_NCBW_ADDR_FAULT cavm_rtt_axi_ncbw_addr_fault_t
#define bustype_CAVM_RTT_AXI_NCBW_ADDR_FAULT CSR_TYPE_RSL
#define basename_CAVM_RTT_AXI_NCBW_ADDR_FAULT "RTT_AXI_NCBW_ADDR_FAULT"
#define busnum_CAVM_RTT_AXI_NCBW_ADDR_FAULT 0
#define arguments_CAVM_RTT_AXI_NCBW_ADDR_FAULT -1,-1,-1,-1

/**
 * Register (RSL) rtt_axi_ncbw_config
 *
 * RTT AXI NCBW Configuration Register
 * RTT AXI NCBW configuration register.
 */
union cavm_rtt_axi_ncbw_config
{
    uint64_t u;
    struct cavm_rtt_axi_ncbw_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t st_op                 : 2;  /**< [ 14: 13](R/W) NCB ST operation. Configurable from ncb4_defs. */
        uint64_t ld_op                 : 2;  /**< [ 12: 11](R/W) NCB LD operation. Configurable from ncb4_defs. */
        uint64_t timer                 : 11; /**< [ 10:  0](R/W) If no new AXI writes come in when a cacheline is partially written, this timer will trigger
                                                                 the shim to send the partial cacheline to NCBW. */
#else /* Word 0 - Little Endian */
        uint64_t timer                 : 11; /**< [ 10:  0](R/W) If no new AXI writes come in when a cacheline is partially written, this timer will trigger
                                                                 the shim to send the partial cacheline to NCBW. */
        uint64_t ld_op                 : 2;  /**< [ 12: 11](R/W) NCB LD operation. Configurable from ncb4_defs. */
        uint64_t st_op                 : 2;  /**< [ 14: 13](R/W) NCB ST operation. Configurable from ncb4_defs. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rtt_axi_ncbw_config_s cn; */
};
typedef union cavm_rtt_axi_ncbw_config cavm_rtt_axi_ncbw_config_t;

#define CAVM_RTT_AXI_NCBW_CONFIG CAVM_RTT_AXI_NCBW_CONFIG_FUNC()
static inline uint64_t CAVM_RTT_AXI_NCBW_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RTT_AXI_NCBW_CONFIG_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e046005008ll;
    __cavm_csr_fatal("RTT_AXI_NCBW_CONFIG", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_RTT_AXI_NCBW_CONFIG cavm_rtt_axi_ncbw_config_t
#define bustype_CAVM_RTT_AXI_NCBW_CONFIG CSR_TYPE_RSL
#define basename_CAVM_RTT_AXI_NCBW_CONFIG "RTT_AXI_NCBW_CONFIG"
#define busnum_CAVM_RTT_AXI_NCBW_CONFIG 0
#define arguments_CAVM_RTT_AXI_NCBW_CONFIG -1,-1,-1,-1

/**
 * Register (RSL) rtt_dv_scratch
 *
 * INTERNAL: RTT Verification Scratch Register
 *
 * Internal:
 * This register set, defines a scratch register for verification purposes only per
 * RTT.
 */
union cavm_rtt_dv_scratch
{
    uint64_t u;
    struct cavm_rtt_dv_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rtt_dv_scratch_s cn; */
};
typedef union cavm_rtt_dv_scratch cavm_rtt_dv_scratch_t;

#define CAVM_RTT_DV_SCRATCH CAVM_RTT_DV_SCRATCH_FUNC()
static inline uint64_t CAVM_RTT_DV_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RTT_DV_SCRATCH_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e046005018ll;
    __cavm_csr_fatal("RTT_DV_SCRATCH", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_RTT_DV_SCRATCH cavm_rtt_dv_scratch_t
#define bustype_CAVM_RTT_DV_SCRATCH CSR_TYPE_RSL
#define basename_CAVM_RTT_DV_SCRATCH "RTT_DV_SCRATCH"
#define busnum_CAVM_RTT_DV_SCRATCH 0
#define arguments_CAVM_RTT_DV_SCRATCH -1,-1,-1,-1

/**
 * Register (RSL) rtt_eco
 *
 * INTERNAL: RTT ECO Register
 */
union cavm_rtt_eco
{
    uint64_t u;
    struct cavm_rtt_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 64; /**< [ 63:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_rtt_eco_s cn; */
};
typedef union cavm_rtt_eco cavm_rtt_eco_t;

#define CAVM_RTT_ECO CAVM_RTT_ECO_FUNC()
static inline uint64_t CAVM_RTT_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_RTT_ECO_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_LOKI))
        return 0x87e046005010ll;
    __cavm_csr_fatal("RTT_ECO", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_RTT_ECO cavm_rtt_eco_t
#define bustype_CAVM_RTT_ECO CSR_TYPE_RSL
#define basename_CAVM_RTT_ECO "RTT_ECO"
#define busnum_CAVM_RTT_ECO 0
#define arguments_CAVM_RTT_ECO -1,-1,-1,-1

#endif /* __CAVM_CSRS_RTT_H__ */
