#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int set = 1000;
	int single = 1000;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		set = min(set, a);
		single = min(single, b);
	}
	int p = 0;
	if (set < single * 6) { a = set; }
	else a = single * 6;
	while (n >= 6) {
		p += a;
		n -= 6;
	}
	if (set < single * n) { p += set; }
	else { p += single * n; }
	cout << p;
	return 0;
}