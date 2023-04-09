#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	long long n;
	cin >> n;
	
	long long ans = n;
	for (long long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ans = ans - ans / i;
			while (n % i == 0) n = n / i;
		}
	}
	if (n > 1) ans = ans - ans / n;
	cout << ans;
	return 0;
}