#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector<int> v(t, 0);
	vector<int> NGE(t, 0);
	stack<int> s;
	for (int i = 0; i < t; i++) {
		cin >> v[i];
	}
	NGE[t - 1] = -1;
	for (int i = t - 2; i >= 0; i--) {
		if (v[i] < v[i + 1]) s.push(v[i + 1]);
		while (s.size() != 0) {
			if (s.top() > v[i]) {
				NGE[i] = s.top();
				break;
			}
			else {
				s.pop();
			}
		}
		if (s.size() == 0) NGE[i] = -1;
	}
	for (int i = 0; i < t; i++) {
		cout << NGE[i] << " ";
	}
	return 0;
}