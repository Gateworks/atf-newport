/*******************************************************************************
*                Copyright 2001, Marvell International Ltd.
* This code contains confidential information of Marvell semiconductor, inc.
* no rights are granted herein under any patent, mask work right or copyright
* of Marvell or any third party.
* Marvell reserves the right at its sole discretion to request that this code
* be immediately returned to Marvell. This code is provided "as is".
* Marvell makes no warranties, express, implied or otherwise, regarding its
* accuracy, completeness or performance.
********************************************************************************
*/
/**
********************************************************************************
* @file mcdInternalInitApApis.h
 *
 * @brief API to configure and run 802.3ap Serdes AutoNeg engine
 * 
* @version   17
********************************************************************************
*/

#ifndef __mcdInternalInitApApis_H
#define __mcdInternalInitApApis_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mcdApiTypes.h"



/**
* @internal mcdInternalApEngineInit function
* @endinternal
 *
* @param[in] pDev
*/
MCD_STATUS mcdInternalApEngineInit
(
    MCD_DEV_PTR               pDev
);

/**
* @internal mcdInternalApEngineStop function
* @endinternal
 *
* @param[in] pDev
*                                      portGroup   - port group (core) number
*/
MCD_STATUS mcdInternalApEngineStop
(
    MCD_DEV_PTR               pDev
);

/**
* @internal mcdInternalApEngineInitGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] engineEnabled            - pointer to boolean that indicated whether the engine
*                                      is enabled
*/
MCD_STATUS mcdInternalApEngineInitGet
(
    MCD_DEV_PTR               pDev,
    MCD_BOOL                  *engineEnabled
);

/**
* @internal mcdInternalApPortStart function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
* @param[in] apCfg                    - AP configuration parameters
*/
MCD_STATUS mcdInternalApPortStart
(
    MCD_DEV_PTR               pDev,
    MCD_U32                   phyPortNum,
    MCD_AP_CFG                *apCfg
);


/**
* @internal mcdInternalApPortConfigGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
*/
MCD_STATUS mcdInternalApPortConfigGet
(
    MCD_DEV_PTR              pDev,
    MCD_U32                  phyPortNum,
    MCD_BOOL                 *apPortEnabled,
    MCD_AP_CFG               *apCfg

);

/**
* @internal mcdInternalApPortSetActiveLanes function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
* @param[in] portMode                 - port mode
*/
MCD_STATUS mcdInternalApPortSetActiveLanes
(
    MCD_DEV_PTR              pDev,
    MCD_U32                  portGroup,
    MCD_U32                  phyPortNum,
    MCD_U32                  portMode

);

/**
* @internal mcdInternalApPortResolutionMaskGet function
* @endinternal
 *
* @param[in] pDev
* @param[out] portBitmask              - port's resolution bit mask
*/
MCD_STATUS mcdInternalApPortResolutionMaskGet
(
    MCD_DEV_PTR              pDev,
    MCD_U32                  *portBitmask
);

/**
* @internal mcdInternalApLockGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
*/
MCD_STATUS mcdInternalApLockGet
(
	MCD_DEV_PTR pDev,
	MCD_U32	phyPortNum
);

/**
* @internal mcdInternalApLockRelease function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
*/
MCD_STATUS mcdInternalApLockRelease
(
    MCD_DEV_PTR  pDev,
	MCD_U32	phyPortNum
);

/**
* @internal mcdInternalApCheckCounterGet function
* @endinternal
 *
* @param[in] pDev
*/
MCD_STATUS mcdInternalApCheckCounterGet
(
  MCD_DEV_PTR pDev,
  MCD_U32 *counter
);

/**
* @internal mcdInternalApPortStatusShow function
* @endinternal
 *
* @param[in] pDev
* @param[in] apPortNum                - AP port number
*/
MCD_STATUS mcdInternalApPortStatusShow
(
  MCD_DEV_PTR pDev,
  MCD_U32  apPortNum
);

/**
* @internal mcdInternalApPortCtrlServiceCpuUartEnableSet function
* @endinternal
 *
* @param[in] pDev
* @param[in] enable                   - boolean value indicate UART setting (/disable)
*/
MCD_STATUS mcdInternalApPortCtrlServiceCpuUartEnableSet
(
    MCD_DEV_PTR pDev,
    MCD_BOOL   enable
);

/**
* @internal mcdpPortCtrlServiceCpuUartEnableGet function
* @endinternal
 *
* @param[in] pDev
*                                      enable - boolean value indicate UART setting (enable/disable)
*/
MCD_STATUS mcdpPortCtrlServiceCpuUartEnableGet
(
    MCD_DEV_PTR pDev,
    MCD_BOOL   *enablePtr
);

#ifdef __cplusplus
}
#endif

#endif /* mcdInternalInitApApis_H */




