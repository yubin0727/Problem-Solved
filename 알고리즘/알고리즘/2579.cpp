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
	vector<int> ans(n + 1, 0);
	for (int i = 1; i <= n; i++) { cin >> v[i]; }
	if (n == 1) { cout << v[1]; }
	else if (n == 2) { cout << v[1] + v[2]; }
	else {
		ans[1] = v[1];
		ans[2] = v[1] + v[2];
		ans[3] = max(v[1] + v[3], v[2] + v[3]);
		for (int i = 4; i <= n; i++) {
			ans[i] = max(ans[i - 2] + v[i], ans[i - 3] + v[i - 1] + v[i]);
		}
		cout << ans[n];
	}
	return 0;
}