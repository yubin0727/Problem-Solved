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
	int tree = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v[i] = t;
	}
	sort(v.begin(), v.end());
	int start = 0;
	int end = v[n - 1];
	int max = 0;

	while (start <= end) {
		long long tree = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			if (v[i] > mid) tree += (v[i] - mid);
		}
		if (tree == m) {
			max = mid;
			break;
		}
		if (tree > m) {
			start = mid + 1;
			if (max < mid) max = mid;
		}
		else end = mid - 1;
	}
	cout << max << endl;
	return 0;
}