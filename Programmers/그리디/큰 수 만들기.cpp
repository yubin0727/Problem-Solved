#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int del = 0;
    deque<int> dq;
    for (int i = 0; i < number.size(); i++) {
        int tmp = number[i] - '0';
        while (del < k && !dq.empty() && dq.back() < tmp) {
            dq.pop_back();
            del++;
        }
        dq.push_back(tmp);
    }
    for (int i = 0; i < number.size() - k; i++) {
        answer += to_string(dq[i]);
    }
    return answer;
}