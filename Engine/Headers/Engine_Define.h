#pragma once
#ifndef __ENGINE_DEFINE_H__
#define __ENGINE_DEFINE_H__

#define PRINT_LOG(Caption, Message)	\
::MessageBox(0, Message, Caption, MB_OK)

#define NO_COPY(ClassName)							\
ClassName(const ClassName&)	= delete;				\
ClassName& operator=(const ClassName&) = delete;

#define DECLARE_SINGLETON(ClassName)			\
		NO_COPY(ClassName)						\
public:											\
	static ClassName* Get_Instance();			\
	static void Destroy_Instance();				\
private:										\
	static ClassName* m_pInstance;

#define IMPLEMENT_SINGLETON(ClassName)			\
ClassName* ClassName::m_pInstance = nullptr;	\
ClassName* ClassName::Get_Instance()			\
{												\
	if (nullptr == m_pInstance)					\
		m_pInstance = new ClassName;			\
	return m_pInstance;							\
}												\
void ClassName::Destroy_Instance()				\
{												\
	if (m_pInstance)							\
	{											\
		delete m_pInstance;						\
		m_pInstance = nullptr;					\
	}											\
}

#endif // !__ENGINE_DEFINE_H__
