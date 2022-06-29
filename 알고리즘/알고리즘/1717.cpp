#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int find_parent(int index) {
	if (v[index] == -1) return index;
	int parent = find_parent(v[index]);
	v[index] = parent;
	return parent;
}

void make_union(int b, int c) {
	int bp = find_parent(b);
	int cp = find_parent(c);
	if (bp == cp) return;
	if (bp < cp) v[cp] = bp;
	else v[bp] = cp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	v.resize(n + 1, -1);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			make_union(b, c);
		}
		else {
			if (find_parent(b) == find_parent(c)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}