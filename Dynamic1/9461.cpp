#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long arr[101];
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 6; i <= N; i++)
			arr[i] = arr[i - 1] + arr[i - 5];
		cout << arr[N] << "\n";
	}
}
