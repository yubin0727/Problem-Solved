#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long ans;
	int days = 1;
	long long sum = 0;
	int j = 0;
	for (; j < m; j++) {
		sum += v[j];
		ans = sum;
	}
	while (j < n) {
		sum -= v[j - m];
		sum += v[j];
		if (ans == sum) {
			days++;
		}
		else if (ans < sum) {
			ans = sum;
			days = 1;
		}
		j++;
	}
	if (ans == 0) {
		cout << "SAD";
	}
	else {
		cout << ans << endl;
		cout << days;
	}
	return 0;
}