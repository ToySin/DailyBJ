#include <iostream>


void	max(int &a, int &b, int &c)
{
	int	max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	if (a == max)
		a = c;
	if (b == max)
		b = c;
	c = max;
}

int	main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, b, c;

	while (1)
	{
		std::cin >> a >> b >> c;
		if (a == 0)
			break;
		max(a, b, c);
		if (c * c == a * a + b * b)
			std::cout << "right\n";
		else
			std::cout << "wrong\n";
	}
}