#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> tree[1001];

int bfs(int start, int end) {
	queue<pair<int, int>> q;
	bool isVisited[1001] = { 0, };
	vector<int> dist(1001, -1);
	isVisited[start] = true;
	dist[start] = 0;
	q.push({ start, 0 });
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a == end) return b;

		for (int i = 0; i < tree[a].size(); i++) {
			int nextNode = tree[a][i].first;
			int nextDist = tree[a][i].second;
			if (!isVisited[nextNode]) {
				q.push({ nextNode, nextDist + b });
				isVisited[nextNode] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a, b, c;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << bfs(a, b) << endl;
	}
	return 0;
}