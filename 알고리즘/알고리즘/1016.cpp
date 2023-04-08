#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long min;
	long long max;
	cin >> min >> max;
	vector<int> v(max - min + 1, 0);
	for (long long i = 2; i * i <= max; i++) {
		long long d = i * i;
		long long s = min / d;
		if (min % d != 0) s++;
		while (s * d <= max) {
			v[s * d - min] = 1;
			s++;
		}
	}

	int ans = 0;
	for (int i = 0; i <= max - min; i++) {
		if (v[i] == 0) ans++;
	}
	cout << ans;
	return 0;
}