#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	int ans = 0;
	cin >> n >> k;
	vector<int> v(k);
	vector<vector<int>> item(k + 1);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
		item[v[i]].push_back(i);
	}
	
	vector<int> m;
	for (int i = 0; i < k; i++) {
		bool isConnected = false; // 멀티탭에 이미 꽂혀있는지 확인
		int use = v[i];
		
		// 멀티탭에 빈칸이 있다면
		if (m.size() < n) {
			for (int j = 0; j < m.size(); j++) {
				if (use == m[j]) isConnected = true;
			}
			if (!isConnected) { // 멀티탭에 꽂혀있지 않다면
				m.push_back(use);
			}
		}

		// 멀티탭에 빈칸이 없다면
		else {
			int max = 0; // 가장 늦게 사용할 전기 용품 차례
			int idx = 0; // 뺄 멀티탭 자리

			for (int j = 0; j < n; j++) {
				if (use == m[j]) isConnected = true; // 멀티탭에 이미 꽂혀있다면
				if (item[m[j]].size() == 0) {
					max = k + 1;
					idx = j;
				}
				else if (item[m[j]][0] > max) { // 가장 늦게 사용할 전기 용품 차례, 뺼 멀티탭 자리 구하기
					max = item[m[j]][0];
					idx = j;
				}
			}
			if (!isConnected) { // 멀티탭에 꽂혀있지 않다면
				m[idx] = use; // 가장 늦게 사용할 전기 용품 플러그 빼고 새로운 전기 용품 플러그 연결
				ans++;
			}
		}
		item[v[i]].erase(item[v[i]].begin());
	}

	cout << ans;
	return 0;
}