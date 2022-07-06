#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> isVisited;
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
		if (isVisited[i] == 0) {
			isVisited[i] = 1;
			v.push_back(i);
			permutation(dep + 1);
			v.pop_back();
			isVisited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	isVisited.resize(n + 1, 0);
	permutation(1);
	return 0;
}