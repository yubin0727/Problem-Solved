#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v(1001);
vector<int> w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d, score;
	int max = 0;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> score;
		v[d].push_back(score);
		if (d > max) {
			max = d;
		}
	}

	for (; max > 0; max--) {
		if (v[max].size() > 0) {
			for (int i = 0; i < v[max].size(); i++) {
				w.push_back(v[max][i]);
			}
			sort(w.begin(), w.end());
		}
		
		if (w.size() > 0) {
			ans += w.back();
			w.pop_back();
		}
	}

	cout << ans;
	return 0;
}