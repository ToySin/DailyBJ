#include <iostream>


int	factorial(int n);

int	main()
{
	int	n;

	std::cin >> n;
	std::cout << factorial(n);

	return 0;
}

int	factorial(int n)
{
	if (n < 2)
		return 1;
	return (n * factorial(n - 1));
}