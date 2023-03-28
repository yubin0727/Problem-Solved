#include <iostream>
#include <vector>

using namespace std;

int a, node, n, d;
int ans = 0;
int endNode = 1;
bool visited[100001];
vector<pair<int, int>> v[100001];

void dfs(int node, int dist) {
	visited[node] = true;
	if (dist > ans) {
		ans = dist;
		endNode = node;
	}
	for (int i = 0; i < v[node].size(); i++) {
		int nextNode = v[node][i].first;
		if (!visited[nextNode]) {
			dfs(nextNode, dist + v[node][i].second);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> node;
		while (true) {
			cin >> n;
			if (n == -1) break;
			cin >> d;
			v[node].push_back(make_pair(n, d));
			v[n].push_back(make_pair(node, d));
		}
	}
	dfs(1, 0);
	for (int i = 0; i <= a; i++) {
		visited[i] = false;
	}
	ans = 0;
	dfs(endNode, 0);
	cout << ans;
	return 0;
}