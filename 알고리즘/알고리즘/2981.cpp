#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector<int> v(t, 0);
	for (int i = 0; i < t; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int m = v[1] - v[0];
	for (int i = 1; i < t - 1; i++) {
		m = gcd(m, v[i + 1] - v[i]);
	}
	vector<int> vec;
	for (int i = 1; i * i <= m; i++) {
		if (m % i == 0) {
			vec.push_back(i);
			if (i * i != m) vec.push_back(m / i);
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	return 0;
}