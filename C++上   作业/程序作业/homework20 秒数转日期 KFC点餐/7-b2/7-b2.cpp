/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>
using namespace std;
struct KFC
{
	char alph;
	char str[100];
	double price1;
};
struct SPECIAL
{
	char str1[100];
	char str2[100];
	double price2;
};
int main()
{
	system("mode con cols=120 lines=35");
	const struct KFC list[] =
	{
		{'A', "香辣鸡腿堡",         18},
		{'B', "劲脆鸡腿堡",         18},
		{'C', "新奥尔良烤鸡腿堡",   18.5},
		{'D', "鸡肉火腿帕尼尼",   14.0},
		{'E', "老北京鸡肉卷",       16.5},
		{'F', "川辣嫩牛卷",     19},
		{'G', "吮指原味鸡(1块)",   11.5},
		{'H', "热辣薯片脆皮鸡",   12.5},
		{'I', "新奥尔良烤翅(2块)", 12},
		{'J', "劲爆鸡米花",         10.5},
		{'K', "香辣鸡翅(2块)",     11.0},
		{'L', "热辣香骨鸡(3块)",     11.0},
		{'M', "鲜蔬色拉",           12.5},
		{'N', "薯条(小)",           8},
		{'O', "薯条(中)",           11},
		{'P', "薯条(大)",           13},
		{'Q', "芙蓉蔬荟汤",         8},
		{'R', "原味花筒冰激凌",     6},
		{'S', "醇香土豆泥",         6.5},
		{'T', "香甜粟米棒",         8.0},
		{'U', "葡式蛋挞",           7.5},
		{'V', "百事可乐(小)",       7.0},
		{'W', "百事可乐(中)",       9.5},
		{'X', "百事可乐(大)",       11.5},
		{'Y', "九珍果汁饮料",       12.0},
		{'Z', "纯纯玉米饮",         11.0},
		{'\0', NULL,                0}
	};

	const struct SPECIAL special[] = {
		{"ANV", "香辣鸡腿堡工作日午餐",    22},
		{"BMV", "劲脆鸡腿堡超值套餐",    24},
		{"ABCGGIIKKOUWWW", "超值全家桶", 100},
		{"IIJKRRUWW", "缤纷小吃桶",  65},
		{"JJ","劲爆鸡米花(2份小)",      9.5},
		{NULL, NULL, 0}
	};
	while (1)
	{
		cout << "=============================================================" << endl;
		cout << "                      KFC 2020冬季菜单" << endl;
		cout << "============================================================= " << endl;
		const KFC* p1 = list;
		const SPECIAL* p2 = special;
		for (; (p1->alph) != '\0'; p1++)
		{
			cout << ' ' << p1->alph << ' ';
			cout << setiosflags(ios::left);
			cout << setw(20) << p1->str;
			cout << setw(7) << p1->price1;
			cout << "|   ";
			cout << (++p1)->alph << ' ';
			cout << setw(20) << p1->str;
			cout << setw(5) << p1->price1;
			cout << endl;
		}
		cout << endl << "【优惠信息】：" << endl;
		char shuru[100] = "ANV";
		char* input = shuru;
		for (; p2->price2 != 0; p2++)
		{
			cout << p2->str2;
			cout << "=";
			strcpy(shuru, p2->str1);
			for (input = shuru; *input != '\0'; input++)
			{
				for (p1 = list; p1->alph != *input;)
					p1++;
				char* p = input;
				int n = 1;
				for (p = input + 1; *p == *input; p++)
					n++;
				if (p - input == 1)
					cout << p1->str;
				else
				{
					cout << p1->str << "*" << n;
					input = input + n - 1;
				}
				if (*(input + 1) != '\0')
					cout << "+";
			}
			cout << "=";
			cout << p2->price2 << endl;
		}
		cout << endl << "【输入规则说明】：" << endl;
		cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
		cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl << endl << "请点单:";
		cin >> shuru;
		if (shuru[0] == '0' && shuru[1] == '\0')
			break;
		else
		{
			_strupr(shuru);
			for (input = shuru; *input != '\0'; input++)
			{
				if (*input < 'A' || *input > 'Z')
					break;
			}
			if (*input != '\0')
			{
				cout << "输入错误，按任意键继续." << endl;
				_getch();
			}
			else
			{
				for (input = shuru; *input != '\0'; input++)
					for (char* input1 = input + 1; *input1 != '\0'; input1++)
					{
						if (*input1 < *input)
						{
							int t = *input1;
							*input1 = *input;
							*input = t;
						}
					}
				cout << "您的点餐=";
				double sum = 0;
				for (input = shuru; *input != '\0'; input++)
				{
					for (p1 = list; p1->alph != *input;)
						p1++;
					char* p = input;
					int n = 1;
					for (p = input + 1; *p == *input; p++)
						n++;
					if (p - input == 1)
					{
						cout << p1->str;
						sum = sum + p1->price1;
					}
					else
					{
						cout << p1->str << "*" << n;
						input = input + n - 1;
						sum = sum + p1->price1 * n;
					}
					if (*(input + 1) != '\0')
						cout << "+";
				}
				cout << endl;
				int jishu[26] = {};
				input = shuru;
				for (; *input != '\0'; input++)
				{
					switch (*input)
					{
						case 'A':
							jishu[0]++;
							break;
						case 'B':
							jishu[1]++;
							break;
						case 'C':
							jishu[2]++;
							break;
						case 'G':
							jishu[6]++;
							break;
						case 'I':
							jishu[8]++;
							break;
						case 'J':
							jishu[9]++;
							break;
						case 'K':
							jishu[10]++;
							break;
						case 'M':
							jishu[12]++;
							break;
						case 'N':
							jishu[13]++;
							break;
						case 'O':
							jishu[14]++;
							break;
						case 'R':
							jishu[17]++;
							break;
						case 'U':
							jishu[20]++;
							break;
						case 'V':
							jishu[21]++;
							break;
						case 'W':
							jishu[22]++;
							break;
						default:
							;
					}
				}
				while(jishu[0] > 0 && jishu[13] > 0 && jishu[21] > 0)
				{
					jishu[0]--;
					jishu[13]--;
					jishu[21]--;
					sum = sum - 11;
				}
				while (jishu[1] > 0 && jishu[12] > 0 && jishu[21] > 0)
				{
					jishu[1]--;
					jishu[12]--;
					jishu[21]--;
					sum = sum - 13.5;
				}
				while (jishu[0] > 0 && jishu[1] > 0 && jishu[2] > 0 && jishu[6] > 1 && jishu[8] > 1 && jishu[10] > 1 && jishu[14] > 0 && jishu[20] > 0 && jishu[22] > 2)
				{
					jishu[0]--;
					jishu[1]--;
					jishu[2]--;
					jishu[6] = jishu[6] - 2;
					jishu[8] = jishu[8] - 2;
					jishu[10] = jishu[10] - 2;
					jishu[14]--;
					jishu[20]--;
					jishu[22] = jishu[22] - 3;
					sum = sum - 70.5;
				}
				while (jishu[8] > 1 && jishu[9] > 0 && jishu[10] > 0 && jishu[17] > 1 && jishu[20] > 0 && jishu[22] > 1)
				{
					jishu[8] = jishu[8] - 2;
					jishu[9]--;
					jishu[10]--;
					jishu[17] = jishu[17] - 2;
					jishu[20]--;
					jishu[22] = jishu[22] - 2;
					sum = sum - 19;
				}
				while (jishu[9] > 1)
				{
					jishu[9] = jishu[9] - 2;
					sum = sum - 11.5;
				}
				cout << "共计：" << sum << "元" << endl;
				cout << "点单完成，按任意键继续." << endl;
				_getch();
			}
		}
		system("cls");
	}
	return 0;
}