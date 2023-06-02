#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;
vector<int> v(4, 0);
int M = -2e9;
int m = 2e9;

void ans(int d, int r) {
	if (d == n) {
		if (r > M) M = r;
		if (r < m) m = r;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (v[i] == 0) continue;
			v[i]--;
			if (i == 0) {
				ans(d + 1, r + a[d]);
			}
			else if (i == 1) {
				ans(d + 1, r - a[d]);
			}
			else if (i == 2) {
				ans(d + 1, r * a[d]);
			}
			else if (i == 3) {
				ans(d + 1, r / a[d]);
			}
			v[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	a.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> v[0] >> v[1] >> v[2] >> v[3];
	ans(1, a[0]);
	cout << M << "\n" << m;

	return 0;
}