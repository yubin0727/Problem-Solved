#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				v[i][j] += v[i - 1][j];
			}
			else if (j == i) {
				v[i][j] += v[i - 1][j - 1];
			}
			else {
				v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
			}
		}
	}
	int ans = v[n - 1][0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, v[n - 1][i]);
	}
	cout << ans;
	return 0;
}