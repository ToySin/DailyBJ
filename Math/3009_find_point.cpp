#include <iostream>

class Point
{
	public:
		int	x, y;
		Point() {}
		Point(int pos_x, int pos_y) { x = pos_x; y = pos_y;}
		void	PrintPoint() { std::cout << x << " " << y << "\n";}
};

int main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	Point	*arr[4];
	int	x, y;
	int	rare_x, rare_y;

	for (int i = 0; i < 3; i++)
	{
		std::cin >> x >> y;
		arr[i] = new Point(x, y);
	}

	arr[3] = new Point;

	for (int i = 0; i < 3; i++)
	{
		rare_x = arr[i]->x;
		rare_y = arr[i]->y;
		for (int j = 0; j < 3; j++)
		{
			if ((i != j) && (rare_x == arr[j]->x))
				rare_x = 0;
			if ((i != j) && (rare_y == arr[j]->y))
				rare_y = 0;
		}
		if (rare_x)
			arr[3]->x = rare_x;
		if (rare_y)
			arr[3]->y = rare_y;
	}
	arr[3]->PrintPoint();
	for (int i = 0; i < 4; i++)
		delete arr[i];
	return 0;
}