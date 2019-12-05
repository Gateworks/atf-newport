/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <debug.h>
#include <psci.h>
#include <runtime_svc.h>
#include <cavm_svc.h>
#include <stdint.h>
#include <uuid.h>
#include <string.h>
#include <cavm_common.h>
#include <cavm_gpio.h>
#include <errno.h>
#include <libfdt.h>

#define PAR_EL1_F	(1 << 0)

/* Cavium OEM Service UUID */
DEFINE_SVC_UUID(thunder_svc_uid,
		0xcf98f46f, 0xfa9c, 0x4e5a, 0xa4, 0x3a,
		0x2a, 0x2f, 0x05, 0xb1, 0x45, 0x59);

/* Setup Standard Services */
static int32_t thunder_svc_setup(void)
{
	return 0;
}

/*
 * Top-level OEM Service SMC handler
 */
uint64_t thunder_svc_smc_handler(uint32_t smc_fid,
				 uint64_t x1,
				 uint64_t x2,
				 uint64_t x3,
				 uint64_t x4,
				 void *cookie,
				 void *handle,
				 uint64_t flags)
{
	int64_t ret = 0;

	VERBOSE("ThunderX Service Call: 0x%x\n", smc_fid);

	switch (smc_fid) {
	case THUNDERX_SVC_CALL_COUNT:
		/*
		 * Return the number of Service Calls.
		 */
		SMC_RET1(handle, THUNDERX_NUM_CALLS);

	case THUNDERX_SVC_UID:
		/* Return UID to the caller */
		SMC_UUID_RET(handle, thunder_svc_uid);

	case THUNDERX_SVC_VERSION:
		/* Return the version of current implementation */
		SMC_RET2(handle, THUNDERX_VERSION_MAJOR, THUNDERX_VERSION_MINOR);

	case THUNDERX_DRAM_SIZE:
		ret = thunder_dram_size_node(x1);
		WARN("DRAM size for %lx: %lx\n", x1, ret);
		SMC_RET1(handle, ret);

	case THUNDERX_NODE_COUNT:
		ret = thunder_get_node_count();
		SMC_RET1(handle, ret);

	case THUNDERX_PUTC:
		putchar(x1);
		SMC_RET0(handle);
#if (!defined(PLAT_t81) && !defined(PLAT_t83))
	case THUNDERX_DISABLE_RVU_LFS:
		ret = octeontx2_clear_lf_to_pf_mapping(x1);
		SMC_RET1(handle, ret);
#endif
	case THUNDERX_INSTALL_GPIO_INT:
		ret = gpio_install_irq(x1, x2, x3, x4);
		SMC_RET1(handle, ret);

	case THUNDERX_REMOVE_GPIO_INT:
		gpio_clear_irq(x1);
		SMC_RET1(handle, 0);
	default:
		WARN("Unimplemented ThunderX Service Call: 0x%x \n", smc_fid);
		SMC_RET1(handle, SMC_UNK);
	}
}

/* Register Standard Service Calls as runtime service */
DECLARE_RT_SVC(
		thunder_svc,
		OEN_OEM_START,
		OEN_OEM_END,
		SMC_TYPE_YIELD,
		thunder_svc_setup,
		thunder_svc_smc_handler
);
