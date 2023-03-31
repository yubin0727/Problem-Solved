#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, l;
	cin >> n >> l;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	deque<pair<int, int>> dq;

	for (int i = 0; i < n; i++) {
		int idx = i;
		int a = v[i];
		if (dq.size() == 0) {
			dq.push_back({ i, a });
		}
		else {
			while (dq.size() > 0 && dq.back().second > a) {
				dq.pop_back();
			}
			dq.push_back({ i, a });
			if (dq.front().first <= i - l) dq.pop_front();
		}
		cout << dq.front().second << " ";
	}
	return 0;
}