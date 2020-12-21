#include "..\Headers\SceneMgr.h"
#include "Scene.h"
USING(Engine)
IMPLEMENT_SINGLETON(CSceneMgr)

CSceneMgr::CSceneMgr()
{
}

HRESULT CSceneMgr::Setup_CurScene(_int iSceneIndex, CScene * pCurScene)
{
	if (nullptr == pCurScene)
		return E_FAIL;
	if (m_iCurSceneIndex != iSceneIndex)
	{
		Safe_Release(m_pCurScene);
		m_pCurScene = pCurScene;

		m_iCurSceneIndex = iSceneIndex;
	}
	return S_OK;
}

_uint CSceneMgr::Update_Scene(_float fDeltatime)
{
	if (nullptr == m_pCurScene)
		return 0;

	return m_pCurScene->Update_Scene(fDeltatime);
}

_uint CSceneMgr::Late_Update_Scene(_float fDeltatime)
{
	if (nullptr == m_pCurScene)
		return 0;

	return m_pCurScene->Late_Update_Scene(fDeltatime);
}

void CSceneMgr::Free()
{
	Safe_Release(m_pCurScene);
}
