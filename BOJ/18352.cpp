#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> road;
vector<int> visited;
vector<int> ans;

void bfs(int s) {
	queue<int> q;
	visited[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (int i = 0; i < road[n].size(); i++) {
			if (visited[road[n][i]] == -1) {
				visited[road[n][i]] = visited[n] + 1;
				q.push(road[n][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k, x;
	cin >> n >> m >> k >> x;
	road.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
	}
	visited.resize(n + 1, -1);
	bfs(x);
	for (int i = 1; i <= n; i++) {
		if (visited[i] == k) {
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size() == 0) cout << -1;
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}