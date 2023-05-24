#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, l;
vector<vector<int>> board;
queue<pair<int, char>> direction; // 방향 변환 정보
deque<pair<int, int>> snake; // 뱀 (front - 머리, back - 꼬리)
int dx[] = { 0, -1, 0, 1 }; // 우, 상, 좌, 하 (반시계방향)
int dy[] = { 1, 0, -1, 0 };
int d = 0;
int ans = 0;

void solution() {
	while (1) {
		if (!direction.empty() && direction.front().first <= ans) {
			char nextD = direction.front().second;
			direction.pop();
			if (nextD == 'L') {
				d = (d + 1) % 4;
			}
			else {
				d = (d + 3) % 4;
			}
		}
		int headR = snake.front().first;
		int headC = snake.front().second;
		int nextR = headR + dx[d];
		int nextC = headC + dy[d];
		if (nextR < 1 || nextR > n || nextC < 1 || nextC > n) return; // 벽과 부딪히면 종료
		int len = snake.size();
		for (int i = 1; i < len; i++) { // 자신의 몸과 부딪히면 종료
			int bodyR = snake[i].first;
			int bodyC = snake[i].second;
			if (bodyR == nextR && bodyC == nextC) return;
		}
		snake.push_front({ nextR, nextC }); // 몸길이 늘어남
		if (board[nextR][nextC] == 1) { // 이동한 칸에 사과가 있다면
			board[nextR][nextC] = 0;    // 사과 없어짐
		}
		else {                // 이동한 칸에 사과가 없다면
			snake.pop_back(); // 꼬리 위치한 칸 비워주기
		}
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; // 보드의 크기
	board.resize(n + 1, vector<int>(n + 1, 0)); // index 1부터 시작하도록
	cin >> k; // 사과의 개수
	int r, c;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		board[r][c] = 1;
	}
	cin >> l;
	int t; char dir;
	for (int i = 0; i < l; i++) {
		cin >> t >> dir;
		direction.push({ t, dir });
	}
	snake.push_front({ 1, 1 });
	solution();
	cout << ans + 1;
	return 0;
}