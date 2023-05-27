#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> v;
vector<vector<int>> tree;

void find(int start, int end, int level) {
	if (start == end) {
		tree[level].push_back(v[start]);
		return;
	}
	int parent = (start + end) / 2;
	tree[level].push_back(v[parent]);
	find(start, parent - 1, level + 1);
	find(parent + 1, end, level + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	m = (int)pow(2, n) - 1;
	v.resize(m);
	tree.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	find(0, m - 1, 0);

	for (int i = 0; i < n; i++) {
		int a = (int)pow(2, i);
		for (int j = 0; j < a; j++) {
			cout << tree[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
