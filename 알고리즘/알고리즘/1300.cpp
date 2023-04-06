#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;
long long s, e, mid;

int main() {
	cin >> n >> k;
	s = 1;
	e = n * n;
	while (s <= e) {
		mid = (s + e) / 2;
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min((long long)n, mid / i);
		}
		if (cnt >= k) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << s;
	return 0;
}