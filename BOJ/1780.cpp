#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int m = 0;
int z = 0;
int o = 0;

void paper(int x, int y, int s) {
	if (s == 0) return;
	bool mp = false;
	bool zp = false;
	bool op = false;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (v[i][j] == -1) mp = true;
			else if (v[i][j] == 0) zp = true;
			else if (v[i][j] == 1) op = true;
		}
		if ((mp && zp) || (zp && op) || (mp && op)) break;
	}
	if (mp && !zp && !op) m++;
	else if (!mp && zp && !op) z++;
	else if (!mp && !zp && op) o++;
	else {
		paper(x, y, s / 3);
		paper(x, y + s / 3, s / 3);
		paper(x, y + s * 2 / 3, s / 3);
		paper(x + s / 3, y, s / 3);
		paper(x + s / 3, y + s / 3, s / 3);
		paper(x + s / 3, y + s * 2 / 3, s / 3);
		paper(x + s * 2 / 3, y, s / 3);
		paper(x + s * 2 / 3, y + s / 3, s / 3);
		paper(x + s * 2 / 3, y + s * 2 / 3, s / 3);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	v.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	paper(0, 0, n);
	cout << m << "\n" << z << "\n" << o;
	return 0;
}