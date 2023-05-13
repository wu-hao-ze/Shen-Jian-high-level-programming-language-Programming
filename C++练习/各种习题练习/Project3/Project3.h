#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Project31.h"
using namespace std;
class Teacher;
class Student {
private:
	int num;	
	char name[16];
	char sex;	
	char addr[64];
public:
	Student();
	Student(const int num1, const char* name1, const char sex1, const char* addr1);
	friend ostream& operator<<(ostream& out, const Student& stu);
	Student& operator=(const Teacher& t);
	operator Teacher();
};


