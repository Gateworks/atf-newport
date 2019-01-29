/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __SFP_INTF_H__
#define __SFP_INTF_H__

#define SFP_MAX_EEPROM_SIZE	0x100

/* Type of GPIO pin */
typedef enum {
	GPIO_PIN_NONE = 0,
	/* GPIO pin is directly connected to SoC */
	GPIO_PIN_DEFAULT,
	/* GPIO pin is PCA953X expander type. Range of expanders fall under this type */
	GPIO_PIN_PCA953X,
	/* GPIO pin is PCA957X expander type */
	GPIO_PIN_PCA957X,
	/* GPIO pin is PCF857X expander type */
	GPIO_PIN_PCF857X,
	/* 40 pin expander type */
	GPIO_PIN_PCA9698,
	/* GPIO pin is PCA9552 LED driver */
	GPIO_PIN_PCA9552,
	/* Pin is controlled via CPLD(similar to GPIO controller) */
	GPIO_PIN_CPLD,
	GPIO_PIN_OTHER,
} gpio_type_e;

typedef enum i2c_mux_type {
	I2C_SWITCH,
	I2C_MUX,
	I2C_OTHER
} i2c_mux_type_e;

/* Type of i2c bus */
typedef enum {
	I2C_BUS_NONE = 0,
	I2C_BUS_DEFAULT,	/* Directly connected to SoC */
	I2C_BUS_PCA9540,
	I2C_BUS_PCA9542,
	I2C_BUS_PCA9543,
	I2C_BUS_PCA9544,
	I2C_BUS_PCA9545,
	I2C_BUS_PCA9546,
	I2C_BUS_PCA9547,
	I2C_BUS_PCA9548,
	I2C_BUS_OTHER
} i2c_bus_type_e;

typedef struct gpio_compat {
	char compatible[64];		/* compatible string */
	gpio_type_e type;		/* type */
	uint8_t ngpios;			/* max number of pins */
} gpio_compat_t;

typedef struct i2c_compat {
	char compatible[64];		/* Compatible string */
	i2c_bus_type_e type;	/* Device type */
	i2c_mux_type_e mux_type;	/* Mux or Switch */
	uint8_t enable;			/* Enable bit for mux. Each mux have different bit */
	uint8_t size;			/* Max number of channels */
} i2c_compat_t;

typedef struct i2c_info {
	uint8_t addr;			/* Address of the MUX/Switch */
	uint8_t channel;		/* To which channel the slot is connected to */
	uint8_t enable_bit;		/* Enable bit of channel - Varies for MUX */
	uint8_t is_mux;			/* Whether it is a MUX or Switch */
	uint8_t bus;			/* TWSI bus the slot is connected to */
	uint8_t type;			/* Type of MUX/Switch */
} i2c_info_t;

typedef struct gpio_info {
	uint16_t pin;			/* Pin Number */
	uint16_t num_pins;		/* Total pins supported by the Expander */
	uint8_t i2c_addr;		/* Expander's TWSI address */
	uint8_t i2c_bus;		/* TWSI bus Expander is connected to */
	uint8_t dir_out;		/* Direction of the Pin is output */
	uint8_t dir_in;			/* Direction of the Pin is input */
	uint8_t type;			/* Type of Expander */
	uint8_t flags;
	uint16_t reserved;		/* For alignment */
	i2c_info_t i2c_info;	/* details of how the expander is connected to SoC - switch or Mux */
} gpio_info_t;

/* State machine maintain for SFP/QSFP management for communication
 * between AP & MCP
 * sfp_mod_state_info : Module status
 * sfp_data_state_info : EEPROM status
 */
typedef enum sfp_mod_state_info {
	/* Module disconnected */
	SFP_MOD_STATE_ABSENT = 0,
	/* Module connected */
	SFP_MOD_STATE_PRESENT,
	/* Other state */
	SFP_MOD_STATE_OTHER
} sfp_mod_state_info_t;

typedef enum sfp_data_state_info {
	SFP_DATA_STATE_IDLE = 0,
	/* MCP is updating the data (before the read of EEPROM, this state to be set) */
	SFP_DATA_STATE_READ_EEPROM,
	/* MCP read the eeprom data and EEPROM data is valid */
	SFP_DATA_STATE_EEPROM_VALID,
	/* MCP read the eeprom data and data is not valid. MCP should read the
	 * EEPROM again or throw error to user
	 */
	SFP_DATA_STATE_EEPROM_NVAL,
} sfp_data_state_info_t;

/* Data structure for the SFP slot info obtained from DT */
typedef struct sfp_slot_info {
	char name[16];
	uint8_t is_sfp;				/* set when SFP is connected */
	uint8_t is_qsfp;                        /* set when QSFP is connected */
	uint16_t eeprom_addr;			/* TWSI address of EEPROM */
	uint32_t max_power;			/* different power levels in mW */
	i2c_info_t i2c_eeprom_info;		/* TWSI details for EEPROM connection */
	i2c_info_t i2c_diag_info;           /* TWSI details for DIAG connection (if applicable) */
	gpio_info_t tx_disable;             /* SFP : GPIO details for tx_disable pin */
	gpio_info_t mod_abs;                /* SFP : GPIO details for mod_abs pin */
	gpio_info_t tx_fault;               /* SFP : GPIO details for tx_fault */
	gpio_info_t rx_los;                 /* SFP : GPIO details for rx_los */
	gpio_info_t select;                 /* QSFP : GPIO details for ModSelL pin */
	gpio_info_t reset;                  /* QSFP : GPIO details for ResetL pin */
	gpio_info_t lp_mode;                /* QSFP : GPIO details for LPMode */
	gpio_info_t mod_prs;                /* QSFP : GPIO details for ModPrsL */
	gpio_info_t interrupt;              /* QSFP : GPIO details for IntL */
} sfp_slot_info_t;

/* Ownership of shared memory */
typedef enum sfp_own {
	SFP_OWN_NONE = 0,
	SFP_OWN_AP,
	SFP_OWN_MCP
} sfp_own_info_t;

/* Data structures to be shared between AP and MCP */
typedef struct sfp_context {
	uint8_t mod_status;          /* transceiver state, sfp_mod_state_info_t*/
	uint8_t data_status;          /* transceiver data status, sfp_data_state_info_t*/
	uint8_t lock;           /* lock to prevent conflict of access between AP and MCP */
	/* SFF-8419 provides details of these pins */
	uint8_t mod_abs;        /* state of mod_abs pin for SFP */
	uint8_t tx_disable;     /* state of tx_disable pin for SFP */
	uint8_t tx_fault;       /* state of tx_fault pin for SFP */
	uint8_t rx_los;         /* state of rx_los pin for SFP */
	/* SFF-8438 provides details of these pins */
	uint8_t select;         /* state of Select pin for QSFP */
	uint8_t reset;          /* state of reset pin for QSFP */
	uint8_t lp_mode;        /* state of LPmode pin for QSFP */
	uint8_t interrupt;      /* state of Interrupt pin for QSFP */
	uint8_t mod_prs;        /* state of Mod present pin for QSFP */
} sfp_context_t;

/* FIXME: this is not complete list. Add it during implementation of this functionality */
typedef enum sfp_async_req_id {
	SFP_REQ_NONE = 0,
	SFP_REQ_TX_ENABLE,	/* Turn ON transmitter */
	SFP_REQ_TX_DISABLE,	/* Turn OFF transmitter */
	SFP_REQ_SET_POWER_MODE,	/* Set to High/Low Power Mode */
	SFP_REQ_GET_POWER_MODE,	/* Get power mode status */
	SFP_REQ_WRITE_GPIO,	/* To toggle on one of SFP/QSFP GPIO pins */
	SFP_REQ_READ_GPIO,	/* To know the status of SFP/QSFP GPIO pins */
	SFP_REQ_READ_BYTE,	/* To read one of the bytes in EEPROM */
} sfp_req_id_t;

typedef struct sfp_async_req {
	uint32_t req_id;
	/* For ex: which GPIO pin to toggle, which page/byte of EEPROM to read */
	uint32_t req_args;
} sfp_async_req_t;

typedef struct sfp_async_resp {
	uint8_t ack;		/* ack to be set by MCP and clear by AP */
	uint8_t req_stat;	/* 0 indicates fail and 1 indicates success */
	uint16_t err_type;	/* to be set by MCP on error conditions */
	/* FIXME */
	uint32_t data;		/* to return any data if required as a response */
} sfp_async_resp_t;

typedef struct sfp_shared_data {
	char board_model[64];
	uint32_t cgx_id;
	uint32_t lmac_id;
	sfp_slot_info_t sfp_slot;		/* Module info from DT based on board */
	sfp_context_t sfp_ctx;                  /* State machine for SFP/QSFP state */
	uint8_t buf[SFP_MAX_EEPROM_SIZE];	/* SFP/QSFP EEPROM data */
#if 0	/* FIXME */
	sfp_async_req sfp_req;			/* Post Req to MCP sfp_req_id_t */
	sfp_async_rsp sfp_rsp;			/* Receive Response from MCP for request sent */
#endif
} sfp_shared_data_t;

#endif /* __SFP_INTF_H__ */
