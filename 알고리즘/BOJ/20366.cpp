#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 2e9;
using namespace std;

vector<int> v;

int minH() {
	int ans = INF;
	int n = v.size();
	for (int i = 0; i < n - 3; i++) {
		for (int j = 3; j < n; j++) {
			int a = v[i] + v[j];
			int left = i + 1;
			int right = j - 1;
			while (left < right) {
				int b = v[left] + v[right];
				if (a > b) {
					ans = min(a - b, ans);
					left++;
				}
				else if (a < b) {
					ans = min(b - a, ans);
					right--;
				}
				else return 0;
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	v.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	bool isAns = false;
	int ans = minH();
	cout << ans;
	return 0;
}