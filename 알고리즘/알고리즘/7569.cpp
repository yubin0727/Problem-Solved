#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int box[101][101][101];
int day[101][101][101];
int m, n, h;
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> h;
	queue<pair<pair<int, int>, int>> q; // row, column, h
	fill_n(&day[0][0][0], (m + 1) * (n + 1) * (h + 1), -1);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cin >> box[j][k][i];
				if (box[j][k][i] == 1) {
					q.push({ {j, k}, i });
					day[j][k][i] = 0;
				}
			}
		}
	}
	
	while (!q.empty()) {
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int curZ = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			int nextZ = curZ + dz[i];
			if (nextX > 0 && nextX <= n && nextY > 0 && nextY <= m && nextZ > 0 && nextZ <= h && box[nextX][nextY][nextZ] == 0) {
				box[nextX][nextY][nextZ] = 1;
				day[nextX][nextY][nextZ] = day[curX][curY][curZ] + 1;
				q.push({ {nextX, nextY}, nextZ });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (box[j][k][i] == 0) {
					cout << -1;
					return 0;
				}
				ans = max(ans, day[j][k][i]);
			}
		}
	}
	cout << ans;
	return 0;
}