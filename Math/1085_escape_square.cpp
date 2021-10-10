#include <iostream>


int	main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	int	x, y;
	int	w, h;

	std::cin >> x >> y >> w >> h;

	int	ver = (x < w - x ? x : w - x);
	int	hor = (y < h - y ? y : h - y);

	std::cout << (ver < hor ? ver : hor);

	return 0;
}