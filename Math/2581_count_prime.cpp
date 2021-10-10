#include <iostream>


int	isPrime(int n);

int	main()
{
	int	m, n;
	int	sum = 0;
	int	flag = -1;

	std::cin >> m >> n;
	while (m <= n)
	{
		if (isPrime(m))
		{
			if (flag == -1)
				flag = m;
			sum += m;
		}
		m++;
	}
	if (sum)
		std::cout << sum << std::endl;
	std::cout << flag;

	return 0;
}

int	isPrime(int n)
{
	unsigned int	i;

	if (n < 2)
		return 0;
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}