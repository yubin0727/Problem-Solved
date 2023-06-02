#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;

int find_parent(int a) {
	if (p[a] == -1) return a;
	int parent = find_parent(p[a]);
	p[a] = parent;
	return parent;
}

long long sTree(int a, int b, long long d, int cost) {
	int ap = find_parent(a);
	int bp = find_parent(b);
	if (ap == bp) return d;
	else {
		if (ap < bp) p[bp] = ap;
		else p[ap] = bp;
		d += cost;
	}
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e;
	cin >> v >> e;
	vector<pair<int, pair<int, int>>> g;
	p.resize(v + 1, -1);
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		g.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(g.begin(), g.end());
	
	long long d = 0;
	for (int i = 0; i < e; i++) {
		int a = g[i].second.first;
		int b = g[i].second.second;
		int cost = g[i].first;
		d = sTree(a, b, d, cost);
	}

	cout << d << endl;
	return 0;
}