/** @file
 *
 * Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
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
#ifndef __CAVM_SFP_MGMT_H__
#define __CAVM_SFP_MGMT_H__

#include <cavm_sfp_intf.h>

#define SFP_EEPROM_I2C_ADDR	0x50

/* expander's ports are organized as N banks of 8 ports each */
#define GPIO_BANK_SZ		8

/* This macro implementation is based
 * on the info for the current expanders that has only
 * support for 8 bits/16 bits
 */
/* From PCA9535 data sheet */
#define GPIO_REG_PCA953X_IN(x)		((x < GPIO_BANK_SZ) ? 0 : 1)
#define GPIO_REG_PCA953X_OUT(x)		((x < GPIO_BANK_SZ) ? 2 : 3)
#define GPIO_REG_PCA953X_INVERT(x)	((x < GPIO_BANK_SZ) ? 4 : 5)
#define GPIO_REG_PCA953X_CFG(x)		((x < GPIO_BANK_SZ) ? 6 : 7)

/* From PCA9575 data sheet */
#define GPIO_REG_PCA957X_IN(x)		((x < GPIO_BANK_SZ) ? 0 : 1)
#define GPIO_REG_PCA957X_INVERT(x)	((x < GPIO_BANK_SZ) ? 2 : 3)
#define GPIO_REG_PCA957X_CFG(x)		((x < GPIO_BANK_SZ) ? 8 : 9)
#define GPIO_REG_PCA957X_OUT(x)		((x < GPIO_BANK_SZ) ? 0xA : 0xB)

/* From PCA9698 data sheet - 40 bits ( 5 banks of 8 ports each)
 * register address is calculated based on division round up
 * reg = macro * (max_pins + (GPIO_BANK_SZ - 1)/GPIO_BANK_SZ
 * reg += pin/GPIO_BANK_SZ;
 */
#define GPIO_REG_PCA9698_IN		0
#define GPIO_REG_PCA9698_OUT		4
#define GPIO_REG_PCA9698_INVERT		8
#define GPIO_REG_PCA9698_DIR		12

/* Connector type for module */
typedef enum {
	SFP_CONN_UNKNOWN = 0x00,	/* Unknown or Unspecified */
	SFP_CONN_SFP = 0x03,		/* SFP/SFP+/SFP28 */
	SFP_CONN_QSFP = 0x0C,		/* QSFP */
	SFP_CONN_QSFPP = 0x0D,		/* QSFP+ */
	SFP_CONN_QSFP28 = 0x11,		/* QSFP28 */
} sfp_conn_type_e;

/* Media type plugged into a SFP/SFP+/QSFP+ port */
typedef enum {
	SFP_MED_UNKNOWN = 0,		/* Unknown or unspecified */
	SFP_MED_MOD_FIBER,
	SFP_MED_TWINAX,
	SFP_MED_NOT_PRESENT
} sfp_media_type_e;

/* FEC capabilities */
typedef enum sfp_fec_mode {
	SFP_FEC_MODE_NONE,
	SFP_FEC_MODE_RS,
	SFP_FEC_MODE_FIRECODE,
	SFP_FEC_MODE_RS_FIRECODE	/* Both RS and FIRECODE FEC modes */
} sfp_fec_mode_t;

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
 * See SFF-8472 Optical and cable variants specification compliance for SFP
 * See SFF-8436 specification compliance for QSFP
 * See table 4-4 from SFF-8024 for the extended specification compliance codes
 */

typedef enum {
	SFP_TRANS_TYPE_NONE,
	SFP_TRANS_TYPE_1G_PCC,	/* 1G Passive copper cable */
	SFP_TRANS_TYPE_1G_ACC,	/* 1G Active copper cable */
	SFP_TRANS_TYPE_1G_LX,
	SFP_TRANS_TYPE_1G_SX,
	SFP_TRANS_TYPE_10G_SR,
	SFP_TRANS_TYPE_10G_LR,
	SFP_TRANS_TYPE_10G_LRM,
	SFP_TRANS_TYPE_10G_ER,
	SFP_TRANS_TYPE_10G_PCC,
	SFP_TRANS_TYPE_10G_ACC,
	SFP_TRANS_TYPE_XLPPI,
	SFP_TRANS_TYPE_40G_LR4,
	SFP_TRANS_TYPE_40G_SR4,
	SFP_TRANS_TYPE_40G_CR4,
	SFP_TRANS_TYPE_100G_AOC,
	SFP_TRANS_TYPE_100G_SR4,
	SFP_TRANS_TYPE_100G_LR4,
	SFP_TRANS_TYPE_100G_ER4,
	SFP_TRANS_TYPE_100G_ACC,
	SFP_TRANS_TYPE_100G_CR4,
	SFP_TRANS_TYPE_4x10G_SR,
	SFP_TRANS_TYPE_25G_CA_N,
	SFP_TRANS_TYPE_25G_ACC_S,
	SFP_TRANS_TYPE_25G_CA_S,
	SFP_TRANS_TYPE_25G_ACC_M,
	SFP_TRANS_TYPE_25G_CA_L,
	SFP_TRANS_TYPE_25G_ACC_L,
	SFP_TRANS_TYPE_25G_SR,
	SFP_TRANS_TYPE_25G_LR,
	SFP_TRANS_TYPE_25G_AOC,
	SFP_TRANS_TYPE_4x10G,
	SFP_TRANS_TYPE_4x25G_CR,
	SFP_TRANS_TYPE_1000_BASET,
	SFP_TRANS_TYPE_10G_BASET,
	SFP_TRANS_TYPE_MULTI_RATE_10G_40G_SR = 0x30,
	SFP_TRANS_TYPE_MULTI_RATE_10G_40G_CR,
	SFP_TRANS_TYPE_MULTI_RATE_10G_40G_LR,
	SFP_TRANS_TYPE_MULTI_RATE_40G_100G_SR,
	SFP_TRANS_TYPE_MULTI_RATE_40G_100G_CR,
	SFP_TRANS_TYPE_MULTI_RATE_40G_100G_LR,
	SFP_TRANS_TYPE_MULTI_RATE_40G_100G_AOC,
	SFP_TRANS_TYPE_UNKNOWN = 0xFF,
} sfp_cable_compliance_e;

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

/* Data structure describing the 256 bytes of SFP EEPROM - SFF8472 SPEC */
typedef struct sfp_mod_info {
	/* 0 : Identifier Type of transceiver (Table 3.2) */
	uint8_t id;
	/* 1 : Extended identifier of type of transceiver (Table 3.3) */
	uint8_t ext_id;
	/* 2 : Connector Code for connector type (Table 3.4) */
	uint8_t connector_type;
	/* 3-10 : Transceiver Code for electronic or optical compatibility (Table 3.5) */
	uint8_t compliance_code[8];
	/* 11 : Encoding Code for high speed serial encoding algorithm (Table 3.6) */
	uint8_t encoding;
	/* 12 : BR, Nominal Nominal signalling rate, units of 100MBd. */
	uint8_t bitrate;
	/* 13 : Rate Identifier Type of rate select functionality (Table 3.6a) */
	uint8_t rate_id;
	/* 14 : Length(SMF,km) Link length supported for single mode fiber, units of km */
	uint8_t smf_1000m;
	/* 15 : Length (SMF) Link length supported for single mode fiber, units of 100 m */
	uint8_t smf_100m;
	/* 16 : Length (50um) Link length supported for 50 um OM2 fiber, units of 10 m */
	uint8_t om2_10m;
	/* 17 : Length (62.5um) Link length supported for 62.5 um OM1 fiber, units of 10 m */
	uint8_t om1_10m;
	/* 18 : Length (cable) Link length supported for copper or direct attach cable, units of m */
	uint8_t dac_1m;
	/* 19 : Length (OM3) Link length supported for 50 um OM3 fiber, units of 10 m */
	uint8_t om3_10m;
	/* 20-35 : Vendor name SFP vendor name (ASCII) */
	char    vendor_name[16];
	/* 36 : Transceiver Code for electronic or optical compatibility (Table 3.5) */
	uint8_t ext_compliance_code;
	/* 37-39 : Vendor OUI SFP vendor IEEE company ID */
	uint8_t vendor_oui[3];
	/* 40-55 : Vendor PN Part number provided by SFP vendor (ASCII) */
	char    vendor_pn[16];
	/* 56-59 : Vendor rev Revision level for part number provided by vendor (ASCII) */
	char    vendor_rev[4];
	/* 60-61 : Wavelength Laser wavelength (Passive/Active Cable Specification Compliance) */
	uint8_t wavelen[2];
	/* 62 : Unallocated */
	uint8_t reserved;
	/* 63 : CC_BASE Check code for Base ID Fields (addresses 0 to 62) */
	uint8_t checksum;
	/* 64-65 : 2 Options - Optional transceiver signals implemented (Table 3.7) */
	uint8_t options[2];
	/* 66 : BR max - Upper bit rate margin */
	uint8_t br_max;
	/* 67 : BR min - Lower bit rate margin */
	uint8_t br_min;
	/* 68-83 : Vendor SN - Serial number provided by vendor (ASCII) */
	char    vendor_sn[16];
	/* 84-91 : Date code - Vendor manufacturing date code (Table 3.8) (ASCII encoded) */
	char    date_code[8];
	/* 92 : Diagnostic Monitoring Type (Table 3.9) */
	uint8_t diagnostic;
	/* 93 : Enhanced Options - Optional enhanced features implemented (if any) in the transceiver (Table 3.10) */
	uint8_t enhanced;
	/* 94 : SFF-8472 Compliance - Indicates which revision of SFF-8472 the transceiver complies with. (Table 3.12) */
	uint8_t sff8472;
	/* 95 : CC_EXT Check code for the Extended ID Fields (addresses 64 to 94) */
	uint8_t ext_checksum;
	/* 96-127 : Vendor Specific - Vendor Specific EEPROM */
	uint8_t vendor[32];
	/* 128-255 : 128 bytes reserved for SFF-8079 */
	uint8_t sff8079[128];
} sfp_mod_info_t;

/* Data structure describing the QSFP EEPROM contents - SFF 8636 spec
 * This is the PAGE 0 contents for the Identifier
 */
typedef struct qsfp_mod_info {
	/* 128 : Identifier Identifier Type of free side device */
	uint8_t id;
	/* 129 : Ext. Identifier Extended Identifier of free side device */
	uint8_t ext_id;
	/* 130 : Connector Type Code for media connector type */
	uint8_t connector_type;
	/* 131-138 : Specification Compliance Code for electronic or optical compatibility */
	uint8_t compliance_code[8];
	/* 139 : Encoding Code for serial encoding algorithm */
	uint8_t encoding;
	/* 140 : BR, nominal Nominal bit rate, units of 100 Mbps. For BR > 25.4G, set this to FFh and use Byte 222 */
	uint8_t bit_rate;
	/* 141 : Extended Rate Select Compliance Tags for extended rate select compliance */
	uint8_t ext_rate_sel;
	/* 142 : Length (SMF) Link length supported for SMF fiber in km */
	uint8_t smf_1000m;
	/* 143 : Length (OM3 50 um) Link length supported for EBW 50/125 um fiber (OM3), units of 2 m */
	uint8_t om3_2m;
	/* 144 : Length (OM2 50 um) Link length supported for 50/125 um fiber (OM2), units of 1 m */
	uint8_t om2_1m;
	/* 145 : Length (OM1 62.5 um) Link length supported for 62.5/125 um fiber (OM1), units of 1 m */
	uint8_t om1_1m;
	/* 146 : Length (passive copper or active cable or OM4 50 um) Length of passive
	 * or active cable assembly (units of 1 m) or link length supported for OM4 50/125um
	 * fiber (units of 2 m) as indicated by Byte 147
	 */
	uint8_t length_1m_2m;
	/* 147 : Device technology */
	uint8_t technology;
	/* 148-163 : Vendor name Free side device vendor name (ASCII) */
	char    vendor_name[16];
	/* 164 : Extended Module Extended Module codes for InfiniBand */
	uint8_t ext_mod_code;
	/* 165-167 : Vendor OUI Free side device vendor IEEE company ID */
	uint8_t vendor_oui[3];
	/* 168-183 : Vendor PN Part number provided by free side device vendor(ASCII) */
	char    vendor_pn[16];
	/* 184-185 : Vendor rev Revision level for part number provided by vendor(ASCII) */
	char    vendor_rev[2];
	/* 186-187 : Wavelength or Copper Cable Attenuation Nominal laser wavelength
	 * (wavelength=value/20 in nm) or copper cable attenuation in dB at 2.5 GHz (Byte 186)
	 * and 5.0 GHz (Byte 187)
	 */
	uint8_t wave_or_attn[2];
	/* 188-189 : Wavelength tolerance or Copper Cable Attenuation Guaranteed range of
	 * laser wavelength(+/- value) from nominal wavelength.(wavelength Tol.=value/200 in nm)
	 * or copper cable attenuation in dB at 7.0 GHz (Byte 188) and 12GHz (Byte 189)
	 */
	uint8_t wavet_or_attng[2];
	/* 190 : Max case temp. Maximum case temperature in degrees C */
	uint8_t max_temp;
	/* 191 : CC_BASE Check code for base ID fields (Bytes 128-190) */
	uint8_t checksum;
	/* 192 : Link codes Extended Specification Compliance Codes */
	uint8_t ext_compliance;
	/* 193-195 : Options Rate Select, TX Disable, TX Fault, LOS, Warning indicators for:
	 * Temperature, VCC, RX power, TX Bias, TX EQ, Adaptive TX EQ, RX EMPH, CDR Bypass
	 * CDR LOL Flag
	 */
	uint8_t options_rate[3];
	/* 196-211 : Vendor SN Serial number provided by vendor (ASCII) */
	char    vendor_sn[16];
	/* 212-219 : Date Code Vendor's manufacturing date code */
	char    date_code[8];
	/* 220 : Diagnostic Monitoring Type in the free side device. */
	uint8_t diagnostic;
	/* 221 : Enhanced Options Indicates which optional enhanced features are
	 * implemented in the free side device
	 */
	uint8_t enh_options;
	/* 222 : BR, nominal Nominal bit rate per channel, units of 250 Mbps */
	uint8_t bit_rate_chan;
	/* 223 : CC_EXT Check code for the Extended ID Fields (Bytes 192-222) */
	uint8_t ext_checksum;
	/* 224-255 : Vendor Specific Vendor Specific EEPROM */
	uint8_t vendor_spec[32];
} qsfp_mod_info_t;

/* FIXME : not parsed currently */
/* Data structure for the diagnostics */
typedef struct sfp_diag_info {
	uint8_t diag_paging;				/* True if diagnostic address 0x7f is used */
	sff_8472_diag_rev_e diag_rev;			/* Diagnostic feature revision */
	uint8_t diag_addr_change_required;		/* True if an address change sequence is required */
	uint8_t diag_rx_power_averaged;			/* True if RX power is averaged, false if OMA */
	uint8_t diag_externally_calibrated;		/* True if diagnostics are externally calibrated */
	uint8_t diag_internally_calibrated;		/* True if diagnostics are internally calibrated */
	uint8_t diag_soft_rate_select_control;		/* Soft rate select control implemented per SFF-8431 */
	uint8_t diag_app_select_control;		/* Application select control implemented per SFF-8079 */
	uint8_t diag_soft_rate_select_implemented;	/* Soft RATE_SELECT control and moonitoring implemented */
	uint8_t diag_soft_rx_los_implemented;		/* True if soft RX_LOS monitoring implemented */
	uint8_t diag_soft_tx_fault_implemented;		/* True if soft TX_FAULT monitoring implemented */
	uint8_t diag_soft_tx_disable_implemented;	/* Soft TX_DISABLE control and monitoring implemented */
	uint8_t diag_alarm_warning_flags_implemented;	/* True if alarm/warning flags implemented */
} sfp_diag_info_t;

/* Data structure to save the capabilities for SFP/QSFP module
 * Other info from EEPROM are for debugging purpose only
 */
typedef struct sfp_capabilities {
	int trans_type;
	int an_enable;
	int fec_type;
	int speed_limit;
	int far_end;	/* Far End breakout capability - 1 or 2 or 4 channels per slot */
	int active;	/* 1 indicates active (optical or copper), 0 indicates passive copper */
	int optical;	/* 1 indicates optical device*/
} sfp_cap_info_t;

/* Declare APIs */
void sfp_init_shmem(void);
void sfp_send_msg_mcp(int cgx_id, int lmac_id);
int sfp_parse_eeprom_data(int cgx_id, int lmac_id);
int sfp_get_mod_status(int cgx_id, int lmac_id);
int sfp_get_an_capability(int cgx_id, int lmac_id);
int sfp_get_fec_capability(int cgx_id, int lmac_id);
int sfp_get_speed_capability(int cgx_id, int lmac_id);
int sfp_is_transceiver_active(int cgx_id, int lmac_id);
int sfp_is_transceiver_optical(int cgx_id, int lmac_id);
#endif /* __CAVM_SFP_MGMT_H__ */
