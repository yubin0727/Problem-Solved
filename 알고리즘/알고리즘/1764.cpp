#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int  n, m;
	cin >> n >> m;
	vector<string> v, r;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) { r.push_back(s); }
	}
	sort(r.begin(), r.end());
	cout << r.size() << "\n";
	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << "\n";
	}
	return 0;
}