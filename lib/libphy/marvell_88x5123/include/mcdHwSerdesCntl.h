/*******************************************************************************
Copyright (C) 2014-2016, Marvell International Ltd. and its affiliates
If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.
*******************************************************************************/

/********************************************************************
This file contains functions prototypes and global defines/data for
higher-level functions using MDIO access to perform resets, perform
queries of the phy, etc. that are necessary to control and read
status of the Marvell X5121/X5111/X2381/X5123/EC808 PHY.
********************************************************************/
#ifndef MCD_HWSERDESCNT_H
#define MCD_HWSERDESCNT_H

#if C_LINKAGE
#if defined __cplusplus
    extern "C" {
#endif
#endif

#define MCD_SEMA_SERDES          15
#define MCD_CM3_SERDES_LOCK      5
#define MCD_HOST_SERDES_LOCK    10


/* SBus address for each component */
#define MCD_SBUS_SBUS_MASTER  0xFD
#define MCD_SBUS_SBUS_SERDES  0xFF

/* SBus indirect access register */
#define MCD_SBUS_RX_DATA_VALID  0xF440
#define MCD_SBUS_COMMAND_REG    0xF441
#define MCD_SBUS_ADDR_REG       0xF442
#define MCD_SBUS_EXECUTION      0xF443
#define MCD_SBUS_INPUT_DATA_L   0xF444
#define MCD_SBUS_INPUT_DATA_H   0xF445
#define MCD_SBUS_RESULT_CODE    0xF446
#define MCD_SBUS_OUTPUT_DATA_L  0xF448
#define MCD_SBUS_OUTPUT_DATA_H  0xF449

/* SBus result return code MCD_SBUS_RESULT_CODE */
#define MCD_SBUS_RESET             0x0
#define MCD_SBUS_WRITE_COMPLETE    0x1
#define MCD_SBUS_WRITE_FAILED      0x2
#define MCD_SBUS_READ_ALL_COMPLETE 0x3
#define MCD_SBUS_READ_COMPLETE     0x4
#define MCD_SBUS_READ_FAILED       0x5
#define MCD_SBUS_CMD_ISSUE_DONE    0x6
#define MCD_SBUS_MODE_CHANGE_DONE  0x7

/* SBus Read/Write command */
#define MCD_SBUS_ADDR   0x20
#define MCD_SBUS_WRITE  0x21
#define MCD_SBUS_READ   0x22

/* SBus master register map */
#define MCD_SBUS_MASTER_INTR_CMD     0x02
#define MCD_SBUS_MASTER_INTR_STATUS  0x07
#define MCD_SBUS_MASTER_INTR_RESULT  0x08

/* Sbus SerDes Register */
#define MCD_SBUS_SERDES_INTR_CMD     0x03
#define MCD_SBUS_SERDES_INTR_RESULT  0x04

/* Sbus SerDes Diagnostic Register */
#define MCD_SBUS_TEMPERATURE_SENSOR  0x11
#define MCD_SBUS_TEMPERATURE_DATA    0x17
#define MCD_SBUS_VOLTAGE_DATA        0x18

#define MCD_SERDES_LANE_COUNT       16
#define MCD_SKIP_SERDES             0xFF

/************************* definition *****************************************************/

#ifndef MV_HWS_REDUCED_BUILD_EXT_CM3
#define MCD_SBC_UNIT_BASE_ADDRESS         (0x33000000)
#define MCD_SBC_MASTER_BASE_ADDRESS       (0x33040000)
#else
#define MCD_SBC_UNIT_BASE_ADDRESS         (0x63000000)
#define MCD_SBC_MASTER_BASE_ADDRESS       (0x63040000)
#endif
#define MCD_SBC_UNIT_REG_ADDR(reg)        (MCD_SBC_UNIT_BASE_ADDRESS | reg)
#define MCD_SBC_UNIT_COMMOM_CTRL_REG_ADDR (0x0)
#define MCD_SBC_UNIT_SOFT_RESET           (0x1)
#define MCD_SBC_UNIT_INTERNAL_ROM_ENABLE  (0x2)

#define MCD_SBC_MASTER_SERDES_NUM_SHIFT   (10)
#define MCD_SBC_MASTER_REG_ADDR_SHIFT     (2)

#define  AVAGO_ETH_CONNECTION         1
#define  AVAGO_SBUS_CONNECTION        3
#define  MAX_AVAGO_SERDES_ADDRESS     255
#define  NA_VALUE                     0
#define  AVAGO_INVALID_SBUS_ADDR      (-1)
#define  AVAGO_SERDES_INIT_BYPASS_VCO (0xFFFF)

#define MCD_SERDES_TX_EQUALIZE_PASS       (0x54)

#define MCD_TRAINING_TIMEOUT       6000

#define MCD_SERDES_DEFAILT_DC_GAIN              110
#define MCD_SERDES_DEFAILT_LOW_FREQUENCY         13
#define MCD_SERDES_DEFAILT_HIGH_FREQUENCY         3
#define MCD_SERDES_DEFAILT_BANDWIDTH              3
#define MCD_SERDES_DEFAILT_LOOP_BANDWIDTH         0
/* set default signal OK threshold to be good for all types of connectors
defined by worst case with DAC cables - squelch level 84 - threshold value 1*/
#define MCD_SERDES_DEFAILT_SQUELCH             100
#define MCD_SERDES_HIGHEST_SQUELCH             150
#define MCD_SERDES_DEFAILT_SIGNAL_OK_THRESHOLD   2

typedef enum
{
    MCD_SPEED_NA,
    MCD_1_25G,
    MCD_3_125G,
    MCD_5G,
    MCD_6_25G,
    MCD_10_3125G,        /*40 r4 - ( or 10) for 10G, 20G, 40G  R4*/
    MCD_10_9375G,
    MCD_12_1875G,        /* for 11.8G, 23.6G, 47.2G */
    MCD_12_5G,
    MCD_20_625G,       /* for 40G R2 */
    MCD_25_78125G,     /* 50, 25,for 100G retimer*/
    MCD_28_05G,
    LAST_MCD_SERDES_SPEED

}MCD_SERDES_SPEED;


typedef enum
{
    /* for serdes */
    MCD_DFE_STOP_ADAPTIVE = 4,
    MCD_DFE_START_ADAPTIVE,
    MCD_DFE_ICAL,
    MCD_DFE_PCAL

}MCD_DFE_MODE;

/**
* @enum MCD_SERDES_TX_PATTERN
 *
 * @brief Defines different serdes transmit patterns.
 * Comment: Other - as output value means any other mode not mentioned
 * in this enum;
 * as input means HW default for PHY Test Data 5
 * register;
*/
typedef enum
{
  MCD_1T,
  MCD_2T,
  MCD_5T,
  MCD_10T,
  MCD_PRBS7,
  MCD_PRBS9,
  MCD_PRBS15,
  MCD_PRBS23,
  MCD_PRBS31,
  MCD_DFETraining,
  MCD_Other,
  MCD_PRBS11,

  MCD_LAST_SERDES_TX_PATTERN

}MCD_SERDES_TX_PATTERN;

/**
* @enum MCD_SERDES_TEST_GEN_MODE
 *
 * @brief Defines different serdes test generator modes.
*/
typedef enum{

    MCD_SERDES_NORMAL,

    MCD_SERDES_TEST

} MCD_SERDES_TEST_GEN_MODE;

/*
 * Typedef: struct MCD_SERDES_TEST_GEN_STATUS
 *
 * Description: Defines serdes test generator results.
 *
 */
typedef struct
{
  MCD_U32       errorsCntr;
  MCD_UNION64   txFramesCntr;
  MCD_U32       lockStatus;

}MCD_SERDES_TEST_GEN_STATUS;


typedef struct
{
  MCD_U32 txAmp;       /* atten in Avago */
  MCD_U32 txEmph0;     /* post in Avago */
  MCD_U32 txEmph1;     /* pre in Avago */

  /* Avago */
  MCD_U32 DC;
  MCD_U32 LF;
  MCD_U32 HF;
  MCD_U32 BW;
  MCD_U32 LB;
  MCD_U32 EO;
  MCD_32  DFE[13];

}MCD_AUTO_TUNE_RESULTS;

typedef struct
{
    MCD_U32              txAmp;
    MCD_BOOL             txAmpAdj;
    MCD_U32              txEmph0;
    MCD_U32              txEmph1;
    MCD_BOOL             txAmpShft;

}MCD_MAN_TUNE_TX_CONFIG_DATA;

typedef enum
{
    MCD_IGNORE_RX_TRAINING,
    MCD_ONE_SHOT_DFE_TUNING,                /* Single time iCal */
    MCD_START_CONTINUE_ADAPTIVE_TUNING,     /* adaptive pCal */
    MCD_STOP_CONTINUE_ADAPTIVE_TUNING,
    MCD_DFE_VSR_TUNING

}MCD_RX_TRAINING_MODES;

typedef enum
{
    MCD_IGNORE_TX_TRAINING,
    MCD_START_TRAINING,
    MCD_STOP_TRAINING

}MCD_TX_TRAINING_MODES;

typedef enum
{
    MCD_RX_DIRECTION,
    MCD_TX_DIRECTION

}MCD_SERDES_DIRECTION;

typedef enum
{
  MCD_TUNE_PASS,
  MCD_TUNE_FAIL,
  MCD_TUNE_NOT_COMPLITED,
  MCD_TUNE_READY,
  MCD_TUNE_NOT_READY,
  MCD_TUNE_INTERRUPTED
}MCD_AUTO_TUNE_STATUS;

/* DFE Status has the following bits:
   0 - ICal in progress
   1 - PCal in progress
   4 - ICal pending, signal off
   5 - PCal pending, signal off
   6 - adaptive PCal enabled
   7 - Input Offset correction done
   9 - Electrical idle condition detected during calibration:
       - 1 signal was down or still down,
       - 0 signal OK */
typedef enum
{
  MCD_DFE_ICAL_WORKS   = (1 << 0),
  MCD_DFE_PCAL_WORKS   = (1 << 1),
  MCD_DFE_ICAL_PENDING = (1 << 4),
  MCD_DFE_PCAL_PENDING = (1 << 5),
  MCD_DFE_PCAL_ADAPTIVE_ENABLE = (1 << 6),
  MCD_DFE_INPUT_OFFSET_CORRECTED = (1 << 7),
  MCD_DFE_ELECTIC_IDLE_SUGNAL_DOWN = (1 << 9)
} MCD_DFE_STATUS;

typedef struct
{
    MCD_U32     dcGain;
    MCD_U32     lowFrequency;
    MCD_U32     highFrequency;
    MCD_U32     bandWidth;
    MCD_U32     loopBandwidth;
    MCD_U32     squelch;

}MCD_MAN_TUNE_CTLE_CONFIG_DATA;

typedef struct
{
    MCD_U8     etlMinDelay;
    MCD_U8     etlMaxDelay;
    MCD_U8     etlEnableOverride;
}MCD_ETL_CONFIG_DATA;

typedef struct
{
    MCD_U16     attenuation;
    MCD_U16     postCursor;
    MCD_U16     preCursor;
    MCD_U16     dcGain;
    MCD_U16     lowFrequency;
    MCD_U16     highFrequency;
    MCD_U16     bandWidth;
    MCD_U16     loopBandwidth;
    MCD_U16     squelch;

}MCD_SERDES_TXRX_TUNE_PARAMS;

typedef struct
{
    MCD_U32    txDir;
    MCD_U32    rxDir;
}MCD_SERDES_LANE_STEERING_REMAP;

typedef struct
{
    MCD_U8     rxPolarity;
    MCD_U8     txPolarity;
    MCD_U16    preCursor;
    MCD_U16    attenuation;
    MCD_U16    postCursor;

}MCD_SERDES_CONFIG_DATA;

typedef struct
{
    MCD_U8 txOverrideBmp;
    MCD_U16 serdesTxParams; /* txAmp, Emph0, Emph1 */

}MCD_MAN_TUNE_TX_CONFIG_OVERRIDE_DB;

typedef struct
{
    MCD_U16     dcGain;
    MCD_U16     lowFrequency;
    MCD_U16     highFrequency;
    MCD_U16     bandWidth;
    MCD_U16     loopBandwidth;
    MCD_U8      bitMapEnable;
    /*
    dcGain - 0x1
    lowFrequency - 0x2
    highFrequency - 0x4
    bandWitdh - 0x8
    loopBandWith - 0x10
    */
}MCD_PRE_DEFINED_CTLE_DATA;


#if MCD_ENABLE_SERDES_API
#include "mcdSerdes.h"
#endif

#include "mcdApiRegs.h"

extern MCD_U8 mcdBaudRate2DividerValue[LAST_MCD_SERDES_SPEED];


/*
   The MCD_GET_SERDES_ID returns the matching SerDes lane with the given
   parameters below.  Use the MCD_LINE_SIDE and MCD_HOST_SIDE
   definitions to identify the line or host side.

   SerDes lane starts from 1 to 16 when calling diagnostic and setting

   The 88X5121 SerdesId mapping:

   Host Port0: Lane0: SerDesID 8   Host Port1: Lane0: SerDesID 4
               Lane1: SerDesID 7               Lane1: SerDesID 3
               Lane2: SerDesID 6               Lane2: SerDesID 2
               Lane3: SerDesID 5               Lane3: SerDesID 1

   Line Port0: Lane0: SerDesID 9   Line Port1: Lane0: SerDesID 13
               Lane1: SerDesID 10              Lane1: SerDesID 14
               Lane2: SerDesID 11              Lane2: SerDesID 15
               Lane3: SerDesID 12              Lane3: SerDesID 16

   The 88X5123 SerdesId mapping:

   Host Port0: Lane0: SerDesID 9   Host Port1: Lane0: SerDesID 13
               Lane1: SerDesID 10              Lane1: SerDesID 14
               Lane2: SerDesID 11              Lane2: SerDesID 15
               Lane3: SerDesID 12              Lane3: SerDesID 16

   Line Port0: Lane0: SerDesID 1   Line Port1: Lane0: SerDesID 5
               Lane1: SerDesID 2               Lane1: SerDesID 6
               Lane2: SerDesID 3               Lane2: SerDesID 7
               Lane3: SerDesID 4               Lane3: SerDesID 8
*/

#define MCD_GET_SERDES_ID(host_or_line, port_id, lane_offset) \
    (((host_or_line == MCD_HOST_SIDE) ? 8 : 0) + ((port_id << 2)) + lane_offset + 1)

/* Get SERDES number (0..15) from SBUS Address */
#define MCD_SERDES_FROM_SBUS_ADDR_GET(_sbus_addr) ((_sbus_addr) - 1)

/**
* @struct MCD_SERDES_EYE_GET_RESULT
 *
 * @brief A struct containing the results for Serdes Eye Monitoring
*/
typedef struct{

    char *matrixPtr;

    unsigned int                 x_points;

    unsigned int                 y_points;

    char *vbtcPtr;

    char *hbtcPtr;

    unsigned int                 height_mv;

    unsigned int                 width_mui;

} MCD_SERDES_EYE_GET_RESULT;

/**
* @struct MCD_SERDES_EYE_GET_INPUT
 *
 * @brief A struct containing the input parameters for Serdes Eye Monitoring
*/
typedef struct{

    unsigned int            min_dwell_bits;

    unsigned int            max_dwell_bits;

} MCD_SERDES_EYE_GET_INPUT;



/*******************************************************************************
* mvHwsAvagoSerdesEyeGet
*
* DESCRIPTION:
*       Per SERDES return the adapted tuning results
*       Can be run after create port.
*
* INPUTS:
*       devNum    - system device number
*       serdesNum - physical serdes number
*       eye_inputPtr - pointer to input parameters structure
*
* OUTPUTS:
*       eye_resultsPtr - pointer to results structure
*
* RETURNS:
*       0  - on success
*       1  - on error
*
*******************************************************************************/
#ifndef MV_HWS_REDUCED_BUILD_EXT_CM3
unsigned int mvHwsAvagoSerdesEyeGet
(
    unsigned char                       devNum,
    unsigned int                        serdesNum,
    MCD_SERDES_EYE_GET_INPUT  *eye_inputPtr,
    MCD_SERDES_EYE_GET_RESULT *eye_resultsPtr
);

#endif

/******************************************************************************
MCD_STATUS mcdExecuteIndirectSBusCmd
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31

 Outputs:
    None

 Returns:
    MCD_OK if command was executed successful, MCD_FAIL otherwise

 Description:
    The function issues an execute command after an indirect SBUS read or write
    command is issued.

 Side effects:
    None

 Notes/Warnings:
    None

******************************************************************************/
MCD_STATUS mcdExecuteIndirectSBusCmd
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort
);


/******************************************************************************
MCD_STATUS mcdIndirectSBusWrite
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 sBusReceiverAddr,
    IN MCD_U16 regAddr,
    IN MCD_U16 dataH,
    IN MCD_U16 dataL,
    OUT MCD_U16 *resultCode
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    sBusReceiverAddr - SBUS address
    regAddr - register address
    dataH - 16-bit High word to be written
    dataL - 16-bit Low word to be written

 Outputs:
    resultCode - returns 1 if write is successful. Otherwise 0.

 Returns:
    MCD_OK if write was successful, MCD_FAIL otherwise

 Description:
    The function performs an indirect write on both the High and Low 16-bit words to the SBUS.
    There are 3 parts to this operation. The SBUS write command, the High and Low 16-bit words
    and lastly issue the mcdExecuteIndirectSBusCmd to execute the write.

 Side effects:
    None

 Notes/Warnings:
    None
******************************************************************************/
MCD_STATUS mcdIndirectSBusWrite
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 sBusReceiverAddr,
    IN MCD_U16 regAddr,
    IN MCD_U16 dataH,
    IN MCD_U16 dataL,
    OUT MCD_U16 *resultCode
);

#ifndef MV_HWS_REDUCED_BUILD_EXT_CM3
/******************************************************************************
MCD_STATUS mcdIndirectSBusRead
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 sBusReceiverAddr,
    IN MCD_U16 regAddr,
    OUT MCD_U16 *dataH,
    OUT MCD_U16 *dataL,
    OUT MCD_U16 *resultCode
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    sBusReceiverAddr - SBUS address
    regAddr - register address

 Outputs:
    dataH - returns 16-bit High word of the requested address
    dataL - returns 16-bit Low word of the requested address
    resultCode - returns 1 if write is successful. Otherwise 0.

 Returns:
    MCD_OK if read was successful, MCD_FAIL otherwise

 Description:
    The function performs an indirect read on both the High and Low 16-bit words to the SBUS.
    There are 3 parts to this operation. The SBUS read command, the High and Low 16-bit words
    and lastly issue the mcdExecuteIndirectSBusCmd to execute the read.

 Side effects:
    None

 Notes/Warnings:
    None
******************************************************************************/
MCD_STATUS mcdIndirectSBusRead
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 sBusReceiverAddr,
    IN MCD_U16 regAddr,
    OUT MCD_U16 *dataH,
    OUT MCD_U16 *dataL,
    OUT MCD_U16 *resultCode
);
#endif
/******************************************************************************
void mcdSerdesoAaplInit

    IN MCD_DEV_PTR pDev
 Description:
    The function  updates aapl structure for CM3

    Side effects:
    None

 Notes/Warnings:
    None
******************************************************************************/
MCD_STATUS mcdSerdesoAaplInit(MCD_DEV_PTR  pDev);

/**
* @internal mcdSerdesSpicoInterrupt function
* @endinternal
 *
* @param[out] result                   - spico interrupt return value
*/
int mcdSerdesSpicoInterrupt
(
    MCD_DEV_PTR     pDev,
    unsigned int    serdesNum,
    unsigned int    interruptCode,
    unsigned int    interruptData,
    int             *result
);

/**
* @internal mcdSerdesTxEnable function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesTxEnable
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_BOOL                        enable
);

/**
* @internal mcdSerdesTxRxEnableSet function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesTxRxEnableSet
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_BOOL                        txEnable,
    MCD_BOOL                        rxEnable,
    MCD_BOOL                        tx_outputEnable
);

/**
* @internal mcdSerdesSignalDetectGet function
* @endinternal
 *
* @param[out] signalDet                - TRUE if signal detected and FALSE otherwise.
*/
MCD_STATUS mcdSerdesSignalDetectGet
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_BOOL                        *signalDet
);

/**
* @internal mcdSerdesDfeConfig_noSignalCheck function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesDfeConfig_noSignalCheck
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_DFE_MODE                    dfeMode
);

/**
* @internal mcdSerdesDataVoltageOffsetCheck function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[out] stateIsOk                - MCD_TRUE - data voltage offset OK, MCD_FALSE - out of valid bounds
*/
MCD_STATUS mcdSerdesDataVoltageOffsetCheck
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_BOOL                        *stateIsOk
);

/**
* @internal mcdSerdesAutoTuneStatus function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[out] rxStatus                 - status of Rx-Training
* @param[out] txStatus                 - status of TX-Training
*/
MCD_STATUS mcdSerdesAutoTuneStatus
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_AUTO_TUNE_STATUS            *rxStatus,
    MCD_AUTO_TUNE_STATUS            *txStatus
);
/**
* @internal mcdSerdesRxAutoTuneStatusGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[out] rxStatus                 - status of Rx-Training
*/
MCD_STATUS mcdSerdesRxAutoTuneStatusGet
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_AUTO_TUNE_STATUS            *rxStatus
);

/**
* @internal mcdSerdesDfeStatusGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[out] dfeStatusBitmapPtr       - status of DFE as in HW
*/
MCD_STATUS mcdSerdesDfeStatusGet
(
    MCD_DEV_PTR               pDev,
    MCD_U8                    serdesNum,
    MCD_DFE_STATUS            *dfeStatusBitmapPtr
);

/**
* @internal mcdSerdesManualTxConfig function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesManualTxConfig
(
    MCD_DEV_PTR         pDev,
    MCD_U8              serdesNum,
    MCD_16              txAmp,
    MCD_16              emph0,
    MCD_16              emph1
);

/**
* @internal mcdSerdesManualCtleConfig function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[in] dcGain                   - DC-Gain value        (rang: 0-255)
* @param[in] lowFrequency             - CTLE Low-Frequency   (rang: 0-15)
* @param[in] highFrequency            - CTLE High-Frequency  (rang: 0-15)
* @param[in] bandWidth                - CTLE Band-width      (rang: 0-15)
* @param[in] loopBandwidth            - CTLE Loop Band-width (rang: 0-15)
* @param[in] squelch                  - Signal OK threshold  (rang: 0-310)
*/
MCD_STATUS mcdSerdesManualCtleConfig
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_U8                          dcGain,
    MCD_U8                          lowFrequency,
    MCD_U8                          highFrequency,
    MCD_U8                          bandWidth,
    MCD_U8                          loopBandwidth,
    MCD_U16                         squelch
);

/**
* @internal mcdSerdesManualCtleConfigGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical lane number
* @param[out] configParams             - Ctle params structures:
*/
MCD_STATUS mcdSerdesManualCtleConfigGet
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_MAN_TUNE_CTLE_CONFIG_DATA   *configParams
);
/**
* @internal mcdSerdesSignalOkCfg function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[in] signalThreshold          - Signal OK threshold (0-15)
*/
MCD_STATUS mcdSerdesSignalOkCfg
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_U8                          signalThreshold
);

/**
* @internal mcdSerdesSignalOkThresholdGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[out] signalThreshold          - Signal OK threshold (0-15)
*/
MCD_STATUS mcdSerdesSignalOkThresholdGet
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_U8                          *signalThreshold
);

#ifndef MV_HWS_REDUCED_BUILD_EXT_CM3
/******************************************************************************
MCD_STATUS mcdSerdesInterrupt
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 sBusReceiverAddr,
    IN MCD_U16 interruptCode,
    IN MCD_U16 interruptData,
    OUT MCD_U16 interruptResult
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    sBusReceiverAddr - SBUS address
    interruptCode - SerDes interrupt code to issue
    interruptData - SerDes interrupt data to issue

 Outputs:
    interruptResult - returns the result of the issued interrupt code and data

 Returns:
    MCD_OK if interrupt issued was successful, MCD_FAIL otherwise

 Description:
    The function issue an interrupt code and data. It retries up to 100 time for
    the interrupt completion.

 Side effects:
    None

 Notes/Warnings:
    None
******************************************************************************/
MCD_STATUS mcdSerdesInterrupt
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 sBusReceiverAddr,
    IN MCD_U16 interruptCode,
    IN MCD_U16 interruptData,
    OUT MCD_U16 *interruptResult
);

/******************************************************************************
MCD_STATUS mcdSbusInterrupt
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 interruptCode,
    IN MCD_U16 interruptInput,
    OUT MCD_U16 *interruptResult,
    OUT MCD_U16 *interruptStatus
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    sBusReceiverAddr - SBUS address
    interruptCode - SBUS interrupt code to issue
    interruptInput - SBUS interrupt input data to issue

 Outputs:
    interruptResult - returns the result of the issued interrupt code and data
    interruptStatus - returns the status of the issued interrupt

 Returns:
    MCD_OK if interrupt issued was successful, MCD_FAIL otherwise

 Description:
    The function issue an interrupt code and data. It retries up to 500 time for
    the interrupt completion.

 Side effects:
    None

 Notes/Warnings:
    None
******************************************************************************/
MCD_STATUS mcdSbusInterrupt
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 interruptCode,
    IN MCD_U16 interruptInput,
    OUT MCD_U16 *interruptResult,
    OUT MCD_U16 *interruptStatus
);
#endif /* MV_HWS_REDUCED_BUILD_EXT_CM3 */
#if MCD_ENABLE_SERDES_API

/**
* @internal mcdLoadSBusSerdesFromCpuMemory function
* @endinternal
 *
*/
MCD_STATUS mcdLoadSBusSerdesFromCpuMemory
(
    MCD_DEV_PTR pDev,
    unsigned int sbus_addr,
    IN MCD_U16 imageSize,
    IN MCD_U16 const image[]
);

/**
* @internal mcdLoadSBusMasterFromCpuMemory function
* @endinternal
 *
*/
MCD_STATUS mcdLoadSBusMasterFromCpuMemory
(
    MCD_DEV_PTR pDev,
    IN MCD_U16 imageSize, /* 0 if skipped */
    IN MCD_U16 const image[],
    IN MCD_U16 swapImageSize, /* 0 if skipped */
    IN MCD_U16 const swapImage[]
);

/******************************************************************************
MCD_STATUS mcdInitSerdesDev
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16     const *pBusMasterImage,
    IN MCD_U16     busMasterImageSize,
    IN MCD_U16     const *pBusMasterSwapImage,
    IN MCD_U16     busMasterSwapImageSize,
    IN MCD_U16     const *pSerdesImage,
    IN MCD_U16     serdesImageSize
);
 Inputs:
    pDev                      - pointer to MCD_DEV initialized by mcdInitDriver() call
    pBusMasterImage           - input buffer image of the SBUS Master ROM
    busMasterImageSize        - SBUS Master ROM image size
    pBusMasterSwapImage       - input buffer Swap image of the SBUS Master ROM
    busMasterSwapImageSize    - SBUS Master ROM Swap image size
    pSerdesImage              - input buffer image of the SERDES ROM
    serdesImageSize           - SERDES ROM image size

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This SerDes initialization function is called during mcdInitDriver() when the
    MCD_ENABLE_SERDES_API is set to 1. This function allocates the device structure
    memory requires when the Serdes API is called. In addition, it will initialize
    the MDIO read/write function pointer for the serdes API operation.

 Side effects:
    None

 Notes/Warnings:
    The mcdFreeSerdesDev must be called when the driver unloads or exits. The
    mcdFreeSerdesDev will release the serdes device structure memory.
*******************************************************************************/
MCD_STATUS mcdInitSerdesDev
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16     const *pBusMasterImage,
    IN MCD_U16     busMasterImageSize,
    IN MCD_U16     const *pBusMasterSwapImage,
    IN MCD_U16     busMasterSwapImageSize,
    IN MCD_U16     const *pSerdesImage,
    IN MCD_U16     serdesImageSize
);

/******************************************************************************
MCD_STATUS mcdFreeSerdesDev
(
    IN MCD_DEV_PTR pDev
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function releases the Serdes API device structure memory.

 Side effects:
    None

 Notes/Warnings:
    The mcdFreeSerdesDev must be called when the driver unloads or exits. The
    mcdFreeSerdesDev will release the serdes device structure memory.
*******************************************************************************/
MCD_STATUS mcdFreeSerdesDev
(
    IN MCD_DEV_PTR pDev
);


/**
* @internal mcdSerdesPowerCtrl function
* @endinternal
 *
*/
int mcdSerdesPowerCtrl
(
    MCD_DEV_PTR         pDev,
    unsigned int        serdesNum,
    unsigned char       powerUp,
    MCD_SERDES_SPEED    baudRate,
    MCD_BOOL            retimrMode,
    MCD_U32             refClkSel,
    MCD_U32             refClkDiv
);

/******************************************************************************
 MCD_STATUS mcdSerdesGetEye
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 sampleSize,
   IN MCD_U16 highDefinition,
   IN MCD_U16 serdesLogLevel,
   OUT PMCD_EYE_DATA eyeDataBuf
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    sampleSize - The eye sample size based on the max dwell bit.
                       Range [4 to 8] where x is the exponential
                       e.g. 4 = 10,000; 8 = 100,000,000
    highDefinition - MCD_DISABLE: disable high resolution;
                     MCD_ENABLE: enable high definition
                     The high definition option increases the y resolution to 1 step
    serdesLogLevel - The level of logging in the serdes APIs
                     Range [0 - 15]. Set to 0 when not debugging.

 Outputs:
   eyeDataBuf - The output results for the SerDes eye, vertical and horizontal bathtub.
                Refer to the MCD_EYE_DATA data structure.

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    The function gathers the eye diagram measurements including the vertical
    and horizontal bathtub measurements from an individual SerDes lane.
    The output in the eyeDataBuf returns all the useful eye measurements.

    The pEyeData in this function holds the raw data values. Refer to the
    MCD_SER_EYE_CONFIG_TYPE, MCD_SER_EYE_DATA_TYPE and MCD_EYE_DATA for
    descriptions of configuration and return data values.

 Side effects:
    None

 Notes/Warnings:
    This function takes several seconds to complete. In the event of a slower
    read access or selecting the high definition measurements, it may take up
    to a minute.

    The memory usage significantly increases when the serdesLogLevel is set
    to > 0. If debugging/logging is not required, serdesLogLevel should be 0.

    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetEye
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 sampleSize,
   IN MCD_U16 highDefinition,
   IN MCD_U16 serdesLogLevel,
   OUT PMCD_EYE_DATA eyeDataBuf
);
/**
* @internal mcdSerdesEyeGetExt function
* @endinternal
 *
* @param[out] eye_resultsPtr           - pointer to results structure
*/
MCD_STATUS mcdSerdesEyeGetExt
(
    IN MCD_DEV_PTR                          pDev,
    IN MCD_U16                              sAddr,
    IN MCD_SERDES_EYE_GET_INPUT             *eye_inputPtr,
    OUT MCD_SERDES_EYE_GET_RESULT           *eye_resultsPtr
);

#ifndef MV_HWS_REDUCED_BUILD_EXT_CM3
/******************************************************************************
MCD_STATUS mcdSerdesGetRevision
(
   IN MCD_DEV_PTR pDev,
   OUT MCD_U16 *serdesRevision,
   OUT MCD_U16 *sbmRevision
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call

 Outputs:
    serdesRevision - SerDes revision
    sbmRevision - SBus master revision

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This call returns the SerDes and SBus master revisions

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetRevision
(
   IN MCD_DEV_PTR pDev,
   OUT MCD_U16 *serdesRevision,
   OUT MCD_U16 *sbmRevision
);
#endif

/******************************************************************************
MCD_STATUS mcdSerdesGetVoltage
(
   IN MCD_DEV_PTR pDev,
   OUT MCD_U16 *coreVoltage,
   OUT MCD_U16 *DVDDVoltage,
   OUT MCD_U16 *AVDDVoltage
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call

 Outputs:
    coreVoltage - Core voltage value
    DVDDVoltage - DVDD voltage value
    AVDDVoltage - AVDD voltage value

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    The call returns the output voltages of the core, DVDD and AVDD.
    The values return in the outputs are in millivolt(mV).

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetVoltage
(
   IN MCD_DEV_PTR pDev,
   OUT MCD_U16 *coreVoltage,
   OUT MCD_U16 *DVDDVoltage,
   OUT MCD_U16 *AVDDVoltage
);


/*******************************************************************************
MCD_STATUS mcdSerdesGetTemperature(
    IN MCD_DEV_PTR pDev,
    OUT MCD_32 *coreTemperature,
    OUT MCD_32 *serdesTemperature
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call

 Outputs:
    serdesTemperature - SerDes temperature value
    coreTemperature   - Core temperature value

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    The call returns the temperatures of the Core and SerDes.
    The values return in the outputs are in milli-Celsius(mC).

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetTemperature
(
    IN MCD_DEV_PTR pDev,
    OUT MCD_32 *serdesTemperature,
    OUT MCD_32 *coreTemperature
);

/*******************************************************************************
* mcdSerdesVcoConfig
*
* DESCRIPTION:
*       Compensate the VCO calibration value according to Temperature in order
*       to enable Itemp operation
*
* INPUTS:
*       pSerdesDev
*       serdesNum - SERDES number
*       temperature - Temperature (in C) from Avago Serdes
*       txTherm     - Tx Thermometer of VCO  (0...0xFFFF)
*       txBin       - Tx bin of VCO  (0...0xFFFF)
*       rxTherm     - Rx Thermometer of VCO  (0...0xFFFF)
*       rxBin       - Rx bin of VCO  (0...0xFFFF)
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       0  - on success
*       1  - on error
*
*******************************************************************************/
unsigned int mcdSerdesVcoConfig
(
    MCD_DEV_PTR     pDev,
    unsigned int    serdesNum,
    int     temperature,
    int     txTherm,
    int     txBin,
    int     rxTherm,
    int     rxBin
);

/*******************************************************************************
* mcdSerdesCalCodeGet
*
* DESCRIPTION:
*       Get the calibration code(value) for Rx or Tx
*
* INPUTS:
*       pDev
*       serdesNum - SERDES number
*       mode      - True for Tx mode, False for Rx mode
*
* OUTPUTS:
*       therm - Thermometer of VCO  (0...0xFFFF)
*       bin   - bin of VCO  (0...0xFFFF)
*
* RETURNS:
*       0  - on success
*       1  - on error
*
*******************************************************************************/
unsigned int mcdSerdesCalCodeGet
(
    MCD_DEV_PTR     pDev,
    int serdesNum,
    MCD_BOOL    mode,
    int         *therm,
    int         *bin
);

/******************************************************************************
MCD_STATUS mcdSerdesGetTxFFE
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_16 *preCursor,
   OUT MCD_16 *attenuation,
   OUT MCD_16 *postCursor,
   OUT MCD_16 *slew
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr

 Outputs:
    preCursor   - Pre-cursor setting
    attenuation - Attenuator setting
    postCursor  - Post-cursor setting
    slew - Slew rate setting [0..3], 0 is fastest

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function call returns the TX equalization values of an individual
    SerDes lane.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetTxFFE
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_16 *preCursor,
   OUT MCD_16 *attenuation,
   OUT MCD_16 *postCursor,
   OUT MCD_16 *slew
);


/******************************************************************************
MCD_STATUS mcdSerdesSetTxFFE
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_16 preCursor,
   IN MCD_16 attenuation,
   IN MCD_16 postCursor,
   IN MCD_16 slew
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    preCursor   - Pre-cursor setting range [-7 to 15]
    attenuation - Attenuator setting range [0 to 31]
    postCursor  - Post-cursor setting [-31 to 31]
    slew - Slew rate setting [0..3], 0 is fastest

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function sets the TX equalization preCursor, attenuation,
    postCursor and slew values on an individual SerDes lane.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesSetTxFFE
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_16 preCursor,
   IN MCD_16 attenuation,
   IN MCD_16 postCursor,
   IN MCD_16 slew
);


/******************************************************************************
MCD_STATUS mcdSerdesGetTxPolarity
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_U16 *polarity
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr

 Outputs:
    polarity - returns 1 if inverter is enabled, 0 if data is not being inverted.

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function returns the TX inverter polarity for an individual SerDes lane.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetTxPolarity
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_U16 *polarity
);


/******************************************************************************
MCD_STATUS mcdSerdesSetTxPolarity
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 polarity
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    polarity - 1 to invert TX polarity, 0 to use normal polarity.

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function sets the TX inverter polarity with the given value for an
    individual SerDes lane.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesSetTxPolarity
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 polarity
);


/******************************************************************************
MCD_STATUS mcdSerdesGetRxPolarity
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_U16 *polarity
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr

 Outputs:
    polarity - returns 1 if inverter is enabled, 0 if data is not being inverted.

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function returns the RX inverter polarity for an individual SerDes lane.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetRxPolarity
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_U16 *polarity
);


/******************************************************************************
MCD_STATUS mcdSerdesSetRxPolarity
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 polarity
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    polarity - 1 to invert RX polarity, 0 to use normal polarity

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function sets the RX inverter polarity with the given value for
    an individual SerDes lane.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesSetRxPolarity
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 polarity
);


/******************************************************************************
MCD_STATUS mcdSerdesGetCDRLock
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_U16 *CDRLockState
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr

 Outputs:
    CDRLockState - returns 1 if locked; 0 if not locked;

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function retrieves the Clock Data Recovery(CDR) lock state for an
    individual SerDes lane.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetCDRLock
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_U16 *CDRLockState
);


/******************************************************************************
MCD_STATUS mcdSerdesPMDTrainingLog
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT PMCD_TRAINING_INFO pTrainInfo
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr

 Outputs:
    pTrainInfo - Training log data is stored in the output structure. Refer to
                 the MCD_TRAINING_INFO and MCD_TRAINING_STATS structures for more
                 info on the values.

                 This is a pointer to an MCD_TRAINING_INFO structure.

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function retrieves the link training log for an individual SerDes lane.
    The output results are stored in the pTrainInfo. The caller must pass in
    a pre-allocated memory MCD_TRAINING_INFO structure for the pTrainInfo
    to store the training log results.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesPMDTrainingLog
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT PMCD_TRAINING_INFO pTrainInfo /* this is a pointer to an MCD_TRAINING_INFO */
);

/******************************************************************************
MCD_STATUS mcdSerdesTxInjectError
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 numErrBit
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    numErrBit - Number of error bits to inject (max=65535)

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function injects errors into the TX data on an individual SerDes lane.
    TX error injection affects the transmitted data stream. Therefore, errors
    are only detected when comparing with a known pattern.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesTxInjectError
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 numErrBit
);


/******************************************************************************
MCD_STATUS mcdSerdesRxInjectError
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 numErrBit
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    numErrBit - Number of error bits to inject.

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function injects errors into the RX data on an individual SerDes lane.
    RX error injection affects only the main data channel. Therefore, errors
    are only detected if the MAIN channel is one of the selected compare inputs.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesRxInjectError
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 numErrBit
);


/******************************************************************************
MCD_STATUS mcdSerdesSetTxPRBS
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_SERDES_TX_DATA_TYPE txDataType
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    txDataType - Tx data selection. Refer to MCD_SERDES_TX_DATA_TYPE for selections
        MCD_SERDES_TX_DATA_SEL_PRBS7    = 0, < PRBS7 (x^7+x^6+1)
        MCD_SERDES_TX_DATA_SEL_PRBS9    = 1, < PRBS9 (x^9+x^7+1)
        MCD_SERDES_TX_DATA_SEL_PRBS11   = 2, < PRBS11 (x^11+x^9+1)
        MCD_SERDES_TX_DATA_SEL_PRBS15   = 3, < PRBS15 (x^15+x^14+1)
        MCD_SERDES_TX_DATA_SEL_PRBS23   = 4, < PRBS23 (x^23+x^18+1)
        MCD_SERDES_TX_DATA_SEL_PRBS31   = 5, < PRBS31 (x^31+x^28+1)
        MCD_SERDES_TX_DATA_SEL_USER     = 7, < User pattern generator
        MCD_SERDES_TX_DATA_SEL_CORE     = 8, < External data
        MCD_SERDES_TX_DATA_SEL_LOOPBACK = 9  < Parallel loopback from receiver

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function sets the Tx PRBS data source on an individual SerDes lane.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesSetTxPRBS
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_SERDES_TX_DATA_TYPE txDataType
);

/******************************************************************************
MCD_STATUS mcdSerdesGetTxPRBS
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_SERDES_TX_DATA_TYPE *txDataType
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr

 Outputs:
    txDataType - Returns the Tx data selection. Refer to MCD_SERDES_TX_DATA_TYPE
                 for selection type.
        MCD_SERDES_TX_DATA_SEL_PRBS7    = 0, < PRBS7 (x^7+x^6+1)
        MCD_SERDES_TX_DATA_SEL_PRBS9    = 1, < PRBS9 (x^9+x^7+1)
        MCD_SERDES_TX_DATA_SEL_PRBS11   = 2, < PRBS11 (x^11+x^9+1)
        MCD_SERDES_TX_DATA_SEL_PRBS15   = 3, < PRBS15 (x^15+x^14+1)
        MCD_SERDES_TX_DATA_SEL_PRBS23   = 4, < PRBS23 (x^23+x^18+1)
        MCD_SERDES_TX_DATA_SEL_PRBS31   = 5, < PRBS31 (x^31+x^28+1)
        MCD_SERDES_TX_DATA_SEL_USER     = 7, < User pattern generator
        MCD_SERDES_TX_DATA_SEL_CORE     = 8, < External data
        MCD_SERDES_TX_DATA_SEL_LOOPBACK = 9  < Parallel loopback from receiver

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function retrieves the selected Tx PRBS data type for the SerDes lane.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetTxPRBS
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_SERDES_TX_DATA_TYPE *txDataType
);

/******************************************************************************
MCD_STATUS mcdSerdesSetTxUserData
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_32 userData[4]
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    userData[4] - 80-bit user data (4 x 20).

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function loads the 80-bit value into the TX user data register and
    select it as the TX input. The bit transmit order is from the least
    significant bit [0] of user_data[0] through bit [19] of user_data[3].
    Each word holds 20 significant bits.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesSetTxUserData
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_32 userData[4]
);


/******************************************************************************
MCD_STATUS mcdSerdesGetTxUserData
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_32 userData[4]
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr

 Outputs:
    userData[4] - 80-bit user data (4 x 20)

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function retrieves the 80-bit TX user data register.

    Only the first 20 bits of the pattern are returned as that is all
    that is readily available from the SerDes.

    These bits are then duplicated into the other bits.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.

    Only the first 20 bits of the pattern are returned as that is all
    that is readily available from the SerDes. See description for details.
*******************************************************************************/
MCD_STATUS mcdSerdesGetTxUserData
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_32 userData[4]
);

#ifndef MV_HWS_REDUCED_BUILD_EXT_CM3
/******************************************************************************
MCD_STATUS mcdSerdesSetRxCmpData
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_SERDES_RX_CMP_TYPE RxCmpType
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    RxCmpType - Rx compare data setting. Refer to MCD_SERDES_RX_CMP_TYPE for
                selections
        MCD_SERDES_RX_CMP_DATA_PRBS7     = 0, < PRBS7 (x^7+x^6+1)
        MCD_SERDES_RX_CMP_DATA_PRBS9     = 1, < PRBS9 (x^9+x^7+1)
        MCD_SERDES_RX_CMP_DATA_PRBS11    = 2, < PRBS11 (x^11+x^9+1)
        MCD_SERDES_RX_CMP_DATA_PRBS15    = 3, < PRBS15 (x^15+x^14+1)
        MCD_SERDES_RX_CMP_DATA_PRBS23    = 4, < PRBS23 (x^23+x^18+1)
        MCD_SERDES_RX_CMP_DATA_PRBS31    = 5, < PRBS31 (x^31+x^28+1)
        MCD_SERDES_RX_CMP_DATA_SELF_SEED = 7, < Auto-seed to received 40 bit repeating pattern.
                                              < NOTE: This is USER mode in firmware.
        MCD_SERDES_RX_CMP_DATA_OFF       = 8  < Disable cmp data generator

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function sets the RX compare data configuration. It sets the PRBS pattern
    to compare incoming data against. If MCD_SERDES_RX_CMP_DATA_SELF_SEED is
    selected, the comparator automatically synchronizes to an incoming 80 bit
    pattern. The error counter then reports deviations from that pattern.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesSetRxCmpData
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_SERDES_RX_CMP_TYPE RxCmpType
);

/******************************************************************************
MCD_STATUS mcdSerdesGetRxCmpData
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_SERDES_RX_CMP_TYPE *RxCmpType
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr

 Outputs:
    RxCmpType - Rx compare data type from the MCD_SERDES_RX_CMP_TYPE selection
        MCD_SERDES_RX_CMP_DATA_PRBS7     = 0, < PRBS7 (x^7+x^6+1)
        MCD_SERDES_RX_CMP_DATA_PRBS9     = 1, < PRBS9 (x^9+x^7+1)
        MCD_SERDES_RX_CMP_DATA_PRBS11    = 2, < PRBS11 (x^11+x^9+1)
        MCD_SERDES_RX_CMP_DATA_PRBS15    = 3, < PRBS15 (x^15+x^14+1)
        MCD_SERDES_RX_CMP_DATA_PRBS23    = 4, < PRBS23 (x^23+x^18+1)
        MCD_SERDES_RX_CMP_DATA_PRBS31    = 5, < PRBS31 (x^31+x^28+1)
        MCD_SERDES_RX_CMP_DATA_SELF_SEED = 7, < Auto-seed to received 40 bit repeating pattern.
                                              < NOTE: This is USER mode in firmware.
        MCD_SERDES_RX_CMP_DATA_OFF       = 8  < Disable cmp data generator

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function retrieves the Rx compare data configuration that is set by
    the mcdSerdesSetRxCmpData function.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetRxCmpData
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   OUT MCD_SERDES_RX_CMP_TYPE *RxCmpType
);

/******************************************************************************
MCD_STATUS mcdSerdesGetErrCount
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_BOOL resetCounter,
   OUT MCD_U32 *errCount
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    resetCounter - Set to MCD_TRUE to reset error count after read or
                   MCD_FALSE to not reset the error counter.

 Outputs:
    errCount - returns the number of error count

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function retrieves the error count for the earlier operations.

    If the resetCounter is MCD_TRUE will reset the error counter to 0
    after reading the value.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesGetErrCount
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_BOOL resetCounter,
   OUT MCD_U32 *errCount
);

#endif /* MV_HWS_REDUCED_BUILD_EXT_CM3 */
#define MCD_CLEAR_SERDES_LOOPBACK 0
#define MCD_DEEP_SERDES_LOOPBACK 1
#define MCD_SHALLOW_SERDES_LOOPBACK 2
#define MCD_PARALLEL_SERDES_LOOPBACK 2
/******************************************************************************
MCD_STATUS mcdSerdesSetLoopback
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 loopbackMode
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr
    loopbackMode -  MCD_CLEAR_SERDES_LOOPBACK(0)
                    MCD_DEEP_SERDES_LOOPBACK(1)
                    MCD_SHALLOW_SERDES_LOOPBACK(2)

 Outputs:
    None

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function sets an individual serdes lane to input loopback mode.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesSetLoopback
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr,
   IN MCD_U16 loopbackMode
);

/**
* @internal mcdSerdesEnhanceTune function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesArr                - collection of SERDESes to configure
* @param[in] numOfSerdes              - number of SERDESes to configure
* @param[in] min_LF                   - Minimum LF value that can be set on Serdes (0...15)
* @param[in] max_LF                   - Maximum LF value that can be set on Serdes (0...15)
*/
MCD_STATUS mcdSerdesEnhanceTune
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                         *serdesArr,
    MCD_U8                          numOfSerdes,
    MCD_U8                          min_LF,
    MCD_U8                          max_LF
);

/**
* @internal mcdSerdesEnhanceTuneLite function
* @endinternal
 *
* @param[in] pDev                     - system device number
* @param[in] serdesArr                - collection of SERDESes to configure
* @param[in] numOfSerdes              - number of SERDESes to configure
* @param[in] serdesSpeed              - speed of serdes
* @param[in] min_dly                  - Minimum delay_cal value:
*                                      - for Serdes speed 10G (25...28)
*                                      - for Serdes speed 25G (15...19)
* @param[in] max_dly                  - Maximum delay_cal value:
*                                      - for Serdes speed 10G (30)
*                                      - for Serdes speed 25G (21)
*/
MCD_STATUS mcdSerdesEnhanceTuneLite
(
    MCD_DEV_PTR       pDev,
    MCD_U8      *serdesArr,
    MCD_U8     numOfSerdes,
    MCD_SERDES_SPEED    serdesSpeed,
    MCD_U8                   min_dly,
    MCD_U8                   max_dly
);

/**
* @internal mcdSerdesEnhanceTuneLitePhase1 function
* @endinternal
 *
* @param[in] pDev                     - system device number
* @param[in] serdesArr                - collection of SERDESes to configure
* @param[in] numOfSerdes              - number of SERDESes to configure
* @param[in] serdesSpeed              - speed of serdes
* @param[in] currentDelaySize         - delays array size
* @param[in] currentDelayPtr          - delays array
* @param[in] inOutI                   - iteration index between different phases
* @param[in] best_eye                 - best eyes array to update
* @param[in] best_dly                 - best delays array to update
* @param[in] subPhase                 - assist flag to know which code to execute in this sub-phase
* @param[out] inOutI                   - iteration index between different phases
* @param[out] best_eye                 - best eyes array to update
* @param[out] best_dly                 - best delays array to update
* @param[out] subPhase                 - assist flag to know which code to execute in this sub-phase
*/
MCD_STATUS mcdSerdesEnhanceTuneLitePhase1
(
    MCD_DEV_PTR       pDev,
    MCD_U8      *serdesArr,
    MCD_U8     numOfSerdes,
    MCD_SERDES_SPEED     serdesSpeed,
    MCD_U8       currentDelaySize,
    MCD_U8       *currentDelayPtr,
    MCD_U8       *inOutI,
    MCD_U16      *best_eye,
    MCD_U8       *best_dly,
    MCD_U8       *subPhase,
    MCD_U8    min_dly,
    MCD_U8    max_dly
);

/**
* @internal mcdSerdesEnhanceTuneLitePhase2 function
* @endinternal
 *
* @param[in] pDev                     - system device number
* @param[in] serdesArr                - collection of SERDESes to configure
* @param[in] numOfSerdes              - number of SERDESes to configure
* @param[in] best_dly                 - best delay to set on serdes
*/
MCD_STATUS mcdSerdesEnhanceTuneLitePhase2
(
    MCD_DEV_PTR    pDev,
    MCD_U8      *serdesArr,
    MCD_U8     numOfSerdes,
    MCD_U8       *best_dly
);

/**
* @internal mcdSerdesDefaultMinMaxDlyGet function
* @endinternal
 *
* @param[in] laneSpeed                - mode type of port
*/
MCD_STATUS mcdSerdesDefaultMinMaxDlyGet
(
    MCD_SERDES_SPEED         laneSpeed,
    MCD_U8              *min_dly_ptr,
    MCD_U8              *max_dly_ptr
);

/**
* @internal mcdSerdesAutoTuneStatusShort function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[out] rxStatus                 - Rx-Training status
* @param[out] txStatus                 - Tx-Training status
*/
MCD_STATUS mcdSerdesAutoTuneStatusShort
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_AUTO_TUNE_STATUS            *rxStatus,
    MCD_AUTO_TUNE_STATUS            *txStatus
);

/**
* @internal mcdSerdesBypassCtleTuneStart function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesBypassCtleTuneStart
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum
);
/**
* @internal mcdSerdesAutoTuneStartExt function
* @endinternal
 *
*/

MCD_STATUS mcdSerdesAutoTuneStartExt
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_RX_TRAINING_MODES           rxTraining,
    MCD_TX_TRAINING_MODES           txTraining
);

/**
* @internal mcdSerdesAutoTuneStartExtAp function
* @endinternal
 *
*/

MCD_STATUS mcdSerdesAutoTuneStartExtAp
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_RX_TRAINING_MODES           rxTraining,
    MCD_TX_TRAINING_MODES           txTraining,
    MCD_U32                         laneSpeed,
    MCD_U32                         laneNum
);


/******************************************************************************
MCD_STATUS mcdSerdesReset
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    sAddr - SerDes lane. Range [1 to 16]; Refer to MCD_GET_SERDES_ID for sAddr

 Outputs:
    none

 Returns:
    MCD_OK if successful, MCD_FAIL otherwise

 Description:
    This function resets a SerDes lane on a given SerDes lane ID.

 Side effects:
    None

 Notes/Warnings:
    Calling this function requires blocking all other caller from issuing
    interrupt read/write calls to the SerDes and SBus master.
*******************************************************************************/
MCD_STATUS mcdSerdesReset
(
   IN MCD_DEV_PTR pDev,
   IN MCD_U16 sAddr
);
/**
* @internal mcdSerdesAccessLock function
* @endinternal
 *
*/
void mcdSerdesAccessLock
(
    MCD_DEV_PTR pDev
);

/**
* @internal mcdSerdesAccessUnlock function
* @endinternal
 *
*/
void mcdSerdesAccessUnlock
(
   MCD_DEV_PTR pDev
);


/*******************************************************************************
* mcdSerdesResetImpl
*
* DESCRIPTION:
*       Per SERDES Clear the serdes registers (back to defaults.
*
* INPUTS:
*       pSerdesDev
*       serdesNum - serdes number
*       analogReset - Analog Reset (On/Off)
*       digitalReset - digital Reset (On/Off)
*       syncEReset - SyncE Reset (On/Off)
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       0  - on success
*       1  - on error
*
*******************************************************************************/
unsigned int mcdSerdesResetImpl
(
    MCD_DEV_PTR      pDev,
    unsigned int     serdesNum,
    unsigned int     analogReset,
    unsigned int     digitalReset,
    unsigned int     syncEReset
);

/**
* @internal mcdSerdesRxTune function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                -  SERDES number
*/
MCD_STATUS mcdSerdesRxTune
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum
);

/**
* @internal mcdSerdesSetOneSideRetimerMode function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesSetOneSideRetimerMode
(
    MCD_DEV_PTR         pDev,
    MCD_U8              serdesNum,
    MCD_U8              clockSourceSerdesNum,
    MCD_SERDES_SPEED    baudRate,
    MCD_U8              useSimpleTuneOnly
);
#ifndef MV_HWS_REDUCED_BUILD_EXT_CM3
/**
* @internal mcdSerdesSetRetimerMode function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesSetRetimerMode
(
    MCD_DEV_PTR         pDev,
    MCD_U8              serdesNum,
    MCD_SERDES_SPEED    baudRate
);
#endif
/**
* @internal mcdSerdesSetRetimerClock function
* @endinternal
 *
*/
MCD_STATUS  mcdSerdesSetRetimerClock
(
    MCD_DEV_PTR         pDev,
    unsigned int        serdesNum,
    MCD_SERDES_SPEED    baudRate
);
/**
* @internal mcdSerdesSetRetimerClockLaneSteeringMode function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesSetRetimerClockLaneSteeringMode
(
    MCD_DEV_PTR         pDev,
    unsigned int        serdesNum,
    unsigned int        partnerSerdesNum,
    MCD_SERDES_SPEED    baudRate
);

/**
* @internal mcdSetSerdesLaneCfgForRetimerMode function
* @endinternal
 *
*/
MCD_STATUS mcdSetSerdesLaneCfgForRetimerMode
(
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 serdesLane,
     IN MCD_SERDES_SPEED baudRate       /*  Retimer mode from the list             */
);

/**
* @internal mcdSetSerdesLaneCfgForRetimerModePreSet function
* @endinternal
 *
*/
MCD_STATUS mcdSetSerdesLaneCfgForRetimerModePreSet
(
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 serdesLane,
     IN MCD_SERDES_SPEED baudRate       /*  Retimer mode from the list             */
);

/**
* @internal mcdSetSerdesLaneCfgForRetimerModePostSet function
* @endinternal
 *
*/
MCD_STATUS mcdSetSerdesLaneCfgForRetimerModePostSet
(
     IN MCD_DEV_PTR         pDev,
     IN MCD_U16             serdesLane,
     IN MCD_SERDES_SPEED    baudRate,
     IN MCD_U16             clockSourceSerdes,
     IN MCD_BOOL            sendIcal,
     IN MCD_BOOL            switchClk

);

#ifndef MV_HWS_REDUCED_BUILD_EXT_CM3
/**
* @internal mcdSetRetimerMode function
* @endinternal
 *
*/
MCD_STATUS mcdSetRetimerMode
(
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 portNum,
     IN MCD_SERDES_SPEED baudRate
);
#endif
/**
* @internal mcdSerdesSetTxMux function
* @endinternal
 *
*/
 MCD_STATUS mcdSerdesSetTxMux
 (
     MCD_DEV_PTR         pDev,
     MCD_U8              localSerdes,
     MCD_SERDES_SPEED    baudRate,
     MCD_U8              clockSourceSerdes,
     MCD_BOOL            switchClk
 );

/**
* @internal mcdSerdesRealCdrStateGet function
* @endinternal
 *
* @param[out] lockedPtr                - locked or not.
*/
MCD_STATUS mcdSerdesRealCdrStateGet
(
    MCD_DEV_PTR         pDev,
    unsigned int        serdesNum,
    MCD_BOOL            *lockedPtr
);

/**
* @internal mcdSerdesDwellTimeSet function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesDwellTimeSet
(
    MCD_DEV_PTR         pDev,
    unsigned int        serdesNum,
    unsigned int        time
);

/**
* @internal mcdSerdesClockRegular function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - SERDES number
* @param[in] baudRate                 - serdes speed
*/
MCD_STATUS mcdSerdesClockRegular
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 serdesNum,
    IN MCD_SERDES_SPEED baudRate
);

/**
* @internal mcdSerdesNoPpmModeSet function
* @endinternal
 *
* @param[in] pDev
*                                      serdesNum - SERDES number.
* @param[in] baudRate                 - serdes speed.
*                                      refRxClk  - selects which of the 4 remote lanes RX clock is used
* @param[in] slice                    -  number [0..1]
* @param[in] enable                   - MCD_TRUE - start forwarding clock, MCD_FALSE - stop
*                                      forwarding.
*/
MCD_STATUS mcdSerdesNoPpmModeSet
(
    MCD_DEV_PTR         pDev,
    unsigned int        serdesNum,
    MCD_SERDES_SPEED    baudRate,
    unsigned int        refRxClk,
    MCD_U8              slice,
    MCD_BOOL            enable
);

/**
* @internal mcdSerdesCtleBiasUpdateDB function
* @endinternal
 *
* @param[in] pDev
*                                      serdesNum - SERDES number.
* @param[in] ctleBiasVal              - ctle bias value [0..1].
* @param[in] host_or_line             - host/line serdes.
*/
MCD_STATUS mcdSerdesCtleBiasUpdateDB
(
    MCD_DEV_PTR         pDev,
    unsigned int        serdesNum,
    MCD_U16             ctleBiasVal,
    MCD_U8              host_or_line
);

/*******************************************************************************
* mcdLaneSteeringOtherSideCfg
*
* DESCRIPTION:
*       bring up other slice SerDes's for lane steering
*
* INPUTS:
*       pDev
*       portMode - port mode
*       masterSlice  - active slice
*       baudRate  - SerDes baud rate
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       0  - on success
*       1  - on error
*
*******************************************************************************/
MCD_STATUS mcdLaneSteeringOtherSideCfg
(
    MCD_DEV_PTR    pDev,
    MCD_OP_MODE    portMode,
    MCD_MASTER_SLICE  masterSlice,
    MCD_SERDES_SPEED  baudRate
);

/*******************************************************************************
* mcdLaneSteeringAutoTuneStart
*
* DESCRIPTION:
*       start auto tune in lane steering order
*
* INPUTS:
*       pDev
*       slice - slice
*       masterSlice  - active slice
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       0  - on success
*       1  - on error
*
*******************************************************************************/
MCD_STATUS mcdLaneSteeringAutoTuneStart
(
    MCD_DEV_PTR    pDev,
    MCD_U16        slice,
    MCD_MASTER_SLICE  masterSlice
);
/*******************************************************************************
* mcdSerdesAutoTuneResult
*
* DESCRIPTION:
*       Per SERDES return the adapted tuning results
*       Can be run after create port.
*
* INPUTS:
*        pSerdesDev
*       serdesNum - physical serdes number
*
* OUTPUTS:
*       results - the adapted tuning results.
*
* RETURNS:
*       0  - on success
*       1  - on error
*
*******************************************************************************/
MCD_STATUS mcdSerdesAutoTuneResult
(
    MCD_DEV_PTR                 pDev,
    MCD_U8                      serdesNum,
    MCD_AUTO_TUNE_RESULTS       *results
);

/**
* @internal mcdSetSerdesDefaultCtleParameters function
* @endinternal
 *
*/
MCD_STATUS mcdSetSerdesDefaultCtleParameters
(
    unsigned int        portNum,
    MCD_OP_MODE         portMode
);

/**
* @internal mcdSetSetSerdesDefaultElectricalParameters function
* @endinternal
 *
*/
MCD_STATUS mcdSetSetSerdesDefaultElectricalParameters
(
    unsigned int        portNum,
    MCD_OP_MODE         portMode
);

/*******************************************************************************
* mcdSerdesCalCodeSet
*
* DESCRIPTION:
*       Set the calibration code(value) for Rx or Tx
*
* INPUTS:
*       pSerdesDev
*       serdesNum - SERDES number
*       mode      - True for Tx mode, False for Rx mode
*       therm     - Thermometer of VCO (0...0xFFFF)
*       bin       - bin of VCO (0...0xFFFF)
*
* OUTPUTS:
*       None.
*
* RETURNS:*       0  - on success
*       1  - on error
*
*******************************************************************************/
unsigned int mcdSerdesCalCodeSet
(
    MCD_DEV_PTR     pDev,
    int serdesNum,
    MCD_BOOL mode,
    int therm,
    int bin
);

/*******************************************************************************
* mcdSerdesCalCodeShift
*
* DESCRIPTION:
*       Shift the calcode according to the amount value
*
* INPUTS:
*       pDev
*       serdesNum - SERDES number
*       mode      - True for Tx mode, False for Rx mode
*       shift     - amount of cal-code shift
*       therm     - Thermometer of VCO  (0...0xFFFF)
*       bin       - bin of VCO  (0...0xFFFF)
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       0  - on success
*       1  - on error
*
*******************************************************************************/
unsigned int mcdSerdesCalCodeShift
(
    MCD_DEV_PTR     pDev,
    int serdesNum,
    MCD_BOOL mode,
    int shift,
    int therm,
    int bin
);

/*******************************************************************************
* mcdSerdesShiftCalc
*
* DESCRIPTION:
*       Calculate the Shift value according to the Temperature
*
* INPUTS:
*       pDev
*
* OUTPUTS:
*       shift - Shift value for calibration code in Rx and Tx
*
* RETURNS:
*       0  - on success
*       1  - on error
*
*******************************************************************************/
unsigned int mcdSerdesShiftCalc
(
   MCD_DEV_PTR     pDev,
   int             temperature,
   int             *shift
);

/**
* @internal mcdSerdesManualTxConfigGet function
* @endinternal
 *
* @param[out] configParams             - Manual Tx params structures:
*/
MCD_STATUS mcdSerdesManualTxConfigGet
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_MAN_TUNE_TX_CONFIG_DATA      *configParams
);

/**
* @internal mcdSerdesTxEnableGet function
* @endinternal
 *
* @retval 0                        - on success
* @retval 1                        - on error
*
* @note Disabling transmission of packets from SERDES causes to link down
*       of devices that are connected to the port.
*
* @param[out] enablePtr
*/
MCD_STATUS mcdSerdesTxEnableGet
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_BOOL                        *enablePtr
);

/**
* @internal mcdSerdesRxSignalCheck function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[out] rxSignal                 - Serdes is ready for Tuning or not
*/
MCD_STATUS mcdSerdesRxSignalCheck
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_AUTO_TUNE_STATUS            *rxSignal
);

/**
* @internal mcdSerdesDfeConfig function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[in] dfeMode                  - start/stop/iCal/pCal
*/
MCD_STATUS mcdSerdesDfeConfig
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_DFE_MODE                    dfeMode
);

/**
* @internal mcdSerdesTxAutoTuneStatusShort function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[out] txStatus                 - status of Tx-Training
*/
MCD_STATUS mcdSerdesTxAutoTuneStatusShort
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_AUTO_TUNE_STATUS            *txStatus
);

/**
* @internal mcdSerdesAutoTuneStart function
* @endinternal
 *
*/
MCD_STATUS mcdSerdesAutoTuneStart
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_BOOL                        rxTraining,
    MCD_BOOL                        txTraining
);

/**
* @internal mcdSerdesRxAutoTuneStart function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[in] rxTraining               - Rx Training (true/false)
*/
MCD_STATUS mcdSerdesRxAutoTuneStart
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_BOOL                        rxTraining
);

/**
* @internal mcdSerdesTxAutoTuneStart function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[in] txTraining               - Tx Training (true/false)
*/
MCD_STATUS mcdSerdesTxAutoTuneStart
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_BOOL                        txTraining
);

/**
* @internal mcdSerdesTxAutoTuneStop function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
*/
MCD_STATUS mcdSerdesTxAutoTuneStop
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum
);

/**
* @internal mcdSerdesSetTxMuxLaneSteering function
* @endinternal
 *
*/
 MCD_STATUS mcdSerdesSetTxMuxLaneSteering
 (
     MCD_DEV_PTR         pDev,
     MCD_U8              localSerdes,
     MCD_U8              otherSideSerdes,
     MCD_SERDES_SPEED    baudRate
 );

/**
* @internal mcdSerdesShiftSamplePoint function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[in] delay                    - set the  (0..31)
*/
MCD_STATUS mcdSerdesShiftSamplePoint
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          serdesNum,
    MCD_U32                         delay
);

/**
* @internal mcdSerdesArrayAutoTuneSet function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesArr                - collection of SERDESes to configure
* @param[in] numOfSerdes              - number of SERDESes to configure
* @param[in] trainingMode             - for value 0: set iCAL mode,
*                                      for value 1: set pCAL mode
*/
MCD_STATUS mcdSerdesArrayAutoTuneSet
(
    MCD_DEV_PTR                     pDev,
    MCD_U8                          *serdesArr,
    MCD_U8                          numOfSerdes,
    MCD_BOOL                        trainingMode
);

/**
* @internal mcdSerdesPolarityConfigImpl function
* @endinternal
 *
*/
int mcdSerdesPolarityConfigImpl
(
    MCD_DEV_PTR         pDev,
    unsigned int        serdesNum,
    unsigned int        invertTx,
    unsigned int        invertRx
);

/**
* @internal mcdSerdesSbmVoltageGet function
* @endinternal
 *
* @param[in] pSerdesDev
*                                      serdesNum   - physical serdes number
*                                      sensorAddr  - SBus address of the AVAGO_THERMAL_SENSOR
*/
int mcdSerdesSbmVoltageGet
(
    MCD_SER_DEV_PTR  pSerdesDev,
    unsigned int    serdesNum,
    unsigned int    sensorAddr,
    unsigned int    *voltage
);
#ifndef MV_HWS_REDUCED_BUILD_EXT_CM3
/**
* @internal mcdSerdesGetLoopbackInfo function
* @endinternal
 *
* @param[in] pDev
*                                      serdesNum - physical Serdes number
* @param[out] lbModePtr                - current loopback mode
*/
MCD_STATUS mcdSerdesGetLoopbackInfo
(
    IN MCD_DEV_PTR  pDev,
    IN MCD_U16      sAddr,
    IN MCD_U16      *lbModePtr
);
#endif /* MV_HWS_REDUCED_BUILD_EXT_CM3 */
/**
* @internal mcdSerdesDigitalReset function
* @endinternal
 *
* @param[in] pDev
*                                      serdesNum - serdes number
* @param[in] digitalReset             - digital Reset (On/Off)
*/
MCD_STATUS mcdSerdesDigitalReset
(
    MCD_DEV_PTR      pDev,
    unsigned int     serdesNum,
    MCD_BOOL         digitalReset
);

/**
* @internal mcdSerdesTestGenGet function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[out] txPatternPtr             - pattern to transmit ("Other" means any mode not
* @param[out] modePtr                  - test mode or normal
*/
MCD_STATUS mcdSerdesTestGenGet
(
    MCD_DEV_PTR              pDev,
    MCD_U16                  serdesNum,
    MCD_SERDES_TX_PATTERN    *txPatternPtr,
    MCD_SERDES_TEST_GEN_MODE *modePtr
);

/**
* @internal mcdSerdesTestGenStatus function
* @endinternal
 *
* @param[in] pDev
* @param[in] serdesNum                - physical serdes number
* @param[in] txPattern                - pattern to transmit
* @param[in] counterAccumulateMode    - Enable/Disable reset the accumulation of error counters
*/
MCD_STATUS mcdSerdesTestGenStatus
(
    MCD_DEV_PTR                  pDev,
    MCD_U16                      serdesNum,
    MCD_SERDES_TX_PATTERN        txPattern,
    MCD_BOOL                     counterAccumulateMode,
    MCD_SERDES_TEST_GEN_STATUS   *status
);



#endif /* MCD_ENABLE_SERDES_API */

#if C_LINKAGE
#if defined __cplusplus
}
#endif
#endif

#endif /* defined MCD_HWSERDESCNT_H */


