/* 1953729 –≈09 Œ‚∫∆‘Û */
#pragma once

int menu();
void InputHangLie(int&, int&, int popstar[12][12]);
void InputZuoBiao(int&, int&, int, int);
void OutputDangQianSZ(int, int, int popstar[12][12], int dakai[12][12]);
void OutputGuiBingSZ(int, int, int popstar[12][12], int dakai[12][12]);
void OutputXiaLuoSZ(int, int, int popstar[12][12], int dakai[12][12]);
void XiaLuo(int hang, int lie, int popstar[12][12], int dakai[12][12]);
void OutScore(char fenshu[12][12], int&, int);
void Judge(int&, int&, int, int, int popstar[12][12]);
void kuosan(int, int, int popstar[12][12], int dakai[12][12], char fenshu[12][12]);
int PanDuanEnd(int, int, int popstar[12][12]);
void end(int, int, int);
void kuangjia(int hang, int lie, int popstar[12][12]);
void shubiao(int&, int& alph1, int& alph2, int hang, int lie, int popstar[12][12]);