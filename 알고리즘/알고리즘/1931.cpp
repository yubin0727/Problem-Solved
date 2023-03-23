#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int max = 0;
	int ans = 0;	

	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);

	int f = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first >= f) {
			f = v[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}