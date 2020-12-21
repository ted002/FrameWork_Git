#pragma once
#ifndef __RENDERER_H__
#define __RENDERER_H__

/*
������ ������ �׷캰�� �켱������ ������ ���ʷ� �������Ѵ�.
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