#include "..\Headers\Management.h"

USING(Engine)
IMPLEMENT_SINGLETON(CManagement)

CManagement::CManagement()
	: m_pDevice_Manager(CGraphic_Device::Get_Instance())
	, m_pRenderer(CRenderer::Get_Instance())
	, m_pSceneMgr(CSceneMgr::Get_Instance())
	, m_pComponentMgr(CComponentMgr::Get_Instance())
	, m_pKeyMgr(CKeyMgr::Get_Instance())
{
	Safe_AddRef(m_pDevice_Manager);
	Safe_AddRef(m_pRenderer);
	Safe_AddRef(m_pSceneMgr);
	Safe_AddRef(m_pComponentMgr);
	Safe_AddRef(m_pKeyMgr);
}

HRESULT CManagement::Ready_Engine(HWND hWnd, int iWinCX, int iWinCY, EDisplayMode eDisplayMode, _uint iSceneCount)
{
	if (nullptr == hWnd ||
		nullptr == m_pDevice_Manager ||
		nullptr == m_pRenderer||
		nullptr == m_pSceneMgr ||
		nullptr == m_pComponentMgr ||
		nullptr == m_pKeyMgr)
		return E_FAIL;

	if (FAILED(m_pDevice_Manager->Ready_Graphic_Device(hWnd, iWinCX, iWinCY, eDisplayMode)))
	{
		PRINT_LOG(L"Error", L"Failed To Ready_Graphic_Device");
		return E_FAIL;
	}

	if (FAILED(m_pRenderer->Set_Device(m_pDevice_Manager->Get_Device())))
	{
		PRINT_LOG(L"Error", L"Failed To Set_Device to Renderer");
		return E_FAIL;
	}
	if (FAILED(m_pComponentMgr->Ready_Component_Manager(iSceneCount)))
	{
		PRINT_LOG(L"Error", L"Failed To Ready_Component_Manager");
		return E_FAIL;
	}

	return S_OK;
}

_uint CManagement::Update_Engine()
{
	if (nullptr == m_pSceneMgr)
		return 0;

	_uint iEvent = 0;

	if (iEvent = m_pSceneMgr->Update_Scene(0.0))
		return iEvent;

	if (iEvent = m_pSceneMgr->Late_Update_Scene(0.0))
		return iEvent;
	Key_Update();


	return iEvent;
}

HRESULT CManagement::Render_Engine(HWND hWnd)
{
	if (nullptr == m_pRenderer)
		return E_FAIL;

	if (FAILED(m_pRenderer->Render_RenderList(hWnd)))
	{
		PRINT_LOG(L"Error", L"Failed To Render_RenderList");
		return E_FAIL;
	}

	return S_OK;
}

LPDIRECT3DDEVICE9 CManagement::Get_Device()
{
	if (nullptr == m_pDevice_Manager)
		return nullptr;

	return m_pDevice_Manager->Get_Device();
}

HRESULT CManagement::Setup_CurScene(_int iSceneIndex, CScene * pCurScene)
{
	if (nullptr == m_pSceneMgr)
		return E_FAIL;

	return m_pSceneMgr->Setup_CurScene(iSceneIndex, pCurScene);
}

HRESULT CManagement::Add_Component_Prototype(_uint iSceneIndex, const wstring & PrototypeTag, CComponent * pPrototype)
{
	if (nullptr == m_pComponentMgr)
		return E_FAIL;

	return m_pComponentMgr->Add_Component_Prototype(iSceneIndex, PrototypeTag, pPrototype);
}

CComponent * CManagement::Clone_Component(_uint iSceneIndex, const wstring & PrototypeTag, void * pArg)
{
	if (nullptr == m_pComponentMgr)
		return nullptr;

	return m_pComponentMgr->Clone_Component(iSceneIndex, PrototypeTag, pArg);
}

bool CManagement::Key_Pressing(int _key)
{
	if (nullptr == m_pKeyMgr)
		return false;

	return m_pKeyMgr->Key_Pressing(_key);
}

bool CManagement::Key_Down(int _key)
{
	if (nullptr == m_pKeyMgr)
		return false;

	return m_pKeyMgr->Key_Down(_key);
}

bool CManagement::Key_Up(int _key)
{
	if (nullptr == m_pKeyMgr)
		return false;

	return m_pKeyMgr->Key_Up(_key);
}

void CManagement::Key_Update()
{
	if (nullptr == m_pKeyMgr)
		return;

	return m_pKeyMgr->Key_Update();
}

void CManagement::Free()
{
	Safe_Release(m_pComponentMgr);
	Safe_Release(m_pSceneMgr);
	Safe_Release(m_pRenderer);
	Safe_Release(m_pDevice_Manager);
}

void CManagement::Release_Engine()
{
	/* 항상 CManagement의 Destroy부터 호출해라! */
	if (CManagement::Destroy_Instance())
		PRINT_LOG(L"Warning", L"Failed To Release CManagement");

	if (CComponentMgr::Destroy_Instance())
		PRINT_LOG(L"Warning", L"Failed To Release CComponent_Manager");

	if (CSceneMgr::Destroy_Instance())
		PRINT_LOG(L"Warning", L"Failed To Release CScene_Manager");

	if (CRenderer::Destroy_Instance())
		PRINT_LOG(L"Warning", L"Failed To Release CRenderer");

	if (CKeyMgr::Destroy_Instance())
		PRINT_LOG(L"Warning", L"Failed To Release CKeyMgr");

	if (CGraphic_Device::Destroy_Instance())
		PRINT_LOG(L"Warning", L"Failed To Release CGraphic_Device");
}
