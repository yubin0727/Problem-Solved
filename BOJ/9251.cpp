#include <iostream>
#include <algorithm>

int dp[1001][1001];

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	int a = str1.size();
	int b = str2.size();
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[a][b];
	return 0;
}