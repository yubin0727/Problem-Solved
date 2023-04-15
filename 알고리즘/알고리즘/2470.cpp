#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = n - 1;
	int a = abs(v[start] + v[end]);
	int ans1 = 0;
	int ans2 = end;
	while (start < end) {
		int tmp = v[start] + v[end];
		if (a > abs(tmp)) {
			ans1 = start;
			ans2 = end;
			a = abs(tmp);
		}
		if (tmp < 0) start++;
		else end--;
	}
	cout << v[ans1] << " " << v[ans2];
	return 0;
}