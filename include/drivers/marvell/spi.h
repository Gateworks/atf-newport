/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __SPI_H__
#define __SPI_H__

/* Flag used to change configuration of SPI */
#define	SPI_CS_HIGH		0x04		/* CS active high */
#define	SPI_LSB_FIRST		0x08		/* per-word bits-on-wire */
#define	SPI_3WIRE		0x10		/* SI/SO signals shared */
#define SPI_FORCE_X1_READ	0x20
#define SPI_FORCE_LEGACY_MODE	0x40

#define PLL_REF_CLK_CN8XXX	50000000	/* 50 MHz */
#define PLL_REF_CLK_CN9XXX	100000000	/* 100 MHz */

/* Max data per one transfer in legacy mode (CN8xxx) */
#define MPI_MAX_DATA	8

/* MPI_WIDE_BUF has 144 registers. Each is 64 bit, so contains 8 bytes. */
#define MPI_MAX_DATA_CN9XXX	(144 * 8)

#define SPI_NOR_CMD_READ		0x03
#define SPI_NOR_CMD_READ_FAST		0x0b
#define SPI_NOR_CMD_QREAD		0x6b

#define SPI_NOR_CMD_WREN		0x06
#define SPI_NOR_CMD_WRDI		0x04

#define SPI_NOR_CMD_PROGRAM		0x02

#define SPI_NOR_CMD_ERASE		0x20

#define SPI_NOR_CMD_RDSR		0x5

#define SPI_STATUS_WIP			(1 << 0)

#define SPI_ADDRESSING_24BIT		24
#define SPI_ADDRESSING_32BIT		32

#define SPI_PAGE_SIZE			256

#define SPI_NOR_PROGRAM_TIMEOUT		1000		/* 1 sec */
#define SPI_NOR_ERASE_TIMEOUT		2000		/* 2 sec */
#define CONFIG_SPI_FREQUENCY		16000000

typedef struct {
	/*
	 * Use the 'in_use' flag as any value for base and file_pos could be
	 * valid.
	 */
	int		in_use;
	unsigned int	spi_con;
	unsigned int	cs;
	size_t		file_pos;
	size_t		offset_address;
} file_state_t;

#endif /* __SPI_H__ */
