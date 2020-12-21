#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__
#include "Base.h"

BEGIN(Engine)
class ENGINE_DLL CScene abstract : public CBase
{
protected:
	explicit CScene(LPDIRECT3DDEVICE9 pDevice);
	virtual ~CScene() = default;

public:
	virtual HRESULT Ready_Scene()= 0;
	virtual _uint Update_Scene(_float fDeltaTime)=0;
	virtual _uint Late_Update_Scene(_float fDeltaTime)=0;
public:
	virtual void Free() override;
protected:
	LPDIRECT3DDEVICE9 m_pDevice;
};

END
#endif // !__SCENE_H__
