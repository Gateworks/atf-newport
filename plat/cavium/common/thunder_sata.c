#include <stdint.h>
#include <stdio.h>
#include <timers.h>
#include <platform_def.h>
#include <thunder_private.h>
#include <debug.h>
#include <assert.h>
#include <thunder_common.h>

#undef SATA_DEBUG

#define PM_DISABLE_PARTIAL	0x1
#define PM_DISABLE_SLUMBER	0x2

#define SATA_POLL_INTERVAL	250

#define SSTS_DET_PHY_DEV_GOOD	0x3

#ifdef SATA_DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...) ((void) (0))
#endif

static uint64_t sata_base[PLATFORM_MAX_NODES][MAX_SATA_CONTROLLERS];
static uint64_t gser_base[PLATFORM_MAX_NODES][MAX_SATA_GSER];
#if 0
static uint8_t sata_state_count[PLATFORM_MAX_NODES][MAX_SATA_CONTROLLERS];
static char last_sata_state[PLATFORM_MAX_NODES][MAX_SATA_CONTROLLERS];
#endif

static int timer_hd;

/* Number of SATA controllers on platform */
static int sata_ctrlr_count;

/**
 * ThunderX has an issue where SATA drives may randomly drop out if power
 * management is enabled on two lanes of a half of a QLM. Force the SCTL[IPM]
 * bits to disable PARTIAL sleep and SLUMBER. We do this periodically in case
 * the OS tries to enable power management. We silently fix it so the OS doesn't
 * change.
 *
 * @param node   Node to check
 * @param sata   SATA controller to check
 *
 * @return Zero, unused
 */
static int sata_drive_check_power_management(int node, int sata)
{
	union cavm_satax_uahc_p0_sctl sctl;

	sctl.u = CSR_READ_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SCTL(sata));
	if (sctl.s.ipm != (PM_DISABLE_SLUMBER | PM_DISABLE_PARTIAL)) {
		sctl.s.ipm = PM_DISABLE_PARTIAL | PM_DISABLE_SLUMBER;
		debug("ATF: N%d: SATA%d: Force disabling PARTIAL and SLUMBER\n",
		      node, sata);
		CSR_WRITE_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SCTL(sata),
			  sctl.u);
	}
	return 0;
}

/**
 * ThunderX has an issue where drives may be detected and stuck
 * in busy after a SATA controller reset. Poll the drive status
 * to detect this, issuing a COMRESET as needed.
 *
 * @param node   Node to check
 * @param sata   SATA controller to check
 *
 * @return Zero, unused
 */
#if 0
static int sata_drive_check_detect_failure(int node, int sata)
{
	union cavm_satax_uahc_p0_cmd cmd;
	union cavm_satax_uahc_p0_sctl sctl;
	union cavm_satax_uahc_p0_ssts ssts;
	union cavm_satax_uahc_p0_tfd tfd;
	int is_detected;
	int is_busy;

	/*
	 * Check if the SATA controller is started. If so assume drive is
	 * working fine. Also if FIS processing is not started, then
	 * the SATA controller must not be setup yet.
	 */
	cmd.u = CSR_READ_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_CMD(sata));
	if (cmd.s.st || !cmd.s.fre) {
		sata_state_count[node][sata] = 0;
		return 0;
	}

	/* Check if the controller is sending COMRESET (SCTL[DET]=1) */
	sctl.u = CSR_READ_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SCTL(sata));
	if (sata_state_count[node][sata] && sctl.s.det) {
		/* We have already started COMRESET, finish it */
		debug("ATF: N%d: SATA%d: Restart drive detect\n", node, sata);
		sctl.s.det = 0;
		CSR_WRITE_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SCTL(sata),
			  sctl.u);
		sata_state_count[node][sata] = 0;
		return 0;
	}

	/* See if the controller has detected the drive */
	ssts.u = CSR_READ_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SSTS(sata));
	is_detected = (ssts.s.det == SSTS_DET_PHY_DEV_GOOD);

	/* See if the drive is busy */
	tfd.u = CSR_READ_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_TFD(sata));
	is_busy = ((tfd.s.sts & 0x80) != 0);

	/*
	 * If the drive isn't detected or busy we will need to
	 * recover it using COMRESET.
	 */
	if (!is_detected || is_busy) {
		/*
		 * Require the drive to be missing for 2 timer
		 * periods before starting COMRESET.
		 */
		if (sata_state_count[node][sata] < 2) {
			sata_state_count[node][sata]++;
			return 0;
		}
		debug("ATF: N%d: SATA%d: Failed drive detect\n", node, sata);
		sctl.s.det = 1;
		CSR_WRITE_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SCTL(sata),
			  sctl.u);
		return 0;
	} else {
		/* Drive looks good even though the controller is not ready */
		sata_state_count[node][sata] = 0;
	}

	return 0;
}

/**
 * ThunderX has an issue where hot unplug of drives may not be detected.
 * Poll the SATA controller to detect and recover this condition.
 *
 * @param node   Node to check
 * @param sata   SATA controller to check
 *
 * @return Zero, unused
 */

#define NUM_CONTINUOUS_EIE_READ 10
static int sata_drive_check_unplug_failure(int node, int sata)
{
	union cavm_gserx_rx_eie_detsts detsts;
	union cavm_satax_uahc_p0_ssts ssts;
	union cavm_satax_uahc_p0_serr serr;
	union cavm_gserx_lanex_lbert_cfg lbert_cfg;
	union cavm_gserx_lanex_misc_cfg_0 cfg_0;
	int i, lane, qlm;

	/* Determine which GSER and lane this SATA connects to */
	qlm = thunder_sata_to_gser(sata);
	lane = thunder_sata_to_lane(sata);
	if (lane < 0 || qlm < 0)
		return 0;

	/*
	 * Use exiting eletrical idle to detect if a drive is unplugged. The
	 * lane's EIESTS becomes zero when a drive is hot unplugged.
	 */
	for (i = 0; i < NUM_CONTINUOUS_EIE_READ; i++) {
		detsts.u = CSR_READ_PA(gser_base[node][qlm],
			            CAVM_GSERX_RX_EIE_DETSTS(qlm));
		if (detsts.s.eiests & (1 << lane)) {
			/* EIESTS is set, so a drive is plugged in */
			goto detected;
		}
	}

	/* See if the controller has detected the drive */
	ssts.u = CSR_READ_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SSTS(sata));
	if (ssts.s.det != SSTS_DET_PHY_DEV_GOOD) {
		/*
		 * The controller knows there isn't a drive, so we
		 * don't need to do anything.
		 */
		goto detected;
	}

	serr.u = CSR_READ_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SERR(sata));
	if (serr.u != 0) {
		/*
		 * The controller knows there isn't a drive, so we
		 * don't need to do anything.
		 */
		goto detected;
	}

	if (last_sata_state[node][sata] == 0) {
		last_sata_state[node][sata] = 1;
		return 0;
	}

	debug("ATF: N%d: SATA%d: Fixup hot unplug (QLM %d, Lane %d)\n", node,
	      sata, qlm, lane);

	/* Set the pattern generator to create a static pattern of zeros */
	CSR_WRITE_PA(gser_base[node][qlm],
		  CAVM_GSERX_LANEX_LBERT_PAT_CFG(qlm, lane), 0);

	/* Enable the pattern generator creating 8b/10b patterns of zeros */
	lbert_cfg.u = CSR_READ_PA(gser_base[node][qlm],
			       CAVM_GSERX_LANEX_LBERT_CFG(qlm, lane));
	lbert_cfg.s.lbert_pg_width = 3;
	lbert_cfg.s.lbert_pg_mode = 8;
	lbert_cfg.s.lbert_pg_en = 1;
	CSR_WRITE_PA(gser_base[node][qlm], CAVM_GSERX_LANEX_LBERT_CFG(qlm, lane),
		  lbert_cfg.u);

	/* Put the PCS in internal loopback */
	cfg_0.u = CSR_READ_PA(gser_base[node][qlm],
			   CAVM_GSERX_LANEX_MISC_CFG_0(qlm, lane));
	cfg_0.s.cfg_pcs_loopback = 1;
	CSR_WRITE_PA(gser_base[node][qlm], CAVM_GSERX_LANEX_MISC_CFG_0(qlm, lane),
		  cfg_0.u);
	CSR_READ_PA(gser_base[node][qlm], CAVM_GSERX_LANEX_MISC_CFG_0(qlm, lane));

	/* SATA controller should detect link drop */
	serr.u = CSR_READ_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SERR(sata));

	/* Disable PCS loopback */
	cfg_0.s.cfg_pcs_loopback = 0;
	CSR_WRITE_PA(gser_base[node][qlm], CAVM_GSERX_LANEX_MISC_CFG_0(qlm, lane),
		  cfg_0.u);

	/* Disable pattern generator */
	lbert_cfg.s.lbert_pg_en = 0;
	CSR_WRITE_PA(gser_base[node][qlm], CAVM_GSERX_LANEX_LBERT_CFG(qlm, lane),
		  lbert_cfg.u);
	CSR_READ_PA(gser_base[node][qlm], CAVM_GSERX_LANEX_LBERT_CFG(qlm, lane));

	/* Clear non-recovered persistent communication error */
	CSR_WRITE_PA(sata_base[node][sata], CAVM_SATAX_UAHC_P0_SERR(sata), 0x200);

	return 0;
detected:
	last_sata_state[node][sata] = 0;
	return 0;

}
#endif

static int timer_cb(int hd)
{
	int i, node_cnt, node;
	node_cnt = thunder_get_node_count();

	for (node = 0; node < node_cnt; node++) {
		for (i = 0; i < sata_ctrlr_count; ++i) {
			if (sata_base[node][i] == 0)
				continue;
			sata_drive_check_power_management(node, i);
			/*
			The following two calls are disabled till we find
			a solution for all T81/T83 platforms.
			sata_drive_check_detect_failure(node, i);
			sata_drive_check_unplug_failure(node, i);
			*/
		}
	}
	return 0;
}

void sata_ipm_quirk()
{
	int i, node, node_cnt, gser;
	union cavm_satax_uctl_ctl uctl_ctl;
	union cavm_gserx_cfg gser_cfg;

	sata_ctrlr_count = thunder_get_sata_count();

	node_cnt = thunder_get_node_count();
	for (node = 0; node < node_cnt; node++) {
		for (i = 0; i < thunder_get_max_sata_gser(); i++)
			gser_base[node][i] = CSR_PA(node, CAVM_GSERX_PF_BAR0(i));

		for (i = 0; i < sata_ctrlr_count; i++) {
			gser = thunder_sata_to_gser(i);

			gser_cfg.u = CSR_READ_PA(gser_base[node][gser],
					      CAVM_GSERX_CFG(gser));
			debug("CAVM_GSERX_CFG(%d): %lx\n", gser, gser_cfg.u);

			if (!gser_cfg.s.sata) {
				sata_base[node][i] = 0;
				continue;
			}

			sata_base[node][i] = CSR_PA(node, CAVM_SATAX_PF_BAR0(i));

			/* check if we are in SATA mode */
			uctl_ctl.u = CSR_READ_PA(sata_base[node][i],
					      CAVM_SATAX_UCTL_CTL(i));
			debug("CAVM_SATAX_UCTL_CTL(%d): %lx\n", i, uctl_ctl.u);

			if (!uctl_ctl.s.a_clk_en || uctl_ctl.s.a_clkdiv_rst) {
				/*
				 * Assume we cannot have 0 as address.
				 * Mark this controller unavailable.
				 */
				sata_base[node][i] = 0;
			}
		}
	}
	timer_hd = timer_create(TM_PERIODIC, SATA_POLL_INTERVAL, timer_cb);
	timer_start(timer_hd);
}
