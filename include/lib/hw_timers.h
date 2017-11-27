/** @file

  Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#ifndef __HW_TIMERS_H__
#define __HW_TIMERS_H__

#include <stdint.h>

typedef void (*hw_timer_isr_t)(void);

int plat_timers_init(void);
int plat_timer_register_irq(hw_timer_isr_t isr);
void plat_timer_enable(int enable);
void plat_timer_set_period(uint64_t period);
uint64_t plat_timer_ms_to_ticks(uint32_t time);
uint64_t plat_timer_get_remainig(void);


#endif
