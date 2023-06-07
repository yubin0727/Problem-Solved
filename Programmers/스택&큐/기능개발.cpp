#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for (int i = 0; i < progresses.size(); i++) {
        int r = 100 - progresses[i];
        int d = r / speeds[i];
        if (r % speeds[i] != 0) d++;
        q.push(d);
    }
    while (!q.empty()) {
        int max = q.front();
        q.pop();
        int n = 1;
        while (!q.empty() && max >= q.front()) {
            q.pop();
            n++;
        }
        answer.push_back(n);
    }
    return answer;
}