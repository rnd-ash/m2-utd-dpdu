#include "pch.h"
#include "macchina_dpdu.h"

T_PDU_ERROR PDUConstruct(CHAR8* OptionStr, void* pAPITag)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUDestruct()
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUModuleConnect(UNUM32 hMod)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUModuleDisconnect(UNUM32 hMod)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetTimestamp(UNUM32 hMod, UNUM32* pTimestamp)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUIoCtl(UNUM32 hMod, UNUM32 hCLL, UNUM32 IoCtlCommandId, PDU_DATA_ITEM* pInputData, PDU_DATA_ITEM** pOutputData)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetVersion(UNUM32 hMod, PDU_VERSION_DATA* pVersionData)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetStatus(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP, T_PDU_STATUS* pStatusCode, UNUM32* pTimestamp, UNUM32* pExtraInfo)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetLastError(UNUM32 hMod, UNUM32 hCLL, T_PDU_ERR_EVT* pErrorCode, UNUM32* phCoP, UNUM32* pTimestamp, UNUM32* pExtraErrorInfo)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetResourceStatus(PDU_RSC_STATUS_ITEM* pResourceStatus)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUCreateComLogicalLink(UNUM32 hMod, PDU_RSC_DATA* pRscData, UNUM32 resourceId, void* pCllTag, UNUM32* phCLL, PDU_FLAG_DATA* CllCreateFlag)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUDestroyComLogicalLink(UNUM32 hMod, UNUM32 hCLL)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUConnect(UNUM32 hMod, UNUM32 hCLL)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUDisconnect(UNUM32 hMod, UNUM32 hCLL)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDULockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUUnlockResource(UNUM32 hMod, UNUM32 hCLL, UNUM32 LockMask)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetComParam(UNUM32 hMod, UNUM32 hCLL, UNUM32 ParamId, PDU_PARAM_ITEM** pParamItem)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUSetComParam(UNUM32 hMod, UNUM32 hCLL, PDU_PARAM_ITEM* pParamItem)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUStartComPrimitive(UNUM32 hMod, UNUM32 hCLL, UNUM32 CoPType, UNUM32 CoPDataSize, UNUM8* pCoPData, PDU_COP_CTRL_DATA* pCopCtrlData, void* pCoPTag, UNUM32* phCoP)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUCancelComPrimitive(UNUM32 hMod, UNUM32 hCLL, UNUM32 hCoP)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetEventItem(UNUM32 hMod, UNUM32 hCLL, PDU_EVENT_ITEM** pEventItem)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUDestroyItem(PDU_ITEM* pItem)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDURegisterEventCallback(UNUM32 hMod, UNUM32 hCLL, CALLBACKFNC EventCallbackFunction)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetObjectId(T_PDU_OBJT pduObjectType, CHAR8* pShortname, UNUM32* pPduObjectId)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetModuleIds(PDU_MODULE_ITEM** pModuleIdList)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetResourceIds(UNUM32 hMod, PDU_RSC_DATA* pResourceIdData, PDU_RSC_ID_ITEM** pResourceIdList)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetConflictingResources(UNUM32 resourceId, PDU_MODULE_ITEM* pInputModuleList, PDU_RSC_CONFLICT_ITEM** pOutputConflictList)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUGetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCLL, PDU_UNIQUE_RESP_ID_TABLE_ITEM** pUniqueRespIdTable)
{
	return T_PDU_ERROR();
}

T_PDU_ERROR PDUSetUniqueRespIdTable(UNUM32 hMod, UNUM32 hCLL, PDU_UNIQUE_RESP_ID_TABLE_ITEM* pUniqueRespIdTable)
{
	return T_PDU_ERROR();
}
