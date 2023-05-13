/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS		//使用了VS认为unsafe的函数
#include <iostream>
#include <cstdio>
#include <ctime>
#include <conio.h>	//用getch，因此不需要支持Linux
#include <string.h>	//Dev/CB的strlen需要
using namespace std;

struct tj_time {
	int tj_year;	//表示年份
	int tj_month;	//表示月(1-12)
	int tj_day;	//表示日(1-28/29/30/31)
	int tj_hour;	//表示小时(0-23)
	int tj_minute;	//表示分(0-59)
	int tj_second;	//表示秒(0-59)
};

/* 可以在此定义其它需要的函数 */



/***************************************************************************
  函数名称：
  功    能：给出提示并等待回车键
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //思考一下，||的左右两个条件能否互换
		cout << endl << "按回车键继续";
	else
		cout << endl << prompt << "，按回车键继续";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  函数名称：
  功    能：调用系统的转换函数将整型秒值转换为与本题相似的结构体并输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t的本质是64位无符号整数
{
	struct tm* tt;	//struct tm 为系统定义的结构体

	tt = localtime(&input_time);	//localtime为系统函数

	/* tm_*** 为struct tm中的成员，和本题的struct tj_time具体的内容不完全符合，具体含义自己查找相关资料 */
	cout << tt->tm_year + 1900 << '-' << tt->tm_mon + 1 << '-' << tt->tm_mday << ' ' << tt->tm_hour << ':' << tt->tm_min << ':' << tt->tm_sec << endl;

	return;
}

/***************************************************************************
  函数名称：
  功    能：自定义转换结果输出函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* 实现自定义结构的输出，输出形式与system_time_output相同 */
	cout << tp->tj_year << '-' << tp->tj_month << '-' << tp->tj_day << ' ' << tp->tj_hour << ':' << tp->tj_minute << ':' << tp->tj_second << endl;
}

/***************************************************************************
  函数名称：
  功    能：自定义转换函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//定义静态局部变量，不准动

	/* 实现过程开始，在下面添加相应的定义及执行语句即可 */
	const int tian = 86400;
	int shengyu = input_time % tian;
	int tianshu;
	if (shengyu / 3600 + 8 >= 24)
		tianshu = input_time / tian + 1 + 1;
	else
		tianshu = input_time / tian + 1;
	int run = 0;
	result.tj_year = 1970;
	int num = 365;
	for (; tianshu > num;)
	{
		tianshu = tianshu - num;
		result.tj_year++;
		if (result.tj_year % 400 == 0 || result.tj_year % 4 == 0 && result.tj_year % 100 != 0)
			run = 1;
		else
			run = 0;
		if (run)
			num = 366;
		else
			num = 365;
	}
	int Feb;
	if (run)
		Feb = 29;
	else
		Feb = 28;
	int yuefen[12] = { 31,31 + Feb,62 + Feb,92 + Feb,123 + Feb,153 + Feb,184 + Feb,215 + Feb,245 + Feb,276 + Feb,306 + Feb,337 + Feb };
	int i = 0;
	for (; i < 12; i++)
	{
		if (tianshu <= yuefen[i])
			break;
	}
	result.tj_month = i + 1;
	if (i == 0)
		result.tj_day = tianshu;
	else
		result.tj_day = tianshu - yuefen[i - 1];
	result.tj_hour = (shengyu / 3600 + 8) % 24;
	int qita = shengyu % 3600;
	result.tj_minute = qita / 60;
	result.tj_second = qita % 60;
	/* 实现过程结束 */

	return &result;	//注意，返回的是静态局部变量的地址，本语句不准动
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int test_time[] = { 1, 123456789, 349823021, 987654321, 1202990407, 1216468807, 1250312143, 1272636353, 1326193524, 1336549496, 1392837128, 1625675376, 2052743737 };
	int i;
	struct tj_time* tp;

	for (i = 0; i < sizeof(test_time) / sizeof(int); i++) {
		cout << "秒数            ：" << test_time[i] << endl;
		cout << "系统转换的结果  ：";
		system_time_output(test_time[i]);

		cout << "自定义转换的结果：";
		tp = tj_time_convert(test_time[i]);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//系统函数，取当前系统时间（从1970-01-01 00:00:00开始的秒数）

		cout << "当前系统时间    ：" << t << endl;
		cout << "系统转换的结果  ：";
		system_time_output(t);

		cout << "自定义转换的结果：";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}