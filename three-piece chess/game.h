#define ROW 3
#define COL 3
#include <stdlib.h>
#include <time.h>
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL], int row , int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);//*.玩家赢 #.电脑赢 c.继续 q.平局
int IsFull(char board[ROW][COL], int row, int col);