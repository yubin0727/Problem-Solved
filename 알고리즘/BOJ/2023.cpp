#include <iostream>
#include <cmath>

using namespace std;

int n;
int arr[] = { 1, 3, 5, 7, 9 };

bool isPrime(int n) {
	int divisor = int(sqrt(n));
	for (int i = 2; i <= divisor; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void dfs(int a, int d) {
	if (d == n) {
		if (isPrime(a)) cout << a << endl;
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (isPrime(a * 10 + arr[i])) dfs(a * 10 + arr[i], d + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	// 한 자리수 중 소수
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	return 0;
}