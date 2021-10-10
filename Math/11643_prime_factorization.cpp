#include <iostream>


void	factorization(int n);

int	main()
{
	int	n;

	std::cin >> n;
	factorization(n);

	return 0;
}

void	factorization(int n)
{
	int	prime = 2;

	while (n > 1)
	{
		if (n % prime == 0)
		{
			std::cout << prime << std::endl;
			n /= prime;
		}
		else
			prime++;
	}
}