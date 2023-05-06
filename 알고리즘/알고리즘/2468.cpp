#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> h;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs() {
	int ans = 0;
	queue<pair<int, int>> q;
	bool isVisited[100][100] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (h[i][j] == 0 || isVisited[i][j]) continue;
			q.push({ i, j });
			isVisited[i][j] = true;
			while (!q.empty()) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nextR = r + dx[dir];
					int nextC = c + dy[dir];
					if (0 <= nextR && nextR < n && 0 <= nextC && nextC < n && !isVisited[nextR][nextC] && h[nextR][nextC] != 0) {
						q.push({ nextR, nextC });
						isVisited[nextR][nextC] = true;
					}
				}
			}
			ans++;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int minH = 100;
	int maxH = 1;
	h.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> h[i][j];
			minH = min(minH, h[i][j]);
			maxH = max(maxH, h[i][j]);
		}
	}
	int ans = 1;
	for (int i = minH; i <= maxH; i++) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (h[a][b] == i) h[a][b] = 0;
			}
		}
		ans = max(ans, bfs());
	}

	cout << ans;
	return 0;
}