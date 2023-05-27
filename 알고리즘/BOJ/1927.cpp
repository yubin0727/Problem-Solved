#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else{
			pq.push(x);
		}
	}
	return 0;
}