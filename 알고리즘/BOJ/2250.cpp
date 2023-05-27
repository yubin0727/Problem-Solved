#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> col; // 몇 번째 열인지
vector<int> level[10001]; // 레벨
vector<vector<int>> tree; // 트리
vector<int> node;
int start = 1;
int maxDepth = 1;

int findRoot(){
	int root = 1;
	for (int i = 0; i < node.size(); i++) {
		if (node[i] == 1) root = i;
	}
	return root;
}

void dfs(int node, int depth) {
	if (tree[node][0] != -1) {
		dfs(tree[node][0], depth + 1);
	}
	col[node] = start;
	start++;
	level[depth].push_back(node);
	maxDepth = max(depth, maxDepth);
	if (tree[node][1] != -1) {
		dfs(tree[node][1], depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	col.resize(n + 1, -1);
	tree.resize(n + 1);
	node.resize(n + 1, 0);
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		tree[a].push_back(b);
		tree[a].push_back(c);
		node[a]++;
		if (b != -1) node[b]++;
		if (c != -1) node[c]++;
	}
	int root = findRoot();
	dfs(root, 1); // 루트 root, level 1

	int ansL = 1;
	int ansW = 1;
	for (int i = 2; i <= maxDepth; i++) {
		int s = level[i].size();
		
		int w = col[level[i][s - 1]] - col[level[i][0]] + 1;
		if (w > ansW) {
			ansW = w;
			ansL = i;
		}
	}
	cout << ansL << " " << ansW;
	return 0;
}