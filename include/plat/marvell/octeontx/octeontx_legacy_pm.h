/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_LEGACY_PM_H__
#define __OCTEONTX_LEGACY_PM_H__

/*
 * This function allow to override handlers from plat_psci_ops 
 */
void plat_octeontx_legacy_psci_override_pm_ops(plat_psci_ops_t *pm_ops);

#endif /* __OCTEONTX_LEGACY_PM_H__ */