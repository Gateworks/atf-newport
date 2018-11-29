/** @file

  Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

/* CGX driver for OcteonTX (CN8xxx and CN9xxx) */

#include <arch_helpers.h>
#include <assert.h>
#include <debug.h>
#include <psci.h>
#include <errno.h>
#include <gic_common.h>
#include <gicv3.h>
#include <platform.h>
#include <platform_def.h>
#include <runtime_svc.h>
#include <interrupt_mgmt.h>

#include <octeontx_ecam.h>
#include <octeontx_svc.h>
#include <octeontx_common.h>
#include <gpio_octeontx.h>

#define SPSR_ISR	((1ULL << SPSR_E_SHIFT) | (3 << SPSR_AIF_SHIFT))
#define SCR_ISR		(SCR_NS_BIT | SCR_TWE_BIT | SCR_TWI_BIT | SCR_RW_BIT)

uint64_t gpio_intrx_base;
int gpio_intercept_interrupts;

/* -------------------------------------------------------
 * Save fpregs, indicate next SMC that it just need to go
 * stright to el3_exit.
 * Stop El1 interrupts before jumping. This assumes no
 * EL2 virtualization
 * X0 holds the gpio_num,
 * X1 holds sp
 * X2 holds ttbr
 * X3 holds isr_base
 * X4 holds spsr_el3
 * X5 holds scr_el3
 * X6 holds tcr_el1
 */
void el3_start_el0_isr(uint64_t gpio_num, uint64_t sp,
		       uint64_t ttbr, uint64_t isr_base,
		       uint64_t spsr_el3, uint64_t scr_el3,
		       uint64_t tcr_el1);

static volatile int irq_cpu_lock_counter;
volatile struct gpio_irq gpio_ints[MAX_GPIO_INTERRUPTS] = {0};

struct irq_cpu {
	volatile int cpu;
	volatile int counter;
};

static volatile struct irq_cpu el3_gpio_irqs[OCTEONTX_IRQ_GPIO_COUNT] = {
	{ -1, 0 }, /* OCTEONTX_IRQ_GPIO_BASE */
	{ -1, 0 },
	{ -1, 0 },
	{ -1, 0 },
};

static void prepare_el0_isr_callback(uint64_t gpio_num, uint64_t counter)
{
	uint64_t sp;
	uint64_t ttbr;
	uint64_t isr_base;
	uint64_t tcr;

	/*
	 * This system of lock and counter looks somewhat cumbersome,
	 * however it works well for its purpose, preventing making any
	 * calls with inconsistent parameters, or calls to ISRs that are
	 * already removed.
	 *
	 * For most of the time, no locks are held, .in_use_ready
	 * indicates that the interrupt has a registered ISR, and the data
	 * is consistent. .counter increments on every update, so if by
	 * any chance it will be updated during the call, to this
	 * function, it will be found in the last moment, and ISR will not
	 * be called.
	 *
	 * Lock is held only while the ISR is called. This should be
	 * invisible for anything on the local CPU, because only we are
	 * running at this time. Other CPUs, however, will see it, and
	 * calls from them will be delayed until the ISR is finished if
	 * they will wait for this lock.
	 *
	 * If someone else is holding this lock, ISR is not called at all.
	 *
	 */
	if (__atomic_fetch_add(&gpio_ints[gpio_num].lock, 1,
			      __ATOMIC_SEQ_CST) != 0)
		goto finish;

	sp = __atomic_load_n(&gpio_ints[gpio_num].sp, __ATOMIC_SEQ_CST);
	ttbr = __atomic_load_n(&gpio_ints[gpio_num].ttbr, __ATOMIC_SEQ_CST);
	isr_base = __atomic_load_n(&gpio_ints[gpio_num].isr_base,
				   __ATOMIC_SEQ_CST);
	tcr = __atomic_load_n(&gpio_ints[gpio_num].tcr, __ATOMIC_SEQ_CST);

	if (__atomic_load_n(&gpio_ints[gpio_num].in_use_ready,
			   __ATOMIC_SEQ_CST) == 0)
		goto finish;

	if (__atomic_load_n(&gpio_ints[gpio_num].counter,
			    __ATOMIC_SEQ_CST) != counter)
		goto finish;

	el3_start_el0_isr(gpio_num, sp, ttbr, isr_base, SPSR_ISR, SCR_ISR, tcr);

finish:
	__atomic_fetch_sub(&gpio_ints[gpio_num].lock, 1, __ATOMIC_SEQ_CST);
}

uint64_t gpio_irq_handler(uint32_t id, uint32_t flags, void *cookie)
{
	uint64_t counter;
	int i, in_use_ready, index, matched = 0;
	uint64_t cpu, assigned_cpu;
	int mapped_cpu, mapped_counter;

	cpu = plat_my_core_pos();

	index = id - OCTEONTX_IRQ_GPIO_BASE;

	/* For all invalid interrupts, clear interrupt and exit. */
	if ((index < 0) || (index >= OCTEONTX_IRQ_GPIO_COUNT)) {
		ERROR("Invalid GPIO interrupt %x\n", id);
		return 0;
	}

	/*
	 * Global lock that protects CPU to IRQ mapping. Lock before
	 * accessing el3_gpio_irqs.
	 */
	while (__atomic_fetch_add(&irq_cpu_lock_counter, 1,
				 __ATOMIC_SEQ_CST) != 0)
		__atomic_fetch_sub(&irq_cpu_lock_counter, 1, __ATOMIC_SEQ_CST);

	mapped_cpu = el3_gpio_irqs[index].cpu;
	mapped_counter = el3_gpio_irqs[index].counter;

	/* Unlock */
	__atomic_fetch_sub(&irq_cpu_lock_counter, 1, __ATOMIC_SEQ_CST);

	/* For all mis-routed interrupts, clear interrupt and exit. */
	if ((mapped_counter < 1) || (mapped_cpu != cpu)) {
		ERROR("Mis-routed GPIO interrupt id 0x%x mapped cpu=%d but got intr on cpu=%lld\n",
		      id, mapped_cpu, cpu);
		return 0;
	}

	for (i = 0; i < MAX_GPIO_INTERRUPTS; i++) {
		/*
		 * Get the value of .counter before reading
		 * anything from the descriptor. If
		 * anything is or will become invalid, we
		 * will see either .in_use_ready reset, or
		 * .counter incremented.
		 */
		in_use_ready = 0;
		assigned_cpu = 0;
		counter = __atomic_load_n(&gpio_ints[i].counter,
				__ATOMIC_SEQ_CST);

		in_use_ready =
			__atomic_load_n(&gpio_ints[i].in_use_ready,
					__ATOMIC_SEQ_CST);
		if (in_use_ready != 0) {
			assigned_cpu =
				__atomic_load_n(&gpio_ints[i].cpu,
						__ATOMIC_SEQ_CST);
			/* Check for the interrupt for this GPIO */
			if ((assigned_cpu == cpu) &&
			    ((*(volatile uint64_t *)(gpio_intrx_base + 8 * i))
			     & 1)) {
				matched = 1;
				/* Call ISR wrapper */
				prepare_el0_isr_callback(i, counter);

				/* Acknowledge interrupt for this GPIO */
				*(volatile uint64_t *)(gpio_intrx_base + 8 * i)
								 = 0x1;
			}
		}
	}
	/*
	 * For all interrupts with no apparent cause on this CPU
	 */
	if (!matched) {
		ERROR("Stale GPIO interrupt %x\n", id);
		return 0;
	}
	return 0;
}

static int setup_interrupt_entries(int gpio_num, int cpu, int enable)
{
	int i, select_irq = -1;

	/*
	 * Global lock that protects CPU to IRQ mapping. Lock before
	 * accessing el3_gpio_irqs.
	 */
	while (__atomic_fetch_add(&irq_cpu_lock_counter, 1,
				 __ATOMIC_SEQ_CST) != 0)
		__atomic_fetch_sub(&irq_cpu_lock_counter, 1, __ATOMIC_SEQ_CST);

	if (enable) {
		for (i = 0, select_irq = -1;
		     (select_irq == -1) && (i < OCTEONTX_IRQ_GPIO_COUNT);
		     i++) {
			if ((el3_gpio_irqs[i].counter != 0)
			   && (el3_gpio_irqs[i].cpu == cpu)) {
				select_irq = OCTEONTX_IRQ_GPIO_BASE + i;
				el3_gpio_irqs[i].counter++;
			}
		}
		if (select_irq == -1) {
			for (i = 0;
			   (select_irq == -1) && (i < OCTEONTX_IRQ_GPIO_COUNT);
			     i++) {
				if (el3_gpio_irqs[i].counter == 0) {
					el3_gpio_irqs[i].cpu = cpu;
					el3_gpio_irqs[i].counter = 1;
					select_irq = OCTEONTX_IRQ_GPIO_BASE + i;
					gicv3_set_spi_routing(select_irq, GICV3_IRM_PE, read_mpidr());
				}
			}
		}
	} else {
		for (i = 0, select_irq = -1;
		     (select_irq == -1) && (i < OCTEONTX_IRQ_GPIO_COUNT); i++)
			if ((el3_gpio_irqs[i].counter != 0)
			    && (el3_gpio_irqs[i].cpu == cpu)) {
				select_irq = OCTEONTX_IRQ_GPIO_BASE + i;
				el3_gpio_irqs[i].counter--;
				if (el3_gpio_irqs[i].counter == 0)
					el3_gpio_irqs[i].cpu = -1;
				i = OCTEONTX_IRQ_GPIO_COUNT;
			}
	}

	if (enable)
		INFO("IRQ 0x%x for CPU %d\n", select_irq, cpu);

	plat_set_gpio_msix_vectors(gpio_num, select_irq, enable);

	__atomic_thread_fence(__ATOMIC_SEQ_CST);

	/* Unlock */
	__atomic_fetch_sub(&irq_cpu_lock_counter, 1, __ATOMIC_SEQ_CST);

	return 0;
}

int gpio_install_irq(uint64_t gpio_num, uint64_t sp, uint64_t  cpu,
		     uint64_t isr_base)
{
	int retval;

	/* Check if this functionality is available */
	if (gpio_intercept_interrupts == 0)
		return -1;

	/* Lock */
	while (__atomic_fetch_add(&gpio_ints[gpio_num].lock, 1,
				 __ATOMIC_SEQ_CST) != 0)
		__atomic_fetch_sub(&gpio_ints[gpio_num].lock, 1,
				   __ATOMIC_SEQ_CST);

	/*
	 * .in_use indicates that this GPIO is not free to be set without
	 *  releasing. It may be still in the process of being configured,
	 *  so interrupt handler can't rely on it, and should only use
	 *  .in_use_ready .
	 */
	if (__atomic_fetch_add(&gpio_ints[gpio_num].in_use, 1,
			      __ATOMIC_SEQ_CST) != 0) {
		__atomic_fetch_sub(&gpio_ints[gpio_num].in_use, 1,
				   __ATOMIC_SEQ_CST);
		retval = -1;
		ERROR("GPIO in use..cannot be configured\n");
		goto finish;
	}
	gpio_ints[gpio_num].sp = sp;
	gpio_ints[gpio_num].cpu = cpu;
	gpio_ints[gpio_num].ttbr = 0;
	gpio_ints[gpio_num].isr_base = isr_base;
	asm volatile("mrs %0, ttbr0_el1\n\t" : "=r"(gpio_ints[gpio_num].ttbr));
	gpio_ints[gpio_num].tcr = 0;
	asm volatile("mrs %0, tcr_el1\n\t" : "=r"(gpio_ints[gpio_num].tcr));
	gpio_ints[gpio_num].tcr &= ~(1ULL << 22);
	retval = setup_interrupt_entries(gpio_num, cpu, 1);
	if (retval != 0) {
		gpio_ints[gpio_num].sp = 0;
		gpio_ints[gpio_num].cpu = 0;
		gpio_ints[gpio_num].ttbr = 0;
		ERROR("Can't install irq handlerfor gpio:%llu cpu:%llu\n",
		       gpio_num, cpu);
		__atomic_thread_fence(__ATOMIC_SEQ_CST);
		/* Failure, this GPIO is free to be configured. */
		__atomic_fetch_sub(&gpio_ints[gpio_num].in_use, 1,
				   __ATOMIC_SEQ_CST);
	} else {
		INFO("Installed irq handler for gpio:%llu ttrb:%llx sp:%llx\n"
		       "\tisr_base:%llx cpu:%llu tcr:%llx\n",
		       gpio_num, gpio_ints[gpio_num].ttbr,
		       gpio_ints[gpio_num].sp,
		       gpio_ints[gpio_num].isr_base, gpio_ints[gpio_num].cpu,
		       gpio_ints[gpio_num].tcr);
		__atomic_thread_fence(__ATOMIC_SEQ_CST);
		/*
		 * Success, increment .counter, and indicate that GPIO is
		 * ready to be used by setting .in_use_ready .
		 */
		__atomic_fetch_add(&gpio_ints[gpio_num].counter, 1,
				   __ATOMIC_SEQ_CST);
		__atomic_store_n(&gpio_ints[gpio_num].in_use_ready, 1,
				 __ATOMIC_SEQ_CST);
	}

 finish:
	/* Unlock */
	__atomic_fetch_sub(&gpio_ints[gpio_num].lock, 1, __ATOMIC_SEQ_CST);
	return retval;
}

void gpio_clear_irq(uint64_t gpio_num)
{
	/* Lock */
	while (__atomic_fetch_add(&gpio_ints[gpio_num].lock, 1,
				 __ATOMIC_SEQ_CST) != 0)
		__atomic_fetch_sub(&gpio_ints[gpio_num].lock, 1,
				   __ATOMIC_SEQ_CST);

	/*
	 * Prevent ISRs from being called while hardware and descriptors
	 * are being updated.
	 */
	__atomic_store_n(&gpio_ints[gpio_num].in_use_ready, 0,
			 __ATOMIC_SEQ_CST);
	__atomic_thread_fence(__ATOMIC_SEQ_CST);

	setup_interrupt_entries(gpio_num, gpio_ints[gpio_num].cpu, 0);
	gpio_ints[gpio_num].sp = 0;
	gpio_ints[gpio_num].cpu = 0;
	gpio_ints[gpio_num].ttbr = 0;
	__atomic_thread_fence(__ATOMIC_SEQ_CST);
	do {
		/* Acknowledge interrupt for this GPIO */
		*(volatile uint64_t *)(gpio_intrx_base + 8 * gpio_num) = 0x1;
		/* Check for interrupt */
	} while ((*(volatile uint64_t *)(gpio_intrx_base + 8 * gpio_num)) & 1);
	__atomic_thread_fence(__ATOMIC_SEQ_CST);
	/*
	 * Leave this entry free for use. If by now it was not allocated in the
	 * first place, restore the in_use value.
	 */
	if (__atomic_fetch_sub(&gpio_ints[gpio_num].in_use, 1,
			       __ATOMIC_SEQ_CST) == 0)
		__atomic_fetch_add(&gpio_ints[gpio_num].in_use, 1,
				   __ATOMIC_SEQ_CST);
	/* Unlock */
	__atomic_fetch_sub(&gpio_ints[gpio_num].lock, 1, __ATOMIC_SEQ_CST);
	INFO("Removed irq handler for gpio:%llu\n", gpio_num);
}

int octeontx_register_gpio_handlers(void)
{
	int i, rc = 0;

	for (i = 0; i < OCTEONTX_IRQ_GPIO_COUNT; i++) {
		rc = register_interrupt_handler(INTR_TYPE_EL3,
						OCTEONTX_IRQ_GPIO_BASE + i,
						gpio_irq_handler);
		if (rc) {
			ERROR("err %d while registering GPIO IRQ secure interrupt handler\n",
			      rc);
			break;
		}
	}

	NOTICE("GPIO handlers registered\n");
	gpio_intrx_base = CAVM_GPIO_INTRX(0);

	return rc;
}

int gpio_set_out (int pin)
{
	cavm_gpio_tx_set_t gpio_tx_set;
	cavm_gpio_bit_cfgx_t gpio_bit_cfg;

	gpio_tx_set.u = 0;
	gpio_tx_set.s.set = (1ULL << pin);
	CSR_WRITE(CAVM_GPIO_TX_SET, gpio_tx_set.u);
	gpio_bit_cfg.u = CSR_READ(CAVM_GPIO_BIT_CFGX(pin));
	gpio_bit_cfg.s.tx_oe = 1;
	gpio_bit_cfg.s.pin_sel = 0;
	CSR_WRITE(CAVM_GPIO_BIT_CFGX(pin), gpio_bit_cfg.u);
	return 0;
}

int gpio_clr_out (int pin)
{
	cavm_gpio_bit_cfgx_t gpio_bit_cfg;
	cavm_gpio_tx_clr_t gpio_tx_clr;

	gpio_tx_clr.u = 0;
	gpio_tx_clr.s.clr = (1ULL << pin);
	CSR_WRITE(CAVM_GPIO_TX_CLR, gpio_tx_clr.u);
	gpio_bit_cfg.u = CSR_READ(CAVM_GPIO_BIT_CFGX(pin));
	gpio_bit_cfg.s.pin_sel = 0;
	gpio_bit_cfg.s.tx_oe = 1;
	CSR_WRITE(CAVM_GPIO_BIT_CFGX(pin), gpio_bit_cfg.u);
	return 0;
}


