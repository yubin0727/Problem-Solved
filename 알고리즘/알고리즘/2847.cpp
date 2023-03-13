#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int ans = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int s = v[n - 1] - 1;
	for (int j = n - 2; j >= 0; j--) {
		if (v[j] > s) {
			ans += (v[j] - s);
			s--;
		}
		else s = v[j] - 1;
	}
	cout << ans;
	return 0;
}