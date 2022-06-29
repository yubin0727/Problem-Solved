#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> w(n + 1, vector<int>(n + 1, 0));
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		w[a][b] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			for (int k = 1; k <= n; k++) {
				if (k == i || k == j) continue;
				if (w[j][i] == 1 && w[i][k] == 1) w[j][k] = 1;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			if (w[i][j] == 0 && w[j][i] == 0) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}