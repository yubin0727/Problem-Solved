#include <string>
#include <vector>

using namespace std;

int N; // ����� ����
vector<int> isVisited; // �湮���� ����
vector<int> visitNode;     // �湮�� ��� ����
vector<int> information;
vector<vector<int>> tree;
int answer = 0;

void find(int sheep, int wolf) {
    if (sheep > answer) answer = sheep;

    for (int i = 0; i < visitNode.size(); i++) {
        int curNode = visitNode[i];
        for (int j = 0; j < tree[curNode].size(); j++) {
            int nextNode = tree[curNode][j];

            if (isVisited[nextNode] == 0) {
                if (information[nextNode] == 0) { // ���� ���-��, �̵��ϸ� ��
                    isVisited[nextNode] = 1;
                    visitNode.push_back(nextNode);
                    find(sheep + 1, wolf);
                    visitNode.pop_back();
                    isVisited[nextNode] = 0;
                }
                else if (sheep > wolf + 1) { // ���� ���-����, ���� ���� �Ѹ����� �߰��Ǿ ���� �� ���ٸ�
                    isVisited[nextNode] = 1;
                    visitNode.push_back(nextNode);
                    find(sheep, wolf + 1);
                    visitNode.pop_back();
                    isVisited[nextNode] = 0;
                }
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    information = info;
    N = information.size();
    isVisited.resize(N, 0);
    tree.resize(N);
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    visitNode.push_back(0);
    isVisited[0] = 1;
    find(1, 0);

    return answer;
}