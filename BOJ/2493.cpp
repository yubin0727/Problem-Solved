#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	stack<pair<int, int>> s;
	vector<int> ans(n + 1, 0);
	s.push({ 123456789, 0 });
	int h;
	for (int i = 1; i <= n; i++) {
		cin >> h;
		while (s.top().first < h) {
			s.pop();
		}
		ans[i] = s.top().second;
		s.push({ h, i });
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}