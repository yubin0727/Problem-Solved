#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, n;
	while (cin >> x >> n) {
		x = x * 10000000;
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int left = 0;
		int right = n - 1;
		int a, b;
		int minus = -1;
		while (left < right) {
			int sum = v[left] + v[right];
			if (sum > x) right--;
			else if (sum < x) left++;
			else {
				if (v[right] - v[left] > minus) {
					minus = v[right] - v[left];
					a = v[left];
					b = v[right];
				}
				right--;
			}
		}
		if (minus < 0) cout << "danger" << endl;
		else cout << "yes " << a << " " << b << endl;
	}
	return 0;
}