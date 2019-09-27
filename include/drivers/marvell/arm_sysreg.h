/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/* ARMv8 helper functions specific to Marvell */

#ifndef _ARM_SYSREG_H_
#define _ARM_SYSREG_H_

#define ID_AA64MMFR1_EL1_VH_MASK	0xF00
#define HCR_EL2_E2H			0x400000000ULL

/* OS (Linux) in EL2 mode when VHE enabled (ID_AA64MMFR1_EL1.VH set)
 * and HCR.E2H  set, otherwise OS in EL1 mode
 * return
 * - 0 when OS running in EL1
 * - 1 when OS running in EL2
 */
static uint64_t get_os_elmode(void)
{
	uint64_t mmfr1_el1, hcr;

	asm volatile("mrs %0, hcr_el2\n\t" : "=r"(hcr));
	asm volatile("mrs %0, ID_AA64MMFR1_EL1\n\t" : "=r"(mmfr1_el1));

	if ((mmfr1_el1 & ID_AA64MMFR1_EL1_VH_MASK) &&
	    (hcr & HCR_EL2_E2H))
		return 1;

	return 0;
}
#endif /* _ARM_SYSREG_H_ */

