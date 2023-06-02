#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;

int n, e, a, b, c, v1, v2;
vector<pair<int, int>> graph[801];
vector<int> cost1;
vector<int> cost2;

vector<int> dijkstra(int start) {
	bool isVisited[801] = { 0, };
	vector<int> cost(n + 1, INF);
	cost[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < graph[start].size(); i++) {
		int b = graph[start][i].first;
		int c = graph[start][i].second;
		cost[b] = c;
		pq.push({ c, b });
	}
	while (!pq.empty()) {
		int c = pq.top().first;
		int b = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[b].size(); i++) {
			int next = graph[b][i].first;
			int dist = graph[b][i].second;
			if (c + dist < cost[next]) {
				cost[next] = c + dist;
				pq.push({ cost[next], next });
			}
		}
	}

	return cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> v1 >> v2;
	cost1 = dijkstra(v1);
	cost2 = dijkstra(v2);

	// sum1 : 1 -> v1 -> v2 -> N
	// sum2 : 1 -> v2 -> v1 -> N
	int sum1, sum2;

	if (cost1[1] == INF || cost2[n] == INF) { sum1 = -1; }
	else {
		sum1 = cost1[1] + cost2[n] + cost1[v2];
	}
	if (cost2[1] == INF || cost1[n] == INF) { sum2 = -1; }
	else {
		sum2 = cost2[1] + cost1[n] + cost1[v2];
	}
	if (sum1 < sum2) cout << sum1;
	else cout << sum2;
	
	return 0;
}