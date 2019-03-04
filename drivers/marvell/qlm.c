/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:	 BSD-3-Clause
 * https://spdx.org/licenses
 */

/* Common QLM driver for OcteonTX2 */

#include <arch.h>
#include <stdio.h>
#include <string.h>
#include <debug.h>
#include <delay_timer.h>
#include <platform_def.h>
#include <platform_dt.h>
#include <octeontx_common.h>
#include <plat_scfg.h>
#include <plat_board_cfg.h>
#include <octeontx_utils.h>
#include <gsern.h>

/* This file is based on BDK: libbdk-hal/qlm/bdk-qlm-common-cn9xxx.c */

/* define DEBUG_ATF_QLM to enable debug logs */
#undef DEBUG_ATF_QLM

#ifdef DEBUG_ATF_QLM
#define debug_qlm printf
#else
#define debug_qlm(...) ((void) (0))
#endif

static const int TX_TUNING_INVALID = -1000;
static const int TX_TUNING_IDLE = -2000;

/*
 * Structure to define default tuning parameters
 */
struct default_tuning_t {
	octeontx_qlm_modes_t mode : 16;
	uint16_t baud_mhz;
	uint8_t tx_cmain;
	uint8_t tx_cpre;
	uint8_t tx_cpost;
	uint8_t tx_bs;
};

static const struct default_tuning_t DEF_TUNING[] = {
	{QLM_MODE_PCIE_1X1,	2500,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X1,	5000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X1,	8000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X1,	16000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X2,	2500,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X2,	5000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X2,	8000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X2,	16000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X4,	2500,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X4,	5000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X4,	8000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X4,	16000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X8,	2500,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X8,	5000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X8,	8000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X8,	16000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X16,	2500,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X16,	5000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X16,	8000,	24,	0,	0,	52},
	{QLM_MODE_PCIE_1X16,	16000,	24,	0,	0,	52},
	{QLM_MODE_SATA,		1500,	36,	0,	12,	42},
	{QLM_MODE_SATA,		3000,	36,	0,	12,	42},
	{QLM_MODE_SATA,		6000,	36,	0,	12,	42},
	{QLM_MODE_SGMII,	1250,	29,	0,	0,	42},
	{QLM_MODE_1G_X,		1250,	29,	0,	0,	42},
	{QLM_MODE_QSGMII,	5000,	29,	0,	0,	42},
	{QLM_MODE_XAUI,		3125,	48,	0,	0,	42},
	{QLM_MODE_XAUI,		6250,	48,	0,	0,	42},
	{QLM_MODE_RXAUI,	6250,	48,	0,	0,	42},
	{QLM_MODE_XFI,		10312,	29,	0,	0,	42},
	{QLM_MODE_SFI,		10312,	40,	6,	2,	42},
	{QLM_MODE_XLAUI,	10312,	36,	0,	12,	42},
	{QLM_MODE_XLAUI_C2M,	10312,	40,	0,	8,	42},
	{QLM_MODE_10G_KR,	10312,	48,	0,	0,	42},
	{QLM_MODE_40G_KR4,	10312,	48,	0,	0,	42},
	{QLM_MODE_20GAUI_C2C,	20625,	42,	6,	0,	42},
	{QLM_MODE_20GAUI_C2M,	20625,	42,	6,	0,	42},
	{QLM_MODE_25GAUI_C2C,	25781,	42,	6,	0,	42},
	{QLM_MODE_25GAUI_C2M,	25781,	42,	6,	0,	42},
	{QLM_MODE_40GAUI_2_C2C,	20625,	42,	6,	0,	42},
	{QLM_MODE_40GAUI_2_C2M,	20625,	42,	6,	0,	42},
	{QLM_MODE_50GAUI_2_C2C,	25781,	42,	6,	0,	42},
	{QLM_MODE_50GAUI_2_C2M,	25781,	42,	6,	0,	42},
	{QLM_MODE_80GAUI_4_C2C,	20625,	42,	6,	0,	42},
	{QLM_MODE_80GAUI_4_C2M,	20625,	42,	6,	0,	42},
	{QLM_MODE_CAUI_4_C2C,	25781,	42,	6,	0,	42},
	{QLM_MODE_CAUI_4_C2M,	25781,	42,	6,	0,	42},
	{QLM_MODE_25G_AN,	25781,	42,	6,	0,	42},
	{QLM_MODE_50G_AN,	25781,	42,	6,	0,	42},
	{QLM_MODE_100G_AN,	25781,	42,	6,	0,	42},
	{QLM_MODE_USXGMII_4X1,	20625,	42,	6,	0,	42},
	{QLM_MODE_USXGMII_2X1,	20625,	42,	6,	0,	42},
	{QLM_MODE_USXGMII_1X1,	10312,	48,	0,	0,	42},
	{QLM_MODE_DISABLED,	0,	0,	0,	0,	0}
};

static int qlm_poll_for_csr(uint64_t addr, uint64_t mask,
					int poll_val, int timeout)
{
	uint64_t val;

	do {
		/*
		 * NOTE : directly read from addr instead of using
		 * CSR_READ in this case to avoid dependencies
		 */
		val = cavm_le64_to_cpu(*(volatile uint64_t *)addr);
		/*
		 * argument poll_val indicates if the bit should
		 * be polled for value of 1 or 0
		 */
		if ((poll_val && (val & mask)) || (!poll_val && !(val & mask)))
			break;
		udelay(1);
	} while (--timeout > 0);

	if (!timeout)
		return -1;

	return 0;
}

/*
 * Setup the PEM to either driver or receive reset from PRST based on RC or EP
 *
 * @param pem	Which PEM to setup
 * @param is_endpoint
 *			   Non zero if PEM is a EP
 */
octeontx_qlm_state_lane_t qlm_build_state(octeontx_qlm_modes_t mode,
	int baud_mhz, octeontx_qlm_mode_flags_t flags)
{
	octeontx_qlm_state_lane_t state;

	state.u = 0;
	state.s.mode = mode;
	state.s.baud_mhz = baud_mhz;
	state.s.flags = flags;
	state.s.pcie = (mode > QLM_MODE_DISABLED) &&
			(mode <= QLM_MODE_PCIE_1X16);
	state.s.sata = (mode == QLM_MODE_SATA);
	state.s.cgx = (mode >= QLM_MODE_SGMII) &&
			(mode < QLM_MODE_LAST);
	return state;
}

/*
 * Setup the PEM to either driver or receive reset from PRST based on RC or EP
 *
 * @param pem	Which PEM to setuo
 * @param is_endpoint  Non zero if PEM is a EP
 */
void qlm_setup_pem_reset(int pem, int is_endpoint)
{
	cavm_pemx_on_t pemx_on;

	/* Make sure is_endpoint is either 0 or 1 */
	is_endpoint = (is_endpoint != 0);
	CSR_MODIFY(c, CAVM_RST_CTLX(pem),
		/* Link down doesn't automatically assert PERST */
		c.s.prst_link = 0;
		/* Link down automatically assert soft reset for EP */
		c.s.rst_link = is_endpoint;
		/* PERST is output for RC, input for EP */
		c.s.rst_drv = !is_endpoint;
		/* Only read PERST in EP mode */
		c.s.rst_rcv = is_endpoint;
		/* PERST doesn't pull CHIP_RESET */
		c.s.rst_chip = 0);

	if (is_endpoint) {
		/*
		 * If we're configuring an endpoint manually the PEM will not
		 * be turned on by default by the hardware. Turn it on now
		 */
		pemx_on.u = CSR_READ(CAVM_PEMX_ON(pem));
		if (!pemx_on.s.pemon) {
			pemx_on.s.pemon = 1;
			CSR_WRITE(CAVM_PEMX_ON(pem), pemx_on.u);
		}
	}
}

/*
 * Put a QLM into hardware reset
 *
 * @param qlm	QLM to use
 *
 * @return Zero on success, negative on failure
 */
int qlm_reset(int qlm)
{
	CSR_MODIFY(c, CAVM_GSERNX_COMMON_RST_BCFG(qlm),
		c.s.domain_rst_en = 1;
		c.s.rst_pll_rst_sm = 1;
		c.s.pwdn = 1);
	return 0;
}

static void extract_tx_tuning(cavm_gsernx_lanex_tx_drv_bsts_t tx_drv_bsts,
	int *tx_cmain, int *tx_cpre, int *tx_cpost)
{
	int idle, cprea_int, cpreb_int, cposta_int, cpostb_int, cmaind_int;
	int cmainx, enpost_int, muxpost_int, enpre_int, muxpre_int, cmain, post;
	int pre;

	if (tx_drv_bsts.s.tx_invalid) {
		*tx_cmain = TX_TUNING_INVALID;
		*tx_cpre = TX_TUNING_INVALID;
		*tx_cpost = TX_TUNING_INVALID;
		return;
	}
	idle = (tx_drv_bsts.s.muxpost == 0) && (tx_drv_bsts.s.cpostb == 7) &&
		(tx_drv_bsts.s.cposta == 7) && (tx_drv_bsts.s.enpost == 0) &&
		(tx_drv_bsts.s.muxmain == 0) && (tx_drv_bsts.s.cmaind == 7) &&
		(tx_drv_bsts.s.enmain == 3) && (tx_drv_bsts.s.muxpre == 0) &&
		(tx_drv_bsts.s.cpreb == 7) && (tx_drv_bsts.s.cprea == 7) &&
		(tx_drv_bsts.s.enpre == 3);
	if (idle) {
		*tx_cmain = TX_TUNING_IDLE;
		*tx_cpre = TX_TUNING_IDLE;
		*tx_cpost = TX_TUNING_IDLE;
		return;
	}

	cprea_int = (tx_drv_bsts.s.enpre & 1) ? tx_drv_bsts.s.cprea + 1 : 0;
	cpreb_int = (tx_drv_bsts.s.enpre & 2) ? tx_drv_bsts.s.cpreb + 1 : 0;
	cposta_int = (tx_drv_bsts.s.enpost & 1) ? tx_drv_bsts.s.cposta + 1 : 0;
	cpostb_int = (tx_drv_bsts.s.enpost & 2) ? tx_drv_bsts.s.cpostb + 1 : 0;
	cmaind_int = (tx_drv_bsts.s.enmain & 8) ? tx_drv_bsts.s.cmaind + 1 : 0;

	cmainx = cmaind_int;
	if ((tx_drv_bsts.s.enpost & 2) && (tx_drv_bsts.s.muxpost & 2) &&
		(tx_drv_bsts.s.enmain & 8) && (tx_drv_bsts.s.muxmain & 8))
		cmainx += cpostb_int;
	if ((tx_drv_bsts.s.enpre & 2) && (tx_drv_bsts.s.muxpre & 2) &&
		(tx_drv_bsts.s.enmain & 8) && (tx_drv_bsts.s.muxmain & 8))
		cmainx += cpreb_int;

	enpost_int = (cmainx <= 16) && (tx_drv_bsts.s.enpost & 2) ? 1 : 0;
	muxpost_int = (cmainx <= 16) && (tx_drv_bsts.s.muxpost & 2) ? 1 : 0;
	enpre_int = (cmainx <= 16) && (tx_drv_bsts.s.enpre & 2) ? 1 : 0;
	muxpre_int = (cmainx <= 16) && (tx_drv_bsts.s.muxpre & 2) ? 1 : 0;

	cmain = cmainx + 24;
	post = 0;
	if (enpost_int && !muxpost_int)
		post = cposta_int + cpostb_int;
	else if (tx_drv_bsts.s.enpost & 1)
		post = cposta_int;
	pre = 0;
	if (enpre_int && !muxpre_int)
		pre = cprea_int + cpreb_int;
	else if (tx_drv_bsts.s.enpre & 1)
		pre = cprea_int;

	*tx_cmain = cmain;
	*tx_cpre = pre;
	*tx_cpost = post;
}

/*
 * Enable PRBS on a QLM
 *
 * @param qlm	QLM to use
 * @param prbs   PRBS mode (31, etc)
 * @param dir	Directions to enable. This is so you can enable TX and later
 *			   enable RX after TX has run for a time
 *
 * @return Zero on success, negative on failure
 */
int qlm_enable_prbs(int qlm, int prbs, octeontx_qlm_direction_t dir)
{
	int enable_tx = ((dir & OCTEONTX_QLM_DIRECTION_TX) != 0);
	int enable_rx = ((dir & OCTEONTX_QLM_DIRECTION_RX) != 0);
	int prbs_type, tx_cmain, tx_cpre, tx_cpost, num_lanes, is_pattern, lane;
	cavm_gsernx_lanex_tx_drv_bsts_t tx_drv_bsts;

	switch (prbs) {
	case 0: /* Use pattern memory */
		prbs_type = -1;
		break;
	case 7:
		prbs_type = 0;
		break;
	case 9:
		prbs_type = 2;
		break;
	case 11:
		prbs_type = 3;
		break;
	case 15:
		prbs_type = 4;
		break;
	case 20:
		prbs_type = 5;
		break;
	case 23:
		prbs_type = 6;
		break;
	case 29:
		prbs_type = 7;
		break;
	case 31:
	default:
		prbs_type = 8;
		break;
	}

	num_lanes = plat_octeontx_scfg->qlm_max_lane_num[qlm];
	is_pattern = (prbs_type == -1);
	for (lane = 0; lane < num_lanes; lane++) {
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_PAT_CTRL(qlm, lane),
			if (enable_tx)
				c.s.tx_rst_n = is_pattern;
			if (enable_rx)
				c.s.rx_rst_n = is_pattern;
			c.s.en = is_pattern;
			c.s.cycle_cnt_en = 0;
			c.s.cycle_cnt = 0);
		/* PRBS polarity is inverted internally */
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_LT_BCFG(qlm, lane),
			c.s.inv_rx_polarity = 1;
			c.s.inv_tx_polarity = 1);
		/* Capture the current Tx equalization settings */
		tx_drv_bsts.u = CSR_READ(
				CAVM_GSERNX_LANEX_TX_DRV_BSTS(qlm, lane));
		extract_tx_tuning(tx_drv_bsts, &tx_cmain, &tx_cpre, &tx_cpost);
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_LT_PRBS1_BCFG(qlm, lane),
			if (enable_rx) {
				c.s.prbs_rx_rst_n = !is_pattern;
				c.s.prbs_rx_mode = !is_pattern;
				c.s.prbs_type_rx = prbs_type;
			}
			if (enable_tx) {
				c.s.prbs_tx_rst_n = !is_pattern;
				c.s.prbs_tx_mode = !is_pattern;
				c.s.prbs_type_tx = prbs_type;
			}
			c.s.cycle_cnt_en = 0;
			c.s.cycle_cnt = 0);
		if (enable_tx) {
			CSR_MODIFY(c, CAVM_GSERNX_LANEX_SRCMX_BCFG(qlm, lane),
				c.s.tx_ctrl_sel =  is_pattern ? 0x10 : 0;
				c.s.tx_data_sel = is_pattern ? 0x10 : 0);
		}

		/*
		 * Program the captured Tx equalization settings unless
		 * they are invalid
		 */
		if (qlm_tune_lane_tx(qlm, lane, tx_cmain,
			tx_cpre, tx_cpost, tx_drv_bsts.s.tx_bs, -1)) {
			/*
			 * If invalid program the Tx equalization setting to
			 * main = 48, pre = 0, post = 0, bs = 42
			 */
			qlm_tune_lane_tx(qlm, lane, 48, 0, 0, 42, -1);
		}
	}
	return 0;
}

/*
 * Disable PRBS on a QLM
 *
 * @param qlm	QLM to use
 *
 * @return Zero on success, negative on failure
 */
int qlm_disable_prbs(int qlm)
{
	int lane, pcs_src;
	int num_lanes = plat_octeontx_scfg->qlm_max_lane_num[qlm];
	octeontx_qlm_state_lane_t state;

	for (lane = 0; lane < num_lanes; lane++) {
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_PAT_CTRL(qlm, lane),
			c.s.tx_rst_n = 0;
			c.s.rx_rst_n = 0;
			c.s.en = 0);
		/* PRBS polarity is inverted internally */
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_LT_BCFG(qlm, lane),
			c.s.inv_rx_polarity = 0;
			c.s.inv_tx_polarity = 0);
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_LT_PRBS1_BCFG(qlm, lane),
			c.s.prbs_rx_rst_n = 0;
			c.s.prbs_rx_mode = 0;
			c.s.prbs_tx_rst_n = 0;
			c.s.prbs_tx_mode = 0;
			c.s.cycle_cnt_en = 0);
		/* Clear the TX_DRV CSR Tx EQ overrides */
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_TX_DRV_BCFG(qlm, lane),
			c.s.en_tx_bs = 0;	//Disable the TX_BS override
			c.s.en_tx_drv = 0);  //Disable the Tx Driver
		state.u = CSR_READ(CAVM_GSERNX_LANEX_SCRATCHX(qlm, lane, 0));
		/* Determine where the QLM gets data from */
		if (state.s.pcie)
			pcs_src = 1;
		else if (state.s.sata)
			pcs_src = 4;
		else if (state.s.cgx)
			pcs_src = 2;
		else
			pcs_src = 0; /* PRBS */
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_SRCMX_BCFG(qlm, lane),
			c.s.tx_ctrl_sel = pcs_src;
			c.s.tx_data_sel = pcs_src);
	}
	return 0;
}

/*
 * Return the number of PRBS errors since PRBS started running
 *
 * @param qlm	QLM to use
 * @param lane   Which lane
 * @param clear  Clear counter after return the current value
 *
 * @return Number of errors
 */
uint64_t qlm_get_prbs_errors(int qlm, int lane, int clear)
{
	cavm_gsernx_lanex_srcmx_bcfg_t srcx_bcfg;
	cavm_gsernx_lanex_pat_dat_t pat_dat;
	cavm_gsernx_lanex_lt_prbs_sts_t lt_prbs_sts;

	srcx_bcfg.u = CSR_READ(CAVM_GSERNX_LANEX_SRCMX_BCFG(qlm, lane));
	if (srcx_bcfg.s.tx_data_sel == 0x10) {
		/* Pattern mode */
		pat_dat.u = CSR_READ(CAVM_GSERNX_LANEX_PAT_DAT(qlm, lane));
		if (clear) {
			CSR_MODIFY(c, CAVM_GSERNX_LANEX_PAT_CTRL(qlm, lane),
				c.s.rx_rst_n = 0);
			udelay(1);
			CSR_MODIFY(c, CAVM_GSERNX_LANEX_PAT_CTRL(qlm, lane),
				c.s.rx_rst_n = 1);
		}
		if (!pat_dat.s.framing_match || pat_dat.s.err_cnt_ovf)
			return -1;
		return pat_dat.s.err_cnt;
	}

	/* PRBS mode */
	lt_prbs_sts.u =
		CSR_READ(CAVM_GSERNX_LANEX_LT_PRBS_STS(qlm, lane));
	if (clear) {
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_LT_PRBS1_BCFG(qlm, lane),
			c.s.prbs_rx_rst_n = 0);
		udelay(1);
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_LT_PRBS1_BCFG(qlm, lane),
			c.s.prbs_rx_rst_n = 1);
	}
	if (!lt_prbs_sts.s.lock || lt_prbs_sts.s.err_cnt_ovf)
		return -1;
	return lt_prbs_sts.s.err_cnt;
}

/*
 * Inject an error into PRBS
 *
 * @param qlm	QLM to use
 * @param lane   Which lane
 */
void qlm_inject_prbs_error(int qlm, int lane)
{
	CSR_MODIFY(c, CAVM_GSERNX_LANEX_LT_BCFG(qlm, lane),
		c.s.inj_err_cnt_rst_n = 0);
	udelay(1);
	CSR_MODIFY(c, CAVM_GSERNX_LANEX_LT_BCFG(qlm, lane),
		c.s.inj_err_cnt_rst_n = 1;
		c.s.inj_err_cnt_en = 1;
		c.s.inj_err_cnt_len = 1);
}

/*
 * Enable shallow loopback on a QLM
 *
 * @param qlm	QLM to use
 * @param loop	Type of loopback. Not all QLMs support all modes
 *
 * @return Zero on success, negative on failure
 */
int qlm_enable_loop(int qlm, octeontx_qlm_loop_t loop)
{
	int lane;
	int num_lanes = plat_octeontx_scfg->qlm_max_lane_num[qlm];
	cavm_gsernx_lanex_pll_2_bcfg_t lanex_pll_2_bcfg;
	cavm_gsernx_lanex_lt_bcfg_t lanex_lt_bcfg;
	cavm_gsernx_lanex_rx_st_bcfg_t lanex_rx_st_bcfg;
	cavm_gsernx_lanex_tx_1_bcfg_t lanex_tx_1_bcfg;

	for (lane = 0; lane < num_lanes; lane++) {
		lanex_pll_2_bcfg.u = CSR_READ(
				CAVM_GSERNX_LANEX_PLL_2_BCFG(qlm, lane));
		lanex_lt_bcfg.u = CSR_READ(
				CAVM_GSERNX_LANEX_LT_BCFG(qlm, lane));
		lanex_rx_st_bcfg.u = CSR_READ(
				CAVM_GSERNX_LANEX_RX_ST_BCFG(qlm, lane));
		lanex_tx_1_bcfg.u = CSR_READ(
				CAVM_GSERNX_LANEX_TX_1_BCFG(qlm, lane));
		switch (loop) {
		case OCTEONTX_QLM_LOOP_DISABLED:
			/* Far end loop RX CDR to TX */
			lanex_pll_2_bcfg.s.shlb_en		= 0;
			/* Near end loop TX to RX in PCS lite */
			lanex_lt_bcfg.s.core_loopback_mode	= 0;
			/* Far end loop RX to TX in PCS lite */
			lanex_lt_bcfg.s.sloop_mode		= 0;
			/* Far end loop RX CDR to TX */
			lanex_rx_st_bcfg.s.en_sh_lb		= 0;
			/* Near end loop TX to RX */
			lanex_rx_st_bcfg.s.en_lb		= 0;
			/* Near end loop TX to RX in analog */
			lanex_tx_1_bcfg.s.tx_enloop		= 0;
			break;
		case OCTEONTX_QLM_LOOP_SHALLOW: /* External */
			/* Far end loop RX CDR to TX */
			lanex_pll_2_bcfg.s.shlb_en		= 1;
			/* Near end loop TX to RX in PCS lite */
			lanex_lt_bcfg.s.core_loopback_mode	= 0;
			/* Far end loop RX to TX in PCS lite */
			lanex_lt_bcfg.s.sloop_mode		= 1;
			/* Far end loop RX CDR to TX */
			lanex_rx_st_bcfg.s.en_sh_lb		= 1;
			/* Near end loop TX to RX */
			lanex_rx_st_bcfg.s.en_lb		= 0;
			/* Near end loop TX to RX in analog */
			lanex_tx_1_bcfg.s.tx_enloop		= 0;
			break;
		case OCTEONTX_QLM_LOOP_NEAR_END: /* Internal analog */
			/* Far end loop RX CDR to TX */
			lanex_pll_2_bcfg.s.shlb_en		= 0;
			/* Near end loop TX to RX in PCS lite */
			lanex_lt_bcfg.s.core_loopback_mode	= 0;
			/* Far end loop RX to TX in PCS lite */
			lanex_lt_bcfg.s.sloop_mode		= 0;
			/* Far end loop RX CDR to TX */
			lanex_rx_st_bcfg.s.en_sh_lb		= 0;
			/* Near end loop TX to RX */
			lanex_rx_st_bcfg.s.en_lb		= 1;
			/* Near end loop TX to RX in analog */
			lanex_tx_1_bcfg.s.tx_enloop		= 1;
			break;
		case OCTEONTX_QLM_LOOP_CORE: /* Internal digital */
			/* Far end loop RX CDR to TX */
			lanex_pll_2_bcfg.s.shlb_en		= 0;
			/* Near end loop TX to RX in PCS lite */
			lanex_lt_bcfg.s.core_loopback_mode	= 1;
			/* Far end loop RX to TX in PCS lite */
			lanex_lt_bcfg.s.sloop_mode		= 0;
			/* Far end loop RX CDR to TX */
			lanex_rx_st_bcfg.s.en_sh_lb		= 0;
			/* Near end loop TX to RX */
			lanex_rx_st_bcfg.s.en_lb		= 0;
			/* Near end loop TX to RX in analog */
			lanex_tx_1_bcfg.s.tx_enloop		= 0;
			break;
		}
		CSR_WRITE(CAVM_GSERNX_LANEX_PLL_2_BCFG(qlm, lane),
				lanex_pll_2_bcfg.u);
		CSR_WRITE(CAVM_GSERNX_LANEX_LT_BCFG(qlm, lane),
				lanex_lt_bcfg.u);
		CSR_WRITE(CAVM_GSERNX_LANEX_RX_ST_BCFG(qlm, lane),
				lanex_rx_st_bcfg.u);
		CSR_WRITE(CAVM_GSERNX_LANEX_TX_1_BCFG(qlm, lane),
				lanex_tx_1_bcfg.u);
	}
	return 0;
}

/*
 * Given a valid PEM number, return its speed in Gbaud
 *
 * @param pem	PEM to get speed of
 *
 * @return Speed in Gbaud. Zero if disabled
 */
int qlm_get_gbaud_mhz_pem(int pem)
{
	cavm_pemx_diag_status_t diag_status;

	diag_status.u = CSR_READ(CAVM_PEMX_DIAG_STATUS(pem));
	switch (diag_status.cn9.pclk_rate) {
	case 0: /* Gen 1 */
		return 2500;
	case 1: /* Gen 2 */
		return 5000;
	case 2: /* Gen 3 */
		return 8000;
	case 3: /* Gen 4 */
		return 16000;
	}
	return 0;
}

/*
 * Perform RX equalization on a QLM
 *
 * @param qlm	  QLM to perform RX equalization on
 * @param qlm_lane Lane to use, or -1 for all lanes
 *
 * @return Zero on success, negative if any lane failed RX equalization
 */
int qlm_rx_equalization(int qlm, int qlm_lane)
{
	const int TIMEOUT = 1000; /* 1ms */
	const int MAX_LANES = plat_octeontx_scfg->qlm_max_lane_num[qlm];
	int lane;

	debug_qlm(QLM, "N0.QLM%d: Starting RX equalization on lane %d\n",
			qlm, qlm_lane);

	for (lane = 0; lane < MAX_LANES; lane++) {
		/* Skip lanes we don't care about */
		if ((qlm_lane != -1) && (qlm_lane != lane))
			continue;
		/* Enable deep idle */
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_RST1_BCFG(qlm, lane),
			c.s.rx_go2deep_idle = 1);
	}
	for (lane = 0; lane < MAX_LANES; lane++) {
		/* Skip lanes we don't care about */
		if ((qlm_lane != -1) && (qlm_lane != lane))
			continue;
		/* Wait for deep idle */
		qlm_poll_for_csr(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane),
			GSERN_LANE_INIT_BSTS_RX_DEEP_IDLE, 1, TIMEOUT);
		/* Disable deep idle */
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_RST1_BCFG(qlm, lane),
			c.s.rx_go2deep_idle = 0);
	}
	for (int lane = 0; lane < MAX_LANES; lane++) {
		/* Skip lanes we don't care about */
		if ((qlm_lane != -1) && (qlm_lane != lane))
			continue;
		/* Wait for exit of deep idle */
		qlm_poll_for_csr(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane),
			GSERN_LANE_INIT_BSTS_RX_DEEP_IDLE, 0, TIMEOUT);
		/* Wait for RX ready */
		qlm_poll_for_csr(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane),
			GSERN_LANE_INIT_BSTS_RX_READY, 1, TIMEOUT);
	}
	return 0;
}

/*
 * Configure the TX tuning parameters for a QLM lane
 *
 * @param qlm	   QLM to configure
 * @param lane	  Lane to configure
 * @param tx_cmain  Transmitter Main (C0) equalizer tap coefficient value.
 *                  Programs the SerDes transmitter Main tap. Valid range is
 *                  0x30 to 0x18.
 * @param tx_cpre   Transmitter Pre (C-1) equalizer tap coefficient value.
 *                  Programs the transmitter Pre tap. Valid range is 0 to 0x10.
 * @param tx_cpost  Transmitter Post (C+1) equalizer tap coefficient value.
 *                  Programs the transmitter Post tap. Valid range is 0 to
 *                  0x10.
 * @param tx_bs	 TX bias/swing selection. This setting only takes effect if
 *                  [TX_CSPD] is deasserted; with [TX_CSPD] asserted the
 *                  bias/swing control setting seen in the analog bias generator
 *                  is zero.
 *                  Typical override values would be:
 *                  42 = Nominal 1.0V p-p transmit amplitude.
 *                  52 = Nominal 1.2V p-p transmit amplitude.
 *                  The maximum usable value without transmitted waveform
 *                  distortion depends primarily on voltage, secondarily on
 *                  process corner and temperature, but is at least 52. There is
 *                  no minimum setting based on transmitter distortion, only
 *                  that set by the receiver.
 * @param tx_unused Currently unused
 *
 * @return Zero on success, negative on failure
 */
int qlm_tune_lane_tx(int qlm, int lane, int tx_cmain, int tx_cpre,
	int tx_cpost, int tx_bs, int tx_unused)
{
	cavm_gsernx_lanex_srcmx_bcfg_t gsernx_lanex_srcmx_bcfg;
	int _i_en, _stuff, _cpre, _cmain, _cpost;
	/*
	 * Decoded Tx EQ variables to write to the GSERNX_LANEX_TX_DRV_BCFG CSR
	 */
	int enpre, cprea, cpreb, muxpre, enmain, cmaind, muxmain, enpost;
	int cposta, cpostb, muxpost;
	/* internal variables */
	int cpre, cmain, cpost, en;
	int cprea_int, cpreb_int, cmaind_int, cposta_int, cpostb_int;
	int enpre_int;
	int enmain_int, enpost_int;
	/*
	 * =(cpre>>3) + (|cpre[2:0]) + (cpost>>3) + (|cpost[2:0]); range: 0..4
	 */
	int cppru;
	/* possible values are 0 to 24 (6'h18) */
	int cmainx;
	/* possible values are 0 to 504 */
	int cmainx_x_21;
	int cmaindiff;
	int tmp_cpost1, tmp_cpre, tmp__cmain, tmp_cmainx_x_21;

	/*
	 * The rules for programming the transmitter equalizer taps are (all
	 *     values in decimal):
	 *     [TX_CMAIN] + [TX_CPRE] + [TX_CPOST] <= 48
	 *     [TX_CMAIN] - [TX_CPRE] - [TX_CPOST] >= 6
	 *     48 >= [TX_CMAIN] >= 24
	 *     16 >= [TX_CPRE] >= 0
	 *     16 >= [TX_CPOST] >= 0
	 */
	if (tx_cmain + tx_cpre + tx_cpost > 48) {
		WARN(
			"N0.QLM%d.Lane%d: Invalid tuning, Main(%d) + Pre(%d) + Post(%d) <= 48(%d)\n",
			qlm, lane, tx_cmain, tx_cpre, tx_cpost,
			tx_cmain + tx_cpre + tx_cpost);
		return -1;
	}
	if (tx_cmain - tx_cpre - tx_cpost < 6) {
		WARN(
			"N0.QLM%d.Lane%d: Invalid tuning, Main(%d) - Pre(%d) - Post(%d) >= 6(%d)\n",
			qlm, lane, tx_cmain, tx_cpre, tx_cpost,
			tx_cmain - tx_cpre - tx_cpost);
		return -1;
	}
	if ((tx_cmain < 24) || (tx_cmain > 48)) {
		WARN(
			"N0.QLM%d.Lane%d: Invalid tuning, Main (%d, should be 24-48)\n",
			qlm, lane, tx_cmain);
		return -1;
	}
	if ((tx_cpre < 0) || (tx_cpre > 16)) {
		WARN(
			"N0.QLM%d.Lane%d: Invalid tuning, Pre (%d, should be 0-16)\n",
			qlm, lane, tx_cpre);
		return -1;
	}
	if ((tx_cpost < 0) || (tx_cpost > 16)) {
		WARN(
			"N0.QLM%d.Lane%d: Invalid tuning, Post (%d, should be 0-16)\n",
			qlm, lane, tx_cpost);
		return -1;
	}

	gsernx_lanex_srcmx_bcfg.u = CSR_READ(
				CAVM_GSERNX_LANEX_SRCMX_BCFG(qlm, lane));
	/* Check if GSER lane is configured in PCIe mode */
	if (gsernx_lanex_srcmx_bcfg.s.tx_ctrl_sel == 1) {
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_PCIE_TXBIAS_BCFG(qlm, lane),
			c.s.tx_bias_full = tx_bs);
		return 0;
	}
	/* Check if GSER lane is configured in CGX mode */
	else if (gsernx_lanex_srcmx_bcfg.s.tx_ctrl_sel == 2) {
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_CGX_TXEQ_BCFG(qlm, lane),
			if (tx_cpost != -1)
				c.s.tx_cpost = tx_cpost;
			if (tx_cmain != -1)
				c.s.tx_cmain = tx_cmain;
			if (tx_cpre != -1)
				c.s.tx_cpre = tx_cpre;
			if (tx_bs != -1)
				c.s.tx_bs = tx_bs;
			);
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_CGX_TXEQ_BCFG(qlm, lane),
			c.s.tx_coeff_update = 1);
		return 0;
	}
	/* Check if GSER lane is configured in SATA mode */
	else if (gsernx_lanex_srcmx_bcfg.s.tx_ctrl_sel == 4) {
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_SATA_TXDRV1_BCFG(qlm, lane),
			if (tx_cpost != -1)
				c.s.sata_g1_cpost = tx_cpost;
			if (tx_cpost != -1)
				c.s.sata_g1_cmain = tx_cmain;
			if (tx_cpost != -1)
				c.s.sata_g1_cpre = tx_cpre;
			if (tx_bs != -1)
				c.s.sata_g1_tx_bias = tx_bs;
			);
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_SATA_TXDRV2_BCFG(qlm, lane),
			if (tx_cpost != -1)
				c.s.sata_g2_cpost = tx_cpost;
			if (tx_cpost != -1)
				c.s.sata_g2_cmain = tx_cmain;
			if (tx_cpost != -1)
				c.s.sata_g2_cpre = tx_cpre;
			if (tx_bs != -1)
				c.s.sata_g2_tx_bias = tx_bs;
			);
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_SATA_TXDRV3_BCFG(qlm, lane),
			if (tx_cpost != -1)
				c.s.sata_g3_cpost = tx_cpost;
			if (tx_cpost != -1)
				c.s.sata_g3_cmain = tx_cmain;
			if (tx_cpost != -1)
				c.s.sata_g3_cpre = tx_cpre;
			if (tx_bs != -1)
				c.s.sata_g3_tx_bias = tx_bs;
			);
		return 0;
	}
	/* Check if GSER lane is configured in PRBS or Pattern memory mode */
	else if (gsernx_lanex_srcmx_bcfg.s.tx_ctrl_sel == 0 ||
			 gsernx_lanex_srcmx_bcfg.s.tx_ctrl_sel == 0x10) {
		/*
		 * Override the Transmitter Equalizer using
		 * the GSERNX_LANEX_TX_DRV_BCFG CSR and compute the decoded
		 * raw Tx EQ fields from the tx_cpre, tx_cmain, tx_cpost values
		 * passed in
		 */

		_i_en = 1;   /* tx_drv enable */
		/*
		 * FIXME: bitstuffing is off. Add check if we are in bitstuffing
		 *        mode and set this flag
		 */
		_stuff = 0;

		enpre = 0;
		enpre_int = 0;

		enmain_int = 0;
		muxmain = 0;
		enpre_int = 0;
		muxpre = 0;
		enpost_int  = 0;
		muxpost = 0;
		cprea_int = 1;
		cpreb_int = 1;
		cmaind_int = 1;
		cposta_int = 1;
		cpostb_int = 1;
		cpre =  tx_cpre;	/* start with passed-in values */
		cmain = tx_cmain;	/* start with passed-in values */
		cpost = tx_cpost;	/* start with passed-in values */
		_cpre =  tx_cpre;	/* start with passed-in values */
		_cmain = tx_cmain;	/* start with passed-in values */
		_cpost = tx_cpost;	/* start with passed-in values */
		en = _i_en;		/* start with passed-in values */

		/* Check & fix 'invalid' settings */
		if (_stuff == 1) {
			/* No precursor during bit-stuffing */
			if (_cpre != 0) /* if ( (|_cpre) ) { */
				cpre = 0;
		} else {
			/* Precursor out of range (not-stuffed) */
			if (_cpre > 12)
				cpre = 12;
		} /* else: !if( _stuff ) */

		/* Postcursor out of range */
		if (_cpost > 16)
			cpost = 16;

		/* Main cursor too large */
		if (_cmain > 48)
			cmain = 48;

		/* Main cursor too small */
		if (_cmain < 24)
			cmain = 24;

		/*
		 * check for too many blocks in use
		 * original c code comment may work directly here
		 * if ((ceil(cprei/8)+ceil(cmaini/8)+ceil(cposti/8))>8) begin
		 * original code from sv
		 * cppru = (cpre[4:3]) + (|cpre[2:0]) + (cpost[4:3]) +
		 * (|cpost[2:0]);  // max possible value is 4, so
		 */
		tmp_cpost1 = (cpost >> 3) & (0x3);	/* (cpost[4:3]) */
		tmp_cpre = (cpre & 7) > 0  ?  1 : 0;	/* (|cpre[2:0]) */

		cppru = (cpre >> 3) & 0x3;		/* (cpre[4:3]) */
		cppru = (cppru + tmp_cpre + tmp_cpost1 + tmp_cpost1) & 0x3;

		/*
		 * from sv
		 * if ( ( (_cmain[5:3]) + (|_cmain[2:0]) + cppru ) > 8 ) begin
		 */
		tmp__cmain = ((_cmain & 7) > 0) ? 1 : 0;
		if ((((_cmain >> 3) & 7) + tmp__cmain + cppru) > 8) {
			/*
			 * cmain = 'd64 - {cppru, 3'h0};
			 * result here must be =<63, so
			 */
			cmain = 64 - (cppru << 3);
		}

		/* Set tap weights */
		if (_stuff > 0) {
			/*
			 * Common tap weights for all valid bit stuffing
			 * settings
			 *
			 * enpre_int[1]  = '0; cpreb_int = 'd0; muxpre[1] = '1;
			 * Never used -- only E and ~L taps possible
			 */
			enpre_int  &= ~(1<<1); cpreb_int = 0; muxpre  |= (1<<1);
			/* enmain_int[0] = '1;  muxmain[0] = '0;  // Choose E */
			enmain_int |= 1;       muxmain &= ~(1);
			/* enmain_int[1] = '1;  muxmain[1] = '0;  // Choose E */
			enmain_int |= (1<<1);  muxmain &= ~(1<<1);
			/* enmain_int[2] = '1;  muxmain[2] = '0;  // Choose E */
			enmain_int |= (1<<2);  muxmain &= ~(1<<2);

			cmainx = cmain - 24;	/* cmain=<48, so cmainx=<24 */

			/* Set up postcursor tap weights */
			if (cpost <= 8) {	/* All tap weight on cpostb */
				enpost_int &= ~(1);
				cposta_int = 0;
				muxpost &= ~(1);
				if (cpost > 0)
					enpost_int |= (1 << 1);
				else
					enpost_int &= ~(1 << 1);
				cpostb_int = cpost;
				muxpost &= ~(1<<1);
			} else {
				/*
				 * Split tap weights between cpostb and cposta
				 */
				enpost_int |= 1;
				cposta_int = (cpost>>1) + (cpost & 1);
				muxpost &= ~(1);
				enpost_int |= (1<<1);
				cpostb_int = cpost - cposta_int;
				muxpost &= ~(1<<1);
			}  /* cpost */

			/* Set up main cursor tap weights for bit stuffing */
			if (cmainx <= 8) {	/* All tap weight on cmaind */
				if (cmainx != 0)
					enmain_int |= (1 << 3);
				else
					enmain_int &= ~(1 << 3);
				cmaind_int = cmainx;
				muxmain &= ~(1<<3);
				enpre_int &= ~(1);
				cprea_int = 0;
				muxpre |= 1;
			} else if (cmainx <= 16) {
				/* Split tap weight between cmaind and cprea */
				enmain_int |= (1<<3);
				cmaind_int = (cmainx>>1) + (cmainx & 1);
				muxmain &= ~(1<<3);
				enpre_int |= 1;
				cprea_int = cmainx - cmaind_int;
				muxpre  |= 1;
			} else {
				/*
				 * Split tap weight between cmaind, cprea,
				 * and cpost a
				 */

				/*
				 * Need cmaind_int=ceil(cmainx/3);
				 * use (21*cmainx)>>6 + |frac_bits
				 */
				cmainx_x_21 = ((cmainx << 4) & 0x1ff) +
					((cmainx << 2) & 0x1ff) + cmainx;
				tmp_cmainx_x_21 = (cmainx_x_21 & 0x3f) ? 1 : 0;
				enmain_int |= (1<<3);
				cmaind_int = ((cmainx_x_21>>6) & 7) +
								tmp_cmainx_x_21;
				muxmain &= ~(1<<3);
				cmaindiff = cmainx - (cmaind_int&(0xf));
				enpre_int |= 1;
				cprea_int = (((cmaindiff >> 1) & 0xf) +
							(cmaindiff & 1)) & 0xf;
				muxpre |= 1;
				enpost_int |= 1;
				cposta_int =
					(cmainx - cmaind_int - cprea_int) & 0xf;
				muxpost |= 1;
			}  /* cmain */
		} else {  /* if ( _stuff ) */

			/* Common tap weights for all valid settings */
			enmain_int |= 1;       muxmain |= 1;      /* Choose M */
			enmain_int |= (1<<1);  muxmain |= (1<<1); /* Choose M */
			enmain_int |= (1<<2);  muxmain |= (1<<2); /* Choose M */
			cmainx = cmain - 24;

			/* Set up precursor tap weights */
			if (cpre <= 8) {
				/*
				 * enpre_int[0] = (cpre>0);  cprea_int = cpre;
				 * muxpre[0] = '0;  // Choose ~E
				 */
				enpre_int = (cpre > 0) ?
					(enpre_int | 1) : (enpre & ~(1));
				cprea_int = cpre;
				muxpre &= ~(1);
				enpre_int &= ~(1<<1); /* Choose ~E */
				cpreb_int = 0;
				muxpre &= ~(1<<1);
			} else {
				/*
				 * enpre_int[0] = '1;
				 * cprea_int = (cpre>>1) + cpre[0];
				 * muxpre[0] = '0;  // Choose ~E
				 */
				enpre_int |= 1;
				cprea_int = (cpre>>1) + (cpre & (1));
				muxpre &= ~(1);
				/*
				 * enpre_int[1] = '1;
				 * cpreb_int = cpre - cprea_int;
				 * muxpre[1] = '0;  // Choose ~E
				 */
				enpre_int |= (1<<1);
				cpreb_int = cpre - cprea_int;
				muxpre &= ~(1<<1);
			}  /* cpre */

			/*
			 * Set up postcursor tap weights (common with normal
			 * and bit stuffing)
			 */
			if (cpost <= 8) {
				if (cpost > 0)
					enpost_int |= 1;
				else
					enpost_int &= ~(1);
				/*
				 * enpost_int[0] = (cpost>0);
				 * cposta_int = cpost;
				 * muxpost[0] = '0;  // Choose ~L
				 */
				cposta_int = cpost;
				muxpost &= ~(1);
				/*
				 * enpost_int[1] = '0;
				 * cpostb_int = '0;
				 * muxpost[1] = '0;  // Choose ~L
				 */
				enpost_int &= ~(1<<1);
				cpostb_int = 0;
				muxpost &= ~(1<<1);
			} else {
				/*
				 * enpost_int[0] = '1;
				 * cposta_int = (cpost>>1) + cpost[0];
				 * muxpost[0] = '0;  // Choose ~L
				 */
				enpost_int |= 1;
				cposta_int = (cpost>>1) + (cpost & (1));
				muxpost &= ~(1);
				/*
				 * enpost_int[1] = '1;
				 * cpostb_int = cpost - cposta_int;
				 * muxpost[1] = '0;  // Choose ~L
				 */
				enpost_int |= (1<<1);
				cpostb_int = cpost - cposta_int;
				muxpost &= ~(1<<1);
			}   /* cpost */

			/* Set up main cursor tap weights */
			if (cmainx <= 8) {  /* <=8,  only use 4th main block */
				if (cmainx > 0)
					enmain_int |= (1 << 3);
				else
					enmain_int &= ~(1 << 3);
				/*
				 * enmain_int[3] = (cmainx>0);
				 * cmaind_int = cmainx;
				 * muxmain[3] = '1; // Choose M
				 */
				cmaind_int = cmainx;
				muxmain |= (1 << 3);
			} else if (cmainx <= 16) {
				/*
				 * >8, <=16, use 4th main block and one from
				 * pre or post
				 *
				 * enmain_int[3] = '1;
				 * cmaind_int = (cmainx>>1) + cmainx[0];
				 * muxmain[3] = '1; // Choose M
				 */
				enmain_int |= (1<<3);
				cmaind_int = (cmainx>>1) + (cmainx & (1));
				muxmain |= (1<<3);

				/* Decide where to put the last block */
				if (enpre_int&(1<<1)) {
					/* Choose M */
					enpost_int |= (1<<1);
					cpostb_int =
						(cmainx - cmaind_int) & 0xf;
					muxpost |= (1<<1);
				} else {
					/*
					 * enpre_int[1] = '1;
					 * cpreb_int = cmainx - cmaind_int;
					 * muxpre[1]  = '1; // Choose M
					 */
					enpre_int |= (1<<1);
					cpreb_int =
						(cmainx - cmaind_int) & 0xf;
					muxpre |= (1<<1);
				}
			} else {
				/*
				 * >16, use 4th main block and one from
				 * pre & post
				 */
				cmainx_x_21 = ((cmainx << 4) & 0x1ff) +
					      ((cmainx << 2) & 0x1ff) + cmainx;

				/*
				 * enmain_int[3] = '1;
				 * cmaind_int =
				 *     (cmainx_x_21[8:6]) + (|cmainx_x_21[5:0]);
				 * muxmain[3] = '1;  // Choose M
				 */
				tmp_cmainx_x_21 = (cmainx_x_21 & 0x3f) ? 1 : 0;
				enmain_int |= (1<<3);
				cmaind_int = ((cmainx_x_21>>6) & 7) +
							tmp_cmainx_x_21;
				muxmain |= (1<<3);

				/* cmaindiff = cmainx - {1'b0, cmaind_int}; */
				cmaindiff = cmainx - (cmaind_int&(0xf));
				/*
				 * enpre_int[1]  = '1;
				 * cpreb_int  = (cmaindiff[4:1]) + cmaindiff[0];
				 * muxpre[1]  = '1;  // Choose M
				 */
				enpre_int |= (1<<1);
				cpreb_int = ((cmaindiff >> 1) & 0xf) +
							(cmaindiff & (1));
				muxpre  |= (1<<1);
				/*
				 * enpost_int[1] = '1;
				 * cpostb_int = cmainx - cmaind_int - cpreb_int;
				 * muxpost[1] = '1;  // Choose M
				 */
				enpost_int |= (1<<1);
				cpostb_int = cmainx - cmaind_int - cpreb_int;
				muxpost |= 1<<1;
			}
		} /* else: !if( stuff ) */

		/*
		 * max value for *_int is 8, so the c*-1 will all fit into 3b
		 * corresponding en* is 0 when c* is zero,
		 * so the muxes may not be needed
		 *
		 * cprea  = {4{en}} & ( (|cprea_int)  ? cprea_int  - 1 : '0 );
		 */
		cprea = (en > 0) ? ((cprea_int > 0) ? cprea_int - 1 : 0) : 0;
		/* cpreb  = {4{en}} & ((|cpreb_int) ? cpreb_int  - 1 : '0 ); */
		cpreb = (en > 0) ? ((cpreb_int > 0) ? cpreb_int - 1 : 0) : 0;
		/* cmaind = {4{en}} & ((|cmaind_int) ? cmaind_int - 1 : '0); */
		cmaind = (en > 0) ? ((cmaind_int > 0) ? cmaind_int - 1 : 0) : 0;
		/* cposta = {4{en}} & ((|cposta_int) ? cposta_int - 1 : '0); */
		cposta = (en > 0) ? ((cposta_int > 0) ? cposta_int - 1 : 0) : 0;
		/* cpostb = {4{en}} & ((|cpostb_int) ? cpostb_int - 1 : '0); */
		cpostb = (en > 0) ? ((cpostb_int > 0) ? cpostb_int - 1 : 0) : 0;

		/* enpre  = {2{en}} & enpre_int; */
		enpre = (en > 0) ? enpre_int : 0;
		/* enmain = {4{en}} & enmain_int; */
		enmain = (en > 0) ? enmain_int : 0;
		/* enpost = {2{en}} & enpost_int; */
		enpost = (en > 0) ? enpost_int : 0;

		/*
		 * Now Update the TX_DRV CSR with the decoded
		 * Tx EQ override values
		 */
		CSR_MODIFY(c, CAVM_GSERNX_LANEX_TX_DRV_BCFG(qlm, lane),
			if (tx_bs != -1)
				c.s.tx_bs = tx_bs;
			/* Post EQ Tap */
			if (muxpost != -1)
				c.s.muxpost = muxpost;
			if (cpostb != -1)
				c.s.cpostb = cpostb;
			if (cposta != -1)
				c.s.cposta = cposta;
			if (enpost != -1)
				c.s.enpost = enpost;
			/* Main EQ Tap */
			if (muxmain != -1)
				c.s.muxmain = muxmain;
			if (cmaind != -1)
				c.s.cmaind = cmaind;
			if (enmain != -1)
				c.s.enmain = enmain;
			/* PRE EQ Tap */
			if (muxpre != -1)
				c.s.muxpre = muxpre;
			if (cpreb != -1)
				c.s.cpreb = cpreb;
			if (cprea != -1)
				c.s.cprea = cprea;
			if (enpre != -1)
				c.s.enpre = enpre;
			/* Enable Bias Override and Tx Driver */
			c.s.en_tx_bs = 1;  /* Enable the TX_BS override */
			c.s.en_tx_drv = 1; /* Enable the Tx Driver */
			);
	} else {
		WARN("N0.QLM%d: Mode not programmed before tuning call\n", qlm);
		return -1;
	}
	return 0;
}

/*
 * Get the TX tuning parameters for a QLM lane
 *
 * @param qlm	   QLM to configure
 * @param lane	  Lane to configure
 * @param tx_cmain  Transmitter Main (C0) equalizer tap coefficient value.
 *                  Programs the SerDes transmitter Main tap. Valid range is
 *                  0x30 to 0x18.
 * @param tx_cpre   Transmitter Pre (C-1) equalizer tap coefficient value.
 *                  Programs the transmitter Pre tap. Valid range is 0 to 0x10.
 * @param tx_cpost  Transmitter Post (C+1) equalizer tap coefficient value.
 *                  Programs the transmitter Post tap. Valid range is 0 to
 *                  0x10.
 * @param tx_bs	 TX bias/swing selection. This setting only takes effect if
 *                  [TX_CSPD] is deasserted; with [TX_CSPD] asserted the
 *                  bias/swing control setting seen in the analog bias generator
 *                  is zero.
 *                  Typical override values would be:
 *                  42 = Nominal 1.0V p-p transmit amplitude.
 *                  52 = Nominal 1.2V p-p transmit amplitude.
 *                  The maximum usable value without transmitted waveform
 *                  distortion depends primarily on voltage, secondarily on
 *                  process corner and temperature, but is at least 52. There is
 *                  no minimum setting based on transmitter distortion, only
 *                  that set by the receiver.
 * @param tx_unused Currently unused
 *
 * @return Zero on success, negative on failure
 */
int qlm_get_tune_lane_tx(int qlm, int lane, int *tx_cmain, int *tx_cpre,
	int *tx_cpost, int *tx_bs, int *tx_unused)
{
	cavm_gsernx_lanex_tx_drv_bsts_t tx_drv_bsts;

	tx_drv_bsts.u = CSR_READ(CAVM_GSERNX_LANEX_TX_DRV_BSTS(qlm, lane));

	extract_tx_tuning(tx_drv_bsts, tx_cmain, tx_cpre, tx_cpost);
	*tx_bs = tx_drv_bsts.s.tx_bs;
	*tx_unused = 0;
	return 0;
}

/*
 * Some QLM speeds need to override the default tuning parameters
 *
 * @param qlm	  QLM to configure
 * @param lane	 Lane to tune, or -1 for all
 * @param mode	 Desired mode
 * @param baud_mhz Desired speed
 */
void qlm_tune(int qlm, int lane, octeontx_qlm_modes_t mode, int baud_mhz)
{
	const struct default_tuning_t *tuning = DEF_TUNING;
	int num_lanes, l;

	while (tuning->mode) {
		if ((tuning->mode == mode) && (tuning->baud_mhz == baud_mhz))
			break;
		tuning++;
	}
	if (!tuning->mode)
		return;

	num_lanes = plat_octeontx_scfg->qlm_max_lane_num[qlm];
	for (l = 0; l < num_lanes; l++) {
		if ((l == lane) || (lane == -1))
			qlm_tune_lane_tx(qlm, l, tuning->tx_cmain,
				tuning->tx_cpre, tuning->tx_cpost,
				tuning->tx_bs, -1);
	}
}

/*
 * Called to initialize the GSERN programming API
 */
void qlm_init(void)
{
	/* Power on the common clocks */
	CSR_MODIFY(c, CAVM_RST_REFC_CTL,
		c.s.cclk2_pwdn = 0;
		c.s.cclk1_pwdn = 0);
}

/*
 * Call GSERN APIs for CN9XXX chips
 *
 * @param qlm	  QLM to configure
 * @param lane	 Lane inside the QLM
 * @param mode	 Desired mode
 * @param baud_mhz Desired speed
 * @param flags	Flags to specify mode specific options
 *
 * @return Zero on success, negative on failure
 */
int qlm_set_mode(int qlm, int lane, octeontx_qlm_modes_t mode, int baud_mhz,
	octeontx_qlm_mode_flags_t flags)
{
	int num_lanes = plat_octeontx_scfg->qlm_max_lane_num[qlm];
	int gsern_mode = GSERN_MODE_DISABLED;
	int gsern_flags = GSERN_FLAGS_NONE;
	int is_first = 0;
	int is_network = 0;
	int desired_lanes, start_lane, end_lane, l;
	octeontx_qlm_state_lane_t state =
				qlm_build_state(mode, baud_mhz, flags);

	switch (mode) {
	case QLM_MODE_DISABLED:
		gsern_mode = GSERN_MODE_DISABLED;
		break;
	case QLM_MODE_PCIE_1X1 ... QLM_MODE_PCIE_1X16:
		if (flags & OCTEONTX_QLM_MODE_FLAG_ENDPOINT)
			gsern_mode = GSERN_MODE_PCIE_EP;
		else
			gsern_mode = GSERN_MODE_PCIE_RC;
		/*
		 * Figure out how many lanes PCIe desires. This
		 * assumes the modes are in order from least lanes to
		 * most lanes
		 */
		desired_lanes = 1 << (mode - QLM_MODE_PCIE_1X1);
		if (desired_lanes > num_lanes) {
			switch (desired_lanes) {
			case 4:
				is_first = (qlm & 1) == 0;
				if (num_lanes < 4)
					gsern_flags = GSERN_FLAGS_DUAL;
				break;
			case 8:
				is_first = (qlm & 1) == 0;
				gsern_flags = GSERN_FLAGS_DUAL;
				break;
			case 16:
				is_first = (qlm & 3) == 0;
				gsern_flags = GSERN_FLAGS_QUAD;
				break;
			}
		} else
			is_first = 1;
		break;
	case QLM_MODE_SATA:
		gsern_mode = GSERN_MODE_SATA;
		break;
	case QLM_MODE_SGMII:
	case QLM_MODE_1G_X:
	case QLM_MODE_XFI:
	case QLM_MODE_SFI:
	case QLM_MODE_10G_KR:
	case QLM_MODE_QSGMII:
	case QLM_MODE_20GAUI_C2C:
	case QLM_MODE_20GAUI_C2M:
	case QLM_MODE_25GAUI_C2C:
	case QLM_MODE_25GAUI_C2M:
	case QLM_MODE_25G_AN:
	case QLM_MODE_USXGMII_4X1:
	case QLM_MODE_USXGMII_2X1:
	case QLM_MODE_USXGMII_1X1:
		gsern_mode = GSERN_MODE_CGX;
		is_network = 1;
		break;
	case QLM_MODE_RXAUI:
	case QLM_MODE_40GAUI_2_C2C:
	case QLM_MODE_40GAUI_2_C2M:
	case QLM_MODE_50GAUI_2_C2C:
	case QLM_MODE_50GAUI_2_C2M:
	case QLM_MODE_50G_AN:
		gsern_mode = GSERN_MODE_CGX;
		gsern_flags = GSERN_FLAGS_DUAL;
		is_network = 1;
		break;
	case QLM_MODE_XAUI:
	case QLM_MODE_XLAUI:
	case QLM_MODE_XLAUI_C2M:
	case QLM_MODE_40G_KR4:
        case QLM_MODE_80GAUI_4_C2C:
        case QLM_MODE_80GAUI_4_C2M:
	case QLM_MODE_CAUI_4_C2C:
	case QLM_MODE_CAUI_4_C2M:
	case QLM_MODE_100G_AN:
		gsern_mode = GSERN_MODE_CGX;
		gsern_flags = GSERN_FLAGS_QUAD;
		is_network = 1;
		break;
	case QLM_MODE_LAST:
		return -1;
	}

	/* Figure out how many lanes to apply the mode to */
	start_lane = (lane == -1) ? 0 : lane;
	end_lane = (lane == -1) ? num_lanes - 1 : lane;

	/* Loop through all lanes */
	for (l = start_lane; l <= end_lane; l++) {
		/* Only networking requires a call per lane */
		if (is_network || (l == 0)) {
			if (gsern_set_mode(qlm, l, gsern_mode, is_first,
					baud_mhz, gsern_flags))
				return -1;
		}
		CSR_WRITE(CAVM_GSERNX_LANEX_SCRATCHX(qlm, l, 0), state.u);
		qlm_tune(qlm, l, mode, baud_mhz);
	}

	return 0;
}

