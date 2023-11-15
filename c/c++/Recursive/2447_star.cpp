#include <iostream>


void	star(int i, int j, int div, int n);

int	main()
{
	int	n;

	std::cin >> n;
	star(0, 0, n ,n);

	return 0;
}

void	star(int i, int j, int div, int n)
{
	if ((i / div % 3 == 1) && (j / div % 3 == 1))
	{
		std::cout << " ";
		if (j < n - 1)
			star(i, j + 1, n, n);
		else
		{
			std::cout << std::endl;
			if (i < n - 1)
				star(i + 1, 0, n, n);
		}
	}
	else if (div / 3 == 0)
	{
		std::cout << "*";
		if (j < n - 1)
			star(i, j + 1, n, n);
		else
		{
			std::cout << std::endl;
			if (i < n - 1)
				star(i + 1, 0, n, n);
		}
	}
	else
		star(i, j, div / 3, n);
}