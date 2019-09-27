/*
 * Copyright (C) 2016-2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef __GPIO_OCTEONTX_H__
#define __GPIO_OCTEONTX_H__

struct gpio_irq {
	volatile uint64_t sp;
	volatile uint64_t cpu;
	volatile uint64_t ttbr0;
	volatile uint64_t ttbr1;
	volatile uint64_t isr_base;
	volatile uint64_t tcr;
	volatile uint64_t counter;
	volatile uint64_t el_mode;
	volatile int lock;
	volatile int in_use;
	volatile int in_use_ready;
};

/* Driver API */
int gpio_set_out(int pin);
int gpio_clr_out(int pin);

void plat_gpio_irq_setup(void);
void plat_set_gpio_msix_vectors(int gpio_num, int irq_num, int enable);
uint64_t gpio_irq_handler(uint32_t id, uint32_t flags, void *cookie);
int octeontx_register_gpio_handlers(void);
int gpio_install_irq(uint64_t gpio_num, uint64_t sp, uint64_t  cpu,
		     uint64_t isr_base);
void gpio_clear_irq(uint64_t gpio_num);

extern int gpio_intercept_interrupts;
extern volatile struct gpio_irq gpio_ints[MAX_GPIO_INTERRUPTS];
extern uint64_t gpio_intrx_base;

#endif /* __GPIO_OCTEONTX_H__ */
