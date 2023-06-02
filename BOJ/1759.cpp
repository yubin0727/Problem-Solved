#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int l, c;
vector<char> code;
vector<char> alpha;
int numVow = 0; // 모음 개수(a, e, i, o, u)

void PrintCode() {
	for (int i = 0; i < l; i++) {
		cout << code[i];
	}
	cout << "\n";
}

void Solution(int idx, int count) {
	bool isVow = false;
	char tmp = alpha[idx];
	code.push_back(tmp);
	if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u') {
		isVow = true;
		numVow++;
	}
	if (count == l) {
		if (numVow >= 1 && (count - numVow) >= 2) PrintCode();
	}
	else {
		for (int n = idx + 1; n < c; n++) {
			Solution(n, count + 1);
		}
	}
	code.pop_back();
	if (isVow) numVow--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> l >> c;
	alpha.resize(c);
	for (int i = 0; i < c; i++) {
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());
	for (int i = 0; i < c; i++) {
		Solution(i, 1);
	}
	return 0;
}