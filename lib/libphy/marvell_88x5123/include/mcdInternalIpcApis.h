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
* @file mcdInternalIpcApis.h
 *
 * @brief Definitions for IPC feature
 * 
* @version   1
********************************************************************************
*/

#ifndef __mcdInternalIpcApis_H
#define __mcdInternalIpcApis_H

#include "mcdHwSerdesCntl.h"

#if defined(CPU_BE) || defined(MV_CPU_BE)
#define MCD_IPC_CNV_ENABLE
/*#define MCD_IPC_CNV_TEST*/
#endif

#ifdef MCD_IPC_CNV_ENABLE

/* ------------------------------------------------------------------- */
/* Big Endian and Little Endian CPUs shared memory based IPC support.  */
/* ------------------------------------------------------------------- */
/* IPC mcdInternalShmIpcSend and mcdInternalShmIpcRecv message API     */
/* read and write shared memory using functions that copy 32-bit words */
/* with byte swapping.                                                 */
/* The IPC control data delivered in correct format but message        */
/* payload should be prepared to match the other CPU format after byte */
/* swapping.                                                           */

/* order of fields in this enum as in structure describes data */
typedef enum
{
    MCD_IPC_CNV_WORD32_FORMAT_U32_E,       /* 32-bit field                    */
    MCD_IPC_CNV_WORD32_FORMAT_2U16_E,      /* 2 16-bit fields                 */
    MCD_IPC_CNV_WORD32_FORMAT_U16_2U8_E,   /* 16-bit field and 2 8-bit fields */
    MCD_IPC_CNV_WORD32_FORMAT_2U8_U16_E,   /* 2 8-bit fields and 16-bit field */
    MCD_IPC_CNV_WORD32_FORMAT_4U8_E        /* 4 8-bit fields                  */
} MCD_IPC_CNV_WORD32_FORMAT_ENT;

/* ----------------------------------------------- */
/* This function converts both                     */
/* Big Endian to Swapped Little Endian and         */
/* Little Endian to Swapped Big Endian             */
MCD_U32 mcdInternalIpcBeToSwappedLeConvert
(
    IN MCD_IPC_CNV_WORD32_FORMAT_ENT wordFormat,
    IN MCD_U32                       wordValue
);

/* ----------------------------------------------- */
/* This function converts both                     */
/* Swapped Little Endian to Big Endian and         */
/* Swapped Big Endian to Little Endian             */
MCD_U32 mcdInternalIpcSwappedLeToBeConvert
(
    IN MCD_IPC_CNV_WORD32_FORMAT_ENT wordFormat,
    IN MCD_U32                       wordValue
);

#endif /*MCD_IPC_CNV_ENABLE*/

/**
* @internal mcdInternalIpcDbInit function
* @endinternal
 *
* @param[in] pDev
*/
MCD_STATUS mcdInternalIpcDbInit
(
    IN MCD_DEV_PTR pDev
);

/**
* @internal mcdServiceCpuFwPostInit function
* @endinternal
 *
* @param[in] pDev
*                                      phyPortNum  - physical port number
*/
MCD_STATUS mcdServiceCpuFwPostInit
(
    IN MCD_DEV_PTR pDev
);

/**
* @internal mcdInternalServiceCpuMsgSend function
* @endinternal
 *
*/
MCD_STATUS mcdInternalServiceCpuMsgSend
(
    IN MCD_DEV_PTR pDev,
    IN unsigned int channel,
    IN char* msg
);

/**
* @internal mcdInternalServiceCpuMsgRecv function
* @endinternal
 *
*/
MCD_STATUS mcdInternalServiceCpuMsgRecv
(
    IN  MCD_DEV_PTR pDev,
    IN  unsigned int channel,
    OUT char* msg
);

/**
* @internal mcdInternalIpcSendRequestAndGetReply function
* @endinternal
 *
* @param[in] requestMsg               - pointer to request message
* @param[in] msgId                    - message ID
* @param[out] replyData                - pointer to reply message
*/
MCD_STATUS mcdInternalIpcSendRequestAndGetReply
(
    IN  MCD_DEV_PTR                 pDev,
    IN  MCD_IPC_CTRL_MSG_STRUCT     *requestMsg,
    OUT MCD_IPC_REPLY_MSG_STRUCT    *replyData,
    IN  MCD_U32                     msgLength,
    IN  MCD_IPC_CTRL_MSG_DEF_TYPE   msgId
);


/**
* @internal mcdSerdesCfgAddrGetIpc function
* @endinternal
 *
* @param[in] pDev
* @param[out] avagoCfgAddr             - Serdes Configuration structure address
* @param[out] avagoCfgSize             - Serdes Configuration structure size
*/
MCD_STATUS mcdSerdesCfgAddrGetIpc
(
   IN  MCD_DEV_PTR                 pDev,
   OUT MCD_U32                     *avagoCfgAddr,
   OUT MCD_U32                     *avagoCfgSize
);

/**
* @internal mcdSerdesAaplInitIpc function
* @endinternal
 *
* @param[in] pDev
*                                      phyPortNum  - physical port number
*/
MCD_STATUS mcdSerdesAaplInitIpc
(
    MCD_DEV_PTR                 pDev
);

/**
* @internal mcdInternalPortInitIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] portGroup                - port group (core) number
* @param[in] phyPortNum               - physical port number
* @param[in] portMode                 - port standard metric
* @param[in] lbPort                   - if true, init port without serdes activity
* @param[in] refClock                 - Reference clock frequency
* @param[in] refClock                 - Reference clock source line
*/
MCD_STATUS mcdInternalPortInitIpc
(
    MCD_DEV_PTR              pDev,
    MCD_U32                  portGroup,
    MCD_U32                  phyPortNum,
    MCD_U32                  portMode,
    MCD_BOOL                 lbPort,
    MCD_U32                  refClock,
    MCD_U32                  refClockSource

);

/**
* @internal mcdInternalPortResetIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] portGroup                - port group (core) number
* @param[in] phyPortNum               - physical port number
* @param[in] portMode                 - port standard metric
*                                      lbPort     - if true, init port without serdes activity
* @param[in] action                   - Power down or reset
*/
MCD_STATUS mcdInternalPortResetIpc
(
    MCD_DEV_PTR            pDev,
    MCD_U32                portGroup,
    MCD_U32                phyPortNum,
    MCD_U32                portMode,
    MCD_BOOL               action
);

/**
* @internal mcdInternalPortAutoTuneStateCheckIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] portGroup                - port group (core) number
* @param[in] phyPortNum               - physical port number
* @param[in] portMode                 - port standard metric
*                                      portTuningMode - port TX related tuning mode
*/
MCD_STATUS mcdInternalPortAutoTuneStateCheckIpc
(
    MCD_DEV_PTR              pDev,
    MCD_U32                  portGroup,
    MCD_U32                  phyPortNum,
    MCD_U32                  portMode,
    MCD_AUTO_TUNE_STATUS     *rxTune,
    MCD_AUTO_TUNE_STATUS     *txTune
);

/**
* @internal mcdInternalPortLinkStatusGetIpc function
* @endinternal
 *
*/
MCD_STATUS mcdInternalPortLinkStatusGetIpc
(
    MCD_DEV_PTR                pDev,
    MCD_U32                  portGroup,
    MCD_U32                  phyPortNum,
    MCD_U32                  portMode,
    MCD_BOOL                 *linkStatus
);

/**
* @internal mcdInternalPortAutoTuneStopIpc function
* @endinternal
 *
*/
MCD_STATUS mcdInternalPortAutoTuneStopIpc
(
    MCD_DEV_PTR                      pDev,
    MCD_U32                          portGroup,
    MCD_U32                          phyPortNum,
    MCD_U32                          portMode,
    MCD_BOOL                         stopRx,
    MCD_BOOL                         stopTx
);

/**
* @internal mcdInternalPortApStartIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
* @param[in] retimerMode              = TRUE for retimer
*/
MCD_STATUS mcdInternalPortApStartIpc
(
    MCD_DEV_PTR                pDev,
    MCD_U16                    phyPortNum,
    MCD_BOOL                   retimerMode
);

/**
* @internal mcdInternalPortApStopIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
*/
MCD_STATUS mcdInternalPortApStopIpc
(
    MCD_DEV_PTR                 pDev,
    MCD_U16 phyPortNum
);

/**
* @internal mcdInternalPortApCfgGetIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] portGroup                - core number
* @param[in] phyPortNum               - physical port number
*                                      portApCfg  - AP configuration parameters
*/
MCD_STATUS mcdInternalPortApCfgGetIpc
(
    MCD_DEV_PTR                pDev,
    MCD_U32 portGroup,
    MCD_U32 phyPortNum,
    MCD_U32 *apCfg
);

/**
* @internal mcdSetSquelchRxClockControlIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
* @param[in] clckCtrl                 - pin to output the clock
*/
MCD_STATUS mcdSetSquelchRxClockControlIpc
(
   MCD_DEV_PTR                 pDev,
   MCD_U32                     phyPortNum,
   MCD_RX_CLOCK_CTRL_TYPE       clckCtrl
);

/**
* @internal mcdInternalPortApStatusGetIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] phyPortNum               - physical port number
*                                      apStatus   - AP Status parameters
*/
MCD_STATUS mcdInternalPortApStatusGetIpc
(
    MCD_DEV_PTR                pDev,
    MCD_U32 phyPortNum,
    MCD_U32 *portApStatus
);

/**
* @internal mcdInternalPortApStatsGetIpc function
* @endinternal
 *
*/
MCD_STATUS mcdInternalPortApStatsGetIpc
(
    MCD_DEV_PTR                pDev,
    MCD_U32 portGroup,
    MCD_U32 phyPortNum,
    MCD_U32 *portApStats
);

/**
* @internal mcdInternalPortApStatsResetIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] portGroup                - port group (core) number
* @param[in] apPortNum                - AP port number
*/
MCD_STATUS mcdInternalPortApStatsResetIpc
(
    MCD_DEV_PTR pDev,
    MCD_U32 portGroup,
    MCD_U32 apPortNum
);

/**
* @internal mcdInternalPortApIntropSetIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] portGroup                - port group (core) number
* @param[in] phyPortNum               - physical port number
*                                      apintrop    - AP introp parameters
*/
MCD_STATUS mcdInternalPortApIntropSetIpc
(
    MCD_DEV_PTR                pDev,
    MCD_U32 portGroup,
    MCD_U32 phyPortNum,
    MCD_U32 *portApIntrop
);

/**
* @internal mcdInternalPortApIntropGetIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] portGroup                - port group (core) number
* @param[in] phyPortNum               - physical port number
*                                      apintrop    - AP introp parameters
*/
MCD_STATUS mcdInternalPortApIntropGetIpc
(
    MCD_DEV_PTR                pDev,
    MCD_U32 portGroup,
    MCD_U32 phyPortNum,
    MCD_U32 *portApIntrop
);

/**
* @internal mcdInternalPortApDebugGetIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] portGroup                - port group (core) number
* @param[in] phyPortNum               - physical port number
*                                      apDebug    - AP debug parameters
*/
MCD_STATUS mcdInternalPortApDebugGetIpc
(
    MCD_DEV_PTR                pDev,
    MCD_U32 portGroup,
    MCD_U32 phyPortNum,
    MCD_U32 *portApDebug
);

/**
* @internal mcdPortPollingLinkStatusStartIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] mdioPort                 - physical port number
* @param[in] retimerMode              - 1 - retimer mode, 0 -PCS mode
* @param[in] retimerWithAP            - true - retimer with ap
*                                      lineSerdesSpeed  - line Serdes Speed
*                                      hostSerdesSpeed  - host Serdes Speed
* @param[in] lineSerdesBitmap         - line Serdes Bitmap (bits 0-7)
* @param[in] hostSerdesBitmap         - host Serdes Bitmap (bits 0-7)
*/
MCD_STATUS mcdPortPollingLinkStatusStartIpc
(
    MCD_DEV_PTR                   pDev,
    MCD_U16                       mdioPort,
    MCD_BOOL                      retimerMode,
    MCD_BOOL                      retimerWithAP,
    MCD_U16 /*MCD_SERDES_SPEED*/  lineSerdesSpeed,
    MCD_U16 /*MCD_SERDES_SPEED*/  hostSerdesSpeed,
    MCD_U16                       lineSerdesBitmap,
    MCD_U16                       hostSerdesBitmap,
    MCD_U16                       noPpmMode,
    MCD_U8                        reducedRxTraining
);

/**
* @internal mcdPortPollingLinkStatusStopIpc function
* @endinternal
 *
* @param[in] pDev
* @param[in] mdioPort                 - physical port number
*/
MCD_STATUS mcdPortPollingLinkStatusStopIpc
(
    MCD_DEV_PTR                   pDev,
    MCD_U16                       mdioPort
);

#endif /* __mcdInternalIpcApis_H */



