#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> math1 = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    vector<int> math2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> math3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int q1 = 0;
    int q2 = 0;
    for (int i = 0; i < answers.size(); i++) {
        int a = answers[i];
        if (a == math1[q1]) { c1++; }
        if (a == math2[q2]) { c2++; }
        if (a == math3[q1]) { c3++; }
        q1 = (q1 + 1) % 10;
        q2 = (q2 + 1) % 8;
    }
    int m = max(max(c1, c2), c3);
    if (m == c1) { answer.push_back(1); }
    if (m == c2) { answer.push_back(2); }
    if (m == c3) { answer.push_back(3); }
    return answer;
}