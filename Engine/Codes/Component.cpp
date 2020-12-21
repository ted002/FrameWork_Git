#include "..\Headers\Component.h"

USING(Engine)

CComponent::CComponent(LPDIRECT3DDEVICE9 pDevice)
	: m_pDevice(pDevice)
{
	Safe_AddRef(m_pDevice);
}

CComponent::CComponent(const CComponent & other)
	: m_pDevice(other.m_pDevice)
{
	Safe_AddRef(m_pDevice);
}

void CComponent::Free()
{
	Safe_Release(m_pDevice);
}
