#include <iostream>
#include <deque>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	deque<int> dq;
	int t;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		if (s == "push_back") {
			int n;
			cin >> n;
			dq.push_back(n);
		}
		else if (s == "push_front") {
			int n;
			cin >> n;
			dq.push_front(n);
		}
		else if (s == "size") {
			cout << dq.size() << "\n";
		}
		else if (s == "empty") {
			if (dq.size() == 0) { cout << "1" << "\n"; }
			else { cout << "0" << "\n"; }
		}
		else {
			if (dq.size() == 0) { cout << "-1" << "\n"; }
			else {
				if (s == "front") {
					cout << dq.front() << "\n";
				}
				else if (s == "pop_front") {
					cout << dq.front() << "\n";
					dq.pop_front();
				}
				else if (s == "back") {
					cout << dq.back() << "\n";
				}
				else if (s == "pop_back") {
					cout << dq.back() << "\n";
					dq.pop_back();
				}
			}
		}
	}
	return 0;
}