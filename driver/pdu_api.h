/**********************************************************************************************
 * PDU_API.H
 **********************************************************************************************
 * Contains the official PDU API definitions
 **********************************************************************************************
 * Softing AG     Richard-Reitzner-Allee 6     D-85540 Haar, Germany
 * Projekt        EDIC PDU API                 http://www.softing.com
 **********************************************************************************************
 *
 *          (C)  Copyright by Softing AG, 2012
 *                  All rights reserved
 *
 **********************************************************************************************/


#ifndef __PDU_API_H
#define __PDU_API_H

// Basic data types

typedef unsigned char      UNUM8;      // Unsigned numeric 8 bits
typedef signed char        SNUM8;      // Signed numeric 8 bits
typedef unsigned short     UNUM16;     // Unsigned numeric 16 bits
typedef signed short       SNUM16;     // Signed numeric 16 bits
typedef unsigned long      UNUM32;     // Unsigned numeric 32 bits
typedef signed long        SNUM32;     // Signed numeric 32 bits
typedef char               CHAR8;      // ASCII-coded 8-bit character value (ISO8859-1 (Latin 1))


//************************* Constants: *************************

// D-PDU API item type values
typedef enum E_PDU_IT
{
   PDU_IT_IO_UNUM32                = 0x1000,  // IOCTL UNUM32 item.
   PDU_IT_IO_PROG_VOLTAGE          = 0x1001,  // IOCTL Program Voltage item.
   PDU_IT_IO_BYTEARRAY             = 0x1002,  // IOCTL Byte Array item.
   PDU_IT_IO_FILTER                = 0x1003,  // IOCTL Filter item.
   PDU_IT_IO_EVENT_QUEUE_PROPERTY  = 0x1004,  // IOCTL Event Queue Property item.
   PDU_IT_RSC_STATUS               = 0x1100,  // Resource Status item
   PDU_IT_PARAM                    = 0x1200,  // ComParam item
   PDU_IT_RESULT                   = 0x1300,  // Result item
   PDU_IT_STATUS                   = 0x1301,  // Status notification item
   PDU_IT_ERROR                    = 0x1302,  // Error notification item
   PDU_IT_INFO                     = 0x1303,  // Information notification item
   PDU_IT_RSC_ID                   = 0x1400,  // Resource ID item
   PDU_IT_RSC_CONFLICT             = 0x1500,  // Resource Conflict Item
   PDU_IT_MODULE_ID                = 0x1600,  // Module ID item
   PDU_IT_UNIQUE_RESP_ID_TABLE     = 0x1700,  // Unique Response Id Table Item
   PDU_IT_IO_VEHICLE_ID_REQUEST    = 0x1800,  // IOCTL DoIP Vehicle Identification Request.
   PDU_IT_IO_ETH_SWITCH_STATE      = 0x1801,  // IOCTL Switch Ethernet activation pin.
   PDU_IT_IO_ENTITY_ADDRESS 	     = 0x1802,  // DoIP entity addressing item
   PDU_IT_IO_ENTITY_STATUS 	     = 0x1803   // DoIP entity status item
} T_PDU_IT;

// ComPrimitive type values
typedef enum E_PDU_COPT
{
   PDU_COPT_STARTCOMM            = 0x8001,  // Start communication with ECU by sending an optional request. The detailed behaviour is protocol dependent.
   PDU_COPT_STOPCOMM             = 0x8002,  // Stop communication with ECU by sending an optional request. The detailed behaviour is protocol dependent.
   PDU_COPT_UPDATEPARAM          = 0x8003,  // Copies ComParams related to a ComLogicalLink from the working buffer to the active buffer. Prior to update, the values need to be passed to the D-PDU API by calling PDUSetComParam, which modifies the ComParams in the working buffer. 
   PDU_COPT_SENDRECV             = 0x8004,  // Send request data and/or receive corresponding response data (single or multiple responses). See section 11.1.3.17 for detailed settings of the PDU_COP_CTRL_DATA structure.
   PDU_COPT_DELAY                = 0x8005,  // Wait the given time span before executing the next ComPrimitive.
   PDU_COPT_RESTORE_PARAM        = 0x8006   // Copies ComParams related to a ComLogicalLink from active buffer to working buffer. (Converse functionality of PDU_COPT_UPDATEPARAM.)
} T_PDU_COPT;

// Object type values
typedef enum E_PDU_OBJT
{
   PDU_OBJT_PROTOCOL  = 0x8021,  // Object type for object PROTOCOL of MDF.
   PDU_OBJT_BUSTYPE   = 0x8022,  // Object type for object BUSTYPE of MDF.
   PDU_OBJT_IO_CTRL   = 0x8023,  // Object type for object IO_CTRL of MDF.
   PDU_OBJT_COMPARAM  = 0x8024,  // Object type for object COMPARAM of MDF.
   PDU_OBJT_PINTYPE   = 0x8025,  // Object type for object PINTYPE of MDF.
   PDU_OBJT_RESOURCE  = 0x8026   // Object type for object RESOURCE of MDF.
} T_PDU_OBJT;

// Status values
typedef enum E_PDU_STATUS
{
   /*  ComPrimitive status */ 
   PDU_COPST_IDLE         = 0x8010,  /* ComPrimitive is in the CommLogicalLink's ComPrimitive Queue */
                                     /* and has not been acted upon. */
   PDU_COPST_EXECUTING    = 0x8011,  /* ComPrimitive has been pulled from the CommLogicalLink's ComPrimitive Queue */
                                     /* and is in an active state. */
   PDU_COPST_FINISHED     = 0x8012,  /* ComPrimitive is finished. */
                                     /* No further event items will be generated for this ComPrimitive. */
   PDU_COPST_CANCELLED    = 0x8013,  /* ComPrimitive was cancelled by a PDUCancelComPrimitive request.  */
                                     /* No further event items will be generated for this ComPrimitive. */
   PDU_COPST_WAITING      = 0x8014,  /* A periodic send ComPrimitive (NumSendCycles > 1) has finished its periodic cycle */
                                     /* and is waiting for its next cyclic time for transmission. */

   /*  ComLogicalLink status */ 
   PDU_CLLST_OFFLINE      = 0x8050,  /* ComLogicalLink is in communication state "offline".               */
   PDU_CLLST_ONLINE       = 0x8051,  /* ComLogicalLink is in communication state "online".                */
   PDU_CLLST_COMM_STARTED = 0x8052,  /* ComLogicalLink is in communication state "communication started". */
                                     /* A PDU_COPT_STARTCOMM ComPrimitive has been commanded.             */
                                     /* The ComLogicalLink is in a transmit/receive state.                */

   /*  Module status */ 
   PDU_MODST_READY     = 0x8060,   /* The MVCI Protocol Module is ready for communication. */
                                   /* The MVCI Protocol Module has been connected by this D-PDU API Session (See PDUModuleConnect) */
   PDU_MODST_NOT_READY = 0x8061,   /* The MVCI Protocol Module is not ready for communication. */
                                   /* Additional information about the cause may be provided via an additional vendor specific */
                                   /* status code returned in pExtraInfo. Refer to description of PDUGetStatus. */
                                   /* EXAMPLE: After running a PDU_IOCTL_RESET command on the module, it may take some time for */
                                   /* the module until it becomes ready. */
                                   /* Module is connected by this D-PDU API Session, but it is not ready for communication. */
   PDU_MODST_NOT_AVAIL = 0x8062,   /* The MVCI Protocol Module is unavailable for connection. */
                                   /* E.g. MVCI Protocol Module is in use by another D-PDU API connection or communication was */
                                   /* lost after previously being in a PDU_MODST_READY state. */
   PDU_MODST_AVAIL     = 0x8063    /* The MVCI Protocol Module is available for connection (i.e. not yet connected by a D-PDU API */
                                   /* session.) See PDUModuleConnect and PDUModuleDisconnect) */
} T_PDU_STATUS;


// Information event values
typedef enum E_PDU_INFO
{
   PDU_INFO_MODULE_LIST_CHG   = 0x8070,  /* New MVCI Protocol Module list is available.          */
                                         /* Client application should call PDUGetModuleIds       */
                                         /* to get a list of the new set of modules and status.  */
                                         /* Related to the System Callback                       */
   PDU_INFO_RSC_LOCK_CHG      = 0x8071,  /* There has been a change in the lock status on a shared physical resource. */
                                         /* Call PDUGetResourceStatus to get a description of the new lock status.    */
                                         /* Only applicable to a resource shared by multiple ComLogicalLinks.         */
                                         /* Related to the ComLogicalLink Callback.                                   */
   PDU_INFO_PHYS_COMPARAM_CHG = 0x8072   /* There has been a change to the physical ComParams by another */
                                         /* ComLogicalLink sharing the resource.                         */
                                         /* Related to the ComLogicalLink Callback.                      */
} T_PDU_INFO;

// D-PDU API events
typedef enum E_PDU_EVT_DATA
{
   PDU_EVT_DATA_AVAILABLE  = 0x0801,  /* This event indicates that there is event data available to be read by the Application. */
                                      /* The data could be an error, status, or result item. */
                                      /* The application must call PDUGetEventItem to retrieve the item. */
   PDU_EVT_DATA_LOST       = 0x0802   /* This event indicates that the Com Logical Link has lost data due to a buffer (queue) overrun. */
                                      /* No event data is stored in the event queue. */
                                      /* This is for information only. */
} T_PDU_EVT_DATA;


// Reserved ID and handle values
#define PDU_ID_UNDEF     0xFFFFFFFE  /* Undefined ID value. Used to indicate an ID value is undefined.*/
#define PDU_HANDLE_UNDEF 0xFFFFFFFF  /* Undefined handle value. Used to indicate a Handle value is undefined.*/

// IOCTL filter type values
typedef enum E_PDU_FILTER
{
   PDU_FLT_PASS       = 0x00000001, /* Allows matching messages into the receive event queue. For all protocols. */
   PDU_FLT_BLOCK      = 0x00000002, /* Keeps matching messages out of the event queue. For all protocols. */
   PDU_FLT_PASS_UUDT  = 0x00000011, /* Allows matching messages into the receive event queue which are of a UUDT type only. For ISO15765 only */
   PDU_FLT_BLOCK_UUDT = 0x00000012  /* Keeps matching messages out of the event queue which are of a UUDT type only. For ISO15765 only */
} T_PDU_FILTER;

// IOCTL event queue mode type values
typedef enum E_PDU_QUEUE_MODE
{
   PDU_QUE_UNLIMITED  = 0x00000000, /* An attempt is made to allocate memory for every item being placed on the event queue. */
                                    /* In Unlimited Mode, the QueueSize is ignored. (Default Mode for a ComLogicalLink) */
   PDU_QUE_LIMITED    = 0x00000001, /* When the ComLogicalLink's event queue is full (i.e., maximum size has been reached), */
                                    /* no new items are placed on the event queue.  The event items are discarded in this case. */
   PDU_QUE_CIRCULAR   = 0x00000002  /* When the ComLogicalLink's event queue is full (i.e., maximum size has been reached), */
                                    /* then the oldest event item in the queue is deleted so that the new event item can then */
                                    /* be placed in the event queue. */
} T_PDU_QUEUE_MODE;

// Definition of the ODX ComParam classes
typedef enum E_PDU_PC
{
   PDU_PC_TIMING       = 1,    // Message flow timing ComParams, e.g., inter-byte time or time between request and response.
   PDU_PC_INIT         = 2,    // ComParams for initiation of communication e.g., trigger address or wakeup pattern. 
   PDU_PC_COM          = 3,    // General communication ComParam.
   PDU_PC_ERRHDL       = 4,    // ComParam defining the behaviour of the runtime system in case an error occurred, 
                               // e.g., runtime system could either continue communication after a timeout 
                               // was detected, or stop and reactivate.
   PDU_PC_BUSTYPE      = 5,    // This is used to define a bustype specific ComParam (e.g., baudrate). 
                               // Most of these ComParams affect the physical hardware. 
                               // These ComParams can only be modified by the first Com Logical Link that acquired 
                               // the physical resource (PDUCreateComLogicalLink()).  
                               // When a second Com Logical Link is created for the same resource, 
                               // these ComParams that were previously set by the initial 
                               // Com Logical Link will be active for the new Com Logical Link. 
   PDU_PC_UNIQUE_ID    = 6,    // This type of ComParam is used to indicate to both the ComLogicalLink and 
                               // the Application that the information is used for protocol response handling 
                               // from a physical or functional group of ECUs to uniquely define an ECU response.
   PDU_PC_TESTER_PRESENT = 7   // This type of ComParam is used for tester present type of ComParams (CP_TesterPresentXXX).
                               // Tester Present ComParams cannot be changed temporarily using the TempParamUpdate flag 
                               // like other ComParams. Using this type of ComParam class enables an application and
                               // database to properly configure and use Tester Present ComParams.
} T_PDU_PC;

// Definition of ODX ComParam data types 
typedef enum E_PDU_PT
{
   PDU_PT_UNUM8        = 0x00000101,   // Unsigned byte
   PDU_PT_SNUM8        = 0x00000102,   // Signed byte
   PDU_PT_UNUM16       = 0x00000103,   // Unsigned two bytes
   PDU_PT_SNUM16       = 0x00000104,   // Signed two bytes
   PDU_PT_UNUM32       = 0x00000105,   // Unsigned four bytes
   PDU_PT_SNUM32       = 0x00000106,   // Signed four bytes
   PDU_PT_BYTEFIELD    = 0x00000107,   // Structure contains an array of UNUM8 bytes with a maximum length and actual length fields. See B.2.3.1 ComParam BYTEFIELD data type for the definition.  
   PDU_PT_STRUCTFIELD  = 0x00000108,   // Structure contains a void * pointer to an array of structures. The ComParamStructType item determines the type of structure to be typecasted onto the void * pointer.  This structure contains a field for maximum number of struct entries and the actual number of struct entries. B.2.3.2 ComParam STRUCTFIELD data type for the definition.
   PDU_PT_LONGFIELD    = 0x00000109    // Structure contains an array of UNUM32 entries with a maximum length and actual length fields. See B.2.3.3 ComParam LONGFIELD Data Type for the definition.  
} T_PDU_PT;

// Error handling return values
typedef enum E_PDU_ERROR
{
   PDU_STATUS_NOERROR              = 0x00000000,   /* No error for the function call */
   PDU_ERR_FCT_FAILED              = 0x00000001,   /* Function call failed (generic failure) */
   PDU_ERR_RESERVED_1              = 0x00000010,   /* Reserved by ISO22900-2 */
   PDU_ERR_COMM_PC_TO_VCI_FAILED   = 0x00000011,   /* Communication between host and MVCI Protocol Module failed */
   PDU_ERR_PDUAPI_NOT_CONSTRUCTED  = 0x00000020,   /* The D-PDU API has not yet been constructed */
   PDU_ERR_SHARING_VIOLATION       = 0x00000021,   /* A PDUDestruct was not called before another PDUConstruct */
   PDU_ERR_RESOURCE_BUSY           = 0x00000030,   /* The requested resource is already in use */
   PDU_ERR_RESOURCE_TABLE_CHANGED  = 0x00000031,   /* Not used by the D-PDU API */
   PDU_ERR_RESOURCE_ERROR          = 0x00000032,   /* Not used by the D-PDU API */
   PDU_ERR_CLL_NOT_CONNECTED       = 0x00000040,   /* The ComLogicalLink cannot be in the PDU_CLLST_OFFLINE state to 
                                                      perform the requested operation */
   PDU_ERR_CLL_NOT_STARTED         = 0x00000041,   /* The ComLogicalLink must be in the PDU_CLLST_COMM_STARTED state 
                                                      to perform the requested operation */
   PDU_ERR_INVALID_PARAMETERS      = 0x00000050,   /* One or more of the parameters supplied in the function are 
                                                      invalid */
   PDU_ERR_INVALID_HANDLE          = 0x00000060,   /* One or more of the handles supplied in the function are invalid */
   PDU_ERR_VALUE_NOT_SUPPORTED     = 0x00000061,   /* One of the option values in PDUConstruct is invalid */
   PDU_ERR_ID_NOT_SUPPORTED        = 0x00000062,   /* IOCTL command id not supported by the implementation of the 
                                                      D-PDU API */
   PDU_ERR_COMPARAM_NOT_SUPPORTED  = 0x00000063,   /* ComParam id not supported by the implementation of the D-PDU API */
   PDU_ERR_COMPARAM_LOCKED         = 0x00000064,   /* Physical ComParam cannot be changed because it is locked by 
                                                      another ComLogicalLink */
   PDU_ERR_TX_QUEUE_FULL           = 0x00000070,   /* The ComLogicalLink’s transmit queue is full; the ComPrimitive 
                                                      could not be queued */
   PDU_ERR_EVENT_QUEUE_EMPTY       = 0x00000071,   /* No more event items are available to be read from the requested 
                                                      queue */
   PDU_ERR_VOLTAGE_NOT_SUPPORTED   = 0x00000080,   /* The voltage value supplied in the IOCTL call is not supported by 
                                                      the MVCI Protocol Module */
   PDU_ERR_MUX_RSC_NOT_SUPPORTED   = 0x00000081,   /* The specified pin / resource are not supported by the MVCI Protocol 
                                                      Module for the IOCTL call */
   PDU_ERR_CABLE_UNKNOWN           = 0x00000082,   /* The cable attached to the MVCI Protocol Module is of an unknown 
                                                      type */
   PDU_ERR_NO_CABLE_DETECTED       = 0x00000083,   /* No cable is detected by the MVCI Protocol Module */
   PDU_ERR_CLL_CONNECTED           = 0x00000084,   /* The ComLogicalLink is already in the PDU_CLLST_ONLINE state */
   PDU_ERR_TEMPPARAM_NOT_ALLOWED   = 0x00000090,   /* Physical ComParams cannot be changed as a temporary ComParam */
   PDU_ERR_RSC_LOCKED              = 0x000000A0,   /* The resource is already locked */
   PDU_ERR_RSC_LOCKED_BY_OTHER_CLL = 0x000000A1,   /* The ComLogicalLink's resource is currently locked by another 
                                                      ComLogicalLink */
   PDU_ERR_RSC_NOT_LOCKED          = 0x000000A2,   /* The resource is already in the unlocked state */
   PDU_ERR_MODULE_NOT_CONNECTED    = 0x000000A3,   /* The module is not in the PDU_MODST_READY state */
   PDU_ERR_API_SW_OUT_OF_DATE      = 0x000000A4,   /* The API software is older than the MVCI Protocol Module Software */
   PDU_ERR_MODULE_FW_OUT_OF_DATE   = 0x000000A5,   /* The MVCI Protocol Module software is older than the API software */
   PDU_ERR_PIN_NOT_CONNECTED       = 0x000000A6,   /* The requested Pin is not routed by supported cable */
   PDU_ERR_IP_PROTOCOL_NOT_SUPPORTED                     = 0x000000B0,  /* IP protocol is not supported: e.g. IPv6 used as protocolVersion, 
                                                                           but OS doesn't support IPv6 (or it is disabled).*/
   PDU_ERR_DOIP_ROUTING_ACTIVATION_FAILED                = 0x000000B1,  /* DoIP Routing activation failed */
   PDU_ERR_DOIP_ROUTING_ACTIVATION_AUTHENTICATION_FAILED = 0x000000B2,  /* DoIP Routing activation denied due to missing authentication */
   PDU_ERR_DOIP_AMBIGUOUS_LOGICAL_ADDRESS                = 0x000000B3   /* Denied to connect a DoIP LogicalLink with a logical address 
							                                                      which is identical for multiple DoIP entities inside a DoIP MVCI module 
	   					                                                      representing a collection of DoIP entities */
} T_PDU_ERROR;

#define PDU_CLLHDL_LICENSE_CHECK_FAILED 0x80000000

typedef enum E_PDU_ERR_EVT
{
   PDU_ERR_EVT_NOERROR              = 0x00000000,  /* No Error. Event type only returned on a PDUGetLastError if there were 
                                                      no previous errors for the requested handle */
   PDU_ERR_EVT_FRAME_STRUCT         = 0x00000100,  /* CLL/CoP Error: The structure of the received protocol frame is 
                                                      incorrect (e.g. wrong frame number, missing FC...). */
   PDU_ERR_EVT_TX_ERROR             = 0x00000101,  /* CLL/CoP Error: Error encountered during tramsmit of a ComPrimitive 
                                                      PDU */
   PDU_ERR_EVT_TESTER_PRESENT_ERROR = 0x00000102,  /* CLL/CoP Error: Error encountered in transmitting a Tester Present
                                                      message or in receiving an expected response to a Tester Present
                                                      message. */
   PDU_ERR_EVT_RSC_LOCKED           = 0x00000109,  /* CLL Error: A physical ComParam was not set because of a physical 
                                                      ComParam lock. */
   PDU_ERR_EVT_RX_TIMEOUT           = 0x00000103,  /* CLL/CoP Error: Receive timer (e.g. P2Max) expired with no expected
                                                      responses received from the vehicle. */
   PDU_ERR_EVT_RX_ERROR             = 0x00000104,  /* CLL/CoP Error: Error encountered in receiving a mesage from the
                                                      vehicle bus (e.g. checksum error ...). */
   PDU_ERR_EVT_PROT_ERR             = 0x00000105,  /* CLL/CoP Error: Protocol error encountered during handling of a
                                                      ComPrimitive (e.g. if the protocol cannot handle the length of a
                                                      ComPrimitive. */
   PDU_ERR_EVT_LOST_COMM_TO_VCI     = 0x00000106,  /* Module Error: Communication to a MVCI protocol module has been lost. */
   PDU_ERR_EVT_VCI_HARDWARE_FAULT   = 0x00000107,  /* Module Error: The MVCI protocol module has detected a hardware error. */
   PDU_ERR_EVT_INIT_ERROR           = 0x00000108   /* CLL/CoP Error: A failure occurred during a protocol initialization 
                                                      sequence. */
} T_PDU_ERR_EVT;

//************************* API data structures: *************************

typedef struct
{
  UNUM32  ParamMaxLen;        /* Contains the maximum number of bytes, the ComParam can contain in pDataArray. 
                                 This is also the amount of memory the D-PDU API allocates prior to a call of
                                 PDUGetComParam. */
  UNUM32  ParamActLen;        /* Contains the actual number of UNUM8 bytes in pDataArray */
  UNUM8   *pDataArray;        /* Pointer to an array of UNUM8 values */
} PDU_PARAM_BYTEFIELD_DATA;

typedef enum E_PDU_CPST
{
   PDU_CPST_SESSION_TIMING  = 0x00000001,   /* See ComParam struct type PDU_PARAM_STRUCT_SESS_TIMING */
   PDU_CPST_ACCESS_TIMING   = 0x00000002    /* See ComParam struct type PDU_PARAM_STRUCT_ACCESS_TIMING */
} T_PDU_CPST;

typedef struct
{
   T_PDU_CPST ComParamStructType;  /* type of ComParam Structure being used. */
   UNUM32     ParamMaxEntries;     /* Contains the maximum number of struct entries the ComParam can contain in
                                      pStructArray. This is also the amount of memory the D-PDU API allocates prior to
                                      a call of PDUGetComParam. The value of this element is given in the MDF file by
                                      the entry MAX_VALUE of the corresponding COMPARAM_REF */
   UNUM32     ParamActEntries;     /* Contains the actual number of struct entries in pStructArray. The value range of
                                      this element must be between the MDF file entries MIN_VALUE and
                                      MAX_VALUE of the corresponding COMPARAM_REF */
   void*      pStructArray;        /* Pointer to an array of structs (typecasted to the ComParamStructType) */
} PDU_PARAM_STRUCTFIELD_DATA;

typedef struct
{
   UNUM16   session;       /* Session number, for the diagnostic session of ISO 15765-3 */
   UNUM8    P2Max_high;    /* 1ms resolution, default P2Can_Server_max timing supported by the
                              server for the activated diagnostic session. Used for ComParam CP_P2Max. */
   UNUM8    P2Max_low;     /* 1ms resolution. Used for ComParam CP_P2Min. */
   UNUM8    P2Star_high;   /* 10ms resolution. Enhanced (NRC 78hex) P2Can_Server_max supported by the
                              server for the activated diagnostic session. Used for ComParam CP_P2Star */
   UNUM8    P2Star_low;    /* 10ms resolution. Used for internal ECU use only. */
} PDU_PARAM_STRUCT_SESS_TIMING;

typedef struct
{
   UNUM8    P2Min;         /* 0.5ms resolution. Minimum time between tester request and ECU response(s). Used
                              for ComParam_P2Min */
   UNUM8    P2Max;         /* Resolution see table 5 of ISO14230-2. Maximum time between tester request and ECU
                              response(s). User for ComParam CP_P2Max */
   UNUM8    P3Min;         /* 0.5ms resolution. Minimum time between end of ECU responses and start of new
                              tester request. User for ComParam CP_P3Min */
   UNUM8    P3Max;         /* 250ms resolution. Maximum time between ECU responses and start of new tester
                              request used for ComParam CP_P3Max_Ecu or CP_P2Star for the tester */
   UNUM8    P4Min;         /* 0.5ms resolution. Minimum inter byte time for tester request. Use for ComParam
                              CP_P4Min */
   UNUM8    TimingSet;     /* Set number allowing multiple parameters (ex: default, normal) */
} PDU_PARAM_STRUCT_ACCESS_TIMING;

typedef struct
{
   UNUM32   ParamMaxLen;   /* Contains the maximum number of bytes the ComParam can contain in
                              pDataArray. This is also the amount of memory the D-PDU API allocates prior to a
                              call of PDUGetComParam. */
   UNUM32   ParamActLen;   /* Contains the actual number of UNUM32 entries in pDataArray */
   UNUM32   *pDataArray;   /* Pointer to an array of UNUM32 values */
} PDU_PARAM_LONGFIELD_DATA;

// Generic Item for type evaluation and casting
// This is a generic item used for casting to item specific structures. PDU_ITEM is used in the function PDUDestroyItem.
typedef struct {
   T_PDU_IT ItemType;         /* See section D-PDU API item type values */
} PDU_ITEM;

// Item for Generic IOCTL data item type 
// This is a generic IOTCL data item is used for casting to specific IOCTL type structures
// PDU_DATA_ITEM is used in the function PDUIoctl.
typedef struct {
   T_PDU_IT ItemType;         /* value= one of the IOCTL constants from Table D.1.1 (e.g., PDU_IT_IO_UNUM32)*/
   void *pData;               /* holds the data pointer to the specific IOCTL data structure */
} PDU_DATA_ITEM;

// IOCTL programming voltage structure (PDU_IT_IO_PROG_VOLTAGE)
typedef struct {
   UNUM32 ProgVoltage_mv;     /* programming voltage in mv */
   UNUM32 PinOnDLC;           /* pin number on Data Link Connector */
} PDU_IO_PROG_VOLTAGE_DATA;

// IOCTL byte array structure (PDU_IT_IO_BYTEARRAY)
typedef struct {
   UNUM32   DataSize;         /* number of bytes in the data array */
   UNUM8   *pData;            /* pointer to the data array */
} PDU_IO_BYTEARRAY_DATA;

// IOCTL filter data structure
typedef struct {
   T_PDU_FILTER FilterType;        /* type of filter being configured. See IOCTL filter type values */
   UNUM32 FilterNumber;            /* Filter Number. Used to replace filters and stop filters. Range=[1-64] */
   UNUM32 FilterCompareSize;       /* Number of bytes used out of each of the filter messages arrays. Range=[1-12] */
   UNUM8 FilterMaskMessage[12];    /* (Mask message to be ANDed to each incoming message).) */
                                   /* When using the CAN protocol, setting the first 4 bytes of FilterMaskMessage to 0xFF */
                                   /* makes the filter specific to one CAN ID. */
                                   /* Using other values, allows for the reception or blocking of multiple CAN identifiers.*/ 
   UNUM8 FilterPatternMessage[12]; /* (Pattern message to be compared to the incoming message after the FilterMaskMessage has been applied). */
                                   /* If the result matches this pattern message and the FilterType is PASS_FILTER, */
                                   /* then the incoming message will be processed for further reception (otherwise it will be discarded). */
                                   /* If the result matches this pattern message and the FilterType is BLOCK_FILTER, */
                                   /* then the incoming message will be discarded (otherwise it will be processed for further reception). */
                                   /* Message bytes in the received message that are beyond the DataSize of the pattern message */
                                   /* will be treated as 'don’t care'.*/
} PDU_IO_FILTER_DATA;

// IOCTL filter list structure (PDU_IT_IO_FILTER)
typedef struct {
   UNUM32 NumFilterEntries;           /* number of Filter entries in the filter list array */ 
   PDU_IO_FILTER_DATA *pFilterData;   /* pointer to an array of filter data */
} PDU_IO_FILTER_LIST;

// IOCTL event queue property structure (PDU_IT_IO_EVENT_QUEUE_PROPERTY)
typedef struct {
   UNUM32 QueueSize;                   /* maximum size of event queue */
   T_PDU_QUEUE_MODE QueueMode;         /* Queue mode. See IOCTL event queue mode type values */
} PDU_IO_EVENT_QUEUE_PROPERTY_DATA;

// Item for resource status information (via used by PDUGetResourceStatus)
typedef struct {
   UNUM32   hMod;                      /* Handle of a MVCI Protocol Module (IN parameter) */ 
   UNUM32   ResourceId;                /* Resource ID (IN parameter) */
   UNUM32   ResourceStatus;            /* Resource Information Status (OUT Parameter): (See D.1.8 for specfic values.) */
} PDU_RSC_STATUS_DATA;

typedef struct {
   T_PDU_IT ItemType;                        /* value= PDU_IT_RSC_STATUS (IN parameter)*/
   UNUM32  NumEntries;                       /* (IN Parameter) = number of entries in pResourceStatusData array. */
   PDU_RSC_STATUS_DATA *pResourceStatusData; /* array to contain resource status (IN Parameter)*/
} PDU_RSC_STATUS_ITEM;

// Item for ComParam data (used by PDUGetComParam, PDUSetComParam)
typedef struct {
   T_PDU_IT ItemType;                  /* value= PDU_IT_PARAM */
   UNUM32   ComParamId;                /* ComParam Id.  Value from MDF of MVCI Protocol Module */
   T_PDU_PT ComParamDataType;          /* Defines the data type of the ComParam See section B.2.3 ComParam data type */
   T_PDU_PC ComParamClass;             /* ComParam Class type.  The class type is used by the D-PDU API for special ComParam handling cases. (BusType (physical ComParams) and Unique ID ComParams)). See section B.2.2 */
   void   *pComParamData;              /* pointer to ComParam data of type ComParamDataType */
} PDU_PARAM_ITEM;

// Item for module identification (used by PDUGetModuleIds)
typedef struct {
   UNUM32   ModuleTypeId;              /* MVCI Protocol ModuleTypeId */
   UNUM32   hMod;                      /* handle of MVCI Protocol Module assigned by D-PDU API */
   CHAR8   *pVendorModuleName;         /* Vendor specific information string for the unique module identification. */
                                       /* E.g. Module serial number or Module friendly name */
   CHAR8   *pVendorAdditionalInfo;     /* Vendor specific additional information string */
   T_PDU_STATUS ModuleStatus;          /* Status of MVCI Protocol Module detected by D-PDU API session*/
} PDU_MODULE_DATA;

typedef struct {
   T_PDU_IT ItemType;                  /* value= PDU_IT_MODULE_ID */
   UNUM32   NumEntries;                /* number of entries written to the pModuleData array */
   PDU_MODULE_DATA *pModuleData;       /* pointer to array containing module types and module handles */
} PDU_MODULE_ITEM;

// Items for resource identification (used by PDUGetResourceIds)
typedef struct {
   UNUM32 hMod;                        /* MVCI Protocol Module Handle */
   UNUM32 NumIds;                      /* number of resources that match PDU_RSC_DATA */
   UNUM32 *pResourceIdArray;           /* pointer to a list of resource ids */
} PDU_RSC_ID_ITEM_DATA;

typedef struct {
   T_PDU_IT ItemType;                  /* value= PDU_IT_RSC_ID (IN parameter)*/
   UNUM32   NumModules;                /* number of entries in pResourceIdDataArray. */
   PDU_RSC_ID_ITEM_DATA *pResourceIdDataArray; /* pointer to an array of resource Id Item Data */
} PDU_RSC_ID_ITEM;

// Structure for resource data (used by PDUGetResourceIds and PDUCreateComLogicalLink)
typedef struct {
   UNUM32   DLCPinNumber;              /* Pin number on DLC */
   UNUM32   DLCPinTypeId;              /* Pin ID */
} PDU_PIN_DATA;

typedef struct {
   UNUM32   BusTypeId;                 /* Bus Type Id (IN parameter) */
   UNUM32   ProtocolId;                /* Protocol Id (IN parameter) */
   UNUM32   NumPinData;                /* Number of items in the following array */
   PDU_PIN_DATA *pDLCPinData;         /* Pointer to array of PDU_PIN_DATA structures*/
} PDU_RSC_DATA;

// Item for conflicting resources (used by PDUGetConflictingResources)
typedef struct {
   UNUM32   hMod;                      /* Handle of the MVCI Protocol Module with conflict*/ 
   UNUM32   ResourceId;                /* Conflicting Resource ID */
} PDU_RSC_CONFLICT_DATA;

typedef struct {
   T_PDU_IT ItemType;                  /* value= PDU_IT_RSC_CONFLICT */
   UNUM32   NumEntries;                /* number of entries written to pRscConflictData*/
   PDU_RSC_CONFLICT_DATA *pRscConflictData;  /* pointer to array of PDU_RSC_CONFLICT_DATA*/
} PDU_RSC_CONFLICT_ITEM;

// Items for unique response identification (used by PDUGetUniqueRespIdTable and PDUSetUniqueRespIdTable)
typedef struct {
   UNUM32 UniqueRespIdentifier;        /* filled out by Application */
   UNUM32 NumParamItems;               /* number of ComParams for the Unique Identifier */
   PDU_PARAM_ITEM *pParams;            /* pointer to array of ComParam items to uniquely define a ECU response.  The list is protocol specific */
} PDU_ECU_UNIQUE_RESP_DATA;

typedef struct {
   T_PDU_IT ItemType;                  /* value= PDU_IT_UNIQUE_RESP_ID_TABLE */
   UNUM32 NumEntries;                  /* number of entries in the table */
   PDU_ECU_UNIQUE_RESP_DATA *pUniqueData; /* pointer to array of table entries for each ECU response */
} PDU_UNIQUE_RESP_ID_TABLE_ITEM;

// Item for event notification
typedef struct {
   T_PDU_IT ItemType;                  /* value= PDU_IT_RESULT or PDU_IT_STATUS or PDU_IT_ERROR or PDU_IT_INFO*/
   UNUM32 hCop;                        /* If item is from a ComPrimitive then the hCop contains the valid ComPrimitive handle, */
                                       /* else it contains PDU_HANDLE_UNDEF */
   void* pCoPTag;                      /* ComPrimitive Tag. Should be ignored if hCop = PDU_HANDLE_UNDEF*/
   UNUM32 Timestamp;                   /* Timestamp in microseconds*/
   void* pData;                        /* points to the data for the specified Item Type. See section 11.1.4.11.1 to 11.1.4.11.4 */
} PDU_EVENT_ITEM;

// Asynchronous status change notification for PDU_IT_STATUS Item.
typedef T_PDU_STATUS PDU_STATUS_DATA;  /* Status code information. See section D.1.4 to D.1.6*/

// Asynchronous event information notification for PDU_IT_INFO Item.
typedef struct {
   T_PDU_INFO InfoCode;                /* Information code. See Table D.7 - Information event values   */
   UNUM32 ExtraInfoData;               /* Optional additional information */
} PDU_INFO_DATA;

// Asynchronous error notification structure for the PDU_IT_ERROR Item.
typedef struct {
   T_PDU_ERR_EVT ErrorCodeId;          /* error code, binary information. */
   UNUM32 ExtraErrorInfoId;            /* Optional additional error information, text translation via MDF file.  
                                          Binary Information, 0 indicates no additional error information
                                          See section Table D.18 - Event error and examples for additional error codes */
} PDU_ERROR_DATA;

// Structure for extra result data information
typedef struct {
   UNUM32 NumHeaderBytes;              /* Number of header bytes contained in pHeaderBytes array. */
   UNUM32 NumFooterBytes;              /* Number of footer bytes contained in pFooterBytes array. (SAE J1850 PWM) Start position of extra data in received message (for example, IFR) or ISO14230 checksum.) When no extra data bytes are present in the message, NumFooterBytes shall be set to zero. */
   UNUM8* pHeaderBytes;                /* Reference pointer to Response PDU Header bytes, NULL if NumHeaderBytes = 0 */
   UNUM8* pFooterBytes;                /* Reference pointer to Response PDU Footer bytes, NULL if NumFooterBytes = 0 */
} PDU_EXTRA_INFO;

// Structure for flag data 
typedef struct {
   UNUM32 NumFlagBytes;                /* number of bytes in pFlagData array*/
   UNUM8 *pFlagData;                   /* Pointer to flag bytes used for TxFlag, RxFlag, and CllCreateFlag.  See section D.2 Flag definitions */
} PDU_FLAG_DATA;

// Asynchronous result notification structure (received data) for the PDU_IT_RESULT Item.
typedef struct {
   PDU_FLAG_DATA RxFlag;               /* Receive message status. See RxFlag definition.*/
   UNUM32    UniqueRespIdentifier;     /* ECU response unique identifier */
   UNUM32    AcceptanceId;             /* Acceptance Id value from ComPrimitive Expected Response Structure. */
                                       /* If multiple expected response entries match the response payload data, */
                                       /* then the first matching expected response id found in the array of expected */
                                       /* responses is used. (I.e. acceptance filtering is carried out in the sequence */
                                       /* of the expected responses as they appear in the array of expected responses. */
                                       /* Thus, an expected response with the lowest array index has the highest priority.)*/
	PDU_FLAG_DATA  TimestampFlags;	   /* Bitoriented Timestamp Indicator flag (See sections Structure for flag data and TimestampFlag definition).  If the flag data is 0, then the following timestamp information is not valid.*/
	UNUM32 	TxMsgDoneTimestamp;	      /* Transmit Message done Timestamp in microseconds*/
	UNUM32 	StartMsgTimestamp;		   /* Start Message Timestamp in microseconds*/
   PDU_EXTRA_INFO *pExtraInfo;         /* If NULL, no extra information is attached to the response structure. */
                                       /* This feature is enabled by setting the ENABLE_EXTRA_INFO bit in the TxFlag for */
                                       /* the ComPrimitive (See TxFlag definition section)*/
   UNUM32    NumDataBytes;             /* Data size in bytes, if RawMode then the data includes header bytes, checksum, */
                                       /* message data bytes (pDataBytes), and extra data, if any.*/   
   UNUM8    *pDataBytes;               /* Reference pointer to D-PDU API memory that contains PDU Payload data. */
                                       /* In non-Raw mode this data contains no header bytes, CAN Ids, or checksum information. */
                                       /* In RawMode, this data will contain the exact data received from the ECU. */
                                       /* For ISO 15765, ISO11898 and SAE J1939, the first 4 bytes are the */
                                       /* CAN ID (11 bit or 29 bit) followed by a possible extended address byte (See Table D.14 - TxFlag ) */
} PDU_RESULT_DATA;

// Structure for version information (used by PDUGetVersion)
typedef struct {
   UNUM32   MVCI_Part1StandardVersion; /* Release version of supported MVCI Part 1 standard (See Coding of version numbers)*/
   UNUM32   MVCI_Part2StandardVersion; /* Release version of supported MVCI Part 2 standard (See Coding of version numbers)*/
   UNUM32   HwSerialNumber;            /* Unique Serial number of MVCI HW module from a vendor */
   CHAR8    HwName[64];                /* Name of MVCI HW module; zero terminated */
   UNUM32   HwVersion;                 /* Version number of MVCI HW module (See Coding of version numbers)*/
   UNUM32   HwDate;                    /* Manufacturing date of MVCI HW module (See Coding of dates)*/
   UNUM32   HwInterface;               /* Type of MVCI HW module; zero terminated */
   CHAR8    FwName[64];                /* Name of the firmware available in the MVCI HW module */
   UNUM32   FwVersion;                 /* Version number of the firmware in the MVCI HW module (See Coding of version numbers)*/
   UNUM32   FwDate;                    /* Manufacturing date of the firmware in the MVCI HW module (See Coding of dates)*/
   CHAR8    VendorName[64];            /* Name of vendor; zero terminated */
   CHAR8    PDUApiSwName[64];          /* Name of the D-PDU API software; zero terminated */
   UNUM32   PDUApiSwVersion;           /* Version number of D-PDU API software (See Coding of version numbers)*/
   UNUM32   PDUApiSwDate;              /* Manufacturing date of the D-PDU API software (See Coding of dates)*/
} PDU_VERSION_DATA;

// Structure for expected response
typedef struct {
   UNUM32   ResponseType;              /* 0=positive response; >0 negative response */ 
   UNUM32   AcceptanceId;              /* ID assigned by application to be returned in PDU_RESULT_DATA, */
                                       /* which indicates which expected response matched */
   UNUM32   NumMaskPatternBytes;       /* number of bytes in the Mask Data and Pattern Data*/
   UNUM8   *pMaskData;                 /* Pointer to Mask Data. Bits set to a '1' are care bits, '0' are don't care bits. */
   UNUM8   *pPatternData;              /* Pointer to Pattern Data. Bytes to compare after the mask is applied */
   UNUM32	NumUniqueRespIds;	       /* number of items in the following array of unique response identifiers. If the number is set to 0, then responses with any unique response identifier are considered, when trying to match them to this expected response. */
   UNUM32	*pUniqueRespIds;	       /* Array containing unique response identifiers. Only responses with a unique response identifier found in this array are considered, when trying to match them to this expected response. */
} PDU_EXP_RESP_DATA;

// Structure to control a ComPrimitive's operation (used by PDUStartComPrimitive)
typedef struct {
   UNUM32   Time;                      /* Cycle time in ms for cyclic send operation or delay time for PDU_COPT_DELAY ComPrimitive */
   SNUM32   NumSendCycles;             /* # of send cycles to be performed; -1 for infinite cyclic send operation                  */
   SNUM32   NumReceiveCycles;          /* # of receive cycles to be performed;                                                     */ 
                                       /* -1 (IS-CYCLIC) for infinite receive operation,                                           */
                                       /* -2 (IS-MULTIPLE) for multiple expected responses from 1 or more ECUs                     */
   UNUM32   TempParamUpdate;           /* Temporary ComParam and temporary UniqueRespIdTable settings for the ComPrimitive:        */
                                       /* 0 = Do not use temporary ComParams for this ComPrimitive.                                */ 
                                       /*     The ComPrimitive shall attach the "Active" ComParam buffer to the ComPrimitive.      */
                                       /*     This buffer shall be in effect for the ComPrimitive until it is finished.            */
                                       /*     The ComParams for the ComPrimitive will not change even if the "Active" buffer is    */
                                       /*     modified by a subsequent ComPrimitive type of PDU_COPT_UPDATEPARAM.                  */
                                       /* 1 = Use temporary ComParams for this ComPrimitive; The ComPrimitive shall attach the     */
                                       /*     ComParam "Working" buffer "Working" table to the ComPrimitive.                       */
                                       /*     This buffer shall be in effect for the ComPrimitive until it is finished.            */
                                       /*     The ComParams for the ComPrimitive will not change even if the "Active" or           */
                                       /*     "Working" buffers are modified by any subsequent calls to PDUSetComParam.            */
                                       /* NOTE: If TempParamUpdate is set to 1, the ComParam Working Buffer is restored to         */
                                       /* the Active Buffer when this PDUStartComPrimitive function call returns.                  */
   PDU_FLAG_DATA TxFlag;               /* Transmit Flag used to indicate protocol specific elements for the ComPrimitive's         */
                                       /* execution. (See section D.2.1 TxFlag definition.)                                        */
   UNUM32   NumPossibleExpectedResponses;  /* number of entries in pExpectedResponseArray */
   PDU_EXP_RESP_DATA *pExpectedResponseArray; /* pointer to an array of expected responses (see 11.1.3.18 Structure for expected response) */
} PDU_COP_CTRL_DATA;

#define MAX_MSG_LEN 8

#define SFTNG_CAN_MSG_FLAG_RECEIVE_FRAME     0x0001  /* Receive-Flag for a frame */
#define SFTNG_CAN_MSG_FLAG_ERROR_FRAME       0x0002  /* CAN error frame */
#define SFTNG_CAN_MSG_FLAG_REMOTE_FRAME      0x0004  /* CAN remote frame (not supported) */
#define SFTNG_CAN_MSG_FLAG_EXT_ID            0x0008  /* CAN extended identifier */
#define SFTNG_CAN_MSG_FLAG_ACK_FRAME         0x0010  /* Transmit-Flag (Tx-ACK) */
#define SFTNG_CAN_MSG_FLAG_BUFFER_OVERRUN    0x0020  /* Flag to signal Buffer overrun */

typedef enum E_SE_CAN_EVENT_TYPE          /* Enum of the possible CAN event types */
{
   SE_RECEIVE_MSG,                        /* Message has been received */
   SE_CHIP_STATE_MSG,                     /* Chip status */
   SE_TRANSMIT_MSG                        /* Message has been transmitted */
}T_SE_CAN_EVENT_TYPE;

typedef enum E_SE_CAN_CHIP_STATE          /* Enum of the possible CAN chip states */ 
{
   SE_CCS_BUS_OFF,
   SE_CCS_ERROR_ACTIVE,
   SE_CCS_ERROR_PASSIVE,
   SE_CCS_ERROR_WARNING,
   SE_CCS_UNKNOW = 0xFF
}T_SE_CAN_CHIP_STATE;

typedef struct _PDU_SE_CAN_MSG            /* Structure for the description of a single CAN message */
{ 
   UNUM32    id;                          /* CAN ID (standard or extended ID depending on flags) */ 
   UNUM16    flags;                       /* Combination of the SFTNG_CAN_MSG_FLAG_...-Values (see above) */
   UNUM8     dlc;                         /* DLC (data length code) for the CAN frame */ 
   UNUM8     data [MAX_MSG_LEN];          /* CAN frame data bytes */
}T_PDU_SE_CAN_MSG;

typedef struct _PDU_SE_CAN_CHIP_STATE     /* Structure for description of a CAN chip state */
{
   T_SE_CAN_CHIP_STATE chipState;         /* Chip state */
   UNUM8  TxErrorCounter;                 /* Transmit error counter */
   UNUM8  RxErrorCounter;                 /* Receive error counter */
}T_PDU_SE_CAN_CHIP_STATE;

union PDU_SE_EVENT_DATA                   /* Union for T_PDU_SE_CAN_EVENT */
{                                         /* contains either */
   T_PDU_SE_CAN_MSG  canMsg;              /* a CAN message or */
   T_PDU_SE_CAN_CHIP_STATE chipStateMsg;  /* a chip state message */
};

typedef struct _PDU_SE_CAN_EVENT
{
   T_SE_CAN_EVENT_TYPE tEventType;        /* Type of the CAN event */
   UNUM32 timeStamp;                      /* timeStamp of the event (ignored for sending) */
   union PDU_SE_EVENT_DATA eventData;     /* depending on tEventType:
                                             a CAN message or a chipStateMsg */
} T_PDU_SE_CAN_EVENT;


// Structure for IP Address information in PDU_IO_VEHICLE_ID_REQUEST
typedef struct {
	UNUM32	IpVersion;	  /* the IP version to be used for DoIP communication: 4=IPv4, 6=IPv6 */
	UNUM8	  *pAddress;	  /* IPv4: 4 Byte broadcast address (in network byte 	order: MSB first)
					              IPv6: 16 Byte multicast address (in network byte 	order: MSB first)*/
} PDU_IP_ADDR_INFO;

//Structure for IOCTL PDU_IOCTL_VEHICLE_ID_REQUEST command
typedef struct {
	UNUM32	PreselectionMode;	               /* Preselection mode: 0=no preselection */
				                                 /* 1= select DoIP entities with given VIN */
				                                 /* 2= select DoIP entities with given EID */
	CHAR8*	PreselectionValue;	            /* pointer to NULL terminated ASCII string */
				                                 /* containing optional VIN or EID (depending on */
				                                 /* PreselectionMode) */
	UNUM32	CombinationMode;	               /* Combination mode: */
				                                 /* 0= no combination */
				                                 /* 1= combine DoIP entities with common VIN */
				                                 /*    into MVCI of type “DoIP-Vehicle” */
				                                 /* 2= combine DoIP entities with common GroupID */
				                                 /*    into MVCI of type “DoIP-Group” */
				                                 /* 3= combine all DoIP entities */
				                                 /*    into MVCI of type “DoIP-Collection” */
	UNUM32	VehicleDiscoveryTime;	         /* Time-out to wait for vehicle identification 	responses. 0=return immediately, or time in 	milliseconds. */
	UNUM32	NumDestinationAddresses;	      /* Number of broadcast/multicast addresses in the destination address array. May be 0 for default */
	PDU_IP_ADDR_INFO *pDestinationAddresses;	/* pointer to an array of IP addresses on which broadcast/multicast should be performed */
} PDU_IO_VEHICLE_ID_REQUEST;

typedef struct {
   UNUM32	EthernetSenseState;		/*EthernetSenseState
                                    0 = Ethernet activation pin off
                                    1 = Ethernet activation pin on*/
	UNUM32	EthernetActPinNumber;   /* EthernetActPinNumber 
                                    Pin number on DLC of the ethernet activation pin. 
                                    Default shall be 8 as defined in ISO13400-2 for OBD-connector */
} PDU_IO_ETH_SWITCH_STATE;


typedef struct {
   PDU_IP_ADDR_INFO *pDestinationAddresses;
} PDU_IO_PWR_MODE_REQUEST;


// prototype of the applications callback function
typedef void (__stdcall *CALLBACKFNC)(T_PDU_EVT_DATA eventType, UNUM32 hMod, UNUM32 hCLL, void *pCllTag, void *pAPITag);

#endif /* __PDU_API_H */
