#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;

vector<pair<int, int>> bus[1001];
vector<int> cost;
int n, m;

void dijkstra(int x) {
	cost[x] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ cost[x], x });

	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		//if (dist > cost[now]) continue;
		for (int i = 0; i < bus[now].size(); i++) {
			int next = bus[now][i].first;
			int next_dist = bus[now][i].second + dist;
			if (next_dist < cost[next]) {
				cost[next] = next_dist;
				pq.push({ cost[next], next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	cost.resize(n + 1, INF);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		bus[a].push_back({ b, c });
	}

	int start, end;
	cin >> start >> end;

	dijkstra(start);
	cout << cost[end];
	return 0;
}