#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> v[10];
long long d[10];
bool isVisited[10];

long long gcd(long long a, long long b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}
void dfs(int n) {
	isVisited[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		if (!isVisited[v[n][i].first]) {
			d[v[n][i].first] = d[n] * v[n][i].second.second / v[n][i].second.first;
			dfs(v[n][i].first);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	long long lcm = 1;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		v[a].push_back({ b, {p, q} });
		v[b].push_back({ a, {q, p} });
		lcm *= (long long)p * (long long)q / gcd((long long)p, (long long)q);
	}
	d[0] = lcm;
	dfs(0);
	long long m = d[0];
	for (int i = 1; i < n; i++) {
		m = gcd(m, d[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << d[i] / m << " ";
	}
	return 0;
}