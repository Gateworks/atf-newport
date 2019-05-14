/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __OCTEONTX_IRQS_DEF_H__
#define __OCTEONTX_IRQS_DEF_H__

#include <platform_irqs_def.h>

/*******************************************************************************
 * If platform doesn't specify defines for device
 * lets fill it with the default data.
 * If there is no irq of certain type, than -1 is returned by macro.
 ******************************************************************************/

/* UAA definitons */
#ifndef UAA_SPI_IRQ
/* Default there is no UAA device */
#define UAA_SPI_IRQ_DEVS		0x0
#define UAA_SPI_IRQ(dev)		-1
#endif

/* PEM definitions */
#ifndef PEM_SPI_IRQ
/* Default there is no PEM device */
#define PEM_SPI_IRQ_DEVS		0x0
#define PEM_SPI_IRQS_PER_DEV	0x0
#define PEM_SPI_IRQ(dev, irq)	-1
#endif

/* SMMU definitions */
#ifndef SMMU_SPI_IRQ
/* Default there is no SMMU device */
#define SMMU_SPI_IRQ_DEVS		0x0
#define SMMU_SPI_IRQS_PER_DEV	0x0
#define SMMU_SPI_IRQ(dev, irq)	-1
#endif

/* Base SPI for GPIO interrupt to be handled in ATF */
#ifndef GPIO_SPI_IRQ
/* Default there is no GPIO interrupt */
#define GPIO_SPI_IRQS			0x0
#define GPIO_SPI_IRQ(irq)		-1
#endif

/* Default SPI to be used by kernel GPIO driver when intercepting interrupts */
#ifndef GPIO_SPI_IRQ_NSEC
/* Default there is no SPI for kernel GPIO driver */
#define GPIO_SPI_NSEC_IRQS		0x0
#define GPIO_SPI_IRQ_NSEC(irq)	-1
#endif

/* BPHY definitions */
#ifndef BPHY_PSM_IRQ
#define BPHY_PSM_IRQS_NUMBER	0x0
#define BPHY_PSM_IRQ(irq)		-1
#endif

/* GTI CWD definitions */
#ifndef GTI_CWD_SPI_IRQ
#define GTI_CWD_SPI_IRQS	0x0
#define GTI_CWD_SPI_IRQ(irq)		-1
#endif

#endif /* __OCTEONTX_IRQS_DEF_H__ */
