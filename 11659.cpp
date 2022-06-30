#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, a;
	cin >> n >> m;
	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << sum[y] - sum[x - 1] << "\n";
	}
	return 0;
}