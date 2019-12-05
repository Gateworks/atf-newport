/*
 * Copyright (c) 2013-2015, ARM Limited and Contributors. All rights reserved.
 * Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __OCTEONTX_LEGACY_PWRC_H__
#define __OCTEONTX_LEGACY_PWRC_H__

#include <psci.h>

#ifndef __ASSEMBLY__

/*******************************************************************************
 * Function & variable prototypes
 ******************************************************************************/
void octeontx_legacy_pwrc_write_pponr(unsigned long);

void octeontx_legacy_pwrc_setup(void);
int octeontx_legacy_setup_psci_ops(uintptr_t sec_entrypoint,
			       const plat_psci_ops_t **psci_ops);

#endif /*__ASSEMBLY__*/

#endif /* __OCTEONTX_LEGACY_PWRC_H__ */
