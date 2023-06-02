#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool isVisited[100001];

int bfs(int node) {
	queue<pair<int, int>> q;
	isVisited[node] = true;
	q.push({ node, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		if (x == k) break;
		int time = q.front().second;
		q.pop();
		if (x - 1 >= 0 && !isVisited[x - 1]) {
			q.push({ x - 1, time + 1 });
		}
		if (x + 1 <= 100000 && !isVisited[x + 1]) {
			q.push({ x + 1, time + 1 });
		}
		if (x * 2 <= 100000 && !isVisited[x * 2]) {
			q.push({ x * 2, time + 1 });
		}
	}
	return q.front().second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	cout << bfs(n);
	return 0;
}