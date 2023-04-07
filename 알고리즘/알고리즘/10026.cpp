#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> v;
queue<pair<int, int>> q;
bool isVisited[100][100];
int n;
int ans = 0;

void bfs(int i, int j) {
	char c = v[i][j];
	q.push({ i, j });
	isVisited[i][j] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (y - 1 >= 0 && c == v[x][y - 1] && !isVisited[x][y - 1]) {
			q.push({ x, y - 1 });
			isVisited[x][y - 1] = true;
		}
		if (y + 1 < n && c == v[x][y + 1] && !isVisited[x][y + 1]) {
			q.push({ x, y + 1 });
			isVisited[x][y + 1] = true;
		}
		if (x - 1 >= 0 && c == v[x - 1][y] && !isVisited[x - 1][y]) {
			q.push({ x - 1, y });
			isVisited[x - 1][y] = true;
		}
		if (x + 1 < n && c == v[x + 1][y] && !isVisited[x + 1][y]) {
			q.push({ x + 1, y });
			isVisited[x + 1][y] = true;
		}
	}
}

void rg_bfs(int i, int j) {
	bool isBlue = false;
	if (v[i][j] == 'B') isBlue = true;
	q.push({ i, j });
	isVisited[i][j] = true;
	if (isBlue) {
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (y - 1 >= 0 && 'B' == v[x][y - 1] && !isVisited[x][y - 1]) {
				q.push({ x, y - 1 });
				isVisited[x][y - 1] = true;
			}
			if (y + 1 < n && 'B' == v[x][y + 1] && !isVisited[x][y + 1]) {
				q.push({ x, y + 1 });
				isVisited[x][y + 1] = true;
			}
			if (x - 1 >= 0 && 'B' == v[x - 1][y] && !isVisited[x - 1][y]) {
				q.push({ x - 1, y });
				isVisited[x - 1][y] = true;
			}
			if (x + 1 < n && 'B' == v[x + 1][y] && !isVisited[x + 1][y]) {
				q.push({ x + 1, y });
				isVisited[x + 1][y] = true;
			}

		}
	}
	else {
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (y - 1 >= 0 && 'B' != v[x][y - 1] && !isVisited[x][y - 1]) {
				q.push({ x, y - 1 });
				isVisited[x][y - 1] = true;
			}
			if (y + 1 < n && 'B' != v[x][y + 1] && !isVisited[x][y + 1]) {
				q.push({ x, y + 1 });
				isVisited[x][y + 1] = true;
			}
			if (x - 1 >= 0 && 'B' != v[x - 1][y] && !isVisited[x - 1][y]) {
				q.push({ x - 1, y });
				isVisited[x - 1][y] = true;
			}
			if (x + 1 < n && 'B' != v[x + 1][y] && !isVisited[x + 1][y]) {
				q.push({ x + 1, y });
				isVisited[x + 1][y] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	v.resize(n, vector<char>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	// 적록색약이 아닌 사람
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isVisited[i][j]) {
				bfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << " ";

	// 적록색약인 사람
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			isVisited[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isVisited[i][j]) {
				ans++;
				rg_bfs(i, j);
			}
		}
	}
	cout << ans;

	return 0;
}