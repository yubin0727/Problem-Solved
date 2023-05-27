#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int w = 0;
int b = 0;

void paper(int x, int y, int s) {
	if (s == 0) return;
	bool wp = false;
	bool bp = false;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (v[i][j] == 0) wp = true;
			else if (v[i][j] == 1) bp = true;
		}
		if (wp && bp) break;
	}
	if (wp && !bp) w++;
	else if (!wp && bp) b++;
	else if (wp && bp) {
		paper(x, y, s / 2);
		paper(x + s / 2, y, s / 2);
		paper(x, y + s / 2, s / 2);
		paper(x + s / 2, y + s / 2, s / 2);
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
	cout << w << "\n" << b;
	return 0;
}