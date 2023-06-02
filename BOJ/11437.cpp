#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree; // 트리 저장
vector<int> depth; // node의 depth 저장
vector<int> parent; // 부모 노드 저장
bool isVisited[50001];

void bfs() {
	queue<int> q;
	isVisited[1] = true;
	depth[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int curNode = q.front();
		q.pop();
		for (int i = 0; i < tree[curNode].size(); i++) {
			int next = tree[curNode][i];
			if (!isVisited[next]) {
				isVisited[next] = true;
				parent[next] = curNode;
				depth[next] = depth[curNode] + 1;
				q.push(next);
			}
		}
	}
}

int LCA(int u, int v) {
	int uParent = u;
	int vParent = v;
	if (depth[u] > depth[v]) {
		int a = depth[u] - depth[v];
		for (int i = 0; i < a; i++) {
			uParent = parent[uParent];
		}
	}
	else if (depth[u] < depth[v]) {
		int a = depth[v] - depth[u];
		for (int i = 0; i < a; i++) {
			vParent = parent[vParent];
		}
	}
	while (uParent != vParent) {
		uParent = parent[uParent];
		vParent = parent[vParent];
	}
	return uParent;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	tree.resize(n + 1);
	depth.resize(n + 1);
	parent.resize(n + 1, -1);
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	bfs();

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		cout << LCA(u, v) << "\n";
	}

	return 0;
}