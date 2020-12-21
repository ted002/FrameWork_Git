#pragma once
#ifndef __KEYMGR_H__
#define __KEYMGR_H__

#include "Base.h"

BEGIN(Engine)
class CKeyMgr : public CBase
{
	DECLARE_SINGLETON(CKeyMgr)
public:
	CKeyMgr();
	virtual ~CKeyMgr() = default;

public:
	virtual void Free() override;
public:
	bool Key_Pressing(int _key);
	bool Key_Down(int _key);
	bool Key_Up(int _key);
	void Key_Update();

private:
	bool				m_bState[VK_MAX];
};
END
#endif // !__KEYMGR_H__
