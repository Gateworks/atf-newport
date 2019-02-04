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
#include <bphy.h>
#include <errno.h>
#include <libfdt.h>
#include <rvu.h>
#include <octeontx_dram.h>

#if (!defined(PLAT_t81) && !defined(PLAT_t83))
#include <plat_scmi.h>

extern void *scmi_handle;
#endif

/* Cavium OEM Service UUID */
DEFINE_SVC_UUID(octeontx_svc_uid,
		0xcf98f46f, 0xfa9c, 0x4e5a, 0xa4, 0x3a,
		0x2a, 0x2f, 0x05, 0xb1, 0x45, 0x59);

/* Setup Standard Services */
static int32_t octeontx_svc_setup(void)
{
	return 0;
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
		SMC_RET1(handle, OCTEONTX_NUM_CALLS);

	case OCTEONTX_SVC_UID:
		/* Return UID to the caller */
		SMC_UUID_RET(handle, octeontx_svc_uid);

	case OCTEONTX_SVC_VERSION:
		/* Return the version of current implementation */
		SMC_RET2(handle, OCTEONTX_VERSION_MAJOR, OCTEONTX_VERSION_MINOR);

	case OCTEONTX_DRAM_SIZE:
		/* Current implementation support only one node */
		if (x1 >= 1){
			ret = 0;
			WARN("DRAM size for %lx: %llx\n", x1, ret);
			SMC_RET1(handle, ret);
		}
		ret = octeontx_dram_size();
		WARN("DRAM size for %lx: %llx\n", x1, ret);
		SMC_RET1(handle, ret);

	case OCTEONTX_NODE_COUNT:
		/* Current implementation support only one node */
		ret = 1;
		SMC_RET1(handle, ret);

	case OCTEONTX_PUTC:
		putchar(x1);
		SMC_RET0(handle);
#if (!defined(PLAT_t81) && !defined(PLAT_t83))
	case OCTEONTX_DISABLE_RVU_LFS:
		ret = octeontx2_clear_lf_to_pf_mapping(x1);
		SMC_RET1(handle, ret);
		break;
#endif

#if (defined(PLAT_t96))
	case OCTEONTX_NDC_RESET:
		INFO("SVC NDC_RESET: x1 = 0x%lx, x2 = 0x%lx\n", x1, x2);
		ret = scmi_octeontx_reset_ndc(scmi_handle, x1, x2);
		INFO("SVC NDC_RESET: ret 0x%llx\n", ret);
		SMC_RET1(handle, ret);
		break;

	case OCTEONTX_NDC_SYNC:
		INFO("SVC NDC_SYNC: x1 = 0x%lx, x2 = 0x%lx, x3 = 0x%lx\n",
			x1, x2, x3);
		ret = scmi_octeontx_sync_ndc(scmi_handle, x1, x2, x3);
		INFO("SVC NDC_SYNC: ret 0x%llx\n", ret);
		SMC_RET1(handle, ret);
		break;

	case OCTEONTX_NDC_STATUS:
		ret = scmi_octeontx_status_ndc(scmi_handle);
		SMC_RET1(handle, ret);
		break;
#endif

	case OCTEONTX_INSTALL_GPIO_INT:
		ret = gpio_install_irq(x1, x2, x3, x4);
		SMC_RET1(handle, ret);

	case OCTEONTX_REMOVE_GPIO_INT:
		gpio_clear_irq(x1);
		SMC_RET1(handle, 0);

#if (defined(PLAT_f95))
	case OCTEONTX_INSTALL_BPHY_PSM_ERRINT:
		ret = bphy_psm_install_irq(x1, x2, x3, x4);
		SMC_RET1(handle, ret);

	case OCTEONTX_REMOVE_BPHY_PSM_ERRINT:
		bphy_psm_clear_irq(x1);
		SMC_RET1(handle, 0);
#endif

	default:
		WARN("Unimplemented OcteonTX Service Call: 0x%x \n", smc_fid);
		SMC_RET1(handle, SMC_UNK);
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
