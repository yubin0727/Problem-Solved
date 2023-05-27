#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long ans = 0;
	cin >> n >> m;
	vector<long long> v(n + 1, 0);
	vector<long long> r(m, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}
	for (int i = 0; i <= n; i++) {
		int a = v[i] % m;
		r[a]++;
	}
	for (int i = 0; i < m; i++) {
		ans += (r[i] * (r[i] - 1)) / 2;
	}

	cout << ans;
	return 0;
}