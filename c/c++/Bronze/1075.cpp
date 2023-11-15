#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, F;
	int n;
	cin >> N >> F;
	n = ((N / 100) * 100) % F;
	if (n) n = F - n;
	cout << n / 10 << n % 10;
}
