/** @file

    Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _PLATFORM_DT_H_
#define _PLATFORM_DT_H_

#define MAX_CGX			3

#define MAX_LMAC_PER_CGX	4

/* Total number of Hardware VFs */
#define MAX_RVU_HWVFS		256

/* Maximum number of RVU VFs per PF */
#define MAX_VFS_PER_PF		128

/* Global, default number of VFs */
#define DEFAULT_VFS		8

/* Default number of VFs for PF0 (admin PF) */
#define DEFAULT_AF_PF0_VFS	0

/* Default number of VFs for PF15 (CPT PF) */
#define DEFAULT_CPT_PF15_VFS	64

/* Default number of MSIX vectors for software
 * provisioned (SSO_TIM/NPA) RVU PFs */
#define DEFAULT_MSIX_SW		133

/*
 * Default number of MSIX vectors for LMAC RVU PFs, based on
 * NPA_LF (66) + NIX_LF (131) + RVU_PF (13) = 210, which addresses
 * the bare minimum configuration of NIX + NPA.
 */
#define DEFAULT_MSIX_LMAC	210

/* Default number of MSIX vectors for AF PF */
#define DEFAULT_MSIX_AF		37

/* RVU node names definitions */
#define RVU_ADMIN_FDT_NODE	"rvu-admin@0"
#define RVU_SSO_TIM_FDT_NODE	"rvu-sso-tim@0"
#define RVU_NPA_FDT_NODE	"rvu-npa@0"
#define RVU_CPT_FDT_NODE	"rvu-cpt@0"

#endif
