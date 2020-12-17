#pragma once
#ifndef __MAINAPP_H__
#define __MAINAPP_H__

#include "Base.h"
USING(Engine)
class CMainApp final : public CBase
{
private:
	CMainApp();
	virtual ~CMainApp() = default;

public:
	HRESULT Ready_MainApp();
	int Update_MainApp();
	void Late_Update_MainApp();
	void Render_MainApp();

public:
	virtual void Free() override;
	
public:
	static CMainApp* Create();
};

#endif // !__MAINAPP_H__
