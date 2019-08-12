/*
 * Copyright (C) 2016-2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/* MMC driver for OcteonTX (CN8xxx and CN9xxx) */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <platform_def.h>
#include <octeontx_common.h>
#include <io_storage.h>
#include <assert.h>
#include <io_driver.h>
#include <debug.h>
#include <plat_board_cfg.h>
#include <octeontx_security.h>
#include <octeontx_utils.h>

#include <io_mmc.h>
#include <mmc.h>

static file_state_t mmc_current_file = { 0 };
static mio_emm_driver_t mmc_drv = { 0 };

/* Wait for delay reference cycles */
static void wait(uint64_t delay)
{
	uint64_t count = CSR_READ(CAVM_RST_REF_CNTR);
	uint64_t end = count + delay;

	do {
		count = CSR_READ(CAVM_RST_REF_CNTR);
	} while (count < end);
}

static int print_rsp_sts_errors(uint64_t emm_rsp_sts)
{
	int error_count = 0;

	if (RSP_STS_GET_RSP_BAD_STS(emm_rsp_sts) ||
	    RSP_STS_GET_STP_BAD_STS(emm_rsp_sts)) {
		ERROR("MMC: Response bad status\n");
		error_count++;
	}
	if (RSP_STS_GET_RSP_CRC_ERR(emm_rsp_sts) ||
	    RSP_STS_GET_STP_CRC_ERR(emm_rsp_sts)) {
		ERROR("MMC: Response CRC error.\n");
		error_count++;
	}
	if (RSP_STS_GET_RSP_TIMEOUT(emm_rsp_sts) ||
	    RSP_STS_GET_STP_TIMEOUT(emm_rsp_sts)) {
		ERROR("MMC: Response timeout error.\n");
		error_count++;
	}
	if (RSP_STS_GET_BLK_CRC_ERR(emm_rsp_sts)) {
		ERROR("MMC: Read/write block CRC error.\n");
		error_count++;
	}
	if (RSP_STS_GET_BLK_TIMEOUT(emm_rsp_sts)) {
		ERROR("MMC: Read/write block timeout error.\n");
		error_count++;
	}
	if (RSP_STS_GET_DBUF_ERROR(emm_rsp_sts)) {
		ERROR("MMC: Dbuf error, no free buffer\n");
		error_count++;
	}

	return error_count;
}

static uint64_t mio_emm_cmd(uint32_t cmd_idx, uint32_t ctype_xor,
	uint32_t rtype_xor, uint32_t arg, int suppress_warning)
{
	uint64_t cmd;
	int cmd_error = 0;
	uint64_t emm_rsp_sts = 0;

	cmd = 0;
	cmd = MIO_EMM_CMD_SET_CMD_VAL(cmd);
	cmd = MIO_EMM_CMD_SET_RTYPE(cmd, rtype_xor);
	cmd = MIO_EMM_CMD_SET_CTYPE(cmd, ctype_xor);
	cmd = MIO_EMM_CMD_SET_ARG(cmd, arg);
	cmd = MIO_EMM_CMD_SET_CMD_IDX(cmd, cmd_idx);
	cmd = MIO_EMM_CMD_SET_BUS_ID(cmd, mmc_drv.bus_id);

	CSR_WRITE(CAVM_MIO_EMM_CMD, cmd);

	do {
		emm_rsp_sts = CSR_READ(CAVM_MIO_EMM_RSP_STS);
	} while (!RSP_STS_GET_CMD_DONE(emm_rsp_sts));

	if (RSP_STS_GET_RSP_VAL(emm_rsp_sts) ||
	    RSP_STS_GET_STP_VAL(emm_rsp_sts)) {
		cmd_error = print_rsp_sts_errors(emm_rsp_sts);
		if (cmd_error)
			return emm_rsp_sts;
	} else {
		if (cmd_idx != MMC_CMD_GO_IDLE_STATE &&
		    cmd_idx != MMC_CMD_SET_DSR) {
			if (!suppress_warning) {
				ERROR("MMC: No valid response\n"
					"              cmd     = 0x%016llx\n"
					"              rsp_sts = 0x%016llx\n",
					cmd, emm_rsp_sts);
			}

			return emm_rsp_sts;
		}
	}

	return 0;
}

static int sdmmc_rw_block(int write, uint64_t addr, uint32_t blk_cnt,
	uintptr_t buf)
{
	int blks;
	int dma_retry_count;
	int transfer_size;

	uint64_t mio_emm_dma;
	uint64_t emm_dma_cfg;
	uint64_t emm_rsp_sts;

	if (buf == 0) {
		WARN("%s: buf is NULL\n", __func__);

		return -1;
	}

	if (buf >= TZDRAM_BASE + TZDRAM_SIZE)
		octeontx_configure_mmc_security(0); /* non-secure */
	else
		octeontx_configure_mmc_security(1); /* secure */

	/* DMA engine address must be 64-bit aligned */
	assert(!((uintptr_t)buf & 0x7));

	while (blk_cnt > 0) {
		blks = (blk_cnt > 8) ? 8 : blk_cnt;
		transfer_size = blks * mmc_drv.sector_size;

		emm_dma_cfg = 0;
		mio_emm_dma = 0;

		emm_dma_cfg = MIO_EMM_DMA_CFG_SET_ENABLE(emm_dma_cfg);
		emm_dma_cfg = MIO_EMM_DMA_CFG_SET_WRITE(emm_dma_cfg, write ?
							MMC_WRITE : MMC_READ);
		emm_dma_cfg = MIO_EMM_DMA_CFG_SET_LITTLE_ENDIAN(emm_dma_cfg);
		emm_dma_cfg = MIO_EMM_DMA_CFG_SET_SIZE(emm_dma_cfg,
				MIO_EMM_DMA_BYTES_TO_SIZE(transfer_size));

		mio_emm_dma = MIO_EMM_DMA_SET_DMA_VAL(mio_emm_dma);
		mio_emm_dma = MIO_EMM_DMA_SET_BUS_ID(
					mio_emm_dma, mmc_drv.bus_id);
		if (mmc_drv.sector_mode) {
			mio_emm_dma = MIO_EMM_DMA_SET_SECTOR(mio_emm_dma);
			mio_emm_dma = MIO_EMM_DMA_SET_CARD_ADDR(mio_emm_dma,
						addr / mmc_drv.sector_size);
		} else {
			mio_emm_dma = MIO_EMM_DMA_SET_CARD_ADDR(mio_emm_dma,
						addr);
		}
		mio_emm_dma = MIO_EMM_DMA_SET_BLOCK_CNT(mio_emm_dma, blks);
		mio_emm_dma = MIO_EMM_DMA_SET_WRITE(mio_emm_dma, write ?
							MMC_WRITE : MMC_READ);

		CSR_WRITE(CAVM_MIO_EMM_DMA_ADR, buf);
		CSR_WRITE(CAVM_MIO_EMM_DMA_CFG, emm_dma_cfg);
		CSR_WRITE(CAVM_MIO_EMM_DMA, mio_emm_dma);

		do {
			emm_rsp_sts = CSR_READ(CAVM_MIO_EMM_RSP_STS);
		} while (RSP_STS_GET_DMA_VAL(emm_rsp_sts));

		dma_retry_count = 0;
		/* DMA error retry */
		while (RSP_STS_GET_DMA_PEND(emm_rsp_sts) &&
			dma_retry_count < 3) {

			dma_retry_count++;
			INFO("MMC: DMA error, retry %d\n"
				"                rsp_sts: 0x%016llx\n"
				"                rsp_lo : 0x%016llx\n",
				dma_retry_count, emm_rsp_sts,
				(unsigned long long)CSR_READ(
							CAVM_MIO_EMM_RSP_LO));
			print_rsp_sts_errors(emm_rsp_sts);
			mio_emm_dma = CSR_READ(CAVM_MIO_EMM_DMA);
			mio_emm_dma = MIO_EMM_DMA_SET_DMA_VAL(mio_emm_dma);
			CSR_WRITE(CAVM_MIO_EMM_DMA, mio_emm_dma);
			do {
				emm_rsp_sts = CSR_READ(CAVM_MIO_EMM_RSP_STS);
			} while (RSP_STS_GET_DMA_VAL(emm_rsp_sts));
		}
		/* DMA error */
		if (RSP_STS_GET_DMA_PEND(emm_rsp_sts)) {
			ERROR("MMC: sdmmc: DMA error\n");

			mio_emm_dma = CSR_READ(CAVM_MIO_EMM_DMA);
			mio_emm_dma = MIO_EMM_DMA_SET_DMA_VAL(mio_emm_dma);
			mio_emm_dma = MIO_EMM_DMA_SET_DAT_NULL(mio_emm_dma);
			CSR_WRITE(CAVM_MIO_EMM_DMA, mio_emm_dma);
			do {
				emm_rsp_sts = CSR_READ(CAVM_MIO_EMM_RSP_STS);
			} while (RSP_STS_GET_DMA_VAL(emm_rsp_sts));

			return -2;
		}

		do {
			emm_dma_cfg = CSR_READ(CAVM_MIO_EMM_DMA_CFG);
		} while (MIO_EMM_DMA_CFG_GET_ENABLE(emm_dma_cfg));

		blk_cnt -= blks;
		addr += transfer_size;
		buf += transfer_size;
	}

	octeontx_configure_mmc_security(0); /* non-secure */
	return 0;
}


static int sdmmc_rw_data(int write, unsigned int addr, int size, uintptr_t buf)
{
	int blk_cnt, offset, bytes;
	/* DMA engine address must be 64-bit aligned */
	__aligned(8) char tmp_buf[MMC_SECTOR_SIZE];
	int transfer_size;
	int unaligned_buf;

	if (size == 0) {
		WARN("Invalid size %d\n", size);
		return -1;
	}

	if (mmc_drv.sector_mode &&
	   (uint64_t)addr + size > UINT32_MAX * (uint64_t)mmc_drv.sector_size) {
		WARN("Range 0x%llx - 0x%llx is to big for sector mode card\n",
			(uint64_t)addr, (uint64_t)addr + size);

		return -2;
	}

	if (!mmc_drv.sector_mode &&
	   (uint64_t)addr + size > SIZE_2GB) {
		WARN("Range 0x%llx - 0x%llx is to big for byte mode card\n",
			(uint64_t)addr, (uint64_t)addr + size);

		return -3;
	}


	offset = addr % mmc_drv.sector_size;
	unaligned_buf = ((buf - offset) & 0x7);
	if (unaligned_buf)
		WARN("unaligned buf address (0x%lx; offset 0x%x)\n",
			buf, offset);

	/*
	 * addr represent address on sd/mmc card so it should be alligned
	 * to sector_size
	 */
	addr -= offset;
	bytes = 0;

	if (offset) {
		/* First block must be copied to tmp_buf */
		if (sdmmc_rw_block(/* write = */ 0, addr,
			/* blk_cnt = */ 1, (uintptr_t)tmp_buf))
			return -4;
		/* Number of bytes to read/write from first block */
		bytes = MIN(size, mmc_drv.sector_size - offset);
		if (write) {
			memcpy((void *)(tmp_buf + offset), (void *)buf, bytes);
			if (sdmmc_rw_block(/* write = */ 1, addr,
				/* blk_cnt = */ 1, (uintptr_t)tmp_buf))
				return -5;
		} else {
			memcpy((void *)buf, (void *)(tmp_buf + offset), bytes);
		}
		buf += bytes;
		size -= bytes;
		addr += mmc_drv.sector_size;
	}

	blk_cnt = size / mmc_drv.sector_size;
	/* Read/write whole blocks */
	if (unaligned_buf) {
		/*
		 * This is fallback mechanism, when buffer is unaligned.
		 * It requires to copy each block to the tmp_buf which is
		 * aligned.
		 */
		transfer_size = mmc_drv.sector_size;
		while (blk_cnt > 0) {
			if (write)
				memcpy((void *)tmp_buf, (void *)buf,
					transfer_size);
			if (sdmmc_rw_block(write, addr, /* blk_cnt = */ 1,
				(uintptr_t)tmp_buf))
				return -1;
			if (!write)
				memcpy((void *)buf, (void *)tmp_buf,
					transfer_size);
			blk_cnt--;
			size -= transfer_size;
			addr += transfer_size;
			buf += transfer_size;
			bytes += transfer_size;
		}
	}
	if (blk_cnt > 0) {
		/*
		 * When buf is aligned, sdmmc_rw_block use buf address directly
		 * in DMA and handle transfering multiple blocks at the time.
		 */
		if (sdmmc_rw_block(write, addr, blk_cnt, buf))
			return -1;
		transfer_size = blk_cnt * mmc_drv.sector_size;
		size -= transfer_size;
		addr += transfer_size;
		buf += transfer_size;
		bytes += transfer_size;
	}

	if (size > 0) {
		/* Read/write last remaining block */
		if (sdmmc_rw_block(/* write = */ 0, addr,
			/* blk_cnt = */ 1, (uintptr_t)tmp_buf))
			return -1;

		if (write) {
			memcpy((void *)tmp_buf, (void *)buf, size);
			if (sdmmc_rw_block(/* write = */ 1, addr,
				/* blk_cnt = */ 1, (uintptr_t)tmp_buf))
				return -1;
		} else {
			memcpy((void *)buf, (void *)tmp_buf, size);
		}
		bytes += size;
	}

	return bytes;
}

/* Identify the device type as emmc */
static io_type_t device_type_emmc(void)
{
	return IO_TYPE_EMMC;
}

static int emmc_block_open(io_dev_info_t *dev_info, const uintptr_t spec,
		io_entity_t *entity)
{
	int result = -ENOMEM;
	const io_block_spec_t *block_spec = (io_block_spec_t *)spec;

	/*
	 * Since we need to track open state for seek() we only allow one open
	 * spec at a time. When we have dynamic memory we can malloc and set
	 * entity->info.
	 */

	if (mmc_current_file.in_use == 0) {
		assert(block_spec != NULL);
		assert(entity != NULL);

		mmc_current_file.in_use = 1;
		/* File cursor offset for seek and incremental reads etc. */
		mmc_current_file.file_pos = 0;
		mmc_current_file.offset_address = block_spec->offset;

		entity->info = (uintptr_t)&mmc_current_file;

		return 0;
	} else {
		WARN("An emmc device is already active. Close first.\n");
	}

	return result;
}

static int emmc_block_seek(io_entity_t *entity, int mode,
		ssize_t offset)
{
	int result = -ENOENT;

	/* We only support IO_SEEK_SET and CUR for the moment. */
	if (mode == IO_SEEK_SET) {
		assert(entity != NULL);

		/* TODO: can we do some basic limit checks on seek? */
		((file_state_t *)entity->info)->file_pos = offset;
		result = 0;
	} else if (mode == IO_SEEK_CUR) {
		assert(entity != NULL);

		/* TODO: can we do some basic limit checks on seek? */
		((file_state_t *)entity->info)->file_pos += offset;
		result = 0;
	}

	return result;
}


/*
 * This func should only come for reading NS image size
 */
static int emmc_block_size(io_entity_t *entity, size_t *length)
{
	file_state_t *fp;
	uint64_t offset = 0x480000;
	int ret;
	unsigned char *buffer = (unsigned char*)SHARED_MEM_BASE;

	assert(entity != NULL);
	fp = (file_state_t *)entity->info;

	ret = sdmmc_rw_data(0, offset + fp->file_pos, 1024, (uintptr_t) buffer);
	if (ret < 0)
		return ret;

	*length = *(size_t *)(buffer + (2 * 0x100));

	return 0;
}

static int emmc_block_read(io_entity_t *entity, uintptr_t buffer,
		size_t length, size_t *length_read)
{
	file_state_t *fp;
	ssize_t ret;
	unsigned int addr;

	assert(entity != NULL);
	assert(buffer != (uintptr_t)NULL);
	assert(length_read != NULL);

	fp = (file_state_t *)entity->info;

	addr = fp->offset_address + fp->file_pos;

	ret = sdmmc_rw_data(0, addr, length, buffer);
	if (ret < 0)
		return ret;

	*length_read = ret;
	fp->file_pos += ret;

	return 0;
}

static int emmc_block_close(io_entity_t *entity)
{
	assert(entity != NULL);

	entity->info = 0;

	/* This would be a mem free() if we had malloc. */
	memset((void *)&mmc_current_file, 0, sizeof(mmc_current_file));

	return 0;
}

static void sdmmc_set_watchdog(unsigned int time_in_ms)
{
	unsigned int wdog_value;
	uint64_t rst_boot;
	uint64_t mio_emm_modex;

	mio_emm_modex = CSR_READ(CAVM_MIO_EMM_MODEX(mmc_drv.bus_id));
	rst_boot = CSR_READ(CAVM_RST_BOOT);
	wdog_value = RST_BOOT_GET_PNR_MUL(rst_boot) * REF_FREQ * time_in_ms;
	wdog_value /= (MIO_EMM_MODEX_GET_CLK_LO(mio_emm_modex) +
				MIO_EMM_MODEX_GET_CLK_HI(mio_emm_modex));
	CSR_WRITE(CAVM_MIO_EMM_WDOG, wdog_value);
}

static inline void sdmmc_power_cycle(void)
{
	uint64_t gpio_bit_cfgx;
	uint64_t mio_emm_modex;

	/*
	 * Disable buses, causes the clocking to reset to the default
	 * Errata (EMMC-26703) EMMC CSR reset doesn't consistently work
	 */
	mio_emm_modex = CSR_READ(CAVM_MIO_EMM_MODEX(mmc_drv.bus_id));
	while (MIO_EMM_MODEX_GET_CLK_LO(mio_emm_modex) != DEFAULT_CLK_LO) {
		CSR_WRITE(CAVM_MIO_EMM_CFG, 0x0);
		CSR_WRITE(CAVM_MIO_EMM_CFG, 0x1 << mmc_drv.bus_id);
		mio_emm_modex = CSR_READ(CAVM_MIO_EMM_MODEX(mmc_drv.bus_id));
	}
	wait(200 * REF_FREQ);

	// Disable buses and reset device using GPIO8
	CSR_WRITE(CAVM_MIO_EMM_CFG, 0x0);
	gpio_bit_cfgx = CSR_READ(CAVM_GPIO_BIT_CFGX(8));
	gpio_bit_cfgx = GPIO_CFG_TX_OE(gpio_bit_cfgx, 1);
	CSR_WRITE(CAVM_GPIO_BIT_CFGX(8), gpio_bit_cfgx);
	wait(1 * REF_FREQ);
	CSR_WRITE(CAVM_GPIO_TX_CLR, 0x1 << 8);
	wait(200 * REF_FREQ);
	CSR_WRITE(CAVM_GPIO_TX_SET, 0x1 << 8);
	wait(2 * REF_FREQ);

	// Enable bus
	CSR_WRITE(CAVM_MIO_EMM_CFG, 0x1 << mmc_drv.bus_id);

	// Reset the status mask reg., boot will change it
	CSR_WRITE(CAVM_MIO_EMM_STS_MASK, DEFAULT_STS_MASK);
	wait(2 * REF_FREQ);

	sdmmc_set_watchdog(MMC_WATCHDOG_MS);
}

static inline void reset_card(void)
{
	mio_emm_cmd(MMC_CMD_GO_IDLE_STATE, CMD_NO_DATA, RESP_NONE,
		0 /* = arg */, 0 /* = suppress_warning */);
}

static inline uint64_t sdmmc_all_send_cid(void)
{
	return mio_emm_cmd(MMC_CMD_ALL_SEND_CID, CMD_NO_DATA, RESP_NONE,
			0 /* = arg */, 0 /* = suppress_warning */);
}

/*
 * Allow to distinguish SD version 2 >= and MMC
 * Only SD version 2 >= will have rsp_sts == 0
 */
static inline sd_if_cond_t sdmmc_send_if_cond_cmd(void)
{
	sd_if_cond_t rsp;

	if (!strncmp(plat_octeontx_bcfg->bcfg.board_model, "emul-", 5)) {
		/* This always fails on the emulator so save boot time */
		rsp.rsp_sts = -1;
		return rsp;
	}

	rsp.rsp_sts = mio_emm_cmd(SD_CMD_SEND_IF_COND, CMD_READ_DBUF, RESP_R2,
				SD_IF_COND_ARG, 1 /* = suppress_warning */);
	rsp.rsp_lo = CSR_READ(CAVM_MIO_EMM_RSP_LO);
	return rsp;
}

static inline uint32_t sd_ver_2_above_get_ocr(sd_if_cond_t sd_if_cond)
{
	uint64_t emm_rsp_sts;
	uint64_t emm_rsp_lo;
	uint32_t ocr;

	/* suppress warning about uninitialized */
	ocr = 0;
	/* We may have an SD card, as it should respond */
	if (octeontx_bit_extract(SKIP_CRC_RSP(sd_if_cond.rsp_lo), 0, 40) !=
	    EXPECTED_IF_COND_VALUE) {
		ERROR("MMC: Unexpected response from SD_CMD_SEND_IF_COND\n");
		mmc_drv.is_sd = 0;
		return ocr;
	}
	/* Send a ACMD 41 */
	do {
		emm_rsp_sts = mio_emm_cmd(SD_CMD_SEND_OP_COND,
				CMD_NO_DATA, RESP_NONE, 0 /* = arg */,
				0 /* = suppress_warning */);

		if (emm_rsp_sts == 0x0) {
			emm_rsp_sts = mio_emm_cmd(SD_CMD_APP_SEND_OP_COND,
					CMD_NO_DATA, RESP_R3, OP_COND_ARG,
					0 /* = suppress_warning */);
			if (emm_rsp_sts) {
				ERROR("MMC: Failed to recognize card\n");
				mmc_drv.is_sd = 0;
				return ocr;
			}
			mmc_drv.is_sd = 1;
		} else {
			/* Failed, not sure what's out there */
			ERROR("MMC: Failed to recognize card\n");
			mmc_drv.is_sd = 0;
			return ocr;
		}

		emm_rsp_lo = CSR_READ(CAVM_MIO_EMM_RSP_LO);
		ocr = GET_OCR(emm_rsp_lo);
	} while (!OCR_GET_DONE_BIT(ocr));

	return ocr;
}

/*
 * Valid OCR has done_bit set to 1.
 * When function return OCR == 0 that indicate error.
 */
static inline uint32_t sdmmc_send_op_cond_cmd(void)
{
	uint64_t emm_rsp_sts;
	uint64_t emm_rsp_lo;
	uint32_t ocr;

	do {
		emm_rsp_sts = mio_emm_cmd(MMC_CMD_SEND_OP_COND,
				CMD_NO_DATA, RESP_NONE, OP_COND_ARG,
				0 /* = suppress_warning */);
		if (emm_rsp_sts) {
			ERROR("MMC: Failed to recognize card\n");
			ocr = 0;
			return ocr;
		}
		emm_rsp_lo = CSR_READ(CAVM_MIO_EMM_RSP_LO);
		ocr = GET_OCR(emm_rsp_lo);
	} while (!OCR_GET_DONE_BIT(ocr));

	return ocr;
}

static inline uint32_t sdmmc_get_ocr(void)
{
	uint64_t emm_rsp_sts;
	uint64_t emm_rsp_lo;
	uint32_t ocr;

	ocr = 0;
	/* Send a ACMD 41 */
	do {
		if (!strncmp(plat_octeontx_bcfg->bcfg.board_model,
			"emul-", 5)) {
			/* This always fails on the emulator so save time */
			emm_rsp_sts = -1;
		} else {
			emm_rsp_sts = mio_emm_cmd(SD_CMD_SEND_OP_COND,
					CMD_NO_DATA, RESP_NONE, 0 /* = arg */,
					1 /* = suppress_warning */);
		}
		if (emm_rsp_sts == 0x0) {
			emm_rsp_sts = mio_emm_cmd(SD_CMD_APP_SEND_OP_COND,
					CMD_NO_DATA, RESP_R3, OP_COND_ARG,
					0 /* = suppress_warning */);
			if (emm_rsp_sts) {
				/* Have an SD card, version less than 2. */
				mmc_drv.is_sd = 1;
				return sdmmc_send_op_cond_cmd();
			}
		} else {
			/* APP_CMD command failed */
			mmc_drv.is_sd = 0;
			return sdmmc_send_op_cond_cmd();
		}

		emm_rsp_lo = CSR_READ(CAVM_MIO_EMM_RSP_LO);
		ocr = GET_OCR(emm_rsp_lo);
	} while (!OCR_GET_DONE_BIT(ocr));

	mmc_drv.is_sd = 1;
	return ocr;
}

static inline int sd_get_rca(void)
{
	uint64_t emm_rsp_sts;
	uint64_t emm_rsp_lo;
	uint64_t sts_mask;

	/*
	 * For SD, read the relative address from the card
	 * CMD3 response for SD cards is R6 format, similar to R1, but different
	 * Need to chaneg the mio_EMM_STS_MASK register so we don't get
	 * a response status error
	 */
	sts_mask = CSR_READ(CAVM_MIO_EMM_STS_MASK);
	CSR_WRITE(CAVM_MIO_EMM_STS_MASK, STS_MASK_RESP_R6);

	emm_rsp_sts = mio_emm_cmd(SD_CMD_SEND_RELATIVE_ADDR, CMD_NO_DATA,
			RESP_R6, 0 /* = arg */, 0 /* = suppress_warning */);
	CSR_WRITE(CAVM_MIO_EMM_STS_MASK, sts_mask);
	if (emm_rsp_sts) {
		ERROR("MMC: Filed to get rca.\n");
		return -1;
	}
	emm_rsp_lo = CSR_READ(CAVM_MIO_EMM_RSP_LO);

	return GET_RCA(emm_rsp_lo);
}

static inline uint64_t mmc_set_rca(void)
{
	return mio_emm_cmd(MMC_CMD_SET_RELATIVE_ADDR, CMD_NO_DATA, RESP_NONE,
			RCA_ARG(mmc_drv.rca), 0 /* = suppress_warning */);
}

static inline uint64_t sdmmc_select_card(void)
{
	return mio_emm_cmd(MMC_CMD_SELECT_CARD, CMD_NO_DATA, RESP_NONE,
			RCA_ARG(mmc_drv.rca), 0 /* = suppress_warning */);
}

static inline uint64_t sdmmc_send_card_status(void)
{
	return mio_emm_cmd(MMC_CMD_SEND_STATUS, CMD_NO_DATA, RESP_NONE,
			RCA_ARG(mmc_drv.rca), 0 /* = suppress_warning */);
}

static void sdmmc_switch_clock(int clock_hz)
{
	int clock;
	uint64_t rst_boot;
	uint64_t emm_switch;
	uint64_t mio_emm_modex;

	rst_boot = CSR_READ(CAVM_RST_BOOT);
	clock = RST_BOOT_GET_PNR_MUL(rst_boot) * REF_FREQ * 1000;
	clock /= clock_hz;
	clock /= 2; /* half time for hi and half for lo */

	mio_emm_modex = CSR_READ(CAVM_MIO_EMM_MODEX(mmc_drv.bus_id));
	emm_switch = 0;
	emm_switch = MIO_EMM_SWITCH_SET_CLK_LO(emm_switch, clock);
	emm_switch = MIO_EMM_SWITCH_SET_CLK_HI(emm_switch, clock);
	emm_switch = MIO_EMM_SWITCH_SET_SWITHC_EXE(emm_switch, 0);
	emm_switch = MIO_EMM_SWITCH_SET_HS_TIMING(emm_switch,
				MIO_EMM_MODEX_GET_HS_TIMING(mio_emm_modex));
	emm_switch = MIO_EMM_SWITCH_SET_BUS_WIDTH(emm_switch,
				MIO_EMM_MODEX_GET_BUS_WIDTH(mio_emm_modex));
	emm_switch = MIO_EMM_SWITCH_SET_POWER_CLASS(emm_switch,
				MIO_EMM_MODEX_GET_POWER_CLASS(mio_emm_modex));
	emm_switch = MIO_EMM_SWITCH_SET_BUS_ID(emm_switch, mmc_drv.bus_id);

	CSR_WRITE(CAVM_MIO_EMM_SWITCH, emm_switch);
	wait(2 * REF_FREQ);

	sdmmc_set_watchdog(MMC_WATCHDOG_MS);
}

static inline int emmc_is_dev_initialized(void)
{
	if (!mmc_drv.is_init)
		return 0;

	/*
	 * if bus_id didn't change then device is already initialized
	 * with correct parameters
	 */
	return mmc_drv.bus_id == plat_octeontx_bcfg->bcfg.boot_dev.cs;
}

int sdmmc_dev_init(io_dev_info_t *dev_info, const uintptr_t init_params)
{
	uint64_t emm_rsp_sts;
	sd_if_cond_t sd_if_cond;
	uint32_t ocr;

	if (emmc_is_dev_initialized()) {
		INFO("MMC: Device already initialized, skip emmc_dev_init\n");
		return 0;
	}

	mmc_drv.is_init = 0;
	mmc_drv.bus_id = plat_octeontx_bcfg->bcfg.boot_dev.cs;
	mmc_drv.sector_size = MMC_SECTOR_SIZE;

	sdmmc_power_cycle();
	reset_card();

	sd_if_cond = sdmmc_send_if_cond_cmd();
	if (sd_if_cond.rsp_sts == 0x0) {
		/* We may have an SD card */
		ocr = sd_ver_2_above_get_ocr(sd_if_cond);
		if (!mmc_drv.is_sd)
			return -1;
	} else {
		/* Card could be an SD version less than 2.0 or an MMC card */
		ocr = sdmmc_get_ocr();
		if (!OCR_GET_DONE_BIT(ocr))
			return -1;
	}
	mmc_drv.sector_mode = OCR_GET_ACCESS_MODE(ocr);

	emm_rsp_sts = sdmmc_all_send_cid();
	if (emm_rsp_sts) {
		ERROR("MMC: Failed to send command all send cid.\n");
		return -1;
	}

	if (mmc_drv.is_sd) {
		mmc_drv.rca = sd_get_rca();
		if (mmc_drv.rca == -1)
			return -1;
	} else {
		mmc_drv.rca = 1;
		emm_rsp_sts = mmc_set_rca();
		if (emm_rsp_sts) {
			ERROR("MMC: Failed to set rca.\n");
			return -1;
		}
	}

	CSR_WRITE(CAVM_MIO_EMM_RCA, mmc_drv.rca);

	emm_rsp_sts = sdmmc_select_card();
	if (emm_rsp_sts) {
		ERROR("MMC: Failed to select card.\n");
		return -1;
	}
	emm_rsp_sts = sdmmc_send_card_status();
	if (emm_rsp_sts) {
		ERROR("MMC: Failed to send card status.\n");
		return -1;
	}

	/* Do not set clock over 100MHz, for more info see errata EMM-35321 */
	sdmmc_switch_clock(MMC_CLOCK_HZ);

	mmc_drv.is_init = 1;
	return 0;
}

static int emmc_dev_close(io_dev_info_t *dev_info)
{
	/* NOP */
	/* TODO: Consider tracking open files and cleaning them up here */
	return 0;
}



static const io_dev_funcs_t emmc_dev_funcs = {
	.type = device_type_emmc,
	.open = emmc_block_open,
	.seek = emmc_block_seek,
	.size = emmc_block_size,
	.read = emmc_block_read,
	.write = NULL,
	.close = emmc_block_close,
	.dev_init = sdmmc_dev_init,
	.dev_close = emmc_dev_close,
};


/* No state associated with this device so structure can be const */
static const io_dev_info_t emmc_dev_info = {
	.funcs = &emmc_dev_funcs,
	.info = (uintptr_t)NULL
};

/* Open a connection to the emmc device */
static int emmc_dev_open(const uintptr_t dev_spec __attribute__((unused)),
		io_dev_info_t **dev_info)
{
	assert(dev_info != NULL);
	*dev_info = (io_dev_info_t *)&emmc_dev_info; /* cast away const */

	return 0;
}


static const io_dev_connector_t emmc_dev_connector = {
	.dev_open = emmc_dev_open
};

/* Exported functions */

/* Register the emmc driver with the IO abstraction */
int register_io_dev_emmc(const io_dev_connector_t **dev_con)
{
	int result;
	assert(dev_con != NULL);

	result = io_register_device(&emmc_dev_info);
	if (result == 0)
		*dev_con = &emmc_dev_connector;

	return result;
}
