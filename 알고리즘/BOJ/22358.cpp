#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> ride;
vector<vector<int>> lift;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k, s, t;
	cin >> n >> m >> k >> s >> t;
	lift.resize(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ride[a].push_back({ b, c });
		lift[b][a] = 1;
	}


}