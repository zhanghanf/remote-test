#pragma once
#ifndef _MYSTRING_
#define _MYSTRING_
#include<cstring>
class String
{
public:
	String(const char* str = 0);
	String(const String& str);
	String& operator=(const String& str);//class with point members要有拷贝构造，希望赋值后两端具有相同的内容
	char*get_c_str() const{
		return m_data;
	}
	~String();
private:
	char* m_data;
};


#endif // !_MYSTRING_

