#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> it(n, 0);
	vector<int> ot(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> it[i] >> ot[i];
	}
	sort(it.begin(), it.end());
	sort(ot.begin(), ot.end());
	int a = 0;
	int b = 0;
	int cm = 0;
	int maxm = 0;
	int st = it[0];
	int ft = ot[0];
	bool x = true;
	while(b < n){
		if (a == n) break;
		if (it[a] < ot[b]) {
			cm++;
			if (cm == maxm) x = false;
			if (cm > maxm) {
				maxm = cm;
				st = it[a];
				ft = ot[b];
				x = true;
			}
			a++;
		}
		else if (it[a] > ot[b]) {
			if (cm == maxm && x) {
				ft = ot[b];
			}
			cm--;
			b++;
		}
		else {
			if (a == n - 1) {
				if (cm == maxm && x) ft = ot[b + 1];
			}
			a++;
			b++;
		}
	}
	cout << maxm << endl;
	cout << st << " " << ft;
	return 0;
}