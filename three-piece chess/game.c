#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <stdio.h>
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int n = 0;
		for (n = 0; n < col; n++)
		{
			printf(" %c ", board[i][n]);
			if (n < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (n = 0; n < col; n++)
			{
				printf("---");
				if (n < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家-请输入坐标\n");
	scanf("%d%d", &x, &y);
	while (1)
	{
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标错误，请重新输入\n");
			scanf("%d%d", &x, &y);
		}

	}

}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	
}
//返回1表示棋盘满了 返回0表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && board[i][2] != ' ')
			return board[i][1];
	}//判断行赢
	for (i = 0; i < col; i++)
	{
		if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) && board[2][i] != ' ')
			return board[0][i];
	}//判断列赢
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && board[1][1] != ' ')
		return board[1][1];
	if ((board[2][0] == board[1][1] && board[1][1] == board[0][2]) && board[1][1] != ' ')
		return board[1][1];
	//判断对角线
	if (1 == IsFull(board, ROW, COL))
		return 'q';
	return 'c';
		
}