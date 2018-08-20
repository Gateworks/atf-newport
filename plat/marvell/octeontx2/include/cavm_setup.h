/** @file

    Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_SETUP_H__
#define __CAVM_SETUP_H__

/* SCMI helper defines */
#define AP_SECURE0_TO_XCP_MBOX_ADDR	0x58000
#define AP_SECURE0_TO_XCP_MBOX_OFFSET	(AP_SECURE0_TO_XCP_MBOX_ADDR / 0x8)

#define SCMI_AGENT_AP0_SECURE		(0)
#define PLAT_SCMI_DB_MODIFY_MASK	(1 << SCMI_AGENT_AP0_SECURE)
#define PLAT_SCMI_DB_PRESERVE_MASK	(~PLAT_SCMI_DB_MODIFY_MASK)

/* SCMI register configuration API */
const uintptr_t plat_get_scmi_mbox_addr(int node);
const uintptr_t plat_get_scmi_db_addr(int node);

#endif /* __CAVM_SETUP_H__ */
