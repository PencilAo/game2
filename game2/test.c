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
	char mine[HANGS][LIES] = { 0 };  //��Ų��úõ��׵���Ϣ
	char show[HANGS][LIES] = { 0 };  //����Ų�����׵���Ϣ
	//��ʼ��mineΪ'0'
	chu_shi_hua(mine, HANGS, LIES,'0');
	//��ʼ��showΪ'*'
	chu_shi_hua(show, HANGS, LIES, '*');
	//��ӡ����
	//Display(mine, HANG, LIE);
	//������
	SetMine(mine, HANG, LIE);
	//Display(mine, HANG, LIE);
	Display(show, HANG, LIE);
	//�Ų���
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
			printf("ɨ��\n");
			game2();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("����������\n");
		}
	} while (input);
	return 0;
}