#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = 2e9 + 10;
	int left = 0;
	int right = n - 1;
	int a = v[0];
	int b = v[n - 1];
	int Zsum = abs(v[0] + v[n - 1]);
	while (left < right) {
		int sum = v[left] + v[right];
		if (abs(sum) < Zsum) {
			Zsum = abs(sum);
			a = v[left];
			b = v[right];
		}
		if (abs(v[left]) < abs(v[right])) right--;
		else left++;
	}
	cout << a << " " << b;
	return 0;
}