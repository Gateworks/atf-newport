/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __TWSI_H__
#define __TWSI_H__

int octeontx_twsi_send(unsigned int twsi_num,
			uint16_t addr, const uint8_t *buffer, size_t size);
int octeontx_twsi_recv(unsigned int twsi_num,
			uint16_t addr, uint8_t *buffer, size_t size);

#endif /* __TWSI_H__ */
