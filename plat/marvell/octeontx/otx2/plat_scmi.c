/*
 * Copyright (C) 2018-2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <arch_helpers.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <debug.h>
#include <delay_timer.h>
#include <mmio.h>
#include <plat_board_cfg.h>
#include <octeontx_common.h>
#include <octeontx_utils.h>
#include <plat_scmi.h>

#undef DEBUG_SCMI_ATF

#ifdef DEBUG_SCMI_ATF
#define assert_scmi assert
#else
#define assert_scmi(...) ;
#endif

const uintptr_t plat_get_scmi_mbox_addr()
{
	return CAVM_CPC_RAM_MEMX(AP_SECURE0_TO_XCP_MBOX_OFFSET);
}

const uintptr_t plat_get_scmi_db_addr()
{
	return CAVM_XCPX_DEVX_XCP_MBOX(
			    CAVM_CPC_XCP_MAP_E_SCP,
			    CAVM_XCP_MBOX_DEV_E_AP_SECURE0);
}

/*
 * Private helper function to get exclusive access to SCMI channel.
 */
void scmi_get_channel(scmi_channel_t *ch)
{
	assert_scmi(ch->lock);
	bakery_lock_get(ch->lock);

	/* Make sure any previous command has finished */
	assert_scmi(SCMI_IS_CHANNEL_FREE(
			((mailbox_mem_t *)(ch->info->scmi_mbx_mem))->status));
}

/*
 * Private helper function to transfer ownership of channel from AP to SCP.
 */
void scmi_send_sync_command(scmi_channel_t *ch)
{
	mailbox_mem_t *mbx_mem = (mailbox_mem_t *)(ch->info->scmi_mbx_mem);
	int tries_left = SCMI_GENERIC_TIMEOUT_US;

	SCMI_MARK_CHANNEL_BUSY(mbx_mem->status);

	/*
	 * Ensure that any write to the SCMI payload area is seen by SCP before
	 * we write to the doorbell register. If these 2 writes were reordered
	 * by the CPU then SCP would read stale payload data
	 */
	dmbst();

	SCMI_RING_DOORBELL(ch->info->db_reg_addr, ch->info->db_modify_mask,
					ch->info->db_preserve_mask);

	/*
	 * Ensure that the write to the doorbell register is ordered prior to
	 * checking whether the channel is free.
	 */
	dmbsy();

	/* Wait for channel to be free */
	while (!SCMI_IS_CHANNEL_FREE(mbx_mem->status) && tries_left--)
		udelay(1);

	/*
	 * Ensure that any read to the SCMI payload area is done after reading
	 * mailbox status. If these 2 reads were reordered then the CPU would
	 * read invalid payload data
	 */
	dmbld();

	if (tries_left <= 0) {
		/* In case of SCP timeout, set return value to SCMI_E_GENERIC_ERROR */
		mbx_mem->payload[0] = SCMI_E_GENERIC_ERROR;
		WARN("Timeout waiting for SCP response, SCMI header: 0x%x\n",
		     mbx_mem->msg_header);
	}
}

/*
 * Private helper function to release exclusive access to SCMI channel.
 */
void scmi_put_channel(scmi_channel_t *ch)
{
	/* Make sure any previous command has finished */
	assert_scmi(SCMI_IS_CHANNEL_FREE(
			((mailbox_mem_t *)(ch->info->scmi_mbx_mem))->status));

	assert_scmi(ch->lock);
	bakery_lock_release(ch->lock);
}

/*
 * API to query the SCMI protocol version.
 */
int scmi_proto_version(void *p, uint32_t proto_id, uint32_t *version)
{
	mailbox_mem_t *mbx_mem;
	int token = 0, ret;
	scmi_channel_t *ch = (scmi_channel_t *)p;

	validate_scmi_channel(ch);

	scmi_get_channel(ch);

	mbx_mem = (mailbox_mem_t *)(ch->info->scmi_mbx_mem);
	mbx_mem->msg_header = SCMI_MSG_CREATE(proto_id, SCMI_PROTO_VERSION_MSG,
							token);
	mbx_mem->len = SCMI_PROTO_VERSION_MSG_LEN;
	mbx_mem->flags = SCMI_FLAG_RESP_POLL;

	scmi_send_sync_command(ch);

	/* Get the return values */
	SCMI_PAYLOAD_RET_VAL2(mbx_mem->payload, ret, *version);
	assert_scmi(mbx_mem->len == SCMI_PROTO_VERSION_RESP_LEN);
	assert_scmi(token == SCMI_MSG_GET_TOKEN(mbx_mem->msg_header));

	scmi_put_channel(ch);

	return ret;
}

/*
 * API to query the protocol message attributes for a SCMI protocol.
 */
int scmi_proto_msg_attr(void *p, uint32_t proto_id,
		uint32_t command_id, uint32_t *attr)
{
	mailbox_mem_t *mbx_mem;
	int token = 0, ret;
	scmi_channel_t *ch = (scmi_channel_t *)p;

	validate_scmi_channel(ch);

	scmi_get_channel(ch);

	mbx_mem = (mailbox_mem_t *)(ch->info->scmi_mbx_mem);
	mbx_mem->msg_header = SCMI_MSG_CREATE(proto_id,
				SCMI_PROTO_MSG_ATTR_MSG, token);
	mbx_mem->len = SCMI_PROTO_MSG_ATTR_MSG_LEN;
	mbx_mem->flags = SCMI_FLAG_RESP_POLL;
	SCMI_PAYLOAD_ARG1(mbx_mem->payload, command_id);

	scmi_send_sync_command(ch);

	/* Get the return values */
	SCMI_PAYLOAD_RET_VAL2(mbx_mem->payload, ret, *attr);
	assert_scmi(mbx_mem->len == SCMI_PROTO_MSG_ATTR_RESP_LEN);
	assert_scmi(token == SCMI_MSG_GET_TOKEN(mbx_mem->msg_header));

	scmi_put_channel(ch);

	return ret;
}

/*
 * API to set the SCMI power domain power state.
 */
int scmi_pwr_state_set(void *p, uint32_t domain_id,
					uint32_t scmi_pwr_state)
{
	mailbox_mem_t *mbx_mem;
	int token = 0, ret;

	/*
	 * Only asynchronous mode of `set power state` command is allowed on
	 * application processors.
	 */
	uint32_t pwr_state_set_msg_flag = SCMI_PWR_STATE_SET_FLAG_ASYNC;
	scmi_channel_t *ch = (scmi_channel_t *)p;

	validate_scmi_channel(ch);

	scmi_get_channel(ch);

	mbx_mem = (mailbox_mem_t *)(ch->info->scmi_mbx_mem);
	mbx_mem->msg_header = SCMI_MSG_CREATE(SCMI_PWR_DMN_PROTO_ID,
			SCMI_PWR_STATE_SET_MSG, token);
	mbx_mem->len = SCMI_PWR_STATE_SET_MSG_LEN;
	mbx_mem->flags = SCMI_FLAG_RESP_POLL;
	SCMI_PAYLOAD_ARG3(mbx_mem->payload, pwr_state_set_msg_flag,
						domain_id, scmi_pwr_state);

	scmi_send_sync_command(ch);

	/* Get the return values */
	SCMI_PAYLOAD_RET_VAL1(mbx_mem->payload, ret);
	assert_scmi(mbx_mem->len == SCMI_PWR_STATE_SET_RESP_LEN);
	assert_scmi(token == SCMI_MSG_GET_TOKEN(mbx_mem->msg_header));

	scmi_put_channel(ch);

	return ret;
}

/*
 * API to get the SCMI power domain power state.
 */
int scmi_pwr_state_get(void *p, uint32_t domain_id,
					uint32_t *scmi_pwr_state)
{
	mailbox_mem_t *mbx_mem;
	int token = 0, ret;
	scmi_channel_t *ch = (scmi_channel_t *)p;

	validate_scmi_channel(ch);

	scmi_get_channel(ch);

	mbx_mem = (mailbox_mem_t *)(ch->info->scmi_mbx_mem);
	mbx_mem->msg_header = SCMI_MSG_CREATE(SCMI_PWR_DMN_PROTO_ID,
			SCMI_PWR_STATE_GET_MSG, token);
	mbx_mem->len = SCMI_PWR_STATE_GET_MSG_LEN;
	mbx_mem->flags = SCMI_FLAG_RESP_POLL;
	SCMI_PAYLOAD_ARG1(mbx_mem->payload, domain_id);

	scmi_send_sync_command(ch);

	/* Get the return values */
	SCMI_PAYLOAD_RET_VAL2(mbx_mem->payload, ret, *scmi_pwr_state);
	assert_scmi(mbx_mem->len == SCMI_PWR_STATE_GET_RESP_LEN);
	assert_scmi(token == SCMI_MSG_GET_TOKEN(mbx_mem->msg_header));

	scmi_put_channel(ch);

	return ret;
}

/*
 * API to set the SCMI system power state
 */
int scmi_sys_pwr_state_set(void *p, uint32_t flags, uint32_t system_state)
{
	mailbox_mem_t *mbx_mem;
	int token = 0, ret;
	scmi_channel_t *ch = (scmi_channel_t *)p;

	validate_scmi_channel(ch);

	scmi_get_channel(ch);

	mbx_mem = (mailbox_mem_t *)(ch->info->scmi_mbx_mem);
	mbx_mem->msg_header = SCMI_MSG_CREATE(SCMI_SYS_PWR_PROTO_ID,
			SCMI_SYS_PWR_STATE_SET_MSG, token);
	mbx_mem->len = SCMI_SYS_PWR_STATE_SET_MSG_LEN;
	mbx_mem->flags = SCMI_FLAG_RESP_POLL;
	SCMI_PAYLOAD_ARG2(mbx_mem->payload, flags, system_state);

	scmi_send_sync_command(ch);

	/* Get the return values */
	SCMI_PAYLOAD_RET_VAL1(mbx_mem->payload, ret);
	assert_scmi(mbx_mem->len == SCMI_SYS_PWR_STATE_SET_RESP_LEN);
	assert_scmi(token == SCMI_MSG_GET_TOKEN(mbx_mem->msg_header));

	scmi_put_channel(ch);

	return ret;
}

/*
 * API to get the SCMI system power state
 */
int scmi_sys_pwr_state_get(void *p, uint32_t *system_state)
{
	mailbox_mem_t *mbx_mem;
	int token = 0, ret;
	scmi_channel_t *ch = (scmi_channel_t *)p;

	validate_scmi_channel(ch);

	scmi_get_channel(ch);

	mbx_mem = (mailbox_mem_t *)(ch->info->scmi_mbx_mem);
	mbx_mem->msg_header = SCMI_MSG_CREATE(SCMI_SYS_PWR_PROTO_ID,
			SCMI_SYS_PWR_STATE_GET_MSG, token);
	mbx_mem->len = SCMI_SYS_PWR_STATE_GET_MSG_LEN;
	mbx_mem->flags = SCMI_FLAG_RESP_POLL;

	scmi_send_sync_command(ch);

	/* Get the return values */
	SCMI_PAYLOAD_RET_VAL2(mbx_mem->payload, ret, *system_state);
	assert_scmi(mbx_mem->len == SCMI_SYS_PWR_STATE_GET_RESP_LEN);
	assert_scmi(token == SCMI_MSG_GET_TOKEN(mbx_mem->msg_header));

	scmi_put_channel(ch);

	return ret;
}

/*
 * API to set the SCMI Cavium shutdown configuration
 */
int scmi_octeontx_shutdown_config(void *p, uint32_t board_type, uint32_t shutdown_data)
{
	mailbox_mem_t *mbx_mem;
	int token = 0, ret;
	scmi_channel_t *ch = (scmi_channel_t *)p;

	validate_scmi_channel(ch);

	scmi_get_channel(ch);

	mbx_mem = (mailbox_mem_t *)(ch->info->scmi_mbx_mem);
	mbx_mem->msg_header = SCMI_MSG_CREATE(SCMI_CAVM_CONFIG_PROTO_ID,
			SCMI_CAVM_SHUTDOWN_CONFIG_MSG, token);
	mbx_mem->len = SCMI_CAVM_SHUTDOWN_CONFIG_MSG_LEN;
	mbx_mem->flags = SCMI_FLAG_RESP_POLL;
	SCMI_PAYLOAD_ARG2(mbx_mem->payload, board_type, shutdown_data);

	scmi_send_sync_command(ch);

	/* Get the return values */
	SCMI_PAYLOAD_RET_VAL1(mbx_mem->payload, ret);
	assert_scmi(mbx_mem->len == SCMI_CAVM_SHUTDOWN_CONFIG_RESP_LEN);
	assert_scmi(token == SCMI_MSG_GET_TOKEN(mbx_mem->msg_header));

	scmi_put_channel(ch);

	return ret;
}

/*
 * Private helper to fill up proper structures for CAVM_SHUTDOWN_CONFIG
 */
static int scmi_fill_octeontx_shutdown(octeontx_shutdown_config_type_t *board_type,
				   octeontx_shutdown_config_data_t *data)
{
	/* Check for MCU structure */
	if (plat_octeontx_bcfg->bcfg.mcu_twsi.u != 0) {
		/* Shutdown type is MCU, fill up structures accordingly */
		board_type->s.type = SCMI_CAVM_SHUTDOWN_CONFIG_TYPE_MCU;
		data->u = 0;
		data->mcu_s.node = 0;
		data->mcu_s.int_addr = plat_octeontx_bcfg->bcfg.mcu_twsi.s.int_addr;
		data->mcu_s.bus = plat_octeontx_bcfg->bcfg.mcu_twsi.s.bus;
		data->mcu_s.addr = plat_octeontx_bcfg->bcfg.mcu_twsi.s.addr;
	/* Check for GPIO config */
	} else if (plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_out >= 0) {
		/* Shutdown type is ODM, fill up structures accordingly */
		board_type->s.type = SCMI_CAVM_SHUTDOWN_CONFIG_TYPE_ODM;
		data->u = 0;
		data->odm_s.gpio_shutdown = plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_out;
	} else {
		/* Shutdown configuration not available */
		board_type->s.type = SCMI_CAVM_SHUTDOWN_CONFIG_TYPE_NONE;
		data->u = 0;
	}

	return SCMI_E_SUCCESS;
}

/*
 * API to set the SFP related configuration
 */
int scmi_octeontx_sfp_config(void *p, void *sfp_shmem)
{
	mailbox_mem_t *mbx_mem;
	int token = 0, ret;
	uint32_t lodw, hidw;
	scmi_channel_t *ch = (scmi_channel_t *)p;

	validate_scmi_channel(ch);

	scmi_get_channel(ch);

	mbx_mem = (mailbox_mem_t *)(ch->info->scmi_mbx_mem);
	mbx_mem->msg_header = SCMI_MSG_CREATE(SCMI_CAVM_CONFIG_PROTO_ID,
			SCMI_CAVM_SFP_CONFIG_MSG, token);
	mbx_mem->len = SCMI_CAVM_SFP_CONFIG_MSG_LEN;
	mbx_mem->flags = SCMI_FLAG_RESP_POLL;

	lodw = (uint32_t)octeontx_bit_extract((uint64_t)sfp_shmem, 0, 32);
	hidw = (uint32_t)octeontx_bit_extract((uint64_t)sfp_shmem, 32, 32);
	SCMI_PAYLOAD_ARG2(mbx_mem->payload, lodw, hidw);

	scmi_send_sync_command(ch);

	/* Get the return values */
	SCMI_PAYLOAD_RET_VAL1(mbx_mem->payload, ret);
	assert(mbx_mem->len == SCMI_CAVM_SFP_CONFIG_RESP_LEN);
	assert(token == SCMI_MSG_GET_TOKEN(mbx_mem->msg_header));

	scmi_put_channel(ch);

	return ret;
}

/*
 * SCMI Driver initialization API. Returns initialized channel on success
 * or NULL on error. The return type is an opaque void pointer.
 */
void *scmi_init(scmi_channel_t *ch)
{
	octeontx_shutdown_config_type_t board_type;
	octeontx_shutdown_config_data_t shutdown_data;
	uint32_t version;
	int ret;

	assert_scmi(ch && ch->info);
	assert_scmi(ch->info->db_reg_addr);
	assert_scmi(ch->info->db_modify_mask);
	assert_scmi(ch->info->db_preserve_mask);

	assert_scmi(ch->lock);

	bakery_lock_init(ch->lock);

	ch->is_initialized = 1;

#ifdef SCMI_WITH_LEGACY_PM
	ret = scmi_proto_version(ch, SCMI_PWR_DMN_PROTO_ID, &version);
	if (ret != SCMI_E_SUCCESS) {
		WARN("SCMI power domain protocol version message failed");
		goto error;
	}

	if (!is_scmi_version_compatible(SCMI_PWR_DMN_PROTO_VER, version)) {
		WARN("SCMI power domain protocol version 0x%x incompatible with driver version 0x%x",
			version, SCMI_PWR_DMN_PROTO_VER);
		goto error;
	}

	VERBOSE("SCMI power domain protocol version 0x%x detected\n", version);

	ret = scmi_proto_version(ch, SCMI_SYS_PWR_PROTO_ID, &version);
	if ((ret != SCMI_E_SUCCESS)) {
		WARN("SCMI system power protocol version message failed");
		goto error;
	}

	if (!is_scmi_version_compatible(SCMI_SYS_PWR_PROTO_VER, version)) {
		WARN("SCMI system power management protocol version 0x%x incompatible with driver version 0x%x",
			version, SCMI_SYS_PWR_PROTO_VER);
		goto error;
	}

	VERBOSE("SCMI system power management protocol version 0x%x detected\n",
						version);
#endif

	/* Check for custom Cavium protocol */
	ret = scmi_proto_version(ch, SCMI_CAVM_CONFIG_PROTO_ID, &version);
	if (ret != SCMI_E_SUCCESS) {
		WARN("SCMI Cavium config protocol version message failed");
		goto error;
	}

	if (!is_scmi_version_compatible(SCMI_CAVM_CONFIG_PROTO_VER, version)) {
		WARN("SCMI Cavium config protocol version 0x%x incompatible with driver version 0x%x",
			version, SCMI_CAVM_CONFIG_PROTO_VER);
		goto error;
	}

	VERBOSE("SCMI Cavium config protocol version 0x%x detected\n", version);

	/* Fill up the shutdown structures */
	ret = scmi_fill_octeontx_shutdown(&board_type, &shutdown_data);
	if (ret != SCMI_E_SUCCESS) {
		WARN("SCMI: Incorrect shutdown config\n");
		goto error;
	}

	/* Send actual data to SCP */
	ret = scmi_octeontx_shutdown_config(ch, board_type.u, shutdown_data.u);
	if (ret != SCMI_E_SUCCESS) {
		WARN("SCMI Cavium config protocol - unable to send shutdown config - returned %d\n",
			ret);
		goto error;
	}

	/* This SFP configuration message (shared memory location
	 * which is initialized with the SFP/QSFP slot info  parsed from linux
	 * DT specific per board) is sent over SecureAP-SCP SCMI channel to SCP,
	 * which is then handled by SCP and communicated to MCP. Dedicated
	 * shared memory is used to communicate between SecureAP (ATF) and MCP.
	 */
	sfp_init_shmem();

	ret = scmi_octeontx_sfp_config(ch, (void *)SFP_SHMEM_BASE);
	if (ret != SCMI_E_SUCCESS) {
		WARN("SCMI Cavium config protocol - unable to send SFP config - returned %d\n",
			ret);
		goto error;
	}

	NOTICE("SCMI driver initialized\n");

	return (void *)ch;

error:
	ch->is_initialized = 0;
	return NULL;
}
