/** @file

  Copyright (c) 2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <arch.h>
#include <stdio.h>
#include <debug.h>
#include <cavm_common.h>
#include <cavm_legacy_pwrc.h>

/* Any SoC family specific setup
 * to be done in BL31 can be initialized
 * in this API. If there are any platform
 * specific init to be done but not common
 * to family, each platform can define
 * its own API and can be called from here
 */
void plat_cavm_setup(void)
{
	/* FIXME: no functionality as of now,
	 * added to make this API generic
	 */
}

void plat_pwrc_setup(void)
{
	cavm_legacy_pwrc_setup();
}

void plat_setup_psci_ops(uintptr_t sec_entrypoint,
			 const plat_psci_ops_t **psci_ops)
{
	cavm_legacy_setup_psci_ops(sec_entrypoint, psci_ops);
}
