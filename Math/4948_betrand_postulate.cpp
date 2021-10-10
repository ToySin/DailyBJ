#include <iostream>


bool	*Eratos(int n)
{
	bool	*arr = new bool[2 * n + 1];

	for (int i = 0; i <= 2 * n; i++)
		arr[i] = true;
	arr[1] = false;
	for (int i = 2; i * i <= 2 * n; i++)
	{
		if (arr[i])
			for (int j = i * i; j <= 2 * n; j += i)
				arr[j] = false;
	}

	return arr;
}

int	BetrandPostulate(int n)
{
	bool	*arr = Eratos(2 * n);
	int		cnt = 0;

	for (int i = n + 1; i <= 2 * n; i++)
		if (arr[i])
			cnt++;

	delete[] arr;
	return cnt;
}

int	main()
{
	int	n;

	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	while (n)
	{
		std::cout << BetrandPostulate(n) << '\n';
		std::cin >> n;
	}

	return 0;
}