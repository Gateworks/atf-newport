/*******************************************************************************
Copyright (C) 2014, 2015, Marvell International Ltd. and its affiliates
If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.
*******************************************************************************/

/********************************************************************
This file contains headers of updated copies of functions from Avago library..
********************************************************************/
#ifndef MCD_INTERNAL_SERDES_FW_LOAD_H
#define MCD_INTERNAL_SERDES_FW_LOAD_H

#include "mcdApiTypes.h"
#include "mcdSerdes.h"

#if C_LINKAGE
#if defined __cplusplus
    extern "C" {
#endif
#endif

typedef Aapl_t *Aapl_t_ptr;

typedef void mcd_avago_drop_shadow_function(Aapl_t_ptr);

void mcd_avago_spico_upload_reset(
    Aapl_t *aapl,       /**< Pointer to Aapl_t structure */
    uint sbus_addr_in,  /**< Sbus address */
    BOOL ram_bist);     /**< If TRUE, perform spico_ram_bist prior to upload */

int mcd_avago_spico_upload_check_crc(
    Aapl_t *aapl,       /**< Pointer to Aapl_t structure */
    uint sbus_addr_in,  /**< Sbus address */
    int words);         /**< Length of ROM image */

/* This function should do exactly the same as original avago_spico_upload */
/* coded just to check it                                                  */
int mcd_avago_spico_upload(
    Aapl_t *aapl,       /**< Pointer to Aapl_t structure */
    uint sbus_addr_in,  /**< Sbus address */
    BOOL ram_bist,      /**< If TRUE, perform spico_ram_bist prior to upload */
    int words,          /**< Length of ROM image */
    const short *rom);  /**< Avago-supplied ROM image */

/* SWAP IMAGE */

void mcd_avago_spico_upload_swap_image_start(
    Aapl_t *aapl,       /**< [in] Pointer to AAPL structure */
    uint sbus_addr_in); /**< [in] SBus address of SerDes */

int mcd_avago_spico_upload_swap_image_check_crc(
    Aapl_t *aapl,       /**< [in] Pointer to AAPL structure */
    uint sbus_addr_in); /**< [in] SBus address of SerDes */

void mcd_avago_spico_upload_swap_image_load(
    Aapl_t *aapl,       /**< [in] Pointer to AAPL structure */
    uint sbus_addr_in,  /**< [in] SBus address of SerDes */
    int words,          /**< [in] Number of elements in rom */
    const short *rom);  /**< [in] Swap image to upload */

/* This function should do exactly the same as original avago_spico_upload_swap_image */
/* coded just to check it                                                             */
int mcd_avago_spico_upload_swap_image(
    Aapl_t *aapl,       /**< [in] Pointer to AAPL structure */
    uint sbus_addr_in,  /**< [in] SBus address of SerDes */
    int words,          /**< [in] Number of elements in rom */
    const short *rom);  /**< [in] Swap image to upload */

/* ADDED Broadcast Functions */

int mcd_avago_spico_upload_broacast(
    mcd_avago_drop_shadow_function drop_shadow_func,
    uint aapl_amount,              /* *<amount of Pointers to Aapl_t structure */
    Aapl_t_ptr aapl_ptr_arr[],     /**< array of Pointers to Aapl_t structure  */
    Aapl_t_ptr aapl_broadcast_ptr, /**< Pointer to broadcast Aapl_t structure  */
    uint sbus_addr_in,             /**< Sbus address */
    BOOL ram_bist,                 /**< If TRUE, perform spico_ram_bist prior to upload */
    int words,                     /**< Length of ROM image */
    const short *rom);             /**< Avago-supplied ROM image */

int mcd_avago_spico_upload_swap_image_broadcast(
    mcd_avago_drop_shadow_function drop_shadow_func,
    uint aapl_amount,              /* *<amount of Pointers to Aapl_t structure */
    Aapl_t_ptr aapl_ptr_arr[],     /**< array of Pointers to Aapl_t structure  */
    Aapl_t_ptr aapl_broadcast_ptr, /**< Pointer to broadcast Aapl_t structure  */
    uint sbus_addr_in,             /**< [in] SBus address of SerDes */
    int words,                     /**< [in] Number of elements in rom */
    const short *rom);             /**< [in] Swap image to upload */

#if C_LINKAGE
#if defined __cplusplus
}
#endif
#endif

#endif /* defined MCD_INTERNAL_SERDES_FW_LOAD_H */

