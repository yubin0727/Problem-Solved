#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<int> parent;
int n, m;

int find(int x) {
	if (x == parent[x]) return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void make_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) parent[a] = b;
	else parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n; // 도시의 수
	cin >> m; // 여행 계획에 속한 도시들의 수
	v.resize(n + 1, vector<int>(n + 1, 0));
	parent.resize(n + 1);
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == 1 && parent[i] != parent[j]) make_union(i, j);
		}
	}

	int path;
	cin >> path;
	int root = find(path);
	int isPossible = true;
	for (int i = 1; i < m; i++) {
		cin >> path;
		if (root != find(path)) {
			isPossible = false;
			break;
		}
	}
	if (isPossible) cout << "YES";
	else cout << "NO";
	return 0;
}