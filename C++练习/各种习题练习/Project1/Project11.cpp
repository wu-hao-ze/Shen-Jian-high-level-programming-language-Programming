/* 1953729 –≈09 Œ‚∫∆‘Û */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <conio.h>
using namespace std;

struct student
{
	int a1;
	char b1;
};

template<typename T1,typename T2>
class Student
{
private:
	T1 num;
	T1 age;
	T2 score;
	static T2 sum;
	static T1 count;
public:
	Student(T1 n, T1 a, T2 s) :num(n), age(a), score(s) {}
	void total();
	static T2 average();
};
template<class T1, class T2>
T2 Student<T1,T2>::sum = 0;

template<class T1, class T2>
T1 Student<T1,T2>::count = 0;

template<class T3, class T4>
void Student<T3,T4>::total()
{
	sum += score;
	count++;
}
template<class T5, class T6>
T6 Student<T5,T6>::average()
{
	return (sum / count);
}
int main()
{
	Student<int,double> student[3] = {
		Student<int,double>(1001,18,70),
		Student<int,double>(1001,18,70),
		Student<int,double>(1001,18,70)
	};
	int n;
	cout << "input the number of students";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		student[i].total();
	}
	cout << Student<int,double>::average() << endl;
	
	
	return 0;
}