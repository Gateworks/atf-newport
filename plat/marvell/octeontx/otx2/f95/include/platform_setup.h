/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __F95_PLAT_SETUP_H__
#define __F95_PLAT_SETUP_H__

/*
 * The array mapping platform core position (implemented by plat_my_core_pos())
 * to the SCMI power domain ID implemented by SCP.
 *
 * Right now it's pretty dummy, ATF defines PLAT_NUM_PWR_DOMAINS
 * as CORES+CLUSTERS+NODES (for f95, it's 8).
 * Right now use one PWR_DOMAIN per core.
 */
static const uint32_t plat_octeontx_core_pos_to_scmi_dmn_id_map[PLATFORM_CORE_COUNT] = {
				0, 1, 2, 3, 4, 5};

/* CPU topology tree description for F95 */
static const unsigned char plat_octeontx_power_domain_tree_desc[] = {
	/* No of root nodes */
	PLATFORM_MAX_NODES,
	/* No of clusters */
	PLATFORM_MAX_CLUSTERS_PER_NODE,
	/* No of CPU cores */
	PLATFORM_MAX_CPUS_PER_CLUSTER,
};

/* plat APIs specific to Octeon TX2 family */
int plat_get_max_lane_num(int qlm);
int plat_get_cgx_idx(int qlm);

#endif /* __F95_PLAT_SETUP_H__ */
