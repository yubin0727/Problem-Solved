#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j].first >> v[j].second;
		}
		sort(v.begin(), v.end());
		int tmp = v[0].second;
		int ans = 1;
		for (int j = 1; j < n; j++) {
			if (v[j].second < tmp) {
				tmp = v[j].second;
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}