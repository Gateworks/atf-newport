/*
 * Copyright (c) 2019, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <openssl/engine.h>
#include "debug.h"

static ENGINE *engine_to_free_on_exit;

ENGINE *init_engine(const char *engine_id)
{
	ENGINE *e;

	engine_to_free_on_exit = NULL;

	ENGINE_load_builtin_engines();
	e = ENGINE_by_id(engine_id);
	if (!e) {
		ERROR("The engine '%s' isn't available\n", engine_id);
		return NULL;
	}
	if (!ENGINE_init(e)) {
		ERROR("The engine '%s' isn't couldn't initialise\n", engine_id);
		ENGINE_free(e);
		return NULL;
	}
	ENGINE_set_default(e, ENGINE_METHOD_ALL);
	engine_to_free_on_exit = e;
	return e;
}


void release_engine(ENGINE *e)
{
	/* Release the functional reference from ENGINE_init() */
	ENGINE_finish(e);
	/* Release the structural reference from ENGINE_by_id() */
	ENGINE_free(e);
}

void release_engine_atexit(void)
{
	if (engine_to_free_on_exit != NULL)
		release_engine(engine_to_free_on_exit);
}
