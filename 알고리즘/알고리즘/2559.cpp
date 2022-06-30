#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int j = 0;
	int ans = 0;
	for (; j < k; j++) {
		ans += v[j];
	}
	int sum = ans;
	while (j < n) {
		sum -= v[j - k];
		sum += v[j];
		j++;
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}