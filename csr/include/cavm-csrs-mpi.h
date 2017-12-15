#ifndef __CAVM_CSRS_MPI_H__
#define __CAVM_CSRS_MPI_H__
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
 * Cavium MPI.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration mpi_bar_e
 *
 * MPI Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define CAVM_MPI_BAR_E_MPI_PF_BAR0 (0x804000000000ll)
#define CAVM_MPI_BAR_E_MPI_PF_BAR0_SIZE 0x800000ull
#define CAVM_MPI_BAR_E_MPI_PF_BAR4 (0x804000f00000ll)
#define CAVM_MPI_BAR_E_MPI_PF_BAR4_SIZE 0x100000ull

/**
 * Enumeration mpi_int_vec_e
 *
 * MPI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define CAVM_MPI_INT_VEC_E_INTS (0)

/**
 * Register (NCB) mpi_cfg
 *
 * MPI/SPI Configuration Register
 * This register provides configuration for the MPI/SPI interface.
 */
union cavm_mpi_cfg
{
    uint64_t u;
    struct cavm_mpi_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t clkdiv                : 13; /**< [ 28: 16](R/W) Clock divisor.
                                                                 SPI_CK = coprocessor clock / (2 * CLKDIV)
                                                                 CLKDIV = coprocessor clock / (2 * SPI_CK) */
        uint64_t csena3                : 1;  /**< [ 15: 15](R/W) Must be one. */
        uint64_t csena2                : 1;  /**< [ 14: 14](R/W) Must be one. */
        uint64_t csena1                : 1;  /**< [ 13: 13](R/W) Must be one. */
        uint64_t csena0                : 1;  /**< [ 12: 12](R/W) Must be one. */
        uint64_t cslate                : 1;  /**< [ 11: 11](R/W) SPI_CSn_L late.
                                                                 0 = SPI_CSn_L asserts 1/2 SPI_CK cycle before the transaction.
                                                                 1 = SPI_CSn_L asserts coincident with the transaction. */
        uint64_t tritx                 : 1;  /**< [ 10: 10](R/W) Tristate TX. Used only when WIREOR = 1
                                                                 0 = SPI_DO pin is driven when slave is not expected to be driving.
                                                                 1 = SPI_DO pin is tristated when not transmitting. */
        uint64_t idleclks              : 2;  /**< [  9:  8](R/W) Idle clocks. When set, guarantees idle SPI_CK cycles between commands. */
        uint64_t cshi                  : 1;  /**< [  7:  7](R/W) SPI_CSn_L high: 1 = SPI_CSn_L is asserted high, 0 = SPI_CSn_L is asserted low. */
        uint64_t reserved_5_6          : 2;
        uint64_t lsbfirst              : 1;  /**< [  4:  4](R/W) Shift LSB first: 0 = shift MSB first, 1 = shift LSB first. */
        uint64_t wireor                : 1;  /**< [  3:  3](R/W) Wire-OR DO and DI.
                                                                 0 = SPI_DO and SPI_DI are separate wires (SPI). SPI_DO pin is always driven.
                                                                 1 = SPI_DO/DI is all from SPI_DO pin (MPI). SPI_DO pin is tristated when not transmitting.
                                                                 If WIREOR = 1, SPI_DI pin is not used by the MPI/SPI engine. */
        uint64_t clk_cont              : 1;  /**< [  2:  2](R/W) Clock control.
                                                                 0 = Clock idles to value given by IDLELO after completion of MPI/SPI transaction.
                                                                 1 = Clock never idles, requires SPI_CSn_L deassertion/assertion between commands. */
        uint64_t idlelo                : 1;  /**< [  1:  1](R/W) Clock idle low/clock invert.
                                                                 0 = SPI_CK idles high, first transition is high-to-low. This mode corresponds to SPI Block
                                                                 Guide options CPOL = 1, CPHA = 1.
                                                                 1 = SPI_CK idles low, first transition is low-to-high. This mode corresponds to SPI Block
                                                                 Guide options CPOL = 0, CPHA = 0. */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) MPI/SPI enable.
                                                                 0 = Pins are tristated.
                                                                 1 = Pins are driven. */
#else /* Word 0 - Little Endian */
        uint64_t enable                : 1;  /**< [  0:  0](R/W) MPI/SPI enable.
                                                                 0 = Pins are tristated.
                                                                 1 = Pins are driven. */
        uint64_t idlelo                : 1;  /**< [  1:  1](R/W) Clock idle low/clock invert.
                                                                 0 = SPI_CK idles high, first transition is high-to-low. This mode corresponds to SPI Block
                                                                 Guide options CPOL = 1, CPHA = 1.
                                                                 1 = SPI_CK idles low, first transition is low-to-high. This mode corresponds to SPI Block
                                                                 Guide options CPOL = 0, CPHA = 0. */
        uint64_t clk_cont              : 1;  /**< [  2:  2](R/W) Clock control.
                                                                 0 = Clock idles to value given by IDLELO after completion of MPI/SPI transaction.
                                                                 1 = Clock never idles, requires SPI_CSn_L deassertion/assertion between commands. */
        uint64_t wireor                : 1;  /**< [  3:  3](R/W) Wire-OR DO and DI.
                                                                 0 = SPI_DO and SPI_DI are separate wires (SPI). SPI_DO pin is always driven.
                                                                 1 = SPI_DO/DI is all from SPI_DO pin (MPI). SPI_DO pin is tristated when not transmitting.
                                                                 If WIREOR = 1, SPI_DI pin is not used by the MPI/SPI engine. */
        uint64_t lsbfirst              : 1;  /**< [  4:  4](R/W) Shift LSB first: 0 = shift MSB first, 1 = shift LSB first. */
        uint64_t reserved_5_6          : 2;
        uint64_t cshi                  : 1;  /**< [  7:  7](R/W) SPI_CSn_L high: 1 = SPI_CSn_L is asserted high, 0 = SPI_CSn_L is asserted low. */
        uint64_t idleclks              : 2;  /**< [  9:  8](R/W) Idle clocks. When set, guarantees idle SPI_CK cycles between commands. */
        uint64_t tritx                 : 1;  /**< [ 10: 10](R/W) Tristate TX. Used only when WIREOR = 1
                                                                 0 = SPI_DO pin is driven when slave is not expected to be driving.
                                                                 1 = SPI_DO pin is tristated when not transmitting. */
        uint64_t cslate                : 1;  /**< [ 11: 11](R/W) SPI_CSn_L late.
                                                                 0 = SPI_CSn_L asserts 1/2 SPI_CK cycle before the transaction.
                                                                 1 = SPI_CSn_L asserts coincident with the transaction. */
        uint64_t csena0                : 1;  /**< [ 12: 12](R/W) Must be one. */
        uint64_t csena1                : 1;  /**< [ 13: 13](R/W) Must be one. */
        uint64_t csena2                : 1;  /**< [ 14: 14](R/W) Must be one. */
        uint64_t csena3                : 1;  /**< [ 15: 15](R/W) Must be one. */
        uint64_t clkdiv                : 13; /**< [ 28: 16](R/W) Clock divisor.
                                                                 SPI_CK = coprocessor clock / (2 * CLKDIV)
                                                                 CLKDIV = coprocessor clock / (2 * SPI_CK) */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_cfg_s cn; */
};
typedef union cavm_mpi_cfg cavm_mpi_cfg_t;

#define CAVM_MPI_CFG CAVM_MPI_CFG_FUNC()
static inline uint64_t CAVM_MPI_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_CFG_FUNC(void)
{
    return 0x804000001000ll;
}

#define typedef_CAVM_MPI_CFG cavm_mpi_cfg_t
#define bustype_CAVM_MPI_CFG CSR_TYPE_NCB
#define basename_CAVM_MPI_CFG "MPI_CFG"
#define device_bar_CAVM_MPI_CFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_MPI_CFG 0
#define arguments_CAVM_MPI_CFG -1,-1,-1,-1

/**
 * Register (NCB) mpi_dat#
 *
 * MPI/SPI Data Registers
 */
union cavm_mpi_datx
{
    uint64_t u;
    struct cavm_mpi_datx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t data                  : 8;  /**< [  7:  0](R/W/H) Data to transmit/receive. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 8;  /**< [  7:  0](R/W/H) Data to transmit/receive. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_datx_s cn; */
};
typedef union cavm_mpi_datx cavm_mpi_datx_t;

static inline uint64_t CAVM_MPI_DATX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_DATX(unsigned long a)
{
    if (a<=8)
        return 0x804000001080ll + 8ll * ((a) & 0xf);
    __cavm_csr_fatal("MPI_DATX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MPI_DATX(a) cavm_mpi_datx_t
#define bustype_CAVM_MPI_DATX(a) CSR_TYPE_NCB
#define basename_CAVM_MPI_DATX(a) "MPI_DATX"
#define device_bar_CAVM_MPI_DATX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_MPI_DATX(a) (a)
#define arguments_CAVM_MPI_DATX(a) (a),-1,-1,-1

/**
 * Register (NCB) mpi_int_ena_w1c
 *
 * MPI Interrupt Enable Clear Register
 * This register clears interrupt enables.
 */
union cavm_mpi_int_ena_w1c
{
    uint64_t u;
    struct cavm_mpi_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t mpi_intr              : 1;  /**< [  1:  1](R/W1C) Reads or clears MPI_INT_ENA_W1S[MPI_INTR]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t mpi_intr              : 1;  /**< [  1:  1](R/W1C) Reads or clears MPI_INT_ENA_W1S[MPI_INTR]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_int_ena_w1c_s cn; */
};
typedef union cavm_mpi_int_ena_w1c cavm_mpi_int_ena_w1c_t;

#define CAVM_MPI_INT_ENA_W1C CAVM_MPI_INT_ENA_W1C_FUNC()
static inline uint64_t CAVM_MPI_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_INT_ENA_W1C_FUNC(void)
{
    return 0x804000001030ll;
}

#define typedef_CAVM_MPI_INT_ENA_W1C cavm_mpi_int_ena_w1c_t
#define bustype_CAVM_MPI_INT_ENA_W1C CSR_TYPE_NCB
#define basename_CAVM_MPI_INT_ENA_W1C "MPI_INT_ENA_W1C"
#define device_bar_CAVM_MPI_INT_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_MPI_INT_ENA_W1C 0
#define arguments_CAVM_MPI_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) mpi_int_ena_w1s
 *
 * MPI Interrupt Enable Set Register
 * This register sets interrupt enables.
 */
union cavm_mpi_int_ena_w1s
{
    uint64_t u;
    struct cavm_mpi_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t mpi_intr              : 1;  /**< [  1:  1](R/W1S) Enables reporting of MPI_STS[MPI_INTR]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t mpi_intr              : 1;  /**< [  1:  1](R/W1S) Enables reporting of MPI_STS[MPI_INTR]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_int_ena_w1s_s cn; */
};
typedef union cavm_mpi_int_ena_w1s cavm_mpi_int_ena_w1s_t;

#define CAVM_MPI_INT_ENA_W1S CAVM_MPI_INT_ENA_W1S_FUNC()
static inline uint64_t CAVM_MPI_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_INT_ENA_W1S_FUNC(void)
{
    return 0x804000001038ll;
}

#define typedef_CAVM_MPI_INT_ENA_W1S cavm_mpi_int_ena_w1s_t
#define bustype_CAVM_MPI_INT_ENA_W1S CSR_TYPE_NCB
#define basename_CAVM_MPI_INT_ENA_W1S "MPI_INT_ENA_W1S"
#define device_bar_CAVM_MPI_INT_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_MPI_INT_ENA_W1S 0
#define arguments_CAVM_MPI_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) mpi_msix_pba#
 *
 * MPI MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the MPI_INT_VEC_E enumeration.
 */
union cavm_mpi_msix_pbax
{
    uint64_t u;
    struct cavm_mpi_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated MPI_MSIX_VEC()_CTL, enumerated by MPI_INT_VEC_E. Bits
                                                                 that have no associated MPI_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated MPI_MSIX_VEC()_CTL, enumerated by MPI_INT_VEC_E. Bits
                                                                 that have no associated MPI_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_msix_pbax_s cn; */
};
typedef union cavm_mpi_msix_pbax cavm_mpi_msix_pbax_t;

static inline uint64_t CAVM_MPI_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_MSIX_PBAX(unsigned long a)
{
    if (a==0)
        return 0x804000ff0000ll + 8ll * ((a) & 0x0);
    __cavm_csr_fatal("MPI_MSIX_PBAX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MPI_MSIX_PBAX(a) cavm_mpi_msix_pbax_t
#define bustype_CAVM_MPI_MSIX_PBAX(a) CSR_TYPE_NCB
#define basename_CAVM_MPI_MSIX_PBAX(a) "MPI_MSIX_PBAX"
#define device_bar_CAVM_MPI_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_MPI_MSIX_PBAX(a) (a)
#define arguments_CAVM_MPI_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) mpi_msix_vec#_addr
 *
 * MPI MSI-X Vector Table Address Registers
 * This register is the MSI-X vector table, indexed by the MPI_INT_VEC_E enumeration.
 */
union cavm_mpi_msix_vecx_addr
{
    uint64_t u;
    struct cavm_mpi_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's MPI_MSIX_VEC()_ADDR, MPI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of MPI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_MPI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's MPI_MSIX_VEC()_ADDR, MPI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of MPI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_MPI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_msix_vecx_addr_s cn; */
};
typedef union cavm_mpi_msix_vecx_addr cavm_mpi_msix_vecx_addr_t;

static inline uint64_t CAVM_MPI_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_MSIX_VECX_ADDR(unsigned long a)
{
    if (a==0)
        return 0x804000f00000ll + 0x10ll * ((a) & 0x0);
    __cavm_csr_fatal("MPI_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MPI_MSIX_VECX_ADDR(a) cavm_mpi_msix_vecx_addr_t
#define bustype_CAVM_MPI_MSIX_VECX_ADDR(a) CSR_TYPE_NCB
#define basename_CAVM_MPI_MSIX_VECX_ADDR(a) "MPI_MSIX_VECX_ADDR"
#define device_bar_CAVM_MPI_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_MPI_MSIX_VECX_ADDR(a) (a)
#define arguments_CAVM_MPI_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) mpi_msix_vec#_ctl
 *
 * MPI MSI-X Vector Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the MPI_INT_VEC_E enumeration.
 */
union cavm_mpi_msix_vecx_ctl
{
    uint64_t u;
    struct cavm_mpi_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_msix_vecx_ctl_s cn; */
};
typedef union cavm_mpi_msix_vecx_ctl cavm_mpi_msix_vecx_ctl_t;

static inline uint64_t CAVM_MPI_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_MSIX_VECX_CTL(unsigned long a)
{
    if (a==0)
        return 0x804000f00008ll + 0x10ll * ((a) & 0x0);
    __cavm_csr_fatal("MPI_MSIX_VECX_CTL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MPI_MSIX_VECX_CTL(a) cavm_mpi_msix_vecx_ctl_t
#define bustype_CAVM_MPI_MSIX_VECX_CTL(a) CSR_TYPE_NCB
#define basename_CAVM_MPI_MSIX_VECX_CTL(a) "MPI_MSIX_VECX_CTL"
#define device_bar_CAVM_MPI_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_MPI_MSIX_VECX_CTL(a) (a)
#define arguments_CAVM_MPI_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) mpi_sts
 *
 * MPI/SPI STS Register
 */
union cavm_mpi_sts
{
    uint64_t u;
    struct cavm_mpi_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t rxnum                 : 5;  /**< [ 12:  8](RO/H) Number of bytes written for the transaction. */
        uint64_t reserved_2_7          : 6;
        uint64_t mpi_intr              : 1;  /**< [  1:  1](R/W1C/H) MPI interrupt on transaction done.  This interrupt should be cleared
                                                                 before any new SPI/MPI transaction is requested. */
        uint64_t busy                  : 1;  /**< [  0:  0](RO/H) Busy.
                                                                 0 = No MPI/SPI transaction in progress.
                                                                 1 = MPI/SPI engine is processing a transaction. */
#else /* Word 0 - Little Endian */
        uint64_t busy                  : 1;  /**< [  0:  0](RO/H) Busy.
                                                                 0 = No MPI/SPI transaction in progress.
                                                                 1 = MPI/SPI engine is processing a transaction. */
        uint64_t mpi_intr              : 1;  /**< [  1:  1](R/W1C/H) MPI interrupt on transaction done.  This interrupt should be cleared
                                                                 before any new SPI/MPI transaction is requested. */
        uint64_t reserved_2_7          : 6;
        uint64_t rxnum                 : 5;  /**< [ 12:  8](RO/H) Number of bytes written for the transaction. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_sts_s cn; */
};
typedef union cavm_mpi_sts cavm_mpi_sts_t;

#define CAVM_MPI_STS CAVM_MPI_STS_FUNC()
static inline uint64_t CAVM_MPI_STS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_STS_FUNC(void)
{
    return 0x804000001008ll;
}

#define typedef_CAVM_MPI_STS cavm_mpi_sts_t
#define bustype_CAVM_MPI_STS CSR_TYPE_NCB
#define basename_CAVM_MPI_STS "MPI_STS"
#define device_bar_CAVM_MPI_STS 0x0 /* PF_BAR0 */
#define busnum_CAVM_MPI_STS 0
#define arguments_CAVM_MPI_STS -1,-1,-1,-1

/**
 * Register (NCB) mpi_sts_w1s
 *
 * MPI Interrupt Set Register
 * This register sets interrupt bits.
 */
union cavm_mpi_sts_w1s
{
    uint64_t u;
    struct cavm_mpi_sts_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t mpi_intr              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MPI_STS[MPI_INTR]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t mpi_intr              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MPI_STS[MPI_INTR]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_sts_w1s_s cn; */
};
typedef union cavm_mpi_sts_w1s cavm_mpi_sts_w1s_t;

#define CAVM_MPI_STS_W1S CAVM_MPI_STS_W1S_FUNC()
static inline uint64_t CAVM_MPI_STS_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_STS_W1S_FUNC(void)
{
    return 0x804000001020ll;
}

#define typedef_CAVM_MPI_STS_W1S cavm_mpi_sts_w1s_t
#define bustype_CAVM_MPI_STS_W1S CSR_TYPE_NCB
#define basename_CAVM_MPI_STS_W1S "MPI_STS_W1S"
#define device_bar_CAVM_MPI_STS_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_MPI_STS_W1S 0
#define arguments_CAVM_MPI_STS_W1S -1,-1,-1,-1

/**
 * Register (NCB) mpi_tx
 *
 * MPI/SPI Transmit Register
 */
union cavm_mpi_tx
{
    uint64_t u;
    struct cavm_mpi_tx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_22_63        : 42;
        uint64_t csid                  : 2;  /**< [ 21: 20](WO) Which CS to assert for this transaction */
        uint64_t reserved_17_19        : 3;
        uint64_t leavecs               : 1;  /**< [ 16: 16](WO) Leave SPI_CSn_L asserted.
                                                                 0 = Deassert SPI_CSn_L after the transaction is done.
                                                                 1 = Leave SPI_CSn_L asserted after the transaction is done. */
        uint64_t reserved_13_15        : 3;
        uint64_t txnum                 : 5;  /**< [ 12:  8](WO) Number of bytes to transmit. */
        uint64_t reserved_5_7          : 3;
        uint64_t totnum                : 5;  /**< [  4:  0](WO) Total number of bytes to shift (transmit and receive). */
#else /* Word 0 - Little Endian */
        uint64_t totnum                : 5;  /**< [  4:  0](WO) Total number of bytes to shift (transmit and receive). */
        uint64_t reserved_5_7          : 3;
        uint64_t txnum                 : 5;  /**< [ 12:  8](WO) Number of bytes to transmit. */
        uint64_t reserved_13_15        : 3;
        uint64_t leavecs               : 1;  /**< [ 16: 16](WO) Leave SPI_CSn_L asserted.
                                                                 0 = Deassert SPI_CSn_L after the transaction is done.
                                                                 1 = Leave SPI_CSn_L asserted after the transaction is done. */
        uint64_t reserved_17_19        : 3;
        uint64_t csid                  : 2;  /**< [ 21: 20](WO) Which CS to assert for this transaction */
        uint64_t reserved_22_63        : 42;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_tx_s cn; */
};
typedef union cavm_mpi_tx cavm_mpi_tx_t;

#define CAVM_MPI_TX CAVM_MPI_TX_FUNC()
static inline uint64_t CAVM_MPI_TX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_TX_FUNC(void)
{
    return 0x804000001010ll;
}

#define typedef_CAVM_MPI_TX cavm_mpi_tx_t
#define bustype_CAVM_MPI_TX CSR_TYPE_NCB
#define basename_CAVM_MPI_TX "MPI_TX"
#define device_bar_CAVM_MPI_TX 0x0 /* PF_BAR0 */
#define busnum_CAVM_MPI_TX 0
#define arguments_CAVM_MPI_TX -1,-1,-1,-1

/**
 * Register (NCB) mpi_wide_dat
 *
 * MPI/SPI Wide Data Register
 */
union cavm_mpi_wide_dat
{
    uint64_t u;
    struct cavm_mpi_wide_dat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Data to transmit/receive. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Data to transmit/receive. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mpi_wide_dat_s cn; */
};
typedef union cavm_mpi_wide_dat cavm_mpi_wide_dat_t;

#define CAVM_MPI_WIDE_DAT CAVM_MPI_WIDE_DAT_FUNC()
static inline uint64_t CAVM_MPI_WIDE_DAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MPI_WIDE_DAT_FUNC(void)
{
    return 0x804000001040ll;
}

#define typedef_CAVM_MPI_WIDE_DAT cavm_mpi_wide_dat_t
#define bustype_CAVM_MPI_WIDE_DAT CSR_TYPE_NCB
#define basename_CAVM_MPI_WIDE_DAT "MPI_WIDE_DAT"
#define device_bar_CAVM_MPI_WIDE_DAT 0x0 /* PF_BAR0 */
#define busnum_CAVM_MPI_WIDE_DAT 0
#define arguments_CAVM_MPI_WIDE_DAT -1,-1,-1,-1

#endif /* __CAVM_CSRS_MPI_H__ */
