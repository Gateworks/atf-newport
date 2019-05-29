/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __PLATFORM_IRQS_DEF_H__
#define __PLATFORM_IRQS_DEF_H__

/*******************************************************************************
 * Definitions of IRQs
 ******************************************************************************/

/*
 * Definitions of IRQ SGI (Software Generated Interrupt)
 * IDs (range 0x0 - 0xf)
 */
#define SGI_IRQ_OFFSET			0x0

/* Definitions of IRQ PPI (Per-Processor Interrupt) IDs (range 0x10 - 0x1f) */
#define PPI_IRQ_OFFSET			0x10

/* Secure physical generic timer IRQ (interrupt 0xd)*/
#define SEC_TIMER_PPI_IRQ_BASE		(0xd + PPI_IRQ_OFFSET)
#define SEC_TIMER_PPI_IRQ		(SEC_TIMER_PPI_IRQ_BASE)


/*
 * Definitions of IRQ SPI (Shared Peripheral Interrupt)
 * IDs (range 0x20-0x3FC)
 */
#define SPI_IRQ_OFFSET			0x20

/* UAA definitons (range 0x20 - 0x27) */
#define UAA_SPI_IRQ_DEVS		0x8
#define UAA_SPI_IRQ_BASE		(0x0 + SPI_IRQ_OFFSET)
#define UAA_SPI_IRQ(dev)		((dev) + UAA_SPI_IRQ_BASE)

/* Watchdog interrupt (interrupt 0x28)*/
#define GTI_WATCHDOG_SPI_IRQ_BASE	(UAA_SPI_IRQ_BASE + UAA_SPI_IRQ_DEVS)
#define GTI_WATCHDOG_SPI_IRQ_DEVS	0x1
#define GTI_WATCHDOG_SPI_IRQ(dev)	(GTI_WATCHDOG_SPI_IRQ_BASE)

/* PEM definitions (range 0x29 - 0x2c) */
/*
 * F95 has 1 PEM
 */
#define PEM_SPI_IRQ_DEVS		0x1

/*
 * Each of PEM has 4 interrupts
 * (INTA, INTB, INTC, INTD)
 */
#define PEM_SPI_IRQS_PER_DEV		0x4

#define PEM_SPI_IRQ_BASE		(GTI_WATCHDOG_SPI_IRQ_BASE +	\
						GTI_WATCHDOG_SPI_IRQ_DEVS)
#define PEM_SPI_IRQ(dev, irq)		((dev) * PEM_SPI_IRQS_PER_DEV +	\
						(irq) + PEM_SPI_IRQ_BASE)

/* Base SPI for GPIO interrupt to be handled in ATF (range 0x2d - 0x30)*/
#define GPIO_SPI_IRQS			0x4
#define GPIO_SPI_IRQ_BASE		(PEM_SPI_IRQ_BASE + \
					(PEM_SPI_IRQ_DEVS*PEM_SPI_IRQS_PER_DEV))
#define GPIO_SPI_IRQ(irq)		((irq) + GPIO_SPI_IRQ_BASE)

/*
 * Default SPI to be used by kernel GPIO driver when intercepting interrupts
 * (interrupt 0x31)
 */
#define GPIO_SPI_NSEC_IRQS		0x1
#define GPIO_SPI_IRQ_NSEC_BASE		(GPIO_SPI_IRQ_BASE + GPIO_SPI_IRQS)
#define GPIO_SPI_IRQ_NSEC(irq)		((irq) + GPIO_SPI_IRQ_NSEC_BASE)

/*
 * BPHY PSM interrupts. They have to be in continous space.
 * (range 0x32 - 0x4D)
 */
/*
 * These 3 defines are needed to iterate through all BPHY PSM interrupts
 * in simpler way
 */
#define BPHY_PSM_IRQ_BASE	(GPIO_SPI_IRQ_NSEC_BASE + GPIO_SPI_NSEC_IRQS)
#define BPHY_PSM_IRQS_NUMBER	(END_OF_BPHY_IRQS - BPHY_PSM_IRQ_BASE)
#define BPHY_PSM_IRQ(irq)	((irq) + BPHY_PSM_IRQ_BASE)

/* interrupt 0x32 - 0x35 */
#define BPHY_PSM_GPINT_IRQS		0x4
#define BPHY_PSM_GPINT_IRQ_BASE		BPHY_PSM_IRQ_BASE
#define BPHY_PSM_GPINT_IRQ(irq)		((irq) + BPHY_PSM_GPINT_IRQ_BASE)

/* interrupt 0x36 */
#define BPHY_PSM_ERRINT_IRQS		0x1
#define BPHY_PSM_ERRINT_IRQ_BASE	(BPHY_PSM_GPINT_IRQ_BASE +	\
							BPHY_PSM_GPINT_IRQS)
#define BPHY_PSM_ERRINT_IRQ(irq)	((irq) + BPHY_PSM_ERRINT_IRQ_BASE)

/* range 0x37 - 0x38 */
#define BPHY_PSM_QOVF_IRQS		0x2
#define BPHY_PSM_QOVF_IRQ_BASE		(BPHY_PSM_ERRINT_IRQ_BASE +	\
							BPHY_PSM_ERRINT_IRQS)
#define BPHY_PSM_QOVF_IRQ(irq)		((irq) + BPHY_PSM_QOVF_IRQ_BASE)

/* range 0x39 - 0x3A */
#define BPHY_PSM_QTO_IRQS		0x2
#define BPHY_PSM_QTO_IRQ_BASE		(BPHY_PSM_QOVF_IRQ_BASE +	\
							BPHY_PSM_QOVF_IRQS)
#define BPHY_PSM_QTO_IRQ(irq)		((irq) + BPHY_PSM_QTO_IRQ_BASE)

/* range 0x3B - 0x3D */
#define BPHY_PSM_JERR_IRQS		0x3
#define BPHY_PSM_JERR_IRQ_BASE		(BPHY_PSM_QTO_IRQ_BASE +	\
							BPHY_PSM_QTO_IRQS)
#define BPHY_PSM_JERR_IRQ(irq)		((irq) + BPHY_PSM_JERR_IRQ_BASE)

/* range 0x3E - 0x40 */
#define BPHY_PSM_JNFAT_IRQS		0x3
#define BPHY_PSM_JNFAT_IRQ_BASE		(BPHY_PSM_JERR_IRQ_BASE +	\
							BPHY_PSM_JERR_IRQS)
#define BPHY_PSM_JNFAT_IRQ(irq)		((irq) + BPHY_PSM_JNFAT_IRQ_BASE)

/* range 0x41 - 0x43 */
#define BPHY_PSM_JTO_IRQS		0x3
#define BPHY_PSM_JTO_IRQ_BASE		(BPHY_PSM_JNFAT_IRQ_BASE +	\
							BPHY_PSM_JNFAT_IRQS)
#define BPHY_PSM_JTO_IRQ(irq)		((irq) + BPHY_PSM_JTO_IRQ_BASE)

/* range 0x44 - 0x46 */
#define BPHY_PSM_DERR_IRQS		0x3
#define BPHY_PSM_DERR_IRQ_BASE		(BPHY_PSM_JTO_IRQ_BASE +	\
							BPHY_PSM_JTO_IRQS)
#define BPHY_PSM_DERR_IRQ(irq)		((irq) + BPHY_PSM_DERR_IRQ_BASE)

/* range 0x47 - 0x49 */
#define BPHY_PSM_AERR_IRQS		0x3
#define BPHY_PSM_AERR_IRQ_BASE		(BPHY_PSM_DERR_IRQ_BASE +	\
							BPHY_PSM_DERR_IRQS)
#define BPHY_PSM_AERR_IRQ(irq)		((irq) + BPHY_PSM_AERR_IRQ_BASE)

/* range 0x4A - 0x4D */
#define BPHY_PSM_MTO_IRQS		0x3
#define BPHY_PSM_MTO_IRQ_BASE		(BPHY_PSM_AERR_IRQ_BASE +	\
							BPHY_PSM_AERR_IRQS)
#define BPHY_PSM_MTO_IRQ(irq)		((irq) + BPHY_PSM_MTO_IRQ_BASE)

#define END_OF_BPHY_IRQS		(BPHY_PSM_MTO_IRQ_BASE +	\
							BPHY_PSM_MTO_IRQS)
/* End of BPHY PSM interrupts */


#endif /* __PLATFORM_IRQS_DEF_H__ */
