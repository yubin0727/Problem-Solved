#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.resize(m, 0);
		for (int j = 0; j < m; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());

		int ans = v[1] - v[0];
		for (int i = 0; i < m - 2; i++) {
			int a = v[i + 2] - v[i];
			if (a > ans) ans = a;
		}
		int a = v[m - 1] - v[m - 2];
		if (a > ans) ans = a;

		cout << ans << endl;
	}
	return 0;
}