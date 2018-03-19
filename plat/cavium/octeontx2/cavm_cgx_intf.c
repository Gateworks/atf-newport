/** @file

  Copyright (c) 2017, Cavium Inc. All rights reserved.<BR>
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
#include <string.h>
#include <platform_def.h>
#include <timers.h>
#include <cavm_common.h>
#include <delay_timer.h>
#include <cavm_dt.h>
#include <cavm_cgx_intf.h>
#include <cavm_cgx.h>

#define MAX_CGX_TIMERS 2

static int cgx_timers[MAX_CGX_TIMERS];

static cgx_lmac_context_t
		lmac_context[PLATFORM_MAX_NODES][MAX_CGX][MAX_LMAC_PER_CGX];

static uint64_t cgx_get_error_type(int node, int cgx_id, int lmac_id)
{
	cgx_lmac_context_t *lmac_ctx;

	lmac_ctx = &lmac_context[node][cgx_id][lmac_id];
	INFO("%s: %d:%d:%d error_type 0x%x\n", __func__, node, cgx_id, lmac_id,
				lmac_ctx->s.error_type);
	return lmac_ctx->s.error_type;
}

static int cgx_trigger_interrupt(int node, int cgx_id, int lmac_id)
{
	INFO("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	/* Enable the interrupt bit each time before triggering
	 * an interrupt. In case of Link down request, enable bit for
	 * LMAC(CGXX_CMRX_CONFIG(enable)) is disabled
	 * which clears all the dedicated CGX context
	 * state for the LMAC. Hence, need to explicitly enable
	 * the interrupt every time.
	 */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_int_ena_w1s_t,
				CAVM_CGXX_CMRX_INT_ENA_W1S(cgx_id, lmac_id),
				overflw, 1);

	/* FIXME: trigger an interrupt to kernel
	 * via CMRX overflow int bit - Hardware-opaque vector
	 * for software driver (37th MSIX vector) doesn't have interrupt
	 * support yet. this is a workaround for the 1st pass
	 */
	CAVM_MODIFY_CGX_CSR(node, cavm_cgxx_cmrx_int_w1s_t,
				CAVM_CGXX_CMRX_INT_W1S(cgx_id, lmac_id),
				overflw, 1);
	return 0;
}

static int cgx_acquire_csr_lock(int node, int cgx_id, int lmac_id)
{
	int timeout = 10; /* loop for few times but not infinitely */
	cgx_lmac_context_t *lmac_ctx;

	INFO("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	lmac_ctx = &lmac_context[node][cgx_id][lmac_id];

	do {
		if (!lmac_ctx->s.lock) {
			lmac_ctx->s.lock = 1;
			return 0;
		}
		udelay(1);
	} while (timeout--);

	return -1;
}

static void cgx_release_csr_lock(int node, int cgx_id, int lmac_id)
{
	INFO("%s %d:%d:%d\n", __func__, node, cgx_id, lmac_id);
	lmac_context[node][cgx_id][lmac_id].s.lock = 0;
}

static void cgx_release_own_status(int node, int cgx_id, int lmac_id)
{
	CAVM_MODIFY_CGX_CSR(node, union cgx_scratchx1,
			CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 1),
			own_status, 0); /* released the ownership */
}

/* Note : this function executes with lock acquired */
static int cgx_process_requests(int node, int cgx_id, int lmac_id)
{
	int ret = 0;
	int request_id = 0;
	union cgx_scratchx0 scratchx0;
	union cgx_scratchx1 scratchx1;
	cgx_lmac_config_t *lmac;

	lmac = &bfdt->cgx_cfg[cgx_id].lmac_cfg[lmac_id];

	/* Read the command arguments from SCRATCHX(1) */
	scratchx1.u = CSR_READ(node, CAVM_CGXX_CMRX_SCRATCHX(
					cgx_id, lmac_id, 1));
	request_id = scratchx1.s.cmd.id;

	INFO("%s: %d:%d:%d request_id %d\n", __func__, node, cgx_id,
				lmac_id, request_id);

	/* always reset the error bits when processing new
	 * command except when obtaining current status
	 */
	if (request_id != CGX_CMD_GET_LINK_STS)
		cgx_set_error_type(node, cgx_id, lmac_id, 0);

	if (lmac->lmac_enable) {
		switch (request_id) {
		/* FIXME: add support for the commands */
		case CGX_CMD_LINK_BRING_UP:
			break;
		case CGX_CMD_LINK_BRING_DOWN:
			break;
		case CGX_CMD_LINK_STAT_CHANGE:
			break;
		case CGX_CMD_INTF_SHUTDOWN:
			break;
		case CGX_CMD_INTERNAL_LBK:
			break;
		case CGX_CMD_EXTERNAL_LBK:
			break;
		case CGX_CMD_GET_FW_VER:
			break;
		case CGX_CMD_GET_LINK_STS:
			break;
		case CGX_CMD_GET_MAC_ADDR:
			break;
		default:
			ERROR("%s: Invalid ID %d\n", __func__, request_id);
			cgx_set_error_type(node, cgx_id, lmac_id,
				CGX_ERR_REQUEST_ID_INVALID);
			break;
		}
	} else {
		ERROR("%s: CGX%d LMAC%d is not enabled. Req %d ignored\n",
			__func__, cgx_id, lmac_id, request_id);
		cgx_set_error_type(node, cgx_id, lmac_id,
				CGX_ERR_LMAC_NOT_ENABLED);
	}

	/* update the event status either async or resp
	 * to command by writing to evt_sts struct
	 */
	scratchx0.u = CSR_READ(node, CAVM_CGXX_CMRX_SCRATCHX(
					cgx_id, lmac_id, 0));
	if ((cgx_get_error_type(node, cgx_id, lmac_id)) &
				CGX_ERR_MASK)
		scratchx0.s.evt_sts.stat = CGX_STAT_FAIL;
	else
		scratchx0.s.evt_sts.stat = CGX_STAT_SUCCESS;

	if (request_id == CGX_CMD_LINK_STAT_CHANGE) {
		/* handle this case differently as this is not user submitted
		 * request. It is from PHY obtained periodically
		 * polling the link status. Notify to user there is change
		 * in link status by setting event type as CGX_EVT_ASYNC
		 */
		scratchx0.s.evt_sts.id = CGX_EVT_LINK_CHANGE;
		scratchx0.s.evt_sts.evt_type = CGX_EVT_ASYNC;
	} else {
		/* For all other requests, update the command status, ID and
		 * set event type
		 */
		scratchx0.s.evt_sts.id = request_id;
		scratchx0.s.evt_sts.evt_type = CGX_EVT_CMD_RESP;
		if ((request_id != CGX_CMD_LINK_BRING_UP) &&
			(request_id != CGX_CMD_LINK_BRING_DOWN)) {
			/* in case of LINK_UP/DOWN, error type is updated
			 * as part of link status struct
			 */
			if ((cgx_get_error_type(node, cgx_id, lmac_id)) &
							CGX_ERR_MASK)
				scratchx0.s.err.type = cgx_get_error_type(
					node, cgx_id, lmac_id);
		}
	}
	scratchx0.s.evt_sts.ack = 1; /* set ack */
	CSR_WRITE(node, CAVM_CGXX_CMRX_SCRATCHX(
				cgx_id, lmac_id, 0), scratchx0.u);

	return ret;
}

static int cgx_handle_link_change(int node, int cgx_id, int lmac_id,
			link_state_t *new_link)
{
	int timeout = 10; /* check the moderate val */;
	union cgx_scratchx1 cgx_scratch1;
	union cgx_scratchx0 cgx_scratch0;
	cgx_lmac_context_t *lmac_ctx;

	INFO("%s: %d:%d:%d\n", __func__, node, cgx_id, lmac_id);

	/* if the owner ship is available and lock is free, check
	 * for the ack bit to be clear and post the command.
	 */
	do {
		cgx_scratch1.u = CSR_READ(node, CAVM_CGXX_CMRX_SCRATCHX(
					cgx_id, lmac_id, 1));
		cgx_scratch0.u = CSR_READ(node, CAVM_CGXX_CMRX_SCRATCHX(
					cgx_id, lmac_id, 0));
		INFO("%s, waiting for own %d and prev ack %d to be clear\n",
				__func__, cgx_scratch1.s.own_status,
				cgx_scratch0.s.evt_sts.ack);
		if ((!cgx_scratch1.s.own_status) &&
				(!cgx_scratch0.s.evt_sts.ack))
			break;
		udelay(1);
	} while (--timeout);

	if (!timeout) {
		/* not able to obtain the ownership of CSRs */
		WARN("%s %d:%d Owner ship not free to post LINK CHANGE req\n",
			__func__, cgx_id, lmac_id);
		return -1;
	}

	/* acquire the internal lock */
	if (cgx_acquire_csr_lock(node, cgx_id, lmac_id) == -1) {
		WARN("%s %d:%d lock not obtained to post LINK CHANGE req\n",
			 __func__, cgx_id, lmac_id);
		return -1;
	}

	lmac_ctx = &lmac_context[node][cgx_id][lmac_id];
	/* post the command */
	cgx_scratch1.u = CSR_READ(node, CAVM_CGXX_CMRX_SCRATCHX(
				cgx_id, lmac_id, 1));

	/* set the ownership to firmware and update the request ID */
	cgx_scratch1.s.own_status = CGX_OWN_FIRMWARE;
	cgx_scratch1.s.cmd.id = CGX_CMD_LINK_STAT_CHANGE;

	/* pass the new link state as an argument and update the
	 * link status in context structure when the request
	 * is being submitted
	 */
	lmac_ctx->s.link_up = cgx_scratch1.s.lnk_args.link_up =
				new_link->s.link_up;
	lmac_ctx->s.speed = cgx_scratch1.s.lnk_args.speed =
				new_link->s.speed;
	lmac_ctx->s.full_duplex = cgx_scratch1.s.lnk_args.full_duplex =
				new_link->s.full_duplex;

	CSR_WRITE(node, CAVM_CGXX_CMRX_SCRATCHX(cgx_id, lmac_id, 1),
					cgx_scratch1.u);
	/* release the internal lock, but still maintain the own status
	 * as FIRMWARE so that timer #2 can process the link
	 * change command
	 */
	cgx_release_csr_lock(node, cgx_id, lmac_id);

	return 0;
}

/* Timer callback to periodically poll for link */
static int cgx_poll_for_link_cb(int timer)
{
	cgx_lmac_config_t *lmac_cfg;
	cgx_lmac_context_t *lmac_ctx;
	link_state_t link = {0};

	for (int node = 0; node < PLATFORM_MAX_NODES; node++) {
		for (int cgx = 0; cgx < MAX_CGX; cgx++) {
			for (int lmac = 0; lmac < MAX_LMAC_PER_CGX; lmac++) {
				lmac_cfg = &bfdt->cgx_cfg[cgx].lmac_cfg[lmac];
				lmac_ctx = &lmac_context[node][cgx][lmac];
				if (lmac_ctx->s.link_enable) {
					/* check if PHY is present, if not
					 * return the default link status
					 */
					if (!lmac_cfg->phy_present) {
						INFO("%s:%d:%d:%d PHY not present\t",
							__func__, node, cgx, lmac);
						INFO("link %d speed %d duplex %d\n",
							lmac_ctx->s.link_up,
							lmac_ctx->s.speed,
						lmac_ctx->s.full_duplex);
						continue;
					}
					/* FIXME: to interface with PHY
					 * management and get the link status
					 */
					INFO("%s:%d:%d:%d poll for link status\n",
						__func__, node, cgx, lmac);
					if ((lmac_ctx->s.link_up !=
						link.s.link_up) ||
						(lmac_ctx->s.full_duplex !=
						link.s.full_duplex) ||
						(lmac_ctx->s.speed !=
						link.s.speed)) {
						INFO("%s:%d:%d link changed\n",
							__func__, cgx, lmac);
						cgx_handle_link_change(node,
							cgx, lmac, &link);
					}
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

	/* Go through all active LMACs and check
	 * if there are any new message requests by reading
	 * command register of each LMAC(SCRATCHX(1)
	 */
	for (int node = 0; node < PLATFORM_MAX_NODES; node++) {
		for (int cgx = 0; cgx < MAX_CGX; cgx++) {
			for (int lmac = 0; lmac < MAX_LMAC_PER_CGX; lmac++) {
				scratch1.u = CSR_READ(node,
					CAVM_CGXX_CMRX_SCRATCHX(cgx, lmac, 1));
				scratch0.u = CSR_READ(node,
					CAVM_CGXX_CMRX_SCRATCHX(cgx, lmac, 0));
				if (scratch1.s.own_status == CGX_OWN_FIRMWARE) {
					/* acquire firmware internal lock */
					if (cgx_acquire_csr_lock(node, cgx, lmac)
							== -1) {
						WARN("%s %d:%d lock not"
						" obtained to process command,"
						" wait for now\n",
						 __func__, cgx, lmac);
						/* skip to next LMAC */
						continue;
					}

					if (scratch0.s.evt_sts.ack) {
						ERROR("%s Req ignored,"
							" status not cleared\n",
							__func__);
						cgx_set_error_type(node, cgx, lmac,
						CGX_ERR_PREV_ACK_NOT_CLEAR);
						cgx_release_own_status(
								node, cgx, lmac);
						cgx_release_csr_lock(
								node, cgx, lmac);
						/* skip to next LMAC */
						continue;
					}

					cgx_process_requests(node, cgx, lmac);

					cgx_release_own_status(node, cgx, lmac);

					/* trigger an interrupt before ret */
					cgx_trigger_interrupt(node, cgx, lmac);

					/* release firmware internal lock */
					cgx_release_csr_lock(node, cgx, lmac);
				}
			}
		}
	}
	return 0;
}

/* this function to be called from any CGX function when major
 * error type is encountered
 */
void cgx_set_error_type(int node, int cgx_id, int lmac_id, uint64_t type)
{
	cgx_lmac_context_t *lmac_ctx;

	lmac_ctx = &lmac_context[node][cgx_id][lmac_id];
	INFO("%s:%d:%d:%d type 0x%lx\n", __func__, node, cgx_id, lmac_id, type);

	lmac_ctx->s.error_type = type;
}


/* This function should be called once during boot time */
void cgx_fw_intf_init(void)
{
	INFO("%s\n", __func__);

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
	INFO("%s\n", __func__);

	/* bring down all the links and clear all SCRATCHX
	 * registers/context
	 */
	for (int node = 0; node < PLATFORM_MAX_NODES; node++) {
		for (int cgx = 0; cgx < MAX_CGX; cgx++) {
			for (int lmac = 0; lmac < MAX_LMAC_PER_CGX; lmac++) {
				/* FIXME:call the bring down link API
				 * if link_enable is set for the link
				 */
				CSR_WRITE(node, CAVM_CGXX_CMRX_SCRATCHX(
						cgx, lmac, 0), 0);
				CSR_WRITE(node, CAVM_CGXX_CMRX_SCRATCHX(
						cgx, lmac, 1), 0);
				lmac_context[node][cgx][lmac].u64 = 0;
			}
		}
		/* RVU specific: enable LF to PF mapping done
		 * for NIX/NPA PFs. This is required for
		 * networking support in u-boot/uefi.
		 * clear them before booting to kernel
		 */
		octeontx2_clear_lf_to_pf_mapping(node);
	}
}
