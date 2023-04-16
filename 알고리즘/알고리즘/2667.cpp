#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool isVisited[25][25];
vector<vector<int>> v;
vector<int> ans;
int n;

int bfs(int x, int y) {
	int total = 0;
	isVisited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		total++;
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if (i - 1 >= 0 && v[i - 1][j] == 1 && !isVisited[i - 1][j]) {
			q.push({ i - 1,j });
			isVisited[i - 1][j] = true;
		}
		if (j - 1 >= 0 && v[i][j - 1] == 1 && !isVisited[i][j - 1]) {
			q.push({ i, j - 1 });
			isVisited[i][j - 1] = true;
		}
		if (i + 1 < n && v[i + 1][j] == 1 && !isVisited[i + 1][j]) {
			q.push({ i + 1,j });
			isVisited[i + 1][j] = true;
		}
		if (j + 1 < n && v[i][j + 1] == 1 && !isVisited[i][j + 1]) {
			q.push({ i,j + 1 });
			isVisited[i][j + 1] = true;
		}
	}
	return total;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			v[i][j] = s[j] - 48;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1 && !isVisited[i][j]) {
				ans.push_back(bfs(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}