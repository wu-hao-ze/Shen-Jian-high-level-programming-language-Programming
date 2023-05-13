/* ѧ�� ���� �༶ */
#pragma once
#include "cmd_gmw_tools.h"

/* ----------------------

       ע�⣺��ͷ�ļ��ж���� tgmw_* ϵ�к���������ʵ�ֶ��� lib_tgmw_tools.lib �У�Դ���벻�ɼ���

   -----------------------------------------------------------------------------------------------------------*/

/* �����������ڵ�ĳЩ���� */
int tgmw_set_rowcol(CONSOLE_GRAPHICS_INFO *const pCGI, const int row, const int col);
int tgmw_set_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int bgcolor = COLOR_BLACK, const int fgcolor = COLOR_WHITE, const bool cascade = true);
int tgmw_set_font(CONSOLE_GRAPHICS_INFO *const pCGI, const char *fontname = "Terminal", const int fs_high = 16, const int fs_width = 8);
int tgmw_set_delay(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const int delay_ms);
int tgmw_set_ext_rowcol(CONSOLE_GRAPHICS_INFO *const pCGI, const int up_lines = 0, const int down_lines = 0, const int left_cols = 0, const int right_cols = 0);

/* ����������Ϸ����ܵĲ��� */
int tgmw_set_frame_default_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const int type);
int tgmw_set_frame_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const char *top_left = "�X", const char *lower_left = "�^", const char *top_right = "�[",
								const char *lower_right = "�a",	const char *h_normal = "�T", const char *v_normal = "�U", const char *h_top_separator = "�j", 
									const char *h_lower_separator = "�m", const char *v_left_separator = "�d", const char *v_right_separator = "�g", const char *mid_separator = "�p");
int tgmw_set_frame_style(CONSOLE_GRAPHICS_INFO *const pCGI, const int block_width = 2, const int block_high = 1, const bool separator = true);
int tgmw_set_frame_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int bgcolor = -1, const int fgcolor = -1);

/* ����ÿ��ɫ��Ĳ��� */
int tgmw_set_block_default_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const int def_type);
int tgmw_set_block_linetype(CONSOLE_GRAPHICS_INFO *const pCGI, const char *top_left = "�X", const char *lower_left = "�^", const char *top_right = "�[",
								const char *lower_right = "�a", const char *h_normal = "�T", const char *v_normal = "�U");
int tgmw_set_block_border_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off = false);

/* �����Ƿ���Ҫ����״̬������ɫ���ֿ�����������Ŀ����color�����ڸı�������Ļ��ɫ����Ҫ�������� */
int tgmw_set_status_line_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const bool on_off = true);
int tgmw_set_status_line_color(CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const int normal_bgcolor = -1, const int normal_fgcolor = -1, const int catchy_bgcolor = -1, const int catchy_fgcolor = -1);

/* �����Ƿ���Ҫ�к��б� */
int tgmw_set_rowno_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off = false);
int tgmw_set_colno_switch(CONSOLE_GRAPHICS_INFO *const pCGI, const bool on_off = false);

/* ��ȱʡֵ��һ��ȫ�ֳ�ʼ�� */
int tgmw_init(CONSOLE_GRAPHICS_INFO *const pCGI, const int row = 10, const int col = 10, const int bgcolor = COLOR_BLACK, const int fgcolor = COLOR_WHITE);
/* ������ - ��ӡ CONSOLE_GRAPHICS_INFO �ṹ���еĸ���Աֵ */
int tgmw_print(const CONSOLE_GRAPHICS_INFO *const pCGI);

/* ����Ϸ����� */
int tgmw_draw_frame(const CONSOLE_GRAPHICS_INFO *const pCGI);
/* ������״̬������ʾ��Ϣ */
int tgmw_status_line(const CONSOLE_GRAPHICS_INFO *const pCGI, const int type, const char *msg, const char *catchy_msg = NULL);
/* ��һ��ɫ�� */
int tgmw_draw_block(const CONSOLE_GRAPHICS_INFO *const pCGI, const int row_no, const int col_no, const int bdi_value, const BLOCK_DISPLAY_INFO *const bdi);
/* �ƶ�һ��ɫ�� */
int tgmw_move_block(const CONSOLE_GRAPHICS_INFO *const pCGI, const int row_no, const int col_no, const int bdi_value, const int blank_bdi_value, const BLOCK_DISPLAY_INFO *const bdi, const int direction, const int distance);
/* �����̺���� */
int tgmw_read_keyboard_and_mouse(const CONSOLE_GRAPHICS_INFO *const pCGI, int &MAction, int &MRow, int &MCol, int &KeyCode1, int &KeyCode2, const bool update_lower_status_line = true);
