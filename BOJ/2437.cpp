#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 1 < v[i]) {
			break;
		}
		sum += v[i];
	}
	cout << sum + 1;
	return 0;
}