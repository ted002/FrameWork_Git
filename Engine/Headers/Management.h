#pragma once
#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__

#include "Base.h"
#include "Graphic_Device.h"

BEGIN(Engine)
class ENGINE_DLL CManagement final : public CBase
{
	DECLARE_SINGLETON(CManagement)

private:
	CManagement();
	virtual ~CManagement() = default;

public: /*For.General*/
		/*HRESULT Ready_Engine();
		_uint Update_Engine();*/

public: /*For.Graphic_Device*/
	HRESULT Ready_Graphic_Device(HWND hWnd, int iWinCX, int iWinCY, EDisplayMode eDisplayMode);

public: /*For.Time_Manager*/

public: /*For.GameObject_Manager*/

public: /*For.Component_Manager*/


public:
	virtual void Free() override;

private:
	CGraphic_Device*	m_pDevice_Manager = nullptr;
};
END

#endif