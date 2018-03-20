/** @file

    Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __T96_PLAT_SETUP_H__
#define __T96_PLAT_SETUP_H__

/*
 * Defines used for CN96xx to enable particular
 * LMC access to particular ASC_REGION
 */

#define CAVM_CCS_LMC_MASK_LMC0	0x1
#define CAVM_CCS_LMC_MASK_LMC1	0x2
#define CAVM_CCS_LMC_MASK_LMC2	0x4

/* 3 LMCs per node */
#define CAVM_CCS_LMC_MODE	CAVM_CCS_LMC_MODE_E_STRIPE_3
#define CAVM_CCS_LMC_MASK	(CAVM_CCS_LMC_MASK_LMC0 | CAVM_CCS_LMC_MASK_LMC1 | \
					CAVM_CCS_LMC_MASK_LMC2)

/* SCMI related defines */

/*
 * Macros mapping the MPIDR Affinity levels to Cavium Platform Power levels. The
 * power levels have a 1:1 mapping with the MPIDR affinity levels.
 */
#define CAVM_PWR_LVL0		MPIDR_AFFLVL0
#define CAVM_PWR_LVL1		MPIDR_AFFLVL1
#define CAVM_PWR_LVL2		MPIDR_AFFLVL2

/*
 *  Macros for local power states in Cavium platforms encoded by State-ID field
 *  within the power-state parameter.
 */

/* Local power state for power domains in Run state. */
#define CAVM_LOCAL_STATE_RUN	0
/* Local power state for retention. Valid only for CPU power domains */
#define CAVM_LOCAL_STATE_RET	1
/* Local power state for OFF/power-down. Valid for CPU and cluster power
   domains */
#define CAVM_LOCAL_STATE_OFF	2

/* System power domain at level 2, as currently implemented by Cavium platforms */
#define CAVM_SYSTEM_PWR_DMN_LVL		CAVM_PWR_LVL2

/* Macros to read the CAVM power domain state */
#define CAVM_CORE_PWR_STATE(state)	(state)->pwr_domain_state[CAVM_PWR_LVL0]
#define CAVM_CLUSTER_PWR_STATE(state)	(state)->pwr_domain_state[CAVM_PWR_LVL1]
#define CAVM_SYSTEM_PWR_STATE(state)	\
			((PLAT_MAX_PWR_LVL == CAVM_SYSTEM_PWR_DMN_LVL) ?\
			(state)->pwr_domain_state[CAVM_SYSTEM_PWR_DMN_LVL] : 0)

/* SCMI helper defines */
#define AP_SECURE0_TO_XCP_MBOX_ADDR	0x58000
#define AP_SECURE0_TO_XCP_MBOX_OFFSET	(AP_SECURE0_TO_XCP_MBOX_ADDR / 0x8)

#define SCMI_AGENT_AP0_SECURE		(0)
#define PLAT_SCMI_DB_MODIFY_MASK	(1 << SCMI_AGENT_AP0_SECURE)
#define PLAT_SCMI_DB_PRESERVE_MASK	(~PLAT_SCMI_DB_MODIFY_MASK)


/* CPU topology tree description for T96 */
static const unsigned char cavm_power_domain_tree_desc[] = {
	/* No of root nodes */
	PLATFORM_MAX_NODES,
	/* No of clusters */
	PLATFORM_MAX_CLUSTERS_PER_NODE,
	/* No of CPU cores */
	PLATFORM_MAX_CPUS_PER_CLUSTER,
	PLATFORM_MAX_CPUS_PER_CLUSTER,
	PLATFORM_MAX_CPUS_PER_CLUSTER,
	PLATFORM_MAX_CPUS_PER_CLUSTER,
};

/* plat APIs specific to Octeon TX2 family */
int plat_get_max_lane_num(int qlm);
int plat_get_cgx_idx(int qlm);

/* SCMI register configuration API */
const uintptr_t plat_get_scmi_mbox_addr(int node);
const uintptr_t plat_get_scmi_db_addr(int node);

#endif /* __T93_PLAT_SETUP_H__ */
