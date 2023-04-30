#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	bool isPossible = true;
	int k = 1;
	stack<int> s;
	vector<char> ans;
	for (int i = 0; i < n; i++) {
		int next = v[i];
		if (next >= k) {
			while (next >= k) {
				s.push(k);
				k++;
				ans.push_back('+');
			}
			s.pop();
			ans.push_back('-');
		}
		else {
			if (s.top() > next) {
				isPossible = false;
				break;
			}
			else {
				s.pop();
				ans.push_back('-');
			}
		}
	}
	if (isPossible) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}
	return 0;
}