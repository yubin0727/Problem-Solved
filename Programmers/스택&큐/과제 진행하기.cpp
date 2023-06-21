#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> stop; // 진행하다 멈춘 과제 저장
    vector<pair<int, pair<string, int>>> work; // {시작(분), {과제 이름, 소요 시간(분)}}
    for (int i = 0; i < plans.size(); i++) {
        string name = plans[i][0];
        string workStart = plans[i][1];
        int start = stoi(workStart.substr(0, 2)) * 60 + stoi(workStart.substr(3, 2));
        int playtime = stoi(plans[i][2]);
        work.push_back({ start, {name, playtime} });
    }
    sort(work.begin(), work.end());

    int time, playtime;
    string name;
    for (int i = 0; i < work.size() - 1; i++) {
        time = work[i].first + work[i].second.second; // 과제 끝나는 시간
        name = work[i].second.first;
        if (time <= work[i + 1].first) { // 현재 과제가 끝나는 시간이 다음 과제 시작 시간보다 빠른 경우
            answer.push_back(name);

            // 멈췄던 과제가 있다면 다음 과제 시작시간까지 진행
            while (!stop.empty()) {
                name = stop.top().first;
                time += stop.top().second;
                stop.pop();
                if (time <= work[i + 1].first) {
                    answer.push_back(name);
                }
                else {
                    stop.push({ name, time - work[i + 1].first });
                    break;
                }
            }
        }
        else { // 과제 진행하던 중 새로운 과제를 진행해야 하는 경우
            stop.push({ name, time - work[i + 1].first }); // {과제 이름, 남은 시간}
        }
    }
    answer.push_back(work[work.size() - 1].second.first);
    while (!stop.empty()) {
        answer.push_back(stop.top().first);
        stop.pop();
    }

    return answer;
}