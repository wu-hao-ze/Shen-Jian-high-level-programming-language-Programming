/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "14-b5.h"
using namespace std;

#if defined(__linux) || defined(__linux__)
#include <sys/time.h>
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
long get_cur_msec(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);

	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

#else
#include <Windows.h>
#include <conio.h>
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
long get_cur_msec(void)
{
	return GetTickCount(); //取当前系统时间，单位毫秒
}

#endif

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
//int memory_speed_test(int op)
//{
//	const int MAX_BYTES = 100 * 1024 * 1024;
//
//	TString s1;
//	int     total, len, i;
//	int     MB_count, MB_prev_count;
//	char    temp[65536];
//	long    t_start, t_end, t_cur, t_prev;
//	char* crc_str;
//
//	cout << "内存性能测试" << (op == 0 ? "(s1=s1+str方式)" : "(s1+=str方式)") << endl;
//	cout << "注意事项：1、根据配置不同，大约1-10分钟，以内存耗尽或申请满100MB字节为结束条件" << endl;
//	cout << "          2、在VS2019下测试时，先打开任务管理器，观察运行过程中本程序占用的内存值" << endl;
//	cout << "          3、VS2019下如果内存耗尽，会出现错误提示，此时可以观察任务管理器中本程序占用的内存值" << endl;
//	cout << "             - 如果等到内存耗尽再打开任务管理器，可能会因为无内存而无法打开" << endl;
//	cout << "          4、Linux服务器下，每个用户的最大可用内存为512MB，超出则分配空间失败" << endl;
//	cout << "             - 建议内存性能测试在Windows下通过后再在Linux运行" << endl;
//
//	//为防止前面多按回车导致此处不停顿，必须输入continue才能继续
//	while (1) {
//		char tmp[80];
//		cout << "请输入continue后继续" << endl;
//		cin >> tmp;
//		cin.ignore(65536, '\n'); //跳过回车
//		if (strcmp(tmp, "continue") == 0)
//			break;
//	}
//
//	crc_str = new(nothrow) char[MAX_BYTES + 65536]; //申请（100MB+64KB）空间
//	if (crc_str == NULL) {
//		cout << "无法申请" << MAX_BYTES + 65536 << "字节的校验空间，程序终止，请检查后再次运行" << endl;
//		return -1;
//	}
//	*crc_str = 0; //置为空串
//
//	t_prev = t_start = get_cur_msec(); //取当前系统时间，单位毫秒
//	MB_prev_count = 0;
//	srand((unsigned int)time(0));
//	total = 0;
//	while (1) {
//		len = 32768 + rand() % 32768;
//
//		for (i = 0; i < len; i++)
//			temp[i] = ' ' + rand() % 95;	//数组用随机字符填充
//		temp[len] = 0;
//		total += len;
//		if (op == 0)
//			s1 = s1 + temp;
//		else
//			s1 += temp;
//
//		strcat(crc_str, temp);
//
//		MB_count = s1.length() / (1024 * 1024);
//		if (MB_count - MB_prev_count >= 1) {
//			MB_prev_count = MB_count;
//
//			t_cur = get_cur_msec();   //取当前系统时间
//
//			cout << "s1已有长度：" << setw(10) << s1.length() / (1024.0 * 1024) << " MB字节，本次增加 " << setw(5) << len << " 字节，总用时"
//				<< setw(10) << (t_cur - t_start) / 1000.0 << "秒，本次1MB用时" << setw(10) << (t_cur - t_prev) / 1000.0 << "秒" << endl;
//			t_prev = t_cur;
//		}
//		else
//			cout << "s1已有长度：" << setw(10) << s1.length() / (1024.0 * 1024) << " MB字节，本次增加 " << setw(5) << len << " 字节" << endl;
//
//		if (s1.length() == 0 || s1.length() > MAX_BYTES)	//满100MB或内存耗尽则结束
//			break;
//	}//end of while (1)
//
//	t_end = get_cur_msec();   //取当前系统时间
//
//	cout << "time=" << (t_end - t_start) / 1000.0 << endl;
//
//	if (s1.length() == 0) {
//		cout << "内存分配到达 " << total / (1024 * 1024) << " MB字节后，内存耗尽（请检查程序中的错误）" << endl;
//
//#if !(defined(__linux) || defined(__linux__))
//		cout << endl << "观察任务管理器中本程序的内存占用情况..." << endl;
//		wait_for_enter();
//#endif
//		exit(-1);
//	}
//	else
//		cout << "内存分配到达满100MB，测试结束" << endl;
//
//	int check1 = (s1 != crc_str);			//TString方式比较两串是否相等
//	int check2 = strcmp(s1.c_str(), crc_str);	//strcmp方式比较两串是否相等
//
//	delete[]crc_str; //释放校验串
//
//	if (check1 || check2)
//		cout << "s1累加验证出错，请检查程序的实现部分" << endl;
//	else {
//		cout << "    本次测试耗时 " << (t_end - t_start) / 1000.0 << "秒" << endl;
//		if (op == 0) {
//			cout << "内存性能测试(s1=s1+str方式)" << endl;
//#if !(defined(__linux) || defined(__linux__))
//			cout << "    老师的机器（CPU：AMD Ryzen 7 4700U, 内存：DDR4 3200MHz）运行VS2019-Debug-x86编译的程序，大约耗时240-260秒" << endl;
//#else
//			cout << "    Linux服务器下运行，大约耗时110-130秒（如果多人同时测试，偏差可能较大）" << endl;
//#endif
//		}
//		else {
//			cout << "内存性能测试(s1+=str方式)" << endl;
//#if !(defined(__linux) || defined(__linux__))
//			cout << "    老师的机器（CPU：AMD Ryzen 7 4700U, 内存：DDR4 3200MHz）运行VS2019-Debug-x86编译的程序，大约耗时100-120秒" << endl;
//#else
//			cout << "    Linux服务器下运行，大约耗时50-70秒（如果多人同时测试，偏差可能较大）" << endl;
//#endif
//		}
//		cout << "    【说明】：只有相同编译器下的运行时间才有可比性" << endl;
//		cout << "              如果时间相差太大，除CPU和内存的性能差异外，还有可能是算法问题" << endl;
//
//#if !(defined(__linux) || defined(__linux__))
//		cout << endl << "观察任务管理器中本程序的内存占用情况(不允许超过115MB)..." << endl;
//#endif
//		wait_for_enter();
//	}
//
//	return 0;
//}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	if (1) {
		const TString s1;                 //s1为null
		const TString s2("teststr2");      //s2为"teststr2"
		const TString s3 = "teststr3";       //s3为"teststr3"
		const TString s4 = NULL;            //s4为null
		const TString s5 = "";              //s5为null

		cout << "定义对象并初始化测试(null及字符串常量初始化)" << endl;

		cout << "s1应该是<NULL>，  实际输出：" << s1 << endl;
		cout << "s2应该是teststr2，实际输出：" << s2 << endl;
		cout << "s3应该是teststr3，实际输出：" << s3 << endl;
		cout << "s4应该是<NULL>，  实际输出：" << s4 << endl;
		cout << "s5应该是<NULL>，  实际输出：" << s5 << endl;

		wait_for_enter();
	}

	if (1) {
		const TString s0 = "teststr1";
		const char* str1 = "teststr2";
		const char  str2[] = "teststr3";
		const char* str3 = NULL;
		const char  str4[] = "";
		const TString s1 = s0, s2 = str1, s3 = str2, s4 = str3, s5 = str4;

		cout << "定义对象并初始化测试(TString对象及字符指针、字符数组)" << endl;

		cout << "s1应该是teststr1，实际输出：" << s1 << endl;
		cout << "s2应该是teststr2，实际输出：" << s2 << endl;
		cout << "s3应该是teststr3，实际输出：" << s3 << endl;
		cout << "s4应该是<NULL>，  实际输出：" << s4 << endl;
		cout << "s5应该是<NULL>，  实际输出：" << s5 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1;

		cout << "重载cin测试" << endl;

		cout << "请在键盘上输入Hello" << endl;
		cin >> s1;
		cout << "s1应该是Hello，实际输出：" << s1 << endl;

		cout << "请在键盘上输入Hello 123" << endl;
		cin >> s1;
		cout << "s1应该是Hello，实际输出：" << s1 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1("Hello"), s2;

		cout << "赋值操作测试" << endl;

		cout << "s1应该是Hello， 实际输出：" << s1 << endl;
		
		s2 = s1;
		cout << "s2应该是Hello， 实际输出：" << s2 << endl;

		s1 = "Hi";
		cout << "s1应该是Hi，    实际输出：" << s1 << endl;

		s2 = "";
		cout << "s2应该是<NULL>，实际输出：" << s2 << endl;

		s1 = NULL;
		cout << "s1应该是<NULL>，实际输出：" << s1 << endl;

		s1 = "Hello";
		cout << "s1应该是Hello， 实际输出：" << (s1 = s1) << endl;
		cout << "s1应该是Hello， 实际输出：" << (s1 = s1 = s1 = s1 = s1) << endl;
		cout << "s1应该是Hello， 实际输出：" << (((s1 = s1) = s1) = s1) << endl;

		wait_for_enter();
	}

	if (1) {
		TString s0, s1("tong"), s2("ji"), s3;

		cout << "连接(+)测试(两个TString类)" << endl;

		s3 = s1 + s2;
		cout << "s3应为tongji，实际输出：" << s3 << endl;

		s3 = s2 + s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1 + s0;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s0 + s2;
		cout << "s3应为ji，    实际输出：" << s3 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1("tong"), s2, s3;

		cout << "连接(+)测试(TString类和字符串常量)" << endl;

		s3 = s1 + "ji";
		cout << "s3应为tongji，实际输出：" << s3 << endl;

		s3 = "ji" + s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1 + "";
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s1 + (char*)NULL;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = "" + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = (char*)NULL + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s2 + (char*)NULL;
		cout << "s3应为<NULL>，实际输出：" << s3 << endl;

		s3 = (char*)NULL + s2;
		cout << "s3应为<NULL>，实际输出：" << s3 << endl;

		s3 = s2 + "";
		cout << "s3应为<NULL>，实际输出：" << s3 << endl;

		s3 = "" + s2;
		cout << "s3应为<NULL>，实际输出：" << s3 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1("tong"), s3;
		const char* str1 = "ji", * str2 = "", * str3 = NULL;

		cout << "连接(+)测试(TString类和字符指针)" << endl;

		s3 = s1 + str1;
		cout << "s3应为tongji，实际输出：" << s3 << endl;

		s3 = str1 + s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1 + str2;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = str2 + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s1 + str3;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = str3 + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1("tong"), s3;
		char str1[] = "ji", str2[] = "";

		cout << "连接(+)测试(TString类和字符数组)" << endl;

		s3 = s1 + str1;
		cout << "s3应为tongji，实际输出：" << s3 << endl;

		s3 = str1 + s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1 + str2;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = str2 + s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		wait_for_enter();
	}

	if (1) {
		TString s1("Hello"), s3;
		char c = '!';

		cout << "连接(+)测试(TString类和字符)" << endl;

		s3 = s1 + c;
		cout << "s3应为Hello!，实际输出：" << s3 << endl;

		s3 = c + s1;
		cout << "s3应为!Hello，实际输出：" << s3 << endl;

		s1 = "ello";
		cout << "s3应为Hello!，实际输出：" << 'H' + s1 + c << endl;

		s1 = "hina";
		cout << "s3应为China!，实际输出：" << (s1 = 'C' + s1 + c) << endl;

		wait_for_enter();
	}

	//if (1) {
	//	const TString s1("可"), s3 = "清", s5 = "也";
	//	TString s;
	//	const char* str2 = "以", str4[] = "心";
	//	const char c = '!';

	//	cout << "连接(+)综合测试(TString类和TString类、字符指针、字符数组、字符)" << endl;
	//	s = s1 + str2 + s3 + str4 + s5 + c;
	//	cout << "s应该是可以清心也!，实际输出：" << s << endl;

	//	cout << "s应该是也可以清心!，实际输出：" << (s = s5 + s1 + str2 + s3 + str4[0] + str4[1] + c) << endl;
	//	cout << "s应该是心也可以清!，实际输出：" << (s = str4 + s5 + s1.c_str() + str2 + s3 + c) << endl;
	//	cout << "s应该是清心也可以!，实际输出：" << (s = s3 + str4 + s5 + s1 + str2[0] + &str2[1] + c) << endl;
	//	cout << "s应该是以清心也可!，实际输出：" << (s = str2 + s3 + str4 + s5.c_str() + s1.c_str() + c) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1("tong"), s2 = "ji";
	//	const char* str3 = "tong", str4[] = "ji";

	//	cout << "自连接(+=)简单测试(TString类和TString类、字符指针、字符数组、字符)" << endl;

	//	s1 += s2;
	//	cout << "s1应为tongji，实际输出：" << s1 << endl;

	//	s1 = "tong";
	//	s2 += s1;
	//	cout << "s2应为jitong，实际输出：" << s2 << endl;

	//	s1 = "tong";
	//	s1 += "ji";
	//	cout << "s1应为tongji，实际输出：" << s1 << endl;

	//	s1 = "ji";
	//	s1 += str3;
	//	cout << "s1应为jitong，实际输出：" << s1 << endl;

	//	s1 = "tong";
	//	s1 += str4;
	//	cout << "s1应为tongji，实际输出：" << s1 << endl;

	//	s1 = "tong";
	//	s1 += 'j';
	//	s1 += 'i';
	//	cout << "s1应为tongji，实际输出：" << s1 << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1("可"), s3 = "清", s5 = "也";
	//	TString s;
	//	const char* str2 = "以", str4[] = "心";
	//	const char c = '!';

	//	cout << "自连接(+=)综合测试(TString类和TString类、字符指针、字符数组、字符)" << endl;

	//	s = "1.";
	//	s += s1 + str2 + s3 + str4 + s5 + c;
	//	cout << "s应该是1.可以清心也!，实际输出：" << s << endl;

	//	s = "2.";
	//	cout << "s应该是2.也可以清心!，实际输出：" << (s += s5 + s1 + str2 + s3 + str4[0] + str4[1] + c) << endl;

	//	s = NULL;
	//	cout << "s应该是3.心也可以清!，实际输出：" << ((s = "3.") += str4 + s5 + s1.c_str() + str2 + s3 + c) << endl;

	//	s = NULL;
	//	cout << "s应该是4.清心也可以!，实际输出：" << (((s += "4." + s3) += (str4 + s5)) += (((s1 += str2[0]) += &str2[1]) += c)) << endl;

	//	s = NULL;
	//	s += '5';
	//	s += '.';
	//	s1 = "可";
	//	cout << "s应该是5.以清心也可!，实际输出：" << ((((((s += str2) += s3) += str4) += s5.c_str()) += s1.c_str()) += c) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1("This is a pencil"), s2("is"), s3;

	//	cout << "删除(-)测试(TString类和TString类)" << endl;

	//	cout << "s1应为Th is a pencil，实际输出：" << (s1 = s1 - s2) << endl;
	//	s3 = s1 - s2;
	//	cout << "s3应为Th  a pencil，  实际输出：" << s3 << endl;

	//	s1 = "This is a pencil";
	//	cout << "s1应为Th  a pencil，  实际输出：" << s1 - s2 - s2 - s2 - s2 - s2 << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1("This is a pencil"), s2;
	//	const char* str1 = "is";
	//	const char str2[] = "is";

	//	cout << "删除(-)测试(TString类和char指针及数组)" << endl;

	//	cout << "s1应为Th is a pencil，实际输出：" << (s1 = s1 - str1) << endl;
	//	s2 = s1 - str1;
	//	cout << "s2应为Th  a pencil，  实际输出：" << s2 << endl;

	//	s1 = "This is a pencil";
	//	cout << "s1应为Th is a pencil，实际输出：" << (s1 = s1 - str2) << endl;
	//	s2 = s1 - str2;
	//	cout << "s2应为Th  a pencil，  实际输出：" << s2 << endl;

	//	s1 = "This is a pencil";
	//	cout << "s1应为Th  a pencil，  实际输出：" << s1 - str1 - str1 - str1 - str1 - str1 << endl;

	//	s1 = "This is a pencil";
	//	cout << "s1应为Th  a pencil，  实际输出：" << s1 - str2 - str2 - str2 - str2 - str2 << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1("This is a pencil"), s2;
	//	char c1 = 'i';

	//	cout << "删除(-)测试(TString类和char字符)" << endl;

	//	cout << "s1应为Ths is a pencil，实际输出：" << (s1 = s1 - c1) << endl;
	//	s2 = s1 - c1;
	//	cout << "s2应为Ths s a pencil， 实际输出：" << s2 << endl;

	//	s1 = "This is a pencil";
	//	cout << "s2应为Ths s a pencl，  实际输出：" << (s1 - c1 - c1 - c1 - c1 - c1 - c1 - c1) << endl;

	//	s1 = "This is a pencil";
	//	cout << "s1应为Thi is a pencil，实际输出：" << (s1 = s1 - 's') << endl;
	//	s2 = s1 - 's';
	//	cout << "s2应为Thi i a pencil， 实际输出：" << s2 << endl;

	//	s1 = "This is a pencil";
	//	cout << "s2应为Thi i a pencil， 实际输出：" << (s1 - 's' - 's' - 's' - 's' - 's' - 's') << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1;
	//	const TString s2 = "is";
	//	const char* str3 = "pen", str4[] = "a";
	//	const char c = ' ';

	//	cout << "自删除(-=)简单测试(TString类和TString类、字符指针、字符数组、字符)" << endl;

	//	s1 = "This is a red pencil";
	//	cout << "s1应为Th is a red pencil， 实际输出：" << (s1 -= s2) << endl;

	//	s1 = "This is a red pencil";
	//	cout << "s1应为This is a red cil，  实际输出：" << (s1 -= str3) << endl;

	//	s1 = "This is a red pencil";
	//	cout << "s1应为This is  red pencil，实际输出：" << (s1 -= str4) << endl;

	//	s1 = "This is a red pencil";
	//	cout << "s1应为Thisis a red pencil，实际输出：" << (s1 -= c) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1;
	//	const TString s2 = "is";
	//	const char* str3 = "pen", str4[] = "a";
	//	const char c = ' ';

	//	cout << "自删除(-=)综合测试(TString类和TString类、字符指针、字符数组、字符)" << endl;

	//	s1 = "This is a red pencil";
	//	cout << "s1应为Th  a red pencil，   实际输出：" << ((s1 -= s2) -= s2) << endl;

	//	s1 = "This is a red pencil";
	//	cout << "s1应为This is  red cil，   实际输出：" << ((s1 -= str3) -= str4) << endl;

	//	s1 = "This is a red pencil";
	//	cout << "s1应为Thisisaredpencil，   实际输出：" << ((((s1 -= c) -= c) -= c) -= c) << endl;

	//	s1 = "This is a red pencil";
	//	cout << "s1应为Th，                 实际输出：" << ((((((((((((s1 -= s2) -= s2) -= str3) -= str4) -= c) -= c) -= c) -= c) -= "red") -= 'c') -= 'i') -= 'l') << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1("Hello"), s2;

	//	cout << "复制(*)测试(TString类和int)" << endl;

	//	s2 = s1 * 2;
	//	cout << "s2应为HelloHello，     实际输出：" << s2 << endl;
	//	cout << "s1应为HelloHelloHello，实际输出：" << (s1 = s1 * 3) << endl;

	//	TString s3;
	//	cout << "s3应为<NULL>，         实际输出：" << (s3 * 5) << endl;
	//	cout << "s3应为<NULL>，         实际输出：" << (s3 = s3 * 5) << endl;

	//	int i, n = 100;
	//	s1 = "Hello";
	//	s2 = s1 * n;
	//	for (i = 1; i < n; i++)
	//		s2 = s2 - s1;
	//	cout << "s2应为Hello，          实际输出：" << s2 << endl;

	//	s1 = "Hello";
	//	s2 = s1 * n;
	//	for (i = 0; i < n; i++)
	//		s2 = s2 - 'l';
	//	for (i = 0; i < n; i++)
	//		s2 = s2 - 'l';
	//	for (i = 0; i < n; i++)
	//		s2 = s2 - 'o';
	//	for (i = 0; i < n; i++)
	//		s2 = s2 - 'H';
	//	for (i = 1; i < n; i++)  //注意，只有这个循环是从1开始，少做1次
	//		s2 = s2 - 'e';
	//	cout << "s2应为e，              实际输出：" << s2 << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1;

	//	cout << "自复制(*=)测试(TString类和int)" << endl;

	//	s1 = "Hello";
	//	cout << "s1应为HelloHello，                       实际输出：" << (s1 *= 2) << endl;
	//	s1 += '!';
	//	cout << "s1应为HelloHello!HelloHello!HelloHello!，实际输出：" << (s1 *= 3) << endl;

	//	s1 = "Hello";
	//	cout << "s1应为HelloHello!HelloHello!HelloHello!，实际输出：" << (((s1 *= 2) += '!') *= 3) << endl;

	//	//		特别测试：打开下面这行的注释，期望编译器会报错，如果不报错，说明定义有问题，不符合预期的语义（为什么？仔细想!!!）
	//	//		cout << "s1应为HelloHello!HelloHello!HelloHello!，实际输出：" << (((s1 *= 2) + '!') *= 3) << endl;

	//	s1 = NULL;
	//	cout << "s1应为<NULL>，                           实际输出：" << (s1 *= 100) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1;

	//	cout << "自连接(+=)/自删除(-=)/自复制(*=)综合测试" << endl;

	//	s1 = "Hello";
	//	cout << "s1应为Hello!Hello!Hello!，实际输出：" << ((s1 += '!') *= 3) << endl;

	//	s1 = "Hello";
	//	cout << "s1应为Heo!Heo!Heo!Heo!，  实际输出：" << (((s1 += '!') -= "ll") *= 4) << endl;

	//	s1 = "Hello";
	//	cout << "s1应为HellHello!，        实际输出：" << (((s1 *= 2) -= 'o') += '!') << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1("This is a pencil");

	//	cout << "反转(!)测试" << endl;

	//	cout << " s1应为This is a pencil，实际输出：" << s1 << endl;
	//	cout << "!s1应为licnep a si sihT，实际输出：" << !s1 << endl;
	//	cout << " s1仍为This is a pencil，实际输出：" << s1 << endl;

	//	s1 = NULL;
	//	cout << " s1应为<NULL>，          实际输出：" << s1 << endl;
	//	cout << "!s1应为<NULL>，          实际输出：" << !s1 << endl;
	//	cout << " s1仍为<NULL>，          实际输出：" << s1 << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1 = "house", s2 = "horse", s3 = "house", s4 = "", s5 = NULL;

	//	cout << "比较运算测试(两个TString类)" << endl;

	//	cout << "串1=" << s1 << " 串2=" << s2 << "  > 结果应为1，实际：" << (s1 > s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  >=结果应为1，实际：" << (s1 >= s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  < 结果应为0，实际：" << (s1 < s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  <=结果应为0，实际：" << (s1 <= s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  ==结果应为0，实际：" << (s1 == s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  !=结果应为1，实际：" << (s1 != s2) << endl;

	//	cout << "串1=" << s1 << " 串3=" << s3 << "  > 结果应为0，实际：" << (s1 > s3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << s3 << "  >=结果应为1，实际：" << (s1 >= s3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << s3 << "  < 结果应为0，实际：" << (s1 < s3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << s3 << "  <=结果应为1，实际：" << (s1 <= s3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << s3 << "  ==结果应为1，实际：" << (s1 == s3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << s3 << "  !=结果应为0，实际：" << (s1 != s3) << endl;

	//	cout << "串1=" << s1 << " 串4=" << s4 << " > 结果应为1，实际：" << (s1 > s4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << s4 << " >=结果应为1，实际：" << (s1 >= s4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << s4 << " < 结果应为0，实际：" << (s1 < s4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << s4 << " <=结果应为0，实际：" << (s1 <= s4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << s4 << " ==结果应为0，实际：" << (s1 == s4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << s4 << " !=结果应为1，实际：" << (s1 != s4) << endl;

	//	cout << "串1=" << s1 << " 串5=" << s5 << " > 结果应为1，实际：" << (s1 > s5) << endl;
	//	cout << "串1=" << s1 << " 串5=" << s5 << " >=结果应为1，实际：" << (s1 >= s5) << endl;
	//	cout << "串1=" << s1 << " 串5=" << s5 << " < 结果应为0，实际：" << (s1 < s5) << endl;
	//	cout << "串1=" << s1 << " 串5=" << s5 << " <=结果应为0，实际：" << (s1 <= s5) << endl;
	//	cout << "串1=" << s1 << " 串5=" << s5 << " ==结果应为0，实际：" << (s1 == s5) << endl;
	//	cout << "串1=" << s1 << " 串5=" << s5 << " !=结果应为1，实际：" << (s1 != s5) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1 = "house";

	//	cout << "比较运算测试(TString类和字符串常量)" << endl;

	//	cout << "串1=" << s1 << " 常量=horse" << "  > 结果应为1，实际：" << (s1 > "horse") << endl;
	//	cout << "串1=" << s1 << " 常量=horse" << "  >=结果应为1，实际：" << (s1 >= "horse") << endl;
	//	cout << "串1=" << s1 << " 常量=horse" << "  < 结果应为0，实际：" << (s1 < "horse") << endl;
	//	cout << "串1=" << s1 << " 常量=horse" << "  <=结果应为0，实际：" << (s1 <= "horse") << endl;
	//	cout << "串1=" << s1 << " 常量=horse" << "  ==结果应为0，实际：" << (s1 == "horse") << endl;
	//	cout << "串1=" << s1 << " 常量=horse" << "  !=结果应为1，实际：" << (s1 != "horse") << endl;

	//	cout << "串1=" << s1 << " 常量=house" << "  > 结果应为0，实际：" << (s1 > "house") << endl;
	//	cout << "串1=" << s1 << " 常量=house" << "  >=结果应为1，实际：" << (s1 >= "house") << endl;
	//	cout << "串1=" << s1 << " 常量=house" << "  < 结果应为0，实际：" << (s1 < "house") << endl;
	//	cout << "串1=" << s1 << " 常量=house" << "  <=结果应为1，实际：" << (s1 <= "house") << endl;
	//	cout << "串1=" << s1 << " 常量=house" << "  ==结果应为1，实际：" << (s1 == "house") << endl;
	//	cout << "串1=" << s1 << " 常量=house" << "  !=结果应为0，实际：" << (s1 != "house") << endl;

	//	cout << "串1=" << s1 << " 常量=" << "       > 结果应为1，实际：" << (s1 > "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       >=结果应为1，实际：" << (s1 >= "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       < 结果应为0，实际：" << (s1 < "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       <=结果应为0，实际：" << (s1 <= "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       ==结果应为0，实际：" << (s1 == "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       !=结果应为1，实际：" << (s1 != "") << endl;

	//	cout << "串1=" << s1 << " 常量=<NULL>" << " > 结果应为1，实际：" << (s1 > NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " >=结果应为1，实际：" << (s1 >= NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " < 结果应为0，实际：" << (s1 < NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " <=结果应为0，实际：" << (s1 <= NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " ==结果应为0，实际：" << (s1 == NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " !=结果应为1，实际：" << (s1 != NULL) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1 = NULL, s2 = "";

	//	/* 空的TString和NULL、"" 都认为相等（本质上，NULL是地址，""是串，没有可比性，但是此处做特殊处理） */
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  > 结果应为0，实际：" << (s1 > s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  >=结果应为1，实际：" << (s1 >= s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  < 结果应为0，实际：" << (s1 < s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  <=结果应为1，实际：" << (s1 <= s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  ==结果应为1，实际：" << (s1 == s2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << s2 << "  !=结果应为0，实际：" << (s1 != s2) << endl;

	//	cout << "串1=" << s1 << " 常量=" << "       > 结果应为0，实际：" << (s1 > "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       >=结果应为1，实际：" << (s1 >= "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       < 结果应为0，实际：" << (s1 < "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       <=结果应为1，实际：" << (s1 <= "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       ==结果应为1，实际：" << (s1 == "") << endl;
	//	cout << "串1=" << s1 << " 常量=" << "       !=结果应为0，实际：" << (s1 != "") << endl;

	//	cout << "串1=" << s1 << " 常量=<NULL>" << " > 结果应为0，实际：" << (s1 > NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " >=结果应为1，实际：" << (s1 >= NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " < 结果应为0，实际：" << (s1 < NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " <=结果应为1，实际：" << (s1 <= NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " ==结果应为1，实际：" << (s1 == NULL) << endl;
	//	cout << "串1=" << s1 << " 常量=<NULL>" << " !=结果应为0，实际：" << (s1 != NULL) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1 = "house";
	//	const char* str2 = "horse", * str3 = "house", * str4 = "", * str5 = NULL;

	//	cout << "比较运算测试(TString类和字符指针)" << endl;

	//	cout << "串1=" << s1 << " 串2=" << str2 << "  > 结果应为1，实际：" << (s1 > str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << "  >=结果应为1，实际：" << (s1 >= str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << "  < 结果应为0，实际：" << (s1 < str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << "  <=结果应为0，实际：" << (s1 <= str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << "  ==结果应为0，实际：" << (s1 == str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << "  !=结果应为1，实际：" << (s1 != str2) << endl;

	//	cout << "串1=" << s1 << " 串3=" << str3 << "  > 结果应为0，实际：" << (s1 > str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << "  >=结果应为1，实际：" << (s1 >= str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << "  < 结果应为0，实际：" << (s1 < str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << "  <=结果应为1，实际：" << (s1 <= str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << "  ==结果应为1，实际：" << (s1 == str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << "  !=结果应为0，实际：" << (s1 != str3) << endl;

	//	cout << "串1=" << s1 << " 串4=" << str4 << "       > 结果应为1，实际：" << (s1 > str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "       >=结果应为1，实际：" << (s1 >= str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "       < 结果应为0，实际：" << (s1 < str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "       <=结果应为0，实际：" << (s1 <= str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "       ==结果应为0，实际：" << (s1 == str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "       !=结果应为1，实际：" << (s1 != str4) << endl;

	//	cout << "串1=" << s1 << " 串5=<NULL>" << " > 结果应为1，实际：" << (s1 > str5) << endl;
	//	cout << "串1=" << s1 << " 串5=<NULL>" << " >=结果应为1，实际：" << (s1 >= str5) << endl;
	//	cout << "串1=" << s1 << " 串5=<NULL>" << " < 结果应为0，实际：" << (s1 < str5) << endl;
	//	cout << "串1=" << s1 << " 串5=<NULL>" << " <=结果应为0，实际：" << (s1 <= str5) << endl;
	//	cout << "串1=" << s1 << " 串5=<NULL>" << " ==结果应为0，实际：" << (s1 == str5) << endl;
	//	cout << "串1=" << s1 << " 串5=<NULL>" << " !=结果应为1，实际：" << (s1 != str5) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1 = "house";
	//	char str2[] = "horse", str3[] = "house", str4[] = "";

	//	cout << "比较运算测试(TString类和字符指针)" << endl;

	//	cout << "串1=" << s1 << " 串2=" << str2 << " > 结果应为1，实际：" << (s1 > str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << " >=结果应为1，实际：" << (s1 >= str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << " < 结果应为0，实际：" << (s1 < str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << " <=结果应为0，实际：" << (s1 <= str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << " ==结果应为0，实际：" << (s1 == str2) << endl;
	//	cout << "串1=" << s1 << " 串2=" << str2 << " !=结果应为1，实际：" << (s1 != str2) << endl;

	//	cout << "串1=" << s1 << " 串3=" << str3 << " > 结果应为0，实际：" << (s1 > str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << " >=结果应为1，实际：" << (s1 >= str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << " < 结果应为0，实际：" << (s1 < str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << " <=结果应为1，实际：" << (s1 <= str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << " ==结果应为1，实际：" << (s1 == str3) << endl;
	//	cout << "串1=" << s1 << " 串3=" << str3 << " !=结果应为0，实际：" << (s1 != str3) << endl;

	//	cout << "串1=" << s1 << " 串4=" << str4 << "      > 结果应为1，实际：" << (s1 > str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "      >=结果应为1，实际：" << (s1 >= str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "      < 结果应为0，实际：" << (s1 < str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "      <=结果应为0，实际：" << (s1 <= str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "      ==结果应为0，实际：" << (s1 == str4) << endl;
	//	cout << "串1=" << s1 << " 串4=" << str4 << "      !=结果应为1，实际：" << (s1 != str4) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1 = "tong", s2;

	//	cout << "求长度测试(length()函数)" << endl;

	//	cout << "s1为tong，  长度应为4，实际：" << s1.length() << endl;
	//	cout << "s2为<NULL>，长度应为0，实际：" << s2.length() << endl;
	//	s2 = s1 + "ji";
	//	cout << "s2为tongji，长度应为6，实际：" << s2.length() << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1 = "tong", s2;

	//	cout << "求长度测试(TStringLen()函数)" << endl;

	//	cout << "s1为tong，  长度应为4，实际：" << TStringLen(s1) << endl;
	//	cout << "s2为<NULL>，长度应为0，实际：" << TStringLen(s2) << endl;
	//	cout << "串为tongji，长度应为6，实际：" << TStringLen(s1 + (s2 = "ji")) << endl;
	//	cout << "串为tongji，长度应为6，实际：" << TStringLen(s1 + "ji") << endl;
	//	cout << "串为tongji，长度应为6，实际：" << TStringLen(s2 = s1 + "ji") << endl;
	//	cout << "串为tong，  长度应为4，实际：" << TStringLen(s1 + (char*)NULL) << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	TString s1 = "house";
	//	TString s2[4] = { "yangpu", "sipingroad", "tongji", "shanghai" };
	//	int i, j;
	//	char ch = 'P';

	//	cout << "[]运算符测试" << endl;

	//	cout << "串1是" << s1 << "，依次打印字符的结果是：";
	//	for (i = 0; i < s1.length(); i++)
	//		cout << s1[i] << ' ';
	//	cout << endl << endl;

	//	cout << "串1是" << s1 << "，依次打印字符int值的结果是（有越界）：" << endl;
	//	for (i = -4; i < s1.length() + 4; i++)
	//		cout << int(s1[i]) << ' ';
	//	cout << endl << endl;

	//	s1[0] = s1[0] - 32;
	//	cout << "串1是" << s1 << "，依次打印字符的结果是：";
	//	for (i = 0; i < s1.length(); i++)
	//		cout << s1[i] << ' ';
	//	cout << endl << endl;

	//	s1[1] = 'A';
	//	s1[2] = ch;
	//	ch += 32;
	//	s1[3] = ch;
	//	s1[4] = 'Y';
	//	cout << "串1是" << s1 << "，依次打印字符的结果是：";
	//	for (i = 0; i < s1.length(); i++)
	//		cout << s1[i] << ' ';
	//	cout << endl << endl;

	//	cout << "串2数组是4个字符串，依次打印字符的结果是：" << endl;
	//	for (i = 0; i < 4; i++) {
	//		cout << setw(16) << s2[i] << " => ";
	//		for (j = 0; j < s2[i].length(); j++)
	//			cout << s2[i][j] << ' ';
	//		cout << endl;
	//	}
	//	cout << endl;

	//	cout << "串2数组是4个字符串，首字母大写后依次打印字符的结果是：" << endl;
	//	for (i = 0; i < 4; i++) {
	//		s2[i][0] -= 32;
	//		cout << setw(16) << s2[i] << " => ";
	//		for (j = 0; j < s2[i].length(); j++)
	//			cout << s2[i][j] << ' ';
	//		cout << endl;
	//	}
	//	cout << endl;

	//	wait_for_enter();
	//}

	//if (1) {
	//	memory_speed_test(0);
	//	memory_speed_test(1);
	//}

#if !(defined(__linux) || defined(__linux__))
	system("pause"); //Linux不需要
#endif

	return 0;
}