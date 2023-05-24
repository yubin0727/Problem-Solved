#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, l;
vector<vector<int>> board;
queue<pair<int, char>> direction; // ���� ��ȯ ����
deque<pair<int, int>> snake; // �� (front - �Ӹ�, back - ����)
int dx[] = { 0, -1, 0, 1 }; // ��, ��, ��, �� (�ݽð����)
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
		if (nextR < 1 || nextR > n || nextC < 1 || nextC > n) return; // ���� �ε����� ����
		int len = snake.size();
		for (int i = 1; i < len; i++) { // �ڽ��� ���� �ε����� ����
			int bodyR = snake[i].first;
			int bodyC = snake[i].second;
			if (bodyR == nextR && bodyC == nextC) return;
		}
		snake.push_front({ nextR, nextC }); // ������ �þ
		if (board[nextR][nextC] == 1) { // �̵��� ĭ�� ����� �ִٸ�
			board[nextR][nextC] = 0;    // ��� ������
		}
		else {                // �̵��� ĭ�� ����� ���ٸ�
			snake.pop_back(); // ���� ��ġ�� ĭ ����ֱ�
		}
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; // ������ ũ��
	board.resize(n + 1, vector<int>(n + 1, 0)); // index 1���� �����ϵ���
	cin >> k; // ����� ����
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