#ifndef __CAVM_CSRS_GPIO_H__
#define __CAVM_CSRS_GPIO_H__
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
 * OcteonTX GPIO.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration gpio_assigned_pin_e
 *
 * GPIO Assigned Pin Number Enumeration
 * Enumerates GPIO pin numbers which have certain dedicated hardware and boot usage.
 */
#define CAVM_GPIO_ASSIGNED_PIN_E_BOOT_COMPLETE (0xa)
#define CAVM_GPIO_ASSIGNED_PIN_E_BOOT_REQ (9)
#define CAVM_GPIO_ASSIGNED_PIN_E_BOOT_WAIT (0xe)
#define CAVM_GPIO_ASSIGNED_PIN_E_EJTAG_TCK (0x13)
#define CAVM_GPIO_ASSIGNED_PIN_E_EJTAG_TDI (0x14)
#define CAVM_GPIO_ASSIGNED_PIN_E_EJTAG_TDO (0x12)
#define CAVM_GPIO_ASSIGNED_PIN_E_EJTAG_TMS (0x15)
#define CAVM_GPIO_ASSIGNED_PIN_E_EMMC_POWER (8)
#define CAVM_GPIO_ASSIGNED_PIN_E_FAIL_CODE (0xb)
#define CAVM_GPIO_ASSIGNED_PIN_E_NCSI_CRS_DV (0x1f)
#define CAVM_GPIO_ASSIGNED_PIN_E_NCSI_REF_CLK (0x1a)
#define CAVM_GPIO_ASSIGNED_PIN_E_NCSI_RXD0 (0x1c)
#define CAVM_GPIO_ASSIGNED_PIN_E_NCSI_RXD1 (0x1d)
#define CAVM_GPIO_ASSIGNED_PIN_E_NCSI_RX_ER (0x1e)
#define CAVM_GPIO_ASSIGNED_PIN_E_NCSI_TXD0 (0x18)
#define CAVM_GPIO_ASSIGNED_PIN_E_NCSI_TXD1 (0x19)
#define CAVM_GPIO_ASSIGNED_PIN_E_NCSI_TX_EN (0x1b)
#define CAVM_GPIO_ASSIGNED_PIN_E_PSPI_CLK (0x27)
#define CAVM_GPIO_ASSIGNED_PIN_E_PSPI_CS (0x2a)
#define CAVM_GPIO_ASSIGNED_PIN_E_PSPI_MISO (0x29)
#define CAVM_GPIO_ASSIGNED_PIN_E_PSPI_MOSI (0x28)
#define CAVM_GPIO_ASSIGNED_PIN_E_SPI1_CLK (0x24)
#define CAVM_GPIO_ASSIGNED_PIN_E_SPI1_CS0 (0x25)
#define CAVM_GPIO_ASSIGNED_PIN_E_SPI1_CS1 (0x26)
#define CAVM_GPIO_ASSIGNED_PIN_E_SPI1_IO0 (0x20)
#define CAVM_GPIO_ASSIGNED_PIN_E_SPI1_IO1 (0x21)
#define CAVM_GPIO_ASSIGNED_PIN_E_SPI1_IO2 (0x22)
#define CAVM_GPIO_ASSIGNED_PIN_E_SPI1_IO3 (0x23)
#define CAVM_GPIO_ASSIGNED_PIN_E_SWP_RESET_L (0x2c)
#define CAVM_GPIO_ASSIGNED_PIN_E_SWP_SPI1_CS3 (0x2b)
#define CAVM_GPIO_ASSIGNED_PIN_E_UART7_CTS_L (0x16)
#define CAVM_GPIO_ASSIGNED_PIN_E_UART7_RTS_L (0xc)
#define CAVM_GPIO_ASSIGNED_PIN_E_UART7_SIN (0x17)
#define CAVM_GPIO_ASSIGNED_PIN_E_UART7_SOUT (0xd)

/**
 * Enumeration gpio_bar_e
 *
 * GPIO Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN8 (0x803000000000ll)
#define CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN8_SIZE 0x800000ull
#define CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN9 (0x803000000000ll)
#define CAVM_GPIO_BAR_E_GPIO_PF_BAR0_CN9_SIZE 0x10000ull
#define CAVM_GPIO_BAR_E_GPIO_PF_BAR4 (0x803000f00000ll)
#define CAVM_GPIO_BAR_E_GPIO_PF_BAR4_SIZE 0x100000ull

/**
 * Enumeration gpio_int_vec_e
 *
 * GPIO MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CN81XX(a) (4 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CN83XX(a) (0x18 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CN96XX(a) (0x36 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CN98XX(a) (0x24 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CNF95XX(a) (6 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_LOKI(a) (6 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CLEAR_CN81XX(a) (5 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CLEAR_CN83XX(a) (0x19 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CLEAR_CN96XX(a) (0x37 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CLEAR_CN98XX(a) (0x25 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CLEAR_CNF95XX(a) (7 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_INTR_PINX_CLEAR_LOKI(a) (7 + 2 * (a))
#define CAVM_GPIO_INT_VEC_E_MC_INTR_PPX(a) (0 + (a))

/**
 * Enumeration gpio_misc_strap_pin_e
 *
 * GPIO Miscellaneous Strap Pin Number Enumeration
 * Enumerates GPIO_MISC_STRAP bit numbers and associated pins with their associated
 * strap functions. The names of these values are used as the documented name of each
 * strap.
 */
#define CAVM_GPIO_MISC_STRAP_PIN_E_RSVD_UART0_RTS (0x10)
#define CAVM_GPIO_MISC_STRAP_PIN_E_VDROOP_DIS (0x11)

/**
 * Enumeration gpio_pin_sel_e
 *
 * GPIO Pin Select Enumeration
 * Enumerates the GPIO pin function selections for GPIO_BIT_CFG()[PIN_SEL].
 *
 * The GPIO pins can be configured as either input, output or input/output/bidirectional
 * depending on the GPIO_PIN_SEL_E used as described in the value's description.  When
 * a GPIO pin is used as input, the value is provided to the described function, and is
 * also readable via GPIO_RX_DAT.
 *
 * Multiple GPIO pins may not be configured to point to the same input encoding, or
 * the input result is unpredictable (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
 * GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80).
 *
 * If a given select is not assigned to any pin, then that virtual input receives a
 * logical zero.  E.g. if no GPIO_BIT_CFG()[PIN_SEL] has the value ::OCLA_EXT_TRIGGER,
 * then the GPIO will provide the OCLA block's external trigger input with the value of
 * zero.
 */
#define CAVM_GPIO_PIN_SEL_E_BOOT_REQ (0x3e0)
#define CAVM_GPIO_PIN_SEL_E_BOOT_WAIT (0x3e1)
#define CAVM_GPIO_PIN_SEL_E_BPHY_RESET_OUT (0x486)
#define CAVM_GPIO_PIN_SEL_E_BTS_BFN_CLK (0x506)
#define CAVM_GPIO_PIN_SEL_E_BTS_BFN_IN (0x505)
#define CAVM_GPIO_PIN_SEL_E_BTS_BFN_OUT (0x510)
#define CAVM_GPIO_PIN_SEL_E_BTS_CGBFN_OUT (0x50d)
#define CAVM_GPIO_PIN_SEL_E_BTS_CGCLK_OUT (0x50e)
#define CAVM_GPIO_PIN_SEL_E_BTS_CGTENMS_OUT (0x50c)
#define CAVM_GPIO_PIN_SEL_E_BTS_DAC_CLK (0x511)
#define CAVM_GPIO_PIN_SEL_E_BTS_EXTREFX_CLK(a) (0x500 + (a))
#define CAVM_GPIO_PIN_SEL_E_BTS_PWM_DOUT (0x513)
#define CAVM_GPIO_PIN_SEL_E_BTS_PWM_SCLK (0x512)
#define CAVM_GPIO_PIN_SEL_E_BTS_RFP_IN (0x504)
#define CAVM_GPIO_PIN_SEL_E_BTS_RFP_OUT (0x50f)
#define CAVM_GPIO_PIN_SEL_E_BTS_TPX(a) (0x507 + (a))
#define CAVM_GPIO_PIN_SEL_E_CER_CATERR (0x3fb)
#define CAVM_GPIO_PIN_SEL_E_CER_ERR0 (0x3f8)
#define CAVM_GPIO_PIN_SEL_E_CER_ERR1 (0x3f9)
#define CAVM_GPIO_PIN_SEL_E_CER_ERR2 (0x3fa)
#define CAVM_GPIO_PIN_SEL_E_CGXX_LMACX_RX(a,b) (0x4a0 + 4 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_CGXX_LMACX_RXTX(a,b) (0x4e0 + 4 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_CGXX_LMACX_TX(a,b) (0x4c0 + 4 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_CORE_RESET_IN (0x480)
#define CAVM_GPIO_PIN_SEL_E_CORE_RESET_OUT (0x481)
#define CAVM_GPIO_PIN_SEL_E_CPRI_HDLC_CK (0x276)
#define CAVM_GPIO_PIN_SEL_E_CPRI_HDLC_RX (0x275)
#define CAVM_GPIO_PIN_SEL_E_CPRI_HDLC_TX (0x274)
#define CAVM_GPIO_PIN_SEL_E_EJTAG_TCK (0x3f1)
#define CAVM_GPIO_PIN_SEL_E_EJTAG_TDI (0x3f0)
#define CAVM_GPIO_PIN_SEL_E_EJTAG_TDO (0x3f4)
#define CAVM_GPIO_PIN_SEL_E_EJTAG_TMS (0x3f2)
#define CAVM_GPIO_PIN_SEL_E_GPIO_CLKX_CN8(a) (5 + (a))
#define CAVM_GPIO_PIN_SEL_E_GPIO_CLKX_CN9(a) (0x260 + (a))
#define CAVM_GPIO_PIN_SEL_E_GPIO_CLK_SYNCEX(a) (3 + (a))
#define CAVM_GPIO_PIN_SEL_E_GPIO_PTP_CKOUT (1)
#define CAVM_GPIO_PIN_SEL_E_GPIO_PTP_PPS (2)
#define CAVM_GPIO_PIN_SEL_E_GPIO_PTP_SYSCK (8)
#define CAVM_GPIO_PIN_SEL_E_GPIO_SW (0)
#define CAVM_GPIO_PIN_SEL_E_GSERCX_BURNINX(a,b) (0x61c + 0x10 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_GSERCX_DTESTX(a,b) (0x610 + 0x10 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_GSERPX_BURNINX(a,b) (0x70c + 0x10 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_GSERPX_DTESTX(a,b) (0x700 + 0x10 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_GSERPX_SYNCEX(a,b) (0x580 + 5 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_GSERP16_PCS_DTESTX(a) (0x5f0 + (a))
#define CAVM_GPIO_PIN_SEL_E_GSERP4_PCS_DTESTX(a) (0x5e0 + (a))
#define CAVM_GPIO_PIN_SEL_E_GSERRX_BURNINX(a,b) (0x60c + 0x10 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_GSERRX_DTESTX(a,b) (0x600 + 0x10 * (a) + (b))
#define CAVM_GPIO_PIN_SEL_E_LMCX_ECC_CN8(a) (0x237 + (a))
#define CAVM_GPIO_PIN_SEL_E_LMCX_ECC_CN9(a) (0x3d0 + (a))
#define CAVM_GPIO_PIN_SEL_E_MCDX_IN(a) (0x23f + (a))
#define CAVM_GPIO_PIN_SEL_E_MCDX_OUT(a) (0x242 + (a))
#define CAVM_GPIO_PIN_SEL_E_MCP_RESET_IN (0x482)
#define CAVM_GPIO_PIN_SEL_E_MCP_RESET_OUT (0x483)
#define CAVM_GPIO_PIN_SEL_E_NCSI_CRS_DV (0x258)
#define CAVM_GPIO_PIN_SEL_E_NCSI_REF_CLK (0x25c)
#define CAVM_GPIO_PIN_SEL_E_NCSI_RXDX(a) (0x25a + (a))
#define CAVM_GPIO_PIN_SEL_E_NCSI_RX_ER (0x259)
#define CAVM_GPIO_PIN_SEL_E_NCSI_TXDX(a) (0x25e + (a))
#define CAVM_GPIO_PIN_SEL_E_NCSI_TX_EN (0x25d)
#define CAVM_GPIO_PIN_SEL_E_OCLA_EXT_TRIGGER (0x231)
#define CAVM_GPIO_PIN_SEL_E_PBUS_ADX(a) (0xfa + (a))
#define CAVM_GPIO_PIN_SEL_E_PBUS_ALEX(a) (0xe8 + (a))
#define CAVM_GPIO_PIN_SEL_E_PBUS_CEX(a) (0xec + (a))
#define CAVM_GPIO_PIN_SEL_E_PBUS_CLE (0xe0)
#define CAVM_GPIO_PIN_SEL_E_PBUS_DIR (0xe4)
#define CAVM_GPIO_PIN_SEL_E_PBUS_DMACKX(a) (0xe6 + (a))
#define CAVM_GPIO_PIN_SEL_E_PBUS_DMARQX(a) (0x11a + (a))
#define CAVM_GPIO_PIN_SEL_E_PBUS_OE (0xe3)
#define CAVM_GPIO_PIN_SEL_E_PBUS_WAIT (0xe1)
#define CAVM_GPIO_PIN_SEL_E_PBUS_WE (0xe2)
#define CAVM_GPIO_PIN_SEL_E_PCM_BCLKX(a) (0x246 + (a))
#define CAVM_GPIO_PIN_SEL_E_PCM_DATAX(a) (0x24c + (a))
#define CAVM_GPIO_PIN_SEL_E_PCM_FSYNCX(a) (0x24a + (a))
#define CAVM_GPIO_PIN_SEL_E_PCS_DTESTX(a) (0x5f0 + (a))
#define CAVM_GPIO_PIN_SEL_E_PSPI_CLK (0x28d)
#define CAVM_GPIO_PIN_SEL_E_PSPI_CS (0x290)
#define CAVM_GPIO_PIN_SEL_E_PSPI_MISO (0x28f)
#define CAVM_GPIO_PIN_SEL_E_PSPI_MOSI (0x28e)
#define CAVM_GPIO_PIN_SEL_E_PTP_EVTCNT (0x252)
#define CAVM_GPIO_PIN_SEL_E_PTP_EXT_CLK (0x250)
#define CAVM_GPIO_PIN_SEL_E_PTP_TSTMP (0x251)
#define CAVM_GPIO_PIN_SEL_E_RFIF_RESET_OUTX(a) (0x488 + (a))
#define CAVM_GPIO_PIN_SEL_E_SATAX_ACT_LED_CN8(a) (0x16a + (a))
#define CAVM_GPIO_PIN_SEL_E_SATAX_ACT_LED_CN9(a) (0x420 + (a))
#define CAVM_GPIO_PIN_SEL_E_SATAX_CP_DET_CN8(a) (0x18b + (a))
#define CAVM_GPIO_PIN_SEL_E_SATAX_CP_DET_CN9(a) (0x440 + (a))
#define CAVM_GPIO_PIN_SEL_E_SATAX_CP_POD_CN8(a) (0x145 + (a))
#define CAVM_GPIO_PIN_SEL_E_SATAX_CP_POD_CN9(a) (0x400 + (a))
#define CAVM_GPIO_PIN_SEL_E_SATAX_MP_SWITCH_CN8(a) (0x200 + (a))
#define CAVM_GPIO_PIN_SEL_E_SATAX_MP_SWITCH_CN9(a) (0x460 + (a))
#define CAVM_GPIO_PIN_SEL_E_SATA_LAB_LB (0x18a)
#define CAVM_GPIO_PIN_SEL_E_SCP_RESET_IN (0x484)
#define CAVM_GPIO_PIN_SEL_E_SCP_RESET_OUT (0x485)
#define CAVM_GPIO_PIN_SEL_E_SGPIO_ACT_LEDX_CN8(a) (0xf + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_ACT_LEDX_CN9(a) (0x2c0 + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_ERR_LEDX_CN8(a) (0x90 + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_ERR_LEDX_CN9(a) (0x340 + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_LOC_LEDX_CN8(a) (0x50 + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_LOC_LEDX_CN9(a) (0x300 + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_SCLOCK_CN8 (9)
#define CAVM_GPIO_PIN_SEL_E_SGPIO_SCLOCK_CN9 (0x2a0)
#define CAVM_GPIO_PIN_SEL_E_SGPIO_SDATAINX_CN8(a) (0xd0 + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_SDATAINX_CN9(a) (0x380 + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_SDATAOUTX_CN8(a) (0xb + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_SDATAOUTX_CN9(a) (0x2b0 + (a))
#define CAVM_GPIO_PIN_SEL_E_SGPIO_SLOAD_CN8 (0xa)
#define CAVM_GPIO_PIN_SEL_E_SGPIO_SLOAD_CN9 (0x2a1)
#define CAVM_GPIO_PIN_SEL_E_SPI0_CSX(a) (0x278 + (a))
#define CAVM_GPIO_PIN_SEL_E_SPI1_CLK (0x280)
#define CAVM_GPIO_PIN_SEL_E_SPI1_CSX(a) (0x284 + (a))
#define CAVM_GPIO_PIN_SEL_E_SPI1_IOX(a) (0x288 + (a))
#define CAVM_GPIO_PIN_SEL_E_SPI_CSX(a) (0x233 + (a))
#define CAVM_GPIO_PIN_SEL_E_TIMER (0x11c)
#define CAVM_GPIO_PIN_SEL_E_TIM_GPIO_CLK (0x230)
#define CAVM_GPIO_PIN_SEL_E_TWS_SCLX(a) (0x294 + (a))
#define CAVM_GPIO_PIN_SEL_E_TWS_SDAX(a) (0x29a + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_CTS_CN8(a) (0x13f + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_CTS_CN9(a) (0x3c0 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_DCD_CN8(a) (0x131 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_DCD_CN9(a) (0x3b0 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_DSR_CN8(a) (0x139 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_DSR_CN9(a) (0x3b8 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_DTR_CN8(a) (0x11d + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_DTR_CN9(a) (0x390 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_RI_CN8(a) (0x129 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_RI_CN9(a) (0x3a8 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_RTS_CN8(a) (0x123 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_RTS_CN9(a) (0x398 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_SIN_CN8(a) (0x141 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_SIN_CN9(a) (0x3c8 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_SOUT_CN8(a) (0x125 + (a))
#define CAVM_GPIO_PIN_SEL_E_UARTX_SOUT_CN9(a) (0x3a0 + (a))
#define CAVM_GPIO_PIN_SEL_E_USBX_OVR_CRNT(a) (0x228 + (a))
#define CAVM_GPIO_PIN_SEL_E_USBX_VBUS_CTRL(a) (0x220 + (a))

/**
 * Enumeration gpio_strap_pin_e
 *
 * GPIO Strap Pin Number Enumeration
 * Enumerates GPIO pin numbers with their associated strap functions. The names of
 * these values are used as the documented name of each
 * strap. e.g. GPIO_STRAP_PIN_E::BOOT_METHOD0 describes the GPIO0/BOOT_METHOD0 strap.
 * For strap state, see GPIO_STRAP and GPIO_STRAP1.
 */
#define CAVM_GPIO_STRAP_PIN_E_AVS_DISABLE (9)
#define CAVM_GPIO_STRAP_PIN_E_BOOT_METHOD0 (0)
#define CAVM_GPIO_STRAP_PIN_E_BOOT_METHOD1 (1)
#define CAVM_GPIO_STRAP_PIN_E_BOOT_METHOD2 (2)
#define CAVM_GPIO_STRAP_PIN_E_BOOT_METHOD3 (3)
#define CAVM_GPIO_STRAP_PIN_E_BOOT_METHOD4 (0xc)
#define CAVM_GPIO_STRAP_PIN_E_BOOT_METHOD5 (0xd)
#define CAVM_GPIO_STRAP_PIN_E_CCPI_NODE_ID (0xb)
#define CAVM_GPIO_STRAP_PIN_E_GSER_CLK0_TERM_SEL0 (0x10)
#define CAVM_GPIO_STRAP_PIN_E_GSER_CLK0_TERM_SEL1 (0x11)
#define CAVM_GPIO_STRAP_PIN_E_MCP_DBG_ON_GPIO (4)
#define CAVM_GPIO_STRAP_PIN_E_NCSI_ON_GPIO (5)
#define CAVM_GPIO_STRAP_PIN_E_PCIE0_EP_MODE (0x18)
#define CAVM_GPIO_STRAP_PIN_E_PCIE1_EP_MODE (0x1a)
#define CAVM_GPIO_STRAP_PIN_E_PCIE2_EP_MODE (0x19)
#define CAVM_GPIO_STRAP_PIN_E_PCIE3_EP_MODE (0x1b)
#define CAVM_GPIO_STRAP_PIN_E_TRUSTED_MODE (0xa)

/**
 * Register (NCB) gpio_bit_cfg#
 *
 * GPIO Bit Configuration Registers
 * Each register provides configuration information for the corresponding GPIO pin.
 *
 * Each index is only accessible to the requestor(s) permitted with GPIO_BIT_PERMIT().
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_bit_cfgx
{
    uint64_t u;
    struct cavm_gpio_bit_cfgx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t pin_sel               : 11; /**< [ 26: 16](R/W) Selects which signal is reported to GPIO output, or which signal GPIO input need to
                                                                 connect. Each GPIO pin can be configured either input-only or output-only depending
                                                                 function selected, as enumerated by GPIO_PIN_SEL_E. For GPIO input selects,
                                                                 the GPIO signal used is after glitch filter and XOR inverter (GPIO_BIT_CFG()[PIN_XOR]). */
        uint64_t reserved_15           : 1;
        uint64_t blink_en              : 2;  /**< [ 14: 13](R/W) GPIO pin output blink filter enable. This function is after the [PIN_SEL]
                                                                 multiplexing but before the [PIN_XOR] inverter and [TX_OD] overdriver
                                                                 conversion. When blink filter is enabled, the pin output will generate blinking
                                                                 pattern based on configuration of GPIO_BLINK_CFG.
                                                                 0x0 = Disable blink filter.
                                                                 0x1 = Enable blink filter based on the start of activity.
                                                                 0x2 = Enable blink filter based on the end of activity, essentially based on
                                                                       inversion of blink filter's input.
                                                                 0x3 = Disable blink filter. */
        uint64_t tx_od                 : 1;  /**< [ 12: 12](R/W) GPIO output open-drain conversion. This function is after PIN_SEL MUX
                                                                 and [PIN_XOR] inverter.
                                                                 When set, the pin output will connect to zero, and pin enable
                                                                 will connect to original pin output. With both [TX_OD] and [PIN_XOR] set, a transmit
                                                                 of 1 will tristate the pin output driver to achieve open-drain function. */
        uint64_t fil_sel               : 4;  /**< [ 11:  8](R/W) Filter select. Global counter bit-select (controls sample rate).
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t fil_cnt               : 4;  /**< [  7:  4](R/W) Filter count. Specifies the number of consecutive samples ([FIL_CNT]+1) to change state.
                                                                 Zero to disable the filter.
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t int_type              : 1;  /**< [  3:  3](R/W) Type of interrupt when pin is an input and [INT_EN] set. When set, rising edge
                                                                 interrupt, else level interrupt. The GPIO signal used to generate interrupt is after
                                                                 the filter and after the XOR inverter. */
        uint64_t int_en                : 1;  /**< [  2:  2](R/W) Pin controls interrupt.

                                                                 If set, assertions of this pin after [PIN_XOR] will set GPIO_INTR()[INTR].

                                                                 If set and [INT_TYPE] is clear (level-sensitive), deassertions of this pin
                                                                 after [PIN_XOR] will clear GPIO_INTR()[INTR].

                                                                 This does NOT control if interrupts are enabled towards the MSI-X vector,
                                                                 for that see GPIO_INTR()[INTR_ENA]. */
        uint64_t pin_xor               : 1;  /**< [  1:  1](R/W) GPIO data inversion. When set, inverts the receiving or transmitting GPIO signal.
                                                                 For GPIO output, this inversion is after all GPIO [PIN_SEL] muxes. This inversion function
                                                                 is applicable to any GPIO output mux signals, also used to control GPIO_RX_DAT.
                                                                 For GPIO input, this inversion is before the GPIO [PIN_SEL] muxes, as used to control
                                                                 GPIO interrupts. */
        uint64_t tx_oe                 : 1;  /**< [  0:  0](R/W) Transmit output enable. When set to 1, the GPIO pin can be driven as an output
                                                                 pin if GPIO_BIT_CFG()[PIN_SEL] selects GPIO_PIN_SEL_E::GPIO_SW. [TX_OE] is only
                                                                 used along with GPIO_TX_SET or GPIO_TX_CLR, and [TX_OE] function is before
                                                                 GPIO_BIT_CFG()[PIN_SEL] mux. */
#else /* Word 0 - Little Endian */
        uint64_t tx_oe                 : 1;  /**< [  0:  0](R/W) Transmit output enable. When set to 1, the GPIO pin can be driven as an output
                                                                 pin if GPIO_BIT_CFG()[PIN_SEL] selects GPIO_PIN_SEL_E::GPIO_SW. [TX_OE] is only
                                                                 used along with GPIO_TX_SET or GPIO_TX_CLR, and [TX_OE] function is before
                                                                 GPIO_BIT_CFG()[PIN_SEL] mux. */
        uint64_t pin_xor               : 1;  /**< [  1:  1](R/W) GPIO data inversion. When set, inverts the receiving or transmitting GPIO signal.
                                                                 For GPIO output, this inversion is after all GPIO [PIN_SEL] muxes. This inversion function
                                                                 is applicable to any GPIO output mux signals, also used to control GPIO_RX_DAT.
                                                                 For GPIO input, this inversion is before the GPIO [PIN_SEL] muxes, as used to control
                                                                 GPIO interrupts. */
        uint64_t int_en                : 1;  /**< [  2:  2](R/W) Pin controls interrupt.

                                                                 If set, assertions of this pin after [PIN_XOR] will set GPIO_INTR()[INTR].

                                                                 If set and [INT_TYPE] is clear (level-sensitive), deassertions of this pin
                                                                 after [PIN_XOR] will clear GPIO_INTR()[INTR].

                                                                 This does NOT control if interrupts are enabled towards the MSI-X vector,
                                                                 for that see GPIO_INTR()[INTR_ENA]. */
        uint64_t int_type              : 1;  /**< [  3:  3](R/W) Type of interrupt when pin is an input and [INT_EN] set. When set, rising edge
                                                                 interrupt, else level interrupt. The GPIO signal used to generate interrupt is after
                                                                 the filter and after the XOR inverter. */
        uint64_t fil_cnt               : 4;  /**< [  7:  4](R/W) Filter count. Specifies the number of consecutive samples ([FIL_CNT]+1) to change state.
                                                                 Zero to disable the filter.
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t fil_sel               : 4;  /**< [ 11:  8](R/W) Filter select. Global counter bit-select (controls sample rate).
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t tx_od                 : 1;  /**< [ 12: 12](R/W) GPIO output open-drain conversion. This function is after PIN_SEL MUX
                                                                 and [PIN_XOR] inverter.
                                                                 When set, the pin output will connect to zero, and pin enable
                                                                 will connect to original pin output. With both [TX_OD] and [PIN_XOR] set, a transmit
                                                                 of 1 will tristate the pin output driver to achieve open-drain function. */
        uint64_t blink_en              : 2;  /**< [ 14: 13](R/W) GPIO pin output blink filter enable. This function is after the [PIN_SEL]
                                                                 multiplexing but before the [PIN_XOR] inverter and [TX_OD] overdriver
                                                                 conversion. When blink filter is enabled, the pin output will generate blinking
                                                                 pattern based on configuration of GPIO_BLINK_CFG.
                                                                 0x0 = Disable blink filter.
                                                                 0x1 = Enable blink filter based on the start of activity.
                                                                 0x2 = Enable blink filter based on the end of activity, essentially based on
                                                                       inversion of blink filter's input.
                                                                 0x3 = Disable blink filter. */
        uint64_t reserved_15           : 1;
        uint64_t pin_sel               : 11; /**< [ 26: 16](R/W) Selects which signal is reported to GPIO output, or which signal GPIO input need to
                                                                 connect. Each GPIO pin can be configured either input-only or output-only depending
                                                                 function selected, as enumerated by GPIO_PIN_SEL_E. For GPIO input selects,
                                                                 the GPIO signal used is after glitch filter and XOR inverter (GPIO_BIT_CFG()[PIN_XOR]). */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    struct cavm_gpio_bit_cfgx_cn8
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t pin_sel               : 10; /**< [ 25: 16](R/W) Selects which signal is reported to GPIO output, or which signal GPIO input need to
                                                                 connect. Each GPIO pin can be configured either input-only or output-only depending
                                                                 function selected, as enumerated by GPIO_PIN_SEL_E. For GPIO input selects,
                                                                 the GPIO signal used is after glitch filter and XOR inverter (GPIO_BIT_CFG()[PIN_XOR]). */
        uint64_t reserved_13_15        : 3;
        uint64_t tx_od                 : 1;  /**< [ 12: 12](R/W) GPIO output open-drain conversion. This function is after PIN_SEL MUX
                                                                 and [PIN_XOR] inverter.
                                                                 When set, the pin output will connect to zero, and pin enable
                                                                 will connect to original pin output. With both [TX_OD] and [PIN_XOR] set, a transmit
                                                                 of 1 will tristate the pin output driver to achieve open-drain function. */
        uint64_t fil_sel               : 4;  /**< [ 11:  8](R/W) Filter select. Global counter bit-select (controls sample rate).
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t fil_cnt               : 4;  /**< [  7:  4](R/W) Filter count. Specifies the number of consecutive samples ([FIL_CNT]+1) to change state.
                                                                 Zero to disable the filter.
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t int_type              : 1;  /**< [  3:  3](R/W) Type of interrupt when pin is an input and [INT_EN] set. When set, rising edge
                                                                 interrupt, else level interrupt. The GPIO signal used to generate interrupt is after
                                                                 the filter and after the XOR inverter. */
        uint64_t int_en                : 1;  /**< [  2:  2](R/W) Pin controls interrupt.

                                                                 If set, assertions of this pin after [PIN_XOR] will set GPIO_INTR()[INTR].

                                                                 If set and [INT_TYPE] is clear (level-sensitive), deassertions of this pin
                                                                 after [PIN_XOR] will clear GPIO_INTR()[INTR].

                                                                 This does NOT control if interrupts are enabled towards the MSI-X vector,
                                                                 for that see GPIO_INTR()[INTR_ENA]. */
        uint64_t pin_xor               : 1;  /**< [  1:  1](R/W) GPIO data inversion. When set, inverts the receiving or transmitting GPIO signal.
                                                                 For GPIO output, this inversion is after all GPIO [PIN_SEL] muxes. This inversion function
                                                                 is applicable to any GPIO output mux signals, also used to control GPIO_RX_DAT.
                                                                 For GPIO input, this inversion is before the GPIO [PIN_SEL] muxes, as used to control
                                                                 GPIO interrupts. */
        uint64_t tx_oe                 : 1;  /**< [  0:  0](R/W) Transmit output enable. When set to 1, the GPIO pin can be driven as an output
                                                                 pin if GPIO_BIT_CFG()[PIN_SEL] selects GPIO_PIN_SEL_E::GPIO_SW. [TX_OE] is only
                                                                 used along with GPIO_TX_SET or GPIO_TX_CLR, and [TX_OE] function is before
                                                                 GPIO_BIT_CFG()[PIN_SEL] mux. */
#else /* Word 0 - Little Endian */
        uint64_t tx_oe                 : 1;  /**< [  0:  0](R/W) Transmit output enable. When set to 1, the GPIO pin can be driven as an output
                                                                 pin if GPIO_BIT_CFG()[PIN_SEL] selects GPIO_PIN_SEL_E::GPIO_SW. [TX_OE] is only
                                                                 used along with GPIO_TX_SET or GPIO_TX_CLR, and [TX_OE] function is before
                                                                 GPIO_BIT_CFG()[PIN_SEL] mux. */
        uint64_t pin_xor               : 1;  /**< [  1:  1](R/W) GPIO data inversion. When set, inverts the receiving or transmitting GPIO signal.
                                                                 For GPIO output, this inversion is after all GPIO [PIN_SEL] muxes. This inversion function
                                                                 is applicable to any GPIO output mux signals, also used to control GPIO_RX_DAT.
                                                                 For GPIO input, this inversion is before the GPIO [PIN_SEL] muxes, as used to control
                                                                 GPIO interrupts. */
        uint64_t int_en                : 1;  /**< [  2:  2](R/W) Pin controls interrupt.

                                                                 If set, assertions of this pin after [PIN_XOR] will set GPIO_INTR()[INTR].

                                                                 If set and [INT_TYPE] is clear (level-sensitive), deassertions of this pin
                                                                 after [PIN_XOR] will clear GPIO_INTR()[INTR].

                                                                 This does NOT control if interrupts are enabled towards the MSI-X vector,
                                                                 for that see GPIO_INTR()[INTR_ENA]. */
        uint64_t int_type              : 1;  /**< [  3:  3](R/W) Type of interrupt when pin is an input and [INT_EN] set. When set, rising edge
                                                                 interrupt, else level interrupt. The GPIO signal used to generate interrupt is after
                                                                 the filter and after the XOR inverter. */
        uint64_t fil_cnt               : 4;  /**< [  7:  4](R/W) Filter count. Specifies the number of consecutive samples ([FIL_CNT]+1) to change state.
                                                                 Zero to disable the filter.
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t fil_sel               : 4;  /**< [ 11:  8](R/W) Filter select. Global counter bit-select (controls sample rate).
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t tx_od                 : 1;  /**< [ 12: 12](R/W) GPIO output open-drain conversion. This function is after PIN_SEL MUX
                                                                 and [PIN_XOR] inverter.
                                                                 When set, the pin output will connect to zero, and pin enable
                                                                 will connect to original pin output. With both [TX_OD] and [PIN_XOR] set, a transmit
                                                                 of 1 will tristate the pin output driver to achieve open-drain function. */
        uint64_t reserved_13_15        : 3;
        uint64_t pin_sel               : 10; /**< [ 25: 16](R/W) Selects which signal is reported to GPIO output, or which signal GPIO input need to
                                                                 connect. Each GPIO pin can be configured either input-only or output-only depending
                                                                 function selected, as enumerated by GPIO_PIN_SEL_E. For GPIO input selects,
                                                                 the GPIO signal used is after glitch filter and XOR inverter (GPIO_BIT_CFG()[PIN_XOR]). */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } cn8;
    struct cavm_gpio_bit_cfgx_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t pin_sel               : 11; /**< [ 26: 16](R/W) Selects which signal is reported to GPIO output, or which signal GPIO input need
                                                                 to connect. Each GPIO pin can be configured either input-only, output only or
                                                                 input/output depending on function selected, as enumerated by
                                                                 GPIO_PIN_SEL_E (see also notes in that enumeration).
                                                                 For GPIO input selects, the GPIO signal used is after glitch
                                                                 filter and XOR inverter (GPIO_BIT_CFG()[PIN_XOR]). */
        uint64_t reserved_15           : 1;
        uint64_t blink_en              : 2;  /**< [ 14: 13](R/W) GPIO pin output blink filter enable. This function is after the [PIN_SEL]
                                                                 multiplexing but before the [PIN_XOR] inverter and [TX_OD] overdriver
                                                                 conversion. When blink filter is enabled, the pin output will generate blinking
                                                                 pattern based on configuration of GPIO_BLINK_CFG.
                                                                 0x0 = Disable blink filter.
                                                                 0x1 = Enable blink filter based on the start of activity.
                                                                 0x2 = Enable blink filter based on the end of activity, essentially based on
                                                                       inversion of blink filter's input.
                                                                 0x3 = Disable blink filter. */
        uint64_t tx_od                 : 1;  /**< [ 12: 12](R/W) GPIO output open-drain conversion. This function is after the [PIN_SEL]
                                                                 multiplexing, [PIN_XOR] inverter, and [BLINK_EN] activity filter.
                                                                 When set, the pin output will connect to zero, and pin enable
                                                                 will connect to original pin output. With both [TX_OD] and [PIN_XOR] set, a transmit
                                                                 of 1 will tristate the pin output driver to achieve open-drain function
                                                                 with additional pullup on board. */
        uint64_t fil_sel               : 4;  /**< [ 11:  8](R/W) Filter select. Global counter bit-select (controls sample rate).
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t fil_cnt               : 4;  /**< [  7:  4](R/W) Filter count. Specifies the number of consecutive samples ([FIL_CNT]+1) to change state.
                                                                 Zero to disable the filter.
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t int_type              : 1;  /**< [  3:  3](R/W) Type of interrupt when pin is an input and [INT_EN] set. When set, rising edge
                                                                 interrupt, else level interrupt. The GPIO signal used to generate interrupt is after
                                                                 the filter and after the XOR inverter. */
        uint64_t int_en                : 1;  /**< [  2:  2](R/W) Pin controls interrupt.

                                                                 If set, assertions of this pin after [PIN_XOR] will set GPIO_INTR()[INTR].

                                                                 If set and [INT_TYPE] is clear (level-sensitive), deassertions of this pin
                                                                 after [PIN_XOR] will clear GPIO_INTR()[INTR].

                                                                 This does NOT control if interrupts are enabled towards the MSI-X vector,
                                                                 for that see GPIO_INTR()[INTR_ENA_W1S]. */
        uint64_t pin_xor               : 1;  /**< [  1:  1](R/W) GPIO data inversion. When set, inverts the receiving or transmitting GPIO signal.
                                                                 For GPIO output, this inversion is after all GPIO [PIN_SEL] muxes. This inversion function
                                                                 is applicable to any GPIO output mux signals, also used to control GPIO_RX_DAT.
                                                                 For GPIO input, this inversion is before the GPIO [PIN_SEL] muxes, as used to control
                                                                 GPIO interrupts. */
        uint64_t tx_oe                 : 1;  /**< [  0:  0](R/W) Transmit output enable. When set to 1, the GPIO pin can be driven as an output
                                                                 pin if GPIO_BIT_CFG()[PIN_SEL] selects GPIO_PIN_SEL_E::GPIO_SW. [TX_OE] is only
                                                                 used along with GPIO_TX_SET or GPIO_TX_CLR, and [TX_OE] function is before
                                                                 GPIO_BIT_CFG()[PIN_SEL] mux. */
#else /* Word 0 - Little Endian */
        uint64_t tx_oe                 : 1;  /**< [  0:  0](R/W) Transmit output enable. When set to 1, the GPIO pin can be driven as an output
                                                                 pin if GPIO_BIT_CFG()[PIN_SEL] selects GPIO_PIN_SEL_E::GPIO_SW. [TX_OE] is only
                                                                 used along with GPIO_TX_SET or GPIO_TX_CLR, and [TX_OE] function is before
                                                                 GPIO_BIT_CFG()[PIN_SEL] mux. */
        uint64_t pin_xor               : 1;  /**< [  1:  1](R/W) GPIO data inversion. When set, inverts the receiving or transmitting GPIO signal.
                                                                 For GPIO output, this inversion is after all GPIO [PIN_SEL] muxes. This inversion function
                                                                 is applicable to any GPIO output mux signals, also used to control GPIO_RX_DAT.
                                                                 For GPIO input, this inversion is before the GPIO [PIN_SEL] muxes, as used to control
                                                                 GPIO interrupts. */
        uint64_t int_en                : 1;  /**< [  2:  2](R/W) Pin controls interrupt.

                                                                 If set, assertions of this pin after [PIN_XOR] will set GPIO_INTR()[INTR].

                                                                 If set and [INT_TYPE] is clear (level-sensitive), deassertions of this pin
                                                                 after [PIN_XOR] will clear GPIO_INTR()[INTR].

                                                                 This does NOT control if interrupts are enabled towards the MSI-X vector,
                                                                 for that see GPIO_INTR()[INTR_ENA_W1S]. */
        uint64_t int_type              : 1;  /**< [  3:  3](R/W) Type of interrupt when pin is an input and [INT_EN] set. When set, rising edge
                                                                 interrupt, else level interrupt. The GPIO signal used to generate interrupt is after
                                                                 the filter and after the XOR inverter. */
        uint64_t fil_cnt               : 4;  /**< [  7:  4](R/W) Filter count. Specifies the number of consecutive samples ([FIL_CNT]+1) to change state.
                                                                 Zero to disable the filter.
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t fil_sel               : 4;  /**< [ 11:  8](R/W) Filter select. Global counter bit-select (controls sample rate).
                                                                 Filter and XOR inverter are also applicable to GPIO input muxing signals and interrupts. */
        uint64_t tx_od                 : 1;  /**< [ 12: 12](R/W) GPIO output open-drain conversion. This function is after the [PIN_SEL]
                                                                 multiplexing, [PIN_XOR] inverter, and [BLINK_EN] activity filter.
                                                                 When set, the pin output will connect to zero, and pin enable
                                                                 will connect to original pin output. With both [TX_OD] and [PIN_XOR] set, a transmit
                                                                 of 1 will tristate the pin output driver to achieve open-drain function
                                                                 with additional pullup on board. */
        uint64_t blink_en              : 2;  /**< [ 14: 13](R/W) GPIO pin output blink filter enable. This function is after the [PIN_SEL]
                                                                 multiplexing but before the [PIN_XOR] inverter and [TX_OD] overdriver
                                                                 conversion. When blink filter is enabled, the pin output will generate blinking
                                                                 pattern based on configuration of GPIO_BLINK_CFG.
                                                                 0x0 = Disable blink filter.
                                                                 0x1 = Enable blink filter based on the start of activity.
                                                                 0x2 = Enable blink filter based on the end of activity, essentially based on
                                                                       inversion of blink filter's input.
                                                                 0x3 = Disable blink filter. */
        uint64_t reserved_15           : 1;
        uint64_t pin_sel               : 11; /**< [ 26: 16](R/W) Selects which signal is reported to GPIO output, or which signal GPIO input need
                                                                 to connect. Each GPIO pin can be configured either input-only, output only or
                                                                 input/output depending on function selected, as enumerated by
                                                                 GPIO_PIN_SEL_E (see also notes in that enumeration).
                                                                 For GPIO input selects, the GPIO signal used is after glitch
                                                                 filter and XOR inverter (GPIO_BIT_CFG()[PIN_XOR]). */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } cn9;
};
typedef union cavm_gpio_bit_cfgx cavm_gpio_bit_cfgx_t;

static inline uint64_t CAVM_GPIO_BIT_CFGX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_BIT_CFGX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CN81XX) && (a<=47))
        return 0x803000000400ll + 8ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_CN83XX) && (a<=79))
        return 0x803000000400ll + 8ll * ((a) & 0x7f);
    if (cavm_is_model(OCTEONTX_CN96XX) && (a<=63))
        return 0x803000000400ll + 8ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_CN98XX) && (a<=83))
        return 0x803000000400ll + 8ll * ((a) & 0x7f);
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=63))
        return 0x803000000400ll + 8ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=63))
        return 0x803000000400ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("GPIO_BIT_CFGX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_BIT_CFGX(a) cavm_gpio_bit_cfgx_t
#define bustype_CAVM_GPIO_BIT_CFGX(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_BIT_CFGX(a) "GPIO_BIT_CFGX"
#define device_bar_CAVM_GPIO_BIT_CFGX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_BIT_CFGX(a) (a)
#define arguments_CAVM_GPIO_BIT_CFGX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_bit_permit#
 *
 * GPIO Bit Permit Register
 * This register determines which requestor(s) are permitted to access which GPIO pins.
 *
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 * (That is, only the GPIO_PERMIT permitted agent can change the permission settings of
 * all requestors.)
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_bit_permitx
{
    uint64_t u;
    struct cavm_gpio_bit_permitx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t permitdis             : 4;  /**< [  3:  0](R/W) Each bit, if set, disables the given requestor from accessing the corresponding pin.
                                                                 If a disabled requestor makes a request, the access becomes read-zero/write ignored.
                                                                   \<0\> = Disable APs (non MCP/SCP) secure world from accessing the pin.
                                                                   \<1\> = Disable APs (non MCP/SCP) nonsecure world from accessing the pin.
                                                                   \<2\> = Disable XCP0 (SCP) from accessing the pin.
                                                                   \<3\> = Disable XCP1 (MCP) from accessing the pin. */
#else /* Word 0 - Little Endian */
        uint64_t permitdis             : 4;  /**< [  3:  0](R/W) Each bit, if set, disables the given requestor from accessing the corresponding pin.
                                                                 If a disabled requestor makes a request, the access becomes read-zero/write ignored.
                                                                   \<0\> = Disable APs (non MCP/SCP) secure world from accessing the pin.
                                                                   \<1\> = Disable APs (non MCP/SCP) nonsecure world from accessing the pin.
                                                                   \<2\> = Disable XCP0 (SCP) from accessing the pin.
                                                                   \<3\> = Disable XCP1 (MCP) from accessing the pin. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_bit_permitx_s cn; */
};
typedef union cavm_gpio_bit_permitx cavm_gpio_bit_permitx_t;

static inline uint64_t CAVM_GPIO_BIT_PERMITX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_BIT_PERMITX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CN96XX) && (a<=63))
        return 0x803000002000ll + 8ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_CN98XX) && (a<=83))
        return 0x803000002000ll + 8ll * ((a) & 0x7f);
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=63))
        return 0x803000002000ll + 8ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=63))
        return 0x803000002000ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("GPIO_BIT_PERMITX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_BIT_PERMITX(a) cavm_gpio_bit_permitx_t
#define bustype_CAVM_GPIO_BIT_PERMITX(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_BIT_PERMITX(a) "GPIO_BIT_PERMITX"
#define device_bar_CAVM_GPIO_BIT_PERMITX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_BIT_PERMITX(a) (a)
#define arguments_CAVM_GPIO_BIT_PERMITX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_blink_cfg
 *
 * GPIO Output Blinker Configuration Register
 * This register configures the blink generator.
 *
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_blink_cfg
{
    uint64_t u;
    struct cavm_gpio_blink_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t force_off             : 4;  /**< [ 15: 12](R/W) Force activity off time. The minimum amount of time to disable the activity indicator if
                                                                 it has been continually enabled for the [MAX_ON] time.
                                                                 0x0 = No minimum.
                                                                 0x1 = 1/8 second.
                                                                 ...
                                                                 0xF = 15/8 seconds. */
        uint64_t max_on                : 4;  /**< [ 11:  8](R/W) Maximum activity on time. The maximum amount of time to enable the activity indicator.
                                                                 0x0 = No maximum.
                                                                 0x1 = 1/4 second.
                                                                 ...
                                                                 0xF = 15/4 seconds. */
        uint64_t stretch_off           : 4;  /**< [  7:  4](R/W) Stretch activity off. The minimum amount of time to disable the activity indicator.
                                                                 0x0 = No minimum.
                                                                 0x1 = 1/64 second.
                                                                 ...
                                                                 0xF = 15/64 seconds. */
        uint64_t stretch_on            : 4;  /**< [  3:  0](R/W) Stretch activity on. The minimum amount of time to enable the activity indicator.
                                                                 0x0 = 1/64 second.
                                                                 0x1 = 2/64 second.
                                                                 ...
                                                                 0xF = 16/64 seconds. */
#else /* Word 0 - Little Endian */
        uint64_t stretch_on            : 4;  /**< [  3:  0](R/W) Stretch activity on. The minimum amount of time to enable the activity indicator.
                                                                 0x0 = 1/64 second.
                                                                 0x1 = 2/64 second.
                                                                 ...
                                                                 0xF = 16/64 seconds. */
        uint64_t stretch_off           : 4;  /**< [  7:  4](R/W) Stretch activity off. The minimum amount of time to disable the activity indicator.
                                                                 0x0 = No minimum.
                                                                 0x1 = 1/64 second.
                                                                 ...
                                                                 0xF = 15/64 seconds. */
        uint64_t max_on                : 4;  /**< [ 11:  8](R/W) Maximum activity on time. The maximum amount of time to enable the activity indicator.
                                                                 0x0 = No maximum.
                                                                 0x1 = 1/4 second.
                                                                 ...
                                                                 0xF = 15/4 seconds. */
        uint64_t force_off             : 4;  /**< [ 15: 12](R/W) Force activity off time. The minimum amount of time to disable the activity indicator if
                                                                 it has been continually enabled for the [MAX_ON] time.
                                                                 0x0 = No minimum.
                                                                 0x1 = 1/8 second.
                                                                 ...
                                                                 0xF = 15/8 seconds. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_blink_cfg_s cn; */
};
typedef union cavm_gpio_blink_cfg cavm_gpio_blink_cfg_t;

#define CAVM_GPIO_BLINK_CFG CAVM_GPIO_BLINK_CFG_FUNC()
static inline uint64_t CAVM_GPIO_BLINK_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_BLINK_CFG_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000001440ll;
    __cavm_csr_fatal("GPIO_BLINK_CFG", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_BLINK_CFG cavm_gpio_blink_cfg_t
#define bustype_CAVM_GPIO_BLINK_CFG CSR_TYPE_NCB
#define basename_CAVM_GPIO_BLINK_CFG "GPIO_BLINK_CFG"
#define device_bar_CAVM_GPIO_BLINK_CFG 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_BLINK_CFG 0
#define arguments_CAVM_GPIO_BLINK_CFG -1,-1,-1,-1

/**
 * Register (NCB) gpio_blink_freq
 *
 * GPIO Blink Clock Register
 * This register configures the blink generator.
 *
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_blink_freq
{
    uint64_t u;
    struct cavm_gpio_blink_freq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t div                   : 27; /**< [ 26:  0](R/W) Number of 100 MHz reference clocks in 1/64th of a second. */
#else /* Word 0 - Little Endian */
        uint64_t div                   : 27; /**< [ 26:  0](R/W) Number of 100 MHz reference clocks in 1/64th of a second. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_blink_freq_s cn; */
};
typedef union cavm_gpio_blink_freq cavm_gpio_blink_freq_t;

#define CAVM_GPIO_BLINK_FREQ CAVM_GPIO_BLINK_FREQ_FUNC()
static inline uint64_t CAVM_GPIO_BLINK_FREQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_BLINK_FREQ_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000001448ll;
    __cavm_csr_fatal("GPIO_BLINK_FREQ", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_BLINK_FREQ cavm_gpio_blink_freq_t
#define bustype_CAVM_GPIO_BLINK_FREQ CSR_TYPE_NCB
#define basename_CAVM_GPIO_BLINK_FREQ "GPIO_BLINK_FREQ"
#define device_bar_CAVM_GPIO_BLINK_FREQ 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_BLINK_FREQ 0
#define arguments_CAVM_GPIO_BLINK_FREQ -1,-1,-1,-1

/**
 * Register (NCB) gpio_cer_err_w1c
 *
 * GPIO Central Error Write-One-to-Clear Register
 */
union cavm_gpio_cer_err_w1c
{
    uint64_t u;
    struct cavm_gpio_cer_err_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t caterr                : 1;  /**< [  3:  3](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_CATERR output, to indicate a
                                                                 catastrophic error to the BMC. */
        uint64_t err2                  : 1;  /**< [  2:  2](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR2 output, to indicate an error to the BMC. */
        uint64_t err1                  : 1;  /**< [  1:  1](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR1 output, to indicate an error to the BMC. */
        uint64_t err0                  : 1;  /**< [  0:  0](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR0 GPIO output, to indicate an error to the BMC. */
#else /* Word 0 - Little Endian */
        uint64_t err0                  : 1;  /**< [  0:  0](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR0 GPIO output, to indicate an error to the BMC. */
        uint64_t err1                  : 1;  /**< [  1:  1](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR1 output, to indicate an error to the BMC. */
        uint64_t err2                  : 1;  /**< [  2:  2](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR2 output, to indicate an error to the BMC. */
        uint64_t caterr                : 1;  /**< [  3:  3](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_CATERR output, to indicate a
                                                                 catastrophic error to the BMC. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_cer_err_w1c_s cn; */
};
typedef union cavm_gpio_cer_err_w1c cavm_gpio_cer_err_w1c_t;

#define CAVM_GPIO_CER_ERR_W1C CAVM_GPIO_CER_ERR_W1C_FUNC()
static inline uint64_t CAVM_GPIO_CER_ERR_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_CER_ERR_W1C_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000001608ll;
    __cavm_csr_fatal("GPIO_CER_ERR_W1C", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_CER_ERR_W1C cavm_gpio_cer_err_w1c_t
#define bustype_CAVM_GPIO_CER_ERR_W1C CSR_TYPE_NCB
#define basename_CAVM_GPIO_CER_ERR_W1C "GPIO_CER_ERR_W1C"
#define device_bar_CAVM_GPIO_CER_ERR_W1C 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_CER_ERR_W1C 0
#define arguments_CAVM_GPIO_CER_ERR_W1C -1,-1,-1,-1

/**
 * Register (NCB) gpio_cer_err_w1s
 *
 * GPIO Central Error Write-One-to-Set Register
 * This register report CER Errors to GPIO pins.
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_cer_err_w1s
{
    uint64_t u;
    struct cavm_gpio_cer_err_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t caterr                : 1;  /**< [  3:  3](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_CATERR output, to indicate a
                                                                 catastrophic error to the BMC. */
        uint64_t err2                  : 1;  /**< [  2:  2](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR2 output, to indicate an error to the BMC. */
        uint64_t err1                  : 1;  /**< [  1:  1](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR1 output, to indicate an error to the BMC. */
        uint64_t err0                  : 1;  /**< [  0:  0](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR0 GPIO output, to indicate an error to the BMC. */
#else /* Word 0 - Little Endian */
        uint64_t err0                  : 1;  /**< [  0:  0](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR0 GPIO output, to indicate an error to the BMC. */
        uint64_t err1                  : 1;  /**< [  1:  1](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR1 output, to indicate an error to the BMC. */
        uint64_t err2                  : 1;  /**< [  2:  2](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_ERR2 output, to indicate an error to the BMC. */
        uint64_t caterr                : 1;  /**< [  3:  3](R/W1S) Set the selectable-GPIO GPIO_PIN_SEL_E::CER_CATERR output, to indicate a
                                                                 catastrophic error to the BMC. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_cer_err_w1s_s cn; */
};
typedef union cavm_gpio_cer_err_w1s cavm_gpio_cer_err_w1s_t;

#define CAVM_GPIO_CER_ERR_W1S CAVM_GPIO_CER_ERR_W1S_FUNC()
static inline uint64_t CAVM_GPIO_CER_ERR_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_CER_ERR_W1S_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000001600ll;
    __cavm_csr_fatal("GPIO_CER_ERR_W1S", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_CER_ERR_W1S cavm_gpio_cer_err_w1s_t
#define bustype_CAVM_GPIO_CER_ERR_W1S CSR_TYPE_NCB
#define basename_CAVM_GPIO_CER_ERR_W1S "GPIO_CER_ERR_W1S"
#define device_bar_CAVM_GPIO_CER_ERR_W1S 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_CER_ERR_W1S 0
#define arguments_CAVM_GPIO_CER_ERR_W1S -1,-1,-1,-1

/**
 * Register (NCB) gpio_clk_gen#
 *
 * GPIO Clock Generator Registers
 * This register configures the clock generators. The number of generators is
 * discoverable in GPIO_CONST[CLKGEN].
 *
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_clk_genx
{
    uint64_t u;
    struct cavm_gpio_clk_genx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t high                  : 32; /**< [ 63: 32](R/W) Determines the high period of the GPIO clock generator. [HIGH] defines the
                                                                 number of coprocessor clocks in GPIO clock high period. Writing [HIGH] = 0
                                                                 changes clock generator back original 50% duty cycle, which is backward
                                                                 compatible. */
        uint64_t n                     : 32; /**< [ 31:  0](R/W) Determines the frequency of the GPIO clock generator. N should be less than or equal to
                                                                 2^31-1.
                                                                 The frequency of the GPIO clock generator equals the coprocessor-clock frequency times N
                                                                 divided by 2^32.
                                                                 Writing N = 0x0 stops the clock generator. */
#else /* Word 0 - Little Endian */
        uint64_t n                     : 32; /**< [ 31:  0](R/W) Determines the frequency of the GPIO clock generator. N should be less than or equal to
                                                                 2^31-1.
                                                                 The frequency of the GPIO clock generator equals the coprocessor-clock frequency times N
                                                                 divided by 2^32.
                                                                 Writing N = 0x0 stops the clock generator. */
        uint64_t high                  : 32; /**< [ 63: 32](R/W) Determines the high period of the GPIO clock generator. [HIGH] defines the
                                                                 number of coprocessor clocks in GPIO clock high period. Writing [HIGH] = 0
                                                                 changes clock generator back original 50% duty cycle, which is backward
                                                                 compatible. */
#endif /* Word 0 - End */
    } s;
    struct cavm_gpio_clk_genx_cn8
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t n                     : 32; /**< [ 31:  0](R/W) Determines the frequency of the GPIO clock generator. N should be less than or equal to
                                                                 2^31-1.
                                                                 The frequency of the GPIO clock generator equals the coprocessor-clock frequency times N
                                                                 divided by 2^32.
                                                                 Writing N = 0x0 stops the clock generator. */
#else /* Word 0 - Little Endian */
        uint64_t n                     : 32; /**< [ 31:  0](R/W) Determines the frequency of the GPIO clock generator. N should be less than or equal to
                                                                 2^31-1.
                                                                 The frequency of the GPIO clock generator equals the coprocessor-clock frequency times N
                                                                 divided by 2^32.
                                                                 Writing N = 0x0 stops the clock generator. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn8;
    struct cavm_gpio_clk_genx_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t high                  : 32; /**< [ 63: 32](R/W) Determines the high period of the GPIO clock generator. [HIGH] defines the
                                                                 number of coprocessor clocks in GPIO clock high period. Writing [HIGH] = 0
                                                                 changes clock generator back original 50% duty cycle, which is backward
                                                                 compatible. */
        uint64_t n                     : 32; /**< [ 31:  0](R/W) Determines the frequency of the GPIO clock generator. [N] should be less than or
                                                                 equal to 2^31-1. The frequency of the GPIO clock generator equals the
                                                                 coprocessor-clock frequency times [N] divided by 2^32. Writing [N] = 0x0 stops
                                                                 the clock generator. */
#else /* Word 0 - Little Endian */
        uint64_t n                     : 32; /**< [ 31:  0](R/W) Determines the frequency of the GPIO clock generator. [N] should be less than or
                                                                 equal to 2^31-1. The frequency of the GPIO clock generator equals the
                                                                 coprocessor-clock frequency times [N] divided by 2^32. Writing [N] = 0x0 stops
                                                                 the clock generator. */
        uint64_t high                  : 32; /**< [ 63: 32](R/W) Determines the high period of the GPIO clock generator. [HIGH] defines the
                                                                 number of coprocessor clocks in GPIO clock high period. Writing [HIGH] = 0
                                                                 changes clock generator back original 50% duty cycle, which is backward
                                                                 compatible. */
#endif /* Word 0 - End */
    } cn9;
};
typedef union cavm_gpio_clk_genx cavm_gpio_clk_genx_t;

static inline uint64_t CAVM_GPIO_CLK_GENX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_CLK_GENX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CN8XXX) && (a<=3))
        return 0x803000000040ll + 8ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_CN9XXX) && (a<=7))
        return 0x803000001800ll + 8ll * ((a) & 0x7);
    __cavm_csr_fatal("GPIO_CLK_GENX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_CLK_GENX(a) cavm_gpio_clk_genx_t
#define bustype_CAVM_GPIO_CLK_GENX(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_CLK_GENX(a) "GPIO_CLK_GENX"
#define device_bar_CAVM_GPIO_CLK_GENX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_CLK_GENX(a) (a)
#define arguments_CAVM_GPIO_CLK_GENX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_clk_synce#
 *
 * GPIO Clock SyncE Registers
 * Certain SerDes may be configured as a clock source. The GPIO block can support up to two
 * unique clocks to send out any GPIO pin as configured when GPIO_BIT_CFG()[PIN_SEL] =
 * GPIO_PIN_SEL_E::GPIO_CLK_SYNCE(0..1). The clock can be divided by 20, 40, 80 or 160
 * of the selected SerDes clock. Legal values are based on the number of SerDes.
 *
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_clk_syncex
{
    uint64_t u;
    struct cavm_gpio_clk_syncex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSER(0..3) to select from. */
        uint64_t reserved_4_7          : 4;
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the GSER SerDes recovered clock to create the
                                                                 output clock. The maximum supported GPIO output frequency is 125 MHz.
                                                                 0x0 = Divide by 20.
                                                                 0x1 = Divide by 40.
                                                                 0x2 = Divide by 80.
                                                                 0x3 = Divide by 160. */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the GSER selected with [QLM_SEL] to use as the GPIO
                                                                 internal QLMx clock. */
#else /* Word 0 - Little Endian */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the GSER selected with [QLM_SEL] to use as the GPIO
                                                                 internal QLMx clock. */
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the GSER SerDes recovered clock to create the
                                                                 output clock. The maximum supported GPIO output frequency is 125 MHz.
                                                                 0x0 = Divide by 20.
                                                                 0x1 = Divide by 40.
                                                                 0x2 = Divide by 80.
                                                                 0x3 = Divide by 160. */
        uint64_t reserved_4_7          : 4;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSER(0..3) to select from. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_clk_syncex_s cn8; */
    /* struct cavm_gpio_clk_syncex_s cn81xx; */
    struct cavm_gpio_clk_syncex_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSER(0..6) to select from. */
        uint64_t reserved_4_7          : 4;
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the GSER SerDes recovered clock to create the
                                                                 output clock. The maximum supported GPIO output frequency is 125 MHz.
                                                                 0x0 = Divide by 20.
                                                                 0x1 = Divide by 40.
                                                                 0x2 = Divide by 80.
                                                                 0x3 = Divide by 160. */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the GSER selected with [QLM_SEL] to use as the GPIO
                                                                 internal QLMx clock.  Note that GSER 0..3 have four selections each while
                                                                 GSER 4..6 have two selections each. */
#else /* Word 0 - Little Endian */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the GSER selected with [QLM_SEL] to use as the GPIO
                                                                 internal QLMx clock.  Note that GSER 0..3 have four selections each while
                                                                 GSER 4..6 have two selections each. */
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the GSER SerDes recovered clock to create the
                                                                 output clock. The maximum supported GPIO output frequency is 125 MHz.
                                                                 0x0 = Divide by 20.
                                                                 0x1 = Divide by 40.
                                                                 0x2 = Divide by 80.
                                                                 0x3 = Divide by 160. */
        uint64_t reserved_4_7          : 4;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSER(0..6) to select from. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cn83xx;
    struct cavm_gpio_clk_syncex_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSER to select from. */
        uint64_t reserved_4_7          : 4;
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the GSER SerDes recovered clock to create the
                                                                 output clock. The maximum supported GPIO output frequency is 125 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the GSER permitted with [QLM_SEL] to use as the GPIO
                                                                 internal QLMx clock.  Note that GSER 0..3 have four selections each while
                                                                 GSER 4..6 have two selections each. */
#else /* Word 0 - Little Endian */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the GSER permitted with [QLM_SEL] to use as the GPIO
                                                                 internal QLMx clock.  Note that GSER 0..3 have four selections each while
                                                                 GSER 4..6 have two selections each. */
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the GSER SerDes recovered clock to create the
                                                                 output clock. The maximum supported GPIO output frequency is 125 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t reserved_4_7          : 4;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSER to select from. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cn9;
    /* struct cavm_gpio_clk_syncex_cn9 cn96xxp1; */
    struct cavm_gpio_clk_syncex_cn96xxp3
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSERR to select from. Supported values are 6, 7 & 8. */
        uint64_t reserved_4_7          : 4;
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the SerDes recovered clock selected by [QLM_SEL]
                                                                 to create the output clock. The maximum supported GPIO output frequency is 125
                                                                 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the SerDes selected with [QLM_SEL] to use as the GPIO
                                                                 internal clock. */
#else /* Word 0 - Little Endian */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the SerDes selected with [QLM_SEL] to use as the GPIO
                                                                 internal clock. */
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the SerDes recovered clock selected by [QLM_SEL]
                                                                 to create the output clock. The maximum supported GPIO output frequency is 125
                                                                 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t reserved_4_7          : 4;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSERR to select from. Supported values are 6, 7 & 8. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cn96xxp3;
    struct cavm_gpio_clk_syncex_cn98xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSERR to select from. */
        uint64_t reserved_4_7          : 4;
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the SerDes recovered clock selected by [QLM_SEL]
                                                                 to create the output clock. The maximum supported GPIO output frequency is 125
                                                                 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the SerDes selected with [QLM_SEL] to use as the GPIO
                                                                 internal clock. */
#else /* Word 0 - Little Endian */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the SerDes selected with [QLM_SEL] to use as the GPIO
                                                                 internal clock. */
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the SerDes recovered clock selected by [QLM_SEL]
                                                                 to create the output clock. The maximum supported GPIO output frequency is 125
                                                                 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t reserved_4_7          : 4;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSERR to select from. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cn98xx;
    struct cavm_gpio_clk_syncex_cnf95xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSER to select from. */
        uint64_t reserved_4_7          : 4;
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the SerDes recovered clock selected by [QLM_SEL]
                                                                 to create the output clock. The maximum supported GPIO output frequency is 125
                                                                 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the SerDes selected with [QLM_SEL] to use as the GPIO
                                                                 internal clock. */
#else /* Word 0 - Little Endian */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the SerDes selected with [QLM_SEL] to use as the GPIO
                                                                 internal clock. */
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the SerDes recovered clock selected by [QLM_SEL]
                                                                 to create the output clock. The maximum supported GPIO output frequency is 125
                                                                 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t reserved_4_7          : 4;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which GSER to select from. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cnf95xxp1;
    /* struct cavm_gpio_clk_syncex_cn98xx cnf95xxp2; */
    struct cavm_gpio_clk_syncex_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which Ethernet/CPRI Serdes to select from.
                                                                 0 = GSERR0.
                                                                 1..5 = GSERC(0..4). */
        uint64_t reserved_4_7          : 4;
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the SerDes recovered clock selected by [QLM_SEL]
                                                                 to create the output clock. The maximum supported GPIO output frequency is 125
                                                                 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the SerDes selected with [QLM_SEL] to use as the GPIO
                                                                 internal clock. */
#else /* Word 0 - Little Endian */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Which RX lane within the SerDes selected with [QLM_SEL] to use as the GPIO
                                                                 internal clock. */
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock division of the SerDes recovered clock selected by [QLM_SEL]
                                                                 to create the output clock. The maximum supported GPIO output frequency is 125
                                                                 MHz.
                                                                 0x0 = Divide by 40.
                                                                 0x1 = Divide by 80.
                                                                 0x2 = Divide by 160.
                                                                 0x3 = Divide by 320. */
        uint64_t reserved_4_7          : 4;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which Ethernet/CPRI Serdes to select from.
                                                                 0 = GSERR0.
                                                                 1..5 = GSERC(0..4). */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_gpio_clk_syncex cavm_gpio_clk_syncex_t;

static inline uint64_t CAVM_GPIO_CLK_SYNCEX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_CLK_SYNCEX(unsigned long a)
{
    if (a<=1)
        return 0x803000000060ll + 8ll * ((a) & 0x1);
    __cavm_csr_fatal("GPIO_CLK_SYNCEX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_CLK_SYNCEX(a) cavm_gpio_clk_syncex_t
#define bustype_CAVM_GPIO_CLK_SYNCEX(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_CLK_SYNCEX(a) "GPIO_CLK_SYNCEX"
#define device_bar_CAVM_GPIO_CLK_SYNCEX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_CLK_SYNCEX(a) (a)
#define arguments_CAVM_GPIO_CLK_SYNCEX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_comp
 *
 * GPIO Compensation Register
 */
union cavm_gpio_comp
{
    uint64_t u;
    struct cavm_gpio_comp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t pctl                  : 3;  /**< [ 10:  8](R/W) GPIO bus driver PCTL. Suggested values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
        uint64_t reserved_3_7          : 5;
        uint64_t nctl                  : 3;  /**< [  2:  0](R/W) GPIO bus driver NCTL. Suggested values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
#else /* Word 0 - Little Endian */
        uint64_t nctl                  : 3;  /**< [  2:  0](R/W) GPIO bus driver NCTL. Suggested values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
        uint64_t reserved_3_7          : 5;
        uint64_t pctl                  : 3;  /**< [ 10:  8](R/W) GPIO bus driver PCTL. Suggested values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_comp_s cn; */
};
typedef union cavm_gpio_comp cavm_gpio_comp_t;

#define CAVM_GPIO_COMP CAVM_GPIO_COMP_FUNC()
static inline uint64_t CAVM_GPIO_COMP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_COMP_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN8XXX))
        return 0x803000000080ll;
    __cavm_csr_fatal("GPIO_COMP", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_COMP cavm_gpio_comp_t
#define bustype_CAVM_GPIO_COMP CSR_TYPE_NCB
#define basename_CAVM_GPIO_COMP "GPIO_COMP"
#define device_bar_CAVM_GPIO_COMP 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_COMP 0
#define arguments_CAVM_GPIO_COMP -1,-1,-1,-1

/**
 * Register (NCB) gpio_const
 *
 * GPIO Constants Register
 * This register contains constants for software discovery.
 *
 * This register is accessible to all requestors (regardless of GPIO_PERMIT).
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_const
{
    uint64_t u;
    struct cavm_gpio_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t clkgen                : 4;  /**< [ 19: 16](RO) Number of clock generators in GPIO. */
        uint64_t pp                    : 8;  /**< [ 15:  8](RO) Number of PP vectors in GPIO_INT_VEC_E::MC_INTR_PP(). */
        uint64_t gpios                 : 8;  /**< [  7:  0](RO) Number of GPIOs implemented. */
#else /* Word 0 - Little Endian */
        uint64_t gpios                 : 8;  /**< [  7:  0](RO) Number of GPIOs implemented. */
        uint64_t pp                    : 8;  /**< [ 15:  8](RO) Number of PP vectors in GPIO_INT_VEC_E::MC_INTR_PP(). */
        uint64_t clkgen                : 4;  /**< [ 19: 16](RO) Number of clock generators in GPIO. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    struct cavm_gpio_const_cn8
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t pp                    : 8;  /**< [ 15:  8](RO) Number of PP vectors in GPIO_INT_VEC_E::MC_INTR_PP(). */
        uint64_t gpios                 : 8;  /**< [  7:  0](RO) Number of GPIOs implemented. */
#else /* Word 0 - Little Endian */
        uint64_t gpios                 : 8;  /**< [  7:  0](RO) Number of GPIOs implemented. */
        uint64_t pp                    : 8;  /**< [ 15:  8](RO) Number of PP vectors in GPIO_INT_VEC_E::MC_INTR_PP(). */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn8;
    /* struct cavm_gpio_const_s cn9; */
};
typedef union cavm_gpio_const cavm_gpio_const_t;

#define CAVM_GPIO_CONST CAVM_GPIO_CONST_FUNC()
static inline uint64_t CAVM_GPIO_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_CONST_FUNC(void)
{
    return 0x803000000090ll;
}

#define typedef_CAVM_GPIO_CONST cavm_gpio_const_t
#define bustype_CAVM_GPIO_CONST CSR_TYPE_NCB
#define basename_CAVM_GPIO_CONST "GPIO_CONST"
#define device_bar_CAVM_GPIO_CONST 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_CONST 0
#define arguments_CAVM_GPIO_CONST -1,-1,-1,-1

/**
 * Register (NCB) gpio_intr#
 *
 * GPIO Bit Interrupt Registers
 * Each register provides interrupt information for the corresponding GPIO pin.
 * GPIO_INTR() interrupts can be level or edge interrupts depending on GPIO_BIT_CFG()[INT_TYPE].
 *
 * Each index is only accessible to the requestor(s) permitted with GPIO_BIT_PERMIT().
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_intrx
{
    uint64_t u;
    struct cavm_gpio_intrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t intr_ena_w1s          : 1;  /**< [  3:  3](R/W1S) GPIO signaled interrupt enable. Write one to set interrupt enable.
                                                                 [INTR_ENA_W1S] and [INTR_ENA_W1C] both read the interrupt enable state. */
        uint64_t intr_ena_w1c          : 1;  /**< [  2:  2](R/W1C) GPIO signaled interrupt enable. Write one to clear interrupt enable.
                                                                 [INTR_ENA_W1S] and [INTR_ENA_W1C] both read the interrupt enable state. */
        uint64_t intr_w1s              : 1;  /**< [  1:  1](R/W1S/H) GPIO signaled interrupt. If interrupts are edge-sensitive, write one to set, otherwise
                                                                 will clear automatically when GPIO pin de-asserts.
                                                                 [INTR_W1S] and [INTR] both read the interrupt state. */
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1C/H) GPIO signaled interrupt. If interrupts are edge-sensitive, write one to clear, otherwise
                                                                 will clear automatically when GPIO pin de-asserts.
                                                                 [INTR_W1S] and [INTR] both read the interrupt state.
                                                                 An interrupt set event is sent when [INTR_ENA_W1S] reads as set. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1C/H) GPIO signaled interrupt. If interrupts are edge-sensitive, write one to clear, otherwise
                                                                 will clear automatically when GPIO pin de-asserts.
                                                                 [INTR_W1S] and [INTR] both read the interrupt state.
                                                                 An interrupt set event is sent when [INTR_ENA_W1S] reads as set. */
        uint64_t intr_w1s              : 1;  /**< [  1:  1](R/W1S/H) GPIO signaled interrupt. If interrupts are edge-sensitive, write one to set, otherwise
                                                                 will clear automatically when GPIO pin de-asserts.
                                                                 [INTR_W1S] and [INTR] both read the interrupt state. */
        uint64_t intr_ena_w1c          : 1;  /**< [  2:  2](R/W1C) GPIO signaled interrupt enable. Write one to clear interrupt enable.
                                                                 [INTR_ENA_W1S] and [INTR_ENA_W1C] both read the interrupt enable state. */
        uint64_t intr_ena_w1s          : 1;  /**< [  3:  3](R/W1S) GPIO signaled interrupt enable. Write one to set interrupt enable.
                                                                 [INTR_ENA_W1S] and [INTR_ENA_W1C] both read the interrupt enable state. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_intrx_s cn; */
};
typedef union cavm_gpio_intrx cavm_gpio_intrx_t;

static inline uint64_t CAVM_GPIO_INTRX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_INTRX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CN81XX) && (a<=47))
        return 0x803000000800ll + 8ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_CN83XX) && (a<=79))
        return 0x803000000800ll + 8ll * ((a) & 0x7f);
    if (cavm_is_model(OCTEONTX_CN96XX) && (a<=63))
        return 0x803000000800ll + 8ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_CN98XX) && (a<=83))
        return 0x803000000800ll + 8ll * ((a) & 0x7f);
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=63))
        return 0x803000000800ll + 8ll * ((a) & 0x3f);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=63))
        return 0x803000000800ll + 8ll * ((a) & 0x3f);
    __cavm_csr_fatal("GPIO_INTRX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_INTRX(a) cavm_gpio_intrx_t
#define bustype_CAVM_GPIO_INTRX(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_INTRX(a) "GPIO_INTRX"
#define device_bar_CAVM_GPIO_INTRX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_INTRX(a) (a)
#define arguments_CAVM_GPIO_INTRX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_io_ctl
 *
 * GPIO I/O Control Register
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_io_ctl
{
    uint64_t u;
    struct cavm_gpio_io_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t drive3                : 2;  /**< [ 15: 14](R/W) GPIO\<83:72\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_13           : 1;
        uint64_t slew3                 : 1;  /**< [ 12: 12](R/W) GPIO\<83:72\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t drive2                : 2;  /**< [ 11: 10](R/W) GPIO\<63:48\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_9            : 1;
        uint64_t slew2                 : 1;  /**< [  8:  8](R/W) GPIO\<63:48\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t drive1                : 2;  /**< [  7:  6](R/W) GPIO\<47:24\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_5            : 1;
        uint64_t slew1                 : 1;  /**< [  4:  4](R/W) GPIO\<47:24\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t drive0                : 2;  /**< [  3:  2](R/W) GPIO\<23:0\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_1            : 1;
        uint64_t slew0                 : 1;  /**< [  0:  0](R/W) GPIO\<23:0\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
#else /* Word 0 - Little Endian */
        uint64_t slew0                 : 1;  /**< [  0:  0](R/W) GPIO\<23:0\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_1            : 1;
        uint64_t drive0                : 2;  /**< [  3:  2](R/W) GPIO\<23:0\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t slew1                 : 1;  /**< [  4:  4](R/W) GPIO\<47:24\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_5            : 1;
        uint64_t drive1                : 2;  /**< [  7:  6](R/W) GPIO\<47:24\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t slew2                 : 1;  /**< [  8:  8](R/W) GPIO\<63:48\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_9            : 1;
        uint64_t drive2                : 2;  /**< [ 11: 10](R/W) GPIO\<63:48\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t slew3                 : 1;  /**< [ 12: 12](R/W) GPIO\<83:72\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_13           : 1;
        uint64_t drive3                : 2;  /**< [ 15: 14](R/W) GPIO\<83:72\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_io_ctl_s cn9; */
    struct cavm_gpio_io_ctl_cn96xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t drive2                : 2;  /**< [ 11: 10](R/W) GPIO\<63:48\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_9            : 1;
        uint64_t slew2                 : 1;  /**< [  8:  8](R/W) GPIO\<63:48\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t drive1                : 2;  /**< [  7:  6](R/W) GPIO\<47:24\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_5            : 1;
        uint64_t slew1                 : 1;  /**< [  4:  4](R/W) GPIO\<47:24\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t drive0                : 2;  /**< [  3:  2](R/W) GPIO\<23:0\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_1            : 1;
        uint64_t slew0                 : 1;  /**< [  0:  0](R/W) GPIO\<23:0\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
#else /* Word 0 - Little Endian */
        uint64_t slew0                 : 1;  /**< [  0:  0](R/W) GPIO\<23:0\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_1            : 1;
        uint64_t drive0                : 2;  /**< [  3:  2](R/W) GPIO\<23:0\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t slew1                 : 1;  /**< [  4:  4](R/W) GPIO\<47:24\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_5            : 1;
        uint64_t drive1                : 2;  /**< [  7:  6](R/W) GPIO\<47:24\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t slew2                 : 1;  /**< [  8:  8](R/W) GPIO\<63:48\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_9            : 1;
        uint64_t drive2                : 2;  /**< [ 11: 10](R/W) GPIO\<63:48\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cn96xx;
    struct cavm_gpio_io_ctl_cn98xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t drive3                : 2;  /**< [ 15: 14](R/W) GPIO\<83:72\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_13           : 1;
        uint64_t slew3                 : 1;  /**< [ 12: 12](R/W) GPIO\<83:72\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t drive2                : 2;  /**< [ 11: 10](R/W) GPIO\<71:48\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_9            : 1;
        uint64_t slew2                 : 1;  /**< [  8:  8](R/W) GPIO\<71:48\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t drive1                : 2;  /**< [  7:  6](R/W) GPIO\<47:24\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_5            : 1;
        uint64_t slew1                 : 1;  /**< [  4:  4](R/W) GPIO\<47:24\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t drive0                : 2;  /**< [  3:  2](R/W) GPIO\<23:0\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_1            : 1;
        uint64_t slew0                 : 1;  /**< [  0:  0](R/W) GPIO\<23:0\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
#else /* Word 0 - Little Endian */
        uint64_t slew0                 : 1;  /**< [  0:  0](R/W) GPIO\<23:0\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_1            : 1;
        uint64_t drive0                : 2;  /**< [  3:  2](R/W) GPIO\<23:0\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t slew1                 : 1;  /**< [  4:  4](R/W) GPIO\<47:24\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_5            : 1;
        uint64_t drive1                : 2;  /**< [  7:  6](R/W) GPIO\<47:24\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t slew2                 : 1;  /**< [  8:  8](R/W) GPIO\<71:48\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_9            : 1;
        uint64_t drive2                : 2;  /**< [ 11: 10](R/W) GPIO\<71:48\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t slew3                 : 1;  /**< [ 12: 12](R/W) GPIO\<83:72\> pin output slew rate control.
                                                                 0 = Low slew rate.
                                                                 1 = High slew rate. */
        uint64_t reserved_13           : 1;
        uint64_t drive3                : 2;  /**< [ 15: 14](R/W) GPIO\<83:72\> pin output drive strength.
                                                                 0x0 = 2 mA.
                                                                 0x1 = 4 mA.
                                                                 0x2 = 8 mA.
                                                                 0x3 = 16 mA. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn98xx;
    /* struct cavm_gpio_io_ctl_cn96xx cnf95xx; */
    /* struct cavm_gpio_io_ctl_cn96xx loki; */
};
typedef union cavm_gpio_io_ctl cavm_gpio_io_ctl_t;

#define CAVM_GPIO_IO_CTL CAVM_GPIO_IO_CTL_FUNC()
static inline uint64_t CAVM_GPIO_IO_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_IO_CTL_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000000080ll;
    __cavm_csr_fatal("GPIO_IO_CTL", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_IO_CTL cavm_gpio_io_ctl_t
#define bustype_CAVM_GPIO_IO_CTL CSR_TYPE_NCB
#define basename_CAVM_GPIO_IO_CTL "GPIO_IO_CTL"
#define device_bar_CAVM_GPIO_IO_CTL 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_IO_CTL 0
#define arguments_CAVM_GPIO_IO_CTL -1,-1,-1,-1

/**
 * Register (NCB) gpio_mc_intr#
 *
 * GPIO Bit Multicast Interrupt Registers
 * Each register provides interrupt multicasting for GPIO(4..7).
 *
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_mc_intrx
{
    uint64_t u;
    struct cavm_gpio_mc_intrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and MULTI_CAST
                                                                 is enabled, a GPIO assertion will set all 48 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and MULTI_CAST
                                                                 is enabled, a GPIO assertion will set all 48 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_mc_intrx_s cn8; */
    struct cavm_gpio_mc_intrx_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all 24 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all 24 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } cn9;
    struct cavm_gpio_mc_intrx_cn96xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all 24 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all 24 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn96xxp1;
    struct cavm_gpio_mc_intrx_cn96xxp3
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all 24 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the GIC, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all 24 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the GIC, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn96xxp3;
    struct cavm_gpio_mc_intrx_cn98xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all the INTR bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the GIC, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all the INTR bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the GIC, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } cn98xx;
    struct cavm_gpio_mc_intrx_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t intr                  : 6;  /**< [  5:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all 24 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the GIC, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 6;  /**< [  5:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and GPIO_MULTI_CAST[EN]
                                                                 is enabled, a GPIO assertion will set all 24 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the GIC, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cnf95xx;
    /* struct cavm_gpio_mc_intrx_cnf95xx loki; */
};
typedef union cavm_gpio_mc_intrx cavm_gpio_mc_intrx_t;

static inline uint64_t CAVM_GPIO_MC_INTRX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MC_INTRX(unsigned long a)
{
    if ((a>=4)&&(a<=7))
        return 0x803000001000ll + 8ll * ((a) & 0x7);
    __cavm_csr_fatal("GPIO_MC_INTRX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_MC_INTRX(a) cavm_gpio_mc_intrx_t
#define bustype_CAVM_GPIO_MC_INTRX(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_MC_INTRX(a) "GPIO_MC_INTRX"
#define device_bar_CAVM_GPIO_MC_INTRX(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_MC_INTRX(a) (a)
#define arguments_CAVM_GPIO_MC_INTRX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_mc_intr#_ena_w1c
 *
 * GPIO Bit Multicast Interrupt Registers
 * This register clears interrupt enable bits.
 */
union cavm_gpio_mc_intrx_ena_w1c
{
    uint64_t u;
    struct cavm_gpio_mc_intrx_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_mc_intrx_ena_w1c_s cn8; */
    struct cavm_gpio_mc_intrx_ena_w1c_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } cn9;
    struct cavm_gpio_mc_intrx_ena_w1c_cn96xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn96xx;
    /* struct cavm_gpio_mc_intrx_ena_w1c_cn9 cn98xx; */
    struct cavm_gpio_mc_intrx_ena_w1c_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t intr                  : 6;  /**< [  5:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 6;  /**< [  5:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cnf95xx;
    /* struct cavm_gpio_mc_intrx_ena_w1c_cnf95xx loki; */
};
typedef union cavm_gpio_mc_intrx_ena_w1c cavm_gpio_mc_intrx_ena_w1c_t;

static inline uint64_t CAVM_GPIO_MC_INTRX_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MC_INTRX_ENA_W1C(unsigned long a)
{
    if ((a>=4)&&(a<=7))
        return 0x803000001200ll + 8ll * ((a) & 0x7);
    __cavm_csr_fatal("GPIO_MC_INTRX_ENA_W1C", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_MC_INTRX_ENA_W1C(a) cavm_gpio_mc_intrx_ena_w1c_t
#define bustype_CAVM_GPIO_MC_INTRX_ENA_W1C(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_MC_INTRX_ENA_W1C(a) "GPIO_MC_INTRX_ENA_W1C"
#define device_bar_CAVM_GPIO_MC_INTRX_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_MC_INTRX_ENA_W1C(a) (a)
#define arguments_CAVM_GPIO_MC_INTRX_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_mc_intr#_ena_w1s
 *
 * GPIO Bit Multicast Interrupt Registers
 * This register sets interrupt enable bits.
 */
union cavm_gpio_mc_intrx_ena_w1s
{
    uint64_t u;
    struct cavm_gpio_mc_intrx_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_mc_intrx_ena_w1s_s cn8; */
    struct cavm_gpio_mc_intrx_ena_w1s_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } cn9;
    struct cavm_gpio_mc_intrx_ena_w1s_cn96xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn96xx;
    /* struct cavm_gpio_mc_intrx_ena_w1s_cn9 cn98xx; */
    struct cavm_gpio_mc_intrx_ena_w1s_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t intr                  : 6;  /**< [  5:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 6;  /**< [  5:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cnf95xx;
    /* struct cavm_gpio_mc_intrx_ena_w1s_cnf95xx loki; */
};
typedef union cavm_gpio_mc_intrx_ena_w1s cavm_gpio_mc_intrx_ena_w1s_t;

static inline uint64_t CAVM_GPIO_MC_INTRX_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MC_INTRX_ENA_W1S(unsigned long a)
{
    if ((a>=4)&&(a<=7))
        return 0x803000001300ll + 8ll * ((a) & 0x7);
    __cavm_csr_fatal("GPIO_MC_INTRX_ENA_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_MC_INTRX_ENA_W1S(a) cavm_gpio_mc_intrx_ena_w1s_t
#define bustype_CAVM_GPIO_MC_INTRX_ENA_W1S(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_MC_INTRX_ENA_W1S(a) "GPIO_MC_INTRX_ENA_W1S"
#define device_bar_CAVM_GPIO_MC_INTRX_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_MC_INTRX_ENA_W1S(a) (a)
#define arguments_CAVM_GPIO_MC_INTRX_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_mc_intr#_w1s
 *
 * GPIO Bit Multicast Interrupt Registers
 * This register sets interrupt bits.
 */
union cavm_gpio_mc_intrx_w1s
{
    uint64_t u;
    struct cavm_gpio_mc_intrx_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_mc_intrx_w1s_s cn8; */
    struct cavm_gpio_mc_intrx_w1s_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 36; /**< [ 35:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } cn9;
    struct cavm_gpio_mc_intrx_w1s_cn96xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 24; /**< [ 23:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn96xx;
    /* struct cavm_gpio_mc_intrx_w1s_cn9 cn98xx; */
    struct cavm_gpio_mc_intrx_w1s_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t intr                  : 6;  /**< [  5:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 6;  /**< [  5:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cnf95xx;
    /* struct cavm_gpio_mc_intrx_w1s_cnf95xx loki; */
};
typedef union cavm_gpio_mc_intrx_w1s cavm_gpio_mc_intrx_w1s_t;

static inline uint64_t CAVM_GPIO_MC_INTRX_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MC_INTRX_W1S(unsigned long a)
{
    if ((a>=4)&&(a<=7))
        return 0x803000001100ll + 8ll * ((a) & 0x7);
    __cavm_csr_fatal("GPIO_MC_INTRX_W1S", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_MC_INTRX_W1S(a) cavm_gpio_mc_intrx_w1s_t
#define bustype_CAVM_GPIO_MC_INTRX_W1S(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_MC_INTRX_W1S(a) "GPIO_MC_INTRX_W1S"
#define device_bar_CAVM_GPIO_MC_INTRX_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_MC_INTRX_W1S(a) (a)
#define arguments_CAVM_GPIO_MC_INTRX_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_misc_strap
 *
 * GPIO Misc Strap Value Register
 * This register contains the miscellaneous strap state.
 *
 * Miscellaneous straps are enumerated by GPIO_MISC_STRAP_PIN_E, where the value 0x0
 * corresponds to bit zero in this register.
 *
 * This register is accessible to all requestors (regardless of GPIO_PERMIT).
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_misc_strap
{
    uint64_t u;
    struct cavm_gpio_misc_strap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_63        : 46;
        uint64_t uart1_rts             : 1;  /**< [ 17: 17](RO/H) State of UART1_RTS_L pin strap sampled when DCOK asserts. */
        uint64_t uart0_rts             : 1;  /**< [ 16: 16](RO/H) State of UART0_RTS_L pin strap sampled when DCOK asserts. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t uart0_rts             : 1;  /**< [ 16: 16](RO/H) State of UART0_RTS_L pin strap sampled when DCOK asserts. */
        uint64_t uart1_rts             : 1;  /**< [ 17: 17](RO/H) State of UART1_RTS_L pin strap sampled when DCOK asserts. */
        uint64_t reserved_18_63        : 46;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_misc_strap_s cn; */
};
typedef union cavm_gpio_misc_strap cavm_gpio_misc_strap_t;

#define CAVM_GPIO_MISC_STRAP CAVM_GPIO_MISC_STRAP_FUNC()
static inline uint64_t CAVM_GPIO_MISC_STRAP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MISC_STRAP_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000000030ll;
    __cavm_csr_fatal("GPIO_MISC_STRAP", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_MISC_STRAP cavm_gpio_misc_strap_t
#define bustype_CAVM_GPIO_MISC_STRAP CSR_TYPE_NCB
#define basename_CAVM_GPIO_MISC_STRAP "GPIO_MISC_STRAP"
#define device_bar_CAVM_GPIO_MISC_STRAP 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_MISC_STRAP 0
#define arguments_CAVM_GPIO_MISC_STRAP -1,-1,-1,-1

/**
 * Register (NCB) gpio_misc_supply
 *
 * GPIO Misc Supply Value Register
 * This register contains the state of the GPIO power supplies.
 *
 * This register is accessible to all requestors (regardless of GPIO_PERMIT).
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_misc_supply
{
    uint64_t u;
    struct cavm_gpio_misc_supply_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t reserved_10_11        : 2;
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic north IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t reserved_0_1          : 2;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_1          : 2;
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic north IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t reserved_10_11        : 2;
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_misc_supply_s cn9; */
    struct cavm_gpio_misc_supply_cn96xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_22_63        : 42;
        uint64_t vdet_avs              : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for AVS bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_e             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic east IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic north IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_tws_avs          : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI and AVS:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
#else /* Word 0 - Little Endian */
        uint64_t vdet_tws_avs          : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI and AVS:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic north IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_e             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic east IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_avs              : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for AVS bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t reserved_22_63        : 42;
#endif /* Word 0 - End */
    } cn96xxp1;
    struct cavm_gpio_misc_supply_cn96xxp3
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_22_63        : 42;
        uint64_t vdet_avs              : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for AVS bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_e             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic east I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic north I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_tws_avs          : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI and AVS:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
#else /* Word 0 - Little Endian */
        uint64_t vdet_tws_avs          : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI and AVS:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic north I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_e             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic east I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_avs              : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for AVS bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t reserved_22_63        : 42;
#endif /* Word 0 - End */
    } cn96xxp3;
    struct cavm_gpio_misc_supply_cn98xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t vdet_gpio66           : 2;  /**< [ 23: 22](RO/H) Sensed I/O power supply setting for GPIO66..83.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_tws0             : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for TWS0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..71.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_e             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic east I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic north I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_tws_3_1_avs      : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI[3:1] & AVS. (TWSI[0] is tied to direct 2.5V supply):
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
#else /* Word 0 - Little Endian */
        uint64_t vdet_tws_3_1_avs      : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI[3:1] & AVS. (TWSI[0] is tied to direct 2.5V supply):
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic north I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_e             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic east I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..71.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_tws0             : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for TWS0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio66           : 2;  /**< [ 23: 22](RO/H) Sensed I/O power supply setting for GPIO66..83.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn98xx;
    struct cavm_gpio_misc_supply_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t vdet_scan             : 2;  /**< [ 23: 22](RO/H) Sensed I/O power supply setting for dedicated scan ports:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_avs              : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for AVS bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved.

                                                                 Internal:
                                                                 Values echo VDET_TWS_AVS */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_e             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved.

                                                                 Internal:
                                                                 Values echo VDET_IO_N */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_tws_avs          : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI and AVS:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
#else /* Word 0 - Little Endian */
        uint64_t vdet_tws_avs          : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI and AVS:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_e             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved.

                                                                 Internal:
                                                                 Values echo VDET_IO_N */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_avs              : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for AVS bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved.

                                                                 Internal:
                                                                 Values echo VDET_TWS_AVS */
        uint64_t vdet_scan             : 2;  /**< [ 23: 22](RO/H) Sensed I/O power supply setting for dedicated scan ports:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cnf95xx;
    struct cavm_gpio_misc_supply_loki
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t vdet_scan             : 2;  /**< [ 23: 22](RO/H) Sensed I/O power supply setting for dedicated scan ports:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_avs              : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for AVS bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved.

                                                                 Internal:
                                                                 Values echo VDET_TWS_AVS */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_s             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_tws_avs          : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI and AVS:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
#else /* Word 0 - Little Endian */
        uint64_t vdet_tws_avs          : 2;  /**< [  1:  0](RO/H) Sensed I/O power supply setting for TWSI and AVS:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_spi              : 2;  /**< [  3:  2](RO/H) Sensed I/O power supply setting for SPI0 bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_smi              : 2;  /**< [  5:  4](RO/H) Sensed I/O power supply setting for SMI bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_pci              : 2;  /**< [  7:  6](RO/H) Sensed I/O power supply setting for PCI I/O pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_n             : 2;  /**< [  9:  8](RO/H) Sensed I/O power supply setting for generic IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_io_s             : 2;  /**< [ 11: 10](RO/H) Sensed I/O power supply setting for generic IO pins:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio48           : 2;  /**< [ 13: 12](RO/H) Sensed I/O power supply setting for GPIO48..63.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio24           : 2;  /**< [ 15: 14](RO/H) Sensed I/O power supply setting for GPIO24..47.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_gpio0            : 2;  /**< [ 17: 16](RO/H) Sensed I/O power supply setting for GPIO0..23.
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_emmc             : 2;  /**< [ 19: 18](RO/H) Sensed I/O power supply setting for EMMC bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t vdet_avs              : 2;  /**< [ 21: 20](RO/H) Sensed I/O power supply setting for AVS bus:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved.

                                                                 Internal:
                                                                 Values echo VDET_TWS_AVS */
        uint64_t vdet_scan             : 2;  /**< [ 23: 22](RO/H) Sensed I/O power supply setting for dedicated scan ports:
                                                                 0x0 = 3.3 V.
                                                                 0x1 = 2.5 V.
                                                                 0x2/0x3 = 1.8 V.
                                                                 _ All other values reserved. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } loki;
};
typedef union cavm_gpio_misc_supply cavm_gpio_misc_supply_t;

#define CAVM_GPIO_MISC_SUPPLY CAVM_GPIO_MISC_SUPPLY_FUNC()
static inline uint64_t CAVM_GPIO_MISC_SUPPLY_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MISC_SUPPLY_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000000038ll;
    __cavm_csr_fatal("GPIO_MISC_SUPPLY", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_MISC_SUPPLY cavm_gpio_misc_supply_t
#define bustype_CAVM_GPIO_MISC_SUPPLY CSR_TYPE_NCB
#define basename_CAVM_GPIO_MISC_SUPPLY "GPIO_MISC_SUPPLY"
#define device_bar_CAVM_GPIO_MISC_SUPPLY 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_MISC_SUPPLY 0
#define arguments_CAVM_GPIO_MISC_SUPPLY -1,-1,-1,-1

/**
 * Register (NCB) gpio_msix_pba#
 *
 * GPIO MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the GPIO_INT_VEC_E enumeration.
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_msix_pbax
{
    uint64_t u;
    struct cavm_gpio_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated GPIO_MSIX_VEC()_CTL, enumerated by
                                                                 GPIO_INT_VEC_E. Bits
                                                                 that have no associated GPIO_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated GPIO_MSIX_VEC()_CTL, enumerated by
                                                                 GPIO_INT_VEC_E. Bits
                                                                 that have no associated GPIO_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_msix_pbax_s cn; */
};
typedef union cavm_gpio_msix_pbax cavm_gpio_msix_pbax_t;

static inline uint64_t CAVM_GPIO_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MSIX_PBAX(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CN81XX) && (a<=1))
        return 0x803000ff0000ll + 8ll * ((a) & 0x1);
    if (cavm_is_model(OCTEONTX_CN83XX) && (a<=2))
        return 0x803000ff0000ll + 8ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_CN96XX) && (a<=2))
        return 0x803000ff0000ll + 8ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_CN98XX) && (a<=3))
        return 0x803000ff0000ll + 8ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=2))
        return 0x803000ff0000ll + 8ll * ((a) & 0x3);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=2))
        return 0x803000ff0000ll + 8ll * ((a) & 0x3);
    __cavm_csr_fatal("GPIO_MSIX_PBAX", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_MSIX_PBAX(a) cavm_gpio_msix_pbax_t
#define bustype_CAVM_GPIO_MSIX_PBAX(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_MSIX_PBAX(a) "GPIO_MSIX_PBAX"
#define device_bar_CAVM_GPIO_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_GPIO_MSIX_PBAX(a) (a)
#define arguments_CAVM_GPIO_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_msix_vec#_addr
 *
 * GPIO MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the GPIO_INT_VEC_E enumeration.
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_msix_vecx_addr
{
    uint64_t u;
    struct cavm_gpio_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t addr                  : 51; /**< [ 52:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's GPIO_MSIX_VEC()_ADDR, GPIO_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GPIO_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_GPIO_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's GPIO_MSIX_VEC()_ADDR, GPIO_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GPIO_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_GPIO_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 51; /**< [ 52:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    struct cavm_gpio_msix_vecx_addr_cn8
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's GPIO_MSIX_VEC()_ADDR, GPIO_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GPIO_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_GPIO_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's GPIO_MSIX_VEC()_ADDR, GPIO_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GPIO_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_GPIO_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } cn8;
    /* struct cavm_gpio_msix_vecx_addr_s cn9; */
    /* struct cavm_gpio_msix_vecx_addr_s cn96xxp1; */
    struct cavm_gpio_msix_vecx_addr_cn96xxp3
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t addr                  : 51; /**< [ 52:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 The vector's IOVA is sent to the SMMU as nonsecure (though this only affects
                                                                 physical addresses if PCCPF_XXX_VSEC_SCTL[MSIX_PHYS]=1).

                                                                 1 = This vector's GPIO_MSIX_VEC()_ADDR, GPIO_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GPIO_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.
                                                                 The vector's IOVA is sent to the SMMU as secure (though this only affects
                                                                 physical addresses if PCCPF_XXX_VSEC_SCTL[MSIX_PHYS]=1 or
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC_PHYS]=1).

                                                                 If PCCPF_GPIO_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set.

                                                                 Also note the following:
                                                                 * When PCCPF_XXX_VSEC_SCTL[MSIX_SEC_EN]=1, all secure vectors (including secure
                                                                 VF vectors) will act as if PCCPF/PCCVF_XXX_MSIX_CAP_HDR[MSIXEN]=1,
                                                                 PCCPF/PCCVF_XXX_MSIX_CAP_HDR[FUNM]=0 and PCCPF/PCCVF_XXX_CMD[ME]=1.
                                                                 * When PCCPF_XXX_VSEC_SCTL[MSIX_SEC_PHYS]=1, all secure vectors (including
                                                                 secure VF vectors) are considered physical, regardless of
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_PHYS]. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 The vector's IOVA is sent to the SMMU as nonsecure (though this only affects
                                                                 physical addresses if PCCPF_XXX_VSEC_SCTL[MSIX_PHYS]=1).

                                                                 1 = This vector's GPIO_MSIX_VEC()_ADDR, GPIO_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GPIO_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.
                                                                 The vector's IOVA is sent to the SMMU as secure (though this only affects
                                                                 physical addresses if PCCPF_XXX_VSEC_SCTL[MSIX_PHYS]=1 or
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC_PHYS]=1).

                                                                 If PCCPF_GPIO_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set.

                                                                 Also note the following:
                                                                 * When PCCPF_XXX_VSEC_SCTL[MSIX_SEC_EN]=1, all secure vectors (including secure
                                                                 VF vectors) will act as if PCCPF/PCCVF_XXX_MSIX_CAP_HDR[MSIXEN]=1,
                                                                 PCCPF/PCCVF_XXX_MSIX_CAP_HDR[FUNM]=0 and PCCPF/PCCVF_XXX_CMD[ME]=1.
                                                                 * When PCCPF_XXX_VSEC_SCTL[MSIX_SEC_PHYS]=1, all secure vectors (including
                                                                 secure VF vectors) are considered physical, regardless of
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_PHYS]. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 51; /**< [ 52:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } cn96xxp3;
    /* struct cavm_gpio_msix_vecx_addr_cn96xxp3 cn98xx; */
    /* struct cavm_gpio_msix_vecx_addr_cn96xxp3 cnf95xx; */
    /* struct cavm_gpio_msix_vecx_addr_cn96xxp3 loki; */
};
typedef union cavm_gpio_msix_vecx_addr cavm_gpio_msix_vecx_addr_t;

static inline uint64_t CAVM_GPIO_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MSIX_VECX_ADDR(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CN81XX) && (a<=99))
        return 0x803000f00000ll + 0x10ll * ((a) & 0x7f);
    if (cavm_is_model(OCTEONTX_CN83XX) && (a<=183))
        return 0x803000f00000ll + 0x10ll * ((a) & 0xff);
    if (cavm_is_model(OCTEONTX_CN96XX) && (a<=181))
        return 0x803000f00000ll + 0x10ll * ((a) & 0xff);
    if (cavm_is_model(OCTEONTX_CN98XX) && (a<=203))
        return 0x803000f00000ll + 0x10ll * ((a) & 0xff);
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=133))
        return 0x803000f00000ll + 0x10ll * ((a) & 0xff);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=133))
        return 0x803000f00000ll + 0x10ll * ((a) & 0xff);
    __cavm_csr_fatal("GPIO_MSIX_VECX_ADDR", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_MSIX_VECX_ADDR(a) cavm_gpio_msix_vecx_addr_t
#define bustype_CAVM_GPIO_MSIX_VECX_ADDR(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_MSIX_VECX_ADDR(a) "GPIO_MSIX_VECX_ADDR"
#define device_bar_CAVM_GPIO_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_GPIO_MSIX_VECX_ADDR(a) (a)
#define arguments_CAVM_GPIO_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_msix_vec#_ctl
 *
 * GPIO MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the GPIO_INT_VEC_E enumeration.
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_msix_vecx_ctl
{
    uint64_t u;
    struct cavm_gpio_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t data                  : 32; /**< [ 31:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 32; /**< [ 31:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    struct cavm_gpio_msix_vecx_ctl_cn8
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
    } cn8;
    /* struct cavm_gpio_msix_vecx_ctl_s cn9; */
};
typedef union cavm_gpio_msix_vecx_ctl cavm_gpio_msix_vecx_ctl_t;

static inline uint64_t CAVM_GPIO_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MSIX_VECX_CTL(unsigned long a)
{
    if (cavm_is_model(OCTEONTX_CN81XX) && (a<=99))
        return 0x803000f00008ll + 0x10ll * ((a) & 0x7f);
    if (cavm_is_model(OCTEONTX_CN83XX) && (a<=183))
        return 0x803000f00008ll + 0x10ll * ((a) & 0xff);
    if (cavm_is_model(OCTEONTX_CN96XX) && (a<=181))
        return 0x803000f00008ll + 0x10ll * ((a) & 0xff);
    if (cavm_is_model(OCTEONTX_CN98XX) && (a<=203))
        return 0x803000f00008ll + 0x10ll * ((a) & 0xff);
    if (cavm_is_model(OCTEONTX_CNF95XX) && (a<=133))
        return 0x803000f00008ll + 0x10ll * ((a) & 0xff);
    if (cavm_is_model(OCTEONTX_LOKI) && (a<=133))
        return 0x803000f00008ll + 0x10ll * ((a) & 0xff);
    __cavm_csr_fatal("GPIO_MSIX_VECX_CTL", 1, a, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_MSIX_VECX_CTL(a) cavm_gpio_msix_vecx_ctl_t
#define bustype_CAVM_GPIO_MSIX_VECX_CTL(a) CSR_TYPE_NCB
#define basename_CAVM_GPIO_MSIX_VECX_CTL(a) "GPIO_MSIX_VECX_CTL"
#define device_bar_CAVM_GPIO_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_CAVM_GPIO_MSIX_VECX_CTL(a) (a)
#define arguments_CAVM_GPIO_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_multi_cast
 *
 * GPIO Multicast Register
 * This register enables multicast GPIO interrupts.
 *
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_multi_cast
{
    uint64_t u;
    struct cavm_gpio_multi_cast_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t en                    : 1;  /**< [  0:  0](R/W) Enable GPIO interrupt multicast mode. When [EN] is set, GPIO\<7:4\> functions in multicast
                                                                 mode allowing these four GPIOs to interrupt multiple cores. Multicast functionality allows
                                                                 the GPIO to exist as per-core interrupts as opposed to a global interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t en                    : 1;  /**< [  0:  0](R/W) Enable GPIO interrupt multicast mode. When [EN] is set, GPIO\<7:4\> functions in multicast
                                                                 mode allowing these four GPIOs to interrupt multiple cores. Multicast functionality allows
                                                                 the GPIO to exist as per-core interrupts as opposed to a global interrupt. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_multi_cast_s cn; */
};
typedef union cavm_gpio_multi_cast cavm_gpio_multi_cast_t;

#define CAVM_GPIO_MULTI_CAST CAVM_GPIO_MULTI_CAST_FUNC()
static inline uint64_t CAVM_GPIO_MULTI_CAST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_MULTI_CAST_FUNC(void)
{
    return 0x803000000018ll;
}

#define typedef_CAVM_GPIO_MULTI_CAST cavm_gpio_multi_cast_t
#define bustype_CAVM_GPIO_MULTI_CAST CSR_TYPE_NCB
#define basename_CAVM_GPIO_MULTI_CAST "GPIO_MULTI_CAST"
#define device_bar_CAVM_GPIO_MULTI_CAST 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_MULTI_CAST 0
#define arguments_CAVM_GPIO_MULTI_CAST -1,-1,-1,-1

/**
 * Register (NCB) gpio_ocla_exten_trig
 *
 * GPIO OCLA External Trigger Register
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_ocla_exten_trig
{
    uint64_t u;
    struct cavm_gpio_ocla_exten_trig_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t m_trig                : 1;  /**< [  0:  0](R/W) Manual trigger. Assert the OCLA trigger for GPIO-based triggering. This manual
                                                                 trigger is ORed with the optional GPIO input pin selected with
                                                                 GPIO_BIT_CFG()[PIN_SEL] = GPIO_PIN_SEL_E::OCLA_EXT_TRIGGER. */
#else /* Word 0 - Little Endian */
        uint64_t m_trig                : 1;  /**< [  0:  0](R/W) Manual trigger. Assert the OCLA trigger for GPIO-based triggering. This manual
                                                                 trigger is ORed with the optional GPIO input pin selected with
                                                                 GPIO_BIT_CFG()[PIN_SEL] = GPIO_PIN_SEL_E::OCLA_EXT_TRIGGER. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_ocla_exten_trig_s cn8; */
    struct cavm_gpio_ocla_exten_trig_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t m_trig                : 1;  /**< [  0:  0](R/W) Manual trigger. Assert the OCLA trigger for GPIO-based triggering. This manual
                                                                 trigger is ORed with the optional GPIO input pin permitted with
                                                                 GPIO_BIT_CFG()[PIN_SEL] = GPIO_PIN_SEL_E::OCLA_EXT_TRIGGER. */
#else /* Word 0 - Little Endian */
        uint64_t m_trig                : 1;  /**< [  0:  0](R/W) Manual trigger. Assert the OCLA trigger for GPIO-based triggering. This manual
                                                                 trigger is ORed with the optional GPIO input pin permitted with
                                                                 GPIO_BIT_CFG()[PIN_SEL] = GPIO_PIN_SEL_E::OCLA_EXT_TRIGGER. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } cn9;
};
typedef union cavm_gpio_ocla_exten_trig cavm_gpio_ocla_exten_trig_t;

#define CAVM_GPIO_OCLA_EXTEN_TRIG CAVM_GPIO_OCLA_EXTEN_TRIG_FUNC()
static inline uint64_t CAVM_GPIO_OCLA_EXTEN_TRIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_OCLA_EXTEN_TRIG_FUNC(void)
{
    return 0x803000000020ll;
}

#define typedef_CAVM_GPIO_OCLA_EXTEN_TRIG cavm_gpio_ocla_exten_trig_t
#define bustype_CAVM_GPIO_OCLA_EXTEN_TRIG CSR_TYPE_NCB
#define basename_CAVM_GPIO_OCLA_EXTEN_TRIG "GPIO_OCLA_EXTEN_TRIG"
#define device_bar_CAVM_GPIO_OCLA_EXTEN_TRIG 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_OCLA_EXTEN_TRIG 0
#define arguments_CAVM_GPIO_OCLA_EXTEN_TRIG -1,-1,-1,-1

/**
 * Register (NCB) gpio_permit
 *
 * GPIO Permit Register
 * This register determines which requestor(s) are permitted to access which GPIO global
 * registers.
 *
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 * (That is, only the GPIO_PERMIT permitted agent can change the permission settings of
 * all requestors.)
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_permit
{
    uint64_t u;
    struct cavm_gpio_permit_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t permitdis             : 4;  /**< [  3:  0](R/W) Each bit, if set, disables the given requestor from accessing GPIO global registers.
                                                                 If a disabled requestor makes a request, the access becomes read-zero/write ignored.
                                                                   \<0\> = Disable AP/NCSI/JTAG (non MCP/SCP) secure world from accessing GPIO global registers.
                                                                   \<1\> = Disable AP/NCSI/JTAG (non MCP/SCP) nonsecure world from accessing GPIO global registers.
                                                                   \<2\> = Disable XCP0 (SCP) from accessing GPIO global registers.
                                                                   \<3\> = Disable XCP1 (MCP) from accessing GPIO global registers. */
#else /* Word 0 - Little Endian */
        uint64_t permitdis             : 4;  /**< [  3:  0](R/W) Each bit, if set, disables the given requestor from accessing GPIO global registers.
                                                                 If a disabled requestor makes a request, the access becomes read-zero/write ignored.
                                                                   \<0\> = Disable AP/NCSI/JTAG (non MCP/SCP) secure world from accessing GPIO global registers.
                                                                   \<1\> = Disable AP/NCSI/JTAG (non MCP/SCP) nonsecure world from accessing GPIO global registers.
                                                                   \<2\> = Disable XCP0 (SCP) from accessing GPIO global registers.
                                                                   \<3\> = Disable XCP1 (MCP) from accessing GPIO global registers. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_permit_s cn9; */
    /* struct cavm_gpio_permit_s cn96xx; */
    /* struct cavm_gpio_permit_s cn98xx; */
    struct cavm_gpio_permit_cnf95xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t permitdis             : 4;  /**< [  3:  0](R/W) Each bit, if set, disables the given requestor from accessing GPIO global registers.
                                                                 If a disabled requestor makes a request, the access becomes read-zero/write ignored.
                                                                   \<0\> = Disable AP/JTAG (non MCP/SCP) secure world from accessing GPIO global registers.
                                                                   \<1\> = Disable AP/JTAG (non MCP/SCP) nonsecure world from accessing GPIO global registers.
                                                                   \<2\> = Disable XCP0 (SCP) from accessing GPIO global registers.
                                                                   \<3\> = Disable XCP1 (MCP) from accessing GPIO global registers. */
#else /* Word 0 - Little Endian */
        uint64_t permitdis             : 4;  /**< [  3:  0](R/W) Each bit, if set, disables the given requestor from accessing GPIO global registers.
                                                                 If a disabled requestor makes a request, the access becomes read-zero/write ignored.
                                                                   \<0\> = Disable AP/JTAG (non MCP/SCP) secure world from accessing GPIO global registers.
                                                                   \<1\> = Disable AP/JTAG (non MCP/SCP) nonsecure world from accessing GPIO global registers.
                                                                   \<2\> = Disable XCP0 (SCP) from accessing GPIO global registers.
                                                                   \<3\> = Disable XCP1 (MCP) from accessing GPIO global registers. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } cnf95xx;
    /* struct cavm_gpio_permit_cnf95xx loki; */
};
typedef union cavm_gpio_permit cavm_gpio_permit_t;

#define CAVM_GPIO_PERMIT CAVM_GPIO_PERMIT_FUNC()
static inline uint64_t CAVM_GPIO_PERMIT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_PERMIT_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000001500ll;
    __cavm_csr_fatal("GPIO_PERMIT", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_PERMIT cavm_gpio_permit_t
#define bustype_CAVM_GPIO_PERMIT CSR_TYPE_NCB
#define basename_CAVM_GPIO_PERMIT "GPIO_PERMIT"
#define device_bar_CAVM_GPIO_PERMIT 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_PERMIT 0
#define arguments_CAVM_GPIO_PERMIT -1,-1,-1,-1

/**
 * Register (NCB) gpio_pkg_ver
 *
 * Chip Package Version Register
 * This register reads the package version.
 */
union cavm_gpio_pkg_ver
{
    uint64_t u;
    struct cavm_gpio_pkg_ver_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.
                                                                 0x0 = 50 x 50mm package, up to 3 DDR channels.
                                                                 0x1 = 42.5 x 42.5mm package, up to 2 DDR channels.
                                                                 0x3 = 45 x 45mm package, up to 2 DDR channels, for CN95xxE. */
#else /* Word 0 - Little Endian */
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.
                                                                 0x0 = 50 x 50mm package, up to 3 DDR channels.
                                                                 0x1 = 42.5 x 42.5mm package, up to 2 DDR channels.
                                                                 0x3 = 45 x 45mm package, up to 2 DDR channels, for CN95xxE. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_pkg_ver_s cn9; */
    /* struct cavm_gpio_pkg_ver_s cn96xxp1; */
    struct cavm_gpio_pkg_ver_cn96xxp3
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.

                                                                 If FUS_FUSE_NUM_E::CHIP_ID() fuses indicate pass A or B:
                                                                 0x0 = SKU package A = 50 x 50mm package, up to 3 DDR channels.
                                                                 0x1 = SKU package B = 42.5 x 42.5mm package, up to 2 DDR channels, 4 lanes Ethernet.
                                                                 0x2 = SKU package C = 42.5 x 42.5mm package, up to 2 DDR channels, 8 lanes Ethernet.
                                                                 0x3 = SKU package D = 45 x 45mm package, up to 2 DDR channels, for CN95xxE.

                                                                 If FUS_FUSE_NUM_E::CHIP_ID() fuses indicate pass C or later:
                                                                 0x4 = SKU package M = 50 x 50mm package, up to 3 DDR channels,
                                                                                       backwards A0 board-compatible.
                                                                 0x7 = SKU package P = 50 x 50mm package, up to 3 DDR channels.

                                                                 Internal:
                                                                 Architecturally defined, same encoding across same die.

                                                                 Proposed but currently not planned packages:
                                                                 Pass A: 0x7 = SKU package H = 50 x 50mm package, up to 3 DDR channels,
                                                                               forward C0 board compatible.
                                                                 Pass C: 0x1 = SKU package J = 42.5 x 42.5mm package, up to 2 DDR channels, 4 lanes Ethernet. */
#else /* Word 0 - Little Endian */
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.

                                                                 If FUS_FUSE_NUM_E::CHIP_ID() fuses indicate pass A or B:
                                                                 0x0 = SKU package A = 50 x 50mm package, up to 3 DDR channels.
                                                                 0x1 = SKU package B = 42.5 x 42.5mm package, up to 2 DDR channels, 4 lanes Ethernet.
                                                                 0x2 = SKU package C = 42.5 x 42.5mm package, up to 2 DDR channels, 8 lanes Ethernet.
                                                                 0x3 = SKU package D = 45 x 45mm package, up to 2 DDR channels, for CN95xxE.

                                                                 If FUS_FUSE_NUM_E::CHIP_ID() fuses indicate pass C or later:
                                                                 0x4 = SKU package M = 50 x 50mm package, up to 3 DDR channels,
                                                                                       backwards A0 board-compatible.
                                                                 0x7 = SKU package P = 50 x 50mm package, up to 3 DDR channels.

                                                                 Internal:
                                                                 Architecturally defined, same encoding across same die.

                                                                 Proposed but currently not planned packages:
                                                                 Pass A: 0x7 = SKU package H = 50 x 50mm package, up to 3 DDR channels,
                                                                               forward C0 board compatible.
                                                                 Pass C: 0x1 = SKU package J = 42.5 x 42.5mm package, up to 2 DDR channels, 4 lanes Ethernet. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } cn96xxp3;
    struct cavm_gpio_pkg_ver_cn98xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.
                                                                 0x0 = SKU package A = TBD x TBD package, up to 6 DDR channels, for CN98XX.

                                                                 Internal:
                                                                 Architecturally defined, same encoding across same die. */
#else /* Word 0 - Little Endian */
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.
                                                                 0x0 = SKU package A = TBD x TBD package, up to 6 DDR channels, for CN98XX.

                                                                 Internal:
                                                                 Architecturally defined, same encoding across same die. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } cn98xx;
    struct cavm_gpio_pkg_ver_cnf95xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.
                                                                 0x0 = SKU package A = 45 x 45mm package, up to 2 DDR channels, for CNF95XX.

                                                                 Internal:
                                                                 Architecturally defined, same encoding across same die. */
#else /* Word 0 - Little Endian */
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.
                                                                 0x0 = SKU package A = 45 x 45mm package, up to 2 DDR channels, for CNF95XX.

                                                                 Internal:
                                                                 Architecturally defined, same encoding across same die. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } cnf95xxp1;
    struct cavm_gpio_pkg_ver_cnf95xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.
                                                                 0x0 = SKU package A = 45 x 45mm package, up to 2 DDR channels, for CNF95XX.
                                                                 0x1 = SKU package B = 45 x 45mm package, up to 2 DDR channels, for CNF95XX pass B0+.

                                                                 Internal:
                                                                 Architecturally defined, same encoding across same die. */
#else /* Word 0 - Little Endian */
        uint64_t pkg_ver               : 3;  /**< [  2:  0](RO/H) Reads the package version straps, which are set by the package.
                                                                 0x0 = SKU package A = 45 x 45mm package, up to 2 DDR channels, for CNF95XX.
                                                                 0x1 = SKU package B = 45 x 45mm package, up to 2 DDR channels, for CNF95XX pass B0+.

                                                                 Internal:
                                                                 Architecturally defined, same encoding across same die. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } cnf95xxp2;
    /* struct cavm_gpio_pkg_ver_cnf95xxp1 loki; */
};
typedef union cavm_gpio_pkg_ver cavm_gpio_pkg_ver_t;

#define CAVM_GPIO_PKG_VER CAVM_GPIO_PKG_VER_FUNC()
static inline uint64_t CAVM_GPIO_PKG_VER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_PKG_VER_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000001610ll;
    __cavm_csr_fatal("GPIO_PKG_VER", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_PKG_VER cavm_gpio_pkg_ver_t
#define bustype_CAVM_GPIO_PKG_VER CSR_TYPE_NCB
#define basename_CAVM_GPIO_PKG_VER "GPIO_PKG_VER"
#define device_bar_CAVM_GPIO_PKG_VER 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_PKG_VER 0
#define arguments_CAVM_GPIO_PKG_VER -1,-1,-1,-1

/**
 * Register (NCB) gpio_pspi_ctl
 *
 * GPIO Expansion ROM SPI Control Register
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_pspi_ctl
{
    uint64_t u;
    struct cavm_gpio_pspi_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t pspi_gpio             : 1;  /**< [  0:  0](R/W) PSPI GPIO reset override.
                                                                 When set, this field causes the GPIO pins 39-43 to maintain their
                                                                 values through a chip reset.  This bit is typically set when PCIe Expansion RIM
                                                                 is required and a PEM has been configured as an end point.
                                                                 When cleared, the GPIOs are reset during a chip domain reset.
                                                                 This register is reset only on a cold domain reset. */
#else /* Word 0 - Little Endian */
        uint64_t pspi_gpio             : 1;  /**< [  0:  0](R/W) PSPI GPIO reset override.
                                                                 When set, this field causes the GPIO pins 39-43 to maintain their
                                                                 values through a chip reset.  This bit is typically set when PCIe Expansion RIM
                                                                 is required and a PEM has been configured as an end point.
                                                                 When cleared, the GPIOs are reset during a chip domain reset.
                                                                 This register is reset only on a cold domain reset. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_pspi_ctl_s cn9; */
    /* struct cavm_gpio_pspi_ctl_s cn96xxp1; */
    struct cavm_gpio_pspi_ctl_cn96xxp3
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t pspi_gpio             : 1;  /**< [  0:  0](R/W) PSPI GPIO reset override.
                                                                 When set, this field causes the GPIO pins 39-42 to maintain their
                                                                 values through a chip reset. This bit is typically set when PCIe Expansion RIM
                                                                 is required and a PEM has been configured as an end point.
                                                                 When cleared, the GPIOs are reset during a chip domain reset.
                                                                 This register is reset only on a cold domain reset. */
#else /* Word 0 - Little Endian */
        uint64_t pspi_gpio             : 1;  /**< [  0:  0](R/W) PSPI GPIO reset override.
                                                                 When set, this field causes the GPIO pins 39-42 to maintain their
                                                                 values through a chip reset. This bit is typically set when PCIe Expansion RIM
                                                                 is required and a PEM has been configured as an end point.
                                                                 When cleared, the GPIOs are reset during a chip domain reset.
                                                                 This register is reset only on a cold domain reset. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } cn96xxp3;
    /* struct cavm_gpio_pspi_ctl_cn96xxp3 cn98xx; */
    /* struct cavm_gpio_pspi_ctl_cn96xxp3 cnf95xx; */
    /* struct cavm_gpio_pspi_ctl_cn96xxp3 loki; */
};
typedef union cavm_gpio_pspi_ctl cavm_gpio_pspi_ctl_t;

#define CAVM_GPIO_PSPI_CTL CAVM_GPIO_PSPI_CTL_FUNC()
static inline uint64_t CAVM_GPIO_PSPI_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_PSPI_CTL_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000000088ll;
    __cavm_csr_fatal("GPIO_PSPI_CTL", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_PSPI_CTL cavm_gpio_pspi_ctl_t
#define bustype_CAVM_GPIO_PSPI_CTL CSR_TYPE_NCB
#define basename_CAVM_GPIO_PSPI_CTL "GPIO_PSPI_CTL"
#define device_bar_CAVM_GPIO_PSPI_CTL 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_PSPI_CTL 0
#define arguments_CAVM_GPIO_PSPI_CTL -1,-1,-1,-1

/**
 * Register (NCB) gpio_rx1_dat
 *
 * GPIO Receive Data Extension Register
 * See GPIO_RX_DAT.
 */
union cavm_gpio_rx1_dat
{
    uint64_t u;
    struct cavm_gpio_rx1_dat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t dat                   : 32; /**< [ 31:  0](RO/H) GPIO read data. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 32; /**< [ 31:  0](RO/H) GPIO read data. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_gpio_rx1_dat_cn8
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t dat                   : 29; /**< [ 28:  0](RO/H) GPIO read data. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 29; /**< [ 28:  0](RO/H) GPIO read data. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } cn8;
    /* struct cavm_gpio_rx1_dat_cn8 cn81xx; */
    struct cavm_gpio_rx1_dat_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t dat                   : 16; /**< [ 15:  0](RO/H) GPIO read data. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 16; /**< [ 15:  0](RO/H) GPIO read data. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn83xx;
    struct cavm_gpio_rx1_dat_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t dat                   : 32; /**< [ 31:  0](RO/H) GPIO read data. Unimplemented pins bits read as zero. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 32; /**< [ 31:  0](RO/H) GPIO read data. Unimplemented pins bits read as zero. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn9;
};
typedef union cavm_gpio_rx1_dat cavm_gpio_rx1_dat_t;

#define CAVM_GPIO_RX1_DAT CAVM_GPIO_RX1_DAT_FUNC()
static inline uint64_t CAVM_GPIO_RX1_DAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_RX1_DAT_FUNC(void)
{
    return 0x803000001400ll;
}

#define typedef_CAVM_GPIO_RX1_DAT cavm_gpio_rx1_dat_t
#define bustype_CAVM_GPIO_RX1_DAT CSR_TYPE_NCB
#define basename_CAVM_GPIO_RX1_DAT "GPIO_RX1_DAT"
#define device_bar_CAVM_GPIO_RX1_DAT 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_RX1_DAT 0
#define arguments_CAVM_GPIO_RX1_DAT -1,-1,-1,-1

/**
 * Register (NCB) gpio_rx_dat
 *
 * GPIO Receive Data Register
 * This register contains the state of the GPIO pins, which is after glitch filter and XOR
 * inverter (GPIO_BIT_CFG()[PIN_XOR]). GPIO inputs always report to GPIO_RX_DAT despite of
 * the value of GPIO_BIT_CFG()[PIN_SEL].
 * GPIO_RX_DAT reads GPIO input data for the first 64 GPIOs, and GPIO_RX1_DAT the remainder.
 *
 * Each bit in this register is only accessible to the requestor(s) permitted with
 * GPIO_BIT_PERMIT(), but error will not be reported when there are bits are not
 * permitted by GPIO_BIT_PERMIT().
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_rx_dat
{
    uint64_t u;
    struct cavm_gpio_rx_dat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO/H) GPIO read data. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO/H) GPIO read data. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_rx_dat_s cn8; */
    struct cavm_gpio_rx_dat_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t dat                   : 48; /**< [ 47:  0](RO/H) GPIO read data. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 48; /**< [ 47:  0](RO/H) GPIO read data. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct cavm_gpio_rx_dat_s cn83xx; */
    /* struct cavm_gpio_rx_dat_s cn9; */
};
typedef union cavm_gpio_rx_dat cavm_gpio_rx_dat_t;

#define CAVM_GPIO_RX_DAT CAVM_GPIO_RX_DAT_FUNC()
static inline uint64_t CAVM_GPIO_RX_DAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_RX_DAT_FUNC(void)
{
    return 0x803000000000ll;
}

#define typedef_CAVM_GPIO_RX_DAT cavm_gpio_rx_dat_t
#define bustype_CAVM_GPIO_RX_DAT CSR_TYPE_NCB
#define basename_CAVM_GPIO_RX_DAT "GPIO_RX_DAT"
#define device_bar_CAVM_GPIO_RX_DAT 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_RX_DAT 0
#define arguments_CAVM_GPIO_RX_DAT -1,-1,-1,-1

/**
 * Register (NCB) gpio_strap
 *
 * GPIO Strap Value Register
 * This register contains the first 64 GPIO strap data captured at the rising edge of DC_OK.
 * GPIO_STRAP1 contains the remaining GPIOs.
 *
 * Straps are enumerated by GPIO_STRAP_PIN_E.
 *
 * This register is accessible to all requestors (regardless of GPIO_PERMIT).
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_strap
{
    uint64_t u;
    struct cavm_gpio_strap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t strap                 : 64; /**< [ 63:  0](RO/H) GPIO strap data of GPIO pins less than 64. Unimplemented pins bits read as 0. */
#else /* Word 0 - Little Endian */
        uint64_t strap                 : 64; /**< [ 63:  0](RO/H) GPIO strap data of GPIO pins less than 64. Unimplemented pins bits read as 0. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_strap_s cn8; */
    struct cavm_gpio_strap_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t strap                 : 48; /**< [ 47:  0](RO/H) GPIO strap data of GPIO pins less than 64. Unimplemented pins bits read as 0. */
#else /* Word 0 - Little Endian */
        uint64_t strap                 : 48; /**< [ 47:  0](RO/H) GPIO strap data of GPIO pins less than 64. Unimplemented pins bits read as 0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct cavm_gpio_strap_s cn83xx; */
    /* struct cavm_gpio_strap_s cn9; */
};
typedef union cavm_gpio_strap cavm_gpio_strap_t;

#define CAVM_GPIO_STRAP CAVM_GPIO_STRAP_FUNC()
static inline uint64_t CAVM_GPIO_STRAP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_STRAP_FUNC(void)
{
    return 0x803000000028ll;
}

#define typedef_CAVM_GPIO_STRAP cavm_gpio_strap_t
#define bustype_CAVM_GPIO_STRAP CSR_TYPE_NCB
#define basename_CAVM_GPIO_STRAP "GPIO_STRAP"
#define device_bar_CAVM_GPIO_STRAP 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_STRAP 0
#define arguments_CAVM_GPIO_STRAP -1,-1,-1,-1

/**
 * Register (NCB) gpio_strap1
 *
 * GPIO Strap Value Register
 * See GPIO_STRAP.
 */
union cavm_gpio_strap1
{
    uint64_t u;
    struct cavm_gpio_strap1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t strap                 : 32; /**< [ 31:  0](RO/H) GPIO strap data of GPIO pins less than 64. Unimplemented pins bits read as 0. */
#else /* Word 0 - Little Endian */
        uint64_t strap                 : 32; /**< [ 31:  0](RO/H) GPIO strap data of GPIO pins less than 64. Unimplemented pins bits read as 0. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_gpio_strap1_cn8
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t strap                 : 29; /**< [ 28:  0](RO/H) GPIO strap data of GPIO pins less than 64. Unimplemented pins bits read as 0. */
#else /* Word 0 - Little Endian */
        uint64_t strap                 : 29; /**< [ 28:  0](RO/H) GPIO strap data of GPIO pins less than 64. Unimplemented pins bits read as 0. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } cn8;
    /* struct cavm_gpio_strap1_cn8 cn81xx; */
    struct cavm_gpio_strap1_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t strap                 : 16; /**< [ 15:  0](RO/H) GPIO strap data of GPIO pins 64-79. Unimplemented pins bits read as 0. */
#else /* Word 0 - Little Endian */
        uint64_t strap                 : 16; /**< [ 15:  0](RO/H) GPIO strap data of GPIO pins 64-79. Unimplemented pins bits read as 0. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn83xx;
    struct cavm_gpio_strap1_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t strap                 : 32; /**< [ 31:  0](RO/H) GPIO strap data of GPIO pins 64 and above. Unimplemented pins bits read as 0. */
#else /* Word 0 - Little Endian */
        uint64_t strap                 : 32; /**< [ 31:  0](RO/H) GPIO strap data of GPIO pins 64 and above. Unimplemented pins bits read as 0. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn9;
    /* struct cavm_gpio_strap1_cn9 cn96xx; */
    struct cavm_gpio_strap1_cn98xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t strap                 : 20; /**< [ 19:  0](RO/H) GPIO strap data of GPIO pins 64 and above. Unimplemented pins bits read as 0. */
#else /* Word 0 - Little Endian */
        uint64_t strap                 : 20; /**< [ 19:  0](RO/H) GPIO strap data of GPIO pins 64 and above. Unimplemented pins bits read as 0. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } cn98xx;
    /* struct cavm_gpio_strap1_cn9 cnf95xx; */
    /* struct cavm_gpio_strap1_cn9 loki; */
};
typedef union cavm_gpio_strap1 cavm_gpio_strap1_t;

#define CAVM_GPIO_STRAP1 CAVM_GPIO_STRAP1_FUNC()
static inline uint64_t CAVM_GPIO_STRAP1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_STRAP1_FUNC(void)
{
    return 0x803000001418ll;
}

#define typedef_CAVM_GPIO_STRAP1 cavm_gpio_strap1_t
#define bustype_CAVM_GPIO_STRAP1 CSR_TYPE_NCB
#define basename_CAVM_GPIO_STRAP1 "GPIO_STRAP1"
#define device_bar_CAVM_GPIO_STRAP1 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_STRAP1 0
#define arguments_CAVM_GPIO_STRAP1 -1,-1,-1,-1

/**
 * Register (NCB) gpio_thermal_hot
 *
 * Chip Thermal Hot Register
 * This register reads and drives the thermal hot pin (THERMAL_HOT_L).
 *
 * This register is only accessible to the requestor(s) permitted with GPIO_PERMIT.
 *
 * This register is not accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_thermal_hot
{
    uint64_t u;
    struct cavm_gpio_thermal_hot_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t drv                   : 1;  /**< [  1:  1](R/W) Drive enable.
                                                                 0 = Disable driving THERMAL_HOT_L.
                                                                 1 = Enable the open drain output to drive low THERMAL_HOT_L. */
        uint64_t pin                   : 1;  /**< [  0:  0](RO/H) Inverted version of THERMAL_HOT_L.
                                                                 0 = THERMAL_HOT_L is not being driven (is being pulled high externally).
                                                                 1 = THERMAL_HOT_L is being driven (is near VSS). */
#else /* Word 0 - Little Endian */
        uint64_t pin                   : 1;  /**< [  0:  0](RO/H) Inverted version of THERMAL_HOT_L.
                                                                 0 = THERMAL_HOT_L is not being driven (is being pulled high externally).
                                                                 1 = THERMAL_HOT_L is being driven (is near VSS). */
        uint64_t drv                   : 1;  /**< [  1:  1](R/W) Drive enable.
                                                                 0 = Disable driving THERMAL_HOT_L.
                                                                 1 = Enable the open drain output to drive low THERMAL_HOT_L. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_thermal_hot_s cn; */
};
typedef union cavm_gpio_thermal_hot cavm_gpio_thermal_hot_t;

#define CAVM_GPIO_THERMAL_HOT CAVM_GPIO_THERMAL_HOT_FUNC()
static inline uint64_t CAVM_GPIO_THERMAL_HOT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_THERMAL_HOT_FUNC(void)
{
    if (cavm_is_model(OCTEONTX_CN9XXX))
        return 0x803000001618ll;
    __cavm_csr_fatal("GPIO_THERMAL_HOT", 0, 0, 0, 0, 0, 0, 0);
}

#define typedef_CAVM_GPIO_THERMAL_HOT cavm_gpio_thermal_hot_t
#define bustype_CAVM_GPIO_THERMAL_HOT CSR_TYPE_NCB
#define basename_CAVM_GPIO_THERMAL_HOT "GPIO_THERMAL_HOT"
#define device_bar_CAVM_GPIO_THERMAL_HOT 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_THERMAL_HOT 0
#define arguments_CAVM_GPIO_THERMAL_HOT -1,-1,-1,-1

/**
 * Register (NCB) gpio_tx1_clr
 *
 * GPIO Transmit Clear Mask Register
 * See GPIO_TX_CLR.
 */
union cavm_gpio_tx1_clr
{
    uint64_t u;
    struct cavm_gpio_tx1_clr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t clr                   : 32; /**< [ 31:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX1_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t clr                   : 32; /**< [ 31:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX1_DAT storage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_gpio_tx1_clr_cn8
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t clr                   : 29; /**< [ 28:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX1_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t clr                   : 29; /**< [ 28:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX1_DAT storage. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } cn8;
    /* struct cavm_gpio_tx1_clr_cn8 cn81xx; */
    struct cavm_gpio_tx1_clr_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t clr                   : 16; /**< [ 15:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX1_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t clr                   : 16; /**< [ 15:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX1_DAT storage. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn83xx;
    struct cavm_gpio_tx1_clr_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t clr                   : 32; /**< [ 31:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX1_DAT storage. Unimplemented pins bits read as 0. */
#else /* Word 0 - Little Endian */
        uint64_t clr                   : 32; /**< [ 31:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX1_DAT storage. Unimplemented pins bits read as 0. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn9;
};
typedef union cavm_gpio_tx1_clr cavm_gpio_tx1_clr_t;

#define CAVM_GPIO_TX1_CLR CAVM_GPIO_TX1_CLR_FUNC()
static inline uint64_t CAVM_GPIO_TX1_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_TX1_CLR_FUNC(void)
{
    return 0x803000001410ll;
}

#define typedef_CAVM_GPIO_TX1_CLR cavm_gpio_tx1_clr_t
#define bustype_CAVM_GPIO_TX1_CLR CSR_TYPE_NCB
#define basename_CAVM_GPIO_TX1_CLR "GPIO_TX1_CLR"
#define device_bar_CAVM_GPIO_TX1_CLR 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_TX1_CLR 0
#define arguments_CAVM_GPIO_TX1_CLR -1,-1,-1,-1

/**
 * Register (NCB) gpio_tx1_set
 *
 * GPIO Transmit Set Mask Register
 * See GPIO_TX_SET.
 */
union cavm_gpio_tx1_set
{
    uint64_t u;
    struct cavm_gpio_tx1_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t set                   : 32; /**< [ 31:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX1_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t set                   : 32; /**< [ 31:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX1_DAT storage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct cavm_gpio_tx1_set_cn8
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t set                   : 29; /**< [ 28:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX1_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t set                   : 29; /**< [ 28:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX1_DAT storage. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } cn8;
    /* struct cavm_gpio_tx1_set_cn8 cn81xx; */
    struct cavm_gpio_tx1_set_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t set                   : 16; /**< [ 15:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX1_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t set                   : 16; /**< [ 15:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX1_DAT storage. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn83xx;
    struct cavm_gpio_tx1_set_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t set                   : 32; /**< [ 31:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX1_DAT storage. Unimplemented pins bits read as 0. */
#else /* Word 0 - Little Endian */
        uint64_t set                   : 32; /**< [ 31:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX1_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX1_DAT storage. Unimplemented pins bits read as 0. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn9;
};
typedef union cavm_gpio_tx1_set cavm_gpio_tx1_set_t;

#define CAVM_GPIO_TX1_SET CAVM_GPIO_TX1_SET_FUNC()
static inline uint64_t CAVM_GPIO_TX1_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_TX1_SET_FUNC(void)
{
    return 0x803000001408ll;
}

#define typedef_CAVM_GPIO_TX1_SET cavm_gpio_tx1_set_t
#define bustype_CAVM_GPIO_TX1_SET CSR_TYPE_NCB
#define basename_CAVM_GPIO_TX1_SET "GPIO_TX1_SET"
#define device_bar_CAVM_GPIO_TX1_SET 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_TX1_SET 0
#define arguments_CAVM_GPIO_TX1_SET -1,-1,-1,-1

/**
 * Register (NCB) gpio_tx_clr
 *
 * GPIO Transmit Clear Mask Register
 * This register clears GPIO output data for the first 64 GPIOs, and GPIO_TX1_CLR the
 * remainder.
 *
 * Each bit in this register is only accessible to the requestor(s) permitted with
 * GPIO_BIT_PERMIT(), but error will not be reported when there are bits are not
 * permitted by GPIO_BIT_PERMIT().
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_tx_clr
{
    uint64_t u;
    struct cavm_gpio_tx_clr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t clr                   : 64; /**< [ 63:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 0. When read, [CLR]
                                                                 returns the GPIO_TX_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t clr                   : 64; /**< [ 63:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 0. When read, [CLR]
                                                                 returns the GPIO_TX_DAT storage. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_tx_clr_s cn8; */
    struct cavm_gpio_tx_clr_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t clr                   : 48; /**< [ 47:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 0. When read, [CLR]
                                                                 returns the GPIO_TX_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t clr                   : 48; /**< [ 47:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 0. When read, [CLR]
                                                                 returns the GPIO_TX_DAT storage. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct cavm_gpio_tx_clr_s cn83xx; */
    /* struct cavm_gpio_tx_clr_s cn9; */
};
typedef union cavm_gpio_tx_clr cavm_gpio_tx_clr_t;

#define CAVM_GPIO_TX_CLR CAVM_GPIO_TX_CLR_FUNC()
static inline uint64_t CAVM_GPIO_TX_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_TX_CLR_FUNC(void)
{
    return 0x803000000010ll;
}

#define typedef_CAVM_GPIO_TX_CLR cavm_gpio_tx_clr_t
#define bustype_CAVM_GPIO_TX_CLR CSR_TYPE_NCB
#define basename_CAVM_GPIO_TX_CLR "GPIO_TX_CLR"
#define device_bar_CAVM_GPIO_TX_CLR 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_TX_CLR 0
#define arguments_CAVM_GPIO_TX_CLR -1,-1,-1,-1

/**
 * Register (NCB) gpio_tx_set
 *
 * GPIO Transmit Set Mask Register
 * This register sets GPIO output data. GPIO_TX_SET sets the first 64 GPIOs, and
 * GPIO_TX1_SET the remainder.
 *
 * Each bit in this register is only accessible to the requestor(s) permitted with
 * GPIO_BIT_PERMIT(), but error will not be reported when there are bits are not
 * permitted by GPIO_BIT_PERMIT().
 *
 * When permitted, this register is accessible through ROM scripts; see SCR_WRITE32_S[ADDR].
 */
union cavm_gpio_tx_set
{
    uint64_t u;
    struct cavm_gpio_tx_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t set                   : 64; /**< [ 63:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 1. When read, [SET]
                                                                 returns the GPIO_TX_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t set                   : 64; /**< [ 63:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 1. When read, [SET]
                                                                 returns the GPIO_TX_DAT storage. */
#endif /* Word 0 - End */
    } s;
    /* struct cavm_gpio_tx_set_s cn8; */
    struct cavm_gpio_tx_set_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t set                   : 48; /**< [ 47:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 1. When read, [SET]
                                                                 returns the GPIO_TX_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t set                   : 48; /**< [ 47:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 1. When read, [SET]
                                                                 returns the GPIO_TX_DAT storage. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct cavm_gpio_tx_set_s cn83xx; */
    struct cavm_gpio_tx_set_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t set                   : 64; /**< [ 63:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 1. When read,
                                                                 [SET] returns the GPIO_TX_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t set                   : 64; /**< [ 63:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 1. When read,
                                                                 [SET] returns the GPIO_TX_DAT storage. */
#endif /* Word 0 - End */
    } cn9;
};
typedef union cavm_gpio_tx_set cavm_gpio_tx_set_t;

#define CAVM_GPIO_TX_SET CAVM_GPIO_TX_SET_FUNC()
static inline uint64_t CAVM_GPIO_TX_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t CAVM_GPIO_TX_SET_FUNC(void)
{
    return 0x803000000008ll;
}

#define typedef_CAVM_GPIO_TX_SET cavm_gpio_tx_set_t
#define bustype_CAVM_GPIO_TX_SET CSR_TYPE_NCB
#define basename_CAVM_GPIO_TX_SET "GPIO_TX_SET"
#define device_bar_CAVM_GPIO_TX_SET 0x0 /* PF_BAR0 */
#define busnum_CAVM_GPIO_TX_SET 0
#define arguments_CAVM_GPIO_TX_SET -1,-1,-1,-1

#endif /* __CAVM_CSRS_GPIO_H__ */
