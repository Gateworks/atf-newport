#ifndef __CAVM_CSRS_TRICKBOX__
#define __CAVM_CSRS_TRICKBOX__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2014  Cavium Networks (support@cavium.com). All rights
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

 *   * Neither the name of Cavium Networks nor the names of
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
 * Cavium TRICKBOX.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include "cavm-csr-plat.h"

#define TRICKBOX_CSR_BASE 0x87E013000000
#define TRICKBOX_CSR_SIZE 0x1000

/**
 * NCB32b - tb_tube
 *
 * Tube is used to display any characters being output by the test.  The tube
 * output is later used for post processing by validation script.  The data
 * should be written as a byte and not of any other size.  Any printable
 * ASCII character can be passed to the tube.  If character Ctrl+D (ASCII
 * value of 4) is passed to tube, then this indicates to the environment to
 * stop the test and terminate the simulation.
 */
typedef union tb_tube {
	uint32_t u;
	struct tb_tube_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t value                       : 8;  /**< R/W - Denotes the ASCII character to be printed. CTRL+D ends the simulation. */
#else
		uint32_t value                       : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct tb_tube_s                   cn88xx; */
} tb_tube_t;

#define TB_TUBE TB_TUBE_FUNC()
static inline uint64_t TB_TUBE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_TUBE_FUNC(void)
{
	return 0x000087E013000000ull;
}
#define typedef_TB_TUBE tb_tube_t
#define bustype_TB_TUBE CSR_TYPE_NCB32b
#define busnum_TB_TUBE 0
#define arguments_TB_TUBE -1,-1,-1,-1
#define basename_TB_TUBE "UBE"
#define offset_TB_TUBE (TB_TUBE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_pin_configuration
 *
 * This register is used to drive the associated pins which configure the
 * processor.  All processors are driven with these pin value.  Few of the
 * bits controls behavior of the processor at reset entry (for the subsequent
 * reset).
 */
typedef union tb_pin_configuration {
	uint32_t u;
	struct tb_pin_configuration_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_25_31              : 7;
		uint32_t disablenidebug              : 1;  /**< R/W - This bit is inverted and wired into NIDEN input of trustzone enabled
                                                                 processor.  This is an R/W bit.
                                                                 - 0 enables NIDEN
                                                                 - 1 disables NIDEN */
		uint32_t cfgnmfi                     : 1;  /**< R/W - This bit configures the NMFI for the processor. This is an R/W bit.
                                                                 - 0 indicates FIQ is not NMFI
                                                                 - 1 indicates FIQ is Non Mask able Fast Interrupt */
		uint32_t exceptinit                  : 1;  /**< R/W - This bit indicates ISA state upon exception entry for AArch32.  Equivalent
                                                                 to TE bit.  This is an R/W bit.  This bit takes effect on a reset.
                                                                 - 0 indicates ARM exception entry
                                                                 - 1 indicates Thumb exception entry */
		uint32_t reserved_21_21              : 1;
		uint32_t cp15disable                 : 1;  /**< R/W - This bit indicates disabling of CP15 register. This is an R/W bit.
                                                                 - 0 indicates enable CP15 access
                                                                 - 1 indicates disable CP15 access */
		uint32_t disablespnidebug            : 1;  /**< R/W - This bit is inverted and wired into SPNIDEN input of trustzone enabled
                                                                 processor.  This is an R/W bit.
                                                                 - 0 indicates enable SPNIDEN
                                                                 - 1 indicates disable SPNIDEN */
		uint32_t disablespidebug             : 1;  /**< R/W - This bit is inverted and wired into SPIDEN input of trustzone enabled
                                                                 processor.  This is an R/W bit.
                                                                 - 0 indicates enable SPIDEN input
                                                                 - 1 indicates disable SPIDEN input */
		uint32_t reserved_15_17              : 3;
		uint32_t config64                    : 1;  /**< R/W - This bit controls the boot into AArch64 on Cold reset. This is an R/W bit.
                                                                 - 0 indicates boot into AArch32
                                                                 - 1 indicates boot into AArch64. */
		uint32_t reserved_3_13               : 11;
		uint32_t cfgend                      : 1;  /**< R/W - This bit controls the CFGEND pin input to the processor under reset. This is an R/W bit.
                                                                 - 0 indicates Little Endian
                                                                 - 1 indicates Big Endian */
		uint32_t rw                          : 1;  /**< R/W - Register Width bit determines Arch state of the processor after reset.
                                                                 This is a Read Write (R/W) bit.  This bit takes effect only on reset.
                                                                 - 0 indicates AArch32
                                                                 - 1 indicates AArch64. */
		uint32_t hivecs                      : 1;  /**< R/W - This determines whether the processor resets to HIVECS location when reset
                                                                 is applied.  This is a Write Only bit.  This bit takes effect only on
                                                                 reset.
                                                                 - 0 indicates no HIVECS.
                                                                 - 1 indicates HIVECS is enabled when booting into AArch32. */
#else
		uint32_t hivecs                      : 1;
		uint32_t rw                          : 1;
		uint32_t cfgend                      : 1;
		uint32_t reserved_3_13               : 11;
		uint32_t config64                    : 1;
		uint32_t reserved_15_17              : 3;
		uint32_t disablespidebug             : 1;
		uint32_t disablespnidebug            : 1;
		uint32_t cp15disable                 : 1;
		uint32_t reserved_21_21              : 1;
		uint32_t exceptinit                  : 1;
		uint32_t cfgnmfi                     : 1;
		uint32_t disablenidebug              : 1;
		uint32_t reserved_25_31              : 7;
#endif
	} s;
	/* struct tb_pin_configuration_s      cn88xx; */
} tb_pin_configuration_t;

#define TB_PIN_CONFIGURATION TB_PIN_CONFIGURATION_FUNC()
static inline uint64_t TB_PIN_CONFIGURATION_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PIN_CONFIGURATION_FUNC(void)
{
	return 0x000087E013000004ull;
}
#define typedef_TB_PIN_CONFIGURATION tb_pin_configuration_t
#define bustype_TB_PIN_CONFIGURATION CSR_TYPE_NCB32b
#define busnum_TB_PIN_CONFIGURATION 0
#define arguments_TB_PIN_CONFIGURATION -1,-1,-1,-1
#define basename_TB_PIN_CONFIGURATION "IN_CONFIGURATION"
#define offset_TB_PIN_CONFIGURATION (TB_PIN_CONFIGURATION - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_schedule_fiq
 *
 * Write to ScheduleFIQ causes a trickbox to generate an FIQ into the
 * processor after the programmed number of cycles.  FIQ is asserted to
 * processors in TargetCPU.  The tests making use of the delay count does not
 * assume any significance of the programmed delay value.
 */
typedef union tb_schedule_fiq {
	uint32_t u;
	struct tb_schedule_fiq_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - - Write is number of cycles to wait
                                                                 - Read is a bitmask where each bit is the status of FIQ for a core
                                                                 - NOTE: Current Implementation of AEM trickbox returns ORed FIQ Status for all cores in
                                                                 bit[0]. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_schedule_fiq_s           cn88xx; */
} tb_schedule_fiq_t;

#define TB_SCHEDULE_FIQ TB_SCHEDULE_FIQ_FUNC()
static inline uint64_t TB_SCHEDULE_FIQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_SCHEDULE_FIQ_FUNC(void)
{
	return 0x000087E013000008ull;
}
#define typedef_TB_SCHEDULE_FIQ tb_schedule_fiq_t
#define bustype_TB_SCHEDULE_FIQ CSR_TYPE_NCB32b
#define busnum_TB_SCHEDULE_FIQ 0
#define arguments_TB_SCHEDULE_FIQ -1,-1,-1,-1
#define basename_TB_SCHEDULE_FIQ "CHEDULE_FIQ"
#define offset_TB_SCHEDULE_FIQ (TB_SCHEDULE_FIQ - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_schedule_irq
 *
 * A value of delay count is to be written into ScheduleIRQ register.  After
 * the specified delay count had elapsed, an IRQ will be asserted to
 * processors as specified in TargetCPU.  The tests making use of the delay
 * count does not assume any significance of the programmed delay value.
 */
typedef union tb_schedule_irq {
	uint32_t u;
	struct tb_schedule_irq_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - - Write is number of cycles to wait
                                                                 - Read is a bitmask where each bit is the status of FIQ for a core
                                                                 - NOTE: Current Implementation of AEM trickbox returns ORed FIQ Status for all cores in
                                                                 bit[0]. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_schedule_irq_s           cn88xx; */
} tb_schedule_irq_t;

#define TB_SCHEDULE_IRQ TB_SCHEDULE_IRQ_FUNC()
static inline uint64_t TB_SCHEDULE_IRQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_SCHEDULE_IRQ_FUNC(void)
{
	return 0x000087E01300000Cull;
}
#define typedef_TB_SCHEDULE_IRQ tb_schedule_irq_t
#define bustype_TB_SCHEDULE_IRQ CSR_TYPE_NCB32b
#define busnum_TB_SCHEDULE_IRQ 0
#define arguments_TB_SCHEDULE_IRQ -1,-1,-1,-1
#define basename_TB_SCHEDULE_IRQ "CHEDULE_IRQ"
#define offset_TB_SCHEDULE_IRQ (TB_SCHEDULE_IRQ - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_clear_fiq
 *
 * This register causes the trickbox to de-assert FIQ for processors
 * specified in TargetCPU if currently asserted.
 */
typedef union tb_clear_fiq {
	uint32_t u;
	struct tb_clear_fiq_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - A write of 0x0000_0000 to this register, deasserts the FIQ. All
                                                                 processors as specified in TargetCPU would get their FIQ signals
                                                                 deasserted. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_clear_fiq_s              cn88xx; */
} tb_clear_fiq_t;

#define TB_CLEAR_FIQ TB_CLEAR_FIQ_FUNC()
static inline uint64_t TB_CLEAR_FIQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_CLEAR_FIQ_FUNC(void)
{
	return 0x000087E013000010ull;
}
#define typedef_TB_CLEAR_FIQ tb_clear_fiq_t
#define bustype_TB_CLEAR_FIQ CSR_TYPE_NCB32b
#define busnum_TB_CLEAR_FIQ 0
#define arguments_TB_CLEAR_FIQ -1,-1,-1,-1
#define basename_TB_CLEAR_FIQ "LEAR_FIQ"
#define offset_TB_CLEAR_FIQ (TB_CLEAR_FIQ - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_clear_irq
 *
 * Write to ClearIRQ register to de-assert IRQ for processor as specified in
 * TargetCPU if currently asserted.  There is no effect on writing to this
 * register if IRQ is not asserted.
 */
typedef union tb_clear_irq {
	uint32_t u;
	struct tb_clear_irq_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - A write of 0x0000_0000 to this register, deasserts the IRQ. All
                                                                 processors as specified in TargetCPU would get their IRQ signals
                                                                 deasserted. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_clear_irq_s              cn88xx; */
} tb_clear_irq_t;

#define TB_CLEAR_IRQ TB_CLEAR_IRQ_FUNC()
static inline uint64_t TB_CLEAR_IRQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_CLEAR_IRQ_FUNC(void)
{
	return 0x000087E013000014ull;
}
#define typedef_TB_CLEAR_IRQ tb_clear_irq_t
#define bustype_TB_CLEAR_IRQ CSR_TYPE_NCB32b
#define busnum_TB_CLEAR_IRQ 0
#define arguments_TB_CLEAR_IRQ -1,-1,-1,-1
#define basename_TB_CLEAR_IRQ "LEAR_IRQ"
#define offset_TB_CLEAR_IRQ (TB_CLEAR_IRQ - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_schedule_rst
 *
 * This register indicates the specified number of cycles after which an
 * associated reset as specified in SWResetCtl is applied on the processors
 * as defined by TargetCPU.
 *
 * Writing a value to ScheduleRST Value indicates number of cycles after
 * which RESET is generated to the associated processor.  If value is 0,
 * RESET is driven into immediately.  Drives RESET into the processors as
 * specified in the TargetCPU register.
 */
typedef union tb_schedule_rst {
	uint32_t u;
	struct tb_schedule_rst_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_schedule_rst_s           cn88xx; */
} tb_schedule_rst_t;

#define TB_SCHEDULE_RST TB_SCHEDULE_RST_FUNC()
static inline uint64_t TB_SCHEDULE_RST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_SCHEDULE_RST_FUNC(void)
{
	return 0x000087E013000018ull;
}
#define typedef_TB_SCHEDULE_RST tb_schedule_rst_t
#define bustype_TB_SCHEDULE_RST CSR_TYPE_NCB32b
#define busnum_TB_SCHEDULE_RST 0
#define arguments_TB_SCHEDULE_RST -1,-1,-1,-1
#define basename_TB_SCHEDULE_RST "CHEDULE_RST"
#define offset_TB_SCHEDULE_RST (TB_SCHEDULE_RST - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn_lo2
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * Second abort region. Updates to this affect ABORT_REG64_LO2
 */
typedef union tb_abort_rgn_lo2 {
	uint32_t u;
	struct tb_abort_rgn_lo2_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn_lo2_s          cn88xx; */
} tb_abort_rgn_lo2_t;

#define TB_ABORT_RGN_LO2 TB_ABORT_RGN_LO2_FUNC()
static inline uint64_t TB_ABORT_RGN_LO2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN_LO2_FUNC(void)
{
	return 0x000087E013000038ull;
}
#define typedef_TB_ABORT_RGN_LO2 tb_abort_rgn_lo2_t
#define bustype_TB_ABORT_RGN_LO2 CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN_LO2 0
#define arguments_TB_ABORT_RGN_LO2 -1,-1,-1,-1
#define basename_TB_ABORT_RGN_LO2 "BORT_RGN_LO2"
#define offset_TB_ABORT_RGN_LO2 (TB_ABORT_RGN_LO2 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn_hi2
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * Second abort region. Updates to this affect ABORT_REG64_HI2
 */
typedef union tb_abort_rgn_hi2 {
	uint32_t u;
	struct tb_abort_rgn_hi2_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn_hi2_s          cn88xx; */
} tb_abort_rgn_hi2_t;

#define TB_ABORT_RGN_HI2 TB_ABORT_RGN_HI2_FUNC()
static inline uint64_t TB_ABORT_RGN_HI2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN_HI2_FUNC(void)
{
	return 0x000087E01300003Cull;
}
#define typedef_TB_ABORT_RGN_HI2 tb_abort_rgn_hi2_t
#define bustype_TB_ABORT_RGN_HI2 CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN_HI2 0
#define arguments_TB_ABORT_RGN_HI2 -1,-1,-1,-1
#define basename_TB_ABORT_RGN_HI2 "BORT_RGN_HI2"
#define offset_TB_ABORT_RGN_HI2 (TB_ABORT_RGN_HI2 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn_lo1
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * First abort region. Updates to this affect ABORT_REG64_LO1
 */
typedef union tb_abort_rgn_lo1 {
	uint32_t u;
	struct tb_abort_rgn_lo1_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn_lo1_s          cn88xx; */
} tb_abort_rgn_lo1_t;

#define TB_ABORT_RGN_LO1 TB_ABORT_RGN_LO1_FUNC()
static inline uint64_t TB_ABORT_RGN_LO1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN_LO1_FUNC(void)
{
	return 0x000087E013000040ull;
}
#define typedef_TB_ABORT_RGN_LO1 tb_abort_rgn_lo1_t
#define bustype_TB_ABORT_RGN_LO1 CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN_LO1 0
#define arguments_TB_ABORT_RGN_LO1 -1,-1,-1,-1
#define basename_TB_ABORT_RGN_LO1 "BORT_RGN_LO1"
#define offset_TB_ABORT_RGN_LO1 (TB_ABORT_RGN_LO1 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn_hi1
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * First abort region. Updates to this affect ABORT_REG64_HI1
 */
typedef union tb_abort_rgn_hi1 {
	uint32_t u;
	struct tb_abort_rgn_hi1_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn_hi1_s          cn88xx; */
} tb_abort_rgn_hi1_t;

#define TB_ABORT_RGN_HI1 TB_ABORT_RGN_HI1_FUNC()
static inline uint64_t TB_ABORT_RGN_HI1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN_HI1_FUNC(void)
{
	return 0x000087E013000044ull;
}
#define typedef_TB_ABORT_RGN_HI1 tb_abort_rgn_hi1_t
#define bustype_TB_ABORT_RGN_HI1 CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN_HI1 0
#define arguments_TB_ABORT_RGN_HI1 -1,-1,-1,-1
#define basename_TB_ABORT_RGN_HI1 "BORT_RGN_HI1"
#define offset_TB_ABORT_RGN_HI1 (TB_ABORT_RGN_HI1 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_dbg_control
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register allows the testing and direct driving of processor
 * debug signals.
 */
typedef union tb_dbg_control {
	uint32_t u;
	struct tb_dbg_control_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t dbgpaddr31                  : 1;  /**< R/W - Drives PADDR31.  When HIGH, debug port accesses the processor debug
                                                                 register as if an external debugger was connected (different memory map
                                                                 rights) */
		uint32_t dbgswen                     : 1;  /**< R/W - This bit drives DBGSWEN
                                                                 - 0 DBGSWEN is deasserted
                                                                 - 1 DBGSWEN is asserted */
		uint32_t reserved_4_6                : 3;
		uint32_t dbgacklow                   : 1;  /**< RO - Indicates whether DBGACK is LOW since last cleared (level detect). Read only bit. */
		uint32_t dbgackhigh                  : 1;  /**< RO - Indicates whether DBGACK is HIGH since last cleared (level detect). Read only bit. */
		uint32_t one_in_avs                  : 1;  /**< RO - Reserved. */
		uint32_t dbgen                       : 1;  /**< R/W - Drives DBGEN pin. Read Write bit.
                                                                 - 0 DBGEN deasserted
                                                                 - 1 DBGEN asserted */
#else
		uint32_t dbgen                       : 1;
		uint32_t one_in_avs                  : 1;
		uint32_t dbgackhigh                  : 1;
		uint32_t dbgacklow                   : 1;
		uint32_t reserved_4_6                : 3;
		uint32_t dbgswen                     : 1;
		uint32_t dbgpaddr31                  : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct tb_dbg_control_s            cn88xx; */
} tb_dbg_control_t;

#define TB_DBG_CONTROL TB_DBG_CONTROL_FUNC()
static inline uint64_t TB_DBG_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_DBG_CONTROL_FUNC(void)
{
	return 0x000087E013000054ull;
}
#define typedef_TB_DBG_CONTROL tb_dbg_control_t
#define bustype_TB_DBG_CONTROL CSR_TYPE_NCB32b
#define busnum_TB_DBG_CONTROL 0
#define arguments_TB_DBG_CONTROL -1,-1,-1,-1
#define basename_TB_DBG_CONTROL "BG_CONTROL"
#define offset_TB_DBG_CONTROL (TB_DBG_CONTROL - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_dormant_control
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register controls the power down features of the processor.
 */
typedef union tb_dormant_control {
	uint32_t u;
	struct tb_dormant_control_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_13_31              : 19;
		uint32_t dbgrstreq                   : 1;  /**< R/W - When `1` applies cold reset to the TargetCPU */
		uint32_t dbgpwrupreq                 : 1;  /**< R/W - 1 indicates power up initiated for the TargetCPU */
		uint32_t standbywfe                  : 1;  /**< R/W - STANDBYWFE signal from processor; indicates when processor is in WFE, 1
                                                                 indicates target processor has entered WFE */
		uint32_t reserved_3_9                : 7;
		uint32_t ndbgpwrdwnreq               : 1;  /**< R/W - 0 indicates power down initiated for the TargetCPU */
		uint32_t dbgnopwrdwn                 : 1;  /**< R/W - Reflects the DBGNOPWRDWN signal of TargetCPU */
		uint32_t standbywfi                  : 1;  /**< RO - Signal from processor indicating whether it is in stand-by waiting for
                                                                 interrupt.
                                                                 - 1 indicates target processor has entered WFI */
#else
		uint32_t standbywfi                  : 1;
		uint32_t dbgnopwrdwn                 : 1;
		uint32_t ndbgpwrdwnreq               : 1;
		uint32_t reserved_3_9                : 7;
		uint32_t standbywfe                  : 1;
		uint32_t dbgpwrupreq                 : 1;
		uint32_t dbgrstreq                   : 1;
		uint32_t reserved_13_31              : 19;
#endif
	} s;
	/* struct tb_dormant_control_s        cn88xx; */
} tb_dormant_control_t;

#define TB_DORMANT_CONTROL TB_DORMANT_CONTROL_FUNC()
static inline uint64_t TB_DORMANT_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_DORMANT_CONTROL_FUNC(void)
{
	return 0x000087E0130000A4ull;
}
#define typedef_TB_DORMANT_CONTROL tb_dormant_control_t
#define bustype_TB_DORMANT_CONTROL CSR_TYPE_NCB32b
#define busnum_TB_DORMANT_CONTROL 0
#define arguments_TB_DORMANT_CONTROL -1,-1,-1,-1
#define basename_TB_DORMANT_CONTROL "ORMANT_CONTROL"
#define offset_TB_DORMANT_CONTROL (TB_DORMANT_CONTROL - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_core_generated_irq_pin_value
 *
 * The processor in some cases is capable of generating interrupt which it
 * drives out in some pins to be handled later.  These interrupt can mean an
 * overflow event which needs to be communicated to the running software.
 * Each processor has a set of pins, which it drives, to indicate an
 * Interrupt or event being generated from processor.  These pins in a system
 * environment could be routed through GIC back into the processor to handle
 * the interrupt generated by processor.  The GIC serves here to prioritize
 * the processor interrupt along with other interrupts of the system.
 *
 * The set of interrupts under this category which needs to be visible to the
 * test are PMUIRQ, CTIIRQ and COMMIRQ.  These interrupts which originates
 * from the processor are to be captured by the trickbox.  The test can later
 * read from the trickbox to know the status of these signals.  Two registers
 * in trickbox are necessary to support this feature.
 *
 * - 1. Extended_TargetCpu to indicate the target processor whose status is to be read.
 * - 2. CORE_GENERATED_IRQ_PIN_VALUE to read the value of the associated pins of the TargetCPU.
 *
 * A logical target processor number is written into Extended_TargetCpu
 * register and a subsequent read from CORE_GENERATED_IRQ_PIN_VALUE should
 * return a value of the corresponding interrupt pins for that logical
 * processor.
 *
 * If the pin is edge triggered it is to be latched such that the processor
 * reading the status of this pin at a later instance in time identifies that
 * the pin was asserted.  If the pin is level triggered then no latching
 * would be required as the status can be read by reading the pin value
 * directly.
 */
typedef union tb_core_generated_irq_pin_value {
	uint32_t u;
	struct tb_core_generated_irq_pin_value_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t commirq                     : 1;  /**< R/W - Reads: value 1 indicates COMMIRQ asserted, value 0 indicates
                                                                 COMMIRQ de-asserted

                                                                 Writes: if latched, value 1 will clear the latched status of
                                                                 COMMIRQ and not alter the source of the COMMIRQ. if not latched
                                                                 do nothing. value 0 - do nothing */
		uint32_t reserved_5_7                : 3;
		uint32_t ctiirq                      : 1;  /**< R/W - Reads: value 1 indicates CTIIRQ asserted, value 0 indicates
                                                                 CTIIRQ de-asserted

                                                                 Writes: if latched, value 1 will clear the latched status of
                                                                 CTIIRQ and not alter the source of the CTIIRQ. if not latched
                                                                 do nothing. value 0 - do nothing */
		uint32_t reserved_1_3                : 3;
		uint32_t pmuirq                      : 1;  /**< R/W - Reads: value 1 indicates PMUIRQ asserted, value 0 indicates PMUIRQ
                                                                 de-asserted

                                                                 Writes: if latched, value 1 will clear the latched status of
                                                                 PMUIRQ and not alter the source of the PMUIRQ. if not latched
                                                                 do nothing. value 0 - do nothing */
#else
		uint32_t pmuirq                      : 1;
		uint32_t reserved_1_3                : 3;
		uint32_t ctiirq                      : 1;
		uint32_t reserved_5_7                : 3;
		uint32_t commirq                     : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct tb_core_generated_irq_pin_value_s cn88xx; */
} tb_core_generated_irq_pin_value_t;

#define TB_CORE_GENERATED_IRQ_PIN_VALUE TB_CORE_GENERATED_IRQ_PIN_VALUE_FUNC()
static inline uint64_t TB_CORE_GENERATED_IRQ_PIN_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_CORE_GENERATED_IRQ_PIN_VALUE_FUNC(void)
{
	return 0x000087E0130000B0ull;
}
#define typedef_TB_CORE_GENERATED_IRQ_PIN_VALUE tb_core_generated_irq_pin_value_t
#define bustype_TB_CORE_GENERATED_IRQ_PIN_VALUE CSR_TYPE_NCB32b
#define busnum_TB_CORE_GENERATED_IRQ_PIN_VALUE 0
#define arguments_TB_CORE_GENERATED_IRQ_PIN_VALUE -1,-1,-1,-1
#define basename_TB_CORE_GENERATED_IRQ_PIN_VALUE "ORE_GENERATED_IRQ_PIN_VALUE"
#define offset_TB_CORE_GENERATED_IRQ_PIN_VALUE (TB_CORE_GENERATED_IRQ_PIN_VALUE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_extended_target_cpu
 *
 * Logical processor number
 *
 */
typedef union tb_extended_target_cpu {
	uint32_t u;
	struct tb_extended_target_cpu_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_extended_target_cpu_s    cn88xx; */
} tb_extended_target_cpu_t;

#define TB_EXTENDED_TARGET_CPU TB_EXTENDED_TARGET_CPU_FUNC()
static inline uint64_t TB_EXTENDED_TARGET_CPU_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_EXTENDED_TARGET_CPU_FUNC(void)
{
	return 0x000087E0130000F0ull;
}
#define typedef_TB_EXTENDED_TARGET_CPU tb_extended_target_cpu_t
#define bustype_TB_EXTENDED_TARGET_CPU CSR_TYPE_NCB32b
#define busnum_TB_EXTENDED_TARGET_CPU 0
#define arguments_TB_EXTENDED_TARGET_CPU -1,-1,-1,-1
#define basename_TB_EXTENDED_TARGET_CPU "XTENDED_TARGET_CPU"
#define offset_TB_EXTENDED_TARGET_CPU (TB_EXTENDED_TARGET_CPU - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_target_cpu
 *
 * This register specifies the processor on which an associated event is to
 * be generated.  It indicates the processor to which the pins IRQ, FIQ or
 * debug controls are associated.
 */
typedef union tb_target_cpu {
	uint32_t u;
	struct tb_target_cpu_s {
#ifdef __BIG_ENDIAN
		uint32_t mask                        : 32; /**< R/W - - 0 - associated processor is not participating in the control operation.
                                                                 - 1 - Associated processor participates in the control operation. */
#else
		uint32_t mask                        : 32;
#endif
	} s;
	/* struct tb_target_cpu_s             cn88xx; */
} tb_target_cpu_t;

#define TB_TARGET_CPU TB_TARGET_CPU_FUNC()
static inline uint64_t TB_TARGET_CPU_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_TARGET_CPU_FUNC(void)
{
	return 0x000087E0130000FCull;
}
#define typedef_TB_TARGET_CPU tb_target_cpu_t
#define bustype_TB_TARGET_CPU CSR_TYPE_NCB32b
#define busnum_TB_TARGET_CPU 0
#define arguments_TB_TARGET_CPU -1,-1,-1,-1
#define basename_TB_TARGET_CPU "ARGET_CPU"
#define offset_TB_TARGET_CPU (TB_TARGET_CPU - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn64_lo1
 *
 * First 64bit abort region. Note that writes to ABORT_RGN_LO1 actually
 * change this register and zero ABORT_RGN64_LO1_HI.
 */
typedef union tb_abort_rgn64_lo1 {
	uint32_t u;
	struct tb_abort_rgn64_lo1_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn64_lo1_s        cn88xx; */
} tb_abort_rgn64_lo1_t;

#define TB_ABORT_RGN64_LO1 TB_ABORT_RGN64_LO1_FUNC()
static inline uint64_t TB_ABORT_RGN64_LO1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN64_LO1_FUNC(void)
{
	return 0x000087E013000100ull;
}
#define typedef_TB_ABORT_RGN64_LO1 tb_abort_rgn64_lo1_t
#define bustype_TB_ABORT_RGN64_LO1 CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN64_LO1 0
#define arguments_TB_ABORT_RGN64_LO1 -1,-1,-1,-1
#define basename_TB_ABORT_RGN64_LO1 "BORT_RGN64_LO1"
#define offset_TB_ABORT_RGN64_LO1 (TB_ABORT_RGN64_LO1 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn64_lo1_hi
 *
 * First 64bit abort region. Note that writes to ABORT_RGN_LO1 actually
 * zero this regsiter.
 */
typedef union tb_abort_rgn64_lo1_hi {
	uint32_t u;
	struct tb_abort_rgn64_lo1_hi_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn64_lo1_hi_s     cn88xx; */
} tb_abort_rgn64_lo1_hi_t;

#define TB_ABORT_RGN64_LO1_HI TB_ABORT_RGN64_LO1_HI_FUNC()
static inline uint64_t TB_ABORT_RGN64_LO1_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN64_LO1_HI_FUNC(void)
{
	return 0x000087E013000104ull;
}
#define typedef_TB_ABORT_RGN64_LO1_HI tb_abort_rgn64_lo1_hi_t
#define bustype_TB_ABORT_RGN64_LO1_HI CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN64_LO1_HI 0
#define arguments_TB_ABORT_RGN64_LO1_HI -1,-1,-1,-1
#define basename_TB_ABORT_RGN64_LO1_HI "BORT_RGN64_LO1_HI"
#define offset_TB_ABORT_RGN64_LO1_HI (TB_ABORT_RGN64_LO1_HI - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn64_hi1
 *
 * First 64bit abort region. Note that writes to ABORT_RGN_HI1 actually
 * change this register and zero ABORT_RGN64_HI1_HI.
 */
typedef union tb_abort_rgn64_hi1 {
	uint32_t u;
	struct tb_abort_rgn64_hi1_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn64_hi1_s        cn88xx; */
} tb_abort_rgn64_hi1_t;

#define TB_ABORT_RGN64_HI1 TB_ABORT_RGN64_HI1_FUNC()
static inline uint64_t TB_ABORT_RGN64_HI1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN64_HI1_FUNC(void)
{
	return 0x000087E013000108ull;
}
#define typedef_TB_ABORT_RGN64_HI1 tb_abort_rgn64_hi1_t
#define bustype_TB_ABORT_RGN64_HI1 CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN64_HI1 0
#define arguments_TB_ABORT_RGN64_HI1 -1,-1,-1,-1
#define basename_TB_ABORT_RGN64_HI1 "BORT_RGN64_HI1"
#define offset_TB_ABORT_RGN64_HI1 (TB_ABORT_RGN64_HI1 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn64_hi1_hi
 *
 * First 64bit abort region. Note that writes to ABORT_RGN_HI1 actually
 * zero this regsiter.
 */
typedef union tb_abort_rgn64_hi1_hi {
	uint32_t u;
	struct tb_abort_rgn64_hi1_hi_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn64_hi1_hi_s     cn88xx; */
} tb_abort_rgn64_hi1_hi_t;

#define TB_ABORT_RGN64_HI1_HI TB_ABORT_RGN64_HI1_HI_FUNC()
static inline uint64_t TB_ABORT_RGN64_HI1_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN64_HI1_HI_FUNC(void)
{
	return 0x000087E01300010Cull;
}
#define typedef_TB_ABORT_RGN64_HI1_HI tb_abort_rgn64_hi1_hi_t
#define bustype_TB_ABORT_RGN64_HI1_HI CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN64_HI1_HI 0
#define arguments_TB_ABORT_RGN64_HI1_HI -1,-1,-1,-1
#define basename_TB_ABORT_RGN64_HI1_HI "BORT_RGN64_HI1_HI"
#define offset_TB_ABORT_RGN64_HI1_HI (TB_ABORT_RGN64_HI1_HI - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn64_lo2
 *
 * Second 64bit abort region. Note that writes to ABORT_RGN_LO2 actually
 * change this register and zero ABORT_RGN64_LO2_HI.
 */
typedef union tb_abort_rgn64_lo2 {
	uint32_t u;
	struct tb_abort_rgn64_lo2_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn64_lo2_s        cn88xx; */
} tb_abort_rgn64_lo2_t;

#define TB_ABORT_RGN64_LO2 TB_ABORT_RGN64_LO2_FUNC()
static inline uint64_t TB_ABORT_RGN64_LO2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN64_LO2_FUNC(void)
{
	return 0x000087E013000110ull;
}
#define typedef_TB_ABORT_RGN64_LO2 tb_abort_rgn64_lo2_t
#define bustype_TB_ABORT_RGN64_LO2 CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN64_LO2 0
#define arguments_TB_ABORT_RGN64_LO2 -1,-1,-1,-1
#define basename_TB_ABORT_RGN64_LO2 "BORT_RGN64_LO2"
#define offset_TB_ABORT_RGN64_LO2 (TB_ABORT_RGN64_LO2 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn64_lo2_hi
 *
 * Second 64bit abort region. Note that writes to ABORT_RGN_LO2 actually
 * zero this regsiter.
 */
typedef union tb_abort_rgn64_lo2_hi {
	uint32_t u;
	struct tb_abort_rgn64_lo2_hi_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn64_lo2_hi_s     cn88xx; */
} tb_abort_rgn64_lo2_hi_t;

#define TB_ABORT_RGN64_LO2_HI TB_ABORT_RGN64_LO2_HI_FUNC()
static inline uint64_t TB_ABORT_RGN64_LO2_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN64_LO2_HI_FUNC(void)
{
	return 0x000087E013000114ull;
}
#define typedef_TB_ABORT_RGN64_LO2_HI tb_abort_rgn64_lo2_hi_t
#define bustype_TB_ABORT_RGN64_LO2_HI CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN64_LO2_HI 0
#define arguments_TB_ABORT_RGN64_LO2_HI -1,-1,-1,-1
#define basename_TB_ABORT_RGN64_LO2_HI "BORT_RGN64_LO2_HI"
#define offset_TB_ABORT_RGN64_LO2_HI (TB_ABORT_RGN64_LO2_HI - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn64_hi2
 *
 * Second 64bit abort region. Note that writes to ABORT_RGN_HI2 actually
 * change this register and zero ABORT_RGN64_HI2_HI.
 */
typedef union tb_abort_rgn64_hi2 {
	uint32_t u;
	struct tb_abort_rgn64_hi2_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn64_hi2_s        cn88xx; */
} tb_abort_rgn64_hi2_t;

#define TB_ABORT_RGN64_HI2 TB_ABORT_RGN64_HI2_FUNC()
static inline uint64_t TB_ABORT_RGN64_HI2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN64_HI2_FUNC(void)
{
	return 0x000087E013000118ull;
}
#define typedef_TB_ABORT_RGN64_HI2 tb_abort_rgn64_hi2_t
#define bustype_TB_ABORT_RGN64_HI2 CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN64_HI2 0
#define arguments_TB_ABORT_RGN64_HI2 -1,-1,-1,-1
#define basename_TB_ABORT_RGN64_HI2 "BORT_RGN64_HI2"
#define offset_TB_ABORT_RGN64_HI2 (TB_ABORT_RGN64_HI2 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_abort_rgn64_hi2_hi
 *
 * Second 64bit abort region. Note that writes to ABORT_RGN_HI2 actually
 * zero this regsiter.
 */
typedef union tb_abort_rgn64_hi2_hi {
	uint32_t u;
	struct tb_abort_rgn64_hi2_hi_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_abort_rgn64_hi2_hi_s     cn88xx; */
} tb_abort_rgn64_hi2_hi_t;

#define TB_ABORT_RGN64_HI2_HI TB_ABORT_RGN64_HI2_HI_FUNC()
static inline uint64_t TB_ABORT_RGN64_HI2_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ABORT_RGN64_HI2_HI_FUNC(void)
{
	return 0x000087E01300011Cull;
}
#define typedef_TB_ABORT_RGN64_HI2_HI tb_abort_rgn64_hi2_hi_t
#define bustype_TB_ABORT_RGN64_HI2_HI CSR_TYPE_NCB32b
#define busnum_TB_ABORT_RGN64_HI2_HI 0
#define arguments_TB_ABORT_RGN64_HI2_HI -1,-1,-1,-1
#define basename_TB_ABORT_RGN64_HI2_HI "BORT_RGN64_HI2_HI"
#define offset_TB_ABORT_RGN64_HI2_HI (TB_ABORT_RGN64_HI2_HI - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu0addr
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union tb_ppu0addr {
	uint32_t u;
	struct tb_ppu0addr_s {
#ifdef __BIG_ENDIAN
		uint32_t address                     : 22; /**< R/W - Address bits indicating the starting address of programmed PPU region */
		uint32_t reserved_0_9                : 10;
#else
		uint32_t reserved_0_9                : 10;
		uint32_t address                     : 22;
#endif
	} s;
	/* struct tb_ppu0addr_s               cn88xx; */
} tb_ppu0addr_t;

#define TB_PPU0ADDR TB_PPU0ADDR_FUNC()
static inline uint64_t TB_PPU0ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU0ADDR_FUNC(void)
{
	return 0x000087E013000230ull;
}
#define typedef_TB_PPU0ADDR tb_ppu0addr_t
#define bustype_TB_PPU0ADDR CSR_TYPE_NCB32b
#define busnum_TB_PPU0ADDR 0
#define arguments_TB_PPU0ADDR -1,-1,-1,-1
#define basename_TB_PPU0ADDR "PU0ADDR"
#define offset_TB_PPU0ADDR (TB_PPU0ADDR - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu0mask
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union tb_ppu0mask {
	uint32_t u;
	struct tb_ppu0mask_s {
#ifdef __BIG_ENDIAN
		uint32_t address_mask                : 22; /**< R/W - Used to define the range over which the PPU is enabled for */
		uint32_t reserved_3_9                : 7;
		uint32_t mode                        : 1;  /**< R/W - The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
		uint32_t non_secure                  : 1;  /**< R/W - - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
		uint32_t enable                      : 1;  /**< R/W - - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else
		uint32_t enable                      : 1;
		uint32_t non_secure                  : 1;
		uint32_t mode                        : 1;
		uint32_t reserved_3_9                : 7;
		uint32_t address_mask                : 22;
#endif
	} s;
	/* struct tb_ppu0mask_s               cn88xx; */
} tb_ppu0mask_t;

#define TB_PPU0MASK TB_PPU0MASK_FUNC()
static inline uint64_t TB_PPU0MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU0MASK_FUNC(void)
{
	return 0x000087E013000234ull;
}
#define typedef_TB_PPU0MASK tb_ppu0mask_t
#define bustype_TB_PPU0MASK CSR_TYPE_NCB32b
#define busnum_TB_PPU0MASK 0
#define arguments_TB_PPU0MASK -1,-1,-1,-1
#define basename_TB_PPU0MASK "PU0MASK"
#define offset_TB_PPU0MASK (TB_PPU0MASK - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu1addr
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union tb_ppu1addr {
	uint32_t u;
	struct tb_ppu1addr_s {
#ifdef __BIG_ENDIAN
		uint32_t address                     : 22; /**< R/W - Address bits indicating the starting address of programmed PPU region */
		uint32_t reserved_0_9                : 10;
#else
		uint32_t reserved_0_9                : 10;
		uint32_t address                     : 22;
#endif
	} s;
	/* struct tb_ppu1addr_s               cn88xx; */
} tb_ppu1addr_t;

#define TB_PPU1ADDR TB_PPU1ADDR_FUNC()
static inline uint64_t TB_PPU1ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU1ADDR_FUNC(void)
{
	return 0x000087E013000238ull;
}
#define typedef_TB_PPU1ADDR tb_ppu1addr_t
#define bustype_TB_PPU1ADDR CSR_TYPE_NCB32b
#define busnum_TB_PPU1ADDR 0
#define arguments_TB_PPU1ADDR -1,-1,-1,-1
#define basename_TB_PPU1ADDR "PU1ADDR"
#define offset_TB_PPU1ADDR (TB_PPU1ADDR - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu1mask
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union tb_ppu1mask {
	uint32_t u;
	struct tb_ppu1mask_s {
#ifdef __BIG_ENDIAN
		uint32_t address_mask                : 22; /**< R/W - Used to define the range over which the PPU is enabled for */
		uint32_t reserved_3_9                : 7;
		uint32_t mode                        : 1;  /**< R/W - The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
		uint32_t non_secure                  : 1;  /**< R/W - - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
		uint32_t enable                      : 1;  /**< R/W - - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else
		uint32_t enable                      : 1;
		uint32_t non_secure                  : 1;
		uint32_t mode                        : 1;
		uint32_t reserved_3_9                : 7;
		uint32_t address_mask                : 22;
#endif
	} s;
	/* struct tb_ppu1mask_s               cn88xx; */
} tb_ppu1mask_t;

#define TB_PPU1MASK TB_PPU1MASK_FUNC()
static inline uint64_t TB_PPU1MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU1MASK_FUNC(void)
{
	return 0x000087E01300023Cull;
}
#define typedef_TB_PPU1MASK tb_ppu1mask_t
#define bustype_TB_PPU1MASK CSR_TYPE_NCB32b
#define busnum_TB_PPU1MASK 0
#define arguments_TB_PPU1MASK -1,-1,-1,-1
#define basename_TB_PPU1MASK "PU1MASK"
#define offset_TB_PPU1MASK (TB_PPU1MASK - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu2addr
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union tb_ppu2addr {
	uint32_t u;
	struct tb_ppu2addr_s {
#ifdef __BIG_ENDIAN
		uint32_t address                     : 22; /**< R/W - Address bits indicating the starting address of programmed PPU region */
		uint32_t reserved_0_9                : 10;
#else
		uint32_t reserved_0_9                : 10;
		uint32_t address                     : 22;
#endif
	} s;
	/* struct tb_ppu2addr_s               cn88xx; */
} tb_ppu2addr_t;

#define TB_PPU2ADDR TB_PPU2ADDR_FUNC()
static inline uint64_t TB_PPU2ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU2ADDR_FUNC(void)
{
	return 0x000087E013000240ull;
}
#define typedef_TB_PPU2ADDR tb_ppu2addr_t
#define bustype_TB_PPU2ADDR CSR_TYPE_NCB32b
#define busnum_TB_PPU2ADDR 0
#define arguments_TB_PPU2ADDR -1,-1,-1,-1
#define basename_TB_PPU2ADDR "PU2ADDR"
#define offset_TB_PPU2ADDR (TB_PPU2ADDR - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu2mask
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union tb_ppu2mask {
	uint32_t u;
	struct tb_ppu2mask_s {
#ifdef __BIG_ENDIAN
		uint32_t address_mask                : 22; /**< R/W - Used to define the range over which the PPU is enabled for */
		uint32_t reserved_3_9                : 7;
		uint32_t mode                        : 1;  /**< R/W - The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
		uint32_t non_secure                  : 1;  /**< R/W - - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
		uint32_t enable                      : 1;  /**< R/W - - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else
		uint32_t enable                      : 1;
		uint32_t non_secure                  : 1;
		uint32_t mode                        : 1;
		uint32_t reserved_3_9                : 7;
		uint32_t address_mask                : 22;
#endif
	} s;
	/* struct tb_ppu2mask_s               cn88xx; */
} tb_ppu2mask_t;

#define TB_PPU2MASK TB_PPU2MASK_FUNC()
static inline uint64_t TB_PPU2MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU2MASK_FUNC(void)
{
	return 0x000087E013000244ull;
}
#define typedef_TB_PPU2MASK tb_ppu2mask_t
#define bustype_TB_PPU2MASK CSR_TYPE_NCB32b
#define busnum_TB_PPU2MASK 0
#define arguments_TB_PPU2MASK -1,-1,-1,-1
#define basename_TB_PPU2MASK "PU2MASK"
#define offset_TB_PPU2MASK (TB_PPU2MASK - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu3addr
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union tb_ppu3addr {
	uint32_t u;
	struct tb_ppu3addr_s {
#ifdef __BIG_ENDIAN
		uint32_t address                     : 22; /**< R/W - Address bits indicating the starting address of programmed PPU region */
		uint32_t reserved_0_9                : 10;
#else
		uint32_t reserved_0_9                : 10;
		uint32_t address                     : 22;
#endif
	} s;
	/* struct tb_ppu3addr_s               cn88xx; */
} tb_ppu3addr_t;

#define TB_PPU3ADDR TB_PPU3ADDR_FUNC()
static inline uint64_t TB_PPU3ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU3ADDR_FUNC(void)
{
	return 0x000087E013000248ull;
}
#define typedef_TB_PPU3ADDR tb_ppu3addr_t
#define bustype_TB_PPU3ADDR CSR_TYPE_NCB32b
#define busnum_TB_PPU3ADDR 0
#define arguments_TB_PPU3ADDR -1,-1,-1,-1
#define basename_TB_PPU3ADDR "PU3ADDR"
#define offset_TB_PPU3ADDR (TB_PPU3ADDR - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu3mask
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union tb_ppu3mask {
	uint32_t u;
	struct tb_ppu3mask_s {
#ifdef __BIG_ENDIAN
		uint32_t address_mask                : 22; /**< R/W - Used to define the range over which the PPU is enabled for */
		uint32_t reserved_3_9                : 7;
		uint32_t mode                        : 1;  /**< R/W - The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
		uint32_t non_secure                  : 1;  /**< R/W - - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
		uint32_t enable                      : 1;  /**< R/W - - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else
		uint32_t enable                      : 1;
		uint32_t non_secure                  : 1;
		uint32_t mode                        : 1;
		uint32_t reserved_3_9                : 7;
		uint32_t address_mask                : 22;
#endif
	} s;
	/* struct tb_ppu3mask_s               cn88xx; */
} tb_ppu3mask_t;

#define TB_PPU3MASK TB_PPU3MASK_FUNC()
static inline uint64_t TB_PPU3MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU3MASK_FUNC(void)
{
	return 0x000087E01300024Cull;
}
#define typedef_TB_PPU3MASK tb_ppu3mask_t
#define bustype_TB_PPU3MASK CSR_TYPE_NCB32b
#define busnum_TB_PPU3MASK 0
#define arguments_TB_PPU3MASK -1,-1,-1,-1
#define basename_TB_PPU3MASK "PU3MASK"
#define offset_TB_PPU3MASK (TB_PPU3MASK - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu4addr
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union tb_ppu4addr {
	uint32_t u;
	struct tb_ppu4addr_s {
#ifdef __BIG_ENDIAN
		uint32_t address                     : 22; /**< R/W - Address bits indicating the starting address of programmed PPU region */
		uint32_t reserved_0_9                : 10;
#else
		uint32_t reserved_0_9                : 10;
		uint32_t address                     : 22;
#endif
	} s;
	/* struct tb_ppu4addr_s               cn88xx; */
} tb_ppu4addr_t;

#define TB_PPU4ADDR TB_PPU4ADDR_FUNC()
static inline uint64_t TB_PPU4ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU4ADDR_FUNC(void)
{
	return 0x000087E013000250ull;
}
#define typedef_TB_PPU4ADDR tb_ppu4addr_t
#define bustype_TB_PPU4ADDR CSR_TYPE_NCB32b
#define busnum_TB_PPU4ADDR 0
#define arguments_TB_PPU4ADDR -1,-1,-1,-1
#define basename_TB_PPU4ADDR "PU4ADDR"
#define offset_TB_PPU4ADDR (TB_PPU4ADDR - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu4mask
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union tb_ppu4mask {
	uint32_t u;
	struct tb_ppu4mask_s {
#ifdef __BIG_ENDIAN
		uint32_t address_mask                : 22; /**< R/W - Used to define the range over which the PPU is enabled for */
		uint32_t reserved_3_9                : 7;
		uint32_t mode                        : 1;  /**< R/W - The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
		uint32_t non_secure                  : 1;  /**< R/W - - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
		uint32_t enable                      : 1;  /**< R/W - - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else
		uint32_t enable                      : 1;
		uint32_t non_secure                  : 1;
		uint32_t mode                        : 1;
		uint32_t reserved_3_9                : 7;
		uint32_t address_mask                : 22;
#endif
	} s;
	/* struct tb_ppu4mask_s               cn88xx; */
} tb_ppu4mask_t;

#define TB_PPU4MASK TB_PPU4MASK_FUNC()
static inline uint64_t TB_PPU4MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU4MASK_FUNC(void)
{
	return 0x000087E013000254ull;
}
#define typedef_TB_PPU4MASK tb_ppu4mask_t
#define bustype_TB_PPU4MASK CSR_TYPE_NCB32b
#define busnum_TB_PPU4MASK 0
#define arguments_TB_PPU4MASK -1,-1,-1,-1
#define basename_TB_PPU4MASK "PU4MASK"
#define offset_TB_PPU4MASK (TB_PPU4MASK - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu5addr
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This register indicates the starting address of the PPU region.
 */
typedef union tb_ppu5addr {
	uint32_t u;
	struct tb_ppu5addr_s {
#ifdef __BIG_ENDIAN
		uint32_t address                     : 22; /**< R/W - Address bits indicating the starting address of programmed PPU region */
		uint32_t reserved_0_9                : 10;
#else
		uint32_t reserved_0_9                : 10;
		uint32_t address                     : 22;
#endif
	} s;
	/* struct tb_ppu5addr_s               cn88xx; */
} tb_ppu5addr_t;

#define TB_PPU5ADDR TB_PPU5ADDR_FUNC()
static inline uint64_t TB_PPU5ADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU5ADDR_FUNC(void)
{
	return 0x000087E013000258ull;
}
#define typedef_TB_PPU5ADDR tb_ppu5addr_t
#define bustype_TB_PPU5ADDR CSR_TYPE_NCB32b
#define busnum_TB_PPU5ADDR 0
#define arguments_TB_PPU5ADDR -1,-1,-1,-1
#define basename_TB_PPU5ADDR "PU5ADDR"
#define offset_TB_PPU5ADDR (TB_PPU5ADDR - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppu5mask
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * The PPU Mask along with PPU address defines the region of memory to be
 * protected by PPU.  For each register pair, an address match is deemed to
 * have occurred when:
 *
 * AddressMatch<n> = Enable<n> & ( ! ( (AddressOnBus[31:10] ^ PPU<n>Addr[31:10] ) &
 * PPU<n>Mask[31:10] ) );
 *
 * In addition, a region abort occurs when:
 *
 * RegionAbort<n> = AddressMatch<n> & ( (AccessNS & !RegionNS<n>) + ( !AccessNS & RegionNS<n> &!
 * PPUMode<n>) );
 */
typedef union tb_ppu5mask {
	uint32_t u;
	struct tb_ppu5mask_s {
#ifdef __BIG_ENDIAN
		uint32_t address_mask                : 22; /**< R/W - Used to define the range over which the PPU is enabled for */
		uint32_t reserved_3_9                : 7;
		uint32_t mode                        : 1;  /**< R/W - The Mode bit is defined as 0=strict, 1=real.  In "strict" mode, transfers
                                                                 must have the same NS bit value as the targeted memory in every case.  In
                                                                 "real" mode, the PPU behavior is modified slightly to allow secure
                                                                 accesses to Non Secure memory regions.  Most validation tests will be run
                                                                 with the PPU in "strict" mode, as this allows more rigorous checking of
                                                                 the NS attribute issued by the processor.

                                                                 The Mode bit may be thought of as "allow S to access NS regions".  By
                                                                 marking a region as NS with the Mode bit for the region set as 1, the
                                                                 region will respond to all accesses. */
		uint32_t non_secure                  : 1;  /**< R/W - - 0 protection enabled for non-secure memory
                                                                 - 1 protection enabled for secure memory */
		uint32_t enable                      : 1;  /**< R/W - - 0 disable the PPU region
                                                                 - 1 enable the PPU region */
#else
		uint32_t enable                      : 1;
		uint32_t non_secure                  : 1;
		uint32_t mode                        : 1;
		uint32_t reserved_3_9                : 7;
		uint32_t address_mask                : 22;
#endif
	} s;
	/* struct tb_ppu5mask_s               cn88xx; */
} tb_ppu5mask_t;

#define TB_PPU5MASK TB_PPU5MASK_FUNC()
static inline uint64_t TB_PPU5MASK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPU5MASK_FUNC(void)
{
	return 0x000087E01300025Cull;
}
#define typedef_TB_PPU5MASK tb_ppu5mask_t
#define bustype_TB_PPU5MASK CSR_TYPE_NCB32b
#define busnum_TB_PPU5MASK 0
#define arguments_TB_PPU5MASK -1,-1,-1,-1
#define basename_TB_PPU5MASK "PU5MASK"
#define offset_TB_PPU5MASK (TB_PPU5MASK - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_watchdog
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * System watchdog implements a mechanism in which the simulation is forced
 * to end on reaching 0.  The system watchdog counter is a countdown counter.
 */
typedef union tb_watchdog {
	uint32_t u;
	struct tb_watchdog_s {
#ifdef __BIG_ENDIAN
		uint32_t breakvalue                  : 32; /**< R/W - A read from this register returns the current countdown value of the
                                                                 watchdog timer

                                                                 A write of 0xffff_ffff disables the watch dog time.  Any another value
                                                                 written to this register enables the watchdog timer and starts the timer.
                                                                 Simulation is to be terminated on reaching a count value of 0. */
#else
		uint32_t breakvalue                  : 32;
#endif
	} s;
	/* struct tb_watchdog_s               cn88xx; */
} tb_watchdog_t;

#define TB_WATCHDOG TB_WATCHDOG_FUNC()
static inline uint64_t TB_WATCHDOG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_WATCHDOG_FUNC(void)
{
	return 0x000087E013000284ull;
}
#define typedef_TB_WATCHDOG tb_watchdog_t
#define bustype_TB_WATCHDOG CSR_TYPE_NCB32b
#define busnum_TB_WATCHDOG 0
#define arguments_TB_WATCHDOG -1,-1,-1,-1
#define basename_TB_WATCHDOG "ATCHDOG"
#define offset_TB_WATCHDOG (TB_WATCHDOG - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_axi_abort_ctl
 *
 * NOTE: Per docs, this is not used for 64bit AVS
 *
 * This Control register is used to inject error as part of AXI bus
 * interface.
 */
typedef union tb_axi_abort_ctl {
	uint32_t u;
	struct tb_axi_abort_ctl_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_28_31              : 4;
		uint32_t abtrgn2errortype            : 2;  /**< R/W - Specifies type of error returned when it accesses the region defined by
                                                                 AbortRgnLo2 andAbortRgnHi2 */
		uint32_t abtrgn2wrdisable            : 1;  /**< R/W - Disables aborts on writes to the region defined by AbortRgnLo2 and
                                                                 AbortRgnHi2 */
		uint32_t abtrgn2rddisable            : 1;  /**< R/W - Disables aborts on reads to region defined by AbortRgnLo2 and AbortRgnHi2 */
		uint32_t abtrgn1errortype            : 2;  /**< R/W - Specifies type of error returned when it accesses the region defined by
                                                                 AbortRgnLo1 andAbortRgnHi1 */
		uint32_t abtrgn1wrdisable            : 1;  /**< R/W - Disables aborts on writes to the region defined by AbortRgnLo1 and
                                                                 AbortRgnHi1 */
		uint32_t abtrgn1rddisable            : 1;  /**< R/W - Disables aborts on reads to region defined by AbortRgnLo1 and AbortRgnHi1 */
		uint32_t abtsingleerrortype          : 2;  /**< R/W - Specifies type of error returned by accesses, to AbortSingle specified
                                                                 address */
		uint32_t abtsinglewrdisable          : 1;  /**< R/W - Disables aborts on writes from specified AbortSingle address */
		uint32_t abtsinglerddisable          : 1;  /**< R/W - Disables aborts on reads from specified AbortSingle address */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t abtsinglerddisable          : 1;
		uint32_t abtsinglewrdisable          : 1;
		uint32_t abtsingleerrortype          : 2;
		uint32_t abtrgn1rddisable            : 1;
		uint32_t abtrgn1wrdisable            : 1;
		uint32_t abtrgn1errortype            : 2;
		uint32_t abtrgn2rddisable            : 1;
		uint32_t abtrgn2wrdisable            : 1;
		uint32_t abtrgn2errortype            : 2;
		uint32_t reserved_28_31              : 4;
#endif
	} s;
	/* struct tb_axi_abort_ctl_s          cn88xx; */
} tb_axi_abort_ctl_t;

#define TB_AXI_ABORT_CTL TB_AXI_ABORT_CTL_FUNC()
static inline uint64_t TB_AXI_ABORT_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_AXI_ABORT_CTL_FUNC(void)
{
	return 0x000087E013000500ull;
}
#define typedef_TB_AXI_ABORT_CTL tb_axi_abort_ctl_t
#define bustype_TB_AXI_ABORT_CTL CSR_TYPE_NCB32b
#define busnum_TB_AXI_ABORT_CTL 0
#define arguments_TB_AXI_ABORT_CTL -1,-1,-1,-1
#define basename_TB_AXI_ABORT_CTL "XI_ABORT_CTL"
#define offset_TB_AXI_ABORT_CTL (TB_AXI_ABORT_CTL - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_sw_reset_ctl
 *
 * Controls the type of reset sent to the processor as result of
 * write to ScheduleRST.
 */
typedef union tb_sw_reset_ctl {
	uint32_t u;
	struct tb_sw_reset_ctl_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - - 0x0000_0001 Assert reset using nRESET.  This reset is applied to reset
                                                                 the warm reset domain of the specified processor excluding the auxiliary
                                                                 processor
                                                                 - 0x0000_0005 Assert reset using nRESET.  This reset is applied to reset
                                                                 the warm reset domain of the specified processor excluding the auxiliary
                                                                 processor
                                                                 - 0x2000_0005 Assert reset using nCOREPORESET.  This reset is applied to
                                                                 reset the cold reset domain of the specified processor excluding the
                                                                 auxiliary processor.
                                                                 - 0x0000_0011 Assert reset using nDBGRESET.  This reset is applied to
                                                                 reset the external debug reset domain of the processor, excluding the
                                                                 auxiliary processor
                                                                 - 0x0000_0015 Assert reset using nSYSPORESET.  Reset entire system,
                                                                 excluding auxiliary processor.
                                                                 - 0x0000_0004 Trace unit reset.  Resets all trace unit Trace registers and
                                                                 some management registers TRCOSLSR, TRCPDSR
                                                                 - 0x0000_0014 External trace reset.  Resets some trace unit management
                                                                 registers.
                                                                 - Any other value Reserved.
                                                                 - NOTE:
                                                                     - 1.  ScheduleRST will not have any effect if SWResetCtl contains a
                                                                     reserved value.
                                                                     - 2.  AXI reset is asserted on the first nSYSPORESET.  AXI reset is only
                                                                     asserted on subsequent assertions of nSYSPORESET, and assertion of nRESET,
                                                                     if the auxiliary processor is in reset.
                                                                     - 3.  Assertion and deassertion of nRESET and nSYSPORESET does not change
                                                                     the number of processors that are not in reset.  For example, initially,
                                                                     if one processor is not in reset and nCOREPORESET is used to bring another
                                                                     processor out of reset before nRESET is asserted, then both processors are
                                                                     out of reset when nRESET is deasserted. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_sw_reset_ctl_s           cn88xx; */
} tb_sw_reset_ctl_t;

#define TB_SW_RESET_CTL TB_SW_RESET_CTL_FUNC()
static inline uint64_t TB_SW_RESET_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_SW_RESET_CTL_FUNC(void)
{
	return 0x000087E013000520ull;
}
#define typedef_TB_SW_RESET_CTL tb_sw_reset_ctl_t
#define bustype_TB_SW_RESET_CTL CSR_TYPE_NCB32b
#define busnum_TB_SW_RESET_CTL 0
#define arguments_TB_SW_RESET_CTL -1,-1,-1,-1
#define basename_TB_SW_RESET_CTL "W_RESET_CTL"
#define offset_TB_SW_RESET_CTL (TB_SW_RESET_CTL - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_gte_api
 *
 * Set of functions out of possible group of GTE. Possible groups
 * are external observer, PPU or Access Sensitive Devices.
 */
typedef union tb_gte_api {
	uint32_t u;
	struct tb_gte_api_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_gte_api_s                cn88xx; */
} tb_gte_api_t;

#define TB_GTE_API TB_GTE_API_FUNC()
static inline uint64_t TB_GTE_API_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_GTE_API_FUNC(void)
{
	return 0x000087E013000A00ull;
}
#define typedef_TB_GTE_API tb_gte_api_t
#define bustype_TB_GTE_API CSR_TYPE_NCB32b
#define busnum_TB_GTE_API 0
#define arguments_TB_GTE_API -1,-1,-1,-1
#define basename_TB_GTE_API "TE_API"
#define offset_TB_GTE_API (TB_GTE_API - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_gte_api_param
 *
 * Acts differently based on the groups chosen out of GTE_API.
 *
 */
typedef union tb_gte_api_param {
	uint32_t u;
	struct tb_gte_api_param_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_gte_api_param_s          cn88xx; */
} tb_gte_api_param_t;

#define TB_GTE_API_PARAM TB_GTE_API_PARAM_FUNC()
static inline uint64_t TB_GTE_API_PARAM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_GTE_API_PARAM_FUNC(void)
{
	return 0x000087E013000A04ull;
}
#define typedef_TB_GTE_API_PARAM tb_gte_api_param_t
#define bustype_TB_GTE_API_PARAM CSR_TYPE_NCB32b
#define busnum_TB_GTE_API_PARAM 0
#define arguments_TB_GTE_API_PARAM -1,-1,-1,-1
#define basename_TB_GTE_API_PARAM "TE_API_PARAM"
#define offset_TB_GTE_API_PARAM (TB_GTE_API_PARAM - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_gte_api_status
 *
 * Returns the status or handle of the exercised function.
 *
 */
typedef union tb_gte_api_status {
	uint32_t u;
	struct tb_gte_api_status_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_gte_api_status_s         cn88xx; */
} tb_gte_api_status_t;

#define TB_GTE_API_STATUS TB_GTE_API_STATUS_FUNC()
static inline uint64_t TB_GTE_API_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_GTE_API_STATUS_FUNC(void)
{
	return 0x000087E013000A08ull;
}
#define typedef_TB_GTE_API_STATUS tb_gte_api_status_t
#define bustype_TB_GTE_API_STATUS CSR_TYPE_NCB32b
#define busnum_TB_GTE_API_STATUS 0
#define arguments_TB_GTE_API_STATUS -1,-1,-1,-1
#define basename_TB_GTE_API_STATUS "TE_API_STATUS"
#define offset_TB_GTE_API_STATUS (TB_GTE_API_STATUS - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_gte_api_status_64
 *
 * Lower 32 address associated with 64 bit extended status
 *
 */
typedef union tb_gte_api_status_64 {
	uint32_t u;
	struct tb_gte_api_status_64_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_gte_api_status_64_s      cn88xx; */
} tb_gte_api_status_64_t;

#define TB_GTE_API_STATUS_64 TB_GTE_API_STATUS_64_FUNC()
static inline uint64_t TB_GTE_API_STATUS_64_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_GTE_API_STATUS_64_FUNC(void)
{
	return 0x000087E013000A20ull;
}
#define typedef_TB_GTE_API_STATUS_64 tb_gte_api_status_64_t
#define bustype_TB_GTE_API_STATUS_64 CSR_TYPE_NCB32b
#define busnum_TB_GTE_API_STATUS_64 0
#define arguments_TB_GTE_API_STATUS_64 -1,-1,-1,-1
#define basename_TB_GTE_API_STATUS_64 "TE_API_STATUS_64"
#define offset_TB_GTE_API_STATUS_64 (TB_GTE_API_STATUS_64 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_gte_api_status_64_hi
 *
 * Upper 32 address associated with 64 bit extended status
 *
 */
typedef union tb_gte_api_status_64_hi {
	uint32_t u;
	struct tb_gte_api_status_64_hi_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_gte_api_status_64_hi_s   cn88xx; */
} tb_gte_api_status_64_hi_t;

#define TB_GTE_API_STATUS_64_HI TB_GTE_API_STATUS_64_HI_FUNC()
static inline uint64_t TB_GTE_API_STATUS_64_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_GTE_API_STATUS_64_HI_FUNC(void)
{
	return 0x000087E013000A24ull;
}
#define typedef_TB_GTE_API_STATUS_64_HI tb_gte_api_status_64_hi_t
#define bustype_TB_GTE_API_STATUS_64_HI CSR_TYPE_NCB32b
#define busnum_TB_GTE_API_STATUS_64_HI 0
#define arguments_TB_GTE_API_STATUS_64_HI -1,-1,-1,-1
#define basename_TB_GTE_API_STATUS_64_HI "TE_API_STATUS_64_HI"
#define offset_TB_GTE_API_STATUS_64_HI (TB_GTE_API_STATUS_64_HI - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_gte_api_param_64
 *
 * Lower 32 address associated with 64 bit extended parameter.
 * Generally associated with 64 bit functionality
 */
typedef union tb_gte_api_param_64 {
	uint32_t u;
	struct tb_gte_api_param_64_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_gte_api_param_64_s       cn88xx; */
} tb_gte_api_param_64_t;

#define TB_GTE_API_PARAM_64 TB_GTE_API_PARAM_64_FUNC()
static inline uint64_t TB_GTE_API_PARAM_64_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_GTE_API_PARAM_64_FUNC(void)
{
	return 0x000087E013000A28ull;
}
#define typedef_TB_GTE_API_PARAM_64 tb_gte_api_param_64_t
#define bustype_TB_GTE_API_PARAM_64 CSR_TYPE_NCB32b
#define busnum_TB_GTE_API_PARAM_64 0
#define arguments_TB_GTE_API_PARAM_64 -1,-1,-1,-1
#define basename_TB_GTE_API_PARAM_64 "TE_API_PARAM_64"
#define offset_TB_GTE_API_PARAM_64 (TB_GTE_API_PARAM_64 - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_gte_api_param_64_hi
 *
 * Upper 32 addresses associated with 64 bit extended
 * parameter. Generally associated with 64 bit functionality
 */
typedef union tb_gte_api_param_64_hi {
	uint32_t u;
	struct tb_gte_api_param_64_hi_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_gte_api_param_64_hi_s    cn88xx; */
} tb_gte_api_param_64_hi_t;

#define TB_GTE_API_PARAM_64_HI TB_GTE_API_PARAM_64_HI_FUNC()
static inline uint64_t TB_GTE_API_PARAM_64_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_GTE_API_PARAM_64_HI_FUNC(void)
{
	return 0x000087E013000A2Cull;
}
#define typedef_TB_GTE_API_PARAM_64_HI tb_gte_api_param_64_hi_t
#define bustype_TB_GTE_API_PARAM_64_HI CSR_TYPE_NCB32b
#define busnum_TB_GTE_API_PARAM_64_HI 0
#define arguments_TB_GTE_API_PARAM_64_HI -1,-1,-1,-1
#define basename_TB_GTE_API_PARAM_64_HI "TE_API_PARAM_64_HI"
#define offset_TB_GTE_API_PARAM_64_HI (TB_GTE_API_PARAM_64_HI - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_spi_group_index
 *
 * This is a 32 bit register.  The possible values are based on the number of
 * registers present in the trick box.  The number of registers depends on
 * the number of SPI pins implemented by trickbox.
 */
typedef union tb_spi_group_index {
	uint32_t u;
	struct tb_spi_group_index_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - Valid values are 1 to maximum number of 31. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_spi_group_index_s        cn88xx; */
} tb_spi_group_index_t;

#define TB_SPI_GROUP_INDEX TB_SPI_GROUP_INDEX_FUNC()
static inline uint64_t TB_SPI_GROUP_INDEX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_SPI_GROUP_INDEX_FUNC(void)
{
	return 0x000087E013000C00ull;
}
#define typedef_TB_SPI_GROUP_INDEX tb_spi_group_index_t
#define bustype_TB_SPI_GROUP_INDEX CSR_TYPE_NCB32b
#define busnum_TB_SPI_GROUP_INDEX 0
#define arguments_TB_SPI_GROUP_INDEX -1,-1,-1,-1
#define basename_TB_SPI_GROUP_INDEX "PI_GROUP_INDEX"
#define offset_TB_SPI_GROUP_INDEX (TB_SPI_GROUP_INDEX - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_spi_group_value
 *
 * Each bit indicates the associated value of indexed SPI to be driven into
 * the processor.  996 SPI pins are to be implemented.
 * - For SPI_GROUP_INDEX = 0
 *     - bit[31:0] are reserved
 * - For SPI_GROUP_INDEX = 1
 *     - bit[0] is associated with SPI pin 0 with Interrupt ID 32
 *     - ...
 *     - bit[31] is associated with SPI pin 31 with Interrupt ID 63
 * - ...
 * - For SPI_GROUP_INDEX = 31
 *     - bit[0] is associated with SPI pin 960 with Interrupt ID 992
 *     - ...
 *     - bit[27] is associated with SPI pin 987 with Interrupt ID 1019
 *     - bit[31:27] is reserved
 * - 0 indicates assertion of associated SPI pin
 * - 1 indicates deassertion of associated SPI pin
 */
typedef union tb_spi_group_value {
	uint32_t u;
	struct tb_spi_group_value_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_spi_group_value_s        cn88xx; */
} tb_spi_group_value_t;

#define TB_SPI_GROUP_VALUE TB_SPI_GROUP_VALUE_FUNC()
static inline uint64_t TB_SPI_GROUP_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_SPI_GROUP_VALUE_FUNC(void)
{
	return 0x000087E013000C04ull;
}
#define typedef_TB_SPI_GROUP_VALUE tb_spi_group_value_t
#define bustype_TB_SPI_GROUP_VALUE CSR_TYPE_NCB32b
#define busnum_TB_SPI_GROUP_VALUE 0
#define arguments_TB_SPI_GROUP_VALUE -1,-1,-1,-1
#define basename_TB_SPI_GROUP_VALUE "PI_GROUP_VALUE"
#define offset_TB_SPI_GROUP_VALUE (TB_SPI_GROUP_VALUE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppi_group_target_core
 *
 * This indicates the processor on which the associated value of PPI is to be
 * driven into.  The target processor is the physical target processor
 * number.
 *
 * NOTE: As of the current implementation only 4 processors are supported.
 * VAL uses logical processor numbering scheme based on the resources present
 * in the resource file.  If there is a different mechanism used to indicate
 * the target processor number in this field then VAL needs to convert from
 * logical processor to physical processor which is implementation defined.
 */
typedef union tb_ppi_group_target_core {
	uint32_t u;
	struct tb_ppi_group_target_core_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - This field indicates the physical target processor number to which the PPI
                                                                 is to be driven into. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_ppi_group_target_core_s  cn88xx; */
} tb_ppi_group_target_core_t;

#define TB_PPI_GROUP_TARGET_CORE TB_PPI_GROUP_TARGET_CORE_FUNC()
static inline uint64_t TB_PPI_GROUP_TARGET_CORE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPI_GROUP_TARGET_CORE_FUNC(void)
{
	return 0x000087E013000C20ull;
}
#define typedef_TB_PPI_GROUP_TARGET_CORE tb_ppi_group_target_core_t
#define bustype_TB_PPI_GROUP_TARGET_CORE CSR_TYPE_NCB32b
#define busnum_TB_PPI_GROUP_TARGET_CORE 0
#define arguments_TB_PPI_GROUP_TARGET_CORE -1,-1,-1,-1
#define basename_TB_PPI_GROUP_TARGET_CORE "PI_GROUP_TARGET_CORE"
#define offset_TB_PPI_GROUP_TARGET_CORE (TB_PPI_GROUP_TARGET_CORE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_ppi_group_value
 *
 * Each bit indicates the associated value of PPI to be driven into the
 * processor.  16 PPI pins are available.
 * - PPI 0, bit[0] associated with PPI pin with Interrupt ID 15
 * - PPI 1, bit[1] associated with PPI pin with Interrupt ID 16
 * - ...
 * - PPI 15, bit[15] associated with PPI pin with Interrupt ID 31
 * - 0 indicates deassertion of associated PPI
 * - 1 indicates assertion of associated PPI
 */
typedef union tb_ppi_group_value {
	uint32_t u;
	struct tb_ppi_group_value_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t ppi                         : 16;
#else
		uint32_t ppi                         : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct tb_ppi_group_value_s        cn88xx; */
} tb_ppi_group_value_t;

#define TB_PPI_GROUP_VALUE TB_PPI_GROUP_VALUE_FUNC()
static inline uint64_t TB_PPI_GROUP_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_PPI_GROUP_VALUE_FUNC(void)
{
	return 0x000087E013000C24ull;
}
#define typedef_TB_PPI_GROUP_VALUE tb_ppi_group_value_t
#define bustype_TB_PPI_GROUP_VALUE CSR_TYPE_NCB32b
#define busnum_TB_PPI_GROUP_VALUE 0
#define arguments_TB_PPI_GROUP_VALUE -1,-1,-1,-1
#define basename_TB_PPI_GROUP_VALUE "PI_GROUP_VALUE"
#define offset_TB_PPI_GROUP_VALUE (TB_PPI_GROUP_VALUE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_rei_target_core
 *
 * This indicates the processor on which the associated value of REI is to be
 * driven into.  The target processor is the physical target processor
 * number.
 */
typedef union tb_rei_target_core {
	uint32_t u;
	struct tb_rei_target_core_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - This field indicates the physical target core number to which the REI is
                                                                 to be driven into. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_rei_target_core_s        cn88xx; */
} tb_rei_target_core_t;

#define TB_REI_TARGET_CORE TB_REI_TARGET_CORE_FUNC()
static inline uint64_t TB_REI_TARGET_CORE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_REI_TARGET_CORE_FUNC(void)
{
	return 0x000087E013000C40ull;
}
#define typedef_TB_REI_TARGET_CORE tb_rei_target_core_t
#define bustype_TB_REI_TARGET_CORE CSR_TYPE_NCB32b
#define busnum_TB_REI_TARGET_CORE 0
#define arguments_TB_REI_TARGET_CORE -1,-1,-1,-1
#define basename_TB_REI_TARGET_CORE "EI_TARGET_CORE"
#define offset_TB_REI_TARGET_CORE (TB_REI_TARGET_CORE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_rei_value
 *
 * REI value
 *
 */
typedef union tb_rei_value {
	uint32_t u;
	struct tb_rei_value_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t value                       : 1;  /**< R/W - - 0 indicates deassertion of associated REI
                                                                 - 1 indicates assertion of associated REI */
#else
		uint32_t value                       : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct tb_rei_value_s              cn88xx; */
} tb_rei_value_t;

#define TB_REI_VALUE TB_REI_VALUE_FUNC()
static inline uint64_t TB_REI_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_REI_VALUE_FUNC(void)
{
	return 0x000087E013000C44ull;
}
#define typedef_TB_REI_VALUE tb_rei_value_t
#define bustype_TB_REI_VALUE CSR_TYPE_NCB32b
#define busnum_TB_REI_VALUE 0
#define arguments_TB_REI_VALUE -1,-1,-1,-1
#define basename_TB_REI_VALUE "EI_VALUE"
#define offset_TB_REI_VALUE (TB_REI_VALUE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_sei_target_core
 *
 * This indicates the processor on which the associated value of SEI is to be
 * driven into.  The target processor is the physical target processor
 * number.
 */
typedef union tb_sei_target_core {
	uint32_t u;
	struct tb_sei_target_core_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - This field indicates the physical target processor number to which the SEI
                                                                 is to be driven into. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_sei_target_core_s        cn88xx; */
} tb_sei_target_core_t;

#define TB_SEI_TARGET_CORE TB_SEI_TARGET_CORE_FUNC()
static inline uint64_t TB_SEI_TARGET_CORE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_SEI_TARGET_CORE_FUNC(void)
{
	return 0x000087E013000C60ull;
}
#define typedef_TB_SEI_TARGET_CORE tb_sei_target_core_t
#define bustype_TB_SEI_TARGET_CORE CSR_TYPE_NCB32b
#define busnum_TB_SEI_TARGET_CORE 0
#define arguments_TB_SEI_TARGET_CORE -1,-1,-1,-1
#define basename_TB_SEI_TARGET_CORE "EI_TARGET_CORE"
#define offset_TB_SEI_TARGET_CORE (TB_SEI_TARGET_CORE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_sei_value
 *
 * SEI value
 *
 */
typedef union tb_sei_value {
	uint32_t u;
	struct tb_sei_value_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t value                       : 1;  /**< R/W - - 0 indicates deassertion of associated SEI
                                                                 - 1 indicates assertion of associated SEI */
#else
		uint32_t value                       : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct tb_sei_value_s              cn88xx; */
} tb_sei_value_t;

#define TB_SEI_VALUE TB_SEI_VALUE_FUNC()
static inline uint64_t TB_SEI_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_SEI_VALUE_FUNC(void)
{
	return 0x000087E013000C64ull;
}
#define typedef_TB_SEI_VALUE tb_sei_value_t
#define bustype_TB_SEI_VALUE CSR_TYPE_NCB32b
#define busnum_TB_SEI_VALUE 0
#define arguments_TB_SEI_VALUE -1,-1,-1,-1
#define basename_TB_SEI_VALUE "EI_VALUE"
#define offset_TB_SEI_VALUE (TB_SEI_VALUE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_sei_ppi_rei_control
 *
 * TBD
 *
 */
typedef union tb_sei_ppi_rei_control {
	uint32_t u;
	struct tb_sei_ppi_rei_control_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_5_31               : 27;
		uint32_t rei_en                      : 1;  /**< R/W - - 0 does not affect driving of REI interrupts
                                                                 - 1 drives REI interrupts */
		uint32_t sei_en                      : 1;  /**< R/W - - 0 does not affect driving of SEI interrupt
                                                                 - 1 drives SEI interrupt */
		uint32_t ppi_en                      : 1;  /**< R/W - - 0 does not affect driving of PPI interrupts
                                                                 - 1 drives PPI interrupts */
		uint32_t spi_en                      : 1;  /**< R/W - - 0 does not affect driving of SPI interrupts
                                                                 - 1 drives SPI interrupts */
		uint32_t reserved_0_0                : 1;
#else
		uint32_t reserved_0_0                : 1;
		uint32_t spi_en                      : 1;
		uint32_t ppi_en                      : 1;
		uint32_t sei_en                      : 1;
		uint32_t rei_en                      : 1;
		uint32_t reserved_5_31               : 27;
#endif
	} s;
	/* struct tb_sei_ppi_rei_control_s    cn88xx; */
} tb_sei_ppi_rei_control_t;

#define TB_SEI_PPI_REI_CONTROL TB_SEI_PPI_REI_CONTROL_FUNC()
static inline uint64_t TB_SEI_PPI_REI_CONTROL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_SEI_PPI_REI_CONTROL_FUNC(void)
{
	return 0x000087E013000C80ull;
}
#define typedef_TB_SEI_PPI_REI_CONTROL tb_sei_ppi_rei_control_t
#define bustype_TB_SEI_PPI_REI_CONTROL CSR_TYPE_NCB32b
#define busnum_TB_SEI_PPI_REI_CONTROL 0
#define arguments_TB_SEI_PPI_REI_CONTROL -1,-1,-1,-1
#define basename_TB_SEI_PPI_REI_CONTROL "EI_PPI_REI_CONTROL"
#define offset_TB_SEI_PPI_REI_CONTROL (TB_SEI_PPI_REI_CONTROL - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_gic_rd_event_status_index
 *
 * Logical Processor Number Associated with the Redistributor
 *
 */
typedef union tb_gic_rd_event_status_index {
	uint32_t u;
	struct tb_gic_rd_event_status_index_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - This field holds the logical processor number which is associated with the
                                                                 redistributor whose status information is to be read. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_gic_rd_event_status_index_s cn88xx; */
} tb_gic_rd_event_status_index_t;

#define TB_GIC_RD_EVENT_STATUS_INDEX TB_GIC_RD_EVENT_STATUS_INDEX_FUNC()
static inline uint64_t TB_GIC_RD_EVENT_STATUS_INDEX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_GIC_RD_EVENT_STATUS_INDEX_FUNC(void)
{
	return 0x000087E013000CA0ull;
}
#define typedef_TB_GIC_RD_EVENT_STATUS_INDEX tb_gic_rd_event_status_index_t
#define bustype_TB_GIC_RD_EVENT_STATUS_INDEX CSR_TYPE_NCB32b
#define busnum_TB_GIC_RD_EVENT_STATUS_INDEX 0
#define arguments_TB_GIC_RD_EVENT_STATUS_INDEX -1,-1,-1,-1
#define basename_TB_GIC_RD_EVENT_STATUS_INDEX "IC_RD_EVENT_STATUS_INDEX"
#define offset_TB_GIC_RD_EVENT_STATUS_INDEX (TB_GIC_RD_EVENT_STATUS_INDEX - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_gic_rd_event_status_value
 *
 * WakeRequestDrives DBGEN pin. Read Write bit.
 *
 */
typedef union tb_gic_rd_event_status_value {
	uint32_t u;
	struct tb_gic_rd_event_status_value_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t wakerequest                 : 1;  /**< R/W - WakeRequestDrives DBGEN pin. Read Write bit.
                                                                 - 0 WakeRequest deasserted
                                                                 - 1 WakeRequest asserted */
#else
		uint32_t wakerequest                 : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct tb_gic_rd_event_status_value_s cn88xx; */
} tb_gic_rd_event_status_value_t;

#define TB_GIC_RD_EVENT_STATUS_VALUE TB_GIC_RD_EVENT_STATUS_VALUE_FUNC()
static inline uint64_t TB_GIC_RD_EVENT_STATUS_VALUE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_GIC_RD_EVENT_STATUS_VALUE_FUNC(void)
{
	return 0x000087E013000CA4ull;
}
#define typedef_TB_GIC_RD_EVENT_STATUS_VALUE tb_gic_rd_event_status_value_t
#define bustype_TB_GIC_RD_EVENT_STATUS_VALUE CSR_TYPE_NCB32b
#define busnum_TB_GIC_RD_EVENT_STATUS_VALUE 0
#define arguments_TB_GIC_RD_EVENT_STATUS_VALUE -1,-1,-1,-1
#define basename_TB_GIC_RD_EVENT_STATUS_VALUE "IC_RD_EVENT_STATUS_VALUE"
#define offset_TB_GIC_RD_EVENT_STATUS_VALUE (TB_GIC_RD_EVENT_STATUS_VALUE - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_device_id
 *
 * Device ID of the generating device to be indicted to the ITS.  32 bit,
 * persistent (does not get reset when a transaction is triggered).
 */
typedef union tb_device_id {
	uint32_t u;
	struct tb_device_id_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - 32 bit register, to set the Device ID. */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_device_id_s              cn88xx; */
} tb_device_id_t;

#define TB_DEVICE_ID TB_DEVICE_ID_FUNC()
static inline uint64_t TB_DEVICE_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_DEVICE_ID_FUNC(void)
{
	return 0x000087E013000D00ull;
}
#define typedef_TB_DEVICE_ID tb_device_id_t
#define bustype_TB_DEVICE_ID CSR_TYPE_NCB32b
#define busnum_TB_DEVICE_ID 0
#define arguments_TB_DEVICE_ID -1,-1,-1,-1
#define basename_TB_DEVICE_ID "EVICE_ID"
#define offset_TB_DEVICE_ID (TB_DEVICE_ID - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_attributes
 *
 * Attributes of the transaction. (persistent)
 * 32 bit register, to set the Transaction Attributes
 *  bit[3:0] - Cacheability:
 *            bit[0] - Bufferable
 *            bit[1] - Cacheable
 *            bit[2] - Read allocate
 *            bit[3] - Write allocate
 *  bit[7:4] - Res0
 *  bit[10:8]
 *            bit[8] - Privileged (not user)
 *            bit[9] - Normal (not secure)
 *            bit[10] - Instruction
 *  bit[15:11] - Res0
 *  bit[17:16] Shareability domain
 *            0'b00: non shared
 *            0'b01: inner shared
 *            0'b10: outer shared
 *            0'b11: system
 *  bit[23:18] - Res0
 *  bit[25:24] - Transaction word size
 *            0'b00 - 8 bits
 *            0'b01 - 16 bits
 *            0'b10 - 32 bits
 *            0'b11 - 64 bits
 *  bit[31:26] - Res 0
 */
typedef union tb_attributes {
	uint32_t u;
	struct tb_attributes_s {
#ifdef __BIG_ENDIAN
		uint32_t value                       : 32; /**< R/W - TBD */
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct tb_attributes_s             cn88xx; */
} tb_attributes_t;

#define TB_ATTRIBUTES TB_ATTRIBUTES_FUNC()
static inline uint64_t TB_ATTRIBUTES_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ATTRIBUTES_FUNC(void)
{
	return 0x000087E013000D10ull;
}
#define typedef_TB_ATTRIBUTES tb_attributes_t
#define bustype_TB_ATTRIBUTES CSR_TYPE_NCB32b
#define busnum_TB_ATTRIBUTES 0
#define arguments_TB_ATTRIBUTES -1,-1,-1,-1
#define basename_TB_ATTRIBUTES "TTRIBUTES"
#define offset_TB_ATTRIBUTES (TB_ATTRIBUTES - TRICKBOX_CSR_BASE)


/**
 * NCB - tb_address
 *
 * 64 bit address of the transaction. (Persistent)
 *
 */
typedef union tb_address {
	uint64_t u;
	struct tb_address_s {
#ifdef __BIG_ENDIAN
		uint64_t value                       : 64; /**< R/W - TBD */
#else
		uint64_t value                       : 64;
#endif
	} s;
	/* struct tb_address_s                cn88xx; */
} tb_address_t;

#define TB_ADDRESS TB_ADDRESS_FUNC()
static inline uint64_t TB_ADDRESS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_ADDRESS_FUNC(void)
{
	return 0x000087E013000D20ull;
}
#define typedef_TB_ADDRESS tb_address_t
#define bustype_TB_ADDRESS CSR_TYPE_NCB
#define busnum_TB_ADDRESS 0
#define arguments_TB_ADDRESS -1,-1,-1,-1
#define basename_TB_ADDRESS "DDRESS"
#define offset_TB_ADDRESS (TB_ADDRESS - TRICKBOX_CSR_BASE)


/**
 * NCB - tb_data
 *
 * Data to be read/written.
 * - on read: triggers a read transaction with the configured
 * attributes and returns up to 64 bit of data.
 * - on write: triggers a write of the data written to the address.
 * Returns a transaction acknowledge after the write is complete.
 */
typedef union tb_data {
	uint64_t u;
	struct tb_data_s {
#ifdef __BIG_ENDIAN
		uint64_t value                       : 64; /**< R/W - TBD */
#else
		uint64_t value                       : 64;
#endif
	} s;
	/* struct tb_data_s                   cn88xx; */
} tb_data_t;

#define TB_DATA TB_DATA_FUNC()
static inline uint64_t TB_DATA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_DATA_FUNC(void)
{
	return 0x000087E013000D40ull;
}
#define typedef_TB_DATA tb_data_t
#define bustype_TB_DATA CSR_TYPE_NCB
#define busnum_TB_DATA 0
#define arguments_TB_DATA -1,-1,-1,-1
#define basename_TB_DATA "ATA"
#define offset_TB_DATA (TB_DATA - TRICKBOX_CSR_BASE)


/**
 * NCB32b - tb_operate
 *
 * Status of the operation
 * Read:
 * - 0: Operation in Progress
 * - 1: Transaction error
 *
 * Valid values for this register bit 1:0 for read:
 * - 0 no operation no error,
 * - 1 operation in progress,
 * - 2 transaction error on last transaction
 *
 * Write:
 * - 0: Write, not read.
 * - A write of 1 triggers a write,
 * - A write of 0 triggers a read.
 * - A write is performed and a transaction is already in progress, the write aborts.
 */
typedef union tb_operate {
	uint32_t u;
	struct tb_operate_s {
#ifdef __BIG_ENDIAN
		uint32_t reserved_2_31               : 30;
		uint32_t value                       : 2;  /**< R/W - See above */
#else
		uint32_t value                       : 2;
		uint32_t reserved_2_31               : 30;
#endif
	} s;
	/* struct tb_operate_s                cn88xx; */
} tb_operate_t;

#define TB_OPERATE TB_OPERATE_FUNC()
static inline uint64_t TB_OPERATE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t TB_OPERATE_FUNC(void)
{
	return 0x000087E013000D80ull;
}
#define typedef_TB_OPERATE tb_operate_t
#define bustype_TB_OPERATE CSR_TYPE_NCB32b
#define busnum_TB_OPERATE 0
#define arguments_TB_OPERATE -1,-1,-1,-1
#define basename_TB_OPERATE "PERATE"
#define offset_TB_OPERATE (TB_OPERATE - TRICKBOX_CSR_BASE)

#endif /* __CAVM_CSRS_TRICKBOX__ */
