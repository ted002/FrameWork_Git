#include "stdafx.h"
#include "..\Headers\MainApp.h"


CMainApp::CMainApp()
{
}


CMainApp::~CMainApp()
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

void CMainApp::Late_Update_MainApp()
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
