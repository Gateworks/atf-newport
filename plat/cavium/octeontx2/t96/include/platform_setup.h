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

/*
 * The array mapping platform core position (implemented by plat_my_core_pos())
 * to the SCMI power domain ID implemented by SCP.
 *
 * Right now it's pretty dummy, ATF defines PLAT_NUM_PWR_DOMAINS
 * as CORES+CLUSTERS+NODES (for t93, it's 29).
 * Right now use 24 PWR_DOMAINS (one per core)
 */
static const uint32_t plat_cavm_core_pos_to_scmi_dmn_id_map[PLATFORM_CORE_COUNT] = {
				0, 1, 2, 3,
				4, 5, 6, 7,
				8, 9, 10, 11,
				12, 13, 14, 15,
				16, 17, 18, 19,
				20, 21, 22, 23};

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

#endif /* __T93_PLAT_SETUP_H__ */
