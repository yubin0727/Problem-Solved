#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	double ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += (double)v[i].first * (double)v[i + 1].second;
	}
	ans += (double)v[n - 1].first * (double)v[0].second;
	for (int i = 0; i < n - 1; i++) {
		ans -= (double)v[i].second * (double)v[i + 1].first;
	}
	ans -= (double)v[n - 1].second * (double)v[0].first;
	ans = abs(ans) / 2;

	cout.precision(1);
	cout << fixed;
	cout << ans;
	return 0;
}