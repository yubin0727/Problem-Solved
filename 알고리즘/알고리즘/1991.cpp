#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;

void preorder(int a) {
	cout << char(a + 65);
	if (v[a][0] != -1) {
		preorder(v[a][0]);
	}
	if (v[a][1] != -1) {
		preorder(v[a][1]);
	}
	return;
}

void inorder(int a) {
	if (v[a][0] != -1) {
		inorder(v[a][0]);
	}
	cout << char(a + 65);
	if (v[a][1] != -1) {
		inorder(v[a][1]);
	}
	return;
}

void postorder(int a) {
	if (v[a][0] != -1) {
		postorder(v[a][0]);
	}
	if (v[a][1] != -1) {
		postorder(v[a][1]);
	}
	cout << char(a + 65);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		int a = int(x) - 65;
		if (y != '.') {
			v[a].push_back(int(y) - 65);
		}
		else {
			v[a].push_back(-1);
		}
		if (z != '.') {
			v[a].push_back(int(z) - 65);
		}
		else {
			v[a].push_back(-1);
		}
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;

	return 0;
}