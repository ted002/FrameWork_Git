#include "stdafx.h"
#include "..\Headers\Logo.h"
#include "Stage.h"


CLogo::CLogo(LPDIRECT3DDEVICE9 pDevice)
	: CScene(pDevice)
{
}

HRESULT CLogo::Ready_Scene()
{
	if (FAILED(CScene::Ready_Scene()))
		return E_FAIL;

	SetWindowText(g_hWND, L"Logo");

	return S_OK;
}

_uint CLogo::Update_Scene(_float fDeltaTime)
{
	CScene::Update_Scene(fDeltaTime);

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		CManagement* pManagement = CManagement::Get_Instance();
		if (nullptr == pManagement)
			return 0;

		if (FAILED(pManagement->Setup_CurScene((_int)ESceneType::Stage, CStage::Create(m_pDevice))))
		{
			PRINT_LOG(L"Error", L"Failed To Setup_CurrentScene To Stage");
			return E_FAIL;
		}

		return CHANGE_SCENE;
	}

	return NO_EVENT;
}

_uint CLogo::Late_Update_Scene(_float fDeltaTime)
{
	CScene::Late_Update_Scene(fDeltaTime);

	return NO_EVENT;
}

CLogo * CLogo::Create(LPDIRECT3DDEVICE9 pDevice)
{
	CLogo* pInstance = new CLogo(pDevice);
	if (FAILED(pInstance->Ready_Scene()))
	{
		PRINT_LOG(L"Error", L"Failed To Create Logo");
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CLogo::Free()
{
	/* �θ�� �ڽ� ���� �Ҹ��� ȣ�� ����ó�� Free�� ������ ������ ȣ�� */

	/* �ڽ� ���ҽ����� ���� */

	/* �θ� ���ҽ� ���� */
	CScene::Free();
}
