#include "..\Headers\Renderer.h"

USING(Engine)
IMPLEMENT_SINGLETON(CRenderer)

CRenderer::CRenderer(/*LPDIRECT3DDEVICE9 pDevice*/)
//: m_pDevice(pDevice)
{
	//Safe_AddRef(m_pDevice);
}

HRESULT CRenderer::Set_Device(LPDIRECT3DDEVICE9 pDevice)
{
	if (nullptr == pDevice)
		return E_FAIL;

	m_pDevice = pDevice;
	Safe_AddRef(m_pDevice);

	return S_OK;
}

/* 매 프레임마다 렌더러에 렌더링 대상을 추가 */
HRESULT CRenderer::Add_RenderList(ERenderPriority ePriority, CGameObj* pGameObject)
{
	if (ERenderPriority::End <= ePriority ||
		nullptr == pGameObject)
		return E_FAIL;

	/*m_GameObjects[(_uint)ePriority].push_back(pGameObject);
	Safe_AddRef(pGameObject);*/

	return S_OK;
}

/* 매 프레임마다 렌더링함 */
HRESULT CRenderer::Render_RenderList(HWND hWND /*= nullptr*/)
{
	if (nullptr == m_pDevice)
		return E_FAIL;

	if (FAILED(m_pDevice->Clear(0, nullptr, D3DCLEAR_STENCIL | D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_ARGB(255, 0, 0, 255), 1.f, 0)))
		return E_FAIL;

	if (FAILED(m_pDevice->BeginScene()))
		return E_FAIL;

	if (FAILED(Render_Priority()))
		return E_FAIL;

	if (FAILED(Render_NoAlpha()))
		return E_FAIL;

	if (FAILED(Render_Alpha()))
		return E_FAIL;

	if (FAILED(Render_UI()))
		return E_FAIL;

	if (FAILED(m_pDevice->EndScene()))
		return E_FAIL;

	if (FAILED(m_pDevice->Present(nullptr, nullptr, hWND, nullptr)))
		return E_FAIL;

	return S_OK;
}

HRESULT CRenderer::Render_Priority()
{
	/*for (auto& pGameObject : m_GameObjects[(_uint)ERenderPriority::Priority])
	{
	if (FAILED(pGameObject->Render_GameObject()))
	return E_FAIL;

	Safe_Release(pGameObject);
	}*/

	m_GameObjects[(_uint)ERenderPriority::Priority].clear();

	return S_OK;
}

HRESULT CRenderer::Render_NoAlpha()
{
	//for (auto& pGameObject : m_GameObjects[(_uint)ERenderPriority::NoAlpha])
	//{
	//	if (FAILED(pGameObject->Render_GameObject()))
	//		return E_FAIL;

	//	Safe_Release(pGameObject);
	//}

	m_GameObjects[(_uint)ERenderPriority::NoAlpha].clear();

	return S_OK;
}

HRESULT CRenderer::Render_Alpha()
{
	/*m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

	for (auto& pGameObject : m_GameObjects[(_uint)ERenderPriority::Alpha])
	{
	if (FAILED(pGameObject->Render_GameObject()))
	return E_FAIL;

	Safe_Release(pGameObject);
	}

	m_GameObjects[(_uint)ERenderPriority::Alpha].clear();

	m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);*/

	return S_OK;
}

HRESULT CRenderer::Render_UI()
{
	/*for (auto& pGameObject : m_GameObjects[(_uint)ERenderPriority::UI])
	{
	if (FAILED(pGameObject->Render_GameObject()))
	return E_FAIL;

	Safe_Release(pGameObject);
	}*/

	m_GameObjects[(_uint)ERenderPriority::UI].clear();

	return S_OK;
}

void CRenderer::Free()
{
	for (_uint i = 0; i < (_uint)ERenderPriority::End; ++i)
	{
		for (auto& pGameObject : m_GameObjects[i])
		{
			//Safe_Release(pGameObject);
		}

		m_GameObjects[i].clear();
	}

	Safe_Release(m_pDevice);
}


/*
explicit: 묵시적 형변환 방지, 묵시적 형변환으로 인한 문법 혼란을 방지.

class A
{
public:
explicit A(int n);
};

void Func(int a);
void Func(A a);

void main()
{
//Func(100); // 모호하죠? int a = 100, A a = 100 둘다 가능하기 때문에 모호함.
Func(A(100)); // explicit 키워드를 생성자 앞에 붙인 이후에는 무조건 명시적 형변환해야함.
}
*/

