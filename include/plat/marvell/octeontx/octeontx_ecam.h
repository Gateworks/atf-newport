/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_ECAM_H__
#define __OCTEONTX_ECAM_H__

#define FALSE 0
#define TRUE 1

#define OCTEONTX_ECAM_MAX_BUS	256
#define OCTEONTX_ECAM_MAX_DEV	32
#define OCTEONTX_ECAM_MAX_FUNC	256

#define ECAM_DOM_MASK		0x3F0000000
#define ECAM_DOM_SHIFT		28
#define ECAM_BUS_MASK		0xFF00000
#define ECAM_BUS_SHIFT		20
/* SHIFT and MASK for DEV is to satisfy both ARI and non-ARI buses */
#define ECAM_DEV_MASK		0xF8000
#define ECAM_DEV_SHIFT		15
#define ECAM_FUNC_MASK		0xFF000
#define ECAM_FUNC_SHIFT		12

#define ECAM_INVALID_PROD_ID	0xFF
#define ECAM_INVALID_PCC_IDL_ID	ECAM_INVALID_PROD_ID
#define ECAM_PROD_SHIFT		8
#define ECAM_INVALID_DEV_ID	((ECAM_INVALID_PROD_ID << ECAM_PROD_SHIFT) | \
					ECAM_INVALID_PCC_IDL_ID)

/*
 * Structure for secure/non-secure settings
 * (in a meaning of BAR0 visibility to non-secure world),
 * for particular ECAM device
 */
union ecam_config {
	uint8_t u;
	struct ecam_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint8_t reserved	: 5; /* For future use */
		uint8_t is_secure	: 1; /*
					      * Flag to indicate if given device
					      * is visible only in secure world.
					      * Default: 0
					      */
		uint8_t is_scp_secure	: 1; /*
					      * Flag to indicate if given device
					      * is visible only to SCP.
					      * Used only on T93, default: 0
					      */
		uint8_t is_mcp_secure	: 1; /*
					      * Flag to indicate if given device
					      * is visible only to MCP.
					      * Used only on T93, default: 0
					      */
#else
		uint8_t is_mcp_secure	: 1;
		uint8_t is_scp_secure	: 1;
		uint8_t is_secure	: 1;
		uint8_t reserved	: 5;
#endif
	} s;
};

typedef union ecam_config ecam_config_t;

/* Structure describing ECAM device */
struct ecam_device {
	uint64_t base_addr;
	unsigned ecam;
	unsigned domain;
	unsigned bus;
	unsigned dev;
	unsigned func;
	ecam_config_t config;
};

/*
 * Callbacks structure which makes calling particular method common
 * for all SoCs (used in ECAM scan and enumeration). Definitions
 * of functions are stored in the SoC-specific directories (t81/t83/t93/f95).
 */
struct ecam_platform_defs {
	int soc_type;
	int (*get_ecam_count)();
	int (*get_domain_count)(struct ecam_device *dev);
	int (*is_domain_present)(struct ecam_device *dev);
	int (*get_secure_settings)(struct ecam_device *dev, uint64_t pconfig);
	uint64_t (*get_dev_config)(struct ecam_device *dev);
	struct ecam_probe_callback *(*get_probes)(void);
	struct ecam_init_callback *(*get_plat_inits)(void);
	int (*is_bus_disabled)(struct ecam_device *dev);
	int (*skip_bus)(struct ecam_device *dev);
	void (*enable_bus)(struct ecam_device *dev);
	void (*disable_bus)(struct ecam_device *dev);
	void (*enable_dev)(struct ecam_device *dev);
	void (*disable_dev)(struct ecam_device *dev);
	void (*enable_func)(struct ecam_device *dev);
	void (*disable_func)(struct ecam_device *dev);
};

/*
 * Callbacks structure used to determine if given device's
 * BAR0 should be hidden from non-secure world.
 */
struct ecam_probe_callback {
	int devid;
	int vendor_id;
	int (*io_probe)(uint64_t);
	int call_count;
};

/*
 * Callbacks structure to initialize
 * particular device in secure world.
 */
struct ecam_init_callback {
	int devid;
	int vendor_id;
	void (*io_init)(uint64_t, uint64_t);
};

/*
 * Structure used for defining devices that should be hidden from
 * non-secure world or SCP/MCP.
 */
struct secure_devices {
	int prodid;
	int devid;
};

struct msix_cap {
    uint8_t cap_ID;
    uint8_t next_pointer;
    uint16_t messagecontrol;
    uint32_t table_offset_and_bir;
    uint32_t message_upper_address;

}__attribute__((__packed__));

struct pcie_config {
    uint16_t         vendor_id;
    uint16_t         devid;
    uint16_t         command;
    uint16_t         status;
    int         revision_id : 8;
    int         class_code : 24;
    int         cache_line_size : 8;
    int         lat_timer : 8;
    int         header_type : 8;
    int         bist : 8;
    uint32_t         baseaddress_reg[6];
    int         card_bus_cis_pointer;
    uint16_t         sub_system_vendor_id;
    uint16_t         sub_system_id;
    int         exp_rom_base_address;
    int         cap_pointer : 8;
    int         res0 : 24;
    int         res1;
    int         intterrupt_line : 8;
    int         intterrupt_pin : 8;
    int         max_gnt : 8;
    int         max_lat : 8;
    int         res2[1008];  /* make it 4K boundary */
} __attribute__((__packed__));

uint64_t get_bar_val(struct pcie_config *pconfig, int bar);
int enable_msix(uint64_t config_base, uint8_t cap_pointer, uint16_t *table_size,
		uint8_t *bir);
void octeontx_pci_init(void);

#endif /* __OCTEONTX_ECAM_H__ */
