/*
 *
 * Copyright (C) 2016-2019 Marvell International Ltd.
 *
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#ifndef __OCTEONTX_ATTESTATION_H__
#define __OCTEONTX_ATTESTATION_H__

/* attestation definitions are shared with U-Boot (see arch-octeontx2/atf.h) */

#define ATTESTATION_MAGIC_ID 0x5f415454 /* "_ATT" */

enum sw_attestation_tlv_type {
	ATT_IMG_INIT_BIN,
	ATT_IMG_ATF_BL1,
	ATT_IMG_BOARD_DT,
	ATT_IMG_LINUX_DT,
	ATT_IMG_SCP_TBL1FW,
	ATT_IMG_MCP_TBL1FW,
	ATT_IMG_AP_TBL1FW,
	ATT_IMG_ATF_BL2,
	ATT_IMG_ATF_BL31,
	ATT_IMG_ATF_BL33,
	ATT_SIG_NONCE,

	ATT_TLV_TYPE_COUNT
};

typedef struct sw_attestation_tlv {
	uint16_t type_be;   /* sw_attestation_tlv_type */
	uint16_t length_be;
	uint8_t value[0];   /* array of 'length_be' bytes */
} __packed sw_attestation_tlv_t;

#define SW_ATT_INFO_NONCE_MAX_LEN  256

typedef struct sw_attestation_info_hdr {
	uint32_t magic_be;
	uint16_t tlv_len_be;
	uint16_t total_len_be;
	uint16_t certificate_len_be;
	uint16_t signature_len_be;
	union {
		sw_attestation_tlv_t tlv_list[0];
		int8_t input_nonce[0];
	};
} __packed sw_attestation_info_hdr_t;

#define SHA256_HASH_DER_LEN 51
#define SHA256_HASH_LEN     32
/*
 * This structure holds the version ID info that is used to populate the
 * S/W attestation info structure.
 *
 * In addition to the image version ID info, this structure also contains
 * a pointer to the FDT (which is the sole, original platform argument).
 *
 * As the boot progresses from BL1 through BL31, each BL component saves
 * the version ID (a HASH) of each authenticated image that it loads.
 * It then passes this structure to the next BL component.
 *
 * A pointer to this structure is passed as the platform argument in the
 * 'argx' field appropriate to each BL component.
 */
typedef struct octeontx_bl_platform_args {
	uint8_t init_bin_sig[SHA256_HASH_LEN];
	uint8_t atf_bl1_sig[SHA256_HASH_LEN];
	uint8_t board_dt_sig[SHA256_HASH_LEN];
	uint8_t linux_dt_sig[SHA256_HASH_LEN];
	uint8_t scp_tbl1fw_sig[SHA256_HASH_LEN];
	uint8_t mcp_tbl1fw_sig[SHA256_HASH_LEN];
	uint8_t ap_tbl1fw_sig[SHA256_HASH_LEN];
	/* BL1 stores BL2 encoded hash; BL2 decodes it & places into 'bl2_sig'.
	 * This removes requirement of adding mbedtls code to BL1.
	 */
	uint8_t atf_bl2_enc_sig[SHA256_HASH_DER_LEN];
	uint8_t atf_bl2_sig[SHA256_HASH_LEN];
	uint8_t atf_bl31_sig[SHA256_HASH_LEN];
	uint8_t atf_bl33_sig[SHA256_HASH_LEN];
	void *fdt;
} octeontx_bl_platform_args_t;

void *attestation_info_base(void);

intptr_t generate_attestation_info(uint64_t nonce_len);

#endif /* __OCTEONTX_ATTESTATION_H__ */

