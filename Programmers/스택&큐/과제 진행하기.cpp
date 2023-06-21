#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> stop; // �����ϴ� ���� ���� ����
    vector<pair<int, pair<string, int>>> work; // {����(��), {���� �̸�, �ҿ� �ð�(��)}}
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
        time = work[i].first + work[i].second.second; // ���� ������ �ð�
        name = work[i].second.first;
        if (time <= work[i + 1].first) { // ���� ������ ������ �ð��� ���� ���� ���� �ð����� ���� ���
            answer.push_back(name);

            // ����� ������ �ִٸ� ���� ���� ���۽ð����� ����
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
        else { // ���� �����ϴ� �� ���ο� ������ �����ؾ� �ϴ� ���
            stop.push({ name, time - work[i + 1].first }); // {���� �̸�, ���� �ð�}
        }
    }
    answer.push_back(work[work.size() - 1].second.first);
    while (!stop.empty()) {
        answer.push_back(stop.top().first);
        stop.pop();
    }

    return answer;
}