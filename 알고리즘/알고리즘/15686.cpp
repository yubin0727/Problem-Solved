#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int ans = 500000;
int n, m;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
bool isSelected[13];

void calDist() {
	int totalDist = 0;
	for (int i = 0; i < home.size(); i++) {
		int d = 5000;
		for (int j = 0; j < chicken.size(); j++) {
			if (isSelected[j]) {
				int temp = abs(chicken[j].first - home[i].first) + abs(chicken[j].second - home[i].second);
				d = min(d, temp);
			}
		}
		totalDist += d;
	}
	ans = min(totalDist, ans);
}

void solution(int idx, int c) {
	if (c == m) {
		calDist();
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (!isSelected[i]) {
			isSelected[i] = true;
			solution(i, c + 1);
			isSelected[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == 1) {
				home.push_back({ i, j });
			}
			else if (tmp == 2) {
				chicken.push_back({ i, j });
			}
		}
	}
	solution(0, 0);
	cout << ans;
	return 0;
}