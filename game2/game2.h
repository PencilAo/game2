#pragma once
#define HANG 9
#define LIE 9
#define HANGS HANG + 2
#define LIES LIE + 2
#define EASY_COUNT 10
void chu_shi_hua(char qipan[HANGS][LIES],int hangs, int lies,char str);
void Display(char qipan[HANGS][LIES],int hang, int lie);
void SetMine(char qipan[HANGS][LIES], int hang, int lie);
void Findmine(char mine[HANGS][LIES], char show[HANGS][LIES],int hang,int lie);