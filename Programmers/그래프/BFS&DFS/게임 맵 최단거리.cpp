#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> isVisited(n, vector<int>(m, 0));
    isVisited[0][0] = 1;
    q.push({ {0, 0}, 1 });
    while (!q.empty()) {
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int count = q.front().second;
        q.pop();
        if (curX == n - 1 && curY == m - 1) {
            answer = count;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nX = curX + dx[i];
            int nY = curY + dy[i];
            if (nX < 0 || nX >= n || nY < 0 || nY >= m || maps[nX][nY] == 0 || isVisited[nX][nY] == 1) continue;
            q.push({ {nX, nY}, count + 1 });
            isVisited[nX][nY] = 1;
        }
    }
    if (answer == 0) answer = -1;
    return answer;
}