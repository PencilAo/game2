#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game2.h"
#include <time.h>
#include <stdlib.h>
void menu()
{
	printf("**********************\n");
	printf("****    1.play    ****\n");
	printf("****    0.exit    ****\n");
	printf("**********************\n");
}
void game2()
{
	char mine[HANGS][LIES] = { 0 };  //存放布置好的雷的信息
	char show[HANGS][LIES] = { 0 };  //存放排查出的雷的信息
	//初始化mine为'0'
	chu_shi_hua(mine, HANGS, LIES,'0');
	//初始化show为'*'
	chu_shi_hua(show, HANGS, LIES, '*');
	//打印棋盘
	//Display(mine, HANG, LIE);
	//设置雷
	SetMine(mine, HANG, LIE);
	//Display(mine, HANG, LIE);
	Display(show, HANG, LIE);
	//排查雷
	Findmine(mine, show, HANG, LIE);
}
int main()
{
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷\n");
			game2();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("请重新输入\n");
		}
	} while (input);
	return 0;
}