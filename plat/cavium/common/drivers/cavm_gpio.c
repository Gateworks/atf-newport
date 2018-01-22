/** @file

  Copyright (c) 2016-2018, Cavium Inc. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <cavm_common.h>
#include <cavm_gpio.h>

int gpio_set_out (int pin)
{
	cavm_gpio_tx_set_t gpio_tx_set;
	cavm_gpio_bit_cfgx_t gpio_bit_cfg;
	unsigned long node = cavm_numa_local();

	gpio_tx_set.u = 0;
	gpio_tx_set.s.set = (1ULL << pin);
	CSR_WRITE(node, CAVM_GPIO_TX_SET, gpio_tx_set.u);
	gpio_bit_cfg.u = CSR_READ(node, CAVM_GPIO_BIT_CFGX(pin));
	gpio_bit_cfg.s.tx_oe = 1;
	gpio_bit_cfg.s.pin_sel = 0;
	CSR_WRITE(node, CAVM_GPIO_BIT_CFGX(pin), gpio_bit_cfg.u);
	return 0;
}

int gpio_clr_out (int pin)
{
	cavm_gpio_bit_cfgx_t gpio_bit_cfg;
	cavm_gpio_tx_clr_t gpio_tx_clr;
	unsigned long node = cavm_numa_local();

	gpio_tx_clr.u = 0;
	gpio_tx_clr.s.clr = (1ULL << pin);
	CSR_WRITE(node, CAVM_GPIO_TX_CLR, gpio_tx_clr.u);
	gpio_bit_cfg.u = CSR_READ(node, CAVM_GPIO_BIT_CFGX(pin));
	gpio_bit_cfg.s.pin_sel = 0;
	gpio_bit_cfg.s.tx_oe = 1;
	CSR_WRITE(node, CAVM_GPIO_BIT_CFGX(pin), gpio_bit_cfg.u);
	return 0;
}


