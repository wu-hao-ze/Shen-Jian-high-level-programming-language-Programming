/* 1953729 ��09 ����� */

#pragma once

#include <iostream>
using namespace std;

/* ��ȫTString��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class TString {
private:
	char* content;
	int   len;




	/* ������Ҫ������������ݳ�Ա����Ա��������Ԫ������ */
public:
	const TString& c_str();
	~TString();
	TString();
	TString(const char* s);
	TString(const TString& t);
	TString& operator=(const TString& t);
	friend ostream& operator<<(ostream& out, const TString& t);
	friend istream& operator>>(istream& in, TString& t);
	friend TString operator+(const TString& t1, const TString& t2);
	friend TString operator+(char t1, const TString& t2);
	friend TString operator+(const TString& t1, char t2);
	/* ������Ҫ������������ݳ�Ա����Ա��������Ԫ������ */

};

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
ostream& operator<<(ostream& out, const TString& t);
istream& operator>>(istream& in, TString& t);
TString operator+(const TString& t1, const TString& t2);
TString operator+(char t1, const TString& t2);
TString operator+(const TString& t1, char t2);
/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */