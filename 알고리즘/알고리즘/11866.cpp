#include <iostream>
#include <vector>
using namespace std;
int main() {
	int k, n;
	cin >> k >> n;
	vector<int> v(k, 0);
	for (int i = 0; i < k; i++) {
		v[i] = i + 1;
	}
	int a = n - 1;
	cout << "<";
	for (int i = 0; i < k; i++) {
		if (i != k - 1) cout << v[a] << ", ";
		else {
			cout << v[a];
			break;
		}
		v.erase(v.begin() + a);
		a = (a + n - 1) % v.size();
	}
	cout << ">";
	return 0;
}