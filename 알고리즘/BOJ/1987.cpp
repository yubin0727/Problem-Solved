#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
vector<vector<int>> board;
bool isVisited[26];
int dx[] = { -1, 1,  0, 0 };
int dy[] = {  0, 0, -1, 1 };
int ans = 0;

void solution(int x, int y, int count) {
	ans = max(ans, count);
	for (int i = 0; i < 4; i++) {
		int nextR = x + dx[i];
		int nextC = y + dy[i];
		if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c && !isVisited[board[nextR][nextC]]) {
			isVisited[board[nextR][nextC]] = true;
			solution(nextR, nextC, count + 1);
			isVisited[board[nextR][nextC]] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	board.resize(r, vector<int>(c));
	char tmp;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> tmp;
			board[i][j] = tmp - 'A';
		}
	}
	isVisited[board[0][0]] = true;
	solution(0, 0, 1);
	cout << ans;
	return 0;
}