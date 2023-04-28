#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int s, e;
bool isVisited[100001];

int solution() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	isVisited[s] = true;
	pq.push({ 0, s });

	while (!pq.empty()) {
		int now_time = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		isVisited[now] = true;

		if (now == e) return now_time;

		int next = now - 1;
		if (next >= 0 && !isVisited[next]) {
			pq.push({ now_time + 1, next });
		}

		next = now + 1;
		if (next <= 100000 && !isVisited[next]) {
			pq.push({ now_time + 1, next });
		}

		next = now * 2;
		if (next <= 100000 && !isVisited[next]) {
			pq.push({ now_time, next });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s >> e;
	cout << solution() << endl;
	return 0;
}