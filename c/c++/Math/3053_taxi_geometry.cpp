#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

int	main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int	r;

	std::cin >> r;
	printf("%.6f\n", r * r * M_PI);
	printf("%.6f\n", r * r * 2.0);

	return 0;
}