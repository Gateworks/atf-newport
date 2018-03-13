/** @file

    Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __T93_PLAT_SETUP_H__
#define __T93_PLAT_SETUP_H__

/* CPU topology tree description for T93 */
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

#endif
