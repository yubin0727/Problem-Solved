#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    // 둘 다 클리어하지 못한 플레이어 수가 0 -> 실패율 둘 다 0 -> 스테이지 오름차순
    if (a.first.first == 0 && b.first.first == 0) return a.second < b.second;

    // 둘 중 하나만 0 -> 앞쪽에 0이 아닌 것이 가도록
    if (a.first.first == 0 || b.first.first == 0) return a.first.first > b.first.first;

    // 둘 다 first.first가 0이 아니라면
    if ((long long)a.first.first * b.first.second == (long long)a.first.second * b.first.first) {
        return a.second < b.second;
    }

    return (long long)a.first.first * b.first.second > (long long)a.first.second * b.first.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    // 클리어하지 못한 사용자, 스테이지 총 사용자, 현재 스테이지 순서로 저장
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