#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<int, string> p1;
	map<string, int> p2;
	int n, m;
	string s;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		p1.insert(pair<int, string>(i, s));
		p2.insert(pair<string, int>(s, i));
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		if ('0' <= s[0] && s[0] <= '9') {
			cout << p1[stoi(s)] << "\n";
		}
		else {
			cout << p2[s] << "\n";
		}
	}
	return 0;
}