#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int a, b, c;
vector<int> ans;
bool isVisited[201][201];

void bfs() {
	queue<pair<int, int>> q;
	isVisited[0][0] = true;
	q.push({ 0, 0 });
	while (!q.empty()) {
		int nowA = q.front().first;
		int nowB = q.front().second;
		int nowC = c - nowA - nowB;
		q.pop();
		if (nowA == 0) {
			ans.push_back(nowC);
		}
		if (nowA != 0) {
			// A -> B
			if (nowA + nowB > b) {
				if (!isVisited[nowA + nowB - b][b]) {
					q.push({ nowA + nowB - b , b });
					isVisited[nowA + nowB - b][b] = true;
				}
			}
			else {
				if (!isVisited[0][nowA + nowB]) {
					q.push({ 0, nowA + nowB });
					isVisited[0][nowA + nowB] = true;
				}
			}
			// A -> C
			if (nowA + nowC > c) {
				if (!isVisited[nowA + nowC - c][nowB]) {
					q.push({ nowA + nowC - c , nowB });
					isVisited[nowA + nowC - c][nowB] = true;
				}
			}
			else {
				if (!isVisited[0][nowB]) {
					q.push({ 0, nowB });
					isVisited[0][nowB] = true;
				}
			}
		}
		if (nowB != 0) {
			// B -> A
			if (nowA + nowB > a) {
				if (!isVisited[a][nowA + nowB - a]) {
					q.push({ a, nowA + nowB - a });
					isVisited[a][nowA + nowB - a] = true;
				}
			}
			else {
				if (!isVisited[nowA + nowB][0]) {
					q.push({ nowA + nowB, 0 });
					isVisited[nowA + nowB][0] = true;
				}
			}
			// B -> C
			if (nowB + nowC > c) {
				if (!isVisited[nowA, nowB + nowC - c]) {
					q.push({ nowA , nowB + nowC - c });
					isVisited[nowA][nowB + nowC - c] = true;
				}
			}
			else {
				if (!isVisited[nowA][0]) {
					q.push({ nowA, 0 });
					isVisited[nowA][0] = true;
				}
			}
		}
		if (nowC != 0) {
			// C -> A
			if (nowA + nowC > a) {
				if (!isVisited[a][nowB]) {
					q.push({ a, nowB });
					isVisited[a][nowB] = true;
				}
			}
			else {
				if (!isVisited[nowA + nowC][nowB]) {
					q.push({ nowA + nowC, nowB });
					isVisited[nowA + nowC][nowB] = true;
				}
			}
			// C -> B
			if (nowB + nowC > b) {
				if (!isVisited[nowA][b]) {
					q.push({ nowA, b });
					isVisited[nowA][b] = true;
				}
			}
			else {
				if (!isVisited[nowA][nowB + nowC]) {
					q.push({ nowA, nowB + nowC });
					isVisited[nowA][nowB + nowC] = true;
				}
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	bfs();
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}