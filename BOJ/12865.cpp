#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> w(n + 1);
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	int m = 0;
	vector<vector<int>> value(n + 1, vector<int>(k + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (w[i] <= j) {
				value[i][j] = max(value[i - 1][j], v[i] + value[i - 1][j - w[i]]);
			}
			else value[i][j] = value[i - 1][j];
		}
	}
	cout << value[n][k];
	return 0;
}