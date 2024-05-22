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
	printf("���������� ɨ����Ϸ����������\n");
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
	printf("���������� ɨ����Ϸ���������� \n");
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
	c = c - 9 * '0';//ת��Ϊ����
	return c;
}

              //����
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
		printf("����Ҫ�Ų������\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= hang && y >= 1 && y <= lie)
		{
			if (show[x][y] != '*')
			{
				printf("�����ظ��Ų�\n");
			}
			else
			{
				//�������
				if (mine[x][y] == '1')
				{
					printf("������\n");
					Display(mine, HANG, LIE);
					break;
				}
				//���������
				else
				{
					win++;
					///pailei(mine, show, x, y);             //���⺯��
					//ͳ��(x,y)��Χ�ж��ٸ���
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//ת���������ַ�
					Display(show, HANG, LIE);
				}
			}
		}
		else
		{
			printf("�����������������������\n");
		}
	}
	if (win == hang * lie - EASY_COUNT)
	{
		printf("WC����nb\n");
		Display(mine, HANG, LIE);
	}
}