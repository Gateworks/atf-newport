/** @file

  Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <delay_timer.h>
#include <platform_def.h>
#include <platform_dt.h>
#include <cavm_common.h>
#include <cavm_dt.h>
#include <cavm_cgx.h>
#include <cavm_cgx_intf.h>

/* define DEBUG_ATF_CGX to enable debug logs */
#undef DEBUG_ATF_CGX

#ifdef DEBUG_ATF_CGX
#define debug_cgx printf
#else
#define debug_cgx(...) ((void) (0))
#endif

static int cgx_poll_for_csr(int node, uint64_t addr, uint64_t mask,
					int poll_val)
{
	int tries = 100;
	uint64_t val;

	do {
		/* NOTE : directly read from addr instead of using
		 * CSR_READ in this case to avoid dependencies
		 */
		val = cavm_le64_to_cpu(*(volatile uint64_t *)addr);
		/* argument poll_val indicates if the bit should
		 * be polled for value of 1 or 0
		 */
		if ((poll_val && (val & mask)) || (!poll_val && !(val & mask)))
			break;
		udelay(CGX_POLL_FOR_CSR_DELAY);
	} while (--tries > 0);

	if (!tries)
		return -1;

	return 0;
}

/* This function initializes CGX in the SGMII/QSGMII modes
 * called one time either during boot or mode change
 */
static int cgx_sgmii_hw_init(int node, int cgx_id, int lmac_id)
{
	cgx_lmac_config_t *lmac;
	cavm_cgxx_gmp_gmi_txx_append_t tx_append;

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	debug_cgx("%s: cgx_id = %d, lmac_id = %d\n", __func__, cgx_id, lmac_id);

	/* set TX threshold */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_gmi_txx_thresh_t,
			CAVM_CGXX_GMP_GMI_TXX_THRESH(cgx_id, lmac_id),
			cnt, CGX_GMP_TX_FIFO_WORDS); /* 128-bit words FIFO */
	/* Max packet size */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_gmi_rxx_jabber_t,
			CAVM_CGXX_GMP_GMI_RXX_JABBER(cgx_id, lmac_id),
			cnt, CGX_MAX_FRAME_SIZE); /* Max Frame size */

	/* Disable frame alignment if using preamble */
	tx_append.u = CSR_READ(node, CAVM_CGXX_GMP_GMI_TXX_APPEND(
					cgx_id, lmac_id));
	CSR_WRITE(node, CAVM_CGXX_GMP_GMI_TXX_SGMII_CTL(cgx_id, lmac_id),
				!tx_append.s.preamble);
	tx_append.s.fcs = 1;
	tx_append.s.pad = 1;
	CSR_WRITE(node, CAVM_CGXX_GMP_GMI_TXX_APPEND(cgx_id,
					lmac_id), tx_append.u);

	/* Min packet size */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_gmi_txx_min_pkt_t,
			CAVM_CGXX_GMP_GMI_TXX_MIN_PKT(cgx_id, lmac_id),
			min_size, CGX_GMP_MIN_PACKET_SIZE);

	/* Disable disparity for QSGMII mode, to prevent
	 * propagation across ports
	 */
	if (lmac->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII) {
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_miscx_ctl_t,
				CAVM_CGXX_GMP_PCS_MISCX_CTL(
				cgx_id, lmac_id), disp_en, 0);
	}

	return 0;
}

/* This function initializes CGX in the XFI/XAUI/RXAUI/XLAUI/10G_R/40G_R
 * modes called one time either during boot or mode change
 */
static int cgx_xaui_hw_init(int node, int cgx_id, int lmac_id)
{
	cgx_lmac_config_t *lmac;
	cavm_cgxx_spux_misc_control_t spux_mctrl;
	cavm_cgxx_smux_tx_append_t smux_tx_append;

	debug_cgx("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	/* Max packet size */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_smux_rx_jabber_t,
		CAVM_CGXX_SMUX_RX_JABBER(cgx_id, lmac_id),
		cnt, CGX_MAX_FRAME_SIZE);

	/* Tx threshold */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_smux_tx_thresh_t,
		CAVM_CGXX_SMUX_TX_THRESH(cgx_id, lmac_id),
		cnt, CGX_SMUX_TX_FIFO_WORDS);

	/* FIXME: Disable forward error correction. should FEC
	 * enable option to be provided for 10G/40G BASE-R?
	 */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_fec_control_t,
			CAVM_CGXX_SPUX_FEC_CONTROL(cgx_id, lmac_id),
			fec_en, 0);

	spux_mctrl.u = CSR_READ(node, CAVM_CGXX_SPUX_MISC_CONTROL(
				cgx_id, lmac_id));
	spux_mctrl.s.rx_packet_dis = 1;
	/* Set interleaved running disparity for RXAUI */
	if (lmac->mode == CAVM_CGX_LMAC_TYPES_E_RXAUI)
		spux_mctrl.s.intlv_rdisp = 1;
	CSR_WRITE(node, CAVM_CGXX_SPUX_MISC_CONTROL(cgx_id, lmac_id),
					spux_mctrl.u);

	/* Append FCS & pad to each packet */
	smux_tx_append.u = CSR_READ(node, CAVM_CGXX_SMUX_TX_APPEND(
						cgx_id, lmac_id));
	smux_tx_append.s.pad = 1;
	smux_tx_append.s.fcs_d = 1;
	CSR_WRITE(node, CAVM_CGXX_SMUX_TX_APPEND(cgx_id, lmac_id),
					smux_tx_append.u);
	/* Min packet size */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_smux_tx_min_pkt_t,
			CAVM_CGXX_SMUX_TX_MIN_PKT(cgx_id, lmac_id),
			min_size, CGX_SMUX_MIN_PACKET_SIZE);

	return 0;
}

static void cgx_restart_training(int node, int cgx_id, int lmac_id)
{
	cavm_cgxx_spux_int_t spux_int;

	debug_cgx("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	/* clear the training interrupts by writing 1 - W1C CSR */
	spux_int.u = CSR_READ(node, CAVM_CGXX_SPUX_INT(
				cgx_id, lmac_id));
	spux_int.s.training_done = 1;
	spux_int.s.training_failure = 1;
	CSR_WRITE(node, CAVM_CGXX_SPUX_INT(cgx_id, lmac_id), spux_int.u);

	CSR_WRITE(node, CAVM_CGXX_SPUX_BR_PMD_LD_CUP(cgx_id, lmac_id), 0);
	CSR_WRITE(node, CAVM_CGXX_SPUX_BR_PMD_LP_CUP(cgx_id, lmac_id), 0);
	CSR_WRITE(node, CAVM_CGXX_SPUX_BR_PMD_LP_REP(cgx_id, lmac_id), 0);

	/* wait */
	udelay(CGX_SPUX_TRAINING_RESTART_DELAY);

	/* restart the training */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_br_pmd_control_t,
		CAVM_CGXX_SPUX_BR_PMD_CONTROL(cgx_id, lmac_id),
		train_restart, 1);
}

/* This function initializes the CGX LMAC for
 * a particular mode
 */
static void cgx_lmac_init(int node, int cgx_id, int lmac_id)
{
	cgx_lmac_config_t *lmac;
	cavm_cgxx_cmrx_config_t cmr_config;

	debug_cgx("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	/* FDT parser should have updated the lmac mode by now.
	 * check if mode is programmed, if not, return
	 */
	if ((lmac->mode == -1) || (lmac->lane_to_sds == -1)) {
		ERROR("%s:mode/lane_to_sds not programmed for CGX%dLMAC%d\n",
					__func__, cgx_id, lmac_id);
		return;
	}

	/* program CGX_CMRX_CONFIG register with
	 * lmac_type, lane_to_sds
	 */
	debug_cgx("%s mode %d lane_to_sds %d\n", __func__, lmac->mode,
					lmac->lane_to_sds);
	cmr_config.u = CSR_READ(node,  CAVM_CGXX_CMRX_CONFIG(
				cgx_id, lmac_id));
	cmr_config.s.lmac_type = lmac->mode;
	cmr_config.s.lane_to_sds = lmac->lane_to_sds;
	CSR_WRITE(node, CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
			cmr_config.u);

	/* do one time initialization of CGX based on
	 * the LMAC type. this function will be called
	 * once during boot and whenever mode change
	 * happens
	 */
	switch (lmac->mode) {
	case CAVM_CGX_LMAC_TYPES_E_SGMII:
	case CAVM_CGX_LMAC_TYPES_E_QSGMII:
		cgx_sgmii_hw_init(node, cgx_id, lmac_id);
		break;
	case CAVM_CGX_LMAC_TYPES_E_XAUI:
	case CAVM_CGX_LMAC_TYPES_E_RXAUI:
	case CAVM_CGX_LMAC_TYPES_E_TENG_R:
	case CAVM_CGX_LMAC_TYPES_E_FORTYG_R:
		cgx_xaui_hw_init(node, cgx_id, lmac_id);
		break;
	/* FIXME : add support for new modes*/
	default:
		break;
	}
}

/* This API sets the speed for the link based on PHY status */
int cgx_sgmii_set_link_speed(int node, int cgx_id, int lmac_id,
			 link_state_t *link)
{
	cavm_cgxx_cmrx_config_t cmr_config;
	cavm_cgxx_gmp_gmi_prtx_cfg_t prtx_cfg;
	cavm_cgxx_gmp_pcs_miscx_ctl_t pcs_miscx_ctl;
	cavm_cgxx_gmp_gmi_txx_slot_t txx_slot;
	cavm_cgxx_gmp_gmi_txx_burst_t txx_burst;

	debug_cgx("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	/* disable Rx/Tx */
	cmr_config.u = CSR_READ(node, CAVM_CGXX_CMRX_CONFIG(
				cgx_id, lmac_id));
	cmr_config.s.data_pkt_rx_en = 0;
	cmr_config.s.data_pkt_tx_en = 0;
	CSR_WRITE(node, CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
				cmr_config.u);

	/* Wait for GMX Tx/Rx to be idle */
	if (cgx_poll_for_csr(node, CAVM_CGXX_GMP_GMI_PRTX_CFG(cgx_id, lmac_id),
				CGX_GMP_TX_IDLE_MASK, 1)) {
		debug_cgx("%s: %d:%d CGX GMP Tx not Idle\n",
				__func__, cgx_id, lmac_id);
		cgx_set_error_type(node, cgx_id, lmac_id, CGX_ERR_TX_NOT_IDLE);
		return -1;
	}
	if (cgx_poll_for_csr(node,  CAVM_CGXX_GMP_GMI_PRTX_CFG(
				cgx_id, lmac_id), CGX_GMP_RX_IDLE_MASK, 1)) {
		debug_cgx("%s: %d:%d CGX GMP Rx not Idle\n",
				__func__, cgx_id, lmac_id);
		cgx_set_error_type(node, cgx_id, lmac_id, CGX_ERR_RX_NOT_IDLE);
		return -1;
	}

	/* Read GMX CFG */
	prtx_cfg.u = CSR_READ(node, CAVM_CGXX_GMP_GMI_PRTX_CFG(
			cgx_id, lmac_id));

	/* Read PCS MISCS CTL */
	pcs_miscx_ctl.u = CSR_READ(node, CAVM_CGXX_GMP_PCS_MISCX_CTL(
				cgx_id, lmac_id));

	/* Use GMXENO to force the link down*/
	if (link->s.link_up) {
		pcs_miscx_ctl.s.gmxeno = 0;
		/* change the duplex setting if the link is up */
		prtx_cfg.s.duplex = 1;
	} else
		pcs_miscx_ctl.s.gmxeno = 1;

	/* speed based setting for GMP */
	txx_burst.s.burst = 0;

	switch (link->s.speed) {
	case CGX_LINK_10M:
		prtx_cfg.s.speed = 0;
		prtx_cfg.s.speed_msb = 1;
		prtx_cfg.s.slottime = 0;
		pcs_miscx_ctl.s.samp_pt = 50; /* sampling point */
		txx_slot.s.slot = 0x40;
		CSR_WRITE(node, CAVM_CGXX_GMP_GMI_TXX_SLOT(cgx_id, lmac_id),
						txx_slot.u);
		CSR_WRITE(node, CAVM_CGXX_GMP_GMI_TXX_BURST(cgx_id, lmac_id),
					txx_burst.u);
		break;
	case CGX_LINK_100M:
		prtx_cfg.s.speed = 0;
		prtx_cfg.s.speed_msb = 0;
		prtx_cfg.s.slottime = 0;
		pcs_miscx_ctl.s.samp_pt = 5; /* sampling point */
		txx_slot.s.slot = 0x40;
		CSR_WRITE(node, CAVM_CGXX_GMP_GMI_TXX_SLOT(cgx_id, lmac_id),
						txx_slot.u);
		CSR_WRITE(node, CAVM_CGXX_GMP_GMI_TXX_BURST(cgx_id, lmac_id),
					txx_burst.u);
		break;
	case CGX_LINK_1G:
		prtx_cfg.s.speed = 1;
		prtx_cfg.s.speed_msb = 0;
		prtx_cfg.s.slottime = 1;
		pcs_miscx_ctl.s.samp_pt = 1; /* sampling point */
		txx_slot.s.slot = 0x200;
		CSR_WRITE(node, CAVM_CGXX_GMP_GMI_TXX_SLOT(cgx_id, lmac_id),
						txx_slot.u);
		if (!link->s.full_duplex)
			txx_burst.s.burst = 0x2000;
		CSR_WRITE(node, CAVM_CGXX_GMP_GMI_TXX_BURST(cgx_id, lmac_id),
					txx_burst.u);
		break;
	default:
		break;
	}

	/* write back the new PCS misc and GMX settings */
	CSR_WRITE(node, CAVM_CGXX_GMP_PCS_MISCX_CTL(cgx_id, lmac_id),
				pcs_miscx_ctl.u);
	CSR_WRITE(node, CAVM_CGXX_GMP_GMI_PRTX_CFG(cgx_id, lmac_id),
						prtx_cfg.u);

	/* read back GMX CFG again to check config completion */
	prtx_cfg.u = CSR_READ(node,
			CAVM_CGXX_GMP_GMI_PRTX_CFG(cgx_id, lmac_id));

	/* enable Rx/Tx */
	cmr_config.u = CSR_READ(node, CAVM_CGXX_CMRX_CONFIG(
				cgx_id, lmac_id));
	cmr_config.s.data_pkt_rx_en = 1;
	cmr_config.s.data_pkt_tx_en = 1;
	CSR_WRITE(node, CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
				cmr_config.u);
	return 0;
}

static void cgx_set_autoneg(int node, int cgx_id, int lmac_id)
{
	cgx_lmac_config_t *lmac;
	cavm_cgxx_gmp_pcs_anx_adv_t pcs_anx_adv;
	cavm_cgxx_gmp_pcs_sgmx_an_adv_t sgmx_an_adv;
	cavm_cgxx_spux_an_adv_t spux_an_adv;

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	debug_cgx("%s: node=%d, cgx_id=%d, lmac_id=%d, mode=%d\n", __func__, node,
				cgx_id, lmac_id, lmac->mode);
	switch (lmac->mode) {
	case CAVM_CGX_LMAC_TYPES_E_SGMII:
	case CAVM_CGX_LMAC_TYPES_E_QSGMII:
		/* Write the Advertisement register to be used */
		if (lmac->sgmii_1000x_mode) { /* 1000 BASE-X mode */
			pcs_anx_adv.u = 0;
			pcs_anx_adv.s.rem_flt = 0; /* Link OK */
			/* both symmetric & asymmetric pause to local device */
			pcs_anx_adv.s.pause = 3;
			/* both half-duplex and full-duplex capable */
			pcs_anx_adv.s.hfd = 1;
			pcs_anx_adv.s.fd = 1;
			CSR_WRITE(node, CAVM_CGXX_GMP_PCS_ANX_ADV(
					cgx_id, lmac_id), pcs_anx_adv.u);
		} else { /* SGMII/QSGMII mode */
			if (lmac->phy_mode) {	/* PHY mode */
				sgmx_an_adv.u = 0;
				sgmx_an_adv.s.dup = 1; /* full duplex */
				sgmx_an_adv.s.speed = 1; /* 1000Mb/s */
				CSR_WRITE(node, CAVM_CGXX_GMP_PCS_SGMX_AN_ADV(
					cgx_id, lmac_id), sgmx_an_adv.u);
			} /* nothing to do in MAC mode */
		}

		/* Auto Neg Enable */
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_mrx_control_t,
			CAVM_CGXX_GMP_PCS_MRX_CONTROL(cgx_id, lmac_id),
			an_en, 1);
		break;
	case CAVM_CGX_LMAC_TYPES_E_TENG_R:
	case CAVM_CGX_LMAC_TYPES_E_FORTYG_R:
		/* configure AN only for KR interfaces */
		if (!lmac->use_training)
			break;
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_an_control_t,
				CAVM_CGXX_SPUX_AN_CONTROL(cgx_id, lmac_id),
				an_en, 1);

		/* program the negotiation parameters to be advertised */
		spux_an_adv.u = CSR_READ(node, CAVM_CGXX_SPUX_AN_ADV(
						cgx_id, lmac_id));
		/* disable extended next pages */
		spux_an_adv.s.xnp_able = 0;
		spux_an_adv.s.a40g_cr4 = 0;
		spux_an_adv.s.a10g_kx4 = 0;
		if (lmac->mode == CAVM_CGX_LMAC_TYPES_E_TENG_R)
			spux_an_adv.s.a10g_kr = 1;
		if (lmac->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R)
			spux_an_adv.s.a40g_kr4 = 1;
		CSR_WRITE(node, CAVM_CGXX_SPUX_AN_ADV(cgx_id, lmac_id),
				spux_an_adv.u);

		/* enable an_arb_link_chk_en if link training has to be
		 * performed. if not, clear this bit
		 */
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_an_control_t,
				CAVM_CGXX_SPUX_AN_CONTROL(cgx_id, lmac_id),
				an_arb_link_chk_en, lmac->use_training);
		break;
	/* FIXME: new modes to be supported */
	default:
		break;
	}
}

/* This function sets MAC/PHY mode.
 * Also 1000base-x/SGMII mode. Accordingly, programs the GMP timer
 */
static int cgx_sgmii_set_mode(int node, int cgx_id, int lmac_id)
{
	int timer_val = 0;
	cgx_lmac_config_t *lmac;
	cavm_cgxx_gmp_pcs_miscx_ctl_t pcs_miscx_ctl;
	cavm_cgxx_gmp_pcs_mrx_control_t pcs_mrx_ctl;

	lmac = &bfdt->cgx_cfg[lmac_id].lmac_cfg[lmac_id];

	debug_cgx("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	/* If phy is not present, force to 1G */
	if (!lmac->phy_present)	{
		pcs_mrx_ctl.u = CSR_READ(node, CAVM_CGXX_GMP_PCS_MRX_CONTROL(
						cgx_id, lmac_id));
		pcs_mrx_ctl.s.spdlsb = 0;
		pcs_mrx_ctl.s.spdmsb = 1;
		pcs_mrx_ctl.s.dup = 1;
		CSR_WRITE(node, CAVM_CGXX_GMP_PCS_MRX_CONTROL(
				cgx_id, lmac_id), pcs_mrx_ctl.u);
	}

	/* Adjust the MAC mode based on the info from DT */
	pcs_miscx_ctl.u = CSR_READ(node, CAVM_CGXX_GMP_PCS_MISCX_CTL(
					cgx_id, lmac_id));

	debug_cgx("%s phy mode %d 1000x-base mode %d\n", __func__,
			lmac->phy_mode, lmac->sgmii_1000x_mode);

	/* set to 1 for PHY mode. default is MAC mode */
	pcs_miscx_ctl.s.mac_phy = lmac->phy_mode;

	/* set to 1 for 1000base-x mode. default is SGMII/QSGMII mode */
	pcs_miscx_ctl.s.mode = lmac->sgmii_1000x_mode;

	CSR_WRITE(node, CAVM_CGXX_GMP_PCS_MISCX_CTL(cgx_id, lmac_id),
						pcs_miscx_ctl.u);

	/* Timer value should be 1.6 ms for SGMII/QSGMII and 10 ms for
	 * 1000 base-x mode
	 */
	if (pcs_miscx_ctl.s.mode) /* 1000 base-x mode */
		timer_val = 10000;
	else /* SGMII or QSGMII mode */
		timer_val = 1600; /* reset value */

	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_linkx_timer_t,
			CAVM_CGXX_GMP_PCS_LINKX_TIMER(cgx_id, lmac_id),
			count, timer_val);
	return 0;
}

/* This API brings up SGMII/QSGMII link. This function to be called
 * after the PHY is up (only when link is up).
 */
int cgx_sgmii_set_link_up(int node, int cgx_id, int lmac_id)
{
	cgx_lmac_config_t *lmac;
	cavm_cgxx_gmp_pcs_mrx_control_t pcs_mrx_ctl;

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	debug_cgx("%s: node=%d, cgx_id=%d, lmac_id=%d autoneg_dis=%d\n", __func__,
				node, cgx_id, lmac_id,
				lmac->autoneg_dis);

	/* set MAC/PHY/1000 base-x/SGMII mode */
	cgx_sgmii_set_mode(node, cgx_id, lmac_id);

	/* check if AN is enabled. If not enabled, just
	 * configure MRX_CONTROL CSR with default speed
	 */
	if (lmac->autoneg_dis) {
		pcs_mrx_ctl.s.an_en = 0;
		pcs_mrx_ctl.s.spdlsb = 0;
		pcs_mrx_ctl.s.spdmsb = 1;
		CSR_WRITE(node, CAVM_CGXX_GMP_PCS_MRX_CONTROL(
			cgx_id, lmac_id), pcs_mrx_ctl.u);
	} else	{ /* AN is desired. sequence from AN execution section(HRM) */
		/* enable LMAC */
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
			CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
			enable, 1);

		/* disable GMI */
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_miscx_ctl_t,
				CAVM_CGXX_GMP_PCS_MISCX_CTL(cgx_id, lmac_id),
				gmxeno, 1);

		cgx_set_autoneg(node, cgx_id, lmac_id);
	}

	/* Bring the PCS out of reset */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_mrx_control_t,
		CAVM_CGXX_GMP_PCS_MRX_CONTROL(cgx_id, lmac_id),
		reset, 1);

	/* Wait till reset done */
	if (cgx_poll_for_csr(node, CAVM_CGXX_GMP_PCS_MRX_CONTROL(cgx_id,
				lmac_id), CGX_GMP_PCS_RESET_MASK, 0)) {
		debug_cgx("%s: %d:%d PCS reset not completed\n",
				__func__, cgx_id, lmac_id);
		cgx_set_error_type(node, cgx_id, lmac_id,
				CGX_ERR_PCS_RESET_FAIL);
		return -1;
	}

	if (lmac->autoneg_dis) {
		/* enable LMAC */
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
			CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
			enable, 1);
	} else {
		/* If AN is enabled, reset AN and wait for AN to complete */
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_mrx_control_t,
			CAVM_CGXX_GMP_PCS_MRX_CONTROL(cgx_id, lmac_id),
			rst_an, 1);
		/* Note : check for AN_CPT only for SGMII */
		if (lmac->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) {
			if (cgx_poll_for_csr(node, CAVM_CGXX_GMP_PCS_MRX_STATUS(
				cgx_id, lmac_id), CGX_GMP_PCS_AN_CPT_MASK, 1)) {
				ERROR("%s: %d:%d SGMII AN not complete\n",
						__func__, cgx_id, lmac_id);
				cgx_set_error_type(node, cgx_id, lmac_id,
					CGX_ERR_AN_CPT_FAIL);
				return -1;
			}
		}
	}

	/* Normal operation - power up */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_mrx_control_t,
			CAVM_CGXX_GMP_PCS_MRX_CONTROL(cgx_id, lmac_id),
			pwr_dn, 0);
	return 0;
}

/* This API brings down the link, typically called
 * when user invokes ifconfig down
 */
int cgx_sgmii_set_link_down(int node, int cgx_id, int lmac_id)
{
	cavm_cgxx_cmrx_rx_fifo_len_t rx_fifo_len;
	cavm_cgxx_cmrx_tx_fifo_len_t tx_fifo_len;

	debug_cgx("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	/* Rx disable */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
			CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
			data_pkt_rx_en, 0);

	/* Wait until Rx buffer is empty and Tx path is Idle */
	do {
		rx_fifo_len.u = CSR_READ(node, CAVM_CGXX_CMRX_RX_FIFO_LEN(
				cgx_id, lmac_id));
		tx_fifo_len.u = CSR_READ(node, CAVM_CGXX_CMRX_TX_FIFO_LEN(
				cgx_id, lmac_id));
	} while ((rx_fifo_len.s.fifo_len > 0) &&
				(tx_fifo_len.s.lmac_idle != 1));

	/* Tx disable */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
			CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
			data_pkt_tx_en, 0);

	/* power down PCS */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_mrx_control_t,
			CAVM_CGXX_GMP_PCS_MRX_CONTROL(cgx_id, lmac_id),
			pwr_dn, 1);

	/* LMAC disable */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
		CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
		enable, 0);

	return 0;
}

int cgx_xaui_init_link(int node, int cgx_id, int lmac_id)
{
	cgx_lmac_config_t *lmac;
	cavm_cgxx_smux_tx_ctl_t smux_tx_ctl;

	debug_cgx("%s: %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	/* reset SPU */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_control1_t,
			CAVM_CGXX_SPUX_CONTROL1(cgx_id, lmac_id),
			reset, 1);

	if (cgx_poll_for_csr(node, CAVM_CGXX_SPUX_CONTROL1(cgx_id, lmac_id),
			CGX_SPUX_RESET_MASK, 0)) {
		ERROR("%s: %d:%d SPUX reset not complete\n",
				__func__, cgx_id, lmac_id);
		cgx_set_error_type(node, cgx_id, lmac_id,
				CGX_ERR_SPUX_RESET_FAIL);
		return -1;
	}

	/* disable LMAC */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
			CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
			enable, 0);

	/* low power enable */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_control1_t,
			CAVM_CGXX_SPUX_CONTROL1(cgx_id, lmac_id),
			lo_pwr, 1);

	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_misc_control_t,
			CAVM_CGXX_SPUX_MISC_CONTROL(cgx_id, lmac_id),
			rx_packet_dis, 1);

	/* clear all interrupts as number of them will occur
	 * during bring up of a link
	 */
	CSR_WRITE(node, CAVM_CGXX_SMUX_RX_INT(cgx_id, lmac_id), 0);
	CSR_WRITE(node, CAVM_CGXX_SMUX_TX_INT(cgx_id, lmac_id), 0);
	CSR_WRITE(node, CAVM_CGXX_SPUX_INT(cgx_id, lmac_id), 0);

	/* enable link training, if applicable */
	if (lmac->use_training) {
		/* FIXME : not mentioned in HRM. Is this HW errata?
		 * As per HRM, these registers will be cleared
		 * before start of the traning. Why to explicitly clear them?
		 */
		CSR_WRITE(node, CAVM_CGXX_SPUX_BR_PMD_LD_CUP(cgx_id, lmac_id),
					0);
		CSR_WRITE(node, CAVM_CGXX_SPUX_BR_PMD_LP_CUP(cgx_id, lmac_id),
					0);
		CSR_WRITE(node, CAVM_CGXX_SPUX_BR_PMD_LP_REP(cgx_id, lmac_id),
					0);
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_br_pmd_control_t,
			CAVM_CGXX_SPUX_BR_PMD_CONTROL(cgx_id, lmac_id),
			train_en, 1);
	}

	/* configure and enable AN, if AN is desired. AN
	 * to be enabled only for KR interfaces
	 */
	if (lmac->use_training)
		cgx_set_autoneg(node, cgx_id, lmac_id);
	else /* disable AN */
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_an_control_t,
				CAVM_CGXX_SPUX_AN_CONTROL(cgx_id, lmac_id),
				an_en, 0);

	/* keep the reset values for lane polarity. select deficit
	 * idle count mode and unidirectional enable/disable
	 */
	smux_tx_ctl.u = CSR_READ(node, CAVM_CGXX_SMUX_TX_CTL(cgx_id, lmac_id));
	smux_tx_ctl.s.dic_en = 1;
	smux_tx_ctl.s.uni_en = 0;
	CSR_WRITE(node, CAVM_CGXX_SMUX_TX_CTL(cgx_id, lmac_id),
			smux_tx_ctl.u);

	/* bringup the SMU/SPU, enable LMAC */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
			CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
			enable, 1);

	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_control1_t,
			CAVM_CGXX_SPUX_CONTROL1(cgx_id, lmac_id),
			lo_pwr, 0);

	return 0;
}

int cgx_xaui_set_link_up(int node, int cgx_id, int lmac_id)
{
	cgx_lmac_config_t *lmac;
	cavm_cgxx_spux_an_control_t spux_an_ctl;
	cavm_cgxx_spux_an_status_t spux_an_sts;
	cavm_cgxx_spux_int_t spux_int;
	cavm_cgxx_spux_status2_t spux_status2;
	cavm_cgxx_cmrx_config_t cmr_config;

	debug_cgx("%s: %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	/* check whether AN is complete, if AN is enabled */
	spux_an_ctl.u = CSR_READ(node, CAVM_CGXX_SPUX_AN_CONTROL(
					cgx_id, lmac_id));
	if (spux_an_ctl.s.an_en) {
		spux_an_sts.u = CSR_READ(node, CAVM_CGXX_SPUX_AN_STATUS(
				cgx_id, lmac_id));
		if (!spux_an_sts.s.an_complete) {
			/* If AN is not complete, restart AN */
			WARN("%s: %d:%d AN not complete : restarting\n",
				__func__, cgx_id, lmac_id);
			CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_an_control_t,
				CAVM_CGXX_SPUX_AN_CONTROL(cgx_id, lmac_id),
				an_restart, 1);
			cgx_set_error_type(node, cgx_id, lmac_id,
				CGX_ERR_AN_CPT_FAIL);
			return -1;
		}
	}

	if (lmac->use_training) {
		spux_int.u = CSR_READ(node, CAVM_CGXX_SPUX_INT(
				cgx_id, lmac_id));
		if (!spux_int.s.training_done) {
			WARN("%s: %d:%d training not complete: restarting\n",
				__func__, cgx_id, lmac_id);
			cgx_restart_training(node, cgx_id, lmac_id);
			cgx_set_error_type(node, cgx_id, lmac_id,
						CGX_ERR_TRAINING_FAIL);
			return -1;
		}
	} else {
		/* Perform RX EQU for non-KR interfaces and for the link
		 * speed >= 5Gbaud - XAUI/XLAUI/RXAUI/XFI.
		 * FIXME: might not be needed here. will happen
		 * one time during boot or during mode change
		 */
		debug_cgx("%s: RX EQU mode %d\n", __func__, lmac->mode);
		if (cgx_rx_equalization(node, cgx_id, lmac_id) == -1) {
			ERROR("%s: %d:%d RX EQU failed\n", __func__,
					cgx_id, lmac_id);
			cgx_set_error_type(node, cgx_id, lmac_id,
				CGX_ERR_RX_EQU_FAIL);
			return -1;
		}
	}

	/* bring the SPU out of reset */
	if (cgx_poll_for_csr(node, CAVM_CGXX_SPUX_CONTROL1(cgx_id, lmac_id),
			CGX_SPUX_RESET_MASK, 0)) {
		debug_cgx("%s: %d:%d SPUX reset not completed\n",
				__func__, cgx_id, lmac_id);
		cgx_set_error_type(node, cgx_id, lmac_id,
				CGX_ERR_SPUX_RESET_FAIL);
		return -1;
	}

	/* POLL for the status of the link by checking lane
	 * alignment/block lock
	 */
	if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_TENG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R)) {
		if (cgx_poll_for_csr(node, CAVM_CGXX_SPUX_BR_STATUS1(cgx_id,
				lmac_id), CGX_SPUX_BLK_LOCK_MASK, 1)) {
			debug_cgx("%s: %d:%d: SPUX BLK LOCK not completed\n",
					__func__, cgx_id, lmac_id);
			cgx_set_error_type(node, cgx_id, lmac_id,
					CGX_ERR_SPUX_BR_BLKLOCK_FAIL);
			return -1;
		}

	} else if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_XAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_RXAUI)) {
		if (cgx_poll_for_csr(node, CAVM_CGXX_SPUX_BX_STATUS(cgx_id,
				lmac_id), CGX_SPUX_RX_ALIGN_MASK, 1)) {
			debug_cgx("%s: %d:%d SPUX RX ALIGN not completed\n",
					__func__, cgx_id, lmac_id);
			cgx_set_error_type(node, cgx_id, lmac_id,
					CGX_ERR_SPUX_RX_ALIGN_FAIL);
			return -1;
		}
	}

	/* check the receive fault. latching high bit (stays
	 * set until write 1 to clear by SW
	 */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_status2_t,
		CAVM_CGXX_SPUX_STATUS2(cgx_id, lmac_id),
		rcvflt, 1);
	spux_status2.u = CSR_READ(node, CAVM_CGXX_SPUX_STATUS2(
					cgx_id, lmac_id));
	if (spux_status2.s.rcvflt) {
		if (lmac->use_training)
			cgx_restart_training(node, cgx_id, lmac_id);
		debug_cgx("%s: %d:%d Receive Fault, retry training\n",
			__func__, cgx_id, lmac_id);
		cgx_set_error_type(node, cgx_id, lmac_id,
					CGX_ERR_SPUX_RX_FAULT);
		return -1;
	}

	/* Wait for link to be OK and no faults */
	if (cgx_poll_for_csr(node, CAVM_CGXX_SMUX_RX_CTL(cgx_id, lmac_id),
				CGX_SMUX_RX_STATUS_MASK, 0)) {
		debug_cgx("%s: %d:%d SMUX RX Link not OK\n",
				__func__, cgx_id, lmac_id);
		cgx_set_error_type(node, cgx_id, lmac_id,
				CGX_ERR_SMUX_RX_LINK_NOT_OK);
		return -1;
	}

	/* Wait for SMU Tx to be idle */
	if (cgx_poll_for_csr(node, CAVM_CGXX_SMUX_CTRL(cgx_id, lmac_id),
				CGX_SMUX_TX_IDLE_MASK, 0)) {
		debug_cgx("%s: %d:%d SMUX Tx not Idle\n",
				__func__, cgx_id, lmac_id);
#if 0 /* temp for ASIM. these bits are not simulated */
		cgx_set_error_type(node, cgx_id, lmac_id, CGX_ERR_TX_NOT_IDLE);
		return -1;
#endif
	}
	/* Wait for SMU Rx to be idle */
	if (cgx_poll_for_csr(node, CAVM_CGXX_SMUX_CTRL(cgx_id, lmac_id),
				CGX_SMUX_RX_IDLE_MASK, 0)) {
		debug_cgx("%s: %d:%d SMUX Rx not Idle\n",
				__func__, cgx_id, lmac_id);
#if 0 /* temp for ASIM. these bits are not simulated */
		cgx_set_error_type(node, cgx_id, lmac_id, CGX_ERR_RX_NOT_IDLE);
		return -1;
#endif
	}
	/* check Recv Fault */
	spux_status2.u = CSR_READ(node, CAVM_CGXX_SPUX_STATUS2(
					cgx_id, lmac_id));
	if (spux_status2.s.rcvflt) {
		debug_cgx("%s: %d:%d Receive Fault\n",
				__func__, cgx_id, lmac_id);
		cgx_set_error_type(node, cgx_id, lmac_id,
					CGX_ERR_SPUX_RX_FAULT);
		return -1;
	}
	/* check receive link. latching high bit (stays
	 * set until write 1 to clear by SW
	 */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_status1_t,
		CAVM_CGXX_SPUX_STATUS1(cgx_id, lmac_id),
		rcv_lnk, 1);
	if (cgx_poll_for_csr(node, CAVM_CGXX_SPUX_STATUS1(cgx_id, lmac_id),
				CGX_SMUX_PCS_RCV_LINK_MASK, 1)) {
		debug_cgx("%s: %d:%d SPU receive link down\n",
				__func__, cgx_id, lmac_id);
		cgx_set_error_type(node, cgx_id, lmac_id,
				CGX_ERR_PCS_RECV_LINK_FAIL);
		return -1;
	}

	/* FIXME: Clear out CGX error counters/bits */

	/* enable Data Tx/Rx */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_misc_control_t,
			CAVM_CGXX_SPUX_MISC_CONTROL(cgx_id, lmac_id),
			rx_packet_dis, 0);

	cmr_config.u = CSR_READ(node, CAVM_CGXX_CMRX_CONFIG(
				cgx_id, lmac_id));
	cmr_config.s.data_pkt_rx_en = 1;
	cmr_config.s.data_pkt_tx_en = 1;
	CSR_WRITE(node, CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
				cmr_config.u);
	return 0;
}

int cgx_xaui_get_link(int node, int cgx_id, int lmac_id,
		link_state_t *result)
{
	cgx_lmac_config_t *lmac;
	cavm_cgxx_spux_status1_t spux_status1;
	cavm_cgxx_smux_tx_ctl_t smux_tx_ctl;
	cavm_cgxx_smux_rx_ctl_t	smux_rx_ctl;

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	spux_status1.u = CSR_READ(node, CAVM_CGXX_SPUX_STATUS1(
					cgx_id, lmac_id));
	smux_tx_ctl.u = CSR_READ(node, CAVM_CGXX_SMUX_TX_CTL(
					cgx_id, lmac_id));
	smux_rx_ctl.u = CSR_READ(node, CAVM_CGXX_SMUX_RX_CTL(
					cgx_id, lmac_id));
	if ((smux_tx_ctl.s.ls == 0) && (smux_rx_ctl.s.status ==
			0) && (spux_status1.s.rcv_lnk)) {
		/* link is up */
		result->s.link_up = 1;
		result->s.full_duplex = 1;
		/* FIXME: get the clock info from GSERN for the
		 * particular lane for the mapped QLM/DLM and
		 * multiply by the number of lanes required
		 * for the mode. Wait for HRM.
		 * For now, return the default speed
		 */
		if (lmac->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R)
			result->s.speed = CGX_LINK_40G;
		else
			result->s.speed = CGX_LINK_10G;
	} else {
		/* link is down */
		result->s.link_up = 0;
		result->s.full_duplex = 0;
		result->s.speed = 0;
	}
	return 0;
}

int cgx_xaui_set_link_down(int node, int cgx_id, int lmac_id)
{
	cavm_cgxx_cmrx_rx_fifo_len_t rx_fifo_len;
	cavm_cgxx_cmrx_tx_fifo_len_t tx_fifo_len;

	debug_cgx("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	/* Rx disable */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
			CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
			data_pkt_rx_en, 0);

	/* Wait until Rx buffer is empty and Tx path is Idle */
	do {
		rx_fifo_len.u = CSR_READ(node, CAVM_CGXX_CMRX_RX_FIFO_LEN(
				cgx_id, lmac_id));
		tx_fifo_len.u = CSR_READ(node, CAVM_CGXX_CMRX_TX_FIFO_LEN(
				cgx_id, lmac_id));
	} while ((rx_fifo_len.s.fifo_len > 0) &&
				(tx_fifo_len.s.lmac_idle != 1));

	/* Tx disable */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
			CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
			data_pkt_tx_en, 0);

	/* FIXME: if flow control is enabled, disable appropriate
	 * flow control packets
	 */

	/* disable SerDes lane */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_control1_t,
			CAVM_CGXX_SPUX_CONTROL1(cgx_id, lmac_id),
			lo_pwr, 1);

	/* LMAC disable */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_config_t,
		CAVM_CGXX_CMRX_CONFIG(cgx_id, lmac_id),
		enable, 0);

	return 0;
}

/* FIXME : Waiting for GSERN HRM */
int cgx_rx_equalization(int node, int cgx_id, int lmac_id)
{
	debug_cgx("%s: %d:%d:%d\n", __func__, node, cgx_id, lmac_id);
	return 0;
}

void cgx_set_internal_loopback(int node, int cgx_id, int lmac_id, int enable)
{
	cgx_lmac_config_t *lmac;

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	debug_cgx("%s: %d:%d:%d mode %d enable %d\n", __func__, node, cgx_id,
				lmac_id, lmac->mode, enable);

	if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) || (lmac->mode ==
			CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_mrx_control_t,
			CAVM_CGXX_GMP_PCS_MRX_CONTROL(cgx_id, lmac_id),
			loopbck1, enable);
	} else if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_XAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_RXAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_TENG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R)) {
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_spux_control1_t,
			CAVM_CGXX_SPUX_CONTROL1(cgx_id, lmac_id),
			loopbck, enable);
	}
}

void cgx_set_external_loopback(int node, int cgx_id, int lmac_id, int enable)
{
	cgx_lmac_config_t *lmac;

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	debug_cgx("%s: %d:%d:%d mode %d enable %d\n", __func__, node, cgx_id,
				lmac_id, lmac->mode, enable);

	if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) || (lmac->mode ==
			CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_gmp_pcs_miscx_ctl_t,
				CAVM_CGXX_GMP_PCS_MISCX_CTL(cgx_id, lmac_id),
				loopbck2, enable);
	} else if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_XAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_RXAUI) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_TENG_R) ||
		(lmac->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R)) {
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_smux_ext_loopback_t,
			CAVM_CGXX_SMUX_EXT_LOOPBACK(cgx_id, lmac_id),
			en, enable);
	}
}

/* this function to be called for every CGX from
 * PCI scanning (CGX device enumeration)
 */
void cgx_hw_init(int node, int cgx_id)
{
	int lmac_id;
	cgx_config_t *cgx;

	debug_cgx("%s: %d:%d\n", __func__, node, cgx_id);

	cgx = &bfdt->cgx_cfg[cgx_id];

	/* Retrieve the LMAC config from bfdt structure and loop
	 * through them for lmac_count times and program the HW
	 * for each LMAC
	 */
	for (lmac_id = 0; lmac_id < MAX_LMAC_PER_CGX; lmac_id++) {
		if (cgx->lmac_cfg[lmac_id].lmac_enable)
			cgx_lmac_init(node, cgx_id, lmac_id);
		else
			debug_cgx("%s LMAC%d not enabled\n", __func__, lmac_id);

		/* FIXME: enable CMR INT for testing */
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_int_ena_w1s_t,
				CAVM_CGXX_CMRX_INT_ENA_W1S(cgx_id, lmac_id),
				overflw, 1);
	}

	/* program the LMAC count (already updated by FDT parser)
	 * for each CGX
	 */
	debug_cgx("%s lmac_count %d\n", __func__, cgx->lmac_count);

	CSR_WRITE(node, CAVM_CGXX_CMR_TX_LMACS(cgx_id),
				cgx->lmac_count);
	CSR_WRITE(node, CAVM_CGXX_CMR_RX_LMACS(cgx_id),
				cgx->lmac_count);

	/* FCS setting */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmr_global_config_t,
		CAVM_CGXX_CMR_GLOBAL_CONFIG(cgx_id), fcs_strip, 1);

	/* Set the backpressure and mask */
	for (lmac_id = 0; lmac_id < cgx->lmac_count; lmac_id++) {
		CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmr_chan_msk_and_t,
					CAVM_CGXX_CMR_CHAN_MSK_AND(cgx_id),
					msk_and,
					((1ull << MAX_CHAN_PER_LMAC) - 1) <<
					(lmac_id * MAX_CHAN_PER_LMAC));
	}
}

