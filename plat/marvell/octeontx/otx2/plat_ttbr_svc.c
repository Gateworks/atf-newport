/*
 * Copyright (C) 2019 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <arch_helpers.h>
#include <octeontx_common.h>
#include <plat_ttbr_svc.h>

DEFINE_SYSREG_RW_FUNCS(ttbr1_el2)

int set_ttbr(uint64_t ttbr, uint64_t value)
{
	uint32_t daif;
	uint32_t daif_mask =
		(DAIF_FIQ_BIT | DAIF_IRQ_BIT | DAIF_ABT_BIT) << SPSR_DAIF_SHIFT;

	if (ttbr < 0 || ttbr > TTBR_LAST)
		return TTBR_INV_ARG;

	/* Save oryginal interrupt mask state */
	daif = read_daif();
	write_daif(daif & daif_mask);

	switch (ttbr) {
	case TTBR0_EL1:
		write_ttbr0_el1(value);
		break;

	case TTBR1_EL1:
		write_ttbr1_el1(value);
		break;

	case TTBR0_EL2:
		write_ttbr0_el2(value);
		break;

	case TTBR1_EL2:
		write_ttbr1_el2(value);
		break;

	case VTTBR_EL2:
		write_vttbr_el2(value);
		break;

	default:
		return TTBR_INV_ARG;
	}

	write_cvm_evattid_el1(0);
	/* Restore interrupts */
	write_daif(daif);

	return TTBR_OK;
}
