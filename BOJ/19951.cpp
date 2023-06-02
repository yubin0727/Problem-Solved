#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> h(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	vector<int> d(n + 2, 0);
	for (int i = 0; i < m; i++) {
		int a, b, k;
		cin >> a >> b >> k;
		d[a] += k;
		d[b + 1] -= k;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += d[i];
		cout << h[i] + sum << " ";
	}
	return 0;
}