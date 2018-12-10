/*******************************************************************************
Copyright (C) 2014, 2015, Marvell International Ltd. and its affiliates
If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.
*******************************************************************************/

/********************************************************************
This file contains functions prototypes and global defines/data for
higher-level functions using MDIO access to perform resets, perform
queries of the phy, etc. that are necessary to control and read
status of the Marvell X5121/X5111/X2381/X5123 PHY.
********************************************************************/
#ifndef MCD_API_H
#define MCD_API_H
#if C_LINKAGE
#if defined __cplusplus
    extern "C" {
#endif
#endif

#define MCD_API_MAJOR_VERSION 4
#define MCD_API_MINOR_VERSION 6

/* This macro is handy for calling a function when you want to test the
   return value and return MCD_FAIL, if the function returned MCD_FAIL,
   otherwise continue */

#define ATTEMPT(xFuncToTry) {if(xFuncToTry != MCD_OK) \
                            {MCD_DBG_ERROR("ATTEMPT failed at %s:%u\n",__FUNCTION__,__LINE__); \
                            return MCD_FAIL;}}

/******************************************************************************
MCD_STATUS mcdSetModeSelection
(
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_OP_MODE portMode,
     IN MCD_BOOL autoNegAdvEnable,
     IN MCD_BOOL fecCorrect
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address 0...31 of mdioPort to be configured
    portMode - operational mode
    autoNegAdvEnable - Enable Auto Neg
        MCD_ADV_NONE (link will find no speeds in common and will not
                      complete AN)
        MCD_ADV_40KR4
        MCD_ADV_40CR4
        MCD_ADV_100KR4
        MCD_ADV_100CR4
        MCD_ADV_ALL_CR4
        MCD_ADV_ALL_KR4
        Note -only one speed may be advertise if defined by this function

    fecCorrect - FEC correct

 Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Set the Speed mode selection.

 Side effects:

 Notes/Warnings:

******************************************************************************/
MCD_STATUS mcdSetModeSelection
(
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_OP_MODE portMode,
     IN MCD_BOOL autoNegAdvEnable,
     IN MCD_FEC_TYPE fecCorrect
);

/******************************************************************************
MCD_STATUS mcdSetModeSelectionExt
(
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_OP_MODE portMode,
     IN MCD_BOOL autoNegAdvEnable,
     IN MCD_BOOL fecCorrect,
     IN MCD_MODE_CONFIG_PARAM_PTR configPtr
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address 0...7 of mdioPort to be configured
    portMode - operational mode
    autoNegAdvEnable - Enable Auto Neg if set to TRUE
    fecCorrect - FEC correct
    configPtr  - the structure contains fields to configure different parameters:
         noPpmMode          - should be set to TRUE if there is a need to propagate the line side Rx
                              clock through the device toward the host side, and use it as Tx clock -
                              this mode is used in synchronous ethernet applications in which the recovered clock selection
                              is done on the host side  and not directly from the device.
         electricalParamPtr - pointer to array of serdes electrical parameters structure:
                                       where
                                              typedef struct
                                              {
                                                  MCD_U8     rxPolarity;
                                                  MCD_U8     txPolarity;
                                                  MCD_U16    preCursor;
                                                  MCD_U16    attenuation;
                                                  MCD_U16    postCursor;

                                              }MCD_SERDES_CONFIG_DATA;
                        if electricalParamPtr is NULL - default parameters are set:
                                rxPolarity = 0
                                txPolarity = 0
                                precursor   - default per baudrate (see mcdSerdesTxRxTuneParamsArray)
                                attenuation - default per baudrate (see mcdSerdesTxRxTuneParamsArray)
                                postCursor  - default per baudrate (see mcdSerdesTxRxTuneParamsArray)


 Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Set the port mode parameters , including noPPM mode.

 Side effects:

 Notes/Warnings:

******************************************************************************/
MCD_STATUS mcdSetModeSelectionExt
(
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_OP_MODE portMode,
     IN MCD_BOOL autoNegAdvEnable,
     IN MCD_FEC_TYPE fecCorrect,
     IN MCD_MODE_CONFIG_PARAM_PTR configPtr
);

/******************************************************************************
MCD_STATUS mcdSetLaneSteering
 
 Description:
    Set port with laneSteering/Remap mode, support AP and none AP port. 
 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address 0...31 of mdioPort to be configured
    portMode - operational mode
    masterSlice - active slice
    laneSteeringMode - MCD_P100G_STEERING,
                       MCD_P40G_STEERING,
                       MCD_R4_P25G_STEERING,
                       MCD_R4_P10G_STEERING,
                       MCD_P100G_P40G_P10G_STEERING_AP,
                       MCD_R4_P25G_STEERING_AP,
                       MCD_R4_P10G_STEERING_AP,
                       MCD_G21L_NONE_STEERING,
                       MCD_G21L_P10G_NONE_STEERING_AP
    fecCorrect - FEC correct
    reducedRxTraining - bypass HF/BW values
 
 
 
 Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Notes/Warnings:

******************************************************************************/

MCD_STATUS mcdSetLaneSteering
(
    IN  MCD_DEV_PTR  pDev,
    IN  MCD_U16      mdioPort,
    IN  MCD_MASTER_SLICE  masterSlice,
    IN  MCD_LANE_STEERING_MODE  laneSteeringMode,
    IN  MCD_FEC_TYPE  fecCorrect,
    IN  MCD_BOOL      reducedRxTraining,
    IN MCD_MODE_CONFIG_PARAM_PTR configPtr
);

/******************************************************************************
MCD_STATUS mcdSetModeSelectionLaneSteering
(
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 portSrc[4],
     IN MCD_U16 portDst[4],
     IN MCD_U16 host_or_line,
     IN MCD_OP_MODE portMode,
     IN MCD_BOOL loopbackEnable,
     IN MCD_BOOL autoNegAdvEnable,
     IN MCD_FEC_TYPE fecCorrect
);

 Inputs:
     IN pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
     IN MCD_U16 mdioPortSrc        Source lane numbers, for example 4,5,6,7
     IN MCD_U16 mdioPortDst        Destination lane numbers, for example 7,6,5,4
     IN MCD_U16 host_or_line       Host or line
     IN MCD_OP_MODE portMode       Retimer mode from the list
     IN MCD_BOOL loopbackEnable    loopback on the host_or_line side
     IN MCD_BOOL autoNegAdvEnable  N/A
     IN MCD_FEC_TYPE fecCorrect    N/A

 Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Set the Speed mode selection.

 Side effects:

 Notes/Warnings:

******************************************************************************/
MCD_STATUS mcdSetModeSelectionLaneSteering
(
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 portSrc[4],
     IN MCD_U16 portDst[4],
     IN MCD_U16 host_or_line,
     IN MCD_OP_MODE portMode,
     IN MCD_BOOL loopbackEnable,
     IN MCD_BOOL autoNegAdvEnable,
     IN MCD_FEC_TYPE fecCorrect
);


/******************************************************************************
MCD_STATUS mcdSet100GLaneSteering
(
                  IN MCD_DEV_PTR pDev,
                  IN MCD_U16 srcPortNum,
                  IN MCD_PORT_CONFIG_PARAM_PTR configPtr
);

 Inputs:
     IN pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
     IN portNum         - port number - 0 or 4
     IN configPtr       - the structure includes the following fields:
            fec                - line and host FEC definition:
                                                     typedef enum
                                                     {
                                                             MCD_NO_FEC,                  No FEC
                                                             MCD_RS_FEC,                  RS FEC at both sides
                                                             MCD_FC_FEC,                  FC FEC at both sides
                                                             MCD_RS_FEC_HOST = 4,         RS FEC at host side
                                                             MCD_FC_FEC_HOST = 8,         FC FEC at host side
                                                             MCD_RS_FEC_LINE = 0x10,      RS FEC at line side
                                                             MCD_FC_FEC_LINE = 0x20       FC FEC at line side
                                                      } MCD_FEC_TYPE;

            electricalParamPtr - pointer to array of serdes electrical parameters structure


 Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Set the 100G Lane steering mode (symmetric sheme)

 Side effects:

 Notes/Warnings:

******************************************************************************/
MCD_STATUS mcdSet100GLaneSteering
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 srcPortNum,
    IN MCD_PORT_CONFIG_PARAMS_PTR configPtr,
    IN MCD_BOOL reducedRxTraining
)
;

/******************************************************************************
MCD_STATUS mcdSet40GLaneSteering
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 portNum,
    IN MCD_U16 laneRxDstArr[],
    IN MCD_U16 laneTxDstArr[],
    IN MCD_PORT_CONFIG_PARAM_PTR configPtr
);

 Inputs:
     IN pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
     IN portNum         - port number - 0 or 4
     IN laneRxDstArr[2] - Rx Destination lane numbers
                          for example 0,3,i.e lane0 Rx is remapped to lane0 and lane1 to lane3
     IN laneTxDstArr[2] - Tx  Destination lane numbers,
                          for example 1,2, i.e lane0 Tx is remapped to lane1 and lane1 to lane2
     IN configPtr       - the structure includes the following fields:
            fec                - line and host FEC definition:
                                                     typedef enum
                                                     {
                                                             MCD_NO_FEC,                  No FEC
                                                             MCD_RS_FEC,                  RS FEC at both sides
                                                             MCD_FC_FEC,                  FC FEC at both sides
                                                             MCD_RS_FEC_HOST = 4,         RS FEC at host side
                                                             MCD_FC_FEC_HOST = 8,         FC FEC at host side
                                                             MCD_RS_FEC_LINE = 0x10,      RS FEC at line side
                                                             MCD_FC_FEC_LINE = 0x20       FC FEC at line side
                                                      } MCD_FEC_TYPE;

            electricalParamPtr - pointer to array of serdes electrical parameters structure

 Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Set the 40G Lane steering mode (symmetric sheme)

 Side effects:

 Notes/Warnings:

******************************************************************************/
MCD_STATUS mcdSet40GLaneSteering
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 portNum,
    IN MCD_U16 laneRxDstArr[],
    IN MCD_U16 laneTxDstArr[],
    IN MCD_PORT_CONFIG_PARAMS_PTR configPtr,
    IN MCD_BOOL reducedRxTraining
);

/*******************************************************************
 Enabling speeds for autonegotiation to advertise
 Reading speeds enabled for autonegotation
 Enabling/Disabling/Restarting autonegoation
 *******************************************************************/
#define MCD_ADV_NONE           0x0000 /* No speeds to be advertised */
#define MCD_ADV_10KR           0x0001
#define MCD_ADV_40KR4          0x0002
#define MCD_ADV_40CR4          0x0004
#define MCD_ADV_100CR10        0x0008
#define MCD_ADV_100KP4         0x0010
#define MCD_ADV_100KR4         0x0020
#define MCD_ADV_100CR4         0x0040
#define MCD_ADV_25CKR          0x1000
#define MCD_ADV_ALL_CR4        (MCD_ADV_40CR4 | MCD_ADV_100CR4)
#define MCD_ADV_ALL_KR4        (MCD_ADV_40KR4 | MCD_ADV_100KR4)

/******************************************************************************
 MCD_STATUS mcdSetAutoNegAdvertisingSpeeds
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     IN MCD_U16 speed_bits
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being modified:
         MCD_HOST_SIDE
         MCD_LINE_SIDE
    speed_bits - speeds to be advertised during auto-negotiation. One of the following:
        MCD_ADV_NONE
        MCD_ADV_40KR4
        MCD_ADV_40CR4
        MCD_ADV_100KR4
        MCD_ADV_100CR4
        MCD_ADV_ALL_CR4
        MCD_ADV_ALL_KR4

 Outputs:
    None

 Returns:
    MCD_OK if action was successfully taken, MCD_FAIL if not (modes
    not supporting a particular speed combination or attempting
    to advertising CR and KR both will result in MCD_FAIL)

 Description:
    This function sets the auto-negotiation local advertising speeds only.
    It does not start the auto negotiation. To start auto-negotiation, function
    mcdAutoNegStart() needs to be called.

 Side effects:

 Notes/Warnings:

    Example:
******************************************************************************/
MCD_STATUS mcdSetAutoNegAdvertisingSpeeds
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    IN MCD_U16 speed_bits
);

/******************************************************************************
MCD_STATUS mcdGetAutoNegAdvertisingSpeeds
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    OUT MCD_U16 *speed_bits
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being read:
         MCD_HOST_SIDE
         MCD_LINE_SIDE

 Outputs:
    speed_bits - bits set according to which speeds are currently being
        advertised. One or more bits set according to the defines above
        in mcdSetAutoNegAdvertisingSpeeds().

 Returns:
    MCD_OK or MCD_FAIL, if query succeeded or failed

 Description:
    This function returns the speeds that have been advertised.

 Side effects:

 Notes/Warnings:
    Speeds advertised don't take effect until auto-negotiation is restarted.

******************************************************************************/
MCD_STATUS mcdGetAutoNegAdvertisingSpeeds
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    OUT MCD_U16 *speed_bits
);


/******************************************************************************
 MCD_STATUS mcdAutoNegStart
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     IN MCD_BOOL swReset
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being modified:
      MCD_HOST_SIDE
      MCD_LINE_SIDE

    swReset - changes to advertisement require a software reset to take
              effect, MCD_TRUE or MCD_FALSE indicates whether to perform
              the software reset

 Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, depending on if action was successful

 Description:
    Start or Restarts auto-negotiation. The bit is self-clearing. If the link is up,
    the link will drop and auto-negotiation will start again.

 Side effects:
    None.

 Notes/Warnings:
    Restarting auto-negotiation will enable the auto-negotiation if auto-negotiation is
    disabled.

    This function is important as it is necessary to start or restart auto-negotiation
    after changing many auto-negotiation settings before the changes will take
    effect.

******************************************************************************/
MCD_STATUS mcdAutoNegStart
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    IN MCD_BOOL swReset
);

/******************************************************************************
 MCD_STATUS mcdAutoNegDisable
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     IN MCD_BOOL swReset
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being modified:
      MCD_HOST_SIDE
      MCD_LINE_SIDE
    swReset - disable Auto-neg require a software reset to stop auto-neg
              in progress

 Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Turns off the enable auto-negotiation bit disabling auto-negotiation.

 Side effects:

 Notes/Warnings:
    Restart autonegation will not take effect if AN is disabled.

******************************************************************************/
MCD_STATUS mcdAutoNegDisable
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    IN MCD_BOOL swReset
);

/******************************************************************************
 MCD_STATUS mcdAutoNegEnable
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being modified:
      MCD_HOST_SIDE
      MCD_LINE_SIDE


 Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Re-enables auto-negotiation.

 Side effects:

 Notes/Warnings:
    Restart autonegation will not take effect if AN is disabled.

******************************************************************************/
MCD_STATUS mcdAutoNegEnable
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line
);
/*******************************************************************
 AP capabilities definitions
 *******************************************************************/
#define MCD_AN_1000BASE_KX                            0x0001
#define MCD_AN_10GBase_KX4                            0x0002
#define MCD_AN_10GBase_KR                             0x0004
#define MCD_AN_40GBASE_KR4                            0x0008
#define MCD_AN_40GBASE_CR4                            0x0010
#define MCD_AN_100GBASE_CR10                          0x0020
#define MCD_AN_100GBASE_KP4                           0x0040
#define MCD_AN_100GBASE_KR4                           0x0080
#define MCD_AN_100GBASE_CR4                           0x0100
#define MCD_AN_25GBase_KR1S                           0x0200
#define MCD_AN_25GBASE_KCR                            0x0400
#define MCD_AN_25GBase_KR1_CONSORTIUM                 0x0800
#define MCD_AN_25GBase_CR1_CONSORTIUM                 0x1000
#define MCD_AN_50GBase_KR2_CONSORTIUM                 0x2000
#define MCD_AN_50GBase_CR2_CONSORTIUM                 0x4000

/*******************************************************************
 Reading speed after autonegotation
 *******************************************************************/
#define MCD_NEG_NONE               0x0000 /* Auto-Neg not completed */
#define MCD_NEG_1000KX             0x0001
#define MCD_NEG_10KR               0x0009
#define MCD_NEG_40KR4              0x0021
#define MCD_NEG_40CR4              0x0041
#define MCD_NEG_100CR10            0x0101
#define MCD_NEG_100KP4             0x0201
#define MCD_NEG_100KR4             0x0401
#define MCD_NEG_100CR4             0x0801
#define MCD_NEG_25KR_CONSORTIUM    0x0011
#define MCD_NEG_25CR_CONSORTIUM    0x0081
#define MCD_NEG_25KRCS             0x1001
#define MCD_NEG_25KCR              0x2001
#define MCD_NEG_50KR_CONSORTIUM    0x4001
#define MCD_NEG_50CR_CONSORTIUM    0x8001


/******************************************************************************
MCD_STATUS mcdSetAPModeSelection
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U32 apLaneNum,
    IN MCD_U32 modesVector,
    IN MCD_BOOL fcPause,
    IN MCD_BOOL fcAsmDir,
    IN MCD_FEC_TYPE fecSup,
    IN MCD_FEC_TYPE fecReq,
    IN MCD_BOOL nonceDis
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address 0...7 of mdioPort to be configured
    MCD_U32 apLaneNum - lane number for AP protocol run
    MCD_U32 modesVector - defines port AP capabilities :
            MCD_AN_1000BASE_KX
            MCD_AN_10GBase_KX4
            MCD_AN_10GBase_KR
            MCD_AN_40GBASE_KR4
            MCD_AN_40GBASE_CR4
            MCD_AN_100GBASE_CR10
            MCD_AN_100GBASE_KP4
            MCD_AN_100GBASE_KR4
            MCD_AN_100GBASE_CR4
            MCD_AN_25GBase_KR1S
            MCD_AN_25GBASE_KCR
            MCD_AN_25GBase_KR1_CONSORTIUM
            MCD_AN_25GBase_CR1_CONSORTIUM
            MCD_AN_50GBase_KR2_CONSORTIUM
            MCD_AN_50GBase_CR2_CONSORTIUM

    MCD_BOOL fcPause                         - TRUE if FC is enabled
    MCD_BOOL fcAsmDir                        - TRUE if assymetric FC is enabled
    MCD_FEC_TYPE fecSup                      - supported FEC
    MCD_FEC_TYPE fecReq                      - required FEC
    MCD_BOOL nonceDis                        - TRUE if in loopback
    MCD_CONFIG_SERDES_AP_PARAM_PTR configPtr - pointer to the structure that defines
                                               serdes electrical params (Tx and Rx polarity)
                                               if  configPtr == NULL - Tx and Rx polarity set to 0

    MCD_BOOL apEnable - if TRUE - starts the AP
Outputs:
    None

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Set port AP mode with referenced parameters - not applicable for retimer mode.

 Side effects:

 Notes/Warnings:

******************************************************************************/
MCD_STATUS mcdSetAPModeSelection
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 portNum,
    IN MCD_U32 apLaneNum,
    IN MCD_U32 modesVector,
    IN MCD_BOOL fcPause,
    IN MCD_BOOL fcAsmDir,
    IN MCD_FEC_TYPE fecSup,
    IN MCD_FEC_TYPE fecReq,
    IN MCD_BOOL nonceDis,
    IN MCD_CONFIG_SERDES_AP_PARAM_PTR configPtr,
    IN MCD_BOOL apEnable
);

/******************************************************************************
 MCD_STATUS mcdAutoNegCheckComplete
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     IN MCD_BOOL set_speed,
     OUT MCD_U16 *speed
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-7
    host_or_line - which interface is being checked:
      MCD_HOST_SIDE
      MCD_LINE_SIDE
    set_speed - TRUE:  Set the opposite side speed with AN result.
                FALSE: Don't set speed

 Outputs:
    speed - the result of auto-negotiation. One of the following:
        MCD_NEG_NONE (AN still in process or disabled)
        MCD_NEG_10KR
        MCD_NEG_40KR4
        MCD_NEG_40CR4
        MCD_NEG_100CR10
        MCD_NEG_100KP4
        MCD_NEG_100KR4
        MCD_NEG_100CR4
        MCD_NEG_25KR_CONSORTIUM
        MCD_NEG_25CR_CONSORTIUM
        MCD_NEG_25KRCS
        MCD_NEG_25KCR
        MCD_NEG_50KR_CONSORTIUM
        MCD_NEG_50CR_CONSORTIUM

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Set the Host side speed/FEC with AN result if set-speed is TRUE
    This function returns the auto-negotiated speed upon completion.
    If the training/AN is not finished, it returns MTD_NEG_NONE
    for the speed.

 Side effects:

 Notes/Warnings:

******************************************************************************/
MCD_STATUS mcdAutoNegCheckComplete
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    IN MCD_BOOL set_speed,
    OUT MCD_U16 *speed
);

/******************************************************************************
 MCD_STATUS mcdAutoNegCheckCompleteExt
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     IN MCD_BOOL set_speed,
     IN MCD_MODE_CONFIG_PARAM_PTR configPtr,
     OUT MCD_U16 *speed
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-7
    host_or_line - which interface is being checked:
      MCD_HOST_SIDE
      MCD_LINE_SIDE
    set_speed - TRUE:  Set the opposite side speed with AN result.
                FALSE: Don't set speed
    configPtr  - the structure contains fields to configure different parameters:
         noPpmMode          - should be set to TRUE if there is a need to propagate the line side Rx
                              clock through the device toward the host side, and use it as Tx clock -
                              this mode is used in synchronous ethernet applications in which the recovered clock selection
                              is done on the host side  and not directly from the device.
         electricalParamPtr - pointer to array of serdes electrical parameters structure:
                                       where
                                              typedef struct
                                              {
                                                  MCD_U8     rxPolarity;
                                                  MCD_U8     txPolarity;
                                                  MCD_U16    preCursor;
                                                  MCD_U16    attenuation;
                                                  MCD_U16    postCursor;

                                              }MCD_SERDES_CONFIG_DATA;
                        if electricalParamPtr is NULL - default parameters are set:

 Outputs:
    speed - the result of auto-negotiation. One of the following:
        MCD_NEG_NONE (AN still in process or disabled)
        MCD_NEG_10KR
        MCD_NEG_40KR4
        MCD_NEG_40CR4
        MCD_NEG_100CR10
        MCD_NEG_100KP4
        MCD_NEG_100KR4
        MCD_NEG_100CR4
        MCD_NEG_25KR_CONSORTIUM
        MCD_NEG_25CR_CONSORTIUM
        MCD_NEG_25KRCS
        MCD_NEG_25KCR
        MCD_NEG_50KR_CONSORTIUM
        MCD_NEG_50CR_CONSORTIUM

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not

 Description:
    Set the Host side speed/FEC with AN result, noPPM mode and electrical parameters if set-speed is TRUE.
    This function returns the auto-negotiated speed upon completion.
    If the training/AN is not finished, it returns MTD_NEG_NONE
    for the speed.

 Side effects:

 Notes/Warnings:

******************************************************************************/
MCD_STATUS mcdAutoNegCheckCompleteExt
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    IN MCD_BOOL set_speed,
    IN MCD_MODE_CONFIG_PARAM_PTR configPtr,
    OUT MCD_U16 *speed
);

#define MCD_LINK_UP   1
#define MCD_LINK_DOWN 0
typedef union
{
    /*********** PCS MODES **********************/
    struct
    {
        MCD_U16 hostCurrent; /* per mdioPort */
        MCD_U16 hostLatched;
        MCD_U16 lineCurrent;
        MCD_U16 lineLatched;
    } P100_40_status; /* P100L/S/C/K and P40L/C/K */

    /********* REPEATER MODES ********************/
    struct
    {
        MCD_U16 hostCurrent[8]; /* per lane */
        MCD_U16 lineCurrent[8]; /* per lane */
    } R25_10_status; /* R25L/C, R10L/K */

    struct
    {
        MCD_U16 host_P0[4];
        MCD_U16 host_P1[4];
        MCD_U16 line_P0[4];
        MCD_U16 line_P1[4];
        MCD_U16 hostCurrent[8]; /* per lane */
        MCD_U16 lineCurrent[8]; /* per lane */
    } R100_40_status; /* R100L/C, R40L/C */

    /********* MLG MODES *************************/
#if 0 /* TBD */
    struct
    {
    }
#endif
} DETAILED_STATUS_TYPE;

/******************************************************************************
 MCD_STATUS mcdCheckLinkStatus
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     OUT MCD_U16 *currentStatus,
     OUT MCD_U16 *latchedStatus,
     OUT DETAILED_STATUS_TYPE *statusDetail
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31

 Outputs:
    currentStatus - overall current status of link. MCD_LINK_UP if
        both line and host is up, MCD_LINK_DOWN if any component of
        host or line is down
    latchedStatus - latched status since last time mcdCheckLinkStatus()
        was called. Not available in repeater modes. Available only in
        PCS modes and MLG modes. This is the combination of all latched
        bits on both host and line side giving an overall latched
        indication if link dropped since last read. MCD_LINK_UP
        if no link drop was seen, MCD_LINK_DOWN if any link drop
        was seen.
        Note: This status does not apply to the repeater mode.
    statusDetail - gives details of status for all components links
        on both host and line side. For repeater modes, this is
        the combined serdes status of all lanes on host and line
        side. For PCS modes this is the combined PCS status for host
        and line side. The structure returned depends on the
        mode of operation. See DETAILED_STATUS_TYPE for details.

 Returns:
    MCD_OK or MCD_FAIL, if action was successful or not.

 Description:
    Depending on the mode of operation of this mdioPort, looks at all
    components of the link on both host and line side and returns an
    overall indication if the link is up or down currently in
    "currentStatus". Returns an indication if the link dropped since
    the last time mcdCheckLinkStatus() was called for those
    modes that have a latched status (PCS modes and MLG modes).

    Also returns more details in "statusDetail" in case host or
    line side details for specific lanes are desired. See
    DETAILED_STATUS_TYPE for the different structures that will be
    returned for different modes of operation.

 Side effects:
    Calling this function will clear any latched bits that are
    a component of the link status.

 Notes/Warnings:
    None

******************************************************************************/
MCD_STATUS mcdCheckLinkStatus
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    OUT MCD_U16 *currentStatus,
    OUT MCD_U16 *latchedStatus,
    OUT DETAILED_STATUS_TYPE *statusDetail
);

/******************************************************************************
 MCD_STATUS mcdGetPcsFaultStatus
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     OUT MCD_U16 *currentTxFaultStatus,
     OUT MCD_U16 *currentRxFaultStatus,
     OUT MCD_U16 *latchedTxFaultStatus,
     OUT MCD_U16 *latchedRxFaultStatus
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being read:
       MCD_HOST_SIDE
       MCD_LINE_SIDE


 Outputs:
    currentTxFaultStatus - the value of the Tx Fault Status
        on the second read of the status register (the current status
        after clearing the latch bit)
    currentRxFaultStatus - the value of the Rx Fault Status
        on the second read of the status register (the current status
        after clearing the latch bit)
    latchedTxFaultStatus - the value of the Tx Fault Status
        on the first read of the status register (the value of
        the latched bit since the last read)
    latchedRxFaultStatus - the value of the Rx Fault Status
        on the first read of the status register (the value of
        the latched bit since the last read)

 Returns:
    MCD_OK if query was successful, MCD_FAIL if not. Will return
    MCD_FAIL if the operating mode is not set properly or
    the device is not initialized for this mode of operation.

 Description:
    This function is to be called in any of the 40G or 100G PCS
    modes to check the Tx/Rx fault bits.

    Based on the current operating mode, it reads either the 40G
    or 100G Host/Line PCS Status 2 register twice and returns the value
    of the Tx/Rx fault bits. It returns the first read in the
    "latched" version and the second read in the "current" version.

    For 100G Host Side:
        4.8.11 Tx Fault
        4.8.10 Rx Fault

    For 100G Line Side:
        3.8.11 Tx Fault
        3.8.10 Rx Fault

    For 40G Host Side:
        4.1008.11 Tx Fault
        4.1008.10 Rx Fault

    For 40G Line Side:
        3.1008.11 Tx Fault
        4.1008.10 Rx Fault

 Side effects:
    None.

 Notes/Warnings:
    Clears the latch status of those registers being read.

    Speed must be resolved if using AN and/or port must be configured using
    40G or 100G PCS mode, otherwise an error is returned.

******************************************************************************/
MCD_STATUS mcdGetPcsFaultStatus
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    OUT MCD_U16 *currentTxFaultStatus,
    OUT MCD_U16 *currentRxFaultStatus,
    OUT MCD_U16 *latchedTxFaultStatus,
    OUT MCD_U16 *latchedRxFaultStatus
);

/*****************************************************************************
Enabling and Checking Interrupts and Real-Time Status 40GBASE-R4 Bit
Definitions (for first field in interrupt/status registers)
NOTE: the second field in the functions are not used for 40GBASE-R4 only
for 100GBASE-R4.
*****************************************************************************/
#define MCD_40G_LF_TXD_BIT       (1<<11)   /* Bit definitions for 40GBASE-R4 Interrupt Enable Register */
#define MCD_40G_LF_RXD_BIT       (1<<10)   /* and 40GBASE-R4 Interrupt Status Register */
#define MCD_40G_LN_ALIGN_BIT     (1<<9)
#define MCD_40G_TX_LN_ERRCNT_BIT (1<<8)
#define MCD_40G_JIT0_LOCK_BIT    (1<<7)
#define MCD_40G_JIT_LF_BIT       (1<<6)
#define MCD_40G_LINK_BIT         (1<<5)
#define MCD_40G_HI_BER_BIT       (1<<4)
#define MCD_40G_LN3_BLK_LK_BIT   (1<<3)
#define MCD_40G_LN2_BLK_LK_BIT   (1<<2)
#define MCD_40G_LN1_BLK_LK_BIT   (1<<1)
#define MCD_40G_LN0_BLK_LK_BIT   (1<<0)

#define MCD_40G_LN3_LOCK_BIT      (1<<15)  /* Bit definitions for 40GBASE-R4 Real Time Status Register */
#define MCD_40G_LN2_LOCK_BIT      (1<<14)
#define MCD_40G_LN1_LOCK_BIT      (1<<13)
#define MCD_40G_LN0_LOCK_BIT      (1<<12)
#define MCD_40G_LF_TXD_RT_BIT     (1<<11)
#define MCD_40G_LF_RXD_RT_BIT     (1<<10)
#define MCD_40G_LN_ALIGN_RT_BIT   (1<<9)
/* NOT USED (1<<8) */
#define MCD_40G_JIT0_LOCK_RT_BIT  (1<<7)
#define MCD_40G_JIT_LF_RT_BIT     (1<<6)
#define MCD_40G_LINK_RT_BIT       (1<<5)
#define MCD_40G_HI_BER_RT_BIT     (1<<4)
#define MCD_40G_LN3_BLK_LK_RT_BIT (1<<3)
#define MCD_40G_LN2_BLK_LK_RT_BIT (1<<2)
#define MCD_40G_LN1_BLK_LK_RT_BIT (1<<1)
#define MCD_40G_LN0_BLK_LK_RT_BIT (1<<0)

/*****************************************************************************
Enabling and Checking Interrupts and Real-Time Status 100GBASE-R4 Bit
Definitions Flags 1 and Flags 2
*****************************************************************************/
#define MCD_100G_RXIFO_FULL_BIT   (1<<15)  /* Bit definitions for 100GBASE-R4 Interrupt Enable/Status */
#define MCD_100G_RXFIFO_EMPTY_BIT (1<<14)  /* and real-time Status Registers 1 */
#define MCD_100G_TXFIFO_OF_BIT    (1<<13)
#define MCD_100G_TXFIFO_UF_BIT    (1<<12)
#define MCD_100G_LF_TXD_BIT       (1<<11)
#define MCD_100G_LF_RXD_BIT       (1<<10)
/* NOT USED (1<<9) */
/* NOT USED (1<<8) */
#define MCD_100G_PKTCK_CRCERR_BIT (1<<7)
/* NOT USED (1<<6) */
#define MCD_100G_LINK_BIT         (1<<5)
#define MCD_100G_HI_BER_BIT       (1<<4)
#define MCD_100G_LN3_BLK_LK_BIT   (1<<3)
#define MCD_100G_LN2_BLK_LK_BIT   (1<<2)
#define MCD_100G_LN1_BLK_LK_BIT   (1<<1)
#define MCD_100G_LN0_BLK_LK_BIT   (1<<0)

#define MCD_100G_LN19_BLK_LK_BIT  (1<<15)  /* Bit definitions for 100GBASE-R4 Interrupt Enable/Status */
#define MCD_100G_LN18_BLK_LK_BIT  (1<<14)  /* and real-time Status Registers 2 */
#define MCD_100G_LN17_BLK_LK_BIT  (1<<13)
#define MCD_100G_LN16_BLK_LK_BIT  (1<<12)
#define MCD_100G_LN15_BLK_LK_BIT  (1<<11)
#define MCD_100G_LN14_BLK_LK_BIT  (1<<10)
#define MCD_100G_LN13_BLK_LK_BIT  (1<<9)
#define MCD_100G_LN12_BLK_LK_BIT  (1<<8)
#define MCD_100G_LN11_BLK_LK_BIT  (1<<7)
#define MCD_100G_LN10_BLK_LK_BIT  (1<<6)
#define MCD_100G_LN9_BLK_LK_BIT   (1<<5)
#define MCD_100G_LN8_BLK_LK_BIT   (1<<4)
#define MCD_100G_LN7_BLK_LK_BIT   (1<<3)
#define MCD_100G_LN6_BLK_LK_BIT   (1<<2)
#define MCD_100G_LN5_BLK_LK_BIT   (1<<1)
#define MCD_100G_LN4_BLK_LK_BIT   (1<<0)

/*****************************************************************************
Enabling and Checking Interrupts and Real-Time Status Combined Functions for
40GBR and 100GBR
*****************************************************************************/


/******************************************************************************
 MCD_STATUS mcdSetInterruptEnable
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     IN MCD_U16 intrEnableFlags1,
     IN MCD_U16 intrEnableFlags2  only valid for 100GBR
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being read:
       MCD_HOST_SIDE
       MCD_LINE_SIDE
    intrEnableFlags1 - For each flag a 1 enables the interrupt and a
        0 disables the interrupt. Flags are defined above.
        Flag values depend on operating mode (40G or 100G)
    intrEnableFlags2 - For each flag a 1 enables the interrupt and a
        0 disables the interrupt. Flags are defined above.
        Flag values depend on operating mode (this flag is only for
        100G mode, ignored for 40G mode)

 Outputs:
    None

 Returns:
    MCD_OK if change was successful, MCD_FAIL if not. Will return
    MCD_FAIL if the operating mode is not set properly or
    the device is not initialized for 40G/100G mode of operation.

 Description:
    This function can be called after the port has been initialized for
    any of the 40GR and 100GR modes of operation to enable interrupts.

    Note that the second flag is only for 100G mode. It's ignored
    if the port is in 40GR mode.

 Side effects:
    None.

 Notes/Warnings:
    The bit flags can be OR together to enable multiple interrupts.
    For example:
        (MCD_100G_RXIFO_FULL_BIT | MCD_100G_RXFIFO_EMPTY_BIT) for
    intrEnableFlags1 to enable these two interrupts on 100GR mode.

******************************************************************************/
MCD_STATUS mcdSetInterruptEnable
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    IN MCD_U16 intrEnableFlags1,
    IN MCD_U16 intrEnableFlags2 /* only valid for 100GBR */
);

/******************************************************************************
 MCD_STATUS mcdGetInterruptEnable
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     OUT MCD_U16 *intrEnableFlags1,
     OUT MCD_U16 *intrEnableFlags2  only valid for 100GBR
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being read:
       MCD_HOST_SIDE
       MCD_LINE_SIDE

 Outputs:
    intrEnableFlags1 - For each flag a 1 indicates the interrupt is
        enabled and a 0 indicates the interrupt is disabled.
        Flags are defined above.
        Flag values depend on operating mode (40G or 100G)
    intrEnableFlags2 - For each flag a 1 indicates the interrupt is
        enabled and a 0 indicates the interrupt is disabled.
        Flags are defined above.
        Flag values depend on operating mode (this flag is only for
        100G mode, ignored for 40G mode)

 Returns:
    MCD_OK if query was successful, MCD_FAIL if not. Will return
    MCD_FAIL if the operating mode is not set properly or
    the device is not initialized for 40G/100G mode of operation.

 Description:
    This function can be called after the port has been initialized for
    any of the 40GR and 100GR modes of operation to read what
    interrupts are enabled.

    Note that the second flag is only for 100G mode. It's invalid
    if the port is in 40GR mode.

 Side effects:
    None.

 Notes/Warnings:
    None

******************************************************************************/
MCD_STATUS mcdGetInterruptEnable
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    OUT MCD_U16 *intrEnableFlags1,
    OUT MCD_U16 *intrEnableFlags2 /* only valid for 100GBR */
);

/******************************************************************************
 MCD_STATUS mcdGetInterruptStatus
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     OUT MCD_U16 *latchedStatusFlags1,
     OUT MCD_U16 *currentStatusFlags1,
     OUT MCD_U16 *latchedStatusFlags2,  only valid for 100GBR
     OUT MCD_U16 *currentStatusFlags2,  only valid for 100GBR
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being read:
       MCD_HOST_SIDE
       MCD_LINE_SIDE

 Outputs:
    latchedStatusFlags1 - value of the first read of the
        interrupt status register. Bit values are defined above.
    currentStatusFlags1 - value of the second read of the
        interrupt status register. Bit values are defined above.
    latchedStatusFlags2 - value of the first read of the
        interrupt status register 2. Only valid in 100GR mode.
        Bit values are defined above.
    currentStatusFlags2 - value of the second read of the
        interrupt status register 2.
        Bit values are defined above. Only valid in 100GR mode.


 Returns:
    MCD_OK if query was successful, MCD_FAIL if not. Will return
    MCD_FAIL if the operating mode is not set properly or
    the device is not initialized for 40G/100G mode of operation.

 Description:
    This function can be called after the port has been initialized for
    any of the 40GR and 100GR modes of operation to read what
    interrupts have occurred. The first read value is passed in the
    latched parameter, while the second read value is passed in the
    current read parameter.

    Note that the second flag (#2) is only for 100G mode. It's invalid
    if the port is in 40GR mode.

 Side effects:
    None.

 Notes/Warnings:
    If the interrupt has gone away, calling this function will clear the
    latched bit.

******************************************************************************/
MCD_STATUS mcdGetInterruptStatus
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    OUT MCD_U16 *latchedStatusFlags1,
    OUT MCD_U16 *currentStatusFlags1,
    OUT MCD_U16 *latchedStatusFlags2, /* only valid for 100GBR */
    OUT MCD_U16 *currentStatusFlags2 /* only valid for 100GBR */
);


/******************************************************************************
 MCD_STATUS mcdSquelchRxClockSet
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_RX_CLOCK_CTRL_TYPE pinNum
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-7
    pinNum - select the pin to control clock squelch :
                MCD_RCLK_CTRL0,MCD_RCLK_CTRL1 or MCD_RCLK_CTRL2
 Outputs:
    None

 Returns:
    MCD_OK if change was successful, MCD_FAIL if not. Will return
    MCD_FAIL if the parameters are not valid or if link on line side is not UP

 Description:
    The function defines which pin should be set to squelch RX clock
    clears interrupt on all port lanes and enables
    link status change interrupt for the referenced port

 Side effects:
    None.

 Notes/Warnings:
 This function can be called after the port has been initialized and link is UP

******************************************************************************/
MCD_STATUS mcdSquelchRxClockSet
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U32 laneNum,
    IN MCD_RX_CLOCK_CTRL_TYPE pinNum
);

/******************************************************************************
 MCD_STATUS mcdGetRealtimeStatus
 (
     IN MCD_DEV_PTR pDev,
     IN MCD_U16 mdioPort,
     IN MCD_U16 host_or_line,
     OUT MCD_U16 *rtStatusFlags1,
     OUT MCD_U16 *rtStatusFlags2  only valid for 100GBR
 );

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-31
    host_or_line - which interface is being read:
       MCD_HOST_SIDE
       MCD_LINE_SIDE

 Outputs:
    rtStatusFlags1 - value of reading the real-time status register
        Bit values are defined above.
    rtStatusFlags2 - value of reading the real-time status register
        #2. Bit values are defined above. Only valid in 100GR mode.


 Returns:
    MCD_OK if query was successful, MCD_FAIL if not. Will return
    MCD_FAIL if the operating mode is not set properly or
    the device is not initialized for 40G/100G mode of operation.

 Description:
    This function can be called after the port has been initialized for
    any of the 40GR and 100GR modes of operation to read what
    the current status is.

    Note that the second flag (#2) is only for 100G mode. It's invalid
    if the port is in 40GR mode.

 Side effects:
    None.

 Notes/Warnings:
    None.

******************************************************************************/
MCD_STATUS mcdGetRealtimeStatus
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 host_or_line,
    OUT MCD_U16 *rtStatusFlags1,
    OUT MCD_U16 *rtStatusFlags2 /* only valid for 100GBR */
);

/******************************************************************************
MCD_STATUS mcdSetInterruptEnableEx
(
    IN  MCD_DEV_PTR pDev,
    IN  MCD_U16 mdioPort,
    IN  MCD_U16 host_or_line,
    IN  MCD_U16 interruptRegisterNum,
    IN  MCD_U16 intrEnableFlags
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-7
    host_or_line - which interface is being read:
        MCD_HOST_SIDE
        MCD_LINE_SIDE
    interruptRegisterNum - number of interrupt related register 0..14
        described in Functional Specification.
    intrEnableFlags - For each flag a 1 enables the interrupt and a
        0 disables the interrupt. Flags described in Functional Specification.

 Outputs:
    None

 Returns:
    MCD_OK if change was successful, MCD_FAIL if not.

 Description:
        This function can be called after the port has been initialized.

 Side effects:
    None.

 Notes/Warnings:
    The bit flags can be OR together to enable multiple interrupts.

******************************************************************************/
MCD_STATUS mcdSetInterruptEnableEx
(
    IN  MCD_DEV_PTR pDev,
    IN  MCD_U16 mdioPort,
    IN  MCD_U16 host_or_line,
    IN  MCD_U16 interruptRegisterNum, /*0..14*/
    IN  MCD_U16 intrEnableFlags
);

/******************************************************************************
MCD_STATUS mcdGetInterruptEnableEx
(
    IN  MCD_DEV_PTR pDev,
    IN  MCD_U16 mdioPort,
    IN  MCD_U16 host_or_line,
    IN  MCD_U16 interruptRegisterNum,
    OUT MCD_U16 *intrEnableFlags
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-7
    host_or_line - which interface is being read:
        MCD_HOST_SIDE
        MCD_LINE_SIDE
    interruptRegisterNum - number of interrupt related register 0..14
        described in Functional Specification.

 Outputs:
        intrEnableFlags - For each flag a 1 enables the interrupt and a
            0 disables the interrupt. Flags described in Functional Specification.

 Returns:
    MCD_OK if change was successful, MCD_FAIL if not.

 Description:
        This function can be called after the port has been initialized.

 Side effects:
    None.

 Notes/Warnings:
    None

******************************************************************************/
MCD_STATUS mcdGetInterruptEnableEx
(
    IN  MCD_DEV_PTR pDev,
    IN  MCD_U16 mdioPort,
    IN  MCD_U16 host_or_line,
    IN  MCD_U16 interruptRegisterNum, /*0..14*/
    OUT MCD_U16 *intrEnableFlags
);

/******************************************************************************
MCD_STATUS mcdGetInterruptStatusEx
(
    IN  MCD_DEV_PTR pDev,
    IN  MCD_U16 mdioPort,
    IN  MCD_U16 host_or_line,
    IN  MCD_BOOL toClearStatus,
    IN  MCD_U16 interruptRegisterNum,
    OUT MCD_U16 *interruptStatusFlags
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-7
    host_or_line - which interface is being read:
        MCD_HOST_SIDE
        MCD_LINE_SIDE
    toClearStatus - MCD_TRUE - clear interrupt status register after reading,
                    MCD_FALSE - leave interrupt status register as was before reading.
    interruptRegisterNum - number of interrupt related register 0..14
        described in Functional Specification.

 Outputs:
        interruptStatusFlags - For each flag a 1 means interrupt occurred and a
        0 means the interrupt not occurred. Flags described in Functional Specification.

 Returns:
    MCD_OK if change was successful, MCD_FAIL if not.

 Description:
        This function can be called after the port has been initialized.

 Side effects:
    None.

 Notes/Warnings:
    None

******************************************************************************/
MCD_STATUS mcdGetInterruptStatusEx
(
    IN  MCD_DEV_PTR pDev,
    IN  MCD_U16 mdioPort,
    IN  MCD_U16 host_or_line,
    IN  MCD_BOOL toClearStatus,       /* to clear after read */
    IN  MCD_U16 interruptRegisterNum, /*0..14*/
    OUT MCD_U16 *interruptStatusFlags
);

#define MCD_DOORBELL_EVENT_PORT_0_802_3_AP_E  0x00000001
#define MCD_DOORBELL_EVENT_PORT_1_802_3_AP_E  0x00000002
#define MCD_DOORBELL_EVENT_PORT_2_802_3_AP_E  0x00000004
#define MCD_DOORBELL_EVENT_PORT_3_802_3_AP_E  0x00000008
#define MCD_DOORBELL_EVENT_PORT_4_802_3_AP_E  0x00000010
#define MCD_DOORBELL_EVENT_PORT_5_802_3_AP_E  0x00000020
#define MCD_DOORBELL_EVENT_PORT_6_802_3_AP_E  0x00000040
#define MCD_DOORBELL_EVENT_PORT_7_802_3_AP_E  0x00000080

#define MCD_DOORBELL_EVENT_PORT_0_STATUS_CHANGE_E   0x00010000
#define MCD_DOORBELL_EVENT_PORT_1_STATUS_CHANGE_E   0x00020000
#define MCD_DOORBELL_EVENT_PORT_2_STATUS_CHANGE_E   0x00040000
#define MCD_DOORBELL_EVENT_PORT_3_STATUS_CHANGE_E   0x00080000
#define MCD_DOORBELL_EVENT_PORT_4_STATUS_CHANGE_E   0x00100000
#define MCD_DOORBELL_EVENT_PORT_5_STATUS_CHANGE_E   0x00200000
#define MCD_DOORBELL_EVENT_PORT_6_STATUS_CHANGE_E   0x00400000
#define MCD_DOORBELL_EVENT_PORT_7_STATUS_CHANGE_E   0x00800000

/**
* @internal mcdGetCm3ToHostSignal function
* @endinternal
 *
*/
MCD_STATUS mcdGetCm3ToHostSignal
(
    IN   MCD_DEV_PTR pDev,
    OUT  MCD_U32     *signalCodePtr
);


/******************************************************************************
MCD_STATUS mcdGetRealtimeStatusEx
(
    IN  MCD_DEV_PTR pDev,
    IN  MCD_U16 mdioPort,
    IN  MCD_U16 host_or_line,
    IN  MCD_U16 interruptRegisterNum,
    OUT MCD_U16 *intrRtStatusFlags
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-7
    host_or_line - which interface is being read:
        MCD_HOST_SIDE
        MCD_LINE_SIDE
    interruptRegisterNum - number of interrupt related register 0..14
        described in Functional Specification.

 Outputs:
        intrRtStatusFlags - For each flag a 1 means interrupt occurred and a
            0 means the interrupt not occurred. Flags described in Functional Specification.

 Returns:
    MCD_OK if change was successful, MCD_FAIL if not.

 Description:
        This function can be called after the port has been initialized.

 Side effects:
    None.

 Notes/Warnings:
    None

******************************************************************************/
MCD_STATUS mcdGetRealtimeStatusEx
(
    IN  MCD_DEV_PTR pDev,
    IN  MCD_U16 mdioPort,
    IN  MCD_U16 host_or_line,
    IN  MCD_U16 interruptRegisterNum, /*0..14*/
    OUT MCD_U16 *intrRtStatusFlags
);

/******************************************************************************
 MCD_STATUS mcdSyncEClkConfig
(
    IN MCD_DEV_PTR        pDev,
    IN MCD_U16            mdioPort,
    IN MCD_U32            laneNum,
    IN MCD_RCLK_DIV_VAL   divider,
    IN MCD_BOOL           squelchEnable,
    OUT MCD_RCLK_OUT_PIN  outPin
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdLoadDriver() call
    mdioPort - MDIO port address, 0-7.
    laneNum - SerDes lane number, 0-3.
    divider - selects the division value of the recovered clock.
    squelchEnable - MCD_TRUE - enable Rx squelch,
                    MCD_FALSE - ignore Rx squelch.

 Outputs:
    outPin - configures the pin to output the selected divided recvored
             clock.

 Returns:
    MCD_OK if successful, MCD_FAIL if not. Will return
    MCD_FAIL if the parameters are not valid or if link on line side is not UP

 Description:
    The function defines which pin should output the recovered clock and if squelch
    is enable, call the API mcdSquelchRxClockSet.

 Side effects:
    None.

 Notes/Warnings:
 This function can be called after the port has been initialized and link is UP

******************************************************************************/
MCD_STATUS mcdSyncEClkConfig
(
    IN  MCD_DEV_PTR         pDev,
    IN  MCD_U16             mdioPort,
    IN  MCD_U32             laneNum,
    IN  MCD_RCLK_DIV_VAL    divider,
    IN  MCD_BOOL            squelchEnable,
    IN MCD_RCLK_OUT_PIN    outPin
);

/**
* @internal mcdSetApManualRxParmaeters function
* @endinternal
 *
* @retval MCD_OK                   - on success
* @retval MCD_FAIL                 - on error
*/
MCD_STATUS mcdSetApManualRxParameters
(
    IN  MCD_DEV_PTR  pDev,
    IN  MCD_U16      mdioPort,
    IN  MCD_U16      laneNum,
    IN  MCD_PORT_AP_SERDES_RX_CONFIG *rxOverrideParamsPtr
);

/**
* @internal mcdSetApManualTxParmaeters function
* @endinternal
 *
* @retval MCD_OK                   - on success
* @retval MCD_FAIL                 - on fail
* @param[in] pDev                     - physical device number
* @param[in] mdioPort                 - portNum
* @param[in] laneNum                  - number of SERDES lane of port (0-> lane 0,...,3 -> lane 3 etc.)
* @param[in] txOverrideParamsPtr      - (pointer to) parameters data
*/
MCD_STATUS mcdSetApManualTxParameters
(
    IN  MCD_DEV_PTR  pDev,
    IN  MCD_U16      mdioPort,
    IN  MCD_U16      laneNum,
    IN  MCD_PORT_AP_SERDES_TX_CONFIG *txOverrideParamsPtr
);

#if C_LINKAGE
#if defined __cplusplus
}
#endif
#endif

#endif /* defined MCD_API_H */


