#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647
using namespace std;

vector<pair<int, int>> v1[1001]; 
vector<pair<int, int>> v2[1001];

int main() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<int> t1(n + 1, INF);
	vector<int> t2(n + 1, INF);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v1[a].push_back(make_pair(b, c)); // a 출발, b 도착, c 시간
		v2[b].push_back(make_pair(a, c)); // b 출발, a 도착, c 시간
	}
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, x)); // 시간, 시작지점
	t1[x] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int point = pq.top().second;
		pq.pop();
		for (int i = 0; i < v1[point].size(); i++) {
			int next = v1[point][i].first;
			if (t1[next] > t1[point] + v1[point][i].second) {
				t1[next] = t1[point] + v1[point][i].second;
				pq.push(make_pair(-t1[next], next));
			}
		}
	}
	pq.push(make_pair(0, x));
	t2[x] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int point = pq.top().second;
		pq.pop();
		for (int i = 0; i < v2[point].size(); i++) {
			int next = v2[point][i].first;
			if (t2[next] > t2[point] + v2[point][i].second) {
				t2[next] = t2[point] + v2[point][i].second;
				pq.push(make_pair(-t2[next], next));
			}
		}
	}
	int ans = t1[1] + t2[1];
	for (int i = 2; i <= n; i++) {
		ans = max(ans, t1[i] + t2[i]);
	}
	cout << ans;

	return 0;
}