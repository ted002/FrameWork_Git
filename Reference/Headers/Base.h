#pragma once
#ifndef __BASE_H__

#include "Engine_Include.h"

BEGIN(Engine)

class ENGINE_DLL CBase abstract
{
protected:
	CBase();
	virtual ~CBase() = default;

public:
	_uint AddRef();
	_uint Release();

public:
	virtual void Free() = 0;

protected:
	_uint	m_RefCount = 0;
};

END


#define __BASE_H__
#endif // !__BASE_H__

