#pragma once
#ifndef __GAMEOBJ_H__
#define __GAMEOBJ_H__

#include "Base.h"
BEGIN(Engine)
class CGameObj : public CBase
{
protected:
	explicit CGameObj(LPDIRECT3DDEVICE9 pDevice);
	explicit CGameObj(const CGameObj& other);
	virtual ~CGameObj() = default;
public:
	virtual CGameObj* Clone(void* pArg = nullptr) = 0;
	virtual void Free() override;
protected:
	typedef unordered_map<wstring, class CComponent*>	COMPONENTS;
	COMPONENTS	m_Components;	/* 컴포넌트의 복제본들 보관 */

	LPDIRECT3DDEVICE9	m_pDevice;
};
END
#endif // !__GAMEOBJ_H__
