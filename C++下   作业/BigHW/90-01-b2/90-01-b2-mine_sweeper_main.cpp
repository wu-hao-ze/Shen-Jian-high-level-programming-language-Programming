/*1953729 信09 吴浩泽*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "90-01-b2-mine_sweeper.h"
#include "../include/cmd_console_tools.h"
using namespace std;
int main()
{
	cct_setfontsize("新宋体", 24);
	cct_setcolor(0, 7);
	cct_setconsoleborder(100, 30, 100, 30);
	int num = menu();
	int nanduxuanze;
	while (1)
	{
		if (num == 0)
		{
			cout << '0';
			break;
		}
		if (num == 1 || num == 2 || num == 3 || num == 4)
		{
			cct_cls();
			nanduxuanze = nandu();
			cct_cls();
			neibushuzu(nanduxuanze, num);
		}
		if (num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
		{
			cct_cls();
			nanduxuanze = nandu();
			cct_cls();
			weituxing(nanduxuanze, num);
		}		
		end(num, nanduxuanze);
	}
	cout << endl;
	cct_setfontsize("新宋体", 16);
	cct_setconsoleborder(120, 40, 120, 95);
	return 0;
}
