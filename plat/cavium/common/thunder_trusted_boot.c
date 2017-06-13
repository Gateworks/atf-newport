/** @file

  Copyright (c) 2017, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <assert.h>
#include <platform.h>
#include <platform_oid.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "thunder_dt.h"
#include <mbedtls/sha256.h>

#define ROTPK_BYTES			64

/* SHA256 algorithm */
#define SHA256_BYTES			32

/* ROTPK locations */
#define ARM_ROTPK_REGS_ID		1
#define ARM_ROTPK_DEVEL_RSA_ID		2

#if !ARM_ROTPK_LOCATION_ID
  #error "ARM_ROTPK_LOCATION_ID not defined"
#endif

static const unsigned char rotpk_hash_hdr[] =		\
		"\x30\x31\x30\x0D\x06\x09\x60\x86\x48"	\
		"\x01\x65\x03\x04\x02\x01\x05\x00\x04\x20";
static const unsigned int rotpk_hash_hdr_len = sizeof(rotpk_hash_hdr) - 1;
static unsigned char rotpk_hash_der[sizeof(rotpk_hash_hdr) - 1 + SHA256_BYTES];

static const unsigned char rotpk_asn1_hdr[] = \
		"\x30\x59" \
		"\x30\x13" \
		"\x06\x07" \
		"\x2a\x86\x48\xce\x3d\x02\x01" \
		"\x06\x08" \
		"\x2a\x86\x48\xce\x3d\x03\x01\x07" \
		"\x03\x42" \
		"\x00\x04";
static const unsigned int rotpk_asn1_hdr_len = sizeof(rotpk_asn1_hdr) - 1;
static unsigned char rotpk[sizeof(rotpk_asn1_hdr) - 1 + ROTPK_BYTES];

/*
 * Return the ROTPK hash in the following ASN.1 structure in DER format:
 *
 * AlgorithmIdentifier  ::=  SEQUENCE  {
 *     algorithm         OBJECT IDENTIFIER,
 *     parameters        ANY DEFINED BY algorithm OPTIONAL
 * }
 *
 * DigestInfo ::= SEQUENCE {
 *     digestAlgorithm   AlgorithmIdentifier,
 *     digest            OCTET STRING
 * }
 */
int plat_get_rotpk_info(void *cookie, void **key_ptr, unsigned int *key_len,
			unsigned int *flags)
{
	uint8_t *dst;
	unsigned int i, words;
	uint64_t *src, tmp;
	unsigned char *ptr;

	assert(key_ptr != NULL);
	assert(key_len != NULL);
	assert(flags != NULL);
	assert(bfdt.trust_rot_addr != 0);

	/* Copy the DER header of ROTPK into rotpk structure */
	memcpy(rotpk, rotpk_asn1_hdr, rotpk_asn1_hdr_len);

	/* Move the pointer a header_len forward */
	ptr = &rotpk[rotpk_asn1_hdr_len];

	/* Copy memory from trust_rot_addr to global table indicated by ptr */
	memcpy(ptr, (unsigned char *)bfdt.trust_rot_addr, ROTPK_BYTES);

	/* Convert ROTPK to big endian partly Qx/Qy */
	words = 4;
	src = (uint64_t *)bfdt.trust_rot_addr;
	for (i = 0; i < words; i++) {
		tmp = src[words - 1 - i];
		*ptr++ = (unsigned char)((tmp >> 56) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 48) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 40) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 32) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 24) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 16) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 8) & 0xFF);
		*ptr++ = (unsigned char)(tmp & 0xFF);
	}
	src = (uint64_t *)(bfdt.trust_rot_addr + ROTPK_BYTES/2);
	for (i = 0; i < words; i++) {
		tmp = src[words - 1 - i];
		*ptr++ = (unsigned char)((tmp >> 56) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 48) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 40) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 32) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 24) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 16) & 0xFF);
		*ptr++ = (unsigned char)((tmp >> 8) & 0xFF);
		*ptr++ = (unsigned char)(tmp & 0xFF);
	}

	/* Copy the DER header of ROTPK_HASH */
	memcpy(rotpk_hash_der, rotpk_hash_hdr, rotpk_hash_hdr_len);
	dst = (uint8_t *)&rotpk_hash_der[rotpk_hash_hdr_len];

	/* Finally, calculate SHA256 on ROTPK and store it in dst */
	mbedtls_sha256(rotpk, sizeof(rotpk), dst, 0);

	/* Assign outputs */
	*key_ptr = (void *)rotpk_hash_der;
	*key_len = (unsigned int)sizeof(rotpk_hash_der);
	*flags = ROTPK_IS_HASH;
	return 0;
}

/*
 * Return the non-volatile counter value stored in the platform. The cookie
 * will contain the OID of the counter in the certificate.
 *
 * Return: 0 = success, Otherwise = error
 */
int plat_get_nv_ctr(void *cookie, unsigned int *nv_ctr)
{
	const char *oid;
	uint32_t *nv_ctr_addr;

	assert(cookie != NULL);
	assert(nv_ctr != NULL);

	oid = (const char *)cookie;
	if (strcmp(oid, TRUSTED_FW_NVCOUNTER_OID) == 0) {
		nv_ctr_addr = (uint32_t *)TFW_NVCTR_BASE;
	} else if (strcmp(oid, NON_TRUSTED_FW_NVCOUNTER_OID) == 0) {
		nv_ctr_addr = (uint32_t *)NTFW_CTR_BASE;
	} else {
		return 1;
	}

	*nv_ctr = (unsigned int)(*nv_ctr_addr);

	return 0;
}

/*
 * Store a new non-volatile counter value. By default on ARM development
 * platforms, the non-volatile counters are RO and cannot be modified. We expect
 * the values in the certificates to always match the RO values so that this
 * function is never called.
 *
 * Return: 0 = success, Otherwise = error
 */
int plat_set_nv_ctr(void *cookie, unsigned int nv_ctr)
{
	return 1;
}
