#include "stdafx.h"
#include "MainApp.h"
#include "Logo.h"


CMainApp::CMainApp()
	: m_pManagement(CManagement::Get_Instance())
{
	Safe_AddRef(m_pManagement);
}

HRESULT CMainApp::Ready_MainApp()
{
	if (nullptr == m_pManagement)
		return E_FAIL;

	if (FAILED(m_pManagement->Ready_Engine(g_hWND, WINCX, WINCY, EDisplayMode::Win, (_uint)ESceneType::MaxCount)))
	{
		PRINT_LOG(L"Error", L"Failed To Ready_Engine");
		return E_FAIL;
	}
	m_pDevice = m_pManagement->Get_Device();
	if (nullptr == m_pDevice)
	{
		PRINT_LOG(L"Error", L"Failed To Get_Device");
		return E_FAIL;
	}

	Safe_AddRef(m_pDevice);

	if (FAILED(m_pManagement->Setup_CurScene((_int)ESceneType::Logo, CLogo::Create(m_pDevice))))
	{
		PRINT_LOG(L"Error", L"Failed To Setup_CurrentScene To Logo");
		return E_FAIL;
	}

	return S_OK;
}

_uint CMainApp::Update_MainApp()
{
	_uint iEvent = m_pManagement->Update_Engine();
	if (CHANGE_SCENE == iEvent)
		return 0;

	if (FAILED(m_pManagement->Render_Engine()))
		return 0;

	return 0;
}



void CMainApp::Late_Update_MainApp()
{

}

void CMainApp::Render_MainApp()
{
	
}

void CMainApp::Free()
{
	Safe_Release(m_pDevice);
	Safe_Release(m_pManagement);
}

CMainApp * CMainApp::Create()
{
	CMainApp* pInstance = new CMainApp;
	if (FAILED(pInstance->Ready_MainApp()))
	{
		PRINT_LOG(L"Error", L"Failed To Create MainApp");
		Safe_Release(pInstance);
	}

	return pInstance;
}
