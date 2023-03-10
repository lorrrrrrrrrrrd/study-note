#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
void menu()
{
	printf("*******************\n");
	printf("***1.play 0.exit***\n");
	printf("*******************\n");

}
void game()
{
	char ret = 0;
	//�����жϺ�������ֵ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ʾĿǰ����
	DisplayBoard(board,ROW,COL);
	//����
	while (1)
	{
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//��Ӯ�ж�
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		//��Ӯ�ж�

	}
	if (IsWin(board, ROW, COL) == '*')
		printf("���Ӯ\n");
	else if (IsWin(board,ROW,COL) == '#')
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳�");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
}