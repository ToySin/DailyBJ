#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	int *arr = new int[N];
	for (int i = 0; i < N; i++) std::cin >> arr[i];

	int *count_arr = new int[10001];
	for (int i = 0; i < 10001; i++) count_arr[i] = 0;

	for (int i = 0; i < N; i++) count_arr[arr[i]]++;
	
	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < count_arr[i]; j++)
			std::cout << i << "\n";
	
	return 0;
}