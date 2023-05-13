/* 1953729 信09 吴浩泽 */

/* 允许添加需要的头文件、宏定义等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "14-b5.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */
TString::~TString()
{
	delete[]content;
}

TString::TString()
{
	len = 0;
	content = NULL;
}

TString::TString(const char* s)
{
	if (s == NULL || *s == '\0')
	{
		len = 0;
		content = NULL;
	}
	else
	{
		len = strlen(s);
		content = new char[len + 1];
		strcpy(content, s);
	}
}

TString::TString(const TString& t)
{
	len = t.len;
	content = new char[len + 1];
	if (t.content != NULL)
		strcpy(content, t.content);
}

TString& TString::operator=(const TString& t)
{
	len = t.len;
	if (t.content == NULL || *t.content == '\0' || t.len == 0)
	{
		delete[]content;
		len = 0;
		content = NULL;
	}
	else
	{
		if (content != NULL && content != t.content)
		{
			delete[]content;
			content = new char[len + 1];
		}
		if (content == NULL)
			content = new char[len + 1];
		strcpy(content, t.content);
	}
	return *this;
}



/* 如果有需要的其它全局函数的实现，可以写于此处 */

ostream& operator<<(ostream& out, const TString& t)
{
	if (t.content == NULL || t.len == 0)
		out << "<NULL>";
	else
		out << t.content;
	return out;
}

istream& operator>>(istream& in, TString& t)
{
	t.content = new char[6];
	in >> t.content;
	return in;
}

TString operator+(const TString& t1, const TString& t2)
{
	TString t;
	t.content = new char[t1.len + t2.len + 1];
	t.len = t1.len + t2.len;
	if (t2.content == NULL && t1.content != NULL)
		strcpy(t.content, t1.content);
	else if (t1.content == NULL && t2.content != NULL)
		strcpy(t.content, t2.content);
	else if (t1.content == NULL && t2.content == NULL)
		t.content = NULL;
	else
	{
		strcpy(t.content, t1.content);
		strcat(t.content, t2.content);
	}
	return t;
}

TString operator+(char t1, const TString& t2)
{
	TString t;
	t.content = new char[1 + t2.len + 1];
	t.len = 1 + t2.len;
	char* s1 = &t1;
	s1[1] = '\0';
	strcpy(t.content, s1);
	strcat(t.content, t2.content);
	return t;
}

TString operator+(const TString& t1, char t2)
{
	TString t;
	t.content = new char[t1.len + 1 + 1];
	t.len = t1.len + 1;
	char* s2 = &t2;
	s2[1] = '\0';
	strcpy(t.content, t1.content);
	strcat(t.content, s2);
	return t;
}

const TString& TString:: c_str()
{
	return TString(content);
}