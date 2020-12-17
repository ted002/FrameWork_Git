#pragma once
#ifndef __GRAPHIC_DEVICE_H__
#define __GRAPHIC_DEVICE_H__

#ifdef DLL_EXPORT
#define DLL_DECLSPEC __declspec(dllexport)

#else
#define DLL_DECLSPEC __declspec(dllimport)

#endif // DLL_EXPORT

#include "Engine_Include.h"

enum class DLL_DECLSPEC EDisplayMode
{
	FULL,
	WIN
};
class DLL_DECLSPEC CGraphic_Device final
{
	DECLARE_SINGLETON(CGraphic_Device)

private:
	CGraphic_Device();
	~CGraphic_Device();

public:
	LPDIRECT3DDEVICE9	Get_Device() { return m_pDevice; }

public:
	HRESULT Ready_Graphic_Device(HWND hWnd, int iWinCX, int iWinCY, EDisplayMode eDisplayMode);
	void Release_Graphic_Device();

	void Render_Begin();
	void Render_End(HWND hWND = nullptr);
private:
	LPDIRECT3D9 m_pSDK; // 그래픽카드의 수준을 조사하고 생성하는 객체. 
	LPDIRECT3DDEVICE9 m_pDevice; // 애가 실질적으로 그래픽 장치를 제어하는 객체. 

};

#endif // !__GRAPHIC_DEVICE_H__
