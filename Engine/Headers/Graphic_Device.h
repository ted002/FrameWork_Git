#pragma once
#ifndef __GRAPHIC_DEVICE_H__
#define __GRAPHIC_DEVICE_H__

#include "Engine_Include.h"
enum class EDisplayMode
{
	FULL,
	WIN
};
class CGraphic_Device final
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
	LPDIRECT3D9 m_pSDK; // �׷���ī���� ������ �����ϰ� �����ϴ� ��ü. 
	LPDIRECT3DDEVICE9 m_pDevice; // �ְ� ���������� �׷��� ��ġ�� �����ϴ� ��ü. 

};

#endif // !__GRAPHIC_DEVICE_H__
