#ifndef __CAVM_CSRS_USBH_H__
#define __CAVM_CSRS_USBH_H__
/* This file is auto-generated. Do not edit */

/***********************license start***********************************
* Copyright (C) 2019 Marvell International Ltd.
* SPDX-License-Identifier: BSD-3-Clause
* https://spdx.org/licenses
***********************license end**************************************/


/**
 * @file
 *
 * Configuration and status register (CSR) address and type definitions for
 * OcteonTX USBH.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration uctl_ecc_err_source_e
 *
 * USB UCTL ECC Error Source Enumeration
 * Enumerate sources of ECC error log information.
 */
#define CAVM_UCTL_ECC_ERR_SOURCE_E_NONE (0)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_RAM0_DBE (0xf)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_RAM0_SBE (7)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_RAM1_DBE (0xe)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_RAM1_SBE (6)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_RAM2_DBE (0xd)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_RAM2_SBE (5)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_XM_R_DBE (0xa)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_XM_R_SBE (2)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_XM_W_DBE (9)
#define CAVM_UCTL_ECC_ERR_SOURCE_E_XM_W_SBE (1)

#endif /* __CAVM_CSRS_USBH_H__ */
