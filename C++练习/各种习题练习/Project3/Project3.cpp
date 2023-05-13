/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Project31.h"
#include "Project3.h"
using namespace std;

Student& Student::operator=(const Teacher& t)
{
	num = 19000 + t.num % 1000;
	strcpy(name, t.name);
	strncpy(name, "教师", 4);
	sex = t.sex;
	strcpy(addr, t.addr);
	strcat(addr, "电信学院");
	return *this;
}
Student::operator Teacher()
{
	Teacher a;
	a.num = 1950000 + num % 1000;
	strcpy(a.name, name);
	strncpy(a.name, "学生", 4);
	a.sex = sex;
	strcpy(a.addr, addr);
	strcat(a.addr, "101室");
	return a;
}

Student::Student()
{
	num = 1950000;
	strcpy(name, "<学生S>");
	sex = 'M';
	strcpy(addr, "四平路1239号");
}
Student::Student(const int num1, const char* name1, const char sex1, const char* addr1) :num(num1), sex(sex1)
{
	strcpy(name, name1);
	strcpy(addr, addr1);
}
ostream& operator<<(ostream& out, const Student& stu)
{
	out << stu.num << ' ' << stu.name << ' ' << stu.sex << ' ' << stu.addr;
	return out;
}



Teacher::Teacher()
{
	num = 19000;
	strcpy(name, "<教师T>");
	sex = 'M';
	strcpy(addr, "四平路1239号衷和楼");
}
Teacher::Teacher(const int num1, const char* name1, const char sex1, const char* addr1) :num(num1), sex(sex1)
{
	strcpy(name, name1);
	strcpy(addr, addr1);
}
ostream& operator<<(ostream& out, const Teacher& te)
{
	out << te.num << ' ' << te.name << ' ' << te.sex << ' ' << te.addr;
	return out;
}




int main()
{
	Student s1;	
	Student s2 = Student(1951234, "学生甲", 'M', "曹安公路4800号");
	Teacher t1;	
	Teacher t2 = Teacher(19123, "教师A", 'F', "曹安公路4800号智信馆");

	cout << "学生信息：" << s1 << endl;				
	cout << "学生信息：" << s2 << endl;				
	cout << endl;
	cout << "教师信息：" << t1 << endl;				
	cout << "教师信息：" << t2 << endl;				
	cout << endl;

	t1 = s2;
	cout << "学生信息：" << s2 << endl;				
	cout << "转换为教师的信息：" << t1 << endl;			
	cout << endl;
	s1 = t2;
	cout << "教师信息：" << t2 << endl;				
	cout << "转换为学生的信息：" << s1 << endl;			
	cout << endl;

	return 0;
}