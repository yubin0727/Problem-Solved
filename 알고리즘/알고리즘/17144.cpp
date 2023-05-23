#include <iostream>
#include <vector>

using namespace std;

int r, c, t;
int uclean = 0; int dclean = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

vector<vector<int>> diffuse(vector<vector<int>> v) {
	vector<vector<int>> tmp(r, vector<int>(c, 0));
	tmp[uclean][0] = -1;
	tmp[dclean][0] = -1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (v[i][j] <= 0) continue;
			else {
				tmp[i][j] += v[i][j];
				int d = v[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int nextR = i + dx[k];
					int nextC = j + dy[k];
					if (0 <= nextR && nextR < r && 0 <= nextC && nextC < c) {
						if (tmp[nextR][nextC] == -1) continue;
						tmp[nextR][nextC] += d;
						tmp[i][j] -= d;
					}
				}

			}
		}
	}

	return tmp;
}

vector<vector<int>> operate(vector<vector<int>> v) {
	// 위쪽 바람
	for (int i = uclean - 1; i > 0; i--) {
		v[i][0] = v[i - 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		v[0][i] = v[0][i + 1];
	}
	for (int i = 0; i < uclean; i++) {
		v[i][c - 1] = v[i + 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		v[uclean][i] = v[uclean][i - 1];
	}
	v[uclean][1] = 0;

	// 아래쪽 바람
	for (int i = dclean + 1; i < r - 1; i++) {
		v[i][0] = v[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		v[r - 1][i] = v[r - 1][i + 1];
	}
	for (int i = r - 1; i > dclean; i--) {
		v[i][c - 1] = v[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		v[dclean][i] = v[dclean][i - 1];
	}
	v[dclean][1] = 0;

	return v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> t;
	int a = 0;
	vector<vector<int>> dust(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> dust[i][j];
			if (dust[i][j] == -1) {
				a = i;
			}
		}
	}
	uclean = a - 1;
	dclean = a;
	for (int i = 0; i < t; i++) {
		dust = diffuse(dust);
		dust = operate(dust);
	}

	//cout << endl;
	//for (int i = 0; i < r; i++) {
	//	for (int j = 0; j < c; j++) {
	//		cout << dust[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (dust[i][j] != -1) {
				ans += dust[i][j];
			}
		}
	}
	cout << ans;
	return 0;
}