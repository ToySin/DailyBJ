#include <iostream>

bool	*Eratos(int n)
{
	bool	*arr = new bool[n + 1];

	for (int i = 0; i <= n; i++)
		arr[i] = true;
	arr[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (arr[i])
			for (int j = i * i; j <= n; j += i)
				arr[j] = false;
	}
	return arr;
}

void	Goldbach(int n)
{
	bool	*arr = Eratos(n);
	int		max = 0;

	for (int i = 2; i * 2 <= n; i++)
	{
		if (arr[i] && arr[n - i])
			max = i;
	}
	std::cout << max << " " << n - max;
	delete[] arr;
}


int	main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int	n;
	int	num;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> num;
		Goldbach(num);
		std::cout << '\n';
	}

	return 0;
}