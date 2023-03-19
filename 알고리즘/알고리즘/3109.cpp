#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> v;
vector<vector<int>> visited;
int ans = 0;
int r, c;

bool dfs(int a, int b) {
	visited[a][b] = 1;
	if (b == c - 1) {
		return true;
	}
	else {
		if (a - 1 >= 0 && v[a - 1][b + 1] != 'x' && visited[a - 1][b + 1] == 0) {
			if (dfs(a - 1, b + 1)) return true;
		}
		if (v[a][b + 1] != 'x' && visited[a][b + 1] == 0) {
			if (dfs(a, b + 1)) return true;
		}
		if (a + 1 < r && v[a + 1][b + 1] != 'x' && visited[a + 1][b + 1] == 0) {
			if (dfs(a + 1, b + 1)) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	v.resize(r, vector<char>(c));
	visited.resize(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		if (dfs(i, 0)) ans++;
	}
	
	cout << ans;
	return 0;
}