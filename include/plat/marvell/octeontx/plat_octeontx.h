/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLAT_OCTEONTX_H__
#define __PLAT_OCTEONTX_H__

void set_secondary_cpu_jump_addr(unsigned int bl1_base);

void plat_octeontx_setup(void);
void plat_pwrc_setup(void);

unsigned int plat_get_rom_t_cnt();

#endif /* __PLAT_OCTEONTX_H__ */