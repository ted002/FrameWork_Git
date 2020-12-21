#pragma once
#ifndef __RENDERER_H__
#define __RENDERER_H__

/*
렌더링 대상들을 그룹별로 우선순위를 나누어 차례로 렌더링한다.
*/

#include "Base.h"

BEGIN(Engine)
enum class ERenderPriority
{
	Priority,
	NoAlpha,
	Alpha,
	UI,
	End
};

class CRenderer final : public CBase
{
	DECLARE_SINGLETON(CRenderer)

private:
	/*explicit*/ CRenderer(/*LPDIRECT3DDEVICE9 pDevice*/);
	virtual ~CRenderer() = default;

public:
	HRESULT Set_Device(LPDIRECT3DDEVICE9 pDevice);

public:
	HRESULT Add_RenderList(ERenderPriority ePriority, class CGameObj* pGameObject);
	HRESULT Render_RenderList(HWND hWND = nullptr);

private:
	HRESULT Render_Priority();
	HRESULT Render_NoAlpha();
	HRESULT Render_Alpha();
	HRESULT Render_UI();

public:
	virtual void Free() override;

private:
	typedef list<class CGameObj*>	GAMEOBJECTS;
	GAMEOBJECTS	m_GameObjects[(_uint)ERenderPriority::End];

	LPDIRECT3DDEVICE9 m_pDevice;
};
END

#endif