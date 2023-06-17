#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& key) {
    int m = key.size();
    vector<vector<int>> tmp(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            tmp[i][j] = key[m - j - 1][i];
        }
    }
    key = tmp;
}

bool check(vector<vector<int>> key, vector<vector<int>> expandLock, int x, int y, int n) {
    int m = key.size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            expandLock[x + i][y + j] += key[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (expandLock[m - 1 + i][m - 1 + j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int m = key.size();  // key 크기
    int n = lock.size(); // lock 크기
    int e = 2 * (m - 1) + n;   // expand 어느정도 할 지
    vector<vector<int>> expandLock(e, vector<int>(e, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            expandLock[m - 1 + i][m - 1 + j] = lock[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int x = 0; x < n + m - 1; x++) {
            for (int y = 0; y < n + m - 1; y++) {
                if (check(key, expandLock, x, y, n)) return true;
            }
        }
        rotate(key);
    }
    return false;
}