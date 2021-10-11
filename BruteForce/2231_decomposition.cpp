#include <iostream>


int	NumberCount(int n);

int	main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int N;
	int	num_cnt;
	int	pos_max, pos_min;
	int	i, temp;

	std::cin >> N;
	num_cnt = NumberCount(N);
	pos_max = N - 1;
	pos_min = N - 9 * num_cnt;

	for (i = pos_min; i <= pos_max; i++)
	{
		num_cnt = i;
		temp = i;
		while (temp > 0)
		{
			num_cnt += temp % 10;
			temp /= 10;
		}
		if (num_cnt == N)
		{
			std::cout << i;
			break;
		}
	}
	if (i == pos_max + 1)
		std::cout << 0;
	
	return 0;
}

int	NumberCount(int n)
{
	int	cnt = 0;

	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return cnt;
}