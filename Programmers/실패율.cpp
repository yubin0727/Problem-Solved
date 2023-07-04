#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    // �� �� Ŭ�������� ���� �÷��̾� ���� 0 -> ������ �� �� 0 -> �������� ��������
    if (a.first.first == 0 && b.first.first == 0) return a.second < b.second;

    // �� �� �ϳ��� 0 -> ���ʿ� 0�� �ƴ� ���� ������
    if (a.first.first == 0 || b.first.first == 0) return a.first.first > b.first.first;

    // �� �� first.first�� 0�� �ƴ϶��
    if ((long long)a.first.first * b.first.second == (long long)a.first.second * b.first.first) {
        return a.second < b.second;
    }

    return (long long)a.first.first * b.first.second > (long long)a.first.second * b.first.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    // Ŭ�������� ���� �����, �������� �� �����, ���� �������� ������ ����
    vector<pair<pair<int, int>, int>> fail;
    int users = stages.size();
    sort(stages.begin(), stages.end());

    int idx = 0;
    for (int curStage = 1; curStage <= N; curStage++) {
        int stageUser = 0;
        while (idx < stages.size() && stages[idx] == curStage) {
            idx++;
            stageUser++;
        }
        fail.push_back({ {stageUser, users}, curStage });
        users -= stageUser;
    }

    sort(fail.begin(), fail.end(), comp);

    for (int i = 0; i < N; i++) {
        answer.push_back(fail[i].second);
    }

    return answer;
}