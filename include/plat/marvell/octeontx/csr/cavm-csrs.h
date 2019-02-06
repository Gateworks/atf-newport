#ifndef __CAVM_CSRS_H__
#define __CAVM_CSRS_H__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.

 *   * Neither the name of Cavium Inc. nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.

 * This Software, including technical data, may be subject to U.S. export  control
 * laws, including the U.S. Export Administration Act and its  associated
 * regulations, and may be subject to export or import  regulations in other
 * countries.

 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR
 * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO
 * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR
 * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM
 * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,
 * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF
 * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR
 * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 ***********************license end**************************************/


/**
 * @file
 *
 * Configuration and status register (CSR) address and type definitions for
 * Cavium None.
 *
 * This file is auto generated. Do not edit.
 *
 */

//extern void __cavm_csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));

/* Include all CSR files for easy access */
#include "cavm-csrs-apbr.h"
#include "cavm-csrs-ap.h"
#include "cavm-csrs-avs.h"
#include "cavm-csrs-bbxb.h"
#include "cavm-csrs-bbxd.h"
#include "cavm-csrs-bbxe.h"
#include "cavm-csrs-bbxf.h"
#include "cavm-csrs-bch.h"
#include "cavm-csrs-bgx.h"
#include "cavm-csrs-bphy.h"
#include "cavm-csrs-bts.h"
#include "cavm-csrs-ccs.h"
#include "cavm-csrs-ccu.h"
#include "cavm-csrs-cde.h"
#include "cavm-csrs-cgx.h"
#include "cavm-csrs-cim.h"
#include "cavm-csrs-cpc.h"
#include "cavm-csrs-cpt.h"
#include "cavm-csrs-csk.h"
#include "cavm-csrs-dab_cti.h"
#include "cavm-csrs-dab_dbg.h"
#include "cavm-csrs-dab_etr.h"
#include "cavm-csrs-dab_pmu.h"
#include "cavm-csrs-dab_ras.h"
#include "cavm-csrs-dab_syscti.h"
#include "cavm-csrs-dab_trc.h"
#include "cavm-csrs-dap.h"
#include "cavm-csrs-ddf.h"
#include "cavm-csrs-denc.h"
#include "cavm-csrs-dlfe.h"
#include "cavm-csrs-dmap.h"
#include "cavm-csrs-dpi.h"
#include "cavm-csrs-dro.h"
#include "cavm-csrs-dtx.h"
#include "cavm-csrs-ecam.h"
#include "cavm-csrs-fpa.h"
#include "cavm-csrs-fusf.h"
#include "cavm-csrs-fus.h"
#include "cavm-csrs-gic.h"
#include "cavm-csrs-gpio.h"
#include "cavm-csrs-gser.h"
#include "cavm-csrs-gsern.h"
#include "cavm-csrs-gti.h"
#include "cavm-csrs-iobn.h"
#include "cavm-csrs-key.h"
#include "cavm-csrs-l2c.h"
#include "cavm-csrs-l2c_cbc.h"
#include "cavm-csrs-l2c_mci.h"
#include "cavm-csrs-l2c_tad.h"
#include "cavm-csrs-lbk.h"
#include "cavm-csrs-lmc.h"
#include "cavm-csrs-lmt.h"
#include "cavm-csrs-mcc.h"
#include "cavm-csrs-mdab.h"
#include "cavm-csrs-mdab_mbp_mem.h"
#include "cavm-csrs-mdab_ssp_mem.h"
#include "cavm-csrs-mdbw.h"
#include "cavm-csrs-mdc.h"
#include "cavm-csrs-mdn.h"
#include "cavm-csrs-mhbw.h"
#include "cavm-csrs-mio_boot.h"
#include "cavm-csrs-mio_emm.h"
#include "cavm-csrs-mio_fus.h"
#include "cavm-csrs-mio_ptp.h"
#include "cavm-csrs-mio_tws.h"
#include "cavm-csrs-mpi.h"
#include "cavm-csrs-mrml.h"
#include "cavm-csrs-ncsi.h"
#include "cavm-csrs-ndc.h"
#include "cavm-csrs-ndf.h"
#include "cavm-csrs-nic.h"
#include "cavm-csrs-nix.h"
#include "cavm-csrs-npa.h"
#include "cavm-csrs-npc.h"
#include "cavm-csrs-ocla.h"
#include "cavm-csrs-pbus.h"
#include "cavm-csrs-pccbr.h"
#include "cavm-csrs-pccpf.h"
#include "cavm-csrs-pccvf.h"
#include "cavm-csrs-pcieep.h"
#include "cavm-csrs-pcieepvf.h"
#include "cavm-csrs-pcierc.h"
#include "cavm-csrs-pcm.h"
#include "cavm-csrs-pdec.h"
#include "cavm-csrs-pem.h"
#include "cavm-csrs-pemrc.h"
#include "cavm-csrs-penc.h"
#include "cavm-csrs-pki.h"
#include "cavm-csrs-pko.h"
#include "cavm-csrs-pnbd.h"
#include "cavm-csrs-pnb.h"
#include "cavm-csrs-prach.h"
#include "cavm-csrs-psbm.h"
#include "cavm-csrs-psbs.h"
#include "cavm-csrs-psm.h"
#include "cavm-csrs-rad.h"
#include "cavm-csrs-rdec.h"
#include "cavm-csrs-rfoe.h"
#include "cavm-csrs-rgx.h"
#include "cavm-csrs-rmap.h"
#include "cavm-csrs-rnm.h"
#include "cavm-csrs-rom.h"
#include "cavm-csrs-rst.h"
#include "cavm-csrs-rvu.h"
#include "cavm-csrs-sata.h"
#include "cavm-csrs-scr.h"
#include "cavm-csrs-sgp.h"
#include "cavm-csrs-sli.h"
#include "cavm-csrs-smi.h"
#include "cavm-csrs-smmu.h"
#include "cavm-csrs-sso.h"
#include "cavm-csrs-ssow.h"
#include "cavm-csrs-tdec.h"
#include "cavm-csrs-tim.h"
#include "cavm-csrs-tsn.h"
#include "cavm-csrs-uaa.h"
#include "cavm-csrs-ulfe.h"
#include "cavm-csrs-usbdrd.h"
#include "cavm-csrs-usbh.h"
#include "cavm-csrs-vdr.h"
#include "cavm-csrs-vrm.h"
#include "cavm-csrs-xcv.h"
#include "cavm-csrs-xcp.h"
#include "cavm-csrs-xsx.h"
#include "cavm-csrs-zip.h"

#endif /* __CAVM_CSRS_H__ */
