#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int findL(int s) {
	int left = 0;
	int right = 0;
	int sum = v[0];
	int ans = v.size() + 1;
	while (right < v.size() && left <= right) {
		if (sum < s) {
			right++;
			if (right >= v.size()) break;
			sum += v[right];
		}
		else {
			ans = min(ans, right - left + 1);
			sum -= v[left];
			left++;
		}
	}
	if (ans == v.size() + 1) ans = 0;
	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	v.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int len = findL(s);
	cout << len;
	return 0;
}