#include <iostream>
#include <vector>

using namespace std;

vector<int> primeVector(int n) { // n 이하의 소수로 구성된 벡터
	vector<int> tmp(n + 1, 0);
	vector<int> p;
	for (int i = 2; i <= n; i++) { tmp[i] = i; }
	for (int i = 2; i <= n; i++) {
		if (tmp[i] == i) {
			p.push_back(i);
			for (int j = i * 2; j <= n; j += i) {
				tmp[j] = 0;
			}
		}
	}
	return p;
}

int solution(int n) {
	int ans = 0;
	vector<int> p = primeVector(n);
	int start = 0;
	int end = 0;
	int sum = p[0];
	while (1) {
		if (sum < n) {
			end++;
			if (end < p.size()) sum += p[end];
			else break;
		}
		else if (sum > n) {
			start++;
			if (start <= end) sum -= p[start - 1];
			else break;
		}
		else {
			ans++;
			end++;
			if (end < p.size()) sum += p[end];
			else break;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	if (n == 1) { cout << 0; }
	else { cout << solution(n); }
	return 0;
}
