#include <iostream>


void	Eratos(bool *arr, int n)
{
	arr[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (arr[i])
			for (int j = i * i; j <= n; j += i)
				arr[j] = false;
	}
}

int	main()
{
	int	m, n;
	bool	*arr;

	std::cin >> m >> n;
	arr = new bool[n + 1];
	for (int i = 0; i <= n; i++)
		arr[i] = true;
	Eratos(arr, n);
	for (int i = m; i <= n; i++)
		if (arr[i])
			printf("%d\n", i);
	delete[] arr;
	return 0;
}