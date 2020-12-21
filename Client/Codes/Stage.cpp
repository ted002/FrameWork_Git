#include "stdafx.h"
#include "..\Headers\Stage.h"

CStage::CStage(LPDIRECT3DDEVICE9 pDevice)
	: CScene(pDevice)
{
}

HRESULT CStage::Ready_Scene()
{
	if (FAILED(CScene::Ready_Scene()))
		return E_FAIL;

	SetWindowText(g_hWND, L"Stage");

	return S_OK;
}

_uint CStage::Update_Scene(_float fDeltaTime)
{
	CScene::Update_Scene(fDeltaTime);

	return NO_EVENT;
}

_uint CStage::Late_Update_Scene(_float fDeltaTime)
{
	CScene::Late_Update_Scene(fDeltaTime);

	return NO_EVENT;
}

CStage * CStage::Create(LPDIRECT3DDEVICE9 pDevice)
{
	CStage* pInstance = new CStage(pDevice);
	if (FAILED(pInstance->Ready_Scene()))
	{
		PRINT_LOG(L"Error", L"Failed To Create Stage");
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CStage::Free()
{
	/* 부모와 자식 간에 소멸자 호출 순서처럼 Free도 동일한 순서로 호출 */

	/* 자식 리소스부터 정리 */

	/* 부모 리소스 정리 */
	CScene::Free();
}
