#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int ans = 0;
	cin >> n;
	deque<int> dq(n);
	for (int i = 0; i < n; i++) {
		cin >> dq[i];
	}
	sort(dq.begin(), dq.end(), greater<>());

	while (dq.front() > 1) {
		int a = dq.front();
		dq.pop_front();
		if (dq.front() > 1) {
			ans += a * dq.front();
			dq.pop_front();
		}
		else {
			ans += a;
		}
	}
	while (dq.size() > 0 && dq.front() == 1) {
		ans += dq.front();
		dq.pop_front();
	}

	while (dq.size() > 0) {
		int a = dq.back();
		dq.pop_back();
		if (dq.size() != 0) {
			ans += a * dq.back();
			dq.pop_back();
		}
		else {
			ans += a;
		}
	}

	cout << ans;
	return 0;
}