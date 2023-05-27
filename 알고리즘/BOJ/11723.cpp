#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string str;
	int v;
	int bit = 0;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "add") {
			cin >> v;
			bit = bit | (1 << v);
		}
		else if (str == "remove") {
			cin >> v;
			bit = bit & ~(1 << v);
		}
		else if (str == "check") {
			cin >> v;
			if ((1 << v) & bit) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (str == "toggle") {
			cin >> v;
			bit = bit ^ (1 << v);
		}
		else if (str == "all") {
			bit = (1 << 22) - 1;
		}
		else if (str == "empty") {
			bit = 0;
		}
	}
	return 0;
}