#pragma once
#ifndef __COMPONENT_H__

#include "Base.h"

BEGIN(Engine)
class ENGINE_DLL CComponent abstract : public CBase
{
protected:
	explicit CComponent(LPDIRECT3DDEVICE9 pDevice);
	explicit CComponent(const CComponent& other);
	virtual ~CComponent() = default;

public:
	virtual CComponent* Clone(void* pArg = nullptr) = 0;
	virtual void Free() override;

protected:
	LPDIRECT3DDEVICE9 m_pDevice;
};
END

#define __COMPONENT_H__
#endif