#include <bits/stdc++.h>
using namespace std;

int N, dup;
long long height, cnt;
stack<pair<int, int>> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		cin >> height;
		dup = 1;
		while (!S.empty() && S.top().first <= height) {
			if (S.top().first == height)
				dup += S.top().second;
			cnt += S.top().second;
			S.pop();
		}
		cnt += !S.empty();
		S.push({height, dup});
		//cout << S.top().first << ", " <<
		//		S.top().second << ":" << cnt << "\n";
	}
	cout << cnt;
}
