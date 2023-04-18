#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<pair<int, int>> ans;
int n, m;
int a, b;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int bfs(int x) {
	vector<int> isVisited(n + 1, -1);
	queue<int> q;
	q.push(x);
	isVisited[x]++;
	int total = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		total++;
		for (int i = 0; i < v[a].size(); i++) {
			if (isVisited[v[a][i]] == -1) {
				q.push(v[a][i]);
				isVisited[v[a][i]]++;
			}
		}
	}
	return total;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int n = bfs(i);
		ans.push_back({ n, i });
	}
	sort(ans.begin(), ans.end(), compare);
	int max = ans.front().first;
	int idx = 0;
	while (idx < ans.size() && ans[idx].first == max) {
		cout << ans[idx].second << " ";
		idx++;
	}
	return 0;
}