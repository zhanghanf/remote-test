#include "String.h"

inline String::String(const char* str)
{
	if (str) {
		m_data = new char[strlen(str) + 1];
		strcpy_s(m_data, strlen(str)+1,str);
	}
	else {
		m_data = new char[1];
		m_data[0] = '\0';
	}
}

inline String::String(const String& str)//拷贝构造函数
{
	m_data = new char[strlen(str.m_data) + 1];//深拷贝：创造出来后把内容拷贝过去 浅拷贝：把指针拷贝过去
	strcpy_s(m_data, strlen(str.m_data), str.m_data);
}

String& String::operator=(const String& str)//拷贝赋值引用
{
	if (this == &str) return *this;//检测是否自我赋值（判断来源与目的是否相等），取地址得到指针
	delete[] m_data;//释放自己的空间
	m_data = new char[strlen(str.m_data) + 1];//创建新的空间
	strcpy_s(m_data, strlen(str.m_data)+1,str.m_data);//复制
	// TODO: 在此处插入 return 语句
	return *this；//取值*this
}

inline String::~String()
{
	delete[] m_data;//释放掉动态分配的内存
}
