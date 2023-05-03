#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<pair<int, int>> virus;
vector<pair<int, int>> blank;

int bfs(vector<vector<int>> v, int area) {
	queue<pair<int, int>> q;
	bool isVisited[8][8] = { 0, };
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first, virus[i].second });
		isVisited[virus[i].first][virus[i].second] = true;
	}
	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextR = curR + dx[i];
			int nextC = curC + dy[i];
			if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) continue;
			if (v[nextR][nextC] == 0) {
				v[nextR][nextC] = 2;
				q.push({ nextR, nextC });
				area--;
			}
		}
	}
	return area;
}

int safe(vector<vector<int>> v, int a, int b, int c) {
	int ar = blank[a].first;
	int ac = blank[a].second;
	int br = blank[b].first;
	int bc = blank[b].second;
	int cr = blank[c].first;
	int cc = blank[c].second;
	v[ar][ac] = 1;
	v[br][bc] = 1;
	v[cr][cc] = 1;
	int area = blank.size() - 3;
	//vector<vector<int>> spread = bfs(v, area);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spread[i][j] == 0) {
				area++;
			}
		}
	}*/
	return bfs(v, area);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				virus.push_back({ i, j });
			}
			if (v[i][j] == 0) {
				blank.push_back({ i, j });
			}
		}
	}

	int ans = 0;
	int zeros = blank.size();
	for (int i = 0; i < zeros; i++) {
		for (int j = i + 1; j < zeros; j++) {
			for (int k = j + 1; k < zeros; k++) {
				ans = max(ans, safe(v, i, j, k));
			}
		}
	}
	cout << ans;
	return 0;
}