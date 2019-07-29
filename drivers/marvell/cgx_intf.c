/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/* CGX driver for OcteonTX2 */

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <string.h>
#include <platform_def.h>
#include <timers.h>
#include <octeontx_common.h>
#include <delay_timer.h>
#include <plat_board_cfg.h>
#include <cgx_intf.h>
#include <cgx.h>
#include <plat_scfg.h>
#include <sh_fwdata.h>

#ifdef NT_FW_CONFIG
#include <plat_npc_mcam_profile.h>
#endif

/* define DEBUG_ATF_CGX_INTF to enable debug logs */
#undef DEBUG_ATF_CGX_INTF

#ifdef DEBUG_ATF_CGX_INTF
#define debug_cgx_intf printf
#else
#define debug_cgx_intf(...) ((void) (0))
#endif

#define MAX_CGX_TIMERS 2

static int cgx_timers[MAX_CGX_TIMERS];

static cgx_lmac_context_t
		lmac_context[MAX_CGX][MAX_LMAC_PER_CGX];

static int cgx_get_error_type(int cgx_id, int lmac_id)
{
	cgx_lmac_context_t *lmac_ctx;

	lmac_ctx = &lmac_context[cgx_id][lmac_id];
	return lmac_ctx->s.error_type;
}

static int cgx_trigger_interrupt(int cgx_id, int lmac_id)
{
	debug_cgx_intf("%s %d:%d\n", __func__, cgx_id, lmac_id);

	/* Enable the interrupt bit each time before triggering
	 * an interrupt. In case of Link down request, enable bit for
	 * LMAC(CGXX_CMRX_CONFIG(enable)) is disabled
	 * which clears all the dedicated CGX context
	 * state for the LMAC. Hence, need to explicitly enable
	 * the interrupt every time.
	 */
	CAVM_MODIFY_CGX_CSR(cavm_cgxx_cmrx_int_ena_w1s_t,
				CAVM_CGXX_CMRX_INT_ENA_W1S(cgx_id, lmac_id),
				overflw, 1);

	/* FIXME: trigger an interrupt to kernel
	 * via CMRX overflow int bit - Hardware-opaque vector
	 * for software driver (37th MSIX vector) doesn't have interrupt
	 * support yet. this is a workaround for the 1st pass
	 */
	CAVM_MODIFY_CGX_CSR(cavm_cgxx_cmrx_int_w1s_t,
				CAVM_CGXX_CMRX_INT_W1S(cgx_id, lmac_id),
				overflw, 1);
	return 0;
}

static int cgx_acquire_csr_lock(int cgx_id, int lmac_id)
{
	int timeout = 10; /* loop for few times but not infinitely */
	cgx_lmac_context_t *lmac_ctx;

	lmac_ctx = &lmac_context[cgx_id][lmac_id];

	do {
		if (!lmac_ctx->s.lock) {
			lmac_ctx->s.lock = 1;
			return 0;
		}
		udelay(1);
	} while (timeout--);

	return -1;
}

static void cgx_release_csr_lock(int cgx_id, int lmac_id)
{
	lmac_context[cgx_id][lmac_id].s.lock = 0;
}

static void cgx_release_own_status(int cgx_id, int lmac_id)
{
	CAVM_MODIFY_CGX_CSR(union cgx_scratchx1,
			CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 1),
			own_status, CGX_OWN_NON_SECURE_SW); /* released the ownership */
}

static int cgx_sfp_obtain_capabilities(int cgx_id, int lmac_id)
{
	int trans_type;

	/* Read the EEPROM to determine new module capabilities */
	trans_type = sfp_parse_eeprom_data(cgx_id, lmac_id);

	if (trans_type != SFP_TRANS_TYPE_NONE) {
		/* If Valid transceiver found */
		debug_cgx_intf("%s: %d:%d trans_type %d\n",
				__func__, cgx_id, lmac_id,
				trans_type);
		return sfp_validate_user_options(cgx_id, lmac_id);
	}

	debug_cgx_intf("%s: %d:%d Valid transceiver not identified\n",
		__func__, cgx_id, lmac_id);
	cgx_set_error_type(cgx_id, lmac_id, CGX_ERR_MODULE_INVALID);
	return 0;
}

static void cgx_set_link_state(int cgx_id, int lmac_id,
					link_state_t *link, int err_type)
{
	union cgx_scratchx0 scratchx0;

	debug_cgx_intf("%s %d:%d link_up %d speed %d duplex %d\t"
			"err_type %d fec %d\n",
			__func__, cgx_id, lmac_id,
			link->s.link_up, link->s.speed,
			link->s.full_duplex, err_type,
			link->s.fec);

	scratchx0.u = CSR_READ(CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 0));
	scratchx0.s.link_sts.link_up = link->s.link_up;
	scratchx0.s.link_sts.speed = link->s.speed;
	scratchx0.s.link_sts.full_duplex = link->s.full_duplex;
	scratchx0.s.link_sts.err_type = err_type;
	scratchx0.s.link_sts.fec = link->s.fec;
	CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 0), scratchx0.u);

	/* Update supported FEC to SM when updating link status */
	sh_fwdata_update_supported_fec(cgx_id, lmac_id);
}

static int cgx_link_change_req(int cgx_id, int lmac_id)

{
	int ret = 0, err_type = 0;
	union cgx_scratchx0 scratchx0;
	link_state_t link;
	cgx_lmac_config_t *lmac_cfg;
	cgx_lmac_context_t *lmac_ctx;

	/* get the lmac type and based on lmac
	 * type, change the link settings
	 */
	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	lmac_ctx = &lmac_context[cgx_id][lmac_id];

	debug_cgx_intf("%s %d:%d lmac_type %d\n", __func__, cgx_id,
			lmac_id, lmac_cfg->mode);

	/* In case of link change from down -> up, do the necessary
	 * HW configuration to initialize the link again. For >=10G interfaces,
	 * if the link is down, set up link is already called once. If the link
	 * has changed from up -> down, just update the status. no HW
	 * re-configuration is required.
	 */
	link.s.link_up = lmac_ctx->s.link_up;
	link.s.speed = lmac_ctx->s.speed;
	link.s.full_duplex = lmac_ctx->s.full_duplex;
	link.s.fec = lmac_ctx->s.fec;

	/* clear the previous errors before changing the link */
	cgx_set_error_type(cgx_id, lmac_id, 0);

	if (link.s.link_up) {
		if ((lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) ||
			(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII))
			ret = cgx_sgmii_set_link_speed(cgx_id, lmac_id, &link);
	}

	if (ret == -1) {
		err_type = cgx_get_error_type(cgx_id, lmac_id);
		debug_cgx_intf("%s: %d:%d CGX error %d\n", __func__,
					cgx_id, lmac_id, err_type);
	}

	/* update the current link status along with any error type set */
	cgx_set_link_state(cgx_id, lmac_id, &link, err_type);

	lmac_ctx->s.link_up = link.s.link_up;
	lmac_ctx->s.full_duplex = link.s.full_duplex;
	lmac_ctx->s.speed = link.s.speed;

	/* update the event status to evt_sts struct to notify kernel */
	scratchx0.u = CSR_READ(CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 0));
	if (err_type & CGX_ERR_MASK)
		scratchx0.s.evt_sts.stat = CGX_STAT_FAIL;
	else
		scratchx0.s.evt_sts.stat = CGX_STAT_SUCCESS;

	scratchx0.s.evt_sts.id = CGX_EVT_LINK_CHANGE;
	scratchx0.s.evt_sts.evt_type = CGX_EVT_ASYNC;
	scratchx0.s.evt_sts.ack = 1; /* set ack */
	CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 0), scratchx0.u);

	/* clear the link_change_req after handling it */
	lmac_ctx->s.link_change_req = 0;

	if (link.s.link_up) {
		lmac_ctx->s.link_req = 0;
		lmac_ctx->s.link_enable = 1;
	}
	return ret;
}

static int cgx_link_bringup(int cgx_id, int lmac_id)
{
	int mod_status = 0;
	int sfp_count = 0;
	int trans_type = 0;
	int valid;
	cgx_lmac_config_t *lmac_cfg;
	cgx_lmac_context_t *lmac_ctx;
	link_state_t link;
	int count = 0, count1 = 0;

	/* get the lmac type and based on lmac
	 * type, initialize SGMII/XAUI link
	 */
	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	debug_cgx_intf("%s %d:%d lmac_type %d\n", __func__, cgx_id,
			lmac_id, lmac_cfg->mode);

	lmac_ctx = &lmac_context[cgx_id][lmac_id];
	link.u64 = 0;

	/* link_enable will be set when the LINK UP req is processed.
	 * To avoid processing duplication of requests, check for it
	 * and return the previous link status
	 */
	if (lmac_ctx->s.link_enable == 1) {
		debug_cgx_intf("%s: Link status for %d:%d is already up\n",
			__func__, cgx_id, lmac_id);
		link.s.link_up = lmac_ctx->s.link_up;
		link.s.full_duplex = lmac_ctx->s.full_duplex;
		link.s.speed = lmac_ctx->s.speed;
		link.s.fec = lmac_ctx->s.fec;
		cgx_set_link_state(cgx_id, lmac_id, &link,
			cgx_get_error_type(cgx_id, lmac_id));
		return 0;
	}

	if (!lmac_ctx->s.init_link) {
		cgx_lmac_init_link(cgx_id, lmac_id);
		lmac_ctx->s.init_link = 1;
	}

	/* Save the current FEC what is configured by the user */
	link.s.fec = lmac_ctx->s.fec = lmac_cfg->fec;

	if ((lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
		/* sequence if PHY is present:
		 *	- get PHY status,
		 *	- If link is up, init link and set speed
		 *	- If link is not up, return error
		 * sequence if PHY is not present(same when
		 * 			internal lbk enabled/PHY mode):
		 *	- assign default link status,
		 *	- init link and set speed
		 */
		if ((lmac_ctx->s.lbk1_enable) || (!lmac_cfg->phy_present) ||
				(lmac_cfg->phy_mode)) {
			link.s.link_up = 1;
			link.s.full_duplex = 1;
			link.s.speed = CGX_LINK_1G;
		} else {
			/* Get the link status */
			phy_get_link_status(cgx_id, lmac_id, &link);
		}

		if (link.s.link_up == 1) {	/* PHY link is up */
			/* Check for AN complete */
			if (cgx_sgmii_check_link(cgx_id, lmac_id) != 0) {
				link.s.link_up = 0;
				link.s.full_duplex = 0;
				link.s.speed = CGX_LINK_NONE;
				goto cgx_err;	/* Poll timer to retry */
			}

			/* Set up the link for the negotiated speed */
			if (cgx_sgmii_set_link_speed(cgx_id, lmac_id, &link) != 0)
				goto cgx_err;

			/* SUCCESS case : update the link status and indicate
			 * poll timer to start polling for the link
			 */
			lmac_ctx->s.link_up = link.s.link_up;
			lmac_ctx->s.full_duplex = link.s.full_duplex;
			lmac_ctx->s.speed = link.s.speed;
			lmac_ctx->s.link_enable = 1;
			cgx_set_link_state(cgx_id, lmac_id, &link, 0);

			return 0;

		} else {
			/* if the link is not up, return success with
			 * LINK as down
			 */
			debug_cgx_intf("%s : %d:%d PHY link status is down\n",
				__func__, cgx_id, lmac_id);
			goto cgx_err; /* To poll for the link again */
		}
	} else if ((lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_XAUI) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_RXAUI) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_TENG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_FIFTYG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_USXGMII)) {

		if (lmac_cfg->sfp_slot == 1) {
retry_mod_stat:
			/* Obtain SFP module status */
			mod_status = sfp_get_mod_status(cgx_id, lmac_id);
			if ((mod_status == SFP_MOD_STATE_PRESENT) ||
				(mod_status == SFP_MOD_STATE_EEPROM_UPDATED)) {
				/* Read EEPROM to determine module capability */
				trans_type = sfp_parse_eeprom_data(cgx_id,
								lmac_id);
				if (trans_type == SFP_TRANS_TYPE_NONE) {
					cgx_set_error_type(cgx_id, lmac_id,
						CGX_ERR_MODULE_INVALID);
					/* set link_req to 1 to indicate
					 * poll timer
					 */
					lmac_ctx->s.link_req = 1;
					return -1;
				}
				/* Save the new mod status */
				lmac_ctx->s.mod_stats = mod_status;

				valid = sfp_validate_user_options(cgx_id,
								lmac_id);
				if (valid == 1) {
					debug_cgx_intf("%s: %d:%d\t"
					"trans_type %d\n",
					__func__, cgx_id, lmac_id,
					trans_type);
				} else {
					ERROR("%s: %d:%d User config\t"
						"doesn't match EEPROM\n",
						__func__, cgx_id, lmac_id);
						lmac_ctx->s.link_req = 1;
					return -1;
				}
			} else {
				if (sfp_count++ < 5) {
					mdelay(1);
					goto retry_mod_stat;
				}

				debug_cgx_intf("%s: %d:%d Module not present\n",
					__func__, cgx_id, lmac_id);
				lmac_ctx->s.link_req = 1;
				cgx_set_error_type(cgx_id, lmac_id,
						CGX_ERR_MODULE_NOT_PRESENT);
				return -1;
			}
		}
retry_link:
		if (lmac_cfg->phy_present) {
			/* Get the link status */
			phy_get_link_status(cgx_id, lmac_id, &link);

			if (!link.s.link_up) {
				if (count++ < 5)
					goto retry_link;

				debug_cgx_intf("%s:%d:%d link status is down\n",
					__func__, cgx_id, lmac_id);
				/* PHY link is down */
				link.s.link_up = 0;
				link.s.full_duplex = 0;
				link.s.speed = CGX_LINK_NONE;
				count = 0; /* reset the counter */
				goto cgx_err; /* To poll for the link */
			}
			cgx_set_link_state(cgx_id, lmac_id, &link, 0);
		}

		if (cgx_xaui_set_link_up(cgx_id, lmac_id) == -1) {
			/* if init link fails, retry */
			if (count++ < 5) {
				debug_cgx_intf("%s: %d:%d Init failed,\t"
					"retrying link\n", __func__,
					cgx_id, lmac_id);
				/* clear the error when retrying */
				cgx_set_error_type(cgx_id, lmac_id, 0);
				goto retry_link;
			}
		}

		if (cgx_xaui_get_link(cgx_id, lmac_id, &link) == -1) {
			/* if link is not up, retry */
			if (count1++ < 5) {
				debug_cgx_intf("%s %d:%d Link down,\t"
					"retrying link\n", __func__,
					cgx_id, lmac_id);
				/* clear the error when retrying */
				cgx_set_error_type(cgx_id, lmac_id, 0);
				goto retry_link;
			}
		}
		if (link.s.link_up == 1) {	/* link is up */
			if (cgx_get_error_type(cgx_id, lmac_id) &
						CGX_ERR_MASK)
				goto cgx_err;
			/* SUCCESS case : update the link status and indicate
			 * poll timer to start polling for link
			 */
			lmac_ctx->s.link_up = link.s.link_up;
			lmac_ctx->s.full_duplex = link.s.full_duplex;
			lmac_ctx->s.speed = link.s.speed;
			lmac_ctx->s.link_enable = 1;
			cgx_set_link_state(cgx_id, lmac_id, &link, 0);
			return 0;
		} else {
			/* link is down */
			debug_cgx_intf("%s: %d:%d link status is down\n",
				__func__, cgx_id, lmac_id);
			goto cgx_err; /* Poll timer to poll for the link */
		}
	} else {
		debug_cgx_intf("%s %d:%d mode %d not configured correctly,"
			" cannot initialize link\n",
			__func__, cgx_id, lmac_id, lmac_cfg->mode);
		cgx_set_error_type(cgx_id, lmac_id,
			CGX_ERR_LMAC_MODE_INVALID);
		return -1;
	}

cgx_err:
	/* If the link is up/down, or the CGX configuration failed, reach here
	 * In that case, update the link status along with the error type
	 * in lmac_context structure and the SCRATCHX CSRs and notify
	 * poll timer to start polling for the link
	 */
	lmac_ctx->s.link_up = link.s.link_up;
	lmac_ctx->s.full_duplex = link.s.full_duplex;
	lmac_ctx->s.speed = link.s.speed;
	cgx_set_link_state(cgx_id, lmac_id, &link,
			cgx_get_error_type(cgx_id, lmac_id));

	lmac_ctx->s.link_enable = 1;

	return -1;
}

static int cgx_link_bringdown(int cgx_id, int lmac_id)
{
	cgx_lmac_config_t *lmac_cfg;
	cgx_lmac_context_t *lmac_ctx;
	link_state_t link;

	/* get the lmac type and based on lmac
	 * type, bring down SGMII/XAUI link
	 */
	lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	debug_cgx_intf("%s %d:%d lmac_type %d\n", __func__,
				cgx_id, lmac_id, lmac_cfg->mode);

	lmac_ctx = &lmac_context[cgx_id][lmac_id];

	/* link_enable will be cleared when the LINK DOWN req is processed
	 * To avoid processing duplication of requests, check for it
	 * and return the previous link status.
	 * In case of QSGMII, always bring down the link even
	 * if the link was not brought up
	 */
	if ((lmac_ctx->s.link_enable == 0) && (lmac_cfg->mode !=
				CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
		debug_cgx_intf("%s: Link status for %d:%d is already down\n",
			__func__, cgx_id, lmac_id);
		link.s.link_up = lmac_ctx->s.link_up;
		link.s.full_duplex = lmac_ctx->s.full_duplex;
		link.s.speed = lmac_ctx->s.speed;
		cgx_set_link_state(cgx_id, lmac_id, &link,
			cgx_get_error_type(cgx_id, lmac_id));
		return 0;
	}

	if ((lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
		if (cgx_sgmii_set_link_down(cgx_id, lmac_id) != 0)
			return -1;

	} else if ((lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_XAUI) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_RXAUI) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_TENG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_TWENTYFIVEG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_FORTYG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_FIFTYG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_HUNDREDG_R) ||
		(lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_USXGMII)) {
		if (cgx_xaui_set_link_down(cgx_id, lmac_id) != 0)
			return -1;

	} else {
		debug_cgx_intf("%s LMAC%d mode %d not configured correctly"
			" cannot bring down the link\n",
			__func__, lmac_id, lmac_cfg->mode);
		cgx_set_error_type(cgx_id, lmac_id,
			CGX_ERR_LMAC_MODE_INVALID);
		return -1;
	}

	/* link is brought down successfully. update the link
	 * status and indicate poll timer to stop polling
	 * for the link
	 */
	lmac_ctx->s.link_up = link.s.link_up = 0;
	lmac_ctx->s.full_duplex = link.s.full_duplex = 0;
	lmac_ctx->s.speed = link.s.speed = 0;
	cgx_set_link_state(cgx_id, lmac_id, &link,
			cgx_get_error_type(cgx_id, lmac_id));

	lmac_ctx->s.link_enable = 0;
	lmac_ctx->s.init_link = 0;

	return 0;
}

int cgx_set_fec_type(int cgx_id, int lmac_id, int req_fec)
{
	int ret = 0;
	link_state_t link;
	cgx_lmac_config_t *lmac;
	cgx_lmac_context_t *lmac_ctx;

	lmac_ctx = &lmac_context[cgx_id][lmac_id];
	lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	debug_cgx_intf("%s: %d:%d fec %d request_fec %d\n", __func__, cgx_id,
				lmac_id, lmac->fec, req_fec);

	if ((lmac->mode == CAVM_CGX_LMAC_TYPES_E_SGMII) ||
			(lmac->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII)) {
		ERROR("%s: %d: %d FEC is not applicable for this mode %d\n",
				__func__, cgx_id, lmac_id, lmac->mode);
		cgx_set_error_type(cgx_id, lmac_id, CGX_ERR_SET_FEC_INVALID);
		return -1;
	}

	/* FIXME: FEC change is not implemented yet for modes with AN/LT
	 * hence return error for these modes
	 */
	if (!lmac->autoneg_dis && lmac->use_training) {
		ERROR("%s: %d:%d FEC change is not supported for this mode\n",
			__func__, cgx_id, lmac_id);
		cgx_set_error_type(cgx_id, lmac_id, CGX_ERR_SET_FEC_INVALID);
		return -1;
	}

	if (req_fec == lmac->fec) {
		WARN("%s: %d:%d FEC requested is same as current FEC state\n",
				__func__, cgx_id, lmac_id);
		return 0;
	}

	/* Validate FEC based on LMAC mode */
	ret = cgx_validate_fec_config(lmac->mode, req_fec);
	if (ret == -1) {
		cgx_set_error_type(cgx_id, lmac_id, CGX_ERR_SET_FEC_INVALID);
		return -1;
	}

	/* FIXME: Validate FEC based on transceiver */

	/* Update the new FEC requested by user in the board config */
	lmac->fec = req_fec;

	/* Configure PHY to new mode based on FEC requested
	 * if PHY is present
	 */
	if ((lmac->phy_present) && (lmac->phy_config.init)) {
		phy_config(cgx_id, lmac_id);
		mdelay(1);
	}

	/* Change CGX configuration to new FEC */
	ret = cgx_fec_change(cgx_id, lmac_id, req_fec);
	if (ret == -1) {
		ERROR("%s: FEC type could not be changed\n", __func__);
		cgx_set_error_type(cgx_id, lmac_id, CGX_ERR_SET_FEC_FAIL);
		return -1;
	}

	/* Just update the new FEC type but use the existing link status */
	link.s.fec = lmac_ctx->s.fec = req_fec;
	link.s.link_up = lmac_ctx->s.link_up;
	link.s.full_duplex = lmac_ctx->s.full_duplex;
	link.s.speed = lmac_ctx->s.speed;

	cgx_set_link_state(cgx_id, lmac_id, &link,
			cgx_get_error_type(cgx_id, lmac_id));

	return 0;
}

static int cgx_set_phy_mod_type(int cgx_id, int lmac_id, int phy_mod_type)
{
	cgx_lmac_config_t *lmac;

	lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	if (lmac->phy_present && lmac->phy_config.init &&
	    lmac->phy_config.valid) {
		if (!phy_set_mod_type(cgx_id, lmac_id, phy_mod_type)) {
			if (cgx_update_flash_phy_mod_param(cgx_id,
							   lmac_id,
							   phy_mod_type)) {
				debug_cgx_intf("Flash update phymod failed\n");
				return -1;
			}
		}
	} else {
		debug_cgx_intf("phy not present for SET_PHY_MOD\n");
		return -1;
	}
	return 0;
}

/* Note : this function executes with lock acquired */
static int cgx_process_requests(int cgx_id, int lmac_id)
{
	int ret = 0, val = 0;
	int enable = 0; /* read from scratch1 - cmd_args */
	int request_id = 0, err_type = 0, req_fec, phy_mod_type;
	union cgx_scratchx0 scratchx0;
	union cgx_scratchx1 scratchx1;
	link_state_t link;
	cgx_lmac_context_t *lmac_ctx;
	cgx_lmac_config_t *lmac;

	lmac = &plat_octeontx_bcfg->cgx_cfg[cgx_id].lmac_cfg[lmac_id];
	lmac_ctx = &lmac_context[cgx_id][lmac_id];

	/* Read the command arguments from SCRATCHX(1) */
	scratchx1.u = CSR_READ(CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 1));
	request_id = scratchx1.s.cmd.id;
	enable = scratchx1.s.cmd_args.enable;
	debug_cgx_intf("%s: %d:%d request_id %d\n", __func__, cgx_id,
				lmac_id, request_id);

	/* always reset the error bits when processing new
	 * command except when obtaining current status
	 */
	if (request_id != CGX_CMD_GET_LINK_STS)
		cgx_set_error_type(cgx_id, lmac_id, 0);

	/* some of the commands like below should be handled independent
	 * of whether LMAC is enabled or not
	 */
	if ((request_id == CGX_CMD_INTF_SHUTDOWN) ||
#ifdef NT_FW_CONFIG
		(request_id == CGX_CMD_GET_MKEX_SIZE) ||
		(request_id == CGX_CMD_GET_MKEX_PROFILE) ||
#endif
		(request_id == CGX_CMD_GET_FWD_BASE) ||
		(request_id == CGX_CMD_GET_FW_VER)) {
		switch (request_id) {
		case CGX_CMD_INTF_SHUTDOWN:
			cgx_fw_intf_shutdown();
			/* in case of shutdown, clear all other
			 * bits and set only ack bit to indicate
			 * to user request is processed (this bit
			 * will be cleared by user)
			 */
			scratchx0.u = 0;
			scratchx0.s.evt_sts.ack = 1; /* set ack */
			CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
				cgx_id, lmac_id, 0), scratchx0.u);
			return 0;
		case CGX_CMD_GET_FW_VER:
			scratchx0.u = 0;
			scratchx0.s.ver.major_ver = CGX_FIRMWARE_MAJOR_VER;
			scratchx0.s.ver.minor_ver = CGX_FIRMWARE_MINOR_VER;
			CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
				cgx_id, lmac_id, 0), scratchx0.u);
			break;
#ifdef NT_FW_CONFIG
		case CGX_CMD_GET_MKEX_PROFILE:
			scratchx0.u = 0;
			scratchx0.s.prfl_addr.mcam_addr = otx2_get_npc_profile_addr(0);
			CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
				cgx_id, lmac_id, 0), scratchx0.u);

			debug_cgx_intf("%s: MKEX_PROFILE %u\n", __func__,
				(unsigned int)scratchx0.s.prfl_addr.mcam_addr);
			break;

		case CGX_CMD_GET_MKEX_SIZE:
			scratchx0.u = 0;
			scratchx0.s.prfl_sz.mcam_sz = otx2_get_npc_profile_size(0);
			CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
				cgx_id, lmac_id, 0), scratchx0.u);

			debug_cgx_intf("%s: MKEX_SIZE %u\n", __func__,
				(unsigned int)scratchx0.s.prfl_sz.mcam_sz);
			break;
#endif
		case CGX_CMD_GET_FWD_BASE:
			scratchx0.u = 0;
			scratchx0.s.fwd_base_s.addr = get_sh_fwdata_base();
			CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 0),
				scratchx0.u);
			break;
		}
	} else {
		/* all the below commands should be processed only
		 * when LMAC is enabled
		 */
		if (lmac->lmac_enable) {
			switch (request_id) {
			case CGX_CMD_LINK_BRING_UP:
				ret = cgx_link_bringup(cgx_id, lmac_id);
				break;
			case CGX_CMD_LINK_BRING_DOWN:
				ret = cgx_link_bringdown(cgx_id, lmac_id);
				break;
			case CGX_CMD_INTERNAL_LBK:
				lmac_ctx->s.lbk1_enable = enable;
				cgx_set_internal_loopback(cgx_id, lmac_id, enable);
				break;
			case CGX_CMD_EXTERNAL_LBK:
				cgx_set_external_loopback(cgx_id, lmac_id,
							enable);
				break;
			case CGX_CMD_GET_LINK_STS:
				CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
						cgx_id, lmac_id, 0), 0); /* reset */
				link.s.link_up = lmac_ctx->s.link_up;
				link.s.full_duplex = lmac_ctx->s.full_duplex;
				link.s.speed = lmac_ctx->s.speed;
				link.s.fec = lmac->fec;
				cgx_set_link_state(cgx_id, lmac_id, &link,
					lmac_ctx->s.error_type);
				break;
			case CGX_CMD_GET_MAC_ADDR:
				scratchx0.u = 0;
				scratchx0.s.mac_s.addr_0 = lmac->local_mac_address[0];
				scratchx0.s.mac_s.addr_1 = lmac->local_mac_address[1];
				scratchx0.s.mac_s.addr_2 = lmac->local_mac_address[2];
				scratchx0.s.mac_s.addr_3 = lmac->local_mac_address[3];
				scratchx0.s.mac_s.addr_4 = lmac->local_mac_address[4];
				scratchx0.s.mac_s.addr_5 = lmac->local_mac_address[5];
				debug_cgx_intf("%s mac_addr %x:%x:%x:%x:%x:%x\n", __func__,
						scratchx0.s.mac_s.addr_0,
						scratchx0.s.mac_s.addr_1,
						scratchx0.s.mac_s.addr_2,
						scratchx0.s.mac_s.addr_3,
						scratchx0.s.mac_s.addr_4,
						scratchx0.s.mac_s.addr_5);
				CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
						cgx_id, lmac_id, 0), scratchx0.u);
				break;
			case CGX_CMD_GET_SUPPORTED_FEC:
				scratchx0.u = 0;
				/* SFP EEPROM info will be available only when
				 * link is brought UP. If the link_enable is set
				 * in case of SFP slot, supported FEC should
				 * be returned based on transceiver capabilities
				 * If not, return PCS supported FEC types
				 */
				if ((lmac_ctx->s.link_enable) &&
						(lmac->sfp_slot))
					val = sfp_get_fec_capability(cgx_id,
								lmac_id);
				else
					val = cgx_get_supported_fec_type(
							cgx_id, lmac_id);
				scratchx0.s.supported_fec.fec = val;
				debug_cgx_intf("%s: %d:%d supported FEC %d\n",
					__func__, cgx_id, lmac_id,
					scratchx0.s.supported_fec.fec);
				CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
						cgx_id, lmac_id, 0),
						scratchx0.u);
			break;
			case CGX_CMD_SET_FEC:
				/* Read the command arguments from SCRATCH(1) */
				scratchx1.u = CSR_READ(CAVM_CGXX_CMRX_SCRATCHX(
							cgx_id, lmac_id, 1));
				req_fec = scratchx1.s.fec_args.fec;
				debug_cgx_intf("%s: %d:%d requested FEC %d\n",
						__func__,
						cgx_id, lmac_id, req_fec);
				ret = cgx_set_fec_type(cgx_id, lmac_id,
								req_fec);
				if (!cgx_get_error_type(cgx_id, lmac_id)) {
					if (cgx_update_flash_fec_param(cgx_id,
						lmac_id, req_fec))
						debug_cgx_intf(
						"Flash update fec failed\n");
				}
			break;
			case CGX_CMD_SET_PHY_MOD_TYPE:
				phy_mod_type = scratchx1.s.phy_mod_args.mod;
				ret = cgx_set_phy_mod_type(cgx_id, lmac_id,
							   phy_mod_type);
			break;
			case CGX_CMD_GET_PHY_MOD_TYPE:
				scratchx0.u = 0;
				scratchx0.s.phy_mod_type.mod =
					lmac->phy_config.mod_type;
				CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
						cgx_id, lmac_id, 0),
						scratchx0.u);
			break;
			/* FIXME: add support for other commands */
			default:
				debug_cgx_intf("%s: %d:%d Invalid request %d\n",
					__func__, cgx_id, lmac_id, request_id);
				cgx_set_error_type(cgx_id, lmac_id,
					CGX_ERR_REQUEST_ID_INVALID);
				break;
			}
		} else {
			debug_cgx_intf("%s: CGX%d LMAC%d is not enabled.\t"
					"Req %d ignored\n", __func__, cgx_id,
					lmac_id, request_id);
			cgx_set_error_type(cgx_id, lmac_id,
					CGX_ERR_LMAC_NOT_ENABLED);
		}
	}

	/* update the event status either async or resp
	 * to command by writing to evt_sts struct
	 */
	scratchx0.u = CSR_READ(CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 0));
	err_type = cgx_get_error_type(cgx_id, lmac_id);
	if (err_type & CGX_ERR_MASK)
		scratchx0.s.evt_sts.stat = CGX_STAT_FAIL;
	else
		scratchx0.s.evt_sts.stat = CGX_STAT_SUCCESS;

	/* For all requests, update the command status, ID and
	 * set event type
	 */
	scratchx0.s.evt_sts.id = request_id;
	scratchx0.s.evt_sts.evt_type = CGX_EVT_CMD_RESP;
	if ((request_id != CGX_CMD_LINK_BRING_UP) &&
		(request_id != CGX_CMD_LINK_BRING_DOWN) &&
		(request_id != CGX_CMD_SET_FEC)) {
		/* in case of LINK_UP/DOWN, error type is updated
		 * as part of link status struct
		 */
		if (err_type & CGX_ERR_MASK)
			scratchx0.s.err.type = err_type;
	}

	scratchx0.s.evt_sts.ack = 1; /* set ack */
	CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
				cgx_id, lmac_id, 0), scratchx0.u);

	return ret;
}

static int cgx_handle_link_reqs(int cgx_id, int lmac_id,
			link_state_t *new_link)
{
	int timeout = 10; /* check the moderate val */;
	union cgx_scratchx0 cgx_scratch0;
	cgx_lmac_context_t *lmac_ctx;

	debug_cgx_intf("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	/* check for the ack bit to be clear and post the command */
	do {
		cgx_scratch0.u = CSR_READ(CAVM_CGXX_CMRX_SCRATCHX(
					cgx_id, lmac_id, 0));
		debug_cgx_intf("%s, waiting for prev ack %d to be clear\n",
				__func__, cgx_scratch0.s.evt_sts.ack);
		if (!cgx_scratch0.s.evt_sts.ack)
			break;
		udelay(1);
	} while (--timeout);

	if (!timeout) {
		/* prev ack not clear */
		debug_cgx_intf("%s %d:%d Prev ack not clear to post\t"
			"LINK CHANGE req\n", __func__, cgx_id, lmac_id);
		return -1;
	}

	/* acquire the internal lock */
	if (cgx_acquire_csr_lock(cgx_id, lmac_id) == -1) {
		debug_cgx_intf("%s %d:%d lock not obtained to post\t"
				"LINK CHANGE req\n", __func__, cgx_id, lmac_id);
		return -1;
	}

	lmac_ctx = &lmac_context[cgx_id][lmac_id];

	/* post the command by setting link_change_req */
	lmac_ctx->s.link_up = new_link->s.link_up;
	lmac_ctx->s.speed = new_link->s.speed;
	lmac_ctx->s.full_duplex = new_link->s.full_duplex;
	lmac_ctx->s.link_change_req = 1;

	/* release the internal lock */
	cgx_release_csr_lock(cgx_id, lmac_id);

	return 0;
}

static int cgx_check_sfp_mod_stat(int cgx_id, int lmac_id)
{
	int ret = 0, mod_status = 0;
	cgx_lmac_context_t *lmac_ctx;

	debug_cgx_intf("%s: %d:%d\n", __func__, cgx_id, lmac_id);

	lmac_ctx = &lmac_context[cgx_id][lmac_id];

	/* Obtain the module status */
	mod_status = sfp_get_mod_status(cgx_id, lmac_id);

	if (mod_status == -1)
		return -1;

	/* MCP updates EEPROM buffer every 5s if the user
	 * hasn't un-plugged/plugged the transceiver. In this
	 * case, just update the SH memory with the
	 * data and do not handle any link change
	 */
	if (mod_status == SFP_MOD_STATE_EEPROM_UPDATED) {
		lmac_ctx->s.mod_stats = mod_status;
		sfp_parse_eeprom_data(cgx_id, lmac_id);
		return 0;
	}

	if (mod_status != lmac_ctx->s.mod_stats) {
		/* Update the new status */
		lmac_ctx->s.mod_stats = mod_status;
		if (mod_status == SFP_MOD_STATE_PRESENT) {
			/* User has unplug and plug the module.
			 * In this case, read the EEPROM capabilities
			 * and configure CGX accordingly if there is
			 * a change in capabilities.
			 */
			debug_cgx_intf("%s: %d:%d User has plugged module\n",
				 __func__, cgx_id, lmac_id);

			ret = cgx_sfp_obtain_capabilities(cgx_id, lmac_id);
			if (ret != 1)
				return -1;
			return 1; /* Valid */
		}
		debug_cgx_intf("%s: %d:%d user has un-plugged cable\n",
				__func__, cgx_id, lmac_id);
		/* If Module is absent, clear the EEPROM data */
		sh_fwdata_clear_eeprom_data(cgx_id, lmac_id, 0);
	}
	return 0;
}

/* Timer callback to periodically poll for link */
static int cgx_poll_for_link_cb(int timer)
{
	int valid = 0;
	cgx_lmac_config_t *lmac_cfg;
	cgx_lmac_context_t *lmac_ctx;
	phy_config_t *phy_cfg;
	link_state_t link;

	for (int cgx = 0; cgx < plat_octeontx_scfg->cgx_count; cgx++) {
		for (int lmac = 0; lmac < MAX_LMAC_PER_CGX; lmac++) {
			lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx].lmac_cfg[lmac];
			lmac_ctx = &lmac_context[cgx][lmac];
			phy_cfg = &lmac_cfg->phy_config;

			link.u64 = 0;
			valid = 0;

			if ((lmac_ctx->s.link_enable) ||
				(lmac_ctx->s.link_req)) {
				if (lmac_cfg->sfp_slot)
					valid = cgx_check_sfp_mod_stat(cgx,
							lmac);

				/* Get the link status */
				if (lmac_cfg->mdio_bus_dbg != phy_cfg->mdio_bus)
					phy_get_link_status(cgx, lmac, &link);

				/* If the prev link change is not handled
				 * wait until it is handled as the reqs
				 * are handled one at a time
				 */
				if ((!lmac_ctx->s.link_change_req) &&
				((valid == 1) || ((lmac_ctx->s.link_up !=
					link.s.link_up) ||
					(lmac_ctx->s.full_duplex !=
					link.s.full_duplex) ||
					(lmac_ctx->s.speed !=
					link.s.speed)))) {
					debug_cgx_intf("%d:%d link changed%d\n",
							cgx, lmac,
							link.s.link_up);
					cgx_handle_link_reqs(cgx, lmac,
								&link);
				}
			}
		}
	}
	return 0;
}

/* Timer callback to process CGX requests */
static int cgx_handle_requests_cb(int timer)
{
	union cgx_scratchx1 scratch1;
	union cgx_scratchx0 scratch0;
	cgx_lmac_context_t *lmac_ctx;

	/* Go through all active LMACs and check
	 * if there are any new message requests by reading
	 * command register of each LMAC(SCRATCHX(1)
	 */
	for (int cgx = 0; cgx < plat_octeontx_scfg->cgx_count; cgx++) {
		for (int lmac = 0; lmac < MAX_LMAC_PER_CGX; lmac++) {
			scratch1.u = CSR_READ(CAVM_CGXX_CMRX_SCRATCHX(cgx, lmac, 1));
			scratch0.u = CSR_READ(CAVM_CGXX_CMRX_SCRATCHX(cgx, lmac, 0));
			lmac_ctx = &lmac_context[cgx][lmac];

			/* acquire firmware internal lock */
			if (cgx_acquire_csr_lock(cgx, lmac) == -1) {
				debug_cgx_intf("%s %d:%d lock not"
				" obtained to process command,"
				" wait for now\n",
				 __func__, cgx, lmac);
				/* skip to next LMAC */
				continue;
			}

			/* first, check if link change event is
			 * posted by timer #2 before handling
			 * new requests post by non-secure SW
			 */
			if (lmac_ctx->s.link_change_req) {
				debug_cgx_intf("%s: %d:%d link chng req\n",
					__func__, cgx, lmac);
				cgx_link_change_req(cgx, lmac);

				/* trigger an interrupt to notify the event */
				cgx_trigger_interrupt(cgx, lmac);
			}
			/* poll on ownership to be set as OWN_FW to
			 * process any new requests
			 */
			if (scratch1.s.own_status == CGX_OWN_FIRMWARE) {
				if (scratch0.s.evt_sts.ack) {
					debug_cgx_intf("%s Req ignored,"
						" status not cleared\n",
						__func__);
					cgx_set_error_type(cgx, lmac,
					CGX_ERR_PREV_ACK_NOT_CLEAR);
					cgx_release_own_status(cgx, lmac);
					cgx_release_csr_lock(cgx, lmac);
					/* skip to next LMAC */
					continue;
				}

				cgx_process_requests(cgx, lmac);

				cgx_release_own_status(cgx, lmac);

				/* trigger an interrupt before ret */
				cgx_trigger_interrupt(cgx, lmac);
			}

			/* release firmware internal lock */
			cgx_release_csr_lock(cgx, lmac);
		}
	}
	return 0;
}

void cgx_get_link_state(int cgx_id, int lmac_id, link_state_t *link)
{
	union cgx_scratchx0 scratchx0;

	debug_cgx_intf("%s:%d:%d\n", __func__, cgx_id, lmac_id);

	scratchx0.u = CSR_READ(CAVM_CGXX_CMRX_SCRATCHX(
					cgx_id, lmac_id, 0));
	link->s.link_up  = scratchx0.s.link_sts.link_up;
	link->s.full_duplex = scratchx0.s.link_sts.speed;
	link->s.full_duplex = scratchx0.s.link_sts.full_duplex;
}

/* this function to be called from any CGX function when major
 * error type is encountered
 */
void cgx_set_error_type(int cgx_id, int lmac_id, uint64_t type)
{
	cgx_lmac_context_t *lmac_ctx;

	lmac_ctx = &lmac_context[cgx_id][lmac_id];
	lmac_ctx->s.error_type = type;
}


/* This function should be called once during boot time */
void cgx_fw_intf_init(void)
{
	cgx_config_t *cgx_cfg;
	cgx_lmac_config_t *lmac_cfg;
	cgx_lmac_context_t *lmac_ctx;

	debug_cgx_intf("%s\n", __func__);

	for (int cgx = 0; cgx < plat_octeontx_scfg->cgx_count; cgx++) {
		cgx_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx];

		if (cgx_cfg->enable) {
			for (int lmac = 0; lmac < MAX_LMAC_PER_CGX; lmac++) {
				lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx].lmac_cfg[lmac];
				lmac_ctx = &lmac_context[cgx][lmac];
				if (lmac_cfg->lmac_enable) {
					if (lmac_cfg->phy_present) {
						/* If PHY is present, look up for PHY
						 * driver and init
						 */
						phy_lookup(cgx, lmac, lmac_cfg->phy_config.type);
						if ((lmac_cfg->phy_config.valid) &&
							(!lmac_cfg->phy_config.init)) {
							debug_cgx_intf("%s: init PHY\n", __func__);
							phy_probe(cgx, lmac);
							lmac_cfg->phy_config.init = 1;
						}
					}
					/* Enable LMAC */
					cgx_lmac_init_link(cgx, lmac);
					lmac_ctx->s.init_link = 1;
					/* If PHY is initialized, configure
					 * the PHY. For ex: to set in
					 * particular mode
					 */
					if (lmac_cfg->phy_config.init)
						phy_config(cgx, lmac);
				}
			}
		} else {
			/* for CGXs that are not configured by BDK to any mode,
			 * CGX config CSRs needs to be configured correctly
			 * as init callback will not be triggered for these
			 * CGXs
			 */
			cgx_hw_init(cgx);
		}
	}

	/* start with 1 timer to handle & process CGX requests */
	cgx_timers[0] = timer_create(TM_PERIODIC, 1000, cgx_handle_requests_cb);
	timer_start(cgx_timers[0]);

	/* start 2nd timer to peridically poll for link status */
	cgx_timers[1] = timer_create(TM_PERIODIC, 1000, cgx_poll_for_link_cb);
	timer_start(cgx_timers[1]);
}

/* this function required to be called when booting to kernel
 * from uefi/u-boot. Timer will still be running,
 * Brings down the link for which ever link is enabled and clear
 * the SCRATCHx register info so
 * when kernel is booting, it can start new.
 */
void cgx_fw_intf_shutdown(void)
{
	int init = 0;
	cgx_lmac_context_t *lmac_ctx;
	cgx_lmac_config_t *lmac_cfg;

	cavm_cgxx_cmrx_int_t cmrx_int;

	debug_cgx_intf("%s\n", __func__);

	/* bring down all the links and clear all SCRATCHX
	 * registers/context
	 */
	for (int cgx = 0; cgx < plat_octeontx_scfg->cgx_count; cgx++) {
		for (int lmac = 0; lmac < MAX_LMAC_PER_CGX; lmac++) {
			lmac_ctx = &lmac_context[cgx][lmac];
			lmac_cfg = &plat_octeontx_bcfg->cgx_cfg[cgx]
							.lmac_cfg[lmac];
			/* Bring down the link if link_enable is set.
			 * After bringing down the links, do one time
			 * initialization of the LMACs that are enabled
			 * so kernel can bring up the link.
			 * In case of QSGMII, always bring down the link
			 * for all the LMACs associated with the CGX
			 */
			init = 0;
			if ((lmac_cfg->mode == CAVM_CGX_LMAC_TYPES_E_QSGMII) ||
				(lmac_ctx->s.link_enable)) {
				cgx_link_bringdown(cgx, lmac);
				mdelay(1);
				/* Set to indicate the link is
				 * initialized as the LMAC
				 * context structure will be reset
				 */
				init = 1;
			}
			CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
					cgx, lmac, 0), 0);
			CSR_WRITE(CAVM_CGXX_CMRX_SCRATCHX(
					cgx, lmac, 1), 0);
			lmac_ctx->u64 = 0;
			if (init)
				lmac_ctx->s.init_link = 1;
			/* Clear the interrupt during shutdown for all
			 * LMACs as there might be a possibility that
			 * interrupts are not cleared by u-boot
			 * as it doesn't handle asynchronous events
			 */
			cmrx_int.u = CSR_READ(CAVM_CGXX_CMRX_INT(cgx, lmac));
			cmrx_int.s.overflw = 1;
			CSR_WRITE(CAVM_CGXX_CMRX_INT(cgx, lmac),
					cmrx_int.u);
		}
		/* Now for each CGX, initialize the link for each LMAC
		 * if the link was brought down
		 */
		for (int lmac = 0; lmac < MAX_LMAC_PER_CGX; lmac++) {

			lmac_ctx = &lmac_context[cgx][lmac];
			if (lmac_ctx->s.init_link)
				cgx_lmac_init_link(cgx, lmac);
		}
	}
}
