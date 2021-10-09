#include <iostream>

using namespace std;

void	MergeSort(int *arr, int start, int end);
void	Merge(int *arr, int start, int end);

int	main()
{
	int	n;
	int	*arr;

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	MergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";

	delete[] arr;
	return 0;
}

void	MergeSort(int *arr, int start, int end)
{
	int	mid = (start + end) / 2;

	if (start < end)
	{
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, start, end);
	}
}

void	Merge(int *arr, int start, int end)
{
	int	*sorted = new int[end - start + 1];
	int	mid = (start + end) / 2;
	int	i, j, k;

	i = start;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	while (i <= mid)
		sorted[k++] = arr[i++];
	while (j <= end)
		sorted[k++] = arr[j++];
	
	i = 0;
	while (i <= end - start)
	{
		arr[start + i] = sorted[i];
		i++;
	}
	delete[] sorted;
}