#include <iostream>
#include <vector>

using namespace std;

int n;
long long ans = 0;
vector<int> v;
vector<int> tmp;

void merge_sort(int start, int end) {
	if (start >= end) return;
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	for (int i = start; i <= end; i++) {
		tmp[i] = v[i];
	}
	int k = start;
	int s = start;
	int e = mid + 1;
	while (s <= mid && e <= end) {
		if (tmp[s] > tmp[e]) {
			v[k++] = tmp[e++];
			ans += e - k;
		}
		else {
			v[k++] = tmp[s++];
		}
	}
	while (s <= mid) {
		v[k++] = tmp[s++];
	}
	while (e <= end) {
		v[k++] = tmp[e++];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	v.resize(n, 0);
	tmp.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	merge_sort(0, n -1);
	cout << ans;
	return 0;
}