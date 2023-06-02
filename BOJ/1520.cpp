#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> path;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		return 1;
	}
	if (path[x][y] != -1) return path[x][y];
	path[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nX = x + dx[i];
		int nY = y + dy[i];
		if (0 <= nX && nX < n && 0 <= nY && nY < m && map[nX][nY] < map[x][y]) path[x][y] += dfs(nX, nY);
	}
	return path[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	map.resize(n, vector<int>(m, 0));
	path.resize(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cout << dfs(0, 0);
	return 0;
}