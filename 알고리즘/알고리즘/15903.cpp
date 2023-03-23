#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pq.push(a);
	}
	for (int i = 0; i < m; i++) {
		long long x = pq.top();
		pq.pop();
		long long y = pq.top();
		pq.pop();
		pq.push(x + y);
		pq.push(x + y);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}