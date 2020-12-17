#include "stdafx.h"
#include "MainApp.h"


CMainApp::CMainApp()
{
}

HRESULT CMainApp::Ready_MainApp()
{
	return S_OK;
}

int CMainApp::Update_MainApp()
{
	return 0;
}

void CMainApp::Free()
{
}

void CMainApp::Late_Update_MainApp()
{

}

void CMainApp::Render_MainApp()
{
	
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
