#include <iostream>


int	main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int	T;
	int	x1, y1, r1;
	int	x2, y2, r2;
	int d;
	int add, sub;

	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		std::cin >> x1 >> y1 >> r1;
		std::cin >> x2 >> y2 >> r2;
		d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		add = r1 + r2;
		add = add * add;
		sub = r2 - r1;
		sub = sub * sub;
		if (r1 > r2)
		{
			int	temp = r1;
			r1 = r2;
			r2 = temp;
		}
		if (d == 0)
		{
			if (r1 == r2)
				std::cout << -1;
			else
				std::cout << 0;
		}
		else if (d > add || d < sub)
			std::cout << 0;
		else if (d == add || d == sub)
			std::cout << 1;
		else if (sub < d && d < add)
			std::cout << 2;
		std::cout << "\n";
	}
	return 0;
}