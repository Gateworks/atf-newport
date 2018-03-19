/** @file

  Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CGX_H__
#define __CGX_H__

/* max channels per lmac */
#define MAX_CHAN_PER_LMAC	16

/* REF values from Octeon TX */

/* Max Packet Size */
#define CGX_MAX_FRAME_SIZE		9216

/* SGMII types */
/* Tx Threshold */
#define CGX_GMP_TX_FIFO_WORDS		0x30

/* Min Packet Size */
#define CGX_GMP_MIN_PACKET_SIZE         (60 - 1)

/* XAUI types */
/* Tx Threshold */
#define CGX_SMUX_TX_FIFO_WORDS		(0x100 - 1)

/* Min Packet Size */
#define CGX_SMUX_MIN_PACKET_SIZE         (60 + 4)

/* delay to wait before reading the CSR again when polling */
#define CGX_POLL_FOR_CSR_DELAY 10

/* software to wait ~1.75 ms when restarting training process as per HRM */
#define CGX_SPUX_TRAINING_RESTART_DELAY 2000

/* Read-Modify-Write APIs for CGX CSRs */
#define CAVM_MODIFY_CGX_CSR(node, type, csr, field, val)        \
	do {                                                    \
		type c;                                         \
		c.u = CSR_READ(node, csr);			\
		c.s.field = val;				\
		CSR_WRITE(node, csr, c.u);			\
	} while (0)

/* Macros to define BIT masks for polling */
#define CGX_GMP_TX_IDLE_MASK		1 << 13
#define CGX_GMP_RX_IDLE_MASK		1 << 12
#define CGX_GMP_PCS_RESET_MASK		1 << 15
#define CGX_GMP_PCS_AN_CPT_MASK		1 << 5
#define CGX_CMRX_RX_FIFO_LEN_MASK	1 << 14
#define CGX_CMRX_TX_IDLE_MASK		1 << 14
#define CGX_SPUX_RESET_MASK		1 << 15
#define CGX_SPUX_BLK_LOCK_MASK		1 << 0
#define CGX_SPUX_RX_ALIGN_MASK		1 << 12
#define CGX_SMUX_RX_STATUS_MASK		3 << 0		/* Bit 0 & 1 */
#define CGX_SMUX_TX_IDLE_MASK		1 << 1
#define CGX_SMUX_RX_IDLE_MASK		1 << 0
#define CGX_SMUX_PCS_RCV_LINK_MASK	1 << 1

/* ERROR MASK based on cgx_err_type */
#define CGX_ERR_MASK			0x3FF		/* 10 bits */

/* structure declarations */
typedef union cgx_link_status {
	uint64_t u64;
	struct cgx_link_status_s {
		uint64_t link_up:1;
		uint64_t full_duplex:1;
		uint64_t speed:4;		/* cgx_link_speed enum */
		uint64_t reserved:58;
	} s;
} link_state_t;

/* this structure will be used to maintain the current
 * link status and also lock mechanism to prevent simultaneous
 * access of CSRs by timer #1 and timer #2 CBs. as, SCRATCHX CSRs
 * have been modified to be opaque, it is not reliable to save
 * the current link status
 */
typedef union cgx_lmac_context {
	uint64_t u64;
	struct cgx_lmac_context_s {
		/* Timer #1 and Timer #2 CB should set lock = 1 (if lock == 0)
		 * before writing to SCRATCHX CSRs and free it after writing
		 * In addition to this lock, ownership status of SCRATCHX(1)
		 * should be checked to make sure kernel is not writing to it
		 */
		uint64_t lock:1;
		/* this variable will be used by timer #2 to poll for the
		 * link periodically as long as this variable is set. updated
		 * by timer #1 callback when there is a LINK UP/DOWN request
		 */
		uint64_t link_enable:1;
		/* internal loopback enable/disable */
		uint64_t lbk1_enable:1;
		/* link status */
		uint64_t link_up:1;
		uint64_t full_duplex:1;
		/* cgx_link_speed */
		uint64_t speed:4;
		/* cgx_error_type */
		uint64_t error_type:10;
		uint64_t reserved:35;
	} s;
} cgx_lmac_context_t;

void cgx_hw_init(int node, int cgx_id);
int cgx_sgmii_set_link_speed(int node, int cgx_id, int lmac_id,
			link_state_t *link);
int cgx_sgmii_set_link_up(int node, int cgx_id, int lmac_id);
int cgx_sgmii_set_link_down(int node, int cgx_id, int lmac_id);

int cgx_xaui_init_link(int node, int cgx_id, int lmac_id);
int cgx_xaui_set_link_up(int node, int cgx_id, int lmac_id);
int cgx_xaui_set_link_down(int node, int cgx_id, int lmac_id);
int cgx_xaui_get_link(int node, int cgx_id, int lmac_id,
		link_state_t *result);
int cgx_rx_equalization(int node, int cgx_id, int lmac_id);
void cgx_set_internal_loopback(int node, int cgx_id, int lmac_id, int enable);
void cgx_set_external_loopback(int node, int cgx_id, int lmac_id, int enable);
void cgx_set_error_type(int node, int cgx_id, int lmac_id, uint64_t type);

/* CGX FW interface APIs */
void cgx_fw_intf_init(void);
void cgx_fw_intf_shutdown(void);


#endif
