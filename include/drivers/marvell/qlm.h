/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef _QLM_H_
#define _QLM_H_

/*
 * Define different QLM-MODE variants. These definitions based on the BDK code.
 */
typedef enum {
	/* QLM is disabled (all chips) */
	QLM_MODE_DISABLED,
	/* PCIe modes  */
	/* 1 PCIe, 1 lane. Other lanes unused */
	QLM_MODE_PCIE_1X1,
	/* 1 PCIe, 2 lanes */
	QLM_MODE_PCIE_1X2,
	/* 1 PCIe, 4 lanes */
	QLM_MODE_PCIE_1X4,
	/* 1 PCIe, 8 lanes */
	QLM_MODE_PCIE_1X8,
	/* 1 PCIe, 16 lanes (CN93XX) */
	QLM_MODE_PCIE_1X16,
	/* SATA modes  */
	/* SATA, each lane independent (CN81xx) */
	QLM_MODE_SATA,
	/* BGX / CGX modes */
	/* SGMII, each lane independent (CN81xx) */
	QLM_MODE_SGMII,
	/* 1000BASE-X, each lane independent */
	QLM_MODE_1G_X,
	/* QSGMII is 4 SGMII on one lane (CN81xx) */
	QLM_MODE_QSGMII,
	/* 1 XAUI or DXAUI, 4 lanes (CN81xx), use gbaud to tell difference */
	QLM_MODE_XAUI,
	/* 2 RXAUI, 2 lanes each (CN81xx) */
	QLM_MODE_RXAUI,
	/* 4 XFI, 1 lane each (CN81xx) */
	QLM_MODE_XFI,
	/* 4 SFI, 1 lane each (CN93xx) */
	QLM_MODE_SFI,
	/* 1 XLAUI chip-to-chip, 4 lanes each (CN81xx) */
	QLM_MODE_XLAUI,
	/* 1 XLAUI chip-to-module, 4 lanes each (CN93xx) */
	QLM_MODE_XLAUI_C2M,
	/* 4 10GBASE-KR, 1 lane each (CN81xx) */
	QLM_MODE_10G_KR,
	/* 1 40GBASE-KR4, 4 lanes each (CN83xx) */
	QLM_MODE_40G_KR4,
	/* 20GAUI chip to chip, 1 lane each (CN9XXX) */
	QLM_MODE_20GAUI_C2C,
	/* 20GAUI chip to module, 1 lane each (CN9XXX) */
	QLM_MODE_20GAUI_C2M,
	/* 25G chip-to-chip, 1 lane each (CN93XX QLMs) */
	QLM_MODE_25GAUI_C2C,
	/* 25G chip-to-module, 1 lane each (CN93XX QLMs) */
	QLM_MODE_25GAUI_C2M,
	/* 40GAUI-2 chip to chip, 2 lanes each (CN9XXX) */
	QLM_MODE_40GAUI_2_C2C,
	/* 40GAUI-2 chip to module, 2 lanes each (CN9XXX) */
	QLM_MODE_40GAUI_2_C2M,
	/* 50G chip to chip, 2 lanes each (CN93XX QLMs) */
	QLM_MODE_50GAUI_2_C2C,
	/* 50G chip to module, 2 lanes each (CN93XX QLMs) */
	QLM_MODE_50GAUI_2_C2M,
	/* 80GAUI-2 chip to chip, 4 lanes each (CN9XXX) */
	QLM_MODE_80GAUI_4_C2C,
	/* 80GAUI-2 chip to module, 4 lanes each (CN9XXX) */
	QLM_MODE_80GAUI_4_C2M,
	/* 100G chip-to-chip, 4 lanes each (CN93XX) */
	QLM_MODE_CAUI_4_C2C,
	/* 100G chip-to-module, 4 lanes each (CN93XX) */
	QLM_MODE_CAUI_4_C2M,
	/* 25G max using auto-neg, 1 lane each (CN93XX QLMs) */
	QLM_MODE_25G_AN,
	/* 50G max using auto-neg, 2 lanes each (CN93XX QLMs) */
	QLM_MODE_50G_AN,
	/* 100G max using auto-neg, 4 lanes each (CN93XX) */
	QLM_MODE_100G_AN,
	/* USXGMII, 4 over 1 lane, 10M, 100M, 1G, 2.5G, 5G (CN93XX QLMs) */
	QLM_MODE_USXGMII_4X1,
	/* USXGMII, 2 over 1 lane, 10M, 100M, 1G, 2.5G, 5G, 10G (CN93XX QLMs) */
	QLM_MODE_USXGMII_2X1,
	/*
	 * USXGMII, 1 over 1 lane, 10M, 100M, 1G, 2.5G, 5G, 10G,
	 * 20G (CN93XX QLMs)
	 */
	QLM_MODE_USXGMII_1X1,
	QLM_MODE_LAST,
} octeontx_qlm_modes_t;

/*
 * This structure is stored in GSERNX_LANEX_SCRATCHX to remember the mode of a
 * single lane. Based on the BDK structure;
 */
typedef union {
	uint64_t u;
	struct {
		/* Baudrate of the lane in MHz */
		uint16_t baud_mhz;
		octeontx_qlm_modes_t mode: 8;	/* Mode of the lane */
		uint32_t flags: 8;		/* Mode flags */
		/* Mode is PCIE RC or endpoint, see flags */
		uint32_t pcie: 1;
		uint32_t sata: 1;		/* Mode is SATA */
		/* Mode is supported by CGX, see mode for details */
		uint32_t cgx: 1;
		uint32_t reserved: 29;		/* Reserved for future use */
	} s;
} octeontx_qlm_state_lane_t;

typedef enum {
	OCTEONTX_QLM_MODE_FLAG_NONE = 0,     /* No flags */
	OCTEONTX_QLM_MODE_FLAG_ENDPOINT = 1, /* PCIe in EP instead of RC */
} octeontx_qlm_mode_flags_t;

typedef enum {
	OCTEONTX_QLM_DIRECTION_TX = 1,
	OCTEONTX_QLM_DIRECTION_RX = 2,
	OCTEONTX_QLM_DIRECTION_BOTH = 3,
} octeontx_qlm_direction_t;

typedef enum {
	/* No loopback */
	OCTEONTX_QLM_LOOP_DISABLED,
	/* Loop external data RX->TX (Not supported on CN8XXX) */
	OCTEONTX_QLM_LOOP_SHALLOW,
	/*
	 * Loop internal data TX->RX in analog domain
	 * (Not supported on CN8XXX)
	 */
	OCTEONTX_QLM_LOOP_NEAR_END,
	/* Loop internal data TX->RX in digital domain */
	OCTEONTX_QLM_LOOP_CORE,
} octeontx_qlm_loop_t;

/* QLM APIs */

/*
 * Setup the PEM to either driver or receive reset from PRST based on RC or EP
 *
 * @param pem	Which PEM to setup
 * @param is_endpoint
 *			   Non zero if PEM is a EP
 */
octeontx_qlm_state_lane_t qlm_build_state(octeontx_qlm_modes_t mode,
	int baud_mhz, octeontx_qlm_mode_flags_t flags);

/*
 * Setup the PEM to either driver or receive reset from PRST based on RC or EP
 *
 * @param pem	Which PEM to setuo
 * @param is_endpoint  Non zero if PEM is a EP
 */
void qlm_setup_pem_reset(int pem, int is_endpoint);

/*
 * Put a QLM into hardware reset
 *
 * @param qlm	QLM to use
 *
 * @return Zero on success, negative on failure
 */
int qlm_reset(int qlm);

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
int qlm_enable_prbs(int qlm, int prbs, octeontx_qlm_direction_t dir);

/*
 * Disable PRBS on a QLM
 *
 * @param qlm	QLM to use
 *
 * @return Zero on success, negative on failure
 */
int qlm_disable_prbs(int qlm);

/*
 * Return the number of PRBS errors since PRBS started running
 *
 * @param qlm	QLM to use
 * @param lane   Which lane
 * @param clear  Clear counter after return the current value
 *
 * @return Number of errors
 */
uint64_t qlm_get_prbs_errors(int qlm, int lane, int clear);

/*
 * Inject an error into PRBS
 *
 * @param qlm	QLM to use
 * @param lane   Which lane
 */
void qlm_inject_prbs_error(int qlm, int lane);

/*
 * Enable shallow loopback on a QLM
 *
 * @param qlm	QLM to use
 * @param loop	Type of loopback. Not all QLMs support all modes
 *
 * @return Zero on success, negative on failure
 */
int qlm_enable_loop(int qlm, octeontx_qlm_loop_t loop);

/*
 * Given a valid PEM number, return its speed in Gbaud
 *
 * @param pem	PEM to get speed of
 *
 * @return Speed in Gbaud. Zero if disabled
 */
int qlm_get_gbaud_mhz_pem(int pem);

/*
 * Perform RX equalization on a QLM
 *
 * @param qlm	  QLM to perform RX equalization on
 * @param qlm_lane Lane to use, or -1 for all lanes
 *
 * @return Zero on success, negative if any lane failed RX equalization
 */
int qlm_rx_equalization(int qlm, int qlm_lane);

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
	int tx_cpost, int tx_bs, int tx_unused);

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
	int *tx_cpost, int *tx_bs, int *tx_unused);

/*
 * Some QLM speeds need to override the default tuning parameters
 *
 * @param qlm	  QLM to configure
 * @param lane	 Lane to tune, or -1 for all
 * @param mode	 Desired mode
 * @param baud_mhz Desired speed
 */
void qlm_tune(int qlm, int lane, octeontx_qlm_modes_t mode, int baud_mhz);

/*
 * Called to initialize the GSERN programming API
 */
void qlm_init(void);

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
	octeontx_qlm_mode_flags_t flags);

#endif /* _QLM_H_ */
