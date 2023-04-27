#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> route[1001];
vector<int> cost;
priority_queue<int> dist[1001];
int n, m, k, a, b, c;

void dijkstra() {
	dist[1].push(0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int time = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < route[now].size(); i++) {
			int next = route[now][i].first;
			int next_time = route[now][i].second + time;
			if (dist[next].size() < k) {
				dist[next].push(next_time);
				pq.push({ next_time, next });
			}
			else {
				if (next_time < dist[next].top()) {
					dist[next].pop();
					dist[next].push(next_time);
					pq.push({ next_time, next });
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		route[a].push_back({ b, c });
	}
	dijkstra();
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) cout << -1 << endl;
		else {
			cout << dist[i].top() << endl;
		}
	}
	return 0;
}