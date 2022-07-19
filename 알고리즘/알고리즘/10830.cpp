#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> v(5, vector<long long>(5, 0));
vector<vector<long long>> ans(5, vector<long long>(5, 0));
int n;
long long b;

void multi(vector<vector<long long>> a, vector<vector<long long>> b){
	vector<vector<long long>> t(5, vector<long long>(5, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				t[i][j] += a[i][k] * b[k][j];
			}
			t[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = t[i][j];
		}
	}
}

void result(long long b) {
	if (b == 0) return;
	if (b == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][j] = v[i][j] % 1000;
			}
		}
		return;
	}
	result(b / 2);
	multi(ans, ans);
	if (b % 2 != 0) {
		multi(ans, v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	result(b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}