#include "..\Headers\Management.h"

USING(Engine)
IMPLEMENT_SINGLETON(CManagement)

CManagement::CManagement()
{
}

HRESULT CManagement::Ready_Graphic_Device(HWND hWnd, int iWinCX, int iWinCY, EDisplayMode eDisplayMode)
{
	return E_NOTIMPL;
}

void CManagement::Free()
{
}
