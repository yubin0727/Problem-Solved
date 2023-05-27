#include <iostream>
#include <vector>

using namespace std;

vector<int> method;

int main() {
	int n;
	cin >> n;
	method.resize(n + 1, 0);
	method[1] = 1;
	method[2] = 2;
	for (int i = 3; i <= n; i++) {
		method[i] = (method[i - 2] + method[i - 1]) % 10007;
	}
	cout << method[n];
	return 0;
}
