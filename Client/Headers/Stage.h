#pragma once
#ifndef __STAGE_H__

#include "Scene.h"

USING(Engine)
class CStage final : public CScene
{
private:
	explicit CStage(LPDIRECT3DDEVICE9 pDevice);
	virtual ~CStage() = default;

public:
	virtual HRESULT Ready_Scene() override;
	virtual _uint Update_Scene(_float fDeltaTime) override;
	virtual _uint Late_Update_Scene(_float fDeltaTime) override;

public:
	static CStage* Create(LPDIRECT3DDEVICE9 pDevice);
	virtual void Free() override;

};

#define __STAGE_H__
#endif
