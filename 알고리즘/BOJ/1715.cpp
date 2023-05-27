#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a;
	int ans = 0;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pq.push(a);
	}

	while (pq.size() > 1) {
		int sum = pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		ans += sum;
		pq.push(sum);
	}
	
	cout << ans;
	return 0;
}