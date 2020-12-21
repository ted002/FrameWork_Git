#pragma once
#ifndef __SCENEMGR_H__
#define __SCENEMGR_H__

#include "Base.h"

BEGIN(Engine)

class CSceneMgr : public CBase
{
	DECLARE_SINGLETON(CSceneMgr)
private:
	CSceneMgr();
	virtual ~CSceneMgr() = default;
public:
	HRESULT Setup_CurScene(_int iSceneIndex, class CScene* pCurScene);
	_uint Update_Scene(_float fDeltatime);
	_uint Late_Update_Scene(_float fDeltatime);
public:
	virtual void Free() override;

private:
	class CScene*	m_pCurScene = nullptr;
	_int m_iCurSceneIndex = -1;
};
END
#endif // !__SCENEMGR_H__
