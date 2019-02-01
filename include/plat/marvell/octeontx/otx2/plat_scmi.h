/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLAT_SCMI_H__
#define __PLAT_SCMI_H__

#include <bakery_lock.h>
#include <stddef.h>
#include <stdint.h>
#include <mmio.h>

#define SCMI_GENERIC_TIMEOUT_US   36000

/*
 * SCMI power domain management protocol message and response lengths. It is
 * calculated as sum of length in bytes of the message header (4) and payload
 * area (the number of bytes of parameters or return values in the payload).
 */
#define SCMI_PROTO_VERSION_MSG_LEN		4
#define SCMI_PROTO_VERSION_RESP_LEN		12

#define SCMI_PROTO_MSG_ATTR_MSG_LEN		8
#define SCMI_PROTO_MSG_ATTR_RESP_LEN		12

#define SCMI_PWR_STATE_SET_MSG_LEN		16
#define SCMI_PWR_STATE_SET_RESP_LEN		8

#define SCMI_PWR_STATE_GET_MSG_LEN		8
#define SCMI_PWR_STATE_GET_RESP_LEN		12

#define SCMI_SYS_PWR_STATE_SET_MSG_LEN		12
#define SCMI_SYS_PWR_STATE_SET_RESP_LEN		8

#define SCMI_SYS_PWR_STATE_GET_MSG_LEN		4
#define SCMI_SYS_PWR_STATE_GET_RESP_LEN		12

#define SCMI_CAVM_SHUTDOWN_CONFIG_MSG_LEN	12
#define SCMI_CAVM_SHUTDOWN_CONFIG_RESP_LEN	8

#define SCMI_CAVM_SFP_CONFIG_MSG_LEN		12
#define SCMI_CAVM_SFP_CONFIG_RESP_LEN		8

/* SCMI message header format bit field */
#define SCMI_MSG_ID_SHIFT		0
#define SCMI_MSG_ID_WIDTH		8
#define SCMI_MSG_ID_MASK		((1 << SCMI_MSG_ID_WIDTH) - 1)

#define SCMI_MSG_TYPE_SHIFT		8
#define SCMI_MSG_TYPE_WIDTH		2
#define SCMI_MSG_TYPE_MASK		((1 << SCMI_MSG_TYPE_WIDTH) - 1)

#define SCMI_MSG_PROTO_ID_SHIFT		10
#define SCMI_MSG_PROTO_ID_WIDTH		8
#define SCMI_MSG_PROTO_ID_MASK		((1 << SCMI_MSG_PROTO_ID_WIDTH) - 1)

#define SCMI_MSG_TOKEN_SHIFT		18
#define SCMI_MSG_TOKEN_WIDTH		10
#define SCMI_MSG_TOKEN_MASK		((1 << SCMI_MSG_TOKEN_WIDTH) - 1)


/* SCMI mailbox flags */
#define SCMI_FLAG_RESP_POLL	0
#define SCMI_FLAG_RESP_INT	1

/* SCMI power domain protocol `POWER_STATE_SET` message flags */
#define SCMI_PWR_STATE_SET_FLAG_SYNC	0
#define SCMI_PWR_STATE_SET_FLAG_ASYNC	1

/* SCMI helper defines */
#define AP_SECURE0_TO_XCP_MBOX_ADDR	0x58000
#define AP_SECURE0_TO_XCP_MBOX_OFFSET	(AP_SECURE0_TO_XCP_MBOX_ADDR / 0x8)

#define SCMI_AGENT_AP0_SECURE		(0)
#define PLAT_SCMI_DB_MODIFY_MASK	(1 << SCMI_AGENT_AP0_SECURE)
#define PLAT_SCMI_DB_PRESERVE_MASK	(~PLAT_SCMI_DB_MODIFY_MASK)

/*
 * Helper macro to create an SCMI message header given protocol, message id
 * and token.
 */
#define SCMI_MSG_CREATE(protocol, msg_id, token)				\
	((((protocol) & SCMI_MSG_PROTO_ID_MASK) << SCMI_MSG_PROTO_ID_SHIFT) |	\
	(((msg_id) & SCMI_MSG_ID_MASK) << SCMI_MSG_ID_SHIFT) |			\
	(((token) & SCMI_MSG_TOKEN_MASK) << SCMI_MSG_TOKEN_SHIFT))

/* Helper macro to get the token from a SCMI message header */
#define SCMI_MSG_GET_TOKEN(msg)				\
	(((msg) >> SCMI_MSG_TOKEN_SHIFT) & SCMI_MSG_TOKEN_MASK)

/* SCMI Channel Status bit fields */
#define SCMI_CH_STATUS_RES0_MASK	0xFFFFFFFE
#define SCMI_CH_STATUS_FREE_SHIFT	0
#define SCMI_CH_STATUS_FREE_WIDTH	1
#define SCMI_CH_STATUS_FREE_MASK	((1 << SCMI_CH_STATUS_FREE_WIDTH) - 1)

/* Helper macros to check and write the channel status */
#define SCMI_IS_CHANNEL_FREE(status)					\
	(!!(((mmio_read_32((uintptr_t)&status)) >> SCMI_CH_STATUS_FREE_SHIFT) & SCMI_CH_STATUS_FREE_MASK))

#define SCMI_MARK_CHANNEL_BUSY(status)	do {				\
		uint32_t (val) = mmio_read_32((uintptr_t)&status);	\
		assert(SCMI_IS_CHANNEL_FREE(val));			\
		(val) &= ~(SCMI_CH_STATUS_FREE_MASK <<			\
			SCMI_CH_STATUS_FREE_SHIFT);			\
		mmio_write_32((uintptr_t)&status, (val));		\
	} while (0)

/* Helper macros to copy arguments to the mailbox payload */
#define SCMI_PAYLOAD_ARG1(payld_arr, arg1)				\
		mmio_write_32((uintptr_t)&payld_arr[0], arg1)

#define SCMI_PAYLOAD_ARG2(payld_arr, arg1, arg2)	do {		\
		SCMI_PAYLOAD_ARG1(payld_arr, arg1);			\
		mmio_write_32((uintptr_t)&payld_arr[1], arg2);		\
	} while (0)

#define SCMI_PAYLOAD_ARG3(payld_arr, arg1, arg2, arg3)	do {		\
		SCMI_PAYLOAD_ARG2(payld_arr, arg1, arg2);		\
		mmio_write_32((uintptr_t)&payld_arr[2], arg3);		\
	} while (0)

/* Helper macros to read return values from the mailbox payload */
#define SCMI_PAYLOAD_RET_VAL1(payld_arr, val1)				\
		(val1) = mmio_read_32((uintptr_t)&payld_arr[0])

#define SCMI_PAYLOAD_RET_VAL2(payld_arr, val1, val2)	do {		\
		SCMI_PAYLOAD_RET_VAL1(payld_arr, val1);			\
		(val2) = mmio_read_32((uintptr_t)&payld_arr[1]);	\
	} while (0)

#define SCMI_PAYLOAD_RET_VAL3(payld_arr, val1, val2, val3)	do {	\
		SCMI_PAYLOAD_RET_VAL2(payld_arr, val1, val2);		\
		(val3) = mmio_read_32((uintptr_t)&payld_arr[2]);	\
	} while (0)

/* Helper macro to ring doorbell */
#define SCMI_RING_DOORBELL(addr, modify_mask, preserve_mask)	do {	\
		uint32_t db = mmio_read_32(addr) & (preserve_mask);	\
		mmio_write_32(addr, db | (modify_mask));		\
	} while (0)


/* Supported SCMI Protocol Versions */
#define SCMI_PWR_DMN_PROTO_VER			MAKE_SCMI_VERSION(1, 0)
#define SCMI_SYS_PWR_PROTO_VER			MAKE_SCMI_VERSION(1, 0)
#define SCMI_CAVM_CONFIG_PROTO_VER		MAKE_SCMI_VERSION(1, 0)

#define GET_SCMI_MAJOR_VER(ver)			(((ver) >> 16) & 0xffff)
#define GET_SCMI_MINOR_VER(ver)			((ver) & 0xffff)

#define MAKE_SCMI_VERSION(maj, min)	\
			((((maj) & 0xffff) << 16) | ((min) & 0xffff))

/* Macro to check if the driver is compatible with the SCMI version reported */
#define is_scmi_version_compatible(drv, scmi)				\
	((GET_SCMI_MAJOR_VER(drv) == GET_SCMI_MAJOR_VER(scmi)) &&	\
	(GET_SCMI_MINOR_VER(drv) <= GET_SCMI_MINOR_VER(scmi)))

/* SCMI Protocol identifiers */
#define SCMI_PWR_DMN_PROTO_ID			0x11
#define SCMI_SYS_PWR_PROTO_ID			0x12
#define SCMI_CAVM_CONFIG_PROTO_ID		0xb0

/* Mandatory messages IDs for all SCMI protocols */
#define SCMI_PROTO_VERSION_MSG			0x0
#define SCMI_PROTO_ATTR_MSG			0x1
#define SCMI_PROTO_MSG_ATTR_MSG			0x2

/* SCMI power domain management protocol message IDs */
#define SCMI_PWR_STATE_SET_MSG			0x4
#define SCMI_PWR_STATE_GET_MSG			0x5

/* SCMI system power management protocol message IDs */
#define SCMI_SYS_PWR_STATE_SET_MSG		0x3
#define SCMI_SYS_PWR_STATE_GET_MSG		0x4

/* SCMI custom Cavium configuration protocol message IDs */
#define SCMI_CAVM_SHUTDOWN_CONFIG_MSG		0x4
#define SCMI_CAVM_SFP_CONFIG_MSG		0x5

/* Helper structures for Cavium shutdown config command */
#define SCMI_CAVM_SHUTDOWN_CONFIG_TYPE_NONE	0x0
#define SCMI_CAVM_SHUTDOWN_CONFIG_TYPE_MCU	0x1
#define SCMI_CAVM_SHUTDOWN_CONFIG_TYPE_ODM	0x2

typedef union octeontx_shutdown_config_type {
	uint32_t u;
	struct octeontx_shutdown_config_type_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t type		: 2;
		uint32_t reserved	: 30;
#else
		uint32_t reserved	: 30;
		uint32_t type		: 2;
#endif
	} s;
} octeontx_shutdown_config_type_t;

typedef union octeontx_shutdown_config_data {
	uint32_t u;
	struct octeontx_shutdown_config_mcu_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t node		: 8;
		uint32_t int_addr	: 8;
		uint32_t bus		: 8;
		uint32_t addr		: 8;
#else
		uint32_t addr		: 8;
		uint32_t bus		: 8;
		uint32_t int_addr	: 8;
		uint32_t node		: 8;
#endif
	} mcu_s;
	struct octeontx_shutdown_config_odm_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t gpio_shutdown	: 8;
		uint32_t reserved	: 24;
#else
		uint32_t reserved	: 24;
		uint32_t gpio_shutdown	: 8;
#endif
	} odm_s;
} octeontx_shutdown_config_data_t;

/* Helper macros for system power management protocol commands */

/*
 * Macros to describe the bit-fields of the `attribute` of system power domain
 * protocol PROTOCOL_MSG_ATTRIBUTE message.
 */
#define SYS_PWR_ATTR_WARM_RESET_SHIFT		31
#define SCMI_SYS_PWR_WARM_RESET_SUPPORTED	(1U << SYS_PWR_ATTR_WARM_RESET_SHIFT)

#define SYS_PWR_ATTR_SUSPEND_SHIFT		30
#define SCMI_SYS_PWR_SUSPEND_SUPPORTED		(1 << SYS_PWR_ATTR_SUSPEND_SHIFT)

/*
 * Macros to describe the bit-fields of the `flags` parameter of system power
 * domain protocol SYSTEM_POWER_STATE_SET message.
 */
#define SYS_PWR_SET_GRACEFUL_REQ_SHIFT		0
#define SCMI_SYS_PWR_GRACEFUL_REQ		(1 << SYS_PWR_SET_GRACEFUL_REQ_SHIFT)
#define SCMI_SYS_PWR_FORCEFUL_REQ		(0 << SYS_PWR_SET_GRACEFUL_REQ_SHIFT)

/*
 * Macros to describe the `system_state` parameter of system power
 * domain protocol SYSTEM_POWER_STATE_SET message.
 */
#define SCMI_SYS_PWR_SHUTDOWN			0x0
#define SCMI_SYS_PWR_COLD_RESET			0x1
#define SCMI_SYS_PWR_WARM_RESET			0x2
#define SCMI_SYS_PWR_POWER_UP			0x3
#define SCMI_SYS_PWR_SUSPEND			0x4

/* SCMI Error code definitions */
#define SCMI_E_QUEUED			1
#define SCMI_E_SUCCESS			0
#define SCMI_E_NOT_SUPPORTED		-1
#define SCMI_E_INVALID_PARAM		-2
#define SCMI_E_DENIED			-3
#define SCMI_E_NOT_FOUND		-4
#define SCMI_E_OUT_OF_RANGE		-5
#define SCMI_E_BUSY			-6
#define SCMI_E_COMMS_ERROR		-7
#define SCMI_E_GENERIC_ERROR		-8
#define SCMI_E_HARDWARE_ERROR		-9
#define SCMI_E_PROTOCOL_ERROR		-10

/*
 * Private data structure for representing the mailbox memory layout. Refer
 * the SCMI specification for more details.
 */
typedef struct mailbox_mem {
	uint32_t res_a; /* Reserved */
	volatile uint32_t status;
	uint64_t res_b; /* Reserved */
	uint32_t flags;
	volatile uint32_t len;
	uint32_t msg_header;
	uint32_t payload[];
} mailbox_mem_t;

/*
 * SCMI driver platform information. The details of the doorbell mechanism
 * can be found in the SCMI specification.
 */
typedef struct scmi_channel_plat_info {
	/* SCMI mailbox memory */
	uintptr_t scmi_mbx_mem;
	/* The door bell register address */
	uintptr_t db_reg_addr;
	/* The bit mask that need to be preserved when ringing doorbell */
	uint32_t db_preserve_mask;
	/* The bit mask that need to be set to ring doorbell */
	uint32_t db_modify_mask;
} scmi_channel_plat_info_t;

/*
 * Structure to represent an SCMI channel.
 */
typedef struct scmi_channel {
	scmi_channel_plat_info_t *info;
	 /* The lock for channel access */
	bakery_lock_t *lock;
	/* Indicate whether the channel is initialized */
	int is_initialized;
} scmi_channel_t;

/* External Common API */
void *scmi_init(scmi_channel_t *ch);
int scmi_proto_msg_attr(void *p, uint32_t proto_id, uint32_t command_id,
						uint32_t *attr);
int scmi_proto_version(void *p, uint32_t proto_id, uint32_t *version);

/*
 * Power domain protocol commands. Refer to the SCMI specification for more
 * details on these commands.
 */
int scmi_pwr_state_set(void *p, uint32_t domain_id, uint32_t scmi_pwr_state);
int scmi_pwr_state_get(void *p, uint32_t domain_id, uint32_t *scmi_pwr_state);

/*
 * System power management protocol commands. Refer SCMI specification for more
 * details on these commands.
 */
int scmi_sys_pwr_state_set(void *p, uint32_t flags, uint32_t system_state);
int scmi_sys_pwr_state_get(void *p, uint32_t *system_state);

/* SCMI register configuration API */
const uintptr_t plat_get_scmi_mbox_addr();
const uintptr_t plat_get_scmi_db_addr();

/* Private APIs for use within SCMI driver */
void scmi_get_channel(scmi_channel_t *ch);
void scmi_send_sync_command(scmi_channel_t *ch);
void scmi_put_channel(scmi_channel_t *ch);

static inline void validate_scmi_channel(scmi_channel_t *ch)
{
	assert(ch && ch->is_initialized);
	assert(ch->info && ch->info->scmi_mbx_mem);
}

#endif	/* __PLAT_SCMI_H__ */
