/* 学号 姓名 班级 */
#pragma once
#include "cmd_gmw_tools.h"

/* ----------------------

       注意：此头文件中定义的 tgmw_* 系列函数声明，实现都在 lib_tgmw_tools.lib 中（源代码不可见）

   -----------------------------------------------------------------------------------------------------------*/

/* 设置整个窗口的某些参数 */
int tgmw_set_rowcol(CONSOLE_GRAPHICS_INFO *const pCGI, const int row, const int col);
int tgmw_set_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int bgcolor = COLOR_BLACK, const int fgcolor = COLOR_WHITE, const bool cascade = true);
int tgmw_set_font(CONSOLE_GRAPHICS_INFO *const pCGI, const char *fontname = "Terminal", const int fs_high = 16, const int fs_width = 8);
int tgmw_set_delay(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const int delay_ms);
int tgmw_set_ext_rowcol(CONSOLE_GRAPHICS_INFO *const pCGI, const int up_lines = 0, const int down_lines = 0, const int left_cols = 0, const int right_cols = 0);

/* 设置整个游戏主框架的参数 */
int tgmw_set_frame_default_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const int type);
int tgmw_set_frame_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const char *top_left = "╔", const char *lower_left = "╚", const char *top_right = "╗",
								const char *lower_right = "╝",	const char *h_normal = "═", const char *v_normal = "║", const char *h_top_separator = "╦", 
									const char *h_lower_separator = "╩", const char *v_left_separator = "╠", const char *v_right_separator = "╣", const char *mid_separator = "╬");
int tgmw_set_frame_style(CONSOLE_GRAPHICS_INFO *const pCGI, const int block_width = 2, const int block_high = 1, const bool separator = true);
int tgmw_set_frame_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int bgcolor = -1, const int fgcolor = -1);

/* 设置每个色块的参数 */
int tgmw_set_block_default_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const int def_type);
int tgmw_set_block_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const char *top_left = "╔", const char *lower_left = "╚", const char *top_right = "╗",
								const char *lower_right = "╝", const char *h_normal = "═", const char *v_normal = "║");
int tgmw_set_block_border_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off = false);

/* 设置是否需要上下状态栏及颜色，分开两个函数的目的是color可能在改变整个屏幕颜色是需要级联调用 */
int tgmw_set_status_line_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const bool on_off = true);
int tgmw_set_status_line_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const int normal_bgcolor = -1, const int normal_fgcolor = -1, const int catchy_bgcolor = -1, const int catchy_fgcolor = -1);

/* 设置是否需要行号列标 */
int tgmw_set_rowno_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off = false);
int tgmw_set_colno_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off = false);

/* 用缺省值做一个全局初始化 */
int tgmw_init(CONSOLE_GRAPHICS_INFO *const pCGI, const int row = 10, const int col = 10, const int bgcolor = COLOR_BLACK, const int fgcolor = COLOR_WHITE);
/* 调试用 - 打印 CONSOLE_GRAPHICS_INFO 结构体中的各成员值 */
int tgmw_print(const CONSOLE_GRAPHICS_INFO *const pCGI);

/* 画游戏主框架 */
int tgmw_draw_frame(const CONSOLE_GRAPHICS_INFO *const pCGI);
/* 在上下状态栏上显示信息 */
int tgmw_status_line(const CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const char *msg, const char *catchy_msg = NULL);
/* 画一个色块 */
int tgmw_draw_block(const CONSOLE_GRAPHICS_INFO *const pCGI, const int row_no, const int col_no, const int bdi_value, const BLOCK_DISPLAY_INFO *const bdi);
/* 移动一个色块 */
int tgmw_move_block(const CONSOLE_GRAPHICS_INFO *const pCGI, const int row_no, const int col_no, const int bdi_value, const int blank_bdi_value, const BLOCK_DISPLAY_INFO *const bdi, const int direction, const int distance);
/* 读键盘和鼠标 */
int tgmw_read_keyboard_and_mouse(const CONSOLE_GRAPHICS_INFO *const pCGI, int &MAction, int &MRow, int &MCol, int &KeyCode1, int &KeyCode2, const bool update_lower_status_line = true);
