/***********************license start***********************************
* Copyright (C) 2018 Marvell International Ltd.
* SPDX-License-Identifier: BSD-3-Clause
* https://spdx.org/licenses
***********************license end**************************************/

/**
 * @file
 *
 * Functions for determining which chip you are running on.
 *
 * <hr>$Revision: 49448 $<hr>
 * @addtogroup chips
 * @{
 */


/* Flag bits in top byte. The top byte of MIDR_EL1 is defined
   as ox43, the Cavium implementer code. In this number, bits
   7,5,4 are defined as zero. We use these bits to signal
   that revision numbers should be ignored. It isn't ideal
   that these are in the middle of an already defined field,
   but this keeps the model numbers as 32 bits */
#define __OM_IGNORE_REVISION        0x80000000
#define __OM_IGNORE_MINOR_REVISION  0x20000000
#define __OM_IGNORE_MODEL           0x10000000

#define OCTEONTX_CN83XX_PASS1_0   0x430f0a30
#define OCTEONTX_CN83XX           (OCTEONTX_CN83XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEONTX_CN83XX_PASS1_X   (OCTEONTX_CN83XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

#define OCTEONTX_CN81XX_PASS1_0   0x430f0a20
#define OCTEONTX_CN81XX           (OCTEONTX_CN81XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEONTX_CN81XX_PASS1_X   (OCTEONTX_CN81XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)
/* Note CN80XX will also match the CN81XX macros above. See comment in
   cavm_is_model() about MIO_FUS_FUSE_NUM_E::CHIP_IDX bits 6-7 */

#define OCTEONTX_CN96XX_PASS1_0   0x430f0b20
#define OCTEONTX_CN96XX           (OCTEONTX_CN96XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEONTX_CN96XX_PASS1_X   (OCTEONTX_CN96XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

#define OCTEONTX_CNF95XX_PASS1_0  0x430f0b30
#define OCTEONTX_CNF95XX          (OCTEONTX_CNF95XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEONTX_CNF95XX_PASS1_X  (OCTEONTX_CNF95XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

/* These match entire families of chips */
#define OCTEONTX_CN8XXX           (OCTEONTX_CN83XX_PASS1_0 | __OM_IGNORE_MODEL)
#define OCTEONTX_CN9XXX           (OCTEONTX_CN96XX_PASS1_0 | __OM_IGNORE_MODEL)

static inline uint64_t cavm_get_model() __attribute__ ((pure, always_inline));
static inline uint64_t cavm_get_model()
{
#ifdef CAVM_REMOTE_GET_MODEL
    return CAVM_REMOTE_GET_MODEL;
#elif defined(CAVM_BUILD_HOST)
    extern uint32_t cavm_remote_get_model(void) __attribute__ ((pure));
    return cavm_remote_get_model();
#else
    uint64_t result;
    asm ("mrs %[rd],MIDR_EL1" : [rd] "=r" (result));
    return result;
#endif
}

/**
 * Return non-zero if the chip matech the passed model.
 *
 * @param arg_model One of the OCTEONTX_* constants for chip models and
 *                  passes
 *
 * @return Non-zero if match
 */
static inline int cavm_is_model(uint32_t arg_model) __attribute__ ((pure, always_inline));
static inline int cavm_is_model(uint32_t arg_model)
{
    const uint32_t FAMILY = 0xff00;     /* Bits 15:8, generation t8x=0xa, t9x=0xb */
    const uint32_t PARTNUM = 0xfff0;    /* Bits 15:4, chip t88=0x81, t81=0xa2, t83=0xa3, etc */
    const uint32_t VARIANT = 0xf00000;  /* Bits 23:20, major pass */
    const uint32_t REVISION = 0xf;      /* Bits 3:0, minor pass */

    /* Note that the model matching here is unaffected by
       MIO_FUS_FUSE_NUM_E::CHIP_IDX bits 6-7, which are the alternate package
       fuses. These bits don't affect MIDR_EL1, so:
            CN80XX will match CN81XX (CHIP_IDX 6 is set for 676 ball package)
            CN80XX will match CN81XX (CHIP_IDX 7 is set for 555 ball package)
       Alternate package parts are detected using MIO_FUS_DAT2[chip_id],
       specifically the upper two bits */

    uint32_t my_model = cavm_get_model();
    uint32_t mask;

    if (arg_model & __OM_IGNORE_MODEL)
        mask = FAMILY; /* Matches chip generation (CN8XXX, CN9XXX) */
    else if (arg_model & __OM_IGNORE_REVISION)
        mask = PARTNUM; /* Matches chip model (CN81XX, CN83XX) */
    else if (arg_model & __OM_IGNORE_MINOR_REVISION)
        mask = PARTNUM | VARIANT; /* Matches chip model and major version */
    else
        mask = PARTNUM | VARIANT | REVISION; /* Matches chip model, major version, and minor version */
    return ((arg_model & mask) == (my_model & mask));
}

/**
 * Return non-zero if the die is in an alternate package. The
 * normal is_model() checks will treat alternate package parts
 * as all the same, where this function can be used to detect
 * them. The return value is the upper two bits of
 * MIO_FUS_DAT2[chip_id]. Most alternate packages use bit 6,
 * which will return 1 here. Parts with a second alternative
 * will use bit 7, which will return 2.
 *
 * @param arg_model One of the OCTEONTX_* constants for chip models and
 *                  passes
 *
 * @return Non-zero if an alternate package
 *         0 = Normal package
 *         1 = Alternate package 1 (CN86XX, CN80XX with 555 balls)
 *         2 = Alternate package 2 (CN80XX with 676 balls)
 *         3 = Alternate package 3 (Currently unused)
 */
extern int cavm_is_altpkg(uint32_t arg_model);

#define CAVM_MODEL_MAX_SKU 32 /* Maximum length of SKU is 31 plus zero terminator */

/**
 * Return the SKU string for a chip
 *
 * @param node   Node to get SKU for
 *
 * @return Chip's SKU
 */
extern const char* cavm_model_get_sku(int node);

/** @} */
