#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	int ans = arr[0];
	dp[0] = arr[0];
	for (int j = 1; j < n; j++) {
		dp[j] = max(dp[j - 1] + arr[j], arr[j]);
		ans = max(ans, dp[j]);
	}
	cout << ans;
	return 0;
}