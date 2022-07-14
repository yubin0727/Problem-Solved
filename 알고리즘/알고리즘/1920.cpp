#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

void qtree(int x, int y, int s) {
	if (s == 0) return;
	bool zero = false;
	bool one = false;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (v[i][j] == 0) zero = true;
			else if (v[i][j] == 1) one = true;
		}
		if (zero && one) break;
	}
	if (zero && !one) cout << "0";
	else if (!zero && one) cout << "1";
	else if (zero && one) {
		cout << "(";
		qtree(x, y, s / 2);
		qtree(x, y + s / 2, s / 2);
		qtree(x + s / 2, y, s / 2);
		qtree(x + s / 2, y + s / 2, s / 2);
		cout << ")";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	char c;
	cin >> n;
	v.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			v[i][j] = c - '0';
		}
	}
	qtree(0, 0, n);
	return 0;
}