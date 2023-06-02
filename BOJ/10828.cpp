#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> stack;
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			int a;
			cin >> a;
			stack.push(a);
		}
		else if (s == "pop") {
			if (stack.size() != 0) {
				cout << stack.top() << endl;
				stack.pop();
			}
			else { cout << "-1" << endl; }
		}
		else if (s == "top") {
			if (stack.size() != 0) { cout << stack.top() << endl; }
			else { cout << "-1" << endl; }
		}
		else if (s == "size") { cout << stack.size() << endl; }
		else if (s == "empty") {
			if (stack.empty()) { cout << "1" << endl; }
			else { cout << "0" << endl; }
		}
	}
	return 0;
}