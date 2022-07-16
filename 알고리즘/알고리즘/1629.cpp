#include <iostream>
using namespace std;

long long a, b, c;

long long remain(long long d) {
	if (d == 0) return 1;
	if (d == 1) return a % c;
	long long r = remain(d / 2);
	if (d % 2 == 0) {
		return (r * r) % c;
	}
	else {
		return (((r * r) % c) * (a % c)) % c;
	}
	return r;
}

int main() {
	cin >> a >> b >> c;
	long long ans = remain(b);
	cout << ans;
	return 0;
}