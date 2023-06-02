#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> v(100010, 0);
	int n, t, a, s, e;
	int h = 0;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> s >> e;
			v[s]++;
			v[e]--;
		}
		h = max(h, e);
	}
	for (int i = 1; i <= h; i++) {
		v[i] += v[i - 1];
	}
	int sum = 0;
	for (e = 0; e < t; e++) {
		sum += v[e];
	}
	int ans = sum;
	int index = e;
	while (e <= h) {
		sum -= v[e - t];
		sum += v[e];
		e++;
		if (sum > ans) {
			ans = sum;
			index = e;
		}
	}
	cout << index - t << " " << index;
	return 0;
}