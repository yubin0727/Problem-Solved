#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647

using namespace std;

vector<pair<int, int>> v[20001];
vector<int> d;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	d[start] = 0;
	pq.push(make_pair(0, start)); // <cost, node>
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (d[node] < cost) continue;
		for (int i = 0; i < v[node].size(); i++) {
			int a = v[node][i].first;
			if (d[a] > cost + v[node][i].second) {
				d[a] = cost + v[node][i].second;
				pq.push(make_pair(-d[a], a));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int p, e, start;
	cin >> p >> e >> start;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	d.resize(p + 1);
	for (int i = 1; i <= p; i++) {
		d[i] = INF;
	}
	dijkstra(start);

	for (int i = 1; i <= p; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}
	return 0;
}