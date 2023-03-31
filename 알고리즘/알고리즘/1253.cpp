#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int ans = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int a = 0; a < n; a++) {
		int i = 0;
		int j = n - 1;
		int k = v[a];
		while (i < j) {
			if (v[i] + v[j] == k) {
				if (i != k && j != a) {
					ans++;
					break;
				}
				else if (i == k) i++;
				else j--;
			}
			else if (v[i] + v[j] > k) {
				j--;
			}
			else {
				i++;
			}
		}
	}

	cout << ans;
	return 0;
}