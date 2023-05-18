#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> asc(n, 1);
	vector<int> des(n, 1);
	for (int i = 0; i < n; i++) { cin >> v[i]; }

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				asc[i] = max(asc[i], asc[j] + 1);
			}
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (v[i] > v[j]) {
				des[i] = max(des[i], des[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, asc[i] + des[i] - 1);
	}
	cout << ans;
	return 0;
}