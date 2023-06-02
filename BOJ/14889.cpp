#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<vector<int>> v;
vector<int> steam;
vector<int> lteam;
vector<int> isVisited;
int m = 2e9;
int sum = 0;
int n;

void findm(int d, int a) {
	if (d == n / 2) {
		int index = 0;
		for (int i = 1; i <= n; i++) {
			if (index == n / 2) {
				lteam.push_back(i);
				continue;
			}
			if (steam[index] == i) {
				index++;
			}
			else {
				lteam.push_back(i);
			}
		}
		int start = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				int a = steam[i];
				int b = steam[j];
				start = start + v[a][b] + v[b][a];
			}
		}
		int link = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				int a = lteam[i];
				int b = lteam[j];
				link = link + v[a][b] + v[b][a];
			}
		}
		
		/*cout << "steam : ";
		for (int i = 0; i < n / 2; i++) {
			cout << steam[i] << " ";
		}
		cout << endl << "lteam : ";
		for (int i = 0; i < n / 2; i++) {
			cout << lteam[i] << " ";
		}
		cout << endl << "start : " << start << " link : " << link << endl;*/
		m = min(m, abs(start - link));
		lteam.clear();
	}
	else {
		for (int i = a + 1; i <= n; i++) {
			if (isVisited[i] == 0) {
				isVisited[i] = 1;
				steam.push_back(i);
				findm(d + 1, i);
				steam.pop_back();
				isVisited[i] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	v.resize(n + 1, vector<int>(n + 1, 0));
	isVisited.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
			sum += v[i][j];
		}
	}
	steam.push_back(1);
	isVisited[1] = 1;
	findm(1, 1);
	cout << m;
	return 0;
}