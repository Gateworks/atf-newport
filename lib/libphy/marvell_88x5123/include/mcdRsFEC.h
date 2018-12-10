/*******************************************************************************
Copyright (C) 2014-2016, Marvell International Ltd. and its affiliates
If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.
*******************************************************************************/

/************************************************************************
This file contains functions to configure RS-FEC and read RS-FEC status
************************************************************************/
#ifndef MCD_RSFEC_H
#define MCD_RSFEC_H

#if C_LINKAGE
#if defined __cplusplus
    extern "C" {
#endif
#endif

/*******************************************************************************
MCD_STATUS mcdSetRsFecControl
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 bypassIndicationEnable,
    IN MCD_U16 bypassCorrectionEnable
);

 Inputs:
    pDev       - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort   - MDIO port address, 0-31
    bypassIndicationEnable -
                 MCD_ENABLE:  FEC decoder does not indicate errors to the PCS;
                 MCD_DISABLE: FEC decoder indicates errors to the PCS
    bypassCorrectionEnable -
                 MCD_ENABLE:  FEC decoder performs detection without correction;
                 MCD_DISABLE: FEC decoder performs detection and correction

 Outputs:
    None

 Returns:
    MCD_OK if RS-FEC configuration is successful, MCD_FAIL if not

 Description:
    Enable or disable the RS-FEC bypass indication and bypass correction
    Register name: RS-FEC control register, Device 1 Register 0x00C8

 Side effects:
    None.

 Notes/Warnings:

*******************************************************************************/
MCD_STATUS mcdSetRsFecControl
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 bypassIndicationEnable,
    IN MCD_U16 bypassCorrectionEnable
);

/*******************************************************************************
MCD_STATUS mcdGetRsFecStatus
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    OUT MCD_U16 pcsLaneAlignment,
    OUT MCD_U16 fecLaneAlignment,
    OUT MCD_U16 latchedRsFecHighErr,
    OUT MCD_U16 currRsFecHighErr
);

 Inputs:
    pDev     - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31

 Outputs:
    pcsLaneAlignment
    fecLaneAlignment
    latchedRsFecHighErr
    currRsFecHighErr

 Returns:
    MCD_OK if RS-FEC status is successful, MCD_FAIL if not

 Description:
    Reads and returns the value of the RS-FEC status register
    Register name: RS-FEC status register, Device 1 Register 0x00C9

 Side effects:
    None.

 Notes/Warnings:

 *******************************************************************************/
MCD_STATUS mcdGetRsFecStatus
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    OUT MCD_U16 *pcsLaneAlignment,
    OUT MCD_U16 *fecLaneAlignment,
    OUT MCD_U16 *latchedRsFecHighErr,
    OUT MCD_U16 *currRsFecHighErr
);

/*******************************************************************************
MCD_STATUS mcdGetRsFecPCSAlignmentStatus
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 pcs_lane,
    OUT MCD_U16 *blockLocked,
    OUT MCD_U16 *laneAligned
);

 Inputs:
    pDev     - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    pcs_lane - PCS lane number, 0-19

 Outputs:
    blockLocked - RS-FEC PCS block lock status
    laneAligned - RS-FEC PCS lane alignment status

 Returns:
    MCD_OK if read RS-FEC PCS Aligment status is successful, MCD_FAIL if not

 Description:
    Get RS-FEC PCS Alignment status per lane.
    Register name: RS-FEC PCS Alignment status 1 - 3,
    Device 1, Register 0x0118, 0x0119, 0x011A, 0x011B

 Side effects:
    None.

 Notes/Warnings:

*******************************************************************************/
MCD_STATUS mcdGetRsFecPCSAlignmentStatus
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 pcs_lane,
    OUT MCD_U16 *blockLocked,
    OUT MCD_U16 *laneAligned
);

/*******************************************************************************
MCD_STATUS mcdGetRsFecPMALaneMapping
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    OUT MCD_U16 mapping[MCD_NUM_LANES]
);

 Inputs:
    pDev     - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31

 Outputs:
    mapping - RS-FEC PMA lane mapping data array
              mapping[0] = RS-FEC lane 0 mapped to PMA lane#
              mapping[1] = RS-FEC lane 1 mapped to PMA lane#
              mapping[2] = RS-FEC lane 2 mapped to PMA lane#
              mapping[3] = RS-FEC lane 3 mapped to PMA lane#

 Returns:
    MCD_OK if read RS-FEC PMA lane mapping is successful, MCD_FAIL if not

 Description:
    Get RS-FEC lane to PMA lane mapping
    Register name: RS-FEC lane mapping register, Device 1, Register 0x00CE

 Side effects:
    None.

 Notes/Warnings:

*******************************************************************************/
MCD_STATUS mcdGetRsFecPMALaneMapping
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    OUT MCD_U16 mapping[MCD_NUM_LANES]
);

/*******************************************************************************
MCD_STATUS mcdGetRsFecPCSLaneMapping
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 pcs_lane,
    OUT MCD_U16 *interface_lane
);

 Inputs:
    pDev     - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    pcs_lane - PCS lane number, 0-19

 Outputs:
    interface_lane - RS-FEC PCS lane mapping to interface lane #

 Returns:
    MCD_OK if read RS-FEC PMA lane mapping is successful, MCD_FAIL if not

 Description:
    Get RS-FEC PCS lane mapping received in service interface lane #
    Register name: RS-FEC PCS lane # mapping register
    Device 1, Register 0x00FA - 0x010D

 Side effects:
    None.

 Notes/Warnings:

 *******************************************************************************/
MCD_STATUS mcdGetRsFecPCSLaneMapping
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 pcs_lane,
    OUT MCD_U16 *interface_lane
);

/*******************************************************************************
MCD_STATUS mcdGetRsFecCorrectedCwCntr
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    OUT MCD_U32 *codeWordCounter
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31

 Outputs:
    codeWordCounter - RS-FEC corrected codewords counter

 Returns:
    MCD_OK if read RS-FEC corrected codewords counter is successful, MCD_FAIL if not

 Description:
    Get RS-FEC corrected codewords counter
    Register name: RS-FEC corrected codewords counter lower
                   RS-FEC corrected codewords counter upper
    Device 1, Register 0x00CA, 0x00CB

 Side effects:
    None.

 Notes/Warnings:

*******************************************************************************/
MCD_STATUS mcdGetRsFecCorrectedCwCntr
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    OUT MCD_U32 *codeWordCounter
);

/*******************************************************************************
MCD_STATUS mcdGetRsFecUnCorrectedCwCntr
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    OUT MCD_U32 *codeWordCounter
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31

 Outputs:
    codeWordCounter - RS-FEC uncorrected codewords counter

 Returns:
    MCD_OK if read RS-FEC uncorrected codewords counter is successful, MCD_FAIL if not

 Description:
    Get RS-FEC uncorrected codewords counter
    Register name: RS-FEC Uncorrected codewords counter lower
                   RS-FEC Uncorrected codewords counter upper
    Device 1, Register 0x00CC, 0x00CD

 Side effects:
    None.

 Notes/Warnings:

*******************************************************************************/
MCD_STATUS mcdGetRsFecUnCorrectedCwCntr
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    OUT MCD_U32 *codeWordCounter
);

/*******************************************************************************
MCD_STATUS mcdGetRsFecSymbolErrorCntr
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 lane,
    OUT MCD_U32 *errorCounter
);

 Inputs:
    pDev - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-7
    lane     - Lane number, 0-3

 Outputs:
    errorCounter - RS-FEC Symbol error counter

 Returns:
    MCD_OK if read symbol error counter is successful, MCD_FAIL if not

 Description:
    Get RS-FEC symbol error counter per lane
    Register name: RS-FEC symbol error counter lower lane #
                   RS-FEC symbol error counter upper lane #

 Side effects:
    None.

 Notes/Warnings:

*******************************************************************************/
MCD_STATUS mcdGetRsFecSymbolErrorCntr
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 lane,
    OUT MCD_U32 *errorCounter
);

/*******************************************************************************
MCD_STATUS mcdGetRsFecBipErrorCntr
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 pcs_lane,
    OUT MCD_U16 *errorCounter
);

 Inputs:
    pDev     - pointer to MCD_DEV initialized by mcdInitDriver() call
    mdioPort - MDIO port address, 0-31
    pcs_lane - PCS lane number, 0-19

 Outputs:
    errorCounter - RS-FEC BIP error counter per PCS lane

 Returns:
    MCD_OK if read BIP error counter is successful, MCD_FAIL if not

 Description:
    Get RS-FEC BIP error counter per PCS lane
    Register name: RS-FEC BIP error counter lane #
    Device 1, Register 0x00E6 - 0x00F9

 Side effects:
    None.

 Notes/Warnings:

*******************************************************************************/
MCD_STATUS mcdGetRsFecBipErrorCntr
(
    IN MCD_DEV_PTR pDev,
    IN MCD_U16 mdioPort,
    IN MCD_U16 pcs_lane,
    OUT MCD_U16 *errorCounter
);


#if C_LINKAGE
#if defined __cplusplus
}
#endif
#endif

#endif /* defined MCD_RSFEC_H */



