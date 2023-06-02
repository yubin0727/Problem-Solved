#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> box;
vector<vector<int>> isVisited;
queue<pair<int, int>> q;
int m, n;
int ans = 0;

void bfs() {
	while (!q.empty()) {
		ans++;
		int day = q.size();
		for (int i = 0; i < day; i++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			if (isVisited[r][c]) {
				continue;
			}
			isVisited[r][c] = 1;
			// 위
			if (r - 1 >= 0 && !isVisited[r - 1][c] && box[r-1][c] == 0) {
				q.push({ r - 1, c });
				box[r - 1][c] = 1;
			}
			// 왼쪽
			if (c - 1 >= 0 && !isVisited[r][c - 1] && box[r][c-1] == 0) {
				q.push({ r, c - 1 });
				box[r][c - 1] = 1;
			}
			// 아래
			if (r + 1 < n && !isVisited[r + 1][c] && box[r+1][c] == 0) {
				q.push({ r + 1, c });
				box[r + 1][c] = 1;
			}
			// 오른쪽
			if (c + 1 < m && !isVisited[r][c + 1] && box[r][c+1] == 0) {
				q.push({ r, c + 1 });
				box[r][c + 1] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	box.resize(n, vector<int>(m));
	isVisited.resize(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) q.push({ i, j });
		}
	}
	bfs();
	bool isRipen = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				isRipen = false;
			}
		}
	}
	if (isRipen) cout << ans - 1;
	else cout << -1;
	return 0;
}