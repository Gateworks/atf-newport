/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PHY_MGMT_H__
#define __PHY_MGMT_H__

/* IEEE 802.3 spec CLAUSE 45 MDIO access
 * PMA/PMD control reg bits 6 & 13 determine
 * speed sel
 * 6 13
 * 1 1 = bits 5:2 select speed
 * 1 0 = 1000 Mb/s
 * 0 1 = 100 Mb/s
 * 0 0 = 10 Mb/s
 */
#define PHY_CLAUSE45_SPEED_10M		0x0000
#define PHY_CLAUSE45_SPEED_100M		0x0040
#define PHY_CLAUSE45_SPEED_1G		0x2000
#define PHY_CLAUSE45_SPEED_BITS_2_5_SEL	0x2040
#define PHY_CLAUSE45_SPEED_SEL_MASK	PHY_CLAUSE45_SPEED_BITS_2_5_SEL
#define PHY_CLAUSE45_MAX_SPEED_SEL	0xF

/* IEE 802.3 spec : CLAUSE 45 registers */
#define PMA_PMD_DEVICE_ADDR		1
#define PMA_PMD_CONTROL_REG		0
#define PMA_PMD_STATUS_REG		1

/* IEEE 802.3 spec : CLAUSE 22 registers */
#define MII_CONTROL_REG			0
#define MII_STATUS_REG			1
#define MII_PHY_ID1_REG			2
#define MII_PHY_ID2_REG			3
#define MII_AUTONEG_ADV_REG		4
#define MII_88E1514_STATUS_REG		17
#define MII_88E1548_STATUS_REG		17
#define MII_88E1548_GENERAL_CONTROL_1	20	/* page 18 */
#define MII_MARVELL_22_PAGE_REG		22	/* Clause 22 page register */

/* PHY Identifies for various PHYs supported */
#define PHY_VSC8574_ID1			0x0007
#define PHY_VSC8574_ID2			0x04A2

/* PHY flags */
#define PHY_FLAG_SUPPORTS_CHANGING_MOD_TYPE 1

/* PHY modulation types */
typedef enum phy_mod_type {
	PHY_MOD_TYPE_NRZ,
	PHY_MOD_TYPE_PAM4,
} phy_mod_type;

/* PHY types */
typedef enum phy_type {
	PHY_NONE = 0,
	PHY_MARVELL_88E1548,
	PHY_MARVELL_5123,
	PHY_MARVELL_5113,
	PHY_MARVELL_6141,
	PHY_MARVELL_88E1514,
	PHY_VITESSE_8574,
	PHY_GENERIC_8023_C22,
	PHY_GENERIC_8023_C45,
} phy_type_t;

/* Type of GPIO pin */
typedef enum {
	PHY_MUX_GPIO_PIN_NONE = 0,
	/* GPIO pin is directly connected to SoC */
	PHY_MUX_GPIO_PIN_DEFAULT,
	/* If the pin is controlled via CPLD */
	PHY_MUX_GPIO_PIN_CPLD
} phy_mux_type_t;

/* Media type for vsc8574 */
typedef enum phy_vsc8574_media_mode {
	PHY_MEDIA_COPPER = 0,
	PHY_MEDIA_1000BX,
	PHY_MEDIA_100FX
} phy_vsc8574_media_mode_t;

#ifdef MARVELL_PHY_1548
typedef enum phy_88e1548_media_mode {
	PHY_MEDIA_QSGMII_TO_COPPER = 0,
	PHY_MEDIA_SGMII_TO_COPPER,
	PHY_MEDIA_QSGMII_TO_1000BASE_X,
	PHY_MEDIA_QSGMII_TO_100BASE_FX,
	PHY_MEDIA_QSGMII_TO_SGMII,
	PHY_MEDIA_SGMII_TO_QSGMII,
	PHY_MEDIA_QSGMII_TO_AUTO_COPPER_SGMII,
	PHY_MEDIA_QSGMII_TO_AUTO_COPPER_1000BASE_X,
} phy_88e1548_media_mode_t;

typedef enum phy_88e1548_media_preference {
	PHY_PREFERENCE_FIRST_MEDIA = 0,
	PHY_PREFERENCE_COPPER,
	PHY_PREFERENCE_FIBER
} phy_88e1548_media_preference_t;
#endif

typedef struct phy_compat {
	char compatible[64];	/* compatible string */
	int phy_type;		/* phy_type_t */
} phy_compatible_type_t;

typedef struct phy_drv {
	char drv_name[64];
	int drv_type;
	int flags;	/* Any specific info about the PHY */
	void (*probe)(int cgx_id, int lmac_id); /* Function pointer to initialize PHY */
	void (*reset)(int cgx_id, int lmac_id); /* Function pointer to reset PHY */
	void (*config)(int cgx_id, int lmac_id); /* Function pointer to set mode of PHY */
	void (*set_an)(int cgx_id, int lmac_id); /* Function pointer to configure AN */
	void (*get_link_status)(int cgx_id, int lmac_id, link_state_t *link); /* Function pointer to get link status of PHY */
	void (*shutdown)(int cgx_id, int lmac_id); /* Function pointer to shutdown PHY */
	/* Function pointer to obtain supported modes */
	void (*set_supported_modes)(int cgx_id, int lmac_id);
} phy_drv_t;

typedef struct phy_config {
	int type;
	int addr;	/* PHY ADDR on MDIO bus */
	int mdio_bus;	/* SMI bus number */
	int mux_switch; /* If controlled via switch. Ex: Analog switch on EBB9604 */
	int media_type; /* Optional : Required for VSC8574 */
	int port;	/* Optional : Port num for 88x5123/88x5113 */
	int valid;	/* If valid PHY driver found */
	int init;	/* Whether Initialization is already performed */
	phy_mod_type mod_type; /* Line-side modulation type */
	phy_drv_t *drv; /* struct for PHY driver operations */
	void *priv;
	gpio_info_t mux_info; /* Details of switch details if MDIO is muxed */
	int last_page;	/* Last page selected for Marvell 88E15xx Clause 22 */
	uint64_t supported_link_modes;
	int forceconfig;
#ifdef MARVELL_PHY_1548
	phy_88e1548_media_mode_t marvell_88e1548_mode;
	phy_88e1548_media_preference_t marvell_88e1548_media_pref;
	int last_copper; /* True if last link up was copper, used for polling */
#endif
} phy_config_t;

/* APIs */
void phy_probe(int cgx_id, int lmac_id);
int phy_get_link_status(int cgx_id, int lmac_id, link_state_t *link);
void phy_config(int cgx_id, int lmac_id);
void phy_register(int cgx_id, int lmac_id, phy_drv_t *phy_drv);
void phy_lookup(int cgx_id, int lmac_id, int type);
int phy_mdio_read(phy_config_t *phy, int mode, int devad, int reg);
void phy_mdio_write(phy_config_t *phy, int mode, int devad, int reg, int val);
void phy_set_switch(phy_config_t *phy, int enable);
int phy_set_mod_type(int cgx_id, int lmac_id, phy_mod_type mod_type);
void phy_set_supported_link_modes(int cgx_id, int lmac_id);
void phy_reset(int cgx_id, int lmac_id);

/* Generic PHY driver APIs to be exposed to other PHY drivers */
void phy_generic_probe(int cgx_id, int lmac_id);
void phy_generic_reset(int cgx_id, int lmac_id);
void phy_generic_shutdown(int cgx_id, int lmac_id);
void phy_generic_config(int cgx_id, int lmac_id);
void phy_generic_set_an(int cgx_id, int lmac_id);
void phy_generic_c45_get_link_status(int cgx_id, int lmac_id, link_state_t *link);
void phy_generic_c22_get_link_status(int cgx_id, int lmac_id, link_state_t *link);

phy_drv_t *phy_marvell_drv_lookup(int type);
phy_drv_t *phy_generic_drv_lookup(int type);
phy_drv_t *phy_vitesse_drv_lookup(int type);
#endif /* __CAVM_PHY_MGMT_H__ */
