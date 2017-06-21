/** @file
#
#  Copyright (c) 2016-2017, Cavium Inc. All rights reserved.<BR>
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#**/

#include <platform_def.h>
#include <thunder_private.h>
#include <thunder_common.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "thunder_io.h"
#include "thunder_dt.h"
#include "thunder_ecam.h"

#define DEBUG_ATF_PLAT_ECAM 1

#ifdef DEBUG_ATF_PLAT_ECAM
#define debug_plat_ecam printf
#else
#define debug_plat_ecam(x,...);
#endif

struct ecam_device devs_domain0_cn93xx[] = {
	/* Ecam 0, Domain 0 */
	{0, 0, 1, 0, TRUE, NULL, 0},	/* MRML bridge */
	{0, 0, 2, 0, TRUE, NULL, 0},	/* AP bridge */
	{0, 0, 3, 0, TRUE, NULL, 0},	/* SMMU 0 */
	{0, 0, 4, 0, TRUE, NULL, 0},	/* GIC */
	{0, 0, 5, 0, TRUE, NULL, 0},	/* GTI */
	{0, 0, 6, 0, TRUE, NULL, 0},	/* MPI 0 */
	{0, 0, 7, 0, TRUE, NULL, 0},	/* MPI 1 */
	{0, 0, 8, 0, TRUE, NULL, 0},	/* MIO_PTP */
	{0, 0, 9, 0, TRUE, NULL, 0},	/* RNM bridge */
	{0, 0, 10, 0, TRUE, NULL, 0},	/* BCH bridge */
	{0, 0, 11, 0, TRUE, NULL, 0},	/* NAND */
	{0, 0, 12, 0, TRUE, NULL, 0},	/* CPT0 bridge */
	{0, 0, 13, 0, TRUE, NULL, 0},	/* CPT1 bridge */
	{0, 0, 14, 0, TRUE, NULL, 0},	/* RAD bridge */
	{0, 0, 15, 0, TRUE, NULL, 0},	/* GPIO */
	{0, 0, 16, 0, TRUE, NULL, 0},	/* SSO bridge */
	{0, 0, 17, 0, TRUE, NULL, 0},	/* SSOW bridge */
	{0, 0, 18, 0, TRUE, NULL, 0},	/* FPA bridge */
	{0, 0, 19, 0, TRUE, NULL, 0},	/* TIM bridge */
	{0, 0, 20, 0, TRUE, NULL, 0},	/* DPI0 bridge */
	{0, 0, 24, 0, TRUE, NULL, 0},	/* SLIRE 0 */
	{0, 0, 28, 0, TRUE, NULL, 0},	/* AVS */

	/* Bus1, ARI functions */
	{0, 1, 0, 0, TRUE, NULL, 0},	/* MRML */
	{0, 1, 0, 1, TRUE, NULL, 0},	/* RST */
	{0, 1, 0, 2, TRUE, NULL, 0},	/* DAP */
	{0, 1, 0, 3, TRUE, NULL, 0},	/* FUS */
	{0, 1, 0, 4, TRUE, NULL, 0},	/* FUSF */
	{0, 1, 0, 7, TRUE, NULL, 0},	/* PSBM */
	{0, 1, 0, 8, TRUE, NULL, 0},	/* NCSI */
	{0, 1, 0, 9, TRUE, NULL, 0},	/* CCS */
	{0, 1, 0, 10, TRUE, NULL, 0},	/* SGP */
	{0, 1, 0, 11, TRUE, NULL, 0},	/* SMI */
	{0, 1, 0, 12, TRUE, NULL, 0},	/* EMM */
	{0, 1, 0, 13, TRUE, NULL, 0},	/* KEY */
	{0, 1, 0, 14, TRUE, NULL, 0},	/* BOOT BUS */
	{0, 1, 0, 15, TRUE, NULL, 0},	/* PBUS */
	{0, 1, 0, 32, TRUE, NULL, 0},	/* CCU 0 */
	{0, 1, 0, 33, TRUE, NULL, 0},	/* CCU 1 */
	{0, 1, 0, 34, TRUE, NULL, 0},	/* CCU 2 */
	{0, 1, 0, 35, TRUE, NULL, 0},	/* CCU 3 */
	{0, 1, 0, 48, TRUE, NULL, 0},	/* MCC 0 */
	{0, 1, 0, 49, TRUE, NULL, 0},	/* MCC 1 */
	{0, 1, 0, 64, TRUE, NULL, 0},	/* MDC */
	{0, 1, 0, 68, TRUE, NULL, 0},	/* TSN0 */
	{0, 1, 0, 72, TRUE, NULL, 0},	/* TWSI 0 */
	{0, 1, 0, 73, TRUE, NULL, 1},	/* TWSI 1 */
	{0, 1, 0, 74, TRUE, NULL, 1},	/* TWSI 2 */
	{0, 1, 0, 75, TRUE, NULL, 1},	/* TWSI 3 */
	{0, 1, 0, 76, TRUE, NULL, 1},	/* TWSI 4 */
	{0, 1, 0, 77, TRUE, NULL, 1},	/* TWSI 5 */
	{0, 1, 0, 80, TRUE, NULL, 0},	/* LMC 0 */
	{0, 1, 0, 81, TRUE, NULL, 0},	/* LMC 1 */
	{0, 1, 0, 82, TRUE, NULL, 0},	/* LMC 2 */
	{0, 1, 0, 88, TRUE, NULL, 0},	/* IOBN0 */
	{0, 1, 0, 89, TRUE, NULL, 0},	/* IOBN1 */
	{0, 1, 0, 96, TRUE, NULL, 0},	/* UAA 0 */
	{0, 1, 0, 97, TRUE, NULL, 0},	/* UAA 1 */
	{0, 1, 0, 98, TRUE, NULL, 0},	/* UAA 2 */
	{0, 1, 0, 99, TRUE, NULL, 0},	/* UAA 3 */
	{0, 1, 0, 100, TRUE, NULL, 0},	/* UAA 4 */
	{0, 1, 0, 101, TRUE, NULL, 0},	/* UAA 5 */
	{0, 1, 0, 102, TRUE, NULL, 0},	/* UAA 6 */
	{0, 1, 0, 103, TRUE, NULL, 0},	/* UAA 7 */
	{0, 1, 0, 104, TRUE, NULL, 0},	/* LBK 0 */
	{0, 1, 0, 112, TRUE, NULL, 0},	/* PEM 0 */
	{0, 1, 0, 113, TRUE, NULL, 1},	/* PEM 1 */
	{0, 1, 0, 114, TRUE, NULL, 2},	/* PEM 2 */
	{0, 1, 0, 115, TRUE, NULL, 2},	/* PEM 3 */
	{0, 1, 0, 128, TRUE, NULL, 0},	/* CGX 0 */
	{0, 1, 0, 129, TRUE, NULL, 2},	/* CGX 1 */
	{0, 1, 0, 130, TRUE, NULL, 2},	/* CGX 2 */
	{0, 1, 0, 144, TRUE, NULL, 0},	/* OCLA 0 */
	{0, 1, 0, 145, TRUE, NULL, 0},	/* OCLA 1 */
	{0, 1, 0, 146, TRUE, NULL, 0},	/* OCLA 2 */
	{0, 1, 0, 147, TRUE, NULL, 0},	/* OCLA 3 */
	{0, 1, 0, 148, TRUE, NULL, 0},	/* OCLA 4 */
	{0, 1, 0, 149, TRUE, NULL, 0},	/* OCLA 5 */
	{0, 1, 0, 150, TRUE, NULL, 0},	/* OCLA 6 */
	{0, 1, 0, 151, TRUE, NULL, 0},	/* OCLA 7 */
	{0, 1, 0, 152, TRUE, NULL, 0},	/* OCLA 8 */
	{0, 1, 0, 153, TRUE, NULL, 0},	/* OCLA 9 */
	{0, 1, 0, 240, TRUE, NULL, 0},	/* GSER 0 */
	{0, 1, 0, 241, TRUE, NULL, 0},	/* GSER 1 */
	{0, 1, 0, 242, TRUE, NULL, 0},	/* GSER 2 */
	{0, 1, 0, 243, TRUE, NULL, 0},	/* GSER 3 */
	{0, 1, 0, 244, TRUE, NULL, 0},	/* GSER 4 */
	{0, 1, 0, 245, TRUE, NULL, 0},	/* GSER 5 */
	{0, 1, 0, 246, TRUE, NULL, 0},	/* GSER 6 */
	{0, 1, 0, 247, TRUE, NULL, 0},	/* GSER 7 */

	/* Other Bus # devices for Domain 0 */
	{0, 3, 0, 0, TRUE, NULL, 0},	/* RNM */
	{0, 4, 0, 0, TRUE, NULL, 0},	/* BCH */
	{0, 5, 0, 0, TRUE, NULL, 0},	/* CPT 0 */
	{0, 6, 0, 0, TRUE, NULL, 0},	/* CPT 1 */
	{0, 7, 0, 0, TRUE, NULL, 0},	/* RAD */
	{0, 8, 0, 0, TRUE, NULL, 0},	/* SSO */
	{0, 9, 0, 0, TRUE, NULL, 0},	/* SSOW */
	{0, 10, 0, 0, TRUE, NULL, 0},	/* FPA */
	{0, 11, 0, 0, TRUE, NULL, 0},	/* TIM */
	{0, 12, 0, 0, TRUE, NULL, 0},	/* DPI 0 */

	{-1, 0, 0, 0, 0, NULL, 0},
};

struct ecam_device devs_domain1_cn93xx[] = {
	/* Ecam 0, Domain 1 */
	{1, 0, 2, 0, TRUE, NULL, 0},	/* CPC */
	{1, 0, 2, 1, TRUE, NULL, 0},	/* XPC 0 */
	{1, 0, 2, 2, TRUE, NULL, 0},	/* XPC 2 */
	{1, 0, 4, 0, TRUE, NULL, 0},	/* SATA 0 */
	{1, 0, 5, 0, TRUE, NULL, 0},	/* SATA 1 */
	{1, 0, 6, 0, TRUE, NULL, 0},	/* SATA 2 */
	{1, 0, 7, 0, TRUE, NULL, 0},	/* SATA 3 */

	{-1, 0, 0, 0, 0, NULL, 0},
};

struct ecam_device devs_domain7_cn93xx[] = {
	/* Ecam 0, Domain 7 */
	{7, 0, 0, 0, TRUE, NULL, 0},	/* RVU 0 bridge */
	{7, 0, 1, 0, TRUE, NULL, 0},	/* RVU 1 bridge */
	{7, 0, 2, 0, TRUE, NULL, 0},	/* RVU 2 bridge */
	{7, 0, 3, 0, TRUE, NULL, 0},	/* RVU 3 bridge */
	{7, 0, 4, 0, TRUE, NULL, 0},	/* RVU 4 bridge */
	{7, 0, 5, 0, TRUE, NULL, 0},	/* RVU 5 bridge */
	{7, 0, 6, 0, TRUE, NULL, 0},	/* RVU 6 bridge */
	{7, 0, 7, 0, TRUE, NULL, 0},	/* RVU 7 bridge */
	{7, 0, 8, 0, TRUE, NULL, 0},	/* RVU 8 bridge */
	{7, 0, 9, 0, TRUE, NULL, 0},	/* RVU 9 bridge */
	{7, 0, 10, 0, TRUE, NULL, 0},	/* RVU 10 bridge */
	{7, 0, 11, 0, TRUE, NULL, 0},	/* RVU 11 bridge */
	{7, 0, 12, 0, TRUE, NULL, 0},	/* RVU 12 bridge */
	{7, 0, 13, 0, TRUE, NULL, 0},	/* RVU 13 bridge */
	{7, 0, 14, 0, TRUE, NULL, 0},	/* RVU 14 bridge */
	{7, 0, 15, 0, TRUE, NULL, 0},	/* RVU 15 bridge */

	{-1, 0, 0, 0, 0, NULL, 0},
};

static struct ecam_device *cn93xx_get_dev_idx(int node, int ecam)
{
	debug_plat_ecam("Called cn93xx with N%d.E%d\n", node, ecam);
	int node_ecam = ecam | (node << 2);
	struct ecam_device *devs = NULL;

	switch (node_ecam) {
	case 0:
		devs = &devs_domain0_cn93xx[0];
		debug_plat_ecam("returning domain0\n");
		break;
	case 1:
		devs = &devs_domain1_cn93xx[0];
		debug_plat_ecam("returning domain1\n");
		break;
	case 7:
		devs = &devs_domain7_cn93xx[0];
		debug_plat_ecam("returning domain7\n");
		break;
	}

	return devs;
}

/* Check fuses to see if the device on bus is available
 * or not. If available return 0, else return -1
 */
static int cn93xx_disable_device_on_bus(int node, int bus)
{
	/* TODO: CN9XXX has other fuse registers that are not yet
	 * easy visible on HRM. Do not disable for now any devices on
	 * specified bus */
	return 0;
}

int max_bus_cn93xx[] = { 12, 1, 0, 0, 0, 0, 0, 1, 0 };

static int cn93xx_get_max_bus(int ecam)
{
	return max_bus_cn93xx[ecam];
}

static uint64_t cn93xx_get_config_addr(int node, int ecam)
{
	return thunder_get_ecam_config_addr(node, ecam);
}

static uint64_t cn93xx_get_config_size(int node, int ecam)
{
	return thunder_get_ecam_config_size(node, ecam);
}

static inline void cn93xx_enable_bus(int node, int domain, int bus)
{
	union cavm_ecamx_domx_busx_permit bus_permit;

	debug_plat_ecam("enable_bus N%d:E%d:DOM%d:B%d\n", node, 0, domain, bus);

	switch (domain) {
		case 0:
			domain = 0;
			break;
		case 1:
			domain = 1;
			break;
		case 7:
			domain = 7;
			break;
		default:
			debug_plat_ecam("Domain %d does not exist\n", domain);
			return;
	}

	/* enable bus */
	bus_permit.u = CSR_READ_PA(node, CAVM_ECAMX_DOMX_BUSX_PERMIT(0, domain, bus));
	bus_permit.s.sec_dis = 0;
	bus_permit.s.nsec_dis = 0;
	bus_permit.s.xcp0_dis = 0;
	bus_permit.s.xcp1_dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_DOMX_BUSX_PERMIT(0, domain, bus), bus_permit.u);
	debug_plat_ecam("enable_bus N%d:E%d:DOM%d:B%d\n", node, 0, domain, bus);
}

static inline void cn93xx_disable_bus(int node, int domain, int bus)
{
	union cavm_ecamx_domx_busx_permit bus_permit;

	switch (domain) {
		case 0:
			domain = 0;
			break;
		case 1:
			domain = 1;
			break;
		case 7:
			domain = 7;
			break;
		default:
			debug_plat_ecam("Domain %d does not exist\n", domain);
			return;
	}

	/* disable bus */
	bus_permit.u = CSR_READ_PA(node, CAVM_ECAMX_DOMX_BUSX_PERMIT(0, domain, bus));
	bus_permit.s.sec_dis = 0;
	bus_permit.s.nsec_dis = 1;
	bus_permit.s.xcp0_dis = 0;
	bus_permit.s.xcp1_dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_DOMX_BUSX_PERMIT(0, domain, bus), bus_permit.u);
	debug_plat_ecam("disable_bus N%d:E%d:DOM%d:B%d\n", node, 0, domain, bus);
}

static inline void cn93xx_enable_dev(int node, int domain, int dev)
{
	union cavm_ecamx_domx_devx_permit dev_permit;

	switch (domain) {
		case 0:
			domain = 0;
			break;
		case 1:
			domain = 1;
			break;
		case 7:
			domain = 7;
			break;
		default:
			debug_plat_ecam("Domain %d does not exist\n", domain);
			return;
	}

	/* enable dev */
	dev_permit.u = CSR_READ_PA(node, CAVM_ECAMX_DOMX_DEVX_PERMIT(0, domain, dev));
	dev_permit.s.sec_dis = 0;
	dev_permit.s.nsec_dis = 0;
	dev_permit.s.xcp0_dis = 0;
	dev_permit.s.xcp1_dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_DOMX_DEVX_PERMIT(0, domain, dev), dev_permit.u);
	debug_plat_ecam("enable_dev N%d:E%d:DOM%d:DEV%d\n", node, 0, domain, dev);
}

static inline void cn93xx_disable_dev(int node, int domain, int dev)
{
	union cavm_ecamx_domx_devx_permit dev_permit;

	switch (domain) {
		case 0:
			domain = 0;
			break;
		case 1:
			domain = 1;
			break;
		case 7:
			domain = 7;
			break;
		default:
			debug_plat_ecam("Domain %d does not exist\n", domain);
			return;
	}

	/* disable dev */
	dev_permit.u = CSR_READ_PA(node, CAVM_ECAMX_DOMX_DEVX_PERMIT(0, domain, dev));
	dev_permit.s.sec_dis = 0;
	dev_permit.s.nsec_dis = 1;
	dev_permit.s.xcp0_dis = 0;
	dev_permit.s.xcp1_dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_DOMX_DEVX_PERMIT(0, domain, dev), dev_permit.u);
	debug_plat_ecam("disable_dev N%d:E%d:DOM%d:DEV%d\n", node, 0, domain, dev);
}

static inline void cn93xx_enable_func(int node, int domain, int func)
{
	union cavm_ecamx_domx_rslx_permit rsl_permit;

	switch (domain) {
		case 0:
			domain = 0;
			break;
		case 1:
			domain = 1;
			break;
		case 7:
			domain = 7;
			break;
		default:
			debug_plat_ecam("Domain %d does not exist\n", domain);
			return;
	}

	/* enable func */
	rsl_permit.u = CSR_READ_PA(node, CAVM_ECAMX_DOMX_RSLX_PERMIT(0, domain, func));
	rsl_permit.s.sec_dis = 0;
	rsl_permit.s.nsec_dis = 0;
	rsl_permit.s.xcp0_dis = 0;
	rsl_permit.s.xcp1_dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_DOMX_RSLX_PERMIT(0, domain, func), rsl_permit.u);
	debug_plat_ecam("enable_func N%d:E%d:DOM%d:F%d\n", node, 0, domain, func);
}

static inline void cn93xx_disable_func(int node, int domain, int func)
{
	union cavm_ecamx_domx_rslx_permit rsl_permit;

	switch (domain) {
		case 0:
			domain = 0;
			break;
		case 1:
			domain = 1;
			break;
		case 7:
			domain = 7;
			break;
		default:
			debug_plat_ecam("Domain %d does not exist\n", domain);
			return;
	}

	/* disable func */
	rsl_permit.u = CSR_READ_PA(node, CAVM_ECAMX_DOMX_RSLX_PERMIT(0, domain, func));
	rsl_permit.s.sec_dis = 0;
	rsl_permit.s.nsec_dis = 1;
	rsl_permit.s.xcp0_dis = 0;
	rsl_permit.s.xcp1_dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_DOMX_RSLX_PERMIT(0, domain, func), rsl_permit.u);
	debug_plat_ecam("disable_func N%d:E%d:DOM%d:F%d\n", node, 0, domain, func);
}
const struct ecam_platform_defs ecam_devices_ops = {
	.soc_type = T93PARTNUM,
	.get_dev_idx = cn93xx_get_dev_idx,
	.get_max_bus = cn93xx_get_max_bus,
	.get_config_addr = cn93xx_get_config_addr,
	.get_config_size = cn93xx_get_config_size,
	.enable_bus = cn93xx_enable_bus,
	.disable_bus = cn93xx_disable_bus,
	.enable_dev = cn93xx_enable_dev,
	.disable_dev = cn93xx_disable_dev,
	.enable_func = cn93xx_enable_func,
	.disable_func = cn93xx_disable_func,
	.disable_device_on_bus = cn93xx_disable_device_on_bus,
};
