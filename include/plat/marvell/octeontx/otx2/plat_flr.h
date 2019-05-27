/*
 * Copyright (C) 2018 Marvell International Ltd.
 * This program is provided "as is" without any warranty of any kind,
 * and is distributed under the applicable Marvell proprietary limited use
 * license agreement.
 */

#ifndef __PLAT_FLR_H__
#define __PLAT_FLR_H__

#include <arch_helpers.h>

#define RVU_AF_BAR2_SEL			0x840009000000ll
#define RVU_AF_BAR2_ALIAS		0x840009100000ll
#define RVU_PF_FUNC_BAR2_BASE		0x840200000000ll
#define RVU_PF_FUNC_BAR2_SIZE		0x100000ll

/* Helper RVU definitions */
#define RVU_AF_ADDR_S_BLK_SHIFT		ULL(28)
#define RVU_AF_ADDR_S_BLK_MASK		ULL(0x1f)
#define RVU_AF_ADDR_S_BLK(x)		(((x) >> RVU_AF_ADDR_S_BLK_SHIFT) & RVU_AF_ADDR_S_BLK_MASK)

#define RVU_AF_ADDR_S_ADDR_SHIFT	ULL(0)
#define RVU_AF_ADDR_S_ADDR_MASK		ULL(0xfffffff)
#define RVU_AF_ADDR_S_ADDR(x)		(((x) >> RVU_AF_ADDR_S_ADDR_SHIFT) & RVU_AF_ADDR_S_BLK_MASK)

#define RVU_FUNC_ADDR_S_BLK_SHIFT	ULL(20)
#define RVU_FUNC_ADDR_S_BLK_MASK	ULL(0x1f)
#define RVU_FUNC_ADDR_S_BLK(x)		(((x) >> RVU_FUNC_ADDR_S_BLK_SHIFT) & RVU_FUNC_ADDR_S_BLK_SHIFT)

#define RVU_FUNC_ADDR_S_LF_SLOT_SHIFT	ULL(12)
#define RVU_FUNC_ADDR_S_LF_SLOT_MASK	ULL(0xff)
#define RVU_FUNC_ADDR_S_LF_SLOT(x)	(((x) >> RVU_FUNC_ADDR_S_LF_SLOT_SHIFT) & RVU_FUNC_ADDR_S_LF_SLOT_MASK)

#define RVU_FUNC_ADDR_S_ADDR_SHIFT	ULL(0)
#define RVU_FUNC_ADDR_S_ADDR_MASK	ULL(0xfff)
#define RVU_FUNC_ADDR_S_ADDR(x)		(((x) >> RVU_FUNC_ADDR_S_ADDR_SHIFT) & RVU_FUNC_ADDR_S_ADDR_MASK)

#define RVU_PF_FUNC_S_PF_SHIFT		ULL(10)
#define RVU_PF_FUNC_S_PF_MASK		ULL(0x3f)
#define RVU_PF_FUNC_S_PF(x)		(((x) >> RVU_PF_FUNC_S_PF_SHIFT) & RVU_PF_FUNC_S_PF_MASK)

#define RVU_PF_FUNC_S_FUNC_SHIFT	ULL(0)
#define RVU_PF_FUNC_S_FUNC_MASK		ULL(0x3ff)
#define RVU_PF_FUNC_S_FUNC(x)		(((x) >> RVU_PF_FUNC_S_FUNC_SHIFT) & RVU_PF_FUNC_S_FUNC_MASK)

#define RVU_PFX_FUNCX(pf, func)		(((pf) << 36) | ((func) << 25))
#define RVU_PFX_FUNCX_BAR2(pf, func)	(RVU_PF_FUNC_BAR2_BASE | RVU_PFX_FUNCX(pf, func))

#define PAR_EL1_PA_SHIFT		ULL(12)
#define PAR_EL1_PA_MASK			ULL(0xfffffffff)
#define PAR_EL1_PA(x)			(((x) >> PAR_EL1_PA_SHIFT) & PAR_EL1_PA_MASK)

#define PAR_EL1_F_SHIFT			ULL(0)
#define PAR_EL1_F_MASK			ULL(0x1)
#define PAR_EL1_F(x)			(((x) >> PAR_EL1_F_SHIFT) & PAR_EL1_F_MASK)

#define VA_OFFSET_SHIFT			ULL(0)
#define VA_OFFSET_MASK			ULL(0xfff)
#define VA_OFFSET(x)			(((x) >> VA_OFFSET_SHIFT) & VA_OFFSET_MASK)

#define MIDR_FLR_MASK			ULL(0xfffffff0)

#define GP_REG_OFFSET			ULL(0x8)

#define CAVM_TRAPOPC_INSN_SHIFT		ULL(0)
#define CAVM_TRAPOPC_INSN_MASK		ULL(0xffffffff)
#define CAVM_TRAPOPC_INSN(x)		(((x) >> CAVM_TRAPOPC_INSN_SHIFT) & CAVM_TRAPOPC_INSN_MASK)

#define CAVM_TRAPOPC_REGSET_SHIFT	ULL(32)
#define CAVM_TRAPOPC_REGSET_MASK	ULL(0x1f)
#define CAVM_TRAPOPC_REGSET(x)		(((x) >> CAVM_TRAPOPC_REGSET_SHIFT) & CAVM_TRAPOPC_REGSET_MASK)

/* Trap registers (implementation-specific) */
#define AP_CVM_TRAPOPC_EL3		S3_6_C11_C6_1
#define AP_CVM_TRAPADDR_EL3(x)		S3_6_C11_C7_##x
#define AP_CVM_TRAPCTL_EL3(x)		S3_6_C11_C8_##x
#define AP_CVM_TRAPINSN_EL3(x)		S3_6_C11_C9_##x
#define AP_CVM_TRAPADDRENA_EL3(x)	S3_6_C11_C9_##x

#define AP_CVM_TRAPOPC_EL3_REGSET4	ULL(0)
#define AP_CVM_TRAPOPC_EL3_REGSET5	ULL(1)
#define AP_CVM_TRAPOPC_EL3_REGSET6	ULL(2)
#define AP_CVM_TRAPOPC_EL3_REGSET7	ULL(3)

DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapopc_el3, AP_CVM_TRAPOPC_EL3)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapaddr4_el3, AP_CVM_TRAPADDR_EL3(4))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapaddr5_el3, AP_CVM_TRAPADDR_EL3(5))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapaddr6_el3, AP_CVM_TRAPADDR_EL3(6))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapaddr7_el3, AP_CVM_TRAPADDR_EL3(7))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapctl0_el3, AP_CVM_TRAPCTL_EL3(0))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapctl1_el3, AP_CVM_TRAPCTL_EL3(1))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapctl2_el3, AP_CVM_TRAPCTL_EL3(2))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapctl3_el3, AP_CVM_TRAPCTL_EL3(3))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapctl4_el3, AP_CVM_TRAPCTL_EL3(4))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapctl5_el3, AP_CVM_TRAPCTL_EL3(5))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapctl6_el3, AP_CVM_TRAPCTL_EL3(6))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapctl7_el3, AP_CVM_TRAPCTL_EL3(7))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapinsn0_el3, AP_CVM_TRAPINSN_EL3(0))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapinsn1_el3, AP_CVM_TRAPINSN_EL3(1))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapinsn2_el3, AP_CVM_TRAPINSN_EL3(2))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapinsn3_el3, AP_CVM_TRAPINSN_EL3(3))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapaddrena4_el3, AP_CVM_TRAPADDRENA_EL3(4))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapaddrena5_el3, AP_CVM_TRAPADDRENA_EL3(5))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapaddrena6_el3, AP_CVM_TRAPADDRENA_EL3(6))
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmtrapaddrena7_el3, AP_CVM_TRAPADDRENA_EL3(7))

#define AP_CVM_TRAPOPC_EL3_REGSET_RVU_SEL	AP_CVM_TRAPOPC_EL3_REGSET4
#define AP_CVM_TRAPOPC_EL3_REGSET_RVU_ALIAS	AP_CVM_TRAPOPC_EL3_REGSET5

#define INVALID_REG_IDX			U(0xff)

#define OPCODE_RT_MASK			U(0x1f)
#define OPCODE_RT_SHIFT			U(0)
#define OPCODE_RT(x)			(((x) >> OPCODE_RT_SHIFT) & OPCODE_RT_MASK)

#define OPCODE_RN_MASK			U(0x1f)
#define OPCODE_RN_SHIFT			U(5)
#define OPCODE_RN(x)			(((x) >> OPCODE_RN_SHIFT) & OPCODE_RN_MASK)

/*
 * This fields are valid for Load/store register pair instructions
 */
#define OPCODE_RT2_MASK			U(0x1f)
#define OPCODE_RT2_SHIFT		U(10)
#define OPCODE_RT2(x)			(((x) >> OPCODE_RT2_SHIFT) & OPCODE_RT2_MASK)

#define OPCODE_IMM7_MASK		U(0x7f)
#define OPCODE_IMM7_SHIFT		U(15)
#define OPCODE_IMM7(x)			(((x) >> OPCODE_IMM7_SHIFT) & OPCODE_IMM7_MASK)

#define OPCODE_PAIR_DW_BIT		(1 << 31)
#define OPCODE_PAIR_SIZE_4B		U(0x2)
#define OPCODE_PAIR_SIZE_8B		U(0x3)

/*
 * This field is valid for Load register (literal) set of instructions
 */
 #define OPCODE_LITERAL_SIZE_MASK		U(0x3)
 #define OPCODE_LITERAL_SIZE_SHIFT		U(30)
 #define OPCODE_LITERAL_SIZE(x)			(((x) >> OPCODE_LITERAL_SIZE_SHIFT) & OPCODE_LITERAL_SIZE_MASK)
 #define OPCODE_LITERAL_SIZE_4B			U(0x0)
 #define OPCODE_LITERAL_SIZE_8B			U(0x1)
 #define OPCODE_LITERAL_SIZE_SIGNED_4B	U(0x2)
 #define OPCODE_LITERAL_SIZE_PRFM		U(0x3)

/*
 * This field is valid for Atomic memory operations set of instructions
 */
#define OPCODE_ATOMIC_OPC_MASK		U(0xf)
#define OPCODE_ATOMIC_OPC_SHIFT		U(12)
#define OPCODE_ATOMIC_OPC(x)		(((x) >> OPCODE_ATOMIC_OPC_SHIFT) \
						& OPCODE_ATOMIC_OPC_MASK)
#define OPCODE_ATOMIC_OPC_ADD		U(0x0)
#define OPCODE_ATOMIC_OPC_CLR		U(0x1)
#define OPCODE_ATOMIC_OPC_EOR		U(0x2)
#define OPCODE_ATOMIC_OPC_SET		U(0x3)
#define OPCODE_ATOMIC_OPC_SMAX		U(0x4)
#define OPCODE_ATOMIC_OPC_SMIN		U(0x5)
#define OPCODE_ATOMIC_OPC_UMAX		U(0x6)
#define OPCODE_ATOMIC_OPC_UMIN		U(0x7)
#define OPCODE_ATOMIC_OPC_SWAP		U(0x8)

/*
 * This field is valid for Atomic memory operations set of instructions
 */
#define OPCODE_RS_MASK		U(0x1f)
#define OPCODE_RS_SHIFT		U(16)
#define OPCODE_RS(x)		(((x) >> OPCODE_RS_SHIFT) & OPCODE_RS_MASK)


/*
 * This field is correct for all instructions from the following sets:
 * Load/store register (unscaled immediate)
 * Load/store register (immediate post-indexed)
 * Load/store register (unprivileged)
 * Load/store register (immediate pre-indexed)
 */
#define OPCODE_IMM9_MASK		U(0x1ff)
#define OPCODE_IMM9_SHIFT		U(12)
#define OPCODE_IMM9(x)			(((x) >> OPCODE_IMM9_SHIFT) & OPCODE_IMM9_MASK)

#define OPCODE_SIZE_MASK		U(0x3)
#define OPCODE_SIZE_SHIFT		U(30)
#define OPCODE_SIZE(x)			(((x) >> OPCODE_SIZE_SHIFT) & OPCODE_SIZE_MASK)
#define OPCODE_SIZE_1B			U(0x0)
#define OPCODE_SIZE_2B			U(0x1)
#define OPCODE_SIZE_4B			U(0x2)
#define OPCODE_SIZE_8B			U(0x3)

#define OPCODE_LD_ST_SHIFT		U(10)
#define OPCODE_LD_ST_MASK		U(0xf8000)
/*
 * This value covers all of the following instruction sets:
 * Load/store register (unscaled immediate)
 * Load/store register (immediate post-indexed)
 * Load/store register (unprivileged)
 * Load/store register (immediate pre-indexed)
 * Atomic memory operations
 * Load/store register (pac)
 * Load/store register (register offset)
 * Load/store register (unsigned immediate)
 *
 * exclude SIMD instructions
 * Basically, in most cases it'll be just LDR/STR
 */
#define OPCODE_LD_ST_VAL		U(0xe0000)
#define OPCODE_LD_ST(x)			(((x) >> OPCODE_LD_ST_SHIFT) & OPCODE_LD_ST_MASK)

#define OPCODE_LD_ST_POST_PRE_SHIFT	U(10)
#define OPCODE_LD_ST_POST_PRE_MASK	U(0xfc001)
/*
 * This value covers all of the following instruction sets:
 * Load/store register (immediate post-indexed)
 * Load/store register (immediate pre-indexed)
 * exclude SIMD instructions
 */
#define OPCODE_LD_ST_POST_PRE_VAL		U(0xe0001)
#define OPCODE_LD_ST_POST_PRE(x)		(((x) >> OPCODE_LD_ST_POST_PRE_SHIFT) & OPCODE_LD_ST_POST_PRE_MASK)

#define OPCODE_LD_ST_PRFM_SHIFT	U(10)
#define OPCODE_LD_ST_PRFM_MASK	U(0x3e2000)
/*
 * This value covers instructions PRFUM and PRFM register offset
 * and unsigned immediate variant.
 */
#define OPCODE_LD_ST_PRFM_VAL		U(0x3e2000)
#define OPCODE_LD_ST_PRFM(x)		(((x) >> OPCODE_LD_ST_PRFM_SHIFT) & OPCODE_LD_ST_PRFM_MASK)

#define OPCODE_LD_ST_PAC_SHIFT	U(10)
#define OPCODE_LD_ST_PAC_MASK	U(0xec801)
/*
 * This value covers Load/store register (pac) instucitons
 */
#define OPCODE_LD_ST_PAC_VAL	U(0xe0801)
#define OPCODE_LD_ST_PAC(x)		(((x) >> OPCODE_LD_ST_PAC_SHIFT) \
						& OPCODE_LD_ST_PAC_MASK)


#define OPCODE_LD_ST_PAIR_SHIFT		U(10)
#define OPCODE_LD_ST_PAIR_MASK		U(0xf8000)
/*
 * This value covers all of the following instruction sets:
 * Load/store no-allocate pair (offset)
 * Load/store register pair (post-indexed)
 * Load/store register pair (offset)
 * Load/store register pair (pre-indexed)
 *
 * exclude SIMD instructions
 */
#define OPCODE_LD_ST_PAIR_VAL		U(0xa0000)
#define OPCODE_LD_ST_PAIR(x)		(((x) >> OPCODE_LD_ST_PAIR_SHIFT) & OPCODE_LD_ST_PAIR_MASK)

#define OPCODE_PAIR_POST_PRE_SHIFT	U(10)
#define OPCODE_PAIR_POST_PRE_MASK	U(0xfa000)
/*
 * This value covers all of the following instruction sets:
 * Load/store register pair (post-indexed)
 * Load/store register pair (pre-indexed)
 * exclude SIMD instructions
 */
#define OPCODE_PAIR_POST_PRE_VAL	U(0xa2000)
#define OPCODE_PAIR_POST_PRE(x)		(((x) >> OPCODE_PAIR_POST_PRE_SHIFT) & OPCODE_PAIR_POST_PRE_MASK)

#define OPCODE_LD_ST_LITERAL_SHIFT		U(10)
#define OPCODE_LD_ST_LITERAL_MASK		U(0xf8000)
/*
 * This value covers Load register (literal) instructions
 * exclude SIMD instructions
 */
#define OPCODE_LD_ST_LITERAL_VAL		U(0x60000)
#define OPCODE_LD_ST_LITERAL(x)			(((x) >> OPCODE_LD_ST_LITERAL_SHIFT) & OPCODE_LD_ST_LITERAL_MASK)

#define OPCODE_LD_ST_ATOMIC_SHIFT		U(10)
#define OPCODE_LD_ST_ATOMIC_MASK		U(0xec803)
/*
 * This value covers Atomic memory operations
 */
#define OPCODE_LD_ST_ATOMIC_VAL		U(0xe0800)
#define OPCODE_LD_ST_ATOMIC(x)		(((x) >> OPCODE_LD_ST_ATOMIC_SHIFT) \
						& OPCODE_LD_ST_ATOMIC_MASK)

enum rvu_block_addr_e {
	BLKADDR_RVUM    = 0x0ULL,
	BLKADDR_LMT     = 0x1ULL,
	BLKADDR_MSIX    = 0x2ULL,
	BLKADDR_NPA     = 0x3ULL,
	BLKADDR_NIX0    = 0x4ULL,
	BLKADDR_NIX1    = 0x5ULL,
	BLKADDR_NPC     = 0x6ULL,
	BLKADDR_SSO     = 0x7ULL,
	BLKADDR_SSOW    = 0x8ULL,
	BLKADDR_TIM     = 0x9ULL,
	BLKADDR_CPT0    = 0xaULL,
	BLKADDR_CPT1    = 0xbULL,
	BLKADDR_NDC0    = 0xcULL,
	BLKADDR_NDC1    = 0xdULL,
	BLKADDR_NDC2    = 0xeULL,
	BLKADDR_NDC3    = 0xfULL,
	BLKADDR_NDC4    = 0x10ULL,
	BLKADDR_NDC5    = 0x11ULL,
	BLKADDR_NDC6    = 0x12ULL,
	BLKADDR_NDC7    = 0x13ULL,
	BLKADDR_MAX     = 0x14ULL,
};

typedef enum flr_operation_e {
	FLR_OPERATION_ADD   = OPCODE_ATOMIC_OPC_ADD,
	FLR_OPERATION_CLR   = OPCODE_ATOMIC_OPC_CLR,
	FLR_OPERATION_EOR   = OPCODE_ATOMIC_OPC_EOR,
	FLR_OPERATION_SET   = OPCODE_ATOMIC_OPC_SET,
	FLR_OPERATION_SMAX  = OPCODE_ATOMIC_OPC_SMAX,
	FLR_OPERATION_SMIN  = OPCODE_ATOMIC_OPC_SMIN,
	FLR_OPERATION_UMAX  = OPCODE_ATOMIC_OPC_UMAX,
	FLR_OPERATION_UMIN  = OPCODE_ATOMIC_OPC_UMIN,
	FLR_OPERATION_SWAP  = OPCODE_ATOMIC_OPC_SWAP,
	FLR_OPERATION_LOAD,
	FLR_OPERATION_STORE,
} flr_operation_e;

struct blk_entry {
	int enabled;
	enum rvu_block_addr_e block;
};

union octeontx_trapctl_el3
{
    uint64_t u;
    struct octeontx_trapctl_el3_s
    {
        uint64_t ena                   : 1;  /**< [  0:  0](R/W) Enable. */
        uint64_t mtype                 : 3;  /**< [  3:  1](R/W) Read-only. Typs of matcher for software capability discovery:
                                                                   0x0 = Not present.
                                                                   0x1 = Physical address matcher. This value is advertised in indices 4..7.
                                                                   0x2 = Instruction matcher. This value is advertised in indices 0..3. */
        uint64_t action                : 4;  /**< [  7:  4](R/W) Trap action:
                                                                   0x0 = Trap to EL3 on a match.
                                                                   0x1 = Flush the instruction pipeline and reissue instruction. For instruction matches
                                                                 only, otherwise UNPREDICTABLE.
                                                                   0x2-0xF = Reserved. */
        uint64_t reserved_8_31         : 24;
        uint64_t el0s                  : 1;  /**< [ 32: 32](R/W) Trap accesses from EL0S. */
        uint64_t el0ns                 : 1;  /**< [ 33: 33](R/W) Trap accesses from EL0NS. */
        uint64_t el1s                  : 1;  /**< [ 34: 34](R/W) Trap accesses from EL1S. */
        uint64_t el1ns                 : 1;  /**< [ 35: 35](R/W) Trap accesses from EL1NS. */
        uint64_t el2                   : 1;  /**< [ 36: 36](R/W) Trap accesses from EL2. */
        uint64_t reserved_37_63        : 27;
    } s;
    /* struct octeontx_trapctl_el3_s cn; */
};
typedef union octeontx_trapctl_el3 octeontx_trapctl_el3_t;

union rvu_af_bar2_sel
{
    uint64_t u;
    struct rvu_af_bar2_sel_s
    {
        uint64_t alias_pf_func         : 16; /**< [ 15:  0](R/W) PF and function whose BAR2 registers may be accessed from the AF BAR2 alias
                                                                 registers. Format specified by RVU_PF_FUNC_S. */
        uint64_t alias_ena             : 1;  /**< [ 16: 16](R/W) Enable BAR2 register accesses from the AF BAR2 alias registers in BAR0. */
        uint64_t reserved_17_63        : 47;
    } s;
};
typedef union rvu_af_bar2_sel rvu_af_bar2_sel_t;

/* Exported functions */
void plat_flr_init(void);
void octeontx_trap_handler(void * ctx_handle);

#endif /* __PLAT_FLR_H__ */
