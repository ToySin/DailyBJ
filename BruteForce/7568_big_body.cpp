#include <iostream>

class Info
{
	public:
		int x;
		int y;
		int rank;
};

int	main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	Info *arr = new Info[N];
	for (int i = 0; i < N; i++)
		std::cin >> arr[i].x >> arr[i].y;

	int cnt;
	for (int i = 0; i < N; i++)
	{
		cnt = 1;
		for (int j = 0; j < N; j++)
			if ((arr[i].x < arr[j].x) && (arr[i].y < arr[j].y))
				cnt++;
		arr[i].rank = cnt;
	}

	for (int i = 0; i < N; i++)
		std::cout << arr[i].rank << " ";

	return 0;
}