#include "..\Headers\ComponentMgr.h"

USING(Engine)
IMPLEMENT_SINGLETON(CComponentMgr)


CComponentMgr::CComponentMgr()
{
}


HRESULT CComponentMgr::Ready_Component_Manager(_uint iSceneCount)
{
	if (0 == iSceneCount)
		return E_FAIL;

	m_pComponents = new COMPONENTS[iSceneCount];
	m_iSceneCount = iSceneCount;

	return S_OK;
}

HRESULT CComponentMgr::Add_Component_Prototype(
	_uint iSceneIndex,
	const wstring& PrototypeTag,
	CComponent * pPrototype)
{
	if (m_iSceneCount <= iSceneIndex ||
		nullptr == m_pComponents ||
		nullptr == pPrototype)
		return E_FAIL;

	auto iter_find = m_pComponents[iSceneIndex].find(PrototypeTag);
	if (m_pComponents[iSceneIndex].end() == iter_find)
	{
		m_pComponents[iSceneIndex].insert(make_pair(PrototypeTag, pPrototype));
	}

	return S_OK;
}

CComponent * CComponentMgr::Clone_Component(
	_uint iSceneIndex,
	const wstring & PrototypeTag,
	void* pArg)
{
	if (m_iSceneCount <= iSceneIndex ||
		nullptr == m_pComponents)
		return nullptr;

	auto iter_find = m_pComponents[iSceneIndex].find(PrototypeTag);
	if (m_pComponents[iSceneIndex].end() == iter_find)
		return nullptr;

	return iter_find->second->Clone(pArg);
}

void CComponentMgr::Free()
{
	for (_uint i = 0; i < m_iSceneCount; ++i)
	{
		for (auto& Pair : m_pComponents[i])
		{
			Safe_Release(Pair.second);
		}
	}

	Safe_Delete_Array(m_pComponents);
}
