/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <debug.h>
#include <psci.h>
#include <runtime_svc.h>
#include <octeontx_svc.h>
#include <stdint.h>
#include <uuid.h>
#include <string.h>
#include <octeontx_common.h>
#include <gpio_octeontx.h>
#include <gti_watchdog.h>
#include <errno.h>
#include <libfdt.h>
#include <octeontx_dram.h>
#include <platform_svc.h>

/*
 * FIXME: UUID should be different for platforms with different set
 *        of SMC calls.
 */
/* OcteonTX OEM Service UUID */
DEFINE_SVC_UUID(octeontx_svc_uid,
		0xcf98f46f, 0xfa9c, 0x4e5a, 0xa4, 0x3a,
		0x2a, 0x2f, 0x05, 0xb1, 0x45, 0x59);

/* Setup Standard Services */
static int32_t octeontx_svc_setup(void)
{
	return 0;
}

WEAK uintptr_t plat_octeontx_svc_smc_handler(uint32_t smc_fid,
					u_register_t x1,
					u_register_t x2,
					u_register_t x3,
					u_register_t x4,
					void *cookie,
					void *handle,
					u_register_t flags)
{
	WARN("Unimplemented OcteonTX Service Call: 0x%x\n", smc_fid);
	SMC_RET1(handle, SMC_UNK);
}

/*
 * Top-level OEM Service SMC handler
 */
uintptr_t octeontx_svc_smc_handler(uint32_t smc_fid,
				 u_register_t x1,
				 u_register_t x2,
				 u_register_t x3,
				 u_register_t x4,
				 void *cookie,
				 void *handle,
				 u_register_t flags)
{
	int64_t ret = 0;

	VERBOSE("OcteonTX Service Call: 0x%x\n", smc_fid);

	switch (smc_fid) {
	case OCTEONTX_SVC_CALL_COUNT:
		/*
		 * Return the number of Service Calls.
		 */
		SMC_RET1(handle,
			OCTEONTX_NUM_CALLS + PLAT_OCTEONTX_NUM_SMC_CALLS);
		break;

	case OCTEONTX_SVC_UID:
		/* Return UID to the caller */
		SMC_UUID_RET(handle, octeontx_svc_uid);

	case OCTEONTX_SVC_VERSION:
		/* Return the version of current implementation */
		SMC_RET2(handle, PLAT_OCTEONTX_VERSION_MAJOR,
			PLAT_OCTEONTX_VERSION_MINOR);
		break;

	case OCTEONTX_DRAM_SIZE:
		/* Current implementation support only one node */
		if (x1 >= 1){
			ret = 0;
			SMC_RET1(handle, ret);
		}
		ret = octeontx_dram_size();
		SMC_RET1(handle, ret);
		break;

	case OCTEONTX_NODE_COUNT:
		/* Current implementation support only one node */
		ret = 1;
		SMC_RET1(handle, ret);
		break;

	case OCTEONTX_PUTC:
		putchar(x1);
		SMC_RET0(handle);
		break;

	case OCTEONTX_INSTALL_GPIO_INT:
		ret = gpio_install_irq(x1, x2, x3, x4);
		SMC_RET1(handle, ret);
		break;

	case OCTEONTX_REMOVE_GPIO_INT:
		gpio_clear_irq(x1);
		SMC_RET1(handle, 0);
		break;

	case OCTEONTX_INSTALL_WDOG:
		ret = gti_wdog_install_handler(x1, x2, x3, x4);
		SMC_RET1(handle, ret);
		break;

	case OCTEONTX_REMOVE_WDOG:
		ret = gti_wdog_remove_handler();
		SMC_RET1(handle, ret);
		break;

	default:
		return plat_octeontx_svc_smc_handler(smc_fid, x1, x2, x3, x4,
			cookie, handle, flags);
	}
}

/* Register Standard Service Calls as runtime service */
DECLARE_RT_SVC(
		octeontx_svc,
		OEN_SIP_START,
		OEN_SIP_END,
		SMC_TYPE_FAST,
		octeontx_svc_setup,
		octeontx_svc_smc_handler
);
