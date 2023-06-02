#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt = 0;
vector<int> v;

bool possible(int r) {
	for (int i = 0; i < r; i++) {
		if (v[r] == v[i] || (r - i == abs(v[r] - v[i]))) {
			return false;
		}
	}
	return true;
}

void queen(int r) {
	if (r == n) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			v[r] = i;
			if (possible(r)) {
				queen(r + 1);
			}
		}
	}
}

int main() {
	cin >> n;
	v.resize(n, 0);
	queen(0);
	cout << cnt;
	return 0;
}