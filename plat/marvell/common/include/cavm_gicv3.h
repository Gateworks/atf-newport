#ifndef __CAVM_GICV3_H__
#define __CAVM_GICV3_H__

/* The following are already defined in gic_private.h
 * We need these to do special setting than the default when GIC is initialized
 */

/*
 * Macro to convert an mpidr to a value suitable for programming into a
 * GICD_IROUTER. Bits[31:24] in the MPIDR are cleared as they are not relevant
 * to GICv3.
 */
#define gicd_irouter_val_from_mpidr(mpidr, irm)		\
	((mpidr & ~(0xff << 24)) |			\
	 (irm & IROUTER_IRM_MASK) << IROUTER_IRM_SHIFT)

static inline void gicd_write_irouter(uintptr_t base,
				      unsigned int id,
				      unsigned long long affinity)
{
	assert(id >= MIN_SPI_ID);
	*((volatile uint64_t *)(base + GICD_IROUTER + (id << 3))) = affinity;
}

static unsigned int gicd_read_icfgr(uintptr_t base, unsigned int id)
{
	unsigned int n = id >> ICFGR_SHIFT;

	return *((volatile uint32_t *)(base + GICD_ICFGR + (n << 2)));
}

static void gicd_write_icfgr(uintptr_t base, unsigned int id, unsigned int val)
{
	unsigned int n = id >> ICFGR_SHIFT;

	*((volatile uint32_t *)(base + GICD_ICFGR + (n << 2))) = val;
}

#endif
