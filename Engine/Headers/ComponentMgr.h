#pragma once
#ifndef __COMPONENTMGR_H__
#define __COMPONENTMGR_H__

#include "Base.h"
#include "Component.h"

BEGIN(Engine)

class CComponentMgr : public CBase
{
	DECLARE_SINGLETON(CComponentMgr)

public:
	CComponentMgr();
	virtual ~CComponentMgr() = default;
public:
	HRESULT Ready_Component_Manager(_uint iSceneCount);
	HRESULT Add_Component_Prototype(_uint iSceneIndex, const wstring& PrototypeTag, CComponent* pPrototype);
	CComponent* Clone_Component(_uint iSceneIndex, const wstring& PrototypeTag, void* pArg = nullptr);

public:
	virtual void Free() override;
private:
	/* unordered_map: 해시 기반의 맵, 탐색속도가 어마어마하게 빠르다. 대신 키값 정렬이 없다. */
	typedef unordered_map<wstring, CComponent*> COMPONENTS; /* 컴포넌트들의 원형들을 보관할 컨테이너 */
	COMPONENTS*	m_pComponents = nullptr; /* 동적배열 */
	_uint		m_iSceneCount = 0;

};

END
#endif // !__COMPONENTMGR_H__
