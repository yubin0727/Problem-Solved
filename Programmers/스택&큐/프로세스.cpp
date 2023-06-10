#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push({ priorities[i], i });
    }
    while (!q.empty()) {
        if (pq.top() == q.front().first) {
            answer++;
            if (q.front().second == location) {
                break;
            }
            else {
                pq.pop();
                q.pop();
            }
        }
        else {
            int p = q.front().first;
            int l = q.front().second;
            q.pop();
            q.push({ p, l });
        }
    }

    return answer;
}