#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> v;
vector<int> setSize;

int find_parent(int n) {
	if (v[n] == -1) return n;
	int parent = find_parent(v[n]);
	v[n] = parent;
	return parent;
}

int number_friend(int a, int b) {
	int ap = find_parent(a);
	int bp = find_parent(b);
	if (ap == bp) {
		return setSize[ap];
	}
	else {
		if (ap < bp) {
			v[bp] = ap;
			setSize[ap] += setSize[bp];
			return setSize[ap];
		}
		else {
			v[ap] = bp;
			setSize[bp] += setSize[ap];
			return setSize[bp];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		setSize.clear();
		v.clear();
		int n;
		cin >> n;
		map<string, int> m;
		int z = 0;
		string f1, f2;
		for (int j = 0; j < n; j++) {
			cin >> f1 >> f2;
			int a, b;
			auto iter = m.find(f1);
			if (iter != m.end()) {
				a = iter->second;
			}
			else {
				m.insert(pair<string, int>(f1, z));
				v.push_back(-1);
				setSize.push_back(1);
				a = z++;
			}
			iter = m.find(f2);
			if (m.find(f2) != m.end()) {
				b = iter->second;
			}
			else {
				m.insert(pair<string, int>(f2, z));
				v.push_back(-1);
				setSize.push_back(1);
				b = z++;
			}
			int ans = number_friend(a, b);
			cout << ans << "\n";
		}
	}
}