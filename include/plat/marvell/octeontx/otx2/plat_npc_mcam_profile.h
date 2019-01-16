/** @file

  Copyright (c) 2018, Marvell International Ltd. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CAVM_NPC_MCAM_PROFILE_H__
#define __CAVM_NPC_MCAM_PROFILE_H__

#ifdef NT_FW_CONFIG
uint64_t otx2_get_npc_profile_addr(uint64_t profile_id);
uint64_t otx2_get_npc_profile_size(uint64_t profile_id);
#endif

#endif /* __CAVM_NPC_MCAM_PROFILE_H__ */
