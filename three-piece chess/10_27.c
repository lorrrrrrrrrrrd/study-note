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
	//接收判断函数返回值
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//显示目前棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1)
	{
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//输赢判断
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		//输赢判断

	}
	if (IsWin(board, ROW, COL) == '*')
		printf("玩家赢\n");
	else if (IsWin(board,ROW,COL) == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
}