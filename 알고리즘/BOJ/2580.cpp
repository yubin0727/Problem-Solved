#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(9, vector<int>(9, 0));
vector<pair<int, int>> f;
bool isFilled = false;

bool check(int i, int n) {
	int x = f[n].first;
	int y = f[n].second;
	for (int j = 0; j < 9; j++) { // За
		if (v[x][j] == i) return false;
	}
	for (int j = 0; j < 9; j++) { // ї­
		if (v[j][y] == i) return false; 
	}
	int a = x / 3;
	int b = y / 3;
	for (int j = a * 3; j < a * 3 + 3; j++) {
		for (int k = b * 3; k < b * 3 + 3; k++) {
			if (j == x && k == y) continue;
			if (v[j][k] == i) return false;
		}
	}
	return true;
}

void sudoku(int n) {
	if (n == f.size()) {
		isFilled = true;
		return;
	}
	else {
		int x = f[n].first;
		int y = f[n].second;
		for (int i = 1; i <= 9; i++) {
			if (check(i, n)) {
				v[x][y] = i;
				sudoku(n + 1);
			}
			if (isFilled) return;
		}
		v[x][y] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> v[i][j];
			if (v[i][j] == 0) {
				f.push_back({ i, j });
			}
		}
	}
	sudoku(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}