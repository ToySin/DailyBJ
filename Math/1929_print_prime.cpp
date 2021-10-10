#include <iostream>


int	isPrime(int n)
{
	int	i = 2;

	if (n < 2)
		return 0;
	while (i * i <= n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int	main()
{
	int	m, n;

	std::cin >> m >> n;
	while (m <= n)
	{
		if (isPrime(m))
			std::cout << m << std::endl;
		m++;
	}
	return 0;
}