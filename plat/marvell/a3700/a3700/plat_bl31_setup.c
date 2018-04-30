/*
 * Copyright (C) 2016 - 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:	BSD-3-Clause
 * https://spdx.org/licenses
 */
#include <a3700_dram_cs.h>
#include <dram_win.h>
#include <io_addr_dec.h>
#include <mmio.h>
#include <plat_config.h>
#include <plat_marvell.h>
#include <plat_private.h>
#include <sys_info.h>

/* This function passes DRAM cpu decode window information in ATF to sys info */
static void pass_dram_sys_info(struct dram_win_map *win_map)
{
	uint32_t win_id;
	struct dram_win *win;

	for (win_id = 0; win_id < DRAM_WIN_MAP_NUM_MAX; win_id++) {
		win = win_map->dram_windows + win_id;
		if (win_id < win_map->dram_win_num) {
			set_info(CPU_DEC_WIN0_BASE + win_id, win->base_addr);
			set_info(CPU_DEC_WIN0_SIZE + win_id, win->win_size);
		} else {
			set_info(CPU_DEC_WIN0_SIZE + win_id, 0);
		}

	}
}

/* This routine does MPP initialization */
static void marvell_bl31_mpp_init(void)
{
	mmio_clrbits_32(MVEBU_NB_GPIO_SEL_REG, 1 << MVEBU_GPIO_TW1_GPIO_EN_OFF);

	/* Set hidden GPIO setting for SPI.
	 * In north_bridge_pin_out_en_high register 13804,
	 * bit 28 is the one which enables CS, CLK pins to be
	 * output, need to set it to 1.
	 * The initial value of this bit is 1, but in UART boot mode
	 * initialization, this bit is disabled and the SPI CS and CLK pins
	 * are used for downloading image purpose; so after downloading,
	 * we should set this bit to 1 again to enable SPI CS and CLK pins.
	 * And anyway, this bit value should be 1 in all modes,
	 * so here we does not judge boot mode and set this bit to 1 always.
	 */
	mmio_setbits_32(MVEBU_NB_GPIO_OUTPUT_EN_HIGH_REG, 1 << MVEBU_GPIO_NB_SPI_PIN_MODE_OFF);
}

/* This function overruns the same function in marvell_bl31_setup.c */
void bl31_plat_arch_setup(void)
{
	struct dec_win_config *io_dec_map;
	uint32_t dec_win_num;
	struct dram_win_map dram_wins_map;

	marvell_bl31_plat_arch_setup();

	/* MPP init */
	marvell_bl31_mpp_init();

	/* initialize the timer for delay functionality */
	plat_delay_timer_init();

	/* CPU address decoder windows initialization. */
	cpu_wins_init();

	/* fetch CPU-DRAM window mapping information by reading
	 * CPU-DRAM decode windows (only the enabled ones)
	 */
	dram_win_map_build(&dram_wins_map);

	/* Pass DRAM cpu decode window information
	 * so that u-boot could get it later
	 */
	pass_dram_sys_info(&dram_wins_map);

	/* Get IO address decoder windows */
	if (marvell_get_io_dec_win_conf(&io_dec_map, &dec_win_num)) {
		printf("No IO address decoder windows configurations found!\n");
		return;
	}

	/* IO address decoder init */
	if (init_io_addr_dec(&dram_wins_map, io_dec_map, dec_win_num)) {
		printf("IO address decoder windows initialization failed!\n");
		return;
	}
}
