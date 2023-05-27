#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, INF));
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (v[a][b] > c) {
			v[a][b] = c;
		}
	}
	for (int i = 1; i <= n; i++) { // i가 경유, j 시작, k 도착
		for (int j = 1; j <= n; j++) { 
			//if (j == i) continue;
			for (int k = 1; k <= n; k++) {
				if (k == j || k == i) continue;
				if (v[j][i] != INF && v[i][k] != INF) {
					v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == INF) cout << "0 ";
			else cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}