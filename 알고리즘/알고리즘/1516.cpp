#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, a;
	cin >> n;
	vector<int> time(n + 1, 0);
	vector<int> tmp(n + 1);
	vector<int> deg(n + 1, 0);
	vector<vector<int>> build(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> tmp[i];
		while (true) {
			cin >> a;
			if (a == -1) break;
			build[a].push_back(i);
			deg[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < build[node].size(); i++) {
			int next = build[node][i];
			time[next] = max(time[next], time[node] + tmp[node]);
			deg[next]--;
			if (deg[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= n; i++) { cout << time[i] + tmp[i] << endl; }
	
	return 0;
}