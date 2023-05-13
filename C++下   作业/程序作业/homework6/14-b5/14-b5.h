/* 1953729 信09 吴浩泽 */

#pragma once

#include <iostream>
using namespace std;

/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class TString {
private:
	char* content;
	int   len;




	/* 根据需要定义所需的数据成员、成员函数、友元函数等 */
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
	/* 根据需要定义所需的数据成员、成员函数、友元函数等 */

};

/* 如果有其它全局函数需要声明，写于此处 */
ostream& operator<<(ostream& out, const TString& t);
istream& operator>>(istream& in, TString& t);
TString operator+(const TString& t1, const TString& t2);
TString operator+(char t1, const TString& t2);
TString operator+(const TString& t1, char t2);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */