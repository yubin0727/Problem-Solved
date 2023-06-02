#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct marble
{
	int rx, ry;
	int bx, by;
	int c;
};

int n, m;
char board[11][11];
bool isVisited[11][11][11][11]; // 방문 여부 체크
int dx[] = { -1, 1, 0, 0 }; // 위, 아래 이동
int dy[] = { 0, 0, -1, 1 }; // 왼쪽, 오른쪽 이동

int move(int& x, int& y, int& i) {
	int dist = 0;
	while (board[x + dx[i]][y + dy[i]] != '#' && board[x][y] != 'O') {
		x += dx[i];
		y += dy[i];
		dist++;
	}
	return dist;
}

int bfs(int rx, int ry, int bx, int by) {
	queue<marble> q;
	q.push({ rx, ry, bx, by, 0 });
	isVisited[rx][ry][bx][by] = true;
	while (!q.empty()) {
		int rr = q.front().rx;
		int rc = q.front().ry;
		int br = q.front().bx;
		int bc = q.front().by;
		int dist = q.front().c;
		q.pop();

		if (dist >= 10) break;

		for (int i = 0; i < 4; i++) {
			int next_rx = rr, next_ry = rc, next_bx = br, next_by = bc;
			int dist_r = move(next_rx, next_ry, i);
			int dist_b = move(next_bx, next_by, i);

			if (board[next_bx][next_by] == 'O') continue;
			if (board[next_rx][next_ry] == 'O') {
				return dist + 1;
			}
			if (next_bx == next_rx && next_by == next_ry) {
				if (dist_r > dist_b) {
					next_rx -= dx[i];
					next_ry -= dy[i];
				}
				else {
					next_bx -= dx[i];
					next_by -= dy[i];
				}
			}

			if (isVisited[next_rx][next_ry][next_bx][next_by]) continue;
			isVisited[next_rx][next_ry][next_bx][next_by] = true;
			q.push({ next_rx, next_ry, next_bx, next_by, dist + 1 });
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int rx = 0, ry = 0, bx = 0, by = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (board[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}
	cout << bfs(rx, ry, bx, by);

	return 0;
}