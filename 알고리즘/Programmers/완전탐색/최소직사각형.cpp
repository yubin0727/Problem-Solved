#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    for (int i = 0; i < sizes.size(); i++) {
        int cardW = sizes[i][0];
        int cardH = sizes[i][1];
        if (cardW > cardH) {
            w = max(w, cardW);
            h = max(h, cardH);
        }
        else {
            w = max(w, cardH);
            h = max(h, cardW);
        }
    }
    answer = w * h;
    return answer;
}