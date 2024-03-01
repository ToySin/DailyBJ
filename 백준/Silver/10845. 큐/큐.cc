#include <bits/stdc++.h>
using namespace std;
int N, n;
queue<int> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		string oper;
		cin >> oper;
		if (oper == "push") {
			cin >> n;
			Q.push(n);
		}
		else if (oper == "pop") {
			if (Q.empty())
				cout << -1 << "\n";
			else {
				cout << Q.front() << "\n";
				Q.pop();
			}
		}
		else if (oper == "size") {
			cout << Q.size() << "\n";
		}
		else if (oper == "empty") {
			cout << Q.empty() << "\n";
		}
		else if (oper == "front") {
			if (Q.empty())
				cout << -1 << "\n";
			else
				cout << Q.front() << "\n";
		}
		else if (oper == "back") {
			if (Q.empty())
				cout << -1 << "\n";
			else
				cout << Q.back() << "\n";
		}
	}
}
