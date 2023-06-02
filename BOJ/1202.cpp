#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, c;
	long long ans = 0;
	cin >> n >> k;
	vector<pair<int, int>> t(n);
	vector<int> v;
	priority_queue<int> pq;
	
	for (int i = 0; i < n; i++) {
		cin >> t[i].first >> t[i].second;
	}
	for (int j = 0; j < k; j++) {
		cin >> c;
		v.push_back(c);
	}
	sort(t.begin(), t.end());
	sort(v.begin(), v.end());

	int idx = 0;
	for (int i = 0; i < k; i++) {
		int w = v[i];
		while (idx < n && t[idx].first <= w) {
			pq.push(t[idx].second);
			idx++;
		}
		if (pq.size() != 0) {
			ans = ans + pq.top();
			pq.pop();
		}
	}

	cout << ans;
	return 0;
}