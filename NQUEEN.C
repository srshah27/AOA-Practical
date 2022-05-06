#define N 4
#include <stdio.h>
#include <conio.h>

void print(int board[4][4])
{
    int i = 0, j = 0;
    printf("\nThe solution for chess of order %d:\n",N);
	for (i = 0; i < N; i++) {
	printf("     ");
		for (j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
		printf("\n");
}

int isSafe (int board[4][4], int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return 0;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return 0;

	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return 0;

	return 1;
}

int queens_n(int board[4][4], int col)
{
	int i = 0;
	if (col >= N)
		return 1;

	for (i = 0; i < N; i++) {
		if (isSafe(board, i, col))
		{
			board[i][col] = 1;

			if (queens_n(board, col + 1))
				return 1;

			board[i][col] = 0; // BACKTRACK
		}
	}

	return 0;
}

int queens()
{
	int board[N][N] = { 	{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 } };

	if (queens_n(board, 0) == 0) {
		printf("Solution does not exist");
		return 0;
	}

	print(board);
	return 1;
}

int main()
{
	clrscr();
	queens();
	getch();
	return 0;
}
