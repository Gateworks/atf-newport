#ifndef __CAVM_CSRS_MIO_EMM_H__
#define __CAVM_CSRS_MIO_EMM_H__
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
 * Cavium MIO_EMM.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration mio_emm_bar_e
 *
 * eMMC Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR0 (0x87e009000000ll)
#define CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR0_SIZE 0x800000ull
#define CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR4 (0x87e009f00000ll)
#define CAVM_MIO_EMM_BAR_E_MIO_EMM_PF_BAR4_SIZE 0x100000ull

/**
 * Enumeration mio_emm_int_vec_e
 *
 * eMMC MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define CAVM_MIO_EMM_INT_VEC_E_DMA_INT_DONE (8)
#define CAVM_MIO_EMM_INT_VEC_E_DMA_INT_FIFO (7)
#define CAVM_MIO_EMM_INT_VEC_E_EMM_BUF_DONE (0)
#define CAVM_MIO_EMM_INT_VEC_E_EMM_CMD_DONE (1)
#define CAVM_MIO_EMM_INT_VEC_E_EMM_CMD_ERR (3)
#define CAVM_MIO_EMM_INT_VEC_E_EMM_DMA_DONE (2)
#define CAVM_MIO_EMM_INT_VEC_E_EMM_DMA_ERR (4)
#define CAVM_MIO_EMM_INT_VEC_E_EMM_SWITCH_DONE (5)
#define CAVM_MIO_EMM_INT_VEC_E_EMM_SWITCH_ERR (6)

/**
 * Register (RSL) mio_emm_access_wdog
 *
 * eMMC Access Watchdog Register
 */
union cavm_mio_emm_access_wdog
{
    uint64_t u;
    struct cavm_mio_emm_access_wdog_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t clk_cnt               : 32; /**< [ 31:  0](R/W) Number of coprocessor-clocks to allow for a store operation to the device to complete
                                                                 before hardware will halt the operation.
                                                                 Hardware will inject an error on the next 512-byte block boundary.   The pending DMA
                                                                 operation can be resumed or terminated. A value of zero disables timer. */
#else /* Word 0 - Little Endian */
        uint64_t clk_cnt               : 32; /**< [ 31:  0](R/W) Number of coprocessor-clocks to allow for a store operation to the device to complete
                                                                 before hardware will halt the operation.
                                                                 Hardware will inject an error on the next 512-byte block boundary.   The pending DMA
                                                                 operation can be resumed or terminated. A value of zero disables timer. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_access_wdog_s cn; */
};
typedef union cavm_mio_emm_access_wdog cavm_mio_emm_access_wdog_t;

#define CAVM_MIO_EMM_ACCESS_WDOG CAVM_MIO_EMM_ACCESS_WDOG_FUNC()
static inline uint64_t CAVM_MIO_EMM_ACCESS_WDOG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_ACCESS_WDOG_FUNC(void)
{
    return 0x87e0090020f0ll;
}

#define typedef_CAVM_MIO_EMM_ACCESS_WDOG cavm_mio_emm_access_wdog_t
#define bustype_CAVM_MIO_EMM_ACCESS_WDOG CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_ACCESS_WDOG "MIO_EMM_ACCESS_WDOG"
#define device_bar_CAVM_MIO_EMM_ACCESS_WDOG 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_ACCESS_WDOG 0
#define arguments_CAVM_MIO_EMM_ACCESS_WDOG -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_buf_dat
 *
 * eMMC Data Buffer Access Register
 */
union cavm_mio_emm_buf_dat
{
    uint64_t u;
    struct cavm_mio_emm_buf_dat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](R/W/H) Direct access to the 1 KB data buffer memory. Address specified by MIO_EMM_BUF_IDX. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](R/W/H) Direct access to the 1 KB data buffer memory. Address specified by MIO_EMM_BUF_IDX. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_buf_dat_s cn; */
};
typedef union cavm_mio_emm_buf_dat cavm_mio_emm_buf_dat_t;

#define CAVM_MIO_EMM_BUF_DAT CAVM_MIO_EMM_BUF_DAT_FUNC()
static inline uint64_t CAVM_MIO_EMM_BUF_DAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_BUF_DAT_FUNC(void)
{
    return 0x87e0090020e8ll;
}

#define typedef_CAVM_MIO_EMM_BUF_DAT cavm_mio_emm_buf_dat_t
#define bustype_CAVM_MIO_EMM_BUF_DAT CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_BUF_DAT "MIO_EMM_BUF_DAT"
#define device_bar_CAVM_MIO_EMM_BUF_DAT 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_BUF_DAT 0
#define arguments_CAVM_MIO_EMM_BUF_DAT -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_buf_idx
 *
 * eMMC Data Buffer Address Register
 */
union cavm_mio_emm_buf_idx
{
    uint64_t u;
    struct cavm_mio_emm_buf_idx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t inc                   : 1;  /**< [ 16: 16](R/W) Automatically advance [BUF_NUM]/[OFFSET] after each access to
                                                                 MIO_EMM_BUF_DAT. Wraps after the last offset of the last data buffer. */
        uint64_t reserved_7_15         : 9;
        uint64_t buf_num               : 1;  /**< [  6:  6](R/W/H) Specify the data buffer for the next access to MIO_EMM_BUF_DAT. */
        uint64_t offset                : 6;  /**< [  5:  0](R/W/H) Specify the 8B data buffer offset for the next access to MIO_EMM_BUF_DAT. */
#else /* Word 0 - Little Endian */
        uint64_t offset                : 6;  /**< [  5:  0](R/W/H) Specify the 8B data buffer offset for the next access to MIO_EMM_BUF_DAT. */
        uint64_t buf_num               : 1;  /**< [  6:  6](R/W/H) Specify the data buffer for the next access to MIO_EMM_BUF_DAT. */
        uint64_t reserved_7_15         : 9;
        uint64_t inc                   : 1;  /**< [ 16: 16](R/W) Automatically advance [BUF_NUM]/[OFFSET] after each access to
                                                                 MIO_EMM_BUF_DAT. Wraps after the last offset of the last data buffer. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_buf_idx_s cn; */
};
typedef union cavm_mio_emm_buf_idx cavm_mio_emm_buf_idx_t;

#define CAVM_MIO_EMM_BUF_IDX CAVM_MIO_EMM_BUF_IDX_FUNC()
static inline uint64_t CAVM_MIO_EMM_BUF_IDX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_BUF_IDX_FUNC(void)
{
    return 0x87e0090020e0ll;
}

#define typedef_CAVM_MIO_EMM_BUF_IDX cavm_mio_emm_buf_idx_t
#define bustype_CAVM_MIO_EMM_BUF_IDX CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_BUF_IDX "MIO_EMM_BUF_IDX"
#define device_bar_CAVM_MIO_EMM_BUF_IDX 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_BUF_IDX 0
#define arguments_CAVM_MIO_EMM_BUF_IDX -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_cfg
 *
 * eMMC Configuration Register
 */
union cavm_mio_emm_cfg
{
    uint64_t u;
    struct cavm_mio_emm_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t bus_ena               : 4;  /**< [  3:  0](R/W) eMMC bus enable mask.

                                                                 Setting bits 0..2 enable the corresponding EMMC bus by allowing EMMC_CMD[BUS_ENA]
                                                                 operation. Bit 3 is reserved.

                                                                 Clearing all bits of this field will reset the other MIO_EMM_* registers.
                                                                 To ensure a proper reset the BUS_ENA bits should be cleared for a minimum of 2 EMMC_CLK
                                                                 periods.  This period be determined by waiting twice the number of coprocessor clocks
                                                                 specified in MIO_EMM_MODE0[CLK_HI] and MIO_EMM_MODE0[CLK_LO].

                                                                 Setting one or more bits will enable EMMC_CLK operation. */
#else /* Word 0 - Little Endian */
        uint64_t bus_ena               : 4;  /**< [  3:  0](R/W) eMMC bus enable mask.

                                                                 Setting bits 0..2 enable the corresponding EMMC bus by allowing EMMC_CMD[BUS_ENA]
                                                                 operation. Bit 3 is reserved.

                                                                 Clearing all bits of this field will reset the other MIO_EMM_* registers.
                                                                 To ensure a proper reset the BUS_ENA bits should be cleared for a minimum of 2 EMMC_CLK
                                                                 periods.  This period be determined by waiting twice the number of coprocessor clocks
                                                                 specified in MIO_EMM_MODE0[CLK_HI] and MIO_EMM_MODE0[CLK_LO].

                                                                 Setting one or more bits will enable EMMC_CLK operation. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_cfg_s cn; */
};
typedef union cavm_mio_emm_cfg cavm_mio_emm_cfg_t;

#define CAVM_MIO_EMM_CFG CAVM_MIO_EMM_CFG_FUNC()
static inline uint64_t CAVM_MIO_EMM_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_CFG_FUNC(void)
{
    return 0x87e009002000ll;
}

#define typedef_CAVM_MIO_EMM_CFG cavm_mio_emm_cfg_t
#define bustype_CAVM_MIO_EMM_CFG CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_CFG "MIO_EMM_CFG"
#define device_bar_CAVM_MIO_EMM_CFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_CFG 0
#define arguments_CAVM_MIO_EMM_CFG -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_cmd
 *
 * eMMC Command Register
 */
union cavm_mio_emm_cmd
{
    uint64_t u;
    struct cavm_mio_emm_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t skip_busy             : 1;  /**< [ 62: 62](R/W) Controls when command is completed.
                                                                 0 = Command doesn't complete until card has dropped the BUSY signal.
                                                                 1 = Complete command regardless of the BUSY signal. Status of signal can be read in
                                                                 MIO_EMM_RSP_STS[RSP_BUSYBIT]. */
        uint64_t bus_id                : 2;  /**< [ 61: 60](R/W) Specify the eMMC bus */
        uint64_t cmd_val               : 1;  /**< [ 59: 59](R/W/H) Request valid. Software writes this bit to a 1. Hardware clears it when the operation completes. */
        uint64_t reserved_56_58        : 3;
        uint64_t dbuf                  : 1;  /**< [ 55: 55](R/W) Specify the data buffer to be used for a block transfer. */
        uint64_t offset                : 6;  /**< [ 54: 49](R/W/H) Debug only. Specify the number of 8-byte transfers used in the command. Value is
                                                                 64-OFFSET. The block transfer still starts at the first byte in the 512 B data buffer.
                                                                 Software must ensure CMD16 has updated the card block length. */
        uint64_t reserved_43_48        : 6;
        uint64_t ctype_xor             : 2;  /**< [ 42: 41](R/W) Command type override; typically zero. Value is XOR'd with the default command type. See
                                                                 Command and Response Types for command types per command index. Types are:
                                                                 0x0 = No data.
                                                                 0x1 = Read data into Dbuf.
                                                                 0x2 = Write data from Dbuf.
                                                                 0x3 = Reserved. */
        uint64_t rtype_xor             : 3;  /**< [ 40: 38](R/W) Response type override; typically zero. Value is XOR'd with default response type. See
                                                                 Command and Response Types for response types per command index. Types are:
                                                                 0x0 = No Response.
                                                                 0x1 = R1, 48 bits.
                                                                 0x2 = R2, 136 bits.
                                                                 0x3 = R3, 48 bits.
                                                                 0x4 = R4, 48 bits.
                                                                 0x5 = R5, 48 bits.
                                                                 0x6, 0x7 = Reserved. */
        uint64_t cmd_idx               : 6;  /**< [ 37: 32](R/W/H) eMMC command */
        uint64_t arg                   : 32; /**< [ 31:  0](R/W/H) eMMC command argument */
#else /* Word 0 - Little Endian */
        uint64_t arg                   : 32; /**< [ 31:  0](R/W/H) eMMC command argument */
        uint64_t cmd_idx               : 6;  /**< [ 37: 32](R/W/H) eMMC command */
        uint64_t rtype_xor             : 3;  /**< [ 40: 38](R/W) Response type override; typically zero. Value is XOR'd with default response type. See
                                                                 Command and Response Types for response types per command index. Types are:
                                                                 0x0 = No Response.
                                                                 0x1 = R1, 48 bits.
                                                                 0x2 = R2, 136 bits.
                                                                 0x3 = R3, 48 bits.
                                                                 0x4 = R4, 48 bits.
                                                                 0x5 = R5, 48 bits.
                                                                 0x6, 0x7 = Reserved. */
        uint64_t ctype_xor             : 2;  /**< [ 42: 41](R/W) Command type override; typically zero. Value is XOR'd with the default command type. See
                                                                 Command and Response Types for command types per command index. Types are:
                                                                 0x0 = No data.
                                                                 0x1 = Read data into Dbuf.
                                                                 0x2 = Write data from Dbuf.
                                                                 0x3 = Reserved. */
        uint64_t reserved_43_48        : 6;
        uint64_t offset                : 6;  /**< [ 54: 49](R/W/H) Debug only. Specify the number of 8-byte transfers used in the command. Value is
                                                                 64-OFFSET. The block transfer still starts at the first byte in the 512 B data buffer.
                                                                 Software must ensure CMD16 has updated the card block length. */
        uint64_t dbuf                  : 1;  /**< [ 55: 55](R/W) Specify the data buffer to be used for a block transfer. */
        uint64_t reserved_56_58        : 3;
        uint64_t cmd_val               : 1;  /**< [ 59: 59](R/W/H) Request valid. Software writes this bit to a 1. Hardware clears it when the operation completes. */
        uint64_t bus_id                : 2;  /**< [ 61: 60](R/W) Specify the eMMC bus */
        uint64_t skip_busy             : 1;  /**< [ 62: 62](R/W) Controls when command is completed.
                                                                 0 = Command doesn't complete until card has dropped the BUSY signal.
                                                                 1 = Complete command regardless of the BUSY signal. Status of signal can be read in
                                                                 MIO_EMM_RSP_STS[RSP_BUSYBIT]. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_cmd_s cn; */
};
typedef union cavm_mio_emm_cmd cavm_mio_emm_cmd_t;

#define CAVM_MIO_EMM_CMD CAVM_MIO_EMM_CMD_FUNC()
static inline uint64_t CAVM_MIO_EMM_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_CMD_FUNC(void)
{
    return 0x87e009002058ll;
}

#define typedef_CAVM_MIO_EMM_CMD cavm_mio_emm_cmd_t
#define bustype_CAVM_MIO_EMM_CMD CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_CMD "MIO_EMM_CMD"
#define device_bar_CAVM_MIO_EMM_CMD 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_CMD 0
#define arguments_CAVM_MIO_EMM_CMD -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_comp
 *
 * eMMC Compensation Register
 */
union cavm_mio_emm_comp
{
    uint64_t u;
    struct cavm_mio_emm_comp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t pctl                  : 3;  /**< [ 10:  8](R/W) eMMC bus driver PCTL. Typical values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
        uint64_t reserved_3_7          : 5;
        uint64_t nctl                  : 3;  /**< [  2:  0](R/W) eMMC bus driver NCTL. Typical values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
#else /* Word 0 - Little Endian */
        uint64_t nctl                  : 3;  /**< [  2:  0](R/W) eMMC bus driver NCTL. Typical values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
        uint64_t reserved_3_7          : 5;
        uint64_t pctl                  : 3;  /**< [ 10:  8](R/W) eMMC bus driver PCTL. Typical values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_comp_s cn; */
};
typedef union cavm_mio_emm_comp cavm_mio_emm_comp_t;

#define CAVM_MIO_EMM_COMP CAVM_MIO_EMM_COMP_FUNC()
static inline uint64_t CAVM_MIO_EMM_COMP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_COMP_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e009002040ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e009002040ll;
    __cavm_csr_fatal("MIO_EMM_COMP", 0, 0, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MIO_EMM_COMP cavm_mio_emm_comp_t
#define bustype_CAVM_MIO_EMM_COMP CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_COMP "MIO_EMM_COMP"
#define device_bar_CAVM_MIO_EMM_COMP 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_COMP 0
#define arguments_CAVM_MIO_EMM_COMP -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma
 *
 * eMMC External DMA Configuration Register
 */
union cavm_mio_emm_dma
{
    uint64_t u;
    struct cavm_mio_emm_dma_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t skip_busy             : 1;  /**< [ 62: 62](R/W) Controls when DMA is completed.
                                                                 0 = DMA doesn't complete until card has dropped the BUSY signal.
                                                                 1 = Complete DMA after last transfer regardless of the BUSY signal. Status of signal can
                                                                 be read in MIO_EMM_RSP_STS[RSP_BUSYBIT]. */
        uint64_t bus_id                : 2;  /**< [ 61: 60](R/W) Specify the eMMC bus */
        uint64_t dma_val               : 1;  /**< [ 59: 59](R/W/H) Software writes this bit to a 1 to indicate that hardware should perform the DMA transfer.
                                                                 Hardware clears this bit when the DMA operation completes or is terminated. */
        uint64_t sector                : 1;  /**< [ 58: 58](R/W/H) Specify CARD_ADDR and eMMC are using sector (512 B) addressing. */
        uint64_t dat_null              : 1;  /**< [ 57: 57](R/W) Do not perform any eMMC commands. A DMA read returns all 0s. A DMA write tosses the data.
                                                                 In the case of a failure, this can be used to unwind the DMA engine. */
        uint64_t thres                 : 6;  /**< [ 56: 51](R/W) Number of 8-byte blocks of data that must exist in the DBUF before starting the 512-byte
                                                                 block transfer. Zero indicates to wait for the entire block. */
        uint64_t rel_wr                : 1;  /**< [ 50: 50](R/W) Set the reliable write parameter when performing CMD23 (SET_BLOCK_COUNT) for a multiple block. */
        uint64_t rw                    : 1;  /**< [ 49: 49](R/W) Read/write bit (0 = read, 1 = write). */
        uint64_t multi                 : 1;  /**< [ 48: 48](R/W) Perform operation using a multiple block command instead of a series of single block commands. */
        uint64_t block_cnt             : 16; /**< [ 47: 32](R/W/H) Number of blocks to read/write. Hardware decrements the block count after each successful
                                                                 block transfer. */
        uint64_t card_addr             : 32; /**< [ 31:  0](R/W/H) Data address for media <= 2 GB is a 32-bit byte address, and data address for media > 2 GB
                                                                 is a 32-bit sector (512 B) address. Hardware advances the card address after each
                                                                 successful block transfer by 512 for byte addressing and by 1 for sector addressing. */
#else /* Word 0 - Little Endian */
        uint64_t card_addr             : 32; /**< [ 31:  0](R/W/H) Data address for media <= 2 GB is a 32-bit byte address, and data address for media > 2 GB
                                                                 is a 32-bit sector (512 B) address. Hardware advances the card address after each
                                                                 successful block transfer by 512 for byte addressing and by 1 for sector addressing. */
        uint64_t block_cnt             : 16; /**< [ 47: 32](R/W/H) Number of blocks to read/write. Hardware decrements the block count after each successful
                                                                 block transfer. */
        uint64_t multi                 : 1;  /**< [ 48: 48](R/W) Perform operation using a multiple block command instead of a series of single block commands. */
        uint64_t rw                    : 1;  /**< [ 49: 49](R/W) Read/write bit (0 = read, 1 = write). */
        uint64_t rel_wr                : 1;  /**< [ 50: 50](R/W) Set the reliable write parameter when performing CMD23 (SET_BLOCK_COUNT) for a multiple block. */
        uint64_t thres                 : 6;  /**< [ 56: 51](R/W) Number of 8-byte blocks of data that must exist in the DBUF before starting the 512-byte
                                                                 block transfer. Zero indicates to wait for the entire block. */
        uint64_t dat_null              : 1;  /**< [ 57: 57](R/W) Do not perform any eMMC commands. A DMA read returns all 0s. A DMA write tosses the data.
                                                                 In the case of a failure, this can be used to unwind the DMA engine. */
        uint64_t sector                : 1;  /**< [ 58: 58](R/W/H) Specify CARD_ADDR and eMMC are using sector (512 B) addressing. */
        uint64_t dma_val               : 1;  /**< [ 59: 59](R/W/H) Software writes this bit to a 1 to indicate that hardware should perform the DMA transfer.
                                                                 Hardware clears this bit when the DMA operation completes or is terminated. */
        uint64_t bus_id                : 2;  /**< [ 61: 60](R/W) Specify the eMMC bus */
        uint64_t skip_busy             : 1;  /**< [ 62: 62](R/W) Controls when DMA is completed.
                                                                 0 = DMA doesn't complete until card has dropped the BUSY signal.
                                                                 1 = Complete DMA after last transfer regardless of the BUSY signal. Status of signal can
                                                                 be read in MIO_EMM_RSP_STS[RSP_BUSYBIT]. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_dma_s cn; */
};
typedef union cavm_mio_emm_dma cavm_mio_emm_dma_t;

#define CAVM_MIO_EMM_DMA CAVM_MIO_EMM_DMA_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_FUNC(void)
{
    return 0x87e009002050ll;
}

#define typedef_CAVM_MIO_EMM_DMA cavm_mio_emm_dma_t
#define bustype_CAVM_MIO_EMM_DMA CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA "MIO_EMM_DMA"
#define device_bar_CAVM_MIO_EMM_DMA 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA 0
#define arguments_CAVM_MIO_EMM_DMA -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma_adr
 *
 * eMMC DMA Address Register
 * This register sets the address for eMMC/SD flash transfers to/from memory. Sixty-four-bit
 * operations must be used to access this register. This register is updated by the DMA
 * hardware and can be reloaded by the values placed in the MIO_EMM_DMA_FIFO_ADR.
 */
union cavm_mio_emm_dma_adr
{
    uint64_t u;
    struct cavm_mio_emm_dma_adr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t adr                   : 49; /**< [ 48:  0](R/W/H) DMA engine IOVA. Must be 64-bit aligned. */
#else /* Word 0 - Little Endian */
        uint64_t adr                   : 49; /**< [ 48:  0](R/W/H) DMA engine IOVA. Must be 64-bit aligned. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_dma_adr_s cn; */
};
typedef union cavm_mio_emm_dma_adr cavm_mio_emm_dma_adr_t;

#define CAVM_MIO_EMM_DMA_ADR CAVM_MIO_EMM_DMA_ADR_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_ADR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_ADR_FUNC(void)
{
    return 0x87e009000188ll;
}

#define typedef_CAVM_MIO_EMM_DMA_ADR cavm_mio_emm_dma_adr_t
#define bustype_CAVM_MIO_EMM_DMA_ADR CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA_ADR "MIO_EMM_DMA_ADR"
#define device_bar_CAVM_MIO_EMM_DMA_ADR 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA_ADR 0
#define arguments_CAVM_MIO_EMM_DMA_ADR -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma_cfg
 *
 * eMMC DMA Configuration Register
 * This register controls the internal DMA engine used with the eMMC/SD flash controller. Sixty-
 * four-bit operations must be used to access this register. This register is updated by the
 * hardware DMA engine and can also be reloaded by writes to the MIO_EMM_DMA_FIFO_CMD register.
 */
union cavm_mio_emm_dma_cfg
{
    uint64_t u;
    struct cavm_mio_emm_dma_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t en                    : 1;  /**< [ 63: 63](R/W/H) DMA engine enable. */
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W/H) DMA engine R/W bit: 0 = read, 1 = write. */
        uint64_t clr                   : 1;  /**< [ 61: 61](R/W/H) DMA engine abort. When set to 1, DMA is aborted and EN is cleared on completion. */
        uint64_t reserved_60           : 1;
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W/H) DMA engine 32-bit swap. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W/H) DMA engine enable 16-bit swap. */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W/H) DMA engine enable 8-bit swap. */
        uint64_t endian                : 1;  /**< [ 56: 56](R/W/H) DMA engine endian mode: 0 = big-endian, 1 = little-endian. */
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine size. Specified in the number of 64-bit transfers (encoded in -1 notation). For
                                                                 example, to transfer 512 bytes, SIZE = 64 - 1 = 63. */
        uint64_t reserved_0_35         : 36;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_35         : 36;
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine size. Specified in the number of 64-bit transfers (encoded in -1 notation). For
                                                                 example, to transfer 512 bytes, SIZE = 64 - 1 = 63. */
        uint64_t endian                : 1;  /**< [ 56: 56](R/W/H) DMA engine endian mode: 0 = big-endian, 1 = little-endian. */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W/H) DMA engine enable 8-bit swap. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W/H) DMA engine enable 16-bit swap. */
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W/H) DMA engine 32-bit swap. */
        uint64_t reserved_60           : 1;
        uint64_t clr                   : 1;  /**< [ 61: 61](R/W/H) DMA engine abort. When set to 1, DMA is aborted and EN is cleared on completion. */
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W/H) DMA engine R/W bit: 0 = read, 1 = write. */
        uint64_t en                    : 1;  /**< [ 63: 63](R/W/H) DMA engine enable. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_dma_cfg_s cn; */
};
typedef union cavm_mio_emm_dma_cfg cavm_mio_emm_dma_cfg_t;

#define CAVM_MIO_EMM_DMA_CFG CAVM_MIO_EMM_DMA_CFG_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_CFG_FUNC(void)
{
    return 0x87e009000180ll;
}

#define typedef_CAVM_MIO_EMM_DMA_CFG cavm_mio_emm_dma_cfg_t
#define bustype_CAVM_MIO_EMM_DMA_CFG CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA_CFG "MIO_EMM_DMA_CFG"
#define device_bar_CAVM_MIO_EMM_DMA_CFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA_CFG 0
#define arguments_CAVM_MIO_EMM_DMA_CFG -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma_fifo_adr
 *
 * eMMC Internal DMA FIFO Address Register
 * This register specifies the internal address that is loaded into the eMMC internal DMA FIFO.
 * The FIFO is used to queue up operations for the MIO_EMM_DMA_CFG/MIO_EMM_DMA_ADR when the DMA
 * completes successfully.
 */
union cavm_mio_emm_dma_fifo_adr
{
    uint64_t u;
    struct cavm_mio_emm_dma_fifo_adr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t adr                   : 46; /**< [ 48:  3](R/W) DMA engine IOVA. Must be 64-bit aligned. */
        uint64_t reserved_0_2          : 3;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_2          : 3;
        uint64_t adr                   : 46; /**< [ 48:  3](R/W) DMA engine IOVA. Must be 64-bit aligned. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_dma_fifo_adr_s cn; */
};
typedef union cavm_mio_emm_dma_fifo_adr cavm_mio_emm_dma_fifo_adr_t;

#define CAVM_MIO_EMM_DMA_FIFO_ADR CAVM_MIO_EMM_DMA_FIFO_ADR_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_FIFO_ADR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_FIFO_ADR_FUNC(void)
{
    return 0x87e009000170ll;
}

#define typedef_CAVM_MIO_EMM_DMA_FIFO_ADR cavm_mio_emm_dma_fifo_adr_t
#define bustype_CAVM_MIO_EMM_DMA_FIFO_ADR CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA_FIFO_ADR "MIO_EMM_DMA_FIFO_ADR"
#define device_bar_CAVM_MIO_EMM_DMA_FIFO_ADR 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA_FIFO_ADR 0
#define arguments_CAVM_MIO_EMM_DMA_FIFO_ADR -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma_fifo_cfg
 *
 * eMMC Internal DMA FIFO Configuration Register
 * This register controls DMA FIFO Operations.
 */
union cavm_mio_emm_dma_fifo_cfg
{
    uint64_t u;
    struct cavm_mio_emm_dma_fifo_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t clr                   : 1;  /**< [ 16: 16](R/W) DMA FIFO Clear. When set erases all commands in the DMA FIFO. Must be zero for normal operation. */
        uint64_t reserved_13_15        : 3;
        uint64_t int_lvl               : 5;  /**< [ 12:  8](R/W) Interrupt threshold indicating the number of entries remaining in the
                                                                 DMA FIFO.  An interrupt occurs if the FIFO is read at the level specified.
                                                                 A value of 0 disables the interrupt.  A value of 17 or greater will cause an
                                                                 interrupt only if the FIFO is overflowed.
                                                                 See MIO_EMM_DMA_INT[FIFO]. */
        uint64_t reserved_5_7          : 3;
        uint64_t count                 : 5;  /**< [  4:  0](RO/H) Number of entries in the DMA FIFO. This count is incremented by writes to the
                                                                 MIO_EMM_DMA_FIFO_CMD register and decremented each time the internal DMA engine completes
                                                                 the previous command successfully.

                                                                 Up to 16 entries can be placed in the FIFO. Entries written to a full FIFO will
                                                                 potentially corrupt existing entries.  Care must be taken by software to insure
                                                                 that this condition does not occur. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 5;  /**< [  4:  0](RO/H) Number of entries in the DMA FIFO. This count is incremented by writes to the
                                                                 MIO_EMM_DMA_FIFO_CMD register and decremented each time the internal DMA engine completes
                                                                 the previous command successfully.

                                                                 Up to 16 entries can be placed in the FIFO. Entries written to a full FIFO will
                                                                 potentially corrupt existing entries.  Care must be taken by software to insure
                                                                 that this condition does not occur. */
        uint64_t reserved_5_7          : 3;
        uint64_t int_lvl               : 5;  /**< [ 12:  8](R/W) Interrupt threshold indicating the number of entries remaining in the
                                                                 DMA FIFO.  An interrupt occurs if the FIFO is read at the level specified.
                                                                 A value of 0 disables the interrupt.  A value of 17 or greater will cause an
                                                                 interrupt only if the FIFO is overflowed.
                                                                 See MIO_EMM_DMA_INT[FIFO]. */
        uint64_t reserved_13_15        : 3;
        uint64_t clr                   : 1;  /**< [ 16: 16](R/W) DMA FIFO Clear. When set erases all commands in the DMA FIFO. Must be zero for normal operation. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_dma_fifo_cfg_s cn; */
};
typedef union cavm_mio_emm_dma_fifo_cfg cavm_mio_emm_dma_fifo_cfg_t;

#define CAVM_MIO_EMM_DMA_FIFO_CFG CAVM_MIO_EMM_DMA_FIFO_CFG_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_FIFO_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_FIFO_CFG_FUNC(void)
{
    return 0x87e009000160ll;
}

#define typedef_CAVM_MIO_EMM_DMA_FIFO_CFG cavm_mio_emm_dma_fifo_cfg_t
#define bustype_CAVM_MIO_EMM_DMA_FIFO_CFG CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA_FIFO_CFG "MIO_EMM_DMA_FIFO_CFG"
#define device_bar_CAVM_MIO_EMM_DMA_FIFO_CFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA_FIFO_CFG 0
#define arguments_CAVM_MIO_EMM_DMA_FIFO_CFG -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma_fifo_cmd
 *
 * eMMC Internal DMA FIFO Command Register
 * This register specifies a command that is loaded into the eMMC internal DMA FIFO.  The FIFO is
 * used to queue up operations for the MIO_EMM_DMA_CFG/MIO_EMM_DMA_ADR when the DMA completes
 * successfully. Writes to this register store both the MIO_EMM_DMA_FIFO_CMD and the
 * MIO_EMM_DMA_FIFO_ADR contents into the FIFO and increment the MIO_EMM_DMA_FIFO_CFG[COUNT]
 * field.
 *
 * Note: This register has a similar format to the MIO_EMM_DMA_CFG register with the exception
 * that the EN and CLR fields are absent. These are supported in the MIO_EMM_DMA_FIFO_CFG.
 */
union cavm_mio_emm_dma_fifo_cmd
{
    uint64_t u;
    struct cavm_mio_emm_dma_fifo_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W) DMA engine R/W bit: 0 = read, 1 = write. */
        uint64_t reserved_61           : 1;
        uint64_t intdis                : 1;  /**< [ 60: 60](R/W) DMA command interrupt disable. When set, the DMA command being submitted will
                                                                 not generate a MIO_EMM_DMA_INT[DONE] interrupt when it completes. When cleared
                                                                 the command will generate the interrupt.

                                                                 For example, this field can be set for all the DMA commands submitted to the DMA
                                                                 FIFO in the case of a write to the eMMC device because the MIO_EMM_INT[DMA_DONE]
                                                                 interrupt would signify the end of the operation. It could be cleared on the last
                                                                 DMA command being submitted to the DMA FIFO and the MIO_EMM_DMA_INT[DONE] would
                                                                 occur when the read data from the eMMC device was available in local memory. */
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W) DMA engine 32-bit swap enable.  See [ENDIAN]. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W) DMA engine 16-bit swap enable.  See [ENDIAN]. */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W) DMA engine 8-bit swap enable.  See [ENDIAN]. */
        uint64_t endian                : 1;  /**< [ 56: 56](R/W) DMA engine endian mode: 0 = little-endian, 1 = big-endian.
                                                                 Using 0..7 to identify bytes.
                                                                 <pre>
                                                                 [SWAP32] [SWAP16] [SWAP8] [ENDIAN]  Result
                                                                    0        0        0      0       7 6 5 4 3 2 1 0
                                                                    0        0        1      0       6 7 4 5 2 3 0 1
                                                                    0        1        0      0       5 4 7 6 1 0 3 2
                                                                    1        0        0      0       3 2 1 0 7 6 5 4
                                                                    0        0        0      1       0 1 2 3 4 5 6 7
                                                                    0        0        1      1       1 0 3 2 5 4 7 6
                                                                    0        1        0      1       2 3 0 1 6 7 4 5
                                                                    1        0        0      1       4 5 6 7 0 1 2 3
                                                                 </pre> */
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine size. Specified in the number of 64-bit transfers (encoded in -1 notation). For
                                                                 example, to transfer 512 bytes, SIZE = 64 - 1 = 63. */
        uint64_t reserved_0_35         : 36;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_35         : 36;
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine size. Specified in the number of 64-bit transfers (encoded in -1 notation). For
                                                                 example, to transfer 512 bytes, SIZE = 64 - 1 = 63. */
        uint64_t endian                : 1;  /**< [ 56: 56](R/W) DMA engine endian mode: 0 = little-endian, 1 = big-endian.
                                                                 Using 0..7 to identify bytes.
                                                                 <pre>
                                                                 [SWAP32] [SWAP16] [SWAP8] [ENDIAN]  Result
                                                                    0        0        0      0       7 6 5 4 3 2 1 0
                                                                    0        0        1      0       6 7 4 5 2 3 0 1
                                                                    0        1        0      0       5 4 7 6 1 0 3 2
                                                                    1        0        0      0       3 2 1 0 7 6 5 4
                                                                    0        0        0      1       0 1 2 3 4 5 6 7
                                                                    0        0        1      1       1 0 3 2 5 4 7 6
                                                                    0        1        0      1       2 3 0 1 6 7 4 5
                                                                    1        0        0      1       4 5 6 7 0 1 2 3
                                                                 </pre> */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W) DMA engine 8-bit swap enable.  See [ENDIAN]. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W) DMA engine 16-bit swap enable.  See [ENDIAN]. */
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W) DMA engine 32-bit swap enable.  See [ENDIAN]. */
        uint64_t intdis                : 1;  /**< [ 60: 60](R/W) DMA command interrupt disable. When set, the DMA command being submitted will
                                                                 not generate a MIO_EMM_DMA_INT[DONE] interrupt when it completes. When cleared
                                                                 the command will generate the interrupt.

                                                                 For example, this field can be set for all the DMA commands submitted to the DMA
                                                                 FIFO in the case of a write to the eMMC device because the MIO_EMM_INT[DMA_DONE]
                                                                 interrupt would signify the end of the operation. It could be cleared on the last
                                                                 DMA command being submitted to the DMA FIFO and the MIO_EMM_DMA_INT[DONE] would
                                                                 occur when the read data from the eMMC device was available in local memory. */
        uint64_t reserved_61           : 1;
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W) DMA engine R/W bit: 0 = read, 1 = write. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } s;
    struct cavm_mio_emm_dma_fifo_cmd_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_63           : 1;
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W) DMA engine R/W bit: 0 = read, 1 = write. */
        uint64_t reserved_61           : 1;
        uint64_t reserved_60           : 1;
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W) DMA engine 32-bit swap enable.  See [ENDIAN]. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W) DMA engine 16-bit swap enable.  See [ENDIAN]. */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W) DMA engine 8-bit swap enable.  See [ENDIAN]. */
        uint64_t endian                : 1;  /**< [ 56: 56](R/W) DMA engine endian mode: 0 = little-endian, 1 = big-endian.
                                                                 Using 0..7 to identify bytes.
                                                                 <pre>
                                                                 [SWAP32] [SWAP16] [SWAP8] [ENDIAN]  Result
                                                                    0        0        0      0       7 6 5 4 3 2 1 0
                                                                    0        0        1      0       6 7 4 5 2 3 0 1
                                                                    0        1        0      0       5 4 7 6 1 0 3 2
                                                                    1        0        0      0       3 2 1 0 7 6 5 4
                                                                    0        0        0      1       0 1 2 3 4 5 6 7
                                                                    0        0        1      1       1 0 3 2 5 4 7 6
                                                                    0        1        0      1       2 3 0 1 6 7 4 5
                                                                    1        0        0      1       4 5 6 7 0 1 2 3
                                                                 </pre> */
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine size. Specified in the number of 64-bit transfers (encoded in -1 notation). For
                                                                 example, to transfer 512 bytes, SIZE = 64 - 1 = 63. */
        uint64_t reserved_0_35         : 36;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_35         : 36;
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine size. Specified in the number of 64-bit transfers (encoded in -1 notation). For
                                                                 example, to transfer 512 bytes, SIZE = 64 - 1 = 63. */
        uint64_t endian                : 1;  /**< [ 56: 56](R/W) DMA engine endian mode: 0 = little-endian, 1 = big-endian.
                                                                 Using 0..7 to identify bytes.
                                                                 <pre>
                                                                 [SWAP32] [SWAP16] [SWAP8] [ENDIAN]  Result
                                                                    0        0        0      0       7 6 5 4 3 2 1 0
                                                                    0        0        1      0       6 7 4 5 2 3 0 1
                                                                    0        1        0      0       5 4 7 6 1 0 3 2
                                                                    1        0        0      0       3 2 1 0 7 6 5 4
                                                                    0        0        0      1       0 1 2 3 4 5 6 7
                                                                    0        0        1      1       1 0 3 2 5 4 7 6
                                                                    0        1        0      1       2 3 0 1 6 7 4 5
                                                                    1        0        0      1       4 5 6 7 0 1 2 3
                                                                 </pre> */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W) DMA engine 8-bit swap enable.  See [ENDIAN]. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W) DMA engine 16-bit swap enable.  See [ENDIAN]. */
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W) DMA engine 32-bit swap enable.  See [ENDIAN]. */
        uint64_t reserved_60           : 1;
        uint64_t reserved_61           : 1;
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W) DMA engine R/W bit: 0 = read, 1 = write. */
        uint64_t reserved_63           : 1;
#endif /* Word 0 - End */
    } cn88xxp1;
    /* struct cavm_mio_emm_dma_fifo_cmd_s cn81xx; */
    /* struct cavm_mio_emm_dma_fifo_cmd_s cn83xx; */
    /* struct cavm_mio_emm_dma_fifo_cmd_s cn88xxp2; */
};
typedef union cavm_mio_emm_dma_fifo_cmd cavm_mio_emm_dma_fifo_cmd_t;

#define CAVM_MIO_EMM_DMA_FIFO_CMD CAVM_MIO_EMM_DMA_FIFO_CMD_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_FIFO_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_FIFO_CMD_FUNC(void)
{
    return 0x87e009000178ll;
}

#define typedef_CAVM_MIO_EMM_DMA_FIFO_CMD cavm_mio_emm_dma_fifo_cmd_t
#define bustype_CAVM_MIO_EMM_DMA_FIFO_CMD CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA_FIFO_CMD "MIO_EMM_DMA_FIFO_CMD"
#define device_bar_CAVM_MIO_EMM_DMA_FIFO_CMD 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA_FIFO_CMD 0
#define arguments_CAVM_MIO_EMM_DMA_FIFO_CMD -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma_int
 *
 * eMMC DMA Interrupt Register
 * Sixty-four-bit operations must be used to access this register.
 */
union cavm_mio_emm_dma_int
{
    uint64_t u;
    struct cavm_mio_emm_dma_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t fifo                  : 1;  /**< [  1:  1](R/W1C/H) Internal DMA FIFO has dropped to level specified by MIO_EMM_DMA_FIFO_CFG[INT_LVL]. */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Internal DMA engine request completion interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Internal DMA engine request completion interrupt. */
        uint64_t fifo                  : 1;  /**< [  1:  1](R/W1C/H) Internal DMA FIFO has dropped to level specified by MIO_EMM_DMA_FIFO_CFG[INT_LVL]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_dma_int_s cn; */
};
typedef union cavm_mio_emm_dma_int cavm_mio_emm_dma_int_t;

#define CAVM_MIO_EMM_DMA_INT CAVM_MIO_EMM_DMA_INT_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_INT_FUNC(void)
{
    return 0x87e009000190ll;
}

#define typedef_CAVM_MIO_EMM_DMA_INT cavm_mio_emm_dma_int_t
#define bustype_CAVM_MIO_EMM_DMA_INT CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA_INT "MIO_EMM_DMA_INT"
#define device_bar_CAVM_MIO_EMM_DMA_INT 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA_INT 0
#define arguments_CAVM_MIO_EMM_DMA_INT -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma_int_ena_w1c
 *
 * eMMC DMA Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_mio_emm_dma_int_ena_w1c
{
    uint64_t u;
    struct cavm_mio_emm_dma_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t fifo                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MIO_EMM_DMA_INT[FIFO]. */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MIO_EMM_DMA_INT[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MIO_EMM_DMA_INT[DONE]. */
        uint64_t fifo                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MIO_EMM_DMA_INT[FIFO]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_dma_int_ena_w1c_s cn; */
};
typedef union cavm_mio_emm_dma_int_ena_w1c cavm_mio_emm_dma_int_ena_w1c_t;

#define CAVM_MIO_EMM_DMA_INT_ENA_W1C CAVM_MIO_EMM_DMA_INT_ENA_W1C_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_INT_ENA_W1C_FUNC(void)
{
    return 0x87e0090001a8ll;
}

#define typedef_CAVM_MIO_EMM_DMA_INT_ENA_W1C cavm_mio_emm_dma_int_ena_w1c_t
#define bustype_CAVM_MIO_EMM_DMA_INT_ENA_W1C CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA_INT_ENA_W1C "MIO_EMM_DMA_INT_ENA_W1C"
#define device_bar_CAVM_MIO_EMM_DMA_INT_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA_INT_ENA_W1C 0
#define arguments_CAVM_MIO_EMM_DMA_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma_int_ena_w1s
 *
 * eMMC DMA Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_mio_emm_dma_int_ena_w1s
{
    uint64_t u;
    struct cavm_mio_emm_dma_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t fifo                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MIO_EMM_DMA_INT[FIFO]. */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MIO_EMM_DMA_INT[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MIO_EMM_DMA_INT[DONE]. */
        uint64_t fifo                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MIO_EMM_DMA_INT[FIFO]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_dma_int_ena_w1s_s cn; */
};
typedef union cavm_mio_emm_dma_int_ena_w1s cavm_mio_emm_dma_int_ena_w1s_t;

#define CAVM_MIO_EMM_DMA_INT_ENA_W1S CAVM_MIO_EMM_DMA_INT_ENA_W1S_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_INT_ENA_W1S_FUNC(void)
{
    return 0x87e0090001a0ll;
}

#define typedef_CAVM_MIO_EMM_DMA_INT_ENA_W1S cavm_mio_emm_dma_int_ena_w1s_t
#define bustype_CAVM_MIO_EMM_DMA_INT_ENA_W1S CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA_INT_ENA_W1S "MIO_EMM_DMA_INT_ENA_W1S"
#define device_bar_CAVM_MIO_EMM_DMA_INT_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA_INT_ENA_W1S 0
#define arguments_CAVM_MIO_EMM_DMA_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_dma_int_w1s
 *
 * eMMC DMA Interrupt Set Register
 * This register sets interrupt bits.
 */
union cavm_mio_emm_dma_int_w1s
{
    uint64_t u;
    struct cavm_mio_emm_dma_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t fifo                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MIO_EMM_DMA_INT[FIFO]. */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MIO_EMM_DMA_INT[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MIO_EMM_DMA_INT[DONE]. */
        uint64_t fifo                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MIO_EMM_DMA_INT[FIFO]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_dma_int_w1s_s cn; */
};
typedef union cavm_mio_emm_dma_int_w1s cavm_mio_emm_dma_int_w1s_t;

#define CAVM_MIO_EMM_DMA_INT_W1S CAVM_MIO_EMM_DMA_INT_W1S_FUNC()
static inline uint64_t CAVM_MIO_EMM_DMA_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_DMA_INT_W1S_FUNC(void)
{
    return 0x87e009000198ll;
}

#define typedef_CAVM_MIO_EMM_DMA_INT_W1S cavm_mio_emm_dma_int_w1s_t
#define bustype_CAVM_MIO_EMM_DMA_INT_W1S CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_DMA_INT_W1S "MIO_EMM_DMA_INT_W1S"
#define device_bar_CAVM_MIO_EMM_DMA_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_DMA_INT_W1S 0
#define arguments_CAVM_MIO_EMM_DMA_INT_W1S -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_int
 *
 * eMMC Interrupt Register
 */
union cavm_mio_emm_int
{
    uint64_t u;
    struct cavm_mio_emm_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t switch_err            : 1;  /**< [  6:  6](R/W1C/H) Switch operation encountered an error. */
        uint64_t switch_done           : 1;  /**< [  5:  5](R/W1C/H) Switch operation completed successfully. */
        uint64_t dma_err               : 1;  /**< [  4:  4](R/W1C/H) External DMA transfer encountered an error. See MIO_EMM_RSP_STS. */
        uint64_t cmd_err               : 1;  /**< [  3:  3](R/W1C/H) Operation specified by MIO_EMM_CMD encountered an error. See MIO_EMM_RSP_STS. */
        uint64_t dma_done              : 1;  /**< [  2:  2](R/W1C/H) External DMA transfer completed successfully. */
        uint64_t cmd_done              : 1;  /**< [  1:  1](R/W1C/H) Operation specified by MIO_EMM_CMD completed successfully. */
        uint64_t buf_done              : 1;  /**< [  0:  0](R/W1C/H) The next 512B block transfer of a multiblock transfer has completed. */
#else /* Word 0 - Little Endian */
        uint64_t buf_done              : 1;  /**< [  0:  0](R/W1C/H) The next 512B block transfer of a multiblock transfer has completed. */
        uint64_t cmd_done              : 1;  /**< [  1:  1](R/W1C/H) Operation specified by MIO_EMM_CMD completed successfully. */
        uint64_t dma_done              : 1;  /**< [  2:  2](R/W1C/H) External DMA transfer completed successfully. */
        uint64_t cmd_err               : 1;  /**< [  3:  3](R/W1C/H) Operation specified by MIO_EMM_CMD encountered an error. See MIO_EMM_RSP_STS. */
        uint64_t dma_err               : 1;  /**< [  4:  4](R/W1C/H) External DMA transfer encountered an error. See MIO_EMM_RSP_STS. */
        uint64_t switch_done           : 1;  /**< [  5:  5](R/W1C/H) Switch operation completed successfully. */
        uint64_t switch_err            : 1;  /**< [  6:  6](R/W1C/H) Switch operation encountered an error. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_int_s cn; */
};
typedef union cavm_mio_emm_int cavm_mio_emm_int_t;

#define CAVM_MIO_EMM_INT CAVM_MIO_EMM_INT_FUNC()
static inline uint64_t CAVM_MIO_EMM_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_INT_FUNC(void)
{
    return 0x87e009002078ll;
}

#define typedef_CAVM_MIO_EMM_INT cavm_mio_emm_int_t
#define bustype_CAVM_MIO_EMM_INT CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_INT "MIO_EMM_INT"
#define device_bar_CAVM_MIO_EMM_INT 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_INT 0
#define arguments_CAVM_MIO_EMM_INT -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_int_ena_w1c
 *
 * eMMC Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
union cavm_mio_emm_int_ena_w1c
{
    uint64_t u;
    struct cavm_mio_emm_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t switch_err            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for MIO_EMM_INT[SWITCH_ERR]. */
        uint64_t switch_done           : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for MIO_EMM_INT[SWITCH_DONE]. */
        uint64_t dma_err               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for MIO_EMM_INT[DMA_ERR]. */
        uint64_t cmd_err               : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MIO_EMM_INT[CMD_ERR]. */
        uint64_t dma_done              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MIO_EMM_INT[DMA_DONE]. */
        uint64_t cmd_done              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MIO_EMM_INT[CMD_DONE]. */
        uint64_t buf_done              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MIO_EMM_INT[BUF_DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t buf_done              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for MIO_EMM_INT[BUF_DONE]. */
        uint64_t cmd_done              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for MIO_EMM_INT[CMD_DONE]. */
        uint64_t dma_done              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for MIO_EMM_INT[DMA_DONE]. */
        uint64_t cmd_err               : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for MIO_EMM_INT[CMD_ERR]. */
        uint64_t dma_err               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for MIO_EMM_INT[DMA_ERR]. */
        uint64_t switch_done           : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for MIO_EMM_INT[SWITCH_DONE]. */
        uint64_t switch_err            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for MIO_EMM_INT[SWITCH_ERR]. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_int_ena_w1c_s cn; */
};
typedef union cavm_mio_emm_int_ena_w1c cavm_mio_emm_int_ena_w1c_t;

#define CAVM_MIO_EMM_INT_ENA_W1C CAVM_MIO_EMM_INT_ENA_W1C_FUNC()
static inline uint64_t CAVM_MIO_EMM_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_INT_ENA_W1C_FUNC(void)
{
    return 0x87e0090020b8ll;
}

#define typedef_CAVM_MIO_EMM_INT_ENA_W1C cavm_mio_emm_int_ena_w1c_t
#define bustype_CAVM_MIO_EMM_INT_ENA_W1C CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_INT_ENA_W1C "MIO_EMM_INT_ENA_W1C"
#define device_bar_CAVM_MIO_EMM_INT_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_INT_ENA_W1C 0
#define arguments_CAVM_MIO_EMM_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_int_ena_w1s
 *
 * eMMC Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
union cavm_mio_emm_int_ena_w1s
{
    uint64_t u;
    struct cavm_mio_emm_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t switch_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for MIO_EMM_INT[SWITCH_ERR]. */
        uint64_t switch_done           : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for MIO_EMM_INT[SWITCH_DONE]. */
        uint64_t dma_err               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for MIO_EMM_INT[DMA_ERR]. */
        uint64_t cmd_err               : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MIO_EMM_INT[CMD_ERR]. */
        uint64_t dma_done              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MIO_EMM_INT[DMA_DONE]. */
        uint64_t cmd_done              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MIO_EMM_INT[CMD_DONE]. */
        uint64_t buf_done              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MIO_EMM_INT[BUF_DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t buf_done              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for MIO_EMM_INT[BUF_DONE]. */
        uint64_t cmd_done              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for MIO_EMM_INT[CMD_DONE]. */
        uint64_t dma_done              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for MIO_EMM_INT[DMA_DONE]. */
        uint64_t cmd_err               : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for MIO_EMM_INT[CMD_ERR]. */
        uint64_t dma_err               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for MIO_EMM_INT[DMA_ERR]. */
        uint64_t switch_done           : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for MIO_EMM_INT[SWITCH_DONE]. */
        uint64_t switch_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for MIO_EMM_INT[SWITCH_ERR]. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_int_ena_w1s_s cn; */
};
typedef union cavm_mio_emm_int_ena_w1s cavm_mio_emm_int_ena_w1s_t;

#define CAVM_MIO_EMM_INT_ENA_W1S CAVM_MIO_EMM_INT_ENA_W1S_FUNC()
static inline uint64_t CAVM_MIO_EMM_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_INT_ENA_W1S_FUNC(void)
{
    return 0x87e0090020b0ll;
}

#define typedef_CAVM_MIO_EMM_INT_ENA_W1S cavm_mio_emm_int_ena_w1s_t
#define bustype_CAVM_MIO_EMM_INT_ENA_W1S CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_INT_ENA_W1S "MIO_EMM_INT_ENA_W1S"
#define device_bar_CAVM_MIO_EMM_INT_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_INT_ENA_W1S 0
#define arguments_CAVM_MIO_EMM_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_int_w1s
 *
 * eMMC Interrupt Set Register
 * This register sets interrupt bits.
 */
union cavm_mio_emm_int_w1s
{
    uint64_t u;
    struct cavm_mio_emm_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t switch_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets MIO_EMM_INT[SWITCH_ERR]. */
        uint64_t switch_done           : 1;  /**< [  5:  5](R/W1S/H) Reads or sets MIO_EMM_INT[SWITCH_DONE]. */
        uint64_t dma_err               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets MIO_EMM_INT[DMA_ERR]. */
        uint64_t cmd_err               : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MIO_EMM_INT[CMD_ERR]. */
        uint64_t dma_done              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MIO_EMM_INT[DMA_DONE]. */
        uint64_t cmd_done              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MIO_EMM_INT[CMD_DONE]. */
        uint64_t buf_done              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MIO_EMM_INT[BUF_DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t buf_done              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets MIO_EMM_INT[BUF_DONE]. */
        uint64_t cmd_done              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets MIO_EMM_INT[CMD_DONE]. */
        uint64_t dma_done              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets MIO_EMM_INT[DMA_DONE]. */
        uint64_t cmd_err               : 1;  /**< [  3:  3](R/W1S/H) Reads or sets MIO_EMM_INT[CMD_ERR]. */
        uint64_t dma_err               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets MIO_EMM_INT[DMA_ERR]. */
        uint64_t switch_done           : 1;  /**< [  5:  5](R/W1S/H) Reads or sets MIO_EMM_INT[SWITCH_DONE]. */
        uint64_t switch_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets MIO_EMM_INT[SWITCH_ERR]. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_int_w1s_s cn; */
};
typedef union cavm_mio_emm_int_w1s cavm_mio_emm_int_w1s_t;

#define CAVM_MIO_EMM_INT_W1S CAVM_MIO_EMM_INT_W1S_FUNC()
static inline uint64_t CAVM_MIO_EMM_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_INT_W1S_FUNC(void)
{
    return 0x87e009002080ll;
}

#define typedef_CAVM_MIO_EMM_INT_W1S cavm_mio_emm_int_w1s_t
#define bustype_CAVM_MIO_EMM_INT_W1S CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_INT_W1S "MIO_EMM_INT_W1S"
#define device_bar_CAVM_MIO_EMM_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_INT_W1S 0
#define arguments_CAVM_MIO_EMM_INT_W1S -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_mode#
 *
 * eMMC Operating Mode Register
 */
union cavm_mio_emm_modex
{
    uint64_t u;
    struct cavm_mio_emm_modex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t hs_timing             : 1;  /**< [ 48: 48](RO/H) Current high-speed timing mode. Required when CLK frequency is higher than 20 MHz. */
        uint64_t reserved_43_47        : 5;
        uint64_t bus_width             : 3;  /**< [ 42: 40](RO/H) Current card bus mode. Out of reset, the card is in 1-bit data bus mode. Select bus width.
                                                                 0x0 = 1-bit data bus (power on).
                                                                 0x1 = 4-bit data bus.
                                                                 0x2 = 8-bit data bus.
                                                                 0x3 = Reserved.
                                                                 0x4 = Reserved.
                                                                 0x5 = 4-bit data bus (dual data rate).
                                                                 0x6 = 8-bit data bus (dual data rate).
                                                                 0x7 = Reserved.
                                                                 0x8 = Reserved. */
        uint64_t reserved_36_39        : 4;
        uint64_t power_class           : 4;  /**< [ 35: 32](RO/H) Out of reset, the card power class is 0, which is the minimum current consumption class
                                                                 for the card. EXT_CSD bytes [203:200] and [239:238] contain the power class for different
                                                                 BUS_WITDH and CLK frequencies. Software should write this field with the 4-bit field from
                                                                 the EXT_CSD bytes corresponding to the selected operating mode. */
        uint64_t clk_hi                : 16; /**< [ 31: 16](RO/H) Current number of coprocessor-clocks to hold the eMMC CLK pin high. */
        uint64_t clk_lo                : 16; /**< [ 15:  0](RO/H) Current number of coprocessor-clocks to hold the eMMC CLK pin low. */
#else /* Word 0 - Little Endian */
        uint64_t clk_lo                : 16; /**< [ 15:  0](RO/H) Current number of coprocessor-clocks to hold the eMMC CLK pin low. */
        uint64_t clk_hi                : 16; /**< [ 31: 16](RO/H) Current number of coprocessor-clocks to hold the eMMC CLK pin high. */
        uint64_t power_class           : 4;  /**< [ 35: 32](RO/H) Out of reset, the card power class is 0, which is the minimum current consumption class
                                                                 for the card. EXT_CSD bytes [203:200] and [239:238] contain the power class for different
                                                                 BUS_WITDH and CLK frequencies. Software should write this field with the 4-bit field from
                                                                 the EXT_CSD bytes corresponding to the selected operating mode. */
        uint64_t reserved_36_39        : 4;
        uint64_t bus_width             : 3;  /**< [ 42: 40](RO/H) Current card bus mode. Out of reset, the card is in 1-bit data bus mode. Select bus width.
                                                                 0x0 = 1-bit data bus (power on).
                                                                 0x1 = 4-bit data bus.
                                                                 0x2 = 8-bit data bus.
                                                                 0x3 = Reserved.
                                                                 0x4 = Reserved.
                                                                 0x5 = 4-bit data bus (dual data rate).
                                                                 0x6 = 8-bit data bus (dual data rate).
                                                                 0x7 = Reserved.
                                                                 0x8 = Reserved. */
        uint64_t reserved_43_47        : 5;
        uint64_t hs_timing             : 1;  /**< [ 48: 48](RO/H) Current high-speed timing mode. Required when CLK frequency is higher than 20 MHz. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_modex_s cn; */
};
typedef union cavm_mio_emm_modex cavm_mio_emm_modex_t;

static inline uint64_t CAVM_MIO_EMM_MODEX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_MODEX(unsigned long a)
{
    if (a<=3)
        return 0x87e009002008ll + 8ll * ((a) & 0x3);
    __cavm_csr_fatal("MIO_EMM_MODEX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MIO_EMM_MODEX(a) cavm_mio_emm_modex_t
#define bustype_CAVM_MIO_EMM_MODEX(a) CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_MODEX(a) "MIO_EMM_MODEX"
#define device_bar_CAVM_MIO_EMM_MODEX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_MODEX(a) (a)
#define arguments_CAVM_MIO_EMM_MODEX(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_emm_msix_pba#
 *
 * eMMC MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the MIO_EMM_INT_VEC_E
 * enumeration.
 */
union cavm_mio_emm_msix_pbax
{
    uint64_t u;
    struct cavm_mio_emm_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated MIO_EMM_MSIX_VEC()_CTL, enumerated by
                                                                 MIO_EMM_INT_VEC_E. Bits that have no associated MIO_EMM_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated MIO_EMM_MSIX_VEC()_CTL, enumerated by
                                                                 MIO_EMM_INT_VEC_E. Bits that have no associated MIO_EMM_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_msix_pbax_s cn; */
};
typedef union cavm_mio_emm_msix_pbax cavm_mio_emm_msix_pbax_t;

static inline uint64_t CAVM_MIO_EMM_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_MSIX_PBAX(unsigned long a)
{
    if (a==0)
        return 0x87e009ff0000ll + 8ll * ((a) & 0x0);
    __cavm_csr_fatal("MIO_EMM_MSIX_PBAX", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MIO_EMM_MSIX_PBAX(a) cavm_mio_emm_msix_pbax_t
#define bustype_CAVM_MIO_EMM_MSIX_PBAX(a) CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_MSIX_PBAX(a) "MIO_EMM_MSIX_PBAX"
#define device_bar_CAVM_MIO_EMM_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_MIO_EMM_MSIX_PBAX(a) (a)
#define arguments_CAVM_MIO_EMM_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_emm_msix_vec#_addr
 *
 * eMMC MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the MIO_EMM_INT_VEC_E enumeration.
 */
union cavm_mio_emm_msix_vecx_addr
{
    uint64_t u;
    struct cavm_mio_emm_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's MIO_EMM_MSIX_VEC()_ADDR, MIO_EMM_MSIX_VEC()_CTL, and
                                                                 corresponding bit of MIO_EMM_MSIX_PBA() are RAZ/WI and does not cause a fault when
                                                                 accessed by the nonsecure world.

                                                                 If PCCPF_MIO_EMM_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's MIO_EMM_MSIX_VEC()_ADDR, MIO_EMM_MSIX_VEC()_CTL, and
                                                                 corresponding bit of MIO_EMM_MSIX_PBA() are RAZ/WI and does not cause a fault when
                                                                 accessed by the nonsecure world.

                                                                 If PCCPF_MIO_EMM_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_msix_vecx_addr_s cn; */
};
typedef union cavm_mio_emm_msix_vecx_addr cavm_mio_emm_msix_vecx_addr_t;

static inline uint64_t CAVM_MIO_EMM_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_MSIX_VECX_ADDR(unsigned long a)
{
    if (a<=8)
        return 0x87e009f00000ll + 0x10ll * ((a) & 0xf);
    __cavm_csr_fatal("MIO_EMM_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MIO_EMM_MSIX_VECX_ADDR(a) cavm_mio_emm_msix_vecx_addr_t
#define bustype_CAVM_MIO_EMM_MSIX_VECX_ADDR(a) CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_MSIX_VECX_ADDR(a) "MIO_EMM_MSIX_VECX_ADDR"
#define device_bar_CAVM_MIO_EMM_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_MIO_EMM_MSIX_VECX_ADDR(a) (a)
#define arguments_CAVM_MIO_EMM_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_emm_msix_vec#_ctl
 *
 * eMMC MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the MIO_EMM_INT_VEC_E enumeration.
 */
union cavm_mio_emm_msix_vecx_ctl
{
    uint64_t u;
    struct cavm_mio_emm_msix_vecx_ctl_s
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
    /* struct cavm_mio_emm_msix_vecx_ctl_s cn; */
};
typedef union cavm_mio_emm_msix_vecx_ctl cavm_mio_emm_msix_vecx_ctl_t;

static inline uint64_t CAVM_MIO_EMM_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_MSIX_VECX_CTL(unsigned long a)
{
    if (a<=8)
        return 0x87e009f00008ll + 0x10ll * ((a) & 0xf);
    __cavm_csr_fatal("MIO_EMM_MSIX_VECX_CTL", 1, a, 0, 0, 0);
   return 0;
}

#define typedef_CAVM_MIO_EMM_MSIX_VECX_CTL(a) cavm_mio_emm_msix_vecx_ctl_t
#define bustype_CAVM_MIO_EMM_MSIX_VECX_CTL(a) CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_MSIX_VECX_CTL(a) "MIO_EMM_MSIX_VECX_CTL"
#define device_bar_CAVM_MIO_EMM_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_MIO_EMM_MSIX_VECX_CTL(a) (a)
#define arguments_CAVM_MIO_EMM_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) mio_emm_rca
 *
 * eMMC Relative Card Address Register
 */
union cavm_mio_emm_rca
{
    uint64_t u;
    struct cavm_mio_emm_rca_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t card_rca              : 16; /**< [ 15:  0](R/W/H) Whenever software performs CMD7, hardware updates [CARD_RCA] with the relative card
                                                                 address
                                                                 from the MIO_EMM_CMD[ARG], unless the operation encounters an error. */
#else /* Word 0 - Little Endian */
        uint64_t card_rca              : 16; /**< [ 15:  0](R/W/H) Whenever software performs CMD7, hardware updates [CARD_RCA] with the relative card
                                                                 address
                                                                 from the MIO_EMM_CMD[ARG], unless the operation encounters an error. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_rca_s cn; */
};
typedef union cavm_mio_emm_rca cavm_mio_emm_rca_t;

#define CAVM_MIO_EMM_RCA CAVM_MIO_EMM_RCA_FUNC()
static inline uint64_t CAVM_MIO_EMM_RCA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_RCA_FUNC(void)
{
    return 0x87e0090020a0ll;
}

#define typedef_CAVM_MIO_EMM_RCA cavm_mio_emm_rca_t
#define bustype_CAVM_MIO_EMM_RCA CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_RCA "MIO_EMM_RCA"
#define device_bar_CAVM_MIO_EMM_RCA 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_RCA 0
#define arguments_CAVM_MIO_EMM_RCA -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_rsp_hi
 *
 * eMMC Response Data High Register
 */
union cavm_mio_emm_rsp_hi
{
    uint64_t u;
    struct cavm_mio_emm_rsp_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO/H) Command response (as per JEDEC eMMC spec and SD Specifications):
                                                                 _ RSP_TYPE = 1: DAT[63:0] = 0x0.
                                                                 _ RSP_TYPE = 2: DAT[63:0] = CID[127:64] or CSD[127:64].
                                                                 _ RSP_TYPE = 3: DAT[63:0] = 0x0.
                                                                 _ RSP_TYPE = 4: DAT[63:0] = 0x0.
                                                                 _ RSP_TYPE = 5: DAT[63:0] = 0x0. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO/H) Command response (as per JEDEC eMMC spec and SD Specifications):
                                                                 _ RSP_TYPE = 1: DAT[63:0] = 0x0.
                                                                 _ RSP_TYPE = 2: DAT[63:0] = CID[127:64] or CSD[127:64].
                                                                 _ RSP_TYPE = 3: DAT[63:0] = 0x0.
                                                                 _ RSP_TYPE = 4: DAT[63:0] = 0x0.
                                                                 _ RSP_TYPE = 5: DAT[63:0] = 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_rsp_hi_s cn; */
};
typedef union cavm_mio_emm_rsp_hi cavm_mio_emm_rsp_hi_t;

#define CAVM_MIO_EMM_RSP_HI CAVM_MIO_EMM_RSP_HI_FUNC()
static inline uint64_t CAVM_MIO_EMM_RSP_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_RSP_HI_FUNC(void)
{
    return 0x87e009002070ll;
}

#define typedef_CAVM_MIO_EMM_RSP_HI cavm_mio_emm_rsp_hi_t
#define bustype_CAVM_MIO_EMM_RSP_HI CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_RSP_HI "MIO_EMM_RSP_HI"
#define device_bar_CAVM_MIO_EMM_RSP_HI 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_RSP_HI 0
#define arguments_CAVM_MIO_EMM_RSP_HI -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_rsp_lo
 *
 * eMMC Response Data Low Register
 */
union cavm_mio_emm_rsp_lo
{
    uint64_t u;
    struct cavm_mio_emm_rsp_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO/H) Command response (as per JEDEC eMMC spec and SD Specifications).

                                                                 <pre>
                                                                 RSP_TYPE = 1:
                                                                 DAT[63:46] = 0x0
                                                                 DAT[45:40] = Command index
                                                                 DAT[39: 8] = Card status
                                                                 DAT[ 7: 1] = CRC7
                                                                 DAT[    0] = End bit

                                                                 RSP_TYPE = 2:
                                                                 DAT[63: 1] = CID[63:1] or CSD[63:1] including CRC
                                                                 DAT[    0] = End bit

                                                                 RSP_TYPE = 3:
                                                                 DAT[63:46] = 0x0
                                                                 DAT[45:40] = Check bits (0x3F)
                                                                 DAT[39: 8] = OCR register
                                                                 DAT[ 7: 1] = Check bits (0x7F)
                                                                 DAT[    0] = End bit

                                                                 RSP_TYPE = 4:
                                                                 DAT[63:46] = 0x0
                                                                 DAT[45:40] = CMD39 ('10111')
                                                                 DAT[39:24] = RCA[31:16]
                                                                 DAT[   23] = Status
                                                                 DAT[22:16] = Register address
                                                                 DAT[15: 8] = Register contents
                                                                 DAT[ 7: 1] = CRC7
                                                                 DAT[    0] = End bit

                                                                 RSP_TYPE = 5:
                                                                 DAT[63:46] = 0x0
                                                                 DAT[45:40] = CMD40 ('10100')
                                                                 DAT[39:24] = RCA[31:16]
                                                                 DAT[   23] = Status
                                                                 DAT[22:16] = Register address
                                                                 DAT[15: 8] = Not defined. May be used for IRQ data
                                                                 DAT[ 7: 1] = CRC7
                                                                 DAT[    0] = End bit
                                                                 </pre> */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO/H) Command response (as per JEDEC eMMC spec and SD Specifications).

                                                                 <pre>
                                                                 RSP_TYPE = 1:
                                                                 DAT[63:46] = 0x0
                                                                 DAT[45:40] = Command index
                                                                 DAT[39: 8] = Card status
                                                                 DAT[ 7: 1] = CRC7
                                                                 DAT[    0] = End bit

                                                                 RSP_TYPE = 2:
                                                                 DAT[63: 1] = CID[63:1] or CSD[63:1] including CRC
                                                                 DAT[    0] = End bit

                                                                 RSP_TYPE = 3:
                                                                 DAT[63:46] = 0x0
                                                                 DAT[45:40] = Check bits (0x3F)
                                                                 DAT[39: 8] = OCR register
                                                                 DAT[ 7: 1] = Check bits (0x7F)
                                                                 DAT[    0] = End bit

                                                                 RSP_TYPE = 4:
                                                                 DAT[63:46] = 0x0
                                                                 DAT[45:40] = CMD39 ('10111')
                                                                 DAT[39:24] = RCA[31:16]
                                                                 DAT[   23] = Status
                                                                 DAT[22:16] = Register address
                                                                 DAT[15: 8] = Register contents
                                                                 DAT[ 7: 1] = CRC7
                                                                 DAT[    0] = End bit

                                                                 RSP_TYPE = 5:
                                                                 DAT[63:46] = 0x0
                                                                 DAT[45:40] = CMD40 ('10100')
                                                                 DAT[39:24] = RCA[31:16]
                                                                 DAT[   23] = Status
                                                                 DAT[22:16] = Register address
                                                                 DAT[15: 8] = Not defined. May be used for IRQ data
                                                                 DAT[ 7: 1] = CRC7
                                                                 DAT[    0] = End bit
                                                                 </pre> */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_rsp_lo_s cn; */
};
typedef union cavm_mio_emm_rsp_lo cavm_mio_emm_rsp_lo_t;

#define CAVM_MIO_EMM_RSP_LO CAVM_MIO_EMM_RSP_LO_FUNC()
static inline uint64_t CAVM_MIO_EMM_RSP_LO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_RSP_LO_FUNC(void)
{
    return 0x87e009002068ll;
}

#define typedef_CAVM_MIO_EMM_RSP_LO cavm_mio_emm_rsp_lo_t
#define bustype_CAVM_MIO_EMM_RSP_LO CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_RSP_LO "MIO_EMM_RSP_LO"
#define device_bar_CAVM_MIO_EMM_RSP_LO 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_RSP_LO 0
#define arguments_CAVM_MIO_EMM_RSP_LO -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_rsp_sts
 *
 * eMMC Response Status Register
 */
union cavm_mio_emm_rsp_sts
{
    uint64_t u;
    struct cavm_mio_emm_rsp_sts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t bus_id                : 2;  /**< [ 61: 60](RO/H) eMMC bus ID to which the response status corresponds. */
        uint64_t cmd_val               : 1;  /**< [ 59: 59](RO/H) Read-only copy of MIO_EMM_CMD[CMD_VAL]. [CMD_VAL] = 1 indicates that a direct operation is
                                                                 in progress. */
        uint64_t switch_val            : 1;  /**< [ 58: 58](RO/H) Read-only copy of MIO_EMM_SWITCH[SWITCH_EXE]. [SWITCH_VAL] = 1 indicates that a switch
                                                                 operation is in progress. */
        uint64_t dma_val               : 1;  /**< [ 57: 57](RO/H) Read-only copy of MIO_EMM_DMA[DMA_VAL]. [DMA_VAL] = 1 indicates that a DMA operation is in
                                                                 progress. */
        uint64_t dma_pend              : 1;  /**< [ 56: 56](RO/H) The DMA engine has a pending transfer resulting from an error. Software can resume the
                                                                 transfer by writing MIO_EMM_DMA[DMA_VAL] = 1.

                                                                 Software can terminate the transfer by writing MIO_EMM_DMA[DMA_VAL] = 1 and
                                                                 MIO_EMM_DMA[DAT_NULL] = 1. Hardware will then clear [DMA_PEND] and perform the DMA
                                                                 operation. */
        uint64_t acc_timeout           : 1;  /**< [ 55: 55](RO/H) The store operation to the device took longer than MIO_EMM_ACCESS_WDOG[CLK_CNT]
                                                                 coprocessor-clocks to complete.
                                                                 Valid when [DMA_PEND] is set. */
        uint64_t reserved_29_54        : 26;
        uint64_t dbuf_err              : 1;  /**< [ 28: 28](RO/H) For [CMD_TYPE] = 1, indicates that a DMA read data arrived from the card without a free
                                                                 DBUF. For [CMD_TYPE] = 2, indicates a DBUF underflow occurred during a DMA write. See
                                                                 MIO_EMM_DMA[THRES]. */
        uint64_t reserved_24_27        : 4;
        uint64_t dbuf                  : 1;  /**< [ 23: 23](RO/H) DBUF corresponding to the most recently attempted block transfer. */
        uint64_t blk_timeout           : 1;  /**< [ 22: 22](RO/H) Timeout waiting for read data or 3-bit CRC token. */
        uint64_t blk_crc_err           : 1;  /**< [ 21: 21](RO/H) For [CMD_TYPE] = 1, indicates a card read data CRC mismatch. MIO_EMM_RSP_STS[DBUF]
                                                                 indicates
                                                                 the failing data buffer.

                                                                 For [CMD_TYPE] = 2, indicates card returned 3-bit CRC status token indicating that the
                                                                 card
                                                                 encountered a write data CRC check mismatch. MIO_EMM_RSP_STS[DBUF] indicates the failing
                                                                 data buffer. */
        uint64_t rsp_busybit           : 1;  /**< [ 20: 20](RO/H) Debug only. eMMC protocol utilizes DAT0 as a busy signal during block writes and R1b
                                                                 responses. This bit should read zero before any DMA or Command with data is executed. */
        uint64_t stp_timeout           : 1;  /**< [ 19: 19](RO/H) Stop transmission response timeout. */
        uint64_t stp_crc_err           : 1;  /**< [ 18: 18](RO/H) Stop transmission response had a CRC error. */
        uint64_t stp_bad_sts           : 1;  /**< [ 17: 17](RO/H) Stop transmission response had bad status. */
        uint64_t stp_val               : 1;  /**< [ 16: 16](RO/H) Stop transmission response valid. */
        uint64_t rsp_timeout           : 1;  /**< [ 15: 15](RO/H) Response timeout. */
        uint64_t rsp_crc_err           : 1;  /**< [ 14: 14](RO/H) Response CRC error. */
        uint64_t rsp_bad_sts           : 1;  /**< [ 13: 13](RO/H) Response bad status. */
        uint64_t rsp_val               : 1;  /**< [ 12: 12](RO/H) Response ID. See MIO_EMM_RSP_HI/MIO_EMM_RSP_LO. */
        uint64_t rsp_type              : 3;  /**< [ 11:  9](RO/H) Indicates the response type. See MIO_EMM_RSP_HI/MIO_EMM_RSP_LO. */
        uint64_t cmd_type              : 2;  /**< [  8:  7](RO/H) eMMC command type.
                                                                 0x0 = No data.
                                                                 0x1 = Read.
                                                                 0x2 = Write. */
        uint64_t cmd_idx               : 6;  /**< [  6:  1](RO/H) eMMC command index most recently attempted. */
        uint64_t cmd_done              : 1;  /**< [  0:  0](RO/H) eMMC command completed. Once the command has completed, the status is final and can be
                                                                 examined by software. */
#else /* Word 0 - Little Endian */
        uint64_t cmd_done              : 1;  /**< [  0:  0](RO/H) eMMC command completed. Once the command has completed, the status is final and can be
                                                                 examined by software. */
        uint64_t cmd_idx               : 6;  /**< [  6:  1](RO/H) eMMC command index most recently attempted. */
        uint64_t cmd_type              : 2;  /**< [  8:  7](RO/H) eMMC command type.
                                                                 0x0 = No data.
                                                                 0x1 = Read.
                                                                 0x2 = Write. */
        uint64_t rsp_type              : 3;  /**< [ 11:  9](RO/H) Indicates the response type. See MIO_EMM_RSP_HI/MIO_EMM_RSP_LO. */
        uint64_t rsp_val               : 1;  /**< [ 12: 12](RO/H) Response ID. See MIO_EMM_RSP_HI/MIO_EMM_RSP_LO. */
        uint64_t rsp_bad_sts           : 1;  /**< [ 13: 13](RO/H) Response bad status. */
        uint64_t rsp_crc_err           : 1;  /**< [ 14: 14](RO/H) Response CRC error. */
        uint64_t rsp_timeout           : 1;  /**< [ 15: 15](RO/H) Response timeout. */
        uint64_t stp_val               : 1;  /**< [ 16: 16](RO/H) Stop transmission response valid. */
        uint64_t stp_bad_sts           : 1;  /**< [ 17: 17](RO/H) Stop transmission response had bad status. */
        uint64_t stp_crc_err           : 1;  /**< [ 18: 18](RO/H) Stop transmission response had a CRC error. */
        uint64_t stp_timeout           : 1;  /**< [ 19: 19](RO/H) Stop transmission response timeout. */
        uint64_t rsp_busybit           : 1;  /**< [ 20: 20](RO/H) Debug only. eMMC protocol utilizes DAT0 as a busy signal during block writes and R1b
                                                                 responses. This bit should read zero before any DMA or Command with data is executed. */
        uint64_t blk_crc_err           : 1;  /**< [ 21: 21](RO/H) For [CMD_TYPE] = 1, indicates a card read data CRC mismatch. MIO_EMM_RSP_STS[DBUF]
                                                                 indicates
                                                                 the failing data buffer.

                                                                 For [CMD_TYPE] = 2, indicates card returned 3-bit CRC status token indicating that the
                                                                 card
                                                                 encountered a write data CRC check mismatch. MIO_EMM_RSP_STS[DBUF] indicates the failing
                                                                 data buffer. */
        uint64_t blk_timeout           : 1;  /**< [ 22: 22](RO/H) Timeout waiting for read data or 3-bit CRC token. */
        uint64_t dbuf                  : 1;  /**< [ 23: 23](RO/H) DBUF corresponding to the most recently attempted block transfer. */
        uint64_t reserved_24_27        : 4;
        uint64_t dbuf_err              : 1;  /**< [ 28: 28](RO/H) For [CMD_TYPE] = 1, indicates that a DMA read data arrived from the card without a free
                                                                 DBUF. For [CMD_TYPE] = 2, indicates a DBUF underflow occurred during a DMA write. See
                                                                 MIO_EMM_DMA[THRES]. */
        uint64_t reserved_29_54        : 26;
        uint64_t acc_timeout           : 1;  /**< [ 55: 55](RO/H) The store operation to the device took longer than MIO_EMM_ACCESS_WDOG[CLK_CNT]
                                                                 coprocessor-clocks to complete.
                                                                 Valid when [DMA_PEND] is set. */
        uint64_t dma_pend              : 1;  /**< [ 56: 56](RO/H) The DMA engine has a pending transfer resulting from an error. Software can resume the
                                                                 transfer by writing MIO_EMM_DMA[DMA_VAL] = 1.

                                                                 Software can terminate the transfer by writing MIO_EMM_DMA[DMA_VAL] = 1 and
                                                                 MIO_EMM_DMA[DAT_NULL] = 1. Hardware will then clear [DMA_PEND] and perform the DMA
                                                                 operation. */
        uint64_t dma_val               : 1;  /**< [ 57: 57](RO/H) Read-only copy of MIO_EMM_DMA[DMA_VAL]. [DMA_VAL] = 1 indicates that a DMA operation is in
                                                                 progress. */
        uint64_t switch_val            : 1;  /**< [ 58: 58](RO/H) Read-only copy of MIO_EMM_SWITCH[SWITCH_EXE]. [SWITCH_VAL] = 1 indicates that a switch
                                                                 operation is in progress. */
        uint64_t cmd_val               : 1;  /**< [ 59: 59](RO/H) Read-only copy of MIO_EMM_CMD[CMD_VAL]. [CMD_VAL] = 1 indicates that a direct operation is
                                                                 in progress. */
        uint64_t bus_id                : 2;  /**< [ 61: 60](RO/H) eMMC bus ID to which the response status corresponds. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_rsp_sts_s cn; */
};
typedef union cavm_mio_emm_rsp_sts cavm_mio_emm_rsp_sts_t;

#define CAVM_MIO_EMM_RSP_STS CAVM_MIO_EMM_RSP_STS_FUNC()
static inline uint64_t CAVM_MIO_EMM_RSP_STS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_RSP_STS_FUNC(void)
{
    return 0x87e009002060ll;
}

#define typedef_CAVM_MIO_EMM_RSP_STS cavm_mio_emm_rsp_sts_t
#define bustype_CAVM_MIO_EMM_RSP_STS CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_RSP_STS "MIO_EMM_RSP_STS"
#define device_bar_CAVM_MIO_EMM_RSP_STS 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_RSP_STS 0
#define arguments_CAVM_MIO_EMM_RSP_STS -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_sample
 *
 * eMMC Sampling Register
 */
union cavm_mio_emm_sample
{
    uint64_t u;
    struct cavm_mio_emm_sample_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t cmd_cnt               : 10; /**< [ 25: 16](R/W) Number of coprocessor-clocks before the eMMC clock rising edge to sample the command pin. */
        uint64_t reserved_10_15        : 6;
        uint64_t dat_cnt               : 10; /**< [  9:  0](R/W) Number of coprocessor-clocks before the eMMC clock edge to sample the data pin. */
#else /* Word 0 - Little Endian */
        uint64_t dat_cnt               : 10; /**< [  9:  0](R/W) Number of coprocessor-clocks before the eMMC clock edge to sample the data pin. */
        uint64_t reserved_10_15        : 6;
        uint64_t cmd_cnt               : 10; /**< [ 25: 16](R/W) Number of coprocessor-clocks before the eMMC clock rising edge to sample the command pin. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_sample_s cn; */
};
typedef union cavm_mio_emm_sample cavm_mio_emm_sample_t;

#define CAVM_MIO_EMM_SAMPLE CAVM_MIO_EMM_SAMPLE_FUNC()
static inline uint64_t CAVM_MIO_EMM_SAMPLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_SAMPLE_FUNC(void)
{
    return 0x87e009002090ll;
}

#define typedef_CAVM_MIO_EMM_SAMPLE cavm_mio_emm_sample_t
#define bustype_CAVM_MIO_EMM_SAMPLE CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_SAMPLE "MIO_EMM_SAMPLE"
#define device_bar_CAVM_MIO_EMM_SAMPLE 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_SAMPLE 0
#define arguments_CAVM_MIO_EMM_SAMPLE -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_sts_mask
 *
 * eMMC Status Mask Register
 */
union cavm_mio_emm_sts_mask
{
    uint64_t u;
    struct cavm_mio_emm_sts_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t sts_msk               : 32; /**< [ 31:  0](R/W) Any bit set in [STS_MSK] causes the corresponding bit in the card status to be
                                                                 considered when computing response bad status. */
#else /* Word 0 - Little Endian */
        uint64_t sts_msk               : 32; /**< [ 31:  0](R/W) Any bit set in [STS_MSK] causes the corresponding bit in the card status to be
                                                                 considered when computing response bad status. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_sts_mask_s cn; */
};
typedef union cavm_mio_emm_sts_mask cavm_mio_emm_sts_mask_t;

#define CAVM_MIO_EMM_STS_MASK CAVM_MIO_EMM_STS_MASK_FUNC()
static inline uint64_t CAVM_MIO_EMM_STS_MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_STS_MASK_FUNC(void)
{
    return 0x87e009002098ll;
}

#define typedef_CAVM_MIO_EMM_STS_MASK cavm_mio_emm_sts_mask_t
#define bustype_CAVM_MIO_EMM_STS_MASK CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_STS_MASK "MIO_EMM_STS_MASK"
#define device_bar_CAVM_MIO_EMM_STS_MASK 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_STS_MASK 0
#define arguments_CAVM_MIO_EMM_STS_MASK -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_switch
 *
 * eMMC Operating Mode Switch Register
 */
union cavm_mio_emm_switch
{
    uint64_t u;
    struct cavm_mio_emm_switch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t bus_id                : 2;  /**< [ 61: 60](R/W/H) Specifies the eMMC bus id. */
        uint64_t switch_exe            : 1;  /**< [ 59: 59](R/W/H) When clear, the operating modes are updated directly without performing any
                                                                 SWITCH operations. This allows software to perform the SWITCH operations manually, then
                                                                 update the hardware.

                                                                 Software writes this bit to a 1 to indicate that hardware should perform the necessary
                                                                 SWITCH operations.

                                                                 * First, the POWER_CLASS switch is performed. If it fails, [SWITCH_ERR0] is set and the
                                                                 remaining SWITCH operations are not performed. If it succeeds, [POWER_CLASS] is
                                                                 updated and the HS_TIMING switch is performed.

                                                                 * If the HS_TIMING switch fails, [SWITCH_ERR1] is set and the remaining SWITCH operations
                                                                 are not performed. If it succeeds, [HS_TIMING] is updated and the BUS_WIDTH switch
                                                                 operation is performed.

                                                                 * If the BUS_WIDTH switch operation fails, [SWITCH_ERR2] is set. If it succeeds, the
                                                                 BUS_WITDH is updated.

                                                                 Changes to CLK_HI and CLK_LO are discarded if any SWITCH_ERR occurs. */
        uint64_t switch_err0           : 1;  /**< [ 58: 58](RO/H) Error encountered while performing POWER_CLASS switch. See MIO_EMM_RSP_STS. */
        uint64_t switch_err1           : 1;  /**< [ 57: 57](RO/H) Error encountered while performing HS_TIMING switch. See MIO_EMM_RSP_STS. */
        uint64_t switch_err2           : 1;  /**< [ 56: 56](RO/H) Error encountered while performing BUS_WIDTH switch. See MIO_EMM_RSP_STS. */
        uint64_t reserved_49_55        : 7;
        uint64_t hs_timing             : 1;  /**< [ 48: 48](R/W) Requested update to HS_TIMING. */
        uint64_t reserved_43_47        : 5;
        uint64_t bus_width             : 3;  /**< [ 42: 40](R/W) Requested update to BUS_WIDTH. */
        uint64_t reserved_36_39        : 4;
        uint64_t power_class           : 4;  /**< [ 35: 32](R/W) Requested update to POWER_CLASS. */
        uint64_t clk_hi                : 16; /**< [ 31: 16](R/W) Requested update to CLK_HI. */
        uint64_t clk_lo                : 16; /**< [ 15:  0](R/W) Requested update to CLK_LO. */
#else /* Word 0 - Little Endian */
        uint64_t clk_lo                : 16; /**< [ 15:  0](R/W) Requested update to CLK_LO. */
        uint64_t clk_hi                : 16; /**< [ 31: 16](R/W) Requested update to CLK_HI. */
        uint64_t power_class           : 4;  /**< [ 35: 32](R/W) Requested update to POWER_CLASS. */
        uint64_t reserved_36_39        : 4;
        uint64_t bus_width             : 3;  /**< [ 42: 40](R/W) Requested update to BUS_WIDTH. */
        uint64_t reserved_43_47        : 5;
        uint64_t hs_timing             : 1;  /**< [ 48: 48](R/W) Requested update to HS_TIMING. */
        uint64_t reserved_49_55        : 7;
        uint64_t switch_err2           : 1;  /**< [ 56: 56](RO/H) Error encountered while performing BUS_WIDTH switch. See MIO_EMM_RSP_STS. */
        uint64_t switch_err1           : 1;  /**< [ 57: 57](RO/H) Error encountered while performing HS_TIMING switch. See MIO_EMM_RSP_STS. */
        uint64_t switch_err0           : 1;  /**< [ 58: 58](RO/H) Error encountered while performing POWER_CLASS switch. See MIO_EMM_RSP_STS. */
        uint64_t switch_exe            : 1;  /**< [ 59: 59](R/W/H) When clear, the operating modes are updated directly without performing any
                                                                 SWITCH operations. This allows software to perform the SWITCH operations manually, then
                                                                 update the hardware.

                                                                 Software writes this bit to a 1 to indicate that hardware should perform the necessary
                                                                 SWITCH operations.

                                                                 * First, the POWER_CLASS switch is performed. If it fails, [SWITCH_ERR0] is set and the
                                                                 remaining SWITCH operations are not performed. If it succeeds, [POWER_CLASS] is
                                                                 updated and the HS_TIMING switch is performed.

                                                                 * If the HS_TIMING switch fails, [SWITCH_ERR1] is set and the remaining SWITCH operations
                                                                 are not performed. If it succeeds, [HS_TIMING] is updated and the BUS_WIDTH switch
                                                                 operation is performed.

                                                                 * If the BUS_WIDTH switch operation fails, [SWITCH_ERR2] is set. If it succeeds, the
                                                                 BUS_WITDH is updated.

                                                                 Changes to CLK_HI and CLK_LO are discarded if any SWITCH_ERR occurs. */
        uint64_t bus_id                : 2;  /**< [ 61: 60](R/W/H) Specifies the eMMC bus id. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_switch_s cn; */
};
typedef union cavm_mio_emm_switch cavm_mio_emm_switch_t;

#define CAVM_MIO_EMM_SWITCH CAVM_MIO_EMM_SWITCH_FUNC()
static inline uint64_t CAVM_MIO_EMM_SWITCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_SWITCH_FUNC(void)
{
    return 0x87e009002048ll;
}

#define typedef_CAVM_MIO_EMM_SWITCH cavm_mio_emm_switch_t
#define bustype_CAVM_MIO_EMM_SWITCH CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_SWITCH "MIO_EMM_SWITCH"
#define device_bar_CAVM_MIO_EMM_SWITCH 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_SWITCH 0
#define arguments_CAVM_MIO_EMM_SWITCH -1,-1,-1,-1

/**
 * Register (RSL) mio_emm_wdog
 *
 * eMMC Watchdog Register
 */
union cavm_mio_emm_wdog
{
    uint64_t u;
    struct cavm_mio_emm_wdog_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t clk_cnt               : 26; /**< [ 25:  0](R/W) Maximum number of CLK_CNT cycles to wait for the card to return a response, read data, or
                                                                 the 3-bit CRC status token following write data. The following timeouts are detected:

                                                                 Expected response to a command doesn't occur causing MIO_EMM_RSP_STS[RSP_TIMEOUT].

                                                                 On a read command, expected data isn't returned causing MIO_EMM_RSP_STS[BLK_TIMEOUT].

                                                                 On a multi read command, expected data isn't returned causing
                                                                 MIO_EMM_RSP_STS[BLK_TIMEOUT].

                                                                 On a write command, expected token to a write block isn't received causing
                                                                 MIO_EMM_RSP_STS[BLK_TIMEOUT].

                                                                 If a stop command is issued by the hardware and no response is returned causing
                                                                 MIO_EMM_RSP_STS[STP_TIMEOUT].

                                                                 Issues this timeout doesn't cover are stalls induced by the card which are not limited by
                                                                 the specifications.
                                                                 For example, when a write multi command is issued to the card and a block (not the last)
                                                                 is transferred the card can "stall" CNXXXX by forcing emmc_data<0> low for as long as
                                                                 it wants to free up buffer space.

                                                                 The second case is when the last block of a write or multi write is being transferred and
                                                                 the card elects to perform some background tasks. The same stall mechanism with
                                                                 emmc_data<0> is used but this can last for an extend time period. */
#else /* Word 0 - Little Endian */
        uint64_t clk_cnt               : 26; /**< [ 25:  0](R/W) Maximum number of CLK_CNT cycles to wait for the card to return a response, read data, or
                                                                 the 3-bit CRC status token following write data. The following timeouts are detected:

                                                                 Expected response to a command doesn't occur causing MIO_EMM_RSP_STS[RSP_TIMEOUT].

                                                                 On a read command, expected data isn't returned causing MIO_EMM_RSP_STS[BLK_TIMEOUT].

                                                                 On a multi read command, expected data isn't returned causing
                                                                 MIO_EMM_RSP_STS[BLK_TIMEOUT].

                                                                 On a write command, expected token to a write block isn't received causing
                                                                 MIO_EMM_RSP_STS[BLK_TIMEOUT].

                                                                 If a stop command is issued by the hardware and no response is returned causing
                                                                 MIO_EMM_RSP_STS[STP_TIMEOUT].

                                                                 Issues this timeout doesn't cover are stalls induced by the card which are not limited by
                                                                 the specifications.
                                                                 For example, when a write multi command is issued to the card and a block (not the last)
                                                                 is transferred the card can "stall" CNXXXX by forcing emmc_data<0> low for as long as
                                                                 it wants to free up buffer space.

                                                                 The second case is when the last block of a write or multi write is being transferred and
                                                                 the card elects to perform some background tasks. The same stall mechanism with
                                                                 emmc_data<0> is used but this can last for an extend time period. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_mio_emm_wdog_s cn; */
};
typedef union cavm_mio_emm_wdog cavm_mio_emm_wdog_t;

#define CAVM_MIO_EMM_WDOG CAVM_MIO_EMM_WDOG_FUNC()
static inline uint64_t CAVM_MIO_EMM_WDOG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_MIO_EMM_WDOG_FUNC(void)
{
    return 0x87e009002088ll;
}

#define typedef_CAVM_MIO_EMM_WDOG cavm_mio_emm_wdog_t
#define bustype_CAVM_MIO_EMM_WDOG CSR_TYPE_RSL
#define basename_CAVM_MIO_EMM_WDOG "MIO_EMM_WDOG"
#define device_bar_CAVM_MIO_EMM_WDOG 0x0 /* PF_BAR0 */
#define busnum_CAVM_MIO_EMM_WDOG 0
#define arguments_CAVM_MIO_EMM_WDOG -1,-1,-1,-1

#endif /* __CAVM_CSRS_MIO_EMM_H__ */
