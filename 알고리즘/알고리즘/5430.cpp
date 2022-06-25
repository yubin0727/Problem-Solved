#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> dq;
int front = 1;

void RnD(string s) {
	for (int j = 0; j < s.length(); j++) {
		if (s[j] == 'R') {
			front *= -1;
		}
		else if(s[j] == 'D') {
			if (dq.size() == 0) {
				cout << "error\n";
				return;
			}
			if (front == 1) {
				dq.pop_front();
			}
			else {
				dq.pop_back();
			}
		}
	}
	cout << "[";
	if (front == 1) {
		for (int i = 0; i < dq.size(); i++) {
			if (i != dq.size() - 1) { cout << dq[i] << ","; }
			else { cout << dq[i]; }
		}
	}
	else {
		for (int i = dq.size() - 1; i >= 0; i--) {
			if (i != 0) { cout << dq[i] << ","; }
			else { cout << dq[i]; }
		}
	}
	cout << "]\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, m;
	char c;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		dq.clear();
		front = 1;
		cin >> s;
		cin >> n;
		cin >> c;
		for (int j = 0; j < n; j++) {
			cin >> m;
			dq.push_back(m);
			if (j != n - 1) cin >> c;
		}
		cin >> c;
		RnD(s);
	}
	return 0;
}