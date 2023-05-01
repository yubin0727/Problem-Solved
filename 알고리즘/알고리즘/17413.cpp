#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	stack<char> inverse;
	string s;
	getline(cin, s);
	bool isInverse = true;
	for (int i = 0; i < s.size(); i++) {
		if (isInverse) {
			if (s[i] == '<') {
				while (!inverse.empty()) {
					cout << inverse.top();
					inverse.pop();
				}
				isInverse = false;
				cout << s[i];
			}
			else if (s[i] == ' ') {
				while (!inverse.empty()) {
					cout << inverse.top();
					inverse.pop();
				}
				cout << " ";
			}
			else {
				inverse.push(s[i]);
			}
		}
		else {
			cout << s[i];
			if (s[i] == '>') isInverse = true;
		}
	}
	while (!inverse.empty()) {
		cout << inverse.top();
		inverse.pop();
	}

	/*stringstream ss(s);
	string word;
	while (ss >> word) {
		for (int i = 0; i < word.size(); i++) {
			if (isInverse) {
				if (word[i] == '<') {
					while (!inverse.empty()) {
						cout << inverse.top();
						inverse.pop();
					}
					isInverse = false;
					cout << word[i];
				}
				else {
					inverse.push(word[i]);
				}
			}
			else {
				cout << word[i];
				if (word[i] == '>') isInverse = true;
			}
		}
		while (!inverse.empty()) {
			cout << inverse.top();
			inverse.pop();
		}
		cout << " ";
	}*/

	
	return 0;
}