#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int> q;
	int t;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;
			q.push(n);
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			if (q.size() == 0) { cout << "1" << "\n"; }
			else { cout << "0" << "\n"; }
		}
		else {
			if (q.size() == 0) { cout << "-1" << "\n"; }
			else {
				if (s == "pop") {
					cout << q.front() << "\n";
					q.pop();
				}
				else if (s == "front") { cout << q.front() << "\n"; }
				else if (s == "back") { cout << q.back() << "\n"; }
			}
		}
	}
	return 0;
}