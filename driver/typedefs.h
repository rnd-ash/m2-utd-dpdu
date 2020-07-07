#pragma once
#include "pdu_api.h"

typedef T_PDU_ERROR(__stdcall* tPDUConstruct)(CHAR8* OptionStr, void* pAPITag);
typedef T_PDU_ERROR(__stdcall* tPDUDestruct)();
typedef T_PDU_ERROR(__stdcall* tPDUModuleConnect)(UNUM32 hMod);
typedef T_PDU_ERROR(__stdcall* tPDUModuleDisconnect)(UNUM32 hMod);
typedef T_PDU_ERROR(__stdcall* tPDUGetTimestamp)(UNUM32 hMod, UNUM32* pTimestamp);
typedef T_PDU_ERROR(__stdcall* tPDUIoCtl)(UNUM32 hMod, UNUM32 hCLL, UNUM32 IoCtlCommandId, PDU_DATA_ITEM* pInputData, PDU_DATA_ITEM** pOutputData);
typedef T_PDU_ERROR(__stdcall* tPDUGetVersion)(UNUM32 hMod, PDU_VERSION_DATA* pVersionData);
typedef T_PDU_ERROR(__stdcall* tPDUGetStatus)(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP, T_PDU_STATUS* pStatusCode, UNUM32* pTimestamp, UNUM32* pExtraInfo);
typedef T_PDU_ERROR(__stdcall* tPDUGetLastError)(UNUM32 hMod, UNUM32 hCLL, T_PDU_ERR_EVT* pErrorCode, UNUM32* phCoP, UNUM32* pTimestamp, UNUM32* pExtraErrorInfo);
typedef T_PDU_ERROR(__stdcall* tPDUGetResourceStatus)(PDU_RSC_STATUS_ITEM* pResourceStatus);
typedef T_PDU_ERROR(__stdcall* tPDUCreateComLogicalLink)(UNUM32 hMod, PDU_RSC_DATA* pRscData, UNUM32 resourceId, void* pCllTag, UNUM32* phCLL, PDU_FLAG_DATA* CllCreateFlag);
typedef T_PDU_ERROR(__stdcall* tPDUDestroyComLogicalLink)(UNUM32 hMod, UNUM32 hCLL);
typedef T_PDU_ERROR(__stdcall* tPDUConnect)(UNUM32 hMod, UNUM32 hCLL);
typedef T_PDU_ERROR(__stdcall* tPDUDisconnect)(UNUM32 hMod, UNUM32 hCLL);
typedef T_PDU_ERROR(__stdcall* tPDULockResource)(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask);
typedef T_PDU_ERROR(__stdcall* tPDUUnlockResource)(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask);
typedef T_PDU_ERROR(__stdcall* tPDUGetComParam)(UNUM32 hMod, UNUM32 hCLL, UNUM32 ParamId, PDU_PARAM_ITEM** pParamItem);
typedef T_PDU_ERROR(__stdcall* tPDUSetComParam)(UNUM32 hMod, UNUM32 hCLL, PDU_PARAM_ITEM* pParamItem);
typedef T_PDU_ERROR(__stdcall* tPDUStartComPrimitive)(UNUM32 hMod, UNUM32 hCLL, UNUM32 CoPType, UNUM32 CoPDataSize, UNUM8* pCoPData, PDU_COP_CTRL_DATA* pCopCtrlData, void* pCoPTag, UNUM32* phCoP);
typedef T_PDU_ERROR(__stdcall* tPDUCancelComPrimitive)(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP);
typedef T_PDU_ERROR(__stdcall* tPDUGetEventItem)(UNUM32 hMod, UNUM32 hCLL, PDU_EVENT_ITEM** pEventItem);
typedef T_PDU_ERROR(__stdcall* tPDUDestroyItem)(PDU_ITEM* pItem);
typedef T_PDU_ERROR(__stdcall* tPDURegisterEventCallback)(UNUM32 hMod, UNUM32 hCLL, CALLBACKFNC EventCallbackFunction);
typedef T_PDU_ERROR(__stdcall* tPDUGetObjectId)(T_PDU_OBJT pduObjectType, CHAR8* pShortname, UNUM32* pPduObjectId);
typedef T_PDU_ERROR(__stdcall* tPDUGetModuleIds)(PDU_MODULE_ITEM** pModuleIdList);
typedef T_PDU_ERROR(__stdcall* tPDUGetResourceIds)(UNUM32 hMod, PDU_RSC_DATA* pResourceIdData, PDU_RSC_ID_ITEM** pResourceIdList);
typedef T_PDU_ERROR(__stdcall* tPDUGetConflictingResources)(UNUM32 resourceId, PDU_MODULE_ITEM* pInputModuleList, PDU_RSC_CONFLICT_ITEM** pOutputConflictList);
typedef T_PDU_ERROR(__stdcall* tPDUGetUniqueRespIdTable)(UNUM32 hMod, UNUM32 hCLL, PDU_UNIQUE_RESP_ID_TABLE_ITEM** pUniqueRespIdTable);
typedef T_PDU_ERROR(__stdcall* tPDUSetUniqueRespIdTable)(UNUM32 hMod, UNUM32 hCLL, PDU_UNIQUE_RESP_ID_TABLE_ITEM* pUniqueRespIdTable);
