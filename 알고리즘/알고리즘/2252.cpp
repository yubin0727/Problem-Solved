#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> student;
vector<int> deg;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	student.resize(n + 1);
	deg.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		student[a].push_back(b);
		deg[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int i = 0; i < student[node].size(); i++) {
			int next = student[node][i];
			deg[next]--;
			if (deg[next] == 0) q.push(next);
		}
	}
	return 0;
}