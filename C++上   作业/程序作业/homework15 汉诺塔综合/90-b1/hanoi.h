/* 1953729 信09 吴浩泽 */
#pragma once

/* -----------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ----------------------------------------- */

int menu();
int end(int);
void input(int*, char*, char*, char*, int);
void hanoi(int n, char src, char tmp, char dst, int num);
void choose(int n, char src, char tmp, char dst, int num);
void first(int n, char src, char dst);
void second(int n, char src, char dst);
void heng(int n, char src, char dst);
void shu(int n, char src, char dst, int num);
void fourth(int n, char src, char dst, int num);
void draw(int n, char src, char dst, int num);
void drawplate(int n, char src, char dst, int num);
void move(int n, char src, char dst, int num);
void eighth(int n, char src, char dst, int num);
void ninth(int n, char src, char tmp, char dst, int num);
void feifa();