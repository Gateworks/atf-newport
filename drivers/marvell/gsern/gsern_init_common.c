/*
 * This file was copied from BDK using gsern-bdk-to-atf.sh script.
 * Do not edit it manually!
 */


/***********************license start***********************************
* Copyright (C) 2018 Marvell International Ltd.
* SPDX-License-Identifier: BSD-3-Clause
* https://spdx.org/licenses
***********************license end**************************************/
#include <gsern.h>
#include <gsern/gsern_internal.h>

/* Some fields in GSERN must be based on the VDD supplied to VDDA_GSER. This
   global contains the BDK's guess as what the voltage currently is in
   millivolts */
int gsern_voltage = 900; /* HRM recomendation, increase to 1000 for 25G */

/**
 * Wait for GSERNX_COMMON_INIT_BSTS[rst_sm_complete]
 *
 * @param node
 * @param qlm
 *
 * @return
 */
int gsern_init_wait_for_sm_complete(int qlm)
{
	const int TIMEOUT = 10000; /* Timeout for wait loops in microsec */

	if (gsern_is_platform(GSERN_PLATFORM_ASIM) || gsern_is_platform(GSERN_PLATFORM_EMULATOR))
		return 0;

	if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_COMMON_INIT_BSTS(qlm), GSERN_COMMON_INIT_BSTS_RST_SM_COMPLETE, ==, 1, TIMEOUT))
	{
		gsern_error("N0.QLM%d: Timeout waiting for GSERNX_COMMON_INIT_BSTS[rst_sm_complete]\n", qlm);
		return -1;
	}
	if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_COMMON_INIT_BSTS(qlm), GSERN_COMMON_INIT_BSTS_RST_SM_READY, ==, 1, TIMEOUT))
	{
		gsern_error("N0.QLM%d: Timeout waiting for GSERNX_COMMON_INIT_BSTS[rst_sm_ready]\n", qlm);
		return -1;
	}
	if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_COMMON_INIT_BSTS(qlm), GSERN_COMMON_INIT_BSTS_CAL_READY, ==, 1, TIMEOUT))
	{
		gsern_error("N0.QLM%d: Timeout waiting for GSERNX_COMMON_INIT_BSTS[cal_ready]\n", qlm);
		return -1;
	}
	if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_COMMON_INIT_BSTS(qlm), GSERN_COMMON_INIT_BSTS_CAL_FAIL, ==, 0, TIMEOUT))
	{
		gsern_error("N0.QLM%d: Timeout waiting for GSERNX_COMMON_INIT_BSTS[cal_fail=0]\n", qlm);
		return -1;
	}
	return 0;
}

/**
 * Wait for GSERNX_LANEX_INIT_BSTS[rst_sm_ready]
 *
 * @param node
 * @param qlm
 * @param qlm_lane
 *
 * @return
 */
int gsern_init_wait_for_sm_ready(int qlm, int qlm_lane)
{
	const int TIMEOUT = 10000; /* Timeout for wait loops in microsec */
	int num_lanes = gsern_qlm_get_lanes(qlm);

	if (gsern_is_platform(GSERN_PLATFORM_ASIM) || gsern_is_platform(GSERN_PLATFORM_EMULATOR))
		return 0;

	for (int lane = 0; lane < num_lanes; lane++)
	{
	   /* Skip lanes we don't care about */
		if ((qlm_lane != -1) && (qlm_lane != lane))
			continue;

		if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane), GSERN_COMMON_INIT_BSTS_RST_SM_COMPLETE, ==, 1, TIMEOUT))
		{
			gsern_error("N0.QLM%d.Lane%d: Timeout waiting for GSERNX_LANEX_INIT_BSTS[rst_sm_complete]\n", qlm, lane);
			return -1;
		}
		if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane), GSERN_COMMON_INIT_BSTS_RST_SM_READY, ==, 1, TIMEOUT))
		{
			gsern_error("N0.QLM%d.Lane%d: Timeout waiting for GSERNX_LANEX_INIT_BSTS[rst_sm_ready]\n", qlm, lane);
			return -1;
		}
		if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane), GSERN_COMMON_INIT_BSTS_CAL_READY, ==, 1, TIMEOUT))
		{
			gsern_error("N0.QLM%d.Lane%d: Timeout waiting for GSERNX_LANEX_INIT_BSTS[cal_ready]\n", qlm, lane);
			return -1;
		}
		if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane), GSERN_COMMON_INIT_BSTS_CAL_FAIL, ==, 0, TIMEOUT))
		{
			gsern_error("N0.QLM%d.Lane%d: Timeout waiting for GSERNX_LANEX_INIT_BSTS[cal_fail=0]\n", qlm, lane);
			return -1;
		}
	}
	return 0;
}

/**
 * Wait for GSERNX_LANEX_INIT_BSTS[rx_ready, rx_rst_sm_complete]
 *
 * @param node
 * @param qlm
 * @param qlm_lane
 *
 * @return
 */
int gsern_init_wait_for_rx_ready(int qlm, int qlm_lane)
{
	const int TIMEOUT = 10000; /* Timeout for wait loops in microsec */
	int num_lanes = gsern_qlm_get_lanes(qlm);

	if (gsern_is_platform(GSERN_PLATFORM_ASIM) || gsern_is_platform(GSERN_PLATFORM_EMULATOR))
		return 0;

	for (int lane = 0; lane < num_lanes; lane++)
	{
	   /* Skip lanes we don't care about */
		if ((qlm_lane != -1) && (qlm_lane != lane))
			continue;

		if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane), GSERN_LANE_INIT_BSTS_RX_READY, ==, 1, TIMEOUT))
		{
			GSERN_TRACE(QLM, "N0.QLM%d.Lane%d: Timeout waiting for GSERNX_LANEX_INIT_BSTS[rx_ready]\n", qlm, lane);
			return -1;
		}
		if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane), GSERN_LANE_INIT_BSTS_RX_RST_SM_COMPLETE, ==, 1, TIMEOUT))
		{
			GSERN_TRACE(QLM, "N0.QLM%d.Lane%d: Timeout waiting for GSERNX_LANEX_INIT_BSTS[rx_rst_sm_complete]\n", qlm, lane);
			return -1;
		}
	}
	return 0;
}

/**
 * Wait for GSERNX_LANEX_INIT_BSTS[tx_ready, tx_rst_sm_complete]
 *
 * @param node
 * @param qlm
 * @param qlm_lane
 *
 * @return
 */
int gsern_init_wait_for_tx_ready(int qlm, int qlm_lane)
{
	const int TIMEOUT = 10000; /* Timeout for wait loops in microsec */
	int num_lanes = gsern_qlm_get_lanes(qlm);

	if (gsern_is_platform(GSERN_PLATFORM_ASIM) || gsern_is_platform(GSERN_PLATFORM_EMULATOR))
		return 0;

	for (int lane = 0; lane < num_lanes; lane++)
	{
	   /* Skip lanes we don't care about */
		if ((qlm_lane != -1) && (qlm_lane != lane))
			continue;

		if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane), GSERN_LANE_INIT_BSTS_TX_READY, ==, 1, TIMEOUT))
		{
			gsern_error("N0.QLM%d.Lane%d: Timeout waiting for GSERNX_LANEX_INIT_BSTS[tx_ready]\n", qlm, lane);
			return -1;
		}
		if (GSERN_CSR_WAIT_FOR_FIELD(CAVM_GSERNX_LANEX_INIT_BSTS(qlm, lane), GSERN_LANE_INIT_BSTS_TX_RST_SM_COMPLETE, ==, 1, TIMEOUT))
		{
			gsern_error("N0.QLM%d.Lane%d: Timeout waiting for GSERNX_LANEX_INIT_BSTS[tx_rst_sm_complete]\n", qlm, lane);
			return -1;
		}
	}
	return 0;
}

