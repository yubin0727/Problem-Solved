#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n;
	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int>> min;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (max.size() == min.size()) {
			max.push(k);
		}
		else {
			min.push(k);
		}
		
		if (!max.empty() && !min.empty()) {
			if (max.top() > min.top()) {
				int a = max.top();
				max.pop();
				int b = min.top();
				min.pop();
				max.push(b);
				min.push(a);
			}
		}
		
		cout << max.top() << endl;
	}
	return 0;
}