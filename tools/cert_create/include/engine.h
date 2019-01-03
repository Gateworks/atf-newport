/*
 * Copyright (c) 2019, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ENGINE_H_
#define ENGINE_H_

ENGINE *init_engine(const char *engine_id);
void release_engine(ENGINE *e);
void release_engine_atexit(void);

#endif /* ENGINE_H_ */
