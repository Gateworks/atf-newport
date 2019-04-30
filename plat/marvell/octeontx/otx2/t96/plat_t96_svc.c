/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <debug.h>
#include <runtime_svc.h>
#include <octeontx_svc.h>
#include <platform_svc.h>
#include <octeontx_common.h>
#include <stdint.h>
#include <uuid.h>
#include <plat_scmi.h>
#include <rvu.h>

extern void *scmi_handle;

uintptr_t plat_octeontx_svc_smc_handler(uint32_t smc_fid,
					u_register_t x1,
					u_register_t x2,
					u_register_t x3,
					u_register_t x4,
					void *cookie,
					void *handle,
					u_register_t flags)
{
	uint64_t ret = 0;

	switch (smc_fid) {
	case PLAT_OCTEONTX_DISABLE_RVU_LFS:
		ret = octeontx2_clear_lf_to_pf_mapping(x1);
		SMC_RET1(handle, ret);
		break;

	case PLAT_OCTEONTX_NDC_RESET:
		INFO("SVC NDC_RESET: x1 = 0x%lx, x2 = 0x%lx\n", x1, x2);
		ret = scmi_octeontx_reset_ndc(scmi_handle, x1, x2);
		INFO("SVC NDC_RESET: ret 0x%llx\n", ret);
		SMC_RET1(handle, ret);
		break;

	case PLAT_OCTEONTX_NDC_SYNC:
		INFO("SVC NDC_SYNC: x1 = 0x%lx, x2 = 0x%lx, x3 = 0x%lx\n",
			x1, x2, x3);
		ret = scmi_octeontx_sync_ndc(scmi_handle, x1, x2, x3);
		INFO("SVC NDC_SYNC: ret 0x%llx\n", ret);
		SMC_RET1(handle, ret);
		break;

	case PLAT_OCTEONTX_NDC_STATUS:
		ret = scmi_octeontx_status_ndc(scmi_handle);
		SMC_RET1(handle, ret);
		break;

	case PLAT_OCTEONTX_OOO_CONFIG:
		INFO("SVC OOO CONFIG: x1 = 0x%lx\n", x1);
		ret = octeontx2_configure_ooo(x1);
		SMC_RET1(handle, ret);
		break;

	default:
		WARN("Unimplemented OcteonTX Service Call: 0x%x\n", smc_fid);
		SMC_RET1(handle, SMC_UNK);
	}
}
