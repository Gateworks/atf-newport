CGX related support in T9x firmware
===================================

## 1. Overview

This doc provides details on high level design of CGX implementation in ATF 
including  SFP/PHY management and interface data structures used for ATF,
U-Boot, UEFI and kernel communication.

> **NOTES**:  
> DT properties are mainly needed by ATF configure the ports accordingly. 
> There is no DT dependency enforced > on kernel. 
> If required, ATF can trim the DT properties if it doesn’t need to be passed to OS. 
> Hence no restriction on whether OS boots with ACPI ON/OFF…

---

## 2. Device Tree

Same as CN8XXX platforms, CGX nodes with all interfaces defined as sub nodes 
and PHY or SFP/QSFP slot info to be present.

Number of VFs/MSIX property for each sub nodes defined to be used by RVU driver:

```c
// Example:
"num-rvu-vfs"
"num-msix-vec"
```

Along with this, auto negotiation property, MAC/PHY mode to be added to DT whichwill be used by ATF to configure CGX.

For AN to be disabled, the sub node should have following property 
`“octeontx,disable-autonegotiation"`.
> **Note**: this is applicable only for SGMII/QSGMII modes.

FEC configuration for each LMAC (Applicable for 10G/25G/40G/50G/100G/USXGMII modes)
`octeontx,fec-type = <N>` where N can be 0, 1 or 2. If this attribute is not specified, 
default FEC type specific to mode will be configured.
> **Note**: If user wants to disable FEC, specify the value as 0 in the above property

```c
/* enum declaration for FEC */
typedef enum cgx_fec_type {
        CGX_FEC_NONE,
        CGX_FEC_BASE_R,			/* BASE-R/FIRECODE FEC */
        CGX_FEC_RS				/* RS-FEC */
} fec_type_t;
```

For an LMAC that's connected to a PHY that supports two different modulation
types on the line-side:  `octeontx,phy-mod-type = <N>` where N can be 0 (meaning
NRZ) or 1 (meaning PAM4).  The default is NRZ.

> **Note**: On PHYs that support only one modulation type,
`octeontx,phy-mod-type = <N>` has no effect.

```c
/* PHY modulation types */
typedef enum phy_mod_type {
        PHY_MOD_TYPE_NRZ,
        PHY_MOD_TYPE_PAM4,
} phy_mod_type;
```

**SFP (example slot info):**

```c
sfp_1: sfp-slot@1 {
             compatible = "sfp-slot";
             /* format : gpio_controller phandle, pin, flags
              * flags : polarity inversion
              */
             rx_los = <&gpio0 4 0>;
             detect = <&gpio0 5 0>;
             tx_fault = <&gpio0 6 0>;
             tx_disable = <&gpio0 7 0>;
             eeprom = <&sfp1_eeprom>;
             /* power in mW supported by board for SFP
              * levels : 1000, 1500, 2000mW)
              */
             max_power = <1500>;
};
```

**QSFP (example slot info):**

```c
qsfp_1: qsfp-slot@1 {
           compatible = "qsfp-slot";
           /* format : gpio_controller phandle, pin, flags
            * flags : polarity inversion
            */
           mod_sel = <&gpio1 4 0>;
           mod_present = <&gpio1 5 0>;
           reset = <&gpio_15_0 48 0>; /* direct connection to SoC */
           lowpow_mode = <&gpio1 6 0>;
           int = <&gpio1 7 0>;
           eeprom = <&qsfp1_eeprom>;
           /* power in mW supported by board for QSFP
            * levels : 1500, 2000, 2500, 3500, 4000, 4500, 5000 mW)
            */
           max_power = <3500>;
};
```

> **NOTE**:  
> Slot info need to be mapped to LMAC nodes based on the board design.  
> For example, on particular CN9X board, QLM7/3 has QSFP slot, 
> all 100G/40G/25G/10G LMAC nodes in CGX1 needs to have handle to QSFP slot info
>
> ```c
> cgx@0 { /* QLM3 or QLM 7 */
>   ethernetA29: 100g@00 {
>       reg = <0>;
>       num-rvu-vfs = <8>;
>       num-msix-vec = <210>;
>       qsfp-slot = <&qsfp_20>;
>       phy-handle = <&>;
>   };
> };

**GPIO expanders info (example):**
```c
gpio0: gpio-i2c@0 {
    #gpio-cells = <2>;
    compatible = "nxp_pca8574";
    gpio-controller;
    reg = <0x22>;
    ngpios = <8>;
};
```

**I2C switch info (example):**

```c
switch@e0 {
    #address-cells = <1>;
    #size-cells = <0>;
    compatible = "nxp_pca9548";
    reg = <0xE0>;
    i2c@0 {
        #address-cells = <1>;
        #size-cells = <0>;
        reg = <0>;  
        sfp0_eeprom: eeprom@50 {
            compatible = "atmel,24c01";
            reg = <0x50>;
        };  

    sfp_0: sfp-slot@0 {
    };

    i2c@1 {
        #address-cells = <1>;
        #size-cells = <0>;
        reg = <1>;
    };
};
```

PHY should have the details of which MDIO bus it is connected to and its 
address and the compatible string should include the PHY name and/or the 
CLAUSE string (if the PHY complaints with generic C22/C45 standard)
PHY (example PHY info):

```c
mdio0@87e005003800 {
    sgmii00: sgmii00 {
        reg = <0x0>;
        compatible = "marvell,88e1240", "ethernet-phy-ieee802.3-c22";
    };
};
```

And, the corresponding LMAC node depending on the board design, should have
the handle to PHY:

```c
ethernetA0: sgmii@00 {
    reg = <0>;
    num-rvu-vfs = <8>;
    num-msix-vec = <210>;
    phy-handle = <&sgmii00>;
};
```

LED example: **TODO**
> **Note**: 
> unlike CN8xxx, BDK will not trim the DT based on the QLM mode as each lane 
> can support different modes for CN9xxx and mode change is supported 
> dynamically. CN9xxx DT should not have “qlm-mode” and “local-mac-address” 
> property in the CGX sub-nodes.

---

## 3. BOARD CONFIG/USER OPTIONS

These are to be configured in board DT/via SETUP menu in BDK.

 Item            | Comments                        | Status
-----------------|---------------------------------|------
QLM MODE         |                                 | Done
QLM FREQUENCY    |                                 | Done
FEC              |                                 | ?
BINDINGS         |(If Splitter is connected or so) | ?
Device Settings  | (Required for GSERN tuning)     | ?

---

## 4. ATF CGX INTERFACE

### 4.1. BOOT TIME

---

#### 4.1.1. DT PARSER

Based on the QLM LANE mode configuration by BDK (via `GSERNX_LANEX_SCRATCHX CSR`)
mode is obtained for each lane of QLM. It gets mapped against CGX instance and
checked against the OS DT to map the info with each LMAC of CGX.

```c
typedef union
{
    uint64_t u;
    struct {
        uint16_t baud_mhz;        /* Baudrate of the lane in MHz */
        cavm_qlm_modes_t mode: 8; /* Mode of the lane */
        uint32_t flags: 8;        /* Mode flags */
        uint32_t pcie: 1;         /* Mode is PCIE RC or endpoint, see flags */
        uint32_t sata: 1;         /* Mode is SATA */
        uint32_t cgx: 1;          /* Mode is supported by CGX, see mode for details */
        uint32_t reserved: 29;    /* Reserved for future use */
    } s;
} cavm_qlm_state_lane_t;
```

Additional properties of LMAC configuration like PHY info, SFP/QSFP module info, 
RVU info, etc. are parsed from Linux DT specific to each board and updated in 
global board config structure per LMAC.

---

#### 4.1.2. GSERN

**TODO**

---

#### 4.1.3. CGX HW INIT

During PCI scan, CGX init callback will be called for each CGX.

This callback initializes the LMACs based on the info retrieved from board config 
structure. Programs the LMAC count for CGX and LMAC type for each LMAC.

Also, one time HW initialization based on LMAC type is done like configuring 
threshold, min/max packet size etc.

LMACs will not be enabled at this point. PCS will be in reset.

2 timers are started and run periodically. Timer #1  to check for requests and
process them. Timer #2 to interface with PHY or SFP/QSFP module to periodically
to poll for link status

> **Note**: 
> CGX device is hidden from non-secure world if the particular CGX is not 
> configured for any mode in BDK. 

---

#### 4.1.4. INTERRUPT ENABLE


MSIX vector provided for SW purpose (37th vector in CGX) is dummy and
interrupt cannot be triggered. 

For firmware to notify kernel, `CGXX_CMRX_INT(0..2)(0..3)` – Overflow bit (bit 1)
is chosen as communication method for T9X PASS 1.0 
(until [http://mcbuggin.caveonetworks.com/bug/33218] is resolved)

---

### 4.2. RUN TIME SERVICES

Interface from/to kernel, U-Boot and UEFI:  
`CGX SCRATCHX()` registers implemented only for SW purpose. 
> **NOTE**: 
> Please check the SCRATCHX CSRs section of the doc for interface details 
> which will be referred in the below section.

---

#### 4.2.1. INTERFACE FROM U-BOOT/UEFI/KERNEL

`CGXX_CMRX_SCRATCHX[cgx][lmac][1]` reserved for this purpose for each LMAC.  
Refer to [cgx_scratchx1](#cgx_scratchx1) structure.

> **Note**s:
> - User can post the requests only if the “ack” bit is clear 
>   (and default ownership for command register is with non-secure SW).
>
> - After writing the command ID, non-secure SW should set the ownership 
>   to `CGX_OWN_FIRMWARE` for firmware to process the command.
>
> - Firmware will set the ownership back to `CGX_OWN_NON_SECURE_SW` 
>   after processing the command
>
> - User should clear the interrupt for any command response along with 
>   clearing ack/releasing the ownership

---

##### 4.2.1.1. GET FW VER

Parameters to be sent:

- REQUEST ID – `CGX_CMD_GET_FW_VER`
- Major/Minor version number returned

---

##### 4.2.1.2. GET MAC ADDR

Parameters to be sent:

- REQUEST ID – `CGX_CMD_GET_MAC_ADDR`
- If MAC address is not configured, zeros are returned.

---

##### 4.2.1.3. LINK BRING UP 

Initiated when ethernet interfaces are brought up
Parameters to be sent:

- REQUEST ID – `CGX_CMD_LINK_UP`
- As part of request processing, ATF will bring up the link
  as per the sequence documented in HRM

Now, poll timer will start to check for link status periodically. 
Even though ATF polls periodically for the link status, info will be shared 
with non-secure SW only when there is change in link status.

Return the link state info (by write to `CGXX_CMRX_SCRATCHX[cgx][lmac][0]`)  
Refer to [cgx_scratchx0](#cgx_scratchx0) structure.

If the PHY link is not up, `CGX_ERR_PHY_LINK_DOWN` will be returned.

Any errors will be set in the `CGXX_CMRX_SCRATCHX[cgx][lmac][0]`  
Refer to [cgx_scratchx0](#cgx_scratchx0) structure.

**Code Flow**:

- CGX HW initialization is done based on LMAC type
- If PHY is present : 
  - Check the link status
  - If PHY link is up, CGX configured based on the link status
  - If PHY link is down, CMD_SUCCESS is returned with the link status as down
(In both the cases, link_enable is set for the poll timer to poll for the link)

- If PHY is not present: 
  - default link status is updated and CGX is configured

- If SFP/QSFP slot is present:
  - Read the module status
  - If module is present and EEPROM data is available, check the module capabilities against user options.
  - If matches, configure CGX
  - SFP/QSFP flow chart to be followed, Refer to [this.](https://caviumnetworks.sharepoint.com/:u:/r/sites/ic-engplatform/_layouts/15/doc2.aspx?sourcedoc=%7B738fdb57-b29c-477e-a8f9-c529e382e8a0%7D&action=default&uid=%7B738FDB57-B29C-477E-A8F9-C529E382E8A0%7D&ListItemId=705&ListId=%7BC63A6416-EB1D-45C6-BF4A-F59B8DA8FC4E%7D&odsp=1&env=prod)

- If CGX configuration succeeds, current link status will be set

- If CGX configuration fails, both error type and current link status will be set

> **NOTE**:  
> Link bring up request will enable TX/RX for packet transfer. As per HRM,
> NIX should be configured before enabling TX/RX as packets should not arrive
> at NIX before configuration. So, user should send LINK UP request only after
> NIX is fully configured.

---

##### 4.2.1.4. LINK BRING DOWN

Initiated when ethernet interfaces are brought down 
Parameters to be sent : 

- REQUEST ID - `CGX_CMD_LINK_BRING_DOWN`

As part of request processing, ATF will bring down the link 
(sequence followed in HRM). 

Timer #2 will stop periodically polling for the link status of this LMAC until
 next LINK UP is sent

---

##### 4.2.1.5. INTERNAL LOOPBACK

Parameters to be sent : 

- REQUEST ID - `CGX_CMD_INTERNAL_LBK`
- cmd_args.enable = 1 to enable loopback

or

- cmd_args.enable = 0 to disable loopback

---

##### 4.2.1.6. EXTERNAL LOOPBACK

Parameters to be sent:

- REQUEST ID - `CGX_CMD_EXTERNAL_LBK`
- cmd_args.enable = 1 to enable loopback

or

- cmd_args.enable = 0 to disable loopback

> **NOTE**:  
> To enable loopback, sequence should be request ID for loopback followed
> by request ID to bring the link up.

---

##### 4.2.1.7. LINK CHANGE

Timer #2 polling periodically for the link status notifies Timer #1
if there is any change in link status.

Timer #1 will notify kernel about the change in link status via interrupt
when this command is processed. Event type will be set as `CGX_EVT_ASYNC` and
event ID will be `CGX_CMD_LINK_STATE_CHANGE`. 
New link status will be updated in lnk_sts.

**Code Flow**:

- If there is a change in link status reported by PHY or SFP/QSFP module, 
  CGX is reconfigured based on LMAC type before notifying kernel 
  via asynchronous event
- If link is up and CGX configuration succeeds,
  - Stat: `CGX_STAT_SUCCESS`
  - Lnk_sts : updated with current status
  - Err_type: `CGX_ERR_NONE`
- If link is down, and CGX configuration fails, 
  - Stat : `CGX_STAT_FAIL`
  - Lnk_sts : updated with current status
  - Err_type: CGX HW error type

---

##### 4.2.1.8. INTF SHUTDOWN

When U-Boot or UEFI boots to kernel, U-Boot or UEFI should send the below
command to ATF - `CGX_CMD_INTF_SHUTDOWN`. 

This command should be sent when CGX driver is unloaded in kernel as well.

As result:

- ATF brings down the link for active links 
  (for which ever LMAC, LINK UP request was sent)
- Clears the `SCRATCHX CSR`s (but only sets the ack bit and users should
  not check for any response for this command as the status bits are cleared).
- Also clear the interrupt when releasing the ownership

---

##### 4.2.1.9. FEC CHANGE

In addition to FEC type allowed to be mentioned in Linux DT, User is allowed
to change the FEC type dynamically from kernel via ethtool.
This command - CGX_CMD_SET_FEC needs to be sent to ATF with the required FEC
type from kernel upon execution of ethtool commands.

As result, ATF:
- Validates if FEC change is allowed for the particular mode and if the FEC
type requested matches with the expected PCS type. If not, returns error.
- Link status is updated with the new FEC if CGX is successfully configured.
- Status is updated with CGX_STAT_FAIL or CGX_STAT_SUCCESS info

Optionally, CGX_CMD_GET_SUPPORTED_FEC command can be sent to ATF to know the
supported FEC types. But, by default, supported FEC types are updated in
shared FW data memory

---

##### 4.2.1.10. MODE CHANGE
This command supports changing the ethernet port's current speed to
different speed. Following are the parameters expected:

/* command argument to be passed for cmd ID - CGX_CMD_MODE_CHANGE */
struct cgx_mode_change_args {
        uint64_t reserved1:8;
        uint64_t speed:4; /* cgx_link_speed enum */
        uint64_t duplex:1; /* 0 - full duplex, 1 - half duplex */
        uint64_t an:1;  /* 0 - disable AN, 1 - enable AN */
        uint64_t port:8; /* device port */
        uint64_t mode:42;
};

ATF generates interrupt as a response to this command,
  - evt_type : `CGX_EVT_CMD_RESP`
  - cmd ID : CGX_CMD_MODE_CHANGE
  - cmd status: Either `CGX_STAT_SUCCESS`/`CGX_STAT_FAIL`

If the command status is successful, ATF updates the link
status also in the response structure

NOTE: Based on current QLM configuration, ATF decides whether to allow the change.

---

#### 4.2.2. INTERFACE FROM ATF to U-BOOT/UEFI/KERNEL

`CGXX_CMRX_SCRATCHX[cgx][lmac][0]`/`CGXX_CMRX_SCRATCHX[cgx][lmac][1]` reserved
for this purpose for each LMAC, refer to [cgx_scratchx0](#cgx_scratchx0) and
[cgx_scratchx1](#cgx_scratchx1) structures.
 
- ATF will write the following status for any command submitted in scratchx0:
  - evt_type : `CGX_EVT_CMD_RESP`
  - cmd ID : same command ID posted by user
  - cmd status: Either `CGX_STAT_SUCCESS`/`CGX_STAT_FAIL`

    - If status is returned as `CGX_STAT_FAIL`, 
      reason/error type will be set in `cgx_err_sts_s` struct
      > **Note**: In case of LINK UP/DOWN both error type and response
      > will be updated in `cgx_lnk_sts_s` struct

    - If status is returned as `CGX_CMD_SUCCESS`, based on cmd ID, 
      specific responses will be set
      - `GET_FW_VER` - `cgx_ver_s` struct
      - `GET_MAC_ADDR` - `cgx_mac_addr_s` struct

- In addition, ATF will generate asynchronous event without any commands
  being posted. This is based on PHY or SFP/QSFP module link status read
  by periodic polling.
  - evt_type : `CGX_EVT_ASYNC`
  - evt ID : `CGX_EVT_LINK_CHANGE`
  - status : `CGX_STAT_SUCCESS`/`CGX_STAT_FAIL`
  
  - If status is `CGX_STAT_FAIL`, error_type and link status
    will set in `cgx_lnk_sts_s` struct

  - If status is `CGX_STAT_SUCCESS`, error_type will be zero and 
    current status will be set in `cgx_lnk_sts_s` struct


- Finally sets the ack bit and triggers interrupt

- Interrupt is triggered by setting overflow bit of 
  `CAVM_CGXX_CMRX_INT_W1S(0..2)(0..3)` 

> **Note**: 
> User is responsible for clearing the interrupt upon reception of interrupt.
> Also, to differentiate between HW triggered genuine overflow interrupt or
> firmware triggered event notification interrupt, user needs to read 
> the ack bit of `SCRATCHX(0)` register.
> If this bit it set to 1, it is triggered by firmware and needs
> appropriate action as discussed above.

---

### 4.3. SCRATCHX CSRs

`CGXX_CMRX_SCRATCHX(0..2)(0..3)(0..1)` SCRATCHX CSRs added for SW purpose on
OCTEON TX2 FAMILY of SoCs. These CSRs are primarily used as the communication
method between ATF and non-secure SW.

`CGXX_CMRX_SCRATCHX(CGX)(LMAC)(0)` – STATUS REGISTER
`CGXX_CMRX_SCRATCHX(CGX)(LMAC)(1)` – COMMAND REGISTER

Please refer to [this.]( http://cadmzgitt1.caveonetworks.com/cgit/cgit.cgi/thunder/boot/atf.git/tree/plat/cavium/octeontx2/include/cavm_cgx_intf.h) for the interface definitions. 
Current version of the interface – v1.0

---

## 5. SFP MANAGEMENT

For network ports with SFP/QSFP slots, before CGX is configured, module capabilities are to be known.  Mostly, the module EEPROM will be connected via TWSI bus and since TWSI operations are slow, all TWSI accesses for SFP/QSFP slots are offloaded to MCP (MIPS based Management Control Processor).

### 5.1. SHARED MEMORY

ATF and MCP use shared memory to communicate with each other for SFP management.
This SM is fixed memory in non-secure region which will include the data structures
required to save the SFP module status, EEPROM data (256 bytes) and device tree info 
to access the TWSI bus, I2C multiplexer/switch, GPIO expanders etc.

**SM data structure:**

```c
#define SFP_MAX_EEPROM_SIZE     0x100
typedef struct sfp_shared_data {
        sfp_slot_info_t sfp_slot;         /* Module info from DT based on board */
        sfp_context_t sfp_ctx;            /* State machine for SFP/QSFP state */
        uint8_t buf[SFP_MAX_EEPROM_SIZE]; /* SFP/QSFP EEPROM data */
        sfp_async_req sfp_req;            /* Post Req to MCP sfp_req_id_t */
        sfp_async_rsp sfp_rsp;            /* Receive Response from MCP for request sent */
} sfp_shared_data_t;
```

> **Note**:
> This data structure is separately maintained for each LMAC.
> If the LMAC doesn’t have SFP/QSFP module connected,
> this SM doesn’t have any impact.

**Context structure in SM:**

```c
/* Data structures to be shared between AP and MCP */
typedef struct sfp_context {
        uint8_t mod_status;          /* transceiver state, sfp_mod_state_info_t*/
        uint8_t data_status;	/* transceiver data status, sfp_data_state_info_t*/
        uint8_t lock;           /* lock to prevent conflict of access between AP and MCP */
        /* SFF-8419 provides details of these pins */
        uint8_t mod_abs;        /* state of mod_abs pin for SFP */
        uint8_t tx_disable;     /* state of tx_disable pin for SFP */
        uint8_t tx_fault;       /* state of tx_fault pin for SFP */
        uint8_t rx_los;         /* state of rx_los pin for SFP */
        /* SFF-8438 provides details of these pins */
        uint8_t select;         /* state of Select pin for QSFP */
        uint8_t reset;          /* state of reset pin for QSFP */
        uint8_t lp_mode;        /* state of LPmode pin for QSFP */
        uint8_t interrupt;      /* state of Interrupt pin for QSFP */
        uint8_t mod_prs;        /* state of Mod present pin for QSFP */
        uint8_t reserved;       /* for alignment */
} sfp_context_t;
```

**State Machine:**

```c
/* State machine maintain for SFP/QSFP management for communication
 * between AP & MCP
 * sfp_mod_state_info: Module status
 * sfp_data_state_info: EEPROM status
 */
typedef enum sfp_mod_state_info {
        /* Module disconnected */
        SFP_MOD_STATE_ABSENT = 0,
        /* Module connected */
        SFP_MOD_STATE_PRESENT,
        /* Other state */
        SFP_MOD_STATE_OTHER /* Change in other states like Rx LOS or Tx disable */
} sfp_mod_state_info_t;

typedef enum sfp_data_state_info {
        SFP_DATA_STATE_IDLE = 0,
/* MCP to update it after reading the EEPROM data */        SFP_DATA_STATE_READ_EEPROM,
          /* MCP to update it after validate checksum of EEPROM data */
           SFP_DATA_STATE_EEPROM_VALID,
          /* MCP read the EEPROM data and data is not valid. MCP should read the
         * EEPROM again (5 times) before setting this mode 
         */
        SFP_DATA_STATE_EEPROM_NVAL,
} sfp_data_state_info_t;
```

**Code Flow:**

- Initial mod_state will be module not present.

- MCP to first check the module availability, and if module is present,
  updates the state to `MOD_PRS`.

- If module is present, MCP to update the state as `READ_EEPROM` before reading
  the data from EEPROM and once the data is read from EEPROM and checksum is
  validated, state is updated to `EEPROM_VALID`

- The above steps (2 & 3) to be continued when periodically polling 
  for the status (every 1 ms).

- If the module is not present, state should be maintained at `MOD_ABS`.

- During periodic polling, if there is a change is module status 
  (either from MOD connected->disconnected or disconnected->connected),
  state should be updated accordingly.

- AP, upon request from user to bring the LINK up, checks for the current state.
  If the current data state is `EEPROM_VALID`, reads the EEPROM data,
  parses the info and obtains the cable type.

  - AP obtains the Auto-Negotiation (AN), Forward Error Correction (FEC),
    max speed capabilities and validate it against user options.

  - Using these options, configure CGX to bring the LINK up.

  - If the LINK is up, timer #2 running to obtain the status periodically
    by reading the module status.

  - If there is a change in module status (disconnected->connected),

    - READ the EEPROM capabilities

    - Case 1: If the link was never brought up and link request was 
      already sent,  try to bring the link up

    - Case 2: If the link was already active earlier, handled it as a link change.

  - If there is a change in module status (connected->disconnected), 
    send a asynchronous notification to user about this.

- If the module state is not present/data state is not `EEPROM_VALID`,
  AP will retry for 5 times to check the status before returning the error
  to user (At this point, link will not be brought up).
  But later, link will be brought up when the module status is obtained
  by poll timer #2 (see d.ii)

---

## 5.2. AP->SCP

ATF when initializing SCMI driver, initializes SM with info parsed from DT
related to accessing SFP/QSFP slots and sends `SCMI_CAVM_SFP_CONFIG_MSG`
to SCP which is passed to MCP.

---

## 5.3. AP->MCP

When bringing the CGX link up, some of the SFP/QSFP pins might need to be
toggled or some info needs to be read from EEPROM. This need to be asynchronous.
Will be using SM and use the below request & response data structures.
MCP to create a separate task to handle this request which will be of 
high priority compared to other tasks.

```c
/* Example Request IDs. FIXME: this is not complete list */
typedef enum sfp_async_req_id {
        SFP_REQ_NONE = 0,
        SFP_REQ_TX_ENABLE,      /* Turn ON transmitter */
        SFP_REQ_TX_DISABLE,     /* Turn OFF transmitter */
        SFP_REQ_SET_POWER_MODE, /* Set to High/Low Power Mode */
        SFP_REQ_GET_POWER_MODE, /* Get power mode status */
        SFP_REQ_WRITE_GPIO,     /* To toggle on one of SFP/QSFP GPIO pins */
        SFP_REQ_READ_GPIO,      /* Optional */
        SFP_REQ_READ_BYTE,      /* Optional: if required to read one of the bytes in EEPROM */
} sfp_req_id_t;

typedef struct sfp_async_req {
        uint8_t req_id;		/* sfp_req_id_t */
        /* Ex: which GPIO pin to toggle, which page/byte of EEPROM to read */
        uint32_t req_args;
} sfp_async_req_t;

typedef struct sfp_async_resp {
        uint8_t err_stat;       /* 0 indicates fail and 1 indicates success */
        /* FIXME: any other specific fields expected as response - command specific */
} sfp_async_resp_t;
```

## 5.4 MCP->AP

MCP runs its own firmware known as MCP BL1 (compiled for 32-bit microMIPS architecture).
MCP is viewed as non-secure agent. It runs several tasks in cooperative multitasking way.
MSI-X interrupts could be programmatically routed to one of the three GIB interrupt lines.
Besides there is mailbox interrupt line as well.

---

### 5.4.1 Access to main RAM (MMIO windows)

MCP accesses shared memory region via special hardware mechanism - programmatically
configured MMIO windows that map certain fixed regions of MCP's MMIO virtual address
space into the AP's virtual or physical address space. Thus any access to the mapped
32-bit wide MMIO address range at MCP side is transparently forwarded to the
corresponding AP's RAM. It's recommended to access shared RAM using 32-bit wide 
operations and 32-bit aligned offsets.

Address of shared memory region is received during start up of AP BL1 via SCMI message
using custom vendor-specific protocol. Since MCP is non-secure agent it setups 32-bit
NCB-based cache-able virtual window. Then MCP BL1 setups mapping for one on the four
fixed address ranges to the received virtual address via special CSRs
(`CAVM_XCPX_WINX_CFG` and `CAVM_XCPX_WINX_ADDR`).

---

### 5.4.2 SFP management tasks

MCP BL1 uses two always running tasks and few temporary tasks for SFP management
activities.

First is status loop task that polls for status changes. At the beginning, it waits
for SCMI configuration message from AP BL1 (received thru SCP) and then setups
required hardware (like I2C switches and GPIO expanders) and starts second task
for handling asynchronous request from ATF.

Once done with setting up everything, status loop task goes into the never ending loop
polling QSFP/SFP ports pointed out by configuration data from shared memory region.
Upon detected status change it reports about a change to ATF and, in case of new
connection observed, starts a task for reading and validating EEPROM.

A task for reading EEPROM implements EEPROM reading sequence, copies just read EEPROM
to the shared memory region and then finishes.

Both status loop task and asynchronous command handling task have highest priority.
When possible (time left) they yield execution to allow other tasks to proceed.
Status loop task does that once per millisecond and asynchronous command task - once
per microsecond.

### 5.4.3 TWSI locking

Depending on hardware design, required for SFP management GPIOs could situated under
the same TWSI controller and/or same I2C switch/mux and GPIO expander, so transactions
should not access same hardware in the same time.

Currently, a global lock for TWSI access is implemented such that no new TWSI transaction
is allowed until previous one is done. Task that requested TWSI transaction is blocked and
yield for about 1 microsecond before next attempt to acquire the lock. Going forward,
parallel access to different TWSI controllers may be allowed to improve responsiveness
and overall latencies of SFP management's activities.

---

### 5.4.4 Interrupt handling

Currently no interrupts are involved in SFP management related code. However, MCP BL1 has
framework in place to signal interrupts to AP in the similar way to SCMI notifications from
MCP Bl1 to AP cores.

---

## 5.5. Processing on MCP (Accessing SFP/QSFP module)

For SFP, First 128 bytes of data from EEPROM can be just read.  
> **Note**: 
> if the module is connected, but the data is not read, it should be re-tried.
> We should have a re-try limit of either 3 or 5 depending on the performance
> before returning error to the user.

**SFP Sequence:**

- Check for module detect.
- If Module is present, assert TX disable
- Read the data from EEPROM
- Update SM

For QSFP, some transceivers cannot be identified in low power mode. 
In that case, set it to high power mode, before reading from EEPROM.

**QSFP Sequence:**

- Check for module present

- Assert module select

- Configure power class
  - First read byte 1 to check if memory map is flat or paged
  - If paged, select page select to 0 (upper mem 00h)
  - Read Byte 129 (TABLE 6-16 EXTENDED IDENTIFIER VALUES from `SFF-8636`)
    to read the power class.

- If the power class is one of 1.5, 2.0, 2.5, 3.0 W MAX, no need to do anything.

- If the power is one of 4.0 W, 4.5 W, 5.0 W mac, set byte 93 bit 2 to 
   enable high power mode. But, before enabling the high power class, check 
   the MAX power level supported by the board. 
   This info will be available in DT (which will be updated in SM for MCP to read)

> *With reference to SFF8636*: 
> The memory map is arranged into a single lower page address space of 128 bytes
> and multiple upper address pages. This structure permits timely access to
> addresses in the lower page such as interrupt flags and monitors.
> Less time critical entries such as serial ID information and threshold settings
> are available with the page select function. Data used for interrupt handling
> is located in Lower Page 00h to enable single block read operations for time
> critical data.  
> Upper Page 01h and Upper Page 02h are optional.  
> Upper Page 01h allows implementation of application select table while  
> Upper Page 02h provides a user read/write space.  
> Implementation of these two pages is optional.  
> Lower and Upper Page 00h are always implemented.

- Read EEPROM
  Lower Page 00: Bytes 0 – 127
  First read 128 bytes from EEPROM:  
  
  - Byte 0: Identifier (`SFF 8024`)
  
  - Byte 1: Revision Compliance
  
  - Byte 2:
    - Bit 0 : Data_Not_Ready : If it is low, data is available
    - Bit 2 : Upper memory flat or paged

  - Check if Byte 2, bit 0 is low for data to be ready.
  
  - If data is ready, check byte 2 bit 2 for upper memory type.
  
  - If bit 2 is 0, select page 0 by writing 0 to byte 127 

  - After setting page select, it is better to give a delay
    (`QLOGIC` reference: 500 us).

  - Now, upper page 00h contents (another 128 bytes: 128 – 255) 
    are read which  is used for read only identification information.
    These contents are copied to SM as well.

## 5.6. I2C Switches supported

Below table lists the I2C MUX/Switches supported and the corresponding DTS compatible for each of the types.

static const i2c_compat_t i2c_compat_list[] = {
	{ "cavium,thunder-8890-twsi", I2C_BUS_DEFAULT, I2C_OTHER,  0, 6},
	{ "cavium,thunderx-i2c", I2C_BUS_DEFAULT, I2C_OTHER,  0, 6},
	{ "nxp_pca9540", I2C_BUS_PCA9540, I2C_MUX,    4, 2 },
	{ "nxp_pca9542", I2C_BUS_PCA9542, I2C_MUX,    4, 2 },
	{ "nxp_pca9543", I2C_BUS_PCA9543, I2C_SWITCH, 0, 2 },
	{ "nxp_pca9544", I2C_BUS_PCA9544, I2C_MUX,    4, 4 },
	{ "nxp_pca9545", I2C_BUS_PCA9545, I2C_SWITCH, 0, 4 },
	{ "nxp_pca9546", I2C_BUS_PCA9546, I2C_SWITCH, 0, 4 },
	{ "nxp_pca9547", I2C_BUS_PCA9547, I2C_MUX,    8, 8 },
	{ "nxp_pca9548", I2C_BUS_PCA9548, I2C_SWITCH, 0, 8 },
};

NOTE: MCP supports only PCA9548 driver currently. If a platform requires other I2C switch/MUX type, corresponding driver should be added in MCP.

## 5.7. GPIO Expanders supported

Below table lists the GPIO expanders supported and the corresponding DTS compatible for each of the GPIO expanders.

If a GPIO expander needs to be added other than the listed below, this array in ATF and driver for the GPIO expander in MCP(if it doesn't belong to the below mentioned generic expander types), should be incorporated.

static const gpio_compat_t gpio_compat_list[] = {
	{ "cavium,thunder-8890-gpio", GPIO_PIN_DEFAULT, 64 },	/* 64 pins for T9x */
	{ "nxp_pca9505",	GPIO_PIN_PCA953X, 40 },
	{ "nxp_pca9698",	GPIO_PIN_PCA953X, 40 },
	{ "nxp_pca9534",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9535",	GPIO_PIN_PCA953X, 16 },
	{ "nxp_pca9536",	GPIO_PIN_PCA953X, 4 },
	{ "nxp_pca9537",	GPIO_PIN_PCA953X, 4 },
	{ "nxp_pca9538",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9539",	GPIO_PIN_PCA953X, 16 },
	{ "nxp_pca9554",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9554a",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9555",	GPIO_PIN_PCA953X, 16 },
	{ "nxp_pca9555a",	GPIO_PIN_PCA953X, 16 },
	{ "nxp_pca9556",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9557",	GPIO_PIN_PCA953X, 8 },
	{ "nxp_pca9574",	GPIO_PIN_PCA957X, 8 },
	{ "nxp_pca9575",	GPIO_PIN_PCA957X, 16 },
	{ "maxim_max7310",	GPIO_PIN_PCA953X, 8 },
	{ "maxim_max7312",	GPIO_PIN_PCA953X, 16 },
	{ "maxim_max7313",	GPIO_PIN_PCA953X, 16 },
	{ "maxim_max7315",	GPIO_PIN_PCA953X, 8 },
	{ "ti_pca6107",		GPIO_PIN_PCA953X, 8 },
	{ "ti_tca6408",		GPIO_PIN_PCA953X, 8 },
	{ "ti_tca6416",		GPIO_PIN_PCA953X, 16 },
	{ "ti_tca9554",		GPIO_PIN_PCA953X, 8 },
	{ "nxp_pcf8574",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pcf8574a",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca8574",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca9670",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca9672",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca9674",	GPIO_PIN_PCF857X, 8 },
	{ "nxp_pca8575",	GPIO_PIN_PCF857X, 16 },
	{ "nxp_pcf8575",	GPIO_PIN_PCF857X, 16 },
	{ "nxp_pca9671",	GPIO_PIN_PCF857X, 16 },
	{ "nxp_pca9673",	GPIO_PIN_PCF857X, 16 },
	{ "nxp_pca9675",	GPIO_PIN_PCF857X, 16 },
	{ "maxim_max7328",	GPIO_PIN_PCF857X, 8 },
	{ "maxim_max7329",	GPIO_PIN_PCF857X, 8 },
	{ "cavium,cpld96xx",	GPIO_PIN_CPLD,	8},
};

---

## 6. LED management

**TODO**

---

## 7. PHY management

PHYs are expected to be accessed via MDIO bus and details of PHY address and busare parsed from board linux DT.

 * SMI driver is included in ATF
 * Generic Clause 22/45 APIs are supported
 * Framework is provided to integrate individual SDK for the respective PHYs in the library.

### 7.1 List of PHYs supported:

```c
/* PHY types */
typedef enum phy_type {
        PHY_NONE = 0,
        PHY_MARVELL_5123,
        PHY_MARVELL_5113,
        PHY_MARVELL_88E1514,
        PHY_VITESSE_8574,
        PHY_GENERIC_8023_C22,
        PHY_GENERIC_8023_C45,
} phy_type_t;
```

### 7.2 DTS changes
Board Linux DTS needs to have the corresponding PHY compatible string to choose
the appropriate PHY

```c
/* List of PHY compatible strings/types */
static const phy_compatible_type_t phy_compat_list[] = {
        { "marvell,88x5123", PHY_MARVELL_5123},
        { "marvell,88x5113", PHY_MARVELL_5113},
        { "marvell,88e1514", PHY_MARVELL_88E1514},
        { "marvell,88e1512", PHY_MARVELL_88E1514},
        { "vitesse,vsc8574", PHY_VITESSE_8574},
        { "ethernet-phy-ieee802.3-c22", PHY_GENERIC_8023_C22},
        { "ethernet-phy-ieee802.3-c45", PHY_GENERIC_8023_C45},
};
```

### 7.3 PHY management framework
At boot time, if a corresponding LMAC of a CGX is reported to have PHY by the parser, it looks up for the PHY driver in ATF and assigns corresponding handle(below struct) to each PHY type.

```c
typedef struct phy_config {
        int type;
        int addr;       /* PHY ADDR on MDIO bus */
        int mdio_bus;   /* SMI bus number */
        int mux_switch; /* If controlled via switch. Ex: Analog switch on EBB9604 */
        int media_type; /* Optional : Required for VSC8574 */
        int port;       /* Optional : port num for Marvell PHYs */
        int valid;      /* If valid PHY driver found */
        int init;       /* Whether Initialization is already performed */
        phy_mod_type mod_type; /* Line-side modulation type */
        phy_drv_t *drv; /* struct for PHY driver operations */
        void *priv;
        gpio_info_t mux_info; /* Details of switch details if MDIO is muxed */
} phy_config_t;
```

#### 7.3.1 PHY framework APIs
Each driver is expected to have a set of APIs defined as below. Initialization of the PHY to be done in the probe callback

```c
typedef struct phy_drv {
        char drv_name[64];
        int drv_type;
        int flags;      /* Any specific info about the PHY */
        void (*probe)(int cgx_id, int lmac_id); /* Function pointer to initialize PHY */
        void (*reset)(int cgx_id, int lmac_id); /* Function pointer to reset PHY */
        void (*config)(int cgx_id, int lmac_id); /* Function pointer to set mode of PHY */
        void (*set_an)(int cgx_id, int lmac_id); /* Function pointer to configure AN */
        void (*get_link_status)(int cgx_id, int lmac_id, link_state_t *link); /* Function pointer to get link status of PHY */
        void (*shutdown)(int cgx_id, int lmac_id); /* Function pointer to shutdown PHY */
} phy_drv_t;
```

Ex:
```c
phy_drv_t marvell_drv[] = {
        {
                .drv_name                       = "MARVELL-88E1514",
                .drv_type                       = PHY_MARVELL_88E1514,
                .flags                          = 0,
                .probe                          = phy_marvell_1514_probe,
                .config                         = phy_generic_config,
                .set_an                         = phy_generic_set_an,
                .reset                          = phy_generic_reset,
                .get_link_status                = phy_marvell_1514_get_link_status,
                .shutdown                       = phy_generic_shutdown,
        },
        {
                .drv_name                       = "MARVELL-88X5123",
                .drv_type                       = PHY_MARVELL_5123,
                .flags                          = 0,
                .probe                          = phy_marvell_5123_probe,
                .config                         = phy_marvell_5123_config,
                .set_an                         = phy_marvell_5123_set_an,
                .reset                          = phy_generic_reset,
                .get_link_status                = phy_marvell_5123_get_link_status,
                .shutdown                       = phy_generic_shutdown,
        },
};
```

#### 7.3.2 PHY SDK Library
If a PHY has its own SDK, it should be built as a library and copied to atf/lib/libphy path alongwith the header files.

Library should be included in the build as below in platform makefile along
with the include path.

BL31_LIBS               +=      lib/libphy/libphy_88x5123.a     \
                                lib/libphy/libphy_88x5113.a     \

---

## 8. SFP/QSFP with integrated PHY
There are cases where some boards do have PHY integrated with SFP/QSFP slots. Code flow is little different for this case.

**TODO**

## 9. User interface commands

### 9.1 Change FEC via ethtool

 > ethtool --show-fec ethX

-- The above command provides the supported FEC types for a particular ethernet interface

 > ethtool --set-fec ethX encoding <rs | baser | off>

-- The above command provides option to user to change FEC type for a particular ethernet interface. Allowed FEC types depends on the protocol.


### 9.2 Read QSFP/SFP module info via ethtool

 > ethtool -m ethX

-- The above command dumps the SFP/QSFP module EEPROM information for a particular ethernet interface.

-- The above command displays all zeros in below cases:

	* If the ethernet port do not have a QSFP/SFP slot (say, RJ45 slot)
	* QSFP/SFP module is not SFF compliant
	* If the corresponding LMAC node in DTS doesn't have sfp-slot or qsfp-slot
	info (as quoted in section 2 in this doc)

NOTE: this command is not yet supported on all boards

### 9.3 Set or show PHY line-side modulation type via ethtool private flag

If the PHY supports changing line-side modulation type (NRZ or PAM4), the
following commands are available:

 > ethtool --set-priv-flags ethX pam4 off

 > ethtool --set-priv-flags ethX pam4 on

 > ethtool --show-priv-flags ethX

Turning off PAM4 means setting modulation type to NRZ.

 > **Note**: Only the 6141 PHY supports these commands, currently.

### 9.4 Change FEC or PHY line-side modulation type via U-Boot

 > ethlist

-- Command to display available network interface info

 > set_fec <ethX> [type]

-- Modify fec type for selected ethernet interface
-- Example - set_fec <ethX> [type]
-- Set FEC type for any of RVU PF based network interfaces
	* where type - 0 [NO FEC] 1 [BASER_FEC] 2 [RS_FEC]

 > get_fec <ethX>

-- Display fec type for selected ethernet interface
-- Example - get_fec <ethX>
-- Get FEC type for any of RVU PF based network interfaces

 > get_phymod <ethX>

-- Display line side phy-mod type for selected ethernet interface
-- Example - get_phymod <ethX>
-- Get PHY MOD type for any of RVU PF based network interfaces

 > set_phymod <ethX> [type]

-- Modify line side phy-mod type for selected ethernet interface
-- Example - set_phymod <ethX> [type]
-- Set PHY MOD type for any of RVU PF based network interfaces
	* where type - 0 [NRZ] 1 [PAM4]

### 9.5 Change speed/mode via ethtool

--  command to change the mode

 > ethtool -s ethX advertise 0xXXXXXXX (ethtool argument from the below table for the corresponding mode)


|    Serial   no    |    ATF   MODE            |    ETHTOOL   MODE                                  |     ethtool   argument    |
|-------------------|--------------------------|----------------------------------------------------|----------------------------|
|    1              |    CGX_MODE_SGMII        |    ETHTOOL_LINK_MODE_10BaseT_Half_BIT              |    0x1                     |
|    2              |    CGX_MODE_1000BASEX    |    ETHTOOL_LINK_MODE_1000BaseX_Full_BIT            |    0x20000000000           |
|    3              |    CGX_MODE_QSGMII       |    ETHTOOL_LINK_MODE_1000BaseT_Full_BIT            |    0x1000                  |
|    4              |    CGX_MODE_10G_C2C      |    ETHTOOL_LINK_MODE_10000BaseKX4_Full_BIT         |    0x40000                 |
|    5              |    CGX_MODE_10G_C2M      |    ETHTOOL_LINK_MODE_10000BaseR_Fec_Full_BIT       |    0x100000                |
|    6              |    CGX_MODE_10G_KR       |    ETHTOOL_LINK_MODE_10000BaseKR_Full_BIT          |    0x80000                 |
|    7              |    CGX_MODE_20G_C2C      |    ETHTOOL_LINK_MODE_20000BaseMLD2_Full_BIT        |    0x200000                |
|    8              |    CGX_MODE_25G_C2C      |    ETHTOOL_LINK_MODE_10000BaseCR_Full_BIT          |    0x40000000000           |
|    9              |    CGX_MODE_25G_C2M      |    ETHTOOL_LINK_MODE_25000BaseSR_Full_BIT          |    0x200000000             |
|    10             |    CGX_MODE_25G_2_C2M    |    ETHTOOL_LINK_MODE_20000BaseKR2_Full_BIT         |    0x400000                |
|    11             |    CGX_MODE_25G_CR       |    ETHTOOL_LINK_MODE_25000BaseCR_Full_BIT          |    0x8000000               |
|    12             |    CGX_MODE_25G_KR       |    ETHTOOL_LINK_MODE_25000BaseKR_Full_BIT          |    0x100000000             |
|    13             |    CGX_MODE_40G_C2C      |    ETHTOOL_LINK_MODE_40000BaseSR4_Full_BIT         |    0x2000000               |
|    14             |    CGX_MODE_40G_C2M      |    ETHTOOL_LINK_MODE_40000BaseLR4_Full_BIT         |    0x4000000               |
|    15             |    CGX_MODE_40G_CR4      |    ETHTOOL_LINK_MODE_40000BaseCR4_Full_BIT         |    0x1000000               |
|    16             |    CGX_MODE_40G_KR4      |    ETHTOOL_LINK_MODE_40000BaseKR4_Full_BIT         |    0x800000                |
|    17             |    CGX_MODE_40GAUI       |    ETHTOOL_LINK_MODE_40000BaseR_Full_BIT           |    0x80000000000           |
|    18             |    CGX_MODE_50G_C2C      |    ETHTOOL_LINK_MODE_50000BaseSR2_Full_BIT         |    0x10000000000           |
|    19             |    CGX_MODE_50G_C2M      |    ETHTOOL_LINK_MODE_10000BaseLR_Full_BIT          |    0x100000000000          |
|    20             |    CGX_MODE_50G_4_C2C    |    ETHTOOL_LINK_MODE_50000BaseSR2_Full_BIT         |    0x8000000               |
|    21             |    CGX_MODE_50G_CR       |    ETHTOOL_LINK_MODE_50000BaseCR2_Full_BIT         |    0x400000000             |
|    22             |    CGX_MODE_50G_KR       |    ETHTOOL_LINK_MODE_50000BaseKR2_Full_BIT         |    0x800000000             |
|    23             |    CGX_MODE_80GAUI       |    ETHTOOL_LINK_MODE_10000BaseLRM_Full_BIT         |    0x200000000000          |
|    24             |    CGX_MODE_100G_C2C     |    ETHTOOL_LINK_MODE_100000BaseSR4_Full_BIT        |    0x2000000000            |
|    25             |    CGX_MODE_100G_C2M     |    ETHTOOL_LINK_MODE_100000BaseLR4_ER4_Full_BIT    |    0x8000000000            |
|    26             |    CGX_MODE_100G_CR4     |    ETHTOOL_LINK_MODE_100000BaseCR4_Full_BIT        |    0x4000000000            |
|    27             |    CGX_MODE_100G_KR4     |    ETHTOOL_LINK_MODE_100000BaseKR4_Full_BIT        |    0x1000000000            |
|    28             |    CGX_MODE_SGMII        |    ETHTOOL_LINK_MODE_10BaseT_Full_BIT		    |    0x2			 |
|    29             |    CGX_MODE_SGMII        |    ETHTOOL_LINK_MODE_100BaseT_Half_BIT		    |    0x4			 |
|    30             |    CGX_MODE_SGMII        |    ETHTOOL_LINK_MODE_100BaseT_Full_BIT		    |    0x8			 |
|    31             |    CGX_MODE_SGMII        |    ETHTOOL_LINK_MODE_1000BaseT_Half_BIT	    |    0x10			 |
|    32             |    CGX_MODE_SGMII        |    ETHTOOL_LINK_MODE_1000BaseT_Full_BIT	    |    0x20			 |

Mode/Speed change is restricted based on the physical port capability. Each port depending on whether it has PHY or no PHY, can support different MODES listed above. In addition, MODE change cannot be supported for MODES that require changes in number of lanes it uses. For Ex: run time, MODE change from XLAUI (which uses 4 lanes) cannot be changed to XFI(which uses 1 lane).

Some of the valid use cases are listed here:
* MODE change between 1G_X(1000 BASE-X)/10G_*/20G_*
* MODE change between 50G_4*/25G_2*/10G_KR
* MODE change between 40G_*/80GAUI*
