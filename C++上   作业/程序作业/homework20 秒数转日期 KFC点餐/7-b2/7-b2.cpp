/* 1953729 ��09 ����� */
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
		{'A', "�������ȱ�",         18},
		{'B', "���༦�ȱ�",         18},
		{'C', "�°¶��������ȱ�",   18.5},
		{'D', "�������������",   14.0},
		{'E', "�ϱ��������",       16.5},
		{'F', "������ţ��",     19},
		{'G', "˱ָԭζ��(1��)",   11.5},
		{'H', "������Ƭ��Ƥ��",   12.5},
		{'I', "�°¶�������(2��)", 12},
		{'J', "�������׻�",         10.5},
		{'K', "��������(2��)",     11.0},
		{'L', "������Ǽ�(3��)",     11.0},
		{'M', "����ɫ��",           12.5},
		{'N', "����(С)",           8},
		{'O', "����(��)",           11},
		{'P', "����(��)",           13},
		{'Q', "ܽ��������",         8},
		{'R', "ԭζ��Ͳ������",     6},
		{'S', "����������",         6.5},
		{'T', "�������װ�",         8.0},
		{'U', "��ʽ��̢",           7.5},
		{'V', "���¿���(С)",       7.0},
		{'W', "���¿���(��)",       9.5},
		{'X', "���¿���(��)",       11.5},
		{'Y', "�����֭����",       12.0},
		{'Z', "����������",         11.0},
		{'\0', NULL,                0}
	};

	const struct SPECIAL special[] = {
		{"ANV", "�������ȱ����������",    22},
		{"BMV", "���༦�ȱ���ֵ�ײ�",    24},
		{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 100},
		{"IIJKRRUWW", "�ͷ�С��Ͱ",  65},
		{"JJ","�������׻�(2��С)",      9.5},
		{NULL, NULL, 0}
	};
	while (1)
	{
		cout << "=============================================================" << endl;
		cout << "                      KFC 2020�����˵�" << endl;
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
		cout << endl << "���Ż���Ϣ����" << endl;
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
		cout << endl << "���������˵������" << endl;
		cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
		cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl << endl << "��㵥:";
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
				cout << "������󣬰����������." << endl;
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
				cout << "���ĵ��=";
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
				cout << "���ƣ�" << sum << "Ԫ" << endl;
				cout << "�㵥��ɣ������������." << endl;
				_getch();
			}
		}
		system("cls");
	}
	return 0;
}