#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) { cin >> v[i]; }
	if (n == 1) cout << v[1];
	else if (n == 2) cout << v[1] + v[2];
	else {
		dp[1] = v[1];
		dp[2] = v[1] + v[2];
		for (int i = 3; i <= n; i++) {
			dp[i] = max(max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]), dp[i - 1]);
		}
		cout << dp[n];
	}
	return 0;
}