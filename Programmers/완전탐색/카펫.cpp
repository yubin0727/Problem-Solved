#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;
    for (int h = 1; h * h <= area; h++) {
        if (area % h == 0) {
            int w = area / h;
            if ((h - 2) * (w - 2) == yellow) {
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    return answer;
}