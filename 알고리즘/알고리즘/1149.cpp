#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(3, 0));
	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	for (int i = 1; i < n; i++) {
		v[i][0] += min(v[i - 1][1], v[i - 1][2]);
		v[i][1] += min(v[i - 1][0], v[i - 1][2]);
		v[i][2] += min(v[i - 1][1], v[i - 1][0]);
	}

	int ans = min(min(v[n - 1][0], v[n - 1][1]), v[n - 1][2]);
	cout << ans;
	return 0;
}