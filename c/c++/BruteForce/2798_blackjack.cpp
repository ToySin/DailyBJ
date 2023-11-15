#include <iostream>


int	main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int	N, M;
	int	*arr;
	int	max = 0;

	std::cin >> N >> M;
	arr = new int[N];
	for (int i = 0; i < N; i++)
		std::cin >> arr[i];
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int	sum = arr[i] + arr[j] + arr[k];

				if (max < sum && sum <= M)
					max = sum;
			}
		}
	}
	std::cout << max;
	return 0;
}