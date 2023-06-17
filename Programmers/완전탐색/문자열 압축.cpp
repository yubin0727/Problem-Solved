#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; i++) {
        string tmp = "";
        int same = 1; // 같은 문자열의 개수 누적
        string curString = s.substr(0, i); // curString - 가장 최근에 잘라진 문자열 저장
        int j = i;
        for (; j + i <= s.size(); j += i) {
            if (curString.compare(s.substr(j, i)) == 0) { // 이전 문자열과 같다면
                same++;
            }
            else { // 이전 문자열과 다르다면
                if (same == 1) {
                    tmp += curString;
                }
                else {
                    tmp = tmp + to_string(same) + curString;
                    same = 1;
                }
                curString = s.substr(j, i);
            }
        }
        if (same == 1) {
            tmp += curString;
        }
        else {
            tmp += to_string(same) + curString;
            same = 1;
        }
        tmp += s.substr(j); // 남은 부분이 잘리는 크기(i)보다 작다면 압축 불가능 -> 남은 부분 붙여줌
        if (answer > tmp.size()) answer = tmp.size();
    }
    return answer;
}