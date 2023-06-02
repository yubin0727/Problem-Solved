#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int max = 0;
	int ans = 0;
	int n, d, m;
	priority_queue<pair<int, int>> pq;
	priority_queue<int> cup;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> m;
		if (d > max) max = d;
		pq.push(make_pair(d, m));
	}
	for (; max > 0; max--) {
		while (pq.size() != 0 && pq.top().first >= max) {
			cup.push(pq.top().second);
			pq.pop();
		}
		if (cup.size() != 0) {
			ans += cup.top();
			cup.pop();
		}
	}

	cout << ans;
	return 0;
}