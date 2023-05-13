/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/* 此处允许添加必须的定义或声明（不允许全局变量） */
class Teacher;
/* Student 类的定义（成员函数不允许体内实现） */
class Student {
private:
	int num;	//学号
	char name[16];	//姓名
	char sex;	//性别，只能是 F/M 两种，大小写不敏感
	char addr[64];	//家庭住址
	//私有部分不允许添加任何内容
public:
	Student();
	Student(const int num1, const char* name1, const char sex1, const char* addr1);
	friend ostream& operator<<(ostream& out, const Student& stu);
	Student& operator=(const Teacher& t);
	operator Teacher();
	//公有部分允许添加成员函数（体外实现），不允许添加数据成员、友元声明
};

/* ----给出Student类成员函数及友元函数的体外实现（部分无法在此处实现的函数可以再往后放）---- */
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


/* Teacher 类的定义(Teacher类中不允许再添加任何数据成员、成员函数、友元，成员函数不允许体内实现) */
class Teacher {
private:
	int num;	//工号
	char name[16];	//姓名
	char sex;	//性别，只能是 F/M 两种，大小写不敏感
	char addr[64];	//家庭住址
	//私有部分不允许添加任何内容
public:
	Teacher();
	Teacher(const int num1, const char* name1, const char sex1, const char* addr1);
	friend ostream& operator<<(ostream& out, const Teacher& te);
	friend Student;
	//公有部分不允许添加任何内容
};

/* ----给出Teacher类成员函数及友元函数的体外实现---- */
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



/* ----给出Studentr类中必须在Teacher后实现的成员函数的体外实现---- */
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



/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	Student s1;	//缺省值 - 学号：1950000 姓名：<学生S> 性别：M 地址：四平路1239号
	Student s2 = Student(1951234, "学生甲", 'M', "曹安公路4800号");
	Teacher t1;	//缺省值 - 工号：19000 姓名：<教师T> 性别：M 地址：四平路1239号衷和楼
	Teacher t2 = Teacher(19123, "教师A", 'F', "曹安公路4800号智信馆");

	/* 打印原始学生信息 */
	cout << "学生信息：" << s1 << endl;				//期望输出："学生信息：1950000 <学生S> M 四平路1239号"
	cout << "学生信息：" << s2 << endl;				//期望输出："学生信息：1951234 学生甲 M 曹安公路4800号"
	cout << endl;

	/* 打印原始教师信息 */
	cout << "教师信息：" << t1 << endl;				//期望输出："教师信息：19000 <教师T> M 四平路1239号衷和楼"
	cout << "教师信息：" << t2 << endl;				//期望输出："教师信息：19123 教师A F 曹安公路4800号智信馆"
	cout << endl;

	/* 学生转教师测试：
		学号转工号规则：工号 = 19 + 学号后三位
		姓名转换规则：前两个汉字转换为"教师"，后续字符不变
		性别转换规则：原样转换
		地址转换规则：原地址后加"电信学院"(不考虑字符串越界)    */
	t1 = s2;
	cout << "学生信息：" << s2 << endl;				//期望输出："学生信息：1951234 学生甲 M 曹安公路4800号"
	cout << "转换为教师的信息：" << t1 << endl;			//期望输出："转换为教师的信息：19234 教师甲 M 曹安公路4800号电信学院"
	cout << endl;

	/* 教师转学生测试：
		工号转学号规则：学号 = 1950 + 工号后三位
		姓名转换规则：前两个汉字转换为"学生"，后续字符不变
		性别转换规则：原样转换
		地址转换规则：原地址后加"101室"(不考虑字符串越界)    */
	s1 = t2;
	cout << "教师信息：" << t2 << endl;				//期望输出："教师信息：19123 教师A F 曹安公路4800号智信馆"
	cout << "转换为学生的信息：" << s1 << endl;			//期望输出："转换为学生的信息：1950123 学生A F 曹安公路4800号智信馆101室"
	cout << endl;

	return 0;
}