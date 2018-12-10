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
* mcdPortCtrlApInitIf.h
*
* DESCRIPTION:
*       API to configure and run 802.3ap Serdes AutoNeg engine
*
* DEPENDENCIES:
*
* FILE REVISION NUMBER:
*       $Revision: 17 $
******************************************************************************/

#ifndef __mcdPortCtrlApIf_H
#define __mcdPortCtrlApIf_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mcdInternalPortApInitIf.h"
#include "mcdPortCtrlApLogDefs.h"

/**
* @internal mcdAutoNegPortCtrlStart function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
* @param[in] retimerMode              = TRUE for retimer
*/
MCD_STATUS mcdAutoNegPortCtrlStart
(
    MCD_DEV_PTR    pDev,
    MCD_U16        phyPortNum,
    MCD_BOOL       retimerMode
);

/**
* @internal mcdApSerdesRxParametersManualSetStart function
* @endinternal
 *
* @retval MCD_OK                   - on success
* @retval MCD_FAIL                 - on error
*/
MCD_STATUS mcdApSerdesRxParametersManualSetStart
(
    MCD_DEV_PTR                         pDev,
    MCD_U16                             phyPortNum,
    MCD_MAN_TUNE_CTLE_CONFIG_OVERRIDE   *rxCfgPtr
);

/**
* @internal mcdApSerdesTxParametersManualSetStart function
* @endinternal
 *
* @retval MCD_OK                   - on success
* @retval MCD_FAIL                 - on fail
* @param[in] pDev                     - physical device number
*                                      mdioPort         - portNum
*                                      txOverrideParamsPtr - (pointer to) parameters data
*/
MCD_STATUS mcdApSerdesTxParametersManualSetStart
(
    MCD_DEV_PTR                         pDev,
    MCD_U16                             phyPortNum,
    MCD_PORT_AP_SERDES_TX_CONFIG        *txCfgPtr
);

/**
* @internal mcdAutoNegPortCtrlStop function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
*/
MCD_STATUS mcdAutoNegPortCtrlStop
(
    MCD_DEV_PTR pDev,
    MCD_U16 phyPortNum
);

/**
* @internal mcdApPortCtrlSysAck function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
*/
MCD_STATUS mcdApPortCtrlSysAck
(
    MCD_DEV_PTR pDev,
    MCD_U32 phyPortNum
);

/**
* @internal mcdApPortCtrlCfgGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
* @param[in] apCfg                    - AP configuration parameters
* @param[out] apCfg                    - AP configuration parameters
*/
MCD_STATUS mcdApPortCtrlCfgGet
(
    MCD_DEV_PTR    pDev,
    MCD_U32        phyPortNum,
    MCD_AP_CFG     *apCfg
);

/**
* @internal mcdApPortCtrlStatusGet function
* @endinternal
 *
* @param[in] pDev
*                                      phyPortNum - physical port number
* @param[in] apStatus                 - AP status parameters
* @param[out] apStatus                 - AP/HCD results
*/
MCD_STATUS mcdApPortCtrlStatusGet
(
    MCD_DEV_PTR            pDev,
    MCD_U32                apPortNum,
    MCD_AP_PORT_STATUS *apStatus
);

/**
* @internal mcdApPortCtrlStatsGet function
* @endinternal
 *
* @param[in] pDev
*                                      phyPortNum - physical port number
* @param[out] apStats                  - AP stats
*/
MCD_STATUS mcdApPortCtrlStatsGet
(
    MCD_DEV_PTR           pDev,
    MCD_U32               apPortNum,
    MCD_AP_PORT_STATS *apStats
);

/**
* @internal mcdApPortCtrlStatsReset function
* @endinternal
 *
* @param[in] pDev
* @param[in] apPortNum                - AP port number
*/
MCD_STATUS mcdApPortCtrlStatsReset
(
    MCD_DEV_PTR           pDev,
    MCD_U32               apPortNum
);

/**
* @internal mcdApPortCtrlIntropSet function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
*                                      apintrop    - AP introp parameters
*/
MCD_STATUS mcdApPortCtrlIntropSet
(
    MCD_DEV_PTR            pDev,
    MCD_U32                phyPortNum,
    MCD_AP_PORT_INTROP *apIntrop
);

/**
* @internal mcdApPortCtrlIntropGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
*                                      apintrop    - AP introp parameters
*/
MCD_STATUS mcdApPortCtrlIntropGet
(
    MCD_DEV_PTR           pDev,
    MCD_U32               phyPortNum,
    MCD_AP_PORT_INTROP   *apIntrop
);

/**
* @internal mcdApPortCtrlDebugGet function
* @endinternal
 *
* @param[in] pDev
* @param[out] apDebug                  - AP debug parameters
*/
MCD_STATUS mcdApPortCtrlDebugGet
(
    MCD_DEV_PTR           pDev,
    MCD_FW_LOG *apDebug
);

/**
* @internal mcdApPortCtrlSerdesGuiSet function
* @endinternal
 *
* @param[in] pDev
* @param[in] state                    - Serdes GUI
*/
MCD_STATUS mcdApPortCtrlSerdesGuiSet
(
    MCD_DEV_PTR pDev,
    MCD_U8 state
);

/**
* @internal mcdApPortCtrlStatsShow function
* @endinternal
 *
* @param[in] pDev
* @param[in] apPortNum                - AP port number
*/
MCD_STATUS mcdApPortCtrlStatsShow
(
    MCD_DEV_PTR pDev,
    MCD_U32  apPortNum
);

/**
* @internal mcdApPortCtrlIntropShow function
* @endinternal
 *
* @param[in] pDev
* @param[in] apPortNum                - AP port number
*/
MCD_STATUS mcdApPortCtrlIntropShow
(
    MCD_DEV_PTR pDev,
    MCD_U32  apPortNum
);

/**
* @internal mcdApPortCtrlDebugInfoShow function
* @endinternal
 *
* @param[in] pDev
* @param[in] apPortNum                - AP port number
*                                      cpssLog   - boolean value indicate if log will be part of CPSS log mechanism or terminal print
*/
MCD_STATUS mcdApPortCtrlDebugInfoShow
(
    MCD_DEV_PTR pDev,
    MCD_U32    apPortNum,
    MCD_BOOL   apCpssLogEnable
);

/**
* @internal mcdPollingStatShow function
* @endinternal
 *
* @param[in] pDev                     - pointer to device
*/
MCD_STATUS mcdPollingStatShow
(
    MCD_DEV_PTR             pDev
);

typedef enum
{
    MCD_POLLING_PORT_STATISTIC_VAL_LAST_UP_TIME_E,
    MCD_POLLING_PORT_STATISTIC_VAL_LONGEST_UP_TIME_E,
    MCD_POLLING_PORT_STATISTIC_VAL_PCS_CHECK_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_PCS_CHECK_FAIL_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SERDES_SIGNAL_CHECK_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SERDES_SIGNAL_CHECK_FAIL_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SERDES_TRAIN_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SERDES_TRAIN_FAIL_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SIGNAL_OFF_TO_CHECK_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SIGNAL_CHECK_TO_OFF_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SIGNAL_CHECK_TO_ON_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SIGNAL_ON_TO_OFF_COUNT_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SIGNAL_MIN_ON_TIME_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SIGNAL_MAX_OFF_TO_CHECK_TIME_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SIGNAL_MAX_OFF_TO_ON_TIME_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SIGNAL_MIN_BOTH_SIDES_ON_TIME_E,
    MCD_POLLING_PORT_STATISTIC_VAL_SIGNAL_MAX_ONE_SIDE_ON_TO_BOTH_SIDES_ON_TIME_E,
    MCD_POLLING_PORT_STATISTIC_VAL_ICAL_FAILED_COUNT_E
} MCD_POLLING_PORT_STATISTIC_VAL_ENT;

/**
* @internal mcdPollingStatValueGet function
* @endinternal
 *
* @param[in] pDev                     - pointer to device
* @param[in] lineSide                 - host side - 0, line side - 1
* @param[out] pollingStatValPtr        - pointer to required value.
*/
MCD_STATUS mcdPollingStatValueGet
(
    IN  MCD_DEV_PTR                         pDev,
    IN  MCD_U32                             portOrSerdes,
    IN  MCD_U32                             lineSide,
    IN  MCD_POLLING_PORT_STATISTIC_VAL_ENT  valueType,
    OUT MCD_U32                             *pollingStatValPtr
);

/**
* @internal mcdPollingStatRetimerPerPortValuesClear function
* @endinternal
 *
* @param[in] pDev                     - pointer to device
* @param[in] portNum                  - port number
* @param[in] lineSide                 - host side - 0, line side - 1
*/
MCD_STATUS mcdPollingStatRetimerPerPortValuesClear
(
    IN  MCD_DEV_PTR                         pDev,
    IN  MCD_U32                             portNum,
    IN  MCD_U32                             lineSide
);

#ifdef __cplusplus
}
#endif

#endif /* mcdervicesPortCtrlApIf_H */



