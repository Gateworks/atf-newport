/*
 * Copyright (C) 2017-2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#ifndef __SH_FWDATA_H_
#define __SH_FWDATA_H_

#include <rvu.h>

/* CGX related shared firmware data */
struct sfp_eeprom_s {
#define SFP_EEPROM_SIZE 256
	uint16_t sff_id;
	uint8_t buf[SFP_EEPROM_SIZE];
	uint64_t reserved;
};

struct phy_s {
	uint64_t can_change_mod_type : 1;
	uint64_t mod_type            : 1;
};

struct cgx_lmac_fwdata_s {
	/* RO to kernel. FW to set rw_valid as 0 when updating this struct
	 * indicating data is invalid. After copying the data, this bit needs
	 * to be set as 1. only when this bit is 1, kernel should
	 * read this info
	 */
	uint16_t rw_valid;
	uint64_t supported_fec;
	uint64_t supported_an;
	uint64_t supported_link_modes;
	/* only applicable if AN is supported */
	uint64_t advertised_fec;
	uint64_t advertised_link_modes;
	/* Only applicable if SFP/QSFP slot is present */
	struct sfp_eeprom_s sfp_eeprom;
	struct phy_s phy;
#define LMAC_FWDATA_RESERVED_MEM 1023
	uint64_t reserved[LMAC_FWDATA_RESERVED_MEM];

};

/* To be synced with linux/drivers/net/ethernet/marvell/octeontx2/af/rvu.h */
struct sh_fwdata {
#define SH_FWDATA_HEADER_MAGIC	0xCFDA	/*Custom Firmware Data*/
#define SH_FWDATA_VERSION	0x0001
	uint32_t header_magic;
	uint32_t version;		/* version id */

	/* MAC address */
#define PF_MACNUM_MAX	32
#define VF_MACNUM_MAX	256
	uint64_t pf_macs[PF_MACNUM_MAX];
	uint64_t vf_macs[VF_MACNUM_MAX];
	uint64_t sclk;
	uint64_t rclk;
	uint64_t mcam_addr;
	uint64_t mcam_sz;
 #define FWDATA_RESERVED_MEM 1024
	uint64_t reserved[FWDATA_RESERVED_MEM];
	/* Do not add new fields below this line */
#define CGX_MAX		4
#define CGX_LMACS_MAX	4
	struct cgx_lmac_fwdata_s cgx_fw_data[CGX_MAX][CGX_LMACS_MAX];
};

static inline uint64_t get_sh_fwdata_base(void)
{
	return SH_FWDATA_BASE;
}

/* API declarations */
void sh_fwdata_init(void);
void sh_fwdata_update_supported_fec(int cgx_id, int lmac_id);
int sh_fwdata_get_supported_fec(int cgx_id, int lmac_id);
void sh_fwdata_update_eeprom_data(int cgx_id, int lmac_id, uint16_t sff_id);
void sh_fwdata_clear_eeprom_data(int cgx_id, int lmac_id, uint16_t sff_id);
void sh_fwdata_update_phy_mod_type(int cgx_id, int lmac_id);
void sh_fwdata_update_phy_can_change_mod_type(int cgx_id, int lmac_id);

#endif
