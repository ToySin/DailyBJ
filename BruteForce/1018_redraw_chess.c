#include <stdio.h>
#include <stdlib.h>

int main()
{
	int M, N;
	int	**board;

	scanf("%d %d", &M, &N);
	board = (int **)malloc(sizeof(int *) * M);
	for (int i = 0; i < M; i++)
		board[i] = (int *)malloc(sizeof(int) * N);

}
