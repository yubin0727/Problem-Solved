#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	while (true) {
		getline(cin, str);
		if (str[0] == '.') { break; }
		else {
			stack<char> s;
			for (int i = 0; i < str.length(); i++) {
				if (str[i] == '.') { break; }
				else if (str[i] == '(' || str[i] == '[') s.push(str[i]);
				else if (str[i] == ')') {
					if (s.size() != 0 && s.top() == '(') { s.pop(); }
					else { s.push(str[i]); }
				}
				else if (str[i] == ']') {
					if (s.size() != 0 && s.top() == '[') { s.pop(); }
					else { s.push(str[i]); }
				}
			}
			if (s.size() != 0) cout << "no" << "\n";
			else cout << "yes" << "\n";
		}
	}
	return 0;
}