#define _CRT_SECURE_NO_WARNINGS
#include "game2.h"
#include <time.h>
#include <stdlib.h>
void chu_shi_hua(char qipan[HANGS][LIES], int hangs, int lies,char str)
{
	int i, j;
	for (i = 0; i < hangs; i++)
	{
		for (j = 0; j < lies; j++)
		{
			qipan[i][j] = str;
		}
	}
}
void Display(char qipan[HANGS][LIES], int hang, int lie)
{
	int i, j;
	printf("————— 扫雷游戏—————\n");
	for (j = 0; j <= lie; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= hang; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= lie; j++)
		{
			printf("%c ", qipan[i][j]);
		}
		printf("\n");
	}
	printf("————— 扫雷游戏————— \n");
}
void SetMine(char qipan[HANGS][LIES], int hang, int lie)
{
	int count = EASY_COUNT;
	//1~9
	while (count)
	{
		int x = rand() % hang + 1;
		int y = rand() % lie + 1;
		if (qipan[x][y] == '0')
		{
			qipan[x][y] = '1';
			count--;
		}
	}
}
int get_mine_count(char qipan[HANGS][LIES],int x,int y)
{
	int i, j;
	int c = 0;
	for (i = y - 1; i <= y + 1; i++)
	{
		for (j = x - 1; j <= x + 1; j++)
		{
			c += qipan[j][i];
		}
	}
	c = c - 9 * '0';//转换为数字
	return c;
}

              //问题
//////void pailei(char mine[HANGS][LIES], char show[HANGS][LIES], int x, int y)
//////{
//////	int i, j;
//////	int cou = 1;
//////	for (i = -1; i <= 1; i++)
//////	{
//////		for (j = -1; j <= 1; j++)
//////		{
//////			if (i != 0 || j != 0)
//////			{
//////				if (mine[x + j][y + i] != '0' || mine[x + j][y + i] != ' ')
//////				{
//////					cou = 0;
//////					break;
//////				}
//////			}
//////		}
//////	}
//////	if (cou == 1)
//////	{
//////		for (i = -1; i <= 1; i++)
//////		{
//////			for (j = -1; j <= 1; j++)
//////			{
//////				if (i != 0 || j != 0)
//////				{
//////					show[x + j][y + i] = ' ';
//////					pailei(mine,show,x+j,y+i);
//////				}
//////			}
//////			
//////		}
//////	}
//////}
void Findmine(char mine[HANGS][LIES], char show[HANGS][LIES], int hang, int lie)
{
	int x, y;
	int win = 0;
	while (win<hang * lie - EASY_COUNT)
	{
		printf("输入要排查的坐标\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= hang && y >= 1 && y <= lie)
		{
			if (show[x][y] != '*')
			{
				printf("请勿重复排查\n");
			}
			else
			{
				//如果是雷
				if (mine[x][y] == '1')
				{
					printf("你死了\n");
					Display(mine, HANG, LIE);
					break;
				}
				//如果不是雷
				else
				{
					win++;
					///pailei(mine, show, x, y);             //问题函数
					//统计(x,y)周围有多少个雷
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//转换成数字字符
					Display(show, HANG, LIE);
				}
			}
		}
		else
		{
			printf("输入的坐标有问题重新输入\n");
		}
	}
	if (win == hang * lie - EASY_COUNT)
	{
		printf("WC你真nb\n");
		Display(mine, HANG, LIE);
	}
}