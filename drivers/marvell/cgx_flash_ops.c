/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/* CGX Flash helpers for OcteonTX2 */

#include <arch.h>
#include <stdio.h>
#include <string.h>
#include <libfdt.h>
#include <debug.h>
#include <spi.h>
#include <delay_timer.h>
#include <platform_def.h>
#include <platform_dt.h>
#include <octeontx_common.h>
#include <plat_board_cfg.h>
#include <cgx.h>
#include <octeontx_utils.h>

/* define DEBUG_ATF_CGX_FLASH to enable debug logs */
#undef DEBUG_ATF_CGX_FLASH

#ifdef DEBUG_ATF_CGX_FLASH
#define debug_cgx_flash printf
#else
#define debug_cgx_flash(...) ((void) (0))
#endif

/* Fixed flash offset for storage of lmac params */
#define	SPI_NVDATA_OFFSET 0xFD0000

extern uint32_t spi_mode;

static void cgx_fdt_get_spi_bus_cs(int *bus, int *cs)
{
	const void *fdt = fdt_ptr;
	const uint32_t *reg, *preg;
	int node, addr;

	*bus = -1;
	*cs = -1;
	if (fdt_check_header(fdt))
		return;
	node = fdt_node_offset_by_compatible(fdt, -1, "spi-flash");
	while (node > 0) {
		if (fdt_getprop(fdt, node, "u-boot,env", NULL)) {
			reg = fdt_getprop(fdt, node, "reg", NULL);
			if (reg)
				*cs = fdt32_to_cpu(*reg);
			preg = fdt_getprop(fdt, fdt_parent_offset(fdt, node),
					  "reg", NULL);
			if (preg) {
				addr = fdt32_to_cpu(*preg);
				/* SPI node will have PCI addr, so map it */
				if (addr == 0x3000)
					*bus = 0;
				if (addr == 0x3800)
					*bus = 1;
			}
			debug_cgx_flash("\n Env SPI [bus:cs] [%d:%d]\n",
					*bus, *cs);
			break;
		}
		node = fdt_node_offset_by_compatible(fdt, node, "spi-flash");
	}
}

static int cgx_read_flash_lmac_params(uint8_t *buf, int buflen)
{
	int err = 0, spi_con, cs;

	cgx_fdt_get_spi_bus_cs(&spi_con, &cs);
	if (spi_con == -1 || cs == -1)
		return -1;
	err = spi_config(CONFIG_SPI_FREQUENCY, 0, 0, 0, spi_con, cs);
	if (err < 0) {
		debug_cgx_flash("Config flash failed for lmac params\n");
		return -1;
	}
	spi_mode |= SPI_FORCE_X1_READ;

	err = spi_nor_read(buf, buflen, SPI_NVDATA_OFFSET,
			   SPI_ADDRESSING_24BIT, spi_con, cs);
	if (err < 0)
		debug_cgx_flash("Read flash failed for lmac params\n");
	spi_mode &= ~SPI_FORCE_X1_READ;
	return err;
}

int cgx_read_flash_fec(int cgx_id, int lmac_id, int *fec)
{
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac;
	cgx_lmac_flash_ctx_t *ptr;
	cgx_lmac_flash_ctx_t fctx[MAX_CGX * MAX_LMAC_PER_CGX];
	int ret;

	cgx = &(plat_octeontx_bcfg->cgx_cfg[cgx_id]);
	lmac = &cgx->lmac_cfg[lmac_id];

	ret = cgx_read_flash_lmac_params((uint8_t *)fctx, sizeof(fctx));
	if (ret < 0)
		return -1;
	ptr = &fctx[cgx_id * MAX_LMAC_PER_CGX + lmac_id];

	if (!ptr->s.valid || !ptr->s.fec_valid || ptr->s.cgx_id != cgx_id ||
	    ptr->s.lmac_id != lmac_id || ptr->s.qlm_mode != lmac->mode_idx)
		return -1;

	*fec = ptr->s.fec_type;
	return 0;
}

int cgx_read_flash_phy_mod(int cgx_id, int lmac_id, int *phy_mod)
{
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac;
	cgx_lmac_flash_ctx_t *ptr;
	cgx_lmac_flash_ctx_t fctx[MAX_CGX * MAX_LMAC_PER_CGX];
	int ret;

	cgx = &(plat_octeontx_bcfg->cgx_cfg[cgx_id]);
	lmac = &cgx->lmac_cfg[lmac_id];

	ret = cgx_read_flash_lmac_params((uint8_t *)fctx, sizeof(fctx));
	if (ret < 0)
		return -1;
	ptr = &fctx[cgx_id * MAX_LMAC_PER_CGX + lmac_id];

	if (!ptr->s.valid || !ptr->s.mod_valid || ptr->s.cgx_id != cgx_id ||
	    ptr->s.lmac_id != lmac_id || ptr->s.qlm_mode != lmac->mode_idx)
		return -1;

	*phy_mod = ptr->s.mod_type;
	return 0;
}

static int cgx_update_flash_lmac_params(int cgx_id, int lmac_id, int fec,
				  int phy_mod)
{
	cgx_config_t *cgx;
	cgx_lmac_config_t *lmac;
	cgx_lmac_flash_ctx_t fctx[MAX_CGX * MAX_LMAC_PER_CGX];
	cgx_lmac_flash_ctx_t *ptr;
	int err, spi_con, cs;

	cgx = &(plat_octeontx_bcfg->cgx_cfg[cgx_id]);
	lmac = &cgx->lmac_cfg[lmac_id];
	cgx_fdt_get_spi_bus_cs(&spi_con, &cs);
	if (spi_con == -1 || cs == -1)
		return -1;

	err = cgx_read_flash_lmac_params((uint8_t *)fctx, sizeof(fctx));
	if (err < 0) {
		debug_cgx_flash("Read flash failed for lmac params\n");
		return -1;
	}
	ptr = &fctx[cgx_id * MAX_LMAC_PER_CGX + lmac_id];
	ptr->s.valid = 1;
	ptr->s.cgx_id = cgx_id;
	ptr->s.lmac_id = lmac_id;
	ptr->s.qlm_mode = lmac->mode_idx;
	if (fec != 0xF) {
		ptr->s.fec_type = fec;
		ptr->s.fec_valid = 1;
	}
	if (phy_mod != 0xF) {
		ptr->s.mod_type = phy_mod;
		ptr->s.mod_valid = 1;
	}

	err = spi_nor_erase(SPI_NVDATA_OFFSET, SPI_ADDRESSING_24BIT, spi_con,
			    cs);
	if (err < 0) {
		debug_cgx_flash("Erase flash failed for lmac params\n");
		return -1;
	}
	err = spi_nor_write((uint8_t *)fctx, sizeof(fctx), SPI_NVDATA_OFFSET,
			    SPI_ADDRESSING_24BIT, spi_con, cs);
	if (err < 0) {
		debug_cgx_flash("Write flash failed for lmac params\n");
		return -1;
	}
	return 0;
}

int cgx_update_flash_fec_param(int cgx_id, int lmac_id, int fec)
{
	return cgx_update_flash_lmac_params(cgx_id, lmac_id, fec, 0xF);
}

int cgx_update_flash_phy_mod_param(int cgx_id, int lmac_id, int phy_mod)
{
	return cgx_update_flash_lmac_params(cgx_id, lmac_id, 0xF, phy_mod);
}

