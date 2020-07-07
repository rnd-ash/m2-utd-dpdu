#pragma once

#include "typedefs.h"
#include <Windows.h>

extern tPDUConstruct                 PDUConstruct;
extern tPDUDestruct                  PDUDestruct;
extern tPDUModuleConnect             PDUModuleConnect;
extern tPDUModuleDisconnect          PDUModuleDisconnect;
extern tPDUGetTimestamp              PDUGetTimestamp;
extern tPDUIoCtl                     PDUIoCtl;
extern tPDUGetVersion                PDUGetVersion;
extern tPDUGetStatus                 PDUGetStatus;
extern tPDUGetLastError              PDUGetLastError;
extern tPDUGetResourceStatus         PDUGetResourceStatus;
extern tPDUCreateComLogicalLink      PDUCreateComLogicalLink;
extern tPDUDestroyComLogicalLink     PDUDestroyComLogicalLink;
extern tPDUConnect                   PDUConnect;
extern tPDUDisconnect                PDUDisconnect;
extern tPDULockResource              PDULockResource;
extern tPDUUnlockResource            PDUUnlockResource;
extern tPDUGetComParam               PDUGetComParam;
extern tPDUSetComParam               PDUSetComParam;
extern tPDUStartComPrimitive         PDUStartComPrimitive;
extern tPDUCancelComPrimitive        PDUCancelComPrimitive;
extern tPDUGetEventItem              PDUGetEventItem;
extern tPDUDestroyItem               PDUDestroyItem;
extern tPDURegisterEventCallback     PDURegisterEventCallback;
extern tPDUGetObjectId               PDUGetObjectId;
extern tPDUGetModuleIds              PDUGetModuleIds;
extern tPDUGetResourceIds            PDUGetResourceIds;
extern tPDUGetConflictingResources   PDUGetConflictingResources;
extern tPDUGetUniqueRespIdTable      PDUGet;