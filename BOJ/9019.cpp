#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Solution(int a, int b) {
	queue<pair<int, string>> q;
	bool isVisited[10000] = { 0, };
	q.push({ a, "" });
	isVisited[a] = true;
	int n;
	string tmp;
	while (!q.empty()) {
		n = q.front().first;
		tmp = q.front().second;
		q.pop();
		if (n == b) break;
		
		// D老 锭
		int next = n * 2;
		if (next > 9999) next %= 10000;
		if (!isVisited[next]) {
			q.push({ next, tmp + 'D' });
			isVisited[next] = true;
		}

		// S老 锭
		next = n - 1;
		if (next == 0) next = 9999;
		if (!isVisited[next]) {
			q.push({ next, tmp + 'S' });
			isVisited[next] = true;
		}
		
		int d4 = n % 10;
		n /= 10;
		int d3 = n % 10;
		n /= 10;
		int d2 = n % 10;
		int d1 = n / 10;

		// L老 锭
		next = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
		if (!isVisited[next]) {
			q.push({ next, tmp + 'L' });
			isVisited[next] = true;
		}

		// S老 锭
		next = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
		if (!isVisited[next]) {
			q.push({ next, tmp + 'R' });
			isVisited[next] = true;
		}

	}
	cout << tmp << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		Solution(a, b);
	}
	return 0;
}