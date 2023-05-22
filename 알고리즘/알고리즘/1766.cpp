#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	vector<int> deg(n + 1, 0);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		deg[b]++;
		v[a].push_back(b);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int q = pq.top();
		pq.pop();
		cout << q << " ";
		for (int i = 0; i < v[q].size(); i++) {
			int next = v[q][i];
			deg[next]--;
			if (deg[next] == 0) {
				pq.push(next);
			}
		}
	}

	return 0;
}