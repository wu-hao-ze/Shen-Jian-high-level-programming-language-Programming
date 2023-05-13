/* 1953729 –≈09 Œ‚∫∆‘Û */
#pragma once

struct square
{
	int num;
	int flag;
};

void KuangJia(int hang, int lie, int score, square _2048[8][8]);
void menu(int& hang, int& lie, int& score, int& yanshi);
void color(int num);
void _2048_up(int hang, int lie, int yanshi, square _2048[8][8]);
void _2048_down(int hang, int lie, int yanshi, square _2048[8][8]);
void _2048_left(int hang, int lie, int yanshi, square _2048[8][8]);
void _2048_right(int hang, int lie, int yanshi, square _2048[8][8]);




