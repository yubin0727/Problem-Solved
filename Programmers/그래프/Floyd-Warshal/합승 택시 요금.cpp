#include <string>
#include <vector>
#include <algorithm>

#define INF 98765432

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<int>> taxiFare(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        taxiFare[i][i] = 0;
    }
    for (int i = 0; i < fares.size(); i++) {
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];
        taxiFare[c][d] = f;
        taxiFare[d][c] = f;
    }
    for (int k = 1; k <= n; k++) { // ���İ��� ����
        for (int i = 1; i <= n; i++) { // ���
            for (int j = 1; j <= n; j++) { // ����
                if (taxiFare[i][k] == INF || taxiFare[k][j] == INF) continue;
                taxiFare[i][j] = min(taxiFare[i][j], taxiFare[i][k] + taxiFare[k][j]);
            }
        }
    }
    // s:�������. a,b:��������
    answer = taxiFare[s][a] + taxiFare[s][b];
    for (int i = 1; i <= n; i++) {
        answer = min(answer, taxiFare[s][i] + taxiFare[i][a] + taxiFare[i][b]);
    }

    return answer;
}