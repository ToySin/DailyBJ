#include <iostream>

int cnt_hanoi(int n, int start, int mid, int end)
{
	int	cnt = 0;

	if (n == 1)
		return 1;

	cnt += cnt_hanoi(n - 1, start, end, mid);
	cnt++;
	cnt += cnt_hanoi(n - 1, mid, start, end);

	return cnt;
}

void	hanoi(int n, int start, int mid, int end)
{
	if (n == 1)
		std::cout << start << " " << end << "\n";
	else
	{
		hanoi(n - 1, start, end, mid);
		std::cout << start << " " << end << "\n";
		hanoi(n - 1, mid, start, end);
	}
}

int	main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int	n;

	std::cin >> n;
	std::cout << cnt_hanoi(n, 1, 2, 3) << "\n";
	hanoi(n, 1, 2, 3);

	return 0;
}