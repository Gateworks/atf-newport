/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __PLATFORM_IRQS_DEF_H__
#define __PLATFORM_IRQS_DEF_H__

/*******************************************************************************
 * Definitions of IRQs
 ******************************************************************************/

/* Definitions of IRQ SGI (Software Generated Interrupt) IDs (range 0x0 - 0xf) */
#define SGI_IRQ_OFFSET			0x0

/* Definitions of IRQ PPI (Per-Processor Interrupt) IDs (range 0x10 - 0x1f) */
#define PPI_IRQ_OFFSET			0x10

/* Secure physical generic timer IRQ (interrupt 0xd)*/
#define SEC_TIMER_PPI_IRQ_BASE	(0xd + PPI_IRQ_OFFSET)
#define SEC_TIMER_PPI_IRQ		(SEC_TIMER_PPI_IRQ_BASE)


/* Definitions of IRQ SPI (Shared Peripheral Interrupt) IDs (range 0x20-0x3FC) */
#define SPI_IRQ_OFFSET			0x20

/* UAA definitons (range 0x20 - 0x27) */
#define UAA_SPI_IRQ_DEVS		0x8
#define UAA_SPI_IRQ_BASE		(0x0 + SPI_IRQ_OFFSET)
#define UAA_SPI_IRQ(dev)		((dev) + UAA_SPI_IRQ_BASE)

/* Watchdog interrupt (interrupt 0x28)*/
#define GTI_WATCHDOG_SPI_IRQ_BASE		(UAA_SPI_IRQ_BASE + UAA_SPI_IRQ_DEVS)
#define GTI_WATCHDOG_SPI_IRQ_DEVS		0x1
#define GTI_WATCHDOG_SPI_IRQ(dev)		(GTI_WATCHDOG_SPI_IRQ_BASE)

/* PEM definitions (range 0x29 - 0x38) */
/*
 * T96 has 4 PEMs
 */
#define PEM_SPI_IRQ_DEVS		0x4

/*
 * Each of PEM has 4 interrupts
 * (INTA, INTB, INTC, INTD)
 */
#define PEM_SPI_IRQS_PER_DEV			0x4

#define PEM_SPI_IRQ_BASE		(GTI_WATCHDOG_SPI_IRQ_BASE + GTI_WATCHDOG_SPI_IRQ_DEVS)
#define PEM_SPI_IRQ(dev, irq)	((dev) * PEM_SPI_IRQS_PER_DEV + (irq) + PEM_SPI_IRQ_BASE)

/* Base SPI for GPIO interrupt to be handled in ATF (range 0x39 - 0x3c)*/
#define GPIO_SPI_IRQS			0x4
#define GPIO_SPI_IRQ_BASE		(PEM_SPI_IRQ_BASE + (PEM_SPI_IRQ_DEVS*PEM_SPI_IRQS_PER_DEV))
#define GPIO_SPI_IRQ(irq)		((irq) + GPIO_SPI_IRQ_BASE)

/* Default SPI to be used by kernel GPIO driver when intercepting interrupts (interrupt 0x3d)*/
#define GPIO_SPI_NSEC_IRQS		0x1
#define GPIO_SPI_IRQ_NSEC_BASE	(GPIO_SPI_IRQ_BASE + GPIO_SPI_IRQS)
#define GPIO_SPI_IRQ_NSEC(irq)	((irq) + GPIO_SPI_IRQ_NSEC_BASE)

#endif /* __PLATFORM_IRQS_DEF_H__ */