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
	uint16_t valid;	/* to be set to 1 after copying data to buf */
	uint8_t buf[SFP_EEPROM_SIZE];
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
};

/* To be synced with linux/drivers/net/ethernet/marvell/octeontx2/af/rvu.h */
struct sh_fwdata {
#define SH_FWDATA_HEADER_MAGIC	0xCFDA	/*Custom Firmware Data*/
#define SH_FWDATA_VERSION	0x0000
	uint32_t header_magic;
	uint32_t version;		/* version id */

	/* MAC address */
#define PF_MACNUM_MAX	32
#define VF_MACNUM_MAX	256
	uint64_t pf_macs[PF_MACNUM_MAX];
	uint64_t vf_macs[VF_MACNUM_MAX];

#define CGX_MAX		3
#define CGX_LMACS_MAX	4
	struct cgx_lmac_fwdata_s cgx_fw_data[CGX_MAX][CGX_LMACS_MAX];
};

static inline uint64_t get_sh_fwdata_base(void)
{
	return SH_FWDATA_BASE;
}

void sh_fwdata_init(void);

#endif
