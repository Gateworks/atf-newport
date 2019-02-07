/*
 * Copyright (C) 2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#include <debug.h>
#include <assert.h>
#include <context.h>
#include <platform.h>
#include <platform_def.h>
#include <platform_setup.h>
#include <plat_flr.h>

/* Global structures for FLR _SEL handling */
rvu_af_bar2_sel_t blk_af_bar2_sel[BLKADDR_MAX];

static struct blk_entry block_map[] = {
	{ .enabled = 1, .block = BLKADDR_RVUM },
	{ .enabled = 0, .block = BLKADDR_LMT },
	{ .enabled = 0, .block = BLKADDR_MSIX },
	{ .enabled = 1, .block = BLKADDR_NPA },
	{ .enabled = 1, .block = BLKADDR_NIX0 },
	{ .enabled = 0, .block = BLKADDR_NIX1 },
	{ .enabled = 0, .block = BLKADDR_NPC },
	{ .enabled = 1, .block = BLKADDR_SSO },
	{ .enabled = 1, .block = BLKADDR_SSOW },
	{ .enabled = 1, .block = BLKADDR_TIM },
	{ .enabled = 1, .block = BLKADDR_CPT0 },
	{ .enabled = 0, .block = BLKADDR_CPT1 },
	{ .enabled = 0, .block = BLKADDR_NDC0 },
	{ .enabled = 0, .block = BLKADDR_NDC1 },
	{ .enabled = 0, .block = BLKADDR_NDC2 },
	{ 0 },
};

static inline uint64_t read_gp_reg(void *h, uint64_t *mask, uint8_t *r_id)
{
	/*
	 * X30 read should be never handled, since X30 (LR)
	 * is updated always on SMC handling sequence.
	 */
	assert(*r_id < 32 && *r_id != 30);

	/*
	 * x31 has to be encoded as ZR, load/stores to SP
	 * are not supported (and never should be).
	 * Return 0 in such case.
	 */
	if (*r_id == 31)
		return 0;

	return (read_ctx_reg(get_gpregs_ctx(h), (*r_id)*GP_REG_OFFSET) & *mask);
}

static inline void write_gp_reg(void *h, uint64_t *mask, uint8_t *r_id, uint64_t val)
{
	/*
	 * X30 write should be never handled, since X30 (LR)
	 * is updated always on SMC handling sequence.
	 */
	assert(*r_id < 32 && *r_id != 30);

	/*
	 * x31 has to be encoded as ZR, load/stores to SP
	 * are not supported (and never should be).
	 * Ignore this write.
	 */
	if (*r_id == 31)
		return;

	write_ctx_reg(get_gpregs_ctx(h), (*r_id)*GP_REG_OFFSET, (val & *mask));
}

/*
 * This function check bit number val_len in val. If it is one, then all bits
 * after val_len are filed with 1, else bits after val_len are filed with 0.
 */
static inline uint64_t sign_extend(uint64_t val, uint8_t val_len, uint64_t mask)
{
	uint64_t extended_sign = mask & (~(0ull) << (val_len - 1));
	if (val & (0x1 << (val_len - 1))) {
		/* sign bit is 1. Set ones after sign. */
		return val | extended_sign;
	}

	/* sign bit is 0. Set zeros after sign */
	return val & (~extended_sign);
}

static inline int is_block_disabled(int blk_id)
{
	assert(blk_id >= 0 && (blk_id < (sizeof(block_map) / sizeof(struct blk_entry))));

	return (!(block_map[blk_id].enabled));
}

static inline int is_flr_wa_applicable(void) {
	uint64_t midr;

	/* Mask out minor revision bits */
	midr = read_midr() & MIDR_FLR_MASK;

	return (OCTEONTX2_CN96XX_MIDR == midr);
}

static inline void virt_to_phys_el0(uintptr_t va)
{
	/*
	 * Determine 1 stage vs 2 stage translation.
	 * VTTBR_EL2 has to be set on given core for 2 stage translation.
	 * PAR_EL1[47:12] stores the result.
	 */
	if (read_vttbr_el2() != 0)
		__asm__ volatile ("at S12E0R, %[va]" : : [va] "r" (va));
	else
		__asm__ volatile ("at S1E0R, %[va]" : : [va] "r" (va));
}

static inline void virt_to_phys_el1(uintptr_t va)
{
	/*
	 * Determine 1 stage vs 2 stage translation.
	 * VTTBR_EL2 has to be set on given core for 2 stage translation.
	 * PAR_EL1[47:12] stores the result.
	 */
	if (read_vttbr_el2() != 0)
		__asm__ volatile ("at S12E1R, %[va]" : : [va] "r" (va));
	else
		__asm__ volatile ("at S1E1R, %[va]" : : [va] "r" (va));
}

static inline void virt_to_phys_el2(uintptr_t va)
{
	/*
	 * In case of EL2, always perform Stage 1 translation.
	 * PAR_EL1[47:12] stores the result.
	 */
	__asm__ volatile ("at S1E2R, %[va]" : : [va] "r" (va));
}

/*
 * Some memory access HAS TO be done using exactly atomic instruction.
 * rt will be modified. Address (rn) may be passed using any form,
 * rs and rt have to be registers.
 */
#define ATOMIC_ASM_STUB_64(instr)					       \
static inline void do_##instr##64(uint64_t *rs, uint64_t *rt, uint64_t *rn)    \
{									       \
	__asm__ volatile (#instr " %[rs], %[rt], %[rn]"			       \
			:						       \
			[rt] "=r" (*rt)					       \
			:						       \
			[rs] "r" (*rs), [rn] "X" (*rn));		       \
}

/*
 * Some memory access HAS TO be done using exactly atomic instruction.
 * rt will be modified. Address (rn) may be passed using any form,
 * rs and rt have to be wx registers, so they are loaded from memory.
 */
#define ATOMIC_ASM_STUB_32(instr, size)					       \
static inline void do_##instr##size(uint64_t *rs, uint64_t *rt, uint64_t *rn)  \
{									       \
	__asm__ volatile (						       \
		"ldr"#size" w0, %[rs];"					       \
		"ldr"#size" w1, %[rt];"					       \
		#instr #size" w0, w1, %[rn];"				       \
		"str"#size" w1, %[rt];"					       \
		: :							       \
		[rs] "m" (*rs), [rt] "m" (*rt), [rn] "X" (*rn)		       \
		: "w0", "w1"						       \
	);								       \
}

ATOMIC_ASM_STUB_64(ldadd)
ATOMIC_ASM_STUB_32(ldadd, /* Intentionally empty */)
ATOMIC_ASM_STUB_32(ldadd, h)
ATOMIC_ASM_STUB_32(ldadd, b)

ATOMIC_ASM_STUB_64(ldclr)
ATOMIC_ASM_STUB_32(ldclr, /* Intentionally empty */)
ATOMIC_ASM_STUB_32(ldclr, h)
ATOMIC_ASM_STUB_32(ldclr, b)

ATOMIC_ASM_STUB_64(ldeor)
ATOMIC_ASM_STUB_32(ldeor, /* Intentionally empty */)
ATOMIC_ASM_STUB_32(ldeor, h)
ATOMIC_ASM_STUB_32(ldeor, b)

ATOMIC_ASM_STUB_64(ldset)
ATOMIC_ASM_STUB_32(ldset, /* Intentionally empty */)
ATOMIC_ASM_STUB_32(ldset, h)
ATOMIC_ASM_STUB_32(ldset, b)

ATOMIC_ASM_STUB_64(ldsmax)
ATOMIC_ASM_STUB_32(ldsmax, /* Intentionally empty */)
ATOMIC_ASM_STUB_32(ldsmax, h)
ATOMIC_ASM_STUB_32(ldsmax, b)

ATOMIC_ASM_STUB_64(ldsmin)
ATOMIC_ASM_STUB_32(ldsmin, /* Intentionally empty */)
ATOMIC_ASM_STUB_32(ldsmin, h)
ATOMIC_ASM_STUB_32(ldsmin, b)

ATOMIC_ASM_STUB_64(ldumax)
ATOMIC_ASM_STUB_32(ldumax, /* Intentionally empty */)
ATOMIC_ASM_STUB_32(ldumax, h)
ATOMIC_ASM_STUB_32(ldumax, b)

ATOMIC_ASM_STUB_64(ldumin)
ATOMIC_ASM_STUB_32(ldumin, /* Intentionally empty */)
ATOMIC_ASM_STUB_32(ldumin, h)
ATOMIC_ASM_STUB_32(ldumin, b)

ATOMIC_ASM_STUB_64(swp)
ATOMIC_ASM_STUB_32(swp, /* Intentionally empty */)
ATOMIC_ASM_STUB_32(swp, h)
ATOMIC_ASM_STUB_32(swp, b)

#undef ATOMIC_ASM_STUB_64
#undef ATOMIC_ASM_STUB_32

static uintptr_t virt_to_phys(uintptr_t va)
{
	uint64_t pa, par_el1;
	int elx;

	/* Determine from which EL exception came */
	elx = GET_EL(read_spsr_el3());
	switch (elx) {
		case MODE_EL2:
			virt_to_phys_el2(va);
			break;
		case MODE_EL1:
			virt_to_phys_el1(va);
			break;
		case MODE_EL0:
			virt_to_phys_el0(va);
			break;
		default:
			ERROR("FLR handling: Unsupported va_to_pa translation from EL%d\n", elx);
			return 0;
        }

	/* Ensure that translation was performed */
	dmbst();

        /* Handle incorrect translation */
        par_el1 = read_par_el1();
        if (PAR_EL1_F(par_el1)) {
		ERROR("Unsuccessful address translation of VA=0x%lx from EL%d\n",
			va, elx);
                return 0;
	}

        /* Extract PAR_EL1_PA, concatenate with VA[11:0] */
        pa = ((PAR_EL1_PA(par_el1) << PAR_EL1_PA_SHIFT) | VA_OFFSET(va));

        return pa;
}

static int update_value(void *ctx_h, uint64_t *value, uint64_t *mask,
	uint8_t *rt_id, uint8_t *rs_id, flr_operation_e op)
{
	uint64_t rs_value;
	uint64_t rt_value;

	if (op == FLR_OPERATION_STORE) {
		/* If it was write, the value to store is saved at Rt */
		INFO("val = 0x%llx; rt=%d; mask=0x%llx\n",
			read_gp_reg(ctx_h, mask, rt_id), *rt_id, *mask);
		*value = read_gp_reg(ctx_h, mask, rt_id);

		INFO("%s: Write: value=0x%llx\n", __func__, (*value & *mask));
	} else if (op == FLR_OPERATION_LOAD) {
		/*
		 * On reads, Rt is the register that is returned,
		 * Rn stores requested address, as well as FAR_EL3.
		 * Write proper structure field at Rt.
		 */
		write_gp_reg(ctx_h, mask, rt_id, *value);
		INFO("%s: Read: value=0x%llx\n", __func__, (*value & *mask));
	} else {
/*
 * This macro helps to reduce repetitive sequence of choosing correct function.
 */
#define DO_ATOMIC_OPERATION(instr)					\
do {									\
	if (*mask == UINT64_MAX) {					\
		do_##instr##64(&rs_value, &rt_value, value);		\
	} else if (*mask == UINT32_MAX) {				\
		do_##instr(&rs_value, &rt_value, value);		\
	} else if (*mask == UINT16_MAX) {				\
		do_##instr##h(&rs_value, &rt_value, value);		\
	} else if (*mask == UINT8_MAX) {				\
		do_##instr##b(&rs_value, &rt_value, value);		\
	} else {							\
		ERROR("%s: Invalid mask = 0x%llx\n", __func__, *mask);	\
		return -1;						\
	}								\
} while (0)

		rs_value = read_gp_reg(ctx_h, mask, rs_id);
		switch (op) {
		case FLR_OPERATION_ADD:
			DO_ATOMIC_OPERATION(ldadd);
			break;
		case FLR_OPERATION_CLR:
			DO_ATOMIC_OPERATION(ldclr);
			break;
		case FLR_OPERATION_EOR:
			DO_ATOMIC_OPERATION(ldeor);
			break;
		case FLR_OPERATION_SET:
			DO_ATOMIC_OPERATION(ldset);
			break;
		case FLR_OPERATION_SMAX:
			DO_ATOMIC_OPERATION(ldsmax);
			break;
		case FLR_OPERATION_SMIN:
			DO_ATOMIC_OPERATION(ldsmin);
			break;
		case FLR_OPERATION_UMAX:
			DO_ATOMIC_OPERATION(ldumax);
			break;
		case FLR_OPERATION_UMIN:
			DO_ATOMIC_OPERATION(ldumin);
			break;
		case FLR_OPERATION_SWAP:
			DO_ATOMIC_OPERATION(swp);
			break;
		default:
			ERROR("%s: unknown op 0x%x\n", __func__, op);
			return -1;
		}
		write_gp_reg(ctx_h, mask, rt_id, rt_value);
		INFO("%s: Atomic op 0x%x: value=0x%llx, rs=0x%llx\n",
			 __func__, op, (rt_value & *mask), rs_value & *mask);
#undef DO_ATOMIC_OPERATION
	}
	return 0;
}

static int do_alias(void *ctx_h, uintptr_t pa, uint64_t *mask, uint8_t *rt_id,
	uint8_t *rs_id, flr_operation_e op)
{
	int blk_id, lf_slot, addr, rc;
	uint64_t *pa_bar2;
	uint64_t pf, func;
	uint64_t val;

	assert(pa != 0);
	assert(ctx_h != NULL);
	assert(mask != NULL);
	assert(rt_id != NULL);

	/* Extract BLK from PA */
	blk_id = RVU_AF_ADDR_S_BLK(pa);

	/* Validate blk_id, handle access to not existing CSR */
	if (is_block_disabled(blk_id))
		return -1;

	/* Validate the alias_ena bit */
	if (!(blk_af_bar2_sel[blk_id].s.alias_ena)) {
		INFO(
			"(blk)_AF_BAR2_SEL[ALIAS_ENA] not set for blk_id=%d, requested operation 0x%x\n",
			blk_id, op);
		/* write ignored, read as 0 */
		val = 0;
		update_value(ctx_h, &val, mask, rt_id, rs_id, op);

		return 0;
	}

	/* Extract PF and FUNC from AF_BAR2_SEL */
	pf = RVU_PF_FUNC_S_PF(blk_af_bar2_sel[blk_id].s.alias_pf_func);
	func = RVU_PF_FUNC_S_FUNC(blk_af_bar2_sel[blk_id].s.alias_pf_func);

	/* Extract LF_SLOT and ADDR from PA */
	lf_slot = RVU_FUNC_ADDR_S_LF_SLOT(pa);
	addr = RVU_FUNC_ADDR_S_ADDR(pa);

	/* Construct the BAR2 PA address based on the (blk)_AF_BAR2_SEL and PA */
	pa_bar2 = (uint64_t *)(RVU_PFX_FUNCX_BAR2(pf, func) |
		   (blk_id << RVU_FUNC_ADDR_S_BLK_SHIFT) |
		   (lf_slot << RVU_FUNC_ADDR_S_LF_SLOT_SHIFT) |
		   (addr << RVU_FUNC_ADDR_S_ADDR_SHIFT));

	/*
	 * Map dynamically given memory.
	 * Exclude case for (func != 0 || blk_id != 0), which is already mapped
	 * (required by earlier stage RVU code).
	 * Consider mapping func == 0 dynamically for cavm_rvu.c purposes.
	 */
	if ((func != 0) || (blk_id != 0)) {
		rc = mmap_add_dynamic_region((RVU_PFX_FUNCX_BAR2(pf, func) | (blk_id << RVU_FUNC_ADDR_S_BLK_SHIFT)),
					     (RVU_PFX_FUNCX_BAR2(pf, func) | (blk_id << RVU_FUNC_ADDR_S_BLK_SHIFT)),
					     RVU_PF_FUNC_BAR2_SIZE,
					     MT_DEVICE | MT_RW | MT_SECURE);
		if (rc) {
			ERROR("Unable to map memory rc=%d, addr=0x%llx, size=0x%llx\n",
				rc, RVU_PFX_FUNCX_BAR2(pf, func), RVU_PF_FUNC_BAR2_SIZE);
			return rc;
		}
	}

	update_value(ctx_h, pa_bar2, mask, rt_id, rs_id, op);
	INFO("%s: op 0x%x: addr=%p\n", __func__, op, pa_bar2);

	/* Unmap this region */
	if ((func != 0) || (blk_id != 0)) {
		rc = mmap_remove_dynamic_region((RVU_PFX_FUNCX_BAR2(pf, func) | (blk_id << RVU_FUNC_ADDR_S_BLK_SHIFT)),
						RVU_PF_FUNC_BAR2_SIZE);
		if (rc) {
			ERROR("Unable to remove mapped memory addr=0x%llx, size=0x%llx\n",
				RVU_PFX_FUNCX_BAR2(pf, func), RVU_PF_FUNC_BAR2_SIZE);
			return rc;
		}
	}

	return 0;
}

static int alias_handler(void *ctx_h, uintptr_t pa, uint64_t *mask,
	uint8_t *rt_id, uint8_t *rt2_id, flr_operation_e op)
{
	int rc;

	rc = do_alias(ctx_h, pa, mask, rt_id, rt2_id, op);
	if(rc) {
		ERROR("Unable to handle operation 0x%x PA=0x%lx\n", op, pa);
		return rc;
	}

	/* If it's not pair instruction, nothing to do here, simply return. */
	if (*rt2_id == INVALID_REG_IDX ||
	    (op != FLR_OPERATION_STORE && op != FLR_OPERATION_LOAD))
		return rc;

	/* Load/store register pair are only in 8B and 4B variants */
	pa += (*mask == UINT64_MAX) ? 8 : 4;
	rc = do_alias(ctx_h, pa, mask, rt2_id, NULL, op);
	if(rc)
		ERROR(
			"Unable to handle operation 0x%x PA=0x%lx for second register in pair\n",
			op, pa);
	return rc;
}

static int do_sel(void *ctx_h, uintptr_t pa, uint64_t *mask, uint8_t *rt_id,
	uint8_t *rs_id, flr_operation_e op)
{
	int blk_id;

	/* Validate input args */
	assert(pa != 0);
	assert(ctx_h != NULL);
	assert(mask != NULL);
	assert(rt_id != NULL);

	/* Extract BLK from PA */
	blk_id = RVU_AF_ADDR_S_BLK(pa);

	/* Validate blk_id, handle access to not existing CSR */
	if (is_block_disabled(blk_id))
		return -1;

	update_value(ctx_h, &(blk_af_bar2_sel[blk_id].u), mask,
			rt_id, rs_id, op);
	INFO("%s: op 0x%x: blk_id=%d, blk_af_bar2_sel.u=0x%llx\n",
	     __func__, op, blk_id, (blk_af_bar2_sel[blk_id].u & *mask));

	return 0;
}

static int sel_handler(void *ctx_h, uintptr_t pa, uint64_t *mask,
	uint8_t *rt_id, uint8_t *rt2_id, flr_operation_e op)
{
	int rc;

	rc = do_sel(ctx_h, pa, mask, rt_id, rt2_id, op);
	if(rc) {
		ERROR("Unable to handle operation 0x%x PA=0x%lx\n", op, pa);
		return rc;
	}

	/* If it's not pair instruction, nothing to do here, simply return. */
	if (*rt2_id == INVALID_REG_IDX ||
	    (op != FLR_OPERATION_STORE && op != FLR_OPERATION_LOAD))
		return rc;

	/* Load/store register pair are only in 8B and 4B variants */
	pa += (*mask == UINT64_MAX) ? 8 : 4;
	rc = do_sel(ctx_h, pa, mask, rt2_id, NULL, op);
	if(rc)
		ERROR(
			"Unable to handle operation 0x%x PA=0x%lx for second register in pair\n",
			op, pa);
	return rc;
}

static int update_rn(void *ctx_h, uint8_t *rn_id, int16_t *imm)
{
	uint64_t rn_val, rn_mask = UINT64_MAX;

	/* No need to update rn */
	if (*imm == 0)
		return 0;

	/* Post and pre indexed load/store instructions add imm value to Rn */
	rn_val = read_gp_reg(ctx_h, &rn_mask, rn_id);
	write_gp_reg(ctx_h, &rn_mask, rn_id, rn_val + *imm);

	INFO("%s: rn_val=0x%llx, imm=0x%x, rn_val+imm=0x%llx\n",
		 __func__, rn_val, *imm, rn_val + *imm);
	return 0;
}

static int validate_ld_st(uint32_t opcode, uint64_t *size_mask, uint8_t *rt_offset, uint8_t *rn_offset, int16_t *imm9)
{
	if (OPCODE_LD_ST_PRFM(opcode) == OPCODE_LD_ST_PRFM_VAL)
		return -1;
	if (OPCODE_LD_ST_PAC(opcode) == OPCODE_LD_ST_PAC_VAL)
		return -1;

	/* Check for instruction size (applicable for LD/ST only) */
	*size_mask = 0x0;
	switch (OPCODE_SIZE(opcode)) {
		case OPCODE_SIZE_1B:
			*size_mask = UINT8_MAX;
			break;
		case OPCODE_SIZE_2B:
			*size_mask = UINT16_MAX;
			break;
		case OPCODE_SIZE_4B:
			*size_mask = UINT32_MAX;
			break;
		case OPCODE_SIZE_8B:
			*size_mask = UINT64_MAX;
			break;
		default:
			ERROR("Unsupported size mask=0x%x\n", OPCODE_SIZE(opcode));
			return -1;
	}

	/* Extract RT register offset from opcode */
	*rt_offset = OPCODE_RT(opcode);

	/*
	 * For post and pre indexed instruction there will be
	 * need to update RN register, because both, post and pre indexed
	 * instructions, cause side effects, which one of them is update RN.
	 */
	if (OPCODE_LD_ST_POST_PRE(opcode) == OPCODE_LD_ST_POST_PRE_VAL) {
		/* Extract RN register offset from opcode */
		*rn_offset = OPCODE_RN(opcode);
		/* Extract imm9 from opcode */
		*imm9 = sign_extend(OPCODE_IMM9(opcode), 9, UINT16_MAX);
	} else {
		/* suppress uninitialized warning */
		*rn_offset = 0;
		*imm9 = 0;
	}

	return 0;
}

static int validate_ld_st_pair(uint32_t opcode, uint64_t *size_mask, uint8_t *rt_offset, uint8_t *rn_offset, uint8_t *rt2_offset, int16_t *imm7)
{
	/* Load/store pair are defined only for word and double word */
	int scale = opcode & OPCODE_PAIR_DW_BIT ? OPCODE_PAIR_SIZE_8B : OPCODE_PAIR_SIZE_4B;

	/* Check for instruction size */
	*size_mask = (scale == OPCODE_PAIR_SIZE_8B) ? UINT64_MAX : UINT32_MAX;

	/* Extract RT registers offset from opcode */
	*rt_offset = OPCODE_RT(opcode);
	*rt2_offset = OPCODE_RT2(opcode);

	if (OPCODE_PAIR_POST_PRE(opcode) == OPCODE_PAIR_POST_PRE_VAL) {
		/* Extract RN register offset from opcode */
		*rn_offset = OPCODE_RN(opcode);
		/* Extract imm9 from opcode */
		*imm7 = sign_extend(OPCODE_IMM7(opcode), 7, UINT16_MAX) << scale;
	} else {
		/* suppress uninitialized warning */
		*rn_offset = 0;
		*imm7 = 0;
	}

	return 0;
}

static int validate_ld_st_literal(uint32_t opcode, uint64_t *size_mask, uint8_t *rt_offset)
{
	/* Check for instruction size */
	*size_mask = 0x0;
	switch (OPCODE_LITERAL_SIZE(opcode)) {
		case OPCODE_LITERAL_SIZE_4B:
		case OPCODE_LITERAL_SIZE_SIGNED_4B:
			*size_mask = UINT32_MAX;
			break;
		case OPCODE_LITERAL_SIZE_8B:
			*size_mask = UINT64_MAX;
			break;
		case OPCODE_LITERAL_SIZE_PRFM:
			/* Prefetch is not supported */
			return -1;
		default:
			ERROR("Unsupported size mask=0x%x\n", OPCODE_SIZE(opcode));
			return -1;
	}

	/* Extract RT register offset from opcode */
	*rt_offset = OPCODE_RT(opcode);

	return 0;
}

static int validate_ld_st_atomic(uint32_t opcode, uint64_t *size_mask,
	uint8_t *rt_offset, uint8_t *rn_offset, uint8_t *rt2_offset,
	flr_operation_e *op)
{
	/* Check for instruction size (applicable for LD/ST only) */
	*size_mask = 0x0;
	switch (OPCODE_SIZE(opcode)) {
	case OPCODE_SIZE_1B:
		*size_mask = UINT8_MAX;
		break;
	case OPCODE_SIZE_2B:
		*size_mask = UINT16_MAX;
		break;
	case OPCODE_SIZE_4B:
		*size_mask = UINT32_MAX;
		break;
	case OPCODE_SIZE_8B:
		*size_mask = UINT64_MAX;
		break;
	default:
		ERROR("Unsupported size mask=0x%x\n", OPCODE_SIZE(opcode));
		return -1;
	}

	/*
	 * TODO: Only SWAP, ADD and CLR could be trapped, so support for
	 *       the rest atomic operations is disabled at the moment.
	 *       When enabling, test of operation is needed.
	 */
	switch (OPCODE_ATOMIC_OPC(opcode)) {
	case OPCODE_ATOMIC_OPC_ADD:
		*op = FLR_OPERATION_ADD;
		break;
	case OPCODE_ATOMIC_OPC_CLR:
		*op = FLR_OPERATION_CLR;
		ERROR(
			"At the moment atomic CLR opperation is not supported\n");
		return -1;
	case OPCODE_ATOMIC_OPC_EOR:
		*op = FLR_OPERATION_EOR;
		break;
	case OPCODE_ATOMIC_OPC_SET:
		*op = FLR_OPERATION_SET;
		ERROR(
			"At the moment atomic SET opperation is not supported\n");
		return -1;
	case OPCODE_ATOMIC_OPC_SMAX:
		*op = FLR_OPERATION_SMAX;
		ERROR(
			"At the moment atomic SMAX opperation is not supported\n");
		return -1;
	case OPCODE_ATOMIC_OPC_SMIN:
		*op = FLR_OPERATION_SMIN;
		ERROR(
			"At the moment atomic SMIN opperation is not supported\n");
		return -1;
	case OPCODE_ATOMIC_OPC_UMAX:
		*op = FLR_OPERATION_UMAX;
		ERROR(
			"At the moment atomic UMAX opperation is not supported\n");
		return -1;
	case OPCODE_ATOMIC_OPC_UMIN:
		*op = FLR_OPERATION_UMIN;
		ERROR(
			"At the moment atomic UMIN opperation is not supported\n");
		return -1;
	case OPCODE_ATOMIC_OPC_SWAP:
		*op = FLR_OPERATION_SWAP;
		break;
	default:
		ERROR("Unsupported atomic opperation=0x%x\n",
			OPCODE_ATOMIC_OPC(opcode));
		return -1;
	}

	/* Extract RT register offset from opcode */
	*rt_offset = OPCODE_RT(opcode);
	/* Extract RS register offset from opcode */
	*rt2_offset = OPCODE_RS(opcode);
	/* Extract RN register offset from opcode */
	*rn_offset = OPCODE_RN(opcode);

	return 0;
}

static int validate_opcode(uint32_t opcode, uint64_t *size_mask,
	uint8_t *rt_offset, uint8_t *rn_offset, uint8_t *rt2_offset,
	int16_t *imm, flr_operation_e *op)
{
	/*
	 * OPCODE_LD_ST_ATOMIC has to be before OPCODE_LD_ST, because the later
	 * one include atomic subset. This is a lot easier than creating mask
	 * that excludes atomic operations.
	 */
	if (OPCODE_LD_ST_ATOMIC(opcode) == OPCODE_LD_ST_ATOMIC_VAL) {
		*imm = 0;
		return validate_ld_st_atomic(opcode, size_mask, rt_offset,
						rn_offset, rt2_offset, op);
	}

	if (OPCODE_LD_ST(opcode) == OPCODE_LD_ST_VAL) {
		*rt2_offset = INVALID_REG_IDX;
		return validate_ld_st(opcode, size_mask, rt_offset, rn_offset, imm);
	}

	if (OPCODE_LD_ST_PAIR(opcode) == OPCODE_LD_ST_PAIR_VAL)
		return validate_ld_st_pair(opcode, size_mask, rt_offset, rn_offset, rt2_offset, imm);

	if (OPCODE_LD_ST_LITERAL(opcode) == OPCODE_LD_ST_LITERAL_VAL) {
		*rt2_offset = INVALID_REG_IDX;
		*rn_offset = INVALID_REG_IDX;
		*imm = 0;
		return validate_ld_st_literal(opcode, size_mask, rt_offset);
	}

	/* Unsupported instruction */
	return -1;
}

void octeontx_trap_handler(void *ctx_handle)
{
	uint64_t reg_el3, size_mask, pa;
	int16_t imm;
	uint8_t rt_offset, rn_offset, rt2_offset;
	flr_operation_e op;
	int rc;

	assert(ctx_handle != NULL);

	/*
	 * Sanity check for CAVIUM_IO_TRAP decoder.
	 * Only in this case ESR_EL3[WnR] exist in ISS
	 */
	reg_el3 = read_esr_el3();
	assert(EC_BITS(reg_el3) == EC_CAVIUM_IO_TRAP);

	/* Read write flag */
	op = !!(reg_el3 & ESR_WNR_MASK) ? FLR_OPERATION_STORE :
		FLR_OPERATION_LOAD;

	/*
	 * Check for FAR_EL3 validity, for physical address
	 * traps this bit is cleared, it's set for instruction traps.
	 */
	if (reg_el3 & ESR_FAR_ELX_NOT_VALID_MASK) {
		ERROR("Invalid FAR_EL3, unable to get address that came from EL%llu\n",
		      GET_EL(read_spsr_el3()));
		panic();
	}

	/* Convert VA to PA based on FAR_EL3 */
	reg_el3 = read_far_el3();
	pa = virt_to_phys(reg_el3);
	if (pa == 0) {
		ERROR("Invalid PA 0x%llx from EL%llu\n", pa, GET_EL(read_spsr_el3()));
		panic();
	}

	/* Extract and validate opcode */
	reg_el3 = read_cvmtrapopc_el3();
	INFO("Handling opcode=0x%llx\n", CAVM_TRAPOPC_INSN(reg_el3));
	rc = validate_opcode(CAVM_TRAPOPC_INSN(reg_el3), &size_mask, &rt_offset,
				&rn_offset, &rt2_offset, &imm, &op);
	if (rc) {
		ERROR("Unsupported opcode=0x%llx, please contact firmware team\n",
		      CAVM_TRAPOPC_INSN(reg_el3));
		panic();
	}

	/*
	 * Determine handle type based on REGSET.
	 * Future implementation of trap handlers should be placed here.
	 */
	switch (CAVM_TRAPOPC_REGSET(reg_el3)) {
		case AP_CVM_TRAPOPC_EL3_REGSET_RVU_SEL:
			rc = sel_handler(ctx_handle, pa, &size_mask,
				&rt_offset, &rt2_offset, op);
			break;
		case AP_CVM_TRAPOPC_EL3_REGSET_RVU_ALIAS:
			rc = alias_handler(ctx_handle, pa, &size_mask,
				&rt_offset, &rt2_offset, op);
			break;
		default:
			rc = -1;
			break;
	}

	if (rc) {
		ERROR("FLR handler filed\n");
		panic();
	}

	update_rn(ctx_handle, &rn_offset, &imm);

	return;
}

void plat_flr_init(void)
{
	uint64_t trapaddr_el3, trapaddrena_el3;
	octeontx_trapctl_el3_t trapctl_el3;

	if (!is_flr_wa_applicable())
		return;

	/*
	 * Perform trap configuration of (blk)_AF_BAR2_SEL registers,
	 * take address for RVU_AF_BAR2_SEL, mask out blk, match load and store
	 */
	trapaddr_el3 = (RVU_AF_BAR2_SEL | (3ull << 62));
	trapaddr_el3 &= ~(RVU_AF_ADDR_S_BLK_MASK << RVU_AF_ADDR_S_BLK_SHIFT);

	/* Trap selected address, ignoring only block */
	trapaddrena_el3 = ~(RVU_AF_ADDR_S_BLK_MASK << RVU_AF_ADDR_S_BLK_SHIFT);

	/* Trap configuration */
	trapctl_el3.u = read_cvmtrapctl4_el3();
	if (trapctl_el3.s.mtype != 1) {
		ERROR("Trap not on physical address, mtype = %x\n", trapctl_el3.s.mtype);
		return;
	}

	/* Trap accesses from EL2 and NS EL1/EL0 */
	trapctl_el3.s.el2 = 1;
	trapctl_el3.s.el1ns = 1;
	trapctl_el3.s.el0ns = 1;

	/* Trap to EL3 on a match */
	trapctl_el3.s.action = 0;
	trapctl_el3.s.ena = 1;

	/* Write configuration - for _SEL, use 4 reg set */
	write_cvmtrapaddr4_el3(trapaddr_el3);
	write_cvmtrapaddrena4_el3(trapaddrena_el3);
	write_cvmtrapctl4_el3(trapctl_el3.u);

	/* Clear variables */
	trapaddr_el3 = 0;
	trapaddrena_el3 = 0;
	trapctl_el3.u = 0;

	/*
	 * Perform trap configuration of (blk)_AF_BAR2_ALIAS registers,
	 * take address for RVU_AF_BAR2_ALIAS, mask out blk, match load and store
	 */
	trapaddr_el3 = (RVU_AF_BAR2_ALIAS | (3ull << 62));
	trapaddr_el3 &= ~(RVU_AF_ADDR_S_BLK_MASK << RVU_AF_ADDR_S_BLK_SHIFT);

	/*
	 * Trap selected address, ignoring block, RVU_FUNC_ADDR_S[LF_SLOT]
	 * and RVU_FUNC_ADDR_S[ADDR]
	 */
	trapaddrena_el3 = ~((RVU_AF_ADDR_S_BLK_MASK << RVU_AF_ADDR_S_BLK_SHIFT) |
			    (RVU_FUNC_ADDR_S_LF_SLOT_MASK << RVU_FUNC_ADDR_S_LF_SLOT_SHIFT) |
			    (RVU_FUNC_ADDR_S_ADDR_MASK << RVU_FUNC_ADDR_S_ADDR_SHIFT));

	/* Trap configuration */
	trapctl_el3.u = read_cvmtrapctl5_el3();
	if (trapctl_el3.s.mtype != 1) {
		ERROR("Trap not on physical address, mtype = %x\n", trapctl_el3.s.mtype);
		return;
	}

	/* Trap accesses from EL2 and NS EL1/EL0 */
	trapctl_el3.s.el2 = 1;
	trapctl_el3.s.el1ns = 1;
	trapctl_el3.s.el0ns = 1;

	/* Trap to EL3 on a match */
	trapctl_el3.s.action = 0;
	trapctl_el3.s.ena = 1;

	/* Write configuration - for _ALIAS, use 5 reg set */
	write_cvmtrapaddr5_el3(trapaddr_el3);
	write_cvmtrapaddrena5_el3(trapaddrena_el3);
	write_cvmtrapctl5_el3(trapctl_el3.u);
}
