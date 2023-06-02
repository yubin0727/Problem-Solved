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
		bool isConnected = false; // ��Ƽ�ǿ� �̹� �����ִ��� Ȯ��
		int use = v[i];
		
		// ��Ƽ�ǿ� ��ĭ�� �ִٸ�
		if (m.size() < n) {
			for (int j = 0; j < m.size(); j++) {
				if (use == m[j]) isConnected = true;
			}
			if (!isConnected) { // ��Ƽ�ǿ� �������� �ʴٸ�
				m.push_back(use);
			}
		}

		// ��Ƽ�ǿ� ��ĭ�� ���ٸ�
		else {
			int max = 0; // ���� �ʰ� ����� ���� ��ǰ ����
			int idx = 0; // �� ��Ƽ�� �ڸ�

			for (int j = 0; j < n; j++) {
				if (use == m[j]) isConnected = true; // ��Ƽ�ǿ� �̹� �����ִٸ�
				if (item[m[j]].size() == 0) {
					max = k + 1;
					idx = j;
				}
				else if (item[m[j]][0] > max) { // ���� �ʰ� ����� ���� ��ǰ ����, �E ��Ƽ�� �ڸ� ���ϱ�
					max = item[m[j]][0];
					idx = j;
				}
			}
			if (!isConnected) { // ��Ƽ�ǿ� �������� �ʴٸ�
				m[idx] = use; // ���� �ʰ� ����� ���� ��ǰ �÷��� ���� ���ο� ���� ��ǰ �÷��� ����
				ans++;
			}
		}
		item[v[i]].erase(item[v[i]].begin());
	}

	cout << ans;
	return 0;
}