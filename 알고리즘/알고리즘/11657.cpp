#include <iostream>
#include <vector>
#define INF 99999999

using namespace std;

struct edge {
	int start;
	int end;
	int time;
};
vector<edge> v;
vector<long long> dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	v.resize(m);
	dist.resize(n + 1, INF);
	for (int i = 0; i < m; i++) {
		cin >> v[i].start >> v[i].end >> v[i].time;
	}

	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int a = v[j].start;
			int b = v[j].end;
			int c = v[j].time;
			if (dist[a] != INF && dist[a] + c < dist[b]) dist[b] = dist[a] + c;
		}
	}
	bool isUpdate = false;
	for (int i = 0; i < v.size(); i++) {
		int a = v[i].start;
		int b = v[i].end;
		int c = v[i].time;
		if (dist[a] != INF && dist[a] + c < dist[b]) isUpdate = true;
	}

	if (isUpdate) cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) cout << -1 << endl;
			else cout << dist[i] << endl;
		}
	}
	return 0;
}