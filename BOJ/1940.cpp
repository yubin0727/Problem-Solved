#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int left = 0;
	int right = n - 1;
	int ans = 0;
	while (left < right) {
		int sum = v[left] + v[right];
		if (sum > m) right--;
		else if (sum < m) left++;
		else {
			ans++;
			right--;
		}
	}
	cout << ans;
	return 0;
}