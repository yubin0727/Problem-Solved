#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> v;
int n, r, c;

int visit(int a, int b, int s) { // a가 행이고 b가 열임
	if (s == 0) return 0;
	if (r < a + (int)pow(2, s - 1)) {
		if (c < b + (int)pow(2, s - 1)) {
			return visit(a, b, s - 1);
		}
		else {
			return visit(a, b + (int)pow(2, s - 1), s - 1) + (int)pow(pow(2, s - 1), 2);
		}
	}
	else {
		if (c < b + (int)pow(2, s - 1)) {
			return visit(a + (int)pow(2, s - 1), b, s- 1) + (int)pow(pow(2, s - 1), 2) * 2;
		}
		else {
			return visit(a + (int)pow(2, s - 1), b + (int)pow(2, s - 1), s - 1) + (int)pow(pow(2, s - 1), 2) * 3;
		}
	}
}

int main() {
	cin >> n >> r >> c;
	cout << visit(0, 0, n);
	return 0;
}