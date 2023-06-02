#include <iostream>
#include <vector>

using namespace std;

int n;
int ans;
vector<int> student;
vector<int> isVisited;
vector<int> isDone;

void dfs(int node) {
	isVisited[node] = 1;
	int nextNode = student[node];
	
	if (isVisited[nextNode] == 0) {
		dfs(nextNode);
	}
	else if (isDone[nextNode] == 0) {
		for (int tmp = nextNode; tmp != node; tmp = student[tmp]) {
			ans++;
		}
		ans++;
	}
	isDone[node] = 1;
}

int solution() {
	ans = 0;
	for (int i = 1; i <= n; i++) {
		if (isVisited[i] == 0) {
			dfs(i);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		student.resize(n + 1, 0);
		isVisited.clear();
		isDone.clear();
		isVisited.resize(n + 1, 0);
		isDone.resize(n + 1, 0);
		for (int j = 1; j <= n; j++) {
			cin >> student[j];
		}

		cout << n - solution() << "\n";
	}
	return 0;
}