#include "..\Headers\Scene.h"

USING(Engine)


CScene::CScene(LPDIRECT3DDEVICE9 pDevice)
	:m_pDevice(pDevice)
{
	Safe_AddRef(m_pDevice);
}

HRESULT CScene::Ready_Scene()
{
	return S_OK;
}

_uint CScene::Update_Scene(_float fDeltaTime)
{
	return 0;
}

_uint CScene::Late_Update_Scene(_float fDeltaTime)
{
	return 0;
}


void CScene::Free()
{
	Safe_Release(m_pDevice);
}
