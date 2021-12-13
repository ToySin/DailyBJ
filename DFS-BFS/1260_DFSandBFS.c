#include <stdio.h>
#include <stdlib.h>

int	front = -1;
int	rear = -1;
int	queue[10000];

int	is_empty(void)
{
	return (front == rear);
}

int	enqueue(int V)
{
	rear = (rear + 1) % 10000;
	queue[rear] = V;
	return (queue[rear]);
}

int	dequeue(void)
{
	front = (front + 1) % 10000;
	return (queue[front]);
}

void	BFS(int **adj, int N, int V)
{
	int	visited[N + 1];
	int	curr_V;

	for (int i = 1; i <= N; i++)
		visited[i] = 0;
	enqueue(V);
	while (!is_empty())
	{
		curr_V = dequeue();
		if (visited[curr_V])
			continue ;
		printf("%d ", curr_V);
		visited[curr_V] = 1;
		for (int i = 1; i <= N; i++)
			if (adj[curr_V][i])
				enqueue(i);
	}
}

void	rDFS(int **adj, int *visited, int N, int V)
{
	if (visited[V])
		return ;
	printf("%d ", V);
	visited[V] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (adj[V][i])
			rDFS(adj, visited, N, i);
	}
}

void	DFS(int **adj, int N, int V)
{
	int	visited[N + 1];

	for (int i = 1; i <= N; i++)
		visited[i] = 0;
	rDFS(adj, visited, N, V);
	printf("\n");
}

int	main()
{
	int	**adj_matrix;
	int	N, M, V;
	int	v1, v2;

	scanf("%d %d %d", &N, &M, &V);
	adj_matrix = (int **)malloc(sizeof(int *) * (N + 1));
	for (int i = 1; i <= N; i++)
		adj_matrix[i] = (int *)calloc(N + 1, sizeof(int));
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &v1, &v2);
		adj_matrix[v1][v2] = 1;
		adj_matrix[v2][v1] = 1;
	}
	DFS(adj_matrix, N, V);
	BFS(adj_matrix, N, V);
	for (int i = 1; i <= N; i++)
		free(adj_matrix[i]);
	free(adj_matrix);
	return (0);
}


/*
5 7 1
1 2
1 4
5 1
3 5
4 3
3 1
2 3
*/

/*
8 12 7
1 2
2 4
4 7
3 6
6 1
7 6
7 8
1 3
2 7
1 4
2 5
7 5
*/

/*
6 9 1
3 5
1 3
4 1
2 3
3 4
6 4
3 6
1 2
2 5
*/

/*
8 12 4
1 2
2 4
4 7
3 6
6 1
7 6
7 8
1 3
2 7
1 4
2 5
7 5
*/
