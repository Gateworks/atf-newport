/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef _GSERN_INTERNAL_H_
#define _GSERN_INTERNAL_H_

#include <gsern.h>
#include <octeontx_common.h>
#include <debug.h>
#include <delay_timer.h>
#include <plat_scfg.h>
#include <plat_board_cfg.h>
#include <octeontx_utils.h>

/* define DEBUG_ATF_GSERN to enable debug logs */
#undef DEBUG_ATF_GSERN

#ifdef DEBUG_ATF_GSERN
#define debug_gsern printf
/*
 * Define values to evaluate following expression to true:
 * gsern_trace_enables & (1ull << GSERN_TRACE_ENABLE_QLM)
 */
#define gsern_trace_enables	2
#define GSERN_TRACE_ENABLE_QLM	1
#else
#define debug_gsern(...) ((void) (0))
/*
 * Define values to evaluate following expression to false:
 * gsern_trace_enables & (1ull << GSERN_TRACE_ENABLE_QLM)
 */
#define gsern_trace_enables	1
#define GSERN_TRACE_ENABLE_QLM	1
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

/* These constants represent the possible QLM reference clock speeds in Hz */
#define REF_100MHZ 100000000
#define REF_125MHZ 125000000
#define REF_156MHZ 156250000

/* From bdk/libbdk-hal/bdk-clock.h */
#define GTI_RATE 100000000ull

/* Argument for gsern_is_platform */
#define GSERN_PLATFORM_ASIM		0
#define GSERN_PLATFORM_EMULATOR		1

/* Argument for gsern_config_get_int */
#define GSERN_CONFIG_QLM_LANE_RX_POLARITY		0
#define GSERN_CONFIG_QLM_LANE_TX_POLARITY		1
#define GSERN_CONFIG_QLM_TUNING_TX_MAIN			2
#define GSERN_CONFIG_QLM_TUNING_TX_PRE			3
#define GSERN_CONFIG_QLM_TUNING_TX_POST			4
#define GSERN_CONFIG_QLM_TUNING_TX_BS			5
#define GSERN_CONFIG_QLM_VOLTAGE			6
#define GSERN_CONFIG_QLM_TUNING_RX_PREVGA_GN_OVRD	7
#define GSERN_CONFIG_QLM_TUNING_RX_PREVGA_GN_ADAPT	8

#define GSERN_CONFIG_QLM_TUNING_TX_MAIN_NAME	"MAIN"
#define GSERN_CONFIG_QLM_TUNING_TX_PRE_NAME	"PRE"
#define GSERN_CONFIG_QLM_TUNING_TX_POST_NAME	"POST"
#define GSERN_CONFIG_QLM_TUNING_TX_BS_NAME	"BS"

#define GSERN_CSR_WAIT_FOR_FIELD(addr, mask, ignore, val, timeout)	\
	gsern_poll_for_csr(addr, mask, val, timeout)

/* Defines for simple functions */
#define gsern_qlm_get_lanes(q)	plat_octeontx_scfg->qlm_max_lane_num[q]
#define qlm_get_lanes(q)	gsern_qlm_get_lanes(q)

#define GSERN_TRACE(ignore, format, ...)	debug_gsern(format, ##__VA_ARGS__)
#define GSERN_CSR_MODIFY		CSR_MODIFY
#define GSERN_CSR_INIT			CSR_INIT
#define GSERN_CSR_WRITE			CSR_WRITE
#define GSERN_CSR_READ			CSR_READ
#define bool				int
#define false				0
#define true				1
#define gsern_error			WARN
#define gsern_warn			WARN
#define gsern_wait_usec			udelay
#define gsern_is_model			cavm_is_model
#define gsern_clock_get_count(...)	read_cntpct_el0()
#define gsern_clock_get_rate(...)	GTI_RATE
#define gsern_extracts			octeontx_bit_extract

static inline int64_t gsern_extract_smag(uint64_t v, int lsb, int msb)
{
	int64_t r = octeontx_bit_extract(v, lsb, msb - lsb);

	if (v & (1ull << msb))
		r = -r;
	return r;
}

static inline int qlm_get_gbaud_mhz(int qlm, int lane)
{
	qlm_state_lane_t state;

	state = plat_otx2_get_qlm_state_lane(qlm, lane);
	return state.s.baud_mhz;
}

/* Internal functions */
extern int gsern_voltage;

int gsern_is_platform(int plat);
int gsern_config_get_int(int prop, ...);
int gsern_poll_for_csr(uint64_t addr, uint64_t mask, int poll_val, int timeout);
const char *qlm_mode_to_cfg_str(qlm_modes_t mode);

/* Implemented in drivers/marvell/gsern/gsern_init_common.c */
int gsern_init_wait_for_sm_complete(int qlm);
int gsern_init_wait_for_sm_ready(int qlm, int qlm_lane);
int gsern_init_wait_for_rx_ready(int qlm, int qlm_lane);
int gsern_init_wait_for_tx_ready(int qlm, int qlm_lane);

/* Stub implemented in drivers/marvell/gsern/gsern_internal.c */
int gsern_init_pcie(int qlm, bool is_first_qlm, enum gsern_flags flags,
	enum gsern_lane_modes mode);
int gsern_init_sata_no_scc(int qlm, enum gsern_lane_modes mode);
int gsern_init_sata_scc(int qlm, enum gsern_lane_modes mode);

/* Implemented in drivers/marvell/gsern/gsern_init_network.c */
int gsern_init_network(int qlm, int qlm_lane, enum gsern_flags flags,
	enum gsern_lane_modes mode);

#endif /* _GSERN_INTERNAL_H_ */
