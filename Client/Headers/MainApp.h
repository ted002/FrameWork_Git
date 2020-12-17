#pragma once
#ifndef __MAINAPP_H__
#define __MAINAPP_H__

class CMainApp final
{
private:
	explicit CMainApp();
	virtual ~CMainApp();


public:
	HRESULT Ready_MainApp();
	int		Update_MainApp();
	void	Late_Update_MainApp();
	void	Render_MainApp();


public:
	static CMainApp * Create();


};

#endif // !__MAINAPP_H__
