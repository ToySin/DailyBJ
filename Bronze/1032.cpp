#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	string main_str;
	string temp;
	while (N--) {
		cin >> temp;
		if (main_str.empty()) main_str = temp;
		else {
			for (int i = 0; i < main_str.size(); i++) {
				if (main_str[i] != temp[i])
					main_str[i] = '?';
			}
		}
	}
	cout << main_str;
}
