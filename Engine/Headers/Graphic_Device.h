#pragma once
#ifndef __GRAPHIC_DEVICE_H__
#define __GRAPHIC_DEVICE_H__
#include "Base.h"

BEGIN(Engine)

enum class EDisplayMode
{
	Full,
	Win
};

class CGraphic_Device final : public CBase
{
	DECLARE_SINGLETON(CGraphic_Device)

private:
	CGraphic_Device();
	virtual ~CGraphic_Device() = default;

public:
	LPDIRECT3DDEVICE9	Get_Device() { return m_pDevice; }

public:
	HRESULT Ready_Graphic_Device(HWND hWnd, int iWinCX, int iWinCY, EDisplayMode eDisplayMode);

public:
	virtual void Free() override;

private:
	LPDIRECT3D9 m_pSDK; // 그래픽카드의 수준을 조사하고 생성하는 객체. 
	LPDIRECT3DDEVICE9 m_pDevice; // 애가 실질적으로 그래픽 장치를 제어하는 객체. 

};

END
#endif // !__GRAPHIC_DEVICE_H__
