/** @file
 *
 * Copyright (c) 2016-2018, Marvell International Ltd. All rights reserved.
 * This program and the accompanying materials
 * are licensed and made available under the terms and conditions of the BSD
 * License which accompanies this distribution.  The full text of the license
 * may be found at http://opensource.org/licenses/bsd-license.php
 *
 * THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
 * WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 *
**/
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
#include <cavm_irqs_def.h>

#include <cavm_ecam.h>
#include <cavm_svc.h>
#include <cavm_common.h>
#include <cavm_bphy.h>

#define SPSR_ISR	((1ULL << SPSR_E_SHIFT) | (3 << SPSR_AIF_SHIFT))
#define SCR_ISR		(SCR_NS_BIT | SCR_TWE_BIT | SCR_TWI_BIT | SCR_RW_BIT)

/* */
#define MAX_BPHY_PSM_INTS	23

struct bphy_psm_irq {
	volatile uint64_t sp;
	volatile uint64_t cpu;
	volatile uint64_t ttbr;
	volatile uint64_t isr_base;
	volatile uint64_t tcr;
	volatile uint64_t counter;
	volatile int lock;
	volatile int in_use;
	volatile int in_use_ready;
};

struct irq_cpu {
	volatile int cpu;
	volatile int counter;
};

/* -------------------------------------------------------
 * Save fpregs, indicate next SMC that it just need to go
 * stright to el3_exit.
 * Stop El1 interrupts before jumping. This assumes no
 * EL2 virtualization
 * X0 holds the irq_num,
 * X1 holds sp
 * X2 holds ttbr
 * X3 holds isr_base
 * X4 holds spsr_el3
 * X5 holds scr_el3
 * X6 holds tcr_el1
 */
void el3_start_el0_isr(uint64_t irq_num, uint64_t sp,
		       uint64_t ttbr, uint64_t isr_base,
		       uint64_t spsr_el3, uint64_t scr_el3,
		       uint64_t tcr_el1);

static uint64_t bphy_psm_errint_base;
static volatile int irq_cpu_lock_counter;
volatile struct bphy_psm_irq bphy_ints[MAX_BPHY_PSM_INTS] = {0};

static volatile struct irq_cpu el3_bphy_irqs[] =
	{[0 ... (BPHY_PSM_IRQS_NUMBER - 1)] = { -1, 0 }};

static void prepare_el0_isr_callback(uint64_t irq_num, uint64_t counter)
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
	if (__atomic_fetch_add(&bphy_ints[irq_num].lock, 1,
			      __ATOMIC_SEQ_CST) != 0)
		goto finish;

	sp = __atomic_load_n(&bphy_ints[irq_num].sp, __ATOMIC_SEQ_CST);
	ttbr = __atomic_load_n(&bphy_ints[irq_num].ttbr, __ATOMIC_SEQ_CST);
	isr_base = __atomic_load_n(&bphy_ints[irq_num].isr_base,
				   __ATOMIC_SEQ_CST);
	tcr = __atomic_load_n(&bphy_ints[irq_num].tcr, __ATOMIC_SEQ_CST);

	if (__atomic_load_n(&bphy_ints[irq_num].in_use_ready,
			   __ATOMIC_SEQ_CST) == 0)
		goto finish;

	if (__atomic_load_n(&bphy_ints[irq_num].counter,
			    __ATOMIC_SEQ_CST) != counter)
		goto finish;

	el3_start_el0_isr(irq_num, sp, ttbr, isr_base, SPSR_ISR, SCR_ISR, tcr);

finish:
	__atomic_fetch_sub(&bphy_ints[irq_num].lock, 1, __ATOMIC_SEQ_CST);
}

uint64_t bphy_psm_irq_handler(uint32_t id, uint32_t flags, void *cookie)
{
	uint64_t counter;
	int in_use_ready, index, matched = 0;
	uint64_t cpu, assigned_cpu;
	int mapped_cpu, mapped_counter;

	cpu = plat_my_core_pos();

	index = id - BPHY_PSM_IRQ_BASE;

	INFO("%s: id=0x%x, index=0x%x\n", __func__, id, index);
	/* For all invalid interrupts, clear interrupt and exit. */
	if ((index < 0) || (index >= BPHY_PSM_IRQS_NUMBER)) {
		ERROR("Invalid BPHY PSM interrupt %x\n", id);
		return 0;
	}

	/*
	 * Global lock that protects CPU to IRQ mapping. Lock before
	 * accessing el3_bphy_irqs.
	 */
	while (__atomic_fetch_add(&irq_cpu_lock_counter, 1,
				 __ATOMIC_SEQ_CST) != 0)
		__atomic_fetch_sub(&irq_cpu_lock_counter, 1, __ATOMIC_SEQ_CST);

	mapped_cpu = el3_bphy_irqs[index].cpu;
	mapped_counter = el3_bphy_irqs[index].counter;

	/* Unlock */
	__atomic_fetch_sub(&irq_cpu_lock_counter, 1, __ATOMIC_SEQ_CST);

	/* For all mis-routed interrupts, clear interrupt and exit. */
	if ((mapped_counter < 1) || (mapped_cpu != cpu)) {
		ERROR("Mis-routed BPHY PSM interrupt id 0x%x mapped cpu=%d but got intr on cpu=%ld\n",
		      id, mapped_cpu, cpu);
		return 0;
	}

	/*
	 * Get the value of .counter before reading
	 * anything from the descriptor. If
	 * anything is or will become invalid, we
	 * will see either .in_use_ready reset, or
	 * .counter incremented.
	 */
	in_use_ready = 0;
	assigned_cpu = 0;
	counter = __atomic_load_n(&bphy_ints[index].counter, __ATOMIC_SEQ_CST);

	in_use_ready = __atomic_load_n(&bphy_ints[index].in_use_ready,
				       __ATOMIC_SEQ_CST);
	if (in_use_ready != 0) {
		assigned_cpu = __atomic_load_n(&bphy_ints[index].cpu,
					       __ATOMIC_SEQ_CST);

		/* Check for the interrupt for this IRQ */
		if ((assigned_cpu == cpu)) {
			matched = 1;
			/* Call ISR wrapper */
			prepare_el0_isr_callback(index, counter);
		}
	}

	/*
	 * For all interrupts with no apparent cause on this CPU
	 */
	if (!matched) {
		ERROR("Stale BPHY PSM interrupt %x\n", id);
		return 0;
	}

	return 0;
}

static int setup_interrupt_entries(int irq_num, int cpu, int enable)
{
	int select_irq = -1;

	/*
	 * Global lock that protects CPU to IRQ mapping. Lock before
	 * accessing el3_bphy_irqs.
	 */
	while (__atomic_fetch_add(&irq_cpu_lock_counter, 1,
				 __ATOMIC_SEQ_CST) != 0)
		__atomic_fetch_sub(&irq_cpu_lock_counter, 1, __ATOMIC_SEQ_CST);

	if (enable) {
		if (el3_bphy_irqs[irq_num].counter == 0) {
			el3_bphy_irqs[irq_num].cpu = cpu;
			el3_bphy_irqs[irq_num].counter = 1;
			select_irq = BPHY_PSM_IRQ(irq_num);
			gicv3_set_spi_routing(select_irq,
					      GICV3_IRM_PE,
					      read_mpidr());
		} else {
			NOTICE("ERR: handler already registered for MSI-X %d\n",
			       irq_num);
			return -1;
		}
	} else {
		if ((el3_bphy_irqs[irq_num].counter != 0)
		    && (el3_bphy_irqs[irq_num].cpu == cpu)) {
			select_irq = BPHY_PSM_IRQ(irq_num);
			el3_bphy_irqs[irq_num].counter--;
			if (el3_bphy_irqs[irq_num].counter == 0)
				el3_bphy_irqs[irq_num].cpu = -1;
		}
	}

	if (enable)
		INFO("IRQ 0x%x for CPU %d\n", select_irq, cpu);

	plat_set_bphy_psm_msix_vectors(irq_num, select_irq, enable);

	__atomic_thread_fence(__ATOMIC_SEQ_CST);

	/* Unlock */
	__atomic_fetch_sub(&irq_cpu_lock_counter, 1, __ATOMIC_SEQ_CST);

	return 0;
}

int bphy_psm_install_irq(uint64_t irq_num, uint64_t sp, uint64_t  cpu,
			 uint64_t isr_base)
{
	int retval;

	INFO("Entering %s\n", __func__);
	/* Lock */
	while (__atomic_fetch_add(&bphy_ints[irq_num].lock, 1,
				 __ATOMIC_SEQ_CST) != 0)
		__atomic_fetch_sub(&bphy_ints[irq_num].lock, 1,
				   __ATOMIC_SEQ_CST);

	/*
	 * .in_use indicates that this is not free to be set without
	 *  releasing. It may be still in the process of being configured,
	 *  so interrupt handler can't rely on it, and should only use
	 *  .in_use_ready .
	 */
	if (__atomic_fetch_add(&bphy_ints[irq_num].in_use, 1,
			      __ATOMIC_SEQ_CST) != 0) {
		__atomic_fetch_sub(&bphy_ints[irq_num].in_use, 1,
				   __ATOMIC_SEQ_CST);
		retval = -1;
		ERROR("IRQ in use..cannot be configured\n");
		goto finish;
	}
	bphy_ints[irq_num].sp = sp;
	bphy_ints[irq_num].cpu = cpu;
	bphy_ints[irq_num].ttbr = 0;
	bphy_ints[irq_num].isr_base = isr_base;
	asm volatile("mrs %0, ttbr0_el1\n\t" : "=r"(bphy_ints[irq_num].ttbr));
	bphy_ints[irq_num].tcr = 0;
	asm volatile("mrs %0, tcr_el1\n\t" : "=r"(bphy_ints[irq_num].tcr));
	bphy_ints[irq_num].tcr &= ~(1ULL << 22);
	retval = setup_interrupt_entries(irq_num, cpu, 1);
	if (retval != 0) {
		bphy_ints[irq_num].sp = 0;
		bphy_ints[irq_num].cpu = 0;
		bphy_ints[irq_num].ttbr = 0;
		ERROR("Can't install irq handler for bphy psm:%lu cpu:%lu\n",
		       irq_num, cpu);
		__atomic_thread_fence(__ATOMIC_SEQ_CST);
		/* Failure, this IRQ is free to be configured. */
		__atomic_fetch_sub(&bphy_ints[irq_num].in_use, 1,
				   __ATOMIC_SEQ_CST);
	} else {
		INFO("Installed irq handler for bphy psm:%lu ttrb:%lx sp:%lx\n"
		       "\tisr_base:%lx cpu:%lu tcr:%lx\n",
		       irq_num, bphy_ints[irq_num].ttbr,
		       bphy_ints[irq_num].sp,
		       bphy_ints[irq_num].isr_base, bphy_ints[irq_num].cpu,
		       bphy_ints[irq_num].tcr);
		__atomic_thread_fence(__ATOMIC_SEQ_CST);
		/*
		 * Success, increment .counter, and indicate that IRQ is
		 * ready to be used by setting .in_use_ready .
		 */
		__atomic_fetch_add(&bphy_ints[irq_num].counter, 1,
				   __ATOMIC_SEQ_CST);
		__atomic_store_n(&bphy_ints[irq_num].in_use_ready, 1,
				 __ATOMIC_SEQ_CST);
	}

 finish:
	/* Unlock */
	__atomic_fetch_sub(&bphy_ints[irq_num].lock, 1, __ATOMIC_SEQ_CST);
	return retval;
}

void bphy_psm_clear_irq(uint64_t irq_num)
{
	INFO("%s\n", __func__);
	/* Lock */
	while (__atomic_fetch_add(&bphy_ints[irq_num].lock, 1,
				 __ATOMIC_SEQ_CST) != 0)
		__atomic_fetch_sub(&bphy_ints[irq_num].lock, 1,
				   __ATOMIC_SEQ_CST);

	/*
	 * Prevent ISRs from being called while hardware and descriptors
	 * are being updated.
	 */
	__atomic_store_n(&bphy_ints[irq_num].in_use_ready, 0,
			 __ATOMIC_SEQ_CST);
	__atomic_thread_fence(__ATOMIC_SEQ_CST);

	setup_interrupt_entries(irq_num, bphy_ints[irq_num].cpu, 0);
	bphy_ints[irq_num].sp = 0;
	bphy_ints[irq_num].cpu = 0;
	bphy_ints[irq_num].ttbr = 0;
	__atomic_thread_fence(__ATOMIC_SEQ_CST);

	bphy_psm_errint_base = ~(0ull);

	__atomic_thread_fence(__ATOMIC_SEQ_CST);
	/*
	 * Leave this entry free for use. If by now it was not allocated in the
	 * first place, restore the in_use value.
	 */
	if (__atomic_fetch_sub(&bphy_ints[irq_num].in_use, 1,
			       __ATOMIC_SEQ_CST) == 0)
		__atomic_fetch_add(&bphy_ints[irq_num].in_use, 1,
				   __ATOMIC_SEQ_CST);
	/* Unlock */
	__atomic_fetch_sub(&bphy_ints[irq_num].lock, 1, __ATOMIC_SEQ_CST);
	INFO("Removed irq handler for bphy psm:%lu\n", irq_num);
}

int cavm_register_bphy_intr_handlers(void)
{
	int i, rc = 0;

	for (i = 0; i < MAX_BPHY_PSM_INTS; i++) {
		rc = register_interrupt_handler(INTR_TYPE_EL3,
						BPHY_PSM_IRQ(i), bphy_psm_irq_handler);
		if (rc) {
			ERROR("err %d registering BPHY secure IRQ handler\n", rc);
			break;
		}
	}

	bphy_psm_errint_base = CAVM_PSM_INT_ERRINT_SUM_W1C;

	NOTICE("Bphy intr handlers registered\n");

	return rc;
}

