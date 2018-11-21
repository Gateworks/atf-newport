/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __BPHY_H__
#define __BPHY_H__

int cavm_register_bphy_intr_handlers(void);
void plat_set_bphy_psm_msix_vectors(int msix_num, int irq_num, int enable);
int bphy_psm_install_irq(uint64_t irq_num, uint64_t sp, uint64_t  cpu,
			 uint64_t isr_base);
void bphy_psm_clear_irq(uint64_t irq_num);

#endif

