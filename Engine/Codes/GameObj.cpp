#include "..\Headers\GameObj.h"

USING(Engine)

CGameObj::CGameObj(LPDIRECT3DDEVICE9 pDevice)
	: m_pDevice(pDevice)
{
	Safe_AddRef(m_pDevice);
}

CGameObj::CGameObj(const CGameObj & other)
	: m_pDevice(other.m_pDevice)
{
	Safe_AddRef(m_pDevice);
}

void CGameObj::Free()
{
	Safe_Release(m_pDevice);
}
