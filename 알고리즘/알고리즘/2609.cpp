#include <iostream>
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
int lcm(int a, int b) {
	int m = gcd(a, b);
	return a * b / m;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
	return 0;
}