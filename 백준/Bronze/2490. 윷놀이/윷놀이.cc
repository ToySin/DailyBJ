#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt, tmp;
	string str = "DCBAE";
	for (int i = 0; i < 3; i++) {
		cnt = 0;
		for (int j = 0; j < 4; j++) {
			cin >> tmp;
			cnt += tmp;
		}
		cout << str[cnt] << "\n";
	}
}
