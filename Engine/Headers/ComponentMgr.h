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
	/* unordered_map: �ؽ� ����� ��, Ž���ӵ��� ���ϰ� ������. ��� Ű�� ������ ����. */
	typedef unordered_map<wstring, CComponent*> COMPONENTS; /* ������Ʈ���� �������� ������ �����̳� */
	COMPONENTS*	m_pComponents = nullptr; /* �����迭 */
	_uint		m_iSceneCount = 0;

};

END
#endif // !__COMPONENTMGR_H__
