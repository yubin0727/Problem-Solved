#include <string>
#include <vector>

using namespace std;

bool isVisited[200] = { 0, };
vector<vector<int>> com;

void dfs(int n) {
    if (isVisited[n]) return;
    isVisited[n] = true;
    for (int i = 0; i < com[n].size(); i++) {
        if (!isVisited[com[n][i]]) {
            dfs(com[n][i]);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    com.resize(computers.size());
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers.size(); j++) {
            if (computers[i][j] == 1 && i != j) {
                com[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < com.size(); i++) {
        if (!isVisited[i]) {
            dfs(i);
            answer++;
        }
    }
    return answer;
}