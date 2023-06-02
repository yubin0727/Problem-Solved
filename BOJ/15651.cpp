#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

void permutation(int dep) {
	if (dep > m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		permutation(dep + 1);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	permutation(1);
	return 0;
}