/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __CGX_INTF_H__
#define __CGX_INTF_H__

#define CGX_FIRMWARE_MAJOR_VER		1
#define CGX_FIRMWARE_MINOR_VER		0

/* CGX error types. set for cmd response status as CGX_STAT_FAIL */
enum cgx_error_type {
	CGX_ERR_NONE,
	CGX_ERR_LMAC_NOT_ENABLED,
	CGX_ERR_LMAC_MODE_INVALID,
	CGX_ERR_REQUEST_ID_INVALID,
	CGX_ERR_PREV_ACK_NOT_CLEAR,
	CGX_ERR_PHY_LINK_DOWN,
	CGX_ERR_PCS_RESET_FAIL,
	CGX_ERR_AN_CPT_FAIL,
	CGX_ERR_TX_NOT_IDLE,
	CGX_ERR_RX_NOT_IDLE,
	CGX_ERR_SPUX_BR_BLKLOCK_FAIL,
	CGX_ERR_SPUX_RX_ALIGN_FAIL,
	CGX_ERR_SPUX_TX_FAULT,
	CGX_ERR_SPUX_RX_FAULT,
	CGX_ERR_SPUX_RESET_FAIL,
	CGX_ERR_SPUX_AN_RESET_FAIL,
	CGX_ERR_SPUX_USX_AN_RESET_FAIL,
	CGX_ERR_SMUX_RX_LINK_NOT_OK,
	CGX_ERR_PCS_LINK_FAIL,
	CGX_ERR_TRAINING_FAIL,
	CGX_ERR_RX_EQU_FAIL,
	CGX_ERR_SPUX_BER_FAIL,
	CGX_ERR_SPUX_RSFEC_ALGN_FAIL,
	CGX_ERR_SPUX_MARKER_LOCK_FAIL,	/* = 23 */
	/* FIXME : add more error types when adding support for new modes */
};

/* LINK speed types */
enum cgx_link_speed {
	CGX_LINK_NONE,
	CGX_LINK_10M,
	CGX_LINK_100M,
	CGX_LINK_1G,
	CGX_LINK_2HG,	/* 2.5 Gbps */
	CGX_LINK_5G,
	CGX_LINK_10G,
	CGX_LINK_20G,
	CGX_LINK_25G,
	CGX_LINK_40G,
	CGX_LINK_50G,
	CGX_LINK_80G,
	CGX_LINK_100G,
	CGX_LINK_MAX,
};

/* REQUEST ID types. Input to firmware */
enum cgx_cmd_id {
	CGX_CMD_NONE,
	CGX_CMD_GET_FW_VER,
	CGX_CMD_GET_MAC_ADDR,
	CGX_CMD_SET_MTU,
	CGX_CMD_GET_LINK_STS,		/* optional to user */
	CGX_CMD_LINK_BRING_UP,
	CGX_CMD_LINK_BRING_DOWN,
	CGX_CMD_INTERNAL_LBK,
	CGX_CMD_EXTERNAL_LBK,
	CGX_CMD_HIGIG,
	CGX_CMD_LINK_STAT_CHANGE,
	CGX_CMD_MODE_CHANGE,		/* hot plug support */
	CGX_CMD_INTF_SHUTDOWN,
	CGX_CMD_GET_MKEX_SIZE,
	CGX_CMD_GET_MKEX_PROFILE,
	CGX_CMD_GET_FWD_BASE,		/* get base address of shared FW data */
	CGX_CMD_GET_LINK_MODES,		/* Supported Link Modes */
	CGX_CMD_SET_LINK_MODE,
	CGX_CMD_GET_SUPPORTED_FEC,
	CGX_CMD_SET_FEC,
	CGX_CMD_GET_AN,
	CGX_CMD_SET_AN,
	CGX_CMD_GET_ADV_LINK_MODES,
	CGX_CMD_GET_ADV_FEC,
};

/* async event ids */
enum cgx_evt_id {
	CGX_EVT_NONE,
	CGX_EVT_LINK_CHANGE,
};

/* event types - cause of interrupt */
enum cgx_evt_type {
	CGX_EVT_ASYNC,
	CGX_EVT_CMD_RESP
};

enum cgx_stat {
	CGX_STAT_SUCCESS,
	CGX_STAT_FAIL
};

enum cgx_cmd_own {
	/* default ownership with kernel/uefi/u-boot */
	CGX_OWN_NON_SECURE_SW,
	/* set by kernel/uefi/u-boot after posting a new request to ATF */
	CGX_OWN_FIRMWARE,
};
/* Supported LINK MODE enums
 * Each link mode is a bit mask of these
 * enums which are represented as bits
 * The modes enum is still a FIXME
 */
typedef enum {
	CGX_MODE_SGMII_BIT = 0,
	CGX_MODE_1000_BASEX_BIT,
	CGX_MODE_QSGMII_BIT,
	CGX_MODE_10G_R_BIT,
	CGX_MODE_10G_KR_BIT,
	CGX_MODE_20G_R_BIT,
	CGX_MODE_25G_R_BIT,
	CGX_MODE_25G_KR_BIT,
	CGX_MODE_40G_R4_BIT,
	CGX_MODE_40G_KR4_BIT,
	CGX_MODE_50G_R2_BIT,
	CGX_MODE_50G_KR_BIT,
	CGX_MODE_80G_R4_BIT,
	CGX_MODE_100G_R4_BIT,
	CGX_MODE_100G_KR4_BIT,
	CGX_MODE_XAUI_BIT,
	CGX_MODE_RXAUI_BIT,
	CGX_MODE_USXGMII_BIT,
	CGX_MODE_MAX_BIT /* = 18 */
} cgx_mode_t;

/* scratchx(0) CSR used for ATF->non-secure SW communication.
 * This acts as the status register
 * Provides details on command ack/status, link status, error details
 */

/* CAUTION : below structures are placed in order based on the bit positions
 * For any updates/new bitfields, corresponding structures needs to be updated
 */
struct cgx_evt_sts_s {			/* start from bit 0 */
	uint64_t ack:1;
	uint64_t evt_type:1;		/* cgx_evt_type */
	uint64_t stat:1;		/* cgx_stat */
	uint64_t id:6;			/* cgx_evt_id/cgx_cmd_id */
	uint64_t reserved:55;
};

/* all the below structures are in the same memory location of SCRATCHX(0)
 * value can be read/written based on command ID
 */

/* Resp to command IDs with command status as CGX_STAT_FAIL
 * Not applicable for commands :
 *	CGX_CMD_LINK_BRING_UP/DOWN/CGX_EVT_LINK_CHANGE
 *	check struct cgx_lnk_sts_s comments
 */
struct cgx_err_sts_s {			/* start from bit 9 */
	uint64_t reserved1:9;
	uint64_t type:10;		/* cgx_error_type */
	uint64_t reserved2:35;
};

/* Resp to cmd ID as CGX_CMD_GET_FW_VER with cmd status as CGX_STAT_SUCCESS */
struct cgx_ver_s {			/* start from bit 9 */
	uint64_t reserved1:9;
	uint64_t major_ver:4;
	uint64_t minor_ver:4;
	uint64_t reserved2:47;
};

/* Resp to cmd ID as CGX_CMD_GET_MAC_ADDR with cmd status as CGX_STAT_SUCCESS
 * Returns each byte of MAC address in a separate bit field
 */
struct cgx_mac_addr_s {			/* start from bit 9 */
	uint64_t reserved1:9;
	uint64_t addr_0:8;
	uint64_t addr_1:8;
	uint64_t addr_2:8;
	uint64_t addr_3:8;
	uint64_t addr_4:8;
	uint64_t addr_5:8;
	uint64_t reserved2:7;
};

#ifdef NT_FW_CONFIG
struct cgx_mcam_profile_addr_s {
	uint64_t reserved1:9; /* start from bit 9 */
	uint64_t mcam_addr:55;
};

struct cgx_mcam_profile_sz_s {
	uint64_t reserved1:9; /* start from bit 9 */
	uint64_t mcam_sz:55;
};
#endif

/* Resp to cmd ID - CGX_CMD_LINK_BRING_UP/DOWN, event ID CGX_EVT_LINK_CHANGE
 * status can be either CGX_STAT_FAIL or CGX_STAT_SUCCESS
 * In case of CGX_STAT_FAIL, it indicates CGX configuration failed when
 * processing link up/down/change command. Both err_type and current link status
 * will be updated
 * In case of CGX_STAT_SUCCESS, err_type will be CGX_ERR_NONE and current
 * link status will be updated
 */
struct cgx_lnk_sts_s {
	uint64_t reserved1:9;
	uint64_t link_up:1;
	uint64_t full_duplex:1;
	uint64_t speed:4;	/* cgx_link_speed */
	uint64_t err_type:10;
	uint64_t an:1;		/* Current AN state : enabled/disabled */
	uint64_t fec:2;		/* Current FEC type if enabled, if not 0 */
	uint64_t port:8;	/* Share the current port info if required */
	uint64_t reserved2:28;
};

struct sh_fwd_base_s {
	uint64_t reserved1:9;
	uint64_t addr:55;
};

struct cgx_link_modes_s {
	uint64_t reserved1:9;
	uint64_t modes:55;
};

/* Resp to cmd ID - CGX_CMD_GET_ADV_FEC/CGX_CMD_GET_SUPPORTED_FEC
 * fec : 2 bits
 * typedef enum cgx_fec_type {
 *     CGX_FEC_NONE,
 *     CGX_FEC_BASE_R,
 *     CGX_FEC_RS
 * } fec_type_t;
 */
struct cgx_fec_types_s {
	uint64_t reserved1:9;
	uint64_t fec:2;
	uint64_t reserved2:53;
};

/* Resp to cmd ID - CGX_CMD_GET_AN */
struct cgx_get_an_s {
	uint64_t reserved1:9;
	uint64_t an:1;
	uint64_t reserved2:54;
};

union cgx_rsp_sts {
	/* Fixed, applicable for all commands/events */
	struct cgx_evt_sts_s evt_sts;
	/* response to CGX_CMD_LINK_BRINGUP/DOWN/LINK_CHANGE */
	struct cgx_lnk_sts_s link_sts;
	/* response to CGX_CMD_GET_FW_VER */
	struct cgx_ver_s ver;
	/* response to CGX_CMD_GET_MAC_ADDR */
	struct cgx_mac_addr_s mac_s;
	/* response to CGX_CMD_GET_FWD_BASE */
	struct sh_fwd_base_s fwd_base_s;
	/* response if evt_status = CMD_FAIL */
	struct cgx_err_sts_s err;
	/* response to CGX_CMD_GET_SUPPORTED_FEC */
	struct cgx_fec_types_s supported_fec;
	/* response to CGX_CMD_GET_LINK_MODES */
	struct cgx_link_modes_s supported_modes;
	/* response to CGX_CMD_GET_ADV_LINK_MODES */
	struct cgx_link_modes_s adv_modes;
	/* response to CGX_CMD_GET_ADV_FEC */
	struct cgx_fec_types_s adv_fec;
	/* response to CGX_CMD_GET_AN */
	struct cgx_get_an_s an;
#ifdef NT_FW_CONFIG
	/* response to CGX_CMD_GET_MKEX_SIZE */
	struct cgx_mcam_profile_sz_s prfl_sz;
	/* response to CGX_CMD_GET_MKEX_PROFILE */
	struct cgx_mcam_profile_addr_s prfl_addr;
#endif
};

union cgx_scratchx0 {
	uint64_t u;
	union cgx_rsp_sts s;
};

/* scratchx(1) CSR used for non-secure SW->ATF communication
 * This CSR acts as a command register
 */
struct cgx_cmd {			/* start from bit 2 */
	uint64_t reserved1:2;
	uint64_t id:6;			/* cgx_request_id */
	uint64_t reserved2:56;
};

/* all the below structures are in the same memory location of SCRATCHX(1)
 * corresponding arguments for command Id needs to be updated
 */

/* Any command using enable/disable as an argument need
 * to pass the option via this structure.
 * Ex: Loopback, HiGig...
 */
struct cgx_ctl_args {			/* start from bit 8 */
	uint64_t reserved1:8;
	uint64_t enable:1;
	uint64_t reserved2:55;
};

/* command argument to be passed for cmd ID - CGX_CMD_SET_MTU */
struct cgx_mtu_args {
	uint64_t reserved1:8;
	uint64_t size:16;
	uint64_t reserved2:40;
};

/* command argument to be passed for cmd ID - CGX_CMD_LINK_CHANGE */
struct cgx_link_change_args {		/* start from bit 8 */
	uint64_t reserved1:8;
	uint64_t link_up:1;
	uint64_t full_duplex:1;
	uint64_t speed:4;		/* cgx_link_speed */
	uint64_t reserved2:50;
};

/* command argument to be passed for cmd ID - CGX_CMD_SET_LINK_MODE */
struct cgx_set_mode_args {
	uint64_t reserved1:8;
	uint64_t mode:56;
};

/* command argument to be passed for cmd ID - CGX_CMD_SET_FEC */
struct cgx_set_fec_args {
	uint64_t reserved1:8;
	uint64_t fec:2;
	uint64_t reserved2:54;
};

union cgx_cmd_s {
	uint64_t own_status:2;			/* cgx_cmd_own */
	struct cgx_cmd cmd;
	struct cgx_ctl_args cmd_args;
	struct cgx_mtu_args mtu_size;
	struct cgx_link_change_args lnk_args;	/* Input to CGX_CMD_LINK_CHANGE */
	struct cgx_set_mode_args mode_args;
	struct cgx_set_fec_args fec_args;
	/* any other arg for command id * like : mtu, dmac filtering control */
};

union cgx_scratchx1 {
	uint64_t u;
	union cgx_cmd_s s;
};

#endif
