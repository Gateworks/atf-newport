/** @file
 *
 * Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
 * This program and the accompanying materials
 * are licensed and made available under the terms and conditions of the BSD
 * License which accompanies this distribution.  The full text of the license
 * may be found at http://opensource.org/licenses/bsd-license.php
 *
 * THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
 * WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED.
 *
 */
#ifndef __CAVM_PHY_MGMT_H__
#define __CAVM_PHY_MGMT_H__

#define SFP_MAX_EEPROM_SIZE	0x100

#define SFP_EEPROM_I2C_ADDR	0x50

/* From PCA9535PW data sheet. */
#define GPIO_REG_PCA9535_IN(x)		((x < 8) ? 0 : 1)
#define GPIO_REG_PCA9535_OUT(x)		((x < 8) ? 2 : 3)
#define GPIO_REG_PCA9535_INVERT(x)	((x < 8) ? 4 : 5)
#define GPIO_REG_PCA9535_DIR(x)		((x < 8) ? 6 : 7)

/* GPIO flags associated with a pin. */
typedef enum {
	GPIO_ACTIVE_HIGH = 0,		/* Active high */
	GPIO_ACTIVE_LOW = 1,		/* Active low */
	GPIO_OPEN_COLLECTOR = 2,	/* Output is open-collector */
} sfp_gpio_flags_e;

/* Type of GPIO pin */
typedef enum {
	GPIO_PIN_DEFAULT,	/* GPIO pin is directly connected to SoC */
	GPIO_PIN_PCA9535,	/* GPIO pin is PCA9535 expander */
	GPIO_PIN_PCA9555,	/* GPIO pin is PCA9555 expander */
	GPIO_PIN_PCA9552,	/* GPIO pin is PCA9552 LED driver */
	GPIO_PIN_OTHER,
} sfp_gpio_type_e;

/* Type of i2c bus */
typedef enum {
	I2C_BUS_DEFAULT,
	I2C_MUX_PCA9546,	/* I2C switch */
	I2C_MUX_PCA9548,	/* I2C switch */
	I2C_MUX_OTHER
} sfp_i2c_bus_type_e;

typedef struct sfp_i2c_info {
	uint8_t addr;
	uint8_t channel;
	uint8_t enable_bit;
	uint8_t is_mux;
	uint8_t bus;
	uint8_t mux_id;
	uint8_t eeprom_addr;
	sfp_i2c_bus_type_e type;
} sfp_i2c_info_t;

typedef struct sfp_gpio_info {
	int pin;			/* Pin Number */
	int num_pins;			/* Total pins supported by the controller */
	int i2c_addr;			/* Controller I2C address */
	int i2c_bus;			/* TWSI bus */
	int dir_out;
	int dir_in;
	sfp_gpio_type_e type;
	sfp_gpio_flags_e flags;
	sfp_i2c_info_t i2c_info;
} sfp_gpio_info_t;

/* Connector type for module */
typedef enum {
	SFP_CONN_UNKNOWN = 0x00,	/* Unknown or Unspecified */
	SFP_CONN_SFP = 0x03,		/* SFP/SFP+/SFP28 */
	SFP_CONN_QSFP = 0x0C,		/* QSFP */
	SFP_CONN_QSFPP = 0x0D,		/* QSFP+ */
	SFP_CONN_QSFP28 = 0x11,		/* QSFP28 */
} sfp_conn_type_e;

/* Module type plugged into a SFP/SFP+/QSFP+ port */
typedef enum {
	SFP_MOD_UNKNOWN = 0,		/* Unknown or unspecified */
	SFP_MOD_SC = 0x1,		/* Subscriber Connector */
	SFP_MOD_OPTICAL_LC = 0x7,	/* Fiber optic module (LC connector) */
	SFP_MOD_OPTICAL_PIGTAIL = 0xB,	/* Fiber optic module (pigtail, no connector) */
	SFP_MOD_COPPER_PIGTAIL = 0x21,	/* copper module */
	SFP_MOD_RJ45 = 0x22,		/* RJ45 (i.e. 10GBase-T) */
	SFP_MOD_NO_SEP_CONN = 0x23,	/* No separable connector (SFP28/copper) */
	SFP_MOD_OTHER			/* Unknown/other module type */
} sfp_mod_type_e;

/* Peak rate supported by SFP cable. */
typedef enum {
	SFP_RATE_UNKNOWN,	/* Unknown rate */
	SFP_RATE_1G,		/* 1Gbps */
	SFP_RATE_10G,		/* 10Gbps */
	SFP_RATE_25G,		/* 25Gbps */
	SFP_RATE_40G,		/* 40Gbps */
	SFP_RATE_100G		/* 100Gbps */
} sfp_rate_e;

/* Cable compliance specification
 * See table 4-4 from SFF-8024 for the extended specification compliance codes
 */
typedef enum {
	SFP_CABLE_UNSPEC = 0,
	/* Active optical cables. */
	SFP_CABLE_100G_AOC = 0x01,
	SFP_CABLE_100G_SR4 = 0x2,
	SFP_CABLE_100G_LR4 = 0x3,
	SFP_CABLE_100G_ER4 = 0x4,
	SFP_CABLE_100G_SR10 = 0x5,
	SFP_CABLE_100G_CWDM4_MSA = 0x6,
	SFP_CABLE_100G_PSM4 = 0x7,
	SFP_CABLE_100G_ACC = 0x8,
	SFP_CABLE_100G_CWDM4 = 0x9,
	SFP_CABLE_100G_CR4 = 0xB,
	SFP_CABLE_25G_CR_CA_S = 0xC,
	SFP_CABLE_25G_CR_CA_N = 0xD,
	SFP_CABLE_40G_ER4 = 0x10,
	SFP_CABLE_4X10G_SR = 0x11,
	SFP_CABLE_40G_PSM4 = 0x12,
	SFP_CABLE_G959_1_P1I1_2D1 = 0x13,
	SFP_CABLE_G959_1_P1S1_2D2 = 0x14,
	SFP_CABLE_G959_1_P1L1_2D2 = 0x15,
	SFP_CABLE_10GBASE_T = 0x16,
	SFP_CABLE_100G_CLR4 = 0x17,
	SFP_CABLE_100G_AOC_LOW_BER = 0x18,
	SFP_CABLE_100G_ACC_LOW_BER = 0x19
} sfp_cable_ext_compliance_e;

/* Optical modes module is compliant with. */
typedef enum {
	SFP_CABLE_10GBASE_ER = 0x80,	/* 10G ER */
	SFP_CABLE_10GBASE_LRM = 0x40,	/* 10G LRM */
	SFP_CABLE_10GBASE_LR = 0x20,	/* 10G LR */
	SFP_CABLE_10GBASE_SR = 0x10	/* 10G SR */
} sfp_10g_eth_compliance_e;

/* Diagnostic ASIC compatibility. */
typedef enum {
	SFP_SFF_8472_NO_DIAG = 0x00,
	SFP_SFF_8472_REV_9_3 = 0x01,
	SFP_SFF_8472_REV_9_5 = 0x02,
	SFP_SFF_8472_REV_10_2 = 0x03,
	SFP_SFF_8472_REV_10_4 = 0x04,
	SFP_SFF_8472_REV_11_0 = 0x05,
	SFP_SFF_8472_REV_11_3 = 0x06,
	SFP_SFF_8472_REV_11_4 = 0x07,
	SFP_SFF_8472_REV_12_0 = 0x08,
	SFP_SFF_8472_REV_UNALLOCATED = 0xff
} sff_8472_diag_rev_e;

/* Data structure describing the current SFP or QSFP EEPROM. */
typedef struct sfp_mod_info {
	sfp_conn_type_e conn_type;			/* Connector type */
	sfp_mod_type_e mod_type;			/* Module type */
	sfp_rate_e rate;				/* Rate of module */
	sfp_10g_eth_compliance_e eth_comp;		/* 10G Ethernet Compliance codes (logical OR) */
	sfp_cable_ext_compliance_e cable_comp;		/* Extended Cable compliance */
	uint8_t vendor_name[17];				/* Module vendor name */
	uint8_t vendor_oui[3];					/* Vendor OUI */
	uint8_t vendor_pn[17];					/* Vendor part number */
	uint8_t vendor_rev[5];					/* Vendor revision */
	uint8_t vendor_sn[17];					/* Vendor serial number */
	uint8_t date_code[9];					/* Date code */
	uint8_t valid;						/* True if module is valid */
	uint8_t active_cable;					/* False for passive copper */
	uint8_t copper_cable;					/* True if cable is copper */
	uint8_t limiting;					/* True if module is limiting (not passive copper) */
	int max_copper_cable_len;				/* Maximum length of copper cable in meters */
	int max_single_mode_cable_length;			/* Max single mode cable length in meters */
	int max_50um_om2_cable_length;				/* Max 50um OM2 cable length */
	int max_62_5um_om1_cable_length;			/* Max 62.5um OM1 cable length */
	int max_50um_om4_cable_length;				/* Max 50um OM4 cable length */
	int max_50um_om3_cable_length;				/* Max 50um OM3 cable length */
	int bitrate_min;					/* Minimum bitrate in Mbps */
	int bitrate_max;					/* Maximum bitrate in Mbps */
	/* Set to true if forward error correction is required,
	 * for example, a 25GBase-CR CA-S cable.
	 *
	 * FEC should only be disabled at 25G with CA-N cables.  FEC is required
	 * with 5M and longer cables.
	 */
	uint8_t fec_required;
	uint8_t linear_rx_output;				/* True if RX output is linear */
	int power_level;					/* Power level, can be 1, 2 or 3 */
	uint8_t cooled_laser;					/* False - conventional cooling; true - active cooling */
	uint8_t internal_cdr;					/* Internal retimer or clock and data recovery circuit */
	uint8_t los_implemented;				/* True if LoS is implemented */
	uint8_t los_inverted;					/* True if LoS is inverted from the standard */
	uint8_t tx_fault_implemented;				/* True if TX_FAULT is implemented */
	uint8_t tx_disable_implemented;				/* True if TX_DISABLE is implemented */
	uint8_t rate_select_implemented;			/* True if RATE_SELECT is implemented */
	uint8_t tuneable_transmitter;				/* True if tuneable transmitter technology is used */
	uint8_t rx_decision_threshold_implemented;		/* True if receiver decision threshold is implemented */
	uint8_t diag_monitoring;				/* True if diagnostic monitoring present */
	uint8_t diag_paging;					/* True if diagnostic address 0x7f is used */
	sff_8472_diag_rev_e diag_rev;				/* Diagnostic feature revision */
	uint8_t diag_addr_change_required;			/* True if an address change sequence is required */
	uint8_t diag_rx_power_averaged;				/* True if RX power is averaged, false if OMA */
	uint8_t diag_externally_calibrated;			/* True if diagnostics are externally calibrated */
	uint8_t diag_internally_calibrated;			/* True if diagnostics are internally calibrated */
	uint8_t diag_soft_rate_select_control;			/* Soft rate select control implemented per SFF-8431 */
	uint8_t diag_app_select_control;			/* Application select control implemented per SFF-8079 */
	uint8_t diag_soft_rate_select_implemented;		/* Soft RATE_SELECT control and moonitoring implemented */
	uint8_t diag_soft_rx_los_implemented;			/* True if soft RX_LOS monitoring implemented */
	uint8_t diag_soft_tx_fault_implemented;			/* True if soft TX_FAULT monitoring implemented */
	uint8_t diag_soft_tx_disable_implemented;		/* Soft TX_DISABLE control and monitoring implemented */
	uint8_t diag_alarm_warning_flags_implemented;		/* True if alarm/warning flags implemented */
} sfp_mod_info_t;

/* This structure contains the tap values to use for various cable lengths */
typedef struct phy_vsc7224_tap {
	uint16_t len;		/* Starting cable length for tap values */
	uint16_t main_tap;	/* Main tap value to use */
	uint16_t pre_tap;	/* Pre-tap value to use */
	uint16_t post_tap;	/* Post-tap value to use */
} phy_vsc7224_tap_t;

typedef struct phy_vsc7224_chan {
	int lane;
	uint8_t is_tx;			/* True if is transmit channel */
	uint8_t maintap_disable;	/* True to disable the main tap */
	uint8_t pretap_disable;		/* True to disable pre-tap */
	uint8_t posttap_disable;	/* True to disable post-tap */
	int num_taps;			/* Number of tap values */
	phy_vsc7224_tap_t taps[6];	/* For now, consider 6 TAPS as max */
} phy_vsc7224_chan_t;

/* Data structure for Microsemi VSC7224 reclocking chip */
typedef struct phy_vsc7224 {
	const char *name;
	phy_vsc7224_chan_t channel[4];
	sfp_i2c_info_t i2c_bus;
	int i2c_addr;
} phy_vsc7224_t;

/* Data structure for the SFP slots */
typedef struct sfp_slot_info {
	const char *name;
	sfp_mod_info_t sfp_mod_info;
	sfp_i2c_info_t i2c_eeprom_info;		/* for EEPROM */
	sfp_gpio_info_t tx_disable;
	sfp_gpio_info_t mod_abs;
	sfp_gpio_info_t tx_error;
	sfp_gpio_info_t los;
	int last_mod_abs;
	uint8_t is_qsfp;			/* sfp or qsfp */
} sfp_slot_info_t;

typedef struct phy_timer_mapping_s {
	int node;
	int cgx_idx;
	int lmac_idx;
	int lmac_type;
	int start;
	int timer;
} phy_timer_mapping_t;

#endif /* __CAVM_PHY_MGMT_H__ */
