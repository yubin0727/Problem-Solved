#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		cout << a * b / gcd(a, b) << endl;
	}
	return 0;
}