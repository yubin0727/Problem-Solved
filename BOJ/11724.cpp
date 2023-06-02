#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[1001];
bool arr[1001];

void bfs(int n) {
	queue<int> q;
	q.push(n);
	arr[n] = true;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i = 0; i < g[a].size(); i++) {
			if (arr[g[a][i]]) continue;
			q.push(g[a][i]);
			arr[g[a][i]] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i]) continue;
		ans++;
		bfs(i);
	}
	cout << ans;
	return 0;
}