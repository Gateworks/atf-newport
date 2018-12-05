/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#include <arch.h>
#include <platform_def.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <plat_board_cfg.h>
#include <octeontx_board_cfg_bl1.h>
#include <octeontx_common.h>
#include <debug.h>
#include <assert.h>

#include <libfdt.h>

static void print_board_variables()
{
	INFO("======================\n");
	INFO("BOARD MODEL = %s\n", plat_octeontx_bcfg->bcfg.board_model);
	INFO("BMC BOOT TWSI bus=0x%x, addr=0x%x\n",
		plat_octeontx_bcfg->bcfg.bmc_boot_twsi_bus,
		plat_octeontx_bcfg->bcfg.bmc_boot_twsi_addr);
	INFO("BMC IPMI TWSI bus=0x%x, addr=0x%x\n",
		plat_octeontx_bcfg->bcfg.bmc_ipmi_twsi_bus,
		plat_octeontx_bcfg->bcfg.bmc_ipmi_twsi_addr);
	INFO("GPIO Shutdown pin IN = 0x%x\n",
		plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_in);
	INFO("GPIO Shutdown pin OUT = 0x%x\n",
		plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_out);
#if TRUSTED_BOARD_BOOT
	INFO("TRUST-ROT-ADDR = 0x%llx\n",
		plat_octeontx_bcfg->bcfg.trust_rot_addr);
	INFO("TRUST-BSSK-ADDR = 0x%llx\n",
		plat_octeontx_bcfg->bcfg.trust_key_addr);
#endif
	INFO("======================\n");

}

#if TRUSTED_BOARD_BOOT
static uint64_t octeontx_fdt_get_uint64(const void *fdt, int offset, const char *property, int base)
{
	const char *name;
	int len;

	name = fdt_getprop(fdt, offset, property, &len);
	if (!name) {
		WARN("No %s is found\n", property);
		return 0;
	} else {
		return (uint64_t)strtol(name, NULL, base);
	}
}
#endif

static int octeontx_fdt_get(const void *fdt, int offset, const char *property, int base)
{
	const char *name;
	int len;

	name = fdt_getprop(fdt, offset, property, &len);
	if (!name) {
		WARN("No %s is found\n", property);
		return -1;
	} else {
		return (int)strtol(name, NULL, base);
	}

}

WEAK int plat_octeontx_fill_board_details(void) {
	return 0;
}

WEAK void plat_octeontx_print_board_variables(void) {}

int octeontx_fill_board_details(int info)
{
	const void *fdt = fdt_ptr;
	const char *name;
	int offset, len, config, rc;

	if (fdt_check_header(fdt)) {
		printf("WARNING: Invalid device tree\n");
		return -1;
	}

	offset = fdt_path_offset(fdt, "/cavium,bdk");
	if (offset < 0) {
		printf("WARNING: FDT node not found\n");
		return offset;
	}

	name = fdt_getprop(fdt, offset, "BOARD-MODEL", &len);
	if (!name) {
		printf("WARNING: No BOARD-MODEL is found\n");
		plat_octeontx_bcfg->bcfg.board_model[0] = '\0';
	} else {
		strncpy(plat_octeontx_bcfg->bcfg.board_model, name, sizeof(plat_octeontx_bcfg->bcfg.board_model));
		/* Terminate, in case strlen(name) > sizeof(board_model) */
		plat_octeontx_bcfg->bcfg.board_model[sizeof(plat_octeontx_bcfg->bcfg.board_model) - 1] = '\0';
		len = strlen(plat_octeontx_bcfg->bcfg.board_model);
		for (int i = 0; i < len; i++)
			plat_octeontx_bcfg->bcfg.board_model[i] = tolower(plat_octeontx_bcfg->bcfg.board_model[i]);
	}

	config = octeontx_fdt_get(fdt, offset, "BMC-BOOT-TWSI-CONFIG", 0);
	if (config != -1) {
		plat_octeontx_bcfg->bcfg.bmc_boot_twsi_bus = (config >> 8) & 0xff;
		plat_octeontx_bcfg->bcfg.bmc_boot_twsi_addr = config & 0xff;
	} else {
		plat_octeontx_bcfg->bcfg.bmc_boot_twsi_bus = octeontx_fdt_get(fdt, offset, "BMC-BOOT-TWSI-BUS", 10);
		plat_octeontx_bcfg->bcfg.bmc_boot_twsi_addr = octeontx_fdt_get(fdt, offset, "BMC-BOOT-TWSI-ADDR", 16);
	}
	config = octeontx_fdt_get(fdt, offset, "BMC-IPMI-TWSI-CONFIG", 0);
	if (config != -1) {
		plat_octeontx_bcfg->bcfg.bmc_ipmi_twsi_bus = (config >> 8) & 0xff;
		plat_octeontx_bcfg->bcfg.bmc_ipmi_twsi_addr = config & 0xff;
	} else {
		plat_octeontx_bcfg->bcfg.bmc_ipmi_twsi_bus = octeontx_fdt_get(fdt, offset, "BMC-IPMI-TWSI-BUS", 10);
		plat_octeontx_bcfg->bcfg.bmc_ipmi_twsi_addr = octeontx_fdt_get(fdt, offset, "BMC-IPMI-TWSI-ADDR", 16);
	}

	plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_in = octeontx_fdt_get(fdt, offset, "GPIO-SHUTDOWN-CTL-IN", 0);
	/* The new format is hex and allows for node id and polarity
	 * packed into the value. We don't use them right now and mask
	 * them out. */
	if (plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_in != -1)
		plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_in &= 0xff;

	plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_out = octeontx_fdt_get(fdt, offset, "GPIO-SHUTDOWN-CTL-OUT", 0);
	/* The new format is hex and allows for node id and polarity
	 * packed into the value. We don't use them right now and mask
	 * them out. */
	if (plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_out != -1)
		plat_octeontx_bcfg->bcfg.gpio_shutdown_ctl_out &= 0xff;

	config = octeontx_fdt_get(fdt, offset, "MCU-SHUTDOWN-TWSI-CONFIG", 16);
	if (config != -1) {
		plat_octeontx_bcfg->bcfg.mcu_twsi.s.int_addr = (config >> 16) & 0xff;
		plat_octeontx_bcfg->bcfg.mcu_twsi.s.bus = (config >> 8) & 0xff;
		plat_octeontx_bcfg->bcfg.mcu_twsi.s.addr = config & 0xff;
	} else {
		plat_octeontx_bcfg->bcfg.mcu_twsi.u = 0;
	}

#if TRUSTED_BOARD_BOOT
	/*
	 * Configuration for Trusted Board Boot received from BDK.
	 * For more information, please refer to bdk-trusted-boot.pdf file
	 * in BDK source repository.
	 */
	plat_octeontx_bcfg->bcfg.trust_rot_addr = octeontx_fdt_get_uint64(fdt, offset, "TRUST-ROT-ADDR", 16);

	/*
	 * If either octeontx_fdt_get_uint64 returned -1 (property not found) or
	 * 0 (property found, but set to 0 indicates non-secure boot), stop secure booting
	 */
	if (plat_octeontx_bcfg->bcfg.trust_rot_addr == 0 || plat_octeontx_bcfg->bcfg.trust_rot_addr == -1) {
		printf("ERROR: No TRUST-ROT-ADDR in DTS, trusted boot failed\n");
		return -1;
	}

#if CRYPTO_BOARD_BOOT
	/*
	 * TRUST-BSSK-ADDR is set only when HUK parameter was passed to build system.
	 * If so, it contains the address of BSSK key. Firstly, try to get BSSK
	 */
	plat_octeontx_bcfg->bcfg.trust_key_addr = octeontx_fdt_get_uint64(fdt, offset, "TRUST-BSSK-ADDR", 16);

	/*
	 * If either octeontx_fdt_get_uint64 returned -1 (property not found) or
	 * 0 (property found, but set to 0 indicates SSK), print info about it
	 */
	if (plat_octeontx_bcfg->bcfg.trust_key_addr == 0 || plat_octeontx_bcfg->bcfg.trust_rot_addr == -1) {
		printf("INFO: No TRUST-BSSK-ADDR in DTS, images will be decrypted\n"
		       "      with SSK key from FUSF_SSKX(0..1).\n");
		plat_octeontx_bcfg->bcfg.trust_key_addr = 0;
	}
#endif /* CRYPTO_BOARD_BOOT */

#endif /* TRUSTED_BOARD_BOOT */

  rc = plat_octeontx_fill_board_details();
	if (rc) {
		WARN("Processing family FDT failed\n");
		return rc;
	}

	if (info) {
		print_board_variables();
		plat_octeontx_print_board_variables();
	}
	return 0;
}
