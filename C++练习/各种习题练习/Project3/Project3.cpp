/* 1953729 ��09 ����� */
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
	strncpy(name, "��ʦ", 4);
	sex = t.sex;
	strcpy(addr, t.addr);
	strcat(addr, "����ѧԺ");
	return *this;
}
Student::operator Teacher()
{
	Teacher a;
	a.num = 1950000 + num % 1000;
	strcpy(a.name, name);
	strncpy(a.name, "ѧ��", 4);
	a.sex = sex;
	strcpy(a.addr, addr);
	strcat(a.addr, "101��");
	return a;
}

Student::Student()
{
	num = 1950000;
	strcpy(name, "<ѧ��S>");
	sex = 'M';
	strcpy(addr, "��ƽ·1239��");
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
	strcpy(name, "<��ʦT>");
	sex = 'M';
	strcpy(addr, "��ƽ·1239���Ժ�¥");
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
	Student s2 = Student(1951234, "ѧ����", 'M', "�ܰ���·4800��");
	Teacher t1;	
	Teacher t2 = Teacher(19123, "��ʦA", 'F', "�ܰ���·4800�����Ź�");

	cout << "ѧ����Ϣ��" << s1 << endl;				
	cout << "ѧ����Ϣ��" << s2 << endl;				
	cout << endl;
	cout << "��ʦ��Ϣ��" << t1 << endl;				
	cout << "��ʦ��Ϣ��" << t2 << endl;				
	cout << endl;

	t1 = s2;
	cout << "ѧ����Ϣ��" << s2 << endl;				
	cout << "ת��Ϊ��ʦ����Ϣ��" << t1 << endl;			
	cout << endl;
	s1 = t2;
	cout << "��ʦ��Ϣ��" << t2 << endl;				
	cout << "ת��Ϊѧ������Ϣ��" << s1 << endl;			
	cout << endl;

	return 0;
}