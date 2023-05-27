#include <iostream>
#include <vector>

using namespace std;

vector<int> know;
vector<int> parent;
vector<vector<int>> party;
int n, m, k, p;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void make_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	parent.resize(n + 1);
	party.resize(m);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> p;
		know.push_back(p);
	}
	for (int i = 0; i < m; i++) {
		int a, first, person;
		cin >> a;
		cin >> first;
		party[i].push_back(first);
		for (int j = 1; j < a; j++) {
			cin >> person;
			party[i].push_back(person);
			make_union(first, person);
		}
	}
	
	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool isPossible = true;
		for (int j = 0; j < know.size(); j++) {
			if (find(party[i][0]) == find(know[j])) {
				isPossible = false;
				break;
			}
		}
		if (isPossible) ans++;
	}
	cout << ans;
	return 0;
}