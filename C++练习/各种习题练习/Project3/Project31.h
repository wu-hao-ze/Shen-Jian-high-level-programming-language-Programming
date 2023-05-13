#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Project3.h"
using namespace std;
class Student;
class Teacher {
private:
	int num;	
	char name[16];
	char sex;	
	char addr[64];
public:
	Teacher();
	Teacher(const int num1, const char* name1, const char sex1, const char* addr1);
	friend ostream& operator<<(ostream& out, const Teacher& te);
	friend Student;
};