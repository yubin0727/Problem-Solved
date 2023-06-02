#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p, d;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back(make_pair(d, p));
	}
	sort(v.begin(), v.end());

	int j = n-1;
	if (n != 0) {
		for (int i = v[n-1].first; i > 0; i--) {
			while (j >= 0 && v[j].first >= i) {
				pq.push(v[j].second);
				j--;
			}
			if (pq.size() > 0) {
				ans += pq.top();
				pq.pop();
			}
		}
	}

	cout << ans;
	return 0;
}