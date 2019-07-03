/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __MMC_H__
#define __MMC_H__

#define MMC_READ	0
#define MMC_WRITE	1

#define SHARED_MEM_BASE (TZDRAM_BASE + TZDRAM_SIZE)

#define ROUND_UP(val, align)	(((val) + (align) - 1) / (align) * (align))

/*
 * Some large devices (32GB Samsung EVO) have shown timeouts with a watchdog of
 * 500ms. The 750ms values is to give a 50% margin
 */
#define MMC_WATCHDOG_MS 750 /* In milliseconds */
#define MMC_CLOCK_HZ    10000000

#define SIZE_2GB	0x80000000

#define REF_FREQ	50000 /* number of reference cycles in a millisecond */
#define INIT_MAX_RETRY	20
#define MMC_SECTOR_SIZE	512

#define CMD_NO_DATA 	0
#define CMD_READ_DBUF	1
#define CMD_WRITE_DBUF	2
#define RESP_NONE	0
#define RESP_R1		1
#define RESP_R2		2
#define RESP_R3		3
#define RESP_R4		4
#define RESP_R5		5
#define RESP_R6		0

#define BUS_1_BIT	0
#define BUS_4_BIT	1
#define BUS_8_BIT	2

#define MMC_CMD_GO_IDLE_STATE		0
#define MMC_CMD_SEND_OP_COND		1
#define MMC_CMD_ALL_SEND_CID		2
#define MMC_CMD_SET_RELATIVE_ADDR	3
#define MMC_CMD_SET_DSR			4
#define MMC_CMD_SWITCH			6
#define MMC_CMD_SELECT_CARD		7
#define MMC_CMD_SEND_EXT_CSD		8
#define MMC_CMD_SEND_CSD		9
#define MMC_CMD_SEND_CID		10
#define MMC_CMD_STOP_TRANSMISSION	12
#define MMC_CMD_SEND_STATUS		13
#define MMC_CMD_SET_BLOCKLEN		16
#define MMC_CMD_READ_SINGLE_BLOCK	17
#define MMC_CMD_READ_MULTIPLE_BLOCK	18
#define MMC_CMD_WRITE_SINGLE_BLOCK	24
#define MMC_CMD_WRITE_MULTIPLE_BLOCK	25
#define MMC_CMD_ERASE_GROUP_START	35
#define MMC_CMD_ERASE_GROUP_END		36
#define MMC_CMD_ERASE			38
#define MMC_CMD_APP_CMD			55
#define MMC_CMD_SPI_READ_OCR		58
#define MMC_CMD_SPI_CRC_ON_OFF		59
#define MMC_CMD_RES_MAN			62

#define SD_CMD_SEND_RELATIVE_ADDR	3
#define SD_CMD_SWITCH_FUNC		6
#define SD_CMD_SEND_IF_COND		8

#define SD_CMD_APP_SET_BUS_WIDTH	6
#define SD_CMD_ERASE_WR_BLK_START	32
#define SD_CMD_ERASE_WR_BLK_END		33
#define SD_CMD_APP_SEND_OP_COND		41
#define SD_CMD_APP_SEND_SCR		51
#define SD_CMD_SEND_OP_COND		55

/* Response from sdmmc is followed by CRC. This macro helps to get rid of it */
#define SKIP_CRC_RSP(a) ((a) >> 8)

/* When command send to sdmmc has rca as arg it has to be shifted */
#define RCA_ARG(a) ((a) << 16)

/* This macro helps to read RCA from sdmmc response */
#define GET_RCA(a) ((uint32_t)(octeontx_bit_extract(SKIP_CRC_RSP((a)), 16, 16)))

/* This macro helps to read OCR from sdmmc response */
#define GET_OCR(a) ((uint32_t)(octeontx_bit_extract(SKIP_CRC_RSP((a)), 0, 32)))

#define SD_IF_COND_ARG 0x000001AA

/*
 * Expected value of lower 40 bits in response for SD_CMD_SEND_IF_COND command
 * generated via SD card version >= 2
 */
#define EXPECTED_IF_COND_VALUE (0x0800000000 | SD_IF_COND_ARG)

#define DEFAULT_STS_MASK 0xE4390080

/* argument used in MMC_CMD_SEND_OP_COND and SD_CMD_APP_SEND_OP_COND commands */
#define OP_COND_ARG 0x40ff8000

/*
 * SD response R6 is similar to R1 but trigger bad status in response status.
 * This value mask this error.
 */
#define STS_MASK_RESP_R6 0xE000

#define DEFAULT_CLK_LO 2500

#define OCR_GET_VOLTS_1_7__1_95(reg)	octeontx_bit_extract((reg), 7, 1)
#define OCR_GET_VOLTS_2_0__2_6(reg)	octeontx_bit_extract((reg), 8, 7)
#define OCR_GET_VOLTS_2_7__3_6(reg)	octeontx_bit_extract((reg), 15, 9)
#define OCR_GET_ACCESS_MODE(reg)	octeontx_bit_extract((reg), 29, 2)
#define OCR_GET_DONE_BIT(reg)		octeontx_bit_extract((reg), 31, 1)

#define RSP_STS_GET_CMD_DONE(reg)	octeontx_bit_extract((reg), 0, 1)
#define RSP_STS_GET_CMD_IDX(reg)	octeontx_bit_extract((reg), 1, 6)
#define RSP_STS_GET_CMD_TYPE(reg)	octeontx_bit_extract((reg), 7, 2)
#define RSP_STS_GET_RSP_TYPE(reg)	octeontx_bit_extract((reg), 9, 3)
#define RSP_STS_GET_RSP_VAL(reg)	octeontx_bit_extract((reg), 12, 1)
#define RSP_STS_GET_RSP_BAD_STS(reg)	octeontx_bit_extract((reg), 13, 1)
#define RSP_STS_GET_RSP_CRC_ERR(reg)	octeontx_bit_extract((reg), 14, 1)
#define RSP_STS_GET_RSP_TIMEOUT(reg)	octeontx_bit_extract((reg), 15, 1)
#define RSP_STS_GET_STP_VAL(reg)	octeontx_bit_extract((reg), 16, 1)
#define RSP_STS_GET_STP_BAD_STS(reg)	octeontx_bit_extract((reg), 17, 1)
#define RSP_STS_GET_STP_CRC_ERR(reg)	octeontx_bit_extract((reg), 18, 1)
#define RSP_STS_GET_STP_TIMEOUT(reg)	octeontx_bit_extract((reg), 19, 1)
#define RSP_STS_GET_RSP_BUSYBIT(reg)	octeontx_bit_extract((reg), 20, 1)
#define RSP_STS_GET_BLK_CRC_ERR(reg)	octeontx_bit_extract((reg), 21, 1)
#define RSP_STS_GET_BLK_TIMEOUT(reg)	octeontx_bit_extract((reg), 22, 1)
#define RSP_STS_GET_DBUF(reg)		octeontx_bit_extract((reg), 23, 1)
#define RSP_STS_GET_DBUF_ERROR(reg)	octeontx_bit_extract((reg), 28, 1)
#define RSP_STS_GET_ACC_TIMEOUT(reg)	octeontx_bit_extract((reg), 55, 1)
#define RSP_STS_GET_DMA_PEND(reg)	octeontx_bit_extract((reg), 56, 1)
#define RSP_STS_GET_DMA_VAL(reg)	octeontx_bit_extract((reg), 57, 1)
#define RSP_STS_GET_SWITCH_VAL(reg)	octeontx_bit_extract((reg), 58, 1)
#define RSP_STS_GET_CMD_VAL(reg)	octeontx_bit_extract((reg), 59, 1)
#define RSP_STS_GET_BUS_ID(reg)		octeontx_bit_extract((reg), 60, 2)

#define MIO_EMM_CMD_SET_ARG(reg, val)		\
					octeontx_bit_insert((reg), (val), 0, 32)
#define MIO_EMM_CMD_SET_CMD_IDX(reg, val)	\
					octeontx_bit_insert((reg), (val), 32, 6)
#define MIO_EMM_CMD_SET_RTYPE(reg, val)		\
					octeontx_bit_insert((reg), (val), 38, 3)
#define MIO_EMM_CMD_SET_CTYPE(reg, val)		\
					octeontx_bit_insert((reg), (val), 41, 2)
#define MIO_EMM_CMD_SET_CMD_VAL(reg)		\
					octeontx_bit_insert((reg), 1, 59, 1)
#define MIO_EMM_CMD_SET_BUS_ID(reg, val)	\
					octeontx_bit_insert((reg), (val), 60, 2)

#define MIO_EMM_DMA_SET_CARD_ADDR(reg, val)		\
				octeontx_bit_insert((reg), (val), 0, 32)
#define MIO_EMM_DMA_SET_BLOCK_CNT(reg, val)		\
				octeontx_bit_insert((reg), (val), 32, 16)
#define MIO_EMM_DMA_SET_WRITE(reg, val)			\
				octeontx_bit_insert((reg), (val), 49, 1)
#define MIO_EMM_DMA_SET_DAT_NULL(reg)			\
				octeontx_bit_insert((reg), 1, 57, 1)
#define MIO_EMM_DMA_SET_SECTOR(reg)			\
				octeontx_bit_insert((reg), 1, 58, 1)
#define MIO_EMM_DMA_SET_DMA_VAL(reg)			\
				octeontx_bit_insert((reg), 1, 59, 1)
#define MIO_EMM_DMA_SET_BUS_ID(reg, val)		\
				octeontx_bit_insert((reg), (val), 60, 2)

/*
 * DMA engine size. Specified in the number of 64-bit transfers
 * (encoded in -1 notation). For example, to transfer 512 bytes,
 * SIZE = 64 - 1 = 63.
 */
#define MIO_EMM_DMA_BYTES_TO_SIZE(val)		(((val) >> 3) - 1)
#define MIO_EMM_DMA_CFG_SET_SIZE(reg, val)		\
				octeontx_bit_insert((reg), (val), 36, 20)
#define MIO_EMM_DMA_CFG_SET_LITTLE_ENDIAN(reg)		\
				octeontx_bit_insert((reg), 1, 56, 1)
#define MIO_EMM_DMA_CFG_SET_WRITE(reg, val)		\
				octeontx_bit_insert((reg), (val), 62, 1)
#define MIO_EMM_DMA_CFG_SET_ENABLE(reg)			\
				octeontx_bit_insert((reg), 1, 63, 1)
#define MIO_EMM_DMA_CFG_GET_ENABLE(reg)			\
				octeontx_bit_extract((reg), 63, 1)

#define MIO_EMM_MODEX_GET_CLK_LO(reg)       octeontx_bit_extract((reg), 0, 16)
#define MIO_EMM_MODEX_GET_CLK_HI(reg)       octeontx_bit_extract((reg), 16, 16)
#define MIO_EMM_MODEX_GET_POWER_CLASS(reg)  octeontx_bit_extract((reg), 32, 4)
#define MIO_EMM_MODEX_GET_BUS_WIDTH(reg)    octeontx_bit_extract((reg), 40, 3)
#define MIO_EMM_MODEX_GET_HS_TIMING(reg)    octeontx_bit_extract((reg), 48, 1)
#define MIO_EMM_MODEX_GET_HS200_TIMING(reg) octeontx_bit_extract((reg), 49, 1)
#define MIO_EMM_MODEX_GET_HS400_TIMING(reg) octeontx_bit_extract((reg), 50, 1)

#define GPIO_CFG_TX_OE(reg, val) octeontx_bit_insert((reg), (val), 0, 1)

#define RST_BOOT_GET_PNR_MUL(reg) octeontx_bit_extract((reg), 33, 6)

#define MIO_EMM_SWITCH_SET_CLK_LO(reg, val)		\
				octeontx_bit_insert((reg), (val), 0, 16)
#define MIO_EMM_SWITCH_SET_CLK_HI(reg, val)		\
				octeontx_bit_insert((reg), (val), 16, 16)
#define MIO_EMM_SWITCH_SET_POWER_CLASS(reg, val)	\
				octeontx_bit_insert((reg), (val), 32, 4)
#define MIO_EMM_SWITCH_SET_BUS_WIDTH(reg, val)		\
				octeontx_bit_insert((reg), (val), 40, 3)
#define MIO_EMM_SWITCH_SET_HS_TIMING(reg, val)		\
				octeontx_bit_insert((reg), (val), 48, 1)
#define MIO_EMM_SWITCH_SET_HS200_TIMING(reg, val)	\
				octeontx_bit_insert((reg), (val), 49, 1)
#define MIO_EMM_SWITCH_SET_HS400_TIMING(reg, val)	\
				octeontx_bit_insert((reg), (val), 50, 1)
#define MIO_EMM_SWITCH_SET_SWITHC_EXE(reg, val)		\
				octeontx_bit_insert((reg), (val), 59, 1)
#define MIO_EMM_SWITCH_SET_BUS_ID(reg, val)		\
				octeontx_bit_insert((reg), (val), 60, 2)

typedef struct sd_if_cond {
	uint64_t rsp_sts;
	uint64_t rsp_lo;
} sd_if_cond_t;

typedef struct {
	/*
	 * Use the 'in_use' flag as any value for base and file_pos could be
	 * valid.
	 */
	int	in_use;
	size_t	file_pos;
	size_t	offset_address;
} file_state_t;

typedef struct mio_emm_driver {
	int rca;
	int sector_size;
	uint8_t bus_id;
	uint8_t bus_width;
	uint8_t sector_mode;
	uint8_t is_sd;
	uint8_t is_init;
} mio_emm_driver_t;

int sdmmc_dev_init(io_dev_info_t *dev_info, const uintptr_t init_params);

#endif /* __MMC_H__ */
