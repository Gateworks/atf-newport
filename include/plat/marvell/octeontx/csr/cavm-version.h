/***********************license start***********************************
* Copyright (C) 2018 Marvell International Ltd.
* SPDX-License-Identifier: BSD-3-Clause
* https://spdx.org/licenses
***********************license end**************************************/

/**
 * @file
 *
 * Functions for identifying CAVM build version.
 *
 * <hr>$Revision$<hr>
 */


extern const char cavm_version_str[];

/**
 * Return CAVM version string
 *
 * @return CAVM version string
 */
static inline const char *cavm_version_string(void)
{
	return cavm_version_str;
}
