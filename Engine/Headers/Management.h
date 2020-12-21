#pragma once
#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__

#include "Base.h"
#include "Graphic_Device.h"
#include "Renderer.h"
#include "SceneMgr.h"
#include "ComponentMgr.h"
#include "KeyMgr.h"

BEGIN(Engine)
class ENGINE_DLL CManagement final : public CBase
{
	DECLARE_SINGLETON(CManagement)

private:
	CManagement();
	virtual ~CManagement() = default;

public: /*For.General*/
	HRESULT Ready_Engine(HWND hWnd, int iWinCX, int iWinCY, EDisplayMode eDisplayMode, _uint iSceneCount);
	_uint Update_Engine();
	HRESULT Render_Engine(HWND hWnd = nullptr);

public: /*For.Graphic_Device*/
	LPDIRECT3DDEVICE9	Get_Device();

public: /*For.Time_Manager*/

public: /*For.Scene_Manager*/
	HRESULT Setup_CurScene(_int iSceneIndex, class CScene * pCurScene);


public: /*For.GameObject_Manager*/

public: /*For.Component_Manager*/
	HRESULT Add_Component_Prototype(_uint iSceneIndex, const wstring& PrototypeTag, CComponent* pPrototype);
	CComponent* Clone_Component(_uint iSceneIndex, const wstring& PrototypeTag, void* pArg = nullptr);

public: /*For.Key_Manager*/
	bool Key_Pressing(int _key);
	bool Key_Down(int _key);
	bool Key_Up(int _key);
	void Key_Update();

public:
	virtual void Free() override;
	static void Release_Engine();

private:
	CGraphic_Device*	m_pDevice_Manager = nullptr;
	CRenderer*			m_pRenderer = nullptr;
	CSceneMgr*			m_pSceneMgr = nullptr;
	CComponentMgr*		m_pComponentMgr = nullptr;
	CKeyMgr*			m_pKeyMgr = nullptr;
};
END

#endif