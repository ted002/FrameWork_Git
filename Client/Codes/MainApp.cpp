#include "stdafx.h"
#include "MainApp.h"


CMainApp::CMainApp()
{
}


CMainApp::~CMainApp()
{
}

HRESULT CMainApp::Ready_MainApp()
{
	if (FAILED(CGraphic_Device::Get_Instance()->Ready_Graphic_Device(g_hWND, WINCX, WINCY, EDisplayMode::WIN)))
	{
		return E_FAIL;
	}
	return S_OK;
}

int CMainApp::Update_MainApp()
{
	return 0;
}

void CMainApp::Late_Update_MainApp()
{

}

void CMainApp::Render_MainApp()
{
	CGraphic_Device::Get_Instance()->Render_Begin();
	CGraphic_Device::Get_Instance()->Render_End();
}

CMainApp * CMainApp::Create()
{
	CMainApp* pInstance = new CMainApp();
	if (FAILED(pInstance->Ready_MainApp()))
	{
		delete pInstance;
		pInstance = nullptr;
	}
	return pInstance;
}
