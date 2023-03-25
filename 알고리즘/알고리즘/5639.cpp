#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void post(int start, int end) {
	if (start == end) {
		cout << v[start] << endl;
		return;
	}
	if (start > end) {
		return;
	}
	int root = v[start];
	int idx = start + 1;
	while (true) {
		if (idx <= end && v[idx] < root) {
			idx++;
		}
		else break;
	}
	post(start + 1, idx - 1);
	post(idx, end);
	cout << root << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	
	post(0, v.size() - 1);
	return 0;
}