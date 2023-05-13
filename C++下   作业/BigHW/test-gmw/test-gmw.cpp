/* 学号 姓名 班级 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <math.h>
#include <time.h>
#include "../include/cmd_console_tools.h"
#include "../include/cmd_gmw_tools.h"
using namespace std;

/* -----------------------------

    注意：本项(ENABLE_LIB_TGMW_TOOLS)如果打开（置1）
					则本源文件中所有测试用例中的 gmw_* 系列函数，均会使用 lib_tgmw_tools.lib 中已实现的 tgmw_* 系列函数（即老师给出的已实现函数供参考）
          本项(ENABLE_LIB_TGMW_TOOLS)如果关闭（置0）
					则本源文件中所有测试用例中的 gmw_* 系列函数，均会使用 cmd_gmw_tools.cpp 中已实现的 gmw_* 系列函数（目前为空，需要自己实现）

          通过本项的切换，可以灵活的在参考demo和自己实现之间做切换

	最终完成并交作业时，一定要做几件事：
		1、本项(ENABLE_LIB_TGMW_TOOLS)必须置0
		2、从test-gmw项目中移除 lib_tgmw_tools.h 和 lib_tgmw_tools.lib
		3、从对应的 include 目录中删除 lib_tgmw_tools.h
		4、从对应的 lib 目录中删除 lib_tgmw_tools.lib

----------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define ENABLE_LIB_TGMW_TOOLS			 1

#if ENABLE_LIB_TGMW_TOOLS
#include "../include/lib_tgmw_tools.h"
#define gmw_set_rowcol tgmw_set_rowcol
#define gmw_set_color tgmw_set_color
#define gmw_set_font tgmw_set_font
#define gmw_set_delay tgmw_set_delay
#define gmw_set_ext_rowcol tgmw_set_ext_rowcol

#define gmw_set_frame_default_linetype tgmw_set_frame_default_linetype
#define gmw_set_frame_linetype tgmw_set_frame_linetype
#define gmw_set_frame_style tgmw_set_frame_style
#define gmw_set_frame_color tgmw_set_frame_color

#define gmw_set_block_default_linetype tgmw_set_block_default_linetype
#define gmw_set_block_linetype tgmw_set_block_linetype
#define gmw_set_block_border_switch tgmw_set_block_border_switch

#define gmw_set_status_line_switch tgmw_set_status_line_switch
#define gmw_set_status_line_color tgmw_set_status_line_color

#define gmw_set_rowno_switch tgmw_set_rowno_switch
#define gmw_set_colno_switch tgmw_set_colno_switch

#define gmw_init tgmw_init
#define gmw_print tgmw_print

#define gmw_draw_frame tgmw_draw_frame
#define gmw_status_line tgmw_status_line
#define gmw_draw_block tgmw_draw_block
#define gmw_move_block tgmw_move_block
#define gmw_read_keyboard_and_mouse tgmw_read_keyboard_and_mouse
#endif

/***************************************************************************
  函数名称：
  功    能：显示按键继续的信息
  输入参数：
  返 回 值：
  说    明：借用 CONSOLE_GRAPHICS_INFO 结构，定位在下状态栏(x,y)的(0,y+2)位置
***************************************************************************/
static void to_be_continued(const char *prompt, const CONSOLE_GRAPHICS_INFO *const bgi)
{
	if (bgi->inited == CGI_INITED) { //初始化过
		cct_setcolor(bgi->area_bgcolor, bgi->area_fgcolor); //恢复初始颜色

		cct_gotoxy(0, bgi->SLI.lower_start_y + 2);//光标设到指定位置
		cout << setw(bgi->cols - 1) << ' '; //先用空格清空整行

		cct_gotoxy(0, bgi->SLI.lower_start_y + 2);//光标设到指定位置
	}
	else { //未初始化过
		cct_setcolor(); //缺省颜色
		cct_gotoxy(0, 0);//光标设到指定位置
	}

	if (prompt)
		cout << prompt << "，按回车键继续...   ";
	else
		cout << "按回车键继续...   ";

	while (_getch() != '\r')
		;

	return;
}

/***************************************************************************
  函数名称：
  功    能：显示按键继续的信息
  输入参数：
  返 回 值：
  说    明：借用 CONSOLE_GRAPHICS_INFO 结构，定位在下状态栏(x,y)的(0,y+2)位置
***************************************************************************/
static void to_be_continued(const char *game_name, const char *prompt, const CONSOLE_GRAPHICS_INFO *const bgi)
{
	if (bgi->inited == CGI_INITED) { //初始化过
		cct_setcolor(bgi->area_bgcolor, bgi->area_fgcolor); //恢复初始颜色

		cct_gotoxy(0, bgi->SLI.lower_start_y + 2);//光标设到指定位置
		cout << setw(bgi->cols - 1) << ' '; //先用空格清空整行

		cct_gotoxy(0, bgi->SLI.lower_start_y + 2);//光标设到指定位置
		cout << game_name << '-' << (bgi->CFI.separator ? "有" : "无") << "分隔线-" << prompt << "，按回车键继续...";
	}
	else {
		cct_setcolor(); //恢复缺省颜色
		cct_gotoxy(0, 0);//光标设到指定位置
		cout << game_name << '-' << prompt << "，按回车键继续...   ";
	}

	while (_getch() != '\r')
		;

	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_by_fixed(void)
{
	CONSOLE_GRAPHICS_INFO MyCGI; //声明一个CGI变量
	char temp[256];

	/* 先做初始化，这样后续可以在此基础上任意修改部分设置，其余采用预设值
		游戏区域（主框架）为10*10，带分隔线，每个色块的大小为2列*1行，色块不带边框
		窗口背景色黑，前景色白
		字体为点阵，8*16
		画边框及色块时无延时，色块移动时延时3ms
		上下左右辅助区域全部为0
		上状态栏开，正常文本颜色同窗口，醒目文本背景同窗口，前景为亮黄
		下状态栏开，正常文本颜色同窗口，醒目文本背景同窗口，前景为亮黄
		不显示行号
		不显示列标
		游戏区域为双线框，带分隔线，色块大小为2（宽度2列=1个汉字）*1（高度1行），颜色同窗口
		色块为双框线，颜色（未完）		*/
	gmw_init(&MyCGI);

	if (1) {
		/* 显示初始化的框架 */
		gmw_draw_frame(&MyCGI);

		/* 上状态栏显示内容 */
		sprintf(temp, "测试1 - 窗口大小：%d行 %d列", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* 下状态栏显示内容 */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "输入End返回", "本关结束，"); //只是给出提示而已，如果真的想输入End，后续还需要加输入及判断

		to_be_continued("测试1完毕", &MyCGI);
	}

	if (1) {
		/* 为了简化，不检查输入正确性，自行保证 */
		cct_cls();
		int sel;
		cout << "测试2比较耗时，是否进行[0/1] : ";
		cin >> sel;
		if (sel == 1) {
		const int row = 6, col = 7;
		/* 在初始化框架的基础上修改：
			游戏区域大小
			额外行列
			窗口颜色
			字体字号
			每个游戏块的大小
			显示行号
			显示列标
			设置延时	*/
		gmw_set_rowcol(&MyCGI, row, col);					//游戏区域6*7
		gmw_set_ext_rowcol(&MyCGI, 3, 4, 10, 20);				//设置额外行列
		gmw_set_color(&MyCGI, COLOR_BLUE, COLOR_HGREEN);		//修改窗口颜色并级联修改游戏区域、上下状态栏
		gmw_set_font(&MyCGI, "新宋体", 16, 0);				//TrueType字体（新宋体）宽度不需要，可任意设置
		gmw_set_frame_style(&MyCGI, 6, 3, true);				//每个色块区域宽度6列*高度3列，要分隔线
		gmw_set_frame_default_linetype(&MyCGI, 2);			//设置框架线型为预置值2（全部为单线）
		gmw_set_rowno_switch(&MyCGI, true);					//显示行号
		gmw_set_colno_switch(&MyCGI, true);					//显示列标
			gmw_set_delay(&MyCGI, DELAY_OF_DRAW_FRAME, 200);		//画边框的延时
		gmw_set_block_border_switch(&MyCGI, true);			//设置色块需要小边框

		/* 显示框架 */
		gmw_draw_frame(&MyCGI);

		/* 上状态栏显示内容 */
		sprintf(temp, "测试2 - 窗口大小：%d行 %d列", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* 向框架中填充色块 */
		{
			const BLOCK_DISPLAY_INFO bdi[] = {
				{BDI_VALUE_BLANK, -1, -1, "  "},						//0不显示，用空格填充即可
				{1,  COLOR_HBLACK, -1, "〇"},				//如果给出数字1，则显示空心球
				{2,  COLOR_HBLUE, COLOR_HYELLOW, "◎"},	//如果给出数字2，则显示双线空心球
				{3,  COLOR_HCYAN, COLOR_GREEN, "★"},		//如果给出数字3，则显示星
				{4,  COLOR_HRED, -1, NULL},				//如果给出数字4，则直接显示4（NULL表示直接显示数字）
				{BDI_VALUE_END, -1, -1, NULL}			//以BDI_VALUE_END结束，一定要有!!!
			};
				gmw_set_delay(&MyCGI, DELAY_OF_DRAW_BLOCK, 200);		//画色块的延时
			int i, j;
			for (i = 0; i < row; i++)
				for (j = 0; j < col; j++)
						gmw_draw_block(&MyCGI, i, j, (i*row + j) % 5, bdi);
		}

		/* 下状态栏显示内容 */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "输入Quit返回", "显示结束，"); //只是给出提示而已，如果真的想输入Quit，后续还需要加输入及判断

		to_be_continued("测试2完毕", &MyCGI);
		}
	}

	if (1) {
		/* 在上面基础上继续修改：
			游戏区域大小
			字体字号
			窗口颜色
			每个游戏块的大小
			不显示行号
			显示列标
			关闭上状态栏
			延时为0	*/
		gmw_set_rowcol(&MyCGI, 9, 12);								//游戏区域9*12
		gmw_set_font(&MyCGI, "新宋体", 20, 0);						//TrueType字体（新宋体）宽度不需要，可任意设置
		gmw_set_color(&MyCGI);										//恢复缺省色，级联
		gmw_set_frame_style(&MyCGI, 4, 2, true);						//每个色块区域宽度4列*高度2列，要分隔线
		gmw_set_rowno_switch(&MyCGI, false);							//不显示行号
		gmw_set_colno_switch(&MyCGI, true);							//显示列标
		gmw_set_status_line_switch(&MyCGI, TOP_STATUS_LINE, false);	//关闭上状态栏
		gmw_set_delay(&MyCGI, DELAY_OF_DRAW_FRAME, 0);				//不要延时
//		gmw_set_frame_linetype(&MyCGI, "╔", "╚", "╗", "╝", "═", "║", "╦", "╩", "╠", "╣", "╬");		//写在这里只是为了对照下面的设置参数
		gmw_set_frame_linetype(&MyCGI, "计", "算", "机", "系", "═", "║", "大", "佬", "好", "高", "程");	//自定义框架元素
		gmw_set_block_border_switch(&MyCGI);							//设置色块不需要小边框

		/* 显示框架 */
		gmw_draw_frame(&MyCGI);

		/* 上状态栏显示内容 */
		sprintf(temp, "测试3 - 窗口大小：%d行 %d列", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* 下状态栏显示内容 */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "输入Quit返回", "显示结束，"); //只是给出提示而已，如果真的想输入Quit，后续还需要加输入及判断

		to_be_continued("测试3完毕", &MyCGI);
	}

	if (1) {
		/* 在上面基础上继续修改：
			游戏区域大小（特地超过了行号列标的最大可表示范围，观察后面是否是*和**）
			额外行列均为0
			字体字号
			窗口颜色
			每个游戏块的大小
			不显示行号
			显示列标
			开启上状态栏
			关闭下状态栏		*/
		gmw_set_rowcol(&MyCGI, 55, 102);							//游戏区域55*102，特地测试行号列标打印是否正确
		gmw_set_ext_rowcol(&MyCGI, 0, 0, 0, 0);					//设置额外行列
		gmw_set_font(&MyCGI, "新宋体", 12, 0);					//TrueType字体（新宋体）宽度不需要，可任意设置
		gmw_set_color(&MyCGI, COLOR_CYAN, COLOR_HWHITE);			//修改窗口颜色(不级联修改游戏区域、上下状态栏）
		gmw_set_frame_style(&MyCGI, 2, 1, false);					//每个色块区域宽度2列*高度1列，不要分隔线
		gmw_set_rowno_switch(&MyCGI, true);						//开启行号显示
		gmw_set_colno_switch(&MyCGI, true);						//开启列标显示
		gmw_set_status_line_switch(&MyCGI, TOP_STATUS_LINE);		//开启上状态栏
		gmw_set_status_line_color(&MyCGI, TOP_STATUS_LINE, COLOR_HYELLOW, COLOR_BLUE, COLOR_HRED, COLOR_BLUE);		//设置上状态栏颜色
		gmw_set_status_line_switch(&MyCGI, LOWER_STATUS_LINE);	//开启下状态栏
		gmw_set_status_line_color(&MyCGI, LOWER_STATUS_LINE, COLOR_HYELLOW, COLOR_HGREEN, COLOR_HRED, COLOR_HGREEN);		//设置下状态栏颜色

		/* 显示框架 */
		gmw_draw_frame(&MyCGI);

		/* 上状态栏显示内容 */
		sprintf(temp, "测试4 - 窗口大小：%d行 %d列", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* 下状态栏显示内容(此行看不到) */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "输入Q返回", "显示结束，"); //只是给出提示而已，如果真的想输入Q，后续还需要加输入及判断

		to_be_continued("测试4完毕", &MyCGI);
	}

	if (1) {
		/* 在上面基础上继续修改：
			游戏区域大小
			左右额外列均为3
			窗口颜色
			字体字号
			不显示行号
			显示列标
			开启上状态栏
			关闭下状态栏		*/
		gmw_set_rowcol(&MyCGI, 5, 5);								//游戏区域5*5
		gmw_set_ext_rowcol(&MyCGI, 0, 0, 3, 3);						//设置额外行列
		gmw_set_color(&MyCGI, COLOR_CYAN, COLOR_HPINK);				//级联修改颜色（显示区域、状态栏颜色不变）
		gmw_set_font(&MyCGI, "新宋体", 24, 0);						//TrueType字体（新宋体）宽度不需要，可任意设置
		gmw_set_frame_style(&MyCGI, 3, 2, false);						//每个色块区域宽度3列*高度2行，不要分隔线（3会变为4）
		gmw_set_frame_default_linetype(&MyCGI, 1);					//框架元素恢复为双线
		gmw_set_colno_switch(&MyCGI);								//开启列标显示
		gmw_set_status_line_switch(&MyCGI, TOP_STATUS_LINE, false);	//关闭上状态栏
		gmw_set_status_line_color(&MyCGI, TOP_STATUS_LINE);			//设置上状态栏颜色为缺省(虽然不显示)
		gmw_set_status_line_switch(&MyCGI, LOWER_STATUS_LINE);		//开启下状态栏
		gmw_set_status_line_color(&MyCGI, LOWER_STATUS_LINE);		//设置下状态栏颜色为缺省

		/* 显示框架 */
		gmw_draw_frame(&MyCGI);

		/* 上状态栏显示内容 */
		sprintf(temp, "测试5 - 窗口大小：%d行 %d列", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* 下状态栏显示内容(特别提示：此行显示可能会乱，要解决！！！提醒：问题不在此行上） */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "输入Hello返回", "测试结束，"); //只是给出提示而已，如果真的想输入Hello，后续还需要加输入及判断

		to_be_continued("测试5完毕", &MyCGI);
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_by_input(void)
{
	/* 恢复初始颜色并清屏 */
	cct_setfontsize("点阵字体", 16, 8);
	cct_setcolor();
	cct_setconsoleborder(120, 35);
	cct_cls();

	/* 为了简化，不检查输入正确性，自行保证 */
	int sel;
	cout << "是否进行自选测试[0/1] : ";
	cin >> sel;
	if (sel != 1)
		return;

	CONSOLE_GRAPHICS_INFO TestCGI; //声明一个CGI变量(也可以是)
	char temp[256];

	/* 初始化（因为下面的输入涵盖到了全部值，可以不要） */
	gmw_init(&TestCGI);

	/* 下面为了简化，都不检查输入正确性，自行保证 */
	if (1) {
		int row, col;
		cout << "输入游戏色块的行数[1..55] : ";
		cin >> row;
		cout << "输入游戏色块的列数[1..102] : ";
		cin >> col;
		gmw_set_rowcol(&TestCGI, row, col);	//如果row,col的值过大，必须是无分隔线，否则cmd窗口会乱
	}

	if (1) {
		int ext_up_line, ext_down_line, ext_left_cols, ext_right_cols;
		cout << "输入游戏区域的上部预留行数[0..10] : ";
		cin >> ext_up_line;
		cout << "输入游戏区域的下部预留行数[0..10] : ";
		cin >> ext_down_line;
		cout << "输入游戏区域的左边预留列数[0..20] : ";
		cin >> ext_left_cols;
		cout << "输入游戏区域的右边预留列数[0..20] : ";
		cin >> ext_right_cols;
		gmw_set_ext_rowcol(&TestCGI, ext_up_line, ext_down_line, ext_left_cols, ext_right_cols);
	}

	if (1) {
		int bg_color, fg_color;
		cout << "输入窗口背景色[0..15] : ";
		cin >> bg_color;
		cout << "输入窗口前景色[0..15] : ";
		cin >> fg_color;
		gmw_set_color(&TestCGI, bg_color, fg_color);
	}

	if (1) {
		int font_num, font_high, font_width;
		cout << "输入字体[0:点阵 1:新宋体] : ";
		cin >> font_num;
		cout << "输入字体高度[1..36] : ";
		cin >> font_high;
		cout << "输入字体宽度[1..36] : ";
		cin >> font_width;
		if (font_num == 1)
			gmw_set_font(&TestCGI, "新宋体", font_high, font_width);
		else
			gmw_set_font(&TestCGI, "Terminal", font_high, font_width);
	}

	if (1) {
		int draw_border_delay;
		cout << "输入画边框延时[0..1000 单位:ms] : ";
		cin >> draw_border_delay;
		gmw_set_delay(&TestCGI, DELAY_OF_DRAW_FRAME, draw_border_delay);
	}

	if (1) {
		int top_status_line, top_normal_bgcolor, top_normal_fgcolor, top_catchy_bgcolor, top_catchy_fgcolor;
		cout << "是否需要上状态栏[0/1] : ";
		cin >> top_status_line;
		if (top_status_line) {
			cout << "输入上状态栏正常文本背景色[-1..16，-1表示用窗口背景色] : ";
			cin >> top_normal_bgcolor;
			cout << "输入上状态栏正常文本前景色[-1..16，-1表示用窗口前景色] : ";
			cin >> top_normal_fgcolor;
			cout << "输入上状态栏醒目文本背景色[-1..16，-1表示用窗口背景色] : ";
			cin >> top_catchy_bgcolor;
			cout << "输入上状态栏醒目文本背景色[-1..16，-1表示用缺省亮黄] : ";
			cin >> top_catchy_fgcolor;
			gmw_set_status_line_switch(&TestCGI, TOP_STATUS_LINE);
			gmw_set_status_line_color(&TestCGI, TOP_STATUS_LINE, top_normal_bgcolor, top_normal_fgcolor, top_catchy_bgcolor, top_catchy_fgcolor);
		}
		else
			gmw_set_status_line_switch(&TestCGI, TOP_STATUS_LINE, false);
	}

	if (1) {
		int lower_status_line, lower_normal_bgcolor, lower_normal_fgcolor, lower_catchy_bgcolor, lower_catchy_fgcolor;
		cout << "是否需要下状态栏[0/1] : ";
		cin >> lower_status_line;
		if (lower_status_line) {
			cout << "输入下状态栏正常文本背景色[-1..16，-1表示用窗口背景色] : ";
			cin >> lower_normal_bgcolor;
			cout << "输入下状态栏正常文本前景色[-1..16，-1表示用窗口前景色] : ";
			cin >> lower_normal_fgcolor;
			cout << "输入下状态栏醒目文本背景色[-1..16，-1表示用窗口背景色] : ";
			cin >> lower_catchy_bgcolor;
			cout << "输入下状态栏醒目文本背景色[-1..16，-1表示用缺省亮黄] : ";
			cin >> lower_catchy_fgcolor;
			gmw_set_status_line_switch(&TestCGI, LOWER_STATUS_LINE);
			gmw_set_status_line_color(&TestCGI, LOWER_STATUS_LINE, lower_normal_bgcolor, lower_normal_fgcolor, lower_catchy_bgcolor, lower_catchy_fgcolor);
		}
		else
			gmw_set_status_line_switch(&TestCGI, LOWER_STATUS_LINE, false);
	}

	if (1) {
		int rowno, colno;
		cout << "输入是否需要行号[0/1] : ";
		cin >> rowno;
		cout << "输入是否需要列标[0/1] : ";
		cin >> colno;
		gmw_set_rowno_switch(&TestCGI, rowno);
		gmw_set_colno_switch(&TestCGI, colno);

		int def_linetype;
		cout << "输入边框线型[1-全双线 2-全单线 3-横双竖单 4-横单竖双] : ";
		cin >> def_linetype;
		gmw_set_block_default_linetype(&TestCGI, def_linetype);
	}

	if (1) {
		int width, high, separator;
		cout << "输入游戏色块的宽度[偶数2..32] : ";
		cin >> width;
		cout << "输入游戏色块的高度[1..10] : ";
		cin >> high;
		cout << "输入是否需要分隔线[0/1] : ";
		cin >> separator;
		gmw_set_frame_style(&TestCGI, width, high, separator);
	}

	if (1) {
		int border_bg_color, border_fg_color;
		cout << "输入游戏区背景色[-1..16，-1表示用窗口背景色] : ";
		cin >> border_bg_color;
		cout << "输入游戏区前景色[-1..16，-1表示用窗口前景色] : ";
		cin >> border_fg_color;
		gmw_set_frame_color(&TestCGI, border_bg_color, border_bg_color);
	}

	/* 显示初始化的框架 */
	gmw_draw_frame(&TestCGI);

	/* 上状态栏显示内容 */
	sprintf(temp, "自选测试 - 窗口大小：%d行 %d列", TestCGI.lines, TestCGI.cols);
	gmw_status_line(&TestCGI, TOP_STATUS_LINE, temp);

	/* 下状态栏显示内容 */
	gmw_status_line(&TestCGI, LOWER_STATUS_LINE, "输入End返回", "测试结束，"); //只是给出提示而已，如果真的想输入End，后续还需要加输入及判断

	to_be_continued("自选测试完毕", &TestCGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_step_of_color_linez(CONSOLE_GRAPHICS_INFO *pColorLinez_CGI)
{
	const char *gname = "ColorLinez";
	const int row = 8, col = 8;

	/* 预置一个数组，1-7表示7种不同颜色的球，0表示无 */
	int cl[row][col] = {
		{0, 0, 0, 0, 4, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 2, 0, 0, 0, 7, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 3, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 6},
		{0, 1, 0, 0, 0, 5, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};

	/* 定义1-7的数字用何种形式显示在界面上
	   - 注：1、本例采用将“正常+选中”信息放在一个数组中的方法
				1-7表示正常，11-17表示选中
			 2、实际实现中的数组值不要求如此，此处仅仅是为了色块的不同状态的显示
			  3、在 test_magic_ball 中用了另外一种方式表示色块的不同状态，可以对照 */
	const BLOCK_DISPLAY_INFO bdi[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //0不显示，用空格填充即可
		{1,  COLOR_HBLACK, -1, "〇"},	//正常状态数字1所对应的彩球
		{2,  COLOR_YELLOW, -1, "〇"},
		{3,  COLOR_HGREEN, -1, "〇"},
		{4,  COLOR_HCYAN, -1, "〇"},
		{5,  COLOR_HRED, -1, "〇"},
		{6,  COLOR_HPINK, -1, "〇"},
		{7,  COLOR_HYELLOW, -1, "〇"},
		{11, COLOR_HBLACK, -1, "◎"},//选中状态数字1所对应的彩球图案
		{12, COLOR_YELLOW, -1, "◎"},
		{13, COLOR_HGREEN, -1, "◎"},
		{14, COLOR_HCYAN, -1, "◎"},
		{15, COLOR_HRED, -1, "◎"},
		{16, COLOR_HPINK, -1, "◎"},
		{17, COLOR_HYELLOW, -1, "◎"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	const int BDI_NORMAL = 0, BDI_SELECTED = 10;
	char temp[256];
	int i, j;

	/* 按row/col的值重设游戏主区域行列 */
	gmw_set_rowcol(pColorLinez_CGI, row, col);

	/* 显示框架 */
	gmw_draw_frame(pColorLinez_CGI);

	/* 上状态栏显示内容 */
	sprintf(temp, "%s-窗口大小：%d行 %d列", gname, pColorLinez_CGI->lines, pColorLinez_CGI->cols);
	gmw_status_line(pColorLinez_CGI, TOP_STATUS_LINE, temp);

	/* 下状态栏显示内容 */
	gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "输入End返回", "测试结束，"); //只是给出提示而已，如果真的想输入End，后续还需要加输入及判断

	/* 将内部数组展现到屏幕上 */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pColorLinez_CGI, i, j, BDI_NORMAL + cl[i][j], bdi);
		}
	to_be_continued(gname, "初始化完毕", pColorLinez_CGI);

	/* 读鼠标/键盘并根据返回值进行相应的动作
	   注：1、本处约定鼠标右键退出，左键显示<行，列>，实际游戏中，要根据返回的行列进行某种动作（找出相同项、设置选中项、消除等）
           2、本处约定按回车退出，其它显示按键信息，实际游戏中，要根据返回的行列进行某种动作（找出相同项、设置选中项、消除等）
           3、实际游戏中应写为函数 */
	if (pColorLinez_CGI->inited == CGI_INITED) {
		gmw_status_line(pColorLinez_CGI, TOP_STATUS_LINE, "测试键盘/鼠标，右键/回车退出");

		int loop = 1;
		int maction, old_mrow, old_mcol, mrow = -1, mcol = -1;
		int keycode1, keycode2;
		int ret;

		while (loop) {
			old_mrow = mrow;
			old_mcol = mcol;
			ret = gmw_read_keyboard_and_mouse(pColorLinez_CGI, maction, mrow, mcol, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				if (maction == MOUSE_ONLY_MOVED) {
					/* 这时，mrow、mcol肯定跟刚才不同 */

					/* 做一个色块变化（color_linez不是所有位置都有色块，此处直接用3代替），不同游戏此处不同，仅仅是个演示 */

					/* 原色块正常显示 */
					if (old_mrow >=0 && old_mcol>=0)
						gmw_draw_block(pColorLinez_CGI, old_mrow, old_mcol, BDI_NORMAL + cl[old_mrow][old_mcol], bdi);

					/* 新色块亮显（因为不是所有色块都有值，此处用3替代） */
					gmw_draw_block(pColorLinez_CGI, mrow, mcol, BDI_SELECTED + 3, bdi);
				}
				else if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
					/* 下状态栏显示内容 */
					gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[读到右键]", NULL);
					loop = 0;
				}
				else {
					sprintf(temp, "[读到左键] %c行%d列", char('A' + mrow), mcol); //未考虑mrow超过26，mcol超过99的情况，如有需要，请自行处理
					gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, temp);
					loop = 0;
				}
			}
			else { //CCT_KEYBOARD_EVENT - 具体键码含义去读 cmd_console_tools.cpp
				switch (keycode1) {
					case 0x0D:
						/* 下状态栏显示内容 */
						gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[读到回车键]", NULL);
						loop = 0;
						break;
					case 0xE0: //224
						switch (keycode2) {
							case KB_ARROW_UP:
								/* 下状态栏显示内容 */
								gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[读到上箭头]", NULL);
								break;
							case KB_ARROW_DOWN:
								/* 下状态栏显示内容 */
								gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[读到下箭头]", NULL);
								break;
							case KB_ARROW_LEFT:
								/* 下状态栏显示内容 */
								gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[读到左箭头]", NULL);
								break;
							case KB_ARROW_RIGHT:
								/* 下状态栏显示内容 */
								gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[读到右箭头]", NULL);
								break;
						}
						break;
					default:
						sprintf(temp, "[读到键码] %d/%d", keycode1, keycode2);
						gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, temp);
						break;
				}//end of switch
			}//end of else
		}//end of while

		/* 上状态栏恢复原有信息 */
		sprintf(temp, "%s-窗口大小：%d行 %d列", gname, pColorLinez_CGI->lines, pColorLinez_CGI->cols);
		gmw_status_line(pColorLinez_CGI, TOP_STATUS_LINE, temp);

		to_be_continued(gname, "键盘鼠标测试完毕", pColorLinez_CGI);
	}

	/* 将其中的一个球显示为“选中状态” - 注：本例任选了一个球，实际游戏中根据鼠标/键盘动作后确定某个球 */
	gmw_draw_block(pColorLinez_CGI, 2, 2, BDI_SELECTED + cl[2][2], bdi);
	to_be_continued(gname, "选中1球", pColorLinez_CGI);

	/* 移动某个球
	   注：1、本例任选了一个球，实际游戏中根据鼠标/键盘动作后确定某个球
		   2、本例中任选了结束为止，实际游戏中根据鼠标/键盘动作后确定移动到的位置
		   3、本例中未修改内部数组的值，实际游戏中可能需要修改 */
	gmw_set_delay(pColorLinez_CGI, DELAY_OF_BLOCK_MOVED, 200); //设置移动延时
	gmw_move_block(pColorLinez_CGI, 2, 2, BDI_SELECTED + cl[2][2], 0, bdi, UP_TO_DOWN, 3);
	/* 为了后续移动，更新数组的值 */
	cl[2 + 3][2] = cl[2][2];
	cl[2][2] = 0;
	to_be_continued(gname, "向下移动3格", pColorLinez_CGI);

	gmw_move_block(pColorLinez_CGI, 5, 2, BDI_SELECTED + cl[5][2], 0, bdi, LEFT_TO_RIGHT, 2);
	/* 为了后续移动，更新数组的值 */
	cl[5][2 + 2] = cl[5][2];
	cl[5][2] = 0;
	to_be_continued(gname, "向右移动2格", pColorLinez_CGI);

	gmw_move_block(pColorLinez_CGI, 5, 4, BDI_SELECTED + cl[5][4], 0, bdi, DOWN_TO_UP, 3);
	/* 为了后续移动，更新数组的值 */
	cl[5 - 3][4] = cl[5][4];
	cl[5][4] = 0;
	to_be_continued(gname, "向上移动3格", pColorLinez_CGI);

	gmw_move_block(pColorLinez_CGI, 2, 4, BDI_SELECTED + cl[2][4], 0, bdi, RIGHT_TO_LEFT, 2);
	/* 为了后续移动，更新数组的值 */
	cl[2][4 - 2] = cl[2][4];
	cl[2][4] = 0;
	to_be_continued(gname, "向左移动2格", pColorLinez_CGI);

	/* 将其中的一个球“消除”
	   注：1、本例任选了一个球，实际游戏中一次消除5个球
		   2、无动画形式
		   3、未修改内部数组的值   */
	gmw_draw_block(pColorLinez_CGI, 2, 2, 0, bdi);
	to_be_continued(gname, "消除1球", pColorLinez_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_color_linez(void)
{
	CONSOLE_GRAPHICS_INFO ColorLinez_CGI; //声明一个CGI变量

	/*用缺省值初始化（窗口背景黑/前景白，点阵16*8，上下左右无额外行列，上下状态栏均有，无行号/列标，框架线型为双线，色块宽度2/高度1/无小边框，颜色略）*/
	gmw_init(&ColorLinez_CGI);

//	gmw_set_ext_rowcol(&ColorLinez_CGI, 3, 2, 10, 10);						//注：不设置附加区域，可能导致to_be_continued打印为两行，此问题未处理（后面同）
	gmw_set_color(&ColorLinez_CGI, COLOR_BLACK, COLOR_HWHITE);			//整个窗口颜色
	gmw_set_font(&ColorLinez_CGI, "新宋体", 32);							//字体
//	gmw_set_frame_style(&ColorLinez_CGI);									//游戏主区域风格：每个色块宽2高1，有分隔线
	gmw_set_frame_default_linetype(&ColorLinez_CGI, 2);					//游戏主区域线型：单线
	gmw_set_frame_color(&ColorLinez_CGI, COLOR_HWHITE, COLOR_BLACK);		//游戏主区域颜色
//	gmw_set_block_border_switch(&ColorLinez_CGI);							//每个游戏色块/彩球不需要边框
//	gmw_set_status_line_switch(&ColorLinez_CGI, TOP_STATUS_LINE);				//需要上状态栏
//	gmw_set_status_line_switch(&ColorLinez_CGI, LOWER_STATUS_LINE);			//需要下状态栏
	gmw_set_rowno_switch(&ColorLinez_CGI, true);							//显示行号
	gmw_set_colno_switch(&ColorLinez_CGI, true);							//显示列标
	gmw_set_delay(&ColorLinez_CGI, DELAY_OF_BLOCK_MOVED, BLOCK_MOVED_DELAY_MS * 3);//加大延时

	test_step_of_color_linez(&ColorLinez_CGI);

	/* 改为无分隔线，再来一次 */
	gmw_set_frame_style(&ColorLinez_CGI, 2, 1, false);					//游戏主区域风格：每个色块宽2高1，无分隔线
	gmw_set_ext_rowcol(&ColorLinez_CGI, 3, 2, 10, 10);					//附加区域：上2下3，左10右10
	gmw_set_frame_default_linetype(&ColorLinez_CGI, 1);					//游戏主区域线型：双线

	test_step_of_color_linez(&ColorLinez_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_step_of_magic_ball(CONSOLE_GRAPHICS_INFO *pMagicBall_CGI)
{
	const char *gname = "MagicBall";
	const int row = 7, col = 7;

	/* 预置一个数组 */
	int mb[row][col] = {
		{1, 2, 3, 4, 5, 6, 7},
		{2, 3, 4, 5, 6, 8, 1},
		{7, 6, 9, 4, 3, 2, 1},
		{8, 4, 9, 6, 7, 1, 2},
		{4, 5, 6, 7, 3, 1, 2},
		{5, 7, 5, 8, 3, 2, 4},
		{6, 2, 3, 4, 1, 6, 7},
	};

	/* 定义1-9的数字用何种形式显示在界面上
	   - 注：1、本例采用将“正常 + 选中 + 提示可消除 + 爆炸”信息放在四个数组中的方法
			 2、实际实现中的数组值不要求如此，此处仅仅是为了色块的不同状态的显示
			 3、在 test_color_linez 中用了另外一种方式表示色块的不同状态，可以对照 */

	/* 定义1-9的数字用何种形式显示在界面上（正常状态） */
	const BLOCK_DISPLAY_INFO bdi_normal[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //0不显示，用空格填充即可
		{1, COLOR_HBLACK, -1, "〇"},
		{2, COLOR_YELLOW, -1, "〇"},
		{3, COLOR_HGREEN, -1, "〇"},
		{4, COLOR_HCYAN, -1, "〇"},
		{5, COLOR_HRED, -1, "〇"},
		{6, COLOR_HPINK, -1, "〇"},
		{7, COLOR_HYELLOW, -1, "〇"},
		{8, COLOR_CYAN, -1, "〇"},
		{9, COLOR_WHITE, -1, "〇"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	/* 定义1-9的数字用何种形式显示在界面上（选中状态） */
	const BLOCK_DISPLAY_INFO bdi_selected[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //空白
		{1, COLOR_HBLACK, -1, "●"},
		{2, COLOR_YELLOW, -1, "●"},
		{3, COLOR_HGREEN, -1, "●"},
		{4, COLOR_HCYAN, -1, "●"},
		{5, COLOR_HRED, -1, "●"},
		{6, COLOR_HPINK, -1, "●"},
		{7, COLOR_HYELLOW, -1, "●"},
		{8, COLOR_CYAN, -1, "●"},
		{9, COLOR_WHITE, -1, "●"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	/* 定义1-9的数字用何种形式显示在界面上（可消除提示状态） */
	const BLOCK_DISPLAY_INFO bdi_prompt[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //空白
		{1, COLOR_HBLACK, -1, "◎"},
		{2, COLOR_YELLOW, -1, "◎"},
		{3, COLOR_HGREEN, -1, "◎"},
		{4, COLOR_HCYAN, -1, "◎"},
		{5, COLOR_HRED, -1, "◎"},
		{6, COLOR_HPINK, -1, "◎"},
		{7, COLOR_HYELLOW, -1, "◎"},
		{8, COLOR_CYAN, -1, "◎"},
		{9, COLOR_WHITE, -1, "◎"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	/* 定义1-9的数字用何种形式显示在界面上（爆炸/消除状态） */
	const BLOCK_DISPLAY_INFO bdi_exploded[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //空白
		{1, COLOR_HBLACK, -1, "¤"},
		{2, COLOR_YELLOW, -1, "¤"},
		{3, COLOR_HGREEN, -1, "¤"},
		{4, COLOR_HCYAN, -1, "¤"},
		{5, COLOR_HRED, -1, "¤"},
		{6, COLOR_HPINK, -1, "¤"},
		{7, COLOR_HYELLOW, -1, "¤"},
		{8, COLOR_CYAN, -1, "¤"},
		{9, COLOR_WHITE, -1, "¤"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	char temp[256];
	int i, j;

	/* 按row/col的值重设游戏主区域行列 */
	gmw_set_rowcol(pMagicBall_CGI, row, col);

	/* 显示框架 */
	gmw_draw_frame(pMagicBall_CGI);

	/* 上状态栏显示内容 */
	sprintf(temp, "%s-窗口大小：%d行 %d列", gname, pMagicBall_CGI->lines, pMagicBall_CGI->cols);
	gmw_status_line(pMagicBall_CGI, TOP_STATUS_LINE, temp);

	/* 下状态栏显示内容 */
	gmw_status_line(pMagicBall_CGI, LOWER_STATUS_LINE, "输入End返回", "测试结束，"); //只是给出提示而已，如果真的想输入End，后续还需要加输入及判断

	/* 将内部数组展现到屏幕上 */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pMagicBall_CGI, i, j, mb[i][j], bdi_normal);
		}
	to_be_continued(gname, "初始化完毕", pMagicBall_CGI);

	/* 将其中的三个球显示为“可消除状态提示” - 注：本例任选了三个球，实际游戏中按要规则查找后显示 */
	gmw_draw_block(pMagicBall_CGI, 2, 2, mb[2][2], bdi_prompt);
	gmw_draw_block(pMagicBall_CGI, 2, 3, mb[2][3], bdi_prompt);
	gmw_draw_block(pMagicBall_CGI, 2, 4, mb[2][4], bdi_prompt);
	to_be_continued(gname, "将3个球设置为可消除提示", pMagicBall_CGI);

	/* 将其中的三个球显示为“选中状态” - 注：本例任选了三个球，实际游戏中按要规则查找后显示
	   另：本例中仅显示选中状态，未修改内部数组的值 */
	gmw_draw_block(pMagicBall_CGI, 2, 2, mb[2][2], bdi_selected);
	gmw_draw_block(pMagicBall_CGI, 2, 3, mb[2][3], bdi_selected);
	gmw_draw_block(pMagicBall_CGI, 2, 4, mb[2][4], bdi_selected);
	to_be_continued(gname, "将3个球设置为选中", pMagicBall_CGI);

	/* 将其中的三个球“消除【动画形式 - 爆炸+空白】” - 注：本例任选了三个球，实际游戏中按要规则查找后显示
	   另：本例中仅延时消除动画，未修改内部数组的值 */
	for (int k = 0; k < 5; k++) {
		gmw_draw_block(pMagicBall_CGI, 2, 2, mb[2][2], bdi_exploded);
		gmw_draw_block(pMagicBall_CGI, 2, 3, mb[2][3], bdi_exploded);
		gmw_draw_block(pMagicBall_CGI, 2, 4, mb[2][4], bdi_exploded);
		Sleep(50);
		gmw_draw_block(pMagicBall_CGI, 2, 2, 0, bdi_normal); //0是空白
		gmw_draw_block(pMagicBall_CGI, 2, 3, 0, bdi_normal);
		gmw_draw_block(pMagicBall_CGI, 2, 4, 0, bdi_normal);
		Sleep(50);
	}
	to_be_continued(gname, "将3个球消除(动画)", pMagicBall_CGI);

	/* 将上步中消除的三个球的上方球下落
	   注：1、未修改内部数组的值
		   2、未使用循环，直接写了定值 */
	gmw_move_block(pMagicBall_CGI, 1, 2, mb[1][2], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 1, 3, mb[1][3], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 1, 4, mb[1][4], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 0, 2, mb[0][2], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 0, 3, mb[0][3], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 0, 4, mb[0][4], 0, bdi_normal, UP_TO_DOWN, 1);
	to_be_continued(gname, "上方球下落", pMagicBall_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_magic_ball(void)
{
	CONSOLE_GRAPHICS_INFO MagicBall_CGI; //声明一个CGI变量

	/*用缺省值初始化（窗口背景黑/前景白，点阵16*8，上下左右无额外行列，上下状态栏均有，无行号/列标，框架线型为双线，色块宽度2/高度1/无小边框，颜色略）*/
	gmw_init(&MagicBall_CGI);

	gmw_set_ext_rowcol(&MagicBall_CGI, 0, 0, 0, 30);						//右边留30列
	gmw_set_color(&MagicBall_CGI, COLOR_BLACK, COLOR_HWHITE);			//整个窗口颜色
	gmw_set_font(&MagicBall_CGI, "新宋体", 36);							//字体
//	gmw_set_frame_style(&MagicBall_CGI);									//游戏主区域风格：每个色块宽2高1，有分隔线
	gmw_set_frame_default_linetype(&MagicBall_CGI, 4);					//游戏主区域线型：横单竖双
	gmw_set_frame_color(&MagicBall_CGI, COLOR_HWHITE, COLOR_BLACK);		//游戏主区域颜色
	gmw_set_rowno_switch(&MagicBall_CGI, true);							//显示行号
	gmw_set_colno_switch(&MagicBall_CGI, false);							//不显示列标
	gmw_set_status_line_switch(&MagicBall_CGI, TOP_STATUS_LINE, false);	//不需要上状态栏
	gmw_set_status_line_switch(&MagicBall_CGI, LOWER_STATUS_LINE, true);	//需要下状态栏

	test_step_of_magic_ball(&MagicBall_CGI);

	/* 改为无分隔线，再来一次 */
	gmw_set_frame_style(&MagicBall_CGI, 2, 1, false);						//游戏主区域风格：每个色块宽2高1，无分隔线
	gmw_set_ext_rowcol(&MagicBall_CGI, 2, 3, 20, 20);						//上2下3，左20右20
	gmw_set_rowno_switch(&MagicBall_CGI, false);							//不显示行号
	gmw_set_colno_switch(&MagicBall_CGI, true);							//显示列标
	gmw_set_status_line_switch(&MagicBall_CGI, TOP_STATUS_LINE, true);	//需要上状态栏
	gmw_set_status_line_switch(&MagicBall_CGI, LOWER_STATUS_LINE, false);	//不需要下状态栏

	test_step_of_magic_ball(&MagicBall_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_step_of_2048(CONSOLE_GRAPHICS_INFO *pG2048_CGI)
{
	const char *gname = "2048";
	const int row = 6, col = 5;

	/* 预置一个数组 */
	int g2048[row][col] = {
		{0, 0, 0, 0, 0},
		{0, 2, 0, 0, 0},
		{0, 0, 0, 4, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 2, 0, 0, 0},
	};
	int g2048_full[row][col] = {
		{8192, 128, 131072, 256, 512},
		{8, 2, 4096, 1024, 65536},
		{16, 1024, 4, 4, 8192},
		{64, 1024, 512, 256, 4096},
		{2048, 32, 16384, 128, 2048},
		{2, 8, 64, 32768, 16},
	};

	/* 定义2 ~ 131072 的数字用何种形式显示在界面上
	   - 注：1、本例采用将“正常 + 当前 + 当前关联项”信息放在三个数组中的方法
			 2、实际实现中的数组值不要求如此，此处仅仅是为了色块的不同状态的显示 */
	const BLOCK_DISPLAY_INFO bdi_normal[] = {
		{BDI_VALUE_BLANK, -1, -1, NULL},  //0不显示，用空格填充即可
		{2, COLOR_HYELLOW, COLOR_BLACK, NULL},
		{4, COLOR_HRED, COLOR_BLACK, NULL},
		{8, COLOR_GREEN, COLOR_BLACK, NULL},
		{16, COLOR_RED, COLOR_BLACK, NULL},
		{32, COLOR_HGREEN, COLOR_BLACK, NULL},
		{64, COLOR_HYELLOW, COLOR_BLACK, NULL},
		{128, COLOR_HRED, COLOR_BLACK, NULL},
		{256, COLOR_HWHITE, COLOR_BLACK, NULL},
		{512, COLOR_HBLACK, COLOR_BLACK, NULL},
		{1024, COLOR_HPINK, COLOR_BLACK, NULL},
		{2048, COLOR_WHITE, COLOR_BLACK, NULL},
		{4096, COLOR_YELLOW, COLOR_BLACK, NULL},
		{8192, COLOR_PINK, COLOR_BLACK, NULL},
		{16384, COLOR_HBLUE, COLOR_BLACK, NULL},
		{32768, COLOR_HCYAN, COLOR_BLACK, NULL},
		{65536, COLOR_HGREEN, COLOR_BLACK, NULL},
		{131072, COLOR_HPINK, COLOR_BLACK, NULL},  //如果开心，还可以继续加
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};

	char temp[256];
	int i, j;

	/* 按row/col的值重设游戏主区域行列 */
	gmw_set_rowcol(pG2048_CGI, row, col);

	/* 显示框架 */
	gmw_draw_frame(pG2048_CGI);

	/* 上状态栏显示内容 */
	sprintf(temp, "%s-窗口大小：%d行 %d列", gname, pG2048_CGI->lines, pG2048_CGI->cols);
	gmw_status_line(pG2048_CGI, TOP_STATUS_LINE, temp);

	/* 下状态栏显示内容 */
	gmw_status_line(pG2048_CGI, LOWER_STATUS_LINE, "输入End返回", "测试结束，"); //只是给出提示而已，如果真的想输入End，后续还需要加输入及判断

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pG2048_CGI, i, j, g2048_full[i][j], bdi_normal);
		}

	to_be_continued(gname, "全部值显示完毕", pG2048_CGI);

	/* 将内部数组展现到屏幕上 */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pG2048_CGI, i, j, g2048[i][j], bdi_normal);
		}
	to_be_continued(gname, "初始化完毕", pG2048_CGI);

	/* 移动某个球
	   注：1、本例任选了一个数字，实际游戏中根据键盘动作后确定某个色块
		   2、本例中任选了结束位置，实际游戏中根据箭头键方向移动到非0为止 */
	gmw_move_block(pG2048_CGI, 2, 3, g2048[2][3], 0, bdi_normal, UP_TO_DOWN, 2);
	/* 为了后续移动，更新数组的值 */
	g2048[2 + 2][3] = g2048[2][3];
	g2048[2][3] = 0;
	to_be_continued(gname, "向下移动2格", pG2048_CGI);

	gmw_move_block(pG2048_CGI, 4, 3, g2048[4][3], 0, bdi_normal, RIGHT_TO_LEFT, 3);
	/* 为了后续移动，更新数组的值 */
	g2048[4][3 - 3] = g2048[4][3];
	g2048[4][3] = 0;
	to_be_continued(gname, "向左移动3格", pG2048_CGI);

	gmw_move_block(pG2048_CGI, 4, 0, g2048[4][0], 0, bdi_normal, DOWN_TO_UP, 2);
	/* 为了后续移动，更新数组的值 */
	g2048[4 - 2][0] = g2048[4][0];
	g2048[4][0] = 0;
	to_be_continued(gname, "向上移动2格", pG2048_CGI);

	gmw_move_block(pG2048_CGI, 2, 0, g2048[2][0], 0, bdi_normal, LEFT_TO_RIGHT, 3);
	/* 为了后续移动，更新数组的值 */
	g2048[2][0 + 3] = g2048[2][0];
	g2048[2][0] = 0;
	to_be_continued(gname, "向右移动3格", pG2048_CGI);

	/* 模拟一次向下的合并
	   注：1、仅做了相同数字合并的演示，其余未做
		   2、未修改数组的值 */
	gmw_move_block(pG2048_CGI, 1, 1, g2048[1][1], 0, bdi_normal, DOWN_TO_UP, 1);
	gmw_move_block(pG2048_CGI, 5, 1, g2048[5][1], 0, bdi_normal, DOWN_TO_UP, 5); //移动到(0,1)的重合位置
	//移动到重合位置后，用新数字的颜色重画(0,1)
	gmw_draw_block(pG2048_CGI, 0, 1, g2048[1][1] + g2048[5][1], bdi_normal); //未修改数组的值，直接用和进行演示

	gmw_move_block(pG2048_CGI, 2, 3, g2048[2][3], 0, bdi_normal, DOWN_TO_UP, 2);
	to_be_continued(gname, "完成一次向上合并", pG2048_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_2048(void)
{
	CONSOLE_GRAPHICS_INFO G2048_CGI; //声明一个CGI变量

	/*用缺省值初始化（窗口背景黑/前景白，点阵16*8，上下左右无额外行列，上下状态栏均有，无行号/列标，框架线型为双线，色块宽度2/高度1/无小边框，颜色略）*/
	gmw_init(&G2048_CGI);

	gmw_set_color(&G2048_CGI, COLOR_BLACK, COLOR_WHITE);			//整个窗口颜色
	gmw_set_font(&G2048_CGI, "新宋体", 16);						//字体
	gmw_set_frame_style(&G2048_CGI, 10, 5, true);					//游戏主区域风格：每个色块宽10高5，有分隔线【数字色块带边框，宽度为10(放最多6位数字)，高度为5(为了保持色块为方形)】
	gmw_set_frame_color(&G2048_CGI, COLOR_WHITE, COLOR_BLACK);	//游戏主区域颜色
	gmw_set_block_border_switch(&G2048_CGI, true);				//小色块带边框
	gmw_set_rowno_switch(&G2048_CGI, true);						//显示行号
	gmw_set_colno_switch(&G2048_CGI, true);						//显示列标

	test_step_of_2048(&G2048_CGI);

	/* 改为无分隔线，再来一次 */
	gmw_set_font(&G2048_CGI, "Terminal", 16, 8);	//字体
	gmw_set_frame_style(&G2048_CGI, 10, 5, false);//游戏主区域风格：每个色块宽10高5，无分隔线【数字色块带边框，宽度为10(放最多6位数字)，高度为5(为了保持色块为方形)】
	gmw_set_ext_rowcol(&G2048_CGI, 2, 3, 4, 5);	//额外行列：上2下3，左4右5
	gmw_set_rowno_switch(&G2048_CGI, false);		//不显示行号
	gmw_set_colno_switch(&G2048_CGI, false);		//不显示列标

	test_step_of_2048(&G2048_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_step_of_merge_to_10(CONSOLE_GRAPHICS_INFO *pMto10_CGI)
{
	const char *gname = "合成十";
	const int row = 6, col = 5;

	/* 预置一个数组 */
	int mto10[row][col] = {
		{1, 3, 2, 1, 1},
		{3, 1, 3, 2, 2},
		{3, 1, 1, 2, 1},
		{1, 1, 1, 2, 1},
		{2, 3, 2, 3, 3},
		{1, 2, 2, 2, 1}
	};

	/* 定义1 ~ 10 的数字用何种形式显示在界面上
	   - 注：1、本例采用将“正常 + 当前 + 当前关联项”信息放在三个数组中的方法
			 2、实际实现中的数组值不要求如此，此处仅仅是为了色块的不同状态的显示 */
	const BLOCK_DISPLAY_INFO bdi_normal[] = {
		{BDI_VALUE_BLANK, -1, -1, NULL},  //0不显示，用空格填充即可
		{1,  COLOR_BLUE,   COLOR_BLACK,  NULL},	//数字1的“正常”状态
		{2,  COLOR_GREEN,  COLOR_BLACK,  NULL},
		{3,  COLOR_CYAN,   COLOR_BLACK,  NULL},
		{4,  COLOR_RED,    COLOR_BLACK,  NULL},
		{5,  COLOR_PINK,   COLOR_BLACK,  NULL},
		{6,  COLOR_HBLUE,  COLOR_BLACK,  NULL},
		{7,  COLOR_HGREEN, COLOR_BLACK,  NULL},
		{8,  COLOR_HCYAN,  COLOR_BLACK,  NULL},
		{9,  COLOR_HRED,   COLOR_BLACK,  NULL},
		{10, COLOR_HPINK,  COLOR_BLACK,  NULL},	//数字10的“正常”状态，如果需要，还可以继续增加11及以后的数字
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	const BLOCK_DISPLAY_INFO bdi_related[] = {
		{BDI_VALUE_BLANK, -1, -1, NULL},  //0不显示，用空格填充即可
		{1,  COLOR_BLUE,   COLOR_WHITE,  NULL},	//数字1的“可选择+关联”状态
		{2,  COLOR_GREEN,  COLOR_WHITE,  NULL},
		{3,  COLOR_CYAN,   COLOR_WHITE,  NULL},
		{4,  COLOR_RED,    COLOR_WHITE,  NULL},
		{5,  COLOR_PINK,   COLOR_WHITE,  NULL},
		{6,  COLOR_HBLUE,  COLOR_WHITE,  NULL},
		{7,  COLOR_HGREEN, COLOR_WHITE,  NULL},
		{8,  COLOR_HCYAN,  COLOR_WHITE,  NULL},
		{9,  COLOR_HRED,   COLOR_WHITE,  NULL},
		{10, COLOR_HPINK,  COLOR_WHITE,  NULL},	//数字10的“可选择+关联”状态，如果需要，还可以继续增加11及以后的数字
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	const BLOCK_DISPLAY_INFO bdi_selected[] = {
		{BDI_VALUE_BLANK, -1, -1, NULL},  //0不显示，用空格填充即可
		{1, COLOR_BLUE,   COLOR_HWHITE, NULL},	//数字1的“选中”状态
		{2, COLOR_GREEN,  COLOR_HWHITE, NULL},
		{3, COLOR_CYAN,   COLOR_HWHITE, NULL},
		{4, COLOR_RED,    COLOR_HWHITE, NULL},
		{5, COLOR_PINK,   COLOR_HWHITE, NULL},
		{6, COLOR_HBLUE,  COLOR_HWHITE, NULL},
		{7, COLOR_HGREEN, COLOR_HWHITE, NULL},
		{8, COLOR_HCYAN,  COLOR_HWHITE, NULL},
		{9, COLOR_HRED,   COLOR_HWHITE, NULL},
		{10,COLOR_HPINK,  COLOR_HWHITE, NULL},	//数字10的“选中”状态，如果需要，还可以继续增加11及以后的数字
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};

	char temp[256];
	int i, j;

	/* 按row/col的值重设游戏主区域行列 */
	gmw_set_rowcol(pMto10_CGI, row, col);

	/* 显示框架 */
	gmw_draw_frame(pMto10_CGI);

	/* 上状态栏显示内容 */
	sprintf(temp, "%s-窗口大小：%d行 %d列", gname, pMto10_CGI->lines, pMto10_CGI->cols);
	gmw_status_line(pMto10_CGI, TOP_STATUS_LINE, temp);

	/* 下状态栏显示内容 */
	gmw_status_line(pMto10_CGI, LOWER_STATUS_LINE, "输入End返回", "测试结束，"); //只是给出提示而已，如果真的想输入End，后续还需要加输入及判断

	/* 将内部数组展现到屏幕上 */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pMto10_CGI, i, j, mto10[i][j], bdi_normal);
		}
	to_be_continued(gname, "初始化完毕", pMto10_CGI);

	/* 显示一个当前项（模拟鼠标移动/键盘上按箭头键的效果） - 此处随便指定一个，实际游戏中根据键盘或鼠标的操作来选择 */
	gmw_draw_block(pMto10_CGI, 2, 2, mto10[2][2], bdi_related);
	to_be_continued(gname, "当前可选状态", pMto10_CGI);

	/* i=0循环：显示一个选中项及关联项（模拟鼠标左键/回车），此处直接写死坐标，实际游戏中要用查找函数来查找当前选中项值相同的所有相邻项
	   i=1循环：消除选中项及关联项（本例中是将数组值置为0后通过显示数组值的方式显示空白块，其它例子中是不改数组值，直接将参数设为0）*/
	for (i = 0; i < 2; i++) {
		if (i == 1)
			mto10[2][2] = mto10[1][1] = mto10[2][1] = mto10[3][0] = mto10[3][1] = mto10[3][2] = 0; //清空数组值

		gmw_draw_block(pMto10_CGI, 2, 2, mto10[2][2], bdi_selected); //当数组值为0时表示消除
		gmw_draw_block(pMto10_CGI, 1, 1, mto10[1][1], bdi_related);
		gmw_draw_block(pMto10_CGI, 2, 1, mto10[2][1], bdi_related);
		gmw_draw_block(pMto10_CGI, 3, 0, mto10[3][0], bdi_related);
		gmw_draw_block(pMto10_CGI, 3, 1, mto10[3][1], bdi_related);
		gmw_draw_block(pMto10_CGI, 3, 2, mto10[3][2], bdi_related);

		if (i == 0)
			to_be_continued(gname, "显示当前选中及关联项", pMto10_CGI);
		else {
			/* 选中项显示新值 */
			mto10[2][2] = 2; //此处直接写死
			gmw_draw_block(pMto10_CGI, 2, 2, mto10[2][2], bdi_normal);

			to_be_continued(gname, "消除当前选中及关联项", pMto10_CGI);
		}
	}

	/* 将上步中合并的（2,2）色块下落到（3,2） - 其余应下落色块的下落未做，实际程序中按需进行即可
	   注：1、未修改内部数组的值
		   2、未使用循环，直接写了定值 */
	gmw_move_block(pMto10_CGI, 2, 2, mto10[2][2], 0, bdi_normal, UP_TO_DOWN, 1);
	to_be_continued(gname, "下落1个色块完成", pMto10_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_merge_to_10(void)
{
	CONSOLE_GRAPHICS_INFO Mto10_CGI; //声明一个CGI变量

	/*用缺省值初始化（窗口背景黑/前景白，点阵16*8，上下左右无额外行列，上下状态栏均有，无行号/列标，框架线型为双线，色块宽度2/高度1/无小边框，颜色略）*/
	gmw_init(&Mto10_CGI);

	gmw_set_color(&Mto10_CGI, COLOR_BLACK, COLOR_WHITE);
	gmw_set_font(&Mto10_CGI, "Terminal", 16, 8);
	gmw_set_frame_style(&Mto10_CGI, 6, 3, true);	//色块带边框，宽度为6(放最多2位数字)，高度为3(最多放一行)
	gmw_set_frame_color(&Mto10_CGI, COLOR_WHITE, COLOR_BLACK);
	gmw_set_block_border_switch(&Mto10_CGI, true);
	gmw_set_rowno_switch(&Mto10_CGI, true);//显示行号
	gmw_set_colno_switch(&Mto10_CGI, true);//显示列标

	test_step_of_merge_to_10(&Mto10_CGI);

	/* 改为无分隔线，再来一次 */
	gmw_set_font(&Mto10_CGI, "Terminal", 20, 10);
	gmw_set_frame_style(&Mto10_CGI, 6, 3, false);//无分隔线
	gmw_set_ext_rowcol(&Mto10_CGI, 2, 3, 4, 5);	//额外行列：上2下3，左4右5

	test_step_of_merge_to_10(&Mto10_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_step_of_popstar(CONSOLE_GRAPHICS_INFO *pPopStar_CGI)
{
	const char *gname = "PopStar";
	const int row = 8, col = 9;

	/* 预置一个数组 */
	int popstar[row][col] = {
		{1, 2, 1, 3, 5, 2, 5, 5, 4},
		{2, 2, 3, 4, 5, 1, 1, 2, 1},
		{1, 1, 4, 4, 5, 2, 1, 1, 1},
		{2, 2, 5, 4, 3, 3, 2, 3, 4},
		{4, 3, 5, 5, 5, 2, 5, 1, 2},
		{1, 3, 3, 2, 2, 2, 3, 3, 3},
		{5, 4, 2, 2, 3, 3, 3, 1, 2},
		{4, 2, 2, 2, 3, 2, 2, 2, 2}
	};
	int popstar_col_moved[row][col] = {
		{0, 2, 0, 0, 5, 0, 0, 0, 0},
		{0, 2, 0, 0, 5, 0, 0, 0, 0},
		{1, 1, 0, 0, 5, 0, 0, 0, 0},
		{2, 2, 5, 0, 3, 0, 0, 3, 0},
		{4, 3, 5, 0, 5, 0, 0, 1, 0},
		{1, 3, 3, 2, 2, 0, 0, 3, 0},
		{5, 4, 2, 2, 3, 0, 0, 1, 0},
		{4, 2, 2, 2, 3, 0, 0, 2, 0}
	};

	/* 定义0-5的数字用何种形式显示在界面上
	   - 注：1、本例采用将“正常 + 当前 + 当前关联项”信息放在三个数组中的方法
			 2、实际实现中的数组值不要求如此，此处仅仅是为了色块的不同状态的显示 */

	 /* 定义1-5的数字用何种形式显示在界面上（正常状态） */
	const BLOCK_DISPLAY_INFO bdi_normal[] = {
		{0, -1, -1, "  "},  //0不显示，用空格填充即可
		{1, COLOR_HBLUE, COLOR_BLACK, "★"},
		{2, COLOR_HGREEN, COLOR_BLACK, "★"},
		{3, COLOR_HCYAN, COLOR_BLACK, "★"},
		{4, COLOR_HRED, COLOR_BLACK, "★"},
		{5, COLOR_HPINK, COLOR_BLACK, "★"},
		{-999, -1, -1, NULL} //判断结束条件为-999
	};
	/* 定义1-5的数字用何种形式显示在界面上（当前选择项状态+选中后关联项状态） */
	const BLOCK_DISPLAY_INFO bdi_related[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //空白
		{1, COLOR_HBLUE, COLOR_WHITE, "★"},
		{2, COLOR_HGREEN, COLOR_WHITE, "★"},
		{3, COLOR_HCYAN, COLOR_WHITE, "★"},
		{4, COLOR_HRED, COLOR_WHITE, "★"},
		{5, COLOR_HPINK, COLOR_WHITE, "★"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};
	/* 定义1-5的数字用何种形式显示在界面上（选中状态） */
	const BLOCK_DISPLAY_INFO bdi_selected[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //空白
		{1, COLOR_HBLUE, COLOR_HWHITE, "★"},
		{2, COLOR_HGREEN, COLOR_HWHITE, "★"},
		{3, COLOR_HCYAN, COLOR_HWHITE, "★"},
		{4, COLOR_HRED, COLOR_HWHITE, "★"},
		{5, COLOR_HPINK, COLOR_HWHITE, "★"},
		{BDI_VALUE_END, -1, -1, NULL} //判断结束条件为-999
	};

	char temp[256];
	int i, j;

	/* 按row/col的值重设游戏主区域行列 */
	gmw_set_rowcol(pPopStar_CGI, row, col);

	/* 显示框架 */
	gmw_draw_frame(pPopStar_CGI);

	/* 上状态栏显示内容 */
	sprintf(temp, "%s-窗口大小：%d行 %d列", gname, pPopStar_CGI->lines, pPopStar_CGI->cols);
	gmw_status_line(pPopStar_CGI, TOP_STATUS_LINE, temp);

	/* 下状态栏显示内容 */
	gmw_status_line(pPopStar_CGI, LOWER_STATUS_LINE, "输入End返回", "测试结束，"); //只是给出提示而已，如果真的想输入End，后续还需要加输入及判断

	/* 将内部数组展现到屏幕上 */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pPopStar_CGI, i, j, popstar[i][j], bdi_normal);
		}
	to_be_continued(gname, "初始化完毕", pPopStar_CGI);

	/* 显示一个当前项（模拟鼠标移动/键盘上按箭头键的效果） - 此处随便指定一个，实际游戏中根据键盘或鼠标的操作来选择 */
	gmw_draw_block(pPopStar_CGI, 4, 4, popstar[4][4], bdi_related);
	to_be_continued(gname, "当前选项状态", pPopStar_CGI);

	/* 显示一个选中项及关联项（模拟鼠标左键/回车），此处直接写死坐标，实际游戏中要用查找函数来查找当前选中项值相同的所有相邻项 */
	gmw_draw_block(pPopStar_CGI, 4, 4, popstar[4][4], bdi_selected);
	gmw_draw_block(pPopStar_CGI, 4, 3, popstar[4][3], bdi_related);
	gmw_draw_block(pPopStar_CGI, 4, 2, popstar[4][2], bdi_related);
	gmw_draw_block(pPopStar_CGI, 3, 2, popstar[3][2], bdi_related);
	to_be_continued(gname, "当前选中及关联项显示状态", pPopStar_CGI);

	/* 消除选中项及关联项 - 此处直接写死坐标 */
	gmw_draw_block(pPopStar_CGI, 4, 4, 0, bdi_normal);
	gmw_draw_block(pPopStar_CGI, 4, 3, 0, bdi_normal);
	gmw_draw_block(pPopStar_CGI, 4, 2, 0, bdi_normal);
	gmw_draw_block(pPopStar_CGI, 3, 2, 0, bdi_normal);
	to_be_continued(gname, "消除4项完成", pPopStar_CGI);

	/* 将上步中消除的（2,2）色块下落到（4,2）
	   注：1、未修改内部数组的值
		   2、未使用循环，直接写了定值 */
	gmw_move_block(pPopStar_CGI, 2, 2, popstar[2][2], 0, bdi_normal, UP_TO_DOWN, 2);
	to_be_continued(gname, "下落1个色块完成", pPopStar_CGI);

	/* 演示整列移动(应为函数，此处直接写) */
	{
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++) {
				gmw_draw_block(pPopStar_CGI, i, j, popstar_col_moved[i][j], bdi_normal);
			}
		to_be_continued(gname, "列移动初始化完毕", pPopStar_CGI);

		//如果写为函数，下面两个const都是参数
		const int moved_col_no = 7;
		const int distance = 2;

		for (i = row - 1; i >= 0; i--) {
			if (popstar_col_moved[i][moved_col_no] == 0)
				continue; //空白块不移动
			gmw_move_block(pPopStar_CGI, i, moved_col_no, popstar_col_moved[i][moved_col_no], 0, bdi_normal, RIGHT_TO_LEFT, distance);
			//应修改数组的值，此处略
		}
	}
	to_be_continued(gname, "整列左移2格完毕", pPopStar_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void test_popstar(void)
{
	CONSOLE_GRAPHICS_INFO PopStar_CGI; //声明一个CGI变量

	/*用缺省值初始化（窗口背景黑/前景白，点阵16*8，上下左右无额外行列，上下状态栏均有，无行号/列标，框架线型为双线，色块宽度2/高度1/无小边框，颜色略）*/
	gmw_init(&PopStar_CGI);

	gmw_set_color(&PopStar_CGI, COLOR_BLACK, COLOR_WHITE);
	gmw_set_font(&PopStar_CGI, "Terminal", 16, 8);
	gmw_set_frame_style(&PopStar_CGI, 6, 3, true);	//色块带边框，宽度为6，高度为3
	gmw_set_frame_color(&PopStar_CGI, COLOR_WHITE, COLOR_BLACK);
	gmw_set_block_border_switch(&PopStar_CGI, true);

	test_step_of_popstar(&PopStar_CGI);

	/* 改为无分隔线，再来一次 */
	gmw_set_font(&PopStar_CGI, "新宋体", 20);
	gmw_set_frame_style(&PopStar_CGI, 6, 3, false);
	gmw_set_ext_rowcol(&PopStar_CGI, 2, 3, 4, 5);	//上2下3，左4右5
	gmw_set_rowno_switch(&PopStar_CGI, true);//显示行号
	gmw_set_colno_switch(&PopStar_CGI, true);//显示列标

	test_step_of_popstar(&PopStar_CGI);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	/* 因为引入了 lib_tgmw_tools.lib，此处先检查几个结构体的大小是否符合要求 */
	if (sizeof(STATUS_LINE_INFO) != 120) {
		cout << "STATUS_LINE_INFO 不是120字节，如果使用 lib_tgmw_tools.lib 中的函数则可能出错" << endl;
		return -1;
	}
	if (sizeof(CONSOLE_FRAME_INFO) != 136) {
		cout << "CONSOLE_FRAME_INFO 不是136字节，如果使用 lib_tgmw_tools.lib 中的函数则可能出错" << endl;
		return -1;
	}
	if (sizeof(CONSOLE_BLOCK_INFO) != 84) {
		cout << "CONSOLE_BLOCK_INFO 不是84字节，如果使用 lib_tgmw_tools.lib 中的函数则可能出错" << endl;
		return -1;
	}
	if (sizeof(CONSOLE_GRAPHICS_INFO) != 492) {
		cout << "CONSOLE_GRAPHICS_INFO 不是492字节，如果使用 lib_tgmw_tools.lib 中的函数则可能出错" << endl;
		return -1;
	}

	/* 用固定值测试框架 */
	test_by_fixed();

	/* 用键盘输入值测试框架 */
	test_by_input();

	/* 用 color_linez 来测试游戏区域 */
	test_color_linez();

	/* 用 magic_ball 来测试游戏区域 */
	test_magic_ball();

	/* 用 2048 来测试游戏区域 */
	test_2048();

	/* 用 合成十 来测试游戏区域 */
	test_merge_to_10();

	/* 用 消灭星星 来测试游戏区域 */
	test_popstar();

	cct_setcolor();

	system("pause");

	return 0;
}
